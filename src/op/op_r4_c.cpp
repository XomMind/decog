// op_r4_c: CAchievements / CSupporters consoles and map/effect logic in 0x7ee000-0x828000, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <ostream>
#include <algorithm>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
	Pos(const Pos &pos);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
};

class Console;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	int getWidth() throw();
	int getHeight() throw();
	XConsole *getParent();	// NOTE: placeholder name
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBack_417fc0(int x, int y, XColor color, int flag) throw();	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	void setPos(int x, int y);
	bool isHidden();	// NOTE: placeholder name
	bool input429d00(void *event);	// NOTE: placeholder name (XConsole::input body)
	void updateBase429e30();	// NOTE: placeholder name (XConsole::update body)

	char pad4[0x5c];
};

class Engine
{
public:
	void stopAll();	// NOTE: placeholder name
	char data[0x58];
};


class Engine2	// NOTE: placeholder name
{
public:
	bool update();	// NOTE: placeholder name (0x50fff0)
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer) throw();
	virtual ~Console();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	void animate(string name);	// NOTE: placeholder name

	int unknown60;
	Engine2 *engine;
	void *title;
};

string intToString(int value);	// NOTE: placeholder name
bool unknown4328a0();	// NOTE: placeholder name
extern bool opr4c_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)
int minInt(int a, int b);	// 0x9cdb30
int opr4c_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
template <class T> void opr4c_eraseRange(vector<T> &v, int first, int last);	// NOTE: placeholder name (0x9e25a0)
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0
class CAchievementsEntry;
void opr4c_insertAt(vector<CAchievementsEntry*> &v, int index, CAchievementsEntry *value);	// NOTE: placeholder name (0x9dbdc0)
extern int opr4c_bcbe24[];	// NOTE: placeholder name
extern int opr4c_bcbe2c[];	// NOTE: placeholder name
extern int opr4c_bcbe34[];	// NOTE: placeholder name

class UiM : public XConsole	// NOTE: placeholder name (global at 0xcec03c)
{
public:
	void unknown4968e0();	// NOTE: placeholder name
};
extern UiM *unknown_cec03c;	// NOTE: placeholder name

class KeyMapX	// NOTE: placeholder name (global at 0xcefa8c)
{
public:
	void unknown416640();	// NOTE: placeholder name
};
extern KeyMapX *unknown_cefa8c;	// NOTE: placeholder name

//==================================================================
// CAchievements
//==================================================================

class CAchievementsEntry : public Console	// NOTE: placeholder name (0x74 bytes)
{
public:
	CAchievementsEntry(XConsole *parent, int x, int y, void *record_, int index_);	// 0x7edf90

	int unknown6c;
	int unknown70;
};

class CAchievements : public Console
{
public:
	virtual ~CAchievements();
	virtual bool input(void *event);
	virtual void update();

	void unknown7eeb50();	// NOTE: placeholder name
	void unknown7f0d10(int value);	// NOTE: placeholder name
	void unknown7f1bd0(int count, int start, bool flag);	// NOTE: placeholder name

	int unknown6c;
	vector<int> unknown70;
	vector<void*> unknown80;
	vector<CAchievementsEntry*> unknown90;
	int unknowna0;
	XConsole *unknowna4;
	XConsole *unknowna8;
	XConsole *unknownac;
	XConsole *unknownb0;
	XConsole *unknownb4;
};

void CAchievements::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
	case 1:
		unknown7f1bd0(opr4c_bcbe24[unknown4328a0() != 0],0,true);
		unknown60 = 3;
	case 3:
		engine->update();
		break;
	default:
		break;
	}
	updateBase429e30();
}

