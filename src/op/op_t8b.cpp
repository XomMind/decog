// op_t8b: VS2010 std template instances and small helpers in 0x9d4000-0x9de000, matched against COGMIND.exe (Beta 17.1).
// NOTE: placeholder names (OpT8b_...); element types are guessed from the disassembly
//	(ICF folded same-sized scalar instances, so the element type of some vectors is int by convention).
#include <vector>
#include <string>
#include <algorithm>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908
extern int (*OpT8b_shuffleFn)(int);	// NOTE: placeholder name (0xcaecd8)

struct Point
{
	int x;
	int y;

	Point();
	Point(int v);
	Point(int x_, int y_);
	Point(const Point &p);
	Point &operator=(const Point &p);
};

class HEntity
{
	int	ID;
public:
	HEntity();
	bool operator==(HEntity other) const;
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();	// 0x411e30
	bool operator==(XColor color);	// 0x411f40
	XColor &operator=(XColor color);	// 0x411f10
};



template void vector<int>::assign<int>(int, int);
template void vector<int>::assign<vector<int>::iterator>(vector<int>::iterator, vector<int>::iterator);
template vector<int>::vector(vector<int>::iterator, vector<int>::iterator);

void OpT8b_Fn9d9890(vector<Point> &dst, vector<Point> &src, int first, int last)	// NOTE: placeholder name
{
	for (int i = first; i <= last && i < src.size(); i++)
		dst.push_back(src[i]);
}

void OpT8b_Fn9d98e0(vector<Point> &list, vector<int> &indices)	// NOTE: placeholder name
{
	for (int i = 0; i < list.size(); i++)
		indices.push_back(i);
}

int OpT8b_Fn9d99a0(vector<int> &v)	// NOTE: placeholder name
{
	if (v.empty())
		return 0;
	vector<int> unique;
	unique.push_back(0);
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 0; j < unique.size(); j++)
		{
			if (v[i] == v[unique[j]])
				goto next;
		}
		unique.push_back(i);
next:;
	}
	return unique.size();
}

int OpT8b_Fn9d9ab0(vector<float> &v)	// NOTE: placeholder name
{
	int best = 0;
	for (unsigned int i = 1; i < v.size(); i++)
	{
		if (v[i] > v[best])
			best = i;
	}
	return best;
}

bool OpT8b_Fn9d9b60(const vector<bool> &v)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i])
			return true;
	}
	return false;
}

int OpT8b_Fn9d76c0(const vector<bool> &v, bool value)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
			return i;
	}
	return -1;
}

void OpT8b_Fn9d78c0(vector<string> &v, string s)	// NOTE: placeholder name
{
	for (vector<string>::iterator it = v.begin(); it != v.end(); )
	{
		if (*it == s)
			it = v.erase(it);
		else
			++it;
	}
}

bool OpT8b_Fn9d6280(vector<int> &a, vector<int> &b)	// NOTE: placeholder name
{
	return a.size() == b.size() && equal(a.begin(),a.end(),b.begin());
}

void OpT8b_Fn9d9190(vector<int> &v, int first, int last)	// NOTE: placeholder name
{
	random_shuffle(v.begin() + first,v.begin() + last,OpT8b_shuffleFn);
}

template void std::sort(vector<int>::iterator, vector<int>::iterator);
template vector<HEntity>::iterator std::unique(vector<HEntity>::iterator, vector<HEntity>::iterator);

bool OpT8b_Fn9db3a0(XColor &dest, XColor color)	// NOTE: placeholder name
{
	if (color == dest)
		return false;
	dest = color;
	return true;
}

bool OpT8b_Fn9d4c40(int a, int b, int c)	// NOTE: placeholder name
{
	return a < b && b < c;
}

bool OpT8b_Fn9daf80(int a, int b, int c)	// NOTE: placeholder name
{
	return a <= b && b <= c;
}

void OpT8b_Fn9d5b10(float *value, float v)	// NOTE: placeholder name
{
	if (*value < v)
		*value = v;
}

void OpT8b_Fn9d84a0(vector<int> &v, int value, unsigned int count)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
		v.push_back(value);
}

bool OpT8b_Fn9dae40(const string &a, const string &b)	// NOTE: placeholder name
{
	return b < a;
}

bool OpT8b_Fn9db380(int *value, int v)	// NOTE: placeholder name
{
	if (v == *value)
		return false;
	*value = v;
	return true;
}

bool OpT8b_contains_9db330(vector<int> &v, int value);	// NOTE: placeholder name

bool OpT8b_Fn9db000(vector<int> &v, int value)	// NOTE: placeholder name
{
	if (!OpT8b_contains_9db330(v,value))
	{
		v.push_back(value);
		return true;
	}
	return false;
}

void OpT8b_Fn9db7e0(vector<string> &v)	// NOTE: placeholder name
{
	random_shuffle(v.begin(),v.end(),OpT8b_shuffleFn);
}

bool OpT8b_Fn9db650(const vector<char> &v, char c)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == c)
			return true;
	}
	return false;
}

int OpT8b_Fn9db9d0(vector<int> &v, int value)	// NOTE: placeholder name
{
	int count = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
			count++;
	}
	return count;
}


int OpT8b_Fn9d4340(vector<int> &v)	// NOTE: placeholder name
{
	int best = 0;
	for (unsigned int i = 1; i < v.size(); i++)
	{
		if (v[i] > v[best])
			best = i;
	}
	return v[best];
}

int OpT8b_Fn9d7290(vector<int> &v)	// NOTE: placeholder name
{
	int best = 0;
	for (unsigned int i = 1; i < v.size(); i++)
	{
		if (v[i] < v[best])
			best = i;
	}
	return v[best];
}

int OpT8b_Fn9d7d70(vector<float> &v)	// NOTE: placeholder name
{
	int best = 0;
	for (unsigned int i = 1; i < v.size(); i++)
	{
		if (v[i] < v[best])
			best = i;
	}
	return best;
}

int OpT8b_Fn9d8ed0(vector<int> &v)	// NOTE: placeholder name
{
	int count = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] > 0)
			count++;
	}
	return count;
}

bool OpT8b_Fn9d85c0(float a, float b, float c)	// NOTE: placeholder name
{
	return a < b && b < c;
}

float OpT8b_Fn9d5ac0(float a, float b, float c)	// NOTE: placeholder name
{
	return b < a ? a : (b > c ? c : b);
}

void OpT8b_Fn9d5b30(vector<int> &v, int value)	// NOTE: placeholder name
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); )
	{
		if (*it == value)
			it = v.erase(it);
		else
			++it;
	}
}

template string std::operator+(const string &, string &&);
template basic_string<char>::basic_string(vector<char>::iterator, vector<char>::iterator);
template string & string::assign<vector<char>::iterator>(vector<char>::iterator, vector<char>::iterator);
