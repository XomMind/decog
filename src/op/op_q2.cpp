// op_q2: assorted functions in 0x516000-0x6c0000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

string intToString(int value);

//==================================================================
// lore entries
//==================================================================

struct OpQ2_LoreSource	// NOTE: placeholder name
{
	int unknown0;
	string name;
	int unknown20;
	int type;
};

struct OpQ2_LoreDialogue	// NOTE: placeholder name
{
	char pad0[0x24];
	int type;
	int speaker;
};

struct OpQ2_LoreRecord	// NOTE: placeholder name
{
	char pad0[0x24];
	int type;
	char pad28[0x1ac - 0x28];
	string name;
};

extern string gameStrings_d38648[];
extern vector<string> opQ2_loreTypes;	// NOTE: placeholder name (0xd1d9b0)
extern vector<string> opQ2_speakers;	// NOTE: placeholder name (0xd2283c)

struct OpQ2_LoreEntry	// NOTE: placeholder name
{
	string getTypeLabel();	// NOTE: placeholder name
	string getName();	// NOTE: placeholder name

	int unknown0;
	bool known;
	OpQ2_LoreSource *source;
	OpQ2_LoreDialogue *dialogue;
	int number;
	OpQ2_LoreRecord *record;
};

string OpQ2_LoreEntry::getTypeLabel()
{
	return record ? gameStrings_d38648[record->type] + " Analyses" : source ? opQ2_loreTypes[source->type] + " Records" : opQ2_loreTypes[dialogue->type] + " Dialogue";
}

string OpQ2_LoreEntry::getName()
{
	return source ? source->name : (dialogue ? intToString(number) + (dialogue->speaker == -1 ? "" : " (" + opQ2_speakers[dialogue->speaker] + ")") : record->name);
}

//==================================================================
// Item queries
//==================================================================

float maxf(float a, float b);

class HItem
{
public:
	int ID;
	bool isValid() const;
};

class Entity
{
public:
	bool isPlayer();
	int unknown5cb220();	// NOTE: placeholder name
	int unknown5cad50();	// NOTE: placeholder name
	int unknown5d22a0(int type);	// NOTE: placeholder name
	int unknown5d2150(int type, int a);	// NOTE: placeholder name
	HItem unknown5d2380(int type);	// NOTE: placeholder name
};
class Map
{
public:
	int getTurn();	// 0x464270
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)

class HEntity
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const throw();	// 0x9b6570
};

struct OpQ2_ItemRecord	// NOTE: placeholder layout
{
	int unknown0;
	char pad04[0x24 - 0x4];
	string unknown24;
	int unknown40;
	int unknown44;
	int unknown48;
	int unknown4C;
	int unknown50;
	int unknown54;
	char pad58[0x94 - 0x58];
	int unknown94;
	char pad98[0xa0 - 0x98];
	int unknownA0;
	char padA4[0xa8 - 0xa4];
	int integrityMax;
	int unknownAC;
	int unknownB0;
	char padB4[0xbc - 0xb4];
	int unknownBC;
	char padC0[0xcc - 0xc0];
	int unknownCC;
	char padD0[0xd8 - 0xd0];
	float unknownD8;
	int unknownDC;
	int unknownE0;
	int unknownE4;
	int unknownE8;
	int unknownEC;
	int unknownF0;
	char padF4[0x108 - 0xf4];
	int unknown108;
	int unknown10C;
	int unknown110;
	char pad114[0x130 - 0x114];
	int unknown130;
	char pad134[0x165 - 0x134];
	bool unknown165;
	char pad166[0x1ac - 0x166];
	bool unknown1AC;
	bool unknown1AD;
	char pad1AE[0x20b - 0x1ae];
	bool unknown20B;
};

