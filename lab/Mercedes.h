#include "Mazda.h"

Mazda::Mazda()
{
	fuelCapacity = 40;	// L
	fuelConsumption = 7;	// L / 100 km
	avrSpeed[Rain] = 60;	// km / h
	avrSpeed[Sunny] = 75; // km / h
	avrSpeed[Storm] = 40; // km / h
}
void Mazda::printName()
{
	std::cout << "Mazda: ";
}
const float Mazda::speedBasedOnWeather(Weather w)
{
	return avrSpeed[w];
}