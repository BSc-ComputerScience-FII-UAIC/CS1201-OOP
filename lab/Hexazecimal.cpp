#include "Hexazecimal.h"


int Hexazecimal::GetValue()
{
    return this->value;
}

std::string Hexazecimal::GetFormatName()
{
    return this->format;
}

std::string Hexazecimal::FormatNumber(int nr)
{
    char buff[100];
    itoa(nr, buff, 16);
    return buff;
}
