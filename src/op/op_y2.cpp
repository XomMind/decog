// op_y2: assorted classes in 0x440000-0x490000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <iosfwd>
#include <math.h>
#include "../util/rng.h"
using namespace std;

extern RNG rng;

void opY2_readInt(istream &stream, int *value);	// NOTE: placeholder name (0x9d8480)
void opY2_readBool(istream &stream, bool *value);	// NOTE: placeholder name (0x9cf520)
void opY2_readString(istream &stream, string *value);	// NOTE: placeholder name
void opY2_readIntVector(istream &stream, vector<int> *value);	// NOTE: placeholder name (0x9cf5e0)
void opY2_readStringB(istream &stream, string *value);	// NOTE: placeholder name (0x4096f0)
void opY2_readDouble(istream &stream, double *value);	// NOTE: placeholder name (0x9cfa70)
void opY2_readIntVectorB(istream &stream, vector<int> *value);	// NOTE: placeholder name (0x4097e0)

struct OpY2_Range	// NOTE: placeholder name
{
	OpY2_Range() throw();	// 0x40bef0
	void load(istream &stream);	// NOTE: placeholder name (0x45f040)

	int low;
	int high;
};

struct MapRecord;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
};

//==================================================================
// weighted list
//==================================================================

struct OpY2_WeightedList	// NOTE: placeholder name
{
	int rollIndex();	// NOTE: placeholder name

	int total;	// NOTE: placeholder name
	vector<int> weights;	// NOTE: placeholder name
};

int OpY2_WeightedList::rollIndex()
{
	int roll = rng.rangeInt(1.0f,(float)total);
	int running = 1;
	for (unsigned int i = 0; i < weights.size(); i++)
	{
		running += weights[i];
		if (running > roll)
			return i;
	}
	return 0;
}

//==================================================================
// loadable records
//==================================================================

struct OpY2_Rec448270	// NOTE: placeholder name
{
	void load(istream &stream);	// NOTE: placeholder name

	int unknown0;
	int unknown4;
	int unknown8;
};

void OpY2_Rec448270::load(istream &stream)
{
	opY2_readInt(stream,&unknown0);
	opY2_readInt(stream,&unknown4);
	opY2_readInt(stream,&unknown8);
}

struct OpY2_Rec4482c0	// NOTE: placeholder name
{
	~OpY2_Rec4482c0();	// 0x448a40
	void load(istream &stream);	// NOTE: placeholder name

	int unknown0;
	int unknown4;
	int unknown8;
	vector<int> unknownc;
	vector<int> unknown1c;
	int unknown2c;
	int unknown30;
	int unknown34;
	OpY2_Range unknown38;
	int unknown40;
};

OpY2_Rec4482c0::~OpY2_Rec4482c0()
{
}

void OpY2_Rec4482c0::load(istream &stream)
{
	opY2_readInt(stream,&unknown0);
	opY2_readInt(stream,&unknown4);
	opY2_readInt(stream,&unknown8);
	opY2_readIntVector(stream,&unknownc);
	opY2_readIntVector(stream,&unknown1c);
	opY2_readInt(stream,&unknown2c);
	opY2_readInt(stream,&unknown30);
	opY2_readInt(stream,&unknown34);
	unknown38.load(stream);
	opY2_readInt(stream,&unknown40);
}

struct OpY2_Rec448390	// NOTE: placeholder name
{
	MapRecord *getA(unsigned int index);	// NOTE: placeholder name
	MapRecord *getB(unsigned int index);	// NOTE: placeholder name

	int unknown0;
	int unknown4;
	int unknown8;
	vector<MapRecord*> listA;	// NOTE: placeholder name
	vector<MapRecord*> listB;	// NOTE: placeholder name
};

MapRecord *OpY2_Rec448390::getA(unsigned int index)
{
	return index >= listA.size() ? listA.back() : listA[index];
}

MapRecord *OpY2_Rec448390::getB(unsigned int index)
{
	return index >= listB.size() ? listB.back() : listB[index];
}

struct OpY2_Rec448430	// NOTE: placeholder name
{
	void load(istream &stream);	// NOTE: placeholder name

