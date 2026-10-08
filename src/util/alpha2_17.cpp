// alpha2_17: particle effect update (0x5045f0): advances an effect (projectile/beam particle) along its
//	path, handling impacts against cells, props and robots, explosions, deflection and glyph animation.
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <vector>
#include <cmath>
#include <cctype>
#include "rng.h"
using std::vector;
extern RNG rng;

struct A2UEntity;
struct A2UProp;
struct A2UPoint
{
	int x;
	int y;
	A2UPoint() throw();	// 0x453b40
	A2UPoint(int x_, int y_) throw();	// 0x46ca20
	A2UPoint(const A2UPoint &other) throw();	// 0x46ca50
	void assign_46ca50(const A2UPoint &other) throw();
	bool same_409b90(const A2UPoint &other) const throw();
	bool differs_409bd0(const A2UPoint &other) const throw();
};
struct A2UFloatPair
{
	float x;
	float y;
	A2UFloatPair() throw();	// 0x40a6b0
};
struct A2UPointPair
{
	A2UPoint first;
	A2UPoint second;
};
struct A2UStepper
{
	bool next_410420(A2UPoint &pos, A2UPoint &sub);
	void init_4103b0(const A2UPoint &a, const A2UPoint &b, const A2UPoint &c, const A2UPoint &d, int e);
	char data[0x30];
};
struct A2UColor
{
	unsigned char r, g, b;
};
struct A2UHE	// HEntity
{
	int id;
	A2UEntity *get_9b6570() const throw();
	bool isValid_9b7230() const throw();
	bool isNull_9b65d0() const throw();
	void reset_9b7270() throw();
};
struct A2UHP	// HProp
{
	int id;
	A2UProp *get_9b64f0() const throw();
	bool isValid_9b7230() const throw();
};
struct A2UHI
{
	int id;
	bool isValid_9b7230() const throw();
};
struct A2UCounter
{
	void unknown658a30();
};
struct A2UHC
{
	int id;
	A2UCounter *get_9b64d0() const throw();
};
struct A2UHR
{
	int id;
};
struct A2UView
{
	const int *getConst_9cfeb0(A2UPoint *p);
};
struct A2UWeapon
{
	char pad0[0x194];
	int x194;	// +0x194
	char pad198[0x19c - 0x198];
	int x19c;	// +0x19c
	int x1a0;	// +0x1a0
	bool x1a4;	// +0x1a4
};
struct A2USource
{
	char pad0[0x0c];
	A2UHE entity;	// +0x0c
};
struct A2UExtra
{
	int x0;	// +0x00
	A2UWeapon *weapon;	// +0x04
	A2UHE owner;	// +0x08
	A2UView *view;	// +0x0c
	int range;	// +0x10
	int travelled;	// +0x14
	float x18;	// +0x18
	A2UHI x1c;	// +0x1c
	A2UHI item;	// +0x20
	int x24;	// +0x24
	A2UHC counter;	// +0x28
	vector<A2UPointPair> waypoints;	// +0x2c
	vector<int> targets;	// +0x3c
	vector<A2UPoint> hits;	// +0x4c
	int x5c;	// +0x5c
	A2USource *source;	// +0x60
};
struct A2UData
{
	char pad0[0x20];
	int kind;	// +0x20
	int durationMode;	// +0x24
	char pad28[0x30 - 0x28];
	int speedMode;	// +0x30
	int speed;	// +0x34
	float speedRange;	// +0x38
	char pad3c[0x45 - 0x3c];
	bool solid;	// +0x45
	char pad46[0x48 - 0x46];
	int glyphMode;	// +0x48
	vector<int> glyphs;	// +0x4c
	unsigned int period;	// +0x5c
	bool marks;	// +0x60
	char pad61[0x68 - 0x61];
	A2UColor color;	// +0x68
	char pad6b[0xb8 - 0x6b];
	vector<int> spawns;	// +0xb8
	vector<int> sounds;	// +0xc8
};
struct A2UEffect;
struct A2UPool
{
	A2UEffect *alloc_508610();
	char pad0[0x24];
	vector<int> effects;	// +0x24
};
struct A2UEntity
{
	int unknown45a320();
	bool unknown5ddac0(const A2UPoint &p, int a);
	bool unknown637da0(int a, int b, A2UWeapon *weapon, const A2UPoint *p);
	bool deflect_637f00(A2UWeapon *weapon, const A2UPoint &from, const A2UPoint &at, A2UPoint &to);
	void projectileImpact_5f1010(A2UHE owner, A2UView *view, int a, A2UWeapon *weapon, float b, const A2UPoint &from, int c, int d, int e);
};
struct A2UProp
{
	int getNestedField_45c5f0();
	void damage_664840(A2UHE owner, A2UView *view, int a, A2UWeapon *weapon, float b, int c, int d, int e);
	bool unknown6658d0(int a, int b, A2UWeapon *weapon);
};
struct A2UCell
{
	A2UHE getEntity_45d250();
	bool unknown45d2d0();
	bool unknown45d480();
	bool unknown45d500();
	A2UHP getProp_45d550();
	void unknown45dec0(bool flag);
	void unknown66b690(int glyph, const A2UColor &color);
	void unknown66e650(A2UHE owner, A2UView *view, int a, A2UWeapon *weapon, float b, int c);
	void blast_66eff0(A2UHE owner, A2UWeapon *weapon, int a, const A2UPoint &from, int b, int c);
	bool unknown6701c0(int a, int b, A2UWeapon *weapon);
};
struct A2UGrid
{
	A2UCell **atPoint_9ced70(A2UPoint &p) throw();
	bool contains_9b43b0(const A2UPoint &p) throw();
};
struct A2UMarks
{
	bool &operator()(const A2UPoint &p);	// 0x9d2770
	int data[3];
};
struct A2UExplosion
{
	A2UExplosion(A2UHE owner, int a, const A2UPoint &p, A2UHC counter, const A2UPoint &from, const A2UPoint &at);	// 0x515ca0
	int data[0x40 / 4];
};
struct A2UFactory
{
	A2UHR createA_7930e0(A2UExplosion *x);
};
struct A2UMap
{
	bool isVisible_4631c0(const A2UPoint &p);
	bool unknown717ce0(A2UHE entity, int a);
	void addBuffer_465410(A2UHE entity, int a);
	A2UHR addRecord_777a20(A2UHR record);
	bool unknown7278e0(A2UHE owner, A2UWeapon *weapon, const A2UPoint &p);
	void thrownItemArrived_7499f0(A2UHE owner, A2UHI item, int a, const A2UPoint &p, int b);
	void impact_749ee0(A2UHE owner, A2USource *source, const A2UPoint &p, int a);
	void response_74da60(A2UHE owner, A2UWeapon *weapon, const A2UPoint &p);
};

