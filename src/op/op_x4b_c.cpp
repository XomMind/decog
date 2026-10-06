// op_x4b: functions in 0x6c1000-0x6c6000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct OpX4b_EntityRecord	// NOTE: placeholder name
{
	char pad00[0x24];
	int unknown24;	// NOTE: placeholder name
	int unknown28;	// NOTE: placeholder name
	char pad2c[0x68 - 0x2c];
	int unknown68;	// NOTE: placeholder name
	char pad6c[0x75 - 0x6c];
	bool unknown75;	// NOTE: placeholder name
};
extern vector<OpX4b_EntityRecord *> opx4b_entityRecords;	// NOTE: placeholder name (0xd25de0)

class OpX4b_GameData	// NOTE: placeholder name
{
public:
	int unknown46f4e0();	// NOTE: placeholder name
};
extern OpX4b_GameData opx4b_gameData;	// NOTE: placeholder name (0xd1e860)

class OpX4b_World	// NOTE: placeholder name
{
public:
	OpX4b_EntityRecord *unknown6c5600(int a, int b, bool c, bool d);	// NOTE: placeholder name
};

OpX4b_EntityRecord *OpX4b_World::unknown6c5600(int a, int b, bool c, bool d)
{
	int level = opx4b_gameData.unknown46f4e0();
	for (int i = 0; i < opx4b_entityRecords.size(); i++)
	{
		if (opx4b_entityRecords[i]->unknown24 == a && opx4b_entityRecords[i]->unknown28 == b && !opx4b_entityRecords[i]->unknown75)
		{
			for (int j = i + 1; j <= opx4b_entityRecords.size(); j++)
			{
				if (j == opx4b_entityRecords.size() || opx4b_entityRecords[j]->unknown28 != b || opx4b_entityRecords[j]->unknown75)
				{
					j--;
					if (b == 0x17)
					{
						level += rng.rangeInt(-1.0f,1.0f);
						if (c)
							level++;
						for (int k = j; k >= i; k--)
						{
							if (opx4b_entityRecords[k]->unknown68 <= level)
								return opx4b_entityRecords[k];
						}
					}
					else
					{
						if (c)
						{
							for (int m = i; m <= j; m++)
							{
								if (opx4b_entityRecords[m]->unknown68 > level)
									return opx4b_entityRecords[m];
							}
							return unknown6c5600(a,b,false,d);
						}
						else
						{
							for (int n = j; n >= i; n--)
							{
								if (opx4b_entityRecords[n]->unknown68 <= level)
									return opx4b_entityRecords[n];
							}
						}
					}
					break;
				}
			}
			break;
		}
	}
	if (d)
	{
		for (unsigned int p = 0; p < opx4b_entityRecords.size(); p++)
		{
			if (opx4b_entityRecords[p]->unknown28 == b && opx4b_entityRecords[p]->unknown24 == a)
				return opx4b_entityRecords[p];
		}
	}
	return NULL;
}
