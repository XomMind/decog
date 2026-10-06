// XCell / XConsole header-inline accessors laid out by LTCG at 0x416eb0-0x4176af (Beta 17.1).
// The bodies live in engine/xconsole.h (header-inline); this unit only references them so they
//	are emitted, and the same functions are also referenced from harness/engine_use.cpp.
// NOTE: placeholder function name
#include "engine/xcolor.h"
#include "engine/xconsole.h"

void unknown_cc_r2_15_use(XConsole *c, XCell *cell, XCell &cell2, XColor *color, Pos &p)
{
	bool b = *cell != cell2;
	cell->getFore();
	cell->getBack();
	cell->scale(0.5f);
	cell->desaturate(0.5f);
	cell->colorize(color);
	cell->swapColors();
	cell->shiftHue(1);
	cell->cycle(1);
	cell->invert();
	cell->applyFilters();

	c->inBounds(1,2);
	c->inBounds(p);
	c->contains(p);
	c->getAbsPos();
	c->getMaxCoord();
	c->isWide();
	c->getScaleX();
	c->isUnscaled();
	c->hasSubconsoles();
	c->getSubconsoles();
	c->isVisible();
	c->getChar(1,2);
	c->getFore(1,2);
}
