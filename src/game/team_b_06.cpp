// team_b_06: game-logic helpers (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1), batch 4.
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
// NOTE: MSVC's stack layout depends on local variable names; the names below were chosen to match.
#include <string>
#include <vector>
using namespace std;

class Entity;
class EntityAI;
class HEntity { public: int ID; HEntity(); Entity *operator->() const; bool operator==(HEntity other) const; };
class Group { public: vector<HEntity> *getMembers(); };	// NOTE: placeholder name (ICF'd member address getter)
class HGroup { public: int ID; HGroup(); Group *operator->() const; };
class Entity { public: HGroup getGroup(); EntityAI *getAI(); };
class EntityAI
{
public:
	HEntity self;
	HEntity getFollowEntity();
	bool getFollowers580a90(vector<HEntity> &out, int groupType);	// NOTE: placeholder name
};
class Map { public: HGroup unknown463890(int i); };	// NOTE: placeholder name
extern Map *endObjA;	// 0xcefc4c

//==================================================================
// followers
//==================================================================

bool EntityAI::getFollowers580a90(vector<HEntity> &out, int groupType)	// 0x580a90
{
	vector<HEntity> &members = groupType == 15 ? *self->getGroup()->getMembers() : *endObjA->unknown463890(groupType)->getMembers();
	for (unsigned int i = 0; i < members.size(); i++)
	{
		if (members[i]->getAI() && members[i]->getAI()->getFollowEntity() == self)
			out.push_back(members[i]);
	}
	return !out.empty();
}

struct TeamB_Squad673630 {	// NOTE: placeholder name/layout
 int pad0; HEntity leader; void collectFollowers673630(vector<HEntity> &out); };
void TeamB_Squad673630::collectFollowers673630(vector<HEntity> &out)	// 0x673630
{
	out.push_back(leader);
	vector<HEntity> &allies = *endObjA->unknown463890(3)->getMembers();
	for (unsigned int i = 0; i < allies.size(); i++)
	{
		if (allies[i]->getAI()->getFollowEntity() == leader)
			out.push_back(allies[i]);
	}
	vector<HEntity> &enemies = *endObjA->unknown463890(4)->getMembers();
	for (unsigned int j = 0; j < enemies.size(); j++)
	{
		if (enemies[j]->getAI()->getFollowEntity() == leader)
			out.push_back(enemies[j]);
	}
}

//==================================================================
// candidate position filter
//==================================================================

struct Point { int x; int y; };	// NOTE: placeholder layout
struct TeamB_PropInfo { char pad[0x28]; int value28; char pad2c[0xc]; int value38; };
class Prop { public: TeamB_PropInfo *getInfo(); };
class HProp { public: int ID; HProp(); Prop *operator->() const; };
class Cell { public: HProp getProp(); };
struct TeamB_CellGrid { Cell **at(Point &p); };
extern TeamB_CellGrid teamb_cells_cfd44c;
template <class T> void OpQ5_eraseStep(vector<T> &v, int &index);
struct OpW2_MachineRecord;
class BS { public: int unknown7142a0(vector<OpW2_MachineRecord *> &out); };
extern BS *teamb_world;
struct TeamB_681a90
{
	bool filter681a90(vector<Point> &points, vector<OpW2_MachineRecord *> &out);
};
bool TeamB_681a90::filter681a90(vector<Point> &points, vector<OpW2_MachineRecord *> &out)	// 0x681a90
{
	for (int i = 0; i < points.size(); i++)
	{
		if ((*teamb_cells_cfd44c.at(points[i]))->getProp()->getInfo()->value38 != 0 || (*teamb_cells_cfd44c.at(points[i]))->getProp()->getInfo()->value28 == -2)
			OpQ5_eraseStep(points,i);
	}
	if (points.empty())
		return false;
	return teamb_world->unknown7142a0(out);
}

//==================================================================
// free slot run search
//==================================================================

bool teamb_containsInt9db330(vector<int> &v, int value);	// NOTE: placeholder name (ICF body at 0x9db330)
int teamb_findFreeRun86f8a0(int start, int end, int count, vector<int> &used, bool forward)	// NOTE: placeholder name (0x86f8a0)
{
	if (forward)
	{
		for (int i = start; i <= end; i++)
		{
			if (!teamb_containsInt9db330(used,i))
			{
				count--;
				while (count != 0)
				{
					if (i + count > end || teamb_containsInt9db330(used,i + count))
						return -1;
					count--;
				}
				return i;
			}
		}
	}
	else
	{
		for (int i = start; i >= end; i--)
		{
			if (!teamb_containsInt9db330(used,i))
			{
				count--;
				while (count != 0)
				{
					if (i - count < end || teamb_containsInt9db330(used,i - count))
						return -1;
					count--;
				}
				return i;
			}
		}
	}
	return -1;
}

//==================================================================
// message text with numbered arguments
//==================================================================

class OpR1d_Replacer { public: void unknown455420(string &text, int number, const string &replacement); };
class OpR1d_Grammar { public: void parseGrammar(string &text); };
void opU5_replace407e00(string &text, string from, string to);	// NOTE: placeholder name (0x407e00)
struct TeamB_MessageRecord { char pad[0x2c]; string text; };
extern vector<TeamB_MessageRecord*> teamb_messageRecords_cf08c4;	// NOTE: placeholder name
extern string teamb_string_cf0c70;	// NOTE: placeholder name
extern string teamb_string_cf4acc;	// NOTE: placeholder name
struct TeamB_Message
{
	int type;
	char pad4[8];
	vector<string> args;
	string getText514060();
};
string TeamB_Message::getText514060()	// 0x514060
{
	string text = teamb_messageRecords_cf08c4[type]->text;
	opU5_replace407e00(text,teamb_string_cf0c70,teamb_string_cf4acc);
	for (unsigned int i = 0; i < args.size(); i++)
		((OpR1d_Replacer*)this)->unknown455420(text,i + 1,args[i]);
	if (!args.empty())
		((OpR1d_Grammar*)this)->parseGrammar(text);
	return text;
}
