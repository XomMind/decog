// team_d_113: item record name 0x55eb20 (callers OpW1_SearchQuery::matches and four unnamed functions; the
// class OpW1_ItemRecord in op_w1.cpp declares it as getName(int, int)): matter/data style records are
// "<amount> <name>", unidentified items get "Unknown/Prototype/Construct/Alien <slot type>", others carry
// the prefix for the given style and a "+" when flagged.
// NOTE: class layouts are partial; names are placeholders.
#include <string>
#include <vector>
using namespace std;

string intToString(int value);	// 0x4051f0

extern string slotTypeNames113_d293c0[];	// NOTE: placeholder name
extern string prefixes113_cf75b0[];		// NOTE: placeholder name
extern string unknownPrefix113_cf763c;	// NOTE: placeholder name
extern vector<int> identified113_cf4830;	// NOTE: placeholder name
extern vector<int> flagged113_cf48cc;	// NOTE: placeholder name

class ItemRecord113	// NOTE: placeholder name and layout
{
public:
	int		id;			// +0x00
	char	pad04[0x24 - 4];
	string	name;		// +0x24
	char	pad40[4];
	int		type;		// +0x44
	char	pad48[0x94 - 0x48];
	int		rating;		// +0x94

	string getName(int amount, int style);	// NOTE: placeholder name
};

string ItemRecord113::getName(int amount, int style)
{
	if (type <= 3)
	{
		if (type == 0 || type == 3)
			return intToString(amount) + " " + name;
		else
			return name;
	}
	if (identified113_cf4830[id] == 0)
	{
		string s;
		switch (rating)
		{
		case 0:
			s = "Unknown " + slotTypeNames113_d293c0[type];
			break;
		case 1:
			s = "Prototype " + slotTypeNames113_d293c0[type];
			break;
		case 2:
			s = "Construct " + slotTypeNames113_d293c0[type];
			break;
		case 3:
			s = "Alien " + slotTypeNames113_d293c0[type];
			break;
		}
		if (style == 5)
			return unknownPrefix113_cf763c + s;
		return s;
	}
	return flagged113_cf48cc[id] != 0 ? prefixes113_cf75b0[style] + name + "+" : prefixes113_cf75b0[style] + name;
}
