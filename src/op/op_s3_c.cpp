// op_s3_c: functions in 0x653000-0x667000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
#include "../util/rng.h"
#include "../game/penetrationrollpool.h"
using namespace std;

extern RNG rng;	// NOTE: placeholder name (0xd30908)

struct Point
{
	int x;
	int y;

	Point();
	Point(const Point &p);
	Point &operator=(const Point &p);
	void set(int x_, int y_);
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
};

class HProp
{
	int	ID;
public:
	HProp();
};

struct OpS3c_TerrainBase	// NOTE: placeholder name
{
	int		pad00[8];
	int		resists[7];
	char	pad3c[0x4c - 0x3c];
	bool	unknown4c;
};

struct OpS3c_PropData	// NOTE: placeholder name
{
	char				pad00[0x60];
	OpS3c_TerrainBase	*base;
	char				pad64[0x70 - 0x64];
	int					armor;
};

struct OpS3c_Attack	// NOTE: placeholder name
{
	char	pad00[0x68];
	int		damage;
	int		type;
};

struct OpS3c_Actor	// NOTE: placeholder name
{
	char	pad00[0x174];
	string	name;
};

bool opS3c_logMessage(int id, const string &text, const string &b, int c, HEntity d, HEntity e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)

class OpS3c_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpS3c_MsgConsole *opS3c_msgConsole;	// NOTE: placeholder name (0xcec058)

class OpS3c_LogMsgs	// NOTE: placeholder name (CLogMsgs)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpS3c_LogMsgs *opS3c_logMsgs;	// NOTE: placeholder name (0xcec0b4)
extern OpS3c_LogMsgs *opS3c_logMsgs2;	// NOTE: placeholder name (0xcec0c4)

extern PenetrationRollPool opS3c_rollPool;	// NOTE: placeholder name (0xd2c41c)
extern int opS3c_debugLevel;	// NOTE: placeholder name (0xd28d18)

class OpS3c_World	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	HEntity getUnknown45d250();	// NOTE: placeholder name
	void unknown465800(HProp p, HEntity e);	// NOTE: placeholder name
};
extern OpS3c_World *opS3c_world;	// NOTE: placeholder name (0xcefc4c)

struct OpS1c_Data;
struct OpQ5_U9d7de0
{
	int ID;
	string name;
};
extern vector<OpQ5_U9d7de0 *> OpR2D_d2c408;	// NOTE: placeholder name (0xd2c408)
template <class T> bool OpQ5_findByName(vector<T*> &v, string &name, T *&result);	// NOTE: placeholder name (0x9d7de0)
template <class T> void eraseAt(vector<T> &v, unsigned int *index);	// NOTE: placeholder name (0x9de640, steps index back)

struct OpW8_EntityEC	// NOTE: placeholder name (0x14 bytes)
{
	OpW8_EntityEC() throw();	// 0x456260

	char pad00[0x14];
};

struct OpQ5_T9d0160	// NOTE: placeholder name (record of an entity effect, 20 bytes)
{
	OpS1c_Data *getData();	// NOTE: placeholder name (0x9fcd80, folded getter)
};

struct OpS3c_Data	// NOTE: placeholder name
{
	char pad00[0x62];
	bool unknown62;
};

class OpS1c_RecList	// NOTE: placeholder name
{
public:
	~OpS1c_RecList();	// 0x458720 scalar deleting dtor
	bool hasData(OpS1c_Data *data);		// NOTE: placeholder name (0x4563e0)
	void add(OpS1c_Data *data);			// NOTE: placeholder name (0x456660)
	bool removeExpired();				// NOTE: placeholder name (0x456860)
	vector<OpQ5_T9d0160*> *getList();	// NOTE: placeholder name (0x9c0790)

	vector<OpQ5_T9d0160*> records;
	int turn;
};

class Prop
{
public:
	void unknown665b10(OpQ5_U9d7de0 *type, bool flag);	// NOTE: placeholder name
	bool unknown665b90(string &name, bool flag);		// NOTE: placeholder name
	bool unknown665be0(bool flag);					// NOTE: placeholder name
	void unknown665cb0();							// NOTE: placeholder name

	HProp handle;						// +0x00
	OpS3c_PropData *data;				// +0x04
	Point position;						// +0x08
	char pad10[0x30 - 0x10];
	OpS1c_RecList *effects;				// +0x30

	void unknown65f520(int a, int b, int c, int d, int e, HProp f, int g, int h, int i);	// NOTE: placeholder name
	void unknown665860(OpS3c_Attack *attack);						// NOTE: placeholder name
	bool unknown6658d0(int a, int b, OpS3c_Actor *actor);				// NOTE: placeholder name
	const string &unknown45c5b0();									// NOTE: placeholder name
	int unknown665a70(int id, int amount);							// NOTE: placeholder name
};

void Prop::unknown665b10(OpQ5_U9d7de0 *type, bool flag)
{
	if (effects == NULL)
	{
		OpW8_EntityEC *created = new OpW8_EntityEC();
		effects = (OpS1c_RecList *)created;
	}
	else if (!flag && effects->hasData((OpS1c_Data *)type))
	{
		return;
	}
	effects->add((OpS1c_Data *)type);
}

bool Prop::unknown665b90(string &name, bool flag)
{
	OpQ5_U9d7de0 *type;
	if (OpQ5_findByName(OpR2D_d2c408,name,type))
	{
		unknown665b10(type,flag);
		return true;
	}
	return false;
}

bool Prop::unknown665be0(bool flag)
{
	if (effects != NULL)
	{
		if (flag)
		{
			vector<OpQ5_T9d0160*> *list = effects->getList();
			for (unsigned int i = 0; i < list->size(); i++)
			{
				if (!((OpS3c_Data *)(*list)[i]->getData())->unknown62)
				{
					eraseAt(*list,&i);
				}
			}
			if (!list->empty())
			{
				return false;
			}
		}
		delete effects;
		effects = NULL;
	}
	return true;
}

void Prop::unknown665cb0()
{
	if (effects != NULL && effects->removeExpired())
	{
		delete effects;
		effects = NULL;
	}
}

void Prop::unknown665860(OpS3c_Attack *attack)
{
	int resist;
	if (attack->type >= 7)
		resist = 100;
	else
		resist = data->base->resists[attack->type];
	unknown65f520(attack->damage * resist / 100, attack->type, 0, 0, 0, HProp(), 0, 0, 0);
}

bool Prop::unknown6658d0(int a, int b, OpS3c_Actor *actor)
{
	if (data->armor == -1)
		return false;
	if (b == -1 || (a == -1 ? opS3c_rollPool.nextValue() : opS3c_rollPool.peekValue(a)) <= b)
	{
		if (a == -1)
		{
			do
			{
				if (opS3c_logMessage(0x195, actor->name, unknown45c5b0(), 0, HEntity(), HEntity(), &position, 0))
					opS3c_msgConsole->unknown8758d0(true);
				opS3c_logMsgs->scrollToEnd();
			} while (0);
			if (opS3c_debugLevel >= 0)
			{
				do
				{
					if (opS3c_logMessage(0x2d3, actor->name, unknown45c5b0(), 0, HEntity(), HEntity(), &position, 1))
						opS3c_msgConsole->unknown8758d0(false);
					opS3c_logMsgs2->scrollToEnd();
				} while (0);
			}
			if (data->base->unknown4c && rng.chance(50) && unknown665a70(12, 1) >= 3)
				opS3c_world->unknown465800(handle, opS3c_world->getUnknown45d250());
		}
		return true;
	}
	else
		return false;
}
