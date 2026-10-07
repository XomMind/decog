// op_r3b: Cell methods (0x670000-0x682000) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include "../util/rng.h"
#include "../game/penetrationrollpool.h"
using namespace std;

extern RNG rng;	// NOTE: placeholder name (0xd30908)

struct Point
{
	int x;
	int y;

	Point();
	Point(const Point &p);
	Point &operator=(const Point &p);
	void set(int x_, int y_);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();
	XColor(const XColor &c);
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const Point &p);	// 0x9ced70
	int getWidth();					// 0x9fcd80
	int getHeight();				// 0x9b8f00
};

class Cell;
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

class Entity;
class Prop;
class Group;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool isValid() const;
	bool isNull() const;
	Entity *operator->() const;
};

class Item;

class HItem
{
	int	ID;
public:
	HItem();
	bool isValid() const;
	Item *operator->() const;	// 0x9b65b0
};

class HProp
{
	int	ID;
public:
	HProp();
	bool isValid() const;
	bool isNull() const;
	Prop *operator->() const;
};

class HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	HGroup();
	bool isValid() const;
	Group *operator->() const;	// 0x9b7250
};

class Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();	// NOTE: placeholder name (ICF'd getter)
};

class Entity
{
public:
	HGroup getGroup();
};

class BS	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
	HEntity getEntity_45d250();	// NOTE: placeholder name (folded HEntity getter, 0x45d250)
	void unknown465840(const Point &p, HEntity e);	// NOTE: placeholder name
	bool unknown71ec60(const Point &p, vector<Point> visited);	// NOTE: placeholder name
	void addPoint6a8(const Point &p);	// NOTE: placeholder name (0x465320)
};
extern BS *world;	// NOTE: placeholder name (0xcefc4c)

struct CellEffectRecord	// NOTE: partial record
{
	int type;
};

struct CellEffect	// NOTE: partial effect object
{
	CellEffectRecord	*record;
	int					value;

	CellEffect(CellEffectRecord *record_, int value_) throw();	// 0x46ca20
};

struct OpR3b_TerrainBase	// NOTE: placeholder name
{
	int					pad00[8];
	int					resists[7];
	vector<CellEffect *>	effects;
	bool				unknown4c;
};

struct CellTerrainRecord	// NOTE: member names are placeholders
{
	int					ID;
	string				name;
	string				tag;
	int					unknown3c;
	int					unknown40;
	XColor				foreColor;
	XColor				backColor;
	int					unknown4c;
	OpR3b_TerrainBase	*base;
	int					unknown54;
	bool				unknown58;
	int					passable;
	bool				unknown60;
	int					unknown64;
	int					armor;
	int					unknown6c;
	int					unknown70;
	int					unknown74;
	int					unknown78;
	bool				unknown7c;
	bool				unknown7d;
	vector<CellEffect *>	effects;
	string				description;
	void				*sound1;
	void				*sound2;
	void				*sound3;
	string				unknownB8;
	int					unknownD4;
	int					unknownD8;
	bool				unknownDC;
};

struct OpR3b_Attack	// NOTE: placeholder name
{
	char	pad00[0x68];
	int		damage;
	int		type;
};

struct OpR3b_Actor	// NOTE: placeholder name
{
	char	pad00[0x174];
	string	name;
};

bool opr3b_logMessage(int id, const string &text, const string *b, int c, HEntity d, HEntity e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)

class OpR3b_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpR3b_MsgConsole *opr3b_msgConsole;	// NOTE: placeholder name (0xcec058)

class OpR3b_LogMsgs	// NOTE: placeholder name (CLogMsgs)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpR3b_LogMsgs *opr3b_logMsgs;	// NOTE: placeholder name (0xcec0b4)
extern OpR3b_LogMsgs *opr3b_logMsgs2;	// NOTE: placeholder name (0xcec0c4)

class SoundMgr	// NOTE: placeholder name
{
public:
	void unknown454500(const Point &p);	// NOTE: placeholder name
};
extern SoundMgr soundMgr;	// NOTE: placeholder name (0xd2d2a0)
extern vector<Point> opr3b_pointsD2c454;	// NOTE: placeholder name (0xd2c454)

extern PenetrationRollPool opr3b_rollPool;	// NOTE: placeholder name (0xd2c41c)
extern int opr3b_debugLevel;	// NOTE: placeholder name (0xd28d18)
extern vector<CellEffectRecord *> opr3b_effectRecords;	// NOTE: placeholder name (0xd2f0f8)

class Cell
{
public:
	CellTerrainRecord	*terrain;
	int					unknown04;
	int					unknown08;
	int					unknown0c;
	XColor				color;
	string				unknown14;
	Point				position;
	bool				open;
	bool				blocked;
	bool				unknown3a;
	char				pad3b;
	int					caveinInstability;
	int					unknown40;
	HProp				prop;
	HEntity				entity;
	vector<HItem>		items;
	vector<CellEffect *>	effects;
	int					unknown6c;

	CellEffect *getEffect(int type);
	string *unknown45d140();	// NOTE: placeholder name
	bool unknown45db90();	// NOTE: placeholder name
	bool unknown45dc70();	// NOTE: placeholder name
	bool unknown45dbb0();	// NOTE: placeholder name
	HItem getItem();	// 0x45d8f0
	void unknown66dae0(int amount, int type, bool a, int b, int c, int d, HEntity e, int f);	// NOTE: placeholder name

