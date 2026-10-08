// op_w1: CInventory/CPartswap/CPartremove/CPartmanage/CMapshift/CItemTag/CSearch consoles (0x8a7370-0x8b0000), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <ctype.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Item	// NOTE: placeholder layout
{
public:
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	bool unknown4579d0();	// NOTE: placeholder name
	void unknown458700(const string &text);	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
};

class HItemP	// NOTE: placeholder layout (operator-> at 0x9b65b0)
{
public:
	int ID;
	bool isValid() const;
	Item *operator->() const;
};

bool OpW1_compareItemNames(HItemP a, HItemP b)	// NOTE: placeholder name
{
	string nameA = a->getName(0,0);
	string nameB = b->getName(0,0);
	return lexicographical_compare(nameA.begin(),nameA.end(),nameB.begin(),nameB.end());
}

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos);
	Pos &operator=(const Pos &pos);	// 0x46ca50
	bool operator==(const Pos &pos) const;	// 0x409b90
	void set(int x_);	// NOTE: placeholder name (0x409ff0)
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	bool operator!=(XColor color);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// 0x40a6e0
	Rect(int x_, int y_, int width_, int height_);
	Rect(const Rect &rect);
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
};

class HItemList : public vector<HItemP>	// NOTE: placeholder layout
{
};

class Entity	// NOTE: placeholder layout
{
public:
	HItemList *getInventoryList();
	bool unknown5cc080(HItemP item, int type);	// NOTE: placeholder name
	int unknown448fe0(int type);	// NOTE: placeholder name
	bool unknown5cc120(int slot);	// NOTE: placeholder name
	int unknown5cb760();	// NOTE: placeholder name
	int unknown5cb7f0();	// NOTE: placeholder name
	int unknown5cb7a0();	// NOTE: placeholder name
	int unknown45a8d0();	// NOTE: placeholder name
	int unknown45a920();	// NOTE: placeholder name
	bool isPlayer();
	Pos &getPosition() throw();	// NOTE: placeholder name (0x45a4a0)
	Pos &getPositionNothrow() throw();	// NOTE: placeholder name (same function; private name keeps the throw() declaration under LTCG)
	string *getNameAt0c();	// NOTE: placeholder name (folded getter 0x416f40)
	void unknown45b070(const string &name);	// NOTE: placeholder name
	void unknown642940(class HProp item, int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown5e2b50();	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
	bool isValid() const;
	void reset();	// NOTE: placeholder name (0x9b7270)
	Entity *operator->() const throw();	// 0x9b6570
	Entity *get_9b6570() const throw();	// NOTE: placeholder name (operator-> under a private name, so LTCG keeps this TU's throw())
};

class OpW1_Item	// NOTE: placeholder name
{
public:
	bool unknown457ff0();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
	int unknown45cb30();	// NOTE: placeholder name (folded getter)
	HEntity unknown457b50();	// NOTE: placeholder name
	int unknown4578c0();	// NOTE: placeholder name
	int unknown577fb0();	// NOTE: placeholder name
	int unknown4578a0();	// NOTE: placeholder name
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	bool unknown4579d0();	// NOTE: placeholder name
	void unknown458700(const string &text);	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
	int unknown44aec0();	// NOTE: placeholder name (folded getter)
	int unknown457a30();	// NOTE: placeholder name
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp();
	bool isValid() const;
	bool isNull() const;
	void reset();	// NOTE: placeholder name (0x9b7270)
	OpW1_Item *operator->() const;	// 0x9b65b0
	bool operator==(HProp other) const;	// 0x9b7210
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
	Pos getPos();
	Pos localToAbs(Pos pos);
	int getWidth();	// 0x44b0d0
	int getHeight();
	Pos getMaxCoord();
	bool contains(const Pos &p);
	Rect getRect();
	void removeSubconsole(XConsole *console);
	void resetBack_418450();	// NOTE: placeholder name
	void putChar_4180b0(int x, int y, int ch);
	void putChar_418110(int x, int y, int ch, XColor fore);
	void putChar_418150(int x, int y, int ch, XColor fore, XColor back, bool flag);
	void setChar_417f50(int x, int y, int ch);
	XColor getBack(int x, int y);
	void setFore(XColor color);
	void setPos(int x, int y);
	void setPos(const Pos &pos);
	void setForeRow(int x, int y, int width, XColor color);
	void setBackRow(int x, int y, int width, XColor color);
	void print(int x, int y, const string &text);
	void printAligned(int x, int y, int alignment, const string &text);
	void clearRow(int x, int y, int width);

	char pad04[0x60 - 0x04];
};

class OpW1_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpW1_Engine	// NOTE: placeholder name (Engine)
{
public:
	void unknown50fff0();	// NOTE: placeholder name
	OpW1_EngineItem *unknown50fb50(OpW1_Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
};

class OpW1_ConsoleTitle	// NOTE: placeholder name (ConsoleTitle, 0x8c bytes)
{
public:
	OpW1_ConsoleTitle(XConsole *parent, string text, int a, int b);
	char pad[0x8c];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	void setTitle(OpW1_ConsoleTitle *title);	// NOTE: placeholder name (0x7ad4e0)
	void animate(string name);
	void unknown48c3c0(int value);	// NOTE: placeholder name

	int unknown60;
	OpW1_Engine *engine;
	void *title;
};

struct OpW1_MapNote	// NOTE: placeholder name
{
	Pos pos;	// NOTE: placeholder name
	char text[1];	// NOTE: placeholder layout
	bool isAt(const Pos &p);	// NOTE: placeholder name (0x409b90)
};

class OpW1_World	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	vector<OpW1_MapNote*> *getMapNotes();	// NOTE: placeholder name (0x463f60)
	class OpW1_Grid *getGrid();	// NOTE: placeholder name (0x463e70)
	bool isVisible(const Pos &pos);	// NOTE: placeholder name (0x4631c0)
	void unknown72e8e0(int value);	// NOTE: placeholder name
	void unknown729eb0(const Pos &pos, const string &text, int a, int b);	// NOTE: placeholder name
	HEntity getPlayer() throw();	// 0x4630f0
	HEntity getPlayerNothrow() throw();	// NOTE: placeholder name (same function; private name keeps the throw() declaration under LTCG)
	bool unknown71bbd0();	// NOTE: placeholder name
};
extern OpW1_World *opw1_world;	// NOTE: placeholder name

struct OpW1_Record : public Console	// NOTE: placeholder name (CInventory row)
{
	HProp item;	// NOTE: placeholder name
};

class OpW1_Inventory : public Console	// NOTE: placeholder name (CInventory at 0xcec08c)
{
public:
	void attemptEquip(HProp item, int a, int slot, int b);	// NOTE: placeholder signature (0x8a3f20)
	int unknown8a20b0();	// NOTE: placeholder name
	bool unknown8a54c0(HProp item, int flag);	// NOTE: placeholder name
	void unknown8a53c0();	// NOTE: placeholder name
	vector<struct OpW1_Record*> *getRecords();	// NOTE: placeholder name (0x4a9ad0)
};
extern OpW1_Inventory *opw1_inventory;	// NOTE: placeholder name

class OpW1_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void unknown416640();	// NOTE: placeholder name
	void setTarget(void *target);	// NOTE: placeholder name (folded setter)
	void registerConsole(int command, Console *console, int unknown1, int unknown2);	// NOTE: placeholder name (0x416790)
	void setClickHandler(bool (*handler)());	// NOTE: placeholder name (0x416750)
	void unknown4162e0(int command, int value);	// NOTE: placeholder name
};
extern OpW1_KeyMap *opw1_keyMap;	// NOTE: placeholder name

class OpW1_Highlighter	// NOTE: placeholder name
{
public:
	void unknown429fe0(Console *console, const Pos &pos, const Rect &rect);	// NOTE: placeholder name
	void unknown42ded0();	// NOTE: placeholder name
};

class OpW1_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	OpW1_Highlighter *getHighlighter();	// NOTE: placeholder name (folded getter 0x4ab670)
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
};
extern OpW1_Rex opw1_rex;	// NOTE: placeholder name

class OpW1_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool isIn(const Rect &rect);	// NOTE: placeholder name (0x41a730)
	Pos getPos();	// NOTE: placeholder name (0x41a700)
};
extern OpW1_Mouse *opw1_mouse;	// NOTE: placeholder name

class OpW1_Push : public XConsole	// NOTE: placeholder name (0xcec054)
{
public:
	bool unknown805060(const Pos &pos);	// NOTE: placeholder name
	void unknown8069e0(Pos pos, int a);	// NOTE: placeholder name
	void unknown49b740();	// NOTE: placeholder name
	void unknown49b650(const Pos &pos);	// NOTE: placeholder name
	void unknown806e70(const Pos &pos, int a);	// NOTE: placeholder name
	void unknown8142d0(int a, int b);	// NOTE: placeholder name
	void unknown812950(const Pos &pos, int a);	// NOTE: placeholder name
	void unknown8119c0(HProp item, int a, int b, int c);	// NOTE: placeholder name
	bool operate();	// NOTE: placeholder name (0x49aa00)
	void unknown827950();	// NOTE: placeholder name
};
extern OpW1_Push *opw1_cec054;	// NOTE: placeholder name

struct OpW1_Slot;

class OpW1_Unk89d780 : public XConsole	// NOTE: placeholder name (0xcec088)
{
public:
	void unknown89d780();	// NOTE: placeholder name
	vector<struct OpW1_Slot*> *getSlots();	// NOTE: placeholder name (folded getter 0x4a9ad0)
	bool unknown4a9de0();	// NOTE: placeholder name
	bool getField4a9b90();	// NOTE: placeholder name (folded getter)
	void setField(int value);	// NOTE: placeholder name (0x4a9cb0)
	int unknown898910(OpW1_Slot *slot, HProp item, int value);	// NOTE: placeholder name
	void unknown89c350(HProp item, int slot);	// NOTE: placeholder name
	OpW1_Slot *unknown894e70(HProp item);	// NOTE: placeholder name
	int unknown4a9e90(int key);	// NOTE: placeholder name
	void unknown4a9bf0();	// NOTE: placeholder name
};
extern OpW1_Unk89d780 *opw1_cec088;	// NOTE: placeholder name

class OpW1_SidePanel : public XConsole	// NOTE: placeholder name (0xcec118/0xcec11c/0xcec120)
{
public:
	void unknown8b5080();	// NOTE: placeholder name
};
extern OpW1_SidePanel *opw1_cec118;	// NOTE: placeholder name
extern OpW1_SidePanel *opw1_cec11c;	// NOTE: placeholder name
extern OpW1_SidePanel *opw1_cec120;	// NOTE: placeholder name

extern unsigned int opw1_tickCount;	// NOTE: placeholder name (0xcaed20)
extern unsigned int opw1_cefc80;	// NOTE: placeholder name
extern unsigned int opw1_cefc84;	// NOTE: placeholder name
extern int opw1_cefc90;	// NOTE: placeholder name
extern bool opw1_cec14d;	// NOTE: placeholder name
extern bool opw1_cec14e;	// NOTE: placeholder name
extern bool opw1_cefca8;	// NOTE: placeholder name
extern bool opw1_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)

