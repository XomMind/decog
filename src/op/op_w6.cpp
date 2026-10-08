// op_w6: header-inline members of the HUD/parts/inventory consoles (0x4a0000-0x4b0000), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_) throw();
	Pos(int v) throw();	// 0x409990
	Pos(const Pos &pos);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int width_, int height_);	// 0x456940
	Rect(const Rect &rect);
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	bool isHidden();
	int getWidth44b0d0();	// NOTE: placeholder name (0x44b0d0)
	void setFore(XColor color);
	void setForeRow(int x, int y, int width, XColor color);
	void print(int x, int y, const string &text);
	void setPos(int x, int y);
	void setPos(const Pos &pos);
	void setBackRow(int x, int y, int width, XColor color);
	XConsole *getParent4();	// NOTE: placeholder name (folded +4 getter)
	Pos getPos();
	int getHeight();
	int getLayer();	// NOTE: placeholder name (folded +0x58 getter)
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void clearBack();
	void putChar_418110(int x, int y, int ch, XColor fore);	// NOTE: placeholder name
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch, XColor color);
	void setString_418010(int x, int y, string text);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Pos &pos, int value);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Pos &pos, const Rect &rect) throw();	// NOTE: placeholder name
	Rect getRect() throw();
	void clear();
	void removeSubconsole(XConsole *console);
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)

	char pad04[0x60 - 0x04];
};

class OpW6_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpW6_Engine	// NOTE: placeholder name (Engine)
{
public:
	OpW6_EngineItem *unknown50fb50(OpW6_Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	bool update();	// NOTE: placeholder name (0x50fff0)
	void killGroup(string group);
};

class ConsoleTitle;

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void resize(int width, int height);
	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void animate(string name);
	void unknown7b0640(int a, XColor color, int b, int c);	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);	// NOTE: placeholder name

	int unknown60;
	OpW6_Engine *engine;
	ConsoleTitle *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);
	char pad6c[0x8c - 0x6c];
};

string floatToString(float value, int unknown1, int unknown2);	// NOTE: placeholder name (0x405760)
void opw6_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)
int opw6_unknown434b90(int value) throw();	// NOTE: placeholder name

extern string gameString_d32cfc;	// "[STATS (9)]"
extern string gameStrings_d21e90[];
extern float opw6_cf46f8;	// NOTE: placeholder name
extern XColor *opw6_cf44c0;	// NOTE: placeholder name
extern XColor *opw6_d2981c;	// NOTE: placeholder name
extern XColor *opw6_cfc174;	// NOTE: placeholder name
extern XColor *opw6_cfe674;	// NOTE: placeholder name (COLOR_BLACK)
extern XColor *opw6_cf6b24;	// NOTE: placeholder name
extern XColor *opw6_d29758;	// NOTE: placeholder name
extern XColor opw6_d29ae0[];	// NOTE: placeholder name
extern int opw6_cf4700;	// NOTE: placeholder name
extern XColor *opw6_d25f60;	// NOTE: placeholder name
extern int opw6_fontCellWidth;	// NOTE: placeholder name (0xcaf128)
extern int opw6_fontCellScale;	// NOTE: placeholder name (0xcaf12c)
extern int opw6_cefac4;	// NOTE: placeholder name
extern XConsole *opw6_mapView;	// NOTE: placeholder name (0xcec054)
extern XConsole *opw6_cec06c;	// NOTE: placeholder name
extern int opw6_d3846c;	// NOTE: placeholder name
extern int opw6_d38470;	// NOTE: placeholder name
extern vector<int> opw6_cf4a14;	// NOTE: placeholder name
bool unknown4328a0();	// NOTE: placeholder name
extern string gameStrings_d20620[];	// NOTE: placeholder name
extern XColor *opw6_d20b70;	// NOTE: placeholder name
extern vector<int> opw6_cf4830;	// NOTE: placeholder name
string intToString(int value);
string &padLeft(string &str, unsigned int width, char c);	// NOTE: placeholder name (0x408090)

class OpW6_Item	// NOTE: placeholder name (Item)
{
public:
	int getField4578a0();	// NOTE: placeholder name (folded getter)
	int getField457820();	// NOTE: placeholder name (folded getter)
	bool unknown457d70();	// NOTE: placeholder name
	bool unknown458220();	// NOTE: placeholder name
	bool unknown457cf0();	// NOTE: placeholder name
	int getEffectValue(int type);	// NOTE: placeholder name (0x457be0)
	int getEffect(int type);	// NOTE: placeholder name (0x457b70)
	int unknown577350();	// NOTE: placeholder name
	struct OpW6_ItemData *getData();	// NOTE: placeholder name (folded +8 getter 0x9b4350)
	XColor *getColor577260();	// NOTE: placeholder name
	int unknown573c90(string &name);	// NOTE: placeholder name
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	int unknown5745d0(string &name);	// NOTE: placeholder name
	XColor *unknown5755f0(int a);	// NOTE: placeholder name
	int unknown457a30();	// NOTE: placeholder name
	int unknown457ab0();	// NOTE: placeholder name
	bool unknown457db0();	// NOTE: placeholder name
	int getField457880();	// NOTE: placeholder name (folded getter)
	int unknown577ad0();	// NOTE: placeholder name
};

class HEntity;
class OpW6_Entity	// NOTE: placeholder name (Entity)
{
public:
	int unknown5c7fc0(HEntity other);	// NOTE: placeholder name (relation to other)
	struct OpW6_EntityData *getData();	// NOTE: placeholder name (folded +8 getter 0x9b4350)
	XColor *unknown5c7810();	// NOTE: placeholder name (display colour)
	int unknown45a2e0(const Pos &pos);	// NOTE: placeholder name (glyph at offset)
	string *getName416f40();	// NOTE: placeholder name (folded +0xc getter)
	int getSize();	// NOTE: placeholder name (0x45a360)
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	OpW6_Entity *operator->() const;	// 0x9b6570
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	OpW6_Item *operator->() const;	// 0x9b65b0
	bool operator==(HItem other) const;	// 0x9b78e0
	bool isNull() const;
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp() throw();
	bool isValid() const;
	bool isNull() const;
	OpW6_Item *operator->() const;	// 0x9b65b0
};

class OpW6_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
	int getTurn();	// NOTE: placeholder name (0x464270)
	int unknown7161e0();	// NOTE: placeholder name
	int unknown464290();	// NOTE: placeholder name
	class OpW6_SearchGrid *unknown463e70();	// NOTE: placeholder name
	int unknown4638e0(int a, int b);	// NOTE: placeholder name
};
extern OpW6_World *opw6_world;	// NOTE: placeholder name

//==================================================================
// CPolymindInfo
//==================================================================

class CPolymindInfo : public Console
{
public:
	CPolymindInfo(XConsole *parent);	// 0x4a0080
	virtual ~CPolymindInfo() {};	// 0x4a0270
	virtual void update();	// 0x4a0200
	void refresh(bool animate);	// NOTE: placeholder name (0x4a0290)

	Console *unknown6c;	// NOTE: placeholder name
};

CPolymindInfo::CPolymindInfo(XConsole *parent)
	: Console(parent,Rect(0,-20,36,20),0,false,-1)
{
	unknown6c = new Console(this,36,50,0,0,0,true,-1);
	refresh(true);
	opw6_playSound(0x139,0,0);
	setTitle(new ConsoleTitle(this,"\\ S T A T S \\",0,2));
	animate("CList_Border");
	unknown60 = 1;
}

void CPolymindInfo::update()
{
	if (isHidden())
		return;
	if (unknown60 == 1 && !engine->update())
		unknown60 = 3;
	engine->update();
	refresh(unknown60 != 3);
	updateBase429e30();
}

//==================================================================
// CPolymindButton
//==================================================================

class CPolymindButton : public Console
{
public:
	CPolymindButton(XConsole *parent);	// 0x4a16a0
};

CPolymindButton::CPolymindButton(XConsole *parent)
	: Console(parent,gameString_d32cfc.size(),1,parent->getWidth44b0d0() - 2 - gameString_d32cfc.size(),1,0,false,-1)
{
	setFore(*opw6_cf44c0);
	print(0,0,gameString_d32cfc);
	setForeRow(1,0,5,*opw6_d2981c);
	setForeRow(8,0,1,*opw6_d2981c);
}

//==================================================================
// CPolymindSuspicion
//==================================================================

class CPolymindSuspicion : public Console
{
public:
	CPolymindSuspicion(XConsole *parent);	// 0x4a17a0
	virtual ~CPolymindSuspicion() {};	// 0x4a1820
	virtual void update();	// 0x4a17f0
	int getRequiredWidth();	// NOTE: placeholder name (0x4a1840)
	void refresh();	// NOTE: placeholder name (0x4a1920)
};

CPolymindSuspicion::CPolymindSuspicion(XConsole *parent)
	: Console(parent,Rect(0,0,30,3),0,false,-1)
{
}

void CPolymindSuspicion::update()
{
	resize(getRequiredWidth(),3);
	refresh();
}

