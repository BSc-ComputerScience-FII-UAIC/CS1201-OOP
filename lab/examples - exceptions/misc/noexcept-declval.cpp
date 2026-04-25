#include <iostream>
using namespace std;

class C {
public:
  C() noexcept(true) {}
  //~C() {}
  ~C() noexcept(false) {}
};

template <typename T>
void g() {
  if (noexcept(std::declval<T>().~T()))
  //if (noexcept(~T()))
    std::cout << "NO Exception in Destructor\n";
  else 
    std::cout << "Possible Exception in Destructor\n";
}

int main() {
  g<C>();
}

