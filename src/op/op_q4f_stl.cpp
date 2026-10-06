// op_q4f: STL instantiations in 0x9b0000-0x9d0000 (fstream family)
#include <fstream>
#include <string>

template class std::basic_ofstream<char>;
template class std::basic_ifstream<char>;
#include <iterator>
template class std::istreambuf_iterator<char>;
