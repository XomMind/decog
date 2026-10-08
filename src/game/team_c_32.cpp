// team_c_32: Scorekeeper::outputScoresheet (0x474a20): builds the end-of-run scoresheet text, writes it to
// scores/ (or dumps/), records score history and the protobuf upload, and returns the file path
// NOTE: member names are placeholders (f<offset>); helper classes and globals are private placeholders
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string intToString(int value);
string floatToString(float value, int unknown1, int unknown2);
string &padRight_4080d0(string &text, int width, char fill);	// NOTE: placeholder name
string &padLeft_408090(string &text, int width, char fill);	// NOTE: placeholder name
string opR1d_436e70(int unknown1, int unknown2, int unknown3);	// NOTE: placeholder name
string OpC_formatDateTime_4716f0(string date, string time);	// NOTE: placeholder name
void logError(string location, string message);
bool OpU8a_containsString(vector<string> *list, string text);	// NOTE: placeholder name
int OpT8b_Fn9d4340(vector<int> &v);	// NOTE: placeholder name
void c32_makeDirectory_409240(string path);	// NOTE: placeholder name (0x409240)
int opY2_startNetworkThread(int type, int unknown, void *function, void *data);	// NOTE: placeholder name
extern string gameStrings_cf10d8[], gameStrings_cf2740[], gameStrings_d01c50[], gameStrings_d1d470[], gameStrings_d293c0[], gameStrings_d2e148[], gameStrings_d378d0[], gameStrings_d38dd0[];	// global_string_arrays.cpp
extern string g_cfd42c;	// NOTE: placeholder name (gameString_cfd42c)

namespace Protobuf
{
class Scoresheet;
class PostScoresheetRequest
{
public:
	PostScoresheetRequest();
	Scoresheet *mutable_scoresheet();
	void set_name(const string &name);	// NOTE: placeholder name
	char data[0x14];
};
}
struct OpC_Owner4718c0	// op_c.cpp (declared with the request type it holds here)
{
	OpC_Owner4718c0(bool flag_);
	~OpC_Owner4718c0();

	Protobuf::PostScoresheetRequest *object;
	bool flag;
};
struct OpS1e_Lists { char pad0[0x40]; int f40; string f44; int f60; OpS1e_Lists(const OpS1e_Lists &o); ~OpS1e_Lists(); };	// NOTE: placeholder layout
struct OpR1h_Small { int f0; string f4; int f20; vector<int> f24, f34, f44, f54; OpR1h_Small(); ~OpR1h_Small(); };	// NOTE: placeholder layout
struct C32_Run { int f34; bool f38, f39, f3a; void unknown4852a0(bool isDump); };	// NOTE: placeholder (object at Scorekeeper+0x34)
struct C32_Location { int a, b; string getName(); };	// NOTE: placeholder
struct C32_Grid { int width, height; char *cells; int getWidth(); int getHeight(); char *at(int x, int y); };	// NOTE: placeholder
struct C32_Text { char pad[8]; int f8; string getText(); };
struct C32_Handle { int v; C32_Text *get23c(); void *get224(); };	// NOTE: placeholder
struct C32_Record { char pad[0x20]; string f20; };
struct C32_Log { void render(string path, const string &name); };	// NOTE: placeholder (MessageLog)

extern vector<C32_Handle> g_d1e88c;	// NOTE: placeholder names below
extern C32_Handle g_d1e888;
extern vector<C32_Record *> g_d389c4;
extern int g_bbc218[], g_ba0028[];
extern int g_cf4b38, g_cf4718, g_d25740, g_d25744, g_d25748, g_cf462c, g_cf4614, g_d2577c;
extern bool g_cefb58;
extern bool g_cefacd, g_d28d04, g_d28eb0, g_d25450;
extern vector<int> g_d25480, g_d25490, g_d254a0, g_d254b0;
extern vector<string> g_d25780;
extern string g_d25760, g_d28ccc, g_d2f184;
extern string g_d21b9c;
extern C32_Log g_cf1080, g_d2f75c;
extern OpS1e_Lists *g_cf68a8;
struct C32_Flags { bool isFlagActive(); bool getField(); };
extern C32_Flags g_cf45d8;
struct C32_Obj2 { char pad[0x1af]; bool f1af; };
struct C32_Obj { int getA(); C32_Obj2 *getB(); int getNestedField(); };	// NOTE: placeholder (folded GetCachedSize/getNestedField)
struct C32_Item { int v; C32_Obj *get224(); };
extern vector<C32_Item> g_cf4944;
struct LC43Owner; int lc43_upload4884c0(LC43Owner *data); int c44_uploadRunData_48a3f0(void *data); int opC_uploadRunData_48ae20(void *data);	// NOTE: placeholder names (thread functions; 0x4884c0 is in util/alpha2_02.cpp, 0x48a3f0 in team_c_44.cpp, 0x48ae20 in op_c_rundata.cpp)

