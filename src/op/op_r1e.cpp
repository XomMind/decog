// op_r1e: functions in 0x456a50-0x45f8c0 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
#include <math.h>
#include <ctype.h>
using namespace std;

struct OpQ5_T9e2c40;
template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name (0x9e2c40)

int OpR1e_applyOperation(int value, int operation, float amount, int minimum, int maximum)	// 0x456a50 NOTE: placeholder name
{
	int result;

	switch (operation)
	{
	case 0:
		result = (int)(value + amount);
		break;
	case 1:
		result = (int)(value - amount);
		break;
	case 2:
		result = (int)(value * amount);
		break;
	case 3:
		result = (int)(value / amount);
		break;
	case 5:
		result = minimum != -1 ? minimum : 0;
		break;
	case 6:
		result = maximum == -1 ? 9999 : maximum;
		break;
	case 4:
		if (value == amount)
		{
			return value;
		}
		else if (value < amount)
		{
			return OpR1e_applyOperation(value, 0, amount - value, minimum, maximum);
		}
		else
		{
			return OpR1e_applyOperation(value, 1, value - amount, minimum, maximum);
		}
		break;
	}

	if (minimum != -1 && result <= minimum)
	{
		return value < minimum ? result : minimum;
	}
	else if (maximum != -1 && result >= maximum)
	{
		return value > maximum ? result : maximum;
	}
	else
	{
		return result;
	}
}

float opR1b_noiseResult_4012b0(float v);	// NOTE: placeholder name

bool OpR1e_isAtLeast(float a, float b)	// 0x456bf0 NOTE: placeholder name
{
	return a > b || opR1b_noiseResult_4012b0(a - b) < 0.00005;
}

class OpR1e_Stats	// NOTE: placeholder name
{
public:
	int *getStatPtr(int index);	// 0x456da0 NOTE: placeholder name
};

int *OpR1e_Stats::getStatPtr(int index)
{
	switch (index)
	{
	case 0:
		return (int*)((char*)this + 0xa4);
	case 1:
		return (int*)((char*)this + 0xa8);
	case 2:
		return (int*)((char*)this + 0xac);
	case 3:
		return (int*)((char*)this + 0xb0);
	case 4:
		return (int*)((char*)this + 0xb4);
	case 5:
		return (int*)((char*)this + 0xb8);
	case 6:
		return (int*)((char*)this + 0xbc);
	case 7:
		return (int*)((char*)this + 0xc0);
	case 8:
		return (int*)((char*)this + 0xc8);
	case 9:
		return (int*)((char*)this + 0xcc);
	case 10:
		return (int*)((char*)this + 0xd8);
	case 11:
		return (int*)((char*)this + 0xdc);
	case 12:
		return (int*)((char*)this + 0xe0);
	case 13:
		return (int*)((char*)this + 0xe4);
	case 14:
		return (int*)((char*)this + 0xe8);
	case 15:
		return (int*)((char*)this + 0xec);
	case 16:
		return (int*)((char*)this + 0x100);
	case 17:
		return (int*)((char*)this + 0x104);
	case 18:
		return (int*)((char*)this + 0x108);
	case 19:
		return (int*)((char*)this + 0x10c);
	case 20:
		return (int*)((char*)this + 0x110);
	case 21:
		return (int*)((char*)this + 0x114);
	case 22:
		return (int*)((char*)this + 0x118);
	case 23:
		return (int*)((char*)this + 0x11c);
	case 24:
		return (int*)((char*)this + 0x120);
	case 25:
		return (int*)((char*)this + 0x124);
	case 26:
		return (int*)((char*)this + 0x12c);
	case 27:
		return (int*)((char*)this + 0x130);
	case 28:
		return (int*)((char*)this + 0x138);
	case 29:
		return (int*)((char*)this + 0x14c);
	case 30:
		return (int*)((char*)this + 0x150);
	case 31:
		return (int*)((char*)this + 0x15c);
	default:
		return NULL;
	}
}

extern string gameStrings_d02740[];

