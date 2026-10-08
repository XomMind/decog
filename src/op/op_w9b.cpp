// op_w9b: gameover consoles in 0x7ba000-0x7c0000 (CGameoverAchievements, CGameoverMain, CGameoverOverlay, ...), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
#include "thirdparty/zfstream.h"
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct OpW9b_Offset;
struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();
	explicit Pos(int value);	// NOTE: placeholder name (0x409990)
	Pos(const OpW9b_Offset &offset);	// NOTE: placeholder name (0x46ca50)
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	bool operator==(XColor color);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect() throw();
	Rect(int x_, int y_, int width_, int height_) throw();	// 0x456940	// NOTE: folded default ctor
	Rect(const Rect &rect);
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(void *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	bool isHidden();
	int getWidth_44b0d0();	// NOTE: placeholder name (folded getter)
	int getHeight();
	Pos getPos();
	void setHidden(bool hidden_) throw();
	XConsole *getParent();
	void removeSubconsole(XConsole *console);
	void resetBack_418450();
	void printAligned(int x, int y, int align, const string &text);
	void setChars(int x, int y, int width, int height, int ch);
	void setBackAll_418410(XColor color);
	void setPos(int x, int y);
	XColor getBack(int x, int y);
	void clear();
	void print(int x, int y, const string &text);

	char pad04[0x60 - 0x04];
};

struct OpW9b_Offset	// NOTE: placeholder name
{
	int x;
	int y;
};

class OpW9b_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class Engine
{
public:
	OpW9b_EngineItem *unknown50fb50(Engine *engine, int type, Pos *a, OpW9b_Offset *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	bool isRunning();	// NOTE: placeholder name (0x50fff0)
	void stopAll();	// NOTE: placeholder name (0x50ff30)
};

class Console : public XConsole
{
public:
	virtual ~Console();	// 0x48c2b0
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);

	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void animate(string name);	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void unknown48c460(int anim, const Pos &pos);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	XConsole *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);

	string title;
	int align;
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	string text;
};

class AsciiImage;

class CArtAnimated : public Console
{
public:
	CArtAnimated(XConsole *parent, AsciiImage *image, int x, int y, bool flag, int animation, int a, int b, const Pos &pos, int c, int d);
	void unknown4b29b0();	// NOTE: placeholder name

	char pad6c[0x88 - 0x6c];
};

string intToString(int value);
int minInt(int a, int b);
int opW9b_center(int size, int width);	// NOTE: placeholder name (0x437190)
bool opW9b_findAnimation(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)

extern bool opW9b_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern unsigned int opW9b_tickCount;	// NOTE: placeholder name (0xcaed20)

struct OpW9b_Achievement	// NOTE: placeholder name
{
	char pad0[0x20];
	string name;	// NOTE: placeholder name
	char pad3c[0x40 - 0x3c];
	int category;	// NOTE: placeholder name
	char pad44[0x6c - 0x44];
	char image[0x10];	// NOTE: placeholder layout (AsciiImage)
};
extern vector<OpW9b_Achievement*> opW9b_achievementData;	// NOTE: placeholder name (0xcf09a8)
extern vector<int> opW9b_achievementsEarned;	// NOTE: placeholder name (0xcf47ec)
extern string opW9b_achievementCategoryNames[];	// NOTE: placeholder name (0xd15db0)

class OpW9b_GameData	// NOTE: placeholder name (0xcefaa8)
{
public:
	int getNewAchievementCount();	// NOTE: placeholder name (0x470b50)
	vector<int> *getNewAchievements();	// NOTE: placeholder name (0x470b70)
};
extern OpW9b_GameData *opW9b_gameData;	// NOTE: placeholder name

//==================================================================
// CGameoverAchievements
//==================================================================

class CGameoverAchievements : public Console
{
public:
	CGameoverAchievements(XConsole *parent, const Rect &rect);
	virtual ~CGameoverAchievements() {}
};

CGameoverAchievements::CGameoverAchievements(XConsole *parent, const Rect &rect)
	: Console(parent,rect,0,false,20)
{
	setTitle(new ConsoleTitle(this,"\\ A C H I E V E M E N T S \\",0,1));
	animate("CGameoverAchieve_Border");

	CArtAnimated *art;
	CText *label;
	vector<int> *achievements = opW9b_gameData->getNewAchievements();
	int total = minInt(achievements->size(),4);
	for (int i = 0, y = 2; i < total; i++, y += 6)
	{
		OpW9b_Achievement *achievement = opW9b_achievementData[(*achievements)[i]];
		int animation;
		opW9b_findAnimation("A_CMap_Achieve_Icon_" + opW9b_achievementCategoryNames[achievement->category],&animation);
		art = new CArtAnimated(this,(AsciiImage*)achievement->image,2,y,false,animation,-1,-1,Pos(-1),0,0);
		art->resetBack_418450();
		art->unknown4b29b0();
		label = new CText(this,Pos(art->getPos().x + art->getWidth_44b0d0() * 2 + 1,y + 2),achievement->name,0,0,-1);
		label->animate("A_CMap_Achieve_Name_" + opW9b_achievementCategoryNames[achievement->category]);
	}
	if (opW9b_achievementsEarned.size() > total)
	{
		string more = "+" + intToString(opW9b_achievementsEarned.size() - total) + " more (full list in score sheet)";
		label = new CText(this,Pos(2,getHeight() - 2),more,0,0,-1);
		label->animate("A_BlockAppear_Text");
	}
	achievements->clear();
}

//==================================================================
// CGamoverButton
//==================================================================

class CGamoverButton : public Console
{
public:
	CGamoverButton(XConsole *parent, int x, int y, int command_);	// 0x48fe40

