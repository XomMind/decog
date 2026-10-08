// op_w2_a: map object BS (0xcefc4c) line-of-fire helper matched against COGMIND.exe (Beta 17.1).
// This TU must link before op_w2_m.cpp (it does, by name), or LTCG gives unknown7178d0 an EH frame.
// Separate TU from op_w2_m.cpp: its callees are declared throw() (they are leaf functions the
// original link knew could not throw, so the function has no EH frame).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point() throw();									// 0x453b40
	Point(const Point &p) throw();						// 0x46ca50
	Point &operator=(const Point &p) throw();
	bool operator==(const Point &p) const throw();		// 0x409b90
	bool operator!=(const Point &p) const throw();		// 0x409bd0
	// Private names for the operators above, used by unknown718430: the real operators are undefined
	// (stubbed) in the full link and declared without throw() elsewhere, which would give it EH states.
	Point &assign_w2a(const Point &p) throw();			// NOTE: = operator= (0x46ca50)
	bool equals_w2a(const Point &p) const throw();		// NOTE: = operator== (0x409b90)
	bool differs_w2a(const Point &p) const throw();		// NOTE: = operator!= (0x409bd0)
};

class Bresenham2DStepperSubcell
{
public:
	Bresenham2DStepperSubcell(const Point &fromCell, const Point &fromSubcell, const Point &toCell, const Point &toSubcell, int subcells_) throw();
	virtual ~Bresenham2DStepperSubcell() throw();
	bool next_w2a(Point &cell, Point &subcell) throw();		// NOTE: placeholder name (0x410420 Bresenham2DStepperSubcell::next; private name: the real inline next calls Point::set, which is not provably nothrow in the full link)

	int		p04, p08, p0c, p10, p14, p18, p1c, p20, p24, p28, p2c;
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const Point &p) throw();
	T &at_w2a(const Point &p) throw();	// NOTE: private name for operator() (see Point::assign_w2a)
	bool contains(const Point &p) throw();	// NOTE: placeholder name (0x9b43b0)
	bool contains_w2a(const Point &p) throw();	// NOTE: private name for contains (see Point::assign_w2a)
};

class OpW2B_Grid	// NOTE: placeholder name
{
	int	width;
	int	height;
	int	*data;

public:
	int &operator()(const Point &p) throw();	// 0x9ced70

	int	stamp;	// NOTE: placeholder name
};

class Entity;
class OpW2B_Prop;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool isNull() const;
	void reset();					// NOTE: placeholder name (0x9b7270)
	bool isValid() const throw();
	bool isValid_w2a() const throw();	// NOTE: private name for HEntity::isValid (see unknown718430)
	bool operator==(HEntity other) const throw();
	Entity *operator->() const throw();		// 0x9b6570
	Entity *get_w2a() const throw();		// NOTE: private name for operator-> (0x9b6570), see unknown718430
};

class HProp
{
	int	ID;
public:
	bool isValid() const throw();
	OpW2B_Prop *operator->() const throw();	// 0x9b64f0
};

class OpW2B_Prop	// NOTE: placeholder name
{
public:
	int unknown45c5f0() throw();	// NOTE: placeholder name
	bool unknown65e1d0(HEntity e);	// NOTE: placeholder name
};

class HItem
{
	int	ID;
public:
	bool isValid() const;
};

class OpW2B_Part	// NOTE: placeholder name (EntityPart4588f0)
{
public:
	int unknown458950(int type);	// NOTE: placeholder name
};

class OpW2B_AI	// NOTE: placeholder name (EntityAI)
{
public:
	bool unknown459090();			// NOTE: placeholder name
	bool unknown5814f0(HEntity e);	// NOTE: placeholder name
	OpW2B_Part *unknown4590f0();	// NOTE: placeholder name
};

class OpW2_Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();			// NOTE: placeholder name (trivial getter)
};

class OpW2_HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	OpW2_Group *operator->() const;	// 0x9b7250
};

