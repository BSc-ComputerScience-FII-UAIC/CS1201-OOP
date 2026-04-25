#include "Multimi.h"

bool existsBefore(int poz, int* a)
{
	for (int j = 0; j < poz; j++)
		if (a[poz] == a[j])
			return true;
	return false;
}

bool exists(int n, int* a, int val)
{
	for (int j = 0; j < n; j++)
		if (a[j] == val)
			return true;
	return false;
}



Multime::Multime()
{
	std::cout << "a";
	size = 0;
	v = nullptr;
}

Multime::Multime(bool initLists) : size(5)
{
	std::cout << "b";
	v = new int[5] {1, 2, 3, 4, 5};
}

Multime::Multime(int min, int max, int count)
{
	std::cout << "c";
	size = count;
	v = new int[size];

	srand(count);

	for (int i = 0; i < size; i++)
	{
		v[i] = rand() % (max - min + 1) + min;
		while (existsBefore(i, v))
			v[i] = rand() % (max - min + 1) + min;
	}
}

Multime::Multime(int count, ...)
{
	size = count;
	va_list list;
	va_start(list, count);
	v = new int[size];

	for (int i = 0; i < size; i++)
		v[i] = va_arg(list, int);

	va_end(list);
}

Multime::Multime(const Multime& other)	// Deep copy
{
	size = other.size;
	v = new int[size];
	memcpy(v, other.v, size * sizeof(int));
}


Multime& operator + (Multime& a, Multime& b)
{
	Multime c;
	int* p = new int[a.size + b.size];
	int k = 0;
	for (int i = 0; i < a.size; i++)
		if (exists(b.size, b.v, a.v[i]) == true)
			p[k++] = a.v[i];
	c.size = k;
	c.v = new int[k];
	for (int i = 0; i < k; i++)
		c.v[i] = p[i];
	return c;
}

Multime& operator * (Multime& a, Multime& b)
{
	Multime c;
	int* p = new int[a.size + b.size];
	int k = 0;
	for (int i = 0; i < a.size; i++)
		p[k++] = a.v[i];
	for (int i = 0; i < b.size; i++)
		if (exists(k, p, b.v[i]) == false)
			p[k++] = b.v[i];

	c.size = k;
	c.v = new int[k];
	for (int i = 0; i < k; i++)
		c.v[i] = p[i];
	return c;
}

Multime& operator - (Multime& a, Multime& b)
{
	Multime c;

	int* p = new int[a.size + b.size];
	int k = 0;
	for (int i = 0; i < a.size; i++)
		if (exists(b.size, b.v, a.v[i]) == false)
			p[k++] = a.v[i];
	c.size = k;
	c.v = new int[k];
	for (int i = 0; i < k; i++)
		c.v[i] = p[i];
	return c;
}

int Multime::operator[](int poz)
{
	if (size > 0 && poz >= 0 && poz < size)
		return v[poz];
}

Multime& Multime::operator()(int start, int end)
{
	Multime c;
	if (start > end || start < 0 || end >= size || size <=0)
		return c;
	c.size = end - start + 1;
	c.v = new int[c.size];

	for (int i = start; i < c.size; i++)
		c.v[i - start] = v[i];
	
	return c;
}



void Multime::Print()
{
	for (int i = 0; i < size; i++)
		std::cout << v[i] << ' ';
	std::cout << std::endl;
}

void Multime::SetElement(int poz, int val)
{
	if (v != nullptr && poz < size && exists(size, v, val) == false)
		v[poz] = val;
	else
		std::cout << "Error for setting element!" << std::endl;
}

const int Multime::GetElement(int poz)
{
	if (poz >= 0 && poz < size && v != nullptr)
		return v[poz];
	else
	{
		std::cout << "Error returning element from position " << poz << std::endl;
		return 0;
	}
}

void Multime::Sort()
{
	if (size == 0)
		return;
	int aux;
	bool ok;
	do
	{
		ok = true;
		for (int i = 0; i < size - 1; i++)
			if (v[i] > v[i + 1])
			{
				aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				ok = false;
			}
	} while (!ok);
}