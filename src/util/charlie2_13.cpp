// Options menu change handler (0x7d2030; CCommands::unknown7d2030): with a button, opens the picker for that
// option (font sets, fullscreen, difficulty, volumes, name/seed text inputs, timing lists...); without one,
// applies the picked text (or toggles the boolean option) and refreshes the option's value display.
// NOTE: placeholder names and layouts throughout (C2O*, c2o_<address>).
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

string intToString(int v);
int stringToInt(const string &s);
void OpU5_unknown7d1d30(const string &s);

struct C2OPos { int x, y; C2OPos(); C2OPos(int nx, int ny); C2OPos(const C2OPos &o); C2OPos(const C2OPos &o, int dx, int dy); };
struct C2ORect { int x, y, w, h; C2ORect(); };
struct C2OHE { int id; C2OHE(); };
class COptionButton { public: C2OPos c2o_localToAbs(C2OPos p); char pad00[0x78]; int type; };
class COptionValue { public: void c2o_clear(); void c2o_refresh(); C2OPos c2o_getPos(); };
struct C2OTextInput { void c2o_setText(const string &s); void c2o_setUnknown98(const vector<int> &v); void c2o_setUnknownA9(bool v); };
struct C2OInputHost { char pad00[0x7c]; C2OTextInput *input; };
struct C2OType { C2OType(void *mission, C2ORect &area, int a, const string &title, int b, void (*fn)(const string &), int c, int d, int e); char pad[0x80]; };
struct C2ORex
{
	bool c2o_isValid();
	void c2o_f418aa0(vector<string> &names, int v);
	void c2o_f418ba0(vector<int> &sizes, int v);
	int c2o_f418c50();
	int c2o_f418c20();
	void c2o_f424020(string &name, int v);
	bool c2o_f4188e0();
	void c2o_f418cc0(bool v);
	void c2o_toggleFullscreen();
	int c2o_f4189e0();
};
struct C2OMixer { void c2o_setVolume(int v); };
struct C2OMouse { void c2o_setCellPoint(const C2OPos &p); void c2o_setCursorHidden(bool v); };
struct C2OSoundRef { char pad[0xc]; void *sound; char pad2[4]; };
struct C2OAudio { char pad[0xc8]; vector<C2OSoundRef> sounds; };
struct C2OEntity { char pad[0x44]; int type; char pad2[0x190 - 0x48]; C2OAudio *audio; };
struct C2OPlayer { int id; };
struct C2OMap { C2OPlayer c2o_getPlayer(); };
struct C2OSoundMgr { void c2o_f4544e0(); void c2o_f4544c0(C2OPlayer p); void c2o_f454540(); void c2o_f500010(); void c2o_f5003b0(); void c2o_f500260(int v); };
struct C2OCMap { void *c2o_getAudioLog(); void c2o_endAudioLogs(); void c2o_f819900(); };
struct C2OParts { void c2o_f8968b0(int mode); };
struct C2OUi { void c2o_update(); };
struct C2OGM { void c2o_f78d700(int a, int b); };

class CCommands
{
public:
	void unknown7d2030(COptionButton *button, string text);
	void c2o_delay();
	void c2o_menu(const string &title, const vector<string> &options, vector<bool> *enabled);
	void c2o_f7d1d80();
	void c2o_f7d5c70();
	char pad00[0x11c];
	vector<COptionButton *> optionButtons;	// +0x11c
	vector<COptionValue *> optionValues;	// +0x12c
	int pad13c;
	int selected;	// +0x140
	int pad144;
	int pending;	// +0x148
};

extern bool c2o_d28c8a, c2o_d28c88, c2o_d28c89, c2o_d28d08, c2o_d28d09, c2o_d28d30, c2o_d28cbe, c2o_d28c90[], c2o_d28d14, c2o_d28c8b,
	c2o_d28d16, c2o_d28e58, c2o_d28d1c, c2o_d28d1d, c2o_d28d24, c2o_d28d25, c2o_d28d26, c2o_d28d27, c2o_d28d04, c2o_d28d05, c2o_d28d06,
	c2o_d28d07, c2o_d28d28, c2o_d28d31, c2o_d28d32, c2o_d28d38, c2o_d28d39, c2o_d28d3a, c2o_d28d3b, c2o_d28d3c, c2o_d28d4c, c2o_d28d4d,
	c2o_d28d60, c2o_d257d4;
