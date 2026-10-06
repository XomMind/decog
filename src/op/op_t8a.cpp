// op_t8a: std (VS2010) template instances in 0x9ca000-0x9d4000 over placeholder element types.
// NOTE: placeholder names; one OpT8a_T<addr> element type per exe function instance
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;

template void vector<float>::_Insert_n(vector<float>::const_iterator _Where, size_t _Count, const float &_Val);

template basic_string<char>::basic_string(vector<char>::iterator _First, vector<char>::iterator _Last);

struct OpY1_CharEqualNoCase	// NOTE: placeholder name (defined in op_y1.cpp)
{
	OpY1_CharEqualNoCase() {}
	bool operator()(char a, char b);
};

template string::iterator std::search(string::iterator, string::iterator, string::iterator, string::iterator, OpY1_CharEqualNoCase);

template string &string::assign(istreambuf_iterator<char> _First, istreambuf_iterator<char> _Last);

int OpT8a_findStringIndex(const string *list, unsigned int count, string s)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
	{
		if (list[i] == s)
		{
			return i;
		}
	}
	return -1;
}

int OpT8a_sumVector(vector<int> &v)	// NOTE: placeholder name
{
	int total = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		total += v[i];
	}
	return total;
}

class OpS_Frame	// NOTE: placeholder name (defined in op_s1a.cpp)
{
public:
	vector<bool> marked;
	bool hasState;
	int unknown18;
	int unknown1c;
	int unknown20;
	int unknown24;
	int unknown28;
	int unknown2c;

	OpS_Frame(const vector<bool> &marked_, bool hasState_, int unknown18_, int unknown1c_, int unknown20_, int unknown24_, int unknown28_, int unknown2c_);
};

void OpS_deleteBack(vector<OpS_Frame*> &frames)	// NOTE: placeholder name (declared in op_s1a.cpp)
{
	delete frames.back();
	frames.pop_back();
}

//==================================================================
// delete helpers over vectors of pointers (0x9ce5d0-0x9cea50)
//==================================================================

struct OpT8a_T9e7060	// NOTE: placeholder name
{
	int m0;
	~OpT8a_T9e7060();
};

struct OpT8a_T9e70c0	// NOTE: placeholder name
{
	int m0;
	~OpT8a_T9e70c0();
};

class OpT8a_VBase	// NOTE: placeholder name
{
public:
	virtual ~OpT8a_VBase();
};

struct OpT8a_PtrGrid	// NOTE: placeholder name
{
	int width;
	int height;
	int **data;

	void deleteContents() throw();
};

void OpT8a_PtrGrid::deleteContents() throw()
{
	for (int i = 0; i < width*height; i++)
		delete data[i];
	delete [] data;
	height = 0;
	width = 0;
	data = NULL;
}

void OpT8a_deleteObject(vector<OpT8a_T9e7060*> &v, int index)	// NOTE: placeholder name
{
	delete v[index];
	v.erase(v.begin()+index);
}

void OpT8a_eraseAt(vector<int> &v, unsigned int &i)	// NOTE: placeholder name
{
	v.erase(v.begin()+i);
	i--;
}

void OpT8a_deleteBack(vector<OpT8a_T9e70c0*> &v)	// NOTE: placeholder name
{
	delete v.back();
	v.pop_back();
}

void OpT8a_deleteVectorContents(vector<OpT8a_VBase*> &v)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
		delete v[i];
}

void OpT8a_deleteVectorElement(vector<OpT8a_VBase*> &v, int index)	// NOTE: placeholder name
{
	delete v[index];
	v.erase(v.begin()+index);
}

template vector<int>::vector(vector<int>::iterator _First, vector<int>::iterator _Last);

//==================================================================
// Array2D<XCell> (see op_s7.cpp)
//==================================================================

struct XCell;

class OpT8a_CellGrid	// NOTE: placeholder name (op_s7.cpp OpS7_CellGrid)
{
public:
	int width;
	int height;
	XCell *cells;

	OpT8a_CellGrid(const OpT8a_CellGrid &other);	// 0x9cdd40
	~OpT8a_CellGrid();	// 0x9cec20
	void resize(int width_, int height_);	// 0x9ce020
	void copyFrom(int destX, int destY, OpT8a_CellGrid &src, int srcX, int srcY, int copyWidth, int copyHeight);	// 0x9ce150
	void contract(int left, int right, int top, int bottom);	// 0x9ce440
};

void OpT8a_CellGrid::contract(int left, int right, int top, int bottom)
{
	if (left == 0 && right == 0 && top == 0 && bottom == 0)
		return;
	OpT8a_CellGrid old(*this);
	resize(width - left - right,height - top - bottom);
	copyFrom(0,0,old,left,top,width,height);
}

template void vector<int>::assign(int _Count, int _Val);

int OpT8a_findString(vector<string> &list, string s)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (list[i] == s)
		{
			return i;
		}
	}
	return -1;
}

template vector<char>::iterator std::transform(string::iterator, string::iterator, vector<char>::iterator, int (*)(int));

template vector<unsigned int>::vector(unsigned int _Count, unsigned int _Val);

void OpT8a_readInts(istream &in, vector<int> &v)	// NOTE: placeholder name
{
	int count;
	in.read((char*)&count,4);
	while (count)
	{
		int value;
		in.read((char*)&value,4);
		v.push_back(value);
		count--;
	}
}

template string std::operator+(char _Left, string &&_Right);
template string std::operator+(string &&_Left, char _Right);

//==================================================================
// Array2D<int> layer (0x9cfc50-0x9cfd10)
//==================================================================

struct OpT8a_IntGrid	// NOTE: placeholder name (Array2D<int>)
{
	int width;
	int height;
	int *cells;

	OpT8a_IntGrid();	// 0x9d2670
	~OpT8a_IntGrid();	// 0x9cec20
	void resize(int width_, int height_, istream *stream);	// 0x9d4090
	void fill(int value);	// 0x9ec800
};

class OpT8a_Layer	// NOTE: placeholder name
{
public:
	int unknown0;
	int unknown4;
	OpT8a_IntGrid grid;
	int width;
	int height;
	int unknown1c;
	int unknown20;
	int fillValue;
	int unknown28;

	OpT8a_Layer(int unknown0_, int unknown4_, int unknown1c_, int unknown20_, int width_, int height_, int fillValue_, bool clear_);
	void clear();	// 0x9ed5b0
};

OpT8a_Layer::OpT8a_Layer(int unknown0_, int unknown4_, int unknown1c_, int unknown20_, int width_, int height_, int fillValue_, bool clear_)
	: unknown0(unknown0_)
	, unknown4(unknown4_)
{
	width = width_;
	height = height_;
	unknown1c = unknown1c_;
	unknown20 = unknown20_;
	fillValue = fillValue_;
	grid.resize(width_,height_,NULL);
	if (clear_)
		clear();
}

class OpT8a_Holder	// NOTE: placeholder name
{
public:
	int unknown0;
	int unknown4;
	OpT8a_IntGrid grid;

	OpT8a_Holder();
};

OpT8a_Holder::OpT8a_Holder()
{
	OpT8a_Layer layer(1,1,0,0,1,1,0,false);
}
