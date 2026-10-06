// op_u8a: vector helper instances in 0x9bf000-0x9d8000 (placeholder names)
// NOTE: placeholder names
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <istream>
#include <ostream>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;
	Point();	// 0x453b40
	Point(const Point &p);	// 0x46ca50
};

class Predicate_409b90
{
public:
	int field0;
	int field4;
	bool test(const Predicate_409b90 & arg0);
};

class HEntity
{
public:
	int ID;
	bool operator==(HEntity other) const;	// 0x9b78e0
};

struct OpU8a_Rec	// NOTE: placeholder name
{
	int count;
	int pad4;
	string name;
};

struct OpU8a_Rec4	// NOTE: placeholder name
{
	int pad0;
	string name;
};

struct OpU8a_Area	// NOTE: placeholder name
{
	char pad[16];
	OpU8a_Area(const OpU8a_Area &a);	// 0x40b130
};

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
istream &OpU8a_Fn9ede50(istream &stream, string &value);	// NOTE: placeholder name

extern vector<string> opU8a_names1;	// NOTE: placeholder name (0xd323ac)
extern vector<int> opU8a_map1;	// NOTE: placeholder name (0xd2f4f4)
extern vector<int> opU8a_values1;	// NOTE: placeholder name (0xcfe704)
extern vector<string> opU8a_names2;	// NOTE: placeholder name (0xd29808)
extern vector<int> opU8a_map2;	// NOTE: placeholder name (0xd161b4)
extern vector<int> opU8a_values2;	// NOTE: placeholder name (0xcf67c0)

//==================================================================
// random picks
//==================================================================

string OpU8a_randomString(vector<string> &v)	// NOTE: placeholder name
{
	return v[rng.rangeInt(0,v.size() - 1)];
}

Point OpU8a_randomPoint(vector<Point> &v)	// NOTE: placeholder name
{
	return v[rng.rangeInt(0,v.size() - 1)];
}

OpU8a_Rec *OpU8a_randomRec(vector<OpU8a_Rec*> &v)	// NOTE: placeholder name
{
	return v[rng.rangeInt(0,v.size() - 1)];
}

//==================================================================
// searches
//==================================================================

int OpU8a_indexOfPoint(vector<Point> &v, Point p)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (((Predicate_409b90&)v[i]).test((Predicate_409b90&)p))
			return i;
	}
	return -1;
}

bool OpU8a_anyPositive(vector<int> &v)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] > 0)
			return true;
	}
	return false;
}

bool OpU8a_anyNonZero(vector<int> &v)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i])
			return true;
	}
	return false;
}

int OpU8a_indexOfName(vector<OpU8a_Rec*> &v, string &name)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i]->name == name)
			return i;
	}
	return -1;
}

int OpU8a_indexOfEntity(vector<HEntity> &v, HEntity e)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == e)
			return i;
	}
	return -1;
}

bool OpU8a_containsEntity(vector<HEntity> &v, HEntity e)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == e)
			return true;
	}
	return false;
}

bool OpU8a_removeEntity(vector<HEntity> &v, HEntity e)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == e)
		{
			v.erase(v.begin()+i);
			return true;
		}
	}
	return false;
}

bool OpU8a_removePoint(vector<Point> &v, Point p)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (((Predicate_409b90&)v[i]).test((Predicate_409b90&)p))
		{
			v.erase(v.begin()+i);
			return true;
		}
	}
	return false;
}

void OpU8a_appendUnique(vector<Point> &out, vector<Point> &in)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < in.size(); i++)
	{
		for (unsigned int j = 0; j < out.size(); j++)
		{
			if (((Predicate_409b90&)out[j]).test((Predicate_409b90&)in[i]))
				goto next;
		}
		out.push_back(in[i]);
next:;
	}
}

int OpU8a_indexOfName4(vector<OpU8a_Rec4*> &v, string &name)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i]->name == name)
			return i;
	}
	return -1;
}

OpU8a_Area OpU8a_randomArea(vector<OpU8a_Area> &v)	// NOTE: placeholder name
{
	return v[rng.rangeInt(0,v.size() - 1)];
}

bool OpU8a_containsString(vector<string> &v, string s)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == s)
			return true;
	}
	return false;
}

void OpU8a_insertString(vector<string> &v, int index, string s)	// NOTE: placeholder name
{
	if (index == v.size())
		v.push_back(s);
	else
		v.insert(v.begin()+index,s);
}

