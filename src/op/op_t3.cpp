// op_t3: functions in 0x5dc000-0x68e000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <vector>
using namespace std;
struct Point
{
	int x;
	int y;
	Point(int x_, int y_) throw();	// 0x46ca20
};
extern vector<int> opT3_d2f0f8;	// NOTE: placeholder name (0xd2f0f8)
class OpT3_Box	// NOTE: placeholder name
{
public:
	char pad00[0x20];
	vector<Point *> points;	// +0x20
	Point *unknown45c800(int id);	// NOTE: placeholder name
	int unknown665a70(int id, int amount);	// NOTE: placeholder name
};
int OpT3_Box::unknown665a70(int id, int amount)
{
	Point *p = unknown45c800(id);
	if (p != NULL)
	{
		p->y += amount;
		return p->y;
	}
	else
	{
		points.push_back(new Point(opT3_d2f0f8[id],amount));
		return amount;
	}
}
struct OpT3_PropData	// NOTE: placeholder name
{
	char pad00[0x68];
	int unknown68;
	char pad6c[0xa4 - 0x6c];
	int unknownA4;
};
class OpT3_Prop	// NOTE: placeholder name
{
public:
	int ID;
	OpT3_PropData *data;	// +0x04
	void unknown665d10(int *value, float factor);	// NOTE: placeholder name
	void unknown665d40(int *value, float factor);	// NOTE: placeholder name
};
void OpT3_Prop::unknown665d10(int *value, float factor)
{
	*value -= data->unknown68 * factor;
}
void OpT3_Prop::unknown665d40(int *value, float factor)
{
	*value -= data->unknownA4 * factor;
}

bool opT3_inRange(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)
template <class T> T opT3_randomElement(vector<T> &v);	// NOTE: placeholder name (0x9d5d00)
extern int opT3_caf164;	// NOTE: placeholder name
struct OpT3_ItemType	// NOTE: placeholder name
{
	int unknown00;
	char pad04[0x44 - 0x4];
	int unknown44;
	char pad48[0xf0 - 0x48];
	int unknownF0;
	char padf4[0x238 - 0xf4];
	bool unknown238;
};
extern vector<OpT3_ItemType *> opT3_itemTypes;	// NOTE: placeholder name (0xd2d1c4)

int opT3_f6853a0(int key)	// NOTE: placeholder name
{
	vector<int> matches;
	for (int i = opT3_itemTypes.size() - 1; i >= 0; i--)
	{
		if (opT3_inRange(14,opT3_itemTypes[i]->unknown44,19) && opT3_itemTypes[i]->unknownF0 == key && opT3_itemTypes[i]->unknown238)
			matches.push_back(i);
	}
	return matches.empty() ? opT3_caf164 : opT3_randomElement(matches);
}

void opT3_f6854b0(vector<int> &list, int key)	// NOTE: placeholder name
{
	int index = opT3_f6853a0(key);
	if (index != opT3_caf164)
		list.push_back(index);
}

class Map
{
public:
	int unknown4638e0(int type, int value);	// NOTE: placeholder name
};
extern Map *opT3_world;	// NOTE: placeholder name (0xcefc4c)
class OpT3_Rec65cf50	// NOTE: placeholder name
{
public:
	char pad00[0x10];
	int unknown10;
	bool unknown65cf50(int value);	// NOTE: placeholder name
};
bool OpT3_Rec65cf50::unknown65cf50(int value)
{
	return !opT3_world->unknown4638e0(unknown10,value);
}
