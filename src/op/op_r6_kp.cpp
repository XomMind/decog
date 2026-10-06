// op_r6: std::vector instantiations over placeholder element types
// NOTE: placeholder names; kind flags: C = ctor + copy ctor, A = operator=, D = dtor (user-provided); size in bytes
#include <vector>
using namespace std;

struct OpR6_KP_8_0
{
	int m0;
	int m4;
};
template class std::vector<OpR6_KP_8_0>;

