// op_ai_ctor: EntityAI::EntityAI (0x57f6a0) (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts; member names follow claude_a_ai.cpp where known.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;
	Point() throw();	// 0x453b40
	Point(int v) throw();	// 0x409990
	Point(int x_, int y_) throw();	// 0x46ca20
	Point(const Point &p) throw();	// 0x46ca50
	Point &operator=(const Point &p) throw();	// NOTE: folded with the copy ctor (0x46ca50)
	void set(int x_, int y_) throw();	// 0x40a010
	void setBoth_409ff0(int v) throw();	// NOTE: placeholder name
};

struct OpEA_Segment	// NOTE: placeholder name (two points; ctor 0x40b100)
{
	OpEA_Segment() throw();
	Point a;
	Point b;
};

class OpEA_Handle	// NOTE: placeholder name (generic object handle)
{
	int ID;
public:
	OpEA_Handle() throw();	// 0x9b6590
	void reset() throw();	// 0x9b7270
};

struct OpEA_EntityRecord	// NOTE: placeholder name
{
	int pad00;
	string name;	// +0x04
	int unknown20;
	int unknown24;
	int type;	// +0x28
	char pad2c[0x48 - 0x2c];
	int unknown48;
	char pad4c[0x7c - 0x4c];
	int unknown7c;
	char pad80[0x15c - 0x80];
	bool unknown15c;
};

struct OpEA_Record68	// NOTE: placeholder name
{
	char pad00[0x68];
	int unknown68;
};

class Entity
{
public:
	char pad00[8];
	OpEA_EntityRecord *record;	// +0x08
	bool unknown5c7f70();	// NOTE: placeholder name
	bool unknown5d1280(int a);	// NOTE: placeholder name
	OpEA_Record68 *getRecord_pingsize();	// NOTE: placeholder name (folded getter)
	const Point &getPosition();	// 0x45a4a0
	bool unknown5cabd0();	// NOTE: placeholder name
	bool unknown5cac90();	// NOTE: placeholder name
	int unknown5cad50();	// NOTE: placeholder name
	const string &getName();	// 0x45a280
};

class HEntity
{
	int ID;
public:
	Entity *operator->() const;	// 0x9b6570
};

class OpEA_Map	// NOTE: placeholder name (BS)
{
public:
	HEntity getPlayer();	// 0x4630f0
	int getTurn();	// 0x464270
	int unknown74b2c0(const Point &p);	// NOTE: placeholder name
};
extern OpEA_Map *opEA_map;	// NOTE: placeholder name (0xcefc4c)

struct OpEA_Location	// NOTE: placeholder name
{
	int pad00;
	int unknown04;
};
class OpEA_HLocation	// NOTE: placeholder name
{
	int ID;
public:
	OpEA_Location *get23c();	// NOTE: placeholder name
};
extern OpEA_HLocation opEA_location;	// NOTE: placeholder name (0xd1e888)

class OpEA_Cells	// NOTE: placeholder name (0xcfd44c)
{
public:
	int getWidth();	// NOTE: placeholder name
	int getHeight();	// NOTE: placeholder name
	void getRect(const Point &p, int radius, OpEA_Segment &out);	// NOTE: placeholder name (0x9b4430)
};
extern OpEA_Cells opEA_cells;	// NOTE: placeholder name

int ops7_clamp_9cdc80(int low, int value, int high);	// NOTE: placeholder name

class AIOrder	// NOTE: placeholder name (0x458bd0)
{
public:
	AIOrder(int type, HEntity target, const Point &pos);
	char pad00[0x1c];
};

extern int opEA_behaviorByType_bb9ed0[];	// NOTE: placeholder name
extern int opEA_modeByType_bba058[];	// NOTE: placeholder name
extern int opEA_bba680[];	// NOTE: placeholder name
extern int opEA_bba1e0[];	// NOTE: placeholder name
extern int opEA_rangeByType_bba370[];	// NOTE: placeholder name

class EntityAI
{
public:
	EntityAI(HEntity owner_, int behavior_, int mode_);
	void unknown5b2d10();	// NOTE: placeholder name

	HEntity owner;
	int behavior;	// NOTE: placeholder name
	int mode;	// NOTE: placeholder name
	int unknown0c;
	Point unknown10;
	Point unknown18;
	OpEA_Handle unknown20;
	vector<Point> line;	// +0x24
	int unknown34;
	int unknown38;
	int unknown3c;
	OpEA_Handle unknown40;
	int unknown44;
	int unknown48;
	int unknown4c;
	OpEA_Handle unknown50;
	bool unknown54;
	bool unknown55;
	bool unknown56;
	OpEA_Handle unknown58;
	bool unknown5c;
	int unknown60;
	int unknown64;
	int unknown68;
	vector<Point> path;	// +0x6c
	bool unknown7c;
	OpEA_Segment area;	// +0x80
	vector<Point> candidates;	// +0x90
	int unknownA0;
	OpEA_Segment unknownA4;
	OpEA_Handle unknownB4;
	OpEA_Handle unknownB8;
	int unknownBC;
	int unknownC0;
	int unknownC4;
	int unknownC8;
	int unknownCC;
	int unknownD0;
	OpEA_Handle unknownD4;
	int unknownD8;
	vector<int> remembered;	// +0xdc
	int rememberedTurn;	// +0xec
	vector<void *> targets;	// +0xf0
	int unknown100;
	int unknown104;
	int unknown108;
	int unknown10C;
	bool unknown110;
	AIOrder *order;	// +0x114
	char *unknown118;
	void *part;	// +0x11c
	vector<void *> objects;	// +0x120
};

