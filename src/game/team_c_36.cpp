// team_c_36: Config::init (0x43afa0): sets defaults, then reads user/system.cfg, options.cfg and advanced.cfg
// NOTE: member names are placeholders (f<offset>); the option names come from configOptionNames (0xd35e18)
#include <string>
#include <vector>
#include <fstream>
using namespace std;

extern string configOptionNames[];	// global_string_arrays.cpp
extern string gameStrings_cf3418[];	// global_string_arrays.cpp
extern string gameStrings_cf3668[];	// global_string_arrays.cpp
extern string gameStrings_d15db0[];	// global_string_arrays.cpp
extern string gameStrings_d1e1e0[];	// global_string_arrays.cpp
extern string gameStrings_d1e448[];	// global_string_arrays.cpp
extern string gameStrings_d1ed68[];	// global_string_arrays.cpp
extern string gameStrings_d21dd0[];	// global_string_arrays.cpp
extern string gameStrings_d230f8[];	// global_string_arrays.cpp
extern string gameStrings_d25ee0[];	// global_string_arrays.cpp
extern string gameStrings_d28c1c[];	// global_string_arrays.cpp
extern string gameStrings_d38478[];	// global_string_arrays.cpp
extern string gameStrings_d384f0[];	// global_string_arrays.cpp
extern string gameString_cfd42c;	// global_strings.cpp
extern int mode_cebd5c;	// NOTE: placeholder name
void logError(string location, string message);
int OpX5_minInt(int a, int b);	// NOTE: placeholder name (op_x5.cpp)

class C29_Stats	// NOTE: placeholder (object at 0xd223f0; the methods are folded with Protobuf/REX accessors)
{
public:
	int getA();	// NOTE: placeholder names
	int getB();
	int getC();
	int getD();
	bool isValid();
	bool getFlag();
};
extern C29_Stats stats_d223f0;	// NOTE: placeholder name

void logWarning(string location, string message);
void logMessage(string message);
string intToString(int value);
int stringToInt(const string &s);
void OpX5_fillInts(int *list, unsigned int count, int value);
void OpC_clampMin(int *v, int m);
void OpC_clampMax(int *value, int max);
string &padRight_4080d0(string &text, int width, char fill);
int ops7_clamp_9cdc80(int low, int value, int high);
int OpT8a_findStringIndex(const string *list, unsigned int count, string s);
void parseLine_408d70(string &text, vector<string> &out);
bool isAllowedChar_415fc0(char c);
void c36_split_408700(const string &text, char delim, vector<string> &out);	// NOTE: placeholder name

