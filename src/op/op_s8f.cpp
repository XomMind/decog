// op_s8f: std (VS2010) template instances and compiler-generated members (address range 0x9ef460-0x9f9050)
// NOTE: placeholder names (OpS8f_*)
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

template vector<unsigned int>::vector<unsigned int>(unsigned int, unsigned int);

struct OpS8f_H4	// NOTE: placeholder name; 4-byte element type with operator< (0x9f5830)
{
	unsigned int v;
	bool operator<(OpS8f_H4 o) const { return v < o.v; };
};

bool OpS8f_search(vector<OpS8f_H4> &c, const OpS8f_H4 &x)
{
	return binary_search(c.begin(),c.end(),x);
}

struct Point
{
	int x;
	int y;

	Point();
	Point(const Point &p);
	Point &operator=(const Point &p);
};

struct E8_9b3130	// NOTE: placeholder name; element of the vectors copied by vector::operator= 0x9b3130 (distinct from lead/stl_a.cpp E8_0)
{
	char pad[8];
	E8_9b3130 &operator=(const E8_9b3130 &e);	// NOTE: the exe assigns these elements with a call (_Copy_impl 0x9efd30); copies stay inline (construct 0x9f05e0)
};

struct OpH_CDA10_1	// NOTE: placeholder name
{
	char pad[0x10];
	OpH_CDA10_1();
	OpH_CDA10_1(const OpH_CDA10_1 &o);
	~OpH_CDA10_1();
	OpH_CDA10_1 &operator=(const OpH_CDA10_1 &o);
};

struct OpR6_KA_20_0
{
	int m0;
	int m4;
	int m8;
	int m12;
	int m16;
	OpR6_KA_20_0 &operator=(const OpR6_KA_20_0 &o);
};

// implicit operator= of placeholder structs (member-wise)
struct OpS8f_S9f4e00	// NOTE: placeholder name
{
	vector<E8_9b3130> a;
	vector<int> b;
	vector<E8_9b3130> c;
	vector<int> d;
	int e;
	bool f;
	bool g;
	Point p;
	bool h;
};

struct OpS8f_S9f4ea0	// NOTE: placeholder name
{
	vector<E8_9b3130> a;
	vector<int> b;
};

struct OpS8f_S9f4ed0	// NOTE: placeholder name
{
	int m0;
	int m4;
	int m8;
	int m12;
	int m16;
	vector<int> a;
	vector<int> b;
	bool c;
};

struct OpS8f_S9f4f50	// NOTE: placeholder name
{
	vector<int> a;
	vector<int> b;
	vector<int> c;
};

struct OpS8f_S9f4f90	// NOTE: placeholder name
{
	Point p;
	int m8;
	int m12;
	int m16;
};

struct OpS8f_S9f4fd0	// NOTE: placeholder name
{
	Point p;
	int m8;
};

struct OpS8f_S9f5000	// NOTE: placeholder name
{
	Point p;
	bool a;
	int m12;
};

struct OpS8f_S9f5040	// NOTE: placeholder name
{
	int m0;
	int m4;
	int m8;
	int m12;
	vector<int> a;
	vector<OpH_CDA10_1> b;
	vector<OpR6_KA_20_0> c;
};

void OpS8f_uses(OpS8f_S9f4e00 &a1, OpS8f_S9f4ea0 &a2, OpS8f_S9f4ed0 &a3, OpS8f_S9f4f50 &a4, OpS8f_S9f4f90 &a5, OpS8f_S9f4fd0 &a6, OpS8f_S9f5000 &a7, OpS8f_S9f5040 &a8)
{
	a1 = a1;
	a2 = a2;
	a3 = a3;
	a4 = a4;
	a5 = a5;
	a6 = a6;
	a7 = a7;
	a8 = a8;
}
