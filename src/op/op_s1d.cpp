// op_s1d: functions in 0x45b000-0x45e000 matched against COGMIND.exe (Beta 17.1).
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

struct OpQ5_T9d1190;
struct OpQ5_T9d11d0;
struct OpQ5_T9d1230;
struct OpQ5_T9d1270;
template <class T> void readBinary(istream &stream, T *value)	// NOTE: placeholder name
{
	stream.read((char*)value,sizeof(T));
}

struct OpQ5_T9d12b0;
struct OpQ5_T9d1360;
struct OpQ5_T9d14a0;
struct OpQ5_T9d1550;
template <class T> void OpQ5_readPointer(istream &stream, T *&p);	// NOTE: placeholder name
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
void OpS1d_readVector9cf5e0(istream &stream, vector<int> &v);	// NOTE: placeholder name

template <class T> void OpQ5_writePointer(ostream &stream, T *&p);	// NOTE: placeholder name
template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v);	// NOTE: placeholder name

void OpS1d_writeVector9d2130(ostream &stream, vector<int> &v);	// NOTE: placeholder name

class Prop;

class HProp
{
	int	ID;
public:
	HProp();
	void unknown9cfa90(ostream &stream);	// NOTE: placeholder name
	void unknown9cfaf0(istream &stream);	// NOTE: placeholder name
	bool isValid() const;
	Prop *operator->() const;
};

class OpY1_ShuffleBag	// NOTE: placeholder name
{
public:
	int mode;
	int blanks;
	vector<int> items;
	vector<int> deck;
};

class OpR3_ItemOwner	// NOTE: placeholder name
{
public:
	~OpR3_ItemOwner();	// 0x659f10
};

struct OpS1d_Plain	// NOTE: placeholder name
{
	int unknown0;
};

struct MapRecord	// NOTE: placeholder layout
{
	int ID;	// NOTE: placeholder name
};

class OpR1e_Match	// NOTE: placeholder name
{
public:
	bool matches45b980(int a, int b);	// NOTE: placeholder name
};

struct OpQ5_T9e2c40;
template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name (0x9e2c40)

class UnknownPart45c060	// NOTE: placeholder name
{
public:
	~UnknownPart45c060();	// 0x45c060
	bool unknown45c160(int a, int b);	// NOTE: placeholder name
	MapRecord *unknown45c1c0(int ID);	// NOTE: placeholder name
	UnknownPart45c060(istream &stream);	// 0x45bdf0
	void write(ostream &stream);	// 0x45bc00

	HProp unknown0;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
	int unknown8;	// NOTE: placeholder name
	int unknownc;	// NOTE: placeholder name
	bool unknown10;	// NOTE: placeholder name
	bool unknown11;	// NOTE: placeholder name
	OpY1_ShuffleBag *unknown14;	// NOTE: placeholder name
	vector<MapRecord*> unknown18;	// NOTE: placeholder name
	int unknown28;	// NOTE: placeholder name
	int unknown2c;	// NOTE: placeholder name
	bool unknown30;	// NOTE: placeholder name
	int unknown34;	// NOTE: placeholder name
	OpR3_ItemOwner *unknown38;	// NOTE: placeholder name
	int unknown3c;	// NOTE: placeholder name
	vector<int> unknown40;	// NOTE: placeholder name
	vector<int> unknown50;	// NOTE: placeholder name
	vector<int> unknown60;	// NOTE: placeholder name
	HProp unknown70;	// NOTE: placeholder name
	bool unknown74;	// NOTE: placeholder name
	OpS1d_Plain *unknown78;	// NOTE: placeholder name
	int unknown7c;	// NOTE: placeholder name
	int unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	int unknown88;	// NOTE: placeholder name
	int unknown8c;	// NOTE: placeholder name
};

