#include "ast.h"

void printMenu() {
    cout << "\nMenu\n";
    cout << "1. OK.\n";
    cout << "2. Empty AST (not OK).\n";
    cout << "3. Non-empty AST (not OK).\n";
    cout  << "0. Exit\n";
}

void ok() {
  AstNonEmpty a("a");
  AstNonEmpty b("b");
  vector<Ast*> l = {&a, &b};
  AstNonEmpty aplusb("_+_", l);
  cout << endl;
  cout << "aplusb.print(): ";
  aplusb.print();  // this is OK
  cout << endl;
}

void emptyAst() {
    AstEmpty  ast;
    cout << "ast.child(1)->print(): ";
    ast.child(1)->print();
    cout << endl;
    cout << "ast.chldNo(): ";
    cout << ast.chldNo();
    cout << endl;
}

void nonEmptyAst(){
    AstNonEmpty a("a");
    AstNonEmpty b("b");
    vector<Ast*> l = {&a, &b};
    AstNonEmpty aplusb("_+_", l);
    cout << endl;
    cout << "child(2)->print(): ";
    aplusb.child(2)->print();  // here should be an exception
    cout << endl;
}

int main() {
    int option;
    do {
        printMenu();
        cout << "\nOption: ";
        cin >> option;
        try {
            switch (option) {
                case 1: 
                    ok();
                    break;
                case 2:
                    emptyAst();
                    break;
                case 3:
                    nonEmptyAst();
                    break;
                default:
                    break;
            }
        }    
        catch (MyException exc) {
            
            exc.debugPrint();
            cout << "Here the exceptions can be handled." << endl;
        }
    } while (option > 0);
    return 0;
}

