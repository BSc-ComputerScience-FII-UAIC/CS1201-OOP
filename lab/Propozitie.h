#include "Propozitie.h"

Propozitie::Propozitie()
{
	original_txt = nullptr;
	no_words = 0;
}

Propozitie::Propozitie(const char * txt)
{
	original_txt = new char[strlen(txt)];
	strcpy(original_txt, txt);
	Create(txt);
}

Propozitie::~Propozitie()
{
	
}

void Propozitie::Create(const char * txt)
{
	char * _txt = new char[strlen(txt)];
	strcpy(_txt, txt);
	char * p = strtok(_txt, " ");
	while (p)
	{
		v.push_back(p);
		no_words++;
		p = strtok(NULL, " ");
	}
}

char * Propozitie::operator[](int index)
{
	return v.at(index);
}

Propozitie::operator char *()
{
	return original_txt;
}

std::vector<char*>::iterator Propozitie::begin()
{
	return v.begin();
}

std::vector<char*>::iterator Propozitie::end()
{
	return v.end();
}

int Propozitie::GetNumberOfWords()
{
	return no_words;
}

bool Propozitie::Contains(const char * txt, bool ignoreCase)
{
	for (int i = 0; i < no_words; i++)
	{
		if (ignoreCase == true)
		{
			bool ok = true;
			for (int j = 0; j < strlen(txt); j++)
			{
				if (txt[j] <= 'z' && txt[j] >= 'a')
				{
					if (v[i][j] <= 'z' && v[i][j] >= 'a')
						if (v[i][j] != txt[j])
						{
							ok = false;
							break;
						}
					if (v[i][j] <= 'Z' && v[i][j] >= 'A')
						if (v[i][j] - 'A' + 'a' != txt[j])
						{
							ok = false;
							break;
						}
				}
				else
				{
					if (v[i][j] <= 'z' && v[i][j] >= 'a')
						if (v[i][j] + 'A' - 'a' != txt[j])
						{
							ok = false;
							break;
						}
					if (v[i][j] <= 'Z' && v[i][j] >= 'A')
						if (v[i][j] != txt[j])
						{
							ok = false;
							break;
						}
				}
			}
			if (strlen(txt) != strlen(v[i]))
				ok = false;
			if (ok)
				return true;
		}
		else
			if (strcmp(txt, v[i]) == 0)
				return true;
	}
	return false;
}