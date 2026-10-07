// team_d_04: dynamic initializers (and atexit destructors) of colour, handle, protobuf and other class globals
// NOTE: all global names are placeholders carrying the exe data address; types come from the
// constructor/destructor callees.
#include <vector>
#include <string>
#include <istream>
#include <ostream>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();
	XColor(int r_, int g_, int b_);
	XColor(const XColor &c);
};

class Prop;

class HProp	// NOTE: placeholder layout
{
	int ID;
public:
	HProp();
	bool isValid() const;	// NOTE: folded with HItem::isValid
	Prop *operator->() const;
};

struct LogColorEntry	// NOTE: placeholder layout
{
	int a[2];

	LogColorEntry();
};

namespace google { namespace protobuf { namespace internal {
class RepeatedPtrFieldBase	// NOTE: placeholder layout (constructor is protected in the exe)
{
	void **elements_;
	int current_size_;
	int allocated_size_;
	int total_size_;
public:
	RepeatedPtrFieldBase();
};
} } }
using google::protobuf::internal::RepeatedPtrFieldBase;

class Unknown_438ab0_4489f0	// NOTE: placeholder name (constructor sub_438ab0, destructor Wrapper_4489f0::cleanup)
{
	int pad[4];
public:
	Unknown_438ab0_4489f0();
	~Unknown_438ab0_4489f0();
};

class Unknown_4588d0_439630	// NOTE: placeholder name (constructor sub_4588d0, destructor sub_439630)
{
	int pad[4];
public:
	Unknown_4588d0_439630();
	~Unknown_4588d0_439630();
};

class Unknown_43aee0_446260	// NOTE: placeholder name (constructor OpR1d_Report::OpR1d_Report, destructor sub_446260)
{
	int pad[4];
public:
	Unknown_43aee0_446260();
	~Unknown_43aee0_446260();
};

class Unknown_448e60_448ed0	// NOTE: placeholder name (constructor Calls_448e60::delegate, destructor sub_448ed0)
{
	int pad[4];
public:
	Unknown_448e60_448ed0();
	~Unknown_448e60_448ed0();
};

class Unknown_4493c0_449420	// NOTE: placeholder name (constructor Calls_4493c0::delegate, destructor sub_449420)
{
	int pad[4];
public:
	Unknown_4493c0_449420();
	~Unknown_4493c0_449420();
};

class Unknown_454340_4543b0	// NOTE: placeholder name (constructor sub_454340, destructor sub_4543b0)
{
	int pad[4];
public:
	Unknown_454340_4543b0();
	~Unknown_454340_4543b0();
};

class Unknown_456200_456230	// NOTE: placeholder name (constructor Calls_456200::delegate, destructor Calls_456230::delegate)
{
	int pad[4];
public:
	Unknown_456200_456230();
	~Unknown_456200_456230();
};

class Unknown_45eab0_45ebd0	// NOTE: placeholder name (constructor sub_45eab0, destructor sub_45ebd0)
{
	int pad[4];
public:
	Unknown_45eab0_45ebd0();
	~Unknown_45eab0_45ebd0();
};

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;

	Point(int v);	// NOTE: placeholder name (0x409990: sets both coordinates)
	Point(const Point &p);
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor
};

struct PointB { int x; int y; };	// NOTE: placeholder element type (vector at +0xa8)
struct VE_2190 { int a[4]; };		// NOTE: placeholder element type (vector of vectors at +0x21c)

struct Range8	// NOTE: placeholder name (8-byte value pair)
{
	int a;
	int b;

	void serialize_40bf20(ostream &stream);	// NOTE: folded with Point::serialize_40bf20
	void read(istream &stream);				// NOTE: placeholder name (OpS1e_Range::read)
	int randomInRange();					// NOTE: folded with Point::randomInRange_40c130
};

struct Pair8	// NOTE: placeholder name (OpU1_Point)
{
	int a;
	int b;

	void write(ostream &stream);
	void read(istream &stream);
};

struct IntBox4	// NOTE: placeholder name (OpC_IntBox)
{
	int value;

	void write(ostream &stream);
	void read(istream &stream);
};

struct EntityRecord04	// NOTE: placeholder name and layout
{
	char		pad000[0x13c];
	vector<int>	unknown13c;
	char		pad14c[0x1dc - 0x14c];
	int			unknown1dc;
};
extern vector<EntityRecord04 *> entityRecords04_d25de0;	// NOTE: placeholder name
extern vector<int> list_d39458;	// NOTE: placeholder name
extern vector<int> list_d21b10;	// NOTE: placeholder name

