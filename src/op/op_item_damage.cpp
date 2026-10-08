// op_item_damage: Item::takeDamage_57ab10 (0x57ab10), applies damage to an item/part, reports the hit or
// destruction in the log and runs the on-destroy effects; returns true if the item was destroyed
// (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

class Entity;
class HEntity
{
public:
	int ID;
	HEntity();	// 0x9b6590
	Entity *operator->() const;	// 0x9b6570
	bool isValid() const;	// 0x9b65e0
	bool operator==(HEntity other) const;	// 0x9b6500
};
class Entity
{
public:
	bool isPlayer();	// 0x5c7600
	int unknown45a8d0();	// NOTE: placeholder name
	void unknown45b1b0(int value);	// NOTE: placeholder name
	string unknown45a410();	// NOTE: placeholder name (name)
	int getFaction();	// 0x45a2c0
	bool isHostileTo(HEntity other);	// 0x45aa70
	bool unknown5d6480(int item);	// NOTE: placeholder name
	bool unknown5c7f70();	// NOTE: placeholder name
	int unknown5c7fc0(HEntity other);	// NOTE: placeholder name
	int unknown5d22a0(int type);	// NOTE: placeholder name
	void unknown5deb40(int value);	// NOTE: placeholder name
	void die(bool a, int b, HEntity c, int d, int e, int f, int g, int h);	// 0x633790
};

struct OpIT_Record	// NOTE: placeholder name (item record)
{
	char pad00[0x48];
	int type;	// +0x48
	char pad4c[0x94 - 0x4c];
	int unknown94;	// +0x94
	char pad98[0xec - 0x98];
	int unknownec;	// +0xec
	int effect;	// +0xf0
	int effectValue;	// +0xf4
};

class OpIT_Handle	// NOTE: placeholder name (HItem)
{
public:
	int ID;
	void *get224();	// NOTE: placeholder name
};

class OpIT_Map	// NOTE: placeholder name (BS at 0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
	int *unknown4640c0();	// NOTE: placeholder name
	void *unknown4636d0();	// NOTE: placeholder name
	bool unknown714a50();	// NOTE: placeholder name
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
};
extern OpIT_Map *opIT_map;	// NOTE: placeholder name

class OpIT_Xom	// NOTE: placeholder name (0xd25450)
{
public:
	bool active;
	void unknown69e700(int event, int flag, float value);	// NOTE: placeholder name
	bool unknown69eba0(int item);	// NOTE: placeholder name
};
extern OpIT_Xom opIT_xom_d25450;	// NOTE: placeholder name

class OpIT_Stats	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern OpIT_Stats opIT_stats;	// NOTE: placeholder name

class OpIT_Owned	// NOTE: placeholder name
{
public:
	void unknown672f20(HEntity e, int a, int b, string text);	// NOTE: placeholder name
};
extern OpIT_Owned *opIT_cf68f0;	// NOTE: placeholder name
extern int opIT_cf68b4;	// NOTE: placeholder name
extern HEntity opIT_cf68b8;	// NOTE: placeholder name

class OpIT_ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpIT_ConsoleA *opIT_consoleA_cec058;	// NOTE: placeholder name
class OpIT_LogMsgs	// NOTE: placeholder name (CLogMsgs)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpIT_LogMsgs *opIT_logMsgs_cec0b4;	// NOTE: placeholder name
extern OpIT_LogMsgs *opIT_combatLog_cec0c4;	// NOTE: placeholder name

class OpIT_Sounds	// NOTE: placeholder name (0xd1f3d4)
{
public:
	int lookup_folded(const string &name);	// NOTE: placeholder name
};
extern OpIT_Sounds opIT_sounds_d1f3d4;	// NOTE: placeholder name
extern string opIT_soundNames_d323f8[];	// NOTE: placeholder name
extern string opIT_critNames_d1e058[];	// NOTE: placeholder name

class CPart
{
public:
	void drawStatus(bool flag);	// 0x4a8e70
};
class OpIT_Parts	// NOTE: placeholder name (CParts at 0xcec088)
{
public:
	CPart *unknown894e70(int item);	// NOTE: placeholder name
};
extern OpIT_Parts *opIT_parts_cec088;	// NOTE: placeholder name

class OpIT_PlayerData	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
	bool hasCompanion();	// NOTE: placeholder name
};
extern OpIT_PlayerData opIT_playerData;	// NOTE: placeholder name

class OpIT_Spawner	// NOTE: placeholder name (OpU5_SpawnTracker)
{
public:
	void spawn(int type, int a, string text);	// NOTE: placeholder name
};
struct OpIT_Tracker { char pad[0x30]; OpIT_Spawner *spawner; };	// NOTE: placeholder name
extern OpIT_Tracker *opIT_cf4ac8;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);	// 0x406c90
};
extern RNG rng;

