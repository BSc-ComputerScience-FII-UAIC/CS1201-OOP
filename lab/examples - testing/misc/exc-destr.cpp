#include <iostream>

class A {
    public:
    /*
        ~A() {
            throw "Thrown by Destructor";
        }
    */
        ~A() noexcept(false) {
            throw "Thrown by Destructor";
        }
};
int main() {
    try {
        A   a;
    }
    catch(const char *exc){
      std::cout << "Print " << exc << "\n";
    }
}