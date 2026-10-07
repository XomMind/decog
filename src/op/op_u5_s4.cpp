// op_u5_s4: Console-derived UI functions in 0x7ac000-0x7c7000 of COGMIND.exe (Beta 17.1). Names are placeholders unless stated.
#include <string>
#include <vector>
#include <stdlib.h>
#include "../thirdparty/zfstream.h"
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
	Pos &operator+=(const Pos &pos);	// 0x409a30
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
	XConsole *getParent();	// 0x9b8f00
	int getWidth();	// 0x44b0d0
	bool isWide();
	void setPos(const Pos &pos);	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	Pos getPos();	// 0x40a970
	int getHeight();
	int getChar(int x, int y);
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	bool isVisible();	// NOTE: placeholder name
	bool hasSubconsoles();	// NOTE: placeholder name
	vector<XConsole*> *getSubconsoles() throw();
	void setForeRow(int x, int y, int width, XColor color);	// NOTE: placeholder name
	void clearInterior();
	void clear();	// NOTE: placeholder name
	void setFore(XColor color) throw();	// NOTE: placeholder name
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	bool input429d00(void *event);	// NOTE: placeholder name (XConsole::input body)
	void setHidden(bool hidden_);	// NOTE: placeholder name
	void update429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)

	char pad04[0x60 - 0x04];
};

class Engine
{
public:
	bool update();	// NOTE: placeholder name (0x50fff0)
	void killGroup(string group);
};

class ConsoleTitle;

class Console : public XConsole
{
public:
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void unknown48c460(int anim, const Pos &pos);	// NOTE: placeholder name
	void drawBorder_7c6510(Console *source, const Pos *pos, int width, int height);	// NOTE: placeholder name (0x7c6510)

	int unknown60;
	Engine *engine;
	ConsoleTitle *title;
};

class ConsoleTitle : public Console
{
public:
	string text;	// NOTE: placeholder name
	int align;	// NOTE: placeholder name
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class OpU5s4_Mode	// NOTE: placeholder name (folded getter 0x4ab670)
{
public:
	int getMode_4ab670();	// NOTE: placeholder name
};

//==================================================================
// CGamemenu*
//==================================================================

class CGamemenuButtonText : public Console
{
public:
	CGamemenuButtonText(XConsole *parent, int x, int y, const string &text);
};

class CMission : public Console	// NOTE: partial (see op_q4e_ui.cpp)
{
public:
	void unknown4b32c0();	// NOTE: placeholder name
	void unknown4b32e0();	// NOTE: placeholder name
	void unknown988a30();	// NOTE: placeholder name
	void unknown988ad0(bool flag);	// NOTE: placeholder name
	void unknown988d30();	// NOTE: placeholder name
};
extern CMission *opU5s4_cec034;	// NOTE: placeholder name

class CGamemenuButton;

class OpU5s4_Gamemenu	// NOTE: placeholder name (0xcec03c)
{
public:
	vector<CGamemenuButton*> *getButtons_4968a0();	// NOTE: placeholder name
};
extern OpU5s4_Gamemenu *opU5s4_gamemenu;	// NOTE: placeholder name (0xcec03c)

extern bool opU5s4_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern int opU5s4_cef8c0;	// NOTE: placeholder name
extern string gameString_d33d58;	// NOTE: placeholder name
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
int opU5s4_centerOffset(int inner, int outer);	// NOTE: placeholder name (0x437190)
void opU5s4_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)

class CGamemenuButton : public Console
{
public:
	virtual bool input(void *event);
	virtual void mouseLeave();

	int key;	// NOTE: placeholder name
	int index;	// NOTE: placeholder name
	CGamemenuButtonText *keyText;	// NOTE: placeholder name
	CGamemenuButtonText *nameText;	// NOTE: placeholder name
	CGamemenuButtonText *infoText;	// NOTE: placeholder name
	CGamemenuButtonText *confirmText;	// NOTE: placeholder name
	unsigned int confirmTime;	// NOTE: placeholder name
};

