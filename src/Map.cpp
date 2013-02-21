#include "Map.h"

Map::Map()
{
}

Map::Map(const char* file)
{
	openMap(file);
}

int Map::getW()
{
	return w;
}
int Map::getH()
{
	return h;
}

int Map::getSpace(int x, int y)
{
	return map.at(y).at(x);
}
