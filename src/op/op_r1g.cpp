// op_r1g: serialization/container helpers in 0x46cbc0-0x4729d0 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <map>
#include "../util/rng.h"
#include "../util/stringutil.h"
using namespace std;

struct Point
{
	int x;
	int y;

	Point() throw();			// (-1,-1)
	Point(int v);
	Point(int x_, int y_);
	Point(const Point &p);
	Point(const Point &p, int dx, int dy);	// 0x4099c0
	Point &operator=(const Point &p);
	bool operator!=(const Point &p) const;
	void set(int x_, int y_);
	bool isInvalid() const;		// NOTE: placeholder name; x < 0 || y < 0
};

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name
template <class T> void writeBinary(ostream &stream, T *value);	// NOTE: placeholder name
void OpQ1_readString(istream &in, string *text);	// 0x4096f0
void OpQ1_writeString(ostream &out, string text);	// 0x409650
void OpY1_writeIntVector(ostream &stream, vector<int> *value);	// NOTE: placeholder name (0x9d2130, template instance)
void OpY1_readIntVector(istream &stream, vector<int> *value);	// NOTE: placeholder name (0x9cf5e0, template instance)

class Entity
{
public:
	bool isPlayer();
};

class HEntity
{
public:
	int ID;
	HEntity();
	Entity *operator->() const;	// 0x9b6570
	bool operator==(HEntity other) const;
};

class Item
{
public:
	int unknown44aec0();	// NOTE: placeholder name (ICF'd trivial getter)
	HEntity unknown457b50();	// NOTE: placeholder name (owner)
};

class HItemP
{
public:
	int ID;
	HItemP();
	Item *operator->() const;	// 0x9b65b0
};

struct OpR1g_HData	// NOTE: placeholder name
{
	char	pad0[4];
	int		x;
	int		y;
};

class HProp
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
	OpR1g_HData *operator->() const;	// 0x9b7910
	bool isNull() const;
	void save(ostream &stream);	// NOTE: placeholder name (0x9cfa90)
	void load(istream &stream);	// NOTE: placeholder name (0x9cfaf0)
};

//==================================================================
// three parallel integer lists
//==================================================================

struct OpR1g_Triple	// NOTE: placeholder name
{
	OpR1g_Triple() throw();	// 0x46cb90
	~OpR1g_Triple();	// 0x9b7080
	OpR1g_Triple(const OpR1g_Triple &other);
	void clear();	// NOTE: placeholder name (0x46cc60)
	void write(ostream &stream);	// NOTE: placeholder name
	void read(istream &stream);	// NOTE: placeholder name
	void add(int x, int y, int z);	// NOTE: placeholder name
	void merge();	// NOTE: placeholder name

	vector<int>	xs;
	vector<int>	ys;
	vector<int>	zs;
};

OpR1g_Triple::OpR1g_Triple() throw()
{
}

OpR1g_Triple::OpR1g_Triple(const OpR1g_Triple &other)
{
	xs = other.xs;
	ys = other.ys;
	zs = other.zs;
}

void OpR1g_Triple::write(ostream &stream)
{
	OpY1_writeIntVector(stream,&xs);
	OpY1_writeIntVector(stream,&ys);
	OpY1_writeIntVector(stream,&zs);
}

void OpR1g_Triple::read(istream &stream)
{
	clear();
	OpY1_readIntVector(stream,&xs);
	OpY1_readIntVector(stream,&ys);
	OpY1_readIntVector(stream,&zs);
}

void OpR1g_Triple::add(int x, int y, int z)
{
	if (!xs.empty() && xs.back() == x && ys.back() == y)
		zs.back() += z;
	else
	{
		xs.push_back(x);
		ys.push_back(y);
		zs.push_back(z);
	}
}

template <class T> void OpR1g_removeAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9de6f0)
void OpR1g_eraseAt(vector<int> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0)
template <class T> void OpR1g_moveElement(vector<T> &v, unsigned int from, unsigned int to);	// NOTE: placeholder name

