// team_a_02: Map (world object, global 0xcefc4c) header-inline accessors at 0x4642b0-0x464a60.
// Provides the code for the rows in config/mapping.d/cc_r1_02.csv (whose source file is missing).
// NOTE: class layout is partial; padding members and all member names here are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int	x;
	int	y;

	Point(const Point &p);						// 0x46ca50
};

class HEntity
{
	int	ID;
};

class HProp
{
public:
	int ID;
	struct Prop *operator->() const;			// 0x9b64f0
};

struct Elem_9e3c60	// NOTE: placeholder name
{
	char pad[0x10];
	Elem_9e3c60();
	Elem_9e3c60(const Elem_9e3c60 &e);
};

struct MapRecord	// NOTE: placeholder layout
{
	int		unknown0;
	HEntity	unknown4;
	int		unknown8;
};

template <class T> class OpX5_Array2D	// NOTE: placeholder name (defined in op_x5.cpp)
{
public:
	T *atPoint(Point &p);
};

bool OpU8a_removeEntity(vector<HEntity> &v, HEntity e);		// 0x9d2f00
bool OpU8a_removePoint(vector<Point> &v, Point p);			// 0x9d3060
bool OpU8a_containsEntity(vector<HEntity> &v, HEntity e);	// 0x9d31e0
bool OpV4c_Fn9d3020(vector<Point> &list, Point p);			// 0x9d3020

class BS
{
public:
	void opw3_unknown7243c0(int x, int y, bool flag);	// NOTE: placeholder name
	void opw3_unknown724420(int x, int y);				// NOTE: placeholder name
};

class OpX5_Holder
{
public:
	void eraseSortedEntity(vector<HEntity> &v, HEntity e);
};

class OpU5_Map	// NOTE: placeholder name
{
public:
	void unknown9e29b0(vector<HProp> *list, HProp prop);	// NOTE: placeholder name
};

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

class Map	// NOTE: placeholder name (see src/pathing/gamedecl.h)
{
public:
	int unknown4642b0();
	int unknown4642d0();
	int unknown4642f0();
	bool unknown464310();
	bool unknown464330();
	bool unknown464350();
	bool unknown464370();
	bool unknown464390();
	char *unknown4643b0();
	char *unknown4643d0();
	char *unknown4643f0();
	int unknown464410(Point &p);
	bool unknown464450();
	int unknown464490();
	char *unknown4644b0();
	unsigned int unknown4644d0();
	vector<Elem_9e3c60> *unknown4644f0();
	char *unknown464510();
	char *unknown464530();
	bool unknown464550();
	char *unknown464570();
	char *unknown464590();
	char *unknown4645b0();
	int unknown4645d0();
	char *unknown4645f0();
	char *unknown464610();
	char *unknown464630();
	char *unknown464650();
	char *unknown464670();
	char *unknown464690();
	char *unknown4646b0();
	char *unknown4646d0();
	void unknown4646f0();
	void unknown464710(int value);
	void unknown464730(bool value);
	void unknown464750(int value);
	void unknown464780();
	void unknown4647a0(Point &p, bool flag);
	void unknown4647d0(Point &p);
	void unknown464800(HEntity e);
	void unknown464840(HProp prop);
	void unknown464870(HEntity e);
	void registerUnstableCell(const Point &p);
	void unknown4648d0(const Point &p);
	bool unknown464900();
	char *unknown464920();
	char *unknown464940();
	int unknown464960(vector<HEntity> &entities);
	void unknown464a00(int value);
	bool unknown464a20();
	void unknown464a60();

	int							pad0;
	unsigned int				unknown4;
	char						pad8[0x30 - 0x8];
	bool						unknown30;
	char						pad31[0xf4 - 0x31];
	vector<Point>				unknownF4;
	char						pad104[0x138 - 0x104];
	vector<Point>				unknown138;
	char						pad148[0x1b8 - 0x148];
	char						unknown1b8[0x10];
	char						unknown1c8[0x10];
	bool						unknown1d8;
	vector<MapRecord *>			unknown1dc;
	vector<int>					unknown1ec;
	int							unknown1fc;
	char						pad200[0x204 - 0x200];
	bool						unknown204;
	char						pad205[0x234 - 0x205];
	HProp						unknown234;
	char						pad238[0x240 - 0x238];
	int							unknown240;
	char						pad244[0x31c - 0x244];
	int							unknown31c;
	int							unknown320;
	int							unknown324;
	char						pad328[0x32c - 0x328];
	bool						unknown32c;
	bool						unknown32d;
	char						pad32e[0x4b0 - 0x32e];
	char						unknown4b0[0x10];
	char						unknown4c0[0x10];
	char						unknown4d0[0x10];
	char						pad4e0[0x594 - 0x4e0];
	char						unknown594[0x10];
	char						pad5a4[0x648 - 0x5a4];
	char						unknown648[0x10];
	int							unknown658;
	int							pad65c;
	bool						unknown660;
	int							unknown664;
	char						pad668[0x6ec - 0x668];
	vector<HEntity>				unknown6ec;
	vector<HEntity>				unknown6fc;
	char						pad70c[0x730 - 0x70c];
	vector<HProp>				unknown730;
	char						pad740[0x868 - 0x740];
	int							unknown868;
	char						pad86c[0x874 - 0x86c];
	vector<Elem_9e3c60>			unknown874;
	char						unknown884[0x10];
	char						unknown894[0x10];
	bool						unknown8a4;
	char						pad8a5[3];
	char						unknown8a8[4];
	char						unknown8ac[4];
	int							unknown8b0;
	char						unknown8b4[0x18];
	char						unknown8cc[0x38];
	char						unknown904[0x20];
	char						unknown924[0x20];
	char						unknown944[0x10];
	char						unknown954[0x18];
	char						unknown96c[0x10];
	char						unknown97c[0x10];
	char						pad98c[0xb05 - 0x98c];
	bool						unknownB05;
	bool						unknownB06;
	bool						unknownB07;
	char						padB08[0xb80 - 0xb08];
	OpX5_Array2D<int>			*unknownB80;
};

