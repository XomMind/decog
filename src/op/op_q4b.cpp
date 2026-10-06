// op_q4b: CInfo / CInfoLine / CInfoCompare and neighbouring UI consoles in 0x8b3900-0x8fec50 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include <string>
#include <vector>
using namespace std;

//==================================================================
// engine-side declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos();	// 0x453b40
	Pos(int v);	// 0x409990
	Pos(int x_, int y_);	// 0x46ca20
	Pos &operator=(const Pos &pos);	// 0x46ca50
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(const Rect &rect);	// 0x40a720
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
};

struct XEvent
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputAscii(int key, int type);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	bool isHidden();
	XConsole *getParent();
	int getWidth();	// 0x44b0d0
	int getHeight();
	float getScaleX();
	void setHidden(bool hidden);
	void setPos(int x, int y);
	void clear();
	void clearInterior();
	void removeSubconsole(XConsole *console);
	void deleteSubconsoles();
	void deleteSubconsolesExcept(XConsole *a, XConsole *b);
	bool contains(const Pos &pos);
	Pos localToAbs(Pos pos);
	void setScaleX(float scale);	// NOTE: placeholder name (0x417b60)
	void setScaleY(float scale);	// NOTE: placeholder name (0x417b80)
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch);
	void setCharColumn(int x, int y, int height, int ch);
	void setForeFrame(int x, int y, int width, int height, XColor color);
	void unknown429f10(vector<unsigned int> *colors, bool flag);	// NOTE: placeholder name
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)

	char pad04[0x60 - 0x04];
};

class ConsoleTitle;

class Console : public XConsole
{
public:
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer) throw();
	virtual ~Console();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);	// NOTE: placeholder name

	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void animate(string name);	// NOTE: placeholder name

	int state;	// NOTE: placeholder name (Console::unknown60)
	class OpQ4b_Engine *engine;
	ConsoleTitle *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);	// 0x48c710

	char pad6c[0x8c - 0x6c];
};

class CCloseButton : public Console
{
public:
	CCloseButton(XConsole *parent, const XColor &color, int unknown);	// 0x48d4a0 (NOTE: placeholder parameter names)

	char pad6c[0x8c - 0x6c];
};

class OpQ4b_Engine	// NOTE: placeholder name
{
public:
	void stopAll();	// NOTE: placeholder name (0x50ff30)
	bool update();	// NOTE: placeholder name (0x50fff0)
};

//==================================================================
// game-side declarations
//==================================================================

struct OpQ4b_ItemData	// NOTE: placeholder name
{
	char pad00[0x284];
	int field284;	// NOTE: placeholder name
};

class Item	// NOTE: placeholder layout
{
public:
	int getType();	// NOTE: placeholder name (folded getter 0x44aec0)
	int getNestedField();	// NOTE: placeholder name (folded getter 0x4578a0)
	int getField457820();	// NOTE: placeholder name (folded getter)
	OpQ4b_ItemData *getData();	// NOTE: placeholder name (folded +8 getter 0x9b4350)
	void unknown458390(int a);	// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class HProp;

class HItemP	// NOTE: placeholder layout (operator-> at 0x9b65b0)
{
public:
	int ID;
	bool isValid() const;
	Item *operator->() const;
};

class HItemList : public vector<HItemP>	// NOTE: placeholder layout
{
};

struct OpQ4b_EntityData	// NOTE: placeholder name
{
	char pad00[0x170];
	string field170;	// NOTE: placeholder name
};

class Entity	// NOTE: placeholder layout
{
public:
	void unknown637bb0();	// NOTE: placeholder name
	int getField457820();	// NOTE: placeholder name (folded getter)
	OpQ4b_EntityData *getData();	// NOTE: placeholder name (folded +8 getter 0x9b4350)
	bool unknown5cd5d0();	// NOTE: placeholder name
	bool unknown5c80a0();	// NOTE: placeholder name
	HItemList *getInventoryList();
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp() throw();
	bool isValid() const;
	bool isNull() const;
	void reset();	// NOTE: placeholder name (0x9b7270)
	Item *operator->() const;	// 0x9b65b0
	bool operator==(HProp other) const;	// 0x9b78e0
	bool operator!=(HProp other) const;	// 0x9b6510
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity() throw();
	bool isValid() const;
	void reset();	// NOTE: placeholder name (0x9b7270)
	Entity *operator->() const throw();	// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;	// 0x9b6510
};

class OpQ4b_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
	int unknown4636d0();	// NOTE: placeholder name
	int unknown463710();	// NOTE: placeholder name
	int unknown464290();	// NOTE: placeholder name
};
extern OpQ4b_World *opq4b_world;	// NOTE: placeholder name

