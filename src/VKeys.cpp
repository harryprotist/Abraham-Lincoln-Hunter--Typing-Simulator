#include "VKeys.h"

bool VKeys::vk[61] = {false};

void VKeys::pushKey(int keyNum)
{
	vk[keyNum] = true;
}
void VKeys::popKey(int keyNum)
{
	vk[keyNum] = false;
}
bool VKeys::getKey(int keyNum)
{
	return vk[keyNum];
}

char VKeys::translateKey(int keyNum)
{
	switch(keyNum)
	{
		case 0: return '~'; break;
		case 1: return '1'; break;
		case 2: return '2'; break;
		case 3: return '3'; break;
		case 4: return '4'; break;
		case 5: return '5'; break;
		case 6: return '6'; break;
		case 7: return '7'; break;
		case 8: return '8'; break;
		case 9: return '9'; break;
		case 10: return '0'; break;
		case 11: return '-'; break;
		case 12: return '='; break;
		case 13: return '<'; break;
		case 14: return '|'; break;
		case 15: return 'q'; break;
		case 16: return 'w'; break;
		case 17: return 'e'; break;
		case 18: return 'r'; break;
		case 19: return 't'; break;
		case 20: return 'y'; break;
		case 21: return 'u'; break;
		case 22: return 'i'; break;
		case 23: return 'o'; break;
		case 24: return 'p'; break;
		case 25: return '['; break;
		case 26: return ']'; break;
		case 27: return '\\'; break;
		case 28: return '|'; break;
		case 29: return 'a'; break;
		case 30: return 's'; break;
		case 31: return 'd'; break;
		case 32: return 'f'; break;
		case 33: return 'g'; break;
		case 34: return 'h'; break;
		case 35: return 'j'; break;
		case 36: return 'k'; break;
		case 37: return 'l'; break;
		case 38: return ';'; break;
		case 39: return '\''; break;
		case 40: return '>'; break;
		case 41: return '|'; break;
		case 42: return 'z'; break;
		case 43: return 'x'; break;
		case 44: return 'c'; break;
		case 45: return 'v'; break;
		case 46: return 'b'; break;
		case 47: return 'n'; break;
		case 48: return 'm'; break;
		case 49: return ','; break;
		case 50: return '.'; break;
		case 51: return '/'; break;
		case 52: return '|'; break;
		case 53: return '|'; break;
		case 54: return '|'; break;
		case 55: return '|'; break;
		case 56: return ' '; break;
		case 57: return '|'; break;
		case 58: return '|'; break;
		case 59: return '|'; break;
		case 60: return '|'; break;
		default: return '|'; break;
	}
}
