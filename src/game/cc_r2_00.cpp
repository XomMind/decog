// Entity: header-inline accessors and destructor (0x45a0b0-0x45a805).
// NOTE: class layouts are partial; padding members, member names and most method names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;

	Point(const Point &p);								// 0x46ca50
	Point(const Point &p, int dx, int dy);				// 0x4099c0
	Point(const Point &a, const Point &b);				// 0x4099f0 (sum)
	bool operator==(const Point &p) const;				// 0x409b90
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(int x, int y);
	T &operator()(const Point &p);
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
};

class HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	HGroup();
};

class HExplosive	// NOTE: placeholder layout
{
	int	ID;
public:
	HExplosive();
};

int maxInt(int a, int b);	// 0x9cdb60
int minInt(int a, int b);	// 0x9cdb30

template <class T> bool inVector(vector<T> &v, T e);	// NOTE: placeholder name (0x9d0ce0)
template <class T> void deleteVector(vector<T*> &v);	// NOTE: placeholder name (0x9d0670 for this instance)

struct EntityRecord	// NOTE: placeholder
{
	int		ID;
	string	name;
	char	pad20[0x24 - 4 - sizeof(string)];
	int		aiType;				// NOTE: placeholder name
	int		faction;			// NOTE: placeholder name
	char	pad2c[0x94 - 0x2c];
	int		unknown94;			// NOTE: placeholder name
	int		unknown98;			// NOTE: placeholder name
	int		size;				// NOTE: placeholder name
	int		caveWall;			// NOTE: placeholder name
	char	padA4[0x224 - 0xa4];
	int		unknown224;			// NOTE: placeholder name
};

struct EntityData4563c0;	// NOTE: placeholder name, element type of the owned pointer vectors

class EntityPart4563c0	// NOTE: placeholder name (dtor 0x4563c0)
{
public:
	~EntityPart4563c0();
};

class EntityPart4588f0	// NOTE: placeholder name (dtor 0x4588f0)
{
public:
	~EntityPart4588f0();
};

class EntityAI
{
public:
	~EntityAI();	// 0x580900
};

class Entity
{
public:
	~Entity();
	HEntity unknown45a260();						// NOTE: placeholder name
	const string &getName();						// NOTE: placeholder name
	int getAiType();								// NOTE: placeholder name
	int getFaction();								// NOTE: placeholder name
	int unknown45a2e0(const Point &offset);			// NOTE: placeholder name
	int unknown45a320();							// NOTE: placeholder name
	int unknown45a340();							// NOTE: placeholder name
	int getSize();									// NOTE: placeholder name
	bool canEnterCaveWall();						// NOTE: placeholder name
	int unknown45a3a0();							// NOTE: placeholder name
	int unknown45a3c0();							// NOTE: placeholder name
	HGroup getGroup();								// NOTE: placeholder name
	string unknown45a410() const;					// NOTE: placeholder name
	const Point &getPosition();						// NOTE: placeholder name
	Point unknown45a4c0();							// NOTE: placeholder name
	bool unknown45a510(const Point &p);				// NOTE: placeholder name
	int unknown45a540(const Point &p);				// NOTE: placeholder name
	bool unknown45a5a0(Array2D<int> &map, int value);	// NOTE: placeholder name
	bool unknown45a600(Array2D<int> &map, int value, const Point &p);	// NOTE: placeholder name
	bool unknown45a680(Array2D<int> &map);			// NOTE: placeholder name
	int unknown45a700();							// NOTE: placeholder name
	float unknown45a720();							// NOTE: placeholder name
	vector<EntityData4563c0 *> &unknown45a740();	// NOTE: placeholder name
	int getTarget();								// NOTE: placeholder name
	bool unknown45a780();							// NOTE: placeholder name
	int unknown45a7b0();							// NOTE: placeholder name
	int unknown45a7e0();							// NOTE: placeholder name

	int getAscii(const Point &p);					// 0x5c7a10
	int unknown5c8cb0();							// NOTE: placeholder name
	int unknown5c8d40(int a, int b);				// NOTE: placeholder name
	int unknown5d1ee0();							// NOTE: placeholder name
	int unknown5d22a0(int type);					// NOTE: placeholder name

