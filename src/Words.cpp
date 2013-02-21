#include "Words.h"

std::vector<const char*> Words::wordList {"lincoln", "house", "free", "war", "\'merica", "\'murica", "flag", "south", "north",
"jam", "civil", "theatre", "theater", "logs", "top", "hat", "catch", "america",
"time", "cannon", "canon", "barn", "door", "floor", "science", "prime", "plum",
"cent", "dollar", "principal", "zimbabwe", "music", "trumpet", "trombone", "piano",
"program", "meta", "yo", "dawg", "leopard", "lion", "plus plus", "c", "chemistry", "physics",
"angry", "exhibit", "blithe", "thorium", "thalium", "l1il1", "pzpzpzp", "trolls", "batch",
"grambler", "gambler", "broats", "goat", "nuclear", "nucular", "pushbroom", "squirrel", "hub",
"canada", "protist", "bomb", "lie", "liar", "yell", "screech", "will", "not", "if", "if and only if",
"pizza", "soup", "super", "xubuntu", "penguin", "over", "nine-thousand", "implies", "then", "or", "and",
"in soviet russia", "googol", "python", "int", "double", "float", "bool", "boolean", "lisp", "scheme",
"you", "hunt", "wampire", "captain", "kappa", "maple", "crayfish", "lobster", "laser", "sonic", "is", "breh",
"bro", "broseph", "stalin"};

SDL_Surface* Words::image = NULL;
TTF_Font* Words::font = NULL;
bool Words::fontLoaded = false;
std::string Words::phrase = "";

Words::Words()
{
}

void Words::onCleanup()
{
	SDL_FreeSurface(image);
	TTF_CloseFont(font);
}

bool Words::loadFont(const char* fontFile)
{
	if(fontLoaded || (font = TTF_OpenFont(fontFile, 14)) == NULL)
		return false; 

	fontLoaded = true;

	return true;
}

void Words::scrambleWords()
{
	if(!fontLoaded)
		return;

	srand(time(NULL));
	
	std::string tmpList;
	SDL_Color c = {0, 0, 0};
	
	//*
	for(int i = 0; i < (rand() % 3) + 3 && tmpList.length() < 40; i++)
	{
		tmpList += wordList[rand() % wordList.size()];
		tmpList += " ";
	}
	//*/
	if(image != NULL)
	{
		SDL_FreeSurface(image);
		image = NULL;
	}
	//tmpList = "a "; // remove when done debugging		

	phrase = tmpList;	
	image = TTF_RenderText_Solid(font, tmpList.c_str(), c);
}

std::string Words::getPhrase()
{
	return phrase;
}
void Words::setPhrase( const char* s )
{
	phrase = s;

	SDL_Color c = {0, 0, 0};
	image = TTF_RenderText_Solid(font, phrase.c_str(), c);
}

bool Words::blitWords(SDL_Surface* dest, int x, int y)
{
	return Render::Blit(image, dest, x, y);
}