class DataLoader04	// NOTE: placeholder name (OpT5_DataLoader at 0xcefaa8)
{
public:
	void unknown7929d0();	// NOTE: placeholder name
	void unknown792c50();	// NOTE: placeholder name
};
extern DataLoader04 *dataLoader04_cefaa8;	// NOTE: placeholder name

template <class T> void writeBinary(ostream &stream, T *value);
template <class T> void readBinary(istream &stream, T *value);
template <class T> void OpS8a_writeRawVector(ostream &stream, vector<T> &v);	// NOTE: placeholder name
template <class T> void OpQ5_writePointer(ostream &stream, T *&p);	// NOTE: placeholder name
template <class T> void OpQ5_writeElements(ostream &stream, vector<T> &v);	// NOTE: placeholder name
template <class T> void OpQ5_writeVectors(ostream &stream, vector< vector<T> > &v);	// NOTE: placeholder name
template <class T> void OpQ5_readPointer(istream &stream, T *&p);	// NOTE: placeholder name
template <class T> void OpQ5_readReference(istream &stream, T *&p, vector<T*> &list);	// NOTE: placeholder name
template <class T> void OpU8_readStructs(istream &stream, vector<T> &v);	// NOTE: placeholder name
template <class T> void OpQ5_readVectors(istream &stream, vector< vector<T> > &v);	// NOTE: placeholder name
void OpS8c_writeOptionalInt(ostream &stream, int *p);	// NOTE: placeholder name
void OpQ1_writeString(ostream &out, string text);
void OpQ1_readString(istream &in, string *text);	// NOTE: placeholder name (0x4096f0)
void OpQ1_writeStringVectorList(ostream &out, vector<vector<string> > *lists);	// NOTE: placeholder name (0x409890)
void OpQ1_readStringVectorList(istream &in, vector<vector<string> > *lists);	// NOTE: placeholder name (0x4098f0)
void OpT8a_readInts(istream &stream, vector<int> &v);	// NOTE: placeholder name
void OpS8a_readP8s(istream &stream, vector<Point> &v);	// NOTE: placeholder name

class HExplosive	// NOTE: placeholder layout
{
	int ID;
};

struct VE_KCDA_16_1 { int a[4]; };	// NOTE: placeholder vector element type

struct Owned_45f830 { ~Owned_45f830(); };	// NOTE: placeholder name (scalar deleting destructor 0x45f830)
struct StoredEntity { ~StoredEntity(); };	// NOTE: placeholder layout (scalar deleting destructor 0x45f860)

class HEntity;

class EntityAI	// NOTE: placeholder layout
{
public:
	int unknown5b4710(HEntity e, int a, int b, int c, int d);	// NOTE: placeholder name
	int getBehavior();					// NOTE: placeholder name (folded getter 0x9b8f00)
	void unknown44bef0(int value);		// NOTE: placeholder name
};

struct PropData	// NOTE: placeholder name and layout
{
	char	pad000[0x8c];
	int		unknown8c;
};

class Prop	// NOTE: placeholder layout
{
public:
	PropData *getData();				// NOTE: placeholder name (folded getter 0x9b8f00)
	void unknown45ce10(int a, int b, int c, HProp p);	// NOTE: placeholder name
};

