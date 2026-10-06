// c105: placement / marking helpers of the map object BS (0x71bcc0-0x7206f0) matched against COGMIND.exe.
// NOTE: class layouts are partial; member names and most method names are placeholders.
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// NOTE: placeholder name (0xd30908)

struct Point
{
	int x;
	int y;

	Point();
	Point(int x_, int y_);
	Point(const Point &p);
	Point &operator=(const Point &p);
	bool operator==(const Point &p) const;
	bool adjacent(const Point &p) const;	// NOTE: placeholder name (PushGeometry::adjacent)
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const Point &p);
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	int getWidth();					// NOTE: placeholder name
	int getHeight();				// NOTE: placeholder name
};

class Entity;
class Item;
class Prop;
class Group;
class EntityAI;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool isValid() const;
	bool operator==(HEntity other) const;
	Entity *operator->() const;
};

class HItem
{
	int	ID;
public:
	bool isValid() const;
	Item *operator->() const;
};

class HProp
{
	int	ID;
public:
	bool isValid() const;
};

class HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	Group *operator->() const;
};

class Group	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: placeholder name
};

class Item
{
public:
	int getType();			// NOTE: placeholder name
	bool unknown457cf0();	// NOTE: placeholder name
	int unknown457fb0();	// NOTE: placeholder name
};

struct XColor	// NOTE: placeholder name
{
	unsigned int rgba;
	XColor(const XColor &c);
	XColor &operator=(XColor c);
};

class EntityAI	// NOTE: placeholder name
{
public:
	bool unknown458fb0(HEntity e);	// NOTE: placeholder name
};

class Entity
{
public:
	const Point &getPosition();			// NOTE: placeholder name (0x45a4a0)
	int getSize();						// NOTE: placeholder name (0x45a360)
	EntityAI *getRecord();				// NOTE: placeholder name (0x45b590)
	Point unknown45a4c0();				// NOTE: placeholder name
	int unknown45a540(const Point &p);	// NOTE: placeholder name
	const XColor &unknown5c7630();		// NOTE: placeholder name
	bool unknown5cb680(HGroup g);		// NOTE: placeholder name
	vector<Point> *getFootprint();		// NOTE: placeholder name (0x45d1a0)
};

class Cell
{
public:
	bool canPlaceEntity(int size);		// NOTE: placeholder name (0x66ad20)
	bool hasBlockingObject();			// NOTE: placeholder name (0x45d7b0)
	bool fitsProp(void *propData);		// NOTE: placeholder name (0x45d570)
	bool isPassableFor(HEntity e);		// NOTE: placeholder name (0x66ab30)
	HItem getItem();					// NOTE: placeholder name (0x45d8f0)
	HProp getProp();					// NOTE: placeholder name (0x45d550)
	HEntity getEntity();				// NOTE: placeholder name (0x45d250)
	void unknown66b640();				// NOTE: placeholder name
};

struct MapRecord	// NOTE: placeholder name
{
	char	pad0[0x28];
	int		unknown28;	// NOTE: placeholder name
};

struct MarkRecord	// NOTE: placeholder name; element of the entity record list at BS+0x10
{
	Point	position;
	HEntity	entity;
};

struct Mark	// NOTE: placeholder name
{
	int		unknown0;
	int		type;		// NOTE: placeholder name
	HEntity	entity;
	int		unknownc;
	XColor	color;
};

class Map	// NOTE: placeholder name
{
public:
	bool unknown465200(const Point &a, const Point &b);			// NOTE: placeholder name
	bool isReachable(int range, const Point &from, const Point &to);	// NOTE: placeholder name (0x465230)
};

extern Array2D<Cell *>	cells;				// NOTE: placeholder name (0xcfd44c)
extern vector<MapRecord *>	mapRecords;		// NOTE: placeholder name (0xcfd2cc)
extern int				itemTypeMatter;		// NOTE: placeholder (0xcefbe4)

