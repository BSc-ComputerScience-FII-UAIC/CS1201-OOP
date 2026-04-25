#pragma once

#include "Car.h"
#include "Weather.h"

class Mercedes final : public Car {
public:
	Mercedes();
	void printName() override;
	const float speedBasedOnWeather(Weather) override;
};