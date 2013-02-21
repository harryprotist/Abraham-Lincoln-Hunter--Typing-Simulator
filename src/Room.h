#ifndef _APPLICATION_ROOM_H_
#define _APPLICATION_ROOM_H_

#include "Map.h"
#include <stdlib.h>

class Room
{
public:

	int x;
	int y;

	Room* up;
	Room* down;
	Room* left;
	Room* right;

	static void mapToRoom(Map map, std::vector<Room>& rooms);
	static void createRooms(Map map, std::vector<Room>& rooms);
};

#endif