extern vector<Point>	dijkstraCells;		// NOTE: placeholder name (0xd15e58)
extern int				dijkstraRangeEnd;	// NOTE: placeholder name (0xced284)
extern int				dijkstraRangeStart;	// NOTE: placeholder name (0xcef678)
extern bool				dijkstraFlag;		// NOTE: placeholder name (0xcefc9d)
void clearDijkstraResults();				// NOTE: placeholder name
void findFirstDijkstraRange();				// NOTE: placeholder name
bool findNextDijkstraRange();				// NOTE: placeholder name

class DijkstraCost_d1e1dc	// NOTE: placeholder name
{
public:
	int pad0;
	int pad4;
	int pad8;
	int padc;
};

class DijkstraCost_d35394	// NOTE: placeholder name
{
public:
	int pad0;
	int pad4;
	int pad8;
	int padc;
};

class DijkstraCost_d39714	// NOTE: placeholder name
{
public:
	int pad0;
	int pad4;
	int pad8;
	int padc;
};

class DijkstraRunner	// NOTE: placeholder name (global at 0xcfe568)
{
public:
	void run(const Point &start, int range, void *cost, void *data);	// NOTE: placeholder name (0x40ca20)
};

extern DijkstraRunner		dijkstra;			// NOTE: placeholder name (0xcfe568)
extern DijkstraCost_d1e1dc	dijkstraCost_d1e1dc;
extern DijkstraCost_d35394	dijkstraCost_d35394;
extern DijkstraCost_d39714	dijkstraCost_d39714;

class CellRect	// NOTE: placeholder name (0x40b100)
{
public:
	int pad0;
	int pad4;
	int pad8;
	int padc;
	CellRect &delegate();							// 0x40b100
	Point unknown40be90();							// NOTE: placeholder name
};

class CellArea	// NOTE: placeholder name (same object as cells)
{
public:
	void getRect(const Point &p, int radius, CellRect &out);	// NOTE: placeholder name (0x9b4430)
};

extern CellArea cellArea;	// NOTE: placeholder name (0xcfd44c)

bool isEntrance(const Point &p);					// NOTE: placeholder name (0x448b80)
int randomIndex(vector<int> &v);					// NOTE: placeholder name (0x9d5d00)
int maxInt(int a, int b);							// NOTE: placeholder name (0x9cdb60)
void eraseAt(vector<HItem> *v, int *i);				// NOTE: placeholder name (0x9d6440)
int distance(const Point &a, const Point &b);		// NOTE: placeholder name (0x40a3f0)
void getAdjacentCells(const Point &p, vector<Point> &adjacent);	// NOTE: placeholder name (0x4fab80)
void moveToIndex(vector<Point> *v, int from, int to);	// NOTE: placeholder name (0x9d53f0)
void eraseIndex(vector<Point> *v, int i);			// NOTE: placeholder name (0x9d5190)

void addEntityAt(const Point &p, vector<HEntity> &out);	// NOTE: placeholder name (0x71c470)
void addPropAt(const Point &p, vector<HProp> &out);		// NOTE: placeholder name (0x71c4e0)

class BS : public Map
{
public:
	bool unknown71bcc0(const Point &p, Point &out);
	bool findPlacement(const Point &p, Point &out, int size);		// 0x71c150
	bool unknown71c200(const Point &p, Point &out, int size);
	bool unknown71c300(const Point &p, int radius, int size, Point &out, bool avoidEntrances);
	bool unknown71c3c0(const Point &p, Point &out, void *propData);
	void unknown71c550(HEntity e, vector<HEntity> &out);
	void unknown71c6d0(HEntity e, vector<HProp> &out);
	int unknown71c850(const Point &p);
	int unknown71c930();
	bool unknown71ca20(HEntity e);
	bool unknown71cb10(HEntity e);
	int unknown71cbf0(int limit);
	void unknown71ce30(const Point &p);
	void unknown71dd30(HEntity e);
	void unknown71fe20(vector<Point> &points);
	void unknown720210(vector<Point> &points);
	void unknown720610(vector<Point> &points);
	void unknown71fef0(HEntity e);
	void unknown7202f0(HEntity e);
	void unknown7206f0(HEntity e);
	void unknown72a0b0(HEntity e);	// NOTE: placeholder name
	int unknown463e50();			// NOTE: placeholder name
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name