void OpR1g_Triple::merge()
{
	for (unsigned int i = 0; i < xs.size(); i++)
	{
		for (unsigned int j = i + 1; j < xs.size(); j++)
		{
			if (xs[j] == xs[i] && ys[j] == ys[i])
			{
				zs[i] += zs[j];
				OpR1g_removeAt(xs,j);
				OpR1g_removeAt(ys,j);
				OpR1g_eraseAt(zs,j);
			}
		}
	}
	for (unsigned int k = 1; k < xs.size(); k++)
	{
		if (zs[k] > zs[k-1])
		{
			if (zs[k] > zs[0])
			{
				OpR1g_moveElement(xs,k,0);
				OpR1g_moveElement(ys,k,0);
				OpR1g_moveElement(zs,k,0);
			}
			else
			{
				for (int l = k - 1; l >= 0; l--)
				{
					if (zs[k] <= zs[l])
					{
						OpR1g_moveElement(xs,k,l+1);
						OpR1g_moveElement(ys,k,l+1);
						OpR1g_moveElement(zs,k,l+1);
						break;
					}
				}
			}
		}
	}
}

//==================================================================
// records
//==================================================================

struct OpR1g_Rec	// NOTE: placeholder name
{
	OpR1g_Rec(istream &stream);
	void write(ostream &stream);	// NOTE: placeholder name

	int		a;
	int		b;
	string	text;
	int		c;
	int		d;
	int		e;
	int		f;
};

OpR1g_Rec::OpR1g_Rec(istream &stream)
{
	readBinary(stream,&a);
	readBinary(stream,&b);
	OpQ1_readString(stream,&text);
	readBinary(stream,&c);
	readBinary(stream,&d);
	readBinary(stream,&e);
	readBinary(stream,&f);
}

void OpR1g_Rec::write(ostream &stream)
{
	writeBinary(stream,&a);
	writeBinary(stream,&b);
	OpQ1_writeString(stream,text);
	writeBinary(stream,&c);
	writeBinary(stream,&d);
	writeBinary(stream,&e);
	writeBinary(stream,&f);
}

struct OpR1g_PropPair	// NOTE: placeholder name
{
	OpR1g_PropPair(istream &stream);
	void write(ostream &stream);	// NOTE: placeholder name
	bool isFirstEmpty();	// NOTE: placeholder name
	bool isSecondEmpty();	// NOTE: placeholder name

	int		a;
	int		zero4;
	HProp	first;
	int		zeroc;
	HProp	second;
};

OpR1g_PropPair::OpR1g_PropPair(istream &stream)
{
	readBinary(stream,&a);
	zero4 = 0;
	first.load(stream);
	zeroc = 0;
	second.load(stream);
}

void OpR1g_PropPair::write(ostream &stream)
{
	writeBinary(stream,&a);
	first.save(stream);
	second.save(stream);
}

bool OpR1g_PropPair::isFirstEmpty()
{
	return zero4 == 0 && first.isNull();
}

bool OpR1g_PropPair::isSecondEmpty()
{
	return zeroc == 0 && second.isNull();
}

struct OpR1g_EntityPair	// NOTE: placeholder name
{
	bool has(HEntity other);	// NOTE: placeholder name

	HEntity	first;
	HEntity	second;
};

bool OpR1g_EntityPair::has(HEntity other)
{
	return first == other || second == other;
}

struct OpR1g_ItemPair	// NOTE: placeholder name
{
	bool isPlayerSwap();	// NOTE: placeholder name

	HItemP	first;
	HItemP	second;
};

bool OpR1g_ItemPair::isPlayerSwap()
{
	return first.operator->() && second.operator->()
		&& first->unknown44aec0() != second->unknown44aec0()
		&& first->unknown44aec0() <= 4 && second->unknown44aec0() <= 4
		&& first->unknown457b50().operator->() && first->unknown457b50()->isPlayer()
		&& second->unknown457b50().operator->() && second->unknown457b50()->isPlayer();
}

//==================================================================
// big level-state object (global at 0xcf45d8)
//==================================================================

class HExplosive	// NOTE: placeholder layout (4-byte handle; the exe destroys these vectors with the handle family 0x9b7e00)
{
	int ID;
};

struct OpQ5_T9d8e70;
struct OpQ5_T9e2c40;
struct OpQ5_T9ed890;
template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name

struct OpR1g_Obj128	// NOTE: placeholder name
{
	~OpR1g_Obj128();
};

struct OpR1g_Pair8	// NOTE: placeholder name
{
	OpR1g_Pair8() throw();	// 0x453b40
	int a;
	int b;
};

