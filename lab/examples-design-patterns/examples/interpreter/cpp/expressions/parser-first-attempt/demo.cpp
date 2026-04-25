//#include "ast.h"
#include "parser/parser.h"
#include <iostream>
#include <optional>

int main() {
  char str[80];
  std::cout << "Input: ";
  std::cin.getline(str, 80);
  Parser p(str);
  //Parser p(" a + b / 82");
  std::optional<Expression*> ast = p.arithExpression();
  if (ast.has_value()) {
    std::cout << ast.value()->toString() << "\n" << p.getIndex() << "\n";
  }
  return 0;
}
