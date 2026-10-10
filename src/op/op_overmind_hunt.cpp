// op_overmind_hunt: Overmind::spawnHunterParty (0x687520), sends a hunter squad (leader plus rolled escorts) after
// a target entity or area and returns the number of robots spawned (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	Point() throw();	// 0x453b40
};
struct OpOH_Pos	// NOTE: placeholder name (Pos)
{
	int x;
	int y;
	explicit OpOH_Pos(int v) throw();	// 0x409990
};
struct OpOH_Area	// NOTE: placeholder name (Area)
{
	OpOH_Area();	// 0x40b100
	OpOH_Area &set_40b130(const OpOH_Area &a);	// NOTE: placeholder name (folded with the copy ctor)
	int x1;
	int y1;
	int x2;
	int y2;
};

class OpOH_AI	// NOTE: placeholder name (EntityAI)
{
public:
	void setFollowEntity(class HEntity e, int flag);	// NOTE: placeholder name (0x5b2f80)
	void unknown459470(OpOH_Area &area);	// NOTE: placeholder name
	void setUnknown_451930(int value);	// NOTE: placeholder name (folded setter)
};
class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	OpOH_AI *getAI_45b590();	// NOTE: placeholder name
	void unknown5fdab0();	// NOTE: placeholder name
	bool isPlayer();	// 0x5c7600
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
extern EntityRecord *opOH_hunter_cefc08;	// NOTE: placeholder name

class OpOH_Grid	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getRect(const Point &p, int radius, OpOH_Area &out);	// NOTE: placeholder name (0x9b4430)
	OpOH_Area getArea();	// NOTE: placeholder name (0x9b4400)
};
extern OpOH_Grid opOH_cells_cfd44c;	// NOTE: placeholder name

class OpOH_World	// NOTE: placeholder name (BS at 0xcefc4c)
{
public:
	int unknown4638e0(int a, int b);	// NOTE: placeholder name
	int getTurn();	// 0x464270
	int unknown715730(int a);	// NOTE: placeholder name
	EntityRecord *selectRobotOfClass(int a, int b, bool c, bool d);	// NOTE: placeholder name
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
};
extern OpOH_World *opOH_world;	// NOTE: placeholder name

struct OpOH_MapNode { int pad00; int type; };	// NOTE: placeholder name
class OpOH_Handle	// NOTE: placeholder name
{
public:
	int ID;
	OpOH_MapNode *get23c();	// NOTE: placeholder name
	bool operator!=(OpOH_Handle other) const;	// NOTE: placeholder name (0x9b6510)
};
extern OpOH_Handle opOH_current_d1e888;	// NOTE: placeholder name
extern OpOH_Handle opOH_d1ebe0;	// NOTE: placeholder name
extern OpOH_Handle opOH_d1ebd8;	// NOTE: placeholder name

class OpOH_GameData	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	int getDepthIndex();	// NOTE: placeholder name (difficulty)
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
};
extern OpOH_GameData opOH_gameData;	// NOTE: placeholder name

template <class T> class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	OpR5h_WL();
	~OpR5h_WL();
	void add(T value, int weight);
	bool pick(T *out);
	void *getTotal_9b81d0();	// NOTE: placeholder name (folded getter)
	char pad[0x24];
};

class Party	// NOTE: placeholder layout
{
public:
	Party(int type, HEntity leader, int a, bool b, int c);
	char pad[0x38];
};

class RNG
{
public:
	bool chance(int percent);	// 0x406c90
};
extern RNG rng;

class OpOH_Stats	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern OpOH_Stats opOH_stats;	// NOTE: placeholder name

struct OpOH_EscortChance { int first; int second; int pad[2]; };	// NOTE: placeholder name
extern OpOH_EscortChance opOH_escortChance_b93f20[];	// NOTE: placeholder name
extern int opOH_escortWeights_b93e88[][3];	// NOTE: placeholder name
extern const int opOH_targetRadius_b91df8;	// NOTE: placeholder name (15)
extern const int opOH_partyDuration_b91e18;	// NOTE: placeholder name (75)
extern const char empty_b9573b[];	// NOTE: placeholder name ("")
extern const char empty_b9574b[];	// NOTE: placeholder name ("")

int stringToInt(const string &s);	// 0x405610
void OpV4c_Fn9d0690(int *value, int step, int low);	// NOTE: placeholder name
void opOH_eraseAt_9da940(vector<HEntity> &v, int index);	// NOTE: placeholder name (OpQ5_eraseAt)

class Overmind	// NOTE: placeholder layout
{
public:
	int spawnHunterParty(HEntity target, Point *area, bool alone);	// NOTE: placeholder name
	bool findDispatchExit(Point *out, bool allowVisible, int minDistance, bool ignoreProps, const OpOH_Pos &from, Point **access, bool preferProps, bool ignoreUsed);	// NOTE: placeholder name
	void unknown683e60(const Point &p, vector<vector<HEntity> > &out);	// NOTE: placeholder name
	bool addParty(Party *party, Point *access);	// NOTE: placeholder name

