#pragma once
#include <string>
#include "car.h"
#include <vector>
#include <iostream>
using namespace std;

class Dealer {
public:
	vector<Car> listOfCars;
	int maxCapacity;
	Dealer() : maxCapacity(10) {};
	void operator+=(Car); 

	void PrintOffers(bool(*filter)(Car c));

};