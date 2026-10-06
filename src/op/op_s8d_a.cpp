// op_s8d: serialization / STL template instances (0x9dc8a0-0x9ebbe0). Placeholder names.
// NOTE: placeholder names
#include <vector>
#include <string>
#include <istream>
#include <ostream>
using namespace std;

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name

struct OpS8d_Pair16	// NOTE: placeholder name
{
	int a,b,c,d;
	OpS8d_Pair16();	// 0x40b100
	void read(istream &stream);	// 0x40b450
};

template <class T> void OpS8d_readStructs(istream &stream, vector<T> &v)	// NOTE: placeholder name
{
	T item;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(item);
		v.back().read(stream);
		count--;
	}
}

template void OpS8d_readStructs<OpS8d_Pair16>(istream &stream, vector<OpS8d_Pair16> &v);
