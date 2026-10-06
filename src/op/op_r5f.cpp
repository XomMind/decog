// op_r5f: consoles CType/CNotification/CParse/CTrailer/CRexpaint/CDifficulty/CTitle/CIntro/CMapAnim/CEffect in 0x954180-0x965c10, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos();
	Pos(int x_, int y_);	// 0x46ca20
	Pos(int v);	// 0x409990
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos &operator=(const Pos &pos);
	Pos operator+(const Pos &pos) const;	// 0x409b60
};

struct Point
{
	int x;
	int y;

	Point &operator=(const Point &p);	// 0x46ca50
	Point(const Point &p);	// 0x46ca50
	Point(int v);	// 0x409990
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(unsigned char value);
	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();
	Rect(int x_, int y_, int width_, int height_);
	Rect(const Rect &rect);
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(const XEvent &event);	// 0x944370
	XEvent(int type_);	// 0x415c60

	int type;
	Point pos;
};

class ConsoleTitle;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(XEvent *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();

	bool isHidden();
	Rect getRect();
	Point getPos();
	void setPos(const Point &pos);
	int getWidth();	// 0x44b0d0
	int getHeight();
	void print(int x, int y, const string &text);
	void printAligned(int x, int y, int align, const string &text);
	void setCharRow(int x, int y, int width, int ch);
	string getFirstLine();
	void clear(int x, int y, int width, int height);
	void clearInterior();
	void setFore(XColor color);
	void setBack(XColor color);
	void setHidden(bool hidden_);
	void setPassThrough_418480(bool passThrough_);	// NOTE: placeholder name
	int printWrapped_418260(int x, int y, int width, int height, const string &text);	// NOTE: placeholder name
	void deleteSubconsoles();
	void clear();
	void putChar_418150(int x, int y, int ch, XColor fore, XColor back, bool flag);	// NOTE: placeholder name
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	void setScaleX_417b60(float value);	// NOTE: placeholder name
	void setScaleY_417b80(float value);	// NOTE: placeholder name
	float getScaleX();
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBack_417fc0(int x, int y, XColor color, int mode);	// NOTE: placeholder name
	void setUnknown_451400(int value);	// NOTE: placeholder name (folded setter)
	void unknown429ea0();	// NOTE: placeholder name
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)
	void removeSubconsole(XConsole *console);
	XConsole *getParent4();	// NOTE: placeholder name (folded +4 getter)
	void setPos(int x, int y);
	void setBackAll_418410(XColor color);	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class OpQ4d_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpQ4d_Engine	// NOTE: placeholder name
{
public:
	OpQ4d_EngineItem *unknown50fb50(OpQ4d_Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	void killGroup(string group);
	void update();	// NOTE: placeholder name (0x50fff0)
	void render();	// NOTE: placeholder name (0x5100b0)
	void stopAll();	// NOTE: placeholder name
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
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
	void unknown48c460(int anim, const Pos &pos);	// NOTE: placeholder name

	int unknown60;
	OpQ4d_Engine *engine;
	void *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);

	char pad6c[0x8c - 0x6c];
};

class HItem
{
public:
	int ID;
	HItem();
	bool isValid() const;
};

class Entity
{
public:
	int getAiType();	// NOTE: placeholder name (0x45a2a0)
	int getFaction();	// NOTE: placeholder name (0x45a2c0)
	Pos &getPosition();	// NOTE: placeholder name
	int getSize();	// NOTE: placeholder name
};

class HEntity : public HItem	// NOTE: placeholder layout
{
public:
	HEntity();
	Entity *operator->() const throw();	// 0x9b6570
};

extern string opr5f_factionNames[];	// NOTE: placeholder name (0xd2f798)
string OpR5f_toUpper_4083a0(const string &text);	// NOTE: placeholder name

