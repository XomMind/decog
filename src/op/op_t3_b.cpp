// op_t3_b: Prop functions in 0x65c8a0-0x65e8a0 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	void set(int x_, int y_);	// NOTE: placeholder name (0x40a010)
	Point &operator=(const Point &p);	// 0x46ca50
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();	// 0x411d40
	XColor(const XColor &color) throw();	// 0x411e30
	XColor &operator=(XColor color);	// 0x411f10
	bool operator!=(XColor color);	// 0x411f90
	static XColor scale(XColor color, float value);	// NOTE: placeholder name (0x413740)
	static XColor lerp(XColor a, XColor b, float t);	// NOTE: placeholder name
	bool nonzero();	// NOTE: placeholder name (0x412180)
	void setHSV(float h, float s, float v);	// NOTE: placeholder name (0x412500)
	void getHSV(float *h, float *s, float *v);	// NOTE: placeholder name (0x413520)
};

struct OpT3b_XCell	// NOTE: placeholder name
{
	int getChar();	// NOTE: placeholder name (ICF'd trivial getter, 0x9b8f00)
	XColor *getFore();	// NOTE: placeholder name (0x416f40)
	XColor *getBack();	// NOTE: placeholder name (0x416f60)
};

class Item
{
public:
	int unknown577600(int percent);	// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	bool isValid() const;
	Item *operator->() const throw();	// 0x9b65b0
};

class Entity
{
public:
	HItem unknown5d2380(int type);	// NOTE: placeholder name
	int unknown5c7f40();	// NOTE: placeholder name
};

class HEntity
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const;	// 0x9b6570
};

class Prop;

class HProp
{
public:
	int ID;
	HProp();
	bool isValid() const;
	bool isNull() const;
	Prop *operator->() const;	// 0x9b64f0
};

struct OpT3b_PropData	// NOTE: placeholder name
{
	char pad00[0x5c];
	bool unknown5C;	// NOTE: placeholder name
	char pad5d[0x68 - 0x5d];
	int unknown68;	// NOTE: placeholder name
	char pad6c[0xc4 - 0x6c];
	bool unknownC4;	// NOTE: placeholder name
	char padC5[0xf4 - 0xc5];
	int unknownF4;	// NOTE: placeholder name
	int unknownF8;	// NOTE: placeholder name
	char padFC[0x120 - 0xfc];
	int unknown120;	// NOTE: placeholder name
	char pad124[0x158 - 0x124];
	bool unknown158;	// NOTE: placeholder name
	char pad159[0x15c - 0x159];
	int unknown15C;	// NOTE: placeholder name
	char pad160[0x164 - 0x160];
	int unknown164;	// NOTE: placeholder name
	char pad168[0x16c - 0x168];
	XColor unknown16C;	// NOTE: placeholder name
};

struct OpQ5_T9e2c40;
template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name (0x9e2c40)

class ItemEffectList	// NOTE: placeholder name
{
public:
	~ItemEffectList();
};

class UnknownPart45c060	// NOTE: placeholder name
{
public:
	~UnknownPart45c060();	// 0x45c060

	char pad00[0x28];
	int unknown28;	// NOTE: placeholder name
	char pad2c[4];
	bool unknown30;	// NOTE: placeholder name
	char pad31[7];
	int unknown38;	// NOTE: placeholder name
};

class OpR3_PropLink	// NOTE: placeholder name
{
public:
	bool unknown65cf80();	// NOTE: placeholder name (0x65cf80)

	char pad00[0x10];
	int unknown10;	// NOTE: placeholder name
};

class Prop
{
public:
	void unknown65d9d0(int type);	// NOTE: placeholder name
	XColor unknown65dbb0();	// NOTE: placeholder name
	void unknown65e8a0(OpT3b_XCell *cell);	// NOTE: placeholder name
	void unknown65eaa0();	// NOTE: placeholder name (0x65eaa0)
	void unknown65ec20();	// NOTE: placeholder name (0x65ec20)
	OpT3b_PropData *getData();	// NOTE: placeholder name (ICF'd trivial getter, 0x9b8f00)

	HProp handle;	// NOTE: placeholder name
	OpT3b_PropData *data;	// NOTE: placeholder name
	Point position;	// NOTE: placeholder name
	bool unknown10;	// NOTE: placeholder name
	int unknown14;	// NOTE: placeholder name
	XColor color1;	// NOTE: placeholder name
	XColor color2;	// NOTE: placeholder name
	bool passable;	// NOTE: placeholder name
	vector<OpQ5_T9e2c40 *> stats;	// NOTE: placeholder name
	ItemEffectList *machine;	// NOTE: placeholder name
	int unknown34;	// NOTE: placeholder name
	int unknown38;	// NOTE: placeholder name
	int unknown3C;	// NOTE: placeholder name
	bool unknown40;	// NOTE: placeholder name
	bool soundOrigin;	// NOTE: placeholder name
	bool unknown42;	// NOTE: placeholder name
	UnknownPart45c060 *unknown44;	// NOTE: placeholder name
	bool unknown48;	// NOTE: placeholder name
	OpR3_PropLink *unknown4C;	// NOTE: placeholder name
};

class Map	// NOTE: partial
{
public:
	HEntity getPlayer() throw();	// 0x4630f0
	void addPoint6a8(const Point &p);	// NOTE: placeholder name (0x465320)
	void unknown464ed0(HProp prop);	// NOTE: placeholder name
	void unknown71de30(int x, int y);	// NOTE: placeholder name
	int unknown4638e0(int type, int value);	// NOTE: placeholder name
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)

class SoundMgr	// NOTE: placeholder name
{
public:
	void updatePropMute(HProp prop);	// 0x454520
};
extern SoundMgr soundMgr;	// NOTE: placeholder name (0xd2d2a0)

