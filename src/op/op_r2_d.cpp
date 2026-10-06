// op_r2_d: Item / Entity / Map helpers in 0x570000-0x5b0000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
	Point();	// 0x453b40
	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p);	// 0x46ca50
	Point(int v);	// 0x409990
	Point &operator=(const Point &p);	// 0x46ca50
	void fill(int v);	// NOTE: placeholder name (0x409ff0)
	void assign(const Point &p);	// NOTE: placeholder name (0x40a030)
};

struct Area	// NOTE: placeholder name
{
	Area();	// 0x40b100
	Point min;
	Point max;
};

int distanceCeil(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
int minInt(int a, int b);	// 0x9cdb30
bool inRange(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)

class Entity;
class Item;
class Prop;
struct OpQ5_U9d7de0;

class HEntity	// NOTE: placeholder layout
{
	int ID;
public:
	HEntity();
	bool isNull() const;
	bool operator==(HEntity other) const;	// 0x9b78e0
	void clear();	// NOTE: placeholder name (0x9b7270)
	Entity *operator->() const;	// 0x9b6570
};

class HItem	// NOTE: placeholder layout
{
	int ID;
public:
	HItem();
	bool isNull() const;
	bool isValid() const;
	bool operator!=(HItem other) const;
	Item *operator->() const;	// 0x9b65b0
};

class HProp	// NOTE: placeholder layout
{
	int ID;
public:
	HProp();
	bool isValid() const;
	Prop *operator->() const;	// 0x9b64f0
};

struct ResistTable	// NOTE: placeholder name
{
	char pad00[0x20];
	int values[12];
	vector<vector<int> > unknown50;	// NOTE: placeholder name
};

struct PropData	// NOTE: placeholder name
{
	char pad00[0x60];
	ResistTable *unknown60;	// NOTE: placeholder name
	char pad64[0x78 - 0x64];
	bool unknown78;	// NOTE: placeholder name
	char pad79[0xa8 - 0x79];
	int unknownA8[7];	// NOTE: placeholder name
	char padc4[0xf8 - 0xc4];
	int unknownF8;	// NOTE: placeholder name
};

class Prop
{
public:
	PropData *unknown9b8f00();	// NOTE: placeholder name (folded getter)
	int unknown45c630();	// NOTE: placeholder name
	const Point &getPosition();	// NOTE: placeholder name (0x4184d0)
};

struct TerrainRecord	// NOTE: placeholder name
{
	char pad00[0x50];
	ResistTable *unknown50;	// NOTE: placeholder name
};

class Cell
{
public:
	TerrainRecord *unknown9fcd80();	// NOTE: placeholder name (folded getter)
	int getArmor();	// 0x66ae70
	HProp getProp();	// NOTE: placeholder name (0x45d550)
	void addItem(HItem item, int a);	// NOTE: placeholder name (0x66bcf0)
	void removeItem(HItem item);	// NOTE: placeholder name (0x66c020)
	bool unknown45db50();	// NOTE: placeholder name
	int unknown45a6e0();	// NOTE: placeholder name (folded getter)
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	T &operator()(int x, int y);	// 0x9ceda0
	void getArea(const Point &center, int radius, Area &area);	// NOTE: placeholder name (0x9b4430)
};
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	bool isPlayer();	// 0x5c7600
	int unknown5c7fa0();	// NOTE: placeholder name
	void unknown5dfb60(HItem item);	// NOTE: placeholder name
	void unknown5dfbd0(HItem item);	// NOTE: placeholder name
	int unknown5e2b50();	// NOTE: placeholder name
	int unknown5cb9b0(bool flag);	// NOTE: placeholder name
	void polymindUnpossess(bool flag);	// NOTE: placeholder name (0x5d93d0)
	int unknown5cb570(int type, bool flag);	// NOTE: placeholder name
	int unknown490840();	// NOTE: placeholder name (folded getter)
	HItem unknown5d5d40();	// NOTE: placeholder name
	int unknown5d2150(int type, int base);	// NOTE: placeholder name
	int unknown5dc440(HItem item);	// NOTE: placeholder name
};

