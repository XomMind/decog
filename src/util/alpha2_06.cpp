// alpha2_06: Entity salvage/inventory drop on death (0x631a20), called from Entity::die.
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <string>
#include <vector>
#include "rng.h"
using std::string;
extern RNG rng;

struct A2XEntity;
struct A2XItem;
struct A2XPoint
{
	int x;
	int y;
	A2XPoint() throw();	// 0x453b40
	int randomInRange_40c130() throw();
};
struct A2XRect
{
	int x;
	int y;
	int x2;
	int y2;
	A2XRect() throw();	// 0x40b100
};
struct A2XFloatRange
{
	float min;
	float max;
	float random_40c700() throw();
};
struct A2XHE	// HEntity
{
	int id;
	A2XHE() throw();	// 0x9b6590
	A2XEntity *get_9b6570() const throw();
	bool notEquals_9b6510(A2XHE other) const throw();
	bool equals_9b78e0(A2XHE other) const throw();
};
struct A2XHI	// HItem
{
	int id;
	A2XHI() throw();	// 0x9b6590
	A2XItem *get_9b65b0() const throw();
	bool valid_9b7230() const throw();
};
struct A2XHG	// handle at Entity+0x28
{
	int id;
	struct A2XGroup *get_9b7250() const throw();
};
struct A2XGroup
{
	int type_9b4350() throw();
};
struct A2XItemDef
{
	char pad0[0x70];
	int category;	// +0x70
	bool unique;	// +0x74
};
struct A2XEffectDef;
struct A2XEffect
{
	A2XEffectDef *def;
	int amount;
	A2XEffect(A2XEffectDef *d, int a) : def(d), amount(a) {}
};
struct A2XItem
{
	int getType_44aec0() throw();
	int chance_457880() throw();
	int count_4578c0() throw();
	A2XEffect *getEffect_457b70(int effect) throw();
	int value_457c80() throw();
	int value_457ca0() throw();
	int unknown457f90() throw();
	void setIntegrity_458310(int value) throw();
	void setCount_458360(int value) throw();
	void addEffect_4585a0(A2XEffect *effect);
	bool unknown577990();
	void setActive_5791a0(bool active);
	void setScaled_579880(int value);
	void place_57a0f0(const A2XPoint &pos, bool a, int b);
	void remove_57dbe0(bool a, bool b, bool c, bool d);
	A2XItemDef *getDef_9b4350() throw();
	string getName_571db0(bool full, bool label);
	int integrity_9b6bf0() throw();
};
struct A2XEntityDef
{
	char pad0[0x24];
	int kind;	// +0x24
	int type;	// +0x28
	char pad2c[0x70 - 0x2c];
	int salvageParts;	// +0x70
	char pad74[0x13c - 0x74];
	int bonusMatter;	// +0x13c
	char pad140[0x210 - 0x140];
	A2XPoint salvage;	// +0x210
};
struct A2XCell
{
	A2XHI getItem_45d8f0();
};
struct A2XGrid
{
	A2XCell **at_9ceda0(int x, int y) throw();
	void getRect_9b4430(const A2XPoint &center, int radius, A2XRect &rect);
};
struct A2XMap
{
	A2XHE getPlayer_4630f0();
	int relation_463910(A2XHG faction, A2XHG group);
	int turns_4642d0(int value) throw();
	void place_464840(A2XHI item);
	bool findDrop_71bc10(const A2XPoint &pos, A2XPoint &dest);
	A2XHI spawnMatter_71e7c0(const A2XPoint &pos, int amount, bool flag);
	void mark_727e30(A2XHI item, int turns);
};
struct A2XStats
{
	bool add_4729d0(unsigned int id, int value, string text, int extra);
};
struct A2XPart
{
	void drawStatus_4a8e70(bool flag);
};
struct A2XParts
{
	A2XPart *find_894e70(int item);
};
struct A2XFactory
{
	A2XHI create_7932b0(A2XItemDef *def);
};
struct A2XGameData
{
	int getDepthIndex() throw();
};
struct A2XWorldRecord
{
	int pad0;
	int type;	// +0x04
};
struct A2XWorldHandle
{
	int id;
	A2XWorldRecord *get_9b7910() const throw();
};
struct A2XConsole
{
	void bubble_8758d0(bool flag);
};
struct A2XLog
{
	void scrollToEnd_7b4f10();
};
struct A2XEntity
{
	bool drop_631a20(A2XHE killer, bool showMessages);
	A2XHG getGroup_45a3f0() throw();
	const A2XPoint &getPosition_45a4a0() throw();
	A2XPoint position_45a4c0();
	void *effect_45ac40(int effect);
	void *effect_45acb0(int effect);
	int collectParts_5cb8b0(std::vector<A2XHI> *parts);

