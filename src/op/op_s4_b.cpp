// op_s4_b: functions in 0x69e000-0x6a0000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <stdlib.h>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
	Point();	// 0x453b40
};

struct Area	// NOTE: placeholder name
{
	Area();	// 0x40b100
	Point min;
	Point max;
};

int distanceCeil(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
int minInt(int a, int b) throw();	// 0x9cdb30
int opS4_clamp9cdc80(int low, int value, int high);	// NOTE: placeholder name (0x9cdc80)
void opS4_unknown9d06d0(int *value, int delta, int limit);	// NOTE: placeholder name (0x9d06d0)

class OpS4_Entity;
class OpS4_HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	OpS4_Entity *operator->() const;	// 0x9b6570
};

class OpS4_HProp	// NOTE: placeholder layout
{
public:
	int ID;
	OpS4_HProp();
};

class OpS4_Item	// NOTE: placeholder layout
{
public:
	int unknown457f90();	// NOTE: placeholder name
	bool unknown457d70();	// NOTE: placeholder name
	int unknown457920();	// NOTE: placeholder name (0x457920)
	int unknown4578a0();	// NOTE: placeholder name (0x4578a0)
	int unknown577af0();	// NOTE: placeholder name
	struct OpS4_ItemData *getData();	// NOTE: placeholder name
};

struct OpS4_ItemData	// NOTE: placeholder layout
{
	char pad00[0x54];
	int unknown54;
};

class OpS4_HItem	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	OpS4_Item *operator->() const;	// 0x9b65b0
};

class OpS4_Cell	// NOTE: placeholder layout
{
public:
	OpS4_HItem getItem();	// NOTE: placeholder name
};

template <class T>
class OpS4_Array2D	// NOTE: placeholder name
{
public:
	T &operator()(int x, int y);	// 0x9ceda0
	void getRect(const Point &p, int radius, Area &out);	// NOTE: placeholder name (0x9b4430)
};
extern OpS4_Array2D<OpS4_Cell *> opS4_cells;	// NOTE: placeholder name (0xcfd44c)

class OpS4_Entity	// NOTE: placeholder layout
{
public:
	const Point &getPosition();	// 0x45a4a0
	bool unknown5d2a00(int type);	// NOTE: placeholder name
	int unknown5d15a0(int a);	// NOTE: placeholder name
};

class OpS4_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	OpS4_HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
	int getTurn();	// 0x464270
	int unknown4642f0();	// NOTE: placeholder name
	bool isVisible(const Point &p);	// NOTE: placeholder name (0x4631c0)
	int unknown7151c0();	// NOTE: placeholder name
	int unknown714b50();	// NOTE: placeholder name
};
extern OpS4_Map *opS4_map;	// NOTE: placeholder name (0xcefc4c)

class OpS4_Stats	// NOTE: placeholder name
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
};
extern OpS4_Stats opS4_stats;	// NOTE: placeholder name (0xd2c658)

struct OpS4_Expiry	// NOTE: placeholder name
{
	int first;
	int second;
	void set(int first_, int second_);	// NOTE: placeholder name (0x690d40)
};

struct OpS4_Pair	// NOTE: placeholder name
{
	int count;
	int unknownAC;
	void reset();	// NOTE: placeholder name (0x45fac0)
};

struct OpS4_Flags	// NOTE: placeholder name (object at 0xd1e860)
{
	void set(const string &name, const string &value);	// NOTE: placeholder name (0x46f700)
};
extern OpS4_Flags opS4_flags;	// NOTE: placeholder name (0xd1e860)

struct OpS4_GameState	// NOTE: placeholder name
{
	int unknown04;
	int getDepthIndex();	// NOTE: placeholder name
};

class OpS4_HGameState	// NOTE: placeholder name (object at 0xd1e888)
{
public:
	int ID;
	OpS4_GameState *operator->() const;	// 0x9b7910
};
extern OpS4_HGameState opS4_gameState;	// NOTE: placeholder name (0xd1e888)

extern int opS4_bbad00[];	// NOTE: placeholder name
extern int opS4_bbaaf8[];	// NOTE: placeholder name
extern int opS4_bbaf08[];	// NOTE: placeholder name
extern int opS4_bbaf74[];	// NOTE: placeholder name
extern string opS4_messages_d2d1d8[];	// NOTE: placeholder name

