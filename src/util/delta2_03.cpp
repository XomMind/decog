// CRobot::CRobot (exe 0x9450f0): robot hacking console constructor.
// NOTE: class is declared here as D2Robot (placeholder name) so this TU's vtable/dtor COMDATs do not
//	collide with op_r5e.cpp's partial CRobot; layouts are partial, member names are placeholders.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos) throw();
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color) throw();
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;
	Rect(int x_, int y_, int width_, int height_);
	Rect(const Rect &rect) throw();	// 0x40a720
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();

	Pos getPos();
	int getWidth();	// 0x44b0d0
	void setHidden(bool hidden_);

	char pad04[0x60 - 0x04];
};

class ConsoleTitle;

class Console : public XConsole
{
public:
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);
	void drawFrame(Rect *area, XColor color, bool thin, bool lines);	// NOTE: placeholder name
	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown48c3c0(int value);	// NOTE: placeholder name

	int unknown60;
	void *engine;
	void *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);
	char pad6c[0x8c - 0x6c];
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);
	char pad6c[0x88 - 0x6c];
};

class CCloseButton : public Console
{
public:
	CCloseButton(XConsole *parent, const XColor &color, int x);
	char pad6c[0x8c - 0x6c];
};

class D2Item
{
public:
	int value45cb30();	// NOTE: placeholder name (ICF'd getter 0x44b0f0 family)
};

class HItem
{
public:
	int ID;
	D2Item *operator->() const;	// 0x9b65b0
};

class D2Entity
{
public:
	const string &name();	// NOTE: placeholder name (ICF'd getter)
	int unknown5d47c0(class HEntity entity, vector<HItem> *a, vector<HItem> *b);	// NOTE: placeholder name
};

class HEntity
{
public:
	int ID;
	D2Entity *operator->() const;	// 0x9b6570
};

class D2Map	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();
};
extern D2Map *d2r_cefc4c;

class D2GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	const string &getEntryText(const string &key);
};
extern D2GameData d2r_d1e860;

class D2Graph	// NOTE: placeholder name (0xcefa8c)
{
public:
	void pushFrame(int a, XConsole *console, int c, bool d);
};
extern D2Graph *d2r_cefa8c;

class D2GM	// NOTE: placeholder name (0xcefaa8)
{
public:
	void showOnce(int type, bool a, int b, int c, int d);
};
extern D2GM *d2r_cefaa8;

class D2Robot;

class CRobotTarget : public Console
{
public:
	CRobotTarget(XConsole *parent, int y, bool unknown6c_, int unused, int type_, int unknown78_, int unknown74_);	// op_w7.cpp
	char pad6c[0x80 - 0x6c];
};

class D2Robot : public Console
{
public:
	D2Robot(XConsole *parent, const Rect &rect, HEntity entity, vector<int> hacks);
	virtual bool input(void *event);
	virtual void inputMouse(int a, int b);
	virtual void close();

	unsigned int unknown6c;
	CCloseButton *closeButton;
	HEntity entity;
	vector<int> hacks;
	vector<CRobotTarget*> targets;
	vector<HItem> unknown98;
	vector<HItem> unknowna8;
	void *manual;
	unsigned int unknownbc;
	unsigned int unknownc0;
};

extern D2Robot *d2r_cec108;
extern XColor *d2r_cfe674;
extern XColor *d2r_cf1f2c;
extern int d2r_cef9b0, d2r_cef9b4, d2r_cef9d0, d2r_cef9d4;
extern int d2r_b97d38[];
extern string d2r_cfc460[];
extern bool d2r_d28ea4;
extern vector<int> d2r_rifLevels_cf4a04;

string opr5f_unknown954490(HEntity entity);
void OpW7_loadRobotAnimations();
bool OpS8b_Fn9d51d0(vector<int> &list, int value);
void d2r_insertAt(vector<int> &list, int index, int value);
int stringToInt(const string &text);
string intToString(int value);
bool isOdd_406340(int value);
void logError(string location, string message);
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);
int opR1d_454200(unsigned int sound, unsigned int channel, int loopsB, int loops);

