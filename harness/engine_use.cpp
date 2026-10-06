// Emit header-inline engine functions until their real callers are reconstructed.
#include "../src/engine/xcolor.h"
#include "../src/engine/xconsole.h"
#include "../src/engine/xroot.h"

void harness_engine(XConsole *c, XCell *cell, XRoot *root, istream &in, Pos &p, Rect &r, XColor col, string s)
{
	XColor color;
	color.toString();

	XColorFilter filter;
	XColorFilter filter2(filter);
	cell->set(*cell);
	XCell cell2(*cell);
	cell->read(in);
	*cell = cell2;
	bool b = *cell != cell2;
	cell->getFore();
	cell->getBack();
	cell->scale(0.5f);
	cell->desaturate(0.5f);
	cell->colorize(&color);
	cell->swapColors();
	cell->shiftHue(1);
	cell->cycle(1);
	cell->invert();
	cell->applyFilters();

	c->inBounds(1,2);
	c->inBounds(p);
	c->contains(p);
	c->getPos();
	c->getAbsPos();
	c->getHeight();
	c->getMaxCoord();
	c->isWide();
	c->getScaleX();
	c->isUnscaled();
	c->hasSubconsoles();
	c->getSubconsoles();
	c->isHidden();
	c->isVisible();
	c->getChar(1,2);
	c->getFore(1,2);
	c->getBack(1,2);
	c->getCell(1,2);
	c->getChar(p);
	c->getFore(p);
	c->getBack(p);
	c->getCell(p);
	c->getString(p,3);
	c->getFirstLine();
	c->getStringVertical(p,3);
	c->getLastCharX(1);
	c->setPos(1,2);
	c->move(1,2);
	c->setFore(col);
	c->setBack(col);
	c->setScaleX(1.0f);
	c->setScaleY(1.0f);
	c->setHidden(true);
	c->clear();
	c->clear(1,2,3,4);
	c->clear(r);
	c->clearInterior();
	c->clear(c);
	c->clearBack();
	c->clearChars();
	c->deleteSubconsolesExcept(c);
	c->deleteSubconsolesExcept(c,c);
	c->getSubconsoleIndex(c);
	c->moveSubconsole(c,1);
	c->setChar(1,2,3);
	c->setFore(1,2,col);
	c->setBack(1,2,col,12);
	c->setString(1,2,s);
	c->putChar(1,2,3);
	c->putChar(1,2,3,col);
	c->putChar(1,2,3,col,col,1);
	c->putCell(1,2,*cell);
	c->setCharRow(1,2,3);
	c->setForeAll(col);
	c->setBackAll(col);
	c->resetBack();
	c->setPassThrough(true);
	c->setIgnoreMouse(true);
	c->getWidth();
	c->getParent();
	cell->getChar();

	root->getBuffer();
	root->getLastFrame();
}
