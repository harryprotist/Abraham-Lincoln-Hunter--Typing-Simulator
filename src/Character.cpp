#include "Character.h"

const int res = 20;

Character::Character(const char* imagePath, Room* startRoom) :
	currentRoom(startRoom),
	Entity(imagePath, res, res * 2)
{
	x = startRoom->x;
	y = startRoom->y;
}
	

bool Character::moveRoom(int direction)
{
	Room* tmpRoom = currentRoom;

	switch(direction)
	{
	case 0:
		currentRoom = currentRoom->up;
	break;
	case 1:
		currentRoom = currentRoom->right;
	break;
	case 2:
		currentRoom = currentRoom->down;
	break;
	case 3:
		currentRoom = currentRoom->left;
	break;
	default:
		return false;
	break;
	}

	if(currentRoom == tmpRoom)
		return false;
	return true;
}

float Character::speed = 0.05f;

bool Character::onLoop()
{
	if(x < (currentRoom->x))
		x += speed;
	if(y < (currentRoom->y))
		y += speed;
	if(y > (currentRoom->y))
		y -= speed;
	if(x > (currentRoom->x))
		x -= speed;

	if(fabs((float)currentRoom->x - x) < 0.05f)
		x = (float)currentRoom->x;
	if(fabs((float)currentRoom->y - y) < 0.05f)
		y = (float)currentRoom->y;

	if(x == (currentRoom->x) && y == (currentRoom->y))
		return false;
	return true;
}














