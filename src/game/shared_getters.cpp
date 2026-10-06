#include "../pathing/gamedecl.h"
#include "../consoles/xconsole.h"

// NOTE: legacy pathing declaration exposes the terrain pointer as its x86 word.
int Cell::getTerrain()
{
	return (int)terrain;
}

int XBuffer::getWidth()
{
	return data[0];
}