void logError(string location, string message);
string intToString(int value);

class OpW1_Message	// NOTE: placeholder name (0x20 bytes, ctor 0x510d20)
{
public:
	OpW1_Message(int a, int b, int c, int d, HProp e, HProp f);
	int pad[8];
};
class OpW1_MessageLog	// NOTE: placeholder name (0xcec0f4)
{
public:
	void add(OpW1_Message *message);	// NOTE: placeholder name (0x7b1880)
};
extern OpW1_MessageLog *opw1_cec0f4;	// NOTE: placeholder name
void opw1_showWarning(int type, const string &text, int a, int b, HEntity entity, HProp prop, int c);	// NOTE: placeholder name (0x7b1750)
class OpW1_Audio	// NOTE: placeholder name (0xcefaa8)
{
public:
	void play(int sound, int a, int b, int c, int d);	// NOTE: placeholder name (0x793450)
};
extern OpW1_Audio *opw1_cefaa8;	// NOTE: placeholder name
extern int opw1_cf462c;	// NOTE: placeholder name
extern int opw1_cefc68;	// NOTE: placeholder name
extern int opw1_cefc6c;	// NOTE: placeholder name

class OpW1_TextInput	// NOTE: placeholder name
{
public:
	void setUnknown95(bool value);	// NOTE: placeholder name (0x48d360)
	void unknown4544c0(int value);	// NOTE: placeholder name
	void setText(const char *text);	// NOTE: placeholder name (0x48d300)
	string &getText();	// NOTE: placeholder name (0x458ef0)
	void clear();	// NOTE: placeholder name
	void setKeyHandler(void (*handler)(int key, int modifier));	// NOTE: placeholder name (folded setter)
};

class OpW1_TextWindow : public Console	// NOTE: placeholder name (0x80 bytes)
{
public:
	OpW1_TextWindow(XConsole *parent, const Rect &rect, int unknown1, const string &title, int alignment, void (*callback)(const string &text), int unknown2, int maxLength, int unknown3);	// 0x4b1c50
	virtual void openWindow();	// NOTE: placeholder name (Console slot 8)
	virtual void closeWindow();	// NOTE: placeholder name (Console slot 9)

	char pad6c[0x78 - 0x6c];
	bool unknown78;
	OpW1_TextInput *input;	// NOTE: placeholder name
};
extern OpW1_TextWindow *opw1_textWindow;	// NOTE: placeholder name (0xcec10c)
extern XConsole *opw1_cec034;	// NOTE: placeholder name

void cItemTagConsoleDone(const string &text);
int opw1_centerOffset(int size, int total);	// NOTE: placeholder name (0x437190)
string opw1_truncate(const string &text, unsigned int length);	// NOTE: placeholder name (0x408490)
extern int opw1_caf128;	// NOTE: placeholder name

struct OpW1_Pair	// NOTE: placeholder name
{
	OpW1_Pair(int value);	// 0x409990
	int a;
	int b;
};

class OpW1_Info : public Console	// NOTE: placeholder name (CInfo at 0xcec11c)
{
public:
	void unknown8b4500(HEntity entity, HProp a, HProp b, const OpW1_Pair &c, int d, int e);	// NOTE: placeholder name
	Pos *getUnknownCC();	// NOTE: placeholder name (0x4aec60)
};
extern OpW1_Info *opw1_info;	// NOTE: placeholder name

bool opw1_unknown5111e0(int id, const string &a, const string *b, int c, HProp d, HProp e, int f, int g);	// NOTE: placeholder name
class OpW1_Unk780790	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool unknown780790();	// NOTE: placeholder name
};
extern OpW1_Unk780790 opw1_cf45d8;	// NOTE: placeholder name
class OpW1_Unk7aa280	// NOTE: placeholder name
{
public:
	void unknown7aa280(int a, int b, string text);	// NOTE: placeholder name
};
struct OpW1_Unkcf4ac8	// NOTE: placeholder name
{
	char pad00[0x30];
	OpW1_Unk7aa280 *unknown30;	// NOTE: placeholder name
};
extern OpW1_Unkcf4ac8 *opw1_cf4ac8;	// NOTE: placeholder name
class OpW1_Unk8758d0	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(int value);	// NOTE: placeholder name
};
extern OpW1_Unk8758d0 *opw1_cec058;	// NOTE: placeholder name
class OpW1_Unk7b4f10	// NOTE: placeholder name (0xcec0b4)
{
public:
	void unknown7b4f10();	// NOTE: placeholder name
};
extern OpW1_Unk7b4f10 *opw1_cec0b4;	// NOTE: placeholder name
class OpW1_Unk7b8500	// NOTE: placeholder name (0xcec0c8)
{
public:
	void unknown7b8500(HEntity entity);	// NOTE: placeholder name
};
extern OpW1_Unk7b8500 *opw1_cec0c8;	// NOTE: placeholder name

void opw1_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)
int opw1_findIndex(void *list, int id);
bool opw1_isBetween(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)
extern bool opw1_d28c8a;	// NOTE: placeholder name

class OpW1_Unk4ac780	// NOTE: placeholder name
{
public:
	void resetField();	// NOTE: placeholder name (0x4ac780)
};
class CSearch;
extern CSearch *opw1_cec0a4;	// NOTE: placeholder name (CSearch)	// NOTE: placeholder name (0x9d4660)

//==================================================================
// CPartswap
//==================================================================

struct OpW1_Slot : public Console	// NOTE: placeholder name
{
	HProp item;	// NOTE: placeholder name
	int unknown70;
	HProp unknown74;	// NOTE: placeholder name
	int unknown78;
	int type;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
};

struct OpW1_Link	// NOTE: placeholder name
{
	HProp a;	// NOTE: placeholder name
	HProp b;	// NOTE: placeholder name
	bool isActive();	// NOTE: placeholder name (0x46d440)
};
extern vector<OpW1_Link*> opw1_links;	// NOTE: placeholder name (0xcf4760)
extern XColor *opw1_COLOR_BLACK;	// NOTE: placeholder name (0xcfe674)
extern XColor opw1_d29804;	// NOTE: placeholder name
bool opw1_findAnimation(const string &name, int *index);	// NOTE: placeholder name (0x9d45a0)
extern bool asciiEnabled;	// NOTE: placeholder name (0xd28d30)
template <class T> void OpW1_eraseAtIndex(vector<T> *v, unsigned int *i);	// NOTE: placeholder name (0x9de640, steps i back)

struct OpW1_SlotRow : public Console	// NOTE: placeholder name
{
	OpW1_SlotRow(XConsole *parent, OpW1_Slot *slot);	// 0x4aa830
	OpW1_Slot *slot;	// NOTE: placeholder name
};

struct OpW1_PartRow : public Console	// NOTE: placeholder name
{
	HProp item;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
};

struct OpW1_PartList : public Console	// NOTE: placeholder name
{
	OpW1_PartList(XConsole *parent, const Rect &rect, vector<HItemP> &items, HProp linked, bool flag);	// 0x4aaed0
	vector<OpW1_PartRow*> rows;	// NOTE: placeholder name
};

struct OpW1_Holder : public Console	// NOTE: placeholder name
{
	HProp item;	// NOTE: placeholder name
};

class CPartswap : public Console
{
public:
	bool canSwap(int slot, HProp newItem);	// NOTE: placeholder name
	void close(bool sound);	// NOTE: placeholder name
	void setMode(int mode);	// NOTE: placeholder name
	void open(int a, int b, HProp item, bool flag);	// NOTE: placeholder name
	bool openA(OpW1_Slot *slot);	// NOTE: placeholder name (0x8a7d80)
	void closeA(bool sound);	// NOTE: placeholder name
	bool openB(int index);	// NOTE: placeholder name (0x8a8830)
	void closeB(bool sound);	// NOTE: placeholder name
	bool openC();	// NOTE: placeholder name (0x8a9730)
	void closeC(bool sound);	// NOTE: placeholder name
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);

	int mode;	// NOTE: placeholder name
	Console *unknown70;	// NOTE: placeholder name
	OpW1_PartList *unknown74;	// NOTE: placeholder name
	int unknown78;	// NOTE: placeholder name
	HProp unknown7c;	// NOTE: placeholder name
	Console *unknown80;	// NOTE: placeholder name
	vector<Console*> unknown84;	// NOTE: placeholder name
	Console *unknown94;	// NOTE: placeholder name
	Console *unknown98;	// NOTE: placeholder name
	vector<OpW1_SlotRow*> unknown9c;	// NOTE: placeholder name
	vector<Console*> unknownAc;	// NOTE: placeholder name
	OpW1_Record *unknownBc;	// NOTE: placeholder name
	bool unknownC0;	// NOTE: placeholder name
	HProp item;	// NOTE: placeholder name
	Console *unknownC8;	// NOTE: placeholder name
	bool unknownCc;	// NOTE: placeholder name
};

bool CPartswap::canSwap(int slot, HProp newItem)
{
	if (opw1_cf462c == 0xb)
	{
		opw1_cec0f4->add(new OpW1_Message(0xe7,0,0,0,HProp(),HProp()));
		return false;
	}
	if (newItem.isValid() && newItem->unknown4578c0() > 1)
	{
		opw1_cec0f4->add(new OpW1_Message(0x79,0,0,0,HProp(),HProp()));
		return false;
	}
	if (newItem.isValid() && newItem->unknown577fb0())
	{
		opw1_cec0f4->add(new OpW1_Message(0x7a,0,0,0,HProp(),HProp()));
		return false;
	}
	if (item.isNull() && !opw1_world->getPlayer()->unknown5cc120(slot))
	{
		opw1_cec0f4->add(new OpW1_Message(0x77,0,0,0,HProp(),HProp()));
		return false;
	}
	if ((newItem.isValid() && newItem->unknown4578a0() == 5) || (item.isValid() && newItem->unknown4578a0() == 5))
	{
		opw1_cec0f4->add(new OpW1_Message(0x1f,0,0,0,HProp(),HProp()));
		return false;
	}
	int energy = opw1_world->getPlayer()->unknown5cb760();
	int energyAdd = opw1_world->getPlayer()->unknown5cb7f0();
	int energyNeeded = newItem.isValid() ? energy + energyAdd : energy;
	int matterCost = opw1_world->getPlayer()->unknown5cb7a0();
	if (opw1_world->getPlayer()->unknown45a8d0() < energyNeeded)
	{
		opw1_cefc68 = energyNeeded;
		opw1_showWarning(0,intToString(opw1_cefc68),0,0,opw1_world->getPlayer(),HProp(),0);
		opw1_cefaa8->play(0x32,1,0,0,0);
		return false;
	}
	if (opw1_world->getPlayer()->unknown45a920() < matterCost)
	{
		opw1_cefc6c = matterCost;
		opw1_showWarning(1,intToString(opw1_cefc6c),0,0,opw1_world->getPlayer(),HProp(),0);
		opw1_cefaa8->play(0x35,1,0,0,0);
		return false;
	}
	return true;
}

