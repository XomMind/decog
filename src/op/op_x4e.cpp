// op_x4e: functions in 0x7f37f0-0x806d00 of COGMIND.exe (Beta 17.1). Names are placeholders unless stated.
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
	XColor &operator=(XColor color);
	XColor operator*(float f);
	XColor &operator*=(float f);
	bool operator!=(XColor color);
};

struct Pos
{
	int x;
	int y;

	Pos();	// 0x453b40
	Pos(int x_, int y_);
	Pos(int v);	// 0x409990
	void set_409ff0(int v);	// NOTE: placeholder name (sets both coordinates)
	Pos(const Pos &pos) throw();
	void set(int x_, int y_);	// 0x40a010 NOTE: placeholder name
	Pos &operator+=(const Pos &pos);	// 0x409a30
	void set_40a030(const Pos &pos);	// NOTE: placeholder name
	Pos operator-(const Pos &pos) const;	// 0x409b30
	Pos &operator*=(const Pos &pos);	// 0x409ab0 NOTE: placeholder name
	Pos &operator/=(const Pos &pos);	// 0x409af0 NOTE: placeholder name
	bool operator!=(const Pos &pos) const;	// 0x409bd0
	bool equals_409cb0(int x_, int y_);	// NOTE: placeholder name
	bool differs_409cf0(int x_, int y_);	// NOTE: placeholder name
	Pos &operator=(const Pos &pos);	// 0x46ca50
	Pos operator+(const Pos &pos) const;	// 0x409b60
	bool operator==(const Pos &pos) const;	// 0x409b90
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int width_, int height_) throw();	// 0x456940 (throw() as in op_w9.cpp: it cannot throw)
	Rect(const Rect &rect);
	void set(int x_, int y_, int width_, int height_);	// 0x40a840 NOTE: placeholder name
};

class XConsole;

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
	XConsole *getParent();	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	void setFore(XColor color) throw();
	void clearBack();	// NOTE: placeholder name
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch);	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch, XColor fore);	// NOTE: placeholder name
	void setCharColumn(int x, int y, int height, int ch, XColor fore);	// NOTE: placeholder name
	void setBackRow(int x, int y, int width, XColor color);
	void setForeRow(int x, int y, int width, XColor color);	// NOTE: placeholder name
	void setFore_417f80(int x, int y, XColor color);	// NOTE: placeholder name
	void setBackAll_418410(XColor color);	// NOTE: placeholder name
	void setPos(int x, int y);	// NOTE: placeholder name
	void setPos(const Pos &pos);
	void setHidden(bool hidden_);	// NOTE: placeholder name
	vector<XConsole*> *getSubconsoles() throw();
	void clear();	// NOTE: placeholder name
	void setScaleX(float scale);	// NOTE: placeholder name (0x417b60)
	void setScaleY(float scale);	// NOTE: placeholder name (0x417b80)
	int getLayer_44a7d0();	// NOTE: placeholder name
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	void putChar_418110(int x, int y, int ch, XColor fore);	// NOTE: placeholder name
	void resetBack_418450() throw();	// NOTE: placeholder name
	void setForeAll_4183d0(XColor color);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Pos &pos, int value);	// NOTE: placeholder name
	void clearInterior();
	int getSubconsoleIndex(XConsole *console);	// 0x417eb0
	void moveSubconsole(XConsole *console, int index);
	int countLines_418350(int x, int y, int width, int height, int align, const string &text);

	char pad04[0x60 - 0x04];
};