class Scorekeeper	// NOTE: placeholder layout
{
public:
	vector<int> * f0;
	// OVERLAP 4
	vector<vector<int> *> f4;
	char pad14[0x20];
	C32_Run run34;
	string f3c;
	string f58;
	string f74;
	string f90;
	string fac;
	string fc8;
	string fe4;
	char pad100[0x10];
	int f110;
	int f114;
	int f118;
	int f11c;
	int f120;
	int f124;
	int f128;
	int f12c;
	bool f130;
	int f134;
	int f138;
	bool f13c;
	int f140;
	int f144;
	int f148;
	int f14c;
	C32_Location f150;
	vector<int> f158;
	vector<int> f168;
	vector< vector<string> > f178;
	vector< vector<int> > f188;
	vector< vector<int> > f198;
	char pad1a8[0x4];
	int f1ac;
	vector<string> f1b0;
	vector<int> f1c0;
	C32_Grid f1d0;
	int f1dc;
	vector< vector<string> > f1e0;
	vector< vector<int> > f1f0;
	char pad200[0x10];
	vector<string> f210;
	vector<int> f220;
	char pad230[0x4];
	vector<string> f234;
	vector<string> f244;
	vector<string> f254;
	vector<int> f264;
	vector<string> f274;
	int f284;
	vector<int> f288;
	vector<string> f298;
	vector<int> f2a8;
	vector<int> f2b8;
	vector< vector<int> > f2c8;
	vector<string> f2d8;
	char pad2e8[0x10];
	vector<int> f2f8;
	vector<int> f308;
	vector<string> f318;
	vector<string> f328;
	vector<string> f338;
	vector<int> f348;
	vector<int> f358;
	vector<string> f368;
	vector<int> f378;
	vector<int> f388;
	vector<string> f398;
	vector<int> f3a8;
	vector<int> f3b8;
	vector<int> f3c8;
	vector<int> f3d8;
	vector<string> f3e8;
	vector<int> f3f8;
	vector<int> f408;
	vector<int> f418;
	vector<int> f428;
	vector<string> f438;
	vector<int> f448;
	vector<int> f458;
	char pad468[0x10];
	vector<string> f478;
	vector<string> f488;
	vector<string> f498;
	vector<string> f4a8;
	vector<int> f4b8;
	vector<string> f4c8;
	vector<int> f4d8;
	vector<int> f4e8;
	string f4f8;
	bool f514;
	unsigned int f518;
	unsigned int f51c;
	string f520;
	string f53c;
	int f558;
	int f55c;
	string f560;
	int f57c;
	int f580;
	int f584;
	int f588;
	int f58c;
	int f590;
	vector<int> f594;
	int f5a4;
	int f5a8;
	int f5ac;
	bool f5b0;
	int f5b4;
	bool f5b8;
	bool f5b9;
	int f5bc;
	bool f5c0;
	int f5c4;
	string f5c8;
	int f5e4;
	int f5e8;
	int f5ec;
	bool f5f0;
	string f5f4;
	string f610;
	int f62c;
	string f630;
	char pad64c[0x40];
	int f68c;
	int f690;

	int delegate(int index);	// NOTE: placeholder names
	void add4729d0(int a, int b, string c, int d);
	void c32_writeStatBlock_473d20(string *sheet, string title, int first, int last, bool flag);
	void totalScore_47f2e0();
	void createProtobuf(Protobuf::Scoresheet *scoresheet, string filename, bool isDump);
	string outputScoresheet(bool isDump);
};

