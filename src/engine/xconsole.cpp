#include "engine/xconsole.h"
#include "engine/xroot.h"

//==================================================================
// XCell
//==================================================================

XCell::XCell()
	: font	(0)
	, ch	(' ')
	, glyph	(fontCharmaps[font]->at(' '))
	, fore	(COLOR_BLACK)
	, back	(COLOR_BLACK)
{}

XCell::XCell(int font_)
	: font	(font_)
	, ch	(' ')
	, glyph	(fontCharmaps[font]->at(' '))
	, fore	(COLOR_BLACK)
	, back	(COLOR_BLACK)
{}

XCell::XCell(int font_, int ch_, XColor fore_, XColor back_)
	: font	(font_)
	, ch	(ch_)
	, glyph	(fontCharmaps[font]->at(ch_))
	, fore	(fore_)
	, back	(back_)
{}

void XCell::setChar(int ch_)
{
	ch = ch_;
	glyph = fontCharmaps[font]->at(ch_);
}

void XCell::setChar(int ch_, XColor fore_)
{
	ch = ch_;
	glyph = fontCharmaps[font]->at(ch_);
	fore = fore_;
}

void XCell::set(int ch_, XColor fore_, XColor back_, int flag)
{
	ch = ch_;
	glyph = fontCharmaps[font]->at(ch_);
	fore = fore_;
	setBack(back_,flag);
}

// background blending modes, as libtcod's TCOD_bkgnd_flag_t (alpha in bits 8+)
void XCell::setBack(XColor back_, int flag)
{
	switch (flag & 0xff)
	{
		case 1: back = back_; break;
		case 2: back.add(back_); break;
		case 3: back.subtract(back_); break;
		case 4: back.multiply(back_); break;
		case 5:
		{
			float alpha = (flag >> 8) / 255.0;
			back.lerp(back_,alpha);
			break;
		}
		case 6:
		{
			float alpha = (flag >> 8) / 255.0;
			back.addAlpha(back_,alpha);
			break;
		}
		case 7: back.screen(back_); break;
		case 8: back.colorDodge(back_); break;
		case 9: back.colorBurn(back_); break;
		case 10: back.burn(back_); break;
		case 11: back.overlay(back_); break;
	}
}

//==================================================================
// XConsole
//==================================================================

XConsole::XConsole(XConsole *parent_, int width, int height, int x, int y, int font_, bool hidden_, int layer_)
	: parent		(parent_)
	, font			(font_)
	, fontType		(rex.fontSets[font].type)
	, fore			(COLOR_WHITE)
	, back			(COLOR_BLACK)
	, backFlag		(0)
	, alignment		(0)
	, scaleX		(1)
	, scaleY		(1)
	, hidden		(hidden_)
	, passThrough	(false)
	, ignoreMouse	(false)
{
	setPos(Pos(x,y));
	if (parent != NULL)
		parent->subconsoles.push_back(this);
	buffer.resize(width,height,XCell(font));
	if (parent != NULL)
		rex.consoleAddToLayer(this,layer_);
	else
		layer = -1;
}

XConsole::~XConsole()
{
	deleteVectorContents(subconsoles);
	if (!rexShuttingDown)
	{
		mouse->forgetConsole(this);
		if (parent != NULL)
			rex.consoleRemoveFromLayer(this);
	}
}

Pos XConsole::absToLocal(Pos p)
{
	p -= absPos;
	if (fontType != 0)
	{
		switch (fontType)
		{
			case 1:
				if (p.x < 0) p.x--;
				p.x /= 2;
				break;
			case 2:
				if (p.x < 0) p.x--;
				p.x /= 2;
				if (p.y < 0) p.y--;
				p.y /= 2;
				break;
			case 3:
				if (p.x < 0) p.x -= 3;
				p.x /= 4;
				if (p.y < 0) p.y--;
				p.y /= 2;
				break;
		}
	}
	return p;
}

Pos XConsole::localToAbs(Pos p)
{
	if (fontType != 0)
	{
		p.x *= FONT_TYPE_WIDTH[fontType];
		p.y *= FONT_TYPE_HEIGHT[fontType];
	}
	p += absPos;
	return p;
}

Rect XConsole::getRect()
{
	return Rect(absPos.x,absPos.y,getWidth() * FONT_TYPE_WIDTH[fontType],getHeight() * FONT_TYPE_HEIGHT[fontType]);
}

bool XConsole::getVisibleArea(int *x, int *y, int *offsetX, int *offsetY)
{
	if ((absPos.x >= rex.getRoot()->getWidth() && absPos.y >= rex.getRoot()->getHeight()) ||
		(absPos.x + getWidth() * FONT_TYPE_WIDTH[fontType] < 0 && absPos.y + getHeight() * FONT_TYPE_HEIGHT[fontType] < 0))
		return false;
	*x = absPos.x >= 0 ? 0 : -absPos.x / FONT_TYPE_WIDTH[fontType];
	*y = absPos.y >= 0 ? 0 : -absPos.y / FONT_TYPE_HEIGHT[fontType];
	*offsetX = *x > 0 ? 0 : absPos.x;
	*offsetY = *y > 0 ? 0 : absPos.y;
	return true;
}

