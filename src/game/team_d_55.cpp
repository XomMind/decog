// team_d_55: BS member 0x6f1370 (Zhirov encounter dialogs when the player carries the SGEMP Prototype).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

class Entity;
class Item;

class HEntity
{
	int ID;
public:
	HEntity();
	Entity *operator->() const;
};

class HItem
{
	int ID;
public:
	HItem();
	bool isValid() const;
	Item *operator->() const;
};

class Item
{
public:
	const string &unknown457860();		// NOTE: placeholder name (record name)
	void unknown57a190(HEntity e, int a, int b, int c);	// NOTE: placeholder name
};

class Entity
{
public:
	vector<HItem> *getInventoryList();
	int getFaction();					// 0x45a2c0
};

class Group55	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: placeholder name (folded getter 0x416f40)
};

class HGroup55	// NOTE: placeholder name
{
	int ID;
public:
	Group55 *operator->() const;
};

struct Location55	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;		// +0x04
};

class HLoc55	// NOTE: placeholder name
{
	int ID;
public:
	Location55 *operator->() const;
};
extern vector<HLoc55> locations55_d1e88c;	// NOTE: placeholder name

class GameData55	// NOTE: placeholder name (0xd1e860)
{
public:
	const string &getEntryText(const string &key);	// 0x46f6d0
};
extern GameData55 gameData55_d1e860;	// NOTE: placeholder name

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

class BS
{
public:
	char				pad000[0x4c];
	vector<HGroup55>	groups;		// +0x4c
	char				pad05c[0x66c - 0x5c];
	HEntity				leader;		// +0x66c

	bool unknown6f0f80(HEntity *a, HEntity *b, HEntity *c);	// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &talk, int a);	// NOTE: placeholder name
	void unknown6f1370();	// NOTE: placeholder name
};

void BS::unknown6f1370()
{
	if (stringToInt(gameData55_d1e860.getEntryText("zhiZhirovOfferedHelp_g")) && !stringToInt(gameData55_d1e860.getEntryText("zhiCloakGeneratorsDisabled_g"))
		&& !stringToInt(gameData55_d1e860.getEntryText("zhiZhirovDead_g")) && locations55_d1e88c[locations55_d1e88c.size() - 3]->type != 5)
	{
		HItem item;
		vector<HItem> *items = leader->getInventoryList();
		for (unsigned int i = 0; i < items->size(); i++)
		{
			if ((*items)[i]->unknown457860() == "SGEMP Prototype")
			{
				item = (*items)[i];
				break;
			}
		}
		if (item.isValid())
		{
			HEntity e;
			HEntity node;
			HEntity target;
			if (unknown6f0f80(&e,&node,&target))
			{
				bool done = false;
				for (unsigned int j = 0; j < groups[2]->getMembers()->size(); j++)
				{
					if ((*groups[2]->getMembers())[j]->getFaction() == 0x5e)
					{
						done = true;
						break;
					}
				}
				if (done)
				{
					unknown6c65a0(e,"ACC_Zhirov_Sigix_Dialog",0);
					unknown6c65a0(e,"ACC_Zhirov_Sigix_Attack",0);
				}
				else if (stringToInt(gameData55_d1e860.getEntryText("usedCoreResetMatrix_g")))
				{
					unknown6c65a0(e,"ACC_Zhirov_Reset_Dialog",0);
					unknown6c65a0(e,"ACC_Zhirov_Sigix_Attack",0);
				}
				else
				{
					unknown6c65a0(e,"ACC_Zhirov_Dialogue",0);
					unknown6c65a0(e,"ACC_Zhirov_Score",0);
					unknown6c65a0(e,"ACC_Zhirov_Damaged",0);
					item->unknown57a190(e,4,0,0);
					unknown6c65a0(e,"ACC_Zhirov_Data",0);
				}
			}
		}
	}
}
