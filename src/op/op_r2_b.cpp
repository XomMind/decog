// op_r2: sound manager / sound path callbacks in 0x4fe000-0x515000 (COGMIND.exe Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Point
{
	int x;
	int y;

	Point() throw();	// 0x453b40
	Point(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
	Point &operator=(const Point &p);	// 0x46ca50 (ICF with the copy ctor)
	bool operator!=(const Point &p) const;	// 0x409bd0
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor() throw();	// 0x411d40
	XColor(const XColor &color) throw();	// 0x411e30
	void read(istream &stream);	// 0x411e70
};

class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	const XColor &unknown5c7630();	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const;	// 0x9b6570
	bool operator==(HEntity e) const;	// 0x9b6620
	void clear() throw();	// 0x9b7270
};

class Cell
{
public:
	int unknown45d430();	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(int x, int y) throw();	// 0x9ceda0
};
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

struct OpR2b_Area	// NOTE: placeholder name (0xd35b84)
{
	bool contains(int x, int y);	// 0x40b700
};
extern OpR2b_Area opr2b_area;	// NOTE: placeholder name

class Cartographer2DMoveCost
{
public:
	virtual bool getNeighbors(int x, int y, int *neighborX, int *neighborY, void *data);	// NOTE: placeholder name
	virtual bool isPassable(int x, int y, void *data) = 0;	// NOTE: placeholder name
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost) = 0;	// NOTE: placeholder name
};

class XBuffer;
class SoundData
{
public:
	char pad0[8];
	vector<XBuffer *> buffers;	// NOTE: placeholder name
};

class AudioMixer	// NOTE: placeholder name (0xcefa90)
{
public:
	bool unknown419540();	// NOTE: placeholder name
	void unknown419c10(XBuffer *chunk, int fade);	// NOTE: placeholder name
	void unknown41a210(int channel);	// NOTE: placeholder name
};
extern AudioMixer *audioMixer;	// NOTE: placeholder name

struct OpR2b_Location	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int type;		// NOTE: placeholder name
};
class OpR2b_HLocation	// NOTE: placeholder name
{
public:
	int ID;
	OpR2b_Location *operator->() const;	// 0x9b7910
};
extern OpR2b_HLocation opr2b_location;	// NOTE: placeholder name (0xd1e888)

extern bool audioDisabled;	// NOTE: placeholder name (0xd28cbc)
extern bool opr2b_groupEnabled[];	// NOTE: placeholder name (0xd28c90)
extern int opr2b_groupVolume[];	// NOTE: placeholder name (0xd28c94)
extern int opr2b_mapSounds[];	// NOTE: placeholder name (0xce9f48)
extern vector<SoundData *> opr2b_sounds;	// NOTE: placeholder name (0xd2e9a0)

void opr2b_loadDeferredSound(SoundData *sound);	// NOTE: placeholder name (0x4fed60)
void opr2b_playSound(int sound, int volume, int a, int b);	// NOTE: placeholder name (0x454200)
int opr2b_distance(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)

class AmbientSource	// NOTE: placeholder name
{
public:
	HEntity prop;	// NOTE: placeholder name
};

class SoundMgr	// NOTE: placeholder name
{
public:
	void unknown4544e0();	// NOTE: placeholder name
	void unknown500010();	// NOTE: placeholder name
	void unknown500260(bool flag);	// NOTE: placeholder name
	void unknown5003b0();	// NOTE: placeholder name
	void updateAmbient();	// 0x4ff710

	vector<AmbientSource *>	sources;	// NOTE: placeholder name
	vector<Point>			points;		// NOTE: placeholder name
	vector<HEntity>			props;		// NOTE: placeholder name
	char					pad30[0x60];
	HEntity					unknown90;	// NOTE: placeholder name
	bool					unknown94;	// NOTE: placeholder name
	HEntity					unknown98;	// NOTE: placeholder name
	Point					unknown9c;	// NOTE: placeholder name
	int						unknowna4;	// NOTE: placeholder name
};