class Cell	// NOTE: placeholder layout
{
public:
	bool unknown45d480();				// NOTE: placeholder name
	HProp getProp();
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	bool contains(const Point &p);		// NOTE: placeholder name (0x9b43b0)
	bool inBounds(int x, int y);		// NOTE: placeholder name (0x9b45c0)
	Cell **atPoint(const Point &p);		// NOTE: folded with OpX5_Array2D<int>::atPoint
	Cell **at(int x, int y);			// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

class Item	// NOTE: placeholder layout
{
public:
	int unknown4578a0();				// NOTE: placeholder name (folded getter)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class HItem	// NOTE: placeholder layout
{
	int ID;
public:
	Item *operator->() const;
};

class Entity	// NOTE: placeholder layout
{
public:
	const string &getName();			// NOTE: placeholder name (folded getter 0x416f40)
	Point &getPosition();
	EntityAI *getAI();					// 0x45b590
	int getField490840(int index);		// NOTE: placeholder name
	void unknown637bb0();				// NOTE: placeholder name
	void unknown5dea60(int value);		// NOTE: placeholder name
	int unknown5c7d30();				// NOTE: placeholder name
	vector<HItem> *getInventoryList();
	void changePos(const Point &p, int a);
	void unknown45b090(int value);		// NOTE: placeholder name
	void unknown45b0b0();				// NOTE: placeholder name
	int unknown5c92e0(int value);		// NOTE: placeholder name
	int unknown5ca670();				// NOTE: placeholder name
	void unknown45b240(int value);		// NOTE: placeholder name
	void unknown5ded70(int value);		// NOTE: placeholder name
};

class HEntity : public IntBox4	// NOTE: placeholder layout (an IntBox4 for serialization)
{
public:
	Entity *operator->() const;
	void reset();
	bool operator==(HEntity other) const;
};

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getPlayer();
	bool unknown4631f0(HEntity e);		// NOTE: placeholder name
	int getTurn();
	bool isVisible(const Point &p);		// 0x4631c0
	bool unknown716940(const Point &from, const Point &to, Entity *e, int *length);	// NOTE: placeholder name
	bool isReachable(int range, const Point &from, const Point &to);	// NOTE: placeholder name
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
	void unknown734560(HEntity e, int a, int b);	// NOTE: placeholder name
	HItem unknown6c51d0(EntityRecord04 *type, HEntity e, bool a, bool b);	// NOTE: placeholder name
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)

class CMap04	// NOTE: placeholder name (0xcec054)
{
public:
	void unknown808510(const Point &p, int index, vector<Point> *out);	// NOTE: placeholder name
};
extern CMap04 *cmap_cec054;	// NOTE: placeholder name

class Effect04	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class EffectMgr04	// NOTE: placeholder name (0xcefc50)
{
public:
	Effect04 *create();	// NOTE: placeholder name (0x508610)
};
extern EffectMgr04 *effectMgr_cefc50;	// NOTE: placeholder name

extern Point point_d2e20c;	// NOTE: placeholder name
extern vector<int> vec_cf7574;	// NOTE: placeholder name (vector of EntityRecord04 pointers)

bool OpX5_containsRecord(vector<int> &v, int value);	// NOTE: placeholder name
template <class T> void OpV4c_shuffle(vector<T> &v);	// NOTE: placeholder name
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)
EntityRecord04 *OpU8a_randomRec(vector<EntityRecord04 *> &v);	// NOTE: placeholder name
int opR1d_454260(const Point &pos, unsigned int sound);	// NOTE: placeholder name
void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);

HEntity OpD_restoreEntity_690940(StoredEntity *stored, const Point &pos, int a, int b, int c);	// NOTE: placeholder name
void opW5_message(int type, HProp prop, const string &text, int value);	// NOTE: placeholder name
void logEventS_5141b0(int id, const string &a, const string &b, int c, HEntity e, int d);	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
struct Owned_45f890 { ~Owned_45f890(); void unknown672f20(HEntity e, int a, int b, string text); };	// NOTE: placeholder name (scalar deleting destructor 0x45f890)
struct Owned_45c220 { ~Owned_45c220(); };	// NOTE: placeholder name (scalar deleting destructor 0x45c220)

class Unknown_45f320_45f560	// NOTE: placeholder name (constructor sub_45f320, destructor sub_45f560); layout from the destructor
{
public:
	Unknown_45f320_45f560();
	~Unknown_45f320_45f560();
	void serialize(ostream &stream);	// NOTE: placeholder name (0x6919f0)
	void unserialize(istream &stream);	// NOTE: placeholder name (0x691240)
	void unknown69a5b0(bool flag);	// NOTE: placeholder name
	bool unknown69ac10(const Point &loc, Range8 &range, bool flag);	// NOTE: placeholder name

