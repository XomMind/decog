// op_t2: misc functions in 0x4c7000-0x5dc000
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	Point &unknown4099f0(const Point &a, const Point &b);	// NOTE: placeholder name (0x4099f0)
	Point unknown409b30(const Point &other);	// NOTE: placeholder name (0x409b30)
};

class OpT2_Location	// NOTE: placeholder name
{
public:
	int pad0;
	int type;	// +0x04
};

class OpT2_HLocation	// NOTE: placeholder name
{
public:
	int ID;
	OpT2_Location *operator->() const;	// 0x9b7910
};
extern OpT2_HLocation opT2_location;	// NOTE: placeholder name (0xd1e888)

class OpT2_Options	// NOTE: placeholder name
{
public:
	bool unknown46f4b0(int index);	// NOTE: placeholder name (0x46f4b0)
};
extern OpT2_Options opT2_options;	// NOTE: placeholder name (0xd1e860)

bool opT2_unknown5714a0(int index)	// NOTE: placeholder name
{
	if (index >= 4)
	{
		return opT2_location->type == index - 4;
	}
	else
	{
		switch (index)
		{
			case 0:
				return false;
			case 1:
				return true;
			case 2:
				return opT2_options.unknown46f4b0(1);
			case 3:
				return opT2_options.unknown46f4b0(2);
		}
		return false;
	}
}

//--------------------------------------------------------------

//--------------------------------------------------------------

class OpT2_Rec4ccdc0	// NOTE: placeholder name
{
public:
	vector<Point> a;	// +0x00
	vector<unsigned int> b;	// +0x10
	vector<Point> c;	// +0x20
	vector<unsigned int> d;	// +0x30

	~OpT2_Rec4ccdc0();	// 0x4ccdc0
};

OpT2_Rec4ccdc0::~OpT2_Rec4ccdc0()
{
}

//--------------------------------------------------------------

class OpT2_HEntity	// NOTE: placeholder name
{
public:
	int ID;
};

class OpT2_TurnRec;	// NOTE: placeholder name

class OpT2_Inventory	// NOTE: placeholder name
{
public:
	vector<OpT2_TurnRec *> *unknown518c00(int type, OpT2_HEntity e, OpT2_HEntity a, OpT2_HEntity b, OpT2_HEntity c, int d, vector<OpT2_TurnRec *> *f, int g, int h, int i);	// NOTE: placeholder name (0x518c00)
	vector<OpT2_TurnRec *> *unknown51ca20(vector<int> *types, OpT2_HEntity e, OpT2_HEntity a, OpT2_HEntity b, OpT2_HEntity c, int d, vector<OpT2_TurnRec *> *f, int g, int h, int i);	// NOTE: placeholder name (0x51ca20)
};

vector<OpT2_TurnRec *> *OpT2_Inventory::unknown51ca20(vector<int> *types, OpT2_HEntity e, OpT2_HEntity a, OpT2_HEntity b, OpT2_HEntity c, int d, vector<OpT2_TurnRec *> *f, int g, int h, int i)
{
	for (unsigned int n = 0; n < types->size(); n++)
	{
		f = unknown518c00((*types)[n],e,a,b,c,d,f,g,h,i);
	}
	return f;
}

//--------------------------------------------------------------

//--------------------------------------------------------------

extern int opT2_caf148;	// NOTE: placeholder name (0xcaf148)
void opr2c_playEffect_55ca10(int id, const Point &from, Point *p1);	// NOTE: placeholder name (0x55ca10)

void opT2_playEffectPath_55ca70(int id, vector<Point> &path, Point *origin)	// NOTE: placeholder name
{
	if (id != opT2_caf148)
	{
		for (int i = path.size() - 1; i >= 0; i--)
		{
			Point offset;
			opr2c_playEffect_55ca10(id,path[i],origin != NULL ? &offset.unknown4099f0(*origin,path[i].unknown409b30(path[0])) : NULL);
		}
	}
}

//--------------------------------------------------------------

struct OpT2_ItemData	// NOTE: placeholder name
{
	char pad0[0x50];
	int m50;	// +0x50
	char pad54[0xa4 - 0x54];
	int ma4;	// +0xa4
};

class OpT2_HItem;

class OpT2_Item	// NOTE: placeholder name
{
public:
	int pad0[2];
	OpT2_ItemData *m8;	// +0x08

	bool unknown575850(OpT2_HItem other);	// NOTE: placeholder name (0x575850)
};

class OpT2_HItem	// NOTE: placeholder name
{
public:
	int ID;
	OpT2_Item *operator->() const;	// 0x9b65b0
};

bool OpT2_Item::unknown575850(OpT2_HItem other)
{
	if (other->m8->m50 == m8->m50)
	{
		if (other->m8->ma4 == m8->ma4)
		{
			return true;
		}
		else
		{
			return m8->ma4 > other->m8->ma4;
		}
	}
	else
	{
		return m8->m50 < other->m8->m50;
	}
}

//--------------------------------------------------------------

struct OpT2_SoundRef	// NOTE: placeholder name
{
	char pad00[0x38];
	int sound;	// +0x38
};
extern int opT2_caf144;	// NOTE: placeholder name (0xcaf144)
bool opr2c_playSoundRef_55cb90(OpT2_SoundRef *ref, const Point &pos);	// NOTE: placeholder name (0x55cb90)

class OpT2_Entity	// NOTE: placeholder name
{
public:
	const Point &getPosition();	// 0x45a4a0
};

class OpT2_HEntity2	// NOTE: placeholder name
{
public:
	int ID;
	OpT2_Entity *operator->() const;	// 0x9b6570
};

class OpT2_Map	// NOTE: placeholder name (0xcefc4c)
{
public:
	OpT2_HEntity2 getPlayer();	// 0x4630f0
};
extern OpT2_Map *opT2_world;	// NOTE: placeholder name (0xcefc4c)

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)

bool opT2_playSoundNearest_55cc00(OpT2_SoundRef *ref, vector<Point> &points)	// NOTE: placeholder name
{
	if (ref->sound == opT2_caf144 || points.empty())
	{
		return false;
	}
	int best = 0;
	int distance;
	int bestDistance = OpQ1_distanceCeil_40a3f0(opT2_world->getPlayer()->getPosition(),points[best]);
	for (unsigned int i = 1; i < points.size(); i++)
	{
		distance = OpQ1_distanceCeil_40a3f0(opT2_world->getPlayer()->getPosition(),points[i]);
		if (distance < bestDistance)
		{
			bestDistance = distance;
			best = i;
		}
	}
	return opr2c_playSoundRef_55cb90(ref,points[best]);
}
