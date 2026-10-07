// team_a_17: DF generator settings constructors (OpW7_GenSettings in op_w7_df.cpp, renamed here to avoid clashing with
// its layout) and the OpY2_Rec4482c0 room record constructor that the eh vector constructor iterator calls.
// NOTE: layouts are partial; callees declared throw() are nothrow in the exe.
#include <vector>
#include <string>
#include <istream>
using namespace std;

namespace DF
{
class Tunneler
{
public:
	Tunneler();
	virtual ~Tunneler();
	char pad04[0x48 - 4];
};
}

struct Range_448160	// NOTE: placeholder name (constructor 0x448160)
{
	char pad[0x14];
	Range_448160();
	~Range_448160();
};


struct Settings_448aa0	// NOTE: placeholder name (constructor 0x448aa0)
{
	char pad[0x84];
	Settings_448aa0() throw();
	~Settings_448aa0();
};

struct Pair_40bef0	// NOTE: placeholder name (constructor 0x40bef0)
{
	int a;
	int b;
	Pair_40bef0() throw();
};

struct OpY2_Rec4482c0	// NOTE: placeholder name (layout as in op_y2.cpp; constructor 0x448a10, destructor 0x448a40)
{
	OpY2_Rec4482c0();
	~OpY2_Rec4482c0();

	int unknown0;
	int unknown4;
	int unknown8;
	vector<int> unknownc;
	vector<int> unknown1c;
	int unknown2c;
	int unknown30;
	int unknown34;
	Pair_40bef0 unknown38;
	int unknown40;
};

OpY2_Rec4482c0::OpY2_Rec4482c0()
{
}

struct TeamA_E0c_448760 { char pad[0x0c]; };	// NOTE: placeholder element types (sizes from the exe's vector destructors)
struct TeamA_Eac_448760 { char pad[0xac]; };
struct TeamA_E84_448760 { char pad[0x84]; };

struct GenSettings_448760	// NOTE: placeholder name (OpW7_GenSettings in op_w7_df.cpp)
{
	int unknown00;
	int unknown04;
	int unknown08;
	int unknown0c;
	int unknown10;
	Range_448160 unknown14;
	Range_448160 unknown28;
	Range_448160 unknown3c;
	int unknown50;
	int unknown54;
	DF::Tunneler tunneler;
	vector<TeamA_E0c_448760> unknownA0;
	int unknownB0;
	vector<unsigned int> unknownB4;
	OpY2_Rec4482c0 rooms[3];
	int unknown190;
	float unknown194;
	int unknown198;
	int unknown19c;
	int unknown1a0;
	int unknown1a4;
	int unknown1a8;
	vector<TeamA_Eac_448760> unknown1ac;
	vector<TeamA_E84_448760> unknown1bc;
	Settings_448aa0 unknown1cc;
	vector<std::string> unknown250;
	Pair_40bef0 unknown260;
	char pad268[0x280 - 0x268];
	GenSettings_448760();
	GenSettings_448760(istream &in);
	~GenSettings_448760();
	void load(istream &in);
};

GenSettings_448760::GenSettings_448760()
{
}

GenSettings_448760::GenSettings_448760(istream &in)
{
	load(in);
}

GenSettings_448760::~GenSettings_448760()
{
}
