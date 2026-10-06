// World/map group-relation helpers matched against COGMIND.exe (Beta 17.1).
// NOTE: class layout is partial; padding members and all names except those learned elsewhere are placeholders.
#include <vector>
using namespace std;

class Entity;
class Group;
class HGroup;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	Entity *operator->() const;	// 0x9b6570
};

class HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	Group *operator->() const;	// 0x9b7250
};

class Entity
{
public:
	HGroup getGroup();	// 0x45a3f0
};

class Group	// NOTE: placeholder name
{
public:
	int unknown45e1a0(HEntity e);	// NOTE: placeholder name (index of member)
	vector<HEntity> *unknown416f40();	// NOTE: placeholder name (member list)
	int unknown9b8f00();			// NOTE: placeholder name (ICF'd trivial getter)
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;
public:
	T	unknownC;	// NOTE: placeholder name
	T &operator()(int x, int y);	// 0x9ceda0
};

int findEntityIndex(vector<HEntity> &v, HEntity e);		// 0x9d3110
void unknown9d31e0(vector<HEntity> &v, HEntity e);		// NOTE: placeholder name

struct MapObjA	// NOTE: placeholder name
{
	char	pad[0xc];
	int		unknownC;	// NOTE: placeholder name
	char	pad10[0x18 - 0x10];
	int		unknown18;	// NOTE: placeholder name
};

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	void unknown4635c0(HEntity e);							// NOTE: placeholder name
	int unknown4635f0(HEntity e);							// NOTE: placeholder name
	bool unknown463660();									// NOTE: placeholder name
	int unknown463690();									// NOTE: placeholder name
	vector<int *> *unknown4636b0();							// NOTE: placeholder name
	unsigned int unknown4636d0();							// NOTE: placeholder name
	vector<int *> *unknown4636f0();							// NOTE: placeholder name
	unsigned int unknown463710();							// NOTE: placeholder name
	int *unknown463730();									// NOTE: placeholder name
	bool unknown463750();									// NOTE: placeholder name
	void unknown463770(bool value);							// NOTE: placeholder name
	bool unknown463790(HEntity e, int x, int y);			// NOTE: placeholder name
	int *unknown4637f0();									// NOTE: placeholder name
	Array2D<bool> &getMimicGrid();							// 0x463810
	int *unknown463830();									// NOTE: placeholder name
	MapObjA *unknown463850();								// NOTE: placeholder name
	int unknown463870();									// NOTE: placeholder name
	HGroup unknown463890(int i);							// NOTE: placeholder name
	Array2D<int> *unknown4638c0();							// NOTE: placeholder name
	int unknown4638e0(int a, int b);						// NOTE: placeholder name
	int unknown463910(HGroup a, HGroup b);					// NOTE: placeholder name
	vector<HGroup> *unknown463950();						// NOTE: placeholder name
	void unknown463970(HEntity e, vector<vector<HEntity> *> *out);	// NOTE: placeholder name
	int *unknown463a10();									// NOTE: placeholder name
	int *unknown463a30();									// NOTE: placeholder name
	int &unknown463a50(unsigned int i);						// NOTE: placeholder name
	int *unknown463a70();									// NOTE: placeholder name
	int *unknown463a90();									// NOTE: placeholder name

	char				pad00[0x4c];
	vector<HGroup>		groups;							// NOTE: placeholder name
	Array2D<int>		groupRelations;					// NOTE: placeholder name
	char				pad6c[0x8c - 0x6c];
	int					unknown8c;						// NOTE: placeholder name
	char				pad90[0xe4 - 0x90];
	vector<int>			unknownE4;						// NOTE: placeholder name
	int					unknownF4;						// NOTE: placeholder name
	char				padf8[0x128 - 0xf8];
	int					unknown128;						// NOTE: placeholder name
	char				pad12c[0x674 - 0x12c];
	int					unknown674;						// NOTE: placeholder name
	char				pad678[0x680 - 0x678];
	Array2D<bool>		mimicGrid;						// NOTE: placeholder name
	char				pad690[0x69c - 0x690];
	int					unknown69c;						// NOTE: placeholder name
	char				pad6a0[0x6a8 - 0x6a0];
	vector<int>			unknown6a8;						// NOTE: placeholder name
	vector<int *>		unknown6b8;						// NOTE: placeholder name
	vector<HEntity>		entities;						// NOTE: placeholder name (+0x6c8)
	vector<Array2D<int> *>	unknown6d8;					// NOTE: placeholder name
	MapObjA				*unknown6e8;					// NOTE: placeholder name
	vector<int *>		unknown6ec;						// NOTE: placeholder name
	vector<int *>		unknown6fc;						// NOTE: placeholder name
	bool				unknown70c;						// NOTE: placeholder name
	char				pad70d[0x764 - 0x70d];
	int					unknown764;						// NOTE: placeholder name
};

void Map::unknown4635c0(HEntity e)
{
	unknown9d31e0(entities,e);
}

int Map::unknown4635f0(HEntity e)
{
	int index = findEntityIndex(entities,e);
	if (index != -1)
		index += groups[0]->unknown416f40()->size() + unknown6b8.size();
	return index;
}

bool Map::unknown463660()
{
	return !unknown6a8.empty();
}

int Map::unknown463690()
{
	return unknown6e8->unknown18;
}

vector<int *> *Map::unknown4636b0()
{
	return &unknown6ec;
}

unsigned int Map::unknown4636d0()
{
	return unknown6ec.size();
}

vector<int *> *Map::unknown4636f0()
{
	return &unknown6fc;
}

unsigned int Map::unknown463710()
{
	return unknown6fc.size();
}

int *Map::unknown463730()
{
	return &unknown764;
}

bool Map::unknown463750()
{
	return unknown70c;
}

void Map::unknown463770(bool value)
{
	unknown70c = value;
}

bool Map::unknown463790(HEntity e, int x, int y)
{
	Array2D<int> *grid = unknown6d8[groups[0]->unknown45e1a0(e)];
	return (*grid)(x,y) == grid->unknownC;
}

int *Map::unknown4637f0()
{
	return &unknown674;
}

Array2D<bool> &Map::getMimicGrid()
{
	return mimicGrid;
}

int *Map::unknown463830()
{
	return &unknown69c;
}

MapObjA *Map::unknown463850()
{
	return unknown6e8;
}

int Map::unknown463870()
{
	return unknown6e8->unknownC;
}

HGroup Map::unknown463890(int i)
{
	return groups[i];
}

Array2D<int> *Map::unknown4638c0()
{
	return &groupRelations;
}

int Map::unknown4638e0(int a, int b)
{
	return groupRelations(a,b);
}

int Map::unknown463910(HGroup a, HGroup b)
{
	return groupRelations(a->unknown9b8f00(),b->unknown9b8f00());
}

vector<HGroup> *Map::unknown463950()
{
	return &groups;
}

void Map::unknown463970(HEntity e, vector<vector<HEntity> *> *out)
{
	for (unsigned int i = 0; i < groups.size(); i++)
	{
		if (!unknown463910(e->getGroup(),groups[i]))
			out->push_back(groups[i]->unknown416f40());
	}
}

int *Map::unknown463a10()
{
	return &groupRelations.unknownC;
}

int *Map::unknown463a30()
{
	return &unknown8c;
}

int &Map::unknown463a50(unsigned int i)
{
	return unknownE4[i];
}

int *Map::unknown463a70()
{
	return &unknownF4;
}

int *Map::unknown463a90()
{
	return &unknown128;
}