class BS	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	int unknown464290();	// NOTE: placeholder name
	int unknown4642d0();	// NOTE: placeholder name
	HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
	int getTurn();	// 0x464270
	void unknown4657e0();	// NOTE: placeholder name
	void unknown464b90(HItem item);	// NOTE: placeholder name
	void unknown464c10(HItem item);	// NOTE: placeholder name
	void unknown726b70(HItem item);	// NOTE: placeholder name
	void unknown726bd0(HItem item);	// NOTE: placeholder name
};
extern BS *world;	// NOTE: placeholder name (0xcefc4c)

struct ItemEffectType	// NOTE: placeholder name
{
	int ID;
};

struct ItemEffect	// NOTE: placeholder name
{
	ItemEffect(int type_, int state_) throw();	// 0x46ca20
	ItemEffectType *type;
	int state;
};
class CInventory	// NOTE: placeholder layout
{
public:
	void reopen(int mode, HItem item);	// NOTE: placeholder signature (0x8a2ce0)
};
extern CInventory *inventory;	// NOTE: placeholder name (0xcec08c)

class CParts	// NOTE: placeholder layout
{
public:
	void unknown8979b0(HItem item, int a, int b);	// NOTE: placeholder name
	void unknown897290(HItem item, int key);	// NOTE: placeholder name
};
extern CParts *parts;	// NOTE: placeholder name (0xcec088)

class CMapFine	// NOTE: placeholder layout
{
public:
	void addNewInventoryItemIndicator(HItem item);	// 0x876860
};
extern CMapFine *mapFine;	// NOTE: placeholder name (0xcec058)

class OpR2D_Audio	// NOTE: placeholder layout
{
};
extern int OpR2D_cefc90;	// NOTE: placeholder name
extern int OpR2D_d28d68;	// NOTE: placeholder name
extern bool OpR2D_d25450;	// NOTE: placeholder name
extern int OpR2D_d254c4;	// NOTE: placeholder name
extern int OpR2D_cf462c;	// NOTE: placeholder name
extern bool OpR2D_cefb5a;	// NOTE: placeholder name
extern vector<HItem> OpR2D_cf4944;	// NOTE: placeholder name
void unknown454160(const Point &p, int a, int b);	// NOTE: placeholder name
bool OpR2D_unknown4569a0(int id, HEntity a, HEntity b, HProp c, HItem item, int d, string *name, void *e, HEntity f, HProp g, HItem h, int i);	// NOTE: placeholder name (0x4569a0)

void opw8_increase(int *value, int amount, int maximum);	// NOTE: placeholder name (0x9d06d0)
int opw8_decrease(int *value, int amount, int minimum);	// NOTE: placeholder name (0x9d0690)
extern int OpR2D_cf4718;	// NOTE: placeholder name
extern float OpR2D_tableBA6614[];	// NOTE: placeholder name

struct OpW8_EntityEC	// NOTE: placeholder name (0x14 bytes)
{
	OpW8_EntityEC() throw();	// 0x456260

	char pad00[0x14];
};

struct PropEffects	// NOTE: placeholder name
{
	bool unknown4563e0(OpQ5_U9d7de0 *type);	// NOTE: placeholder name
	void unknown456660(OpQ5_U9d7de0 *type);	// NOTE: placeholder name
};

struct OpQ5_U9d7de0	// NOTE: placeholder name (the item effect type record)
{
	int ID;
	string name;
};
extern vector<OpQ5_U9d7de0 *> OpR2D_d2c408;	// NOTE: placeholder name (0xd2c408)
template <class T> bool OpQ5_findByName(vector<T*> &v, string &name, T *&result);	// NOTE: placeholder name (0x9d7de0)

