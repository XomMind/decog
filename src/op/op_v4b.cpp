// op_v4b: misc small functions matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; names are placeholders.
#include <istream>
#include <ostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
using namespace std;

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name
template <class T> void writeBinary(ostream &stream, T *value);	// NOTE: placeholder name
class HEntity
{
	int	ID;
public:
	HEntity();
};

int OpU8a_indexOfEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d3110)

template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name
template <class T> void OpS8a_writeRawVector(ostream &stream, vector<T> &v);	// NOTE: placeholder name
void OpT8a_readInts(istream &in, vector<int> &v);	// NOTE: placeholder name
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
class MapRecord;
void unknown_9e40e0(ostream &os, vector<MapRecord *> &records);	// NOTE: placeholder name
struct OpQ5_T9e13a0;


struct OpV4b_Ints3
{
	vector<int>	list0;
	vector<int>	list10;
	int			value20;

	void OpV4b_read(istream &stream);	// NOTE: placeholder name
	void OpV4b_write(ostream &stream);	// NOTE: placeholder name
};

void OpV4b_Ints3::OpV4b_read(istream &stream)
{
	OpT8a_readInts(stream,list0);
	OpT8a_readInts(stream,list10);
	readBinary(stream,&value20);
}

void OpV4b_Ints3::OpV4b_write(ostream &stream)
{
	OpS8a_writeRawVector(stream,list0);
	OpS8a_writeRawVector(stream,list10);
	writeBinary(stream,&value20);
}

struct OpV4b_Dims
{
	int width;
	int height;
	char OpV4b_inBounds(int x, int y);	// NOTE: placeholder name
};

char OpV4b_Dims::OpV4b_inBounds(int x, int y)
{
	return (x >= 0 && x < width && y >= 0 && y < height) ? 1 : 0;
}

struct OpV4b_Tri	// NOTE: placeholder name
{
	vector<unsigned int>	a;
	vector<unsigned int>	b;
	vector<unsigned int>	c;

	~OpV4b_Tri();
};

OpV4b_Tri::~OpV4b_Tri()
{
}

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	bool isEmpty();	// NOTE: placeholder name (0x9b81b0)
	void remove(T value);	// 0x9bab80
	T &pick();	// 0x9ba470
	void removeAt(int index);	// NOTE: placeholder name (0x9c1d20)
	void OpV4b_pickAll(vector<T> &out);	// NOTE: placeholder name
};

template <class T>
void OpR5h_WL<T>::removeAt(int index)
{
	total -= weights[index];
	removeVectorElement(values,index);
	removeVectorElement(weights,index);
}

template <class T>
void OpR5h_WL<T>::OpV4b_pickAll(vector<T> &out)
{
	T value;
	OpR5h_WL<T> copy(*this);
	while (!copy.isEmpty())
	{
		value = copy.pick();
		out.push_back(value);
		copy.remove(value);
	}
}

template void OpR5h_WL<int>::OpV4b_pickAll(vector<int> &out);

//==================================================================
// STL instances
//==================================================================

template wstring &wstring::assign(const wstring &_Right, size_t _Roff, size_t _Count);	// 0x9bbef0

struct OpV4b_S172	// NOTE: placeholder name
{
	char pad[0xac];
};

struct OpV4b_S132	// NOTE: placeholder name
{
	char pad[0x84];
};

template void vector<OpV4b_S172>::_Tidy();	// 0x9be7f0
template vector<OpV4b_S172>::~vector();	// 0x9b48a0
template void vector<OpV4b_S132>::_Tidy();	// 0x9be8e0
template vector<OpV4b_S132>::~vector();	// 0x9b4a80
template wstring &wstring::erase(size_t _Off, size_t _Count);	// 0x9c2790
template wstring &wstring::assign(const wchar_t *_Ptr, size_t _Count);	// 0x9c2710
template size_t wstring::max_size() const;	// 0x9c2540

struct OpV4b_StrPair	// NOTE: placeholder name
{
	string first;
	string second;

	OpV4b_StrPair(const string &a, const string &b);
};

OpV4b_StrPair::OpV4b_StrPair(const string &a, const string &b)
	: first		(a)
	, second	(b)
{
}
template void wstring::_Chassign(size_t _Off, size_t _Count, wchar_t _Ch);	// 0x9c2830
template void wstring::_Eos(size_t _Newsize);	// 0x9c2880
template bool wstring::_Grow(size_t _Newsize, bool _Trim);	// 0x9c28c0
template void istreambuf_iterator<char>::_Inc();	// 0x9c2e50
template char istreambuf_iterator<char>::_Peek() const;	// 0x9c2eb0

template void OpR5h_WL<int>::removeAt(int index);

