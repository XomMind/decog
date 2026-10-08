// NOTE: private nothrow aliases for 0x69e700; old source remains unchanged.
// op_s4_b: functions in 0x69e000-0x6a0000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <stdlib.h>
struct LB2X_RNG;
using namespace std;

extern LB2X_RNG lb2x_rng;	// 0xd30908

struct LB2X_Point	// NOTE: placeholder layout
{
	int x;
	int y;
	LB2X_Point() throw();	// 0x453b40
};

struct LB2X_Area	// NOTE: placeholder name
{
	LB2X_Area() throw();	// 0x40b100
	LB2X_Point min;
	LB2X_Point max;
};

int LB2X_distanceCeil(const LB2X_Point &a, const LB2X_Point &b) throw();	// NOTE: placeholder name (0x40a3f0)
int LB2X_minInt(int a, int b) throw();	// 0x9cdb30
int lb2x_opS4_clamp9cdc80(int low, int value, int high) throw();	// NOTE: placeholder name (0x9cdc80)
void lb2x_opS4_unknown9d06d0(int *value, int delta, int limit) throw();	// NOTE: placeholder name (0x9d06d0)

class lb2x_OpS4_Entity;
class lb2x_OpS4_HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	lb2x_OpS4_Entity *operator->() const throw();	// 0x9b6570
};

class lb2x_OpS4_HProp	// NOTE: placeholder layout
{
public:
	int ID;
	lb2x_OpS4_HProp() throw();
};

class lb2x_OpS4_Item	// NOTE: placeholder layout
{
public:
	int unknown457f90() throw();	// NOTE: placeholder name
	bool unknown457d70() throw();	// NOTE: placeholder name
	int unknown457920() throw();	// NOTE: placeholder name (0x457920)
	int unknown4578a0() throw();	// NOTE: placeholder name (0x4578a0)
	int unknown577af0() throw();	// NOTE: placeholder name
	struct lb2x_OpS4_ItemData *getData() throw();	// NOTE: placeholder name
};

struct lb2x_OpS4_ItemData	// NOTE: placeholder layout
{
	char pad00[0x54];
	int unknown54;
};

class lb2x_OpS4_HItem	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const throw();
	lb2x_OpS4_Item *operator->() const throw();	// 0x9b65b0
};

class lb2x_OpS4_Cell	// NOTE: placeholder layout
{
public:
	lb2x_OpS4_HItem getItem() throw();	// NOTE: placeholder name
};

template <class T>
class lb2x_OpS4_Array2D	// NOTE: placeholder name
{
public:
	T &operator()(int x, int y) throw();	// 0x9ceda0
	void getRect(const LB2X_Point &p, int radius, LB2X_Area &out) throw();	// NOTE: placeholder name (0x9b4430)
};
extern lb2x_OpS4_Array2D<lb2x_OpS4_Cell *> lb2x_opS4_cells;	// NOTE: placeholder name (0xcfd44c)

class lb2x_OpS4_Entity	// NOTE: placeholder layout
{
public:
	const LB2X_Point &getPosition() throw();	// 0x45a4a0
	bool unknown5d2a00(int type) throw();	// NOTE: placeholder name
	int unknown5d15a0(int a) throw();	// NOTE: placeholder name
};

class lb2x_OpS4_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	lb2x_OpS4_HEntity getPlayer() throw();	// NOTE: placeholder name (0x4630f0)
	int getTurn() throw();	// 0x464270
	int unknown4642f0() throw();	// NOTE: placeholder name
	bool isVisible(const LB2X_Point &p) throw();	// NOTE: placeholder name (0x4631c0)
	int unknown7151c0() throw();	// NOTE: placeholder name
	int unknown714b50() throw();	// NOTE: placeholder name
};
extern lb2x_OpS4_Map *lb2x_opS4_map;	// NOTE: placeholder name (0xcefc4c)

class lb2x_OpS4_Stats	// NOTE: placeholder name
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra) throw();	// NOTE: placeholder name (0x4729d0)
};
extern lb2x_OpS4_Stats lb2x_opS4_stats;	// NOTE: placeholder name (0xd2c658)

struct lb2x_OpS4_Expiry	// NOTE: placeholder name
{
	int first;
	int second;
	void set(int first_, int second_) throw();	// NOTE: placeholder name (0x690d40)
};

struct lb2x_OpS4_Pair	// NOTE: placeholder name
{
	int count;
	int unknownAC;
	void reset() throw();	// NOTE: placeholder name (0x45fac0)
};

struct lb2x_OpS4_Flags	// NOTE: placeholder name (object at 0xd1e860)
{
	void set(const string &name, const string &value) throw();	// NOTE: placeholder name (0x46f700)
};
extern lb2x_OpS4_Flags lb2x_opS4_flags;	// NOTE: placeholder name (0xd1e860)

struct lb2x_OpS4_GameState	// NOTE: placeholder name
{
	int unknown04;
	int unknown46ed20() throw();	// NOTE: placeholder name
};

class lb2x_OpS4_HGameState	// NOTE: placeholder name (object at 0xd1e888)
{
public:
	int ID;
	lb2x_OpS4_GameState *operator->() const throw();	// 0x9b7910
};
extern lb2x_OpS4_HGameState lb2x_opS4_gameState;	// NOTE: placeholder name (0xd1e888)

