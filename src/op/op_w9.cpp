// op_w9: generic UI consoles in 0x7b0000-0x7c0000 (CTextInput, CList, CLog, CAllies, CIntel, ...), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos();	// 0x453b40
	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();
	Pos(const Pos &pos, int dx, int dy);	// NOTE: placeholder name
	explicit Pos(int value);	// NOTE: placeholder name (0x409990)
	Pos operator+(const Pos &pos) const;	// 0x409b60
	Pos &operator=(const Pos &pos);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	static XColor addAlpha(XColor a, XColor b, float alpha);	// 0x4137b0
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect() throw();	// NOTE: folded default ctor
	Rect(int x_, int y_, int width_, int height_) throw();	// 0x456940
	Rect(const Rect &rect);
	Rect &operator=(const Rect &rect);	// NOTE: folded with the copy ctor (0x40a720)
	void set(int x_, int y_, int width_, int height_);	// NOTE: placeholder name (0x40a840)
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
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	bool isHidden();
	int getWidth();
	int getHeight();
	Pos getPos();
	bool contains(const Pos &p);
	bool inBounds(const Pos &p);
	float getScaleX();
	void setHidden(bool hidden_) throw();
	XConsole *getParent();
	void removeSubconsole(XConsole *console);
	void deleteSubconsoles();
	void setScaleX(float value);	// NOTE: placeholder name (0x417b60)
	void setScaleY(float value);
	void setPos(const Pos &pos);	// NOTE: placeholder name (0x417b80)
	void unknown429f10(int a, int b);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Pos &pos, int value);	// NOTE: placeholder name
	void clear(XConsole *console);
	void setPos(int x, int y);
	void setFore(XColor color);
	void setFore_417f80(int x, int y, XColor color);
	int getChar(int x, int y);
	bool isWide();
	void setCharRow(int x, int y, int length, int ch, XColor color);
	void setCharColumn(int x, int y, int length, int ch, XColor color);
	void setForeFrame(int x, int y, int width, int height, XColor color);
	struct OpW9_Cell *getCell_4176e0(int x, int y, int layer);	// NOTE: placeholder name
	void setChar_417f50(int x, int y, int ch);
	void setBackAll_418410(XColor color);
	void clearBack();
	void putChar_418110(int x, int y, int ch, XColor fore);
	void clear();
	void clearInterior();
	void move(int dx, int dy);
	void print(int x, int y, const string &text);

	char pad04[0x60 - 0x04];
};

class OpW9_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class Engine
{
public:
	OpW9_EngineItem *unknown50fb50(Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	bool isRunning();	// NOTE: placeholder name (0x50fff0)
	bool unknown454d30();	// NOTE: placeholder name
	void killGroup(string group);
	void stopAll();	// NOTE: placeholder name (0x50ff30)
	void render();	// NOTE: placeholder name (0x5100b0)
};

struct OpW9_Cell	// NOTE: placeholder name
{
	void unknown4280e0();	// NOTE: placeholder name
};

class RNG
{
public:
	int rangeInt(float min, float max);
};
extern RNG rng;

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

	bool isActive_7ad420();	// NOTE: placeholder name
	void unknown48e8b0();	// NOTE: placeholder name
	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void animate(string name);	// NOTE: placeholder name
	void animate(string name, int unknown1, int unknown2);	// NOTE: placeholder name
	void unknown7ad6a0(int index, int unknown1, int unknown2, int a, int b);	// NOTE: placeholder name
	Pos getAnchor(int anchor);	// NOTE: placeholder name
	void drawFrame(Rect *area, XColor color, bool thin, bool lines);	// NOTE: placeholder name
	void setFrameFore(XColor color);	// NOTE: placeholder name
	void replaceSpecialChars(int ch);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	XConsole *title;
};

class Console;
class OpW9_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void registerConsole(int command, Console *console, int unknown1, int unknown2);	// NOTE: placeholder name (0x416790)
	void unknown416640();	// NOTE: placeholder name
	void unknown4162e0(int command, int value);	// NOTE: placeholder name
};
extern OpW9_KeyMap *opW9_keyMap;	// NOTE: placeholder name

class OpW9_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	Pos getPos();	// NOTE: placeholder name (0x41a700)
	void unknown41a8b0();	// NOTE: placeholder name
	bool unknown41a6e0();	// NOTE: placeholder name (folded getter)
};
extern OpW9_Mouse *opW9_mouse;	// NOTE: placeholder name

class OpW9_SidePanel : public XConsole	// NOTE: placeholder name (0xcec11c)
{
public:
	void unknown8b5080();	// NOTE: placeholder name
};
extern OpW9_SidePanel *opW9_cec11c;	// NOTE: placeholder name

struct OpW9_Options	// NOTE: placeholder name (0xcec130)
{
	char pad00[0x9d];
	bool unknown9d;	// NOTE: placeholder name
	char pad9e[0xc8 - 0x9e];
	void (*renderHook)(XConsole *console);	// NOTE: placeholder name

	int getUnknown58();	// NOTE: placeholder name (folded getter 0x44a7d0)
};
extern OpW9_Options *opW9_options;	// NOTE: placeholder name

extern bool opW9_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern unsigned int opW9_tickCount;	// NOTE: placeholder name (0xcaed20)
extern void *opW9_help;	// NOTE: placeholder name (0xcec038)
extern const char opW9_listHotkeys[];	// NOTE: placeholder name (0xb965f4)

string intToString(int value);
bool opW9_findAnimation(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)
extern string opW9_listDifferentNames[];	// NOTE: placeholder name (0xcfac48)
extern string opW9_listOptionNames[];	// NOTE: placeholder name (0xcf35c0)
extern Pos opW9_cfbec0;	// NOTE: placeholder name
extern XColor *opW9_cfc180;	// NOTE: placeholder name
extern XColor *opW9_cfd448;	// NOTE: placeholder name
extern XColor *opW9_d2d29c;	// NOTE: placeholder name
extern XColor *opW9_cf44c0;	// NOTE: placeholder name
extern XColor *opW9_d1d46c;	// NOTE: placeholder name
extern XColor *opW9_d323c4;	// NOTE: placeholder name
extern XColor *opW9_d30424;	// NOTE: placeholder name
extern XColor *opW9_d22fcc;	// NOTE: placeholder name
void opW9_clamp(int low, int &value, int high);	// NOTE: placeholder name (0x9cdc50)
template <class T> void removeVectorElement(vector<T> &v, int index);
template <class T> void OpW9_insertAt(vector<T> &v, int i, T e);	// NOTE: placeholder name (0x9dbdc0)

//==================================================================
// CListOption / CList
//==================================================================

class CListOption : public Console
{
public:
	CListOption(XConsole *parent, int x, int y, int width, const string &text, int font, bool hidden, int unknown6c_, int unknown70_, bool selectable_, int unknown78_, int unknown7c_);

	void draw();	// NOTE: placeholder name
	virtual bool input(XEvent *event);
	virtual void render();

	int unknown6c;
	int unknown70;
	bool selectable;
	int unknown78;
	int unknown7c;
};

class CList : public Console
{
public:
	CList(XConsole *parent, const Pos &pos, string title, int unknown74_, const vector<string> &options_, int maxVisible, int font, void (*callback_)(int,const string&), int unknownC4_, int layer, bool unknown9c_, bool unknown9d_, vector<bool> *enabled_, vector<int> *unknownA4_, vector<int> *unknownA8_, bool noClose_);	// 0x48d9a0

	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);
	virtual void update();
	virtual void close();

	void cancel();	// NOTE: placeholder name
	void unknown7b2870();	// NOTE: placeholder name
	int getOptionAtMouse();	// NOTE: placeholder name
	void select(int index);	// NOTE: placeholder name
	void highlight(int index);	// NOTE: placeholder name
	void scroll(int amount, int target);	// NOTE: placeholder name
	void updateScroll();	// NOTE: placeholder name

	unsigned int closeTime;	// NOTE: placeholder name
	XConsole *closeButton;
	int unknown74;
	vector<string> options;
	unsigned int maxLength;
	int optionWidth;
	int numVisible;
	int unknown94;
	int unknown98;
	bool unknown9c;
	bool unknown9d;
	bool noClose;
	vector<bool> *enabled;
	vector<int> *unknownA4;
	vector<int> *unknownA8;
	vector<CListOption*> listOptions;
	void (*callback)(int,const string&);
	bool unknownC0;
	void (*highlightCallback)(int,const string&);	// NOTE: placeholder name
	int unknownC8;
	CListOption *moreAbove;	// NOTE: placeholder name
	CListOption *moreBelow;	// NOTE: placeholder name
};

void CListOption::draw()
{
	animate(unknown70 ? string("A_CList_Scroll") : (selectable ? (unknown78 ? "A_CList_Different_" + opW9_listDifferentNames[unknown78] : (unknown7c == -1 ? string("A_CList_Option_Standard") : "A_CList_Option_" + opW9_listOptionNames[unknown7c])) : string("A_CList_NotOption")));

	if (unknown70 == 0 && selectable && unknown78 == 0 && opW9_options->unknown9d)
	{
		const string &optionText = ((CList*)getParent())->options[unknown6c];
		int dot = optionText.find('.');
		if (dot != string::npos && optionText.find("Redist.") == string::npos)
		{
			int start = 0;
			if (optionText.rfind(' ',dot - 1) != string::npos)
				start = optionText.rfind(' ',dot - 1) + 1;
			int animIndex;
			if (opW9_findAnimation(unknown7c == -1 ? string("CList_Op_Standard_Prefix_E") : "CList_Op_" + opW9_listOptionNames[unknown7c] + "_Prefix_E",&animIndex))
			{
				do
				{
					for (int x = Pos(start,0).x; x < Pos(start,0).x + dot - start + 1; x++)
						engine->unknown50fb50(engine,animIndex,&Pos(x,Pos(start,0).y),&opW9_cfbec0,NULL,NULL,9)->unknown50de10();
				} while (false);
			}
		}
	}
}

bool CListOption::input(XEvent *event)
{
	if (isHidden() || opW9_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0x106:
			if (unknown70)
				((CList*)getParent())->scroll(-unknown70,-1);
			else if (selectable)
				((CList*)getParent())->select(unknown6c);
			return true;
		case 0x107:
			if (((CList*)getParent())->highlightCallback == NULL)
				((CList*)getParent())->cancel();
			else if (unknown70 == 0 && selectable)
				((CList*)getParent())->highlight(unknown6c);
			return true;
	}
	return false;
}

void CListOption::render()
{
	if (isHidden())
		return;
	engine->render();
	if (opW9_options->renderHook)
		opW9_options->renderHook(this);
	XConsole::render();
}

