// team_c_09: Array2D<int> helpers (pad, view wrappers), Array2D getMaxX/Y, vector<int>::assign<int>
// NOTE: all non-std names are placeholders
#include <istream>
#include <vector>
using namespace std;

template <class T> void readBinary(istream &stream, T *value);

template <class T> class OpC_Arr2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *cells;

	OpC_Arr2D(istream &stream);
	OpC_Arr2D(OpC_Arr2D<T> *source);
	~OpC_Arr2D();
	void OpS8e_blit(int x, int y, OpC_Arr2D<T> *src);
	void OpS8e_resize(int width_, int height_);
	void OpS8e_fill(T value);
	void OpS8e_add(OpC_Arr2D<T> *other);
	void OpS8e_pad(T value, int left, int right, int top, int bottom);
};

template <class T> OpC_Arr2D<T>::OpC_Arr2D(istream &stream)
{
	readBinary(stream,&width);
	readBinary(stream,&height);
	cells = new T[width*height];
	for (int i = 0; i < width*height; i++)
		stream.read((char*)&cells[i],sizeof(T));
}

template <class T> void OpC_Arr2D<T>::OpS8e_resize(int width_, int height_)
{
	if (width_ == width && height_ == height)
		return;
	delete [] cells;
	width = width_;
	height = height_;
	cells = new T[width*height];
}

template <class T> void OpC_Arr2D<T>::OpS8e_fill(T value)
{
	for (int i = 0; i < width*height; i++)
		cells[i] = value;
}

template <class T> void OpC_Arr2D<T>::OpS8e_add(OpC_Arr2D<T> *other)
{
	for (int i = 0; i < width*height; i++)
		cells[i] = cells[i] + other->cells[i];
}

template <class T> void OpC_Arr2D<T>::OpS8e_pad(T value, int left, int right, int top, int bottom)
{
	if (left == 0 && right == 0 && top == 0 && bottom == 0)
		return;
	int prevWidth = width;
	int prevHeight = height;
	OpC_Arr2D<T> original(this);
	OpS8e_resize(width+left+right,height+top+bottom);
	OpS8e_blit(left,top,&original);
	if (left)
	{
		for (int i = 0; i < width-prevWidth-right; i++)
		{
			for (int j = 0; j < height; j++)
				cells[i*height+j] = value;
		}
	}
	if (right)
	{
		for (int i = left+prevWidth; i < width; i++)
		{
			for (int j = 0; j < height; j++)
				cells[i*height+j] = value;
		}
	}
	if (top)
	{
		for (int i = left; i < prevWidth+left; i++)
		{
			for (int j = 0; j < height-prevHeight-bottom; j++)
				cells[i*height+j] = value;
		}
	}
	if (bottom)
	{
		for (int i = left; i < prevWidth+left; i++)
		{
			for (int j = top+prevHeight; j < height; j++)
				cells[i*height+j] = value;
		}
	}
}

// 0x9ec470 (OpS8e_Array2D<int>::OpS8e_pad in op_s8e_arr.cpp differs only in local names, which move the stack slots)
template void OpC_Arr2D<int>::OpS8e_pad(int value, int left, int right, int top, int bottom);

//==================================================================
// int grid (width, height, int *cells) and the view that embeds one at +8
//==================================================================
struct OpC_IntGrid	// NOTE: placeholder name
{
	int width;
	int height;
	int *cells;

	void resize(int width_, int height_, istream *stream);	// OpS8a_Array2D<int>::resize (0x9d4090)
	void fill(int value);	// 0x9ec800
	void add(OpC_IntGrid *other);	// 0x9ec6b0
};

class OpC_View	// NOTE: placeholder name (layout of OpV4c_View)
{
public:
	int field0;
	int field4;
	OpC_IntGrid grid;
	int width;
	int height;
	int offsetX;
	int offsetY;
	int fillValue;
	int lastValue;

	void init(int x_, int y_, int fillValue_);	// 0x9cffc0
	void fillGrid(int value);	// 0x9d0030
	void addGrid(OpC_View *other);	// 0x9d0140
	void clearGrid();	// 0x9ed5b0
};

void OpC_View::init(int x_, int y_, int fillValue_)
{
	height = 1;
	width = 1;
	offsetY = 0;
	offsetX = 0;
	grid.resize(1,1,0);
	grid.fill(fillValue_);
	field0 = x_;
	field4 = y_;
	fillValue = fillValue_;
}

void OpC_View::fillGrid(int value)
{
	grid.fill(value);
}

void OpC_View::addGrid(OpC_View *other)
{
	grid.add(&other->grid);
}

void OpC_View::clearGrid()
{
	grid.fill(fillValue);
}

//==================================================================
// Array2D getMaxX / getMaxY (folded across element types)
//==================================================================
template <class T> class OpC_Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *data;

	int getMaxX();
	int getMaxY();
};

template <class T> int OpC_Array2D<T>::getMaxX()
{
	return width - 1;
}

template <class T> int OpC_Array2D<T>::getMaxY()
{
	return height - 1;
}

template int OpC_Array2D<int>::getMaxX();
template int OpC_Array2D<int>::getMaxY();

struct OpC_Area	// NOTE: placeholder name/layout
{
	char pad[0x14];
	int x;
	int y;
	int width;
	int height;

	int getRight();	// 0x9b6c10
	int getBottom();	// 0x9b6c30
};

int OpC_Area::getRight()
{
	return width + x - 1;
}

int OpC_Area::getBottom()
{
	return height + y - 1;
}

// vector<int>::assign<int> is mapped twice already (op_t8a, op_t8b); the folded body at 0x9ceaf0 gets the <unsigned> instance
template void vector<int>::assign<unsigned int>(unsigned int _Count, unsigned int _Val);
template void vector<int>::_Assign<int>(int _Count, int _Val, _Int_iterator_tag);
