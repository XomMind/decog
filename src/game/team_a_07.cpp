// team_a_07: small helpers and accessors in 0x421900-0x458900 (crash-handler install, blink timers, terrain
// flag lookups, serialization wrappers, simple ctors/dtors).
// NOTE: class, member and function names are placeholders; layouts are partial.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <windows.h>
using namespace std;

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

LONG WINAPI crashHandler_421930(EXCEPTION_POINTERS *info);	// NOTE: placeholder name
void installCrashHandler_421920()	// NOTE: placeholder name
{
	SetUnhandledExceptionFilter(crashHandler_421930);
}

class TickStamp_427300	// NOTE: placeholder name
{
public:
	char pad[0x74];
	unsigned int unknown74;
	void stamp();
};

void TickStamp_427300::stamp()
{
	unknown74 = tickCount;
}

struct Pair_432630	// NOTE: placeholder name
{
	int first;
	int second;
};

class Virtual_432630	// NOTE: placeholder name
{
public:
	virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
	virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
	virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
	virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
	virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
	virtual void v50(); virtual void v54(); virtual void v58();
	virtual Pair_432630 unknown5c();
	int firstOf5c();
};

int Virtual_432630::firstOf5c()
{
	return unknown5c().first;
}

struct Bytes4_4326b0	// NOTE: placeholder name
{
	char a;
	char b;
	char c;
	char d;
	Bytes4_4326b0();
};

Bytes4_4326b0::Bytes4_4326b0()
{
	a = 0;
	b = 0;
	c = 0;
	d = 0;
}

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color) throw();	// 0x411e30
	XColor &operator=(XColor color);	// 0x411f10
	bool operator!=(XColor color);	// 0x411f90
};

extern XColor color_d29804;	// NOTE: placeholder name (0xd29804)
extern XColor *opr5f_COLOR_BLACK;	// NOTE: placeholder name (0xcfe674)
extern bool colorIsSet_cefb3c;	// NOTE: placeholder name (0xcefb3c)
void setColor_4347a0(XColor color)	// NOTE: placeholder name
{
	color_d29804 = color;
	colorIsSet_cefb3c = color_d29804 != *opr5f_COLOR_BLACK;
}

extern int tableBase_ba7ab4[];	// NOTE: placeholder name (0xba7ab4)
int tableEntry_434a80(int index, int n)	// NOTE: placeholder name
{
	return tableBase_ba7ab4[index] + (n - 1) * 1500;
}

int triple_434aa0(int n)	// NOTE: placeholder name
{
	return (n - 1) * 3 + 1;
}

int triple_434ac0(int n)	// NOTE: placeholder name
{
	return n * 3 + 1;
}

int halfDiff_437190(int a, int b)	// NOTE: placeholder name
{
	return (b - a) / 2;
}

bool blink_437320(unsigned int period)	// NOTE: placeholder name
{
	return (tickCount / period) % 2;
}

bool blinkSince_437340(unsigned int period, unsigned int start)	// NOTE: placeholder name
{
	return ((tickCount - start) / period) % 2;
}

struct Point
{
	int	x;
	int	y;
};

bool opR1d_437360(int x1, int y1, int x2, int y2);	// NOTE: placeholder name
int opR1d_437440(int x1, int y1, int x2, int y2);	// NOTE: placeholder name
bool pointsFn_4373c0(const Point &a, const Point &b)	// NOTE: placeholder name
{
	return opR1d_437360(a.x,a.y,b.x,b.y);
}

int pointsFn_4374c0(const Point &a, const Point &b)	// NOTE: placeholder name
{
	return opR1d_437440(a.x,a.y,b.x,b.y);
}

template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
template <class T> void OpQ5_deleteObjects(vector<T*> &v) throw();	// NOTE: placeholder name
template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v);	// NOTE: placeholder name
template <class T> void OpQ5_clearObjects(vector<T*> &v) throw();	// NOTE: placeholder name
template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name
template <class T> void writeBinary(ostream &stream, T *value);	// NOTE: placeholder name
void OpT8a_readInts(istream &in, vector<int> &v);	// NOTE: placeholder name
struct OpQ5_T9cf200;
struct OpQ5_T9d8e70;
struct OpQ5_T9d02a0;
struct OpQ5_T9e2c40;

struct ObjList_437560	// NOTE: placeholder name
{
	vector<OpQ5_T9cf200 *> objects;
	void read(istream &stream);
};

void ObjList_437560::read(istream &stream)
{
	OpQ5_readObjects(stream,objects,0);
}

class Unknown_438ab0_4489f0	// NOTE: placeholder name (shared with team_d_04.cpp; destructor not defined here)
{
public:
	bool flag;
	vector<unsigned int> values;
	Unknown_438ab0_4489f0();
	~Unknown_438ab0_4489f0();
};

Unknown_438ab0_4489f0::Unknown_438ab0_4489f0()
	: flag(false)
{
}

class Config445590	// NOTE: placeholder name
{
public:
	int boolToInt(bool value);
};

int Config445590::boolToInt(bool value)
{
	return value ? 1 : 0;
}

