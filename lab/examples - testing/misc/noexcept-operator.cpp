#include <iostream>

class A {
public:
  A() noexcept(false) {
    throw 2;
  }
};

class B {
public:
  B() noexcept(true) {  }
};

template <typename T>
void f() {
  if (noexcept(T()))
    std::cout << "NO possible exception in Implicit Constructor" << std::endl;
  else 
    std::cout << "Possible exception in Implicit Constructor" << std::endl;
}

int main() {
  f<A>();
  f<B>();
}