class OpW5_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class Engine
{
public:
	bool isRunning();	// NOTE: placeholder name (0x50fff0)
	void stopAll();	// NOTE: placeholder name (0x50ff30)
	class OpW5_EngineItem *unknown50fb50(Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
	void killGroup(string group);
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	virtual ~Console();

	virtual bool input(void *event);
	virtual void update();
	virtual void render();	// NOTE: placeholder name
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	void animate(string name);	// NOTE: placeholder name
	bool inputBase_429d00(void *event);	// NOTE: placeholder name
	Rect getRect();	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void setTitle(class ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void unknown7b0640(int a, XColor color, int b, int c);	// NOTE: placeholder name

	int unknown60;
	Engine *engine;
	void *title;
};

typedef Pos Point;

//==================================================================
// game-side declarations (partial; placeholder names)
//==================================================================

struct OpX4e_ItemType;

class Item	// NOTE: partial
{
public:
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name
	int unknown44aec0();	// NOTE: placeholder name (ICF'd trivial getter)
	OpX4e_ItemType *unknown9b4350();	// NOTE: placeholder name (ICF'd trivial getter)
	void *getEffect(int type);	// 0x457b70
	int unknown457c80();	// NOTE: placeholder name
	int getAmount_9b6bf0();	// NOTE: placeholder name (ICF'd trivial getter)
	bool unknown5773d0(bool a, bool b);	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	HItem();
	bool isValid() const;
	bool isNull() const;
	Item *operator->() const;	// 0x9b65b0
};

class HEntity;

class OpX4e_AI	// NOTE: placeholder name (EntityAI)
{
public:
	int unknown45ad90();	// NOTE: placeholder name (ICF'd trivial getter)
	bool unknown458fb0(HEntity e);	// NOTE: placeholder name
	bool unknown581140();	// NOTE: placeholder name
};

class OpX4e_Group	// NOTE: placeholder name
{
public:
	bool unknown45e3c0();	// NOTE: placeholder name (folded getter)
	vector<HEntity> *getMembers();	// NOTE: placeholder name (0x416f40)
	int unknown9b4350();	// NOTE: placeholder name (ICF'd trivial getter)
};

class OpX4e_HGroup	// NOTE: placeholder name
{
public:
	int ID;
	OpX4e_Group *operator->() const;	// 0x9b7250
};

class Entity	// NOTE: partial
{
public:
	Pos &getPosition();	// NOTE: placeholder name
	bool isPlayer();	// 0x5c7600
	OpX4e_AI *getAI();	// NOTE: placeholder name (0x45b590)
	bool isHostileTo(HEntity e);	// 0x45aa70
	OpX4e_HGroup getGroup();	// 0x45a3f0
	int unknown490840();	// NOTE: placeholder name (folded getter)
	int unknown5ca260();	// NOTE: placeholder name
	int unknown5cc190(int slot);	// NOTE: placeholder name
	HItem unknown5cc460(int slot, int maxSize);	// NOTE: placeholder name
	vector<HItem> *getInventoryList();	// 0x45ab00
	int getFaction();	// 0x45a2c0
	int unknown5c7d30();	// NOTE: placeholder name
	int unknown5d2150(int type, int a);	// NOTE: placeholder name
	bool unknown5d5250();	// NOTE: placeholder name
	bool unknown5d7670();	// NOTE: placeholder name
	void *getTarget();	// 0x45a760
	HItem unknown5d2380(int type);	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
	bool isValid() const;	// 0x9b7230
	void reset();	// 0x9b7270
	Entity *operator->() const;	// 0x9b6570
};

class Prop	// NOTE: partial
{
public:
	const string &getName();	// 0x45c5b0
};

class HProp
{
public:
	int ID;
	HProp();
	bool isValid() const;
	Prop *operator->() const;	// 0x9b64f0
};

class World	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	OpX4e_HGroup unknown463890(int i);	// NOTE: placeholder name
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	bool unknown465200(const Point &a, const Point &b);	// NOTE: placeholder name
	int getTurn();	// 0x464270
	HEntity getPlayer();	// 0x4630f0
	bool isVisible(const Point &p);	// 0x4631c0
	char pad0[0x66c];
	HEntity unknown66c;	// NOTE: placeholder name
};
extern World *opX4e_world;	// NOTE: placeholder name (0xcefc4c)
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name

struct OpX4e_InterfaceMessage	// NOTE: placeholder name (0x20 bytes, ctor 0x510d20)
{
	OpX4e_InterfaceMessage(int type, int a, int b, int c, HEntity d, HProp e);

