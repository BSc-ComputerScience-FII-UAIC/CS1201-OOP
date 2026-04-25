#include <iostream>
#include "Propozitie.h"
#include <vector>

using namespace std;

class Math {
protected:
	Math()
	{
		cout << "Math\n";
	}
public:

	static bool isGreater(int x, int y)
	{
		return x > y;
	}
	virtual bool isLower(int x, int y)
	{
		cout << "is lower (math)\n";
		return x < y;
	}
};

class A : public Math {
public:
	A()
	{
		cout << "A\n";
	}
	bool isLower(int x, int y)
	{
		cout << "isLower";
		return true;
	}
};
class B : public A {

};

int main()
{
	Math * m = new A;
	bool rez = m->isLower(5, 6);
	cout << sizeof(A);
	cout << sizeof(Math);
	cout << sizeof(B);
	
	return 0;
}