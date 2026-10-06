// op_t8f: std (VS2010) template instances and helpers in 0x9fd000-0xa044d0, over placeholder element types
// NOTE: placeholder names (OpT8f_*); types are inferred from the instance bodies in COGMIND.exe
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

//==================================================================
// std::string built from iterator ranges (vector<char>, istreambuf_iterator)
//==================================================================
typedef istreambuf_iterator<char>	OpT8f_StreamIt;
typedef vector<char>::iterator		OpT8f_CharIt;

template string& string::_Replace<OpT8f_StreamIt>(string::const_iterator, string::const_iterator, OpT8f_StreamIt, OpT8f_StreamIt, input_iterator_tag);
template void string::_Construct<OpT8f_StreamIt>(OpT8f_StreamIt, OpT8f_StreamIt, input_iterator_tag);
template void string::_Construct<OpT8f_CharIt>(OpT8f_CharIt, OpT8f_CharIt, forward_iterator_tag);

void OpT8f_forceStringCtors(OpT8f_StreamIt a, OpT8f_StreamIt b, OpT8f_CharIt c, OpT8f_CharIt d)	// NOTE: placeholder name (forces basic_string ctor instances)
{
	string s1(a, b);
	string s2(c, d);
}