	char pad00[0x20];
};

class OpX4e_InterfaceMsg	// NOTE: placeholder name (CInterfaceMsg at 0xcec0f4)
{
public:
	void add(OpX4e_InterfaceMessage *message);	// NOTE: placeholder name
};
extern OpX4e_InterfaceMsg *opX4e_interfaceMsg;	// NOTE: placeholder name (0xcec0f4)

class Area	// NOTE: placeholder name (two corner points)
{
public:
	Area();	// 0x40b100
	bool fitAround_40bcb0(const Point &p, int margin);	// NOTE: placeholder name
	bool contains_40b750(const Point &p);	// NOTE: placeholder name

	Point min;
	Point max;
};
void OpX4e_placePoint_9d5460(vector<Point> &list, unsigned int index, Point p);	// NOTE: placeholder name

class Cell	// NOTE: partial
{
public:
	HEntity getEntity();	// 0x45d250
};

template <class T>
class Array2D	// NOTE: partial
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
};
extern Array2D<Cell *> opX4e_cells;	// NOTE: placeholder name (0xcfd44c)

struct OpX4e_Scroll : public Pos	// NOTE: placeholder name (0xd1d9dc)
{
	char pad08[0x0a - 0x08];
	bool unknown0a;	// NOTE: placeholder name
};
extern OpX4e_Scroll opX4e_scroll;	// NOTE: placeholder name (0xd1d9dc)

extern Rect opX4e_screenRect;	// NOTE: placeholder name (0xcf27ec)
class OpX4e_GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
};
extern OpX4e_GameData opX4e_gameData;	// NOTE: placeholder name (0xd1e860)

struct OpX4e_Location	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
};

class OpX4e_HLocation	// NOTE: placeholder name
{
public:
	int ID;
	OpX4e_Location *operator->() const;	// 0x9b7910
};
extern OpX4e_HLocation opX4e_location;	// NOTE: placeholder name (0xd1e888)
extern bool opX4e_d28fa0;	// NOTE: placeholder name
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
extern float opX4e_bba1dc;	// NOTE: placeholder name (0.85f)
extern float opX4e_bba054;	// NOTE: placeholder name (0.5f)
extern float opX4e_cf46f8;	// NOTE: placeholder name
extern int opX4e_cf4b98;	// NOTE: placeholder name
extern int opX4e_cebd5c;	// NOTE: placeholder name
extern int opX4e_cefab4;	// NOTE: placeholder name
extern int opX4e_cefab8;
extern Pos opX4e_cfbec0;	// NOTE: placeholder name
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)

class OpX4e_AnimItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpX4e_Engine	// NOTE: placeholder name (0xcefc64)
{
public:
	void unknown454d90(int anim);	// NOTE: placeholder name
	OpX4e_AnimItem *unknown50fb50(OpX4e_Engine *engine, int type, Pos *a, Pos *b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
};
extern OpX4e_Engine *opX4e_engine;	// NOTE: placeholder name (0xcefc64)

class Particle
{
public:
	Pos *getPos();	// 0x462e10
};
	// NOTE: placeholder name
void OpB_updateFontScale_446320();	// NOTE: placeholder name

class CAllies	// NOTE: partial
{
public:
	void endOrder();
};
extern CAllies *opX4e_allies;	// NOTE: placeholder name (0xcec0c8)

class SoundMgr	// NOTE: partial
{
public:
	void unknown454540();	// NOTE: placeholder name
};
extern SoundMgr opX4e_soundMgr;	// NOTE: placeholder name (0xd2d2a0)

int opX4e_maxInt(int a, int b) throw();	// NOTE: placeholder name (0x9cdb60)
extern bool opX4e_cefacd;	// NOTE: placeholder name
extern bool opX4e_d28c8a;	// NOTE: placeholder name
extern bool opX4e_d28d15;	// NOTE: placeholder name
extern int opX4e_screenWidth;	// NOTE: placeholder name (0xcf27f4)
extern int opX4e_screenHeight;	// NOTE: placeholder name (0xcf27f8)

class CMap : public Console	// NOTE: partial layout
{
public:
	bool unknown8062d0();	// NOTE: placeholder name
	CMap(XConsole *parent);	// 0x7f57e0
	virtual ~CMap();
	bool operate49aa00();	// NOTE: placeholder name
	int getField49aae0();	// NOTE: placeholder name
	void unknown827950();	// NOTE: placeholder name
	void unknown7f5fd0(int value);	// NOTE: placeholder name
	void centerPush_805020(Pos *out);	// NOTE: placeholder name
	void unknown8051f0(Pos *min, Pos *max);	// NOTE: placeholder name
	bool unknown806d00(vector<Point> &points, bool flag);	// NOTE: placeholder name
	bool unknown805de0(HEntity entity, bool flag);	// NOTE: placeholder name
	int unknown806420(HEntity entity, HItem *outItem, int *outSlot);	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);
	void unknown8069e0(Point p, bool flag);	// NOTE: placeholder name