	virtual bool input(void *event);

	int command;	// NOTE: placeholder name
};
extern Console *opW9b_gameover;	// NOTE: placeholder name (0xcec144)

bool CGamoverButton::input(void *event)
{
	if (isHidden() || opW9b_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (((XEvent*)event)->type)
	{
		case 0x19d:
			opW9b_gameover->input(&XEvent(command));
			return true;
	}
	return false;
}

//==================================================================
// CGameoverMain
//==================================================================

struct OpW9b_StatRecord	// NOTE: placeholder name (MapRecord)
{
	char pad00[0x20];
	string name;	// NOTE: placeholder name
	char pad3c[0x40 - 0x3c];
	bool unknown40;	// NOTE: placeholder name
	int unknown44;	// NOTE: placeholder name
};
extern vector<OpW9b_StatRecord*> opW9b_statRecords;	// NOTE: placeholder name (0xd389c4)

class OpW9b_Stats	// NOTE: placeholder name (0xd2c658)
{
public:
	int get(int id);	// NOTE: placeholder name (0x472c70)
};
extern OpW9b_Stats opW9b_stats;	// NOTE: placeholder name
extern const int opW9b_scoreMultipliers[];	// NOTE: placeholder name (0xbbc218)
extern int opW9b_colorScheme;	// NOTE: placeholder name (0xcf4718)
extern string opW9b_colorSchemeNames[];	// NOTE: placeholder name (0xcfabc0)
extern OpW9b_Offset opW9b_d2e20c;	// NOTE: placeholder name
int opW9b_sum(vector<int> &values);	// NOTE: placeholder name (0x9cdbd0)

class CGameover;
class CGameoverMain : public Console
{
public:
	CGameoverMain(CGameover *parent, const Rect &rect);
	virtual ~CGameoverMain() {}	// 0x490030 (op_w5)

	virtual void trigger(const string &command, int value);

	int printSection(int y, bool performance);	// NOTE: placeholder name

	Console *unknown6c;	// NOTE: placeholder name (upload console)
	CGameoverAchievements *achievements;	// NOTE: placeholder name
	unsigned int unknown74;	// NOTE: placeholder name
	Console *unknown78;	// NOTE: placeholder name (restart button)
	Console *unknown7c;	// NOTE: placeholder name (quit button)
	unsigned int unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	Console *unknown88;	// NOTE: placeholder name
};

void CGameoverMain::trigger(const string &command, int value)
{
	if (command == "achievements" && opW9b_gameData->getNewAchievementCount())
	{
		vector<int> *achievements = opW9b_gameData->getNewAchievements();
		int total = minInt(achievements->size(),4);
		Rect rect;
		rect.width = 40;
		for (unsigned int i = 0; i < achievements->size(); i++)
		{
			int width = opW9b_achievementData[(*achievements)[i]]->name.size() + 15;
			if (width > rect.width)
				rect.width = width;
		}
		rect.height = total * 5 + total + 3;
		if (opW9b_achievementsEarned.size() > total)
			rect.height++;
		rect.x = getWidth_44b0d0() + 1;
		rect.y = opW9b_center(rect.height,getHeight());
		this->achievements = new CGameoverAchievements(this,rect);
	}
}

int CGameoverMain::printSection(int y, bool performance)
{
	string header = performance ? "P e r f o r m a n c e" : "S t a t s";
	Pos cursor(7,y);
	CText *text = new CText(this,cursor,header,0,0,-1);
	text->animate("A_GMain_Header_" + opW9b_colorSchemeNames[opW9b_colorScheme]);
	Console *separator = new Console(this,36 - header.size() - 1,1,header.size() + 8,cursor.y,0,false,-1);
	separator->animate("A_GMain_Divider_" + opW9b_colorSchemeNames[opW9b_colorScheme]);
	cursor.y++;
	y = cursor.y;
	int valueX = cursor.x + 35;

	if (performance)
	{
		for (int i = 0; i <= 6; i++)
		{
			if (opW9b_statRecords[i]->unknown44 == 0)
			{
				printAligned(cursor.x,cursor.y,0,opW9b_statRecords[i]->name + " (" + intToString(opW9b_stats.get(i)) + ")");
				printAligned(valueX,cursor.y,2,intToString(opW9b_stats.get(i) * opW9b_scoreMultipliers[i]));
				cursor.y++;
			}
		}
	}
	else
	{
		for (int i = 7; i < 0x4a1; i++)
		{
			if (opW9b_statRecords[i]->unknown40)
			{
				printAligned(cursor.x,cursor.y,0,opW9b_statRecords[i]->name);
				printAligned(valueX,cursor.y,2,intToString(opW9b_stats.get(i)));
				cursor.y++;
			}
		}
		printAligned(cursor.x,cursor.y,0,"New Achievements");
		printAligned(valueX,cursor.y,2,intToString(opW9b_achievementsEarned.size()));
		cursor.y++;
	}

	int index;
	opW9b_findAnimation("SilentType_GR3_Vert_E",&index);
	if (index)
	{
		for (int x = 7; x <= valueX; x++)
			engine->unknown50fb50(engine,index,&Pos(x,y),&opW9b_d2e20c,&Pos(x,cursor.y - 1),&Pos(opW9b_d2e20c),9)->unknown50de10();
	}

	if (performance)
	{
		vector<int> scores(7,0);
		for (int i = 0; i <= 6; i++)
			scores[i] = opW9b_stats.get(i) * opW9b_scoreMultipliers[i];
		string totalText = "Total Score: " + intToString(opW9b_sum(scores));
		text = new CText(this,Pos(valueX - totalText.size() + 1,cursor.y),totalText,0,0,-1);
		text->animate("A_GMain_Score_" + opW9b_colorSchemeNames[opW9b_colorScheme]);
		cursor.y++;
	}
	return cursor.y;
}

//==================================================================
// CGameover
//==================================================================

class OpW9b_Rex	// NOTE: placeholder name (REX at 0xd223f0)
{
public:
	XConsole *getRoot();	// NOTE: placeholder name (folded getter)
	int getWidth_418980();	// NOTE: placeholder name
	int getHeight_4189a0();	// NOTE: placeholder name
};
extern OpW9b_Rex opW9b_rex;	// NOTE: placeholder name

class OpW9b_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void unknown4162e0(int command, int value);	// NOTE: placeholder name
};
extern OpW9b_KeyMap *opW9b_keyMap;	// NOTE: placeholder name

