// op_u7_stl: VS2010 std template instances in 0x9b0000-0x9bf000 of COGMIND.exe (Beta 17.1).
// NOTE: placeholder element types (OpU7_T...) where the real type is unknown
#include <vector>
#include <string>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

template void std::vector<XColor>::_Tidy();	// 0x9be310
template std::vector<XColor>::~vector();	// 0x9b3da0
template void std::vector<XColor>::_Construct_n(unsigned int, const XColor *);	// 0x9be170
template std::wstring &std::wstring::append(unsigned int, wchar_t);	// 0x9bbe70
template void std::wstring::_Tidy(bool, unsigned int);	// 0x9bbfe0
