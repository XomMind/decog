// team_c_62: robot terminal command line submit (0x942d40): echoes the command, unlocks matching memory entries,
//	dispatches "name=value" commands to the robot terminal, and answers the hidden easter-egg commands
// NOTE: names are placeholders; layouts are partial
#include <string>
#include <vector>
using namespace std;

struct C62_Inventory;
struct C62_Group { int getType(); };	// NOTE: placeholder (folded getter)
class C62_HGroup { public: int ID; C62_HGroup(); C62_Group *get230() const; };	// NOTE: placeholder (group handle)
struct C62_Entity { vector<int> *unknown45afd0(); int getWidth(); C62_Inventory *getInventory(); int getFaction(); C62_HGroup getGroup(); int getAiType(); };	// NOTE: placeholder names
struct Value_4b1b30 { int value; C62_Entity *operator->() const; };	// HEntity as returned by Push_4b1b30::operate (src/match_push/refined.cpp)
class Push_4b1b30 { public: Value_4b1b30 operate(); };	// src/match_push/refined.cpp
class C62_HProp { public: int ID; C62_HProp(); };	// NOTE: placeholder (HProp)
struct C62_Input { const string &getText(); };	// NOTE: placeholder (folded getter 0x458ef0)
struct C62_Field { char pad0[0x6c]; C62_Input *f6c; };	// NOTE: placeholder layout
struct C62_Rec { char pad0[0x70]; int f70; int f74; int f78; };	// NOTE: placeholder layout
class C62_Robot	// NOTE: placeholder (robot terminal console at 0xcec108)
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void select(int id, int a);
	C62_Field *getField();
	void delegate();
	vector<C62_Rec *> *getFieldAddress();
	void unknown9471d0(Value_4b1b30 entity, int type, string value);
	void unknown946990();
};
class C62_Shell	// NOTE: placeholder (0xcec104)
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void close();
};
struct C62_KeyMap { void popFrame(); };
struct C62_Map { Value_4b1b30 getPlayer(); };
struct C62_Console2 { void unknown8758d0(bool flag); };
struct C62_Log { void scrollToEnd(); };
struct C62_Stats { vector<int> *counts; bool add4729d0(unsigned int id, int value, string text, int extra); };	// NOTE: placeholder layout
struct C62_PlayerData { void unknown77fbc0(int type); };

bool c62_message5111e0(int id, const string *a, const string *b, int c, Value_4b1b30 entity, C62_HProp prop, int d, int e);	// NOTE: placeholder name (0x5111e0)
void resetCount_466930();
void opR1f_466860(const string &text);
int OpT8a_findString(vector<string> &list, string s);
bool c62_containsValue(vector<int> &v, int value);	// NOTE: placeholder name (OpX5_containsRecord)
bool OpQ4d_unknown942c00(int type, C62_Inventory *inventory, int id);	// NOTE: placeholder signature
void OpW7_unknown4b1bf0(Value_4b1b30 entity, C62_HProp prop);	// NOTE: placeholder signature
void OpC_stringFunc_408660(string &text, char c);
void stripLeadingChar_408600(string &s, char c);
int OpQ1_findStringNoCase(const string *list, unsigned int count, const string &text);

extern string gameStrings_cfc460[];	// global_string_arrays.cpp
extern string gameStrings_d032b8[];	// global_string_arrays.cpp
extern bool c62_cefca9;	// NOTE: placeholder names below
extern C62_Shell *c62_cec104;
extern C62_Robot *c62_cec108;
extern C62_KeyMap *c62_cefa8c;
extern C62_Map *c62_cefc4c;
extern C62_Console2 *c62_cec058;
extern C62_Log *c62_cec0b4;
extern vector<string> c62_d1e930;
extern vector<int> c62_d1e940;
extern int c62_b98be0[];
extern C62_Stats c62_d2c658;
extern C62_PlayerData c62_cf45d8;
extern const char c62_empty_b998de[];
extern const char c62_empty_b998df[];

#define C62_ROBOT_ENTITY() ((Push_4b1b30 *)c62_cec108)->operate()
#define C62_MSG(id, text) do { if (c62_message5111e0(id,text,0,0,C62_ROBOT_ENTITY(),C62_HProp(),0,0)) c62_cec058->unknown8758d0(true); c62_cec0b4->scrollToEnd(); } while (0)