class OpR1e_Named	// NOTE: placeholder name
{
public:
	string getPrefixedName(int *length);	// 0x456fd0 NOTE: placeholder name

	char pad0[0x24];
	string name;	// NOTE: placeholder name
	int prefixIndex;	// NOTE: placeholder name
};

string OpR1e_Named::getPrefixedName(int *length)
{
	string result = name;

	if (prefixIndex != 0)
	{
		result.erase(0, 4);
		result.insert(0, gameStrings_d02740[prefixIndex]);

		if (length != NULL)
		{
			*length = gameStrings_d02740[prefixIndex].size();
		}
	}
	else if (length != NULL)
	{
		*length = 0;
	}

	return result;
}

extern bool opR1e_table_ba05d0[][0x1f];	// NOTE: placeholder name
extern bool opR1e_table_ba1268[][0x12];	// NOTE: placeholder name

class OpR1e_Flags	// NOTE: placeholder name
{
public:
	bool getFlag(int index);	// 0x4570c0 NOTE: placeholder name

	char pad0[0x40];
	int unknown40;	// NOTE: placeholder name
	int unknown44;	// NOTE: placeholder name
	char pad48[0xc];
	int unknown54;	// NOTE: placeholder name
	char pad58[0x98];
	int unknownf0;	// NOTE: placeholder name
};

bool OpR1e_Flags::getFlag(int index)
{
	if (index == 0x10)
	{
		return unknown54 == 3;
	}
	else if (index == 0x11)
	{
		return unknown40 == 0x1b;
	}
	else if (index <= 9)
	{
		return opR1e_table_ba05d0[index][unknown44];
	}
	else
	{
		return opR1e_table_ba1268[unknownf0][index];
	}
}

string intToString(int value);

class OpR1e_Unit	// NOTE: placeholder name
{
public:
	int getValue457430(int divisor);	// NOTE: placeholder name
	int getValue4574c0(int divisor, bool a, bool b);	// NOTE: placeholder name
	int getValue457550();	// NOTE: placeholder name
	int getValue457620();	// NOTE: placeholder name
	string getSuffix();	// NOTE: placeholder name

	char pad0[0x50];
	int unknown50;	// NOTE: placeholder name
	char pad54[0x40];
	int unknown94;	// NOTE: placeholder name
};

int OpR1e_Unit::getValue457430(int divisor)
{
	return (int)((unknown50 * 11 + 40) * (unknown94 != 0 ? 1.6 : 1.0) / (divisor ? divisor : 1));
}

int OpR1e_Unit::getValue4574c0(int divisor, bool a, bool b)
{
	return (int)((unknown50 * 6 + 20) * ((unknown94 != 0 ? 1.6 : 1.0) + (!a && !b ? 0.0 : 0.4)) / (divisor ? divisor : 1));
}

int OpR1e_Unit::getValue457550()
{
	return 100 - (5 + (unknown94 ? 3 : 0)) * unknown50;
}

int OpR1e_Unit::getValue457620()
{
	return 45 - (4 + (unknown94 ? 3 : 0)) * unknown50;
}

string OpR1e_Unit::getSuffix()
{
	string text;

	for (int i = 1; i <= 3; i++)
	{
		if (i != 1)
		{
			text += "/";
		}

		text += intToString(getValue457430(i));
	}

	return text;
}

//==================================================================
// Item
//==================================================================

class ItemEffectList	// NOTE: placeholder name
{
public:
	~ItemEffectList();
	bool unknown4567f0(int id, bool flag);	// NOTE: placeholder name

	vector<OpQ5_T9e2c40*> effects;	// NOTE: placeholder name
};

struct OpR1e_Slot	// NOTE: placeholder name
{
	int ascii;	// NOTE: placeholder name
	int color;	// NOTE: placeholder name
};
extern OpR1e_Slot opR1e_slots_d01618[];	// NOTE: placeholder name
extern bool asciiEnabled;	// NOTE: placeholder name (0xd28d30)