bool CAchievements::input(void *event)
{
	if (isHidden() || opr4c_consoleInputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (*(int*)event)
	{
	case 0x27:
		unknown7f0d10(2);
		return true;
	case 0x28:
		unknown7f0d10(-2);
		return true;
	case 0x29:
		unknown7f0d10(opr4c_bcbe34[unknown4328a0() != 0] * 2);
		return true;
	case 0x2a:
		unknown7f0d10(-opr4c_bcbe34[unknown4328a0() != 0] * 2);
		return true;
	case 0x2b:
		unknown7f0d10(-10000);
		return true;
	case 0x2c:
		unknown7f0d10(10000);
		return true;
	case 0x2d:
		unknown7eeb50();
		return true;
	}
	return false;
}

void CAchievements::unknown7eeb50()
{
	unknown_cec03c->removeSubconsole(unknowna4);
	unknown_cec03c->removeSubconsole(unknowna8);
	unknown_cec03c->removeSubconsole(unknownac);
	unknown_cec03c->removeSubconsole(unknownb0);
	if (unknownb4)
		unknown_cec03c->removeSubconsole(unknownb4);
	unknown_cec03c->unknown4968e0();
	unknown60 = 0;
	unknown_cefa8c->unknown416640();
	getParent()->removeSubconsole(this);
}

void CAchievements::unknown7f0d10(int value)
{
	if (value == 0 || unknown90.empty())
		return;
	int first = unknown90.front()->unknown70;
	if (value < 0)
	{
		value = -value;
		if (first == 0)
			return;
		if (first - value < 0)
			value = first;
		if (value >= opr4c_bcbe24[unknown4328a0() != 0])
		{
			for (unsigned int i = 0; i < unknown90.size(); i++)
			{
				if (unknown90[i])
					removeSubconsole(unknown90[i]);
			}
			unknown90.clear();
			first = opr4c_maxInt(0,first - value);
			unknown7f1bd0(opr4c_bcbe24[unknown4328a0() != 0],first,true);
		}
		else
		{
			int a = opr4c_bcbe24[unknown4328a0() != 0] - value;
			for (unsigned int j = a; j < unknown90.size(); j++)
				removeSubconsole(unknown90[j]);
			opr4c_eraseRange(unknown90,a,unknown90.size() - 1);
			first -= value;
			unknown7f1bd0(value,first,true);
		}
	}
	else
	{
		if (unknown90.back()->unknown70 == unknown80.size() - 1)
			return;
		if (first + value >= (int)unknown80.size() - opr4c_bcbe24[unknown4328a0() != 0])
			value -= first + value - ((int)unknown80.size() - opr4c_bcbe24[unknown4328a0() != 0]);
		if (value >= opr4c_bcbe24[unknown4328a0() != 0])
		{
			for (unsigned int k = 0; k < unknown90.size(); k++)
			{
				if (unknown90[k])
					removeSubconsole(unknown90[k]);
			}
			unknown90.clear();
			first = minInt(unknown80.size() - opr4c_bcbe24[unknown4328a0() != 0],first + value);
			unknown7f1bd0(opr4c_bcbe24[unknown4328a0() != 0],first,false);
		}
		else
		{
			for (int m = 0; m < value; m++)
			{
				removeSubconsole(unknown90.front());
				removeVectorElement(unknown90,0);
			}
			first = unknown90.size() + value + first;
			unknown7f1bd0(value,first,false);
		}
	}
}

void CAchievements::unknown7f1bd0(int count, int start, bool flag)
{
	int i = 0;
	unsigned int index = start;
	int row;
	int c2;
	int px;
	unsigned int k;
	int yy;
	for (; i < count && index < unknown80.size(); index++, i++)
	{
		if (flag)
			opr4c_insertAt(unknown90,i,new CAchievementsEntry(this,0,0,unknown80[index],index));
		else
			unknown90.push_back(new CAchievementsEntry(this,0,0,unknown80[index],index));
	}
	k = 0;
	c2 = 0;
	row = 0;
	px = 2;
	yy = opr4c_bcbe2c[unknown4328a0() != 0];
	for (; k < unknown90.size(); k++)
	{
		unknown90[k]->setPos(px,yy);
		c2++;
		px = 0x3a;
		if (c2 == 2)
		{
			c2 = 0;
			px = 2;
			row++;
			yy += 6;
		}
	}
}

//==================================================================
// CSupporters
//==================================================================

class OpR4c_Rex	// NOTE: placeholder name (object at 0xd223f0)
{
public:
	int getHeight_4189a0();	// NOTE: placeholder name
};
extern OpR4c_Rex opr4c_rex;	// NOTE: placeholder name

class CSupporters : public Console
{
public:
	virtual ~CSupporters();
	virtual bool input(void *event);

	void unknown7f2f60();	// NOTE: placeholder name
	void unknown7f30e0(int offset);	// NOTE: placeholder name
	int unknown7f3790();	// NOTE: placeholder name
	int unknown7f37b0();	// NOTE: placeholder name

	char pad6c[0x98 - 0x6c];
	XConsole *unknown98;
};
extern CSupporters *opr4c_supporters;	// NOTE: placeholder name (0xcec04c)

class CSupporterCountButton : public Console
{
public:
	void unknown7f2010();	// NOTE: placeholder name

	bool flag;
};

void CSupporterCountButton::unknown7f2010()
{
	if (flag)
		printAligned(getWidth() - 2,0,2,intToString(opr4c_supporters->unknown7f3790()));
	else
		print(1,0,intToString(opr4c_supporters->unknown7f37b0()));
}

void CSupporters::unknown7f2f60()
{
	unknown_cec03c->removeSubconsole(unknown98);
	unknown_cec03c->unknown4968e0();
	unknown60 = 0;
	unknown_cefa8c->unknown416640();
	getParent()->removeSubconsole(this);
}

bool CSupporters::input(void *event)
{
	if (isHidden() || opr4c_consoleInputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (*(int*)event)
	{
	case 0x27:
		unknown7f30e0(5);
		return true;
	case 0x28:
		unknown7f30e0(-5);
		return true;
	case 0x29:
		unknown7f30e0((opr4c_rex.getHeight_4189a0() - 0xd) / 2);
		return true;
	case 0x2a:
		unknown7f30e0(-((opr4c_rex.getHeight_4189a0() - 0xd) / 2));
		return true;
	case 0x2b:
		unknown7f30e0(-10000);
		return true;
	case 0x2c:
		unknown7f30e0(10000);
		return true;
	case 0x2d:
		unknown7f2f60();
		return true;
	}
	return false;
}

//==================================================================
// free functions
//==================================================================

struct Point	// NOTE: placeholder layout; also used as an int range (min,max)
{
	int x;
	int y;
	Point(int x_, int y_);	// 0x46ca20
};

bool pointsOverlap_40c420(vector<Point> &v, const Point &r);	// NOTE: placeholder name

int opr4c_findFreeRange(int start, int length, int limit, vector<Point> &used, bool forward)	// NOTE: placeholder name (0x8145f0)
{
	if (forward)
	{
		for (int i = start; i <= limit; i++)
		{
			if (i + length - 1 <= limit)
			{
				if (!pointsOverlap_40c420(used,Point(i,i + length - 1)))
					return i;
			}
		}
	}
	else
	{
		for (int i = start; i >= limit; i--)
		{
			if (i + length - 1 <= start)
			{
				if (!pointsOverlap_40c420(used,Point(i,i + length - 1)))
					return i;
			}
		}
	}
	return -1;
}
