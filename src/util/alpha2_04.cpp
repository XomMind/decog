// alpha2_04: Item::damage (0x57ab10): applies damage to an item's integrity, logs the result and
//	destroys the item at zero integrity.
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <string>
#include "rng.h"
using std::string;
extern RNG rng;

struct A2DEntity;
struct A2DItem;
struct A2DHE	// HEntity
{
	int id;
	A2DHE() throw();	// 0x9b6590
	A2DEntity *get_9b6570() const throw();
	bool valid_9b7230() const throw();
	bool equals_9b78e0(A2DHE other) const throw();
};
struct A2DHI	// HItem
{
	int id;
	A2DItem *get_9b65b0() const throw();
};
struct A2DEntity
{
	int faction_45a2c0() throw();
	string name_45a410();
	int value_45a8d0() throw();
	bool hostile_45aa70(A2DHE other);
	void drain_45b1b0(int amount);
	bool player_5c7600() throw();
	bool flag_5c7f70();
	int relation_5c7fc0(A2DHE other);
	int count_5d22a0(int kind);
	bool owns_5d6480(int item);
	void shake_5deb40(int amount);
	void die_633790(bool seen, int cause, A2DHE killer, int a, int b, int c, int d, int e);
};
struct A2DItemDef
{
	char pad0[0x48];
	int slot;	// +0x48
	char pad4c[0x94 - 0x4c];
	int rating;	// +0x94
	char pad98[0xec - 0x98];
	int category;	// +0xec
	int type;	// +0xf0
	int typeValue;	// +0xf4
};
struct A2DMap
{
	A2DHE getPlayer_4630f0();
	bool visible_4631f0(A2DHE entity);
	int mode_4636d0() throw();
	int *kills_4640c0() throw();
	bool flag_714a50();
};
struct A2DXom
{
	bool enabled;
	int event_69e700(int type, int level, float mult);
	bool owned_69eba0(int item);
};
struct A2DStats
{
	bool add_4729d0(unsigned int id, int value, string text, int extra);
};
struct A2DConsole
{
	void bubble_8758d0(bool flag);
};
struct A2DLog
{
	void scrollToEnd_7b4f10();
};
struct A2DPart
{
	void drawStatus_4a8e70(bool flag);
};
struct A2DParts
{
	A2DPart *find_894e70(int item);
};
struct A2DPlayerData
{
	bool event_77fbc0(int id);
	bool hasCompanion_780790();
};
struct A2DSpawnTracker
{
	void spawn_7aa280(int type, int count, string text);
};
struct A2DWorld
{
	char pad0[0x30];
	A2DSpawnTracker *spawner;	// +0x30
};
struct A2DOwned
{
	void notify_672f20(A2DHE entity, int type, int value, string text);
};

extern A2DMap *a2d_map_cefc4c;
extern A2DXom a2d_xom_d25450;
extern A2DStats a2d_stats_d2c658;
extern A2DConsole *a2d_console_cec058;
extern A2DLog *a2d_log_cec0b4;
extern A2DLog *a2d_log_cec0c4;
extern A2DParts *a2d_parts_cec088;
extern A2DPlayerData a2d_playerData_cf45d8;
extern A2DWorld *a2d_world_cf4ac8;
extern A2DOwned *a2d_owned_cf68f0;
extern int a2d_tracking_cf68b4;
extern A2DHE a2d_tracked_cf68b8;
extern int a2d_messageLevel_d28d18;
extern int a2d_alertTime_cf4b38;
extern bool a2d_reduced_ba0968[];
extern float a2d_reduction_ba09b0[];
extern string a2d_critNames_d1e058[];
extern string a2d_damageNames_d323f8[];
extern string a2d_lastDamage_d1f3d4;
extern const char a2d_empty_b91d16[];
extern const char a2d_empty_b91d17[];
extern const char a2d_empty_b91d26[];
extern const char a2d_empty_b91d27[];
extern const char a2d_empty_b91d36[];
extern const char a2d_empty_b91d37[];

bool a2d_show_5111e0(int id, const string &text, string *a, string *b, A2DHE entity, A2DHE other, int c, int d);
string a2d_intToString_4051f0(int value);
void a2d_subtractMin_9d0690(int *value, int amount, int min);
int a2d_max_9cdb60(int a, int b);
bool a2d_between_9daf80(int low, int value, int high);
bool a2d_salvage_4569a0(int type, A2DHE a, A2DHE b, A2DHE c, int item, int d, int e, void *inventory, A2DHE f, A2DHE g, int item2, int h);

