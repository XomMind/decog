// op_x5_d: functions in 0x966070-0x969000 of COGMIND.exe (Beta 17.1). Names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Pos
{
	int x;
	int y;

	Pos();
};

struct Point
{
	int x;
	int y;

	Point(int x_, int y_);	// 0x46ca20
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int width_, int height_) throw();	// 0x456940
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event) = 0;
	virtual void inputKey(int key, int mode);	// NOTE: placeholder name
	virtual void update() = 0;
	virtual void render() = 0;	// NOTE: placeholder name

	int getWidth();	// 0x44b0d0
	int getHeight();
	Pos getPos();
	void unknown429fe0(XConsole *console, const Point &pos, Rect *rect);	// NOTE: placeholder name
	void copyColorsTo(XConsole *dest, Point &destPos, Rect *rect);	// NOTE: placeholder name (0x42a3c0)

	char pad04[0x60 - 0x04];
};

class OpX5D_EngineItem	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpX5D_Engine	// NOTE: placeholder name
{
public:
	OpX5D_EngineItem *unknown50fb50(OpX5D_Engine *engine, int type, const Point &a, const Point &b, const Point &c, const Point &d, int value);	// NOTE: placeholder name
};

class Console : public XConsole
{
public:
	virtual ~Console();
	virtual bool input(void *event);
	virtual void update();
	virtual void render();

	void animate(string name) { animate(name,0x30,0); };	// NOTE: placeholder name
	void animate(string name, int unknown1, int unknown2);	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name

	int unknown60;
	OpX5D_Engine *engine;
	void *title;
};

class CEffect : public Console
{
public:
	CEffect(XConsole *parent, const Rect &rect, int type_);
	void unknown48c460(int id, const Point &pos);	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
};

extern XConsole *opX5D_cec138;	// NOTE: placeholder name
extern XConsole *opX5D_cec078;	// NOTE: placeholder name
extern XConsole *opX5D_cec07c;	// NOTE: placeholder name
extern XConsole *opX5D_cec084;	// NOTE: placeholder name
extern XConsole *opX5D_cec088;	// NOTE: placeholder name
extern XConsole *opX5D_cec08c;	// NOTE: placeholder name
extern Point opX5D_cfbec0;	// NOTE: placeholder name
int OpX5D_randomElement(vector<int> &v);	// NOTE: placeholder name (0x9d5d00)
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
string intToString(int value);	// 0x4051f0
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name

extern XConsole *opX5D_cec0b0;	// NOTE: placeholder name
extern XConsole *opX5D_cec0c8;	// NOTE: placeholder name
extern XConsole *opX5D_cec074;	// NOTE: placeholder name
extern int opX5D_d01a20;	// NOTE: placeholder name
extern unsigned int opX5D_tickCount;	// NOTE: placeholder name (0xcaed20)
extern int opX5D_screenWidth;	// NOTE: placeholder name (0xcf27f4)
extern int opX5D_screenHeight;	// NOTE: placeholder name (0xcf27f8)

class REX	// NOTE: placeholder layout (0xd223f0)
{
public:
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
	XConsole *getConsole_4ab670();	// NOTE: placeholder name (folded getter)
};
extern REX opX5D_rex;	// NOTE: placeholder name

class HEntity
{
public:
	int ID;
	HEntity() throw();
};

struct OpS2_PhraseTextB	// NOTE: placeholder name
{
	OpS2_PhraseTextB(int index, string *a, string *b, string *c, HEntity d, HEntity e);	// 0x510f80

	char pad00[0x28];
};

class OpX5D_MessageLog	// NOTE: placeholder name (object at 0xcf1080)
{
public:
	int push(OpS2_PhraseTextB *text);	// NOTE: placeholder name (0x5121f0)
};
extern OpX5D_MessageLog opX5D_messageLog;	// NOTE: placeholder name

class OpX5D_Messages	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpX5D_Messages *opX5D_cec058;	// NOTE: placeholder name

class OpX5D_LogMsgs	// NOTE: placeholder name (0xcec0b4)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpX5D_LogMsgs *opX5D_cec0b4;	// NOTE: placeholder name

template <class T> class OpX5_Array2D	// NOTE: placeholder name (defined in op_x5.cpp)
{
public:
	T *at(int x, int y);

	int width;
	int height;
	T *cells;
};

class OpX5D_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	OpX5_Array2D<bool> *unknown4637f0();	// NOTE: placeholder name
	OpX5_Array2D<int> *unknown463830();	// NOTE: placeholder name
};
extern OpX5D_World *opX5D_world;	// NOTE: placeholder name (0xcefc4c)

