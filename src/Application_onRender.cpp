#include "Application.h"

const int res = 20;

void Application::onRender()
{
	switch(gameState)
	{
		case -1:
			onRender_splash();
		break;
		case 0:
			onRender_menu();
		break;
		case 1:
			onRender_game();
		break;
		case 2:
			onRender_type();
		break;
	}

	SDL_Flip(mainWindow);
}

void Application::onRender_splash()
{
	Render::Blit(splash_Image, mainWindow, 0, 0);
}

void Application::onRender_menu()
{
	Render::Blit(menu_Background, mainWindow, 0, 0);
	Render::Blit(menu_Title, mainWindow, 20, 20);
	
	if(menu_PlayButtonDown)
	{
		Render::Blit(menu_Button.down, mainWindow, 30, 360);
	}
	else
	{
		Render::Blit(menu_Button.up, mainWindow, 30, 360);
	}
	Render::DrawText(emulator_font, mainWindow, "PLAY GAME", 35, 375);
	
	if(menu_QuitButtonDown)
	{
		Render::Blit(menu_Button.down, mainWindow, 30, 440);
	}	
	else
	{
		Render::Blit(menu_Button.up, mainWindow, 30, 440);
	}
	Render::DrawText(emulator_font, mainWindow, "QUIT GAME", 35, 455);

	Render::DrawText(emulator_font, mainWindow, "Game made by Ben Sharafian", 0, 620);
}

void Application::onRender_game()
{
	int s;

	if(countTicks > 100)
	{
		for(int y = 0; y < level_Mansion.getH(); y++)
		{
			for(int x = 0; x < level_Mansion.getW(); x++)
			{
				Render::Blit(game_TileSet, mainWindow, x * res + 360 - (int)(360 / res + 1) * res, y * res + 150 - (int)(150 / res + 1) * res, res * 2, res * 3, res, res);
			}
		}
	}	

	for(int y = 0; y < level_Mansion.getH(); y++)
	{
		for(int x = 0; x < level_Mansion.getW(); x++)
		{						
			s = level_Mansion.getSpace(x, y) * res;
			Render::Blit(game_TileSet, mainWindow, x * res - player->x * res + 360, y * res - player->y * res + 150, s % (res * 5), ((s / res) / 5) * res, res, res);
		}
	}
	
	if(countTicks > 100)
	{
		player->image.getFrame(mainWindow, 360, 150 - res, -1);
		lincoln->image.getFrame(mainWindow, lincoln->x * res - player->x * res + 360, lincoln->y * res - player->y * res + 150 - res, -1);
	
		countTicks = 0;
	}
	else
	{
		player->image.getFrame(mainWindow, 360, 150 - res, player->image.getFrameInt());
		lincoln->image.getFrame(mainWindow, lincoln->x * res - player->x * res + 360, lincoln->y * res - player->y * res + 150 - res, lincoln->image.getFrameInt());
	}

	Render::Blit(game_HUD, mainWindow, 0, 0);

	for(int f = 0; f < 5; f++)
	{
		rHand->image.state = f;
		rHand->image.getFrame(mainWindow, rHand->x + f * 42, rHand->y, (int)rHand->fingers[f]);
	}
	for(int f = 0; f < 5; f++)
	{
		lHand->image.state = f;
		lHand->image.getFrame(mainWindow, lHand->x + f * 42, lHand->y, (int)lHand->fingers[f]);
	}

	if(hasEntered)
	{
		if(player->currentRoom->left != player->currentRoom)
		{
			availibleDirections->state = 0;
			availibleDirections->getFrame(mainWindow, 0, 0, 0);
		}
		if(player->currentRoom->up != player->currentRoom)
		{
			availibleDirections->state = 1;
			availibleDirections->getFrame(mainWindow, 200, 0, 0);
		}
		if(player->currentRoom->down != player->currentRoom)
		{
			availibleDirections->state = 2;
			availibleDirections->getFrame(mainWindow, 2 * 200, 0, 0);
		}
		if(player->currentRoom->right != player->currentRoom)
		{
			availibleDirections->state = 3;
			availibleDirections->getFrame(mainWindow, 3 * 200, 0, 0);
		}
	}

	Words::blitWords(mainWindow, 20, 8);	
	Render::DrawText(Words::font, mainWindow, vIn.c_str(), 20, 36);
}	

void Application::onRender_type()
{
	// render paper/bg
	Render::Blit(paper, mainWindow, 0, 0);
	// render hud
	Render::Blit(game_HUD, mainWindow, 0, 0);
	// render hands
	for (int f = 0; f < 5; f++)
	{
		rHand->image.state = f;
		rHand->image.getFrame(mainWindow, rHand->x + f * 42, rHand->y, (int)rHand->fingers[f]);
	}
	for (int f = 0; f < 5; f++)
	{
		lHand->image.state = f;
		lHand->image.getFrame(mainWindow, lHand->x + f * 42, lHand->y, (int)lHand->fingers[f]);
	}
	// render lincoln progress
	for (lBar->state = 0; lBar->state <= lincolnProgress; lBar->state++)
	{
		lBar->getFrame(mainWindow, 17 + lBar->state, 3, 0); 
	}
	// render text
	Render::DrawText(Words::font, mainWindow, vIn.c_str(), 20, 36);
}	
