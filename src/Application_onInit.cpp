#include "Application.h"

bool Application::onInit()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	if(TTF_Init() < 0)
		return false;


	
	if((mainWindow = SDL_SetVideoMode(800, 640, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
	{
		return false;
	}
	SDL_WM_SetCaption("Abraham Lincoln Hunter", 0);

	// Load Splash Screen
	/*	
	if((splash_Image = Render::Load("Image/Splash.png")) == NULL)
	{
		return false;
	}
	*/

	// Load Font(s)
	if((emulator_font = TTF_OpenFont("Font/emulator.ttf", 20)) == NULL)
	{
		return false;
	}

	// Load for menu stage
	if((menu_Background = Render::Load("Image/menu_Background.png")) == NULL)
		return false;
	if((menu_Title = Render::Load("Image/menu_Title.png")) == NULL)
		return false;
	if((menu_Button.up = Render::Load("Image/menu_Button.png")) == NULL)
		return false;
	if((menu_Button.down = Render::Load("Image/menu_ButtonDown.png")) == NULL)
		return false;
	
	// Load for game stage
	lHand = new Hand(false);
	rHand = new Hand(true);
	
	lHand->x = 150;
	lHand->y = 450;

	rHand->x = 450;
	rHand->y = 450;
	
	if((game_HUD = Render::Load("Image/game_HUD.png")) == NULL)
		return false;
	if((game_TileSet = Render::Load("Map/map_tileset.png")) == NULL)
		return false;

	if(!level_Mansion.openMap("Map/map_house.map"))
		return false;

	// load map
	Room::createRooms(level_Mansion, rooms);
	Room::mapToRoom(level_Mansion, rooms);

	// create player
	player = new Character("Image/player.png", &rooms[1]);
	if(player->image.nullImage)
		return false;

	player->image.state = 4;

	availibleDirections = new Animation("Image/arrows.png", 200, 640);

	// create abraham-lincolnu
	srand(time(NULL) );
	lincoln = new Lincoln(rooms, player, &rooms.at(rooms.size() - (rand() % 6) ) );
	if(lincoln->image.nullImage)
		return false;

	lincoln->image.state = 4;

	// Setting up the words
	Words::loadFont("Font/emulator.ttf");
	Words::scrambleWords();

	// Prepare for the Typing stage
	if ( (aFont = TTF_OpenFont("Font/emulator.ttf", 11) ) == NULL)
	{
		return false;
	}
	if ( (paper = Render::Load("Image/paper.png") ) == NULL)
	{
		return false;
	}
	if ( (paper_original = Render::Load("Image/paper.png") ) == NULL)
	{
		return false;
	}

	lBar = new Animation("Image/progress.png", 1, 24);		

	setAddress();

	return true;
}
	
void Application::setAddress()
{
	std::string a = "four score and seven years ago\n\
our fathers brought forth on this continent, a\n\
new nation, conceived in liberty, and dedicated\n\
to the proposition that all men are created\n\
equal.\n\
now we are engaged in a great civil war,\n\
testing whether that nation, or any nation\n\
so conceived and so dedicated, can long endure.\n\
we are met on a great battle-field of that war.\n\
we have come to dedicate a portion of that\n\
field, as a final resting place for those who\n\
here gave their lives that that nation might\n\
live. it is altogether fitting and proper\n\
that we should do this.\n\
but, in a larger sense, we can not dedicate\n\
-- we can not consecrate -- we can not hallow\n\
-- this ground. the brave men, living and dead,\n\
who struggled here, have consecrated it, far\n\
above our poor power to add or detract. the\n\
world will little note, nor long remember what\n\
we say here, but it can never forget what they\n\
did here. it is for us the living, rather, to\n\
be dedicated here to the unfinished work which\n\
they who fought here have thus far so nobly\n\
advanced. it is rather for us to be here\n\
dedicated to the great task remaining before\n\
us -- that from these honored dead we take\n\
increased devotion to that cause for which\n\
they gave the last full measure of devotion\n\
-- that we here highly resolve that these\n\
dead shall not have died in vain -- that\n\
this nation, under god, shall have a new\n\
birth of freedom -- and that government of\n\
the people, by the people, for the people,\n\
shall not perish from the earth.";

	int index, lindex = 0;
	for (int i = 0; i < 36; i++)
	{
		index = a.find("\n", lindex);
		address.push_back(a.substr(lindex, (index - lindex) ) );

		lindex = index + 1;
	} 
}