string Scorekeeper::outputScoresheet(bool isDump)
{
	if (!isDump && g_cf4b38 == 10 && g_d1e888.get23c()->f8 > 9 && !g_cefacd && !g_cf45d8.isFlagActive())
	{
		g_d25740 = g_d25740 - 1;
		switch (g_cf4718)
		{
		case 1:
			g_d25744 = g_d25744 - 1;
			break;
		case 2:
			g_d25748 = g_d25748 - 1;
			break;
		}
		return string();
	}
	f2b8.clear();
	for (int i_2b2c = 525; i_2b2c <= 532; i_2b2c++)
	{
		f2b8.push_back((*f0)[i_2b2c]);
	}
	f2c8.clear();
	for (unsigned int i_2b30 = 0; i_2b30 < f4.size(); i_2b30++)
	{
		f2c8.push_back(vector<int>());
		for (int i_2b34 = 525; i_2b34 <= 532; i_2b34++)
	{
		f2c8.back().push_back((*f4[i_2b30])[i_2b34]);
	}
	}
	f284 = (*f0)[206];
	f288.clear();
	for (unsigned int i_2b38 = 0; i_2b38 < f4.size(); i_2b38++)
	{
		f288.push_back((*f4[i_2b38])[206]);
	}
	if (!isDump)
	{
		vector<C32_Item> * list = &g_cf4944;
		for (unsigned int i_2b40 = 0; i_2b40 < list->size(); i_2b40++)
	{
		if ((*list)[i_2b40].get224())
	{
		if ((*list)[i_2b40].get224()->getA() == -1)
	{
		add4729d0(157, 1, "", -1);
		add4729d0(((*list)[i_2b40].get224()->getB()->f1af ? 162 : (*list)[i_2b40].get224()->getNestedField() + 158), 1, "", -1);
	}
	}
	}
	}
	run34.unknown4852a0(isDump);
	string * tmp = new string();
	*tmp += "Cogmind - " + f3c + " " + f58 + " // " + OpC_formatDateTime_4716f0(f90, fac);
	if (!f74.empty())
	{
		*tmp += " // " + f74 + "\n";
	}
	else
	{
		*tmp += "\n";
	}
	*tmp += "\n";
	*tmp += "Player: " + fc8 + "\n";
	*tmp += "\n";
	*tmp += "Result: " + fe4 + "\n";
	*tmp += "\n";
	*tmp += " Performance \n";
	*tmp += "-------------\n";
	string line;
	for (int i_2b44 = 0; i_2b44 <= 6; i_2b44++)
	{
		line = g_d389c4[i_2b44]->f20 + " (" + intToString(delegate(i_2b44)) + ")";
		padRight_4080d0(line, 27, 32);
		*tmp += line + intToString(delegate(i_2b44) * g_bbc218[i_2b44]) + "\n";
	}
	*tmp += "              TOTAL SCORE: " + intToString(f110) + "\n";
	*tmp += "\n";
	c32_writeStatBlock_473d20(tmp, "Bonus", 7, 106, 0);
	*tmp += " Cogmind \n";
	*tmp += "---------\n";
	*tmp += padRight_4080d0(string("Core Integrity"), 27, 32) + intToString(f114) + "/" + intToString(f118) + "\n";
	*tmp += padRight_4080d0(string("Matter"), 27, 32) + intToString(f11c) + "/" + intToString(f120) + "\n";
	*tmp += padRight_4080d0(string("Energy"), 27, 32) + intToString(f124) + "/" + intToString(f128) + "\n";
	*tmp += padRight_4080d0(string("System Corruption"), 27, 32) + intToString(f12c) + "%" + (f130 ? " +Membrane\n" : "\n");
	*tmp += padRight_4080d0(string("Temperature"), 27, 32) + gameStrings_cf2740[f134] + " (" + intToString(f138) + ")" + (f13c ? " +ITN\n" : "\n");
	*tmp += padRight_4080d0(string("Movement"), 27, 32) + gameStrings_d2e148[f140] + " (" + (f144 != 0 ? intToString(f144) : string("Siege")) + ")";
	if (f14c != 0)
	{
		*tmp += " Ox" + intToString(f14c);
	}
	if (f148 != 0)
	{
		*tmp += " +NEM " + intToString(f148);
	}
	*tmp += "\n";
	*tmp += padRight_4080d0(string("Location"), 27, 32) + f150.getName() + "\n";
	*tmp += "\n";
	*tmp += " Parts \n";
	*tmp += "-------\n";
	int w = 1;
	for (int i_2b48 = 0; i_2b48 < 4; i_2b48++)
	{
		for (unsigned int i_2b4c = 0; i_2b4c < f188[i_2b48].size(); i_2b4c++)
	{
		if (f188[i_2b48][i_2b4c] > w)
	{
		w = f188[i_2b48][i_2b4c];
	}
	}
	}
	for (unsigned int i_2b50 = 0; i_2b50 < f1b0.size(); i_2b50++)
	{
		if (f1c0[i_2b50] > w)
	{
		w = f1c0[i_2b50];
	}
	}
	w = w + 2;
	for (int i_2b54 = 0; i_2b54 < 4; i_2b54++)
	{
		line = ">";
		padRight_4080d0(line, w + 1, 32);
		*tmp += line;
		if (f168[i_2b54] != 0)
	{
		line = "--- " + gameStrings_d38dd0[i_2b54] + " (" + intToString(f158[i_2b54] - f168[i_2b54]) + "+" + intToString(f168[i_2b54]) + ") ";
	}
	else
	{
		line = "--- " + gameStrings_d38dd0[i_2b54] + " (" + intToString(f158[i_2b54]) + ") ";
	}
		padRight_4080d0(line, 22, 45);
		*tmp += line + "\n";
		if (f178[i_2b54].empty())
	{
		line.assign(w + 4, 32);
		*tmp += line + " (None)\n";
	}
	else
	{
		for (unsigned int i_2b58 = 0; i_2b58 < f178[i_2b54].size(); i_2b58++)
	{
		line.assign(w - f188[i_2b54][i_2b58], 32);
		if (line.size() == w)
	{
		line += " ";
	}
		*tmp += line + f178[i_2b54][i_2b58];
		if (f198[i_2b54][i_2b58] != 0)
	{
		*tmp += " (";
		for (int i_2b5c = 0; i_2b5c < f198[i_2b54][i_2b58]; i_2b5c++)
	{
		*tmp += "+";
	}
		*tmp += ")";
	}
		*tmp += "\n";
	}
	}
	}
	line = ">";
	padRight_4080d0(line, w + 1, 32);
	*tmp += line;
	line = "--- INVENTORY (" + intToString(f1ac) + ") ";
	padRight_4080d0(line, 22, 45);
	*tmp += line + "\n";
	if (f1b0.empty())
	{
		line.assign(w + 4, 32);
		*tmp += line + " (None)\n";
	}
	else
	{
		for (unsigned int i_2b60 = 0; i_2b60 < f1b0.size(); i_2b60++)
	{
		line.assign(w - f1c0[i_2b60], 32);
		if (line.size() == w)
	{
		line += " ";
	}
		*tmp += line + f1b0[i_2b60] + "\n";
	}
	}
	*tmp += "\n";
	*tmp += " Peak State \n";
	*tmp += "------------\n";
	if (f1dc == 0)
	{
		*tmp += "None\n";
	}
	else
	{
		int n_2b64 = 1;
		for (int i_2b68 = 0; i_2b68 < 4; i_2b68++)
	{
		for (unsigned int i_2b6c = 0; i_2b6c < f1f0[i_2b68].size(); i_2b6c++)
	{
		if (f1f0[i_2b68][i_2b6c] > n_2b64)
	{
		n_2b64 = f1f0[i_2b68][i_2b6c];
	}
	}
	}
		for (unsigned int i_2b70 = 0; i_2b70 < f210.size(); i_2b70++)
	{
		if (f220[i_2b70] > n_2b64)
	{
		n_2b64 = f220[i_2b70];
	}
	}
		n_2b64 = n_2b64 + 2;
		for (int i_2b74 = 0; i_2b74 < 4; i_2b74++)
	{
		line = ">";
		padRight_4080d0(line, n_2b64 + 1, 32);
		*tmp += line;
		line = "--- " + gameStrings_d38dd0[i_2b74] + " ";
		padRight_4080d0(line, 22, 45);
		*tmp += line + "\n";
		if (f1e0[i_2b74].empty())
	{
		line.assign(n_2b64 + 4, 32);
		*tmp += line + " (None)\n";
	}
	else
	{
		for (unsigned int i_2b78 = 0; i_2b78 < f1e0[i_2b74].size(); i_2b78++)
	{
		line.assign(n_2b64 - f1f0[i_2b74][i_2b78], 32);
		if (line.size() == n_2b64)
	{
		line += " ";
	}
		*tmp += line + f1e0[i_2b74][i_2b78] + "\n";
	}
	}
	}
		line = ">";
		padRight_4080d0(line, n_2b64 + 1, 32);
		*tmp += line;
		line = "--- INVENTORY ";
		padRight_4080d0(line, 22, 45);
		*tmp += line + "\n";
		if (f210.empty())
	{
		line.assign(n_2b64 + 4, 32);
		*tmp += line + " (None)\n";
	}
	else
	{
		for (unsigned int i_2b7c = 0; i_2b7c < f210.size(); i_2b7c++)
	{
		line.assign(n_2b64 - f220[i_2b7c], 32);
		if (line.size() == n_2b64)
	{
		line += " ";
	}
		*tmp += line + f210[i_2b7c] + "\n";
	}
	}
		*tmp += "[Rating: " + intToString(f1dc) + "]\n";
	}
	*tmp += "\n";
	*tmp += " Favorites \n";
	*tmp += "-----------\n";
	for (int i_2b80 = 0; i_2b80 < 4; i_2b80++)
	{
		line = gameStrings_d378d0[i_2b80];
		padRight_4080d0(line, 27, 32);
		if (f234[i_2b80].empty())
	{
		*tmp += line + "None\n";
	}
	else
	{
		*tmp += line + f234[i_2b80] + "\n";
		for (int i_2b84 = 0; i_2b84 < 31; i_2b84++)
	{
		if (!f244[i_2b84].empty() && g_ba0028[i_2b84] == i_2b80)
	{
		line = "  " + gameStrings_d293c0[i_2b84];
		padRight_4080d0(line, 27, 32);
		*tmp += line + f244[i_2b84] + "\n";
	}
	}
	}
	}
	*tmp += "\n";
	c32_writeStatBlock_473d20(tmp, "Build", 107, 209, 0);
	*tmp += " Class Distribution \n";
	*tmp += "--------------------\n";
	if (f254.empty())
	{
		*tmp += "None\n";
	}
	else
	{
		int v2b88 = intToString(OpT8b_Fn9d4340(f264)).size();
		for (unsigned int i_2b8c = 0; i_2b8c < f254.size(); i_2b8c++)
	{
		*tmp += " " + padLeft_408090(intToString(f264[i_2b8c]), v2b88, 32) + "% | " + f254[i_2b8c] + "\n";
	}
	}
	*tmp += "\n";
	*tmp += " Dominant Class \n";
	*tmp += "----------------\n";
	int width = 0;
	for (unsigned int i_2b90 = 0; i_2b90 < f274.size(); i_2b90++)
	{
		if (f274[i_2b90].size() > width)
	{
		width = f274[i_2b90].size();
	}
	}
	if (width == 0)
	{
		*tmp += "None\n";
	}
	else
	{
		for (unsigned int i_2b94 = 0; i_2b94 < f274.size(); i_2b94++)
	{
		if (!f274[i_2b94].empty())
	{
		*tmp += " " + padLeft_408090(string(f274[i_2b94]), width, 32) + " | " + g_d1e88c[i_2b94].get23c()->getText() + "\n";
	}
	}
	}
	*tmp += "\n";
	c32_writeStatBlock_473d20(tmp, "Resources", 210, 222, 0);
	c32_writeStatBlock_473d20(tmp, "Kills", 223, 356, 1);
	for (unsigned int i_2b98 = 0; i_2b98 < f298.size(); i_2b98++)
	{
		*tmp += "  " + f298[i_2b98] + " (" + g_d1e88c[f2a8[i_2b98]].get23c()->getText() + ")\n";
	}
	*tmp += "\n";
	c32_writeStatBlock_473d20(tmp, "Combat", 357, 523, 0);
	c32_writeStatBlock_473d20(tmp, "Alert", 524, 575, 0);
	c32_writeStatBlock_473d20(tmp, "Stealth", 576, 584, 0);
	c32_writeStatBlock_473d20(tmp, "Traps", 585, 601, 0);
	c32_writeStatBlock_473d20(tmp, "Machines", 602, 612, 0);
	c32_writeStatBlock_473d20(tmp, "Hacking", 613, 783, 0);
	c32_writeStatBlock_473d20(tmp, "Bothacking", 784, 892, 0);
	c32_writeStatBlock_473d20(tmp, "Allies", 893, 955, 0);
	c32_writeStatBlock_473d20(tmp, "Intel", 956, 1005, 0);
	c32_writeStatBlock_473d20(tmp, "Exploration", 1006, 1041, 0);
	c32_writeStatBlock_473d20(tmp, "Actions", 1042, 1060, 0);
	*tmp += " Route \n";
	*tmp += "-------\n";
	for (unsigned int i_2b9c = 0; i_2b9c < f2d8.size(); i_2b9c++)
	{
		*tmp += f2d8[i_2b9c] + "\n";
	}
	*tmp += "\n";
	*tmp += " History \n";
	*tmp += "---------\n";
	if (f2f8.empty())
	{
		*tmp += "None\n";
	}
	else
	{
		int x = string("Turn").size();
		int y = string("Location").size();
		for (unsigned int i_2ba8 = 0; i_2ba8 < f2f8.size(); i_2ba8++)
	{
		if (x < intToString(f2f8[i_2ba8]).size())
	{
		x = intToString(f2f8[i_2ba8]).size();
	}
		if (f308[i_2ba8] != -1 && g_d1e88c[f308[i_2ba8]].get23c()->getText().size() > y)
	{
		y = g_d1e88c[f308[i_2ba8]].get23c()->getText().size();
	}
	}
		x = x + 1;
		y = y + 1;
		*tmp += padLeft_408090(string("Turn"), x, 32) + " | " + padRight_4080d0(string("Location"), y, 32) + "| Event\n";
		for (unsigned int i_2bac = 0; i_2bac < f2f8.size(); i_2bac++)
	{
		*tmp += padLeft_408090(intToString(f2f8[i_2bac]), x, 32) + " | " + padRight_4080d0((f308[i_2bac] != -1 ? g_d1e88c[f308[i_2bac]].get23c()->getText() : string(g_d21b9c)), y, 32) + "| " + f318[i_2bac] + "\n";
	}
	}
	*tmp += "\n";
	*tmp += " Last Messages \n";
	*tmp += "---------------\n";
	for (unsigned int i_2bb0 = 0; i_2bb0 < f328.size(); i_2bb0++)
	{
		*tmp += f328[i_2bb0] + "\n";
	}
	*tmp += "\n";
	*tmp += " Map \n";
	*tmp += "-----\n";
	*tmp += "+";
	for (int n_2bb4 = f1d0.getWidth() + 2; n_2bb4 > 0; n_2bb4--)
	{
		*tmp += "-";
	}
	*tmp += "+\n";
	for (int i_2bb8 = 0; i_2bb8 < f1d0.getHeight(); i_2bb8++)
	{
		*tmp += "| ";
		for (int i_2bbc = 0; i_2bbc < f1d0.getWidth(); i_2bbc++)
	{
		*tmp += *(f1d0.at(i_2bbc, i_2bb8));
	}
		*tmp += " |\n";
	}
	*tmp += "+";
	for (int n_2bc0 = f1d0.getWidth() + 2; n_2bc0 > 0; n_2bc0--)
	{
		*tmp += "-";
	}
	*tmp += "+\n";
	*tmp += "\n";
	c32_writeStatBlock_473d20(tmp, "Best States", 1121, 1184, 0);
	*tmp += " Item Schematics \n";
	*tmp += "-----------------\n";
	if (f338.empty())
	{
		*tmp += "None\n";
	}
	else
	{
		int n_2bc8 = 0;
		int n_2bc4 = 0;
		for (unsigned int i_2bcc = 0; i_2bcc < f338.size(); i_2bcc++)
	{
		if (f338[i_2bcc].size() > n_2bc8)
	{
		n_2bc8 = f338[i_2bcc].size();
	}
		if (n_2bc4 < g_d1e88c[f348[i_2bcc]].get23c()->getText().size())
	{
		n_2bc4 = g_d1e88c[f348[i_2bcc]].get23c()->getText().size();
	}
	}
		n_2bc8 = n_2bc8 + 1;
		n_2bc4 = n_2bc4 + 1;
		for (unsigned int i_2bd0 = 0; i_2bd0 < f338.size(); i_2bd0++)
	{
		*tmp += padLeft_408090(string(f338[i_2bd0]), n_2bc8, 32) + " | " + padRight_4080d0(g_d1e88c[f348[i_2bd0]].get23c()->getText(), n_2bc4, 32) + "| " + gameStrings_d01c50[f358[i_2bd0]] + "\n";
	}
	}
	*tmp += "\n";
	*tmp += " Robot Schematics \n";
	*tmp += "------------------\n";
	if (f368.empty())
	{
		*tmp += "None\n";
	}
	else
	{
		int n_2bd8 = 0;
		int n_2bd4 = 0;
		for (unsigned int i_2bdc = 0; i_2bdc < f368.size(); i_2bdc++)
	{
		if (f368[i_2bdc].size() > n_2bd8)
	{
		n_2bd8 = f368[i_2bdc].size();
	}
		if (n_2bd4 < g_d1e88c[f378[i_2bdc]].get23c()->getText().size())
	{
		n_2bd4 = g_d1e88c[f378[i_2bdc]].get23c()->getText().size();
	}
	}
		n_2bd8 = n_2bd8 + 1;
		n_2bd4 = n_2bd4 + 1;
		for (unsigned int i_2be0 = 0; i_2be0 < f368.size(); i_2be0++)
	{
		*tmp += padLeft_408090(string(f368[i_2be0]), n_2bd8, 32) + " | " + padRight_4080d0(g_d1e88c[f378[i_2be0]].get23c()->getText(), n_2bd4, 32) + "| " + gameStrings_d01c50[f388[i_2be0]] + "\n";
	}
	}
	*tmp += "\n";
	*tmp += " Fabricated \n";
	*tmp += "------------\n";
	if (f398.empty())
	{
		*tmp += "Nothing\n";
	}
	else
	{
		int x = 0;
		int n = 0;
		int y = 0;
		for (unsigned int i_2bf0 = 0; i_2bf0 < f398.size(); i_2bf0++)
	{
		if (f398[i_2bf0].size() > x)
	{
		x = f398[i_2bf0].size();
	}
		if (n < intToString(f3a8[i_2bf0]).size())
	{
		n = intToString(f3a8[i_2bf0]).size();
	}
		if (y < g_d1e88c[f3b8[i_2bf0]].get23c()->getText().size())
	{
		y = g_d1e88c[f3b8[i_2bf0]].get23c()->getText().size();
	}
	}
		x = x + 1;
		n = n + 1;
		y = y + 1;
		for (unsigned int i_2bf4 = 0; i_2bf4 < f398.size(); i_2bf4++)
	{
		*tmp += padLeft_408090(string(f398[i_2bf4]), x, 32) + " | x" + padRight_4080d0(intToString(f3a8[i_2bf4]), n, 32) + "| " + padRight_4080d0(g_d1e88c[f3b8[i_2bf4]].get23c()->getText(), y, 32);
		line.clear();
		if (f3c8[i_2bf4] != 0)
	{
		line += "| Preloaded";
	}
		if (f3d8[i_2bf4] != 0)
	{
		line += (line.empty() ? "| Authchip" : ", Authchip");
	}
		if (!line.empty())
	{
		*tmp += line;
	}
		*tmp += "\n";
	}
	}
	*tmp += "\n";
	*tmp += " Repaired \n";
	*tmp += "----------\n";
	if (f3e8.empty())
	{
		*tmp += "Nothing\n";
	}
	else
	{
		int n_2c00 = 0;
		int n_2bf8 = 0;
		int n_2bfc = 0;
		for (unsigned int i_2c04 = 0; i_2c04 < f3e8.size(); i_2c04++)
	{
		if (f3e8[i_2c04].size() > n_2c00)
	{
		n_2c00 = f3e8[i_2c04].size();
	}
		if (n_2bf8 < intToString(f3f8[i_2c04]).size() + 1)
	{
		n_2bf8 = intToString(f3f8[i_2c04]).size() + 1;
	}
		if (n_2bfc < g_d1e88c[f408[i_2c04]].get23c()->getText().size())
	{
		n_2bfc = g_d1e88c[f408[i_2c04]].get23c()->getText().size();
	}
	}
		n_2c00 = n_2c00 + 1;
		n_2bf8 = n_2bf8 + 1;
		n_2bfc = n_2bfc + 1;
		for (unsigned int i_2c08 = 0; i_2c08 < f3e8.size(); i_2c08++)
	{
		*tmp += padLeft_408090(string(f3e8[i_2c08]), n_2c00, 32) + " | " + padRight_4080d0(intToString(f3f8[i_2c08]) + "%", n_2bf8, 32) + "| " + padRight_4080d0(g_d1e88c[f408[i_2c08]].get23c()->getText(), n_2bfc, 32);
		line.clear();
		if (f418[i_2c08] != 0)
	{
		line += "| Broken";
	}
		if (f428[i_2c08] != 0)
	{
		line += (line.empty() ? "| Corrupted" : ", Corrupted");
	}
		if (!line.empty())
	{
		*tmp += line;
	}
		*tmp += "\n";
	}
	}
	*tmp += "\n";
	*tmp += " Studied \n";
	*tmp += "---------\n";
	if (f438.empty())
	{
		*tmp += "None\n";
	}
	else
	{
		int n_2c10 = 0;
		int n_2c0c = 0;
		for (unsigned int i_2c14 = 0; i_2c14 < f438.size(); i_2c14++)
	{
		if (f438[i_2c14].size() > n_2c10)
	{
		n_2c10 = f438[i_2c14].size();
	}
		if (n_2c0c < g_d1e88c[f448[i_2c14]].get23c()->getText().size())
	{
		n_2c0c = g_d1e88c[f448[i_2c14]].get23c()->getText().size();
	}
	}
		n_2c10 = n_2c10 + 1;
		n_2c0c = n_2c0c + 1;
		for (unsigned int i_2c18 = 0; i_2c18 < f438.size(); i_2c18++)
	{
		*tmp += padLeft_408090(string(f438[i_2c18]), n_2c10, 32) + " | " + padRight_4080d0(g_d1e88c[f448[i_2c18]].get23c()->getText(), n_2c0c, 32) + "| " + gameStrings_d1d470[f458[i_2c18]] + "\n";
	}
	}
	*tmp += "\n";
	*tmp += " Alien Tech Used \n";
	*tmp += "-----------------\n";
	if (f478.empty())
	{
		*tmp += "None\n";
	}
	else
	{
		for (unsigned int i_2c1c = 0; i_2c1c < f478.size(); i_2c1c++)
	{
		*tmp += f478[i_2c1c] + "\n";
	}
	}
	*tmp += "\n";
	*tmp += " Achievements \n";
	*tmp += "--------------\n";
	if (f488.empty())
	{
		*tmp += "None\n";
	}
	else
	{
		for (unsigned int i_2c20 = 0; i_2c20 < f488.size(); i_2c20++)
	{
		*tmp += f488[i_2c20] + "\n";
	}
	}
	*tmp += "\n";
	*tmp += " Challenges \n";
	*tmp += "------------\n";
	if (f498.empty())
	{
		*tmp += "None\n";
	}
	else
	{
		for (unsigned int i_2c24 = 0; i_2c24 < f498.size(); i_2c24++)
	{
		*tmp += f498[i_2c24] + "\n";
	}
	}
	*tmp += "\n";
	if (g_cf462c == 2)
	{
		string title(" Cogshop Purchases");
		if (!f4a8.empty())
	{
		title += " (" + intToString(f4a8.size()) + ")";
	}
		title += "\n";
		*tmp += title;
		*tmp += string(title.size(), 45) + "\n";
		if (f4a8.empty())
	{
		*tmp += "None\n";
	}
	else
	{
		for (unsigned int i_2c44 = 0; i_2c44 < f4a8.size(); i_2c44++)
	{
		*tmp += f4a8[i_2c44] + " (" + (f4b8[i_2c44] > 0 ? intToString(f4b8[i_2c44]) : string("Loot Box")) + ")\n";
	}
	}
		*tmp += "\n";
	}
	if (g_cf462c == 5)
	{
		c32_writeStatBlock_473d20(tmp, "RPGLIKE", 1061, 1093, 0);
	}
	else
	{
		if (g_cf462c == 7)
	{
		c32_writeStatBlock_473d20(tmp, "Player 2", 1094, 1108, 0);
	}
	else
	{
		if (g_cf462c == 11)
	{
		c32_writeStatBlock_473d20(tmp, "Polymind", 1109, 1120, !f4c8.empty());
		if (!f4c8.empty())
	{
		*tmp += "Top 5 Hosts by Kills:\n";
		for (unsigned int i_2c48 = 0; i_2c48 < f4c8.size(); i_2c48++)
	{
		*tmp += "  " + f4c8[i_2c48] + " (" + g_d1e88c[f4d8[i_2c48]].get23c()->getText() + ": " + intToString(f4e8[i_2c48]) + ")\n";
	}
		*tmp += "\n";
	}
	}
	}
	}
	*tmp += " Game \n";
	*tmp += "------\n";
	*tmp += padRight_4080d0(string("Seed"), 18, 32) + f4f8 + "\n";
	*tmp += padRight_4080d0(string("  Manual?"), 18, 32) + intToString(f514 != 0) + "\n";
	*tmp += padRight_4080d0(string("Play Time"), 18, 32) + padLeft_408090(intToString(f518 / 3600), 2, 48) + ":" + padLeft_408090(intToString((f518 / 60) % 60), 2, 48) + ":" + padLeft_408090(intToString(f518 % 60), 2, 48) + "\n";
	*tmp += padRight_4080d0(string("  Cumulative"), 18, 32) + floatToString(f51c / 60.0, 1, 1) + " hours\n";
	*tmp += padRight_4080d0(string("  Start"), 18, 32) + OpC_formatDateTime_4716f0(f520, f53c) + "\n";
	*tmp += padRight_4080d0(string("  End"), 18, 32) + OpC_formatDateTime_4716f0(f90, fac) + "\n";
	*tmp += padRight_4080d0(string("Sessions"), 18, 32) + intToString(f558) + "\n";
	*tmp += padRight_4080d0(string("Manual Loads"), 18, 32) + intToString(f55c) + "\n";
	*tmp += padRight_4080d0(string("Difficulty"), 18, 32) + f560 + "\n";
	*tmp += padRight_4080d0(string("Special Mode"), 18, 32) + (f74.empty() ? string("None") : string(f74)) + "\n";
	*tmp += padRight_4080d0(string("Game No."), 18, 32) + intToString(f57c) + "\n";
	*tmp += padRight_4080d0(string("  Rogue"), 18, 32) + intToString(f580) + "\n";
	*tmp += padRight_4080d0(string("  Adventurer"), 18, 32) + intToString(f584) + "\n";
	*tmp += padRight_4080d0(string("  Explorer"), 18, 32) + intToString(f588) + "\n";
	*tmp += padRight_4080d0(string("Win Type"), 18, 32) + (f58c == -1 ? string("-") : intToString(f58c)) + "\n";
	*tmp += padRight_4080d0(string("  Total"), 18, 32) + intToString(f590) + "\n";
	*tmp += padRight_4080d0(string("  Types"), 18, 32);
	for (unsigned int i_2c4c = 0; i_2c4c < f594.size(); i_2c4c++)
	{
		if (i_2c4c != 0)
	{
		*tmp += "/";
	}
		*tmp += intToString(f594[i_2c4c]);
	}
	*tmp += "\n";
	*tmp += padRight_4080d0(string("Lore%"), 18, 32) + intToString(f5a4) + "\n";
	*tmp += padRight_4080d0(string("Gallery%"), 18, 32) + intToString(f5a8) + "\n";
	*tmp += padRight_4080d0(string("Achievement%"), 18, 32) + intToString(f5ac) + "\n";
	*tmp += padRight_4080d0(string("Wizard Run"), 18, 32) + intToString(f5b0 != 0) + "\n";
	*tmp += "\n";
	*tmp += " Options \n";
	*tmp += "---------\n";
	*tmp += padRight_4080d0(string("Layout"), 18, 32) + intToString(f5b4) + "\n";
	*tmp += padRight_4080d0(string("ASCII"), 18, 32) + intToString(f5b8 != 0) + "\n";
	*tmp += padRight_4080d0(string("Keyboard"), 18, 32) + intToString(f5b9 != 0) + "\n";
	*tmp += padRight_4080d0(string("Movement"), 18, 32) + gameStrings_cf10d8[f5bc] + "\n";
	*tmp += padRight_4080d0(string("Keybinds"), 18, 32) + intToString(f5c0 != 0) + "\n";
	*tmp += padRight_4080d0(string("Fullscreen"), 18, 32) + intToString(f5c4) + "\n";
	*tmp += padRight_4080d0(string("Font"), 18, 32) + f5c8 + "\n";
	*tmp += padRight_4080d0(string("Map View"), 18, 32) + intToString(f5e4) + "x" + intToString(f5e8) + "\n";
	*tmp += padRight_4080d0(string("Zoom Use"), 18, 32) + intToString(f5ec) + "%\n";
	*tmp += padRight_4080d0(string("Tactical HUD"), 18, 32) + intToString(f5f0 != 0) + "\n";
	*tmp += padRight_4080d0(string("Map Filters"), 18, 32) + f5f4 + "\n";
	*tmp += padRight_4080d0(string("Filters"), 18, 32) + f610 + "\n";
	*tmp += padRight_4080d0(string("Steam"), 18, 32) + (f62c == 3 ? string("SD") : (f62c == 2 ? string("X") : intToString(f62c))) + "\n";
	*tmp += "\n";
	*tmp += "\n";
	*tmp += "RUN: " + f630 + "\n";
	string msg((isDump ? g_cfd42c + "dumps" : g_cfd42c + "scores"));
	c32_makeDirectory_409240(msg);
	msg += "/";
	string label;
	label += fc8 + "-" + f90 + "-" + fac + "-" + intToString(run34.f34) + "-" + intToString(f110);
	if (f58c != -1)
	{
		label += "_w" + intToString(g_cf4b38);
	}
	if (run34.f38)
	{
		label += "+";
	}
	if (run34.f39)
	{
		label += "+";
	}
	if (run34.f3a)
	{
		label += "+";
	}
	label += ".txt";
	msg += label;
	ofstream log(msg.c_str());
	if (log.is_open())
	{
		log << *tmp;
		log.close();
	}
	else
	{
		logError("Scorekeeper::totalScore()", "Unable to open file to store score record: " + msg);
	}
	if (!isDump)
	{
		totalScore_47f2e0();
	}
	OpC_Owner4718c0 * pick = new OpC_Owner4718c0(1);
	pick->object = new Protobuf::PostScoresheetRequest();
	Protobuf::Scoresheet * s = pick->object->mutable_scoresheet();
	createProtobuf(s, label, isDump);
	bool visible = !isDump;
	if (visible)
	{
		if (g_cf45d8.getField())
	{
		f690 = 2;
	}
	else
	{
		if (!g_d28d04)
	{
		f690 = 3;
	}
	else
	{
		if (g_d28ccc == g_d2f184)
	{
		f690 = 4;
	}
	else
	{
		if (g_cf4614 != 0)
	{
		f690 = 5;
	}
	else
	{
		if (OpU8a_containsString(&g_d25780, f630))
	{
		f690 = 6;
	}
	}
	}
	}
	}
		if (f690 == 0)
	{
		string run = opR1d_436e70(1, 0, 0);
		if (run != g_d25760)
	{
		g_d25760 = run;
		g_d2577c = 1;
	}
	else
	{
		if (g_d2577c == 30)
	{
		f690 = 7;
	}
	else
	{
		g_d2577c = g_d2577c + 1;
	}
	}
	}
		if (f690 != 0)
	{
		visible = 0;
	}
	}
	if (visible)
	{
		pick->object->set_name(*tmp);
		g_cefb58 = 0;
		if (!(opY2_startNetworkThread(3, 0, &lc43_upload4884c0, pick)))
	{
		delete pick;
	}
		if (g_cf68a8 != 0)
	{
		if (g_d1e888.get23c()->f8 < 8)
	{
		if (f74.empty())
	{
		if (f498.empty())
	{
		OpS1e_Lists * lists = new OpS1e_Lists(*g_cf68a8);
		lists->f40 = f68c;
		lists->f44 = fc8;
		lists->f60 = f110;
		if (!(opY2_startNetworkThread(4, 0, &c44_uploadRunData_48a3f0, lists)))
	{
		delete lists;
	}
	}
	}
	}
	}
		if (g_d25450)
	{
		if (!g_d25480.empty())
	{
		if (g_d25480.size() == g_d254a0.size())
	{
		if (g_d1e888.get23c()->f8 < 8)
	{
		if (f74.empty())
	{
		if (f498.empty() && g_d25740 >= 30)
	{
		OpR1h_Small * small = new OpR1h_Small();
		small->f0 = f68c;
		small->f4 = fc8;
		small->f20 = f110;
		small->f24 = g_d25480;
		small->f34 = g_d25490;
		small->f44 = g_d254a0;
		small->f54 = g_d254b0;
		if (!(opY2_startNetworkThread(5, 0, &opC_uploadRunData_48ae20, small)))
	{
		delete small;
	}
	}
	}
	}
	}
	}
	}
	}
	else
	{
		delete pick;
		delete tmp;
	}
	tmp = 0;
	for (int i = 525, j = 0; i <= 532; i++, j++)
		(*f0)[i] = f2b8[j];
	for (unsigned int k = 0; k < f4.size(); k++)
	{
		for (int i = 525, j = 0; i <= 532; i++, j++)
			(*f4[k])[i] = f2c8[k][j];
	}
	(*f0)[206] = f284;
	for (unsigned int k = 0; k < f4.size(); k++)
		(*f4[k])[206] = f288[k];
	string tail(msg);
	tail.erase(tail.begin() + tail.rfind('.'),tail.end());
	g_cf1080.render(tail,string() + "_log");
	if (g_d28eb0)
		g_d2f75c.render(tail,string() + "_combat");
	return msg;
}