int opr5f_maxInt(int a, int b) throw();	// NOTE: placeholder name (0x9cdb60)
void opr5f_unknown953d90(HEntity entity, vector<int> *hacks);	// NOTE: placeholder name
extern int opr5f_hackCosts[];	// NOTE: placeholder name (0xb97d38)
extern int opr5f_tileWidth;	// NOTE: placeholder name (0xcaf128)
extern int opr5f_tileHeight;	// NOTE: placeholder name (0xcaf12c)
extern int opr5f_cf27ec;	// NOTE: placeholder name
extern int opr5f_cf27f0;	// NOTE: placeholder name
extern int opr5f_cf27f4;	// NOTE: placeholder name
extern int opr5f_cf27f8;	// NOTE: placeholder name

class OpR5f_Map	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	Pos &unknown458ef0();	// NOTE: placeholder name (folded getter)
};
extern OpR5f_Map *opr5f_cec054;	// NOTE: placeholder name
extern XConsole *opr5f_cec034;	// NOTE: placeholder name

class CRobot : public Console	// 0xcec108
{
public:
	CRobot(XConsole *parent, const Pos &pos, HEntity entity, vector<int> hacks);	// 0x9450f0

	char pad6c[0xc4 - 0x6c];
};

string opr5f_unknown954490(HEntity entity)
{
	string text = OpR5f_toUpper_4083a0(entity->getAiType() != 1 ? string("EXTERNAL") : opr5f_factionNames[entity->getFaction()]);
	for (int i = text.size() - 1; i > 0; i--)
		text.insert(text.begin() + i,' ');
	return text;
}

//==================================================================
// shared declarations (op_r5f)
//==================================================================

class OpR5f_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void unknown416640();	// NOTE: placeholder name
	void unknown416340(bool value);	// NOTE: placeholder name
	void unknown416570();	// NOTE: placeholder name
	void unknown4162e0(int command, bool value);	// NOTE: placeholder name
};
extern OpR5f_KeyMap *opr5f_keyMap;	// NOTE: placeholder name

extern bool opr5f_inputBlocked;	// NOTE: placeholder name (0xcefa5f)
void opr5f_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)

class OpR5f_Sound	// NOTE: placeholder name (0xcefa90)
{
public:
	void haltAll();	// NOTE: placeholder name (0x419c50)
};
extern OpR5f_Sound *opr5f_sound;	// NOTE: placeholder name

class OpR5f_Unk9c05e0	// NOTE: placeholder name (0xcefaa8)
{
public:
	void unknown9c05e0();	// NOTE: placeholder name (empty function)
};
extern OpR5f_Unk9c05e0 *opr5f_cefaa8;	// NOTE: placeholder name

class OpR5f_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	XConsole *getConsole_4ab670();	// NOTE: placeholder name (folded getter)
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
};
extern OpR5f_Rex opr5f_rex;	// NOTE: placeholder name

class OpR5f_Delay	// NOTE: placeholder name (0xcec03c)
{
public:
	void delay();	// NOTE: placeholder name
};
extern OpR5f_Delay *opr5f_cec03c;	// NOTE: placeholder name

class OpR5f_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	void unknown464710(int value);	// NOTE: placeholder name
};
extern OpR5f_World *opr5f_world;	// NOTE: placeholder name

void opr5f_unknown954640(bool flag);	// NOTE: placeholder name

class CTextInput : public Console
{
public:
	string &getText_458ef0();	// NOTE: placeholder name (folded getter, +0x6c)

	char pad6c[0xe4 - 0x6c];
};

//==================================================================
// CType
//==================================================================

class CType : public Console
{
public:
	virtual bool input(XEvent *event);
	virtual void close();

	char pad6c[0x74 - 0x6c];
	void (*callback)(const string &text);	// NOTE: placeholder name
	bool unknown78;	// NOTE: placeholder name
	char pad79[0x7c - 0x79];
	CTextInput *textInput;	// NOTE: placeholder name
};
extern CType *opr5f_cec10c;	// NOTE: placeholder name

