// team_d_43: Entity member 0x602170 (weapon backfire: self damage, knockback and part damage).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &a, const Point &b);	// NOTE: placeholder name (0x4099f0: a + b)
	Point(const Point &p) throw();			// 0x46ca50
};
extern Point directions43_d015d8[];	// NOTE: placeholder name

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

struct ItemData43	// NOTE: placeholder name and layout
{
	char	pad000[0x70];
	int		unknown70;	// NOTE: placeholder name
};

class Item
{
public:
	int unknown4578c0();			// NOTE: placeholder name (folded getter)
	ItemData43 *getData();			// NOTE: placeholder name (folded getter 0x9b4350)
	int unknown457f90();			// NOTE: placeholder name
	int unknown577fb0();			// NOTE: placeholder name
	bool unknown457e90();			// NOTE: placeholder name
	int unknown9b6bf0();			// NOTE: placeholder name (folded getter, integrity)
	string unknown571db0(int a, int b);	// NOTE: placeholder name (item name)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown57ab10(int amount, int a, int b, int c, HProp p, int d, int e);	// NOTE: placeholder name
};

class HItem
{
	int ID;
public:
	Item *operator->() const;
};

struct EntityRec43	// NOTE: placeholder name and layout
{
	char	pad000[0x9c];
	int		unknown9c;	// NOTE: placeholder name
};

class Console43	// NOTE: placeholder name (object behind 0xcec138)
{
public:
	void unknown965250(int value);	// NOTE: placeholder name
};
extern Console43 *console43_cec138;	// NOTE: placeholder name

class RNG
{
public:
	int rangeInt(float low, float high);
};
extern RNG rng;
extern int int_cf462c;	// NOTE: placeholder name

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
bool logMessageSS_5111e0(int id, const string &text, const string &text2, int b, HEntity e, HProp d, int f, int g);	// NOTE: placeholder name (0x5111e0)
bool logMessageP_5111e0(int id, const string &text, int a, int b, HEntity e, HProp d, const Point &pos, int g);	// NOTE: placeholder name (0x5111e0)
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name
int OpX5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
string intToString(int value);
template <class T> void OpV4c_shuffle(vector<T> &v);	// NOTE: placeholder name

class Entity
{
public:
	char			pad00[4];
	HEntity			self;		// +0x04
	EntityRec43		*record;	// +0x08
	char			pad0c[0x30 - 0x0c];
	vector<Point>	positions;	// +0x30, NOTE: placeholder name
	char			pad40[0x8c - 0x40];
	int				unknown8c;	// NOTE: placeholder name
	char			pad90[0xc0 - 0x90];
	bool			unknownc0;	// NOTE: placeholder name

	bool isPlayer();				// 0x5c7600
	int takeDamage(int a, int b, int c, int d, int e, int f, int g, bool h, HProp i, int j, int k, int l, int m, int n);	// 0x5e5520
	bool unknown5c84f0(const Point &p);	// NOTE: placeholder name
	bool unknown5c85a0(const Point &p, bool large);	// NOTE: placeholder name
	bool unknown5c8710(const Point &p);	// NOTE: placeholder name
	void unknown5ddac0(const Point &p, bool flag);	// NOTE: placeholder name
	bool unknown5fdd30();			// NOTE: placeholder name
	unsigned int unknown5cb8b0(vector<HItem> *out);	// NOTE: placeholder name
	Point unknown45a4c0();			// NOTE: placeholder name
	void unknown642940(HItem item, int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown602170(HItem item, int dir);	// NOTE: placeholder name
};

void Entity::unknown602170(HItem item, int dir)
{
	bool player = isPlayer();
	int damage = rng.rangeInt(10.0f,60.0f);
	if (unknown8c > 1 && damage >= unknown8c)
		damage = unknown8c - 1;
	takeDamage(0,0,0,damage,4,0,0,true,HProp(),1,8,0,0,1);
	if (dir != 8 && record->unknown9c == 1)
	{
		Point p(positions[0],directions43_d015d8[dir]);
		if (unknown5c84f0(p) && !unknown5c85a0(p,false) && !unknown5c8710(p))
		{
			unknown5ddac0(p,false);
			if (!unknown5fdd30())
				return;
		}
	}
	if (player)
	{
		do { if (logMessageSS_5111e0(0x17a,item->unknown571db0(0,0),intToString(damage),0,self,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
		opR1d_4541b0(0x61,0,0);
		console43_cec138->unknown965250(damage);
	}
	for (int n = rng.rangeInt(0.0f,2.0f); n > 0; n--)
	{
		vector<HItem> parts;
		if (unknown5cb8b0(&parts))
		{
			OpV4c_shuffle(parts);
			for (unsigned int i = 0; i < parts.size(); i++)
			{
				if (parts[i]->unknown4578c0() == 1 && parts[i]->getData()->unknown70 > 1 && parts[i]->unknown457f90() != 7 && !parts[i]->unknown577fb0() && (int_cf462c != 2 || player))
				{
					do { if (logMessageS_5111e0(player ? 0x17b : 0x17c,parts[i]->unknown571db0(0,0),0,0,self,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
					if (parts[i]->unknown457e90() || unknownc0)
					{
						do { if (logMessageP_5111e0(0x45,parts[i]->unknown571db0(0,0),0,0,self,HProp(),unknown45a4c0(),0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0);
						parts[i]->unknown57dbe0(player,1,1,1);
					}
					else
					{
						int integrity = parts[i]->unknown9b6bf0();
						if (integrity > 1)
						{
							int amount = OpX5_maxInt(1,rng.rangeInt(20.0f,50.0f) * integrity / 100);
							parts[i]->unknown57ab10(OpX5_minInt(parts[i]->unknown9b6bf0() - 1,amount),1,0,0,HProp(),0,0);
						}
						unknown642940(parts[i],player,1,0,2);
					}
					break;
				}
			}
		}
	}
}
