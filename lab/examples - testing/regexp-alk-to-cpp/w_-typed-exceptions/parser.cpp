#include "parser.h"

void Parser::nextSym() {
  if (index < input.size()) {
    index++;
  }
  else {
    ParserException exc;
    exc.setBadPos(index);
    throw exc;
  }
}

void Parser::expect(char s) {
  if (accept(s)) {
    return;
  }
  // error("unexpected symbol at position " + to_string(index));
  // return false;
  ParserException exc;
  exc.setErrMsg(string("unexpected symbol"));
  exc.setBadPos(index);
  throw exc;
}

Ast* Parser::factor() {
  Ast* past;
  char s = sym();
  if (acceptSigma()) {
    past = new AstNonEmpty(string(1, s));
  } else if (accept('(')) {
    past = expression();
    expect(')');
  } // else ???
  else {
    ParserException exc;
    exc.setErrMsg(string("expected alphabet symbol or ("));
    exc.setBadPos(index);
    throw exc;
  }
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