void opr5f_unknown954640(bool flag)
{
	string text = flag ? string() : opr5f_cec10c->textInput->getText_458ef0();
	opr5f_cec10c->callback(text);
}

void CType::close()
{
	opr5f_playSound(0x28,0,0);
	opr5f_keyMap->unknown416640();
	getParent4()->removeSubconsole(this);
}

bool CType::input(XEvent *event)
{
	if (isHidden() || opr5f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0x100:
		{
			if (unknown78)
				return false;
		}
		case 0x101:
		{
			opr5f_unknown954640(true);
			return true;
		}
	}
	return false;
}

//==================================================================
// CNotification
//==================================================================

class CNotification : public Console
{
public:
	virtual ~CNotification();
	virtual bool input(XEvent *event);
	virtual void close();
};

void CNotification::close()
{
	opr5f_cec03c->delay();
	opr5f_keyMap->unknown416640();
	getParent4()->removeSubconsole(this);
}

bool CNotification::input(XEvent *event)
{
	if (isHidden() || opr5f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0x100:
		case 0x101:
		{
			close();
			return true;
		}
	}
	return false;
}

//==================================================================
// CParse
//==================================================================

class CParse : public Console
{
public:
	virtual bool input(XEvent *event);

	void unknown95a590();	// NOTE: placeholder name
};

void CParse::unknown95a590()
{
	opr5f_keyMap->unknown416640();
	getParent4()->removeSubconsole(this);
	opr5f_world->unknown464710(2);
}

bool CParse::input(XEvent *event)
{
	if (isHidden() || opr5f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0x100:
		case 0x101:
		{
			unknown95a590();
			return true;
		}
	}
	return false;
}

//==================================================================
// CRobot window
//==================================================================

void opr5f_unknown954180(HEntity entity)
{
	vector<int> hackList;
	opr5f_unknown953d90(entity,&hackList);

	int sections = 0;
	for (unsigned int i = 0; i < hackList.size(); i++)
	{
		if (opr5f_hackCosts[hackList[i]] == -1)
		{
			sections++;
			break;
		}
	}
	for (unsigned int j = 0; j < hackList.size(); j++)
	{
		if (opr5f_hackCosts[hackList[j]] == 0)
		{
			sections++;
			break;
		}
	}
	for (unsigned int k = 0; k < hackList.size(); k++)
	{
		if (opr5f_hackCosts[hackList[k]] > 0)
		{
			sections++;
			break;
		}
	}

	Pos windowPos;
	int windowWidth = opr5f_maxInt(0x28,opr5f_unknown954490(entity).size() * 2 + 6);
	int windowHeight = hackList.size() + sections * 2 + 3;
	Pos mapPos = entity->getPosition() + opr5f_cec054->unknown458ef0();
	mapPos.x *= opr5f_tileWidth;
	mapPos.x += 1;
	mapPos.x += entity->getSize() * opr5f_tileWidth;
	mapPos.x += opr5f_cf27ec;
	mapPos.y *= opr5f_tileHeight;
	mapPos.y += opr5f_cf27f0;
	if (mapPos.x + windowWidth >= opr5f_cf27f4 * opr5f_tileWidth + opr5f_cf27ec)
		mapPos.x = (entity->getPosition().x + opr5f_cec054->unknown458ef0().x) * opr5f_tileWidth - windowWidth;
	if (mapPos.y + windowHeight >= opr5f_cf27f8 * opr5f_tileHeight + opr5f_cf27f0)
		mapPos.y -= mapPos.y + windowHeight - (opr5f_cf27f8 * opr5f_tileHeight + opr5f_cf27f0);
	windowPos.x = mapPos.x;
	windowPos.y = mapPos.y;
	new CRobot(opr5f_cec034,windowPos,entity,hackList);
}

//==================================================================
// CParseLine
//==================================================================

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	string text;
};

class CParseLine : public Console
{
public:
	CParseLine(XConsole *parent, int width, int y, const string &left, const string &right);	// 0x9548e0
};

