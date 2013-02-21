#ifndef _APPLICATION_WORDS_H_
#define _APPLICATION_WORDS_H_

#include "Render.h"
#include "SDL/SDL_ttf.h"

#include <time.h>
#include <string>
#include <vector>

class Words
{
public:

	static std::vector<const char*> wordList;

	static bool blitWords(SDL_Surface* dest, int x, int y);
	static void scrambleWords();

	static std::string getPhrase();
	static void setPhrase( const char* s );
	
	static bool loadFont(const char* fontFile);

	static void onCleanup();	

	static TTF_Font* font;

private:

	Words();
	static bool fontLoaded;
	static std::string phrase;
	
	static SDL_Surface* image;
};

#endif 
