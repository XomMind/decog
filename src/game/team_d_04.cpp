// team_d_04: dynamic initializers (and atexit destructors) of colour, handle, protobuf and other class globals
// NOTE: all global names are placeholders carrying the exe data address; types come from the
// constructor/destructor callees.
#include <vector>
#include <string>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();
	XColor(int r_, int g_, int b_);
	XColor(const XColor &c);
};

class HProp	// NOTE: placeholder layout
{
	int ID;
public:
	HProp();
};

struct LogColorEntry	// NOTE: placeholder layout
{
	int a[2];

	LogColorEntry();
};

namespace google { namespace protobuf { namespace internal {
class RepeatedPtrFieldBase	// NOTE: placeholder layout (constructor is protected in the exe)
{
	void **elements_;
	int current_size_;
	int allocated_size_;
	int total_size_;
public:
	RepeatedPtrFieldBase();
};
} } }
using google::protobuf::internal::RepeatedPtrFieldBase;

class Unknown_438ab0_4489f0	// NOTE: placeholder name (constructor sub_438ab0, destructor Wrapper_4489f0::cleanup)
{
	int pad[4];
public:
	Unknown_438ab0_4489f0();
	~Unknown_438ab0_4489f0();
};

class Unknown_4588d0_439630	// NOTE: placeholder name (constructor sub_4588d0, destructor sub_439630)
{
	int pad[4];
public:
	Unknown_4588d0_439630();
	~Unknown_4588d0_439630();
};

class Unknown_43aee0_446260	// NOTE: placeholder name (constructor OpR1d_Report::OpR1d_Report, destructor sub_446260)
{
	int pad[4];
public:
	Unknown_43aee0_446260();
	~Unknown_43aee0_446260();
};

class Unknown_448e60_448ed0	// NOTE: placeholder name (constructor Calls_448e60::delegate, destructor sub_448ed0)
{
	int pad[4];
public:
	Unknown_448e60_448ed0();
	~Unknown_448e60_448ed0();
};

class Unknown_4493c0_449420	// NOTE: placeholder name (constructor Calls_4493c0::delegate, destructor sub_449420)
{
	int pad[4];
public:
	Unknown_4493c0_449420();
	~Unknown_4493c0_449420();
};

class Unknown_454340_4543b0	// NOTE: placeholder name (constructor sub_454340, destructor sub_4543b0)
{
	int pad[4];
public:
	Unknown_454340_4543b0();
	~Unknown_454340_4543b0();
};

class Unknown_456200_456230	// NOTE: placeholder name (constructor Calls_456200::delegate, destructor Calls_456230::delegate)
{
	int pad[4];
public:
	Unknown_456200_456230();
	~Unknown_456200_456230();
};

class Unknown_45eab0_45ebd0	// NOTE: placeholder name (constructor sub_45eab0, destructor sub_45ebd0)
{
	int pad[4];
public:
	Unknown_45eab0_45ebd0();
	~Unknown_45eab0_45ebd0();
};

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
};

class HExplosive	// NOTE: placeholder layout
{
	int ID;
};

struct VE_KCDA_16_1 { int a[4]; };	// NOTE: placeholder vector element type

struct Owned_45f830 { ~Owned_45f830(); };	// NOTE: placeholder name (scalar deleting destructor 0x45f830)
struct Owned_45f860 { ~Owned_45f860(); };	// NOTE: placeholder name (scalar deleting destructor 0x45f860)
struct Owned_45f890 { ~Owned_45f890(); };	// NOTE: placeholder name (scalar deleting destructor 0x45f890)
struct Owned_45c220 { ~Owned_45c220(); };	// NOTE: placeholder name (scalar deleting destructor 0x45c220)

class Unknown_45f320_45f560	// NOTE: placeholder name (constructor sub_45f320, destructor sub_45f560); layout from the destructor
{
public:
	Unknown_45f320_45f560();
	~Unknown_45f320_45f560();

	vector<unsigned int>	unknown000;
	vector<unsigned int>	unknown010;
	Owned_45f830			*unknown020;
	char					pad024[0x34 - 0x24];
	Owned_45f860			*unknown034;
	char					pad038[0x44 - 0x38];
	vector<unsigned int>	unknown044;
	vector<unsigned int>	unknown054;
	char					pad064[0x68 - 0x64];
	Owned_45f890			*unknown068;
	char					pad06c[0x70 - 0x6c];
	vector<unsigned int>	unknown070;
	char					pad080[0x88 - 0x80];
	vector<HExplosive>		unknown088;
	vector<Point>			unknown098;
	vector<Point>			unknown0a8;
	vector<HExplosive>		unknown0b8;
	char					pad0c8[0xdc - 0xc8];
	vector<HExplosive>		unknown0dc;
	char					pad0ec[0x100 - 0xec];
	string					unknown100;
	char					pad11c[0x124 - 0x11c];
	vector<unsigned int>	unknown124;
	char					pad134[0x154 - 0x134];
	vector<HExplosive>		unknown154;
	vector<Point>			unknown164;
	vector<unsigned int>	unknown174;
	char					pad184[0x1cc - 0x184];
	Owned_45c220			*unknown1cc;
	char					pad1d0[0x1d4 - 0x1d0];
	Owned_45c220			*unknown1d4;
	vector<Point>			unknown1d8;
	vector<Point>			unknown1e8;
	vector<HExplosive>		unknown1f8;
	vector<char>			unknown208;
	char					pad218[0x21c - 0x218];
	vector<VE_KCDA_16_1>	unknown21c;
	char					pad22c[0x234 - 0x22c];
	vector<unsigned int>	unknown234;
	vector<unsigned int>	unknown244;
	vector<HExplosive>		unknown254;
	vector<HExplosive>		unknown264;
	vector<HExplosive>		unknown274;
};

