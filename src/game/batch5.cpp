// EntityAI methods and friends matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; all type/member names are placeholders.
#include <string>
#include <vector>
using namespace std;

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
	Point();
	Point(int v);	// 0x409990
	Point(int x_, int y_);
	void set(int x_, int y_);	// 0x40a010
	Point &operator=(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
};
string pointToString(const Point &p);	// NOTE: placeholder name (0x40a4a0)

struct Rect4	// NOTE: placeholder name
{
	Rect4(int a, int b, int c, int d);	// 0x456940
	int v[4];
};

struct Area	// NOTE: placeholder name
{
	Area();	// 0x40b100
	void set(const Rect4 &r);	// NOTE: placeholder name (0x40b3a0)
	void randomPoint(Point *out);	// NOTE: placeholder name (0x40be30)
	Point min;
	Point max;
};

struct Group	// NOTE: placeholder name
{
	int getFoo();	// NOTE: placeholder name (0x9b8f00)
};

class HGroup	// NOTE: placeholder name
{
	int ID;
public:
	HGroup();
	Group *operator->() const;	// 0x9b7250
};

class Entity;

class HEntity	// NOTE: placeholder layout
{
	int ID;
public:
	HEntity();
	int getID() const;	// 0x9fcd80 (really returns a pointer; see addEarlyExiter)
	bool isValid() const;
	bool operator!=(HEntity other) const;	// 0x9b6510
	Entity *operator->() const;	// 0x9b6570
};

// NOTE: the exe folds this identity accessor (0x9c0790) with the protobuf one, so it needs a name from that set
namespace Protobuf
{
	class Cogmind	// NOTE: placeholder, stands in for the exit list
	{
	public:
		bool isEmpty();	// NOTE: placeholder name (0x9b86e0)
		unsigned int count();	// NOTE: placeholder name (0x9b9260)
		HEntity *&at(unsigned int i);	// NOTE: placeholder name (0x9b81f0)
	};
}
namespace google { namespace protobuf { namespace internal
{
	template <class T> class ExplicitlyConstructed
	{
	public:
		T *get_mutable();
	};
}}}
typedef google::protobuf::internal::ExplicitlyConstructed<Protobuf::Cogmind> ExitHolder;	// NOTE: placeholder name

struct EntityRecord	// NOTE: placeholder
{
	int unknown00;
	string name;
	char pad[0x28 - 4 - sizeof(string)];
	int index;
	char pad2c[0x78 - 0x2c];
	int ascii;	// NOTE: placeholder name
	char pad7c[0x9c - 0x7c];
	int type;	// NOTE: placeholder name
};

class Entity
{
public:
	int unknown00;
	HEntity self;
	EntityRecord *record;
	string name;	// NOTE: placeholder name
	char pad28[0x30 - 0x28];
	vector<Point> positions;	// NOTE: placeholder name
	int getFoo();	// NOTE: placeholder name (0x457820)
	const string &getNameAt0c();	// NOTE: placeholder name (0x416f40: returns this+0xc; not Entity::getName 0x45a280)
	bool isPlayer();	// NOTE: placeholder name (0x5c7600)
	int unknown5cb220();	// NOTE: placeholder name
	int getAsciiDefault();	// NOTE: placeholder name (0x5c79d0)
	int getAscii(const Point &p);
	HGroup getGroup();	// 0x45a3f0
	const Point &getPosition();	// 0x45a4a0
	ExitHolder *getExitHolder();	// NOTE: placeholder name (0x45ad90)
};

struct LevelAccess	// NOTE: placeholder name
{
	char pad[0x20];
	vector<int> a;
	vector<int> b;
	vector<string> c;
	vector<vector<int> > d;
};

class Cell
{
public:
	HEntity getEntity();
	bool isPassableFor(HEntity e);
	bool unknown66b1c0(int a, bool b);	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);
	void getBounds(const Point &p, int radius, Area *out);	// NOTE: placeholder name (0x9b4430)
	int getWidth();
	int getHeight();	// 0x9b8f00
};

