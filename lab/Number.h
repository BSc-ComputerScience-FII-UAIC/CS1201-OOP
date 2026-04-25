#pragma once
#include "Hexazecimal.h"
#include "Decimal.h"
class Number {
	int number;
	int count = 0;
public:
	Number(int value);
	Number(Number* n);
	Number(Hexazecimal* n);
	Number(Decimal* n);
	int operator(int) (Number n);
	Number operator+(Number n);
	Number operator*(Number n);
	Number operator-(Number n);
	Number operator/(Number n);
	Number operator+=(Number n);
	void Print();
};