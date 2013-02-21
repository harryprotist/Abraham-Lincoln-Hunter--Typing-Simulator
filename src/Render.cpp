#include "Render.h"

bool Render::Blit(SDL_Surface* src, SDL_Surface* dest, int x, int y)
{
	Render::Blit(src, dest, x, y, 0, 0, src->w, src->h);
}

bool Render::Blit(SDL_Surface* src, SDL_Surface* dest, int x1, int y1, int x2, int y2, int w, int h)
{
	SDL_Rect dest_rect;
	dest_rect.x = x1;
	dest_rect.y = y1;

	SDL_Rect src_rect;
	src_rect.x = x2;
	src_rect.y = y2;
	src_rect.w = w;
	src_rect.h = h;	

	if(SDL_BlitSurface(src, &src_rect, dest, &dest_rect) < 0)
	{
		return false;
	}
	return true;	
}

bool Render::DrawText(TTF_Font* src, SDL_Surface* dest, const char* txt, int x, int y)
{
	SDL_Color black = {0, 0, 0};
	
	SDL_Surface* tmp = TTF_RenderText_Solid(src, txt, black);
	if(tmp != NULL)
	{
		Blit(tmp, dest, x, y);
		SDL_FreeSurface(tmp);
		return true;
	}

	return false;
}

SDL_Surface* Render::Load(const char* file)
{
	SDL_Surface* load = NULL;
	SDL_Surface* ret = NULL;

	load = IMG_Load(file);

	if(load != NULL)
	{
		ret = SDL_DisplayFormatAlpha(load);
	
		return ret;
	}

	return NULL;
}
