// op_overmind_surgical: Overmind::unknown685a10 (0x685a10), sends an investigation squad (Q-series Zionites get
// surgical loadouts) after a target and returns the number of robots spawned (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	Point() throw();	// 0x453b40
	Point(const Point &p) throw();	// 0x46ca50
	int randomInRange_40c130();	// NOTE: placeholder name
};
struct OpOS_Pos	// NOTE: placeholder name (Pos)
{
	int x;
	int y;
	explicit OpOS_Pos(int v) throw();	// 0x409990
};
struct OpOS_Area	// NOTE: placeholder name (Area)
{
	OpOS_Area();	// 0x40b100
	int x1;
	int y1;
	int x2;
	int y2;
};

class OpOS_AI	// NOTE: placeholder name (EntityAI)
{
public:
	void setFollowEntity(class HEntity e, int flag);	// NOTE: placeholder name (0x5b2f80)
	void unknown459470(OpOS_Area &area);	// NOTE: placeholder name
	void setUnknown_451930(int value);	// NOTE: placeholder name (folded setter)
};
class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	OpOS_AI *getAI_45b590();	// NOTE: placeholder name
	void unknown5fdab0();	// NOTE: placeholder name
	bool isPlayer();	// 0x5c7600
	int getFaction();	// 0x45a2c0
	void unknown5de480(struct OpOS_ItemRecord *record);	// NOTE: placeholder name
	void unknown5deb40(int value);	// NOTE: placeholder name
	void unknown5ded70(int value);	// NOTE: placeholder name
};
class HEntity
{
public:
	int ID;
	HEntity();	// 0x9b6590
	Entity *operator->() const;	// 0x9b6570
	bool isValid() const;	// 0x9b65e0
	bool isNull() const;	// 0x9b65d0
};

struct EntityRecord	// NOTE: placeholder layout
{
	char pad00[0x28];
	int index;	// +0x28, NOTE: placeholder name
};

class OpOS_Grid	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getRect(const Point &p, int radius, OpOS_Area &out);	// NOTE: placeholder name (0x9b4430)
};
extern OpOS_Grid opOS_cells_cfd44c;	// NOTE: placeholder name

class OpOS_World	// NOTE: placeholder name (BS at 0xcefc4c)
{
public:
	int unknown4638e0(int a, int b);	// NOTE: placeholder name
	int getTurn();	// 0x464270
	EntityRecord *unknown6c5600(int a, int b, bool c, bool d);	// NOTE: placeholder name
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
};
extern OpOS_World *opOS_world;	// NOTE: placeholder name

struct OpOS_MapNode { int pad00; int type; };	// NOTE: placeholder name
class OpOS_Handle	// NOTE: placeholder name
{
public:
	int ID;
	OpOS_MapNode *get23c();	// NOTE: placeholder name
};
extern OpOS_Handle opOS_current_d1e888;	// NOTE: placeholder name

class OpOS_GameData	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	int unknown46f4e0();	// NOTE: placeholder name (difficulty)
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
};
extern OpOS_GameData opOS_gameData;	// NOTE: placeholder name

template <class T> class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	OpR5h_WL();
	~OpR5h_WL();
	void add(T value, int weight);
	bool pick(T *out);
	char pad[0x24];
};

class Party	// NOTE: placeholder layout
{
public:
	Party(int type, HEntity leader, int a, bool b, int c);
	char pad[0x38];
};

class OpOS_Stats	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern OpOS_Stats opOS_stats;	// NOTE: placeholder name


int stringToInt(const string &s);	// 0x405610
void OpV4c_Fn9d0690(int *value, int step, int low);	// NOTE: placeholder name
void opOS_eraseAt_9da940(vector<HEntity> &v, int index);	// NOTE: placeholder name (OpQ5_eraseAt)

struct OpOS_ItemRecord;	// NOTE: placeholder name
extern vector<OpOS_ItemRecord *> opOS_itemRecords_d2d1c4;	// NOTE: placeholder name
extern int opOS_kindWeights_b93738[][2];	// NOTE: placeholder name
extern Point opOS_squadSizes_d29310[][2];	// NOTE: placeholder name
extern bool opOS_d1eb99;	// NOTE: placeholder name
extern const int opOS_targetRadius_b91df4;	// NOTE: placeholder name (15)
extern const int opOS_partyDuration_b91e00;	// NOTE: placeholder name (150)
extern const char empty_b95727[];	// NOTE: placeholder name ("")
extern const char empty_b9572f[];	// NOTE: placeholder name ("")
void logError(string location, string message);	// 0x404f10

class Overmind	// NOTE: placeholder layout
{
public:
	int unknown685a10(HEntity target, Point *area);	// NOTE: placeholder name
	bool unknown683500(Point *out, bool allowVisible, int minDistance, bool ignoreProps, const OpOS_Pos &from, Point **access, bool preferProps, bool ignoreUsed);	// NOTE: placeholder name
	void unknown683e60(const Point &p, vector<vector<HEntity> > &out);	// NOTE: placeholder name
	bool unknown6827d0(Party *party, Point *access);	// NOTE: placeholder name
	void loadZWeaponList(vector<int> &out, int level);
	void spawnSurgicalParty(vector<int> &out, vector<int> &records);

