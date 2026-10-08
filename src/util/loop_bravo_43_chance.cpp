// NOTE: private borrowed World evaluator718430. Complete native Point/stepper owners; downstream audited prototypes.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <vector>
using namespace std;

struct LB43P
{
	int x;
	int y;

	LB43P() throw();									// 0x453b40
	LB43P(const LB43P &p) throw();						// 0x46ca50
	LB43P &operator=(const LB43P &p) throw();
	bool operator==(const LB43P &p) const throw();		// 0x409b90
	bool operator!=(const LB43P &p) const throw();		// 0x409bd0
};

class LB43LineBase{protected:int errorX,errorY,deltaX2,deltaY2,stepX,stepY,deltaX,deltaY,x,y;public:virtual~LB43LineBase()throw();};
class LB43Line:public LB43LineBase{int subcells;public:LB43Line(const LB43P&,const LB43P&,const LB43P&,const LB43P&,int)throw();virtual~LB43Line()throw();bool next(LB43P&,LB43P&)throw();};
static_assert(sizeof(LB43LineBase)==44&&sizeof(LB43Line)==48,"native subcell hierarchy");

template <class T>
class LB43Array	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const LB43P &p) throw();
	bool contains(const LB43P &p) throw();	// NOTE: placeholder name (0x9b43b0)
};

class LB43Grid	// NOTE: placeholder name
{
	int	width;
	int	height;
	int	*data;

public:
	int &operator()(const LB43P &p) throw();	// 0x9ced70

	int	stamp;	// NOTE: placeholder name
};

class LB43Entity;
class LB43Prop;

class LB43HE	// NOTE: placeholder layout
{
	int	ID;
public:
	LB43HE();
	bool isNull() const;
	void reset();					// NOTE: placeholder name (0x9b7270)
	bool isValid() const throw();
	bool operator==(LB43HE other) const throw();
	LB43Entity *operator->() const throw();		// 0x9b6570
};

class LB43HP
{
	int	ID;
public:
	bool isValid() const throw();
	LB43Prop *operator->() const throw();	// 0x9b64f0
};

class LB43Prop	// NOTE: placeholder name
{
public:
	int unknown45c5f0() throw();	// NOTE: placeholder name
	bool unknown65e1d0(LB43HE e);	// NOTE: placeholder name
};

class LB43HI
{
	int	ID;
public:
	bool isValid() const;
};

struct LB43Modifier;
class LB43Part	// NOTE: placeholder name (EntityPart4588f0)
{
public:
	LB43Modifier*unknown458950(int type);	// NOTE: placeholder name
};

class LB43AI	// NOTE: placeholder name (EntityAI)
{
public:
	bool unknown459090();			// NOTE: placeholder name
	bool unknown5814f0(LB43HE e);	// NOTE: placeholder name
	LB43Part *unknown4590f0();	// NOTE: placeholder name
};

class LB43Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();			// NOTE: placeholder name (trivial getter)
};

class LB43HG	// NOTE: placeholder name
{
	int	ID;
public:
	LB43Group *operator->() const;	// 0x9b7250
};

class LB43Entity
{
public:
	int unknown45a320() throw();		// NOTE: placeholder name
	LB43P &pos45a4a0() throw();	// 0x45a4a0
	LB43P unknown5c80f0(const LB43P &p);	// NOTE: placeholder name
	bool unknown45a510(const LB43P &p);	// NOTE: placeholder name
	bool player5c7600();
	LB43AI *ai45b590();					// NOTE: placeholder name (0x45b590)
	int target45a760();					// 0x45a760
	int faction45a2c0();					// 0x45a2c0
	LB43HG group45a3f0();				// NOTE: placeholder name
	int unknown5c7cb0();				// NOTE: placeholder name
	int unknown5c7cf0();				// NOTE: placeholder name
	int unknown5d7b80();				// NOTE: placeholder name
	int unknown5caee0();				// NOTE: placeholder name
	int unknown5d7b00(bool a);			// NOTE: placeholder name
	void unknown5e37a0(LB43HE target, float *value);	// NOTE: placeholder name
	int unknown45a6e0();				// NOTE: placeholder name (trivial getter)
	int unknown45a700();				// NOTE: placeholder name
	int unknown44a7d0();				// NOTE: placeholder name (trivial getter)
	int unknown5cab90();				// NOTE: placeholder name
	int unknown45a990();				// NOTE: placeholder name
	bool unknown45ae30();				// NOTE: placeholder name
	LB43Part *unknown45ae50();		// NOTE: placeholder name
	bool unknown5c7f70();				// NOTE: placeholder name
	int unknown5d15a0(bool a);			// NOTE: placeholder name
	int unknown45a340();				// NOTE: placeholder name
	int unknown5d1390();				// NOTE: placeholder name
	bool unknown5ced30();				// NOTE: placeholder name
	bool unknown45aff0();				// NOTE: placeholder name
	LB43HI unknown5d2380(int slot);		// NOTE: placeholder name
	bool unknown45a780();				// NOTE: placeholder name
	int unknown5d22a0(int type);		// NOTE: placeholder name
	bool unknown5d1280(bool a);			// NOTE: placeholder name
	int unknown457820();				// NOTE: placeholder name
};