CParseLine::CParseLine(XConsole *parent, int width, int y, const string &left, const string &right)
	: Console(parent,width,1,2,y,0,false,-1)
{
	CText *leftText = new CText(this,Pos(0,0),left,0,0,-1);
	leftText->animate(right.size() ? "A_CParseLine_Entry" : "A_CParseLine_EntryLone");
	if (!right.empty())
	{
		CText *rightText = new CText(this,Pos(left.size(),0),right,0,0,-1);
		rightText->animate("A_CParseLine_Data");
		Console *cellOverlay = new Console(this,right.size(),1,left.size(),0,0,false,-1);
		cellOverlay->animate(right.size() > 1 ? "A_CParseLine_Overlay" : "CParseLine_OverlayCell");
	}
}

//==================================================================
// CTrailer
//==================================================================

class CTrailer : public Console
{
public:
	CTrailer();	// 0x95a6c0
	virtual ~CTrailer();	// defined in cc_r2_21
	virtual bool input(XEvent *event);

	void stop();	// NOTE: placeholder name (0x95aed0)
	void toggle();	// NOTE: placeholder name (0x95af10)

	int unknown6c;	// NOTE: placeholder name
	bool playing;	// NOTE: placeholder name
};

CTrailer::CTrailer()
	: Console(opr5f_rex.getConsole_4ab670(),opr5f_rex.unknown418980(),opr5f_rex.unknown4189a0(),0,0,0,true,-1)
{
	unknown6c = 0;
	playing = true;
}

void CTrailer::stop()
{
	unknown60 = 4;
	deleteSubconsoles();
	engine->stopAll();
	opr5f_sound->haltAll();
}

void CTrailer::toggle()
{
	if (playing)
	{
		stop();
		clear();
	}
	else
		open();
	playing = !playing;
}

bool CTrailer::input(XEvent *event)
{
	if (isHidden() || opr5f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0x186:
		{
			if (!playing && unknown6c < 13)
				unknown6c++;
			toggle();
			return true;
		}
		case 0x189:
		{
			opr5f_cefaa8->unknown9c05e0();
		}
		case 0x188:
		{
			toggle();
			return true;
		}
	}
	return false;
}

//==================================================================
// CRexpaint
//==================================================================

class ConsoleArt : public Console
{
public:
	void drawArt(int layer);

	char pad6c[0x84 - 0x6c];
};

class CArtAnimated : public ConsoleArt
{
public:
	CArtAnimated(XConsole *parent, const string &file, int x, int y, bool hidden, int unknown84_, int layer, int frame, const Pos &offset_, int width, int height);
	void unknown4b29b0();	// NOTE: placeholder name (0x4b29b0)

	int unknown84;
};

int opr5f_centerOffset(int inner, int outer) throw();	// NOTE: placeholder name (0x437190)
bool opr5f_findAnimation_9d45a0(const string &name, int *index);	// NOTE: placeholder name
extern OpR5f_KeyMap *opr5f_keyMap;

class CRexpaint : public Console
{
public:
	CRexpaint();	// 0x95b020
	virtual ~CRexpaint();	// defined in cc_r2_21
	virtual void open();	// 0x95b090
	virtual bool input(XEvent *event);
	virtual void trigger(const string &command, int value);

	void stop();	// NOTE: placeholder name (0x95b510)

	CArtAnimated *unknown6c;	// NOTE: placeholder name
	CArtAnimated *unknown70;	// NOTE: placeholder name
	CArtAnimated *unknown74;	// NOTE: placeholder name
};

CRexpaint::CRexpaint()
	: Console(opr5f_rex.getConsole_4ab670(),opr5f_rex.unknown418980() / 2,opr5f_rex.unknown4189a0(),0,0,4,true,-1)
{
	unknown6c = NULL;
	unknown70 = NULL;
	unknown74 = NULL;
}

