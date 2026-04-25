#include "Ford.h"

Ford::Ford()
{
	fuelCapacity = 55;	// L
	fuelConsumption = 12;	// L / 100 km
	avrSpeed[Rain] = 55;	// km / h
	avrSpeed[Sunny] = 100; // km / h
	avrSpeed[Storm] = 40; // km / h
}
void Ford::printName()
{
	std::cout << "Ford: ";
}
const float Ford::speedBasedOnWeather(Weather w)
{
	return avrSpeed[w];
}