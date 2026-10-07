// team_a_08: small helpers and accessors in 0x459600-0x4fda00 (unit/weapon accessors, Map/TurnClock helpers,
// game-data location queries, button hover handlers).
// NOTE: class, member and function names are placeholders unless noted; layouts are partial.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
using namespace std;

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

struct Point
{
	int	x;
	int	y;
	Point(int x_, int y_);						// 0x46ca20
	Point(const Point &p);						// 0x46ca50
};

class HEntity
{
	int	ID;
public:
	bool operator==(HEntity e) const;			// 0x9b78e0
};

struct EntityData4563c0;
struct OpQ5_T9e2c40;
template <class T> void OpQ5_clearObjects(vector<T*> &v) throw();	// NOTE: placeholder name
template <class T> void writeBinary(ostream &stream, T *value);	// NOTE: placeholder name
int OpU8a_indexOfEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d3110)
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name

class Unit_459640	// NOTE: placeholder name
{
public:
	char pad[0x10];
	int unknown10;
	char pad14[0x56 - 0x14];
	bool unknown56;
	void reset();
};

void Unit_459640::reset()
{
	if (unknown56)
	{
		unknown56 = false;
		unknown10 = -1;
	}
}

class Weapon_4598b0	// NOTE: placeholder name
{
public:
	char pad[0x68];
	int unknown68;
	int unknown4598b0();
	int unknown4598d0();
};

int Weapon_4598b0::unknown4598b0()
{
	return 50 - unknown68 * 6;
}

int Weapon_4598b0::unknown4598d0()
{
	return 60 - unknown68 * 6;
}

class Record_45a040	// NOTE: placeholder name
{
public:
	int unknown0;
	int unknown4;
	void writeBase_9cfa90(ostream &stream);	// NOTE: placeholder name
	void write(ostream &stream);
};

void Record_45a040::write(ostream &stream)
{
	writeBase_9cfa90(stream);
	writeBinary(stream,&unknown4);
}

class Signed_45e0e0	// NOTE: placeholder name
{
public:
	char pad[0x6c];
	int unknown6c;
	bool makePositive();
};

bool Signed_45e0e0::makePositive()
{
	if (unknown6c < 0)
	{
		unknown6c = -unknown6c;
		return true;
	}
	return false;
}

class Effect_45e110	// NOTE: placeholder name
{
public:
	void unknown66dae0(int a, int b, int c, bool d, int e, bool f, int g, int h);	// NOTE: placeholder name
	void trigger(bool a, bool b, int c);
};

void Effect_45e110::trigger(bool a, bool b, int c)
{
	unknown66dae0(0,9,1,a,0,b,c,0);
}

class EntityList_45e1a0	// NOTE: placeholder name
{
public:
	char pad[0xc];
	vector<HEntity> entities;
	int indexOf(HEntity e);
};

int EntityList_45e1a0::indexOf(HEntity e)
{
	return OpU8a_indexOfEntity(entities,e);
}

struct Owned_45e560	// NOTE: placeholder name
{
	char pad[0xc];
	int *data;
	~Owned_45e560();
};

Owned_45e560::~Owned_45e560()
{
	delete data;
}

class TurnClock	// NOTE: placeholder name
{
public:
	int pad0;
	int pad4;
	int unknown8;
	int *unknownC;
	int unknown45e590();						// NOTE: placeholder name
};

int TurnClock::unknown45e590()
{
	if (unknown8 == 0)
		return *unknownC;
	else
		return 0;
}

struct TeamB_673b00 { int pad0; int pad4; int expireTurn; void setExpire673b00(); };	// NOTE: placeholder name/layout (team_b_01.cpp)
struct Counter_45ea50	// NOTE: placeholder name
{
	int unknown0;
	int count;
	Counter_45ea50(int value);
	void increment();
};

Counter_45ea50::Counter_45ea50(int value)
{
	unknown0 = value;
	count = 1;
	((TeamB_673b00 *)this)->setExpire673b00();
}

void Counter_45ea50::increment()
{
	count++;
	((TeamB_673b00 *)this)->setExpire673b00();
}

struct Shot_4606d0	// NOTE: placeholder name
{
	Point pos;
	int unknown8;
	int unknownC;
	Shot_4606d0(Point p, int a, int b);
};

Shot_4606d0::Shot_4606d0(Point p, int a, int b)
	: pos(p)
{
	unknown8 = a;
	unknownC = b;
}

struct ShotList_460700	// NOTE: placeholder name
{
	int pad0;
	int pad4;
	vector<OpQ5_T9e2c40 *> objects;
	void clear();
};

void ShotList_460700::clear()
{
	OpQ5_clearObjects(objects);
}

class Map	// NOTE: placeholder name (see src/pathing/gamedecl.h)
{
public:
	char pad[0x8b4];
	vector<int> unknown8b4;
	char pad8c4[0xb70 - 0x8c4];
	vector<EntityData4563c0 *> unknownB70;
	int unknown4658e0();
	void unknown465910(EntityData4563c0 *data);
	int getTurn();								// 0x464270
	void unknown4659c0(int amount);				// NOTE: placeholder name
	void unknown465990(int turn);
};

int Map::unknown4658e0()
{
	return !unknown8b4.empty();
}

void Map::unknown465910(EntityData4563c0 *data)
{
	unknownB70.push_back(data);
}

void Map::unknown465990(int turn)
{
	int delta = turn - getTurn();
	unknown4659c0(delta);
}

