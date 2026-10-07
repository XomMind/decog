// team_d_21: map view mark creation (0x819870, 0x8196c0).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
// The mark constructors are defined here as trivial placeholders: the exe's new-expressions keep
// their result temporaries but have no exception states, which VS2010 /GL only produces when LTCG
// can prove the constructor cannot throw (it must be defined in the link, not stubbed).
#include <vector>
using namespace std;

class Entity
{
public:
	int getFaction();	// 0x45a2c0
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	Entity *operator->() const;
};

class EntityMark	// NOTE: placeholder name (OpW5_EntityMark, 0x10 bytes, constructor 0x49a340)
{
public:
	EntityMark(HEntity e);
	int pad[4];
};

EntityMark::EntityMark(HEntity e)	// NOTE: placeholder body
{
	pad[0] = *(int *)&e;
}

struct Point
{
	int x;
	int y;
};

class PosMark2	// NOTE: placeholder name (OpW5_PosMark2, 0x10 bytes, constructor 0x49a3c0)
{
public:
	PosMark2(const Point &p, int range);
	int pad[4];
};

PosMark2::PosMark2(const Point &p, int range)	// NOTE: placeholder body
{
	pad[0] = p.x;
	pad[1] = range;
}

extern int flag_d28e40;	// NOTE: placeholder name
void playSound_4541b0(int id, int a, int b);	// NOTE: placeholder name

class Map
{
public:
	int unknown4642b0();				// NOTE: placeholder name
	vector<HEntity> *unknown4636b0();	// NOTE: placeholder name
};
extern Map *world;

class PlayerData	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool isSlotEmpty(int id);		// NOTE: placeholder name (0x46de40)
	void unknown77fbc0(int id);		// NOTE: placeholder name
};
extern PlayerData playerData_cf45d8;	// NOTE: placeholder name

class OpD_MapView22	// NOTE: placeholder name (MapView)
{
public:
	void unknown8196c0(HEntity e);	// NOTE: placeholder name
	void unknown819870(const Point &p, int range);	// NOTE: placeholder name
	void unknown49ac90(const Point &p, bool a, int b);	// NOTE: placeholder name

	char pad[0x31c];
	vector<EntityMark *> marks;	// +0x31c, NOTE: placeholder name
	char pad32c[0x35c - 0x32c];
	vector<PosMark2 *> posMarks;	// +0x35c, NOTE: placeholder name
};

void OpD_MapView22::unknown8196c0(HEntity e)
{
	marks.push_back(new EntityMark(e));
	if (world->unknown4642b0() <= 5 && playerData_cf45d8.isSlotEmpty(0x3f) && !world->unknown4636b0()->empty())
	{
		for (unsigned int i = 0; i < world->unknown4636b0()->size(); i++)
		{
			if ((*world->unknown4636b0())[i].operator->() && (*world->unknown4636b0())[i]->getFaction() == 9)
			{
				playerData_cf45d8.unknown77fbc0(0x3f);
				break;
			}
		}
	}
}

void OpD_MapView22::unknown819870(const Point &p, int range)
{
	posMarks.push_back(new PosMark2(p,range));
	unknown49ac90(p,flag_d28e40 != 0,0);
	playSound_4541b0(0x47,0,0);
}