	char				pad0[0x10];
	vector<MarkRecord *>	markRecords;	// 0x10	NOTE: placeholder name
	char				pad1c[0x4c - 0x20];
	vector<HGroup>		groups;				// 0x4c
	char				pad58[0x4e0 - 0x5c];
	vector<HItem>		items4e0;			// 0x4e0	NOTE: placeholder name
	char				pad4ec[0x66c - 0x4f0];
	HEntity				target;				// 0x66c	NOTE: placeholder name
	char				pad670[0xb94 - 0x670];
	vector<int>			indices;			// 0xb94	NOTE: placeholder name
};

void addEntityAt(const Point &p, vector<HEntity> &out)
{
	if (cells.contains(p) && cells(p)->getEntity().isValid())
		out.push_back(cells(p)->getEntity());
}

void addPropAt(const Point &p, vector<HProp> &out)
{
	if (cells.contains(p) && cells(p)->getProp().isValid())
		out.push_back(cells(p)->getProp());
}

bool BS::unknown71bcc0(const Point &p, Point &out)
{
	if (cells(p)->hasBlockingObject() || (cells(p)->getItem().isValid() && cells(p)->getItem()->getType() == itemTypeMatter && rng.chance(50)))
	{
		out = p;
		return true;
	}
	else
	{
		clearDijkstraResults();
		dijkstra.run(p, 12, &dijkstraCost_d35394, (void *)itemTypeMatter);
		if (dijkstraCells.empty())
		{
			return false;
		}
		else
		{
			findFirstDijkstraRange();
			out = dijkstraCells[rng.rangeInt(dijkstraRangeStart, dijkstraRangeEnd)];
			return true;
		}
	}
}

bool BS::findPlacement(const Point &p, Point &out, int size)
{
	if (!cells(p)->canPlaceEntity(size))
	{
		clearDijkstraResults();
		dijkstra.run(p, 12, &dijkstraCost_d1e1dc, &size);
		if (dijkstraCells.empty())
		{
			return false;
		}
		else
		{
			findFirstDijkstraRange();
			out = dijkstraCells[rng.rangeInt(dijkstraRangeStart, dijkstraRangeEnd)];
			return true;
		}
	}
	else
	{
		out = p;
		return true;
	}
}

bool BS::unknown71c200(const Point &p, Point &out, int size)
{
	if (!cells(p)->canPlaceEntity(size))
	{
		clearDijkstraResults();
		dijkstraFlag = true;
		dijkstra.run(p, 32, &dijkstraCost_d1e1dc, &size);
		dijkstraFlag = false;
		if (dijkstraCells.empty())
		{
			return false;
		}
		else
		{
			findFirstDijkstraRange();
			while (rng.chance(80))
			{
				if (!findNextDijkstraRange())
					goto fallback;
			}
			out = dijkstraCells[rng.rangeInt(dijkstraRangeStart, dijkstraRangeEnd)];
			return true;
fallback:
			return findPlacement(p, out, size);
		}
	}
	else
	{
		out = p;
		return true;
	}
}

bool BS::unknown71c300(const Point &p, int radius, int size, Point &out, bool avoidEntrances)
{
	CellRect rect;
	rect.delegate();
	cellArea.getRect(p, radius, rect);
	for (int i = 0; i < 20; i++)
	{
		Point pt = rect.unknown40be90();
		if (cells(pt)->canPlaceEntity(size) && (!avoidEntrances || !isEntrance(pt)) && isReachable(5, pt, p))
		{
			out = pt;
			return true;
		}
	}
	return false;
}

