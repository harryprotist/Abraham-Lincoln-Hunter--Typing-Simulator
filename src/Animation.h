#ifndef _APPLICATION_ANIMATION_H_
#define _APPLICATION_ANIMATION_H_

#include "Render.h"
#include <stdlib.h>

class Animation
{
public:

	bool nullImage;

	Animation(const char* file, int frameW, int frameH);
	~Animation();	

	int state;

	void getFrame(SDL_Surface* dest, int x, int y, int useFrame);

	int getFrameInt();

private:
	
	int frame;

	int frameW;
	int frameH;

	SDL_Surface* image;
};

#endif
