// op_x4c: BS::unknown6c98c0 (0x6c98c0), Beta 17.1. NOTE: class/method names are placeholders.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;
};

class HProp;

class Prop
{
public:
	bool unknown45cb10();	// NOTE: placeholder name
	int unknown45c9b0();	// NOTE: placeholder name
	int getNestedField() throw();	// NOTE: placeholder name (0x45c570)
	int getNestedField_45c570() throw();	// NOTE: placeholder name (same function under a private name, see HProp::get_9b64f0)
	const Point &getPosition();	// 0x4184d0
	struct OpX4c_PropData *getData();	// NOTE: placeholder name (ICF'd trivial getter, 0x9b8f00)
};

class HProp
{
public:
	int ID;
	Prop *operator->() const throw();	// 0x9b64f0
	Prop *get_9b64f0() const throw();	// NOTE: placeholder name (operator-> under a private name, so LTCG keeps this TU's throw())
};

class Cell
{
public:
	void unknown45df70();	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
};
extern Array2D<Cell *> cells;	// 0xcfd44c

struct OpX4c_PropData	// NOTE: placeholder name
{
	char pad00[0x8c];
	int unknown8c;
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

class OpX4c_Lists460090	// NOTE: placeholder name (OpR1F_Lists460090; private name keeps the throw() ctor declaration)
{
public:
	OpX4c_Lists460090(int value0_, int value8_) throw();	// 0x460090
	void unknown460290(HProp prop);	// NOTE: placeholder name

	char pad00[0x4c];
};

struct OpD_PropRegistry	// NOTE: placeholder name (object at 0xd1e720)
{
	void unknown9d0fc0(HProp prop, bool flag);	// NOTE: placeholder name
};
extern OpD_PropRegistry opd_propRegistry;	// NOTE: placeholder name (0xd1e720)

extern vector<vector<HProp> > opx4c_machines;	// NOTE: placeholder name (0xd31640)
extern vector<OpX4c_Lists460090 *> opx4c_listsCf44b0;	// NOTE: placeholder name
extern int opx4c_countCefbb4;	// NOTE: placeholder name
extern int opx4c_chanceA[][3];	// NOTE: placeholder name (0xb9f950)
extern int opx4c_chanceB[][3];	// NOTE: placeholder name (0xb9fb18)
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0

class BS	// NOTE: placeholder name
{
public:
	void unknown6c98c0(int level, vector<int> &ids);	// NOTE: placeholder name
};

void BS::unknown6c98c0(int level, vector<int> &ids)
{
	if (!ids.empty())
	{
		int chance = rng.chance(opx4c_chanceA[opx4c_location->type][level]) ? 100 : opx4c_chanceB[opx4c_location->type][level];
		for (int i = ids.size() - 1; i >= 0; i--)
		{
			int id = ids[i];
			if (!opx4c_machines[id][0]->unknown45cb10() && opx4c_machines[id][0]->getData()->unknown8c == 0 && opx4c_machines[id][0]->unknown45c9b0() == 0 && rng.chance(chance))
			{
				vector<HProp> &list = opx4c_machines[id];
				OpX4c_Lists460090 *lists = new OpX4c_Lists460090(list[0].get_9b64f0()->getNestedField_45c570(),id);
				for (unsigned int j = 0; j < list.size(); j++)
				{
					lists->unknown460290(list[j]);
					cells(list[j]->getPosition())->unknown45df70();
					opd_propRegistry.unknown9d0fc0(list[j],true);
				}
				opx4c_listsCf44b0.push_back(lists);
				opx4c_countCefbb4++;
				opx4c_machines[id].clear();
				removeVectorElement(ids,i);
			}
		}
	}
}
