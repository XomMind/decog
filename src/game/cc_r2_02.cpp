// Map: small header-inline accessors (0x465200-0x4657ba).
// NOTE: class layout is partial; padding members, member names and most method names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;

	Point(int x_, int y_) throw();						// 0x46ca20
	bool operator==(const Point &p) const;				// 0x409b90
};

class Item	// NOTE: placeholder layout
{
public:
	const Point &getPosition();							// NOTE: placeholder name (0x575920)
};

class Entity	// NOTE: placeholder layout
{
public:
	void unknown44e360(int v);							// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	Entity *operator->() const;							// 0x9b6570
};

class HItem	// NOTE: placeholder layout
{
	int	ID;
public:
	operator Item *() const;							// 0x9b65b0
};

class XBuffer	// NOTE: placeholder layout
{
public:
	XBuffer(int a, int b) throw();								// 0x46ca20
};

int findItemIndex(vector<HItem> &v, HItem e);			// 0x9d3110
int findEntityIndex(vector<HEntity> &v, HEntity e);		// 0x9d3110
void eraseEntityAt(vector<HEntity> &v, int i);			// 0x9da940
void removeVectorElement(vector<int> &v, int i);		// 0x9de6f0
bool unknown9d31e0(vector<HEntity> &v, HEntity e);		// NOTE: placeholder name
void unknown9d30e0(vector<HEntity> &v, HEntity e);		// NOTE: placeholder name
void deleteVector(vector<XBuffer*> &v);					// NOTE: placeholder name (0x9d0670)

class Map	// NOTE: placeholder layout
{
	char			pad0[0x2d0];
public:
	vector<HItem>	items;				// 0x2d0	NOTE: placeholder name
	vector<Point>	itemPositions;		// 0x2e0	NOTE: placeholder name
	bool			flag2f0;			// NOTE: placeholder name
private:
	char			pad2f1[3];
public:
	vector<HEntity>	entities;			// 0x2f4	NOTE: placeholder name
	vector<int>		entityValues;		// 0x304	NOTE: placeholder name
private:
	char			pad314[0x320 - 0x314];
public:
	int				unknown320;			// NOTE: placeholder name
private:
	char			pad324[0x6a8 - 0x324];
public:
	vector<Point>	points6a8;			// NOTE: placeholder name
private:
	char			pad6b8[0x7b4 - 0x6b8];
public:
	vector<HEntity>	list7b4;			// NOTE: placeholder name
private:
	char			pad7c4[0x7d0 - 0x7c4];
public:
	vector<Point>	points7d0;			// NOTE: placeholder name
private:
	char			pad7e0[0x9b4 - 0x7e0];
public:
	int				unknown9b4;			// NOTE: placeholder name
private:
	char			pad9b8[0x9bc - 0x9b8];
public:
	vector<HEntity>	list9bc;			// NOTE: placeholder name
private:
	char			pad9cc[0xa04 - 0x9cc];
public:
	int				unknownA04;			// NOTE: placeholder name
	int				unknownA08;			// NOTE: placeholder name
private:
	char			padA0c[0xa15 - 0xa0c];
public:
	bool			flagA15;			// NOTE: placeholder name
	bool			flagA16;			// NOTE: placeholder name
private:
	char			padA17;
public:
	int				unknownA18;			// NOTE: placeholder name
private:
	char			padA1c[0xa60 - 0xa1c];
public:
	vector<XBuffer*>	buffers;		// NOTE: placeholder name
	unsigned int	unknownA70;			// NOTE: placeholder name
	bool			flagA74;			// NOTE: placeholder name
private:
	char			padA75[0xa7c - 0xa75];
public:
	HEntity			entityA7c;			// NOTE: placeholder name
private:
	char			padA80[0xb18 - 0xa80];
public:
	int				unknownB18;			// NOTE: placeholder name
private:
	char			padB1c[0xb24 - 0xb1c];
public:
	vector<HEntity>	listB24;			// NOTE: placeholder name

	bool unknown72a290(int x1, int y1, int x2, int y2);							// NOTE: placeholder name
	bool unknown72a4d0(int a, int x1, int y1, int x2, int y2);					// NOTE: placeholder name
	void unknown72a9d0(int a, int x1, int y1, int x2, int y2, int b);			// NOTE: placeholder name
	void unknown72ad80(int a, int x1, int y1, int x2, int y2, int b, int c);	// NOTE: placeholder name
	void unknown72b030(int a, int b, int c, int d);								// NOTE: placeholder name

