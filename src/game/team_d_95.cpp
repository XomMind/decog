// team_d_95: member 0x68d980 of the security-level object (callers include BS::turnUpdate_51da30 and
// Entity::die): raises a high/maximum security lockdown (messages, stats, investigation squads, music).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

int stringToInt(const string &s);

struct Point
{
	int x;
	int y;

	Point();	// NOTE: placeholder name (Push_453b40::operate); makes Point a non-POD return type, as in the exe
};
Point OpU8a_randomPoint(vector<Point> &points);	// NOTE: placeholder name

class HProp
{
public:
	int ID;
	HProp();
};

class Entity;

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
};

class AI95	// NOTE: placeholder name (0x130-byte AI built by 0x57f6a0)
{
public:
	AI95(HEntity e, int a, int b);
	char pad[0x130];
};

class EntityAI
{
public:
	void unknown459540(const Point &p);	// NOTE: placeholder name
};

class Entity
{
public:
	void setAI(AI95 *ai);
	EntityAI *getAI();
	int unknown5d15a0(bool notify);	// NOTE: placeholder name
};

class Group95	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: folded getter
};

class HGroup
{
	int ID;
public:
	Group95 *operator->() const;	// NOTE: folded (OpC_Handle::get230)
};

struct World95	// NOTE: placeholder name and layout
{
	char	pad000[0x5b4];
	int		unknown5b4;	// +0x5b4

	int getTurn();
	int unknown4642d0();						// NOTE: placeholder name
	HEntity getPlayer();
	HGroup unknown463890(int i);				// NOTE: placeholder name
	void unknown714000(vector<Point> &out);		// NOTE: placeholder name
	int unknown714590(int &count, int &reachable);	// NOTE: placeholder name
};
extern World95 *world95_cefc4c;	// NOTE: placeholder name

class OpV1_GameData
{
public:
	const string &getEntryText(const string &key);
	bool unknown46f4b0(int a);	// NOTE: placeholder name
};
extern OpV1_GameData gameData95_d1e860;	// NOTE: placeholder name

struct Location95	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;
};

class HLoc95	// NOTE: placeholder name
{
	int ID;
public:
	Location95 *operator->() const;
};
extern HLoc95 location95_d1e888;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

class OpR1h_Stats
{
public:
	void add472b90(unsigned int id, int value);
	int count(int id);	// NOTE: placeholder name (Calls_472c70::delegate)
};
extern OpR1h_Stats stats95_d2c658;	// NOTE: placeholder name

struct StatRec95	// NOTE: placeholder name and layout
{
	char	pad00[0x4c];
	int		divisor;	// +0x4c
};
extern vector<StatRec95 *> statRecs95_d389c4;	// NOTE: placeholder name

class PlayerData
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern PlayerData playerData95_cf45d8;	// NOTE: placeholder name

class DataLoader95	// NOTE: placeholder name (0xcefaa8)
{
public:
	void unknown793690();	// NOTE: placeholder name
};
extern DataLoader95 *dataLoader95_cefaa8;	// NOTE: placeholder name
void opw8_unknown789ac0();
void opR1d_4541b0(int id, int a, int b);

class Popups95	// NOTE: placeholder name (OpW5_RolledValues at 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);
};
extern Popups95 *popups95_cefb48;	// NOTE: placeholder name

class ConsoleA95	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA95 *consoleA95_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs95_cec0b4;	// NOTE: placeholder name

