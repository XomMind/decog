// op_x5_a2: CScan::update (0x884460), matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <deque>
#include <list>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos();	// 0x453b40
	Pos(const Pos &pos);	// 0x46ca50
	Pos &operator=(const Pos &pos);	// 0x46ca50
	bool operator!=(const Pos &pos) const;	// 0x409bd0
	void set_409ff0(int v);	// NOTE: placeholder name (sets both coordinates)
};

struct Point	// NOTE: the exe names this type Point
{
	int x;
	int y;

	int clamp_40c270(int value);	// 0x40c270
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// 0x40a6e0
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	bool isHidden();
	void setHidden(bool hidden);
	void clear();
	void setScaleX(float value);
	void setScaleY(float value);
	float getScaleX();
	void print(int x, int y, const string &text);
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)
	void getRect4286b0(Rect &bounds);	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class OpQ4a_Engine	// NOTE: placeholder name (Engine)
{
public:
	bool update();	// NOTE: placeholder name (0x50fff0)
	void stopAll();	// NOTE: placeholder name (0x50ff30)
};

class Console : public XConsole
{
public:
	int unknown60;
	OpQ4a_Engine *engine;
	void *title;
};

class OpQ4a_Entity;

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	OpQ4a_Entity *operator->() const;	// 0x9b6570
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
};

class OpQ4a_Entity	// NOTE: placeholder name (Entity)
{
public:
	bool unknown5c8820(HEntity other);	// NOTE: placeholder name
	HItem unknown5d5d40();	// NOTE: placeholder name
	Pos &getPosition();	// 0x45a4a0
	Pos unknown5c80f0(const Pos &p);	// NOTE: placeholder name
};

class OpX5A_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
	bool unknown4631f0(HEntity entity);	// NOTE: placeholder name
	double unknown718430(HEntity entity, const Pos &pos, int a, int b);	// NOTE: placeholder name
	double unknown719a90(HEntity entity, const Pos &pos, int a, int b);	// NOTE: placeholder name
};
extern OpX5A_Map *opX5A_map;	// NOTE: placeholder name (0xcefc4c)

class OpX5A_MapView : public XConsole	// NOTE: placeholder name (MapView at 0xcec054)
{
public:
	bool unknown805190(Pos *p);	// NOTE: placeholder name
};
extern OpX5A_MapView *opX5A_mapView;	// NOTE: placeholder name (0xcec054)

class OpX5A_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool isIn(const Rect &bounds);	// NOTE: placeholder name (0x41a730)
};
extern OpX5A_Mouse *opX5A_mouse;	// NOTE: placeholder name

class CScanText : public Console
{
public:
	void setStyle(bool dark, bool silent, bool cell);	// NOTE: placeholder name (0x4a28d0)
};

class CScanButtons : public Console
{
public:
	void clearRows();	// NOTE: placeholder name (0x4a2770)
};

extern Point opX5A_range_d2c3f4;	// NOTE: placeholder name
extern Point opX5A_range_d1e01c;	// NOTE: placeholder name
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
string intToString(int value);

class CScan : public Console
{
public:
	virtual void update();	// 0x884460

	bool unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	CScanText *unknown74;	// NOTE: placeholder name
	CScanText *unknown78;	// NOTE: placeholder name
	CScanButtons *buttons;	// NOTE: placeholder name
	Pos unknown80;	// NOTE: placeholder name
	HProp unknown88;	// NOTE: placeholder name
	HEntity unknown8c;	// NOTE: placeholder name
	int unknown90;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
	int unknown9c;	// NOTE: placeholder name
	HProp unknownA0;	// NOTE: placeholder name
	int unknownA4;	// NOTE: placeholder name
	Pos unknownA8;	// NOTE: placeholder name
	int unknownB0;	// NOTE: placeholder name
	bool unknownB4;	// NOTE: placeholder name
};

void CScan::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
			break;	// NOTE: stray break before the first case (dead jmp in the exe)
		case 1:
			if (!engine->update())
				unknown60 = 3;
			break;
		case 3:
		{
			engine->update();
			if (unknown8c.operator->() && opX5A_map->unknown4631f0(unknown8c))
			{
				Pos pos = unknown80;
				HEntity entity = unknown8c;
				int meleeHit = opX5A_range_d2c3f4.clamp_40c270((int)(opX5A_map->unknown718430(opX5A_map->getPlayer(),pos,0,0) * 100.0));
				int rangedHit = opX5A_map->getPlayer()->unknown5c8820(entity) && opX5A_map->getPlayer()->unknown5d5d40().isValid() ? opX5A_range_d1e01c.clamp_40c270((int)(opX5A_map->unknown719a90(opX5A_map->getPlayer(),entity->unknown5c80f0(opX5A_map->getPlayer()->getPosition()),0,0) * 100.0)) : -1;
				if (meleeHit != unknown98 || rangedHit != unknown9c)
				{
					unknown98 = meleeHit;
					unknown9c = rangedHit;
					if (unknown78)
					{
						unknown78->clear();
						unknown78->print(0,0,"Base Hit " + intToString(unknown98) + (unknown9c == -1 ? string("%") : "% (melee " + intToString(unknown9c) + "%)"));
						unknown78->setStyle(true,false,false);
					}
				}
			}
			Rect bounds;
			getRect4286b0(bounds);
			bool hover = opX5A_mouse->isIn(bounds);
			if (hover)
			{
				if (buttons->isHidden())
				{
					buttons->setHidden(false);
					if (unknown74)
						unknown74->setHidden(true);
					if (unknown78)
						unknown78->setHidden(true);
				}
			}
			else if (!buttons->isHidden())
			{
				buttons->setHidden(true);
				buttons->clearRows();
				if (unknown74)
					unknown74->setHidden(false);
				if (unknown78)
					unknown78->setHidden(false);
			}
			Pos target;
			if (opX5A_mapView->unknown805190(&target))
			{
				if (unknownA8 != target)
				{
					unknownA8 = target;
					unknownB0 = tickCount;
				}
			}
			else
				unknownA8.set_409ff0(-1);
			break;
		}
		case 4:
			engine->update();
			if (getScaleX() != 0.0f)
			{
				if (tickCount - unknown70 >= 500)
				{
					setScaleX(0.0f);
					setScaleY(0.0f);
				}
				else
				{
					setScaleX(1.0 - (tickCount - unknown70) / 500.0);
					setScaleY(1.0 - (tickCount - unknown70) / 500.0);
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			break;
	}
	updateBase429e30();
}
