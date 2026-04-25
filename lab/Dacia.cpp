#pragma once

#include <iostream>
#include <iomanip>	// for setprecision()
#include "Weather.h"

class Car {
public:
	virtual void printName() = 0;
	virtual const float speedBasedOnWeather(Weather) = 0;

	float fuelConsumption;
	float fuelCapacity;
	float time;
protected:
	float avrSpeed[3];
};