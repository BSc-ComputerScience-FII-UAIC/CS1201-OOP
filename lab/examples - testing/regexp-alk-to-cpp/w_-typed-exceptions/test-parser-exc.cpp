#include "parser.h"

void printMenu() {
    cout << "\nMenu\n";
    cout << "1. OK.\n";
    cout << "2. Not OK.\n";
    cout  << "0. Exit\n";
}
 void ok()  {
    vector<char> alph{'a', 'b', 'c'};  // c++11
    Parser parser(alph);
    parser.setInput("(a.b+c)*.(b.a)");
    Ast* past = parser.expression();
    past->print();
 }

 void notOK() {
    vector<char> alph{'a', 'b', 'c'};  // c++11
    Parser parser(alph);
    parser.setInput("(a.b+");
    Ast* past = parser.expression();  // it should be an exception
    past->print();
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
                    notOK();
                    break;
                default:
                    break;
            }
        }
        catch (MyException& exc) {
            exc.debugPrint();
            cout << "Here the parsing exceptions can be handled." << endl;
        }
    } while (option > 0);
    return 0;
}