	Pos scroll;	// NOTE: placeholder name
	HEntity unknown74;	// NOTE: placeholder name
	char pad78[0x5f0 - 0x78];
	unsigned int unknown5f0;	// NOTE: placeholder name
	unsigned int unknown5f4;	// NOTE: placeholder name
	Point unknown5f8;	// NOTE: placeholder name
	vector<HEntity> unknown600;	// NOTE: placeholder name
	unsigned int unknown610;	// NOTE: placeholder name
	unsigned int unknown614;	// NOTE: placeholder name
	char pad618[0x7f4 - 0x618];
	HEntity unknown7f4;	// NOTE: placeholder name
	char pad7f8[0x8c4 - 0x7f8];
};

extern CMap *opX4e_mapView;	// NOTE: placeholder name (0xcec054)

//==================================================================
// functions
//==================================================================

struct OpX4e_PropData	// NOTE: placeholder name
{
	char pad00[0x20];
	string name;	// NOTE: placeholder name
};
extern vector<OpX4e_PropData *> opX4e_propTypes;	// NOTE: placeholder name (0xcf35b0)
string OpR5f_toUpper_4083a0(const string &text);	// NOTE: placeholder name

unsigned int opX4e_getPropNameUpper_7ffe10(HProp prop, unsigned int type, string &out)	// NOTE: placeholder name
{
	out = OpR5f_toUpper_4083a0(prop.isValid() ? prop->getName() : opX4e_propTypes[type]->name);
	return out.size();
}

bool CMap::unknown8062d0()
{
	if (opX4e_world->unknown66c->unknown5d2380(0x1f).isValid())
	{
		if (tickCount < unknown610 + 500)
			return true;
		else
		{
			if (tickCount > unknown614 + 5000)
			{
				unknown614 = tickCount;
				unknown610 = tickCount;
				opR1d_4541b0(0x3c,0,0);
				opX4e_interfaceMsg->add(new OpX4e_InterfaceMessage(0xab,0,0,0,HEntity(),HProp()));
				return true;
			}
		}
	}
	return false;
}

//==================================================================
// CDragDrop
//==================================================================

struct OpX4e_ItemType	// NOTE: placeholder name
{
	char pad00[0x1ac];
	bool unknown1ac;	// NOTE: placeholder name
};

class OpX4e_Inventory	// NOTE: placeholder name (CInventory, 0xcec08c)
{
public:
	void unknown8a53c0();	// NOTE: placeholder name
};
extern OpX4e_Inventory *opX4e_inventory;	// NOTE: placeholder name (0xcec08c)
extern int opX4e_cefc90;	// NOTE: placeholder name

struct OpX4e_ItemRef	// NOTE: placeholder name (HItem layout without a constructor)
{
	int ID;
	Item *operator->() const;	// 0x9b65b0
};

class CDragDrop : public Console
{
public:
	CDragDrop(const Pos &pos, HItem item);	// 0x7f37f0
	virtual ~CDragDrop();
	virtual void update();
	virtual void close();

