#pragma once

#include "Dacia.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"
#include "Ford.h"

class Circuit {
	int length;
	Car* cars[100];
	int numberOfCars;
	Weather weather;
public:
	Circuit();
	~Circuit();
	void SetLength(const int);
	void SetWeather(const Weather);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};
