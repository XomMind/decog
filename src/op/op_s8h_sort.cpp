// op_s8h: std (VS2010) sort/heap/rotate internals over placeholder element types
// NOTE: placeholder names; types are inferred from the instance bodies in COGMIND.exe
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

//==================================================================
// 4-byte element with member operator< (0x9f5830)
//==================================================================
struct OpS8h_TB
{
	unsigned m0;
	bool operator<(OpS8h_TB o) const;
};

typedef bool (*OpS8h_PredB)(OpS8h_TB, OpS8h_TB);

template void std::_Med3<OpS8h_TB *>(OpS8h_TB *, OpS8h_TB *, OpS8h_TB *);
template void std::_Adjust_heap<OpS8h_TB *, int, OpS8h_TB>(OpS8h_TB *, int, int, OpS8h_TB &&);
template void std::_Push_heap<OpS8h_TB *, int, OpS8h_TB>(OpS8h_TB *, int, int, OpS8h_TB &&);
template void std::_Pop_heap<OpS8h_TB *, int, OpS8h_TB>(OpS8h_TB *, OpS8h_TB *, OpS8h_TB *, OpS8h_TB &&, int *);
template void std::_Pop_heap_0<OpS8h_TB *, OpS8h_TB>(OpS8h_TB *, OpS8h_TB *, OpS8h_TB *);
template void std::_Pop_heap<OpS8h_TB *>(OpS8h_TB *, OpS8h_TB *);

template void std::_Med3<OpS8h_TB *, OpS8h_PredB>(OpS8h_TB *, OpS8h_TB *, OpS8h_TB *, OpS8h_PredB);
template void std::_Adjust_heap<OpS8h_TB *, int, OpS8h_TB, OpS8h_PredB>(OpS8h_TB *, int, int, OpS8h_TB &&, OpS8h_PredB);
template void std::_Push_heap<OpS8h_TB *, int, OpS8h_TB, OpS8h_PredB>(OpS8h_TB *, int, int, OpS8h_TB &&, OpS8h_PredB);
template void std::_Pop_heap<OpS8h_TB *, int, OpS8h_TB, OpS8h_PredB>(OpS8h_TB *, OpS8h_TB *, OpS8h_TB *, OpS8h_TB &&, OpS8h_PredB, int *);
template void std::_Pop_heap_0<OpS8h_TB *, OpS8h_TB, OpS8h_PredB>(OpS8h_TB *, OpS8h_TB *, OpS8h_PredB, OpS8h_TB *);
template void std::_Pop_heap<OpS8h_TB *, OpS8h_PredB>(OpS8h_TB *, OpS8h_TB *, OpS8h_PredB);

template void std::_Rotate<OpS8h_TB *>(OpS8h_TB *, OpS8h_TB *, OpS8h_TB *, random_access_iterator_tag);
template void std::_Rotate<OpS8h_TB *, int, OpS8h_TB>(OpS8h_TB *, OpS8h_TB *, OpS8h_TB *, int *, OpS8h_TB *);

//==================================================================
// 4-byte element (pointer), predicate sorts only
//==================================================================
struct OpS8h_TAe;
typedef OpS8h_TAe *OpS8h_TA;
typedef bool (*OpS8h_PredA)(OpS8h_TA, OpS8h_TA);