void CList::update()
{
	if (isHidden())
		return;

	switch (unknown60)
	{
		case 0:
			break;
		case 1:
			if (!engine->isRunning())
				unknown60 = 3;
			break;
		case 3:
			break;
		case 4:
			engine->isRunning();
			if (getScaleX() != 0)
			{
				if (opW9_tickCount - closeTime >= 500)
				{
					setScaleX(0);
					setScaleY(0);
				}
				else
				{
					setScaleX((float)(1 - (opW9_tickCount - closeTime) / 500.0));
					setScaleY((float)(1 - (opW9_tickCount - closeTime) / 500.0));
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			opW9_keyMap->unknown416640();
			getParent()->removeSubconsole(this);
			break;
	}
	XConsole::update();
}

void CList::close()
{
	if (opW9_help)
		return;
	if (unknown60 == 4)
		return;

	unknown60 = 4;
	unknown429f10(0,0);
	deleteSubconsoles();
	opW9_keyMap->unknown4162e0(0x12,0);
	closeTime = opW9_tickCount;
	animate("A_BlockFadeVis");
	if (!opW9_cec11c->isHidden())
		opW9_cec11c->unknown8b5080();
}

void CList::unknown7b2870()
{
	unknown60 = 0;
	if (!opW9_cec11c->isHidden())
		opW9_cec11c->unknown8b5080();
	opW9_keyMap->unknown416640();
	getParent()->removeSubconsole(this);
}

int CList::getOptionAtMouse()
{
	Pos mousePos = opW9_mouse->getPos();
	if (!contains(mousePos))
		return -1;
	for (unsigned int i = 0; i < listOptions.size(); i++)
	{
		if (listOptions[i]->contains(mousePos))
			return i;
	}
	return -1;
}

bool CList::input(XEvent *event)
{
	if (isHidden() || opW9_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0x108:
			scroll(-unknown94,-1);
			return true;
		case 0x109:
			scroll(unknown94,-1);
			return true;
		case 0x10a:
			if (unknown98 > 0)
				scroll(numVisible,-1);
			return true;
		case 0x10b:
			if (unknown98 + numVisible < options.size())
				scroll(-numVisible,-1);
			return true;
		case 0x10c:
			scroll(99999,-1);
			return true;
		case 0x10d:
			scroll(-99999,-1);
			return true;
		case 0x107:
			if (highlightCallback)
				return false;
		case 0x10e:
			if (noClose)
				return true;
			cancel();
			return true;
		case 0x10f:
			if (unknown74 == 0x12)
			{
				if (noClose)
					return false;
				cancel();
				return true;
			}
			else
				return false;
	}
	return false;
}

void CList::inputAscii(int key, int modifier)
{
	if (!isActive_7ad420())
		return;

	switch (modifier)
	{
		case 0:
		case 1:
			if (modifier == 1)
			{
				if (highlightCallback)
				{
					if (unknown9c)
					{
						for (unsigned int i = unknown98; i < options.size(); i++)
						{
							if (opW9_listHotkeys[i] == key)
							{
								highlight(i);
								break;
							}
						}
					}
					else
						highlight(unknown98 + key - 'A');
					break;
				}
				key += 0x20;
			}

			if (unknown9c)
			{
				for (unsigned int j = unknown98; j < options.size(); j++)
				{
					if (opW9_listHotkeys[j] == key)
					{
						select(j);
						break;
					}
				}
			}
			else
				select(unknown98 + key - 'a');
			break;
	}
}

void CList::select(int index)
{
	if (index >= 0 && index < options.size() && (enabled == NULL || enabled->at(index)))
		callback(unknown74,unknownC0 ? intToString(index) : options[index]);
}

void CList::highlight(int index)
{
	if (index >= 0 && index < options.size() && (enabled == NULL || enabled->at(index)))
		highlightCallback(unknown74,options[index]);
}

void CList::scroll(int amount, int target)
{
	int newStart = (target == -1 ? unknown98 - amount : target);
	opW9_clamp(0,newStart,options.size() - numVisible);
	if (newStart != unknown98)
	{
		if (moreAbove)
			removeSubconsole(moreAbove);
		if (newStart > 0)
		{
			moreAbove = new CListOption(this,7,1,optionWidth,options[newStart - 1],0,false,0,-1,true,0,-1);
			moreAbove->draw();
		}
		else
			moreAbove = NULL;

		if (moreBelow)
			removeSubconsole(moreBelow);
		if (newStart + numVisible < options.size())
		{
			moreBelow = new CListOption(this,7,numVisible + 2,optionWidth,options[newStart + numVisible],0,false,0,1,true,0,-1);
			moreBelow->draw();
		}
		else
			moreBelow = NULL;

		if (newStart + numVisible <= unknown98 || newStart >= unknown98 + numVisible)
		{
			for (int i = 0; i < listOptions.size(); i++)
			{
				if (listOptions[i])
					removeSubconsole(listOptions[i]);
			}
			listOptions.clear();

			for (int i = newStart, y = 2; i < newStart + numVisible; i++, y++)
			{
				listOptions.push_back(new CListOption(this,7,y,optionWidth,options[i],0,false,i,0,enabled ? enabled->at(i) : true,unknownA4 ? unknownA4->at(i) : 0,unknownA8 ? unknownA8->at(i) : -1));
				listOptions.back()->draw();
			}
		}
		else if (newStart < unknown98)
		{
			for (int i = 0; i < unknown98 - newStart; i++)
			{
				removeSubconsole(listOptions.back());
				listOptions.pop_back();
			}
			for (int i = 0; i < listOptions.size(); i++)
				listOptions[i]->setPos(Pos(7,listOptions[i]->getPos().y + (unknown98 - newStart)));
			for (int i = 0, y = listOptions.front()->getPos().y - 1, index = listOptions.front()->unknown6c - 1; i < unknown98 - newStart; i++, y--, index--)
			{
				OpW9_insertAt(listOptions,0,new CListOption(this,7,y,optionWidth,options[index],0,false,index,0,enabled ? enabled->at(index) : true,unknownA4 ? unknownA4->at(index) : 0,unknownA8 ? unknownA8->at(index) : -1));
				listOptions.front()->draw();
			}
			for (int i = 0, index = newStart; i < listOptions.size(); i++, index++)
				listOptions[i]->unknown6c = index;
		}
		else
		{
			for (int i = 0; i < newStart - unknown98; i++)
			{
				removeSubconsole(listOptions.front());
				listOptions.erase(listOptions.begin());
			}
			for (int i = 0; i < listOptions.size(); i++)
				listOptions[i]->setPos(Pos(7,listOptions[i]->getPos().y - (newStart - unknown98)));
			for (int i = 0, y = listOptions.back()->getPos().y + 1, index = listOptions.back()->unknown6c + 1; i < newStart - unknown98; i++, y++, index++)
			{
				listOptions.push_back(new CListOption(this,7,y,optionWidth,options[index],0,false,index,0,enabled ? enabled->at(index) : true,unknownA4 ? unknownA4->at(index) : 0,unknownA8 ? unknownA8->at(index) : -1));
				listOptions.back()->draw();
			}
			for (int i = 0, index = newStart; i < listOptions.size(); i++, index++)
				listOptions[i]->unknown6c = index;
		}

		unknown98 = newStart;
		updateScroll();
	}
}

void CList::updateScroll()
{
	for (int i = unknown98, j = 0, y = 2; j < numVisible; i++, j++, y++)
	{
		XColor color(*opW9_cfc180);
		if (enabled == NULL || enabled->at(i))
		{
			if (unknownA4 && unknownA4->at(i))
			{
				switch (unknownA4->at(i))
				{
					case 1: color = *opW9_cfd448;
					case 2: color = *opW9_d2d29c; break;
				}
			}
			else if (unknownA8 == NULL)
				color = *opW9_cf44c0;
			else
			{
				switch (unknownA8->at(i))
				{
					case 0: color = *opW9_cf44c0; break;
					case 1: color = *opW9_d1d46c; break;
					case 2: color = *opW9_d323c4; break;
					case 3: color = *opW9_d30424; break;
					case 4: color = *opW9_d2d29c; break;
				}
			}
		}
		else
			color = *opW9_d22fcc;
		putChar_418110(3,y,unknown9c ? opW9_listHotkeys[i] : y + 0x5f,color);
		putChar_418110(5,y,'-',*opW9_cf44c0);
	}
}

//==================================================================
// CLogMsg / CLogMsgs / CLog
//==================================================================

struct OpW9_LogSource	// NOTE: placeholder name
{
	char pad00[0x24];
	int unknown24;	// NOTE: placeholder name
};

struct LogMsg	// NOTE: placeholder name
{
	OpW9_LogSource *source;	// NOTE: placeholder name
	string text;
	int unknown20;	// NOTE: placeholder name
	int unknown24;	// NOTE: placeholder name
};

struct OpW9_LogStyle	// NOTE: placeholder name
{
	char pad00[0x24];
	int colors[3];	// NOTE: placeholder name
	int unknown30;	// NOTE: placeholder name
	int unknown34;	// NOTE: placeholder name
};
extern vector<OpW9_LogStyle*> opW9_logStyles;	// NOTE: placeholder name (0xd35b48)
extern vector<int> opW9_cfe704;	// NOTE: placeholder name

class CLogMsg : public Console
{
public:
	CLogMsg(XConsole *parent, int y, LogMsg *msg_, int type);	// 0x48e340

	void setText(const string &text);	// NOTE: placeholder name
	void colorize(int index);	// NOTE: placeholder name (0x48e3e0)

	LogMsg *msg;
};

class CLog;

class CLogMsgs : public Console	// NOTE: placeholder name
{
public:
	CLogMsgs(XConsole *parent, int type_);
	virtual ~CLogMsgs() { consoles.clear(); lines.clear(); }

	virtual bool input(XEvent *event);
	virtual void update();

	vector<LogMsg*> *getMessages();	// 0x48e4e0, NOTE: placeholder name
	vector<CLogMsg*> *getConsoles();	// NOTE: placeholder name (folded getter 0x45a840)
	CLog *getLog();	// NOTE: placeholder name (0x48e510)
	void unknown7b3df0(int value);	// NOTE: placeholder name
	void addLine(int index, int y, bool atFront);	// NOTE: placeholder name
	void scroll(int amount, bool unknown);	// NOTE: placeholder name
	void scrollToEnd();	// NOTE: placeholder name
	void toggleExpanded();	// NOTE: placeholder name
	void clearLines();	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
	bool expanded;	// NOTE: placeholder name
	int index;	// NOTE: placeholder name
	vector<CLogMsg*> consoles;	// NOTE: placeholder name
	bool unknown88;	// NOTE: placeholder name
	int lastIndex;	// NOTE: placeholder name
	vector<Console*> lines;	// NOTE: placeholder name
	int topIndex;	// NOTE: placeholder name
	int offset;	// NOTE: placeholder name
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);

	string title;
	int align;
};

class OpW9_LogFilter : public Console	// NOTE: placeholder name (0x70 bytes)
{
public:
	OpW9_LogFilter(XConsole *parent);	// 0x48e1d0
	void unknown48e250(bool value);	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
};

class CLog : public Console
{
public:
	CLog(XConsole *parent, int mode_);
	virtual ~CLog() {}

	virtual bool input(XEvent *event);
	virtual void update();
	virtual void open();
	virtual void close();

	CLogMsgs *getMessages();	// NOTE: placeholder name (0x48e760)
	bool getUnknown80();	// NOTE: placeholder name (0x48e740)
	bool unknown48e7b0();	// NOTE: placeholder name
	void unknown7b5f40(CLogMsg *msg, bool top);	// NOTE: placeholder name
	bool unknown7b60e0();	// NOTE: placeholder name
	void unknown7b62c0();	// NOTE: placeholder name
	void unknown7b6370();	// NOTE: placeholder name

	bool opened;	// NOTE: placeholder name
	unsigned int closeTime;	// NOTE: placeholder name
	Console *unknown74;	// NOTE: placeholder name
	Console *unknown78;	// NOTE: placeholder name
	int mode;	// NOTE: placeholder name
	bool unknown80;	// NOTE: placeholder name
	Console *unknown84;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
};

class OpW9_Push : public XConsole	// NOTE: placeholder name (0xcec054)
{
public:
	bool operate();	// NOTE: placeholder name (0x49aa00)
	bool unknown49aa60();	// NOTE: placeholder name
	void unknown819a60();	// NOTE: placeholder name
	bool unknown805190(Pos &pos);	// NOTE: placeholder name
	void unknown827950();	// NOTE: placeholder name
	void unknown49ac70();	// NOTE: placeholder name
	Pos &getOffset();	// NOTE: placeholder name (folded getter 0x458ef0)
	void unknown8069e0(Pos pos, int a);	// NOTE: placeholder name
	void unknown8279c0(const Pos &pos);	// NOTE: placeholder name
	void unknown806e70(const Pos &pos, int a);	// NOTE: placeholder name
};
extern OpW9_Push *opW9_cec054;	// NOTE: placeholder name

class OpW9_UIControl : public XConsole	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown49c3d0(int value);	// NOTE: placeholder name
};
extern OpW9_UIControl *opW9_cec058;	// NOTE: placeholder name

class HEntity;
class OpW9_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	int unknown715800(vector<HEntity> &out);	// NOTE: placeholder name
	HEntity getPlayer() throw();	// 0x4630f0
	vector<vector<HEntity> > *unknown463ec0();	// NOTE: placeholder name
	bool unknown463160(const Pos &pos);	// NOTE: placeholder name
	int unknown4642d0();	// NOTE: placeholder name
};
extern OpW9_World *opW9_world;	// NOTE: placeholder name

struct OpW9_GameState	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
};
class OpW9_HGameState	// NOTE: placeholder name
{
public:
	int ID;
	OpW9_GameState *operator->() const;	// 0x9b7910
};
extern OpW9_HGameState opW9_gameState;	// NOTE: placeholder name (0xd1e888)

class OpW9_Audio	// NOTE: placeholder name (0xcefaa8)
{
public:
	void play(int sound, int a, int b, int c, int d);	// NOTE: placeholder name (0x793450)
};
extern OpW9_Audio *opW9_audio;	// NOTE: placeholder name

extern CLog *opW9_log0;	// NOTE: placeholder name (0xcec0b0)
extern CLogMsgs *opW9_logMsgs0;	// NOTE: placeholder name (0xcec0b4)
extern CLog *opW9_log1;	// NOTE: placeholder name (0xcec0b8)
extern CLogMsgs *opW9_logMsgs1;	// NOTE: placeholder name (0xcec0bc)
extern CLog *opW9_log2;	// NOTE: placeholder name (0xcec0c0)
extern CLogMsgs *opW9_logMsgs2;	// NOTE: placeholder name (0xcec0c4)
class OpW9_LogTabs : public Console	// NOTE: placeholder name (0xcec0d0)
{
};
extern OpW9_LogTabs *opW9_cec0d0;	// NOTE: placeholder name
class OpW9_MessageLog : public XConsole	// NOTE: placeholder name (0xcec0f4)
{
public:
	void unknown7b1cc0();	// NOTE: placeholder name
};
extern OpW9_MessageLog *opW9_cec0f4;	// NOTE: placeholder name
class OpW9_Unk98a3a0	// NOTE: placeholder name (0xcec0e0)
{
public:
	void unknown98a3a0();	// NOTE: placeholder name
};
extern OpW9_Unk98a3a0 *opW9_cec0e0;	// NOTE: placeholder name
extern XConsole *opW9_cec118;	// NOTE: placeholder name
extern XConsole *opW9_cec0f8;	// NOTE: placeholder name
extern Rect opW9_rect_cf4154;	// NOTE: placeholder name
extern Rect opW9_rect_d39268;	// NOTE: placeholder name
extern Rect opW9_rects_d316c4[];	// NOTE: placeholder name
extern Rect opW9_rects_d35dc8[];	// NOTE: placeholder name
extern int opW9_cf4564;	// NOTE: placeholder name
extern int opW9_cf4568;	// NOTE: placeholder name
extern int opW9_cf456c;	// NOTE: placeholder name
extern int opW9_cf4570;	// NOTE: placeholder name
extern int opW9_logConsoleRect0Y;	// NOTE: placeholder name (0xd01a18)
extern int opW9_logConsoleRect0Width;	// NOTE: placeholder name (0xd01a1c)
extern int opW9_logConsoleRect0Height;	// NOTE: placeholder name (0xd01a20)
extern int opW9_logConsoleRect2Y;	// NOTE: placeholder name (0xd01a38)
extern Rect opW9_logRects[];	// NOTE: placeholder name (0xd30234)
extern Rect opW9_logConsoleRects[];	// NOTE: placeholder name (0xd01a14)
extern int opW9_logRect0Width;	// NOTE: placeholder name (0xd3023c, opW9_logRect0Width)
extern int opW9_logRect0Height;	// NOTE: placeholder name (0xd30240)
extern int opW9_logRect1Height;	// NOTE: placeholder name (0xd30250)
extern int opW9_logExpandedWidth;	// NOTE: placeholder name (0xd358b8)
extern int opW9_logExpandedHeight;	// NOTE: placeholder name (0xd358bc)
extern int opW9_cebd5c;	// NOTE: placeholder name
extern int opW9_d28d18;	// NOTE: placeholder name
extern int opW9_d28d64;	// NOTE: placeholder name
extern int opW9_cf462c;	// NOTE: placeholder name
extern int opW9_caf12c;	// NOTE: placeholder name
extern bool opW9_ba7694[];	// NOTE: placeholder name
extern vector<int> opW9_d22590;	// NOTE: placeholder name
unsigned int opW9_minUnsigned(unsigned int a, unsigned int b);	// NOTE: placeholder name (0x9e2310)
int minInt(int a, int b);	// 0x9cdb30

