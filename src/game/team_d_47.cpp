// team_d_47: Item member 0x57a620 (disruption: a part is disabled unless a shield prevents it).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <string>
using namespace std;

class Entity;
class Item;

class HEntity
{
	int ID;
public:
	Entity *operator->() const;
};

class HProp
{
	int ID;
public:
	HProp();
};

class HItem
{
	int ID;
public:
	bool isValid() const;
	bool isNull() const;
	Item *operator->() const;
};

class Entity
{
public:
	bool isPlayer();				// 0x5c7600
	HItem unknown5d2380(int slot);	// NOTE: placeholder name
	void unknown5fd550(HItem item, int turns);	// NOTE: placeholder name
	string unknown45a410() const;	// NOTE: placeholder name (name)
	int unknown5c7fc0(HEntity other);	// NOTE: placeholder name (relation to other)
};

class Item
{
public:
	char	pad00[4];
	HItem	self;		// +0x04
	char	pad08[0x10 - 0x08];
	HEntity	owner;		// +0x10

	int unknown4578a0();				// NOTE: placeholder name (folded getter, slot)
	string unknown571db0(int a, int b);	// NOTE: placeholder name (item name)
	bool unknown57a620();				// NOTE: placeholder name
};

class Range47	// NOTE: placeholder name
{
public:
	int randomInRange();	// NOTE: folded with Point::randomInRange_40c130
};
extern Range47 disruption47_d38724;	// NOTE: placeholder name
extern int int_d28d18;	// NOTE: placeholder name

class CPart47	// NOTE: placeholder name (CPart)
{
public:
	void unknown890710(int value);	// NOTE: placeholder name
};

class CParts47	// NOTE: placeholder name (CParts at 0xcec088)
{
public:
	void unknown89d610(HItem item, int value);	// NOTE: placeholder name
	CPart47 *unknown894e70(HItem item);	// NOTE: placeholder name
};
extern CParts47 *parts47_cec088;	// NOTE: placeholder name

class Map47	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getPlayer();
};
extern Map47 *world47;	// NOTE: placeholder name (0xcefc4c)

class Stats47	// NOTE: placeholder name (0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
};
extern Stats47 stats_d2c658;	// NOTE: placeholder name

class ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA *consoleA_cec058;	// NOTE: placeholder name
class CLogMsgs
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern CLogMsgs *logMsgs47_cec0c4;	// NOTE: placeholder name
bool logMessageS_5111e0(int id, const string &text, int a, int b, HEntity e, HProp d, int f, int g);	// NOTE: placeholder name (0x5111e0)

bool Item::unknown57a620()
{
	if (owner->isPlayer())
		stats_d2c658.add4729d0(0x16f,1,"",-1);
	HItem shield = owner->unknown5d2380(0x29);
	if (shield.isNull())
		shield = owner->unknown5d2380(unknown4578a0() + 0x3a);
	if (shield.isValid())
	{
		if (owner->isPlayer())
		{
			string text = "  " + shield->unknown571db0(0,0) + " prevented disruption";
			do { if (logMessageS_5111e0(0x2d0,text,0,0,owner,HProp(),0,1)) consoleA_cec058->unknown8758d0(false); logMsgs47_cec0c4->scrollToEnd(); } while (0);
			stats_d2c658.add4729d0(0x170,1,"",-1);
		}
		return false;
	}
	else
	{
		owner->unknown5fd550(self,disruption47_d38724.randomInRange());
		if (owner->isPlayer())
		{
			parts47_cec088->unknown89d610(self,0xc);
			CPart47 *part = parts47_cec088->unknown894e70(self);
			if (part)
				part->unknown890710(0);
		}
		if (int_d28d18 >= 0)
		{
			string msg("  ");
			if (!owner->isPlayer())
				msg += owner->unknown45a410() + " ";
			msg += unknown571db0(0,0) + " disabled (Disruption)";
			do { if (logMessageS_5111e0(0x2c7 + (owner->unknown5c7fc0(world47->getPlayer()) != 2),msg,0,0,owner,HProp(),0,1)) consoleA_cec058->unknown8758d0(false); logMsgs47_cec0c4->scrollToEnd(); } while (0);
		}
		return true;
	}
}
