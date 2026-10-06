// MapView small accessors/setters laid out at 0x49ab20-0x49b117.
// NOTE: class layouts are partial; padding members and all member/class names here are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int	x;
	int	y;

	Point &operator=(const Point &p);			// 0x46ca50
};

class Entity;
class HEntity
{
	int	ID;
public:
	HEntity();
	void clear();								// 0x9b7270
};

class PropB;
class HProp
{
	int	ID;
public:
	HProp();
};

struct MapRecord	// NOTE: placeholder name
{
	int	ID;
};

class XBuffer	// NOTE: placeholder name
{
public:
	XBuffer(bool flag) throw();					// 0x499b50
	char pad[0x18];
};

class XBufferB	// NOTE: placeholder name
{
public:
	XBufferB(const Point &p, bool flag) throw();	// 0x499cf0
	char pad[0x10];
};

class PanelChild	// NOTE: placeholder name
{
public:
	void unknown499af0();	// NOTE: placeholder name
};

class Panel	// NOTE: placeholder name
{
public:
	void unknown49abf0();	// NOTE: placeholder name

	char pad0[0x370];
	PanelChild *child;	// NOTE: placeholder name
};


extern unsigned int tickCount;					// 0xcaed20
extern int unknown_d28e40;						// NOTE: placeholder name

int unknown9d4660(vector<MapRecord *> *v,int id);	// NOTE: placeholder name
void unknown9d4760(vector<MapRecord *> *v,int i);	// NOTE: placeholder name
void unknown9d47d0(vector<MapRecord *> *v,int i);	// NOTE: placeholder name

class MapView	// NOTE: placeholder name
{
public:
	bool unknown49ab20();	// NOTE: placeholder name
	bool unknown49ab40();	// NOTE: placeholder name
	bool unknown49ab60();	// NOTE: placeholder name
	int unknown49abb0();	// NOTE: placeholder name
	bool unknown49ac10();	// NOTE: placeholder name
	void unknown49ac30(const Point &p);	// NOTE: placeholder name
	void unknown49ac50();	// NOTE: placeholder name
	void unknown49ac70();	// NOTE: placeholder name
	bool unknown49ac90(const Point &p,bool a,int b);	// NOTE: placeholder name
	bool unknown806d00(vector<Point> &v,bool a);	// NOTE: placeholder name
	void unknown49ad30();
	void unknown49ad70(int a);	// NOTE: placeholder name
	void unknown49ada0(int a);	// NOTE: placeholder name
	void unknown49adc0(int a);
	void unknown49adf0(unsigned int a);	// NOTE: placeholder name
	void unknown49ae20(int a);	// NOTE: placeholder name
	XBuffer *unknown49ae50(bool a);	// NOTE: placeholder name
	XBuffer *unknown49aec0();	// NOTE: placeholder name
	void unknown49aee0();	// NOTE: placeholder name
	void unknown49af00();	// NOTE: placeholder name
	void unknown49af20();	// NOTE: placeholder name
	HProp unknown49af40();	// NOTE: placeholder name
	void unknown49af60();	// NOTE: placeholder name
	void unknown49af80(int id);	// NOTE: placeholder name
	void unknown49afd0(const Point &p,bool a);	// NOTE: placeholder name
	MapRecord *unknown49b050();	// NOTE: placeholder name
	void unknown49b070(int id);	// NOTE: placeholder name
	bool unknown49b0c0(int id);	// NOTE: placeholder name

