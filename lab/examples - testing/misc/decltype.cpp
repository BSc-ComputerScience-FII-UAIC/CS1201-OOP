#include <iostream>

int main() {
    double a = 2.5;
    int b = 3;
    decltype(a) c = a*b;
    decltype(b) d = a*b;
    std::cout << "c: " << c << "\nd: " << d << "\n";
}