// op_s8d: container / serialization helper instances (0x9dc8a0-0x9ebbe0)
// NOTE: placeholder names
#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include <algorithm>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908
bool OpY1_equalsNoCase(const string &a, const string &b);

struct OpQ5_T9ee9a0;
struct OpQ5_T9ef000;
template <class T> void OpQ5_readPointer(istream &stream, T *&p);	// NOTE: placeholder name

struct OpQ5_U9da1f0
{
	int pad;
};
template <class T> void OpQ5_moveElement(vector<T> &v, unsigned int from, unsigned int to);	// NOTE: placeholder name
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0

template <class T> void OpS8d_readPointers(istream &stream, vector<T*> &v)	// NOTE: placeholder name
{
	T *p;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		OpQ5_readPointer(stream,p);
		v.push_back(p);
		count--;
	}
}
template void OpS8d_readPointers<OpQ5_T9ee9a0>(istream &stream, vector<OpQ5_T9ee9a0*> &v);
template void OpS8d_readPointers<OpQ5_T9ef000>(istream &stream, vector<OpQ5_T9ef000*> &v);

void OpS8d_readFloats(istream &stream, vector<float> &v)	// NOTE: placeholder name
{
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		float f;
		stream.read((char*)&f,sizeof(f));
		v.push_back(f);
		count--;
	}
}

void OpS8d_reverseElements(vector<OpQ5_U9da1f0> &v)	// NOTE: placeholder name
{
	for (int remaining = v.size(), i = 0; remaining > 1; remaining--, i++)
		OpQ5_moveElement(v,v.size() - 1,i);
}

int OpS8d_popRandom(vector<int> &v)	// NOTE: placeholder name
{
	int value;
	int index = rng.rangeInt(0,v.size() - 1);
	value = v[index];
	removeVectorElement(v,index);
	return value;
}

int OpS8d_maxValue(int *values, unsigned int count)	// NOTE: placeholder name
{
	int best = 0;
	for (unsigned int i = 1; i < count; i++)
	{
		if (values[i] > values[best])
			best = i;
	}
	return values[best];
}

struct OpS8d_Rec10
{
	int a;
};

void OpS8d_deleteAndStep(vector<OpS8d_Rec10*> &v, unsigned int *i)	// NOTE: placeholder name
{
	delete v[*i];
	vector<OpS8d_Rec10*>::iterator it = v.begin() + *i;
	v.erase(it);
	(*i)--;
}

void OpS8d_deleteAll(vector<OpS8d_Rec10*> &v)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		delete v[i];
	}
}

int OpS8d_countNonNull(vector<OpS8d_Rec10*> &v)	// NOTE: placeholder name
{
	int count = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i])
			count++;
	}
	return count;
}

struct OpS8d_Rec18
{
	int a[6];
	string name;
};

int OpS8d_findName18(vector<OpS8d_Rec18*> &v, const string &name)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i]->name == name)
			return i;
	}
	return -1;
}

struct OpS8d_Rec8
{
	int a[2];
	string name;
};

int OpS8d_findNameNoCase8(vector<OpS8d_Rec8*> &v, const string &name)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (OpY1_equalsNoCase(v[i]->name,name))
			return i;
	}
	return -1;
}

struct OpS8d_Rec4
{
	int a;
	string name;
};

int OpS8d_findNameNoCase4(vector<OpS8d_Rec4*> &v, const string &name)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (OpY1_equalsNoCase(v[i]->name,name))
			return i;
	}
	return -1;
}

bool OpS8d_containsInRange(vector<OpS8d_Rec10*> &v, OpS8d_Rec10 *value, unsigned int first, unsigned int last)	// NOTE: placeholder name
{
	for (unsigned int i = first; i <= last; i++)
	{
		if (v[i] == value)
			return true;
	}
	return false;
}

int OpS8d_findNonZero(unsigned char *data, unsigned int count)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
	{
		if (data[i])
			return i;
	}
	return -1;
}

float OpS8d_average(vector<float> &v)	// NOTE: placeholder name
{
	if (v.empty())
		return 0;
	float total = v[0];
	for (unsigned int i = 1; i < v.size(); i++)
		total += v[i];
	return total / v.size();
}

struct OpS8d_Rec1ac
{
	int a[107];
	string name;
};

int OpS8d_findName1ac(vector<OpS8d_Rec1ac*> &v, const string &name)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i]->name == name)
			return i;
	}
	return -1;
}

struct OpS8d_Color3	// NOTE: placeholder name
{
	unsigned char r, g, b;
};

void OpS8d_appendColors(vector<OpS8d_Color3> &v, OpS8d_Color3 *colors, unsigned int count)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
		v.push_back(colors[i]);
}

void OpS8d_appendIndices(vector<int> &source, vector<int> &indices)	// NOTE: placeholder name
{
	for (int i = 0; i < source.size(); i++)
		indices.push_back(i);
}

void OpS8d_appendInts(vector<int> &v, int *values, unsigned int count)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
		v.push_back(values[i]);
}

bool OpS8d_anyNegative(int *values, unsigned int count)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
	{
		if (values[i] < 0)
			return true;
	}
	return false;
}

void OpS8d_reverseInts(vector<int> &v)	// NOTE: placeholder name
{
	reverse(v.begin(),v.end());
}

template void vector<int>::insert<int*>(vector<int>::const_iterator where, int *first, int *last);
