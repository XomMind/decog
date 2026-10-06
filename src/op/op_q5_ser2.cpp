// op_q5: more serialization/container helper template instances (placeholder names)
// NOTE: placeholder names
#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name


template <class T> void OpQ5_eraseStep(vector<T> &v, int &index)	// NOTE: placeholder name
{
	v.erase(v.begin()+index);
	index--;
}

template <class T> void OpQ5_eraseAt(vector<T> &v, int index)	// NOTE: placeholder name
{
	v.erase(v.begin()+index);
}

template <class T> int OpQ5_randomIndex(vector<T> &v)	// NOTE: placeholder name
{
	return rng.rangeInt(0,v.size() - 1);
}

template <class T> void OpQ5_deleteBack(vector<T*> &v)	// NOTE: placeholder name
{
	delete v.back();
	v.pop_back();
}

template <class T> void OpQ5_readReference(istream &stream, T *&p, vector<T*> &list);	// NOTE: placeholder name
template <class T> void OpQ5_readReferences(istream &stream, vector<T*> &v, vector<T*> &list)	// NOTE: placeholder name
{
	T *p;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		OpQ5_readReference(stream,p,list);
		v.push_back(p);
		count--;
	}
}

template <class T> void OpQ5_writeElements(ostream &stream, vector<T> &v)	// NOTE: placeholder name
{
	unsigned int count = v.size();
	stream.write((char*)&count,sizeof(count));
	for (unsigned int i = 0; i < count; i++)
		v[i].write(stream);
}

template <class T> void OpQ5_writeVector(ostream &stream, vector<T> &v);	// NOTE: placeholder name
template <class T> void OpQ5_writeVectors(ostream &stream, vector< vector<T> > &v)	// NOTE: placeholder name
{
	unsigned int count = v.size();
	stream.write((char*)&count,sizeof(count));
	for (unsigned int i = 0; i < count; i++)
		OpQ5_writeVector(stream,v[i]);
}

struct OpQ5_U9d3d90
{
	int pad;
};

struct OpQ5_U9d5030
{
	int pad;
};

struct OpQ5_U9d6440
{
	int pad;
};

struct OpQ5_U9d7300
{
	int pad;
};

struct OpQ5_U9de4b0
{
	int pad;
};

struct OpQ5_U9de8a0
{
	int pad;
};

struct OpQ5_U9e2670
{
	int pad;
};

struct OpQ5_U9e26c0
{
	int pad;
};

struct OpQ5_U9e2a40
{
	int pad;
};

struct OpQ5_U9e2a90
{
	int pad;
};

struct OpQ5_U9e2ae0
{
	int pad;
};

struct OpQ5_U9cfab0
{
	int pad;
};

struct OpQ5_U9d4ff0
{
	int pad;
};

struct OpQ5_U9d5190
{
	int pad;
};

struct OpQ5_U9d9f80
{
	int pad;
};

struct OpQ5_U9da940
{
	int pad;
};

struct OpQ5_U9dae00
{
	int pad;
};

struct OpQ5_U9de1d0
{
	int pad;
};

struct OpQ5_U9de470
{
	int pad;
};

struct OpQ5_U9de6b0
{
	int pad;
};

struct OpQ5_U9d5310
{
	int pad;
};

struct OpQ5_U9d9230
{
	int pad;
};

struct OpQ5_U9d9b20
{
	int pad;
};

struct OpQ5_U9da8b0
{
	int pad;
};

struct OpQ5_U9db3e0
{
	int pad;
};

struct OpQ5_U9db420
{
	int pad;
};

struct OpQ5_U9db950
{
	int pad;
};

struct OpQ5_U9db990
{
	int pad;
};

struct OpQ5_U9dbbe0
{
	int pad;
};

struct OpQ5_U9d2620
{
	int pad;
	~OpQ5_U9d2620();
};

struct OpQ5_U9dae60
{
	int pad;
	~OpQ5_U9dae60();
};

struct OpQ5_U9dbc20
{
	int pad;
	~OpQ5_U9dbc20();
};

struct OpQ5_U9df2e0
{
	int pad;
	~OpQ5_U9df2e0();
};

struct OpQ5_U9e32e0
{
	int pad;
	~OpQ5_U9e32e0();
};

