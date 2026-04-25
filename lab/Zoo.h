#pragma once
#include "Animal.h"
class Shark : public Animal {
public:
	std::string GetName() {
		std::string toReturn = "Shark";
		return toReturn;
	}
	bool isAFish() {
		return true;
	}
	bool isABird() {
		return false;
	}
	bool isAMammal() {
		return false;	//rechinii sunt si mamifere aparent
	}
};