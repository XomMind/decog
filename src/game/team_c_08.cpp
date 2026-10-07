// team_c_08: small std template instances (XColor copy/fill, setfill, ...) and tiny helpers
// NOTE: all non-std names are placeholders
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

struct OpC_Color3	// NOTE: placeholder name; XColor layout (a distinct name keeps these COMDATs from folding with other TUs' XColor)
{
	unsigned char r, g, b;
	OpC_Color3(const OpC_Color3 &c);
	OpC_Color3 &operator=(OpC_Color3 c);
};

template OpC_Color3 *std::_Move<OpC_Color3 *, OpC_Color3 *>(OpC_Color3 *, OpC_Color3 *, OpC_Color3 *, _Nonscalar_ptr_iterator_tag);
template void std::_Fill<OpC_Color3 *, OpC_Color3>(OpC_Color3 *, OpC_Color3 *, const OpC_Color3 &);
template OpC_Color3 *std::_Copy_backward<OpC_Color3 *, OpC_Color3 *>(OpC_Color3 *, OpC_Color3 *, OpC_Color3 *, _Nonscalar_ptr_iterator_tag);
template OpC_Color3 *std::_Copy_impl<OpC_Color3 *, OpC_Color3 *>(OpC_Color3 *, OpC_Color3 *, OpC_Color3 *, _Nonscalar_ptr_iterator_tag);
// element move-assign is ICF-folded across vector types; a private element type keeps the
// callees (vector move-assign) from pairing with other exe copies of the same body
struct OpC_MvElem { int v; };	// NOTE: placeholder name
template vector<OpC_MvElem> *std::_Move<vector<OpC_MvElem> *, vector<OpC_MvElem> *>(vector<OpC_MvElem> *, vector<OpC_MvElem> *, vector<OpC_MvElem> *, _Nonscalar_ptr_iterator_tag);
template void std::_Uninit_fill_n<float, unsigned int, float>(float *, unsigned int, const float &, _Scalar_ptr_iterator_tag);
template int *&std::_Rechecked<int *, int *>(int *&, int *);
struct OpC_DrElem { int v; };	// NOTE: placeholder name (private type: see above)
template vector<OpC_DrElem>::reference vector<OpC_DrElem>::iterator::operator*() const;
template _Fillobj<char> std::setfill<char>(char);
template ostream &std::operator<< <char, char_traits<char> >(ostream &, const _Fillobj<char> &);

void OpC_clampMax(int *v, int m)
{
	if (*v > m)
		*v = m;
}

void OpC_clampMin(int *v, int m)
{
	if (*v < m)
		*v = m;
}

int OpC_square(int x)
{
	return x * x;
}

float OpC_degToRad(float d)
{
	return (float)(d * 3.1415927410125732 / 180.0);
}

template <class T> void writeBinary(ostream &stream, T *value);
template <class T> void readBinary(istream &stream, T *value);

struct OpC_IntBox
{
	int v;
	void write(ostream &stream);
	void read(istream &stream);
};

void OpC_IntBox::write(ostream &stream)
{
	writeBinary(stream, &v);
}

void OpC_IntBox::read(istream &stream)
{
	readBinary(stream, &v);
}

struct Point	// as in pathing/gamedecl.h
{
	int x;
	int y;

	Point();
	Point(int x_, int y_);
	Point(const Point &p);
	Point &operator=(const Point &p);
};
struct OpC_D8P { char pad[8]; vector<Point> v; ~OpC_D8P(); };
OpC_D8P::~OpC_D8P() {}
struct OpC_D4P { char pad[4]; vector<Point> v; ~OpC_D4P(); };
OpC_D4P::~OpC_D4P() {}
struct OpC_D1cS { char pad[0x1c]; string s; ~OpC_D1cS(); };
OpC_D1cS::~OpC_D1cS() {}
struct OpC_D10S { char pad[0x10]; string s; ~OpC_D10S(); };
OpC_D10S::~OpC_D10S() {}
struct OpC_D4S { char pad[4]; string s; ~OpC_D4S(); };
OpC_D4S::~OpC_D4S() {}
