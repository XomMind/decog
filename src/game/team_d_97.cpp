// team_d_97: member 0x5bb750 of the robot record whose +0 is its HEntity (callers EntityAI::takeTurn and
// Entity::die): a robot calls reinforcements (combat: damaged arrivals; otherwise fresh troops and terrain
// effects), with optional faction conversion and alert music.
// NOTE: class layouts are partial; member and method names are placeholders.
// NOTE: local names follow the stack-slot hash order (the squad pointer is "to", the visibility flag "first").
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};
void getAdjacentCells(const Point &p, vector<Point> &adjacent);	// NOTE: placeholder name (0x4fab80)
int opR1d_454260(const Point &p, int id);	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)

struct Range97	// NOTE: placeholder name (Point::randomInRange_40c130)
{
	int lo;
	int hi;

	int randomInRange_40c130();
};

struct Record97	// NOTE: placeholder name and layout
{
	char	pad000[0x210];
	Range97	reinforcement;	// +0x210
};

class HProp
{
public:
	int ID;
	HProp();
	bool isValid() const;	// NOTE: folded with HItem::isValid
};

class Item
{
public:
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	int getCharges();				// NOTE: placeholder name (folded getter)
	void setCharges(int value);		// NOTE: placeholder name (folded setter)
};

class HItem
{
public:
	int ID;
	Item *operator->() const;
};

class Entity;

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
};

class Group97;
class HGroup
{
	int ID;
};

class Entity
{
public:
	char		pad000[8];
	Record97	*record;	// +0x08
	char		pad00c[0xb4 - 0xc];
	int			unknownb4;	// +0xb4

	bool isHostileTo(HEntity e);
	struct EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	int getTarget();
	void die(bool a, int cause, HProp killer, bool b, int c, int d, int e, int f);	// NOTE: placeholder signature (0x633790)
	int getIntegrity();				// NOTE: placeholder name (folded getter Sweep_490840::getField)
	void unknown5dea60(int value, int flag);	// NOTE: placeholder name
	vector<HItem> *getInventoryList();
	int unknown45a990();			// NOTE: placeholder name
	void setUnknown(int value);		// NOTE: placeholder name (folded setter Sweep_4514c0::setField)
	Point &getPosition();
	void unknown637bb0();			// NOTE: placeholder name
	void changeFaction(HGroup newGroup, bool flag);
	void unknown5fd900(int level, int duration);	// NOTE: placeholder name
};

class Cell
{
public:
	bool unknown4550b0();					// NOTE: placeholder name (folded getter Sweep_4550b0::getField)
	void unknown66b700(int a, int b);		// NOTE: placeholder name
};

class CellGrid97	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: folded (OpX5_Array2D<int>::atPoint)
};
extern CellGrid97 cells97_cfd44c;	// NOTE: placeholder name
extern int value97_d29730;	// NOTE: placeholder name
extern int base97_b96108;	// NOTE: placeholder name (120)

struct Squad97	// NOTE: placeholder name and layout
{
	int		type;
	char	pad04[8];
	bool	unknown0c;
};

class Overmind97	// NOTE: placeholder name (Overmind at 0xcf6428)
{
public:
	Squad97 *unknown683310(HEntity e);	// NOTE: placeholder name
	void deployAssaultParty(HEntity e, int type, bool flag, vector<HEntity> *out);	// NOTE: placeholder signature
	void spawnPatrolParty(HEntity e, bool b, int c, int d, Point *e2, int f, vector<HEntity> *out, int h, bool i);	// NOTE: placeholder signature
};
extern Overmind97 overmind97_cf6428;	// NOTE: placeholder name

class BS
{
public:
	HEntity getPlayer();
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	HProp unknown71e7c0(const Point &p, int amount, bool protomatter);
	void unknown464840(HProp prop);	// NOTE: placeholder name
	HGroup unknown463890(int i);	// NOTE: placeholder name
};
extern BS *world97_cefc4c;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float lo, float hi);
};
extern RNG rng;

class ConsoleA97	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA97 *consoleA97_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs97_cec0b4;	// NOTE: placeholder name

class State97	// NOTE: placeholder name (object at 0xd25450)
{
public:
	bool unknown000;	// NOTE: placeholder name

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
};
extern State97 state97_d25450;	// NOTE: placeholder name

bool showMessage97(int id, const void *text, const void *b, int c, HEntity d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)

class Caller97	// NOTE: placeholder name and layout
{
public:
	HEntity	self;		// +0x00
	char	pad04[0xc8 - 4];
	int		type;		// +0xc8

