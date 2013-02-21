#include "Entity.h"

std::vector<Entity*> Entity::entityList;

Entity::Entity(const char* file, int frameW, int frameH) : 
	x(0.0f),
	y(0.0f),
	image(file, frameW, frameH)
{
	entityList.push_back(this);
}

void Entity::onRender(SDL_Surface* dest)
{
}

void Entity::onCleanup()
{
}
