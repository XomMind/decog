// Lead cluster c026: small helpers around 0x453390-0x454e20.
// NOTE: all class names, member names and layouts are placeholders.
#include <string>
#include <vector>
#include <math.h>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor() throw();
	XColor(const XColor &color) throw();
	XColor &operator=(XColor color) throw();
};

class HExplosive	// NOTE: placeholder layout
{
	int ID;
public:
	HExplosive();
};

class SaveStream;	// NOTE: placeholder name
struct Pos;
struct Particle
{
	Pos *getPos();
	void kill();	// NOTE: placeholder name
};

struct Pos	// NOTE: placeholder name
{
	int x;
	int y;
	bool test(const Pos &p);	// NOTE: placeholder name
};

struct MapRecord
{
	int ID;
};

class Console;

void readLogWidth(SaveStream *stream, int *field);					// NOTE: placeholder name (0x9d8480)
void readLogField10(SaveStream *stream, void *field);				// NOTE: placeholder name (0x4096f0)
void readLogField30(SaveStream *stream, void *field);				// NOTE: placeholder name (0x9cf520)
void c026_read9cfa70(SaveStream *stream, void *field);				// NOTE: placeholder name (0x9cfa70)
void c026_read4097e0(SaveStream *stream, void *field);				// NOTE: placeholder name (0x4097e0)
namespace PhysFScpp
{
	void getCdRomDirs(void (*)(void *, const char *), void *);
}
float c026_logf(float x);											// NOTE: placeholder name (0x4012f0)

extern XColor c026_colA0, c026_colA1, c026_colA2, c026_colA3, c026_colA4, c026_colA5, c026_colA6, c026_colA7;	// NOTE: placeholder names
extern XColor c026_srcA[8];	// NOTE: placeholder name

class C026_Rec453390	// NOTE: placeholder name
{
public:
	virtual ~C026_Rec453390();
	void cleanup();	// NOTE: placeholder name (0x4f9c30)

	string s10;		// NOTE: placeholder name
	string s2c;		// NOTE: placeholder name
	string s48;		// NOTE: placeholder name
	string s6c;		// NOTE: placeholder name
};

C026_Rec453390::~C026_Rec453390()
{
	cleanup();
}

class C026_Rec453470	// NOTE: placeholder name
{
public:
	C026_Rec453470(const string &s);

	string name;				// NOTE: placeholder name
	int unknown1c;				// NOTE: placeholder name
	char pad20[4];
	vector<HExplosive> list;	// NOTE: placeholder name
	bool flag;					// NOTE: placeholder name
};

C026_Rec453470::C026_Rec453470(const string &s)
	: name(s)
	, unknown1c(0)
{
	flag = true;
}

class C026_Rec453ae0	// NOTE: placeholder name
{
public:
	~C026_Rec453ae0();

	string name;				// NOTE: placeholder name
	char pad1c[8];
	vector<string> list;		// NOTE: placeholder name
};

C026_Rec453ae0::~C026_Rec453ae0()
{
}

class C026_Meter	// NOTE: placeholder name
{
public:
	float getRatio(bool zeroIfEmpty);	// NOTE: placeholder name (0x453b70)

	int cur;	// NOTE: placeholder name
	int max;	// NOTE: placeholder name
};

float C026_Meter::getRatio(bool zeroIfEmpty)
{
	if (max == 0)
	{
		if (zeroIfEmpty)
			return 0.0f;
		else
			return 0.0f;
	}
	if (cur > max)
		return 1.0f;
	return (float)cur / max;
}

void c026_initColors453c60()	// NOTE: placeholder name
{
}

class C026_Range	// NOTE: placeholder name
{
public:
	int percentInverse(int v);	// NOTE: placeholder name (0x453fe0)
	int curveLog10(int v);		// NOTE: placeholder name (0x454020)
	int curveLog(int v);		// NOTE: placeholder name (0x454080)
	int curveInv(int v);		// NOTE: placeholder name (0x4540f0)

	char pad00[0x6c];
	int lo;	// NOTE: placeholder name
	int hi;	// NOTE: placeholder name
};

int C026_Range::percentInverse(int v)
{
	return 100 - (v - lo) * 100 / (hi - lo);
}

int C026_Range::curveLog10(int v)
{
	float x = (v - lo) * 9.0 / (hi - lo);
	return (int)(100.0 - log10(x + 1) * 100.0);
}

int C026_Range::curveLog(int v)
{
	float x = (v - lo) * 10.0 / (hi - lo);
	float y = -(x - 10.0);
	return (int)((c026_logf(y) + 4.0) * 100.0 / 6.3026);
}

int C026_Range::curveInv(int v)
{
	float x = (v - lo) * 8.5 / (hi - lo);
	float y = 1 / log10(x + 1.5) - 1.0;
	return (int)(y / 4.6789 * 100.0);
}
