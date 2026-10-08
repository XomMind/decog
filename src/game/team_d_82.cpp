// team_d_82: BS member 0x738310 (Exiles base attacked: evacuation announcement, clears tagged props and
// robots, scripts the Exiles' evacuation dialogue).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct Pos : public Point
{
	Pos(int x_, int y_);	// 0x46ca20
};

struct OpQ1_Box
{
	int x1;
	int y1;
	int x2;
	int y2;

	OpQ1_Box(int a, int b, int c, int d);
};

class HProp;

class Prop
{
public:
	int unknown45c800(int type);			// NOTE: placeholder name
	bool unknown665be0(bool flag);			// NOTE: placeholder name
};

class HProp
{
public:
	int ID;
	HProp();
	bool isValid() const;
	Prop *operator->() const;
};

class EntityAI
{
public:
	void unknown459540(const Point &p);		// NOTE: placeholder name
	void unknown459470(const OpQ1_Box &area);	// NOTE: placeholder name
};

class Entity
{
public:
	bool isPlayer();
	int unknown45acb0(int value);			// NOTE: placeholder name
	void removeEffectsA(bool onlyInactive);	// NOTE: placeholder name (0x639730)
	const string &getName();
	EntityAI *getAI();
};

class HEntity
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const;
};

class Cell
{
public:
	HProp getProp();
	HEntity getEntity();
};

class CellGrid82	// NOTE: placeholder name (0xcfd44c)
{
public:
	int getWidth();
	int getHeight();
	Cell **at(int x, int y);	// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid82 cells82_cfd44c;	// NOTE: placeholder name

class Group82	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: folded getter
};

class HGroup
{
	int ID;
public:
	Group82 *operator->() const;	// NOTE: folded (OpC_Handle::get230)
};

class OpV1_GameData
{
public:
	void setEntryText(const string &key, const string &text);
};
extern OpV1_GameData gameData82_d1e860;	// NOTE: placeholder name

class MessageLog82	// NOTE: placeholder name (0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name (folded with a protobuf SetCachedSize)
};
extern MessageLog82 messageLog82_cf1080;	// NOTE: placeholder name

class ConsoleA82	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA82 *consoleA82_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs82_cec0b4;	// NOTE: placeholder name

void opR1d_4541b0(int id, int a, int b);
bool showMessage82(int id, const string *text, const string *b, int c, HProp d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
void message82_5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name
bool OpU8a_removeEntity(vector<HProp> &v, HProp e);	// NOTE: placeholder name (the exe's takes an HEntity-typed handle)
extern bool flag82_d28fb0;	// NOTE: placeholder name
extern int value82_d1eac8;	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	char			pad000[0x4c];
	vector<HGroup>	groups;		// +0x4c
	char			pad05c[0x320 - 0x5c];
	int				unknown320;	// +0x320
	char			pad324[0x4f0 - 0x324];
	vector<HProp>	unknown4f0;	// +0x4f0

	void removeEntity(HEntity e);
	void unknown6c65a0(HEntity e, const string &text, int value);
	void unknown738310();	// NOTE: placeholder name
};

void BS::unknown738310()
{
	gameData82_d1e860.setEntryText("exiMaincAttacked_g","1");
	do
	{
		messageLog82_cf1080.unknown451400(1);
		if (1)
		{
			if (!(flag82_d28fb0 && 1 && 0))
				opR1d_4541b0(0x12d,0,0);
		}
		do
		{
			if (showMessage82(0x324,&string("EXILES: Incoming Unaware force detected on approach from Mines. Prepare for evacuation."),0,0,HProp(),HProp(),0,0))
				consoleA82_cec058->unknown8758d0(true);
			logMsgs82_cec0b4->scrollToEnd();
		} while (0);
		logMsgs82_cec0b4->scrollToEnd();
	} while (0);
	do
	{
		message82_5141b0(0x137,0,0,0,HProp(),0);
	} while (0);
	value82_d1eac8 = unknown320;
	for (int x = 0; x < cells82_cfd44c.getWidth(); x++)
	{
		for (int y = 0; y < cells82_cfd44c.getHeight(); y++)
		{
			if ((*cells82_cfd44c.at(x,y))->getProp().isValid() && !(*cells82_cfd44c.at(x,y))->getProp()->unknown45c800(0x85))
			{
				(*cells82_cfd44c.at(x,y))->getProp()->unknown665be0(false);
				OpU8a_removeEntity(unknown4f0,(*cells82_cfd44c.at(x,y))->getProp());
			}
			if ((*cells82_cfd44c.at(x,y))->getEntity().isValid() && !(*cells82_cfd44c.at(x,y))->getEntity()->isPlayer() && !(*cells82_cfd44c.at(x,y))->getEntity()->unknown45acb0(0x85))
			{
				removeEntity((*cells82_cfd44c.at(x,y))->getEntity());
				(*cells82_cfd44c.at(x,y))->getEntity()->removeEffectsA(true);
			}
		}
	}
	vector<HEntity> members(*groups[9]->getMembers());
	for (int i = members.size() - 1; i >= 0; i--)
	{
		if (members[i]->getName() == "8R-AWN")
		{
			members[i]->getAI()->unknown459540(Pos(0x37,0x2c));
			unknown6c65a0(members[i],"EXI_Brawn_Defense_Talk",0);
			unknown6c65a0(members[i],"EXI_Brawn_Death",0);
		}
		else if (members[i]->getName() == "EX-BIN")
		{
			unknown6c65a0(members[i],"EXI_Bin_Evac_Actions",0);
			unknown6c65a0(members[i],"EXI_Bin_Death",0);
		}
		else if (members[i]->getName() == "EX-DEC")
		{
			unknown6c65a0(members[i],"EXI_Dec_Evac_Actions",0);
			unknown6c65a0(members[i],"EXI_Dec_Death",0);
		}
		else if (members[i]->getName() == "EX-HEX")
			unknown6c65a0(members[i],"EXI_Hex_Evac_Actions",0);
		else if (members[i]->getName() == "Zionite")
			members[i]->getAI()->unknown459470(OpQ1_Box(0x31,0x52,0x43,0x58));
	}
}
