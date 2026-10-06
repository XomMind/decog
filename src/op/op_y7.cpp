// op_y7: consoles in 0x8a0000-0x9b0000 (CParts, CInfo, CMachine, CShell, CHack, CRobot, CTitle, ...), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//==================================================================
// shared declarations
//==================================================================

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
	Pos(int v);	// 0x409990
	Pos(const Pos &pos);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	static XColor lerp(XColor a, XColor b, float t);
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// 0x40a6e0
	Rect(int x_, int y_, int width_, int height_);	// 0x456940
	Rect(const Rect &rect);	// 0x40a720
};

class OpY7_Item	// NOTE: placeholder name
{
public:
	int unknownGetter();	// NOTE: placeholder name (folded getter, 0x...)
	int getNestedField();	// NOTE: placeholder name (0x457820, item type)
	int unknown9b6bf0();	// NOTE: placeholder name (folded getter)
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	struct OpY7_ItemData *getData();	// NOTE: placeholder name (folded getter 0x9b4350)
	int getEffect(int type);	// 0x457b70
};

struct OpY7_ItemData	// NOTE: placeholder name
{
	char pad00[0x1ac];
	bool unknown1ac;	// NOTE: placeholder name
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp();	// 0x9b6590
	bool isValid() const;
	OpY7_Item *operator->() const;	// 0x9b65b0
};

class OpY7_Entity;

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
	bool isValid() const;
	bool operator==(HEntity other) const;
	OpY7_Entity *operator->() const;	// 0x9b6570
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	HItem();	// 0x9b6590
	bool isValid() const;
	OpY7_Item *operator->() const;	// 0x9b65b0
};

class OpY7_Entity	// NOTE: placeholder name (Entity)
{
public:
	int unknown5db3c0(HProp item, bool flag, int a);	// NOTE: placeholder name
	int unknown642940(HProp item, int a, int b, int c, int d);	// NOTE: placeholder name
	Pos &getPosition();	// 0x45a4a0
};

class OpY7_Cell	// NOTE: placeholder name (Cell)
{
public:
	HItem getItem();	// 0x45d8f0
};

class OpY7_Cells	// NOTE: placeholder name (0xcfd44c)
{
public:
	OpY7_Cell *&operator()(const Pos &p);	// 0x9ced70
};
extern OpY7_Cells opy7_cells;	// NOTE: placeholder name

bool opy7_unknown5111e0(int id, const string &text, int a, int b, HEntity entity, HProp other, int c, int d);	// NOTE: placeholder name
void opy7_message7b1750(int type, const string &text, int a, int b, HEntity entity, HProp prop, int c);	// NOTE: placeholder name

class OpY7_Unk8758d0	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpY7_Unk8758d0 *opy7_cec058;	// NOTE: placeholder name

class OpY7_LogMsgs	// NOTE: placeholder name (CLogMsgs at 0xcec0b4)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpY7_LogMsgs *opy7_logMsgs;	// NOTE: placeholder name

struct XEvent;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	virtual void refresh();
	virtual bool input(void *event);
	virtual void inputAscii(int key, int modifier);	// NOTE: placeholder name
	virtual void update();
	virtual void render();

	bool isHidden();
	int getHeight();
	Pos getPos();
	void setChar_417f50(int x, int y, int ch);
	void putChar_418150(int x, int y, int ch, XColor fore, XColor back, bool flag);
	void removeSubconsole(XConsole *console);
	void getRect4286b0(Rect &rect);	// NOTE: placeholder name
	void render429ea0();	// NOTE: placeholder name (XConsole::render body)
	bool input429d00(XEvent *event);	// NOTE: placeholder name (XConsole::input body)
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)
	void setBackAll_418410(XColor color);
	void setBack_417fc0(int x, int y, XColor color, bool flag);
	float getScaleX();
	void unknown417b60(float value);	// NOTE: placeholder name (scale x)
	void unknown417b80(float value);	// NOTE: placeholder name (scale y)
	void setHidden(bool hidden);
	void setFore(XColor color);
	void setCharRow(int x, int y, int width, int ch);
	void print(int x, int y, const string &text);
	int countVisible();
	int getWidth();	// 0x44b0d0
	void resetBack_418450();	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class OpY7_Engine	// NOTE: placeholder name (Engine)
{
public:
	void render();	// NOTE: placeholder name (0x5100b0)
	bool update();	// NOTE: placeholder name (0x50fff0)
	void killGroup(string group);
	void stopAll();	// NOTE: placeholder name (0x50ff30)
};

class ConsoleTitle;

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)
	void animate(string name);
	void unknown48c3c0(int value);	// NOTE: placeholder name
	bool isActive_7ad420();	// NOTE: placeholder name

	int unknown60;
	OpY7_Engine *engine;
	void *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);
	char pad6c[0x8c - 0x6c];
};

class CTactical : public Console
{
public:
	CTactical(XConsole *parent, int type_);	// 0x4a9880

	int type;	// NOTE: placeholder name
};

class Unknown_8a1600 : public Console	// NOTE: placeholder name
{
public:
	Unknown_8a1600(XConsole *parent);
	bool unknown8a15a0(void *event);	// NOTE: placeholder name

	vector<class XBuffer*> children;	// NOTE: placeholder name
};

