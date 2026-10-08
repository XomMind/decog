// op_s8b: generic container helper instances (0x9d43b0-0x9d7980). Placeholder names.
// NOTE: placeholder names
#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

class Predicate_409b90
{
public:
	int field0;
	int field4;
	bool test(const Predicate_409b90 & arg0);
};

bool OpS8b_Fn9d43b0(int *values, unsigned int count, int value)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
	{
		if (values[i] == value)
			return true;
	}
	return false;
}

int OpS8b_Fn9d43f0(vector<int> &v, int first, int last)	// NOTE: placeholder name
{
	int total = 0;
	for (int i = first; i <= last; i++)
		total += v[i];
	return total;
}

int OpS8b_Fn9d4500(vector<int> &v)	// NOTE: placeholder name
{
	int best = 0;
	for (unsigned int i = 1; i < v.size(); i++)
	{
		if (v[i] > v[best])
			best = i;
	}
	return best;
}

void OpS8b_Fn9d4560(char *src, char *dest, unsigned int count)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
		dest[i] = src[i];
}

int OpS8b_Fn9d4660(vector<int> &v, int value)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
			return i;
	}
	return -1;
}

int OpS8b_Fn9d4b30(unsigned char *data, unsigned int count, unsigned char value)	// NOTE: placeholder name
{
	vector<int> matches;
	for (int i = 0; i < count; i++)
	{
		if (data[i] == value)
			matches.push_back(i);
	}
	if (matches.empty())
	{
		return -1;
	}
	else
	{
		return matches[rng.rangeInt(0,matches.size() - 1)];
	}
}

void OpS8b_Fn9d4c70(ostream &stream, int *values, unsigned int count)	// NOTE: placeholder name
{
	stream.write((char*)&count,sizeof(count));
	for (unsigned int i = 0; i < count; i++)
		stream.write((char*)&values[i],sizeof(int));
}

void OpS8b_Fn9d4ec0(istream &stream, int *values)	// NOTE: placeholder name
{
	unsigned int count;
	stream.read((char*)&count,sizeof(count));
	for (unsigned int i = 0; i < count; i++)
		stream.read((char*)&values[i],sizeof(int));
}

struct OpY2_Rec448270	// NOTE: placeholder name
{
	char pad[12];
	void load(istream &stream);	// NOTE: placeholder name
};

struct OpY2_Rec4482c0	// NOTE: placeholder name
{
	char pad[0x44];
	void load(istream &stream);	// NOTE: placeholder name
};

void OpS8b_Fn9d4cc0(istream &stream, vector<OpY2_Rec448270> &v)	// NOTE: placeholder name
{
	OpY2_Rec448270 rec;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(rec);
		v.back().load(stream);
		count--;
	}
}

void OpS8b_Fn9d4d20(istream &stream, OpY2_Rec4482c0 *recs)	// NOTE: placeholder name
{
	unsigned int count;
	stream.read((char*)&count,sizeof(count));
	for (unsigned int i = 0; i < count; i++)
		recs[i].load(stream);
}

bool OpS8b_Fn9d5080(unsigned char *values, unsigned int count)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
	{
		if (values[i])
			return true;
	}
	return false;
}

int OpS8b_Fn9d50c0(int *values, unsigned int count)	// NOTE: placeholder name
{
	int best = 0;
	for (unsigned int i = 1; i < count; i++)
	{
		if (values[i] > values[best])
			best = i;
	}
	return best;
}

bool OpS8b_Fn9d51d0(vector<int> &v, int value)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
		{
			v.erase(v.begin()+i);
			return true;
		}
	}
	return false;
}

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();	// 0x411e30
	bool operator==(XColor color);	// 0x411f40
};

int OpS8b_Fn9d4f10(XColor *colors, unsigned int count, XColor color)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
	{
		if (colors[i] == color)
			return i;
	}
	return -1;
}

struct OpS8b_T9d4f60	// NOTE: placeholder name
{
	char pad[4];
	virtual ~OpS8b_T9d4f60();
};

void OpS8b_Fn9d4f60(vector<OpS8b_T9d4f60*> &v, int &index)	// NOTE: placeholder name
{
	delete v[index];
	v.erase(v.begin()+index);
	index--;
}