void CPartswap::close(bool sound)
{
	if (unknownC0)
	{
		opw1_inventory->unknown8a53c0();
		unknownC0 = false;
	}
	opw1_cefc80 = opw1_tickCount + 200;
	opw1_cefc84 = opw1_tickCount + 200;
	mode = 0;
	if (sound)
		opw1_playSound(0x2a,0,0);
	opw1_keyMap->unknown416640();
	opw1_keyMap->setTarget(opw1_cec088);
	resize(1,1);
	resetBack_418450();
}

void CPartswap::setMode(int mode_)
{
	mode = mode_;
	if (opw1_cec054->operate())
		opw1_cec054->unknown827950();
	opw1_cec088->unknown89d780();
	opw1_keyMap->registerConsole(0x16,this,0x158,0);
	resize(opw1_rex.unknown418980(),opw1_rex.unknown4189a0());
	resetBack_418450();
	opw1_playSound(0x2e,0,0);
}

void CPartswap::open(int a, int b, HProp item_, bool flag)
{
	if (!opw1_cec118->isHidden())
		opw1_cec118->unknown8b5080();
	if (!opw1_cec11c->isHidden())
		opw1_cec11c->unknown8b5080();
	if (!opw1_cec120->isHidden())
		opw1_cec120->unknown8b5080();
	item = item_;
	unknownCc = flag;
	if (item.isValid())
	{
		if (mode != 2)
		{
			setMode(2);
			if (!openC())
				closeC(true);
		}
	}
	else if (b)
	{
		if (mode != 2)
		{
			if (opw1_cefc90 == 1)
			{
				opw1_inventory->unknown8a53c0();
				unknownC0 = true;
			}
			setMode(2);
			if (!openB(opw1_findIndex(opw1_inventory->getRecords(),b)))
				closeB(true);
		}
	}
	else if (a)
	{
		if (mode != 2)
		{
			setMode(2);
			if (!openA((OpW1_Slot*)a))
				closeA(true);
		}
	}
	else if (mode != 1)
	{
		if (opw1_cefc90 == 1)
		{
			opw1_inventory->unknown8a53c0();
			unknownC0 = true;
		}
		setMode(1);
	}
}

bool CPartswap::openA(OpW1_Slot *slot)
{
	if (slot->unknown74.isValid() && slot->item.isValid())
	{
		opw1_cec0f4->add(new OpW1_Message(0x78,0,0,0,HProp(),HProp()));
		return false;
	}
	unknown78 = slot->key;
	unknown7c = slot->item;
	if (!canSwap(slot->type,slot->item))
		return false;
	bool hasItem = unknown7c.isValid();
	HProp paired;
	if (unknown7c.isValid())
	{
		for (unsigned int i = 0; i < opw1_links.size(); i++)
		{
			if (!opw1_links[i]->isActive())
				OpW1_eraseAtIndex(&opw1_links,&i);
		}
		for (unsigned int i = 0; i < opw1_links.size(); i++)
		{
			if (opw1_links[i]->a == unknown7c && opw1_links[i]->b->unknown44aec0() == 4)
			{
				paired = opw1_links[i]->b;
				break;
			}
			if (opw1_links[i]->b == unknown7c && opw1_links[i]->a->unknown44aec0() == 4)
			{
				paired = opw1_links[i]->a;
				break;
			}
		}
	}
	vector<HItemP> parts;
	HItemList *inventory = opw1_world->getPlayer()->getInventoryList();
	for (unsigned int i = 0; i < inventory->size() && parts.size() < 0x18; i++)
	{
		if (opw1_world->getPlayer()->unknown5cc080((*inventory)[i],slot->type))
			parts.push_back((*inventory)[i]);
	}
	if (parts.empty())
	{
		opw1_cec0f4->add(new OpW1_Message(0x77,0,0,0,HProp(),HProp()));
		return false;
	}
	else
	{
		mode = 2;
		sort(parts.begin(),parts.end(),OpW1_compareItemNames);
		unsigned int longestName = parts[0]->getName(1,1).size();
		if (hasItem && longestName < string("Remove").size())
			longestName = string("Remove").size();
		if (paired.isNull() && longestName < string("(no autopair found)").size())
			longestName = string("(no autopair found)").size();
		for (unsigned int i = 1; i < parts.size(); i++)
		{
			if (longestName < parts[i]->getName(1,1).size())
				longestName = parts[i]->getName(1,1).size();
		}
		int width = longestName + (asciiEnabled ? 11 : 10);
		Rect menuRect(0,0,width,parts.size() + 2);
		menuRect.height += 2;
		if (hasItem)
			menuRect.height++;
		Pos loc = slot->localToAbs(Pos(0,0));
		menuRect.x = loc.x - width;
		menuRect.y = loc.y - 1;
		if (menuRect.y + menuRect.height >= opw1_rex.unknown4189a0())
			menuRect.y -= menuRect.y + menuRect.height - opw1_rex.unknown4189a0();
		unknown74 = new OpW1_PartList(this,menuRect,parts,paired,hasItem);
		unknown70 = new Console(this,Rect(menuRect.x + menuRect.width - 1,slot->getRect().y,slot->getWidth() + 1,1),0,false,0xf);
		opw1_rex.getHighlighter()->unknown429fe0(unknown70,Pos(0,0),unknown70->getRect());
		unknown70->animate("A_CPartswap_Highlight");
		return true;
	}
}

void CPartswap::closeA(bool sound)
{
	if (mode != 0)
	{
		if (unknown74)
		{
			removeSubconsole(unknown74);
			unknown74 = NULL;
		}
		if (unknown70)
		{
			removeSubconsole(unknown70);
			unknown70 = NULL;
		}
		close(sound);
	}
}

bool CPartswap::openB(int index)
{
	unknownBc = (*opw1_inventory->getRecords())[index];
	if (!canSwap(unknownBc->item->unknown4578a0(),unknownBc->item))
		return false;
	int slotType = unknownBc->item->unknown4578a0();
	vector<OpW1_Slot*> compatible;
	vector<OpW1_Slot*> incompatible;
	vector<OpW1_Slot*> *allSlots = opw1_cec088->getSlots();
	for (unsigned int i = 0; i < allSlots->size(); i++)
	{
		if ((*allSlots)[i]->type == slotType && ((*allSlots)[i]->item.isNull() || ((*allSlots)[i]->item.isValid() && (*allSlots)[i]->item->unknown4578c0() == 1 && (*allSlots)[i]->unknown74.isNull())))
			compatible.push_back((*allSlots)[i]);
		else
			incompatible.push_back((*allSlots)[i]);
	}
	if (compatible.empty())
	{
		opw1_cec0f4->add(new OpW1_Message(0x77,0,0,0,HProp(),HProp()));
		return false;
	}
	else
	{
		mode = 2;
		if (opw1_cec088->unknown4a9de0())
			opw1_rex.getHighlighter()->unknown42ded0();
		for (unsigned int i = 0; i < compatible.size(); i++)
		{
			unknown9c.push_back(new OpW1_SlotRow(this,compatible[i]));
			for (int x = 0; x < unknown9c.back()->getWidth(); x++)
			{
				if (unknown9c.back()->getBack(x,0) != opw1_d29804)
					unknown9c.back()->putChar_418150(x,0,0x20,*opw1_COLOR_BLACK,opw1_d29804,true);
			}
			unknownAc.push_back(new Console(this,1,1,compatible[i]->getRect().x - 1,compatible[i]->getRect().y,0,false,-1));
			unknownAc.back()->animate("A_CPartswap_Highlight");
		}
		OpW1_Slot *target = NULL;
		for (unsigned int i = 0; i < allSlots->size(); i++)
		{
			if ((*allSlots)[i]->type == slotType)
			{
				target = (*allSlots)[i];
				break;
			}
		}
		if (opw1_cefc90 == 2 && unknownBc->getRect().y < target->getRect().y)
			unknown94 = new Console(this,1,target->getRect().y - unknownBc->getRect().y + opw1_world->getPlayer()->unknown448fe0(slotType),opw1_cec088->getPos().x,opw1_cec088->getPos().y + target->getPos().y - (target->getRect().y - unknownBc->getRect().y),0,false,-1);
		else
			unknown94 = new Console(this,1,unknownBc->getRect().y - target->getRect().y + 1,opw1_cec088->getPos().x,opw1_cec088->getPos().y + target->getPos().y,0,false,-1);
		unknown94->animate("A_CPartswap_Link_Bar");
		if (opw1_cefc90 == 2)
		{
			unknown98 = new Console(this,1,1,opw1_cec088->getPos().x - 1,unknownBc->getRect().y,0,false,-1);
			unknown98->animate("A_CPartswap_Link_Bar");
		}
		int anim;
		if (opw1_findAnimation("A_CPartswap_Unswappable",&anim))
		{
			for (unsigned int i = 0; i < incompatible.size(); i++)
			{
				unknown84.push_back(new Console(this,incompatible[i]->getRect(),0,false,-1));
				opw1_rex.getHighlighter()->unknown429fe0(unknown84.back(),Pos(0,0),incompatible[i]->getRect());
				unknown84.back()->unknown48c3c0(anim);
			}
		}
		unknown70 = new Console(this,Rect(unknownBc->getRect().x,unknownBc->getRect().y,unknownBc->getWidth() + 1,1),0,false,0xf);
		opw1_rex.getHighlighter()->unknown429fe0(unknown70,Pos(0,0),unknown70->getRect());
		unknown70->animate("A_CPartswap_Highlight");
		if (asciiEnabled)
		{
			unknown80 = new Console(this,1,1,unknownBc->getRect().x + 3,unknownBc->getRect().y,2,false,0x10);
			unknown80->setChar_417f50(0,0,unknownBc->item->unknown457a30());
			unknown80->animate("A_CPartswap_Highlight");
		}
		return true;
	}
}

void CPartswap::closeB(bool sound)
{
	if (mode != 0)
	{
		if (unknown70)
		{
			removeSubconsole(unknown70);
			unknown70 = NULL;
		}
		if (unknown80)
		{
			removeSubconsole(unknown80);
			unknown80 = NULL;
		}
		for (unsigned int i = 0; i < unknown84.size(); i++)
		{
			if (unknown84[i])
				removeSubconsole(unknown84[i]);
		}
		unknown84.clear();
		if (unknown94)
		{
			removeSubconsole(unknown94);
			unknown94 = NULL;
		}
		if (unknown98)
		{
			removeSubconsole(unknown98);
			unknown98 = NULL;
		}
		for (unsigned int i = 0; i < unknown9c.size(); i++)
		{
			if (unknown9c[i])
				removeSubconsole(unknown9c[i]);
		}
		unknown9c.clear();
		for (unsigned int i = 0; i < unknownAc.size(); i++)
		{
			if (unknownAc[i])
				removeSubconsole(unknownAc[i]);
		}
		unknownAc.clear();
		close(sound);
	}
}

