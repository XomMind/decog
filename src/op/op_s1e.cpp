// op_s1e: entity list / misc helpers in 0x45e000-0x472000 (COGMIND.exe Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class Entity;
struct EntityEffect;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	Entity *operator->() const;
};

class Entity
{
public:
	~Entity();
	int getFaction();					// 0x45a2c0
	const string &getName();			// 0x45a280
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	bool unknown45ad20(const string &effectName);	// NOTE: placeholder name
};

class Group	// NOTE: placeholder name
{
public:
	HEntity unknown45e1c0(const string &name);	// NOTE: placeholder name
	HEntity unknown45e250(int type);			// NOTE: placeholder name
	HEntity unknown45e2d0(const string &name);	// NOTE: placeholder name
	bool unknown45e3e0(int type);				// NOTE: placeholder name
	void unknown45e4c0();						// NOTE: placeholder name
	~Group();									// 0x45e140

	char			pad00[0x04];
	int				faction;
	char			pad08[0x04];
	vector<HEntity>	entities;
	char			pad1c[0x2c - 0x1c];
	vector<XColor>	colors;
};

extern XColor opS1e_cf0e98[][6];	// NOTE: placeholder name

Group::~Group()
{
}

void Group::unknown45e4c0()
{
	for (int i = 0; i < 6; i++)
		colors.push_back(opS1e_cf0e98[faction][i]);
}

HEntity Group::unknown45e1c0(const string &name)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getName() == name)
			return entities[i];
	}
	return HEntity();
}

HEntity Group::unknown45e250(int type)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getFaction() == type)
			return entities[i];
	}
	return HEntity();
}

HEntity Group::unknown45e2d0(const string &name)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->unknown45ad20(name))
			return entities[i];
	}
	return HEntity();
}

bool Group::unknown45e3e0(int type)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->unknown45ac40(type))
			return true;
	}
	return false;
}

//==================================================================
// small helpers
//==================================================================

struct OpS1e_Cfg	// NOTE: placeholder name
{
	bool operator==(const OpS1e_Cfg &other) const;	// 0x45e860
	void randomize();								// 0x45e940

	int		kind;
	int		flip;
	int		count;
	bool	flag0;
	bool	flag1;
	bool	flag2;
	bool	flag3;
	bool	flag4;
	bool	flag5;
	bool	flag6;
};

bool OpS1e_Cfg::operator==(const OpS1e_Cfg &other) const
{
	return kind == other.kind && flip == other.flip && count == other.count
		&& flag0 == other.flag0 && flag1 == other.flag1 && flag2 == other.flag2 && flag3 == other.flag3
		&& flag4 == other.flag4 && flag5 == other.flag5 && flag6 == other.flag6;
}

void OpS1e_Cfg::randomize()
{
	kind = rng.rangeInt(0, 6);
	flip = !rng.chance(50);
	count = rng.chance(50) ? 0 : rng.rangeInt(1, 3);
	flag0 = rng.chance(50);
	flag1 = rng.chance(50);
	flag2 = rng.chance(50);
	flag3 = rng.chance(50);
	flag4 = rng.chance(50);
	flag5 = rng.chance(50);
	flag6 = rng.chance(50);
}

class HProp	// NOTE: placeholder layout
{
	int	ID;
public:
	HProp();
};

struct OpR1F_Target45e690	// NOTE: placeholder name
{
	HProp getProp1();				// NOTE: placeholder name (0x45e610)
	HProp getProp2();				// NOTE: placeholder name (0x45e650)
	void unknown45e690(int value);	// NOTE: placeholder name

	char	pad00[0x08];
	int		type;
	void	*data;
};

HProp OpR1F_Target45e690::getProp1()
{
	if (type == 1)
	{
		return *(HProp *)data;
	}
	else
	{
		return HProp();
	}
}

HProp OpR1F_Target45e690::getProp2()
{
	if (type == 2)
	{
		return *(HProp *)data;
	}
	else
	{
		return HProp();
	}
}

void OpR1F_Target45e690::unknown45e690(int value)
{
	if (type == 0)
		*(int *)data = value;
}

class TurnClock	// NOTE: placeholder name
{
public:
	int unknown9b8f00();	// NOTE: placeholder name (ICF'd getter)
};