class Entity
{
public:
	int unknown45a320() throw();		// NOTE: placeholder name
	const Point &getPosition() throw();	// 0x45a4a0
	const Point &getPosition_w2a() throw();	// NOTE: private name for getPosition (0x45a4a0); the real one is not provably nothrow in the full link
	Point unknown5c80f0(const Point &p);	// NOTE: placeholder name
	bool unknown45a510(const Point &p);	// NOTE: placeholder name
	bool isPlayer();
	OpW2B_AI *getAI();					// NOTE: placeholder name (0x45b590)
	void *getTarget();					// 0x45a760
	int getFaction();					// 0x45a2c0
	OpW2_HGroup getGroup();				// NOTE: placeholder name
	int unknown5c7cb0();				// NOTE: placeholder name
	int unknown5c7cf0();				// NOTE: placeholder name
	int unknown5d7b80();				// NOTE: placeholder name
	int unknown5caee0();				// NOTE: placeholder name
	int unknown5d7b00(int a);			// NOTE: placeholder name
	void unknown5e37a0(HEntity target, float *value);	// NOTE: placeholder name
	int unknown45a6e0();				// NOTE: placeholder name (trivial getter)
	int unknown45a700();				// NOTE: placeholder name
	int unknown44a7d0();				// NOTE: placeholder name (trivial getter)
	int unknown5cab90();				// NOTE: placeholder name
	int unknown45a990();				// NOTE: placeholder name
	bool unknown45ae30();				// NOTE: placeholder name
	OpW2B_Part *unknown45ae50();		// NOTE: placeholder name
	bool unknown5c7f70();				// NOTE: placeholder name
	int unknown5d15a0(int a);			// NOTE: placeholder name
	int unknown45a340();				// NOTE: placeholder name
	int unknown5d1390();				// NOTE: placeholder name
	bool unknown5ced30();				// NOTE: placeholder name
	bool unknown45aff0();				// NOTE: placeholder name
	HItem unknown5d2380(int slot);		// NOTE: placeholder name
	bool unknown45a780();				// NOTE: placeholder name
	int unknown5d22a0(int type);		// NOTE: placeholder name
	bool unknown5d1280(int a);			// NOTE: placeholder name
	int unknown457820();				// NOTE: placeholder name
};

class Cell
{
public:
	bool unknown45d480_w2a() throw();	// NOTE: placeholder name (0x45d480; private name: the real Cell::unknown45d480 is not provably nothrow in the full link)
	bool isOpen();					// NOTE: placeholder name (0x4550b0)
	HProp getProp() throw();		// 0x45d550
	HEntity getEntity() throw();	// 0x45d250
	HEntity getEntity_w2a() throw();	// NOTE: private name for getEntity (0x45d250), see unknown718430
};

extern Array2D<Cell *>	cells;				// NOTE: placeholder name (0xcfd44c)
extern Array2D<bool>	opw2_d201c8[];		// NOTE: placeholder name
extern Point			effectOrigin;		// NOTE: placeholder name (0xd2e20c)
extern vector<int>		opw2_cf4910;		// NOTE: placeholder name
extern float			opw2_ba099c[];		// NOTE: placeholder name
extern const float		opw2_b9b9b4;		// NOTE: placeholder name
extern const float		opw2_b9b9b0;		// NOTE: placeholder name
extern const float		opw2_b9763c;		// NOTE: placeholder name
extern const float		opw2_b97640;		// NOTE: placeholder name
extern const float		opw2_b97644;		// NOTE: placeholder name
extern const float		opw2_b97648;		// NOTE: placeholder name
extern const float		opw2_b97650;		// NOTE: placeholder name
extern const float		opw2_b97654;		// NOTE: placeholder name
extern const float		opw2_b96374;		// NOTE: placeholder name
extern const float		opw2_b9637c;		// NOTE: placeholder name
extern const float		opw2_b96378;		// NOTE: placeholder name
extern const float		opw2_b96380;		// NOTE: placeholder name
extern const float		opw2_b9636c;		// NOTE: placeholder name
extern const float		opw2_b96370;		// NOTE: placeholder name
extern const float		opw2_b95a3c;		// NOTE: placeholder name
extern const double		opw2_c36f08;		// NOTE: placeholder name (120.0)
int opw2_distance(const Point &a, const Point &b) throw();	// NOTE: placeholder name (0x40a3f0)
int opw2_distance_w2a(const Point &a, const Point &b) throw();	// NOTE: private name for opw2_distance (see Point::assign_w2a)
int opw2_maxInt(int a, int b);		// NOTE: placeholder name (0x9cdb60)
float maxf(float a, float b);
void opw2_eraseAt(vector<HEntity> *v, int *i);	// NOTE: placeholder name (0x9d6440)