class OpW9b_Unknown_cf45d8	// NOTE: placeholder name
{
public:
	bool isFlagActive();	// NOTE: placeholder name (0x46dd50)
	bool unknown77e7c0();	// NOTE: placeholder name
};
extern OpW9b_Unknown_cf45d8 opW9b_unknown_cf45d8;	// NOTE: placeholder name
extern bool opW9b_cefacd;	// NOTE: placeholder name
extern bool opW9b_d28de3;	// NOTE: placeholder name
extern bool opW9b_cefb18;	// NOTE: placeholder name
int opr4a_unknown77e2b0(gzifstream &stream, bool chrono, bool manual);	// NOTE: placeholder name

// checks that a readable save exists (0x77e7c0)
bool OpW9b_Unknown_cf45d8::unknown77e7c0()
{
	bool valid = !opW9b_cefacd && !opW9b_unknown_cf45d8.isFlagActive() && opW9b_colorScheme != 0 && !opW9b_d28de3;
	if (opW9b_cefb18)
		valid = true;
	gzifstream file;
	if (valid && opr4a_unknown77e2b0(file,false,valid) == 0)
	{
		file.close();
		return true;
	}
	else
		return false;
}

class OpW9b_Scorekeeper	// NOTE: placeholder name (0xd2c658)
{
public:
	string totalScore_474a20(int flags);	// NOTE: placeholder name
};

extern int opW9b_gameoverType;	// NOTE: placeholder name (0xcf4b38)
extern XColor opW9b_d29804;	// NOTE: placeholder name
void opW9b_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)

struct Point
{
	int x;
	int y;
};

class OpW9b_Grid	// NOTE: placeholder name (Array2D<int>)
{
public:
	int &at(int x, int y);	// NOTE: placeholder name (0x9ceda0)
	void resize(int width, int height, int value);	// NOTE: placeholder name (0x9cf690)
	int getWidth();	// NOTE: placeholder name (folded getter)
	int getHeight();	// NOTE: placeholder name (folded getter)

	int data[3];
};

class CGameoverOverlay : public Console
{
public:
	CGameoverOverlay(Console *parent);
	virtual ~CGameoverOverlay();

	virtual void update();
	virtual void trigger(const string &command, int value);

	string unknown7bdfd0();	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	unsigned int unknown70;	// NOTE: placeholder name
	unsigned int unknown74;	// NOTE: placeholder name
	unsigned int unknown78;	// NOTE: placeholder name
	unsigned int unknown7c;	// NOTE: placeholder name
	int mapWidth;	// NOTE: placeholder name
	int mapHeight;	// NOTE: placeholder name
	OpW9b_Grid shown;	// NOTE: placeholder name
	Point offset;	// NOTE: placeholder name
	vector<int> mapAnimations;	// NOTE: placeholder name
	int eraseAnimation;	// NOTE: placeholder name
	int closeAnimation;	// NOTE: placeholder name
	unsigned int unknownb4;	// NOTE: placeholder name
	unsigned int unknownb8;	// NOTE: placeholder name
	Point martyrPos;	// NOTE: placeholder name
	vector<Console*> martyrs;	// NOTE: placeholder name
};

class CGameover : public Console
{
public:
	CGameover();
	virtual ~CGameover();

	virtual bool input(void *event);
	virtual void update();
	virtual void trigger(const string &command, int value);

	void unknown7bfe60();	// NOTE: placeholder name
	bool getUnknown6c_4ab570();	// NOTE: placeholder name (folded getter)
	string &getScore_490820();	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	string score;	// NOTE: placeholder name
	CGameoverOverlay *overlay;	// NOTE: placeholder name
	unsigned int unknown90;	// NOTE: placeholder name
	CGameoverMain *stats;	// NOTE: placeholder name
	unsigned int unknown98;	// NOTE: placeholder name
	bool unknown9c;	// NOTE: placeholder name
};

CGameover::CGameover()
	: Console(opW9b_rex.getRoot(),opW9b_rex.getWidth_418980() / 2,opW9b_rex.getHeight_4189a0(),0,0,2,false,-1)
{
	unknown90 = opW9b_tickCount;
	stats = NULL;
	unknown98 = 0;
	unknown9c = false;
	opW9b_gameover = this;
	opW9b_keyMap->unknown4162e0(0x23,1);
	unknown6c = opW9b_unknown_cf45d8.unknown77e7c0();
	score = ((OpW9b_Scorekeeper*)&opW9b_stats)->totalScore_474a20(0);
	if (opW9b_gameoverType == 4 || opW9b_gameoverType == 5 || opW9b_gameoverType == 12 || opW9b_gameoverType == 13)
		unknown7bfe60();
	else if (opW9b_gameoverType == 6 || opW9b_gameoverType == 7 || opW9b_gameoverType == 8 || opW9b_gameoverType == 9)
		unknown98 = 0;
	else if (opW9b_gameoverType <= 9)
	{
		opW9b_playSound(0x70,0,0);
		unknown98 = opW9b_tickCount + 3125;
		setBackAll_418410(opW9b_d29804);
	}
	else
		unknown7bfe60();
}

