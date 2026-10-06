// op_t8e: std (VS2010) template instances over placeholder element types, 0x9f6000-0x9fd000
// NOTE: placeholder names; OpT8e_T<addr> element types are named after the exe address
#include <vector>
#include <string>
#include <list>
#include <istream>
#include <algorithm>
#include <memory>
using namespace std;

struct Point
{
	int x;
	int y;

	Point() throw();	// 0x453b40
	Point(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
	Point &operator=(const Point &p);	// 0x46ca50 (ICF with the copy ctor)
	bool operator!=(const Point &p) const;	// 0x409bd0
};

// string::replace(const_iterator, const_iterator, _It, _It) over vector<char>::iterator
template string &string::replace<vector<char>::iterator>(string::const_iterator, string::const_iterator, vector<char>::iterator, vector<char>::iterator);

// string::replace(const_iterator, const_iterator, _It, _It) over istreambuf_iterator<char>
template string &string::replace<istreambuf_iterator<char> >(string::const_iterator, string::const_iterator, istreambuf_iterator<char>, istreambuf_iterator<char>);

// _Distance wrappers (vector iterators)
template void std::_Distance<vector<Point>::iterator, int>(vector<Point>::iterator, vector<Point>::iterator, int &);
template void std::_Distance<vector<char>::iterator, unsigned int>(vector<char>::iterator, vector<char>::iterator, unsigned int &);

// Array2D<int>-like grid (same layout as OpS8e_Array2D / Array2D)
template <class T> class OpT8e_Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *cells;

	OpT8e_Array2D(OpT8e_Array2D<T> *source);
	int getWidth();
	int getHeight();
	T *getCells();
	void blit(int x, int y, OpT8e_Array2D<T> *src);
};

template <class T> OpT8e_Array2D<T>::OpT8e_Array2D(OpT8e_Array2D<T> *source)
{
	width = source->width;
	height = source->height;
	cells = new T[source->width*source->height];
	copy(source->getCells(),source->getCells()+width*height,cells);
}

template <class T> void OpT8e_Array2D<T>::blit(int x, int y, OpT8e_Array2D<T> *src)
{
	for (int i = 0; i < src->getWidth(); i++)
	{
		for (int j = 0; j < src->getHeight(); j++)
			cells[(i+x)*height+j+y] = src->cells[i*src->height+j];
	}
}

template OpT8e_Array2D<int>::OpT8e_Array2D(OpT8e_Array2D<int> *source);
template void OpT8e_Array2D<int>::blit(int x, int y, OpT8e_Array2D<int> *src);

// vector<string>::emplace
template vector<string>::iterator vector<string>::emplace<string>(vector<string>::const_iterator _Where, string &&_Val);

// _Random_shuffle(first, last, int (*&)(int), int *) over element pointers
struct OpT8e_T9f6c50
{
	int m0;
	int m4;
	int m8;
	int m12;
};

struct OpT8e_T9f7250
{
	int m0;
};

struct OpT8e_T9f7f20
{
	int m0;
};

template void std::_Random_shuffle<OpT8e_T9f6c50 *, int (*)(int), int>(OpT8e_T9f6c50 *, OpT8e_T9f6c50 *, int (*&)(int), int *);
template void std::_Random_shuffle<Point *, int (*)(int), int>(Point *, Point *, int (*&)(int), int *);
template void std::_Random_shuffle<OpT8e_T9f7250 **, int (*)(int), int>(OpT8e_T9f7250 **, OpT8e_T9f7250 **, int (*&)(int), int *);
template void std::_Random_shuffle<string *, int (*)(int), int>(string *, string *, int (*&)(int), int *);
template void std::_Random_shuffle<OpT8e_T9f7f20 *, int (*)(int), int>(OpT8e_T9f7f20 *, OpT8e_T9f7f20 *, int (*&)(int), int *);

// operator>>(istream &, string &)
template istream &std::operator>><char, char_traits<char>, allocator<char> >(istream &, string &);