class OpQ4b_MouseEvent	// NOTE: placeholder name
{
public:
	int getButton();	// NOTE: placeholder name (folded getter 0x457dd0)
	bool isDown();	// NOTE: placeholder name (0x415f40)
};

class OpQ4b_KeyEntry	// NOTE: placeholder name
{
public:
	int getKey();	// NOTE: placeholder name (folded getter 0x457dd0)
};

class OpQ4b_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void registerConsole(int command, Console *console, int unknown1, int unknown2);	// NOTE: placeholder name (0x416790)
	void unknown416570();	// NOTE: placeholder name
	void unknown416640();	// NOTE: placeholder name
	void unknown4162e0(int a, int b);	// NOTE: placeholder name
	void unknown416710(Console *console, int command);	// NOTE: placeholder name
	void setHoverCallback(bool (*callback)());	// NOTE: placeholder name (0x416750)
	void setClickCallback(bool (*callback)(OpQ4b_MouseEvent *event));	// NOTE: placeholder name (0x416770)
	class OpQ4b_KeyEntry *getField416230();	// NOTE: placeholder name
};
extern OpQ4b_KeyMap *opq4b_keyMap;	// NOTE: placeholder name

class OpQ4b_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	Pos getPos();	// 0x40a970
	void setPos(const Pos &pos);	// NOTE: placeholder name (0x41a910)
	bool getField41a6e0();	// NOTE: placeholder name
};
extern OpQ4b_Mouse *opq4b_mouse;	// NOTE: placeholder name

class OpQ4b_Audio	// NOTE: placeholder name (0xcefaa8)
{
public:
	void play(int sound, int a, int b, int c, int d);	// NOTE: placeholder name (0x793450)
	HProp unknown7932b0(int id);	// NOTE: placeholder name
};
extern OpQ4b_Audio *opq4b_audio;	// NOTE: placeholder name

class OpQ4b_Log : public XConsole	// NOTE: placeholder name (CLog at 0xcec0b0)
{
public:
	bool getField48e740();	// NOTE: placeholder name
	void unknown7b60e0();	// NOTE: placeholder name
};
extern OpQ4b_Log *opq4b_cec0b0;	// NOTE: placeholder name

class OpQ4b_Message	// NOTE: placeholder name (0x510d20)
{
public:
	OpQ4b_Message(int type, int a, int b, int c, HProp x, HProp y);	// NOTE: placeholder name

	char data[0x20];
};

class OpQ4b_InterfaceMsg : public XConsole	// NOTE: placeholder name (CInterfaceMsg at 0xcec0f4)
{
public:
	void add(OpQ4b_Message *msg);	// NOTE: placeholder name (0x7b1880)
	void hide();	// NOTE: placeholder name (0x7b1cc0)
};
extern OpQ4b_InterfaceMsg *opq4b_cec0f4;	// NOTE: placeholder name

class OpQ4b_Root : public XConsole	// NOTE: placeholder name (0xcec034)
{
public:
	void unknown4b3280();	// NOTE: placeholder name
};
extern OpQ4b_Root *opq4b_cec034;	// NOTE: placeholder name

class OpQ4b_MapView : public XConsole	// NOTE: placeholder name (0xcec054)
{
public:
	bool unknown49aa00();	// NOTE: placeholder name
	void unknown8142d0(int a, int b);	// NOTE: placeholder name
	void unknown827950();	// NOTE: placeholder name
	bool unknown820dc0(int a, int b);	// NOTE: placeholder name
};
extern OpQ4b_MapView *opq4b_mapView;	// NOTE: placeholder name

class OpQ4b_Inventory	// NOTE: placeholder name (CInventory at 0xcec08c)
{
public:
	void reopen(int a, HProp item);	// NOTE: placeholder name (0x8a2ce0)
};
extern OpQ4b_Inventory *opq4b_cec08c;	// NOTE: placeholder name

struct OpQ4b_ListOption	// NOTE: placeholder name
{
	char pad[0x6c];
	int index;
};

class OpQ4b_List : public Console	// NOTE: placeholder name (CList at 0xcec130)
{
public:
	int getType();	// NOTE: placeholder name (folded getter 0x48e040)
	OpQ4b_ListOption *getOption(int index);	// NOTE: placeholder name (0x48e060)
	int getOptionAtMouse();	// NOTE: placeholder name (0x7b28c0)
	void select(int index);	// NOTE: placeholder name (0x7b2c50)
};
extern OpQ4b_List *opq4b_cec130;	// NOTE: placeholder name

class OpQ4b_Hover : public XConsole	// NOTE: placeholder name (0xcec040)
{
public:
	Console *findHovered();	// NOTE: placeholder name (0x497670)
	vector<Console*> getValues();	// NOTE: placeholder name (0x497700)
};
extern OpQ4b_Hover *opq4b_cec040;	// NOTE: placeholder name

