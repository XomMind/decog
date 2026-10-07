// team_a_19: constructor of the namespace-scope singleton at 0x45f320 (class shared with team_d_04.cpp) and REX::initJLog.
// NOTE: layout reconstructed from the constructor; names are placeholders.
#include <string>
#include <vector>
using namespace std;

class HProp
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
};

struct Init_45f020	// NOTE: placeholder name (8-byte value type, constructor 0x45f020)
{
	int a;
	int b;
	Init_45f020() throw();
};

class Push_453b40	// NOTE: placeholder name (8-byte value type, constructor 0x453b40)
{
public:
	int a;
	int b;
	Push_453b40() throw();
};

class Unknown_45f320_45f560	// NOTE: placeholder name (shared with team_d_04.cpp, which defines the destructor); layout from the constructor
{
public:
	Unknown_45f320_45f560();
	~Unknown_45f320_45f560();

	vector<unsigned int> unknown000;
	vector<unsigned int> unknown010;
	char pad020[0x24 - 0x20];
	Init_45f020 unknown024;
	char pad02c[0x30 - 0x2c];
	HProp unknown030;
	char pad034[0x38 - 0x34];
	Init_45f020 unknown038;
	char pad040[0x44 - 0x40];
	vector<unsigned int> unknown044;
	vector<unsigned int> unknown054;
	char pad064[0x70 - 0x64];
	vector<unsigned int> unknown070;
	Init_45f020 unknown080;
	vector<unsigned int> unknown088;
	vector<unsigned int> unknown098;
	vector<unsigned int> unknown0a8;
	vector<unsigned int> unknown0b8;
	char pad0c8[0xd4 - 0xc8];
	Init_45f020 unknown0d4;
	vector<unsigned int> unknown0dc;
	Init_45f020 unknown0ec;
	Init_45f020 unknown0f4;
	HProp unknown0fc;
	string unknown100;
	char pad11c[0x120 - 0x11c];
	HProp unknown120;
	vector<unsigned int> unknown124;
	Init_45f020 unknown134;
	Push_453b40 unknown13c;
	Push_453b40 unknown144;
	char pad14c[0x154 - 0x14c];
	vector<unsigned int> unknown154;
	vector<unsigned int> unknown164;
	vector<unsigned int> unknown174;
	char pad184[0x188 - 0x184];
	Push_453b40 unknown188;
	char pad190[0x1a0 - 0x190];
	HProp unknown1a0;
	char pad1a4[0x1b4 - 0x1a4];
	Init_45f020 unknown1b4;
	Init_45f020 unknown1bc;
	char pad1c4[0x1d8 - 0x1c4];
	vector<unsigned int> unknown1d8;
	vector<unsigned int> unknown1e8;
	vector<unsigned int> unknown1f8;
	vector<unsigned int> unknown208;
	char pad218[0x21c - 0x218];
	vector<unsigned int> unknown21c;
	char pad22c[0x234 - 0x22c];
	vector<unsigned int> unknown234;
	vector<unsigned int> unknown244;
	vector<unsigned int> unknown254;
	vector<unsigned int> unknown264;
	vector<unsigned int> unknown274;
};

Unknown_45f320_45f560::Unknown_45f320_45f560()
{
}


void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
extern string gameString_d1e024;	// version string (0xd1e024)

class JLog
{
public:
	void setHeader(string header_);	// NOTE: placeholder name (0x404b10)
	void init();	// NOTE: placeholder name (0x410710)
	void setFilename_4041d0(string name);	// NOTE: placeholder name (folded setter)
	void setMinLevel_4ed0d0(int level);	// NOTE: placeholder name (folded setter)
	void setCallback_44ed80(void (*callback)(int level));	// NOTE: placeholder name (folded setter)
	void setUnknown58_404b70(bool value);	// NOTE: placeholder name (0x404b70)
};
extern JLog *jlog;	// NOTE: placeholder name (0xcefa64)

// Allocates the log through a stand-in with a trivially defined constructor: the exe proves JLog's constructor
// (0x4225c0) nothrow, which LTCG can only do here if the constructor is defined in the link.
struct JLogNew_4225c0	// NOTE: placeholder name (0x60 bytes)
{
	char pad[0x60];
	JLogNew_4225c0();
};

JLogNew_4225c0::JLogNew_4225c0()
{
}

void defaultLogCallback_421f10(int level);	// NOTE: placeholder name (0x421f10)

class REX
{
public:
	void initJLog(int minLevel, string *header, void (*callback)(int level), bool flag);
};

void REX::initJLog(int minLevel, string *header, void (*callback)(int level), bool flag)
{
	if (jlog)
		logFatal("REX::initJLog()","Log already initialized");
	jlog = (JLog *)new JLogNew_4225c0();
	jlog->setHeader(header ? *header : "REX v" + gameString_d1e024);
	jlog->init();
	jlog->setFilename_4041d0("run.log");
	jlog->setMinLevel_4ed0d0(minLevel);
	jlog->setCallback_44ed80(callback == NULL ? defaultLogCallback_421f10 : callback);
	jlog->setUnknown58_404b70(flag);
}
