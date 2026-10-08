// op_ai_upgrade: 0x4fe3f0, picks the best replacement for an equipped part from a list of candidates
// (used by EntityAI::takeTurn) (COGMIND.exe Beta 17.1).
// NOTE: placeholder names; the Item getters are folded trivial accessors named by address.
#include <vector>
using namespace std;

class Item
{
public:
	int slotType_4578c0();	// NOTE: placeholder name
	bool flag_415ee0();	// NOTE: placeholder name
	bool flag_457d10();	// NOTE: placeholder name
	int type_4578a0();	// NOTE: placeholder name
	int group_457820();	// NOTE: placeholder name
	int integrity_9b6bf0();	// NOTE: placeholder name
	int value_457ca0();	// NOTE: placeholder name
	int kind_457f90();	// NOTE: placeholder name
	int stat_457fb0();	// NOTE: placeholder name
	int subtype_457880();	// NOTE: placeholder name
	int rating_457920();	// NOTE: placeholder name
};

class HItem
{
	int ID;
public:
	HItem();	// 0x9b6590
	Item *operator->() const;	// 0x9b65b0
	bool isNull() const;	// 0x9b65d0
};

class Entity
{
public:
	int unknown5d1390();	// NOTE: placeholder name
};

class HEntity
{
	int ID;
public:
	Entity *operator->() const;	// 0x9b6570
};

struct OpQ5_U9d6440;	// NOTE: placeholder name
template <class T> void OpQ5_eraseStep(vector<T> &list, int &index);	// NOTE: placeholder name
extern int opAU_kindCompare_ba2f88[];	// NOTE: placeholder name: 0 = higher stat_457fb0 is better, 1 = lower

HItem opAU_findUpgrade_4fe3f0(HItem item, vector<HItem> &candidates, HEntity owner)	// NOTE: placeholder name
{
	if (item->slotType_4578c0() != 1 || item->flag_415ee0() || item->flag_457d10())
		return HItem();
	HItem best;
	for (unsigned int i = 0; i < candidates.size(); i++)
	{
		if (candidates[i]->type_4578a0() != item->type_4578a0() || candidates[i]->slotType_4578c0() != 1)
			OpQ5_eraseStep((vector<OpQ5_U9d6440>&)candidates,(int&)i);
	}
	for (unsigned int j = 0; j < candidates.size(); j++)
	{
		if (item->group_457820() == candidates[j]->group_457820() && item->integrity_9b6bf0() > candidates[j]->integrity_9b6bf0() && item->value_457ca0() >= candidates[j]->value_457ca0() + 15 && (best.isNull() || best->integrity_9b6bf0() > candidates[j]->integrity_9b6bf0()))
			best = candidates[j];
	}
	if (best.isNull())
	{
		for (unsigned int k = 0; k < candidates.size(); k++)
		{
			if (item->kind_457f90() != 0 && item->kind_457f90() == candidates[k]->kind_457f90())
			{
				switch (opAU_kindCompare_ba2f88[item->kind_457f90()])
				{
				case 0:
					if (item->stat_457fb0() > candidates[k]->stat_457fb0() && (best.isNull() || best->stat_457fb0() > candidates[k]->stat_457fb0() || best->integrity_9b6bf0() > candidates[k]->integrity_9b6bf0()))
						best = candidates[k];
					break;
				case 1:
					if (item->stat_457fb0() < candidates[k]->stat_457fb0() && (best.isNull() || best->stat_457fb0() < candidates[k]->stat_457fb0() || best->integrity_9b6bf0() > candidates[k]->integrity_9b6bf0()))
						best = candidates[k];
					break;
				}
			}
		}
		if (best.isNull())
		{
			if ((item->kind_457f90() == 0 || item->kind_457f90() == 0x76) && item->type_4578a0() != 2)
			{
				bool sameSubtype = item->type_4578a0() == 1;
				for (unsigned int m = 0; m < candidates.size(); m++)
				{
					if (item->type_4578a0() == candidates[m]->type_4578a0() && (!sameSubtype || item->subtype_457880() == candidates[m]->subtype_457880()))
					{
						if ((item->rating_457920() == candidates[m]->rating_457920() && item->integrity_9b6bf0() * 0.75 >= candidates[m]->integrity_9b6bf0()) || (item->rating_457920() > candidates[m]->rating_457920() && item->integrity_9b6bf0() >= candidates[m]->integrity_9b6bf0()))
						{
							if (best.isNull() || best->rating_457920() > candidates[m]->rating_457920() || (best->rating_457920() == candidates[m]->rating_457920() && best->integrity_9b6bf0() > candidates[m]->integrity_9b6bf0()))
								best = candidates[m];
						}
					}
				}
			}
			if (best.isNull())
			{
				if (item->kind_457f90() == 0x2e)
				{
					for (unsigned int n = 0; n < candidates.size(); n++)
					{
						if (candidates[n]->kind_457f90() == 0x2e && item->integrity_9b6bf0() * 0.75 + item->rating_457920() >= candidates[n]->integrity_9b6bf0() + candidates[n]->rating_457920())
						{
							if (best.isNull() || best->integrity_9b6bf0() + best->rating_457920() > candidates[n]->integrity_9b6bf0() + candidates[n]->rating_457920())
								best = candidates[n];
						}
					}
				}
				if (best.isNull() && item->type_4578a0() == 1 && item->subtype_457880() - 9 == owner->unknown5d1390())
				{
					for (unsigned int p = 0; p < candidates.size(); p++)
					{
						if (candidates[p]->type_4578a0() == 1 && candidates[p]->subtype_457880() != item->subtype_457880() && (best.isNull() || best->integrity_9b6bf0() + best->rating_457920() > candidates[p]->integrity_9b6bf0() + candidates[p]->rating_457920()))
							best = candidates[p];
					}
				}
			}
		}
	}
	return best;
}
