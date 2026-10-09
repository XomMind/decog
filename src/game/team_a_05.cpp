// team_a_05: small helpers and accessors in 0x408000-0x41b200 (string padding, geometry wrappers, SDL/SDL_mixer
// wrappers, surface holders, toggles).
// NOTE: class, member and function names are placeholders unless they are STL names; layouts are partial.
#include <string>
#include <vector>
#include <fstream>
#include "../util/rng.h"
using namespace std;

extern RNG rng;

struct SDL_Surface;
extern "C" void SDL_FreeSurface(SDL_Surface *surface);
extern "C" void SDL_WM_SetCaption(const char *title, const char *icon);
extern "C" unsigned int SDL_GetTicks();
struct Mix_Chunk;
extern "C" void Mix_FreeChunk(Mix_Chunk *chunk);
extern "C" int Mix_HaltChannel(int channel);
extern "C" int Mix_FadeOutGroup(int tag, int ms);
extern "C" int Mix_HaltGroup(int tag);
extern "C" int Mix_GroupOldest(int tag);

struct Point
{
	int	x;
	int	y;
	Point(int x_, int y_);						// 0x46ca20
	Point(const Point &p);						// 0x46ca50
};

struct Area	// NOTE: placeholder name
{
	Point min;
	Point max;
	int distance_40ba00(const Area &other);
	int touches_40baa0(const Area &other);	// NOTE: placeholder name
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;
	bool contains(int x_, int y_) const;	// NOTE: placeholder name (0x40a9a0)
	int distance_40ae20(const Rect &other);	// NOTE: placeholder name
	int touches_40aef0(const Rect &other);	// NOTE: placeholder name
};

int Rect::touches_40aef0(const Rect &other)
{
	return distance_40ae20(other) == 0;
}

int Area::touches_40baa0(const Area &other)
{
	return distance_40ba00(other) == 0;
}

void teamA_copyArea(Area &a)	// NOTE: placeholder (not in the exe; emits Area's implicit copy constructor)
{
	Area b(a);
}

string &padLeft_408090(string &s, unsigned int width, char c)	// NOTE: placeholder name
{
	if (s.size() < width)
		s.insert(0,width - s.size(),c);
	return s;
}

string &padRight_4080d0(string &s, unsigned int width, char c)	// NOTE: placeholder name
{
	if (s.size() < width)
		s.append(width - s.size(),c);
	return s;
}

int randomIndex_4091d0(int count)	// NOTE: placeholder name
{
	return rng.rangeInt(0,count - 1);
}

void OpQ1_writeString(ostream &out, string text);	// 0x409650
void writeStringRef_409740(ostream &out, const string &text)	// NOTE: placeholder name
{
	OpQ1_writeString(out,text);
}

void teamA_useOfstream()	// NOTE: placeholder (not in the exe)
{
	ofstream f("x");
}

class PushGeometry
{
public:
	int x;
	int y;
	int distanceTo(const PushGeometry &p);
	int isAdjacent_409e20(const PushGeometry &p);	// NOTE: placeholder name
};

int PushGeometry::isAdjacent_409e20(const PushGeometry &p)
{
	return distanceTo(p) == 1;
}

float OpY1_angle(int x1, int y1, int x2, int y2);	// NOTE: placeholder name
float angleBetween_40a680(const Point &a, const Point &b)	// NOTE: placeholder name
{
	return OpY1_angle(a.x,a.y,b.x,b.y);
}

extern const float minusOne_c36e10;	// NOTE: placeholder name (0xc36e10, -1.0f)

struct FloatPair_40a6b0	// NOTE: placeholder name
{
	float a;
	float b;
	FloatPair_40a6b0();
};

FloatPair_40a6b0::FloatPair_40a6b0()
{
	a = minusOne_c36e10;
	b = minusOne_c36e10;
}

struct FloatPair_40c470	// NOTE: placeholder name
{
	float a;
	float b;
	FloatPair_40c470();
};

FloatPair_40c470::FloatPair_40c470()
{
	a = 0;
	b = 0;
}

struct IntRange_40c170	// NOTE: placeholder name
{
	int low;
	int high;
	int middle();
};

int IntRange_40c170::middle()
{
	return (low + high) / 2;
}

