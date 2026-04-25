#include "visitor-eval.h"
#include <iostream>
#include <stack>


void VisitorEval::visitIntConstant(IntConstant* constant) {
  IntOrBool ib;
  ib.vint = *constant;
  valStack.push(ib);
}

	
void VisitorEval::visitVarName(VarName* variable) {
  IntOrBool ib;
  ib.vint = state.lookup(*variable);
  valStack.push(ib);
}
 
void VisitorEval::visitMultExpression(MultExpression* me) {
  list<string> label = me->getLabel();
  list<string>::reverse_iterator rits = label.rbegin();
  if (valStack.size() > 0) {
    int temp = valStack.top().vint;
    valStack.pop();
    while (rits != label.rend()) {
      if (*rits =="*") temp *= valStack.top().vint;
      if (*rits =="/") temp = valStack.top().vint / temp;
      if (*rits =="%") temp = valStack.top().vint % temp;
      valStack.pop();
      ++rits;
    }
    IntOrBool ib;
    ib.vint = temp;
    valStack.push(ib);
  }
}
  
void VisitorEval::visitArithExpression(ArithExpression* ae) {
  list<string> label = ae->getLabel();
  list<string>::reverse_iterator rits = label.rbegin();
  if (valStack.size() > 0) {
    int temp = valStack.top().vint;
    valStack.pop();
    while (rits != label.rend()) {
      if (*rits =="+")  temp += valStack.top().vint;
      if (*rits =="-")  temp = valStack.top().vint - temp;
      valStack.pop();
      ++rits;
    }
    IntOrBool ib;
    ib.vint = temp;
    valStack.push(ib);
  }
}
  
  
int VisitorEval::getCumulateVal() {
  if (valStack.size() > 0)
    return valStack.top().vint;
  else throw "Stack empty.";
}