void UnknownPart45c060::write(ostream &stream)
{
	unknown0.unknown9cfa90(stream);
	writeBinary(stream,&unknown4);
	writeBinary(stream,&unknown8);
	writeBinary(stream,&unknownc);
	writeBinary(stream,&unknown10);
	writeBinary(stream,&unknown11);
	OpQ5_writePointer(stream,(OpQ5_T9d1190*&)unknown14);
	OpQ5_writeObjects(stream,(vector<OpQ5_T9d11d0*>&)unknown18);
	writeBinary(stream,&unknown28);
	writeBinary(stream,&unknown2c);
	writeBinary(stream,&unknown30);
	writeBinary(stream,&unknown34);
	OpQ5_writePointer(stream,(OpQ5_T9d1230*&)unknown38);
	writeBinary(stream,&unknown3c);
	OpS1d_writeVector9d2130(stream,unknown40);
	OpS1d_writeVector9d2130(stream,unknown50);
	OpS1d_writeVector9d2130(stream,unknown60);
	unknown70.unknown9cfa90(stream);
	writeBinary(stream,&unknown74);
	OpQ5_writePointer(stream,(OpQ5_T9d1270*&)unknown78);
	writeBinary(stream,&unknown7c);
	writeBinary(stream,&unknown80);
	writeBinary(stream,&unknown84);
	writeBinary(stream,&unknown88);
	writeBinary(stream,&unknown8c);
}

UnknownPart45c060::UnknownPart45c060(istream &stream)
{
	unknown0.unknown9cfaf0(stream);
	readBinary(stream,&unknown4);
	readBinary(stream,&unknown8);
	readBinary(stream,&unknownc);
	readBinary(stream,&unknown10);
	readBinary(stream,&unknown11);
	OpQ5_readPointer(stream,(OpQ5_T9d12b0*&)unknown14);
	OpQ5_readObjects(stream,(vector<OpQ5_T9d1360*>&)unknown18,0);
	readBinary(stream,&unknown28);
	readBinary(stream,&unknown2c);
	readBinary(stream,&unknown30);
	readBinary(stream,&unknown34);
	OpQ5_readPointer(stream,(OpQ5_T9d14a0*&)unknown38);
	readBinary(stream,&unknown3c);
	OpS1d_readVector9cf5e0(stream,unknown40);
	OpS1d_readVector9cf5e0(stream,unknown50);
	OpS1d_readVector9cf5e0(stream,unknown60);
	unknown70.unknown9cfaf0(stream);
	readBinary(stream,&unknown74);
	OpQ5_readPointer(stream,(OpQ5_T9d1550*&)unknown78);
	readBinary(stream,&unknown7c);
	readBinary(stream,&unknown80);
	readBinary(stream,&unknown84);
	readBinary(stream,&unknown88);
	readBinary(stream,&unknown8c);
}

UnknownPart45c060::~UnknownPart45c060()
{
	delete unknown14;
	OpQ5_clearObjects((vector<OpQ5_T9e2c40*>&)unknown18);
	delete unknown38;
	delete unknown78;
}

bool UnknownPart45c060::unknown45c160(int a, int b)
{
	for (unsigned int i = 0; i < unknown18.size(); i++)
	{
		if (((OpR1e_Match*)unknown18[i])->matches45b980(a,b))
		{
			return true;
		}
	}

	return false;
}

MapRecord *UnknownPart45c060::unknown45c1c0(int ID)
{
	for (unsigned int i = 0; i < unknown18.size(); i++)
	{
		if (unknown18[i]->ID == ID)
		{
			return unknown18[i];
		}
	}

	return NULL;
}

class OpS1d_PropTriple	// NOTE: placeholder name
{
public:
	OpS1d_PropTriple(istream &stream);	// 0x45c3e0
	void write(ostream &stream);	// 0x45c340

	HProp unknown0;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
	HProp unknown8;	// NOTE: placeholder name
	HProp unknownc;	// NOTE: placeholder name
	int unknown10;	// NOTE: placeholder name
	int unknown14;	// NOTE: placeholder name
	int unknown18;	// NOTE: placeholder name
	int unknown1c;	// NOTE: placeholder name
};

void OpS1d_PropTriple::write(ostream &stream)
{
	unknown0.unknown9cfa90(stream);
	writeBinary(stream,&unknown4);
	unknown8.unknown9cfa90(stream);
	unknownc.unknown9cfa90(stream);
	writeBinary(stream,&unknown10);
	writeBinary(stream,&unknown14);
	writeBinary(stream,&unknown18);
	writeBinary(stream,&unknown1c);
}

OpS1d_PropTriple::OpS1d_PropTriple(istream &stream)
{
	unknown0.unknown9cfaf0(stream);
	readBinary(stream,&unknown4);
	unknown8.unknown9cfaf0(stream);
	unknownc.unknown9cfaf0(stream);
	readBinary(stream,&unknown10);
	readBinary(stream,&unknown14);
	readBinary(stream,&unknown18);
	readBinary(stream,&unknown1c);
}

