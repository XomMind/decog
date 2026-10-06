// op_x4a: OpU4_Mode (Xom/Zion spawn setup) function matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

class GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
	bool unknown46f4b0(int a);	// NOTE: placeholder name
};
extern GameData gameData;	// NOTE: placeholder name (0xd1e860)

class Push_46ed20
{
public:
	char unknown0[0x4];
	int field4;
	int field8;
	int operate();
};

class OpU4_HGameState	// NOTE: placeholder name
{
public:
	int ID;
	Push_46ed20 *operator->() const;	// 0x9b7910
};
extern OpU4_HGameState opu4_d1e888;	// NOTE: placeholder name

struct OpU4_EntityRecord	// NOTE: placeholder name
{
	int unknown0;
};

class OpU4_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	OpU4_EntityRecord *unknown6c5600(int a, int b, bool c, bool d);	// NOTE: placeholder name
};
extern OpU4_World *opu4_world;	// NOTE: placeholder name (0xcefc4c)

struct OpR5h_Pair;

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	OpR5h_WL(const int *w, int count);	// 0x9ba790
	void add(T value, int weight);	// 0x9ba310
	void remove(T value);	// 0x9bab80
	T &pick();	// 0x9ba470
	T &pickNot(T value);	// 0x9ba750
};

class OpU4_Spawn	// NOTE: placeholder name
{
public:
	int type;
	string code;
	int unknown20;
	OpU4_Spawn(int type_);	// NOTE: placeholder name
};

class OpU4_Obj6bed40	// NOTE: placeholder name
{
public:
	void unknown6bed40(OpR5h_WL<int> *a, OpR5h_WL<int> *b);	// NOTE: placeholder name
};

bool opu4_inVector(vector<int> &v, int value);	// NOTE: placeholder name (0x9db330)

extern vector<int>		opu4_d1e920;	// NOTE: placeholder name
extern vector<string>	opu4_d1e900;	// NOTE: placeholder name
extern string			opu4_d2ae30[];	// NOTE: placeholder name
extern int				opu4_caf160;	// NOTE: placeholder name
extern int				opu4_cf4744;	// NOTE: placeholder name
extern int				opu4_d38628;	// NOTE: placeholder name
extern int				opu4_bbb460[];	// NOTE: placeholder name
extern int				opu4_bbb5bc[];	// NOTE: placeholder name
extern int				opu4_bbb5e8[];	// NOTE: placeholder name
extern unsigned char	opu4_b90458[];	// NOTE: placeholder name
extern int				opu4_bbbbb0[];	// NOTE: placeholder name

class OpU4_Mode	// NOTE: placeholder name
{
public:
	bool unknown0;
	char pad01[0x47];
	vector<int> list48;	// NOTE: placeholder name
	vector<OpU4_Spawn *> spawns;	// NOTE: placeholder name
	char pad68[0x70 - 0x68];
	vector<int> list70;	// NOTE: placeholder name

	void unknown6be920();	// NOTE: placeholder name
	void unknown6beeb0(int a, int b);	// NOTE: placeholder name
};

void OpU4_Mode::unknown6beeb0(int a, int b)
{
	unknown6be920();
	OpU4_EntityRecord *entityRecord;
	if (!stringToInt(gameData.unknown46f6d0("zioWasImprinted_g")) || stringToInt(gameData.unknown46f6d0("zioAttackedLocals_g")))
	{
		unknown0 = false;
		return;
	}
	unknown0 = true;
	if (opu4_d1e920[0] == 0)
	{
		for (int i = 0; i <= 12; i++)
			opu4_d1e900[i] = opu4_d2ae30[i];
	}
	for (int j = 0; j <= 12; j++)
		opu4_d1e920[j] = 0;
	opu4_d1e920[0] = 1;
	opu4_d1e920[7] = 1;
	if (!gameData.unknown46f4b0(1))
	{
		for (int k = 0; k <= 12; k++)
			opu4_d1e920[k] = 0;
		return;
	}
	list48.assign(8,opu4_caf160);
	for (int n = 0; n <= 7; n++)
	{
		if (n == 2 || n == 6 || n == 7)
			continue;
		entityRecord = opu4_world->unknown6c5600(3,opu4_bbb460[n],false,true);
		if (entityRecord != NULL)
			list48[n] = entityRecord->unknown0;
	}
	int stage = opu4_d1e888->operate();
	if (opu4_bbb5bc[stage] != 0 && opu4_b90458[opu4_d1e888->field4] != 0)
	{
		OpR5h_WL<int> special;
		OpR5h_WL<int> second;
		((OpU4_Obj6bed40 *)this)->unknown6bed40(&special,&second);
		bool has7 = false;
		for (int m = 0; m < opu4_bbb5bc[stage]; m++)
		{
			spawns.push_back(new OpU4_Spawn(rng.chance(opu4_bbb5e8[stage]) ? (has7 ? special.pickNot(7) : special.pick()) : second.pick()));
			if (spawns.back()->type == 7)
				has7 = true;
		}
	}
	OpR5h_WL<int> list(opu4_bbbbb0,15);
	if (opu4_cf4744 != 0)
		list.remove(10);
	if (opu4_d1e888->field8 == 1)
		list.remove(14);
	for (int q = 0; q < opu4_d38628; q++)
	{
		int value = list.pick();
		while (opu4_inVector(list70,value))
			value = list.pick();
		list70.push_back(value);
	}
}
