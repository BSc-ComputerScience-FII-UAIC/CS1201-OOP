#include "expr-manager.h"
#include "visitors/visitor-storef.h"
#include "parser/parser-factory.h"
#include <iostream>

using namespace std;


int main()
{
  //Parser p("a + b");
  char str[80];
  std::cout << "Input: ";
  std::cin.getline(str, 80);
  Parser p(str);

  std::optional<Expression*> ast = p.expression();
  if (!ast.has_value()) {
    std::cout << "Parsing error.\n";
    return 1;
  }
    
  ofstream outfile("test.xml");
  VisitorStoref visitorStoref;
  ast.value()->accept(visitorStoref, outfile);
  outfile.close();

  Registrar aReg = createRegistrar();


  outfile.open("test-copy.xml", ios::out);
  ifstream inpfile("test.xml");

  try {
    Expression* exprCopy = ExprManager::loadf(inpfile, aReg);
    ast.value()->accept(visitorStoref, outfile);
  }
  catch(string msg) {
    cout << msg << endl;
  }
  inpfile.close();

  return 0;
}
