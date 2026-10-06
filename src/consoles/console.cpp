#include "console.h"

void Console::resize(int width, int height)
{
	XConsole::resize(width,height);
	engine->setMax(getMaxCoord());
}
