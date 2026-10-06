// Game UI consoles in 0x7c0000-0x9b0000 (CGameover, ...) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members, member names and method names are placeholders
//	unless stated otherwise (RTTI class names are real).
#include <string>
#include <vector>
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
	Pos(const Pos &pos);
	Pos &operator=(const Pos &pos);
	int distance(const Pos &pos) const;	// NOTE: placeholder name
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();
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
	void setHidden(bool hidden_) throw();	// NOTE: placeholder name
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	int printWrapped_418260(int x, int y, int width, int height, const string &text);	// NOTE: placeholder name
	XConsole *getParent();	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	void clearBack();	// NOTE: placeholder name
	void setForeRow(int x, int y, int width, XColor color);	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class Engine
{
public:
	void update();
	void stopAll();	// NOTE: placeholder name
	void killGroup(string group);
};

class Console : public XConsole
{
public:
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

class XMouse
{
public:
	Pos getPos_41a700();	// NOTE: placeholder name
};
extern XMouse *mouse;

class KeyMap	// NOTE: placeholder name
{
public:
	void unknown416640();	// NOTE: placeholder name
};
extern KeyMap *keyMap;	// NOTE: placeholder name

extern string gameStrings_d26040[];	// NOTE: placeholder name

extern bool consoleInputBlocked;	// NOTE: placeholder name
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

int unknown437190(int a, int b);	// NOTE: placeholder name ((b - a) / 2)

// command event passed to XConsole::input()
struct OpE_Command	// NOTE: placeholder name
{
	OpE_Command(int command_);

	int command;
	int data[2];
};

//==================================================================
// CGameover
//==================================================================

struct MapRecord
{
	char pad00[0x40];
	bool unknown40;	// NOTE: placeholder name
};
extern vector<MapRecord*> opE_mapRecords;	// NOTE: placeholder name (0xd389c4)

extern int opE_unknown_cf4b38;	// NOTE: placeholder name
extern int opE_unknown_cefaf4;	// NOTE: placeholder name
extern bool opE_unknown_cefacd;	// NOTE: placeholder name
extern XColor *opE_unknown_d20438;	// NOTE: placeholder name

class OpE_Unknown_cf45d8	// NOTE: placeholder name
{
public:
	bool unknown46dd50();	// NOTE: placeholder name
};
extern OpE_Unknown_cf45d8 opE_unknown_cf45d8;	// NOTE: placeholder name

class OpE_Unknown_cefaa8	// NOTE: placeholder name
{
public:
	void unknown792e90(const string &name);	// NOTE: placeholder name
};
extern OpE_Unknown_cefaa8 *opE_unknown_cefaa8;	// NOTE: placeholder name

class OpE_Unknown_cec148	// NOTE: placeholder name
{
public:
	bool unknown4b8e30();	// NOTE: placeholder name
	void unknown9aafd0();	// NOTE: placeholder name
};
extern OpE_Unknown_cec148 *opE_unknown_cec148;	// NOTE: placeholder name

class OpE_Rex	// NOTE: placeholder name
{
public:
	void unknown4262c0(int a, int b, int c, int d, string text);	// NOTE: placeholder name
};
extern OpE_Rex opE_rex;	// NOTE: placeholder name (0xd223f0)

class CEnding
{
public:
	CEnding();

	char data[0x1f4];
};

class CGameover;
class CGameoverMain : public Console
{
public:
	CGameoverMain(CGameover *parent, const Rect &rect);

	char pad6c[0x74 - 0x6c];
	unsigned int unknown74;	// NOTE: placeholder name
	Console *unknown78;	// NOTE: placeholder name (restart button)
	Console *unknown7c;	// NOTE: placeholder name (quit button)
	unsigned int unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	Console *unknown88;	// NOTE: placeholder name
};

void unknown7c15d0(bool flag);	// NOTE: placeholder name

class CGameover : public Console
{
public:
	virtual bool input(void *event);
	virtual void update();
	virtual void trigger(const string &command, int value);