struct OpS8b_Rec448430	// NOTE: placeholder name
{
	char pad[0xb0];
	OpS8b_Rec448430();	// 0x4bf280
	~OpS8b_Rec448430();	// 0x4bf300
};

struct OpY2_Rec448430	// NOTE: placeholder name
{
	char pad[0xb0];
	void load(istream &stream);	// NOTE: placeholder name
};

void OpS8b_Fn9d4d70(istream &stream, vector<OpY2_Rec448430> &v)	// NOTE: placeholder name
{
	OpS8b_Rec448430 rec;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(*(OpY2_Rec448430*)&rec);
		v.back().load(stream);
		count--;
	}
}

struct OpS8b_Quad	// NOTE: placeholder name
{
	int a;
	int b;
	int c;
	int d;
};

struct OpS8b_Data84	// NOTE: placeholder name
{
	OpS8b_Quad q0;
	OpS8b_Quad q1;
	OpS8b_Quad q2;
	OpS8b_Quad q3;
	OpS8b_Quad q4;
	OpS8b_Quad q5;
	OpS8b_Quad q6;
	OpS8b_Quad q7;
	int tail;
};

struct OpS8b_Rec448630	// NOTE: placeholder name
{
	int f0;
	int f1;
	int f2;
	int f3;
	int f4;
	int f5;
	int f6;
	int f7;
	int f8;
	int f9;
	int f10;
	int f11;
	int f12;
	int f13;
	int f14;
	int f15;
	int f16;
	int f17;
	int f18;
	int f19;
	int f20;
	int f21;
	int f22;
	int f23;
	int f24;
	int f25;
	int f26;
	int f27;
	int f28;
	int f29;
	int f30;
	int f31;
	int f32;
	OpS8b_Rec448630();	// 0x448aa0
	~OpS8b_Rec448630();	// 0x448b40
};

struct OpY2_Rec448630 : public OpS8b_Data84	// NOTE: placeholder name
{
	void load(istream &stream);	// NOTE: placeholder name
};

void OpS8b_Fn9d4e20(istream &stream, vector<OpS8b_Rec448630> &v)	// NOTE: placeholder name
{
	OpS8b_Rec448630 rec;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(rec);
		((OpY2_Rec448630&)v.back()).load(stream);
		count--;
	}
}

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();	// NOTE: placeholder
	void read_40a8b0(istream &in);	// NOTE: placeholder name
};

void OpS8b_Fn9d5250(istream &stream, vector<Rect> &v)	// NOTE: placeholder name
{
	Rect rect;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(rect);
		v.back().read_40a8b0(stream);
		count--;
	}
}

struct OpS8b_Data34	// NOTE: placeholder name
{
	OpS8b_Quad q0;
	OpS8b_Quad q1;
	OpS8b_Quad q2;
	int tail;
};

struct OpY2_Rec449200 : public OpS8b_Data34	// NOTE: placeholder name
{
	void load(istream &stream);	// NOTE: placeholder name
};

class Calls_4c9b00 : public OpS8b_Data34
{
public:
	Calls_4c9b00 & delegate();
};

void OpS8b_Fn9d52b0(istream &stream, vector<OpY2_Rec449200> &v)	// NOTE: placeholder name
{
	Calls_4c9b00 rec;
	rec.delegate();
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(*(OpY2_Rec449200*)&rec);
		v.back().load(stream);
		count--;
	}
}

struct Point : public Predicate_409b90
{
	Point(const Point &p);	// NOTE: placeholder
};

Point OpS8b_Fn9d5350(vector<Point> &v)	// NOTE: placeholder name
{
	return v[rng.rangeInt(0,v.size() - 1)];
}

int OpS8b_Fn9d53a0(vector<Point> &v, Point p)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i].test(p))
			return i;
	}
	return -1;
}

void OpS8b_Fn9d5460(vector<Point> &v, int index, Point p)	// NOTE: placeholder name
{
	if (index == v.size())
		v.push_back(p);
	else
		v.insert(v.begin()+index,p);
}

void OpS8b_Fn9d4440(vector<string> &v, int index, string s)	// NOTE: placeholder name
{
	if (index == v.size())
		v.push_back(s);
	else
		v.insert(v.begin()+index,s);
}