void CGameover::unknown7bfe60()
{
	overlay = new CGameoverOverlay(this);
	if (opW9b_gameoverType == 4 || opW9b_gameoverType == 5 || opW9b_gameoverType == 7 || opW9b_gameoverType == 8 || opW9b_gameoverType == 12 || opW9b_gameoverType == 9)
		trigger("show_stats_win",0);
	else
	{
		animate("A_Gameover_Bkg");
		animate(opW9b_gameoverType <= 9 ? "A_Gameover_Sfx_Win" : "A_Gameover_Sfx_Loss");
		overlay->resetBack_418450();
		overlay->setChars(0,0,overlay->getWidth_44b0d0(),overlay->getHeight(),'0');
		if (opW9b_gameoverType <= 9)
			overlay->animate("A_Gameover_Win");
		else
		{
			int animation;
			opW9b_findAnimation("Gameover_Loss_E",&animation);
			if (animation)
			{
				int middle = getHeight() / 2;
				int below = middle + 1;
				for (int x = 0; x < getWidth_44b0d0(); x++)
				{
					overlay->engine->unknown50fb50(overlay->engine,animation,&Pos(x,0),&opW9b_d2e20c,&Pos(x,middle),&Pos(opW9b_d2e20c),9)->unknown50de10();
					overlay->engine->unknown50fb50(overlay->engine,animation,&Pos(x,getHeight() - 1),&opW9b_d2e20c,&Pos(x,below),&Pos(opW9b_d2e20c),9)->unknown50de10();
				}
			}
		}
	}
}

//==================================================================
// gameover helpers
//==================================================================

int opW9b_randomElement(vector<int> &values);	// NOTE: placeholder name (0x9d5d00)

int opW9b_unknown7bdc70()	// NOTE: placeholder name
{
	vector<int> ids;
	ids.push_back(2);
	ids.push_back(3);
	ids.push_back(4);
	ids.push_back(5);
	ids.push_back(7);
	ids.push_back(9);
	ids.push_back(10);
	ids.push_back(12);
	ids.push_back(13);
	ids.push_back(14);
	ids.push_back(16);
	ids.push_back(17);
	ids.push_back(18);
	ids.push_back(24);
	ids.push_back(25);
	ids.push_back(26);
	ids.push_back(27);
	ids.push_back(28);
	ids.push_back(30);
	ids.push_back(31);
	ids.push_back(34);
	return opW9b_randomElement(ids);
}

int opW9b_unknown7bde70()	// NOTE: placeholder name
{
	vector<int> ids;
	ids.push_back(2);
	ids.push_back(3);
	ids.push_back(4);
	ids.push_back(5);
	ids.push_back(9);
	ids.push_back(13);
	ids.push_back(24);
	ids.push_back(26);
	ids.push_back(27);
	ids.push_back(28);
	ids.push_back(30);
	ids.push_back(31);
	ids.push_back(34);
	return opW9b_randomElement(ids);
}

//==================================================================
// CGameoverMain
//==================================================================

struct OpW9b_SaveInfo	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int location;	// NOTE: placeholder name
	int depth;	// NOTE: placeholder name
	char padc[0x25 - 0xc];
	bool known;	// NOTE: placeholder name
};
class OpW9b_HSaveInfo	// NOTE: placeholder name
{
public:
	int ID;
	OpW9b_SaveInfo *operator->() const;	// 0x9b7910
};
extern OpW9b_HSaveInfo opW9b_saveInfo;	// NOTE: placeholder name (0xcf4618)
extern string opW9b_locationNames[];	// NOTE: placeholder name (0xcfaca0)
extern string opW9b_gameoverTitles[];	// NOTE: placeholder name (0xd329d0)
extern string opW9b_customFilePath;	// NOTE: placeholder name (0xcfd42c)

class CGameoverUpload : public Console
{
public:
	CGameoverUpload(XConsole *parent, const Rect &rect);	// 0x48fcc0
};


CGameoverMain::CGameoverMain(CGameover *parent, const Rect &rect)
	: Console(parent,rect,0,false,20),
	unknown6c(NULL),
	achievements(NULL),
	unknown74(opW9b_tickCount),
	unknown80(0),
	unknown88(NULL)
{
	animate("CGameoverMain_Border");
	string line = "=  " + opW9b_gameoverTitles[opW9b_gameoverType] + "  =";
	CText *label = new CText(this,Pos(opW9b_center(line.size(),getWidth_44b0d0()),3),line,0,0,-1);
	label->animate("A_Credits_Contributor");

	int row = 6;
	row = printSection(row,true);
	row++;
	row = printSection(row,false);
	row++;

	string text;
	text = ((CGameover*)opW9b_gameover)->getScore_490820().empty() ? string("(no scoresheet for suicides below depth 9)") : "Full record in /" + (opW9b_customFilePath.empty() ? opW9b_customFilePath + "scores" : string("[custom]")) + "/ directory";
	label = new CText(this,Pos(opW9b_center(text.size(),getWidth_44b0d0()),row),text,0,0,-1);
	label->animate("A_BlockAppear_Dark");
	row += 2;

	if (((CGameover*)opW9b_gameover)->getScore_490820().empty())
	{
		text = "(stat upload inapplicable)";
		label = new CText(this,Pos(opW9b_center(text.size(),getWidth_44b0d0()),row),text,0,0,-1);
		label->animate("A_BlockAppear_Dark");
	}
	else
	{
		unknown6c = new CGameoverUpload(this,Rect(1,row,getWidth_44b0d0() - 2,1));
		unknown6c->animate("A_GMain_Upload");
	}
	row += 3;

	unknown78 = new CGamoverButton(this,6,row,0x19f);
	unknown7c = new CGamoverButton(this,0x1c,row,0x1a0);

	if (((CGameover*)opW9b_gameover)->getUnknown6c_4ab570())
	{
		Console *button = new CGamoverButton(this,0,row + 2,0x19e);
		string location = "-" + intToString(opW9b_saveInfo->depth) + "/" + (opW9b_saveInfo->known ? opW9b_locationNames[opW9b_saveInfo->location] : "???");
		int x = opW9b_center(button->getWidth_44b0d0() + location.size() + 1,getWidth_44b0d0());
		button->setPos(x,button->getPos().y);
		label = new CText(this,Pos(x + button->getWidth_44b0d0() + 1,button->getPos().y),location,0,0,-1);
		label->animate("A_BlockAppear_Dark");
	}
	animate("A_GMain_Achievement_Tim");
}