class OpX5D_Map : public Console	// NOTE: placeholder name
{
public:
	void unknown8051f0(Pos *min, Pos *max);	// NOTE: placeholder name
	const Point &unknown458ef0();	// NOTE: placeholder name (folded getter)
};
extern OpX5D_Map *opX5D_cec054;	// NOTE: placeholder name

class OpX5D_Effect	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class OpX5D_EffectMgr	// NOTE: placeholder name
{
public:
	OpX5D_Effect *create();	// NOTE: placeholder name (0x508610)
};
extern OpX5D_EffectMgr *opX5D_effectMgr;	// NOTE: placeholder name (0xcefc50)

void OpX5D_spawnBorderEffects(vector<int> &horizontalTiles, vector<int> &verticalTiles, int endState, int startState, XConsole *console, int count)	// NOTE: placeholder name
{
	CEffect *effect;
	bool chance;
	for (int i = 0; i < 4; i++)
	{
		chance = rng.chance(50);
		switch (i)
		{
			case 0:
				effect = new CEffect(opX5D_cec138,Rect(console->getPos().x,console->getPos().y,console->getWidth(),1),4);
				goto horizontal;
			case 1:
				effect = new CEffect(opX5D_cec138,Rect(console->getPos().x,console->getPos().y + console->getHeight() - 1,console->getWidth(),1),4);
horizontal:
				effect->unknown48c3c0(startState);
				if (chance)
				{
					for (int j = 0; j < count; j++)
					{
						do
						{
							effect->engine->unknown50fb50(effect->engine,OpX5D_randomElement(horizontalTiles),Point(rng.rangeInt(effect->getWidth() / 4,effect->getWidth() - 1),0),opX5D_cfbec0,Point(0,0),opX5D_cfbec0,9)->unknown50de10();
						} while (0);
					}
				}
				else
				{
					for (int k = 0; k < count; k++)
					{
						do
						{
							effect->engine->unknown50fb50(effect->engine,OpX5D_randomElement(horizontalTiles),Point(rng.rangeInt(0,effect->getWidth() / 4 * 3 - 1),0),opX5D_cfbec0,Point(effect->getWidth() - 1,0),opX5D_cfbec0,9)->unknown50de10();
						} while (0);
					}
				}
				effect->unknown48c3c0(endState);
				break;
			case 2:
				effect = new CEffect(opX5D_cec138,Rect(console->getPos().x,console->getPos().y,1,console->getHeight()),4);
				goto vertical;
			case 3:
				effect = new CEffect(opX5D_cec138,Rect(console->getPos().x + console->getWidth() - 1,console->getPos().y,1,console->getHeight()),4);
vertical:
				effect->unknown48c3c0(startState);
				if (chance)
				{
					for (int l = 0; l < count; l++)
					{
						do
						{
							effect->engine->unknown50fb50(effect->engine,OpX5D_randomElement(verticalTiles),Point(0,rng.rangeInt(effect->getHeight() / 4,effect->getHeight() - 1)),opX5D_cfbec0,Point(0,0),opX5D_cfbec0,9)->unknown50de10();
						} while (0);
					}
				}
				else
				{
					for (int m = 0; m < count; m++)
					{
						do
						{
							effect->engine->unknown50fb50(effect->engine,OpX5D_randomElement(verticalTiles),Point(0,rng.rangeInt(0,effect->getHeight() / 4 * 3 - 1)),opX5D_cfbec0,Point(0,effect->getHeight() - 1),opX5D_cfbec0,9)->unknown50de10();
						} while (0);
					}
				}
				effect->unknown48c3c0(endState);
				break;
		}
	}
}

class OpX5D_Obj_cec138 : public Console	// NOTE: placeholder name (object at 0xcec138)
{
public:
	void unknown9666d0();	// NOTE: placeholder name
	void unknown966ed0();	// NOTE: placeholder name
	void unknown9675f0();	// NOTE: placeholder name
	void unknown967c90();	// NOTE: placeholder name

	char pad6c[0xbc - 0x6c];
	vector<CEffect*> unknownbc;
	int unknowncc;
	vector<CEffect*> unknownd0;
	int unknowne0;
	vector<CEffect*> unknowne4;
	int unknownf4;
	int unknownf8;
};