bool CPartswap::openC()
{
	if (!canSwap(item->unknown4578a0(),item))
		return false;
	int slotType = item->unknown4578a0();
	vector<OpW1_Slot*> compatible;
	vector<OpW1_Slot*> incompatible;
	vector<OpW1_Slot*> *allSlots = opw1_cec088->getSlots();
	for (unsigned int i = 0; i < allSlots->size(); i++)
	{
		if ((*allSlots)[i]->type == slotType && ((*allSlots)[i]->item.isNull() || ((*allSlots)[i]->item.isValid() && (*allSlots)[i]->item->unknown4578c0() == 1 && (*allSlots)[i]->unknown74.isNull())))
			compatible.push_back((*allSlots)[i]);
		else
			incompatible.push_back((*allSlots)[i]);
	}
	if (compatible.empty())
	{
		opw1_cec0f4->add(new OpW1_Message(0x77,0,0,0,HProp(),HProp()));
		return false;
	}
	else
	{
		mode = 2;
		if (opw1_cec088->unknown4a9de0())
			opw1_rex.getHighlighter()->unknown42ded0();
		for (unsigned int i = 0; i < compatible.size(); i++)
		{
			unknown9c.push_back(new OpW1_SlotRow(this,compatible[i]));
			for (int x = 0; x < unknown9c.back()->getWidth(); x++)
			{
				if (unknown9c.back()->getBack(x,0) != opw1_d29804)
					unknown9c.back()->putChar_418150(x,0,0x20,*opw1_COLOR_BLACK,opw1_d29804,true);
			}
			unknownAc.push_back(new Console(this,1,1,compatible[i]->getRect().x - 1,compatible[i]->getRect().y,0,false,-1));
			unknownAc.back()->animate("A_CPartswap_Highlight");
		}
		int startY;
		for (unsigned int i = 0; i < allSlots->size(); i++)
		{
			if ((*allSlots)[i]->type == slotType)
			{
				startY = (*allSlots)[i]->getRect().y;
				break;
			}
		}
		if (!opw1_cec088->getField4a9b90())
			startY--;
		string text = " " + item->getName(0,0) + " >> ";
		unknownC8 = new Console(this,text.size(),1,opw1_cec088->getPos().x - text.size(),startY,0,false,0xf);
		unknownC8->print(0,0,text);
		unknownC8->animate("A_CPartswap_Highlight");
		int endY;
		for (int i = allSlots->size() - 1; i >= 0; i--)
		{
			if ((*allSlots)[i]->type == slotType)
			{
				endY = (*allSlots)[i]->getRect().y;
				break;
			}
		}
		unknown94 = new Console(this,1,endY - startY + 1,opw1_cec088->getPos().x,startY,0,false,-1);
		unknown94->animate("A_CPartswap_Link_Bar");
		int animation;
		if (opw1_findAnimation("A_CPartswap_Unswappable",&animation))
		{
			for (unsigned int i = 0; i < incompatible.size(); i++)
			{
				unknown84.push_back(new Console(this,incompatible[i]->getRect(),0,false,-1));
				opw1_rex.getHighlighter()->unknown429fe0(unknown84.back(),Pos(0,0),incompatible[i]->getRect());
				unknown84.back()->unknown48c3c0(animation);
			}
		}
		return true;
	}
}

void CPartswap::closeC(bool sound)
{
	if (mode != 0)
	{
		for (unsigned int i = 0; i < unknown84.size(); i++)
		{
			if (unknown84[i])
				removeSubconsole(unknown84[i]);
		}
		unknown84.clear();
		if (unknown94)
		{
			removeSubconsole(unknown94);
			unknown94 = NULL;
		}
		for (unsigned int i = 0; i < unknown9c.size(); i++)
		{
			if (unknown9c[i])
				removeSubconsole(unknown9c[i]);
		}
		unknown9c.clear();
		for (unsigned int i = 0; i < unknownAc.size(); i++)
		{
			if (unknownAc[i])
				removeSubconsole(unknownAc[i]);
		}
		unknownAc.clear();
		if (unknownC8)
		{
			removeSubconsole(unknownC8);
			unknownC8 = NULL;
		}
		close(sound);
	}
}

bool CPartswap::input(XEvent *event)
{
	if (isHidden() || opw1_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opw1_world->unknown71bbd0())
		return false;
	switch (event->type)
	{
		case 5:
			if (unknown74 && !opw1_mouse->isIn(unknown74->getRect()))
			{
				closeA(true);
				return true;
			}
			else if (unknown94)
			{
				for (unsigned int i = 0; i < unknown9c.size(); i++)
				{
					if (opw1_mouse->isIn(unknown9c[i]->getRect()))
						goto skip;
				}
				if (unknownC8)
					closeC(true);
				else
					closeB(true);
				return true;
skip:
				return false;
			}
			else
				return false;
		case 0x157:
			if (mode == 0)
			{
				open(0,0,HProp(),0);
				return true;
			}
		case 0x158:
			if (unknownC8)
				closeC(true);
			else if (unknown74)
				closeA(true);
			else
				closeB(true);
			return true;
	}
	return false;
}

void CPartswap::inputAscii(int key, int modifier)
{
	if (opw1_world->unknown71bbd0())
		return;
	if (unknownCc)
	{
		unknownCc = false;
		return;
	}
	switch (modifier)
	{
		case 1:
			key += 0x20;
		case 0:
			if (unknown94)
			{
				OpW1_Slot *slot = NULL;
				for (unsigned int i = 0; i < unknown9c.size(); i++)
				{
					if (unknown9c[i]->slot->key == key)
					{
						slot = unknown9c[i]->slot;
						break;
					}
				}
				if (slot == NULL)
					return;
				if (unknownC8)
				{
					if (slot->item.isNull())
					{
						logError("CPartswap::inputAscii()","ground swap targeting empty slot");
						return;
					}
					HProp oldItem = slot->item;
					int slotKey = slot->key;
					if (!opw1_cec088->unknown898910(slot,item,item->unknown457ff0() ? item->unknown457fb0() - item->unknown45cb30() : 0))
					{
						opw1_inventory->attemptEquip(item,1,slotKey,1);
						if (oldItem.operator->() && oldItem->unknown457b50().isValid() && oldItem->unknown457b50()->isPlayer())
							opw1_world->getPlayer()->unknown642940(oldItem,1,1,0,0);
						opw1_world->getPlayer()->unknown5e2b50();
					}
					closeC(false);
				}
				else
				{
					opw1_cec088->setField(slot->key);
					if (slot->item.isValid())
						opw1_cec088->unknown89c350(unknownBc->item,slot->key);
					else
						opw1_inventory->attemptEquip(unknownBc->item,0,slot->key,0);
					closeB(false);
				}
			}
			else if (unknown74)
			{
				if (unknown74)
				{
					opw1_cec088->setField(unknown78);
					for (unsigned int i = 0; i < unknown74->rows.size(); i++)
					{
						if (unknown74->rows[i]->key == key)
						{
							if (unknown74->rows[i]->item.isNull())
							{
								if (unknown74->rows[i]->key == 0x7a)
								{
									OpW1_Slot *target = opw1_cec088->unknown894e70(unknown7c);
									if (target)
										opw1_cec088->unknown898910(target,HProp(),0);
								}
							}
							else if (unknown7c.isValid())
								opw1_cec088->unknown89c350(unknown74->rows[i]->item,unknown78);
							else
								opw1_inventory->attemptEquip(unknown74->rows[i]->item,0,unknown78,0);
							break;
						}
					}
				}
				closeA(false);
			}
			else
			{
				int part = opw1_cec088->unknown4a9e90(key);
				if (part == 0)
					return;
				mode = 2;
				if (!openA((OpW1_Slot*)part))
					closeA(true);
				else
					opw1_playSound(0x2e,0,0);
				if (unknownC0)
				{
					opw1_inventory->unknown8a53c0();
					unknownC0 = false;
				}
			}
			break;
		case 2:
			if (!unknown74 && !unknown94 && !unknownC8)
			{
				int index = key == 0x30 ? 9 : key - 0x31;
				if (index >= opw1_inventory->getRecords()->size())
					return;
				mode = 2;
				if (!openB(index))
					closeB(true);
				else
					opw1_playSound(0x2e,0,0);
			}
			break;
	}
}

//==================================================================
// CPartremove
//==================================================================

class CPartremove : public Console
{
public:
	void open();	// NOTE: placeholder name
	void close(bool sound);	// NOTE: placeholder name
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);

	bool active;	// NOTE: placeholder name
	bool skipKey;	// NOTE: placeholder name
	bool collapsedInventory;	// NOTE: placeholder name
};

void CPartremove::open()
{
	active = true;
	skipKey = true;
	if (opw1_cefc90 == 1)
	{
		opw1_inventory->unknown8a53c0();
		collapsedInventory = true;
	}
	opw1_keyMap->registerConsole(0x17,this,0x15e,0);
	opw1_playSound(0x2e,0,0);
}

void CPartremove::close(bool sound)
{
	active = false;
	if (sound)
		opw1_playSound(0x2a,0,0);
	opw1_keyMap->unknown416640();
	if (collapsedInventory)
	{
		opw1_inventory->unknown8a53c0();
		collapsedInventory = false;
	}
}

bool CPartremove::input(XEvent *event)
{
	if (isHidden() || opw1_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opw1_world->unknown71bbd0())
		return false;
	if (!active)
		return false;
	switch (event->type)
	{
		case 0x159:
			opw1_cec088->unknown4a9bf0();
			return true;
		case 0x15a:
			opw1_inventory->input(&XEvent(0x122));
			return true;
		case 0x15b:
			opw1_inventory->input(&XEvent(0x123));
			return true;
		case 0x15c:
			opw1_inventory->input(&XEvent(0x125));
			return true;
		case 0x15d:
			opw1_inventory->input(&XEvent(0x124));
			return true;
		case 0x15e:
			close(true);
			return true;
	}
	return false;
}

void CPartremove::inputAscii(int key, int modifier)
{
	if (skipKey)
	{
		skipKey = false;
		return;
	}
	if (opw1_world->unknown71bbd0())
		return;
	switch (modifier)
	{
		case 1:
			key += 0x20;
		case 0:
		{
			bool oldValue = opw1_cec14e;
			opw1_cec14e = true;
			opw1_cefca8 = true;
			opw1_cec088->inputAscii(key,0);
			opw1_cefca8 = false;
			opw1_cec14e = oldValue;
			close(false);
		}
			break;
		case 2:
		{
			int index = key == 0x30 ? 9 : key - 0x31;
			if (index >= opw1_inventory->getRecords()->size())
				return;
			opw1_inventory->input(&XEvent(index + 0x140));
			close(false);
		}
			break;
	}
}

//==================================================================
// CPartmanage
//==================================================================

class CPartmanage : public Console
{
public:
	void open();	// NOTE: placeholder name
	void close(bool sound);	// NOTE: placeholder name
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);

	int mode;	// NOTE: placeholder name
	bool skipKey;	// NOTE: placeholder name
	bool collapsedInventory;	// NOTE: placeholder name
};

void CPartmanage::open()
{
	mode = 1;
	opw1_keyMap->registerConsole(0x18,this,0x169,0);
	opw1_playSound(0x2e,0,0);
}

void CPartmanage::close(bool sound)
{
	mode = 0;
	if (sound)
		opw1_playSound(0x2a,0,0);
	opw1_keyMap->unknown416640();
	if (collapsedInventory)
	{
		opw1_inventory->unknown8a53c0();
		collapsedInventory = false;
	}
}

