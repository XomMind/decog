// team_d_73: BS members 0x7409f0 (the Warlord's forces turn hostile after attacking the locals) and
// 0x740300 (the Warlord's forces declare against Cogmind or the Sigix).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

int stringToInt(const string &s);

struct Point
{
	int x;
	int y;
};
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);

struct Area73	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;
};

class HProp
{
public:
	int ID;
	HProp();
};

class Entity;
class EntityAI;

class HEntity
{
public:
	int ID;
	HEntity();	// NOTE: folded with HProp::HProp
	bool isValid() const;
	bool isNull() const;
	void resetField();	// NOTE: placeholder name (Sweep_9b7270::resetField)
	Entity *operator->() const;
	bool operator==(HEntity e) const;
};

class Group73	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: folded getter
};

class HGroup
{
	int ID;
public:
	Group73 *operator->() const;	// NOTE: folded (OpC_Handle::get230)
};

class EntityAI
{
public:
	void unknown459410(const Area73 &area);	// NOTE: placeholder name
};

class AI73	// NOTE: placeholder name (0x130-byte AI built by 0x57f6a0)
{
public:
	AI73(HEntity e, int a, int b);
	char pad[0x130];
};

class Entity
{
public:
	void unknown6396f0(const string &talk, int flag);	// NOTE: placeholder name
	void changeFaction(HGroup newGroup, bool flag);
	void setAI(AI73 *ai);
	EntityAI *getAI();
	int getTarget();
	int getFaction();
	Point &getPosition();
};

class OpV1_GameData
{
public:
	const string &getEntryText(const string &key);
	void setEntryText(const string &key, const string &text);
};
extern OpV1_GameData gameData73_d1e860;	// NOTE: placeholder name

class CellGrid73	// NOTE: placeholder name (0xcfd44c)
{
public:
	Area73 getArea();
};
extern CellGrid73 cells73_cfd44c;	// NOTE: placeholder name

class State73	// NOTE: placeholder name (object at 0xd25450)
{
public:
	bool unknown000;	// NOTE: placeholder name

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
};
extern State73 state73_d25450;	// NOTE: placeholder name

HEntity OpX5_randomRecord(vector<HEntity> &v);	// NOTE: placeholder name
void message73_5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name

class MessageLog73	// NOTE: placeholder name (0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name (folded with a protobuf SetCachedSize)
};
extern MessageLog73 messageLog73_cf1080;	// NOTE: placeholder name

class ConsoleA73	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA73 *consoleA73_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs73_cec0b4;	// NOTE: placeholder name

