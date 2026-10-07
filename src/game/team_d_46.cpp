// team_d_46: item desirability score 0x581e70 (used by EntityAI::takeTurn when picking up items).
// NOTE: names and layouts are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Entity
{
public:
	Point &getPosition();
	int unknown45a940();	// NOTE: placeholder name (percentage)
};

class HEntity
{
	int ID;
public:
	Entity *operator->() const;
};

class Item
{
public:
	int unknown4578a0();	// NOTE: placeholder name (folded getter, slot)
	int unknown457f90();	// NOTE: placeholder name
	int unknown457880();	// NOTE: placeholder name (folded getter)
	int unknown457920();	// NOTE: placeholder name
	int unknown457ca0();	// NOTE: placeholder name
	int unknown4578c0();	// NOTE: placeholder name (folded getter)
	const Point &unknown575920();	// NOTE: placeholder name (position)
};

class HItem
{
	int ID;
public:
	Item *operator->() const;
};

extern int mins46_ba7b0c[];		// NOTE: placeholder name
extern int caps46_ba7b1c[];		// NOTE: placeholder name
extern int limits46_ba7b2c[];	// NOTE: placeholder name
extern int minimums46_ba7b50[];	// NOTE: placeholder name

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
bool OpX5_containsRecord(vector<int> &v, int value);	// NOTE: placeholder name

class ItemEval46	// NOTE: placeholder name
{
public:
	HEntity		owner;			// +0x00
	int			mode;			// +0x04
	int			index;			// +0x08
	int			unknown0c;		// NOTE: placeholder name
	vector<int>	unknown10;		// NOTE: placeholder name
	bool		unknown20;		// NOTE: placeholder name
	vector<int>	counts;			// +0x24
	int			unknown34;		// NOTE: placeholder name
	float		unknown38;		// NOTE: placeholder name
	int			unknown3c;		// NOTE: placeholder name
	int			unknown40;		// NOTE: placeholder name
	vector<int>	unknown44;		// NOTE: placeholder name

	int score(HItem item, bool flag);	// NOTE: placeholder name
};

int ItemEval46::score(HItem item, bool flag)
{
	int type = item->unknown4578a0();
	switch (mode)
	{
	case 0:
		{
			int value = 0;
			if (item->unknown457f90() == 7)
			{
				if (unknown3c == 0 && limits46_ba7b2c[index])
					return 0;
				if (unknown3c > limits46_ba7b2c[index])
					value = 0xf;
			}
			else if (caps46_ba7b1c[type] != 9999)
			{
				if (counts[type] > caps46_ba7b1c[type])
				{
					if (type == 1)
						value = item->unknown457880() != unknown0c ? 0x14 : 1;
					else
						value = 1;
				}
			}
			else if (unknown34 < 0)
			{
				if (item->unknown457f90() == 1 || item->unknown457f90() == 2)
					return 0xf;
			}
			if (value)
			{
				value += 12 - item->unknown457920();
				value = OpX5_maxInt(1,value - item->unknown457ca0() * value / 100);
			}
			return value;
		}
	case 2:
		if (item->unknown457880() == 0)
			return (100 - owner->unknown45a940()) / 4;
		if (item->unknown457880() == 3)
			return 0x14;
		if (item->unknown457880() == 2)
			return 0x14;
	case 3:
		if (!flag && minimums46_ba7b50[item->unknown457f90()] && unknown44[item->unknown457f90()] >= minimums46_ba7b50[item->unknown457f90()])
			return 0;
	}
	int total = item->unknown457920();
	total *= item->unknown4578c0();
	if (item->unknown457f90() == 7)
	{
		if (unknown3c == 0 && limits46_ba7b2c[index])
			total = 0xf;
		if (unknown3c >= limits46_ba7b2c[index])
			return 0;
	}
	switch (mode)
	{
	case 1:
		if (item->unknown457880() == unknown0c)
			total *= 4;
		else if (item->unknown457f90() == 1 || item->unknown457f90() == 2)
			total = (int)(total * unknown38);
		break;
	case 2:
		if (type == 1 && unknown20)
			total *= 2;
		else if (OpX5_containsRecord(unknown10,type))
			total *= 2;
		if (item->unknown457f90() == 1 || item->unknown457f90() == 2)
			total = (int)(total * unknown38);
		break;
	case 3:
		if (counts[type] >= caps46_ba7b1c[type] || (unknown34 <= 0 && (item->unknown457f90() == 1 || item->unknown457f90() == 2)))
			return 0;
		if (counts[type] < mins46_ba7b0c[type])
		{
			if (type == 1 && item->unknown457880() == unknown0c)
				total *= 4;
			else
				total *= 2;
		}
		break;
	}
	if (mode >= 2)
		total -= OpQ1_distanceCeil_40a3f0(owner->getPosition(),item->unknown575920()) / 6;
	if ((unknown0c >= 12 || unknown40 > 3) && (item->unknown457880() == 0x15 || item->unknown457880() == 0x17))
		total /= 2;
	total = OpX5_maxInt(1,item->unknown457ca0() * total / 100);
	return total;
}
