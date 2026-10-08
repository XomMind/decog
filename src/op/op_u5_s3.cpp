// op_u5_s3: assorted functions in 0x794940-0x7ac1c0 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <ostream>
#include "../pathing/gamedecl.h"
#include "../util/rng.h"
using namespace std;

class OpU5_HMachine	// NOTE: placeholder name
{
public:
	int ID;
};

struct OpU5_MapRecord	// NOTE: placeholder name
{
	Point position;
	OpU5_HMachine machine;
	char pad0c[1];
	bool revealed;	// NOTE: placeholder name
};

class OpU5_Level	// NOTE: placeholder name (BS)
{
public:
	void announceMachine(OpU5_HMachine machine);	// NOTE: placeholder name (0x71dd30)
};
extern OpU5_Level *opU5_level;	// NOTE: placeholder name (0xcefc4c)

class OpU5_HEntity;
class OpU5_HPlayer;

class OpU5_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	void unknown4647a0(const Point &p, bool flag);	// NOTE: placeholder name

	char pad0[0x720];
	vector<HProp> propList;	// NOTE: placeholder name
	int getTurn();	// NOTE: placeholder name (0x464270)
	HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
	OpU5_HPlayer getPlayerHandle();	// NOTE: placeholder name (0x4630f0)
	bool isVisible(const Point &p);	// NOTE: placeholder name (0x4631c0)
	void unknown9e29b0(vector<HProp> *list, HProp prop);	// NOTE: placeholder name
};
extern OpU5_Map *opU5_map;	// NOTE: placeholder name (0xcefc4c)

template <class T> int OpU5_randomIndex(vector<T> &v);	// NOTE: placeholder name (0x9d9b20)
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0

void opU5_revealRandomMachine(vector<OpU5_MapRecord *> &records, int &count, vector<int> &indexes, vector<Point> &found)	// NOTE: placeholder name (0x794940)
{
	while (count != 0 && !indexes.empty())
	{
		int index = OpU5_randomIndex(indexes);
		OpU5_MapRecord *mr = records[indexes[index]];
		opU5_level->announceMachine(mr->machine);
		opU5_map->unknown4647a0(mr->position,true);
		mr->revealed = true;
		found.push_back(mr->position);
		removeVectorElement(indexes,index);
		count--;
	}
}

class OpU5_Shell	// NOTE: placeholder name (CShell at 0xcec100)
{
public:
	void addPointC8(const vector<Point> &p);	// NOTE: placeholder name (0x4b0e80)
	void unknown90ec30(string text);	// NOTE: placeholder name
};
extern OpU5_Shell *opU5_shell;	// NOTE: placeholder name (0xcec100)

class OpU5_MapConsole	// NOTE: placeholder name (object at 0xcec054)
{
public:
	void unknown813050(int a, HProp prop, int b, int c, int d);	// NOTE: placeholder name
};
extern OpU5_MapConsole *opU5_mapConsole;	// NOTE: placeholder name (0xcec054)

void opU5_markPropPoints(vector<Point> &points)	// NOTE: placeholder name (0x794a60)
{
	if (!points.empty())
	{
		if (opU5_shell != NULL)
		{
			opU5_shell->addPointC8(points);
			for (unsigned int i = 0; i < points.size(); i++)
				opU5_map->unknown9e29b0(&opU5_map->propList,cells(points[i])->getProp());
		}
		else
		{
			for (unsigned int j = 0; j < points.size(); j++)
			{
				if (cells(points[j])->getProp().isValid())
				{
					opU5_mapConsole->unknown813050(1,cells(points[j])->getProp(),0,0,0);
					opU5_map->unknown9e29b0(&opU5_map->propList,cells(points[j])->getProp());
				}
			}
		}
	}
}

bool opU5_logMessage(int id, const string &text, const string *b, int c, HProp d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)

class OpU5_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpU5_MsgConsole *opU5_msgConsole;	// NOTE: placeholder name (0xcec058)

class OpU5_LogMsgs	// NOTE: placeholder name (CLogMsgs)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpU5_LogMsgs *opU5_logMsgs;	// NOTE: placeholder name (0xcec0b4)

void opU5_logWithShell(bool flag, const string &text)	// NOTE: placeholder name (0x794c40)
{
	if (flag)
	{
		do
		{
			if (opU5_logMessage(0x1d7,string("SKIM"),&text,0,HProp(),HProp(),0,0))
				opU5_msgConsole->unknown8758d0(true);
			opU5_logMsgs->scrollToEnd();
		} while (0);
	}
	else
	{
		do
		{
			if (opU5_logMessage(0x323,text,0,0,HProp(),HProp(),0,0))
				opU5_msgConsole->unknown8758d0(true);
			opU5_logMsgs->scrollToEnd();
		} while (0);
		if (opU5_shell != NULL)
			opU5_shell->unknown90ec30(text);
	}
}

void opU5_writeQuotedInt(ostream &out, int value)	// NOTE: placeholder name (0x79a050)
{
	if (value != 0)
		out << "\"" << value << "\",";
	else
		out << "\"\",";
}

