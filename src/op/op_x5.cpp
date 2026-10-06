// op_x5: STL/array template instances and small helpers in 0x80f000-0xa044d0
#include <cstring>
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct OpX5_S3 { char b[3]; };	// NOTE: placeholder name
struct OpX5_S8 { char b[8]; };	// NOTE: placeholder name
struct OpX5_S14 { char b[0x14]; };	// NOTE: placeholder name
struct OpX5_S34 { char b[0x34]; };	// NOTE: placeholder name

int OpX5_minInt(int a, int b)	// NOTE: placeholder name
{
	return a > b ? b : a;
}

int OpX5_maxInt(int a, int b)	// NOTE: placeholder name
{
	return a < b ? b : a;
}

void OpX5_clampInt(int lo, int *value, int hi)	// NOTE: placeholder name
{
	if (*value < lo)
		*value = lo;
	else if (*value > hi)
		*value = hi;
}

void OpX5_fillChars(char *p, unsigned int count, char value)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
		p[i] = value;
}

void OpX5_fillInts(int *p, unsigned int count, int value)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
		p[i] = value;
}

unsigned int OpX5_minUInt(unsigned int a, unsigned int b)	// NOTE: placeholder name
{
	return a > b ? b : a;
}

bool OpX5_inRangeIncl(unsigned int a, unsigned int b, unsigned int c)	// NOTE: placeholder name
{
	return a <= b && b <= c;
}

bool OpX5_inRangeExcl(unsigned int a, unsigned int b, unsigned int c)	// NOTE: placeholder name
{
	return a < b && b < c;
}

double OpX5_maxDouble(double a, double b)	// NOTE: placeholder name
{
	return a < b ? b : a;
}

template <class T> class OpX5_Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *cells;
	OpX5_Array2D();
	T *at(int x, int y);
	T *atPoint(Point &p);
	void zero();
	void load(void *src);
	void freeCells();
};

template <class T> OpX5_Array2D<T>::OpX5_Array2D()
{
	height = 0;
	width = 0;
	cells = NULL;
}

template <class T> T *OpX5_Array2D<T>::at(int x, int y)
{
	return &cells[x*height+y];
}

template <class T> T *OpX5_Array2D<T>::atPoint(Point &p)
{
	return &cells[p.x*height+p.y];
}

template <class T> void OpX5_Array2D<T>::zero()
{
	memset(cells,0,sizeof(T)*width*height);
}

template <class T> void OpX5_Array2D<T>::load(void *src)
{
	memcpy(cells,src,sizeof(T)*width*height);
}

template <class T> void OpX5_Array2D<T>::freeCells()
{
	delete [] cells;
}

template OpX5_Array2D<OpX5_S14>::OpX5_Array2D();
template OpX5_S14 *OpX5_Array2D<OpX5_S14>::at(int x, int y);
template OpX5_S14 *OpX5_Array2D<OpX5_S14>::atPoint(Point &p);
template OpX5_S34 *OpX5_Array2D<OpX5_S34>::at(int x, int y);
template OpX5_S34 *OpX5_Array2D<OpX5_S34>::atPoint(Point &p);
template OpX5_S3 *OpX5_Array2D<OpX5_S3>::at(int x, int y);
template OpX5_S3 *OpX5_Array2D<OpX5_S3>::atPoint(Point &p);
template OpX5_S8 *OpX5_Array2D<OpX5_S8>::at(int x, int y);
template char *OpX5_Array2D<char>::at(int x, int y);
template int *OpX5_Array2D<int>::at(int x, int y);
template int *OpX5_Array2D<int>::atPoint(Point &p);
template void OpX5_Array2D<int>::zero();
template void OpX5_Array2D<int>::load(void *src);
template void OpX5_Array2D<char>::zero();
template void OpX5_Array2D<int>::freeCells();