struct OpR1e_ItemType	// NOTE: placeholder name
{
	char pad0[0x24];
	string name;	// NOTE: placeholder name
	char pad40[4];
	int slot;	// NOTE: placeholder name
	char pad48[0x30];
	int ascii;	// NOTE: placeholder name
};

class Item
{
public:
	~Item();	// 0x457780
	string unknown457990();	// 0x457990 NOTE: placeholder name
	string unknown4579f0();	// 0x4579f0 NOTE: placeholder name
	int unknown457a30();	// 0x457a30 NOTE: placeholder name

	char pad0[8];
	OpR1e_ItemType *type;	// NOTE: placeholder name
	char padc[0x3c];

	vector<OpQ5_T9e2c40*> effects;	// NOTE: placeholder name
	ItemEffectList *unknown58;	// NOTE: placeholder name
	string unknown5c;	// NOTE: placeholder name
};

Item::~Item()
{
	OpQ5_clearObjects(effects);
	delete unknown58;
}

class OpR1e_Pages	// NOTE: placeholder name
{
public:
	int getPageCount();	// 0x457740 NOTE: placeholder name

	char pad0[0xa8];
	int total;	// NOTE: placeholder name
	char padac[0xb4];
	int perPage;	// NOTE: placeholder name
};

int OpR1e_Pages::getPageCount()
{
	return total / perPage + (total % perPage != 0);
}

string Item::unknown457990()
{
	return type->name;
}

string Item::unknown4579f0()
{
	return unknown5c;
}

int Item::unknown457a30()
{
	return asciiEnabled ? type->ascii : opR1e_slots_d01618[type->slot].ascii;
}

//==================================================================
// Record lists
//==================================================================

class HEntity
{
	int ID;
public:
	HEntity();
	bool operator==(HEntity other) const;
};

struct OpR1e_RecKey	// NOTE: placeholder name
{
	int ID;	// NOTE: placeholder name
	string name;	// NOTE: placeholder name
};

struct OpR1e_Rec	// NOTE: placeholder name
{
	OpR1e_RecKey *key;	// NOTE: placeholder name
	int value;	// NOTE: placeholder name
};

void opR1e_deleteAt_9d8f20(vector<OpR1e_Rec*> &v, int index);	// NOTE: placeholder name

class OpR1e_RecLists	// NOTE: placeholder name
{
public:
	int getValue457330(int ID);	// 0x457330 NOTE: placeholder name
	OpR1e_Rec *getRec4573a0(int ID);	// 0x4573a0 NOTE: placeholder name
	HEntity *getEntity459570(HEntity entity);
	void removeByName45b440(const string &name);	// NOTE: placeholder name
	void removeEffects45b4c0(int id, bool flag);	// NOTE: placeholder name	// 0x459570 NOTE: placeholder name

	char pad0[0xdc];
	vector<OpR1e_Rec*> listDC;	// NOTE: placeholder name
	ItemEffectList *effectsEC;	// NOTE: placeholder name
	vector<HEntity*> listF0;	// NOTE: placeholder name
	char pad100[0xd0];
	vector<OpR1e_Rec*> list1d0;	// NOTE: placeholder name
};

int OpR1e_RecLists::getValue457330(int ID)
{
	for (unsigned int i = 0; i < list1d0.size(); i++)
	{
		if (list1d0[i]->key->ID == ID)
		{
			return list1d0[i]->value;
		}
	}

	return 0;
}

OpR1e_Rec *OpR1e_RecLists::getRec4573a0(int ID)
{
	for (unsigned int i = 0; i < list1d0.size(); i++)
	{
		if (list1d0[i]->key->ID == ID)
		{
			return list1d0[i];
		}
	}

	return NULL;
}

HEntity *OpR1e_RecLists::getEntity459570(HEntity entity)
{
	for (unsigned int i = 0; i < listF0.size(); i++)
	{
		if (*listF0[i] == entity)
		{
			return listF0[i];
		}
	}

	return NULL;
}

