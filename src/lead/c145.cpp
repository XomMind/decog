// CInventory helpers and small consoles at 0x8a0d10-0x8a7310 (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos(const Pos &pos);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	bool operator==(HEntity other) const;
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp();
};

struct ItemRef	// NOTE: placeholder name
{
	int pad2c[0x2c / 4];
	int unknown2c;
};

struct ItemData	// NOTE: placeholder name
{
	char pad00[0x128];
	int unknown128;
	char pad12c[0x1a0 - 0x12c];
	ItemRef *unknown1a0;
	char pad1a4[0x1b0 - 0x1a4];
	bool unknown1b0;
};

class Item	// NOTE: placeholder layout
{
public:
	int unknown457820();	// NOTE: placeholder name
	int unknown457880();	// NOTE: placeholder name
	int unknown4578a0();	// NOTE: placeholder name
	int unknown4578c0();	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
	int unknown457fd0();	// NOTE: placeholder name
	ItemData *unknownGetData();	// NOTE: placeholder name
};

class HItemP	// NOTE: placeholder layout (operator-> at 0x9b65b0)
{
public:
	int ID;
	bool isValid() const;
	Item *operator->() const;
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

	bool contains(const Pos &p);
	void clearInterior();
	void clear();
	int getHeight();
	int getWidth();
	void setPos(const Pos &p);
	void putChar_418110(int x, int y, int ch, XColor fore);
	void setHidden(bool hidden);
	void unknown417b60(float value);	// NOTE: placeholder name
	void unknown417b80(float value);	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();

	void animate(string name);	// NOTE: placeholder name

	int unknown60;
	void *engine;
	void *title;
};

class XBuffer;

// element of CInventory::records (a Console, 0x74 bytes)
struct MapRecord : public Console	// NOTE: placeholder name
{
	MapRecord(XConsole *parent, int value);

	union
	{
		HEntity entity;	// NOTE: placeholder name
		HItemP item;	// NOTE: placeholder name
	};
	char pad70[0x80 - 0x70];
	int id;	// NOTE: placeholder name

	void unknown4aa3a0(int flag);	// NOTE: placeholder name
};

struct PushBounds
{
	int x;
	int y;
	int width;
	int height;
	Pos topLeft();
};

extern PushBounds *bounds;	// NOTE: placeholder name (0xcefa94)
extern XColor *borderColor;	// NOTE: placeholder name (0xcf6b24)
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern int unknown_cefc90;	// NOTE: placeholder name
extern bool unknown_cefc89;	// NOTE: placeholder name

bool unknown9daf80(int a, int b, int c);	// NOTE: placeholder name
Pos unknown4b33b0();	// NOTE: placeholder name

class CInventory : public Console
{
public:
	virtual void trigger(const string &command, int value);	// NOTE: placeholder name

	int unknown8a0d10(HEntity entity);	// NOTE: placeholder name
	int unknown8a0d70(int id);	// NOTE: placeholder name
	int unknown8a0df0(int id);	// NOTE: placeholder name
	void unknown8a1b40();	// NOTE: placeholder name
	void unknown8a1f90();	// NOTE: placeholder name
	MapRecord *unknown8a1fd0(HEntity entity, bool flag);	// NOTE: placeholder name
	int unknown8a20b0();	// NOTE: placeholder name
	void unknown8a2120(int delta);	// NOTE: placeholder name
	void unknown8a2930();	// NOTE: placeholder name
	void unknown8a29b0();	// NOTE: placeholder name
	void unknown8a5680();	// NOTE: placeholder name
	void unknown8a56d0(int value);	// NOTE: placeholder name
	void unknown8a5740();	// NOTE: placeholder name
	void unknown8a57e0();	// NOTE: placeholder name
	void unknown8a5860();	// NOTE: placeholder name
	void unknown8a5900();	// NOTE: placeholder name
	void unknown8a59a0();	// NOTE: placeholder name
	void unknown8a5a40();	// NOTE: placeholder name
	void unknown8a5ab0();	// NOTE: placeholder name
	void unknown8a5b20(int value);	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	unsigned int unknown70;	// NOTE: placeholder name
	vector<MapRecord*> records;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
	MapRecord *unknown8c;	// NOTE: placeholder name
	MapRecord *unknown90;	// NOTE: placeholder name
};

