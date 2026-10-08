// op_cmap_exit: 0x825e00, the CMap handler for taking the exit the player stands on (blocked exits,
// lockdowns, RIF override, garrison relays, then the evolution screen) (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	int unknown45a880();	// NOTE: placeholder name
};
struct HEntity
{
	int ID;
	HEntity() throw();
	Entity *operator->() const;	// 0x9b6570
};

struct OpUE_MapRecord	// NOTE: placeholder name
{
	int pad00;
	int type;	// +0x04
	int unknown08;	// +0x08
	char pad0c[0x25 - 0x0c];
	bool unknown25;	// +0x25
};
struct OpUE_Handle	// NOTE: placeholder name
{
	int ID;
	OpUE_MapRecord *get();	// NOTE: placeholder name (0x9c0060, OpC_Handle::get23c)
};
struct OpUE_Exit	// NOTE: placeholder name
{
	char pad00[8];
	OpUE_Handle node;	// +0x08
	char pad0c[0x1c - 0x0c];
	int state;	// +0x1c
};

class OpUE_Map	// NOTE: placeholder name (Map at 0xcefc4c)
{
public:
	OpUE_Exit *getZone(const Point &p);	// NOTE: placeholder name (0x462e30)
	HEntity getPlayer();	// 0x4630f0
	bool getFlag2f0();	// NOTE: placeholder name
	vector<OpUE_Exit *> *getExits_462e10();	// NOTE: placeholder name
	void unknown777190(int value);	// NOTE: placeholder name
	void checkAutosaving(bool flag);	// NOTE: placeholder name

	char pad00[0x66c];
	HEntity player;	// +0x66c
};
extern OpUE_Map *opUE_map;	// NOTE: placeholder name

class OpUE_GameData	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
	int getDepthChange(OpUE_Handle node, bool update);	// NOTE: placeholder name (0x9c4a30)
};
extern OpUE_GameData opUE_gameData;	// NOTE: placeholder name
extern OpUE_Handle opUE_current_d1e888;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);	// 0x406c90
};
extern RNG rng;

struct OpUE_PhraseTextA	// NOTE: placeholder name
{
	OpUE_PhraseTextA(int index, string *a, string *b, string *c, HEntity d, HEntity e);	// 0x510d20
	char pad00[0x20];
};
struct OpUE_PhraseTextB	// NOTE: placeholder name
{
	OpUE_PhraseTextB(int index, string *a, string *b, string *c, HEntity d, HEntity e);	// 0x510f80
	char pad00[0x28];
};
class OpUE_InterfaceMsg	// NOTE: placeholder name (CInterfaceMsg at 0xcec0f4)
{
public:
	void add(OpUE_PhraseTextA *text);	// NOTE: placeholder name
};
extern OpUE_InterfaceMsg *opUE_interfaceMsg;	// NOTE: placeholder name
class OpUE_MessageLog	// NOTE: placeholder name (object at 0xcf1080)
{
public:
	int push(OpUE_PhraseTextB *text);	// NOTE: placeholder name (0x5121f0)
};
extern OpUE_MessageLog opUE_messageLog;	// NOTE: placeholder name
class OpUE_Messages	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpUE_Messages *opUE_cec058;	// NOTE: placeholder name
class OpUE_LogMsgs	// NOTE: placeholder name (0xcec0b4)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpUE_LogMsgs *opUE_cec0b4;	// NOTE: placeholder name

class OpUE_Stats	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	vector<int> *current;
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern OpUE_Stats opUE_stats;	// NOTE: placeholder name
class OpUE_PlayerData	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	void unknown77fbc0(int type);	// NOTE: placeholder name
};
extern OpUE_PlayerData opUE_playerData;	// NOTE: placeholder name

extern unsigned char opUE_exitBlocked_ba6650[][3];	// NOTE: placeholder name
extern int opUE_cf4718;	// NOTE: placeholder name
extern string opUE_mapNames_cfaca0[];	// NOTE: placeholder name
extern int opUE_cf462c;	// NOTE: placeholder name
extern int opUE_cf4724;	// NOTE: placeholder name
extern const char empty_b9642f[];	// NOTE: placeholder name ("")
extern const char empty_b96433[];	// NOTE: placeholder name ("")

int stringToInt(const string &s);	// 0x405610
int OpS8d_findNonZero(unsigned char *data, unsigned int count);	// NOTE: placeholder name
void opUE_phrase_7b1750(int type, string *a, string *b, string *c, int d, int e, int f);	// NOTE: placeholder name (opW9_unknown7b1750)
void opUE_message_49c610(int type, HEntity entity, const string &text, int value);	// NOTE: placeholder name (opW5_message)
void opUE_logPhrase_5141b0(int index, string *a, string *b, string *c, HEntity d, int e);	// NOTE: placeholder name (opS2_logPhrase_5141b0)
bool opr4a_unknown778220();	// NOTE: placeholder name
void opUE_openEvolve_4b5780(int depth, OpUE_Handle node, bool flag);	// NOTE: placeholder name (OpW7_openEvolve)