extern bool opw8_d28d26;	// NOTE: placeholder name
extern int opw8_d35be0;	// NOTE: placeholder name
extern int opw8_d25e0c;	// NOTE: placeholder name
extern int opw8_cf281c;	// NOTE: placeholder name
extern int opw8_d2b284;	// NOTE: placeholder name
extern int opw8_d23094;	// NOTE: placeholder name
extern int opw8_d2f34c;	// NOTE: placeholder name
extern bool opQ2_table_ba034c[];	// NOTE: placeholder name
extern bool opw8_table_ba0968[];	// NOTE: placeholder name
extern int opQ2_table_ba0970[];	// NOTE: placeholder name
class CParts
{
public:
	bool isLinked4a9b10(HItem item);	// NOTE: placeholder name
};
extern CParts *opQ2_parts;	// NOTE: placeholder name (0xcec088)
extern int opw8_cefb38;	// NOTE: placeholder name
extern vector<int> opQ2_cf4830;	// NOTE: placeholder name
extern vector<int> opQ2_cf4844;	// NOTE: placeholder name
extern vector<int> opQ2_cf48cc;	// NOTE: placeholder name
extern OpQ2_ItemRecord *opw8_cefbe8;
const float opQ2_float2 = 2.0f;	// NOTE: placeholder name (0xb960b4)
const float opQ2_float2b = 2.0f;	// NOTE: placeholder name (0xb960b0)
const float opQ2_floatB96584 = 2.0f;	// NOTE: placeholder name
const float opQ2_floatB96588 = 3.0f;	// NOTE: placeholder name
const float opQ2_float05 = 0.5f;	// NOTE: placeholder name (0xba09d8)
const float opQ2_floatB960A0 = 2.0f;	// NOTE: placeholder name
const float opQ2_floatB960A4 = 3.0f;	// NOTE: placeholder name
const float opQ2_floatB960A8 = 1.5f;	// NOTE: placeholder name
const float opQ2_floatB960AC = 0.5f;	// NOTE: placeholder name	// NOTE: placeholder name

class Item
{
public:
	int unknown577260();	// NOTE: placeholder name
	int unknown577350();	// NOTE: placeholder name
	bool unknown577530();	// NOTE: placeholder name
	bool unknown5775a0();	// NOTE: placeholder name
	int unknown577600(int percent);	// NOTE: placeholder name
	bool unknown577640();	// NOTE: placeholder name
	bool unknown5776c0();	// NOTE: placeholder name
	bool unknown577700();	// NOTE: placeholder name
	int unknown577b10();
	int unknown577bd0();	// NOTE: placeholder name
	int unknown577c90();	// NOTE: placeholder name
	float unknown577d80();	// NOTE: placeholder name
	int unknown577df0();	// NOTE: placeholder name
	int unknown577e60();	// NOTE: placeholder name
	int unknown577f30();	// NOTE: placeholder name
	int unknown577fb0();	// NOTE: placeholder name
	int unknown577790();	// NOTE: placeholder name
	bool unknown578830();	// NOTE: placeholder name
	int unknown5788e0();	// NOTE: placeholder name
	int unknown5789c0();	// NOTE: placeholder name
	int unknown578a70();	// NOTE: placeholder name
	int unknown578b10();	// NOTE: placeholder name
	bool unknown5773d0(bool a, bool b);	// NOTE: placeholder name
	int unknown457ca0();	// NOTE: placeholder name
	bool unknown457db0();	// NOTE: placeholder name
	int unknown577fd0();	// NOTE: placeholder name	// NOTE: placeholder name
	bool unknown577b80();	// NOTE: placeholder name
	int getEffectValue(int type);	// NOTE: placeholder name (0x457be0)
	void *getEffect(int type);	// 0x457b70
	int unknown44aec0();	// NOTE: placeholder name (ICF'd trivial getter)
	bool unknown415ee0();	// NOTE: placeholder name (ICF'd trivial getter)
	bool unknown457d10();	// NOTE: placeholder name
	int unknown457cd0();	// NOTE: placeholder name
	bool unknown458030();	// NOTE: placeholder name
	bool unknown577940();	// NOTE: placeholder name
	bool unknown577990();	// NOTE: placeholder name
	int unknown5779f0();	// NOTE: placeholder name
	int unknown577a90();	// NOTE: placeholder name

	int unknown0;
	HItem handle;
	OpQ2_ItemRecord *record;
	int unknownC;
	HEntity owner;
	int unknown14;
	int unknown18;
	int integrity;
	int unknown20;
	int unknown24;
	int unknown28;
	char pad2C[0x40 - 0x2c];
	bool unknown40;
	char pad41[0x44 - 0x41];
	int unknown44;
};