struct XEvent	// NOTE: placeholder name
{
	XEvent(int type_);	// 0x415c60

	int type;
	Pos mouse;
};

class OpY7_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	bool isIn(const Rect &rect);	// NOTE: placeholder name (0x41a730)
	bool isOver(XConsole *console);	// NOTE: placeholder name (0x41a760)
};
extern OpY7_Mouse *opy7_mouse;	// NOTE: placeholder name

class OpY7_Keys	// NOTE: placeholder name (0xd338cc)
{
public:
	bool isDown(int key);	// NOTE: placeholder name (0x439510)
};
extern OpY7_Keys opy7_keys;	// NOTE: placeholder name

class OpY7_Audio	// NOTE: placeholder name (0xcefaa8)
{
public:
	void play(int sound, int a, const string &name, int c, int d);	// NOTE: placeholder name (0x793450)
};
extern OpY7_Audio *opy7_audio;	// NOTE: placeholder name

struct OpY7_Link	// NOTE: placeholder name
{
	HProp a;	// NOTE: placeholder name
	HProp b;	// NOTE: placeholder name
	bool isActive();	// NOTE: placeholder name (0x46d440)
};
extern vector<OpY7_Link*> opy7_links;	// NOTE: placeholder name (0xcf4760)
template <class T> void OpY7_eraseAtIndex(vector<T> *v, unsigned int *i);	// NOTE: placeholder name (0x9de640, steps i back)

extern unsigned int opy7_tickCount;	// NOTE: placeholder name (0xcaed20)
extern XColor *opy7_COLOR_BLACK;	// NOTE: placeholder name (0xcfe674)
extern XColor *opy7_d2175c;	// NOTE: placeholder name
extern XColor *opy7_d20438;	// NOTE: placeholder name
extern bool opy7_d28d16;	// NOTE: placeholder name (option)
extern bool opy7_d28d09;	// NOTE: placeholder name (option)
extern vector<int> opy7_d22590;	// NOTE: placeholder name

class OpY7_World	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	bool unknown71bbd0();	// NOTE: placeholder name
	HEntity getPlayer();	// 0x4630f0
	void unknown774390(int type, int value);	// NOTE: placeholder name
};
extern OpY7_World *opy7_world;	// NOTE: placeholder name

class OpY7_Info : public Console	// NOTE: placeholder name (CInfo at 0xcec11c)
{
public:
	void unknown8b4500(HEntity entity, HProp a, HProp b, const Pos &c, int d, int e);	// NOTE: placeholder name
};
extern OpY7_Info *opy7_info;
extern class OpY7_Parts *opy7_parts;	// NOTE: placeholder name (0xcec088)
	// NOTE: placeholder name (0xcec11c)

extern XConsole *opy7_cec0f8;	// NOTE: placeholder name
extern bool opy7_cefca8;	// NOTE: placeholder name
extern bool opy7_d28fbc;	// NOTE: placeholder name
extern bool opy7_cec14e;	// NOTE: placeholder name
extern bool opy7_cec14d;	// NOTE: placeholder name (ctrl held)
extern int opy7_cec12c;	// NOTE: placeholder name

string intToString(int value);

class OpY7_Root : public XConsole	// NOTE: placeholder name (0xcec034)
{
public:
	int unknown48c5e0();	// NOTE: placeholder name (particle count)
};
extern OpY7_Root *opy7_cec034;	// NOTE: placeholder name

//==================================================================
// CParts
//==================================================================

struct OpY7_Part : public Console	// NOTE: placeholder name (CPart)
{
	HProp item;	// NOTE: placeholder name
};

class OpY7_Parts : public Console	// NOTE: placeholder name (CParts at 0xcec088)
{
public:
	void render8a1060();	// NOTE: placeholder name (CParts vtable slot 7)
	OpY7_Part *unknown894e70(HProp item);	// NOTE: placeholder name
	void inputAscii8a0e50(int key, int modifier);	// NOTE: placeholder name (CParts vtable slot 5)
	int unknown8a0d70(int key);	// NOTE: placeholder name
	int unknown8a0df0(int key);	// NOTE: placeholder name
	bool unknown894f70();	// NOTE: placeholder name
	int unknown89cda0(OpY7_Part *part);	// NOTE: placeholder name
	int unknown898910(OpY7_Part *part, HProp item, int value);	// NOTE: placeholder name
	void unknown8993e0(OpY7_Part *part, int a);	// NOTE: placeholder name
	void unknown89adf0(OpY7_Part *part);	// NOTE: placeholder name

	char pad6c[0x74 - 0x6c];
	vector<OpY7_Part*> parts;	// NOTE: placeholder name
	char pad84[0xb8 - 0x84];
	unsigned int unknownB8;	// NOTE: placeholder name
	char padBC[0xd0 - 0xbc];
	unsigned int unknownD0;	// NOTE: placeholder name
	vector<Rect> unknownD4;	// NOTE: placeholder name
	unsigned int unknownE4;	// NOTE: placeholder name
	vector<XConsole*> unknownE8;	// NOTE: placeholder name
};