int CPolymindSuspicion::getRequiredWidth()
{
	const string &label = string("Suspicion");
	return floatToString(opw6_cf46f8,1,1).size() + (gameStrings_d21e90[opw6_unknown434b90((int)opw6_cf46f8)].size() + label.size() + 6);
}

void CPolymindSuspicion::refresh()
{
	int offset = getParent4()->getWidth44b0d0();
	setPos(offset,0);
	bool active = opw6_cf4700 && !opw6_world->unknown4638e0(0,3);
	offset = 2;
	setFore(active ? *opw6_d2981c : *opw6_cfc174);
	string label = "Suspicion";
	print(offset,1,label);
	offset = offset + label.size() + 1;
	int tier = opw6_unknown434b90((int)opw6_cf46f8);
	label = gameStrings_d21e90[tier];
	setFore(*opw6_cfe674);
	print(offset,1,label);
	setBackRow(offset,1,label.size(),active ? opw6_d29ae0[tier] : *opw6_cfc174);
	offset = offset + label.size() + 1;
	setFore(active ? opw6_d29ae0[tier] : *opw6_cfc174);
	print(offset,1,floatToString(opw6_cf46f8,1,1));
	unknown7b0640(0,active ? *opw6_cf6b24 : *opw6_d29758,1,0);
}

//==================================================================
// CPolymind
//==================================================================

class CPolymind : public Console
{
public:
	CPolymind(XConsole *parent);	// 0x4a1c90
	virtual ~CPolymind() {};	// 0x4a1e50
	virtual void update();	// 0x4a1de0
	int getX();	// NOTE: placeholder name (0x4a1c20)
	int getY();	// NOTE: placeholder name (0x4a1c30)
	int getRequiredWidth();	// NOTE: placeholder name (0x4a1e90)
	void toggleInfo();	// NOTE: placeholder name (0x4a1ec0)
	void refresh();	// NOTE: placeholder name (0x4a1f80)
	bool unknown87afd0();	// NOTE: placeholder name

	CPolymindButton *button;	// NOTE: placeholder name
	CPolymindInfo *info;	// NOTE: placeholder name
	CPolymindSuspicion *suspicion;	// NOTE: placeholder name
	string unknown78;	// NOTE: placeholder name
	string unknown94;	// NOTE: placeholder name
};

int CPolymind::getX()
{
	return opw6_fontCellWidth;
}

int CPolymind::getY()
{
	return opw6_mapView->getPos().y + opw6_mapView->getHeight()*opw6_fontCellScale - opw6_fontCellScale - 3 - opw6_cefac4*opw6_fontCellScale;
}

CPolymind::CPolymind(XConsole *parent)
	: Console(parent,Rect(getX(),getY(),34,3),0,false,3)
	, info	(NULL)
{
	button = new CPolymindButton(this);
	suspicion = new CPolymindSuspicion(this);
	update();
}

void CPolymind::update()
{
	if (isHidden())
		return;
	setPos(getX(),getY());
	if (unknown87afd0())
	{
		resize(getRequiredWidth(),3);
		refresh();
	}
	updateBase429e30();
}

int CPolymind::getRequiredWidth()
{
	return unknown78.size() + unknown94.size() + 34;
}

void CPolymind::toggleInfo()
{
	if (info)
	{
		opw6_playSound(0x28,0,0);
		removeSubconsole(info);
		info = NULL;
	}
	else
		info = new CPolymindInfo(opw6_cec06c);
}

void CPolymind::refresh()
{
	clear();
	int x = 2;
	setFore(*opw6_cfe674);
	print(x,1,unknown78);
	setBackRow(x,1,unknown78.size(),*opw6_cf6b24);
	setFore(*opw6_d2981c);
	x += unknown78.size();
	print(x,1," Protomatter ");
	x += 13;
	setFore(*opw6_cfe674);
	print(x,1," % ");
	setBackRow(x,1,3,*opw6_d25f60);
	x += 4;
	setFore(*opw6_d2981c);
	print(x,1,unknown94);
	x += unknown94.size();
	x += 2;
	button->setPos(x,1);
	unknown7b0640(0,*opw6_cf6b24,1,0);
}

//==================================================================
// CHudRif
//==================================================================

class CHudRif : public Console
{
public:
	CHudRif(XConsole *parent);	// 0x4a21c0
	virtual bool mouseEnter();	// 0x4a2400
	virtual void mouseLeave();	// 0x4a2430
	virtual void update();	// 0x4a23a0
	void refresh();	// NOTE: placeholder name (0x4a2280)

	int count;	// NOTE: placeholder name
};

CHudRif::CHudRif(XConsole *parent)
	: Console(parent,Rect(opw6_d3846c - 8,opw6_d38470 - ((unknown4328a0() != 0) + 1),8,1),0,true,parent->getLayer() + 2)
{
	count = opw6_cf4a14.size();
	refresh();
}

void CHudRif::refresh()
{
	print(0,0,"[RIF_" + padLeft(intToString(count),2,'0') + "]");
	animate("A_CHudRif_Color");
}

void CHudRif::update()
{
	if (isHidden())
		return;
	engine->update();
	if (count != opw6_cf4a14.size())
	{
		count = opw6_cf4a14.size();
		refresh();
	}
	updateBase429e30();
}

bool CHudRif::mouseEnter()
{
	animate("A_CHudRif_Hover");
	return true;
}

void CHudRif::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_CHudRif_Color");
}

//==================================================================
// CHudData / CHud
//==================================================================

class CHudData : public Console
{
public:
	CHudData(XConsole *parent, const Rect &rect, int type);	// 0x4a2480
	virtual ~CHudData() {};	// 0x4a24d0

	int type;	// NOTE: placeholder name
};

CHudData::CHudData(XConsole *parent, const Rect &rect, int type_)
	: Console(parent,rect,0,false,-1)
{
	type = type_;
}

class CHud : public Console
{
public:
	virtual ~CHud();	// 0x4a2520
	int getBottom();	// NOTE: placeholder name (0x4a2560)

	char pad6c[0x70 - 0x6c];
	XConsole *unknown70;	// NOTE: placeholder name
};

int CHud::getBottom()
{
	return unknown70->getPos().y + unknown70->getHeight();
}

CHud::~CHud()
{
}

//==================================================================
// CScanButton / CScanText / CScan
//==================================================================

class CScanButton : public Console
{
public:
	CScanButton(XConsole *parent, int x, int y, int type);	// 0x4a25c0
	virtual bool mouseEnter();	// 0x4a26f0
	virtual void mouseLeave();	// 0x4a2720

	int type;	// NOTE: placeholder name
};

CScanButton::CScanButton(XConsole *parent, int x, int y, int type_)
	: Console(parent,gameStrings_d20620[type_ - 0x8c].size(),1,x,y,0,false,-1)
{
	type = type_;
	setFore(*opw6_d2981c);
	print(0,0,gameStrings_d20620[type - 0x8c]);
	setFore_417f80(0,0,*opw6_cf44c0);
	setFore_417f80(1,0,*opw6_d20b70);
	setFore_417f80(getWidth44b0d0() - 1,0,*opw6_cf44c0);
}

bool CScanButton::mouseEnter()
{
	animate("A_ButtonHover_Begin_SCAN_HOV_OK");
	return true;
}

void CScanButton::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_SCAN_HOV_OK");
}

class CScan : public Console
{
public:
	virtual ~CScan();	// 0x4a2b10
};

class OpW6_ScanRows : public Console	// NOTE: placeholder name
{
public:
	void clearRows();	// NOTE: placeholder name (0x4a2770)

	vector<XConsole*> rows;	// NOTE: placeholder name
};

void OpW6_ScanRows::clearRows()
{
	for (unsigned int i = 0; i < rows.size(); i++)
		rows[i]->clearBack();
}

class CScanText : public Console
{
public:
	CScanText(XConsole *parent, int x, int y, int width, string text, HItem item_, HEntity entity_);	// 0x4a27c0
	void setStyle(bool dark, bool silent, bool cell);	// NOTE: placeholder name (0x4a28d0)

	HItem item;	// NOTE: placeholder name
	HEntity entity;	// NOTE: placeholder name
};

CScanText::CScanText(XConsole *parent, int x, int y, int width, string text, HItem item_, HEntity entity_)
	: Console(parent,width,1,x,y,0,false,-1)
{
	item = item_;
	entity = entity_;
	if (text.size() > getWidth44b0d0())
		text.erase(text.begin() + getWidth44b0d0(),text.end());
	print(0,0,text);
}

void CScanText::setStyle(bool dark, bool silent, bool cell)
{
	if (cell)
		animate(dark ? "A_CScan_Cell_Dk" : "A_CScan_Cell");
	else if (dark)
		animate("A_CScan_Text_Dk");
	else if (entity.isValid())
	{
		switch (entity->unknown5c7fc0(opw6_world->getPlayer()))
		{
			case 0: animate("A_CScan_Text_Hostile"); break;
			case 1: animate("A_CScan_Text_Neutral"); break;
			case 2: animate("A_CScan_Text_Friendly"); break;
		}
	}
	else if (item.isValid())
	{
		if (item->getField4578a0() == 5)
			animate("A_CScan_Text_Item");
		else if (opw6_cf4830[item->getField457820()] != 0 && !item->unknown457d70())
			animate("A_CScan_Text_Broken");
		else
			animate("A_CScan_Text_Part");
	}
	else if (silent)
		animate("A_CScan_Text_Silent");
	else
		animate("A_CScan_Text_Terrain");
}

