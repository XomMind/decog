// op_q1_b: stream serialization helpers and misc in 0x409600-0x409900 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

void OpQ1_writeString(ostream &out, string text)	// NOTE: placeholder name (0x409650)
{
	unsigned int size = text.size();
	out.write((char *)&size,4);
	for (unsigned int i = 0; i < size; i++)
		out.write(&text[i],1);
}

void OpQ1_readString(istream &in, string *text)	// NOTE: placeholder name (0x4096f0)
{
	unsigned int size;
	in.read((char *)&size,4);
	while (size)
	{
		char c;
		in.read(&c,1);
		text->push_back(c);
		size--;
	}
}

void OpQ1_writeStringVector(ostream &out, vector<string> *list)	// NOTE: placeholder name (0x409770)
{
	unsigned int size = list->size();
	out.write((char *)&size,4);
	for (unsigned int i = 0; i < size; i++)
		OpQ1_writeString(out,(*list)[i]);
}

void OpQ1_readStringVector(istream &in, vector<string> *list)	// NOTE: placeholder name (0x4097e0)
{
	string text;
	unsigned int count;
	in.read((char *)&count,4);
	while (count)
	{
		text.clear();
		OpQ1_readString(in,&text);
		list->push_back(text);
		count--;
	}
}

void OpQ1_writeStringVectorList(ostream &out, vector<vector<string> > *lists)	// NOTE: placeholder name (0x409890)
{
	unsigned int count = lists->size();
	out.write((char *)&count,4);
	for (unsigned int i = 0; i < count; i++)
		OpQ1_writeStringVector(out,&(*lists)[i]);
}

void OpQ1_readStringVectorList(istream &in, vector<vector<string> > *lists)	// NOTE: placeholder name (0x4098f0)
{
	unsigned int count;
	in.read((char *)&count,4);
	while (count)
	{
		lists->push_back(vector<string>());
		OpQ1_readStringVector(in,&lists->back());
		count--;
	}
}

#include <math.h>

struct OpQ1_Point	// NOTE: placeholder name
{
	int x;
	int y;

	void rotateInto_40a3b0(int size);	// NOTE: placeholder name
};

int OpQ1_sqr(int value);	// NOTE: placeholder name (0x9ccff0, template instance)

void OpQ1_Point::rotateInto_40a3b0(int size)
{
	int oldY = y;
	y = x;
	x = size - 1 - oldY;
}

int OpQ1_distanceCeil_40a3f0(const OpQ1_Point &a, const OpQ1_Point &b)	// NOTE: placeholder name
{
	return (int)(sqrt((float)(OpQ1_sqr(b.x - a.x) + OpQ1_sqr(b.y - a.y))) + 0.9999);
}

float OpQ1_distance_40a450(const OpQ1_Point &a, const OpQ1_Point &b)	// NOTE: placeholder name
{
	return sqrt((float)(OpQ1_sqr(b.x - a.x) + OpQ1_sqr(b.y - a.y)));
}

struct OpQ1_Glyph	// NOTE: placeholder name
{
	char pad00[0x20];
	unsigned char flagsA;
	int character;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

	bool equals_415e30(const OpQ1_Glyph &other);	// NOTE: placeholder name
};

bool OpQ1_Glyph::equals_415e30(const OpQ1_Glyph &other)
{
	return flagsA == other.flagsA && character == other.character && r == other.r && g == other.g && b == other.b && a == other.a;
}

extern "C" unsigned int __cdecl SDL_GetTicks(void);
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

class OpQ1_FrameTimer	// NOTE: placeholder name
{
public:
	unsigned int unknown00;
	unsigned int unknown04;
	unsigned int interval;
	unsigned int framesPerSecond;
	unsigned int lastFramesPerSecond;
	unsigned int unknown14;
	unsigned int frameMs;
	bool unknown1c;
	bool unknown1d;

	OpQ1_FrameTimer();	// NOTE: placeholder name (0x41aea0)
	void setFramesPerSecond_41b070(unsigned int value);	// NOTE: placeholder name
	void toggleLimit_41b0b0();	// NOTE: placeholder name
};

OpQ1_FrameTimer::OpQ1_FrameTimer()
{
	unknown00 = 0;
	unknown04 = 0;
	interval = 1000;
	framesPerSecond = 60;
	lastFramesPerSecond = 60;
	unknown14 = 0;
	unknown1c = false;
	unknown1d = false;
	frameMs = framesPerSecond ? 1000 / framesPerSecond : 0;
}

void OpQ1_FrameTimer::setFramesPerSecond_41b070(unsigned int value)
{
	framesPerSecond = value;
	if (framesPerSecond)
	{
		lastFramesPerSecond = framesPerSecond;
		frameMs = 1000 / framesPerSecond;
	}
}

void OpQ1_FrameTimer::toggleLimit_41b0b0()
{
	setFramesPerSecond_41b070(framesPerSecond ? 0 : lastFramesPerSecond);
}

class OpQ1_Clock	// NOTE: placeholder name
{
public:
	unsigned int unknown00;
	unsigned int nextTick;
	unsigned int startTick;
	unsigned int lastTick;

	void start_416920();	// NOTE: placeholder name
};

void OpQ1_Clock::start_416920()
{
	tickCount = SDL_GetTicks();
	lastTick = tickCount;
	startTick = tickCount;
	nextTick = tickCount + 14;
}

class OpQ1_Sprite	// NOTE: placeholder name
{
public:
	char pad00[0x20];
	OpQ1_Sprite *parent;
	int scale;
	char pad28[4];
	int width;
	int height;

	int getWidth_416b70();	// NOTE: placeholder name
	int getHeight_416bb0();	// NOTE: placeholder name
};

int OpQ1_Sprite::getWidth_416b70()
{
	return parent ? parent->width * scale : width;
}

int OpQ1_Sprite::getHeight_416bb0()
{
	return parent ? parent->height * scale : height;
}
