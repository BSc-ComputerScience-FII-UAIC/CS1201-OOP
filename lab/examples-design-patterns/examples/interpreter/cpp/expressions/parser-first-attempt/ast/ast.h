#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <list>
#include <iostream>

using namespace std;

// forward declarations
class AndExpression;
class RelExpression;
class ArithExpression;
class MultExpression;
class PrimaryExpression;

class Digit {
 public: Digit(char = '0');
  /*
    digit2int(s) {
    digits = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];
    if ("0" <= s && s <= "9")
    for (i = 0; i < 10; ++i)
    if (s == digits[i]) return i;
    }
  */
 public: operator int() const {return sym - '0';}
 public: string getLabel() const { return  string(1, sym); }
 private: char sym;
};


class Expression {
 public: virtual list<string> getLabel() const { return label; }
 public: virtual void addLabel(string str) { label.push_back(str); }
 public: virtual string toString() { return ""; }
 protected: list<string> label;
};


/*
  Expression ::=
  ArithExpression
  ArithExpression ::=
  MultExpression (("+" | "-") MultExpression)
*/
class ArithExpression : public Expression {
 public: void addChild(MultExpression* me) { children.push_back(me); }
 public: list<MultExpression*> getChildren() { return children; }
 public:string toString();
 private: list<MultExpression*> children;
};

/*
  MultExpression ::=
  PrimaryExpression (("*" | "/" | "%") PrimaryExpression)*

*/
class MultExpression : public Expression {
 public: void addChild(PrimaryExpression* pe) { children.push_back(pe); }
 public:list<PrimaryExpression*> getChildren() { return children; }
 public: string toString();
 private: list<PrimaryExpression*> children;
};

/*
  PrimaryExpression ::=
  IntConstant
  | BoolConstant
  | VarName
  | "(" Expression ")"   

*/    
class PrimaryExpression : public Expression {
 public: void addChild(Expression* e) { child = e; }
 private: Expression* child;
};

/*
  IntConstant ::=
  Digit+
*/
class IntConstant : public PrimaryExpression {
 public: void addDigit(Digit d) { digits.push_back(d); }  // strong agregation
 public: operator int() const;
 public: list<string> getLabel() {
    computeLabel();
    return label;
  }
 public: string toString() { return *getLabel().begin(); }
 private: void computeLabel();
 private: list<Digit> digits;
};


class VarName : public PrimaryExpression {
 public: VarName(string name = "") { label.push_back(name); }
 public: string toString() { return *getLabel().begin(); }
};

#endif
