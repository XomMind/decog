// op_v4f: std (VS2010) algorithm / container template instances in 0x9fd000-0xa044d0
// NOTE: placeholder names (OpV4f_*); element types are inferred from the instance bodies in COGMIND.exe
#include <vector>
#include <string>
#include <algorithm>
#include <locale>
#include <memory>
using namespace std;

//==================================================================
// 4-byte class with operator< at 0x9f5830 (sorting, no predicate)
//==================================================================
struct OpV4f_TA
{
	int v;
	bool operator<(OpV4f_TA o) const;	// 0x9f5830
};

void OpV4f_useTA(OpV4f_TA *a, OpV4f_TA *b, OpV4f_TA *c, vector<OpV4f_TA> &v)	// NOTE: placeholder name (forces instances)
{
	make_heap(a, b);
	pop_heap(a, b);
	push_heap(a, b);
	_Insertion_sort(a, b);
	rotate(a, b, c);
	rotate(v.begin(), v.begin(), v.end());
	distance(a, b);
	iter_swap(a, b);
	copy(a, b, c);
	copy_backward(a, b, c);
}

//==================================================================
// 4-byte element sorted with a by-value predicate (two instance families)
//==================================================================
struct OpV4f_Obj;
typedef OpV4f_Obj *OpV4f_TB;

struct OpV4f_TC
{
	int v;
};

typedef bool (*OpV4f_PredB)(OpV4f_TB, OpV4f_TB);
typedef bool (*OpV4f_PredC)(OpV4f_TC, OpV4f_TC);

void OpV4f_useTB(OpV4f_TB *a, OpV4f_TB *b, OpV4f_TB *c, OpV4f_PredB p)	// NOTE: placeholder name (forces instances)
{
	make_heap(a, b, p);
	sort_heap(a, b, p);
	pop_heap(a, b, p);
	push_heap(a, b, p);
	_Insertion_sort(a, b, p);
	_Median(a, b, c, p);
}

void OpV4f_useTC(OpV4f_TC *a, OpV4f_TC *b, OpV4f_TC *c, OpV4f_PredC p)	// NOTE: placeholder name (forces instances)
{
	make_heap(a, b, p);
	sort_heap(a, b, p);
	pop_heap(a, b, p);
	push_heap(a, b, p);
	_Insertion_sort(a, b, p);
	_Median(a, b, c, p);
}

//==================================================================
// 12-byte element with copy constructor at 0x454300
//==================================================================
struct OpV4f_A12
{
	int a;
	int b;
	int c;
	OpV4f_A12(const OpV4f_A12 &o);	// 0x454300
};

void OpV4f_useA12(OpV4f_A12 *a, OpV4f_A12 *b, OpV4f_A12 *c, vector<OpV4f_A12> &v)	// NOTE: placeholder name (forces instances)
{
	rotate(a, b, c);
	distance(a, b);
	swap(*a, *b);
}

//==================================================================
// 16-byte elements: class with copy ctor/assign at 0x40b130, and a std::vector
//==================================================================
struct OpV4f_A16
{
	int a;
	int b;
	int c;
	int d;
	OpV4f_A16(const OpV4f_A16 &o);	// 0x40b130
	OpV4f_A16 &operator=(const OpV4f_A16 &o);	// 0x40b130
};

struct OpV4f_Item
{
	int v;
};

typedef vector<OpV4f_Item> OpV4f_Vec;

void OpV4f_useA16(OpV4f_A16 *a, OpV4f_A16 *b, OpV4f_A16 *c)	// NOTE: placeholder name (forces instances)
{
	rotate(a, b, c);
	swap(*a, *b);
}

void OpV4f_useVec(OpV4f_Vec *a, OpV4f_Vec *b, OpV4f_Vec *c)	// NOTE: placeholder name (forces instances)
{
	rotate(a, b, c);
}

//==================================================================
// Other swap element types: 16-byte class (copy ctor/assign at 0x40a720), Point-like (0x46ca50)
//==================================================================
struct OpV4f_Sw16
{
	int a;
	int b;
	int c;
	int d;
	OpV4f_Sw16(const OpV4f_Sw16 &o);	// 0x40a720
	OpV4f_Sw16 &operator=(const OpV4f_Sw16 &o);	// 0x40a720
};

struct OpV4f_Pt
{
	int x;
	int y;
	OpV4f_Pt(const OpV4f_Pt &o);	// 0x46ca50
	OpV4f_Pt &operator=(const OpV4f_Pt &o);	// 0x46ca50
};

void OpV4f_useSwap(OpV4f_Sw16 *a, OpV4f_Sw16 *b, OpV4f_Pt *c, OpV4f_Pt *d)	// NOTE: placeholder name (forces instances)
{
	swap(*a, *b);
	swap(*c, *d);
}

//==================================================================
// vector::emplace_back with rvalues of 28-byte, 4-byte and pointer elements
//==================================================================
struct OpV4f_E28
{
	int d[7];
};

struct OpV4f_E4
{
	int v;
};

struct OpV4f_Buf;

template void vector<OpV4f_E28>::emplace_back<OpV4f_E28>(OpV4f_E28 &&);
template void vector<OpV4f_E4>::emplace_back<OpV4f_E4>(OpV4f_E4 &&);
template void vector<OpV4f_Buf *>::emplace_back<OpV4f_Buf *>(OpV4f_Buf *&&);

//==================================================================
// placement copy construction (allocator::construct with lvalue)
//==================================================================
struct OpV4f_Cf
{
	int d[4];
	OpV4f_Cf(const OpV4f_Cf &o) throw();	// 0x416ce0
};

struct OpV4f_Rec
{
	int d[13];
	OpV4f_Rec(const OpV4f_Rec &o) throw();	// 0x9f4960
};

template void allocator<OpV4f_Cf>::construct<OpV4f_Cf &>(OpV4f_Cf *, OpV4f_Cf &);
template void allocator<OpV4f_Rec>::construct<OpV4f_Rec &>(OpV4f_Rec *, OpV4f_Rec &);

//==================================================================
// string::replace over a different byte iterator, vector<bool> iter_swap, 2-string pair
//==================================================================
typedef vector<unsigned char>::iterator OpV4f_ByteIt;

template string &string::replace<OpV4f_ByteIt>(string::const_iterator, string::const_iterator, OpV4f_ByteIt, OpV4f_ByteIt);

template void std::iter_swap<vector<bool>::iterator, vector<bool>::iterator>(vector<bool>::iterator, vector<bool>::iterator);

void OpV4f_usePair(string &a, string &b)	// NOTE: placeholder name (forces instances)
{
	pair<string, string> p(move(a), move(b));
}

//==================================================================
// scalar (pointer) element: _Rotate and swap
//==================================================================
struct OpV4f_Node;

void OpV4f_useNode(OpV4f_Node **a, OpV4f_Node **b, OpV4f_Node **c)	// NOTE: placeholder name (forces instances)
{
	rotate(a, b, c);
	swap(*a, *b);
}

//==================================================================
// std::string elements sorted with a predicate
//==================================================================
typedef bool (*OpV4f_PredS)(const string &, const string &);

void OpV4f_useStrings(string *a, string *b, string *c, OpV4f_PredS p)	// NOTE: placeholder name (forces instances)
{
	pop_heap(a, b);
	pop_heap(a, b, p);
	_Med3(a, b, c, p);
}
