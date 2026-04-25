#pragma once

#include <string.h>

class myClass {
	float value;
	char name[8] = "MyClass";
public:
	int priority;

	friend bool operator < (myClass, myClass);
};