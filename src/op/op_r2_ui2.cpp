// op_r2: misc console helpers in 0x490000-0x4c0000, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

class HItem
{
public:
	int ID;
	bool isValid() const;
};

struct OpR2_PropData	// NOTE: placeholder name
{
	char pad00[0x80];
	int unknown80;
	int unknown84;
	int unknown88;
};

class OpR2_Prop	// NOTE: placeholder name (Prop)
{
public:
	OpR2_PropData *getData();	// NOTE: placeholder name (folded getter 0x45cb30)
};

class HProp
{
public:
	int ID;
	OpR2_Prop *operator->() const;	// 0x9b64f0
};

struct OpR2_Entry4afc40	// NOTE: placeholder name
{
	char pad00[0x70];
	int *unknown70;
	char pad74[0x80 - 0x74];
	string name;
};

struct OpR2_Entry4afe70	// NOTE: placeholder name
{
	char pad00[0x70];
	int unknown70;
	char pad74[0x80 - 0x74];
	string name;
};

struct OpR2_Target2	// NOTE: placeholder name
{
	char pad00[0x78];
	vector<OpR2_Entry4afe70*> entries;

	string unknown4afe70(int id);	// NOTE: placeholder name
};

struct OpR2_Target	// NOTE: placeholder name
{
	char pad00[0x70];
	HProp prop;
	int unknown74;
	vector<OpR2_Entry4afc40*> entries;
	char pad88[0x8c - 0x88];
	HItem item;

	OpR2_Entry4afc40 *unknown4afc40(int id);	// NOTE: placeholder name
	OpR2_Entry4afc40 *unknown4afce0();	// NOTE: placeholder name
	OpR2_Entry4afc40 *unknown4afd50();	// NOTE: placeholder name
	bool unknown4afdc0(int type);	// NOTE: placeholder name
};

extern int opr2_caf164;	// NOTE: placeholder name
extern int opr2_caf160;	// NOTE: placeholder name
extern vector<OpR2_Entry4afc40*> opr2_d2d1c4;	// NOTE: placeholder name
extern vector<OpR2_Entry4afc40*> opr2_d25de0;	// NOTE: placeholder name

OpR2_Entry4afc40 *OpR2_Target::unknown4afc40(int id)
{
	for (unsigned int i = 0; i < entries.size(); i++)
	{
		if (entries[i]->unknown70 && *entries[i]->unknown70 == id)
			return entries[i];
	}
	return NULL;
}

OpR2_Entry4afc40 *OpR2_Target::unknown4afce0()
{
	return prop->getData()->unknown80 == opr2_caf164 ? NULL : opr2_d2d1c4[prop->getData()->unknown80];
}

OpR2_Entry4afc40 *OpR2_Target::unknown4afd50()
{
	return prop->getData()->unknown88 == opr2_caf160 ? NULL : opr2_d25de0[prop->getData()->unknown88];
}

bool OpR2_Target::unknown4afdc0(int type)
{
	switch (type)
	{
	case 0x43:
		return !(prop->getData()->unknown80 == opr2_caf164 && prop->getData()->unknown88 == opr2_caf160);
	case 0x4d:
	case 0x5f:
		return item.isValid();
	}
	return true;
}

string OpR2_Target2::unknown4afe70(int id)
{
	for (unsigned int i = 0; i < entries.size(); i++)
	{
		if (entries[i]->unknown70 == id)
			return entries[i]->name;
	}
	return string();
}
