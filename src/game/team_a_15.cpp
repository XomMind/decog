// team_a_15: record builders that snapshot props/entities into parallel vectors (0x460290, 0x460a00, 0x46e770).
// NOTE: all class and member names are placeholders (unique per function so call pairing stays unambiguous).
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int	x;
	int	y;
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class Prop_460290	// NOTE: placeholder name (the prop behind the handle)
{
public:
	Point &getPos_4184d0();			// NOTE: placeholder name
	int getType_44a630();			// NOTE: placeholder name
	XColor getColor_45c780();		// NOTE: placeholder name
	XColor getColor_454580();		// NOTE: placeholder name
};

class HProp_460290	// NOTE: placeholder name
{
public:
	int ID;
	Prop_460290 *operator->();	// NOTE: placeholder name
};

class PropRecords_460290	// NOTE: placeholder name
{
public:
	char pad0[0xc];
	vector<Point> positions;
	vector<int> types;
	vector<XColor> foreColors;
	vector<XColor> backColors;
	void add(HProp_460290 prop);
};

void PropRecords_460290::add(HProp_460290 prop)
{
	positions.push_back(prop->getPos_4184d0());
	types.push_back(prop->getType_44a630());
	foreColors.push_back(prop->getColor_45c780());
	backColors.push_back(prop->getColor_454580());
}

class Group_460a00	// NOTE: placeholder name
{
public:
	int getHeight_47bfa0();		// NOTE: placeholder name
};

class HGroup_460a00	// NOTE: placeholder name
{
public:
	int ID;
	Group_460a00 *operator->();	// NOTE: placeholder name
};

class Entity_460a00	// NOTE: placeholder name
{
public:
	void *getEffect_45ac40(int type);	// NOTE: placeholder name
	int getNestedField_457820();		// NOTE: placeholder name
	HGroup_460a00 getGroup_45a3f0();	// NOTE: placeholder name
	string &getName_416f40();			// NOTE: placeholder name
};

class HEntity_460a00	// NOTE: placeholder name
{
public:
	int ID;
	Entity_460a00 *operator->() const;	// NOTE: placeholder name
};

class EntityRecords_460a00	// NOTE: placeholder name
{
public:
	char pad0[8];
	vector<int> unknown8;
	vector<int> unknown18;
	vector<string> names;
	void add(HEntity_460a00 entity);
};

void EntityRecords_460a00::add(HEntity_460a00 entity)
{
	if (entity->getEffect_45ac40(0x39))
		return;
	unknown8.push_back(entity->getNestedField_457820());
	unknown18.push_back(entity->getGroup_45a3f0()->getHeight_47bfa0());
	names.push_back(entity->getName_416f40());
}

class HEntity
{
	int	ID;
};

struct OpS8a_Rec24;
template <class T> class OpS8a_Pool	// NOTE: placeholder name
{
public:
	T *release(HEntity e);
};
extern OpS8a_Pool<OpS8a_Rec24> pool_d21720;	// NOTE: placeholder name (0xd21720)
extern OpS8a_Pool<OpS8a_Rec24> pool_d2a298;	// NOTE: placeholder name (0xd2a298)
extern vector<HEntity> entities_cf4944;	// NOTE: placeholder name (0xcf4944)
bool OpU8a_containsEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d31e0)

class Info_46e770	// NOTE: placeholder name
{
public:
	int getHeight_46e770();	// NOTE: placeholder name
	int getValueB_46e770();	// NOTE: placeholder name
	int getValueC_46e770();	// NOTE: placeholder name
};

class Entity_46e770	// NOTE: placeholder name
{
public:
	Info_46e770 *getInfo_45b590();	// NOTE: placeholder name
	vector<HEntity> *getInventoryList_45ab00();	// NOTE: placeholder name
	bool isPlayer_46e770();	// NOTE: placeholder name
};

class Snapshot_46e770	// NOTE: placeholder name
{
public:
	int unknown0;
	Entity_46e770 *entity;
	int unknown8;
	int unknownC;
	int unknown10;
	vector<OpS8a_Rec24 *> items;
	vector<int> flags;
	void init(HEntity e, int value);
};

void Snapshot_46e770::init(HEntity e, int value)
{
	unknown0 = value;
	entity = (Entity_46e770 *)pool_d21720.release(e);
	unknown8 = entity->getInfo_45b590() ? entity->getInfo_45b590()->getHeight_46e770() : 0x22;
	unknownC = entity->getInfo_45b590() ? entity->getInfo_45b590()->getValueB_46e770() : 0xe;
	unknown10 = entity->getInfo_45b590() ? entity->getInfo_45b590()->getValueC_46e770() : 0;
	vector<HEntity> *inventory = entity->getInventoryList_45ab00();
	for (unsigned int i = 0; i < inventory->size(); i++)
	{
		if (entity->isPlayer_46e770())
			flags.push_back(OpU8a_containsEntity(entities_cf4944,(*inventory)[i]) ? 1 : 0);
		items.push_back(pool_d2a298.release((*inventory)[i]));
	}
	inventory->clear();
}