extern string gameStrings_d22758[];
extern string gameStrings_d37d50[];
extern string OpR2D_string_d1f3f4;	// NOTE: placeholder name
const float OpR2D_float08 = 0.8f;	// NOTE: placeholder name (0xbe2658)
extern vector<int> effectTypes;	// NOTE: placeholder name (0xd2f0f8)

struct ItemRecord	// NOTE: placeholder name
{
	int unknown457330(int id) throw();	// NOTE: placeholder name
	char pad00[0x24];
	string name;	// NOTE: placeholder name
	char pad40[0x44 - 0x40];
	int unknown44;	// NOTE: placeholder name
	int unknown48;	// NOTE: placeholder name
	char pad4c[0x68 - 0x4c];
	int unknown68;	// NOTE: placeholder name
	char pad6c[0x94 - 0x6c];
	int unknown94;	// NOTE: placeholder name
	char pad98[0xec - 0x98];
	int unknownEC;	// NOTE: placeholder name
	int unknownF0;	// NOTE: placeholder name
	char padf4[0x104 - 0xf4];
	int unknown104;	// NOTE: placeholder name
	char pad108[0x124 - 0x108];
	int unknown124;	// NOTE: placeholder name
	int unknown128;	// NOTE: placeholder name
	char pad12c[0x1a0 - 0x12c];
	int *unknown1a0;	// NOTE: placeholder name
	char pad1a4[0x278 - 0x1a4];
	int *unknown278;	// NOTE: placeholder name
};

class Item
{
public:
	void setActive(bool active);	// 0x5791a0
	void setActivateOkayTurn(int turn);	// 0x4583b0
	void addEffect(ItemEffect *effect);	// NOTE: placeholder name (0x4585a0)
	ItemEffect *getEffect(int type);	// NOTE: placeholder name (0x457b70)
	int unknown44aec0();	// NOTE: placeholder name (folded getter)
	int unknown457880();	// NOTE: placeholder name (folded getter)
	int unknown457f90();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
	int unknown4580e0();	// NOTE: placeholder name
	ItemRecord *unknown9b4350();	// NOTE: placeholder name (folded getter)
	bool unknown577940();	// NOTE: placeholder name
	const Point &unknown575920();	// NOTE: placeholder name
	bool unknown578d90(HItem item);	// NOTE: placeholder name
	int unknown578f20(vector<Point> *cellList, int *range);	// NOTE: placeholder name
	bool unknown578b80(HProp prop);	// NOTE: placeholder name
	bool unknown578c50(const Point &p);	// NOTE: placeholder name
	bool unknown578d00(HEntity target);	// NOTE: placeholder name
	int unknown578e90(bool flag);	// NOTE: placeholder name
	int unknown579050();	// NOTE: placeholder name
	float unknown579090();	// NOTE: placeholder name
	bool unknown5790e0();	// NOTE: placeholder name
	void unknown578800();	// NOTE: placeholder name
	void unknown579c80();	// NOTE: placeholder name
	void unknown579e60(bool added, HItem item);	// NOTE: placeholder name
	void unknown579f50(bool a, bool b);	// NOTE: placeholder name
	void unknown57a0f0(const Point &p, int a, bool b);	// NOTE: placeholder name
	bool unknown57a190(HEntity e, int state_, bool a, bool b);	// NOTE: placeholder name
	void unknown57a520(HProp prop, int flag);	// NOTE: placeholder name
	void unknown57a5d0(int state_, int flag);	// NOTE: placeholder name
	void unknown5797c0();	// NOTE: placeholder name
	void unknown5798b0(int amount);	// NOTE: placeholder name
	void unknown57beb0(ItemRecord *source, int amount);	// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown57c160(const Point &p);	// NOTE: placeholder name
	void unknown57c090(OpQ5_U9d7de0 *type, bool flag);	// NOTE: placeholder name
	bool unknown57c110(string &name, bool flag);	// NOTE: placeholder name
	void unknown57bf30(int type, int state);	// NOTE: placeholder name
	int unknown57bff0(int type, int amount);	// NOTE: placeholder name