	bool unknown0;
	int unknown4;
	int unknown8;
	int unknownc;
	int unknown10;
	string unknown14;
	string unknown30;
	bool unknown4c;
	string unknown50;
	int unknown6c;
	vector<int> unknown70;
	int unknown80;
	bool unknown84;
	OpY2_Range unknown88;
	OpY2_Range unknown90;
	OpY2_Range unknown98;
	OpY2_Range unknowna0;
	int unknowna8;
};

void OpY2_Rec448430::load(istream &stream)
{
	opY2_readBool(stream,&unknown0);
	opY2_readInt(stream,&unknown4);
	opY2_readInt(stream,&unknown8);
	opY2_readInt(stream,&unknownc);
	opY2_readInt(stream,&unknown10);
	opY2_readString(stream,&unknown14);
	opY2_readString(stream,&unknown30);
	opY2_readBool(stream,&unknown4c);
	opY2_readString(stream,&unknown50);
	opY2_readInt(stream,&unknown6c);
	opY2_readIntVector(stream,&unknown70);
	opY2_readInt(stream,&unknown80);
	opY2_readBool(stream,&unknown84);
	unknown88.load(stream);
	unknown90.load(stream);
	unknown98.load(stream);
	unknowna0.load(stream);
	opY2_readInt(stream,&unknowna8);
}

//==================================================================
// misc
//==================================================================

struct OpY2_Named	// NOTE: placeholder name
{
	void parseSuffix();	// NOTE: placeholder name

	char pad0[0x14];
	string name;	// NOTE: placeholder name
	string suffix;	// NOTE: placeholder name
};

void OpY2_Named::parseSuffix()
{
	unsigned int pos = name.rfind('_');
	if (pos != string::npos && name.size() - pos == 4)
		suffix.assign(name.begin() + pos + 1,name.end());
}

struct OpY2_Rec448630	// NOTE: placeholder name
{
	void load(istream &stream);	// NOTE: placeholder name

	bool unknown0;
	int unknown4;
	int unknown8;
	int unknownc;
	int unknown10;
	OpY2_Range unknown14;
	OpY2_Range unknown1c;
	OpY2_Range unknown24;
	vector<int> unknown2c;
	OpY2_Range unknown3c;
	OpY2_Range unknown44;
	OpY2_Range unknown4c;
	OpY2_Range unknown54;
	OpY2_Range unknown5c;
	OpY2_Range unknown64;
	OpY2_Range unknown6c;
	OpY2_Range unknown74;
	OpY2_Range unknown7c;
};

void OpY2_Rec448630::load(istream &stream)
{
	opY2_readBool(stream,&unknown0);
	opY2_readInt(stream,&unknown4);
	opY2_readInt(stream,&unknown8);
	opY2_readInt(stream,&unknownc);
	opY2_readInt(stream,&unknown10);
	unknown14.load(stream);
	unknown1c.load(stream);
	unknown24.load(stream);
	opY2_readIntVector(stream,&unknown2c);
	unknown3c.load(stream);
	unknown44.load(stream);
	unknown4c.load(stream);
	unknown54.load(stream);
	unknown5c.load(stream);
	unknown64.load(stream);
	unknown6c.load(stream);
	unknown74.load(stream);
	unknown7c.load(stream);
}

int opY2_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)

struct OpY2_Variance	// NOTE: placeholder name
{
	int vary(int value);	// NOTE: placeholder name

	char pad0[0x10];
	int amount;	// NOTE: placeholder name
};

int OpY2_Variance::vary(int value)
{
	return opY2_maxInt(0,value + rng.rangeInt((float)-amount,(float)amount));
}

struct OpY2_Rec449200	// NOTE: placeholder name
{
	void load(istream &stream);	// NOTE: placeholder name

	bool unknown0;
	int unknown4;
	int unknown8;
	int unknownc;
	OpY2_Range unknown10;
	OpY2_Range unknown18;
	int unknown20;
	OpY2_Range unknown24;
	OpY2_Range unknown2c;
};

void OpY2_Rec449200::load(istream &stream)
{
	opY2_readBool(stream,&unknown0);
	opY2_readInt(stream,&unknown4);
	opY2_readInt(stream,&unknown8);
	opY2_readInt(stream,&unknownc);
	unknown10.load(stream);
	unknown18.load(stream);
	opY2_readInt(stream,&unknown20);
	unknown24.load(stream);
	unknown2c.load(stream);
}

