#include "ast/ast-visitor.h"
#include "state.h"
#include "visitor-eval.h"
#include "parser/parser-visitor.h"
#include <iostream>

int main()
{
  try {
    char str[80];
    std:: cout << "Input ({a,b}-expr): ";
    std::cin.getline(str, 80);  
    Parser p(str);
   
    std::optional<Expression*> ae = p.expression();
    
    if (ae.has_value()) std::cout << ae.value()->toString() << "\n";
    else std::cout << "nothing\n";
    
    State st;
    VarName a("a"), b("b");
    st.update(a, 10);
    st.update(b, 5);
    st.print();
    VisitorEval visitorEval1(st);
    if (ae.has_value()) {
      ae.value()->accept(visitorEval1);
      cout << "ae = " << visitorEval1.getCumulateVal() << endl;
    }
  }
  catch (char const *msg) {
    std::cout << msg << "\n";
    return 1;
  }
  return 0;
}