void OpY7_Parts::inputAscii8a0e50(int key, int modifier)
{
	if (opy7_world->unknown71bbd0())
		return;
	if (!opy7_cec0f8->isHidden())
		return;
	switch (modifier)
	{
		case 0:
			if (!opy7_cefca8 && opy7_d28fbc)
				return;
			if (opy7_cec14e)
			{
				int index = unknown8a0d70(key);
				if (index != -1)
				{
					if (unknown894f70())
					{
						int result = unknown89cda0(parts[index]);
						if (result == 0)
							unknownB8 = 0;
					}
					else
						unknown898910(parts[index],HProp(),0);
				}
			}
			else if (opy7_cec14d)
			{
				int index = unknown8a0d70(key);
				if (index != -1)
					unknown8993e0(parts[index],0);
			}
			break;
		case 1:
			if (!opy7_cefca8 && opy7_d28fbc)
				return;
			if (opy7_cec14e)
				return;
			if (opy7_cec14d)
			{
				int index = unknown8a0df0(key + 0x20);
				if (index != -1)
					unknown89adf0(parts[index]);
			}
			else if (opy7_cec12c == 0)
			{
				int index = unknown8a0d70(key + 0x20);
				if (index != -1)
					opy7_info->unknown8b4500(HEntity(),parts[index]->item,HProp(),Pos(-1),0,0);
			}
			break;
	}
}

void OpY7_Parts::render8a1060()
{
	if (isHidden())
		return;
	engine->render();
	if (isActive_7ad420() && opy7_tickCount > unknownD0 + 1000)
	{
		for (int y = 2; y < getHeight() - 1; y++)
		{
			setChar_417f50(0,y,0x80);
			putChar_418150(1,y,' ',*opy7_COLOR_BLACK,*opy7_COLOR_BLACK,true);
			unknownD4.clear();
		}
		if (opy7_d28d16)
		{
			Rect rect;
			getRect4286b0(rect);
			for (unsigned int i = 0; i < opy7_links.size(); i++)
			{
				if (!opy7_links[i]->isActive())
					OpY7_eraseAtIndex(&opy7_links,&i);
				else
				{
					HProp item = opy7_links[i]->a->unknownGetter() <= 3 ? opy7_links[i]->a : opy7_links[i]->b;
					OpY7_Part *part = opy7_parts->unknown894e70(item);
					if (part != NULL)
					{
						int y = part->getPos().y;
						setChar_417f50(0,y,0x85);
						putChar_418150(1,y,0x81,*opy7_d2175c,*opy7_COLOR_BLACK,true);
						unknownD4.push_back(Rect(rect.x,rect.y + y,2,1));
						if (opy7_mouse->isIn(unknownD4.back()))
						{
							if (unknownE4 == 0)
								unknownE4 = opy7_tickCount;
							putChar_418150(1,y,'>',*opy7_COLOR_BLACK,*opy7_d20438,true);
						}
						if (opy7_d28d09 && opy7_d22590[0x1a] == 0)
							opy7_audio->play(0x1a,1,item->getName(0,0),0,0);
					}
				}
			}
		}
	}
	if (unknownE4 != 0 && opy7_tickCount >= unknownE4 + 500 && unknownE8.empty())
		input(&XEvent(0x110));
	else if (!unknownE8.empty() && !opy7_keys.isDown(0x61))
	{
		for (unsigned int i = 0; i < unknownD4.size(); i++)
		{
			if (opy7_mouse->isIn(unknownD4[i]))
				goto done;
		}
		for (unsigned int j = 0; j < unknownE8.size(); j++)
		{
			if (unknownE8[j] != NULL)
				removeSubconsole(unknownE8[j]);
		}
		unknownE8.clear();
		unknownE4 = 0;
	}
done:
	render429ea0();
}

//==================================================================
// CInventoryItem
//==================================================================

extern Rect opy7_d33be0;	// NOTE: placeholder name (inventory rect)
extern bool opy7_cefc89;	// NOTE: placeholder name

extern bool opy7_cefa74;	// NOTE: placeholder name
extern XColor *opy7_d39294;	// NOTE: placeholder name
extern XColor *opy7_d25f60;	// NOTE: placeholder name
void opy7_unknown7f4560(HProp item);	// NOTE: placeholder name
float opy7_fade4372b0(float from, float to, unsigned int start, int duration);	// NOTE: placeholder name
template <class T> void opy7_removeAt9da940(vector<T> &v, int index);	// NOTE: placeholder name
void opy7_eraseAt9ce6d0(vector<unsigned int> &v, unsigned int &i);	// NOTE: placeholder name

struct OpY7_Record : public Console	// NOTE: placeholder name (CInventoryItem)
{
	void drawName();	// NOTE: placeholder name (CInventoryItem::drawName)
	void drawState();	// NOTE: placeholder name (CInventoryItem::drawState)

	HEntity item;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	XConsole *unknown74;	// NOTE: placeholder name
};

