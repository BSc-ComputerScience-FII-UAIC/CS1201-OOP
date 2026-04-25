#pragma once
#include "Printer.h"
class Hexazecimal : public Printer {
	std::string format = "Hexazecimal";
	int value = 0x0000000E;
public:
	int GetValue();
	Hexazecimal() = default;
	std::string GetFormatName();
	std::string FormatNumber(int);
};