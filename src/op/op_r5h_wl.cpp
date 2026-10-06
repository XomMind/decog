// op_r5h_wl: weighted random lists (template instances) in 0x9b0000-0x9bb000, Beta 17.1.
// NOTE: class/method names are placeholders; layout: values @0, weights @0x10, total @0x20.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;

	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
	bool operator==(const Point &p) const;	// 0x409b90
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	bool operator==(HEntity other) const;	// 0x9b78e0
};

struct EntityData4563c0;

struct OpR5h_Pair	// NOTE: placeholder name
{
	int value;
	int weight;
};

bool opR5h_inVector(vector<int> &v, int value);	// NOTE: placeholder name (0x9db330)
int opR5h_indexOf(vector<int> &v, int value);	// NOTE: placeholder name (0x9d4660)
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	OpR5h_WL(const int *w, int count);	// 0x9ba790
	OpR5h_WL(vector<int> &w);	// 0x9baaa0
	void reset();	// NOTE: placeholder name (0x9c07a0)
	void init(const OpR5h_Pair *pairs, int count);	// NOTE: placeholder name (0x9b9e90)
	void add(T value, int weight);	// 0x9ba310
	void addUnique(T value, int weight);	// 0x9b6e10
	void addOrAdjust(T value, int weight);	// 0x9ba350
	void remove(T value);	// 0x9bab80
	void removeAt(int index);	// NOTE: placeholder name (0x9c1d20)
	bool contains(T value);	// 0x9ba080
	bool contains(T *value);	// 0x9b6f10
	int getWeight(T *value);	// 0x9b6f60
	bool setWeight(T value, int weight);	// 0x9ba9a0
	bool setWeightAt(unsigned int index, int weight);	// 0x9baa30
	T &pick();	// 0x9ba470
	bool pick(T *out);	// 0x9ba6a0
	T &pickNot(T value);	// 0x9ba750
};

template <class T>
OpR5h_WL<T>::OpR5h_WL() throw()
{
	reset();
}

template <class T>
void OpR5h_WL<T>::add(T value, int weight)
{
	if (weight > 0)
	{
		values.push_back(value);
		weights.push_back(weight);
		total += weight;
	}
}

template <class T>
T &OpR5h_WL<T>::pick()
{
	if (!weights.empty())
	{
		int r = rng.rangeInt(0,(float)(total - 1));
		int sum = 0;
		for (unsigned int i = 0; i < weights.size(); i++)
		{
			sum += weights[i];
			if (r < sum)
				return values[i];
		}
	}
	return values.front();
}

template <class T>
OpR5h_WL<T>::OpR5h_WL(const int *w, int count)
{
	reset();
	for (int i = 0; i < count; i++)
		add(i,w[i]);
}

template <class T>
OpR5h_WL<T>::OpR5h_WL(vector<int> &w)
{
	reset();
	for (unsigned int i = 0; i < w.size(); i++)
		add(i,w[i]);
}

template <class T>
void OpR5h_WL<T>::init(const OpR5h_Pair *pairs, int count)
{
	reset();
	for (int i = 0; i < count; i++)
		add(pairs[i].value,pairs[i].weight);
}

template <class T>
void OpR5h_WL<T>::addUnique(T value, int weight)
{
	if (weight > 0 && !opR5h_inVector(values,value))
	{
		values.push_back(value);
		weights.push_back(weight);
		total += weight;
	}
}

template <class T>
void OpR5h_WL<T>::addOrAdjust(T value, int weight)
{
	for (unsigned int i = 0; i < values.size(); i++)
	{
		if (values[i] == value)
		{
			if (weights[i] + weight <= 0)
			{
				total -= weights[i];
				removeVectorElement(weights,i);
				removeVectorElement(values,i);
			}
			else
			{
				weights[i] += weight;
				total += weight;
			}
			return;
		}
	}
	add(value,weight);
}

