// op_r3: functions in 0x650000-0x6fe000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	void set(int x_, int y_);	// NOTE: placeholder name (0x40a010)
	Point &operator=(const Point &p);	// 0x46ca50
};

class OpR3_ItemData	// NOTE: placeholder name
{
public:
	char pad00[0xf0];
	int type;	// NOTE: placeholder name
};

class Item
{
public:
	OpR3_ItemData *unknownGetData();	// NOTE: placeholder name (ICF'd trivial getter)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	bool isValid() const;
	Item *operator->() const throw();	// 0x9b65b0
};

bool opr3_anyNonZero(vector<int> &values);	// NOTE: placeholder name (0x9d7f70)
extern int opr3_tileTable[][4];	// NOTE: placeholder name (0xbe80a8)

float OpR3_pointAngle(Point &a, Point &b);	// NOTE: placeholder name (0x40a680)

void OpR3_f6513f0(Point &from, Point &to, vector<Point> &out)	// NOTE: placeholder name
{
	Point a;
	Point b;
	float angle = OpR3_pointAngle(from, to);
	if (angle >= 330.0 || angle <= 30.0)
	{
		a.set(-1, 0);
		b.set(1, 0);
	}
	else if (angle < 60.0)
	{
		a.set(-1, 0);
		b.set(0, 1);
	}
	else if (angle < 120.0)
	{
		a.set(0, -1);
		b.set(0, 1);
	}
	else if (angle < 150.0)
	{
		a.set(0, -1);
		b.set(-1, 0);
	}
	else if (angle < 210.0)
	{
		a.set(1, 0);
		b.set(-1, 0);
	}
	else if (angle < 240.0)
	{
		a.set(1, 0);
		b.set(0, -1);
	}
	else if (angle < 300.0)
	{
		a.set(0, 1);
		b.set(0, -1);
	}
	else
	{
		a.set(0, 1);
		b.set(1, 0);
	}
	out.push_back(a);
	out.push_back(b);
}

class OpR3_ItemList	// NOTE: placeholder name
{
public:
	bool unknown6591c0(int a);	// NOTE: placeholder name
	bool unknown659220(int a);	// NOTE: placeholder name

	char pad00[0x44];
	vector<HItem> items;
};

bool OpR3_ItemList::unknown6591c0(int a)
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i]->unknownGetData()->type != 0x77)
			return false;
	}
	return true;
}

bool OpR3_ItemList::unknown659220(int a)
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i]->unknownGetData()->type != 0x77 && items[i]->unknownGetData()->type != 0x72)
			return false;
	}
	return true;
}

class OpR3_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	void unknown464fd0(HItem item);	// NOTE: placeholder name
	void unknown4650c0(HItem item);	// NOTE: placeholder name
};
extern OpR3_Map *opr3_world;	// NOTE: placeholder name (0xcefc4c)

class OpR3_ItemPool	// NOTE: placeholder name
{
public:
	void unknown9d05e0(HItem item, bool flag);	// NOTE: placeholder name
};
extern OpR3_ItemPool opr3_pool;	// NOTE: placeholder name (0xd2a298)

class OpR3_ItemOwner	// NOTE: placeholder name
{
public:
	~OpR3_ItemOwner();	// 0x659f10

	char pad00[0x18];
	vector<HItem> items;
	char pad28[0xc];
	vector<unsigned int> ids;
};

OpR3_ItemOwner::~OpR3_ItemOwner()
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		opr3_world->unknown464fd0(items[i]);
		opr3_world->unknown4650c0(items[i]);
		opr3_pool.unknown9d05e0(items[i], true);
	}
}

class OpR3_Counter	// NOTE: placeholder name
{
public:
	void unknown658a30();	// NOTE: placeholder name
	void unknownSetState(int state);	// NOTE: placeholder name (0x458?)

	char pad00[0x58];
	int count;
};

void OpR3_Counter::unknown658a30()
{
	count--;
	if (count <= 0)
	{
		count = 0;
		unknownSetState(2);
	}
}

//==================================================================
// Prop
//==================================================================

struct OpR3_PropFlag	// NOTE: placeholder name
{
	char pad00[0x30];
	bool flag30;	// NOTE: placeholder name
};
extern vector<OpR3_PropFlag *> opr3_propFlags;	// NOTE: placeholder name (0xd39f1c)

struct OpR3_StatType	// NOTE: placeholder name
{
	int id;
};

