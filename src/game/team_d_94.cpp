// team_d_94: BS member 0x730f40: a group member with effect 0x8a calls derelict reinforcements (weighted
// derelict names, spawn near a fixed entrance or out of sight, optionally following each other).
// NOTE: class layouts are partial; member and method names are placeholders. Matching relies on the Pos
// constructors defined in team_a_repair.cpp (LTCG proves "new Pos(...)" cannot throw).
#include <vector>
#include <string>
using namespace std;

int OpQ1_distanceCeil_40a3f0(const struct Point &a, const struct Point &b);

struct Point
{
	int x;
	int y;

	Point();								// NOTE: placeholder name (Push_453b40::operate)
	Point(const Point &p) throw();			// 0x46ca50
	Point &operator=(const Point &p);		// NOTE: folded with the copy constructor (0x46ca50)
};

struct Pos : public Point
{
	Pos(int v);				// 0x409990
	Pos(int x_, int y_);	// 0x46ca20
	Pos &operator=(const Point &p);	// NOTE: folded with Point's copy constructor (0x46ca50)
};

struct Area94	// NOTE: placeholder name
{
	Point min;
	Point max;
};

class WeightedStrings94	// NOTE: placeholder name (OpR5h_WLString / OpR5h_WL<string>)
{
public:
	vector<string> values;
	vector<int> weights;
	int total;

	WeightedStrings94();
	void add(string value, int weight);
	string &pick();
};

class CellGrid94	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getRandom_9cf0c0(Point *out);	// NOTE: placeholder name
	Area94 getArea();
};
extern CellGrid94 cells94_cfd44c;	// NOTE: placeholder name
extern vector<int> effectTable94_d2f0f8;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

class Entity;

class HEntity
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const;
};

class EntityAI
{
public:
	void unknown459470(const Area94 &area);	// NOTE: placeholder name
	void setFollowEntity(HEntity followEntity_, int followParam_);
};

class Group94	// NOTE: placeholder name
{
public:
	int getType();					// NOTE: placeholder name (folded getter)
	vector<HEntity> *getMembers();	// NOTE: folded getter
};

class HGroup
{
	int ID;
public:
	Group94 *operator->() const;	// NOTE: folded (OpC_Handle::get230)
};

struct EntityEffect;

class Entity
{
public:
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	void unknown45b360(int type);			// NOTE: placeholder name (remove effect)
	void unknown45b340(Pos *effect);		// NOTE: placeholder name (add effect)
	HGroup getGroup();
	EntityAI *getAI();
	Point &getPosition();
};

class BS	// NOTE: placeholder layout
{
public:
	char	pad000[0x66c];
	HEntity	player;	// +0x66c

	bool isVisible(const Point &p);
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
	bool unknown716940(const Point &from, const Point &to, Entity *e, unsigned int *length);	// NOTE: placeholder name
	HEntity unknown6c5dc0(const string &name, const Point &pos, int group, bool flag, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name
	void unknown730f40(HEntity e);	// NOTE: placeholder name
};

void BS::unknown730f40(HEntity e)
{
	if (!e->unknown45ac40(0x8a))
		return;
	e->unknown45b360(0x8a);
	int amount = e->getGroup()->getType();
	bool ok = amount == 0xa;
	vector<HEntity> *k = e->getGroup()->getMembers();
	int num = 0;
	for (unsigned int i = 0; i < k->size(); i++)
	{
		if ((*k)[i]->unknown45ac40(0x8a))
			num++;
	}
	if (num > (ok ? 0x19 : 0x41))
		return;
	WeightedStrings94 ret;
	int size;
	if (ok)
	{
		size = rng.chance(25) ? 2 : 1;
		ret.add("Federalist",10);
		ret.add("Explorer",5);
		ret.add("Ranger",5);
		ret.add("Guru",5);
		ret.add("Scrapper_3",0x32);
		ret.add("Elite_4",0x14);
		ret.add("Thug_5",2);
		ret.add("Savage_5",1);
		ret.add("Butcher_5",1);
		ret.add("Mutant_5",1);
	}
	else
	{
		size = 2;
		ret.add("Federalist",0x14);
		ret.add("Explorer",7);
		ret.add("Ranger",7);
		ret.add("Guru",5);
		ret.add("Scrapper_3",0x38);
		ret.add("Thug_5",2);
		ret.add("Savage_5",1);
		ret.add("Butcher_5",1);
		ret.add("Mutant_5",1);
	}
	bool success = rng.chance(50);
	Pos temp(-1);
	Pos x(0x26,3);
	Pos adj(0x7a,0xe);
	if (rng.chance(10))
		temp = rng.chance(50) ? x : adj;
	Point start;
	vector<HEntity> center;
	for (int j = 0; j < size; j++)
	{
		if (j && success)
		{
		}
		else
		{
			if (temp.x != -1)
				start = temp;
			else
			{
				for (int t = 0; t < 200; t++)
				{
					cells94_cfd44c.getRandom_9cf0c0(&start);
					if (!isVisible(start) && OpQ1_distanceCeil_40a3f0(start,player->getPosition()) > 0x10 && findPlaceableNear(start,start,1) && unknown716940(start,x,0,0))
						goto found;
				}
				return;
			}
		}
found:
		HEntity spawn = unknown6c5dc0(ret.pick(),start,amount,false,0x22,0xe,false);
		if (spawn.isValid())
		{
			spawn->unknown45b340(new Pos(effectTable94_d2f0f8[0x8a],1));
			spawn->getAI()->unknown459470(cells94_cfd44c.getArea());
			if (success && !center.empty())
				spawn->getAI()->setFollowEntity(center.front(),0);
			center.push_back(spawn);
		}
	}
}