class OpQ4b_Shortcut	// NOTE: placeholder name (0xcec128)
{
public:
	void unknown8b1c90();	// NOTE: placeholder name
};
extern OpQ4b_Shortcut *opq4b_cec128;	// NOTE: placeholder name

class CInfoCompare;

class OpQ4b_Parts : public XConsole	// NOTE: placeholder name (CParts at 0xcec088)
{
public:
	CInfoCompare *unknown894ee0();	// NOTE: placeholder name
};
extern OpQ4b_Parts *opq4b_cec088;	// NOTE: placeholder name

class CInfoCompare : public Console
{
public:
	CInfoCompare(XConsole *parent);	// 0x8ec690
	virtual ~CInfoCompare();
	virtual void inputAscii(int key, int type);	// 0x8ec5e0 (NOTE: placeholder name)
	virtual void trigger(const string &command, int value);	// 0x8ec880

	HProp getTarget();	// 0x4aeed0
	void unknown8ec700(bool flag, HProp target);	// NOTE: placeholder name

	HProp target;	// NOTE: placeholder name
};

class OpQ4b_Keys	// NOTE: placeholder name (0xd338cc)
{
public:
	bool isDown(int key);	// NOTE: placeholder name (0x439510)
};
extern OpQ4b_Keys opq4b_keys;	// NOTE: placeholder name

class OpQ4b_ItemTag	// NOTE: placeholder name (CItemTag at 0xcec0a0)
{
public:
	void openForEntity(HEntity entity, int flag);	// 0x8aba90
};
extern OpQ4b_ItemTag *opq4b_cec0a0;	// NOTE: placeholder name

extern int opq4b_cf4854;	// NOTE: placeholder name
extern int opq4b_cf4898;	// NOTE: placeholder name
extern int opq4b_cf48dc;	// NOTE: placeholder name
extern int opq4b_cf4920;	// NOTE: placeholder name
extern vector<int> opq4b_cf4910;	// NOTE: placeholder name
extern vector<int> opq4b_d2d1c4;	// NOTE: placeholder name
extern bool opq4b_d28fa7;	// NOTE: placeholder name (option)

void opq4b_unknown8b2ee0(int command);	// NOTE: placeholder name (0x8b2ee0)
void opq4b_unknown8b1da0(HEntity entity, HProp item, int mode);	// NOTE: placeholder name (0x8b1da0)

extern bool opq4b_inputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern bool opq4b_d28e5e;	// NOTE: placeholder name (option)
extern bool opq4b_d28c8a;	// NOTE: placeholder name (option)
extern bool opq4b_d28d28;	// NOTE: placeholder name (option)
extern unsigned int opq4b_tickCount;	// NOTE: placeholder name (0xcaed20)
extern int opq4b_cec0fc;	// NOTE: placeholder name
extern XConsole *opq4b_cec0f8;	// NOTE: placeholder name
extern int opq4b_cec100;	// NOTE: placeholder name
extern int opq4b_cec038;	// NOTE: placeholder name

extern Rect opq4b_rectD20464;	// NOTE: placeholder name
extern Rect opq4b_rectCF0DA8;	// NOTE: placeholder name
extern Pos opq4b_posD2A88C;	// NOTE: placeholder name
extern Pos opq4b_posD21E48;	// NOTE: placeholder name
extern Pos opq4b_posD32EBC;	// NOTE: placeholder name
extern Rect opq4b_rectD22F7C;	// NOTE: placeholder name
extern Rect opq4b_rectD32E00;	// NOTE: placeholder name
extern XColor *opq4b_closeColor;	// NOTE: placeholder name (0xcf1f2c)
extern XColor opq4b_colorCF6F2C;	// NOTE: placeholder name

void opq4b_showHelp(int topic);	// NOTE: placeholder name (opW5_showHelp, 0x490970)
void opq4b_swap9da1f0(HItemList *list, unsigned int a, unsigned int b);	// NOTE: placeholder name
int opw2_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
bool opq4b_hover8b4940();	// NOTE: placeholder name (0x8b4940)
bool opq4b_click8b4080(OpQ4b_MouseEvent *event);	// NOTE: placeholder name (0x8b4080)

//==================================================================
// CInfo / CInfoLine
//==================================================================

class CInfo;
extern CInfo *opq4b_cec118;	// NOTE: placeholder name
extern CInfo *opq4b_cec11c;	// NOTE: placeholder name
extern CInfo *opq4b_cec120;	// NOTE: placeholder name
extern CInfo *opq4b_cec124;	// NOTE: placeholder name

class CInfoEntry : public Console	// NOTE: placeholder name
{
public:
};

