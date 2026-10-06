#ifndef PATHING_GAMEDECL_H
#define PATHING_GAMEDECL_H

//==================================================================
// Minimal declarations of game types used by the pathing code
//==================================================================
// NOTE: everything here belongs to other parts of the game and is only declared
//	(the bodies live elsewhere in the exe). All member/type names are placeholders
//	unless they are RTTI class names.

#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();					// (-1,-1)
	Point(int v);
	Point(int x_, int y_);
	Point(const Point &p);
	Point(const Point &p, int dx, int dy);	// 0x4099c0
	Point &operator=(const Point &p);
	bool operator!=(const Point &p) const;
	void set(int x_, int y_);
	bool isInvalid() const;		// NOTE: placeholder name; x < 0 || y < 0
};

// 2D array, column-major: data[x * height + y]
template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(int x, int y);
	T &operator()(const Point &p);
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	int getWidth() { return width; };	// NOTE: placeholder name (0x9fcd80)
	int getHeight();				// NOTE: placeholder name (0x9b8f00)
	void getAdjacent(const Point &p, vector<Point> &adjacent);	// NOTE: placeholder name (0x9ce500)
};

class Entity;
class Item;
class Prop;
class Group;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	int getID() const;
	bool operator==(HEntity other) const;
	bool operator!=(HEntity other) const;
	bool isValid() const;
	bool isNull() const;
	Entity *operator->() const;
};

class HItem
{
	int	ID;
public:
	HItem();
	bool isValid() const;
	Item *operator->() const;
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

class HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	HGroup();
	Group *operator->() const;	// 0x9b7250
};

class Group	// NOTE: placeholder name
{
public:
	int getType();	// NOTE: placeholder name (ICF'd trivial getter)
};

class Item
{
public:
	int getType();	// NOTE: placeholder name (ICF'd trivial getter)
};

struct PropData	// NOTE: placeholder name
{
	char	pad[0xF4];
	int		interactType;	// 2 = noninteractive machine?
};

class Prop
{
public:
	bool isPassableFor(HEntity entity);	// NOTE: placeholder name (0x65e1d0)
	bool isOpenPassage();			// NOTE: placeholder name (0x45c7a0)
	bool usesWallArmor();			// NOTE: placeholder name (0x45cb70)
	bool isTrap();					// NOTE: placeholder name (0x45cb70)
	PropData *getData();			// NOTE: placeholder name (0x9b8f00)
	int getTerminalIndex();			// NOTE: placeholder name (0x45c630)
	bool blocksEntity(HEntity e);	// NOTE: placeholder name (0x65e1d0)
};

struct EntityRecord	// NOTE: placeholder
{
	HEntity getOwner();	// 0x458e90
};

class Entity
{
	int unknown00;
	HEntity handle;	// +4, partial x86 layout
public:
	bool canEnterCaveWall();			// NOTE: placeholder name (0x45a380)
	bool isPlayer();						// NOTE: placeholder name (0x5c7600)
	int getFaction();					// NOTE: placeholder name (0x45a2c0)
	int getAiType();					// NOTE: placeholder name (0x45a2a0)
	int getSize();						// NOTE: placeholder name (0x45a360)
	EntityRecord *getRecord();			// NOTE: placeholder name (0x45b590)
	const Point &getPosition();			// NOTE: placeholder name (0x45a4a0)
	HGroup getGroup();					// NOTE: placeholder name (0x45a3f0)
	bool isInGroup(HGroup g);			// NOTE: placeholder name (0x5cb6b0)
	bool isHostileTo(HEntity e);		// NOTE: placeholder name (0x45aa70)
	int getTarget();					// NOTE: placeholder name (0x45a760)
	bool isXomCandidate();				// NOTE: placeholder name (0x5d51a0)
};

struct CellTerrainRecord	// NOTE: partial record; descriptive field names
{
	int ID;
	char unknown04[0x58];
	int passable;
	char unknown60[8];
	int armor;
};

struct CellEffectRecord	// NOTE: partial record
{
	int type;
};

struct CellEffect	// NOTE: partial effect object
{
	CellEffectRecord *record;
	int value;
};

