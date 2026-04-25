#pragma once

#include "Car.h"
#include "Weather.h"

class  Toyota final : public Car {
public:
	Toyota();
	void printName() override;
	const float speedBasedOnWeather(Weather) override;
};