void SoundMgr::unknown500010()
{
	if (!opr2b_groupEnabled[2] || !audioMixer->unknown419540() || audioDisabled)
	{
		points.clear();
		props.clear();
		return;
	}

	bool previous = unknown94;
	unknown94 = false;
	if (unknown90.isValid())
	{
		if (unknown90.operator->() == NULL)
		{
			unknown4544e0();
			return;
		}
		unknown98 = unknown90;
		unknown90.clear();
		unknown9c = unknown98->getPosition();
		updateAmbient();
		return;
	}

	if (unknown98.operator->() == NULL)
	{
		unknown4544e0();
		return;
	}
	if (previous || unknown98->getPosition() != unknown9c)
	{
		unknown9c = unknown98->getPosition();
		updateAmbient();
		return;
	}

	for (unsigned int i = 0; i < props.size(); i++)
	{
		for (unsigned int j = 0; j < sources.size(); j++)
		{
			if (props[i] == sources[j]->prop)
			{
				updateAmbient();
				return;
			}
		}
	}
	for (unsigned int i = 0; i < points.size(); i++)
	{
		if (opr2b_distance(unknown9c,points[i]) <= 25)
		{
			updateAmbient();
			return;
		}
	}
}

void SoundMgr::unknown500260(bool flag)
{
	if (audioDisabled)
		return;
	if (unknowna4 != 0x142)
	{
		if (flag)
		{
			int volumeA = opr2b_groupVolume[3]*100/10;
			audioMixer->unknown419c10(opr2b_sounds[unknowna4]->buffers.front(),volumeA);
		}
		return;
	}
	unknowna4 = opr2b_mapSounds[opr2b_location->type];
	if (unknowna4 == 0x142 || !opr2b_groupEnabled[3] || !audioMixer->unknown419540())
		return;
	opr2b_loadDeferredSound(opr2b_sounds[unknowna4]);
	int volumeB = opr2b_groupVolume[3]*100/10;
	audioMixer->unknown419c10(opr2b_sounds[unknowna4]->buffers.front(),volumeB);
	opr2b_playSound(unknowna4,12,3000,-1);
}

void SoundMgr::unknown5003b0()
{
	if (unknowna4 != 0x142)
	{
		audioMixer->unknown41a210(12);
		unknowna4 = 0x142;
	}
}

class SoundPathCallback : public Cartographer2DMoveCost
{
public:
	virtual bool isPassable(int x, int y, void *data);
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};

bool SoundPathCallback::isPassable(int x, int y, void *data)
{
	return cells(x,y)->unknown45d430() < 100 && opr2b_area.contains(x,y);
}

bool SoundPathCallback::getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
{
	if (!isPassable(toX,toY,data))
		return false;

	cost = (int)((fromX != toX && fromY != toY) ? (cells(toX,toY)->unknown45d430()+2)*1.5 : cells(toX,toY)->unknown45d430()+2);
	return true;
}

extern XColor *opr2b_defaultColor;	// NOTE: placeholder name (0xcfc180)

class OpR2b_Obj500d50	// NOTE: placeholder name
{
public:
	XColor getColor();	// NOTE: placeholder name

	int		type;			// NOTE: placeholder name
	char	pad4[8];
	HEntity	entity;			// NOTE: placeholder name
	char	pad10[8];
	XColor	color;			// NOTE: placeholder name
};

XColor OpR2b_Obj500d50::getColor()
{
	XColor *src;
	XColor *result;
	result = type == 2 ? (src = (entity.operator->() != NULL ? (XColor *)&entity->unknown5c7630() : opr2b_defaultColor)) : &color;
	return *result;
}

struct OpR2b_Elem	// NOTE: placeholder name
{
	int a;
	int b;
	int c;
	int d;
};

struct OpR2b_Info	// NOTE: placeholder name
{
	char pad[0x13c];
	vector<int> list;	// NOTE: placeholder name
};

class HAnim;
class EndObjB	// NOTE: placeholder name (0xcefc50), only the first member is needed here
{
public:
	unsigned unknown4549d0();	// NOTE: placeholder name
	void stopAll();	// NOTE: placeholder name (0x5086c0)
	void unknown454770();	// NOTE: placeholder name
	HAnim *unknown508610();	// NOTE: placeholder name

	vector<HAnim *> anims;	// NOTE: placeholder name
	vector<HAnim *> pool;	// NOTE: placeholder name
	int unknown20;	// NOTE: placeholder name
};
extern EndObjB *opr2b_engine;	// NOTE: placeholder name (0xcefc50)

