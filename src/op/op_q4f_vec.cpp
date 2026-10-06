// op_q4f: explicit std::vector<T> instantiations over placeholder element types (shape-matching)
// NOTE: all element types are placeholders (size + which special members are user-provided).
#include <vector>
#include <string>
using namespace std;

template<int S, int I> struct OpQ4f_K101
{
	char pad[S];
	OpQ4f_K101();
	OpQ4f_K101(const OpQ4f_K101 &e);
	~OpQ4f_K101();
};
template<int S, int I> struct OpQ4f_K010
{
	char pad[S];
	OpQ4f_K010 &operator=(const OpQ4f_K010 &e);
};
template<int S, int I> struct OpQ4f_K001
{
	char pad[S];
	~OpQ4f_K001();
};
template<int S, int I> struct OpQ4f_K011
{
	char pad[S];
	OpQ4f_K011 &operator=(const OpQ4f_K011 &e);
	~OpQ4f_K011();
};
template class std::vector<OpQ4f_K101<8, 0> >;
template class std::vector<OpQ4f_K010<8, 0> >;
template class std::vector<OpQ4f_K001<8, 0> >;
template class std::vector<OpQ4f_K011<8, 0> >;
template class std::vector<OpQ4f_K101<12, 0> >;
template class std::vector<OpQ4f_K010<12, 0> >;
template class std::vector<OpQ4f_K001<12, 0> >;
template class std::vector<OpQ4f_K011<12, 0> >;
template class std::vector<OpQ4f_K101<16, 0> >;
template class std::vector<OpQ4f_K010<16, 0> >;
template class std::vector<OpQ4f_K001<16, 0> >;
template class std::vector<OpQ4f_K011<16, 0> >;
template class std::vector<OpQ4f_K101<20, 0> >;
template class std::vector<OpQ4f_K010<20, 0> >;
template class std::vector<OpQ4f_K001<20, 0> >;
template class std::vector<OpQ4f_K011<20, 0> >;
template class std::vector<OpQ4f_K101<24, 0> >;
template class std::vector<OpQ4f_K010<24, 0> >;
template class std::vector<OpQ4f_K001<24, 0> >;
template class std::vector<OpQ4f_K011<24, 0> >;
template class std::vector<OpQ4f_K101<28, 0> >;
template class std::vector<OpQ4f_K010<28, 0> >;
template class std::vector<OpQ4f_K001<28, 0> >;
template class std::vector<OpQ4f_K011<28, 0> >;
template class std::vector<OpQ4f_K101<32, 0> >;
template class std::vector<OpQ4f_K010<32, 0> >;
template class std::vector<OpQ4f_K001<32, 0> >;
template class std::vector<OpQ4f_K011<32, 0> >;
template class std::vector<OpQ4f_K101<36, 0> >;
template class std::vector<OpQ4f_K010<36, 0> >;
template class std::vector<OpQ4f_K001<36, 0> >;
template class std::vector<OpQ4f_K011<36, 0> >;
template class std::vector<OpQ4f_K101<40, 0> >;
template class std::vector<OpQ4f_K010<40, 0> >;
template class std::vector<OpQ4f_K001<40, 0> >;
template class std::vector<OpQ4f_K011<40, 0> >;
template class std::vector<OpQ4f_K101<44, 0> >;
template class std::vector<OpQ4f_K010<44, 0> >;
template class std::vector<OpQ4f_K001<44, 0> >;
template class std::vector<OpQ4f_K011<44, 0> >;
template class std::vector<OpQ4f_K101<48, 0> >;
template class std::vector<OpQ4f_K010<48, 0> >;
template class std::vector<OpQ4f_K001<48, 0> >;
template class std::vector<OpQ4f_K011<48, 0> >;
