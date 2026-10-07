// team_a_09: small helpers in 0x408000-0x48c700 (string char helpers, key state, list removal, console recursion).
// NOTE: class, member and function names are placeholders; layouts are partial.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern "C" unsigned int SDL_GetTicks();

struct Point
{
	int	x;
	int	y;
	Point(const Point &p);						// 0x46ca50
	Point &operator=(const Point &p);			// 0x46ca50 (ICF with the copy ctor)
};

struct Area	// NOTE: placeholder name
{
	Point min;
	Point max;
	Area &operator=(const Area &other);	// 0x40b130 (ICF with the copy constructor)
};

class Areas_4594f0	// NOTE: placeholder name
{
public:
	char pad[0x80];
	Area unknown80;
	char pad90[0xa4 - 0x90];
	Area unknownA4;
	void setBoth(const Area &a);
};

void Areas_4594f0::setBoth(const Area &a)
{
	unknown80 = unknownA4 = a;
}

void replaceChar_4081c0(string &s, char from, char to)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (s[i] == from)
			s[i] = to;
	}
}

char randomChar_4085b0(string &s)	// NOTE: placeholder name
{
	return s[rng.rangeInt(0,s.size() - 1)];
}

void stripLeadingChar_408600(string &s, char c)	// NOTE: placeholder name
{
	while (!s.empty() && s[0] == c)
		s.erase(s.begin());
}

extern int global_cefa78;	// NOTE: placeholder name (0xcefa78)
struct Timer_4168b0	// NOTE: placeholder name
{
	bool unknown0;
	int unknown4;
	int unknown8;
	int unknownC;
	Timer_4168b0();
};

Timer_4168b0::Timer_4168b0()
{
	unknown0 = false;
	unknown4 = 1;
	unknown8 = 0;
	unknownC = 0;
	global_cefa78 = 0;
	tickCount = 1;
}

struct OpS8b_T9d4f60;
void OpS8b_Fn9d4f60(vector<OpS8b_T9d4f60*> &v, int &index);	// NOTE: placeholder name
class List_417dd0	// NOTE: placeholder name
{
public:
	char pad[0x44];
	vector<OpS8b_T9d4f60 *> items;
	void removeOthers(OpS8b_T9d4f60 *keep);
};

void List_417dd0::removeOthers(OpS8b_T9d4f60 *keep)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] != keep)
			OpS8b_Fn9d4f60(items,i);
	}
}

class Notice_418e20	// NOTE: placeholder name
{
public:
	char pad[0x16c];
	string text;
	unsigned int expire;
	void show(const string &s);
};

void Notice_418e20::show(const string &s)
{
	text = s;
	expire = SDL_GetTicks() + 5000;
}

extern int keyCodes_cec458[0x143];	// NOTE: placeholder name (0xcec458)
extern unsigned char *keyState_cefa84;	// NOTE: placeholder name (0xcefa84)
class Keys_439510	// NOTE: placeholder name
{
public:
	bool mapped;
	bool isDown(int key);
};

bool Keys_439510::isDown(int key)
{
	if (mapped)
	{
		for (int i = 0; i < 0x143; i++)
		{
			if (keyCodes_cec458[i] == key)
				return keyState_cefa84[i];
		}
		return false;
	}
	else
		return keyState_cefa84[key];
}

class HProp
{
public:
	int ID;
	HProp() throw();							// 0x9b6590
};

class Push_453b40	// NOTE: placeholder name (constructor 0x453b40)
{
public:
	int a;
	int b;
	Push_453b40() throw();
};

struct OpV4d_Trivial;
void deleteMapRecords_4543b0(vector<OpV4d_Trivial *> &v) throw();	// NOTE: placeholder name (OpV4d_deleteMapRecords, nothrow in the exe)

class HExplosive	// NOTE: placeholder layout
{
	int	ID;
};

class Unknown_454340_4543b0	// NOTE: placeholder name (shared with team_d_04.cpp)
{
public:
	vector<OpV4d_Trivial *> unknown0;
	vector<Point> unknown10;
	vector<HExplosive> unknown20;
	char pad30[0x90 - 0x30];
	HProp unknown90;
	int unknown94;
	HProp unknown98;
	Push_453b40 unknown9c;
	int unknownA4;
	Unknown_454340_4543b0();
	~Unknown_454340_4543b0();
};

Unknown_454340_4543b0::~Unknown_454340_4543b0()
{
	deleteMapRecords_4543b0(unknown0);
}

Unknown_454340_4543b0::Unknown_454340_4543b0()
{
	unknownA4 = 0x142;
}