	int unknown00;
	HItem handle;
	ItemRecord *record;
	int state;	// NOTE: placeholder name
	HEntity owner;
	Point position;
	int integrity;	// NOTE: placeholder name
	char pad20[0x24 - 0x20];
	int unknown24;	// NOTE: placeholder name
	char pad28[0x30 - 0x28];
	int activeTurn;	// NOTE: placeholder name
	int unknown34;	// NOTE: placeholder name
	char pad38[0x44 - 0x38];
	int unknown44;	// NOTE: placeholder name
	vector<ItemEffect *> effects;	// NOTE: placeholder name
	PropEffects *unknown58;	// NOTE: placeholder name
};

//==================================================================
// free helpers
//==================================================================

bool OpR2D_unknown571520(int a, int b)	// NOTE: placeholder name
{
	if (a >= 4)
	{
		return b == a;
	}
	else
	{
		switch (a)
		{
		case 0:
			return false;
		case 1:
			return true;
		case 2:
			return b == 2;
		case 3:
			return b == 3;
		default:
			return false;
		}
	}
}

//==================================================================
// OpR2D_EntityRec: object with a record pointer at +8
//==================================================================

struct OpR2D_EntityData	// NOTE: placeholder name
{
	char pad00[0xf0];
	int type;	// NOTE: placeholder name
};

class OpR2D_Obj571d70	// NOTE: placeholder name
{
public:
	bool unknown571d70();	// NOTE: placeholder name

	char pad00[8];
	OpR2D_EntityData *data;	// NOTE: placeholder name
};

bool OpR2D_Obj571d70::unknown571d70()
{
	if (data->type == 0xcf || data->type == 0xd6)
	{
		return true;
	}
	return false;
}

class OpR2D_Obj575950	// NOTE: placeholder name
{
public:
	void unknown575950();	// NOTE: placeholder name

	char pad00[0xc];
	int mode;	// NOTE: placeholder name
};

void OpR2D_Obj575950::unknown575950()
{
	OpR2D_string_d1f3f4 = mode == 5 ? gameStrings_d22758[0] : (mode == 4 ? gameStrings_d22758[1] : gameStrings_d22758[2]);
}

class OpR2D_Obj5798f0	// NOTE: placeholder name
{
public:
	bool unknown5798f0();	// NOTE: placeholder name
	int unknown581630();	// NOTE: placeholder name

	char pad00[0x34];
	int expireTurn;	// NOTE: placeholder name
	int pad38;
	int endTurn;	// NOTE: placeholder name
};

bool OpR2D_Obj5798f0::unknown5798f0()
{
	switch (expireTurn)
	{
	case -2:
		return true;
	case -1:
		return false;
	}
	if (world->unknown464290() >= expireTurn + 0x19)
	{
		expireTurn = -1;
	}
	return false;
}

int OpR2D_Obj5798f0::unknown581630()
{
	return endTurn != -1 && world->unknown4642d0() >= endTurn;
}

class OpR2D_Obj581810	// NOTE: placeholder name
{
public:
	string unknown581810();	// NOTE: placeholder name

	char pad00[8];
	int index;	// NOTE: placeholder name
};

string OpR2D_Obj581810::unknown581810()
{
	return gameStrings_d37d50[index];
}

class OpR2D_Obj5815e0	// NOTE: placeholder name
{
public:
	bool unknown5815e0();	// NOTE: placeholder name

	HEntity entity;
	char pad04[0x55 - 4];
	bool flag55;	// NOTE: placeholder name
};

bool OpR2D_Obj5815e0::unknown5815e0()
{
	return !flag55 || (entity->unknown5c7fa0() / 5) % 3 == 0;
}

//==================================================================
// Item
//==================================================================

const Point &Item::unknown575920()
{
	if (state > 4)
	{
		return position;
	}
	else
	{
		return owner->getPosition();
	}
}

