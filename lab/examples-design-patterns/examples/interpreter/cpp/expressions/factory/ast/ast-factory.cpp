#include "ast-factory.h"
#include <iostream>

// Digit::Digit(char c) {
//   if ('0' <= c && c <= '9')
//     sym = c;
//   else throw "Non digit char.";
// }

string CompoundExpression::toString() {
  list <Expression*>::const_iterator ite;
  list<string>::const_iterator its = label.begin();
  string str = children.size() > 1 ? "(" : "";
  int i = 0;
  for(ite = children.begin(); ite != children.end(); ++ite) {
    if (i > 0) {
      str = str + " " + *its + " ";
      ++its;
    }
    str = str + (*ite)->toString();
    ++i;
  }
  if (children.size() > 1) str += ")";
  return str;
}

void CompoundExpression::accept(Visitor& visitor) {
    list<Expression*>::iterator it;
    for ( it = children.begin(); it != children.end(); ++it)
      (*it)->accept(visitor);
  }


void CompoundExpression::accept(Visitor& visitor, ofstream& f) {
  list<Expression*>::iterator it;
  for ( it = children.begin(); it != children.end(); ++it)
    (*it)->accept(visitor, f);
}


void ArithExpression::accept(Visitor& visitor) {
    this->CompoundExpression::accept(visitor);
    visitor.visitArithExpression(this);
  }

void MultExpression::accept(Visitor& visitor) {
    this->CompoundExpression::accept(visitor);
    visitor.visitMultExpression(this);
  }


string BracketExpression::toString() {
  if (children.size() > 0) return (*children.begin())->toString();
  return "";
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
  //  list <Digit>::const_iterator it;
  int cnst = 0;
  // for(it = digits.begin(); it != digits.end(); ++it) 
  //   cnst = cnst * 10 + *it ;
  for (int i = 0; i < (*label.begin()).size(); ++i)
    cnst = cnst * 10 + (*label.begin())[i] - '0' ;
  return cnst;
}

// void IntConstant::computeLabel() {
//   list <Digit>::const_iterator it;
//   string str = "";
//   for(it = digits.begin(); it != digits.end(); ++it) 
//     str += it->getLabel();
//   label.push_back(str);
// }

void IntConstant::loadInfo(ifstream& f) {
  int val;
  f >> val;
  stringstream ss;
  ss << val;
  label.push_front(ss.str());
}


void VarName::loadInfo(ifstream& f) {
  char c;
  f >> c;
  string name;
  name.push_back(c);
  label.push_front(name);
}