class OpS4_HEntityTmp	// NOTE: placeholder name
{
public:
	int ID;
	OpS4_HEntityTmp();
};
class OpS4_HPropTmp	// NOTE: placeholder name
{
public:
	int ID;
	OpS4_HPropTmp();
};

bool opS4_showMessage(int type, const string &text, int a, int b, OpS4_HEntityTmp entity, OpS4_HPropTmp prop, int c, int d);	// 0x5111e0
void opS4_message(int type, OpS4_HEntityTmp entity, const string &text, int value);	// NOTE: placeholder name (opW5_message)

class OpS4_Messages	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(int flag);	// NOTE: placeholder name
};
extern OpS4_Messages *opS4_messages;	// NOTE: placeholder name (0xcec058)

class OpS4_LogMsgs	// NOTE: placeholder name (CLogMsgs at 0xcec0b4)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpS4_LogMsgs *opS4_logMsgs;	// NOTE: placeholder name (0xcec0b4)

class OpS4_RolledValues	// NOTE: placeholder name
{
public:
	bool say(int ID, bool force, string name);	// 0x49e250
};
extern OpS4_RolledValues *opS4_rolledValues;	// NOTE: placeholder name (0xcefb48)

class OpS4_Xom	// NOTE: placeholder name
{
public:
	bool active;
	char pad01[0x0f];
	int unknown10;	// NOTE: placeholder name
	int unknown14;	// NOTE: placeholder name
	OpS4_Expiry expiry;
	vector<int> times;
	vector<int> types;
	vector<int> turnLog;
	vector<int> amounts;
	vector<int> levels;
	char pad70[0x94 - 0x70];
	int unknown94;	// NOTE: placeholder name
	char pad98[0xa8 - 0x98];
	OpS4_Pair pair;
	char padB0[0x1d0 - 0xb0];
	bool unknown1D0;	// NOTE: placeholder name

	void unknown69e450();	// NOTE: placeholder name
	bool unknown69e530();	// NOTE: placeholder name
	bool unknown69e680(int type);	// NOTE: placeholder name
	int unknown69e700(int type, int level, float mult);	// NOTE: placeholder name
	void unknown69ea20(bool flag);	// NOTE: placeholder name
	bool unknown69eba0(OpS4_HItem item);	// NOTE: placeholder name
	void unknown69ecb0(int type);	// NOTE: placeholder name
	void unknown69e900();	// NOTE: placeholder name
	bool unknown69e9b0(const Point &p);	// NOTE: placeholder name
	int unknown69ed90();	// NOTE: placeholder name
	bool unknown69edf0();	// NOTE: placeholder name
};

void OpS4_Xom::unknown69e450()
{
	active = true;
	expiry.set(0x28,0x14);
	opS4_stats.add4729d0(0x3b8,unknown14,string(""),-1);
	string a("1");
	string b("followingXom_g");
	opS4_flags.set(b,a);
}

bool OpS4_Xom::unknown69e530()
{
	if (opS4_map->getPlayer()->unknown5d2a00(0xda))
	{
		return false;
	}
	Area area;
	opS4_cells.getRect(opS4_map->getPlayer()->getPosition(),30,area);
	for (int x = area.min.x; x <= area.max.x; x++)
	{
		for (int y = area.min.y; y <= area.max.y; y++)
		{
			if (opS4_cells(x,y)->getItem().isValid() && opS4_cells(x,y)->getItem()->unknown457f90() == 0xda && opS4_cells(x,y)->getItem()->unknown457d70())
			{
				return false;
			}
		}
	}
	return true;
}

bool OpS4_Xom::unknown69e680(int type)
{
	return times[type] != 0 && (opS4_bbad00[type] == -1 || (opS4_bbad00[type] > 0 && opS4_map->getTurn() - times[type] < opS4_bbad00[type]));
}

void OpS4_Xom::unknown69e900()
{
	if (pair.count > 3)
	{
		unknown69e700(0x22,(pair.count <= 7) ? 0 : 2,0.0f);
		pair.unknownAC = 0;
	}
	if (pair.unknownAC >= 6)
	{
		unknown69e700(0x24,(pair.unknownAC >= 12) ? ((pair.unknownAC >= 18) ? 2 : 1) : 0,0.0f);
	}
	pair.reset();
}

