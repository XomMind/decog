// team_d_92: member 0x65c1f0 (called from EntityAI::takeTurn): picks the next order type for a squad
// (pending special orders first, then Overmind events, weighted reinforcements).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
using namespace std;

template <class T> void OpS8c_shuffle(vector<T> &v);	// NOTE: placeholder name
bool OpX5_containsRecord(vector<int> &v, int value);	// NOTE: placeholder name
int opr1c_getThresholdIndex(int value);	// 0x433260, NOTE: placeholder name

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void add(T value, int weight);
	T &pick();
	unsigned int size();	// NOTE: placeholder name (0x9b81d0)
};

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

struct Location92	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;
};

class HLoc92	// NOTE: placeholder name
{
	int ID;
public:
	Location92 *operator->() const;
};
extern HLoc92 location92_d1e888;	// NOTE: placeholder name

class GameData92	// NOTE: placeholder name (0xd1e860)
{
public:
	bool unknown46f4b0(int a);	// NOTE: placeholder name
};
extern GameData92 gameData92_d1e860;	// NOTE: placeholder name

class OpS1e_EntryList	// NOTE: placeholder layout (0xcf6428)
{
public:
	int countParties(int ID);	// NOTE: placeholder name
};
extern OpS1e_EntryList entryList92_cf6428;	// NOTE: placeholder name
extern int threat92_cf6428;	// NOTE: placeholder name (first field of the object at 0xcf6428)
extern bool flag92_cf6458;	// NOTE: placeholder name
extern int value92_cf6474;	// NOTE: placeholder name
extern int value92_cf645c;	// NOTE: placeholder name

class HProp
{
public:
	int ID;
};

class BS
{
public:
	vector< vector<HProp> > &unknown463be0();	// NOTE: placeholder name
	vector<int> &unknown463b30();				// NOTE: placeholder name
};
extern BS *world92_cefc4c;	// NOTE: placeholder name

class Group92	// NOTE: placeholder name
{
public:
	int getType();	// NOTE: placeholder name (folded getter)
};

class HGroup
{
	int ID;
public:
	Group92 *operator->() const;	// NOTE: folded (OpC_Handle::get230)
};

class Entity
{
public:
	HGroup getGroup();
};

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
};

struct Order92	// NOTE: placeholder name and layout
{
	int		type;
	int		unknown04;
	bool	done;
};

struct Squad92	// NOTE: placeholder name and layout
{
	char				pad00[0x10];
	bool				unknown10;
	char				pad11[0x18 - 0x11];
	vector<Order92 *>	orders;		// +0x18
	char				pad28[0x40 - 0x28];
	vector<int>			unknown40;	// +0x40
	char				pad50[0x60 - 0x50];
	vector<int>			unknown60;	// +0x60
	HEntity				leader;		// +0x70
};

class Owner92	// NOTE: placeholder name
{
public:
	int unknown65c1f0(Squad92 *squad, int mode);	// NOTE: placeholder name
};

int Owner92::unknown65c1f0(Squad92 *squad, int mode)
{
	for (unsigned int i = 0; i < squad->orders.size(); i++)
	{
		if (squad->orders[i]->type == 5 && !squad->orders[i]->done)
			return 5;
	}
	if (flag92_cf6458 && mode != 1)
	{
		for (unsigned int j = 0; j < squad->orders.size(); j++)
		{
			if (squad->orders[j]->type == 6 && !squad->orders[j]->done)
				return 6;
		}
	}
	if (location92_d1e888->type == 0x22 && mode != 1)
	{
		for (unsigned int k = 0; k < squad->orders.size(); k++)
		{
			if (squad->orders[k]->type == 0x31 && !squad->orders[k]->done)
				return 0x31;
		}
	}
	if (squad->unknown10)
		return 0x70;
	if (gameData92_d1e860.unknown46f4b0(1) && location92_d1e888->type != 0x23)
	{
		switch (mode)
		{
		case 0:
			{
				if (squad->leader.operator->() && squad->leader->getGroup()->getType() == 3 && !OpX5_containsRecord(squad->unknown40,1))
					return 0x38;
				if (world92_cefc4c->unknown463be0()[2].empty() && !OpX5_containsRecord(squad->unknown40,2))
					return 0x39;
				if (opr1c_getThresholdIndex(threat92_cf6428) >= 2 && rng.chance(50) && value92_cf6474 == 0 && value92_cf645c == 0)
					return 0x12;
				if (rng.chance(50) && location92_d1e888->type != 0x22)
				{
					vector<int> types;
					types.push_back(4);
					types.push_back(5);
					types.push_back(6);
					types.push_back(7);
					OpS8c_shuffle(types);
					for (unsigned int m = 0; m < types.size(); m++)
					{
						if (entryList92_cf6428.countParties(types[m]))
							return types[m] + 0x1f;
					}
				}
				OpR5h_WL<int> wl;
				if (!OpX5_containsRecord(squad->unknown60,0x2a))
					wl.add(0x2a,0xf);
				if (!OpX5_containsRecord(squad->unknown60,0x13))
					wl.add(0x13,0xf);
				if (world92_cefc4c->unknown463b30()[7] == 0)
					wl.add(7,0x14);
				if (world92_cefc4c->unknown463b30()[8] == 0)
					wl.add(8,0xf);
				if (world92_cefc4c->unknown463b30()[9] == 0)
					wl.add(9,5);
				if (world92_cefc4c->unknown463b30()[0xb] == 0)
					wl.add(0xb,0xf);
				if (world92_cefc4c->unknown463b30()[0x10] == 0)
					wl.add(0x10,5);
				if (!OpX5_containsRecord(squad->unknown40,2) && world92_cefc4c->unknown463be0()[2].size() < 2)
					wl.add(0x39,0xa);
				if (wl.size())
					return wl.pick();
			}
			break;
		case 1:
			if (opr1c_getThresholdIndex(threat92_cf6428) >= 1 && value92_cf6474 == 0 && value92_cf645c == 0)
				return 0x12;
			if (location92_d1e888->type != 0x22)
			{
				vector<int> types2;
				types2.push_back(4);
				types2.push_back(5);
				types2.push_back(6);
				types2.push_back(7);
				OpS8c_shuffle(types2);
				for (unsigned int n = 0; n < types2.size(); n++)
				{
					if (entryList92_cf6428.countParties(types2[n]))
						return types2[n] + 0x1f;
				}
			}
			break;
		}
	}
	return 0x70;
}