void CLogMsg::setText(const string &text)
{
	msg->text = text;
	print(0,0,msg->text);
	engine->stopAll();
	if (getParent() != opW9_logMsgs2 || !opW9_log2->isHidden())
		colorize(2);
}

CLogMsgs::CLogMsgs(XConsole *parent, int type_)
	: Console(parent,opW9_logRects[type_],0,true,-1)
	, type		(type_)
	, expanded	(false)
	, unknown88	(false)
	, lastIndex	(-1)
	, topIndex	(-1)
	, offset	(-9999)
{
}

void CLogMsgs::unknown7b3df0(int value)
{
	unknown60 = 1;
	setHidden(false);
	clear();
	if (value == -1)
	{
		index = getMessages()->size() - 1;
		if (type == 1)
			index -= opW9_logMsgs0->getHeight();
	}
	else
		index = value;

	for (int i = index, y = getHeight() - 1; i >= 0 && y >= 0; i--, y--)
		consoles.push_back(new CLogMsg(this,y,(*getMessages())[i],type));
	reverse(consoles.begin(),consoles.end());
	for (unsigned int i = 0; i < consoles.size(); i++)
		consoles[i]->colorize(0);
}

void CLogMsgs::addLine(int index, int y, bool atFront)
{
	vector<LogMsg*> *messages = getMessages();
	string text = (*messages)[index]->text;
	if (index - 1 >= 0 && (*messages)[index - 1]->unknown24 == (*messages)[index]->unknown24)
	{
		if ((*messages)[index]->text.size() >= 6 && (*messages)[index]->text[5] == '_')
			text.erase(0,5);
		text.insert(text.begin(),5,' ');
	}
	Console *line = new Console(opW9_cec058,text.size(),1,1,y,0,false,-1);
	if (atFront)
		OpW9_insertAt(lines,0,line);
	else
		lines.push_back(line);
	line->print(0,0,text);
	line->unknown48c3c0(opW9_cfe704[opW9_logStyles[(*messages)[index]->source->unknown24]->unknown34]);
}

void CLogMsgs::update()
{
	if (isHidden())
		return;

	switch (unknown60)
	{
		case 0:
			break;
		case 1:
			if (!engine->isRunning())
				unknown60 = 3;
			break;
		case 3:
			if (type == 2 && opW9_d28d18 >= 0)
			{
				vector<LogMsg*> *messages = getMessages();
				if (index == messages->size() - 1)
				{
					if (lastIndex != -1)
						clearLines();
				}
				else if (lastIndex != index)
				{
					if (offset == -9999)
						offset = opW9_ba7694[opW9_cf462c] ? -8 : 0;
					int height = opW9_cec054->getHeight() * opW9_caf12c + offset - 2;
					if (lastIndex == -1)
					{
						opW9_cec058->unknown49c3d0(0);
						opW9_cec058->unknown49c3d0(1);
						lastIndex = index;
						topIndex = index + 1;
						for (int i = topIndex, j = 0, y = height; i >= 0 && j < height; i--, j++, y--)
							addLine(i,y,true);
					}
					else if (messages->size() > height)
					{
						int delta = (index - lastIndex) * 8;
						if (delta < 0)
						{
							if (abs(delta) > height)
								delta = -height;
							int start = topIndex - height + delta;
							if (start < 0)
							{
								delta += abs(start);
								start = 0;
							}
							for (int i = abs(delta); i != 0; i--)
							{
								opW9_cec058->removeSubconsole(lines.back());
								lines.pop_back();
							}
							for (unsigned int i = 0; i < lines.size(); i++)
								lines[i]->move(0,-delta);
							int y = lines.empty() ? height : lines.front()->getPos().y - 1;
							for (int i = start - delta - 1, j = abs(delta); j != 0; i--, j--, y--)
								addLine(i,y,true);
						}
						else
						{
							if (delta > height)
								delta = height;
							int end = topIndex + delta;
							if (end > messages->size() - 1)
							{
								delta = messages->size() - 1 - topIndex;
								end = messages->size() - 1;
							}
							for (int i = delta; i != 0; i--)
							{
								opW9_cec058->removeSubconsole(lines.front());
								removeVectorElement(lines,0);
							}
							for (unsigned int i = 0; i < lines.size(); i++)
								lines[i]->move(0,-delta);
							int y = lines.empty() ? 0 : lines.back()->getPos().y + 1;
							for (int i = topIndex + 1, j = delta; j != 0; i++, j--, y++)
								addLine(i,y,false);
						}
						topIndex += delta;
						lastIndex = index;
					}
				}
			}
			break;
	}
	XConsole::update();
}

void CLogMsgs::scroll(int amount, bool unknown)
{
	if (amount == 0 || isHidden())
		return;

	int oldIndex = index;
	if (amount < 0)
	{
		amount = -amount;
		int minIndex = (type == 0 ? opW9_logRect1Height : 0);
		if (index - getHeight() >= minIndex)
		{
			int top = index - getHeight() + 1;
			if (top - amount < minIndex)
				amount = top - minIndex;
			getLog()->unknown7b5f40(consoles.back(),0);
			if (amount >= consoles.size())
			{
				for (unsigned int i = 0; i < consoles.size(); i++)
				{
					if (consoles[i])
						removeSubconsole(consoles[i]);
				}
				consoles.clear();
				consoles.clear();
			}
			else
			{
				for (int i = 0; i < amount; i++)
				{
					removeSubconsole(consoles.back());
					consoles.pop_back();
				}
				for (unsigned int i = 0; i < consoles.size(); i++)
					consoles[i]->setPos(Pos(consoles[i]->getPos(),0,amount));
			}
			if (amount > getHeight())
			{
				index -= amount;
				amount = getHeight();
				top = index + 1;
			}
			else
				index -= amount;
			int color = consoles.empty() ? 3 : 0;
			for (int i = 0, j = top - 1, y = consoles.empty() ? getHeight() - 1 : consoles.front()->getPos().y - 1; i < amount; i++, y--, j--)
			{
				OpW9_insertAt(consoles,0,new CLogMsg(this,y,(*getMessages())[j],type));
				consoles.front()->colorize(color);
			}
		}
	}
	else if (index < getMessages()->size() - 1)
	{
		amount = minInt(index + amount,getMessages()->size() - 1) - index;
		getLog()->unknown7b5f40(consoles.front(),1);
		if (amount >= consoles.size())
		{
			for (unsigned int i = 0; i < consoles.size(); i++)
			{
				if (consoles[i])
					removeSubconsole(consoles[i]);
			}
			consoles.clear();
			consoles.clear();
		}
		else
		{
			for (int i = 0; i < amount; i++)
			{
				removeSubconsole(consoles.front());
				removeVectorElement(consoles,0);
			}
			for (unsigned int i = 0; i < consoles.size(); i++)
				consoles[i]->setPos(Pos(consoles[i]->getPos(),0,-amount));
		}
		if (amount > getHeight())
		{
			index = index + amount - getHeight();
			amount = getHeight();
		}
		int color = consoles.empty() ? 3 : 0;
		for (int i = 0, j = index + 1, y = consoles.empty() ? 0 : consoles.back()->getPos().y + 1; i < amount; i++, y++, j++)
		{
			consoles.push_back(new CLogMsg(this,y,(*getMessages())[j],type));
			consoles.back()->colorize(color);
		}
		index += amount;
	}
	else if (opW9_cebd5c == 2 && !unknown)
	{
		if (type == 0 && opW9_log0->getUnknown80())
		{
			opW9_log0->unknown7b60e0();
			return;
		}
		else if (type == 2 && opW9_log2->unknown48e7b0())
		{
			opW9_log2->unknown7b6370();
			return;
		}
	}

	if (type == 0)
		opW9_logMsgs1->scroll(index - oldIndex,false);
}

void CLogMsgs::scrollToEnd()
{
	if (isHidden())
		return;
	if (index != getMessages()->size() - 1)
		scroll(getMessages()->size() - 1 - index,false);
}

void CLogMsgs::toggleExpanded()
{
	expanded = !expanded;
	if (expanded)
	{
		resize(opW9_logExpandedWidth,opW9_logExpandedHeight);
		int count = opW9_minUnsigned(index - consoles.size(),opW9_logExpandedHeight - consoles.size());
		for (unsigned int i = 0; i < consoles.size(); i++)
			consoles[i]->setPos(Pos(0,count + i));
		for (int i = 0, j = index - consoles.size() - count + 1, y = 0; i < count; i++, j++, y++)
		{
			OpW9_insertAt(consoles,i,new CLogMsg(this,y,(*getMessages())[j],type));
			consoles[i]->colorize(3);
		}
		if (consoles.back()->getPos().y != getHeight() - 1)
		{
			for (int y = consoles.back()->getPos().y; y < getHeight(); y++, index++)
			{
				consoles.push_back(new CLogMsg(this,y,(*getMessages())[index + 1],type));
				consoles.back()->colorize(3);
			}
		}
	}
	else
	{
		resize(opW9_logRect0Width,opW9_logRect0Height);
		while (consoles.size() > opW9_logRect0Height)
		{
			removeSubconsole(consoles.front());
			removeVectorElement(consoles,0);
		}
		for (unsigned int i = 0; i < consoles.size(); i++)
			consoles[i]->setPos(Pos(0,i));
	}
	if (!expanded)
		scrollToEnd();
	opW9_logMsgs1->scroll((opW9_logExpandedHeight - opW9_logRect1Height) * (expanded ? -1 : 1),false);
}

void CLogMsgs::clearLines()
{
	topIndex = -1;
	lastIndex = -1;
	if (lines.empty())
		return;
	for (unsigned int i = 0; i < lines.size(); i++)
		opW9_cec058->removeSubconsole(lines[i]);
	lines.clear();
}

void CLog::open()
{
	unknown60 = 1;
	setHidden(false);
	if (opW9_cebd5c == 2 && !opened)
	{
		clear();
		animate("A_4_Border");
		unknown60 = 3;
		opened = true;
	}
	if (opened)
	{
		clearInterior();
		animate("CLog_Content");
	}
	else
	{
		clear();
		animate("CLog_Border");
		opened = true;
	}
	setScaleX(1.0f);
	setScaleY(1.0f);
}

void CLog::close()
{
	unknown60 = 4;
	getMessages()->close();
	closeTime = opW9_tickCount;
	animate("A_BlockFadeInterior");
}

