// team_d_128: BS member 0x777190 (callers OpR5g_Obj::unknown96b930/96b9d0 and others): the run is won - record
// the win, choose which ending applies (from what the player carries, who escaped with them and the world
// state flags), log the ending phrase, award achievements and score bonuses, then end the game.
// NOTE: class layouts are partial; names other than BS/gameOver are placeholders. Local names follow the
// stack-slot hash order.
// NOTE: the robot classes carry file-unique names with throw() helpers so the stats call gets no EH
// state in the full build either.
#include <string>
#include <vector>
using namespace std;

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
int OpQ1_distanceCeil_40a3f0(const struct Point &a, const struct Point &b);	// NOTE: placeholder name
int opr1c_scaleRepeated(int value, int count, float factor);	// 0x4343d0, NOTE: placeholder name
bool OpV4c_Fn9d3f40(int *list, unsigned int count);	// NOTE: placeholder name
void gameOver();

struct Point
{
	int x;
	int y;
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
	const string &getName128();	// NOTE: placeholder name (Push_457860::operate)
};

class HItem
{
public:
	int ID;
	HItem();
	Item *operator->() const;	// NOTE: OpC_Handle::get224
	bool isValid() const;
};

class Entity128
{
public:
	int unknown45a880() throw();	// NOTE: placeholder name
	vector<HItem> *getInventoryList();
	int getFaction();
	const Point &getPosition();
	HItem unknown5d2a90(int type);	// NOTE: placeholder name
};

class HEntity128
{
public:
	int ID;
	Entity128 *operator->() const throw();
};

struct Group128	// NOTE: placeholder name
{
	vector<HEntity128> *getMembers128();	// NOTE: placeholder name (folded getter XCell::getFore)
};

class HGroup
{
public:
	int ID;
	Group128 *operator->();	// NOTE: OpC_Handle::get230
};

class OpV1_GameData
{
public:
	const string &getEntryText(const string &key);
};
extern OpV1_GameData gameData128_d1e860;	// NOTE: placeholder name

class Stats128	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
	void add472b90(unsigned int id, int value);
	int unknown472c70(int id);	// NOTE: placeholder name (Calls_472c70::delegate)
};
extern Stats128 stats128_d2c658;	// NOTE: placeholder name

class PlayerData128	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern PlayerData128 playerData128_cf45d8;	// NOTE: placeholder name

struct Phrase128	// NOTE: placeholder name (OpR1d_Phrase)
{
	int		id;
	int		number;
	int		label;	// +0x08
};
extern vector<Phrase128 *> phrases128_cf4d00;	// NOTE: placeholder name
void message128_5141b0(int id, const string *text, int b, int c, HProp e, int d);	// NOTE: placeholder name (0x5141b0)

struct Location128	// NOTE: placeholder name
{
	int		unknown00;
	int		type;	// +0x04
};

class HLocation128	// NOTE: placeholder name
{
public:
	int ID;
	Location128 *operator->() const;	// NOTE: OpC_Handle::get23c
};
extern HLocation128 location128_d1e888;	// NOTE: placeholder name

struct ScoreRecord128	// NOTE: placeholder name and layout
{
	char	pad00[0x4c];
	int		value;	// +0x4c
};
extern vector<ScoreRecord128 *> scores128_d389c4;	// NOTE: placeholder name

extern int ending128_cf4b38;		// NOTE: placeholder name
extern string endingNames128_cf6f30[];	// NOTE: placeholder name
extern int bonusMode128_cf4738;		// NOTE: placeholder name
extern int flags128_cf471c[];		// NOTE: placeholder name
extern const float factorA128_ba682c;	// NOTE: placeholder name (1.45)
extern const float factorB128_ba6840;	// NOTE: placeholder name (1.35)

class BS	// NOTE: placeholder layout
{
public:
	char			pad000[0x4c];
	vector<HGroup>	groups;		// +0x04c
	char			pad05c[0x66c - 0x5c];
	HEntity128			player;		// +0x66c