struct OpQ5_U9d63f0
{
	int pad;
};

struct OpQ5_U9d8200
{
	int pad;
};

struct OpQ5_U9dfbe0
{
	int pad;
};

struct OpQ5_U9dfd70
{
	int pad;
};

struct OpQ5_U9e0630
{
	int pad;
};

struct OpQ5_U9e1210
{
	int pad;
};

struct OpQ5_U9ed690
{
	int pad;
};

struct OpQ5_U9d0840
{
	int pad;
	void write(ostream &stream);
};

struct OpQ5_U9d25c0
{
	int pad;
	void write(ostream &stream);
};

struct OpQ5_U9d9600
{
	int pad;
	void write(ostream &stream);
};

struct OpQ5_U9dada0
{
	int pad;
	void write(ostream &stream);
};

struct OpQ5_U9dbee0
{
	int pad;
	void write(ostream &stream);
};

struct OpQ5_U9df330
{
	int pad;
	void write(ostream &stream);
};

struct OpQ5_U9d1d20
{
	int pad;
};

struct OpQ5_U9d2190
{
	int pad;
};

struct OpQ5_U9da850
{
	int pad;
};

struct OpQ5_U9dbf40
{
	int pad;
};

struct OpQ5_U9dbfa0
{
	int pad;
};

struct OpQ5_U9dc500
{
	int pad;
};

