// op_x5_adv: std::advance instances over placeholder element types (placeholder names)
#include <vector>
#include <iterator>
using namespace std;
struct OpX5_A1 { int v; };
struct OpX5_A2 { int v; };
struct OpX5_A3 { int v; };
struct OpX5_A4 { int v; };
struct OpX5_A5 { int v; };
struct OpX5_A6 { int v; };
struct OpX5_A7 { int v; };
template void std::advance<vector<OpX5_A1>::iterator, int>(vector<OpX5_A1>::iterator &where, int off);
template void std::advance<vector<OpX5_A2>::iterator, int>(vector<OpX5_A2>::iterator &where, int off);
template void std::advance<vector<OpX5_A3>::iterator, int>(vector<OpX5_A3>::iterator &where, int off);
template void std::advance<vector<OpX5_A4>::iterator, int>(vector<OpX5_A4>::iterator &where, int off);
template void std::advance<vector<OpX5_A5>::iterator, int>(vector<OpX5_A5>::iterator &where, int off);
template void std::advance<vector<OpX5_A6>::iterator, int>(vector<OpX5_A6>::iterator &where, int off);
template void std::advance<vector<OpX5_A7>::iterator, int>(vector<OpX5_A7>::iterator &where, int off);
