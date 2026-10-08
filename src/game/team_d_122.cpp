// team_d_122: GM::readyGame (0x78b8a0; callers the game-UI start, CDifficulty::update, CMission and others):
// prepares a run - resets global systems, starts the particle engine, then either resumes a saved game
// (logging its seed, difficulty, mode and challenges) or picks the newest save slot, clears the combat log
// stream and builds a new world, player data and BattleScape.
// NOTE: class layouts are partial; names other than GM::readyGame/GM::unserialize are placeholders.
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

void logInfo(string location, string message);	// 0x405090
void logMessage(string message);	// 0x404cb0
void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
string opr1c_getSaveName_432c70(string version);	// 0x432c70, NOTE: placeholder name
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

class Holder122	// NOTE: placeholder name (OpX2_Holder455030)
{
public:
	void clear455010();	// NOTE: placeholder name
};
extern Holder122 holder122_cf1080;	// NOTE: placeholder name
extern Holder122 holder122_d2f75c;	// NOTE: placeholder name

struct Obj122;	// NOTE: placeholder element type
extern vector<Obj122 *> list122_d378ac;	// NOTE: placeholder name
extern vector<Obj122 *> list122_d01be8;	// NOTE: placeholder name

class Handle122	// NOTE: placeholder name (0x9b7270 clear)
{
public:
	int ID;
	void clear();
};
extern Handle122 handle122_d2d504;	// NOTE: placeholder name

class AnimPool122	// NOTE: placeholder name (OpD_AnimPool4547c0, 0x68 bytes)
{
public:
	char pad[0x68];
	AnimPool122();
};
extern AnimPool122 *animPool122_cefc50;	// NOTE: placeholder name

class GameData122	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	int		unknown00;
	string	seed;	// +0x04

	void unknown784410();	// NOTE: placeholder name
};
extern GameData122 gameData122_d1e860;	// NOTE: placeholder name

class PlayerData122	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	string getFlagsText();
	bool isWizard();	// NOTE: placeholder name (folded getter Sweep_46dd90::getField)
	void unknown779af0();	// NOTE: placeholder name
};
extern PlayerData122 playerData122_cf45d8;	// NOTE: placeholder name

extern string difficultyNames122_d307d0[];	// NOTE: placeholder name
extern string modeNames122_d2f508[];		// NOTE: placeholder name
extern int difficulty122_cf4718;	// NOTE: placeholder name
extern int mode122_cf462c;			// NOTE: placeholder name

struct SaveSlot122	// NOTE: placeholder name and layout (0x70 bytes)
{
	string	version;
	char	pad1c[0x70 - 0x1c];
};
extern SaveSlot122 saveSlots122_d29dc8[];	// NOTE: placeholder name

class ResourceMgr122	// NOTE: placeholder name (XResourceMgr at *0xcefa88)
{
public:
	bool fileExists(string file);
};
extern ResourceMgr122 *resources122_cefa88;	// NOTE: placeholder name

class LogStream122	// NOTE: placeholder name (ofstream at 0xd28eb8)
{
public:
	bool is_open();
	void close();
};
extern LogStream122 combatLog122_d28eb8;	// NOTE: placeholder name
extern bool combatLogging122_d28eb1;	// NOTE: placeholder name
extern string userDir122_cfd42c;	// NOTE: placeholder name
extern int newRuns122_d25740;		// NOTE: placeholder name

class Reset122	// NOTE: placeholder name (the per-run state objects)
{
public:
	void reset_673b20();	// NOTE: placeholder name
	void reset690e00();	// NOTE: placeholder name
	void reset69bb00();	// NOTE: placeholder name
	void unknown6be810();	// NOTE: placeholder name
};
extern Reset122 state122_cf6428;	// NOTE: placeholder name
extern Reset122 state122_cf6888;	// NOTE: placeholder name
extern Reset122 state122_d25450;	// NOTE: placeholder name
extern Reset122 state122_d1dd38;	// NOTE: placeholder name

class LuigiAi122	// NOTE: placeholder name (LuigiAi at 0xcebffc)
{
public:
	char	pad00[0x1c];
	int		unknown1c;	// +0x1c

