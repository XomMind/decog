// op_x5_b_a: CInventory scrolling 0x8a2120, Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos(const Pos &pos, int dx, int dy);	// 0x4099c0
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();

	void clear(int x, int y, int width, int height);
	void setPos(const Pos &pos);
	Pos getPos();
	void removeSubconsole(XConsole *console);

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	virtual ~Console();

	int unknown60;
	void *engine;
	char pad68[0x6c - 0x68];
};

class OpX5B_Item	// NOTE: placeholder name (Item)
{
public:
	int getNestedField();	// NOTE: placeholder name (0x4578c0)
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	OpX5B_Item *operator->() const;	// 0x9b65b0
	bool operator==(HItem other) const;	// 0x9b78e0
};

class CInventoryItem : public Console
{
public:
	CInventoryItem(XConsole *parent, int y, int count, HItem item_, int type_);	// 0x4a9ff0
	void setCount(int count);	// NOTE: placeholder name (0x4aa210)
	void drawState();	// NOTE: placeholder name (0x4aa560)

	HItem item;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
	Console *marker;	// NOTE: placeholder name
	void *bar;	// NOTE: placeholder name
};

class OpX5B_Entity	// NOTE: placeholder name (Entity)
{
public:
	void unknown5cb830(vector<HItem> *list);	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity() throw();	// 0x9b6590
	OpX5B_Entity *operator->() const;	// 0x9b6570
};

class OpX5B_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
};
extern OpX5B_World *opx5b_world;	// NOTE: placeholder name (0xcefc4c)

class OpX5B_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	void updatePosition();	// NOTE: placeholder name (0x41a8b0)
};
extern OpX5B_Mouse *opx5b_mouse;	// NOTE: placeholder name (0xcefa94)
extern int opx5b_d33be8;	// NOTE: placeholder name (inventory width)

void opx5b_removeVectorElement(vector<CInventoryItem*> &v, int index);	// NOTE: placeholder name (0x9de6f0)
void opx5b_insertAt(vector<CInventoryItem*> &v, int index, CInventoryItem *value);	// NOTE: placeholder name (0x9dbdc0)

//==================================================================
// CInventory
//==================================================================

class OpX5B_Inventory : public Console	// NOTE: placeholder name (CInventory, vtable 0xc35cdc)
{
public:
	void scroll8a2120(int direction);	// NOTE: placeholder name

	char pad6c[0x74 - 0x6c];
	vector<CInventoryItem*> items;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
	CInventoryItem *unknown8c;	// NOTE: placeholder name
	CInventoryItem *unknown90;	// NOTE: placeholder name
};

void OpX5B_Inventory::scroll8a2120(int direction)
{
	vector<HItem> list;
	unsigned int p;
	int w;
	opx5b_world->getPlayer()->unknown5cb830(&list);
	if (direction != 0)
	{
		for (unsigned int i = 0; i < items.size(); i++)
		{
			items[i]->setPos(Pos(items[i]->getPos(),0,direction));
			if (items[i]->type < 2)
			{
				switch (direction)
				{
					case -1:
						items[i]->setCount(i);
						break;
					case 1:
						items[i]->setCount(i + 2);
						break;
				}
			}
		}
		switch (direction)
		{
			case -1:
				if (items.front() != NULL)
				{
					removeSubconsole(items.front());
					items.front() = NULL;
				}
				opx5b_removeVectorElement(items,0);
				break;
				break;
			case 1:
				if (items.back() != NULL)
				{
					removeSubconsole(items.back());
					items.back() = NULL;
				}
				items.pop_back();
				break;
		}
	}
	if (direction == 0)
	{
		unsigned int m = unknown84;
		int n = 0;
		for (; m < list.size() && n < 10; m++)
		{
			int b = m == unknown84 ? unknown88 : 0;
			for (; b < list[m]->getNestedField() && n < 10; b++, n++)
			{
				items.push_back(new CInventoryItem(this,n + 2,n + 1,list[m],b != 0));
				items.back()->drawState();
			}
		}
	}
	else if (direction < 0)
	{
		items.push_back(new CInventoryItem(this,0xb,0xa,unknown90->item,(unknown90->item == items.back()->item) != 0));
		items.back()->drawState();
	}
	else
	{
		opx5b_insertAt(items,0,new CInventoryItem(this,2,1,unknown8c->item,unknown88 != 0));
		items.front()->drawState();
	}
	if (unknown8c != NULL && unknown8c != NULL)
	{
		removeSubconsole(unknown8c);
		unknown8c = NULL;
	}
	if (unknown84 > 0 || unknown88 > 0)
	{
		unknown8c = new CInventoryItem(this,1,0,unknown88 != 0 ? list[unknown84] : list[unknown84 - 1],2);
		unknown8c->drawState();
	}
	else
		clear(1,1,opx5b_d33be8 - 2,1);
	if (unknown90 != NULL && unknown90 != NULL)
	{
		removeSubconsole(unknown90);
		unknown90 = NULL;
	}
	p = unknown84;
	{
		int count = 0;
		for (; p < list.size() && count <= 10; p++)
		{
			w = count != 0 ? 0 : unknown88;
			for (; w < list[p]->getNestedField(); w++)
			{
				count++;
				if (count > 10)
					goto done;
			}
		}
	}
done:
	if (p < list.size())
	{
		unknown90 = new CInventoryItem(this,0xc,0,list[p],3);
		unknown90->drawState();
	}
	else
		clear(1,0xc,opx5b_d33be8 - 2,1);
	opx5b_mouse->updatePosition();
}
