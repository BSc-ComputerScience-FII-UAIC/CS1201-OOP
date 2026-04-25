#pragma once

#include <vector>


class Propozitie
{
	char* original_txt;
	std::vector<char*> v;
	int no_words;
public:
	Propozitie();
	Propozitie(const char *txt);
	~Propozitie();
	void Create(const char * txt);

	char * operator[](int index);
	operator char*();

	std::vector<char*>::iterator begin();
	std::vector<char*>::iterator end();

	int GetNumberOfWords();
	bool Contains(const char *word, bool ignoreCase);
};