struct OpQ5_U9da940
{
	int pad;
};

template <class T>
class OpV4b_WL2	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	void removeAt(int index);	// NOTE: placeholder name (0x9c1b60)
	void removeEntity(HEntity entity);	// NOTE: placeholder name
};

template <class T>
void OpV4b_WL2<T>::removeAt(int index)
{
	total -= weights[index];
	OpQ5_eraseAt(values,index);
	removeVectorElement(weights,index);
}

template void OpV4b_WL2<OpQ5_U9da940>::removeAt(int index);

template <class T>
void OpV4b_WL2<T>::removeEntity(HEntity entity)
{
	int index = OpU8a_indexOfEntity((vector<HEntity>&)values,entity);
	if (index != -1)
		removeAt(index);
}

template void OpV4b_WL2<OpQ5_U9da940>::removeEntity(HEntity entity);

struct OpV4b_A	// NOTE: placeholder name
{
	int a, b, c, d;
};
struct OpV4b_B	// NOTE: placeholder name
{
	int a, b, c, d;
};
struct OpV4b_C	// NOTE: placeholder name
{
	int a, b, c, d;
};

template void vector<OpV4b_A>::push_back(const OpV4b_A &_Val);	// 0x9b7510
template void vector<OpV4b_B>::push_back(OpV4b_B &&_Val);	// 0x9b9a70
template void vector<OpV4b_C>::push_back(OpV4b_C &&_Val);	// 0x9b8f20

struct Point
{
	int x;
	int y;

	Point(const Point &p, int dx, int dy);	// 0x4099c0
};

class OpV4b_IntGrid	// NOTE: placeholder name (Array2D<int>)
{
public:
	int width;
	int height;
	int *cells;

	Point find_9cefa0(int value);	// NOTE: placeholder name
};

class OpV4b_Offset	// NOTE: placeholder name
{
public:
	int unknown0;
	int unknown4;
	OpV4b_IntGrid grid;
	int unknown14;
	int unknown18;
	int offsetX;
	int offsetY;

	Point findOffset(int value);	// NOTE: placeholder name
};

Point OpV4b_Offset::findOffset(int value)
{
	return Point(grid.find_9cefa0(value),offsetX,offsetY);
}

struct OpV4b_Objs3	// NOTE: placeholder name
{
	vector<OpQ5_T9e13a0*>	objects;
	vector<int>				list10;
	int						value20;

	void OpV4b_read(istream &stream);	// NOTE: placeholder name
	void OpV4b_write(ostream &stream);	// NOTE: placeholder name
};

void OpV4b_Objs3::OpV4b_read(istream &stream)
{
	OpQ5_readObjects(stream,objects,0);
	OpT8a_readInts(stream,list10);
	readBinary(stream,&value20);
}

void OpV4b_Objs3::OpV4b_write(ostream &stream)
{
	unknown_9e40e0(stream,(vector<MapRecord*>&)objects);
	OpS8a_writeRawVector(stream,list10);
	writeBinary(stream,&value20);
}

struct OpV4b_D	// NOTE: placeholder name
{
	int a, b, c, d;
};

template vector<OpV4b_D> &vector<OpV4b_D>::operator=(const vector<OpV4b_D> &_Right);	// 0x9b7660

struct OpV4b_E12	// NOTE: placeholder name
{
	int a, b, c;
};
struct OpV4b_E16	// NOTE: placeholder name
{
	int a, b, c, d;
};
struct OpV4b_E20	// NOTE: placeholder name
{
	int a, b, c, d, e;
};

struct OpV4b_Lists	// NOTE: placeholder name
{
	int					unknown0;
	int					unknown4;
	int					unknown8;
	int					unknownC;
	vector<OpV4b_E12>	list10;
	vector<OpV4b_E16>	list20;
	vector<OpV4b_E20>	list30;

	OpV4b_Lists(const OpV4b_Lists &other);
};

OpV4b_Lists::OpV4b_Lists(const OpV4b_Lists &other)
	: unknown0	(other.unknown0)
	, unknown4	(other.unknown4)
	, unknown8	(other.unknown8)
	, unknownC	(other.unknownC)
	, list10	(other.list10)
	, list20	(other.list20)
	, list30	(other.list30)
{
}

template void vector<float>::_Assign_n(size_t _Count, const float &_Val);	// 0x9c0800

struct OpV4b_V	// NOTE: placeholder name
{
	int a, b, c;
};

typedef _Tree<_Tmap_traits<char,OpV4b_V,less<char>,allocator<pair<const char,OpV4b_V> >,false> > OpV4b_Tree;

template OpV4b_Tree::const_iterator OpV4b_Tree::find(const char &_Keyval) const;	// 0x9b8d10
