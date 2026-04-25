#pragma once
class Eagle : public Animal {
public:
	std::string GetName() {
		std::string toReturn = "Eagle";
		return toReturn;
	}
	bool isAFish() {
		return false;
	}
	bool isABird() {
		return true;
	}
	bool isAMammal() {
		return false;
	}
};