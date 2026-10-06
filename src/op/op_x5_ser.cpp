// op_x5_ser: serialization methods, 0x80f000-0xa044d0 (placeholder names)
// NOTE: placeholder names
#include <vector>
#include <string>
#include <istream>
using namespace std;

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name
void OpT8a_readInts(istream &in, vector<int> &v);	// NOTE: placeholder name, defined in op_t8a.cpp

struct OpQ5_U9e1210;
struct OpQ5_U9ed690;
struct OpQ5_U9dfd70;
template <class T> void OpQ5_readReferences(istream &stream, vector<T*> &v, vector<T*> &list);	// NOTE: placeholder name

struct OpX5_Reader9d3230	// NOTE: placeholder name
{
	vector<OpQ5_U9e1210*> refs;
	vector<int> ints;
	int value;
	void read(istream &stream, vector<OpQ5_U9e1210*> &list);
};

void OpX5_Reader9d3230::read(istream &stream, vector<OpQ5_U9e1210*> &list)
{
	OpQ5_readReferences(stream,refs,list);
	OpT8a_readInts(stream,ints);
	readBinary(stream,&value);
}

struct OpX5_Reader9d32e0	// NOTE: placeholder name
{
	vector<OpQ5_U9ed690*> refs;
	vector<int> ints;
	int value;
	void read(istream &stream, vector<OpQ5_U9ed690*> &list);
};

void OpX5_Reader9d32e0::read(istream &stream, vector<OpQ5_U9ed690*> &list)
{
	OpQ5_readReferences(stream,refs,list);
	OpT8a_readInts(stream,ints);
	readBinary(stream,&value);
}


void OpX5_readReferenceLists(istream &stream, vector<vector<OpQ5_U9dfd70*> > &v, vector<OpQ5_U9dfd70*> &list)	// NOTE: placeholder name
{
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(vector<OpQ5_U9dfd70*>());
		OpQ5_readReferences(stream,v.back(),list);
		count--;
	}
}