bool Item::unknown578b80(HProp prop)
{
	int value = record->unknown124;
	if (record->unknown128 < 7)
	{
		value = value * prop->unknown9b8f00()->unknownA8[record->unknown128] / 100 * prop->unknown9b8f00()->unknown60->values[record->unknown128] / 100;
	}
	return value * OpR2D_float08 >= prop->unknown45c630();
}

bool Item::unknown578c50(const Point &p)
{
	int value = record->unknown124;
	if (record->unknown128 < 7)
	{
		value = value * cells(p)->unknown9fcd80()->unknown50->values[record->unknown128] / 100;
	}
	return value * OpR2D_float08 >= cells(p)->getArmor();
}

bool Item::unknown578d00(HEntity target)
{
	int value = record->unknown124 * target->unknown5cb570(record->unknown128,true) / 100;
	return value * OpR2D_float08 >= target->unknown490840();
}

bool Item::unknown578d90(HItem item)
{
	if (state != 3)
	{
		return false;
	}
	if (!inRange(0x1a,record->unknown44,0x1c) || owner.isNull())
	{
		return false;
	}
	if (item.isNull())
	{
		item = owner->unknown5d5d40();
	}
	return item.isValid() && item != handle && item->unknown457880() != 0x1d && item->unknown457880() != 0x1e && !owner->unknown5dc440(handle);
}

int Item::unknown578e90(bool flag)
{
	if (!flag && !unknown578d90(HItem()))
	{
		return 0;
	}
	return (owner->unknown5d5d40()->unknown4580e0() - unknown4580e0()) / 10 + owner->unknown5d2150(0x6c,0) + 0x14;
}

int Item::unknown578f20(vector<Point> *cellList, int *range)
{
	int count;
	int radius;
	Point origin = unknown575920();
	radius = range ? *range : unknown457fb0();
	count = 0;
	Area area;
	cells.getArea(origin,radius,area);
	for (int x = area.min.x; x <= area.max.x; x++)
	{
		for (int y = area.min.y; y <= area.max.y; y++)
		{
			if (cells(x,y)->unknown45db50() && distanceCeil(origin,Point(x,y)) <= radius)
			{
				count += cells(x,y)->unknown45a6e0();
				if (cellList)
				{
					cellList->push_back(Point(x,y));
				}
			}
		}
	}
	return count;
}

int Item::unknown579050()
{
	int current = unknown578f20(NULL,NULL);
	int limit = record->unknown1a0[0x30 / 4] * 2;
	return minInt(current,limit);
}

float Item::unknown579090()
{
	int current = unknown578f20(NULL,NULL);
	int limit = record->unknown1a0[0x30 / 4] * 2;
	if (current < limit)
	{
		return (float)current / limit;
	}
	else
	{
		return 1;
	}
}

bool Item::unknown5790e0()
{
	return unknown44aec0() == 3 && unknown457880() < 0x19 && unknown9b4350()->unknown104 == 0 && unknown457f90() != 0xcf && unknown9b4350()->unknown94 != 2 && !getEffect(0x52) && !unknown577940();
}

void Item::unknown5797c0()
{
	setActivateOkayTurn(0);
	if (record->unknown457330(0x5f))
	{
		if (getEffect(0x5f))
		{
			getEffect(0x5f)->state = record->unknown457330(0x5f);
		}
		else
		{
			addEffect(new ItemEffect(effectTypes[0x5f],record->unknown457330(0x5f)));
		}
	}
}

void Item::unknown57bf30(int type, int state_)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i]->type->ID == type)
		{
			effects[i]->state = state_;
			return;
		}
	}
	addEffect(new ItemEffect(effectTypes[type],state_));
}

int Item::unknown57bff0(int type, int amount)
{
	ItemEffect *effect = getEffect(type);
	if (effect)
	{
		effect->state += amount;
		return effect->state;
	}
	else
	{
		effects.push_back(new ItemEffect(effectTypes[type],amount));
		return amount;
	}
}

