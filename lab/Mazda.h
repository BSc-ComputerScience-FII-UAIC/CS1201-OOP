#pragma once

#include "Car.h"
#include "Weather.h"

class Ford final : public Car {
public:
	Ford();
	void printName() override;
	const float speedBasedOnWeather(Weather) override;
};