	OpX4e_ItemRef unknown6c;	// NOTE: placeholder name (plain copy of an HItem)
	bool unknown70;	// NOTE: placeholder name
	unsigned int unknown74;	// NOTE: placeholder name
};
extern XConsole *opX4e_cec034;	// NOTE: placeholder name
extern CDragDrop *opX4e_dragDrop;	// NOTE: placeholder name (0xcec12c)

CDragDrop::CDragDrop(const Pos &pos, HItem item)
	: Console(opX4e_cec034,item->unknown571db0(false,false).size() + 6,1,pos.x,pos.y,0,false,10)
{
	unknown6c.ID = item.ID;
	unknown70 = false;
	unknown74 = tickCount;
	string text = " [ " + unknown6c->unknown571db0(false,false) + " ] ";
	print(0,0,text);
	animate(unknown6c->unknown44aec0() <= 3 && (unknown6c->unknown9b4350()->unknown1ac || unknown6c->getEffect(0x6e)) ? "A_CDragDrop_Destroy" : "A_CDragDrop_Normal");
	opX4e_dragDrop = this;
	if (unknown6c->unknown44aec0() <= 3 && opX4e_cefc90 == 1)
	{
		opX4e_inventory->unknown8a53c0();
		unknown70 = true;
	}
}

class OpX4e_Mouse	// NOTE: placeholder name (XMouse, 0xcefa94)
{
public:
	Pos getPos_40a970();	// NOTE: placeholder name
};
extern OpX4e_Mouse *opX4e_mouse;	// NOTE: placeholder name (0xcefa94)

class OpX4e_Holder	// NOTE: placeholder name (0xcec0d4)
{
public:
	Console *getConsole_4ab670() throw();	// NOTE: placeholder name
};
extern OpX4e_Holder *opX4e_holder;	// NOTE: placeholder name (0xcec0d4)

class OpX4e_Graph	// NOTE: placeholder name (0xcefa8c)
{
public:
	void pushFrame();
	void setMarked(unsigned int index, bool marked);
	void clearMarked(bool skipFirst);
};
extern OpX4e_Graph *opX4e_keys;	// NOTE: placeholder name (0xcefa8c)

void opX4e_createDragDrop_7f4560(HItem item)	// NOTE: placeholder name
{
	if (opX4e_cefc90 == 1)
		opX4e_holder->getConsole_4ab670()->animate("A_Inv_AttentionGlow");
	Pos pos = opX4e_mouse->getPos_40a970();
	opX4e_dragDrop = new CDragDrop(Pos(pos.x - 3 - item->unknown571db0(false,false).size() / 2,pos.y),item);
	if (opX4e_mapView->operate49aa00())
		opX4e_mapView->unknown827950();
	opX4e_keys->pushFrame();
	opX4e_keys->clearMarked(true);
	opX4e_keys->setMarked(0x15,true);
}

void CMap::unknown8069e0(Point p, bool flag)
{
	if (opX4e_cefacd && unknown7f4.isValid())
	{
		if (!unknown7f4.operator->())
			unknown7f4.reset();
		else if (unknown7f4->getPosition() != p)
			return;
	}
	scroll.set(p.x < opX4e_screenWidth / 2 ? opX4e_screenWidth / 2 - p.x : -opX4e_maxInt(p.x - opX4e_screenWidth / 2,0),p.y < opX4e_screenHeight / 2 ? opX4e_screenHeight / 2 - p.y : -opX4e_maxInt(p.y - opX4e_screenHeight / 2,0));
	if (!flag && (!opX4e_d28c8a || opX4e_d28d15) && opX4e_scroll.differs_409cf0(0,0) && opX4e_cells(p)->getEntity().isValid() && opX4e_cells(p)->getEntity()->isPlayer())
	{
		scroll += opX4e_scroll;
		if (scroll.x > opX4e_screenWidth / 2)
		{
			int shift = scroll.x - opX4e_screenWidth / 2;
			opX4e_scroll.x -= shift;
			scroll.x -= shift;
		}
		else if (scroll.x + opX4e_cells.getWidth() - 1 < opX4e_screenWidth / 2)
		{
			int shift2 = opX4e_screenWidth / 2 - (scroll.x + opX4e_cells.getWidth() - 1);
			opX4e_scroll.x += shift2;
			scroll.x += shift2;
		}
		if (scroll.y > opX4e_screenHeight / 2)
		{
			int shift3 = scroll.y - opX4e_screenHeight / 2;
			opX4e_scroll.y -= shift3;
			scroll.y -= shift3;
		}
		else if (scroll.y + opX4e_cells.getHeight() - 1 < opX4e_screenHeight / 2)
		{
			int shift4 = opX4e_screenHeight / 2 - (scroll.y + opX4e_cells.getHeight() - 1);
			opX4e_scroll.y += shift4;
			scroll.y += shift4;
		}
	}
}