//==================================================================
// OpR1e_Variant
//==================================================================

extern string robotClassNames_d2f798[];
string intToString(int value);

template <class T> T sumArray(const T *values, unsigned int count) throw();	// NOTE: placeholder name (0x9d0ca0)
extern string gameStrings_d2b4f8[];
extern int opw8_caf2b8[];	// NOTE: placeholder name
char opw8_randomChar(const string &chars);	// NOTE: placeholder name (0x4085b0)


struct OpR1e_Elem	// NOTE: placeholder name (vector of record pointers)
{
	char pad[0x10];
};

class OpR1e_Variant	// NOTE: placeholder name
{
public:
	int getValue459840(int divisor);	// NOTE: placeholder name
	string getName4598f0();	// NOTE: placeholder name
	string getName459a40();	// NOTE: placeholder name
	string getName459c30();	// NOTE: placeholder name
	int getChar459ca0();	// NOTE: placeholder name
	void appendCode459d00(string &code);	// NOTE: placeholder name
	string getSuffix459e00();	// NOTE: placeholder name

	int unknown0;	// NOTE: placeholder name
	string unknown4;	// NOTE: placeholder name
	bool unknown20;	// NOTE: placeholder name
	char pad21[3];
	int kind;	// NOTE: placeholder name
	int index;	// NOTE: placeholder name
	string unknown2c;	// NOTE: placeholder name
	int unknown48;	// NOTE: placeholder name
	string unknown4c;	// NOTE: placeholder name
	int unknown68;	// NOTE: placeholder name
	char pad6c[0x98 - 0x6c];
	int unknown98;	// NOTE: placeholder name
	char pad9c[0xc4 - 0x9c];
	vector<OpQ5_T9e2c40*> records;	// NOTE: placeholder name
	vector<unsigned int> unknownd4;	// NOTE: placeholder name
	char pade4[0x18];
	vector<unsigned int> unknownfc;	// NOTE: placeholder name
	char pad10c[0x3c];
	vector<unsigned int> unknown148;	// NOTE: placeholder name
	char pad158[8];
	vector<OpR1e_Elem> unknown160;	// NOTE: placeholder name
	string unknown170;	// NOTE: placeholder name
	string unknown18c;	// NOTE: placeholder name
	char pad1a8[4];
	string unknown1ac;	// NOTE: placeholder name
};

int OpR1e_Variant::getValue459840(int divisor)
{
	return (int)((unknown68 * 11 + 40) * 1.6 / (divisor ? divisor : 1));
}

string OpR1e_Variant::getName4598f0()
{
	if (unknown20 && kind == 3)
	{
		return unknown1ac + " (Tier " + intToString(unknown68) + ")";
	}
	else
	{
		return unknown1ac;
	}
}

string OpR1e_Variant::getName459a40()
{
	string name;

	switch (kind)
	{
	case 0:
		name = unknown2c.empty() ? string("Special") : unknown2c;
		break;
	case 1:
	case 2:
	case 3:
		name = unknown2c.empty() ? robotClassNames_d2f798[index] : unknown2c;

		if (kind == 2)
		{
			name += " (Prototype)";
		}
		else if (kind == 3)
		{
			name += " (Derelict)";
		}

		break;
	}

	return name;
}

string OpR1e_Variant::getName459c30()
{
	if (unknown48 >= 0x79)
	{
		return unknown1ac;
	}
	else
	{
		return gameStrings_d2b4f8[unknown48];
	}
}

int OpR1e_Variant::getChar459ca0()
{
	return unknown98 >= 3 && isalpha(opw8_caf2b8[index]) ? opw8_caf2b8[index] - 0x20 : opw8_caf2b8[index];
}

void OpR1e_Variant::appendCode459d00(string &code)
{
	string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

	for (int i = 0; i < 5; i++)
	{
		code += opw8_randomChar(chars);
	}

	code.insert(code.begin() + 2, '-');
	code += "(";
	code += (char)getChar459ca0();
	code += ")";
}

