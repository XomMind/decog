// team_d_115: console update 0x7f5170 (caller CMap::update): a small list panel under the map that shows four
// titled groups of item names. It hides itself while other overlays are up, follows the map's bottom edge in
// one layout mode, and when dirty resizes to fit its contents and redraws them.
// NOTE: class layouts are partial; names are placeholders. Local names follow the stack-slot hash order.
#include <string>
#include <vector>
using namespace std;

int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &c);
};
extern XColor &back115_cfe674;		// NOTE: placeholder name
extern XColor &title115_d2175c;		// NOTE: placeholder name
extern XColor &text115_d2981c;		// NOTE: placeholder name

struct Pos
{
	int x;
	int y;

	Pos(const Pos &p);
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);

	bool isHidden();
	void setHidden(bool hidden);
	Pos getPos();
	void setPos(int x, int y);
	int getWidth115();	// NOTE: placeholder name (folded getter Wrapper_44b0d0::cleanup)
	int getHeight();
	void clear();
	void resetBack_418450();	// NOTE: placeholder name
	void setBack(XColor color);
	void setFore(XColor color);
	void setUnknown115(int value);	// NOTE: placeholder name (folded setter, 0x451400)
	void print(int x, int y, const string &text);
};
extern XConsole *console115_cec11c;	// NOTE: placeholder name
extern XConsole *console115_cec0f8;	// NOTE: placeholder name

class MapFine115	// NOTE: placeholder name (CMapFine at 0xcec058)
{
public:
	bool hasBubbles();
	int getBottom_49c210();	// NOTE: placeholder name
};
extern MapFine115 *mapFine115_cec058;	// NOTE: placeholder name

class Queue115	// NOTE: placeholder name (0xcec0c4)
{
public:
	bool hasItems();
};
extern Queue115 *queue115_cec0c4;	// NOTE: placeholder name

class ItemRecord115	// NOTE: placeholder name (see team_d_113)
{
public:
	string getName(int amount, int style);
};
extern vector<ItemRecord115 *> itemRecords115_d2d1c4;	// NOTE: placeholder name
extern vector< vector<int> > groups115_cf4a58;	// NOTE: placeholder name
extern string titles115_d378d0[];	// NOTE: placeholder name
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern int layout115_cebd5c;	// NOTE: placeholder name

class Panel115 : public XConsole	// NOTE: placeholder name and layout
{
public:
	char			pad04[0x6c - 4];
	bool			dirty;		// +0x6c
	unsigned int	showTime;	// +0x70

	void update();	// NOTE: placeholder name
};

void Panel115::update()
{
	if (console115_cec11c->isHidden() && console115_cec0f8->isHidden())
		setHidden(tickCount >= showTime);
	else
		setHidden(true);
	if (mapFine115_cec058->hasBubbles() || queue115_cec0c4->hasItems())
		setHidden(true);
	if (isHidden())
		return;
	if (layout115_cebd5c == 2)
	{
		int level = mapFine115_cec058->getBottom_49c210() + 1;
		setPos(getPos().x,level);
	}
	if (dirty)
	{
		int count;
		int to;
		int n;
		int last = 4;
		for (unsigned int i = 0; i < groups115_cf4a58.size(); i++)
			last += OpX5_maxInt(1,groups115_cf4a58[i].size());
		count = 0;
		for (int c = 0; c < 4; c++)
		{
			if (titles115_d378d0[c].size() > count)
				count = titles115_d378d0[c].size() + 2;
			for (unsigned int j = 0; j < groups115_cf4a58[c].size(); j++)
			{
				to = itemRecords115_d2d1c4[groups115_cf4a58[c][j]]->getName(0,0).size() + 3;
				if (to > count)
					count = to;
			}
		}
		if (getWidth115() != count || getHeight() != last)
			resize(count,last);
		clear();
		resetBack_418450();
		setBack(back115_cfe674);
		setUnknown115(1);
		string msg;
		n = 0;
		for (int k = 0; k < 4; k++)
		{
			msg = " " + titles115_d378d0[k] + " ";
			setFore(title115_d2175c);
			print(0,n,msg);
			n++;
			if (groups115_cf4a58[k].empty())
			{
				msg = "  - ";
				print(0,n,msg);
				n++;
			}
			else
			{
				setFore(text115_d2981c);
				for (unsigned int m = 0; m < groups115_cf4a58[k].size(); m++)
				{
					msg = "  " + itemRecords115_d2d1c4[groups115_cf4a58[k][m]]->getName(0,0) + " ";
					print(0,n,msg);
					n++;
				}
			}
		}
		dirty = false;
	}
}
