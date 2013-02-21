#ifndef _LINCOLN_H_
#define _LINCOLN_H_

#include "Character.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

class Lincoln : public Character
{
private:
	
	std::vector<Room> map;
	Character* ch;
	
public:
	
	Lincoln(std::vector<Room> map, Character* player, Room* room);
	int onCalc();

};

#endif
