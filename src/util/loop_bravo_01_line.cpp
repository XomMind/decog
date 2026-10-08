// NOTE: private aliases isolate nothrow inference for 0x7178d0.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <vector>
using namespace std;

struct LB1Point
{
	int x;
	int y;

	LB1Point() throw();									// 0x453b40
	LB1Point(const LB1Point &p) throw();						// 0x46ca50
	LB1Point &operator=(const LB1Point &p) throw();
	bool operator==(const LB1Point &p) const throw();		// 0x409b90
	bool operator!=(const LB1Point &p) const throw();		// 0x409bd0
};

class LB1Bresenham2DStepperSubcell
{
public:
	LB1Bresenham2DStepperSubcell(const LB1Point &fromCell, const LB1Point &fromSubcell, const LB1Point &toCell, const LB1Point &toSubcell, int subcells_) throw();
	virtual ~LB1Bresenham2DStepperSubcell() throw();
	bool next(LB1Point &cell, LB1Point &subcell) throw();		// NOTE: placeholder name

	int		p04, p08, p0c, p10, p14, p18, p1c, p20, p24, p28, p2c;
};

template <class T>
class LB1Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const LB1Point &p) throw();
	bool contains(const LB1Point &p) throw();	// NOTE: placeholder name (0x9b43b0)
};

class lb1_OpW2B_Grid	// NOTE: placeholder name
{
	int	width;
	int	height;
	int	*data;

public:
	int &operator()(const LB1Point &p) throw();	// 0x9ced70

	int	stamp;	// NOTE: placeholder name
};

class LB1Entity;
class lb1_OpW2B_Prop;

class LB1HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	LB1HEntity();
	bool isNull() const;
	void reset();					// NOTE: placeholder name (0x9b7270)
	bool isValid() const throw();
	bool operator==(LB1HEntity other) const throw();
	LB1Entity *operator->() const throw();		// 0x9b6570
};

class LB1HProp
{
	int	ID;
public:
	bool isValid() const throw();
	lb1_OpW2B_Prop *operator->() const throw();	// 0x9b64f0
};

class lb1_OpW2B_Prop	// NOTE: placeholder name
{
public:
	int unknown45c5f0() throw();	// NOTE: placeholder name
	bool unknown65e1d0(LB1HEntity e);	// NOTE: placeholder name
};

class LB1HItem
{
	int	ID;
public:
	bool isValid() const;
};

class lb1_OpW2B_Part	// NOTE: placeholder name (EntityPart4588f0)
{
public:
	int unknown458950(int type);	// NOTE: placeholder name
};

class lb1_OpW2B_AI	// NOTE: placeholder name (EntityAI)
{
public:
	bool unknown459090();			// NOTE: placeholder name
	bool unknown5814f0(LB1HEntity e);	// NOTE: placeholder name
	lb1_OpW2B_Part *unknown4590f0();	// NOTE: placeholder name
};

class lb1_OpW2_Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();			// NOTE: placeholder name (trivial getter)
};

class lb1_OpW2_HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	lb1_OpW2_Group *operator->() const;	// 0x9b7250
};

class LB1Entity
{
public:
	int unknown45a320() throw();		// NOTE: placeholder name
	const LB1Point &getPosition() throw();	// 0x45a4a0
	LB1Point unknown5c80f0(const LB1Point &p);	// NOTE: placeholder name
	bool unknown45a510(const LB1Point &p);	// NOTE: placeholder name
	bool isPlayer();
	lb1_OpW2B_AI *getAI();					// NOTE: placeholder name (0x45b590)
	void *getTarget();					// 0x45a760
	int getFaction();					// 0x45a2c0
	lb1_OpW2_HGroup getGroup();				// NOTE: placeholder name
	int unknown5c7cb0();				// NOTE: placeholder name
	int unknown5c7cf0();				// NOTE: placeholder name
	int unknown5d7b80();				// NOTE: placeholder name
	int unknown5caee0();				// NOTE: placeholder name
	int unknown5d7b00(int a);			// NOTE: placeholder name
	void unknown5e37a0(LB1HEntity target, float *value);	// NOTE: placeholder name
	int unknown45a6e0();				// NOTE: placeholder name (trivial getter)
	int unknown45a700();				// NOTE: placeholder name
	int unknown44a7d0();				// NOTE: placeholder name (trivial getter)
	int unknown5cab90();				// NOTE: placeholder name
	int unknown45a990();				// NOTE: placeholder name
	bool unknown45ae30();				// NOTE: placeholder name
	lb1_OpW2B_Part *unknown45ae50();		// NOTE: placeholder name
	bool unknown5c7f70();				// NOTE: placeholder name
	int unknown5d15a0(int a);			// NOTE: placeholder name
	int unknown45a340();				// NOTE: placeholder name
	int unknown5d1390();				// NOTE: placeholder name
	bool unknown5ced30();				// NOTE: placeholder name
	bool unknown45aff0();				// NOTE: placeholder name
	LB1HItem unknown5d2380(int slot);		// NOTE: placeholder name
	bool unknown45a780();				// NOTE: placeholder name
	int unknown5d22a0(int type);		// NOTE: placeholder name
	bool unknown5d1280(int a);			// NOTE: placeholder name
	int unknown457820();				// NOTE: placeholder name
};

class LB1Cell
{
public:
	bool unknown45d480() throw();	// NOTE: placeholder name
	bool isOpen();					// NOTE: placeholder name (0x4550b0)
	LB1HProp getProp() throw();		// 0x45d550
	LB1HEntity getEntity() throw();	// 0x45d250
};

