#include <vector>
#include <string>
#include <algorithm>
#include "MyVector.h"

void ex1()
{
	int size;
	printf("Size of vector = ");
	std::cin >> size;

	std::vector<std::string> v;
	std::string x;
	for (int i = 0; i < size; i++)
	{
		std::cin >> x;
		v.push_back(x);
	}

	auto f = [](std::string s1, std::string s2)->bool{ 
														if (int(s1.size()) < int(s2.size())) return false;
														else 
														{	
															if (int(s1.size()) > int(s2.size())) return true; 
															else 
															{
																if (s1 < s2) return false;
																else
																	return true;
															}
														}
	};
	
	std::sort(v.begin(), v.end(), f);

	for (int i = 0; i < size; i++)
	{
		std::cout << v.at(i) << " ";
	}
}

int main()
{
	
	/*int list[] = {1,2,3,4,5,6,7,8};
	int size = sizeof(list) / sizeof(int);
	int max_outside;
	auto ex2 = [list, &max_outside](int size)->int  {int max = list[0]; 
															for (int i = 0; i < size; i++) 
																if (max < list[i]) max = list[i]; 
															max_outside = max;
															return max; 
															};
	std::cout << ex2(size);*/

	MyVector v(5);
	v.Add(12);
	v.Add(3);
	v.Add(-78);
	v.Add(432);
	v.Add(123);
	v.Add(1000);
	v.Add(1000);
	v.Add(1000);
	v.Add(1000);
	v.Add(1000);
	v.Add(1000);

	 //auto _funct = [](int &a)->void { if (a % 2 == 0) a = 1; else a = 0; };
	 //v.Iterate(_funct);

	 auto _funct2 = [](int &a)->bool {if (a >= -100 && a <= 100) return false; return true; };
	 v.Filter(_funct2);
	 v.Print();
	return 0;
}