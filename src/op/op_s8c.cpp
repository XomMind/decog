// op_s8c: vector/serialization helper instances 0x9d7980-0x9dc8a0 (placeholder names)
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

template <class T> void writeBinary(ostream &stream, T *value);	// NOTE: placeholder name

struct Point
{
	int x;
	int y;
	Point();	// 0x453b40
	Point(const Point &p);	// 0x46ca50
};

struct OpS8c_Named
{
	int pad;
	string name;
};

struct OpS8c_Area
{
	char pad[16];
	OpS8c_Area(const OpS8c_Area &a);	// 0x40b130
};

struct OpS8c_Handle
{
	int h;
	OpS8c_Handle();
};

struct OpS8c_Plain
{
	int pad[3];
};

template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name

template <class T> void OpS8c_deleteObject(vector<T*> &v, int index)	// NOTE: placeholder name
{
	delete v[index];
	v.erase(v.begin()+index);
}

template <class T> void OpS8c_shuffle(vector<T> &v)	// NOTE: placeholder name
{
	random_shuffle(v.begin(),v.end(),OpS8c_shuffleFn);
}

bool OpS8c_Fn9d0ce0(vector<Point> &v, Point p);	// NOTE: placeholder name

int OpS8c_indexOfName(vector<OpS8c_Named*> &v, string &name)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i]->name == name)
			return i;
	}
	return -1;
}

bool OpS8c_between(float a, float b, float c)	// NOTE: placeholder name
{
	return a < b && b < c;
}

OpS8c_Area OpS8c_randomArea(vector<OpS8c_Area> &v)	// NOTE: placeholder name
{
	return v[rng.rangeInt(0,v.size() - 1)];
}

int OpS8c_indexOfMinFloat(vector<float> &v)	// NOTE: placeholder name
{
	int best = 0;
	for (unsigned int i = 1; i < v.size(); i++)
	{
		if (v[i] < v[best])
			best = i;
	}
	return best;
}

int OpS8c_indexOfMaxFloat(vector<float> &v)	// NOTE: placeholder name
{
	int best = 0;
	for (unsigned int i = 1; i < v.size(); i++)
	{
		if (v[i] > v[best])
			best = i;
	}
	return best;
}

int OpS8c_indexOfMinInt(vector<int> &v)	// NOTE: placeholder name
{
	int best = 0;
	for (unsigned int i = 1; i < v.size(); i++)
	{
		if (v[i] < v[best])
			best = i;
	}
	return best;
}

bool OpS8c_anyNonNull(vector<OpS8c_Named*> &v)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i])
			return true;
	}
	return false;
}

OpS8c_Handle OpS8c_popRandom(vector<OpS8c_Handle> &v)	// NOTE: placeholder name
{
	int index = rng.rangeInt(0,v.size() - 1);
	OpS8c_Handle h = v[index];
	OpQ5_eraseAt(v,index);
	return h;
}

void OpS8c_appendUnique(vector<Point> &out, vector<Point> &in)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < in.size(); i++)
	{
		if (!OpS8c_Fn9d0ce0(out,in[i]))
			out.push_back(in[i]);
	}
}

void OpS8c_readPoints(istream &stream, vector<Point> &v)	// NOTE: placeholder name
{
	Point position;
	int count;
	stream.read((char*)&count,4);
	while (count != 0)
	{
		stream.read((char*)&position,8);
		v.push_back(position);
		count--;
	}
}

void OpS8c_writePoints(ostream &stream, vector<Point> &v)	// NOTE: placeholder name
{
	unsigned int count = v.size();
	stream.write((char*)&count,4);
	for (unsigned int i = 0; i < count; i++)
		stream.write((char*)&v[i],8);
}

int OpS8c_countPositive(vector<int> &v)	// NOTE: placeholder name
{
	int count = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] > 0)
			count++;
	}
	return count;
}

void OpS8c_insertAt(vector<int> &v, int index, int value)	// NOTE: placeholder name
{
	if (index == v.size())
		v.push_back(value);
	else
		v.insert(v.begin()+index,value);
}

void OpS8c_shuffleRange(vector<int> &v, int from, int to)	// NOTE: placeholder name
{
	random_shuffle(v.begin()+from,v.begin()+to,OpS8c_shuffleFn);
}

void OpS8c_copyRange(vector<Point> &out, vector<Point> &in, int from, int to)	// NOTE: placeholder name
{
	for (int i = from; i <= to && i < in.size(); i++)
		out.push_back(in[i]);
}

void OpS8c_indices(vector<Point> &in, vector<int> &out)	// NOTE: placeholder name
{
	for (int i = 0; i < in.size(); i++)
		out.push_back(i);
}

void OpS8c_copyInts(int *src, int *dst, unsigned int count)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
		dst[i] = src[i];
}

bool OpS8c_anyTrue(const vector<bool> &v)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i])
			return true;
	}
	return false;
}

int OpS8c_randomOf(int *a, unsigned int count)	// NOTE: placeholder name
{
	return a[rng.rangeInt(0,count - 1)];
}

void OpS8c_writeOptionalInt(ostream &stream, int *p)	// NOTE: placeholder name
{
	bool present = p != NULL;
	writeBinary(stream,&present);
	if (present)
		writeBinary(stream,p);
}

void OpS8c_instances()	// NOTE: placeholder name
{
	vector<OpS8c_Plain*> *v = 0;
	OpS8c_deleteObject(*v,0);
	vector<int> *w = 0;
	OpS8c_shuffle(*w);
}
