#pragma once
#include <string>
class Animal {
public:
	virtual std::string GetName() = 0;
	virtual bool isAFish() = 0;
	virtual bool isABird() = 0;
	virtual bool isAMammal() = 0;
};