template void OpQ5_eraseStep<OpQ5_U9d3d90>(vector<OpQ5_U9d3d90> &v, int &index);
template void OpQ5_eraseStep<OpQ5_U9d5030>(vector<OpQ5_U9d5030> &v, int &index);
template void OpQ5_eraseStep<OpQ5_U9d6440>(vector<OpQ5_U9d6440> &v, int &index);
template void OpQ5_eraseStep<OpQ5_U9d7300>(vector<OpQ5_U9d7300> &v, int &index);
template void OpQ5_eraseStep<OpQ5_U9de4b0>(vector<OpQ5_U9de4b0> &v, int &index);
template void OpQ5_eraseStep<OpQ5_U9de8a0>(vector<OpQ5_U9de8a0> &v, int &index);
template void OpQ5_eraseStep<OpQ5_U9e2670>(vector<OpQ5_U9e2670> &v, int &index);
template void OpQ5_eraseStep<OpQ5_U9e26c0>(vector<OpQ5_U9e26c0> &v, int &index);
template void OpQ5_eraseStep<OpQ5_U9e2a40>(vector<OpQ5_U9e2a40> &v, int &index);
template void OpQ5_eraseStep<OpQ5_U9e2a90>(vector<OpQ5_U9e2a90> &v, int &index);
template void OpQ5_eraseStep<OpQ5_U9e2ae0>(vector<OpQ5_U9e2ae0> &v, int &index);
template void OpQ5_eraseAt<OpQ5_U9cfab0>(vector<OpQ5_U9cfab0> &v, int index);
template void OpQ5_eraseAt<OpQ5_U9d4ff0>(vector<OpQ5_U9d4ff0> &v, int index);
template void OpQ5_eraseAt<OpQ5_U9d5190>(vector<OpQ5_U9d5190> &v, int index);
template void OpQ5_eraseAt<OpQ5_U9d9f80>(vector<OpQ5_U9d9f80> &v, int index);
template void OpQ5_eraseAt<OpQ5_U9da940>(vector<OpQ5_U9da940> &v, int index);
template void OpQ5_eraseAt<OpQ5_U9dae00>(vector<OpQ5_U9dae00> &v, int index);
template void OpQ5_eraseAt<OpQ5_U9de1d0>(vector<OpQ5_U9de1d0> &v, int index);
template void OpQ5_eraseAt<OpQ5_U9de470>(vector<OpQ5_U9de470> &v, int index);
template void OpQ5_eraseAt<OpQ5_U9de6b0>(vector<OpQ5_U9de6b0> &v, int index);
template int OpQ5_randomIndex<OpQ5_U9d5310>(vector<OpQ5_U9d5310> &v);
template int OpQ5_randomIndex<OpQ5_U9d9230>(vector<OpQ5_U9d9230> &v);
template int OpQ5_randomIndex<OpQ5_U9d9b20>(vector<OpQ5_U9d9b20> &v);
template int OpQ5_randomIndex<OpQ5_U9da8b0>(vector<OpQ5_U9da8b0> &v);
template int OpQ5_randomIndex<OpQ5_U9db3e0>(vector<OpQ5_U9db3e0> &v);
template int OpQ5_randomIndex<OpQ5_U9db420>(vector<OpQ5_U9db420> &v);
template int OpQ5_randomIndex<OpQ5_U9db950>(vector<OpQ5_U9db950> &v);
template int OpQ5_randomIndex<OpQ5_U9db990>(vector<OpQ5_U9db990> &v);
template int OpQ5_randomIndex<OpQ5_U9dbbe0>(vector<OpQ5_U9dbbe0> &v);
template void OpQ5_deleteBack<OpQ5_U9d2620>(vector<OpQ5_U9d2620*> &v);
template void OpQ5_deleteBack<OpQ5_U9dae60>(vector<OpQ5_U9dae60*> &v);
template void OpQ5_deleteBack<OpQ5_U9dbc20>(vector<OpQ5_U9dbc20*> &v);
template void OpQ5_deleteBack<OpQ5_U9df2e0>(vector<OpQ5_U9df2e0*> &v);
template void OpQ5_deleteBack<OpQ5_U9e32e0>(vector<OpQ5_U9e32e0*> &v);
template void OpQ5_readReferences<OpQ5_U9d63f0>(istream &stream, vector<OpQ5_U9d63f0*> &v, vector<OpQ5_U9d63f0*> &list);
template void OpQ5_readReferences<OpQ5_U9d8200>(istream &stream, vector<OpQ5_U9d8200*> &v, vector<OpQ5_U9d8200*> &list);
template void OpQ5_readReferences<OpQ5_U9dfbe0>(istream &stream, vector<OpQ5_U9dfbe0*> &v, vector<OpQ5_U9dfbe0*> &list);
template void OpQ5_readReferences<OpQ5_U9dfd70>(istream &stream, vector<OpQ5_U9dfd70*> &v, vector<OpQ5_U9dfd70*> &list);
template void OpQ5_readReferences<OpQ5_U9e0630>(istream &stream, vector<OpQ5_U9e0630*> &v, vector<OpQ5_U9e0630*> &list);
template void OpQ5_readReferences<OpQ5_U9e1210>(istream &stream, vector<OpQ5_U9e1210*> &v, vector<OpQ5_U9e1210*> &list);
template void OpQ5_readReferences<OpQ5_U9ed690>(istream &stream, vector<OpQ5_U9ed690*> &v, vector<OpQ5_U9ed690*> &list);
template void OpQ5_writeElements<OpQ5_U9d0840>(ostream &stream, vector<OpQ5_U9d0840> &v);
template void OpQ5_writeElements<OpQ5_U9d25c0>(ostream &stream, vector<OpQ5_U9d25c0> &v);
template void OpQ5_writeElements<OpQ5_U9d9600>(ostream &stream, vector<OpQ5_U9d9600> &v);
template void OpQ5_writeElements<OpQ5_U9dada0>(ostream &stream, vector<OpQ5_U9dada0> &v);
template void OpQ5_writeElements<OpQ5_U9dbee0>(ostream &stream, vector<OpQ5_U9dbee0> &v);
template void OpQ5_writeElements<OpQ5_U9df330>(ostream &stream, vector<OpQ5_U9df330> &v);
template void OpQ5_writeVectors<OpQ5_U9d1d20>(ostream &stream, vector< vector<OpQ5_U9d1d20> > &v);
template void OpQ5_writeVectors<OpQ5_U9d2190>(ostream &stream, vector< vector<OpQ5_U9d2190> > &v);
template void OpQ5_writeVectors<OpQ5_U9da850>(ostream &stream, vector< vector<OpQ5_U9da850> > &v);
template void OpQ5_writeVectors<OpQ5_U9dbf40>(ostream &stream, vector< vector<OpQ5_U9dbf40> > &v);
template void OpQ5_writeVectors<OpQ5_U9dbfa0>(ostream &stream, vector< vector<OpQ5_U9dbfa0> > &v);
template void OpQ5_writeVectors<OpQ5_U9dc500>(ostream &stream, vector< vector<OpQ5_U9dc500> > &v);