class OpUE_CMap	// NOTE: placeholder name (CMap)
{
public:
	void useExit_825e00();	// NOTE: placeholder name
	void unknown8142d0(int a, bool b);	// NOTE: placeholder name
	void labelAccess80e3a0(bool timed, OpUE_Exit *exit);	// NOTE: placeholder name
};

void OpUE_CMap::useExit_825e00()
{
	OpUE_Exit *exit = opUE_map->getZone(opUE_map->player->getPosition());
	if (opUE_exitBlocked_ba6650[exit->node.get()->type][opUE_cf4718])
	{
		if (opUE_cf4718 == 0)
			opUE_phrase_7b1750(0xdc,&opUE_mapNames_cfaca0[exit->node.get()->type],0,0,HEntity().ID,HEntity().ID,0);
		else
		{
			int found = OpS8d_findNonZero(opUE_exitBlocked_ba6650[exit->node.get()->type],3);
			opUE_phrase_7b1750(found != 1 ? 0xdd : 0xde,&opUE_mapNames_cfaca0[exit->node.get()->type],0,0,HEntity().ID,HEntity().ID,0);
		}
	}
	else if (exit->state == 2)
		opUE_interfaceMsg->add(new OpUE_PhraseTextA(0xc3,0,0,0,HEntity(),HEntity()));
	else if (exit->state == 3)
		opUE_phrase_7b1750(0xc2,&string("Lockdown"),0,0,HEntity().ID,HEntity().ID,0);
	else if (exit->state == 4)
		opUE_phrase_7b1750(0xc2,&string(opUE_cf462c == 4 ? "Abominations" : (opUE_cf4724 ? "Gauntlet" : "Super Gauntlet")),0,0,HEntity().ID,HEntity().ID,0);
	else if (exit->state == 1 && (stringToInt(opUE_gameData.getEntryText("installedRif_g")) || opUE_map->getFlag2f0()))
	{
		do
		{
			if (opUE_messageLog.push(new OpUE_PhraseTextB(0x1cf,0,0,0,HEntity(),HEntity())))
				opUE_cec058->unknown8758d0(true);
			opUE_cec0b4->scrollToEnd();
		} while (0);
		if (opUE_map->getFlag2f0())
		{
			do
			{
				if (opUE_messageLog.push(new OpUE_PhraseTextB(0x1d0,0,0,0,HEntity(),HEntity())))
					opUE_cec058->unknown8758d0(true);
				opUE_cec0b4->scrollToEnd();
			} while (0);
			opUE_message_49c610(0x320,HEntity(),string("Remote lockdown override."),0);
		}
		else
			opUE_message_49c610(0x320,HEntity(),string("RIF authorized."),0);
		exit->state = 0;
		unknown8142d0(7,false);
		labelAccess80e3a0(true,exit);
	}
	else if (exit->state == 1 && opUE_map->getPlayer()->unknown45a880() > 25 && !rng.chance(stringToInt(opUE_gameData.getEntryText("garrisonRelaysDisabled_g")) * 10 + 30))
	{
		do
		{
			if (opUE_messageLog.push(new OpUE_PhraseTextB(0x1cf,0,0,0,HEntity(),HEntity())))
				opUE_cec058->unknown8758d0(true);
			opUE_cec0b4->scrollToEnd();
		} while (0);
		do
		{
			if (opUE_messageLog.push(new OpUE_PhraseTextB(0x1d0,0,0,0,HEntity(),HEntity())))
				opUE_cec058->unknown8758d0(true);
			opUE_cec0b4->scrollToEnd();
		} while (0);
		do
		{
			opUE_logPhrase_5141b0(0x199,0,0,0,HEntity(),0);
		} while (0);
		exit->state = 2;
		unknown8142d0(7,false);
		labelAccess80e3a0(true,exit);
		exit = NULL;
		vector<OpUE_Exit *> *exits = opUE_map->getExits_462e10();
		for (unsigned int i = 0; i < exits->size(); i++)
		{
			if ((*exits)[i]->state == 1)
			{
				if (exit)
					goto done;
				else
					exit = (*exits)[i];
			}
		}
		if (exit)
			exit->state = 0;
done:
		;
	}
	else if (exit->node.get()->unknown08 == 0)
		opUE_map->unknown777190(0x1c);
	else
	{
		if (opr4a_unknown778220())
			opUE_map->checkAutosaving(true);
		int depth = opUE_gameData.getDepthChange(exit->node,true);
		if (opUE_current_d1e888.get()->type != 0xc && opUE_current_d1e888.get()->type != 0xd && opUE_current_d1e888.get()->type != 0xe)
		{
			if (exit->node.get()->unknown25)
			{
				opUE_stats.add4729d0(0x406,1,empty_b9642f,-1);
				if ((*opUE_stats.current)[0x406] == 10)
					opUE_playerData.unknown77fbc0(0x75);
			}
			else
			{
				opUE_stats.add4729d0(0x407,1,empty_b96433,-1);
				if ((*opUE_stats.current)[0x407] == 10)
					opUE_playerData.unknown77fbc0(0x136);
			}
		}
		opUE_openEvolve_4b5780(depth,exit->node,false);
	}
}