extern vector<OpT3b_PropData *> opT3b_propTypes;	// NOTE: placeholder name (0xcf35b0)
extern vector<vector<HProp> > opT3b_machines;	// NOTE: placeholder name (0xd31640)
extern XColor opT3b_colorD29804;	// NOTE: placeholder name (0xd29804)
extern XColor *opT3b_colorCF281C;	// NOTE: placeholder name
extern XColor *opT3b_colorD23094;	// NOTE: placeholder name
extern XColor *opT3b_colorCF63B0;	// NOTE: placeholder name
extern XColor *opT3b_colorD204AC;	// NOTE: placeholder name
extern float opT3b_machineHue[][3];	// NOTE: placeholder name (0xb9e678)
extern float opT3b_machineSat[][3];	// NOTE: placeholder name (0xb9e67c)
extern float opT3b_machineScale[][3];	// NOTE: placeholder name (0xb9e680)
extern float opT3b_flatHue[][3];	// NOTE: placeholder name (0xb9e654)
extern float opT3b_flatSat[][3];	// NOTE: placeholder name (0xb9e658)
extern float opT3b_flatScale[][3];	// NOTE: placeholder name (0xb9e65c)
extern const float opT3b_machineValueFactor;	// NOTE: placeholder name (0xb9e650)
float opT3b_pulse(float low, float high, int period, int offset);	// NOTE: placeholder name (0x4371a0)
bool opT3b_periodic(int period);	// NOTE: placeholder name (0x437320)

void Prop::unknown65d9d0(int type)
{
	if (data->unknown68 != opT3b_propTypes[type]->unknown68)
		world->addPoint6a8(position);
	soundMgr.updatePropMute(handle);
	data = opT3b_propTypes[type];
	unknown10 = data->unknown5C;
	unknown14 = data->unknown164;
	color1 = data->unknown16C;
	color2 = opT3b_colorD29804;
	passable = data->unknownC4;
	OpQ5_clearObjects(stats);
	unknown65eaa0();
	world->unknown464ed0(handle);
	delete machine;
	unknown65ec20();
	unknown34 = -1;
	unknown38 = -1;
	unknown3C = 0;
	unknown40 = false;
	soundOrigin = data->unknown15C;
	unknown42 = data->unknown158;
	delete unknown44;
	unknown44 = NULL;
	unknown48 = false;
	unknown4C = NULL;
	world->unknown71de30(position.x,position.y);
}

XColor Prop::unknown65dbb0()
{
	if (unknown34 != -1)
	{
		if (unknown48)
			return XColor::lerp(color1,*opT3b_colorCF281C,opT3b_pulse(0.0f,1.0f,2000,0));
		else if (unknown3C == 4)
			return XColor::lerp(color1,*opT3b_colorD23094,opT3b_pulse(0.0f,1.0f,2000,0));
		else if (unknown3C == 3)
			return XColor::lerp(color1,*opT3b_colorCF63B0,opT3b_pulse(0.0f,1.0f,2000,0));
		else if (unknown3C == 2 && world->getPlayer()->unknown5d2380(0x1a).isValid())
			return XColor::lerp(color1,*opT3b_colorD204AC,opT3b_pulse(0.0f,1.0f,2000,0));
		else if (unknown3C == 0)
		{
			if (data->unknownF8 != 5 && ((unknown44 != NULL && unknown44->unknown28 < 0) || (!opT3b_machines[unknown34].empty() && opT3b_machines[unknown34].front()->unknown44 != NULL && opT3b_machines[unknown34].front()->unknown44->unknown28 < 0)))
			{
				XColor col = color1;
				float h;
				float s;
				float v;
				col.getHSV(&h,&s,&v);
				v = v / opT3b_machineScale[data->unknownF8][0] * opT3b_machineValueFactor;
				col.setHSV(0.0f,0.0f,v);
				return col;
			}
			if (unknown44 == NULL && !opT3b_machines[unknown34].empty() && opT3b_machines[unknown34].front()->unknown44 != NULL && opT3b_machines[unknown34].front()->unknown44->unknown38 != 0)
				return XColor::scale(color1,opT3b_pulse(0.0f,0.5f,2000,0) + 0.5);
			if (unknown44 != NULL && unknown44->unknown28 >= 0 && unknown44->unknown30 && opT3b_periodic(1000))
				return color2;
		}
	}
	else if (unknown4C != NULL && world->unknown4638e0(unknown4C->unknown10,0))
		return XColor::scale(color1,opT3b_pulse(0.0f,0.5f,2000,0) + 0.5);
	return color1;
}

void Prop::unknown65e8a0(OpT3b_XCell *cell)
{
	float h;
	float s;
	float v;
	bool state = data->unknownF4 == 1;
	unknown14 = cell->getChar();
	bool fore = true;
	while (true)
	{
		if (fore ? cell->getFore()->nonzero() : cell->getBack()->nonzero())
		{
			if (fore)
				cell->getFore()->getHSV(&h,&s,&v);
			else
				cell->getBack()->getHSV(&h,&s,&v);
			v = v / opT3b_machineValueFactor * (state ? opT3b_machineScale[data->unknownF8][0] : opT3b_flatScale[data->unknown120][0]);
			if (v >= 1.0)
				v = 1.0f;
			if (state)
			{
				XColor *target = fore ? &color1 : &color2;
				target->setHSV(opT3b_machineHue[data->unknownF8][0],opT3b_machineSat[data->unknownF8][0],v);
			}
			else
			{
				XColor *target = fore ? &color1 : &color2;
				target->setHSV(opT3b_flatHue[data->unknown120][0],opT3b_flatSat[data->unknown120][0],v);
			}
		}
		if (fore)
			fore = false;
		else
			break;
	}
}