void Item::unknown579c80()
{
	if (record->unknown278)
	{
		int index = 0;
		if (cells(position)->getProp().isValid() && cells(position)->getProp()->unknown9b8f00()->unknown78 && cells(position)->getProp()->unknown9b8f00()->unknown60->unknown50[index][*record->unknown278])
		{
			unknown454160(position,cells(position)->getProp()->unknown9b8f00()->unknown60->unknown50[index][*record->unknown278],0x12);
		}
		else
		{
			if (cells(position)->unknown9fcd80()->unknown50->unknown50[index][*record->unknown278])
			{
				unknown454160(position,cells(position)->unknown9fcd80()->unknown50->unknown50[index][*record->unknown278],0x12);
			}
		}
	}
}

void Item::unknown579e60(bool added, HItem item)
{
	if (owner == world->getPlayer())
	{
		if (state == 4)
		{
			if (inventory)
			{
				inventory->reopen(added ? 4 : 5,item);
				if (OpR2D_cefc90 == 1)
				{
					mapFine->addNewInventoryItemIndicator(handle);
				}
			}
		}
		else
		{
			if (added)
			{
				parts->unknown8979b0(handle,0,0);
			}
			else
			{
				parts->unknown897290(handle,0x20);
			}
			if ((OpR2D_d28d68 == 0 || OpR2D_d28d68 == 4) && inventory)
			{
				inventory->reopen(4,HItem());
			}
		}
	}
}

void Item::unknown579f50(bool a, bool b)
{
	if (state <= 4)
	{
		if (record->unknownEC)
		{
			unknown578800();
		}
		owner->unknown5dfbd0(handle);
		if (state <= 3)
		{
			world->unknown726bd0(handle);
		}
		setActive(false);
		if (a)
		{
			unknown579e60(true,HItem());
		}
		if (!b && state != 4 && record->unknownF0 != 0x2b)
		{
			int turn = owner->unknown5e2b50();
			if (OpR2D_d25450 && OpR2D_d254c4 == -1)
			{
				OpR2D_d254c4 = turn;
			}
		}
		if (OpR2D_cf462c == 0xb && owner->isPlayer() && !OpR2D_cefb5a && !owner->unknown5cb9b0(false))
		{
			owner->polymindUnpossess(true);
		}
		owner.clear();
	}
	else if (state == 5)
	{
		cells(position)->removeItem(handle);
	}
}

void Item::unknown57a0f0(const Point &p, int a, bool b)
{
	if (state <= 4 && owner->isPlayer())
	{
		world->unknown4657e0();
	}
	unknown579f50(b,false);
	state = 5;
	setActive(false);
	position = p;
	cells(position)->addItem(handle,a);
	if (a == 1)
	{
		unknown579c80();
	}
}

bool Item::unknown57a190(HEntity e, int state_, bool a, bool b)
{
	bool wasOnGround = state == 5;
	unknown579f50(a,b);
	state = state_;
	owner = e;
	owner->unknown5dfb60(handle);
	activeTurn = world->getTurn();
	if (owner->isPlayer() && unknown34 >= 0 && record->unknown48 != 5)
	{
		unknown34 = world->unknown464290();
		OpR2D_cf4944.push_back(handle);
	}
	if (state <= 3)
	{
		world->unknown726b70(handle);
	}
	if (state <= 4)
	{
		world->unknown464b90(handle);
	}
	if (record->unknown44 == 3)
	{
		world->unknown464c10(handle);
	}
	if (wasOnGround)
	{
		HItem item = handle;
		if (OpR2D_unknown4569a0(0x4b,owner,HEntity(),HProp(),handle,0,&record->name,unknown58,HEntity(),HProp(),handle,0) && !item.operator->())
		{
			return false;
		}
	}
	if (a)
	{
		unknown579e60(false,handle);
	}
	if (wasOnGround && record->unknown278)
	{
		if (cells(position)->getProp().isValid() && cells(position)->getProp()->unknown9b8f00()->unknown78 && cells(position)->getProp()->unknown9b8f00()->unknown60->unknown50[1][*record->unknown278])
		{
			unknown454160(position,cells(position)->getProp()->unknown9b8f00()->unknown60->unknown50[1][*record->unknown278],0x12);
		}
		else
		{
			if (cells(position)->unknown9fcd80()->unknown50->unknown50[1][*record->unknown278])
			{
				unknown454160(position,cells(position)->unknown9fcd80()->unknown50->unknown50[1][*record->unknown278],0x12);
			}
		}
	}
	return true;
}

