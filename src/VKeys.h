#ifndef _APPLICATION_VKEYS_H_
#define _APPLICATION_VKEYS_H_

#include "Hand.h"

class VKeys
{
private:
	VKeys(){};
	static bool vk[61];
public:
	static char translateKey(int keyNum);

	static void pushKey(int keyNum);
	static void popKey(int keyNum);
	static bool getKey(int keyNum);
};

#endif
