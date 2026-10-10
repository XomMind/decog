// team_d_114: member 0x674aa0 of the per-game state record (see team_d_105; caller BS::unknown6de330): applies
// the core/integrity loss for leaving one map and entering the next (recording stats), the zone bonus, and
// resets the per-map fields.
// NOTE: the class layout is partial and every name is a placeholder; local names follow the stack-slot hash
// order.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	void set(int v);	// NOTE: placeholder name (0x409ff0)
	int randomInRange_40c130();
};
extern Point range114_cf39ec;	// NOTE: placeholder name

class HEntity
{
public:
	int ID;
};

class Handle114	// NOTE: placeholder name (a handle with clear(), 0x9b7270)
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
	void init_9cf690(int width_, int height_, int fill_);	// NOTE: placeholder name
};

struct Ptr114;		// NOTE: placeholder element types
struct Obj114;
struct Pair114 { int a; int b; int c; };
struct Rec114 { int a; int b; int c; int d; };

template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name


struct Location114	// NOTE: placeholder name and layout
{
	int		unknown00;
	int		type;	// +0x04
};

class HLocation114	// NOTE: placeholder name
{
public:
	int ID;
	Location114 *operator->() const;	// NOTE: OpC_Handle::get23c
};
extern HLocation114 location114_d1e888;	// NOTE: placeholder name
extern vector<HLocation114> locations114_d1e88c;	// NOTE: placeholder name

struct LossPair114	// NOTE: placeholder name
{
	int		leave;
	int		enter;
};
extern LossPair114 coreLoss114_b91a40[];	// NOTE: placeholder name
extern int coreLossByDifficulty114_ba6550[][3];	// NOTE: placeholder name
extern int mapFlag114_b90000[];		// NOTE: placeholder name
extern int mapFlag114_b90098[];		// NOTE: placeholder name
extern LossPair114 surgicalBlocks114_b90290[];	// NOTE: placeholder name
extern int minCore114_b91b88;		// NOTE: placeholder name
extern int difficulty114_cf4718;	// NOTE: placeholder name
extern int flag114_cf4724;			// NOTE: placeholder name
extern int flag114_cf4740;			// NOTE: placeholder name

int OpX5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
void OpC_clampMin(int *v, int m);
void OpC_clampMax(int *value, int max);
int abs(int x);
#pragma intrinsic(abs)

class Stats114	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern Stats114 stats114_d2c658;	// NOTE: placeholder name

class GameData114	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	bool unknown46f4b0(int a);	// NOTE: placeholder name
};
extern GameData114 gameData114_d1e860;	// NOTE: placeholder name

class CellGrid114	// NOTE: placeholder name (0xcfd44c)
{
public:
	int getWidth();
	int getHeight();
};
extern CellGrid114 cells114_cfd44c;	// NOTE: placeholder name

class State114	// NOTE: placeholder name and layout
{
public:
	int					unknown00;
	int					unknown04;
	int					unknown08;
	float				unknown0c;
	int					unknown10;
	int					unknown14;
	vector<Ptr114 *>	list18;
	int					unknown28;
	Handle114			handle2c;
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
	vector<Obj114 *>	objects50;
	OpS8e_Array2D<int>	surgicalExplored;
	int					lastDispatchTurn;
	int					surgicalTimer;
	int					unknown74;
	bool				unknown78;
	int					unknown7c;
	int					unknown80;
	int					extraTrackers;
	int					unknown88;
	int					unknown8c;
	int					unknown90;
	int					unknown94;
	vector<Point>		points98;
	vector<Ptr114 *>	lista8;
	int					unknownb8;
	int					unknownbc;
	Point				posc0;
	Point				posc8;
	int					unknownd0;
	Handle114			handled4;
	vector<HEntity>		entitiesd8;
	Handle114			handlee8;
	char				padec[4];
	Point				posf0;
	Point				posf8;
	bool				unknown100;
	int					unknown104;
	vector<Obj114 *>	objects108;
	vector<Point>		points118;
	int					failedDispatches;
	Point				pos12c;
	int					unknown134;
	int					unknown138;
	int					unknown13c;
	int					unknown140;
	int					unknown144;
	vector<Pair114>		pairs148;
	vector<Rec114>		recs158;
	bool				unknown168;
	vector<Ptr114 *>	list16c;
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