CScan::~CScan()
{
}

//==================================================================
// scan colours
//==================================================================

// NOTE: the original indexes two global arrays (XColor[5] at 0xd20504, string[5] at 0xcfb7b8) with
//	constants; each element is declared separately here so every address operand names a symbol.
extern XColor opw6_d20504, opw6_d20507, opw6_d2050a, opw6_d2050d, opw6_d20510;	// NOTE: placeholder names
extern string opw6_cfb7b8, opw6_cfb7d4, opw6_cfb7f0, opw6_cfb80c, opw6_cfb828;	// NOTE: placeholder names
extern XColor *opw6_d2b284;	// NOTE: placeholder name
extern XColor *opw6_cf27e8;	// NOTE: placeholder name
extern XColor *opw6_d1dae0;	// NOTE: placeholder name
extern XColor *opw6_d20438;	// NOTE: placeholder name
extern XColor *opw6_d201c4;	// NOTE: placeholder name

void opw6_initScanColors()	// NOTE: placeholder name (0x4a2b60)
{
	opw6_d20504 = *opw6_d2b284;
	opw6_d20507 = *opw6_cf27e8;
	opw6_d2050a = *opw6_d1dae0;
	opw6_d2050d = *opw6_d20438;
	opw6_d20510 = *opw6_d201c4;
	opw6_cfb7b8 = "AZ4";
	opw6_cfb7d4 = "OR3";
	opw6_cfb7f0 = "CY3";
	opw6_cfb80c = "YE3";
	opw6_cfb828 = "PU3";
}

//==================================================================
// CEvasion / CEvasionFull
//==================================================================

class HExplosive	// NOTE: placeholder layout
{
public:
	int ID;
};

class CEvasion : public Console
{
public:
	virtual ~CEvasion();	// 0x4a2c30

	char pad6c[0x78 - 0x6c];
	vector<string> unknown78;	// NOTE: placeholder name
	vector<unsigned int> unknown88;	// NOTE: placeholder name
	vector<bool> unknown98;	// NOTE: placeholder name
	int unknownAc;	// NOTE: placeholder name
	string unknownB0;	// NOTE: placeholder name
};

CEvasion::~CEvasion()
{
}

class CEvasionFull : public Console
{
public:
	virtual ~CEvasionFull();	// 0x4a2d00
};
extern CEvasionFull *opw6_cec080;	// NOTE: placeholder name

CEvasionFull::~CEvasionFull()
{
	opw6_cec080 = NULL;
}

//==================================================================
// CVolleyButton / CVolley / CPartsButton
//==================================================================

extern XColor *opw6_d25e0c;	// NOTE: placeholder name
extern char opw6_b6f3e3[];	// NOTE: placeholder name

class CVolleyButton : public Console
{
public:
	CVolleyButton(XConsole *parent, int x, int range);	// 0x4a2d60
	void setHighlight(bool on);	// NOTE: placeholder name (0x4a2de0)

	int range;	// NOTE: placeholder name
};

CVolleyButton::CVolleyButton(XConsole *parent, int x, int range_)
	: Console(parent,1,1,x,0,0,false,-1)
{
	range = range_;
	setHighlight(false);
}

void CVolleyButton::setHighlight(bool on)
{
	putChar_418110(0,0,opw6_b6f3e3[range],on ? *opw6_d25e0c : *opw6_cf6b24);
}

class CVolley : public Console
{
public:
	virtual ~CVolley();	// 0x4a2e40

	char pad6c[0x78 - 0x6c];
	vector<HExplosive> unknown78;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
	vector<unsigned int> unknown8c;	// NOTE: placeholder name
};

CVolley::~CVolley()
{
}

class CPartsButton : public Console
{
public:
	CPartsButton(XConsole *parent, int x, int type);	// 0x4a2ef0
	virtual void mouseLeave();	// 0x4a2f30

	int type;	// NOTE: placeholder name
};

CPartsButton::CPartsButton(XConsole *parent, int x, int type_)
	: Console(parent,1,1,x,0,0,false,-1)
{
	type = type_;
}

void CPartsButton::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_PART_HOV_OK");
}

class OpW6_PartsRow : public Console	// NOTE: placeholder name
{
public:
	void unknown88b680();	// NOTE: placeholder name
};

class OpW6_PartsRows : public Console	// NOTE: placeholder name
{
public:
	void refreshRows();	// NOTE: placeholder name (0x4a2f80)

	vector<OpW6_PartsRow*> rows;	// NOTE: placeholder name
};

void OpW6_PartsRows::refreshRows()
{
	for (unsigned int i = 0; i < rows.size(); i++)
		rows[i]->unknown88b680();
}

int opw6_getItemState(HItem item)	// NOTE: placeholder name (0x4a2fd0)
{
	return item->unknown458220() ? 2 : item->unknown457cf0() != 0;
}

//==================================================================
// HUD value readouts (0x4a6240-0x4a6d00)
//==================================================================

extern int opw6_cf6474;	// NOTE: placeholder name
extern int opw6_cf645c;	// NOTE: placeholder name
extern int opw6_cf6428;	// NOTE: placeholder name
int opw6_unknown433260(int value);	// NOTE: placeholder name

class OpW6_HudValue : public Console	// NOTE: placeholder name (several CHud* readouts share this shape)
{
public:
	void setValue4a6240(int value_);	// NOTE: placeholder name
	void setValue4a6360(int value_);	// NOTE: placeholder name
	void setValue4a6630(int value_);	// NOTE: placeholder name
	void setValue4a6940(int value_);	// NOTE: placeholder name
	void setValue4a6a30(int value_);	// NOTE: placeholder name
	void setValue4a6d20(int value_);	// NOTE: placeholder name
	void setValue4a7150(int value_);	// NOTE: placeholder name
	void setValue4a7700(int value_);	// NOTE: placeholder name
	void setValue4a79f0(int value_);	// NOTE: placeholder name
	int getItemValue4a7db0(HItem item);	// NOTE: placeholder name
	void setValue4a7e00(int value_);	// NOTE: placeholder name
	int getMode4a6cb0();	// NOTE: placeholder name
	void setTurn4a6d00();	// NOTE: placeholder name

	char pad6c[0x70 - 0x6c];
	int value;	// NOTE: placeholder name
};

void OpW6_HudValue::setValue4a6240(int value_)
{
	value = value_;
	print(getWidth44b0d0() - 2,0,value > 9 ? "*" : intToString(value));
}

void OpW6_HudValue::setValue4a6360(int value_)
{
	value = value_;
	print(getWidth44b0d0() - 3,0,value > 99 ? "**" : (value > 9 ? intToString(value) : "0" + intToString(value)));
}

void OpW6_HudValue::setValue4a6630(int value_)
{
	value = value_;
	print(getWidth44b0d0() - 4,0,(value > 99 ? "**" : (value > 9 ? intToString(value) : "0" + intToString(value))) + "%");
}

void OpW6_HudValue::setValue4a6940(int value_)
{
	value = value_;
	clear();
	setFore(*opw6_d2981c);
	print(0,0,intToString(value) + "%");
}

void OpW6_HudValue::setValue4a6a30(int value_)
{
	int previous = value;
	value = value_;
	print(getWidth44b0d0() - 2,0,value == 0 ? "L" : (value == 6 ? "H" : intToString(value)));
	if (value > previous)
		opw6_playSound(0x53,0,0);
}

int OpW6_HudValue::getMode4a6cb0()
{
	return opw6_cf6474 ? 7 : (opw6_cf645c ? 6 : opw6_unknown433260(opw6_cf6428));
}

void OpW6_HudValue::setTurn4a6d00()
{
	value = opw6_world->getTurn();
}

void OpW6_HudValue::setValue4a6d20(int value_)
{
	value = value_;
	print(getWidth44b0d0() - 4,0,value > 999 ? "***" : (value > 99 ? intToString(value) : (value > 9 ? "0" + intToString(value) : "00" + intToString(value))));
}

void OpW6_HudValue::setValue4a7150(int value_)
{
	value = value_;
	print(getWidth44b0d0() - 8,0,value > 9 ? "*" : intToString(value));
	if (value == 8)
		print(getWidth44b0d0() - 5,0,"MAX");
	else
	{
		int next = opw6_world->unknown7161e0();
		print(getWidth44b0d0() - 5,0,next > 999 ? "***" : (next > 99 ? intToString(next) : (next > 9 ? "0" + intToString(next) : "00" + intToString(next))));
	}
}