extern A2UMap *a2u_map_cefc4c;
extern A2UGrid a2u_grid_cfd44c;
extern A2UFactory *a2u_factory_cefaa8;
extern unsigned int a2u_clock_caed20;
extern unsigned int a2u_delta_cefa78;
extern bool a2u_mute_d28cbc;
extern A2UMarks a2u_marks_d201c8[];
extern const A2UPoint a2u_none_d2e20c;
struct A2UText;
extern const A2UText a2u_chars_d2022c, a2u_chars_d32974, a2u_chars_d01f04;
extern int a2u_digits_bb9340[];

void a2u_clampMin_9d5b10(float *value, float low);
void a2u_eraseValue_9d5b30(vector<int> &list, int value);
bool a2u_contains_9d0ce0(vector<A2UPoint> &list, A2UPoint p);
void a2u_removeAt_9de6f0(vector<int> &list, int index);
void a2u_eraseAt_9d9f80(vector<A2UPointPair> &list, int index);
int a2u_distanceCeil_40a3f0(const A2UPoint &a, const A2UPoint &b);
float a2u_angle_40a680(const A2UPoint &a, const A2UPoint &b);
void a2u_pointAlongLine_4066e0(float x0, float y0, float x1, float y1, float distance, float *x, float *y);
int a2u_randomRec_9d5d00(vector<int> &list);
char a2u_randomChar_4085b0(const A2UText &chars);
int a2u_randomOf_9d9c10(int *list, unsigned int count);


