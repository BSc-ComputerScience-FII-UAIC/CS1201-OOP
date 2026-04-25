#include "Mercedes.h"

Mercedes::Mercedes()
{
	fuelCapacity = 100;	// L
	fuelConsumption = 15;	// L / 100 km
	avrSpeed[Rain] = 50;	// km / h
	avrSpeed[Sunny] = 115; // km / h
	avrSpeed[Storm] = 40; // km / h
}
void Mercedes::printName()
{
	std::cout << "Mercedes: ";
}
const float Mercedes::speedBasedOnWeather(Weather w)
{
	return avrSpeed[w];
}