void CLog::update()
{
	if (isHidden())
		return;

	switch (unknown60)
	{
		case 0:
			break;
		case 1:
			if (!engine->isRunning())
				unknown60 = 3;
			break;
		case 3:
			if (unknown74 && !unknown74->engine->unknown454d30() && unknown74)
			{
				removeSubconsole(unknown74);
				unknown74 = NULL;
			}
			if (unknown78 && !unknown78->engine->unknown454d30() && unknown78)
			{
				removeSubconsole(unknown78);
				unknown78 = NULL;
			}
			engine->isRunning();
			if (mode == 2)
			{
				if (opW9_d22590[0x53] == 0 && opW9_gameState->type != 1 && opW9_world->unknown4642d0() >= 100)
					opW9_audio->play(0x53,1,0,0,1);
				if (opW9_cebd5c == 2 && opW9_d22590[0x53] && opW9_d22590[0x54] == 0 && opW9_gameState->type != 1 && opW9_world->unknown4642d0() >= 100)
					opW9_audio->play(0x54,1,0,0,1);
			}
			break;
		case 4:
			engine->isRunning();
			if (getScaleX() != 0)
			{
				if (opW9_tickCount - closeTime >= 500)
				{
					setScaleX(0);
					setScaleY(0);
				}
				else
				{
					setScaleX((float)(1 - (opW9_tickCount - closeTime) / 500.0));
					setScaleY((float)(1 - (opW9_tickCount - closeTime) / 500.0));
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			opW9_keyMap->unknown416640();
			if (unknown74)
			{
				removeSubconsole(unknown74);
				unknown74 = NULL;
			}
			if (unknown78)
			{
				removeSubconsole(unknown78);
				unknown78 = NULL;
			}
			break;
	}
	XConsole::update();
}

bool CLogMsgs::input(XEvent *event)
{
	if (isHidden() || opW9_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	bool unknown = false;
	int amount;
	switch (event->type)
	{
		case 0xc2:
		case 0xc3:
			if (unknown88)
			{
				unknown88 = false;
				return false;
			}
			if (opW9_cec054->operate())
				return false;
			if (type != 0 || opW9_log2->unknown48e7b0())
				return false;
			amount = (event->type == 0xc2 ? -1 : 1);
			goto doScroll;
		case 0xc4:
		case 0xc5:
			if (unknown88)
			{
				unknown88 = false;
				return false;
			}
			if (opW9_cec054->operate())
				return false;
			if (opW9_cebd5c == 2)
			{
				if (type == 0 && opW9_d28d64 != 3)
				{
					opW9_cec0d0->input(&XEvent(0xd3));
					opW9_logMsgs2->input(&XEvent(event->type));
				}
				else if (type == 2 && !opW9_log2->unknown48e7b0())
				{
					opW9_log2->unknown7b62c0();
					return true;
				}
			}
			if (type != 2)
				return false;
			amount = (event->type == 0xc4 ? 1 : -1);
			goto doScroll;
		case 0xc6:
			if (type == 1)
			{
				opW9_logMsgs0->input(&XEvent(0xc6));
				return true;
			}
			amount = -1;
			unknown = true;
			goto doScroll;
		case 0xc7:
			if (type == 1)
			{
				opW9_logMsgs0->input(&XEvent(0xc7));
				return true;
			}
			amount = 1;
			unknown = true;
			goto doScroll;
		case 0xc8:
			if (type != 0 || opW9_log2->unknown48e7b0())
				return false;
			amount = -getHeight();
			goto doScroll;
		case 0xc9:
			if (type != 0 || opW9_log2->unknown48e7b0())
				return false;
			amount = getHeight();
		doScroll:
			if (type == 0 && opW9_cebd5c == 2 && !opW9_log0->getUnknown80())
			{
				opW9_log0->unknown7b60e0();
				return true;
			}
			scroll(amount,unknown);
			return true;
		case 0xca:
			if (type != 0 || opW9_log2->unknown48e7b0())
				return false;
			scrollToEnd();
			return true;
		case 0xce:
			if (type != 2)
				return false;
			opW9_log2->unknown7b6370();
			return true;
	}
	return false;
}

CLog::CLog(XConsole *parent, int mode_)
	: Console(parent,opW9_logConsoleRects[mode_],0,true,mode_ ? 5 : 11)
	, unknown74	(NULL)
	, unknown78	(NULL)
	, mode		(mode_)
	, unknown80	(false)
	, unknown88	(0)
{
	switch (mode)
	{
		case 0:
			opW9_logMsgs0 = new CLogMsgs(this,mode);
			unknown84 = new OpW9_LogFilter(this);
			break;
		case 1:
			opW9_logMsgs1 = new CLogMsgs(this,mode);
			unknown84 = NULL;
			break;
		case 2:
			opW9_logMsgs2 = new CLogMsgs(this,mode);
			unknown84 = NULL;
			break;
	}
	setTitle(new ConsoleTitle(this,mode == 2 ? "/ C O M B A T /" : "/ L O G /",0,0));
	opened = false;
}

void CLog::unknown7b5f40(CLogMsg *msg, bool top)
{
	Console *&marker = (top ? unknown74 : unknown78);
	if (marker)
	{
		clear(marker);
		removeSubconsole(marker);
	}
	marker = NULL;
	marker = new Console(this,unknown80 ? (top ? opW9_rect_cf4154 : opW9_rect_d39268) : (top ? opW9_rects_d316c4[mode] : opW9_rects_d35dc8[mode]),0,false,-1);
	msg->unknown429fe0(marker,Pos(0,0),0);
	marker->animate("A_BlockFadePure");
}

bool CLog::unknown7b60e0()
{
	if (mode != 0 || opW9_logMsgs0->getConsoles()->empty())
		return false;
	if (!unknown80 && (!opW9_cec118->isHidden() || !opW9_cec0f8->isHidden()))
		return false;

	unknown80 = !unknown80;
	if (unknown78)
	{
		clear(unknown78);
		removeSubconsole(unknown78);
	}
	unknown78 = NULL;
	if (unknown80)
	{
		resize(opW9_cf456c,opW9_cf4570);
		setPos(opW9_cf4564,opW9_cf4568);
		engine->stopAll();
		animate("A_CLog_Border_Expand");
		if (!opW9_cec0f4->isHidden())
			opW9_cec0f4->unknown7b1cc0();
	}
	else
	{
		resize(opW9_logConsoleRect0Width,opW9_logConsoleRect0Height);
		setPos(opW9_logConsoleRects[0].x,opW9_logConsoleRect0Y);
		engine->stopAll();
		animate("A_CLog_Border_Shrink");
	}
	((OpW9_LogFilter*)unknown84)->unknown48e250(!unknown80);
	opW9_logMsgs0->toggleExpanded();
	if (opW9_cec0e0)
		opW9_cec0e0->unknown98a3a0();
	return true;
}

void CLog::unknown7b62c0()
{
	if (!unknown48e7b0())
	{
		if (opW9_tickCount < unknown88)
			return;
		if (opW9_log0->getUnknown80())
			opW9_log0->unknown7b60e0();
		opW9_keyMap->registerConsole(9,this,0xce,0);
		if (opW9_cebd5c == 2)
		{
			setPos(getPos().x,0);
			opW9_cec0d0->setHidden(true);
			opW9_cec0d0->unknown48e8b0();
		}
	}
}

void CLog::unknown7b6370()
{
	if (unknown48e7b0())
	{
		opW9_keyMap->unknown416640();
		if (opW9_cebd5c == 2)
		{
			setPos(getPos().x,opW9_logConsoleRect2Y);
			opW9_cec0d0->setHidden(false);
			opW9_cec0d0->unknown48e8b0();
		}
		opW9_logMsgs2->scrollToEnd();
		unknown88 = opW9_tickCount + 100;
	}
}

bool CLog::input(XEvent *event)
{
	int amount;	// NOTE: unused
	if (isHidden() || opW9_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0xcc:
		case 0xcd:
			if (mode == 2)
			{
				unknown7b6370();
				return true;
			}
		case 0xcb:
			if (opW9_log2->unknown48e7b0())
				return false;
			return unknown7b60e0();
	}
	return false;
}

//==================================================================
// CModeReport / CMulticonsoleButton(s)
//==================================================================

class OpW9_Inventory : public Console	// NOTE: placeholder name (CInventory at 0xcec08c)
{
public:
	void unknown4aa7c0();	// NOTE: placeholder name
};
extern OpW9_Inventory *opW9_inventory;	// NOTE: placeholder name

class OpW9_ModeHost : public Console	// NOTE: placeholder name
{
public:
	void unknown4a9bb0();	// NOTE: placeholder name
};

class OpW9_World2	// NOTE: placeholder name (0xcefc4c)
{
public:
	bool unknown71bbd0();	// NOTE: placeholder name
};
extern OpW9_World2 *opW9_world2;	// NOTE: placeholder name

class OpW9_ModeSwitcher	// NOTE: placeholder name (0xcec034)
{
public:
	void unknown987b10(int mode);	// NOTE: placeholder name

	char pad00[0xb0];
	int unknownB0;	// NOTE: placeholder name
};
extern OpW9_ModeSwitcher *opW9_cec034;	// NOTE: placeholder name

extern int opW9_consoleMode;	// NOTE: placeholder name (0xd28d64)
extern XColor *opW9_cf6b24;	// NOTE: placeholder name
extern XColor *opW9_d25e0c;	// NOTE: placeholder name
extern XColor *opW9_d2981c;	// NOTE: placeholder name
extern XColor *opW9_colorBlack;	// NOTE: placeholder name (0xcfe674)
extern vector<XColor> opW9_d2b4bc;	// NOTE: placeholder name
extern const char opW9_modeChars[];	// NOTE: placeholder name (0xb8f714)
extern int opW9_d31680;	// NOTE: placeholder name
extern int opW9_d31684;	// NOTE: placeholder name
extern int opW9_d31688;	// NOTE: placeholder name
extern int opW9_d3168c;	// NOTE: placeholder name

class CModeReport : public Console
{
public:
	CModeReport(XConsole *parent, const Rect &rect, string text);

	virtual void update();

	unsigned int startTime;	// NOTE: placeholder name
};

CModeReport::CModeReport(XConsole *parent, const Rect &rect, string text)
	: Console(parent,rect,0,false,-1)
{
	startTime = opW9_tickCount;
	if (getParent() == opW9_cec0d0)
	{
		setFore(*opW9_colorBlack);
		opW9_d2b4bc[0] = *opW9_cf6b24;
		print(0,0,"`b" + intToString(0) + "`" + text + "`x`");
	}
	else
	{
		setFore(*opW9_d2981c);
		print(0,0,text);
	}
}

void CModeReport::update()
{
	if (opW9_tickCount >= startTime + 2000)
		getParent() == opW9_cec0d0 ? ((Console*)getParent())->unknown48e8b0() : (getParent() == opW9_inventory ? ((OpW9_Inventory*)getParent())->unknown4aa7c0() : ((OpW9_ModeHost*)getParent())->unknown4a9bb0());
}

class CMulticonsoleButton : public Console
{
public:
	CMulticonsoleButton(XConsole *parent, int x, int mode_);	// 0x48e820

	virtual bool isActive();
	virtual bool input(XEvent *event);

	void draw();	// NOTE: placeholder name

	int mode;	// NOTE: placeholder name
};

class CMulticonsoleButtons : public Console
{
public:
	CMulticonsoleButtons(XConsole *parent);

	virtual bool input(XEvent *event);

	void select(int previous);	// NOTE: placeholder name

	vector<CMulticonsoleButton*> buttons;	// NOTE: placeholder name
	CModeReport *report;	// NOTE: placeholder name
};

bool CMulticonsoleButton::input(XEvent *event)
{
	if (opW9_world2->unknown71bbd0())
		return false;
	switch (event->type)
	{
		case 0xcf:
		{
			int previous = opW9_consoleMode;
			if (opW9_consoleMode != mode)
				opW9_cec034->unknown987b10(mode);
			((CMulticonsoleButtons*)getParent())->select(previous);
			return true;
		}
	}
	return false;
}

bool CMulticonsoleButton::isActive()
{
	if (opW9_consoleMode == mode && (opW9_cebd5c != 2 || opW9_consoleMode != 3))
		return false;
	animate("A_ButtonHover_Begin_PART_HOV_OK");
	return true;
}

CMulticonsoleButtons::CMulticonsoleButtons(XConsole *parent)
	: Console(parent,opW9_cebd5c == 2 ? 5 : 9,1,opW9_d31680 + opW9_d31688 - 1 - (opW9_cebd5c == 2 ? 5 : 9),opW9_d31684 + opW9_d3168c - 1,0,false,8)
{
	report = NULL;
	putChar_418110(0,0,'{',*opW9_cf6b24);
	for (int x = 2; x < getWidth() - 1; x += 2)
		putChar_418110(x,0,'\\',*opW9_cf6b24);
	putChar_418110(getWidth() - 1,0,'}',*opW9_cf6b24);
	for (int i = (opW9_cebd5c != 2 ? 0 : 2), x = 1; i < 4; i++, x += 2)
		buttons.push_back(new CMulticonsoleButton(this,x,i));
}

bool CMulticonsoleButtons::input(XEvent *event)
{
	if (isHidden() || opW9_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opW9_world2->unknown71bbd0())
		return false;

	switch (event->type)
	{
		case 0xd0:
		case 0xd1:
		case 0xd2:
		case 0xd3:
		{
			int previous = opW9_consoleMode;
			int newMode = event->type - 0xd0;
			if (opW9_consoleMode != newMode)
				opW9_cec034->unknown987b10(newMode);
			select(previous);
			return true;
		}
	}
	return false;
}

void CMulticonsoleButtons::select(int previous)
{
	if (opW9_cebd5c == 2)
	{
		if (report)
			unknown48e8b0();
		switch (opW9_consoleMode)
		{
			case 0:
				opW9_cec054->input(&XEvent(0x89));
				break;
			case 1:
				opW9_cec054->input(&XEvent(0x8b));
				break;
			case 2:
			case 3:
			{
				string text = (opW9_consoleMode == 2 ? " EXTENDED LOG MODE ACTIVATED " : " COMBAT LOG MODE ACTIVATED ");
				report = new CModeReport(this,Rect(-text.size() - 1,0,text.size(),1),text);
				if (opW9_consoleMode == 3 && previous == 3)
				{
					if (!opW9_log2->unknown48e7b0())
						opW9_log2->unknown7b62c0();
					else
						opW9_log2->unknown7b6370();
				}
				break;
			}
		}
	}
}

class CAllySymbol : public Console
{
public:
	virtual void refresh();
};

//==================================================================
// CAlly / CAllies
//==================================================================

struct OpW9_AIOrder	// NOTE: placeholder name
{
	bool unknown0;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
	class HEntity *dummy;	// NOTE: placeholder layout
};

class EntityAI	// NOTE: placeholder layout
{
public:
	bool unknown458eb0();	// NOTE: placeholder name
	struct OpW9_AITarget *unknown459050();	// NOTE: placeholder name
	int unknown459280();	// NOTE: placeholder name
	void unknown5b5380(class OpW9_Order *order);	// NOTE: placeholder name
};

class Entity	// NOTE: placeholder layout
{
public:
	Pos &getPosition() throw();	// 0x45a4a0
	XColor *unknown5ca2b0();	// NOTE: placeholder name
	EntityAI *getAI();	// NOTE: placeholder name (folded getter 0x45b590)
	int getFaction();
	int getSize();
	Pos unknown45a4c0();	// NOTE: placeholder name
	bool unknown45aaa0(HEntity entity);	// NOTE: placeholder name
	void *getTarget();
	struct OpW9_EntityData *getData();	// NOTE: placeholder name (folded getter 0x9b4350)
};
struct OpW9_EntityData	// NOTE: placeholder name
{
	char pad000[0x158];
	int unknown158;	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
	bool isValid() const;
	bool isNull() const;
	Entity *operator->() const throw();	// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;
};

struct OpW9_AITarget	// NOTE: placeholder name
{
	bool unknown0;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
	HEntity target;	// NOTE: placeholder name
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp();
};

struct OpW9_Pair	// NOTE: placeholder name
{
	OpW9_Pair(int value);	// 0x409990
	int a;
	int b;
};

class Cell
{
public:
	HEntity getEntity();
	bool unknown4550b0();	// NOTE: placeholder name (folded getter)
	bool unknown45db70();	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Pos &p);	// 0x9ced70
};
extern Array2D<Cell *> opW9_cells;	// NOTE: placeholder name (0xcfd44c)

class OpW9_Info : public Console	// NOTE: placeholder name (CInfo at 0xcec11c)
{
public:
	void unknown8b4500(HEntity entity, HProp a, HProp b, const OpW9_Pair &c, int d, int e);	// NOTE: placeholder name
};

class CAlly;
class CAllies : public Console
{
public:
	CAllies(XConsole *parent);
	virtual ~CAllies() {}

	virtual bool input(XEvent *event);
	virtual void update();
	virtual void open();
	virtual void close();
	virtual void trigger(const string &command, int value);

	void unknown7b7980();	// NOTE: placeholder name
	void beginOrder();	// NOTE: placeholder name (0x7b8200)
	void endOrder();	// NOTE: placeholder name (0x7b8290)
	void unknown7b8500(HEntity entity);	// NOTE: placeholder name
	void scrollTop();	// NOTE: placeholder name
	void scrollBottom();	// NOTE: placeholder name
	void scrollUp();	// NOTE: placeholder name (0x7b78a0)
	void scrollDown();	// NOTE: placeholder name (0x7b78e0)
	void unknown7b8340(const Pos &pos);	// NOTE: placeholder name
	bool getUnknown48f0a0();	// NOTE: placeholder name
	void unknown48f2d0();	// NOTE: placeholder name
	void unknown48f2f0();	// NOTE: placeholder name
	void setUnknownA4(int value);	// NOTE: placeholder name (folded setter)
	vector<HEntity> *getUnknown94();	// NOTE: placeholder name (0x48f0e0)
	bool getUnknown48f0c0();	// NOTE: placeholder name

	bool opened;	// NOTE: placeholder name
	unsigned int closeTime;	// NOTE: placeholder name
	vector<CAlly*> allies;	// NOTE: placeholder name
	int scroll;	// NOTE: placeholder name
	CAlly *upArrow;	// NOTE: placeholder name
	CAlly *downArrow;	// NOTE: placeholder name
	bool unknown90;	// NOTE: placeholder name
	bool unknown91;	// NOTE: placeholder name
	vector<HEntity> unknown94;	// NOTE: placeholder name
	int unknownA4;	// NOTE: placeholder name
	bool unknownA8;	// NOTE: placeholder name
	int unknownAc;	// NOTE: placeholder name
};
extern Rect opW9_alliesRect;	// NOTE: placeholder name (0xd31680)
extern CAllies *opW9_allies;	// NOTE: placeholder name (0xcec0c8)
void opW9_unknown7b8bc0(HEntity entity, bool value);	// NOTE: placeholder name


extern XColor *opW9_d20b70;	// NOTE: placeholder name
extern XColor opW9_d29804;	// NOTE: placeholder name
extern XColor *opW9_d30264;	// NOTE: placeholder name
extern const int opW9_b96600[];	// NOTE: placeholder name
extern float opW9_ba6ae0;	// NOTE: placeholder name
float opW9_pulse(float low, float high, int period, int offset);	// NOTE: placeholder name (0x4371a0)

class CAlly : public Console
{
public:
	CAlly(XConsole *parent, int y, int number_, HEntity entity_, int type_);	// 0x48e980
	void setNumber(int number_);	// NOTE: placeholder name (folded setter 0x4ec710)

	virtual bool isActive();
	virtual void refresh();
	virtual bool input(XEvent *event);
	virtual void update();
	virtual void render();

	void unknown48eab0();	// NOTE: placeholder name
	void unknown48eea0();	// NOTE: placeholder name

	HEntity entity;
	int type;	// NOTE: placeholder name
	int number;	// NOTE: placeholder name
	Console *label;	// NOTE: placeholder name
	int unknown7c;	// NOTE: placeholder name
	HEntity unknown80;	// NOTE: placeholder name
	bool highlighted;	// NOTE: placeholder name
	int status;	// NOTE: placeholder name
};

void CAlly::update()
{
	if (isHidden())
		return;

	engine->isRunning();
	if (type == 1)
	{
		putChar_418110(6,0,0xb3,*entity->unknown5ca2b0());
		if (entity.operator->() && entity->getAI()->unknown459050())
		{
			int newStatus;
			if (entity->getAI()->unknown458eb0())
				newStatus = 2;
			else
				newStatus = entity->getAI()->unknown459050()->unknown0 ? 0 : 1;
			if (unknown7c != entity->getAI()->unknown459280() || (opW9_b96600[unknown7c] == 2 && unknown80 != entity->getAI()->unknown459050()->target))
			{
				unknown48eab0();
				status = newStatus;
				unknown48eea0();
			}
			else if (newStatus != status)
			{
				status = newStatus;
				unknown48eea0();
			}
		}
	}
	if (type < 2)
	{
		if (opW9_allies->getUnknown48f0a0())
		{
			print(1,0,intToString(number));
			setFore_417f80(1,0,*opW9_d20b70);
		}
		else if (opW9_allies->getUnknown48f0c0() && entity.isValid())
		{
			print(1,0,intToString(number));
			setFore_417f80(1,0,*opW9_d2981c);
		}
		else
			setChar_417f50(1,0,' ');
	}
	XConsole::update();
}

bool CAlly::input(XEvent *event)
{
	if (opW9_world2->unknown71bbd0())
		return false;

	switch (event->type)
	{
		case 0xd8:
			if (opW9_cec054->unknown49aa60() && entity.isValid())
				opW9_allies->unknown7b8340(entity->getPosition());
			else
			{
				switch (type)
				{
					case 0:
					case 1:
						if (!opW9_cec11c->isHidden())
							opW9_cec11c->unknown8b5080();
						opW9_unknown7b8bc0(entity,0);
						break;
					case 2:
						opW9_allies->scrollDown();
						break;
					case 3:
						opW9_allies->scrollUp();
						break;
				}
			}
			return true;
		case 0xd9:
			if (type == 1 && (opW9_cebd5c != 1 || opW9_cec11c->isHidden()))
				((OpW9_Info*)opW9_cec11c)->unknown8b4500(entity,HProp(),HProp(),OpW9_Pair(-1),0,0);
			return true;
	}
	return false;
}

bool CAlly::isActive()
{
	if (type == 0)
		opW9_cec054->unknown819a60();
	animate("A_ButtonHover_Begin_ALLY_HOV_OK");
	if (label)
		label->animate("A_ButtonHover_Begin_ALLY_HOV_OK");
	return true;
}

void CAlly::refresh()
{
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_ALLY_HOV_OK");
	if (label)
	{
		label->engine->killGroup("fadein");
		label->animate("A_ButtonHover_End_ALLY_HOV_OK");
	}
}

void CAlly::render()
{
	if (isHidden())
		return;

	engine->render();
	if (type == 1)
	{
		Pos mousePos;
		bool hovered;
		hovered = opW9_cec054->unknown805190(mousePos);
		if (hovered && opW9_cells(mousePos)->getEntity() == entity && (opW9_options == NULL || opW9_options->getUnknown58() != 11) && !opW9_cec054->unknown49aa60())
		{
			setBackAll_418410(XColor::addAlpha(opW9_d29804,*opW9_d30264,opW9_pulse(opW9_ba6ae0,0.35f,1000,0)));
			highlighted = true;
		}
		else if (highlighted)
		{
			clearBack();
			highlighted = false;
		}
	}
	XConsole::render();
}

void CAllySymbol::refresh()
{
	getParent()->refresh();
}

CAllies::CAllies(XConsole *parent)
	: Console(parent,opW9_alliesRect,0,true,3)
	, scroll		(-1)
	, upArrow		(NULL)
	, downArrow		(NULL)
	, unknown90		(false)
	, unknown91		(false)
	, unknownA4		(11)
	, unknownA8		(false)
	, unknownAc		(4)
{
	setTitle(new ConsoleTitle(this,"/ A L L I E S /",0,0));
	opened = false;
}

void CAllies::open()
{
	unknown60 = 1;
	setHidden(false);
	if (opW9_cebd5c == 2 && !opened)
	{
		clear();
		animate("A_4_Border");
		unknown60 = 3;
		opened = true;
	}
	if (opened)
	{
		clearInterior();
		animate("CAllies_Content");
	}
	else
	{
		clear();
		animate("CAllies_Border");
		opened = true;
	}
	setScaleX(1.0f);
	setScaleY(1.0f);
}

void CAllies::update()
{
	if (isHidden())
		return;

	switch (unknown60)
	{
		case 0:
			break;
		case 1:
			if (!engine->isRunning())
				unknown60 = 3;
			break;
		case 3:
			engine->isRunning();
			break;
		case 4:
			engine->isRunning();
			if (getScaleX() != 0)
			{
				if (opW9_tickCount - closeTime >= 500)
				{
					setScaleX(0);
					setScaleY(0);
				}
				else
				{
					setScaleX((float)(1 - (opW9_tickCount - closeTime) / 500.0));
					setScaleY((float)(1 - (opW9_tickCount - closeTime) / 500.0));
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			break;
	}
	XConsole::update();
}

void CAllies::close()
{
	unknown60 = 4;
	closeTime = opW9_tickCount;
	animate("A_BlockFadeInterior");
}

void CAllies::trigger(const string &command, int value)
{
	if (command == "show_allies")
		unknown7b7980();
}

void CAllies::scrollUp()
{
	if (!upArrow)
		return;
	scroll--;
	unknown7b7980();
}

void CAllies::scrollDown()
{
	if (!downArrow)
		return;
	scroll++;
	unknown7b7980();
}

void CAllies::scrollTop()
{
	if (!upArrow)
		return;
	scroll = -1;
	unknown7b7980();
}

void CAllies::scrollBottom()
{
	if (!downArrow)
		return;
	scroll = 9999;
	unknown7b7980();
}

int opW9_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
template <class T> bool opW9_contains(vector<T> &v, T value);	// NOTE: placeholder name (0x9db330)

void CAllies::unknown7b7980()
{
	if (isHidden())
		return;

	vector<HEntity> list;
	if (opW9_world->unknown715800(list) == 0)
	{
		if (upArrow)
		{
			removeSubconsole(upArrow);
			upArrow = NULL;
		}
		if (downArrow)
		{
			removeSubconsole(downArrow);
			downArrow = NULL;
		}
		for (unsigned int i = 0; i < allies.size(); i++)
		{
			if (allies[i])
				removeSubconsole(allies[i]);
		}
		allies.clear();
		return;
	}

	vector<CAlly*> newAllies;
	scroll = (scroll >= (int)list.size() - 6 ? opW9_maxInt(-1,list.size() - 6) : scroll);
	for (int i = scroll, y = 0; i < (int)list.size() && y < 6; i++, y++)
	{
		if (i == -1)
		{
			for (unsigned int k = 0; k < allies.size(); k++)
			{
				if (allies[k]->type == 0)
				{
					newAllies.push_back(allies[k]);
					goto foundA;
				}
			}
			newAllies.push_back(new CAlly(this,y + 2,y,HEntity(),0));
			newAllies.back()->unknown48eea0();
		foundA:;
		}
		else
		{
			for (unsigned int k = 0; k < allies.size(); k++)
			{
				if (allies[k]->type == 1 && allies[k]->entity == list[i])
				{
					newAllies.push_back(allies[k]);
					newAllies.back()->setPos(Pos(newAllies.back()->getPos().x,y + 2));
					newAllies.back()->setNumber(y);
					goto foundB;
				}
			}
			newAllies.push_back(new CAlly(this,y + 2,y,list[i],1));
			newAllies.back()->unknown48eea0();
		foundB:;
		}
	}

	for (int i = allies.size() - 1; i >= 0; i--)
	{
		if (!opW9_contains(newAllies,allies[i]))
			removeSubconsole(allies[i]);
	}
	allies = newAllies;

	if (scroll > -1)
	{
		if (upArrow == NULL || upArrow->entity != (scroll == 0 ? HEntity() : list[scroll - 1]))
		{
			if (upArrow && upArrow)
			{
				removeSubconsole(upArrow);
				upArrow = NULL;
			}
			upArrow = new CAlly(this,1,-1,scroll - 1 == -1 ? HEntity() : list[scroll - 1],3);
			upArrow->unknown48eea0();
		}
	}
	else if (upArrow && upArrow)
	{
		removeSubconsole(upArrow);
		upArrow = NULL;
	}

	if (scroll + 6 < list.size())
	{
		if (downArrow == NULL || downArrow->entity != list[scroll + 6])
		{
			if (downArrow && downArrow)
			{
				removeSubconsole(downArrow);
				downArrow = NULL;
			}
			downArrow = new CAlly(this,8,-1,list[scroll + 6],2);
			downArrow->unknown48eea0();
		}
	}
	else if (downArrow && downArrow)
	{
		removeSubconsole(downArrow);
		downArrow = NULL;
	}

	opW9_mouse->unknown41a8b0();
}

extern int opW9_d1e848;	// NOTE: placeholder name
extern bool opW9_d28e06;	// NOTE: placeholder name

void CAllies::beginOrder()
{
	if (!unknown90)
	{
		unknown90 = true;
		opW9_keyMap->registerConsole(11,this,0xe7,0);
		if (opW9_cebd5c == 2)
		{
			setPos(getPos().x,0);
			opW9_cec0d0->setHidden(true);
			opW9_cec0d0->unknown48e8b0();
			unknownAc = opW9_cec034->unknownB0;
		}
	}
}

void CAllies::endOrder()
{
	if (unknown90)
	{
		if (!opW9_cec11c->isHidden())
			opW9_cec11c->unknown8b5080();
		unknown90 = false;
		opW9_keyMap->unknown416640();
		if (opW9_cebd5c == 2)
		{
			setPos(getPos().x,opW9_d1e848);
			opW9_cec0d0->setHidden(false);
			opW9_cec0d0->unknown48e8b0();
			opW9_cec034->unknown987b10(unknownAc);
		}
	}
	unknown91 = false;
}

int opW9_unknown7b9750(int order, HEntity target, const Pos &pos);	// NOTE: placeholder name
void opW9_unknown7b9540(int order, vector<HEntity> &targets, const Pos &pos);	// NOTE: placeholder name
template <class T> bool opW9_erase(vector<T> &v, T e);	// NOTE: placeholder name (0x9d2f00)

class OpW9_Message	// NOTE: placeholder name (0x20 bytes, ctor 0x510d20)
{
public:
	OpW9_Message(int type, int a, int b, int c, HProp d, HProp e);
	int pad[8];
};
class OpW9_MessageLog2 : public XConsole	// NOTE: placeholder name (0xcec0f4)
{
public:
	void add(OpW9_Message *message);	// NOTE: placeholder name (0x7b1880)
};

void CAllies::unknown7b8340(const Pos &pos)
{
	int error = opW9_unknown7b9750(unknownA4,unknown94.size() == 1 ? unknown94.front() : HEntity(),pos);
	if (error == 0)
	{
		unknown91 = false;
		if (unknown94.size() > 1 && opW9_b96600[unknownA4] == 2)
			opW9_erase(unknown94,opW9_cells(pos)->getEntity());
		opW9_unknown7b9540(unknownA4,unknown94,pos);
		opW9_cec054->unknown827950();
		if (opW9_d28e06)
		{
			opW9_cec054->unknown49ac70();
			input(&XEvent(0x2f));
		}
	}
	else
		((OpW9_MessageLog2*)opW9_cec0f4)->add(new OpW9_Message(error + 0xb8,0,0,0,HProp(),HProp()));
}

void CAllies::unknown7b8500(HEntity entity)
{
	for (unsigned int i = 0; i < allies.size(); i++)
	{
		if (allies[i]->entity == entity)
		{
			allies[i]->unknown48eab0();
			allies[i]->unknown48eea0();
			break;
		}
	}
}

template <class T> void opW9_eraseAt(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440)
string opW9_unknown407a80(int count, const string &text);	// NOTE: placeholder name
void opW9_showWarning(int type, const string &text, int a, int b, HEntity entity, HProp prop, int c);	// NOTE: placeholder name (0x7b1750)

bool CAllies::input(XEvent *event)
{
	if (isHidden() || opW9_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opW9_world2->unknown71bbd0())
		return false;

	switch (event->type)
	{
		case 0xd4:
			if (unknownA8)
			{
				unknownA8 = false;
				return false;
			}
			if (opW9_cec054->operate())
				return false;
			scrollDown();
			return true;
		case 0xd5:
			if (unknownA8)
			{
				unknownA8 = false;
				return false;
			}
			if (opW9_cec054->operate())
				return false;
			scrollUp();
			return true;
		case 0xd6:
			scrollBottom();
			return true;
		case 0xd7:
			scrollTop();
			return true;
		case 0xda:
		case 0xdb:
		case 0xdc:
		case 0xdd:
		case 0xde:
		case 0xdf:
			if ((unknown90 || unknown91) && allies.size() > event->type - 0xda)
			{
				if (unknown90)
					opW9_unknown7b8bc0(allies[event->type - 0xda]->entity,1);
				else if (opW9_b96600[unknownA4] == 2 && allies[event->type - 0xda]->entity.isValid())
					unknown7b8340(allies[event->type - 0xda]->entity->getPosition());
			}
			return true;
		case 0xe0:
		case 0xe1:
		case 0xe2:
		case 0xe3:
		case 0xe4:
		case 0xe5:
			if ((unknown90 || unknown91) && allies.size() > event->type - 0xe0 && allies[event->type - 0xe0]->entity.isValid())
				((OpW9_Info*)opW9_cec11c)->unknown8b4500(allies[event->type - 0xe0]->entity,HProp(),HProp(),OpW9_Pair(-1),0,0);
			return true;
		case 0xe6:
			if (unknown90 && !unknown91)
			{
				vector<HEntity> list;
				if (opW9_world->unknown715800(list))
				{
					for (unsigned int i = 0; i < list.size(); i++)
					{
						if (list[i]->getFaction() != 8)
							opW9_eraseAt(list,i);
					}
					if (list.empty())
						((OpW9_MessageLog2*)opW9_cec0f4)->add(new OpW9_Message(0xbf,0,0,0,HProp(),HProp()));
					else
					{
						unknown94 = list;
						opW9_unknown7b9540(4,unknown94,opW9_world->getPlayer()->getPosition());
						string text = opW9_unknown407a80(unknown94.size(),"allied Mechanic");
						opW9_showWarning(0xc0,text,0,0,HEntity(),HProp(),0);
					}
					if (!opW9_cec11c->isHidden())
						opW9_cec11c->unknown8b5080();
					endOrder();
				}
			}
			return true;
		case 0xd8:
		case 0xe7:
			if (unknown90 || unknown91)
			{
				if (!opW9_cec11c->isHidden())
					((Console*)opW9_cec11c)->close();
				else
					endOrder();
			}
			return true;
	}
	return false;
}

extern CList *opW9_activeList;	// NOTE: placeholder name (0xcec130)
extern string opW9_orderNames[];	// NOTE: placeholder name (0xd2ed90)
extern const bool opW9_orderAllowed[][10];	// NOTE: placeholder name (0xb96630)
extern int opW9_caf128;	// NOTE: placeholder name
extern int opW9_caf164;	// NOTE: placeholder name
extern int opW9_cf27ec;	// NOTE: placeholder name
extern int opW9_cf27f0;	// NOTE: placeholder name
extern int opW9_cf27f4;	// NOTE: placeholder name
extern int opW9_cf27f8;	// NOTE: placeholder name
void opW9_orderListCallback(int id, const string &option);	// NOTE: placeholder name (0x7b9340)

void opW9_unknown7b8bc0(HEntity entity, bool value)
{
	if (opW9_activeList)
	{
		opW9_activeList->unknown7b2870();
		opW9_allies->unknown48f2d0();
	}
	opW9_allies->endOrder();
	if (entity.isValid() && entity->getAI()->unknown458eb0())
	{
		((OpW9_MessageLog2*)opW9_cec0f4)->add(new OpW9_Message(0xb6,0,0,0,HProp(),HProp()));
		return;
	}

	Pos pos(-1);
	if (entity.isValid())
	{
		if (!opW9_cec054->inBounds(entity->getPosition() + opW9_cec054->getOffset()))
			opW9_cec054->unknown8069e0(entity->getPosition(),0);
		if (value)
		{
			int titleWidth = string(" \\ C O M M A N D S \\  ").size();
			int height = 15;
			pos = entity->getPosition() + opW9_cec054->getOffset();
			pos.x *= opW9_caf128;
			pos.x += 1;
			pos.x += entity->getSize() * opW9_caf128;
			pos.x += opW9_cf27ec;
			pos.y *= opW9_caf12c;
			pos.y += opW9_cf27f0;
			if (pos.x + titleWidth >= opW9_cf27f4 * opW9_caf128 + opW9_cf27ec)
				pos.x = (entity->getPosition().x + opW9_cec054->getOffset().x) * opW9_caf128 - titleWidth;
			if (pos.y + height >= opW9_cf27f8 * opW9_caf12c + opW9_cf27f0)
				pos.y -= pos.y + height - (opW9_cf27f8 * opW9_caf12c + opW9_cf27f0);
		}
	}

	vector<string> options;
	for (int i = 0; i < 11; i++)
		options.push_back(opW9_orderNames[i]);
	vector<bool> *enabled = new vector<bool>;
	enabled->assign(11,true);
	vector<HEntity> *targets = opW9_allies->getUnknown94();
	targets->clear();
	if (entity.isValid())
	{
		targets->push_back(entity);
		int faction = entity->getFaction();
		for (int i = 0; i < 10; i++)
		{
			if (!opW9_orderAllowed[faction][i])
				enabled->at(i) = false;
		}
		enabled->at(10) = entity->getData()->unknown158 != opW9_caf164;
	}
	else
	{
		opW9_world->unknown715800(*targets);
		for (unsigned int i = 0; i < targets->size(); i++)
		{
			if ((*targets)[i]->getAI()->unknown458eb0())
				opW9_eraseAt(*targets,i);
		}
		if (targets->empty())
		{
			((OpW9_MessageLog2*)opW9_cec0f4)->add(new OpW9_Message(0xb7,0,0,0,HProp(),HProp()));
			return;
		}
		for (int i = 0; i < 10; i++)
		{
			for (unsigned int j = 0; j < targets->size(); j++)
			{
				if (opW9_orderAllowed[(*targets)[j]->getFaction()][i])
					goto nextOrder;
			}
			enabled->at(i) = false;
		nextOrder:;
		}
		for (unsigned int i = 0; i < targets->size(); i++)
		{
			if ((*targets)[i]->getData()->unknown158 != opW9_caf164)
				goto done;
		}
		enabled->at(10) = false;
	done:;
	}
	new CList((XConsole*)opW9_cec034,pos.x == -1 ? Pos(opW9_allies->getPos().x,opW9_allies->getPos().y + opW9_allies->getHeight()) : pos,"\\ C O M M A N D S \\",11,options,0x1a,0,opW9_orderListCallback,0,0x16,true,false,enabled,NULL,NULL,false);
}

int opW9_findString(string *strings, int count, string text);	// NOTE: placeholder name (0x9cda80)

void opW9_orderListCallback(int id, const string &option)
{
	if (option.empty())
	{
		opW9_activeList->close();
		opW9_allies->unknown48f2d0();
		return;
	}

	int index = opW9_findString(opW9_orderNames,11,option);
	int order = index;
	opW9_allies->setUnknownA4(order);
	vector<HEntity> *entities = opW9_allies->getUnknown94();
	for (unsigned int i = 0; i < entities->size(); i++)
	{
		if (order < 10)
		{
			if (!opW9_orderAllowed[(*entities)[i]->getFaction()][order])
				opW9_eraseAt(*entities,i);
		}
		else if ((*entities)[i]->getData()->unknown158 == opW9_caf164)
			opW9_eraseAt(*entities,i);
	}

	if (opW9_b96600[order])
	{
		opW9_activeList->unknown7b2870();
		if (opW9_b96600[order] == 2)
			opW9_allies->unknown48f2f0();
		opW9_cec054->unknown8279c0(entities->front()->unknown45a4c0());
		if (opW9_mouse->unknown41a6e0())
			opW9_cec054->unknown806e70(entities->front()->unknown45a4c0(),0);
	}
	else
	{
		opW9_activeList->close();
		opW9_unknown7b9540(order,*entities,Pos(-1));
	}
}

class OpW9_Order	// NOTE: placeholder name (0x1c bytes, PropPoints458bd0)
{
public:
	OpW9_Order(int type, HEntity target, const Pos &pos);
	int pad[7];
};

class OpW9_Strings	// NOTE: placeholder name (0xd2c658)
{
public:
	void unknown4729d0(int id, int value, string text, int flag);	// NOTE: placeholder name
};
extern OpW9_Strings opW9_d2c658;	// NOTE: placeholder name
void opW9_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)

void opW9_unknown7b9540(int order, vector<HEntity> &targets, const Pos &pos)
{
	if (pos.x != -1)
		opW9_playSound(0x2b,0,0);

	HEntity targetEntity;
	Pos targetPos(pos);
	switch (order)
	{
		case 0: break;
		case 1: break;
		case 2:
			targetEntity = opW9_world->getPlayer();
			break;
		case 3:
			targetEntity = opW9_cells(pos)->getEntity();
			break;
		case 4:
			targetEntity = opW9_cells(pos)->getEntity();
			break;
		case 5: break;
		case 6: break;
		case 7: break;
		case 8: break;
		case 9: break;
		case 10:
			targetEntity = opW9_world->getPlayer();
			break;
	}
	for (unsigned int i = 0; i < targets.size(); i++)
		targets[i]->getAI()->unknown5b5380(new OpW9_Order(order,targetEntity,pos));
	opW9_d2c658.unknown4729d0(0x3a2,1,"",-1);
	opW9_d2c658.unknown4729d0(order + 0x3a3,1,"",-1);
}

int opW9_unknown7b9750(int order, HEntity target, const Pos &pos)
{
	switch (opW9_b96600[order])
	{
		case 0:
			return 0;
		case 1:
			if (!opW9_world->unknown463160(pos))
				return 1;
			if (order != 5 && !opW9_cells(pos)->unknown4550b0() && !opW9_cells(pos)->unknown45db70())
				return 2;
			return 0;
		case 2:
			if (!opW9_world->unknown463160(pos))
				return 1;
			if (opW9_cells(pos)->getEntity().isNull())
				return 3;
			else
			{
				HEntity entity = opW9_cells(pos)->getEntity();
				if (!entity->unknown45aaa0(opW9_world->getPlayer()))
					return 4;
				if (entity->getTarget())
					return 5;
				if (entity == target)
					return 6;
			}
			return 0;
	}
	return 0;
}

//==================================================================
// CIntel
//==================================================================

void opW9_fillInt(int *values, unsigned int count, int value);	// NOTE: placeholder name (0x9e2be0)
void opW9_fillBool(bool *values, unsigned int count, bool value);	// NOTE: placeholder name (0x9cdcc0)
extern Rect opW9_intelRect;	// NOTE: placeholder name (0xd1e844)

class CIntelLine : public Console
{
public:
	CIntelLine(XConsole *parent, int y, int number_, int category_, int type_);	// 0x48f420

	virtual bool input(XEvent *event);
	virtual void update();

	void setNumber(int number_);	// NOTE: placeholder name (folded setter)
	void unknown7b9ab0();	// NOTE: placeholder name
	void unknown48f550();	// NOTE: placeholder name

	int category;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	int number;	// NOTE: placeholder name
	unsigned int count;	// NOTE: placeholder name
	Console *label;	// NOTE: placeholder name
};

class CIntel : public Console
{
public:
	CIntel(XConsole *parent);
	virtual ~CIntel() {}

	virtual bool input(XEvent *event);
	virtual void update();
	virtual void open();
	virtual void close();
	virtual void trigger(const string &command, int value);

	void unknown7ba190();	// NOTE: placeholder name
	void scrollUp();	// NOTE: placeholder name
	void scrollDown();	// NOTE: placeholder name
	void scrollTop();	// NOTE: placeholder name
	void scrollBottom();	// NOTE: placeholder name
	void beginSelect();	// NOTE: placeholder name
	void endSelect();	// NOTE: placeholder name
	void unknown48f9e0(int category);	// NOTE: placeholder name
	void unknown48fa80();	// NOTE: placeholder name
	bool getSelecting();	// NOTE: placeholder name (folded getter 0x48f8b0)
	bool unknown48f8d0(int category);	// NOTE: placeholder name

	bool opened;	// NOTE: placeholder name
	unsigned int closeTime;	// NOTE: placeholder name
	vector<CIntelLine*> lines;	// NOTE: placeholder name
	int filters[20];	// NOTE: placeholder name
	int scroll;	// NOTE: placeholder name
	CIntelLine *upArrow;	// NOTE: placeholder name
	CIntelLine *downArrow;	// NOTE: placeholder name
	bool selecting;	// NOTE: placeholder name
	bool unknownE1[20];	// NOTE: placeholder name
	bool unknownF5;	// NOTE: placeholder name
	int unknownF8;	// NOTE: placeholder name
};

CIntel::CIntel(XConsole *parent)
	: Console(parent,opW9_intelRect,0,true,3)
	, scroll	(-1)
	, upArrow	(NULL)
	, downArrow	(NULL)
	, selecting	(false)
	, unknownF5	(false)
	, unknownF8	(4)
{
	setTitle(new ConsoleTitle(this,"/ I N T E L /",0,0));
	opened = false;
	opW9_fillInt(filters,20,1);
	opW9_fillBool(unknownE1,20,true);
}

void CIntel::open()
{
	unknown60 = 1;
	setHidden(false);
	if (opW9_cebd5c == 2 && !opened)
	{
		clear();
		animate("A_4_Border");
		unknown60 = 3;
		opened = true;
	}
	if (opened)
	{
		clearInterior();
		animate("CIntel_Content");
	}
	else
	{
		clear();
		animate("CIntel_Border");
		opened = true;
	}
	setScaleX(1.0f);
	setScaleY(1.0f);
}

void CIntel::update()
{
	if (isHidden())
		return;

	switch (unknown60)
	{
		case 0:
			break;
		case 1:
			if (!engine->isRunning())
				unknown60 = 3;
			break;
		case 3:
			engine->isRunning();
			break;
		case 4:
			engine->isRunning();
			if (getScaleX() != 0)
			{
				if (opW9_tickCount - closeTime >= 500)
				{
					setScaleX(0);
					setScaleY(0);
				}
				else
				{
					setScaleX((float)(1 - (opW9_tickCount - closeTime) / 500.0));
					setScaleY((float)(1 - (opW9_tickCount - closeTime) / 500.0));
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			break;
	}
	unknown7ba190();
	XConsole::update();
}

void CIntel::close()
{
	unknown60 = 4;
	closeTime = opW9_tickCount;
	animate("A_BlockFadeInterior");
}

void CIntel::trigger(const string &command, int value)
{
	if (command == "show_intel")
		unknown7ba190();
}

void CIntel::scrollUp()
{
	if (!upArrow)
		return;
	scroll--;
	unknown7ba190();
}

void CIntel::scrollDown()
{
	if (!downArrow)
		return;
	scroll++;
	unknown7ba190();
}

void CIntel::scrollTop()
{
	if (!upArrow)
		return;
	scroll = -1;
	unknown7ba190();
}

void CIntel::scrollBottom()
{
	if (!downArrow)
		return;
	scroll = 9999;
	unknown7ba190();
}

void CIntel::beginSelect()
{
	if (!selecting)
	{
		selecting = true;
		opW9_keyMap->registerConsole(11,this,0xe7,0);
		if (opW9_cebd5c == 2)
		{
			setPos(getPos().x,0);
			opW9_cec0d0->setHidden(true);
			opW9_cec0d0->unknown48e8b0();
			unknownF8 = opW9_cec034->unknownB0;
		}
	}
}

void CIntel::endSelect()
{
	if (selecting)
	{
		if (!opW9_cec11c->isHidden())
			opW9_cec11c->unknown8b5080();
		selecting = false;
		opW9_keyMap->unknown416640();
		if (opW9_cebd5c == 2)
		{
			setPos(getPos().x,opW9_d1e848);
			opW9_cec0d0->setHidden(false);
			opW9_cec0d0->unknown48e8b0();
			opW9_cec034->unknown987b10(unknownF8);
		}
	}
}

bool CIntel::input(XEvent *event)
{
	if (isHidden() || opW9_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opW9_world2->unknown71bbd0())
		return false;

	switch (event->type)
	{
		case 0xd4:
			if (unknownF5)
			{
				unknownF5 = false;
				return false;
			}
			scrollDown();
			return true;
		case 0xd5:
			if (unknownF5)
			{
				unknownF5 = false;
				return false;
			}
			scrollUp();
			return true;
		case 0xd6:
			scrollBottom();
			return true;
		case 0xd7:
			scrollTop();
			return true;
		case 0xda:
		case 0xdb:
		case 0xdc:
		case 0xdd:
		case 0xde:
		case 0xdf:
			if (selecting && lines.size() > event->type - 0xda)
				((Console*)lines[event->type - 0xda])->input(&XEvent(0xd8));
			return true;
		case 0xe0:
		case 0xe1:
		case 0xe2:
		case 0xe3:
		case 0xe4:
		case 0xe5:
		case 0xe6:
			return true;
		case 0xd8:
		case 0xe7:
			endSelect();
			return true;
	}
	return false;
}

extern CIntel *opW9_intel;	// NOTE: placeholder name (0xcec0cc)

bool CIntelLine::input(XEvent *event)
{
	if (opW9_world2->unknown71bbd0())
		return false;

	switch (event->type)
	{
		case 0xd8:
			switch (type)
			{
				case 0:
					opW9_intel->unknown48fa80();
					break;
				case 1:
					opW9_intel->unknown48f9e0(category);
					break;
				case 2:
					opW9_intel->scrollDown();
					break;
				case 3:
					opW9_intel->scrollUp();
					break;
			}
			return true;
	}
	return false;
}

void CIntel::unknown7ba190()
{
	vector<vector<HEntity> > *categories = opW9_world->unknown463ec0();
	vector<unsigned int> ids;
	ids.push_back(0);
	for (int i = 1; i < categories->size(); i++)
	{
		if (!(*categories)[i].empty())
			ids.push_back(i);
	}

	vector<CIntelLine*> newList;
	scroll = (scroll >= (int)ids.size() - 6 ? opW9_maxInt(-1,ids.size() - 6) : scroll);
	for (int i = scroll, y = 0; i < (int)ids.size() && y < 6; i++, y++)
	{
		if (i == -1)
		{
			for (unsigned int k = 0; k < lines.size(); k++)
			{
				if (lines[k]->type == 0)
				{
					newList.push_back(lines[k]);
					goto foundA;
				}
			}
			newList.push_back(new CIntelLine(this,y + 2,y,20,0));
			newList.back()->unknown7b9ab0();
		foundA:;
		}
		else
		{
			for (unsigned int k = 0; k < lines.size(); k++)
			{
				if (lines[k]->type == 1 && lines[k]->category == ids[i])
				{
					newList.push_back(lines[k]);
					newList.back()->setPos(Pos(newList.back()->getPos().x,y + 2));
					newList.back()->setNumber(y);
					if (filters[ids[i]] == -1)
						unknown48f9e0(ids[i]);
					goto foundB;
				}
			}
			filters[ids[i]] = filters[ids[i]] != 0;
			unknownE1[ids[i]] = true;
			newList.push_back(new CIntelLine(this,y + 2,y,ids[i],1));
			newList.back()->unknown7b9ab0();
		foundB:;
		}
	}

	for (int i = lines.size() - 1; i >= 0; i--)
	{
		if (!opW9_contains(newList,lines[i]))
			removeSubconsole(lines[i]);
	}
	lines = newList;

	if (scroll > -1)
	{
		if (upArrow == NULL || upArrow->category != (scroll == 0 ? 20 : ids[scroll - 1]))
		{
			if (upArrow && upArrow)
			{
				removeSubconsole(upArrow);
				upArrow = NULL;
			}
			upArrow = new CIntelLine(this,1,-1,scroll - 1 == -1 ? 20 : ids[scroll - 1],3);
			upArrow->unknown7b9ab0();
		}
	}
	else if (upArrow && upArrow)
	{
		removeSubconsole(upArrow);
		upArrow = NULL;
	}

	if (scroll + 6 < ids.size())
	{
		if (downArrow == NULL || downArrow->category != ids[scroll + 6])
		{
			if (downArrow && downArrow)
			{
				removeSubconsole(downArrow);
				downArrow = NULL;
			}
			downArrow = new CIntelLine(this,8,-1,ids[scroll + 6],2);
			downArrow->unknown7b9ab0();
		}
	}
	else if (downArrow && downArrow)
	{
		removeSubconsole(downArrow);
		downArrow = NULL;
	}

	opW9_mouse->unknown41a8b0();
}

extern string opW9_intelNames[];	// NOTE: placeholder name (0xd2eec8)

void CIntelLine::update()
{
	if (isHidden())
		return;

	engine->isRunning();
	if (type < 2)
	{
		if (opW9_intel->getSelecting())
		{
			print(1,0,intToString(number));
			setFore_417f80(1,0,*opW9_d20b70);
		}
		else
			setChar_417f50(1,0,' ');
	}
	if (type == 1 && (*opW9_world->unknown463ec0())[category].size() != count)
	{
		unknown48f550();
		unknown7b9ab0();
	}
	XConsole::update();
}

void CIntelLine::unknown7b9ab0()
{
	animate(type >= 2 ? "A_CIntel_Button" : (type != 0 && !opW9_intel->unknown48f8d0(category) ? "A_CIntel_Inactive" : "A_CIntel_Active"));
	if (label)
		label->animate(opW9_intel->unknown48f8d0(category) ? "A_CIntel_Symbol_" + opW9_intelNames[category] : "A_CIntel_Symbol_Fade_" + opW9_intelNames[category]);
}

//==================================================================
// Console (out-of-line members)
//==================================================================

void Console::animate(string name, int unknown1, int unknown2)
{
	int index;
	if (!opW9_findAnimation(name,&index))
		return;
	unknown7ad6a0(index,unknown1,unknown2,0,0);
}

Pos Console::getAnchor(int anchor)
{
	switch (anchor)
	{
		case '0': return Pos(0,0);
		case '1': return Pos(getWidth() - 1,0);
		case '2': return Pos(0,getHeight() - 1);
		case '3': return Pos(getWidth() - 1,getHeight() - 1);
		case '4': return Pos(getWidth() / 2,getHeight() / 2);
		case '5': return Pos(title->getPos(),-1,0);
		case '6': return Pos(title->getPos(),title->getWidth() * (title->isWide() ? 2 : 1) / (isWide() ? 2 : 1),0);
		case '7':
		case '8': return Pos(getWidth() / 2,0);
		case '9': return Pos(getWidth() / 2 + 1,0);
		case ':':
		case ';': return Pos(getWidth() / 2,getHeight() - 1);
		case '<': return Pos(getWidth() / 2 + 1,getHeight() - 1);
		case '=':
		case '>': return Pos(0,getHeight() / 2);
		case '?': return Pos(0,getHeight() / 2 + 1);
		case '@':
		case 'A': return Pos(getWidth() - 1,getHeight() / 2);
		case 'B': return Pos(getWidth() - 1,getHeight() / 2 + 1);
		case 'C': return Pos(rng.rangeInt(0,getWidth() - 1),rng.rangeInt(0,getHeight() - 1));
		case 'D': return Pos(rng.rangeInt(1,getWidth() - 2),rng.rangeInt(1,getHeight() - 2));
	}
	return Pos(0,0);
}

void Console::drawFrame(Rect *area, XColor color, bool thin, bool lines)
{
	Rect rect;
	if (area)
		rect = *area;
	else
		rect.set(0,0,getWidth(),getHeight());

	if (lines)
	{
		putChar_418110(rect.x,rect.y,thin ? 0xda : 0xc9,color);
		putChar_418110(rect.x + rect.width - 1,rect.y,thin ? 0xbf : 0xbb,color);
		putChar_418110(rect.x + rect.width - 1,rect.y + rect.height - 1,thin ? 0xd9 : 0xbc,color);
		putChar_418110(rect.x,rect.y + rect.height - 1,thin ? 0xc0 : 0xc8,color);
		setCharRow(rect.x + 1,rect.y,rect.width - 2,thin ? 0xc4 : 0xcd,color);
		setCharRow(rect.x + 1,rect.y + rect.height - 1,rect.width - 2,thin ? 0xc4 : 0xcd,color);
		setCharColumn(rect.x,rect.y + 1,rect.height - 2,thin ? 0xb3 : 0xba,color);
		setCharColumn(rect.x + rect.width - 1,rect.y + 1,rect.height - 2,thin ? 0xb3 : 0xba,color);
	}
	else
	{
		putChar_418110(rect.x,rect.y,thin ? 0x88 : 0x94,color);
		putChar_418110(rect.x + rect.width - 1,rect.y,thin ? 0x89 : 0x95,color);
		putChar_418110(rect.x + rect.width - 1,rect.y + rect.height - 1,thin ? 0x8a : 0x96,color);
		putChar_418110(rect.x,rect.y + rect.height - 1,thin ? 0x87 : 0x93,color);
		setCharRow(rect.x + 1,rect.y,rect.width - 2,thin ? 0x81 : 0x8d,color);
		setCharRow(rect.x + 1,rect.y + rect.height - 1,rect.width - 2,thin ? 0x81 : 0x8d,color);
		setCharColumn(rect.x,rect.y + 1,rect.height - 2,thin ? 0x80 : 0x8c,color);
		setCharColumn(rect.x + rect.width - 1,rect.y + 1,rect.height - 2,thin ? 0x80 : 0x8c,color);
	}
}

void Console::setFrameFore(XColor color)
{
	setForeFrame(0,0,getWidth(),getHeight(),color);
}

void Console::replaceSpecialChars(int ch)
{
	for (int x = 0; x < getWidth(); x++)
	{
		for (int y = 0; y < getHeight(); y++)
		{
			if (getChar(x,y) >= 0xe3)
			{
				setChar_417f50(x,y,ch);
				getCell_4176e0(x,y,0)->unknown4280e0();
			}
		}
	}
}

//==================================================================
// CCloseButton / CInterfaceMsg
//==================================================================

class OpW9_KeyMap2	// NOTE: placeholder name (0xcefa8c)
{
public:
	bool hasCommand(int command);	// NOTE: placeholder name (0x416200)
};

class OpW9_ItemTag	// NOTE: placeholder name (CItemTag at 0xcec0a0)
{
public:
	bool isOpen_4ab690();	// NOTE: placeholder name (folded getter)
	void close_8ac1f0();	// NOTE: placeholder name (CItemTag::close)
};
extern OpW9_ItemTag *opW9_itemTag;	// NOTE: placeholder name (0xcec0a0)
extern Console *opW9_cec104;	// NOTE: placeholder name

class CTextButton : public Console
{
public:
	string text;
};

class CCloseButton : public CTextButton
{
public:
	virtual bool input(XEvent *event);

	int command;
};

bool CCloseButton::input(XEvent *event)
{
	if (!((OpW9_KeyMap2*)opW9_keyMap)->hasCommand(command))
		return false;

	switch (event->type)
	{
		case 5:
		{
			if (opW9_cec104)
				opW9_cec104->close();
			if (opW9_itemTag->isOpen_4ab690())
				opW9_itemTag->close_8ac1f0();
			((Console*)getParent())->close();
			return true;
		}
	}
	return false;
}

struct OpW9_MsgStyle	// NOTE: placeholder name
{
	char pad00[0x20];
	int unknown20;	// NOTE: placeholder name
	int unknown24;	// NOTE: placeholder name
};
struct OpW9_MsgSource	// NOTE: placeholder name
{
	char pad00[0x24];
	OpW9_MsgStyle *style;	// NOTE: placeholder name
};
extern OpW9_MsgStyle *opW9_defaultMsgStyle;	// NOTE: placeholder name (0xcefbc8)

struct OpW9_InterfaceMessage	// NOTE: placeholder name (0x20 bytes, ctor 0x510d20)
{
	OpW9_InterfaceMessage(int type, int a, int b, int c, HEntity d, HProp e);

	OpW9_MsgSource *source;	// NOTE: placeholder name
	string text;	// NOTE: placeholder name
};

class OpW9_KeyHelper	// NOTE: placeholder name (0xcefa90)
{
public:
	void unknown41a210(int index);	// NOTE: placeholder name
};
extern OpW9_KeyHelper *opW9_keyHelper;	// NOTE: placeholder name

class CInterfaceMsg : public Console
{
public:
	virtual void update();
	virtual void close();

	void add(OpW9_InterfaceMessage *message);	// NOTE: placeholder name
	void hide();	// NOTE: placeholder name

	unsigned int closeTime;	// NOTE: placeholder name
	vector<OpW9_InterfaceMessage*> messages;
	int current;	// NOTE: placeholder name
	bool unknown84;	// NOTE: placeholder name
	unsigned int openTime;	// NOTE: placeholder name
};
extern CInterfaceMsg *opW9_interfaceMsg;	// NOTE: placeholder name (0xcec0f4)

struct OpW9_MapRecord	// NOTE: placeholder name
{
	char pad00[0x20];
	int unknown20;	// NOTE: placeholder name
};
extern vector<OpW9_MapRecord*> opW9_messageTypes;	// NOTE: placeholder name (0xd01c04)

class OpW9_World3	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer() throw();	// 0x4630f0
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	bool isVisible(HProp p);	// NOTE: placeholder name (BS::isVisible)
};

void opW9_unknown7b1750(int type, int a, int b, int c, HEntity d, HProp e, HProp f)	// NOTE: placeholder name
{
	switch (opW9_messageTypes[type]->unknown20)
	{
		case 0:
			break;
		case 1:
			if (d != ((OpW9_World3*)opW9_world)->getPlayer())
				return;
			else
				break;
		case 2:
			if (!((OpW9_World3*)opW9_world)->unknown4631f0(d))
				return;
			else
				break;
		case 3:
			if (!((OpW9_World3*)opW9_world)->isVisible(f))
				return;
			break;
	}
	opW9_interfaceMsg->add(new OpW9_InterfaceMessage(type,a,b,c,d,e));
}

void CInterfaceMsg::add(OpW9_InterfaceMessage *message)
{
	if (message == NULL)
	{
		if (current == -1)
			current = messages.size();
		current--;
		unknown84 = false;
		if (current == -1)
			return;
	}
	else
	{
		messages.push_back(message);
		while (messages.size() >= 10)
			removeVectorElement(messages,0);
		current = messages.size() - 1;
		unknown84 = true;
	}

	unknown60 = 1;
	setHidden(false);
	openTime = opW9_tickCount;
	clear();
	engine->stopAll();
	setTitle(new ConsoleTitle(this,messages[current]->text,0,0));
	((Console*)title)->unknown48c3c0(messages[current]->source ? messages[current]->source->style->unknown20 : opW9_defaultMsgStyle->unknown20);
	setScaleX(1);
	setScaleY(1);
}

void CInterfaceMsg::update()
{
	if (isHidden())
		return;

	switch (unknown60)
	{
		case 0:
			break;
		case 1:
			if (!engine->isRunning())
				unknown60 = 3;
			break;
		case 3:
			if (opW9_tickCount >= openTime + 3000)
				close();
			break;
		case 4:
			engine->isRunning();
			if (getScaleX() != 0)
			{
				if (opW9_tickCount - closeTime >= 500)
				{
					setScaleX(0);
					setScaleY(0);
				}
				else
				{
					setScaleX((float)(1 - (opW9_tickCount - closeTime) / 500.0));
					setScaleY((float)(1 - (opW9_tickCount - closeTime) / 500.0));
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			break;
	}
	XConsole::update();
}

void CInterfaceMsg::close()
{
	unknown60 = 4;
	closeTime = opW9_tickCount;
	unknown48c3c0(messages[current]->source ? messages[current]->source->style->unknown24 : opW9_defaultMsgStyle->unknown24);
	current = -1;
	unknown84 = false;
	opW9_keyHelper->unknown41a210(0xf);
}

void CInterfaceMsg::hide()
{
	unknown60 = 4;
	engine->stopAll();
	if (title)
		((Console*)title)->engine->stopAll();
	setHidden(true);
	closeTime = opW9_tickCount;
	current = -1;
	unknown84 = false;
}

extern XColor *opW9_d25e0c;	// NOTE: placeholder name
extern XColor *opW9_cf6b24;	// NOTE: placeholder name

void CMulticonsoleButton::draw()
{
	clear();
	putChar_418110(0,0,opW9_modeChars[mode],opW9_consoleMode == mode ? *opW9_d25e0c : *opW9_cf6b24);
}

//==================================================================
// CTextInput / CTemp
//==================================================================

class OpW9_Clipboard	// NOTE: placeholder name (0xcefa98)
{
public:
	bool getText(string &text);	// NOTE: placeholder name (0x41ae40)
};
extern OpW9_Clipboard *opW9_clipboard;	// NOTE: placeholder name
extern bool opW9_ctrlHeld;	// NOTE: placeholder name (0xcec14d)
extern const int opW9_invalidFileChars[];	// NOTE: placeholder name (0xcaecf8)
bool opW9_between(int lo, int v, int hi);	// NOTE: placeholder name (0x9daf80)
bool opW9_inArray(const int *a, unsigned int n, int e);	// NOTE: placeholder name (0x9d43b0)

class CTextInput : public Console
{
public:
	virtual void inputAscii(int key, int type);

	string text;
	int cursor;
	bool unknown8c;	// NOTE: placeholder name
	int maxLength;	// NOTE: placeholder name
	bool numeric;	// NOTE: placeholder name
	bool skipNext;	// NOTE: placeholder name
	vector<int> blockedKeys;	// NOTE: placeholder name
	bool uppercase;	// NOTE: placeholder name
	bool trimLeading;	// NOTE: placeholder name
	bool unknownAa;	// NOTE: placeholder name
	void (*doneCallback)(int cancelled);	// NOTE: placeholder name
	int result;	// NOTE: placeholder name
	void (*historyCallback)(bool down);	// NOTE: placeholder name
	void (*typeCallback)();	// NOTE: placeholder name
	void (*matchCallback)();	// NOTE: placeholder name
	string matchText;	// NOTE: placeholder name
	bool (*specialCallback)(int key);	// NOTE: placeholder name
	void (*keyHook)(int key, int type);	// NOTE: placeholder name
};

void CTextInput::inputAscii(int key, int type)
{
	if (skipNext)
	{
		skipNext = false;
		return;
	}
	if (keyHook)
		keyHook(key,type);

	switch (type)
	{
		case 3:
			if (unknown8c)
				break;
		case 0:
		case 1:
		case 2:
		case 4:
			if (key == '`')
				break;
			if (numeric && type != 2)
				break;
			if (maxLength && text.size() == maxLength)
				break;
			if (opW9_ctrlHeld)
			{
				if (key == 'v')
				{
					string clip;
					if (opW9_clipboard->getText(clip))
					{
						for (int i = 0; i < clip.size(); i++)
						{
							if (!opW9_between(' ',clip[i],'z') || clip[i] == '`')
							{
								clip.erase(clip.begin() + i);
								i--;
							}
						}
						if (maxLength && clip.size() > maxLength)
							clip.erase(clip.begin() + maxLength,clip.end());
						if (numeric)
						{
							for (int j = 0; j < clip.size(); j++)
							{
								if (!opW9_between('0',clip[j],'9'))
								{
									clip.erase(clip.begin() + j);
									j--;
								}
							}
						}
						if (unknown8c)
						{
							for (int k = 0; k < clip.size(); k++)
							{
								if (opW9_inArray(opW9_invalidFileChars,10,clip[k]))
								{
									clip.erase(clip.begin() + k);
									k--;
								}
							}
						}
						text += clip;
						cursor = text.size();
					}
				}
				break;
			}
			if (opW9_contains(blockedKeys,key))
				break;
			if (uppercase && type == 0)
				key -= 0x20;
			text.insert(text.begin() + cursor,(char)key);
			if (key != ' ' && typeCallback)
				typeCallback();
			if (key == ' ' && specialCallback && specialCallback(0))
				break;
			cursor++;
			if (matchCallback && text == matchText)
				matchCallback();
			break;
		case 5:
			switch (key)
			{
				case 8:
					if (cursor > 0)
					{
						if (opW9_ctrlHeld)
						{
							if (unknownAa)
							{
								unsigned int bracket = text.find('(',0);
								if (bracket != string::npos && bracket < text.size() - 1)
								{
									text.erase(text.begin() + bracket + 1,text.end());
									cursor = text.size();
									break;
								}
							}
							text.erase(text.begin(),text.begin() + cursor);
							cursor = 0;
						}
						else
						{
							text.erase(text.begin() + cursor - 1);
							cursor--;
						}
					}
					break;
				case 13:
					if (trimLeading)
					{
						while (!text.empty() && text[0] == ' ')
							text.erase(text.begin());
					}
					result = 2;
					if (doneCallback)
						doneCallback(0);
					break;
				case 27:
					result = 3;
					if (doneCallback)
						doneCallback(1);
					break;
				case 127:
					if (cursor != text.size())
					{
						if (opW9_ctrlHeld)
							text.erase(text.begin() + cursor,text.end());
						else
							text.erase(text.begin() + cursor);
					}
					break;
				case 128:
					if (cursor != 0)
					{
						if (opW9_ctrlHeld)
							cursor = 0;
						else
							cursor--;
					}
					break;
				case 129:
					if (cursor < text.size())
					{
						if (opW9_ctrlHeld)
							cursor = text.size();
						else
							cursor++;
					}
					break;
				case 130:
				case 131:
					if (historyCallback)
						historyCallback(key == 130);
					break;
				case 132:
					cursor = 0;
					break;
				case 133:
					cursor = text.size();
					break;
				case 135:
					if (specialCallback)
						specialCallback(1);
					break;
			}
			break;
	}
}

class CTemp : public Console
{
public:
	virtual void update();
};

void CTemp::update()
{
	if (isHidden())
		return;
	if (!engine->isRunning())
		getParent()->removeSubconsole(this);
	else
		XConsole::update();
}
