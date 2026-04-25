#pragma once
#include "Feline.h"
class Lion : public Feline {
public:
	std::string GetName() {
		std::string toReturn = "Lion";
		return toReturn;
	}
	bool isAFish() {
		return false;
	}
	bool isABird() {
		return false;
	}
	bool isAMammal() {
		return true;
	}
	int GetSpeed() {
		return 80;
	}
};