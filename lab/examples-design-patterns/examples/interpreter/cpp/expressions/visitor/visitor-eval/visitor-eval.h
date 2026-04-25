#ifndef VISITOR_EVAL_H
#define VISITOR_EVAL_H
#include "../visitor.h"
#include "state.h"
#include <iostream>
#include <stack>

class VisitorEval : public Visitor {
public:
  union IntOrBool {
    int vint;
    bool vbool;
  };
  VisitorEval(State aState)
  {
    state = aState;
  }

  void visitIntConstant(IntConstant* constant);	
  void visitVarName(VarName* variable);
  void visitMultExpression(MultExpression* me);
  void visitArithExpression(ArithExpression* ae);
  int getCumulateVal();
private:
  State state;
  stack<IntOrBool> valStack;
};
#endif
