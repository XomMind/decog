// Map (the world object behind the global at 0xcefc4c): small accessors laid out at 0x463ec0-0x4642a4.
// NOTE: class layout is partial; padding members and all member/class names here are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int	x;
	int	y;

	Point(const Point &p);						// 0x46ca50
	bool operator==(const Point &p) const;		// 0x409b90
};

class Entity;

class HEntity
{
	int	ID;
public:
	HEntity();
	Entity *operator->() const;					// 0x9b6570
};

struct Marker	// NOTE: placeholder name
{
	int		pad0;
	int		pad4;
	Point	position;	// NOTE: placeholder name
};

class HMarker	// NOTE: placeholder name
{
	int	ID;
public:
	Marker *operator->() const;					// 0x9b7cd0
};

class TurnClock	// NOTE: placeholder name
{
public:
	int unknown45e590();						// NOTE: placeholder name
};

class HTurnClock	// NOTE: placeholder name
{
	int	ID;
public:
	TurnClock *operator->() const;				// 0x9b73b0
};

class Map	// NOTE: placeholder name (see src/pathing/gamedecl.h)
{
public:
	vector<vector<HMarker> > &unknown463ec0();	// NOTE: placeholder name
	bool unknown463ee0(int index, const Point &p);	// NOTE: placeholder name
	vector<int> &unknown463f60();				// NOTE: placeholder name
	bool unknown463f80();						// NOTE: placeholder name
	int unknown463fa0();						// NOTE: placeholder name
	vector<int> &unknown463fc0();				// NOTE: placeholder name
	int unknown463fe0();						// NOTE: placeholder name
	int unknown464000();						// NOTE: placeholder name
	int unknown464020();						// NOTE: placeholder name
	HEntity unknown464040();					// NOTE: placeholder name
	vector<Point> &unknown464060();				// NOTE: placeholder name
	bool unknown464080();						// NOTE: placeholder name
	vector<int> &unknown4640a0();				// NOTE: placeholder name
	int &unknown4640c0();						// NOTE: placeholder name
	int &unknown4640e0();						// NOTE: placeholder name
	bool &unknown464100();						// NOTE: placeholder name
	void unknown464120(HEntity entity);			// NOTE: placeholder name
	HEntity unknown464140();					// NOTE: placeholder name
	void unknown464160();						// NOTE: placeholder name
	bool unknown464180();						// NOTE: placeholder name
	bool unknown4641b0();						// NOTE: placeholder name
	bool unknown4641d0();						// NOTE: placeholder name
	bool unknown4641f0();						// NOTE: placeholder name
	bool unknown464210();						// NOTE: placeholder name
	bool unknown464230();						// NOTE: placeholder name
	bool unknown464250();						// NOTE: placeholder name
	int getTurn();								// NOTE: placeholder name
	int unknown464290();						// NOTE: placeholder name

	char						pad0[0x318];
	int							unknown318;
	char						pad31c[0x65c - 0x31c];
	HTurnClock					clock;			// NOTE: placeholder name
	bool						unknown660;
	char						pad661[0x7e0 - 0x661];
	vector<vector<HMarker> >	unknown7e0;
	vector<int>					unknown7f0;
	char						pad800[0x9cc - 0x800];
	int							unknown9cc;
	int							unknown9d0;
	vector<int>					unknown9d4;
	bool						unknown9e4;
	HEntity						unknown9e8;
	int							unknown9ec;		// a turn number
	char						pad9f0[0xa0d - 0x9f0];
	bool						unknownA0d;
	bool						unknownA0e;
	char						padA0f[0xa14 - 0xa0f];
	bool						unknownA14;
	bool						unknownA15;
	int							unknownA18;
	bool						unknownA1c;
	char						padA1d[0xa70 - 0xa1d];
	int							unknownA70;
	char						padA74[0xb08 - 0xa74];
	vector<int>					unknownB08;
	int							unknownB18;
	char						padB1c[0xb34 - 0xb1c];
	int							unknownB34;
	int							unknownB38;
	char						padB3c[0xba8 - 0xb3c];
	HEntity						unknownBA8;
	char						padBAC[0xbd4 - 0xbac];
	vector<Point>				unknownBD4;
	bool						unknownBE4;
};

vector<vector<HMarker> > &Map::unknown463ec0()
{
	return unknown7e0;
}

bool Map::unknown463ee0(int index, const Point &p)
{
	for (unsigned int i = 0; i < unknown7e0[index].size(); i++)
	{
		if (unknown7e0[index][i]->position == p)
			return true;
	}
	return false;
}

vector<int> &Map::unknown463f60()
{
	return unknown7f0;
}

bool Map::unknown463f80()
{
	return unknown660;
}

int Map::unknown463fa0()
{
	return unknownA70;
}

vector<int> &Map::unknown463fc0()
{
	return unknownB08;
}

int Map::unknown463fe0()
{
	return unknownB18;
}

int Map::unknown464000()
{
	return unknownB34;
}

int Map::unknown464020()
{
	return unknownB38;
}

HEntity Map::unknown464040()
{
	return unknownBA8;
}

vector<Point> &Map::unknown464060()
{
	return unknownBD4;
}

bool Map::unknown464080()
{
	return unknownBE4;
}

vector<int> &Map::unknown4640a0()
{
	return unknown9d4;
}

int &Map::unknown4640c0()
{
	return unknown9cc;
}

int &Map::unknown4640e0()
{
	return unknown9d0;
}

bool &Map::unknown464100()
{
	return unknown9e4;
}

void Map::unknown464120(HEntity entity)
{
	unknown9e8 = entity;
}

HEntity Map::unknown464140()
{
	return unknown9e8;
}

void Map::unknown464160()
{
	unknown9ec = getTurn();
}

bool Map::unknown464180()
{
	return unknown9ec == getTurn();
}

bool Map::unknown4641b0()
{
	return unknownA0d;
}

bool Map::unknown4641d0()
{
	return unknownA0e;
}

bool Map::unknown4641f0()
{
	return unknownA14;
}

bool Map::unknown464210()
{
	return unknownA15;
}

bool Map::unknown464230()
{
	return unknownA18 == 2;
}

bool Map::unknown464250()
{
	return unknownA1c;
}

int Map::getTurn()
{
	return clock->unknown45e590();
}

int Map::unknown464290()
{
	return unknown318;
}
