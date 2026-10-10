// op_q3: functions in 0x6c0000-0x87b000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../engine/xcolor.h"
using namespace std;

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
};

class Map
{
public:
	int getTurn() throw();	// 0x464270
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)

class HEntity;
class HItem;
class HProp;
struct OpQ3_Talk;	// NOTE: placeholder name
struct OpQ3_ItemType;	// NOTE: placeholder name
struct OpQ3_EntityRecord;	// NOTE: placeholder name

class Entity
{
public:
	bool isPlayer();
	void unknown6395d0(OpQ3_Talk *talk, bool flag);	// NOTE: placeholder name
	void unknown45b4c0(OpQ3_Talk *talk, bool flag);	// NOTE: placeholder name
};

class HEntity
{
public:
	int ID;
	HEntity();
	bool isNull() const;
	bool operator==(HEntity other) const;
	Entity *operator->() const;
};

class HItem
{
public:
	int ID;
	HItem();
	bool isNull() const;
	class Item *operator->() const;	// 0x9b65b0
};

class HProp
{
public:
	int ID;
	HProp() throw();
	bool isNull() const;
	struct OpQ3_Prop *operator->() const;	// 0x9b64f0
};

class Cell
{
public:
	HProp getProp();	// 0x45d550
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
};
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

struct OpQ3_Cec0cc	// NOTE: placeholder name
{
	void unknown48f940(int value);	// NOTE: placeholder name
};
extern OpQ3_Cec0cc *opq3_cec0cc;	// NOTE: placeholder name

struct OpQ3_Marker	// NOTE: placeholder name
{
	void unknown6c20b0(int type, const Point &p, int value);	// NOTE: placeholder name

	char pad00[4];
	int type;
	Point pos;
	int turn;
	int value;
};

void OpQ3_Marker::unknown6c20b0(int type_, const Point &p, int value_)
{
	type = type_;
	pos = p;
	turn = world->getTurn();
	value = value_;
	if (opq3_cec0cc)
		opq3_cec0cc->unknown48f940(type);
}

extern XColor *opq3_colorBlack;	// NOTE: placeholder name (0xcfe674)
extern XColor opq3_d29804;	// NOTE: placeholder name

XColor unknown6c1c70(XColor *color, bool *flag)	// NOTE: placeholder name
{
	if (*color != XColor(*opq3_colorBlack))
	{
		*flag = true;
		return XColor(*color);
	}
	else
	{
		*flag = false;
		return XColor(opq3_d29804);
	}
}

//==================================================================
// BS (world) methods
//==================================================================
struct OpQ3_Talk	// NOTE: placeholder name
{
	char pad00[0x3c];
	int type;
};

struct OpQ3_Prop	// NOTE: placeholder name
{
	int unknown9b8f00();	// NOTE: placeholder name (ICF'd trivial getter)
	int unknown457b10();	// NOTE: placeholder name
	struct OpQ3_PropInfo *unknown45cb30();	// NOTE: placeholder name
	void unknown665b10(OpQ3_Talk *talk, bool flag);	// NOTE: placeholder name
};

struct OpQ3_ItemType	// NOTE: placeholder name
{
	char pad00[0x48];
	int unknown48;
};

class Item
{
public:
	void unknown458390(bool flag);	// NOTE: placeholder name
	int unknown457820(int flag);	// NOTE: placeholder name
	void unknown57a190(HEntity e, int amount, int a, int b);	// NOTE: placeholder name
	void unknown57a0f0(Point &p, bool a, bool b);	// NOTE: placeholder name
};

class OpQ3_ItemFactory	// NOTE: placeholder name (object at 0xcefaa8)
{
public:
	HItem create(OpQ3_ItemType *type);	// NOTE: placeholder name (0x7932b0)
};
extern OpQ3_ItemFactory *opq3_itemFactory;	// NOTE: placeholder name (0xcefaa8)

class OpQ3_PlayerData	// NOTE: placeholder name (object at 0xcf45d8)
{
public:
	void unknown77ffb0(int a);	// NOTE: placeholder name
};
extern OpQ3_PlayerData opq3_playerData;	// NOTE: placeholder name (0xcf45d8)

class OpQ3_WeightedTable	// NOTE: placeholder name
{
public:
	bool empty();	// NOTE: placeholder name
	int &pick() throw();	// NOTE: placeholder name (0x9ba470)
};