bool ops7_between_9cdb90(float low, float value, float high);	// NOTE: placeholder name
struct FloatRange_40c730	// NOTE: placeholder name
{
	float low;
	float high;
	bool contains(float value);
};

bool FloatRange_40c730::contains(float value)
{
	return ops7_between_9cdb90(low,value,high);
}

int OpT8a_sumVector(vector<int> &v);	// NOTE: placeholder name
struct IntList_40c820 : public vector<int>	// NOTE: placeholder name
{
	int sum();
};

int IntList_40c820::sum()
{
	return OpT8a_sumVector(*this);
}

class Unknown_40cde0	// NOTE: placeholder name (destructor at 0x40cde0)
{
public:
	int width;
	int height;
	bool flagA;
	bool flagB;
	int limit;
	int unknown10;
	int *grids[9];
	Unknown_40cde0();	// 0x40ca90 (builds and destroys a temporary Unknown_40cde0(1,1))
	Unknown_40cde0(int width_, int height_);
	~Unknown_40cde0();
};

Unknown_40cde0::Unknown_40cde0()
{
	Unknown_40cde0 temp(1,1);
}

class Fov_40c9e0	// NOTE: placeholder name
{
public:
	int unknown40dd50(int x, int y, int a, int b, int c, int d);	// NOTE: placeholder name
	int unknown40e990(int x, int y, int a, int b, int c);	// NOTE: placeholder name
	int unknown40f310(int x, int y, int a, int b, int c, int d, int e);	// NOTE: placeholder name
	int unknown40c9e0(const Point &p, int a, int b, int c, int d);	// NOTE: placeholder name
	int unknown40ca20(const Point &p, int a, int b, int c);	// NOTE: placeholder name
	int unknown40ca50(const Point &p, int a, int b, int c, int d, int e);	// NOTE: placeholder name
};

int Fov_40c9e0::unknown40c9e0(const Point &p, int a, int b, int c, int d)
{
	return unknown40dd50(p.x,p.y,a,b,c,d);
}

int Fov_40c9e0::unknown40ca20(const Point &p, int a, int b, int c)
{
	return unknown40e990(p.x,p.y,a,b,c);
}

int Fov_40c9e0::unknown40ca50(const Point &p, int a, int b, int c, int d, int e)
{
	return unknown40f310(p.x,p.y,a,b,c,d,e);
}

SDL_Surface *OpR1a_createSurface(int width, int height, bool alpha);	// NOTE: placeholder name (0x413e80)
class SurfaceHolder_413d50	// NOTE: placeholder name
{
public:
	SDL_Surface *surface;
	SurfaceHolder_413d50(int width, int height, bool alpha);
	void release();
	void create(int width, int height, bool alpha);
};

SurfaceHolder_413d50::SurfaceHolder_413d50(int width, int height, bool alpha)
{
	surface = 0;
	create(width,height,alpha);
}

void SurfaceHolder_413d50::release()
{
	SDL_FreeSurface(surface);
	surface = 0;
}

void SurfaceHolder_413d50::create(int width, int height, bool alpha)
{
	release();
	surface = OpR1a_createSurface(width,height,alpha);
}

bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name
bool OpS8b_Fn9d43b0(int *values, unsigned int count, int value);	// NOTE: placeholder name
extern int reservedChars_caecf8[10];	// NOTE: placeholder name (0xcaecf8)
bool isAllowedChar_415fc0(char c)	// NOTE: placeholder name
{
	if (OpT8b_Fn9daf80(0x20,c,0x7e) && !OpS8b_Fn9d43b0(reservedChars_caecf8,10,c))
		return true;
	else
		return false;
}

class BoolList_416200	// NOTE: placeholder name
{
public:
	char pad[0x10];
	vector<bool> flags;
	bool get(int index);
};

bool BoolList_416200::get(int index)
{
	return flags[index];
}

struct Toggle_416900	// NOTE: placeholder name
{
	bool value;
	void toggle();
};

void Toggle_416900::toggle()
{
	value = !value;
}

class Grid_416a30	// NOTE: placeholder name
{
public:
	int pad0;
	int width;
	char pad8[8];
	vector<int> cells;
	void set(int index, int x, int y);
};

