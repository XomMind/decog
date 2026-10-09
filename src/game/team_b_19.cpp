// team_b_19: CInfo show-by-name (0x8f9c60) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
struct Pos { int x; int y; explicit Pos(int v); };	// 0x409990
class HEntity { public: int ID; HEntity(); };
class HProp { public: int ID; HProp(); };	// NOTE: ctor 0x9b6590 shared by all handles
class HItem { public: int ID; HItem(); };
struct OpU5s2_EntityRecord;
struct OpU5s2_HD { int ID; };
class OpU5s2_Factory
{
public:
	HEntity createEntity(OpU5s2_EntityRecord *record);	// 0x793200
	OpU5s2_HD createD(int *data);	// 0x7932b0
};
extern OpU5s2_Factory *teamb_factory_cefaa8;	// NOTE: placeholder name
class CInfo { public: void unknown8b4500(HEntity a, HProp b, HEntity c, Pos *pos, int mode, bool e); };
extern CInfo *opx5e_cec11c;	// NOTE: placeholder name (0xcec11c)
class XConsole { public: virtual ~XConsole(); void setHidden(bool hidden); };
extern XConsole *teamb_cec0f8;	// NOTE: placeholder name
extern int opw8_caf160;
extern int opw8_caf164;
extern vector<OpU5s2_EntityRecord*> teamb_entityRecords_d25de0;
extern vector<int*> teamb_itemTypes_d2d1c4;
int teamb_find8f8930(const string &name);
int teamb_find8f89f0(const string &name);
HItem teamb_findInventoryItem8f8d30(const string &name);
HItem OpR5d_findItem8f90d0(const string &name);
HItem OpR5d_findItem8f96a0(const string &name);
HItem OpR5d_findItem8f98c0(const string &name);
// NOTE: HEntity()/HItem()-typed temporaries below are spelled HProp() because the exe uses the shared handle ctor
#define H_E (*(HEntity*)&HProp())
void teamb_info8f9c60(int type, const string &name)	// NOTE: placeholder name (0x8f9c60)
{
	switch (type)
	{
	case 3:
		{
			int first = teamb_find8f8930(name);
			int found = first == opw8_caf164 ? teamb_find8f89f0(name) : opw8_caf160;
			if (first != opw8_caf164)
				opx5e_cec11c->unknown8b4500(H_E,*(HProp*)&teamb_factory_cefaa8->createD(teamb_itemTypes_d2d1c4[first]),H_E,&Pos(-1),1,true);
			else
				opx5e_cec11c->unknown8b4500(teamb_factory_cefaa8->createEntity(teamb_entityRecords_d25de0[found]),HProp(),H_E,&Pos(-1),1,true);
		}
		break;
	case 6:
		{
			HItem item = teamb_findInventoryItem8f8d30(name);
			opx5e_cec11c->unknown8b4500(H_E,*(HProp*)&item,H_E,&Pos(-1),1,false);
		}
		break;
	case 7:
		{
			HItem item = OpR5d_findItem8f90d0(name);
			opx5e_cec11c->unknown8b4500(H_E,*(HProp*)&item,H_E,&Pos(-1),1,false);
		}
		break;
	case 8:
		{
			HItem item = OpR5d_findItem8f96a0(name);
			opx5e_cec11c->unknown8b4500(H_E,*(HProp*)&item,H_E,&Pos(-1),1,false);
		}
		break;
	case 9:
		{
			HItem item = OpR5d_findItem8f98c0(name);
			opx5e_cec11c->unknown8b4500(H_E,*(HProp*)&item,H_E,&Pos(-1),1,false);
		}
		break;
	}
	teamb_cec0f8->setHidden(true);
}