	int pad0;
	A2XHE self;	// +0x04
	A2XEntityDef *def;	// +0x08
	char padc[0x28 - 0x0c];
	A2XHG faction;	// +0x28
	char pad2c[0x98 - 0x2c];
	int damageChance;	// +0x98
	char pad9c[0xb0 - 0x9c];
	int salvageChance;	// +0xb0
	int salvageModifier;	// +0xb4
	char padb8[0xc0 - 0xb8];
	bool keepAll;	// +0xc0
	char padc1[0x134 - 0xc1];
	std::vector<A2XHI> inventory;	// +0x134
};

extern A2XMap *a2x_map_cefc4c;
extern A2XGrid a2x_grid_cfd44c;
extern A2XStats a2x_stats_d2c658;
extern A2XParts *a2x_parts_cec088;
extern A2XFactory *a2x_factory_cefaa8;
extern A2XGameData a2x_gameData_d1e860;
extern A2XWorldHandle a2x_world_d1e888;
extern A2XConsole *a2x_console_cec058;
extern A2XLog *a2x_log_cec0b4;
extern int a2x_mode_cf462c;
extern int a2x_difficulty_cf4718;
extern int a2x_destroyAll_cf472c;
extern bool a2x_salvageTypes_b951c0[];
extern bool a2x_dropCategories_b9651c[];
extern bool a2x_worldTypes_b90130[];
extern int a2x_matterPenalty_ba77fc[];
extern int a2x_bonusChance_ba7ec0[];
extern A2XFloatRange a2x_bonusRange_cfbed8[];
extern const float a2x_allyFactor_ba7ecc;
extern const float a2x_maxDrops_c36ecc;
extern A2XPoint a2x_matterCap_d3861c;
extern A2XPoint a2x_markTurns_d2d1bc;
extern std::vector<A2XEffectDef *> a2x_effects_d2f0f8;
extern A2XItemDef *a2x_def_cefbe8;
extern A2XItemDef *a2x_def_cefbec;
extern A2XItemDef *a2x_def_cefbf4;
extern A2XItemDef *a2x_def_cefbf8;
extern A2XItemDef *a2x_def_cefbfc;
extern const char a2x_empty_b95141[];
extern const char a2x_empty_b95142[];
extern const char a2x_empty_b95143[];
extern const char a2x_empty_b951b1[];
extern const char a2x_empty_b951b2[];
extern const char a2x_empty_b951b3[];
extern const char a2x_empty_b951bd[];
extern const char a2x_empty_b951be[];
extern const char a2x_empty_b951bf[];
extern const char a2x_empty_b95221[];
extern const char a2x_empty_b95222[];

bool a2x_show_5111e0(int id, const string &text, string *a, string *b, A2XHE entity, A2XHE other, int c, int d);
bool a2x_show0_5111e0(int id, int text, string *a, string *b, A2XHE entity, A2XHE other, int c, int d);
int a2x_min_9cdb30(int a, int b);
int a2x_max_9cdb60(int a, int b);
void a2x_clampMin_9cf5c0(int *value, int min);
bool a2x_between_9daf80(int low, int value, int high);
void a2x_shuffle_9d9fc0(std::vector<A2XHI> &list);

#define A2X_MSG(ID,TEXT) do{if(a2x_show_5111e0(ID,TEXT,0,0,self,A2XHE(),0,0))a2x_console_cec058->bubble_8758d0(true);a2x_log_cec0b4->scrollToEnd_7b4f10();}while(false)
#define A2X_MSG0(ID) do{if(a2x_show0_5111e0(ID,0,0,0,self,A2XHE(),0,0))a2x_console_cec058->bubble_8758d0(true);a2x_log_cec0b4->scrollToEnd_7b4f10();}while(false)

