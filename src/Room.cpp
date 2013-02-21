#include "Room.h"

void Room::mapToRoom(Map map, std::vector<Room>& rooms)
{
	int currentNode[2];

	int upMostNode[2];
	int downMostNode[2];
	int leftMostNode[2];
	int rightMostNode[2];
	
	int tmpNode[2];
	int lastSpace;

	for(int i = 0; i < rooms.size(); i++)
	{
		currentNode[0] = rooms.at(i).x;
		currentNode[1] = rooms.at(i).y;		

		// find node vertically
		upMostNode[0] = -1;
		downMostNode[0] = -1;
		for(int y = currentNode[1], x = currentNode[0]; y < map.getH(); y++)
		{
			lastSpace = map.getSpace(x, y);

			if(lastSpace == 0 && y > currentNode[1])
			{
				downMostNode[0] = x;
				downMostNode[1] = y;
				
				break;
			}
		}
		for(int y = currentNode[1], x = currentNode[0]; y > 0; y--)
		{		
			lastSpace = map.getSpace(x, y);

			if(lastSpace == 0 && y < currentNode[1])
			{
				upMostNode[0] = x;
				upMostNode[1] = y;
		
				break;
			}
		}

		if(upMostNode[0] == -1)
		{		
			upMostNode[0] = currentNode[0];
			upMostNode[1] = currentNode[1];
		}
		if(downMostNode[0] == -1)
		{
			downMostNode[0] = currentNode[0];
			downMostNode[1] = currentNode[1];
		}

		// find nodes horizontally
		rightMostNode[0] = -1;
		leftMostNode[0] = -1;
		for(int y = currentNode[1], x = currentNode[0]; x < map.getW(); x++) 
		{
			lastSpace = map.getSpace(x, y);

			if(lastSpace == 0 && x > currentNode[0])
			{
				rightMostNode[0] = x;
				rightMostNode[1] = y;
		
				break;
			}
		}
		for(int y = currentNode[1], x = currentNode[0]; x > 0; x--)
		{
			lastSpace = map.getSpace(x, y);

			if(lastSpace == 0 && x < currentNode[0])
			{
				leftMostNode[0] = x;
				leftMostNode[1] = y;

				break;
			}
		}

		if(rightMostNode[0] == -1)
		{
			rightMostNode[0] = currentNode[0];
			rightMostNode[1] = currentNode[1];
		}
		if(leftMostNode[0] == -1) 
		{
			leftMostNode[0] = currentNode[0];
			leftMostNode[1] = currentNode[1];
		}
		
		// create nodes for the current nodes
		for(int n = 0; n < rooms.size(); n++)
		{
			tmpNode[0] = rooms.at(n).x;
			tmpNode[1] = rooms.at(n).y;

			if(tmpNode[0] == upMostNode[0] && tmpNode[1] == upMostNode[1])
				rooms.at(i).up = &rooms.at(n);
			if(tmpNode[0] == downMostNode[0] && tmpNode[1] == downMostNode[1])
				rooms.at(i).down = &rooms.at(n);
			if(tmpNode[0] == rightMostNode[0] && tmpNode[1] == rightMostNode[1])
				rooms.at(i).right = &rooms.at(n);
			if(tmpNode[0] == leftMostNode[0] && tmpNode[1] == leftMostNode[1])
				rooms.at(i).left = &rooms.at(n);
		}	
	}
}

void Room::createRooms(Map map, std::vector<Room>& rooms)
{
	Room tmp;	

	for(int y = 0; y < map.getH(); y++){for(int x = 0; x < map.getW(); x++)
	{
		if(map.getSpace(x, y) == 0)
		{
			tmp.x = x;
			tmp.y = y;
			
			rooms.push_back(tmp);
		}
	}}
}




















