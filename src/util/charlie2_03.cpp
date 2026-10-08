// CAchievements::inputAscii (0x7eed40): category/state hotkeys, toggle-all, and txt/html/csv export.
// NOTE: placeholder names and layouts (C2A*); vector views are stubs that pair with the exe's folded STL bodies.
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct C2AState	// NOTE: placeholder layout (per-achievement unlock record)
{
	int index;
	char p04[0x1c];
	int f20;
	int f24;
	int f28;
	int f2c;
	string getPadded4675b0();
};
struct C2ARec	// NOTE: placeholder layout (achievement definition)
{
	char p00[0x20];
	string name;
	char p3c[4];
	int category;
	char p44[4];
	bool secret;
	char p49[7];
	string desc;
};
struct C2AIntVec { int pad[4]; unsigned size() const; int &operator[](unsigned i); bool empty() const; };
struct C2AStateVec { int pad[4]; C2AState *&operator[](unsigned i); };
struct C2ARecVec { int pad[4]; unsigned size() const; C2ARec *&operator[](unsigned i); };
struct C2AButton { void hoverBegin496e60(); };
struct C2AButtonVec { int pad[4]; C2AButton *&operator[](unsigned i); };
struct C2AExport { char p00[0x6c]; C2AButtonVec buttons; };
struct C2AToggle { void set7ed4f0(int mode); };
struct C2APanel
{
	char p00[0x7c];
	C2AToggle *toggleAll;
	C2AIntVec primaryButtons;
	C2AIntVec secondaryButtons;
	void setPrimaryState(int s);
	void setSecondaryState(int s);
};
struct C2AProgress { int percent46c930(); int countInCategory46c970(int c); };
struct C2APlayer { string getName4b98a0(); };
struct C2AMessages { void message498470(string &s); };

class CAchievements	// NOTE: placeholder layout
{
public:
	char p00[0x70];
	C2AStateVec states;	// +0x70
	C2AIntVec listed;	// +0x80
	char p90[0xa4 - 0x90];
	C2APanel *panel;	// +0xa4
	char pa8[0xb0 - 0xa8];
	C2AExport *exportConsole;	// +0xb0

	void unknown7f1bd0(int count, int start, bool flag);
	void unknown7f1e00(int category, bool flag);
	void unknown7f1120();
	void inputAscii(int key, int modifier);
};

bool c2a_contains9d43b0(int *list, unsigned n, int v);
string c2a_date436e70(bool b, __int64 t);
string intToString(int v);
string &c2a_padLeft408090(string &s, int width, char c);
void logError(string location, string message);
bool c2a_hasPtr4328a0();

extern int c2a_bcabc4[], c2a_bcbe24[];
extern string c2a_cfd42c;
extern string c2a_d2e8f8[], c2a_d15db0[], c2a_d20af8[], c2a_d304d0[];
extern C2ARecVec c2a_cf09a8;
extern C2AIntVec c2a_cf08d4;
extern C2AProgress c2a_d25628;
extern C2APlayer c2a_d28c68;
extern C2AMessages *c2a_cec048;
extern int c2a_d28d84, c2a_d28d88;
extern vector<bool> c2a_d28d70;

