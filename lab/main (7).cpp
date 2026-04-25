#include "Map.h"
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <iostream>
int main()
{
	Map<int, const char*> m, n;
	n[15] = "";
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";

	std::cout << m.Includes(n);

	for (auto[key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	for (auto[key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	return 0;
}