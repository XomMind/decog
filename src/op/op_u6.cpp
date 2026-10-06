// op_u6: functions in 0x7ea000-0x88c000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();
	Pos(const Pos &pos, int dx, int dy);	// NOTE: placeholder name (0x4099c0)
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	static XColor lerp(XColor a, XColor b, float t);
};

struct Rect;

class OpR2b_Engine	// NOTE: placeholder name
{
public:
	void stopAll();	// NOTE: placeholder name (0x50ff30)
};

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

	void clearBack();
	int getWidth();
	Pos getPos();
	void setPos(const Pos &pos);
	void setFore(XColor color);
	void setBackRow(int x, int y, int width, XColor color);
	void setBackAll_418410(XColor color);
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void print(int x, int y, const string &text);
	void removeSubconsole(XConsole *console);
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);
	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	virtual ~Console();

	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);

	void animate(string name);	// NOTE: placeholder name
	void drawFrame(Rect *area, XColor color, bool thin, bool lines);	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void unknown48c650();	// NOTE: placeholder name

	int unknown60;
	OpR2b_Engine *engine;
	void *title;
};

string intToString(int value);	// 0x4051f0
int OpY1_countDigits(unsigned int value);	// NOTE: placeholder name (0x406850)
extern XColor *opU6_colorBlack;	// NOTE: placeholder name (0xcfe674)
extern int opU6_anim_cef7e0[];	// NOTE: placeholder name
extern int opU6_anim_cef8e4[];	// NOTE: placeholder name
extern int opS6_anim_cef930[];	// NOTE: placeholder name
extern int opS6_anim_cef96c;	// NOTE: placeholder name
extern XColor opU6_categoryColors[][3];	// NOTE: placeholder name (0xd01c18)
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern vector<bool> opS6_achievementCategories;	// NOTE: placeholder name (0xd28d70)
extern int opS6_anim_cef864[];	// NOTE: placeholder name
extern int opS6_anim_cef998;	// NOTE: placeholder name
extern string opY6_strings_d2e8f8[];	// NOTE: placeholder name
extern vector<int> opU6_cf08d4;	// NOTE: placeholder name

class OpU6_GM	// NOTE: placeholder name (object at 0xd25628)
{
public:
	int unknown46c970(int category) throw();	// NOTE: placeholder name
};
extern OpU6_GM opU6_gm;	// NOTE: placeholder name

//==================================================================
// CAchievements categories
//==================================================================

class CAchievementsCategoryBar : public Console
{
public:
	CAchievementsCategoryBar(XConsole *parent, int category_);

	virtual void render();

	int category;	// NOTE: placeholder name
	unsigned int startTick;	// NOTE: placeholder name
	int percent;	// NOTE: placeholder name
	int filled;	// NOTE: placeholder name
	bool drawn;	// NOTE: placeholder name
};

CAchievementsCategoryBar::CAchievementsCategoryBar(XConsole *parent, int category_)
	: Console(parent,0x1d,1,1,2,0,false,-1)
{
	category = category_;
	startTick = tickCount;
	drawn = false;
	int total = opU6_gm.unknown46c970(category);
	percent = total * 100 / opU6_cf08d4[category];
	if (percent == 100 && total < opU6_cf08d4[category])
		percent = 99;
	filled = (int)(percent / 100.0 * 29.0);
	if (filled == 0 && percent != 0)
		filled = 1;
	else if (filled == 0x1d && percent < 100)
		filled--;
}

void CAchievementsCategoryBar::render()
{
	if (drawn)
		return;
	float elapsed = (float)(tickCount - startTick);
	if (elapsed >= 200.0)
	{
		setBackAll_418410(opU6_categoryColors[category][0]);
		setBackRow(0,0,filled,opU6_categoryColors[category][1]);
		if (percent < 100)
		{
			if ((unsigned int)(filled + OpY1_countDigits(percent) + 3) <= 0x1d)
			{
				setFore(opU6_categoryColors[category][2]);
				print(filled,0," " + intToString(percent) + "% ");
			}
			else
			{
				setFore(*opU6_colorBlack);
				print(filled - OpY1_countDigits(percent) - 2,0,intToString(percent) + "% ");
			}
		}
		drawn = true;
	}
	else
	{
		float t = (float)(elapsed / 200.0);
		XColor fade = XColor::lerp(*opU6_colorBlack,opU6_categoryColors[category][0],t);
		setBackAll_418410(fade);
		fade = XColor::lerp(opU6_categoryColors[category][0],opU6_categoryColors[category][1],t);
		setBackRow(0,0,(int)(filled * t),fade);
	}
}