struct OpR3_Stat	// NOTE: placeholder name
{
	OpR3_StatType *type;
	int count;

	OpR3_Stat(const OpR3_Stat &stat) throw();	// 0x46ca50 (folded with Point::Point(const Point &))
	OpR3_Stat(OpR3_StatType *type_, int count_) throw();	// 0x46ca20 (folded with Point::Point(int, int))
};

struct OpR3_StatList	// NOTE: placeholder name
{
	char pad00[0x3c];
	vector<OpR3_Stat *> stats;
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();	// 0x411d40
	XColor(const XColor &color) throw();	// 0x411e30
	XColor &operator=(XColor color);	// 0x411f10
	bool operator!=(XColor color);	// 0x411f90
	static XColor scale(XColor color, float value);	// NOTE: placeholder name (0x413740)
	bool nonzero();	// NOTE: placeholder name (0x412180)
	void setHSV(float h, float s, float v);	// NOTE: placeholder name (0x412500)
	void getHSV(float *h, float *s, float *v);	// NOTE: placeholder name (0x413520)
};

struct OpR3_XCell	// NOTE: placeholder name
{
	int getChar();	// NOTE: placeholder name (ICF'd trivial getter, 0x9b8f00)
	XColor *getFore();	// NOTE: placeholder name (0x416f40)
	XColor *getBack();	// NOTE: placeholder name (0x416f60)
};

class OpR3_ColorBag	// NOTE: placeholder name (weighted random colors)
{
public:
	OpR3_ColorBag();	// 0x9ba580
	~OpR3_ColorBag();	// 0x65e4a0
	void add(XColor color, int weight);	// NOTE: placeholder name (0x9ba5b0)
	XColor &pick();	// NOTE: placeholder name (0x9ba5f0)

	vector<XColor> colors;
	vector<int> weights;
	int total;
};

OpR3_ColorBag::~OpR3_ColorBag()
{
}

struct PropData	// NOTE: placeholder name
{
	char pad00[0x5c];
	bool unknown5C;	// NOTE: placeholder name
	char pad5d[0x60 - 0x5d];
	OpR3_StatList *unknown60;	// NOTE: placeholder name
	char pad64[4];
	int unknown68;	// NOTE: placeholder name
	char pad6c[4];
	int unknown70;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	char pad78[0xc4 - 0x78];
	bool unknownC4;	// NOTE: placeholder name
	char padC5[0xcc - 0xc5];
	int unknownCC;	// NOTE: placeholder name
	char padD0[0xd4 - 0xd0];
	vector<OpR3_Stat *> unknownD4;	// NOTE: placeholder name
	vector<int> unknownE4;	// NOTE: placeholder name
	int unknownF4;	// NOTE: placeholder name
	int unknownF8;	// NOTE: placeholder name
	bool unknownFC;	// NOTE: placeholder name
	char padFD[0x120 - 0xfd];
	int unknown120;	// NOTE: placeholder name
	char pad124[0x140 - 0x124];
	int unknown140;	// NOTE: placeholder name
	char pad144[0x158 - 0x144];
	bool unknown158;	// NOTE: placeholder name
	char pad159[0x15c - 0x159];
	int unknown15C;	// NOTE: placeholder name
	char pad160[0x164 - 0x160];
	int unknown164;	// NOTE: placeholder name
	char pad168[0x16c - 0x168];
	XColor unknown16C;	// NOTE: placeholder name
};

struct OpR3_EntityRecord	// NOTE: placeholder name
{
	char pad00[0xc0];
	int unknownC0;	// NOTE: placeholder name
};

class Entity
{
public:
	OpR3_EntityRecord *unknownGetRecord();	// NOTE: placeholder name (ICF'd trivial getter, 0x9b4350)
};

class HEntity
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const;	// 0x9b6570
};

class HProp
{
public:
	int ID;
	HProp();
	bool isValid() const;
	bool isNull() const;
	void reset();	// 0x9b7270
	class Prop *operator->() const;	// 0x9b64f0
};

class Cell
{
public:
	HProp getProp();	// 0x45d550
	void unknown45df50(HProp prop);	// NOTE: placeholder name (same function as the int overload below)
	HItem getItem();	// 0x45d8f0
	void unknown45df50(int propID);	// NOTE: placeholder name
	void unknown45df70();	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	T &operator()(int x, int y);	// 0x9ceda0
	bool contains(int x, int y);	// NOTE: placeholder name (0x9b45c0)
};
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