struct A2DItem
{
	bool damage(int damage, int damageType, int chance, int crit, A2DHE attacker, int messageMode, int *overflow);
	bool unknown457ad0() throw();
	bool unknown457cf0() throw();
	int unknown457f90() throw();
	string getName_571db0(bool a, bool b);
	int unknown577fb0() throw();
	void setActive_5791a0(bool active);
	void unknown57a620();
	void remove_57dbe0(bool a, bool b, bool c, bool d);

	int pad0;
	A2DHI self;	// +0x04
	A2DItemDef *def;	// +0x08
	int location;	// +0x0c
	A2DHE owner;	// +0x10
	char pad14[0x1c - 0x14];
	int integrity;	// +0x1c
	char pad20[0x58 - 0x20];
	void *inventory;	// +0x58
};

#define A2D_MSG(ID,TEXT,FLAG,BUBBLE,LOG) do{if(a2d_show_5111e0(ID,TEXT,0,0,owner,A2DHE(),0,FLAG))a2d_console_cec058->bubble_8758d0(BUBBLE);LOG->scrollToEnd_7b4f10();}while(false)

bool A2DItem::damage(int damage, int damageType, int chance, int crit, A2DHE attacker, int messageMode, int *overflow)
{
	if (integrity == -1)
		return false;
	if (damage == -1)
		integrity = 0;
	else
	{
		if (owner.get_9b6570())
		{
			if (def->type == 63 && owner.get_9b6570() && unknown457cf0() && owner.get_9b6570()->value_45a8d0() >= damage / 2 * def->typeValue)
			{
				owner.get_9b6570()->drain_45b1b0(damage / 2 * def->typeValue);
				damage = damage / 2;
			}
			if (owner.get_9b6570()->player_5c7600() && a2d_reduced_ba0968[def->category] && unknown577fb0() == 2)
			{
				int reduced = (int)(damage * a2d_reduction_ba09b0[def->category]);
				if (reduced != damage)
				{
					a2d_stats_d2c658.add_4729d0(372,damage - reduced,a2d_empty_b91d16,-1);
					damage = reduced;
				}
			}
		}
		if (overflow && damage > integrity)
			*overflow = damage - integrity;
		a2d_subtractMin_9d0690(&integrity,damage,0);
	}
	if (integrity <= 0)
	{
		if (owner.valid_9b7230())
		{
			if (owner.get_9b6570()->player_5c7600())
			{
				A2D_MSG(60,getName_571db0(false,false),0,true,a2d_log_cec0b4);
				if (damage == -1)
					a2d_stats_d2c658.add_4729d0(150,1,a2d_empty_b91d17,-1);
				if (attacker.valid_9b7230() && def->slot == 3)
				{
					(*a2d_map_cefc4c->kills_4640c0())++;
					if (a2d_xom_d25450.enabled && !owner.get_9b6570()->owns_5d6480(self.id) && a2d_map_cefc4c->mode_4636d0())
						a2d_xom_d25450.event_69e700(15,0,0.0f);
				}
				if (a2d_xom_d25450.enabled)
				{
					if (def->type == 218)
						a2d_xom_d25450.event_69e700(13,0,0.0f);
					else if (attacker.get_9b6570())
					{
						if (attacker.get_9b6570()->player_5c7600())
						{
							if (a2d_map_cefc4c->flag_714a50())
								a2d_xom_d25450.event_69e700(8,a2d_xom_d25450.owned_69eba0(self.id) ? 1 : 0,0.0f);
						}
						else if (attacker.get_9b6570()->hostile_45aa70(a2d_map_cefc4c->getPlayer_4630f0()))
						{
							if (attacker.get_9b6570()->faction_45a2c0() == 26)
							{
								if (!a2d_map_cefc4c->visible_4631f0(attacker))
									a2d_xom_d25450.event_69e700(11,a2d_xom_d25450.owned_69eba0(self.id) ? 1 : 0,0.0f);
							}
						}
						else
							a2d_xom_d25450.event_69e700(10,a2d_xom_d25450.owned_69eba0(self.id) ? 1 : 0,0.0f);
					}
				}
				if (a2d_tracking_cf68b4 && attacker.get_9b6570() && a2d_tracked_cf68b8.equals_9b78e0(attacker))
					a2d_owned_cf68f0->notify_672f20(attacker,7,0,a2d_empty_b91d26);
			}
			else if (owner.get_9b6570()->flag_5c7f70())
				A2D_MSG(61,getName_571db0(false,false),0,true,a2d_log_cec0b4);
			if (a2d_messageLevel_d28d18 >= 0 && messageMode)
			{
				string text = "  " + (owner.get_9b6570()->player_5c7600() ? string(a2d_empty_b91d27) : owner.get_9b6570()->name_45a410() + " ") + getName_571db0(false,false) + " destroyed";
				switch (crit)
				{
					case 3:
					case 6:
						text += " (Crit: " + a2d_critNames_d1e058[crit] + ")";
				}
				A2D_MSG(owner.get_9b6570()->player_5c7600() ? 713 : 714 + (owner.get_9b6570()->relation_5c7fc0(a2d_map_cefc4c->getPlayer_4630f0()) != 2),text,1,false,a2d_log_cec0c4);
			}
			if (def->type == 77)
				setActive_5791a0(false);
			int amount = a2d_max_9cdb60(5,owner.get_9b6570()->count_5d22a0(77));
			if (amount > 5)
				A2D_MSG(80,a2d_intToString_4051f0(amount),0,true,a2d_log_cec0b4);
			owner.get_9b6570()->shake_5deb40(amount);
			if (messageMode == 2 && attacker.get_9b6570() && attacker.get_9b6570()->player_5c7600())
				a2d_playerData_cf45d8.event_77fbc0(40);
		}
		if (location == 5)
		{
			a2d_lastDamage_d1f3d4 = a2d_damageNames_d323f8[damageType];
			a2d_salvage_4569a0(5,A2DHE(),A2DHE(),A2DHE(),self.id,0,0,inventory,A2DHE(),A2DHE(),self.id,0);
		}
		if (def->type == 102 && owner.get_9b6570())
		{
			A2DHI item = self;
			if (owner.get_9b6570()->player_5c7600())
				a2d_alertTime_cf4b38 = 20;
			owner.get_9b6570()->die_633790(a2d_map_cefc4c->visible_4631f0(owner),7,A2DHE(),0,0,0,0,0);
			if (!item.get_9b65b0())
				return true;
		}
		remove_57dbe0(true,true,true,true);
		return true;
	}
	else
	{
		if (owner.valid_9b7230())
		{
			if (owner.equals_9b78e0(a2d_map_cefc4c->getPlayer_4630f0()) && location != 4)
			{
				A2DPart *part = a2d_parts_cec088->find_894e70(self.id);
				if (part)
					part->drawStatus_4a8e70(true);
			}
			if (a2d_messageLevel_d28d18 >= 0 && messageMode)
			{
				string text = "  " + (owner.get_9b6570()->player_5c7600() ? string(a2d_empty_b91d36) : owner.get_9b6570()->name_45a410() + " ") + getName_571db0(false,false);
				if (damage == 0 && crit && a2d_between_9daf80(57,unknown457f90(),61))
				{
					text += " prevented critical effect";
					A2D_MSG(owner.get_9b6570()->player_5c7600() ? 720 : 721 + (owner.get_9b6570()->relation_5c7fc0(a2d_map_cefc4c->getPlayer_4630f0()) != 2),text,1,false,a2d_log_cec0c4);
				}
				else
				{
					switch (messageMode)
					{
						case 1:
							text += " damaged: ";
							break;
						case 2:
							text += " overflow dmg: ";
							break;
					}
					text += a2d_intToString_4051f0(damage);
					if (crit)
						text += " (Crit: " + a2d_critNames_d1e058[crit] + ")";
					A2D_MSG(owner.get_9b6570()->player_5c7600() ? 710 : 711 + (owner.get_9b6570()->relation_5c7fc0(a2d_map_cefc4c->getPlayer_4630f0()) != 2),text,1,false,a2d_log_cec0c4);
				}
			}
			if (damage > 0 && def->type == 214 && owner.equals_9b78e0(a2d_map_cefc4c->getPlayer_4630f0()) && a2d_playerData_cf45d8.hasCompanion_780790())
				a2d_world_cf4ac8->spawner->spawn_7aa280(34,0,a2d_empty_b91d37);
			if (chance && unknown457cf0() && !unknown457ad0() && def->rating != 2 && rng.chance(chance) && !unknown577fb0())
				unknown57a620();
		}
		return false;
	}
}