void Grid_416a30::set(int index, int x, int y)
{
	cells[index] = y * width + x;
}

class Surface28_416b40	// NOTE: placeholder name
{
public:
	char pad[0x28];
	SDL_Surface *surface;
	void release();
};

void Surface28_416b40::release()
{
	SDL_FreeSurface(surface);
	surface = 0;
}

class REX
{
public:
	char pad[0x24];
	string title;
	string icon;
	void updateCaption_418d70();	// NOTE: placeholder name
};

void REX::updateCaption_418d70()
{
	SDL_WM_SetCaption(title.c_str(),icon.c_str());
}

extern int global_cebc48;	// NOTE: placeholder name (0xcebc48)
extern int global_ced168;	// NOTE: placeholder name (0xced168)
class Setter_418de0	// NOTE: placeholder name
{
public:
	void setA(int value);
	void setB(int value);
};

void Setter_418de0::setA(int value)
{
	global_cebc48 = value;
}

void Setter_418de0::setB(int value)
{
	global_ced168 = value;
}

struct Sound_419330	// NOTE: placeholder name
{
	Mix_Chunk *chunk;
	int unknown4;
	string name;
	~Sound_419330();
};

Sound_419330::~Sound_419330()
{
	Mix_FreeChunk(chunk);
}

struct MapRecord	// NOTE: placeholder layout
{
	int		unknown0;
	int		unknown4;
};

class SoundList_419550	// NOTE: placeholder name
{
public:
	int pad0;
	vector<MapRecord *> sounds;
	int get(unsigned int index);
};

int SoundList_419550::get(unsigned int index)
{
	return sounds[index]->unknown4;
}

class Mixer_419bf0	// NOTE: placeholder name
{
public:
	void haltChannel(int channel);
	void haltAll();
	void fadeOutGroup(int tag, int ms);
	void haltGroup(int tag);
	bool groupBusy(int tag);
};

void Mixer_419bf0::haltChannel(int channel) { Mix_HaltChannel(channel); }
void Mixer_419bf0::haltAll() { Mix_HaltChannel(-1); }
void Mixer_419bf0::fadeOutGroup(int tag, int ms) { Mix_FadeOutGroup(tag,ms); }
void Mixer_419bf0::haltGroup(int tag) { Mix_HaltGroup(tag); }
bool Mixer_419bf0::groupBusy(int tag) { return Mix_GroupOldest(tag) != -1; }

class Surfaces_41a6b0	// NOTE: placeholder name
{
public:
	char pad[0x1c];
	SDL_Surface *a;
	SDL_Surface *b;
	void release();
};

void Surfaces_41a6b0::release()
{
	SDL_FreeSurface(a);
	SDL_FreeSurface(b);
}

class Pos_41a700	// NOTE: placeholder name
{
public:
	char pad[0x10];
	int x;
	int y;
	Point getPos();
};

Point Pos_41a700::getPos()
{
	return Point(x,y);
}

struct Cell_41a730	// NOTE: placeholder name
{
	int x;
	int y;
	bool inside(const Rect &r);
};

bool Cell_41a730::inside(const Rect &r)
{
	return r.contains(x,y);
}

class OpR1c_Mouse
{
public:
	void setCell(int x_, int y_);
	void setCellPoint_41a910(const Point &p);	// NOTE: placeholder name
};

void OpR1c_Mouse::setCellPoint_41a910(const Point &p)
{
	setCell(p.x,p.y);
}

extern REX rex_d223f0;	// NOTE: placeholder name (0xd223f0)
class Window_41b0f0	// NOTE: placeholder name
{
public:
	char pad[0x1c];
	bool unknown1c;
	bool unknown1d;
	void setUnknown1c(bool value);
	void toggleUnknown1c();
	void toggleUnknown1d();
};

void Window_41b0f0::setUnknown1c(bool value)
{
	unknown1c = value;
	if (!unknown1c)
		rex_d223f0.updateCaption_418d70();
}

void Window_41b0f0::toggleUnknown1c()
{
	setUnknown1c(!unknown1c);
}

void Window_41b0f0::toggleUnknown1d()
{
	unknown1d = !unknown1d;
}
