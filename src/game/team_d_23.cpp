// team_d_23: Item state copy (0x57c230).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
// The two constructors used by the new-expressions are defined here with placeholder bodies so that
// LTCG can prove they cannot throw, as in the exe (no exception states, but the new-expression
// result temporaries remain).
#include <vector>
#include <string>
using namespace std;

struct ItemEffect	// NOTE: placeholder name (8 bytes; copy constructor folded with Point's, 0x46ca50)
{
	int a;
	int b;

	ItemEffect(const ItemEffect &other);
};

ItemEffect::ItemEffect(const ItemEffect &other)	// NOTE: placeholder body
{
	a = other.a;
	b = other.b;
}

class ItemEffectList	// NOTE: placeholder name (0x14 bytes)
{
public:
	ItemEffectList();							// 0x456260
	~ItemEffectList();
	void copyFrom(ItemEffectList *other);		// NOTE: placeholder name (C065_Rec518b70::copyFrom)

	int pad[5];
};

ItemEffectList::ItemEffectList()	// NOTE: placeholder body
{
	pad[0] = 0;
}

class HItem
{
	int	ID;
};

class Map
{
public:
	void unknown464f60(HItem item);	// NOTE: placeholder name
	void unknown464fd0(HItem item);	// NOTE: placeholder name
};
extern Map *world;

template <class T> void OpQ5_clearObjects(vector<T *> &v);	// NOTE: placeholder name

class Item	// NOTE: placeholder layout
{
public:
	void addEffect(ItemEffect *effect);
	void unknown57c230(Item *other);	// NOTE: placeholder name

	int				unknown00;	// NOTE: placeholder name
	HItem			handle;		// +4, NOTE: placeholder name
	char			pad08[0x1c - 0x08];
	int				unknown1c;	// NOTE: placeholder name
	bool			unknown20;	// NOTE: placeholder name
	int				unknown24;	// NOTE: placeholder name
	int				unknown28;	// NOTE: placeholder name
	int				unknown2c;	// NOTE: placeholder name
	int				unknown30;	// NOTE: placeholder name
	int				unknown34;	// NOTE: placeholder name
	char			pad38[0x40 - 0x38];
	bool			unknown40;	// NOTE: placeholder name
	int				unknown44;	// NOTE: placeholder name
	vector<ItemEffect *> effects;	// +0x48, NOTE: placeholder name
	ItemEffectList	*effectList;	// +0x58, NOTE: placeholder name
	string			unknown5c;	// NOTE: placeholder name
};

void Item::unknown57c230(Item *other)
{
	unknown1c = other->unknown1c;
	unknown20 = other->unknown20;
	unknown24 = other->unknown24;
	unknown28 = other->unknown28;
	unknown2c = other->unknown2c;
	unknown30 = other->unknown30;
	unknown34 = other->unknown34;
	unknown40 = other->unknown40;
	unknown44 = other->unknown44;
	OpQ5_clearObjects(effects);
	for (unsigned int i = 0; i < other->effects.size(); i++)
		addEffect(new ItemEffect(*other->effects[i]));
	world->unknown464fd0(handle);
	delete effectList;
	effectList = NULL;
	if (other->effectList)
	{
		effectList = new ItemEffectList;
		effectList->copyFrom(other->effectList);
		world->unknown464f60(handle);
	}
	unknown5c = other->unknown5c;
}
