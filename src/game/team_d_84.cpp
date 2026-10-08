// team_d_84: BS member 0x7480e0 (lab breach: scan effects, alert messages, scan triggers, A5 spawn,
// wakes the ARM robots).
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
	const string &getName();				// NOTE: placeholder name (Push_45c590::operate)
	void unknown45ce10(bool a, int b, bool c, HProp p);	// NOTE: placeholder name
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
	void unknown459410(const OpQ1_Box &area);	// NOTE: placeholder name
};

struct EntityEffect;
class AI84	// NOTE: placeholder name (0x130-byte AI built by 0x57f6a0)
{
public:
	AI84(class HEntity e, int a, int b);
	char pad[0x130];
};

class Entity
{
public:
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	bool unknown45ad20(const string &tag);	// NOTE: placeholder name
	void changeFaction(class HGroup newGroup, bool flag);
	void setAI(AI84 *ai);
	int getTarget();
	int getFaction();
	void unknown5fdab0();					// NOTE: placeholder name (Push_5fdab0::operate)
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
	void unknown670ed0();	// NOTE: placeholder name
	HProp getProp();
	HEntity getEntity();
};

class CellGrid84	// NOTE: placeholder name (0xcfd44c)
{
public:
	int getWidth();
	int getHeight();
	Cell **at(int x, int y);	// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid84 cells84_cfd44c;	// NOTE: placeholder name

class Group84	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: folded getter
};

class HGroup
{
	int ID;
public:
	Group84 *operator->() const;	// NOTE: folded (OpC_Handle::get230)
};

int stringToInt(const string &s);

class State84	// NOTE: placeholder name (object at 0xd25450)
{
public:
	bool unknown000;	// NOTE: placeholder name

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
};
extern State84 state84_d25450;	// NOTE: placeholder name

void opW5_message(int type, HProp prop, const string &text, int value);	// NOTE: placeholder name
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)
void opr2c_playEffect_55ca10(int id, const Point &from, Point *p1);	// NOTE: placeholder name (0x55ca10)

class OpV1_GameData
{
public:
	const string &getEntryText(const string &key);
	void setEntryText(const string &key, const string &text);
};
extern OpV1_GameData gameData84_d1e860;	// NOTE: placeholder name

class MessageLog84	// NOTE: placeholder name (0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name (folded with a protobuf SetCachedSize)
};
extern MessageLog84 messageLog84_cf1080;	// NOTE: placeholder name

class ConsoleA84	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA84 *consoleA84_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs84_cec0b4;	// NOTE: placeholder name

void opR1d_4541b0(int id, int a, int b);
bool showMessage84(int id, const string *text, const string *b, int c, HProp d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
void message84_5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name
bool OpU8a_removeEntity(vector<HProp> &v, HProp e);	// NOTE: placeholder name (the exe's takes an HEntity-typed handle)
extern int value84_d1ebcc;	// NOTE: placeholder name

class OpR1h_Stats
{
public:
	void add472b90(unsigned int id, int value);
};
extern OpR1h_Stats stats84_d2c658;	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	HGroup unknown463890(int i);	// NOTE: placeholder name
	bool unknown6c6b90(const Point &p, const string &type, int a, int b);	// NOTE: placeholder name
	void unknown7480e0(bool alert);	// NOTE: placeholder name
};

void BS::unknown7480e0(bool alert)
{
	int *id;
	vector<HEntity> *list;
	if (OpU8a_lookup2("P_Lab_Scan_E",(int *)&id))
	{
		for (int a = 1; a <= 0x30; a++)
			opr2c_playEffect_55ca10(*id,Pos(a,6),&Pos(a,0x22));
		if (OpU8a_lookup2("P_Lab_Scan_Sound",(int *)&id))
			opr2c_playEffect_55ca10(*id,Pos(0x11,0x13),0);
	}
	if (OpU8a_lookup2("P_Lab_Scan_LC_Area",(int *)&id))
	{
		for (int b = 0x22; b <= 0x28; b++)
			opr2c_playEffect_55ca10(*id,Pos(3,b),0);
		for (int c = 4; c <= 6; c++)
			opr2c_playEffect_55ca10(*id,Pos(c,0x28),0);
		OpQ1_Box box(7,0x27,0xa,0x2a);
		for (int x = box.x1; x <= box.x2; x++)
		{
			for (int y = box.y1; y <= box.y2; y++)
				opr2c_playEffect_55ca10(*id,Pos(x,y),0);
		}
	}
	if (alert)
	{
		opW5_message(0x320,HProp(),string("Scanners sweep the area."),0);
		do
		{
			messageLog84_cf1080.unknown451400(1);
			if (0)
				opR1d_4541b0(-1,0,0);
			do
			{
				if (showMessage84(0x324,&string("A0_COM: INTRUDER ALERT."),0,0,HProp(),HProp(),0,0))
					consoleA84_cec058->unknown8758d0(true);
				logMsgs84_cec0b4->scrollToEnd();
			} while (0);
			logMsgs84_cec0b4->scrollToEnd();
		} while (0);
		do
		{
			message84_5141b0(0x1e5,0,0,0,HProp(),0);
		} while (0);
	}
	else
	{
		do
		{
			messageLog84_cf1080.unknown451400(1);
			if (0)
				opR1d_4541b0(-1,0,0);
			do
			{
				if (showMessage84(0x324,&string("A0_COM: LAB BREACHED."),0,0,HProp(),HProp(),0,0))
					consoleA84_cec058->unknown8758d0(true);
				logMsgs84_cec0b4->scrollToEnd();
			} while (0);
			logMsgs84_cec0b4->scrollToEnd();
		} while (0);
		opW5_message(0x320,HProp(),string("Scanners sweep the area."),0);
		do
		{
			message84_5141b0(0x1e6,0,0,0,HProp(),0);
		} while (0);
	}
	gameData84_d1e860.setEntryText("labAlerted_g","1");
	for (int x2 = 0; x2 < cells84_cfd44c.getWidth(); x2++)
	{
		for (int y2 = 0; y2 < cells84_cfd44c.getHeight(); y2++)
		{
			if ((*cells84_cfd44c.at(x2,y2))->getProp().isValid() && (*cells84_cfd44c.at(x2,y2))->getProp()->getName() == "LAB_Scan_Trigger")
				(*cells84_cfd44c.at(x2,y2))->getProp()->unknown45ce10(true,0,true,HProp());
		}
	}
	gameData84_d1e860.setEntryText("enemiesWithArchitect_g","1");
	unknown6c6b90(Pos(0x24,0x13),"LAB_Spawn_A5",0,-1);
	list = unknown463890(1)->getMembers();
	if (!list->empty())
	{
		for (int i = list->size() - 1; i >= 0; i--)
		{
			if ((*list)[i]->unknown45ad20("ARM_Wakeup"))
				(*list)[i]->changeFaction(unknown463890(5),true);
		}
	}
	if (state84_d25450.unknown000)
		state84_d25450.unknown69e700(0x6c,0,0.0f);
}
