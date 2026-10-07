// team_d_65: member 0x780ac0 of the object behind the +0x42c/+0x43c/+0x44c lists (RIF installation:
// records the turn, unlocks the RIF ability slots and reports Garrison-access abilities).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

string intToString(int value);
int stringToInt(const string &s);

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

class Item65	// NOTE: placeholder name
{
public:
	int unknown457f90();									// NOTE: placeholder name
	string unknown571db0(int a, int b);						// NOTE: placeholder name (name text)
	void unknown57dbe0(int a, int b, int c, int d);			// NOTE: placeholder name
};

class HItem65	// NOTE: placeholder name
{
public:
	int ID;
	Item65 *operator->() const;
};

class Entity
{
public:
	void unknown5cb8b0(vector<HItem65> &items);	// NOTE: placeholder name
};

class Map
{
public:
	HEntity getPlayer();
	int getTurn();
};
extern Map *world65_cefc4c;	// NOTE: placeholder name

class OpV1_GameData
{
public:
	const string &getEntryText(const string &key);
	void setEntryText(const string &key, const string &text);
};
extern OpV1_GameData gameData65_d1e860;	// NOTE: placeholder name

struct Location65	// NOTE: placeholder name and layout
{
	int unknown00;
	int unknown04;
	int unknown08;
};

class HLoc65	// NOTE: placeholder name
{
	int ID;
public:
	Location65 *operator->() const;
};
extern HLoc65 location65_d1e888;	// NOTE: placeholder name

class DataLoader65	// NOTE: placeholder name (0xcefaa8)
{
public:
	void unknown793690();	// NOTE: placeholder name
};
extern DataLoader65 *dataLoader65_cefaa8;	// NOTE: placeholder name

void opw8_unknown789ac0();

class PhraseText65	// NOTE: placeholder name (OpS2_PhraseTextB)
{
public:
	PhraseText65(int id, string *a, string *b, string *c, HProp e1, HProp e2);
	char pad[0x28];
};

class MessageLog
{
public:
	int push(PhraseText65 *text);
};
extern MessageLog messageLog65_cf1080;	// NOTE: placeholder name

class ConsoleA65	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA65 *consoleA65_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs65_cec0b4;	// NOTE: placeholder name

bool showMessage65(int id, const string &text, const string *b, int c, HEntity d, HProp e, const struct Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
void message65_5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name

class Owner65	// NOTE: placeholder name and layout
{
public:
	char					pad000[0x42c];
	vector<int>				unknown42c;
	vector<unsigned int>	unknown43c;
	vector<int>				unknown44c;

	void unknown780ac0();	// NOTE: placeholder name
};

void Owner65::unknown780ac0()
{
	if (stringToInt(gameData65_d1e860.getEntryText("installedRif_g")))
		return;
	gameData65_d1e860.setEntryText("installedRif_g",intToString(world65_cefc4c->getTurn()));
	gameData65_d1e860.setEntryText("garCommArraySupport_g","0");
	for (int i = 0; i <= 2; i++)
	{
		unknown42c[i] = 1;
		unknown43c.push_back(i);
		unknown44c.push_back(location65_d1e888->unknown08);
	}
	dataLoader65_cefaa8->unknown793690();
	opw8_unknown789ac0();
	do
	{
		if (messageLog65_cf1080.push(new PhraseText65(0x29a,0,0,0,HProp(),HProp())))
			consoleA65_cec058->unknown8758d0(true);
		logMsgs65_cec0b4->scrollToEnd();
	} while (0);
	do
	{
		message65_5141b0(0x192,0,0,0,HProp(),0);
	} while (0);
	vector<HItem65> parts;
	world65_cefc4c->getPlayer()->unknown5cb8b0(parts);
	for (unsigned int k = 0; k < parts.size(); k++)
	{
		if (parts[k]->unknown457f90() == 0xd2)
		{
			do
			{
				if (showMessage65(0x29e,parts[k]->unknown571db0(0,0),0,0,world65_cefc4c->getPlayer(),HProp(),0,0))
					consoleA65_cec058->unknown8758d0(true);
				logMsgs65_cec0b4->scrollToEnd();
			} while (0);
			parts[k]->unknown57dbe0(1,0,1,1);
		}
	}
}