extern bool asciiEnabled;	// NOTE: placeholder name (0xd28d30)
extern bool opS1d_flagd28e74;	// NOTE: placeholder name (0xd28e74)

struct OpS1d_PropData	// NOTE: placeholder name; partial record
{
	char pad0[0x3c];
	vector<int> unknown3c;	// NOTE: placeholder name
	char pad4c[0x6c - 0x4c];
	void *unknown6c;	// NOTE: placeholder name
	char pad70[0xc5 - 0x70];
	bool unknownc5;	// NOTE: placeholder name
	char padc6[0xfc - 0xc6];
	bool unknownfc;	// NOTE: placeholder name
	char padfd[0x168 - 0xfd];
	int unknown168;	// NOTE: placeholder name
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &c);	// 0x411e30
};

class Prop
{
public:
	int unknown45c650();	// NOTE: placeholder name
	bool unknown45c610();	// NOTE: placeholder name
	int unknown45c700();	// NOTE: placeholder name
	int unknown45c740();	// NOTE: placeholder name
	XColor unknown45c780();	// NOTE: placeholder name
	bool unknown45c7a0();	// NOTE: placeholder name
	bool unknown45cc10();	// NOTE: placeholder name

	int ID;
	OpS1d_PropData *data;	// NOTE: placeholder name
	char pad8[0x14 - 8];
	int unknown14;	// NOTE: placeholder name
	XColor color;	// NOTE: placeholder name
	char pad1b[0x1e - 0x1b];
	bool unknown1e;	// NOTE: placeholder name
	char pad1f[0x34 - 0x1f];
	int machineIndex;	// NOTE: placeholder name
	char pad38[0x44 - 0x38];
	int unknown44;	// NOTE: placeholder name
};

int Prop::unknown45c650()
{
	return (asciiEnabled && data->unknown3c.empty() && data->unknown168) ? data->unknown168 :
		((asciiEnabled && (machineIndex != -1 || data->unknownfc) && unknown44 == 0 && !opS1d_flagd28e74) ? unknown14 + 0x34 : unknown14);
}

bool Prop::unknown45c610()
{
	return data->unknown6c;
}

int Prop::unknown45c700()
{
	return asciiEnabled ? data->unknown168 : unknown14;
}

int Prop::unknown45c740()
{
	return !asciiEnabled ? data->unknown168 : unknown14;
}

XColor Prop::unknown45c780()
{
	return color;
}

bool Prop::unknown45c7a0()
{
	return unknown1e || data->unknownc5;
}

//==================================================================
// Cell
//==================================================================

class HEntity
{
	int	ID;
public:
	HEntity();
	bool operator==(HEntity e) const;
};

struct CellEffectRecord	// NOTE: partial record
{
	int type;
};

struct CellEffect	// NOTE: partial effect object
{
	CellEffectRecord *record;
	int value;
};

struct OpS1d_TerrainBase	// NOTE: placeholder name
{
	int pad00[8];
	int resists[7];
};

struct CellTerrainRecord	// NOTE: partial record
{
	char pad0[0x50];
	OpS1d_TerrainBase *base;
};

class HItem
{
	int	ID;
public:
	HItem();
};

template <class T> void eraseAt(vector<T> &v, unsigned int index);	// NOTE: placeholder name (0x9d8f20)

class Cell
{
public:
	bool unknown45ddf0();	// NOTE: placeholder name
	bool unknown45de40();	// NOTE: placeholder name
	void unknown45dec0(bool flag);	// NOTE: placeholder name
	void unknown45df00(HEntity entity, int amount);	// NOTE: placeholder name
	void unknown45df90(CellEffect *effect);	// NOTE: placeholder name
	void unknown45dfb0(int type);	// NOTE: placeholder name
	void unknown66dae0(int amount, int type, bool a, int b, int c, int d, HEntity e, int f);	// NOTE: placeholder name

	CellTerrainRecord *terrain;
	char pad04[8];
	int unknown0c;	// NOTE: placeholder name
	char pad10[0x34];
	HProp prop;
	HEntity entity;
	vector<HItem> items;
	vector<CellEffect*> effects;
};