extern const char c2a_bfd69c[], c2a_bfd688[], c2a_bfd6a4[], c2a_bfd6ac[], c2a_bfd6b4[],
	c2a_bfd6bc[], c2a_bfd6c0[], c2a_bfd6c4[], c2a_bfd6cc[], c2a_bfd6dc[], c2a_bfd6e0[], c2a_bfd6f4[],
	c2a_bfd6f8[], c2a_bfd6fc[], c2a_bfd700[], c2a_bfd704[], c2a_bfd708[], c2a_bfd70c[], c2a_bfd710[],
	c2a_bfd714[], c2a_bfd718[], c2a_bfd71c[], c2a_bfd720[], c2a_bfd724[], c2a_bfd728[], c2a_bfd72c[],
	c2a_bfd730[], c2a_bfd734[], c2a_bfd738[], c2a_bfd73c[],
	c2a_bfd748[], c2a_bfd750[], c2a_bfd758[], c2a_bfd798[], c2a_bfd774[], c2a_bfd810[], c2a_bfd830[],
	c2a_bfd898[], c2a_bfd910[], c2a_bfd998[], c2a_bfda10[], c2a_bfda90[], c2a_bfdb08[], c2a_bfdb70[],
	c2a_bfdbe0[], c2a_bfdc50[], c2a_bfdcc0[], c2a_bfdd30[], c2a_bfdda0[], c2a_bfde10[], c2a_bfd78c[],
	c2a_bfd904[], c2a_bfd97c[], c2a_bfd984[],
	c2a_bfda04[], c2a_bfde84[], c2a_bfde8c[], c2a_bfda0c[], c2a_bfda7c[], c2a_bfde9c[], c2a_bfdafc[],
	c2a_bfdea4[], c2a_bfdea8[], c2a_bfdeb8[], c2a_bfdec0[], c2a_bfdec8[], c2a_bfded4[], c2a_bfdef0[],
	c2a_bfdf38[], c2a_bfdf40[], c2a_bfdf48[], c2a_bfdf68[], c2a_bfdfb0[], c2a_bfdfb8[], c2a_bfdfbc[],
	c2a_bfdfd0[], c2a_bfdfd4[], c2a_bfdfd8[], c2a_bfdfe8[], c2a_bfdff4[], c2a_bfe01c[], c2a_bfe00c[],
	c2a_bfe020[], c2a_bfe048[], c2a_bfe054[],
	c2a_bfe060[], c2a_bfe09c[], c2a_bfe0a0[], c2a_bfe0a4[], c2a_bfe0a8[], c2a_bfe0ac[], c2a_bfe0b0[],
	c2a_b9640a[], c2a_bfe0b4[], c2a_bfe0b8[], c2a_bfe0bc[], c2a_b9640b[], c2a_bfe0c0[], c2a_bfe0c4[],
	c2a_bfe0c8[], c2a_bfe0d4[], c2a_b9640f[], c2a_bfe0cc[], c2a_bfe0d0[], c2a_bfe0d8[], c2a_b96413[],
	c2a_bfe0dc[], c2a_bfe0e0[], c2a_bfe0e4[], c2a_bfe0f0[], c2a_bfe0e8[], c2a_bfe0ec[], c2a_bfe0f4[],
	c2a_bfe0f8[], c2a_bfe0fc[], c2a_bfe120[], c2a_bfe150[];