	vector<unsigned int>	unknown000;
	vector<unsigned int>	unknown010;
	Owned_45f830			*unknown020;
	Range8					unknown024;
	EntityRecord04			*unknown02c;
	HEntity					unknown030;
	StoredEntity			*unknown034;
	Range8					unknown038;
	int						unknown040;
	vector<unsigned int>	unknown044;
	vector<unsigned int>	unknown054;
	int						unknown064;
	Owned_45f890			*unknown068;
	int						unknown06c;
	vector<unsigned int>	unknown070;
	Range8					unknown080;
	vector<HExplosive>		unknown088;
	vector<Point>			unknown098;
	vector<Point>			unknown0a8;
	vector<HExplosive>		unknown0b8;
	int						unknown0c8;
	int						unknown0cc;
	int						unknown0d0;
	Range8					unknown0d4;
	vector<HExplosive>		unknown0dc;
	Range8					unknown0ec;
	Range8					unknown0f4;
	IntBox4					unknown0fc;
	string					unknown100;
	int						unknown11c;
	HEntity					unknown120;
	vector<unsigned int>	unknown124;
	Range8					unknown134;
	Pair8					unknown13c;
	Pair8					unknown144;
	int						unknown14c;
	int						unknown150;
	vector<HExplosive>		unknown154;
	vector<Point>			unknown164;
	vector<unsigned int>	unknown174;
	int						unknown184;
	Pair8					unknown188;
	int						unknown190;
	bool					unknown194;
	int						unknown198;
	bool					unknown19c;
	IntBox4					unknown1a0;
	int						unknown1a4;
	int						unknown1a8;
	bool					unknown1ac;
	int						unknown1b0;
	Range8					unknown1b4;
	Range8					unknown1bc;
	bool					unknown1c4;
	int						unknown1c8;
	Owned_45c220			*unknown1cc;
	int						unknown1d0;
	Owned_45c220			*unknown1d4;
	vector<Point>			unknown1d8;
	vector<Point>			unknown1e8;
	vector<HExplosive>		unknown1f8;
	vector<char>			unknown208;
	int						unknown218;
	vector<VE_KCDA_16_1>	unknown21c;
	bool					unknown22c;
	int						unknown230;
	vector<unsigned int>	unknown234;
	vector<unsigned int>	unknown244;
	vector<HExplosive>		unknown254;
	vector<HExplosive>		unknown264;
	vector<HExplosive>		unknown274;
};

Unknown_45f320_45f560::~Unknown_45f320_45f560()
{
	delete unknown020;
	delete unknown034;
	delete unknown068;
	delete unknown1cc;
	delete unknown1d4;
}

#define VINTS(v)	(*(vector<int> *)&(v))	// NOTE: the exe's int-vector helpers take vector<int>
#define VSTRS(v)	((vector<vector<string> > *)&(v))
#define VVEC(v)		(*(vector<vector<VE_2190> > *)&(v))
#define VPTB(v)		(*(vector<PointB> *)&(v))

void Unknown_45f320_45f560::serialize(ostream &stream)
{
	OpS8a_writeRawVector(stream,VINTS(unknown000));
	OpS8a_writeRawVector(stream,VINTS(unknown010));
	OpQ5_writePointer(stream,unknown020);
	unknown024.serialize_40bf20(stream);
	OpS8c_writeOptionalInt(stream,(int *)unknown02c);
	unknown030.write(stream);
	OpQ5_writePointer(stream,unknown034);
	unknown038.serialize_40bf20(stream);
	writeBinary(stream,&unknown040);
	OpS8a_writeRawVector(stream,VINTS(unknown044));
	OpS8a_writeRawVector(stream,VINTS(unknown054));
	writeBinary(stream,&unknown064);
	OpQ5_writePointer(stream,unknown068);
	writeBinary(stream,&unknown06c);
	OpS8a_writeRawVector(stream,VINTS(unknown070));
	unknown080.serialize_40bf20(stream);
	OpQ5_writeElements(stream,unknown088);
	OpQ5_writeElements(stream,unknown098);
	OpQ5_writeElements(stream,VPTB(unknown0a8));
	OpQ5_writeElements(stream,unknown0b8);
	writeBinary(stream,&unknown0c8);
	writeBinary(stream,&unknown0cc);
	writeBinary(stream,&unknown0d0);
	unknown0d4.serialize_40bf20(stream);
	OpQ5_writeElements(stream,unknown0dc);
	unknown0ec.serialize_40bf20(stream);
	unknown0f4.serialize_40bf20(stream);
	unknown0fc.write(stream);
	OpQ1_writeString(stream,unknown100);
	writeBinary(stream,&unknown11c);
	unknown120.write(stream);
	OpS8a_writeRawVector(stream,VINTS(unknown124));
	unknown134.serialize_40bf20(stream);
	unknown13c.write(stream);
	unknown144.write(stream);
	writeBinary(stream,&unknown14c);
	writeBinary(stream,&unknown150);
	OpQ5_writeElements(stream,unknown154);
	OpQ5_writeElements(stream,unknown164);
	OpS8a_writeRawVector(stream,VINTS(unknown174));
	writeBinary(stream,&unknown184);
	unknown188.write(stream);
	writeBinary(stream,&unknown190);
	writeBinary(stream,&unknown194);
	writeBinary(stream,&unknown198);
	writeBinary(stream,&unknown19c);
	unknown1a0.write(stream);
	writeBinary(stream,&unknown1a4);
	writeBinary(stream,&unknown1a8);
	writeBinary(stream,&unknown1ac);
	writeBinary(stream,&unknown1b0);
	unknown1b4.serialize_40bf20(stream);
	unknown1bc.serialize_40bf20(stream);
	writeBinary(stream,&unknown1c4);
	writeBinary(stream,&unknown1c8);
	OpQ5_writePointer(stream,unknown1cc);
	writeBinary(stream,&unknown1d0);
	OpQ5_writePointer(stream,unknown1d4);
	OpQ5_writeElements(stream,unknown1d8);
	OpQ5_writeElements(stream,unknown1e8);
	OpQ5_writeElements(stream,unknown1f8);
	OpQ1_writeStringVectorList(stream,VSTRS(unknown208));
	writeBinary(stream,&unknown218);
	OpQ5_writeVectors(stream,VVEC(unknown21c));
	writeBinary(stream,&unknown22c);
	writeBinary(stream,&unknown230);
	OpS8a_writeRawVector(stream,VINTS(unknown234));
	OpS8a_writeRawVector(stream,VINTS(unknown244));
	OpQ5_writeElements(stream,unknown254);
	OpQ5_writeElements(stream,unknown264);
	OpQ5_writeElements(stream,unknown274);
}