class BS	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	bool unknown71ec60(const Point &p, vector<Point> visited);	// NOTE: placeholder name
	void addPoint6a8(const Point &p);	// NOTE: placeholder name (0x465320)
	void unknown464e60(int propID);	// NOTE: placeholder name (takes an HProp by value)
};
extern BS *world;	// NOTE: placeholder name (0xcefc4c)

class OpR3_PropFactory	// NOTE: placeholder name (object at 0xcefaa8)
{
public:
	HProp unknown793360(PropData *type);	// NOTE: placeholder name
};
extern OpR3_PropFactory *opr3_propFactory;	// NOTE: placeholder name (0xcefaa8)
extern vector<PropData *> opr3_propTypes;	// NOTE: placeholder name (0xcf35b0)
extern int opr3_noID;	// NOTE: placeholder name (0xcaf15c)

class SoundMgr	// NOTE: placeholder name
{
public:
	void unknown454500(const Point &p);	// NOTE: placeholder name
};
extern SoundMgr soundMgr;	// NOTE: placeholder name (0xd2d2a0)

class OpR3_Machine	// NOTE: placeholder name
{
public:
	OpR3_Machine(vector<int> zones);	// 0x456280

	char pad00[0x14];
};

struct OpR3_MachineState	// NOTE: placeholder name
{
	char pad00[0x28];
	int unknown28;	// NOTE: placeholder name
};

class OpR3_PropLink	// NOTE: placeholder name
{
public:
	bool unknown65cf80();	// NOTE: placeholder name
	string unknown65cc80();	// NOTE: placeholder name

	HProp prop;
	int unknown04;	// NOTE: placeholder name
	char pad08[0x18 - 8];
	int unknown18;	// NOTE: placeholder name
	int unknown1C;	// NOTE: placeholder name
};

float opr3_pulse(float low, float high, int period, int offset);	// NOTE: placeholder name (0x4371a0, opR1d_4371a0)
extern float opr3_machineValueScale[][3];	// NOTE: placeholder name (0xb9e680)
extern const float opr3_machineValueFactor;	// NOTE: placeholder name (0xb9e650)
extern XColor *opr3_colorD32968;	// NOTE: placeholder name
extern XColor *opr3_colorCEFDCC;	// NOTE: placeholder name

class Prop
{
public:
	XColor unknown65e040();	// NOTE: placeholder name
	Prop(PropData *data_);	// 0x65d4c0
	void unknown65e2d0();	// NOTE: placeholder name
	void unknown65eaa0();	// NOTE: placeholder name
	int unknown665a70(int id, int amount);	// NOTE: placeholder name
	OpR3_Stat *unknown45c800(int id);	// NOTE: placeholder name
	void unknown65ec20();	// NOTE: placeholder name
	void unknown65e500();	// NOTE: placeholder name
	PropData *getData();	// NOTE: placeholder name (ICF'd trivial getter, 0x9b8f00)
	int getUnknown34();	// NOTE: placeholder name (0x44ab40)
	void unknown45cc50(const Point &p);	// NOTE: placeholder name
	bool isPassableFor(HEntity e);	// NOTE: placeholder name (0x65e1d0)
	bool unknown65e230();	// NOTE: placeholder name
	bool unknown65e280();	// NOTE: placeholder name
	void unknown65f170();	// NOTE: placeholder name
	void unknown65f270(const Point &newPos);	// NOTE: placeholder name

	HProp handle;	// NOTE: placeholder name
	PropData *data;	// NOTE: placeholder name
	Point position;	// NOTE: placeholder name
	bool unknown10;	// NOTE: placeholder name
	int unknown14;	// NOTE: placeholder name
	XColor color1;	// NOTE: placeholder name
	XColor color2;	// NOTE: placeholder name
	bool passable;	// NOTE: placeholder name
	vector<OpR3_Stat *> stats;	// NOTE: placeholder name
	OpR3_Machine *machine;	// NOTE: placeholder name
	int unknown34;	// NOTE: placeholder name
	int unknown38;	// NOTE: placeholder name
	int unknown3C;	// NOTE: placeholder name
	bool unknown40;	// NOTE: placeholder name
	bool soundOrigin;	// NOTE: placeholder name
	bool unknown42;	// NOTE: placeholder name
	OpR3_MachineState *unknown44;	// NOTE: placeholder name
	bool unknown48;	// NOTE: placeholder name
	OpR3_PropLink *unknown4C;	// NOTE: placeholder name
};