EntityAI::EntityAI(HEntity owner_, int behavior_, int mode_)
	: owner			(owner_)
	, behavior		(owner->unknown5c7f70() ? 3 : (behavior_ == 0x22 ? opEA_behaviorByType_bb9ed0[owner->record->type] : behavior_))
	, mode			(mode_ == 0xe ? opEA_modeByType_bba058[owner->record->type] : mode_)
	, unknown0c		(0)
	, unknown34		(0)
	, unknown38		(0)
	, unknown3c		(0)
	, unknown44		(0)
	, unknown48		(opEA_bba680[owner->record->type])
	, unknown4c		(opEA_bba1e0[owner->record->type])
	, unknown54		(false)
	, unknown55		(false)
	, unknown56		(false)
	, unknown64		(0)
	, unknownBC		(0)
	, unknownC0		(2)
	, unknownC4		(0)
	, unknownC8		(0)
	, unknownCC		(0)
	, unknownD0		(owner->getRecord_pingsize()->unknown68 * 300 + 500)
	, unknownD8		(owner->record->unknown7c)
	, rememberedTurn	(0)
	, unknown100	(0)
	, unknown104	(0)
	, unknown108	(0)
	, unknown10C	(0)
	, unknown110	(false)
	, order			(owner->unknown5c7f70() ? new AIOrder(owner->unknown5d1280(1) ? 0 : 2,opEA_map->getPlayer(),Point(-1)) : NULL)
	, unknown118	(NULL)
	, part			(NULL)
{
	unknown10.x = -1;
	unknown18.x = -1;
	unknown20.reset();
	unknown58.reset();
	unknown5c = false;
	unknown60 = 0;
	unknown68 = 0;
	unknown7c = false;
	switch (behavior)
	{
	case 1:
		path.push_back(owner->getPosition());
		break;
		break;
	case 5:
		unknownCC = -1;
		break;
	case 0xe:
		if (opEA_location.get23c()->unknown04 == 0)
			behavior = 0;
		else
		{
			path.assign(6,Point(-1));
			Point pos(owner->getPosition());
			path[1] = Point(ops7_clamp_9cdc80(0,pos.x - 10,opEA_cells.getWidth() - 20),ops7_clamp_9cdc80(0,pos.y - 10,opEA_cells.getHeight() - 20));
			path[0] = opEA_map->unknown74b2c0(path[1]);
			path[4] = rng.chance(25) ? -1 : rng.rangeInt(500.0f,1500.0f);
			path[5].setBoth_409ff0(0);
		}
		break;
	}
	if (owner->record->type == 0x1c && owner->record->unknown24 != 2 && owner->unknown5cabd0())
	{
		if (owner->unknown5cad50())
			unknownCC = opEA_map->getTurn() + 1;
		else if (behavior == 1)
			unknownCC = 1;
	}
	if (owner->record->unknown48 == 0x2c && owner->unknown5cac90())
	{
		if (owner->unknown5cad50())
			unknownCC = opEA_map->getTurn() + 1;
		else
			unknownCC = 1;
	}
	if (owner->unknown5c7f70())
	{
		switch (mode)
		{
		case 5:
			mode = 1;
			break;
		case 3:
			mode = owner->record->unknown15c ? !!(owner->record->name == "Swarm Drone") + 8 : 1;
			break;
		case 7:
			mode = 8;
			break;
		}
	}
	else if (mode == 3)
	{
		if (owner->record->name == "Swarm Drone")
			mode = 9;
		else if (owner->record->unknown15c)
			mode = 8;
	}
	else if (mode == 1)
	{
		if (owner->record->name == "A-27 Freighter" || owner->record->name == "Sauler")
			mode = 2;
	}
	switch (mode)
	{
	case 7:
		unknown34 = 1;
	}
	if (owner->getName() == "Tracker")
		unknown34 = 1;
	if (opEA_rangeByType_bba370[owner->record->type] == 0)
	{
		area.a.set(0,0);
		area.b.set(opEA_cells.getWidth() - 1,opEA_cells.getHeight() - 1);
	}
	else
		opEA_cells.getRect(owner->getPosition(),opEA_rangeByType_bba370[owner->record->type],area);
	unknownA0 = 0;
	unknownA4.a.x = -1;
	unknownB4.reset();
	unknown5b2d10();
}
