// team_c_42: Scorekeeper scoresheet stat block (0x473d20): writes one titled block of stat rows (this run plus
//	per-run history columns) into the scoresheet text
// NOTE: helper classes and globals are private placeholders; Scorekeeper layout is partial
#include <string>
#include <vector>
using namespace std;

string intToString(int value);
string &padRight_4080d0(string &text, int width, char fill);	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);
extern string gameStrings_d37ec0[];	// global_string_arrays.cpp

struct C42_StatSet { int get472440(unsigned int index); };	// NOTE: placeholder (OpR1h_StatSet)
struct C42_StatDef { char pad0[0x20]; string f20; char pad3c[0x41 - 0x3c]; bool f41; char pad42[2]; int f44; bool f48; bool f49; };	// NOTE: placeholder layout
struct C42_Loc { int f0; int f4; int f8; };	// NOTE: placeholder
class C42_HLoc { public: int ID; C42_Loc *operator->() const; };	// NOTE: placeholder
extern vector<C42_StatDef *> c42_d389c4;	// NOTE: placeholder names
extern vector<C42_HLoc> c42_d1e88c;

class Scorekeeper	// NOTE: placeholder layout (partial)
{
public:
	C42_StatSet *f0;
	vector<C42_StatSet *> f4;

	int delegate(int index);	// NOTE: placeholder name
	void c32_writeStatBlock_473d20(string *sheet, string title, int first, int last, bool flag);
};

void Scorekeeper::c32_writeStatBlock_473d20(string *sheet, string title, int first, int last, bool flag)
{
	bool allies = false;
	int center = 4;
	int adj = 3;
	for (int cols = first; cols <= last; cols++)
	{
		center = OpX5_maxInt(center,intToString(f0->get472440(cols)).size());
		if (c42_d389c4[cols]->f41)
		{
			allies = true;
			for (unsigned int current = 0; current < f4.size(); current++)
			{
				if (c42_d389c4[cols]->f41)
					adj = OpX5_maxInt(adj,intToString(f4[current]->get472440(cols)).size());
			}
		}
	}
	center++;
	adj++;
	if (allies)
	{
		*sheet += padRight_4080d0(" " + string(title),27,32) + padRight_4080d0(string(" "),center,32) + "| ";
		for (unsigned int cols = 0; cols < c42_d1e88c.size(); cols++)
			*sheet += padRight_4080d0(intToString(-c42_d1e88c[cols]->f8),adj,32);
	}
	else
		*sheet += " " + title;
	*sheet += "\n";
	if (allies)
	{
		*sheet += padRight_4080d0(string(title.size() + 2,'-'),27,32) + padRight_4080d0(string("Run"),center,32) + "| ";
		for (unsigned int current = 0; current < c42_d1e88c.size(); current++)
			*sheet += padRight_4080d0(string(gameStrings_d37ec0[c42_d1e88c[current]->f4]),adj,32);
	}
	else
		*sheet += string(title.size() + 2,'-');
	*sheet += "\n";
	string col;
	int begin = 0;
	for (int cols = first; cols <= last; cols++)
	{
		if (delegate(cols) == 0 && c42_d389c4[cols]->f48)
			continue;
		begin++;
		if (c42_d389c4[cols]->f44 != 0)
		{
			col.clear();
			for (int current = 0; current < c42_d389c4[cols]->f44; current++)
				col += "  ";
			col += c42_d389c4[cols]->f20;
		}
		else
			col = c42_d389c4[cols]->f20;
		padRight_4080d0(col,27,32);
		if (c42_d389c4[cols]->f49)
			*sheet += col + "\n";
		else
		{
			int distanceSq = delegate(cols);
			if (c42_d389c4[cols]->f41)
			{
				*sheet += col + padRight_4080d0(distanceSq != 0 ? intToString(distanceSq) : string("."),center,32) + "| ";
				for (unsigned int distances = 0; distances < f4.size(); distances++)
				{
					int enemies = f4[distances]->get472440(cols);
					if (enemies != 0)
						*sheet += padRight_4080d0(intToString(enemies),adj,32);
					else
						*sheet += padRight_4080d0(string("."),adj,32);
				}
				*sheet += "\n";
			}
			else
				*sheet += col + (distanceSq != 0 ? intToString(distanceSq) : string(".")) + "\n";
		}
	}
	if (begin == 0)
		*sheet += "None\n";
	if (!flag)
		*sheet += "\n";
}