extern int c2o_d28c68, c2o_cebd5c, c2o_d28ca4, c2o_d28ca8, c2o_d257d0, c2o_d28d0c, c2o_d28d10, c2o_d28c8c, c2o_d28c94[], c2o_d28d68,
	c2o_d28d18, c2o_d28d20, c2o_d035d4, c2o_d28d2c, c2o_d28d34, c2o_d28d40, c2o_d28d44, c2o_d28d48, c2o_d28d50, c2o_d28d54,
	c2o_d28d58, c2o_d28d5c;
extern unsigned c2o_d035d0;
extern string c2o_d28c6c, c2o_d2a504, c2o_d2d490, c2o_cfd42c, c2o_d28ccc, c2o_d2f184, c2o_d28ce8;
extern string c2o_d1d088[], c2o_cf1148[], c2o_d307d0[], c2o_d25808[], c2o_d25e8c[], c2o_d39718[];
extern vector<int> c2o_d22590;
extern vector<C2OEntity *> c2o_d2d1c4;
extern C2ORex c2o_d223f0;
extern C2OMixer *c2o_cefa90;
extern C2OMouse *c2o_cefa94;
extern C2OSoundMgr c2o_d2d2a0;
extern C2OMap *c2o_cefc4c;
extern C2OCMap *c2o_cec054;
extern C2OParts *c2o_cec088;
extern C2OUi c2o_d1d9c0;
extern void *c2o_cec034;
extern C2OInputHost *c2o_cec10c;
extern C2OGM *c2o_cefaa8;
extern const char c2o_bfb5d8[], c2o_bfb5e8[], c2o_bfb5fc[], c2o_bfb61c[], c2o_bfb614[], c2o_bfb624[], c2o_bfb63c[], c2o_bfb64c[],
	c2o_bfb65c[], c2o_bfb66c[], c2o_bfb67c[], c2o_bfb68c[], c2o_bfb698[], c2o_bfb6a4[], c2o_bfb6a8[], c2o_bfb6b0[], c2o_bfb6b4[],
	c2o_bfb6c8[], c2o_bfb6d8[], c2o_bfb6ec[], c2o_bfb6f0[], c2o_bfb700[], c2o_bfb70c[], c2o_bfb718[], c2o_bfb728[], c2o_bfb73c[];
int c2o_indexOf(vector<COptionButton *> &list, COptionButton *button);
int c2o_findStringIndex(const string *list, unsigned n, string s);
void c2o_4541b0(unsigned sound, int a, int b);
void c2o_eraseAt(vector<string> &list, int index);
void c2o_removeVectorElement(vector<int> &list, int index);
void c2o_insertString(vector<string> &list, int index, string s);
void c2o_insertAt(vector<int> &list, int index, int v);
void c2o_moveElementS(vector<string> &list, unsigned from, unsigned to);
void c2o_moveElementB(vector<bool> &list, unsigned from, unsigned to);
void c2o_playSound(void *sound, int channel, int fade, int loopsB, int loops);
void c2o_padRight(string &s, int width, char c);
string c2o_toUpper(const string &s);
bool c2o_logPhrase(int id, const string *a, const string *b, const string *c, C2OHE d, C2OHE e, int f);

#define C2O_REFRESH \
	optionValues[selected]->c2o_clear(); \
	optionValues[selected]->c2o_refresh(); \
	c2o_4541b0(0x32, 0, 0)