struct OpY2_Pos	// NOTE: placeholder name
{
	int x;
	int y;

	OpY2_Pos(const OpY2_Pos &a, const OpY2_Pos &b);	// 0x4099f0
	bool operator==(const OpY2_Pos &pos) const;	// 0x409b90
};
extern OpY2_Pos opY2_dirOffsets[4];	// NOTE: placeholder name (0xd03240)

int opY2_dirBetween(const OpY2_Pos &a, const OpY2_Pos &b)	// NOTE: placeholder name
{
	for (int i = 0; i < 4; i++)
	{
		if (OpY2_Pos(a,opY2_dirOffsets[i]) == b)
			return i;
	}
	return 0;
}

//==================================================================
// cave settings (object at *0xcefb54)
//==================================================================

struct OpY2_Rect	// NOTE: placeholder name
{
	int x;
	int y;
	int width;
	int height;
};

struct OpY2_BridgeSpec	// NOTE: placeholder name (0x34 bytes)
{
	char data[0x34];
};

struct OpY2_CaveSettings	// NOTE: placeholder name
{
	OpY2_CaveSettings(istream &stream);	// NOTE: placeholder name
	~OpY2_CaveSettings();	// 0x449570
	void load(istream &stream);	// NOTE: placeholder name

	char pad0[0xc];
	OpY2_Range unknownc;
	char pad14[0x1c];
	OpY2_Range unknown30;
	char pad38[0x10];
	vector<OpY2_Rect> regions;
	char pad58[0x18];
	vector<int> unknown70;
	vector<OpY2_BridgeSpec> bridges;
	OpY2_Range unknown90;
	char pad98[0xc];
};

OpY2_CaveSettings::OpY2_CaveSettings(istream &stream)
{
	load(stream);
}

OpY2_CaveSettings::~OpY2_CaveSettings()
{
}

//==================================================================
// network threads
//==================================================================

extern "C" void *SDL_CreateThread(int (*fn)(void*), void *data);
extern bool opY2_networkAvailable;	// NOTE: placeholder name (0xcefb3f)
extern vector<void*> opY2_networkThreads;	// NOTE: placeholder name (0xd16178)

void *opY2_startNetworkThread(void *id, bool force, int (*fn)(void*), void *data)	// NOTE: placeholder name
{
	if ((opY2_networkAvailable || !force) && opY2_networkThreads.size() < 10)
	{
		opY2_networkThreads.push_back(id);
		return SDL_CreateThread(fn,data);
	}
	else
		return 0;
}

struct OpY2_StringPair	// NOTE: placeholder name
{
	OpY2_StringPair(const string &a, const string &b, int c);

	string first;	// NOTE: placeholder name
	string second;	// NOTE: placeholder name
	int unknown38;	// NOTE: placeholder name
};

OpY2_StringPair::OpY2_StringPair(const string &a, const string &b, int c)
	: first		(a)
	, second	(b)
	, unknown38	(c)
{
}

//==================================================================
// color palettes
//==================================================================

extern XColor opY2_palette1[9];	// NOTE: placeholder name (0xcf40ac)
extern XColor opY2_palette2[11];	// NOTE: placeholder name (0xcf1060)
extern XColor *opY2_c_cfc180;	// NOTE: placeholder name
extern XColor *opY2_c_d30424;	// NOTE: placeholder name
extern XColor *opY2_c_d323c4;	// NOTE: placeholder name
extern XColor *opY2_c_d395f8;	// NOTE: placeholder name
extern XColor *opY2_c_cf281c;	// NOTE: placeholder name
extern XColor *opY2_c_d2ccec;	// NOTE: placeholder name
extern XColor *opY2_c_cfd448;	// NOTE: placeholder name
extern XColor *opY2_c_cf44c0;	// NOTE: placeholder name
extern XColor *opY2_c_cfc174;	// NOTE: placeholder name
extern XColor *opY2_c_d2981c;	// NOTE: placeholder name
extern XColor *opY2_c_cf27e8;	// NOTE: placeholder name
extern XColor *opY2_c_d2043c;	// NOTE: placeholder name
extern XColor *opY2_c_d22fcc;	// NOTE: placeholder name
extern XColor *opY2_c_d20438;	// NOTE: placeholder name
extern XColor *opY2_c_d204ac;	// NOTE: placeholder name