void opU5_writeQuotedText(ostream &out, const string &text)	// NOTE: placeholder name (0x79a0a0)
{
	string escaped = text;
	for (unsigned int i = 0; i < escaped.size(); i++)
	{
		if (escaped[i] == '"')
		{
			escaped.insert(i,"\"");
			i++;
		}
	}
	out << "\"" << escaped << "\",";
}

extern RNG rng;	// 0xd30908

struct OpU5_Spawn	// NOTE: placeholder name
{
	char pad0[0x20];
	int type;		// NOTE: placeholder name
	int chance;		// NOTE: placeholder name
	char pad28[8];
	int interval;	// NOTE: placeholder name
	vector<string> messages;	// NOTE: placeholder name
};
extern vector<OpU5_Spawn *> opU5_spawns;	// NOTE: placeholder name (0xd25860)

class OpU5_HItem;

struct OpU5_EntityData	// NOTE: placeholder name
{
	int pad0;
	int type;	// NOTE: placeholder name

	bool unknown5c98c0(int a, int b, int c);	// NOTE: placeholder name
	int unknown5d15a0(int a);	// NOTE: placeholder name
	vector<OpU5_HItem> *getInventoryList();	// 0x45ab00
};

class OpU5_HEntity	// NOTE: placeholder name
{
public:
	int ID;
	OpU5_EntityData *operator->() const;	// 0x9b7910
};
extern OpU5_HEntity opU5_playerHandle;	// NOTE: placeholder name (0xd1e888)

class OpU5_HPlayer	// NOTE: placeholder name; a separate handle type so its operator-> (0x9b6570) pairs apart from OpU5_HEntity's (0x9b7910)
{
public:
	int ID;
	OpU5_EntityData *operator->() const;	// 0x9b6570
};

class OpU5_ItemData	// NOTE: placeholder name
{
public:
	const Point &unknown575920();	// NOTE: placeholder name
	HEntity unknown457b50();	// NOTE: placeholder name (owner)
	int unknown44aec0();	// NOTE: placeholder name (ICF'd trivial getter)
	int unknown4578a0();	// NOTE: placeholder name
	int unknown457820();	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name
};

class OpU5_HItem	// NOTE: placeholder name
{
public:
	int ID;
	OpU5_HItem();	// NOTE: ICF'd with the HProp constructor
	bool isValid() const;
	bool isNull() const;
	OpU5_ItemData *operator->() const;	// 0x9b65b0
};

class OpU5_SpawnTracker;

struct OpU5_State	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	OpU5_HItem item;
	char pad8[0x10 - 8];
	int unknown10;	// NOTE: placeholder name
	char pad14[0x30 - 0x14];
	OpU5_SpawnTracker *tracker;	// NOTE: placeholder name

	void updateSpawns();	// NOTE: placeholder name (0x7aaee0)
	bool isOwnedByPlayer();	// NOTE: placeholder name (0x7abf80)
};
extern OpU5_State *opU5_state;	// NOTE: placeholder name (0xcf4ac8)

string OpU8a_randomString(vector<string> &v);	// NOTE: placeholder name (0x9d3280)
void opU5_processText4351e0(string &text);	// NOTE: placeholder name
void opU5_replace407e00(string &text, string from, string to);	// NOTE: placeholder name
void opU5_message(int type, HEntity entity, const string &text, int value);	// NOTE: placeholder name (opW5_message)
extern string opU5_stringD216cc;	// NOTE: placeholder name (0xd216cc)

class OpU5_SpawnTracker	// NOTE: placeholder name
{
public:
	int lastTurn;
	vector<int> lastSpawn;	// NOTE: placeholder name
	vector<int> minGap;		// NOTE: placeholder name

	bool canSpawn(unsigned int index);	// NOTE: placeholder name (0x7aa160)
	bool spawn(unsigned int index, bool force, string extra);	// NOTE: placeholder name (0x7aa280)
};

bool OpU5_SpawnTracker::canSpawn(unsigned int index)
{
	OpU5_Spawn *spawn = opU5_spawns[index];
	if (lastSpawn[index] != 0 && (spawn->interval == 0 || opU5_map->getTurn() - lastSpawn[index] < spawn->interval)
		|| spawn->type != 0x26 && spawn->type != opU5_playerHandle->type
		|| minGap[index] != 0 && opU5_map->getTurn() - lastTurn < minGap[index]
		|| spawn->chance != 0 && !rng.chance(spawn->chance)
		|| !opU5_map->isVisible(opU5_state->item->unknown575920()))
		return false;
	return true;
}

bool OpU5_SpawnTracker::spawn(unsigned int index, bool force, string extra)
{
	if (!force && !canSpawn(index))
		return false;
	lastSpawn[index] = opU5_map->getTurn();
	string message = (opU5_spawns[index]->messages.size() > 1 ? OpU8a_randomString(opU5_spawns[index]->messages) : opU5_spawns[index]->messages[0]);
	opU5_processText4351e0(message);
	message.insert(0,opU5_state->item->unknown571db0(false,false) + ": \"");
	if (!extra.empty())
		opU5_replace407e00(message,opU5_stringD216cc,extra);
	message += "\"";
	if (opU5_state->item->unknown457b50() == opU5_map->getPlayer())
		opU5_message(0x322,opU5_map->getPlayer(),message,0);
	else
	{
		do
		{
			if (opU5_logMessage(0x322,message,0,0,HProp(),HProp(),&opU5_state->item->unknown575920(),0))
				opU5_msgConsole->unknown8758d0(true);
			opU5_logMsgs->scrollToEnd();
		} while (0);
	}
	return true;
}

