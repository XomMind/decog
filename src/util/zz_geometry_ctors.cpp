// Rect(), Rect(const Rect &), Area(), XEvent(int) and Array2D<bool>::operator()(int, int): no file defines them, so every
// caller linked against a stub, and the strict target check rejected the pairing with the address of an unrelated
// overload that shares the display name (Rect(int,int,int,int) 0x456940, Area(const Area &) 0x40b130, XEvent(const XEvent &)
// 0x944370, Array2D<bool>::operator()(const Point &) 0x9d2770).
// Exe addresses: Rect() 0x40a6e0 (folded with a protobuf zero-init ctor), Rect(const Rect &) 0x40a720,
// Area() 0x40b100, XEvent(int) 0x415c60, Array2D<bool>::operator()(int, int) 0x9cec50 (folded with OpX5_Array2D<char>::at).
struct Pos
{
	int x;
	int y;
	Pos();					// 0x453b40
	void set409ff0(int v);	// 0x409ff0
	explicit Pos(int v);	// 0x409990
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;
	Rect();						// 0x40a6e0
	Rect(const Rect &rect);		// 0x40a720
};

struct Area
{
	Pos min;
	Pos max;
	Area();						// 0x40b100
};

struct XEvent
{
	int type;
	Pos pos;
	XEvent(int type_);			// 0x415c60
};

Rect::Rect()
	: x (0)
	, y (0)
	, width (0)
	, height (0)
{
}

Rect::Rect(const Rect &rect)
	: x (rect.x)
	, y (rect.y)
	, width (rect.width)
	, height (rect.height)
{
}

Area::Area()
	: min (-1)
	, max (-1)
{
}

XEvent::XEvent(int type_)
	: type (type_)
{
	pos.set409ff0(-10000);
}

// Array2D<bool>::operator()(int, int): the exe calls the column-major at(x, y) (0x9cec50, folded with the char-element
// OpX5_Array2D::at); the configured 0x9d2770 is the operator()(const Point &) overload.
struct Point
{
	int x;
	int y;
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(int x, int y);
};

template <class T>
T &Array2D<T>::operator()(int x, int y)
{
	return data[x * height + y];
}

template bool &Array2D<bool>::operator()(int x, int y);
