//#include "ast-composite.h"
#include "parser/parser-composite.h"
#include <iostream>
//#include <optional>

int main() {
  char str[80];
  std::cout << "Input: ";
  std::cin.getline(str, 80);
  Parser p(str);
  //Parser p(b + a * 3 / 5");
  try {
      std::optional<Expression *> ast = p.expression();
      if (ast.has_value()) {
          std::cout << ast.value()->toString() << "\n" << p.getIndex() << "\n";
      }
  }
  catch (const char* msg) {
      std::cout << msg << "\n";
  }
  return 0;
}
