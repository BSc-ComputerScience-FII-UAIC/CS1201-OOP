#include<iostream>
#include <string>
#include <functional>

int main(void) {

  std::function<int()> f = nullptr;
  try {
    f();
  } catch(const std::bad_function_call& e) {
    std::cout << "bad_function_call caught: " << e.what() << '\n';
  }
  return 0;
}