class OpY7_Inventory : public Console	// NOTE: placeholder name (CInventory at 0xcec08c)
{
public:
	void update8a1be0();	// NOTE: placeholder name (CInventory vtable slot 6)
	OpY7_Record *unknown8a1fd0(HProp item, bool flag);	// NOTE: placeholder name
	OpY7_Inventory(XConsole *parent);	// 0x8a1930
	void attemptEquip(HProp item, int a, int slot, int b);	// NOTE: placeholder signature (0x8a3f20)
	void unknown4aa790();	// NOTE: placeholder name
	void reopen(int mode, HProp item);	// NOTE: placeholder signature (0x8a2ce0)
	int unknown8a4ec0(HProp item, bool flag);	// NOTE: placeholder name
	bool unknown8a54c0(HEntity item, bool flag);	// NOTE: placeholder name
	void render8a6e10();	// NOTE: placeholder name (CInventory vtable slot 7)
	void setTimed(HProp item);	// NOTE: placeholder name (0x4aa760)

	bool unknown6c;	// NOTE: placeholder name
	unsigned int unknown70;	// NOTE: placeholder name
	vector<OpY7_Record*> records;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
	OpY7_Record *unknown8c;	// NOTE: placeholder name
	OpY7_Record *unknown90;	// NOTE: placeholder name
	HProp unknown94;	// NOTE: placeholder name
	Unknown_8a1600 *unknown98;	// NOTE: placeholder name
	int unknown9c;	// NOTE: placeholder name
	vector<HProp> unknownA0;	// NOTE: placeholder name
	vector<unsigned int> unknownB0;	// NOTE: placeholder name
	int unknownC0;	// NOTE: placeholder name
	HProp unknownC4;	// NOTE: placeholder name
};

int OpY7_Inventory::unknown8a4ec0(HProp item, bool flag)
{
	HEntity player = opy7_world->getPlayer();
	int res = player->unknown5db3c0(item,flag,0);
	switch (res)
	{
		case 0:
			do
			{
				if (opy7_unknown5111e0(item->unknownGetter() <= 3 && (item->getData()->unknown1ac || item->getEffect(0x6e)) ? 0x10 : 0xf,item->getName(0,0),0,0,player,HProp(),0,0))
					opy7_cec058->unknown8758d0(true);
				opy7_logMsgs->scrollToEnd();
			}
			while (0);
			unknown94 = item;
			opy7_world->unknown774390(8,player->unknown642940(item,1,0,0,0));
			break;
		case 8:
			opy7_message7b1750(0x14,opy7_cells(player->getPosition())->getItem()->getName(0,0),0,0,player,HProp(),0);
			break;
		case 9:
			opy7_message7b1750(0x15,item->getName(0,0),0,0,player,HProp(),0);
			break;
		case 0xb:
			opy7_message7b1750(0x17,item->getName(0,0),0,0,player,HProp(),0);
			break;
		case 0xc:
			opy7_message7b1750(0x19,item->getName(0,0),0,0,player,HProp(),0);
			break;
		case 0xd:
			opy7_message7b1750(0x1a,item->getName(0,0),0,0,player,HProp(),0);
			break;
		case 0xe:
			opy7_message7b1750(0x1b,item->getName(0,0),0,0,player,HProp(),0);
			break;
	}
	return res;
}

bool OpY7_Inventory::unknown8a54c0(HEntity item, bool flag)
{
	vector<OpY7_Record*> rows;
	if (flag)
	{
		if (unknown8c != NULL && unknown8c->item == item)
			rows.push_back(unknown8c);
		if (unknown90 != NULL && unknown90->item == item)
			rows.push_back(unknown90);
	}
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->item == item && (flag || records[i]->unknown70 == 0))
			rows.push_back(records[i]);
	}
	for (unsigned int i = 0; i < rows.size(); i++)
	{
		rows[i]->drawName();
		rows[i]->drawState();
	}
	return !rows.empty();
}

extern bool opy7_cefacd;	// NOTE: placeholder name (debug display)
extern bool opy7_cefad6;	// NOTE: placeholder name (show particle count)
extern bool opy7_cefad7;	// NOTE: placeholder name (show console count)
extern XColor *opy7_d161d4;	// NOTE: placeholder name
extern XColor *opy7_d35bbc;	// NOTE: placeholder name

void OpY7_Inventory::render8a6e10()
{
	if (isHidden())
		return;
	engine->render();
	if (opy7_cefacd && (opy7_cefad6 || opy7_cefad7))
	{
		setFore(*opy7_d161d4);
		setCharRow(0x18,getHeight() - 1,0x1e,0x81);
		setFore(*opy7_d35bbc);
		if (opy7_cefad6)
		{
			int particles = opy7_cec034->unknown48c5e0();
			print(0x18,getHeight() - 1,string("Particles: ") + (particles == 0 ? string("None") : (particles < 1000 ? string("<1K") : intToString(particles / 1000) + "K")));
		}
		else
		{
			int consoles = opy7_cec034->countVisible();
			print(0x18,getHeight() - 1,string("Consoles: ") + intToString(consoles));
		}
	}
	render429ea0();
}

OpY7_Inventory::OpY7_Inventory(XConsole *parent)
	: Console(parent,opy7_d33be0,0,false,7),
	unknown84(0),
	unknown88(0),
	unknown8c(NULL),
	unknown90(NULL),
	unknown9c(0),
	unknownC0(0)
{
	setTitle(new ConsoleTitle(this,"/ I N V E N T O R Y /",0,4));
	unknown6c = false;
	new CTactical(this,7);
	unknown98 = new Unknown_8a1600(this);
	opy7_cefc89 = false;
}

