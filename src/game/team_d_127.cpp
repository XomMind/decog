// team_d_127: BS member 0x774390 (callers CInventory::attemptEquip, OpV3h_Map::unknown826920, the parts
// equip helpers and more): ends a player action - records the action turn and its duration, runs the
// pending Lightpack quantum anomalies (items swallowed and later discharged nearby), marks the explored
// region, updates the action counters and refreshes the map; then counts the action in the stats.
// NOTE: class layouts are partial; names other than BS are placeholders. Local names follow the stack-slot
// hash order.
// NOTE: x/f/v/first are four locals the exe initializes but never reads; num is the list of swallowed items.
#include <string>
#include <vector>
using namespace std;

template <class T> void OpQ5_appendVector(vector<T> &v, vector<T> &other);	// NOTE: placeholder name
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name

struct Point
{
	int x;
	int y;

	Point();				// 0x453b40
	Point(int x_, int y_);	// 0x46ca20 (Pos)
};

class HProp
{
public:
	int ID;
	HProp();
};

class Item
{
public:
	void unknown57a5d0(int a, int b);	// NOTE: placeholder name
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown57a0f0(const Point *p, int a, bool b);	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	HItem();
	Item *operator->() const;	// NOTE: OpC_Handle::get224
};

HItem OpX5_randomRecord(vector<HItem> &v);	// NOTE: placeholder name
struct OpS8c_Handle : public HItem {};	// NOTE: placeholder name (handle type named by the configured OpS8c_popRandom signature)
OpS8c_Handle OpS8c_popRandom(vector<OpS8c_Handle> &v);	// NOTE: placeholder name

class Entity
{
public:
	bool unknown5c97f0();	// NOTE: placeholder name
	int unknown5cb830(vector<HItem> *list);	// NOTE: placeholder name
	const Point &getPosition();
	int getIdleTurns127();	// NOTE: placeholder name (folded getter, 0x45a6e0)
	void setIdleTurns127(int value);	// NOTE: placeholder name (folded setter, 0x45b090)
	void unknown45b0b0();	// NOTE: placeholder name
	void setField127(HProp prop);	// NOTE: placeholder name (folded setter Sweep_451600::setField)
};

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
};

void opW5_message(int type, HProp prop, const string &text, int value);	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

class TurnQueue127	// NOTE: placeholder name (OpS3e_TurnQueue at 0xd225a0)
{
public:
	void unknown6727c0(int turns);	// NOTE: placeholder name
};
extern TurnQueue127 turnQueue127_d225a0;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs127_cec0c4;	// NOTE: placeholder name

class CInventory
{
public:
	void reopen(int mode, HProp prop);
};
extern CInventory *inventory127_cec08c;	// NOTE: placeholder name

class SpawnTracker127	// NOTE: placeholder name (OpU5_SpawnTracker)
{
public:
	void spawn(int type, bool flag, string text);
};

struct ItemRec127	// NOTE: placeholder name and layout (OpS1f_ItemRec at *0xcf4ac8)
{
	char				pad00[0x30];
	SpawnTracker127		*tracker;	// +0x30
};
extern ItemRec127 *itemRec127_cf4ac8;	// NOTE: placeholder name

class PlayerData127	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	bool hasCompanion();
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern PlayerData127 playerData127_cf45d8;	// NOTE: placeholder name

class Stats127	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern Stats127 stats127_d2c658;	// NOTE: placeholder name

struct Location127	// NOTE: placeholder name
{
	int		unknown00;
	int		type;	// +0x04
};

class HLocation127	// NOTE: placeholder name
{
public:
	int ID;
	Location127 *operator->() const;	// NOTE: OpC_Handle::get23c
};
extern HLocation127 location127_d1e888;	// NOTE: placeholder name

struct MapFlags127	// NOTE: placeholder name (6-byte per-map-type record)
{
	bool	trackExploration;
	char	pad[5];
};
extern MapFlags127 mapFlags127_b90180[];	// NOTE: placeholder name

struct RegionScale127	// NOTE: placeholder name
{
	int		size;
	int		value;
};
extern RegionScale127 regionScale127_b90290[];	// NOTE: placeholder name

class Grid127	// NOTE: placeholder name (OpX5_Array2D<int> at 0xcf6488)
{
public:
	int *atPoint(Point &p);
};
extern Grid127 explored127_cf6488;	// NOTE: placeholder name
extern int unexplored127_cf6498;	// NOTE: placeholder name

class CMap127	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	void unknown819ce0();	// NOTE: placeholder name
	void unknown49af20();	// NOTE: placeholder name
	void unknown8142d0(unsigned int a, bool b);	// NOTE: placeholder name
};
extern CMap127 *cmap127_cec054;	// NOTE: placeholder name

class State127	// NOTE: placeholder name (object at 0xd25450)
{
public:
	bool unknown000;	// NOTE: placeholder name

	void unknown6a0150(int a);	// NOTE: placeholder name
};
extern State127 state127_d25450;	// NOTE: placeholder name