bool Prop::isPassableFor(HEntity e)
{
	if (data->unknownCC >= 0 && e.isValid() && e->unknownGetRecord()->unknownC0 == data->unknownCC)
		return true;
	return passable;
}

bool Prop::unknown65e230()
{
	return unknown38 != -1 && !opr3_propFlags[unknown38]->flag30;
}

bool Prop::unknown65e280()
{
	return (unknown34 != -1 || data->unknownFC) && data->unknown70 != -1;
}

void Prop::unknown65f170()
{
	unknown10 = false;
	if (cells(position)->getItem().isValid())
	{
		vector<Point> adj(1, position);
		if (!world->unknown71ec60(position, adj))
			cells(position)->getItem()->unknown57dbe0(0, 0, 1, 1);
	}
}

void Prop::unknown65f270(const Point &newPos)
{
	if (data->unknown68 > 0)
	{
		world->addPoint6a8(position);
		world->addPoint6a8(newPos);
	}
	if (soundOrigin)
	{
		soundMgr.unknown454500(position);
		soundMgr.unknown454500(newPos);
	}
	cells(position)->unknown45df70();
	position = newPos;
	cells(position)->unknown45df50(handle.ID);
}

void OpR3_f65f3e0(int type, const Point &p, int amount, int mode)	// NOTE: placeholder name
{
	if (type != opr3_noID)
	{
		if (mode == 2)
		{
			PropData *t;
			for (t = opr3_propTypes[type]; t->unknown74 != opr3_noID; t = opr3_propTypes[t->unknown74])
			{
				if (amount <= 0 || amount < t->unknown70)
				{
					cells(p)->unknown45df50(opr3_propFactory->unknown793360(t));
					cells(p)->getProp()->unknown45cc50(p);
					break;
				}
				amount -= t->unknown70;
			}
		}
		else
		{
			cells(p)->unknown45df50(opr3_propFactory->unknown793360(opr3_propTypes[type]));
			cells(p)->getProp()->unknown45cc50(p);
		}
	}
}

void Prop::unknown65ec20()
{
	if (!data->unknownE4.empty())
	{
		machine = new OpR3_Machine(data->unknownE4);
		world->unknown464e60(handle.ID);
	}
	else
		machine = NULL;
}

void Prop::unknown65eaa0()
{
	unsigned int i;
	unsigned int j;
	OpR3_Stat *found;
	for (i = 0; i < data->unknown60->stats.size(); i++)
		stats.push_back(new OpR3_Stat(*data->unknown60->stats[i]));
	for (j = 0; j < data->unknownD4.size(); j++)
	{
		found = unknown45c800(data->unknownD4[j]->type->id);
		if (found)
			found->count += data->unknownD4[j]->count;
		else
			stats.push_back(new OpR3_Stat(*data->unknownD4[j]));
	}
}

extern PropData *opr3_specialPropData;	// NOTE: placeholder name (0xcefbdc)
extern XColor *opr3_colorD01564;	// NOTE: placeholder names for the pointers below
extern XColor *opr3_colorD32EFC;
extern XColor *opr3_colorD201C4;
extern XColor *opr3_colorD3579C;
extern XColor *opr3_colorD38644;
extern XColor *opr3_colorD29758;
extern XColor *opr3_colorCFC174;
extern XColor *opr3_colorD1ECD4;
extern XColor *opr3_colorD35BC4;
extern XColor *opr3_colorD20B70;
extern XColor opr3_colorD29804;	// NOTE: placeholder name (0xd29804)

void Prop::unknown65e2d0()
{
	OpR3_ColorBag bag;
	if (data == opr3_specialPropData)
	{
		bag.add(*opr3_colorD01564, 5);
		bag.add(*opr3_colorD32EFC, 0x14);
		bag.add(*opr3_colorD201C4, 0x3c);
		bag.add(*opr3_colorD3579C, 0x14);
		bag.add(*opr3_colorD38644, 5);
	}
	else
	{
		bag.add(*opr3_colorD29758, 5);
		bag.add(*opr3_colorCFC174, 0x14);
		bag.add(*opr3_colorD1ECD4, 0x3c);
		bag.add(*opr3_colorD35BC4, 0x14);
		bag.add(*opr3_colorD20B70, 5);
	}
	color1 = bag.pick();
	unknown14 = rng.rangeInt(128.0f, 174.0f);
}

