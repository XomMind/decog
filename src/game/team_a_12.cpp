// team_a_12: constructors/destructors of namespace-scope singletons (class names shared with team_d_04.cpp / cc_r2_30.cpp, which
// declare them for the ??__E/??__F wrappers). Constructors are defined here only for 0x45eab0 and 0x45fae0.
// NOTE: layouts are partial. Callees declared throw() are proven nothrow by LTCG in the real link.
#include <string>
#include <vector>
using namespace std;

template <class T> class OpX5_Array2D	// NOTE: placeholder name (defined in op_x5.cpp; the exe folds the destructor with freeCells)
{
public:
	int width;
	int height;
	T *cells;
	OpX5_Array2D() throw();
	~OpX5_Array2D();
};

struct OpR6_KA_36_0
{
	int m0;
	int m4;
	int m8;
	int m12;
	int m16;
	int m20;
	int m24;
	int m28;
	int m32;
	OpR6_KA_36_0 &operator=(const OpR6_KA_36_0 &o);
};

class Console;
extern vector<Console *> consoles_cf4590;	// NOTE: placeholder name (0xcf4590)
extern vector<Console *> consoles_d1ecc0;	// NOTE: placeholder name (0xd1ecc0)
extern vector<Console *> consoles_d1defc;	// NOTE: placeholder name (0xd1defc)

class Owned_449540	// NOTE: placeholder name (scalar deleting destructor 0x449540)
{
public:
	~Owned_449540();
};
extern Owned_449540 *owned_cefb54;	// NOTE: placeholder name (0xcefb54)

class Unknown_4493c0_449420	// NOTE: placeholder name (shared with team_d_04.cpp; constructor not defined here)
{
public:
	string unknown0;
	string unknown1c;
	char pad38[0x40 - 0x38];
	vector<OpR6_KA_36_0> unknown40;
	char pad50[0x58 - 0x50];
	OpX5_Array2D<int> unknown58;
	OpX5_Array2D<int> unknown64;
	OpX5_Array2D<int> unknown70;
	Unknown_4493c0_449420();
	~Unknown_4493c0_449420();
};

Unknown_4493c0_449420::~Unknown_4493c0_449420()
{
	delete owned_cefb54;
	consoles_cf4590.clear();
	consoles_d1ecc0.clear();
	consoles_d1defc.clear();
}

template <class T> void deleteVector(vector<T*> &v) throw();	// NOTE: placeholder name (0x9d21f0 for Console)
class Owned_43aeb0	// NOTE: placeholder name (scalar deleting destructor 0x43aeb0)
{
public:
	~Owned_43aeb0() throw();
};

class Unknown_45fe00_45fe80	// NOTE: placeholder name (shared with team_d_04.cpp; constructor not defined here)
{
public:
	char pad0[0x10];
	vector<unsigned int> unknown10;
	vector<unsigned int> unknown20;
	vector<unsigned int> unknown30;
	char pad40[0x48 - 0x40];
	vector<unsigned int> unknown48;
	vector<Console *> unknown58;
	Owned_43aeb0 *unknown68;
	char pad6c[0x70 - 0x6c];
	vector<unsigned int> unknown70;
	char pad80[0x84 - 0x80];
	vector<unsigned int> unknown84;
	Unknown_45fe00_45fe80();
	~Unknown_45fe00_45fe80();
};

Unknown_45fe00_45fe80::~Unknown_45fe00_45fe80()
{
	deleteVector(unknown58);
	delete unknown68;
}

struct OpQ5_T9ed630;
struct ItemType_d2d1c4;
extern string gameString_d21928;	// NOTE: placeholder name (0xd21928)
extern string gameString_cf33fc;	// NOTE: placeholder name (0xcf33fc)
extern vector<ItemType_d2d1c4 *> itemTypes_d2d1c4;	// NOTE: placeholder name (0xd2d1c4)
extern vector<string> opR1f_d33d28;	// NOTE: placeholder name
extern vector<string> vec_d33d48;	// NOTE: placeholder name
void resetCount_466840();	// NOTE: placeholder name
void resetCount_466a00();	// NOTE: placeholder name

