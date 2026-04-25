#include "parser-factory.h"
#include <optional>
#include <string>

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
    //cnst->addDigit(Digit(s));
    string str;         // added
    str.push_back(s);   // added
    s = lookAhead(1)[0];
    while (acceptDigit()) {
      //cnst->addDigit(Digit(s));
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
    return ast;
  }
*/

std::optional<Expression*> Parser::bracketExpression() {
  if (accept("(")) {
    std::optional<Expression*> astE = expression();
    if (astE.has_value()) {
      expect(")");
      std::optional<BracketExpression*> ast = new BracketExpression();
      ast.value()->addChild(astE.value());
      return ast;
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
        ast1 = primaryExpression();
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
std::optional<Expression*> Parser::multExpression() {
  std::optional<Expression*> astPE = tokenExpression();
  if (!astPE.has_value()) astPE = bracketExpression();
  std::optional<MultExpression*> ast = std::nullopt;
  if (astPE.has_value()) {
    ast = new MultExpression();
    ast.value()->addChild(astPE.value());
  }
  std::string s = lookAhead(1);
  while (accept("*") || accept("/") || accept("%")) {
    astPE = tokenExpression();     // modified according to the new definition
    if (!astPE.has_value()) astPE = bracketExpression();  // added
    if (astPE.has_value()) {
      ast.value()->addChild(astPE.value());
      ast.value()->addLabel(s);
      skipWS();
      s = lookAhead(1);
    }
  }
  if (ast.value()->getChildren().size() > 1) return ast;
  else return astPE;
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
std::optional<Expression*> Parser::arithExpression() {
  std::optional<Expression*> astME = multExpression();
  std::optional<ArithExpression*> ast = std::nullopt;
  if (astME.has_value()) {
    ast = new ArithExpression();
    ast.value()->addChild(astME.value());
  };
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
  if (ast.value()->getChildren().size() > 1) return ast;
  else return astME;
}


/*
expression() {
    ast = arithExpression();
    if (ast != []) return ast;
}
*/
std::optional<Expression*> Parser::expression() {
  std::optional<Expression*> ast = arithExpression();
  if (!ast.has_value()) ast = bracketExpression();
  return ast;
}