class HTurnClock	// NOTE: placeholder name
{
	int	ID;
public:
	TurnClock *operator->() const;	// 0x9b73b0
};

bool OpS1e_isClockEarlier(const HTurnClock &a, const HTurnClock &b);	// NOTE: placeholder name

bool OpS1e_isClockEarlier(const HTurnClock &a, const HTurnClock &b)
{
	return a->unknown9b8f00() < b->unknown9b8f00();
}

struct OpS1e_Slot	// NOTE: placeholder name
{
	bool unknown45e7d0();	// NOTE: placeholder name

	int		type;
	char	pad04[0x04];
	int		value;
	bool	active;
};

bool OpS1e_Slot::unknown45e7d0()
{
	return active && (type == 5 || type == 7) && value != -2;
}

//==================================================================
// serialized record with a vector-of-vectors list
//==================================================================

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name
template <class T> void writeBinary(ostream &stream, T *value);	// NOTE: placeholder name
template <class T> void OpQ5_readVectors(istream &stream, vector< vector<T> > &v);	// NOTE: placeholder name (0x9d1c80)
template <class T> void OpQ5_writeVectors(ostream &stream, vector< vector<T> > &v);	// NOTE: placeholder name (0x9d1d20)
struct OpQ5_U9d1c80
{
	int pad;
};

struct OpQ5_U9d1d20
{
	int pad;
};

struct OpS1e_Block	// NOTE: placeholder name
{
	OpS1e_Block();		// 0x9d2670
	~OpS1e_Block();
	void read(istream &stream);		// 0x9cee40
	void write(ostream &stream);	// 0x9d26a0

	char	data[0x0c];
};

struct OpS1e_Record6f0	// NOTE: placeholder name
{
	OpS1e_Record6f0(istream &stream);	// 0x45e6f0
	void write(ostream &stream);		// 0x45e790

	int									value0;
	OpS1e_Block							block;
	vector< vector<OpQ5_U9d1c80> >	lists;
};

OpS1e_Record6f0::OpS1e_Record6f0(istream &stream)
{
	readBinary(stream, &value0);
	block.read(stream);
	OpQ5_readVectors(stream, lists);
}

void OpS1e_Record6f0::write(ostream &stream)
{
	writeBinary(stream, &value0);
	block.write(stream);
	OpQ5_writeVectors(stream, (vector< vector<OpQ5_U9d1d20> > &)lists);
}

//==================================================================
// object lists
//==================================================================

struct OpQ5_T9d1de0;
struct OpQ5_T9d1e90;
struct OpQ5_T9d1fd0;
struct OpQ5_T9d2010;
template <class T> void OpQ5_readPointer(istream &stream, T *&p);	// NOTE: placeholder name
template <class T> void OpQ5_writePointer(ostream &stream, T *&p);	// NOTE: placeholder name
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v);	// NOTE: placeholder name
template <class T> void OpQ5_deleteObjects(vector<T*> &v);	// NOTE: placeholder name

struct OpS1e_Entry	// NOTE: placeholder name
{
	int		ID;
	char	pad04[0x04];
	int		value;
};

struct OpS1e_EntryList	// NOTE: placeholder name
{
	OpS1e_Entry *lastParty();			// NOTE: placeholder name
	OpS1e_Entry *findParty(int ID);		// NOTE: placeholder name
	int countParties(int ID);				// NOTE: placeholder name

	char					pad00[0x50];
	vector<OpS1e_Entry*>	entries;
};

OpS1e_Entry *OpS1e_EntryList::lastParty()
{
	return entries.empty() ? NULL : entries.back();
}

OpS1e_Entry *OpS1e_EntryList::findParty(int ID)
{
	if (entries.empty())
		return NULL;
	for (int i = entries.size() - 1; i >= 0; i--)
	{
		if (entries[i]->ID == ID)
			return entries[i];
	}
	return NULL;
}

int OpS1e_EntryList::countParties(int ID)
{
	int count = 0;
	for (unsigned int i = 0; i < entries.size(); i++)
	{
		if (entries[i]->ID == ID && entries[i]->value != -2)
			count++;
	}
	return count;
}