class World	// NOTE: placeholder name
{
public:
	LevelAccess *getZone(const Point &p);	// 0x462e30
	int unknown463e50();	// NOTE: placeholder name
	bool unknown7168e0(const Point &a, const Point &b, Entity *e, void *out);	// NOTE: placeholder name
};

struct MapInfo { int pad; int type; };	// NOTE: placeholder
struct MapInfoHandle { MapInfo *operator->(); };	// NOTE: placeholder, 0x9b7910

extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)
extern World *world;	// NOTE: placeholder name (0xcefc4c)
extern int patrolRadius[];	// NOTE: placeholder name (0xbba4f8)
extern int terminalRadius;	// NOTE: placeholder name (0xbba394)
extern int suppressPatrolError;	// NOTE: placeholder name (0xcefaf4)
extern bool asciiEnabled;	// NOTE: placeholder name (0xd28d30)
extern bool deadAsciiEnabled;	// NOTE: placeholder name (0xcf4a00)
extern int deadAscii;	// NOTE: placeholder name (0xce9ff8)
extern MapInfoHandle mapInfo;	// NOTE: placeholder name (0xd1e888)

class EntityAI
{
public:
	void setOperatorTerminal(const Point &p);
	void addEarlyExiter(const Point &p);
	bool setPatrolRandom(Point p);

	HEntity entity;
	int state;
	char pad08[8];
	Point goal;
	char pad18[0x6c - 0x18];
	vector<Point> path;
	char pad7c[4];
	Area area;
};

void EntityAI::setOperatorTerminal(const Point &p)
{
	if (!cells(p)->unknown66b1c0(0,false))
	{
		logError("EntityAI::setOperatorTerminal()",pointToString(p) + " is not an interactive terminal");
		return;
	}
	path.clear();
	path.push_back(p);
	path.push_back(Point(-1));
	cells.getBounds(p,terminalRadius,&area);
}

void EntityAI::addEarlyExiter(const Point &p)
{
	LevelAccess *access = world->getZone(p);
	if (access)
	{
		access->a.push_back(entity->getFoo());
		access->b.push_back(entity->getGroup()->getFoo());
		access->c.push_back(entity->getNameAt0c());
		access->d.push_back(vector<int>());
		if (entity->getExitHolder() && !entity->getExitHolder()->get_mutable()->isEmpty())
		{
			unsigned int i;
			for (i = 0; i < entity->getExitHolder()->get_mutable()->count(); i++)
			{
				access->d.back().push_back(*(const int *)entity->getExitHolder()->get_mutable()->at(i)->getID());
			}
		}
	}
	else
	{
		logError("EntityAI::addEarlyExiter()","no LevelAccess at " + pointToString(p));
	}
}

bool EntityAI::setPatrolRandom(Point p)
{
	if (!cells(p)->isPassableFor(entity) || (cells(p)->getEntity().isValid() && cells(p)->getEntity() != entity))
	{
		p = entity->getPosition();
	}
	Area bounds;
	if (mapInfo->type == 0x21)
	{
		{
			Rect4 area(0,125,200,100);
			bounds.set(area);
		}
	}
	else if (patrolRadius[entity->record->index] == 0)
	{
		bounds.min.set(0,0);
		bounds.max.set(((HEntity *)&cells)->getID() - 1,cells.getHeight() - 1);
	}
	else
	{
		cells.getBounds(p,patrolRadius[entity->record->index],&bounds);
	}
	int tries = 0;
	{
		vector<Point> scratch;
		do
		{
			bounds.randomPoint(&goal);
			tries++;
			if (tries >= 100)
			{
				if (!suppressPatrolError)
				{
					logError("EntityAI::setPatrolRandom()","Unable to path to a valid goal for AI_MOVE_PATROL (" + entity->record->name + ")");
				}
				state = 1;
				path.push_back(entity->getPosition());
				return false;
			}
		}
		while (!(cells(goal)->isPassableFor(entity) && world->unknown7168e0(p,goal,entity.operator->(),&scratch)));
		path.push_back(p);
		path.push_back(goal);
		return true;
	}
}

