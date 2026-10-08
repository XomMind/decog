// op_w6_sigix: CSigixExoskeleton::render (0x8932a0), the Sigix exoskeleton HUD line
// "THREATS n  COMPONENTS n  PING_NUM n  TOR_DIST n" (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &c) throw();	// 0x411e30
};

struct Point
{
	int x;
	int y;
	Point(int x_, int y_) throw();	// 0x46ca20
	Point(const Point &p) throw();	// 0x46ca50
};

struct OpSX_Rect	// NOTE: placeholder name (ctor 0x40b100)
{
	OpSX_Rect() throw();
	int x1;
	int y1;
	int x2;
	int y2;
};

class Entity;
class OpSX_AI;	// NOTE: placeholder name
class HEntity
{
	int ID;
public:
	HEntity() throw();	// 0x9b6590
	bool isValid() const;	// 0x9b65e0
	Entity *operator->() const;	// 0x9b6570
};

struct OpSX_AIRecord	// NOTE: placeholder name
{
	int level;	// NOTE: placeholder name
};
class OpSX_AI	// NOTE: placeholder name
{
public:
	int getLevel_pingsize();	// NOTE: placeholder name (folded getter)
};

class Entity
{
public:
	bool isHostileTo(HEntity other);	// 0x45aa70
	OpSX_AI *getAI_45b590();	// NOTE: placeholder name
	const Point &getPosition();	// 0x45a4a0
	int unknown5c7d30();	// NOTE: placeholder name
};

class Item
{
public:
	int unknown457880();	// NOTE: placeholder name
};
class HItem
{
	int ID;
public:
	bool isValid() const;	// 0x9b65e0
	Item *operator->() const;	// 0x9b65b0
};

class Cell
{
public:
	HEntity getEntity();	// 0x45d250
	HItem getItem();	// NOTE: placeholder name
};

class OpSX_Cells	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell *&atPoint(const Point &p);	// NOTE: placeholder name (0x9ced70)
	Cell *&at(int x, int y);	// NOTE: placeholder name (0x9ceda0)
	void getRect(const Point &p, int radius, OpSX_Rect &out);	// NOTE: placeholder name (0x9b4430)
};
extern OpSX_Cells opSX_cells;	// NOTE: placeholder name

class OpSX_Map	// NOTE: placeholder name (BS)
{
public:
	int unknown464290();	// NOTE: placeholder name
	int unknown463710();	// NOTE: placeholder name
	vector<Point> *unknown463730();	// NOTE: placeholder name
	HEntity getPlayer();	// 0x4630f0
	bool isKnown(int x, int y);	// NOTE: placeholder name
	bool unknown463380(int x, int y);	// NOTE: placeholder name
	vector<vector<int> > *unknown463ec0();	// NOTE: placeholder name
	int unknown464490();	// NOTE: placeholder name
};
extern OpSX_Map *opSX_map;	// NOTE: placeholder name (0xcefc4c)

extern XColor *opSX_bg_cfd448;	// NOTE: placeholder name
extern XColor *opSX_fore_d386c8;	// NOTE: placeholder name

string intToString(int value);	// 0x4051f0
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
bool OpU8a_containsEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name

class CSigixExoskeleton
{
public:
	virtual void render();	// NOTE: placeholder name (vtable slot 7)

	void clear();	// 0x417bc0
	void setBgColor(XColor color);	// NOTE: placeholder name
	void setFore(XColor color);	// 0x417b00
	void setBack(XColor color);	// NOTE: placeholder name
	void print(int x, int y, const string &text);	// 0x4181d0

	char pad04[0x6c - 0x04];
	int turn;	// +0x6c, NOTE: placeholder name
	int threats;	// +0x70, NOTE: placeholder name
	int components;	// +0x74, NOTE: placeholder name
};

void CSigixExoskeleton::render()
{
	clear();
	setBgColor(*opSX_bg_cfd448);
	setFore(*opSX_fore_d386c8);
	setBack(*opSX_bg_cfd448);
	bool valid = false;
	if (turn != opSX_map->unknown464290())
	{
		valid = true;
		turn = opSX_map->unknown464290();
	}
	if (valid)
	{
		threats = opSX_map->unknown463710();
		vector<Point> *point = opSX_map->unknown463730();
		vector<HEntity> hits;
		HEntity entity;
		for (unsigned int i = 0; i < point->size(); i++)
		{
			entity = opSX_cells.atPoint((*point)[i])->getEntity();
			if (entity.isValid() && entity->isHostileTo(opSX_map->getPlayer()) && entity->getAI_45b590() && entity->getAI_45b590()->getLevel_pingsize() >= 2 && !OpU8a_containsEntity(hits,entity))
			{
				threats++;
				hits.push_back(entity);
			}
		}
	}
	string text = "THREATS " + (threats ? intToString(threats) : string("-"));
	print(1,0,text);
	if (valid)
	{
		components = 0;
		Point center(opSX_map->getPlayer()->getPosition());
		OpSX_Rect area;
		opSX_cells.getRect(center,OpX5_maxInt(opSX_map->getPlayer()->unknown5c7d30(),18),area);
		for (int x = area.x1; x < area.x2; x++)
		{
			for (int y = area.y1; y < area.y2; y++)
			{
				if (opSX_cells.at(x,y)->getItem().isValid() && opSX_cells.at(x,y)->getItem()->unknown457880() >= 6 && opSX_map->isKnown(x,y) && (opSX_map->unknown463380(x,y) || OpQ1_distanceCeil_40a3f0(center,Point(x,y)) <= 18))
					components++;
			}
		}
	}
	text = "COMPONENTS " + (components ? intToString(components) : string("-"));
	print(0xd,0,text);
	int num = (*opSX_map->unknown463ec0())[18].size();
	text = "PING_NUM " + (num ? intToString(num) : string("-"));
	print(0x1d,0,text);
	int distance = opSX_map->unknown464490();
	text = "TOR_DIST " + (distance ? intToString(distance) : string("?"));
	print(0x2a,0,text);
}