bool CPartmanage::input(XEvent *event)
{
	if (isHidden() || opw1_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opw1_world->unknown71bbd0())
		return false;
	switch (event->type)
	{
		case 0x15f:
			if (mode == 0)
			{
				open();
				return true;
			}
			else if (mode == 1)
			{
				close(true);
				return true;
			}
			break;
		case 0x160:
		case 0x161:
		case 0x162:
		case 0x163:
		case 0x164:
			if (mode == 1)
			{
				mode = event->type - 0x15e;
				skipKey = true;
				if (opw1_cefc90 == 1 && (mode == 3 || mode == 4 || mode == 6))
				{
					opw1_inventory->unknown8a53c0();
					collapsedInventory = true;
				}
				return true;
			}
			break;
		case 0x165:
			if (mode)
			{
				opw1_inventory->input(&XEvent(0x122));
				return true;
			}
			break;
		case 0x166:
			if (mode)
			{
				opw1_inventory->input(&XEvent(0x123));
				return true;
			}
			break;
		case 0x167:
			if (mode)
			{
				opw1_inventory->input(&XEvent(0x125));
				return true;
			}
			break;
		case 0x168:
			if (mode)
			{
				opw1_inventory->input(&XEvent(0x124));
				return true;
			}
			break;
		case 0x169:
			if (mode)
			{
				close(true);
				return true;
			}
			break;
	}
	return false;
}

void CPartmanage::inputAscii(int key, int modifier)
{
	if (skipKey)
	{
		skipKey = false;
		return;
	}
	if (opw1_world->unknown71bbd0())
		return;
	bool wasA = opw1_cec14d;
	bool wasB = opw1_cec14e;
	switch (modifier)
	{
		case 1:
			key += 0x20;
		case 0:
			switch (mode)
			{
				case 2:
					close(false);
					opw1_cec14d = true;
					opw1_cefca8 = true;
					opw1_cec088->inputAscii(key,0);
					opw1_cefca8 = false;
					break;
				case 4:
					close(false);
					opw1_cefca8 = true;
					opw1_cec088->inputAscii(key - 0x20,1);
					opw1_cefca8 = false;
					break;
				case 5:
					opw1_cec14e = true;
					opw1_cefca8 = true;
					opw1_cec088->inputAscii(key,0);
					opw1_cefca8 = false;
					close(false);
					break;
				case 6:
					opw1_cec14e = true;
					opw1_cefca8 = true;
					opw1_cec088->inputAscii(key,0);
					opw1_cefca8 = false;
					close(false);
					break;
			}
			break;
		case 2:
		{
			int index = key == 0x30 ? 9 : key - 0x31;
			if (index >= opw1_inventory->getRecords()->size())
				break;
			switch (mode)
			{
				case 3:
					close(false);
					opw1_inventory->input(&XEvent(index + 0x136));
					break;
				case 4:
					close(false);
					opw1_inventory->input(&XEvent(index + 0x12c));
					break;
				case 6:
					close(false);
					opw1_inventory->input(&XEvent(index + 0x140));
					break;
			}
		}
			break;
	}
	opw1_cec14d = wasA;
	opw1_cec14e = wasB;
}

//==================================================================
// CMapshift
//==================================================================

class CMapshift : public Console
{
public:
	void open();	// NOTE: placeholder name
	void close();	// NOTE: placeholder name
	virtual bool input(XEvent *event);

	bool active;	// NOTE: placeholder name
};

void CMapshift::open()
{
	if (!opw1_d28c8a)
		return;
	if (!opw1_cec118->isHidden())
		opw1_cec118->unknown8b5080();
	if (!opw1_cec11c->isHidden())
		opw1_cec11c->unknown8b5080();
	if (!opw1_cec120->isHidden())
		opw1_cec120->unknown8b5080();
	if (opw1_cec054->operate())
		opw1_cec054->unknown827950();
	active = true;
	opw1_keyMap->registerConsole(0x19,this,0x16b,0);
}

void CMapshift::close()
{
	active = false;
	opw1_playSound(0x2a,0,0);
	opw1_keyMap->unknown416640();
	if (opw1_cec0a4)
		((OpW1_Unk4ac780*)opw1_cec0a4)->resetField();
}

bool CMapshift::input(XEvent *event)
{
	if (isHidden() || opw1_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opw1_world->unknown71bbd0())
		return false;
	switch (event->type)
	{
		case 5:
			return false;
		case 0x16a:
			if (!active)
			{
				open();
				return true;
			}
		case 0x16b:
			if (active)
				close();
			return true;
		default:
			if (active && opw1_isBetween(0x16c,event->type,0x173))
			{
				opw1_cec054->input(&XEvent(event->type - 0x110));
				return true;
			}
	}
	return false;
}

//==================================================================
// CItemTag
//==================================================================

class CItemTag : public Console
{
public:
	void openForEntity(HEntity entity, bool flag);	// NOTE: placeholder name
	void openForPos(const Pos &pos, bool flag);	// NOTE: placeholder name
	void open(bool flag);	// NOTE: placeholder name
	void close();	// NOTE: placeholder name
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);
	HProp getItem();	// NOTE: placeholder name (0x4b1b30)
	int getMode();	// NOTE: placeholder name (folded getter)
	HEntity getEntity();	// NOTE: placeholder name (0x4ab6b0)
	Pos getPos();	// NOTE: placeholder name (0x4ab6d0)

	int mode;	// NOTE: placeholder name
	bool active;	// NOTE: placeholder name
	HProp item;	// NOTE: placeholder name
	HEntity entity;	// NOTE: placeholder name
	Pos pos;	// NOTE: placeholder name
	bool collapsedInventory;	// NOTE: placeholder name
};
extern CItemTag *opw1_itemTag;	// NOTE: placeholder name (0xcec0a0)

void CItemTag::openForEntity(HEntity entity_, bool flag)
{
	mode = 2;
	entity = entity_;
	open(flag);
}

void CItemTag::openForPos(const Pos &pos_, bool flag)
{
	mode = 3;
	pos = pos_;
	open(flag);
}

bool OpW1_itemTagClick()	// NOTE: placeholder name
{
	Pos mousePos = opw1_mouse->getPos();
	if (opw1_inventory->contains(mousePos) && opw1_itemTag->getItem().isNull())
	{
		int index = opw1_inventory->unknown8a20b0();
		if (index != -1)
		{
			opw1_itemTag->inputAscii(index == 9 ? 0x30 : index + 0x31,2);
			return true;
		}
	}
	return false;
}

void CItemTag::close()
{
	active = false;
	item.reset();
	entity.reset();
	pos.set(-1);
	opw1_playSound(0x2a,0,0);
	opw1_keyMap->unknown416640();
	if (collapsedInventory)
	{
		opw1_inventory->unknown8a53c0();
		collapsedInventory = false;
	}
	opw1_consoleInputBlocked = true;
}

bool CItemTag::input(XEvent *event)
{
	if (isHidden() || opw1_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opw1_world->unknown71bbd0())
		return false;
	switch (event->type)
	{
		case 5:
			return false;
		case 0x174:
		case 0x175:
			if (!active)
			{
				switch (event->type)
				{
					case 0x174:
						mode = 0;
						if (opw1_inventory->getRecords()->empty())
							opw1_cec0f4->add(new OpW1_Message(0x81,0,0,0,HProp(),HProp()));
						else
							open(true);
						break;
					case 0x175:
						mode = 1;
						open(true);
						break;
				}
				return true;
			}
		case 0x176:
			if (active)
				close();
			return true;
	}
	return false;
}

void CItemTag::inputAscii(int key, int modifier)
{
	if (opw1_world->unknown71bbd0())
		return;
	switch (modifier)
	{
		case 2:
			int index = key == 0x30 ? 9 : key - 0x31;
			if (index >= opw1_inventory->getRecords()->size())
			{
				opw1_cec0f4->add(new OpW1_Message(0x82,0,0,0,HProp(),HProp()));
				close();
				return;
			}
			item = (*opw1_inventory->getRecords())[index]->item;
			const int width = 0x34;
			const int boxHeight = 4;
			Rect dialogRect;
			int alignment;
			if (opw1_cefc90 == 2)
			{
				dialogRect.x = opw1_inventory->getPos().x + 2;
				dialogRect.y = opw1_inventory->getPos().y + (*opw1_inventory->getRecords())[index]->getPos().y - 4;
				alignment = 2;
			}
			else
			{
				dialogRect.x = opw1_inventory->getPos().x - width;
				dialogRect.y = opw1_inventory->getPos().y + (*opw1_inventory->getRecords())[index]->getPos().y - 2;
				alignment = 0;
			}
			dialogRect.width = width;
			dialogRect.height = boxHeight;
			if (dialogRect.y + dialogRect.height >= opw1_rex.unknown4189a0())
				dialogRect.y = opw1_rex.unknown4189a0() - dialogRect.height;
			string caption = "\\ Tag " + item->getName(0,0) + " \\";
			new OpW1_TextWindow(opw1_cec034,dialogRect,0,caption,alignment,cItemTagConsoleDone,0,0x19,0);
			opw1_textWindow->input->unknown4544c0(0x2e);
			break;
	}
}

void CItemTag::open(bool flag)
{
	active = true;
	opw1_keyMap->registerConsole(0x1a,this,0x176,0);
	switch (mode)
	{
		case 0:
			opw1_keyMap->setClickHandler(OpW1_itemTagClick);
			if (opw1_cefc90 == 1)
			{
				opw1_inventory->unknown8a53c0();
				collapsedInventory = true;
			}
			break;
		case 1:
		{
			const int width = 0x4b;
			const int boxHeight = 4;
			Rect dialogRect;
			dialogRect.x = opw1_centerOffset(width / opw1_caf128,opw1_cec054->getWidth());
			dialogRect.y = opw1_centerOffset(boxHeight,opw1_cec054->getHeight());
			dialogRect.width = width;
			dialogRect.height = boxHeight;
			string caption = "\\ Add Log Note \\";
			new OpW1_TextWindow(opw1_cec054,dialogRect,0,caption,0,cItemTagConsoleDone,0,0x19,0);
			if (flag)
				opw1_textWindow->input->setUnknown95(true);
			opw1_textWindow->input->unknown4544c0(200);
		}
			break;
		case 2:
		{
			const int maxLength = 0x24;
			const int width = 0x2a;
			const int consoleHeight = 4;
			Rect dialogRect;
			dialogRect.width = width;
			dialogRect.height = consoleHeight;
			dialogRect.x = 0;
			dialogRect.y = opw1_info->getUnknownCC()->y;
			if (dialogRect.y + dialogRect.height - 1 > opw1_info->getMaxCoord().y)
				dialogRect.y -= opw1_info->getUnknownCC()->y + dialogRect.height - 1 - opw1_info->getMaxCoord().y;
			string nameCopy = *entity->getNameAt0c();
			if (nameCopy[0] == '*')
				nameCopy.erase(nameCopy.begin());
			string text = "\\ Name " + opw1_truncate(nameCopy,0x1a) + " \\";
			new OpW1_TextWindow(opw1_info,dialogRect,0,text,0,cItemTagConsoleDone,0,0x19,0);
			if (flag)
				opw1_textWindow->input->setUnknown95(true);
			opw1_textWindow->input->unknown4544c0(maxLength);
		}
			break;
		case 3:
		{
			const int width = 0x4b;
			const int boxHeight = 4;
			Rect dialogRect;
			dialogRect.x = opw1_centerOffset(width / opw1_caf128,opw1_cec054->getWidth());
			dialogRect.y = opw1_centerOffset(boxHeight,opw1_cec054->getHeight());
			dialogRect.width = width;
			dialogRect.height = boxHeight;
			string caption = "\\ Add Map Comment \\";
			new OpW1_TextWindow(opw1_cec054,dialogRect,0,caption,0,cItemTagConsoleDone,0,0x19,0);
			if (flag)
				opw1_textWindow->input->setUnknown95(true);
			opw1_textWindow->input->unknown4544c0(100);
			vector<OpW1_MapNote*> *annotations = opw1_world->getMapNotes();
			for (unsigned int i = 0; i < annotations->size(); i++)
			{
				if ((*annotations)[i]->isAt(pos))
				{
					opw1_textWindow->input->setText((*annotations)[i]->text);
					break;
				}
			}
		}
			break;
	}
}