extern unsigned char opIT_reduces_ba0968[];	// NOTE: placeholder name
extern float opIT_reduction_ba09b0[];	// NOTE: placeholder name
extern int opIT_d28d18;	// NOTE: placeholder name
extern int opIT_cf4b38;	// NOTE: placeholder name
extern const char empty_b91d16[];	// NOTE: placeholder name ("")
extern const char empty_b91d17[];	// NOTE: placeholder name ("")
extern const char empty_b91d26[];	// NOTE: placeholder name ("")
extern const char empty_b91d27[];	// NOTE: placeholder name ("")
extern const char empty_b91d36[];	// NOTE: placeholder name ("")
extern const char empty_b91d37[];	// NOTE: placeholder name ("")
extern const char opIT_s_be2880[];	// NOTE: placeholder name (" ")
extern const char opIT_s_be2884[];	// NOTE: placeholder name
extern const char opIT_s_be2888[];	// NOTE: placeholder name (")")
extern const char opIT_s_be288c[];	// NOTE: placeholder name (" (Crit: ")
extern const char opIT_s_be2898[];	// NOTE: placeholder name (" ")
extern const char opIT_s_be289c[];	// NOTE: placeholder name
extern const char opIT_s_be28d8[];	// NOTE: placeholder name (")")
extern const char opIT_s_be28dc[];	// NOTE: placeholder name (" (Crit: ")

string intToString(int value);	// 0x4051f0
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)
void OpV4c_Fn9d0690(int *value, int step, int low);	// NOTE: placeholder name
bool opIT_log_5111e0(int id, const string &text, int a, int b, HEntity c, HEntity d, int e, int f);	// NOTE: placeholder name
bool OpS1c_unknown4569a0(int a, HEntity b, HEntity c, HEntity d, int e, int f, int g, int h, HEntity i, HEntity j, int k, int l);	// NOTE: placeholder name

#define OPIT_LOG(id,text,c,f,bubble,log) do { if (opIT_log_5111e0(id,text,0,0,c,HEntity(),0,f)) opIT_consoleA_cec058->unknown8758d0(bubble); log->scrollToEnd(); } while (0)	// NOTE: placeholder macro

class Item
{
public:
	bool takeDamage_57ab10(int damage, int sound, int chance, int crit, HEntity attacker, int report, int *overflow);	// NOTE: placeholder name
	bool unknown457cf0();	// NOTE: placeholder name
	bool unknown457ad0();	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
	int unknown577fb0();	// NOTE: placeholder name
	string getName_571db0(int a, int b);	// NOTE: placeholder name
	void setActive(bool active);	// 0x5791a0
	void unknown57a620();	// NOTE: placeholder name
	void remove57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name

	int pad00;
	OpIT_Handle self;	// +0x04
	OpIT_Record *record;	// +0x08
	int slot;	// +0x0c
	HEntity owner;	// +0x10
	char pad14[0x1c - 0x14];
	int integrity;	// +0x1c
	char pad20[0x58 - 0x20];
	int unknown58;	// +0x58
};