//==================================================================
// CGameoverOverlay
//==================================================================

struct Area	// NOTE: placeholder name
{
	Area(int x1_, int y1_, int x2_, int y2_);	// NOTE: placeholder name (0x40b1e0)
	Point randomPoint_40be90();	// NOTE: placeholder name

	int x1;
	int y1;
	int x2;
	int y2;
};

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float min, float max);
};
extern RNG rng;

class CEnding
{
public:
	void markSeen();	// NOTE: placeholder name
};
extern CEnding *opW9b_ending;	// NOTE: placeholder name (0xcec148)

class CGameoverEndingText : public Console
{
public:
	CGameoverEndingText(XConsole *parent, int x, int y, const string &text, const string &animation, int layer);
};

struct OpW9b_MapSeed	// NOTE: placeholder name
{
	char pad00[0x10];
	bool current;	// NOTE: placeholder name
	char pad11[0x18 - 0x11];
	int seed;	// NOTE: placeholder name
};
extern vector<OpW9b_MapSeed*> opW9b_mapSeeds;	// NOTE: placeholder name (0xcf1a04)

class OpW9b_Generator	// NOTE: placeholder name (0xd31580)
{
public:
	void unknown4bf610(int seed, const string &a, const string &b, int c, int d, int e, int f);	// NOTE: placeholder name
	void placeTunnelers();	// NOTE: placeholder name
	bool unknown4c1880(bool flag);	// NOTE: placeholder name
	int getUnknown_45ab90();	// NOTE: placeholder name (folded getter)
};
extern OpW9b_Generator opW9b_generator;	// NOTE: placeholder name

struct OpW9b_RobotPart	// NOTE: placeholder name
{
	int item;	// NOTE: placeholder name
};

struct OpW9b_RobotData	// NOTE: placeholder name
{
	char pad00[0x24];
	int unknown24;	// NOTE: placeholder name
	int unknown28;	// NOTE: placeholder name
	char pad2c[0x68 - 0x2c];
	int unknown68;	// NOTE: placeholder name
	char pad6c[0x139 - 0x6c];
	bool unknown139;	// NOTE: placeholder name
	char pad13a[0x160 - 0x13a];
	vector<vector<struct OpW9b_RobotPart*> > parts;	// NOTE: placeholder name
	char pad170[0x1ac - 0x170];
	string name;	// NOTE: placeholder name
};
extern vector<OpW9b_RobotData*> opW9b_robotData;	// NOTE: placeholder name (0xd25de0)

struct OpW9b_ItemData	// NOTE: placeholder name
{
	char pad00[0x24];
	string name;	// NOTE: placeholder name
	char pad40[0x44 - 0x40];
	int unknown44;	// NOTE: placeholder name
	int unknown48;	// NOTE: placeholder name
	char pad4c[0x54 - 0x4c];
	int unknown54;	// NOTE: placeholder name
	char pad58[0x94 - 0x58];
	int unknown94;	// NOTE: placeholder name
	char pad98[0x1a8 - 0x98];
	int unknown1a8;	// NOTE: placeholder name
	char pad1ac[0x273 - 0x1ac];
	bool unknown273;	// NOTE: placeholder name
};
extern vector<OpW9b_ItemData*> opW9b_itemData;	// NOTE: placeholder name (0xd2d1c4)

extern XColor *opW9b_d20cfc;	// NOTE: placeholder name
extern OpW9b_Grid opW9b_mapGrid;	// NOTE: placeholder name (0xcf1964)
extern const bool opW9b_mapLayers[];	// NOTE: placeholder name (0xbbcad8)
extern string opW9b_d33e1c;	// NOTE: placeholder name
template <class T> int opW9b_randomIndex(vector<T> &v);	// NOTE: placeholder name (0x9d9b20)
char opW9b_randomChar(const string &chars);	// NOTE: placeholder name (0x4085b0)
string opW9b_toUpper(const string &text);	// NOTE: placeholder name (0x4083a0)
string opW5_getEndingType();	// NOTE: placeholder name
template <class T> void removeVectorElement(vector<T> &v, int index);

