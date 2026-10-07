// team_b_11: game-logic helpers (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1), batch 9.
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
#include <vector>
using namespace std;

class FloatRange { public: float random_40c700(); };
extern FloatRange teamb_range_d2ed00;	// NOTE: placeholder name
void OpC_clampMin(int *v, int m);
bool teamb_check69d230();	// NOTE: placeholder name
class HEntity { public: int ID; HEntity(); void clear() throw(); };
struct TeamB_MapType { int pad0; int type; };
class TeamB_HMapType { public: int ID; TeamB_MapType *operator->() const; };
struct TeamB_69d570
{
	char pad[0xc];
	HEntity targetC;
	char pad10[4];
	int value14;
	char pad18[0xb4 - 0x18];
	vector<int> listB4;
	char padc4[4];
	int valueC8;
	char padcc[0x164 - 0xcc];
	int value164;
	int value168;
	char pad16c[0x17c - 0x16c];
	int value17c;
	char pad180[0x194 - 0x180];
	int value194;
	vector<HEntity> list198;
	char pad1a8[0x1b0 - 0x1a8];
	int value1b0;
	HEntity handle1b4;
	int value1b8;
	int value1bc;
	void reset69d570(TeamB_HMapType from, TeamB_HMapType to);
};
void TeamB_69d570::reset69d570(TeamB_HMapType from, TeamB_HMapType to)	// 0x69d570
{
	targetC.clear();
	if (from->type != 13 && to->type != 13 && from->type != 14 && to->type != 14 && from->type != 12 && to->type != 12)
		value14 = (int)(teamb_range_d2ed00.random_40c700() * value14);
	if (teamb_check69d230())
		OpC_clampMin(&value14,5);
	for (unsigned int i = 0; i < listB4.size(); i++)
	{
		if (listB4[i] == -2)
			listB4[i] = 0;
	}
	valueC8 = 0;
	value164 = -1;
	value168 = 0;
	value17c = 0;
	value194 = 0;
	list198.clear();
	value1b0 = 0x61;
	handle1b4.clear();
	value1b8 = 0;
	value1bc = 0;
}

class HProp { public: int ID; HProp() throw(); };
class Map { public: HEntity getPlayer(); };
extern Map *endObjA;
struct TeamB_UIValue { int value; };	// NOTE: placeholder name
class TeamB_Console_cec0f8 { public: TeamB_UIValue get4b1460(); };	// NOTE: placeholder name
extern TeamB_Console_cec0f8 *teamb_cec0f8;	// NOTE: placeholder name
struct TeamB_HackData { char pad[0x70]; int type; int value; };	// NOTE: placeholder layout
struct TeamB_HackOption { TeamB_HackData *data; };	// NOTE: placeholder layout
class TeamB_Machine	// NOTE: placeholder name
{
public:
	vector<TeamB_HackOption*> *unknown518c00(int a, HEntity user, HProp p, TeamB_UIValue v, HProp q, int b, int c, int d, int e, int f);
};
template <class T> void OpX5_deleteObjectAndStep(vector<T*> &v, int &index);
struct OpV4d_Trivial;
void OpV4d_deleteMapRecords(vector<OpV4d_Trivial*> &v);
bool teamb_runHack51da30(vector<TeamB_HackOption*> *options, int a, HProp p, TeamB_UIValue v, HProp q, int b, int c);	// NOTE: placeholder name (0x51da30)
bool teamb_hack900340(int a, TeamB_Machine *machine, int type, int *best)
{
	if (machine)
	{
		vector<TeamB_HackOption*> *list = machine->unknown518c00(a,endObjA->getPlayer(),HProp(),teamb_cec0f8->get4b1460(),HProp(),0,0,0,0,0);
		if (list)
		{
			for (int i = 0; i < list->size(); i++)
			{
				if (list->at(i)->data->type != type)
					OpX5_deleteObjectAndStep(*list,i);
			}
			bool result = teamb_runHack51da30(list,a,HProp(),teamb_cec0f8->get4b1460(),HProp(),0,0);
			if (result)
			{
				*best = -1;
				for (unsigned int j = 0; j < list->size(); j++)
				{
					if (list->at(j)->data->value > *best)
						*best = list->at(j)->data->value;
				}
			}
			OpV4d_deleteMapRecords((vector<OpV4d_Trivial*>&)*list);
			delete list;
			return result;
		}
	}
	return false;
}
