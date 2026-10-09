// zz_explosive64: one 64-byte, non-trivially-destructible element family of std::vector that the exe instantiates
// (_Tidy 0x9be5e0 -> _Destroy 0x9c4200 -> _Destroy_range 0x9e5290 / 0x9f19a0 -> _Dest_val 0x9fa570 -> destroy 0x9fcba0
// -> _Destroy 0x9ffad0 -> scalar deleting dtor).
// These rows used to be reached through `struct HExplosive { char pad[0x40]; ~HExplosive(); }` in op_s1c.cpp, op_r1g.cpp
// and cc_r2_30.cpp, which is the wrong type there: the exe destroys those vectors with the 4-byte handle family
// (vector<HExplosive> dtor 0x9b7e00). NOTE: placeholder name and layout (real element type unknown).
// Lives in src/util/ so it links last (see AGENTS.md: a new TU can change LTCG nothrow inference for later files).
#include <vector>
using namespace std;

struct Explosive64	// NOTE: placeholder name
{
	char pad[0x40];	// NOTE: placeholder layout
	~Explosive64();
};

template class std::vector<Explosive64>;
