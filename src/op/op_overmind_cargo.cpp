// op_overmind_cargo: Overmind::spawnCargoDispatch_68aec0 (0x68aec0), spawns the A-27 Freighter convoy with its
// cargo (optionally PL-3XN's Ring of Power), loot and escorts (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	Point &set_46ca50(const Point &p) throw();	// NOTE: placeholder name (folded with the copy ctor)
	int randomInRange_40c130();	// NOTE: placeholder name
};
struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_) throw();	// 0x46ca20
	void shift_40bf50(int d);	// NOTE: placeholder name
};

struct OpCD_ItemRecord	// NOTE: placeholder name
{
	char pad00[0x4c];
	int mass;	// +0x4c, NOTE: placeholder name
};
class Item
{
public:
	int getNestedField_4578c0();	// NOTE: placeholder name
	void remove57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown57c110(const string &tag, int value);	// NOTE: placeholder name
};
class HItem
{
public:
	int ID;
	HItem();	// 0x9b6590
	bool isValid() const;	// 0x9b65e0
	Item *get224() const;	// NOTE: placeholder name
};

class OpCD_AI	// NOTE: placeholder name (EntityAI)
{
public:
	void setFollowEntity(class HEntity e, int flag);	// NOTE: placeholder name (0x5b2f80)
	void unknown4593b0(Point &p);	// NOTE: placeholder name
	void setField_4505b0(int value);	// NOTE: placeholder name
};
class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	OpCD_AI *getAI_45b590();	// NOTE: placeholder name
	int unknown45a810();	// NOTE: placeholder name
	int unknown5c8e20(int a);	// NOTE: placeholder name
	int unknown5ca210();	// NOTE: placeholder name
	void unknown5cb830(vector<HItem> &out);	// NOTE: placeholder name
	HItem unknown5d2380(int type);	// NOTE: placeholder name
};
class HEntity
{
public:
	int ID;
	HEntity();	// 0x9b6590
	Entity *operator->() const;	// 0x9b6570
	bool isValid() const;	// 0x9b65e0
};

struct EntityRecord;
extern EntityRecord *opCD_carrier_cefc08;	// NOTE: placeholder name

class OpCD_World	// NOTE: placeholder name (BS at 0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
	HEntity unknown6c5dc0(const string &name, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name
	EntityRecord *selectRobotOfClass(int a, int b, bool c, bool d);	// NOTE: placeholder name
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
	HItem unknown6c51d0(int record, HEntity owner, int a, int b);	// NOTE: placeholder name
	void unknown464f60(HItem item);	// NOTE: placeholder name
};
extern OpCD_World *opCD_world;	// NOTE: placeholder name

struct OpCD_MapNode { int pad00; int type; int depth; };	// NOTE: placeholder name
class OpCD_Handle	// NOTE: placeholder name
{
public:
	int ID;
	OpCD_Handle();	// 0x9b6590
	OpCD_MapNode *get23c();	// NOTE: placeholder name
};
extern OpCD_Handle opCD_current_d1e888;	// NOTE: placeholder name
extern int opCD_d1e884;	// NOTE: placeholder name
bool OpC_findNode_470180(int type, int a, int b, OpCD_Handle *out);	// NOTE: placeholder name

class OpCD_GameData	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	int getDepthIndex();	// NOTE: placeholder name (difficulty)
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
};
extern OpCD_GameData opCD_gameData;	// NOTE: placeholder name

struct OpCD_Difficulty	// NOTE: placeholder name (0x28-byte records at 0xb939b0)
{
	int pad00[4];
	int cargoChance;	// +0x10
	int lootChance;	// +0x14
	int pad18[4];
};
extern OpCD_Difficulty opCD_difficulty_b939b0[];	// NOTE: placeholder name

template <class T> class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	T &pick();
};
extern OpR5h_WL<int> opCD_loot_d31700;	// NOTE: placeholder name

class Party	// NOTE: placeholder layout
{
public:
	Party(int type, HEntity leader, int a, int b, int c);
	char pad[0x38];
};

class RNG
{
public:
	bool chance(int percent);	// 0x406c90
};
extern RNG rng;

class OpCD_PlayerData	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	bool isSlotEmpty(int id);	// NOTE: placeholder name
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern OpCD_PlayerData opCD_playerData;	// NOTE: placeholder name

extern vector<OpCD_ItemRecord *> opCD_itemRecords_d2d1c4;	// NOTE: placeholder name
extern Point opCD_d30348;	// NOTE: placeholder name
extern Point opCD_d21760;	// NOTE: placeholder name
extern int opCD_escortCounts_ba6608[];	// NOTE: placeholder name
extern int opCD_cf4718;	// NOTE: placeholder name

int stringToInt(const string &s);	// 0x405610
void logWarning(string location, string message);	// 0x404e50
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)
string OpU8a_randomString(vector<string> &v);	// NOTE: placeholder name
template <class T> bool OpQ5_findByName(vector<T *> &list, const string &name, T *&out);	// NOTE: placeholder name
HItem popRandom9d8030(vector<HItem> &v);	// NOTE: placeholder name (0x9d8030; the config row names the OpS8c_Handle instantiation)

class Overmind	// NOTE: placeholder layout
{
public:
	int spawnCargoDispatch_68aec0();
	void unknown6901e0(HEntity leader, int flag, int a, int b, const Pos &p, int c, int d);	// NOTE: placeholder name
	bool addParty(Party *party, Point *access);	// NOTE: placeholder name

