// team_d_36: Item display name 0x573860.
// NOTE: names and layouts are placeholders.
#include <string>
#include <vector>
using namespace std;

extern string itemTypeNames36_d293c0[];	// NOTE: placeholder name
extern vector<int> itemKnown36_cf4830;	// NOTE: placeholder name

class ItemRec36	// NOTE: placeholder name (item record)
{
public:
	string getPrefixedName(int *length);	// 0x456fd0

	int		unknown00;
	char	pad04[0x24 - 0x04];
	string	name;			// +0x24
	char	pad40[0x44 - 0x40];
	int		unknown44;		// NOTE: placeholder name (slot type)
	char	pad48[0x94 - 0x48];
	int		unknown94;		// NOTE: placeholder name
};

string intToString(int value);

class Item
{
public:
	char		pad00[8];
	ItemRec36	*record;	// +0x08
	char		pad0c[0x1c - 0x0c];
	int			unknown1c;	// NOTE: placeholder name
	bool		faulty;		// +0x20, NOTE: placeholder name

	string unknown573860(bool full, int *length);	// NOTE: placeholder name
};

string Item::unknown573860(bool full, int *length)
{
	if (length)
		*length = 0;
	if (record->unknown44 <= 3)
	{
		switch (record->unknown44)
		{
		case 0:
			return intToString(unknown1c) + " " + record->name;
		case 3:
			return record->name + "-" + intToString(unknown1c);
		default:
			return record->name;
		}
	}
	if (itemKnown36_cf4830[record->unknown00] == 0 && !full)
	{
		switch (record->unknown94)
		{
		case 0:
			return "Unknown " + itemTypeNames36_d293c0[record->unknown44];
		case 1:
			return "Prototype " + itemTypeNames36_d293c0[record->unknown44];
		case 2:
			return "Construct " + itemTypeNames36_d293c0[record->unknown44];
		case 3:
			return "Alien " + itemTypeNames36_d293c0[record->unknown44];
		}
	}
	string name = record->getPrefixedName(length);
	if (faulty)
	{
		name.insert(0,"Faulty ");
		if (length)
			*length += *length ? 7 : 6;
	}
	return name;
}