void cItemTagConsoleDone(const string &input)
{
	string text = input;
	opw1_textWindow->closeWindow();
	switch (opw1_itemTag->getMode())
	{
		case 0:
			if (!text.empty() || (text.empty() && opw1_itemTag->getItem()->unknown4579d0()))
			{
				opw1_itemTag->getItem()->unknown458700(text);
				if (!opw1_inventory->unknown8a54c0(opw1_itemTag->getItem(),1))
					logError("cItemTagConsoleDone()","No corresponding CInventoryItem");
				if (!text.empty() && opw1_itemTag->getItem()->unknown457f90() == 0xd6 && opw1_cf45d8.unknown780790())
					opw1_cf4ac8->unknown30->unknown7aa280(0x2a,0,text);
			}
			break;
		case 1:
			if (!text.empty())
			{
				do
				{
					if (opw1_unknown5111e0(0x32b,text,0,0,HProp(),HProp(),0,0))
						opw1_cec058->unknown8758d0(1);
					opw1_cec0b4->unknown7b4f10();
				} while (0);
			}
			break;
		case 2:
			if (!text.empty())
			{
				HEntity entity = opw1_itemTag->getEntity();
				string name = *entity->getNameAt0c();
				if (name[0] == '*')
					name.erase(name.begin());
				if (text != name)
				{
					do
					{
						if (opw1_unknown5111e0(0x32c,name,&text,0,HProp(),HProp(),0,0))
							opw1_cec058->unknown8758d0(1);
						opw1_cec0b4->unknown7b4f10();
					} while (0);
					text = '*' + text;
					entity->unknown45b070(text);
					if (!opw1_info->isHidden())
						opw1_info->unknown8b4500(entity,HProp(),HProp(),OpW1_Pair(-1),0,0);
					opw1_cec0c8->unknown7b8500(entity);
				}
			}
			break;
		case 3:
			if (!text.empty())
				opw1_world->unknown729eb0(opw1_itemTag->getPos(),text,0,1);
			break;
	}
	opw1_itemTag->close();
}

//==================================================================
// CSearch consoles
//==================================================================

extern XColor *opw1_d20438;	// NOTE: placeholder name
extern XColor *opw1_d22fcc;	// NOTE: placeholder name
extern XColor opw1_cf6f2c;	// NOTE: placeholder name
extern vector<XColor> opw1_d2b4bc;	// NOTE: placeholder name
extern bool opw1_cefc5c;	// NOTE: placeholder name

class OpW1_SearchResults : public Console	// NOTE: placeholder name (CSearchResults at 0xcec0a8)
{
public:
	int getCount();	// NOTE: placeholder name (0x4ac6a0)
	void unknown8af2b0(const Pos &pos);	// NOTE: placeholder name
	void unknown8ae990(int a, int b);	// NOTE: placeholder name
};
extern OpW1_SearchResults *opw1_searchResults;	// NOTE: placeholder name

class CSearchItem : public Console
{
public:
	virtual bool input(XEvent *event);
	virtual void update();

	int unknown6c;
	Pos pos;	// NOTE: placeholder name
	int mode;	// NOTE: placeholder name
};

void CSearchItem::update()
{
	if (isHidden())
		return;
	engine->unknown50fff0();
	if (opw1_cec054->unknown805060(pos))
		putChar_418110(0,0,0x2a,*opw1_d20438);
	else
		putChar_4180b0(0,0,0x20);
	XConsole::update();
}

bool CSearchItem::input(XEvent *event)
{
	if (opw1_world->unknown71bbd0())
		return false;
	switch (event->type)
	{
		case 5:
			switch (mode)
			{
				case 0:
					opw1_searchResults->unknown8af2b0(pos);
					break;
				case 1:
					opw1_searchResults->unknown8ae990(-1,-1);
					break;
				case 2:
					opw1_searchResults->unknown8ae990(1,-1);
					break;
			}
			return true;
	}
	return false;
}

class CSearchResultsCounter : public Console
{
public:
	virtual void update();
	void updateText();	// NOTE: placeholder name

	int total;	// NOTE: placeholder name
	int count;	// NOTE: placeholder name
};

void CSearchResultsCounter::update()
{
	if (opw1_searchResults->getCount() != count)
		updateText();
}

void CSearchResultsCounter::updateText()
{
	count = opw1_searchResults->getCount();
	string text = " MATCHES " + intToString(count) + " / " + intToString(total) + " ";
	if (getWidth() != text.size())
		resize(text.size(),1);
	setFore(*opw1_COLOR_BLACK);
	opw1_d2b4bc[0] = opw1_cf6f2c;
	print(0,0,"`b" + intToString(0) + "`" + text + "`x`");
}

class OpW1_SearchFilter	// NOTE: placeholder name
{
public:
	int getMode();	// NOTE: placeholder name (folded getter)
};

struct OpW1_Point : public Pos	// NOTE: placeholder name
{
	OpW1_Point() throw();	// 0x453b40
	void set(int x_, int y_) throw();	// NOTE: placeholder name (0x40a010)
};
int opw1_distance(const Pos &a, const Pos &b) throw();	// NOTE: placeholder name (0x40a3f0)

struct OpW1_Result : public OpW1_Point	// NOTE: placeholder name (0xc bytes)
{
	OpW1_Result(int x_, int y_);

	int distance;	// NOTE: placeholder name
};

class OpW1_ResultRow : public Console	// NOTE: placeholder name (0x7c bytes)
{
public:
	OpW1_ResultRow(class CSearchResults *parent, int y, OpW1_Result *result, int mode, int index);	// 0x4ab780
	void setKey(int key);	// NOTE: placeholder name (0x4ac250)

	int unknown6c;
	Pos pos;	// NOTE: placeholder name
	char pad78[0x7c - 0x78];
};

class CSearchResults : public Console
{
public:
	CSearchResults(XConsole *parent, const Rect &rect);	// 0x4ac420
	virtual void update();
	bool updateResults(bool force);	// NOTE: placeholder name
	void rebuildRows();	// NOTE: placeholder name
	void selectPos(const Pos &pos);	// NOTE: placeholder name
	void scroll(int delta, int a);	// NOTE: placeholder name (0x8ae990)
	virtual bool input(XEvent *event);
	virtual void inputAscii(int key, int modifier);

	string searchText;	// NOTE: placeholder name
	vector<OpW1_Result*> results;	// NOTE: placeholder name
	vector<OpW1_ResultRow*> rows;	// NOTE: placeholder name
	int pageSize;	// NOTE: placeholder name
	int offset;	// NOTE: placeholder name
	Console *unknownB0;
	OpW1_ResultRow *unknownB4;
	Pos lastPos;	// NOTE: placeholder name
	unsigned int lastTime;	// NOTE: placeholder name
	OpW1_SearchFilter *filter;	// NOTE: placeholder name
};

void CSearchResults::update()
{
	if (isHidden())
		return;
	engine->unknown50fff0();
	if (updateResults(false))
		rebuildRows();
	clearRow(1,getHeight() / 2,getWidth() - 2);
	if (rows.empty())
	{
		setFore(*opw1_d22fcc);
		string text = filter->getMode() ? "No matches found" : "No known items";
		if (opw1_cefc5c)
			text = "\"Botnet is a reasonable hack.\" - MTF, 2021";
		printAligned(getWidth() / 2,getHeight() / 2,1,text);
	}
	XConsole::update();
}

struct OpW1_ItemFlag	// NOTE: placeholder name
{
	bool get();	// NOTE: placeholder name (folded getter)
};

struct OpW1_ItemSlotInfo	// NOTE: placeholder name
{
	char pad00[0x2c];
	int slot;	// NOTE: placeholder name
};

struct OpW1_ItemData	// NOTE: placeholder name
{
	int id;	// NOTE: placeholder name
	char pad04[0x44 - 0x04];
	int unknown44;
	int category;	// NOTE: placeholder name
	int pad4c;
	int unknown50;
	int unknown54;
	char pad58[0x7c - 0x58];
	OpW1_ItemFlag unknown7c;
	char pad80[0x128 - 0x80];
	int slot;	// NOTE: placeholder name
	char pad12c[0x1a0 - 0x12c];
	OpW1_ItemSlotInfo *slotInfo;	// NOTE: placeholder name

	string getName(int a, int b);	// NOTE: placeholder name (0x55eb20)
};

struct OpW1_SearchEntry	// NOTE: placeholder name
{
	char pad00[0x10];
	int type;	// NOTE: placeholder name
	int unknown14;
	int rating;	// NOTE: placeholder name
	char pad1c[0x20 - 0x1c];
	int unknown20;
};

extern vector<OpW1_ItemData*> opw1_itemData;	// NOTE: placeholder name (0xd2d1c4)
extern vector<int*> opw1_cf4830;	// NOTE: placeholder name
extern vector<int*> opw1_d25790;	// NOTE: placeholder name
int opw1_findNoCase(string &text, string &term) throw();	// NOTE: placeholder name (0x4078c0)
enum OpW1_ItemType {};	// NOTE: placeholder name
bool opw1_contains(vector<OpW1_ItemType> *list, int value);	// NOTE: placeholder name (0x9db330)

struct OpW1_SearchQuery	// NOTE: placeholder name
{
	OpW1_SearchQuery(const string &text);	// 0x8ace40
	bool matches(OpW1_SearchEntry *entry);	// NOTE: placeholder name

	vector<string> terms;	// NOTE: placeholder name
	int category;	// NOTE: placeholder name
	vector<OpW1_ItemType> types;	// NOTE: placeholder name
	int slot;	// NOTE: placeholder name
	int minRating;	// NOTE: placeholder name
	int unknown2c;
	bool unknown30;
	bool unknown31;
};

void opw1_split(const string &text, char separator, vector<string> &out);	// NOTE: placeholder name (0x408700)
void opw1_trim(string &text, char ch);	// NOTE: placeholder name (0x408600)
bool opw1_startsWith(const string &text, const string &prefix) throw();	// NOTE: placeholder name (0x4079f0)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
int opw1_clampInt(int low, int value, int high);	// NOTE: placeholder name (0x9cdc80)