class CInfo : public Console
{
public:
	CInfo(XConsole *parent, bool flag, int layer);	// 0x8b3ab0, NOTE: placeholder parameter names
	virtual ~CInfo();
	virtual bool input(void *event);	// 0x8ebcd0
	virtual void inputAscii(int key, int type);	// 0x8ec5e0 (NOTE: placeholder name)
	virtual void update();	// 0x8b4b40
	virtual void close();	// 0x8b4f00
	virtual void trigger(const string &command, int value);	// 0x8b5250

	bool unknown4aed70();	// NOTE: placeholder name
	CInfoEntry *unknown4aecc0();	// NOTE: placeholder name
	CInfoCompare *getCompare();	// NOTE: placeholder name (folded getter 0x45ad90)
	void unknown8b3d50(HEntity a, HProp b, HEntity c, Pos *pos, bool e);	// NOTE: placeholder name
	void unknown8b4010();	// NOTE: placeholder name
	void unknown8b4500(HEntity a, HProp b, HEntity c, Pos *pos, int mode, bool e);	// NOTE: placeholder name
	void unknown8b4990(HProp b, HProp c, bool e);	// NOTE: placeholder name
	void unknown8b5080();	// NOTE: placeholder name

	bool opened;	// NOTE: placeholder name
	char pad6d[0x70 - 0x6d];
	unsigned int openTick;	// NOTE: placeholder name
	CCloseButton *closeButton;	// NOTE: placeholder name
	bool unknown78;	// NOTE: placeholder name
	bool unknown79;	// NOTE: placeholder name
	int unknown7c;	// NOTE: placeholder name
	int unknown80;	// NOTE: placeholder name
	vector<CInfoEntry*> entries;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
	HEntity unknown98;	// NOTE: placeholder name
	HProp unknown9c;	// NOTE: placeholder name
	HEntity unknownA0;	// NOTE: placeholder name
	Pos unknownA4;	// NOTE: placeholder name
	bool unknownAC;	// NOTE: placeholder name
	HProp unknownB0;	// NOTE: placeholder name
	Pos unknownB4;	// NOTE: placeholder name
	Pos unknownBC;	// NOTE: placeholder name
	Pos unknownC4;	// NOTE: placeholder name
	Pos unknownCC;	// NOTE: placeholder name
	Pos unknownD4;	// NOTE: placeholder name
	int unknownDC;	// NOTE: placeholder name
	Pos unknownE0;	// NOTE: placeholder name
	int unknownE8;	// NOTE: placeholder name
	CInfoCompare *unknownEC;	// NOTE: placeholder name
	bool unknownF0;	// NOTE: placeholder name
	HProp unknownF4;	// NOTE: placeholder name
	int unknownF8;	// NOTE: placeholder name
};

class CInfoLine : public Console
{
public:
	virtual bool mouseEnter();	// 0x8b3a30
	virtual bool input(void *event);	// 0x8b3900

	int type;	// NOTE: placeholder name
	HProp item;	// NOTE: placeholder name
};

bool CInfoLine::input(void *event)
{
	if (isHidden() || opq4b_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opq4b_cec118 == getParent() && opq4b_cec130)
		return false;

	switch (((XEvent*)event)->type)
	{
	case 0xe8:
		if (type != 0x192)
			opq4b_showHelp(type);
		else if (item.operator->())
		{
			if (!opq4b_cec11c->unknown4aed70())
			{
				int mode = opq4b_cec0fc ? 5 : (opq4b_cec118->isHidden() ? 3 : 4);
				opq4b_cec120->unknown8b4500(HEntity(),item,HEntity(),&Pos(-1),mode,false);
			}
		}
		return true;
	}
	return false;
}

bool CInfoLine::mouseEnter()
{
	if (type == 0x192 && item.isNull())
		return false;
	if (item.isValid() && ((CInfo*)getParent())->unknown4aed70())
		return false;
	animate("A_CInfoLine_Hov_Begin");
	return true;
}

CInfo::CInfo(XConsole *parent, bool flag, int layer)
	: Console(parent,flag ? opq4b_rectD20464 : opq4b_rectCF0DA8,0,true,layer)
	, unknown78		(false)
	, unknown79		(false)
	, unknown7c		(0)
	, unknown80		(0)
	, unknown94		(-1)
	, unknownAC		(false)
	, unknownDC		(0)
	, unknownE0		(-1)
	, unknownE8		(0)
	, unknownEC		(NULL)
	, unknownF0		(false)
	, unknownF8		(-1)
{
	setTitle(new ConsoleTitle(this,flag ? "/ S T A T U S /" : "/ D A T A /",0,0));
	opened = false;
	closeButton = new CCloseButton(this,*opq4b_closeColor,12);
}