extern LB1Array2D<LB1Cell *>	lb1_cells;				// NOTE: placeholder name (0xcfd44c)
extern LB1Array2D<bool>	lb1_opw2_d201c8[];		// NOTE: placeholder name
extern LB1Point			lb1_effectOrigin;		// NOTE: placeholder name (0xd2e20c)
extern vector<int>		lb1_opw2_cf4910;		// NOTE: placeholder name
extern float			lb1_opw2_ba099c[];		// NOTE: placeholder name
extern const float		lb1_opw2_b9b9b4;		// NOTE: placeholder name
extern const float		lb1_opw2_b9b9b0;		// NOTE: placeholder name
extern const float		lb1_opw2_b9763c;		// NOTE: placeholder name
extern const float		lb1_opw2_b97640;		// NOTE: placeholder name
extern const float		lb1_opw2_b97644;		// NOTE: placeholder name
extern const float		lb1_opw2_b97648;		// NOTE: placeholder name
extern const float		lb1_opw2_b97650;		// NOTE: placeholder name
extern const float		lb1_opw2_b97654;		// NOTE: placeholder name
extern const float		lb1_opw2_b96374;		// NOTE: placeholder name
extern const float		lb1_opw2_b9637c;		// NOTE: placeholder name
extern const float		lb1_opw2_b96378;		// NOTE: placeholder name
extern const float		lb1_opw2_b96380;		// NOTE: placeholder name
extern const float		lb1_opw2_b9636c;		// NOTE: placeholder name
extern const float		lb1_opw2_b96370;		// NOTE: placeholder name
extern const float		lb1_opw2_b95a3c;		// NOTE: placeholder name
extern const double		lb1_opw2_c36f08;		// NOTE: placeholder name (120.0)
int lb1_opw2_distance(const LB1Point &a, const LB1Point &b) throw();	// NOTE: placeholder name (0x40a3f0)
int lb1_opw2_maxInt(int a, int b);		// NOTE: placeholder name (0x9cdb60)
float maxf(float a, float b);
void lb1_opw2_eraseAt(vector<LB1HEntity> *v, int *i);	// NOTE: placeholder name (0x9d6440)

class LB1BS
{
public:
	bool unknown7178d0(LB1HEntity e, const LB1Point &from, const LB1Point &fromSub, const LB1Point &to, const LB1Point &toSub, bool useSeen);
	float unknown718430(LB1HEntity e, const LB1Point &p, vector<float> *breakdown, int range);
	float unknown719a90(LB1HEntity e, const LB1Point &p, vector<float> *breakdown, bool *hostileOut);
	bool isVisible(const LB1Point &p);	// 0x4631c0
	int unknown715fe0(int index, const LB1Point &p, int range, bool first);
	bool unknown7170a0(LB1HEntity e, const LB1Point &p, vector<LB1Point> &path, vector<int> &hits, vector<int> &blocks, LB1Point &last, const LB1Point *at, int atMode, bool f1, bool f2);
	int opw3_unknown7279a0(LB1HEntity e);	// NOTE: placeholder name
	int opw3_unknown727ad0(LB1HEntity e);	// NOTE: placeholder name
	bool opw3_unknown7290f0(LB1HEntity e);	// NOTE: placeholder name
	bool unknown71ca20(LB1HEntity e);

	char			pad0[0x268];
	vector<vector<LB1HProp> >	props268;	// 0x268	NOTE: placeholder name
	char			pad278[0x600 - 0x278];
	LB1HEntity			entity600;	// 0x600	NOTE: placeholder name
	char			pad604[0x618 - 0x604];
	LB1HEntity			entity618;	// 0x618	NOTE: placeholder name
	vector<LB1HEntity>	entities61c;	// 0x61c	NOTE: placeholder name
	vector<LB1HEntity>	entities62c;	// 0x62c	NOTE: placeholder name
	char			pad63c[0x66c - 0x63c];
	LB1HEntity			target;		// 0x66c	NOTE: placeholder name
	char			pad670[0x69c - 0x670];
	lb1_OpW2B_Grid		seen;		// 0x69c	NOTE: placeholder name
	char			pad6ac[0x6e8 - 0x6ac];
	lb1_OpW2B_Grid		*fov;		// 0x6e8	NOTE: placeholder name
};

bool LB1BS::unknown7178d0(LB1HEntity e, const LB1Point &from, const LB1Point &fromSub, const LB1Point &to, const LB1Point &toSub, bool useSeen)
{
	LB1Point here;
	LB1Point subPoint;
	LB1Bresenham2DStepperSubcell line(from, fromSub, to, toSub, 9);
	LB1Point lastPos = from;
	line.next(here, subPoint);
	while (here == from)
		line.next(here, subPoint);
	lb1_OpW2B_Grid *visible = 0;
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
		line.next(here, subPoint);
		if (lastPos != here)
		{
			if (here == to)
				return true;
			check = 0;
			if (visible && ((useSeen && seen(here) == 0) || (!useSeen && (*visible)(here) != stamp)))
				type = 0;
			else if (lb1_cells(here)->unknown45d480())
			{
				type = 0;
				return false;
			}
			else if (lb1_cells(here)->getEntity().isValid())
			{
				type = lb1_cells(here)->getEntity()->unknown45a320();
				check = 4;
			}
			else if (lb1_cells(here)->getProp().isValid() && lb1_cells(here)->getProp()->unknown45c5f0())
			{
				type = lb1_cells(here)->getProp()->unknown45c5f0();
				check = 2;
			}
			lastPos = here;
		}
		if (check != 0 && lb1_opw2_d201c8[type](subPoint))
			return false;
	} while (here != to || subPoint != toSub);
	return true;
}
