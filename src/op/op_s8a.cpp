// op_s8a: handle pools, array and vector helper instances in 0x9d0000-0x9d43b0 (placeholder names)
// NOTE: placeholder names
#include <vector>
#include <string>
#include <istream>
#include <ostream>
using namespace std;

class HEntity
{
public:
	int ID;
	int getIndex();
	int getGeneration();
	bool operator==(HEntity other) const;
};

struct Point
{
	int x;
	int y;
	Point(int x_, int y_);
	Point(const Point &p);
	bool operator==(const Point &p);
	bool unknown409cf0(int x_, int y_);	// NOTE: placeholder name
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor();
	XColor(const XColor &c);
	void read(istream &stream);	// NOTE: placeholder name
};

struct OpS8a_P8	// NOTE: placeholder name
{
	int a;
	int b;
	OpS8a_P8();
	void read(istream &stream);
};

struct OpS8a_G20	// NOTE: placeholder name
{
	char pad[0x14];
	void write(ostream &stream);
};

struct OpS8a_G34	// NOTE: placeholder name
{
	char pad[0x34];
	void write(ostream &stream);
};

class HProp
{
public:
	int ID;
	HProp();
	int getIndex();
	int getGeneration();
	void unknown9ed820(int index);	// NOTE: placeholder name
};

template <class T> struct OpS8a_Pool	// NOTE: placeholder name
{
	vector<T*>	items;
	vector<int>	generations;
	vector<int>	freeList;
	HProp add(T *item);
	void remove(HEntity h, bool deleteItem);
	T *release(HEntity h);
	unsigned int getAll(vector<T*> &result);
	void clearAll(bool deleteItems);
};

template <class T> HProp OpS8a_Pool<T>::add(T *item)
{
	HProp h;
	if (freeList.empty())
	{
		h.unknown9ed820(items.size());
		items.push_back(item);
		generations.push_back(h.getGeneration());
	}
	else
	{
		h.unknown9ed820(freeList.back());
		freeList.pop_back();
		items[h.getIndex()] = item;
		generations[h.getIndex()] = h.getGeneration();
	}
	return h;
}

template <class T> void OpS8a_Pool<T>::remove(HEntity h, bool deleteItem)
{
	int index = h.getIndex();
	if (deleteItem)
	{
		delete items[index];
	}
	items[index] = NULL;
	generations[index] = 0;
	freeList.push_back(index);
}

template <class T> T *OpS8a_Pool<T>::release(HEntity h)
{
	int index = h.getIndex();
	T *item = items[index];
	items[index] = NULL;
	generations[index] = 0;
	freeList.push_back(index);
	return item;
}

template <class T> unsigned int OpS8a_Pool<T>::getAll(vector<T*> &result)
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (generations[i])
			result.push_back(items[i]);
	}
	return result.size();
}

template <class T> void OpS8a_Pool<T>::clearAll(bool deleteItems)
{
	if (deleteItems)
	{
		for (unsigned int i = 0; i < items.size(); i++)
		{
			delete items[i];
		}
	}
	items.clear();
	generations.clear();
	freeList.clear();
}

struct OpS8a_Rec24
{
	~OpS8a_Rec24();
};

struct OpS8a_RecW45eff0
{
	~OpS8a_RecW45eff0();
};

struct OpS8a_Rec18
{
	~OpS8a_Rec18();
};

struct OpS8a_RecKcd
{
	~OpS8a_RecKcd();
};

struct OpS8a_VRec1
{
	virtual ~OpS8a_VRec1();
};

template struct OpS8a_Pool<OpS8a_Rec24>;
template struct OpS8a_Pool<OpS8a_Rec18>;
template struct OpS8a_Pool<OpS8a_RecKcd>;
template struct OpS8a_Pool<OpS8a_VRec1>;
template struct OpS8a_Pool<OpS8a_RecW45eff0>;


template <class T> void readBinary(istream &stream, T *value);
template <class T> void writeBinary(ostream &stream, T *value);

class Cell
{
public:
	char pad[0x70];
	Cell(istream &stream);
	~Cell();
	void save(ostream &stream);
};

template <class T> class OpS8a_Array2D	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *cells;
	OpS8a_Array2D(int width_, int height_, bool value);
	void fill(bool value);
	void read(istream &stream);
	void write(ostream &stream);
	void writeRaw(ostream &stream);
	void resize(int width_, int height_, istream *stream);
	void cleanup();
};

template <class T> OpS8a_Array2D<T>::OpS8a_Array2D(int width_, int height_, bool value)
{
	width = width_;
	height = height_;
	cells = new T[width_*height_];
	fill(value);
}

template <class T> void OpS8a_Array2D<T>::fill(bool value)
{
	for (int i = 0; i < width*height; i++)
		cells[i] = value;
}

template <class T> void OpS8a_Array2D<T>::read(istream &stream)
{
	bool exists;
	readBinary(stream,&width);
	readBinary(stream,&height);
	cells = new T[width*height];
	for (int i = 0; i < width*height; i++)
	{
		readBinary(stream,&exists);
		if (exists)
			cells[i] = new Cell(stream);
		else
			cells[i] = NULL;
	}
}

template <class T> void OpS8a_Array2D<T>::write(ostream &stream)
{
	bool exists;
	writeBinary(stream,&width);
	writeBinary(stream,&height);
	for (int i = 0; i < width*height; i++)
	{
		exists = (bool)cells[i];
		writeBinary(stream,&exists);
		if (exists)
			cells[i]->save(stream);
	}
}

