// SoundMgr / EndObjB and small helper classes (0x454340-0x454a73).
// NOTE: class layouts are partial; padding members, member names and most class names are placeholders.
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor() throw();	// 0x411d40
	XColor(const XColor &color) throw();	// 0x411e30
	void read(istream &stream);
};

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;

	Point() throw();	// 0x453b40
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;

	HProp() throw();
	void clear() throw();	// 0x9b7270
};

class HExplosive	// NOTE: placeholder layout
{
	int ID;
public:
	HExplosive();
};

class Console;
class XBuffer;
class SaveStream;	// NOTE: placeholder name

void readLogField10(SaveStream *stream, void *field);	// NOTE: placeholder name (0x4096f0)
void readLogWidth(SaveStream *stream, int *field);	// NOTE: placeholder name (0x9d8480)

class Bresenham2DStepperSubcell
{
	int pad[11];
public:
	Bresenham2DStepperSubcell() throw();
	virtual ~Bresenham2DStepperSubcell();
};

class KeyHelper	// NOTE: placeholder name
{
public:
	void unknown41a210(int index);	// NOTE: placeholder name
};
extern KeyHelper *unknown_cefa90;	// NOTE: placeholder name

class SoundMgr;
void unknown9e2c40(SoundMgr *mgr);
void unknown9e2be0(void *p, int count, int value);	// NOTE: placeholder name	// NOTE: placeholder name

class SoundMgr	// NOTE: placeholder name
{
public:
	SoundMgr();
	~SoundMgr();

	void unknown454430();	// NOTE: placeholder name
	void unknown4544c0(int value);	// NOTE: placeholder name
	void unknown4544e0();	// NOTE: placeholder name
	void unknown454500(const Point &p);	// NOTE: placeholder name
	void updatePropMute(HProp prop);	// 0x454520
	void unknown454540();	// NOTE: placeholder name

	vector<int>		unknown00;	// NOTE: placeholder name
	vector<Point>	points;		// NOTE: placeholder name
	vector<HProp>	props;		// NOTE: placeholder name
	char			unknown30[0xc];	// NOTE: placeholder name
	char			pad3c[0x90 - 0x3c];
	HProp			unknown90;	// NOTE: placeholder name
	bool			unknown94;	// NOTE: placeholder name
	HProp			unknown98;	// NOTE: placeholder name
	Point			unknown9c;	// NOTE: placeholder name
	int				unknowna4;	// NOTE: placeholder name
};

SoundMgr::SoundMgr()
{
	unknowna4 = 0x142;
}

#if 0	// remaining diff: exe dtor starts at EH state 1 and sets no state before ~vector at +0x20 (ours: 3 tracked members, entry state 2)
SoundMgr::~SoundMgr()
{
	unknown9e2c40(this);
}
#endif

void SoundMgr::unknown454430()
{
	for (int i = 0; i < 12; i++)
		unknown_cefa90->unknown41a210(i);
	points.clear();
	props.clear();
	unknown9e2be0(unknown30,sizeof(unknown30),0);
	unknown90.clear();
	unknown94 = false;
	unknown98.clear();
}

void SoundMgr::unknown4544c0(int value)
{
	unknown90.ID = value;
}

void SoundMgr::unknown4544e0()
{
	unknown454430();
}

void SoundMgr::unknown454500(const Point &p)
{
	points.push_back(p);
}

void SoundMgr::updatePropMute(HProp prop)
{
	props.push_back(prop);
}

void SoundMgr::unknown454540()
{
	unknown94 = true;
}

class Unknown454560	// NOTE: placeholder name
{
public:
	int unknown454560(int unused);	// NOTE: placeholder name

	char pad[0x14];
	int unknown14;	// NOTE: placeholder name
};

int Unknown454560::unknown454560(int unused)
{
	return unknown14;
}

class Unknown454580	// NOTE: placeholder name
{
public:
	XColor unknown454580();	// NOTE: placeholder name

	char pad[0x1b];
	XColor color;	// NOTE: placeholder name
};

XColor Unknown454580::unknown454580()
{
	return color;
}

class LogColorEntry	// NOTE: placeholder name
{
public:
	LogColorEntry();
	void read(SaveStream *stream);	// NOTE: placeholder name

	int unknown00;	// NOTE: placeholder name
	XColor color;	// NOTE: placeholder name
	int unknown08;	// NOTE: placeholder name
	int unknown0c;	// NOTE: placeholder name
	int unknown10;	// NOTE: placeholder name
};

LogColorEntry::LogColorEntry()
{
}