void CAchievements::inputAscii(int key, int modifier)
{
	switch (modifier)
	{
	case 0:
	case 1:
		if (c2a_contains9d43b0(c2a_bcabc4, 3, key))
		{
			string name = c2a_cfd42c + c2a_bfd69c + c2a_bfd688 + c2a_date436e70(true, 0);
			switch (key)
			{
			case 'T': name += c2a_bfd6a4; break;
			case 'H': name += c2a_bfd6ac; break;
			case 'C': name += c2a_bfd6b4; break;
			}
			ofstream output(name.c_str(), ios::out | ios::trunc);
			if (output.is_open())
			{
				C2AState *current;
				int group = 6;
				switch (key)
				{
				case 'T':
				{
					output << c2a_d28c68.getName4b98a0() << c2a_bfd6e0 << c2a_date436e70(true, 0) << c2a_bfd6dc
						<< intToString(c2a_d25628.percent46c930()) << c2a_bfd6cc << listed.size() << c2a_bfd6c4
						<< c2a_cf09a8.size() << c2a_bfd6c0 << c2a_bfd6bc;
					output << c2a_bfd6f4;
					for (int i = 0; i < 6; i++)
					{
						int count = c2a_d25628.countInCategory46c970(i);
						string title = c2a_d2e8f8[i];
						output << c2a_padLeft408090(title, 10, ' ') << c2a_bfd704 << count << c2a_bfd700
							<< c2a_cf08d4[i] << c2a_bfd6fc << count * 100 / c2a_cf08d4[i] << c2a_bfd6f8;
					}
					output << c2a_bfd708;
					for (unsigned j = 0; j < listed.size(); j++)
					{
						current = states[listed[j]];
						if (c2a_d28d88 == 3 && c2a_cf09a8[listed[j]]->category != group)
						{
							group = c2a_cf09a8[listed[j]]->category;
							if (j != 0)
								output << c2a_bfd70c;
							output << c2a_bfd714 << c2a_d2e8f8[group] << c2a_bfd710;
							for (unsigned k = 0; k < c2a_d2e8f8[group].size() + 2; k++)
								output << c2a_bfd718;
							output << c2a_bfd71c;
						}
						if (current)
							output << c2a_bfd72c << current->f20 << c2a_bfd728 << c2a_cf09a8[current->index]->name
								<< c2a_bfd724 << c2a_cf09a8[current->index]->desc << c2a_bfd720;
						else
							output << c2a_bfd73c << c2a_cf09a8[listed[j]]->name << c2a_bfd738
								<< (c2a_cf09a8[listed[j]]->secret ? c2a_bfd734 : c2a_cf09a8[listed[j]]->desc) << c2a_bfd730;
					}
					exportConsole->buttons[0]->hoverBegin496e60();
					break;
				}
				case 'H':
				{
					output << c2a_bfd748;
					output << c2a_bfd750;
					output << c2a_bfd758;
					output << c2a_bfd798;
					output << c2a_bfd774;
					output << c2a_bfd810;
					output << c2a_bfd830;
					output << c2a_bfd898;
					output << c2a_bfd910;
					output << c2a_bfd998;
					output << c2a_bfda10;
					output << c2a_bfda90;
					output << c2a_bfdb08;
					output << c2a_bfdb70;
					output << c2a_bfdbe0;
					output << c2a_bfdc50;
					output << c2a_bfdcc0;
					output << c2a_bfdd30;
					output << c2a_bfdda0;
					output << c2a_bfde10;
					output << c2a_bfd78c;
					output << c2a_bfd904;
					output << c2a_bfd97c;
					output << c2a_bfd984;
					output << c2a_d28c68.getName4b98a0() << c2a_bfda7c << c2a_date436e70(true, 0) << c2a_bfda0c
						<< intToString(c2a_d25628.percent46c930()) << c2a_bfde8c << listed.size() << c2a_bfde84
						<< c2a_cf09a8.size() << c2a_bfda04;
					if (c2a_d28d88 == 3)
					{
						output << c2a_bfde9c;
						for (int i = 0; i < 6; i++)
							output << c2a_bfdea8 << c2a_d15db0[i] << c2a_bfdea4 << c2a_d2e8f8[i] << c2a_bfdafc;
						output << c2a_bfdeb8;
					}
					for (unsigned j = 0; j < listed.size(); j++)
					{
						current = states[listed[j]];
						if (c2a_d28d88 == 3 && c2a_cf09a8[listed[j]]->category != group)
						{
							group = c2a_cf09a8[listed[j]]->category;
							output << c2a_bfdec8 << c2a_d15db0[group] << c2a_bfdec0;
							output << c2a_bfded4;
							output << c2a_bfdef0;
							string title = c2a_d2e8f8[group];
							output << c2a_bfdf38 << title;
							for (int k = title.size(); k < 59; k++)
								output << c2a_bfdf40;
							output << c2a_bfdf48;
							output << c2a_bfdf68;
							output << c2a_bfdfb0;
						}
						output << c2a_bfdfbc << c2a_d15db0[c2a_cf09a8[listed[j]]->category] << c2a_bfdfb8 << c2a_cf09a8[listed[j]]->name;
						if (current)
							output << c2a_bfdfd4 << current->f20 << c2a_bfdfd0;
						if (current)
							output << c2a_bfdff4 << c2a_d15db0[c2a_cf09a8[listed[j]]->category] << c2a_bfdfe8
								<< c2a_cf09a8[listed[j]]->desc << c2a_bfdfd8;
						else
							output << c2a_bfe020 << (c2a_cf09a8[listed[j]]->secret ? c2a_bfe01c : c2a_cf09a8[listed[j]]->desc) << c2a_bfe00c;
					}
					output << c2a_bfe048;
					output << c2a_bfe054;
					exportConsole->buttons[1]->hoverBegin496e60();
					break;
				}
				case 'C':
				{
					output << c2a_bfe060;
					for (unsigned j = 0; j < listed.size(); j++)
					{
						current = states[listed[j]];
						output << c2a_bfe0a4 << c2a_d2e8f8[c2a_cf09a8[listed[j]]->category] << c2a_bfe0a0 << c2a_bfe09c;
						output << c2a_bfe0b0 << c2a_cf09a8[listed[j]]->name << c2a_bfe0ac << c2a_bfe0a8;
						output << c2a_bfe0bc << (current ? intToString(current->f20) : c2a_b9640a) << c2a_bfe0b8 << c2a_bfe0b4;
						output << c2a_bfe0c8 << (current ? current->getPadded4675b0() : c2a_b9640b) << c2a_bfe0c4 << c2a_bfe0c0;
						output << c2a_bfe0d8 << (current ? (current->f28 == -1 ? c2a_bfe0d4 : intToString(current->f28)) : c2a_b9640f)
							<< c2a_bfe0d0 << c2a_bfe0cc;
						output << c2a_bfe0e4 << (current ? intToString(current->f2c) : c2a_b96413) << c2a_bfe0e0 << c2a_bfe0dc;
						output << c2a_bfe0f4 << (current || !c2a_cf09a8[listed[j]]->secret ? c2a_cf09a8[listed[j]]->desc : c2a_bfe0f0)
							<< c2a_bfe0ec << c2a_bfe0e8;
						output << c2a_bfe0f8;
					}
					exportConsole->buttons[2]->hoverBegin496e60();
					break;
				}
				}
				c2a_cec048->message498470(c2a_bfe0fc + name);
			}
			else
				logError(c2a_bfe150, c2a_bfe120 + name);
			break;
		}
		{
			if (modifier == 0)
				key -= 32;
			for (int i = 0; i < 6; i++)
			{
				if (key == c2a_d2e8f8[i][0])
				{
					unknown7f1e00(i, true);
					return;
				}
			}
			if (!panel->primaryButtons.empty())
			{
				for (int i = 0; i < 3; i++)
				{
					if (key == c2a_d20af8[i][0])
					{
						if (c2a_d28d84 == i)
							return;
						panel->setPrimaryState(i);
						if (c2a_d28d84 == 1 && (c2a_d28d88 == 0 || c2a_d28d88 == 1))
							panel->setSecondaryState(3);
						unknown7f1120();
						unknown7f1bd0(c2a_bcbe24[c2a_hasPtr4328a0() != 0], 0, true);
						return;
					}
				}
			}
			if (!panel->secondaryButtons.empty())
			{
				for (int i = 0; i < 4; i++)
				{
					if (key == c2a_d304d0[i][0])
					{
						if (c2a_d28d88 == i)
							return;
						panel->setSecondaryState(i);
						if (c2a_d28d84 == 1 && (c2a_d28d88 == 0 || c2a_d28d88 == 1))
							panel->setPrimaryState(0);
						unknown7f1120();
						unknown7f1bd0(c2a_bcbe24[c2a_hasPtr4328a0() != 0], 0, true);
						return;
					}
				}
			}
		}
		break;
	case 2:
		if (key == '1')
		{
			int count = 0;
			for (int i = 0; i < 6; i++)
			{
				if (c2a_d28d70[i])
					count++;
			}
			if (count < 6)
			{
				for (int i = 0; i < 6; i++)
				{
					if (!c2a_d28d70[i])
						unknown7f1e00(i, false);
				}
			}
			else
			{
				for (int i = 0; i < 6; i++)
				{
					if (c2a_d28d70[i])
						unknown7f1e00(i, false);
				}
			}
			unknown7f1120();
			unknown7f1bd0(c2a_bcbe24[c2a_hasPtr4328a0() != 0], 0, true);
			panel->toggleAll->set7ed4f0(1);
		}
		break;
	}
}