	void cleanup();
	void initialize();
};
extern LuigiAi122 luigi122_cebffc;	// NOTE: placeholder name
extern bool luigiEnabled122_cefb3e;	// NOTE: placeholder name

class Map122	// NOTE: placeholder name (Map, 0xc68 bytes)
{
public:
	char pad[0xc68];
	Map122();
	bool initilize();
};
extern Map122 *world122_cefc4c;	// NOTE: placeholder name

class JLog122	// NOTE: placeholder name (JLog at *0xcefa64)
{
public:
	void end(int level);
};
extern JLog122 *jlog122_cefa64;	// NOTE: placeholder name

class GM	// NOTE: placeholder layout
{
public:
	int		saveSlot;	// +0x00

	bool isWizard122();	// NOTE: placeholder name (folded getter Sweep_470b30::getField)
	bool unserialize(bool a, bool manual);
	bool readyGame(bool newGame, bool a, bool manual);
};
extern GM *gm122_cefaa8;	// NOTE: placeholder name

bool GM::readyGame(bool newGame, bool a, bool manual)
{
	logInfo("GM::readyGame()","Preparing game");
	holder122_cf1080.clear455010();
	holder122_d2f75c.clear455010();
	list122_d378ac.clear();
	list122_d01be8.clear();
	handle122_d2d504.clear();
	logMessage("Starting particle engine");
	animPool122_cefc50 = new AnimPool122();
	if (!newGame)
	{
		if (unserialize(a,manual))
		{
			logMessage("Resuming world seed: " + gameData122_d1e860.seed);
			logMessage("Difficulty: " + difficultyNames122_d307d0[difficulty122_cf4718]);
			logMessage("Special mode: " + modeNames122_d2f508[mode122_cf462c]);
			logMessage("Applied challenge modes: " + playerData122_cf45d8.getFlagsText());
			if (playerData122_cf45d8.isWizard())
			{
				logMessage("Resuming wizard mode run");
				logMessage("Wizard mode state: " + string(gm122_cefaa8->isWizard122() ? "active" : "inactive"));
			}
			jlog122_cefa64->end(2);
			return true;
		}
	}
	else
	{
		for (int i = 9; i >= 0; i--)
		{
			if (resources122_cefa88->fileExists(opr1c_getSaveName_432c70(saveSlots122_d29dc8[i].version)))
			{
				saveSlot = stringToInt(saveSlots122_d29dc8[i].version);
				break;
			}
		}
		if (combatLogging122_d28eb1)
		{
			if (combatLog122_d28eb8.is_open())
				combatLog122_d28eb8.close();
			remove((userDir122_cfd42c + "user/" + "combat_log_stream.txt").c_str());
		}
	}
	if (!isWizard122())
		newRuns122_d25740++;
	logMessage("Building new world");
	gameData122_d1e860.unknown784410();
	logMessage("Starting world seed: " + gameData122_d1e860.seed);
	state122_cf6428.reset_673b20();
	state122_cf6888.reset690e00();
	state122_d25450.reset69bb00();
	state122_d1dd38.unknown6be810();
	logMessage("Preparing player data");
	playerData122_cf45d8.unknown779af0();
	logMessage("Difficulty: " + difficultyNames122_d307d0[difficulty122_cf4718]);
	logMessage("Special mode: " + modeNames122_d2f508[mode122_cf462c]);
	logMessage("Applied challenge modes: " + playerData122_cf45d8.getFlagsText());
	if (playerData122_cf45d8.isWizard())
		logMessage("Starting new wizard mode run");
	if (luigiEnabled122_cefb3e)
	{
		if (luigi122_cebffc.unknown1c)
			luigi122_cebffc.cleanup();
		luigi122_cebffc.initialize();
	}
	world122_cefc4c = new Map122();
	if (!world122_cefc4c->initilize())
	{
		logFatal("GM::readyGame()","Failed to initialize BattleScape");
		jlog122_cefa64->end(2);
		return false;
	}
	jlog122_cefa64->end(2);
	return true;
}
