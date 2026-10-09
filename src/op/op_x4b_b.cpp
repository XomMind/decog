// op_x4b: functions in 0x6c1000-0x6c6000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../engine/xcolor.h"
using namespace std;

struct OpX4b_TerrainRecord	// NOTE: placeholder name
{
	char pad00[0x47];
	XColor backColor;
};

struct OpX4b_PropData	// NOTE: placeholder name
{
	char pad00[0x10];
	int unknown10;	// NOTE: placeholder name
};

class Prop
{
public:
	int unknown45c700();	// NOTE: placeholder name
	int unknown45c740();	// NOTE: placeholder name
	XColor unknown65dbb0();	// NOTE: placeholder name (color)
	XColor unknown65e040();	// NOTE: placeholder name
	int getNested45c570();	// NOTE: placeholder name
	OpX4b_PropData *unknown44b020();	// NOTE: placeholder name (ICF'd getter)
	bool unknown45cb10();	// NOTE: placeholder name
	int unknown457b10();	// NOTE: placeholder name (ICF'd getter)
};

class HProp
{
	int ID;
public:
	HProp();
	bool isValid() const;
	Prop *operator->() const;
};

class Cell
{
public:
	OpX4b_TerrainRecord *terrain9fcd80();	// NOTE: placeholder name (0x9fcd80)
	bool isDoor();
	bool unknown45d700();
	bool unknown45d1e0();
	HProp getProp();
	int getAscii();
	int getAsciiAlt();
	XColor getColor();
	bool canCaveIn();
};

class BS
{
public:
	bool opw3_unknown726c30(HProp prop, bool refresh);	// NOTE: placeholder name
};

extern BS *opx4b_world;	// NOTE: placeholder name (0xcefc4c)
extern XColor *opx4b_colorBlack;	// NOTE: placeholder name (0xcfe674)
extern XColor opx4b_colorD29804;	// NOTE: placeholder name
extern int opx4b_intCaf164;	// NOTE: placeholder name
extern int opx4b_intCaf15c;	// NOTE: placeholder name
extern bool opx4b_flagD28e82;	// NOTE: placeholder name
extern int opx4b_tickCount;	// NOTE: placeholder name (0xcaed20)

bool OpT8b_Fn9db380(int *value, int v);	// NOTE: placeholder name
bool OpT8b_Fn9db3a0(XColor &dest, XColor color);	// NOTE: placeholder name
XColor unknown6c1c70(XColor *color, bool *flag);	// NOTE: placeholder name

struct MapRecord	// element of the grid at BS+0x7c4
{
	void updateItem(Cell *cell);	// 0x6c1a90
	void opw3_unknown6c1cd0(Cell *cell, bool a, bool b);	// NOTE: placeholder name

	int ascii;
	int alternateAscii;
	XColor foreground;
	XColor background;
	bool backgroundSet;	// NOTE: placeholder name
	int unknown10;	// NOTE: placeholder name
	char pad14[0x24 - 0x14];
	int unknown24;	// NOTE: placeholder name
	int unknown28;	// NOTE: placeholder name
	int unknown2c;	// NOTE: placeholder name
	bool canCaveIn;	// NOTE: placeholder name
};

void MapRecord::opw3_unknown6c1cd0(Cell *cell, bool a, bool b)
{
	if (!a)
	{
		if (cell->isDoor())
		{
			HProp prop = cell->getProp();
			ascii = prop->unknown45c700();
			alternateAscii = prop->unknown45c740();
			foreground = prop->unknown65dbb0();
			if (cell->terrain9fcd80()->backColor != XColor(*opx4b_colorBlack))
			{
				background = XColor(cell->terrain9fcd80()->backColor);
				backgroundSet = true;
			}
			else
			{
				background = XColor(opx4b_colorD29804);
				backgroundSet = false;
			}
			unknown10 = opx4b_intCaf164;
			unknown24 = prop->getNested45c570();
			unknown28 = prop->unknown44b020()->unknown10;
			return;
		}
		else if (cell->unknown45d700())
		{
			updateItem(cell);
			return;
		}
	}
	bool changed = true;
	if (b)
	{
		changed = false;
		if (OpT8b_Fn9db380(&ascii,cell->getAscii()))
			changed = true;
		if (OpT8b_Fn9db380(&alternateAscii,cell->getAsciiAlt()))
			changed = true;
		if (OpT8b_Fn9db3a0(foreground,cell->getColor()))
			changed = true;
		if (OpT8b_Fn9db3a0(background,cell->unknown45d1e0() ? cell->getProp()->unknown65e040() : unknown6c1c70(&cell->terrain9fcd80()->backColor,&backgroundSet)))
			changed = true;
	}
	else
	{
		ascii = cell->getAscii();
		alternateAscii = cell->getAsciiAlt();
		foreground = cell->getColor();
		background = cell->unknown45d1e0() ? cell->getProp()->unknown65e040() : unknown6c1c70(&cell->terrain9fcd80()->backColor,&backgroundSet);
	}
	unknown10 = opx4b_intCaf164;
	unknown24 = opx4b_intCaf15c;
	if (cell->getProp().isValid() && cell->getProp()->unknown45cb10() && cell->getProp()->unknown457b10() == 0)
		opx4b_world->opw3_unknown726c30(cell->getProp(),true);
	if (a && changed && !opx4b_flagD28e82 && (!cell->unknown45d1e0() || !cell->getProp()->unknown45cb10()))
		unknown2c = opx4b_tickCount;
	canCaveIn = cell->canCaveIn();
}
