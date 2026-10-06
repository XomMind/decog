// op_t4_b: item selection tables (0x6c3a50-0x6c5000) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

class OpT4_ItemTypeEntry	// NOTE: placeholder name
{
public:
	int ID;
	char pad04[0x50 - 4];
	int unknown50;
	int unknown54;
	int unknown58;
	char pad5c[4];
	int unknown60;
	char pad64[0x94 - 0x64];
	int unknown94;
};

class OpT4_GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	bool unknown46f4b0(int value);	// NOTE: placeholder name
	int unknown46f4e0();	// NOTE: placeholder name
};

struct OpT4_LocationInfo	// NOTE: placeholder name
{
	char pad00[4];
	int depthIndex;
};

class OpT4_HLocation	// NOTE: placeholder name (object at 0xd1e888)
{
public:
	OpT4_LocationInfo *operator->() const;	// 0x9b7910
};
extern OpT4_HLocation opt4_location;	// NOTE: placeholder name (0xd1e888)

class OpT4_RoomType	// NOTE: placeholder name
{
public:
	int ID;
	char pad04[0x68 - 4];
	int unknown68;
	char pad6c[0xe8 - 0x6c];
	int unknowne8;
	int unknownec;
	char padf0[4];
	int unknownf4;
};
extern vector<OpT4_RoomType *> opt4_roomTypes;	// NOTE: placeholder name (0xd25de0)
extern OpT4_GameData opt4_gameData;	// NOTE: placeholder name (0xd1e860)
extern vector<OpT4_ItemTypeEntry *> opt4_itemTypes;	// NOTE: placeholder name (0xd2d1c4)
bool opt4_unknown5714a0(int value);	// NOTE: placeholder name
int opt4_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)

class OpT4_WeightedTable	// NOTE: placeholder name
{
public:
	void clear();	// NOTE: placeholder name (0x9c07a0)
	void add(int value, int weight);	// NOTE: placeholder name (0x9ba310)
};

class OpT4_Selector	// NOTE: placeholder name
{
public:
	char pad00[0xc0];
	OpT4_WeightedTable roomTable;

	void unknown6c4fd0();	// NOTE: placeholder name
	void unknown6c3a50(OpT4_WeightedTable *table, bool flag, int rating);	// NOTE: placeholder name
};

void OpT4_Selector::unknown6c3a50(OpT4_WeightedTable *table, bool flag, int rating)
{
	rating = rating ? rating : opt4_gameData.unknown46f4e0();
	table->clear();
	int weight;
	for (unsigned int i = 0; i < opt4_itemTypes.size(); i++)
	{
		if (bool(opt4_itemTypes[i]->unknown94 != 0) == flag)
		{
			OpT4_ItemTypeEntry *type = opt4_itemTypes[i];
			if (!opt4_unknown5714a0(type->unknown54))
				continue;
			float chance = 1.0f;
			if (opt4_maxInt(1,rating) < type->unknown50)
				continue;
			switch (type->unknown58)
			{
			case 0:
				break;
			case 1:
			case 2:
				{
					chance -= (rating - type->unknown50) * (type->unknown58 == 1 ? 0.35f : 0.15f);
					if (chance <= 0.0)
						continue;
				}
				break;
			default:
				break;
			}
			weight = (int)(type->unknown60 * chance);
			if (weight > 0)
				table->add(type->ID,weight);
		}
	}
}

void OpT4_Selector::unknown6c4fd0()
{
	roomTable.clear();
	int weight;
	for (unsigned int i = 0; i < opt4_roomTypes.size(); i++)
	{
		OpT4_RoomType *type = opt4_roomTypes[i];
		if (type->unknowne8 >= 4)
		{
			if (opt4_location->depthIndex != type->unknowne8 - 4)
				continue;
		}
		else
		{
			switch (type->unknowne8)
			{
			case 0:
				continue;
				break;
			case 2:
				if (!opt4_gameData.unknown46f4b0(1))
					continue;
				break;
			case 3:
				if (!opt4_gameData.unknown46f4b0(2))
					continue;
				break;
			}
		}
		float chance = 1.0f;
		if (opt4_maxInt(1,opt4_gameData.unknown46f4e0()) < type->unknown68)
			continue;
		switch (type->unknownec)
		{
		case 0:
			break;
		case 1:
		case 2:
			chance -= (opt4_gameData.unknown46f4e0() - type->unknown68) * (type->unknownec == 1 ? 0.35f : 0.15f);
			if (chance <= 0.0)
				continue;
			break;
		}
		weight = (int)(type->unknownf4 * chance);
		if (weight > 0)
			roomTable.add(type->ID,weight);
	}
}