void Unknown_45f320_45f560::unserialize(istream &stream)
{
	unknown000.clear();
	OpT8a_readInts(stream,VINTS(unknown000));
	unknown010.clear();
	OpT8a_readInts(stream,VINTS(unknown010));
	delete unknown020;
	OpQ5_readPointer(stream,unknown020);
	unknown024.read(stream);
	OpQ5_readReference(stream,unknown02c,entityRecords04_d25de0);
	unknown030.read(stream);
	OpQ5_readPointer(stream,unknown034);
	unknown038.read(stream);
	readBinary(stream,&unknown040);
	unknown044.clear();
	OpT8a_readInts(stream,VINTS(unknown044));
	unknown054.clear();
	OpT8a_readInts(stream,VINTS(unknown054));
	readBinary(stream,&unknown064);
	delete unknown068;
	OpQ5_readPointer(stream,unknown068);
	if (unknown068 && list_d39458.empty())
		dataLoader04_cefaa8->unknown7929d0();
	if (0) {}
	readBinary(stream,&unknown06c);
	unknown070.clear();
	OpT8a_readInts(stream,VINTS(unknown070));
	unknown080.read(stream);
	unknown088.clear();
	OpU8_readStructs(stream,unknown088);
	unknown098.clear();
	OpS8a_readP8s(stream,unknown098);
	VPTB(unknown0a8).clear();
	OpU8_readStructs(stream,VPTB(unknown0a8));
	unknown0b8.clear();
	OpU8_readStructs(stream,unknown0b8);
	readBinary(stream,&unknown0c8);
	readBinary(stream,&unknown0cc);
	readBinary(stream,&unknown0d0);
	unknown0d4.read(stream);
	unknown0dc.clear();
	OpU8_readStructs(stream,unknown0dc);
	unknown0ec.read(stream);
	unknown0f4.read(stream);
	unknown0fc.read(stream);
	unknown100.clear();
	OpQ1_readString(stream,&unknown100);
	readBinary(stream,&unknown11c);
	unknown120.read(stream);
	unknown124.clear();
	OpT8a_readInts(stream,VINTS(unknown124));
	unknown134.read(stream);
	unknown13c.read(stream);
	unknown144.read(stream);
	readBinary(stream,&unknown14c);
	readBinary(stream,&unknown150);
	unknown154.clear();
	OpU8_readStructs(stream,unknown154);
	unknown164.clear();
	OpS8a_readP8s(stream,unknown164);
	unknown174.clear();
	OpT8a_readInts(stream,VINTS(unknown174));
	readBinary(stream,&unknown184);
	unknown188.read(stream);
	readBinary(stream,&unknown190);
	readBinary(stream,&unknown194);
	readBinary(stream,&unknown198);
	readBinary(stream,&unknown19c);
	if (unknown19c && list_d21b10.empty())
		dataLoader04_cefaa8->unknown792c50();
	if (0) {}
	unknown1a0.read(stream);
	readBinary(stream,&unknown1a4);
	readBinary(stream,&unknown1a8);
	readBinary(stream,&unknown1ac);
	readBinary(stream,&unknown1b0);
	unknown1b4.read(stream);
	unknown1bc.read(stream);
	readBinary(stream,&unknown1c4);
	readBinary(stream,&unknown1c8);
	OpQ5_readPointer(stream,unknown1cc);
	readBinary(stream,&unknown1d0);
	OpQ5_readPointer(stream,unknown1d4);
	unknown1d8.clear();
	OpS8a_readP8s(stream,unknown1d8);
	unknown1e8.clear();
	OpS8a_readP8s(stream,unknown1e8);
	unknown1f8.clear();
	OpU8_readStructs(stream,unknown1f8);
	VSTRS(unknown208)->clear();
	OpQ1_readStringVectorList(stream,VSTRS(unknown208));
	readBinary(stream,&unknown218);
	VVEC(unknown21c).clear();
	OpQ5_readVectors(stream,VVEC(unknown21c));
	readBinary(stream,&unknown22c);
	readBinary(stream,&unknown230);
	unknown234.clear();
	OpT8a_readInts(stream,VINTS(unknown234));
	unknown244.clear();
	OpT8a_readInts(stream,VINTS(unknown244));
	unknown254.clear();
	OpU8_readStructs(stream,unknown254);
	unknown264.clear();
	OpU8_readStructs(stream,unknown264);
	unknown274.clear();
	OpU8_readStructs(stream,unknown274);
}

