#pragma once

#include "Car.h"

class Dacia final : public Car {
public:
	Dacia();
	void printName() override;
	const float speedBasedOnWeather(Weather) override;
};