bool Cell::unknown45ddf0()
{
	return prop.isValid() && prop->unknown45cc10();
}

bool Cell::unknown45de40()
{
	if (unknown0c != -1)
	{
		unknown0c = -1;
		return true;
	}

	return false;
}

void Cell::unknown45dec0(bool flag)
{
	unknown66dae0(0,4,false,0,0,0,HEntity(),flag);
}

void Cell::unknown45df00(HEntity entity, int amount)
{
	amount = amount * terrain->base->resists[4] / 100;
	unknown66dae0(amount,4,false,0,1,0,entity,0);
}

void Cell::unknown45df90(CellEffect *effect)
{
	effects.push_back(effect);
}

void Cell::unknown45dfb0(int type)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i]->record->type == type)
		{
			eraseAt(effects,i);
			return;
		}
	}
}

//==================================================================
// SEntityShoot
//==================================================================

class BattleState	// NOTE: placeholder layout
{
public:
	virtual ~BattleState();
	virtual int getType();			// NOTE: placeholder name
	virtual void update();			// NOTE: placeholder name
	virtual void unknown3() = 0;	// NOTE: placeholder name
};

struct Point
{
	int x;
	int y;
	Point &operator=(const Point &p);	// 0x46ca50
};

struct E8_1	// NOTE: placeholder name
{
	int unknown0;
};

class HExplosive
{
	int	ID;
public:
	HExplosive();
};

extern int opS1d_gce9fec;	// NOTE: placeholder name (0xce9fec)

class SEntityShoot : public BattleState
{
public:
	~SEntityShoot();	// 0x45b620
	void unknown45b6b0(HEntity entity, const Point &p);	// NOTE: placeholder name
	virtual int getType();	// 0x45b6a0
	virtual void update();	// 0x6516b0
	virtual void unknown3();	// NOTE: placeholder name (0x9c05e0)

	char pad04[0x14];
	Point unknown18;	// NOTE: placeholder name
	char pad20[8];
	HEntity unknown28;	// NOTE: placeholder name
	vector<E8_1> unknown2c;	// NOTE: placeholder name
	char pad3c[8];
	vector<HExplosive> unknown44;	// NOTE: placeholder name
	char pad54[0x18];
	vector<Point> unknown6c;	// NOTE: placeholder name
};

SEntityShoot::~SEntityShoot()
{
}

int SEntityShoot::getType()
{
	return opS1d_gce9fec;
}

void SEntityShoot::unknown45b6b0(HEntity entity, const Point &p)
{
	if (entity == unknown28)
	{
		unknown18 = p;
	}
}

class OpS1d_Holder45b540	// NOTE: placeholder name
{
public:
	void *unknown45b540();	// NOTE: placeholder name

	char pad0[0xec];
	void *unknownec;	// NOTE: placeholder name
};

void *OpS1d_Holder45b540::unknown45b540()
{
	void *result = unknownec;
	unknownec = NULL;
	return result;
}

class OpS1d_Thunk45b5e0	// NOTE: placeholder name
{
public:
	virtual void unknown0() = 0;	// NOTE: placeholder name
	virtual void unknown1() = 0;	// NOTE: placeholder name
	virtual void unknown2(Point a, Point b, int c, int d) = 0;	// NOTE: placeholder name
	void unknown45b5e0(const Point &a, const Point &b, int c, int d);	// NOTE: placeholder name
};

void OpS1d_Thunk45b5e0::unknown45b5e0(const Point &a, const Point &b, int c, int d)
{
	unknown2(a,b,c,d);
}

class OpS1d_IntRec45b720	// NOTE: placeholder name
{
public:
	OpS1d_IntRec45b720(istream &stream);	// 0x45b720

	int unknown0;	// NOTE: placeholder name
};

OpS1d_IntRec45b720::OpS1d_IntRec45b720(istream &stream)
{
	readBinary(stream,&unknown0);
}

class OpS1d_IntList45bbe0	// NOTE: placeholder name
{
public:
	void unknown45bbe0(int value);	// NOTE: placeholder name

	char pad0[0x18];
	vector<int> unknown18;	// NOTE: placeholder name
};

void OpS1d_IntList45bbe0::unknown45bbe0(int value)
{
	unknown18.push_back(value);
}
