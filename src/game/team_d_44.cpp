// team_d_44: Entity member 0x6399e0 (corruption alert pulse: alert nearby hostile robots).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p) throw();		// 0x46ca50
	Point add(const Point &p) const;	// NOTE: placeholder name (PushCoord::add)
};

struct Area44	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;

	Area44();	// NOTE: placeholder name (0x40b100)
};

class Entity;

class HEntity
{
	int ID;
public:
	HEntity();
	bool isValid() const;
	Entity *operator->() const;
};

class EntityAI
{
public:
	bool unknown458f10();						// NOTE: placeholder name
	void unknown459520(const Point &p);			// NOTE: placeholder name
	int getMode();								// NOTE: placeholder name (folded getter)
	int unknown5b4710(HEntity e, int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown4593b0(const Point &p);			// NOTE: placeholder name
};

struct EntityData44	// NOTE: placeholder name and layout
{
	char	pad000[0x120];
	int		unknown120;	// NOTE: placeholder name
};

class Entity
{
public:
	char	pad00[4];
	HEntity	self;	// +0x04

	Point &getPosition();
	bool isHostileTo(HEntity e);
	bool isXomCandidate();			// 0x5d51a0
	EntityAI *getAI();				// 0x45b590
	int getSize();
	EntityData44 *getData();		// NOTE: placeholder name (folded getter 0x9b4350)
	bool isPlayer();				// 0x5c7600
	void unknown63a0d0();			// NOTE: placeholder name
	void unknown6399e0(int radius, bool quiet);	// NOTE: placeholder name
};

class Cell
{
public:
	HEntity getEntity();
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getRect(const Point &center, int radius, Area44 *out);	// NOTE: placeholder name (0x9b4430)
	Cell **at(int x, int y);		// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

struct Location44	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;
};

class HLoc44	// NOTE: placeholder name
{
	int ID;
public:
	Location44 *operator->() const;
};
extern HLoc44 location44_d1e888;	// NOTE: placeholder name

class State44	// NOTE: placeholder name (object at 0xd25450)
{
public:
	bool unknown000;	// NOTE: placeholder name

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
};
extern State44 state44_d25450;	// NOTE: placeholder name
extern int threat44_ba5e24[];	// NOTE: placeholder name

class PhraseText44	// NOTE: placeholder name (OpS2_PhraseTextB)
{
public:
	PhraseText44(int id, string *a, string *b, string *c, HEntity e1, HEntity e2);
	char pad[0x28];
};

class MessageLog	// NOTE: placeholder name (0xcf1080)
{
public:
	int push(PhraseText44 *text);
};
extern MessageLog messageLog_cf1080;	// NOTE: placeholder name

class Stats44	// NOTE: placeholder name (0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
};
extern Stats44 stats_d2c658;	// NOTE: placeholder name

class Map44	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	bool isVisible(const Point &p);	// 0x4631c0
};
extern Map44 *world44;	// NOTE: placeholder name (0xcefc4c)

class CMap44	// NOTE: placeholder name (0xcec054)
{
public:
	const Point &unknown458ef0();	// NOTE: placeholder name (trivial getter)
	bool inBounds(const Point &p);
};
extern CMap44 *cmap44_cec054;	// NOTE: placeholder name

class EngineItem44	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

struct Offset44;	// NOTE: placeholder name
extern Offset44 offset44_cfbec0;	// NOTE: placeholder name

class Engine44	// NOTE: placeholder name (0xcefc64)
{
public:
	EngineItem44 *unknown50fb50(Engine44 *engine, int type, const Point &a, Offset44 *b, Point *c, Point *d, int value);	// NOTE: placeholder name
};
extern Engine44 *engine44_cefc64;	// NOTE: placeholder name

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

int opw8_distance(int x1, int y1, int x2, int y2);	// NOTE: placeholder name
bool OpU8a_containsEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d31e0)
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name

void Entity::unknown6399e0(int radius, bool quiet)
{
	int score = 0;
	vector<HEntity> entities;
	Point p2(getPosition());
	Area44 area;
	cells_cfd44c.getRect(p2,radius,&area);
	for (int x = area.x1; x <= area.x2; x++)
	{
		for (int y = area.y1; y <= area.y2; y++)
		{
			if ((*cells_cfd44c.at(x,y))->getEntity().isValid())
			{
				HEntity e = (*cells_cfd44c.at(x,y))->getEntity();
				if (e->isHostileTo(self) && e->isXomCandidate() && opw8_distance(p2.x,p2.y,x,y) <= radius && e->getAI()->unknown458f10() && !OpU8a_containsEntity(entities,e))
				{
					e->getAI()->unknown459520(p2);
					entities.push_back(e);
					if (e->getAI()->getMode() == 1)
					{
						if (location44_d1e888->type == 0xd && e->getSize() > 1)
							e->getAI()->unknown5b4710(self,1,0,0,0);
						else
							e->getAI()->unknown4593b0(p2);
					}
					if (state44_d25450.unknown000)
						score += threat44_ba5e24[e->getData()->unknown120];
				}
			}
		}
	}
	if (!quiet && isPlayer())
	{
		do { if (messageLog_cf1080.push(new PhraseText44(0x16a,NULL,NULL,NULL,HEntity(),HEntity()))) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
		stats_d2c658.add4729d0(0x1c4,1,"",-1);
		stats_d2c658.add4729d0(0x1ce,1,"",-1);
		if (state44_d25450.unknown000 && score)
			state44_d25450.unknown69e700(0x2b,score >= 30,0.0f);
	}
	if (world44->isVisible(p2))
	{
		Point screen = p2.add(cmap44_cec054->unknown458ef0());
		if (cmap44_cec054->inBounds(screen))
		{
			int anim = 0;
			OpU8a_lookup1("A_CMap_Corruption_Alert",&anim);
			if (anim)
				engine44_cefc64->unknown50fb50(engine44_cefc64,anim,screen,&offset44_cfbec0,NULL,NULL,9)->unknown50de10();
			if (isPlayer())
				opR1d_4541b0(0x42,0,0);
		}
	}
	if (isPlayer())
		unknown63a0d0();
}
