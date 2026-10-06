// Item header-inline accessors (0x457f70-0x4584ba) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members and names are placeholders.
#include <string>
#include <vector>
using namespace std;

int unknown_9d0690(int *value, int amount, int minimum);	// NOTE: placeholder name (subtract, clamped to minimum)
int unknown_9d06d0(int *value, int amount, int maximum);	// NOTE: placeholder name (add, clamped to maximum)

struct ItemEffect;

struct ItemType	// NOTE: placeholder name
{
	int unknown56f3c0();	// NOTE: placeholder name

	char pad00[0xa8];
	int maxIntegrity;	// NOTE: placeholder name
	char padac[0xc8 - 0xac];
	int unknownC8;	// NOTE: placeholder name
	char padcc[0xe8 - 0xcc];
	int unknownE8;	// NOTE: placeholder name
	int unknownEC;	// NOTE: placeholder name
	int ID;	// NOTE: placeholder name
	int unknownF4;	// NOTE: placeholder name
	int unknownF8;	// NOTE: placeholder name
	int padfc;
	int unknown100;	// NOTE: placeholder name
	int unknown104;	// NOTE: placeholder name
	char pad108[0x114 - 0x108];
	int unknown114;	// NOTE: placeholder name
	int unknown118;	// NOTE: placeholder name
	int unknown11C;	// NOTE: placeholder name
	char pad120[0x14c - 0x120];
	int unknown14C;	// NOTE: placeholder name
	char pad150[0x15c - 0x150];
	int unknown15C;	// NOTE: placeholder name
	int integrityLoss;	// NOTE: placeholder name (per shot of an unstable weapon)
};

class Item
{
public:
	int unknown457f70();	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
	int unknown457fd0();	// NOTE: placeholder name
	bool unknown457ff0();	// NOTE: placeholder name
	bool unknown458030();	// NOTE: placeholder name
	int unknown458080();	// NOTE: placeholder name
	int unknown4580a0();	// NOTE: placeholder name
	int unknown4580c0();	// NOTE: placeholder name
	int unknown4580e0();	// NOTE: placeholder name
	int unknown458100();	// NOTE: placeholder name
	int unknown458120();	// NOTE: placeholder name
	int unknown458140();	// NOTE: placeholder name
	int unknown458160();	// NOTE: placeholder name
	bool unknown458180();	// NOTE: placeholder name
	bool unknown458220();	// NOTE: placeholder name (isOverloaded?)
	int unknown458240();	// NOTE: placeholder name
	int unknown458260();	// NOTE: placeholder name (remaining shots of an unstable weapon)
	int unknown4582a0();	// NOTE: placeholder name
	void unknown4582d0(int ID_);	// NOTE: placeholder name (setID?)
	void unknown4582f0();	// NOTE: placeholder name
	int unknown458310(int amount);	// NOTE: placeholder name (damage, leaving at least 1)
	void unknown458340();	// NOTE: placeholder name (repair fully)
	int unknown458360(int amount);	// NOTE: placeholder name (repair)
	void unknown458390(bool flag);	// NOTE: placeholder name
	void setActivateOkayTurn(int turn);	// 0x4583b0
	void unknown458460();	// NOTE: placeholder name
	void unknown458480();	// NOTE: placeholder name
	void unknown4584a0();	// NOTE: placeholder name

	ItemEffect *getEffect(int type);	// NOTE: placeholder name (0x457b70)
	int unknown577a90();	// NOTE: placeholder name (turns active)

	int unknown00;
	int ID;
	ItemType *type;
	char pad0c[0x1c - 0x0c];
	int integrity;	// NOTE: placeholder name
	bool unknown20;	// NOTE: placeholder name
	char pad21[3];
	int unknown24;	// NOTE: placeholder name
	int activeTurn;	// NOTE: placeholder name
	int activateOkayTurn;	// NOTE: placeholder name
	char pad30[0x38 - 0x30];
	int unknown38;	// NOTE: placeholder name
	int unknown3c;	// NOTE: placeholder name
	bool overloaded;	// NOTE: placeholder name
	char pad41[3];
	int unknown44;	// NOTE: placeholder name
};

int Item::unknown457f70()
{
	return type->unknownE8;
}

int Item::unknown457f90()
{
	return type->ID;
}

int Item::unknown457fb0()
{
	return type->unknownF4;
}

int Item::unknown457fd0()
{
	return type->unknownF8;
}

bool Item::unknown457ff0()
{
	return type->ID == 8 || type->ID == 9;
}

bool Item::unknown458030()
{
	return unknown44 >= 0 && (type->ID == 0xd0 || getEffect(0x56) != NULL);
}

int Item::unknown458080()
{
	return type->unknown56f3c0();
}

int Item::unknown4580a0()
{
	return type->unknown100;
}

int Item::unknown4580c0()
{
	return type->unknown104;
}

int Item::unknown4580e0()
{
	return type->unknown114;
}

int Item::unknown458100()
{
	return type->unknown14C;
}

int Item::unknown458120()
{
	return type->unknown118;
}

int Item::unknown458140()
{
	return type->unknown11C;
}

int Item::unknown458160()
{
	return type->unknown15C;
}

bool Item::unknown458180()
{
	return type->unknownC8 > 0 || type->unknown15C > 0 || type->unknownE8 > 0 || type->unknownEC != 0 || type->ID == 0xa0 || type->ID == 0xa6 || type->ID == 0xd3;
}

bool Item::unknown458220()
{
	return overloaded;
}

int Item::unknown458240()
{
	return type->integrityLoss;
}

int Item::unknown458260()
{
	return integrity / type->integrityLoss + (integrity % type->integrityLoss != 0);
}

int Item::unknown4582a0()
{
	return type->unknownF4 - unknown577a90();
}

void Item::unknown4582d0(int ID_)
{
	ID = ID_;
}

void Item::unknown4582f0()
{
	activeTurn++;
}

int Item::unknown458310(int amount)
{
	return unknown_9d0690(&integrity,amount,1);
}

void Item::unknown458340()
{
	integrity = type->maxIntegrity;
}

int Item::unknown458360(int amount)
{
	return unknown_9d06d0(&integrity,amount,type->maxIntegrity);
}

void Item::unknown458390(bool flag)
{
	unknown20 = flag;
}

void Item::unknown458460()
{
	unknown24 = 0;
}

void Item::unknown458480()
{
	unknown38++;
}

void Item::unknown4584a0()
{
	unknown3c++;
}
