#pragma once

#include "Car.h"
#include "Weather.h"

class Mazda final : public Car {
public:
	Mazda();
	void printName() override;
	const float speedBasedOnWeather(Weather) override;
};