OpW1_SearchQuery::OpW1_SearchQuery(const string &text)
	: category(4), slot(10), minRating(0), unknown2c(0), unknown30(false), unknown31(false)
{
	vector<string> words;
	opw1_split(text,',',words);
	bool started = false;
	for (unsigned int i = 0; i < words.size(); i++)
	{
		string &word = words[i];
		opw1_trim(word,' ');
		if (!word.empty())
		{
			if (started || word[0] == '.')
			{
				started = true;
				if (word[0] == '.')
					word.erase(word.begin());
				if (!word.empty())
				{
					if (opw1_startsWith(word,"po"))
					{
						if (category == 4)
							category = 0;
					}
					else if (opw1_startsWith(word,"prop"))
					{
						if (category == 4)
							category = 1;
					}
					else if (opw1_startsWith(word,"ut"))
					{
						if (category == 4)
							category = 2;
					}
					else if (opw1_startsWith(word,"we"))
					{
						if (category == 4)
							category = 3;
					}
					else if (opw1_startsWith(word,"mat"))
					{
						types.push_back((OpW1_ItemType)0);
					}
					else if (opw1_startsWith(word,"dat"))
					{
						types.push_back((OpW1_ItemType)1);
					}
					else if (opw1_startsWith(word,"non"))
					{
						for (int j = 0; j < 6; j++)
							types.push_back((OpW1_ItemType)j);
					}
					else if (opw1_startsWith(word,"tra"))
					{
						types.push_back((OpW1_ItemType)5);
					}
					else if (opw1_startsWith(word,"tre"))
					{
						types.push_back((OpW1_ItemType)9);
					}
					else if (opw1_startsWith(word,"leg"))
					{
						types.push_back((OpW1_ItemType)10);
					}
					else if (opw1_startsWith(word,"whe"))
					{
						types.push_back((OpW1_ItemType)11);
					}
					else if (opw1_startsWith(word,"hov"))
					{
						types.push_back((OpW1_ItemType)12);
					}
					else if (opw1_startsWith(word,"fli"))
					{
						types.push_back((OpW1_ItemType)13);
					}
					else if (opw1_startsWith(word,"dev"))
					{
						types.push_back((OpW1_ItemType)14);
					}
					else if (opw1_startsWith(word,"sto"))
					{
						types.push_back((OpW1_ItemType)15);
					}
					else if (opw1_startsWith(word,"proc"))
					{
						types.push_back((OpW1_ItemType)16);
					}
					else if (opw1_startsWith(word,"hac"))
					{
						types.push_back((OpW1_ItemType)17);
					}
					else if (opw1_startsWith(word,"arm"))
					{
						types.push_back((OpW1_ItemType)18);
					}
					else if (opw1_startsWith(word,"ali"))
					{
						types.push_back((OpW1_ItemType)19);
					}
					else if (opw1_startsWith(word,"gun"))
					{
						types.push_back((OpW1_ItemType)20);
						types.push_back((OpW1_ItemType)22);
					}
					else if (opw1_startsWith(word,"can"))
					{
						types.push_back((OpW1_ItemType)21);
						types.push_back((OpW1_ItemType)23);
					}
					else if (opw1_startsWith(word,"lau"))
					{
						types.push_back((OpW1_ItemType)24);
					}
					else if (opw1_startsWith(word,"spe"))
					{
						types.push_back((OpW1_ItemType)25);
					}
					else if (opw1_startsWith(word,"mel"))
					{
						types.push_back((OpW1_ItemType)26);
						types.push_back((OpW1_ItemType)27);
						types.push_back((OpW1_ItemType)28);
						types.push_back((OpW1_ItemType)29);
						types.push_back((OpW1_ItemType)30);
					}
					else if (opw1_startsWith(word,"ki"))
					{
						if (slot == 10)
							slot = 0;
					}
					else if (opw1_startsWith(word,"th"))
					{
						if (slot == 10)
							slot = 1;
					}
					else if (opw1_startsWith(word,"ex"))
					{
						if (slot == 10)
							slot = 2;
					}
					else if (opw1_startsWith(word,"em"))
					{
						if (slot == 10)
							slot = 3;
					}
					else if (opw1_startsWith(word,"imp"))
					{
						if (slot == 10)
							slot = 4;
					}
					else if (opw1_startsWith(word,"sla"))
					{
						if (slot == 10)
							slot = 5;
					}
					else if (opw1_startsWith(word,"pie"))
					{
						if (slot == 10)
							slot = 6;
					}
					else if (opw1_startsWith(word,"en"))
					{
						if (slot == 10)
							slot = 7;
					}
					else if (opw1_startsWith(word,"ph"))
					{
						if (slot == 10)
							slot = 8;
					}
					else
					{
						if (isdigit(word[0]))
						{
							if (word.find('%') != string::npos)
							{
								for (int j = word.size() - 1; j > 0; j--)
								{
									if (!isdigit(word[j]))
										word.erase(word.begin() + j);
								}
								if (!word.empty())
									minRating = opw1_clampInt(0,stringToInt(word),100);
							}
							else
							{
								for (int j = word.size() - 1; j > 0; j--)
								{
									if (!isdigit(word[j]))
										word.erase(word.begin() + j);
								}
								if (!word.empty())
									unknown2c = opw1_clampInt(0,stringToInt(word),10);
							}
						}
						if (opw1_startsWith(word,"uni"))
							unknown30 = true;
						if (opw1_startsWith(word,"unc"))
							unknown31 = true;
					}
				}
			}
			else
				terms.push_back(word);
		}
	}
}

bool OpW1_SearchQuery::matches(OpW1_SearchEntry *entry)
{
	OpW1_ItemData *data = opw1_itemData[entry->type];
	if (!terms.empty())
	{
		for (unsigned int i = 0; i < terms.size(); i++)
		{
			bool negate = false;
			string term;
			if (terms[i][0] == '-' && terms[i].size() > 1)
			{
				term.assign(terms[i].begin() + 1,terms[i].end());
				negate = true;
			}
			else
				term = terms[i];
			if (negate)
			{
				if (opw1_findNoCase(data->getName(entry->unknown14,entry->unknown20),term) != -1)
					return false;
			}
			else
			{
				if (opw1_findNoCase(data->getName(entry->unknown14,entry->unknown20),term) == -1)
					return false;
			}
		}
	}
	if (category != 4 && data->category != category)
		return false;
	if (!types.empty() && !opw1_contains(&types,data->unknown44))
		return false;
	if (opw1_cf4830[entry->type] == 0)
	{
		if (slot != 10 || minRating != 0 || unknown2c != 0 || unknown30 || unknown31)
			return false;
		else
			return true;
	}
	if (slot != 10)
	{
		if (data->slotInfo && data->slotInfo->slot != slot)
			return false;
		else if (data->slot != slot)
			return false;
	}
	if (minRating && entry->rating < minRating)
		return false;
	if (unknown2c && data->unknown50 < unknown2c)
		return false;
	if (unknown30 && data->unknown54)
		return false;
	if (unknown31 && (data->unknown7c.get() || opw1_d25790[data->id] != 0))
		return false;
	return true;
}

class OpW1_Grid	// NOTE: placeholder name
{
public:
	OpW1_SearchEntry *get(int x, int y);	// NOTE: placeholder name (0x9d2c30)
};
class OpW1_MapSize	// NOTE: placeholder name (0xcfd44c)
{
public:
	int getWidth();	// NOTE: placeholder name
	int getHeight();	// NOTE: placeholder name
};
extern OpW1_MapSize opw1_cfd44c;	// NOTE: placeholder name
extern int opw1_caf164;	// NOTE: placeholder name
void opw1_deleteAll(vector<OpW1_Result*> *list);	// NOTE: placeholder name (0x9d0670)
void opw1_clamp(int low, int &value, int high);	// NOTE: placeholder name (0x9cdc50)
template <class T> void OpW1_insertAt(vector<T> &v, int i, T e);	// NOTE: placeholder name (0x9dbdc0)
bool opw1_compareResults(OpW1_Result *a, OpW1_Result *b);	// NOTE: placeholder name (0x4ac400)

OpW1_Result::OpW1_Result(int x_, int y_)
{
	set(x_,y_);
	distance = opw1_distance(opw1_world->getPlayerNothrow().get_9b6570()->getPositionNothrow(),*this);
}

bool CSearchResults::updateResults(bool force)
{
	if (!force && opw1_textWindow->input->getText() == searchText)
		return false;
	opw1_deleteAll(&results);
	searchText = opw1_textWindow->input->getText();
	OpW1_SearchQuery query(searchText);
	bool all = searchText.empty();
	OpW1_Grid *grid = opw1_world->getGrid();
	OpW1_Result *newResult;
	vector<OpW1_Result*>::iterator insertPos;
	for (int x = 0; x < opw1_cfd44c.getWidth(); x++)
	{
		for (int y = 0; y < opw1_cfd44c.getHeight(); y++)
		{
			if (grid->get(x,y)->type != opw1_caf164)
			{
				if (all || query.matches(grid->get(x,y)))
				{
					newResult = new OpW1_Result(x,y);
					insertPos = lower_bound(results.begin(),results.end(),newResult,opw1_compareResults);
					results.insert(insertPos,newResult);
				}
			}
		}
	}
	offset = 0;
	return true;
}

void CSearchResults::rebuildRows()
{
	for (unsigned int i = 0; i < rows.size(); i++)
	{
		if (rows[i])
			removeSubconsole(rows[i]);
	}
	rows.clear();
	if (unknownB0)
	{
		removeSubconsole(unknownB0);
		unknownB0 = NULL;
	}
	if (unknownB4)
	{
		removeSubconsole(unknownB4);
		unknownB4 = NULL;
	}
	for (unsigned int i = 0, y = 2; i < results.size(); i++, y++)
	{
		if (i == 0x1a)
		{
			unknownB4 = new OpW1_ResultRow(this,y,results[i],2,0);
			break;
		}
		else
			rows.push_back(new OpW1_ResultRow(this,y,results[i],0,i));
	}
	for (unsigned int i = 0, hotkey = 'a'; i < rows.size(); i++, hotkey++)
		rows[i]->setKey(hotkey);
}

