// op_y8: STL instantiations (iostream family) in 0x9b0000-0x9d0000
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

template class std::basic_istringstream<char>;
template class std::basic_stringstream<char>;
template class std::basic_ostringstream<char>;
template class std::basic_stringbuf<char>;
template class std::basic_filebuf<char>;