void opX4e_toggleMapFont_7f46e0()	// NOTE: placeholder name
{
	opX4e_d28d15 = !opX4e_d28d15;
	bool active = opX4e_mapView->operate49aa00();
	int status = opX4e_mapView->getField49aae0();
	if (active)
	{
		if (status == 2)
			opX4e_allies->endOrder();
		opX4e_mapView->unknown827950();
	}
	Point p;
	opX4e_mapView->centerPush_805020(&p);
	OpB_updateFontScale_446320();
	opX4e_screenRect.set(0,opX4e_cebd5c == 2 ? 1 : 10,opX4e_cefab4,opX4e_cefab8);
	int id = opX4e_cec034->getSubconsoleIndex(opX4e_mapView);
	opX4e_cec034->removeSubconsole(opX4e_mapView);
	opX4e_mapView = new CMap(opX4e_cec034);
	opX4e_cec034->moveSubconsole(opX4e_mapView,id);
	opX4e_mapView->unknown7f5fd0(1);
	if (opX4e_scroll.differs_409cf0(0,0))
	{
		if (opX4e_d28d15)
		{
			opX4e_scroll /= 2;
			if (opX4e_scroll.equals_409cb0(0,0))
				opX4e_scroll.unknown0a = false;
		}
		else
			opX4e_scroll *= 2;
	}
	opX4e_mapView->unknown8069e0(p,true);
	opX4e_soundMgr.unknown454540();
}

void CMap::trigger(const string &command, int value)
{
	if (command == "jam_check")
	{
		Point pos = *((Particle *)value)->getPos();
		Point diff = pos - this->scroll;
		if (opX4e_cells.contains(diff))
		{
			if (!opX4e_world->isVisible(diff))
				opX4e_engine->unknown454d90(value);
			else if (opX4e_cells(diff)->getEntity().isValid() && opX4e_cells(diff)->getEntity()->getAI() && opX4e_cells(diff)->getEntity()->getAI()->unknown581140())
			{
				int anim;
				if (OpU8a_lookup1("CMap_A_Jam_Nonally",&anim))
				{
					opX4e_engine->unknown454d90(value);
					opX4e_engine->unknown50fb50(opX4e_engine,anim,&pos,&opX4e_cfbec0,NULL,NULL,9)->unknown50de10();
				}
			}
		}
		else
			opX4e_engine->unknown454d90(value);
	}
}

bool CMap::unknown806d00(vector<Point> &points, bool flag)
{
	if (flag)
	{
		OpX4e_placePoint_9d5460(points,0,unknown74.operator->() ? unknown74->getPosition() : opX4e_world->getPlayer()->getPosition());
	}
	Area bounds;
	unknown8051f0(&bounds.min,&bounds.max);
	Point initial = bounds.min;
	for (int idx = 0; idx < points.size(); idx++)
	{
		Area trial = bounds;
		if (trial.fitAround_40bcb0(points[idx],1))
		{
			for (int x = 0; x < idx; x++)
			{
				if (!trial.contains_40b750(points[x]))
					goto next;
			}
			bounds = trial;
		}
next:;
	}
	if (initial == bounds.min)
		return false;
	scroll += initial - bounds.min;
	return true;
}