struct Unknown467710	// NOTE: placeholder name (shared with cc_r2_30.cpp; constructor not defined here)
{
	string unknown0;
	string unknown1c;
	int unknown38;
	string unknown3c;
	char pad58[0xb8 - 0x58];
	string unknownB8;
	string unknownD4;
	bool unknownF0;
	char padF1[0xf4 - 0xf1];
	string unknownF4;
	bool unknown110;
	int unknown114;
	int unknown118;
	int unknown11c;
	int unknown120;
	int unknown124;
	vector<int> unknown128;
	string unknown138;
	int unknown154;
	vector<string> unknown158;
	vector<int> unknown168;
	vector<string> unknown178;
	vector<OpQ5_T9ed630 *> unknown188;
	vector<string> unknown198;
	int unknown1a8;
	bool unknown1ac;
	bool unknown1ad;
	bool unknown1ae;
	bool unknown1af;
	bool unknown1b0;
	int unknown1b4;
	int unknown1b8;
	bool unknown1bc;
	bool unknown1bd;
	bool unknown1be;
	bool unknown1bf;
	bool unknown1c0;
	bool unknown1c1;
	bool unknown1c2;
	bool unknown1c3;
	bool unknown1c4;
	Unknown467710();
	~Unknown467710();
	void reset();
};

void deleteObjects_467710(vector<OpQ5_T9ed630 *> &v) throw();	// NOTE: placeholder name (OpQ5_deleteObjects<OpQ5_T9ed630>, nothrow in the exe)

Unknown467710::~Unknown467710()
{
	deleteObjects_467710(unknown188);
}

class HExplosive	// NOTE: placeholder layout
{
	int	ID;
};

struct OpR6_KCDA_16_1
{
	int m0;
	int m4;
	int m8;
	int m12;
	OpR6_KCDA_16_1();
	OpR6_KCDA_16_1(const OpR6_KCDA_16_1 &o);
	OpR6_KCDA_16_1 &operator=(const OpR6_KCDA_16_1 &o);
	~OpR6_KCDA_16_1();
};

struct OpR6_KA_16_0
{
	int m0;
	int m4;
	int m8;
	int m12;
	OpR6_KA_16_0 &operator=(const OpR6_KA_16_0 &o);
};

struct Point
{
	int	x;
	int	y;
};

class HProp
{
public:
	int ID;
	HProp() throw();							// 0x9b6590
};

class Push_453b40	// NOTE: placeholder name (8-byte value type, constructor 0x453b40)
{
public:
	int a;
	int b;
	Push_453b40() throw();
};

struct OpX5_S14;

struct Init_45f020	// NOTE: placeholder name (constructor 0x45f020)
{
	int a;
	int b;
	Init_45f020() throw();
};

struct Init_45faa0	// NOTE: placeholder name (constructor 0x45faa0)
{
	int a;
	int b;
	int c;
	Init_45faa0() throw();
};

struct Area_45fae0	// NOTE: placeholder name (an Area; unique name so the nothrow declaration is the only one)
{
	Point min;
	Point max;
	Area_45fae0() throw();	// 0x40b100
};

extern bool flag_cefb26;	// NOTE: placeholder name (0xcefb26)
extern vector<string> strings_d2d4c8;	// NOTE: placeholder name (0xd2d4c8)

class Unknown_45fae0_45fbd0	// NOTE: placeholder name (shared with team_d_04.cpp)
{
public:
	char pad0[0xc];
	HProp unknownC;
	char pad10[0x18 - 0x10];
	Init_45f020 unknown18;
	vector<unsigned int> unknown20;
	vector<unsigned int> unknown30;
	vector<unsigned int> unknown40;
	vector<unsigned int> unknown50;
	vector<unsigned int> unknown60;
	char pad70[0xa8 - 0x70];
	Init_45faa0 unknownA8;
	vector<unsigned int> unknownB4;
	char padC4[0x120 - 0xc4];
	vector<unsigned int> unknown120;
	vector<unsigned int> unknown130;
	char pad140[0x144 - 0x140];
	HProp unknown144;
	vector<OpR6_KCDA_16_1> unknown148;
	char pad158[0x16c - 0x158];
	Area_45fae0 unknown16c;
	char pad17c[0x184 - 0x17c];
	vector<unsigned int> unknown184;
	char pad194[0x198 - 0x194];
	vector<HExplosive> unknown198;
	char pad1a8[0x1b4 - 0x1a8];
	HProp unknown1b4;
	Unknown_45fae0_45fbd0();
	~Unknown_45fae0_45fbd0();
};

Unknown_45fae0_45fbd0::Unknown_45fae0_45fbd0()
{
}

Unknown_45fae0_45fbd0::~Unknown_45fae0_45fbd0()
{
	if (flag_cefb26)
		strings_d2d4c8.clear();
}

struct OpQ5_T9d1d80;
struct OpV4d_Trivial;
void OpV4d_deleteMapRecords(vector<OpV4d_Trivial*> &v) throw();	// NOTE: placeholder name