void OpX5D_Obj_cec138::unknown9666d0()
{
	string horizontalString = "CEffect_Xom_Horz_";
	string verticalString = "CEffect_Xom_Vert_";
	vector<int> horizontalIds;
	vector<int> verticalIds;
	int timerId, clearAnimation, particles;
	for (int i = 1; i <= 4; i++)
	{
		int tile;
		if (!OpU8a_lookup1(horizontalString + intToString(i),&tile))
			return;
		horizontalIds.push_back(tile);
		if (!OpU8a_lookup1(verticalString + intToString(i),&tile))
			return;
		verticalIds.push_back(tile);
	}
	if (!(OpU8a_lookup1("A_CEffect_Xom_Timer",&timerId) && OpU8a_lookup1("A_CEffect_Xom_Clear",&clearAnimation)))
		return;
	particles = 10;
	OpX5D_spawnBorderEffects(horizontalIds,verticalIds,timerId,clearAnimation,opX5D_cec078,particles);
	OpX5D_spawnBorderEffects(horizontalIds,verticalIds,timerId,clearAnimation,opX5D_cec07c,particles);
	OpX5D_spawnBorderEffects(horizontalIds,verticalIds,timerId,clearAnimation,opX5D_cec084,particles);
	OpX5D_spawnBorderEffects(horizontalIds,verticalIds,timerId,clearAnimation,opX5D_cec088,particles * 2);
	OpX5D_spawnBorderEffects(horizontalIds,verticalIds,timerId,clearAnimation,opX5D_cec08c,particles);
}

void OpX5D_Obj_cec138::unknown966ed0()
{
	unknowncc = opX5D_tickCount + 0x35c;
	unknownbc.push_back(new CEffect(this,Rect(0,0,opX5D_rex.unknown418980() - opX5D_cec074->getWidth(),opX5D_d01a20),0xb));
	opX5D_rex.getConsole_4ab670()->unknown429fe0(unknownbc.back(),Point(0,0),&Rect(0,0,opX5D_rex.unknown418980() - opX5D_cec074->getWidth(),opX5D_d01a20));
	unknownbc.back()->animate("A_CEffect_RIF");
	unknownbc.back()->animate("CEffect_Digits_Space");
	unknownbc.push_back(new CEffect(this,Rect(opX5D_cec074->getPos().x,0,opX5D_cec074->getWidth(),opX5D_rex.unknown4189a0()),0xb));
	opX5D_rex.getConsole_4ab670()->unknown429fe0(unknownbc.back(),Point(0,0),&Rect(opX5D_cec074->getPos().x,0,opX5D_cec074->getWidth(),opX5D_rex.unknown4189a0()));
	unknownbc.back()->animate("A_CEffect_RIF");
	unknownbc.back()->animate("CEffect_Digits_Space");
	unknownbc.push_back(new CEffect(this,Rect(opX5D_cec054->getPos().x,opX5D_cec054->getPos().y,opX5D_cec054->getWidth(),opX5D_cec054->getHeight()),0xc));
	opX5D_cec054->copyColorsTo(unknownbc.back(),Point(0,0),NULL);
	int digitsEffect, spaceEffect;
	OpU8a_lookup1("CEffect_Digits",&digitsEffect);
	OpU8a_lookup1("CEffect_Digits_Space",&spaceEffect);
	if (digitsEffect && spaceEffect)
	{
		CEffect *effect = unknownbc.back();
		OpX5_Array2D<bool> *map = opX5D_world->unknown4637f0();
		OpX5_Array2D<int> *mapped = opX5D_world->unknown463830();
		Pos min;
		Pos end;
		opX5D_cec054->unknown8051f0(&min,&end);
		for (int x = min.x, screenX = OpX5_maxInt(opX5D_cec054->unknown458ef0().x,0); x <= end.x && screenX < opX5D_screenWidth; x++, screenX++)
		{
			for (int y = min.y, cy = OpX5_maxInt(opX5D_cec054->unknown458ef0().y,0); y <= end.y && cy < opX5D_screenHeight; y++, cy++)
			{
				if (*map->at(x,y))
					effect->unknown48c460(digitsEffect,Point(screenX,cy));
				else
					effect->unknown48c460(spaceEffect,Point(screenX,cy));
			}
		}
	}
	int effectID;
	OpU8a_lookup2("Block_Turn_Progress_RIF",&effectID);
	opX5D_effectMgr->create()->init(opX5D_effectMgr,effectID,Point(0,0),Point(0,0),0,0,0,9,0);
	opR1d_4541b0(0x8c,0,0);
}

