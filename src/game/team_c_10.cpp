// team_c_10: member-wise destructors, allocator<T>::construct(T *, T &&) instances, wstring / string-from-iterator instances
// NOTE: all non-std names are placeholders
#include <memory>
#include <string>
#include <vector>
using namespace std;

struct Point	// as in pathing/gamedecl.h (copy ctor: throw() keeps placement new free of EH)
{
	int x;
	int y;

	Point();
	Point(const Point &p) throw();
	Point &operator=(const Point &p);
};

struct OpC_Rec9e7780	// NOTE: placeholder name/layout
{
	char pad0[8];
	vector<unsigned int> list8;
	vector<unsigned int> list18;
	vector<string> names28;

	~OpC_Rec9e7780();
};

OpC_Rec9e7780::~OpC_Rec9e7780()
{
}

struct OpC_Rec9e7850	// NOTE: placeholder name/layout
{
	char pad0[8];
	vector<unsigned int> list8;
	string name18;
	char pad34[0xc];
	string text40;
	char pad5c[0x20];
	vector<string> names7c;

	~OpC_Rec9e7850();
};

OpC_Rec9e7850::~OpC_Rec9e7850()
{
}

struct OpC_Rec9e78f0	// NOTE: placeholder name/layout
{
	char pad0[0x10];
	vector<Point> points10;
	vector<unsigned int> list20;

	~OpC_Rec9e78f0();
};

OpC_Rec9e78f0::~OpC_Rec9e78f0()
{
}

//==================================================================
// allocator<T>::construct(T *, T &&): placement new + copy ctor
//==================================================================

struct OpC_C16a { int a, b, c, d; OpC_C16a(const OpC_C16a &o) throw(); };
struct OpC_C12 { int a, b, c; OpC_C12(const OpC_C12 &o) throw(); };
struct OpC_C16b { int a, b, c, d; OpC_C16b(const OpC_C16b &o) throw(); };
struct OpC_C16p { int a; Point p; int d; };
struct OpC_C24 { int v[9]; OpC_C24(const OpC_C24 &o) throw(); };

template void allocator<OpC_C16a>::construct(OpC_C16a *, OpC_C16a &&);
template void allocator<OpC_C12>::construct(OpC_C12 *, OpC_C12 &&);
template void allocator<OpC_C16b>::construct(OpC_C16b *, OpC_C16b &&);
template void allocator<OpC_C16p>::construct(OpC_C16p *, OpC_C16p &&);
template void allocator<OpC_C24>::construct(OpC_C24 *, OpC_C24 &&);

//==================================================================
// std::wstring / std::string instances
//==================================================================
template wstring::basic_string(const wchar_t *_Ptr);	// 0x9b0040
template wstring::~basic_string();	// 0x9b00c0
template string::basic_string(string::iterator, string::iterator);	// 0x9ccda0
template wstring::basic_string(string::const_iterator, string::const_iterator);	// 0x9d5680
