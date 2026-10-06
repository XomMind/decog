// op_r6: std::vector instantiations over placeholder element types
// NOTE: placeholder names; kind flags: C = ctor + copy ctor, A = operator=, D = dtor (user-provided); size in bytes
#include <vector>
using namespace std;

struct OpR6_KCA_16_0
{
	int m0;
	int m4;
	int m8;
	int m12;
	OpR6_KCA_16_0();
	OpR6_KCA_16_0(const OpR6_KCA_16_0 &o);
	OpR6_KCA_16_0 &operator=(const OpR6_KCA_16_0 &o);
};
template class std::vector<OpR6_KCA_16_0>;

struct OpR6_KCA_16_1
{
	int m0;
	int m4;
	int m8;
	int m12;
	OpR6_KCA_16_1();
	OpR6_KCA_16_1(const OpR6_KCA_16_1 &o);
	OpR6_KCA_16_1 &operator=(const OpR6_KCA_16_1 &o);
};
template class std::vector<OpR6_KCA_16_1>;

struct OpR6_KCA_20_0
{
	int m0;
	int m4;
	int m8;
	int m12;
	int m16;
	OpR6_KCA_20_0();
	OpR6_KCA_20_0(const OpR6_KCA_20_0 &o);
	OpR6_KCA_20_0 &operator=(const OpR6_KCA_20_0 &o);
};
template class std::vector<OpR6_KCA_20_0>;

