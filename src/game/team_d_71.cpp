// team_d_71: companion banter member 0x7ace20 (called from Entity::turnUpdate): picks a remark about the
// robot's state, its parts or another companion's items.
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

class Flags71	// NOTE: placeholder name (OpR1e_Flags)
{
public:
	bool getFlag(int flag);
};

class Item
{
public:
	int unknown457920();					// NOTE: placeholder name (rating)
	bool unknown457cf0();					// NOTE: placeholder name
	int unknown45cb30();					// NOTE: placeholder name (folded getter)
	Flags71 *getData();						// NOTE: placeholder name (folded getter)
	string unknown571db0(int a, int b);		// NOTE: placeholder name (name text)
};

class HItem
{
public:
	int ID;
	HItem();	// NOTE: declared only (makes HItem a non-POD return type, as in the exe)
	Item *operator->() const;
};

class Entity
{
public:
	int unknown45a880();					// NOTE: placeholder name
	int unknown45a990();					// NOTE: placeholder name
	int unknown5cab90();					// NOTE: placeholder name
	bool unknown5d6c30(vector<HItem> *out);	// NOTE: placeholder name
	vector<HItem> *getInventoryList();
	const string &getName();				// NOTE: placeholder name (folded getter XCell::getFore)
};

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
	bool operator!=(HEntity e) const;
};

HItem OpX5_randomRecord(vector<HItem> &v);	// NOTE: placeholder name
extern int threshold71_b9610c;	// NOTE: placeholder name

class CompanionData
{
public:
	char				pad00[0x10];
	vector<HEntity *>	members;	// +0x10

	bool contains(HEntity e);							// NOTE: placeholder name (OpR4_ListHolder::contains)
	bool canUse(HEntity e, unsigned int type);			// NOTE: placeholder name (OpU5_SlotTable::canUse)
	bool unknown7ac1c0(HEntity e, int type, int force, string text);	// NOTE: placeholder name
	void unknown7ace20(HEntity e);						// NOTE: placeholder name
};

void CompanionData::unknown7ace20(HEntity e)
{
	if (!contains(e))
		return;
	if (e->unknown45a990() >= threshold71_b9610c && unknown7ac1c0(e,9,0,""))
		return;
	if (e->unknown5cab90() >= 50 && unknown7ac1c0(e,10,0,""))
		return;
	if (e->unknown45a880() < 50 && unknown7ac1c0(e,8,0,""))
		return;
	vector<HItem> parts;
	e->unknown5d6c30(&parts);
	if (!parts.empty() && canUse(e,1))
	{
		HItem best = parts[0];
		for (unsigned int i = 1; i < parts.size(); i++)
		{
			if (parts[i]->unknown457920() > best->unknown457920())
				best = parts[i];
		}
		unknown7ac1c0(e,1,1,best->unknown571db0(0,0));
		return;
	}
	if (members.size() == 2)
	{
		for (unsigned int j = 0; j < members.size(); j++)
		{
			if (*members[j] != e)
			{
				HEntity other = *members[j];
				if (canUse(e,2))
				{
					vector<HItem> items;
					vector<HItem> *pool = other->getInventoryList();
					for (unsigned int k = 0; k < pool->size(); k++)
					{
						if ((*pool)[k]->unknown457cf0() && (*pool)[k]->getData()->getFlag(0xd))
							items.push_back((*pool)[k]);
					}
					if (!items.empty())
					{
						unknown7ac1c0(e,2,1,OpX5_randomRecord(items)->unknown571db0(0,0));
						return;
					}
				}
				else if (canUse(e,3))
				{
					vector<HItem> list;
					other->unknown5d6c30(&list);
					if (!list.empty())
					{
						unknown7ac1c0(e,3,1,OpX5_randomRecord(list)->unknown571db0(0,0));
						return;
					}
				}
			}
		}
	}
	if (!parts.empty() && parts[0]->unknown45cb30() >= 2)
		unknown7ac1c0(e,0xb,0,e->getName());
}
