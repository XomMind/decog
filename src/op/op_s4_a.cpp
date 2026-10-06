// op_s4_a: functions in 0x691000-0x6a0000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	bool operator==(HEntity other) const;	// 0x9b78e0
};

struct OpS4_LocationInfo	// NOTE: placeholder name
{
	char pad00[4];
	int depthIndex;
};

class OpS4_HLocation	// NOTE: placeholder name (object at 0xd1e888)
{
public:
	int ID;
	bool operator==(HEntity other) const;	// 0x9b78e0
	OpS4_LocationInfo *operator->() const;	// 0x9b7910
};

extern bool opS4_cefb2a;	// NOTE: placeholder name
extern int opS4_cf645c;	// NOTE: placeholder name
extern int opS4_cf6474;	// NOTE: placeholder name
extern int opS4_cf65a4;	// NOTE: placeholder name
extern bool opS4_cf4a00;	// NOTE: placeholder name
extern HEntity opS4_d1ebd8;	// NOTE: placeholder name
extern HEntity opS4_d1ebe0;	// NOTE: placeholder name
extern OpS4_HLocation opS4_location;	// NOTE: placeholder name (0xd1e888)
extern int opS4_ba4fc8[];	// NOTE: placeholder name
extern int opS4_ba4ca8[][5];	// NOTE: placeholder name

class OpS4_A	// NOTE: placeholder name
{
public:
	bool unknown6997f0(int type);	// NOTE: placeholder name
};

bool OpS4_A::unknown6997f0(int type)
{
	if (opS4_cefb2a)
	{
		return false;
	}
	if (opS4_cf645c || opS4_cf6474 || opS4_cf65a4 || opS4_location == opS4_d1ebd8 || opS4_location == opS4_d1ebe0 || opS4_cf4a00)
	{
		return true;
	}
	if (type != 10 && opS4_ba4ca8[opS4_location->depthIndex][opS4_ba4fc8[type]] < 2)
	{
		return true;
	}
	return false;
}

void opS4_unknown9cdc50(int low, int &value, int high);	// NOTE: placeholder name

class OpS4_Tally	// NOTE: placeholder name
{
public:
	vector<int> total;
	vector<int> recent;

	void unknown6998a0(unsigned int index, int amount, bool set);	// NOTE: placeholder name
};

void OpS4_Tally::unknown6998a0(unsigned int index, int amount, bool set)
{
	if (set)
	{
		total[index] = amount;
		recent[index] = 0;
	}
	else
	{
		total[index] += amount;
		opS4_unknown9cdc50(0, total[index], 9999);
		recent[index] += amount;
		opS4_unknown9cdc50(0, recent[index], 9999);
	}
}

class OpS4_AI	// NOTE: placeholder layout
{
public:
	int getBehavior();	// NOTE: placeholder name (0x459xxx)
	int getMode();	// NOTE: placeholder name
	void setMode(int mode);	// NOTE: placeholder name
	bool unknown458eb0();	// NOTE: placeholder name
	void unknown459640();	// NOTE: placeholder name
	bool unknown580c10();	// NOTE: placeholder name
};

class OpS4_Entity;
class OpS4_HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	OpS4_Entity *operator->() const;	// 0x9b6570
	void reset();	// 0x9b7270
	bool isValid() const;	// NOTE: placeholder name (folded 0x9b6xxx)
};

struct OpS4_Op45	// NOTE: placeholder name
{
	char pad00[8];
	void operate();	// NOTE: placeholder name (0x45f0a0)
};

struct OpS4_Op409	// NOTE: placeholder name
{
	char pad00[8];
	void operate(int value);	// NOTE: placeholder name (0x409ff0)
};

class OpS4_Entity	// NOTE: placeholder layout
{
public:
	OpS4_AI *getAI();	// NOTE: placeholder name (0x45b590)
	bool unknown5d5320();	// NOTE: placeholder name
	void unknown637a50();	// NOTE: placeholder name
	bool isHostileTo(OpS4_HEntity e);	// 0x45aa70
};

class OpS4_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	bool unknown716250(OpS4_HEntity e, int rating, string *reason);	// NOTE: placeholder name
};
extern OpS4_Map *opS4_map;	// NOTE: placeholder name (0xcefc4c)

bool opS4_unknown9db330(vector<int> &list, int arg);	// NOTE: placeholder name
void opS4_unknown9da310(vector<int> &list, int arg, vector<unsigned int> *out);	// NOTE: placeholder name
int opS4_unknown9d5d00(vector<unsigned int> *list);	// NOTE: placeholder name
void opS4_unknown4351e0(string &name);	// NOTE: placeholder name
extern vector<vector<string> > opS4_names_d21b10;	// NOTE: placeholder name

class OpR3d_InventoryHold	// NOTE: placeholder name
{
public:
	OpR3d_InventoryHold(int id);	// NOTE: placeholder name (0x690810)
	char pad00[0x18];
};

class OpS4_Stats	// NOTE: placeholder name
{
public:
	void add472b90(unsigned int id, int value);	// NOTE: placeholder name
};
extern OpS4_Stats opS4_stats;	// NOTE: placeholder name (0xd2c658)

class OpS4_Plan	// NOTE: placeholder name
{
public:
	OpS4_Plan();	// NOTE: placeholder name (0x672c40)
	char pad00[0x20];
};

