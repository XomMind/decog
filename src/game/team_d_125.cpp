// team_d_125: Item member 0x573c90 (callers C38_Snapshot::unknown483d30 and CPart::drawName): appends the
// item's status suffix to a display name - stored matter/charge counts, the contents of a container, the
// module of a processor slot or the count of rings - and returns the suffix length.
// NOTE: class layouts are partial; names are placeholders.
#include <string>
#include <vector>
using namespace std;

string intToString(int value);	// 0x4051f0
string opw8_countString(int count, const string &noun);	// NOTE: placeholder name (0x407a80)

extern string moduleNames125_d2b4f8[];	// NOTE: placeholder name
extern int noItem125_caf164;	// NOTE: placeholder name

struct ItemRecord125	// NOTE: placeholder name and layout
{
	char	pad000[0x1b4];
	string	name;	// +0x1b4
};
extern vector<ItemRecord125 *> itemRecords125_d2d1c4;	// NOTE: placeholder name

class Item
{
public:
	int unknown457f90();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
	int getField125();		// NOTE: placeholder name (folded getter, 0x45cb30)
	int getEffectValue(int type);	// NOTE: placeholder name (0x457be0)
	int getEffect(int type);	// NOTE: placeholder name (0x457b70)
	int unknown573c90(string &name);	// NOTE: placeholder name
};

int Item::unknown573c90(string &name)
{
	string s;
	switch (unknown457f90())
	{
	case 0xa6:
		s = " (" + intToString(getField125()) + "/" + intToString(unknown457fb0());
		if (getField125())
		{
			int id = getEffectValue(0x51);
			s += " " + (id == noItem125_caf164 ? string("ERR") : itemRecords125_d2d1c4[id]->name);
		}
		s += ")";
		break;
	case 0xa7:
		s = " (" + intToString(getField125()) + "/" + intToString(unknown457fb0()) + ")";
		break;
	case 0x7c:
		s = " (" + intToString(getField125()) + ")";
		break;
	case 0x68:
		s = " (" + (getEffect(0x74) ? string(moduleNames125_d2b4f8[getEffectValue(0x74)]) : string("Blank")) + ")";
		break;
	}
	if (s.empty() && getEffect(0x79))
		s = " (" + opw8_countString(getEffectValue(0x79),"Ring") + ")";
	if (s.size())
		name += s;
	return s.size();
}
