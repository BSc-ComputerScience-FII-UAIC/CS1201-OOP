#include "Toyota.h"

Toyota::Toyota()
{
	fuelCapacity = 60;	// L
	fuelConsumption = 10;	// L / 100 km
	avrSpeed[Rain] = 55;	// km / h
	avrSpeed[Sunny] = 95; // km / h
	avrSpeed[Storm] = 45; // km / h
}
void Toyota::printName()
{
	std::cout << "Toyota: ";
}
const float Toyota::speedBasedOnWeather(Weather w)
{
	return avrSpeed[w];
}