class CAchievementsCategoryButton : public Console
{
public:
	CAchievementsCategoryButton(XConsole *parent, int x, int y, int category_);

	virtual bool mouseEnter();
	virtual bool input(void *event);

	int category;	// NOTE: placeholder name
};

CAchievementsCategoryButton::CAchievementsCategoryButton(XConsole *parent, int x, int y, int category_)
	: Console(parent,opY6_strings_d2e8f8[category_].size() + 2,1,x,y,0,false,-1)
{
	category = category_;
	putChar_4180b0(0,0,'[');
	print(1,0,opY6_strings_d2e8f8[category]);
	putChar_4180b0(getWidth() - 1,0,']');
	unknown48c3c0(opS6_achievementCategories[category] ? opS6_anim_cef864[category] : opS6_anim_cef998);
}

class CAchievementsCategory : public Console
{
public:
	CAchievementsCategory(XConsole *parent, int x, int y, int category_);

	int category;	// NOTE: placeholder name
	CAchievementsCategoryButton *button;	// NOTE: placeholder name
	CAchievementsCategoryBar *bar;	// NOTE: placeholder name
	Console *label;	// NOTE: placeholder name
};

CAchievementsCategory::CAchievementsCategory(XConsole *parent, int x, int y, int category_)
	: Console(parent,0x20,4,x,y,0,false,-1)
{
	category = category_;
	drawFrame(NULL,*opU6_colorBlack,true,false);
	unknown48c3c0(opU6_anim_cef7e0[category]);
	button = new CAchievementsCategoryButton(this,2,0,category);
	Console *back = new Console(this,1,2,0,1,0,false,-1);
	back->unknown48c3c0(opU6_anim_cef8e4[category]);
	bar = new CAchievementsCategoryBar(this,category);
	int total = opU6_gm.unknown46c970(category);
	int count = OpY1_countDigits(total) + OpY1_countDigits(opU6_cf08d4[category]) + 3;
	label = new Console(this,count,1,getWidth() - 3 - count,1,0,false,-1);
	label->print(0,0,intToString(total) + " / " + intToString(opU6_cf08d4[category]));
	label->unknown48c3c0(opS6_achievementCategories[category] ? opS6_anim_cef930[category] : opS6_anim_cef96c);
}

class CAchievementsControls : public Console
{
public:
	virtual ~CAchievementsControls();

	vector<unsigned int> unknown6c;	// NOTE: placeholder name
	int unknown7c;	// NOTE: placeholder name
	vector<unsigned int> unknown80;	// NOTE: placeholder name
	vector<unsigned int> unknown90;	// NOTE: placeholder name
};

CAchievementsControls::~CAchievementsControls()
{
}

//==================================================================
// CMap
//==================================================================

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;

	Point(int x_, int y_);
};

bool findEffectID(const string &name, int *id);	// NOTE: placeholder name (0x9d7980)
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name
int opS6_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)

class OpU6_Effect	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class OpU6_EffectMgr	// NOTE: placeholder name
{
public:
	OpU6_Effect *create();	// NOTE: placeholder name (0x508610)
};
extern OpU6_EffectMgr *opU6_effectMgr;	// NOTE: placeholder name (0xcefc50)

class XTimerD	// NOTE: placeholder name
{
public:
	XTimerD(const Pos &pos_, bool flag_);	// 0x499c20

	int pad0;
	int pad4;
	int pad8;
	int padC;
};
extern int opU6_d28e40;	// NOTE: placeholder name

struct OpU6_Path	// NOTE: placeholder name
{
	int pad0;
	vector<Point> points;
};

struct OpU6_Elem50c	// NOTE: placeholder name
{
	int pad[3];
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;

	void unknown9b7270();	// NOTE: placeholder name (resets the handle)
};

int OpU8a_indexOfEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d3110)
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9de...)
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0
struct OpQ5_U9da940	// NOTE: placeholder name
{
	int pad;
};
class OpU6_Gm2	// NOTE: placeholder name (pointer at 0xcefaa8)
{
public:
	void unknown78d700(bool a, bool b);	// NOTE: placeholder name
};
extern OpU6_Gm2 *opU6_gm2;	// NOTE: placeholder name
extern bool opU6_asciiEnabled;	// NOTE: placeholder name (0xd28d30)
extern int opU6_table_b98a08[];	// NOTE: placeholder name
extern int opU6_tickCountInt;	// NOTE: placeholder name (0xcaed20)

