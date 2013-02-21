#ifndef _APPLICATION_ENTITY_H_
#define _APPLICATION_ENTITY_H_

#include <stdlib.h>
#include <vector>
#include "Animation.h"

class Entity
{
public:
	float x;
	float y;	

	virtual void onRender(SDL_Surface* dest);
	void onCleanup();

	Entity(const char* file, int frameW, int frameH);

	Animation image;
	
protected:

	static std::vector<Entity*> entityList;	
};

#endif