void opR1d_4541b0(int id, int a, int b);
bool showMessage73(int id, const string *text, const string *b, int c, HProp d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
extern bool flag73_cf4a00;	// NOTE: placeholder name

struct Ally73	// NOTE: placeholder name and layout
{
	Point	pos;		// +0x00
	char	pad08[5];
	bool	unknown0d;	// +0x0d
};

class BS	// NOTE: placeholder layout
{
public:
	char			pad000[0x10];
	vector<Ally73 *>	allies;	// +0x10
	char			pad020[0x4c - 0x20];
	vector<HGroup>	groups;		// +0x4c
	char			pad05c[0x66c - 0x5c];
	HEntity			player;		// +0x66c
	char			pad670[0x8c4 - 0x670];
	int				unknown8c4;	// +0x8c4

	HEntity unknown715230(int group, int faction);
	bool unknown463400(HEntity e);	// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &text, int value);
	void unknown7409f0(bool quiet);	// NOTE: placeholder name
	void unknown740300(bool quiet);	// NOTE: placeholder name
};

void BS::unknown7409f0(bool quiet)
{
	if (stringToInt(gameData73_d1e860.getEntryText("warAttackedLocals_g")))
		return;
	gameData73_d1e860.setEntryText("warAttackedLocals_g","1");
	gameData73_d1e860.setEntryText("garCommArraySupport_g","0");
	if (!quiet)
	{
		do
		{
			message73_5141b0(0x215,0,0,0,HProp(),0);
		} while (0);
	}
	if (state73_d25450.unknown000)
		state73_d25450.unknown69e700(0x76,0,0.0f);
	HEntity unit = unknown715230(9,0x5b);
	if (unit.isValid())
		unit->unknown6396f0("RES_Warlord_Sigix_Check",1);
	Area73 area = cells73_cfd44c.getArea();
	vector<HEntity> targets(*groups[9]->getMembers());
	HEntity closest;
	int first = 9999;
	for (int i = targets.size() - 1; i >= 0; i--)
	{
		targets[i]->changeFaction(groups[5],false);
		targets[i]->setAI(new AI73(targets[i],0x22,0xe));
		targets[i]->getAI()->unknown459410(area);
		if (unknown463400(targets[i]) && !targets[i]->getTarget())
		{
			int dist = OpQ1_distanceCeil_40a3f0(targets[i]->getPosition(),player->getPosition());
			if (closest.isNull())
			{
				closest = targets[i];
				first = dist;
			}
			else if (dist < first)
			{
				closest = targets[i];
				first = dist;
			}
		}
	}
	if (closest.isNull() && unit.isValid() && unit->getTarget() != 8)
		closest = unit;
	if (closest.isNull() && !targets.empty())
	{
		closest = OpX5_randomRecord(targets);
		if (closest == unit && unit->getTarget() == 8)
			closest.resetField();
	}
	if (closest.isValid())
		unknown6c65a0(closest,"COM_Warlord_Hostile_T",0);
}

void BS::unknown740300(bool quiet)
{
	if (unknown8c4 == 5)
		return;
	gameData73_d1e860.setEntryText("warAttackedLocals_g","1");
	gameData73_d1e860.setEntryText("garCommArraySupport_g","0");
	unknown8c4 = 5;
	if (flag73_cf4a00)
	{
		do
		{
			messageLog73_cf1080.unknown451400(1);
			if (0)
				opR1d_4541b0(-1,0,0);
			do
			{
				if (showMessage73(0x324,&string("ANNOUNCEMENT: Sigix threat confirmed. Defend the planet!"),0,0,HProp(),HProp(),0,0))
					consoleA73_cec058->unknown8758d0(true);
				logMsgs73_cec0b4->scrollToEnd();
			} while (0);
			logMsgs73_cec0b4->scrollToEnd();
		} while (0);
	}
	else
	{
		do
		{
			messageLog73_cf1080.unknown451400(1);
			if (0)
				opR1d_4541b0(-1,0,0);
			do
			{
				if (showMessage73(0x324,&string("ANNOUNCEMENT: Cogmind has turned on us. Destroy the traitor."),0,0,HProp(),HProp(),0,0))
					consoleA73_cec058->unknown8758d0(true);
				logMsgs73_cec0b4->scrollToEnd();
			} while (0);
			logMsgs73_cec0b4->scrollToEnd();
		} while (0);
	}
	if (!quiet)
	{
		do
		{
			message73_5141b0(0x1cc,0,0,0,HProp(),0);
		} while (0);
	}
	if (state73_d25450.unknown000)
		state73_d25450.unknown69e700(0x70,0,0.0f);
	vector<HEntity> *members = groups[9]->getMembers();
	for (unsigned int i = 0; i < members->size(); i++)
	{
		if ((*members)[i]->getFaction() == 0x5b)
		{
			(*members)[i]->unknown6396f0("RES_Warlord_Dialogue",1);
			(*members)[i]->unknown6396f0("RES_Warlord_Sigix_Check",1);
			if (!quiet)
			{
				unknown6c65a0((*members)[i],"RES_Warlord_Dialogue2",0);
				unknown6c65a0((*members)[i],"RES_Warlord_Dialog2_End",0);
			}
			break;
		}
	}
	for (int j = members->size() - 1; j >= 0; j--)
		(*members)[j]->changeFaction(groups[5],false);
	if (!quiet && !stringToInt(gameData73_d1e860.getEntryText("enemiesWithArchitect_g")))
	{
		for (unsigned int k = 0; k < allies.size(); k++)
		{
			if (allies[k]->unknown0d && OpQ1_distanceCeil_40a3f0(allies[k]->pos,player->getPosition()) <= 15)
				return;
		}
		unknown6c65a0(player,"RES_Architect_Support",0);
	}
}
