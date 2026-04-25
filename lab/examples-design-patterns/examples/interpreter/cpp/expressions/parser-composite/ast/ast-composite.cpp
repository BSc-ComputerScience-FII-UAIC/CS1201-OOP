#include "ast-composite.h"
#include <iostream>

list<string> Expression::getLabel() const {
  return label;
}

void Expression::addLabel(const string& str) {
  label.push_back(str);
}

string CompoundExpression::toString() {
  list <Expression*>::const_iterator ite;
  auto its = label.begin();
  string str = children.size() > 1 ? "(" : "";
  int i = 0;
  for(ite = children.begin(); ite != children.end(); ++ite) {
    if (i > 0) {
      str += " " + *its + " ";
      ++its;
    }
    str += (*ite)->toString();
    ++i;
  }
  if (children.size() > 1) str += ")";
  return str;
}

list<Expression*> CompoundExpression::getChildren() {
  return children;
}

void CompoundExpression::addChild(Expression* pe) {
  children.push_back(pe);
}


ArithExpression::ArithExpression(MultExpression* pme) {
  if (pme) children = list<Expression*>(1, pme);
}

MultExpression::MultExpression(TokenExpression* pte) {
  if (pte) children = list<Expression*>(1, pte);
}

MultExpression::MultExpression(BracketExpression* pbe) {
  if (pbe) children = list<Expression*>(1, pbe);
}			  

BracketExpression::BracketExpression(Expression* pe) {
  if (pe) children = list<Expression*>(1, pe);
}

string BracketExpression::toString() {
  if (!children.empty())
    return string("(") + (*children.begin())->toString() + string(")");
  return "";
}
						       
IntConstant::operator int() const {
  int cnst = 0;
  for (int i = 0; i < (*label.begin()).size(); ++i)
    cnst = cnst * 10 + (*label.begin())[i] - '0';
  return cnst;
}

string IntConstant::toString() {
  return *getLabel().begin();
}

VarName::VarName(const string& name) {
  if (!name.empty()) label = list<string>(1, name);
}
