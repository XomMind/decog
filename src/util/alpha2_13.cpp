// alpha2_13: particle emitter spawn (0x5098e0): resolves where an emitter rule fires (anchor, offset,
//	random point, matching neighbour cells) and launches the rule's effect there.
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <vector>
#include "rng.h"
using std::vector;
extern RNG rng;

struct A2PColor
{
	unsigned char r, g, b;
	A2PColor(const A2PColor &other) throw();	// 0x411e30
	bool operator==(A2PColor other) throw();	// 0x411f40
};
struct A2PPoint
{
	int x;
	int y;
	A2PPoint() throw();	// 0x453b40
	A2PPoint(int value) throw();	// 0x409990
	A2PPoint(int x_, int y_) throw();	// 0x46ca20
	A2PPoint(const A2PPoint &other) throw();	// 0x46ca50
	A2PPoint(const A2PPoint &base, int dx, int dy) throw();	// 0x4099c0
	A2PPoint(const A2PPoint &base, const A2PPoint &delta) throw();	// 0x4099f0
	A2PPoint &operator=(const A2PPoint &other) throw();	// 0x46ca50
	A2PPoint subtract_409b30(const A2PPoint &other) const throw();
	bool equals_409b90(const A2PPoint &other) throw();
	bool differs_409bd0(const A2PPoint &other) throw();
	void set_40a010(int x_, int y_) throw();
	void set_40a060(const A2PPoint &base, int dx, int dy) throw();
	void add_40a2a0(int dx, int dy) throw();
	void scale_40a300(int factor) throw();
};
struct A2PStepper
{
	void getDelta_410490(A2PPoint &delta) throw();
};
struct A2PConsole
{
	bool inBounds_4173d0(const A2PPoint &p) throw();
	int getChar_417700(const A2PPoint &p) throw();
	A2PColor getBack_417750(const A2PPoint &p) throw();
	A2PPoint getAnchor_7b0290(int anchor);
	void emit_7ad6a0(int id, int anchor, int a, int dx, int dy);
};
struct A2PDef;
struct A2PEffect
{
	void init_50de10();
};
struct A2PEngine	// OpR2b_Engine
{
	A2PConsole *console;
	bool contains_454c20(const A2PPoint &p) throw();
	A2PEffect *create_50fb50(A2PEngine *engine, int id, const A2PPoint &pos, const A2PPoint *a, const A2PPoint *b, const A2PPoint *c, int layer);
	bool blocked_50fbf0(A2PDef *def, const A2PPoint &p) throw();
};
struct A2PCell
{
	bool unknown66b460() throw();
	bool unknown66b4b0() throw();
	bool unknown66b510() throw();
	bool unknown66b560() throw();
	bool unknown66b5b0() throw();
};
struct A2PGrid
{
	bool contains_9b43b0(const A2PPoint &p) throw();
	A2PCell **atPoint_9ced70(A2PPoint &p) throw();
};
struct A2PMapView
{
	const A2PPoint &offset_458ef0() throw();
};
struct A2PRule	// 0x48 bytes
{
	int id;	// +0x00
	char pad04[0x18 - 0x04];
	bool needsChar;	// +0x18
	char pad19[0x24 - 0x19];
	int anchor;	// +0x24
	int type;	// +0x28
	int dx;	// +0x2c
	int dy;	// +0x30
	int targetAnchor;	// +0x34
	int targetType;	// +0x38
	int tx;	// +0x3c
	int ty;	// +0x40
	bool ownLayer;	// +0x44
};

extern A2PGrid a2p_grid_cfd44c;
extern A2PMapView *a2p_mapView_cec054;
extern A2PColor &a2p_color_d20cfc;
extern A2PPoint a2p_none_cfbec0;
void a2p_rotate_501fc0(const A2PPoint &center, const A2PPoint &p, float angle, A2PPoint &out);

class A2PParticle
{
public:
	bool emit(const A2PRule &rule, A2PPoint pos);

	A2PDef *def;	// +0x00
	A2PEngine *engine;	// +0x04
	char pad08[0x10 - 0x08];
	A2PPoint origin;	// +0x10
	A2PPoint p18;	// +0x18
	A2PPoint p20;	// +0x20
	A2PPoint p28;	// +0x28
	char pad30[0x38 - 0x30];
	A2PStepper stepper;	// +0x38
	char pad39[0x68 - 0x39];
	A2PPoint p68;	// +0x68
	A2PPoint p70;	// +0x70
	int layer;	// +0x78
};

