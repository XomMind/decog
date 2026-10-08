// team_d_105: member 0x673b20 (caller GM::readyGame): resets a 0x199-byte per-game state record to its
// defaults (counters, flags, lists, handles and positions; +0x104 gets a fresh random value).
// NOTE: the class layout is partial and every name is a placeholder; the element types of the cleared
// vectors are placeholders chosen to give distinct instantiations.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	void set(int v);	// NOTE: placeholder name (0x409ff0)
	int randomInRange_40c130();
};
extern Point range105_cf39ec;	// NOTE: placeholder name

class HEntity
{
public:
	int ID;
};

class Handle105	// NOTE: placeholder name (a handle with clear(), 0x9b7270)
{
public:
	int ID;
	void clear();
};

template <class T> class OpS8e_Array2D
{
public:
	int	width;
	int	height;
	T	*data;

	void OpS8e_resize(int width_, int height_);
};

struct Ptr105;		// NOTE: placeholder element types
struct Obj105;
struct Pair105 { int a; int b; int c; };
struct Rec105 { int a; int b; int c; int d; };

template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name

class State105	// NOTE: placeholder name and layout
{
public:
	int					unknown00;
	int					unknown04;
	int					unknown08;
	float				unknown0c;
	int					unknown10;
	int					unknown14;
	vector<Ptr105 *>	list18;
	int					unknown28;
	Handle105			handle2c;
	bool				unknown30;
	bool				unknown31;
	int					unknown34;
	int					unknown38;
	int					unknown3c;
	bool				unknown40;
	bool				unknown41;
	int					unknown44;
	bool				unknown48;
	bool				unknown49;
	bool				unknown4a;
	int					unknown4c;
	vector<Obj105 *>	objects50;
	OpS8e_Array2D<int>	grid60;
	int					unknown6c;
	int					unknown70;
	int					unknown74;
	bool				unknown78;
	int					unknown7c;
	int					unknown80;
	int					unknown84;
	int					unknown88;
	int					unknown8c;
	int					unknown90;
	int					unknown94;
	vector<Point>		points98;
	vector<Ptr105 *>	lista8;
	int					unknownb8;
	int					unknownbc;
	Point				posc0;
	Point				posc8;
	int					unknownd0;
	Handle105			handled4;
	vector<HEntity>		entitiesd8;
	char				pade8[4];
	int					unknownec;
	Point				posf0;
	Point				posf8;
	bool				unknown100;
	int					unknown104;
	char				pad108[0x118 - 0x108];
	vector<Point>		points118;
	int					unknown128;
	Point				pos12c;
	int					unknown134;
	int					unknown138;
	int					unknown13c;
	int					unknown140;
	int					unknown144;
	vector<Pair105>		pairs148;
	vector<Rec105>		recs158;
	bool				unknown168;
	vector<Ptr105 *>	list16c;
	int					unknown17c;
	int					unknown180;
	Point				pos184;
	int					unknown18c;
	int					unknown190;
	bool				unknown194;
	bool				unknown195;
	bool				unknown196;
	bool				unknown197;
	bool				unknown198;

	void reset_673b20();	// NOTE: placeholder name
};

void State105::reset_673b20()
{
	unknown00 = 0;
	unknown04 = 0;
	unknown08 = 0;
	unknown0c = 0.0f;
	unknown10 = 0;
	unknown14 = 0;
	list18.clear();
	unknown28 = 0;
	handle2c.clear();
	unknown30 = false;
	unknown31 = false;
	unknown34 = 0;
	unknown38 = 0;
	unknown3c = 0;
	unknown40 = false;
	unknown41 = false;
	unknown44 = 0;
	unknown48 = false;
	unknown49 = false;
	unknown4a = false;
	unknown4c = 0;
	OpQ5_clearObjects(objects50);
	grid60.OpS8e_resize(1,1);
	unknown6c = 0;
	unknown70 = 0;
	unknown74 = 0;
	unknown78 = false;
	unknown7c = 0;
	unknown80 = 0;
	unknown84 = 0;
	unknown88 = 0;
	unknown8c = 0;
	unknown90 = 0;
	unknown94 = -1;
	points98.clear();
	lista8.clear();
	unknownb8 = 0;
	unknownbc = 0;
	posc0.set(-1);
	posc8.set(-1);
	unknownd0 = 0;
	handled4.clear();
	entitiesd8.clear();
	unknownec = 0;
	posf0.set(-1);
	posf8.set(-1);
	unknown100 = false;
	unknown104 = range105_cf39ec.randomInRange_40c130();
	points118.clear();
	unknown128 = 0;
	pos12c.set(-1);
	unknown134 = 0;
	unknown138 = 0;
	unknown13c = 0;
	unknown140 = 0;
	unknown144 = 0;
	pairs148.clear();
	recs158.clear();
	unknown168 = false;
	list16c.clear();
	unknown17c = 0;
	unknown180 = 0;
	pos184.set(-1);
	unknown18c = 0;
	unknown190 = 0;
	unknown194 = false;
	unknown195 = false;
	unknown196 = false;
	unknown197 = false;
	unknown198 = false;
}