	int							unknown00;		// NOTE: placeholder name
	HEntity						self;			// NOTE: placeholder name
	EntityRecord				*record;
	string						name;			// NOTE: placeholder name
	HGroup						group;			// NOTE: placeholder name
	int							unknown2c;		// NOTE: placeholder name
	vector<Point>				footprint;		// NOTE: placeholder name
	int							unknown40;		// NOTE: placeholder name
	char						pad44[0x50 - 0x44];
	int							unknown50;		// NOTE: placeholder name
	char						pad54[0x5c - 0x54];
	float						unknown5c;		// NOTE: placeholder name
	vector<EntityData4563c0 *>	unknown60;		// NOTE: placeholder name
	int							target;			// NOTE: placeholder name
	char						pad74[0x9c - 0x74];
	vector<int>					unknown9c;		// NOTE: placeholder name
	char						padAC[0xdc - 0xac];
	vector<EntityData4563c0 *>	unknownDC;		// NOTE: placeholder name
	EntityPart4563c0			*unknownEC;		// NOTE: placeholder name
	EntityPart4588f0			*unknownF0;		// NOTE: placeholder name
	vector<EntityData4563c0 *>	unknownF4;		// NOTE: placeholder name
	vector<EntityData4563c0 *>	unknown104;		// NOTE: placeholder name
	char						pad114[0x124 - 0x114];
	vector<int>					unknown124;		// NOTE: placeholder name
	vector<HExplosive>			unknown134;		// NOTE: placeholder name
	EntityAI					*ai;			// NOTE: placeholder name
};

Entity::~Entity()
{
	deleteVector(unknown60);
	deleteVector(unknownDC);
	delete unknownEC;
	delete unknownF0;
	deleteVector(unknownF4);
	deleteVector(unknown104);
	delete ai;
}

HEntity Entity::unknown45a260()
{
	return self;
}

const string &Entity::getName()
{
	return record->name;
}

int Entity::getAiType()
{
	return record->aiType;
}

int Entity::getFaction()
{
	return record->faction;
}

int Entity::unknown45a2e0(const Point &offset)
{
	return getAscii(Point(footprint[0],offset));
}

int Entity::unknown45a320()
{
	return record->unknown94;
}

int Entity::unknown45a340()
{
	return record->unknown98;
}

int Entity::getSize()
{
	return record->size;
}

bool Entity::canEnterCaveWall()
{
	return record->caveWall;
}

int Entity::unknown45a3a0()
{
	return record->caveWall;
}

int Entity::unknown45a3c0()
{
	return maxInt(record->unknown224,unknown5d22a0(16));
}

HGroup Entity::getGroup()
{
	return group;
}

string Entity::unknown45a410() const
{
	return string(name.begin(),name[1] == '-' ? name.begin() + 4 : name.end());
}

const Point &Entity::getPosition()
{
	return footprint[0];
}

Point Entity::unknown45a4c0()
{
	return Point(footprint[0],(record->size - 1) / 2,(record->size - 1) / 2);
}

bool Entity::unknown45a510(const Point &p)
{
	return inVector(footprint,p);
}

int Entity::unknown45a540(const Point &p)
{
	for (unsigned int i = 0; i < footprint.size(); i++)
	{
		if (footprint[i] == p)
			return i;
	}
	return 0;
}

bool Entity::unknown45a5a0(Array2D<int> &map, int value)
{
	for (unsigned int i = 0; i < footprint.size(); i++)
	{
		if (map(footprint[i]) == value)
			return true;
	}
	return false;
}

bool Entity::unknown45a600(Array2D<int> &map, int value, const Point &p)
{
	for (int y = p.y; y < record->size; y++)
	{
		for (int x = p.x; x < record->size; x++)
		{
			if (map(x,y) == value)
				return true;
		}
	}
	return false;
}

bool Entity::unknown45a680(Array2D<int> &map)
{
	for (unsigned int i = 0; i < footprint.size(); i++)
	{
		if (map(footprint[i]))
			return true;
	}
	return false;
}

int Entity::unknown45a700()
{
	return minInt(unknown50,3);
}

float Entity::unknown45a720()
{
	return unknown5c;
}

vector<EntityData4563c0 *> &Entity::unknown45a740()
{
	return unknown60;
}

int Entity::getTarget()
{
	return target;
}

bool Entity::unknown45a780()
{
	return unknown5c8cb0() > unknown5d1ee0();
}

int Entity::unknown45a7b0()
{
	return unknown5c8cb0() - unknown5d1ee0();
}

int Entity::unknown45a7e0()
{
	return unknown5c8d40(unknown5c8cb0(),unknown5d1ee0());
}