int CInventory::unknown8a0d10(HEntity entity)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->entity == entity)
			return i;
	}
	return -1;
}

int CInventory::unknown8a0d70(int id)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->id == id)
		{
			if (records[i]->item.isValid())
				return i;
			else
				return -1;
		}
	}
	return -1;
}

int CInventory::unknown8a0df0(int id)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->id == id)
			return i;
	}
	return -1;
}

void CInventory::unknown8a1b40()
{
	unknown60 = 3;
	setHidden(false);
	if (unknown6c)
	{
		clearInterior();
		animate("CInventory_Content");
	}
	else
	{
		clear();
		animate("CInventory_Border");
		unknown6c = true;
	}
	unknown417b60(1.0f);
	unknown417b80(1.0f);
}

void CInventory::unknown8a1f90()
{
	unknown60 = 4;
	unknown70 = tickCount;
	animate("A_BlockFadeInterior");
}

MapRecord *CInventory::unknown8a1fd0(HEntity entity, bool flag)
{
	if (flag)
	{
		if (unknown8c && unknown8c->entity == entity)
			return unknown8c;
		if (unknown90 && unknown90->entity == entity)
			return unknown90;
	}
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->entity == entity)
			return records[i];
	}
	return NULL;
}

int CInventory::unknown8a20b0()
{
	Pos pos = bounds->topLeft();
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->contains(pos))
			return i;
	}
	return -1;
}

void CInventory::trigger(const string &command, int value)
{
	if (command == "show_items")
		unknown8a2120(0);
}

void CInventory::unknown8a2930()
{
	if (!unknown8c)
		return;
	if (unknown88 > 0)
		unknown88--;
	else
	{
		unknown84--;
		unknown88 = unknown8c->item->unknown4578c0() - 1;
	}
	unknown8a2120(1);
}

void CInventory::unknown8a29b0()
{
	if (!unknown90)
		return;
	if (unknown88 < records.front()->item->unknown4578c0() - 1)
		unknown88++;
	else
	{
		unknown84++;
		unknown88 = 0;
	}
	unknown8a2120(-1);
}

void CInventory::unknown8a5680()
{
	for (unsigned int i = 0; i < records.size(); i++)
		records[i]->unknown4aa3a0(0);
}

void CInventory::unknown8a56d0(int value)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->item->unknown457820() == value)
			records[i]->unknown4aa3a0(0);
	}
}

void CInventory::unknown8a5740()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->item->unknown457f90() == 1 && records[i]->item->unknown457fd0())
			records[i]->unknown4aa3a0(0);
	}
}

void CInventory::unknown8a57e0()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->item->unknownGetData()->unknown1b0)
			records[i]->unknown4aa3a0(0);
	}
}

void CInventory::unknown8a5860()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->item->unknown457880() == 0x14 || records[i]->item->unknown457880() == 0x15)
			records[i]->unknown4aa3a0(0);
	}
}

void CInventory::unknown8a5900()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->item->unknown457880() == 0x16 || records[i]->item->unknown457880() == 0x17)
			records[i]->unknown4aa3a0(0);
	}
}

void CInventory::unknown8a59a0()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->item.isValid() && unknown9daf80(0x1a,records[i]->item->unknown457880(),0x1c))
			records[i]->unknown4aa3a0(0);
	}
}

void CInventory::unknown8a5a40()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->item->unknown457880() >= 0x1a)
			records[i]->unknown4aa3a0(1);
	}
}