void OpW6_HudValue::setValue4a7700(int value_)
{
	value = value_;
	print(getWidth44b0d0() - 3,0,value > 99 ? "**" : (value > 9 ? intToString(value) : "0" + intToString(value == -1 ? 0 : value)));
}

void OpW6_HudValue::setValue4a79f0(int value_)
{
	value = value_;
	print(getWidth44b0d0() - 3,0,value > 99 ? "**" : (value > 9 ? intToString(value) : (value == 0 ? "OK" : "0" + intToString(value))));
}

class OpW6_Unkd225a0	// NOTE: placeholder name (object at 0xd225a0)
{
public:
	int unknown672a20(HItem item);	// NOTE: placeholder name
};
extern OpW6_Unkd225a0 opw6_d225a0;	// NOTE: placeholder name
int maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)

int OpW6_HudValue::getItemValue4a7db0(HItem item)
{
	if (item->getEffectValue(0x61) == 0)
		return -1;
	else
	{
		int amount = -opw6_d225a0.unknown672a20(item);
		return maxInt(amount,0);
	}
}

void OpW6_HudValue::setValue4a7e00(int value_)
{
	value = value_;
	print(getWidth44b0d0() - 4,0,value == -1 ? "???" : (value > 999 ? "***" : (value > 99 ? intToString(value) : (value > 9 ? "0" + intToString(value) : "00" + intToString(value)))));
}

//==================================================================
// CPartAnimation
//==================================================================

extern int opw6_d31698;	// NOTE: placeholder name (parts list width)

class CPartAnimation : public Console
{
public:
	CPartAnimation(XConsole *parent, const string &name, bool multislot, int key, int type);	// 0x4a8330
};

CPartAnimation::CPartAnimation(XConsole *parent, const string &name, bool multislot, int key, int type)
	: Console(parent,opw6_d31698 - 4,1,0,0,0,false,-1)
{
	string letter;
	letter += key - 0x20;
	print(1,0,letter);
	print(5,0,name);
	switch (type)
	{
		break;	// NOTE: reproduces a dead jump after the jump table
		case 1: animate(multislot ? "A_CPartDestroyed_Multislot" : "A_CPartDestroyed_Normal"); break;
		case 2: animate(multislot ? "A_CPartForced_Multislot" : "A_CPartForced_Normal"); break;
		case 3: animate(multislot ? "A_CPartDiscarded_Multislot" : "A_CPartDiscarded_Normal"); break;
		case 4: animate(multislot ? "A_CPartRejected_Multislot" : "A_CPartRejected_Normal"); break;
		case 5: animate(multislot ? "A_CPartReleased_Multislot" : "A_CPartReleased_Normal"); break;
		case 6: animate(multislot ? "A_CPartExpended_Melted_Multislot" : "A_CPartExpended_Melted_Normal"); break;
		case 7: animate(multislot ? "A_CPartExpended_System_Multislot" : "A_CPartExpended_System_Normal"); break;
		case 8: animate(multislot ? "A_CPartFried_Multislot" : "A_CPartFried_Normal"); break;
		case 9: animate(multislot ? "A_CPartFried_MultislotUsed" : "A_CPartFried_NormalUsed"); break;
		case 10: animate(multislot ? "A_CPartTransformed_Multislot" : "A_CPartTransformed_Normal"); break;
		case 11: animate(multislot ? "A_CPartFused_Multislot" : "A_CPartFused_Normal"); break;
		case 12: animate(multislot ? "A_CPartDisrupted_Multislot" : "A_CPartDisrupted_Normal"); break;
	}
}

//==================================================================
// CPartDamaged / CPartSorted / CPartConfirming
//==================================================================

extern string opw6_listOptionNames[];	// NOTE: placeholder name (0xcf35c0)
extern Pos opw6_cfbec0;	// NOTE: placeholder name
void opw6_findAnimation(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)

class CPartDamaged : public Console
{
public:
	CPartDamaged(XConsole *parent, HItem item, bool multislot);	// 0x4a8760
};

CPartDamaged::CPartDamaged(XConsole *parent, HItem item, bool multislot)
	: Console(parent,1,1,3,0,0,false,-1)
{
	animate((multislot ? "A_CPartDamaged_Multislot_" : "A_CPartDamaged_Normal_") + opw6_listOptionNames[item->unknown577350()]);
}

class CPartSorted : public Console
{
public:
	CPartSorted(XConsole *parent);	// 0x4a8820
};

CPartSorted::CPartSorted(XConsole *parent)
	: Console(parent,opw6_d31698 - 4,1,0,0,0,false,-1)
{
	animate("A_CPartSorted");
}

class CPartConfirming : public Console
{
public:
	CPartConfirming(XConsole *parent, HItem item_, const string &name, int key, bool temporary);	// 0x4a88c0

	HItem item;	// NOTE: placeholder name
};

CPartConfirming::CPartConfirming(XConsole *parent, HItem item_, const string &name, int key, bool temporary)
	: Console(parent,opw6_d31698 - 4,1,0,0,0,false,-1)
{
	item = item_;
	resetBack_418450();
	if (item->getEffect(0x6e))
		putChar_4180b0(0,0,'f');
	else
		putChar_4180b0(0,0,':');
	string letter;
	letter += key - 0x20;
	print(1,0,letter);
	int animIndex;
	opw6_findAnimation(temporary ? "CPartConfirm_Temp_Ref" : "CPartConfirm_Dstry_Ref",&animIndex);
	if (animIndex)
	{
		do
		{
			for (int x = Pos(0,0).x; x < Pos(0,0).x + 3; x++)
				engine->unknown50fb50(engine,animIndex,&Pos(x,Pos(0,0).y),&opw6_cfbec0,NULL,NULL,9)->unknown50de10();
		} while (false);
	}
	print(5,0,name);
	opw6_findAnimation(temporary ? "CPartConfirm_Temp_Name" : "CPartConfirm_Dstry_Name",&animIndex);
	if (animIndex)
	{
		do
		{
			for (unsigned int x = Pos(5,0).x; x < Pos(5,0).x + name.size(); x++)
				engine->unknown50fb50(engine,animIndex,&Pos(x,Pos(5,0).y),&opw6_cfbec0,NULL,NULL,9)->unknown50de10();
		} while (false);
	}
}

//==================================================================
// CPart
//==================================================================

struct OpW6_ItemData	// NOTE: placeholder name (item definition record)
{
	char pad00[0x94];
	int unknown94;	// NOTE: placeholder name
	char pad98[0x1ac - 0x98];
	bool unknown1ac;	// NOTE: placeholder name
};

class OpW6_PartBar : public Console	// NOTE: placeholder name (0x98 bytes)
{
public:
	OpW6_PartBar(XConsole *parent, int unknown);	// 0x88b970
	void unknown88bab0(bool flag);	// NOTE: placeholder name

	char pad6c[0x70 - 0x6c];
	int unknown70;	// NOTE: placeholder name
	char pad74[0x98 - 0x74];
};

extern int opw6_cf462c;	// NOTE: placeholder name
extern int opw6_bcc2e0;	// NOTE: placeholder name
bool opw6_truncate408220(string &text, unsigned int length, int unknown);	// NOTE: placeholder name
string &opw6_padRight4080d0(string &text, unsigned int width, char c);	// NOTE: placeholder name

class CPart : public Console
{
public:
	CPart(XConsole *parent, int y, HItem item_, bool unknown70_, HItem unknown74_, int unknown7c_, int key_);	// 0x4a8bd0
	void drawStatus(bool damaged);	// NOTE: placeholder name (0x4a8e70)
	void unknown4a8f90(bool flag);	// NOTE: placeholder name
	void drawName(bool flag);	// NOTE: placeholder name (0x4a8fe0)
	string getName8900d0();	// NOTE: placeholder name
	bool isHovered();	// NOTE: placeholder name (0x4a9150)
	void confirm(bool temporary);	// NOTE: placeholder name (0x4a9250)
	bool cancelConfirm();	// NOTE: placeholder name (0x4a93a0)
	virtual bool mouseEnter();	// 0x4a93f0
	virtual void mouseLeave();	// 0x4a9450
	void blitTo(XConsole *target);	// NOTE: placeholder name (0x4a94d0)

	HItem item;	// NOTE: placeholder name
	bool unknown70;	// NOTE: placeholder name
	HItem unknown74;	// NOTE: placeholder name
	bool unknown78;	// NOTE: placeholder name
	int unknown7c;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	bool unknown88;	// NOTE: placeholder name
	int unknown8c;	// NOTE: placeholder name
	XConsole *unknown90;	// NOTE: placeholder name
	OpW6_PartBar *unknown94;	// NOTE: placeholder name
	XConsole *unknown98;	// NOTE: placeholder name
	int unknown9c;	// NOTE: placeholder name
	CPartConfirming *confirming;	// NOTE: placeholder name
};