class OpR2b_Obj500dd0	// NOTE: placeholder name
{
public:
	OpR2b_Obj500dd0(OpR2b_Info *info_, int a_, int b_, int c_, float e_, int f_, int g_, int h_, int i_, vector<OpR2b_Elem> *elems, int j_, int k_);	// NOTE: placeholder name

	unsigned		tick;		// NOTE: placeholder name
	OpR2b_Info		*info;		// NOTE: placeholder name
	int				a;			// NOTE: placeholder name
	int				b;			// NOTE: placeholder name
	int				c;			// NOTE: placeholder name
	int				zero;		// NOTE: placeholder name
	float			e;			// NOTE: placeholder name
	int				f;			// NOTE: placeholder name
	int				g;			// NOTE: placeholder name
	int				h;			// NOTE: placeholder name
	int				i;			// NOTE: placeholder name
	vector<OpR2b_Elem>	elems;	// NOTE: placeholder name
	vector<int>		list;		// NOTE: placeholder name
	vector<OpR2b_Elem>	elemsB;	// NOTE: placeholder name
	int				j;			// NOTE: placeholder name
	int				k;			// NOTE: placeholder name
};

OpR2b_Obj500dd0::OpR2b_Obj500dd0(OpR2b_Info *info_, int a_, int b_, int c_, float e_, int f_, int g_, int h_, int i_, vector<OpR2b_Elem> *elems_, int j_, int k_)
	: info	(info_)
	, a		(a_)
	, b		(b_)
	, c		(c_)
	, zero	(0)
	, e		(e_)
	, f		(f_)
	, g		(g_)
	, h		(h_)
	, i		(i_)
	, j		(j_)
	, k		(k_)
{
	tick = opr2b_engine->unknown4549d0();
	if (elems_ != NULL)
		elems = *elems_;
	if (info != NULL && !info->list.empty())
		list = info->list;
}

//==================================================================
// record readers
//==================================================================

template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name
void opr2b_readText(istream &stream, string *value);	// NOTE: placeholder name (0x436960)
void opr2b_readIntVector(istream &stream, vector<int> *values);	// NOTE: placeholder name (0x9cf5e0)

class SaveStream;	// NOTE: placeholder name

class LogColorEntry	// NOTE: placeholder name
{
public:
	LogColorEntry();	// 0x4545a0
	void read(SaveStream *stream);	// 0x4545c0

	int unknown00;	// NOTE: placeholder name
	XColor color;	// NOTE: placeholder name
	int unknown08;	// NOTE: placeholder name
	int unknown0c;	// NOTE: placeholder name
	int unknown10;	// NOTE: placeholder name
};

struct OpR2b_IntPair	// NOTE: placeholder name
{
	OpR2b_IntPair();	// 0x40bef0
	void read(istream &stream);	// NOTE: placeholder name (0x45f040)

	int a;
	int b;
};

struct OpR2b_Rec500f10;
struct OpR2b_Rec508a80;
void opr2b_readRec500f10s(istream &stream, vector<OpR2b_Rec500f10> *recs);	// NOTE: placeholder name (0x9d5a60)
void opr2b_readRec508a80s(istream &stream, vector<OpR2b_Rec508a80> *recs);	// NOTE: placeholder name (0x9d5c00)

struct OpR2b_Rec500f10	// NOTE: placeholder name (read at 0x500f10)
{
	int unknown[15];
};

struct OpR2b_Rec508a80	// NOTE: placeholder name (read at 0x508a80)
{
	int unknown0;
	int unknown4;
	int unknown8;
	SoundData *sound;	// NOTE: placeholder name
	void *unknown10;
	int unknown14;
};

int soundPlayRelative(const Point &pos, SoundData *sound, int channel, bool noPlay);	// 0x4ff170

class OpR2b_Rec501030	// NOTE: placeholder name
{
public:
	OpR2b_Rec501030(istream &stream);	// 0x501030
	bool unknown5012a0(const Point &pos);	// NOTE: placeholder name

	int unknown0;
	string unknown4;
	int unknown20;
	int unknown24;
	int unknown28;
	int unknown2c;
	int unknown30;
	int unknown34;
	int unknown38;
	OpR2b_IntPair unknown3c;
	bool unknown44;
	bool unknown45;
	int unknown48;
	vector<int> unknown4c;
	int unknown5c;
	bool unknown60;
	LogColorEntry unknown64;
	LogColorEntry unknown78;
	LogColorEntry unknown8c;
	LogColorEntry unknowna0;
	bool unknownb4;
	vector<OpR2b_Rec500f10> unknownb8;
	vector<OpR2b_Rec508a80> unknownc8;
};