	void unknown5bb750(bool combat, int mode, bool explode);	// NOTE: placeholder name
};

void Caller97::unknown5bb750(bool combat, int mode, bool explode)
{
	vector<HEntity> v;
	bool x = self->isHostileTo(world97_cefc4c->getPlayer());
	bool first = world97_cefc4c->unknown4631f0(self);
	bool base = self->unknown45ac40(0x30);
	Squad97 *to = overmind97_cf6428.unknown683310(self);
	if (combat)
	{
		if (!self->getTarget())
		{
			do
			{
				if (showMessage97(0x279,0,0,0,self,HProp(),0,0))
					consoleA97_cec058->unknown8758d0(true);
				logMsgs97_cec0b4->scrollToEnd();
			} while (0);
			if (type == 4 || type == 5)
				overmind97_cf6428.deployAssaultParty(self,type,false,&v);
			else if (to && to->type == 7)
				overmind97_cf6428.deployAssaultParty(self,type,to->unknown0c,&v);
			else
				overmind97_cf6428.spawnPatrolParty(self,false,0,0,0,0,&v,10,false);
		}
		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (v[i].operator->())
			{
				if (rng.chance(25))
					v[i]->die(explode,10,HProp(),true,0,0,0,0);
				else
				{
					do
					{
						if (showMessage97(0x278,0,0,0,v[i],HProp(),0,0))
							consoleA97_cec058->unknown8758d0(true);
						logMsgs97_cec0b4->scrollToEnd();
					} while (0);
					v[i]->unknown5dea60(OpX5_maxInt(1,v[i]->getIntegrity() * rng.rangeInt(50.0f,100.0f) / 100),0);
					vector<HItem> *inv = v[i]->getInventoryList();
					for (int j = inv->size() - 1; j >= 0; j--)
					{
						if (rng.chance(10))
							(*inv)[j]->unknown57dbe0(0,1,1,1);
						else if (rng.chance(50))
							(*inv)[j]->setCharges(OpX5_maxInt(1,(*inv)[j]->getCharges() * rng.rangeInt(50.0f,100.0f) / 100));
					}
					if (mode == 3)
						v[i]->setUnknown(self->unknown45a990() * rng.rangeInt(25.0f,75.0f) / 100 + base97_b96108);
				}
			}
		}
	}
	else
	{
		do
		{
			if (showMessage97(0x277,0,0,0,self,HProp(),0,0))
				consoleA97_cec058->unknown8758d0(true);
			logMsgs97_cec0b4->scrollToEnd();
		} while (0);
		if (type == 4 || type == 5)
			overmind97_cf6428.deployAssaultParty(self,type,false,&v);
		else if (to && to->type == 7)
			overmind97_cf6428.deployAssaultParty(self,type,to->unknown0c,&v);
		else
			overmind97_cf6428.spawnPatrolParty(self,false,0,0,0,0,&v,10,false);
		for (unsigned int k = 0; k < v.size(); k++)
		{
			do
			{
				if (showMessage97(0x278,0,0,0,v[k],HProp(),0,0))
					consoleA97_cec058->unknown8758d0(true);
				logMsgs97_cec0b4->scrollToEnd();
			} while (0);
			v[k]->setUnknown(self->unknown45a990() * rng.rangeInt(25.0f,75.0f) / 100);
		}
		vector<Point> vec;
		getAdjacentCells(self->getPosition(),vec);
		for (unsigned int m = 0; m < vec.size(); m++)
		{
			if ((*cells97_cfd44c.atPoint(vec[m]))->unknown4550b0())
				(*cells97_cfd44c.atPoint(vec[m]))->unknown66b700(0x11,value97_d29730);
		}
		opR1d_454260(self->getPosition(),0x9b);
		int center = self->record->reinforcement.randomInRange_40c130() + self->unknownb4;
		if (center > 0)
		{
			HProp p = world97_cefc4c->unknown71e7c0(self->getPosition(),center,false);
			if (p.isValid())
				world97_cefc4c->unknown464840(p);
		}
		self->unknown637bb0();
	}
	if (base)
	{
		for (unsigned int n = 0; n < v.size(); n++)
		{
			if (v[n].operator->())
			{
				v[n]->changeFaction(world97_cefc4c->unknown463890(1),true);
				v[n]->unknown5fd900(1,6);
			}
		}
	}
	else if (!x && state97_d25450.unknown000 && first)
		state97_d25450.unknown69e700(0x1e,0,0.0f);
}
