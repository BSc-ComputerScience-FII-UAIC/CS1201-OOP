#include "parser-composite.h"
#include <string>

Parser::Parser(string str) {
  input = str; index = 0;
}

/*
lookAhead(k) modifies index, input {
  if (index + k <= input.size()) {
    str = "";
    for (i = 0; i < k; ++i)
      str = str + input.at(index + i);
    return str;
  }
  else return "\0";
}
*/
string Parser::lookAhead(int k) {
  if (index + k <= input.size()) {
    return input.substr(index, k);
  }
  else return "\0";
}

/*
skipWS() modifies index, input {
  // skip the spaces
  while (index < input.size() &&
	 (input.at(index) == " "  ||
	  input.at(index) == "\t" ||  // not working
	  input.at(index) == "\n"))   // not working
    index++;
}
*/
void Parser::skipWS() {
  while (index < input.size() &&
	 (input[index] == ' '  ||
	  input[index] == '\t' ||  
	  input[index] == '\n'))   
    index++;
}

/*
  nextSym(k) modifies index, input {
  if (index + k <= input.size())
  index += k;
  else
  error("nextsym(): expected a symbol");
  }
*/
void Parser::nextSym(int k) {
  if (index + k <= input.size())
    index += k;
  else
    throw "nextsym(): expected a symbol";
}

/*
accept(str) {
  if (lookAhead(str.size()) == str) {
    nextSym(str.size());
    skipWS();
    return true;
  }
  return false;
}
*/
bool Parser::accept(string str) {
  if (lookAhead(str.size()) == str) {
    nextSym(str.size());
    skipWS();
    return true;
  }
  return false;
}

/*
expect(str) {
  skipWS();
  if (accept(str))
    return true;
  error("expect: unexpected symbol");
  return false;
}
*/
bool Parser::expect(string str) {
  skipWS();
  if (accept(str))
    return true;
  throw "expect: unexpected symbol";
}

int Parser::getIndex() {
  return index;
}

/*
varName() {
  skipWS();
  s = lookAhead(1);
  if ("a" <= s && s <= "z") {
    nextSym(1);
    skipWS();
    return [s, <>];
  }
  else return [];
}
*/
std::optional<VarName*> Parser::varName() {
  skipWS();
  string s = lookAhead(1);
  if ("a" <= s && s <= "z") {
    nextSym(1);
    skipWS();
    return new VarName(s);
  }
  else return std::nullopt;
}


/*
acceptDigit() modifies index, input {
  digits = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];
  if (index < input.size()) {
    for (i = 0; i < 10; ++i) 
      if (accept(digits[i])) {
	return true;
      }
  }
  return false;
}
*/
bool Parser::acceptDigit() {
  string digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  if (index < input.size()) {
    for (int i = 0; i < 10; ++i) 
      if (accept(digits[i])) {
        return true;
      }
  }
  return false;
}

/*
intConstant() {
  skipWS();
  s = lookAhead(1);
  if (acceptDigit()) {
    const = digit2int(s);
    s = lookAhead(1);
    while (acceptDigit()) {
      const = const * 10 + digit2int(s);
      s = lookAhead(1);
    }
    skipWS();
    return [const, <>];
  }
  else return [];
}
*/
std::optional<IntConstant *> Parser::intConstant() {
  skipWS();
  char s = lookAhead(1)[0];
  if (acceptDigit()) {
    IntConstant *cnst = new IntConstant();
    string str;         // added
    str.push_back(s);   // added
    s = lookAhead(1)[0];
    while (acceptDigit()) {
      str += s;
      s = lookAhead(1)[0];
    }
    skipWS();
    cnst->addLabel(str);  // added
    return cnst;
  }
  return std::nullopt;
}

/*
// part of the PrimaryExpression
tokenExpression() {
  ast = intConstant();
  if (ast != []) return ast;
  ast = boolConstant();  // it must be before the variable name (greedy approach)
  if (ast != []) return ast;
  ast = varName();
  return ast;
}
*/