bool OpS4_Xom::unknown69e9b0(const Point &p)
{
	return opS4_map->isVisible(p) || distanceCeil(opS4_map->getPlayer()->getPosition(),p) <= 20;
}

int OpS4_Xom::unknown69ed90()
{
	return opS4_clamp9cdc80(0,abs(unknown10 - 100) / 2 + opS4_map->unknown714b50() + unknown14 / 2,100) * 20 / 100 + 5;
}

bool OpS4_Xom::unknown69edf0()
{
	if (unknown1D0)
	{
		unknown1D0 = false;
		return true;
	}
	return rng.chance(unknown69ed90());
}

int OpS4_Xom::unknown69e700(int type, int level, float mult)
{
	if (unknown69e680(type))
	{
		do {} while (0);
		return 6;
	}
	int amount = (int)(opS4_bbaaf8[type] * ((level == 3) ? mult : (float)opS4_bbaf08[level]));
	opS4_stats.add4729d0(0x3b8,minInt(amount,100 - unknown14),string(""),-1);
	opS4_unknown9d06d0(&unknown14,amount,100);
	times[type] = opS4_map->getTurn();
	for (int i = 5; i >= 0; i--)
	{
		if (amount >= opS4_bbaf74[i])
		{
			if (type < 0x7a)
			{
				do
				{
					if (opS4_showMessage(0x2b4,opS4_messages_d2d1d8[i],0,0,OpS4_HEntityTmp(),OpS4_HPropTmp(),0,0))
					{
						opS4_messages->unknown8758d0(1);
					}
					opS4_logMsgs->scrollToEnd();
				} while (false);
				if (opS4_rolledValues)
				{
					opS4_rolledValues->say(0x3c,false,string(""));
				}
			}
			types.push_back(type);
			turnLog.push_back(opS4_map->getTurn());
			amounts.push_back(amount);
			levels.push_back(unknown14);
			do {} while (0);
			return i;
		}
	}
	return 6;
}

extern OpS4_Xom opS4_xom;	// NOTE: placeholder name (0xd25450)

void OpS4_Xom::unknown69ea20(bool flag)
{
	if (opS4_xom.active && flag && opS4_map->unknown4642f0() < 500 && !unknown69e680(2) && !opS4_map->getPlayer()->unknown5d2a00(0x97))
	{
		bool itemFound = false;
		Area area;
		opS4_cells.getRect(opS4_map->getPlayer()->getPosition(),15,area);
		for (int x = area.min.x; x <= area.max.x; x++)
		{
			for (int y = area.min.y; y <= area.max.y; y++)
			{
				if (opS4_cells(x,y)->getItem().isValid() && opS4_cells(x,y)->getItem()->unknown457f90() == 0x97)
				{
					itemFound = true;
					break;
				}
			}
		}
		if (!itemFound)
		{
			opS4_xom.unknown69e700(2,0,0.0f);
		}
	}
}

bool OpS4_Xom::unknown69eba0(OpS4_HItem item)
{
	if (item->unknown457f90() == 0xda)
	{
		return false;
	}
	if (item->getData()->unknown54 == 0 || item->unknown457920() >= opS4_gameState->getDepthIndex() + 3)
	{
		return true;
	}
	if (item->unknown4578a0() == 2 && item->unknown457f90() != 0 && item->unknown577af0() >= 100 && !opS4_map->getPlayer()->unknown5d2a00(item->unknown457f90()))
	{
		return true;
	}
	return false;
}

void OpS4_Xom::unknown69ecb0(int type)
{
	int a = opS4_map->unknown7151c0();
	if (a > unknown94)
	{
		int b = opS4_map->getPlayer()->unknown5d15a0(0);
		if (type == 0x38 && b < 0x50)
		{
			return;
		}
		int limit = -1;
		switch (type)
		{
		case 0x37:
		case 0x39:
			limit = 0x50;
		case 0x3a:
		case 0x3b:
			limit = 0x64;
		}
		unknown69e700(type,limit != -1 && b >= limit,0.0f);
	}
}