void CInfo::unknown8b3d50(HEntity a, HProp b, HEntity c, Pos *pos, bool e)
{
	if (this == opq4b_cec118 && opq4b_cec0b0->getField48e740())
		opq4b_cec0b0->unknown7b60e0();
	unknown8b4010();
	unknown7c = opq4b_world->unknown4636d0();
	unknown80 = opq4b_world->unknown463710();
	entries.clear();
	unknown94 = -1;
	unknown98 = a;
	unknown9c = b;
	unknownA0 = c;
	unknownA4 = *pos;
	unknownAC = e;
	if (unknownAC && unknown9c.isValid())
		unknown9c->unknown458390(0);
	if (unknown9c.isValid() && opq4b_d28e5e)
	{
		HItemList *list = opq4b_world->getPlayer()->getInventoryList();
		int total = 0;
		for (unsigned int i = 0; i < list->size(); i++)
		{
			if ((*list)[i]->getNestedField() == unknown9c->getNestedField())
			{
				opq4b_swap9da1f0(list,i,total);
				total++;
			}
		}
		opq4b_cec08c->reopen(0,HProp());
	}
	if (opq4b_d28c8a && unknown9c.isValid() && unknown9c->getType() == 5)
	{
		unknownF4 = unknown9c;
		unknownF8 = opq4b_world->unknown464290();
	}
	state = 1;
	if (opened)
	{
		clearInterior();
		animate("CInfo_Content");
	}
	else
	{
		clear();
		animate("CInfo_Border");
		opened = true;
		opq4b_audio->play(0x37,1,0,0,0);
	}
}

void CInfo::unknown8b4010()
{
	if (unknownAC)
	{
		if (unknown9c.isValid())
			unknown9c->unknown57dbe0(0,1,1,1);
		else
			unknown98->unknown637bb0();
		unknownAC = false;
	}
}

void CInfo::unknown8b4500(HEntity a, HProp b, HEntity c, Pos *pos, int mode, bool e)
{
	if (!opq4b_cec0f4->isHidden())
		opq4b_cec0f4->hide();
	switch (state)
	{
	case 0:
	{
		setHidden(false);
		if (mode == 6)
		{
			opq4b_keyMap->registerConsole(0xc,this,0xf3,0);
			opq4b_keyMap->setClickCallback(opq4b_click8b4080);
		}
		else
		{
			opq4b_keyMap->unknown416570();
			opq4b_cec034->unknown4b3280();
			opq4b_keyMap->unknown4162e0(0xc,1);
			opq4b_keyMap->unknown416710(this,0xf3);
			if (a == opq4b_world->getPlayer() || mode == 0)
				opq4b_keyMap->setClickCallback(opq4b_click8b4080);
		}
		HProp item;
		if (opq4b_d28c8a && b.isValid() && b->getType() == 5 && b != unknownF4 && opq4b_world->unknown464290() == unknownF8)
			item = unknownF4;
		unknown8b3d50(a,b,c,pos,e);
		unknown8b4990(b,item,e);
		opq4b_mapView->unknown8142d0(0x12,0);
		break;
	}
	case 1:
		if (!unknown78)
			return;
	case 3:
	{
		if (opq4b_cec128)
			opq4b_cec128->unknown8b1c90();
		engine->stopAll();
		deleteSubconsolesExcept(title,closeButton);
		HProp previous = unknown9c;
		if (this == opq4b_cec124)
		{
			unknown9c.reset();
			unknownAC = false;
			if (unknownB0.isValid())
				unknownB0->unknown57dbe0(0,1,1,1);
			unknownB0 = previous;
		}
		unknown8b3d50(a,b,c,pos,e);
		unknown8b4990(b,previous,e);
		break;
	}
	case 4:
		return;
	}
	setScaleX(1.0f);
	setScaleY(1.0f);
	if (opq4b_d28c8a && opq4b_mapView->unknown49aa00() && this != opq4b_cec120)
		unknownE0 = opq4b_mouse->getPos();
	else
		unknownE0.x = -1;
	if (a == opq4b_world->getPlayer())
		setPos(opq4b_rectD20464.x,opq4b_rectD20464.y);
	else
	{
		switch (mode)
		{
		case 0:
			setPos(opq4b_rectCF0DA8.x,opq4b_rectCF0DA8.y);
			break;
		case 1:
			setPos(opq4b_posD2A88C.x,opq4b_posD2A88C.y);
			break;
		case 2:
			setPos(opq4b_rectD20464.x + opq4b_rectD20464.width,opq4b_rectD20464.y);
			break;
		case 3:
			setPos(opq4b_rectCF0DA8.x - opq4b_rectCF0DA8.width,opq4b_rectCF0DA8.y);
			break;
		case 4:
			setPos(opq4b_rectD20464.x,opq4b_rectD20464.y);
			break;
		case 5:
			setPos(opq4b_posD21E48.x,opq4b_posD21E48.y);
			break;
		case 6:
			setPos(opq4b_posD32EBC.x,opq4b_posD32EBC.y);
			break;
		}
	}
}

