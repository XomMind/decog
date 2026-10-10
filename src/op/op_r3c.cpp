// op_r3c: functions in 0x682000-0x690000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <cstdlib>
#include "../util/rng.h"
using namespace std;

struct Point
{
	int x;
	int y;

	Point();
	Point(int v);
	Point(int x_, int y_);
	Point(const Point &p);
	Point &operator=(const Point &p);
	bool operator!=(const Point &p) const;
};

class Entity;
class Prop;

class HEntity;
class OpR3c_Group	// NOTE: placeholder name
{
public:
	int unknown9b8f00();				// NOTE: placeholder name (trivial getter at +4)
	vector<HEntity> *getMembers();	// NOTE: placeholder name (0x416f40)
};

class OpR3c_HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	OpR3c_Group *operator->() const;	// 0x9b7250
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool isValid() const;
	Entity *operator->() const;	// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b78e0
};

class OpR3c_AI	// NOTE: placeholder name (EntityAI)
{
public:
	HEntity getFollowEntity();	// 0x458ed0
};

class Entity
{
public:
	OpR3c_AI *getAI();					// NOTE: placeholder name (0x45b590)
	OpR3c_HGroup getGroup();			// 0x45a3f0
	int unknown5d22a0(int type);		// NOTE: placeholder name
};

class HProp
{
	int	ID;
public:
	HProp();
	bool isValid() const;
};

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	int getTurn();			// 0x464270
	HEntity getPlayer();	// 0x4630f0
	OpR3c_HGroup unknown463890(int i);	// NOTE: placeholder name
	int getDisabledGarrisonAccesses();	// NOTE: placeholder name
	void unknown7297a0();	// NOTE: placeholder name
};

struct OpR3c_GameState	// NOTE: placeholder name
{
	char pad00[4];
	int type;
};

class OpR3c_HGameState	// NOTE: placeholder name
{
public:
	int ID;
	OpR3c_GameState *operator->() const;	// 0x9b7910
};

class OpR3c_Chance	// NOTE: placeholder name (0xcf45d8)
{
public:
	void unknown77e900(int amount, int flag);	// NOTE: placeholder name
	void unknown77fbc0(int id);				// NOTE: placeholder name
};

class OpR3c_Console	// NOTE: placeholder name
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};

class OpR3c_LogScroller	// NOTE: placeholder name
{
public:
	void scrollToEnd();	// 0x7b4f10
};

class OpR3c_MessageLog	// NOTE: placeholder name (0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name
};

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
bool opr3c_unknown5111e0(int id, const string &a, const string *b, int c, HProp d, HProp e, const Point *f, int g);	// NOTE: placeholder name
void opr3c_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)
void opr3c_clamp(int low, int &value, int high);	// NOTE: placeholder name (0x9cdc50)

class OpR3c_GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	bool unknown46f4b0(int a);					// NOTE: placeholder name
	int getDepthIndex();						// NOTE: placeholder name
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};

class OpR3c_Stats	// NOTE: placeholder name (0xd2c658)
{
public:
	bool unknown4729d0(int id, int value, string text, int extra);	// NOTE: placeholder name
	int unknown472c70(int id);										// NOTE: placeholder name
};

struct OpR3c_Squad	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	HEntity leader;	// NOTE: placeholder name
};

class OpR3c_IntGrid	// NOTE: placeholder name (Array2D<int>)
{
	int width;
	int height;
	int *data;
public:
	void fill(int value);	// NOTE: placeholder name (0x9cf020)
};

struct OpR3c_Range	// NOTE: placeholder name
{
	int randomInRange_40c130() throw();	// NOTE: placeholder name

	int min;
	int max;
};

class OpR3c_Overmind	// NOTE: placeholder name (object at 0xcf6428)
{
public:
	int unknown0;				// NOTE: placeholder name
	int unknown4;				// NOTE: placeholder name
	int unknown8;				// NOTE: placeholder name
	char pad0c[0x34 - 0x0c];
	int unknown34;				// NOTE: placeholder name
	char pad38[0x4c - 0x38];
	int unknown4c;				// NOTE: placeholder name
	vector<OpR3c_Squad *> squads;	// NOTE: placeholder name
	OpR3c_IntGrid surgicalExplored;	// NOTE: placeholder name
	char pad6c[0x70 - 0x6c];
	int surgicalTimer;				// NOTE: placeholder name
	char pad74[0x88 - 0x74];
	int unknown88;				// NOTE: placeholder name
	int unknown8c;				// NOTE: placeholder name
	char pad90[0x100 - 0x90];
	bool unknown100;			// NOTE: placeholder name
	char pad101[0x138 - 0x101];
	int unknown138;				// NOTE: placeholder name
	int unknown13c;				// NOTE: placeholder name
	char pad140[0x16c - 0x140];
	vector<int> unknown16c;		// NOTE: placeholder name

