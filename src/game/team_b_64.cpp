// team_b_64: small template/container helpers in 0x9d2000-0xa05000 whose exe bodies are ICF-folded
// instances; each is reconstructed here over a private element type (placeholder names).
#include <vector>
#include <string>
#include <istream>
#include <algorithm>
#include <new>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

//==================================================================
// 2D array readers (0x9d29d0, 0x9d2ae0, 0x9d2cd0, 0x9d2de0, 0x9d3360)
//==================================================================

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name

class OpR1F_ColorProp461b70	// NOTE: placeholder name/layout (20 bytes)
{
public:
	char pad[20];
	OpR1F_ColorProp461b70();
	void read(istream &stream);
};

class OpR1F_Style460e50	// NOTE: placeholder name/layout (52 bytes)
{
public:
	char pad[52];
	OpR1F_Style460e50();
	void read(istream &stream);
};

struct TeamB_Pt453b40	// NOTE: placeholder name (8-byte pair defaulting to -1,-1; same body as Point())
{
	int x;
	int y;
	TeamB_Pt453b40();
};

TeamB_Pt453b40::TeamB_Pt453b40()
{
	x = -1;
	y = -1;
}

template <class T> class TeamB_Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *cells;
	void read(istream &stream);
	void readRaw(istream &stream);
	void resize(int width_, int height_, istream *stream);
};

template <class T> void TeamB_Array2D<T>::read(istream &stream)
{
	readBinary(stream,&width);
	readBinary(stream,&height);
	cells = new T[width*height];
	for (int i = 0; i < width*height; i++)
		cells[i].read(stream);
}

template <class T> void TeamB_Array2D<T>::readRaw(istream &stream)
{
	readBinary(stream,&width);
	readBinary(stream,&height);
	cells = new T[width*height];
	for (int i = 0; i < width*height; i++)
		stream.read((char*)&cells[i],sizeof(T));
}

template <class T> void TeamB_Array2D<T>::resize(int width_, int height_, istream *stream)
{
	delete [] cells;
	width = width_;
	height = height_;
	cells = new T[width*height];
	if (stream)
	{
		for (int i = 0; i < width*height; i++)
			stream->read((char*)&cells[i],sizeof(T));
	}
}

template void TeamB_Array2D<OpR1F_ColorProp461b70>::read(istream &stream);
template void TeamB_Array2D<OpR1F_Style460e50>::read(istream &stream);
template void TeamB_Array2D<OpR1F_ColorProp461b70>::resize(int width_, int height_, istream *stream);
template void TeamB_Array2D<OpR1F_Style460e50>::resize(int width_, int height_, istream *stream);
template void TeamB_Array2D<TeamB_Pt453b40>::readRaw(istream &stream);

//==================================================================
// 0x9d4b30: random index of an entry equal to value (-1 if none)
//==================================================================

template <class T> struct TeamB_Alloc9d4b30 : allocator<T>	// NOTE: placeholder name (private vector instances)
{
	template <class U> struct rebind { typedef TeamB_Alloc9d4b30<U> other; };
	TeamB_Alloc9d4b30() {}
	template <class U> TeamB_Alloc9d4b30(const TeamB_Alloc9d4b30<U> &) {}
};

int OpW7_pickIndex_9d4b30(bool *values, unsigned int count, bool value)	// NOTE: placeholder name
{
	vector<unsigned int, TeamB_Alloc9d4b30<unsigned int> > matches;
	for (unsigned int i = 0; i < count; i++)
	{
		if (values[i] == value)
			matches.push_back(i);
	}
	if (matches.empty())
		return -1;
	else
		return matches[rng.rangeInt(0,matches.size() - 1)];
}

//==================================================================
// 0x9d8fc0: insert at index (append when index == size)
//==================================================================

struct TeamB_W9d8fc0	// NOTE: placeholder name (4-byte handle)
{
	int id;
};

void teamb_insertAt_9d8fc0(vector<TeamB_W9d8fc0> &v, unsigned int index, TeamB_W9d8fc0 value)	// NOTE: placeholder name
{
	if (index == v.size())
		v.push_back(value);
	else
		v.insert(v.begin() + index,value);
}

//==================================================================
// 0x9df3f0: read a counted list of triples
//==================================================================

struct TeamB64_Triple	// NOTE: placeholder name
{
	TeamB64_Triple() throw();	// 0x46cb90
	~TeamB64_Triple();	// 0x9b7080
	TeamB64_Triple(const TeamB64_Triple &other);
	void read(istream &stream);	// NOTE: placeholder name

	vector<int>	xs;
	vector<int>	ys;
	vector<int>	zs;
};

void teamb_readTriples_9df3f0(istream &stream, vector<TeamB64_Triple> &v)	// NOTE: placeholder name
{
	TeamB64_Triple triple;
	int count;
	stream.read((char*)&count,4);
	while (count)
	{
		v.push_back(triple);
		v.back().read(stream);
		count--;
	}
}

//==================================================================
// 0x9e2970 / 0x9e29b0: sorted handle lists
//==================================================================

struct TeamB_H9e2970	// NOTE: placeholder name (4-byte handle)
{
	int id;
	bool operator<(const TeamB_H9e2970 &o) const;
};

