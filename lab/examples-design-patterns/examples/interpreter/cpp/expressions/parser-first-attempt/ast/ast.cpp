#include "ast.h"
#include <iostream>

Digit::Digit(char c) {
  if ('0' <= c && c <= '9')
    sym = c;
  else throw "Non digit char.";
}


string ArithExpression::toString() {
  list <MultExpression*>::const_iterator itme;
  list<string>::const_iterator its = label.begin();
  string str = children.size() > 1 ? "(" : "";
  int i = 0;
  for(itme = children.begin(); itme != children.end(); ++itme) {
    if (i > 0) {
      str = str + " " + *its + " ";
      ++its;
    }
    str = str + (*itme)->toString();
    ++i;
  }
  if (children.size() > 1) str += ")";
  return str;
}

string MultExpression::toString() {
  list <PrimaryExpression*>::const_iterator itpe;
  list<string>::const_iterator its = label.begin();
  string str = children.size() > 1 ? "(" : "";
  int i = 0;
  for(itpe = children.begin(); itpe != children.end(); ++itpe) {
    if (i > 0) {
      str += " " + *its + " ";
      ++its;
    }
    str = str + (*itpe)->toString();
    ++i;
  }
  if (children.size() > 1) str += ")";
  return str;
}

/*
  s = lookAhead(1);
  const = digit2int(s);
  while (acceptDigit()) {
  s = lookAhead(1);
  const = const * 10 + digit2int(s);
  }
*/
IntConstant::operator int() const {
  list <Digit>::const_iterator it;
  int cnst = 0;
  for(it = digits.begin(); it != digits.end(); ++it) 
    cnst = cnst * 10 + *it ;
  return cnst;
}

void IntConstant::computeLabel() {
  list <Digit>::const_iterator it;
  string str = "";
  for(it = digits.begin(); it != digits.end(); ++it) 
    str += it->getLabel();
  label.push_back(str);
}
