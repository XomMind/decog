// team_d_29: reset of the 0x1d4-byte state object at 0xd25450 (0x69bb00).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Range8	// NOTE: placeholder name
{
	int a;
	int b;

	int randomInRange();	// NOTE: folded with Point::randomInRange_40c130
};

class HEntity	// NOTE: placeholder layout
{
	int ID;
public:
	void reset();	// 0x9b7270
};

class HExplosive	// NOTE: placeholder layout
{
	int ID;
};

class RNG
{
public:
	int rangeInt(float low, float high);
};
extern RNG rng;

struct Pair45fac0	// NOTE: placeholder name (0x45fac0 zeroes both values)
{
	int a;
	int b;

	void reset();	// NOTE: placeholder name
};

extern Range8 range_cf2814;	// NOTE: placeholder name
extern int int_caf154;	// NOTE: placeholder name
extern vector<vector<string> > data_d204ec;	// NOTE: placeholder name

class OpD_State29	// NOTE: placeholder name (the class of the global at 0xd25450, Unknown_45fae0_45fbd0 elsewhere)
{
public:
	void reset69bb00();	// NOTE: placeholder name

	bool					unknown000;
	int						unknown004;
	int						unknown008;
	int						unknown00c;
	int						unknown010;
	int						unknown014;
	int						unknown018;
	int						unknown01c;
	vector<int>				unknown020;
	vector<int>				unknown030;
	vector<int>				unknown040;
	vector<int>				unknown050;
	vector<int>				unknown060;
	int						unknown070;
	int						unknown074;
	int						unknown078;
	int						unknown07c;
	int						unknown080;
	int						unknown084;
	int						unknown088;
	int						unknown08c;
	int						unknown090;
	int						unknown094;
	int						unknown098;
	int						unknown09c;
	int						unknown0a0;
	bool					unknown0a4;
	Pair45fac0				unknown0a8;
	int						unknown0b0;
	vector<int>				unknown0b4;
	int						unknown0c4;
	int						unknown0c8;
	bool					unknown0cc;
	int						unknown0d0;
	int						unknown0d4;
	int						unknown0d8;
	int						unknown0dc;
	int						unknown0e0;
	int						unknown0e4;
	int						unknown0e8;
	int						unknown0ec;
	int						unknown0f0;
	int						unknown0f4;
	int						unknown0f8;
	int						unknown0fc;
	int						unknown100;
	int						unknown104;
	int						unknown108;
	int						unknown10c;
	int						unknown110;
	int						unknown114;
	int						unknown118;
	int						unknown11c;
	vector<int>				unknown120;
	vector<int>				unknown130;
	int						unknown140;
	HEntity					unknown144;
	vector<vector<int> >	unknown148;
	bool					unknown158;
	bool					unknown159;
	int						unknown15c;
	bool					unknown160;
	bool					unknown161;
	bool					unknown162;
	bool					unknown163;
	int						unknown164;
	int						unknown168;
	int						unknown16c;
	int						unknown170[3];
	int						unknown17c;
	bool					unknown180;
	vector<int>				unknown184;
	int						unknown194;
	vector<HExplosive>		unknown198;
	int						unknown1a8;
	int						unknown1ac;
	int						unknown1b0;
	int						unknown1b4;
	int						unknown1b8;
	int						unknown1bc;
	bool					unknown1c0;
	bool					unknown1c1;
	bool					unknown1c2;
	int						unknown1c4;
	int						unknown1c8;
	int						unknown1cc;
	bool					unknown1d0;
};

void OpD_State29::reset69bb00()
{
	unknown000 = false;
	unknown004 = 0;
	unknown008 = 0;
	unknown010 = 100;
	unknown014 = range_cf2814.randomInRange();
	unknown020.assign(0x82u,0);
	unknown030.clear();
	unknown040.clear();
	unknown050.clear();
	unknown060.clear();
	unknown070 = 0;
	unknown074 = 0;
	unknown078 = 0;
	unknown07c = 0;
	unknown080 = 112;
	unknown084 = 0;
	unknown088 = 0;
	unknown08c = 0;
	unknown090 = 0;
	unknown094 = 0;
	unknown098 = 0;
	unknown09c = 0;
	unknown0a0 = int_caf154;
	unknown0a4 = false;
	unknown0a8.reset();
	unknown0b0 = 0;
	unknown0b4.assign(0x6eu,0);
	unknown0c4 = 0;
	unknown0c8 = 0;
	unknown0cc = false;
	unknown0d0 = 0;
	unknown0d4 = 0;
	unknown0d8 = 0;
	unknown0dc = 0;
	unknown0e0 = 0;
	unknown0e4 = 0;
	unknown0e8 = 10;
	unknown0ec = 0;
	unknown0f0 = 0;
	unknown0f4 = 0;
	unknown0f8 = 0;
	unknown0fc = 0;
	unknown100 = 0;
	unknown104 = 0;
	unknown108 = 0;
	unknown10c = 0;
	unknown110 = 0;
	unknown114 = 0;
	unknown118 = 0;
	unknown11c = 0;
	unknown120.clear();
	unknown130.clear();
	unknown140 = 0;
	unknown144.reset();
	unknown148.clear();
	for (unsigned int i = 0; i < data_d204ec.size(); i++)
		unknown148.push_back(vector<int>(data_d204ec[i].size(),0));
	unknown158 = false;
	unknown159 = false;
	unknown15c = 0;
	unknown160 = false;
	unknown161 = false;
	unknown162 = false;
	unknown163 = false;
	unknown164 = -1;
	unknown168 = 0;
	unknown16c = 1;
	unknown17c = 0;
	unknown180 = false;
	unknown184.clear();
	unknown184.assign(4u,0);
	unknown194 = 0;
	unknown198.clear();
	unknown1a8 = -1;
	unknown1ac = 0;
	unknown1b0 = 0x61;
	unknown1b8 = 0;
	unknown1bc = 0;
	unknown1c0 = false;
	unknown1c1 = false;
	unknown1c2 = false;
	unknown1c4 = rng.rangeInt(100.0f,200.0f);
	unknown1c8 = 0;
	unknown1cc = 0x6e;
	unknown1d0 = false;
}