class Config	// NOTE: placeholder layout (object at 0xd28c68)
{
public:
	int f0;
	string f4;
	bool f20;
	bool f21;
	bool f22;
	bool f23;
	int f24;
	bool f28[4];
	int f2c[4];
	int f3c;
	int f40;
	int f44;
	bool f48;
	int f4c;
	int f50;
	bool f54;
	bool f55;
	bool f56;
	int f58;
	int f5c;
	int f60;
	string f64;
	string f80;
	bool f9c;
	bool f9d;
	bool f9e;
	bool f9f;
	bool fa0;
	bool fa1;
	int fa4;
	int fa8;
	bool fac;
	bool fad;
	bool fae;
	int fb0;
	bool fb4;
	bool fb5;
	int fb8;
	bool fbc;
	bool fbd;
	bool fbe;
	bool fbf;
	bool fc0;
	int fc4;
	bool fc8;
	bool fc9;
	bool fca;
	int fcc;
	bool fd0;
	bool fd1;
	bool fd2;
	bool fd3;
	bool fd4;
	int fd8;
	int fdc;
	int fe0;
	bool fe4;
	bool fe5;
	int fe8;
	int fec;
	int ff0;
	int ff4;
	bool ff8;
	int ffc;
	int f100;
	bool f104;
	vector<bool> f108;
	int f11c;
	int f120;
	bool f124;
	bool f125;
	char pad128[0x20];
	int f148[12];
	bool f178;
	bool f179;
	bool f17a;
	bool f17b;
	int f17c;
	int f180;
	bool f184;
	bool f185;
	bool f186;
	bool f187;
	int f188;
	int f18c;
	bool f190;
	bool f191;
	bool f192;
	bool f193;
	bool f194;
	bool f195;
	int f198;
	bool f19c;
	bool f19d;
	bool f19e;
	bool f19f;
	bool f1a0;
	int f1a4;
	int f1a8;
	int f1ac;
	bool f1b0;
	int f1b4;
	int f1b8;
	bool f1bc;
	bool f1bd;
	bool f1be;
	bool f1bf;
	int f1c0;
	int f1c4;
	int f1c8;
	int f1cc;
	int f1d0;
	bool f1d4;
	bool f1d5;
	bool f1d6;
	int f1d8;
	bool f1dc;
	bool f1dd;
	bool f1de;
	bool f1df;
	bool f1e0;
	bool f1e1;
	bool f1e2;
	bool f1e3;
	bool f1e4;
	bool f1e5;
	bool f1e6;
	bool f1e7;
	int f1e8;
	bool f1ec;
	bool f1ed;
	bool f1ee;
	bool f1ef;
	bool f1f0;
	bool f1f1;
	bool f1f2;
	bool f1f3;
	bool f1f4;
	bool f1f5;
	bool f1f6;
	int f1f8;
	int f1fc;
	bool f200;
	bool f201;
	bool f202;
	int f204;
	int f208;
	bool f20c;
	bool f20d;
	bool f20e;
	bool f20f;
	bool f210;
	bool f211;
	bool f212;
	bool f213;
	bool f214;
	bool f215;
	bool f216;
	bool f217;
	bool f218;
	bool f219;
	bool f21a;
	bool f21b;
	bool f21c;
	bool f21d;
	bool f21e;
	int f220;
	bool f224;
	int f228;
	int f22c;
	int f230;
	int f234;
	int f238;
	bool f23c;
	int f240;
	int f244;
	bool f248;
	bool f249;
	char pad24a[0xae];
	bool f2f8;
	bool f2f9;
	bool f2fa;
	bool f2fb;
	bool f2fc;
	bool f2fd;
	bool f2fe;
	bool f2ff;
	int f300;
	int f304;
	int f308;
	bool f30c;
	int f310;
	int f314;
	int f318;
	int f31c;
	int f320;
	int f324;
	int f328;
	int f32c;
	bool f330;
	int f334;
	bool f338;
	bool f339;
	bool f33a;
	bool f33b;
	bool f33c;
	bool f33d;
	bool f33e;
	bool f33f;
	bool f340;
	bool f341;
	bool f342;
	bool f343;
	bool f344;
	bool f345;
	bool f346;
	bool f347;
	bool f348;
	bool f349;
	bool f34a;
	int f34c;
	int f350;
	bool f354;
	bool f355;
	int f358;
	bool f35c;

	int boolToInt(bool value);	// 0x445590
	string colorFiltersToString(int which);	// 0x445e70
	void save(int which, bool skipStats);
	bool breakConfigVar(const string &line, string &name, string &value, int lineNum, const string &file);
	void init_43afa0();
	void init_4456b0(int id, string value);
};


