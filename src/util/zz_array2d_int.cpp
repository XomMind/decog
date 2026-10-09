// Array2D<int>::operator()(int, int) / operator()(const Point &) / operator()(const Pos &).
// The exe calls OpX5_Array2D<int>::at (0x9ceda0) and ::atPoint (0x9ced70) for these; 0x9cfe20/0x9cfd90 are the
// bounds-checked view class, a different type (OpV4c_View).
struct Point
{
	int x;
	int y;
};

struct Pos
{
	int x;
	int y;
};

// 2D array, column-major: data[x * height + y]
template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(int x, int y);
	T &operator()(const Point &p);
	T &operator()(const Pos &p);
};

template <class T>
T &Array2D<T>::operator()(int x, int y)
{
	return data[x * height + y];
}

template <class T>
T &Array2D<T>::operator()(const Point &p)
{
	return data[p.x * height + p.y];
}

template <class T>
T &Array2D<T>::operator()(const Pos &p)
{
	return data[p.x * height + p.y];
}

template int &Array2D<int>::operator()(int x, int y);
template int &Array2D<int>::operator()(const Point &p);
template int &Array2D<int>::operator()(const Pos &p);