void OpY7_Inventory::update8a1be0()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
			break;	// NOTE: stray break before the first case (dead jmp in the exe)
		case 1:
			if (!engine->update())
				unknown60 = 3;
			break;
		case 3:
			if (unknownC0 != 0)
			{
				OpY7_Record *record = unknown8a1fd0(unknownC4,false);
				if (record == NULL)
					unknown4aa790();
				else if (!opy7_mouse->isOver(record))
				{
					if (opy7_cefa74)
						opy7_unknown7f4560(unknownC4);
					unknown4aa790();
				}
				else if (opy7_tickCount >= unknownC0)
				{
					opy7_unknown7f4560(unknownC4);
					unknown4aa790();
				}
			}
			if (!unknownA0.empty())
			{
				const int duration = 3000;
				OpY7_Record *item;
				for (unsigned int i = 0; i < unknownA0.size(); i++)
				{
					item = unknown8a1fd0(unknownA0[i],false);
					if (item == NULL || opy7_tickCount >= unknownB0[i] + duration)
					{
						if (item != NULL)
						{
							if (item->unknown74 != NULL)
								item->unknown74->setBackAll_418410(*opy7_d39294);
							else
								item->setBack_417fc0(3,0,*opy7_d39294,true);
						}
						opy7_removeAt9da940(unknownA0,i);
						opy7_eraseAt9ce6d0(unknownB0,i);
					}
					else
					{
						XColor color = XColor::lerp(*opy7_d39294,*opy7_d25f60,opy7_fade4372b0(0.75f,0.0f,unknownB0[i],duration));
						if (item->unknown74 != NULL)
							item->unknown74->setBackAll_418410(color);
						else
							item->setBack_417fc0(3,0,color,true);
					}
				}
			}
			engine->update();
			break;
		case 4:
			engine->update();
			if (getScaleX() != 0.0f)
			{
				if (opy7_tickCount - unknown70 >= 500)
				{
					unknown417b60(0.0f);
					unknown417b80(0.0f);
				}
				else
				{
					unknown417b60(1.0 - (opy7_tickCount - unknown70) / 500.0);
					unknown417b80(1.0 - (opy7_tickCount - unknown70) / 500.0);
					break;
				}
			}
			engine->stopAll();
			unknown60 = 0;
			setHidden(true);
			break;
	}
	updateBase429e30();
}
extern OpY7_Inventory *opy7_inventory;	// NOTE: placeholder name (0xcec08c)

class OpY7_Partswap : public Console	// NOTE: placeholder name (CPartswap at 0xcec090)
{
public:
	void open(int a, XConsole *source, HProp item, bool flag);	// NOTE: placeholder signature (0x8a7b00)
};
extern OpY7_Partswap *opy7_partswap;	// NOTE: placeholder name (0xcec090)

extern unsigned int opy7_cefc80;	// NOTE: placeholder name
extern unsigned int opy7_cefc84;	// NOTE: placeholder name

class OpY7_InventoryItem : public Console	// NOTE: placeholder name (CInventoryItem)
{
public:
	bool input8a1770(XEvent *event);	// NOTE: placeholder name (CInventoryItem vtable slot 4)

	HProp item;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
};

bool OpY7_InventoryItem::input8a1770(XEvent *event)
{
	if (opy7_world->unknown71bbd0())
		return false;
	if (opy7_tickCount < opy7_cefc84)
		return false;
	switch (event->type)
	{
		case 0x127:
			switch (type)
			{
				case 0:
				case 1:
					opy7_inventory->attemptEquip(item,0,0x20,0);
					opy7_inventory->unknown4aa790();
					break;
				case 2:
					opy7_inventory->reopen(2,HProp());
					break;
				case 3:
					opy7_inventory->reopen(3,HProp());
					break;
			}
			return true;
		case 0x128:
			if (type < 2)
				opy7_info->unknown8b4500(HEntity(),item,HProp(),Pos(-1),0,0);
			return true;
		case 0x129:
			if (type < 2)
				opy7_inventory->unknown8a4ec0(item,1);
			return true;
		case 0x12a:
			if (type < 2 && opy7_tickCount >= opy7_cefc80)
				opy7_inventory->setTimed(item);
			return true;
		case 0x12b:
			opy7_partswap->open(0,this,HProp(),false);
			return true;
	}
	return false;
}

//==================================================================
// item sorting
//==================================================================

template <class T> void opy7_eraseRange9d9530(vector<T> &v, int first, int last);	// NOTE: placeholder name
template <class T> void opy7_insertAt9d8fc0(vector<T> &v, int index, T value);	// NOTE: placeholder name

void opy7_sortItems8a2a40(vector<HProp> &items)	// NOTE: placeholder name
{
	if (items.empty())
		return;
	unsigned int i = 0;
	while (i < items.size() - 1)
	{
		if (items[i]->getNestedField() == items[i + 1]->getNestedField())
		{
			vector<HProp> group;
			group.push_back(items[i]);
			for (unsigned int j = i + 1; j < items.size() && items[j]->getNestedField() == items[i]->getNestedField(); j++)
			{
				if (items[j]->unknown9b6bf0() <= group.back()->unknown9b6bf0())
					group.push_back(items[j]);
				else
				{
					for (unsigned int k = 0; k < group.size(); k++)
					{
						if (items[j]->unknown9b6bf0() > group[k]->unknown9b6bf0())
						{
							opy7_insertAt9d8fc0(group,k,items[j]);
							break;
						}
					}
				}
			}
			opy7_eraseRange9d9530(items,i,i + group.size() - 1);
			items.insert(items.begin() + i,group.begin(),group.end());
			i += group.size();
		}
		else
			i++;
	}
}

