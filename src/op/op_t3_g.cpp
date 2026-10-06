// op_t3_g: Plan / spawn-record functions (0x672000-0x674000) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member/method names are placeholders unless named in config/.
#include <string>
#include <vector>
#include <istream>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// NOTE: placeholder name (0xd30908)

class Entity;
class EntityAI
{
public:
	int unknownValue();	// NOTE: placeholder name (0x45b590 chain)
};

class HEntity
{
	int	ID;
public:
	HEntity() throw();
	Entity *operator->() const;
};

class Entity
{
public:
	EntityAI *getAI();	// NOTE: placeholder name (0x45b590)
};

class Map
{
public:
	int getTurn();	// 0x464270
	bool unknown463400(HEntity e);	// NOTE: placeholder name
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)

struct OpT3g_Brain	// NOTE: placeholder layout
{
	char pad000[0x110];
	int level;
};
extern OpT3g_Brain *opT3g_brain;	// NOTE: placeholder name (0xcf68b4)

struct MapRecord	// NOTE: placeholder layout
{
	char pad00[0x20];
	vector<int> chances;
	vector<int> cooldowns;
	vector<vector<string> > names;
};
extern vector<MapRecord *> opT3g_records;	// NOTE: placeholder name (0xd39458)

template <class T> class OpS8a_Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *cells;
	OpS8a_Array2D();
	~OpS8a_Array2D();
	void fill(int value);	// NOTE: placeholder name (0x9cf020)
	void resize(int width_, int height_, istream *stream);
	T &operator()(int x, int y);	// 0x9ceda0
};

class OpS4_Plan	// NOTE: placeholder name
{
public:
	int								turn;
	OpS8a_Array2D<int>				lastTurns;
	vector<vector<vector<int> > >	names;

	OpS4_Plan();	// 0x672c40
	bool unknown672dd0(HEntity e, int type);	// NOTE: placeholder name
};

OpS4_Plan::OpS4_Plan()
{
	turn = 0;
	lastTurns.resize(20,10,NULL);
	lastTurns.fill(0);
	names.assign(20,vector<vector<int> >());
	for (int i = 0; i < 20; i++)
	{
		names[i].assign(10,vector<int>());
		for (int j = 0; j < 10; j++)
			names[i][j].assign(opT3g_records[i]->names[j].size(),0);
	}
}

bool OpS4_Plan::unknown672dd0(HEntity e, int type)
{
	if (type != 4 && e->getAI()->unknownValue() == 23)
		return false;
	if (turn != 0 && world->getTurn() < turn + 6)
		return false;
	MapRecord *record = opT3g_records[type];
	int level = opT3g_brain->level;
	if ((lastTurns(type,level) != 0 && (record->cooldowns[level] <= 0 || world->getTurn() - lastTurns(type,level) < record->cooldowns[level])) || (record->chances[level] != 0 && !rng.chance(record->chances[level])))
		return false;
	if (type == 15)
	{
		return !world->unknown463400(e);
	}
	else
	{
		return world->unknown463400(e);
	}
}