void OpQ4d_unknown942d40(bool flag)
{
	if (c62_cefca9)
	{
		c62_cefca9 = false;
		return;
	}
	if (c62_cec104 != 0)
		c62_cec104->close();
	string cmd = c62_cec108->getField()->f6c->getText();
	bool handled;
	c62_cefa8c->popFrame();
	c62_cec108->delegate();
	if (flag)
		resetCount_466930();
	else if (!cmd.empty())
	{
		opR1f_466860(cmd);
		string text = "Command string: " + cmd;
		C62_MSG(504,&text);
		int idx = OpT8a_findString(c62_d1e930,cmd);
		handled = false;
		if (idx != -1)
		{
			if (c62_containsValue(*C62_ROBOT_ENTITY()->unknown45afd0(),idx))
			{
				C62_MSG(505,&(gameStrings_d032b8[idx].empty() ? string("Memory inaccessible.") : gameStrings_d032b8[idx]));
				goto end;
			}
			else if (c62_b98be0[idx] != 0 && c62_d1e940[idx] == c62_b98be0[idx])
			{
			}
			else
			{
				int width = C62_ROBOT_ENTITY()->getWidth();
				if (OpQ4d_unknown942c00(53,c62_cefc4c->getPlayer()->getInventory(),idx))
					handled = true;
				if (c62_cefc4c->getPlayer().operator->() != 0 && C62_ROBOT_ENTITY().operator->() != 0)
				{
					if (OpQ4d_unknown942c00(54,C62_ROBOT_ENTITY()->getInventory(),idx))
						handled = true;
				}
				if (handled)
				{
					OpW7_unknown4b1bf0(c62_cefc4c->getPlayer(),C62_HProp());
					OpW7_unknown4b1bf0(C62_ROBOT_ENTITY(),C62_HProp());
					c62_d1e940[idx]++;
					if (C62_ROBOT_ENTITY().operator->() != 0)
						C62_ROBOT_ENTITY()->unknown45afd0()->push_back(idx);
					c62_d2c658.add4729d0(801,1,c62_empty_b998de,width);
					if ((*c62_d2c658.counts)[801] == 50)
						c62_cf45d8.unknown77fbc0(189);
					c62_d2c658.add4729d0(880,1,c62_empty_b998df,-1);
				}
			}
		}
		else
		{
			string adj = cmd;
			string center;
			string behaviour;
			unsigned int allies = adj.find('=',0);
			if (allies == string::npos)
				center = adj;
			else
			{
				center.assign(adj.begin(),adj.begin() + allies);
				OpC_stringFunc_408660(center,' ');
				behaviour.assign(adj.begin() + allies + 1,adj.end());
				stripLeadingChar_408600(behaviour,' ');
			}
			int clean = OpQ1_findStringNoCase(gameStrings_cfc460,73,center);
			if (clean != -1)
			{
				int col = clean;
				if (col >= 72)
				{
					c62_cec108->unknown9471d0(C62_ROBOT_ENTITY(),col,behaviour);
					return;
				}
				vector<C62_Rec *> *cols = c62_cec108->getFieldAddress();
				for (unsigned int current = 0; current < cols->size(); current++)
				{
					if ((*cols)[current]->f70 == col)
					{
						c62_cec108->select((*cols)[current]->f78,0);
						return;
					}
				}
			}
		}
		if (!handled)
		{
			if (cmd == "RM -RF /")
				C62_MSG(504,&string("Hello 0x0961h."));
			else if (cmd == "WARSERF.EXE" && C62_ROBOT_ENTITY()->getFaction() == 1 && C62_ROBOT_ENTITY()->getGroup().get230()->getType() == 4)
				C62_MSG(504,&string("Unexpected end of data stream. Network initialization failed."));
			else if (cmd == "POTATO.EXE" && C62_ROBOT_ENTITY()->getAiType() == 1 && (C62_ROBOT_ENTITY()->getGroup().get230()->getType() == 3 || C62_ROBOT_ENTITY()->getGroup().get230()->getType() == 4))
				C62_MSG(504,&string("Testing. Nailhacker was here."));
			else
				C62_MSG(505,&string("No effect."));
		}
	end:
		c62_cec108->unknown946990();
	}
}
