#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <math.h>

#include "Room.h"
#include "Map.h"
#include "Render.h"
#include "Button.h"
#include "Lincoln.h"
#include "Hand.h"
#include "Words.h"

class Application
{
public:

	int onExec();

	Application();

private:	

	bool running;	
	int gameState;
	
	SDL_Surface* mainWindow;
	
	/////////////////

	SDL_Surface* splash_Image;
	int splashTime;

	/////////////////

	SDL_Surface* menu_Background;
	SDL_Surface* menu_Title;
	
	Button menu_Button;

	bool menu_PlayButtonDown;
	bool menu_QuitButtonDown;

	///////////////////
	
	SDL_Surface* game_HUD;
	SDL_Surface* game_TileSet;
	
	Lincoln* lincoln;
	bool l_isMoving;
	
	Character* player;
	bool p_isMoving;
	bool hasEntered;

	Animation* availibleDirections;

	Hand* lHand;
	Hand* rHand;

	bool runTyping();
	void runPresses(int& lHandSpeed, int& rHandSpeed);
	void runHandMove(int lHandSpeed, int rHandSpeed);

	Map level_Mansion;
	std::vector<Room> rooms;

	int lastNumTicks;
	int prevTicks;
	int countTicks;
	int countTo30;

	bool keys[256];

	int keyDelay[61];
	std::string vIn;
		

	///////////////////

	void setAddress();

	SDL_Surface* paper;
	SDL_Surface* paper_original;
	std::vector<std::string> address;
	int currentLine;
	void cacheText();
	TTF_Font* aFont;
	
	int lincolnProgress;
	Animation* lBar;

	bool gameWon;
	bool gameLost;
	
	int countTo2;

	///////////////////

	TTF_Font* emulator_font;


	bool onInit();
	void onCleanup();
	
	void onEvent();
		
		void onClickDown_menu(SDL_Event event);void onClickDown_game(SDL_Event event);void onClickDown_type(SDL_Event event);
		void onClickUp_menu(SDL_Event event);void onClickUp_game(SDL_Event event);void onClickUp_type(SDL_Event event);
	
		void onKeyDown_menu(SDL_Event event);void onKeyDown_game(SDL_Event event);void onKeyDown_type(SDL_Event event);
		void onKeyUp_menu(SDL_Event event);void onKeyUp_game(SDL_Event event);void onKeyUp_type(SDL_Event event);			

	void onLoop();
		
		void onLoop_splash();
		void onLoop_menu();
		void onLoop_game();
		void onLoop_type();

		void onWin();
		void onLose();
	
	void onRender();

		void onRender_splash();
		void onRender_menu();
		void onRender_game();
		void onRender_type();
};

#endif