XConsole *XConsole::getConsoleAt(const Pos &p)
{
	if (hidden || (layer > 0 && this != modal->getConsole() && !contains(p)) || ignoreMouse)
		return NULL;
	XConsole *console = NULL;
	if (!subconsoles.empty())
	{
		for (int i = subconsoles.size() - 1; i >= 0; i--)
		{
			console = subconsoles[i]->getConsoleAt(p);
			if (console != NULL)
				return console;
		}
	}
	if (passThrough)
	{
		XConsole *target = this;
		while (target->parent != NULL && target->passThrough)
			target = target->parent;
		return target;
	}
	return this;
}

void XConsole::resize(int width, int height)
{
	buffer.resize(width,height,XCell(font));
}

void XConsole::setPos(const Pos &p)
{
	pos = p;
	if (parent != NULL)
	{
		absPos = parent->absPos;
		absPos.translate(pos.x * FONT_TYPE_WIDTH[parent->fontType],pos.y * FONT_TYPE_HEIGHT[parent->fontType]);
	}
	else
		absPos.set(0);
	for (unsigned int i = 0; i < subconsoles.size(); i++)
		subconsoles[i]->setPos(subconsoles[i]->getPos());
}

void XConsole::clearRow(int x, int y, int width)
{
	XCell cell(font);
	for (int i = x; i < x + width; i++)
		buffer.get(i,y)->set(cell);
}

void XConsole::deleteSubconsoles()
{
	deleteVector(subconsoles);
}

void XConsole::setCharRow(int x, int y, int width, int ch)
{
	for (int i = x; i < x + width; i++)
		buffer.get(i,y)->setChar(ch);
}

void XConsole::setCharRow(int x, int y, int width, int ch, XColor fore_)
{
	for (int i = x; i < x + width; i++)
		buffer.get(i,y)->setChar(ch,fore_);
}

void XConsole::setCharRow(int x, int y, int width, int ch, XColor fore_, XColor back_)
{
	for (int i = x; i < x + width; i++)
		buffer.get(i,y)->set(ch,fore_,back_,1);
}

void XConsole::setCharColumn(int x, int y, int height, int ch)
{
	for (int i = y; i < y + height; i++)
		buffer.get(x,i)->setChar(ch);
}

void XConsole::setCharColumn(int x, int y, int height, int ch, XColor fore_)
{
	for (int i = y; i < y + height; i++)
		buffer.get(x,i)->setChar(ch,fore_);
}

void XConsole::setChars(int x, int y, int width, int height, int ch)
{
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
			buffer.get(i,j)->setChar(ch);
	}
}

void XConsole::setForeRow(int x, int y, int width, XColor color)
{
	for (int i = x; i < x + width; i++)
		buffer.get(i,y)->fore = color;
}

void XConsole::setForeColumn(int x, int y, int height, XColor color)
{
	for (int i = y; i < y + height; i++)
		buffer.get(x,i)->fore = color;
}

void XConsole::setFore(int x, int y, int width, int height, XColor color)
{
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
			buffer.get(i,j)->fore = color;
	}
}

void XConsole::setForeFrame(int x, int y, int width, int height, XColor color)
{
	setForeRow(x,y,width,color);
	setForeRow(x,y + height - 1,width,color);
	setForeColumn(x,y + 1,height - 2,color);
	setForeColumn(x + width - 1,y + 1,height - 2,color);
}

void XConsole::setBackRow(int x, int y, int width, XColor color)
{
	for (int i = x; i < x + width; i++)
		buffer.get(i,y)->back = color;
}

void XConsole::setBack(int x, int y, int width, int height, XColor color)
{
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
			buffer.get(i,j)->back = color;
	}
}

bool XConsole::input(XEvent *event)
{
	if (subconsoles.empty())
		return false;
	if (event->mouse.x == MOUSE_NONE)
	{
		for (int i = subconsoles.size() - 1; i >= 0; i--)
		{
			XConsole *console = subconsoles[i];
			if (console->input(event))
				return true;
		}
	}
	else
	{
		for (int i = subconsoles.size() - 1; i >= 0; i--)
		{
			if (subconsoles[i]->layer == 0 || subconsoles[i]->contains(event->mouse))
			{
				XConsole *console = subconsoles[i];
				if (console->input(event))
					return true;
			}
		}
	}
	return false;
}

void XConsole::update()
{
	if (subconsoles.empty())
		return;
	for (unsigned int i = 0; i < subconsoles.size(); i++)
	{
		XConsole *console = subconsoles[i];
		console->update();
	}
}

void XConsole::render()
{
	if (subconsoles.empty())
		return;
	for (unsigned int i = 0; i < subconsoles.size(); i++)
	{
		XConsole *console = subconsoles[i];
		console->render();
	}
}

int XConsole::countVisible()
{
	if (hidden)
		return 0;
	int count = 1;
	for (unsigned int i = 0; i < subconsoles.size(); i++)
		count += subconsoles[i]->countVisible();
	return count;
}
