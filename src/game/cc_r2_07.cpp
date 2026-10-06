// Cell queries (0x45d600-0x45ddeb): placement, terrain and prop tests on a map cell.
// NOTE: class layouts are partial; padding members and names are placeholders
//	unless already bound by matched callers.
#include <vector>
using namespace std;

class Entity;
class Prop;

class HEntity
{
	int	ID;
public:
	HEntity();
	bool isNull() const;
	Entity *operator->() const;
};

class HItem
{
	int	ID;
public:
	HItem();
};

class HProp
{
	int	ID;
public:
	HProp();
	bool isValid() const;
	bool isNull() const;
	Prop *operator->() const;
};

class Entity
{
public:
	int getFaction();				// NOTE: placeholder name (0x45a2c0)
};

class Prop
{
public:
	bool isPassableFor(HEntity entity);	// NOTE: placeholder name (0x65e1d0)
	bool isTrap();					// NOTE: placeholder name (0x45cb70)
	bool unknown45cb90(int value);	// NOTE: placeholder name
	bool unknown45cbd0();			// NOTE: placeholder name
	bool unknown470b30();			// NOTE: placeholder name
};

struct PropData	// NOTE: placeholder name; partial record
{
	char	unknown00[0x5c];
	bool	unknown5c;		// NOTE: placeholder name
	char	unknown5d[0x67];
	bool	unknownc4;		// NOTE: placeholder name
	char	unknownc5[0x7b];
	int		unknown140;		// NOTE: placeholder name
};

struct CellTerrainRecord	// NOTE: partial record
{
	int		ID;
	char	unknown04[0x58];
	int		passable;		// NOTE: placeholder name; 1..3 have special meanings
	bool	machinePart;	// NOTE: placeholder name
};

struct Point
{
	int x;
	int y;
};

class Cell
{
public:
	bool canPlaceProp(void *propData);	// NOTE: placeholder name (bound by matched callers)
	bool unknown45d6a0();			// NOTE: placeholder name; open, empty, non-terrain cell
	bool unknown45d700();			// NOTE: placeholder name
	bool hasBlockingObject();		// NOTE: placeholder name (bound by matched callers)
	HItem getItem();				// NOTE: placeholder name (bound by matched callers); first item or null
	bool unknown45d940();			// NOTE: placeholder name; no items, not a machine
	bool unknown45d990();			// NOTE: placeholder name
	bool unknown45da30();			// NOTE: placeholder name
	bool unknown45da50();			// NOTE: placeholder name
	void unknown45daf0(bool flag);	// NOTE: placeholder name (bound by matched callers); sets open
	void unknown45db10();			// NOTE: placeholder name; sets blocked
	void unknown45db30();			// NOTE: placeholder name; clears blocked
	bool unknown45db50();			// NOTE: placeholder name
	bool unknown45db70();			// NOTE: placeholder name; terrain->passable != 0
	bool unknown45db90();			// NOTE: placeholder name
	bool unknown45dbb0();			// NOTE: placeholder name
	bool unknown45dbf0();			// NOTE: placeholder name
	bool isEdge();					// NOTE: placeholder name (bound by matched callers)
	bool isShortcut();				// NOTE: placeholder name (bound by matched callers)
	bool unknown45dc70();			// NOTE: placeholder name
	bool unknown45dc90(int value);	// NOTE: placeholder name
	bool isMachinePart();			// NOTE: placeholder name (bound by matched callers)
	bool unknown45dcf0();			// NOTE: placeholder name; has a trap prop
	bool unknown45dd40(int value);	// NOTE: placeholder name
	bool isDoor();					// NOTE: placeholder name (bound by matched callers)
	bool unknown45d230();			// NOTE: placeholder name (0x45d230); unknown0c != -1

	CellTerrainRecord	*terrain;			// +0x00
	char				unknown04[8];
	int					unknown0c;			// +0x0c, -1 = none
	char				unknown10[0x20];
	Point				position;			// +0x30
	bool				open;				// +0x38
	bool				blocked;			// +0x39
	bool				unknown3a;			// +0x3a NOTE: placeholder name
	char				unknown3b;
	int					caveinInstability;	// +0x3c
	int					unknown40;			// +0x40 NOTE: placeholder name
	HProp				prop;				// +0x44
	HEntity				entity;				// +0x48
	vector<HItem>		items;				// +0x4c
};

bool Cell::canPlaceProp(void *propData)
{
	return (prop.isNull() || prop->isPassableFor(HEntity())) && !isMachinePart() &&
		(open || (propData != NULL && ((PropData *)propData)->unknown5c && ((PropData *)propData)->unknownc4 && ((PropData *)propData)->unknown140 == 16));
}

bool Cell::unknown45d6a0()
{
	return open && prop.isNull() && !unknown45db70() && !isMachinePart();
}

bool Cell::unknown45d700()
{
	return !items.empty() && (prop.isNull() || prop->isPassableFor(HEntity()) || prop->unknown470b30()) &&
		!unknown45db70() && !isMachinePart() && unknown3a;
}

bool Cell::hasBlockingObject()
{
	return items.empty() && (prop.isNull() || (prop->isPassableFor(HEntity()) && !isDoor())) &&
		!unknown45db70() && !isMachinePart() && open && (entity.isNull() || entity->getFaction() != 11);	// 11: some faction ID, name unknown
}

HItem Cell::getItem()
{
	return items.empty() ? HItem() : items.front();
}

bool Cell::unknown45d940()
{
	return items.empty() && !isMachinePart();
}

bool Cell::unknown45d990()
{
	return items.empty() && (prop.isNull() || (prop->isPassableFor(HEntity()) && !isDoor())) &&
		!unknown45dbf0() && !isMachinePart() && open;
}

bool Cell::unknown45da30()
{
	return !unknown45d230();
}

bool Cell::unknown45da50()
{
	return (prop.isNull() || (prop->isPassableFor(HEntity()) && !isDoor())) &&
		!unknown45dbf0() && !isMachinePart() && open && !unknown45d230();
}

void Cell::unknown45daf0(bool flag)
{
	open = flag;
}

void Cell::unknown45db10()
{
	blocked = true;
}

void Cell::unknown45db30()
{
	blocked = false;
}

bool Cell::unknown45db50()
{
	return unknown40 > 0;
}

bool Cell::unknown45db70()
{
	return terrain->passable;
}

bool Cell::unknown45db90()
{
	return unknown3a;
}

bool Cell::unknown45dbb0()
{
	return unknown45db70() && unknown3a;
}

bool Cell::unknown45dbf0()
{
	return unknown45db70() && !unknown3a;
}

bool Cell::isEdge()
{
	return terrain->passable >= 2;
}

bool Cell::isShortcut()
{
	return terrain->passable == 2;
}

bool Cell::unknown45dc70()
{
	return terrain->passable == 3;
}

bool Cell::unknown45dc90(int value)
{
	return terrain->passable == 1 || (terrain->passable == 2 && value != 4);
}

bool Cell::isMachinePart()
{
	return terrain->machinePart;
}

bool Cell::unknown45dcf0()
{
	return prop.isValid() && prop->isTrap();
}

bool Cell::unknown45dd40(int value)
{
	return prop.isValid() && prop->unknown45cb90(value);
}

bool Cell::isDoor()
{
	return prop.isValid() && prop->unknown45cbd0();
}