	char pad00[0x4c];
	int unknown4c;	// NOTE: placeholder name
	char pad50[0x128 - 0x50];
	int failedDispatches;	// +0x128, NOTE: placeholder name
};

int Overmind::spawnHunterParty(HEntity target, Point *area, bool alone)
{
	if (stringToInt(opOH_gameData.getEntryText("comConduitDisabled_g")) || unknown4c || opOH_world->unknown4638e0(0,3) == 2)
		return 0;
	bool changed = opOH_current_d1e888.get23c()->type == 0x22;
	vector<vector<HEntity> > vec2;
	if (changed)
		unknown683e60(area ? *area : target->getPosition(),vec2);
	bool ok = true;
	if (opOH_current_d1e888.get23c()->type == 0x21 && stringToInt(opOH_gameData.getEntryText("frgUfdAttacked_g")))
		ok = false;
	EntityRecord *element = opOH_hunter_cefc08;
	Point cx;
	Point *to = NULL;
	if (!changed && !findDispatchExit(&cx,true,0,ok,OpOH_Pos(-1),&to,false,false))
	{
		failedDispatches++;
		return 0;
	}
	else
		OpV4c_Fn9d0690(&failedDispatches,1,0);
	HEntity first;
	if (changed)
	{
		if (!vec2[element->index].empty())
		{
			first = vec2[element->index][0];
			opOH_eraseAt_9da940(vec2[element->index],0);
			first->unknown5fdab0();
		}
	}
	else
		first = opOH_world->placeEntity(element,cx,3,false,0x22,0xe,false);
	if (first.isNull())
		return 0;
	OpOH_Area edges;
	if (target.isValid())
		opOH_cells_cfd44c.getRect(target->getPosition(),opOH_targetRadius_b91df8,edges);
	else if (area)
		opOH_cells_cfd44c.getRect(*area,0xf,edges);
	else
		edges.set_40b130(opOH_cells_cfd44c.getArea());
	first->getAI_45b590()->unknown459470(edges);
	first->getAI_45b590()->setUnknown_451930(0);
	int count = 1;
	int multiplier = opOH_world->unknown715730(1);
	if (multiplier && !alone)
	{
		int num = 0;
		if (rng.chance(multiplier * opOH_escortChance_b93f20[opOH_gameData.getDepthIndex()].first))
			num++;
		if (num && rng.chance(multiplier * opOH_escortChance_b93f20[opOH_gameData.getDepthIndex()].second))
			num++;
		if (num)
		{
			OpR5h_WL<int> ranks;
			int v;
			for (v = 0; v < 3; v++)
				ranks.add(v,opOH_escortWeights_b93e88[opOH_gameData.getDepthIndex()][v]);
			if (!ranks.getTotal_9b81d0())
				goto done;
			int pick;
			EntityRecord *r1;
			for (int i = 0; i < num; i++)
			{
				ranks.pick(&pick);
				if (multiplier < 2 && pick <= 1)
					pick = 2;
				switch (pick)
				{
					case 0:
						r1 = opOH_world->selectRobotOfClass(1,0x16,false,false);
						break;
					case 1:
						r1 = opOH_world->selectRobotOfClass(1,0x17,false,false);
						break;
					case 2:
						r1 = opOH_world->selectRobotOfClass(1,0x19,false,false);
						break;
				}
				if (!r1)
					goto spawned;
				HEntity follower;
				if (changed)
				{
					if (!vec2[r1->index].empty())
					{
						follower = vec2[r1->index][0];
						opOH_eraseAt_9da940(vec2[r1->index],0);
						follower->unknown5fdab0();
					}
				}
				else
					follower = opOH_world->placeEntity(r1,cx,3,false,0x22,0xe,false);
				if (follower.isNull())
					break;
				follower->getAI_45b590()->setFollowEntity(first,0);
				count++;
			}
done:
			;
		}
	}
spawned:
	addParty(new Party(7,first,-1,target.isValid() && target->isPlayer(),opOH_world->getTurn() + opOH_partyDuration_b91e18),to);
	if (opOH_current_d1e888 != opOH_d1ebe0 && opOH_current_d1e888 != opOH_d1ebd8 && !(opOH_current_d1e888.get23c()->type == 0x21 && stringToInt(opOH_gameData.getEntryText("frgUfdAttacked_g"))))
	{
		opOH_stats.add4729d0(0x231,1,empty_b9573b,-1);
		opOH_stats.add4729d0(0x235,1,empty_b9574b,-1);
	}
	return count;
}
