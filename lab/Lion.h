#pragma once
#include "Animal.h"
class Cow : public Animal {
public:
	std::string GetName() {
		std::string toReturn = "Cow";
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
};