class OpS4_GM	// NOTE: placeholder name
{
public:
	void unknown7929d0();	// NOTE: placeholder name
};
extern OpS4_GM *opS4_gm;	// NOTE: placeholder name (0xcefaa8)
extern vector<int> opS4_vec_d39458;	// NOTE: placeholder name

struct OpS4_Brain	// NOTE: placeholder layout
{
	char pad000[0x110];
	int state;
};

class OpS4_Unit	// NOTE: placeholder name
{
public:
	char pad00[0x2c];
	OpS4_Brain *brain;
	OpS4_HEntity self;
	OpR3d_InventoryHold *hold;
	char pad38[8];
	int flag40;
	char pad44[0x24];
	OpS4_Plan *plan;
	char pad6c[0xd4 - 0x6c];
	OpS4_Op45 opD4;
	char padDC[0xf4 - 0xdc];
	OpS4_Op45 opF4;
	OpS4_HEntity handleFC;
	char pad100[0x120 - 0x100];
	OpS4_HEntity handle120;
	char pad124[0x134 - 0x124];
	OpS4_Op45 op134;
	OpS4_Op409 op13C;
	char pad144[0x21c - 0x144];
	vector<vector<int> > flagLists;

	void unknown699c20();	// NOTE: placeholder name
	int unknown69b8a0(int index);	// NOTE: placeholder name
	int unknown69b9b0(vector<string> &names, vector<int> &flags);	// NOTE: placeholder name
	bool unknown69ba80(OpS4_HEntity e);	// NOTE: placeholder name
	void unknown69a0a0(bool flag);	// NOTE: placeholder name
	void unknown69a5b0(bool flag);	// NOTE: placeholder name
	void unknown699720(OpS4_Brain *brain_, bool flag);	// NOTE: placeholder name
	void unknown699960();	// NOTE: placeholder name

	void unknown699a00(bool flag);	// NOTE: placeholder name
	void unknown699e20();	// NOTE: placeholder name
};

void OpS4_Unit::unknown699e20()
{
	if (self->getAI()->getBehavior() == 0x17 && self->getAI()->getMode() == 4)
	{
		return;
	}
	if (self->unknown5d5320())
	{
		if (self->getAI()->getBehavior() != 0x17)
		{
			do {} while (0);
			unknown699a00(true);
		}
		if (self->getAI()->getMode() != 4)
		{
			self->getAI()->setMode(4);
			if (self->getAI()->unknown458eb0())
			{
				self->getAI()->unknown459640();
			}
			do {} while (0);
		}
	}
}

void OpS4_Unit::unknown699720(OpS4_Brain *brain_, bool flag)
{
	brain = brain_;
	flag40 = 1;
	if (flag)
	{
		opS4_stats.add472b90(0x1b, -999999);
	}
	if (plan == NULL)
	{
		if (opS4_vec_d39458.empty())
		{
			opS4_gm->unknown7929d0();
		}
		plan = new OpS4_Plan();
	}
}

void OpS4_Unit::unknown699960()
{
	self->unknown637a50();
	hold = new OpR3d_InventoryHold(self.ID);
	self.reset();
}

void OpS4_Unit::unknown699c20()
{
	if (brain == NULL)
	{
		return;
	}
	switch (brain->state)
	{
	case 0:
		if (self.isValid())
		{
			unknown699a00(false);
		}
		break;
	case 1:
		if (hold)
		{
			opD4.operate();
		}
		else
		{
			if (self.isValid())
			{
				unknown699a00(false);
			}
		}
		break;
	case 2:
		if (handleFC.isValid())
		{
			unknown69a0a0(false);
		}
		if (handle120.isValid())
		{
			unknown69a5b0(false);
		}
		if (hold)
		{
			opF4.operate();
		}
		do {} while (0);
		break;
	case 3:
		if (hold)
		{
			op134.operate();
			op13C.operate(-1);
		}
		else
		{
			if (self.isValid())
			{
				unknown699a00(false);
			}
		}
		break;
	case 4:
		if (self.isValid())
		{
			unknown699a00(false);
		}
		break;
	case 5:
		if (self.isValid())
		{
			unknown699a00(false);
		}
		break;
	case 6:
		if (self.isValid())
		{
			unknown699a00(false);
		}
		break;
	case 7:
		if (self.isValid())
		{
			unknown699a00(false);
		}
		break;
	case 8:
		if (self.isValid())
		{
			unknown699a00(false);
		}
		break;
	}
}

int OpS4_Unit::unknown69b8a0(int index)
{
	if (!opS4_unknown9db330(flagLists[index], 0))
	{
		return -1;
	}
	vector<unsigned int> list;
	opS4_unknown9da310(flagLists[index], 0, &list);
	int pick = opS4_unknown9d5d00(&list);
	flagLists[index][pick] = 1;
	opS4_unknown4351e0(opS4_names_d21b10[index][pick]);
	return pick;
}

int OpS4_Unit::unknown69b9b0(vector<string> &names, vector<int> &flags)
{
	if (!opS4_unknown9db330(flags, 0))
	{
		return -1;
	}
	vector<unsigned int> list;
	opS4_unknown9da310(flags, 0, &list);
	int pick = opS4_unknown9d5d00(&list);
	flags[pick] = 1;
	opS4_unknown4351e0(names[pick]);
	return pick;
}

bool OpS4_Unit::unknown69ba80(OpS4_HEntity e)
{
	return (e->isHostileTo(self) || !e->getAI()->unknown580c10()) && opS4_map->unknown716250(e, 100, NULL);
}