#define A2U_SPAWN(N,P) do{if(!data->spawns.empty())spawn_5031d0(N,P);}while(false)
#define A2U_SOUND(N) do{if(!data->sounds.empty()&&!a2u_mute_d28cbc)sound_503930(N);}while(false)
#define A2U_FINISH(E) do{if(E)A2U_SPAWN(7,origin);A2U_SPAWN(8,origin);A2U_SOUND(5);start=0;if(data->marks&&a2u_grid_cfd44c.contains_9b43b0(origin))(*a2u_grid_cfd44c.atPoint_9ced70(origin))->unknown66b690(glyph,data->color);return true;}while(false)
#define A2U_IMPACT(E,P) do{\
	if(E)\
	{\
		if(extra->weapon&&extra->weapon->x1a0)\
		{\
			a2u_map_cefc4c->addRecord_777a20(a2u_factory_cefaa8->createA_7930e0(new A2UExplosion(extra->owner,extra->weapon->x1a0,P,extra->counter,point20,origin)));\
			A2U_SPAWN(7,P);\
		}\
		else\
		{\
			if(extra->counter.get_9b64d0())extra->counter.get_9b64d0()->unknown658a30();\
			A2U_SPAWN(7,origin);\
		}\
	}\
	else\
	{\
		if(extra->counter.get_9b64d0())extra->counter.get_9b64d0()->unknown658a30();\
	}\
	if(extra->item.isValid_9b7230())a2u_map_cefc4c->thrownItemArrived_7499f0(extra->owner,extra->item,extra->x24,P,extra->x5c);\
	if(extra->source)a2u_map_cefc4c->impact_749ee0(extra->owner,extra->source,P,0);\
	if(extra->weapon&&extra->weapon->x1a4)a2u_map_cefc4c->response_74da60(extra->owner,extra->weapon,P);\
	a2u_eraseValue_9d5b30(owner->effects,(int)this);\
	A2U_FINISH(E);\
}while(false)

struct A2UEffect
{
	bool update();
	void spawn_5031d0(int trigger, const A2UPoint &pos);
	void sound_503930(int trigger);
	void init_503b20(A2UPool *pool, int record, const A2UPoint &p, const A2UPoint &off, const A2UPoint *to, const A2UPoint *toOff, int owned, int kind, A2UEffect *parent);

	A2UData *data;	// +0x00
	A2UPool *owner;	// +0x04
	unsigned int start;	// +0x08
	unsigned int end;	// +0x0c
	A2UPoint origin;	// +0x10
	A2UPoint offset;	// +0x18
	A2UPoint point20;	// +0x20
	A2UPoint point28;	// +0x28
	float speed;	// +0x30
	float delay;	// +0x34
	A2UStepper stepper;	// +0x38
	A2UPoint point68;	// +0x68
	A2UPoint point70;	// +0x70
	int steps;	// +0x78
	int hitId;	// +0x7c
	int hitType;	// +0x80
	int field84;	// +0x84
	int glyph;	// +0x88
	unsigned int frame;	// +0x8c
	A2UColor color;	// +0x90
	vector<int> spawns;	// +0x94
	vector<int> sounds;	// +0xa4
	A2UExtra *extra;	// +0xb4
};