	char pad00[0xbc];
	int unknownbc;	// +0xbc, NOTE: placeholder name
	Point unknownc0;	// +0xc0
	Point unknownc8;	// +0xc8
	int unknownd0;
	HEntity convoy;	// +0xd4, NOTE: placeholder name
	vector<HEntity> escorts;	// +0xd8, NOTE: placeholder name
	char pade8[0xf8 - 0xe8];
	Point convoyPos;	// +0xf8, NOTE: placeholder name
};

int Overmind::spawnCargoDispatch_68aec0()
{
	int count = 0;
	HEntity freighter = opCD_world->unknown6c5dc0("A-27 Freighter",unknownc0,3,false,0x14,0xe,false);
	if (freighter.isValid())
	{
		count++;
		freighter->getAI_45b590()->unknown4593b0(unknownc8);
		convoy = freighter;
		convoyPos.set_46ca50(convoy->getPosition());
		int level = opCD_gameData.getDepthIndex() + 1;
		Pos xx(level,level + 2);
		if (xx.y > 9)
			xx.shift_40bf50(9 - xx.y);
		unknown6901e0(convoy,1,opCD_d30348.randomInRange_40c130(),opCD_d21760.randomInRange_40c130(),xx,1,0x2a);
		bool visible = false;
		OpCD_Handle cur;
		OpCD_Handle prev;
		if (OpC_findNode_470180(0xb,-1,opCD_d1e884,&cur) && OpC_findNode_470180(0x1c,-1,opCD_d1e884,&prev) && OpT8b_Fn9daf80(prev.get23c()->depth,opCD_current_d1e888.get23c()->depth,cur.get23c()->depth - 2) && !stringToInt(opCD_gameData.getEntryText("scrConvoyRingOfPowerDropped_g")))
			visible = true;
		bool changed = opCD_difficulty_b939b0[opCD_gameData.getDepthIndex()].cargoChance && rng.chance(opCD_difficulty_b939b0[opCD_gameData.getDepthIndex()].cargoChance);
		if (visible || changed)
		{
			if (changed && unknownbc == 1)
				visible = false;
			vector<string> tags;
			if (visible)
				tags.push_back("PL-3XN's Ring of Power");
			else
			{
				tags.push_back("Active Cooling Armor");
				tags.push_back("Exp. Thermic Cannon");
			}
			const int p = 1;
			vector<OpCD_ItemRecord *> edges;
			int old = convoy->unknown5c8e20(0);
			int total2 = convoy->unknown5ca210();
			vector<HItem> parts;
			convoy->unknown5cb830(parts);
			OpCD_ItemRecord *id;
			for (int i = 0; i < p; i++)
			{
				if (OpQ5_findByName(opCD_itemRecords_d2d1c4,OpU8a_randomString(tags),id))
				{
					edges.push_back(id);
					old += id->mass;
					while (old > total2)
					{
						if (parts.empty())
							goto loaded;
						HItem dropped = popRandom9d8030(parts);
						old -= dropped.get224()->getNestedField_4578c0();
						dropped.get224()->remove57dbe0(0,0,1,1);
					}
				}
			}
			for (unsigned int j = 0; j < edges.size(); j++)
			{
				HItem item = opCD_world->unknown6c51d0((int)edges[j],convoy,0,0);
				if (item.isValid() && visible)
				{
					item.get224()->unknown57c110("SCR_RingOfPower_Convoy",0);
					opCD_world->unknown464f60(item);
				}
			}
loaded:
			;
		}
		if (opCD_difficulty_b939b0[opCD_gameData.getDepthIndex()].lootChance && rng.chance(opCD_difficulty_b939b0[opCD_gameData.getDepthIndex()].lootChance))
		{
			int n = convoy->unknown45a810();
			while (n)
			{
				opCD_world->unknown6c51d0(opCD_loot_d31700.pick(),convoy,0,0);
				n--;
			}
		}
		HEntity r1;
		EntityRecord *base = opCD_carrier_cefc08;
		for (int k = opCD_escortCounts_ba6608[opCD_cf4718]; k > 0; k--)
		{
			r1 = opCD_world->placeEntity(base,convoy->getPosition(),3,false,0x22,0xe,false);
			if (r1.isValid())
			{
				r1->getAI_45b590()->setFollowEntity(convoy,0);
				r1->getAI_45b590()->setField_4505b0(4);
				escorts.push_back(r1);
				count++;
			}
			else
				logWarning("Overmind::spawnCargoDispatch()","Carrier spawn failed");
		}
		base = opCD_world->selectRobotOfClass(1,0x13,false,true);
		if (base)
		{
			r1 = opCD_world->placeEntity(base,convoy->getPosition(),3,false,0x22,0xe,false);
			if (r1.isValid())
			{
				r1->getAI_45b590()->setFollowEntity(convoy,0);
				escorts.push_back(r1);
				count++;
			}
		}
		addParty(new Party(3,freighter,-1,0,0),NULL);
		if (opCD_playerData.isSlotEmpty(0x76) && (opCD_world->getPlayer()->unknown5d2380(0x16).isValid() || opCD_world->getPlayer()->unknown5d2380(0x17).isValid()))
			opCD_playerData.unknown77fbc0(0x76);
	}
	return count;
}