struct IntRecord_448190	// NOTE: placeholder name
{
	int value;
	vector<int> values;
	void read(istream &stream);
};

void IntRecord_448190::read(istream &stream)
{
	readBinary(stream,&value);
	OpT8a_readInts(stream,values);
}

struct Tally_4481c0	// NOTE: placeholder name
{
	int total;
	vector<int> values;
	void add(int value);
};

void Tally_4481c0::add(int value)
{
	values.push_back(value);
	total += value;
}

template <class T> class OpX5_Array2D	// NOTE: placeholder name (defined in op_x5.cpp)
{
public:
	T *atPoint(Point &p);
};
extern OpX5_Array2D<int> terrainGrid_cf447c;	// NOTE: placeholder name (0xcf447c)
struct TerrainInfo_bb8380	// NOTE: placeholder layout (0xbb8380, stride 1 byte per index?)
{
	char a;
};
extern char terrainFlagsA_bb8380[];	// NOTE: placeholder name
extern char terrainFlagsB_bb8388[];	// NOTE: placeholder name
extern char terrainFlagsC_bb8390[];	// NOTE: placeholder name
char terrainFlagA_448b60(Point &p)	// NOTE: placeholder name
{
	return terrainFlagsA_bb8380[*terrainGrid_cf447c.atPoint(p)];
}

char terrainFlagB_448b80(Point &p)	// NOTE: placeholder name
{
	return terrainFlagsB_bb8388[*terrainGrid_cf447c.atPoint(p)];
}

char terrainFlagC_448ba0(Point &p)	// NOTE: placeholder name
{
	return terrainFlagsC_bb8390[*terrainGrid_cf447c.atPoint(p)];
}

class Tunnel_448bc0	// NOTE: placeholder name
{
public:
	char pad[0x10];
	int unknown10;
	vector<int> unknown14;
	char pad24[0x44 - 0x24];
	vector<int> unknown44;
	bool isDone();
	void addValue(int value);
};

bool Tunnel_448bc0::isDone()
{
	return unknown10 == 1 && unknown14.empty();
}

void Tunnel_448bc0::addValue(int value)
{
	unknown44.push_back(value);
}

extern int battleType_cefb60;	// NOTE: placeholder name (0xcefb60)
class BattleState	// NOTE: placeholder name (vtable slot 1)
{
public:
	int getType_453c20();
};

int BattleState::getType_453c20()
{
	return battleType_cefb60;
}

extern int explosionType_ce9fe8;	// NOTE: placeholder name (0xce9fe8)
class SExplosionExpand
{
public:
	int getType_455940();	// NOTE: placeholder name
};

int SExplosionExpand::getType_455940()
{
	return explosionType_ce9fe8;
}

class Queue_454d30	// NOTE: placeholder name
{
public:
	char pad[0x14];
	vector<int> items;
	int hasItems();
};

int Queue_454d30::hasItems()
{
	return !items.empty();
}

struct ObjRecord_456390	// NOTE: placeholder name
{
	vector<OpQ5_T9d02a0 *> objects;
	int value;
	void write(ostream &stream);
};

void ObjRecord_456390::write(ostream &stream)
{
	OpQ5_writeObjects(stream,objects);
	writeBinary(stream,&value);
}

struct ObjList_4563c0	// NOTE: placeholder name
{
	vector<OpQ5_T9e2c40 *> objects;
	~ObjList_4563c0();
};

ObjList_4563c0::~ObjList_4563c0()
{
	OpQ5_clearObjects(objects);
}

class Weapon_457490	// NOTE: placeholder name
{
public:
	char pad[0x50];
	int unknown50;
	char pad54[0x94 - 0x54];
	int unknown94;
	int unknown457490();
	int unknown4575d0(int divisor);
};

int Weapon_457490::unknown457490()
{
	return 70 - (unknown94 ? 5 : 3) * unknown50;
}

int Weapon_457490::unknown4575d0(int divisor)
{
	return unknown50 * (unknown94 ? 5 : 3) / (divisor ? divisor : 1);
}

struct Info_4578e0	// NOTE: placeholder name
{
	char pad[0x4c];
	int unknown4c;
};

class Item_4578e0	// NOTE: placeholder name
{
public:
	int pad0;
	int pad4;
	Info_4578e0 *info;
	bool unknown4578e0();
};

bool Item_4578e0::unknown4578e0()
{
	return info->unknown4c > 1;
}

class Named_4579d0	// NOTE: placeholder name
{
public:
	char pad[0x5c];
	string name;
	int hasName();
};

int Named_4579d0::hasName()
{
	return !name.empty();
}

class Unknown_4588d0_439630	// NOTE: placeholder name (shared with team_d_04.cpp)
{
public:
	vector<OpQ5_T9d8e70 *> objects;
	Unknown_4588d0_439630();
	~Unknown_4588d0_439630();
};

Unknown_4588d0_439630::Unknown_4588d0_439630()
{
}

Unknown_4588d0_439630::~Unknown_4588d0_439630()
{
	OpQ5_deleteObjects(objects);
}
