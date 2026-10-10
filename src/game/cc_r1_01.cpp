// BS (the game world object behind the global at 0xcefc4c): header-inline accessors 0x463ab0-0x463ebf.
// NOTE: class layout is partial; padding members, member names and method names are placeholders.
#include <vector>

using namespace std;

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
	Point(const Point &p);	// 0x46ca50
};

class HEntity	// NOTE: placeholder layout
{
	int ID;
public:
	bool isValid() const;
};

class HProp	// NOTE: placeholder layout
{
	int ID;
public:
	HProp();
	bool isValid() const;
};

template <class T> bool inVector(vector<T> &v, T e);	// NOTE: placeholder name (0x9d0ce0)
bool eraseValue(vector<HEntity> &v, HEntity value);				// NOTE: placeholder name (0x9d2f00)

class UnknownList6c2110	// NOTE: placeholder name (0x24 bytes, created on demand by BS)
{
public:
	UnknownList6c2110() throw();	// 0x6c2110

	vector<int> entries;	// NOTE: placeholder name
	char pad10[0x24 - 0x10];
};

struct Unknown7c4	// NOTE: placeholder name
{
	int pad[3];
};

class BS
{
public:
	vector<int> &unknown463ab0();				// NOTE: placeholder name
	vector<int> &unknown463ad0();				// NOTE: placeholder name
	vector<int> &unknown463af0();				// NOTE: placeholder name
	bool unknown463b10();						// NOTE: placeholder name
	vector<int> &unknown463b30();				// NOTE: placeholder name
	bool unknown463b50(Point p);				// NOTE: placeholder name
	void unknown463b80(Point p);				// NOTE: placeholder name
	int getDisabledGarrisonAccesses();						// NOTE: placeholder name
	vector<int> &unknown463bc0();				// NOTE: placeholder name
	vector<vector<HProp> > &unknown463be0();	// NOTE: placeholder name
	vector<HProp> &unknown463c00(int index);	// NOTE: placeholder name
	vector<int> &unknown463c20();				// NOTE: placeholder name
	UnknownList6c2110 *unknown463c40();			// NOTE: placeholder name
	int unknown463ca0();						// NOTE: placeholder name
	vector<int> &unknown463ce0();				// NOTE: placeholder name
	vector<int> &unknown463d00();				// NOTE: placeholder name
	int unknown463d20();						// NOTE: placeholder name
	int unknown463d40();						// NOTE: placeholder name
	vector<int> &unknown463d60();				// NOTE: placeholder name
	vector<HEntity> &getFollowers();			// entities with effect 0x39 (capped at 8 by callers)
	void addFollower(HEntity e);
	void removeFollower(HEntity e);
	vector<int> &unknown463df0();				// NOTE: placeholder name
	HEntity unknown463e10();					// NOTE: placeholder name
	int unknown463e30();						// NOTE: placeholder name
	int unknown463e50();						// NOTE: placeholder name
	Unknown7c4 &unknown463e70();				// NOTE: placeholder name
	bool unknown463e90(const Point &p);			// NOTE: placeholder name

	char pad0[0x148];
	vector<int> list148;				// NOTE: placeholder name
	vector<int> list158;				// NOTE: placeholder name
	vector<int> list168;				// NOTE: placeholder name
	char pad178[0x204 - 0x178];
	bool flag204;						// NOTE: placeholder name
	vector<int> list208;				// NOTE: placeholder name
	char pad218[0x220 - 0x218];
	vector<Point> points220;			// NOTE: placeholder name
	int disabledGarrisonAccesses;						// NOTE: placeholder name
	char pad234[0x258 - 0x234];
	vector<int> list258;				// NOTE: placeholder name
	vector<vector<HProp> > zoneProps;	// NOTE: placeholder name
	char pad278[0x2ac - 0x278];
	UnknownList6c2110 *list2ac;			// NOTE: placeholder name
	vector<int> list2b0;				// NOTE: placeholder name
	vector<int> list2c0;				// NOTE: placeholder name
	char pad2d0[0x524 - 0x2d0];
	vector<int> list524;				// NOTE: placeholder name
	int value534;						// NOTE: placeholder name
	char pad538[0x570 - 0x538];
	int value570;						// NOTE: placeholder name
	vector<int> list574;				// NOTE: placeholder name
	char pad584[0x5ec - 0x584];
	vector<HEntity> followers;					// +0x5ec: pushed through the HEntity-family push_back (0x9b80b0), removed with 0x9d2f00
	char pad5fc[0x604 - 0x5fc];
	vector<int> list604;				// NOTE: placeholder name
	char pad614[0x618 - 0x614];
	HEntity entity618;					// NOTE: placeholder name
	char pad61c[0x640 - 0x61c];
	int value640;						// NOTE: placeholder name
	char pad644[0x658 - 0x644];
	int value658;						// NOTE: placeholder name
	char pad65c[0x7c4 - 0x65c];
	Unknown7c4 data7c4;					// NOTE: placeholder name
	vector<Point> points7d0;			// NOTE: placeholder name
};

vector<int> &BS::unknown463ab0()
{
	return list148;
}

vector<int> &BS::unknown463ad0()
{
	return list158;
}

vector<int> &BS::unknown463af0()
{
	return list168;
}

bool BS::unknown463b10()
{
	return flag204;
}

vector<int> &BS::unknown463b30()
{
	return list208;
}

bool BS::unknown463b50(Point p)
{
	return inVector(points220,p);
}

void BS::unknown463b80(Point p)
{
	points220.push_back(p);
}

int BS::getDisabledGarrisonAccesses()
{
	return disabledGarrisonAccesses;
}

vector<int> &BS::unknown463bc0()
{
	return list258;
}

vector<vector<HProp> > &BS::unknown463be0()
{
	return zoneProps;
}

vector<HProp> &BS::unknown463c00(int index)
{
	return zoneProps[index];
}

vector<int> &BS::unknown463c20()
{
	return list2c0;
}

UnknownList6c2110 *BS::unknown463c40()
{
	if (list2ac == NULL)
	{
		UnknownList6c2110 *list = new UnknownList6c2110();
		list2ac = list;
	}
	return list2ac;
}

int BS::unknown463ca0()
{
	return list2ac ? list2ac->entries.size() : 0;
}

vector<int> &BS::unknown463ce0()
{
	return list2b0;
}

vector<int> &BS::unknown463d00()
{
	return list524;
}

int BS::unknown463d20()
{
	return value534;
}

int BS::unknown463d40()
{
	return value570;
}

vector<int> &BS::unknown463d60()
{
	return list574;
}

vector<HEntity> &BS::getFollowers()
{
	return followers;
}

void BS::addFollower(HEntity e)
{
	followers.push_back(e);
}

void BS::removeFollower(HEntity e)
{
	eraseValue(followers,e);
}

vector<int> &BS::unknown463df0()
{
	return list604;
}

HEntity BS::unknown463e10()
{
	return entity618;
}

int BS::unknown463e30()
{
	return value640;
}

int BS::unknown463e50()
{
	return value658;
}

Unknown7c4 &BS::unknown463e70()
{
	return data7c4;
}

bool BS::unknown463e90(const Point &p)
{
	return inVector(points7d0,p);
}