class BS
{
public:
	bool unknown7178d0(HEntity e, const Point &from, const Point &fromSub, const Point &to, const Point &toSub, bool useSeen);
	float unknown718430(HEntity e, const Point &p, vector<float> *breakdown, int range);
	float unknown719a90(HEntity e, const Point &p, vector<float> *breakdown, bool *hostileOut);
	bool isVisible(const Point &p);	// 0x4631c0
	int unknown715fe0(int index, const Point &p, int range, bool first);
	bool unknown7170a0(HEntity e, const Point &p, vector<Point> &path, vector<int> &hits, vector<int> &blocks, Point &last, const Point *at, int atMode, bool f1, bool f2);
	int opw3_unknown7279a0(HEntity e);	// NOTE: placeholder name
	int opw3_unknown727ad0(HEntity e);	// NOTE: placeholder name
	bool opw3_unknown7290f0(HEntity e);	// NOTE: placeholder name
	bool unknown71ca20(HEntity e);

	char			pad0[0x268];
	vector<vector<HProp> >	props268;	// 0x268	NOTE: placeholder name
	char			pad278[0x600 - 0x278];
	HEntity			entity600;	// 0x600	NOTE: placeholder name
	char			pad604[0x618 - 0x604];
	HEntity			entity618;	// 0x618	NOTE: placeholder name
	vector<HEntity>	entities61c;	// 0x61c	NOTE: placeholder name
	vector<HEntity>	entities62c;	// 0x62c	NOTE: placeholder name
	char			pad63c[0x66c - 0x63c];
	HEntity			target;		// 0x66c	NOTE: placeholder name
	char			pad670[0x69c - 0x670];
	OpW2B_Grid		seen;		// 0x69c	NOTE: placeholder name
	char			pad6ac[0x6e8 - 0x6ac];
	OpW2B_Grid		*fov;		// 0x6e8	NOTE: placeholder name
};

bool BS::unknown7178d0(HEntity e, const Point &from, const Point &fromSub, const Point &to, const Point &toSub, bool useSeen)
{
	Point here;
	Point subPoint;
	Bresenham2DStepperSubcell line(from, fromSub, to, toSub, 9);
	Point lastPos = from;
	line.next_w2a(here, subPoint);
	while (here == from)
		line.next_w2a(here, subPoint);
	OpW2B_Grid *visible = 0;
	int stamp;
	if (e == target)
	{
		visible = useSeen ? &seen : fov;
		stamp = fov->stamp;
	}
	int type;
	int check;
	do
	{
		line.next_w2a(here, subPoint);
		if (lastPos != here)
		{
			if (here == to)
				return true;
			check = 0;
			if (visible && ((useSeen && seen(here) == 0) || (!useSeen && (*visible)(here) != stamp)))
				type = 0;
			else if (cells(here)->unknown45d480_w2a())
			{
				type = 0;
				return false;
			}
			else if (cells(here)->getEntity().isValid())
			{
				type = cells(here)->getEntity()->unknown45a320();
				check = 4;
			}
			else if (cells(here)->getProp().isValid() && cells(here)->getProp()->unknown45c5f0())
			{
				type = cells(here)->getProp()->unknown45c5f0();
				check = 2;
			}
			lastPos = here;
		}
		if (check != 0 && opw2_d201c8[type](subPoint))
			return false;
	} while (here != to || subPoint != toSub);
	return true;
}

