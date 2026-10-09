// op_u5 slice 5: CCommands (the Manual window; global pointer at 0xcec03c) methods in 0x7c6850-0x7d67c0, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
using namespace std;

//==================================================================
// engine-side declarations
//==================================================================

struct Point
{
	int x;
	int y;

	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p, int dx, int dy);	// 0x4099c0
};

struct Pos : public Point
{
	Pos(int v);	// 0x409990
	Pos(int x_, int y_);
	Pos(const Pos &p, int dx, int dy);	// 0x4099c0
};

struct OpU5_PointVar	// NOTE: placeholder name; a Point-like local whose default ctor is 0x453b40 (-1,-1) and whose operator= folds into Point's copy ctor
{
	int x;
	int y;

	OpU5_PointVar();	// 0x453b40
	OpU5_PointVar &operator=(const Point &p);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor operator*(float value);	// 0x412050
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Point mouse;
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int mode);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	bool isHidden();
	int getWidth();
	int getHeight();
	Pos getPos();
	void move(int x, int y);
	void clear();
	void setHidden(bool hidden_);
	void deleteSubconsoles();
	XColor getFore(int x, int y);
	XColor getBack(int x, int y);
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBack_417fc0(int x, int y, XColor color, int mode);	// NOTE: placeholder name
	void setIgnoreMouse_4184a0(bool value);	// NOTE: placeholder name
	void print(int x, int y, const string &text);
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void resetBack_418450();	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Point &pos, int flag);	// NOTE: placeholder name
	bool inputBase429d00(XEvent *event);	// NOTE: placeholder name (XConsole::input body)
	void updateBase429e30();	// NOTE: placeholder name (XConsole::update body)

	char pad04[0x60 - 0x04];
};

class OpU5_Engine	// NOTE: placeholder name (Engine)
{
public:
	bool update();	// NOTE: placeholder name (0x50fff0)
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);	// NOTE: placeholder name

	void unknown48c3c0(int value);	// NOTE: placeholder name
	void drawFrame(void *area, XColor color, bool thin, bool lines);	// NOTE: placeholder name

	int unknown60;
	OpU5_Engine *engine;
	void *title;
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);

	char pad6c[0x88 - sizeof(Console)];
};

class CNotification : public Console
{
public:
	CNotification(XConsole *parent, int x, int y, const string &text, int width);	// 0x4b22b0

	char pad6c[0x70 - sizeof(Console)];
};

class CList : public Console
{
public:
	CList(XConsole *parent, const Pos &pos, string title, int unknown74_, const vector<string> &options_, int maxVisible, int font, void (*callback_)(int,const string&), int unknownC4_, int layer, bool unknown9c_, bool unknown9d_, vector<bool> *enabled_, vector<int> *unknownA4_, vector<int> *unknownA8_, bool noClose_);	// 0x48d9a0

	virtual void close();

	char pad6c[0xd4 - sizeof(Console)];

	void unknown7b2870();	// NOTE: placeholder name
};

class OpU5_AsciiImage	// NOTE: placeholder name (AsciiImage); file-unique so the delete in CCommands() pairs its own deleting destructor with 0x7c6d00
{
public:
	OpU5_AsciiImage() throw();	// 0x4588d0
	~OpU5_AsciiImage();
	bool load(const string &file, int font, Pos *offset, int width, int height);

	char pad[0x10];
};

class CCommandsButton : public Console
{
public:
	void draw(int mode);	// NOTE: placeholder name
};

class CManualButton : public Console
{
public:
	void draw(int state);	// NOTE: placeholder name
};

class COptionButton : public Console
{
public:
	void draw();	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
};

class COptionValue : public Console
{
public:
	void refresh();
};

class Unknown_4959c0 : public Console
{
public:
	void setColors();	// 0x4959c0

	int unknown6c;	// NOTE: placeholder name
};

class Unknown_496180 : public Console
{
public:
	void setHighlight();	// 0x496180
};

class Unknown_c34b98 : public Console
{
public:
	void setColor();	// 0x4962f0
};

