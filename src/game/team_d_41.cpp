// team_d_41: Entity member 0x600e30 (random malfunction effect).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

class HEntity
{
	int ID;
};

class HProp
{
	int ID;
public:
	HProp();
};

struct ItemData41	// NOTE: placeholder name and layout
{
	char	pad000[0x94];
	int		unknown94;	// NOTE: placeholder name
};

class Item
{
public:
	bool unknown457ad0();			// NOTE: placeholder name
	int unknown4578a0();			// NOTE: placeholder name (folded getter)
	ItemData41 *getData();			// NOTE: placeholder name (folded getter 0x9b4350)
	int unknown577fb0();			// NOTE: placeholder name
	bool unknown457d10();			// NOTE: placeholder name
	void *getEffect(int type);
	string unknown571db0(int a, int b);	// NOTE: placeholder name (item name)
	void setBroken(int a, bool b);
};

class HItem
{
	int ID;
public:
	Item *operator->() const;
};

class CPart41	// NOTE: placeholder name (CPart)
{
public:
	void unknown890710(int value);	// NOTE: placeholder name
};

class CParts41	// NOTE: placeholder name (CParts at 0xcec088)
{
public:
	CPart41 *unknown894e70(HItem item);	// NOTE: placeholder name
};
extern CParts41 *parts41_cec088;	// NOTE: placeholder name

class Map41	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
};
extern Map41 *world41;	// NOTE: placeholder name (0xcefc4c)

class RNG
{
public:
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
bool logMessageS_5111e0(int id, const string &text, int a, int b, HEntity e, HProp d, int f, int g);	// NOTE: placeholder name (0x5111e0)
bool logMessageI_5111e0(int id, int text, int a, int b, HEntity e, HProp d, int f, int g);	// NOTE: placeholder name (0x5111e0)
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name
int OpX5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
string intToString(int value);
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name
template <class T> void OpV4c_shuffle(vector<T> &v);	// NOTE: placeholder name
HItem OpX5_randomRecord(vector<HItem> &v);	// NOTE: placeholder name

#define OPD_LOGS(id,text) do { if (logMessageS_5111e0(id,text,0,0,self,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro
#define OPD_LOGI(id) do { if (logMessageI_5111e0(id,0,0,0,self,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro

class Entity
{
public:
	char	pad00[4];
	HEntity	self;	// +0x04

	bool isPlayer();				// 0x5c7600
	unsigned int unknown5cb930(vector<HItem> *out);	// NOTE: placeholder name
	unsigned int unknown5cb8b0(vector<HItem> *out);	// NOTE: placeholder name
	void unknown5fd550(HItem item, int turns);	// NOTE: placeholder name
	int unknown5defa0(int amount, int flag);	// NOTE: placeholder name
	int unknown5ca260();			// NOTE: placeholder name
	int takeDamage(int a, int b, int c, int d, int e, int f, int g, bool h, HProp i, int j, int k, int l, int m, int n);	// 0x5e5520
	void unknown600e30();			// NOTE: placeholder name
};

void Entity::unknown600e30()
{
	if (isPlayer())
		opR1d_4541b0(0x62,0,0);
	switch (rng.rangeInt(0.0f,3.0f))
	{
	case 0:
		{
			bool done = false;
			vector<HItem> list;
			if (unknown5cb930(&list))
			{
				for (int i = list.size() - 1; i >= 0; i--)
				{
					if (list[i]->unknown457ad0() || (list[i]->unknown4578a0() != 2 && list[i]->unknown4578a0() != 3) || list[i]->getData()->unknown94 == 2)
						OpQ5_eraseAt(list,i);
				}
				if (!list.empty())
				{
					OpV4c_shuffle(list);
					int count = rng.rangeInt(1.0f,(float)OpX5_minInt(3,list.size()));
					for (int j = 0; j < count; j++)
					{
						HItem item = OpX5_randomRecord(list);
						unknown5fd550(item,rng.rangeInt(8.0f,15.0f));
						if (isPlayer())
						{
							CPart41 *part = parts41_cec088->unknown894e70(item);
							if (part)
								part->unknown890710(0);
						}
						if (!done)
						{
							OPD_LOGI(0x170);
							done = true;
						}
						OPD_LOGS(0x171,item->unknown571db0(0,0));
					}
				}
			}
		}
		break;
	case 1:
		{
			bool done = false;
			vector<HItem> list;
			if (unknown5cb8b0(&list))
			{
				for (int k = list.size() - 1; k >= 0; k--)
				{
					if (list[k]->unknown457ad0() || list[k]->unknown577fb0() || list[k]->unknown457d10() || list[k]->getEffect(0x55) || list[k]->getData()->unknown94 == 2)
						OpQ5_eraseAt(list,k);
				}
				if (!list.empty())
				{
					HItem item = OpX5_randomRecord(list);
					OPD_LOGS(0x13e,item->unknown571db0(0,0));
					item->setBroken(-2,true);
					if (!done)
					{
						OPD_LOGI(0x172);
						done = true;
					}
				}
			}
		}
		break;
	case 2:
		{
			int amount = rng.rangeInt(1.0f,2.0f);
			amount = unknown5defa0(amount,0);
			if (amount)
				OPD_LOGS(0x173,intToString(amount));
		}
		break;
	case 3:
		{
			int damage = rng.rangeInt(1.0f,5.0f) * unknown5ca260() / 100;
			OPD_LOGS(0x174,intToString(damage));
			takeDamage(10,0,0,damage,1,0,0,!world41->unknown4631f0(self),HProp(),1,8,0,0,0);
		}
		break;
	}
}
