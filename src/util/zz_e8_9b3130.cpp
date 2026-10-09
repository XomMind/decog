// zz_e8_9b3130: the 8-byte trivially copyable element family of std::vector whose operator= is 0x9b3130 (used by
// op_u8c.cpp and op_s8f.cpp); the exe keeps it apart from lead/stl_a.cpp's E8_0 family (reserve 0x9c5de0,
// push_back 0x9b9940, _Uninit_copy 0x9fb760, _Uninit_fill_n 0x9f3350 call into this family's helpers).
// NOTE: placeholder name and layout. In src/util/ so it links last (see AGENTS.md on LTCG nothrow inference).
#include <vector>
using namespace std;

struct E8_9b3130	// NOTE: placeholder name (same definition as in op_u8c.cpp and op_s8f.cpp)
{
	char pad[8];
	E8_9b3130 &operator=(const E8_9b3130 &e);	// NOTE: the exe assigns these elements with a call (_Copy_impl 0x9efd30); copies stay inline (construct 0x9f05e0)
};

template class std::vector<E8_9b3130>;
