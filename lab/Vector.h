#include "Vector.h"
#include "myClass.h"

bool esteMaiMare(char x, char y)
{
	return x > y;
}

bool esteEgal(char x, char y)
{
	return x == y;
}

bool myStrcmp(const char* a, const char* b)
{
	if (strcmp(a, b) == 1) return true;
	return false;
}

int main()
{
	Vector<char> p(10);
	p.Push('A');
	p.Push('C');
	p.Push('B');
	p.Push('D');
	p.Push('E');
	p.Push('J');
	p.Push('X');
	p.Remove(3);
	p.Insert('o', 2);
	for (int i = 0; i < p.Count(); i++)
		std::cout << p.Get(i) << " ";
	std::cout << std::endl;
	p.Sort(nullptr);
	for (int i = 0; i < p.Count(); i++)
		std::cout << p.Get(i) << " ";
	std::cout << std::endl;
	std::cout << "'A' se afla pe pozitia: " << p.firstIndexOf('A', esteEgal) << std::endl;



	Vector<const char*> myChar(10);
	myChar.Push("abc");
	myChar.Push("cde");
	myChar.Push("efg");
	myChar.Push("ghi");
	myChar.Push("jkl");
	myChar.Push("o");
	myChar.Insert("a", 0);
	myChar.Insert("b", 0);
	myChar.Insert("c", 0);
	myChar.Insert("d", 0);
	myChar.Insert("e", 0);
	myChar.Insert("f", 0);
	myChar.Insert("g", 0);
	myChar.Insert("h", 0);
	myChar.Insert("i", 0);
	myChar.Insert("O", 0);

	for (int i = 0; i < myChar.Count(); i++)
		std::cout << myChar.Get(i) << " ";
	std::cout << std::endl;

	myChar.Sort(myStrcmp);

	for (int i = 0; i < myChar.Count(); i++)
		std::cout << myChar.Get(i) << " ";

	Vector<myClass> b(2);
	myClass obj1, obj2, obj3, obj4, obj5;
	obj1.priority = 1;
	obj2.priority = 2;
	obj3.priority = 3;
	obj4.priority = 4;
	obj5.priority = 5;


	b.Push(obj1);
	b.Push(obj1);
	b.Push(obj2);
	b.Push(obj5);
	b.Push(obj5);
	b.Push(obj4);
	b.Push(obj3);
	b.Push(obj4);
	b.Push(obj1);
	b.Push(obj2);
	b.Push(obj3);
	b.Sort(nullptr);

	return 0;
}