struct OpR1g_Nested	// NOTE: placeholder name
{
	OpR1g_Nested();
	~OpR1g_Nested();

	char			pad0[0x1c];
	vector<int>	v1c;
	char			pad2c[0x3c];
	vector<string>	v68;
	vector<int>	v78;
	vector<OpQ5_T9d8e70*>	v88;
	vector<int>	v98;
	vector<int>	va8;
	vector<int>	vb8;
	char			padc8[0x8];
	vector<int>	vd0;
	vector<string>	ve0;
	vector<int>	vf0;
	vector<int>	v100;
	vector<int>	v110;
	vector<int>	v120;
	vector<string>	v130;
	vector<int>	v140;
	vector<int>	v150;
	vector<int>	v160;
	vector<int>	v170;
	vector<int>	v180;
	vector<int>	v190;
	char			pad1a0[0x8];
	vector<OpQ5_T9ed890*>	v1a8;
	char			pad1b8[0x28];
	vector<int>	v1e0;
	vector<HExplosive>	v1f0;
	char			pad200[0x1c];
	OpR1g_Pair8	pair21c;

};

struct Unknown46d8b0	// NOTE: placeholder name
{
	Unknown46d8b0();
	~Unknown46d8b0();
	void clearMarkers();	// NOTE: placeholder name
	bool isFlagActive();	// NOTE: placeholder name
	bool isSlotEmpty(unsigned int index);	// NOTE: placeholder name
	bool hasMarkedList();	// NOTE: placeholder name
	string getFlagsText();	// NOTE: placeholder name
	bool isTypeAllowed(int type);	// NOTE: placeholder name
	int getCountMinusTwo();	// NOTE: placeholder name

	string	s0;
	char			pad1c[0x4];
	string	s20;
	char			pad3c[0x4];
	HProp	prop40;
	char			pad44[0xc];
	bool	flag50;
	char			pad51[0xb];
	vector<int>	v5c;
	vector<int>	v6c;
	vector<int>	v7c;
	char			pad8c[0x18];
	vector<int>	va4;
	char			padb4[0x24];
	int *	ptrd8;
	vector<HExplosive>	vdc;
	vector<int>	vec;
	vector<HExplosive>	vfc;
	vector<int>	v10c;
	char			pad11c[0xc];
	OpR1g_Obj128 *	ptr128;
	vector<int>	v12c;
	char			pad13c[0x8];
	int	flags[12];
	char			pad174[0x4];
	vector<vector<OpQ5_T9e2c40*> >	v178;
	vector<OpQ5_T9e2c40*>	v188;
	vector<int>	v198;
	char			pad1a8[0x4];
	OpR1g_Triple	t1ac;
	char			pad1dc[0x18];
	vector<int>	v1f4;
	vector<int>	v204;
	vector<int>	v214;
	char			pad224[0x4];
	vector<int>	v228;
	vector<int>	v238;
	vector<int>	v248;
	vector<int>	v258;
	char			pad268[0x4];
	vector<int>	v26c;
	char			pad27c[0x4];
	vector<int>	v280;
	vector<int>	v290;
	vector<int>	v2a0;
	vector<int>	v2b0;
	char			pad2c0[0x4];
	vector<int>	v2c4;
	vector<int>	v2d4;
	vector<int>	v2e4;
	vector<int>	v2f4;
	char			pad304[0x4];
	vector<int>	v308;
	vector<int>	v318;
	vector<int>	v328;
	vector<int>	v338;
	char			pad348[0x4];
	vector<int>	v34c;
	vector<int>	v35c;
	vector<HExplosive>	v36c;
	char			pad37c[0xb0];
	vector<int>	v42c;
	vector<int>	v43c;
	vector<int>	v44c;
	char			pad45c[0x4];
	vector<HExplosive>	v460;
	vector<HExplosive>	v470;
	vector<vector<OpQ5_T9e2c40*> >	v480;
	char			pad490[0x18];
	vector<Point>	v4a8;
	char			pad4b8[0x8];
	vector<int>	v4c0;
	vector<HExplosive>	v4d0;
	vector<int>	v4e0;
	int *	ptr4f0;
	string	s4f4;
	string	s510;
	string	s52c;
	char			pad548[0x4];
	vector<int>	v54c;
	char			pad55c[0x8];
	string	s564;
	OpR1g_Nested	nested;

};

