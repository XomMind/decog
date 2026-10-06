// Map (the world object behind the global at 0xcefc4c): header-inline accessors 0x462e30-0x4635b2.
// NOTE: class layout is partial; padding members, member names and most method names are placeholders.
//	Matched code calls some of these accessors through the names Map and BS (both placeholders for
//	the same object), so BS is declared here as a thin alias class on top of Map.
#include <string>
#include <vector>

using namespace std;

struct Point
{
	int	x;
	int	y;

	bool operator==(const Point &p) const;		// 0x409b90
};

class Entity;

class HEntity
{
	int	ID;
public:
	bool operator==(HEntity other) const;		// 0x9b78e0
	Entity *operator->() const;					// 0x9b6570
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
	void clear();								// NOTE: placeholder name (0x9d23e0)
};

class Entity
{
public:
	int getSize();								// 0x45a360
	const Point &getPosition();					// 0x45a4a0
	bool unknown45a5a0(Array2D<int> &grid, int value);	// NOTE: placeholder name
	bool unknown45a600(Array2D<int> &grid, int value, const Point &p);	// NOTE: placeholder name
	bool unknown45a680(Array2D<int> &grid);		// NOTE: placeholder name
};

class Group	// NOTE: placeholder name
{
public:
	vector<HEntity> &getMembers();				// NOTE: placeholder name (0x416f40)

	char			pad0[0xc];
	vector<HEntity>	members;					// NOTE: placeholder name
};

class HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	Group *operator->() const;					// 0x9b7250
};

struct MapZone	// NOTE: placeholder name (an exit/access point; see EntityAI::addEarlyExiter)
{
	Point	position;	// NOTE: placeholder name
	int		machine;	// NOTE: placeholder name
	char	pad0c[8];
	HEntity	entity14;	// NOTE: placeholder name
	HEntity	entity18;	// NOTE: placeholder name
};

struct FovMap	// NOTE: placeholder name
{
	Array2D<int>	grid;	// NOTE: placeholder name
	int				stamp;	// NOTE: placeholder name; a cell is "in" when grid(x,y) == stamp
};

template <class T> bool inVector(vector<T> &v, T e);	// NOTE: placeholder name (0x9d31e0 for HEntity)
int findEntityIndex(vector<HEntity> &v, HEntity e);		// 0x9d3110

class Map	// NOTE: placeholder name (see src/pathing/gamedecl.h)
{
public:
	MapZone *getZone(const Point &p);			// NOTE: placeholder name
	bool unknown462ea0(const Point &p);			// NOTE: placeholder name
	bool unknown462f00(HEntity e);				// NOTE: placeholder name
	MapZone *unknown462f60(HEntity e);			// NOTE: placeholder name
	MapZone *unknown462fd0(HEntity e);			// NOTE: placeholder name
	bool unknown463040();						// NOTE: placeholder name
	string unknown463060(const Point &p);		// NOTE: placeholder name
	int unknown4630a0();						// NOTE: placeholder name
	HEntity getPlayer();						// NOTE: placeholder name
	bool isKnown(int x, int y);					// NOTE: placeholder name
	bool unknown463160(const Point &p);			// NOTE: placeholder name
	bool isVisible(int x, int y);				// NOTE: placeholder name
	bool unknown463260();						// NOTE: placeholder name
	bool unknown463280();						// NOTE: placeholder name
	bool unknown4632a0();						// NOTE: placeholder name
	bool unknown4632c0();						// NOTE: placeholder name
	bool unknown4632e0();						// NOTE: placeholder name
	bool unknown463380(int x, int y);			// NOTE: placeholder name
	bool unknown4633c0(const Point &p);			// NOTE: placeholder name
	bool unknown463400(HEntity e);				// NOTE: placeholder name
	bool unknown463490(HEntity e, const Point &p);	// NOTE: placeholder name
	bool unknown463510(HEntity e);				// NOTE: placeholder name
	int unknown463540(HEntity e);				// NOTE: placeholder name
	vector<HEntity> &unknown4635a0();			// NOTE: placeholder name

	string unknown7146d0(int x, int y);			// NOTE: placeholder name; region name ("northwestern" etc.)

