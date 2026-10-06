// op_r3d: functions in 0x690000-0x6a0000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	bool operator==(HEntity other) const;	// 0x9b78e0
};

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
};

class HProp
{
public:
	int ID;
	void reset();	// 0x9b7270
};

struct OpR3d_Target	// NOTE: placeholder name
{
	HEntity entity;
	int count;
	int unknown08;

	OpR3d_Target(HEntity e) throw();	// 0x45ea50
	void increment();	// NOTE: placeholder name (0x45ea80)
};

class HItem
{
public:
	int ID;
};

class Item;
class Entity
{
public:
	vector<HItem> *getInventoryList();	// 0x45ab00
};

class OpR3d_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	void unknown464fd0(HItem item);	// NOTE: placeholder name
	void unknown4650c0(HItem item);	// NOTE: placeholder name
	void unknown726bd0(HItem item);	// NOTE: placeholder name
	int unknown4642d0();	// NOTE: placeholder name
	int unknown4642f0();	// NOTE: placeholder name
};
extern OpR3d_Map *opr3d_world;	// NOTE: placeholder name (0xcefc4c)

class OpR3d_EntityPool	// NOTE: placeholder name (0xd21720)
{
public:
	Entity *unknown9d0bc0(int id);	// NOTE: placeholder name
};
extern OpR3d_EntityPool opr3d_entityPool;	// NOTE: placeholder name (0xd21720)

class OpR3d_ItemPool	// NOTE: placeholder name (0xd2a298)
{
public:
	Item *unknown9d0bc0(int id);	// NOTE: placeholder name
};
extern OpR3d_ItemPool opr3d_itemPool;	// NOTE: placeholder name (0xd2a298)

template <class T> void OpR3d_eraseAt(vector<T> &v, unsigned int index);	// NOTE: placeholder name (0x9d8f20)

class OpR3d_TargetList	// NOTE: placeholder name
{
public:
	char pad00[0x108];
	vector<OpR3d_Target *> targets;	// +0x108

	OpR3d_Target *unknown690650(HEntity e);	// NOTE: placeholder name
	void unknown6906d0(HEntity e);	// NOTE: placeholder name
	void unknown690750(HEntity e);	// NOTE: placeholder name
};

OpR3d_Target *OpR3d_TargetList::unknown690650(HEntity e)
{
	for (unsigned int i = 0; i < targets.size(); i++)
	{
		if (targets[i]->entity == e)
			return targets[i];
	}
	return NULL;
}

void OpR3d_TargetList::unknown6906d0(HEntity e)
{
	OpR3d_Target *t = unknown690650(e);
	if (t)
		t->increment();
	else
	{
		OpR3d_Target *m = new OpR3d_Target(e);
		OpR3d_Target *n = m;
		targets.push_back(n);
	}
}

void OpR3d_TargetList::unknown690750(HEntity e)
{
	for (unsigned int i = 0; i < targets.size(); i++)
	{
		if (targets[i]->entity == e)
		{
			targets[i]->count--;
			if (targets[i]->count <= 0)
				OpR3d_eraseAt(targets, i);
			return;
		}
	}
}

class OpR3d_InventoryHold	// NOTE: placeholder name
{
public:
	Entity *entity;
	vector<Item *> items;
	bool active;	// +0x14

	OpR3d_InventoryHold(int id);	// NOTE: placeholder name (0x690810)
};

OpR3d_InventoryHold::OpR3d_InventoryHold(int id)
{
	active = true;
	entity = opr3d_entityPool.unknown9d0bc0(id);
	vector<HItem> *inventory = entity->getInventoryList();
	for (unsigned int i = 0; i < inventory->size(); i++)
	{
		opr3d_world->unknown464fd0((*inventory)[i]);
		opr3d_world->unknown4650c0((*inventory)[i]);
		opr3d_world->unknown726bd0((*inventory)[i]);
		Item *item = opr3d_itemPool.unknown9d0bc0((*inventory)[i].ID);
		items.push_back(item);
	}
	inventory->clear();
}

struct OpR3d_Expiry	// NOTE: placeholder name
{
	int first;
	int second;

	void set(int first_, int second_);	// NOTE: placeholder name (0x690d40)
	bool hasExpired();	// NOTE: placeholder name (0x690da0)
};

void OpR3d_Expiry::set(int first_, int second_)
{
	first = (first_ > 0) ? opr3d_world->unknown4642d0() + first_ : first_;
	second = (second_ > 0) ? opr3d_world->unknown4642f0() + second_ : second_;
}

bool OpR3d_Expiry::hasExpired()
{
	return (first > 0 && opr3d_world->unknown4642d0() >= first) || (second > 0 && opr3d_world->unknown4642f0() >= second);
}

class OpR3d_Pair	// NOTE: placeholder name (8 bytes)
{
public:
	int a;
	int b;

	void zero();	// NOTE: placeholder name (0x45f0a0)
	void fill(int v);	// NOTE: placeholder name (0x409ff0)
};