class gzifstream
{
public:
	void close();
};
extern gzifstream *opR1f_cefc20;	// NOTE: placeholder name
extern gzifstream *opR1f_cefc24;	// NOTE: placeholder name
extern gzifstream *opR1f_cefc28;	// NOTE: placeholder name
void closeDataFiles_466440()	// NOTE: placeholder name
{
	opR1f_cefc20->close();
	opR1f_cefc24->close();
	opR1f_cefc28->close();
}

extern vector<string> opR1f_d33d28;	// NOTE: placeholder name
extern vector<string> ops7_d33d38;	// NOTE: placeholder name
extern vector<string> vec_d33d48;	// NOTE: placeholder name
extern int count_cef9dc;	// NOTE: placeholder name (0xcef9dc)
extern int ops7_cebd58;	// NOTE: placeholder name
extern int count_cebd60;	// NOTE: placeholder name (0xcebd60)
void resetCount_466840()	// NOTE: placeholder name
{
	count_cef9dc = opR1f_d33d28.size();
}

void resetCount_466930()	// NOTE: placeholder name
{
	ops7_cebd58 = ops7_d33d38.size();
}

void resetCount_466a00()	// NOTE: placeholder name
{
	count_cebd60 = vec_d33d48.size();
}

struct MapRecord;
extern vector<MapRecord *> records_cf09a8;	// NOTE: placeholder name (0xcf09a8)
class Progress_46c930	// NOTE: placeholder name
{
public:
	char pad[0x188];
	vector<MapRecord *> unknown188;
	unsigned int percent();
	int countInCategory(int category);
};

unsigned int Progress_46c930::percent()
{
	return unknown188.size() * 100 / records_cf09a8.size();
}

int Progress_46c930::countInCategory(int category)	// NOTE: placeholder name; MapRecord layout unknown, so fields are read by offset
{
	int count = 0;
	for (unsigned int i = 0; i < unknown188.size(); i++)
	{
		if (((int *)records_cf09a8[*(int *)unknown188[i]])[0x40 / 4] == category)
			count++;
	}
	return count;
}

class Location_46ecb0	// NOTE: placeholder name
{
public:
	int unknown0;
	int unknown4;
	int unknown8;
	bool inRange();
	Point unknown46ee50();
};

bool Location_46ecb0::inRange()
{
	return OpT8b_Fn9daf80(1,unknown4,6);
}

Point Location_46ecb0::unknown46ee50()
{
	return Point(-unknown8,unknown4);
}

class Push_46ed20
{
public:
	int operate();
};

class HLocation_9b7910	// NOTE: placeholder name
{
public:
	int ID;
	Location_46ecb0 *operator->() const;	// 0x9b7910
};

extern int locationTypes_b90000[];	// NOTE: placeholder name (0xb90000)
class GameData_46f4b0	// NOTE: placeholder name
{
public:
	char pad[0x28];
	HLocation_9b7910 location;
	vector<MapRecord *> unknown2c;
	bool unknown46f4b0(int type);
	int unknown46f4e0();
	Point unknown46f500();
	int unknown46f530();
};

bool GameData_46f4b0::unknown46f4b0(int type)
{
	return locationTypes_b90000[location->unknown4] == type;
}

int GameData_46f4b0::unknown46f4e0()
{
	return ((Push_46ed20 *)location.operator->())->operate();
}

Point GameData_46f4b0::unknown46f500()
{
	return location->unknown46ee50();
}

int GameData_46f4b0::unknown46f530()
{
	return unknown2c.size() - 1;
}

class OpR1h_StatSet
{
public:
	int get472440(unsigned int id);	// NOTE: placeholder name (0x472440)
};

struct OpR6_KA_8_0
{
	OpR1h_StatSet *m0;
	int m4;
	OpR6_KA_8_0 &operator=(const OpR6_KA_8_0 &o);
};

class StatTracker_472c90	// NOTE: placeholder name
{
public:
	int pad0;
	vector<OpR6_KA_8_0> sets;
	int unknown472c90(unsigned int id);
};

int StatTracker_472c90::unknown472c90(unsigned int id)
{
	return sets.back().m0->get472440(id);
}

class Queue_48e560	// NOTE: placeholder name
{
public:
	char pad[0x90];
	vector<int> items;
	int hasItems();
};

int Queue_48e560::hasItems()
{
	return !items.empty();
}

class Flags_48f8d0	// NOTE: placeholder name
{
public:
	char pad[0x84];
	int values[8];
	bool isSet(int index);
};

bool Flags_48f8d0::isSet(int index)
{
	return values[index] == 1;
}

class Console
{
public:
	void animate(string name);	// 0x48c3f0
	virtual ~Console();
};

class CIntelLine : public Console
{
public:
	virtual bool mouseEnter();
};

bool CIntelLine::mouseEnter()
{
	animate("A_ButtonHover_Begin_ALLY_HOV_OK");
	return true;
}

class CGamoverButton : public Console
{
public:
	virtual bool mouseEnter();
};

bool CGamoverButton::mouseEnter()
{
	animate("A_ButtonHover_Begin_EVOL_HOV_OK");
	return true;
}

class CInfoButton : public Console
{
public:
	virtual bool mouseEnter();
};

bool CInfoButton::mouseEnter()
{
	animate("A_ButtonHover_Begin_SHEL_HOV_OK");
	return true;
}

int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name
void playSound_4fd9c0()	// NOTE: placeholder name
{
	opR1d_4541b0(0x21,0,0);
}
