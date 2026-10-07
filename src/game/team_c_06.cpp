// team_c_06: std sort/heap internals over the op_u8d placeholder types (H4, int with predicate)
// (rows already in config/mapping.d/op_u8d.csv; this file provides the code they name).
#include <vector>
#include <algorithm>
using namespace std;

struct H4	// NOTE: placeholder name; 4-byte element type with operator< (0x9f5830)
{
	unsigned m0;
	bool operator<(H4 o) const;
};

typedef bool (*H4Pred)(H4, H4);
typedef bool (*IntPred)(int, int);

template void std::_Median<H4 *>(H4 *, H4 *, H4 *);
template void std::_Adjust_heap<H4 *, int, H4>(H4 *, int, int, H4 &&);
template void std::_Pop_heap<H4 *>(H4 *, H4 *);
template void std::_Med3<H4 *>(H4 *, H4 *, H4 *);
template void std::_Rotate<H4 *>(H4 *, H4 *, H4 *, random_access_iterator_tag);
template void std::_Adjust_heap<int *, int, int, IntPred>(int *, int, int, int &&, IntPred);
template void std::_Pop_heap<H4 *, H4Pred>(H4 *, H4 *, H4Pred);
template void std::_Med3<int *, IntPred>(int *, int *, int *, IntPred);
template void std::_Med3<H4 *, H4Pred>(H4 *, H4 *, H4 *, H4Pred);
