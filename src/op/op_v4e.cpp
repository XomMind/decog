// op_v4e: std (VS2010) vector range-insert instances over placeholder element types, 0x9f5000-0x9fd000
// NOTE: placeholder names; OpV4e_* element types stand for unrecovered game types of that size/kind
#include <vector>
using namespace std;

struct OpV4e_S16	// NOTE: placeholder name; 16-byte trivially copyable element
{
	int a;
	int b;
	int c;
	int d;
};

typedef vector<OpV4e_S16>::iterator OpV4e_S16It;

template void std::vector<OpV4e_S16>::insert<OpV4e_S16It>(vector<OpV4e_S16>::const_iterator, OpV4e_S16It, OpV4e_S16It);	// 0x9efb10

struct OpV4e_W4	// NOTE: placeholder name; 4-byte trivially copyable element
{
	int v;
};

struct OpT8d_H4;	// defined in op_t8d.cpp (only pointers used here)

template vector<OpV4e_W4>::iterator std::vector<OpV4e_W4>::emplace<OpV4e_W4 &>(vector<OpV4e_W4>::const_iterator, OpV4e_W4 &);	// 0x9f82f0
template vector<OpT8d_H4 *>::iterator std::vector<OpT8d_H4 *>::emplace<OpT8d_H4 *&>(vector<OpT8d_H4 *>::const_iterator, OpT8d_H4 *&);	// 0x9f8a90

#include <algorithm>

struct OpV4e_R8a	// NOTE: placeholder name; element type for iterator helper instances
{
	int x;
	int y;
};

struct OpV4e_R8b	// NOTE: placeholder name; element type for iterator helper instances
{
	int x;
	int y;
};

struct OpV4e_R8c	// NOTE: placeholder name; element type for iterator helper instances
{
	int x;
	int y;
};

typedef vector<OpV4e_R8a>::iterator OpV4e_R8aIt;
typedef vector<OpV4e_R8b>::iterator OpV4e_R8bIt;

template void std::_Rotate<OpV4e_R8c *>(OpV4e_R8c *, OpV4e_R8c *, OpV4e_R8c *, random_access_iterator_tag);	// 0x9f85f0
template int std::distance<OpV4e_R8aIt>(OpV4e_R8aIt, OpV4e_R8aIt);	// 0x9f7540
template int std::distance<OpV4e_R8bIt>(OpV4e_R8bIt, OpV4e_R8bIt);	// 0x9f8630