CPart::CPart(XConsole *parent, int y, HItem item_, bool unknown70_, HItem unknown74_, int unknown7c_, int key_)
	: Console(parent,opw6_d31698 - 4,1,2,y,0,false,-1)
{
	item = item_;
	unknown70 = unknown70_;
	unknown74 = unknown74_;
	unknown78 = false;
	unknown7c = unknown7c_;
	key = key_;
	unknown84 = -1;
	unknown88 = false;
	unknown90 = NULL;
	unknown94 = NULL;
	unknown98 = NULL;
	unknown9c = 0;
	confirming = NULL;
	if (item.isValid())
	{
		if (item->getEffect(0x6c) || opw6_cf462c == 0xb)
			putChar_4180b0(0,0,'x');
		else if (item->getData()->unknown94 == 2)
			putChar_4180b0(0,0,'&');
		else if (item->getData()->unknown1ac)
			putChar_4180b0(0,0,':');
		else if (item->getEffect(0x6e))
			putChar_4180b0(0,0,'f');
	}
	string letter;
	letter += key - 0x20;
	print(1,0,letter);
	drawStatus(false);
	drawName(false);
	if (item.isValid() && !unknown70)
		unknown94 = new OpW6_PartBar(this,0);
}

void CPart::drawStatus(bool damaged)
{
	if (item.isValid())
	{
		if (!unknown70)
		{
			putChar_418110(3,0,0xb3,*item->getColor577260());
			if (unknown94 && unknown94->unknown70 == 2)
				unknown94->unknown88bab0(false);
		}
		if (damaged)
		{
			new CPartDamaged(this,item,unknown70);
			unknown84 = opw6_world->unknown464290();
		}
	}
}

void CPart::unknown4a8f90(bool flag)
{
	if (unknown94)
		unknown94->unknown88bab0(flag);
}

void CPart::drawName(bool flag)
{
	string name = getName8900d0();
	int value = 0;
	if (item.isValid() && !unknown70)
		value = item->unknown573c90(name);
	opw6_truncate408220(name,opw6_d31698 - 9 - opw6_bcc2e0 - 1,value);
	unknown8c = name.size() + 4;
	opw6_padRight4080d0(name,opw6_d31698 - 9 - opw6_bcc2e0 - 1,' ');
	if (flag)
		setString_418010(5,0,name);
	else
		print(5,0,name);
}

class OpW6_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool isOver(XConsole *console);	// NOTE: placeholder name (0x41a760)
};
extern OpW6_Mouse *opw6_mouse;	// NOTE: placeholder name

bool CPart::isHovered()
{
	return opw6_mouse->isOver(this) || (unknown90 && opw6_mouse->isOver(unknown90)) || (unknown94 && opw6_mouse->isOver(unknown94)) || (unknown98 && opw6_mouse->isOver(unknown98));
}

void CPart::confirm(bool temporary)
{
	if (confirming)
	{
		removeSubconsole(confirming);
		confirming = NULL;
	}
	confirming = new CPartConfirming(this,item,getName8900d0(),key,temporary);
}

bool CPart::cancelConfirm()
{
	bool wasConfirming = confirming;
	if (confirming)
	{
		removeSubconsole(confirming);
		confirming = NULL;
	}
	return wasConfirming;
}

bool CPart::mouseEnter()
{
	if (item.isValid())
		animate("A_ButtonHover_Begin_PART_HOV_OK");
	else
		animate("A_CPart_Empty_Hover");
	return true;
}

void CPart::mouseLeave()
{
	engine->killGroup("fadein");
	if (item.isValid())
		animate("A_ButtonHover_End_PART_HOV_OK");
	else
		animate("A_CPart_Empty_Hover_End");
}

void CPart::blitTo(XConsole *target)
{
	unknown429fe0(target,Pos(0,0),0);
	if (unknown90)
		unknown90->unknown429fe0(target,unknown90->getPos(),0);
	if (unknown94)
		unknown94->unknown429fe0(target,unknown94->getPos(),0);
	if (unknown98)
		unknown98->unknown429fe0(target,unknown98->getPos(),0);
}

//==================================================================
// CPartsCycle / CPartsCycleModal / CTactical / CSigixExoskeleton
//==================================================================

extern int opw6_bcca28[];	// NOTE: placeholder name
extern bool opw6_bcca38[];	// NOTE: placeholder name
extern int opw6_bcca3c[];	// NOTE: placeholder name
extern int opw6_bcca5c[];	// NOTE: placeholder name

class CPartsCycle : public Console
{
public:
	CPartsCycle(XConsole *parent, int type_, int y);	// 0x4a95a0
	virtual bool mouseEnter();	// 0x4a9690
	virtual void mouseLeave();	// 0x4a96c0

	int type;	// NOTE: placeholder name
};

CPartsCycle::CPartsCycle(XConsole *parent, int type_, int y)
	: Console(parent,Rect(opw6_bcca28[type_],y,7,1),0,true,5)
{
	type = type_;
	print(0,0,"[CYCLE]");
	animate("A_CPartsCycle_Color");
}

bool CPartsCycle::mouseEnter()
{
	animate("A_CPartsCycle_Hover");
	return true;
}

void CPartsCycle::mouseLeave()
{
	engine->killGroup("fadein");
	animate("A_CPartsCycle_Color");
}

class CPartsCycleModal : public Console
{
public:
	CPartsCycleModal(XConsole *parent, int mode_, int x, int y, int height);	// 0x4a9710
	virtual bool mouseEnter();	// 0x4a97b0
	virtual void mouseLeave();	// 0x4a97f0
	void refresh();	// NOTE: placeholder name (0x4a9830)

	int mode;	// NOTE: placeholder name
};

CPartsCycleModal::CPartsCycleModal(XConsole *parent, int mode_, int x, int y, int height)
	: Console(parent,Rect(x,y,1,height),0,false,5)
{
	mode = mode_;
	refresh();
}

bool CPartsCycleModal::mouseEnter()
{
	if (mode == 0)
		return false;
	animate("A_CPartsCycModal_Hover");
	return true;
}

void CPartsCycleModal::mouseLeave()
{
	if (mode == 0)
		return;
	engine->killGroup("fadein");
	refresh();
}

void CPartsCycleModal::refresh()
{
	animate(opw6_bcca38[mode] ? "A_CPartsCycModal_Bright" : "A_CPartsCycModal");
}

class CTactical : public Console
{
public:
	CTactical(XConsole *parent, int type_);	// 0x4a9880

	int type;	// NOTE: placeholder name
};

CTactical::CTactical(XConsole *parent, int type_)
	: Console(parent,Rect(opw6_bcca3c[type_],0,opw6_bcca5c[type_],1),0,false,10)
{
	type = type_;
}

class CSigixExoskeleton : public Console
{
public:
	CSigixExoskeleton(XConsole *parent);	// 0x4a98e0

	int unknown6c;	// NOTE: placeholder name
};

CSigixExoskeleton::CSigixExoskeleton(XConsole *parent)
	: Console(parent,Rect(2,parent->getHeight() - 2,parent->getWidth44b0d0() - 4,1),0,false,-1)
{
	unknown6c = -1;
}

//==================================================================
// CParts
//==================================================================

struct OpW6_PartsEntryA { int data; };	// NOTE: placeholder name
struct OpW6_PartsEntryB { int data; };	// NOTE: placeholder name

class CParts : public Console
{
public:
	virtual ~CParts();	// 0x4a9950
	bool findParts(HItem item, vector<CPart*> &out);	// NOTE: placeholder name (0x4a9a40)
	bool isLinked4a9b10(HItem item);	// NOTE: placeholder name
	void toggleTimer4a9bf0();	// NOTE: placeholder name
	void setTimed4a9c30(HItem item);	// NOTE: placeholder name
	void confirm4a9cf0(HItem item);	// NOTE: placeholder name
	void confirm4a9d40(HItem item);	// NOTE: placeholder name
	void confirm4a9d90(HItem item);	// NOTE: placeholder name
	bool cancelConfirms();	// NOTE: placeholder name (0x4a9de0)
	void refreshCycles();	// NOTE: placeholder name (0x4a9e40)
	CPart *getPartByKey(int key);	// NOTE: placeholder name (0x4a9e90)
	CPart *unknown894e70(HItem item);	// NOTE: placeholder name
	int unknown8a0df0(int key);	// NOTE: placeholder name

	char pad6c[0x74 - 0x6c];
	vector<CPart*> parts;	// NOTE: placeholder name
	char pad84[0x94 - 0x84];
	vector<CPartsCycleModal*> cycles;	// NOTE: placeholder name
	char padA4[0xb8 - 0xa4];
	unsigned int unknownB8;	// NOTE: placeholder name
	char padBC[0xd4 - 0xbc];
	vector<OpW6_PartsEntryA> unknownD4;	// NOTE: placeholder name
	char padE4[0xe8 - 0xe4];
	vector<unsigned int> unknownE8;	// NOTE: placeholder name
	unsigned int unknownF8;	// NOTE: placeholder name (padding)
	unsigned int unknownFC;	// NOTE: placeholder name
	HItem unknown100;	// NOTE: placeholder name
	char pad104[0x108 - 0x104];
	vector<OpW6_PartsEntryB> unknown108;	// NOTE: placeholder name
	vector<unsigned int> unknown118;	// NOTE: placeholder name
	vector<unsigned int> unknown128;	// NOTE: placeholder name
	char pad138[0x140 - 0x138];
	string unknown140;	// NOTE: placeholder name
	HItem unknown15c;	// NOTE: placeholder name (padding)
	HItem unknown160;	// NOTE: placeholder name
	unsigned int unknown164;	// NOTE: placeholder name
	HItem unknown168;	// NOTE: placeholder name
	unsigned int unknown16c;	// NOTE: placeholder name
	HItem unknown170;	// NOTE: placeholder name
	unsigned int unknown174;	// NOTE: placeholder name
	char pad178[0x1a0 - 0x178];
	string unknown1a0;	// NOTE: placeholder name
};

