#ifndef _APPLICATION_HAND_H_
#define _APPLICATION_HAND_H_

#include "Entity.h"
#include "Render.h"
#include "VKeys.h"

typedef int point[2];
typedef point rect[2];

static bool RECT_rectOverlap(rect a, rect b);
static bool RECT_pointInRect(point a, rect b);

class Hand : public Entity
{
public:

	static rect vKey_rects[61];
	static void getKeyPress(Hand* lHand, Hand* rHand);

	void onRender(SDL_Surface* dest);
	void onLoop();

	Hand(bool rightHand);

	void move(int moveX, int moveY);
	int xMomentum;
	int yMomentum;

	bool fingers[5];
	bool rightHand;
};

#endif