int Entity::getAscii(const Point &p)
{
	if (asciiEnabled)
	{
		if (record->type == 1)
		{
			if (deadAsciiEnabled && isPlayer())
				return deadAscii;
			return record->ascii;
		}
		else
		{
			unsigned int i;
			for (i = 0; i < positions.size(); i++)
			{
				if (positions[i] == p)
					return record->ascii + i;
			}
			if (true)
			{
				logError("Entity::getAscii()","Entity (" + getNameAt0c() + ") not found at specificPos " + pointToString(p));
				return '*';
			}
		}
	}
	else
	{
		return getAsciiDefault();
	}
}

struct ItemEffect	// NOTE: placeholder name
{
	ItemEffect(int type_, int state_) throw();	// 0x46ca20
	int type;
	int state;
};

struct ItemRecord	// NOTE: placeholder name
{
	int unknown00;
	int unknown04;
	string name;
	char pad24[0xec - 0x24];
	int mode;	// NOTE: placeholder name
	int unknownf0;	// NOTE: placeholder name
};

class Item
{
public:
	void setOverload(bool overload);
	ItemEffect *getEffect(int type);	// NOTE: placeholder name (0x457b70)
	void addEffect(ItemEffect *effect);	// NOTE: placeholder name (0x4585a0)

	int unknown00;
	int ID;
	ItemRecord *record;
	int unknown0c;
	HEntity owner;	// NOTE: placeholder name
	char pad14[0x40 - 0x14];
	bool overloaded;	// NOTE: placeholder name
	int count;	// NOTE: placeholder name
	vector<ItemEffect *> effects;	// NOTE: placeholder name
};

struct SoundSink	// NOTE: placeholder name
{
	void unknown4aee10(int id);	// NOTE: placeholder name
};
struct Panel	// NOTE: placeholder name
{
	void unknown49abf0();	// NOTE: placeholder name
};

string intToString(int value);	// NOTE: placeholder name

extern vector<int> effectTypes;	// NOTE: placeholder name (0xd2f0f8)
extern bool overloadModeFlag[];	// NOTE: placeholder name (0xba0968)
extern int overloadModeMax[];	// NOTE: placeholder name (0xba0970)
extern SoundSink *soundSink;	// NOTE: placeholder name (0xcec11c)
extern Panel *panel;	// NOTE: placeholder name (0xcec054)

void Item::setOverload(bool overload)
{
	overloaded = overload;
	if (overloaded)
	{
		if (record->mode != 0)
		{
			ItemEffect *effect = getEffect(0x6b);
			int state = effect ? effect->state : 0;
			switch (state)
			{
			case 0:
				if (count != 0)
				{
					logError("Item::setOverload()",record->name + " already has a count value before mode even started");
				}
				addEffect(new ItemEffect(effectTypes[0x6b],1));
				count = 1;
				break;
			case 1:
			case 2:
				logError("Item::setOverload()","unexpected propulsionModeStateType: " + intToString(state));
				break;
			case 3:
				int limit;
				limit = overloadModeFlag[record->mode] ? (owner.isValid() ? owner->unknown5cb220() : overloadModeMax[record->mode]) + 1 : overloadModeMax[record->mode] + 1;
				if (count == limit)
				{
					effect->state = 2;
					count = 0;
				}
				else
				{
					effect->state = 1;
				}
				break;
			}
			soundSink->unknown4aee10(ID);
		}
		else
		{
			if (owner.isValid() && owner->isPlayer() && world->unknown463e50())
			{
				switch (record->unknownf0)
				{
				case 0xd3:
					panel->unknown49abf0();
					break;
				}
			}
		}
	}
}