class Unknown_c34bcc : public Console
{
public:
	Unknown_c34bcc(XConsole *parent, int x, int y, int width, int height, int value);	// 0x496320
	void setColor();	// 0x496370

	int unknown6c;	// NOTE: placeholder name
};


class OpQ5_U9d7530	// NOTE: placeholder name (elements of the vector at 0xd25de0)
{
public:
	char pad00[0x78];
	int glyph;	// NOTE: placeholder name
};
template <class T> bool OpQ5_findByName(vector<T*> &v, const string &name, T *&result);	// NOTE: placeholder name (0x9d7de0; declared with a const string& here)
extern vector<OpQ5_U9d7530*> opU5_units_d25de0;	// NOTE: placeholder name
extern XColor *opU5_color_cfe674;	// NOTE: placeholder name
extern int opU5_anim_cef7f8[];	// NOTE: placeholder name
extern string opU5_strings_d161d8[];	// NOTE: placeholder name

class OpW5_Console4931e0 : public Console	// NOTE: placeholder name
{
public:
	void refreshColor();	// 0x4931e0
};

class OpW5_Console4963e0 : public Console	// NOTE: placeholder name
{
public:
	void refreshColor();	// 0x4963e0
};

class CTitleAnimated : public Console
{
public:
	void unknown4b29b0();	// NOTE: placeholder name
};

class Unknown_c34c00 : public OpW5_Console4963e0
{
public:
	Unknown_c34c00(XConsole *parent, int x, int y, int width, int height);	// 0x4963a0
};

class CArtAnimated : public CTitleAnimated
{
public:
	CArtAnimated(XConsole *parent, class AsciiImage *image, int x, int y, bool hidden, int anim, int unknown1, int unknown2, const Pos &offset, int width, int height);

	char pad6c[0x88 - 0x6c];
};

class OpU5_Rex	// NOTE: placeholder name (object at 0xd223f0)
{
public:
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
	XConsole *getConsole_4ab670();	// NOTE: placeholder name (folded getter)
};
extern OpU5_Rex opU5_rex;	// NOTE: placeholder name (0xd223f0)

class OpU5_Config	// NOTE: placeholder name (object at 0xd28c68)
{
public:
	void save(int index, int flag);	// NOTE: placeholder name (0x440450)
};
extern OpU5_Config opU5_config;	// NOTE: placeholder name (0xd28c68)

class OpU5_KeyMap	// NOTE: placeholder name (pointer global at 0xcefa8c)
{
public:
	void popFrame();	// NOTE: placeholder name (0x416640)
};
extern OpU5_KeyMap *opU5_keyMap;	// NOTE: placeholder name (0xcefa8c)

struct HEntity
{
	int ID;
};

class Map
{
public:
	HEntity getPlayer() throw();	// 0x4630f0
};
extern Map *opU5_map;	// NOTE: placeholder name (0xcefc4c)

class SoundMgr	// NOTE: placeholder name
{
public:
	void unknown500260(bool flag);	// NOTE: placeholder name
	void unknown4544c0(HEntity entity);	// NOTE: placeholder name
	void unknown500010();	// NOTE: placeholder name
};
extern SoundMgr opU5_soundMgr;	// NOTE: placeholder name (0xd2d2a0)

class OpU5_Scorekeeper	// NOTE: placeholder name (object at 0xd2c658)
{
public:
	string totalScore_474a20(int flags);	// NOTE: placeholder name
};
extern OpU5_Scorekeeper opU5_scorekeeper;	// NOTE: placeholder name (0xd2c658)

void opU5_replace407e00(const string &text, string from, string to);	// NOTE: placeholder name (0x407e00)
int opU5_centerOffset(int inner, int outer);	// NOTE: placeholder name (0x437190)

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern int opU5_fontCellSize;	// NOTE: placeholder name (0xcaf128)
extern bool opU5_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern int opU5_consoleMode;	// NOTE: placeholder name (0xd28d64)
extern bool opU5_flag_d28d6c;	// NOTE: placeholder name
extern int opU5_anim_cef824;	// NOTE: placeholder name
extern int opU5_anim_cef880;	// NOTE: placeholder name
extern int opU5_anim_cef8dc;	// NOTE: placeholder name
extern int opU5_table_bcb9e0[];	// NOTE: placeholder name
extern string opU5_strings_d2b410[];	// NOTE: placeholder name
extern string opU5_strings_cfb948[];	// NOTE: placeholder name
extern string opU5_string_cf10bc;	// NOTE: placeholder name