int CMap::unknown806420(HEntity entity, HItem *outItem, int *outSlot)
{
	if (opX4e_world->getTurn() < (entity->getAI() ? entity->getAI()->unknown45ad90() : opX4e_cf4b98) + 12)
		return 0;
	if (!opX4e_world->unknown66c->isHostileTo(entity) || (opX4e_cf46f8 < 100.0 && entity->getGroup()->unknown9b4350() == 3 && !entity->getAI()->unknown458fb0(opX4e_world->unknown66c)))
	{
		if (entity->unknown490840() < (int)(entity->unknown5ca260() * opX4e_bba1dc))
			return 1;
		int slot = opX4e_world->unknown66c->unknown5cc460(3,entity->unknown5cc190(3)).isValid() ? 3 :
			opX4e_world->unknown66c->unknown5cc460(0,entity->unknown5cc190(0)).isValid() ? 0 :
			opX4e_world->unknown66c->unknown5cc460(1,entity->unknown5cc190(1)).isValid() ? 1 :
			opX4e_world->unknown66c->unknown5cc460(2,entity->unknown5cc190(2)).isValid() ? 2 : 4;
		if (slot != 4)
		{
			if (outSlot)
				*outSlot = slot;
			return 3;
		}
		HItem swap;
		vector<HItem> *items = entity->getInventoryList();
		for (unsigned int i = 0; i < items->size(); i++)
		{
			if ((*items)[i]->unknown44aec0() <= 3 && (*items)[i]->getAmount_9b6bf0() < (int)((*items)[i]->unknown457c80() * opX4e_bba054))
			{
				if (swap.isNull() || (*items)[i]->getAmount_9b6bf0() < swap->getAmount_9b6bf0())
				{
					if ((*items)[i]->unknown5773d0(true,false))
						swap = (*items)[i];
				}
			}
		}
		if (swap.isValid())
		{
			if (outItem)
				*outItem = swap;
			return 4;
		}
	}
	return 0;
}

bool CMap::unknown805de0(HEntity entity, bool flag)
{
	if (!flag)
	{
		if (entity->unknown5d7670())
			return false;
	}
	if ((opX4e_d28fa0 || !stringToInt(opX4e_gameData.getEntryText("resScannedCogmind_g")) || (opX4e_location->type == 0x20 && !stringToInt(opX4e_gameData.getEntryText("secScannedCogmind_g")))) && opX4e_world->unknown463890(4)->unknown45e3c0())
	{
		vector<HEntity> *list = opX4e_world->unknown463890(4)->getMembers();
		vector<HEntity> found;
		for (unsigned int i = 0; i < list->size(); i++)
		{
			if ((*list)[i]->getFaction() == 0x14 && opX4e_world->unknown4631f0((*list)[i]) && OpQ1_distanceCeil_40a3f0((*list)[i]->getPosition(),entity->getPosition()) <= (*list)[i]->unknown5c7d30() - entity->unknown5d2150(0x1e,0) && !(*list)[i]->unknown5d5250() && !(*list)[i]->getTarget() && opX4e_world->unknown465200((*list)[i]->getPosition(),entity->getPosition()))
				found.push_back((*list)[i]);
		}
		if (!found.empty())
		{
			if (tickCount < unknown5f0 + 500)
				return true;
			else
			{
				if (tickCount > unknown5f4 + 3000 || unknown5f8 != entity->getPosition())
				{
					unknown5f4 = tickCount;
					unknown5f0 = tickCount;
					unknown5f8.set_40a030(entity->getPosition());
					unknown600 = found;
					opR1d_4541b0(0x3c,0,0);
					opX4e_interfaceMsg->add(new OpX4e_InterfaceMessage(0xac,0,0,0,HEntity(),HProp()));
					return true;
				}
			}
		}
	}
	return false;
}