class CMap : public Console
{
public:
	void unknown807f70(HEntity entity, int value);	// NOTE: placeholder name
	bool unknown808290();	// NOTE: placeholder name
	void unknown8197f0(const Pos &pos, bool flag);	// NOTE: placeholder name
	bool unknown49ac90(const Pos &pos, bool a, int b);	// NOTE: placeholder name
	void unknown819d50(int value, bool flag);	// NOTE: placeholder name
	void unknown8142d0(int a, int b);	// NOTE: placeholder name
	void unknown8079e0(OpU6_Path *path);	// NOTE: placeholder name
	void unknown807e60(bool value);	// NOTE: placeholder name
	void unknown807eb0(bool full);	// NOTE: placeholder name

	char pad6c[0xec - 0x6c];
	bool unknownec;	// NOTE: placeholder name
	char padED[3];
	unsigned int unknownf0;	// NOTE: placeholder name
	HEntity unknownf4;	// NOTE: placeholder name
	char padf8[0x22c - 0xf8];
	vector<HEntity> unknown22c;	// NOTE: placeholder name
	vector<int> unknown23c;	// NOTE: placeholder name
	vector<int> unknown24c;	// NOTE: placeholder name
	char pad25c[0x33c - 0x25c];
	vector<XTimerD> unknown33c;	// NOTE: placeholder name
	char pad34c[0x374 - 0x34c];
	int unknown374;	// NOTE: placeholder name
	unsigned int unknown378;	// NOTE: placeholder name
	bool unknown37c;	// NOTE: placeholder name
	char pad37d[3];
	char pad380[0x420 - 0x380];
	vector<OpU6_Path*> unknown420;	// NOTE: placeholder name
	vector<int> unknown430;	// NOTE: placeholder name
	vector<int> unknown440;	// NOTE: placeholder name
	unsigned int unknown450;	// NOTE: placeholder name
	char pad454[0x4c4 - 0x454];
	bool unknown4c4;	// NOTE: placeholder name
	char pad4c5[3];
	int unknown4c8;	// NOTE: placeholder name
	char pad4cc[0x4dc - 0x4cc];
	vector<Point> unknown4dc;	// NOTE: placeholder name
	vector<Console*> unknown4ec;	// NOTE: placeholder name
	vector<Console*> unknown4fc;	// NOTE: placeholder name
	vector<OpU6_Elem50c> unknown50c;	// NOTE: placeholder name
	char pad51c[0x520 - 0x51c];
	vector<Console*> unknown520;	// NOTE: placeholder name
	vector<Point> unknown530;	// NOTE: placeholder name
	char pad540[0x6b0 - 0x540];
	int unknown6b0;	// NOTE: placeholder name
};

void CMap::unknown807e60(bool value)
{
	if (unknown4c4 == value)
		return;
	else
		unknown4c4 = value;
	if (!unknown4c4)
		unknown807eb0(true);
}

void CMap::unknown807eb0(bool full)
{
	unknown4c8 = -1;
	unknown4dc.clear();
	unknown4ec.clear();
	unknown4fc.clear();
	if (full)
		unknown50c.clear();
	unknown520.clear();
	unknown530.clear();
	unknown6b0 = 0;
}

void CMap::unknown807f70(HEntity entity, int value)
{
	int index = OpU8a_indexOfEntity(unknown22c,entity);
	if (index != -1)
	{
		OpQ5_eraseAt((vector<OpQ5_U9da940>&)unknown22c,index);
		removeVectorElement(unknown23c,index);
		removeVectorElement(unknown24c,index);
	}
	unknown22c.push_back(entity);
	unknown23c.push_back(value);
	unknown24c.push_back(opU6_tickCountInt);
}

bool CMap::unknown808290()
{
	unknownec = !unknownec;
	if (unknownec)
	{
		unknownf0 = tickCount;
		unknownf4.unknown9b7270();
		unknown8142d0(0x12,0);
		opR1d_4541b0(0x41,0,0);
	}
	else
		opR1d_4541b0(0x3f,0,0);
	return unknownec;
}

void CMap::unknown819d50(int value, bool flag)
{
	if (unknown374 != 5 && unknown37c && !opU6_asciiEnabled)
		opU6_gm2->unknown78d700(false,false);
	unknown374 = value;
	unknown378 = tickCount + opU6_table_b98a08[unknown374];
	if (flag && opU6_asciiEnabled)
	{
		opU6_gm2->unknown78d700(false,false);
		unknown37c = true;
	}
	else
		unknown37c = false;
}

void CMap::unknown8197f0(const Pos &pos, bool flag)
{
	unknown33c.push_back(XTimerD(pos,flag));
	if (opU6_d28e40)
		unknown49ac90(pos,true,opU6_d28e40);
}