	void init(HLocation114 from, HLocation114 to);	// NOTE: placeholder name
};

void State114::init(HLocation114 from, HLocation114 to)
{
	int last = unknown00;
	int cur = unknown00;
	int value = OpX5_minInt(coreLoss114_b91a40[from->type].leave + coreLossByDifficulty114_ba6550[0][difficulty114_cf4718],100);
	unknown00 = unknown00 * (100 - value) / 100;
	unknown04 = cur ? unknown04 * unknown00 / cur : 0;
	cur = unknown00;
	value = OpX5_minInt(coreLoss114_b91a40[to->type].enter + coreLossByDifficulty114_ba6550[1][difficulty114_cf4718],100);
	unknown00 = (100 - value) * unknown00 / 100;
	unknown04 = cur ? unknown04 * unknown00 / cur : 0;
	if (abs(last - unknown00))
	{
		stats114_d2c658.add4729d0(0x229,abs(last - unknown00),"",-1);
		stats114_d2c658.add4729d0(0x22a,abs(last - unknown00),"",-1);
	}
	if (mapFlag114_b90000[to->type] == 1)
	{
		int amount = OpX5_minInt(unknown08,0x384);
		unknown00 += amount;
		unknown04 += amount;
		stats114_d2c658.add4729d0(0x219,amount,"",-1);
		stats114_d2c658.add4729d0(0x224,amount,"",-1);
	}
	OpC_clampMax(&unknown04,unknown00);
	if (to->type == 0x22)
		unknown04 = 0;
	OpC_clampMin(&unknown00,unknown34 && mapFlag114_b90000[to->type] == 1 ? minCore114_b91b88 : 0);
	unknown08 = 0;
	unknown0c = 0.0f;
	unknown10 = 0;
	unknown14 = 0;
	unknown30 = mapFlag114_b90098[to->type] != 0 && flag114_cf4724 == 0 && flag114_cf4740 == 0;
	if (locations114_d1e88c.size() > 3 && locations114_d1e88c[locations114_d1e88c.size() - 2]->type == 0xe)
		unknown30 = false;
	unknown34 = 0;
	unknown38 = 1;
	unknown3c = 100;
	unknown41 = unknown40;
	unknown44 = 0;
	unknown48 = false;
	unknown49 = false;
	unknown4a = false;
	unknown4c = 0;
	unknown40 = false;
	if (gameData114_d1e860.unknown46f4b0(1) && location114_d1e888->type != 0x23)
		stats114_d2c658.add4729d0(0x217,unknown00,"",-1);
	surgicalExplored.init_9cf690(cells114_cfd44c.getWidth() / surgicalBlocks114_b90290[location114_d1e888->type].leave + 1,cells114_cfd44c.getHeight() / surgicalBlocks114_b90290[location114_d1e888->type].leave + 1,0);
	lastDispatchTurn = 0;
	unknown74 = 0;
	unknown78 = false;
	unknown7c = 0;
	extraTrackers = 0;
	unknown8c = 0;
	unknown194 = to->type == 0x22;
	unknown195 = false;
	unknown196 = false;
	unknown197 = false;
	unknown198 = false;
	points98.clear();
	lista8.clear();
	unknownb8 = 0;
	unknownbc = 0;
	posc0.set(-1);
	posc8.set(-1);
	unknownd0 = 0;
	handled4.clear();
	entitiesd8.clear();
	handlee8.clear();
	posf0.set(-1);
	posf8.set(-1);
	unknown100 = false;
	OpQ5_clearObjects(objects108);
	points118.clear();
	failedDispatches = 0;
	pos12c.set(-1);
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
	unknown190 = 0x4b0;
}