OpR1g_Nested::OpR1g_Nested()
{
}

OpR1g_Nested::~OpR1g_Nested()
{
}

Unknown46d8b0::Unknown46d8b0()
	: ptrd8		(NULL)
	, ptr128	(NULL)
	, ptr4f0	(NULL)
{
}

Unknown46d8b0::~Unknown46d8b0()
{
	delete ptrd8;
	delete ptr128;
	delete ptr4f0;
	OpQ5_clearObjects(nested.v88);
	clearMarkers();
	OpQ5_clearObjects(v188);
	OpQ5_clearObjects(nested.v1a8);
}

extern bool OpR1g_flag_cefacc;	// NOTE: placeholder name (0xcefacc)
extern int opw2_machineFlags[];	// NOTE: placeholder name (0xb90000)
extern string gameStrings_d20b98[];	// 0xd20b98
bool OpR1g_anySet(int *values, unsigned int count);	// NOTE: placeholder name (0x9d3f40)

struct OpR1g_TypeEntry	// NOTE: placeholder name
{
	int a;
	int b;
};
extern OpR1g_TypeEntry OpR1g_typeTable_d2a68c[];	// NOTE: placeholder name (0xd2a68c)

void Unknown46d8b0::clearMarkers()
{
	if (!v178.empty())
	{
		for (int i = 0; i < 4; i++)
			OpQ5_clearObjects(v178[i]);
		v178.clear();
	}
}

bool Unknown46d8b0::isFlagActive()
{
	return flag50 && OpR1g_flag_cefacc;
}

bool Unknown46d8b0::isSlotEmpty(unsigned int index)
{
	return v204[index] == 0;
}

bool Unknown46d8b0::hasMarkedList()
{
	for (unsigned int i = 0; i < v480.size(); i++)
	{
		if (!v480[i].empty())
			return true;
	}
	return false;
}

string Unknown46d8b0::getFlagsText()
{
	string text;
	if (!OpR1g_anySet(flags,12))
		return "None";
	else
	{
		for (int i = 0; i < 12; i++)
		{
			if (flags[i])
			{
				if (!text.empty())
					text += " / ";
				text += gameStrings_d20b98[i];
			}
		}
		return text;
	}
}

bool Unknown46d8b0::isTypeAllowed(int type)
{
	return flags[10] && opw2_machineFlags[type] == 1 && type != 13 && OpR1g_typeTable_d2a68c[type].a;
}

int Unknown46d8b0::getCountMinusTwo()
{
	return v43c.size() - 2;
}

//==================================================================
// serialized node and its container (global at 0xd338e0)
//==================================================================