extern CList *opU5_cec130;	// NOTE: placeholder name
extern Console *opU5_cec10c;	// NOTE: placeholder name
extern XConsole *opU5_cec034;	// NOTE: placeholder name
extern XConsole *opU5_cec054;	// NOTE: placeholder name
extern XConsole *opU5_cec0b0;	// NOTE: placeholder name (CLog)
extern XConsole *opU5_cec0d0;	// NOTE: placeholder name
extern XConsole *opU5_cec0c8;	// NOTE: placeholder name
extern XConsole *opU5_cec0cc;	// NOTE: placeholder name
extern XConsole *opU5_cec0b8;	// NOTE: placeholder name
extern XConsole *opU5_cec0c0;	// NOTE: placeholder name
extern XConsole *opU5_cec0e0;	// NOTE: placeholder name
extern XConsole *opU5_cec0e4;	// NOTE: placeholder name
extern XConsole *opU5_cec058;	// NOTE: placeholder name
extern XConsole *opU5_cec074;	// NOTE: placeholder name
extern XConsole *opU5_cec078;	// NOTE: placeholder name
extern XConsole *opU5_cec084;	// NOTE: placeholder name
extern XConsole *opU5_cec07c;	// NOTE: placeholder name
extern XConsole *opU5_cec088;	// NOTE: placeholder name
extern XConsole *opU5_cec08c;	// NOTE: placeholder name
extern XConsole *opU5_cec05c;	// NOTE: placeholder name
extern XConsole *opU5_cec060;	// NOTE: placeholder name
extern XConsole *opU5_cec068;	// NOTE: placeholder name
extern XConsole *opU5_cec06c;	// NOTE: placeholder name

class OpU5_Win7d8d60	// NOTE: placeholder name
{
public:
	OpU5_Win7d8d60();	// 0x7d8d60
	char pad[0xc4];
};

class OpU5_Win7e8ee0	// NOTE: placeholder name
{
public:
	OpU5_Win7e8ee0();	// 0x7e8ee0
	char pad[0x98];
};

class OpU5_Win7ee700	// NOTE: placeholder name
{
public:
	OpU5_Win7ee700();	// 0x7ee700
	char pad[0xb8];
};

class OpU5_Win7f2610	// NOTE: placeholder name
{
public:
	OpU5_Win7f2610(int value);	// 0x7f2610
	char pad[0xa0];
};

//==================================================================
// CCommands (global pointer at 0xcec03c)
//==================================================================

class CCommands : public Console
{
public:
	CCommands(XConsole *parent);
	virtual bool input(void *event);	// 0x7d0aa0 (defined in src/game/team_d_58.cpp)
	virtual void inputAscii(int key, int mode);
	virtual void update();
	virtual void close();

	void unknown7d1050(int mode);	// NOTE: placeholder name
	void unknown7d14d0(int section);	// NOTE: placeholder name
	void unknown7d1740();	// NOTE: placeholder name
	void unknown7d17d0();	// NOTE: placeholder name
	void unknown7d1840();	// NOTE: placeholder name
	void unknown7d18d0();	// NOTE: placeholder name
	void unknown7d2030(COptionButton *button, string text);	// NOTE: placeholder name
	void unknown7d1d80();	// NOTE: placeholder name
	void unknown7d1ed0(const string &title, const vector<string> &options, vector<bool> *enabled);	// NOTE: placeholder name
	void unknown7d5c70();	// NOTE: placeholder name
	void unknown7d6690();	// NOTE: placeholder name
	void unknown7d67c0(XConsole *other);	// NOTE: placeholder name
	void unknown7d08c0();	// NOTE: placeholder name
	void addGallerySection(const Point &origin, const string &title, vector<int> &items);	// NOTE: placeholder name (0x7d5cf0)

