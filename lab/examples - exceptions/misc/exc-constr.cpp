#include <iostream>
using namespace std;

class A 
{
public:
  A(const char* s="\0") throw(int);
  ~A();
private:
  static int objNo;
  int id;
  char* nume;
};

A::A(const char* s) throw(int) {
  int n = strlen(s);
  nume = new char[n+1];
  strcpy(nume, s);
  objNo++;
  id = objNo;
  cout << id << " A() "<< s << endl;;
  if (objNo == 3) throw int(3);
  if (isdigit(s[0])) throw char(*s);
}

A::~A() {
  cout << id << " ~A()\n";
  delete [] nume;
  objNo--;
}

void my_unexpected() 
{
  cout << "Unexpected exception.\n";
  throw;
}
void my_terminate() 
{
  cout << "Come back in 5 min.\n";
  exit(1);
}

int A::objNo = 0;

int main() {
  set_unexpected(my_unexpected);
  set_terminate(my_terminate);
  try {
    A a("start");
    A* b = new A[5];
    A c("stop");
  } catch (int i) {
    cout << "Exception: " << i << endl;
  }
  try {
    A d("1234");
  } catch (char c) {
    cout << "It was thrown " << c << endl;
  }
  return 0;
}