D2Robot::D2Robot(XConsole *parent, const Rect &rect, HEntity entity, vector<int> hacks)
	: Console(parent, rect, 0, false, 10), entity(entity), hacks(hacks), manual(NULL), unknownbc(0), unknownc0(0)
{
	d2r_cec108 = this;
	string name = "\\ " + opr5f_unknown954490(this->entity) + " \\";
	setTitle(new ConsoleTitle(this, name, 0, 2));
	OpW7_loadRobotAnimations();

	vector<int> list;
	int y = 2;
	Console *node;
	int choice = 'a';
	string buffer;
	CText *label;
	bool flag;
	for (unsigned int i = 0; i < this->hacks.size(); i++)
	{
		if (d2r_b97d38[this->hacks[i]] == -1)
			list.push_back(this->hacks[i]);
	}
	if (!list.empty())
	{
		if (OpS8b_Fn9d51d0(list, 0))
			d2r_insertAt(list, 0, 0);
		node = new Console(this, Rect(0, y - 1, getWidth(), list.size() + 2), 0, false, -1);
		node->drawFrame(NULL, *d2r_cfe674, true, false);
		node->unknown48c3c0(d2r_cef9b4);
		buffer = " Basic ";
		label = new CText(node, Pos(node->getWidth() - 2 - buffer.size(), 0), buffer, 0, 0, -1);
		label->unknown48c3c0(d2r_cef9d0);
		for (unsigned int i = 0; i < list.size(); i++, y++, choice++)
			targets.push_back(new CRobotTarget(this, y, false, this->entity.ID, list[i], choice, 0));
		list.clear();
		y += 2;
	}
	for (unsigned int i = 0; i < this->hacks.size(); i++)
	{
		if (d2r_b97d38[this->hacks[i]] == 0)
			list.push_back(this->hacks[i]);
	}
	if (!list.empty())
	{
		node = new Console(this, Rect(0, y - 1, getWidth(), list.size() + 2), 0, false, -1);
		node->drawFrame(NULL, *d2r_cfe674, true, false);
		node->unknown48c3c0(d2r_cef9b4);
		flag = stringToInt(d2r_d1e860.getEntryText("installedRif_g"));
		buffer = flag ? " RIF " : " RIF Required ";
		label = new CText(node, Pos(node->getWidth() - 2 - buffer.size(), 0), buffer, 0, 0, -1);
		label->unknown48c3c0(flag ? d2r_cef9d0 : d2r_cef9d4);
		for (unsigned int i = 0; i < list.size(); i++, y++, choice++)
			targets.push_back(new CRobotTarget(this, y, false, this->entity.ID, list[i], choice, 0));
		list.clear();
		y += 2;
	}
	for (unsigned int i = 0; i < this->hacks.size(); i++)
	{
		if (d2r_b97d38[this->hacks[i]] > 0)
			list.push_back(this->hacks[i]);
	}
	if (!list.empty())
	{
		vector<int> copy(list);
		list.clear();
		list.push_back(copy.front());
		if (d2r_d28ea4)
		{
			for (unsigned int i = 1; i < copy.size(); i++)
			{
				if (!lexicographical_compare(((const string &)d2r_cfc460[copy[i]]).begin(), ((const string &)d2r_cfc460[copy[i]]).end(), ((const string &)d2r_cfc460[list.back()]).begin(), ((const string &)d2r_cfc460[list.back()]).end()))
					list.push_back(copy[i]);
				else
				{
					for (unsigned int j = 0; j < list.size(); j++)
					{
						if (lexicographical_compare(((const string &)d2r_cfc460[copy[i]]).begin(), ((const string &)d2r_cfc460[copy[i]]).end(), ((const string &)d2r_cfc460[list[j]]).begin(), ((const string &)d2r_cfc460[list[j]]).end()))
						{
							d2r_insertAt(list, j, copy[i]);
							break;
						}
					}
				}
			}
		}
		else
		{
			for (unsigned int i = 1; i < copy.size(); i++)
			{
				if (d2r_b97d38[copy[i]] < d2r_b97d38[list.front()])
					d2r_insertAt(list, 0, copy[i]);
				else
				{
					for (int j = list.size() - 1; j >= 0; j--)
					{
						if (d2r_b97d38[copy[i]] >= d2r_b97d38[list[j]])
						{
							d2r_insertAt(list, j + 1, copy[i]);
							break;
						}
					}
				}
			}
		}
		node = new Console(this, Rect(0, y - 1, getWidth(), list.size() + 2), 0, false, -1);
		node->drawFrame(NULL, *d2r_cfe674, true, false);
		node->unknown48c3c0(d2r_cef9b4);
		flag = d2r_cefc4c->getPlayer()->unknown5d47c0(this->entity, &unknown98, &unknowna8) ;
		int total = 0;
		if (flag)
		{
			for (unsigned int i = 0; i < unknown98.size(); i++)
				total += unknown98[i]->value45cb30();
			if (d2r_rifLevels_cf4a04[4])
			{
				for (unsigned int i = 0; i < unknowna8.size(); i++)
					total += unknowna8[i]->value45cb30();
			}
		}
		buffer = flag ? " Coupler  " + intToString(total) + " " : string(" Coupler Required ");
		label = new CText(node, Pos(node->getWidth() - 2 - buffer.size(), 0), buffer, 0, 0, -1);
		label->unknown48c3c0(flag ? d2r_cef9d0 : d2r_cef9d4);
		if (flag)
		{
			string count = " " + intToString(total) + " ";
			label = new CText(node, Pos(label->getPos().x + label->getWidth() - count.size(), 0), count, 0, 0, -1);
			label->unknown48c3c0(d2r_cef9b0);
		}
		for (unsigned int i = 0; i < list.size(); i++, y++, choice++)
			targets.push_back(new CRobotTarget(this, y, isOdd_406340(i), this->entity.ID, list[i], choice, total));
		y += 2;
	}
	y -= 1;
	if (choice == 'z')
		logError("CRobot()", "Hacking " + this->entity->name() + " has too many options");
	if (targets.empty())
		y = 1;
	targets.push_back(new CRobotTarget(this, y, false, this->entity.ID, 0x49, 'z', 0));
	animate("CRobot_Border");
	opR1d_4541b0(0x67, 0, 0);
	opR1d_454200(0x68, 0xd, 0, -1);
	d2r_cefa8c->pushFrame(0xe, this, 0xff, false);
	unknown60 = 1;
	closeButton = new CCloseButton(this, *d2r_cf1f2c, 0xe);
	closeButton->setHidden(false);
	d2r_cefaa8->showOnce(0x38, true, 0, 0, 0);
}
