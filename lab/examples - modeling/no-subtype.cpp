#include <iostream>

class Base {
public:
    Base() = default;
    ~Base() = default;
    void doBaseAction() const { privateBaseAction(); }
private:
    void privateBaseAction() const { std::cout << "A base action\n"; }
};

class Derived : public Base {
public:
    Derived() = default;
    ~Derived() = default;
    void doDerivedAction() const { std::cout << "A Derived action.\n"; };
};

int main() {
    Base b;
    Derived d;
    d.doBaseAction(); 
    return 0;
}