	int ID;	// NOTE: placeholder name
	vector<CCommandsButton*> tabButtons;	// NOTE: placeholder name
	vector<Console*> list80;	// NOTE: placeholder name
	vector<Unknown_4959c0*> list90;	// NOTE: placeholder name
	vector<Unknown_496180*> lista0;	// NOTE: placeholder name
	bool unknownb0;	// NOTE: placeholder name
	vector<Console*> listb4;	// NOTE: placeholder name
	void *unknownc4;	// NOTE: placeholder name
	void *unknownc8;	// NOTE: placeholder name
	void *unknowncc;	// NOTE: placeholder name
	void *unknownd0;	// NOTE: placeholder name
	vector<CManualButton*> sectionButtons;	// NOTE: placeholder name
	int page;	// NOTE: placeholder name
	vector<OpW5_Console4931e0*> liste8;	// NOTE: placeholder name
	void *unknownf8;	// NOTE: placeholder name
	int unknownfc;	// NOTE: placeholder name
	int unknown100;	// NOTE: placeholder name
	void *unknown104;	// NOTE: placeholder name
	void *unknown108;	// NOTE: placeholder name
	vector<Console*> list10c;	// NOTE: placeholder name
	vector<COptionButton*> optionButtons;	// NOTE: placeholder name
	vector<COptionValue*> optionValues;	// NOTE: placeholder name
	void *unknown13c;	// NOTE: placeholder name
	int unknown140;	// NOTE: placeholder name
	unsigned int unknown144;	// NOTE: placeholder name
	int unknown148;	// NOTE: placeholder name
	vector<Unknown_c34b98*> list14c;	// NOTE: placeholder name
	OpU5_AsciiImage *unknown15c;	// NOTE: placeholder name
	vector<Unknown_c34bcc*> list160;	// NOTE: placeholder name
	vector<OpW5_Console4963e0*> list170;	// NOTE: placeholder name
	vector<CTitleAnimated*> list180;	// NOTE: placeholder name
	Console *unknown190;	// NOTE: placeholder name
	CCommandsButton *unknown194;	// NOTE: placeholder name
	CCommandsButton *unknown198;	// NOTE: placeholder name
	vector<Console*> list19c;	// NOTE: placeholder name
	vector<Console*> list1ac;	// NOTE: placeholder name
	vector<Console*> list1bc;	// NOTE: placeholder name
	CText *unknown1cc;	// NOTE: placeholder name
	Console *unknown1d0;	// NOTE: placeholder name
};

extern CCommands *opU5_cec03c;	// NOTE: placeholder name

// 0x7c6850. The OpU5_AsciiImage ctor is declared throw() (so the new gets no EH state); &Pos(-1) passes the address
// of a temporary (MSVC extension) to match the uncopied Pos temp.
CCommands::CCommands(XConsole *parent)
	: Console(parent,opU5_rex.unknown418980(),opU5_rex.unknown4189a0(),0,0,0,true,-1),
	ID(opU5_flag_d28d6c ? 1 : 0),
	unknownb0(false),
	unknownc4(0), unknownc8(0), unknowncc(0), unknownd0(0),
	page(0),
	unknownf8(0), unknownfc(0),
	unknown104(0), unknown108(0),
	unknown13c(0),
	unknown144(0), unknown148(50),
	unknown15c(0),
	unknown190(0), unknown194(0), unknown198(0),
	unknown1cc(0), unknown1d0(0)
{
	OpU5_AsciiImage *art = new OpU5_AsciiImage();
	unknown15c = art;
	if (!unknown15c->load(string() + "data/art/" + "credits",4,&Pos(-1),0,0))
	{
		delete unknown15c;
		unknown15c = 0;
	}
}

void OpU5_unknown7d1cc0(int index, const string &name)	// NOTE: placeholder name
{
	if (name.empty())
		opU5_cec130->close();
	else
	{
		opU5_cec03c->unknown7d2030(NULL,name);
		opU5_cec130->unknown7b2870();
		opU5_cec03c->unknown7d1d80();
	}
}