	void unknown465200(const Point &a, const Point &b);							// NOTE: placeholder name
	bool isReachable(int range, const Point &from, const Point &to);			// NOTE: placeholder name
	void unknown465270(int a, const Point &b, const Point &c, int d);			// NOTE: placeholder name
	void unknown4652b0(int a, const Point &b, const Point &c, int d, int e);	// NOTE: placeholder name
	void unknown4652f0(int a, int b, int c, int d);								// NOTE: placeholder name
	void addPoint6a8(const Point &p);											// NOTE: placeholder name
	void resetUnknown9b4();														// NOTE: placeholder name
	void addList9bc(HEntity e);													// NOTE: placeholder name
	void unknown465380();														// NOTE: placeholder name
	void unknown4653b0();														// NOTE: placeholder name
	void setUnknownA18(int v);													// NOTE: placeholder name
	void addBuffer(int a, int b);												// NOTE: placeholder name
	void deleteBuffers();														// NOTE: placeholder name
	void raiseUnknownA70(unsigned int v);										// NOTE: placeholder name
	void setFlagA74(bool v);													// NOTE: placeholder name
	void setEntityA7c(HEntity e);												// NOTE: placeholder name
	void setUnknownB18(int v);													// NOTE: placeholder name
	void addListB24(HEntity e);													// NOTE: placeholder name
	bool isItemAtRecordedPosition(HItem item);									// NOTE: placeholder name
	vector<HItem> &getItems();													// NOTE: placeholder name
	vector<Point> &getItemPositions();											// NOTE: placeholder name
	bool getFlag2f0();															// NOTE: placeholder name
	void setFlag2f0();															// NOTE: placeholder name
	int getEntityValue(HEntity e);												// NOTE: placeholder name
	void clearPoints7d0();														// NOTE: placeholder name
	void unknown4656d0(HEntity e);												// NOTE: placeholder name
	void addEntity(HEntity e, int value);										// NOTE: placeholder name
	void removeEntity(HEntity e);												// NOTE: placeholder name
};

void Map::unknown465200(const Point &a, const Point &b)
{
	unknown72a290(a.x, a.y, b.x, b.y);
}

bool Map::isReachable(int range, const Point &from, const Point &to)
{
	return unknown72a4d0(range, from.x, from.y, to.x, to.y);
}

void Map::unknown465270(int a, const Point &b, const Point &c, int d)
{
	unknown72a9d0(a, b.x, b.y, c.x, c.y, d);
}

void Map::unknown4652b0(int a, const Point &b, const Point &c, int d, int e)
{
	unknown72ad80(a, b.x, b.y, c.x, c.y, d, e);
}

void Map::unknown4652f0(int a, int b, int c, int d)
{
	unknown72b030(a, b, c, d);
}

void Map::addPoint6a8(const Point &p)
{
	points6a8.push_back(p);
}

void Map::resetUnknown9b4()
{
	unknown9b4 = 0;
}

void Map::addList9bc(HEntity e)
{
	list9bc.push_back(e);
}

void Map::unknown465380()
{
	unknownA04 = unknown320;
	unknownA08 = 0;
}

void Map::unknown4653b0()
{
	if (!flagA16)
		flagA15 = true;
}

void Map::setUnknownA18(int v)
{
	if (v == 2 && unknownA18 == 0)
		return;
	unknownA18 = v;
}

void Map::addBuffer(int a, int b)
{
	Point *buffer = new Point(b, a);		// NOTE: the element type is declared XBuffer*, the allocation is an 8-byte Point-like object
	XBuffer *x = (XBuffer *)buffer;
	buffers.push_back(x);
}

void Map::deleteBuffers()
{
	deleteVector(buffers);
}

void Map::raiseUnknownA70(unsigned int v)
{
	if (flagA74 && v > unknownA70)
		unknownA70 = v;
}

void Map::setFlagA74(bool v)
{
	flagA74 = v;
}

void Map::setEntityA7c(HEntity e)
{
	if (!entityA7c.operator->())
		entityA7c = e;
}

void Map::setUnknownB18(int v)
{
	unknownB18 = v;
}

void Map::addListB24(HEntity e)
{
	listB24.push_back(e);
}

bool Map::isItemAtRecordedPosition(HItem item)
{
	int i = findItemIndex(items, item);
	return i != -1 && itemPositions[i] == ((Item *)item)->getPosition();
}

vector<HItem> &Map::getItems()
{
	return items;
}

vector<Point> &Map::getItemPositions()
{
	return itemPositions;
}

bool Map::getFlag2f0()
{
	return flag2f0;
}

void Map::setFlag2f0()
{
	flag2f0 = true;
}

int Map::getEntityValue(HEntity e)
{
	int i = findEntityIndex(entities, e);
	if (i == -1)
		return 0;
	else
		return entityValues[i];
}

void Map::clearPoints7d0()
{
	points7d0.clear();
}

void Map::unknown4656d0(HEntity e)
{
	unknown9d30e0(list7b4, e);
}

void Map::addEntity(HEntity e, int value)
{
	if (unknown9d31e0(entities, e))
		return;
	entities.push_back(e);
	entityValues.push_back(value);
}

void Map::removeEntity(HEntity e)
{
	int i = findEntityIndex(entities, e);
	if (i != -1)
	{
		eraseEntityAt(entities, i);
		removeVectorElement(entityValues, i);
		e.operator->()->unknown44e360(0);
	}
}