int Item::unknown577260()
{
	if (integrity == -1)
	{
		int ret = opw8_d28d26 ? opw8_d35be0 : opw8_d25e0c;
		return ret;
	}
	float ratio = (float)integrity / record->integrityMax;
	if (ratio >= 0.75)
	{
		int high = opw8_d28d26 ? opw8_d35be0 : opw8_d25e0c;
		return high;
	}
	else if (ratio >= 0.4)
		return opw8_cf281c;
	else if (ratio >= 0.2)
	{
		int low = opw8_d28d26 ? opw8_d2b284 : opw8_d23094;
		return low;
	}
	else
		return opw8_d2f34c;
}

int Item::unknown577350()
{
	if (integrity == -1)
		return 0;
	float ratio = (float)integrity / record->integrityMax;
	if (ratio >= 0.75)
		return 0;
	else if (ratio >= 0.4)
		return 1;
	else if (ratio >= 0.2)
		return 2;
	else
		return 3;
}

bool Item::unknown577530()
{
	return record->unknown44 >= 6 && (record->unknown50 <= 8 || record->unknown94 == 0) && record->unknownA0 == 0 && record->unknown94 != 3;
}

bool Item::unknown5775a0()
{
	return unknown44aec0() == 4 && record->unknown44 >= 6 && opQ2_cf4830[record->unknown0] != 0;
}

int Item::unknown577600(int percent)
{
	return (int)(integrity / (double)record->integrityMax * (percent / 100.0) * (integrity * opQ2_float05));
}

bool Item::unknown577640()
{
	return unknown44aec0() == 4 && record->unknown44 >= 6 && record->unknown54 != 0 && record->unknownA0 == 0 && opQ2_cf4844[record->unknown0] == 0 && record->unknown94 != 3;
}

bool Item::unknown5776c0()
{
	return unknown44aec0() == 4 && record->unknown44 >= 6;
}

bool Item::unknown577700()
{
	return record->unknown44 >= 6 && record->unknown48 != 2 && (record->unknown54 == 1 || record->unknown54 == 2) && opQ2_cf48cc[record->unknown0] == 0 && record->unknown94 == 0 && !record->unknown20B;
}

bool Item::unknown577940()
{
	return getEffectValue(0x76) != 0 && getEffectValue(0x77) < getEffectValue(0x76);
}

bool Item::unknown577990()
{
	return !unknown415ee0() && !unknown457d10() && !getEffect(0x56) && record->unknown1AD;
}

int Item::unknown5779f0()
{
	return unknown458030() ? 1 : unknown415ee0() ? 2 : unknown457d10() ? 3 : getEffect(0x56) ? 4 : unknown24 ? 5 : 0;
}

int Item::unknown577a90()
{
	return unknown28 == -1 ? 0 : world->getTurn() - unknown28;
}

bool Item::unknown577b80()
{
	return record->unknown44 >= 6 && unknown457cd0() > 0 && unknownC == 5 && record != opw8_cefbe8;
}

int Item::unknown577b10()
{
	return (int)(unknown40 && owner.operator->() && record->unknown48 == 0 ? record->unknownB0 * opQ2_float2 : record->unknownB0);
}

int Item::unknown577bd0()
{
	int value = record->unknownBC;
	if (value == 0)
		return 0;
	if (opQ2_cf48cc[record->unknown0] != 0 && (!owner.operator->() || owner->isPlayer()))
		value += opQ2_table_ba034c[record->unknown40] ? 1 : 2;
	return (int)(unknown40 && owner.operator->() ? value * opQ2_float2b : value);
}

int Item::unknown577c90()
{
	int value = record->unknownCC;
	if (opQ2_cf48cc[record->unknown0] != 0 && (record->unknown44 == 10 || record->unknown44 == 11) && (!owner.operator->() || owner->isPlayer()))
		value += (record->unknown44 == 10 ? -15 : -10);
	return (int)(unknown40 && owner.operator->() && record->unknown44 == 10 && record->unknownE8 != 0 ? value * opQ2_floatB960AC : value);
}

float Item::unknown577d80()
{
	return unknown40 && owner.operator->() && record->unknown44 >= 12 ? record->unknownD8 * opQ2_floatB960A0 : record->unknownD8;
}

