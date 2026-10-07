// team_b_14: game-logic helpers (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1), batch 12.
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
#include <string>
#include <vector>
using namespace std;

//==================================================================
// CLore: jump to an entry by its hotkey
//==================================================================
struct Pos { int x; int y; Pos(int x_, int y_); Pos(const Pos &p); };
class XConsole
{
public:
	virtual ~XConsole();
	int getWidth();
	Pos localToAbs(Pos pos);
	char pad04[0x6c - 4];
	int *index6c;	// NOTE: placeholder name
};
class OpR1c_Mouse { public: void setCellPoint_41a910(const Pos &p); };
extern OpR1c_Mouse *opx5b_mouse;	// NOTE: placeholder name (0xcefa94)
bool OpT8b_Fn9daf80(int lo, int v, int hi);
extern unsigned int teamb_npos_caf16c;	// NOTE: placeholder name
struct TeamB_LoreData { int pad0; string name; };
struct TeamB_LoreRecord { int pad0; bool known; TeamB_LoreData *data; };
extern vector<TeamB_LoreRecord*> teamb_mapRecords;	// NOTE: placeholder name (0xd02cb4)
class CLore
{
public:
	char pad[0x70];
	vector<XConsole*> pages;
	void scroll7eafe0(int delta, int mode);	// NOTE: placeholder name
	void select7ebd60(int index);	// NOTE: placeholder name
	bool selectKey7eb9b0(char key);
};
bool CLore::selectKey7eb9b0(char key)	// 0x7eb9b0
{
	int index = teamb_npos_caf16c;
	for (unsigned int i = 0; i < teamb_mapRecords.size(); i++)
	{
		if (teamb_mapRecords[i]->data)
		{
			if (teamb_mapRecords[i]->known && teamb_mapRecords[i]->data->name[0] == key)
			{
				index = i;
				break;
			}
		}
		else
			break;
	}
	if (index == teamb_npos_caf16c)
		return false;
	if (!OpT8b_Fn9daf80(*pages.front()->index6c,index,*pages.back()->index6c))
	{
		if (index < *pages.back()->index6c)
			scroll7eafe0(-(*pages.front()->index6c - index) - 1,-1);
		else
			scroll7eafe0(index - *pages.back()->index6c + 1,-1);
	}
	for (unsigned int j = 0; j < pages.size(); j++)
	{
		if (*pages[j]->index6c == index)
		{
			opx5b_mouse->setCellPoint_41a910(pages[j]->localToAbs(Pos(pages[j]->getWidth() - 2,0)));
			select7ebd60(index);
			break;
		}
	}
	return true;
}

//==================================================================
// Overmind: alert from destroyed props
//==================================================================
class OpR2c_Options { public: bool unknown46f4b0(int a); };
extern OpR2c_Options opr2c_d1e860;	// NOTE: placeholder name (0xd1e860)
class OpR1h_Stats { public: bool add4729d0(unsigned int id, int value, string text, int extra) throw(); };
extern OpR1h_Stats teamb_stats_d2c658;	// NOTE: placeholder name
class Group { public: int getValue9b8f00(); };	// NOTE: placeholder name (ICF'd getter)
class HGroup { public: int ID; HGroup(); Group *operator->() const; };
class Entity { public: HGroup getGroup(); };
class HEntity { public: int ID; Entity *operator->() const; };
struct TeamB_PropInfo2 { char pad[0xf8]; int kind; };	// NOTE: placeholder layout
class Prop { public: int getLink_44ab40(); TeamB_PropInfo2 *getInfo(); const string &unknown45c590(); };
class HProp { public: int ID; Prop *operator->() const; };
extern vector<int> unknown_d2a2cc;	// NOTE: placeholder name
extern int teamb_difficulty_cf4718;	// NOTE: placeholder name
extern const int teamb_alertTable_ba6544[];	// NOTE: placeholder name
extern const float teamb_alertScale_b919b4;	// NOTE: placeholder name
class OpR3c_Overmind
{
public:
	char pad[0x4c];
	int value4c;
	void unknown682420(int type, int amount);
	void propDestroyed681eb0(HProp prop, HEntity attacker);
};
void OpR3c_Overmind::propDestroyed681eb0(HProp prop, HEntity attacker)	// 0x681eb0 (empty string literals are tail-merged in the exe)
{
	if (opr2c_d1e860.unknown46f4b0(1) && value4c == 0 && attacker.operator->() && attacker->getGroup()->getValue9b8f00() <= 2)
	{
		if (prop->getLink_44ab40() == -1 || unknown_d2a2cc[prop->getLink_44ab40()] == 0)
		{
			if (prop->getInfo()->kind == 5)
			{
				unknown682420(8,0);
				teamb_stats_d2c658.add4729d0(3,100,"",-1);
			}
			else if (prop->unknown45c590() == "GAR_Relay")
			{
				unknown682420(9,0);
				teamb_stats_d2c658.add4729d0(3,200,"",-1);
			}
			else if (prop->unknown45c590() == "GAR_Generator")
			{
				unknown682420(10,0);
				teamb_stats_d2c658.add4729d0(3,200,"",-1);
			}
			else
			{
				unknown682420(7,(int)(teamb_alertTable_ba6544[teamb_difficulty_cf4718] * teamb_alertScale_b919b4 / 100.0));
				teamb_stats_d2c658.add4729d0(3,10,"",-1);
			}
		}
	}
}
