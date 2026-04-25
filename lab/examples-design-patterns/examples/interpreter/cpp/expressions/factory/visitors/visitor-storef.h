#ifndef _VISITOR_STOREF_H
#define _VISITOR_STOREF_H
#include "../../visitor/visitor.h"

class VisitorStoref : public Visitor {
 public:
    string indent = "";
  
  void visitIntConstant(IntConstant* intconst, ofstream& f) {
    f << indent;
    f << "<intConstant> " << intconst->toString() <<" </intConstant>";
    f << endl;
  }
	
  void visitVarName(VarName* varname, ofstream& f) {
    f << indent;
    f << "<varName> " << varname->toString() <<" </varName>";
    f << endl;
  }

  void visitMultExpression(MultExpression* mult, ofstream& f) {
    f << indent;
    f << "<mult>" << endl;
    indent += "  ";
    print(f, mult->getLabel(), indent);
    mult->CompoundExpression::accept(*this, f);
    indent = indent.erase(indent.size()-2,2);
    f << indent;
    f << "</mult>" << endl;
  }

  void visitArithExpression(ArithExpression* arith, ofstream& f) {
    f << indent.c_str();
    f << "<arith>" << endl;
    indent += "  ";
    print(f, arith->getLabel(), indent);
    arith->CompoundExpression::accept(*this, f);
    indent = indent.erase(indent.size()-2,2);
    f << indent;
    f << "</arith>" << endl;
  }

 private: static void print( ofstream& f, list<string> label, string indent) {
    f << indent << "<label> [";
    for (list<string>::iterator it = label.begin(); it != label.end(); ++it) {
      if (it == label.begin())
	    f << *it;
      else
	    f << "," << *it;
    }
    f << "] </label>" << endl;
  }
};
#endif
