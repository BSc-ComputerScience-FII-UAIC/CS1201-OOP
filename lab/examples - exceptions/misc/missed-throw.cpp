#include <iostream>
#include <exception>
using namespace std;

class One :  public exception { };
class Two :  public exception { };
void g() {
  throw "Surprise.";
}
void fct(int x) throw (One, Two) {
  switch (x){
  case 1: throw One();
  case 2: throw Two();
  }
  g();
}

void my_unexpected() {
  cout << "My unexpected exception.\n";
  exit(1);
}
int main(void) {
  set_unexpected(my_unexpected);
  int option = 1;
  while (option > 0){
    cout << "Option (1-3, 0 - exit): "; 
    cin >> option;
    try {
      fct(option);	
    } catch (One) {
      cout << "Exception one" << endl;
    } catch (Two)  {
      cout << "Exception two" << endl;
    }
  }
  return 0;
}
