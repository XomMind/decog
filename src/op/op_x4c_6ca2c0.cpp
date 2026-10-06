// op_x4c: BS::unknown6ca2c0 (0x6ca2c0), Beta 17.1. NOTE: class/method names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(int v);	// 0x409990
	Point(int x_, int y_);	// 0x46ca20
	int randomInRange_40c130() const;	// NOTE: placeholder name
};

class Item;
class HItem
{
public:
	int ID;
	Item *operator->() const;	// 0x9b65b0
};

struct OpX4c_ItemData	// NOTE: placeholder name
{
	char pad00[0x94];
	int unknown94;
};

class Item
{
public:
	int unknown457880();	// NOTE: placeholder name
	int unknown457820();	// NOTE: placeholder name
	int unknown457900();	// NOTE: placeholder name
	void setField450460(int value);	// NOTE: placeholder name (0x450460, folded setter)
	OpX4c_ItemData *getData();	// NOTE: placeholder name (ICF'd trivial getter, 0x9b4350)
	const Point &unknown575920();	// NOTE: placeholder name
};

class ItemDef;

struct OpX4c_Range	// NOTE: placeholder name
{
	int lo;
	int hi;
	int randomInRange_40c130();	// NOTE: placeholder name
};
extern OpX4c_Range opx4c_rangeD33bd8;	// NOTE: placeholder name (0xd33bd8)
struct OpX4c_RangePair	// NOTE: placeholder name
{
	OpX4c_Range lo;
	OpX4c_Range hi;
};
extern OpX4c_RangePair opx4c_ranges[];	// NOTE: placeholder name (0xd357a8)

struct OpX4c_LocInfo	// NOTE: placeholder name
{
	char pad00[8];
	int depthIndex;
};
class OpX4c_HLoc	// NOTE: placeholder name
{
public:
	int ID;
	OpX4c_LocInfo *operator->() const;	// 0x9b7910
};
extern OpX4c_HLoc opx4c_location;	// 0xd1e888

void opx4c_eraseStep(vector<HItem> &v, unsigned int &index);	// NOTE: placeholder name (0x9d6440)
int opx4c_indexOf(vector<int> &v, int value);	// NOTE: placeholder name (0x9d4660)
int opx4c_maxIndex(vector<int> &v);	// NOTE: placeholder name (0x9d4500)

class BS	// NOTE: placeholder name
{
public:
	char pad0[0x2c0];
	vector<Point> unknown2c0;

	bool unknown6ca170(const Point &range, int picks, int count, int chanceType, vector<ItemDef *> *key, vector<int> *t, int unknown);	// NOTE: placeholder name
	HItem unknown6c5400(ItemDef *type, const Point &p);	// NOTE: placeholder name
	void unknown6ca2c0(const Point &p, int picks, int size);	// NOTE: placeholder name
};

void BS::unknown6ca2c0(const Point &p, int picks, int size)
{
	vector<ItemDef *> key;
	vector<int> t;
	if (!unknown6ca170(Point(-1),picks,opx4c_rangeD33bd8.randomInRange_40c130(),0,&key,&t,0x2a))
		return;
	vector<HItem> list;
	bool found = false;
	for (int x = p.x, index = 0; x < p.x + size; x++)
	{
		for (int y = p.y; y < p.y + size; y++)
		{
			if (t[index] == 0)
			{
				index++;
				if (index == key.size())
					goto done;
			}
			HItem item = unknown6c5400(key[index],Point(x,y));
			if (item->unknown457880() == 0)
				item->setField450460(opx4c_ranges[opx4c_location->depthIndex].lo.randomInRange_40c130());
			t[index]--;
			list.push_back(item);
			if (item->getData()->unknown94 == 1)
				found = true;
		}
	}
done:
	if (found)
	{
		int best = -1;
		for (unsigned int i = 0; i < list.size(); i++)
		{
			if (list[i]->getData()->unknown94 != 1)
				opx4c_eraseStep(list,i);
			else if (best == -1 || list[i]->unknown457900() > list[best]->unknown457900())
				best = i;
		}
		unknown2c0.push_back(list[best]->unknown575920());
	}
	else
	{
		vector<int> kinds;
		vector<int> amounts;
		for (unsigned int k = 0; k < list.size(); k++)
		{
			int slot = opx4c_indexOf(kinds,list[k]->unknown457820());
			if (slot == -1)
			{
				kinds.push_back(list[k]->unknown457820());
				amounts.push_back(1);
			}
			else
				amounts[slot]++;
		}
		int top = opx4c_maxIndex(amounts);
		for (unsigned int m = 0; m < list.size(); m++)
		{
			if (list[m]->unknown457820() == kinds[top])
			{
				unknown2c0.push_back(list[m]->unknown575920());
				break;
			}
		}
	}
}