	char pad0[0x6c];
	Point pos6c;	// NOTE: placeholder name
	HEntity entity74;	// NOTE: placeholder name
	bool flag78;	// NOTE: placeholder name
	char pad79[0xcc - 0x79];
	HProp prop;	// NOTE: placeholder name
	char padd0[0xd8 - 0xd0];
	bool flagd8;	// NOTE: placeholder name
	char padd9[0x124 - 0xd9];
	vector<XBufferB *> buffersB;	// NOTE: placeholder name
	char pad134[0x1c8 - 0x134];
	vector<MapRecord *> records1c8;	// NOTE: placeholder name
	vector<MapRecord *> records1d8;	// NOTE: placeholder name
	char pad1e8[0x214 - 0x1e8];
	unsigned int tick214;	// NOTE: placeholder name
	char pad218[0x458 - 0x218];
	int value458;	// NOTE: placeholder name
	unsigned int tick45c;	// NOTE: placeholder name
	vector<XBuffer *> buffers;	// NOTE: placeholder name
	char pad470[0x4c8 - 0x470];
	int value4c8;	// NOTE: placeholder name
	char pad4cc[0x540 - 0x4cc];
	bool flag540;	// NOTE: placeholder name
	char pad541[0x55c - 0x541];
	HEntity entity55c;	// NOTE: placeholder name
	char pad560[0x64c - 0x560];
	int value64c;	// NOTE: placeholder name
	int value650;	// NOTE: placeholder name
	char pad654[0x668 - 0x654];
	unsigned int tick668;	// NOTE: placeholder name
	vector<unsigned int> values66c;	// NOTE: placeholder name
	unsigned int tick67c;	// NOTE: placeholder name
	char pad680[0x760 - 0x680];
	int state760;	// NOTE: placeholder name
	char pad764[0x768 - 0x764];
	int value768;	// NOTE: placeholder name
	char pad76c[0x770 - 0x76c];
	int value770;	// NOTE: placeholder name
	vector<Point> points774;	// NOTE: placeholder name
	char pad784[0x7f8 - 0x784];
	bool flag7f8;	// NOTE: placeholder name
};

void Panel::unknown49abf0()
{
	child->unknown499af0();
}

bool MapView::unknown49ab20()
{
	return flag7f8;
}

bool MapView::unknown49ab40()
{
	return value4c8 != -1;
}

bool MapView::unknown49ab60()
{
	return (state760 == 8 && points774.empty()) ? 0 : 1;
}

int MapView::unknown49abb0()
{
	return value768;
}

bool MapView::unknown49ac10()
{
	return flagd8;
}

void MapView::unknown49ad30()
{
	state760 = 8;
	value770 = 0;
	points774.clear();
}

void MapView::unknown49ad70(int a)
{
	value64c = a;
	unknown49ad30();
}

void MapView::unknown49ada0(int a)
{
	value650 = a;
}

void MapView::unknown49adc0(int a)
{
	unknown49ad70(tickCount + a);
	unknown49ada0(tickCount + a);
}

void MapView::unknown49adf0(unsigned int a)
{
	tick668 = tickCount;
	values66c.push_back(a);
}

void MapView::unknown49ae20(int a)
{
	value458 = a;
	tick45c = tickCount;
}

XBuffer *MapView::unknown49ae50(bool a)
{
	XBuffer *buffer = new XBuffer(a);
	XBuffer *copy = buffer;
	buffers.push_back(copy);
	return buffers.back();
}

XBuffer *MapView::unknown49aec0()
{
	return buffers.back();
}

void MapView::unknown49aee0()
{
	tick67c = tickCount + 1000;
}

void MapView::unknown49af00()
{
	flag540 = true;
}

void MapView::unknown49af20()
{
	entity55c.clear();
}

HProp MapView::unknown49af40()
{
	return prop;
}

void MapView::unknown49af60()
{
	tick214 = tickCount;
}

void MapView::unknown49af80(int id)
{
	int i = unknown9d4660(&records1c8,id);
	if (i != -1)
		unknown9d4760(&records1c8,i);
}

MapRecord *MapView::unknown49b050()
{
	return records1d8.back();
}

void MapView::unknown49b070(int id)
{
	int i = unknown9d4660(&records1d8,id);
	if (i != -1)
		unknown9d47d0(&records1d8,i);
}

bool MapView::unknown49b0c0(int id)
{
	for (unsigned int i = 0; i < records1d8.size(); i++)
	{
		if (records1d8[i]->ID == id)
			return true;
	}
	return false;
}

void MapView::unknown49ac30(const Point &p)
{
	pos6c = p;
}

void MapView::unknown49ac50()
{
	entity74.clear();
}

void MapView::unknown49ac70()
{
	flag78 = true;
}

bool MapView::unknown49ac90(const Point &p,bool a,int b)
{
	vector<Point> v(1,p);
	bool result = unknown806d00(v,a);
	if (result && b != 0)
		unknown49adc0(b);
	return result;
}

void MapView::unknown49afd0(const Point &p,bool a)
{
	XBufferB *buffer = new XBufferB(p,a);
	XBufferB *copy = buffer;
	buffersB.push_back(copy);
	unknown49ac90(p,unknown_d28e40 != 0,0);
}