void OpU5_unknown7d1d30(const string &name)	// NOTE: placeholder name
{
	opU5_cec03c->unknown7d2030(NULL,name);
	opU5_cec10c->close();
	opU5_cec03c->unknown7d1d80();
}

void CCommands::unknown7d5c70()
{
	if (ID != 3)
		return;
	optionValues[1]->clear();
	optionValues[1]->refresh();
	optionValues[0x1f]->clear();
	optionValues[0x1f]->refresh();
}

void CCommands::unknown7d1d80()
{
	if (unknown148 != 0x32)
	{
		string text = opU5_strings_d2b410[opU5_table_bcb9e0[unknown148]];
		opU5_replace407e00(text,opU5_string_cf10bc,opU5_strings_cfb948[unknown148]);
		new CNotification(opU5_cec034,opU5_centerOffset(0x36,opU5_cec054->getWidth() * opU5_fontCellSize),0x14,text,0x36);
		unknown148 = 0x32;
	}
}

void CCommands::unknown7d1ed0(const string &title, const vector<string> &options, vector<bool> *enabled)
{
	Point pos(optionValues[unknown140]->getPos(),0,1);
	new CList(this,(Pos&)pos,title,0xc,options,0x1a,0,OpU5_unknown7d1cc0,0,0x16,false,false,enabled,NULL,NULL,false);
	if (opU5_cec130->getPos().y + opU5_cec130->getHeight() >= opU5_rex.unknown4189a0())
		opU5_cec130->move(0,opU5_rex.unknown4189a0() - (opU5_cec130->getPos().y + opU5_cec130->getHeight()));
}

void CCommands::unknown7d6690()
{
	string score = opU5_scorekeeper.totalScore_474a20(1);
	if (ID == 6)
	{
		string text = "Data output to " + score;
		unknown1cc = new CText(this,Pos(list1bc[3]->getPos(),0,3),text,0,0,-1);
		unknown1cc->unknown48c3c0(opU5_anim_cef8dc);
	}
}

void CCommands::unknown7d67c0(XConsole *other)
{
	other->setHidden(true);
	unknown1d0 = new Console(opU5_cec03c,opU5_rex.unknown418980(),opU5_rex.unknown4189a0(),0,0,0,false,9);
	opU5_rex.getConsole_4ab670()->unknown429fe0(unknown1d0,Point(0,0),0);
	for (int i = 0; i < unknown1d0->getWidth(); i++)
	{
		for (int j = 0; j < unknown1d0->getHeight(); j++)
		{
			unknown1d0->setFore_417f80(i,j,unknown1d0->getFore(i,j) * 0.5f);
			unknown1d0->setBack_417fc0(i,j,unknown1d0->getBack(i,j) * 0.5f,1);
		}
	}
	unknown1d0->setIgnoreMouse_4184a0(true);
	other->setHidden(false);
}

void CCommands::close()
{
	unknown60 = 4;
	deleteSubconsoles();
	tabButtons.clear();
	list80.clear();
	list90.clear();
	lista0.clear();
	unknownb0 = false;
	listb4.clear();
	unknownc4 = NULL;
	unknownc8 = NULL;
	unknowncc = NULL;
	unknownd0 = NULL;
	sectionButtons.clear();
	liste8.clear();
	unknownf8 = NULL;
	unknown104 = NULL;
	unknown108 = NULL;
	list10c.clear();
	optionButtons.clear();
	optionValues.clear();
	unknown13c = NULL;
	list14c.clear();
	list160.clear();
	list170.clear();
	list180.clear();
	unknown190 = NULL;
	unknown194 = NULL;
	unknown198 = NULL;
	list19c.clear();
	list1ac.clear();
	list1bc.clear();
	unknown1cc = NULL;
	for (int i = 0; i < 3; i++)
		opU5_config.save(i,0);
}