string OpR1e_Variant::getSuffix459e00()
{
	string text;

	for (int i = 1; i <= 3; i++)
	{
		if (i != 1)
		{
			text += "/";
		}

		text += intToString(getValue459840(i));
	}

	return text;
}

class OpR1e_Totals	// NOTE: placeholder name
{
public:
	int getTotal459ef0();	// NOTE: placeholder name

	int v[0x8c + 0x30];	// NOTE: placeholder name
};

int OpR1e_Totals::getTotal459ef0()
{
	return v[0x68 / 4] + v[0x6c / 4] + v[0x70 / 4] + v[0x7c / 4] + v[0x9c / 4] + v[0xa4 / 4] + v[0xac / 4] + v[0xb0 / 4] + v[0xb4 / 4] + v[0xb8 / 4]
		+ v[0xe4 / 4] + v[0xe8 / 4] + v[0xec / 4] + v[0xf0 / 4] + v[0xf4 / 4] + v[0x1c8 / 4]
		+ sumArray(&v[0x1cc / 4], 4)
		+ v[0x1dc / 4] + v[0x1e4 / 4] + v[0x1e8 / 4] + v[0x1ec / 4] + v[0x1f0 / 4]
		+ sumArray(&v[0x1f4 / 4], 7)
		+ v[0x214 / 4] + v[0x21c / 4] + v[0x220 / 4] + v[0x224 / 4] + v[0x228 / 4];
}

//==================================================================
// Handle readers
//==================================================================

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name (0x9d8480)

class HProp
{
	int ID;
public:
	HProp();
	void read9cfaf0(istream &stream);	// NOTE: placeholder name (0x9cfaf0)
};

class OpR1e_PropRef	// NOTE: placeholder name
{
public:
	OpR1e_PropRef(istream &stream);	// 0x45a070

	HProp prop;	// NOTE: placeholder name
	int value;	// NOTE: placeholder name
};

OpR1e_PropRef::OpR1e_PropRef(istream &stream)
{
	prop.read9cfaf0(stream);
	readBinary(stream, &value);
}

class OpR1e_Triple	// NOTE: placeholder name
{
public:
	OpR1e_Triple(istream &stream);	// 0x4596a0

	int a;	// NOTE: placeholder name
	int b;	// NOTE: placeholder name
	int c;	// NOTE: placeholder name
};

OpR1e_Triple::OpR1e_Triple(istream &stream)
{
	readBinary(stream, &a);
	readBinary(stream, &b);
	readBinary(stream, &c);
}

void OpR1e_RecLists::removeByName45b440(const string &name)
{
	for (unsigned int i = 0; i < listDC.size(); i++)
	{
		if (listDC[i]->key->name == name)
		{
			opR1e_deleteAt_9d8f20(listDC, i);
			return;
		}
	}
}

void OpR1e_RecLists::removeEffects45b4c0(int id, bool flag)
{
	if (effectsEC != NULL && effectsEC->unknown4567f0(id, flag))
	{
		delete effectsEC;	effectsEC = NULL;
	}
}

//==================================================================
// OpR1e_Block
//==================================================================

struct OpQ5_T9d1050;
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name (0x9d1050)
void OpQ1_readString(istream &in, string *text);	// NOTE: placeholder name (0x4096f0)
void opr2_readText_436960(istream &stream, string *value);	// NOTE: placeholder name (0x436960)

class OpR1e_Block	// NOTE: placeholder name
{
public:
	OpR1e_Block(istream &stream);	// 0x45b740

	int unknown0;	// NOTE: placeholder name
	string unknown4;	// NOTE: placeholder name
	int unknown20;	// NOTE: placeholder name
	int unknown24;	// NOTE: placeholder name
	int unknown28;	// NOTE: placeholder name
	int unknown2c;	// NOTE: placeholder name
	int unknown30;	// NOTE: placeholder name
	int unknown34;	// NOTE: placeholder name
	int unknown38;	// NOTE: placeholder name
	string unknown3c;	// NOTE: placeholder name
	string unknown58;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	string unknown78;	// NOTE: placeholder name
	string unknown94;	// NOTE: placeholder name
	vector<OpQ5_T9d1050*> unknownb0;	// NOTE: placeholder name
};