class OpX1_PlayerData	// NOTE: placeholder name
{
public:
	bool hasCompanion();	// NOTE: placeholder name (0x780790)
};
extern OpX1_PlayerData opU5_playerData;	// NOTE: placeholder name (0xcf45d8)
extern int opU5_cf47b8;	// NOTE: placeholder name (0xcf47b8)
extern string opU5_stringsD31348[];	// NOTE: placeholder name (0xd31348)
extern vector<int> opU5_valuesCf4c28;	// NOTE: placeholder name (0xcf4c28)

void OpU5_State::updateSpawns()
{
	if (item->unknown457b50() == opU5_map->getPlayer() && item->unknown44aec0() == 3)
	{
		if (opU5_map->getTurn() % 0x83 == 0 && opU5_playerData.hasCompanion() && opU5_state->tracker->canSpawn(0x2c) && opU5_map->getPlayerHandle()->unknown5c98c0(0,0x32,0))
		{
			tracker->spawn(0x2c,true,string(""));
			return;
		}
		if (opU5_playerData.hasCompanion() && opU5_state->tracker->canSpawn(0x2d) && opU5_map->getPlayerHandle()->unknown5d15a0(0) > 200)
		{
			tracker->spawn(0x2d,true,string(""));
			return;
		}
		if (opU5_playerData.hasCompanion() && opU5_state->tracker->canSpawn(0x2e) && (opU5_cf47b8 == 6 || opU5_cf47b8 == 7 || opU5_cf47b8 == 8))
		{
			tracker->spawn(0x2e,true,opU5_stringsD31348[opU5_cf47b8]);
			return;
		}
		if (tracker->canSpawn(0x32))
		{
			OpU5_HItem selected;
			vector<OpU5_HItem> *inventory = opU5_map->getPlayerHandle()->getInventoryList();
			for (unsigned int i = 0; i < inventory->size(); i++)
			{
				if ((*inventory)[i]->unknown4578a0() == 3 && (*inventory)[i]->unknown44aec0() <= 3 && (*inventory)[i]->unknown457f90() != 0xd6
					&& opU5_valuesCf4c28[(*inventory)[i]->unknown457820()] >= 500
					&& (selected.isNull() || opU5_valuesCf4c28[(*inventory)[i]->unknown457820()] >= opU5_valuesCf4c28[selected->unknown457820()]))
					selected = (*inventory)[i];
			}
			if (selected.isValid())
			{
				tracker->spawn(0x32,true,selected->unknown571db0(false,false));
				return;
			}
		}
		if (opU5_playerData.hasCompanion())
			opU5_state->tracker->spawn(0x34,false,string(""));
	}
}

bool OpU5_State::isOwnedByPlayer()
{
	return (unknown0 != 0 && unknown10 == 0 && item.operator->() && item->unknown44aec0() == 3 && item->unknown457b50() == opU5_map->getPlayer());
}

struct OpU5_Slot	// NOTE: placeholder name
{
	HEntity entity;
	char pad4[0x20 - 4];
	int index;	// NOTE: placeholder name
};

struct OpU5_SlotRecord	// NOTE: placeholder name
{
	char pad0[0x20];
	vector<int> chances;	// NOTE: placeholder name
	vector<int> gaps;		// NOTE: placeholder name
};
extern vector<OpU5_SlotRecord *> opU5_slotRecords;	// NOTE: placeholder name (0xd1d078)

class OpU5_SlotTable	// NOTE: placeholder name
{
public:
	char pad0[0x10];
	vector<OpU5_Slot *> slots;	// NOTE: placeholder name
	Array2D<int> lastUsed;		// NOTE: placeholder name

	int findSlot(HEntity e);	// NOTE: placeholder name (0x7ac070)
	bool canUse(HEntity e, unsigned int record);	// NOTE: placeholder name (0x7ac0e0)
};

int OpU5_SlotTable::findSlot(HEntity e)
{
	for (unsigned int i = 0; i < slots.size(); i++)
	{
		if (slots[i]->entity == e)
			return slots[i]->index;
	}
	return 0x20;
}

bool OpU5_SlotTable::canUse(HEntity e, unsigned int record)
{
	int id = findSlot(e);
	if (id == 0x20)
		return false;
	OpU5_SlotRecord *rec = opU5_slotRecords[record];
	if (lastUsed(record,id) != 0 && (rec->gaps[id] == 0 || opU5_map->getTurn() - lastUsed(record,id) < rec->gaps[id])
		|| rec->chances[id] != 0 && !rng.chance(rec->chances[id]))
		return false;
	return true;
}