OpR2b_Rec501030::OpR2b_Rec501030(istream &stream)
{
	readBinary(stream,&unknown0);
	opr2b_readText(stream,&unknown4);
	readBinary(stream,&unknown20);
	readBinary(stream,&unknown24);
	readBinary(stream,&unknown28);
	readBinary(stream,&unknown2c);
	readBinary(stream,&unknown30);
	readBinary(stream,&unknown34);
	readBinary(stream,&unknown38);
	unknown3c.read(stream);
	readBinary(stream,&unknown44);
	readBinary(stream,&unknown45);
	readBinary(stream,&unknown48);
	opr2b_readIntVector(stream,&unknown4c);
	readBinary(stream,&unknown5c);
	readBinary(stream,&unknown60);
	unknown64.read((SaveStream *)&stream);
	unknown78.read((SaveStream *)&stream);
	unknown8c.read((SaveStream *)&stream);
	unknowna0.read((SaveStream *)&stream);
	readBinary(stream,&unknownb4);
	opr2b_readRec500f10s(stream,&unknownb8);
	opr2b_readRec508a80s(stream,&unknownc8);
}

bool OpR2b_Rec501030::unknown5012a0(const Point &pos)
{
	if (unknownc8.empty())
		return false;
	return soundPlayRelative(pos,unknownc8.front().sound,-1,true) ? true : false;
}

//==================================================================
// geometry
//==================================================================

float opr2b_degToRad(float degrees);	// NOTE: placeholder name (0x9cd000, template instance)
float opr2b_cos(float radians);	// NOTE: placeholder name (0x401290)
float opr2b_sin(float radians);	// NOTE: placeholder name (0x401330)

// rotates point b around point a
void opr2b_rotatePoint(const Point *a, const Point *b, float degrees, Point *out)	// NOTE: placeholder name
{
	float radians = opr2b_degToRad(degrees);
	out->x = (int)(a->x + opr2b_cos(radians)*(b->x - a->x) - opr2b_sin(radians)*(b->y - a->y));
	out->y = (int)(a->y + opr2b_sin(radians)*(b->x - a->x) + opr2b_cos(radians)*(b->y - a->y));
}

//==================================================================
// animation engine
//==================================================================

class OpR3_Counter	// NOTE: placeholder name
{
public:
	void unknown658a30();	// NOTE: placeholder name
};

class OpR2b_HObject	// NOTE: placeholder name (folded handle, 0x9b64d0)
{
public:
	int ID;
	OpR3_Counter *operator->() const;	// 0x9b64d0
};

struct OpR2b_HAnimTarget	// NOTE: placeholder name
{
	char pad[0x28];
	OpR2b_HObject object;	// NOTE: placeholder name
};

struct OpR2b_AnimInfo	// NOTE: placeholder name
{
	char pad[0x20];
	int type;	// NOTE: placeholder name
};

class HAnim;
class OpR2b_AnimOwner	// NOTE: placeholder name (EndObjB)
{
public:
	char pad[0x24];
	vector<HAnim *> unknown24;	// NOTE: placeholder name
	vector<HAnim *> unknown34;	// NOTE: placeholder name
};

bool opr2b_removeElement(vector<HAnim *> &v, HAnim *value);	// NOTE: placeholder name (0x9d51d0)

class HAnim	// NOTE: placeholder name (0xb8 bytes)
{
public:
	void stop();	// 0x504550

	OpR2b_AnimInfo *info;	// NOTE: placeholder name
	OpR2b_AnimOwner *owner;	// NOTE: placeholder name
	int active;	// NOTE: placeholder name
	char padc[0xa8];
	OpR2b_HAnimTarget *target;	// NOTE: placeholder name
};

void HAnim::stop()
{
	if (active != 0)
	{
		switch (info->type)
		{
			case 1:
				if (target->object.operator->() != NULL)
					target->object->unknown658a30();
				opr2b_removeElement(owner->unknown24,this);
				break;
			case 3:
				opr2b_removeElement(owner->unknown34,this);
				break;
		}
		active = 0;
	}
}

