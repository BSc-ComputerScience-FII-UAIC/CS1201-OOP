#ifndef _PARSER_H_
#define _PARSER_H_

#include "ast/ast-composite.h"
#include <string>
#include <optional>


class Parser {
 public: Parser(string str = "");
 public: string lookAhead(int);
 public: void skipWS();
 public: void nextSym(int);
 public: bool accept(string);
 public: bool expect(string);
 public: bool acceptDigit();
 public: std::optional<VarName*> varName();
 public: std::optional<IntConstant*> intConstant();
  // public: std::optional<Expression*> primaryExpression();  //replaced by token and bracket
 public: std::optional<TokenExpression*> tokenExpression();
 public: std::optional<BracketExpression*> bracketExpression();
 public: std::optional<MultExpression*> multExpression();
 public: std::optional<Expression*> expression();
 public: std::optional<ArithExpression*> arithExpression();

 public: int getIndex();
 private: string input;
 private: int index;
 private: std::optional<MultExpression*> multExpressionFirst();   //helper
};

#endif