void CRexpaint::stop()
{
	deleteSubconsoles();
	engine->stopAll();
	opr5f_sound->haltAll();
	clear();
	open();
}

void CRexpaint::trigger(const string &command, int value)
{
	if (command == "stop_spread")
		unknown6c->engine->killGroup("expand");
}

bool CRexpaint::input(XEvent *event)
{
	if (isHidden() || opr5f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0x186:
		{
			stop();
			return true;
		}
		case 0x189:
		{
			opr5f_cefaa8->unknown9c05e0();
		}
		case 0x188:
		{
			stop();
			return true;
		}
	}
	return false;
}

void CRexpaint::open()
{
	unknown60 = 3;
	setHidden(false);
	opr5f_keyMap->unknown416340(true);
	opr5f_keyMap->unknown4162e0(0x1f,true);
	setBackAll_418410(XColor(50));
	int frames;
	opr5f_findAnimation_9d45a0("A_CRexpaint",&frames);
	unknown6c = new CArtAnimated(this,string("data/art/rexpaint"),opr5f_centerOffset(0x4b,getWidth()),opr5f_centerOffset(0xc,getHeight()),false,frames,-1,-1,Pos(-1),0,0);
	unknown6c->drawArt(0);
	unknown70 = new CArtAnimated(this,string("data/art/rexpaint"),opr5f_centerOffset(0x4b,getWidth()),opr5f_centerOffset(0xc,getHeight()),false,frames,-1,-1,Pos(-1),0,0);
	unknown70->drawArt(1);
	unknown70->resetBack_418450();
	unknown70->unknown4b29b0();
	unknown74 = new CArtAnimated(this,string("data/art/rexpaint"),opr5f_centerOffset(0x4b,getWidth()),opr5f_centerOffset(0xc,getHeight()),false,frames,-1,-1,Pos(-1),0,0);
	unknown74->resetBack_418450();
	unknown74->drawArt(2);
}

//==================================================================
// CDifficultyWindow
//==================================================================

class CDifficultyButton : public Console
{
public:
	CDifficultyButton(XConsole *parent, int x, int y, const string &text);	// 0x4b26f0
};

class CText;
class CDifficulty;

extern int opr5f_difficultyHeights[];	// NOTE: placeholder name (0xbcdb6c)
extern int opr5f_difficultyNumbers[];	// NOTE: placeholder name (0xbcdb60)
extern string opr5f_difficultyNames[];	// NOTE: placeholder name (0xd1de98)
extern string opr5f_difficultyShort[];	// NOTE: placeholder name (0xd318c0)
extern string opr5f_difficultyTails[];	// NOTE: placeholder name (0xd20880)
extern string opr5f_confirmText;	// NOTE: placeholder name (0xd384d4)
extern string opr5f_infoText;	// NOTE: placeholder name (0xd39e74)
extern XColor *opr5f_COLOR_BLACK;	// NOTE: placeholder name (0xcfe674)
extern int opr5f_difficulty;	// NOTE: placeholder name (0xd28d0c)
string intToString(int value);	// 0x4051f0

class OpR5f_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool getField_41a6e0();	// NOTE: placeholder name
};
extern OpR5f_Mouse *opr5f_mouse;	// NOTE: placeholder name

class CDifficultyWindow : public Console
{
public:
	CDifficultyWindow(int type_, int y);	// 0x95b630
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(XEvent *event);

	bool hasConfirm();	// NOTE: placeholder name (0x4b27f0, folded getter)
	void undoConfirm();	// NOTE: placeholder name (0x95bec0)

	int type;	// NOTE: placeholder name
	CDifficultyButton *description;	// NOTE: placeholder name
	CDifficultyButton *tail;	// NOTE: placeholder name
	CDifficultyButton *confirm;	// NOTE: placeholder name
};