	void unknown670150(OpR3b_Attack *attack);	// NOTE: placeholder name
	bool unknown6701c0(int a, int b, OpR3b_Actor *actor);	// NOTE: placeholder name
	int unknown670360(int type, int amount);	// NOTE: placeholder name
	bool unknown670400();	// NOTE: placeholder name
	void unknown670690();	// NOTE: placeholder name
	void unknown6706d0(bool flag);	// NOTE: placeholder name
};

void Cell::unknown670150(OpR3b_Attack *attack)
{
	unknown66dae0(attack->damage * (attack->type >= 7 ? 100 : terrain->base->resists[attack->type]) / 100, attack->type, false, 0, 0, 0, HEntity(), 0);
}

bool Cell::unknown6701c0(int a, int b, OpR3b_Actor *actor)
{
	if (terrain->armor == -1)
		return false;
	if (b == -1 || (a == -1 ? opr3b_rollPool.nextValue() : opr3b_rollPool.peekValue(a)) <= b)
	{
		if (a == -1)
		{
			do
			{
				if (opr3b_logMessage(0x195, actor->name, unknown45d140(), 0, HEntity(), HEntity(), &position, 0))
					opr3b_msgConsole->unknown8758d0(true);
				opr3b_logMsgs->scrollToEnd();
			} while (0);
			if (opr3b_debugLevel >= 0)
			{
				do
				{
					if (opr3b_logMessage(0x2d3, actor->name, unknown45d140(), 0, HEntity(), HEntity(), &position, 1))
						opr3b_msgConsole->unknown8758d0(false);
					opr3b_logMsgs2->scrollToEnd();
				} while (0);
			}
			if (terrain->base->unknown4c && rng.chance(50) && unknown670360(12, 1) >= 3)
				world->unknown465840(position, world->getEntity_45d250());
		}
		return true;
	}
	else
		return false;
}

int Cell::unknown670360(int type, int amount)
{
	CellEffect *effect = getEffect(type);
	if (effect)
	{
		effect->value += amount;
		return effect->value;
	}
	else
	{
		effects.push_back(new CellEffect(opr3b_effectRecords[type], amount));
		return amount;
	}
}

bool Cell::unknown670400()
{
	if (!unknown45db90() || entity.isValid())
		return false;
	if (getEffect(6) || getEffect(7))
		return false;
	if (unknown45dc70())
		return true;
	Point p = position;
	if (--p.x >= 0 && cells(p)->entity.isValid() && (terrain->passable != 2 || cells(p)->entity->getGroup()->unknown9b4350() != 4))
		return false;
	p = position;
	if (++p.x < cells.getWidth() && cells(p)->entity.isValid() && (terrain->passable != 2 || cells(p)->entity->getGroup()->unknown9b4350() != 4))
		return false;
	p = position;
	if (--p.y >= 0 && cells(p)->entity.isValid() && (terrain->passable != 2 || cells(p)->entity->getGroup()->unknown9b4350() != 4))
		return false;
	p = position;
	if (++p.y < cells.getHeight() && cells(p)->entity.isValid() && (terrain->passable != 2 || cells(p)->entity->getGroup()->unknown9b4350() != 4))
		return false;
	return true;
}

void Cell::unknown670690()
{
	unknown04 = terrain->unknownD4;
	unknown08 = terrain->unknownD8;
	unknown3a = false;
	open = false;
}

void Cell::unknown6706d0(bool flag)
{
	if (!flag)
	{
		vector<Cell *> v;
		if (unknown670400())
			v.push_back(cells(position));
		else
			return;
		Point p = position;
		p.x--;
		while (p.x >= 0)
		{
			if (cells(p)->unknown45dbb0())
			{
				if (cells(p)->unknown670400())
					v.push_back(cells(p));
				else
					return;
				p.x--;
			}
			else
				break;
		}
		p = position;
		p.x++;
		while (p.x < cells.getWidth())
		{
			if (cells(p)->unknown45dbb0())
			{
				if (cells(p)->unknown670400())
					v.push_back(cells(p));
				else
					return;
				p.x++;
			}
			else
				break;
		}
		p = position;
		p.y--;
		while (p.y >= 0)
		{
			if (cells(p)->unknown45dbb0())
			{
				if (cells(p)->unknown670400())
					v.push_back(cells(p));
				else
					return;
				p.y--;
			}
			else
				break;
		}
		p = position;
		p.y++;
		while (p.y < cells.getHeight())
		{
			if (cells(p)->unknown45dbb0())
			{
				if (cells(p)->unknown670400())
					v.push_back(cells(p));
				else
					return;
				p.y++;
			}
			else
				break;
		}
		for (unsigned int i = 0; i < v.size(); i++)
		{
			v[i]->unknown6706d0(true);
			world->addPoint6a8(v[i]->position);
			soundMgr.unknown454500(v[i]->position);
			if (terrain->sound3)
				opr3b_pointsD2c454.push_back(v[i]->position);
		}
		for (unsigned int j = 0; j < v.size(); j++)
		{
			if (v[j]->getItem().isValid())
			{
				vector<Point> visited(1, v[j]->position);
				world->unknown71ec60(v[j]->position, visited);
			}
		}
	}
	unknown670690();
}