struct OpQ5_T9d1de0
{
	char pad[328];
	OpQ5_T9d1de0(istream &stream);
	~OpQ5_T9d1de0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1e90
{
	char pad[120];
	OpQ5_T9d1e90(istream &stream);
	~OpQ5_T9d1e90();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1fd0
{
	char pad[4];
	OpQ5_T9d1fd0(istream &stream);
	~OpQ5_T9d1fd0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d2010
{
	char pad[4];
	OpQ5_T9d2010(istream &stream);
	~OpQ5_T9d2010();
	void serialize(ostream &stream);
};

struct OpQ5_T9ed5d0
{
	char pad[4];
	OpQ5_T9ed5d0(istream &stream);
	~OpQ5_T9ed5d0();
	void serialize(ostream &stream);
};

template <class T> void OpQ5_readPointer(istream &stream, T *&p);	// NOTE: placeholder name
template <class T> void OpQ5_writePointer(ostream &stream, T *&p);	// NOTE: placeholder name
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v);	// NOTE: placeholder name

struct OpR1g_Node	// NOTE: placeholder name
{
	OpR1g_Node(bool flag_);
	OpR1g_Node(istream &stream);
	~OpR1g_Node();
	void clear() throw();	// NOTE: placeholder name (0x46e740)
	void serialize(ostream &stream);	// NOTE: placeholder name

	int						a;
	OpQ5_T9d1de0			*ptr;
	int						b;
	int						c;
	int						d;
	vector<OpQ5_T9d1e90*>	list;
	vector<int>				ints;
	bool					flag;
};

OpR1g_Node::OpR1g_Node(bool flag_)
{
	flag = flag_;
	clear();
}

OpR1g_Node::OpR1g_Node(istream &stream)
{
	readBinary(stream,&a);
	OpQ5_readPointer(stream,ptr);
	readBinary(stream,&b);
	readBinary(stream,&c);
	readBinary(stream,&d);
	OpQ5_readObjects(stream,list,0);
	OpY1_readIntVector(stream,&ints);
	readBinary(stream,&flag);
}

void OpR1g_Node::serialize(ostream &stream)
{
	writeBinary(stream,&a);
	OpQ5_writePointer(stream,*(OpQ5_T9d1fd0**)&ptr);
	writeBinary(stream,&b);
	writeBinary(stream,&c);
	writeBinary(stream,&d);
	OpQ5_writeObjects(stream,*(vector<OpQ5_T9d2010*>*)&list);
	OpY1_writeIntVector(stream,&ints);
	writeBinary(stream,&flag);
}

OpR1g_Node::~OpR1g_Node()
{
	if (flag)
	{
		delete ptr;
		OpQ5_clearObjects(*(vector<OpQ5_T9ed5d0*>*)&list);
	}
}

struct E38_0
{
	char pad[56];
};

struct Unknown46ea00	// NOTE: placeholder name
{
	Unknown46ea00();
	~Unknown46ea00();

	int						a0;
	OpR1g_Node				node;
	vector<int>				v3c;
	vector<int>				v4c;
	vector<int>				v5c;
	vector<E38_0>			elems[15];
	int						a15c;
	vector<int>				v160;
	vector<int>				v170;
	vector<int>				v180;
	vector<string>			v190;
	vector<vector<OpQ5_T9e2c40*> >	v1a0;
	vector<int>				v1b0;
	vector<int>				v1c0;
	vector<string>			v1d0;
};

Unknown46ea00::Unknown46ea00()
	: node	(false)
{
}

Unknown46ea00::~Unknown46ea00()
{
}

//==================================================================
// timed event record
//==================================================================

extern RNG rng;	// 0xd30908

class OpR1g_H	// NOTE: placeholder name
{
public:
	int ID;
	OpR1g_HData *operator->() const;	// 0x9b7910
};

struct OpR1g_Event	// NOTE: placeholder name
{
	OpR1g_Event() throw();	// 0x46eb20
	~OpR1g_Event();
	void init(int x_, int y_, int value_, bool flag_);	// NOTE: placeholder name
	bool isAt(OpR1g_H handle);	// NOTE: placeholder name

	HProp				prop;
	int					x;
	int					y;
	vector<HExplosive>	list0c;
	int					id;
	int					value;
	bool				flag24;
	bool				flag25;
	bool				flag26;
	bool				flag27;
	bool				flag28;
	bool				flag29;
	bool				flag2a;
	bool				flag2b;
	bool				flag2c;
	bool				flag2d;
	bool				flag2e;
	bool				flag2f;
	vector<int>			list30;
	vector<HExplosive>	list40;
	vector<HExplosive>	list50;
	bool				flag60;
	bool				flag61;
};

void OpR1g_Event::init(int x_, int y_, int value_, bool flag_)
{
	x = x_;
	y = y_;
	id = rng.rangeInt(1,(float)numeric_limits<int>::max());
	value = value_;
	flag24 = flag_;
	flag25 = false;
	flag26 = false;
	flag27 = false;
	flag28 = false;
	flag29 = false;
	flag2a = false;
	flag2b = false;
	flag2c = false;
	flag2d = false;
	flag2e = false;
	flag2f = false;
	flag60 = false;
	flag61 = false;
}

OpR1g_Event::~OpR1g_Event()
{
}

bool OpR1g_Event::isAt(OpR1g_H handle)
{
	return x == handle->x && y == handle->y;
}

extern string opw8_machineNames[];	// NOTE: placeholder name (0xcfaca0)

struct OpR1g_Label	// NOTE: placeholder name
{
	string getText();	// NOTE: placeholder name

	int	pad0;
	int	type;
	int	value;
};

string OpR1g_Label::getText()
{
	return "-" + intToString(value) + "/" + opw8_machineNames[type];
}

struct OpR1g_HList	// NOTE: placeholder name
{
	HProp find(int key);	// NOTE: placeholder name

	int				pad0[3];
	vector<OpR1g_H>	list;
};

HProp OpR1g_HList::find(int key)
{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (list[i]->x == key)
			return *(HProp*)&list[i];
	}
	return HProp();
}

//==================================================================
// large game-state object (global at 0xd1e860)
//==================================================================

struct E8_1
{
	char pad[8];
	E8_1();
	E8_1(const E8_1 &e);
};

struct E30_0
{
	char pad[48];
};

struct B10_2
{
	char pad[16];
	bool operator==(const B10_2 &e) const;
	bool operator<(const B10_2 &e) const;
	B10_2();
	B10_2(const B10_2 &e);
	B10_2 &operator=(const B10_2 &e);
	~B10_2();
};

struct OpQ5_T9ed8f0;

struct OpR1g_Buf	// NOTE: placeholder name
{
	OpR1g_Buf() throw();	// 0x9d2670
	~OpR1g_Buf();	// 0x9cec20

