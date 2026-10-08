// team_d_106: slot-table member 0x7ac1c0 (the class of OpU5_SlotTable::findSlot/canUse in op_u5_s3.cpp;
// callers Entity::takeDamage/die/move and CompanionData::unknown7ace20): a robot "says" a line of the given
// record type - picks a random line for its slot, prefixes the speaker name, substitutes the optional
// replacement text and posts it as message 0x322. Returns false when the line is unavailable.
// NOTE: class layouts are partial; names are placeholders.
// NOTE: the locals n (slot) and msg (line text) are named for their stack-slot hash order.
#include <string>
#include <vector>
using namespace std;

string OpU8a_randomString(vector<string> &v);	// NOTE: placeholder name (0x9d3280)
void opr5c_replace407e00(string &text, string from, string to);	// NOTE: placeholder name
extern string token106_d37ca4;	// NOTE: placeholder name

class Entity;

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
};

class Entity
{
public:
	string *getName106();	// NOTE: placeholder name (folded getter XCell::getFore, +0x0c)
};

void opW5_message(int type, HEntity entity, const string &text, int value);	// NOTE: placeholder name

class BS
{
public:
	int getTurn();
};
extern BS *world106_cefc4c;	// NOTE: placeholder name

struct SlotRecord106	// NOTE: placeholder name and layout
{
	char					pad00[0x40];
	vector< vector<string> >	lines;	// +0x40
};
extern vector<SlotRecord106 *> slotRecords106_d1d078;	// NOTE: placeholder name

class Grid106	// NOTE: placeholder name (OpX5_Array2D<int>)
{
public:
	int *at(int x, int y);
};

class SlotTable106	// NOTE: placeholder name and layout (OpU5_SlotTable)
{
public:
	char	pad00[0x20];
	Grid106	lastUsed;	// +0x20

	int findSlot(HEntity e);
	bool canUse(HEntity e, unsigned int record);
	bool unknown7ac1c0(HEntity e, unsigned int record, bool force, string replacement);	// NOTE: placeholder name
};

bool SlotTable106::unknown7ac1c0(HEntity e, unsigned int record, bool force, string replacement)
{
	if (!force && !canUse(e,record))
		return false;
	int n = findSlot(e);
	*lastUsed.at(record,n) = world106_cefc4c->getTurn();
	if (slotRecords106_d1d078[record]->lines[n].empty())
		return false;
	string msg = slotRecords106_d1d078[record]->lines[n].size() > 1 ? OpU8a_randomString(slotRecords106_d1d078[record]->lines[n]) : slotRecords106_d1d078[record]->lines[n][0];
	msg.insert(0,*e->getName106() + ": \"");
	if (!replacement.empty())
		opr5c_replace407e00(msg,token106_d37ca4,replacement);
	msg += "\"";
	opW5_message(0x322,e,msg,0);
	return true;
}