Prop::Prop(PropData *data_)
{
	handle.reset();
	data = data_;
	position.set(-1, -1);
	unknown10 = data->unknown5C;
	if (data->unknownFC)
		unknown65e2d0();
	else
	{
		unknown14 = data->unknown164;
		color1 = data->unknown16C;
	}
	color2 = opr3_colorD29804;
	passable = data->unknownC4;
	unknown65eaa0();
	unknown34 = -1;
	unknown38 = -1;
	unknown3C = 0;
	unknown40 = false;
	soundOrigin = data->unknown15C;
	unknown42 = data->unknown158;
	unknown44 = NULL;
	unknown48 = false;
	unknown4C = NULL;
}

void Prop::unknown65e500()
{
	vector<int> neighbors(4, 0);
	if (cells.contains(position.x,position.y - 1) && cells(position.x,position.y - 1)->getProp().isValid() && cells(position.x,position.y - 1)->getProp()->getUnknown34() != -1)
		neighbors[0] = 1;
	if (cells.contains(position.x + 1,position.y) && cells(position.x + 1,position.y)->getProp().isValid() && cells(position.x + 1,position.y)->getProp()->getUnknown34() != -1)
		neighbors[1] = 1;
	if (cells.contains(position.x,position.y + 1) && cells(position.x,position.y + 1)->getProp().isValid() && cells(position.x,position.y + 1)->getProp()->getUnknown34() != -1)
		neighbors[2] = 1;
	if (cells.contains(position.x - 1,position.y) && cells(position.x - 1,position.y)->getProp().isValid() && cells(position.x - 1,position.y)->getProp()->getUnknown34() != -1)
		neighbors[3] = 1;
	if (!opr3_anyNonZero(neighbors))
	{
		unknown14 = rng.chance(50) ? 139 : 151;
		return;
	}
	while (true)
	{
		unknown14 = rng.rangeInt(128.0f,174.0f);
		for (int i = 0; i < 4; i++)
		{
			if (neighbors[i] && opr3_tileTable[unknown14 - 128][i])
				goto done;
		}
	}
done:;
}

bool OpR3_PropLink::unknown65cf80()
{
	switch (prop->getData()->unknown140)
	{
	case 0xb:
		return unknown18;
	case 0xd:
		return unknown18 > 0;
	default:
		return unknown1C;
	}
}

XColor Prop::unknown65e040()
{
	if (unknown34 != -1 && unknown3C == 0)
	{
		if (color2 != opr3_colorD29804 && unknown44 != NULL && unknown44->unknown28 < 0)
		{
			XColor col = color2;
			float h;
			float s;
			float v;
			col.getHSV(&h,&s,&v);
			v = v / opr3_machineValueScale[data->unknownF8][0] * opr3_machineValueFactor;
			col.setHSV(0.0f,0.0f,v);
			return col;
		}
	}
	else if (unknown4C != NULL && unknown4C->unknown65cf80())
	{
		XColor base = data->unknown140 == 0xb ? *opr3_colorD32968 : *opr3_colorCEFDCC;
		return XColor::scale(base,opr3_pulse(0.0f,0.5f,2000,0) + 0.5);
	}
	return color2;
}

struct OpR3_LocationInfo	// NOTE: placeholder name
{
	int pad00;
	int type;	// NOTE: placeholder name
};

class OpR3_HLocation	// NOTE: placeholder name
{
public:
	int ID;
	OpR3_LocationInfo *operator->() const;	// 0x9b7910
};
extern OpR3_HLocation opr3_location;	// NOTE: placeholder name (0xd1e888)
extern string opr3_machineNames[];	// NOTE: placeholder name (0xd3a280)
extern string opr3_locationNames[];	// NOTE: placeholder name (0xd38e40)
string intToString(int value);	// 0x4051f0
string &opr3_padLeft(string &s, int width, char c);	// NOTE: placeholder name (0x408090)

string OpR3_PropLink::unknown65cc80()
{
	return opr3_machineNames[prop->getData()->unknownF8] + " " + opr3_locationNames[opr3_location->type] + opr3_padLeft(intToString(unknown04), 3, '0');
}

extern vector<OpR3_StatType *> opr3_statTypes;	// NOTE: placeholder name (0xd2f0f8)

int Prop::unknown665a70(int id, int amount)
{
	OpR3_Stat *stat = unknown45c800(id);
	if (stat)
	{
		stat->count += amount;
		return stat->count;
	}
	else
	{
		stats.push_back(new OpR3_Stat(opr3_statTypes[id],amount));
		return amount;
	}
}