struct OpS1e_HolderA	// NOTE: placeholder name
{
	OpS1e_HolderA(istream &stream);	// 0x45ee70

	OpQ5_T9d1de0			*main;
	vector<OpQ5_T9d1e90*>	list;
	bool					flag;
};

OpS1e_HolderA::OpS1e_HolderA(istream &stream)
{
	OpQ5_readPointer(stream, main);
	OpQ5_readObjects(stream, list, 0);
	readBinary(stream, &flag);
}

struct OpS1e_HolderB	// NOTE: placeholder name
{
	void write(ostream &stream);	// 0x45ef00

	OpQ5_T9d1fd0			*main;
	vector<OpQ5_T9d2010*>	list;
	bool					flag;
};

void OpS1e_HolderB::write(ostream &stream)
{
	OpQ5_writePointer(stream, main);
	OpQ5_writeObjects(stream, list);
	writeBinary(stream, &flag);
}

struct OpQ5_T9ed5d0;
template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name

struct OpS1e_HolderC	// NOTE: placeholder name
{
	~OpS1e_HolderC();	// 0x45ef50

	Entity					*main;
	vector<OpQ5_T9ed5d0*>	list;
	bool					flag;
};

OpS1e_HolderC::~OpS1e_HolderC()
{
	if (flag)
	{
		delete main;
		OpQ5_clearObjects(list);
	}
}

struct OpS1e_Range	// NOTE: placeholder name
{
	void read(istream &stream);	// 0x45f040
	int randomInRange_40c130();	// NOTE: placeholder name

	int	min;
	int	max;
};

void OpS1e_Range::read(istream &stream)
{
	readBinary(stream, &min);
	readBinary(stream, &max);
}

struct OpS1e_RangePair	// NOTE: placeholder name
{
	OpS1e_Range	first;
	OpS1e_Range	second;
};

struct OpR3d_Expiry	// NOTE: placeholder name
{
	int first;
	int second;

	void set(int first_, int second_);	// NOTE: placeholder name (0x690d40)
	void unknown45f070(OpS1e_RangePair &ranges);	// NOTE: placeholder name
};

void OpR3d_Expiry::unknown45f070(OpS1e_RangePair &ranges)
{
	set(ranges.first.randomInRange_40c130(), ranges.second.randomInRange_40c130());
}

//==================================================================
// record of four lists
//==================================================================

struct OpQ5_U9d2090
{
	int pad;
};

struct OpQ5_U9d2190
{
	int pad;
};

void OpR1F_write9d2130(ostream &stream, vector<int> *value);	// NOTE: placeholder name (0x9d2130)
void OpR1F_read9cf5e0(istream &stream, vector<int> *value);	// NOTE: placeholder name (0x9cf5e0)

struct OpS1e_Lists	// NOTE: placeholder name
{
	OpS1e_Lists(const OpS1e_Lists &other);	// 0x45f110
	OpS1e_Lists(istream &stream);			// 0x45f1e0
	void write(ostream &stream);			// 0x45f2c0

	vector<int>							list0;
	vector< vector<OpQ5_U9d2090> >	list10;
	vector< vector<OpQ5_U9d2090> >	list20;
	vector< vector<OpQ5_U9d2090> >	list30;
	char								pad40[0x04];
	string								text;
};

OpS1e_Lists::OpS1e_Lists(const OpS1e_Lists &other)
{
	list0 = other.list0;
	list10 = other.list10;
	list20 = other.list20;
	list30 = other.list30;
}

OpS1e_Lists::OpS1e_Lists(istream &stream)
{
	OpR1F_read9cf5e0(stream, &list0);
	OpQ5_readVectors(stream, list10);
	OpQ5_readVectors(stream, list20);
	OpQ5_readVectors(stream, list30);
}

void OpS1e_Lists::write(ostream &stream)
{
	OpR1F_write9d2130(stream, &list0);
	OpQ5_writeVectors(stream, (vector< vector<OpQ5_U9d2190> > &)list10);
	OpQ5_writeVectors(stream, (vector< vector<OpQ5_U9d2190> > &)list20);
	OpQ5_writeVectors(stream, (vector< vector<OpQ5_U9d2190> > &)list30);
}
