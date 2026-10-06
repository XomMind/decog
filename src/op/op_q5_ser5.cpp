// op_q5: container/serialization helper template instances (placeholder names)
// NOTE: placeholder names
#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include "../util/rng.h"
#include "../util/stringutil.h"
using namespace std;

extern RNG rng;	// 0xd30908
void logError(string location, string message);	// NOTE: placeholder name


extern RNG rng_d20d00;	// NOTE: placeholder name (0xd20d00)
void OpQ5_readString(istream &stream, string *value);	// NOTE: placeholder name (0x4096f0)
template <class T> void readBinary(istream &stream, T *value);
template <class T> void OpQ5_readObjectsChance(istream &stream, vector<T*> &v)	// NOTE: placeholder name
{
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		if (rng_d20d00.chance(3))
		{
			int type;
			readBinary(stream,&type);
			switch (type)
			{
			case 0:
				{
					int value;
					readBinary(stream,&value);
				}
				break;
			case 1:
				{
					string text;
					OpQ5_readString(stream,&text);
				}
				break;
			}
		}
		v.push_back(new T(stream));
		count--;
	}
}

struct OpQ5_U9e0e50
{
	char pad[368];
	OpQ5_U9e0e50(istream &stream);
};

struct OpQ5_U9e0f90
{
	char pad[224];
	OpQ5_U9e0f90(istream &stream);
};

struct OpQ5_U9e10d0
{
	char pad[676];
	OpQ5_U9e10d0(istream &stream);
};

struct OpQ5_U9e1260
{
	char pad[556];
	OpQ5_U9e1260(istream &stream);
};

template void OpQ5_readObjectsChance<OpQ5_U9e0e50>(istream &stream, vector<OpQ5_U9e0e50*> &v);
template void OpQ5_readObjectsChance<OpQ5_U9e0f90>(istream &stream, vector<OpQ5_U9e0f90*> &v);
template void OpQ5_readObjectsChance<OpQ5_U9e10d0>(istream &stream, vector<OpQ5_U9e10d0*> &v);
template void OpQ5_readObjectsChance<OpQ5_U9e1260>(istream &stream, vector<OpQ5_U9e1260*> &v);
