// op_s8e_arr: Array2D<T> template instances and small grid helpers (placeholder names)
// NOTE: placeholder names
#include <istream>
using namespace std;

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name

struct XCell
{
	char pad[20];
	XCell();
	XCell(const XCell &cell);
	XCell &operator=(const XCell &cell);
};

template <class T> class Array2D
{
public:
	int width;
	int height;
	T *data;

	int getWidth();
	int getHeight();
	void OpS8e_blit(int x, int y, Array2D<T> *src);	// NOTE: placeholder name
};

template <class T> void Array2D<T>::OpS8e_blit(int x, int y, Array2D<T> *src)
{
	for (int i = 0; i < src->getWidth(); i++)
	{
		for (int j = 0; j < src->getHeight(); j++)
			data[(i+x)*height+j+y] = src->data[i*src->height+j];
	}
}

template void Array2D<XCell>::OpS8e_blit(int x, int y, Array2D<XCell> *src);

void OpS8e_cycleCells(XCell &a, XCell &b, XCell &c, XCell &d)	// NOTE: placeholder name
{
	XCell temp(a);
	a = b;
	b = c;
	c = d;
	d = temp;
}

template <class T> class OpS8e_Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *cells;

	OpS8e_Array2D(istream &stream);
	OpS8e_Array2D(OpS8e_Array2D<T> *source);
	~OpS8e_Array2D();
	void OpS8e_blit(int x, int y, OpS8e_Array2D<T> *src);
	void OpS8e_resize(int width_, int height_);
	void OpS8e_fill(T value);
	void OpS8e_add(OpS8e_Array2D<T> *other);
	void OpS8e_pad(T value, int left, int right, int top, int bottom);
};

template <class T> OpS8e_Array2D<T>::OpS8e_Array2D(istream &stream)
{
	readBinary(stream,&width);
	readBinary(stream,&height);
	cells = new T[width*height];
	for (int i = 0; i < width*height; i++)
		stream.read((char*)&cells[i],sizeof(T));
}

template <class T> void OpS8e_Array2D<T>::OpS8e_resize(int width_, int height_)
{
	if (width_ == width && height_ == height)
		return;
	delete [] cells;
	width = width_;
	height = height_;
	cells = new T[width*height];
}

template <class T> void OpS8e_Array2D<T>::OpS8e_fill(T value)
{
	for (int i = 0; i < width*height; i++)
		cells[i] = value;
}

template <class T> void OpS8e_Array2D<T>::OpS8e_add(OpS8e_Array2D<T> *other)
{
	for (int i = 0; i < width*height; i++)
		cells[i] = cells[i] + other->cells[i];
}

template <class T> void OpS8e_Array2D<T>::OpS8e_pad(T value, int left, int right, int top, int bottom)
{
	if (left == 0 && right == 0 && top == 0 && bottom == 0)
		return;
	int oldWidth = width;
	int oldHeight = height;
	OpS8e_Array2D<T> old(this);
	OpS8e_resize(width+left+right,height+top+bottom);
	OpS8e_blit(left,top,&old);
	if (left)
	{
		for (int i = 0; i < width-oldWidth-right; i++)
		{
			for (int j = 0; j < height; j++)
				cells[i*height+j] = value;
		}
	}
	if (right)
	{
		for (int i = left+oldWidth; i < width; i++)
		{
			for (int j = 0; j < height; j++)
				cells[i*height+j] = value;
		}
	}
	if (top)
	{
		for (int i = left; i < oldWidth+left; i++)
		{
			for (int j = 0; j < height-oldHeight-bottom; j++)
				cells[i*height+j] = value;
		}
	}
	if (bottom)
	{
		for (int i = left; i < oldWidth+left; i++)
		{
			for (int j = top+oldHeight; j < height; j++)
				cells[i*height+j] = value;
		}
	}
}

template OpS8e_Array2D<XCell>::OpS8e_Array2D(istream &stream);
template OpS8e_Array2D<int>::OpS8e_Array2D(istream &stream);
template void OpS8e_Array2D<int>::OpS8e_resize(int width_, int height_);
template void OpS8e_Array2D<int>::OpS8e_fill(int value);
template void OpS8e_Array2D<int>::OpS8e_add(OpS8e_Array2D<int> *other);
template void OpS8e_Array2D<int>::OpS8e_pad(int value, int left, int right, int top, int bottom);
