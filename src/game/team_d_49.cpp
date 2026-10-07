// team_d_49: machine/prop turn update 0x65c8a0 (countdowns, item consumption and a random part reset).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

class HProp
{
	int ID;
public:
	HProp();
};

class Item
{
public:
	int unknown577600(int value);		// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class HItem
{
	int ID;
public:
	Item *operator->() const;
};

struct PropData49	// NOTE: placeholder name and layout
{
	char	pad000[0xf8];
	int		type;	// +0xf8
};

class Prop49	// NOTE: placeholder name
{
public:
	PropData49 *getData();			// NOTE: placeholder name (folded getter)
	const Point &getPos();			// NOTE: placeholder name (0x4184d0)
	int unknown44ab40();			// NOTE: placeholder name (folded getter)
};

struct Countdown49	// NOTE: placeholder name and layout
{
	char		pad00[8];
	int			turns;		// +0x08
	char		pad0c[0x28 - 0x0c];
	int			unknown28;	// NOTE: placeholder name
	Point		unknown2c;	// NOTE: placeholder name
	vector<int>	timers;		// +0x34

	~Countdown49();
	bool unknown65a260(bool flag);	// NOTE: placeholder name
};

class Overmind49	// NOTE: placeholder name (Overmind at 0xcf6428)
{
public:
	int unknown68bc80(int exitIndex, int type, const Point &target);
};
extern Overmind49 overmind49_cf6428;	// NOTE: placeholder name

class ItemLists49	// NOTE: placeholder name (0xcf3a10)
{
public:
	vector<HItem> &operator[](int index);
};
extern ItemLists49 itemLists49_cf3a10;	// NOTE: placeholder name
extern int thresholds49_b99d48[];	// NOTE: placeholder name
extern int caps49_b99d58[];			// NOTE: placeholder name
extern int counts49_b99d68[];		// NOTE: placeholder name
extern int flag49_cefbb8;			// NOTE: placeholder name
extern vector<int> partRecords49_d2d1c4;	// NOTE: placeholder type

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float low, float high);
};
extern RNG rng;

class ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA *consoleA_cec058;	// NOTE: placeholder name
class CLogMsgs
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern CLogMsgs *logMsgs_cec0b4;	// NOTE: placeholder name
bool logMessageP_5111e0(int id, int a, int b, int c, HProp d, HProp e, const Point &pos, int g);	// NOTE: placeholder name (0x5111e0)

void OpT8a_eraseAt(vector<int> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0)
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name
template <class T> void OpQ5_deleteObjects(vector<T> &v);	// NOTE: placeholder name
int OpU8a_randomRec(vector<int> &v);	// NOTE: placeholder name (0x9d5d00)
bool OpT8b_Fn9db000(vector<int> &v, int value);	// NOTE: placeholder name (0x9db000)

class Machine49	// NOTE: placeholder name
{
public:
	int				handle;		// +0x00 (a prop handle)
	int				pad04;
	int				index;		// +0x08
	char			pad0c[0x38 - 0x0c];
	Countdown49		*countdown;	// +0x38
	int				unknown3c;	// NOTE: placeholder name

	Prop49 *operator->() const;	// NOTE: placeholder name (handle access, 0x9b64f0)
	void unknown65c8a0();		// NOTE: placeholder name
};

void Machine49::unknown65c8a0()
{
	if (countdown)
	{
		countdown->turns--;
		if (countdown->turns <= 0)
		{
			if (countdown->unknown65a260(true))
				return;
			delete countdown;
			countdown = NULL;
		}
		else if ((*this)->getData()->type == 5)
		{
			for (unsigned int i = 0; i < countdown->timers.size(); i++)
			{
				countdown->timers[i]--;
				if (countdown->timers[i] <= 0)
				{
					overmind49_cf6428.unknown68bc80(handle,countdown->unknown28,countdown->unknown2c);
					OpT8a_eraseAt(countdown->timers,i);
				}
			}
		}
	}
	switch ((*this)->getData()->type)
	{
	case 3:
		if (unknown3c >= thresholds49_b99d48[index])
		{
			do { if (logMessageP_5111e0(0x1c9,0,0,0,HProp(),HProp(),(*this)->getPos(),0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
			unknown3c = 0;
		}
		{
			vector<HItem> &items = itemLists49_cf3a10[(*this)->unknown44ab40()];
			if (items.size() > caps49_b99d58[index])
			{
				do { if (logMessageP_5111e0(0x1c8,0,0,0,HProp(),HProp(),(*this)->getPos(),0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
				for (int j = 0; j < counts49_b99d68[index] && !items.empty(); j++)
				{
					int value = items.front()->unknown577600(100);
					unknown3c += value;
					items.front()->unknown57dbe0(0,1,1,1);
					OpQ5_eraseAt(items,0);
				}
			}
		}
		break;
	}
	if (flag49_cefbb8 && rng.chance(10))
	{
		flag49_cefbb8 = 0;
		vector<int> records;
		for (int n = rng.rangeInt(8.0f,14.0f); n > 0; n--)
			OpT8b_Fn9db000(records,OpU8a_randomRec(partRecords49_d2d1c4));
		OpQ5_deleteObjects(records);
	}
}