struct TeamB_H9e29b0	// NOTE: placeholder name (4-byte handle)
{
	int id;
	bool operator<(TeamB_H9e29b0 o) const;
	bool operator!=(TeamB_H9e29b0 o) const;
};

class TeamB_World9e2970	// NOTE: placeholder name
{
public:
	bool contains_9e2970(vector<TeamB_H9e2970> *list, TeamB_H9e2970 h);	// NOTE: placeholder name
	void insertSorted_9e29b0(vector<TeamB_H9e29b0> *list, TeamB_H9e29b0 h);	// NOTE: placeholder name
};

bool TeamB_World9e2970::contains_9e2970(vector<TeamB_H9e2970> *list, TeamB_H9e2970 h)
{
	return binary_search(list->begin(),list->end(),h);
}

void TeamB_World9e2970::insertSorted_9e29b0(vector<TeamB_H9e29b0> *list, TeamB_H9e29b0 h)
{
	vector<TeamB_H9e29b0>::iterator it = lower_bound(list->begin(),list->end(),h);
	if (it == list->end() || *it != h)
		list->insert(it,h);
}

//==================================================================
// 0x9e2e40: move a block of entries to another position
//==================================================================

struct TeamB_E9e2e40	// NOTE: placeholder name (4-byte entry)
{
	int id;
};

void teamb_moveBlock_9e2e40(vector<TeamB_E9e2e40> &v, unsigned int from, unsigned int count, unsigned int to)	// NOTE: placeholder name
{
	if (from == to || count == 0)
		return;
	vector<TeamB_E9e2e40> block(v.begin() + from,v.begin() + from + count);
	v.erase(v.begin() + from,v.begin() + from + count);
	if (from < to)
	{
		to -= count;
		to++;
	}
	v.insert(v.begin() + to,block.begin(),block.end());
}

//==================================================================
// 0x9e3160: std::sort over strings with a comparison function
//==================================================================

void teamb_sortStrings_9e3160(vector<string> &v, bool (*pred)(const string &, const string &))	// NOTE: placeholder name (instantiates std::sort)
{
	sort(v.begin(),v.end(),pred);
}

//==================================================================
// 0x9ed6e0 / 0x9ed730: 2D array of points
//==================================================================

struct Point
{
	int x;
	int y;

	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);
};

class OpX5F_PointGrid	// NOTE: placeholder name
{
public:
	void resize(int width_, int height_);	// NOTE: placeholder name (0x9ed730)
	void fill(Point p);	// NOTE: placeholder name (0x9ed6e0)

	int width;
	int height;
	Point *data;
};

void OpX5F_PointGrid::fill(Point p)
{
	for (int i = 0; i < width*height; i++)
		data[i] = p;
}

void OpX5F_PointGrid::resize(int width_, int height_)
{
	if (width_ == width && height_ == height)
		return;
	delete [] data;
	width = width_;
	height = height_;
	data = (Point *)new TeamB_Pt453b40[width*height];
}

//==================================================================
// 0x9e7420: copy constructor of a room-like record
//==================================================================

struct TeamB_R9e7420	// NOTE: placeholder name (16-byte rect)
{
	int x, y, w, h;
	TeamB_R9e7420(const TeamB_R9e7420 &r);
};

struct TeamB_E8_9e7420 { int a, b; };	// NOTE: placeholder name
struct TeamB_E12_9e7420 { int a, b, c; };	// NOTE: placeholder name

struct TeamB_Room9e7420	// NOTE: placeholder name/layout
{
	int id;
	TeamB_R9e7420 rect;
	vector<TeamB_E8_9e7420> v14;
	int i24;
	vector<TeamB_E8_9e7420> v28;
	vector<TeamB_E12_9e7420> v38;
	vector<TeamB_E12_9e7420> v48;
	int i58;
	vector<TeamB_E12_9e7420> v5c;
};

void teamb_copyRoom_9e7420(TeamB_Room9e7420 *dst, const TeamB_Room9e7420 &src)	// NOTE: placeholder name (emits the copy ctor)
{
	new (dst) TeamB_Room9e7420(src);
}

//==================================================================
// 0xa04300: vector iterator difference
//==================================================================

struct TeamB_CItA04300	// NOTE: placeholder name
{
	int *ptr;
	int operator-(const TeamB_CItA04300 &right) const;
};

struct TeamB_ItA04300 : TeamB_CItA04300	// NOTE: placeholder name
{
	int operator-(const TeamB_CItA04300 &right) const;
};

int TeamB_ItA04300::operator-(const TeamB_CItA04300 &right) const
{
	TeamB_CItA04300 tmp(*this);
	return tmp - right;
}

//==================================================================
// 0x9fb2e0: uninitialized copy of 4-byte handles (vector copy)
//==================================================================

struct TeamB_H9fb2e0	// NOTE: placeholder name (4-byte handle with copy ctor and dtor)
{
	int id;
	TeamB_H9fb2e0(const TeamB_H9fb2e0 &h);
	~TeamB_H9fb2e0();
};

void teamb_copyHandles_9fb2e0(vector<TeamB_H9fb2e0> *dst, const vector<TeamB_H9fb2e0> &src)	// NOTE: placeholder name (emits _Uninit_copy)
{
	new (dst) vector<TeamB_H9fb2e0>(src);
}
