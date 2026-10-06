// op_t4_a: functions in 0x68e000-0x702000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
using namespace std;

template <class T> void writeBinary(ostream &stream, T *value)	// NOTE: placeholder name
{
	stream.write((char*)value,sizeof(T));
}

template <class T> void readBinary(istream &stream, T *value)	// NOTE: placeholder name
{
	stream.read((char*)value,sizeof(T));
}

struct OpQ5_U9d2090
{
	int pad;
};

void OpQ1_writeStringVector(ostream &out, vector<string> *list);	// NOTE: placeholder name (0x409770)
void OpQ1_readStringVector(istream &in, vector<string> *list);	// NOTE: placeholder name (0x4097e0)
template <class T> void OpS8a_writeRawVector(ostream &stream, vector<T> &v);	// NOTE: placeholder name (0x9d2130)
template <class T> void OpQ5_writeVectors(ostream &stream, vector< vector<T> > &v);	// NOTE: placeholder name
template <class T> void OpQ5_readVectors(istream &stream, vector< vector<T> > &v);	// NOTE: placeholder name
void OpR4b_readVector9cf5e0(istream &stream, vector<int> &v);	// NOTE: placeholder name

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(const Point &p);	// 0x46ca50
	void unknown40a330(istream &stream);	// NOTE: placeholder name
	void unknown40a370(ostream &stream);	// NOTE: placeholder name
};

class HProp
{
	int	ID;
public:
	HProp();
	void unknown9cfa90(ostream &stream);	// NOTE: placeholder name
	void unknown9cfaf0(istream &stream);	// NOTE: placeholder name
};

class OpT4_Marker	// NOTE: placeholder name
{
public:
	OpT4_Marker(istream &stream);	// 0x6c1440
	void write(ostream &stream);	// 0x6c15d0

	Point pos;
	HProp unknown8;
	bool unknownc;
	bool unknownd;
	bool unknowne;
	int unknown10;
	HProp unknown14;
	HProp unknown18;
	int unknown1c;
	vector<int> list20;
	vector<int> list30;
	vector<string> list40;
	vector< vector<OpQ5_U9d2090> > list50;
};

OpT4_Marker::OpT4_Marker(istream &stream)
{
	pos.unknown40a330(stream);
	unknown8.unknown9cfaf0(stream);
	readBinary(stream,&unknownc);
	readBinary(stream,&unknownd);
	readBinary(stream,&unknowne);
	readBinary(stream,&unknown10);
	unknown14.unknown9cfaf0(stream);
	unknown18.unknown9cfaf0(stream);
	readBinary(stream,&unknown1c);
	OpR4b_readVector9cf5e0(stream,list20);
	OpR4b_readVector9cf5e0(stream,list30);
	OpQ1_readStringVector(stream,&list40);
	OpQ5_readVectors(stream,list50);
}

void OpT4_Marker::write(ostream &stream)
{
	pos.unknown40a370(stream);
	unknown8.unknown9cfa90(stream);
	writeBinary(stream,&unknownc);
	writeBinary(stream,&unknownd);
	writeBinary(stream,&unknowne);
	writeBinary(stream,&unknown10);
	unknown14.unknown9cfa90(stream);
	unknown18.unknown9cfa90(stream);
	writeBinary(stream,&unknown1c);
	OpS8a_writeRawVector(stream,list20);
	OpS8a_writeRawVector(stream,list30);
	OpQ1_writeStringVector(stream,&list40);
	OpQ5_writeVectors(stream,list50);
}
