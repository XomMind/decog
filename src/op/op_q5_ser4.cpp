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


template <class T> void OpQ5_readVec(istream &stream, vector<T> &v);	// NOTE: placeholder name
template <class T> void OpQ5_readVectors(istream &stream, vector< vector<T> > &v)	// NOTE: placeholder name
{
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(vector<T>());
		OpQ5_readVec(stream,v.back());
		count--;
	}
}

template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
template <class T> void OpQ5_readObjectVectors(istream &stream, vector< vector<T*> > &v)	// NOTE: placeholder name
{
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(vector<T*>());
		OpQ5_readObjects(stream,v.back(),0);
		count--;
	}
}

template <class T> void OpQ5_eraseRange(vector<T> &v, int first, int last)	// NOTE: placeholder name
{
	v.erase(v.begin()+first,v.begin()+last+1);
}

template <class T> void OpQ5_appendVector(vector<T> &v, vector<T> &other)	// NOTE: placeholder name
{
	v.insert(v.end(),other.begin(),other.end());
}

template <class T> void OpQ5_prependVector(vector<T> &v, vector<T> &other)	// NOTE: placeholder name
{
	v.insert(v.begin(),other.begin(),other.end());
}

template <class T> void OpQ5_moveElement(vector<T> &v, unsigned int from, unsigned int to)	// NOTE: placeholder name
{
	if (from == to)
		return;
	else if (from < to)
		rotate(v.begin()+from,v.begin()+from+1,v.begin()+to+1);
	else
		rotate(v.begin()+to,v.begin()+from,v.begin()+from+1);
}

struct OpQ5_U9d1c80
{
	int pad;
};

struct OpQ5_U9d2090
{
	int pad;
};

struct OpQ5_U9da6b0
{
	int pad;
};

struct OpQ5_U9dd4b0
{
	int pad;
};

struct OpQ5_U9d93c0
{
	int pad;
};

struct OpQ5_U9ddb90
{
	int pad;
};

struct OpQ5_U9dfa00
{
	int pad;
};

struct OpQ5_U9d3e90
{
	int pad;
};

struct OpQ5_U9d53f0
{
	int pad;
};

struct OpQ5_U9d9530
{
	int pad;
};

struct OpQ5_U9e25a0
{
	int pad;
};

struct OpQ5_U9d0300
{
	int pad;
};

struct OpQ5_U9d49c0
{
	int pad;
};

struct OpQ5_U9d7f20
{
	int pad;
};

struct OpQ5_U9d9140
{
	int pad;
};

struct OpQ5_U9db8c0
{
	int pad;
};

struct OpQ5_U9e3400
{
	int pad;
};

struct OpQ5_U9d46b0
{
	int pad;
};

struct OpQ5_U9de0b0
{
	int pad;
};

struct OpQ5_U9e2fc0
{
	int pad;
};

struct OpQ5_U9d5760
{
	int pad;
};

struct OpQ5_U9d9020
{
	int pad;
};

struct OpQ5_U9da1f0
{
	int pad;
};

struct OpQ5_U9e2340
{
	int pad;
};

struct OpQ5_U9e2ce0
{
	int pad;
};

template void OpQ5_readVectors<OpQ5_U9d1c80>(istream &stream, vector< vector<OpQ5_U9d1c80> > &v);
template void OpQ5_readVectors<OpQ5_U9d2090>(istream &stream, vector< vector<OpQ5_U9d2090> > &v);
template void OpQ5_readVectors<OpQ5_U9da6b0>(istream &stream, vector< vector<OpQ5_U9da6b0> > &v);
template void OpQ5_readVectors<OpQ5_U9dd4b0>(istream &stream, vector< vector<OpQ5_U9dd4b0> > &v);
template void OpQ5_readObjectVectors<OpQ5_U9d93c0>(istream &stream, vector< vector<OpQ5_U9d93c0*> > &v);
template void OpQ5_readObjectVectors<OpQ5_U9ddb90>(istream &stream, vector< vector<OpQ5_U9ddb90*> > &v);
template void OpQ5_readObjectVectors<OpQ5_U9dfa00>(istream &stream, vector< vector<OpQ5_U9dfa00*> > &v);
template void OpQ5_eraseRange<OpQ5_U9d3e90>(vector<OpQ5_U9d3e90> &v, int first, int last);
template void OpQ5_eraseRange<OpQ5_U9d53f0>(vector<OpQ5_U9d53f0> &v, int first, int last);
template void OpQ5_eraseRange<OpQ5_U9d9530>(vector<OpQ5_U9d9530> &v, int first, int last);
template void OpQ5_eraseRange<OpQ5_U9e25a0>(vector<OpQ5_U9e25a0> &v, int first, int last);
template void OpQ5_appendVector<OpQ5_U9d0300>(vector<OpQ5_U9d0300> &v, vector<OpQ5_U9d0300> &other);
template void OpQ5_appendVector<OpQ5_U9d49c0>(vector<OpQ5_U9d49c0> &v, vector<OpQ5_U9d49c0> &other);
template void OpQ5_appendVector<OpQ5_U9d7f20>(vector<OpQ5_U9d7f20> &v, vector<OpQ5_U9d7f20> &other);
template void OpQ5_appendVector<OpQ5_U9d9140>(vector<OpQ5_U9d9140> &v, vector<OpQ5_U9d9140> &other);
template void OpQ5_appendVector<OpQ5_U9db8c0>(vector<OpQ5_U9db8c0> &v, vector<OpQ5_U9db8c0> &other);
template void OpQ5_appendVector<OpQ5_U9e3400>(vector<OpQ5_U9e3400> &v, vector<OpQ5_U9e3400> &other);
template void OpQ5_prependVector<OpQ5_U9d46b0>(vector<OpQ5_U9d46b0> &v, vector<OpQ5_U9d46b0> &other);
template void OpQ5_prependVector<OpQ5_U9de0b0>(vector<OpQ5_U9de0b0> &v, vector<OpQ5_U9de0b0> &other);
template void OpQ5_prependVector<OpQ5_U9e2fc0>(vector<OpQ5_U9e2fc0> &v, vector<OpQ5_U9e2fc0> &other);
template void OpQ5_moveElement<OpQ5_U9d5760>(vector<OpQ5_U9d5760> &v, unsigned int from, unsigned int to);
template void OpQ5_moveElement<OpQ5_U9d9020>(vector<OpQ5_U9d9020> &v, unsigned int from, unsigned int to);
template void OpQ5_moveElement<OpQ5_U9da1f0>(vector<OpQ5_U9da1f0> &v, unsigned int from, unsigned int to);
template void OpQ5_moveElement<OpQ5_U9e2340>(vector<OpQ5_U9e2340> &v, unsigned int from, unsigned int to);
template void OpQ5_moveElement<OpQ5_U9e2ce0>(vector<OpQ5_U9e2ce0> &v, unsigned int from, unsigned int to);
