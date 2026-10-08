// alpha2_05: Item::getName (0x571db0): display name of an item with prefixes and status suffixes.
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <string>
#include <vector>
using std::string;

struct A2NEntity
{
	bool player_5c7600() throw();
};
struct A2NHE	// HEntity
{
	int id;
	A2NEntity *get_9b6570() const throw();
};
struct A2NRecord
{
	char pad0[0x1b4];
	string name;	// +0x1b4
};
struct A2NItemDef
{
	int id;	// +0x00
	char pad4[0x24 - 0x04];
	string name;	// +0x24
	char pad40[0x44 - 0x40];
	int rarity;	// +0x44
	char pad48[0x94 - 0x48];
	int origin;	// +0x94
	char pad98[0xf0 - 0x98];
	int type;	// +0xf0
};

extern int a2n_mode_cec124;
extern std::vector<int> a2n_known_d25790;
extern std::vector<int> a2n_known_cf4830;
extern std::vector<int> a2n_improved_cf48cc;
extern std::vector<A2NRecord *> a2n_records_d2d1c4;
extern string a2n_slotNames_d293c0[];
extern int a2n_invalid_caf164;
extern A2NItemDef *a2n_special_cefbec;
string a2n_intToString_4051f0(int value);
string a2n_countString_407a80(int count, const string &word);

struct A2NItem
{
	string getName(bool full, bool label);
	void *getEffect_457b70(int effect) throw();
	int getEffectValue_457be0(int effect) throw();
	bool unknown457d30() throw();
	int unknown457f90() throw();
	int unknown457fb0() throw();
	bool unknown457ff0() throw();
	bool unknown458030() throw();
	int unknown458240() throw();
	int unknown458260() throw();
	int charges_45cb30() throw();

	int pad0;
	int self;	// +0x04
	A2NItemDef *def;	// +0x08
	int location;	// +0x0c
	A2NHE owner;	// +0x10
	char pad14[0x1c - 0x14];
	int integrity;	// +0x1c
	bool faulty;	// +0x20
	int corrupted;	// +0x24
	char pad28[0x44 - 0x28];
	int armed;	// +0x44
	char pad48[0x5c - 0x48];
	string label;	// +0x5c
};

string A2NItem::getName(bool full, bool showLabel)
{
	if (def->rarity <= 3)
	{
		switch (def->rarity)
		{
			case 0:
				return a2n_intToString_4051f0(integrity) + " " + def->name;
			case 3:
				return def->name + "-" + a2n_intToString_4051f0(integrity);
			default:
				return def->name;
		}
	}
	if (a2n_mode_cec124 ? a2n_known_d25790[def->id] == 0 : a2n_known_cf4830[def->id] == 0)
	{
		string name;
		switch (def->origin)
		{
			case 0:
				name = "Unknown " + a2n_slotNames_d293c0[def->rarity];
				break;
			case 1:
				name = "Prototype " + a2n_slotNames_d293c0[def->rarity];
				break;
			case 2:
				name = "Construct " + a2n_slotNames_d293c0[def->rarity];
				break;
			case 3:
				name = "Alien " + a2n_slotNames_d293c0[def->rarity];
				break;
		}
		if (showLabel && !label.empty())
			name += " {" + label + "}";
		if (corrupted)
			return "Corrupted " + name;
		return name;
	}
	if (unknown458030())
		return full ? "Armed " + def->name + " (" + a2n_intToString_4051f0(armed) + ")" : "Armed " + def->name;
	string name = def->name;
	if (a2n_improved_cf48cc[def->id] && (!owner.get_9b6570() || owner.get_9b6570()->player_5c7600()))
		name += '+';
	if (faulty)
		return "Faulty " + name;
	else if (unknown457d30())
		return "Broken " + name;
	if (getEffect_457b70(86))
		name.insert(0,"Rigged ");
	if (corrupted)
		return "Corrupted " + name;
	if (showLabel && !label.empty())
		name += " {" + label + "}";
	if (full)
	{
		if (unknown457ff0() || def->type == 160)
		{
			if (charges_45cb30())
				name += " (" + a2n_intToString_4051f0(charges_45cb30()) + ")";
		}
		else if (unknown457f90() == 166)
		{
			name += " (" + a2n_intToString_4051f0(charges_45cb30()) + "/" + a2n_intToString_4051f0(unknown457fb0());
			if (charges_45cb30())
			{
				int value = getEffectValue_457be0(81);
				name += " " + (value == a2n_invalid_caf164 ? string("ERR") : a2n_records_d2d1c4[value]->name);
			}
			name += ")";
		}
		else if (unknown457f90() == 124)
			name += " (" + a2n_intToString_4051f0(charges_45cb30()) + ")";
		else if (unknown457f90() == 167)
			name += " (" + a2n_intToString_4051f0(charges_45cb30()) + "/" + a2n_intToString_4051f0(unknown457fb0()) + ")";
		else if (unknown457f90() == 204)
			name += getEffect_457b70(124) ? " (Full)" : " (Empty)";
		else if (unknown457f90() == 205)
			name += getEffect_457b70(124) ? " (Ready)" : " (Expended)";
		else if (getEffectValue_457be0(74))
			name += " (" + a2n_intToString_4051f0(getEffectValue_457be0(73)) + ")";
		else if (getEffectValue_457be0(75))
			name += " (" + a2n_intToString_4051f0(getEffectValue_457be0(75)) + "%)";
		else if (unknown458240())
			name += " (" + a2n_intToString_4051f0(unknown458260()) + ")";
		else if (getEffect_457b70(68))
			name += " (" + a2n_intToString_4051f0(getEffectValue_457be0(68)) + ")";
		else if (getEffect_457b70(71))
			name += " (" + a2n_intToString_4051f0(getEffectValue_457be0(71) == -1 ? 0 : getEffectValue_457be0(71)) + ")";
		else if (getEffect_457b70(118))
		{
			name += " (";
			if (getEffectValue_457be0(119) == getEffectValue_457be0(118))
				name += "Charged";
			else
				name += a2n_intToString_4051f0(getEffectValue_457be0(119)) + "/" + a2n_intToString_4051f0(getEffectValue_457be0(118));
			name += ")";
		}
		else if (getEffect_457b70(121))
			name += " (" + a2n_countString_407a80(getEffectValue_457be0(121),"Ring") + ")";
		else if (def == a2n_special_cefbec)
			name += " (" + a2n_intToString_4051f0(integrity) + ")";
	}
	return name;
}
