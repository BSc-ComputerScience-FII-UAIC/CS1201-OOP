#ifndef _PARSER_H_
#define _PARSER_H_

#include "ast/ast-factory.h"
#include <string>
#include <optional>


class Parser {
 public: Parser(string str) { input = str; index = 0; }
 public: string lookAhead(int);
 public: void skipWS();
 public: void nextSym(int);
 public: bool accept(string);
 public: bool expect(string);
 public: bool acceptDigit();
 public: std::optional<VarName*> varName();
 public: std::optional<IntConstant*> intConstant();
  // public: std::optional<Expression*> primaryExpression();
  public: std::optional<TokenExpression*> tokenExpression();
  public: std::optional<Expression*> bracketExpression();
 public: std::optional<Expression*> multExpression();
 public: std::optional<Expression*> expression();
 public: std::optional<Expression*> arithExpression();

 public: int getIndex() { return index; }
 private: string input;
 private: int index;
};

#endif