struct OpQ5_U9d0300
{
	int pad;
};
template <class T> void OpQ5_appendVector(vector<T> &v, vector<T> &other);	// NOTE: placeholder name

class Sounds_454c70	// NOTE: placeholder name
{
public:
	char pad[0x14];
	vector<OpQ5_U9d0300> pending;
	vector<OpQ5_U9d0300> active;
	void flush();
};

void Sounds_454c70::flush()
{
	OpQ5_appendVector(active,pending);
	pending.clear();
}

class Explosion_455880	// NOTE: placeholder name
{
public:
	int unknown0;
	int unknown4;
	Point unknown8;
	Point unknown10;
	Point unknown18;
	void init(int a, int b, const Point &p1, const Point &p2, const Point &p3);
	void unknown515790();	// NOTE: placeholder name
};

void Explosion_455880::init(int a, int b, const Point &p1, const Point &p2, const Point &p3)
{
	unknown0 = a;
	unknown4 = b;
	unknown8 = p1;
	unknown10 = p2;
	unknown18 = p3;
	unknown515790();
}

class Weapon_457580	// NOTE: placeholder name
{
public:
	char pad[0x50];
	int unknown50;
	char pad54[0x94 - 0x54];
	void *unknown94;
	int unknown457580(int divisor);
};

int Weapon_457580::unknown457580(int divisor)
{
	return (unknown50 / 2 + 1) * (unknown94 ? 12 : 8) / (divisor ? divisor : 1);
}

struct Info_457940	// NOTE: placeholder layout
{
	char pad[0xa4];
	int unknownA4;
};

class Item_457940	// NOTE: placeholder name
{
public:
	int pad0;
	int pad4;
	Info_457940 *info;
	int delegate_457920();	// NOTE: placeholder name
	int unknown457940();
};

int Item_457940::unknown457940()
{
	return info->unknownA4 - delegate_457920() / 2;
}

class Virtual_45b5e0	// NOTE: placeholder name
{
public:
	virtual void v00();
	virtual void v04();
	virtual void v08(int x1, int y1, int x2, int y2, int a, int b);
	void unknown45b5e0(const Point &a, const Point &b, int c, int d);
};

void Virtual_45b5e0::unknown45b5e0(const Point &a, const Point &b, int c, int d)
{
	v08(a.x,a.y,b.x,b.y,c,d);
}

struct OpS8c_Plain;
template <class T> void OpS8c_deleteObject(vector<T*> &v, int index);	// NOTE: placeholder name
class List_45e020	// NOTE: placeholder name
{
public:
	char pad[0x5c];
	vector<OpS8c_Plain *> items;
	void remove(OpS8c_Plain *item);
};

void List_45e020::remove(OpS8c_Plain *item)
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i] == item)
		{
			OpS8c_deleteObject(items,i);
			break;
		}
	}
}

template <class T> void removeVectorElement(vector<T> &v, int index);	// NOTE: placeholder name
class Rolls_460670	// NOTE: placeholder name
{
public:
	vector<int> values;
	int next();
};

int Rolls_460670::next()
{
	int value = values[0];
	removeVectorElement(values,0);
	values.push_back(rng.rangeInt(1,100));
	return value;
}

class XConsole
{
public:
	vector<XConsole*> *getSubconsoles();	// 0x4175d0
};

class OpR2b_Engine
{
public:
	int cleanup_470b50();	// NOTE: placeholder name
	void stopAll();
};

class Console : public XConsole
{
public:
	char pad[0x64];
	OpR2b_Engine *engine;
	int countAll_48c5e0();	// NOTE: placeholder name
	void stopAll_48c650();	// NOTE: placeholder name
};

int Console::countAll_48c5e0()
{
	int count = engine->cleanup_470b50();
	vector<XConsole*> *subs = getSubconsoles();
	for (unsigned int i = 0; i < subs->size(); i++)
		count += ((Console *)(*subs)[i])->countAll_48c5e0();
	return count;
}

void Console::stopAll_48c650()
{
	engine->stopAll();
	vector<XConsole*> *subs = getSubconsoles();
	for (unsigned int i = 0; i < subs->size(); i++)
		((Console *)(*subs)[i])->stopAll_48c650();
}

struct SoundQueue_456780 : public vector<OpQ5_U9d0300>	// NOTE: placeholder name
{
	void merge(vector<OpQ5_U9d0300> &other, bool atFront);
};

void SoundQueue_456780::merge(vector<OpQ5_U9d0300> &other, bool atFront)
{
	if (atFront)
		insert(begin(),other.begin(),other.end());
	else
		OpQ5_appendVector(*this,other);
	other.clear();
}
