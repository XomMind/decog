// team_b_15: CShell item/entity selection by name (0x8f9a20) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; TeamB_* names are placeholders. Local names follow docs/local-name-buckets.txt.
// NOTE: "goto show" without a break reproduces the exe jump layout of cases 6-9.
#include <string>
#include <vector>
using namespace std;
class HItem { public: int ID; HItem(); };
class XConsole { public: virtual ~XConsole(); bool isHidden(); void setHidden(bool hidden); };
class TeamB_List : public XConsole	// NOTE: placeholder name (CList at 0xcec130)
{
public:
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void close();
	void unknown7b2870();
};
struct TeamB_Handle { int value; };
class TeamB_Targeter	// NOTE: placeholder name (object at 0xcec0fc)
{
public:
	void resetField_4aff10();
	TeamB_Handle get4aeb30();
	class Entity *getEntity_45ab90();
};
class Entity { public: int getTarget(); };
struct EntityRecord;
struct ItemType;
class TeamB_Shell { public: void unknown91ca50(TeamB_Handle h, int target, int a, int b, ItemType *item, EntityRecord *entity, HItem handle); };	// NOTE: placeholder name (CShell)
extern XConsole *opx5e_cec11c;
extern TeamB_List *opr5c_activeList;
extern TeamB_Targeter *opX5C_cec0fc;
extern XConsole *teamb_cec0f8;
extern TeamB_Shell *opU5_shell;
extern int opw8_caf160;
extern int opw8_caf164;
extern vector<EntityRecord*> teamb_entityRecords_d25de0;
extern vector<ItemType*> teamb_itemTypes_d2d1c4;
int teamb_find8f8930(const string &name);
int teamb_find8f89f0(const string &name);
HItem teamb_findInventoryItem8f8d30(const string &name);
HItem OpR5d_findItem8f98c0(const string &name);
HItem OpR5d_findItem8f96a0(const string &name);
HItem OpR5d_findItem8f98c0b(const string &name);	// NOTE: placeholder name (0x8f98c0; src/op name clashes with 0x8f90d0)
void teamb_select8f9a20(int type, const string &name)	// NOTE: placeholder name (0x8f9a20)
{
	if (name.empty())
	{
		if (opx5e_cec11c->isHidden())
		{
			opr5c_activeList->close();
			opX5C_cec0fc->resetField_4aff10();
			teamb_cec0f8->setHidden(false);
		}
		return;
	}
	HItem item;
	switch (type)
	{
	case 3:
		{
			int first = teamb_find8f8930(name);
			int found = first == opw8_caf164 ? teamb_find8f89f0(name) : opw8_caf160;
			opr5c_activeList->unknown7b2870();
			opU5_shell->unknown91ca50(opX5C_cec0fc->get4aeb30(),opX5C_cec0fc->getEntity_45ab90()->getTarget(),0x70,-1,first == opw8_caf164 ? NULL : teamb_itemTypes_d2d1c4[first],found == opw8_caf160 ? NULL : teamb_entityRecords_d25de0[found],HItem());
		}
		break;
	case 6:
		item = teamb_findInventoryItem8f8d30(name);
		goto show;
	case 7:
		item = OpR5d_findItem8f98c0(name);
		goto show;
	case 8:
		item = OpR5d_findItem8f96a0(name);
		goto show;
	case 9:
		item = OpR5d_findItem8f98c0b(name);
	show:
		opr5c_activeList->unknown7b2870();
		opU5_shell->unknown91ca50(opX5C_cec0fc->get4aeb30(),opX5C_cec0fc->getEntity_45ab90()->getTarget(),0x70,-1,NULL,NULL,item);
		break;
	}
	opX5C_cec0fc->resetField_4aff10();
}