extern vector<OpQ3_EntityRecord *> opq3_entityRecords;	// NOTE: placeholder name (0xd25de0)
extern vector<OpQ3_Talk *> opq3_talks;	// NOTE: placeholder name (0xd2c408)
extern int opq3_table_ba5f40[];	// NOTE: placeholder name
int opq3_findEntityRecord(vector<OpQ3_EntityRecord *> &list, const string &name);	// NOTE: placeholder name (0x9d7b80)
bool opq3_findTalk(vector<OpQ3_Talk *> &list, const string &name, OpQ3_Talk *&talk);	// NOTE: placeholder name (0x9d7de0)

class BS
{
public:
	HEntity unknown6c5dc0(const string &name, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name
	HEntity placeEntity(OpQ3_EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
	bool unknown6c65a0(HEntity e, const string &name, bool flag);	// NOTE: placeholder name
	bool unknown6c6600(HEntity e, const string &name);	// NOTE: placeholder name
	void unknown6c6660(string &name);	// NOTE: placeholder name
	bool unknown6c6700(HProp p, const string &name, bool flag);	// NOTE: placeholder name
	void unknown6c6770(HProp p, OpQ3_Talk *talk, bool flag);	// NOTE: placeholder name
	void unknown464e60(HProp p);	// NOTE: placeholder name
	OpQ3_EntityRecord *unknown6c5180();	// NOTE: placeholder name
	HItem unknown6c5400(OpQ3_ItemType *type, const Point &p);	// NOTE: placeholder name
	bool unknown71bc10(const Point &p, Point &out);	// NOTE: placeholder name
	HItem unknown6c51d0(OpQ3_ItemType *type, HEntity entity, bool a, bool b);	// NOTE: placeholder name

	char pad0[0xc0];
	OpQ3_WeightedTable table;
	char pad1[0x658 - 0xc0 - 1];
	int unknown658;
	char pad2[0x66c - 0x658 - 4];
	HEntity unknown66c;
};

HEntity BS::unknown6c5dc0(const string &name, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced)
{
	int index = opq3_findEntityRecord(opq3_entityRecords,name);
	return placeEntity(opq3_entityRecords[index],position,groupIndex,unknown18,aiMode1,aiMode2,forced);
}

bool BS::unknown6c65a0(HEntity e, const string &name, bool flag)
{
	if (e.isNull())
		return false;
	OpQ3_Talk *talk;
	opq3_findTalk(opq3_talks,name,talk);
	if (talk)
		e->unknown6395d0(talk,flag);
	return talk ? true : false;
}

bool BS::unknown6c6600(HEntity e, const string &name)
{
	if (e.isNull())
		return false;
	OpQ3_Talk *talk;
	opq3_findTalk(opq3_talks,name,talk);
	if (talk)
		e->unknown45b4c0(talk,true);
	return talk ? true : false;
}

void BS::unknown6c6660(string &name)
{
	string::const_iterator end = name.begin() + 3;
	name.erase(name.begin(),end);
	OpQ3_Talk *talk;
	opq3_findTalk(opq3_talks,name,talk);
	if (talk == NULL)
		return;
	if (opq3_table_ba5f40[talk->type])
		return;
	unknown66c->unknown6395d0(talk,false);
}

bool BS::unknown6c6700(HProp p, const string &name, bool flag)
{
	if (p.isNull())
		return false;
	OpQ3_Talk *talk;
	opq3_findTalk(opq3_talks,name,talk);
	if (talk)
	{
		p->unknown665b10(talk,flag);
		unknown464e60(p);
	}
	return talk ? true : false;
}

void BS::unknown6c6770(HProp p, OpQ3_Talk *talk, bool flag)
{
	p->unknown665b10(talk,flag);
	unknown464e60(p);
}

OpQ3_EntityRecord *BS::unknown6c5180()
{
	return table.empty() ? NULL : opq3_entityRecords[table.pick()];
}

HItem BS::unknown6c51d0(OpQ3_ItemType *type, HEntity entity, bool a, bool b)
{
	HItem item = opq3_itemFactory->create(type);
	if (!b)
		item->unknown458390(false);
	if (entity->isPlayer())
		opq3_playerData.unknown77ffb0(item->unknown457820(0));
	item->unknown57a190(entity,a ? type->unknown48 : 4,(unknown658 && entity == unknown66c) ? true : false,0);
	return item;
}

HItem BS::unknown6c5400(OpQ3_ItemType *type, const Point &p)
{
	Point pos;
	bool found = unknown71bc10(p,pos);
	if (!found)
		return HItem();
	HItem item = opq3_itemFactory->create(type);
	item->unknown57a0f0(pos,false,false);
	return item;
}

//==================================================================
// Map records
//==================================================================
struct OpQ3_Area	// NOTE: placeholder name
{
	bool contains(const Point &p);	// NOTE: placeholder name (0x40b750)
};

struct OpQ3_Record	// NOTE: placeholder name (0x10 bytes)
{
	OpQ3_Record(const Point &p, int type_, int expire_) throw();	// NOTE: placeholder name (0x460010)

	Point pos;
	int type;
	int expire;
};

extern vector<OpQ3_Area> opq3_areas;	// NOTE: placeholder name (0xd204cc)
extern vector<OpQ3_Record *> opq3_records;	// NOTE: placeholder name (0xcf0fa8)

//==================================================================
// Point lists
//==================================================================
extern int opq3_cefbd4;	// NOTE: placeholder name

class OpQ3_PointList	// NOTE: placeholder name
{
public:
	bool unknown6c11f0(const Point &p);	// NOTE: placeholder name

	char pad00[0xc];
	vector<Point> points;
};

bool OpQ3_PointList::unknown6c11f0(const Point &p)
{
	for (unsigned int i = 0; i < points.size(); i++)
	{
		if (points[i] == p)
			return cells(points[i])->getProp().isNull() || cells(points[i])->getProp()->unknown9b8f00() != opq3_cefbd4;
	}
	return false;
}

template <class T> void opq3_eraseAt(vector<T> &v, unsigned int index);	// NOTE: placeholder name (0x9d8f20)

bool opq3_removeRecord(const Point &p)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < opq3_records.size(); i++)
	{
		if (opq3_records[i]->pos == p)
		{
			opq3_eraseAt(opq3_records,i);
			return true;
		}
	}
	return false;
}