class XTimer	// NOTE: placeholder name
{
public:
	void update();	// 0x4218e0
};

class OpR2b_EngineAnim;
template <class T> void opr2b_appendVector(vector<T> &v, vector<T> &other);	// NOTE: placeholder name (0x9d0300)
void opr2b_removeVectorElement(vector<OpR2b_EngineAnim *> &v, int index);	// NOTE: placeholder name (0x9de6f0)
class Item;

class OpR2b_EngineAnim	// NOTE: placeholder name (0xb4 bytes, ctor 0x454a80)
{
public:
	void kill();	// 0x50e830
	bool update();	// NOTE: placeholder name (0x50e890)
	void unknown4582d0(class OpR2b_Engine *engine);	// NOTE: placeholder name
	void render();	// NOTE: placeholder name (0x50f530)
	bool unknown454bd0(OpR2b_AnimInfo *info_, const Point &pos_);	// NOTE: placeholder name

	OpR2b_AnimInfo *info;	// NOTE: placeholder name
	char pad4[0xc];
	Point pos;	// NOTE: placeholder name
	char pad18[0x9c];
};

// the engine's animation list (the one at +0x14 in the engine object)
class OpR2b_Engine	// NOTE: placeholder name
{
public:
	void stopAll();	// NOTE: placeholder name (0x50ff30)
	void unknown50ff80(OpR2b_Engine *other);	// NOTE: placeholder name
	bool update();	// NOTE: placeholder name (0x50fff0)
	void render();	// NOTE: placeholder name (0x5100b0)
	void unknown454c70();	// NOTE: placeholder name
	OpR2b_EngineAnim *unknown50fb50();	// NOTE: placeholder name
	bool unknown50fbf0(OpR2b_AnimInfo *info_, const Point &pos_);	// NOTE: placeholder name

	char pad0[0x14];
	vector<OpR2b_EngineAnim *> anims;	// NOTE: placeholder name
	vector<OpR2b_EngineAnim *> dead;	// NOTE: placeholder name
	XTimer timer;	// NOTE: placeholder name
};

void OpR2b_Engine::stopAll()
{
	for (unsigned int i = 0; i < anims.size(); i++)
		anims[i]->kill();
	unknown454c70();
}

void OpR2b_Engine::unknown50ff80(OpR2b_Engine *other)
{
	for (unsigned int i = 0; i < anims.size(); i++)
		anims[i]->unknown4582d0(other);
	opr2b_appendVector(other->anims,anims);
	anims.clear();
}

bool OpR2b_Engine::update()
{
	if (!anims.empty())
	{
		timer.update();
		for (int i = anims.size()-1; i >= 0; i--)
		{
			if (anims[i]->update())
			{
				dead.push_back(anims[i]);
				opr2b_removeVectorElement(anims,i);
			}
			if (anims.empty())
				break;
		}
		return true;
	}
	else
		return false;
}

void OpR2b_Engine::render()
{
	if (!anims.empty())
	{
		for (unsigned int i = 0; i < anims.size(); i++)
			anims[i]->render();
	}
}

class OpR2b_EffectMgr	// NOTE: placeholder name (0x5088e0)
{
public:
	void unknown5088e0();	// NOTE: placeholder name

	vector<class OpR2b_Effect *> effects;	// NOTE: placeholder name
};

class OpR2b_Effect	// NOTE: placeholder name
{
public:
	void unknown508360();	// NOTE: placeholder name
};

void OpR2b_EffectMgr::unknown5088e0()
{
	if (!effects.empty())
	{
		for (unsigned int i = 0; i < effects.size(); i++)
			effects[i]->unknown508360();
	}
}

void EndObjB::stopAll()
{
	for (unsigned int i = 0; i < anims.size(); i++)
		anims[i]->stop();
	unknown454770();
}

//==================================================================
// record readers (cont.)
//==================================================================

class LogSizeEntry	// NOTE: placeholder name
{
public:
	LogSizeEntry();	// 0x454a10
	void read(SaveStream *stream);	// 0x454a30

	int unknown00;	// NOTE: placeholder name
	int unknown04;	// NOTE: placeholder name
	string text;	// NOTE: placeholder name
};

