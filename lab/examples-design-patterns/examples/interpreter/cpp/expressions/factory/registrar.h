#ifndef _REGISTRAR_H
#define _REGISTRAR_H

#include "ast/ast-factory.h"
#include <map>
#include <string>

using namespace std;

typedef Expression* ( * CreateExprFn )();

class Registrar
{
 public:
  Registrar() {}
  bool registerExpr(string tag, CreateExprFn createExprFn )
  {
    return catalog.insert( std::pair<string, CreateExprFn>(tag, createExprFn) ).second;
  }

  void unregisterExpr(string tag)
  {
    catalog.erase(tag);
  }

  Expression* createExpr(string tag)
  {
    map<string, CreateExprFn>::iterator i;
    i = catalog.find(tag);
    if ( i == catalog.end() )
      throw string( "Unknown expression tag " + tag );
    return (i->second)();
  }
 protected:
  map<string, CreateExprFn> catalog;
};


Expression* createIntConstant() {
    return new IntConstant();
}


Expression* createVarName() {
    return new VarName();
}

Expression* createMultExpression() {
    return new MultExpression();
}


Expression* createArithExpression() {
    return new ArithExpression();
}

Registrar createRegistrar() {
    Registrar aReg;
    aReg.registerExpr("<intConstant>", createIntConstant);
    aReg.registerExpr("<varName>", createVarName);
    aReg.registerExpr("<mult>", createMultExpression);
    aReg.registerExpr("<arith>", createArithExpression);
    return aReg;
}

#endif


