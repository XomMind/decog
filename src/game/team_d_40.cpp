// team_d_40: Entity member 0x600970 (ram/attack a blocking prop or wall cell).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

class HEntity
{
	int ID;
};

class Prop
{
public:
	bool isPassableFor(HEntity e);			// 0x65e1d0
	const string &getName();
	int unknown457b10();					// NOTE: placeholder name (folded getter)
	void unknown45cdb0(HEntity e, int value);	// NOTE: placeholder name
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
	HProp getProp();
	const string &unknown45d140();			// NOTE: placeholder name (terrain name)
	void unknown45df00(HEntity e, int value);	// NOTE: placeholder name
	bool unknown4550b0();					// NOTE: placeholder name (folded getter)
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

class Stats40	// NOTE: placeholder name (0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
};
extern Stats40 stats_d2c658;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

class ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA *consoleA_cec058;	// NOTE: placeholder name
class CLogMsgs
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern CLogMsgs *logMsgs_cec0b4;	// NOTE: placeholder name
bool logMessageS_5111e0(int id, const string &text, int a, int b, HEntity e, HProp d, int f, int g);	// NOTE: placeholder name (0x5111e0)
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)

#define OPD_LOGE(id,text,e) do { if (logMessageS_5111e0(id,text,0,0,e,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro

class Entity
{
public:
	char	pad00[4];
	HEntity	self;		// +0x04
	char	pad08[0x50 - 0x08];
	int		unknown50;	// NOTE: placeholder name
	char	pad54[0x8c - 0x54];
	int		unknown8c;	// NOTE: placeholder name

	int unknown5d1390();			// NOTE: placeholder name
	int unknown6008b0();			// NOTE: placeholder name
	bool isPlayer();				// 0x5c7600
	void alertGroup639ec0(HProp p, int a);	// NOTE: placeholder name
	int takeDamage(int a, int b, int c, int d, int e, int f, int g, bool h, HProp i, int j, int k, int l, int m, int n);	// 0x5e5520
	void unknown600e30();			// NOTE: placeholder name
	bool unknown5c8710(const Point &p);	// NOTE: placeholder name
	void unknown5ddac0(const Point &p, bool flag);	// NOTE: placeholder name
	void unknown5fdd30();			// NOTE: placeholder name
	void unknown600970(int unused, const Point &pos);	// NOTE: placeholder name
};

void Entity::unknown600970(int unused, const Point &pos)
{
	HProp prop;
	if ((*cells_cfd44c.atPoint(pos))->getProp().isValid() && !(*cells_cfd44c.atPoint(pos))->getProp()->isPassableFor(self))
		prop = (*cells_cfd44c.atPoint(pos))->getProp();
	int x = unknown5d1390();
	const string &line = prop.isValid() ? prop->getName() : (*cells_cfd44c.atPoint(pos))->unknown45d140();
	switch (x)
	{
	case 1:
		OPD_LOGE(0xa0,line,self);
		break;
	case 0:
		OPD_LOGE(0xa1,line,self);
		break;
	default:
		OPD_LOGE(0x9f,line,self);
		break;
	}
	int value = unknown6008b0();
	int cur = value;
	unknown50 = 0;
	if (isPlayer())
	{
		stats_d2c658.add4729d0(0x1b1,value,"",-1);
		stats_d2c658.add4729d0(0x1b6,value,"",-1);
		stats_d2c658.add4729d0(0x1e0,cur,"",-1);
		stats_d2c658.add4729d0(0x40e,1,"",-1);
	}
	alertGroup639ec0(HProp(),0);
	if (prop.isValid())
	{
		bool was = prop->unknown457b10() != 0;
		prop->unknown45cdb0(self,value);
		if (isPlayer() && !was && prop.operator->() == NULL)
			stats_d2c658.add4729d0(0x410,1,"",-1);
	}
	else
	{
		(*cells_cfd44c.atPoint(pos))->unknown45df00(self,value);
		if (isPlayer() && (*cells_cfd44c.atPoint(pos))->unknown4550b0())
			stats_d2c658.add4729d0(0x40f,1,"",-1);
	}
	HEntity it = self;
	if (cur)
		takeDamage(7,0,0,OpX5_maxInt(1,cur),4,0,0,false,HProp(),0,8,0,0,0);
	opR1d_4541b0(0xad,0,0);
	opR1d_4541b0(0xae,0,0);
	if (!unknown8c)
		return;
	if (rng.chance(100))
	{
		unknown600e30();
		if (!unknown8c)
			return;
		unknown600e30();
		if (!unknown8c)
			return;
	}
	if (!unknown5c8710(pos))
		unknown5ddac0(pos,false);
	unknown5fdd30();
}
