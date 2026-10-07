// team_c_33: CMap reset (0x7f5fd0): clears the map view state and builds the per-map layout tables
// NOTE: class/member names are placeholders (f<offset>); helper classes and globals are private placeholders
#include <string>
#include <vector>
using namespace std;

struct Point { int x; int y; Point(); Point(const Point &p); Point(const Point &p, int dx, int dy); Point &operator=(const Point &p); };	// NOTE: placeholder
struct Pos : Point { Pos(int x, int y); Pos(int v); };	// NOTE: placeholder
struct HProp { int v; HProp(); bool isNull() const; struct C33_Glyphs *get22c(); };	// NOTE: placeholder
struct C33_Glyphs { int size(); Point *getBuffer_4184d0(); const string &operate(); };	// NOTE: placeholder (folded names)
struct C33_Cell { HProp getProp(); };
struct C33_Cells { int getWidth(); int getHeight(); C33_Cell **at(int x, int y); C33_Cell **at(Point p, int y); };	// NOTE: placeholder (Array2D<Cell *> at 0xcfd44c)
struct C33_Handle { int v; struct C33_Rec23c *get23c(); C33_Glyphs *get22c(); };
struct C33_Rec23c { int f0; int f4; };
struct C33_Rec { char pad[0xf4]; int ff4; };
struct C33_Flag { int v; void resetField(); };	// NOTE: placeholder (resetField folded with Sweep_9b7270)
struct C33_Pt { int x; int y; void operate(int v); void operate(int a, int b); };	// NOTE: placeholder (folded Push_409ff0)
struct C33_Pt2 { int x; int y; void operate(int a, int b); };	// NOTE: placeholder (folded Push_40a010)
struct C33_Noise { char pad[0x40]; void init(int a, float b, int c); };	// NOTE: placeholder (OpR1b_NoiseField::init)
struct C33_Obj;
struct OpQ5_T9e2c40;
struct OpR6_KA_4_1 { int m0; OpR6_KA_4_1 &operator=(const OpR6_KA_4_1 &o); };	// op_r6_ka.cpp
struct OpR6_KA_16_1 { int m0; int m4; int m8; int m12; OpR6_KA_16_1 &operator=(const OpR6_KA_16_1 &o); };
struct OpR6_KA_28_0 { int m0; int m4; int m8; int m12; int m16; int m20; int m24; OpR6_KA_28_0 &operator=(const OpR6_KA_28_0 &o); };
struct OpR6_KA_28_1 { int m0; int m4; int m8; int m12; int m16; int m20; int m24; OpR6_KA_28_1 &operator=(const OpR6_KA_28_1 &o); };
struct Ec_0 { char pad[12]; };	// stl_a.cpp
struct E14_0 { char pad[20]; };
struct C33_Engine { int unknown418980(); int unknown4189a0(); };
struct C33_Resettable { void reset872c80(); void reset873fd0(); };
class C33_Map;
class HEntity { public: int ID; };	// NOTE: placeholder layout
struct CScrapEngineContent { char pad[0x74]; CScrapEngineContent(C33_Map *map); };
struct OpU2_Engine { char pad[0x54]; OpU2_Engine(C33_Map *map, const Pos &size, int flag); };
template <class T> void OpQ5_clearObjects(vector<T*> &v);
int OpX5_maxInt(int a, int b);
int OpU8a_indexOfName(vector<C33_Rec *> *v, const string &name);
bool OpU8a_lookup2(const string &name, int *id);
struct C33_Window { void unknown503b20(); };	// NOTE: placeholder
struct C33_UI { C33_Window *unknown508610(C33_UI *ui, int id, const Pos &a, const Pos &b, int c, int d, int e, int f, int g); };	// NOTE: placeholder (EndObjB::unknown508610)

extern C33_Cells g_cfd44c;	// NOTE: placeholder names below
extern vector< vector<C33_Handle> > g_d31640;
extern vector<int> g_d3862c, g_d31da4, g_d2d28c, g_d2a8a0, g_d01bd8;
extern vector<C33_Rec *> g_d2d1c4;
extern C33_Engine g_d223f0;
extern int g_d1eac0, g_cf27f8, g_cf27f4;
extern bool g_d28d14, g_d28c8b;
extern C33_Handle g_d1e888;
extern C33_Resettable g_d1d9c0;
extern C33_Resettable *g_cec058;
extern OpU2_Engine *g_cefc64;
extern C33_UI *g_cefc50;
extern const float c30_c36f8c;	// NOTE: placeholder name

