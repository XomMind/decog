// Small accessors around 0x45c800-0x45ce7c: a map record database and Prop accessors.
// NOTE: class layouts are partial; padding members, member names and method names are placeholders.
#include <string>
#include <vector>

using namespace std;

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
	Point(const Point &p);	// 0x46ca50 (folded with operator=)
	Point &operator=(const Point &p);	// 0x46ca50
};

struct XColor	// NOTE: placeholder layout
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &c);	// 0x411e30
	XColor &operator=(XColor c);	// 0x411f10
};

struct MapInfo	// NOTE: placeholder name
{
	int ID;
	string name;
};

struct MapRecord	// NOTE: placeholder name
{
	MapInfo *info;
	int unknown4;	// NOTE: placeholder name
};

class MapDatabase	// NOTE: placeholder name
{
public:
	MapRecord *unknown45c800(int mapID);	// NOTE: placeholder name
	int unknown45c870(int mapID);	// NOTE: placeholder name
	MapRecord *unknown45c8e0(string name);	// NOTE: placeholder name

	char pad0[0x20];
	vector<MapRecord *> records;	// NOTE: placeholder name
};

class Prop;

struct PropEffects	// NOTE: placeholder name
{
	bool unknown4563e0(int type);	// NOTE: placeholder name
	int unknown456430(int type);	// NOTE: placeholder name
};

struct PropScale	// NOTE: placeholder name
{
	char pad0[0x30];
	int percent;	// NOTE: placeholder name
};

struct PropData	// NOTE: placeholder name; partial record
{
	char pad0[0x60];
	PropScale *scale;	// NOTE: placeholder name
	char pad64[0xb8 - 0x64];
	int percent;	// NOTE: placeholder name
	char padbc[0xd0 - 0xbc];
	bool flagd0;	// NOTE: placeholder name
	bool flagd1;	// NOTE: placeholder name
	char padd2[0x140 - 0xd2];
	int unknown140;	// NOTE: placeholder name
};

class Prop
{
public:
	bool unknown45c9d0(int a);	// NOTE: placeholder name
	int unknown45ca00(int a);	// NOTE: placeholder name
	bool unknown45ca30();	// NOTE: placeholder name
	bool unknown45ca70();	// NOTE: placeholder name
	bool unknown45cab0();	// NOTE: placeholder name
	bool unknown45cad0();	// NOTE: placeholder name
	bool unknown45caf0();	// NOTE: placeholder name
	bool unknown45cb10();	// NOTE: placeholder name
	bool unknown45cb50();	// NOTE: placeholder name
	bool isTrap();	// NOTE: placeholder name (0x45cb70)
	bool unknown45cb90(int value);	// NOTE: placeholder name
	bool unknown45cbd0();	// NOTE: placeholder name
	bool unknown45cc10();	// NOTE: placeholder name
	void unknown45cc50(const Point &p);	// NOTE: placeholder name
	void unknown45cc70(const XColor &c);	// NOTE: placeholder name
	void unknown45cca0(const XColor &c);	// NOTE: placeholder name
	void unknown45ccd0(bool v);	// NOTE: placeholder name
	void unknown45ccf0(bool v);	// NOTE: placeholder name
	void unknown45cd10(bool v);	// NOTE: placeholder name
	void unknown45cd30(bool v);	// NOTE: placeholder name
	void unknown45cd50();	// NOTE: placeholder name
	void unknown45cd70(int a, int b, int c, bool d);	// NOTE: placeholder name
	void unknown45cdb0(int a, int value);	// NOTE: placeholder name
	void unknown45ce10(bool a, int b, bool c, int d);	// NOTE: placeholder name
	void unknown45ce50(int a, bool b);	// NOTE: placeholder name

	void unknown664840(int a, int b, int c, int d, float e, bool f, int g, int *h);	// NOTE: placeholder name
	void unknown65f520(int a1, int a2, int a3, bool a4, int a5, int a6, bool a7, bool a8, int a9);	// NOTE: placeholder name