	char pad00[0x4c];
	int unknown4c;	// NOTE: placeholder name
	char pad50[0x90 - 0x50];
	void *surgical;	// +0x90, NOTE: placeholder name
	char pad94[0x128 - 0x94];
	int failedDispatches;	// +0x128, NOTE: placeholder name
};

int Overmind::unknown685a10(HEntity target, Point *area)
{
	if (stringToInt(opOS_gameData.getEntryText("comConduitDisabled_g")) || unknown4c || opOS_world->unknown4638e0(0,3) == 2)
		return 0;
	bool ok = opOS_current_d1e888.get23c()->type == 0x22;
	vector<vector<HEntity> > events;
	if (ok)
		unknown683e60(area ? *area : target->getPosition(),events);
	OpR5h_WL<int> tags;
	for (int i = 0; i < 2; i++)
	{
		int weight = opOS_kindWeights_b93738[opOS_gameData.unknown46f4e0()][i];
		if (weight && i == 1 && opOS_d1eb99)
			weight /= 2;
		tags.add(i,weight);
	}
	int tag;
	do
		tags.pick(&tag);
	while (tag == 1 && (!surgical || ok));
	int value = opOS_squadSizes_d29310[opOS_gameData.unknown46f4e0()][tag].randomInRange_40c130() - 1;
	EntityRecord *first;
	EntityRecord *element;
	switch (tag)
	{
		case 0:
			first = opOS_world->unknown6c5600(1,0x19,false,false);
			element = NULL;
			break;
		case 1:
			first = opOS_world->unknown6c5600(1,0x1b,false,false);
			element = NULL;
			break;
	}
	if (!first)
		return 0;
	if (!element)
		element = first;
	Point pt;
	Point *prev = NULL;
	if (!ok && !unknown683500(&pt,true,0,true,OpOS_Pos(-1),&prev,false,false))
	{
		failedDispatches++;
		return 0;
	}
	else
		OpV4c_Fn9d0690(&failedDispatches,1,0);
	int entityCount = 0;
	vector<HEntity> xx;
	HEntity cur;
	if (ok)
	{
		if (!events[first->index].empty())
		{
			cur = events[first->index][0];
			opOS_eraseAt_9da940(events[first->index],0);
			cur->unknown5fdab0();
		}
	}
	else
		cur = opOS_world->placeEntity(first,pt,3,false,0x22,0xe,false);
	if (cur.isValid())
	{
		entityCount++;
		Point center(area ? *area : target->getPosition());
		OpOS_Area region;
		opOS_cells_cfd44c.getRect(center,opOS_targetRadius_b91df4,region);
		cur->getAI_45b590()->unknown459470(region);
		cur->getAI_45b590()->setUnknown_451930(0);
		if (cur->getFaction() == 0x1b)
			xx.push_back(cur);
		while (value)
		{
			HEntity follower;
			if (ok)
			{
				if (!events[element->index].empty())
				{
					follower = events[element->index][0];
					opOS_eraseAt_9da940(events[element->index],0);
					follower->unknown5fdab0();
				}
			}
			else
				follower = opOS_world->placeEntity(element,pt,3,false,0x22,0xe,false);
			if (follower.isNull())
				break;
			follower->getAI_45b590()->setFollowEntity(cur,0);
			follower->getAI_45b590()->setUnknown_451930(0);
			if (follower->getFaction() == 0x1b)
				xx.push_back(follower);
			value--;
			entityCount++;
		}
		unknown6827d0(new Party(5,cur,-1,target.isValid() && target->isPlayer(),opOS_world->getTurn() + opOS_partyDuration_b91e00),prev);
	}
	if (!xx.empty())
	{
		if (!surgical)
		{
			logError("Overmind::spawnSurgicalParty()","No analysis on which to base CLASS_QSERIES");
			return entityCount;
		}
		for (unsigned int i = 0; i < xx.size(); i++)
		{
			vector<int> weapons;
			loadZWeaponList(weapons,opOS_gameData.unknown46f4e0());
			vector<int> parts;
			spawnSurgicalParty(parts,weapons);
			for (unsigned int j = 0; j < weapons.size(); j++)
				xx[i]->unknown5de480(opOS_itemRecords_d2d1c4[weapons[j]]);
			for (unsigned int k = 0; k < parts.size(); k++)
				xx[i]->unknown5de480(opOS_itemRecords_d2d1c4[parts[k]]);
			xx[i]->unknown5deb40(10000);
			xx[i]->unknown5ded70(10000);
		}
	}
	opOS_stats.add4729d0(0x231,1,empty_b95727,-1);
	opOS_stats.add4729d0(0x233,1,empty_b9572f,-1);
	return entityCount;
}
