#include "Map.h"

bool Map::openMap(const char* file)
{
	std::ifstream fin;
	fin.open(file);

	if(!fin.is_open())
		return false;

	std::vector<int> blank;

	std::string line;
	int iLine;
	
	for(int l = 0;; l++)
	{
		fin >> line;
		if(!fin.good()) break;
	
		map.push_back(blank);	

		for(int i = 0; i < line.size(); i++)
		{
			switch(line[i])
			{
			case 'g':
				iLine = 17;
			break;
			case 'F':
				iLine = 22;
			break;
			case 'U':
				iLine = 18;
			break;
			case 'V':
				iLine = 26;
			break;
			case 'T':
				iLine = 23;
			break;
			case 'L':
				iLine = 16;
			break;
			case '.':
				iLine = 1;
			break;
			case '|':
				iLine = 2;
			break;
			case 'I':
				iLine = 15;
			break;
			case 'u':
				iLine = 28;
			break;
			case 'R':
				iLine = 0;
			break;
			case 'n':
				iLine = 29;
			break;
			case '[':
				iLine = 7;
			break;
			case 'D':
				iLine = 13;
			break;
			case 'C':
				iLine = 14;
			break;
			case 'E':
				iLine = 25;
			break;
			case 'v':
				iLine = 11;
			break;
			case '+':
				iLine = 4;
			break;
			case '<':
				iLine = 12;
			break;
			case '^':
				iLine = 9;
			break;
			case '}':
				iLine = 5;
			break;
			case 'K':
				iLine = 21;
			break;
			case 'N':
				iLine = 19;
			break;
			case 'J':
				iLine = 20;
			break;
			case '-':
				iLine = 3;
			break;
			case ']':
				iLine = 8;
			break;
			case '{':
				iLine = 6;
			break;
			case '3':
				iLine = 27;
			break;
			case '>':
				iLine = 10;
			break;
			case 'X':
				iLine = 24;
			break;
			}

			map.at(l).push_back(iLine);
		}

		// Quick patch to stop segfaults from map errors
		if(map.at(l).size() != map.at(0).size())
			map.at(l) = map.at(0);
	}
	fin.close();

	h = map.size();
	w = map.at(0).size();

	return true;
}			
