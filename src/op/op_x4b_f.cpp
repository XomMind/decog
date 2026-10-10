// op_x4b: RANDOM_ITEM / RANDOM_ENTITY spec parsers (0x6c4600, 0x6c4ac0) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

class OpX4b_Range	// NOTE: placeholder name
{
public:
	OpX4b_Range();	// 0x40bef0
	bool parseRange_40bf80(const string &text);	// NOTE: placeholder name
	int randomInRange_40c130();	// NOTE: placeholder name
	bool contains_40c190(int value);	// NOTE: placeholder name

	int low;
	int high;
};

struct OpX4b_LocationInfo	// NOTE: placeholder name
{
	int getDepthIndex();	// NOTE: placeholder name
};

class OpX4b_HLocation	// NOTE: placeholder name (object at 0xd1e888)
{
public:
	OpX4b_LocationInfo *operator->() const;	// 0x9b7910
};
extern OpX4b_HLocation opx4b_location;	// NOTE: placeholder name (0xd1e888)

struct OpX4b_ItemDef	// NOTE: placeholder name
{
	int ID;
};

struct OpX4b_EntityRecord	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	char pad04[0x68 - 4];
	int unknown68;	// NOTE: placeholder name
	char pad6c[0xe8 - 0x6c];
	int unknownE8;	// NOTE: placeholder name
	char padEC[0xf0 - 0xec];
	int unknownF0;	// NOTE: placeholder name
};
extern vector<OpX4b_EntityRecord *> opx4b_entityRecords;	// NOTE: placeholder name (0xd25de0)
extern int opx4b_table_ba3acc[];	// NOTE: placeholder name

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void add(T value, int weight);	// 0x9ba310
	T &pick();	// 0x9ba470
	bool isEmpty();	// NOTE: placeholder name (0x9b81b0)
};

class OpX4b_World	// NOTE: placeholder name
{
public:
	OpX4b_EntityRecord *unknown6c5180();	// NOTE: placeholder name
	OpX4b_ItemDef *selectRandomItemOfRating(int level, int mode, int chanceType, int rating, int category, int unknown, int attempt);	// 0x6c40e0
};
extern OpX4b_World *opx4b_world;	// NOTE: placeholder name (0xcefc4c)

extern int opx4b_invalidID;	// NOTE: placeholder name (0xcaf164)
extern int opx4b_invalidEntityID;	// NOTE: placeholder name (0xcaf160)
extern string opx4b_modeNames[];	// NOTE: placeholder name (0xd1e2b8)
extern string opx4b_chanceNames[];	// NOTE: placeholder name (0xd2f218)
extern string opx4b_ratingNames[];	// NOTE: placeholder name (0xcf3668)
extern string opx4b_categoryNames[];	// NOTE: placeholder name (0xd21bb8)
extern string opx4b_unknownNames[];	// NOTE: placeholder name (0xd01568)

int OpT8a_findStringIndex(const string *list, unsigned int count, string s);	// NOTE: placeholder name
void opw8_eraseFirstChar(string &s);	// NOTE: placeholder name (0x4077e0)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
void opw1_split(const string &text, char separator, vector<string> &out);	// NOTE: placeholder name (0x408700)
int unknown405b40(unsigned char c) throw();	// NOTE: placeholder name
int OpX5_minInt(int a, int b);	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name

int OpX4b_unknown6c4600(const string &text)	// NOTE: placeholder name
{
	if (text.find("RANDOM_ITEM",0) == string::npos)
		return opx4b_invalidID;
	string s = text;
	size_t pos = s.find('(',0);
	if (pos == string::npos)
		return opx4b_invalidID;
	s.erase(s.begin(),s.begin() + pos + 1);
	pos = s.rfind(')',string::npos);
	if (pos == string::npos)
		return opx4b_invalidID;
	s.erase(s.begin() + pos,s.end());
	vector<string> split;
	opw1_split(s,',',split);
	if (split.size() != 6)
		return opx4b_invalidID;
	int rating;
	if (split[0][0] == '+')
	{
		opw8_eraseFirstChar(split[0]);
		rating = OpX5_minInt(opx4b_location->getDepthIndex() + stringToInt(split[0]),10);
	}
	else
	{
		OpX4b_Range range;
		range.parseRange_40bf80(split[0]);
		rating = range.randomInRange_40c130();
	}
	OpX4b_ItemDef *entry = opx4b_world->selectRandomItemOfRating(rating,
		OpT8a_findStringIndex(opx4b_modeNames,3,split[1]),
		OpT8a_findStringIndex(opx4b_chanceNames,3,split[2]),
		split[3] == "-" ? 0x1f : OpT8a_findStringIndex(opx4b_ratingNames,0x1f,split[3]),
		split[4] == "-" ? 0x12 : OpT8a_findStringIndex(opx4b_categoryNames,0x12,split[4]),
		split[5] == "-" ? 0x2a : OpT8a_findStringIndex(opx4b_unknownNames,0x2a,split[5]),0);
	return entry ? entry->ID : opx4b_invalidID;
}

int OpX4b_unknown6c4ac0(const string &text)
{
	if (text.find("RANDOM_ENTITY",0) == string::npos)
		return opx4b_invalidEntityID;
	size_t pos = text.find('(',0);
	if (pos == string::npos)
	{
		OpX4b_EntityRecord *ent = opx4b_world->unknown6c5180();
		return ent ? ent->unknown0 : opx4b_invalidEntityID;
	}
	string s = text;
	s.erase(s.begin(),s.begin() + pos + 1);
	pos = s.rfind(')',string::npos);
	if (pos == string::npos)
		return opx4b_invalidEntityID;
	s.erase(s.begin() + pos,s.end());
	vector<string> split;
	opw1_split(s,',',split);
	if (split.size() != 2)
		return opx4b_invalidEntityID;
	OpX4b_Range range;
	if (isdigit(split[0][0]))
		range.low = unknown405b40(split[0][0]);
	else if (split[0][0] == '+')
		range.low = OpX5_minInt(opx4b_location->getDepthIndex() + unknown405b40(split[0][1]),10);
	else
		range.low = OpX5_maxInt(opx4b_location->getDepthIndex() - unknown405b40(split[0][1]),1);
	if (isdigit(split[1][0]))
		range.high = unknown405b40(split[1][0]);
	else if (split[1][0] == '+')
		range.high = OpX5_minInt(opx4b_location->getDepthIndex() + unknown405b40(split[1][1]),10);
	else
		range.high = OpX5_maxInt(opx4b_location->getDepthIndex() - unknown405b40(split[1][1]),1);
	OpR5h_WL<int> wl;
	for (unsigned int n = 0; n < opx4b_entityRecords.size(); n++)
	{
		if (opx4b_entityRecords[n]->unknownE8 && range.contains_40c190(opx4b_entityRecords[n]->unknown68))
			wl.add(n,opx4b_table_ba3acc[opx4b_entityRecords[n]->unknownF0]);
	}
	return wl.isEmpty() ? opx4b_invalidEntityID : wl.pick();
}