CParts::~CParts()
{
}

bool CParts::findParts(HItem item, vector<CPart*> &out)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item == item)
			out.push_back(parts[i]);
	}
	return !parts.empty();
}

extern unsigned int opw6_tickCount;	// NOTE: placeholder name (0xcaed20)
extern unsigned int opw6_d28e60;	// NOTE: placeholder name

bool CParts::isLinked4a9b10(HItem item)
{
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item == item)
			return parts[i]->unknown74.isValid();
	}
	return false;
}

void CParts::toggleTimer4a9bf0()
{
	if (unknownB8)
		unknownB8 = 0;
	else
		unknownB8 = opw6_tickCount;
}

void CParts::setTimed4a9c30(HItem item)
{
	unknownFC = opw6_tickCount + opw6_d28e60;
	unknown100 = item;
}

void CParts::confirm4a9cf0(HItem item)
{
	unknown160 = item;
	unknown164 = opw6_tickCount;
	CPart *part = unknown894e70(item);
	if (part)
		part->confirm(false);
}

void CParts::confirm4a9d40(HItem item)
{
	unknown168 = item;
	unknown16c = opw6_tickCount;
	CPart *part = unknown894e70(item);
	if (part)
		part->confirm(true);
}

void CParts::confirm4a9d90(HItem item)
{
	unknown170 = item;
	unknown174 = opw6_tickCount;
	CPart *part = unknown894e70(item);
	if (part)
		part->confirm(true);
}

bool CParts::cancelConfirms()
{
	bool cancelled = false;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->cancelConfirm())
			cancelled = true;
	}
	return cancelled;
}

void CParts::refreshCycles()
{
	for (unsigned int i = 0; i < cycles.size(); i++)
		cycles[i]->refresh();
}

CPart *CParts::getPartByKey(int key)
{
	int index = unknown8a0df0(key);
	return index == -1 ? NULL : parts[index];
}

//==================================================================
// CInvsortButton
//==================================================================

class CInvsortButton : public Console
{
public:
	CInvsortButton(XConsole *parent, int x);	// 0x4a9f10

	int unknown6c;	// NOTE: placeholder name
	bool unknown70;	// NOTE: placeholder name
};

CInvsortButton::CInvsortButton(XConsole *parent, int x)
	: Console(parent,8,1,x,0,0,false,-1)
{
	unknown6c = 0;
	unknown70 = false;
	setFore(*opw6_cf6b24);
	print(0,0,"sort (t)");
}

//==================================================================
// CInventoryItem / CInventory
//==================================================================

extern int opw6_d33be8;	// NOTE: placeholder name (inventory width)
extern bool asciiEnabled;	// NOTE: placeholder name (0xd28d30)
extern XColor *opw6_cfd448;	// NOTE: placeholder name

class CInventoryItem : public Console
{
public:
	CInventoryItem(XConsole *parent, int y, int count, HItem item_, int type_);	// 0x4a9ff0
	virtual bool mouseEnter();	// 0x4aa530 (shared by several buttons)
	void setCount(int count);	// NOTE: placeholder name (0x4aa210)
	void drawBar();	// NOTE: placeholder name (0x4aa310)
	void unknown4aa3a0(bool flag);	// NOTE: placeholder name
	void drawName();	// NOTE: placeholder name (0x4aa3d0)
	void drawState();	// NOTE: placeholder name (0x4aa560)

	HItem item;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	Console *marker;	// NOTE: placeholder name
	OpW6_PartBar *bar;	// NOTE: placeholder name
};

CInventoryItem::CInventoryItem(XConsole *parent, int y, int count, HItem item_, int type_)
	: Console(parent,opw6_d33be8 - 3,1,1,y,0,false,-1)
{
	item = item_;
	type = type_;
	marker = NULL;
	bar = NULL;
	if (type < 2)
		setCount(count);
	if (type == 0)
	{
		if (asciiEnabled)
		{
			marker = new Console(this,1,1,3,0,2,false,-1);
			marker->putChar_418110(0,0,item->unknown457a30(),*item->unknown5755f0(0));
		}
		else
			putChar_418110(3,0,item->unknown457ab0(),*item->unknown5755f0(0));
		drawBar();
	}
	drawName();
	if (item->getField457880() >= 6 && type == 0)
		bar = new OpW6_PartBar(this,1);
}

void CInventoryItem::setCount(int count)
{
	print(1,0,intToString(count == 10 ? 0 : count));
	setFore_417f80(1,0,item->getField4578a0() == 5 ? *opw6_cfc174 : (type == 0 ? *opw6_d20b70 : *opw6_cfd448));
}

void CInventoryItem::drawBar()
{
	if (item->getField4578a0() != 5)
		putChar_418110((asciiEnabled != 0) + 5,0,0xb3,*item->getColor577260());
	if (bar && bar->unknown70 == 2)
		bar->unknown88bab0(false);
}

void CInventoryItem::unknown4aa3a0(bool flag)
{
	if (bar)
		bar->unknown88bab0(flag);
}

void CInventoryItem::drawName()
{
	string name = item->getName(0,1);
	int value = 0;
	if (type != 1 && opw6_cf4830[item->getField457820()] != 0)
		value = item->unknown5745d0(name);
	opw6_truncate408220(name,opw6_d33be8 - ((asciiEnabled != 0) + 7) - opw6_bcc2e0 - 3,value);
	opw6_padRight4080d0(name,opw6_d33be8 - ((asciiEnabled != 0) + 7) - opw6_bcc2e0 - 3,' ');
	print((asciiEnabled != 0) + 7,0,name);
}

bool CInventoryItem::mouseEnter()
{
	animate("A_ButtonHover_Begin_INV_HOV_OK");
	return true;
}

void CInventoryItem::drawState()
{
	string name;
	switch (type)
	{
		case 0:
			if (item->getField4578a0() == 5)
				name = "A_CInvItem_Item";
			else if (opw6_cf4830[item->getField457820()] != 0 && !item->unknown457d70())
				name = "A_CInvItem_Broken";
			else if (item->unknown457db0())
				name = "A_CInvItem_Corrupted";
			else
				name = "A_CInvItem_Part";
			break;
		case 1:
			name = "A_CInvItem_Multislot";
			break;
		case 2:
		case 3:
			name = "A_CInvItem_Button";
			break;
	}
	animate(name);
}

class OpW6_Inventory : public Console	// NOTE: placeholder name (CInventory, vtable 0xc35cdc)
{
public:
	virtual ~OpW6_Inventory();	// 0x4aa6d0
	void setTimed(HItem item);	// NOTE: placeholder name (0x4aa760)

	char pad6c[0x74 - 0x6c];
	vector<CInventoryItem*> items;	// NOTE: placeholder name
	char pad84[0xa0 - 0x84];
	vector<HExplosive> unknownA0;	// NOTE: placeholder name
	vector<unsigned int> unknownB0;	// NOTE: placeholder name
	unsigned int unknownC0;	// NOTE: placeholder name
	HItem unknownC4;	// NOTE: placeholder name
};

OpW6_Inventory::~OpW6_Inventory()
{
}

void OpW6_Inventory::setTimed(HItem item)
{
	unknownC0 = opw6_tickCount + opw6_d28e60;
	unknownC4 = item;
}

//==================================================================
// CPartswapPart / CPartswapListPart
//==================================================================

class OpW6_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	XConsole *getHighlighter();	// NOTE: placeholder name (folded getter 0x4ab670)

	char pad0[0x6c];
	XConsole *highlighter;	// NOTE: placeholder name
};

XConsole *OpW6_Rex::getHighlighter()
{
	return highlighter;
}
extern OpW6_Rex opw6_rex;	// NOTE: placeholder name
extern XColor *opw6_d1ecd4;	// NOTE: placeholder name
extern XColor *opw6_d204ac;	// NOTE: placeholder name

class CPartswapPart : public Console
{
public:
	CPartswapPart(XConsole *parent, Console *slot_);	// 0x4aa830
	virtual ~CPartswapPart() {};	// 0x4aa8b0

	Console *slot;	// NOTE: placeholder name
};

CPartswapPart::CPartswapPart(XConsole *parent, Console *slot_)
	: Console(parent,slot_->getRect(),0,false,-1)
{
	slot = slot_;
	opw6_rex.getHighlighter()->unknown429fe0(this,Pos(0,0),slot->getRect());
}

