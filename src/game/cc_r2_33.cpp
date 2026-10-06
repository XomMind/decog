// cc_r2_33: std::vector<T> helper instantiations (_Cons_val, _Move, _Umove, _Ucopy, _Dest_val)
// for a set of game element types. Element types other than XColor are placeholders named
// after the exe address of the first helper using them.
#include <vector>

using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();
	XColor(const XColor &c);
};

struct Elem_9e3800	// NOTE: placeholder name
{
	char pad[0x10];
	Elem_9e3800();
	Elem_9e3800(const Elem_9e3800 &e);
};

struct Elem_9e3840	// NOTE: placeholder name
{
	int a;
	int b;
	Elem_9e3840();
	Elem_9e3840(const Elem_9e3840 &e);
	Elem_9e3840 &operator=(const Elem_9e3840 &e);
};

struct Elem_9e39f0	// NOTE: placeholder name
{
	char pad[0x10];
	Elem_9e39f0();
	Elem_9e39f0(const Elem_9e39f0 &e);
	Elem_9e39f0 &operator=(const Elem_9e39f0 &e);
};

struct Elem_9e3a60	// NOTE: placeholder name
{
	char pad[0x10];
	Elem_9e3a60();
	Elem_9e3a60(const Elem_9e3a60 &e);
};

struct Elem_9e3a80	// NOTE: placeholder name
{
	char pad[0x10];
	Elem_9e3a80();
	Elem_9e3a80(const Elem_9e3a80 &e);
};

struct Elem_9e3aa0	// NOTE: placeholder name
{
	char pad[0x10];
	Elem_9e3aa0();
	Elem_9e3aa0(const Elem_9e3aa0 &e);
	Elem_9e3aa0 &operator=(const Elem_9e3aa0 &e);
};

struct Elem_9e3b20	// NOTE: placeholder name
{
	int a;
	int b;
	int c;
};

struct Elem_9e3b60	// NOTE: placeholder name
{
	char pad[0xac];
	Elem_9e3b60();
	Elem_9e3b60(const Elem_9e3b60 &e);
};

struct Elem_9e3ba0	// NOTE: placeholder name
{
	char pad[0x84];
	Elem_9e3ba0();
	Elem_9e3ba0(const Elem_9e3ba0 &e);
};

struct Elem_9e3be0	// NOTE: placeholder name
{
	char pad[0x6c];
	Elem_9e3be0();
	Elem_9e3be0(const Elem_9e3be0 &e);
	~Elem_9e3be0();
};

struct Elem_9e3c40	// NOTE: placeholder name
{
	char pad[0x10];
	Elem_9e3c40();
	Elem_9e3c40(const Elem_9e3c40 &e);
};

struct Elem_9e3c60	// NOTE: placeholder name
{
	char pad[0x10];
	Elem_9e3c60();
	Elem_9e3c60(const Elem_9e3c60 &e);
};

template class std::vector<char>;
template class std::vector<Elem_9e3800>;
template class std::vector<Elem_9e3840>;
template class std::vector<XColor>;
template class std::vector<Elem_9e39f0>;
template class std::vector<Elem_9e3a60>;
template class std::vector<Elem_9e3a80>;
template class std::vector<Elem_9e3aa0>;
template class std::vector<Elem_9e3b20>;
template class std::vector<Elem_9e3b60>;
template class std::vector<Elem_9e3ba0>;
template class std::vector<Elem_9e3be0>;
template class std::vector<Elem_9e3c40>;
template class std::vector<Elem_9e3c60>;
