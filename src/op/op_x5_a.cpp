// op_x5_a: CRpglikeUpgrades::update (0x8798b0), matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <deque>
#include <list>
using namespace std;

struct Pos
{
	int x;
	int y;
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool isActive();	// NOTE: placeholder name
	virtual void refresh();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	bool isHidden();
	void setHidden(bool hidden);
	float getScaleX();
	void unknown417b60(float value);	// NOTE: placeholder name (scale x)
	void unknown417b80(float value);	// NOTE: placeholder name (scale y)
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)
	void removeSubconsole(XConsole *console);
	XConsole *getParent();	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class OpR2b_Engine	// NOTE: placeholder name
{
public:
	void stopAll();	// NOTE: placeholder name (0x50ff30)
	bool update();	// NOTE: placeholder name (0x50fff0)
};

class Console : public XConsole
{
public:
	int unknown60;
	OpR2b_Engine *engine;
	void *title;
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp();	// 0x9b6590
};

class Entity	// NOTE: placeholder layout
{
public:
	void unknown5c94e0(int slot, HProp value);	// NOTE: placeholder name
	void unknown5de870(int amount, bool linked);	// NOTE: placeholder name
	int unknown448fe0(int type);	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	Entity *operator->() const throw();	// 0x9b6570
};

class OpX5A_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
};
extern OpX5A_Map *opX5A_map;	// NOTE: placeholder name (0xcefc4c)

class OpR1h_Stats	// NOTE: placeholder name
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra) throw();	// NOTE: placeholder name (0x4729d0)
};
extern OpR1h_Stats opX5A_stats;	// NOTE: placeholder name (0xd2c658)

class PlayerData	// NOTE: partial
{
public:
	bool unknown77fbc0(int type);	// NOTE: placeholder name
};
extern PlayerData opX5A_playerData;	// NOTE: placeholder name (0xcf45d8)

class OpS_Graph	// NOTE: placeholder name
{
public:
	void popFrame();	// 0x416640
};
extern OpS_Graph *opX5A_graph;	// NOTE: placeholder name (0xcefa8c)

class OpX5A_Parts	// NOTE: placeholder name (CParts at 0xcec088)
{
public:
	void unknown897160(int slot);	// NOTE: placeholder name
};
extern OpX5A_Parts *opX5A_parts;	// NOTE: placeholder name (0xcec088)

class OpX5A_Inventory	// NOTE: placeholder name (CInventory at 0xcec08c)
{
public:
	void unknown8a5b20(int slot);	// NOTE: placeholder name
};
extern OpX5A_Inventory *opX5A_inventory;	// NOTE: placeholder name (0xcec08c)

class OpX5A_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpX5A_MsgConsole *opX5A_msgConsole;	// NOTE: placeholder name (0xcec058)

class OpX5A_LogMsgs	// NOTE: placeholder name (CLogMsgs at 0xcec0b4)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpX5A_LogMsgs *opX5A_logMsgs;	// NOTE: placeholder name (0xcec0b4)

struct OpX5A_StatInfo	// NOTE: placeholder name
{
	char pad00[0x20];
	string name;	// NOTE: placeholder name
};
extern vector<OpX5A_StatInfo*> opX5A_statInfo;	// NOTE: placeholder name (0xd389c4)
extern string opX5A_upgradeNames[];	// NOTE: placeholder name (0xd378d0)

// NOTE: the verifier pairs a data symbol only at offset 0, so a column of the table at 0xba7930 is reached through a view
struct OpX5A_UpgradeInfoView	// NOTE: placeholder name
{
	int value;
	int pad[3];
};
extern OpX5A_UpgradeInfoView opX5A_upgradeStep[];	// NOTE: placeholder name (0xba7938)

string intToString(int value);
int *opW5_getUpgradeValue(int id);	// NOTE: placeholder name
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)
void opR1d_4541b0(int sound, int a, int b);	// NOTE: placeholder name
bool OpX5A_message5141b0(int id, const string &text, const string &value, int a, HProp prop, int b);	// NOTE: placeholder name
bool OpX5A_message5111e0(int id, const string &title, const string &text, int a, HProp first, HProp second, int b, int c);	// NOTE: placeholder name
extern int opX5A_cf469c;	// NOTE: placeholder name

class CRpglikeUpgrades : public Console
{
public:
	virtual void update();

	int unknown6c;	// NOTE: placeholder name
	char pad70[0x94 - 0x70];
	int unknown94;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
	int unknown9c;	// NOTE: placeholder name
	vector<int> unknowna0;	// NOTE: placeholder name
	bool unknownb0;	// NOTE: placeholder name
};

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

void CRpglikeUpgrades::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
			break;	// NOTE: stray break before the first case (dead jmp in the exe)
		case 1:
			if (!engine->update())
				unknown60 = 3;
			break;
			break;	// NOTE: stray break (dead jmp in the exe)
		case 4:
			engine->update();
			if (getScaleX() != 0.0f)
			{
				if (tickCount - unknown6c >= 500)
				{
					unknown417b60(0.0f);
					unknown417b80(0.0f);
				}
				else
				{
					unknown417b60(1.0 - (tickCount - unknown6c) / 500.0);
					unknown417b80(1.0 - (tickCount - unknown6c) / 500.0);
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			opX5A_graph->popFrame();
			if (unknownb0)
			{
				bool statsChanged = false;
				bool upgraded = false;
				for (int i = 0; i < unknowna0.size(); i++)
				{
					if (unknowna0[i] != 0)
					{
						if (i <= 3)
						{
							int type = i;
							for (int j = 0; j < unknowna0[i]; j++)
							{
								opX5A_map->getPlayer()->unknown5c94e0(type,HProp());
								opX5A_stats.add4729d0(0x6b,1,"",-1);
								opX5A_stats.add4729d0(type + 0x6c,1,"",-1);
							}
							do
							{
								OpX5A_message5141b0(0x2d,opX5A_upgradeNames[type],intToString(unknowna0[i]),0,HProp(),0);
							}
							while (0);
							statsChanged = true;
							if (opX5A_map->getPlayer()->unknown448fe0(3) >= 7)
								opX5A_playerData.unknown77fbc0(0x8b);
						}
						else
						{
							int amount = unknowna0[i] * opX5A_upgradeStep[i].value;
							*opW5_getUpgradeValue(i) += amount;
							upgraded = true;
							if (i == 4)
								opX5A_map->getPlayer()->unknown5de870(amount,false);
							if (OpT8b_Fn9daf80(0x15,i,0x17))
							{
								opX5A_parts->unknown897160(i);
								opX5A_inventory->unknown8a5b20(i);
							}
						}
						string text = "+" + intToString(unknowna0[i] * opX5A_upgradeStep[i].value);
						do
						{
							if (OpX5A_message5111e0(0x2fa,opX5A_statInfo[i + 0x429]->name,text,0,HProp(),HProp(),0,0))
								opX5A_msgConsole->unknown8758d0(true);
							opX5A_logMsgs->scrollToEnd();
						}
						while (0);
						opX5A_stats.add4729d0(0x428,unknowna0[i],"",-1);
						opX5A_stats.add4729d0(i + 0x429,unknowna0[i],"",-1);
					}
				}
				opX5A_stats.add4729d0(0x427,opX5A_cf469c - unknown9c,"",-1);
				opX5A_cf469c = unknown9c;
				if (statsChanged)
					opR1d_4541b0(0xc8,0,0);
				if (upgraded)
					opR1d_4541b0(0xcb,0,0);
			}
			getParent()->removeSubconsole(this);
			break;
	}
	updateBase429e30();
}