	void unknown6820b0();								// NOTE: placeholder name
	void unknown682110(int terrain, HEntity e);		// NOTE: placeholder name
	void unknown6821f0();								// NOTE: placeholder name
	void unknown6823f0(int a);						// NOTE: placeholder name
	void unknown682420(int a, int b);					// NOTE: placeholder name
	void unknown682220(const Point &p);				// NOTE: placeholder name
	int unknown686c60(const Point &p, int a, int b, int c);	// NOTE: placeholder name
	void unknown682770(int a, int b);					// NOTE: placeholder name
	OpR3c_Squad *unknown683310(HEntity e);			// NOTE: placeholder name
	bool unknown683380(HEntity e, int *out);			// NOTE: placeholder name
	int unknown683410(HEntity e, vector<HEntity> &out);	// NOTE: placeholder name
	void resetSurgicalTimer();								// NOTE: placeholder name
	void unknown68d920(int a);						// NOTE: placeholder name
	bool unknown68e1a0();								// NOTE: placeholder name
};

extern RNG rng;							// 0xd30908
extern OpR3c_Range opr3c_dd31508;		// NOTE: placeholder name (0xd31508)
extern Map *world;							// 0xcefc4c
extern OpR3c_GameData opr3c_gameData;		// NOTE: placeholder name (0xd1e860)
extern OpR3c_Stats opr3c_stats;			// NOTE: placeholder name (0xd2c658)
extern int TERRAIN_CAVE_WALL;				// NOTE: placeholder (0xcefba0)
extern int caveinThirdTerrain;			// NOTE: placeholder (0xcefba4)
extern int opr3c_terrainCefbac;			// NOTE: placeholder name
extern int opr3c_terrainCefbb0;			// NOTE: placeholder name
extern const float opr3c_three;			// NOTE: placeholder name (0xb919e0, 3.0f)
extern const float opr3c_amounts[];		// NOTE: placeholder name (0xb91998)
extern const int opr3c_zoneCloakDelay[];	// NOTE: placeholder name (0xb989b4)
extern const int opr3c_threatObfuscation[];	// NOTE: placeholder name (0xb989a8)
extern const int opr3c_statTable[];		// NOTE: placeholder name (0xbbc238)
extern const bool opr3c_gainsTable[];	// NOTE: placeholder name (0xb8ffd4)
extern const int opr3c_surgicalIntervals[][5];		// NOTE: placeholder name (0xb93790)
extern vector<int> opr3c_rifLevels;	// NOTE: placeholder name (0xcf4a04)
extern OpR3c_HGameState opr3c_gameState;	// NOTE: placeholder name (0xd1e888)
extern OpR3c_Chance opr3c_chance;		// NOTE: placeholder name (0xcf45d8)
extern int opr3c_mode;					// NOTE: placeholder name (0xcf462c)
extern int opr3c_counter;				// NOTE: placeholder name (0xcf4630)
extern OpR3c_Console *opr3c_consoleA;	// NOTE: placeholder name (0xcec058)
extern OpR3c_LogScroller *opr3c_consoleB;	// NOTE: placeholder name (0xcec0b4)
extern OpR3c_MessageLog opr3c_messageLog;	// NOTE: placeholder name (0xcf1080)
extern bool opr3c_flag_d28fb0;			// NOTE: placeholder name
int opr3c_maxInt(int a, int b);			// NOTE: placeholder name (0x9cdb60)

void OpR3c_Overmind::unknown6820b0()
{
	if (opr3c_gameData.unknown46f4b0(1))
	{
		unknown682420(0x11,0);
		opr3c_stats.unknown4729d0(3,0x3c,"",-1);
	}
}

void OpR3c_Overmind::unknown682110(int terrain, HEntity e)
{
	if (opr3c_gameData.unknown46f4b0(1) && e.operator->() && e->getGroup()->unknown9b8f00() <= 2)
	{
		if (terrain == opr3c_terrainCefbb0 || terrain == TERRAIN_CAVE_WALL)
			unknown682420(0x12,opr3c_maxInt(1,(int)(opr3c_gameData.getDepthIndex() / opr3c_three)));
		else if (terrain == caveinThirdTerrain)
			unknown682420(0x13,0);
		else if (terrain == opr3c_terrainCefbac)
			unknown682420(0x14,0);
	}
}

void OpR3c_Overmind::unknown6821f0()
{
	unknown16c.push_back(world->getTurn());
}

void OpR3c_Overmind::unknown6823f0(int a)
{
	if (opr3c_gameData.unknown46f4b0(1))
		unknown682420(a,0);
}