bool Item::takeDamage_57ab10(int damage, int sound, int chance, int crit, HEntity attacker, int report, int *overflow)
{
	if (integrity == -1)
		return false;
	if (damage == -1)
		integrity = 0;
	else
	{
		if (owner.operator->())
		{
			if (record->effect == 0x3f && owner.operator->() && unknown457cf0() && owner->unknown45a8d0() >= damage / 2 * record->effectValue)
			{
				owner->unknown45b1b0(damage / 2 * record->effectValue);
				damage = damage / 2;
			}
			if (owner->isPlayer() && opIT_reduces_ba0968[record->unknownec] && unknown577fb0() == 2)
			{
				int reduced = damage * opIT_reduction_ba09b0[record->unknownec];
				if (reduced != damage)
				{
					opIT_stats.add4729d0(0x174,damage - reduced,empty_b91d16,-1);
					damage = reduced;
				}
			}
		}
		if (overflow && damage > integrity)
			*overflow = damage - integrity;
		OpV4c_Fn9d0690(&integrity,damage,0);
	}
	if (integrity <= 0)
	{
		if (owner.isValid())
		{
			if (owner->isPlayer())
			{
				OPIT_LOG(0x3c,getName_571db0(0,0),owner,0,true,opIT_logMsgs_cec0b4);
				if (damage == -1)
					opIT_stats.add4729d0(0x96,1,empty_b91d17,-1);
				if (attacker.isValid() && record->type == 3)
				{
					(*opIT_map->unknown4640c0())++;
					if (opIT_xom_d25450.active && !owner->unknown5d6480(self.ID) && opIT_map->unknown4636d0())
						opIT_xom_d25450.unknown69e700(0xf,0,0.0f);
				}
				if (opIT_xom_d25450.active)
				{
					if (record->effect == 0xda)
						opIT_xom_d25450.unknown69e700(0xd,0,0.0f);
					else if (attacker.operator->())
					{
						if (attacker->isPlayer())
						{
							if (opIT_map->unknown714a50())
								opIT_xom_d25450.unknown69e700(8,opIT_xom_d25450.unknown69eba0(self.ID) != 0,0.0f);
						}
						else if (attacker->isHostileTo(opIT_map->getPlayer()))
						{
							if (attacker->getFaction() == 0x1a && !opIT_map->unknown4631f0(attacker))
								opIT_xom_d25450.unknown69e700(0xb,opIT_xom_d25450.unknown69eba0(self.ID) != 0,0.0f);
						}
						else
							opIT_xom_d25450.unknown69e700(0xa,opIT_xom_d25450.unknown69eba0(self.ID) != 0,0.0f);
					}
				}
				if (opIT_cf68b4 && attacker.operator->() && opIT_cf68b8 == attacker)
					opIT_cf68f0->unknown672f20(attacker,7,0,empty_b91d26);
			}
			else if (owner->unknown5c7f70())
				OPIT_LOG(0x3d,getName_571db0(0,0),owner,0,true,opIT_logMsgs_cec0b4);
			if (opIT_d28d18 >= 0 && report)
			{
				string text = opIT_s_be2884 + (owner->isPlayer() ? string(empty_b91d27) : owner->unknown45a410() + opIT_s_be2880) + getName_571db0(0,0) + " destroyed";
				switch (crit)
				{
					case 3:
					case 6:
						text += opIT_s_be288c + opIT_critNames_d1e058[crit] + opIT_s_be2888;
				}
				OPIT_LOG(owner->isPlayer() ? 0x2c9 : (owner->unknown5c7fc0(opIT_map->getPlayer()) != 2) + 0x2ca,text,owner,1,false,opIT_combatLog_cec0c4);
			}
			if (record->effect == 0x4d)
				setActive(false);
			int extra = OpX5_maxInt(5,owner->unknown5d22a0(0x4d));
			if (extra > 5)
				OPIT_LOG(0x50,intToString(extra),owner,0,true,opIT_logMsgs_cec0b4);
			owner->unknown5deb40(extra);
			if (report == 2 && attacker.operator->() && attacker->isPlayer())
				opIT_playerData.unknown77fbc0(0x28);
		}
		if (slot == 5)
		{
			opIT_sounds_d1f3d4.lookup_folded(opIT_soundNames_d323f8[sound]);
			OpS1c_unknown4569a0(5,HEntity(),HEntity(),HEntity(),self.ID,0,0,unknown58,HEntity(),HEntity(),self.ID,0);
		}
		if (record->effect == 0x66 && owner.operator->())
		{
			OpIT_Handle me = self;
			if (owner->isPlayer())
				opIT_cf4b38 = 0x14;
			owner->die(opIT_map->unknown4631f0(owner),7,HEntity(),0,0,0,0,0);
			if (!me.get224())
				return true;
		}
		remove57dbe0(1,1,1,1);
		return true;
	}
	else
	{
		if (owner.isValid())
		{
			if (owner == opIT_map->getPlayer() && slot != 4)
			{
				CPart *part = opIT_parts_cec088->unknown894e70(self.ID);
				if (part)
					part->drawStatus(true);
			}
			if (opIT_d28d18 >= 0 && report)
			{
				string text = opIT_s_be289c + (owner->isPlayer() ? string(empty_b91d36) : owner->unknown45a410() + opIT_s_be2898) + getName_571db0(0,0);
				if (damage == 0 && crit && OpT8b_Fn9daf80(0x39,unknown457f90(),0x3d))
				{
					text += " prevented critical effect";
					OPIT_LOG(owner->isPlayer() ? 0x2d0 : (owner->unknown5c7fc0(opIT_map->getPlayer()) != 2) + 0x2d1,text,owner,1,false,opIT_combatLog_cec0c4);
				}
				else
				{
					switch (report)
					{
						case 1:
							text += " damaged: ";
							break;
						case 2:
							text += " overflow dmg: ";
							break;
					}
					text += intToString(damage);
					if (crit)
						text += opIT_s_be28dc + opIT_critNames_d1e058[crit] + opIT_s_be28d8;
					OPIT_LOG(owner->isPlayer() ? 0x2c6 : (owner->unknown5c7fc0(opIT_map->getPlayer()) != 2) + 0x2c7,text,owner,1,false,opIT_combatLog_cec0c4);
				}
			}
			if (damage > 0 && record->effect == 0xd6 && owner == opIT_map->getPlayer() && opIT_playerData.hasCompanion())
				opIT_cf4ac8->spawner->spawn(0x22,0,empty_b91d37);
			if (chance && unknown457cf0() && !unknown457ad0() && record->unknown94 != 2 && rng.chance(chance) && !unknown577fb0())
				unknown57a620();
		}
		return false;
	}
}
