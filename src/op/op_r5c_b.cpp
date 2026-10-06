// op_r5c_b: info-panel helpers in 0x89d000-0x8b4000 (item/entity spawn by name, shortcut handlers), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos() throw();	// 0x453b40
	Pos(int x_, int y_) throw();	// 0x46ca20
	Pos(int v) throw();	// 0x409990
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(void *event);
	bool isHidden();
	XConsole *getParent();
	void removeSubconsole(XConsole *console);
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class OpR5c_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void unknown416640();	// NOTE: placeholder name
	void unknown416730();	// NOTE: placeholder name (sets a flag)
};
extern OpR5c_KeyMap *opr5c_keyMap;	// NOTE: placeholder name (0xcefa8c)

class OpR5c_Entity;
class OpR5c_Item
{
public:
	int getField9b6bf0();	// NOTE: placeholder name (folded getter)
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity() throw();	// 0x9b6590
	bool isValid() const;
	OpR5c_Entity *operator->() const;	// 0x9b6570
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
	bool isValid() const;
	OpR5c_Item *operator->() const;	// 0x9b65b0
};

struct ItemType;

class OpR5c_Analysis : public XConsole	// NOTE: placeholder name (CAnalysis at 0xcec128)
{
public:
	void unknown8b1c90();	// NOTE: placeholder name
};
extern OpR5c_Analysis *opr5c_analysis;	// NOTE: placeholder name (0xcec128)

bool opr5c_unknown8b12f0()	// NOTE: placeholder name
{
	opr5c_analysis->input(&XEvent(0xf4));
	opr5c_keyMap->unknown416730();
	return true;
}

void OpR5c_Analysis::unknown8b1c90()
{
	opr5c_analysis = NULL;
	opr5c_keyMap->unknown416640();
	getParent()->removeSubconsole(this);
}

struct OpR5c_EntityType	// NOTE: placeholder name
{
	char pad00[0x1ac];
	string name;
};

class OpR5c_EntityRecord	// NOTE: placeholder name (0x4598f0)
{
public:
	string getName4598f0();	// NOTE: placeholder name
};

class OpR5c_ItemMgr	// NOTE: placeholder name (0xcefaa8)
{
public:
	HProp create7932b0(ItemType *type);	// NOTE: placeholder name (0x7932b0)
	HEntity create793200(OpR5c_EntityRecord *record);	// NOTE: placeholder name
};
extern OpR5c_ItemMgr *opr5c_itemMgr;	// NOTE: placeholder name (0xcefaa8)

class OpR5c_List	// NOTE: placeholder name (CList at 0xcec130)
{
public:
	virtual void slot0() = 0;
	virtual void slot1() = 0;
	virtual void slot2() = 0;
	virtual void slot3() = 0;
	virtual void slot4() = 0;
	virtual void slot5() = 0;
	virtual void slot6() = 0;
	virtual void slot7() = 0;
	virtual void slot8() = 0;
	virtual void slot9() = 0;
};
extern OpR5c_List *opr5c_activeList;	// NOTE: placeholder name (0xcec130)

class OpR5c_Info : public XConsole	// NOTE: placeholder name (CInfo at 0xcec11c)
{
public:
	void unknown8b4500(HEntity a, HProp b, HEntity c, Pos *pos, int mode, bool e);	// NOTE: placeholder name
};
extern OpR5c_Info *opr5c_itemUI;	// NOTE: placeholder name (0xcec11c)

extern vector<ItemType*> opr5c_itemTypes;	// NOTE: placeholder name (0xd2d1c4)
extern vector<OpR5c_EntityRecord*> opr5c_entityTypes;	// NOTE: placeholder name (0xd25de0)
int opr5c_findItemType9e31a0(vector<ItemType*> &types, const string &name);	// NOTE: placeholder name
int opr5c_findEntityType9e3200(vector<OpR5c_EntityRecord*> &types, const string &name);	// NOTE: placeholder name

void opr5c_spawn8b36f0(int mode, const string &name)	// NOTE: placeholder name
{
	if (name.empty())
	{
		if (opr5c_itemUI->isHidden())
			opr5c_activeList->slot9();
		return;
	}
	switch (mode)
	{
		case 0:
		case 1:
		case 4:
			{
				int index = opr5c_findItemType9e31a0(opr5c_itemTypes,name);
				opr5c_itemUI->unknown8b4500(HEntity(),opr5c_itemMgr->create7932b0(opr5c_itemTypes[index]),HEntity(),&Pos(-1),2,true);
			}
			break;
		case 2:
		case 5:
			{
				int index = -1;
				if (mode == 2)
					index = opr5c_findEntityType9e3200(opr5c_entityTypes,name);
				else
				{
					for (unsigned int i = 0; i < opr5c_entityTypes.size(); i++)
					{
						if (opr5c_entityTypes[i]->getName4598f0() == name)
						{
							index = i;
							break;
						}
					}
				}
				opr5c_itemUI->unknown8b4500(opr5c_itemMgr->create793200(opr5c_entityTypes[index]),HProp(),HEntity(),&Pos(-1),2,true);
			}
			break;
	}
}

class CInfoCompare : public XConsole	// NOTE: placeholder layout
{
public:
	HProp getTarget();	// 0x4aeed0
};

bool opr5c_compareInfo89d920(CInfoCompare *a, CInfoCompare *b)	// NOTE: placeholder name
{
	return a->getTarget()->getField9b6bf0() > b->getTarget()->getField9b6bf0();
}

void opr5c_spawn8b36d0(int mode, const string &name)	// NOTE: placeholder name
{
	opr5c_spawn8b36f0(mode,name);
}