class CPartswapListPart : public Console
{
public:
	CPartswapListPart(XConsole *parent, int y, HProp item_, int key_);	// 0x4aa900
	virtual ~CPartswapListPart() {};	// 0x4aae80

	HItem item;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
};

CPartswapListPart::CPartswapListPart(XConsole *parent, int y, HProp item_, int key_)
	: Console(parent,parent->getWidth44b0d0() - 2,1,1,y,0,false,-1)
{
	item.ID = item_.ID;	// NOTE: the original converts between two handle types here
	key = key_;
	string letter;
	letter += key - 0x20;
	print(1,0,letter);
	setFore_417f80(1,0,item.isValid() ? *opw6_d20b70 : *opw6_d1ecd4);
	if (item.isValid())
	{
		if (asciiEnabled)
		{
			Console *marker = new Console(this,1,1,3,0,2,false,-1);
			marker->putChar_418110(0,0,item->unknown457a30(),*item->unknown5755f0(0));
		}
		else
			putChar_418110(3,0,item->unknown457ab0(),*item->unknown5755f0(0));
		putChar_418110((asciiEnabled != 0) + 5,0,0xb3,*item->getColor577260());
	}
	setFore(item.isValid() && opw6_cf4830[item->getField457820()] != 0 && !item->unknown457d70() ? *opw6_d204ac : (item.isValid() && opw6_cf4830[item->getField457820()] != 0 && item->unknown577ad0() > 0 ? *opw6_cf27e8 : (key == 0x79 && item.isNull() ? *opw6_cf6b24 : *opw6_d2981c)));
	string name = item.isValid() ? item->getName(1,1) : string(key == 0x79 ? "(no autopair found)" : "Remove");
	print((asciiEnabled != 0) + 7,0,name);
}

//==================================================================
// CPartswapList / CPartswap / CPartremove / CPartmanage / CMapshift / CItemTag
//==================================================================

extern XColor *opw6_d2175c;	// NOTE: placeholder name

class CPartswapList : public Console
{
public:
	CPartswapList(XConsole *parent, const Rect &rect, vector<HProp> &items, HProp linked, bool flag);	// 0x4aaed0
	virtual ~CPartswapList() {};	// 0x4ab110

	vector<CPartswapListPart*> rows;	// NOTE: placeholder name
};

CPartswapList::CPartswapList(XConsole *parent, const Rect &rect, vector<HProp> &items, HProp linked, bool flag)
	: Console(parent,rect,0,false,-1)
{
	unknown7b0640(0,*opw6_cf6b24,1,0);
	unsigned int i, key;
	for (i = 0, key = 0x61; i < items.size(); i++, key++)
		rows.push_back(new CPartswapListPart(this,i + 1,items[i],key));
	setCharRow(1,i + 1,getWidth44b0d0() - 2,0x81,*opw6_d2175c);
	rows.push_back(new CPartswapListPart(this,i + 2,linked,0x79));
	if (flag)
		rows.push_back(new CPartswapListPart(this,i + 3,HProp(),0x7a));
}

class CPartswap : public Console
{
public:
	CPartswap(XConsole *parent);	// 0x4ab1a0
	virtual ~CPartswap() {};	// 0x4ab2a0

	int mode;	// NOTE: placeholder name
	Console *unknown70;	// NOTE: placeholder name
	CPartswapList *unknown74;	// NOTE: placeholder name
	int unknown78;	// NOTE: placeholder name
	HProp unknown7c;	// NOTE: placeholder name
	Console *unknown80;	// NOTE: placeholder name
	vector<Console*> unknown84;	// NOTE: placeholder name
	Console *unknown94;	// NOTE: placeholder name
	Console *unknown98;	// NOTE: placeholder name
	vector<CPartswapPart*> unknown9c;	// NOTE: placeholder name
	vector<Console*> unknownAc;	// NOTE: placeholder name
	Console *unknownBc;	// NOTE: placeholder name
	bool unknownC0;	// NOTE: placeholder name
	HProp item;	// NOTE: placeholder name
	Console *unknownC8;	// NOTE: placeholder name
	bool unknownCc;	// NOTE: placeholder name
};

CPartswap::CPartswap(XConsole *parent)
	: Console(parent,Rect(0,0,1,1),0,false,13)
	, mode	(0)
	, unknown70	(NULL)
	, unknown74	(NULL)
	, unknown80	(NULL)
	, unknown94	(NULL)
	, unknown98	(NULL)
	, unknownBc	(NULL)
	, unknownC0	(false)
	, unknownC8	(NULL)
	, unknownCc	(false)
{
	resetBack_418450();
}

class CPartremove : public Console
{
public:
	CPartremove(XConsole *parent);	// 0x4ab360
	virtual ~CPartremove() {};	// 0x4ab3c0

	bool unknown6c;	// NOTE: placeholder name
	bool unknown6d;	// NOTE: placeholder name
	bool unknown6e;	// NOTE: placeholder name
};

CPartremove::CPartremove(XConsole *parent)
	: Console(parent,Rect(0,0,1,1),0,false,-1)
	, unknown6c	(false)
	, unknown6d	(false)
	, unknown6e	(false)
{
	resetBack_418450();
}

class CPartmanage : public Console
{
public:
	CPartmanage(XConsole *parent);	// 0x4ab410
	virtual ~CPartmanage() {};	// 0x4ab480

	Console *unknown6c;	// NOTE: placeholder name
	bool unknown70;	// NOTE: placeholder name
	bool unknown71;	// NOTE: placeholder name
};

CPartmanage::CPartmanage(XConsole *parent)
	: Console(parent,Rect(0,0,1,1),0,false,-1)
	, unknown6c	(NULL)
	, unknown70	(false)
	, unknown71	(false)
{
	resetBack_418450();
}

class CMapshift : public Console
{
public:
	CMapshift(XConsole *parent);	// 0x4ab4f0
	virtual ~CMapshift() {};	// 0x4ab550

	bool unknown6c;	// NOTE: placeholder name
};

CMapshift::CMapshift(XConsole *parent)
	: Console(parent,Rect(0,0,1,1),0,false,-1)
	, unknown6c	(false)
{
	resetBack_418450();
}

class CItemTag : public Console
{
public:
	CItemTag(XConsole *parent);	// 0x4ab5c0
	virtual ~CItemTag() {};	// 0x4ab650
	Pos getPos();	// NOTE: placeholder name (0x4ab6d0)

	Console *unknown6c;	// NOTE: placeholder name
	bool unknown70;	// NOTE: placeholder name
	HProp item;	// NOTE: placeholder name
	HProp entity;	// NOTE: placeholder name
	Pos pos;	// NOTE: placeholder name
	bool unknown84;	// NOTE: placeholder name
};

CItemTag::CItemTag(XConsole *parent)
	: Console(parent,Rect(0,0,1,1),0,false,-1)
	, unknown6c	(NULL)
	, unknown70	(false)
	, pos	(-1)
	, unknown84	(false)
{
	resetBack_418450();
}

Pos CItemTag::getPos()
{
	return pos;
}

//==================================================================
// CSearchItem row / CSearchResultsCounter / CSearchResults / CSearch
//==================================================================

struct OpW1_Result	// NOTE: placeholder name (shared with op_w1)
{
	int x;
	int y;
	int distance;	// NOTE: placeholder name
};

class OpW1_ResultRow : public Console	// NOTE: placeholder name (CSearchItem, shared with op_w1)
{
public:
	void setKey(int key);	// NOTE: placeholder name (0x4ac250)
};

void OpW1_ResultRow::setKey(int key)
{
	string letter;
	letter += key - 0x20;
	setFore(*opw6_d2981c);
	print(5,0,letter);
}

struct OpW6_SearchEntry	// NOTE: placeholder name
{
	char pad00[0x10];
	int type;	// NOTE: placeholder name
};

class OpW6_SearchGrid	// NOTE: placeholder name
{
public:
	OpW6_SearchEntry *get(int x, int y);	// NOTE: placeholder name (0x9d2c30)
};

class OpW6_MapSize	// NOTE: placeholder name (0xcfd44c)
{
public:
	int getWidth();	// NOTE: placeholder name
	int getHeight();	// NOTE: placeholder name
};
extern OpW6_MapSize opw6_cfd44c;	// NOTE: placeholder name
extern int opw6_caf164;	// NOTE: placeholder name

class CSearchResultsCounter : public Console
{
public:
	CSearchResultsCounter(XConsole *parent);	// 0x4ac2f0
	void updateText();	// NOTE: placeholder name

	int total;	// NOTE: placeholder name
	int count;	// NOTE: placeholder name
};

CSearchResultsCounter::CSearchResultsCounter(XConsole *parent)
	: Console(parent,1,1,2,0,0,false,0x1b)
{
	total = 0;
	count = 0;
	OpW6_SearchGrid *grid = opw6_world->unknown463e70();
	for (int x = 0; x < opw6_cfd44c.getWidth(); x++)
	{
		for (int y = 0; y < opw6_cfd44c.getHeight(); y++)
		{
			if (grid->get(x,y)->type != opw6_caf164)
				total++;
		}
	}
	updateText();
}

