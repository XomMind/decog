// team_d_126: BS member 0x747860 (callers BS::turnUpdate_51da30/74e750, EntityAI::takeTurn and two BS members):
// activates the Command garrisons once - alert message and phrase, opens the garrison doors, rallies the
// Overmind's squads around the player, and points the commander's guards at the inner areas.
// NOTE: class layouts are partial; names other than BS are placeholders. Local names follow the stack-slot
// hash order.
#include <string>
#include <vector>
using namespace std;

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

struct Point
{
	int x;
	int y;

	Point(int v);					// 0x409990 (Pos)
	Point(int x_, int y_);			// 0x46ca20 (Pos)
	Point(const Point &p);			// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor
};

struct Area126	// NOTE: placeholder name (Area)
{
	int x1;
	int y1;
	int x2;
	int y2;

	Area126();								// 0x40b100
	Area126(const Point &a, const Point &b);	// NOTE: placeholder name (0x40b160)
	bool contains_40b750(const Point &p);	// NOTE: placeholder name
};

class AI126	// NOTE: placeholder name
{
public:
	int getMode126();	// NOTE: placeholder name (folded getter Array2D::getHeight)
	void setArea126(const Area126 &area);	// NOTE: placeholder name (Calls_459470::delegate)
};

class Entity;

class HEntity
{
public:
	int ID;
	HEntity();
	Entity *operator->() const;
	bool isNull() const;
};

class Entity
{
public:
	int getTarget();
	const Point &getPosition();
	void unknown5fdab0();	// NOTE: placeholder name (Push_5fdab0::operate)
	AI126 *getAI126();	// NOTE: placeholder name (folded getter ManualUI::unknown45b590)
};

class HProp
{
public:
	int ID;
	HProp();
};

struct Group126	// NOTE: placeholder name
{
	vector<HEntity> *getMembers126();	// NOTE: placeholder name (folded getter XCell::getFore)
};

class HGroup
{
public:
	int ID;
	Group126 *operator->();	// NOTE: OpC_Handle::get230
};

class Cell
{
public:
	void unknown66a050(int terrainID, int cause, int flag);	// NOTE: placeholder name
};

class CellGrid126	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(Point &p);			// NOTE: folded (OpX5_Array2D<int>::atPoint)
	Area126 getArea();					// NOTE: placeholder name (0x9b4400)
	void getRect(const Point &center, int radius, Area126 *out);	// NOTE: placeholder name (0x9b4430)
};
extern CellGrid126 cells126_cfd44c;	// NOTE: placeholder name

struct TerrainType126	// NOTE: placeholder name
{
	int		ID;
};
extern TerrainType126 *terrain126_cefb9c;	// NOTE: placeholder name

class OpV1_GameData
{
public:
	const string &getEntryText(const string &key);
	void setEntryText(const string &key, const string &text);
};
extern OpV1_GameData gameData126_d1e860;	// NOTE: placeholder name

class Overmind126	// NOTE: placeholder name (Overmind at 0xcf6428)
{
public:
	void *unknown687520(HEntity e, int a, bool b);	// NOTE: placeholder name
	void unknown683e60(const Point &pos, vector< vector<HEntity> > *out);	// NOTE: placeholder name
};
extern Overmind126 overmind126_cf6428;	// NOTE: placeholder name

class MessageLog126	// NOTE: placeholder name (0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name
};
extern MessageLog126 messageLog126_cf1080;	// NOTE: placeholder name
extern bool soundOff126_d28fb0;	// NOTE: placeholder name
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name

class ConsoleA126	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA126 *consoleA126_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs126_cec0b4;	// NOTE: placeholder name

bool showMessage126(int id, const string *text, const string *b, int c, HProp d, HProp e, const void *at, int flag);	// NOTE: placeholder name (0x5111e0)
void message126_5141b0(int id, const string *text, int b, int c, HProp e, int d);	// NOTE: placeholder name (0x5141b0)

struct Location126	// NOTE: placeholder name
{
	int		unknown00;
	int		type;	// +0x04
};

class HLocation126	// NOTE: placeholder name
{
public:
	int ID;
	Location126 *operator->() const;	// NOTE: OpC_Handle::get23c
};

