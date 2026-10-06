// op_q5: binary stream helper instances (placeholder names)
#include <istream>
#include <ostream>
using namespace std;

template <class T> void readBinary(istream &stream, T *value)	// NOTE: placeholder name
{
	stream.read((char*)value,sizeof(T));
}

template <class T> void writeBinary(ostream &stream, T *value)	// NOTE: placeholder name
{
	stream.write((char*)value,sizeof(T));
}

template void readBinary<bool>(istream &stream, bool *value);
template void writeBinary<bool>(ostream &stream, bool *value);
template void readBinary<int>(istream &stream, int *value);
template void writeBinary<int>(ostream &stream, int *value);
template void readBinary<__int64>(istream &stream, __int64 *value);