class C33_Map	// NOTE: placeholder layout (CMap)
{
public:
	char pad0[0x74];
	C33_Flag f74;
	bool f78;
	vector< vector<Point> > f7c;
	int f8c;
	int f90;
	int f94;
	vector<Point> f98;
	vector<int> fa8;
	vector<int> fb8;
	int fc8;
	HProp fcc;
	bool fd0;
	char padd1[0x7];
	bool fd8;
	char paddc[0x4];
	int fe0;
	char pade4[0x8];
	bool fec;
	char padf0[0x8];
	int ff8;
	bool ffc;
	char pad100[0x10];
	C33_Pt f110;
	C33_Flag f118;
	C33_Pt f11c;
	char pad124[0x10];
	int f134;
	char pad138[0x80];
	int f1b8;
	int f1bc;
	int f1c0;
	char pad1c4[0x4];
	vector<C33_Obj *> f1c8;
	char pad1d8[0x10];
	C33_Pt f1e8;
	int f1f0;
	int f1f4;
	int f1f8;
	int f1fc;
	C33_Pt f200;
	C33_Pt f208;
	C33_Flag f210;
	int f214;
	vector<HEntity> f218;
	int f228;
	vector<HEntity> f22c;
	vector<int> f23c;
	vector<int> f24c;
	vector<HEntity> f25c;
	vector<int> f26c;
	vector<OpR6_KA_4_1> f27c;
	vector<int> f28c;
	vector<OpR6_KA_28_0> f29c;
	vector<OpR6_KA_28_0> f2ac;
	vector<E14_0> f2bc;
	vector<Ec_0> f2cc;
	vector<OpR6_KA_28_0> f2dc;
	vector<Point> f2ec;
	vector<int> f2fc;
	vector<int> f30c;
	vector<OpQ5_T9e2c40 *> f31c;
	vector<OpQ5_T9e2c40 *> f32c;
	vector<OpR6_KA_16_1> f33c;
	vector<OpR6_KA_28_1> f34c;
	vector<OpQ5_T9e2c40 *> f35c;
	int f36c;
	CScrapEngineContent * f370;
	int f374;
	int f378;
	bool f37c;
	bool f37d;
	int f380;
	int f384;
	int f388;
	C33_Pt f38c;
	int f394;
	int f398;
	char pad39c[0x8];
	int f3a4;
	char pad3a8[0xac];
	int f454;
	char pad458[0x18];
	C33_Noise f470;
	int f4b0;
	char pad4b4[0x10];
	bool f4c4;
	int f4c8;
	char pad4cc[0x74];
	bool f540;
	vector<Point> f544;
	int f554;
	int f558;
	char pad55c[0xc];
	C33_Pt f568;
	char pad570[0x8];
	C33_Pt f578;
	char pad580[0x8];
	int f588;
	C33_Pt f58c;
	char pad594[0x8];
	C33_Pt f59c;
	char pad5a4[0x20];
	C33_Flag f5c4;
	char pad5c8[0x4];
	int f5cc;
	int f5d0;
	int f5d4;
	int f5d8;
	int f5dc;
	int f5e0;
	int f5e4;
	int f5e8;
	int f5ec;
	int f5f0;
	int f5f4;
	C33_Pt f5f8;
	char pad600[0x10];
	int f610;
	int f614;
	int f618;
	int f61c;
	int f620;
	int f624;
	int f628;
	int f62c;
	int f630;
	int f634;
	int f638;
	int f63c;
	int f640;
	C33_Pt f644;
	int f64c;
	int f650;
	int f654;
	int f658;
	int f65c;
	int f660;
	int f664;
	int f668;
	char pad66c[0x10];
	int f67c;
	int f680;
	char pad684[0x78];
	C33_Pt f6fc;
	C33_Flag f704;
	char pad708[0x10];
	C33_Pt f718;
	char pad720[0x30];
	int f750;
	int f754;
	C33_Pt2 f758;
	int f760;
	char pad764[0x4];
	int f768;
	bool f76c;
	int f770;
	char pad774[0x10];
	C33_Pt f784;
	C33_Pt f78c;
	int f794;
	vector<int> f798;
	int f7a8;
	int f7ac;
	char pad7b0[0x10];
	vector<Point> f7c0;
	vector<Point> f7d0;
	vector<int> f7e0;
	int f7f0;
	C33_Flag f7f4;
	bool f7f8;
	bool f7f9;
	bool f7fa;
	char pad7fb[0x3d];
	bool f838;
	bool f839;
	bool f83a;
	bool f83b;
	bool f83c;
	bool f83d;
	bool f83e;
	bool f83f;
	char pad840[0x10];
	bool f850;
	bool f851;
	char pad854[0x10];
	int f864;
	int f868;
	int f86c;
	bool f870;
	char pad871[0x13];
	bool f884;
	char pad885[0x13];
	bool f898;
	char pad899[0x13];
	bool f8ac;
	bool f8ad;
	bool f8ae;
	bool f8af;
	bool f8b0;
	bool f8b1;
	int f8b4;
	bool f8b8;
	int f8bc;
	int f8c0;

	void unknown808510(const Pos &pos, int count, vector<int> *list);	// NOTE: placeholder names
	void unknown819900();
	void reset(bool refresh);
};