struct Garrison126b	// NOTE: placeholder name and layout
{
	Point			pos;		// +0x00
	HLocation126	location;	// +0x08
};

class BS	// NOTE: placeholder layout
{
public:
	char					pad000[0x10];
	vector<Garrison126b *>	garrisons;	// +0x010
	char					pad020[0x4c - 0x20];
	vector<HGroup>			groups;		// +0x04c
	char					pad05c[0x66c - 0x5c];
	HEntity					player;		// +0x66c

	HEntity unknown715230(int a, int b);	// NOTE: placeholder name
	void unknown747860(bool a, bool b);	// NOTE: placeholder name
};

void BS::unknown747860(bool a, bool b)
{
	if (stringToInt(gameData126_d1e860.getEntryText("comMaincReinforced_g")))
		return;
	HEntity last = unknown715230(3,0x5f);
	if (last.isNull() || last->getTarget())
		return;
	do
	{
		messageLog126_cf1080.unknown451400(1);
		if (1)
		{
			if (!(soundOff126_d28fb0 && 0 && 1))
				opR1d_4541b0(0x11e,0,0);
		}
		do
		{
			if (showMessage126(0x324,&string("ALERT: All Command garrisons activated."),0,0,HProp(),HProp(),0,0))
				consoleA126_cec058->unknown8758d0(true);
			logMsgs126_cec0b4->scrollToEnd();
		} while (0);
		logMsgs126_cec0b4->scrollToEnd();
	} while (0);
	do
	{
		message126_5141b0(0x220,0,0,0,HProp(),0);
	} while (0);
	vector<Point> vec;
	vec.push_back(Point(0x98,0x48));
	vec.push_back(Point(0x99,0x48));
	vec.push_back(Point(0x9a,0x48));
	vec.push_back(Point(0x98,0x52));
	vec.push_back(Point(0x99,0x52));
	vec.push_back(Point(0x9a,0x52));
	for (unsigned int i = 0; i < vec.size(); i++)
		(*cells126_cfd44c.atPoint(vec[i]))->unknown66a050(terrain126_cefb9c->ID,2,0);
	if (!stringToInt(gameData126_d1e860.getEntryText("comPlayerSurrendered_g")))
		overmind126_cf6428.unknown687520(player,0,false);
	vector< vector<HEntity> > list;
	overmind126_cf6428.unknown683e60(player->getPosition(),&list);
	Area126 center = cells126_cfd44c.getArea();
	for (unsigned int j = 0; j < list.size(); j++)
	{
		for (unsigned int k = 0; k < list[j].size(); k++)
		{
			list[j][k]->unknown5fdab0();
			list[j][k]->getAI126()->setArea126(center);
		}
		list[j].clear();
	}
	if (a)
	{
		Area126 h(Point(0x74,0x40),Point(0xad,0x51));
		Area126 w;
		Point pt(1);
		for (unsigned int m = 0; m < garrisons.size(); m++)
		{
			if (garrisons[m]->location->type == 6 && garrisons[m]->pos.x > 100)
			{
				pt = garrisons[m]->pos;
				break;
			}
		}
		cells126_cfd44c.getRect(pt,0xf,&w);
		vector<HEntity> *msgs = groups[3]->getMembers126();
		for (unsigned int n = 0; n < msgs->size(); n++)
		{
			if (w.contains_40b750((*msgs)[n]->getPosition()) && (*msgs)[n]->getAI126()->getMode126() == 1)
				(*msgs)[n]->getAI126()->setArea126(h);
		}
	}
	if (b)
	{
		Area126 tag(Point(0x74,0x40),Point(0x93,0x48));
		Area126 point(Point(0x91,0x4b),Point(0x95,0x51));
		vector<HEntity> *size = groups[3]->getMembers126();
		for (unsigned int q = 0; q < size->size(); q++)
		{
			if (point.contains_40b750((*size)[q]->getPosition()) && (*size)[q]->getAI126()->getMode126() == 1)
				(*size)[q]->getAI126()->setArea126(tag);
		}
	}
	gameData126_d1e860.setEntryText("comMaincReinforced_g","1");
}
