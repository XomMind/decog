// op_x5_misc: vector helper instances and small functions, 0x80f000-0xa044d0 (placeholder names)
// NOTE: placeholder names
#include <vector>
#include <string>
#include <algorithm>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908
extern int (*OpX5_shuffleFn)(int);	// NOTE: placeholder name (0xcaecd8)

struct MapRecord;
struct EntityData4563c0;

class HEntity
{
public:
	int ID;
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator<(const HEntity &other) const;	// NOTE: placeholder, ordering used by lower_bound
};

bool OpU8a_containsEntity(vector<HEntity> &v, HEntity e);	// 0x9d31e0
bool OpU8a_containsString(vector<string> &v, string s);	// 0x9d3fe0

struct Point
{
	int x;
	int y;
	Point();	// 0x453b40
	Point(int x_, int y_);
	Point(const Point &p);	// 0x46ca50
	bool operator==(const Point &p);	// 0x409b90
};

struct OpT8e_T9f6c50	// NOTE: placeholder name (16-byte element, a Rect in the callers)
{
	int a;
	int b;
	int c;
	int d;
};
struct OpX5_Handle
{
	int h;
	OpX5_Handle();
};

struct OpX5_Area
{
	int a;
	int b;
	int c;
	int d;
	OpX5_Area(const OpX5_Area &a);	// 0x40b130
};

struct OpX5_Elem9e3be0
{
	int pad[3];
	OpX5_Elem9e3be0(const OpX5_Elem9e3be0 &e);	// 0x9e7420
	~OpX5_Elem9e3be0();
};

template <class T> void OpX5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name

string OpX5_popRandomString(vector<string> &v)	// NOTE: placeholder name
{
	int index = rng.rangeInt(0,v.size() - 1);
	string s = v[index];
	OpX5_eraseAt(v,index);
	return s;
}

OpX5_Handle OpX5_randomRecord(vector<OpX5_Handle> &v)	// NOTE: placeholder name
{
	return v[rng.rangeInt(0,v.size() - 1)];
}

OpX5_Elem9e3be0 OpX5_randomElem(vector<OpX5_Elem9e3be0> &v)	// NOTE: placeholder name
{
	return v[rng.rangeInt(0,v.size() - 1)];
}

OpX5_Area OpX5_popRandomArea(vector<OpX5_Area> &v)	// NOTE: placeholder name
{
	int index = rng.rangeInt(0,v.size() - 1);
	OpX5_Area a = v[index];
	OpX5_eraseAt(v,index);
	return a;
}

Point OpX5_popRandomPoint(vector<Point> &v)	// NOTE: placeholder name
{
	int index = rng.rangeInt(0,v.size() - 1);
	Point p = v[index];
	OpX5_eraseAt(v,index);
	return p;
}

bool OpX5_containsRecord(vector<MapRecord*> &v, MapRecord *record)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == record)
			return true;
	}
	return false;
}

bool OpX5_addUniquePoint(vector<Point> &v, Point p)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == p)
			return false;
	}
	v.push_back(p);
	return true;
}

template <class T> void OpX5_shuffle(vector<T> &v)	// NOTE: placeholder name
{
	random_shuffle(v.begin(),v.end(),OpX5_shuffleFn);
}

bool OpX5_addUniqueEntityData(vector<EntityData4563c0*> &v, EntityData4563c0 *e)	// NOTE: placeholder name
{
	if (!OpU8a_containsEntity((vector<HEntity>&)v,*(HEntity*)&e))
	{
		v.push_back(e);
		return true;
	}
	return false;
}

void OpX5_removeAllEntity(vector<HEntity> &v, HEntity e)	// NOTE: placeholder name
{
	vector<HEntity>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it == e)
			it = v.erase(it);
		else
			++it;
	}
}

void OpX5_shufflePoints(vector<OpT8e_T9f6c50> &v)	// NOTE: placeholder name; the exe shuffles a vector of 16-byte elements (callers pass vector<Rect>)
{
	random_shuffle(v.begin(),v.end(),OpX5_shuffleFn);
}

void OpX5_shuffleBools(vector<bool> &v)	// NOTE: placeholder name
{
	random_shuffle(v.begin(),v.end(),OpX5_shuffleFn);
}

struct OpX5_Holder	// NOTE: placeholder name
{
	void eraseSortedEntity(vector<HEntity> &v, HEntity e);
};

void OpX5_Holder::eraseSortedEntity(vector<HEntity> &v, HEntity e)
{
	vector<HEntity>::iterator it = lower_bound(v.begin(),v.end(),e);
	if (it != v.end() && *it == e)
		OpX5_eraseAt(v,it - v.begin());
}

bool OpX5_addUniqueString(vector<string> &v, string s)	// NOTE: placeholder name
{
	if (!OpU8a_containsString(v,s))
	{
		v.push_back(s);
		return true;
	}
	return false;
}

void OpX5_appendUniqueStrings(vector<string> &a, vector<string> &b)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < b.size(); i++)
	{
		for (unsigned int j = 0; j < a.size(); j++)
		{
			if (a[j] == b[i])
				goto found;
		}
		a.push_back(b[i]);
found:;
	}
}

int OpX5_countString(vector<string> &v, string s)	// NOTE: placeholder name
{
	int count = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == s)
			count++;
	}
	return count;
}