void opY2_initPalette1()
{
	opY2_palette1[0] = *opY2_c_cfc180;
	opY2_palette1[1] = *opY2_c_d30424;
	opY2_palette1[2] = *opY2_c_d323c4;
	opY2_palette1[3] = *opY2_c_d395f8;
	opY2_palette1[4] = *opY2_c_cf281c;
	opY2_palette1[5] = *opY2_c_cf281c;
	opY2_palette1[6] = *opY2_c_d2ccec;
	opY2_palette1[7] = *opY2_c_cfd448;
	opY2_palette1[8] = *opY2_c_cf44c0;
}

void opY2_initPalette2()
{
	opY2_palette2[0] = *opY2_c_cfc180;
	opY2_palette2[1] = *opY2_c_cfc174;
	opY2_palette2[2] = *opY2_c_d2981c;
	opY2_palette2[3] = *opY2_c_cf27e8;
	opY2_palette2[4] = *opY2_c_d2043c;
	opY2_palette2[5] = *opY2_c_d22fcc;
	opY2_palette2[6] = *opY2_c_d20438;
	opY2_palette2[7] = *opY2_c_cf27e8;
	opY2_palette2[9] = *opY2_c_d2981c;
	opY2_palette2[8] = *opY2_c_d204ac;
}

//==================================================================
// record loaded from stream (0x453e50)
//==================================================================

struct OpY2_Rec453e50	// NOTE: placeholder name
{
	OpY2_Rec453e50(istream &stream);	// NOTE: placeholder name

	bool unknown0;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
	vector<int> unknown8;	// NOTE: placeholder name
	string unknown18;	// NOTE: placeholder name
	int unknown34;	// NOTE: placeholder name
	int unknown38;	// NOTE: placeholder name
	int unknown3c;	// NOTE: placeholder name
	string unknown40;	// NOTE: placeholder name
	int unknown5c;	// NOTE: placeholder name
	double unknown60;	// NOTE: placeholder name
	int unknown68;	// NOTE: placeholder name
	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int unknown74;	// NOTE: placeholder name
	bool unknown78;	// NOTE: placeholder name
	vector<int> unknown7c;	// NOTE: placeholder name
};

OpY2_Rec453e50::OpY2_Rec453e50(istream &stream)
{
	unknown0 = false;
	opY2_readInt(stream,&unknown4);
	opY2_readStringB(stream,&unknown18);
	opY2_readInt(stream,&unknown34);
	opY2_readInt(stream,&unknown38);
	opY2_readInt(stream,&unknown3c);
	opY2_readString(stream,&unknown40);
	opY2_readInt(stream,&unknown5c);
	opY2_readDouble(stream,&unknown60);
	opY2_readInt(stream,&unknown68);
	opY2_readInt(stream,&unknown6c);
	opY2_readInt(stream,&unknown70);
	opY2_readInt(stream,&unknown74);
	opY2_readBool(stream,&unknown78);
	opY2_readIntVectorB(stream,&unknown7c);
}

//==================================================================
// logarithmic scaling curves
//==================================================================

float c026_logf(float x);	// NOTE: placeholder name (0x4012f0)

struct OpY2_CurveRange	// NOTE: placeholder name
{
	int curveA(int value);	// NOTE: placeholder name
	int curveB(int value);	// NOTE: placeholder name
	int curveC(int value);	// NOTE: placeholder name

	char pad0[0x6c];
	int low;	// NOTE: placeholder name
	int high;	// NOTE: placeholder name
};

int OpY2_CurveRange::curveA(int value)
{
	return (int)(100.0 - log(1.0 + (float)((value - low) * 9.0f / (high - low))) * 100.0);
}

int OpY2_CurveRange::curveB(int value)
{
	return (int)((c026_logf(-((float)((value - low) * 10.0f / (high - low)) - 10.0)) + 4.0) * 100.0 / 6.3026);
}

int OpY2_CurveRange::curveC(int value)
{
	return (int)((float)(1.0 / log((double)(float)((value - low) * 8.5f / (high - low)) + 1.5) - 1.0) / 4.6789 * 100.0);
}
