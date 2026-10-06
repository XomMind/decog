// Item header-inline accessors (0x457a70-0x457f67) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members and names are placeholders.
#include <vector>
using namespace std;

class Entity;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool isValid() const;
	Entity *operator->() const;
};

struct ItemEffectType	// NOTE: placeholder name
{
	int	ID;	// NOTE: placeholder name
};

struct ItemEffect	// NOTE: placeholder name
{
	ItemEffectType	*type;	// NOTE: placeholder name
	int				state;	// NOTE: placeholder name
};

struct ItemEffectList	// NOTE: placeholder name
{
	vector<ItemEffect *>	effects;	// NOTE: placeholder name

	int unknown456430(int type);	// NOTE: placeholder name (count of effects of this type)
};

struct SlotAscii	// NOTE: placeholder name
{
	int	ascii;	// NOTE: placeholder name
	int	unknown04;	// NOTE: placeholder name
};

extern bool asciiEnabled;	// NOTE: placeholder name (0xd28d30)
extern SlotAscii unknown_d01618[];	// NOTE: placeholder name

struct ItemType	// NOTE: placeholder name
{
	char	pad00[0x44];
	int		slot;	// NOTE: placeholder name
	char	pad48[0x70 - 0x48];
	int		unknown70;	// NOTE: placeholder name
	int		pad74;
	int		tile;	// NOTE: placeholder name
	char	pad7c[0x90 - 0x7c];
	bool	autoActivate;	// NOTE: placeholder name
	char	pad91[0xa4 - 0x91];
	int		unknownA4;	// NOTE: placeholder name
	int		maxIntegrity;	// NOTE: placeholder name
	char	padac[0xb4 - 0xac];
	float	unknownB4;	// NOTE: placeholder name
	int		unknownB8;	// NOTE: placeholder name
	int		padbc;
	int		unknownC0;	// NOTE: placeholder name
	int		unknownC4;	// NOTE: placeholder name
	int		unknownC8;	// NOTE: placeholder name
	int		padcc;
	int		unknownD0;	// NOTE: placeholder name
	int		unknownD4;	// NOTE: placeholder name
};

class Item
{
public:
	int unknown457a70();	// NOTE: placeholder name (ascii-aware tile)
	int unknown457ab0();	// NOTE: placeholder name (slot ascii)
	bool unknown457ad0();	// NOTE: placeholder name (isAutoActivate?)
	int unknown457af0();	// NOTE: placeholder name
	int unknown457b30();	// NOTE: placeholder name
	HEntity unknown457b50();	// NOTE: placeholder name (owner)
	ItemEffect *getEffect(int type);	// NOTE: placeholder name
	int getEffectValue(int type);	// NOTE: placeholder name
	int unknown457c50(int type);	// NOTE: placeholder name
	int unknown457c80();	// NOTE: placeholder name (max integrity)
	int unknown457ca0();	// NOTE: placeholder name (integrity percent)
	int unknown457cd0();	// NOTE: placeholder name (damage taken)
	bool unknown457cf0();	// NOTE: placeholder name (isActive?)
	bool unknown457d10();	// NOTE: placeholder name
	bool unknown457d30();	// NOTE: placeholder name
	bool unknown457d50();	// NOTE: placeholder name
	bool unknown457d70();	// NOTE: placeholder name
	bool unknown457db0();	// NOTE: placeholder name
	float unknown457df0();	// NOTE: placeholder name
	int unknown457e10();	// NOTE: placeholder name
	bool unknown457e30();	// NOTE: placeholder name
	bool unknown457e70();	// NOTE: placeholder name
	bool unknown457e90();	// NOTE: placeholder name
	int unknown457ed0();	// NOTE: placeholder name
	int unknown457ef0();	// NOTE: placeholder name
	int unknown457f10();	// NOTE: placeholder name
	int unknown457f30();	// NOTE: placeholder name
	int unknown457f50();	// NOTE: placeholder name

	bool unknown415ee0();	// NOTE: placeholder name (returns unknown20; folded getter)

	int						unknown00;
	int						ID;
	ItemType				*type;
	int						unknown0c;
	HEntity					owner;	// NOTE: placeholder name
	char					pad14[0x1c - 0x14];
	int						integrity;	// NOTE: placeholder name
	bool					unknown20;	// NOTE: placeholder name
	char					pad21[3];
	int						unknown24;	// NOTE: placeholder name
	int						activeTurn;	// NOTE: placeholder name
	int						activateOkayTurn;	// NOTE: placeholder name
	char					pad30[0x38 - 0x30];
	int						unknown38;	// NOTE: placeholder name
	int						unknown3c;	// NOTE: placeholder name
	bool					overloaded;	// NOTE: placeholder name
	char					pad41[3];
	int						unknown44;	// NOTE: placeholder name
	vector<ItemEffect *>	effects;	// NOTE: placeholder name
	ItemEffectList			*unknown58;	// NOTE: placeholder name
};

int Item::unknown457a70()
{
	return !asciiEnabled ? type->tile : unknown_d01618[type->slot].ascii;
}

int Item::unknown457ab0()
{
	return unknown_d01618[type->slot].ascii;
}

bool Item::unknown457ad0()
{
	return type->autoActivate;
}

int Item::unknown457af0()
{
	return unknown38;
}

int Item::unknown457b30()
{
	return type->unknownA4;
}

HEntity Item::unknown457b50()
{
	return owner;
}

ItemEffect *Item::getEffect(int type)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i]->type->ID == type)
			return effects[i];
	}
	return NULL;
}

int Item::getEffectValue(int type)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i]->type->ID == type)
			return effects[i]->state;
	}
	return 0;
}

int Item::unknown457c50(int type)
{
	if (unknown58 != NULL)
		return unknown58->unknown456430(type);
	return 0;
}

int Item::unknown457c80()
{
	return type->maxIntegrity;
}

int Item::unknown457ca0()
{
	return integrity * 100 / type->maxIntegrity;
}

int Item::unknown457cd0()
{
	return type->maxIntegrity - integrity;
}

bool Item::unknown457cf0()
{
	return activeTurn != -1;
}

bool Item::unknown457d10()
{
	return activateOkayTurn < 0;
}

bool Item::unknown457d30()
{
	return activateOkayTurn == -2;
}

bool Item::unknown457d50()
{
	return activateOkayTurn == -1;
}

bool Item::unknown457d70()
{
	return !unknown415ee0() && !unknown457d10();
}

bool Item::unknown457db0()
{
	return unknown24;
}

float Item::unknown457df0()
{
	return type->unknownB4;
}

int Item::unknown457e10()
{
	return type->unknownB8;
}

bool Item::unknown457e30()
{
	return type->slot != 0 && type->slot != 3;
}

bool Item::unknown457e70()
{
	return type->slot >= 4;
}

bool Item::unknown457e90()
{
	return type->unknown70 == 2 || getEffect(0x6d) != NULL;
}

int Item::unknown457ed0()
{
	return type->unknownC0;
}

int Item::unknown457ef0()
{
	return type->unknownC4;
}

int Item::unknown457f10()
{
	return type->unknownC8;
}

int Item::unknown457f30()
{
	return type->unknownD0;
}

int Item::unknown457f50()
{
	return type->unknownD4;
}
