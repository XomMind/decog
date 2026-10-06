// Map (the world object behind the global at 0xcefc4c): header-inline accessors 0x4649e0-0x464b8d.
//	The neighbouring accessors 0x4642b0-0x464a74 are in cc_r1_02 (same class, same layout).
// NOTE: class layout is partial; padding members, member names and method names are placeholders.
//	The exe lays these out in declaration order (LTCG), so the method order below follows the exe.
#include <vector>
using namespace std;

class HEntity
{
	int	ID;
public:
	HEntity();
};

class HItem
{
	int	ID;
public:
	HItem();
};

struct MapRecord	// NOTE: placeholder name; element of the vector at 0x1dc (12 bytes, ctor 0x455da0)
{
	int		unknown0;
	HEntity	entity;		// NOTE: placeholder name
	int		value;		// NOTE: placeholder name
};

template <class T> bool addUnique(vector<T> &v, T e);					// NOTE: placeholder name (0x9d3020 for Point)
template <class T> void removeVectorElement(vector<T> &v, int index);	// NOTE: placeholder name (0x9de6f0 for int)
int findItemIndex(vector<HItem> &v, HItem item);						// NOTE: placeholder name (0x9d3110)
void eraseItemAt(vector<HItem> &v, int index);							// NOTE: placeholder name (0x9da940)

class Map	// NOTE: placeholder name
{
public:
	void unknown4649e0(MapRecord *record);			// NOTE: placeholder name
	void unknown464a80(HEntity entity);				// NOTE: placeholder name
	void unknown464ab0();							// NOTE: placeholder name
	void unknown464ad0();							// NOTE: placeholder name
	void unknown464af0(HItem item, int amount);		// NOTE: placeholder name
	void unknown464b40(int index);					// NOTE: placeholder name

	char					pad000[0x1dc];
	vector<MapRecord *>		unknown1dc;				// NOTE: placeholder name
	char					pad1ec[0x278 - 0x1ec];
	vector<HEntity>			unknown278;				// NOTE: placeholder name
	char					pad288[0x32c - 0x288];
	bool					unknown32c;				// NOTE: placeholder name
	bool					unknown32d;				// NOTE: placeholder name
	char					pad32e[0x340 - 0x32e];
	vector<HItem>			items340;				// NOTE: placeholder name
	vector<int>				values350;				// NOTE: placeholder name; parallel to items340
	vector<int>				values360;				// NOTE: placeholder name; parallel to items340
};

void Map::unknown4649e0(MapRecord *record)
{
	unknown1dc.push_back(record);
}

void Map::unknown464a80(HEntity entity)
{
	addUnique(unknown278,entity);
}

void Map::unknown464ab0()
{
	unknown32c = true;
}

void Map::unknown464ad0()
{
	unknown32d = true;
}

void Map::unknown464af0(HItem item, int amount)
{
	int index = findItemIndex(items340,item);
	if (index != -1)
		values360[index] += amount;
}

void Map::unknown464b40(int index)
{
	eraseItemAt(items340,index);
	removeVectorElement(values350,index);
	removeVectorElement(values360,index);
}