//==================================================================
// Path / blast objects
//==================================================================
struct OpQ3_Location	// NOTE: placeholder name
{
	int unknown00;
	int depth;
	bool unknown46ecb0();	// NOTE: placeholder name
};

class OpQ3_HLocation	// NOTE: placeholder name
{
public:
	OpQ3_Location *operator->() const throw();	// 0x9b7910
};
extern OpQ3_HLocation opq3_location;	// NOTE: placeholder name (0xd1e888)

extern vector<vector<HProp> > opq3_props;	// NOTE: placeholder name (0xd31640)

class OpQ3_Path	// NOTE: placeholder name
{
public:
	HProp unknown6c12e0();	// NOTE: placeholder name
	bool unknown6c1320();	// NOTE: placeholder name

	vector<Point> points;
};

HProp OpQ3_Path::unknown6c12e0()
{
	return opq3_props[points.front().x][0];
}

bool OpQ3_Path::unknown6c1320()
{
	return !opq3_props[points.front().x].empty() && opq3_props[points.front().x][0]->unknown457b10() == 0;
}

struct OpQ3_HExplosive	// NOTE: placeholder name
{
	int ID;
};

class OpQ3_Blast	// NOTE: placeholder name
{
public:
	OpQ3_Blast(const Point &p, int unknown08_, bool unknown0c_, int unknown14_, int unknown18_);	// NOTE: placeholder name

	Point pos;
	int unknown08;
	bool unknown0c;
	bool unknown0d;
	bool unknown0e;
	int unknown10;
	int unknown14;
	int unknown18;
	int unknown1c;
	vector<OpQ3_HExplosive> unknown20;
	vector<OpQ3_HExplosive> unknown30;
	vector<OpQ3_HExplosive> unknown40;
	vector<OpQ3_HExplosive> unknown50;
};

OpQ3_Blast::OpQ3_Blast(const Point &p, int unknown08_, bool unknown0c_, int unknown14_, int unknown18_)
	: pos		(p)
	, unknown08	(unknown08_)
	, unknown0c	(unknown0c_)
	, unknown0d	(false)
	, unknown0e	(false)
	, unknown10	(2)
	, unknown14	(unknown14_)
	, unknown18	(unknown18_)
	, unknown1c	(opq3_location->depth == 0xd)
{
}

//==================================================================
// Location / range objects
//==================================================================
extern bool opq3_table_b90480[];	// NOTE: placeholder name

class OpQ3_Obj6c1a10	// NOTE: placeholder name
{
public:
	bool unknown6c1a10();	// NOTE: placeholder name

	char pad00[8];
	OpQ3_HLocation unknown08;
	char pad0c[8];
	HProp unknown14;
	HProp unknown18;
};

