#pragma once
#include "Printer.h"
class Decimal : public Printer {
	std::string format = "Decimal";
	int value = 0;
public:
	int GetValue();
	Decimal() = default;
	std::string GetFormatName();
	std::string FormatNumber(int);
};