void CInfo::unknown8b4990(HProp b, HProp c, bool e)
{
	if (this != opq4b_cec120 && !opq4b_cec100 && c.operator->() && b.isValid() && c != b && (!e || this == opq4b_cec124))
	{
		if (unknownEC)
			unknownEC->unknown8ec700(!unknownF0,c);
		else
		{
			unknownEC = new CInfoCompare(opq4b_cec034);
			unknownEC->unknown8ec700(!unknownF0,c);
			opq4b_keyMap->setHoverCallback(opq4b_hover8b4940);
		}
		unknownF0 = true;
	}
	else if (unknownEC)
	{
		opq4b_cec034->removeSubconsole(unknownEC);
		unknownEC = NULL;
		opq4b_keyMap->setHoverCallback(NULL);
	}
}

void CInfo::update()
{
	if (isHidden())
		return;
	switch (state)
	{
	case 0:
		break;
	case 1:
		if (!engine->update())
			state = 3;
		break;
	case 3:
		if (opened)
		{
			if (!unknown78)
				closeButton->setHidden(false);
			unknown78 = true;
		}
		if (opq4b_d28d28)
		{
			if (opq4b_world->unknown463710() > unknown80)
			{
				opq4b_cec0f4->add(new OpQ4b_Message(0x61,0,0,0,HProp(),HProp()));
				unknown80 = opq4b_world->unknown463710();
			}
		}
		else if (opq4b_world->unknown4636d0() > unknown7c)
		{
			opq4b_cec0f4->add(new OpQ4b_Message(0x60,0,0,0,HProp(),HProp()));
			unknown7c = opq4b_world->unknown4636d0();
		}
		break;
	case 4:
		engine->update();
		if (getScaleX() != 0.0f)
		{
			if (opq4b_tickCount - openTick >= 500)
			{
				setScaleX(0.0f);
				setScaleY(0.0f);
			}
			else
			{
				setScaleX(1.0 - (opq4b_tickCount - openTick) / 500.0);
				setScaleY(1.0 - (opq4b_tickCount - openTick) / 500.0);
				break;
			}
		}
		engine->stopAll();
		state = 0;
		setHidden(true);
		opq4b_keyMap->unknown416640();
		if (unknownE0.x != -1 && opq4b_d28c8a)
			opq4b_mouse->setPos(unknownE0);
		unknownE0.x = -1;
		if (!opq4b_d28c8a && opq4b_mapView->unknown49aa00())
			opq4b_mapView->unknown827950();
		unknown8b4010();
		if (this == opq4b_cec124)
		{
			if (unknownB0.isValid())
				unknownB0->unknown57dbe0(0,1,1,1);
			getParent()->removeSubconsole(opq4b_cec124);
			opq4b_cec124 = NULL;
		}
		return;
	}
	updateBase429e30();
}

void CInfo::close()
{
	if (opq4b_cec038)
		return;
	if (opq4b_cec118 == this && opq4b_cec130)
		return;
	if (opq4b_cec128)
		opq4b_cec128->unknown8b1c90();
	if (state == 4)
		return;
	state = 4;
	if (getHeight() < 50)
	{
		vector<unsigned int> colors(1u,unknownE8);
		unknown429f10(&colors,0);
	}
	else
		unknown429f10(0,0);
	deleteSubconsolesExcept(title,closeButton);
	if (unknownEC)
	{
		opq4b_cec034->removeSubconsole(unknownEC);
		unknownEC = NULL;
		opq4b_keyMap->setHoverCallback(NULL);
	}
	openTick = opq4b_tickCount;
	animate("A_BlockFadeInterior");
	if (opq4b_cec0fc && this != opq4b_cec120)
		opq4b_cec0f8->setHidden(false);
}

void CInfo::unknown8b5080()
{
	state = 0;
	engine->stopAll();
	setHidden(true);
	deleteSubconsolesExcept(title,closeButton);
	if (unknownEC)
	{
		opq4b_cec034->removeSubconsole(unknownEC);
		unknownEC = NULL;
		opq4b_keyMap->setHoverCallback(NULL);
	}
	opq4b_keyMap->unknown416640();
	if (opq4b_cec0fc && this != opq4b_cec120)
		opq4b_cec0f8->setHidden(false);
	if (unknownE0.x != -1 && opq4b_d28c8a)
		opq4b_mouse->setPos(unknownE0);
	unknownE0.x = -1;
	if (!opq4b_d28c8a && opq4b_mapView->unknown49aa00())
		opq4b_mapView->unknown827950();
	unknown8b4010();
	if (this == opq4b_cec124)
	{
		if (unknownB0.isValid())
			unknownB0->unknown57dbe0(0,1,1,1);
		getParent()->removeSubconsole(opq4b_cec124);
		opq4b_cec124 = NULL;
	}
}

