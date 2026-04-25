#ifndef _VISITOR_H
#define _VISITOR_H
#include <iostream>

class TokenExpression;
class IntConstant;
class BoolConstant;
class VarName;
class CompoundExpression;
class MultExpression;
class ArithExpression;
class RelExpression;
class AndExpression;
class BoolExpression;
class BracketExpression;

class Visitor {
 public:
  virtual void visitTokenExpression(TokenExpression*) {}
  virtual void visitIntConstant(IntConstant*) {}
  virtual void visitVarName(VarName*) {}
  virtual void visitCompoundExpression(CompoundExpression*) {}
  virtual void visitMultExpression(MultExpression*) {}
  virtual void visitArithExpression(ArithExpression*) {}
  virtual void visitBracketExpression(BracketExpression*) {}
  virtual void visitIntConstant(IntConstant*, std::ofstream&) = 0;
  virtual void visitVarName(VarName*, std::ofstream&) = 0;
  virtual void visitMultExpression(MultExpression*, std::ofstream&) {}
  virtual void visitArithExpression(ArithExpression*, std::ofstream&) {}
 protected:
  Visitor(){};
};


#endif