class Unknown_45eab0_45ebd0	// NOTE: placeholder name (shared with team_d_04.cpp)
{
public:
	char pad0[0x18];
	vector<unsigned int> unknown18;
	char pad28[0x2c - 0x28];
	HProp unknown2c;
	char pad30[0x50 - 0x30];
	vector<OpQ5_T9d1d80 *> unknown50;
	OpX5_Array2D<OpX5_S14> unknown60;
	char pad6c[0x90 - 0x6c];
	void *unknown90;
	char pad94[0x98 - 0x94];
	vector<Point> unknown98;
	vector<unsigned int> unknownA8;
	char padB8[0xc0 - 0xb8];
	Push_453b40 unknownC0;
	Push_453b40 unknownC8;
	char padD0[0xd4 - 0xd0];
	HProp unknownD4;
	vector<HExplosive> unknownD8;
	HProp unknownE8;
	char padEc[0xf0 - 0xec];
	Push_453b40 unknownF0;
	Push_453b40 unknownF8;
	char pad100[0x108 - 0x100];
	vector<OpV4d_Trivial *> unknown108;
	vector<Point> unknown118;
	char pad128[0x12c - 0x128];
	Push_453b40 unknown12c;
	char pad134[0x148 - 0x134];
	vector<OpR6_KCDA_16_1> unknown148;
	vector<OpR6_KA_16_0> unknown158;
	char pad168[0x16c - 0x168];
	vector<unsigned int> unknown16c;
	char pad17c[0x184 - 0x17c];
	Push_453b40 unknown184;
	Unknown_45eab0_45ebd0();
	~Unknown_45eab0_45ebd0();
};

Unknown_45eab0_45ebd0::Unknown_45eab0_45ebd0()
{
}

void deleteObjects_45ebd0(vector<OpQ5_T9d1d80 *> &v) throw();	// NOTE: placeholder name (OpQ5_deleteObjects<OpQ5_T9d1d80>, nothrow in the exe)

Unknown_45eab0_45ebd0::~Unknown_45eab0_45ebd0()
{
	deleteObjects_45ebd0(unknown50);
	delete unknown90;
	OpV4d_deleteMapRecords(unknown108);
}

struct OpT8a_VBase;
void OpT8a_deleteVectorContents(vector<OpT8a_VBase*> &v);	// NOTE: placeholder name
class Owned_449070	// NOTE: placeholder name (scalar deleting destructor 0x449070)
{
public:
	~Owned_449070();
};
extern Owned_449070 *owned_cefb50;	// NOTE: placeholder name (0xcefb50)
extern vector<Console *> consoles_cfb678;	// NOTE: placeholder name (0xcfb678)
extern vector<Console *> consoles_d2e224;	// NOTE: placeholder name (0xd2e224)
struct TeamA_E8_448ed0	// NOTE: placeholder 8-byte element type
{
	int a;
	int b;
};

class Unknown_448e60_448ed0	// NOTE: placeholder name (shared with team_d_04.cpp; constructor not defined here)
{
public:
	string unknown0;
	string unknown1c;
	char pad38[0x44 - 0x38];
	vector<OpT8a_VBase *> unknown44;
	vector<Point> unknown54;
	vector<Point> unknown64;
	char pad74[0x8c - 0x74];
	vector<TeamA_E8_448ed0> unknown8c;
	vector<TeamA_E8_448ed0> unknown9c;
	vector<Point> unknownAc;
	Unknown_448e60_448ed0();
	~Unknown_448e60_448ed0();
};

Unknown_448e60_448ed0::~Unknown_448e60_448ed0()
{
	OpT8a_deleteVectorContents(unknown44);
	delete owned_cefb50;
	consoles_cfb678.clear();
	consoles_d2e224.clear();
}

void Unknown467710::reset()
{
	unknown0 = gameString_d21928;
	unknown1c = gameString_cf33fc;
	unknown38 = 0;
	unknownB8.clear();
	unknownD4.clear();
	unknownF0 = true;
	unknown110 = false;
	unknown114 = 0;
	unknown118 = 0;
	unknown11c = 0;
	unknown120 = 0;
	unknown124 = 0;
	unknown128.assign(10u,0u);
	unknown138 = "";
	unknown154 = 0;
	unknown168.assign(itemTypes_d2d1c4.size(),0);
	unknown178.clear();
	unknown188.clear();
	unknown198.clear();
	unknown1a8 = 0;
	unknown1ac = false;
	unknown1ad = false;
	unknown1ae = false;
	unknown1af = false;
	unknown1b0 = false;
	unknown1b4 = -11;
	unknown1b8 = -1;
	unknown1bc = false;
	unknown1bd = false;
	unknown1be = false;
	unknown1bf = false;
	unknown1c0 = false;
	unknown1c1 = false;
	unknown1c2 = false;
	unknown1c3 = false;
	unknown1c4 = false;
	opR1f_d33d28.clear();
	resetCount_466840();
	vec_d33d48.clear();
	resetCount_466a00();
}