extern int lb2x_opS4_bbad00[];	// NOTE: placeholder name
extern int lb2x_opS4_bbaaf8[];	// NOTE: placeholder name
extern int lb2x_opS4_bbaf08[];	// NOTE: placeholder name
extern int lb2x_opS4_bbaf74[];	// NOTE: placeholder name
extern string lb2x_opS4_messages_d2d1d8[];	// NOTE: placeholder name

class lb2x_OpS4_HEntityTmp	// NOTE: placeholder name
{
public:
	int ID;
	lb2x_OpS4_HEntityTmp() throw();
};
class lb2x_OpS4_HPropTmp	// NOTE: placeholder name
{
public:
	int ID;
	lb2x_OpS4_HPropTmp() throw();
};

bool lb2x_opS4_showMessage(int type, const string &text, int a, int b, lb2x_OpS4_HEntityTmp entity, lb2x_OpS4_HPropTmp prop, int c, int d) throw();	// 0x5111e0
void lb2x_opS4_message(int type, lb2x_OpS4_HEntityTmp entity, const string &text, int value) throw();	// NOTE: placeholder name (opW5_message)

class lb2x_OpS4_Messages	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(int flag) throw();	// NOTE: placeholder name
};
extern lb2x_OpS4_Messages *lb2x_opS4_messages;	// NOTE: placeholder name (0xcec058)

class lb2x_OpS4_LogMsgs	// NOTE: placeholder name (CLogMsgs at 0xcec0b4)
{
public:
	void scrollToEnd() throw();	// 0x7b4f10
};
extern lb2x_OpS4_LogMsgs *lb2x_opS4_logMsgs;	// NOTE: placeholder name (0xcec0b4)

class lb2x_OpS4_RolledValues	// NOTE: placeholder name
{
public:
	bool say(int ID, bool force, string name) throw();	// 0x49e250
};
extern lb2x_OpS4_RolledValues *lb2x_opS4_rolledValues;	// NOTE: placeholder name (0xcefb48)

class LB2X_OpS4_Xom	// NOTE: placeholder name
{
public:
	bool active;
	char pad01[0x0f];
	int unknown10;	// NOTE: placeholder name
	int unknown14;	// NOTE: placeholder name
	lb2x_OpS4_Expiry expiry;
	vector<int> times;
	vector<int> types;
	vector<int> turnLog;
	vector<int> amounts;
	vector<int> levels;
	char pad70[0x94 - 0x70];
	int unknown94;	// NOTE: placeholder name
	char pad98[0xa8 - 0x98];
	lb2x_OpS4_Pair pair;
	char padB0[0x1d0 - 0xb0];
	bool unknown1D0;	// NOTE: placeholder name

	void unknown69e450() throw();	// NOTE: placeholder name
	bool unknown69e530() throw();	// NOTE: placeholder name
	bool unknown69e680(int type) throw();	// NOTE: placeholder name
	int unknown69e700(int type, int level, float mult);	// NOTE: placeholder name
	void unknown69ea20(bool flag) throw();	// NOTE: placeholder name
	bool unknown69eba0(lb2x_OpS4_HItem item) throw();	// NOTE: placeholder name
	void unknown69ecb0(int type) throw();	// NOTE: placeholder name
	void unknown69e900() throw();	// NOTE: placeholder name
	bool unknown69e9b0(const LB2X_Point &p) throw();	// NOTE: placeholder name
	int unknown69ed90() throw();	// NOTE: placeholder name
	bool unknown69edf0() throw();	// NOTE: placeholder name
};

int LB2X_OpS4_Xom::unknown69e700(int type, int level, float mult)
{
	if (unknown69e680(type))
	{
		do {} while (0);
		return 6;
	}
	int amount = (int)(lb2x_opS4_bbaaf8[type] * ((level == 3) ? mult : (float)lb2x_opS4_bbaf08[level]));
	lb2x_opS4_stats.add4729d0(0x3b8,LB2X_minInt(amount,100 - unknown14),string(""),-1);
	lb2x_opS4_unknown9d06d0(&unknown14,amount,100);
	times[type] = lb2x_opS4_map->getTurn();
	for (int i = 5; i >= 0; i--)
	{
		if (amount >= lb2x_opS4_bbaf74[i])
		{
			if (type < 0x7a)
			{
				do
				{
					if (lb2x_opS4_showMessage(0x2b4,lb2x_opS4_messages_d2d1d8[i],0,0,lb2x_OpS4_HEntityTmp(),lb2x_OpS4_HPropTmp(),0,0))
					{
						lb2x_opS4_messages->unknown8758d0(1);
					}
					lb2x_opS4_logMsgs->scrollToEnd();
				} while (false);
				if (lb2x_opS4_rolledValues)
				{
					lb2x_opS4_rolledValues->say(0x3c,false,string(""));
				}
			}
			types.push_back(type);
			turnLog.push_back(lb2x_opS4_map->getTurn());
			amounts.push_back(amount);
			levels.push_back(unknown14);
			do {} while (0);
			return i;
		}
	}
	return 6;
}