class OpR5f_Difficulty : public Console	// NOTE: placeholder name (CDifficulty at 0xcec028)
{
public:
	virtual void close();
	vector<CDifficultyWindow*> *getWindows();	// NOTE: placeholder name (0x458ef0, folded getter)
};
extern OpR5f_Difficulty *opr5f_cec028;	// NOTE: placeholder name

CDifficultyWindow::CDifficultyWindow(int type_, int y)
	: Console(opr5f_cec028,0x86,opr5f_difficultyHeights[type_],0,y,0,false,-1)
{
	type = type_;
	confirm = NULL;
	drawFrame(NULL,*opr5f_COLOR_BLACK,true,false);

	CDifficultyButton *button = new CDifficultyButton(this,0x1a - opr5f_difficultyNames[type].size() - 4,0," " + intToString(opr5f_difficultyNumbers[type]) + " -");
	button->animate("A_CDiff_Text_FadeIn_Number");
	button->setPassThrough_418480(true);
	button = new CDifficultyButton(this,0x1a - opr5f_difficultyNames[type].size(),0,opr5f_difficultyNames[type]);
	button->animate("A_CDiff_Name");
	button->setPassThrough_418480(true);
	button = new CDifficultyButton(this,0x1a,0,opr5f_difficultyShort[type]);
	button->animate("A_CDiff_Text_FlashIn_Desc_Short");
	button->setPassThrough_418480(true);
	description = new CDifficultyButton(this,0x1b,2,intToString(type));
	description->animate("A_CDiff_Desc_Long");
	description->setPassThrough_418480(true);
	tail = new CDifficultyButton(this,0x1a,getHeight() - 1,opr5f_difficultyTails[type]);
	tail->animate("A_CDiff_Text_FadeIn_Tail");
	tail->setPassThrough_418480(true);
}

bool CDifficultyWindow::mouseEnter()
{
	if (opr5f_mouse->getField_41a6e0())
		return false;
	animate("A_CDiff_Border_Color");
	return true;
}

void CDifficultyWindow::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_CDiff_Border_Black");
}

void CDifficultyWindow::undoConfirm()
{
	if (confirm)
	{
		if (confirm)
		{
			removeSubconsole(confirm);
			confirm = NULL;
		}
		description->animate("A_CDiff_Confirm_Desc_Long_Undo");
		tail->animate("A_CDiff_Confirm_Desc_Tail_Undo");
	}
}

bool CDifficultyWindow::input(XEvent *event)
{
	if (isHidden() || opr5f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0x187:
		{
			if (confirm)
			{
				opr5f_difficulty = type;
				opr5f_cec028->close();
			}
			else
			{
				vector<CDifficultyWindow*> *windows = opr5f_cec028->getWindows();
				for (unsigned int i = 0; i < windows->size(); i++)
				{
					if ((*windows)[i]->confirm)
					{
						(*windows)[i]->undoConfirm();
						break;
					}
				}
				confirm = new CDifficultyButton(this,0x1a - opr5f_confirmText.size(),2,opr5f_confirmText);
				confirm->animate("A_CDiff_Confirm");
				confirm->setPassThrough_418480(true);
				opr5f_playSound(0x33,0,0);
				description->animate("A_CDiff_Confirm_Desc_Long");
				tail->animate("A_CDiff_Confirm_Desc_Tail");
			}
			return true;
		}
	}
	return false;
}

//==================================================================
// CDifficulty
//==================================================================

class GM	// NOTE: placeholder layout (object at 0xcefaa8)
{
public:
	bool readyGame(bool a, bool b, bool c);	// 0x78b8a0
};
extern GM *opr5f_gm;	// NOTE: placeholder name

class OpR5f_Clock	// NOTE: placeholder name (0xcefa9c)
{
public:
	void start_416920();	// NOTE: placeholder name
};
extern OpR5f_Clock *opr5f_clock;	// NOTE: placeholder name

class AsciiImage
{
public:
	AsciiImage();
	~AsciiImage();
	bool load(const string &file, int font, Pos *offset, int width, int height);