std::optional<TokenExpression*> Parser::tokenExpression() {
  std::optional<IntConstant*> astIC = intConstant();
  if (astIC.has_value()) return astIC.value();
  std::optional<VarName*> astVN = varName();
  if (astVN.has_value()) return astVN.value();
  return std::nullopt;
}

/*
// part of the PrimaryExpression
bracketExpression() {
  if (accept("(")) {
    ast = expression();
    expect(")");
  }
  if (ast != []) return ast;
  error("bracketExpression: syntax error");
}
*/

std::optional<BracketExpression*> Parser::bracketExpression() {
  if (accept("(")) {
    std::optional<Expression*> astE = expression();
    if (astE.has_value()) {
      expect(")");
      return new BracketExpression(astE.value());
    }
  }
  return std::nullopt;
}


/*
multiplicativeExpression() {
  // the next two lines modified according to new definition
  ast = tokenExpression();
  if (ast == []) ast = bracketExpression();
  list = < ast >;
  tag = "_";
  s = lookAhead(1);
  while (accept("*") || accept("/") || accept("%")) {
    // ast1 = primaryExpression();
    ast1 = tokenExpression();
    if (ast1 == []) ast = bracketExpression();
    list.pushBack(ast1);
    tag = tag + s + "_";
    skipWS();
    s = lookAhead(1);
  }
  if (list.size() > 1)
    return [tag, list];
  else
    return list.at(0);
}
*/

std::optional<MultExpression*> Parser::multExpressionFirst() {
  optional<MultExpression*> ast = std::nullopt;
  std::optional<TokenExpression*> astPTE = tokenExpression();
  if (astPTE.has_value()) {
    ast = new MultExpression(astPTE.value());
  }
  else {
    std::optional<BracketExpression*> astPBE = bracketExpression();    
    if (astPBE.has_value()) {
      ast = new MultExpression(astPBE.value());
    }
  }
  return ast;
}
  
std::optional<MultExpression*> Parser::multExpression() {
  optional<MultExpression*> ast = multExpressionFirst();
  if (ast.has_value()) {
    std::string s = lookAhead(1);
    while (accept("*") || accept("/") || accept("%")) {
      optional<MultExpression*> astnext = multExpressionFirst(); 
      if (astnext.has_value()) {
	ast.value()->addChild(astnext.value());
	ast.value()->addLabel(s);
	skipWS();
	s = lookAhead(1);
      }
    }
  }
  return ast;
}

/*
arithExpression() {
  ast = multiplicativeExpression();
  list = < ast >;
  tag = "_";
  s = lookAhead(1);
  while (accept("+") || accept("-")) {
    ast1 = multiplicativeExpression();
    list.pushBack(ast1);
    tag = tag + s + "_";
    skipWS();
    s = lookAhead(1);
  }
  if (list.size() > 1)
    return [tag, list];
  else
    return list.at(0);
}
*/
std::optional<ArithExpression*> Parser::arithExpression() {
  optional<ArithExpression*> ast = std::nullopt;
  std::optional<MultExpression*> astME = multExpression();
  if (astME.has_value()) {
    ast = new ArithExpression(astME.value());
    std::string s = lookAhead(1);
    while (accept("+") || accept("-")) {
      astME = multExpression();
      if (astME.has_value()) {
        ast.value()->addChild(astME.value());
        ast.value()->addLabel(s);
	skipWS();
        s = lookAhead(1);
      }
    }
  }
  return ast;
}


/*
  expression() {
  ast = arithExpression();
  if (ast != []) return ast;
  }
*/
std::optional<Expression*> Parser::expression() {
  return arithExpression();;
}


// Expression* loadf(ifstream& f)
// {
//   if (f.eof())
//     throw "Unknown file.";
//   string tag;
//   f >> tag;
//   return loadfRec(f, tag);
// }