void CGameoverOverlay::update()
{
	if (isHidden())
		return;

	engine->isRunning();

	if (opW9b_gameoverType <= 9 && opW9b_gameoverType != 4 && opW9b_gameoverType != 5 && opW9b_gameoverType != 7 && opW9b_gameoverType != 8 && opW9b_gameoverType != 12 && opW9b_gameoverType != 9 && mapWidth == 0 && unknown70 && opW9b_tickCount >= unknown70)
	{
		unknown70 += 500;
		for (int x = 0; x < getWidth_44b0d0(); x++)
		{
			for (int y = 0; y < getHeight(); y++)
			{
				if (getBack(x,y) == *opW9b_d20cfc)
					goto map;
			}
		}
		engine->stopAll();
		animate("A_Gameover_Win2");
		((Console*)getParent())->engine->stopAll();
		unknown70 = 0;
		if (opW9b_ending)
			opW9b_ending->markSeen();
	}
map:
	if (mapWidth)
	{
		if (unknown74 && opW9b_tickCount >= unknown74)
		{
			clear();
			int seed;
			for (unsigned int i = 0; i < opW9b_mapSeeds.size(); i++)
			{
				if (opW9b_mapSeeds[i]->current)
				{
					seed = opW9b_mapSeeds[i]->seed;
					break;
				}
			}
			opW9b_generator.unknown4bf610(seed,"","",0,1,0,-1);
			opW9b_generator.placeTunnelers();
			unknown78 = opW9b_tickCount;
			unknown74 = 0;
			mapWidth = opW9b_mapGrid.getWidth();
			mapHeight = opW9b_mapGrid.getHeight();
			shown.resize(mapWidth,mapHeight,21);
			offset.x = mapWidth > getWidth_44b0d0() ? -opW9b_center(getWidth_44b0d0(),mapWidth) : opW9b_center(mapWidth,getWidth_44b0d0());
			offset.y = mapHeight > getHeight() ? -opW9b_center(getHeight(),mapHeight) : opW9b_center(mapHeight,getHeight());
		}
		if (unknown78 && opW9b_tickCount >= unknown78)
		{
			if (opW9b_generator.unknown4c1880(true))
			{
				unknown78 = 0;
				unknown7c = opW9b_tickCount + 1000;
			}
			else
				unknown78 = opW9b_tickCount + (opW9b_generator.getUnknown_45ab90() != -1 ? 500 : 50);
		}
		if (unknown7c && opW9b_tickCount >= unknown7c)
		{
			unknown48c3c0(closeAnimation);
			unknown7c = 0;
			unknown74 = opW9b_tickCount + 400;
		}
		for (int mapX = offset.x < 0 ? -offset.x : 0, viewX = offset.x < 0 ? 0 : offset.x; viewX < getWidth_44b0d0() && mapX < mapWidth; mapX++, viewX++)
		{
			for (int mapY = offset.y < 0 ? -offset.y : 0, cy = offset.y < 0 ? 0 : offset.y; cy < getHeight() && mapY < mapHeight; mapY++, cy++)
			{
				if (opW9b_mapLayers[opW9b_mapGrid.at(mapX,mapY)])
				{
					if (opW9b_mapGrid.at(mapX,mapY) != shown.at(mapX,mapY))
					{
						shown.at(mapX,mapY) = opW9b_mapGrid.at(mapX,mapY);
						unknown48c460(mapAnimations[shown.at(mapX,mapY)],Pos(viewX,cy));
					}
				}
				else if (opW9b_mapLayers[shown.at(mapX,mapY)])
				{
					unknown48c460(eraseAnimation,Pos(viewX,cy));
					shown.at(mapX,mapY) = 21;
				}
			}
		}
	}

	if (opW9b_gameoverType == 4 && opW9b_tickCount > unknownb8 + 5)
	{
		Area area(0,0,getWidth_44b0d0() - 1,0);
		area.y2 = minInt((opW9b_tickCount - unknownb4) / 15 + 1,getHeight() - 1);
		area.x1 -= 10;
		area.x2 += 10;
		string variant = opW5_getEndingType();
		while (opW9b_tickCount > unknownb8 + 5)
		{
			string name;
			if (rng.chance(20))
			{
				int index;
				do
				{
					index = opW9b_randomIndex(opW9b_robotData);
				} while (opW9b_robotData[index]->unknown24 != 1);
				name += opW9b_robotData[index]->name;
				name += " ";
				for (int i = 0; i < 6; i++)
					name += opW9b_randomChar(opW9b_d33e1c);
			}
			else
			{
				int index;
				do
				{
					index = opW9b_randomIndex(opW9b_itemData);
				} while (opW9b_itemData[index]->unknown54 != 1 && opW9b_itemData[index]->unknown54 != 2);
				name += opW9b_itemData[index]->name;
				int number = rng.rangeInt(-10,10);
				if (number > 1)
					name += " x" + intToString(number);
			}
			name = opW9b_toUpper(name);
			Point pos = area.randomPoint_40be90();
			string anim;
			if (rng.chance(1))
			{
				name.insert(0,1,' ');
				name += " ";
				new CGameoverEndingText(this,pos.x,pos.y,name,"A_CGameover_0b10End2_" + variant,15);
			}
			else
				new CGameoverEndingText(this,pos.x,pos.y,name,"A_CGameover_0b10End1_" + variant,-1);
			unknownb8 += 5;
		}
	}

	if (opW9b_gameoverType == 7)
	{
		if (martyrPos.x == -1)
		{
			martyrPos.x = opW9b_center(76,getWidth_44b0d0());
			martyrPos.y = 40;
			string title = "[ WALL OF MARTYRS ]";
			Console *console = new Console(this,title.size(),1,martyrPos.x,martyrPos.y,4,false,-1);
			console->print(0,0,title);
			console->animate("A_Warlord_Martyr_Title");
			martyrPos.x++;
		}
		while (opW9b_tickCount > unknownb8 + 400)
		{
			martyrPos.y += 2;
			if (martyrPos.y >= getHeight() - 1)
			{
				martyrPos.y -= 2;
				removeSubconsole(martyrs[0]);
				removeVectorElement(martyrs,0);
				for (unsigned int i = 0; i < martyrs.size(); i++)
					martyrs[i]->setPos(martyrPos.x,martyrs[i]->getPos().y - 2);
			}
			string name = unknown7bdfd0();
			martyrs.push_back(new Console(this,name.size(),1,martyrPos.x,martyrPos.y,4,false,-1));
			martyrs.back()->print(0,0,name);
			int animation;
			opW9b_findAnimation("Warlord_Martyr_Name",&animation);
			for (int i = 0; i <= 7; i++)
				martyrs.back()->unknown48c460(animation,Pos(i,0));
			opW9b_findAnimation("Warlord_Martyr_Hyphen",&animation);
			martyrs.back()->unknown48c460(animation,Pos(9,0));
			opW9b_findAnimation("Warlord_Martyr_Cause",&animation);
			int last = martyrs.back()->getWidth_44b0d0() - 1;
			for (int i = 11; i <= last; i++)
				martyrs.back()->unknown48c460(animation,Pos(i,0));
			unknownb8 += 400;
		}
	}

	XConsole::update();
}

