// team_c_05: explicit std::vector<T> instantiations over the op_y8 placeholder element types
// (rows already in config/mapping.d/op_y8.csv; this file provides the code they name).
// NOTE: all element types are placeholders: Y8_<size>_<flags>_<n>, plain POD of that size.
#include <vector>
#include <ostream>
using namespace std;
struct Y8_4_00_0 { char pad[4]; };
struct Y8_c_00_0 { char pad[12]; };
struct Y8_10_00_0 { char pad[16]; };
struct Y8_10_14_0 { char pad[16]; };
struct Y8_10_14_1 { char pad[16]; };
struct Y8_40_00_0 { char pad[0x40]; };
struct Y8_54_00_0 { char pad[0x54]; };
struct Y8_6c_00_0 { char pad[0x6c]; };
template class std::vector<Y8_4_00_0>;
template class std::vector<Y8_c_00_0>;
template class std::vector<Y8_10_00_0>;
template class std::vector<Y8_10_14_0>;
template class std::vector<Y8_10_14_1>;
template class std::vector<Y8_40_00_0>;
template class std::vector<Y8_54_00_0>;
template class std::vector<Y8_6c_00_0>;

// operator<<(ostream &, char) (0x9cd0c0)
template basic_ostream<char, char_traits<char> > &std::operator<< <char_traits<char> >(basic_ostream<char, char_traits<char> > &, char);
