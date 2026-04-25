#ifndef _VISITOR_H
#define _VISITOR_H

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
  virtual void visitIntConstant(IntConstant*) = 0;
  virtual void visitVarName(VarName*) = 0;
  virtual void visitCompoundExpression(CompoundExpression*) {}
  virtual void visitMultExpression(MultExpression*) {}
  virtual void visitArithExpression(ArithExpression*) {}
  virtual void visitBracketExpression(BracketExpression*) {}
 protected:
  Visitor(){};
};


#endif