#define A2P_FULL(ADJ) adj = origin; ADJ; if (engine->console->inBounds_4173d0(adj) && engine->console->getChar_417700(adj) != ' ' && engine->console->getBack_417750(adj) == a2p_color_d20cfc && !engine->blocked_50fbf0(def,adj)) hits.push_back(adj);
#define A2P_CHAR(ADJ) adj = origin; ADJ; if (engine->console->inBounds_4173d0(adj) && engine->console->getChar_417700(adj) != ' ' && !engine->blocked_50fbf0(def,adj)) hits.push_back(adj);
#define A2P_ONE(ADJ) adj = origin; ADJ; if (engine->console->inBounds_4173d0(adj) && true && !engine->blocked_50fbf0(def,adj)) hits.push_back(adj);
#define A2P_CHANCECHAR(ADJ) adj = origin; ADJ; if (engine->console->inBounds_4173d0(adj) && rng.chance(rule.dx) && engine->console->getChar_417700(adj) != ' ' && !engine->blocked_50fbf0(def,adj)) hits.push_back(adj);
#define A2P_CHANCE(ADJ) adj = origin; ADJ; if (engine->console->inBounds_4173d0(adj) && rng.chance(rule.dx) && !engine->blocked_50fbf0(def,adj)) hits.push_back(adj);
#define A2P_CELL(ADJ,TEST) point = center; adj = origin; ADJ; if (a2p_grid_cfd44c.contains_9b43b0(point) && a2p_grid_cfd44c.atPoint_9ced70(point)[0]->TEST() && !engine->blocked_50fbf0(def,adj)) hits.push_back(adj);
#define A2P_CELLS(TEST) center = origin.subtract_409b30(a2p_mapView_cec054->offset_458ef0()); A2P_CELL(point.y -= 1; adj.y -= 1,TEST) A2P_CELL(point.y += 1; adj.y += 1,TEST) A2P_CELL(point.x -= 1; adj.x -= 1,TEST) A2P_CELL(point.x += 1; adj.x += 1,TEST)
#define A2P_DIAG(M) M(adj.x -= 1; adj.y -= 1) M(adj.x += 1; adj.y -= 1) M(adj.x -= 1; adj.y += 1) M(adj.x += 1; adj.y += 1)
#define A2P_ORTH(M) M(adj.y -= 1) M(adj.y += 1) M(adj.x -= 1) M(adj.x += 1)
#define A2P_LAYER (rule.ownLayer ? layer : 9)

