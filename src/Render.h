#ifndef APPLICATION_RENDER_H_
#define APPLICATION_RENDER_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

class Render
{
public:
	static bool Blit(SDL_Surface* src, SDL_Surface* dest, int x, int y);
	static bool Blit(SDL_Surface* src, SDL_Surface* dest, int x1, int y1, int x2, int y2, int w, int h);
	
	static bool DrawText(TTF_Font* src, SDL_Surface* dest, const char* txt, int x, int y);

	static SDL_Surface* Load(const char* file);

private:
	Render();
};

#endif