	int	pad0;
	int	pad4;
	int	pad8;
};

struct OpR1g_Rect	// NOTE: placeholder name
{
	OpR1g_Rect() throw();	// 0x40b100
	Point a;
	Point b;
};

struct Unknown46f1e0	// NOTE: placeholder name
{
	Unknown46f1e0();
	~Unknown46f1e0();
	bool hasHandleAt(int key);	// NOTE: placeholder name
	bool hasAnyObjects();	// NOTE: placeholder name
	bool hasObjectID(int id);	// NOTE: placeholder name
	bool isLastOfType3();	// NOTE: placeholder name
	bool isFlagEnabledA();	// NOTE: placeholder name
	bool isFlagEnabledB();	// NOTE: placeholder name
	bool isFlagEnabledC();	// NOTE: placeholder name
	int getTier();	// NOTE: placeholder name
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)

	char			pad0[0x4];
	string	s4;
	char			pad20[0x4];
	HProp	prop24;
	HProp	prop28;
	vector<OpR1g_H>	v2c;
	vector<E30_0>	v3c;
	vector<int>	v4c;
	char			pad5c[0x4];
	vector<int>	v60;
	vector<int>	v70;
	vector<vector<OpQ5_T9e2c40*> >	v80;
	vector<vector<OpQ5_T9e2c40*> >	v90;
	vector<string>	va0;
	vector<int>	vb0;
	vector<int>	vc0;
	vector<string>	vd0;
	vector<int>	ve0;
	vector<int>	vf0;
	map<char,B10_2>	map100;
	OpR1g_Buf	buf110;
	vector<unsigned int>	arr11c[15];
	vector<int>	v20c;
	vector<HExplosive>	v21c;
	vector<string>	v22c;
	vector<int>	v23c;
	char			pad24c[0x30];
	HProp	prop27c;
	char			pad280[0x8];
	OpR1g_Rect	rect288;
	OpR1g_Rect	rect298;
	char			pad2a8[0x8];
	int		i2b0;
	char			pad2b4[0x30];
	vector<int>	v2e4;
	int		i2f4;
	char			pad2f8[0x20];
	vector<string>	v318;
	vector<int>	v328;
	char			pad338[0x4];
	vector<int>	v33c;
	char			pad34c[0x4];
	Point	point350;
	char			pad358[0x20];
	HProp	prop378;
	char			pad37c[0x4];
	HProp	prop380;
	HProp	prop384;
	char			pad388[0x18];
	vector<HExplosive>	v3a0;
	vector<Point>	v3b0;
	vector<Point>	v3c0;
	vector<int>	v3d0;
	vector<int>	v3e0;
	char			pad3f0[0x1c];
	Point	point40c;
	vector<E8_1>	v414;
	vector<int>	v424;
	vector<int>	v434;
	vector<string>	v444;

};

Unknown46f1e0::Unknown46f1e0()
{
}

Unknown46f1e0::~Unknown46f1e0()
{
	for (int i = 0; i < 15; i++)
		OpQ5_clearObjects(*(vector<OpQ5_T9ed8f0*>*)&arr11c[i]);
}

bool Unknown46f1e0::hasHandleAt(int key)
{
	for (unsigned int i = 0; i < v2c.size(); i++)
	{
		if (v2c[i]->x == key)
			return true;
	}
	return false;
}

struct OpR1g_Obj	// NOTE: placeholder name
{
	int ID;
};

bool Unknown46f1e0::hasAnyObjects()
{
	for (int i = 0; i < 15; i++)
	{
		if (!arr11c[i].empty())
			return true;
	}
	return false;
}