bool BS::unknown71c3c0(const Point &p, Point &out, void *propData)
{
	if (!cells(p)->fitsProp(propData))
	{
		clearDijkstraResults();
		dijkstra.run(p, 12, &dijkstraCost_d39714, propData);
		if (dijkstraCells.empty())
		{
			return false;
		}
		else
		{
			findFirstDijkstraRange();
			out = dijkstraCells[rng.rangeInt(dijkstraRangeStart, dijkstraRangeEnd)];
			return true;
		}
	}
	else
	{
		out = p;
		return true;
	}
}

void BS::unknown71c550(HEntity e, vector<HEntity> &out)
{
	Point pos = e->getPosition();
	int size = e->getSize();
	if (pos.y > 0)
	{
		for (int i = -1; i < size + 1; i++)
			addEntityAt(Point(pos.x + i, pos.y - 1), out);
	}
	if (pos.y + size < cells.getHeight())
	{
		for (int j = -1; j < size + 1; j++)
			addEntityAt(Point(pos.x + j, pos.y + 1), out);
	}
	if (pos.x > 0)
	{
		for (int k = 0; k < size; k++)
			addEntityAt(Point(pos.x - 1, pos.y + k), out);
	}
	if (pos.x + size < cells.getWidth())
	{
		for (int l = 0; l < size; l++)
			addEntityAt(Point(pos.x + 1, pos.y + l), out);
	}
}

void BS::unknown71c6d0(HEntity e, vector<HProp> &out)
{
	Point pos = e->getPosition();
	int size = e->getSize();
	if (pos.y > 0)
	{
		for (int i = -1; i < size + 1; i++)
			addPropAt(Point(pos.x + i, pos.y - 1), out);
	}
	if (pos.y + size < cells.getHeight())
	{
		for (int j = -1; j < size + 1; j++)
			addPropAt(Point(pos.x + j, pos.y + 1), out);
	}
	if (pos.x > 0)
	{
		for (int k = 0; k < size; k++)
			addPropAt(Point(pos.x - 1, pos.y + k), out);
	}
	if (pos.x + size < cells.getWidth())
	{
		for (int l = 0; l < size; l++)
			addPropAt(Point(pos.x + 1, pos.y + l), out);
	}
}

int BS::unknown71c850(const Point &p)
{
	int count;
	vector<Point> adjacent;
	getAdjacentCells(p, adjacent);
	count = 0;
	for (unsigned int i = 0; i < adjacent.size(); i++)
	{
		if (cells(adjacent[i])->isPassableFor(HEntity()))
			count++;
	}
	return count;
}

int BS::unknown71c930()
{
	if (items4e0.empty())
		return 0;
	int total = 0;
	for (unsigned int i = 0; i < items4e0.size(); i++)
	{
		if (items4e0[i].operator->() && items4e0[i]->unknown457cf0())
			total = maxInt(total, items4e0[i]->unknown457fb0());
		else
			eraseAt(&items4e0, (int *)&i);
	}
	return total;
}

bool BS::unknown71ca20(HEntity e)
{
	if (e == target)
		return false;
	int range = unknown71c930();
	return range && unknown4631f0(e) && unknown465200(target->unknown45a4c0(), e->unknown45a4c0()) && ::distance(target->unknown45a4c0(), e->unknown45a4c0()) <= range;
}

bool BS::unknown71cb10(HEntity e)
{
	for (unsigned int i = 0; i < groups.size(); i++)
	{
		if (e->unknown5cb680(groups[i]))
		{
			vector<HEntity> *members = groups[i]->getMembers();
			for (unsigned int j = 0; j < members->size(); j++)
			{
				if ((*members)[j]->getRecord()->unknown458fb0(e))
					return true;
			}
		}
	}
	return false;
}

int BS::unknown71cbf0(int limit)
{
	if (!indices.empty())
	{
		int index;
		for (int i = 0; i < 500; i++)
		{
			index = randomIndex(indices);
			if (mapRecords[index]->unknown28 <= limit)
				return index;
		}
	}
	return 0;
}