// globals (placeholders)
extern int c36_ba6abc[];
extern string c36_cfd42c;
extern unsigned int c36_d035d0;
extern unsigned int c36_d035d4;
extern string c36_d2a504;
extern string c36_d2f184;
void Config::init_43afa0()
{
	f0 = 1;
	f4 = c36_d2a504;
	f20 = 1;
	f21 = 0;
	f22 = 0;
	f23 = 0;
	f24 = 7;
	f28[0] = 1;
	f28[1] = 1;
	f28[2] = 1;
	f28[3] = 1;
	f2c[0] = 10;
	f2c[1] = 10;
	f2c[2] = 10;
	f2c[3] = 10;
	f3c = 0;
	f40 = 0;
	f44 = 60;
	f48 = 0;
	f4c = 500;
	f50 = 30;
	f54 = 0;
	f55 = 1;
	f56 = 0;
	f58 = 0;
	f5c = 0;
	f60 = -1;
	f64 = c36_d2f184;
	f80 = "0";
	f9c = 0;
	f9d = 1;
	f9e = 0;
	f9f = 1;
	fa0 = 1;
	fa1 = 1;
	fa4 = 3;
	fa8 = 0;
	fac = 0;
	fad = 0;
	fae = 0;
	fb0 = 0;
	fb4 = 1;
	fb5 = 0;
	fb8 = 0;
	fbc = 0;
	fbd = 0;
	fbe = 0;
	fbf = 1;
	fc0 = 1;
	fc4 = 750;
	fc8 = 1;
	fc9 = 1;
	fca = 1;
	fcc = 1500;
	fd0 = 1;
	fd1 = 1;
	fd2 = 1;
	fd3 = 1;
	fd4 = 1;
	fd8 = 2000;
	fdc = 0;
	fe0 = 2;
	fe4 = 1;
	fe5 = 1;
	fe8 = 300;
	fec = 20;
	ff0 = 20;
	ff4 = 10;
	ff8 = 1;
	ffc = 3;
	f100 = 2;
	f104 = 0;
	f108.assign(6, true);
	f11c = 0;
	f120 = 0;
	f124 = 0;
	f125 = 0;
	OpX5_fillInts(f148, 12, 0);
	f178 = 0;
	f179 = 0;
	f17a = 0;
	f17b = 0;
	f17c = 3;
	f180 = 10;
	f184 = 0;
	f185 = 0;
	f186 = 0;
	f187 = 1;
	f188 = 26;
	f18c = 0;
	f190 = 1;
	f191 = 1;
	f192 = 0;
	f193 = 0;
	f194 = 0;
	f195 = 0;
	f198 = 0;
	f19c = 0;
	f19d = 0;
	f19e = 0;
	f19f = 0;
	f1a0 = 0;
	f1a4 = 300;
	f1a8 = 600;
	f1ac = 2000;
	f1b0 = 0;
	f1b4 = 0;
	f1b8 = 100;
	f1bc = 1;
	f1bd = 0;
	f1be = 0;
	f1bf = 1;
	f1c0 = 350;
	f1c4 = 2000;
	f1c8 = 3;
	f1cc = 0;
	f1d0 = 8;
	f1d4 = 0;
	f1d5 = 0;
	f1d6 = 1;
	f1d8 = 750;
	f1dc = 0;
	f1dd = 0;
	f1de = 0;
	f1df = 1;
	f1e0 = 0;
	f1e1 = 1;
	f1e2 = 0;
	f1e3 = 0;
	f1e4 = 0;
	f1e5 = 0;
	f1e6 = 0;
	f1e7 = 1;
	f1e8 = 0;
	f1ec = 0;
	f1ed = 0;
	f1ee = 0;
	f1ef = 1;
	f1f0 = 1;
	f1f1 = 0;
	f1f2 = 0;
	f1f3 = 0;
	f1f4 = 0;
	f1f5 = 0;
	f1f6 = 0;
	f1f8 = 250;
	f1fc = 5000;
	f200 = 0;
	f201 = 1;
	f202 = 1;
	f204 = 4;
	f208 = 15;
	f20c = 0;
	f20d = 1;
	f20e = 0;
	f20f = 0;
	f210 = 0;
	f211 = 0;
	f212 = 0;
	f213 = 0;
	f214 = 0;
	f215 = 0;
	f216 = 0;
	f217 = 1;
	f218 = 1;
	f219 = 0;
	f21a = 0;
	f21b = 0;
	f21c = 0;
	f21d = 0;
	f21e = 0;
	f220 = 3000;
	f224 = 0;
	f228 = 10000;
	f22c = 8000;
	f230 = 500;
	f234 = 2000;
	f238 = 2000;
	f23c = 0;
	f240 = 30000;
	f244 = 1000;
	f248 = 0;
	f249 = 0;
	f2f8 = 0;
	f2f9 = 0;
	f2fa = 0;
	f2fb = 0;
	f2fc = 0;
	f2fd = 0;
	f2fe = 0;
	f2ff = 1;
	f300 = 5000;
	f304 = 20;
	f308 = 5000;
	f30c = 0;
	f310 = 6;
	f314 = 5000;
	f318 = 6;
	f31c = 5000;
	f320 = 10000;
	f324 = 1000;
	f328 = 750;
	f32c = 5;
	f330 = 0;
	f334 = 0;
	f338 = 1;
	f339 = 0;
	f33a = 0;
	f33b = 0;
	f33c = 0;
	f33d = 0;
	f33e = 0;
	f33f = 0;
	f340 = 0;
	f341 = 0;
	f342 = 0;
	f343 = 0;
	f344 = 0;
	f345 = 0;
	f346 = 1;
	f347 = 0;
	f348 = 0;
	f349 = 0;
	f34a = 1;
	f34c = 48;
	f350 = 3000;
	f354 = 0;
	f355 = 0;
	f358 = 114;
	f35c = 0;
	ifstream allies;
	string bottom;
	vector<string> center;
	string adj;
	string col;
	int a1;
	int branch;
	allies.open((c36_cfd42c + "user/" + "system.cfg").c_str());
	if (!allies.is_open())
	{
		logWarning("Config::init()", "Unable to open " + (c36_cfd42c + "user/" + "system.cfg") + ", creating new default config");
		save(0, 1);
	}
	else
	{
		logMessage("Reading config: " + (c36_cfd42c + "user/" + "system.cfg"));
		a1 = 0;
		while (getline(allies, bottom))
	{
		a1 = a1 + 1;
		center.clear();
		parseLine_408d70(bottom, center);
		if (!center.empty() && breakConfigVar(center.front(), adj, col, a1, c36_cfd42c + "user/" + "system.cfg"))
	{
		branch = OpT8a_findStringIndex(configOptionNames, 243, adj);
		switch (branch)
	{
	case 0:
		f0 = ops7_clamp_9cdc80(0, stringToInt(col), 2);
		break;
	case 1:
		f4 = col;
		break;
	case 2:
		f20 = stringToInt(col);
		break;
	case 3:
		f21 = stringToInt(col);
		break;
	case 4:
		f22 = stringToInt(col);
		break;
	case 5:
		f23 = stringToInt(col);
		break;
	case 6:
		f24 = ops7_clamp_9cdc80(1, stringToInt(col), 10);
		break;
	case 7:
	case 8:
	case 9:
	case 10:
		f28[branch - 7] = stringToInt(col);
		break;
	case 11:
	case 12:
	case 13:
	case 14:
		f2c[branch - 11] = ops7_clamp_9cdc80(1, stringToInt(col), 10);
		break;
	case 15:
		f3c = stringToInt(col);
		if (f3c != 0 && f3c < 50)
	{
		f3c = 0;
		logError("Config::init()", "mapWidth below minimum (" + intToString(50) + "), reset to automatic");
		f4 = c36_d2a504;
	}
		break;
	case 16:
		f40 = stringToInt(col);
		if (f40 != 0 && f40 < c36_ba6abc[f0])
	{
		f40 = 0;
		logError("Config::init()", "mapHeight below minimum (" + intToString(c36_ba6abc[f0]) + "), reset to automatic");
		f4 = c36_d2a504;
	}
		break;
	case 17:
		f44 = stringToInt(col);
		break;
	case 18:
		f48 = stringToInt(col);
		break;
	case 19:
		f4c = stringToInt(col);
		break;
	case 20:
		f50 = stringToInt(col);
		break;
	case 21:
		f54 = stringToInt(col);
		break;
	case 22:
		f55 = stringToInt(col);
		break;
	case 23:
		f56 = stringToInt(col);
		break;
	case 24:
		f58 = stringToInt(col);
		break;
	case 25:
		f5c = stringToInt(col);
		break;
	case 26:
		f60 = stringToInt(col);
	}
	}
	}
		allies.close();
	}
	allies.open((c36_cfd42c + "user/" + "options.cfg").c_str());
	if (!allies.is_open())
	{
		logWarning("Config::init()", "Unable to open " + (c36_cfd42c + "user/" + "options.cfg") + ", creating new default config");
		save(1, 1);
	}
	else
	{
		logMessage("Reading config: " + (c36_cfd42c + "user/" + "options.cfg"));
		a1 = 0;
		while (getline(allies, bottom))
	{
		a1 = a1 + 1;
		center.clear();
		parseLine_408d70(bottom, center);
		if (!center.empty() && breakConfigVar(center.front(), adj, col, a1, c36_cfd42c + "user/" + "options.cfg"))
	{
		branch = OpT8a_findStringIndex(configOptionNames, 243, adj);
		switch (branch)
	{
	case 27:
		f64 = col;
		if (!f64.empty())
	{
		for (int cols = f64.size() - 1; cols >= 0; cols--)
	{
		if (!isAllowedChar_415fc0(f64[cols]) || f64[cols] == ',')
			f64.erase(f64.begin() + cols);
	}
	}
		while (!f64.empty() && f64[0] == ' ')
			f64.erase(f64.begin());
		if (f64.empty())
	{
		f64 = c36_d2f184;
	}
	else
	{
		if (f64.size() > c36_d035d4)
	{
		f64.erase(f64.begin() + c36_d035d4, f64.end());
	}
	else
	{
		if (f64.size() < c36_d035d0)
	{
		padRight_4080d0(f64, c36_d035d0, '_');
	}
	}
	}
		break;
	case 28:
		f80 = col;
		if (!f80.empty())
	{
		for (int cols = f80.size() - 1; cols >= 0; cols--)
	{
		if (!isAllowedChar_415fc0(f80[cols]) || f80[cols] == '`' || f80[cols] == ',')
			f80.erase(f80.begin() + cols);
	}
	}
		if (f80.empty())
	{
		f80 = "0";
	}
		break;
	case 29:
		f9c = stringToInt(col);
		break;
	case 30:
		f9d = stringToInt(col);
		break;
	case 31:
		f9e = stringToInt(col);
		break;
	case 32:
		f9f = stringToInt(col);
		break;
	case 33:
		fa0 = stringToInt(col);
		break;
	case 34:
		fa1 = stringToInt(col);
		break;
	case 35:
		fa4 = ops7_clamp_9cdc80(0, stringToInt(col), 3);
		break;
	case 36:
	{
		branch = OpT8a_findStringIndex(gameStrings_d384f0, 3, col);
		if (branch == -1)
	{
		logError("Config::init()", "Replacing unrecognized log format (" + col + ") with default");
	}
	else
	{
		fa8 = branch;
	}
	}
	break;
	case 37:
		fac = stringToInt(col);
		break;
	case 38:
		fad = stringToInt(col);
		break;
	case 39:
		fae = stringToInt(col);
		break;
	case 40:
	{
		branch = OpT8a_findStringIndex(gameStrings_d28c1c, 2, col);
		if (branch == -1)
	{
		logError("Config::init()", "Replacing unrecognized log combat verbosity (" + col + ") with default");
	}
	else
	{
		fb0 = branch;
	}
	}
	break;
	case 41:
		fb4 = stringToInt(col);
		break;
	case 42:
		fb5 = stringToInt(col);
		break;
	case 43:
		fb8 = stringToInt(col);
		break;
	case 44:
		fbc = stringToInt(col);
		break;
	case 45:
		fbd = stringToInt(col);
		break;
	case 46:
		fbe = stringToInt(col);
		break;
	case 47:
		fbf = stringToInt(col);
		break;
	case 48:
		fc0 = stringToInt(col);
		break;
	case 49:
		fc4 = stringToInt(col);
		break;
	case 50:
		fc8 = stringToInt(col);
		break;
	case 51:
		fc9 = stringToInt(col);
		break;
	case 52:
		fca = stringToInt(col);
		break;
	case 53:
		fcc = stringToInt(col);
		break;
	case 54:
		fd0 = stringToInt(col);
		break;
	case 55:
		fd1 = stringToInt(col);
		break;
	case 56:
		fd2 = stringToInt(col);
		break;
	case 57:
		fd3 = stringToInt(col);
		break;
	case 58:
		fd4 = stringToInt(col);
		break;
	case 59:
		fd8 = stringToInt(col);
		OpC_clampMax(&fd8, 2000);
		break;
	case 60:
		fdc = stringToInt(col);
		OpC_clampMax(&fdc, 4);
		break;
	case 61:
	{
		branch = OpT8a_findStringIndex(gameStrings_d38478, 3, col);
		if (branch == -1)
	{
		logError("Config::init()", "Replacing unrecognized fov handling (" + col + ") with default");
	}
	else
	{
		fe0 = branch;
	}
	}
	break;
	case 62:
		fe4 = stringToInt(col);
		break;
	case 63:
		fe5 = stringToInt(col);
		break;
	case 64:
		fe8 = stringToInt(col);
		break;
	case 65:
		fec = stringToInt(col);
		break;
	case 66:
		ff0 = stringToInt(col);
		break;
	case 67:
		ff4 = stringToInt(col);
		break;
	case 68:
		ff8 = stringToInt(col);
		break;
	case 69:
	{
		branch = OpT8a_findStringIndex(gameStrings_d21dd0, 4, col);
		if (branch == -1)
	{
		logError("Config::init()", "Replacing unrecognized multiconsole type (" + col + ") with default");
	}
	else
	{
		ffc = branch;
		if (f0 == 2 && ffc < 2)
	{
		logWarning("Config::init()", "Last multiconsole setting (" + col + ") incompatible with new UI layout, replacing with default");
		ffc = 3;
	}
	}
	}
	break;
	case 70:
	{
		branch = OpT8a_findStringIndex(gameStrings_cf3418, 8, col);
		if (branch == -1)
	{
		logError("Config::init()", "Replacing unrecognized part info mode (" + col + ") with default");
	}
	else
	{
		f100 = branch;
	}
	}
	break;
	case 71:
		f104 = stringToInt(col);
		break;
	case 72:
		f108.assign(6, false);
		if (col != "NONE")
	{
		vector<string> cols;
		c36_split_408700(col, 124, cols);
		for (unsigned int current = 0; current < cols.size(); current++)
	{
		branch = OpT8a_findStringIndex(gameStrings_d15db0, 6, cols[current]);
		if (branch == -1)
	{
		logError("Config::init()", "Unknown achievementCategoryType: " + cols[current]);
	}
	else
	{
		f108[branch] = true;
	}
	}
	}
		break;
	case 73:
	{
		branch = OpT8a_findStringIndex(gameStrings_d1e1e0, 3, col);
		if (branch == -1)
	{
		logError("Config::init()", "Replacing unrecognized achievementsStateFilterType (" + col + ") with default");
	}
	else
	{
		f11c = branch;
	}
	}
	break;
	case 74:
	{
		branch = OpT8a_findStringIndex(gameStrings_d1e448, 4, col);
		if (branch == -1)
	{
		logError("Config::init()", "Replacing unrecognized achievementsSortType (" + col + ") with default");
		break;
	}
		f120 = branch;
	}
	}
	}
	}
		allies.close();
	}
	allies.open((c36_cfd42c + "user/" + "advanced.cfg").c_str());
	if (!allies.is_open())
	{
		logWarning("Config::init()", "Unable to open " + (c36_cfd42c + "user/" + "advanced.cfg") + ", creating new default config");
		save(2, 1);
	}
	else
	{
		logMessage("Reading config: " + (c36_cfd42c + "user/" + "advanced.cfg"));
		a1 = 0;
		while (getline(allies, bottom))
	{
		a1 = a1 + 1;
		center.clear();
		parseLine_408d70(bottom, center);
		if (!center.empty() && breakConfigVar(center.front(), adj, col, a1, c36_cfd42c + "user/" + "advanced.cfg"))
	{
		branch = OpT8a_findStringIndex(configOptionNames, 243, adj);
		switch (branch)
	{
	case 75:
		f124 = stringToInt(col);
		break;
	case 76:
		f125 = stringToInt(col);
		break;
	case 77:
		init_4456b0(77, col);
		break;
	case 78:
		init_4456b0(78, col);
		break;
	case 79:
	case 80:
	case 81:
	case 82:
	case 83:
	case 84:
	case 85:
	case 86:
	case 87:
	case 88:
	case 89:
	case 90:
		f148[branch - 79] = stringToInt(col);
		break;
	case 91:
		f178 = stringToInt(col);
		break;
	case 92:
		f179 = stringToInt(col);
		break;
	case 93:
		f17a = stringToInt(col);
		break;
	case 94:
		f17b = stringToInt(col);
		break;
	case 95:
		f17c = stringToInt(col);
		break;
	case 96:
		f180 = stringToInt(col);
		break;
	case 97:
		f184 = stringToInt(col);
		break;
	case 98:
		f185 = stringToInt(col);
		break;
	case 99:
		f186 = stringToInt(col);
		break;
	case 100:
		f187 = stringToInt(col);
		break;
	case 101:
		f188 = stringToInt(col);
		break;
	case 102:
		f18c = stringToInt(col);
		break;
	case 103:
		f190 = stringToInt(col);
		break;
	case 104:
		f191 = stringToInt(col);
		break;
	case 105:
		f192 = stringToInt(col);
		break;
	case 106:
		f193 = stringToInt(col);
		break;
	case 107:
		f194 = stringToInt(col);
		break;
	case 108:
		f195 = stringToInt(col);
		break;
	case 109:
		f198 = stringToInt(col);
		f198 = ops7_clamp_9cdc80(0, f198, 100);
		break;
	case 110:
		f19c = stringToInt(col);
		break;
	case 111:
		f19d = stringToInt(col);
		break;
	case 112:
		f19e = stringToInt(col);
		break;
	case 113:
		f19f = stringToInt(col);
		break;
	case 114:
		f1a0 = stringToInt(col);
		break;
	case 115:
		f1a4 = stringToInt(col);
		break;
	case 116:
		f1a8 = stringToInt(col);
		OpC_clampMin(&f1a8, f1a4 + 1);
		break;
	case 117:
		f1ac = stringToInt(col);
		OpC_clampMin(&f1ac, 501);
		break;
	case 118:
		f1b0 = stringToInt(col);
		break;
	case 119:
		if (col == "NONE")
	{
		f1b4 = 0;
	}
	else
	{
		branch = OpT8a_findStringIndex(gameStrings_cf3668, 31, col);
		if (branch == -1)
	{
		logError("Config::init()", "Replacing unrecognized focusPropulsionType type (" + col + ") with default");
	}
	else
	{
		f1b4 = branch;
	}
	}
		break;
	case 120:
		f1b8 = stringToInt(col);
		f1b8 = ops7_clamp_9cdc80(10, f1b8, 500);
		break;
	case 121:
		f1bc = stringToInt(col);
		break;
	case 122:
		f1bd = stringToInt(col);
		break;
	case 123:
		f1be = stringToInt(col);
		break;
	case 124:
		f1bf = stringToInt(col);
		break;
	case 125:
		f1c0 = stringToInt(col);
		OpC_clampMin(&f1c0, 100);
		break;
	case 126:
		f1c4 = stringToInt(col);
		break;
	case 127:
	{
		branch = OpT8a_findStringIndex(gameStrings_d1ed68, 5, col);
		if (branch == -1)
	{
		logError("Config::init()", "Replacing unrecognized keyboardMoveViewCenterpointBehaviorFull type (" + col + ") with default");
	}
	else
	{
		f1c8 = branch;
	}
	}
	break;
	case 128:
	{
		branch = OpT8a_findStringIndex(gameStrings_d1ed68, 5, col);
		if (branch == -1)
	{
		logError("Config::init()", "Replacing unrecognized keyboardMoveViewCenterpointBehaviorModal type (" + col + ") with default");
	}
	else
	{
		f1cc = branch;
	}
	}
	break;
	case 129:
		f1d0 = ops7_clamp_9cdc80(2, stringToInt(col), 11);
		break;
	case 130:
		f1d4 = stringToInt(col);
		break;
	case 131:
		f1d5 = stringToInt(col);
		break;
	case 132:
		f1d6 = stringToInt(col);
		break;
	case 133:
		f1d8 = ops7_clamp_9cdc80(0, stringToInt(col), 3000);
		break;
	case 134:
		f1dc = stringToInt(col);
		break;
	case 135:
		f1dd = stringToInt(col);
		break;
	case 136:
		f1de = stringToInt(col);
		break;
	case 137:
		f1df = stringToInt(col);
		break;
	case 138:
		f1e0 = stringToInt(col);
		break;
	case 139:
		f1e1 = stringToInt(col);
		break;
	case 140:
		f1e2 = stringToInt(col);
		break;
	case 141:
		f1e3 = stringToInt(col);
		break;
	case 142:
		f1e4 = stringToInt(col);
		break;
	case 143:
		f1e5 = stringToInt(col);
		break;
	case 144:
		f1e6 = stringToInt(col);
		break;
	case 145:
		f1e7 = stringToInt(col);
		break;
	case 146:
		f1e8 = stringToInt(col);
		break;
	case 147:
		f1ec = stringToInt(col);
		break;
	case 148:
		f1ed = stringToInt(col);
		break;
	case 149:
		f1ee = stringToInt(col);
		break;
	case 150:
		f1ef = stringToInt(col);
		break;
	case 151:
		f1f0 = stringToInt(col);
		break;
	case 152:
		f1f1 = stringToInt(col);
		break;
	case 153:
		f1f2 = stringToInt(col);
		break;
	case 154:
		f1f3 = stringToInt(col);
		break;
	case 155:
		f1f4 = stringToInt(col);
		break;
	case 156:
		f1f5 = stringToInt(col);
		break;
	case 157:
		f1f6 = stringToInt(col);
		break;
	case 158:
		f1f8 = stringToInt(col);
		OpC_clampMin(&f1f8, 50);
		break;
	case 159:
		f1fc = stringToInt(col);
		OpC_clampMin(&f1fc, 1000);
		break;
	case 160:
		f200 = stringToInt(col);
		break;
	case 161:
		f201 = stringToInt(col);
		break;
	case 162:
		f202 = stringToInt(col);
		break;
	case 163:
		f204 = stringToInt(col);
		f204 = ops7_clamp_9cdc80(2, f204, 20);
		break;
	case 164:
		f208 = stringToInt(col);
		f208 = ops7_clamp_9cdc80(2, f208, 20);
		break;
	case 165:
		f20c = stringToInt(col);
		break;
	case 166:
		f20d = stringToInt(col);
		break;
	case 167:
		f20e = stringToInt(col);
		break;
	case 168:
		f20f = stringToInt(col);
		break;
	case 169:
		f210 = stringToInt(col);
		break;
	case 170:
		f211 = stringToInt(col);
		break;
	case 171:
		f212 = stringToInt(col);
		break;
	case 172:
		f213 = stringToInt(col);
		break;
	case 173:
		f214 = stringToInt(col);
		break;
	case 174:
		f215 = stringToInt(col);
		break;
	case 175:
		f216 = stringToInt(col);
		break;
	case 176:
		f217 = stringToInt(col);
		break;
	case 177:
		f218 = stringToInt(col);
		break;
	case 178:
		f219 = stringToInt(col);
		break;
	case 179:
		f21a = stringToInt(col);
		break;
	case 180:
		f21b = stringToInt(col);
		break;
	case 181:
		f21c = stringToInt(col);
		break;
	case 182:
		f21d = stringToInt(col);
		break;
	case 183:
		f21e = stringToInt(col);
		break;
	case 184:
		f220 = stringToInt(col);
		break;
	case 185:
		f224 = stringToInt(col);
		break;
	case 186:
		f228 = stringToInt(col);
		break;
	case 187:
		f22c = stringToInt(col);
		break;
	case 188:
		f230 = stringToInt(col);
		break;
	case 189:
		f234 = stringToInt(col);
		break;
	case 190:
		f238 = stringToInt(col);
		break;
	case 191:
		f23c = stringToInt(col);
		break;
	case 192:
		f240 = stringToInt(col);
		if (f240 != 0)
	{
		f240 = ops7_clamp_9cdc80(500, f240, 100000);
	}
		break;
	case 193:
		f244 = stringToInt(col);
		if (f244 != 0)
	{
		f244 = ops7_clamp_9cdc80(100, f244, 5000);
	}
		break;
	case 194:
		f248 = stringToInt(col);
		break;
	case 195:
		f249 = stringToInt(col);
		break;
	case 196:
		f2f8 = stringToInt(col);
		break;
	case 197:
		f2f9 = stringToInt(col);
		break;
	case 198:
		f2fa = stringToInt(col);
		break;
	case 199:
		f2fb = stringToInt(col);
		break;
	case 200:
		f2fc = stringToInt(col);
		break;
	case 201:
		f2fd = stringToInt(col);
		break;
	case 202:
		f2fe = stringToInt(col);
		break;
	case 203:
		f2ff = stringToInt(col);
		break;
	case 204:
		f300 = stringToInt(col);
		break;
	case 205:
		f304 = stringToInt(col);
		if (f304 != 0)
	{
		f304 = ops7_clamp_9cdc80(10, f304, 100);
	}
		break;
	case 206:
		f308 = stringToInt(col);
		OpC_clampMin(&f308, 2000);
		break;
	case 207:
		f30c = stringToInt(col);
		break;
	case 208:
		f310 = stringToInt(col);
		if (f310 != 0)
	{
		f310 = ops7_clamp_9cdc80(6, f310, 10);
	}
		break;
	case 209:
		f314 = stringToInt(col);
		OpC_clampMin(&f314, 2000);
		break;
	case 210:
		f318 = stringToInt(col);
		if (f318 != 0)
	{
		f318 = ops7_clamp_9cdc80(6, f318, 10);
	}
		break;
	case 211:
		f31c = stringToInt(col);
		OpC_clampMin(&f31c, 2000);
		break;
	case 212:
		f320 = stringToInt(col);
		OpC_clampMin(&f320, 2000);
		break;
	case 213:
		f324 = stringToInt(col);
		break;
	case 214:
		f328 = stringToInt(col);
		OpC_clampMin(&f328, 0);
		break;
	case 215:
		f32c = stringToInt(col);
		OpC_clampMin(&f32c, 0);
		break;
	case 216:
		f330 = stringToInt(col);
		break;
	case 217:
	{
		branch = OpT8a_findStringIndex(gameStrings_d25ee0, 4, col);
		if (branch == -1)
	{
		logError("Config::init()", "Replacing unrecognized cogmindPartLossMapIndicator type (" + col + ") with default");
	}
	else
	{
		f334 = branch;
	}
	}
	break;
	case 218:
		f338 = stringToInt(col);
		break;
	case 219:
		f339 = stringToInt(col);
		break;
	case 220:
		f33a = stringToInt(col);
		break;
	case 221:
		f33b = stringToInt(col);
		break;
	case 222:
		f33c = stringToInt(col);
		break;
	case 223:
		f33d = stringToInt(col);
		break;
	case 224:
		f33e = stringToInt(col);
		break;
	case 225:
		f33f = stringToInt(col);
		break;
	case 226:
		f340 = stringToInt(col);
		break;
	case 227:
		f341 = stringToInt(col);
		break;
	case 228:
		f342 = stringToInt(col);
		break;
	case 229:
		f343 = stringToInt(col);
		break;
	case 230:
		f344 = stringToInt(col);
		break;
	case 231:
		f345 = stringToInt(col);
		break;
	case 232:
		f346 = stringToInt(col);
		break;
	case 233:
		f347 = stringToInt(col);
		break;
	case 234:
		f348 = stringToInt(col);
		break;
	case 235:
		f349 = stringToInt(col);
		break;
	case 236:
		f34a = stringToInt(col);
		break;
	case 237:
		f34c = stringToInt(col);
		f34c = ops7_clamp_9cdc80(5, f34c, 100);
		break;
	case 238:
		f350 = stringToInt(col);
		f350 = ops7_clamp_9cdc80(1000, f350, 20000);
		break;
	case 239:
		f354 = stringToInt(col);
		break;
	case 240:
		f355 = stringToInt(col);
		break;
	case 241:
	{
		f358 = OpT8a_findStringIndex(gameStrings_d230f8, 323, col);
		if (f358 == -1)
	{
		logError("Config::init()", "Replacing unrecognized runCommandModKey (" + col + ") with default 'r'");
		f358 = 114;
	}
	}
	break;
	case 242:
		f35c = stringToInt(col);
	}
	}
	}
		allies.close();
	}
}
