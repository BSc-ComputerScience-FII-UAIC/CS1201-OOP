#include "Number.h"

Number::Number(int value)
{
	this->number = value;
	count++;
}

Number::Number(Number* n)
{
	this->number = n->number;
}

Number::Number(Hexazecimal* n)
{
	this->number = n->GetValue();
}

Number::Number(Decimal* n)
{
	this->number = n->GetValue();
}



Number Number::operator+(Number n)
{
	this->number += n.number;
	return this;
}

Number Number::operator*(Number n)
{
	this->number = this->number * n.number;
	return this;
}


Number Number::operator-(Number n)
{
	this->number = this->number - n.number;
	return this;
}

Number Number::operator/(Number n)
{
	this->number = this->number / n.number;
	return this;
}

Number Number::operator+=(Number n)
{
	this->number += n.number;
	return this;
}

void Number::Print()
{

}