bool Unknown46f1e0::hasObjectID(int id)
{
	for (int i = 0; i < 15; i++)
	{
		for (unsigned int j = 0; j < arr11c[i].size(); j++)
		{
			if ((*(vector<OpR1g_Obj*>*)&arr11c[i])[j]->ID == id)
				return true;
		}
	}
	return false;
}

int stringToInt(const string &s);	// 0x405610
int opR1g_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
extern int opR1g_flags_b90e08[];	// NOTE: placeholder name (0xb90e08)
extern int opR1g_tierLimit_b9994c;	// NOTE: placeholder name (0xb9994c)
extern int opR1g_tierLimits_b9993c[];	// NOTE: placeholder name (0xb9993c)

bool Unknown46f1e0::isLastOfType3()
{
	if (prop28->x != 3)
		return false;
	for (int i = v2c.size() - 2; i >= 0; i--)
	{
		if (v2c[i]->y != prop28->y)
			break;
		if (v2c[i]->x == 3)
			return false;
	}
	return true;
}

bool Unknown46f1e0::isFlagEnabledA()
{
	return opw2_machineFlags[prop28->x] == 1 && prop28->x != 0x23 && stringToInt(getEntryText("exiFarcomEnabled_g"));
}

bool Unknown46f1e0::isFlagEnabledB()
{
	return opR1g_flags_b90e08[prop28->x] && !stringToInt(getEntryText("warMetWarlord_g")) && stringToInt(getEntryText("garCommArraySupport_g"));
}

bool Unknown46f1e0::isFlagEnabledC()
{
	return stringToInt(getEntryText("scrUfdJoined0bPrime_g")) && !stringToInt(getEntryText("scrAttackedLocals_g")) && !stringToInt(getEntryText("scrOptimusDestroyed_g"));
}

int Unknown46f1e0::getTier()
{
	int tier = 0;
	if (i2f4 >= opR1g_tierLimit_b9994c)
		tier = 5;
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (i2f4 < opR1g_tierLimits_b9993c[i])
			{
				tier = i;
				break;
			}
		}
	}
	if (i2b0)
		tier -= 2;
	return opR1g_maxInt(0,tier);
}

//==================================================================
// scoresheet location
//==================================================================

namespace google { namespace protobuf {
	class EnumValueDescriptor
	{
	public:
		int number() const;
	};

	class EnumDescriptor
	{
	public:
		const EnumValueDescriptor *FindValueByName(const string &name) const;
	};
}}

namespace Protobuf
{
	enum MapType {};
	const ::google::protobuf::EnumDescriptor *MapType_descriptor();

	class Location
	{
		char pad[0x14];
	public:
		Location();
		void set_depth(int value);
		void set_map(MapType value);
	};
}

string &opR1g_padLeft(string &s, unsigned int width, char c);	// NOTE: placeholder name (0x408090)
extern string gameStrings_cfe140[];	// 0xcfe140

Protobuf::Location *OpR1g_createLocation(int depth, int map)	// NOTE: placeholder name
{
	const ::google::protobuf::EnumValueDescriptor *enumValue;
	Protobuf::Location *location = new Protobuf::Location();
	location->set_depth(depth >= 0 ? 0 : depth);
	enumValue = Protobuf::MapType_descriptor()->FindValueByName(depth >= 0 ? "MAP_W" + opR1g_padLeft(intToString(depth),2,'0') : "MAP_" + gameStrings_cfe140[map]);
	location->set_map((Protobuf::MapType)enumValue->number());
	return location;
}

//==================================================================
// pair of fixed-size integer tables
//==================================================================

struct OpR1g_Tables	// NOTE: placeholder name
{
	OpR1g_Tables();
	OpR1g_Tables(istream &stream);

	vector<unsigned int>	a;
	vector<unsigned int>	b;
};

OpR1g_Tables::OpR1g_Tables()
{
	unsigned int fill1 = 0;
	a.assign(0x4a1,fill1);
	unsigned int fill2 = 0;
	b.assign(0x4a1,fill2);
}

OpR1g_Tables::OpR1g_Tables(istream &stream)
{
	OpY1_readIntVector(stream,(vector<int>*)&a);
	OpY1_readIntVector(stream,(vector<int>*)&b);
}