extern Unknown_45f320_45f560 unk_cf6888;
extern const float factor_ba442c;	// NOTE: placeholder name (0.1f)

void Unknown_45f320_45f560::unknown69a5b0(bool flag)
{
	if (unknown034 == NULL)
		do {} while (0);
	string name = unknown120->getName();
	Point pos = unknown120->getPosition();
	if (!flag)
		unknown120->unknown637bb0();
	unknown120.reset();
	unknown030 = OpD_restoreEntity_690940(unknown034,pos,0xb,0x17,4);
	delete unknown034;
	unknown034 = NULL;
	unknown030->getAI()->unknown5b4710(world->getPlayer(),-2,1,0,0);
	if (world->unknown4631f0(unknown030))
	{
		string msg = flag ? unknown030->getName() + " reconstitutes true form from the rubble and scrap." : name + " form shifts and reconstitutes itself, revealing true form.";
		opW5_message(0x320,HProp(),msg,0);
		do { logEventS_5141b0(0x91,name,unknown030->getName(),0,unknown030,0); } while (0);
		if (unk_cf6888.unknown02c && unknown030.operator->() && unk_cf6888.unknown030 == unknown030)
			unk_cf6888.unknown068->unknown672f20(unknown030,10,0,name);
	}
	if (flag)
	{
		int penalty = (int)(entityRecords04_d25de0[unknown11c]->unknown1dc * factor_ba442c);
		unknown030->unknown5dea60(OpX5_maxInt(1,unknown030->getField490840(0) - penalty));
		do {} while (0);
	}
}

