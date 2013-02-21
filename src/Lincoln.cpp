#include "Lincoln.h"

Lincoln::Lincoln(std::vector<Room> Map, Character* player, Room* room) : 
	map(Map), ch(player), Character("Image/lincoln.png", room)
{}

int Lincoln::onCalc()
{
	int dir;
	int risk[] = { -1, -1, -1, -1 };
	Room* cSp = NULL;

	int crx = ch->currentRoom->x, cry = ch->currentRoom->y;

	// get Availible directions
	
	// 	find the current space
	for(int i = 0; i < map.size(); i++)
	{
		if(map.at(i).x == (int)x && map.at(i).y == (int)y)
		{
			cSp = &(map.at(i));	 
			break;
		}
	}
	if(cSp == NULL)
		return -1;

	//	 find which directions are availible
	if(cSp->up->y != cSp->y)
		risk[0] = 0;
	if(cSp->right->x != cSp->x)
		risk[1] = 0;
	if(cSp->down->y != cSp->y)
		risk[2] = 0;
	if(cSp->left->x != cSp->x)
		risk[3] = 0;

	// Check directions, and whether or not the player is in them
	if(crx == cSp->up->x && cry == cSp->up->y)
		risk[0] += (risk[0] < 0) ? 0:100;
	if(crx == cSp->right->x && cry == cSp->right->y)
		risk[1] += (risk[1] < 0) ? 0:100;
	if(crx == cSp->down->x && cry == cSp->down->y)
		risk[2] += (risk[2] < 0) ? 0:100;
	if(crx == cSp->left->x && cry == cSp->left->y)
		risk[3] += (risk[3] < 0) ? 0:100;			

	// Check directions for each direction, to see if the player can reach those spaces
	Room* r = NULL;
	for(int i = 0; i < 4; i++)
	{
		switch(i)
		{
			case 0: r = cSp->up; break;
			case 1: r = cSp->right; break;
			case 2: r = cSp->down; break;
			case 3: r = cSp->left; break; 
		}

		if(risk[i] >= 0)
		{
			if(crx == r->up->x && cry == r->up->y)
				risk[i] += 24;
			if(crx == r->right->x && cry == r->right->y)
				risk[i] += 24;
			if(crx == r->down->x && cry == r->down->y)
				risk[i] += 24;
			if(crx == r->left->x && cry == r->left->y)
				risk[i] += 24;	
		}

	}

	// Move to the safest direction ( the one with the lowest risk )
	srand(time(NULL));
	do
	{
		dir = rand() % 4;
	}	
	while(risk[dir] == -1);

	for(int i = 0; i < 4; i++)
	{
		if(risk[dir] /*<*/> risk[i] && risk[i] >= 0) 
			dir = i;
	}

	return dir;	
}
