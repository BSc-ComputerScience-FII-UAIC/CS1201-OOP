#include "ast.h"

Ast* AstNonEmpty::child(int i) {
  if (0 <= i and i < chldNo()) {
    return children[i];
  }
  throw "Error: index out of bounds.";
}
  

void AstNonEmpty::print() {
  cout << "[\"" << label << "\", <";
  for (int i = 0; i < chldNo(); ++i){
    children[i]->print();
    if (i < (chldNo() - 1))
      cout << ", ";
  }
  cout << ">]";
}
  
