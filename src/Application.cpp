#include "Application.h"

// Class constructor
Application::Application() : 	
	/* gameState(-1) enables splash screen */gameState(0), 
	mainWindow(NULL), 
	menu_Background(NULL), menu_Title(NULL),
	emulator_font(NULL),
	menu_PlayButtonDown(false), menu_QuitButtonDown(false),
	game_HUD(NULL), game_TileSet(NULL),
	level_Mansion(), player(NULL), p_isMoving(false), hasEntered(false), lincoln(NULL), l_isMoving(false),
	lastNumTicks(0), prevTicks(0), countTicks(0), countTo30(0),
	vIn("_"),
	splash_Image(NULL), splashTime(0),
	paper(NULL), paper_original(NULL), currentLine(0), lincolnProgress(0), gameWon(false), gameLost(false), countTo2(0), lBar(NULL), aFont(NULL)
{
	for(int i = 0; i < 256; i++) keys[i] = false;
	for(int i = 0; i < 61; i++) keyDelay[i] = 0;
}

// Main game loop
int Application::onExec()
{
	if(!(running = onInit() ) )
	{
		std::cerr << "Unable to initialize game" << std::endl;
	}

	while(running)
	{
		onEvent();
		onRender();
		onLoop();
	}
	
	onCleanup();
	
	return 0;
}
