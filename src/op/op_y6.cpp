// op_y6: game UI consoles in 0x7c0000-0x8a0000 (CCommands*, CGamemenu*, ...) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

//==================================================================
// engine-side declarations
//==================================================================

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
};

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();
};

struct OpY6_Pos2	// NOTE: placeholder name
{
	int x;
	int y;
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

	bool isHidden();	// NOTE: placeholder name
	int getWidth();
	int getHeight();
	Pos getPos();
	void setHidden(bool hidden_);	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)

	char pad04[0x60 - 0x04];
};

class Engine
{
public:
	bool isRunning();	// NOTE: placeholder name (0x50fff0)
	void killGroup(string group);
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();

	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	void animate(string name);	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	void *title;
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	string text;
};

class OpY6_Mouse	// NOTE: placeholder name (pointer global at 0xcefa94)
{
public:
	bool isHovered(XConsole *console);	// NOTE: placeholder name (0x41a760)
};
extern OpY6_Mouse *opY6_mouse;	// NOTE: placeholder name

class OpY6_Rex	// NOTE: placeholder name (object at 0xd223f0)
{
public:
	int getHeight_4189a0();	// NOTE: placeholder name
};
extern OpY6_Rex opY6_rex;	// NOTE: placeholder name

extern bool opY6_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)
void opY6_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)
string opY6_toUpper(const string &text);	// NOTE: placeholder name (0x4083a0)
bool opY6_contains(vector<int> &values, int value);	// NOTE: placeholder name (0x9db330)
int opY6_centerOffset(int inner, int outer);	// NOTE: placeholder name (0x437190)

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern int opW5_anim_cef85c;	// NOTE: placeholder name
extern int opW5_anim_cef970;	// NOTE: placeholder name
extern int opW5_anim_cef978;	// NOTE: placeholder name

extern int opY6_fontCellSize;	// NOTE: placeholder name (0xcaf128)
extern int opY6_unknown_cf27f4;	// NOTE: placeholder name
extern int opY6_anim_cef884;	// NOTE: placeholder name
extern OpY6_Pos2 opY6_advancedPos;	// NOTE: placeholder name (0xd323bc)
extern bool opY6_unknown_d257d4;	// NOTE: placeholder name
extern bool opY6_unknown_d28d6c;	// NOTE: placeholder name
extern vector<int> opY6_unknown_d22590;	// NOTE: placeholder name
extern int opY6_achievementState_d28d84;	// NOTE: placeholder name
extern int opY6_achievementState_d28d88;	// NOTE: placeholder name
extern string opY6_strings_d2e8f8[];	// NOTE: placeholder name
extern string opY6_strings_d15db0[];	// NOTE: placeholder name
extern string opY6_strings_d1e1e0[];	// NOTE: placeholder name
extern string opY6_strings_d1e448[];	// NOTE: placeholder name
extern vector<bool> opY6_achievementCategories;	// NOTE: placeholder name (0xd28d70)

//==================================================================
// CCommands*
//==================================================================

class CCommandsAdvancedPageButton : public Console
{
public:
	virtual bool mouseEnter();

	bool next;	// NOTE: placeholder name
	bool enabled;	// NOTE: placeholder name
};

//==================================================================
// CGamemenu*
//==================================================================

extern int opW5_anim_cef85c;	// NOTE: placeholder name
extern int opW5_anim_cef970;	// NOTE: placeholder name
extern int opW5_anim_cef978;	// NOTE: placeholder name

class CGamemenuButton : public Console
{
public:
	virtual bool mouseEnter();

	int key;	// NOTE: placeholder name
	int index;	// NOTE: placeholder name
};

class CGamemenuSaveloadButton : public Console
{
public:
	virtual bool mouseEnter();

	int type;	// NOTE: placeholder name
	char pad70[0x88 - 0x70];
	bool hasSave;	// NOTE: placeholder name
};

//==================================================================
// CCommands (the Manual window; global pointer at 0xcec03c) and related
//==================================================================

struct OpY6_ManualSection	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	string title;	// NOTE: placeholder name
	vector<string> lines;	// NOTE: placeholder name
	vector<int> headers;	// NOTE: placeholder name
};
extern vector<OpY6_ManualSection*> opY6_manualSections;	// NOTE: placeholder name (0xcf39dc)

class CManualButton : public Console
{
public:
	void unknown7c56e0();	// NOTE: placeholder name
};

class CManualText : public Console
{
public:
	CManualText(XConsole *parent, int y, const string &text, bool header_);

	bool header;	// NOTE: placeholder name
};

class CManualPageButton : public Console
{
public:
	CManualPageButton(XConsole *parent, bool flag_);

	bool flag;	// NOTE: placeholder name
};

class CCommandsButton : public Console
{
public:
	void draw(int mode);	// NOTE: placeholder name
};

class CCommandPage : public XConsole	// NOTE: placeholder name
{
public:
	int getPage() { return page; };	// NOTE: placeholder name

