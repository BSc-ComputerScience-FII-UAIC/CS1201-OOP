#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>

bool isSeparator(char sep)
{
	return sep == ' ' || sep == ',' || sep == '.' || sep == '?' || sep == '!';
}

void toUpperCase(std::string& aux)
{
	for (unsigned int i = 0; i < aux.length(); i++)
		if (aux[i] >= 'A' && aux[i] <= 'Z')
			aux[i] = aux[i] - 'A' + 'a';
}

class Compare {
public:
	bool operator() (std::map<std::string, int>::iterator s1, std::map<std::string, int>::iterator s2)
	{
		if (s1->second < s2->second) return true;
		if (s1->second > s2->second) return false;
		if (s1->first < s2->first) return false;
		return true;
	}
};

int main()
{
	std::ifstream fin("input.txt");
	std::string s;
	std::map<std::string, int> m;

	std::getline(fin, s);

	int i = 0;
	int j = 0;
	std::string aux;
	while (s[i + j] != 0)
	{
		if (isSeparator(s[j + i]))
		{
			aux = s.substr(i, j);
			while (isSeparator(s[j + i]))
				j++;
			i += j;
			j = 0;
			toUpperCase(aux);
			if (m.find(aux) == m.end())	// it does not exist
				m[aux] = 1;
			else
				m[aux]++;
		}
		else
			j++;
	}
	std::priority_queue<std::map<std::string, int>::iterator, std::vector<std::map<std::string, int>::iterator>, Compare> p;
	std::map<std::string, int>::iterator it = m.begin();
	while (it != m.end())
	{
		p.push(it);
		it++;
	}
	while (!p.empty())
	{
		std::cout << "The word " << p.top()->first << " appears " << p.top()->second << " times" << std::endl;
		p.pop();
	}

	fin.close();
	return 0;
}