bool CGamemenuButton::input(void *event)
{
	if (isHidden() || opU5s4_consoleInputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (((XEvent*)event)->type)
	{
	case 0x14:
		if (confirmText != NULL || index == 0)
		{
			if (tickCount < confirmTime)
				break;
			switch (index)
			{
			case 0:
				opU5s4_cec034->unknown988d30();
				break;
			case 1:
				opU5s4_cec034->unknown988ad0(false);
				break;
			case 2:
				opU5s4_cec034->unknown988a30();
				break;
			}
		}
		else
		{
			vector<CGamemenuButton*> *buttons = opU5s4_gamemenu->getButtons_4968a0();
			for (unsigned int i = 0; i < buttons->size(); i++)
			{
				if ((*buttons)[i]->confirmText != NULL)
				{
					(*buttons)[i]->nameText->setHidden(false);
					(*buttons)[i]->confirmText->getParent()->removeSubconsole((*buttons)[i]->confirmText);
					(*buttons)[i]->confirmText = NULL;
					(*buttons)[i]->confirmTime = 0;
					break;
				}
			}
			confirmText = new CGamemenuButtonText(this,opU5s4_centerOffset(gameString_d33d58.size(),getWidth()),2,gameString_d33d58);
			confirmText->unknown48c3c0(opU5s4_cef8c0);
			nameText->setHidden(true);
			confirmTime = tickCount + 1000;
			opU5s4_playSound(0x33,0,0);
		}
		return true;
	}
	return false;
}

void CGamemenuButton::mouseLeave()
{
	engine->killGroup("hover");
	clearInterior();
}

class Unknown_c34b30 : public Console	// CGamemenuSaveloadButtonText
{
public:
	Unknown_c34b30(XConsole *parent, int x, int y, const string &text);	// 0x495a10
};

class OpU5s4_PlayerData	// NOTE: placeholder name (object at 0xcf45d8)
{
public:
	bool isFlagActive_46d8b0();	// NOTE: placeholder name
};
extern OpU5s4_PlayerData opU5s4_playerData;	// NOTE: placeholder name (0xcf45d8)
extern int opU5s4_cf4718;	// NOTE: placeholder name

class REX
{
public:
	void renderRoot();	// 0x426c00
};
extern REX rex;	// 0xd223f0

class CGamemenuSaveloadButton;

class OpU5s4_GamemenuB	// NOTE: placeholder name (0xcec03c)
{
public:
	vector<CGamemenuSaveloadButton*> *getButtons_4968c0();	// NOTE: placeholder name
	void unknown7d0a80();	// NOTE: placeholder name
};
extern OpU5s4_GamemenuB *opU5s4_gamemenuB;	// NOTE: placeholder name (0xcec03c)

class OpU5s4_MapView	// NOTE: placeholder name (0xcec054)
{
public:
	void unknown49ad70(unsigned int time);	// NOTE: placeholder name
};
extern OpU5s4_MapView *opU5s4_mapView;	// NOTE: placeholder name (0xcec054)
extern XColor *opU5s4_color_d20b70;	// NOTE: placeholder name

class CGamemenuSaveloadButton : public Console
{
public:
	virtual bool input(void *event);
	virtual void mouseLeave();

	int type;	// NOTE: placeholder name
	Unknown_c34b30 *keyText;	// NOTE: placeholder name
	Unknown_c34b30 *nameText;	// NOTE: placeholder name
	Unknown_c34b30 *saveText;	// NOTE: placeholder name
	Unknown_c34b30 *infoText;	// NOTE: placeholder name
	Unknown_c34b30 *confirmText;	// NOTE: placeholder name
	unsigned int confirmTime;	// NOTE: placeholder name
	bool hasSave;	// NOTE: placeholder name
};

bool CGamemenuSaveloadButton::input(void *event)
{
	if (isHidden() || opU5s4_consoleInputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (((XEvent*)event)->type)
	{
	case 0x14:
		if (opU5s4_playerData.isFlagActive_46d8b0() || opU5s4_cf4718 == 0)
			return true;
		if (type == 1 && !hasSave)
			return true;
		if (confirmText != NULL)
		{
			if (tickCount < confirmTime)
				break;
			switch (type)
			{
			case 0:
				confirmText->clear();
				confirmText->setFore(*opU5s4_color_d20b70);
				confirmText->print(0,0," SAVING... ");
				rex.renderRoot();
				opU5s4_gamemenuB->unknown7d0a80();
				opU5s4_cec034->unknown4b32c0();
				opU5s4_cec034->input(&XEvent(8));
				opU5s4_mapView->unknown49ad70(tickCount + 250);
				break;
			case 1:
				confirmText->clear();
				confirmText->setFore(*opU5s4_color_d20b70);
				confirmText->print(0,0," LOADING...");
				rex.renderRoot();
				opU5s4_gamemenuB->unknown7d0a80();
				opU5s4_cec034->unknown4b32e0();
				opU5s4_cec034->input(&XEvent(0xa));
				opU5s4_mapView->unknown49ad70(tickCount + 250);
				break;
			}
		}
		else
		{
			vector<CGamemenuSaveloadButton*> *buttons = opU5s4_gamemenuB->getButtons_4968c0();
			for (unsigned int i = 0; i < buttons->size(); i++)
			{
				if ((*buttons)[i]->confirmText != NULL)
				{
					(*buttons)[i]->nameText->setHidden(false);
					(*buttons)[i]->confirmText->getParent()->removeSubconsole((*buttons)[i]->confirmText);
					(*buttons)[i]->confirmText = NULL;
					(*buttons)[i]->confirmTime = 0;
					break;
				}
			}
			confirmText = new Unknown_c34b30(this,opU5s4_centerOffset(gameString_d33d58.size(),getWidth()),2,gameString_d33d58);
			confirmText->unknown48c3c0(opU5s4_cef8c0);
			nameText->setHidden(true);
			confirmTime = tickCount + 250;
			opU5s4_playSound(0x33,0,0);
		}
		return true;
	}
	return false;
}

void CGamemenuSaveloadButton::mouseLeave()
{
	engine->killGroup("hover");
	clearInterior();
}

class OpU5s4_Button : public Console	// NOTE: placeholder name
{
public:
	void setHighlight_7c2cd0();	// NOTE: placeholder name (0x7c2cd0)

	bool unknown6c;
	bool unknown6d;
};

extern XColor *opU5s4_color_d2981c;	// NOTE: placeholder name
extern XColor *opU5s4_color_d29758;	// NOTE: placeholder name

void OpU5s4_Button::setHighlight_7c2cd0()
{
	if (((OpU5s4_Mode*)getParent())->getMode_4ab670() == 1)
		unknown6d = unknown6c;
	else
		unknown6d = !unknown6c;
	setForeRow(1,0,2,unknown6d ? *opU5s4_color_d2981c : *opU5s4_color_d29758);
}

class OpU5s4_Page : public Console	// NOTE: placeholder name
{
public:
	bool isDone_7ad420();	// NOTE: placeholder name (0x7ad420)
};

bool OpU5s4_Page::isDone_7ad420()
{
	if (unknown60 != 0 && unknown60 != 3)
		return false;
	if (hasSubconsoles())
	{
		vector<XConsole*> *subconsoles = getSubconsoles();
		for (unsigned int i = 0; i < subconsoles->size(); i++)
		{
			if (!((OpU5s4_Page*)(*subconsoles)[i])->isDone_7ad420())
				return false;
		}
	}
	return true;
}

void Console::setTitle(ConsoleTitle *title_)
{
	if (title != NULL)
	{
		removeSubconsole(title);
		title = NULL;
	}
	title = title_;
	switch (title->align)
	{
	case 0:
		title->setPos(Pos(getWidth() / 2 - title->text.size() / (title->isWide() ? 1 : 2),0));
		break;
	case 1:
		title->setPos(Pos(2 - (isWide() ? 1 : 0),0));
		break;
	case 2:
		title->setPos(Pos(1,0));
		break;
	case 3:
		title->setPos(Pos(getWidth() - (2 - (isWide() ? 1 : 0)) - 1 - title->text.size(),0));
		break;
	case 4:
		title->setPos(Pos(getWidth() - (isWide() ? 1 : 0) - 1 - title->text.size(),0));
		break;
	}
}

class OpU5s4_DataLoader	// NOTE: placeholder name (0xcefaa8)
{
public:
	bool unknown792b10();	// 0x792b10
};
extern OpU5s4_DataLoader *opU5s4_dataLoader;	// NOTE: placeholder name (0xcefaa8)
extern vector<int> opU5s4_d1d078;	// NOTE: placeholder name

class CBD
{
public:
	CBD();	// 0x7ac590
	~CBD();

	char pad00[0x2c];
};
extern CBD *opU5s4_cbd;	// NOTE: placeholder name (0xcefc14)

void OpU5s4_recreateCBD_7ad350()	// NOTE: placeholder name (0x7ad350)
{
	if (opU5s4_d1d078.empty())
		opU5s4_dataLoader->unknown792b10();
	else
		delete opU5s4_cbd;
	opU5s4_cbd = new CBD();
}

class OpU5s4_Window1	// NOTE: placeholder name
{
public:
	OpU5s4_Window1();	// NOTE: placeholder name (0x7d8d60)
	char pad00[0xc4];
};

class OpU5s4_Window2	// NOTE: placeholder name
{
public:
	OpU5s4_Window2();	// NOTE: placeholder name (0x7e8ee0)
	char pad00[0x98];
};

class OpU5s4_Window3	// NOTE: placeholder name
{
public:
	OpU5s4_Window3();	// NOTE: placeholder name (0x7ee700)
	char pad00[0xb8];
};

class OpU5s4_Manual	// NOTE: placeholder name (0xcec03c)
{
public:
	void unknown7d6690();	// NOTE: placeholder name
};
extern OpU5s4_Manual *opU5s4_manual;	// NOTE: placeholder name (0xcec03c)

class CCommandsLetterButton : public Console
{
public:
	virtual bool input(void *event);

	int type;	// NOTE: placeholder name
};

bool CCommandsLetterButton::input(void *event)
{
	switch (((XEvent*)event)->type)
	{
	case 0x14:
		if (type == 0)
			new OpU5s4_Window1();
		else if (type == 1)
			new OpU5s4_Window2();
		else if (type == 2)
			new OpU5s4_Window3();
		else if (type == 3)
			opU5s4_manual->unknown7d6690();
		return true;
	default:
		return false;
	}
}

extern int opU5s4_mode_cf4b38;	// NOTE: placeholder name
extern int opU5s4_cefaf4;	// NOTE: placeholder name

class OpU5s4_Stats	// NOTE: placeholder name
{
public:
	OpU5s4_Stats();	// NOTE: placeholder name (0x998090)
	char pad00[0x1f4];
};

class OpU5s4_Gameover : public Console	// NOTE: placeholder name (CGameover, see op_e.cpp)
{
public:
	virtual void update();

	void unknown7bfe60();	// NOTE: placeholder name

	char pad6c[0x90 - 0x6c];
	unsigned int unknown90;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
	unsigned int unknown98;	// NOTE: placeholder name
	bool unknown9c;	// NOTE: placeholder name
};

void OpU5s4_Gameover::update()
{
	if (isHidden())
		return;
	engine->update();
	if (unknown98 != 0)
	{
		if (tickCount > unknown98)
		{
			unknown7bfe60();
			unknown98 = 0;
		}
		return;
	}
	if (!unknown9c && opU5s4_mode_cf4b38 <= 9)
	{
		new OpU5s4_Stats();
		unknown9c = true;
	}
	else if (unknown94 == 0 && tickCount > unknown90 + 10000)
		trigger("show_stats",0);
	if (opU5s4_cefaf4 != 0)
		input(&XEvent(0x19f));
	else
		update429e30();
}

//==================================================================
// game menu
//==================================================================

class OpU5s4_Graph	// NOTE: placeholder name (OpS_Graph, object pointer at 0xcefa8c)
{
public:
	void setMarked(unsigned int index, bool marked);
};
extern OpU5s4_Graph *opU5s4_graph;	// NOTE: placeholder name (0xcefa8c)

class OpU5s4_GM	// NOTE: placeholder name (object at 0xcefaa8)
{
public:
	void endGame();
	bool readyGame(bool a, bool b, bool c);	// NOTE: placeholder name
	void unknown78c050();	// NOTE: placeholder name
};
extern OpU5s4_GM *opU5s4_gm;	// NOTE: placeholder name (0xcefaa8)

int opU5s4_unknown77e2b0(gzifstream &stream, bool chrono, bool manual);	// NOTE: placeholder name

extern XConsole *opU5s4_cec0f4;	// NOTE: placeholder name
extern XConsole *opU5s4_cec0b0;	// NOTE: placeholder name
extern XConsole *opU5s4_cec0d0;	// NOTE: placeholder name
extern XConsole *opU5s4_cec0c8;	// NOTE: placeholder name
extern XConsole *opU5s4_cec0cc;	// NOTE: placeholder name
extern XConsole *opU5s4_cec0b8;	// NOTE: placeholder name
extern XConsole *opU5s4_cec0c0;	// NOTE: placeholder name
extern XConsole *opU5s4_cec0e4;	// NOTE: placeholder name
extern XConsole *opU5s4_cec0e8;	// NOTE: placeholder name
extern XConsole *opU5s4_cec0ec;	// NOTE: placeholder name
extern XConsole *opU5s4_cec054;	// NOTE: placeholder name
extern XConsole *opU5s4_cec058;	// NOTE: placeholder name
extern XConsole *opU5s4_cec074;	// NOTE: placeholder name
extern XConsole *opU5s4_cec078;	// NOTE: placeholder name
extern XConsole *opU5s4_cec07c;	// NOTE: placeholder name
extern XConsole *opU5s4_cec084;	// NOTE: placeholder name
extern XConsole *opU5s4_cec088;	// NOTE: placeholder name
extern XConsole *opU5s4_cec08c;	// NOTE: placeholder name
extern XConsole *opU5s4_cec138;	// NOTE: placeholder name
extern int opU5s4_consoleMode;	// NOTE: placeholder name (0xd28d64)
extern bool opU5s4_d28c8a;	// NOTE: placeholder name
extern int opU5s4_cebd5c;	// NOTE: placeholder name
extern bool opU5s4_cefacd;	// NOTE: placeholder name
extern int opU5s4_cf4614;	// NOTE: placeholder name

void opU5s4_showGameUi_7c15d0(bool load)	// NOTE: placeholder name (0x7c15d0)
{
	opU5s4_cec034->setHidden(false);
	opU5s4_cec0f4->setHidden(false);
	opU5s4_cec0b0->setHidden(false);
	opU5s4_cec0d0->setHidden(false);
	switch (opU5s4_consoleMode)
	{
	case 0:
		opU5s4_cec0c8->setHidden(false);
		break;
	case 1:
		opU5s4_cec0cc->setHidden(false);
		break;
	case 2:
		opU5s4_cec0b8->setHidden(false);
		break;
	case 3:
		opU5s4_cec0c0->setHidden(false);
		break;
	}
	opU5s4_cec0e4->setHidden(!(!opU5s4_d28c8a && opU5s4_cec0d0->isVisible()));
	opU5s4_cec0e8->setHidden(!(opU5s4_cec0d0->isVisible() && opU5s4_cebd5c == 2));
	opU5s4_cec0ec->setHidden(!(opU5s4_cec0d0->isVisible() && opU5s4_cebd5c == 2));
	opU5s4_cec054->setHidden(false);
	opU5s4_cec058->setHidden(false);
	opU5s4_cec074->setHidden(false);
	opU5s4_cec078->setHidden(false);
	opU5s4_cec07c->setHidden(false);
	opU5s4_cec084->setHidden(false);
	opU5s4_cec088->setHidden(false);
	opU5s4_cec08c->setHidden(false);
	opU5s4_cec138->setHidden(false);
	opU5s4_graph->setMarked(4,true);
	opU5s4_graph->setMarked(5,opU5s4_cefacd);
	opU5s4_graph->setMarked(7,true);
	opU5s4_graph->setMarked(0x23,false);
	if (load)
	{
		gzifstream stream;
		if (!opU5s4_unknown77e2b0(stream,false,true))
		{
			stream.close();
			int turn = opU5s4_cf4614;
			opU5s4_gm->endGame();
			if (!opU5s4_gm->readyGame(false,false,true))
				exit(1);
			opU5s4_gm->unknown78c050();
			opU5s4_cf4614 = turn + 1;
			return;
		}
	}
	opU5s4_cec034->unknown988ad0(false);
}

extern int opU5s4_anim_cef8bc;	// NOTE: placeholder name

void Console::drawBorder_7c6510(Console *source, const Pos *pos, int width, int height)
{
	const Pos &base = pos ? *pos : source->getPos();
	int w = width ? width : source->getWidth();
	int h = height ? height : source->getHeight();
	setChar_417f50(base.x,base.y,0x88);
	setChar_417f50(base.x,base.y + h - 1,0x87);
	for (int i = 1; i < w - 1; i++)
	{
		setChar_417f50(base.x + i,base.y,0x81);
		setChar_417f50(base.x + i,base.y + h - 1,0x81);
	}
	setChar_417f50(base.x + w - 1,base.y,0x89);
	setChar_417f50(base.x + w - 1,base.y + h - 1,0x8a);
	for (int j = 1; j < h - 1; j++)
	{
		setChar_417f50(base.x,base.y + j,0x80);
		setChar_417f50(base.x + w - 1,base.y + j,0x80);
	}
	Pos titlePos = source->title->getPos();
	titlePos += base;
	for (int k = 0; k < source->title->getWidth(); k++)
		setChar_417f50(titlePos.x + k,titlePos.y,source->title->getChar(k,0));
	for (int m = 0; m < w; m++)
	{
		unknown48c460(opU5s4_anim_cef8bc,Pos(base.x + m,base.y));
		unknown48c460(opU5s4_anim_cef8bc,Pos(base.x + m,base.y + h - 1));
	}
	for (int n = 1; n < h - 1; n++)
	{
		unknown48c460(opU5s4_anim_cef8bc,Pos(base.x,base.y + n));
		unknown48c460(opU5s4_anim_cef8bc,Pos(base.x + w - 1,base.y + n));
	}
}