extern int actionDurations127_b95fa0[];	// NOTE: placeholder name
extern vector<int> actionTurns127_cf4770;	// NOTE: placeholder name
extern int pendingAnomalies127_cf4a34;	// NOTE: placeholder name
extern vector<HItem> swallowed127_cf4a38;	// NOTE: placeholder name
extern int discharges127_cf4d5c;	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	char	pad000[0x318];
	int		unknown318;
	int		unknown31c;
	char	pad320[0x658 - 0x320];
	int		actionState;	// +0x658
	char	pad65c[0x664 - 0x65c];
	int		duration;		// +0x664
	char	pad668[4];
	HEntity	player;			// +0x66c
	char	pad670[0xb05 - 0x670];
	bool	unknownb05;		// +0xb05
	char	padb06[0xc14 - 0xb06];
	int		unknownc14;		// +0xc14

	int getTurn();
	void unknown74b1d0();	// NOTE: placeholder name
	bool unknown71bc10(const Point &p, Point &out);	// NOTE: placeholder name
	void unknown774390(int action, int turns);	// NOTE: placeholder name
};
extern BS *world127_cefc4c;	// NOTE: placeholder name

void BS::unknown774390(int action, int turns)
{
	actionState = 2;
	if (turns == -1)
		turns = actionDurations127_b95fa0[action];
	actionTurns127_cf4770[action] = getTurn();
	world127_cefc4c->unknown74b1d0();
	logMsgs127_cec0c4->scrollToEnd();
	duration = turns;
	turnQueue127_d225a0.unknown6727c0(unknownb05 ? 0 : turns);
	if (player.operator->())
	{
		if (pendingAnomalies127_cf4a34)
		{
			if (!player->unknown5c97f0())
				pendingAnomalies127_cf4a34 = 0;
			else
			{
				int x = 0;
				int f = 2;
				int v = 0x32;
				int first = 0x32;
				vector<HItem> num;
				for (int i = 0; i < pendingAnomalies127_cf4a34; i++)
				{
					vector<HItem> items;
					if (player->unknown5cb830(&items))
					{
						int odds = items.size() / 2;
						if (rng.chance(odds))
						{
							HItem it = OpX5_randomRecord(items);
							it->unknown57a5d0(8,0);
							num.push_back(it);
							string msg = it->unknown571db0(false,false) + " swallowed by quantum anomaly within Lightpack 2.0.";
							opW5_message(0x320,HProp(),msg,0);
							opR1d_4541b0(0xff,0,0);
							if (rng.chance(50) && !swallowed127_cf4a38.empty())
							{
								OpS8c_Handle back = OpS8c_popRandom((vector<OpS8c_Handle> &)swallowed127_cf4a38);
								if (rng.chance(50))
									back->unknown57dbe0(0,0,1,1);
								else
								{
									Point p;
									if (!unknown71bc10(player->getPosition(),p))
										swallowed127_cf4a38.push_back(back);
									else
									{
										string text = "Quantum anomaly discharges " + back->unknown571db0(false,false) + ".";
										opW5_message(0x320,HProp(),text,0);
										back->unknown57a0f0(&p,1,false);
										if (back->unknown457f90() == 0xd6 && playerData127_cf45d8.hasCompanion())
											itemRec127_cf4ac8->tracker->spawn(0x27,false,"");
										if (++discharges127_cf4d5c == 5)
											playerData127_cf45d8.unknown77fbc0(0xd2);
									}
								}
							}
						}
					}
				}
				pendingAnomalies127_cf4a34 = 0;
				if (!num.empty())
				{
					OpQ5_appendVector(swallowed127_cf4a38,num);
					if (inventory127_cec08c)
						inventory127_cec08c->reopen(4,HProp());
				}
			}
		}
		if (mapFlags127_b90180[location127_d1e888->type].trackExploration)
		{
			Point cell(player->getPosition().x / regionScale127_b90290[location127_d1e888->type].size,player->getPosition().y / regionScale127_b90290[location127_d1e888->type].size);
			if (*explored127_cf6488.atPoint(cell) == 0)
			{
				*explored127_cf6488.atPoint(cell) = 1;
				unexplored127_cf6498 -= regionScale127_b90290[location127_d1e888->type].value;
			}
		}
		player->setIdleTurns127(action == 1 || action == 2 ? 0 : player->getIdleTurns127() + 1);
		if (action != 1 && action != 2)
			player->unknown45b0b0();
		else
			cmap127_cec054->unknown819ce0();
		if (action != 9)
			player->setField127(HProp());
		if (action != 0xb && action != 0xc && action != 0xd)
			cmap127_cec054->unknown49af20();
		cmap127_cec054->unknown8142d0(0x10,true);
		if (state127_d25450.unknown000 && (action == 1 || action == 2))
			state127_d25450.unknown6a0150(0);
	}
	unknownc14 = 0;
	unknown318++;
	unknown31c++;
	stats127_d2c658.add4729d0(0x412,1,"",-1);
	stats127_d2c658.add4729d0(action + 0x413,1,"",-1);
}
