#include "Application.h"

void Application::onCleanup()
{
	SDL_FreeSurface(splash_Image);

	SDL_FreeSurface(menu_Background);
	SDL_FreeSurface(menu_Title);

	SDL_FreeSurface(game_HUD);
	SDL_FreeSurface(game_TileSet);
	
	SDL_FreeSurface(paper);

	delete player;
	delete lincoln;
	
	delete availibleDirections;

	delete lHand;
	delete rHand;

	delete lBar;

	TTF_CloseFont(emulator_font);
	TTF_CloseFont(Words::font);
	TTF_CloseFont(aFont);

	SDL_Quit();
}
