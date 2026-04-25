#include "myClass.h"

bool operator < (myClass a, myClass b)
{
	return a.priority < b.priority;
}