Unknown_45f320_45f560::~Unknown_45f320_45f560()
{
	delete unknown020;
	delete unknown034;
	delete unknown068;
	delete unknown1cc;
	delete unknown1d4;
}

class Unknown_45fae0_45fbd0	// NOTE: placeholder name (constructor sub_45fae0, destructor sub_45fbd0)
{
	int pad[4];
public:
	Unknown_45fae0_45fbd0();
	~Unknown_45fae0_45fbd0();
};

class Unknown_45fe00_45fe80	// NOTE: placeholder name (constructor Calls_45fe00::delegate, destructor sub_45fe80)
{
	int pad[4];
public:
	Unknown_45fe00_45fe80();
	~Unknown_45fe00_45fe80();
};

class Unknown_4c1840	// NOTE: placeholder name (constructor OpW7_PathMoveCost::OpW7_PathMoveCost)
{
	int pad[4];
public:
	Unknown_4c1840();
};

class Unknown_4dbd80	// NOTE: placeholder name (constructor ??0StaticDescriptorInitializer@protobuf_scoresheet_2eproto@@QAE@XZ)
{
	int pad[4];
public:
	Unknown_4dbd80();
};

struct Unknown3	// NOTE: placeholder name (as in cc_r2_24.cpp)
{
	char pad[3];
};

extern Unknown3&	ptr_cf6b24;

XColor	cols_cfe5a8[20];
XColor	col_d31654(8, 8, 8);
LogColorEntry	unks_d01618[31];
XColor	cols_d216f8[11];
XColor	cols_d01714[4] =
{
	XColor(0, 0, 0),
	XColor(65, 65, 65),
	XColor(75, 75, 75),
	XColor(90, 90, 90)
};
RepeatedPtrFieldBase	rpfs_d01a14[3];
RepeatedPtrFieldBase	rpfs_d30234[3];
RepeatedPtrFieldBase	rpf_cf4564;
RepeatedPtrFieldBase	rpf_d358b0;
RepeatedPtrFieldBase	rpf_d31680;
RepeatedPtrFieldBase	rpf_d1e844;
RepeatedPtrFieldBase	rpf_cf27ec;
RepeatedPtrFieldBase	rpf_d1e1c8;
RepeatedPtrFieldBase	rpf_d38464;
RepeatedPtrFieldBase	rpf_cfb78c;
RepeatedPtrFieldBase	rpf_d35e08;
RepeatedPtrFieldBase	rpf_d33be0;
RepeatedPtrFieldBase	rpf_d31690;
RepeatedPtrFieldBase	rpf_d20464;
RepeatedPtrFieldBase	rpf_cf0da8;
RepeatedPtrFieldBase	rpf_d32e00;
RepeatedPtrFieldBase	rpf_d32ebc;
RepeatedPtrFieldBase	rpf_d22f7c;
RepeatedPtrFieldBase	rpf_d2a88c;
RepeatedPtrFieldBase	rpf_d21e48;
RepeatedPtrFieldBase	rpf_d316b4;
RepeatedPtrFieldBase	rpf_d3238c;
RepeatedPtrFieldBase	rpf_d2975c;
XColor	col_d29804(0, 0, 0);
XColor	cols_d329a4[14];
XColor	cols_d29ae0[7];
Unknown_438ab0_4489f0	unk_d338cc;
Unknown_4588d0_439630	unk_d28c54;
Unknown_43aee0_446260	unk_d28c68;
XColor	cols_cf127c[9] =
{
	XColor(20, 20, 20),
	XColor(77, 62, 39),
	XColor(178, 89, 0),
	XColor(51, 41, 26),
	XColor(56, 56, 56),
	XColor(0, 0, 0),
	XColor(165, 42, 42),
	XColor(0, 216, 255),
	XColor(0, 107, 128)
};
XColor	col_d25f68(255, 255, 0);
XColor	col_d223c8(213, 0, 217);
Unknown_448e60_448ed0	unk_d31580;
Unknown_4493c0_449420	unk_d29268;
XColor	cols_cf40ac[9];
XColor	cols_cf1060[10];
Unknown_454340_4543b0	unk_d2d2a0;
XColor	col_d02364;
XColor	col_d349ec;
Unknown_456200_456230	unk_d1f3b8;
Unknown_45eab0_45ebd0	unk_cf6428;
Unknown_45f320_45f560	unk_cf6888;
XColor	cols_d395fc[7];
Unknown_45fae0_45fbd0	unk_d25450;
Unknown_45fe00_45fe80	unk_d1dd38;
HProp	hprop_d2d504;
XColor	cols_d2c35c[7];
XColor	col_cf6f2c((XColor &)ptr_cf6b24);
XColor	cols_cf0d48[32];
RepeatedPtrFieldBase	rpfs_d316c4[3];
RepeatedPtrFieldBase	rpfs_d35dc8[3];
RepeatedPtrFieldBase	rpf_cf4154;
RepeatedPtrFieldBase	rpf_d39268;
RepeatedPtrFieldBase	rpf_d1ed58;
RepeatedPtrFieldBase	rpf_cf75a0;
RepeatedPtrFieldBase	rpf_d2600c;
RepeatedPtrFieldBase	rpf_d20b4c;
XColor	cols_d01c18[18];
HProp	hprop_d388f4;
XColor	cols_d20504[5];
RepeatedPtrFieldBase	rpf_d01a04;
RepeatedPtrFieldBase	rpf_d35b6c;
HProp	hprop_d35bb8;
XColor	cols_d2a584[11];
XColor	cols_d21e5c[17];
XColor	cols_d2c37c[17];
Unknown_4c1840	unk_cf672c;
Unknown_4dbd80	unk_cefcaa;