bool OpU8a_lookup1(string &name, int *value)	// NOTE: placeholder name
{
	*value = 0;
	vector<string>::iterator it = find(opU8a_names1.begin(),opU8a_names1.end(),name);
	if (it == opU8a_names1.end() || *it != name)
		return false;
	*value = opU8a_values1[opU8a_map1[it - opU8a_names1.begin()]];
	return true;
}

bool OpU8a_lookup2(string &name, int *value)	// NOTE: placeholder name
{
	*value = 0;
	vector<string>::iterator it = find(opU8a_names2.begin(),opU8a_names2.end(),name);
	if (it == opU8a_names2.end() || *it != name)
		return false;
	*value = opU8a_values2[opU8a_map2[it - opU8a_names2.begin()]];
	return true;
}

int OpU8a_randomIndexOf(unsigned char *data, unsigned int length, unsigned char c)	// NOTE: placeholder name
{
	vector<unsigned int> matches;
	for (unsigned int i = 0; i < length; i++)
	{
		if (data[i] == c)
			matches.push_back(i);
	}
	if (matches.empty())
	{
		return -1;
	}
	else
	{
		return matches[rng.rangeInt(0,matches.size() - 1)];
	}
}

string OpU8a_toString(unsigned int value)	// NOTE: placeholder name
{
	string result;
	stringstream ss;
	if (!(ss << value && OpU8a_Fn9ede50(ss,result)))
		logError("lexical_cast()","Bad lexical cast");
	return result;
}

//==================================================================
// record list readers
//==================================================================

struct OpU8a_RecA	// NOTE: placeholder name
{
	char pad[0xb0];
	OpU8a_RecA();	// 0x4bf280
	~OpU8a_RecA();	// 0x4bf300
	void load(istream &stream);	// 0x448430
};

struct OpU8a_Range	// NOTE: placeholder name
{
	int low;
	int high;
};

struct OpU8a_RecB	// NOTE: placeholder name
{
	bool unknown0;
	int unknown4;
	int unknown8;
	int unknownc;
	int unknown10;
	OpU8a_Range unknown14;
	OpU8a_Range unknown1c;
	OpU8a_Range unknown24;
	vector<int> unknown2c;
	OpU8a_Range unknown3c;
	OpU8a_Range unknown44;
	OpU8a_Range unknown4c;
	OpU8a_Range unknown54;
	OpU8a_Range unknown5c;
	OpU8a_Range unknown64;
	OpU8a_Range unknown6c;
	OpU8a_Range unknown74;
	OpU8a_Range unknown7c;
	OpU8a_RecB();	// 0x448aa0
	~OpU8a_RecB();	// 0x448b40
	void load(istream &stream);	// 0x448630
};

struct OpU8a_RecC	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	string text;
	OpU8a_RecC();	// 0x454a10
	void read(istream &stream);	// 0x454a30
};

struct OpU8a_RecD	// NOTE: placeholder name
{
	char pad[0x40];
	OpU8a_RecD();	// 0x455dd0
	~OpU8a_RecD();	// 0x9e7360
	void read(istream &stream);	// 0x517da0
};

template <class T> void OpU8a_readLoaded(istream &stream, vector<T> &v)	// NOTE: placeholder name
{
	T item;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(item);
		v.back().load(stream);
		count--;
	}
}

template <class T> void OpU8a_readRead(istream &stream, vector<T> &v)	// NOTE: placeholder name
{
	T item;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(item);
		v.back().read(stream);
		count--;
	}
}

template void OpU8a_readLoaded<OpU8a_RecA>(istream &stream, vector<OpU8a_RecA> &v);
template void OpU8a_readLoaded<OpU8a_RecB>(istream &stream, vector<OpU8a_RecB> &v);
template void OpU8a_readRead<OpU8a_RecC>(istream &stream, vector<OpU8a_RecC> &v);
template void OpU8a_readRead<OpU8a_RecD>(istream &stream, vector<OpU8a_RecD> &v);

//==================================================================
// reference lists
//==================================================================

struct OpQ5_U9dfd70;
template <class T> void OpQ5_readReferences(istream &stream, vector<T*> &v, vector<T*> &list);	// NOTE: placeholder name

template <class T> void OpU8a_readReferenceLists(istream &stream, vector<vector<T*> > &lists, vector<T*> &all)	// NOTE: placeholder name
{
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		lists.push_back(vector<T*>());
		OpQ5_readReferences(stream,lists.back(),all);
		count--;
	}
}

template void OpU8a_readReferenceLists<OpQ5_U9dfd70>(istream &stream, vector<vector<OpQ5_U9dfd70*> > &lists, vector<OpQ5_U9dfd70*> &all);