bool opw1_compareResults(OpW1_Result *a, OpW1_Result *b)	// NOTE: placeholder name (0x4ac400)
{
	return a->distance < b->distance;
}

struct OpV4d_Trivial;
void OpV4d_deleteMapRecords(vector<OpV4d_Trivial *> &records);	// NOTE: placeholder name (op_v4d.cpp)

// Defined here (it was only a stub) so LTCG can prove ~CSearchResults nothrow, as in the exe; folded at 0x9d0670.
void opw1_deleteAll(vector<OpW1_Result*> *list)	// NOTE: placeholder name (0x9d0670)
{
	OpV4d_deleteMapRecords(*(vector<OpV4d_Trivial *> *)list);
	list->clear();
}

class CSearchResults : public Console
{
public:
	CSearchResults(XConsole *parent, const Rect &rect);	// 0x4ac420
	virtual ~CSearchResults();	// 0x4ac600
	bool updateResults(bool force);	// NOTE: placeholder name
	void rebuildRows();	// NOTE: placeholder name

	string searchText;	// NOTE: placeholder name
	vector<OpW1_Result*> results;	// NOTE: placeholder name
	vector<OpW1_ResultRow*> rows;	// NOTE: placeholder name
	int pageSize;	// NOTE: placeholder name
	int offset;	// NOTE: placeholder name
	Console *unknownB0;
	OpW1_ResultRow *unknownB4;
	Pos lastPos;	// NOTE: placeholder name
	unsigned int lastTime;	// NOTE: placeholder name
	CSearchResultsCounter *counter;	// NOTE: placeholder name
};
extern CSearchResults *opw6_cec0a8;	// NOTE: placeholder name

CSearchResults::CSearchResults(XConsole *parent, const Rect &rect)
	: Console(parent,rect,0,false,0x1b)
	, pageSize	(5)
	, offset	(0)
	, unknownB0	(NULL)
	, unknownB4	(NULL)
	, lastPos	(-1)
	, lastTime	(0)
{
	setTitle(new ConsoleTitle(this,"/ R E S U L T S /",0,4));
	animate("CType_Border");
	opw6_cec0a8 = this;
	counter = new CSearchResultsCounter(this);
	updateResults(true);
	rebuildRows();
}

CSearchResults::~CSearchResults()
{
	opw6_cec0a8 = NULL;
	opw1_deleteAll(&results);
}

class CSearch : public Console
{
public:
	CSearch(XConsole *parent);	// 0x4ac6f0
	virtual ~CSearch() {};	// 0x4ac760

	bool active;	// NOTE: placeholder name
	Console *unknown70;	// NOTE: placeholder name
	CSearchResults *results;	// NOTE: placeholder name
	int unknown78;
};

CSearch::CSearch(XConsole *parent)
	: Console(parent,Rect(0,0,1,1),0,false,0x19)
	, active	(false)
	, results	(NULL)
	, unknown78	(0)
{
	resetBack_418450();
}

//==================================================================
// CSpecialCommand / CSpecialCommands / CAnalysis
//==================================================================

extern int opw6_ceca68, opw6_ceca6c, opw6_ceca70, opw6_ceca74, opw6_ceca78, opw6_ceca7c;	// NOTE: placeholder names (animation indices)

void opw6_initCommandAnimations()	// NOTE: placeholder name (0x4ac7d0)
{
	opw6_findAnimation("A_Option_Header",&opw6_ceca70);
	opw6_findAnimation("A_CRobotTarget_Delay",&opw6_ceca7c);
	opw6_findAnimation("CRobotTarget_Ascii",&opw6_ceca74);
	opw6_findAnimation("CRobotTarget_Dark",&opw6_ceca68);
	opw6_findAnimation("CRobotTarget_Text",&opw6_ceca78);
	opw6_findAnimation("A_Option_Desc",&opw6_ceca6c);
}

extern string gameStrings_d2ccf0[];
extern int opw6_bccaf0[];	// NOTE: placeholder name

class CSpecialCommand : public Console
{
public:
	CSpecialCommand(XConsole *parent, int x, int y, int type_);	// 0x4ac960

	int type;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
};

CSpecialCommand::CSpecialCommand(XConsole *parent, int x, int y, int type_)
	: Console(parent,gameStrings_d2ccf0[type_].size() + 6,1,x,y,0,false,-1)
{
	type = type_;
	unknown70 = opw6_bccaf0[type];
	unknown48c3c0(opw6_ceca7c);
}

class CSpecialCommands : public Console
{
public:
	CSpecialCommands(XConsole *parent);	// 0x4aca10
	virtual ~CSpecialCommands() {};	// 0x4acab0
	void setTimer();	// NOTE: placeholder name (0x4acb40)

	bool unknown6c;	// NOTE: placeholder name
	bool unknown6d;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	vector<CSpecialCommand*> unknown74;	// NOTE: placeholder name
	vector<CSpecialCommand*> unknown84;	// NOTE: placeholder name
	vector<CSpecialCommand*> unknown94;	// NOTE: placeholder name
	int unknownA4;	// NOTE: placeholder name
	Console *unknownA8;	// NOTE: placeholder name
	unsigned int unknownAc;	// NOTE: placeholder name
};

CSpecialCommands::CSpecialCommands(XConsole *parent)
	: Console(parent,Rect(0,0,1,1),0,false,0x19)
	, unknown6c	(false)
	, unknown6d	(false)
	, unknownA8	(NULL)
	, unknownAc	(0)
{
	resetBack_418450();
}

void CSpecialCommands::setTimer()
{
	unknownAc = opw6_tickCount + 500;
}

class CAnalysis : public Console
{
public:
	virtual ~CAnalysis();	// 0x4acb90
};
extern CAnalysis *opw6_cec128;	// NOTE: placeholder name

CAnalysis::~CAnalysis()
{
	opw6_cec128 = NULL;
}

//==================================================================
// CInfoTitleGlyph / CInfoTitle
//==================================================================

struct OpW6_EntityData	// NOTE: placeholder name
{
	char pad00[0x78];
	int glyph;	// NOTE: placeholder name
};

extern bool opw6_d28def;	// NOTE: placeholder name
extern int opw6_cebfd0;	// NOTE: placeholder name
extern int opw6_cebf0c;	// NOTE: placeholder name
int centerOffset(int inner, int outer) throw();	// NOTE: placeholder name (0x437190)

class CInfoTitleGlyph : public Console
{
public:
	CInfoTitleGlyph(XConsole *parent, int x, int size, HEntity entity, HItem item, bool flag);	// 0x4add80
	void highlight();	// NOTE: placeholder name (0x4adfe0)
};

CInfoTitleGlyph::CInfoTitleGlyph(XConsole *parent, int x, int size, HEntity entity, HItem item, bool flag)
	: Console(parent,size,size,x,0,2,false,-1)
{
	if (entity.isValid())
	{
		if (asciiEnabled && size > 1)
		{
			int index = 0;
			for (int y = 0; y < size; y++, index++)
			{
				for (int x = 0; x < size; x++, index++)
					putChar_418110(x,y,entity->getData()->glyph + index,*entity->unknown5c7810());
				index--;
			}
		}
		else
		{
			for (int x = 0; x < size; x++)
			{
				for (int y = 0; y < size; y++)
					putChar_418110(x,y,entity->unknown45a2e0(Pos(x,y)),*entity->unknown5c7810());
			}
		}
	}
	else
	{
		putChar_418110(0,0,item->unknown457a30(),*item->unknown5755f0(flag));
		if (asciiEnabled && opw6_d28def && item->getData()->unknown94 == 2)
			setFore_417f80(0,0,*opw6_d1ecd4);
	}
}

void CInfoTitleGlyph::highlight()
{
	unknown48c3c0(opw6_cebfd0);
}

class CInfoTitle : public Console
{
public:
	CInfoTitle(XConsole *parent, int y, HEntity entity, HItem item, bool flag);	// 0x4ae000
	void highlight();	// NOTE: placeholder name (0x4ae300)

	CInfoTitleGlyph *glyph;	// NOTE: placeholder name
};

CInfoTitle::CInfoTitle(XConsole *parent, int y, HEntity entity, HItem item, bool flag)
	: Console(parent,1,1,0,y,0,false,-1)
{
	string name = entity.isValid() ? *entity->getName416f40() : item->getName(1,0);
	int size = entity.isValid() ? entity->getSize() : 1;
	name += " [";
	int pos = name.size();
	name.append(size*2,' ');
	name += "]";
	Console::resize(name.size(),size);
	setPos(Pos(centerOffset(getWidth44b0d0(),getParent4()->getWidth44b0d0()),getPos().y));
	print(0,0,name);
	glyph = new CInfoTitleGlyph(this,pos,size,entity,item,flag);
}

void CInfoTitle::highlight()
{
	unknown48c3c0(opw6_cebf0c);
	glyph->highlight();
}