//==================================================================
// CSpecialCommand(s)
//==================================================================

extern bool opy7_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)
extern bool opy7_cefc73;	// NOTE: placeholder name

class OpY7_MapView : public XConsole	// NOTE: placeholder name (MapView at 0xcec054)
{
public:
	bool operate49aa00();	// NOTE: placeholder name
	int getField49aae0();	// NOTE: placeholder name
	bool test49aaa0();	// NOTE: placeholder name
	bool unknown49ac10();	// NOTE: placeholder name
	bool unknown49ab60();	// NOTE: placeholder name
	void unknown49ad30();	// NOTE: placeholder name
	void unknown827950();	// NOTE: placeholder name
	void unknown827cf0();	// NOTE: placeholder name
	void unknown8081d0();	// NOTE: placeholder name
};
extern OpY7_MapView *opy7_mapView;	// NOTE: placeholder name (0xcec054)

class OpY7_SidePanel : public XConsole	// NOTE: placeholder name (CInfo at 0xcec118/0xcec11c/0xcec120/0xcec124)
{
public:
	void unknown8b5080();	// NOTE: placeholder name
	HItem getUnknown98();	// NOTE: placeholder name (0x4aebc0)
	HEntity getUnknown9c();	// NOTE: placeholder name (0x4aebe0)
};
extern OpY7_SidePanel *opy7_cec118;	// NOTE: placeholder name
extern OpY7_SidePanel *opy7_cec11c;	// NOTE: placeholder name
extern OpY7_SidePanel *opy7_cec120;	// NOTE: placeholder name
extern OpY7_SidePanel *opy7_cec124;	// NOTE: placeholder name

class OpY7_List	// NOTE: placeholder name (CList at 0xcec130)
{
public:
	int getType();	// NOTE: placeholder name (folded getter 0x48e040)
};
extern OpY7_List *opy7_activeList;	// NOTE: placeholder name

class OpY7_Log : public XConsole	// NOTE: placeholder name (CLog at 0xcec0b0)
{
public:
	bool getField48e740();	// NOTE: placeholder name
	void unknown7b60e0();	// NOTE: placeholder name
};
extern OpY7_Log *opy7_log;	// NOTE: placeholder name

class OpY7_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void registerConsole(int command, Console *console, int unknown1, int unknown2);	// NOTE: placeholder name (0x416790)
	void unknown416640();	// NOTE: placeholder name
	struct OpY7_KeyEntry *getField416230();	// NOTE: placeholder name
};

struct OpY7_KeyEntry	// NOTE: placeholder name
{
	int getKey();	// NOTE: placeholder name (folded getter)
};
extern OpY7_KeyMap *opy7_keyMap;	// NOTE: placeholder name

void opy7_initCommandAnimations();	// NOTE: placeholder name (0x4ac7d0)
void opy7_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)
int opy7_centerOffset(int size, int total);	// NOTE: placeholder name (0x437190)
extern string opy7_commandDescriptions[];	// NOTE: placeholder name (0xd2b288)
extern string opy7_d387a0;	// NOTE: placeholder name
extern int opy7_ceca6c;	// NOTE: placeholder name
extern int opy7_commandKeys[];	// NOTE: placeholder name (0xbccaf0)

class OpY7_Search : public Console	// NOTE: placeholder name (CSearch at 0xcec0a4)
{
public:
	void open(int mode);	// NOTE: placeholder signature (0x8af730)
};
extern OpY7_Search *opy7_search;	// NOTE: placeholder name

class OpY7_ItemTag : public Console	// NOTE: placeholder name (CItemTag at 0xcec0a0)
{
public:
	void openForEntity(HItem item, int a);	// NOTE: placeholder signature (0x8aba90)
};
extern OpY7_ItemTag *opy7_itemTag;	// NOTE: placeholder name

class OpY7_TextInput	// NOTE: placeholder name (CTextInput)
{
public:
	void setUnknown95(bool value);	// NOTE: placeholder name (0x48d360)
};

class OpY7_TextWindow : public Console	// NOTE: placeholder name (0xcec10c)
{
public:
	char pad6c[0x7c - 0x6c];
	OpY7_TextInput *input;	// NOTE: placeholder name
};
extern OpY7_TextWindow *opy7_textWindow;	// NOTE: placeholder name