//==================================================================
// CInfoCompare
//==================================================================

CInfoCompare::CInfoCompare(XConsole *parent)
	: Console(parent,opq4b_cec124 ? opq4b_rectD22F7C : opq4b_rectD32E00,0,false,0x19)
{
}

void CInfoCompare::inputAscii(int key, int type)
{
	switch (type)
	{
	case 2:
		if (opq4b_cec124 && key != 0x30)
			opq4b_cec040->getValues()[key - 0x31]->input(&XEvent(0x26));
		break;
	}
}

void CInfoCompare::unknown8ec700(bool flag, HProp target_)
{
	engine->stopAll();
	deleteSubconsoles();
	target = target_;
	if (flag)
	{
		state = 1;
		resetBack_418450();
		animate("CInfoCompare_Border");
	}
	else
	{
		state = 3;
		setCharColumn(0,1,getHeight() - 2,0x80);
		setChar_417f50(0,0,0x88);
		setChar_417f50(0,getHeight() - 1,0x87);
		setCharRow(1,0,9,0x81);
		setCharRow(1,getHeight() - 1,9,0x81);
		setChar_417f50(getWidth() - 2,0,0x84);
		setChar_417f50(getWidth() - 2,getHeight() - 1,0x86);
		setForeFrame(0,0,getWidth(),getHeight(),opq4b_colorCF6F2C);
		animate("CInfoCompare_Content");
	}
}

//==================================================================
// CInfo input callbacks
//==================================================================

bool opq4b_hover8b4940()
{
	if (opq4b_cec11c->getCompare() && opq4b_cec11c->getCompare()->contains(opq4b_mouse->getPos()))
		return true;
	return false;
}

bool opq4b_click8b4080(OpQ4b_MouseEvent *event)
{
	if (opq4b_cec124)
	{
		if (event->getButton() == 1 && event->isDown() && !opq4b_cec124->contains(opq4b_mouse->getPos()))
		{
			if (opq4b_cec124->getCompare() && opq4b_cec124->getCompare()->contains(opq4b_mouse->getPos()))
			{
				opq4b_cec124->input(&XEvent(0xea));
				return true;
			}
			Console *hovered = opq4b_cec040->findHovered();
			if (hovered)
			{
				hovered->input(&XEvent(0x26));
				return true;
			}
		}
		else if (event->getButton() == 3 && event->isDown() && !opq4b_cec124->contains(opq4b_mouse->getPos()))
			opq4b_cec124->close();
		return false;
	}
	if (event->getButton() == 3 && event->isDown() && opq4b_mapView->contains(opq4b_mouse->getPos()))
	{
		if ((opq4b_cec118->isHidden() || !opq4b_cec118->contains(opq4b_mouse->getPos()))
			&& (opq4b_cec11c->isHidden() || !opq4b_cec11c->contains(opq4b_mouse->getPos()))
			&& (opq4b_cec120->isHidden() || !opq4b_cec120->contains(opq4b_mouse->getPos()))
			&& opq4b_mapView->unknown820dc0(0,1))
			return true;
		return false;
	}
	if (event->getButton() == 1 && event->isDown() && opq4b_cec088->contains(opq4b_mouse->getPos()))
	{
		CInfoCompare *entry = opq4b_cec088->unknown894ee0();
		if (entry && entry->getTarget().isValid())
			return true;
		return false;
	}
	if (event->getButton() == 1 && event->isDown() && !opq4b_cec120->isHidden() && opq4b_cec11c->contains(opq4b_mouse->getPos()))
	{
		CInfoEntry *entry = opq4b_cec11c->unknown4aecc0();
		if (entry)
		{
			entry->input(&XEvent(0xe8));
			return true;
		}
		else
			return false;
	}
	if (event->getButton() == 1 && event->isDown() && opq4b_cec130)
	{
		if (opq4b_cec130->getFrame() == 0 || opq4b_cec130->getFrame() == 1 || opq4b_cec130->getFrame() == 2 || opq4b_cec130->getFrame() == 4 || opq4b_cec130->getFrame() == 5)
		{
			if (opq4b_cec130->contains(opq4b_mouse->getPos()))
			{
				int option = opq4b_cec130->getOptionAtMouse();
				if (option != -1)
				{
					opq4b_cec130->select(opq4b_cec130->getOption(option)->index);
					return true;
				}
				else
					return false;
			}
		}
	}
	return false;
}

int opq4b_barWidth8b51f0(float value, float maximum)	// NOTE: placeholder name
{
	if (value <= 0.0 || maximum <= 0.0)
		return 0;
	else if (value >= maximum)
		return 22;
	else
		return opw2_maxInt(1,(int)(value / maximum * 22.0));
}