void Item::unknown57a520(HProp prop, int flag)
{
	unknown579f50(flag != 0,false);
	switch (prop->unknown9b8f00()->unknownF8)
	{
	case 2:
		state = 6;
		position.assign(prop->getPosition());
		break;
	case 3:
		state = 7;
		position.assign(prop->getPosition());
		break;
	default:
		state = 10;
		position.fill(-1);
		break;
	}
}

void Item::unknown57a5d0(int state_, int flag)
{
	unknown579f50(flag != 0,false);
	state = state_;
	position.assign(Point(0));
}

void Item::unknown5798b0(int amount)
{
	opw8_increase(&unknown24,(int)(amount * OpR2D_tableBA6614[OpR2D_cf4718]),10);
}

void Item::unknown57beb0(ItemRecord *source, int amount)
{
	if (integrity == -1)
	{
		return;
	}
	int damage = amount == -1 ? source->unknown68 : amount;
	if (damage == -1)
	{
		integrity = 0;
	}
	else
	{
		opw8_decrease(&integrity,damage,0);
	}
	if (integrity <= 0)
	{
		unknown57dbe0(1,1,1,1);
	}
}

void Item::unknown57c090(OpQ5_U9d7de0 *type, bool flag)
{
	if (unknown58 == NULL)
	{
		OpW8_EntityEC *created = new OpW8_EntityEC();
		unknown58 = (PropEffects *)created;
	}
	else if (!flag && unknown58->unknown4563e0(type))
	{
		return;
	}
	unknown58->unknown456660(type);
}

bool Item::unknown57c110(string &name, bool flag)
{
	OpQ5_U9d7de0 *type;
	if (OpQ5_findByName(OpR2D_d2c408,name,type))
	{
		unknown57c090(type,flag);
		return true;
	}
	return false;
}

void Item::unknown57c160(const Point &p)
{
	unknown44 = world->getTurn() + 0x28;
	addEffect(new ItemEffect(effectTypes[0x4c],p.x));
	addEffect(new ItemEffect(effectTypes[0x4d],p.y));
}

//==================================================================
// record list helpers
//==================================================================

struct OpQ5_T9d86c0;	// NOTE: placeholder name
struct OpQ5_T9d0770	// NOTE: placeholder name
{
	int ID;
};
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
template <class T> void OpQ5_deleteObject(vector<T*> &v, int index);	// NOTE: placeholder name

struct OpR2D_Rec57f0b0	// NOTE: placeholder name
{
	vector<OpQ5_T9d86c0 *> records;	// NOTE: placeholder name

	OpR2D_Rec57f0b0(istream &stream);	// 0x57f0b0
};

OpR2D_Rec57f0b0::OpR2D_Rec57f0b0(istream &stream)
{
	OpQ5_readObjects(stream,records,0);
}

struct OpR2D_List57f140	// NOTE: placeholder name
{
	vector<OpQ5_T9d0770 *> records;	// NOTE: placeholder name

	OpQ5_T9d0770 *unknown57f140(OpQ5_T9d0770 *record);	// NOTE: placeholder name
};

OpQ5_T9d0770 *OpR2D_List57f140::unknown57f140(OpQ5_T9d0770 *record)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->ID == record->ID)
		{
			OpQ5_deleteObject(records,i);
			break;
		}
	}
	records.push_back(record);
	return record;
}
