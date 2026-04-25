#include "Dacia.h"

Dacia::Dacia()
{
	fuelCapacity = 50;	// L
	fuelConsumption = 5;	// L / 100 km 
	avrSpeed[Rain] = 50;	// km / h
	avrSpeed[Sunny] = 80; // km / h
	avrSpeed[Storm] = 30; // km / h
}
void Dacia::printName()
{
	std::cout << "Dacia: ";
}
const float Dacia::speedBasedOnWeather(Weather w)
{
	return avrSpeed[w];
}