OpR1e_Block::OpR1e_Block(istream &stream)
{
	readBinary(stream, &unknown0);
	OpQ1_readString(stream, &unknown4);
	readBinary(stream, &unknown20);
	readBinary(stream, &unknown24);
	readBinary(stream, &unknown28);
	readBinary(stream, &unknown2c);
	readBinary(stream, &unknown30);
	readBinary(stream, &unknown34);
	readBinary(stream, &unknown38);
	opr2_readText_436960(stream, &unknown3c);
	opr2_readText_436960(stream, &unknown58);
	readBinary(stream, &unknown74);
	opr2_readText_436960(stream, &unknown78);
	opr2_readText_436960(stream, &unknown94);
	OpQ5_readObjects(stream, unknownb0, 0);
}

class OpR1e_Match	// NOTE: placeholder name
{
public:
	bool matches45b980(int a, int b);	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
	int value;	// NOTE: placeholder name
};

bool OpR1e_Match::matches45b980(int a, int b)
{
	return type == 5 ? type == a : (type == a && value == b);
}

//==================================================================
// OpR1e_Spawner
//==================================================================

class OpY1_ShuffleBag
{
public:
	int mode;
	int blanks;
	vector<int> items;
	vector<int> deck;

	OpY1_ShuffleBag(const vector<int> &items_, int blanks_, int mode_);
};

extern int opr4a_caf164;	// NOTE: placeholder name
extern int opw2_caf160;	// NOTE: placeholder name

class OpR1e_Spawner	// NOTE: placeholder name
{
public:
	OpR1e_Spawner(int a_, int b_, int c_, int d_, bool e_);	// 0x45ba00

	int a;	// NOTE: placeholder name
	int b;	// NOTE: placeholder name
	int c;	// NOTE: placeholder name
	int d;	// NOTE: placeholder name
	bool e;	// NOTE: placeholder name
	bool unknown11;	// NOTE: placeholder name
	OpY1_ShuffleBag *bag;	// NOTE: placeholder name
	vector<unsigned int> unknown18;	// NOTE: placeholder name
	int unknown28;	// NOTE: placeholder name
	int unknown2c;	// NOTE: placeholder name
	bool unknown30;	// NOTE: placeholder name
	int unknown34;	// NOTE: placeholder name
	int unknown38;	// NOTE: placeholder name
	int unknown3c;	// NOTE: placeholder name
	vector<unsigned int> unknown40;	// NOTE: placeholder name
	vector<unsigned int> unknown50;	// NOTE: placeholder name
	vector<unsigned int> unknown60;	// NOTE: placeholder name
	HProp unknown70;	// NOTE: placeholder name
	bool unknown74;	// NOTE: placeholder name
	int unknown78;	// NOTE: placeholder name
	int unknown7c;	// NOTE: placeholder name
	int unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
	int unknown8c;	// NOTE: placeholder name
};

OpR1e_Spawner::OpR1e_Spawner(int a_, int b_, int c_, int d_, bool e_)
	: a					(a_)
	, b					(b_)
	, c					(c_)
	, d					(d_)
	, e					(e_)
	, unknown11			(false)
	, unknown28			(0)
	, unknown2c			(0)
	, unknown30			(false)
	, unknown34			(0)
	, unknown38			(0)
	, unknown3c			(0)
	, unknown74			(false)
	, unknown78			(0)
	, unknown7c			(0)
	, unknown80			(opr4a_caf164)
	, unknown84			(opr4a_caf164)
	, unknown88			(opw2_caf160)
	, unknown8c			(opw2_caf160)
{
	vector<int> items;

	for (int i = 0; i < 20; i++)
	{
		items.push_back(i * 5);
	}

	bag = new OpY1_ShuffleBag(items, 1, 1);
}