class LB43Cell
{
public:
	bool unknown45d480() throw();	// NOTE: placeholder name
	bool open4550b0();					// NOTE: placeholder name (0x4550b0)
	LB43HP prop45d550() throw();		// 0x45d550
	LB43HE entity45d250() throw();	// 0x45d250
};

extern LB43Array<LB43Cell *>	lb43_cfd44c;				// NOTE: placeholder name (0xcfd44c)
extern LB43Array<bool>	lb43_d201c8[];		// NOTE: placeholder name
extern LB43P			lb43_d2e20c;		// NOTE: placeholder name (0xd2e20c)
extern vector<int>		lb43_cf4910;		// NOTE: placeholder name
extern float			lb43_ba099c[];		// NOTE: placeholder name
extern const float		lb43_b9b9b4;		// NOTE: placeholder name
extern const float		lb43_b9b9b0;		// NOTE: placeholder name
extern const float		lb43_b9763c;		// NOTE: placeholder name
extern const float		lb43_b97640;		// NOTE: placeholder name
extern const float		lb43_b97644;		// NOTE: placeholder name
extern const float		lb43_b97648;		// NOTE: placeholder name
extern const float		lb43_b97650;		// NOTE: placeholder name
extern const float		lb43_b97654;		// NOTE: placeholder name
extern const float		lb43_b96374;		// NOTE: placeholder name
extern const float		lb43_b9637c;		// NOTE: placeholder name
extern const float		lb43_b96378;		// NOTE: placeholder name
extern const float		lb43_b96380;		// NOTE: placeholder name
extern const float		lb43_b9636c;		// NOTE: placeholder name
extern const float		lb43_b96370;		// NOTE: placeholder name
extern const float		lb43_b95a3c;		// NOTE: placeholder name
extern const double		lb43_c36f08;		// NOTE: placeholder name (120.0)
int lb43_distance40a3f0(const LB43P &a, const LB43P &b) throw();	// NOTE: placeholder name (0x40a3f0)
int lb43_max9cdb60(int a, int b);		// NOTE: placeholder name (0x9cdb60)
float lb43_max9cd020(float a, float b);
void lb43_erase9d6440(vector<LB43HE> *v, int *i);	// NOTE: placeholder name (0x9d6440)

class LB43World
{
public:
	bool unknown7178d0(LB43HE e, const LB43P &from, const LB43P &fromSub, const LB43P &to, const LB43P &toSub, bool useSeen);
	float unknown718430(LB43HE e, const LB43P &p, vector<float> *breakdown, int range);
	float unknown719a90(LB43HE e, const LB43P &p, vector<float> *breakdown, bool *hostileOut);
	bool visible4631c0(const LB43P &p);	// 0x4631c0
	int unknown715fe0(int index, const LB43P &p, int range, bool first);
	bool unknown7170a0(LB43HE e, const LB43P &p, vector<LB43P> &path, vector<int> &hits, vector<int> &blocks, LB43P &last, const LB43P *at, int atMode, bool f1, bool f2);
	int opw3_unknown7279a0(LB43HE e);	// NOTE: placeholder name
	int opw3_unknown727ad0(LB43HE e);	// NOTE: placeholder name
	bool opw3_unknown7290f0(LB43HE e);	// NOTE: placeholder name
	bool unknown71ca20(LB43HE e);