void CCommands::unknown7d08c0()
{
	unknown60 = 0;
	opU5_cec0b0->setHidden(false);
	opU5_cec0d0->setHidden(false);
	switch (opU5_consoleMode)
	{
	case 0:
		opU5_cec0c8->setHidden(false);
		break;
	case 1:
		opU5_cec0cc->setHidden(false);
		break;
	case 2:
		opU5_cec0b8->setHidden(false);
		break;
	case 3:
		opU5_cec0c0->setHidden(false);
		break;
	}
	if (opU5_cec0e0)
		opU5_cec0e0->setHidden(false);
	opU5_cec0e4->setHidden(false);
	opU5_cec054->setHidden(false);
	opU5_cec058->setHidden(false);
	opU5_cec074->setHidden(false);
	opU5_cec078->setHidden(false);
	opU5_cec084->setHidden(false);
	opU5_cec07c->setHidden(false);
	opU5_cec088->setHidden(false);
	opU5_cec08c->setHidden(false);
	if (opU5_cec05c)
		opU5_cec05c->setHidden(false);
	if (opU5_cec060)
		opU5_cec060->setHidden(false);
	if (opU5_cec068)
		opU5_cec068->setHidden(false);
	if (opU5_cec06c)
		opU5_cec06c->setHidden(false);
	setHidden(true);
	opU5_keyMap->popFrame();
	opU5_soundMgr.unknown500260(false);
	opU5_soundMgr.unknown4544c0(opU5_map->getPlayer());
	opU5_soundMgr.unknown500010();
}

void CCommands::inputAscii(int key, int mode)
{
	switch (mode)
	{
	case 0:
	case 1:
		switch (ID)
		{
		case 0:
			for (unsigned int i = 0; i < list90.size(); i++)
			{
				if (list90[i]->unknown6c == key)
				{
					list90[i]->input(&XEvent(0x14));
					break;
				}
			}
			break;
		case 1:
			break;
		case 2:
			if (mode == 1)
				key += 0x20;
			unknown7d14d0(key - 0x61);
			break;
		case 3:
			for (unsigned int i = 0; i < optionButtons.size(); i++)
			{
				if (optionButtons[i]->unknown6c == key)
				{
					unknown7d2030(optionButtons[i],string(""));
					break;
				}
			}
			break;
		case 4:
		case 5:
			break;
		case 6:
			if (mode == 1)
				key += 0x20;
			switch (key)
			{
			case 'g':
				new OpU5_Win7d8d60();
				break;
			case 'l':
				new OpU5_Win7e8ee0();
				break;
			case 'a':
				new OpU5_Win7ee700();
				break;
			case 'd':
				opU5_cec03c->unknown7d6690();
				break;
			}
			break;
		}
		break;
	}
}

void CCommands::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		break;
	case 1:
		for (unsigned int i = 0; i < tabButtons.size(); i++)
			tabButtons[i]->draw(0);
		unknown60 = 2;
	case 2:
		switch (ID)
		{
		case 0:
			for (unsigned int i = 0; i < list80.size(); i++)
				list80[i]->open();
			for (unsigned int i = 0; i < list90.size(); i++)
				list90[i]->setColors();
			for (unsigned int i = 0; i < lista0.size(); i++)
				lista0[i]->setHighlight();
			break;
		case 1:
			for (unsigned int i = 0; i < listb4.size(); i++)
				listb4[i]->open();
			break;
		case 2:
			if (unknownfc == 0)
			{
				for (unsigned int i = 0; i < sectionButtons.size(); i++)
					sectionButtons[i]->draw(0);
			}
			else if (unknownfc == 1)
			{
				sectionButtons[unknown100]->draw(1);
				sectionButtons[page]->draw(2);
			}
			for (unsigned int i = 0; i < liste8.size(); i++)
			{
				if (liste8[i])
					liste8[i]->refreshColor();
			}
			break;
		case 3:
			for (unsigned int i = 0; i < list10c.size(); i++)
				list10c[i]->unknown48c3c0(opU5_anim_cef824);
			for (unsigned int i = 0; i < optionButtons.size(); i++)
			{
				optionButtons[i]->draw();
				optionValues[i]->refresh();
			}
			break;
		case 4:
			for (unsigned int i = 0; i < list14c.size(); i++)
				list14c[i]->setColor();
			break;
		case 5:
			for (unsigned int i = 0; i < list160.size(); i++)
				list160[i]->setColor();
			for (unsigned int i = 0; i < list170.size(); i++)
				list170[i]->refreshColor();
			for (unsigned int i = 0; i < list180.size(); i++)
				list180[i]->unknown4b29b0();
			unknown190->unknown48c3c0(opU5_anim_cef880);
			unknown194->draw(0);
			unknown198->draw(0);
			break;
		}
		unknown60 = 3;
	case 3:
		engine->update();
		break;
	case 4:
		unknown7d08c0();
		break;
	}
	updateBase429e30();
}

