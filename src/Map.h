#ifndef _APPLICATION_MAP_H_
#define _APPLICATION_MAP_H_

#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Map
{
public:
	
	Map(const char* file);
	Map();

	bool openMap(const char* file);
	int getSpace(int x, int y);
	
	int getW();
	int getH();
	
private:

	int w;
	int h;
	
	std::vector<std::vector<int> > map;
};

#endif