void CInventory::unknown8a5ab0()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->item->unknown457f90() == 0xc9)
			records[i]->unknown4aa3a0(1);
	}
}

void CInventory::unknown8a5b20(int value)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->item.isValid() && records[i]->item->unknown4578a0() == 3)
		{
			if ((value == 0x17 && records[i]->item->unknownGetData()->unknown1a0 && records[i]->item->unknownGetData()->unknown1a0->unknown2c == 2)
				|| records[i]->item->unknownGetData()->unknown128 == value - 0x15)
				records[i]->unknown4aa3a0(0);
		}
	}
}

//==================================================================
// small consoles near CInventory
//==================================================================

struct OpE_Command	// NOTE: placeholder name
{
	OpE_Command(int command_);

	int command;
	int data0;
	int data1;
};

class World	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	bool unknown71bbd0();	// NOTE: placeholder name
};
extern World *world;	// NOTE: placeholder name (0xcefc4c)
extern CInventory *inventory;	// NOTE: placeholder name (0xcec08c)
extern XConsole *unknown_cec090;	// NOTE: placeholder name

class Unknown_8a1600 : public Console	// NOTE: placeholder name
{
public:
	Unknown_8a1600(XConsole *parent);
	bool unknown8a15a0(void *event);	// NOTE: placeholder name

	vector<XBuffer*> children;	// NOTE: placeholder name
};

class Unknown_4a9f10 : public Console	// NOTE: placeholder name
{
public:
	Unknown_4a9f10(XConsole *parent, int value);

	char pad6c[0x74 - 0x6c];
};

bool Unknown_8a1600::unknown8a15a0(void *event)
{
	if (world->unknown71bbd0())
		return false;
	switch (*(int*)event)
	{
		case 0x127:
			inventory->input(&OpE_Command(0x126));
			return true;
	}
	return false;
}

Unknown_8a1600::Unknown_8a1600(XConsole *parent)
	: Console(parent,10,1,3,parent->getHeight() - 1,0,false,-1)
{
	putChar_418110(0,0,0x7b,*borderColor);
	for (int i = 2; i < getWidth() - 1; i += 2)
		putChar_418110(i,0,0x5c,*borderColor);
	putChar_418110(getWidth() - 1,0,0x7d,*borderColor);
	children.push_back((XBuffer*)new Unknown_4a9f10(this,1));
}

class Unknown_8a7310 : public Console	// NOTE: placeholder name
{
public:
	bool unknown8a7310(void *event);	// NOTE: placeholder name

	MapRecord *unknown6c;	// NOTE: placeholder name
};

bool Unknown_8a7310::unknown8a7310(void *event)
{
	if (world->unknown71bbd0())
		return false;
	switch (*(int*)event)
	{
		case 0x156:
			unknown_cec090->inputMouse(unknown6c->id,0);
			return true;
	}
	return false;
}

class Unknown_8a53c0 : public Console	// NOTE: placeholder name
{
public:
	void unknown8a53c0();	// NOTE: placeholder name
};

class Unknown_510d20	// NOTE: placeholder name
{
public:
	Unknown_510d20(int a, int b, int c, int d, HProp e, HProp f);
	int pad[8];
};
class Unknown_cec0f4	// NOTE: placeholder name
{
public:
	void unknown7b1880(Unknown_510d20 *obj);	// NOTE: placeholder name
};
extern Unknown_cec0f4 *unknown_cec0f4;	// NOTE: placeholder name (0xcec0f4)

void Unknown_8a53c0::unknown8a53c0()
{
	switch (unknown_cefc90)
	{
		case 0:
			unknown_cec0f4->unknown7b1880(new Unknown_510d20(0x7e,0,0,0,HProp(),HProp()));
			break;
		case 1:
			unknown_cefc89 = true;
			setPos(unknown4b33b0());
			break;
		case 2:
			unknown_cefc89 = false;
			setPos(unknown4b33b0());
			break;
	}
}
