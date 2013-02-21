#include "Hand.h"

bool RECT_rectOverlap(rect a, rect b)
{
	for(int y = 0; y < 2; y++){
	for(int x = 0; x < 2; x++)
	{
		if(	a[0][0] < b[x][y] &&
		 	a[1][0] > b[x][y] &&
			a[0][1] < b[x][y] &&
			a[1][1] > b[x][y] )
		{
			return true;
		}
	}}
	return false;
}
bool RECT_pointInRect(point a, rect b)
{
	if(	b[0][0] < a[0] &&
	 	b[1][0] > a[0] &&
		b[0][1] < a[1] &&
		b[1][1] > a[1] )
	{
		return true;
	}
	return false;
}

Hand::Hand(bool rightHand) : 
	Entity(((rightHand) ? "Image/rightHand.png" : "Image/leftHand.png") , 42, 283)
{
	for(int i = 0; i < 5; i++)
		fingers[i] = false;	
}

void Hand::move(int moveX, int moveY)
{
	xMomentum += moveX;
	yMomentum += moveY;
}

void Hand::onRender(SDL_Surface* dest)
{
	image.state = 0;

	for(int i = 0; i < 5; i++) 
	{
		image.getFrame(dest, x + (i * 20), y, (fingers[i] ? 0 : 1));
		image.state++;
	}
}

void Hand::onLoop()
{
	x += xMomentum;
	y += yMomentum;
}

rect Hand::vKey_rects[61] = {{{24, 397}, {63, 431}},  // ~
			{{72, 392}, {111, 431}}, // 1
			{{120, 392}, {159, 431}}, // 2
			{{168, 392}, {207, 431}}, // 3
			{{216, 392}, {255, 431}}, // 4
			{{264, 392}, {303, 431}}, // 5
			{{312, 392}, {351, 431}}, // 6
			{{360, 392}, {399, 431}}, // 7
			{{408, 392}, {447, 431}}, // 8
			{{456, 392}, {495, 431}}, // 9
			{{504, 392}, {543, 431}}, // 0
			{{552, 392}, {591, 431}}, // -
			{{600, 392}, {639, 431}}, // =
			{{663, 392}, {774, 431}}, // BackSpace
			{{24, 440},  {87, 479}},  // Tab
			{{112, 440}, {151, 479}}, // Q
			{{160, 440}, {199, 479}}, // W
			{{208, 440}, {247, 479}}, // E
			{{256, 440}, {295, 479}}, // R
			{{304, 440}, {343, 479}}, // T
			{{352, 440}, {391, 479}}, // Y
			{{400, 440}, {439, 479}}, // U
			{{448, 440}, {487, 479}}, // I
			{{496, 440}, {535, 479}}, // O
			{{544, 440}, {583, 479}}, // P
			{{592, 440}, {639, 479}}, // [
			{{648, 440}, {695, 479}}, // ]
			{{720, 440}, {775, 479}}, // (BackSlash)
			{{24, 488}, {103, 527}},  // Caps Lock
			{{128, 488}, {167, 527}}, // A
			{{176, 488}, {215, 527}}, // S
			{{224, 488}, {263, 527}}, // D
			{{272, 488}, {311, 527}}, // F
			{{320, 488}, {359, 527}}, // G
			{{368, 488}, {407, 527}}, // H
			{{416, 488}, {455, 527}}, // J
			{{464, 488}, {503, 527}}, // K
			{{512, 488}, {551, 527}}, // L
			{{560, 488}, {607, 527}}, // ;
			{{616, 488}, {663, 527}}, // '
			{{688, 488}, {775, 527}}, // Enter
			{{24, 536}, {135, 575}},  // lShift
		/**/	{{157, 536}, {196, 575}}, // Z
			{{205, 536}, {244, 575}}, // X
			{{253, 536}, {292, 575}}, // C
			{{301, 536}, {340, 575}}, // V
			{{349, 536}, {388, 575}}, // B
			{{397, 536}, {436, 575}}, // N
			{{445, 536}, {484, 575}}, // M
			{{493, 536}, {532, 575}}, // ,
			{{541, 536}, {580, 575}}, // .
		/**/	{{589, 536}, {628, 575}}, // /
			{{664, 536}, {774, 575}}, // rShift
			{{28, 588},  {77, 619}},  // lCtrl
			{{93, 588},  {132, 621}}, // lHat
			{{149, 588}, {188, 621}}, // lAlt
			{{200, 584}, {543, 623}}, // SpaceBar
			{{557, 588}, {596, 621}}, // rAlt
			{{612, 588}, {652, 621}}, // rHat
			{{668, 588}, {709, 621}}, // ???
			{{724, 588}, {772, 621}}};// rCtrl

void Hand::getKeyPress(Hand* lHand, Hand* rHand)
{
	point rh[5];
	point lh[5];
	
	lh[0][0] = 15 + lHand->x;lh[0][1] = 50 + lHand->y;
	lh[1][0] = 60 + lHand->x;lh[1][1] = 36 + lHand->y;
	lh[2][0] = 104 + lHand->x;lh[2][1] = 33 + lHand->y;
	lh[3][0] = 148 + lHand->x;lh[3][1] = 38 + lHand->y;
	lh[4][0] = 190 + lHand->x;lh[4][1] = 155 + lHand->y;

	rh[0][0] = 15 + rHand->x;rh[0][1] = 155 + rHand->y;
	rh[1][0] = 60 + rHand->x;rh[1][1] = 38 + rHand->y;
	rh[2][0] = 104 + rHand->x;rh[2][1] = 33 + rHand->y;
	rh[3][0] = 148 + rHand->x;rh[3][1] = 36 + rHand->y;
	rh[4][0] = 190 + rHand->x;rh[4][1] = 50 + rHand->y;

	for(int f = 0; f < 5; f++)
	{
		for(int i = 0; i < 61; i++)
		{
			if(RECT_pointInRect(lh[f], vKey_rects[i]))
			{
				if(lHand->fingers[f]) 
					VKeys::pushKey(i);
				else VKeys::popKey(i);
			}
			if(RECT_pointInRect(rh[f], vKey_rects[i]))
			{
				if(rHand->fingers[f]) 
					VKeys::pushKey(i);
				else VKeys::popKey(i);
			}
		}
	}
}