void CCommands::unknown7d2030(COptionButton *button, string text)
{
	if (button)
		selected = c2o_indexOf(optionButtons, button);
	if (c2o_d28c8a && button)
		c2o_cefa94->c2o_setCellPoint(button->c2o_localToAbs(C2OPos(4, 0)));
	switch (optionButtons[selected]->type)
	{
	case 0:
		if (button)
		{
			vector<string> options;
			for (int i = 0; i < 3; i++)
				options.push_back(c2o_d1d088[i]);
			c2o_menu(c2o_bfb5d8, options, 0);
		}
		else
		{
			c2o_d28c68 = c2o_findStringIndex(c2o_d1d088, 3, text);
			if (c2o_d28c68 != c2o_cebd5c)
			{
				c2o_d28c6c = c2o_d2a504;
				c2o_d28ca4 = 0;
				c2o_d28ca8 = 0;
				pending = 0;
			}
			c2o_delay();
			c2o_d22590[0xc] = 1;
			C2O_REFRESH;
		}
		break;
	case 1:
		if (button)
		{
			vector<string> parts;
			vector<int> v;
			c2o_d223f0.c2o_f418aa0(parts, 0);
			c2o_d223f0.c2o_f418ba0(v, 0);
			vector<int> arr;
			for (int i = 0; i < v.size(); i++)
			{
				if (c2o_d28d30 && v[i] <= 10)
					arr.push_back(i);
				else if (c2o_d223f0.c2o_isValid())
				{
					if (v[i] > c2o_d223f0.c2o_f418c50())
						arr.push_back(i);
					else if (v[i] < c2o_d223f0.c2o_f418c50())
						arr.push_back(i);
				}
				else if (!c2o_d28cbe && v[i] > c2o_d223f0.c2o_f418c20())
					arr.push_back(i);
			}
			if (!arr.empty())
			{
				for (int j = arr.size() - 1; j >= 0; j--)
				{
					c2o_eraseAt(parts, arr[j]);
					c2o_removeVectorElement(v, arr[j]);
				}
			}
			vector<bool> *vec2 = 0;
			vec2 = new vector<bool>(v.size(), true);
			vector<string> temp(parts);
			parts.clear();
			vector<int> prev(v);
			v.clear();
			vector<bool> old(*vec2);
			vec2->clear();
			parts.push_back(temp[0]);
			v.push_back(prev[0]);
			vec2->push_back(old[0]);
			for (int i = 1; i < temp.size(); i++)
			{
				if (prev[i] <= v.back())
				{
					parts.push_back(temp[i]);
					v.push_back(prev[i]);
					vec2->push_back(old[i]);
				}
				else
				{
					for (int j = 0; j < parts.size(); j++)
					{
						if (prev[i] > v[j])
						{
							c2o_insertString(parts, j, temp[i]);
							c2o_insertAt(v, j, prev[i]);
							vec2->insert(vec2->begin() + j, old[i]);
							break;
						}
					}
				}
			}
			for (int i = 0, num = parts.size(); num; i++, num--)
			{
				if (!vec2->at(i))
				{
					c2o_moveElementS(parts, i, parts.size() - 1);
					c2o_moveElementB(*vec2, i, vec2->size() - 1);
					i--;
				}
			}
			c2o_menu(c2o_bfb5e8, parts, vec2);
		}
		else
		{
			c2o_d223f0.c2o_f424020(text, 0);
			c2o_d2d490 = text;
			if (c2o_d28c6c != c2o_d2a504)
				c2o_d28c6c = c2o_d2d490;
			c2o_delay();
			c2o_d22590[0xa] = 1;
			C2O_REFRESH;
		}
		break;
	case 2:
		if (button)
		{
			vector<string> options;
			for (int i = 0; i < 3; i++)
				options.push_back(c2o_cf1148[i]);
			c2o_menu(c2o_bfb5fc, options, 0);
		}
		else
		{
			int mode = c2o_findStringIndex(c2o_cf1148, 3, text);
			int steps = 0;
			switch (mode)
			{
			case 0:
				if (c2o_d223f0.c2o_isValid())
				{
					c2o_d28c88 = false;
					steps = 1;
				}
				break;
			case 1:
				if (!c2o_d223f0.c2o_isValid())
				{
					c2o_d28c89 = false;
					c2o_d223f0.c2o_f418cc0(false);
					c2o_d28c88 = true;
					steps = 1;
				}
				else if (c2o_d223f0.c2o_f4188e0())
				{
					c2o_d28c89 = false;
					c2o_d223f0.c2o_f418cc0(false);
					steps = 2;
				}
				break;
			case 2:
				if (!c2o_d223f0.c2o_isValid())
				{
					c2o_d28c89 = true;
					c2o_d223f0.c2o_f418cc0(true);
					c2o_d28c88 = true;
					steps = 1;
				}
				else if (!c2o_d223f0.c2o_f4188e0())
				{
					c2o_d28c89 = true;
					c2o_d223f0.c2o_f418cc0(true);
					steps = 2;
				}
			}
			while (steps)
			{
				c2o_d223f0.c2o_toggleFullscreen();
				C2O_REFRESH;
				c2o_f7d5c70();
				steps--;
			}
			c2o_delay();
		}
		break;
	case 3:
		c2o_d28d08 = !c2o_d28d08;
		C2O_REFRESH;
		break;
	case 4:
		c2o_d28d09 = !c2o_d28d09;
		if (c2o_d28d09)
		{
			c2o_d22590.assign(0x57u, 0);
			remove((c2o_cfd42c + c2o_bfb61c + c2o_bfb614).c_str());
			c2o_d257d0 = 0;
			c2o_d257d4 = false;
		}
		C2O_REFRESH;
		break;
	case 5:
		if (button)
		{
			vector<string> options;
			for (int i = 2; i >= 0; i--)
				options.push_back(c2o_d307d0[i]);
			c2o_menu(c2o_bfb624, options, 0);
		}
		else
		{
			int old = c2o_d28d0c;
			c2o_d28d0c = c2o_findStringIndex(c2o_d307d0, 3, text);
			if (c2o_d28d0c != old)
				pending = 5;
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 6:
		if (button)
		{
			vector<string> options;
			for (int i = 0; i < 3; i++)
				options.push_back(c2o_d25808[i]);
			c2o_menu(c2o_bfb63c, options, 0);
		}
		else
		{
			c2o_d28d10 = c2o_findStringIndex(c2o_d25808, 3, text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 7:
		if (button)
		{
			vector<string> options;
			for (int v = 0; v <= 100; v += 10)
				options.push_back(intToString(v));
			c2o_menu(c2o_bfb64c, options, 0);
		}
		else
		{
			c2o_d28c8c = stringToInt(text) / 10;
			c2o_cefa90->c2o_setVolume(c2o_d28c8c);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 8:
	case 9:
	case 10:
	case 11:
		if (button)
		{
			vector<string> options;
			for (int v = 0; v <= 100; v += 10)
				options.push_back(intToString(v));
			c2o_menu(c2o_bfb65c, options, 0);
		}
		else
		{
			int channel = optionButtons[selected]->type - 8;
			c2o_d28c90[channel] = c2o_d28c94[channel] = stringToInt(text) / 10;
			c2o_delay();
			C2O_REFRESH;
			switch (channel)
			{
				break;
			case 1:
				for (unsigned i = 0; i < c2o_d2d1c4.size(); i++)
				{
					if (c2o_d2d1c4[i]->type == 0x16 && !c2o_d2d1c4[i]->audio->sounds.empty())
					{
						c2o_playSound(c2o_d2d1c4[i]->audio->sounds.front().sound, -1, 0, 0, 0);
						break;
					}
				}
				break;
			case 2:
				if (!c2o_d28c90[channel])
					c2o_d2d2a0.c2o_f4544e0();
				else
					c2o_d2d2a0.c2o_f4544c0(c2o_cefc4c->c2o_getPlayer());
				c2o_d2d2a0.c2o_f454540();
				c2o_d2d2a0.c2o_f500010();
				if (c2o_cec054->c2o_getAudioLog())
				{
					c2o_cec054->c2o_endAudioLogs();
					c2o_cec054->c2o_f819900();
				}
				break;
			case 3:
				if (!c2o_d28c90[channel])
					c2o_d2d2a0.c2o_f5003b0();
				else
				{
					c2o_d2d2a0.c2o_f500260(1);
					if (c2o_d28c90[2])
					{
						c2o_d2d2a0.c2o_f4544c0(c2o_cefc4c->c2o_getPlayer());
						c2o_d2d2a0.c2o_f500010();
					}
				}
			}
		}
		break;
	case 12:
		c2o_d28d14 = !c2o_d28d14;
		if (!c2o_d28c8b)
		{
			if (c2o_d28d14)
				c2o_cec054->c2o_f819900();
			else
				c2o_cec054->c2o_endAudioLogs();
		}
		C2O_REFRESH;
		break;
	case 13:
		c2o_d28d16 = !c2o_d28d16;
		if (c2o_d28e58)
		{
			int mode = c2o_d28d68;
			c2o_cec088->c2o_f8968b0(mode == 2 ? 0 : 2);
			c2o_cec088->c2o_f8968b0(mode);
		}
		C2O_REFRESH;
		break;
	case 14:
		if (button)
		{
			vector<string> options;
			for (int i = 0; i < 2; i++)
				options.push_back(c2o_d25e8c[i]);
			c2o_menu(c2o_bfb66c, options, 0);
		}
		else
		{
			c2o_d28d18 = c2o_findStringIndex(c2o_d25e8c, 2, text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 15:
		c2o_d28d1c = !c2o_d28d1c;
		C2O_REFRESH;
		break;
	case 16:
		c2o_d28d1d = !c2o_d28d1d;
		pending = 0x10;
		c2o_f7d1d80();
		C2O_REFRESH;
		break;
	case 17:
		if (button)
		{
			vector<string> options;
			options.push_back(intToString(0));
			options.push_back(intToString(5));
			options.push_back(intToString(10));
			options.push_back(intToString(15));
			options.push_back(intToString(20));
			c2o_menu(c2o_bfb67c, options, 0);
		}
		else
		{
			c2o_d28d20 = stringToInt(text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 18:
		c2o_d28d24 = !c2o_d28d24;
		C2O_REFRESH;
		break;
	case 19:
		c2o_d28d25 = !c2o_d28d25;
		C2O_REFRESH;
		break;
	case 20:
		c2o_d28c8a = !c2o_d28c8a;
		c2o_d1d9c0.c2o_update();
		c2o_cefa94->c2o_setCursorHidden(c2o_d28c8a);
		C2O_REFRESH;
		break;
	case 21:
		c2o_d28d26 = !c2o_d28d26;
		pending = 0x15;
		c2o_f7d1d80();
		C2O_REFRESH;
		break;
	case 22:
		c2o_d28d27 = !c2o_d28d27;
		C2O_REFRESH;
		break;
	case 25:
		if (button)
		{
			C2OPos p(optionValues[selected]->c2o_getPos(), 0, 1);
			C2ORect area;
			area.x = p.x;
			area.y = p.y;
			area.w = c2o_d035d4 + 4;
			area.h = 4;
			new C2OType(c2o_cec034, area, 1, c2o_bfb68c, 2, OpU5_unknown7d1d30, 0, -1, 0);
			if (c2o_d28ccc != c2o_d2f184)
				c2o_cec10c->input->c2o_setText(c2o_d28ccc);
			vector<int> v;
			v.push_back(0x2c);
			c2o_cec10c->input->c2o_setUnknown98(v);
			c2o_cec10c->input->c2o_setUnknownA9(true);
		}
		else if (!text.empty())
		{
			c2o_d28ccc = text;
			if (c2o_d28ccc.size() < c2o_d035d0)
				c2o_padRight(c2o_d28ccc, c2o_d035d0, '_');
			C2O_REFRESH;
		}
		break;
	case 26:
		c2o_d28d04 = !c2o_d28d04;
		C2O_REFRESH;
		break;
	case 27:
		if (button)
		{
			C2OPos p(optionValues[selected]->c2o_getPos(), 0, 1);
			C2ORect area;
			area.x = p.x;
			area.y = p.y;
			area.w = c2o_d035d4 + 4;
			area.h = 4;
			new C2OType(c2o_cec034, area, 0, c2o_bfb698, 2, OpU5_unknown7d1d30, 0, -1, 0);
			if (c2o_d28ce8 != c2o_bfb6a4)
				c2o_cec10c->input->c2o_setText(c2o_d28ce8);
			vector<int> v;
			v.push_back(0x2c);
			c2o_cec10c->input->c2o_setUnknown98(v);
		}
		else
		{
			string old(c2o_d28ce8);
			if (text.empty() || c2o_toUpper(text) == c2o_bfb6a8)
				c2o_d28ce8 = c2o_bfb6b0;
			else
				c2o_d28ce8 = text;
			if (c2o_d28ce8 != old)
				pending = 0x1b;
			C2O_REFRESH;
		}
		break;
	case 28:
		c2o_d28d05 = !c2o_d28d05;
		C2O_REFRESH;
		break;
	case 29:
		c2o_d28d06 = !c2o_d28d06;
		C2O_REFRESH;
		break;
	case 30:
		c2o_d28d07 = !c2o_d28d07;
		C2O_REFRESH;
		break;
	case 23:
		c2o_d28d28 = !c2o_d28d28;
		C2O_REFRESH;
		break;
	case 24:
		if (button)
		{
			vector<string> options;
			options.push_back(intToString(0));
			options.push_back(intToString(500));
			options.push_back(intToString(750));
			options.push_back(intToString(1000));
			options.push_back(intToString(1500));
			c2o_menu(c2o_bfb6b4, options, 0);
		}
		else
		{
			c2o_d28d2c = stringToInt(text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 31:
		if (!c2o_d28d30 && c2o_d223f0.c2o_f4189e0() <= 10)
			c2o_logPhrase(0xdb, &intToString(c2o_d223f0.c2o_f4189e0()), 0, 0, C2OHE(), C2OHE(), 0);
		else
		{
			c2o_cefaa8->c2o_f78d700(0, 0);
			C2O_REFRESH;
		}
		break;
	case 32:
		c2o_d28d31 = !c2o_d28d31;
		C2O_REFRESH;
		break;
	case 33:
		c2o_d28d32 = !c2o_d28d32;
		C2O_REFRESH;
		break;
	case 34:
		if (button)
		{
			vector<string> options;
			options.push_back(intToString(0));
			options.push_back(intToString(1));
			options.push_back(intToString(500));
			options.push_back(intToString(1000));
			options.push_back(intToString(1500));
			options.push_back(intToString(2000));
			options.push_back(intToString(3000));
			c2o_menu(c2o_bfb6c8, options, 0);
		}
		else
		{
			c2o_d28d34 = stringToInt(text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 35:
		c2o_d28d38 = !c2o_d28d38;
		C2O_REFRESH;
		break;
	case 36:
		c2o_d28d39 = !c2o_d28d39;
		C2O_REFRESH;
		break;
	case 37:
		c2o_d28d3a = !c2o_d28d3a;
		C2O_REFRESH;
		break;
	case 38:
		c2o_d28d3b = !c2o_d28d3b;
		C2O_REFRESH;
		break;
	case 39:
		c2o_d28d3c = !c2o_d28d3c;
		C2O_REFRESH;
		break;
	case 40:
		if (button)
		{
			vector<string> options;
			options.push_back(intToString(0));
			options.push_back(intToString(500));
			options.push_back(intToString(1000));
			options.push_back(intToString(1500));
			options.push_back(intToString(2000));
			c2o_menu(c2o_bfb6d8, options, 0);
		}
		else
		{
			c2o_d28d40 = stringToInt(text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 41:
		if (button)
		{
			vector<string> options;
			for (int i = 0; i < 4; i++)
				options.push_back(c2o_bfb6ec + intToString(i));
			c2o_menu(c2o_bfb6f0, options, 0);
		}
		else
		{
			c2o_d28d44 = stringToInt(text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 42:
		if (button)
		{
			vector<string> options;
			for (int i = 0; i < 3; i++)
				options.push_back(c2o_d39718[i]);
			c2o_menu(c2o_bfb700, options, 0);
		}
		else
		{
			c2o_d28d48 = c2o_findStringIndex(c2o_d39718, 3, text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 43:
		c2o_d28d4c = !c2o_d28d4c;
		C2O_REFRESH;
		break;
	case 44:
		c2o_d28d4d = !c2o_d28d4d;
		C2O_REFRESH;
		break;
	case 45:
		if (button)
		{
			vector<string> options;
			for (int v = 100; v <= 1000; v += 100)
				options.push_back(intToString(v));
			c2o_menu(c2o_bfb70c, options, 0);
		}
		else
		{
			c2o_d28d50 = stringToInt(text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 46:
		if (button)
		{
			vector<string> options;
			for (int v = 10; v <= 100; v += 10)
				options.push_back(intToString(v));
			c2o_menu(c2o_bfb718, options, 0);
		}
		else
		{
			c2o_d28d54 = stringToInt(text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 47:
		if (button)
		{
			vector<string> options;
			for (int v = 10; v <= 100; v += 10)
				options.push_back(intToString(v));
			c2o_menu(c2o_bfb728, options, 0);
		}
		else
		{
			c2o_d28d58 = stringToInt(text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 48:
		if (button)
		{
			vector<string> options;
			for (int v = 10; v <= 100; v += 10)
				options.push_back(intToString(v));
			c2o_menu(c2o_bfb73c, options, 0);
		}
		else
		{
			c2o_d28d5c = stringToInt(text);
			c2o_delay();
			C2O_REFRESH;
		}
		break;
	case 49:
		c2o_d28d60 = !c2o_d28d60;
		C2O_REFRESH;
		break;
	}
}
