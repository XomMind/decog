// team_d_70: ForcegenObject::ForcegenObject (0x500740): snapshot of the terrain/prop/robot/item
// at a map position (used by Entity::projectileImpact).
// NOTE: the class name comes from the exe's log strings; layouts are partial and member names are placeholders.
#include <string>
using namespace std;

void logError(string location, string message);

struct Point
{
	int x;
	int y;
};
string OpQ1_pointToString(const Point &p);	// NOTE: placeholder name (0x40a4a0)

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();
	XColor(const XColor &c);
	XColor &operator=(XColor c);
};
extern XColor color70_d29804;	// NOTE: placeholder name

struct Terrain70	// NOTE: placeholder name and layout
{
	char	pad00[0x47];
	XColor	back;	// +0x47
};

class Prop
{
public:
	int getHeight();			// NOTE: folded getter (Array2D<XCell>::getHeight)
	int unknown45c650();		// NOTE: placeholder name
	XColor unknown65dbb0();		// NOTE: placeholder name
	XColor unknown65e040();		// NOTE: placeholder name
};

class Entity
{
public:
	int unknown5c7c20(bool a, bool b);	// NOTE: placeholder name
};

class Item
{
public:
	int getID();				// NOTE: folded getter (PingRequest::GetCachedSize)
	int unknown457a30();		// NOTE: placeholder name
	XColor *unknown5755f0(bool force);	// NOTE: placeholder name
};

class HProp
{
public:
	int ID;
	HProp();
	bool isNull() const;
	Prop *operator->() const;	// NOTE: folded (OpC_Handle::get22c)
};

class HEntity
{
public:
	int ID;
	HEntity();	// NOTE: folded with HProp::HProp
	bool isNull() const;		// NOTE: folded with HProp::isNull
	Entity *operator->() const;
};

class HItem
{
public:
	int ID;
	bool isNull() const;		// NOTE: folded with HProp::isNull
	Item *operator->() const;	// NOTE: folded (OpC_Handle::get224)
};

class Cell
{
public:
	Terrain70 *terrain9fcd80();	// NOTE: placeholder name, folded getter 0x9fcd80 (Array2D<Cell*>::getWidth)
	int getAscii();
	XColor getColor();
	HProp getProp();
	HEntity getEntity();
	HItem getItem();
};

class CellGrid70	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: folded (OpX5_Array2D<int>::atPoint)
};
extern CellGrid70 cells70_cfd44c;	// NOTE: placeholder name

class ForcegenObject	// NOTE: placeholder layout
{
public:
	int			type;		// +0x00 (0 terrain, 1 prop, 2 robot, 3 item)
	Terrain70	*terrain;	// +0x04
	int			height;		// +0x08
	HEntity		entity;		// +0x0c
	int			itemID;		// +0x10
	int			ascii;		// +0x14
	XColor		fore;		// +0x18
	XColor		back;		// +0x1b
	bool		unknown1e;	// +0x1e

	ForcegenObject(int type, const Point &pos);
};

ForcegenObject::ForcegenObject(int type, const Point &pos)
	: type(type), terrain(0), height(0), itemID(0), unknown1e(false)
{
	switch (this->type)
	{
	case 0:
		terrain = (*cells70_cfd44c.atPoint(pos))->terrain9fcd80();
		ascii = (*cells70_cfd44c.atPoint(pos))->getAscii();
		fore = (*cells70_cfd44c.atPoint(pos))->getColor();
		back = terrain->back;
		break;
	case 1:
		if ((*cells70_cfd44c.atPoint(pos))->getProp().isNull())
		{
			logError("ForcegenObject()","no prop found at " + OpQ1_pointToString(pos));
			break;
		}
		height = (*cells70_cfd44c.atPoint(pos))->getProp()->getHeight();
		ascii = (*cells70_cfd44c.atPoint(pos))->getProp()->unknown45c650();
		fore = (*cells70_cfd44c.atPoint(pos))->getProp()->unknown65dbb0();
		back = (*cells70_cfd44c.atPoint(pos))->getProp()->unknown65e040();
		break;
	case 2:
		if ((*cells70_cfd44c.atPoint(pos))->getEntity().isNull())
		{
			logError("ForcegenObject()","no ent found at " + OpQ1_pointToString(pos));
			break;
		}
		entity = (*cells70_cfd44c.atPoint(pos))->getEntity();
		ascii = (*cells70_cfd44c.atPoint(pos))->getEntity()->unknown5c7c20(false,true);
		back = color70_d29804;
		break;
	case 3:
		if ((*cells70_cfd44c.atPoint(pos))->getItem().isNull())
		{
			logError("ForcegenObject()","no item found at " + OpQ1_pointToString(pos));
			break;
		}
		itemID = (*cells70_cfd44c.atPoint(pos))->getItem()->getID();
		ascii = (*cells70_cfd44c.atPoint(pos))->getItem()->unknown457a30();
		fore = *(*cells70_cfd44c.atPoint(pos))->getItem()->unknown5755f0(false);
		back = color70_d29804;
		break;
	}
}
