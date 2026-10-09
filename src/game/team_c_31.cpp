// team_c_31: CGallery export (0x7da370, CGallery vtable slot 5): writes the known-item gallery to
// user/gallery_export_*.txt/.html/.csv
// NOTE: class/member names are placeholders; the method is declared non-virtual on a private class
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string intToString(int value);
string tc31_OpY1_intToStringSigned(int value);	// 0x405560 (showpos formatting)
string opR1d_436e70(int unknown1, int unknown2, int unknown3);	// NOTE: placeholder name
bool OpS8b_Fn9d43b0(int *list, unsigned int count, int value);	// NOTE: placeholder name
void unknown7d9df0(ostream &out, const string &name, float value, int unknown1, int unknown2, string text);	// c125.cpp
void unknown7d9f10(ostream &out, const string &name, const string &text);
void unknown7d9f90(ostream &out, const string &text, int span);
void unknown7d9fe0(ostream &out, const string &text);
void unknown7da020(ostream &out, const string &text);
void unknown7da060(ostream &out, int value, string text1, string text2);
void unknown7da120(ostream &out, float value, int unknown1, int unknown2, string text);
void unknown7da210(ostream &out, int value);
void OpU5_writeNameIntLine(ostream &out, const string &name, int value, string text1, string text2);	// op_u5_s6.cpp
void OpU5_writeQuotedFloat(ostream &out, float value, int unknown1, int unknown2);
void OpU5_writeLabelLine(ostream &out, const string &text);

extern string gameString_cfd42c;	// global_strings.cpp
extern string gameStrings_cf6648[], gameStrings_d01b48[], gameStrings_d035d8[], gameStrings_d1e058[], gameStrings_d22280[], gameStrings_d25e10[], gameStrings_d293c0[], gameStrings_d29980[], gameStrings_d2ec50[], gameStrings_d31b68[], gameStrings_d378d0[];	// global_string_arrays.cpp
struct C31_Pair { string a; string b; };	// NOTE: placeholder (the 2704-string table read as 1352 pairs)
#define C31_PAIRS ((C31_Pair *)gameStrings_d035d8)

struct C31_Range { int lo; int hi; bool empty() const; };	// NOTE: placeholder (empty folded with vector<int>::empty)
struct C31_Point { string rangeToString_40c2b0(string separator); };	// NOTE: placeholder (Point::rangeToString_40c2b0)
struct C31_Sub	// NOTE: placeholder layout (OpS2_Sub)
{
	char pad0[0x2c];
	int f2c, f30, f34, f38, f3c, f40;
	C31_Point f44;
	char pad48[0x58 - 0x48];
	int f58, f5c, f60, f64;
};
struct C31_Part	// NOTE: placeholder layout (OpS2_Target)
{
	int f0;
	char pad4[0x24 - 0x4];
	string f24;
	char pad40[0x44 - 0x40];
	int f44, f48, f4c, f50, f54;
	char pad58[0x94 - 0x58];
	int f94;
	char pad98[0xa4 - 0x98];
	int fa4, fa8, fac, fb0;
	float fb4;
	int fb8, fbc, fc0, fc4, fc8, fcc, fd0, fd4;
	float fd8;
	int fdc, fe0, fe4, fe8, fec, ff0, ff4, ff8, ffc, f100, f104, f108, f10c, f110, f114, f118, f11c;
	C31_Range f120;
	int f128, f12c, f130, f134, f138;
	char pad13c[0x14c - 0x13c];
	int f14c, f150, f154, f158, f15c;
	char pad160[0x164 - 0x160];
	bool f164;
	char pad165[0x1a0 - 0x165];
	C31_Sub *f1a0;
	char pad1a4[0x1a8 - 0x1a4];
	C31_Sub *f1a8;
	char pad1ac[0x204 - 0x1ac];
	int f204;
	bool f208;
	char pad209[0x288 - 0x209];
	string f288;

	bool unknown56f3f0();	// NOTE: placeholder names (folded with OpR2c_Entity/OpR2c_Item methods)
	int unknown56fda0() throw();
	string unknown56fde0();
	bool unknown56f460();
	string describe();	// OpS2_Target::describe
	string namesJoined();	// OpS2_Target::namesJoined
	string getSuffix();	// NOTE: folded with OpR1e_Unit::getSuffix
	string idList();	// NOTE: folded with OpS2_Ids::idList
};
extern vector<C31_Part *> g_d2d1c4;	// NOTE: placeholder name
extern vector<int> g_d25790;	// NOTE: placeholder name
extern int g_b96178[], g_b9654c[];	// NOTE: placeholder names
extern int c31_exportKeys_bcabc4[];	// NOTE: placeholder name ('T','H','C')
struct C31_Player { string getName(); };	// NOTE: placeholder (OpW7_Player::getName)
extern C31_Player g_d28c68;	// NOTE: placeholder name
struct C31_Meta { int getGalleryCollectionPercent(); };	// NOTE: placeholder (GameMetaData)
extern C31_Meta g_d25628;	// NOTE: placeholder name
struct C31_UI { void message(const string &text); };	// NOTE: placeholder (Calls_4977a0::delegate)
extern C31_UI *c31_ui_cec040;	// NOTE: placeholder name
struct C31_Button { void hoverBegin(); };	// NOTE: placeholder (Unknown_c34d38::hoverBegin)
struct C31_Tabs { char pad[0x6c]; vector<C31_Button *> f6c; };	// NOTE: placeholder layout
struct C31_Event { int type; int x; int y; C31_Event(int type); };	// NOTE: placeholder (ctor Calls_415c60::delegate)
struct C31_Page { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void onEvent(const C31_Event &e); };	// NOTE: placeholder