bool Unknown_45f320_45f560::unknown69ac10(const Point &loc, Range8 &range, bool flag)
{
	unknown184 = 0;
	(Point &)unknown188 = loc;
	unknown190 = world->getTurn();
	unknown194 = flag;
	if (unknown030->getAI()->getBehavior() == 0x17)
		unknown194 = false;
	vector<int> tried;
	for (int i = 0; i < 30; i++)
	{
		int index = range.randomInRange();
		if (OpX5_containsRecord(tried,index))
			continue;
		tried.push_back(index);
		vector<Point> positions;
		cmap_cec054->unknown808510(loc,index,&positions);
		if (!positions.empty())
		{
			OpV4c_shuffle(positions);
			int cost = world->getPlayer()->unknown5c7d30();
			Point choice(-1);
			Point target(-1);
			int d;
			for (unsigned int j = 0; j < positions.size(); j++)
			{
				if (cells_cfd44c.contains(positions[j]) && world->findPlaceableNear(positions[j],positions[j],1) && world->unknown716940(loc,positions[j],unknown030.operator->(),&d) && d <= 0x23)
				{
					if (world->isReachable(cost,loc,positions[j]))
					{
						if (target.x == -1)
							target = positions[j];
					}
					else
					{
						choice = positions[j];
						break;
					}
				}
			}
			if (choice.x == -1 && target.x != -1)
				choice = target;
			if (choice.x != -1)
			{
				Point pos = unknown030->getPosition();
				if (world->isVisible(pos))
				{
					if (unk_cf6888.unknown02c && unknown030.operator->() && unk_cf6888.unknown030 == unknown030)
						unk_cf6888.unknown068->unknown672f20(unknown030,0x10,0,"");
					string text = unknown030->getName() + " shrinks and is drawn into a quantum tunnel.";
					opW5_message(0x320,HProp(),text,0);
					bool valid = true;
					if ((!cells_cfd44c.inBounds(pos.x - 1,pos.y) || (*cells_cfd44c.at(pos.x - 1,pos.y))->unknown45d480())
						&& (!cells_cfd44c.inBounds(pos.x + 1,pos.y) || (*cells_cfd44c.at(pos.x + 1,pos.y))->unknown45d480())
						&& ((cells_cfd44c.inBounds(pos.x,pos.y + 1) && !(*cells_cfd44c.at(pos.x,pos.y + 1))->unknown45d480())
							|| (cells_cfd44c.inBounds(pos.x,pos.y + 1) && !(*cells_cfd44c.at(pos.x,pos.y + 1))->unknown45d480())))
						valid = false;
					int type;
					if (OpU8a_lookup2(valid ? "Blink_Core_Horz" : "Blink_Core_Vert",&type))
						effectMgr_cefc50->create()->init(effectMgr_cefc50,type,pos,point_d2e20c,NULL,NULL,NULL,9,0);
				}
				opR1d_454260(pos,0x10c);
				unknown030->changePos(choice,1);
				unknown030->unknown45b090(0);
				unknown030->unknown45b0b0();
				world->unknown734560(unknown030,-2,0);
				if (flag)
				{
					vector<HItem> *items = unknown030->getInventoryList();
					for (int k = 0; k < items->size(); k++)
					{
						if ((*items)[k]->unknown4578a0() == 3)
						{
							(*items)[k]->unknown57dbe0(0,0,1,1);
							k--;
						}
					}
					EntityRecord04 *rec = OpU8a_randomRec((vector<EntityRecord04 *> &)vec_cf7574);
					for (int n = unknown030->unknown5c92e0(3); n > 0; n--)
						world->unknown6c51d0(rec,unknown030,true,false);
					unknown030->getAI()->unknown44bef0(rec->unknown13c.empty() ? 8 : 0xb);
					unknown030->unknown45b240(unknown030->unknown5ca670());
					unknown030->unknown5ded70(1000);
				}
				vector<Point> adj;
				sweepGetSurroundingCells(pos,adj);
				for (unsigned int m = 0; m < adj.size(); m++)
				{
					if ((*cells_cfd44c.atPoint(adj[m]))->getProp().isValid() && (*cells_cfd44c.atPoint(adj[m]))->getProp()->getData()->unknown8c != 0)
						(*cells_cfd44c.atPoint(adj[m]))->getProp()->unknown45ce10(0,1,0,HProp());
				}
				return true;
			}
		}
	}
	return false;
}

class Unknown_45fae0_45fbd0	// NOTE: placeholder name (constructor sub_45fae0, destructor sub_45fbd0)
{
	int pad[4];
public:
	Unknown_45fae0_45fbd0();
	~Unknown_45fae0_45fbd0();
};

class Unknown_45fe00_45fe80	// NOTE: placeholder name (constructor Calls_45fe00::delegate, destructor sub_45fe80)
{
	int pad[4];
public:
	Unknown_45fe00_45fe80();
	~Unknown_45fe00_45fe80();
};

class Unknown_4c1840	// NOTE: placeholder name (constructor OpW7_PathMoveCost::OpW7_PathMoveCost)
{
	int pad[4];
public:
	Unknown_4c1840();
};

class Unknown_4dbd80	// NOTE: placeholder name (constructor ??0StaticDescriptorInitializer@protobuf_scoresheet_2eproto@@QAE@XZ)
{
	int pad[4];
public:
	Unknown_4dbd80();
};

struct Unknown3	// NOTE: placeholder name (as in cc_r2_24.cpp)
{
	char pad[3];
};