	int getTurn();
	void unknown464710(int value);	// NOTE: placeholder name
	bool unknown4641b0();	// NOTE: placeholder name
	bool unknown4641d0();	// NOTE: placeholder name
	void unknown777190(int ending);	// NOTE: placeholder name
};

void BS::unknown777190(int ending)
{
	unknown464710(4);
	stats128_d2c658.add4729d0(0x179,player->unknown45a880(),"",-1);
	if (ending != 0x1c)
		ending128_cf4b38 = ending;
	if (ending128_cf4b38 == 0x1c)
	{
		bool sigix = false;
		vector<HItem> *inv = player->getInventoryList();
		for (unsigned int i = 0; i < inv->size(); i++)
		{
			if ((*inv)[i]->getName128() == "Sigix Containment Pod")
			{
				stats128_d2c658.add472b90(0x53,-999999);
				sigix = true;
			}
			else if ((*inv)[i]->getName128() == "Sigix Corpse")
				stats128_d2c658.add472b90(0x52,-999999);
		}
		for (unsigned int j = 0; j < groups[2]->getMembers128()->size(); j++)
		{
			if ((*groups[2]->getMembers128())[j]->getFaction() == 0x5e && OpQ1_distanceCeil_40a3f0(player->getPosition(),(*groups[2]->getMembers128())[j]->getPosition()) <= 7)
			{
				stats128_d2c658.add472b90(0x54,-999999);
				sigix = true;
				break;
			}
		}
		if (!stringToInt(gameData128_d1e860.getEntryText("ac0GateDisabled_g")) && stringToInt(gameData128_d1e860.getEntryText("ac0StartedSingularityCount_g")))
			ending128_cf4b38 = 6;
		else if (sigix)
			ending128_cf4b38 = 3;
		else if (stringToInt(gameData128_d1e860.getEntryText("usedCoreResetMatrix_g")))
			ending128_cf4b38 = 2;
		else if (stringToInt(gameData128_d1e860.getEntryText("comWarlordVictory_g")))
			ending128_cf4b38 = 7;
		else if (stringToInt(gameData128_d1e860.getEntryText("comPlayerSurrenderedVictory_g")))
			ending128_cf4b38 = 8;
		else if (stringToInt(gameData128_d1e860.getEntryText("comMaincDestroyed_g")) && !stringToInt(gameData128_d1e860.getEntryText("comPlayerSurrenderedBefore_g")))
			ending128_cf4b38 = 1;
		else
			ending128_cf4b38 = 0;
	}
	if (ending128_cf4b38 <= 9)
	{
		do
		{
			message128_5141b0(0x2b,&endingNames128_cf6f30[ending128_cf4b38],0,0,HProp(),0);
		} while (0);
		phrases128_cf4d00.back()->label = -1;
	}
	if (unknown4641b0())
		playerData128_cf45d8.unknown77fbc0(0x130);
	if (unknown4641d0())
		playerData128_cf45d8.unknown77fbc0(0x13d);
	if (player->unknown5d2a90(0xd3).isValid())
		playerData128_cf45d8.unknown77fbc0(0x1d3);
	if (location128_d1e888->type != 0x21 && stringToInt(gameData128_d1e860.getEntryText("frgUfdBombsInstalled_g")))
		playerData128_cf45d8.unknown77fbc0(0x1dd);
	if (bonusMode128_cf4738)
		stats128_d2c658.add472b90(0xe,opr1c_scaleRepeated(scores128_d389c4[0xe]->value,0xb,factorA128_ba682c));
	if (!stats128_d2c658.unknown472c70(2))
		stats128_d2c658.add472b90(0x14,opr1c_scaleRepeated(scores128_d389c4[0x14]->value,0xb,factorB128_ba6840));
	stats128_d2c658.add472b90(0x67,-999999);
	if (OpV4c_Fn9d3f40(flags128_cf471c,0xc))
		stats128_d2c658.add472b90(0x69,-999999);
	else
	{
		int bonus = scores128_d389c4[0x68]->value / getTurn() - 5000;
		if (bonus > 0)
			stats128_d2c658.add472b90(0x68,bonus);
	}
	gameOver();
}
