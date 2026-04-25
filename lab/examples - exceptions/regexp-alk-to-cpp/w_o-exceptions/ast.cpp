#include "ast.h"

Ast* AstNonEmpty::child(int i) {
  if (0 <= i and i < chldNo()) {
    return children[i];
  }
  // error;
  return new AstEmpty; // ??
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
  