extern Unknown3&	ptr_cf6b24;

XColor	cols_cfe5a8[20];
XColor	col_d31654(8, 8, 8);
LogColorEntry	unks_d01618[31];
XColor	cols_d216f8[11];
XColor	cols_d01714[4] =
{
	XColor(0, 0, 0),
	XColor(65, 65, 65),
	XColor(75, 75, 75),
	XColor(90, 90, 90)
};
RepeatedPtrFieldBase	rpfs_d01a14[3];
RepeatedPtrFieldBase	rpfs_d30234[3];
RepeatedPtrFieldBase	rpf_cf4564;
RepeatedPtrFieldBase	rpf_d358b0;
RepeatedPtrFieldBase	rpf_d31680;
RepeatedPtrFieldBase	rpf_d1e844;
RepeatedPtrFieldBase	rpf_cf27ec;
RepeatedPtrFieldBase	rpf_d1e1c8;
RepeatedPtrFieldBase	rpf_d38464;
RepeatedPtrFieldBase	rpf_cfb78c;
RepeatedPtrFieldBase	rpf_d35e08;
RepeatedPtrFieldBase	rpf_d33be0;
RepeatedPtrFieldBase	rpf_d31690;
RepeatedPtrFieldBase	rpf_d20464;
RepeatedPtrFieldBase	rpf_cf0da8;
RepeatedPtrFieldBase	rpf_d32e00;
RepeatedPtrFieldBase	rpf_d32ebc;
RepeatedPtrFieldBase	rpf_d22f7c;
RepeatedPtrFieldBase	rpf_d2a88c;
RepeatedPtrFieldBase	rpf_d21e48;
RepeatedPtrFieldBase	rpf_d316b4;
RepeatedPtrFieldBase	rpf_d3238c;
RepeatedPtrFieldBase	rpf_d2975c;
XColor	col_d29804(0, 0, 0);
XColor	cols_d329a4[14];
XColor	cols_d29ae0[7];
Unknown_438ab0_4489f0	unk_d338cc;
Unknown_4588d0_439630	unk_d28c54;
Unknown_43aee0_446260	unk_d28c68;
XColor	cols_cf127c[9] =
{
	XColor(20, 20, 20),
	XColor(77, 62, 39),
	XColor(178, 89, 0),
	XColor(51, 41, 26),
	XColor(56, 56, 56),
	XColor(0, 0, 0),
	XColor(165, 42, 42),
	XColor(0, 216, 255),
	XColor(0, 107, 128)
};
XColor	col_d25f68(255, 255, 0);
XColor	col_d223c8(213, 0, 217);
Unknown_448e60_448ed0	unk_d31580;
Unknown_4493c0_449420	unk_d29268;
XColor	cols_cf40ac[9];
XColor	cols_cf1060[10];
Unknown_454340_4543b0	unk_d2d2a0;
XColor	col_d02364;
XColor	col_d349ec;
Unknown_456200_456230	unk_d1f3b8;
Unknown_45eab0_45ebd0	unk_cf6428;
Unknown_45f320_45f560	unk_cf6888;
XColor	cols_d395fc[7];
Unknown_45fae0_45fbd0	unk_d25450;
Unknown_45fe00_45fe80	unk_d1dd38;
HProp	hprop_d2d504;
XColor	cols_d2c35c[7];
XColor	col_cf6f2c((XColor &)ptr_cf6b24);
XColor	cols_cf0d48[32];
RepeatedPtrFieldBase	rpfs_d316c4[3];
RepeatedPtrFieldBase	rpfs_d35dc8[3];
RepeatedPtrFieldBase	rpf_cf4154;
RepeatedPtrFieldBase	rpf_d39268;
RepeatedPtrFieldBase	rpf_d1ed58;
RepeatedPtrFieldBase	rpf_cf75a0;
RepeatedPtrFieldBase	rpf_d2600c;
RepeatedPtrFieldBase	rpf_d20b4c;
XColor	cols_d01c18[18];
HProp	hprop_d388f4;
XColor	cols_d20504[5];
RepeatedPtrFieldBase	rpf_d01a04;
RepeatedPtrFieldBase	rpf_d35b6c;
HProp	hprop_d35bb8;
XColor	cols_d2a584[11];
XColor	cols_d21e5c[17];
XColor	cols_d2c37c[17];
Unknown_4c1840	unk_cf672c;
Unknown_4dbd80	unk_cefcaa;