template <class T> void OpS8a_Array2D<T>::writeRaw(ostream &stream)
{
	writeBinary(stream,&width);
	writeBinary(stream,&height);
	for (int i = 0; i < width*height; i++)
		stream.write((char*)&cells[i],sizeof(T));
}

template <class T> void OpS8a_Array2D<T>::resize(int width_, int height_, istream *stream)
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

template <class T> void OpS8a_Array2D<T>::cleanup()
{
	for (int i = 0; i < width*height; i++)
		delete cells[i];
	delete [] cells;
	height = 0;
	width = 0;
	cells = NULL;
}

template OpS8a_Array2D<bool>::OpS8a_Array2D(int width_, int height_, bool value);
template void OpS8a_Array2D<bool>::fill(bool value);
template void OpS8a_Array2D<bool>::writeRaw(ostream &stream);
template void OpS8a_Array2D<bool>::resize(int width_, int height_, istream *stream);
template void OpS8a_Array2D<int>::writeRaw(ostream &stream);
template void OpS8a_Array2D<Cell*>::read(istream &stream);
template void OpS8a_Array2D<Cell*>::write(ostream &stream);
template void OpS8a_Array2D<Cell*>::cleanup();


template <class T> class OpS8a_Grid	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *cells;
	void write(ostream &stream);
};

template <class T> void OpS8a_Grid<T>::write(ostream &stream)
{
	writeBinary(stream,&width);
	writeBinary(stream,&height);
	for (int i = 0; i < width*height; i++)
		cells[i].write(stream);
}

template void OpS8a_Grid<OpS8a_G20>::write(ostream &stream);
template void OpS8a_Grid<OpS8a_G34>::write(ostream &stream);
template void OpS8a_Array2D<int>::resize(int width_, int height_, istream *stream);

template <class T> void OpS8a_writeRawVector(ostream &stream, vector<T> &v)	// NOTE: placeholder name
{
	unsigned int count = v.size();
	stream.write((char*)&count,sizeof(count));
	for (unsigned int i = 0; i < count; i++)
		stream.write((char*)&v[i],sizeof(T));
}

template void OpS8a_writeRawVector<int>(ostream &stream, vector<int> &v);

void OpS8a_readXColors(istream &stream, vector<XColor> &v)	// NOTE: placeholder name
{
	XColor color;
	unsigned int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(color);
		v.back().read(stream);
		count--;
	}
}

void OpS8a_readP8s(istream &stream, vector<OpS8a_P8> &v)	// NOTE: placeholder name
{
	OpS8a_P8 value;
	unsigned int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(value);
		v.back().read(stream);
		count--;
	}
}

int OpS8a_clampSub(int &value, int amount, int limit)	// NOTE: placeholder name
{
	if (value + amount >= limit)
	{
		value = limit;
		return limit;
	}
	value -= amount;
	return value;
}

int OpS8a_clampAdd(int &value, int amount, int limit)	// NOTE: placeholder name
{
	if (value + amount >= limit)
	{
		value = limit;
		return limit;
	}
	value += amount;
	return value;
}

bool OpS8a_containsPoint(vector<Point> &v, Point p)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == p)
			return true;
	}
	return false;
}

bool OpS8a_addUniquePoint(vector<Point> &v, Point p)	// NOTE: placeholder name
{
	if (!OpS8a_containsPoint(v,p))
	{
		v.push_back(p);
		return true;
	}
	return false;
}

bool OpS8a_removePoint(vector<Point> &v, Point p)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == p)
		{
			v.erase(v.begin()+i);
			return true;
		}
	}
	return false;
}

bool OpS8a_removeHandle(vector<HEntity> &v, HEntity h)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == h)
		{
			v.erase(v.begin()+i);
			return true;
		}
	}
	return false;
}

int OpS8a_indexOfHandle(vector<HEntity> &v, HEntity h)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == h)
			return i;
	}
	return -1;
}

bool OpS8a_containsHandle(vector<HEntity> &v, HEntity h)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == h)
			return true;
	}
	return false;
}

void OpS8a_removeAllHandles(vector<HEntity> &v, HEntity h)	// NOTE: placeholder name
{
	for (vector<HEntity>::iterator it = v.begin(); it != v.end();)
	{
		if (*it == h)
			it = v.erase(it);
		else
			++it;
	}
}

void OpS8a_readBytes(istream &stream, char *bytes)	// NOTE: placeholder name
{
	unsigned int count;
	stream.read((char*)&count,sizeof(count));
	for (unsigned int i = 0; i < count; i++)
		stream.read(bytes+i,1);
}

void OpS8a_writeBytes(ostream &stream, char *bytes, unsigned int count)	// NOTE: placeholder name
{
	stream.write((char*)&count,sizeof(count));
	for (unsigned int i = 0; i < count; i++)
		stream.write(bytes+i,1);
}

bool OpS8a_anyNonZero(int *values, unsigned int count)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < count; i++)
	{
		if (values[i])
			return true;
	}
	return false;
}

int OpS8a_maxElement(vector<int> &v)	// NOTE: placeholder name
{
	int best = 0;
	for (unsigned int i = 1; i < v.size(); i++)
	{
		if (v[i] > v[best])
			best = i;
	}
	return v[best];
}

bool OpS8a_containsString(vector<string> &v, string s)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == s)
			return true;
	}
	return false;
}