bool A2PParticle::emit(const A2PRule &rule, A2PPoint pos)
{
	if (rule.anchor)
	{
		if (rule.anchor <= 47)
		{
			engine->console->emit_7ad6a0(rule.id,rule.anchor,0,rule.dx,rule.dy);
			return true;
		}
		pos = engine->console->getAnchor_7b0290(rule.anchor);
	}
	else
	{
		switch (rule.type)
		{
			case 0:
				break;
			case 1:
				pos.add_40a2a0(rule.dx,rule.dy);
				if (!engine->contains_454c20(pos))
					return false;
				break;
			case 2:
			{
				A2PPoint target;
				for (int i = 0; i < 25 && !engine->contains_454c20(target); i++)
					target.set_40a060(pos,rng.rangeInt(-rule.dx,rule.dx),rng.rangeInt(-rule.dy,rule.dy));
				if (!engine->contains_454c20(target))
					return false;
				pos = target;
				break;
			}
			case 3:
				pos.set_40a010(rule.dx,rule.dy);
				if (!engine->contains_454c20(pos))
					return false;
				break;
			default:
			{
				A2PPoint center;
				A2PPoint point;
				A2PPoint adj;
				vector<A2PPoint> hits;
				switch (rule.type)
				{
					case 4:
						A2P_DIAG(A2P_FULL)
					case 5:
						A2P_ORTH(A2P_FULL)
						break;
					case 6:
						if (rule.dy == 1)
						{
							A2P_DIAG(A2P_CHAR)
						}
						else
						{
							A2P_DIAG(A2P_ONE)
						}
					case 7:
						if (rule.dy == 1)
						{
							A2P_ORTH(A2P_CHAR)
						}
						else
						{
							A2P_ORTH(A2P_ONE)
						}
						break;
					case 8:
						if (rule.dy == 1)
						{
							A2P_DIAG(A2P_CHANCECHAR)
							A2P_ORTH(A2P_CHANCECHAR)
						}
						else
						{
							A2P_DIAG(A2P_CHANCE)
							A2P_ORTH(A2P_CHANCE)
						}
						break;
					case 9:
						A2P_CELLS(unknown66b460)
						break;
					case 10:
						A2P_CELLS(unknown66b4b0)
						break;
					case 11:
						A2P_CELLS(unknown66b510)
						break;
					case 12:
						A2P_CELLS(unknown66b560)
						break;
					case 13:
						A2P_CELLS(unknown66b5b0)
						break;
				}
				if (!hits.empty())
				{
					for (unsigned int i = 0; i < hits.size(); i++)
						engine->create_50fb50(engine,rule.id,hits[i],&p18,0,0,9)->init_50de10();
				}
				return !hits.empty();
			}
		}
	}
	if (rule.needsChar && engine->console->getChar_417700(pos) == ' ')
		return false;
	if (rule.targetAnchor)
	{
		A2PPoint anchor = engine->console->getAnchor_7b0290(rule.targetAnchor);
		anchor.add_40a2a0(rule.tx,rule.ty);
		if (pos.differs_409bd0(anchor))
			engine->create_50fb50(engine,rule.id,pos,&a2p_none_cfbec0,&anchor,&a2p_none_cfbec0,A2P_LAYER)->init_50de10();
	}
	else
	{
		switch (rule.targetType)
		{
			case 0:
				engine->create_50fb50(engine,rule.id,pos,&a2p_none_cfbec0,0,0,A2P_LAYER)->init_50de10();
				break;
			case 1:
				if (pos.differs_409bd0(p20))
					engine->create_50fb50(engine,rule.id,pos,&a2p_none_cfbec0,&p20,&p28,A2P_LAYER)->init_50de10();
				break;
			case 2:
				if (pos.differs_409bd0(p68))
					engine->create_50fb50(engine,rule.id,pos,&a2p_none_cfbec0,&p68,&p70,A2P_LAYER)->init_50de10();
				break;
			case 3:
			{
				A2PPoint target(pos,rule.tx,rule.ty);
				if (engine->contains_454c20(target) && pos.differs_409bd0(target))
					engine->create_50fb50(engine,rule.id,pos,&a2p_none_cfbec0,&target,&p70,A2P_LAYER)->init_50de10();
				break;
			}
			case 4:
				if (engine->contains_454c20(pos) && engine->contains_454c20(p68))
				{
					A2PPoint target(-1);
					for (int i = 0; i < 25 && (!engine->contains_454c20(target) || pos.equals_409b90(target)); i++)
						target.set_40a060(p68,rng.rangeInt(-rule.tx,rule.tx),rng.rangeInt(-rule.ty,rule.ty));
					if (engine->contains_454c20(target))
						engine->create_50fb50(engine,rule.id,pos,&a2p_none_cfbec0,&target,&p70,A2P_LAYER)->init_50de10();
				}
				break;
			case 5:
			case 6:
			{
				A2PPoint facing;
				stepper.getDelta_410490(facing);
				if (facing.x == 0 && facing.y == 0)
					break;
				facing.scale_40a300(5);
				A2PPoint front(pos,facing);
				A2PPoint node;
				int angle = rule.targetType == 5 ? rule.tx : rng.rangeInt(-rule.tx,rule.tx);
				if (angle < 0)
					angle = 360 - angle;
				a2p_rotate_501fc0(pos,front,angle,node);
				engine->create_50fb50(engine,rule.id,pos,&a2p_none_cfbec0,&node,&a2p_none_cfbec0,A2P_LAYER)->init_50de10();
				break;
			}
			case 7:
				engine->create_50fb50(engine,rule.id,pos,&a2p_none_cfbec0,&(rng.chance(50) ? A2PPoint(pos.x + (rng.chance(50) ? -100 : 100),pos.y) : A2PPoint(pos.x,pos.y + (rng.chance(50) ? -100 : 100))),&a2p_none_cfbec0,A2P_LAYER)->init_50de10();
				break;
			case 8:
			{
				A2PPoint target;
				do
				{
					target.x = rng.rangeInt(-100,100) + pos.x;
					target.y = rng.rangeInt(-100,100) + pos.y;
				}
				while (target.equals_409b90(pos));
				engine->create_50fb50(engine,rule.id,pos,&a2p_none_cfbec0,&target,&a2p_none_cfbec0,A2P_LAYER)->init_50de10();
				break;
			}
			case 9:
			{
				A2PPoint front(pos.x,pos.y - 100);
				A2PPoint node;
				int angle = rule.tx;
				a2p_rotate_501fc0(pos,front,angle,node);
				engine->create_50fb50(engine,rule.id,pos,&a2p_none_cfbec0,&node,&a2p_none_cfbec0,A2P_LAYER)->init_50de10();
				break;
			}
			case 10:
			{
				A2PPoint target(rule.tx,rule.ty);
				if (engine->contains_454c20(target) && pos.differs_409bd0(target))
					engine->create_50fb50(engine,rule.id,pos,&a2p_none_cfbec0,&target,&a2p_none_cfbec0,A2P_LAYER)->init_50de10();
				break;
			}
		}
	}
	return true;
}