template void std::_Med3<OpS8h_TA *, OpS8h_PredA>(OpS8h_TA *, OpS8h_TA *, OpS8h_TA *, OpS8h_PredA);
template void std::_Adjust_heap<OpS8h_TA *, int, OpS8h_TA, OpS8h_PredA>(OpS8h_TA *, int, int, OpS8h_TA &&, OpS8h_PredA);
template void std::_Push_heap<OpS8h_TA *, int, OpS8h_TA, OpS8h_PredA>(OpS8h_TA *, int, int, OpS8h_TA &&, OpS8h_PredA);
template void std::_Pop_heap<OpS8h_TA *, int, OpS8h_TA, OpS8h_PredA>(OpS8h_TA *, OpS8h_TA *, OpS8h_TA *, OpS8h_TA &&, OpS8h_PredA, int *);
template void std::_Pop_heap_0<OpS8h_TA *, OpS8h_TA, OpS8h_PredA>(OpS8h_TA *, OpS8h_TA *, OpS8h_PredA, OpS8h_TA *);
template void std::_Pop_heap<OpS8h_TA *, OpS8h_PredA>(OpS8h_TA *, OpS8h_TA *, OpS8h_PredA);
template void std::_Rotate<OpS8h_TA *, int, OpS8h_TA>(OpS8h_TA *, OpS8h_TA *, OpS8h_TA *, int *, OpS8h_TA *);
template OpS8h_TA *std::_Move_backward<OpS8h_TA *, OpS8h_TA *>(OpS8h_TA *, OpS8h_TA *, OpS8h_TA *, _Nonscalar_ptr_iterator_tag);

//==================================================================
// std::string elements
//==================================================================
typedef bool (*OpS8h_PredS)(const string &, const string &);

template void std::_Med3<string *>(string *, string *, string *);
template void std::_Adjust_heap<string *, int, string>(string *, int, int, string &&);
template void std::_Push_heap<string *, int, string>(string *, int, int, string &&);
template void std::_Pop_heap<string *, int, string>(string *, string *, string *, string &&, int *);
template void std::_Pop_heap_0<string *, string>(string *, string *, string *);
template void std::_Pop_heap<string *>(string *, string *);

template void std::_Med3<string *, OpS8h_PredS>(string *, string *, string *, OpS8h_PredS);
template void std::_Adjust_heap<string *, int, string, OpS8h_PredS>(string *, int, int, string &&, OpS8h_PredS);
template void std::_Push_heap<string *, int, string, OpS8h_PredS>(string *, int, int, string &&, OpS8h_PredS);
template void std::_Pop_heap<string *, int, string, OpS8h_PredS>(string *, string *, string *, string &&, OpS8h_PredS, int *);
template void std::_Pop_heap_0<string *, string, OpS8h_PredS>(string *, string *, OpS8h_PredS, string *);
template void std::_Pop_heap<string *, OpS8h_PredS>(string *, string *, OpS8h_PredS);

template string *std::_Move_backward<string *, string *>(string *, string *, string *, _Nonscalar_ptr_iterator_tag);
template int std::distance<string *>(string *, string *);

//==================================================================
// 16-byte element with copy-assignment at 0x40b130
//==================================================================
struct OpS8h_A16
{
	char pad[16];
	OpS8h_A16(const OpS8h_A16 &o);
	OpS8h_A16 &operator=(const OpS8h_A16 &o);
};

template void std::_Rotate<OpS8h_A16 *>(OpS8h_A16 *, OpS8h_A16 *, OpS8h_A16 *, random_access_iterator_tag);
template void std::_Rotate<OpS8h_A16 *, int, OpS8h_A16>(OpS8h_A16 *, OpS8h_A16 *, OpS8h_A16 *, int *, OpS8h_A16 *);
template void std::iter_swap<OpS8h_A16 *, OpS8h_A16 *>(OpS8h_A16 *, OpS8h_A16 *);
template void std::swap<OpS8h_A16>(OpS8h_A16 &, OpS8h_A16 &);
template int std::distance<OpS8h_A16 *>(OpS8h_A16 *, OpS8h_A16 *);

//==================================================================
// 12-byte element with copy ctor at 0x454300
//==================================================================
struct OpS8h_A12
{
	int m0;
	int m4;
	int m8;
	OpS8h_A12(const OpS8h_A12 &o);
};

template void std::iter_swap<OpS8h_A12 *, OpS8h_A12 *>(OpS8h_A12 *, OpS8h_A12 *);
template void std::swap<OpS8h_A12>(OpS8h_A12 &, OpS8h_A12 &);