void OpR3c_Overmind::unknown682420(int a, int b)
{
	if (stringToInt(opr3c_gameData.unknown46f6d0("comZhirovActivatedSGEMP_g")) || stringToInt(opr3c_gameData.unknown46f6d0("comPlayerSurrendered_g")))
		return;
	if (b == 0)
		b = (int)opr3c_amounts[a];
	if (b > 0)
	{
		if (opr3c_rifLevels[7] != 0)
			b = opr3c_maxInt(1,b - b * opr3c_threatObfuscation[opr3c_rifLevels[7]] / 100);
		int reduction = world->getPlayer()->unknown5d22a0(0x1d);
		if (reduction != 0)
			b = opr3c_maxInt(1,b - b * reduction / 100);
	}
	int previous = unknown0;
	unknown0 += b;
	opr3c_clamp(0,unknown0,99999);
	if (abs(previous - unknown0) != 0)
	{
		opr3c_stats.unknown4729d0(opr3c_statTable[a] < 0x229 ? 0x219 : 0x229,abs(previous - unknown0),"",-1);
		opr3c_stats.unknown4729d0(opr3c_statTable[a],abs(previous - unknown0),"",-1);
	}
	if (opr3c_gameState->type != 0x22)
	{
		if (b > 0)
		{
			if (opr3c_gainsTable[a])
				unknown4 += b;
		}
		else
		{
			unknown4 = previous != 0 ? unknown4 * unknown0 / previous : 0;
		}
	}
	if (opr3c_mode)
	{
		switch (opr3c_mode)
		{
			case 2:
				if (b > 5 && a < 0x18)
					opr3c_counter += b * 10;
				break;
			case 5:
				if (b > 5 && a < 0x18)
					opr3c_chance.unknown77e900(b * 5,0);
				break;
		}
	}
}

void OpR3c_Overmind::unknown682220(const Point &p)
{
	if (world->getTurn() >= unknown88 && unknown686c60(p,-1,0x61,0x7a))
	{
		do
		{
			opr3c_messageLog.unknown451400(1);
			if (1 && !(opr3c_flag_d28fb0 && 1 && 1))
				opr3c_playSound(0x127,0,0);
			do
			{
				if (opr3c_unknown5111e0(0x324,string("ALERT: Construction progress impeded, dispatching reinforcements to local area."),NULL,0,HProp(),HProp(),NULL,0))
					opr3c_consoleA->unknown8758d0(true);
				opr3c_consoleB->scrollToEnd();
			} while (0);
			opr3c_consoleB->scrollToEnd();
		} while (0);
		unknown88 = world->getTurn() + 100;
		unknown8c = unknown8c + 1;
		opr3c_stats.unknown4729d0(0x23b,1,"",-1);
		if (opr3c_stats.unknown472c70(0x23b) == 3)
			opr3c_chance.unknown77fbc0(0x2e);
	}
}

void OpR3c_Overmind::unknown682770(int a, int b)
{
	if (b == 0)
		b = (int)opr3c_amounts[a];
	int previous = unknown8;
	unknown8 += b;
	opr3c_clamp(0,unknown8,99999);
}

OpR3c_Squad *OpR3c_Overmind::unknown683310(HEntity e)
{
	for (unsigned int i = 0; i < squads.size(); i++)
	{
		if (squads[i]->leader == e)
			return squads[i];
	}
	return NULL;
}

template <class T> void opr3c_deleteObject(vector<T *> &v, int index);	// NOTE: placeholder name (0x9da980)

bool OpR3c_Overmind::unknown683380(HEntity e, int *out)
{
	for (unsigned int i = 0; i < squads.size(); i++)
	{
		if (squads[i]->leader == e)
		{
			if (out)
				*out = squads[i]->unknown0;
			opr3c_deleteObject(squads,i);
			return true;
		}
	}
	return false;
}

int OpR3c_Overmind::unknown683410(HEntity e, vector<HEntity> &out)
{
	OpR3c_Squad *squad = unknown683310(e);
	if (squad == NULL)
		return 0;
	out.push_back(e);
	vector<HEntity> *members = world->unknown463890(3)->getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if ((*members)[i]->getAI() && (*members)[i]->getAI()->getFollowEntity() == e)
			out.push_back((*members)[i]);
	}
	return out.size();
}

// Rolls the turn at which the next surgical party is due: interval for this depth, Zone Cloak delay, 75 turns per
// disabled Garrison Access. Exploration pulls it earlier (BS::playerActionFinish), so the visited-block grid is cleared.
void OpR3c_Overmind::resetSurgicalTimer()
{
	surgicalTimer = world->getTurn() + ((opr3c_rifLevels[9] ? opr3c_zoneCloakDelay[opr3c_rifLevels[9]] : 0) + rng.rangeInt((float)opr3c_surgicalIntervals[opr3c_gameData.getDepthIndex()][0],(float)opr3c_surgicalIntervals[opr3c_gameData.getDepthIndex()][1])) + world->getDisabledGarrisonAccesses() * 75;
	surgicalExplored.fill(0);
}

void OpR3c_Overmind::unknown68d920(int a)
{
	if (unknown138 == 0 && opr3c_gameState->type == 0xe)
	{
		unknown138 = world->getTurn() + opr3c_dd31508.randomInRange_40c130();
		unknown13c = a;
	}
}

bool OpR3c_Overmind::unknown68e1a0()
{
	if (unknown100 || unknown4c != 0 || unknown34 != 0)
		return false;
	unknown100 = true;
	world->unknown7297a0();
	return true;
}
