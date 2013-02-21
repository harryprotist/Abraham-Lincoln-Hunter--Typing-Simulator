#include "Animation.h"

Animation::Animation(const char* file, int frameW, int frameH) : 
	state(0),
	frame(0),
	image(NULL)
{	
	if((image = Render::Load(file)) == NULL)
	{
		nullImage = true;			
	}
	else nullImage = false;

	this->frameW = frameW;
	this->frameH = frameH;
}

void Animation::getFrame(SDL_Surface* dest, int x, int y, int useFrame)
{
	bool i = false;
	if(useFrame == -1)
	{
		useFrame = frame;
		i = true;
	}

	Render::Blit(image, dest, x, y, state * frameW, useFrame * frameH, frameW, frameH);
	
	if(((frame + 1) * frameH) >= image->h && i)
		frame = 0;
	else if(i)
		frame++;
}

int Animation::getFrameInt()
{
	return frame;
}

Animation::~Animation()
{
	SDL_Surface* null = NULL;
	if (image != null)
	{
		SDL_FreeSurface(image);
	}
}
	