float BS::unknown718430(HEntity e, const Point &p, vector<float> *breakdown, int range)
{
	if (e->unknown45a510(p))
		return 1.0;
	float cell = e->unknown5c7cb0() / 100.0;
	if (breakdown)
		breakdown->at(0) = cell;
	Point size = p;
	if (e->isPlayer() && cells(size)->getEntity().isNull() && isVisible(size) && cells(size)->isOpen())
	{
		int diff = 25;
		Point entries = e->unknown5c80f0(size);
		Point ret;
		Point time;
		Point chance;
		Bresenham2DStepperSubcell bot(entries, effectOrigin, size, effectOrigin, 9);
		time.assign_w2a(entries);
		bot.next_w2a(chance, ret);
		while (chance.equals_w2a(entries))
			bot.next_w2a(chance, ret);
		while (!bot.next_w2a(chance, ret))
		{
			if (time.differs_w2a(chance))
			{
				if (!cells.contains_w2a(chance))
				{
					chance.x = -1;
					break;
				}
				if (cells.at_w2a(chance)->getEntity_w2a().isValid_w2a() || cells.at_w2a(chance)->unknown45d480_w2a())
				{
					size.assign_w2a(chance);
					break;
				}
				if (range && opw2_distance_w2a(e.get_w2a()->getPosition_w2a(), chance) >= range)
					break;
				time.assign_w2a(chance);
			}
		}
	}
	HEntity front = cells(size)->getEntity();
	int unit = opw2_distance(e->unknown5c80f0(size), size);
	float aux;
	if (unit < 6)
	{
		aux = (6 - unit) * 0.03;
		cell += aux;
		if (breakdown)
			breakdown->at(1) = aux;
	}
	aux = opw2_ba099c[e->unknown5caee0()];
	if (aux != 0)
	{
		cell += aux;
		if (breakdown)
			breakdown->at(6) = aux;
	}
	aux = e->unknown5d7b00(1) / 100.0;
	if (front.isValid())
		e->unknown5e37a0(front, &aux);
	cell += aux;
	if (breakdown)
		breakdown->at(7) = aux;
	int message = e->unknown45a6e0();
	if (message >= 2)
	{
		cell += 0.1;
		if (breakdown)
			breakdown->at(9) = 0.1f;
	}
	else if (message == 0)
	{
		aux = -0.1f;
		if (e->unknown45a700())
		{
			switch (e->unknown44a7d0())
			{
				case 1:
					aux += e->unknown45a700() * opw2_b96374;
					break;
				case 7:
					aux += e->unknown45a700() * opw2_b9637c;
					break;
			}
		}
		cell += aux;
		if (breakdown)
			breakdown->at(9) = aux;
	}
	aux = e->isPlayer() ? -(e->unknown5cab90() / 400.0) : -(e->unknown5cab90() / 800.0);
	if (aux != 0)
	{
		cell += aux;
		if (breakdown)
			breakdown->at(3) = aux;
	}
	cell -= opw2_maxInt(0, e->unknown45a990()) / 3000.0;
	if (breakdown)
		breakdown->at(4) = -opw2_maxInt(0, e->unknown45a990()) / 3000.0f;
	if (e->getGroup()->unknown9b4350() == 3 && !props268[4].empty() && unknown715fe0(4, e->getPosition(), 10, true))
	{
		cell -= opw2_b9b9b4;
		if (breakdown)
			breakdown->at(16) += -opw2_b9b9b4;
	}
	aux = opw3_unknown7279a0(e) / 100.0;
	cell += aux;
	if (breakdown)
		breakdown->at(17) = aux;
	aux = opw3_unknown727ad0(e) / 100.0;
	cell += aux;
	if (breakdown)
		breakdown->at(18) = aux;
	if (e->unknown45ae30() && e->unknown45ae50()->unknown458950(0x36))
	{
		float boosted = cell * opw2_b9763c;
		aux = boosted - cell;
		cell += aux;
		if (breakdown)
			breakdown->at(16) += aux;
	}
	if (e->getGroup()->unknown9b4350() == 3)
	{
		for (unsigned int i = 0; i < entities62c.size(); i++)
		{
			if (!entities62c[i].operator->() || !entities62c[i]->getAI()->unknown459090() || !entities62c[i]->getAI()->unknown4590f0()->unknown458950(0x3a))
				opw2_eraseAt(&entities62c, (int *)&i);
			else if (opw2_distance(entities62c[i]->getPosition(), e->getPosition()) <= 3)
			{
				aux = opw2_b97654;
				cell += aux;
				if (breakdown)
					breakdown->at(16) += aux;
			}
		}
	}
	if (front.isValid())
	{
		if (e->isPlayer() || e->unknown5c7f70())
		{
			aux = 0;
			if (front->getAI() && front->getAI()->unknown459090() && e->isPlayer() && front->getAI()->unknown4590f0()->unknown458950(0x38))
				aux += opw2_b97644;
			if (front->getGroup()->unknown9b4350() == 3 && unknown715fe0(0x17, front->getPosition(), 0x14, true))
				aux += opw2_b9b9b0;
			if (aux != 0)
			{
				cell += aux;
				if (breakdown)
					breakdown->at(15) += aux;
			}
		}
		if (front->isPlayer() && e->getAI() && e->getAI()->unknown459090() && e->getAI()->unknown4590f0()->unknown458950(0x38))
		{
			aux = opw2_b97648;
			cell += aux;
			if (breakdown)
				breakdown->at(16) += aux;
		}
		if (e->getGroup()->unknown9b4350() <= 2)
		{
			if (front == entity618)
			{
				if (!entity618->getAI()->unknown459090() || !entity618->getAI()->unknown4590f0()->unknown458950(0x37))
					entity618.reset();
				else
				{
					aux = opw2_b97640;
					cell += aux;
					if (breakdown)
						breakdown->at(15) += aux;
				}
			}
			if (front->getGroup()->unknown9b4350() == 3)
			{
				for (unsigned int j = 0; j < entities61c.size(); j++)
				{
					if (!entities61c[j].operator->() || !entities61c[j]->getAI()->unknown459090() || !entities61c[j]->getAI()->unknown4590f0()->unknown458950(0x39))
						opw2_eraseAt(&entities61c, (int *)&j);
					else if (opw2_distance(entities61c[j]->getPosition(), front->getPosition()) <= 3)
					{
						aux = opw2_b97650;
						cell += aux;
						if (breakdown)
							breakdown->at(15) += aux;
					}
				}
			}
		}
		if (front->unknown45a6e0() == 0)
		{
			int integrity = front->unknown5d15a0(0);
			if (integrity <= 0x5f)
			{
				aux = (100 - integrity) / 5 / 100.0;
				cell -= aux;
				if (breakdown)
					breakdown->at(10) = -aux;
			}
		}
		switch (front->unknown45a340())
		{
			case 0:
				cell -= 0.3;
				if (breakdown)
					breakdown->at(2) = -0.3f;
				break;
			case 1:
				cell -= 0.1;
				if (breakdown)
					breakdown->at(2) = -0.1f;
				break;
			case 2:
				break;
			case 3:
				cell += 0.1;
				if (breakdown)
					breakdown->at(2) = 0.1f;
				break;
			case 4:
				cell += 0.3;
				if (breakdown)
					breakdown->at(2) = 0.3f;
				break;
		}
		aux = 0;
		int type = front->unknown5d1390();
		switch (type)
		{
			case 2:
			case 5:
				break;
			case 3:
			case 4:
				if (!front->unknown5ced30() && !front->unknown45aff0() && (!opw3_unknown7290f0(front) || front->unknown5d2380(0x74).isValid()) && !front->unknown45a780() && !unknown71ca20(front))
				{
					float penalty = type == 4 ? 0.1 : 0.05;
					cell -= penalty;
					if (breakdown)
						breakdown->at(11) = -penalty;
				}
			case 1:
			case 6:
				if (!front->unknown45a780())
				{
					int armor = front->unknown5d22a0(0x54);
					if (armor)
						aux += armor / 100.0;
				}
		}
		aux += opw2_maxInt(front->unknown5d22a0(0x52), front->unknown5d22a0(0x61)) / 100.0;
		cell -= aux;
		if (breakdown)
			breakdown->at(8) = -aux;
		if (front->unknown45a700() && (front->unknown44a7d0() == 1 || front->unknown44a7d0() == 7) && !front->unknown45a780())
		{
			switch (front->unknown44a7d0())
			{
				case 1:
					aux = front->unknown45a700() * opw2_b96378;
					break;
				case 7:
					aux = front->unknown45a700() * opw2_b96380;
					break;
			}
			cell += aux;
			if (breakdown)
				breakdown->at(10) += aux;
		}
		if (front->unknown5d1280(0) || front->getTarget())
		{
			cell += 0.1;
			if (breakdown)
				breakdown->at(12) = 0.1f;
		}
		cell += opw2_maxInt(0, front->unknown45a990()) / 3000.0;
		if (breakdown)
			breakdown->at(5) = opw2_maxInt(0, front->unknown45a990()) / 3000.0f;
		if (opw2_cf4910[front->unknown457820()] != 0)
		{
			if (e == target)
			{
				cell += opw2_b9636c;
				if (breakdown)
					breakdown->at(14) = opw2_b9636c;
			}
			else if (front == target)
			{
				cell -= opw2_b96370;
				if (breakdown)
					breakdown->at(14) = -opw2_b96370;
			}
		}
		if (front == entity600)
		{
			if (e->isPlayer() || e->getFaction() == 0x5e)
			{
				cell += opw2_b95a3c;
				if (breakdown)
					breakdown->at(17) += opw2_b95a3c;
			}
		}
	}
	else if (!cells(size)->isOpen() || (cells(size)->getProp().isValid() && !cells(size)->getProp()->unknown65e1d0(HEntity())))
	{
		cell += 0.1;
		if (breakdown)
			breakdown->at(12) = 0.1f;
	}
	aux = 0;
	vector<Point> number;
	vector<int> other;
	vector<int> stepper;
	Point flag;
	unknown7170a0(e, size, number, other, stepper, flag, 0, 4, true, true);
	if (number.size() >= 2)
	{
		for (unsigned int k = 0; k < number.size() - 1; k++)
		{
			if (other[k] == 4)
				aux += 0.2;
		}
		if (aux != 0)
		{
			cell -= aux;
			if (breakdown)
				breakdown->at(13) = -aux;
		}
	}
	return maxf(0, cell);
}