// 0x7d5cf0. Local names (point/text/label/base/x/unit) are chosen for the frame layout; OpU5_PointVar and the
// const string& findByName declaration keep their call shapes without touching shared Point/template names.
void CCommands::addGallerySection(const Point &origin, const string &title, vector<int> &items)
{
	OpU5_PointVar point;
	string text = "=  " + title + "  =";
	point = origin;
	point.x -= text.size() / 2;
	list160.push_back(new Unknown_c34bcc(this,point.x,point.y,text.size(),1,1));
	list160.back()->print(0,0,text);
	point.y += 2;
	for (unsigned int i = 0; i < items.size(); i++)
	{
		Point label(origin.x - opU5_strings_d161d8[items[i]].size() / 2,point.y);
		list160.push_back(new Unknown_c34bcc(this,label.x,label.y,opU5_strings_d161d8[items[i]].size(),1,2));
		list160.back()->print(0,0,opU5_strings_d161d8[items[i]]);
		point.y++;
		Point base(origin.x - 0x13,point.y);
		list170.push_back(new Unknown_c34c00(this,base.x,base.y,0x13,5));
		list170.back()->drawFrame(NULL,*opU5_color_cfe674,true,true);
		if (unknown15c)
			list180.push_back(new CArtAnimated(this,(AsciiImage *)unknown15c,base.x + 2,base.y + 1,false,opU5_anim_cef7f8[items[i]],-1,-1,Pos(0,items[i] * 3),0x11,3));
		if (items[i] == 5)
		{
			unknown190 = new Console(this,0x11,3,base.x + 2,base.y + 1,2,false,-1);
			unknown190->resetBack_418450();
			int x = 1;
			OpQ5_U9d7530 *unit;
			if (OpQ5_findByName(opU5_units_d25de0,"Y-45 Defender",unit))
				unknown190->putChar_4180b0(x,1,unit->glyph);
			x += 2;
			if (OpQ5_findByName(opU5_units_d25de0,"T-07 Excavator",unit))
				unknown190->putChar_4180b0(x,1,unit->glyph);
			x += 2;
			if (OpQ5_findByName(opU5_units_d25de0,"O-16 Technician",unit))
				unknown190->putChar_4180b0(x,1,unit->glyph);
			x += 2;
			if (OpQ5_findByName(opU5_units_d25de0,"H-55 Commando",unit))
				unknown190->putChar_4180b0(x,1,unit->glyph);
			x += 2;
			if (OpQ5_findByName(opU5_units_d25de0,"G-34 Mercenary",unit))
				unknown190->putChar_4180b0(x,1,unit->glyph);
			x += 2;
			if (OpQ5_findByName(opU5_units_d25de0,"R-06 Scavenger",unit))
				unknown190->putChar_4180b0(x,1,unit->glyph);
			x += 2;
			if (OpQ5_findByName(opU5_units_d25de0,"U-05 Engineer",unit))
				unknown190->putChar_4180b0(x,1,unit->glyph);
			x += 2;
			if (OpQ5_findByName(opU5_units_d25de0,"D-53 Grenadier",unit))
				unknown190->putChar_4180b0(x,1,unit->glyph);
			x += 2;
		}
		point.y += 5;
	}
}