bool CInfo::input(void *event)
{
	if (isHidden() || opq4b_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opq4b_cec118 == this && opq4b_cec130)
		return false;
	if (state == 4)
		return false;

	switch (((XEvent*)event)->type)
	{
	case 0xe9:
		if (opq4b_cec118 == this && opq4b_cf4854)
			opq4b_unknown8b2ee0(1);
		break;
	case 0xea:
		if (opq4b_cec118 == this && opq4b_cf4898)
			opq4b_unknown8b2ee0(2);
		else if (unknownEC)
		{
			if (opq4b_cec11c == this)
			{
				HProp ITEMV = unknown9c;
				HProp TARGETV = unknownEC->getTarget();
				unknown8b4500(HEntity(),TARGETV,HEntity(),&Pos(-1),0,false);
				unknown8b4990(TARGETV,ITEMV,false);
			}
			else if (opq4b_cec124 == this)
			{
				int a = unknown9c->getField457820();
				int b = unknownEC->getTarget()->getField457820();
				opq4b_cec124->unknown8b4500(HEntity(),opq4b_audio->unknown7932b0(opq4b_d2d1c4[a]),HEntity(),&Pos(-1),6,true);
				opq4b_cec124->unknown8b4500(HEntity(),opq4b_audio->unknown7932b0(opq4b_d2d1c4[b]),HEntity(),&Pos(-1),6,true);
			}
		}
		break;
	case 0xeb:
		if (opq4b_cec118 == this && opq4b_cf48dc)
			opq4b_unknown8b2ee0(4);
		break;
	case 0xec:
		if (opq4b_cec118 == this && opq4b_cf4920)
			opq4b_unknown8b2ee0(5);
		else if (unknown98.isValid() && opq4b_cec11c == this)
		{
			if (opq4b_cf4910[unknown98->getField457820()] && !unknown98->getData()->field170.empty())
				opq4b_unknown8b1da0(unknown98,HProp(),0);
		}
		break;
	case 0xed:
		if (unknown98.isValid() && opq4b_cec11c == this && unknown98->unknown5cd5d0() && opq4b_cec120->isHidden())
			opq4b_unknown8b1da0(unknown98,HProp(),1);
		break;
	case 0xee:
		if (unknown98.isValid() && opq4b_cec11c == this && unknown98->unknown5c80a0() && opq4b_cec120->isHidden())
			opq4b_cec0a0->openForEntity(unknown98,1);
		break;
	case 0xef:
		if (unknown98.isValid() && unknownDC)
			opq4b_unknown8b1da0(unknown98,HProp(),3);
		else if (unknown9c.isValid() && (opq4b_cec11c == this || opq4b_cec120 == this || opq4b_cec124 == this) && unknown9c->getData()->field284)
			opq4b_unknown8b1da0(HEntity(),unknown9c,2);
		break;
	case 0xf0:
		if (unknown94 != -1)
		{
			entries[unknown94]->input(&XEvent(0xe8));
			return true;
		}
		break;
	case 0xf1:
		if (entries.empty())
			return false;
		if (unknown4aed70())
			return false;
		if (opq4b_mouse->getField41a6e0())
		{
			if (unknown94 > 0)
				unknown94 = unknown94 - 1;
			else
				unknown94 = entries.size() - 1;
			opq4b_mouse->setPos(entries[unknown94]->localToAbs(Pos(4,0)));
		}
		return true;
	case 0xf2:
		if (entries.empty())
			return false;
		if (unknown4aed70())
			return false;
		if (opq4b_mouse->getField41a6e0())
		{
			if (unknown94 == entries.size() - 1)
				unknown94 = 0;
			else
				unknown94 = unknown94 + 1;
			opq4b_mouse->setPos(entries[unknown94]->localToAbs(Pos(4,0)));
		}
		return true;
	case 0xf3:
		if (opq4b_keyMap->getField416230() && opq4b_keyMap->getField416230()->getKey() == 0x1b)
		{
			if (this == opq4b_cec120)
				opq4b_cec11c->unknown79 = true;
			else if (this == opq4b_cec11c && unknown79)
			{
				unknown79 = false;
				return false;
			}
		}
		if (this == opq4b_cec11c && !opq4b_cec120->isHidden() && opq4b_keyMap->getField416230() && opq4b_keyMap->getField416230()->getKey() == 3)
			return false;
		if (opq4b_cec130 && (opq4b_keys.isDown(0x64) || opq4b_keys.isDown(0x73)))
			return false;
		if (state != 4 && unknown78 && (opq4b_cec118 != this || opq4b_cec11c->isHidden()))
		{
			if (opq4b_d28fa7)
				unknown8b5080();
			else
				close();
		}
		return true;
	}
	return false;
}
