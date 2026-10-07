// team_d_64: serialize member of the 0x130-byte record written by OpQ5_writePointer<OpQ5_T9d9660>
// NOTE: class and member names are placeholders; element types of the vectors are placeholders
// (only their serializer instantiations matter).
#include <vector>
#include <ostream>
using namespace std;

template <class T> void writeBinary(ostream &stream, T *value);
template <class T> void OpQ5_writePointer(ostream &stream, T *&p);	// NOTE: placeholder name
template <class T> void OpQ5_writeElements(ostream &stream, vector<T> &v);	// NOTE: placeholder name
template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v);	// NOTE: placeholder name

struct OpQ5_U9d0840 { int a; int b; };	// NOTE: placeholder element layout
struct OpQ5_U9d9600 { int a; int b; };	// NOTE: placeholder element layout
struct OpQ5_T9d8cf0;
struct OpQ5_T9d8d50;
struct OpQ5_T9d8d90;
struct OpQ5_T9d8dd0;
struct OpQ5_T9d8e10;

struct Pair64	// NOTE: placeholder name (OpU1_Point)
{
	int a;
	int b;

	void write(ostream &stream);
};

struct PairPair64	// NOTE: placeholder name (written by Calls_40b420::delegate)
{
	Pair64 a;
	Pair64 b;

	void write(ostream &stream);
};

struct IntBox64	// NOTE: placeholder name (OpC_IntBox)
{
	int value;

	void write(ostream &stream);
};

class Record64	// NOTE: placeholder name and layout
{
public:
	IntBox64				unknown000;
	unsigned int			unknown004;
	unsigned int			unknown008;
	unsigned int			unknown00c;
	Pair64					unknown010;
	Pair64					unknown018;
	IntBox64				unknown020;
	vector<OpQ5_U9d0840>	unknown024;
	unsigned int			unknown034;
	unsigned int			unknown038;
	unsigned int			unknown03c;
	IntBox64				unknown040;
	unsigned int			unknown044;
	unsigned int			unknown048;
	unsigned int			unknown04c;
	IntBox64				unknown050;
	bool					unknown054;
	bool					unknown055;
	bool					unknown056;
	IntBox64				unknown058;
	bool					unknown05c;
	unsigned int			unknown060;
	unsigned int			unknown064;
	unsigned int			unknown068;
	vector<OpQ5_U9d0840>	unknown06c;
	bool					unknown07c;
	PairPair64				unknown080;
	vector<OpQ5_U9d0840>	unknown090;
	unsigned int			unknown0a0;
	PairPair64				unknown0a4;
	IntBox64				unknown0b4;
	IntBox64				unknown0b8;
	unsigned int			unknown0bc;
	unsigned int			unknown0c0;
	unsigned int			unknown0c4;
	unsigned int			unknown0c8;
	unsigned int			unknown0cc;
	unsigned int			unknown0d0;
	IntBox64				unknown0d4;
	unsigned int			unknown0d8;
	vector<OpQ5_U9d9600>	unknown0dc;
	unsigned int			unknown0ec;
	vector<OpQ5_T9d8cf0 *>	unknown0f0;
	unsigned int			unknown100;
	unsigned int			unknown104;
	unsigned int			unknown108;
	unsigned int			unknown10c;
	bool					unknown110;
	OpQ5_T9d8d50			*unknown114;
	OpQ5_T9d8d90			*unknown118;
	OpQ5_T9d8dd0			*unknown11c;
	vector<OpQ5_T9d8e10 *>	unknown120;

	void serialize(ostream &stream);	// NOTE: placeholder name (0x5804e0)
};

void Record64::serialize(ostream &stream)
{
	unknown000.write(stream);
	writeBinary(stream,&unknown004);
	writeBinary(stream,&unknown008);
	writeBinary(stream,&unknown00c);
	unknown010.write(stream);
	unknown018.write(stream);
	unknown020.write(stream);
	OpQ5_writeElements(stream,unknown024);
	writeBinary(stream,&unknown034);
	writeBinary(stream,&unknown038);
	writeBinary(stream,&unknown03c);
	unknown040.write(stream);
	writeBinary(stream,&unknown044);
	writeBinary(stream,&unknown048);
	writeBinary(stream,&unknown04c);
	unknown050.write(stream);
	writeBinary(stream,&unknown054);
	writeBinary(stream,&unknown055);
	writeBinary(stream,&unknown056);
	unknown058.write(stream);
	writeBinary(stream,&unknown05c);
	writeBinary(stream,&unknown060);
	writeBinary(stream,&unknown064);
	writeBinary(stream,&unknown068);
	OpQ5_writeElements(stream,unknown06c);
	writeBinary(stream,&unknown07c);
	unknown080.write(stream);
	OpQ5_writeElements(stream,unknown090);
	writeBinary(stream,&unknown0a0);
	unknown0a4.write(stream);
	unknown0b4.write(stream);
	unknown0b8.write(stream);
	writeBinary(stream,&unknown0bc);
	writeBinary(stream,&unknown0c0);
	writeBinary(stream,&unknown0c4);
	writeBinary(stream,&unknown0c8);
	writeBinary(stream,&unknown0cc);
	writeBinary(stream,&unknown0d0);
	unknown0d4.write(stream);
	writeBinary(stream,&unknown0d8);
	OpQ5_writeElements(stream,unknown0dc);
	writeBinary(stream,&unknown0ec);
	OpQ5_writeObjects(stream,unknown0f0);
	writeBinary(stream,&unknown100);
	writeBinary(stream,&unknown104);
	if (unknown108 > 1)
		unknown108 = 1;
	writeBinary(stream,&unknown108);
	writeBinary(stream,&unknown10c);
	writeBinary(stream,&unknown110);
	OpQ5_writePointer(stream,unknown114);
	OpQ5_writePointer(stream,unknown118);
	OpQ5_writePointer(stream,unknown11c);
	OpQ5_writeObjects(stream,unknown120);
}
