#pragma once

#include <iostream>
#include <random>
#include <stdarg.h>

class Multime {
public:
	unsigned int size;
	int* v;

	Multime();
	Multime(bool);
	Multime(int, int, int);
	Multime(int, ...);
	Multime(const Multime&);

	friend Multime& operator + (Multime&, Multime&);
	friend Multime& operator - (Multime&, Multime&);
	friend Multime& operator * (Multime&, Multime&);
	
	int operator[](int);
	Multime& operator()(int, int);

	void Print();
	void SetElement(int, int);
	const int GetElement(int);
	void Sort();
};