bool OpQ3_Obj6c1a10::unknown6c1a10()
{
	return !unknown08->unknown46ecb0() && unknown14.isNull() && unknown18.isNull() && !opq3_table_b90480[unknown08->depth];
}

struct OpQ3_Range	// NOTE: placeholder name (8 bytes)
{
	int randomInRange_40c130() throw();	// NOTE: placeholder name

	int min;
	int max;
};
extern OpQ3_Range opq3_d21b3c;	// NOTE: placeholder name
extern OpQ3_Range opq3_d22fa0;	// NOTE: placeholder name

class OpQ3_Obj6c2110	// NOTE: placeholder name
{
public:
	OpQ3_Obj6c2110();	// NOTE: placeholder name

	vector<OpQ3_HExplosive> unknown00;
	int unknown10;
	int unknown14;
	int unknown18;
	int unknown1c;
	int unknown20;
};

OpQ3_Obj6c2110::OpQ3_Obj6c2110()
{
	unknown10 = 0;
	unknown14 = opq3_d21b3c.randomInRange_40c130();
	unknown18 = opq3_d22fa0.randomInRange_40c130();
	unknown1c = world->getTurn() + unknown18;
	unknown20 = unknown18;
}

//==================================================================
// Prop lists
//==================================================================
struct OpQ3_PropInfo	// NOTE: placeholder name
{
	char pad00[0x28];
	int unknown28;
};

class OpQ3_PropList	// NOTE: placeholder name
{
public:
	bool unknown6c2180();	// NOTE: placeholder name

	vector<HProp> list;
};

void opq3_eraseStepBack(vector<HProp> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440)

bool OpQ3_PropList::unknown6c2180()
{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (!list[i].operator->() || list[i]->unknown457b10() || list[i]->unknown45cb30()->unknown28 < 0)
			opq3_eraseStepBack(list,i);
	}
	return !list.empty();
}

//==================================================================
// String helpers
//==================================================================
bool opq3_splitAfterBracket(const string &s, string &first, string &second)	// NOTE: placeholder name
{
	unsigned int pos = s.find(']',0);
	if (pos == string::npos || pos == s.size() - 1)
		return false;
	first.assign(s.begin(),s.begin() + pos + 1);
	second.assign(s.begin() + pos + 1,s.end());
	return true;
}

//==================================================================
// Item selection tables
//==================================================================
class OpQ3_ItemTypeEntry	// NOTE: placeholder name
{
public:
	int ID;
	char pad04[0x50 - 4];
	int unknown50;
	int unknown54;
	int unknown58;
	char pad5c[4];
	int unknown60;
	char pad64[0x94 - 0x64];
	int unknown94;
};

class OpQ3_GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	int getDepthIndex();	// NOTE: placeholder name
};
extern OpQ3_GameData opq3_gameData;	// NOTE: placeholder name (0xd1e860)
extern vector<OpQ3_ItemTypeEntry *> opq3_itemTypes;	// NOTE: placeholder name (0xd2d1c4)
bool opq3_unknown5714a0(int value);	// NOTE: placeholder name
int opq3_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)

class OpQ3_WeightedTable2	// NOTE: placeholder name
{
public:
	void clear();	// NOTE: placeholder name (0x9c07a0)
	void add(int value, int weight);	// NOTE: placeholder name (0x9ba310)
};

class OpQ3_Selector	// NOTE: placeholder name
{
public:
	void unknown6c3a50(OpQ3_WeightedTable2 *table, bool flag, int rating);	// NOTE: placeholder name
};

void OpQ3_Selector::unknown6c3a50(OpQ3_WeightedTable2 *table, bool flag, int rating)
{
	rating = rating ? rating : opq3_gameData.getDepthIndex();
	table->clear();
	for (unsigned int i = 0; i < opq3_itemTypes.size(); i++)
	{
		if ((opq3_itemTypes[i]->unknown94 != 0) != flag)
			continue;
		OpQ3_ItemTypeEntry *type = opq3_itemTypes[i];
		if (!opq3_unknown5714a0(type->unknown54))
			continue;
		float chance = 1.0f;
		if (opq3_maxInt(1,rating) < type->unknown50)
			continue;
		switch (type->unknown58)
		{
		case 1:
		case 2:
			{
				float step = type->unknown58 == 1 ? 0.05f : 0.1f;
				chance -= (rating - type->unknown50) * step;
				if (chance <= 0.0)
					continue;
			}
		}
		int weight = (int)(type->unknown60 * chance);
		if (weight > 0)
			table->add(type->ID,weight);
	}
}
