// op_r6: std::vector instantiations over placeholder element types
// NOTE: placeholder names; kind flags: C = ctor + copy ctor, A = operator=, D = dtor (user-provided); size in bytes
#include <vector>
using namespace std;

struct OpR6_KC_4_0
{
	int m0;
	OpR6_KC_4_0();
	OpR6_KC_4_0(const OpR6_KC_4_0 &o);
};
template class std::vector<OpR6_KC_4_0>;

struct OpR6_KC_4_1
{
	int m0;
	OpR6_KC_4_1();
	OpR6_KC_4_1(const OpR6_KC_4_1 &o);
};
template class std::vector<OpR6_KC_4_1>;

struct OpR6_KC_8_0
{
	int m0;
	int m4;
	OpR6_KC_8_0();
	OpR6_KC_8_0(const OpR6_KC_8_0 &o);
};
template class std::vector<OpR6_KC_8_0>;

struct OpR6_KC_12_0
{
	int m0;
	int m4;
	int m8;
	OpR6_KC_12_0();
	OpR6_KC_12_0(const OpR6_KC_12_0 &o);
};
template class std::vector<OpR6_KC_12_0>;

struct OpR6_KC_12_1
{
	int m0;
	int m4;
	int m8;
	OpR6_KC_12_1();
	OpR6_KC_12_1(const OpR6_KC_12_1 &o);
};
template class std::vector<OpR6_KC_12_1>;

struct OpR6_KC_16_0
{
	int m0;
	int m4;
	int m8;
	int m12;
	OpR6_KC_16_0();
	OpR6_KC_16_0(const OpR6_KC_16_0 &o);
};
template class std::vector<OpR6_KC_16_0>;

struct OpR6_KC_16_1
{
	int m0;
	int m4;
	int m8;
	int m12;
	OpR6_KC_16_1();
	OpR6_KC_16_1(const OpR6_KC_16_1 &o);
};
template class std::vector<OpR6_KC_16_1>;

struct OpR6_KC_36_0
{
	int m0;
	int m4;
	int m8;
	int m12;
	int m16;
	int m20;
	int m24;
	int m28;
	int m32;
	OpR6_KC_36_0();
	OpR6_KC_36_0(const OpR6_KC_36_0 &o);
};
template class std::vector<OpR6_KC_36_0>;

struct OpR6_KC_64_0
{
	int m0;
	int m4;
	int m8;
	int m12;
	int m16;
	int m20;
	int m24;
	int m28;
	int m32;
	int m36;
	int m40;
	int m44;
	int m48;
	int m52;
	int m56;
	int m60;
	OpR6_KC_64_0();
	OpR6_KC_64_0(const OpR6_KC_64_0 &o);
};
template class std::vector<OpR6_KC_64_0>;

struct OpR6_KC_84_0
{
	int m0;
	int m4;
	int m8;
	int m12;
	int m16;
	int m20;
	int m24;
	int m28;
	int m32;
	int m36;
	int m40;
	int m44;
	int m48;
	int m52;
	int m56;
	int m60;
	int m64;
	int m68;
	int m72;
	int m76;
	int m80;
	OpR6_KC_84_0();
	OpR6_KC_84_0(const OpR6_KC_84_0 &o);
};
template class std::vector<OpR6_KC_84_0>;

