#include "Application.h"

void Application::onEvent()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
			running = false;

		switch(gameState)
		{
			case 0:
				switch(event.type)
				{
					case SDL_MOUSEBUTTONUP:
						onClickUp_menu(event);
					break;
					case SDL_MOUSEBUTTONDOWN:
						onClickDown_menu(event);
					break;
					default:break;
				}
			break;
			case 1:
				switch(event.type)
				{
					case SDL_KEYDOWN:
						keys[(int)event.key.keysym.sym] = true;
					break;
					case SDL_KEYUP:
						keys[(int)event.key.keysym.sym] = false;
					break;
					default:break;
				}
			break;
			case 2:
				switch(event.type)
				{
					case SDL_KEYDOWN:
						keys[(int)event.key.keysym.sym] = true;
					break;
					case SDL_KEYUP:
						keys[(int)event.key.keysym.sym] = false;
					break;
					default:break;
				}
			break;
			default:break;
		}
	}
}

void Application::onClickUp_menu(SDL_Event event)
{
	if(event.button.button == SDL_BUTTON_LEFT && 
		(event.button.x > 30 && event.button.x < 230 &&
		event.button.y > 360 && event.button.y < 423))
	{	
		prevTicks = SDL_GetTicks();
		lastNumTicks = SDL_GetTicks();
		gameState = 1;
	}
	else if(event.button.button == SDL_BUTTON_LEFT &&
		(event.button.x > 30 && event.button.x < 230 &&
		event.button.y > 440 && event.button.y < 503))
	{
		running = false;
	}
	else
	{
		menu_QuitButtonDown = false;
		menu_PlayButtonDown = false;
	}
} 

void Application::onClickDown_menu(SDL_Event event)
{
	if(event.button.button == SDL_BUTTON_LEFT && 
		(event.button.x > 30 && event.button.x < 230 &&
		event.button.y > 360 && event.button.y < 423))
	{	
		menu_PlayButtonDown = true;
	}
	else if(event.button.button == SDL_BUTTON_LEFT &&
		(event.button.x > 30 && event.button.x < 230 &&
		event.button.y > 440 && event.button.y < 503))
	{
		menu_QuitButtonDown = true;
	}
}