	char pad[0x6c - sizeof(XConsole)];
	int page;
};

class CCommands : public Console
{
public:
	void setAdvancedCommandsPage(int page);

	void unknown7d1050(int mode);	// NOTE: placeholder name
	void unknown7d1130();	// NOTE: placeholder name
	void unknown7d1340();	// NOTE: placeholder name
	void unknown7d14d0(int section);	// NOTE: placeholder name
	void unknown7d1740();	// NOTE: placeholder name
	void unknown7d17d0();	// NOTE: placeholder name
	void unknown7d1840();	// NOTE: placeholder name
	void unknown7d18d0();	// NOTE: placeholder name
	int unknown7c6830();	// NOTE: placeholder name
	int getMaxHeight();	// NOTE: placeholder name (0x4963e0)
	int getRange();	// NOTE: placeholder name (0x496560)

	int ID;	// NOTE: placeholder name
	vector<CCommandsButton*> tabButtons;	// NOTE: placeholder name
	char pad80[0xc4 - 0x80];
	CCommandPage *pageIndicator;	// NOTE: placeholder name
	char padc8[0xd0 - 0xc8];
	CText *title;	// NOTE: placeholder name
	vector<CManualButton*> sectionButtons;	// NOTE: placeholder name
	int page;	// NOTE: placeholder name
	vector<Console*> lines;	// NOTE: placeholder name
	int scroll;	// NOTE: placeholder name
	int unknownfc;	// NOTE: placeholder name
	int prevPage;	// NOTE: placeholder name
	CManualPageButton *nextButton;	// NOTE: placeholder name
	CManualPageButton *prevButton;	// NOTE: placeholder name
};

void CCommands::unknown7d1050(int mode)
{
	if (ID == mode || tabButtons.empty())
		return;
	tabButtons[ID]->draw(1);
	ID = mode;
	tabButtons[ID]->draw(2);
	switch (ID)
	{
		case 0:
			opY6_unknown_d28d6c = false;
			break;
		case 1:
			opY6_unknown_d28d6c = true;
			break;
		case 2:
			opY6_unknown_d22590[13] = 1;
			break;
		case 3:
			opY6_unknown_d22590[8] = 1;
			break;
	}
	open();
}

void CCommands::unknown7d1340()
{
	if (scroll == 0)
	{
		if (prevButton)
		{
			removeSubconsole(prevButton);
			prevButton = NULL;
		}
	}
	else if (prevButton == NULL)
		prevButton = new CManualPageButton(this,false);
	if (getRange() + scroll >= opY6_manualSections[page]->lines.size())
	{
		if (nextButton)
		{
			removeSubconsole(nextButton);
			nextButton = NULL;
		}
	}
	else if (nextButton == NULL)
		nextButton = new CManualPageButton(this,true);
}

void CCommands::unknown7d14d0(int section)
{
	if ((!lines.empty() && page == section) || section >= opY6_manualSections.size())
		return;
	if (title && title)
	{
		removeSubconsole(title);
		title = NULL;
	}
	title = new CText(this,Pos(opY6_centerOffset(0x60,opY6_unknown_cf27f4 * opY6_fontCellSize) + 0x1c,opY6_advancedPos.y + 2),opY6_toUpper(opY6_manualSections[section]->title),0,0,-1);
	title->unknown48c3c0(opY6_anim_cef884);
	if (opY6_manualSections[section]->title == "Survival Tips")
		opY6_unknown_d257d4 = true;
	prevPage = page;
	page = section;
	sectionButtons[prevPage]->unknown7c56e0();
	sectionButtons[section]->unknown7c56e0();
	if (prevPage != section)
		scroll = 0;
	unknown7d1130();
	unknown7d1340();
	unknown60 = 2;
	unknownfc = 1;
}

void CCommands::unknown7d1740()
{
	if (ID != 2)
		return;
	if (getRange() + scroll >= opY6_manualSections[page]->lines.size())
		return;
	scroll += getRange();
	unknown7d1130();
	unknown7d1340();
	unknown60 = 2;
	unknownfc = 2;
}

void CCommands::unknown7d17d0()
{
	if (ID != 2)
		return;
	if (scroll == 0)
		return;
	scroll -= getRange();
	unknown7d1130();
	unknown7d1340();
	unknown60 = 2;
	unknownfc = 2;
}

void CCommands::unknown7d1840()
{
	switch (ID)
	{
		case 1:
			if (pageIndicator && pageIndicator->getPage() == 1)
				setAdvancedCommandsPage(2);
			break;
		case 2:
			unknown7d14d0((page == opY6_manualSections.size() - 1) ? 0 : page + 1);
			break;
	}
}

void CCommands::unknown7d18d0()
{
	switch (ID)
	{
		case 1:
			if (pageIndicator && pageIndicator->getPage() == 2)
				setAdvancedCommandsPage(1);
			break;
		case 2:
			unknown7d14d0((page == 0) ? opY6_manualSections.size() - 1 : page - 1);
			break;
	}
}