void OpX5D_Obj_cec138::unknown9675f0()
{
	opR1d_4541b0(0xcc,0,0);
	do
	{
		if (opX5D_messageLog.push(new OpS2_PhraseTextB(0x105,0,0,0,HEntity(),HEntity())))
			opX5D_cec058->unknown8758d0(true);
		opX5D_cec0b4->scrollToEnd();
	} while (0);
	unknowne0 = opX5D_tickCount + 0x960;
	unknownd0.push_back(new CEffect(this,Rect(0,0,opX5D_rex.unknown418980() - opX5D_cec074->getWidth(),opX5D_d01a20),0xd));
	opX5D_rex.getConsole_4ab670()->unknown429fe0(unknownd0.back(),Point(0,0),&Rect(0,0,opX5D_rex.unknown418980() - opX5D_cec074->getWidth(),opX5D_d01a20));
	unknownd0.back()->animate("A_CEffect_Reset");
	unknownd0.push_back(new CEffect(this,Rect(opX5D_cec074->getPos().x,0,opX5D_cec074->getWidth(),opX5D_rex.unknown4189a0()),0xd));
	opX5D_rex.getConsole_4ab670()->unknown429fe0(unknownd0.back(),Point(0,0),&Rect(opX5D_cec074->getPos().x,0,opX5D_cec074->getWidth(),opX5D_rex.unknown4189a0()));
	unknownd0.back()->animate("A_CEffect_Reset");
	unknownd0.push_back(new CEffect(this,Rect(opX5D_cec054->getPos().x,opX5D_cec054->getPos().y,opX5D_cec054->getWidth(),opX5D_cec054->getHeight()),0xe));
	opX5D_cec054->copyColorsTo(unknownd0.back(),Point(0,0),NULL);
	int resetEffect;
	OpU8a_lookup1("CEffect_Reset_Map",&resetEffect);
	if (resetEffect)
	{
		CEffect *effect = unknownd0.back();
		OpX5_Array2D<bool> *map = opX5D_world->unknown4637f0();
		OpX5_Array2D<int> *mapped = opX5D_world->unknown463830();
		Pos min;
		Pos end;
		opX5D_cec054->unknown8051f0(&min,&end);
		for (int x = min.x, screenX = OpX5_maxInt(opX5D_cec054->unknown458ef0().x,0); x <= end.x && screenX < opX5D_screenWidth; x++, screenX++)
		{
			for (int y = min.y, cy = OpX5_maxInt(opX5D_cec054->unknown458ef0().y,0); y <= end.y && cy < opX5D_screenHeight; y++, cy++)
			{
				if (*map->at(x,y))
					effect->unknown48c460(resetEffect,Point(screenX,cy));
			}
		}
	}
	int effectID;
	OpU8a_lookup2("Block_Turn_Progress_Reset",&effectID);
	opX5D_effectMgr->create()->init(opX5D_effectMgr,effectID,Point(0,0),Point(0,0),0,0,0,9,0);
}

void OpX5D_Obj_cec138::unknown967c90()
{
	opX5D_cec054->render();
	opR1d_4541b0(0xb3,0,0);
	do
	{
		if (opX5D_messageLog.push(new OpS2_PhraseTextB(0x2ad,0,0,0,HEntity(),HEntity())))
			opX5D_cec058->unknown8758d0(true);
		opX5D_cec0b4->scrollToEnd();
	} while (0);
	unknownf4 = opX5D_tickCount + 0xd48;
	unknowne4.push_back(new CEffect(this,Rect(0,0,opX5D_cec0b0->getWidth(),opX5D_d01a20),0xf));
	opX5D_rex.getConsole_4ab670()->unknown429fe0(unknowne4.back(),Point(0,0),&Rect(0,0,opX5D_cec0b0->getWidth(),opX5D_d01a20));
	unknowne4.back()->animate("A_CEffect_Imprint");
	unknowne4.push_back(new CEffect(this,Rect(opX5D_cec0c8->getPos().x,0,opX5D_cec0c8->getWidth(),opX5D_d01a20),0xf));
	opX5D_rex.getConsole_4ab670()->unknown429fe0(unknowne4.back(),Point(0,0),&Rect(opX5D_cec0c8->getPos().x,0,opX5D_cec0c8->getWidth(),opX5D_d01a20));
	unknowne4.back()->animate("A_CEffect_Imprint");
	unknowne4.push_back(new CEffect(this,Rect(opX5D_cec074->getPos().x,0,opX5D_cec074->getWidth(),opX5D_rex.unknown4189a0()),0xf));
	opX5D_rex.getConsole_4ab670()->unknown429fe0(unknowne4.back(),Point(0,0),&Rect(opX5D_cec074->getPos().x,0,opX5D_cec074->getWidth(),opX5D_rex.unknown4189a0()));
	unknowne4.back()->animate("A_CEffect_Imprint");
	unknowne4.push_back(new CEffect(this,Rect(opX5D_cec054->getPos().x,opX5D_cec054->getPos().y,opX5D_cec054->getWidth(),opX5D_cec054->getHeight()),0x10));
	opX5D_cec054->unknown429fe0(unknowne4.back(),Point(0,0),NULL);
	unknownf8 = -1;
	int effectID;
	OpU8a_lookup2("Block_Turn_Progress_Imprint",&effectID);
	opX5D_effectMgr->create()->init(opX5D_effectMgr,effectID,Point(0,0),Point(0,0),0,0,0,9,0);
}