	void unknown7bfe60();	// NOTE: placeholder name
	bool unknown7c0520(int command);	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	char pad6d[0x90 - 0x6d];
	unsigned int unknown90;	// NOTE: placeholder name
	CGameoverMain *stats;	// NOTE: placeholder name
	unsigned int unknown98;	// NOTE: placeholder name
	bool unknown9c;	// NOTE: placeholder name
};

void CGameover::update()
{
	if (isHidden())
		return;

	engine->update();

	if (unknown98)
	{
		if (tickCount > unknown98)
		{
			unknown7bfe60();
			unknown98 = 0;
		}
	}
	else
	{
		if (!unknown9c && opE_unknown_cf4b38 <= 9)
		{
			new CEnding();
			unknown9c = true;
		}
		else if (!stats && tickCount > unknown90 + 10000)
			trigger("show_stats",0);

		if (opE_unknown_cefaf4)
			input(&OpE_Command(0x19f));
		else
			XConsole::update();
	}
}

void CGameover::trigger(const string &command, int value)
{
	if (command == "show_stats" || command == "show_stats_win")
	{
		if ((opE_unknown_cf4b38 > 9 || command == "show_stats_win") && !stats)
		{
			Rect rect;
			rect.width = 50;
			rect.height = 26;
			for (int i = 7; i < 0x4a1; i++)
			{
				if (opE_mapRecords[i]->unknown40)
					rect.height++;
			}
			rect.height++;
			if (unknown6c)
				rect.height += 2;
			rect.x = unknown437190(rect.width / 2,getWidth());
			rect.y = unknown437190(rect.height,getHeight());
			stats = new CGameoverMain(this,rect);
		}
	}
	else if (command == "hide_cgameover")
		setHidden(true);
}

bool CGameover::unknown7c0520(int command)
{
	if (unknown6c)
	{
		bool restart = command == 0x19f;
		if (!stats->unknown80)
		{
			if (restart)
				stats->unknown78->animate("A_CGameoverButton_RestartConfirm");
			else
				stats->unknown7c->animate("A_CGameoverButton_QuitConfirm");
			stats->unknown80 = tickCount;
			stats->unknown84 = command;
			stats->unknown88 = new CText(stats,Pos(4,stats->unknown78->getPos().y - 1),"Repeat to confirm decision, will lose save",0,0,-1);
			stats->unknown88->setForeAll_4183d0(*opE_unknown_d20438);
			return true;
		}
		else if (command != stats->unknown84)
		{
			if (restart)
			{
				stats->unknown7c->animate("A_CGameoverButton_QuitReset");
				stats->unknown78->animate("A_CGameoverButton_RestartConfirm");
			}
			else
			{
				stats->unknown78->animate("A_CGameoverButton_RestartReset");
				stats->unknown7c->animate("A_CGameoverButton_QuitConfirm");
			}
			stats->unknown80 = tickCount;
			stats->unknown84 = command;
			return true;
		}
		else if (tickCount < stats->unknown80 + 1500 && !opE_unknown_cefacd && !opE_unknown_cf45d8.unknown46dd50())
			return true;
	}
	return false;
}

bool CGameover::input(void *event)
{
	if (isHidden() || consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	if (unknown98 || (opE_unknown_cec148 && !opE_unknown_cec148->unknown4b8e30()))
		return false;
	if ((tickCount < unknown90 + 2000 || !stats || tickCount < stats->unknown74 + 2000) && !opE_unknown_cefacd && !opE_unknown_cf45d8.unknown46dd50())
		return false;

	switch (*(int*)event)
	{
		case 0x19f:
			if (unknown7c0520(0x19f))
				return true;
			opE_unknown_cefaa8->unknown792e90("_manual_");
		case 0x19e:
		{
			if (!unknown6c && *(int*)event == 0x19e)
				return true;
			setHidden(true);
			if (opE_unknown_cec148)
				opE_unknown_cec148->unknown9aafd0();
			bool unknown = *(int*)event == 0x19e;
			opE_rex.unknown4262c0(0,0,0,0,"");
			unknown7c15d0(unknown);
			return true;
		}
		case 0x1a0:
			if (unknown7c0520(0x1a0))
				return true;
			opE_unknown_cefaa8->unknown792e90("_manual_");
			opE_rex.unknown4262c0(0,0,0,0,"");
			exit(0);
			return true;
	}
	return false;
}

void unknown408100(string &text, char c);	// NOTE: placeholder name

string unknown7c0ad0(const string &name)	// NOTE: placeholder name
{
	string text = name;
	unsigned int pos = text.find('/');
	if (pos != string::npos)
		text.erase(text.begin(),text.begin() + pos + 1);
	text.find('_');
	if (pos != string::npos)
		text.erase(text.begin(),text.begin() + pos + 1);
	unknown408100(text,'+');
	return text;
}

//==================================================================
// CHelp
//==================================================================

class CHelp;
extern CHelp *opE_help;	// NOTE: placeholder name (0xcec038)

class CHelp : public Console
{
public:
	virtual bool input(void *event);
	virtual void update();
	virtual void close();
	virtual void trigger(const string &command, int value);

	int content;	// NOTE: placeholder name
	Pos origin;	// NOTE: placeholder name
};

bool CHelp::input(void *event)
{
	if (isHidden() || consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	switch (*(int*)event)
	{
		case 0x182:
			close();
			return true;
	}
	return false;
}

void CHelp::update()
{
	if (isHidden())
		return;

	engine->update();

	if (origin.x == -1)
		origin = mouse->getPos_41a700();
	else if (origin.distance(mouse->getPos_41a700()) > 20)
	{
		close();
		return;
	}
	XConsole::update();
}

void CHelp::close()
{
	keyMap->unknown416640();
	opE_help = NULL;
	getParent()->removeSubconsole(this);
}

void CHelp::trigger(const string &command, int value)
{
	if (command == "print_content")
		printWrapped_418260(2,1,50,getHeight() - 2,gameStrings_d26040[content]);
}

//==================================================================
// CCommandsButton
//==================================================================

class ManualUI	// NOTE: placeholder name (pointer global at 0xcec03c; the CCommands window)
{
public:
	unsigned int unknown45b590();	// NOTE: placeholder name
	void unknown7d1050(int mode);	// NOTE: placeholder name
	void unknown7d1840();	// NOTE: placeholder name (next page)
	void unknown7d18d0();	// NOTE: placeholder name (previous page)
};
extern ManualUI *unknown_cec03c;	// NOTE: placeholder name

class CGallery : public Console
{
public:
	CGallery();

	char pad6c[0xc4 - 0x6c];
};

class CLore : public Console
{
public:
	CLore();

	char pad6c[0x98 - 0x6c];
};

class CSupporters : public Console
{
public:
	CSupporters(bool unknown);

	char pad6c[0xa0 - 0x6c];
};

bool unknown9d5080(bool *values, unsigned int count);	// NOTE: placeholder name (any true)

extern bool opE_unknown_d28d05;	// NOTE: placeholder name
extern bool opE_unknown_d25718;	// NOTE: placeholder name
extern string opE_unknown_d2571c;	// NOTE: placeholder name
extern bool opE_unknown_d25738;	// NOTE: placeholder name
extern int opE_unknown_cef818;	// NOTE: placeholder name
extern int opE_unknown_cef8b8;	// NOTE: placeholder name
extern int opE_unknown_cef960;	// NOTE: placeholder name
extern int opE_unknown_cef97c;	// NOTE: placeholder name

class CCommandsButton : public Console
{
public:
	virtual bool mouseEnter();
	virtual bool input(void *event);
	virtual void update();

	void draw(int mode);	// NOTE: placeholder name

	int ID;	// NOTE: placeholder name
	int state;	// NOTE: placeholder name
	bool attention[2];	// NOTE: placeholder name
};

void CCommandsButton::update()
{
	if (ID == 4)
	{
		switch (state)
		{
			case 0:
				if (opE_unknown_d28d05)
				{
					if (!opE_unknown_d25718)
						attention[0] = true;
					if (!opE_unknown_d25738 && !opE_unknown_d2571c.empty())
						attention[1] = true;
				}
				if (unknown9d5080(attention,2))
				{
					animate("A_F1_AttentionGlow");
					state = 1;
				}
				else
					state = 2;
				break;
			case 1:
				if (attention[0] && opE_unknown_d25718)
					attention[0] = false;
				if (attention[1] && opE_unknown_d25738)
					attention[1] = false;
				if (!unknown9d5080(attention,2))
				{
					state = 2;
					engine->killGroup("attnglo");
					draw(0);
				}
				break;
		}
	}
	engine->update();
}

bool CCommandsButton::input(void *event)
{
	switch (*(int*)event)
	{
		case 0x14:
			if (ID == 7)
				new CGallery();
			else if (ID == 8)
				new CLore();
			else if (ID == 9)
				new CSupporters(false);
			else if (ID == 10)
				new CSupporters(true);
			else if (unknown_cec03c->unknown45b590() != ID)
				unknown_cec03c->unknown7d1050(ID);
			return true;
	}
	return false;
}

void CCommandsButton::draw(int mode)
{
	engine->stopAll();
	clearBack();
	switch (mode)
	{
		case 0:
			unknown48c3c0(unknown_cec03c->unknown45b590() == ID ? opE_unknown_cef818 : opE_unknown_cef8b8);
			break;
		case 1:
			unknown48c3c0(opE_unknown_cef960);
			break;
		case 2:
			unknown48c3c0(opE_unknown_cef97c);
			break;
	}
}

bool CCommandsButton::mouseEnter()
{
	if (unknown_cec03c->unknown45b590() == ID)
		return false;
	animate("A_ButtonHover_Begin_CMOD_HOV_OK");
	return true;
}

//==================================================================
// CCommandsAdvancedPageButton
//==================================================================

extern XColor *opE_unknown_d2981c;	// NOTE: placeholder name
extern XColor *opE_unknown_d29758;	// NOTE: placeholder name

class CCommandsAdvancedPageButton : public Console
{
public:
	virtual bool input(void *event);

	void refresh();	// NOTE: placeholder name

	bool next;	// NOTE: placeholder name
	bool enabled;	// NOTE: placeholder name
};

bool CCommandsAdvancedPageButton::input(void *event)
{
	if (isHidden() || consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	switch (*(int*)event)
	{
		case 5:
			if (enabled)
			{
				if (next)
					unknown_cec03c->unknown7d1840();
				else
					unknown_cec03c->unknown7d18d0();
			}
			return true;
	}
	return false;
}

void CCommandsAdvancedPageButton::refresh()
{
	if (((ManualUI*)getParent())->unknown45b590() == 1)
		enabled = next;
	else
		enabled = !next;
	const XColor *fore = enabled ? opE_unknown_d2981c : opE_unknown_d29758;
	setForeRow(1,0,2,*fore);
}