class C31_Gallery	// NOTE: placeholder layout (CGallery)
{
public:
	char pad0[0xa4];
	vector<C31_Page *> fa4;
	char padb4[0xbc - 0xb4];
	C31_Tabs *fbc;

	bool unknown7e8920(int key);	// CGallery::unknown7e8920
	void exportKnown(int key, int mode);
};
extern const char empty_b95d3b[];	// NOTE: placeholder name ("" literal pooled in the exe)
extern const char empty_b95ebf[];	// NOTE: placeholder name ("" literal pooled in the exe)
extern const char empty_b95f3b[];	// NOTE: placeholder name ("" literal pooled in the exe)
extern const char empty_b9600e[];	// NOTE: placeholder name ("" literal pooled in the exe)
extern const char empty_b9615f[];	// NOTE: placeholder name ("" literal pooled in the exe)
extern const char empty_b962b6[];	// NOTE: placeholder name ("" literal pooled in the exe)
extern const char empty_b9639b[];	// NOTE: placeholder name ("" literal pooled in the exe)
extern const char empty_b963bf[];	// NOTE: placeholder name ("" literal pooled in the exe)

void C31_Gallery::exportKnown(int key, int mode)
{
	switch (mode)
	{
	case 0:
		key -= 32;
		while (key <= 'Z')
		{
			if (unknown7e8920(key))
				break;
			key++;
		}
		break;
	case 1:
		if (OpS8b_Fn9d43b0(c31_exportKeys_bcabc4,3,key))
		{
			string path = gameString_cfd42c + "user/" + "gallery_export_" + opR1d_436e70(1,0,0);
			switch (key)
			{
			case 'T':
				path += ".txt";
				break;
			case 'H':
				path += ".html";
				break;
			case 'C':
				path += ".csv";
				break;
			}
			ofstream out(path.c_str(),ios::out | ios::trunc);
			if (out.is_open())
			{
				switch (key)
				{
				case 'T':
				{
					C31_Part *element;
					C31_Sub *first;
				out << g_d28c68.getName() << "'s Gallery Collection (" << opR1d_436e70(1, 0, 0) << ", " << intToString(g_d25628.getGalleryCollectionPercent()) << "%)" << "\n";
				out << "\n";
				vector<C31_Part *> parts;
				for (unsigned int i = 0; i < g_d2d1c4.size(); i++)
				{
					if (g_d2d1c4[i]->f48 != 5)
				{
					if (g_d25790[i] != 0)
				{
					parts.push_back(g_d2d1c4[i]);
				}
				}
				}
				for (unsigned int i = 0; i < g_d2d1c4.size(); i++)
				{
					if (g_d2d1c4[i]->f48 == 5)
				{
					if (g_d25790[i] != 0)
				{
					parts.push_back(g_d2d1c4[i]);
				}
				}
				}
				string text;
				for (unsigned int i = 0; i < parts.size(); i++)
				{
					element = parts[i];
					out << "\n";
					out << " " << element->f24 << "\n";
					text.assign(element->f24.size() + 2, 45);
					out << text << " [x" << g_d25790[element->f0] << "]\n";
					unknown7d9f10(out, "Type", gameStrings_d293c0[element->f44]);
					unknown7d9f10(out, "Rating", intToString(element->f50) + (element->f94 != 0 ? "/" + gameStrings_d25e10[element->f94] : string("")));
					if (element->f4c > 1)
				{
					OpU5_writeNameIntLine(out, "Size", element->f4c, "", "");
				}
					OpU5_writeNameIntLine(out, "Mass", element->fa4, "", "");
					OpU5_writeNameIntLine(out, "Integrity", element->fa8, "", (element->unknown56f3f0() ? empty_b95d3b : "*"));
					OpU5_writeNameIntLine(out, "Coverage", element->fac * element->f4c, "", "");
					unknown7d9f10(out, "Special Trait", element->unknown56fde0());
					OpU5_writeNameIntLine(out, "Life", element->unknown56fda0(), "", "");
					unknown7d9df0(out, "Energy", element->fb4, 0, 1, "-");
					OpU5_writeNameIntLine(out, "Matter", element->fb8, "-", "");
					OpU5_writeNameIntLine(out, "Heat", element->fb0, "+", "");
					OpU5_writeNameIntLine(out, "Energy", element->fbc, "+", "");
					OpU5_writeNameIntLine(out, " Storage", element->fc0, "", "");
					unknown7d9f10(out, " Stability", (element->fc8 != 0 ? intToString(100 - element->fc8) + "%" : string("")));
					OpU5_writeNameIntLine(out, "Time/Move", element->fcc, "", "");
					OpU5_writeNameIntLine(out, " Mod/Extra", element->fd0, "", "");
					OpU5_writeNameIntLine(out, "Drag", element->fd4, "", "");
					unknown7d9df0(out, "Energy", element->fd8, 0, 1, "-");
					OpU5_writeNameIntLine(out, "Heat", element->fdc, "+", "");
					OpU5_writeNameIntLine(out, "Support", element->fe0, "", "");
					OpU5_writeNameIntLine(out, " Penalty", element->fe4, "", "");
					OpU5_writeNameIntLine(out, "Burnout", element->fe8, "", "%");
					unknown7d9f10(out, "Special", (element->fec != 0 ? string(gameStrings_d01b48[element->fec]) : string("")));
					OpU5_writeNameIntLine(out, "Range", element->f100, "", "");
					OpU5_writeNameIntLine(out, " Energy", element->f108, "-", "");
					OpU5_writeNameIntLine(out, " Matter", element->f10c, "-", "");
					OpU5_writeNameIntLine(out, " Heat", element->f110, "+", "");
					OpU5_writeNameIntLine(out, " Recoil", element->f14c, "", "");
					OpU5_writeNameIntLine(out, " Targeting", element->f130, "", "%");
					OpU5_writeNameIntLine(out, " Delay", element->f114, "", "");
					unknown7d9f10(out, " Stability", (element->f15c != 0 ? intToString(100 - element->f15c) + "%" : string("")));
					OpU5_writeNameIntLine(out, " Waypoints", element->f104, "", "");
					OpU5_writeNameIntLine(out, " Arc", element->f11c, "", "");
					OpU5_writeNameIntLine(out, " Wide", element->f164 != 0, "", "");
					OpU5_writeNameIntLine(out, "Projectiles", element->f118, "", "");
					unknown7d9f10(out, " Damage", (element->f120.hi == 0 ? string("") : (element->f120.empty() ? intToString(element->f120.hi) : intToString(element->f120.lo) + "-" + intToString(element->f120.hi))));
					unknown7d9f10(out, " Type", (element->f128 < 10 ? string(gameStrings_d29980[element->f128]) : string("")));
					unknown7d9f10(out, " Critical", (element->f138 != 0 ? intToString(element->f138) + "% " + gameStrings_d1e058[element->f134] : string("")));
					unknown7d9f10(out, " Penetration", element->idList());
					unknown7d9f10(out, " Heat Transfer", (element->f158 != 0 ? gameStrings_cf6648[element->f158] + " (" + intToString(g_b96178[element->f158]) + ")" : string("")));
					unknown7d9f10(out, " Spectrum", (element->f154 != 0 ? gameStrings_d31b68[element->f154] + " (" + intToString(g_b9654c[element->f154]) + ")" : string("")));
					OpU5_writeNameIntLine(out, " Disruption", element->f150, "", "");
					unknown7d9f10(out, " Salvage", (element->f12c != 0 ? tc31_OpY1_intToStringSigned(element->f12c) : string("")));
					if (element->f1a0 != 0)
				{
					first = element->f1a0;
					OpU5_writeNameIntLine(out, "Radius", first->f3c, "", "");
					OpU5_writeNameIntLine(out, " Arc", first->f40, "", "");
					unknown7d9f10(out, " Damage", (first->f34 != 0 ? intToString(first->f30 - first->f34) + "-" + intToString(first->f30 + first->f34) : intToString(first->f30)));
					OpU5_writeNameIntLine(out, " Falloff", first->f38, "", "");
					unknown7d9f10(out, " Chunks", first->f44.rangeToString_40c2b0("-"));
					unknown7d9f10(out, " Type", gameStrings_d29980[first->f2c]);
					unknown7d9f10(out, " Heat Transfer", (first->f64 != 0 ? gameStrings_cf6648[first->f64] + " (" + intToString(g_b96178[first->f64]) + ")" : string("")));
					unknown7d9f10(out, " Spectrum", (first->f60 != 0 ? gameStrings_d31b68[first->f60] + " (" + intToString(g_b9654c[first->f60]) + ")" : string("")));
					OpU5_writeNameIntLine(out, " Disruption", first->f5c, "", "");
					unknown7d9f10(out, " Salvage", (first->f58 != 0 ? tc31_OpY1_intToStringSigned(first->f58) : string("")));
				}
					string str = element->describe();
					if (element->f48 != 1)
				{
					if (!str.empty())
				{
					out << "Effect: " << str << "\n";
				}
				}
					if (element->f48 != 1)
				{
					if (element->f288.size() > 1)
				{
					out << "Description: " << element->f288 << "\n";
				}
				}
					if (element->f208)
				{
					OpU5_writeNameIntLine(out, "Fabrication", element->f204, "", "");
					unknown7d9f10(out, " Time", element->getSuffix());
					unknown7d9f10(out, " Components", element->namesJoined());
				}
				}
				fbc->f6c[0]->hoverBegin();
				break;
				}
				case 'H':
				{
					int kind;
					C31_Part *element;
					C31_Sub *first;
				out << "<html>\n";
				out << "<head>\n";
				out << "<STYLE type=\"text/css\">\n";
				out << "body { color: #00CC00; background-color: #000000; font-size: 100%; font-family: 'Courier New', Courier, monospace }\n";
				out << "a { color: #00A3D9; }\n";
				out << "a:visited { color: #C8C8C8 }\n";
				out << "table, th, td {\n";
				out << "  border: 1px solid #006200;\n";
				out << "  border-collapse: collapse;\n";
				out << "  text-align: left;\n";
				out << "  padding: 5px;\n";
				out << "  white-space: nowrap;\n";
				out << "  empty-cells: show;\n";
				out << "}\n";
				out << "th { color: #00f800; }\n";
				out << ".gallery-table td:nth-child(1) { color: #00f800; }\n";
				out << ".superheader {\n";
				out << "  border: 1px solid #00cc00;\n";
				out << "  color: #00ff00;\n";
				out << "  text-align: center;\n";
				out << "  background-color: #003300;\n";
				out << "}\n";
				out << "</head>\n";
				out << "</STYLE>\n";
				out << "<body>\n";
				out << "<a name=\"top\"></a>\n";
				out << g_d28c68.getName() << "'s Gallery Collection (" << opR1d_436e70(1, 0, 0) << ", " << intToString(g_d25628.getGalleryCollectionPercent()) << "%) <br>\n";
				out << "<ul>\n";
				out << "<li><a href=\"#Power\">Power</a></li>\n";
				out << "<li><a href=\"#Propulsion\">Propulsion</a></li>\n";
				out << "<li><a href=\"#Utilities\">Utilities</a></li>\n";
				out << "<li><a href=\"#Weapons\">Weapons</a></li>\n";
				out << "<li><a href=\"#Other\">Other</a></li>\n";
				out << "</ul>\n";
				out << "<br>\n";
				out << "<br>\n";
				vector<C31_Part *> parts;
				for (unsigned int i = 0; i < g_d2d1c4.size(); i++)
				{
					if (g_d2d1c4[i]->f48 != 5)
				{
					if (g_d25790[i] != 0)
				{
					parts.push_back(g_d2d1c4[i]);
				}
				}
				}
				for (unsigned int i = 0; i < g_d2d1c4.size(); i++)
				{
					if (g_d2d1c4[i]->f48 == 5)
				{
					if (g_d25790[i] != 0)
				{
					parts.push_back(g_d2d1c4[i]);
				}
				}
				}
				kind = 4;
				string text;
				for (unsigned int i = 0; i < parts.size(); i++)
				{
					element = parts[i];
					if (element->f48 != kind)
				{
					kind = element->f48;
					if (i != 0)
				{
					out << "</table>\n";
					out << "<br>\n";
					out << "<br>\n";
					out << "<br>\n";
				}
					out << "<a name=\"" << gameStrings_d2ec50[element->f48] << "\"></a>\n";
					out << "<table class=\"gallery-table\">\n";
					switch (element->f48)	// DEF=5e19 END=5e19
				{
				case 0:
					out << "<tr>\n";
					unknown7d9f90(out, "Overview", 8);
					unknown7d9f90(out, "Power", 3);
					unknown7d9f90(out, "Fabrication", 3);
					out << "</tr>\n";
					out << "<tr>\n";
					unknown7d9fe0(out, "Name");
					unknown7d9fe0(out, "Type");
					unknown7d9fe0(out, "Rating");
					unknown7d9fe0(out, "Size");
					unknown7d9fe0(out, "Mass");
					unknown7d9fe0(out, "Integrity");
					unknown7d9fe0(out, "Coverage");
					unknown7d9fe0(out, "Heat");
					unknown7d9fe0(out, "Rate");
					unknown7d9fe0(out, "Storage");
					unknown7d9fe0(out, "Stability");
					unknown7d9fe0(out, "Count");
					unknown7d9fe0(out, "Time");
					unknown7d9fe0(out, "Components");
					out << "</tr>\n";
					break;
				case 1:
					out << "<tr>\n";
					unknown7d9f90(out, "Overview", 6);
					unknown7d9f90(out, "Upkeep", 2);
					unknown7d9f90(out, "Propulsion", 9);
					unknown7d9f90(out, "Fabrication", 3);
					out << "</tr>\n";
					out << "<tr>\n";
					unknown7d9fe0(out, "Name");
					unknown7d9fe0(out, "Type");
					unknown7d9fe0(out, "Rating");
					unknown7d9fe0(out, "Size");
					unknown7d9fe0(out, "Integrity");
					unknown7d9fe0(out, "Coverage");
					unknown7d9fe0(out, "Energy");
					unknown7d9fe0(out, "Heat");
					unknown7d9fe0(out, "Time/Move");
					unknown7d9fe0(out, "Mod/Extra");
					unknown7d9fe0(out, "Drag");
					unknown7d9fe0(out, "Energy");
					unknown7d9fe0(out, "Heat");
					unknown7d9fe0(out, "Support");
					unknown7d9fe0(out, "Penalty");
					unknown7d9fe0(out, "Burnout");
					unknown7d9fe0(out, "Special");
					unknown7d9fe0(out, "Count");
					unknown7d9fe0(out, "Time");
					unknown7d9fe0(out, "Components");
					out << "</tr>\n";
					break;
				case 2:
					out << "<tr>\n";
					unknown7d9f90(out, "Overview", 8);
					unknown7d9f90(out, "Upkeep", 3);
					unknown7d9f90(out, "Fabrication", 3);
					out << "</tr>\n";
					out << "<tr>\n";
					unknown7d9fe0(out, "Name");
					unknown7d9fe0(out, "Type");
					unknown7d9fe0(out, "Rating");
					unknown7d9fe0(out, "Size");
					unknown7d9fe0(out, "Mass");
					unknown7d9fe0(out, "Integrity");
					unknown7d9fe0(out, "Coverage");
					unknown7d9fe0(out, "Special Trait");
					unknown7d9fe0(out, "Energy");
					unknown7d9fe0(out, "Matter");
					unknown7d9fe0(out, "Heat");
					unknown7d9fe0(out, "Count");
					unknown7d9fe0(out, "Time");
					unknown7d9fe0(out, "Components");
					unknown7d9fe0(out, "Effect/Description");
					out << "</tr>\n";
					break;
				case 3:
					out << "<tr>\n";
					unknown7d9f90(out, "Overview", 8);
					unknown7d9f90(out, "Shot", 9);
					unknown7d9f90(out, "Projectile", 10);
					unknown7d9f90(out, "Explosion", 11);
					unknown7d9f90(out, "Fabrication", 3);
					out << "</tr>\n";
					out << "<tr>\n";
					unknown7d9fe0(out, "Name");
					unknown7d9fe0(out, "Type");
					unknown7d9fe0(out, "Rating");
					unknown7d9fe0(out, "Size");
					unknown7d9fe0(out, "Mass");
					unknown7d9fe0(out, "Integrity");
					unknown7d9fe0(out, "Coverage");
					unknown7d9fe0(out, "Special Trait");
					unknown7d9fe0(out, "Range");
					unknown7d9fe0(out, "Energy");
					unknown7d9fe0(out, "Matter");
					unknown7d9fe0(out, "Heat");
					unknown7d9fe0(out, "Recoil");
					unknown7d9fe0(out, "Targeting");
					unknown7d9fe0(out, "Delay");
					unknown7d9fe0(out, "Stability");
					unknown7d9fe0(out, "Waypoints");
					unknown7d9fe0(out, "Arc");
					unknown7d9fe0(out, "Wide");
					unknown7d9fe0(out, "Count");
					unknown7d9fe0(out, "Damage");
					unknown7d9fe0(out, "Type");
					unknown7d9fe0(out, "Critical");
					unknown7d9fe0(out, "Penetration");
					unknown7d9fe0(out, "Heat Transfer");
					unknown7d9fe0(out, "Spectrum");
					unknown7d9fe0(out, "Disruption");
					unknown7d9fe0(out, "Salvage");
					unknown7d9fe0(out, "Radius");
					unknown7d9fe0(out, "Arc");
					unknown7d9fe0(out, "Damage");
					unknown7d9fe0(out, "Falloff");
					unknown7d9fe0(out, "Chunks");
					unknown7d9fe0(out, "Type");
					unknown7d9fe0(out, "Heat Transfer");
					unknown7d9fe0(out, "Spectrum");
					unknown7d9fe0(out, "Disruption");
					unknown7d9fe0(out, "Salvage");
					unknown7d9fe0(out, "Count");
					unknown7d9fe0(out, "Time");
					unknown7d9fe0(out, "Components");
					unknown7d9fe0(out, "Effect/Description");
					out << "</tr>\n";
					break;
				case 5:
					out << "<tr>\n";
					unknown7d9f90(out, "Overview", 6);
					unknown7d9f90(out, "Fabrication", 3);
					out << "</tr>\n";
					out << "<tr>\n";
					unknown7d9fe0(out, "Name");
					unknown7d9fe0(out, "Type");
					unknown7d9fe0(out, "Rating");
					unknown7d9fe0(out, "Size");
					unknown7d9fe0(out, "Integrity");
					unknown7d9fe0(out, "Life");
					unknown7d9fe0(out, "Count");
					unknown7d9fe0(out, "Time");
					unknown7d9fe0(out, "Components");
					unknown7d9fe0(out, "Description");
					out << "</tr>\n";
				}
				}
					out << "<tr>\n";
					unknown7da020(out, element->f24);
					switch (element->f48)	// DEF=afd3 END=afd3
				{
				case 0:
					unknown7da020(out, gameStrings_d293c0[element->f44]);
					unknown7da020(out, intToString(element->f50) + gameStrings_d22280[element->f94]);
					unknown7da060(out, (element->f4c > 1 ? element->f4c : 0), "", "");
					unknown7da060(out, element->fa4, "", "");
					unknown7da060(out, element->fa8, "", (element->unknown56f3f0() ? empty_b95ebf : "*"));
					unknown7da060(out, element->fac * element->f4c, "", "");
					unknown7da060(out, element->fb0, "", "");
					unknown7da060(out, element->fbc, "", "");
					unknown7da060(out, element->fc0, "", "");
					unknown7da020(out, (element->fc8 != 0 ? intToString(100 - element->fc8) + "%" : string("")));
					unknown7da020(out, (element->f208 ? intToString(element->f204) : string("")));
					unknown7da020(out, (element->f208 ? element->getSuffix() : string("")));
					unknown7da020(out, (element->f208 ? element->namesJoined() : string("")));
					break;
				case 1:
					unknown7da020(out, gameStrings_d293c0[element->f44]);
					unknown7da020(out, intToString(element->f50) + gameStrings_d22280[element->f94]);
					unknown7da060(out, (element->f4c > 1 ? element->f4c : 0), "", "");
					unknown7da060(out, element->fa8, "", (element->unknown56f3f0() ? empty_b95f3b : "*"));
					unknown7da060(out, element->fac * element->f4c, "", "");
					unknown7da120(out, element->fb4, 0, 1, "-");
					unknown7da060(out, element->fb0, "+", "");
					unknown7da060(out, element->fcc, "", "");
					unknown7da060(out, element->fd0, "", "");
					unknown7da060(out, element->fd4, "", "");
					unknown7da120(out, element->fd8, 0, 1, "-");
					unknown7da060(out, element->fdc, "+", "");
					unknown7da060(out, element->fe0, "", "");
					unknown7da060(out, element->fe4, "", "");
					unknown7da060(out, element->fe8, "", "%");
					unknown7da020(out, (element->fec != 0 ? string(gameStrings_d01b48[element->fec]) : string("")));
					unknown7da020(out, (element->f208 ? intToString(element->f204) : string("")));
					unknown7da020(out, (element->f208 ? element->getSuffix() : string("")));
					unknown7da020(out, (element->f208 ? element->namesJoined() : string("")));
					break;
				case 2:
					unknown7da020(out, gameStrings_d293c0[element->f44]);
					unknown7da020(out, intToString(element->f50) + gameStrings_d22280[element->f94]);
					unknown7da060(out, (element->f4c > 1 ? element->f4c : 0), "", "");
					unknown7da060(out, element->fa4, "", "");
					unknown7da060(out, element->fa8, "", (element->unknown56f3f0() ? empty_b9600e : "*"));
					unknown7da060(out, element->fac * element->f4c, "", "");
					unknown7da020(out, element->unknown56fde0());
					unknown7da060(out, (int)(element->fb4), "", "");
					unknown7da060(out, element->fb8, "", "");
					unknown7da060(out, element->fb0, "", "");
					unknown7da020(out, (element->f208 ? intToString(element->f204) : string("")));
					unknown7da020(out, (element->f208 ? element->getSuffix() : string("")));
					unknown7da020(out, (element->f208 ? element->namesJoined() : string("")));
					text = element->describe();
					unknown7da020(out, (!text.empty() ? string(text) : (element->f288.size() > 1 ? string(element->f288) : string(""))));
					break;
				case 3:
					unknown7da020(out, gameStrings_d293c0[element->f44]);
					unknown7da020(out, intToString(element->f50) + gameStrings_d22280[element->f94]);
					unknown7da060(out, (element->f4c > 1 ? element->f4c : 0), "", "");
					unknown7da060(out, element->fa4, "", "");
					unknown7da060(out, element->fa8, "", (element->unknown56f3f0() ? empty_b9615f : "*"));
					unknown7da060(out, element->fac * element->f4c, "", "");
					unknown7da020(out, element->unknown56fde0());
					unknown7da060(out, element->f100, "", "");
					unknown7da060(out, element->f108, "-", "");
					unknown7da060(out, element->f10c, "-", "");
					unknown7da060(out, element->f110, "+", "");
					unknown7da060(out, element->f14c, "", "");
					unknown7da060(out, element->f130, "", "%");
					unknown7da060(out, element->f114, "", "");
					unknown7da020(out, (element->f15c != 0 ? intToString(100 - element->f15c) + "%" : string("")));
					unknown7da060(out, element->f104, "", "");
					unknown7da060(out, element->f11c, "", "");
					unknown7da020(out, (element->f164 ? "1" : empty_b962b6));
					unknown7da060(out, (element->f118 > 1 ? element->f118 : 0), "", "");
					unknown7da020(out, (element->f120.hi == 0 ? string("") : (element->f120.empty() ? intToString(element->f120.hi) : intToString(element->f120.lo) + "-" + intToString(element->f120.hi))));
					unknown7da020(out, (element->f128 < 10 ? string(gameStrings_d29980[element->f128]) : string("")));
					unknown7da020(out, (element->f138 != 0 ? intToString(element->f138) + "% " + gameStrings_d1e058[element->f134] : string("")));
					unknown7da020(out, element->idList());
					unknown7da020(out, (element->f158 != 0 ? gameStrings_cf6648[element->f158] + " (" + intToString(g_b96178[element->f158]) + ")" : string("")));
					unknown7da020(out, (element->f154 != 0 ? gameStrings_d31b68[element->f154] + " (" + intToString(g_b9654c[element->f154]) + ")" : string("")));
					unknown7da060(out, element->f150, "", "");
					unknown7da020(out, (element->f12c != 0 ? tc31_OpY1_intToStringSigned(element->f12c) : string("")));
					first = element->f1a0;
					unknown7da020(out, (first != 0 ? intToString(first->f3c) : string("")));
					unknown7da020(out, (first != 0 && first->f40 != 0 ? intToString(first->f40) : string("")));
					unknown7da020(out, (first != 0 ? (first->f34 != 0 ? intToString(first->f30 - first->f34) + "-" + intToString(first->f30 + first->f34) : intToString(first->f30)) : string("")));
					unknown7da020(out, (first != 0 && first->f38 != 0 ? intToString(first->f38) : string("")));
					unknown7da020(out, (first != 0 ? first->f44.rangeToString_40c2b0("-") : string("")));
					unknown7da020(out, (first != 0 ? string(gameStrings_d29980[first->f2c]) : string("")));
					unknown7da020(out, (first != 0 && first->f64 != 0 ? gameStrings_cf6648[first->f64] + " (" + intToString(g_b96178[first->f64]) + ")" : string("")));
					unknown7da020(out, (first != 0 && first->f60 != 0 ? gameStrings_d31b68[first->f60] + " (" + intToString(g_b9654c[first->f60]) + ")" : string("")));
					unknown7da020(out, (first != 0 && first->f5c != 0 ? intToString(first->f5c) : string("")));
					unknown7da020(out, (first != 0 && first->f58 != 0 ? tc31_OpY1_intToStringSigned(first->f58) : string("")));
					unknown7da020(out, (element->f208 ? intToString(element->f204) : string("")));
					unknown7da020(out, (element->f208 ? element->getSuffix() : string("")));
					unknown7da020(out, (element->f208 ? element->namesJoined() : string("")));
					text = element->describe();
					unknown7da020(out, (!text.empty() ? string(text) : (element->f288.size() > 1 ? string(element->f288) : string(""))));
					break;
				case 5:
					unknown7da020(out, gameStrings_d293c0[element->f44]);
					unknown7da020(out, intToString(element->f50) + gameStrings_d22280[element->f94]);
					unknown7da060(out, (element->f4c > 1 ? element->f4c : 0), "", "");
					unknown7da060(out, element->fa8, "", (element->unknown56f3f0() ? empty_b9639b : "*"));
					unknown7da060(out, element->unknown56fda0(), "", "");
					unknown7da020(out, (element->f208 ? intToString(element->f204) : string("")));
					unknown7da020(out, (element->f208 ? element->getSuffix() : string("")));
					unknown7da020(out, (element->f208 ? element->namesJoined() : string("")));
					unknown7da020(out, (element->f288.size() > 1 ? string(element->f288) : string("")));
				}
					out << "</tr>\n";
				}
				out << "</table>\n";
				out << "<br>\n";
				out << "<br>\n";
				out << "<br>\n";
				out << "</body>\n";
				out << "</html>\n";
				fbc->f6c[1]->hoverBegin();
				break;
				}
				case 'C':
				{
					C31_Part *element;
					C31_Sub *first;
				out << "Collected" << ",Name,Type,Slot,Size,Mass,Rating,Category,Integrity,No Repairs,Coverage,Special Trait" << ",Life" << ",Energy Upkeep,Matter Upkeep,Heat Generation" << ",Energy Generation,Energy Storage,Power Stability" << ",Time/Move,Mod/Extra,Drag,Energy/Move,Heat/Move,Support,Penalty,Burnout,Special" << ",Range,Shot Energy,Shot Matter,Shot Heat,Recoil,Targeting,Delay,Overload Stability,Waypoints,Arc,Wide" << ",Projectile Count,Damage Min,Damage Max,Damage Type,Critical,Penetration,Heat Transfer,Spectrum,Disruption,Salvage" << ",Explosion Radius,Explosion Arc,Explosion Damage Min,Explosion Damage Max,Falloff,Chunks,Explosion Type,Explosion Heat Transfer,Explosion Spectrum,Explosion Disruption,Explosion Salvage" << ",Effect" << ",Description" << ",Hackable Schematic" << ",Fabrication Number,Fabrication Time,Fabrication Components" << ",Studyable" << ",Supporter Attribution\n";
				for (unsigned int i = 0; i < g_d2d1c4.size(); i++)
				{
					element = g_d2d1c4[i];
					if (g_d25790[i] != 0)
				{
					unknown7da210(out, g_d25790[element->f0]);
					OpU5_writeLabelLine(out, element->f24);
					OpU5_writeLabelLine(out, gameStrings_d293c0[element->f44]);
					OpU5_writeLabelLine(out, gameStrings_d378d0[element->f48]);
					unknown7da210(out, element->f4c);
					unknown7da210(out, element->fa4);
					unknown7da210(out, element->f50);
					OpU5_writeLabelLine(out, gameStrings_d25e10[element->f94]);
					unknown7da210(out, element->fa8);
					unknown7da210(out, !element->unknown56f3f0());
					unknown7da210(out, element->fac * element->f4c);
					OpU5_writeLabelLine(out, element->unknown56fde0());
					unknown7da210(out, element->unknown56fda0());
					OpU5_writeQuotedFloat(out, element->fb4, 0, 1);
					unknown7da210(out, element->fb8);
					unknown7da210(out, element->fb0);
					unknown7da210(out, element->fbc);
					unknown7da210(out, element->fc0);
					OpU5_writeLabelLine(out, (element->fc8 != 0 ? intToString(100 - element->fc8) + "%" : string("")));
					unknown7da210(out, element->fcc);
					unknown7da210(out, element->fd0);
					unknown7da210(out, element->fd4);
					OpU5_writeQuotedFloat(out, element->fd8, 0, 1);
					unknown7da210(out, element->fdc);
					unknown7da210(out, element->fe0);
					unknown7da210(out, element->fe4);
					OpU5_writeLabelLine(out, (element->fe8 != 0 ? intToString(element->fe8) + "%" : string("")));
					OpU5_writeLabelLine(out, (element->fec != 0 ? string(gameStrings_d01b48[element->fec]) : string("")));
					unknown7da210(out, element->f100);
					unknown7da210(out, element->f108);
					unknown7da210(out, element->f10c);
					unknown7da210(out, element->f110);
					unknown7da210(out, element->f14c);
					unknown7da210(out, element->f130);
					unknown7da210(out, element->f114);
					OpU5_writeLabelLine(out, (element->f15c != 0 ? intToString(100 - element->f15c) + "%" : string("")));
					unknown7da210(out, element->f104);
					unknown7da210(out, element->f11c);
					OpU5_writeLabelLine(out, (element->f164 ? "1" : empty_b963bf));
					unknown7da210(out, element->f118);
					OpU5_writeLabelLine(out, (element->f120.hi == 0 ? string("") : intToString(element->f120.lo)));
					OpU5_writeLabelLine(out, (element->f120.hi == 0 ? string("") : intToString(element->f120.hi)));
					OpU5_writeLabelLine(out, (element->f128 < 10 ? string(gameStrings_d29980[element->f128]) : string("")));
					OpU5_writeLabelLine(out, (element->f138 != 0 ? intToString(element->f138) + "% " + gameStrings_d1e058[element->f134] : string("")));
					OpU5_writeLabelLine(out, element->idList());
					OpU5_writeLabelLine(out, (element->f158 != 0 ? gameStrings_cf6648[element->f158] + " (" + intToString(g_b96178[element->f158]) + ")" : string("")));
					OpU5_writeLabelLine(out, (element->f154 != 0 ? gameStrings_d31b68[element->f154] + " (" + intToString(g_b9654c[element->f154]) + ")" : string("")));
					unknown7da210(out, element->f150);
					unknown7da210(out, element->f12c);
					first = (element->f1a0 != 0 ? element->f1a0 : element->f1a8);
					OpU5_writeLabelLine(out, (first != 0 ? intToString(first->f3c) : string("")));
					OpU5_writeLabelLine(out, (first != 0 && first->f40 != 0 ? intToString(first->f40) : string("")));
					OpU5_writeLabelLine(out, (first != 0 ? (first->f34 != 0 ? intToString(first->f30 - first->f34) : intToString(first->f30)) : string("")));
					OpU5_writeLabelLine(out, (first != 0 ? (first->f34 != 0 ? intToString(first->f30 + first->f34) : intToString(first->f30)) : string("")));
					OpU5_writeLabelLine(out, (first != 0 && first->f38 != 0 ? intToString(first->f38) : string("")));
					OpU5_writeLabelLine(out, (first != 0 ? first->f44.rangeToString_40c2b0("-") : string("")));
					OpU5_writeLabelLine(out, (first != 0 ? string(gameStrings_d29980[first->f2c]) : string("")));
					OpU5_writeLabelLine(out, (first != 0 && first->f64 != 0 ? gameStrings_cf6648[first->f64] + " (" + intToString(g_b96178[first->f64]) + ")" : string("")));
					OpU5_writeLabelLine(out, (first != 0 && first->f60 != 0 ? gameStrings_d31b68[first->f60] + " (" + intToString(g_b9654c[first->f60]) + ")" : string("")));
					OpU5_writeLabelLine(out, (first != 0 && first->f5c != 0 ? intToString(first->f5c) : string("")));
					OpU5_writeLabelLine(out, (first != 0 && first->f58 != 0 ? intToString(first->f58) : string("")));
					OpU5_writeLabelLine(out, element->describe());
					OpU5_writeLabelLine(out, (element->f288.size() > 1 ? string(element->f288) : string("")));
					unknown7da210(out, ((element->f54 == 1 || element->f54 == 2) && element->f44 != 0 ? 1 : 0));
					OpU5_writeLabelLine(out, (element->f208 ? intToString(element->f204) : string("")));
					OpU5_writeLabelLine(out, (element->f208 ? element->getSuffix() : string("")));
					OpU5_writeLabelLine(out, (element->f208 ? element->namesJoined() : string("")));
					unknown7da210(out, element->unknown56f460() != 0);
					for (int j = 0; j < 1352; j++)
				{
					if (C31_PAIRS[j].b == element->f24)
				{
					OpU5_writeLabelLine(out, (C31_PAIRS[j].a.empty() ? string("") : string(C31_PAIRS[j].a)));
				}
				}
					out << "\n";
				}
				}
				fbc->f6c[2]->hoverBegin();
				}
				}
				c31_ui_cec040->message("Known items exported to " + path);
			}
		}
		break;
	case 2:
		if (key != '0')
			fa4[key - '1']->onEvent(C31_Event(0x26));
		break;
	}
}
