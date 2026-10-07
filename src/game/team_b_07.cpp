// team_b_07: game-logic helpers (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1), batch 5.
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
// Each section uses its own partial declarations; they are wrapped in namespaces only where names would clash.
#include <string>
#include <vector>
using namespace std;

struct Point { int x; int y; Point(); bool operator!=(const Point &p) const; };	// NOTE: placeholder layout
class Item { public: bool unknown5773d0(int a, int b); };	// NOTE: partial
class HItem { public: int ID; HItem(); bool isValid() const; Item *operator->() const; };
class HItemList : public vector<HItem> {};
class Entity	// NOTE: partial
{
public:
	HItem unknown5d3f80(int a, int b);	// NOTE: placeholder name
	HItemList *getInventoryList();
	const Point &getPosition();
	bool unknown5c7f70();	// NOTE: placeholder name
	void *getTarget();
};
class HEntity { public: int ID; HEntity(); Entity *operator->() const; bool isValid() const; };
class Map { public: HEntity getPlayer(); int getTurn(); };
extern Map *endObjA;	// 0xcefc4c

//==================================================================
// PlayerData: best-run list
//==================================================================

struct MapRecord;
struct OpQ5_U9df2e0 { char pad[0x2c]; int score; };	// NOTE: placeholder layout
template <class T> void OpQ5_deleteBack(vector<T*> &v);
template <class T> void OpX5_insertAt(vector<T> &v, int index, T value);
bool OpX5_containsRecord(vector<MapRecord*> &v, MapRecord *record);
class PlayerData	// NOTE: partial
{
public:
	char pad[0x128];
	OpQ5_U9df2e0 *current;	// NOTE: placeholder name
	char pad12c[0x608 - 0x12c];
	vector<OpQ5_U9df2e0*> best;	// NOTE: placeholder name
	bool unknown77ed10();	// NOTE: placeholder name
};
bool PlayerData::unknown77ed10()
{
	if (0) {}	// NOTE: no code; shifts MSVC's register rotation to match the exe
	if (current->score == 0)
		return false;
	if (best.empty())
	{
		best.push_back(current);
		return true;
	}
	else
	{
		if (current->score <= best.back()->score)
		{
			if (best.size() < 5)
				best.push_back(current);
		}
		else
		{
			for (unsigned int i = 0; i < best.size(); i++)
			{
				if (current->score > best[i]->score)
				{
					OpX5_insertAt(best,i,current);
					break;
				}
			}
			while (best.size() > 5)
				OpQ5_deleteBack(best);
		}
		return OpX5_containsRecord((vector<MapRecord*>&)best,(MapRecord*)current);
	}
}

//==================================================================
// item/entity name lookup
//==================================================================

struct TeamB_NamedA { char pad[0x24]; string name; };
struct TeamB_NamedB { char pad[0x1ac]; string name; };
extern vector<TeamB_NamedA*> teamb_records_d2d1c4;
extern vector<TeamB_NamedB*> opX4d_entityRecordsB;	// NOTE: placeholder name (0xd25de0)
extern int opw8_caf164;
extern string gameString_cf7584;
string teamb_name8f8820(int a, int b)
{
	string name = a != opw8_caf164 ? teamb_records_d2d1c4[a]->name : opX4d_entityRecordsB[b]->name;
	if (endObjA->getPlayer()->unknown5d3f80(a,b).isValid())
		name += gameString_cf7584;
	return name;
}

//==================================================================
// Party
//==================================================================

void logError(string location, string message);
string intToString(int value);
class RNG { public: int rangeInt(float a, float b); };
extern RNG rng;
extern const bool teamb_partyTimed_b91de8[];	// NOTE: placeholder name
class Party	// NOTE: placeholder name (from the "Party()" log location)
{
public:
	int type;
	HEntity leader;
	int value8;
	bool flagC;
	int value10;
	int timer;
	int value18;
	string name;
	Party(int type_, HEntity leader_, int value8_, bool flagC_, int value10_);
};
Party::Party(int type_, HEntity leader_, int value8_, bool flagC_, int value10_)
	: type(type_),
	leader(leader_),
	value8(value8_),
	flagC(flagC_),
	value10(value10_),
	timer(teamb_partyTimed_b91de8[type_] ? endObjA->getTurn() + rng.rangeInt(15.0f,30.0f) : 0),
	value18(0)
{
	if (!leader.operator->())
		logError("Party()","NULL leader for " + intToString(type_));
}

//==================================================================
// inventory search by name
//==================================================================

string teamb_itemName8f8ab0(HItem item);	// NOTE: placeholder name
HItem teamb_findInventoryItem8f8d30(const string &name)
{
	HItemList *inventory = endObjA->getPlayer()->getInventoryList();
	for (unsigned int i = 0; i < inventory->size(); i++)
	{
		if ((*inventory)[i]->unknown5773d0(1,0) && teamb_itemName8f8ab0((*inventory)[i]) == name)
			return (*inventory)[i];
	}
	return HItem();
}

//==================================================================
// name with prefix
//==================================================================

extern string teamb_strings_cfc230[];	// NOTE: placeholder name
extern string teamb_strings_d1f720[];	// NOTE: placeholder name
extern string opU5_stringsD31348[];	// NOTE: placeholder name (0xd31348)
extern const char teamb_str_bf5a54[];	// NOTE: placeholder name for the "-" literal (unnamed short literals compare with their neighbours)
extern int opw8_cf462c;	// NOTE: placeholder name (game mode)
struct TeamB_7787b0
{
	vector<int> types;
	vector<int> prefixes;
	string getName7787b0(int index);
};
string TeamB_7787b0::getName7787b0(int index)
{
	if (types.empty())
		return "err";
	if (index == -1)
		index = types.size() - 1;
	string name;
	if (prefixes[index] != 20)
		name += teamb_strings_cfc230[prefixes[index]] + teamb_str_bf5a54;
	name += opw8_cf462c == 11 ? teamb_strings_d1f720[types[index]] : opU5_stringsD31348[types[index]];
	return name;
}

//==================================================================
// CMap: click on a target
//==================================================================

class Cell { public: HEntity getEntity(); };
struct TeamB_CellGrid { Cell **at(Point &p); };
extern TeamB_CellGrid teamb_cells_cfd44c;
class BS { public: char pad[0x66c]; HEntity player; bool unknown4631f0(HEntity e); };
extern BS *teamb_world;
class XConsole { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); };
extern XConsole *opX5D_cec0c8;
class CMission { public: bool unknown987b10(int value); };
extern CMission *cmission;	// 0xcec034
void opW9_unknown7b8bc0(HEntity e, int value);
class CMap
{
public:
	bool unknown805190(Point *out);
	bool unknown8212e0();
};
bool CMap::unknown8212e0()
{
	Point pos;
	if (unknown805190(&pos) && teamb_world->player->getPosition() != pos && (*teamb_cells_cfd44c.at(pos))->getEntity().isValid() && (*teamb_cells_cfd44c.at(pos))->getEntity()->unknown5c7f70() && !(*teamb_cells_cfd44c.at(pos))->getEntity()->getTarget() && teamb_world->unknown4631f0((*teamb_cells_cfd44c.at(pos))->getEntity()))
	{
		opX5D_cec0c8->v6();
		if (cmission->unknown987b10(0))
		{
			HEntity target = (*teamb_cells_cfd44c.at(pos))->getEntity();
			opW9_unknown7b8bc0(target,1);
			return true;
		}
	}
	return false;
}
