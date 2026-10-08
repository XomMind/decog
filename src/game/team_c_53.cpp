// team_c_53: startup log lines (0x511440): prints the "Systems online..." boot block into the message log, plus
//	challenge/special-mode/seed notes (also posted to the Discord webhook when one is set)
// NOTE: names are placeholders
#include <string>
#include <vector>
using namespace std;

class C53_H { public: int ID; C53_H(); };	// NOTE: placeholder (HEntity/HProp)
bool c53_message5111e0(int id, const string *a, const string *b, int c, C53_H entity, C53_H prop, int d, int e);	// NOTE: placeholder name (0x5111e0)
void opr5c_replace407e00(string &text, string from, string to);	// NOTE: placeholder name
bool OpV4c_Fn9d3f40(int *list, unsigned int count);	// NOTE: placeholder name
struct C53_Meta { bool unknown7784b0(); };
struct C53_PlayerData { bool getField(); };
class DiscordWebhook { public: void addComment(string comment); };

extern int c53_d30260, c53_cf4570, c53_d30250, c53_d30240, c53_cf4748, c53_cf4718, c53_cf462c, c53_cebd5c;	// NOTE: placeholder names below
extern bool c53_d28de0;
extern C53_Meta c53_d25628;
extern int c53_cf471c[];
extern string c53_d28ce8, c53_d1e864, c53_cf4574;
extern C53_PlayerData c53_cf45d8;
extern DiscordWebhook *c53_cefb5c;
extern string gameStrings_d20b98[], gameStrings_d2f508[], gameStrings_cf2820[];	// global_string_arrays.cpp

class C53_Intro	// NOTE: placeholder layout
{
public:
	char pad0[0x10];
	string f10;
	int f2c;
	bool f30;
	bool f31;
	char pad32[6];
	bool f38;

	void start_511440(int mode, bool quick);
};

void C53_Intro::start_511440(int mode, bool quick)
{
	f10.clear();
	f2c = mode;
	f30 = quick;
	f31 = false;
	f38 = false;
	if (f30)
	{
		for (int center = 0; center < c53_d30260; center++)
				c53_message5111e0(803,&string(" "),0,0,C53_H(),C53_H(),0,1);
	}
	else
	{
		int col = c53_cf4570 + c53_d30250;
		col += c53_d30240;
		for (int cols = 0; cols < col; cols++)
				c53_message5111e0(803,&string(" "),0,0,C53_H(),C53_H(),0,0);
		c53_message5111e0(803,&string("Systems online..."),0,0,C53_H(),C53_H(),0,0);
		c53_message5111e0(803,&string("Loading variables..."),0,0,C53_H(),C53_H(),0,0);
		c53_message5111e0(803,&string(c53_cf4748 != 0 ? "CORE=UNSTABLE" : "CORE=STABLE"),0,0,C53_H(),C53_H(),0,0);
		c53_message5111e0(803,&string("INTEGRATION=OK"),0,0,C53_H(),C53_H(),0,0);
		c53_message5111e0(803,&string("LOCATION=UNKNOWN"),0,0,C53_H(),C53_H(),0,0);
		c53_message5111e0(803,&string("GOAL=EXPLORE"),0,0,C53_H(),C53_H(),0,0);
		if (c53_d28de0 && !c53_d25628.unknown7784b0() && c53_cf4718 == 0 && !OpV4c_Fn9d3f40(c53_cf471c,12))
				c53_message5111e0(809,0,0,0,C53_H(),C53_H(),0,0);
		for (int cols = 0; cols < 12; cols++)
		{
			if (c53_cf471c[cols] != 0)
						c53_message5111e0(807,&string(gameStrings_d20b98[cols]),0,0,C53_H(),C53_H(),0,0);
		}
		if (c53_d28ce8 != "0")
				c53_message5111e0(808,&c53_d1e864,0,0,C53_H(),C53_H(),0,0);
		if (c53_cf462c != 0)
		{
			string cols(c53_cf4574);
			opr5c_replace407e00(cols,"XXX",gameStrings_d2f508[c53_cf462c]);
					c53_message5111e0(805,&cols,0,0,C53_H(),C53_H(),0,0);
			if (c53_cf462c == 5 && c53_cebd5c == 1)
			{
				cols = gameStrings_cf2820[c53_cf462c] + " was an event developed long before the smaller 45-row UI layouts. As the upgrades menu is not fully compatible with the availible interface area, suggest switching to either the Non-modal or Modal layout in the Options menu.";
							c53_message5111e0(805,&cols,0,0,C53_H(),C53_H(),0,0);
			}
		}
		if (c53_cf45d8.getField())
				c53_message5111e0(810,0,0,0,C53_H(),C53_H(),0,0);
		if (c53_cefb5c != 0)
		{
			vector<string> cols;
			if (c53_cf462c != 0)
				cols.push_back("*[SPECIAL MODE]: " + gameStrings_cf2820[c53_cf462c] + "*");
			else
			{
				for (int current = 0; current < 12; current++)
				{
					if (c53_cf471c[current] != 0)
						cols.push_back("*[CHALLENGE]: " + gameStrings_d20b98[current] + "*");
				}
			}
			if (c53_d28ce8 != "0")
				cols.push_back("*[MANUAL SEED]: " + c53_d1e864 + "*");
			if (!cols.empty())
			{
				c53_cefb5c->addComment("*[Starting new run with alternate parameters...]*");
				for (unsigned int current = 0; current < cols.size(); current++)
					c53_cefb5c->addComment(cols[current]);
			}
		}
	}
}
