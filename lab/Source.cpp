#include "MyVector.h"

void MyVector::Resize()
{
	int* _newVector = new int[size * 2];
	memcpy(_newVector, data, size * sizeof(int));
	size = 2 * size;
	delete[] data;
	data = _newVector;
}

MyVector::MyVector(int _size)
{
	data = new int[_size];
	size = _size;
	pos = 0;
}

bool MyVector::Add(int value)
{
	if (pos == size)	// the vector is full
		Resize();
	data[pos++] = value;
	return true;
}
bool MyVector::Delete(int index)
{
	if (index < 0 || index > pos)
		return false;
	for (int i = index; i < pos - 1; i++)
		data[i] = data[i + 1];
	pos--;
	return true;
}

void MyVector::Iterate(void(*funct)(int &))
{
	for (int i = 0; i < pos; i++)
		funct(data[i]);
}

void MyVector::Filter(bool(*funct)(int &))
{
	for (int i = 0; i < pos; i++)
	{
		if (funct(data[i]) == true)
		{
			Delete(i);
			i--;
		}
	}
}

void MyVector::Print()
{
	for (int i = 0; i < pos; i++)
		printf("%d ", data[i]);
}