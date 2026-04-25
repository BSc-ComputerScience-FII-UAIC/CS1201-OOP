#include <iostream>

class Base
{
public:
    Base() = default;
    virtual Base* clone() const { return new Base; }
    virtual ~Base(){ std::cout << "~Base()\n"; }
    virtual void introduceYourself() const {std::cout << "I am a Base.";}
};

class Derived : public Base
{
public:
    Derived () = default;
    Derived* clone() const override { return new Derived; }
    virtual void introduceYourself() const override {std::cout << "I am a Derived.\n";}
    ~Derived() override { std::cout << "~Derived()\n"; }
};

int main() {
    Derived d;
    Base* pb = d.clone();
    pb->introduceYourself();
    delete pb;
    return 0;
}
