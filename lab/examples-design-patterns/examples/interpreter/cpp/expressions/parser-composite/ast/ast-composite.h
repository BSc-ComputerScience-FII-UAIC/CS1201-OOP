#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <list>
#include <iostream>

using namespace std;

template<typename Base, typename T>
  inline bool instanceof(const T*) {
  return is_base_of<Base, T>::value;
}

// forward declarations
class ArithExpression;
class MultExpression;
class TokenExpression;
class BracketExpression;

class Expression {
 public: [[nodiscard]] virtual list<string> getLabel() const;
 public: virtual void addLabel(const string& str);
 public: virtual string toString() = 0;
 protected: list<string> label;
};

class CompoundExpression : public Expression {
 public: virtual void addChild(Expression* pe);
 public: string toString() override;
 public: list<Expression*> getChildren();
 protected: list<Expression*> children;
};


/*
  Expression ::=
  ArithExpression
  ArithExpression ::=
  MultExpression (("+" | "-") MultExpression)*
*/
class ArithExpression : public CompoundExpression {
 public: explicit ArithExpression(MultExpression* pme = nullptr);
};

/*
  MultExpression ::=
  PrimaryExpression (("*" | "/" | "%") PrimaryExpression)*
  PrimaryExpression ::=
  TokenExpression
  | BracketExpression
*/
class MultExpression : public CompoundExpression {
 public: explicit MultExpression(TokenExpression* pte = nullptr);
 public: explicit MultExpression(BracketExpression* pbe = nullptr);
};

/*
  BracketExpression ::=
  | "(" Expression ")"   

*/    
class BracketExpression : public CompoundExpression {
 public: explicit BracketExpression(Expression* pe = nullptr);
 public: string toString() override;
  // to finish it
};


/*
  TokenExpression ::=
  IntConstant
  | VarName   

*/    
class TokenExpression : public Expression {
  // nothing
};

/*
  IntConstant ::=
  Digit+
*/
class IntConstant : public TokenExpression {
 public: explicit operator int() const;
 public: string toString() override;
};


class VarName : public TokenExpression {
 public: explicit VarName(const string& name = "");
 public: string toString() override { return *getLabel().begin(); }
};

#endif
