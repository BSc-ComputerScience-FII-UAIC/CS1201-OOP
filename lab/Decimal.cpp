#include "Decimal.h"

int Decimal::GetValue()
{
    return this->value;
}

std::string Decimal::GetFormatName()
{
    return this->format;
}

std::string Decimal::FormatNumber(int nr)
{
    char buff[100];
    itoa(nr, buff, 10);
    return buff;
}