class OpY7_SpecialCommands : public Console	// NOTE: placeholder name (CSpecialCommands at 0xcec0ac)
{
public:
	void update8b0280();	// NOTE: placeholder name (CSpecialCommands vtable slot 6)
	void open8b02d0();	// NOTE: placeholder name
	void unknown8b0450();	// NOTE: placeholder name
	void unknown8b0e80(int command);	// NOTE: placeholder name
	void close8b0cc0();	// NOTE: placeholder name
	bool input8b0fd0(XEvent *event);	// NOTE: placeholder name (CSpecialCommands vtable slot 4)
	void inputAscii8b1090(int key, int modifier);	// NOTE: placeholder name (CSpecialCommands vtable slot 5)
	void setTimer();	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	bool unknown6d;	// NOTE: placeholder name
	unsigned int unknown70;	// NOTE: placeholder name
	vector<Console*> unknown74;	// NOTE: placeholder name
	vector<Console*> unknown84;	// NOTE: placeholder name
	vector<Console*> unknown94;	// NOTE: placeholder name
	int unknownA4;	// NOTE: placeholder name
	Console *unknownA8;	// NOTE: placeholder name
	unsigned int unknownAC;	// NOTE: placeholder name
};
extern OpY7_SpecialCommands *opy7_specialCommands;	// NOTE: placeholder name

class OpY7_SpecialCommand : public Console	// NOTE: placeholder name (CSpecialCommand)
{
public:
	bool mouseEnter8b01e0();	// NOTE: placeholder name (vtable slot 2)
	void mouseLeave8b0220();	// NOTE: placeholder name (vtable slot 3)
	bool input8b0150(XEvent *event);	// NOTE: placeholder name (vtable slot 4)

	int command;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
};