//==================================================================
// martyr lines
//==================================================================

template <class T>
class ItemSet	// NOTE: placeholder name
{
public:
	ItemSet();	// NOTE: placeholder name (0x9bab50)
	ItemSet(const int *weights, int count);	// NOTE: placeholder name (0x9ba790)
	~ItemSet();	// 0x700dd0
	T &pickRandom() throw();	// NOTE: placeholder name (0x9ba470)
	void add(T item, int weight);	// NOTE: placeholder name (0x9ba310)

	vector<T> items;	// NOTE: placeholder layout
	vector<int> weights;	// NOTE: placeholder name
	int total;	// NOTE: placeholder name
};

struct OpW9b_PropData	// NOTE: placeholder name
{
	char pad00[0x20];
	string name;	// NOTE: placeholder name
	char pad3c[0x8c - 0x3c];
	int unknown8c;	// NOTE: placeholder name
	char pad90[0x118 - 0x90];
	int unknown118;	// NOTE: placeholder name
	char pad11c[0x140 - 0x11c];
	int type;	// NOTE: placeholder name
	int weight;	// NOTE: placeholder name
	char pad148[0x150 - 0x148];
	int unknown150;	// NOTE: placeholder name
};
extern vector<OpW9b_PropData*> opW9b_propData;	// NOTE: placeholder name (0xcf35b0)
extern const int opW9b_martyrCauseWeights[];	// NOTE: placeholder name (0xbf94c4)
template <class T> T opW9b_pick(vector<T> &values);	// NOTE: placeholder name (0x9d5d00)
string opW9b_randomString(vector<string> &values);	// NOTE: placeholder name (0x9d3280)
bool opW9b_between(int lo, int v, int hi);	// NOTE: placeholder name (0x9daf80)

