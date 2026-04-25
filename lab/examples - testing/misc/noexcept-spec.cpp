#include <iostream>

void h() {
    throw "Exception in h";
}

void f() noexcept(false) {
    h();
    //throw "Exception in f";
}

void g() noexcept(false) {
    throw "Exception in g";
}

int main() {
    try {
        f();
        g();
    }
    catch(char const* exc) {
        std::cout << exc << "\n";
    }
    return 0;
}