void CSearchResults::scroll(int delta, int target)
{
	if (results.size() <= 0x1a)
		return;
	int newOffset = (target == -1 ? offset + delta : target);
	opw1_clamp(0,newOffset,results.size() - 0x1a);
	if (newOffset != offset)
	{
		if (unknownB0)
			removeSubconsole(unknownB0);
		if (newOffset > 0)
			unknownB0 = new OpW1_ResultRow(this,1,results[newOffset - 1],1,0);
		else
			unknownB0 = NULL;
		if (unknownB4)
			removeSubconsole(unknownB4);
		if (newOffset + 0x1a < results.size())
			unknownB4 = new OpW1_ResultRow(this,0x1c,results[newOffset + 0x1a],2,0);
		else
			unknownB4 = NULL;
		if (newOffset + 0x1a <= offset || newOffset >= offset + 0x1a)
		{
			for (unsigned int i = 0; i < rows.size(); i++)
			{
				if (rows[i])
					removeSubconsole(rows[i]);
			}
			rows.clear();
			for (int i = newOffset, y = 2; i < newOffset + 0x1a; i++, y++)
				rows.push_back(new OpW1_ResultRow(this,y,results[i],0,i));
		}
		else if (newOffset < offset)
		{
			for (int i = 0; i < offset - newOffset; i++)
			{
				removeSubconsole(rows.back());
				rows.pop_back();
			}
			for (unsigned int i = 0; i < rows.size(); i++)
				rows[i]->setPos(Pos(2,rows[i]->getPos().y + (offset - newOffset)));
			for (int i = 0, y = rows.front()->getPos().y - 1, index = rows.front()->unknown6c - 1; i < offset - newOffset; i++, y--, index--)
				OpW1_insertAt(rows,0,new OpW1_ResultRow(this,y,results[index],0,index));
			for (unsigned int i = 0, index = newOffset; i < rows.size(); i++, index++)
				rows[i]->unknown6c = index;
		}
		else
		{
			for (int i = 0; i < newOffset - offset; i++)
			{
				removeSubconsole(rows.front());
				rows.erase(rows.begin());
			}
			for (unsigned int i = 0; i < rows.size(); i++)
				rows[i]->setPos(Pos(2,rows[i]->getPos().y - (newOffset - offset)));
			for (int i = 0, y = rows.back()->getPos().y + 1, index = rows.back()->unknown6c + 1; i < newOffset - offset; i++, y++, index++)
				rows.push_back(new OpW1_ResultRow(this,y,results[index],0,index));
			for (unsigned int i = 0, index = newOffset; i < rows.size(); i++, index++)
				rows[i]->unknown6c = index;
		}
		offset = newOffset;
		for (unsigned int i = 0, hotkey = 'a'; i < rows.size(); i++, hotkey++)
			rows[i]->setKey(hotkey);
	}
}

class OpW1_Cell	// NOTE: placeholder name (Cell)
{
public:
	HProp getItem();	// NOTE: placeholder name (0x45d8f0)
};
class OpW1_CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	OpW1_Cell *&get(const Pos &pos);	// NOTE: placeholder name (0x9ced70)
};
extern OpW1_CellGrid opw1_cells;	// NOTE: placeholder name
extern unsigned int opw1_d28e98;	// NOTE: placeholder name

class CSearch : public Console
{
public:
	void open(bool flag);	// NOTE: placeholder name
	void close();	// NOTE: placeholder name
	virtual bool input(XEvent *event);

	bool active;	// NOTE: placeholder name
	Console *unknown70;	// NOTE: placeholder name
	CSearchResults *results;	// NOTE: placeholder name
	int unknown78;
};

void CSearchResults::selectPos(const Pos &pos)
{
	opw1_cec054->unknown8069e0(pos,1);
	if (pos == lastPos && opw1_d28e98)
	{
		if (opw1_tickCount < lastTime + opw1_d28e98)
		{
			opw1_cefc80 = opw1_tickCount + 200;
			opw1_cec054->unknown49b740();
			if (opw1_d28c8a)
			{
				opw1_cec054->unknown49b650(pos);
				opw1_cec0a4->close();
				opw1_cec054->input(&XEvent(0x93));
			}
			else
			{
				opw1_cec054->unknown806e70(pos,1);
				opw1_cec0a4->close();
				opw1_cec054->input(&XEvent(0x99));
			}
			return;
		}
	}
	else
		lastPos = pos;
	lastTime = opw1_tickCount;
	opw1_cec054->unknown8142d0(0x12,0);
	if (!opw1_world->isVisible(pos))
		opw1_cec054->unknown812950(pos,6);
	else
		opw1_cec054->unknown8119c0(opw1_cells.get(pos)->getItem(),0,0,0);
}

void CSearch::close()
{
	if (unknown78)
		unknown78--;
	else if (active)
	{
		if (opw1_textWindow)
			opw1_textWindow->closeWindow();
		resize(1,1);
		resetBack_418450();
		active = false;
		if (unknown70)
		{
			removeSubconsole(unknown70);
			unknown70 = NULL;
		}
		if (results)
		{
			removeSubconsole(results);
			results = NULL;
		}
		opw1_playSound(0x2a,0,0);
		opw1_keyMap->unknown416640();
	}
}

bool CSearch::input(XEvent *event)
{
	if (isHidden() || opw1_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opw1_world->unknown71bbd0())
		return false;
	switch (event->type)
	{
		case 5:
			return false;
		case 0x177:
			if (!active)
			{
				open(true);
				return true;
			}
		case 0x17e:
			if (active)
				close();
			return true;
	}
	return false;
}

bool CSearchResults::input(XEvent *event)
{
	if (isHidden() || opw1_consoleInputBlocked)
		return false;
	if (XConsole::input(event))
		return true;
	if (opw1_world->unknown71bbd0())
		return false;
	switch (event->type)
	{
		case 0x16c:
		case 0x178:
			scroll(-pageSize,-1);
			return true;
		case 0x170:
		case 0x179:
			scroll(pageSize,-1);
			return true;
		case 0x17a:
			if (offset > 0)
				scroll(-0x1a,-1);
			return true;
		case 0x17b:
			if (offset + 0x1a < results.size())
				scroll(0x1a,-1);
			return true;
		case 0x17c:
			scroll(-99999,-1);
			return true;
		case 0x17d:
			scroll(99999,-1);
			return true;
	}
	return false;
}

void CSearchResults::inputAscii(int key, int modifier)
{
	if (opw1_world->unknown71bbd0())
		return;
	switch (modifier)
	{
		case 0:
			if (opw1_cec14d)
			{
				int index = key - 0x61;
				if (index < rows.size())
					selectPos(rows[index]->pos);
			}
			break;
	}
}

void OpW1_searchConsoleDone(const string &text)	// NOTE: placeholder name
{
	if (opw1_cec0a4->unknown78)
		opw1_cec0a4->unknown78--;
	else if (!text.empty())
		opw1_textWindow->input->clear();
	else
	{
		string copy = text;
		opw1_textWindow->closeWindow();
		opw1_cec0a4->close();
	}
}

void OpW1_searchInputAscii(int key, int modifier)	// NOTE: placeholder name
{
	opw1_searchResults->inputAscii(key,modifier);
}

bool opw1_unknown4328a0();	// NOTE: placeholder name
extern int opw1_cf27f4;	// NOTE: placeholder name
extern int opw1_d38470;	// NOTE: placeholder name
extern XColor *opw1_d29758;	// NOTE: placeholder name
extern const char *opw1_cea788;	// NOTE: placeholder name
extern const char *opw1_cea78c;	// NOTE: placeholder name

void CSearch::open(bool flag)
{
	active = true;
	opw1_world->unknown72e8e0(0);
	opw1_keyMap->registerConsole(0x1b,NULL,-1,0);
	opw1_playSound(0x2e,0,0);
	Rect windowRect;
	if (opw1_unknown4328a0())
	{
		windowRect.x = opw1_cf27f4 * opw1_caf128;
		windowRect.y = 0;
		windowRect.width = 0x3c;
		windowRect.height = opw1_rex.unknown4189a0();
	}
	else
	{
		windowRect.x = opw1_cf27f4 * opw1_caf128;
		windowRect.y = opw1_d38470;
		windowRect.width = 0x3c;
		windowRect.height = opw1_rex.unknown4189a0() - opw1_d38470;
	}
	resetBack_418450();
	setPos(windowRect.x,windowRect.y);
	resize(windowRect.width,windowRect.height);
	Rect inputRect(0,0,windowRect.width,3);
	string title = "/ S E A R C H /";
	new OpW1_TextWindow(this,inputRect,0,title,4,OpW1_searchConsoleDone,1,0x19,1);
	if (flag)
		opw1_textWindow->input->setUnknown95(true);
	opw1_textWindow->input->unknown4544c0(200);
	opw1_textWindow->input->setKeyHandler(OpW1_searchInputAscii);
	opw1_textWindow->unknown78 = true;
	Rect resultsRect(inputRect.x,inputRect.height,inputRect.width,0x1e);
	bool collapsed = windowRect.height < 0x32;
	int listHeight = windowRect.height - (resultsRect.y + resultsRect.height) + 1;
	unknown70 = new Console(this,0x3c,listHeight,resultsRect.x,resultsRect.y + resultsRect.height - 1,0,false,-1);
	unknown70->setTitle(new OpW1_ConsoleTitle(unknown70,"N/A",0,4));
	unknown70->setFore(*opw1_d29758);
	unknown70->print(3,2,string(collapsed ? opw1_cea78c : opw1_cea788));
	if (!collapsed)
	{
		unknown70->setForeRow(4,9,8,*opw1_COLOR_BLACK);
		unknown70->setBackRow(4,9,8,*opw1_d29758);
		unknown70->setForeRow(0x16,9,9,*opw1_COLOR_BLACK);
		unknown70->setBackRow(0x16,9,9,*opw1_d29758);
	}
	unknown70->animate("CType_Border");
	results = new CSearchResults(this,resultsRect);
	opw1_keyMap->unknown4162e0(0x1b,1);
	opw1_keyMap->unknown4162e0(0x19,1);
}

//==================================================================
// CSpecialCommand
//==================================================================

extern int opw1_ceca68;	// NOTE: placeholder name
extern int opw1_ceca74;	// NOTE: placeholder name
extern int opw1_ceca78;	// NOTE: placeholder name
extern Pos opw1_cfbec0;	// NOTE: placeholder name
extern string opw1_commandNames[];	// NOTE: placeholder name (0xd2ccf0)

class CSpecialCommand : public Console
{
public:
	virtual void trigger(const string &command, int value);	// NOTE: placeholder name

	int command;	// NOTE: placeholder name
	char key;	// NOTE: placeholder name
};

void CSpecialCommand::trigger(const string &trigger, int value)
{
	if (trigger == "content")
	{
		string keyText;
		keyText += key;
		print(0,0,keyText);
		do
		{
			engine->unknown50fb50(engine,opw1_ceca74,&Pos(0,0),&opw1_cfbec0,NULL,NULL,9)->unknown50de10();
		} while (0);
		print(2,0,"-");
		do
		{
			engine->unknown50fb50(engine,opw1_ceca68,&Pos(2,0),&opw1_cfbec0,NULL,NULL,9)->unknown50de10();
		} while (0);
		print(4,0,"[");
		do
		{
			engine->unknown50fb50(engine,opw1_ceca74,&Pos(4,0),&opw1_cfbec0,NULL,NULL,9)->unknown50de10();
		} while (0);
		string name = opw1_commandNames[command];
		print(5,0,name);
		for (unsigned int i = 0; i < name.size(); i++)
		{
			do
			{
				engine->unknown50fb50(engine,opw1_ceca78,&Pos(i + 5,0),&opw1_cfbec0,NULL,NULL,9)->unknown50de10();
			} while (0);
		}
		int x = name.size() + 5;
		print(x,0,"]");
		do
		{
			engine->unknown50fb50(engine,opw1_ceca74,&Pos(x,0),&opw1_cfbec0,NULL,NULL,9)->unknown50de10();
		} while (0);
	}
}