template <class T>
void OpR5h_WL<T>::remove(T value)
{
	int index = opR5h_indexOf(values,value);
	if (index != -1)
		removeAt(index);
}

template <class T>
bool OpR5h_WL<T>::contains(T value)
{
	for (unsigned int i = 0; i < values.size(); i++)
	{
		if (values[i] == value)
			return true;
	}
	return false;
}

template <class T>
bool OpR5h_WL<T>::contains(T *value)
{
	for (unsigned int i = 0; i < values.size(); i++)
	{
		if (values[i] == *value)
			return true;
	}
	return false;
}

template <class T>
int OpR5h_WL<T>::getWeight(T *value)
{
	for (unsigned int i = 0; i < values.size(); i++)
	{
		if (values[i] == *value)
			return weights[i];
	}
	return -1;
}

template <class T>
bool OpR5h_WL<T>::setWeight(T value, int weight)
{
	for (unsigned int i = 0; i < values.size(); i++)
	{
		if (values[i] == value)
		{
			total -= weights[i];
			weights[i] = weight;
			total += weight;
			return true;
		}
	}
	return false;
}

template <class T>
bool OpR5h_WL<T>::setWeightAt(unsigned int index, int weight)
{
	if (index >= weights.size())
		return false;
	total -= weights[index];
	weights[index] = weight;
	total += weight;
	return true;
}

template <class T>
bool OpR5h_WL<T>::pick(T *out)
{
	if (!weights.empty())
	{
		int r = rng.rangeInt(0,(float)(total - 1));
		int sum = 0;
		for (unsigned int i = 0; i < weights.size(); i++)
		{
			sum += weights[i];
			if (r < sum)
			{
				*out = values[i];
				return true;
			}
		}
	}
	return false;
}

template <class T>
T &OpR5h_WL<T>::pickNot(T value)
{
	while (1)
	{
		T *p = &pick();
		if (*p != value)
			return *p;
	}
	return values.front();
}

template OpR5h_WL<int>::OpR5h_WL() throw();
template OpR5h_WL<int>::OpR5h_WL(const int *w, int count);
template OpR5h_WL<int>::OpR5h_WL(vector<int> &w);
template void OpR5h_WL<int>::init(const OpR5h_Pair *pairs, int count);
template void OpR5h_WL<int>::add(int value, int weight);
template void OpR5h_WL<int>::addUnique(int value, int weight);
template void OpR5h_WL<int>::addOrAdjust(int value, int weight);
template void OpR5h_WL<int>::remove(int value);
template bool OpR5h_WL<int>::contains(int value);
template bool OpR5h_WL<int>::contains(int *value);
template int OpR5h_WL<int>::getWeight(int *value);
template bool OpR5h_WL<int>::setWeight(int value, int weight);
template bool OpR5h_WL<int>::setWeightAt(unsigned int index, int weight);
template int &OpR5h_WL<int>::pick();
template bool OpR5h_WL<int>::pick(int *out);
template int &OpR5h_WL<int>::pickNot(int value);

template OpR5h_WL<Point>::OpR5h_WL() throw();
template void OpR5h_WL<Point>::add(Point value, int weight);
template bool OpR5h_WL<Point>::setWeight(Point value, int weight);
template Point &OpR5h_WL<Point>::pick();
template void OpR5h_WL<XColor>::add(XColor value, int weight);
template XColor &OpR5h_WL<XColor>::pick();
template void OpR5h_WL<EntityData4563c0*>::add(EntityData4563c0 *value, int weight);
template bool OpR5h_WL<HEntity>::contains(HEntity *value);
template void OpR5h_WL<string>::add(string value, int weight);
template string &OpR5h_WL<string>::pick();

class OpR5h_WLString	// NOTE: placeholder name
{
public:
	vector<string> values;
	vector<int> weights;
	int total;

	OpR5h_WLString();	// 0x9b9ee0
	void reset();	// NOTE: placeholder name (0x9c1b20)
};

OpR5h_WLString::OpR5h_WLString()
{
	reset();
}
