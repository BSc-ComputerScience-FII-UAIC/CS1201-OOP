#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <list>
#include <iostream>
#include "visitor.h"

using namespace std;

// forward declarations
class ArithExpression;
class MultExpression;

/* class Digit { */
/*  public: Digit(char = '0'); */
/*   /\* */
/*     digit2int(s) { */
/*     digits = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]; */
/*     if ("0" <= s && s <= "9") */
/*     for (i = 0; i < 10; ++i) */
/*     if (s == digits[i]) return i; */
/*     } */
/*   *\/ */
/*  public: operator int() const {return sym - '0';} */
/*  public: string getLabel() const { return  string(1, sym); } */
/*  private: char sym; */
/* }; */


class Expression {
 public: virtual list<string> getLabel() const { return label; }
 public: virtual void addLabel(string str) { label.push_back(str); }
 public: virtual string toString() { return ""; }
 public: virtual list<string> getLabel() { return label; }
 public: virtual void accept(Visitor& visitor) { } 
 protected: list<string> label;
};

class CompoundExpression : public Expression {
 public: void addChild(Expression* pe) { children.push_back(pe); }
 public: list<Expression*> getChildren() { return children; }
 public: string toString();
 public: void accept(Visitor& visitor);
 protected: list<Expression*> children;
};


/*
  ArithExpression ::=
  MultExpression (("+" | "-") MultExpression)
*/
class ArithExpression : public CompoundExpression {
 public: void accept(Visitor& visitor);
};

/*
  MultExpression ::=
  PrimaryExpression (("*" | "/" | "%") PrimaryExpression)*
  PrimaryExpression ::=
  TokenExpression
  | BracketExpression
*/
class MultExpression : public CompoundExpression {
 public: void accept(Visitor& visitor);
};

/*
  BracketExpression ::=
  | "(" Expression ")"   

*/    
class BracketExpression : public CompoundExpression {
 public: string toString();
 public: void accept(Visitor& visitor) {
    this->CompoundExpression::accept(visitor);
  }
  // to finish it
};


/*
  TokenExpression ::=
  IntConstant
  | BoolConstant
  | VarName   

*/    
class TokenExpression : public Expression {
  // to finish it
};

/*
  IntConstant ::=
  Digit+
*/
class IntConstant : public TokenExpression {
  // public: void addDigit(Digit d) { digits.push_back(d); }  // strong agregation
 public: void accept(Visitor& visitor) {
    visitor.visitIntConstant(this);
  }
 public: operator int() const;
 /* public: list<string> getLabel() { */
 /*    computeLabel(); */
 /*    return label; */
 /*  } */
 public: string toString() { return *getLabel().begin(); }
 /* private: void computeLabel(); */
 /* private: list<Digit> digits; */
};


class VarName : public TokenExpression {
 public: VarName(string name = "") { label.push_back(name); }
 public: string toString() { return *getLabel().begin(); }
 public: void accept(Visitor& visitor) {
    visitor.visitVarName(this);
  }
};

#endif
