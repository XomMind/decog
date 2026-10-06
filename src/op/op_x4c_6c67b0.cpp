// op_x4c: BS::placeProp (0x6c67b0), Beta 17.1. NOTE: class/method names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p) throw();	// 0x46ca50
};

class Prop;

class HProp
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
	Prop *operator->() const throw();	// 0x9b64f0
};

class Cell
{
public:
	bool unknown45d6a0();	// NOTE: placeholder name
	HProp getProp() throw();	// 0x45d550
	bool unknown45df50(HProp prop);	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p) throw();	// 0x9ced70
};
extern Array2D<Cell *> cells;	// 0xcfd44c

struct OpX4c_PropData	// NOTE: placeholder name
{
	char pad00[0x140];
	int unknown140;
};

struct OpX4c_PropFactory	// NOTE: placeholder name
{
	HProp create(OpX4c_PropData *type);	// 0x793360
};
extern OpX4c_PropFactory *opx4c_propFactory;	// 0xcefaa8

struct OpX4c_PropLink	// NOTE: placeholder name
{
	OpX4c_PropLink(HProp prop_, int index_);	// 0x45c2e0

	HProp prop;
	int index;
	HProp unknown08;
	HProp unknown0C;
	int unknown10;
	int unknown14;
	int unknown18;
	int unknown1C;
};

OpX4c_PropLink::OpX4c_PropLink(HProp prop_, int index_)
{
	prop = prop_;
	index = index_;
	unknown10 = 3;
	unknown14 = 0;
	unknown18 = 0;
	unknown1C = 0;
}

class Prop
{
public:
	void unknown45cc50(const Point &p);	// NOTE: placeholder name
	OpX4c_PropLink *getLink() throw();			// NOTE: placeholder name (0x44b020)
	void setLink(OpX4c_PropLink *link) throw();	// NOTE: placeholder name (0x44cea0)
};

class OpX4c_WeightedTable	// NOTE: placeholder name
{
public:
	OpX4c_WeightedTable(const int *weights, int count) throw();	// 0x9ba790
	~OpX4c_WeightedTable();	// 0x700dd0
	int &pick() throw();	// 0x9ba470

	vector<int> values;
	vector<int> weights;
	int total;
};

struct OpX4c_Location	// NOTE: placeholder name
{
	int pad00;
	int type;
};

class OpX4c_HLocation	// NOTE: placeholder name
{
public:
	int ID;
	OpX4c_Location *operator->() const throw();	// 0x9b7910
};
extern OpX4c_HLocation opx4c_location;	// 0xd1e888

extern int opx4c_caf130;	// NOTE: placeholder name
extern bool opx4c_cefaed;	// NOTE: placeholder name
extern vector<vector<HProp> > opx4c_traps;	// 0xd20248
extern vector<int> opx4c_d3239c;	// NOTE: placeholder name
extern int opx4c_weights[3];	// NOTE: placeholder name (0xb9762c)
extern int opx4c_allowed[];		// NOTE: placeholder name (0xb90ea0)

void opx4c_dummy(int value);	// NOTE: declaration only; its parameter name seeds the compiler's local-slot ordering
class BS	// NOTE: placeholder name
{
public:
	bool placeProp(OpX4c_PropData *type, const Point &p, int groupIndex, int linkValue, int linkValue2);	// NOTE: placeholder name (0x6c67b0)
};

bool BS::placeProp(OpX4c_PropData *type, const Point &p, int groupIndex, int linkValue, int linkValue2)
{
	if ((opx4c_caf130 != 6 && !cells(p)->unknown45d6a0()) || !cells(p)->unknown45df50(opx4c_propFactory->create(type)))
		return false;
	else
		cells(p)->getProp()->unknown45cc50(p);
	if (groupIndex == -1)
	{
		opx4c_traps.push_back(vector<HProp>());
		opx4c_d3239c.push_back(2);
		opx4c_traps.back().push_back(cells(p)->getProp());
		groupIndex = opx4c_traps.size() - 1;
	}
	else
		opx4c_traps[groupIndex].push_back(cells(p)->getProp());
	cells(p)->getProp()->setLink(new OpX4c_PropLink(cells(p)->getProp(),groupIndex));
	if (opx4c_cefaed)
		cells(p)->getProp()->getLink()->unknown10 = 0;
	else
		cells(p)->getProp()->getLink()->unknown10 = linkValue;
	switch (type->unknown140)
	{
	case 0xd:
		if (opx4c_traps[groupIndex].size() == 1)
		{
			OpX4c_WeightedTable table(opx4c_weights,3);
			int result;
			do
			{
				result = table.pick();
			}
			while (result >= 1 && opx4c_allowed[opx4c_location->type] == 0);
			cells(p)->getProp()->getLink()->unknown14 = result;
		}
		else
			cells(p)->getProp()->getLink()->unknown14 = opx4c_traps[groupIndex].front()->getLink()->unknown14;
		break;
	case 0xb:
		cells(p)->getProp()->getLink()->unknown14 = (linkValue2 != -1) ? linkValue2 : 100;
		break;
	}
	return true;
}