bool OpY7_SpecialCommand::input8b0150(XEvent *event)
{
	if (isHidden() || opy7_consoleInputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (event->type)
	{
		case 0x180:
			if (command == 4)
				opy7_cefc73 = true;
			opy7_specialCommands->inputAscii(key,0);
			return true;
	}
	return false;
}

bool OpY7_SpecialCommand::mouseEnter8b01e0()
{
	opy7_specialCommands->unknown8b0e80(command);
	animate("A_ButtonHover_Begin_HACK_HOV_OK");
	return true;
}

void OpY7_SpecialCommand::mouseLeave8b0220()
{
	opy7_specialCommands->unknown8b0e80(0xc);
	engine->killGroup("fadein");
	animate("A_ButtonHover_End_HACK_HOV_OK");
}

void OpY7_SpecialCommands::update8b0280()
{
	if (isHidden())
		return;
	if (unknown6c && !unknown6d && opy7_tickCount >= unknown70)
		unknown8b0450();
	updateBase429e30();
}

void OpY7_SpecialCommands::open8b02d0()
{
	if (opy7_tickCount < unknownAC)
		return;
	if (opy7_mapView->operate49aa00() && opy7_mapView->getField49aae0() == 2)
		return;
	if (opy7_mapView->test49aaa0())
	{
		opy7_mapView->unknown827950();
		return;
	}
	if (opy7_mapView->unknown49ac10())
	{
		opy7_mapView->unknown8081d0();
		return;
	}
	if (opy7_mapView->operate49aa00() && opy7_mapView->getField49aae0() == 1)
		opy7_mapView->unknown827950();
	if (opy7_mapView->unknown49ab60())
		opy7_mapView->unknown49ad30();
	if (!opy7_cec118->isHidden())
		opy7_cec118->unknown8b5080();
	if (!opy7_cec11c->isHidden())
		opy7_cec11c->unknown8b5080();
	if (!opy7_cec120->isHidden())
		opy7_cec120->unknown8b5080();
	if (opy7_log->getField48e740())
		opy7_log->unknown7b60e0();
	opy7_initCommandAnimations();
	unknown6c = true;
	opy7_keyMap->registerConsole(0x1c,this,0x181,0);
	unknown70 = opy7_tickCount + 150;
}

void OpY7_SpecialCommands::close8b0cc0()
{
	if (unknown6c)
	{
		if (unknown6d)
		{
			for (unsigned int i = 0; i < unknown74.size(); i++)
			{
				if (unknown74[i] != NULL)
					removeSubconsole(unknown74[i]);
			}
			unknown74.clear();
			for (unsigned int i = 0; i < unknown84.size(); i++)
			{
				if (unknown84[i] != NULL)
					removeSubconsole(unknown84[i]);
			}
			unknown84.clear();
			for (unsigned int i = 0; i < unknown94.size(); i++)
				opy7_cec034->removeSubconsole(unknown94[i]);
			unknown94.clear();
			if (unknownA8 != NULL)
			{
				removeSubconsole(unknownA8);
				unknownA8 = NULL;
			}
			opy7_mapView->setHidden(false);
			resize(1,1);
			resetBack_418450();
			unknown6d = false;
		}
		unknown6c = false;
		opy7_playSound(0x2a,0,0);
		opy7_keyMap->unknown416640();
	}
}

void OpY7_SpecialCommands::unknown8b0e80(int command)
{
	if (unknownA8 != NULL)
	{
		if (unknownA8 != NULL)
		{
			removeSubconsole(unknownA8);
			unknownA8 = NULL;
		}
	}
	const string &text = command == 12 ? opy7_d387a0 : opy7_commandDescriptions[command];
	unknownA8 = new Console(this,text.size(),1,opy7_centerOffset(text.size(),getWidth()),unknownA4,0,false,-1);
	unknownA8->print(0,0,text);
	unknownA8->unknown48c3c0(opy7_ceca6c);
}

bool OpY7_SpecialCommands::input8b0fd0(XEvent *event)
{
	if (isHidden() || opy7_consoleInputBlocked)
		return false;
	if (input429d00(event))
		return true;
	if (opy7_world->unknown71bbd0())
		return false;
	switch (event->type)
	{
		case 5:
			return false;
		case 0x17f:
			if (!unknown6c)
			{
				open8b02d0();
				return true;
			}
		case 0x181:
			if (unknown6c)
				close8b0cc0();
			return true;
	}
	return false;
}

void OpY7_SpecialCommands::inputAscii8b1090(int key, int modifier)
{
	switch (modifier)
	{
		case 1:
			key += 0x20;
		case 0:
			for (int i = 0; i < 12; i++)
			{
				if (opy7_commandKeys[i] == key)
				{
					close8b0cc0();
					switch (i)
					{
						case 0:
							opy7_mapView->unknown827cf0();
							break;
						case 2:
							opy7_search->open(0);
							break;
						case 3:
							opy7_mapView->input(&XEvent(opy7_mapView->operate49aa00() ? 0xbe : 0x93));
							break;
						case 4:
							opy7_parts->input(&XEvent(0x120));
							break;
						case 5:
							opy7_mapView->input(&XEvent(0x95));
							break;
						case 1:
							opy7_mapView->input(&XEvent(0x7c));
							break;
						case 6:
							opy7_mapView->input(&XEvent(0x83));
							break;
						case 7:
							opy7_parts->input(&XEvent(0x111));
							break;
						case 8:
							opy7_mapView->input(&XEvent(0x96));
							break;
						case 9:
							opy7_itemTag->input(&XEvent(0x174));
							break;
						case 10:
							opy7_mapView->unknown8081d0();
							break;
						case 11:
							opy7_itemTag->input(&XEvent(0x175));
							opy7_textWindow->input->setUnknown95(false);
							break;
					}
					return;
				}
			}
			break;
	}
}

//==================================================================
// CAnalysis
//==================================================================

class OpY7_Analysis : public Console	// NOTE: placeholder name (CAnalysis)
{
public:
	bool input8b1cd0(XEvent *event);	// NOTE: placeholder name (CAnalysis vtable slot 4)
	void unknown8b1c90();	// NOTE: placeholder name
};

bool OpY7_Analysis::input8b1cd0(XEvent *event)
{
	if (isHidden() || opy7_consoleInputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (event->type)
	{
		case 0xf4:
			if (opy7_cefc73)
			{
				opy7_cefc73 = false;
				return false;
			}
		case 0xf5:
			if (event->type == 0xf5 && opy7_keyMap->getField416230() != NULL && opy7_keyMap->getField416230()->getKey() == 0x20)
				opy7_specialCommands->setTimer();
			unknown8b1c90();
			return true;
	}
	return false;
}

bool opy7_compareNames8b2b40(string &a, string &b)	// NOTE: placeholder name
{
	return lexicographical_compare(a.begin() + (a.size() >= 5 && a[3] == '.' && a[4] == ' ' ? 5 : 0),a.end(),b.begin() + (b.size() >= 5 && b[3] == '.' && b[4] == ' ' ? 5 : 0),b.end());
}

//==================================================================
// CInfoButton
//==================================================================

void opy7_unknown8b1da0(HItem item, HEntity entity, int mode);	// NOTE: placeholder name
void opy7_unknown8b2ee0(int type);	// NOTE: placeholder name

class OpY7_InfoButton : public Console	// NOTE: placeholder name (CInfoButton)
{
public:
	bool input8b2c30(XEvent *event);	// NOTE: placeholder name (CInfoButton vtable slot 4)

	int type;	// NOTE: placeholder name
};

bool OpY7_InfoButton::input8b2c30(XEvent *event)
{
	if (isHidden() || opy7_consoleInputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (event->type)
	{
		case 0xe8:
			switch (type)
			{
				case 0xd:
					opy7_unknown8b1da0(opy7_cec11c->getUnknown98(),HEntity(),0);
					break;
				case 0xe:
					opy7_unknown8b1da0(opy7_cec11c->getUnknown98(),HEntity(),1);
					break;
				case 0xf:
					opy7_itemTag->openForEntity(opy7_cec11c->getUnknown98(),0);
					break;
				case 0x10:
					if (!opy7_cec118->isHidden() || (opy7_cec11c->getUnknown98().isValid() && opy7_cec120->isHidden()))
					{
						HItem item;
						if (opy7_cec118->isHidden() || (!opy7_cec118->isHidden() && opy7_activeList != NULL && opy7_activeList->getType() == 2))
							item = opy7_cec11c->getUnknown98();
						else
							item = opy7_cec118->getUnknown98();
						opy7_unknown8b1da0(item,HEntity(),3);
					}
					else
						opy7_unknown8b1da0(HItem(),opy7_cec124 != NULL ? opy7_cec124->getUnknown9c() : (!opy7_cec120->isHidden() ? opy7_cec120->getUnknown9c() : opy7_cec11c->getUnknown9c()),2);
					break;
				case 0x11:
					opy7_cec11c->input(&XEvent(0xea));
					break;
				default:
					if (opy7_activeList == NULL)
						opy7_unknown8b2ee0(type);
					break;
			}
			return true;
	}
	return false;
}