	char pad00[0x10];
};

class CTitleAnimated : public ConsoleArt
{
public:
	CTitleAnimated(XConsole *parent, AsciiImage *art, int unknown84_, int frame);	// 0x4b28f0
	void unknown4b29b0();	// NOTE: placeholder name

	int unknown84;	// NOTE: placeholder name
};

class OpR5f_Mouse2	// NOTE: placeholder name (0xcefa94)
{
public:
	bool getField_41a6e0();	// NOTE: placeholder name
	void setCursorHidden(bool hidden);	// 0x432170, NOTE: placeholder name
};
extern OpR5f_Mouse2 *opr5f_mouse2;	// NOTE: placeholder name

class OpR5f_GM2	// NOTE: placeholder name (0xcefaa8)
{
public:
	void unknown78c050();	// NOTE: placeholder name
};
extern OpR5f_GM2 *opr5f_gm2;	// NOTE: placeholder name
extern Console *opr5f_cec030;	// NOTE: placeholder name

class CTitle : public Console
{
public:
	CTitle();	// 0x95c5d0
	virtual ~CTitle();	// 0x4b28a0
	virtual bool input(XEvent *event);
	virtual void update();
	virtual void close();
	virtual void trigger(const string &command, int value);	// 0x95ccc0

	void show(bool flag);	// NOTE: placeholder name (0x95c640)

	Console *ascii;	// NOTE: placeholder name
	bool finished;	// NOTE: placeholder name
	bool cursorHidden;	// NOTE: placeholder name
};
extern CTitle *opr5f_cec02c;	// NOTE: placeholder name
extern bool opr5f_cefacd;	// NOTE: placeholder name
extern bool opr5f_cefb2d;	// NOTE: placeholder name

string opr1c_getSaveName_432af0(int version, bool error);	// 0x432af0, NOTE: placeholder name

class CDifficulty : public Console
{
public:
	CDifficulty();	// 0x95bf40
	virtual ~CDifficulty();	// defined in cc_r2_21
	virtual bool input(XEvent *event);
	virtual void update();
	virtual void open();
	virtual void close();

	vector<CDifficultyWindow*> windows;	// NOTE: placeholder name
};

CDifficulty::CDifficulty()
	: Console(opr5f_rex.getConsole_4ab670(),0x86,0x1f,opr5f_centerOffset(0x86,opr5f_rex.unknown418980()),opr5f_centerOffset(0x1f,opr5f_rex.unknown4189a0()),0,true,-1)
{
}

void CDifficulty::close()
{
	unknown60 = 4;
	deleteSubconsoles();
	engine->stopAll();
	opr5f_sound->haltAll();
}

void CDifficulty::open()
{
	unknown60 = 3;
	setHidden(false);
	opr5f_keyMap->unknown416570();
	opr5f_keyMap->unknown416340(true);
	opr5f_keyMap->unknown4162e0(0x1f,true);
	if (opr5f_difficulty != 3)
	{
		close();
	}
	else
	{
		CText *header = new CText(this,Pos(0x1b,0),"SELECT YOUR DIFFICULTY",0,0,-1);
		header->animate("A_CDifficulty_Instruct");
		int top = 3;
		for (int diff = 2; diff >= 0; diff--)
		{
			windows.push_back(new CDifficultyWindow(diff,top));
			top += opr5f_difficultyHeights[diff] + 2;
		}
		Console *divider = new Console(this,0x3b,6,0x1b,top,0,false,-1);
		divider->printWrapped_418260(0,1,divider->getWidth(),divider->getHeight() - 1,opr5f_infoText);
		divider->animate("A_CDifficulty_Divider");
		divider->animate("A_CDifficulty_Info");
	}
}

