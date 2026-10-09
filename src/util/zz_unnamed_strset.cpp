// Small functions whose callers already exist but whose own definitions were missing:
// string-ref setters (the const char* overloads defined elsewhere are different functions),
// the dynamic initializer of the global screen shake, and two placeholder element destructors
// that src/op/op_r6_kcd.cpp only declares.
// NOTE: placeholder layouts; classes here are partial redeclarations.
#include <string>
#include <vector>
using namespace std;

class CTextInput
{
public:
	void setText(const string &text);
	int pad00[0x6c / 4];
	string text;	// +0x6c
	int cursor;	// +0x88 NOTE: placeholder name
};

void CTextInput::setText(const string &text)	// 0x48d300
{
	this->text = text;
	cursor = this->text.size();
}

class Entity
{
public:
	void unknown45b070(const string &s);
	int pad00[3];
	string str_c;	// +0x0c NOTE: placeholder name
};

void Entity::unknown45b070(const string &s)	// 0x45b070
{
	str_c = s;
}

class XScreenShake	// layout as in src/game/cc_r1_07.cpp
{
public:
	XScreenShake();
	unsigned int endTime;
	bool stopped;
	int offsetX;
	int offsetY;
	unsigned int lastTime;
};

XScreenShake screenShake_d16188;	// NOTE: placeholder name (0xd16188; initializer 0xb23d50)

struct OpR6_KCD_40_0	// NOTE: placeholder layout (only the destructor's view; see op_r6_kcd.cpp)
{
	~OpR6_KCD_40_0();
	int m0;
	int m4;
	int m8;
	vector<string> names;	// +0x0c NOTE: placeholder name
	int m28;
	int m32;
	int m36;
};

OpR6_KCD_40_0::~OpR6_KCD_40_0()	// 0x9f51b0
{
}

template <class T> class OpX5_Array2D	// defined in src/op/op_x5.cpp
{
public:
	int width;
	int height;
	T *cells;
	void freeCells();
};

struct OpR6_KCD_28_1	// NOTE: placeholder layout (only the destructor's view; see op_r6_kcd.cpp)
{
	~OpR6_KCD_28_1();
	OpX5_Array2D<int> grid;	// NOTE: placeholder name
	int m12;
	int m16;
	int m20;
	int m24;
};

OpR6_KCD_28_1::~OpR6_KCD_28_1()	// 0x9e7830
{
	grid.freeCells();
}