	int ID;
	PropData *data;	// NOTE: placeholder name
	Point position;	// NOTE: placeholder name
	bool flag10;	// NOTE: placeholder name
	char pad11[7];
	XColor color1;	// NOTE: placeholder name
	XColor color2;	// NOTE: placeholder name
	bool flag1e;	// NOTE: placeholder name
	char pad1f[0x30 - 0x1f];
	PropEffects *effects;	// NOTE: placeholder name
	int machineIndex;	// NOTE: placeholder name
	int pad38;
	int unknown3c;	// NOTE: placeholder name
	bool flag40;	// NOTE: placeholder name
	bool flag41;	// NOTE: placeholder name
	bool flag42;	// NOTE: placeholder name
	char pad43;
	int unknown44;	// NOTE: placeholder name
	bool flag48;	// NOTE: placeholder name
	char pad49[3];
	int unknown4c;	// NOTE: placeholder name
};

MapRecord *MapDatabase::unknown45c800(int mapID)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->info->ID == mapID)
			return records[i];
	}
	return NULL;
}

int MapDatabase::unknown45c870(int mapID)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->info->ID == mapID)
			return records[i]->unknown4;
	}
	return 0;
}

MapRecord *MapDatabase::unknown45c8e0(string name)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->info->name == name)
			return records[i];
	}
	return NULL;
}

bool Prop::unknown45c9d0(int a)
{
	if (effects)
		return effects->unknown4563e0(a);
	return false;
}

int Prop::unknown45ca00(int a)
{
	if (effects)
		return effects->unknown456430(a);
	return 0;
}

bool Prop::unknown45ca30()
{
	return flag40 && machineIndex != -1;
}

bool Prop::unknown45ca70()
{
	return data->flagd0 && unknown3c == 0;
}

bool Prop::unknown45cab0()
{
	return data->flagd1;
}

bool Prop::unknown45cad0()
{
	return flag41;
}

bool Prop::unknown45caf0()
{
	return flag42;
}

bool Prop::unknown45cb10()
{
	return unknown44;
}

bool Prop::unknown45cb50()
{
	return flag48;
}

bool Prop::isTrap()
{
	return unknown4c;
}

void Prop::unknown45cc50(const Point &p)
{
	position = p;
}

void Prop::unknown45cc70(const XColor &c)
{
	color1 = c;
}

void Prop::unknown45cca0(const XColor &c)
{
	color2 = c;
}

void Prop::unknown45ccd0(bool v)
{
	flag10 = v;
}

void Prop::unknown45ccf0(bool v)
{
	flag1e = v;
}

void Prop::unknown45cd10(bool v)
{
	flag40 = v;
}

void Prop::unknown45cd30(bool v)
{
	flag41 = v;
}

void Prop::unknown45cd50()
{
	flag48 = true;
}

// c is integer damage; the callee borrows its address during this call.
void Prop::unknown45cd70(int a, int b, int c, bool d)
{
	unknown664840(a,2,0,0,1.0f,d,b,&c);
}

void Prop::unknown45ce10(bool a, int b, bool c, int d)
{
	unknown65f520(0,4,1,a,b,d,0,c,0);
}

void Prop::unknown45ce50(int a, bool b)
{
	unknown65f520(0,1,1,1,5,a,b,1,0);
}

bool Prop::unknown45cb90(int value)
{
	return unknown4c != 0 && data->unknown140 == value;
}

bool Prop::unknown45cbd0()
{
	return unknown4c != 0 && !flag10;
}

bool Prop::unknown45cc10()
{
	return unknown4c != 0 && flag10;
}

void Prop::unknown45cdb0(int a, int value)
{
	value = value * data->percent / 100 * data->scale->percent / 100;
	unknown65f520(value,4,0,0,1,a,0,0,0);
}