	char				pad0[0x10];
	vector<MapZone *>	zones;					// NOTE: placeholder name
	char				pad20[0x30 - 0x20];
	bool				flag30;					// NOTE: placeholder name
	char				pad31[0x38 - 0x31];
	Array2D<int>		grid38;					// NOTE: placeholder name
	int					stamp44;				// NOTE: placeholder name
	char				pad48[0x4c - 0x48];
	vector<HGroup>		groups;					// NOTE: placeholder name
	char				pad5c[0x66c - 0x5c];
	HEntity				player;					// NOTE: placeholder name
	HEntity				entity670;				// NOTE: placeholder name
	Array2D<bool>		known;					// NOTE: placeholder name
	char				pad680[0x69c - 0x680];
	Array2D<int>		visible;				// NOTE: placeholder name
	char				pad6a8[0x6b8 - 0x6a8];
	vector<HEntity>		list6b8;				// NOTE: placeholder name
	vector<HEntity>		list6c8;				// NOTE: placeholder name
	char				pad6d8[0x6e8 - 0x6d8];
	FovMap				*fov;					// NOTE: placeholder name
	char				pad6ec[0x750 - 0x6ec];
	bool				flag750;				// NOTE: placeholder name
	bool				flag751;				// NOTE: placeholder name
	bool				flag752;				// NOTE: placeholder name
	bool				flag753;				// NOTE: placeholder name
	vector<int>			list754;				// NOTE: placeholder name
	vector<int>			list764;				// NOTE: placeholder name
	vector<int>			list774;				// NOTE: placeholder name
	vector<int>			list784;				// NOTE: placeholder name
	vector<int>			list794;				// NOTE: placeholder name
	vector<int>			list7a4;				// NOTE: placeholder name
};

class BS : public Map	// NOTE: placeholder name, same object as Map
{
public:
	HEntity getEntity671();						// NOTE: placeholder name
	bool isVisible(const Point &p);				// NOTE: placeholder name
	bool unknown4631f0(HEntity e);				// NOTE: placeholder name
};

template <>
bool &Array2D<bool>::operator()(const Point &p)
{
	return data[p.x * height + p.y];
}

MapZone *Map::getZone(const Point &p)
{
	for (unsigned int i = 0; i < zones.size(); i++)
	{
		if (zones[i]->position == p)
			return zones[i];
	}
	return NULL;
}

bool Map::unknown462ea0(const Point &p)
{
	for (unsigned int i = 0; i < zones.size(); i++)
	{
		if (zones[i]->position == p)
			return true;
	}
	return false;
}

bool Map::unknown462f00(HEntity e)
{
	for (unsigned int i = 0; i < zones.size(); i++)
	{
		if (zones[i]->entity14 == e)
			return true;
	}
	return false;
}

MapZone *Map::unknown462f60(HEntity e)
{
	for (unsigned int i = 0; i < zones.size(); i++)
	{
		if (zones[i]->entity14 == e)
			return zones[i];
	}
	return NULL;
}

MapZone *Map::unknown462fd0(HEntity e)
{
	for (unsigned int i = 0; i < zones.size(); i++)
	{
		if (zones[i]->entity18 == e)
			return zones[i];
	}
	return NULL;
}

bool Map::unknown463040()
{
	return flag30;
}

string Map::unknown463060(const Point &p)
{
	return unknown7146d0(p.x,p.y);
}

int Map::unknown4630a0()
{
	stamp44++;
	if (stamp44 > 10000)
	{
		grid38.clear();
		stamp44 = 1;
	}
	return stamp44;
}

HEntity Map::getPlayer()
{
	return player;
}

HEntity BS::getEntity671()
{
	return entity670;
}

bool Map::isKnown(int x, int y)
{
	return known(x,y);
}

bool Map::unknown463160(const Point &p)
{
	return known(p);
}

bool Map::isVisible(int x, int y)
{
	return visible(x,y);
}

bool BS::isVisible(const Point &p)
{
	return visible(p);
}

bool BS::unknown4631f0(HEntity e)
{
	return e->getSize() == 1 ? visible(e->getPosition()) : e->unknown45a680(visible);
}

bool Map::unknown463260()
{
	return flag750;
}

bool Map::unknown463280()
{
	return flag751;
}

bool Map::unknown4632a0()
{
	return flag752;
}

bool Map::unknown4632c0()
{
	return flag753;
}

bool Map::unknown4632e0()
{
	return !list754.empty() || !list774.empty() || !list784.empty() || !list764.empty() || !list794.empty() || !list7a4.empty();
}

bool Map::unknown463380(int x, int y)
{
	return fov->grid(x,y) == fov->stamp;
}

bool Map::unknown4633c0(const Point &p)
{
	return fov->grid(p) == fov->stamp;
}

bool Map::unknown463400(HEntity e)
{
	return e->getSize() == 1 ? fov->grid(e->getPosition()) == fov->stamp : e->unknown45a5a0(fov->grid,fov->stamp);
}

bool Map::unknown463490(HEntity e, const Point &p)
{
	return e->getSize() == 1 ? fov->grid(p) == fov->stamp : e->unknown45a600(fov->grid,fov->stamp,p);
}

bool Map::unknown463510(HEntity e)
{
	return inVector(list6b8,e);
}

int Map::unknown463540(HEntity e)
{
	int index = findEntityIndex(list6b8,e);
	if (index != -1)
		index += groups[0]->getMembers().size();
	return index;
}

vector<HEntity> &Map::unknown4635a0()
{
	return list6b8;
}