bool showMessage95(int id, const string *text, const string *b, int c, HProp d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
void message95_5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name

class State95	// NOTE: placeholder name (object at 0xd25450)
{
public:
	bool unknown000;	// NOTE: placeholder name

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
};
extern State95 state95_d25450;	// NOTE: placeholder name
extern int threshold95_b91b8c;	// NOTE: placeholder name (1600)
extern int gameMode95_cf462c;	// NOTE: placeholder name
extern float value95_cf46f8;	// NOTE: placeholder name
extern bool flag95_d1ebfc;		// NOTE: placeholder name

class Security95	// NOTE: placeholder name and layout (OpS3g_A)
{
public:
	int		level;		// +0x00
	char	pad04[0x34 - 4];
	int		unknown34;	// +0x34 (lockdown turn)
	char	pad38[0x40 - 0x38];
	bool	unknown40;	// +0x40 (maximum lockdown)
	char	pad41[0x4c - 0x41];
	int		unknown4c;	// +0x4c
	char	pad50[0x194 - 0x50];
	bool	unknown194;
	bool	unknown195;
	bool	unknown196;

	void unknown68d6d0(bool flag);	// NOTE: placeholder name
	bool unknown68d980(bool force, bool quiet, bool maximum);	// NOTE: placeholder name
};

bool Security95::unknown68d980(bool force, bool quiet, bool maximum)
{
	if (stringToInt(gameData95_d1e860.getEntryText("comMaincReinforced_g")) || stringToInt(gameData95_d1e860.getEntryText("comMaincDestroyed_g")) || unknown4c != 0 || location95_d1e888->type == 0xd || location95_d1e888->type == 0xe || (location95_d1e888->type == 0x21 && stringToInt(gameData95_d1e860.getEntryText("frgUfdAttacked_g"))))
		return false;
	if (!force)
	{
		if (unknown34 != 0 || level < threshold95_b91b8c || !gameData95_d1e860.unknown46f4b0(1))
			return false;
		if (!rng.chance(5))
			return false;
		if (location95_d1e888->type == 0x21 && world95_cefc4c->unknown4642d0() < 4000)
			return false;
	}
	if (level < threshold95_b91b8c)
		level = threshold95_b91b8c;
	unknown34 = world95_cefc4c->getTurn();
	unknown40 = maximum;
	stats95_d2c658.add472b90(unknown40 ? 0x16 : 0x15,-999999);
	unknown194 = true;
	unknown195 = true;
	unknown196 = true;
	world95_cefc4c->unknown5b4 = -1;
	if (gameMode95_cf462c == 0xb)
	{
		value95_cf46f8 = 100.0f;
		dataLoader95_cefaa8->unknown793690();
		opw8_unknown789ac0();
	}
	unknown68d6d0(false);
	if (location95_d1e888->type == 0x21)
		flag95_d1ebfc = true;
	if (!quiet)
	{
		if (unknown40)
		{
			do
			{
				if (showMessage95(0x324,&string("ALERT: Maximum security lockdown engaged."),0,0,HProp(),HProp(),0,0))
					consoleA95_cec058->unknown8758d0(true);
				logMsgs95_cec0b4->scrollToEnd();
			} while (0);
			do
			{
				message95_5141b0(0x6d,0,0,0,HProp(),0);
			} while (0);
		}
		else
		{
			do
			{
				if (showMessage95(0x324,&string("ALERT: High security lockdown imminent, T-100."),0,0,HProp(),HProp(),0,0))
					consoleA95_cec058->unknown8758d0(true);
				logMsgs95_cec0b4->scrollToEnd();
			} while (0);
			do
			{
				message95_5141b0(0x6b,0,0,0,HProp(),0);
			} while (0);
		}
		if (popups95_cefb48)
			popups95_cefb48->say(0x32,false,"");
	}
	if (stats95_d2c658.count(0x15) / statRecs95_d389c4[0x15]->divisor + stats95_d2c658.count(0x16) / statRecs95_d389c4[0x16]->divisor == 4)
		playerData95_cf45d8.unknown77fbc0(0x15c);
	if (unknown40)
		playerData95_cf45d8.unknown77fbc0(0x13f);
	opR1d_4541b0(0x11e,0,0);
	if (location95_d1e888->type != 0x22 && location95_d1e888->type != 5)
	{
		vector<Point> points;
		world95_cefc4c->unknown714000(points);
		if (points.empty())
		{
		}
		else
		{
			vector<HEntity> *members = world95_cefc4c->unknown463890(4)->getMembers();
			for (unsigned int i = 0; i < members->size(); i++)
			{
				(*members)[i]->setAI(new AI95((*members)[i],0x19,0xe));
				(*members)[i]->getAI()->unknown459540(OpU8a_randomPoint(points));
			}
		}
	}
	if (state95_d25450.unknown000)
	{
		if (unknown40)
			state95_d25450.unknown69e700(0x2f,0,0.0f);
		else
		{
			bool far = false;
			if (world95_cefc4c->getPlayer()->unknown5d15a0(false) >= 100)
			{
				int count;
				int x;
				int dist = world95_cefc4c->unknown714590(count,x);
				if (dist == -1 || dist > 0x1e)
					far = true;
			}
			state95_d25450.unknown69e700(0x2e,far ? 1 : 0,0.0f);
		}
	}
	return true;
}
