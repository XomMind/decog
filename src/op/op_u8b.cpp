// op_u8b: game helper functions 0x9d8000-0x9ee000 (vector/serialization helpers, placeholder names)
// NOTE: placeholder names
#include <vector>
#include <string>
#include <algorithm>
#include <istream>
#include <ostream>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908
extern int (*OpS8c_shuffleFn)(int);	// NOTE: placeholder name (0xcaecd8)

struct Point
{
	int x;
	int y;
	Point();	// 0x453b40
	Point(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// 0x40a6e0
	Rect(const Rect &rect);	// 0x40a720
};

struct OpU8b_Handle
{
	int h;
	OpU8b_Handle();
};

struct OpU8b_Plain
{
	int pad[3];
};

struct OpU8b_Named
{
	char pad[0x24];
	string name;
};

struct OpU8b_Area	// NOTE: placeholder name
{
	char pad[16];
	OpU8b_Area(const OpU8b_Area &a);	// 0x40b130
};

class HProp
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
	void save(ostream &stream);	// NOTE: placeholder name (0x9cfa90)
	void load(istream &stream);	// NOTE: placeholder name (0x9cfaf0)
};

struct OpU8b_Range	// NOTE: placeholder name
{
	OpU8b_Range();	// 0x45f020
	void read(istream &stream);	// 0x45f040

	int	min;
	int	max;
};

struct OpR1g_Triple	// NOTE: placeholder name
{
	OpR1g_Triple() throw();	// 0x46cb90
	~OpR1g_Triple();	// 0x9b7080
	OpR1g_Triple(const OpR1g_Triple &other);
	void read(istream &stream);	// NOTE: placeholder name

	vector<int>	xs;
	vector<int>	ys;
	vector<int>	zs;
};

template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name
void OpT8a_eraseAt(vector<int> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0)
bool OpU8a_containsString(vector<string> &v, string s);	// NOTE: placeholder name (0x9d3fe0)

template <class T> void OpU8b_insertAt(vector<T> &v, int index, T value)	// NOTE: placeholder name
{
	if (index == v.size())
		v.push_back(value);
	else
		v.insert(v.begin()+index,value);
}

template <class T> void OpU8b_shuffle(vector<T> &v)	// NOTE: placeholder name
{
	random_shuffle(v.begin(),v.end(),OpS8c_shuffleFn);
}

void OpU8b_insertPtrAt(vector<OpU8b_Plain*> &v, int index, OpU8b_Plain *value)	// NOTE: placeholder name
{
	if (index == v.size())
		v.push_back(value);
	else
		v.insert(v.begin()+index,value);
}

void OpU8b_shufflePtrs(vector<OpU8b_Plain*> &v)	// NOTE: placeholder name
{
	random_shuffle(v.begin(),v.end(),OpS8c_shuffleFn);
}

void OpU8b_shuffleBools(vector<bool> &v)	// NOTE: placeholder name
{
	random_shuffle(v.begin(),v.end(),OpS8c_shuffleFn);
}

void OpU8b_readPropHandles(istream &stream, vector<HProp> &v)	// NOTE: placeholder name
{
	HProp prop;
	int count;
	stream.read((char*)&count,4);
	while (count != 0)
	{
		v.push_back(prop);
		v.back().load(stream);
		count--;
	}
}

void OpU8b_readRanges(istream &stream, vector<OpU8b_Range> &v)	// NOTE: placeholder name
{
	OpU8b_Range range;
	int count;
	stream.read((char*)&count,4);
	while (count != 0)
	{
		v.push_back(range);
		v.back().read(stream);
		count--;
	}
}

void OpU8b_readTriples(istream &stream, vector<OpR1g_Triple> &v)	// NOTE: placeholder name
{
	OpR1g_Triple triple;
	int count;
	stream.read((char*)&count,4);
	while (count != 0)
	{
		v.push_back(triple);
		v.back().read(stream);
		count--;
	}
}

