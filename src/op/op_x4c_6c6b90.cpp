// op_x4c: BS::unknown6c6b90 (0x6c6b90), Beta 17.1. NOTE: class/method names are placeholders.
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
	HProp();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	Prop *operator->() const;	// 0x9b64f0
};

class Cell
{
public:
	HProp getProp();		// 0x45d550
	bool unknown45df50(HProp prop);	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
};
extern Array2D<Cell *> cells;	// 0xcfd44c

struct OpX4c_PropData;
struct OpX4c_Talk	// NOTE: placeholder name
{
	char pad00[0x3c];
	int type;
};

struct OpX4c_PropFactory	// NOTE: placeholder name
{
	HProp create(OpX4c_PropData *type);	// 0x793360
};
extern OpX4c_PropFactory *opx4c_propFactory;	// 0xcefaa8
extern OpX4c_PropData *opx4c_cefbd0;	// NOTE: placeholder name

class Prop
{
public:
	OpX4c_PropData *getData();	// NOTE: placeholder name (ICF'd trivial getter, 0x9b8f00)
	void unknown45cc50(const Point &p);	// NOTE: placeholder name
	void unknown665b10(OpX4c_Talk *talk, bool flag);	// NOTE: placeholder name
	int unknown665a70(int id, int amount);	// NOTE: placeholder name
};

extern vector<OpX4c_Talk *> opx4c_talks;	// NOTE: placeholder name (0xd2c408)
bool opx4c_findTalk(vector<OpX4c_Talk *> &list, string &name, OpX4c_Talk *&talk);	// NOTE: placeholder name (0x9d7de0)

class BS	// NOTE: placeholder name
{
public:
	void unknown464e60(HProp p);	// NOTE: placeholder name
	bool unknown6c6b90(Point &p, string &name, OpX4c_Talk *talk, int id);	// NOTE: placeholder name
};

bool BS::unknown6c6b90(Point &p, string &name, OpX4c_Talk *talk, int id)
{
	if (cells(p)->getProp().isValid() && cells(p)->getProp()->getData() != opx4c_cefbd0)
		return false;
	OpX4c_Talk *propTalk = NULL;
	if (id == -1)
	{
		if (talk)
			propTalk = talk;
		else
		{
			opx4c_findTalk(opx4c_talks,name,propTalk);
			if (propTalk == NULL)
				return false;
		}
	}
	HProp prop;
	if (cells(p)->getProp().isValid())
		prop = cells(p)->getProp();
	else
	{
		prop = opx4c_propFactory->create(opx4c_cefbd0);
		cells(p)->unknown45df50(prop);
		prop->unknown45cc50(p);
	}
	if (propTalk)
	{
		prop->unknown665b10(propTalk,false);
		unknown464e60(prop);
	}
	else
		prop->unknown665a70(id,1);
	return true;
}