void CDifficulty::update()
{
	if (isHidden())
		return;

	switch (unknown60)
	{
		case 0:
		{
			break;
		}
		case 1:
		{
			unknown60 = 3;
			break;
		}
		case 3:
		{
			engine->update();
			break;
		}
		case 4:
		{
			unknown60 = 0;
			opr5f_keyMap->unknown416640();
			FILE *file = fopen(opr1c_getSaveName_432af0(0x5e,false).c_str(),"r");
			bool newGame = file == NULL;
			if (file)
				fclose(file);
			if (!opr5f_gm->readyGame(newGame,false,false))
				exit(1);
			opr5f_clock->start_416920();
			opr5f_cec02c->show(newGame);
			opr5f_cec028 = NULL;
			opr5f_rex.getConsole_4ab670()->removeSubconsole(this);
			return;
		}
	}
	updateBase429e30();
}

bool CDifficulty::input(XEvent *event)
{
	if (isHidden() || opr5f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	unsigned int i;
	unsigned int j;
	switch (event->type)
	{
		case 0x188:
		{
			if (opr5f_cefacd)
			{
				close();
				windows.clear();
				opr5f_cefaa8->unknown9c05e0();
				opr5f_clock->start_416920();
				open();
			}
			return true;
		}
		case 0x186:
		{
			for (i = 0; i < windows.size(); i++)
			{
				if (windows[i]->hasConfirm())
				{
					windows[i]->undoConfirm();
					break;
				}
			}
			return true;
		}
		case 0x18a:
		case 0x18b:
		case 0x18c:
		{
			if (!windows.empty())
			{
				windows[event->type - 0x18a]->input(&XEvent(0x187));
			}
			return true;
		}
		case 0x18d:
		{
			for (j = 0; j < windows.size(); j++)
			{
				if (windows[j]->hasConfirm())
				{
					windows[j]->input(&XEvent(0x187));
					break;
				}
			}
			return true;
		}
	}
	return false;
}

//==================================================================
// CTitle
//==================================================================

bool opr5f_findAnimation_9d45a0(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)

CTitle::CTitle()
	: Console(opr5f_rex.getConsole_4ab670(),opr5f_rex.unknown418980() / 2,opr5f_rex.unknown4189a0(),0,0,4,true,-1)
{
	ascii = NULL;
	finished = false;
	cursorHidden = false;
}

void CTitle::show(bool flag)
{
	if (!flag || opr5f_cefb2d)
	{
		if (opr5f_cec030)
		{
			opr5f_rex.getConsole_4ab670()->removeSubconsole(opr5f_cec030);
			opr5f_cec030 = NULL;
		}
		opr5f_cec034->setHidden(false);
		opr5f_gm2->unknown78c050();
		opr5f_cec02c = NULL;
		opr5f_rex.getConsole_4ab670()->removeSubconsole(this);
		return;
	}
	int animation;
	CTitleAnimated *console;
	unknown60 = 3;
	setHidden(false);
	opr5f_keyMap->unknown416570();
	opr5f_keyMap->unknown416340(true);
	opr5f_keyMap->unknown4162e0(0x1f,true);
	animate("A_CTitle_Timer");

	AsciiImage titleArt;
	titleArt.load(string() + "data/art/" + "title",4,&Pos(-1),0,0);
	for (int i = 0; i < 3; i++)
	{
		opr5f_findAnimation_9d45a0("A_CTitle_Layer" + intToString(i),&animation);
		console = new CTitleAnimated(this,&titleArt,animation,i);
		console->unknown4b29b0();
	}

	string line = "Grid Sage Games presents";
	ascii = new Console(this,getWidth(),getHeight(),0,0,4,false,-1);
	ascii->animate("A_CTitle_Ascii");
	CText *sage = new CText(this,Pos(opr5f_centerOffset(line.size(),getWidth()),opr5f_centerOffset(1,getHeight())),line,4,0,-1);
	sage->resetBack_418450();
	sage->animate("A_CTitle_Sage");
	if (!opr5f_mouse2->getField_41a6e0())
	{
		opr5f_mouse2->setCursorHidden(true);
		cursorHidden = true;
	}
}