string CGameoverOverlay::unknown7bdfd0()
{
	string name;
	string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	for (int i = 0; i < 5; i++)
		name += opW9b_randomChar(chars);
	name.insert(name.begin() + 2,'-');
	name.insert(name.begin(),' ');
	name += "  - ";

	ItemSet<int> causes(opW9b_martyrCauseWeights,10);
	int cause = causes.pickRandom();
	if (cause <= 3)
	{
		name += "Destroyed by ";
		if (rng.chance(75))
		{
			ItemSet<int> robots;
			for (int i = 0; i < opW9b_robotData.size(); i++)
			{
				if (opW9b_robotData[i]->unknown139)
					robots.add(i,opW9b_robotData[i]->unknown68 <= 7 ? 10 : 1 - opW9b_robotData[i]->unknown68);
			}
			OpW9b_RobotData *robot = opW9b_robotData[robots.pickRandom()];
			name += robot->name + " with ";
			vector<int> weapons;
			for (int i = robot->parts.size() - 1; i >= 0; i--)
			{
				if (opW9b_itemData[robot->parts[i][0]->item]->unknown48 == 3)
				{
					if (opW9b_itemData[robot->parts[i][0]->item]->unknown44 != 0x19 && opW9b_itemData[robot->parts[i][0]->item]->unknown44 != 0x1d && opW9b_itemData[robot->parts[i][0]->item]->unknown44 != 0x1e)
						weapons.push_back(robot->parts[i][0]->item);
				}
				else
					break;
			}
			if (weapons.empty())
				name += "Unknown Weapon";
			else
				name += opW9b_itemData[opW9b_pick(weapons)]->name;
		}
		else
		{
			vector<int> items;
			for (int i = 0; i < opW9b_itemData.size(); i++)
			{
				switch (cause)
				{
					case 0:
						if (!opW9b_between(0x1a,opW9b_itemData[i]->unknown44,0x1c))
							continue;
						break;
					case 1:
						if (opW9b_itemData[i]->unknown44 != 0x14 && opW9b_itemData[i]->unknown44 != 0x16)
							continue;
						break;
					case 2:
						if (opW9b_itemData[i]->unknown44 != 0x15 && opW9b_itemData[i]->unknown44 != 0x17)
							continue;
						break;
					case 3:
						if (opW9b_itemData[i]->unknown44 != 0x18)
							continue;
						break;
				}
				if (opW9b_itemData[i]->unknown54 == 0 && opW9b_itemData[i]->unknown94 != 0)
					continue;
				if (!opW9b_itemData[i]->unknown273)
					continue;
				items.push_back(i);
			}
			name += opW9b_itemData[opW9b_pick(items)]->name;
		}
	}
	else
	{
		switch (cause)
		{
			case 4:
			{
				name += "Destroyed by exploding ";
				vector<int> props;
				for (int i = 0; i < opW9b_propData.size(); i++)
				{
					if (opW9b_propData[i]->unknown8c && opW9b_propData[i]->unknown118)
						props.push_back(i);
				}
				name += opW9b_propData[opW9b_pick(props)]->name;
				break;
			}
			case 5:
			{
				ItemSet<int> hazards;
				for (int i = 0; i < opW9b_propData.size(); i++)
				{
					if (opW9b_propData[i]->unknown150 == 0)
						hazards.add(i,opW9b_propData[i]->weight);
				}
				OpW9b_PropData *prop = opW9b_propData[hazards.pickRandom()];
				while (true)
				{
					switch (prop->type)
					{
						case 0:
							name += "Cut to pieces by " + prop->name;
							goto done;
						case 1:
							name += "Blasted by " + prop->name;
							goto done;
						case 2:
							name += "Destroyed by " + prop->name;
							goto done;
						case 4:
							name += "Corrupted by " + prop->name;
							goto done;
						case 8:
							name += "Corrupted by " + prop->name;
							goto done;
						case 13:
							name += "Succumbed to " + prop->name;
							goto done;
						case 14:
							name += "Sucked down " + prop->name;
							goto done;
						default:
							prop = opW9b_propData[hazards.pickRandom()];
							break;
					}
				}
done:
				break;
			}
			case 6:
			{
				name += "Destroyed by ";
				vector<int> items;
				for (int i = 0; i < opW9b_itemData.size(); i++)
				{
					if (opW9b_itemData[i]->unknown48 == 0 && opW9b_itemData[i]->unknown54 && opW9b_itemData[i]->unknown1a8)
						items.push_back(i);
				}
				name += opW9b_itemData[opW9b_pick(items)]->name;
				name += " chain reaction";
				break;
			}
			case 7:
				if (rng.chance(50))
					name += "Corrupted in " + opW9b_locationNames[opW9b_unknown7bdc70()];
				else
				{
					vector<OpW9b_RobotData*> robots;
					for (int i = 0; i < opW9b_robotData.size(); i++)
					{
						if (opW9b_robotData[i]->unknown28 == 0x19 && opW9b_robotData[i]->unknown24 == 1)
						{
							for (int j = i; j < opW9b_robotData.size(); j++)
							{
								if (opW9b_robotData[j]->unknown28 != 0x19)
									break;
								robots.push_back(opW9b_robotData[j]);
							}
							break;
						}
					}
					if (!robots.empty())
						name += "Corrupted by " + opW9b_pick(robots)->name;
				}
				break;
			case 8:
			{
				string zone = opW9b_locationNames[opW9b_unknown7bdc70()];
				string target = opW9b_locationNames[opW9b_unknown7bde70()];
				vector<string> deaths;
				deaths.push_back("Destroyed ");
				deaths.push_back("Destroyed ");
				deaths.push_back("Destroyed ");
				deaths.push_back("Destroyed ");
				deaths.push_back("Destroyed ");
				deaths.push_back("Destroyed ");
				deaths.push_back("Crushed by cave-in ");
				deaths.push_back("Corrupted ");
				deaths.push_back("Melted ");
				deaths.push_back("Fell ");
				deaths.push_back("Captured and scrapped ");
				deaths.push_back("Captured ");
				deaths.push_back("Short-circuited ");
				vector<string> places;
				places.push_back("during " + target + " assault");
				places.push_back("during " + target + " raid");
				places.push_back("during conquest of " + target);
				places.push_back("during " + zone + " reconnaissance");
				places.push_back("rescuing allies in " + zone);
				places.push_back("in " + zone);
				places.push_back("in " + zone);
				places.push_back("in " + zone);
				name += opW9b_randomString(deaths) + opW9b_randomString(places);
				break;
			}
			case 9:
			{
				vector<string> deaths;
				deaths.push_back("Crushed by blast door");
				deaths.push_back("Experimented on in Testing");
				deaths.push_back("Run over by Superbehemoth");
				deaths.push_back("Permanently disabled by malfunction");
				deaths.push_back("Disappeared searching for Lifeworm");
				deaths.push_back("Corrupted by P-50 Guru");
				deaths.push_back("Attempted to steal T-05 Blastbot components");
				deaths.push_back("Destroyed by X-52 Archer with Q-bolt");
				deaths.push_back("Corrupted by faulty component");
				deaths.push_back("Short-circuited during 0b10 Terminal hack");
				deaths.push_back("Fried while attempting to use RIF Installer");
				deaths.push_back("Overwhelmed by Garrison Access response");
				deaths.push_back("Discovered stuck in Recycling Unit hatch");
				deaths.push_back("Yelled WARLORD FOREVER on a stealth mission");
				deaths.push_back("Remained in vicinity of Demented for too long");
				deaths.push_back("Overloaded Mak. Laser too frequently");
				deaths.push_back("Destroyed by EX-DEC prototype test");
				deaths.push_back("Charged Martyr target squad instead of pulling back");
				deaths.push_back("Failed to disarm Fusion Bomb Trap");
				deaths.push_back("Encountered B-86 Titan while chasing down W-25 Informer");
				deaths.push_back("Encountered infestation in Mines");
				deaths.push_back("Trapped between infestation and Demolisher dispatch in Mines");
				deaths.push_back("Entombed by U-05 Engineer");
				deaths.push_back("Engaged C-40 Crusher in melee");
				deaths.push_back("Stood next to disabled C-40 Crusher that suddenly restarted");
				deaths.push_back("Acted as a diversion for approaching B-99 Colossus");
				deaths.push_back("Cored by CP-WKY misfire");
				deaths.push_back("Cored by T0-N31 misfire");
				deaths.push_back("Cored by DE-C1N misfire");
				deaths.push_back("Cored by V3-CTS misfire");
				name += opW9b_randomString(deaths);
				break;
			}
		}
	}
	return name;
}
