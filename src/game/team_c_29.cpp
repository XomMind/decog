// team_c_29: Config::save (0x440450): writes user/system.cfg, options.cfg or advanced.cfg as name=value lines
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
	char padad[0x1];
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

	int boolToInt(bool value);	// 0x445590
	string colorFiltersToString(int which);	// 0x445e70
	void save(int which, bool skipStats);
};

void Config::save(int which, bool skipStats)
{
	ofstream out;
	switch (which)
	{
	case 0:
		if (!skipStats)
		{
			int a = (stats_d223f0.getA() - stats_d223f0.getB() * 60) / (stats_d223f0.getB() * 2);
			f3c = OpX5_minInt(f3c,a);
			int b = (stats_d223f0.getC() - (mode_cebd5c == 2 ? 1 : 10) * stats_d223f0.getD()) / stats_d223f0.getD();
			f40 = OpX5_minInt(f40,b);
		}
		out.open((gameString_cfd42c + "user/" + "system.cfg").c_str());
		if (!out.is_open())
		{
			logError("Config::save()","Unable to open " + (gameString_cfd42c + "user/" + "system.cfg") + " for writing, config not saved");
			return;
		}
		out << "// This first section of options is accessible from the in-game options menu. Editing them here is not recommended, but you might be interested in advanced.cfg.\n";
		out << configOptionNames[0] << "=" << f0 << "\n";
		out << configOptionNames[1] << "=" << "\"" << f4 << "\"" << "\n";
		if (!skipStats)
			f20 = stats_d223f0.isValid();
		out << configOptionNames[2] << "=" << boolToInt(f20) << "\n";
		if (!skipStats)
			f21 = stats_d223f0.getFlag();
		out << configOptionNames[3] << "=" << boolToInt(f21) << "\n";
		out << configOptionNames[4] << "=" << boolToInt(f22) << "\n";
		out << configOptionNames[5] << "=" << boolToInt(f23) << "\n";
		out << configOptionNames[6] << "=" << f24 << "\n";
		for (int i = 0; i < 4; i++)
			out << configOptionNames[i + 7] << "=" << boolToInt(f28[i]) << "\n";
		for (int j = 0; j < 4; j++)
			out << configOptionNames[j + 11] << "=" << f2c[j] << "\n";
		out << "// The functions of these options are described in the manual under Advanced UI > System Options. Only edit this file while the game is not running.\n";
		out << configOptionNames[15] << "=" << f3c << "\n";
		out << configOptionNames[16] << "=" << f40 << "\n";
		out << configOptionNames[17] << "=" << f44 << "\n";
		out << configOptionNames[18] << "=" << boolToInt(f48) << "\n";
		out << configOptionNames[19] << "=" << f4c << "\n";
		out << configOptionNames[20] << "=" << f50 << "\n";
		out << configOptionNames[21] << "=" << boolToInt(f54) << "\n";
		out << configOptionNames[22] << "=" << boolToInt(f55) << "\n";
		out << configOptionNames[23] << "=" << boolToInt(f56) << "\n";
		out << "// Other internal records\n";
		out << configOptionNames[24] << "=" << f58 << "\n";
		out << configOptionNames[25] << "=" << f5c << "\n";
		out << configOptionNames[26] << "=" << f60 << "\n";
		out.close();
		break;
	case 1:
	{
		out.open((gameString_cfd42c + "user/" + "options.cfg").c_str());
		if (!out.is_open())
		{
			logError("Config::save()","Unable to open " + (gameString_cfd42c + "user/" + "options.cfg") + " for writing, config not saved");
			return;
		}
		out << "// These options are accessible from the in-game options menu. There is no need to edit this file, but you might be interested in advanced.cfg.\n";
		out << configOptionNames[27] << "=" << "\"" << f64 << "\"" << "\n";
		out << configOptionNames[28] << "=" << "\"" << f80 << "\"" << "\n";
		out << configOptionNames[29] << "=" << boolToInt(f9c) << "\n";
		out << configOptionNames[30] << "=" << boolToInt(f9d) << "\n";
		out << configOptionNames[31] << "=" << boolToInt(f9e) << "\n";
		out << configOptionNames[32] << "=" << boolToInt(f9f) << "\n";
		out << configOptionNames[33] << "=" << boolToInt(fa0) << "\n";
		out << configOptionNames[34] << "=" << boolToInt(fa1) << "\n";
		out << configOptionNames[35] << "=" << fa4 << "\n";
		out << configOptionNames[36] << "=" << gameStrings_d384f0[fa8] << "\n";
		out << configOptionNames[37] << "=" << boolToInt(fac) << "\n";
		out << configOptionNames[38] << "=" << boolToInt(false) << "\n";
		out << configOptionNames[39] << "=" << boolToInt(fae) << "\n";
		out << configOptionNames[40] << "=" << gameStrings_d28c1c[fb0] << "\n";
		out << configOptionNames[41] << "=" << boolToInt(fb4) << "\n";
		out << configOptionNames[42] << "=" << boolToInt(fb5) << "\n";
		out << configOptionNames[43] << "=" << fb8 << "\n";
		out << configOptionNames[44] << "=" << boolToInt(fbc) << "\n";
		out << configOptionNames[45] << "=" << boolToInt(fbd) << "\n";
		out << configOptionNames[46] << "=" << boolToInt(fbe) << "\n";
		out << configOptionNames[47] << "=" << boolToInt(fbf) << "\n";
		out << configOptionNames[48] << "=" << boolToInt(fc0) << "\n";
		out << configOptionNames[49] << "=" << fc4 << "\n";
		out << configOptionNames[50] << "=" << boolToInt(fc8) << "\n";
		out << configOptionNames[51] << "=" << boolToInt(fc9) << "\n";
		out << configOptionNames[52] << "=" << boolToInt(fca) << "\n";
		out << configOptionNames[53] << "=" << fcc << "\n";
		out << configOptionNames[54] << "=" << boolToInt(fd0) << "\n";
		out << configOptionNames[55] << "=" << boolToInt(fd1) << "\n";
		out << configOptionNames[56] << "=" << boolToInt(fd2) << "\n";
		out << configOptionNames[57] << "=" << boolToInt(fd3) << "\n";
		out << configOptionNames[58] << "=" << boolToInt(fd4) << "\n";
		out << configOptionNames[59] << "=" << fd8 << "\n";
		out << configOptionNames[60] << "=" << fdc << "\n";
		out << configOptionNames[61] << "=" << gameStrings_d38478[fe0] << "\n";
		out << configOptionNames[62] << "=" << boolToInt(fe4) << "\n";
		out << configOptionNames[63] << "=" << boolToInt(fe5) << "\n";
		out << configOptionNames[64] << "=" << fe8 << "\n";
		out << configOptionNames[65] << "=" << fec << "\n";
		out << configOptionNames[66] << "=" << ff0 << "\n";
		out << configOptionNames[67] << "=" << ff4 << "\n";
		out << configOptionNames[68] << "=" << boolToInt(ff8) << "\n";
		out << "// other/auto:\n";
		out << configOptionNames[69] << "=" << gameStrings_d21dd0[ffc] << "\n";
		out << configOptionNames[70] << "=" << gameStrings_cf3418[f100] << "\n";
		out << configOptionNames[71] << "=" << boolToInt(f104) << "\n";
		out << configOptionNames[72] << "=";
		bool written = false;
		for (int k = 0; k < 6; k++)
		{
			if (f108[k])
			{
				if (written)
					out << '|';
				out << gameStrings_d15db0[k];
				written = true;
			}
		}
		if (!written)
			out << "NONE";
		out << "\n";
		out << configOptionNames[73] << "=" << gameStrings_d1e1e0[f11c] << "\n";
		out << configOptionNames[74] << "=" << gameStrings_d1e448[f120] << "\n";
		out.close();
		break;
	}
	case 2:
		out.open((gameString_cfd42c + "user/" + "advanced.cfg").c_str());
		if (!out.is_open())
		{
			logError("Config::save()","Unable to open " + (gameString_cfd42c + "user/" + "advanced.cfg") + " for writing, config not saved");
			return;
		}
		out << "// The functions of these options are described in the manual under Advanced UI > Advanced Options. Only edit this file while the game is not running.\n";
		out << configOptionNames[75] << "=" << boolToInt(f124) << "\n";
		out << configOptionNames[76] << "=" << boolToInt(f125) << "\n";
		out << configOptionNames[77] << "=" << colorFiltersToString(77) << "\n";
		out << configOptionNames[78] << "=" << colorFiltersToString(78) << "\n";
		for (int m = 0; m < 12; m++)
			out << configOptionNames[m + 79] << "=" << f148[m] << "\n";
		out << configOptionNames[91] << "=" << boolToInt(f178) << "\n";
		out << configOptionNames[92] << "=" << boolToInt(f179) << "\n";
		out << configOptionNames[93] << "=" << boolToInt(f17a) << "\n";
		out << configOptionNames[94] << "=" << boolToInt(f17b) << "\n";
		out << configOptionNames[95] << "=" << f17c << "\n";
		out << configOptionNames[96] << "=" << f180 << "\n";
		out << configOptionNames[97] << "=" << boolToInt(f184) << "\n";
		out << configOptionNames[98] << "=" << boolToInt(f185) << "\n";
		out << configOptionNames[99] << "=" << boolToInt(f186) << "\n";
		out << configOptionNames[100] << "=" << boolToInt(f187) << "\n";
		out << configOptionNames[101] << "=" << f188 << "\n";
		out << configOptionNames[102] << "=" << f18c << "\n";
		out << configOptionNames[103] << "=" << boolToInt(f190) << "\n";
		out << configOptionNames[104] << "=" << boolToInt(f191) << "\n";
		out << configOptionNames[105] << "=" << boolToInt(f192) << "\n";
		out << configOptionNames[106] << "=" << boolToInt(f193) << "\n";
		out << configOptionNames[107] << "=" << boolToInt(f194) << "\n";
		out << configOptionNames[108] << "=" << boolToInt(f195) << "\n";
		out << configOptionNames[109] << "=" << f198 << "\n";
		out << configOptionNames[110] << "=" << boolToInt(f19c) << "\n";
		out << configOptionNames[111] << "=" << boolToInt(f19d) << "\n";
		out << configOptionNames[112] << "=" << boolToInt(f19e) << "\n";
		out << configOptionNames[113] << "=" << boolToInt(f19f) << "\n";
		out << configOptionNames[114] << "=" << boolToInt(f1a0) << "\n";
		out << configOptionNames[115] << "=" << f1a4 << "\n";
		out << configOptionNames[116] << "=" << f1a8 << "\n";
		out << configOptionNames[117] << "=" << f1ac << "\n";
		out << configOptionNames[118] << "=" << boolToInt(f1b0) << "\n";
		out << configOptionNames[119] << "=" << (f1b4 ? gameStrings_cf3668[f1b4] : string("NONE")) << "\n";
		out << configOptionNames[120] << "=" << f1b8 << "\n";
		out << configOptionNames[121] << "=" << boolToInt(f1bc) << "\n";
		out << configOptionNames[122] << "=" << boolToInt(f1bd) << "\n";
		out << configOptionNames[123] << "=" << boolToInt(f1be) << "\n";
		out << configOptionNames[124] << "=" << boolToInt(f1bf) << "\n";
		out << configOptionNames[125] << "=" << f1c0 << "\n";
		out << configOptionNames[126] << "=" << f1c4 << "\n";
		out << configOptionNames[127] << "=" << gameStrings_d1ed68[f1c8] << "\n";
		out << configOptionNames[128] << "=" << gameStrings_d1ed68[f1cc] << "\n";
		out << configOptionNames[129] << "=" << f1d0 << "\n";
		out << configOptionNames[130] << "=" << boolToInt(f1d4) << "\n";
		out << configOptionNames[131] << "=" << boolToInt(f1d5) << "\n";
		out << configOptionNames[132] << "=" << boolToInt(f1d6) << "\n";
		out << configOptionNames[133] << "=" << f1d8 << "\n";
		out << configOptionNames[134] << "=" << boolToInt(f1dc) << "\n";
		out << configOptionNames[135] << "=" << boolToInt(f1dd) << "\n";
		out << configOptionNames[136] << "=" << boolToInt(f1de) << "\n";
		out << configOptionNames[137] << "=" << boolToInt(f1df) << "\n";
		out << configOptionNames[138] << "=" << boolToInt(f1e0) << "\n";
		out << configOptionNames[139] << "=" << boolToInt(f1e1) << "\n";
		out << configOptionNames[140] << "=" << boolToInt(f1e2) << "\n";
		out << configOptionNames[141] << "=" << boolToInt(f1e3) << "\n";
		out << configOptionNames[142] << "=" << boolToInt(f1e4) << "\n";
		out << configOptionNames[143] << "=" << boolToInt(f1e5) << "\n";
		out << configOptionNames[144] << "=" << boolToInt(f1e6) << "\n";
		out << configOptionNames[145] << "=" << boolToInt(f1e7) << "\n";
		out << configOptionNames[146] << "=" << boolToInt(f1e8 != 0) << "\n";
		out << configOptionNames[147] << "=" << boolToInt(f1ec) << "\n";
		out << configOptionNames[148] << "=" << boolToInt(f1ed) << "\n";
		out << configOptionNames[149] << "=" << boolToInt(f1ee) << "\n";
		out << configOptionNames[150] << "=" << boolToInt(f1ef) << "\n";
		out << configOptionNames[151] << "=" << boolToInt(f1f0) << "\n";
		out << configOptionNames[152] << "=" << boolToInt(f1f1) << "\n";
		out << configOptionNames[153] << "=" << boolToInt(f1f2) << "\n";
		out << configOptionNames[154] << "=" << boolToInt(f1f3) << "\n";
		out << configOptionNames[155] << "=" << boolToInt(f1f4) << "\n";
		out << configOptionNames[156] << "=" << boolToInt(f1f5) << "\n";
		out << configOptionNames[157] << "=" << boolToInt(f1f6) << "\n";
		out << configOptionNames[158] << "=" << f1f8 << "\n";
		out << configOptionNames[159] << "=" << f1fc << "\n";
		out << configOptionNames[160] << "=" << boolToInt(f200) << "\n";
		out << configOptionNames[161] << "=" << boolToInt(f201) << "\n";
		out << configOptionNames[162] << "=" << boolToInt(f202) << "\n";
		out << configOptionNames[163] << "=" << f204 << "\n";
		out << configOptionNames[164] << "=" << f208 << "\n";
		out << configOptionNames[165] << "=" << boolToInt(f20c) << "\n";
		out << configOptionNames[166] << "=" << boolToInt(f20d) << "\n";
		out << configOptionNames[167] << "=" << boolToInt(f20e) << "\n";
		out << configOptionNames[168] << "=" << boolToInt(f20f) << "\n";
		out << configOptionNames[169] << "=" << boolToInt(f210) << "\n";
		out << configOptionNames[170] << "=" << boolToInt(f211) << "\n";
		out << configOptionNames[171] << "=" << boolToInt(f212) << "\n";
		out << configOptionNames[172] << "=" << boolToInt(f213) << "\n";
		out << configOptionNames[173] << "=" << boolToInt(f214) << "\n";
		out << configOptionNames[174] << "=" << boolToInt(f215) << "\n";
		out << configOptionNames[175] << "=" << boolToInt(f216) << "\n";
		out << configOptionNames[176] << "=" << boolToInt(f217) << "\n";
		out << configOptionNames[177] << "=" << boolToInt(f218) << "\n";
		out << configOptionNames[178] << "=" << boolToInt(f219) << "\n";
		out << configOptionNames[179] << "=" << boolToInt(f21a) << "\n";
		out << configOptionNames[180] << "=" << boolToInt(f21b) << "\n";
		out << configOptionNames[181] << "=" << boolToInt(f21c) << "\n";
		out << configOptionNames[182] << "=" << boolToInt(f21d) << "\n";
		out << configOptionNames[183] << "=" << boolToInt(f21e) << "\n";
		out << configOptionNames[184] << "=" << f220 << "\n";
		out << configOptionNames[185] << "=" << boolToInt(f224) << "\n";
		out << configOptionNames[186] << "=" << f228 << "\n";
		out << configOptionNames[187] << "=" << f22c << "\n";
		out << configOptionNames[188] << "=" << f230 << "\n";
		out << configOptionNames[189] << "=" << f234 << "\n";
		out << configOptionNames[190] << "=" << f238 << "\n";
		out << configOptionNames[191] << "=" << boolToInt(f23c) << "\n";
		out << configOptionNames[192] << "=" << f240 << "\n";
		out << configOptionNames[193] << "=" << f244 << "\n";
		out << configOptionNames[194] << "=" << boolToInt(f248) << "\n";
		out << configOptionNames[195] << "=" << boolToInt(f249) << "\n";
		out << configOptionNames[196] << "=" << boolToInt(f2f8) << "\n";
		out << configOptionNames[197] << "=" << boolToInt(f2f9) << "\n";
		out << configOptionNames[198] << "=" << boolToInt(f2fa) << "\n";
		out << configOptionNames[199] << "=" << boolToInt(f2fb) << "\n";
		out << configOptionNames[200] << "=" << boolToInt(f2fc) << "\n";
		out << configOptionNames[201] << "=" << boolToInt(f2fd) << "\n";
		out << configOptionNames[202] << "=" << boolToInt(f2fe) << "\n";
		out << configOptionNames[203] << "=" << boolToInt(f2ff) << "\n";
		out << configOptionNames[204] << "=" << f300 << "\n";
		out << configOptionNames[205] << "=" << f304 << "\n";
		out << configOptionNames[206] << "=" << f308 << "\n";
		out << configOptionNames[207] << "=" << boolToInt(f30c) << "\n";
		out << configOptionNames[208] << "=" << f310 << "\n";
		out << configOptionNames[209] << "=" << f314 << "\n";
		out << configOptionNames[210] << "=" << f318 << "\n";
		out << configOptionNames[211] << "=" << f31c << "\n";
		out << configOptionNames[212] << "=" << f320 << "\n";
		out << configOptionNames[213] << "=" << f324 << "\n";
		out << configOptionNames[214] << "=" << f328 << "\n";
		out << configOptionNames[215] << "=" << f32c << "\n";
		out << configOptionNames[216] << "=" << boolToInt(f330) << "\n";
		out << configOptionNames[217] << "=" << gameStrings_d25ee0[f334] << "\n";
		out << configOptionNames[218] << "=" << boolToInt(f338) << "\n";
		out << configOptionNames[219] << "=" << boolToInt(f339) << "\n";
		out << configOptionNames[220] << "=" << boolToInt(f33a) << "\n";
		out << configOptionNames[221] << "=" << boolToInt(f33b) << "\n";
		out << configOptionNames[222] << "=" << boolToInt(f33c) << "\n";
		out << configOptionNames[223] << "=" << boolToInt(f33d) << "\n";
		out << configOptionNames[224] << "=" << boolToInt(f33e) << "\n";
		out << configOptionNames[225] << "=" << boolToInt(f33f) << "\n";
		out << configOptionNames[226] << "=" << boolToInt(f340) << "\n";
		out << configOptionNames[227] << "=" << boolToInt(f341) << "\n";
		out << configOptionNames[228] << "=" << boolToInt(f342) << "\n";
		out << configOptionNames[229] << "=" << boolToInt(f343) << "\n";
		out << configOptionNames[230] << "=" << boolToInt(f344) << "\n";
		out << configOptionNames[231] << "=" << boolToInt(f345) << "\n";
		out << configOptionNames[232] << "=" << boolToInt(f346) << "\n";
		out << configOptionNames[233] << "=" << boolToInt(f347) << "\n";
		out << configOptionNames[234] << "=" << boolToInt(f348) << "\n";
		out << configOptionNames[235] << "=" << boolToInt(f349) << "\n";
		out << configOptionNames[236] << "=" << boolToInt(f34a) << "\n";
		out << configOptionNames[237] << "=" << f34c << "\n";
		out << configOptionNames[238] << "=" << f350 << "\n";
		out << configOptionNames[239] << "=" << boolToInt(f354) << "\n";
		out << configOptionNames[240] << "=" << boolToInt(f355) << "\n";
		out << configOptionNames[241] << "=" << gameStrings_d230f8[f358] << "\n";
		out.close();
		break;
	}

}