struct OpR2b_Rec508930	// NOTE: placeholder name (read at 0x508930)
{
	int unknown[18];
};
void opr2b_readRec508930s(istream &stream, vector<OpR2b_Rec508930> *recs);	// NOTE: placeholder name (0x9d5ba0)
void opr2b_readLogSizeEntries(istream &stream, vector<LogSizeEntry> *entries);	// NOTE: placeholder name (0x9d5c60)

class OpR2b_Rec508b10	// NOTE: placeholder name
{
public:
	OpR2b_Rec508b10(istream &stream);	// 0x508b10

	int unknown0;
	string unknown4;
	int unknown20;
	int unknown24;
	int unknown28;
	int unknown2c;
	int unknown30;
	int unknown34;
	int unknown38;
	int unknown3c;
	OpR2b_IntPair unknown40;
	int unknown48;
	vector<int> unknown4c;
	int unknown5c;
	LogColorEntry unknown60;
	LogColorEntry unknown74;
	LogColorEntry unknown88;
	LogColorEntry unknown9c;
	bool unknownb0;
	int unknownb4;
	int unknownb8;
	int unknownbc;
	XColor unknownc0;
	int unknownc4;
	XColor unknownc8;
	vector<OpR2b_Rec508930> unknowncc;
	vector<OpR2b_Rec508a80> unknowndc;
	bool unknownec;
	vector<LogSizeEntry> unknownf0;
};

OpR2b_Rec508b10::OpR2b_Rec508b10(istream &stream)
{
	readBinary(stream,&unknown0);
	opr2b_readText(stream,&unknown4);
	readBinary(stream,&unknown20);
	readBinary(stream,&unknown24);
	readBinary(stream,&unknown28);
	readBinary(stream,&unknown2c);
	readBinary(stream,&unknown30);
	readBinary(stream,&unknown34);
	readBinary(stream,&unknown38);
	readBinary(stream,&unknown3c);
	unknown40.read(stream);
	readBinary(stream,&unknown48);
	opr2b_readIntVector(stream,&unknown4c);
	readBinary(stream,&unknown5c);
	unknown60.read((SaveStream *)&stream);
	unknown74.read((SaveStream *)&stream);
	unknown88.read((SaveStream *)&stream);
	unknown9c.read((SaveStream *)&stream);
	readBinary(stream,&unknownb0);
	readBinary(stream,&unknownb4);
	readBinary(stream,&unknownb8);
	readBinary(stream,&unknownbc);
	unknownc0.read(stream);
	readBinary(stream,&unknownc4);
	unknownc8.read(stream);
	opr2b_readRec508930s(stream,&unknowncc);
	opr2b_readRec508a80s(stream,&unknowndc);
	readBinary(stream,&unknownec);
	opr2b_readLogSizeEntries(stream,&unknownf0);
}

// NOTE: the two pooled-element ctors below are declared without throw() and are defined elsewhere in the link
// (src/game/team_a_13.cpp, src/game/cc_r2_16.cpp): LTCG proves them nothrow and keeps the exe's extra slot.
class EngineItem_454a80 : public OpR2b_EngineAnim	// NOTE: placeholder name (same name as team_a_13.cpp)
{
public:
	EngineItem_454a80();	// 0x454a80
};

class Item454630 : public HAnim	// NOTE: placeholder name
{
public:
	Item454630();	// 0x454630
};
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

HAnim *EndObjB::unknown508610()
{
	if (pool.empty())
	{
		anims.push_back(new Item454630());
	}
	else
	{
		if (anims.empty())
			unknown20 = tickCount;
		anims.push_back(pool.back());
		pool.pop_back();
	}
	return anims.back();
}

OpR2b_EngineAnim *OpR2b_Engine::unknown50fb50()
{
	if (dead.empty())
	{
		anims.push_back(new EngineItem_454a80());
	}
	else
	{
		anims.push_back(dead.back());
		dead.pop_back();
	}
	return anims.back();
}

bool OpR2b_EngineAnim::unknown454bd0(OpR2b_AnimInfo *info_, const Point &pos_)
{
	return info == info_ && pos == pos_;
}

bool OpR2b_Engine::unknown50fbf0(OpR2b_AnimInfo *info_, const Point &pos_)
{
	if (!anims.empty())
	{
		for (int i = anims.size()-1; i >= 0; i--)
		{
			if (anims[i]->unknown454bd0(info_,pos_))
				return true;
		}
	}
	return false;
}