bool A2UEffect::update()
{
	if (start == 0)
		return false;
	if (end != 0 && a2u_clock_caed20 >= end && (data->durationMode != 4 || !origin.differs_409bd0(point68)))
		A2U_FINISH(0);
	A2U_SPAWN(0,origin);
	A2U_SPAWN(1,origin);
	A2U_SPAWN(2,origin);
	A2U_SOUND(2);
	A2U_SOUND(3);
	A2U_SOUND(4);
	if (data->kind == 2 && origin.same_409b90(point68))
	{
		(*a2u_grid_cfd44c.atPoint_9ced70(origin))->blast_66eff0(extra->owner,extra->weapon,extra->x0,point20,*extra->view->getConst_9cfeb0(&origin),0);
		A2U_FINISH(0);
	}
	switch (data->speedMode)
	{
		break;
		case 2:
			speed = data->speed + data->speedRange * (a2u_clock_caed20 - start);
			a2u_clampMin_9d5b10(&speed,15.0f);
			break;
		case 3:
			speed += rng.rangeFloat(0.0f,data->speedRange);
			a2u_clampMin_9d5b10(&speed,15.0f);
			break;
		case 4:
			speed = data->speed + sin((float)((a2u_clock_caed20 - start) / (double)(end - start) * 1.5707964f)) * (data->speedRange - data->speed);
			a2u_clampMin_9d5b10(&speed,15.0f);
			break;
	}
	if (speed != 0.0f)
	{
		delay += a2u_delta_cefa78;
		while (delay >= speed)
		{
			A2UPoint p;
			for (int i = 0; i < 9; i++)
			{
				p.assign_46ca50(origin);
				steps++;
				if (stepper.next_410420(origin,offset) || !a2u_grid_cfd44c.contains_9b43b0(origin))
				{
					if (data->solid)
					{
						switch (data->kind)
						{
							case 1:
								A2U_IMPACT(0,p);
							default:
								A2U_FINISH(0);
						}
					}
					else
						A2U_FINISH(0);
				}
				if (p.differs_409bd0(origin))
				{
					A2U_SPAWN(5,p);
					A2U_SPAWN(4,origin);
					switch (data->kind)
					{
						break;
						case 1:
							if ((!extra->weapon || extra->x1c.isValid_9b7230()) && p.same_409b90(point68) && extra->waypoints.empty())
							{
								origin.assign_46ca50(p);
								A2U_IMPACT(1,p);
							}
							if (extra->source)
							{
								if (p.same_409b90(point68))
								{
									origin.assign_46ca50(p);
									A2U_IMPACT(1,p);
								}
								else if (extra->source->entity.get_9b6570() && (*a2u_grid_cfd44c.atPoint_9ced70(origin))->getEntity_45d250().isNull_9b65d0())
									extra->source->entity.get_9b6570()->unknown5ddac0(origin,0);
							}
							break;
						case 2:
							if (origin.same_409b90(point68))
							{
								(*a2u_grid_cfd44c.atPoint_9ced70(origin))->blast_66eff0(extra->owner,extra->weapon,extra->x0,point20,*extra->view->getConst_9cfeb0(&origin),0);
								A2U_FINISH(0);
							}
							break;
					}
					steps = 1;
				}
				if (data->kind == 1 && !extra->waypoints.empty() && origin.same_409b90(point68) && offset.same_409b90(point70))
				{
					point68.assign_46ca50(extra->waypoints.front().first);
					point70.assign_46ca50(extra->waypoints.front().second);
					stepper.init_4103b0(origin,offset,point68,point70,9);
					if (data->glyphMode == 2)
					{
						float first = a2u_angle_40a680(origin,point68);
						int count = first >= 337.5 ? 0 : (int)((first / 22.5 + 1.0) / 2.0);
						glyph = data->glyphs[count];
					}
					extra->travelled += a2u_distanceCeil_40a3f0(point20,origin);
					point20.assign_46ca50(origin);
					a2u_eraseAt_9d9f80(extra->waypoints,0);
					A2U_SPAWN(6,origin);
					A2U_SOUND(1);
				}
				if (data->solid && origin.differs_409bd0(point20))
				{
					if (data->kind != 1 || !a2u_contains_9d0ce0(extra->hits,origin))
					{
						if (p.differs_409bd0(origin))
						{
							hitType = 0;
							if ((*a2u_grid_cfd44c.atPoint_9ced70(origin))->unknown45d480() || data->kind == 1 && extra->travelled + a2u_distanceCeil_40a3f0(point20,origin) > extra->range)
							{
								switch (data->kind)
								{
									case 1:
									{
										bool stop = false;
										if (extra->weapon)
										{
											if ((*a2u_grid_cfd44c.atPoint_9ced70(origin))->unknown45d500())
											{
												stop = !extra->targets.empty() && (*a2u_grid_cfd44c.atPoint_9ced70(origin))->getProp_45d550().get_9b64f0()->unknown6658d0(-1,extra->targets.front(),extra->weapon);
												(*a2u_grid_cfd44c.atPoint_9ced70(origin))->getProp_45d550().get_9b64f0()->damage_664840(extra->owner,extra->view,extra->x5c,extra->weapon,extra->x18,0,0,0);
											}
											else
											{
												stop = extra->travelled + a2u_distanceCeil_40a3f0(point20,origin) <= extra->range && !extra->targets.empty() && (*a2u_grid_cfd44c.atPoint_9ced70(origin))->unknown6701c0(-1,extra->targets.front(),extra->weapon);
												(*a2u_grid_cfd44c.atPoint_9ced70(origin))->unknown66e650(extra->owner,extra->view,extra->x5c,extra->weapon,extra->x18,0);
											}
										}
										if (!stop)
											A2U_IMPACT(1,p);
										else
										{
											if (extra->targets.front() != -1)
												a2u_removeAt_9de6f0(extra->targets,0);
											extra->hits.push_back(origin);
											if (extra->weapon->x194)
											{
												A2UFloatPair at;
												a2u_pointAlongLine_4066e0(point20.x,point20.y,origin.x,origin.y,50.0f,&at.x,&at.y);
												owner->alloc_508610()->init_503b20(owner,extra->weapon->x194,origin,offset,&A2UPoint((int)at.x,(int)at.y),&offset,0,9,this);
											}
										}
										break;
									}
									default:
										A2U_FINISH(1);
								}
							}
							else if ((*a2u_grid_cfd44c.atPoint_9ced70(origin))->getEntity_45d250().isValid_9b7230())
							{
								hitId = (*a2u_grid_cfd44c.atPoint_9ced70(origin))->getEntity_45d250().get_9b6570()->unknown45a320();
								hitType = 4;
							}
							else if ((*a2u_grid_cfd44c.atPoint_9ced70(origin))->getProp_45d550().isValid_9b7230() && (*a2u_grid_cfd44c.atPoint_9ced70(origin))->getProp_45d550().get_9b64f0()->getNestedField_45c5f0())
							{
								hitId = (*a2u_grid_cfd44c.atPoint_9ced70(origin))->getProp_45d550().get_9b64f0()->getNestedField_45c5f0();
								hitType = 2;
							}
							else if (data->kind == 1 && (*a2u_grid_cfd44c.atPoint_9ced70(origin))->unknown45d2d0())
								(*a2u_grid_cfd44c.atPoint_9ced70(origin))->unknown45dec0(false);
							p.assign_46ca50(origin);
							if (data->kind == 1 && extra->weapon && extra->weapon->x19c && a2u_map_cefc4c->isVisible_4631c0(origin) && extra->owner.get_9b6570() && a2u_map_cefc4c->unknown7278e0(extra->owner,extra->weapon,origin))
							{
								do
								{
									if (extra->counter.get_9b64d0())
										extra->counter.get_9b64d0()->unknown658a30();
									a2u_eraseValue_9d5b30(owner->effects,(int)this);
									start = 0;
									return true;
								}
								while (false);
							}
						}
						if (hitType && a2u_marks_d201c8[hitId](offset))
						{
							switch (data->kind)
							{
								case 1:
									if (extra->weapon)
									{
										bool stop = false;
										switch (hitType)
										{
											case 4:
												if ((*a2u_grid_cfd44c.atPoint_9ced70(origin))->getEntity_45d250().isValid_9b7230())
												{
													stop = !extra->targets.empty() && (*a2u_grid_cfd44c.atPoint_9ced70(origin))->getEntity_45d250().get_9b6570()->unknown637da0(-1,extra->targets.front(),extra->weapon,&origin);
													if (!a2u_map_cefc4c->unknown717ce0((*a2u_grid_cfd44c.atPoint_9ced70(origin))->getEntity_45d250(),extra->x0))
													{
														a2u_map_cefc4c->addBuffer_465410((*a2u_grid_cfd44c.atPoint_9ced70(origin))->getEntity_45d250(),extra->x0);
														if (!stop && (*a2u_grid_cfd44c.atPoint_9ced70(origin))->getEntity_45d250().get_9b6570()->deflect_637f00(extra->weapon,point20,origin,point68))
														{
															point70.assign_46ca50(a2u_none_d2e20c);
															stepper.init_4103b0(origin,offset,point68,point70,9);
															extra->travelled += a2u_distanceCeil_40a3f0(point20,origin);
															point20.assign_46ca50(origin);
															if (data->glyphMode == 2)
															{
																float first = a2u_angle_40a680(origin,point68);
																int count = first >= 337.5 ? 0 : (int)((first / 22.5 + 1.0) / 2.0);
																glyph = data->glyphs[count];
															}
															extra->owner.reset_9b7270();
															break;
														}
														else
															(*a2u_grid_cfd44c.atPoint_9ced70(origin))->getEntity_45d250().get_9b6570()->projectileImpact_5f1010(extra->owner,extra->view,extra->x5c,extra->weapon,extra->x18,point20,0,0,0);
													}
													if (!stop)
														A2U_IMPACT(1,origin);
												}
												else
													hitType = 0;
												break;
											case 2:
												if ((*a2u_grid_cfd44c.atPoint_9ced70(origin))->getProp_45d550().isValid_9b7230())
												{
													stop = !extra->targets.empty() && (*a2u_grid_cfd44c.atPoint_9ced70(origin))->getProp_45d550().get_9b64f0()->unknown6658d0(-1,extra->targets.front(),extra->weapon);
													(*a2u_grid_cfd44c.atPoint_9ced70(origin))->getProp_45d550().get_9b64f0()->damage_664840(extra->owner,extra->view,extra->x5c,extra->weapon,extra->x18,0,0,0);
													if (!stop)
														A2U_IMPACT(1,origin);
												}
												else
													hitType = 0;
										}
										if (stop)
										{
											if (extra->targets.front() != -1)
												a2u_removeAt_9de6f0(extra->targets,0);
											extra->hits.push_back(origin);
											if (extra->weapon->x194)
											{
												A2UFloatPair at;
												a2u_pointAlongLine_4066e0(point20.x,point20.y,origin.x,origin.y,50.0f,&at.x,&at.y);
												owner->alloc_508610()->init_503b20(owner,extra->weapon->x194,origin,offset,&A2UPoint((int)at.x,(int)at.y),&offset,0,9,this);
											}
										}
									}
									break;
								default:
									A2U_FINISH(1);
							}
						}
					}
				}
			}
			delay -= speed;
		}
		if (delay < 0.0)
			return false;
	}
	if (data->glyphMode >= 13)
	{
		if (data->glyphMode == 13)
			glyph = data->glyphs[(a2u_clock_caed20 - start) / data->period % data->glyphs.size()];
		else
		{
			frame += (double)a2u_delta_cefa78;
			if (frame >= data->period)
			{
				switch (data->glyphMode)
				{
					case 14:
						glyph = a2u_randomRec_9d5d00(data->glyphs);
						break;
					case 15:
						glyph = a2u_randomChar_4085b0(a2u_chars_d2022c);
						break;
					case 16:
						glyph = a2u_randomOf_9d9c10(a2u_digits_bb9340,10);
						break;
					case 17:
						glyph = a2u_randomChar_4085b0(a2u_chars_d32974);
						break;
					case 18:
						glyph = a2u_randomChar_4085b0(a2u_chars_d32974);
						if (islower(glyph))
							glyph = toupper(glyph);
						break;
					case 19:
						glyph = a2u_randomChar_4085b0(a2u_chars_d01f04);
						break;
				}
				frame -= data->period;
			}
			while (frame >= data->period)
				frame -= data->period;
		}
	}
	return false;
}