int Item::unknown577df0()
{
	return (int)(unknown40 && owner.operator->() && record->unknown44 >= 12 ? record->unknownDC * opQ2_floatB960A4 : record->unknownDC);
}

int Item::unknown577e60()
{
	int value = record->unknownE0;
	if (value == 0)
		return 0;
	if (opQ2_cf48cc[record->unknown0] != 0 && record->unknown44 >= 12 && (!owner.operator->() || owner->isPlayer()))
		value += record->unknown4C;
	return (int)(unknown40 && owner.operator->() && record->unknown44 >= 12 ? value * opQ2_floatB960A8 : value);
}

int Item::unknown577f30()
{
	int value = record->unknownE4;
	if (opQ2_cf48cc[record->unknown0] != 0 && record->unknown44 == 9 && (!owner.operator->() || owner->isPlayer()))
		value /= 2;
	return value;
}

int Item::unknown577fd0()
{
	return opw8_table_ba0968[record->unknownEC] ? (owner.isValid() ? owner->unknown5cb220() : opQ2_table_ba0970[record->unknownEC]) - (unknown44 - 1) : opQ2_table_ba0970[record->unknownEC] - (unknown44 - 1);
}

int Item::unknown577790()
{
	if (getEffect(0x52))
		return 0;
	if (owner.isValid())
	{
		if (record->unknown48 == 3)
		{
			if (owner->unknown5d2380(0x5e).isValid())
				return record->unknownAC * record->unknown4C * 2;
		}
		else if (record->unknown44 == 0x12 && owner->unknown5d2380(0x3e).isValid())
			return record->unknownAC * record->unknown4C * owner->unknown5d22a0(0x3e);
		else if ((record->unknown44 == 0x12 || record->unknown44 == 9 && record->unknown4C >= 2) && owner->unknown5cad50() == 2 && opw8_table_ba0968[opw8_cefb38])
			return record->unknownAC * record->unknown4C * 2;
		else if (record->unknownEC == 4 && unknown577fb0() == 2)
			return record->unknownAC * record->unknown4C * 2;
	}
	return record->unknownAC * record->unknown4C;
}

bool Item::unknown5773d0(bool a, bool b)
{
	return record->unknown44 >= 6 && (record->unknown50 <= 8 || record->unknown94 == 0) && record->unknown54 >= 1 && record->unknownA0 == 0 && (b || !record->unknown1AC && !getEffect(0x6e) && !getEffect(0x6c) || unknownC == 4) && (b || !unknown577fb0()) && (b || !a || opQ2_cf4830[record->unknown0] != 0) && record->unknown94 != 3 && record->unknown94 != 2 && (b || unknown457ca0() < 100 || unknown457d10() || unknown457db0()) && !opQ2_parts->isLinked4a9b10(handle);
}

bool Item::unknown578830()
{
	return record->unknownF0 == 0x7c && (record->unknown24.find("Swarmer") != string::npos || record->unknown24.find("Grunt") != string::npos || record->unknown24.find("Brawler") != string::npos || record->unknown24.find("Duelist") != string::npos);
}

int Item::unknown5788e0()
{
	if (record->unknown108 != 0)
		return (int)maxf(1.0f,(unknown40 && owner.operator->() ? record->unknown108 * opQ2_floatB96584 : record->unknown108) * (owner.operator->() && !record->unknown165 ? (100 - owner->unknown5d2150(0x65,0)) / 100.0 : 1.0));
	else
		return 0;
}

int Item::unknown5789c0()
{
	return (int)(owner.operator->() ? (record->unknown10C ? maxf(1.0f,record->unknown10C * ((100 - owner->unknown5d2150(0x64,0)) / 100.0)) : 0.0f) : (float)record->unknown10C);
}

int Item::unknown578a70()
{
	return (int)(unknown40 && owner.operator->() ? record->unknown110 * (1.0 + (opQ2_floatB96588 - 1.0) * (1.0 - owner->unknown5d22a0(0x6f) / 100.0)) : record->unknown110);
}

int Item::unknown578b10()
{
	int value = record->unknown130;
	if (opQ2_cf48cc[record->unknown0] != 0 && (!owner.operator->() || owner->isPlayer()))
		value += 10;
	return value;
}
