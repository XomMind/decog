// op_u3: functions in 0x5ba000-0x68d000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// NOTE: placeholder name (0xd30908)

struct Point
{
	int x;
	int y;

	int randomInRange_40c130();	// NOTE: placeholder name
};

class Prop;

class HProp
{
	int	ID;
public:
	HProp();
	Prop *operator->() const throw();
};

struct OpW8_PartOption	// NOTE: placeholder name
{
	OpW8_PartOption(int type_, int count_, int chance_) throw();	// 0x455da0

	int type;
	int count;
	int chance;
};

struct MapRecord;

class Map	// NOTE: placeholder name
{
public:
	void unknown4649e0(MapRecord *record) throw();	// NOTE: placeholder name
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)

struct OpU3_PropData	// NOTE: placeholder name
{
	char	pad00[0x80];
	int		unknown80;
	Point	unknown84;
};

extern vector<vector<HProp> > opu3_propsByD31640;	// NOTE: placeholder name (0xd31640)

class Prop
{
public:
	bool opu3_unknown6646f0(int a, int b, int c, bool d);	// NOTE: placeholder name
	bool opu3_unknown65f520(int a, int b, int c, int d, int e, int f, int g, int h, int i);	// NOTE: placeholder name

	int		ID;						// +0x00
	OpU3_PropData	*data;			// +0x04
	char	pad08[0x34 - 0x08];
	int		unknown34;
	char	pad38[0x3c - 0x38];
	int		unknown3C;
};

bool Prop::opu3_unknown6646f0(int a, int b, int c, bool d)
{
	if (unknown3C != 2 && unknown3C != 1 && data->unknown80 != 0 && rng.chance(data->unknown80))
	{
		int count = data->unknown84.randomInRange_40c130();
		unsigned int j;
		vector<HProp> *list;
		if (count == 0)
		{
			return opu3_unknown65f520(1,b,1,0,c,a,d,0,0);
		}
		else
		{
			OpW8_PartOption *opt = new OpW8_PartOption(a,ID,count);
			world->unknown4649e0((MapRecord *)opt);
			list = &opu3_propsByD31640[unknown34];
			for (j = 0; j < list->size(); j++)
			{
				(*list)[j]->unknown3C = 2;
			}
		}
	}
	return false;
}