	char			pad0[0x268];
	vector<vector<LB43HP> >	props268;	// 0x268	NOTE: placeholder name
	char			pad278[0x600 - 0x278];
	LB43HE			entity600;	// 0x600	NOTE: placeholder name
	char			pad604[0x618 - 0x604];
	LB43HE			entity618;	// 0x618	NOTE: placeholder name
	vector<LB43HE>	entities61c;	// 0x61c	NOTE: placeholder name
	vector<LB43HE>	entities62c;	// 0x62c	NOTE: placeholder name
	char			pad63c[0x66c - 0x63c];
	LB43HE			target;		// 0x66c	NOTE: placeholder name
	char			pad670[0x69c - 0x670];
	LB43Grid		seen;		// 0x69c	NOTE: placeholder name
	char			pad6ac[0x6e8 - 0x6ac];
	LB43Grid		*fov;		// 0x6e8	NOTE: placeholder name
};

float LB43World::unknown718430(LB43HE e, const LB43P &p, vector<float> *breakdown, int range)
{
	if (e->unknown45a510(p))
		return 1.0;
	float cell = e->unknown5c7cb0() / 100.0;
	if (breakdown)
		breakdown->at(0) = cell;
	LB43P size = p;
	if (e->player5c7600() && lb43_cfd44c(size)->entity45d250().isNull() && visible4631c0(size) && lb43_cfd44c(size)->open4550b0())
	{
		int diff = 25;
		LB43P entries = e->unknown5c80f0(size);
		LB43P ret;
		LB43P time;
		LB43P chance;
		LB43Line bot(entries, lb43_d2e20c, size, lb43_d2e20c, 9);
		time = entries;
		bot.next(chance, ret);
		while (chance == entries)
			bot.next(chance, ret);
		while (!bot.next(chance, ret))
		{
			if (time != chance)
			{
				if (!lb43_cfd44c.contains(chance))
				{
					chance.x = -1;
					break;
				}
				if (lb43_cfd44c(chance)->entity45d250().isValid() || lb43_cfd44c(chance)->unknown45d480())
				{
					size = chance;
					break;
				}
				if (range && lb43_distance40a3f0(e->pos45a4a0(), chance) >= range)
					break;
				time = chance;
			}
		}
	}
	LB43HE front = lb43_cfd44c(size)->entity45d250();
	int unit = lb43_distance40a3f0(e->unknown5c80f0(size), size);
	float aux;
	if (unit < 6)
	{
		aux = (6 - unit) * 0.03;
		cell += aux;
		if (breakdown)
			breakdown->at(1) = aux;
	}
	aux = lb43_ba099c[e->unknown5caee0()];
	if (aux != 0)
	{
		cell += aux;
		if (breakdown)
			breakdown->at(6) = aux;
	}
	aux = e->unknown5d7b00(true) / 100.0;
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
					aux += e->unknown45a700() * lb43_b96374;
					break;
				case 7:
					aux += e->unknown45a700() * lb43_b9637c;
					break;
			}
		}
		cell += aux;
		if (breakdown)
			breakdown->at(9) = aux;
	}
	aux = e->player5c7600() ? -(e->unknown5cab90() / 400.0) : -(e->unknown5cab90() / 800.0);
	if (aux != 0)
	{
		cell += aux;
		if (breakdown)
			breakdown->at(3) = aux;
	}
	cell -= lb43_max9cdb60(0, e->unknown45a990()) / 3000.0;
	if (breakdown)
		breakdown->at(4) = -lb43_max9cdb60(0, e->unknown45a990()) / 3000.0f;
	if (e->group45a3f0()->unknown9b4350() == 3 && !props268[4].empty() && unknown715fe0(4, e->pos45a4a0(), 10, true))
	{
		cell -= lb43_b9b9b4;
		if (breakdown)
			breakdown->at(16) += -lb43_b9b9b4;
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
		float boosted = cell * lb43_b9763c;
		aux = boosted - cell;
		cell += aux;
		if (breakdown)
			breakdown->at(16) += aux;
	}
	if (e->group45a3f0()->unknown9b4350() == 3)
	{
		for (unsigned int i = 0; i < entities62c.size(); i++)
		{
			if (!entities62c[i].operator->() || !entities62c[i]->ai45b590()->unknown459090() || !entities62c[i]->ai45b590()->unknown4590f0()->unknown458950(0x3a))
				lb43_erase9d6440(&entities62c, (int *)&i);
			else if (lb43_distance40a3f0(entities62c[i]->pos45a4a0(), e->pos45a4a0()) <= 3)
			{
				aux = lb43_b97654;
				cell += aux;
				if (breakdown)
					breakdown->at(16) += aux;
			}
		}
	}
	if (front.isValid())
	{
		if (e->player5c7600() || e->unknown5c7f70())
		{
			aux = 0;
			if (front->ai45b590() && front->ai45b590()->unknown459090() && e->player5c7600() && front->ai45b590()->unknown4590f0()->unknown458950(0x38))
				aux += lb43_b97644;
			if (front->group45a3f0()->unknown9b4350() == 3 && unknown715fe0(0x17, front->pos45a4a0(), 0x14, true))
				aux += lb43_b9b9b0;
			if (aux != 0)
			{
				cell += aux;
				if (breakdown)
					breakdown->at(15) += aux;
			}
		}
		if (front->player5c7600() && e->ai45b590() && e->ai45b590()->unknown459090() && e->ai45b590()->unknown4590f0()->unknown458950(0x38))
		{
			aux = lb43_b97648;
			cell += aux;
			if (breakdown)
				breakdown->at(16) += aux;
		}
		if (e->group45a3f0()->unknown9b4350() <= 2)
		{
			if (front == entity618)
			{
				if (!entity618->ai45b590()->unknown459090() || !entity618->ai45b590()->unknown4590f0()->unknown458950(0x37))
					entity618.reset();
				else
				{
					aux = lb43_b97640;
					cell += aux;
					if (breakdown)
						breakdown->at(15) += aux;
				}
			}
			if (front->group45a3f0()->unknown9b4350() == 3)
			{
				for (unsigned int j = 0; j < entities61c.size(); j++)
				{
					if (!entities61c[j].operator->() || !entities61c[j]->ai45b590()->unknown459090() || !entities61c[j]->ai45b590()->unknown4590f0()->unknown458950(0x39))
						lb43_erase9d6440(&entities61c, (int *)&j);
					else if (lb43_distance40a3f0(entities61c[j]->pos45a4a0(), front->pos45a4a0()) <= 3)
					{
						aux = lb43_b97650;
						cell += aux;
						if (breakdown)
							breakdown->at(15) += aux;
					}
				}
			}
		}
		if (front->unknown45a6e0() == 0)
		{
			int integrity = front->unknown5d15a0(false);
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
		aux += lb43_max9cdb60(front->unknown5d22a0(0x52), front->unknown5d22a0(0x61)) / 100.0;
		cell -= aux;
		if (breakdown)
			breakdown->at(8) = -aux;
		if (front->unknown45a700() && (front->unknown44a7d0() == 1 || front->unknown44a7d0() == 7) && !front->unknown45a780())
		{
			switch (front->unknown44a7d0())
			{
				case 1:
					aux = front->unknown45a700() * lb43_b96378;
					break;
				case 7:
					aux = front->unknown45a700() * lb43_b96380;
					break;
			}
			cell += aux;
			if (breakdown)
				breakdown->at(10) += aux;
		}
		if (front->unknown5d1280(false) || front->target45a760())
		{
			cell += 0.1;
			if (breakdown)
				breakdown->at(12) = 0.1f;
		}
		cell += lb43_max9cdb60(0, front->unknown45a990()) / 3000.0;
		if (breakdown)
			breakdown->at(5) = lb43_max9cdb60(0, front->unknown45a990()) / 3000.0f;
		if (lb43_cf4910[front->unknown457820()] != 0)
		{
			if (e == target)
			{
				cell += lb43_b9636c;
				if (breakdown)
					breakdown->at(14) = lb43_b9636c;
			}
			else if (front == target)
			{
				cell -= lb43_b96370;
				if (breakdown)
					breakdown->at(14) = -lb43_b96370;
			}
		}
		if (front == entity600)
		{
			if (e->player5c7600() || e->faction45a2c0() == 0x5e)
			{
				cell += lb43_b95a3c;
				if (breakdown)
					breakdown->at(17) += lb43_b95a3c;
			}
		}
	}
	else if (!lb43_cfd44c(size)->open4550b0() || (lb43_cfd44c(size)->prop45d550().isValid() && !lb43_cfd44c(size)->prop45d550()->unknown65e1d0(LB43HE())))
	{
		cell += 0.1;
		if (breakdown)
			breakdown->at(12) = 0.1f;
	}
	aux = 0;
	vector<LB43P> number;
	vector<int> other;
	vector<int> stepper;
	LB43P flag;
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
	return lb43_max9cd020(0, cell);
}