float BS::unknown719a90(HEntity e, const Point &p, vector<float> *breakdown, bool *hostileOut)
{
	if (e->unknown45a510(p))
		return 1.0;
	float trail = e->unknown5c7cf0() / 100.0;
	if (breakdown)
		breakdown->at(0) = trail;
	float left = e->unknown5d7b80() / 100.0;
	trail += left;
	if (breakdown)
		breakdown->at(7) = left;
	int current = e->unknown45a6e0();
	if (current >= 2)
	{
		trail += 0.1;
		if (breakdown)
			breakdown->at(9) = 0.1f;
	}
	left = e->isPlayer() ? -(e->unknown5cab90() / 400.0) : -(e->unknown5cab90() / 800.0);
	if (left != 0)
	{
		trail += left;
		if (breakdown)
			breakdown->at(3) = left;
	}
	if (e->getGroup()->unknown9b4350() == 3 && !props268[4].empty() && unknown715fe0(4, e->getPosition(), 10, true))
	{
		trail -= opw2_b9b9b4;
		if (breakdown)
			breakdown->at(16) += -opw2_b9b9b4;
	}
	if (e->unknown45ae30() && e->unknown45ae50()->unknown458950(0x36))
	{
		float boosted = trail * opw2_b9763c;
		left = boosted - trail;
		trail += left;
		if (breakdown)
			breakdown->at(16) += left;
	}
	if (e->getGroup()->unknown9b4350() == 3)
	{
		for (unsigned int i = 0; i < entities62c.size(); i++)
		{
			if (!entities62c[i].operator->() || !entities62c[i]->getAI()->unknown459090() || !entities62c[i]->getAI()->unknown4590f0()->unknown458950(0x3a))
				opw2_eraseAt(&entities62c, (int *)&i);
			else if (opw2_distance(entities62c[i]->getPosition(), e->getPosition()) <= 3)
			{
				left = opw2_b97654;
				trail += left;
				if (breakdown)
					breakdown->at(16) += left;
			}
		}
	}
	HEntity record = cells(p)->getEntity();
	if (record.isValid())
	{
		if (record->getAI() && record->getAI()->unknown5814f0(e))
		{
			if (hostileOut)
				*hostileOut = true;
			return opw2_c36f08 / 100.0;
		}
		if (e->isPlayer() || e->unknown5c7f70())
		{
			left = 0;
			if (record->getAI() && record->getAI()->unknown459090() && e->isPlayer() && record->getAI()->unknown4590f0()->unknown458950(0x38))
				left += opw2_b97644;
			if (record->getGroup()->unknown9b4350() == 3 && unknown715fe0(0x17, record->getPosition(), 0x14, true))
				left += opw2_b9b9b0;
			if (left != 0)
			{
				trail += left;
				if (breakdown)
					breakdown->at(15) += left;
			}
		}
		if (record->isPlayer() && e->getAI() && e->getAI()->unknown459090() && e->getAI()->unknown4590f0()->unknown458950(0x38))
		{
			left = opw2_b97648;
			trail += left;
			if (breakdown)
				breakdown->at(16) += left;
		}
		if (e->getGroup()->unknown9b4350() <= 2)
		{
			if (record == entity618)
			{
				if (!entity618->getAI()->unknown459090() || !entity618->getAI()->unknown4590f0()->unknown458950(0x37))
					entity618.reset();
				else
				{
					left = opw2_b97640;
					trail += left;
					if (breakdown)
						breakdown->at(15) += left;
				}
			}
			if (record->getGroup()->unknown9b4350() == 3)
			{
				for (unsigned int j = 0; j < entities61c.size(); j++)
				{
					if (!entities61c[j].operator->() || !entities61c[j]->getAI()->unknown459090() || !entities61c[j]->getAI()->unknown4590f0()->unknown458950(0x39))
						opw2_eraseAt(&entities61c, (int *)&j);
					else if (opw2_distance(entities61c[j]->getPosition(), record->getPosition()) <= 3)
					{
						left = opw2_b97650;
						trail += left;
						if (breakdown)
							breakdown->at(15) += left;
					}
				}
			}
		}
		if (record->unknown45a6e0() == 0)
		{
			int integrity = record->unknown5d15a0(0);
			if (integrity <= 0x5f)
			{
				left = (100 - integrity) / 5 / 100.0;
				trail -= left;
				if (breakdown)
					breakdown->at(10) = -left;
			}
		}
		switch (record->unknown45a340())
		{
			case 0:
				trail -= 0.3;
				if (breakdown)
					breakdown->at(2) = -0.3f;
				break;
			case 1:
				trail -= 0.1;
				if (breakdown)
					breakdown->at(2) = -0.1f;
				break;
			case 2:
				break;
			case 3:
				trail += 0.1;
				if (breakdown)
					breakdown->at(2) = 0.1f;
				break;
			case 4:
				trail += 0.3;
				if (breakdown)
					breakdown->at(2) = 0.3f;
				break;
		}
		int type = record->unknown5d1390();
		switch (type)
		{
			case 2:
			case 5:
				break;
			case 3:
			case 4:
				if (!record->unknown5ced30() && !record->unknown45aff0() && (!opw3_unknown7290f0(record) || record->unknown5d2380(0x74).isValid()) && !record->unknown45a780() && !unknown71ca20(record))
				{
					float penalty = type == 4 ? 0.1 : 0.05;
					trail -= penalty;
					if (breakdown)
						breakdown->at(11) = -penalty;
				}
			case 1:
			case 6:
				if (!record->unknown45a780())
				{
					int armor = record->unknown5d22a0(0x54);
					if (armor)
					{
						left = armor / 100.0;
						trail -= left;
						if (breakdown)
							breakdown->at(8) = -left;
					}
				}
		}
		if (record->unknown45a700() && (record->unknown44a7d0() == 1 || record->unknown44a7d0() == 7) && !record->unknown45a780())
		{
			switch (record->unknown44a7d0())
			{
				case 1:
					left = record->unknown45a700() * opw2_b96378;
					break;
				case 7:
					left = record->unknown45a700() * opw2_b96380;
					break;
			}
			trail += left;
			if (breakdown)
				breakdown->at(10) += left;
		}
		if (record->unknown5d1280(0) || record->getTarget())
		{
			trail += 0.1;
			if (breakdown)
				breakdown->at(12) = 0.1f;
		}
		if (opw2_cf4910[record->unknown457820()] != 0)
		{
			if (e == target)
			{
				trail += opw2_b9636c;
				if (breakdown)
					breakdown->at(14) = opw2_b9636c;
			}
			else if (record == target)
			{
				trail -= opw2_b96370;
				if (breakdown)
					breakdown->at(14) = -opw2_b96370;
			}
		}
		if (record == entity600)
		{
			if (e->isPlayer() || e->getFaction() == 0x5e)
			{
				trail += opw2_b95a3c;
				if (breakdown)
					breakdown->at(17) += opw2_b95a3c;
			}
		}
	}
	else if (!cells(p)->isOpen() || (cells(p)->getProp().isValid() && !cells(p)->getProp()->unknown65e1d0(HEntity())))
	{
		trail += 1.0;
		if (breakdown)
			breakdown->at(12) = 1.0f;
	}
	return maxf(0, trail);
}
