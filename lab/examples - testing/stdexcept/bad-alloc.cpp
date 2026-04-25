#include<iostream>
#include <string>
#include <new>

using namespace std;

void printMenu() {
  cout << "\n1. Negative.\n";
  cout << "2. Small.\n";
  cout << "3. Large.\n";
  cout << "Option: ";
}

int main(void)
{
  // bad_alloc exception
  int negative = -1;
  int small = 1;
  int large = INT_MAX;
  int opt = -1;
  while (opt != 0) {
    try {
      printMenu();
      cin >> opt;
      switch (opt) {
      case 1: new int[negative]; break;
      case 2: new int[small]{1,2,3};  break;
      case 3: new int[large][1000000]; break;
      default: opt = 0;
      }
    } catch(const std::bad_array_new_length &e) {
      cout << "bad_array_new_length caught: " << e.what() << '\n';
    } catch(const std::bad_alloc &e) {
      cout << "bad_alloc caught: " << e.what() << '\n';
    } catch(...) {
      cout << "unknown exceptions caught.";
    }
  }
}
