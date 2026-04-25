#include <iostream>

using namespace std;

class A {
public:
	virtual void f() { cout << "A" << endl; }
};
class B : public A {
public:
	virtual void f() override { cout << "B" << endl; }
};
class C : public B {
public:
	void f() final { cout << "C" << endl; }
};

int main()
{
	B* a = new C();
	a->f();
	return 0;
}
/*#include "Multimi.h"

int main()
{
	Multime A(5, 1, 2, 3, 4, 5);
	Multime B(4, 2, 3, 4, 6);
	Multime C;
	Multime D = { 3, 200, 300, 400 };
	D.Print();
	A.Print();
	B.Print();
	C = A * B;
	C.Print();
	C = A - B;
	C.Print();
	C = B - A;
	C.Print();
	C = A + B;
	C.Print();
	std::cout << C[1] << std::endl;
	C = A * B;
	C = C(0, 5);
	C.Print();
	return 0;
}*/