void C33_Map::reset(bool refresh)
{
	int n;
	f74.resetField();
	f78 = 0;
	if (g_d3862c.empty())
	{
		unknown808510(Pos(0, 0), 18, &g_d3862c);
	}
	if (g_d2d28c.empty())
	{
		unknown808510(Pos(0, 0), (g_d2d1c4[OpU8a_indexOfName(&g_d2d1c4, "Cep. Navigation Harness")])->ff4, &g_d2d28c);
	}
	if (g_d31da4.empty())
	{
		unknown808510(Pos(0, 0), 12, &g_d31da4);
	}
	if (g_d2a8a0.empty())
	{
		unknown808510(Pos(0, 0), 24, &g_d2a8a0);
	}
	if (g_d01bd8.empty())
	{
		unknown808510(Pos(0, 0), 22, &g_d01bd8);
	}
	f7c.clear();
	switch (g_d1e888.get23c()->f4)	// DEF=7ae0 END=7ae0
	{
	case 8:
		if (g_d1eac0 == 2 || g_d1eac0 == 3)
	{
		break;
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(74, 49)))->getProp().isNull() || (*(g_cfd44c.at(74, 49)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(74, 49));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(78, 50)))->getProp().isNull() || (*(g_cfd44c.at(78, 50)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(78, 50));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(79, 51)))->getProp().isNull() || (*(g_cfd44c.at(79, 51)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(79, 51));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(80, 52)))->getProp().isNull() || (*(g_cfd44c.at(80, 52)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(80, 52));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(78, 53)))->getProp().isNull() || (*(g_cfd44c.at(78, 53)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(78, 53));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(79, 54)))->getProp().isNull() || (*(g_cfd44c.at(79, 54)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(79, 54));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(75, 55)))->getProp().isNull() || (*(g_cfd44c.at(75, 55)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(75, 55));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(63, 50)))->getProp().isNull() || (*(g_cfd44c.at(63, 50)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(63, 50));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(61, 51)))->getProp().isNull() || (*(g_cfd44c.at(61, 51)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(61, 51));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(60, 52)))->getProp().isNull() || (*(g_cfd44c.at(60, 52)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(60, 52));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(61, 53)))->getProp().isNull() || (*(g_cfd44c.at(61, 53)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(61, 53));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(82, 42)))->getProp().isNull() || (*(g_cfd44c.at(82, 42)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(82, 42));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(84, 43)))->getProp().isNull() || (*(g_cfd44c.at(84, 43)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(84, 43));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(85, 44)))->getProp().isNull() || (*(g_cfd44c.at(85, 44)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(85, 44));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(86, 42)))->getProp().isNull() || (*(g_cfd44c.at(86, 42)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(86, 42));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(88, 42)))->getProp().isNull() || (*(g_cfd44c.at(88, 42)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(88, 42));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(89, 43)))->getProp().isNull() || (*(g_cfd44c.at(89, 43)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(89, 43));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(75, 60)))->getProp().isNull() || (*(g_cfd44c.at(75, 60)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(75, 60));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(76, 60)))->getProp().isNull() || (*(g_cfd44c.at(76, 60)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(76, 60));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(79, 61)))->getProp().isNull() || (*(g_cfd44c.at(79, 61)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(79, 61));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(81, 61)))->getProp().isNull() || (*(g_cfd44c.at(81, 61)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(81, 61));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(83, 62)))->getProp().isNull() || (*(g_cfd44c.at(83, 62)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(83, 62));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(84, 61)))->getProp().isNull() || (*(g_cfd44c.at(84, 61)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(84, 61));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(85, 59)))->getProp().isNull() || (*(g_cfd44c.at(85, 59)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(85, 59));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(59, 41)))->getProp().isNull() || (*(g_cfd44c.at(59, 41)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(59, 41));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(60, 42)))->getProp().isNull() || (*(g_cfd44c.at(60, 42)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(60, 42));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(62, 41)))->getProp().isNull() || (*(g_cfd44c.at(62, 41)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(62, 41));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(63, 42)))->getProp().isNull() || (*(g_cfd44c.at(63, 42)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(63, 42));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(64, 41)))->getProp().isNull() || (*(g_cfd44c.at(64, 41)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(64, 41));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(66, 40)))->getProp().isNull() || (*(g_cfd44c.at(66, 40)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(66, 40));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(68, 41)))->getProp().isNull() || (*(g_cfd44c.at(68, 41)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(68, 41));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(69, 40)))->getProp().isNull() || (*(g_cfd44c.at(69, 40)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(69, 40));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(61, 66)))->getProp().isNull() || (*(g_cfd44c.at(61, 66)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(61, 66));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(63, 64)))->getProp().isNull() || (*(g_cfd44c.at(63, 64)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(63, 64));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(62, 63)))->getProp().isNull() || (*(g_cfd44c.at(62, 63)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(62, 63));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(68, 60)))->getProp().isNull() || (*(g_cfd44c.at(68, 60)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(68, 60));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(50, 48)))->getProp().isNull() || (*(g_cfd44c.at(50, 48)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(50, 48));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(48, 50)))->getProp().isNull() || (*(g_cfd44c.at(48, 50)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(48, 50));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(49, 51)))->getProp().isNull() || (*(g_cfd44c.at(49, 51)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(49, 51));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(48, 52)))->getProp().isNull() || (*(g_cfd44c.at(48, 52)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(48, 52));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(47, 56)))->getProp().isNull() || (*(g_cfd44c.at(47, 56)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(47, 56));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(48, 57)))->getProp().isNull() || (*(g_cfd44c.at(48, 57)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(48, 57));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(50, 58)))->getProp().isNull() || (*(g_cfd44c.at(50, 58)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(50, 58));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(51, 61)))->getProp().isNull() || (*(g_cfd44c.at(51, 61)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(51, 61));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(49, 62)))->getProp().isNull() || (*(g_cfd44c.at(49, 62)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(49, 62));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(50, 64)))->getProp().isNull() || (*(g_cfd44c.at(50, 64)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(50, 64));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(52, 67)))->getProp().isNull() || (*(g_cfd44c.at(52, 67)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(52, 67));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(54, 68)))->getProp().isNull() || (*(g_cfd44c.at(54, 68)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(54, 68));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(23, 82)))->getProp().isNull() || (*(g_cfd44c.at(23, 82)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(23, 82));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(22, 84)))->getProp().isNull() || (*(g_cfd44c.at(22, 84)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(22, 84));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(23, 85)))->getProp().isNull() || (*(g_cfd44c.at(23, 85)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(23, 85));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(21, 86)))->getProp().isNull() || (*(g_cfd44c.at(21, 86)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(21, 86));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(22, 87)))->getProp().isNull() || (*(g_cfd44c.at(22, 87)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(22, 87));
	}
		f7c.push_back(vector<Point>());
		if ((*(g_cfd44c.at(21, 88)))->getProp().isNull() || (*(g_cfd44c.at(21, 88)))->getProp().get22c()->size() == 1)
	{
		f7c.back().push_back(Pos(-1));
	}
	else
	{
		f7c.back().push_back(Pos(21, 88));
	}
		f8c = 40;
		break;
	case 21:
	{
		f7c.push_back(vector<Point>());
		for (int i_50 = 39; i_50 >= 24; i_50--)
	{
		f7c.back().push_back(Pos(i_50, 13));
	}
		f7c.back().push_back(Pos(24, 13));
		f7c.push_back(vector<Point>());
		for (int i_54 = 0; i_54 < 15; i_54++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_58 = 25; i_58 >= 22; i_58--)
	{
		f7c.back().push_back(Pos(i_58, 14));
	}
		f7c.back().push_back(Pos(22, 14));
		f7c.push_back(vector<Point>());
		for (int i_5c = 0; i_5c < 15; i_5c++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_60 = 23; i_60 >= 19; i_60--)
	{
		f7c.back().push_back(Pos(i_60, 15));
	}
		for (int i_64 = 16; i_64 <= 27; i_64++)
	{
		f7c.back().push_back(Pos(19, i_64));
	}
		f7c.back().push_back(Pos(20, 27));
		f7c.push_back(vector<Point>());
		for (int i_68 = 25; i_68 <= 28; i_68++)
	{
		f7c.back().push_back(Pos(20, i_68));
	}
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(20, 30));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(20, 32));
		f7c.push_back(vector<Point>());
		for (int i_6c = 36; i_6c >= 29; i_6c--)
	{
		f7c.back().push_back(Pos(23, i_6c));
	}
		f7c.push_back(vector<Point>());
		for (int i_70 = 0; i_70 < 6; i_70++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_74 = 22; i_74 >= 20; i_74--)
	{
		f7c.back().push_back(Pos(i_74, 31));
	}
		f7c.push_back(vector<Point>());
		for (int i_78 = 0; i_78 < 6; i_78++)
	{
		f7c.back().push_back(Pos(-1));
	}
		f7c.back().push_back(Pos(24, 29));
		f7c.back().push_back(Pos(-1));
		for (int i_7c = 22; i_7c >= 20; i_7c--)
	{
		f7c.back().push_back(Pos(i_7c, 29));
	}
		f7c.push_back(vector<Point>());
		for (int i_80 = 24; i_80 >= 17; i_80--)
	{
		f7c.back().push_back(Pos(i_80, 7));
	}
		f7c.push_back(vector<Point>());
		for (int i_84 = 0; i_84 < 5; i_84++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_88 = 19; i_88 >= 5; i_88--)
	{
		f7c.back().push_back(Pos(i_88, 6));
	}
		for (int i_8c = 7; i_8c <= 8; i_8c++)
	{
		f7c.back().push_back(Pos(5, i_8c));
	}
		n = f7c.back().size();
		f7c.push_back(vector<Point>());
		for (int i_90 = 0; i_90 < n; i_90++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_94 = 4; i_94 <= 6; i_94++)
	{
		f7c.back().push_back(Pos(i_94, 9));
	}
		for (int i_98 = 6; i_98 <= 8; i_98++)
	{
		f7c.back().push_back(Pos(i_98, 10));
	}
		f7c.push_back(vector<Point>());
		for (int i_9c = 0; i_9c < n; i_9c++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_a0 = 4; i_a0 <= 6; i_a0++)
	{
		f7c.back().push_back(Pos(i_a0, 13));
	}
		for (int i_a4 = 6; i_a4 <= 8; i_a4++)
	{
		f7c.back().push_back(Pos(i_a4, 12));
	}
		for (int i_a8 = 6; i_a8 <= 12; i_a8++)
	{
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(i_a8, 7));
	}
		f7c.push_back(vector<Point>());
		for (int i_ac = 0; i_ac < 8; i_ac++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_b0 = 12; i_b0 >= 6; i_b0--)
	{
		f7c.back().push_back(Pos(i_b0, 8));
	}
		for (int i_b4 = 7; i_b4 <= 9; i_b4++)
	{
		f7c.back().push_back(Pos(i_b4, 9));
	}
		f7c.back().push_back(Pos(9, 10));
		for (int i_b8 = 6; i_b8 <= 10; i_b8++)
	{
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(i_b8, 15));
	}
		f7c.push_back(vector<Point>());
		for (int i_bc = 0; i_bc < 8; i_bc++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_c0 = 10; i_c0 >= 6; i_c0--)
	{
		f7c.back().push_back(Pos(i_c0, 14));
	}
		for (int i_c4 = 7; i_c4 <= 9; i_c4++)
	{
		f7c.back().push_back(Pos(i_c4, 13));
	}
		f7c.back().push_back(Pos(9, 12));
		f7c.push_back(vector<Point>());
		for (int i_c8 = 0; i_c8 < 20; i_c8++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_cc = 8; i_cc <= 11; i_cc++)
	{
		f7c.back().push_back(Pos(3, i_cc));
	}
		for (int i_d0 = 4; i_d0 <= 8; i_d0++)
	{
		f7c.back().push_back(Pos(i_d0, 11));
	}
		f7c.push_back(vector<Point>());
		for (int i_d4 = 0; i_d4 < 20; i_d4++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_d8 = 14; i_d8 >= 12; i_d8--)
	{
		f7c.back().push_back(Pos(3, i_d8));
	}
		f7c.push_back(vector<Point>());
		for (int i_dc = 0; i_dc < 20; i_dc++)
	{
		f7c.back().push_back(Pos(-1));
	}
		f7c.back().push_back(Pos(4, 7));
		f7c.back().push_back(Pos(4, 8));
		f7c.back().push_back(Pos(-1, 9));
		f7c.back().push_back(Pos(4, 10));
		for (int i_e0 = 5; i_e0 <= 8; i_e0++)
	{
		f7c.back().push_back(Pos(i_e0, 10));
	}
		f7c.push_back(vector<Point>());
		for (int i_e4 = 0; i_e4 < 20; i_e4++)
	{
		f7c.back().push_back(Pos(-1));
	}
		f7c.back().push_back(Pos(4, 15));
		f7c.back().push_back(Pos(4, 14));
		f7c.back().push_back(Pos(-1, 13));
		f7c.back().push_back(Pos(4, 12));
		for (int i_e8 = 5; i_e8 <= 8; i_e8++)
	{
		f7c.back().push_back(Pos(i_e8, 12));
	}
		f7c.push_back(vector<Point>());
		for (int i_ec = 0; i_ec < 8; i_ec++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_f0 = 20; i_f0 >= 16; i_f0--)
	{
		f7c.back().push_back(Pos(12, i_f0));
	}
		for (int i_f4 = 11; i_f4 >= 5; i_f4--)
	{
		f7c.back().push_back(Pos(i_f4, 16));
	}
		for (int i_f8 = 15; i_f8 >= 14; i_f8--)
	{
		f7c.back().push_back(Pos(5, i_f8));
	}
		for (int i_fc = 22; i_fc <= 26; i_fc++)
	{
		f7c.push_back(vector<Point>());
		for (int i_100 = 4; i_100 <= 9; i_100++)
	{
		f7c.back().push_back(Pos(i_100, i_fc));
	}
	}
		f7c.back().push_back(Pos(9, 27));
		f7c.back().push_back(Pos(9, 28));
		n = f7c.back().size();
		for (int i_104 = 10; i_104 <= 14; i_104++)
	{
		f7c.back().push_back(Pos(i_104, 28));
	}
		f7c.back().push_back(Pos(14, 27));
		f7c.push_back(vector<Point>());
		for (int i_108 = 0; i_108 < n; i_108++)
	{
		f7c.back().push_back(Pos(-1));
	}
		f7c.back().push_back(Pos(10, 29));
		f7c.back().push_back(Pos(11, 29));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(13, 29));
		f7c.back().push_back(Pos(14, 29));
		f7c.back().push_back(Pos(14, 30));
		f7c.push_back(vector<Point>());
		for (int i_10c = 0; i_10c < 8; i_10c++)
	{
		f7c.back().push_back(Pos(-1));
	}
		for (int i_110 = 20; i_110 <= 33; i_110++)
	{
		f7c.back().push_back(Pos(12, i_110));
	}
		f7c.push_back(vector<Point>());
		for (int i_114 = 41; i_114 >= 37; i_114--)
	{
		f7c.back().push_back(Pos(17, i_114));
	}
		for (int i_118 = 17; i_118 >= 12; i_118--)
	{
		f7c.back().push_back(Pos(i_118, 36));
	}
		for (int i_11c = 35; i_11c >= 33; i_11c--)
	{
		f7c.back().push_back(Pos(12, i_11c));
	}
		f7c.push_back(vector<Point>());
		for (int i_120 = 41; i_120 >= 37; i_120--)
	{
		f7c.back().push_back(Pos(18, i_120));
	}
		for (int i_124 = 18; i_124 <= 23; i_124++)
	{
		f7c.back().push_back(Pos(i_124, 36));
	}
		f8c = 0;
		for (unsigned int i_128 = 0; i_128 < f7c.size(); i_128++)
	{
		f8c = OpX5_maxInt(f8c, f7c[i_128].size());
	}
	}
	break;
	case 13:
		for (unsigned int i_12c = 0; i_12c < g_d31640.size(); i_12c++)
	{
		if (!g_d31640[i_12c].empty())
	{
		if (g_d31640[i_12c].front().get22c()->operate() == "GAR_RIF_Installer")
	{
		if (g_d31640[i_12c].front().get22c()->size() != 1)
	{
		Point pos(*g_d31640[i_12c].front().get22c()->getBuffer_4184d0());
		for (unsigned int i_138 = 1; i_138 < g_d31640[i_12c].size(); i_138++)
	{
		if (g_d31640[i_12c][i_138].get22c()->getBuffer_4184d0()->x < pos.x || g_d31640[i_12c][i_138].get22c()->getBuffer_4184d0()->y < pos.y)
	{
		pos = *g_d31640[i_12c][i_138].get22c()->getBuffer_4184d0();
	}
	}
		if ((*(g_cfd44c.at(pos.x, pos.y + 1)))->getProp().isNull())
	{
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Point(pos));
		f7c.back().push_back(Point(pos, 1, 0));
		f7c.back().push_back(Point(pos, 2, 0));
		f7c.back().push_back(Point(pos, 3, 0));
		f7c.back().push_back(Point(pos, 3, 1));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Point(pos, 0, 2));
		f7c.back().push_back(Point(pos, 1, 2));
		f7c.back().push_back(Point(pos, 2, 2));
		f7c.back().push_back(Point(pos, 3, 2));
	}
	else
	{
		if ((*(g_cfd44c.at(pos.x + 1, pos.y)))->getProp().isNull())
	{
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Point(pos));
		f7c.back().push_back(Point(pos, 0, 1));
		f7c.back().push_back(Point(pos, 0, 2));
		f7c.back().push_back(Point(pos, 0, 3));
		f7c.back().push_back(Point(pos, 1, 3));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Point(pos, 2, 0));
		f7c.back().push_back(Point(pos, 2, 1));
		f7c.back().push_back(Point(pos, 2, 2));
		f7c.back().push_back(Point(pos, 2, 3));
	}
	else
	{
		if ((*(g_cfd44c.at(pos.x + 3, pos.y)))->getProp().isNull())
	{
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Point(pos, 0, 3));
		f7c.back().push_back(Point(pos, 0, 2));
		f7c.back().push_back(Point(pos, 0, 1));
		f7c.back().push_back(Point(pos));
		f7c.back().push_back(Point(pos, 1, 0));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Point(pos, 2, 3));
		f7c.back().push_back(Point(pos, 2, 2));
		f7c.back().push_back(Point(pos, 2, 1));
		f7c.back().push_back(Point(pos, 2, 0));
	}
	else
	{
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Point(pos, 3, 0));
		f7c.back().push_back(Point(pos, 2, 0));
		f7c.back().push_back(Point(pos, 1, 0));
		f7c.back().push_back(Point(pos));
		f7c.back().push_back(Point(pos, 0, 1));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Point(pos, 3, 2));
		f7c.back().push_back(Point(pos, 2, 2));
		f7c.back().push_back(Point(pos, 1, 2));
		f7c.back().push_back(Point(pos, 0, 2));
	}
	}
	}
		f8c = f7c.front().size();
	}
	}
	}
	}
		break;
	case 34:
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(106, 70));
		f7c.back().push_back(Pos(109, 67));
		f7c.back().push_back(Pos(115, 64));
		f7c.back().push_back(Pos(111, 82));
		f7c.back().push_back(Pos(121, 79));
		f7c.back().push_back(Pos(125, 73));
		f7c.back().push_back(Pos(125, 74));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(105, 70));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(105, 68));
		f7c.back().push_back(Pos(105, 67));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(105, 65));
		f7c.back().push_back(Pos(105, 64));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(106, 69));
		f7c.back().push_back(Pos(105, 69));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(106, 71));
		f7c.back().push_back(Pos(106, 72));
		f7c.back().push_back(Pos(106, 73));
		f7c.back().push_back(Pos(106, 75));
		f7c.back().push_back(Pos(105, 75));
		f7c.push_back(vector<Point>());
		for (int i_13c = 105; i_13c <= 113; i_13c++)
	{
		f7c.back().push_back(Pos(i_13c, 74));
	}
		f7c.push_back(vector<Point>());
		for (int i_140 = 109; i_140 >= 105; i_140--)
	{
		f7c.back().push_back(Pos(i_140, 66));
	}
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(108, 67));
		f7c.back().push_back(Pos(107, 67));
		f7c.back().push_back(Pos(106, 67));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(106, 65));
		f7c.back().push_back(Pos(106, 64));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(109, 68));
		f7c.back().push_back(Pos(109, 69));
		f7c.back().push_back(Pos(110, 69));
		f7c.back().push_back(Pos(111, 69));
		f7c.back().push_back(Pos(112, 69));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(109, 70));
		f7c.back().push_back(Pos(110, 70));
		f7c.back().push_back(Pos(111, 70));
		f7c.back().push_back(Pos(112, 70));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(109, 71));
		f7c.back().push_back(Pos(110, 71));
		f7c.back().push_back(Pos(111, 71));
		f7c.back().push_back(Pos(112, 71));
		f7c.push_back(vector<Point>());
		for (int i_144 = 111; i_144 >= 107; i_144--)
	{
		f7c.back().push_back(Pos(i_144, 64));
	}
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(116, 64));
		f7c.back().push_back(Pos(117, 64));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(115, 65));
		f7c.back().push_back(Pos(115, 66));
		f7c.back().push_back(Pos(115, 67));
		f7c.back().push_back(Pos(115, 68));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(113, 68));
		f7c.back().push_back(Pos(113, 69));
		f7c.back().push_back(Pos(113, 70));
		f7c.back().push_back(Pos(113, 71));
		f7c.back().push_back(Pos(113, 72));
		f7c.back().push_back(Pos(113, 73));
		f7c.push_back(vector<Point>());
		for (int i_148 = 64; i_148 <= 72; i_148++)
	{
		f7c.back().push_back(Pos(114, i_148));
	}
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(110, 82));
		f7c.back().push_back(Pos(109, 82));
		f7c.back().push_back(Pos(108, 82));
		f7c.back().push_back(Pos(108, 83));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(110, 82));
		f7c.back().push_back(Pos(110, 83));
		f7c.back().push_back(Pos(110, 84));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(111, 83));
		f7c.back().push_back(Pos(111, 84));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(112, 82));
		f7c.back().push_back(Pos(112, 83));
		f7c.back().push_back(Pos(112, 84));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(111, 81));
		f7c.back().push_back(Pos(111, 80));
		f7c.back().push_back(Pos(112, 80));
		f7c.back().push_back(Pos(113, 80));
		f7c.back().push_back(Pos(113, 79));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(112, 82));
		f7c.back().push_back(Pos(113, 82));
		f7c.back().push_back(Pos(114, 82));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(116, 82));
		f7c.back().push_back(Pos(117, 82));
		f7c.back().push_back(Pos(117, 81));
		f7c.back().push_back(Pos(117, 80));
		f7c.back().push_back(Pos(117, 79));
		f7c.back().push_back(Pos(117, 78));
		f7c.back().push_back(Pos(117, 77));
		f7c.push_back(vector<Point>());
		for (int i_14c = 84; i_14c >= 76; i_14c--)
	{
		f7c.back().push_back(Pos(115, i_14c));
	}
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(120, 79));
		f7c.back().push_back(Pos(119, 79));
		f7c.back().push_back(Pos(119, 78));
		f7c.back().push_back(Pos(119, 77));
		f7c.back().push_back(Pos(119, 76));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(121, 80));
		f7c.back().push_back(Pos(122, 80));
		f7c.back().push_back(Pos(123, 80));
		f7c.back().push_back(Pos(124, 80));
		f7c.back().push_back(Pos(124, 79));
		f7c.back().push_back(Pos(124, 78));
		f7c.back().push_back(Pos(124, 77));
		f7c.back().push_back(Pos(124, 76));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(124, 74));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(122, 79));
		f7c.back().push_back(Pos(122, 80));
		f7c.back().push_back(Pos(122, 81));
		f7c.back().push_back(Pos(122, 82));
		f7c.back().push_back(Pos(122, 83));
		f7c.back().push_back(Pos(122, 84));
		f7c.push_back(vector<Point>());
		for (int i_150 = 125; i_150 >= 117; i_150--)
	{
		f7c.back().push_back(Pos(i_150, 75));
	}
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(125, 76));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(123, 76));
		f7c.back().push_back(Pos(122, 76));
		f7c.back().push_back(Pos(121, 76));
		f7c.back().push_back(Pos(120, 76));
		f7c.back().push_back(Pos(119, 76));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(125, 83));
		f7c.back().push_back(Pos(124, 83));
		f7c.back().push_back(Pos(123, 83));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(121, 83));
		f7c.back().push_back(Pos(120, 83));
		f7c.back().push_back(Pos(119, 83));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(119, 83));
		f7c.back().push_back(Pos(118, 83));
		f7c.back().push_back(Pos(118, 84));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(123, 74));
		f7c.back().push_back(Pos(122, 74));
		f7c.back().push_back(Pos(121, 74));
		f7c.back().push_back(Pos(120, 74));
		f7c.back().push_back(Pos(119, 74));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(119, 76));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(119, 76));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(119, 74));
		f7c.back().push_back(Pos(120, 74));
		f7c.back().push_back(Pos(121, 74));
		f7c.back().push_back(Pos(122, 74));
		f7c.back().push_back(Pos(123, 74));
		f7c.push_back(vector<Point>());
		f7c.back().push_back(Pos(124, 74));
		f7c.back().push_back(Pos(-1));
		f7c.back().push_back(Pos(124, 76));
		f7c.back().push_back(Pos(124, 77));
		f7c.back().push_back(Pos(124, 78));
		f7c.back().push_back(Pos(124, 79));
		f7c.back().push_back(Pos(124, 80));
		f7c.back().push_back(Pos(123, 80));
		f7c.back().push_back(Pos(122, 80));
		f8c = 0;
		fb8.assign(f7c.size(), -1);
	}
	f90 = 0;
	f94 = -1;
	f98.clear();
	fa8.clear();
	fc8 = 0;
	fcc = HProp();
	fd0 = 0;
	fd8 = 0;
	fe0 = 0;
	fec = 0;
	ff8 = 0;
	ffc = 0;
	f110.operate(-1);
	f118.resetField();
	f11c.operate(-1);
	f134 = 0;
	f1b8 = 0;
	f1bc = 0;
	f1c0 = 0;
	OpQ5_clearObjects(f1c8);
	f1e8.operate(-1);
	f1f0 = 0;
	f1f4 = 0;
	f1f8 = 0;
	f1fc = -1;
	f200.operate(-1);
	f208.operate(-1);
	f210.resetField();
	f214 = 0;
	f218.clear();
	f228 = 0;
	f22c.clear();
	f23c.clear();
	f24c.clear();
	f25c.clear();
	f26c.clear();
	f27c.clear();
	f28c.clear();
	f29c.clear();
	f2ac.clear();
	f2bc.clear();
	f2cc.clear();
	f2dc.clear();
	f2ec.clear();
	f2fc.clear();
	f30c.clear();
	OpQ5_clearObjects(f31c);
	OpQ5_clearObjects(f32c);
	f33c.clear();
	f34c.clear();
	OpQ5_clearObjects(f35c);
	f36c = 0;
	if (g_d28d14 && !g_d28c8b)
	{
		unknown819900();
	}
	f370 = new CScrapEngineContent(this);
	f374 = 5;
	f378 = 0;
	f37c = 0;
	f37d = 0;
	f380 = 0;
	f384 = 0;
	f388 = 0;
	f38c.operate(-1);
	f394 = 0;
	f398 = 0;
	f3a4 = -1;
	f470.init(2, c30_c36f8c, 200);
	f4c4 = 0;
	f454 = 0;
	f4b0 = 1;
	f4c8 = -1;
	f540 = 0;
	f544.clear();
	f554 = 0;
	f558 = 0;
	f568.operate(-1);
	f578.operate(-1);
	f588 = 0;
	f58c.operate(-1);
	f59c.operate(-1);
	f5c4.resetField();
	f5cc = 0;
	f5d0 = 0;
	f5d4 = 0;
	f5d8 = 0;
	f5dc = 0;
	f5e0 = 0;
	f5e4 = 0;
	f5e8 = 0;
	f5ec = 0;
	f5f0 = 0;
	f5f4 = 0;
	f5f8.operate(-1);
	f610 = 0;
	f614 = 0;
	f618 = 0;
	f61c = 0;
	f620 = 0;
	f624 = 0;
	f628 = 0;
	f62c = 0;
	f630 = 0;
	f634 = 0;
	f638 = 0;
	f63c = 0;
	f640 = 0;
	f644.operate(-1);
	f64c = 0;
	f650 = 0;
	f654 = 0;
	f658 = 0;
	f65c = 0;
	f660 = 0;
	f664 = 0;
	f668 = 0;
	f67c = 0;
	f680 = 7;
	f6fc.operate(-1);
	f704.resetField();
	f718.operate(-1);
	f750 = 0;
	f754 = 0;
	f758.operate(g_d223f0.unknown418980() / 2, g_d223f0.unknown4189a0() / 2);
	f760 = 8;
	f768 = 0;
	f76c = 0;
	f770 = 0;
	f784.operate(-1);
	f78c.operate(-1);
	f794 = 0;
	f798.clear();
	f7a8 = 0;
	f7ac = 0;
	f7c0.clear();
	f7d0.clear();
	f7e0.clear();
	f7f0 = 0;
	f7f4.resetField();
	f7f8 = 0;
	f7f9 = 1;
	f7fa = 0;
	f838 = 0;
	f839 = 0;
	f83a = 0;
	f83b = 0;
	f83c = 0;
	f83d = 0;
	f83e = 0;
	f83f = 0;
	f850 = 0;
	f851 = 0;
	f864 = 0;
	f868 = 0;
	f86c = -1;
	f870 = 0;
	f884 = 0;
	f898 = 0;
	f8ac = 0;
	f8ad = 0;
	f8ae = 0;
	f8af = 0;
	f8b0 = 0;
	f8b1 = 0;
	f8b4 = 0;
	f8b8 = 0;
	f8bc = 0;
	f8c0 = 0;
	g_cefc64 = new OpU2_Engine(this, Pos((g_cfd44c.getWidth() >= g_cf27f4 ? g_cf27f4 - 1 : g_cfd44c.getWidth() - 1), (g_cfd44c.getHeight() >= g_cf27f8 ? g_cf27f8 - 1 : g_cfd44c.getHeight() - 1)), 0);
	if (!refresh)
	{
		int id;
		OpU8a_lookup2("Block_Turn_Progress_InitUI", &id);
		g_cefc50->unknown508610(g_cefc50, id, Pos(0, 0), Pos(0, 0), 0, 0, 0, 9, 0)->unknown503b20();
	}
	if (!refresh)
	{
		g_d1d9c0.reset872c80();
	}
	g_cec058->reset873fd0();
}
