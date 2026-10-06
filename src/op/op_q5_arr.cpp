// op_q5: container/serialization helper template instances (placeholder names)
// NOTE: placeholder names
#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include "../util/rng.h"
#include "../util/stringutil.h"
using namespace std;

extern RNG rng;	// 0xd30908
void logError(string location, string message);	// NOTE: placeholder name


template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name
template <class T> class OpQ5_Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *cells;
	void read(istream &stream);
	void readRaw(istream &stream);
	void resize(int width_, int height_, istream *stream);
};

template <class T> void OpQ5_Array2D<T>::read(istream &stream)
{
	readBinary(stream,&width);
	readBinary(stream,&height);
	cells = new T[width*height];
	for (int i = 0; i < width*height; i++)
		cells[i].read(stream);
}

template <class T> void OpQ5_Array2D<T>::readRaw(istream &stream)
{
	readBinary(stream,&width);
	readBinary(stream,&height);
	cells = new T[width*height];
	for (int i = 0; i < width*height; i++)
		stream.read((char*)&cells[i],sizeof(T));
}

template <class T> void OpQ5_Array2D<T>::resize(int width_, int height_, istream *stream)
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






struct OpQ5_U9d29d0
{
	char pad[20];
	OpQ5_U9d29d0();
	void read(istream &stream);
};

struct OpQ5_U9d2cd0
{
	char pad[52];
	OpQ5_U9d2cd0();
	void read(istream &stream);
};

struct OpQ5_U9d2ae0
{
	char pad[20];
	OpQ5_U9d2ae0();
	void read(istream &stream);
};

struct OpQ5_U9d2de0
{
	char pad[52];
	OpQ5_U9d2de0();
	void read(istream &stream);
};

struct OpQ5_U9d3360
{
	char pad[8];
	OpQ5_U9d3360();
};

template void OpQ5_Array2D<OpQ5_U9d29d0>::read(istream &stream);
template void OpQ5_Array2D<OpQ5_U9d2cd0>::read(istream &stream);
template void OpQ5_Array2D<OpQ5_U9d2ae0>::resize(int width_, int height_, istream *stream);
template void OpQ5_Array2D<OpQ5_U9d2de0>::resize(int width_, int height_, istream *stream);
template void OpQ5_Array2D<OpQ5_U9d3360>::readRaw(istream &stream);