//==================================================================
// Collection consoles (CLore*, CAchievements*, CSupporters*)
//==================================================================

class CLore : public Console
{
public:
	virtual ~CLore();

	void unknown7e91e0();	// NOTE: placeholder name
	void unknown7ebd60(int key);	// NOTE: placeholder name
	int getSelected();	// NOTE: placeholder name (0x4a9230)
};
extern CLore *opY6_lore;	// NOTE: placeholder name (0xcec044)

class CLoreDetails : public Console
{
public:
	virtual bool input(void *event);
};

bool CLoreDetails::input(void *event)
{
	if (isHidden() || opY6_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	switch (*(int*)event)
	{
		case 0x2d:
			opY6_lore->unknown7e91e0();
			return true;
	}
	return false;
}

struct OpY6_LoreEntry	// NOTE: placeholder name
{
	int key;	// NOTE: placeholder name
	bool known;	// NOTE: placeholder name
};

class CLoreItem : public Console
{
public:
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual void update();

	OpY6_LoreEntry *entry;	// NOTE: placeholder name
};

void CLoreItem::update()
{
	if (isHidden())
		return;
	engine->isRunning();
	if (opY6_mouse->isHovered(this))
	{
		if (opY6_lore->getSelected() != entry->key)
			opY6_lore->unknown7ebd60(entry->key);
	}
	updateBase429e30();
}

bool CLoreItem::mouseEnter()
{
	if (!entry->known)
		return false;
	animate("A_CLoreItem_Hover_Begin");
	return true;
}

void CLoreItem::mouseLeave()
{
	if (!entry->known)
		return;
	engine->killGroup("fadein");
	animate("A_CLoreItem_Hover_End");
}

class CAchievements : public Console
{
public:
	virtual ~CAchievements();
};
extern CAchievements *opY6_achievements;	// NOTE: placeholder name (0xcec048)

class CAchievementsCategoryButton : public Console
{
public:
	virtual bool mouseEnter();
	virtual bool input(void *event);

	int category;	// NOTE: placeholder name
};

bool CAchievementsCategoryButton::input(void *event)
{
	switch (*(int*)event)
	{
		case 0x26:
			opY6_achievements->inputMouse(tolower(opY6_strings_d2e8f8[category][0]),0);
			return true;
	}
	return false;
}

bool CAchievementsCategoryButton::mouseEnter()
{
	if (opY6_achievementCategories[category])
		animate("A_ButtonHover_Begin_Achieve_" + opY6_strings_d15db0[category] + "_HOV_OK");
	else
		animate("A_ButtonHover_Begin_Achieve_OFF_HOV_OK");
	return true;
}

class CAchievementsCategoryToggleAllButton : public Console
{
public:
	virtual bool input(void *event);
};

bool CAchievementsCategoryToggleAllButton::input(void *event)
{
	switch (*(int*)event)
	{
		case 0x26:
			opY6_achievements->inputMouse(0x31,2);
			return true;
	}
	return false;
}

class CAchievementsStateButton : public Console
{
public:
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);

	int state;	// NOTE: placeholder name
	bool primary;	// NOTE: placeholder name
};

bool CAchievementsStateButton::mouseEnter()
{
	if ((primary ? opY6_achievementState_d28d84 : opY6_achievementState_d28d88) == state)
		return false;
	animate("A_AchieveState_HoverGo");
	return true;
}

void CAchievementsStateButton::mouseLeave()
{
	engine->killGroup("fadein");
	if ((primary ? opY6_achievementState_d28d84 : opY6_achievementState_d28d88) == state)
		return;
	animate("A_AchieveState_HoverEnd");
}

class CSupporters : public Console
{
public:
	void unknown7f30e0(int offset);	// NOTE: placeholder name
	int unknown7f3790();	// NOTE: placeholder name
	int unknown7f37b0();	// NOTE: placeholder name
};
extern CSupporters *opY6_supporters;	// NOTE: placeholder name (0xcec04c)

class CSupporterCountButton : public Console
{
public:
	virtual bool mouseEnter();
	virtual bool input(void *event);

	bool flag;	// NOTE: placeholder name
};

bool CSupporterCountButton::input(void *event)
{
	switch (*(int*)event)
	{
		case 0x26:
			if (flag)
				opY6_supporters->unknown7f30e0(-((opY6_rex.getHeight_4189a0() - 0xd) / 2));
			else
				opY6_supporters->unknown7f30e0((opY6_rex.getHeight_4189a0() - 0xd) / 2);
			return true;
	}
	return false;
}

bool CSupporterCountButton::mouseEnter()
{
	if ((flag && !opY6_supporters->unknown7f3790()) || (!flag && !opY6_supporters->unknown7f37b0()))
		return false;
	animate("A_ButtonHover_Begin_CMOD_HOV_OK");
	return true;
}