class OpR3d_Obj64	// NOTE: placeholder name
{
public:
	char pad00[0x64];

	OpR3d_Obj64() throw();	// 0x45f0c0
};

class OpR3d_Obj68	// NOTE: placeholder name
{
public:
	virtual ~OpR3d_Obj68();	// 0x45f890 (scalar deleting)
};

struct OpR3d_Rec	// NOTE: placeholder name
{
	int a;
	int b;
};

enum OpR3d_EnumA	// NOTE: placeholder name
{
	OPR3D_ENUMA_0,
	OPR3D_ENUMA_1
};

enum OpR3d_EnumB	// NOTE: placeholder name
{
	OPR3D_ENUMB_0
};

extern int opr3d_d25740;	// NOTE: placeholder name
extern int opr3d_caf160;	// NOTE: placeholder name

class OpR3d_State	// NOTE: placeholder name (object at 0xcf6888)
{
public:
	vector<OpR3d_EnumA> v00;
	vector<OpR3d_EnumA> v10;
	OpR3d_Obj64 *obj20;
	OpR3d_Pair p24;
	int i2c;
	HProp prop30;
	int i34;
	OpR3d_Pair p38;
	int i40;
	vector<OpR3d_EnumA> v44;
	vector<OpR3d_EnumA> v54;
	int i64;
	OpR3d_Obj68 *obj68;
	int i6c;
	vector<int> v70;
	OpR3d_Pair p80;
	vector<HEntity> v88;
	vector<Point> v98;
	vector<OpR3d_Rec> va8;
	vector<HEntity> vb8;
	int ic8;
	int icc;
	int id0;
	OpR3d_Pair pd4;
	vector<HEntity> vdc;
	OpR3d_Pair pec;
	OpR3d_Pair pf4;
	HProp propfc;
	string s100;
	int i11c;
	HProp prop120;
	vector<int> v124;
	OpR3d_Pair p134;
	OpR3d_Pair p13c;
	OpR3d_Pair p144;
	int i14c;
	int i150;
	vector<HEntity> v154;
	vector<Point> v164;
	vector<int> v174;
	int i184;
	OpR3d_Pair p188;
	int i190;
	bool b194;
	int i198;
	bool b19c;
	HProp prop1a0;
	int i1a4;
	int i1a8;
	bool b1ac;
	int i1b0;
	OpR3d_Pair p1b4;
	OpR3d_Pair p1bc;
	bool b1c4;
	int i1c8;
	int i1cc;
	int i1d0;
	int i1d4;
	vector<Point> v1d8;
	vector<Point> v1e8;
	vector<HEntity> v1f8;
	vector<OpR3d_EnumA> v208;
	int i218;
	vector<OpR3d_EnumB> v21c;
	bool b22c;
	int i230;
	vector<int> v234;
	vector<int> v244;
	vector<HEntity> v254;
	vector<HEntity> v264;
	vector<HEntity> v274;

	void unknown690e00();	// NOTE: placeholder name
};

void OpR3d_State::unknown690e00()
{
	v00.assign(16, (OpR3d_EnumA)0);
	v10.assign(16, (OpR3d_EnumA)0);
	if (opr3d_d25740 >= 20)
		obj20 = new OpR3d_Obj64();
	else
		obj20 = NULL;
	p24.zero();
	i2c = 0;
	prop30.reset();
	i34 = 0;
	p38.zero();
	i40 = 0;
	v44.assign(10, (OpR3d_EnumA)1);
	v54.assign(10, (OpR3d_EnumA)0);
	i64 = 0;
	delete obj68;
	obj68 = NULL;
	i6c = 0;
	v70.clear();
	p80.zero();
	v88.clear();
	v98.clear();
	va8.clear();
	vb8.clear();
	ic8 = 0;
	icc = 0;
	id0 = 15;
	pd4.zero();
	vdc.clear();
	pec.zero();
	pf4.zero();
	propfc.reset();
	s100.clear();
	i11c = opr3d_caf160;
	prop120.reset();
	v124.clear();
	p134.zero();
	p13c.fill(-1);
	p144.fill(-1);
	i14c = 0;
	i150 = 0;
	v154.clear();
	v164.clear();
	v174.clear();
	i184 = 0;
	p188.fill(-1);
	i190 = 0;
	b194 = true;
	i198 = 0;
	b19c = false;
	prop1a0.reset();
	i1a4 = 0;
	i1a8 = 0;
	b1ac = false;
	i1b0 = 0;
	p1b4.zero();
	p1bc.zero();
	b1c4 = false;
	i1c8 = 0;
	i1cc = 0;
	i1d0 = 0;
	i1d4 = 0;
	v1d8.clear();
	v1e8.clear();
	v1f8.clear();
	v208.clear();
	i218 = 0;
	v21c.clear();
	b22c = false;
	i230 = 0;
	v234.clear();
	v244.clear();
	v254.clear();
	v264.clear();
	v274.clear();
}
