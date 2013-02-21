#ifndef _APPLICATION_CHARACTER_H_
#define _APPLICATION_CHARACTER_H_

#include "Entity.h"
#include "Room.h"

#include <cmath>

class Character : public Entity
{
public:

	Room* currentRoom;

	Character(const char* imagePath, Room* startRoom);

	bool moveRoom(int direction);

	bool onLoop();
	static float speed;
};

#endif