void LogColorEntry::read(SaveStream *stream)
{
	readLogWidth(stream,&unknown00);
	color.read(*(istream *)stream);
	readLogWidth(stream,&unknown08);
	readLogWidth(stream,&unknown0c);
	readLogWidth(stream,&unknown10);
}

class ItemBase454630	// NOTE: placeholder name
{
};

class Item454630 : public ItemBase454630	// NOTE: placeholder name
{
public:
	Item454630() throw();
	~Item454630();

	int				unknown00;	// NOTE: placeholder name
	int				unknown04;	// NOTE: placeholder name
	int				unknown08;	// NOTE: placeholder name
	char			pad0c[4];
	Point			unknown10;	// NOTE: placeholder name
	Point			unknown18;	// NOTE: placeholder name
	Point			unknown20;	// NOTE: placeholder name
	Point			unknown28;	// NOTE: placeholder name
	char			pad30[8];
	Bresenham2DStepperSubcell	stepper;	// NOTE: placeholder name
	Point			unknown68;	// NOTE: placeholder name
	Point			unknown70;	// NOTE: placeholder name
	char			pad78[0x90 - 0x78];
	XColor			unknown90;	// NOTE: placeholder name
	vector<Point>	unknown94;	// NOTE: placeholder name
	vector<int>		unknowna4;	// NOTE: placeholder name
	int				*unknownb4;	// NOTE: placeholder name
};

Item454630::Item454630()
	: unknown00		(0)
	, unknown04		(0)
	, unknown08		(0)
	, unknownb4		(NULL)
{
}

Item454630::~Item454630()
{
	delete unknownb4;
}

class Timer454650	// NOTE: placeholder name
{
public:
	Timer454650();	// 0x421650
	~Timer454650();	// 0x421750
	void init(int a, float b, int c);	// NOTE: placeholder name (0x421680)

	char pad[0x20];
};

void unknown9cfb10(vector<Console*> &v);	// NOTE: placeholder name
void unknown9cfb10(vector<ItemBase454630*> &v);	// NOTE: placeholder name
class EndObjB;
void unknown9d0300(vector<ItemBase454630*> *v, EndObjB *obj);	// NOTE: placeholder name

class EndObjB	// NOTE: placeholder name
{
public:
	EndObjB();
	~EndObjB();

	void unknown454770();	// NOTE: placeholder name
	bool unknown454990();	// NOTE: placeholder name
	vector<Console*> *unknown4549b0();	// NOTE: placeholder name
	unsigned unknown4549d0();	// NOTE: placeholder name

	vector<Console*>		unknown00;	// NOTE: placeholder name
	vector<ItemBase454630*>		items;		// NOTE: placeholder name
	int						unknown20;	// NOTE: placeholder name
	vector<Console*>		unknown24;	// NOTE: placeholder name
	vector<Console*>		unknown34;	// NOTE: placeholder name
	Timer454650				unknown44;	// NOTE: placeholder name
	unsigned				counter;	// NOTE: placeholder name
};

#if 0	// remaining diff: exe keeps two stack temps for the pushed pointer (slots -0x14/-0x18); ours elides one
EndObjB::EndObjB()
{
	for (int i = 0; i < 20000; i++)
	{
		ItemBase454630 *item = new Item454630();
		items.push_back(item);
	}
	unknown44.init(2,0.01f,30);
	counter = 0;
}
#endif

EndObjB::~EndObjB()
{
	unknown9cfb10(unknown00);
	unknown9cfb10(items);
}

void EndObjB::unknown454770()
{
	unknown9d0300(&items,this);
	unknown00.clear();
	unknown24.clear();
	unknown34.clear();
	counter = 0;
}

bool EndObjB::unknown454990()
{
	return !unknown00.empty();
}

vector<Console*> *EndObjB::unknown4549b0()
{
	return &unknown24;
}

unsigned EndObjB::unknown4549d0()
{
	counter++;
	if (counter > 99999999)
		counter = 1;
	return counter - 1;
}

class LogSizeEntry	// NOTE: placeholder name
{
public:
	LogSizeEntry();
	void read(SaveStream *stream);	// NOTE: placeholder name

	int unknown00;	// NOTE: placeholder name
	int unknown04;	// NOTE: placeholder name
	string text;	// NOTE: placeholder name
};

LogSizeEntry::LogSizeEntry()
{
}

void LogSizeEntry::read(SaveStream *stream)
{
	readLogWidth(stream,&unknown00);
	readLogWidth(stream,&unknown04);
	readLogField10(stream,&text);
}