void OpU8b_findIndices(vector<OpU8b_Plain*> &v, OpU8b_Plain *value, vector<int> &out)	// NOTE: placeholder name
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
			out.push_back(i);
	}
}

void OpU8b_shuffledIndices(vector<OpU8b_Plain*> &v, vector<int> &out)	// NOTE: placeholder name
{
	for (int i = 0; i < v.size(); i++)
		out.push_back(i);
	OpU8b_shuffle(out);
}

string OpU8b_popRandomString(vector<string> &v)	// NOTE: placeholder name
{
	int index = rng.rangeInt(0,v.size() - 1);
	string s = v[index];
	OpQ5_eraseAt(v,index);
	return s;
}

OpU8b_Handle OpU8b_randomHandle(vector<OpU8b_Handle> &v)	// NOTE: placeholder name
{
	return v[rng.rangeInt(0,v.size() - 1)];
}

bool OpU8b_containsPtr(vector<OpU8b_Plain*> &v, OpU8b_Plain *value)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
			return true;
	}
	return false;
}

bool OpU8b_addUniqueString(vector<string> &v, string s)	// NOTE: placeholder name
{
	if (!OpU8a_containsString(v,s))
	{
		v.push_back(s);
		return true;
	}
	return false;
}

OpU8b_Area OpU8b_popRandomArea(vector<OpU8b_Area> &v)	// NOTE: placeholder name
{
	int index = rng.rangeInt(0,v.size() - 1);
	OpU8b_Area a = v[index];
	OpQ5_eraseAt(v,index);
	return a;
}

Point OpU8b_popRandomPoint(vector<Point> &v)	// NOTE: placeholder name
{
	int index = rng.rangeInt(0,v.size() - 1);
	Point p = v[index];
	OpQ5_eraseAt(v,index);
	return p;
}

bool OpU8b_addUniquePoint(vector<Point> &v, Point p)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == p)
			return false;
	}
	v.push_back(p);
	return true;
}

void OpU8b_appendMissing(vector<string> &a, vector<string> &b)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < b.size(); i++)
	{
		for (unsigned int j = 0; j < a.size(); j++)
		{
			if (a[j] == b[i])
				goto next;
		}
		a.push_back(b[i]);
		next:;
	}
}

int OpU8b_countString(vector<string> &v, string s)	// NOTE: placeholder name
{
	int count = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == s)
			count++;
	}
	return count;
}

void OpU8b_deleteAt(vector<OpU8b_Plain*> &v, int &index)	// NOTE: placeholder name
{
	delete v[index];
	v.erase(v.begin()+index);
	index--;
}

int OpU8b_removeAll(vector<int> &v, int value)	// NOTE: placeholder name
{
	int count = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
		{
			count++;
			OpT8a_eraseAt(v,i);
		}
	}
	return count;
}

bool OpU8b_betweenInclusive(unsigned int a, unsigned int b, unsigned int c)	// NOTE: placeholder name
{
	return a <= b && b <= c;
}

bool OpU8b_betweenExclusive(unsigned int a, unsigned int b, unsigned int c)	// NOTE: placeholder name
{
	return a < b && b < c;
}

void OpU8b_fillInts(int *a, unsigned int count, int value)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
		a[i] = value;
}

double OpU8b_max(double a, double b)	// NOTE: placeholder name
{
	return a < b ? b : a;
}

void OpU8b_deleteAll(vector<OpU8b_Plain*> &v)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
		delete v[i];
}

int OpU8b_indexOfName(vector<OpU8b_Named*> &v, string &name)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i]->name == name)
			return i;
	}
	return -1;
}

void OpU8b_instances()	// NOTE: placeholder name
{
	vector<OpU8b_Plain*> *p = 0;
	OpU8b_shuffle(*p);
	vector<int> *q = 0;
	OpU8b_shuffle(*q);
	OpU8b_insertAt(*q,0,0);
}
