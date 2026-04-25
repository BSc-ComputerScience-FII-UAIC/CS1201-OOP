#include "parser.h"

void Parser::nextSym() {
  if (index < input.size()) {
    index++;
  }
  else {
    throw "Error: index out of input size";
  }
}

//bool Parser::expect(char s) {
void Parser::expect(char s) {
  if (accept(s)) {
    // return true;
    return;
  } 
  // error("unexpected symbol at position " + to_string(index));
  // return false;
  throw s;
}

Ast* Parser::factor() {
  Ast* past;
  char s = sym();
  if (acceptSigma()) {
    past = new AstNonEmpty(string(1, s));
  } else if (accept('(')) {
    past = expression();
    expect(')');
  }
  // else ???
  else
    throw "expected alphabet symbol or (.";
  return past;
}

Ast* Parser::maybeStar() {
  Ast* past = factor();
  if (accept('*')) {
    vector<Ast*> list;
    list.push_back(past);
    return new AstNonEmpty("_*", list);
  }
  else
    return past;
}

Ast* Parser::term() {
  Ast* past = maybeStar();
  vector<Ast*> list;
  list.push_back(past);
  while (accept('.')) {
    past = maybeStar();
    list.push_back(past);
  }
  if (list.size() > 1)
    return new AstNonEmpty("_._", list);
  else
    return list.at(0);
}

Ast* Parser::expression() {
  Ast* past = term();
  vector<Ast*> list;
  list.push_back(past);
  while (accept('+')) {
    past = term();
    list.push_back(past);
  }
  if (list.size() > 1)
    return new AstNonEmpty("_+_", list);
  else
    return list.at(0);
}