int Map::unknown4642b0() { return unknown31c; }
int Map::unknown4642d0() { return unknown320; }
int Map::unknown4642f0() { return unknown324; }
bool Map::unknown464310() { return unknown32c; }
bool Map::unknown464330() { return unknown32d; }
bool Map::unknown464350() { return unknownB05; }
bool Map::unknown464370() { return unknownB06; }
bool Map::unknown464390() { return unknownB07; }
char *Map::unknown4643b0() { return unknown4b0; }
char *Map::unknown4643d0() { return unknown4c0; }
char *Map::unknown4643f0() { return unknown4d0; }

int Map::unknown464410(Point &p)
{
	return unknownB80 ? *unknownB80->atPoint(p) : 0;
}

bool Map::unknown464450()
{
	return unknown234.operator->() && unknown240;
}

int Map::unknown464490() { return unknown868; }
char *Map::unknown4644b0() { return unknown594; }
unsigned int Map::unknown4644d0() { return unknown874.size(); }
vector<Elem_9e3c60> *Map::unknown4644f0() { return &unknown874; }
char *Map::unknown464510() { return unknown884; }
char *Map::unknown464530() { return unknown894; }
bool Map::unknown464550() { return unknown8a4; }
char *Map::unknown464570() { return unknown648; }
char *Map::unknown464590() { return unknown8a8; }
char *Map::unknown4645b0() { return unknown8ac; }
int Map::unknown4645d0() { return unknown8b0; }
char *Map::unknown4645f0() { return unknown8b4; }
char *Map::unknown464610() { return unknown8cc; }
char *Map::unknown464630() { return unknown904; }
char *Map::unknown464650() { return unknown924; }
char *Map::unknown464670() { return unknown944; }
char *Map::unknown464690() { return unknown954; }
char *Map::unknown4646b0() { return unknown96c; }
char *Map::unknown4646d0() { return unknown97c; }
void Map::unknown4646f0() { unknown4 = tickCount; }
void Map::unknown464710(int value) { unknown658 = value; }
void Map::unknown464730(bool value) { unknown660 = value; }
void Map::unknown464750(int value) { unknown664 += value; }
void Map::unknown464780() { unknown30 = false; }

void Map::unknown4647a0(Point &p, bool flag)
{
	((BS *)this)->opw3_unknown7243c0(p.x,p.y,flag);
}

void Map::unknown4647d0(Point &p)
{
	((BS *)this)->opw3_unknown724420(p.x,p.y);
}

void Map::unknown464800(HEntity e)
{
	OpU8a_removeEntity(unknown6ec,e);
	OpU8a_removeEntity(unknown6fc,e);
}

void Map::unknown464840(HProp prop)
{
	((OpU5_Map *)this)->unknown9e29b0(&unknown730,prop);
}

void Map::unknown464870(HEntity e)
{
	((OpX5_Holder *)this)->eraseSortedEntity(*(vector<HEntity> *)&unknown730,e);
}

void Map::registerUnstableCell(const Point &p)
{
	OpV4c_Fn9d3020(unknownF4,p);
}

void Map::unknown4648d0(const Point &p)
{
	OpU8a_removePoint(unknown138,p);
}

bool Map::unknown464900() { return unknown1d8; }
char *Map::unknown464920() { return unknown1b8; }
char *Map::unknown464940() { return unknown1c8; }

int Map::unknown464960(vector<HEntity> &entities)
{
	for (unsigned int i = 0; i < unknown1dc.size(); i++)
	{
		if (OpU8a_containsEntity(entities,unknown1dc[i]->unknown4))
			return unknown1dc[i]->unknown8;
	}
	return 0;
}

void Map::unknown464a00(int value)
{
	unknown1ec.push_back(value);
}

bool Map::unknown464a20()
{
	unknown1fc++;
	return unknown1fc == 1;
}

void Map::unknown464a60() { unknown204 = true; }
