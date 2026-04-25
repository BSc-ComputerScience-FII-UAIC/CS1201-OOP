#pragma once
#include <string>
using namespace std;
class Car {
public:
	int year, cost;
	string color;
	Car(int y, int c, string col) : year(y), cost(c), color(col) {};

};