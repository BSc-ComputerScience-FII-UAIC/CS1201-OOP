#include "Circuit.h"

Circuit::Circuit()
{
	numberOfCars = 0;
	length = 0;
}

Circuit::~Circuit()
{
	for (int i = 0; i < numberOfCars; i++)
		delete cars[i];
}

void Circuit::SetLength(const int amount)
{
	length = amount;
}

void Circuit::SetWeather(const Weather w)
{
	weather = w;
}

void Circuit::AddCar(Car* car)
{
	cars[numberOfCars++] = car;
}

void Circuit::Race()
{
	for (int i = 0; i < numberOfCars; i++)
		if (cars[i]->speedBasedOnWeather(weather) * (cars[i]->fuelCapacity / cars[i]->fuelConsumption) >= length)	// the maximum distance is greater than the length of the circuit
			cars[i]->time = length / cars[i]->speedBasedOnWeather(weather);	// store time
		else
			cars[i]->time = -1.0f;	// mark as unfinished
}

void Circuit::ShowFinalRanks()
{
	Car* aux;
	bool ok;

	do
	{
		ok = true;
		for (int i = 0; i < numberOfCars - 1; i++)
			if (cars[i]->time > cars[i + 1]->time)
			{
				aux = cars[i];
				cars[i] = cars[i + 1];
				cars[i + 1] = aux;
				ok = false;
			}
	} while (!ok);

	std::cout << "FINAL RANKS: " << std::endl;
	for (int i = 0; i < numberOfCars; i++)
		if (cars[i]->time != -1.0f)
		{
			cars[i]->printName();
			std::cout << std::setprecision(3) << cars[i]->time << " hours" << std::endl;
		}
	std::cout << std::endl;
}

void Circuit::ShowWhoDidNotFinish()
{
	bool everybody = true;
	for (int i = 0; i < numberOfCars; i++)
		if (cars[i]->time == -1.0f)
		{
			everybody = false;
			break;
		}
	if (everybody)
		std::cout << "Surprise! Everyone finished!" << std::endl;
	else
	{
		std::cout << "DID NOT FINISH: " << std::endl;
		for (int i = 0; i < numberOfCars; i++)
			if (cars[i]->time == -1.0f)
			{
				cars[i]->printName();
				std::cout << '\n' << std::endl;
			}
	}
	std::cout << std::endl;
}