bool A2XEntity::drop_631a20(A2XHE killer, bool showMessages)
{
	int value = a2x_min_9cdb30(def->salvage.randomInRange_40c130() + salvageModifier,def->salvage.y);
	if (value > 0)
	{
		if (a2x_mode_cf462c == 5 && a2x_salvageTypes_b951c0[def->type] && !keepAll)
		{
			if (rng.chance(40))
			{
				int amount = a2x_min_9cdb30(a2x_matterCap_d3861c.randomInRange_40c130(),def->salvage.randomInRange_40c130() + a2x_min_9cdb30(0,salvageModifier));
				amount -= a2x_gameData_d1e860.getDepthIndex() * a2x_matterPenalty_ba77fc[a2x_difficulty_cf4718];
				if (amount > 0)
				{
					A2XHI item = a2x_map_cefc4c->spawnMatter_71e7c0(position_45a4c0(),amount,true);
					if (item.valid_9b7230())
					{
						a2x_map_cefc4c->place_464840(item);
						if (killer.equals_9b78e0(a2x_map_cefc4c->getPlayer_4630f0()) && self.notEquals_9b6510(a2x_map_cefc4c->getPlayer_4630f0()))
							a2x_stats_d2c658.add_4729d0(1089,amount,a2x_empty_b95141,-1);
					}
				}
				goto inventory;
			}
			else
			{
				value += value * 40 / 100;
				A2XHI item = a2x_map_cefc4c->spawnMatter_71e7c0(position_45a4c0(),value,false);
				if (item.valid_9b7230())
					a2x_map_cefc4c->place_464840(item);
			}
		}
		if (a2x_mode_cf462c == 11 && a2x_salvageTypes_b951c0[def->type] && !keepAll)
		{
			if (def->bonusMatter && rng.chance(a2x_bonusChance_ba7ec0[a2x_difficulty_cf4718]))
			{
				int amount = a2x_max_9cdb60(1,(int)(def->bonusMatter * a2x_bonusRange_cfbed8[a2x_difficulty_cf4718].random_40c700()));
				if (a2x_map_cefc4c->relation_463910(faction,a2x_map_cefc4c->getPlayer_4630f0().get_9b6570()->getGroup_45a3f0()) == 2)
				{
					amount = (int)(amount * a2x_allyFactor_ba7ecc);
					a2x_clampMin_9cf5c0(&amount,1);
				}
				A2XHI item = a2x_map_cefc4c->spawnMatter_71e7c0(position_45a4c0(),amount,true);
				if (item.valid_9b7230())
				{
					a2x_map_cefc4c->place_464840(item);
					a2x_stats_d2c658.add_4729d0(1117,amount,a2x_empty_b95142,-1);
				}
				goto inventory;
			}
			else
			{
				value += value * 40 / 100;
				A2XHI item = a2x_map_cefc4c->spawnMatter_71e7c0(position_45a4c0(),value,false);
				if (item.valid_9b7230())
					a2x_map_cefc4c->place_464840(item);
			}
		}
		else
		{
			A2XHI item = a2x_map_cefc4c->spawnMatter_71e7c0(position_45a4c0(),value,false);
			if (item.valid_9b7230())
				a2x_map_cefc4c->place_464840(item);
			if (a2x_mode_cf462c == 6)
			{
				int amount = def->salvage.randomInRange_40c130() + a2x_min_9cdb30(0,salvageModifier);
				amount = amount / 2;
				if (amount > 0)
				{
					A2XHI extra = a2x_map_cefc4c->spawnMatter_71e7c0(position_45a4c0(),amount,true);
					if (extra.valid_9b7230())
					{
						a2x_map_cefc4c->place_464840(extra);
						if (killer.equals_9b78e0(a2x_map_cefc4c->getPlayer_4630f0()) && self.notEquals_9b6510(a2x_map_cefc4c->getPlayer_4630f0()))
							a2x_stats_d2c658.add_4729d0(1089,amount,a2x_empty_b95143,-1);
					}
				}
			}
		}
		if (killer.equals_9b78e0(a2x_map_cefc4c->getPlayer_4630f0()) && self.notEquals_9b6510(a2x_map_cefc4c->getPlayer_4630f0()))
		{
			a2x_stats_d2c658.add_4729d0(212,value,a2x_empty_b951b1,-1);
			if (a2x_mode_cf462c == 3)
			{
				int count = 1;
				count += value * def->salvageParts / def->salvage.y / 2;
				std::vector<A2XHI> parts;
				if (killer.get_9b6570()->collectParts_5cb8b0(&parts))
				{
					int old;
					for (unsigned int i = 0; i < parts.size(); i++)
					{
						old = parts[i].get_9b65b0()->integrity_9b6bf0();
						int rate = parts[i].get_9b65b0()->value_457c80();
						int amount = rate / 100;
						for (int j = 0; j < count; j++)
						{
							if (rate < 100)
							{
								if (rng.chance(rate))
									amount = 1;
							}
							else if (rate % 100 && rng.chance(rate % 100))
								amount++;
							parts[i].get_9b65b0()->setCount_458360(amount);
						}
						if (parts[i].get_9b65b0()->integrity_9b6bf0() != old)
						{
							A2XPart *part = a2x_parts_cec088->find_894e70(parts[i].id);
							if (part)
								part->drawStatus_4a8e70(false);
						}
					}
				}
			}
		}
	}
inventory:
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].get_9b65b0()->getType_44aec0() == 4 && !inventory[i].get_9b65b0()->getDef_9b4350()->unique)
		{
			A2XPoint dest;
			if (a2x_map_cefc4c->findDrop_71bc10(position_45a4c0(),dest))
			{
				if (inventory[i].get_9b65b0()->unknown457f90() == 124 && def->type == 25)
				{
					a2x_stats_d2c658.add_4729d0(881,1,a2x_empty_b951b2,-1);
					a2x_stats_d2c658.add_4729d0(884,1,a2x_empty_b951b3,-1);
				}
				inventory[i].get_9b65b0()->place_57a0f0(dest,true,0);
				i--;
			}
		}
	}
	if (a2x_destroyAll_cf472c)
	{
		while (!inventory.empty())
			inventory.front().get_9b65b0()->remove_57dbe0(false,true,true,true);
		return false;
	}
	if (!inventory.empty())
		a2x_shuffle_9d9fc0(inventory);
	bool success = false;
	bool dead = effect_45acb0(18);
	if (dead)
	{
		A2XHI result;
		A2XRect area;
		a2x_grid_cfd44c.getRect_9b4430(getPosition_45a4a0(),15,area);
		for (int x = area.x; x < area.x2; x++)
		{
			for (int y = area.y; y < area.y2; y++)
			{
				if (a2x_grid_cfd44c.at_9ceda0(x,y)[0]->getItem_45d8f0().valid_9b7230() && a2x_grid_cfd44c.at_9ceda0(x,y)[0]->getItem_45d8f0().get_9b65b0()->getEffect_457b70(72) && a2x_grid_cfd44c.at_9ceda0(x,y)[0]->getItem_45d8f0().get_9b65b0()->getEffect_457b70(83))
				{
					result = a2x_grid_cfd44c.at_9ceda0(x,y)[0]->getItem_45d8f0();
					goto searched;
				}
			}
		}
searched:
		if (result.valid_9b7230())
		{
			A2X_MSG(22,result.get_9b65b0()->getName_571db0(false,false));
			dead = false;
		}
		else if (rng.chance(salvageChance))
		{
			A2X_MSG0(21);
			dead = false;
		}
		else
			A2X_MSG0(20);
	}
	else if (keepAll)
		dead = true;
	bool hidden = effect_45ac40(50);
	if (hidden && !inventory.empty())
		A2X_MSG0(59);
	while (!inventory.empty())
	{
		if (!dead && a2x_dropCategories_b9651c[inventory.front().get_9b65b0()->getDef_9b4350()->category] && !inventory.front().get_9b65b0()->getEffect_457b70(109) && !keepAll && (hidden || rng.chance(inventory.front().get_9b65b0()->value_457ca0() / 2 + salvageModifier))
			&& !(a2x_mode_cf462c == 1 && a2x_between_9daf80(20,inventory.front().get_9b65b0()->chance_457880(),30)) && a2x_mode_cf462c != 2)
		{
			int destroyChance = hidden ? 0 : salvageChance - inventory.front().get_9b65b0()->value_457c80();
			int damageChance = hidden ? 0 : (this->damageChance - inventory.front().get_9b65b0()->value_457c80()) / 4;
			if (destroyChance > 0 && rng.chance(destroyChance))
			{
				if (showMessages && killer.equals_9b78e0(a2x_map_cefc4c->getPlayer_4630f0()))
				{
					A2X_MSG(63,inventory.front().get_9b65b0()->getName_571db0(false,false));
					a2x_stats_d2c658.add_4729d0(512,1,a2x_empty_b951bd,-1);
				}
			}
			else if (damageChance > 0 && rng.chance(damageChance))
			{
				if (showMessages && killer.equals_9b78e0(a2x_map_cefc4c->getPlayer_4630f0()))
				{
					A2X_MSG(64,inventory.front().get_9b65b0()->getName_571db0(false,false));
					a2x_stats_d2c658.add_4729d0(516,1,a2x_empty_b951be,-1);
				}
			}
			else if (!hidden && inventory.front().get_9b65b0()->getDef_9b4350() == a2x_def_cefbe8 && rng.chance(85))
			{
				A2XPoint dest;
				int total = rng.rangeInt(1,a2x_maxDrops_c36ecc);
				for (int k = 0; k < total; k++)
				{
					if (a2x_map_cefc4c->findDrop_71bc10(position_45a4c0(),dest))
					{
						A2XHI item = a2x_factory_cefaa8->create_7932b0(a2x_def_cefbec);
						item.get_9b65b0()->place_57a0f0(dest,true,0);
						item.get_9b65b0()->addEffect_4585a0(new A2XEffect(a2x_effects_d2f0f8[101],1));
						a2x_map_cefc4c->place_464840(item);
						item.get_9b65b0()->setIntegrity_458310(rng.rangeInt(0,item.get_9b65b0()->integrity_9b6bf0() / 4));
					}
				}
				success = true;
				if (killer.equals_9b78e0(a2x_map_cefc4c->getPlayer_4630f0()))
					a2x_stats_d2c658.add_4729d0(213,total,a2x_empty_b951bf,-1);
			}
			else if (inventory.front().get_9b65b0()->getDef_9b4350() == a2x_def_cefbf4 || inventory.front().get_9b65b0()->getDef_9b4350() == a2x_def_cefbf8)
			{
				A2XPoint dest;
				int total = inventory.front().get_9b65b0()->count_4578c0();
				for (int k = 0; k < total; k++)
				{
					if (a2x_map_cefc4c->findDrop_71bc10(position_45a4c0(),dest))
					{
						A2XHI item = a2x_factory_cefaa8->create_7932b0(a2x_def_cefbfc);
						item.get_9b65b0()->place_57a0f0(dest,true,0);
						item.get_9b65b0()->addEffect_4585a0(new A2XEffect(a2x_effects_d2f0f8[101],1));
						a2x_map_cefc4c->place_464840(item);
						item.get_9b65b0()->setIntegrity_458310(rng.rangeInt(0,item.get_9b65b0()->integrity_9b6bf0() / 4));
					}
				}
				success = true;
				if (killer.equals_9b78e0(a2x_map_cefc4c->getPlayer_4630f0()))
					a2x_stats_d2c658.add_4729d0(213,total,a2x_empty_b95221,-1);
			}
			else
			{
				A2XPoint dest;
				int flags = a2x_worldTypes_b90130[a2x_world_d1e888.get_9b7910()->type] && (faction.get_9b7250()->type_9b4350() == 3 || faction.get_9b7250()->type_9b4350() == 4) && (def->kind == 1 || def->kind == 2);
				if (a2x_map_cefc4c->findDrop_71bc10(position_45a4c0(),dest))
				{
					a2x_map_cefc4c->place_464840(inventory.front());
					if (flags)
						a2x_map_cefc4c->mark_727e30(inventory.front(),a2x_map_cefc4c->turns_4642d0(salvageChance) + a2x_markTurns_d2d1bc.randomInRange_40c130());
					A2XEffect *effect = inventory.front().get_9b65b0()->getEffect_457b70(101);
					if (effect)
						effect->amount++;
					else
						inventory.front().get_9b65b0()->addEffect_4585a0(new A2XEffect(a2x_effects_d2f0f8[101],1));
					if (!hidden)
					{
						inventory.front().get_9b65b0()->setIntegrity_458310(rng.rangeInt(0,inventory.front().get_9b65b0()->integrity_9b6bf0() / 4));
						if (salvageChance && inventory.front().get_9b65b0()->unknown577990() && (salvageChance >= 100 || rng.chance(salvageChance)))
							inventory.front().get_9b65b0()->setScaled_579880(a2x_min_9cdb30(rng.rangeInt(1,a2x_max_9cdb60(1,salvageChance * 10 / 100)),15));
					}
					inventory.front().get_9b65b0()->setActive_5791a0(false);
					inventory.front().get_9b65b0()->place_57a0f0(dest,true,0);
					success = true;
					if (killer.equals_9b78e0(a2x_map_cefc4c->getPlayer_4630f0()))
						a2x_stats_d2c658.add_4729d0(213,1,a2x_empty_b95222,-1);
					goto next;
				}
			}
		}
		inventory.front().get_9b65b0()->remove_57dbe0(false,true,true,true);
next:;
	}
	return success;
}