class Cell
{
	// NOTE: partial 32-bit layout recovered from cave-in callers. Do not allocate
	// Cells from this declaration: the remaining fields are not reconstructed.
	CellTerrainRecord *terrain;
	char unknown04[0x2c];
	Point position;
	bool open;
	bool blocked;
	char unknown3a[2];
	int caveinInstability;
	int unknown40;
	HProp prop;
	HEntity entity;
	vector<HItem> items;
	vector<CellEffect *> effects;
public:
	bool canCaveIn();				// NOTE: placeholder name (0x66af50)
	int getCaveinInstability();		// NOTE: placeholder name (0x457b10)
	void destabilize(int cause, bool force);	// NOTE: placeholder name (0x66d4e0)
	CellEffect *getEffect(int type);	// NOTE: placeholder name (0x45d350)
	int getEffectValue(int type);		// NOTE: placeholder name (0x45d3c0)
	bool isPassableWithoutEntity();	// NOTE: placeholder name (0x66ac40)
	int getArmor();					// NOTE: placeholder name (0x66ae70)
	bool isOpen();						// NOTE: placeholder name (0x4550b0)
	void removeItem(HItem item);		// NOTE: placeholder name (0x66c020)
	int getTerrain();					// NOTE: placeholder name (0x9fcd80)
	bool canPlaceItem();				// NOTE: placeholder name (0x45d880)
	bool hasBlockingObject();			// NOTE: placeholder name (0x45d7b0)
	HItem getItem();					// NOTE: placeholder name (0x45d8f0)
	HProp getProp();					// NOTE: placeholder name (0x45d550)
	HEntity getEntity();				// NOTE: placeholder name (0x45d250)
	bool isDoor();						// NOTE: placeholder name (0x45dda0)
	bool canPlaceProp(void *propData);	// NOTE: placeholder name (0x45d600)
	bool fitsProp(void *propData);		// NOTE: placeholder name (0x45d570)
	bool isShortcut();					// NOTE: placeholder name (0x45dc50)
	bool isEdge();						// NOTE: placeholder name (0x45dc30)
	bool isMachinePart();				// NOTE: placeholder name (0x45dcd0)
	bool isPassable(int size);			// NOTE: placeholder name (0x66ad90)
	bool canPlaceEntity(int size);		// NOTE: placeholder name (0x66ad20)
	bool isPassableFor(HEntity e);		// NOTE: placeholder name (0x66ab30)
	bool isDamagedMachine();			// NOTE: placeholder name (0x66b170)
};

struct MachineHandle	// NOTE: placeholder
{
	int	ID;
	struct MachineData { int pad; int type; } *operator->();
};

struct MapZone	// NOTE: placeholder
{
	int				pad[2];
	MachineHandle	machine;
};

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	void registerUnstableCell(const Point &p);	// NOTE: placeholder name (0x4648a0)
	MapZone *getZone(const Point &p);					// NOTE: placeholder name (0x462e30)
	bool isKnown(int x, int y);							// NOTE: placeholder name (0x463130)
	bool isVisible(int x, int y);						// NOTE: placeholder name (0x463190)
	bool isVisible(const Point &p);						// NOTE: placeholder name (0x4631c0)
	HEntity getPlayer();								// NOTE: placeholder name (0x4630f0)
	bool isReachable(int range, const Point &from, const Point &to);	// NOTE: placeholder name (0x465230)
	Array2D<bool> &getMimicGrid();						// NOTE: placeholder name (0x463810)
};

struct Grid2DBounds	// NOTE: placeholder, the object passed to DijkstraCostRevealLayout as data
{
	bool contains(int x, int y);	// 0x40b700
};

extern Array2D<Cell *>	cells;			// NOTE: placeholder name (0xcfd44c)
extern Array2D<int>		entranceMap;	// NOTE: placeholder name (0xcf447c)
extern Map				*world;			// NOTE: placeholder name (0xcefc4c)

extern int	TERRAIN_EARTH;		// NOTE: placeholder (0xcefb80)
extern int	TERRAIN_RUBBLE;		// NOTE: placeholder (0xcefb84)
extern int	TERRAIN_CAVE_WALL;	// NOTE: placeholder (0xcefba0)
extern PropData	*subcavePropData;	// NOTE: placeholder (0xcefbd8)
extern int	itemTypeMatter;		// NOTE: placeholder (0xcefbe4)

// free helpers
void getAdjacentCells(const Point &p, vector<Point> &adjacent);	// NOTE: placeholder name (0x4fab80)
int distance(const Point &a, const Point &b);					// NOTE: placeholder name (0x40a3f0)
template <class T> bool addUnique(vector<T> &v, T e);			// NOTE: placeholder name (0x9d3020)
template <class T> int findIndex(vector<T> &v, T e);			// NOTE: placeholder name (0x9d53a0)
template <class T> bool inArray(const T *a, unsigned int n, T e);	// NOTE: placeholder name (0x9d43b0)

#endif // PATHING_GAMEDECL_H
