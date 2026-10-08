// team_c_68: civil war start (0x738b70): flags the civil war, clears props and robots tied to the old order,
//	powers down Triborg, re-colors and regroups the factions and sends the combatants at each other
// NOTE: names are placeholders; BS layout is partial
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908
struct XColor { unsigned char r; unsigned char g; unsigned char b; XColor(const XColor &c); XColor &operator=(XColor c); };
struct C68_Point { int x; int y; };	// NOTE: placeholder (Point)
struct C68_Pos { int x; int y; C68_Pos(int x_, int y_) throw(); };	// NOTE: placeholder (Pos)
struct C68_Rect { int x; int y; int w; int h; C68_Rect(); };	// NOTE: placeholder (Rect)
class C68_HEntity;
class C68_HProp { public: int ID; C68_HProp(); bool isValid() const; struct C68_Prop *operator->() const; };	// NOTE: placeholder (HProp)
struct C68_Prop { int unknown45c800(int a); bool unknown665be0(bool a); int getCachedSize(); int getHeight(); void unknown45ce10(int a, int b, bool c, C68_HProp p); };	// NOTE: placeholder names
struct C68_AI { void unknown459540(C68_Pos &p); void unknown459410(C68_Rect &area); void unknown459470(C68_Rect &area); void setCachedSize(int v); void setFollowEntity(C68_HEntity entity, int flag); };	// NOTE: placeholder names
struct C68_Entity	// NOTE: placeholder (Entity)
{
	bool unknown5c98c0(int a, int b, int c);
	bool isPlayer();
	int unknown45acb0(int a);
	void removeEffectsA(int a);
	void unknown5fd900(int a, int b);
	void unknown5dcc70(int a, int b);
	int getTarget();
	bool isXomCandidate();
	void *unknown45ac40(int a);
	C68_Point &getPosition();
	void setAI(C68_AI *ai);
	C68_AI *unknown45b590();
	int getFaction();
	void unknown45b340(C68_Pos *p);
};
class C68_HEntity { public: int ID; C68_HEntity(); C68_Entity *operator->() const; bool isValid() const; };	// NOTE: placeholder (HEntity)
class C68_NewAI { public: C68_NewAI(C68_HEntity entity, int a, int b); char data[0x130]; };	// NOTE: placeholder (0x57f6a0)
struct C68_Cell { C68_HProp getProp(); C68_HEntity getEntity(); };
struct C68_CellGrid { int getWidth(); int getHeight(); C68_Cell **at(int x, int y); C68_Rect getArea(); };
struct C68_Squad { char pad0[0x2c]; vector<XColor> colors; vector<C68_HEntity> *getMembers(); };	// NOTE: placeholder layout
class C68_HSquad { public: int ID; C68_Squad *get230() const; };	// NOTE: placeholder
struct C68_GameData { void setEntryText(const string &key, const string &value); };
struct C68_Audio { bool enabled; void unknown69e700(int id, int flag, float volume); };	// NOTE: placeholder (0xd25450)
void c68_message5141b0(int id, const string *a, const string *b, int c, C68_HProp prop, int d);	// NOTE: placeholder name (0x5141b0)
void opW5_message(int type, C68_HProp prop, const string &text, int value);	// NOTE: placeholder signature
void OpU8a_removeEntity(vector<C68_HProp> &v, C68_HProp p);	// NOTE: placeholder signature
void c68_removeEntity(vector<C68_HEntity> &v, C68_HEntity e);	// NOTE: placeholder name (OpU8a_removeEntity)
template <class T> void OpQ5_eraseStep(vector<T> &v, int &i);	// NOTE: placeholder name
template <class T> void OpV4c_shuffle(vector<T> &v);	// NOTE: placeholder name

extern C68_GameData c68_d1e860;	// NOTE: placeholder names below
extern C68_Audio c68_d25450;
extern C68_CellGrid c68_cfd44c;
extern int c68_cefbd0;
extern XColor *c68_cfe674;
extern XColor *c68_d35bbc;
extern vector<int> c68_d2f0f8;
extern int c68_d1eb40;

class BS	// NOTE: placeholder layout (partial)
{
public:
	char pad0[0x4c];
	vector<C68_HSquad> f4c;
	char pad5c[0x4f0 - 0x5c];
	vector<C68_HProp> f4f0;
	char pad500[0x66c - 0x500];
	C68_HEntity f66c;

	void removeEntity(C68_HEntity entity);
	C68_HEntity unknown715230(int group, int faction);
	bool unknown4631f0(C68_HEntity entity);
	void unknown74d560(int faction, int other, bool value, XColor color);
	void unknown6c65a0(C68_HEntity entity, const string &text, int a);
	void unknown465950(int x, int y, int value);
	void startCivilWar_738b70();
};

void BS::startCivilWar_738b70()
{
	c68_d1e860.setEntryText("scrCivilWar_g","1");
	do
	{
		c68_message5141b0(250,0,0,0,C68_HProp(),0);
	} while (0);
	if (c68_d25450.enabled)
		c68_d25450.unknown69e700(93,f66c->unknown5c98c0(0,66,0) != 0,0.0f);
	for (int distanceSq = 0; distanceSq < c68_cfd44c.getWidth(); distanceSq++)
	{
		for (int distances = 0; distances < c68_cfd44c.getHeight(); distances++)
		{
			if ((*c68_cfd44c.at(distanceSq,distances))->getProp().isValid() && !(*c68_cfd44c.at(distanceSq,distances))->getProp()->unknown45c800(135))
			{
				if ((*c68_cfd44c.at(distanceSq,distances))->getProp()->unknown665be0(true))
					OpU8a_removeEntity(f4f0,(*c68_cfd44c.at(distanceSq,distances))->getProp());
				if (!(*c68_cfd44c.at(distanceSq,distances))->getProp()->getCachedSize() && (*c68_cfd44c.at(distanceSq,distances))->getProp()->getHeight() == c68_cefbd0)
					(*c68_cfd44c.at(distanceSq,distances))->getProp()->unknown45ce10(0,0,true,C68_HProp());
			}
			if ((*c68_cfd44c.at(distanceSq,distances))->getEntity().isValid() && !(*c68_cfd44c.at(distanceSq,distances))->getEntity()->isPlayer() && !(*c68_cfd44c.at(distanceSq,distances))->getEntity()->unknown45acb0(135))
			{
				removeEntity((*c68_cfd44c.at(distanceSq,distances))->getEntity());
				(*c68_cfd44c.at(distanceSq,distances))->getEntity()->removeEffectsA(1);
			}
		}
	}
	C68_HEntity center = unknown715230(10,77);
	if (center.isValid())
	{
		center->unknown5fd900(6,0);
		if (unknown4631f0(center))
			opW5_message(800,C68_HProp(),string("Triborg suddenly powers down."),0);
		center->unknown5dcc70(14,0);
		unknown74d560(14,4,true,*c68_cfe674);
	}
	C68_HEntity adj = unknown715230(10,78);
	if (adj.isValid())
	{
		unknown6c65a0(adj,"SCR_Optimus_CW_Respond1",0);
		unknown6c65a0(adj,"SCR_Optimus_CW_Sees_Tri",0);
		adj->unknown45b590()->setFollowEntity(center,0);
	}
	unknown74d560(13,5,false,*c68_cfe674);
	unknown465950(13,14,1);
	unknown465950(13,4,1);
	for (int distanceSq = 1; distanceSq < 6; distanceSq++)
		f4c[13].get230()->colors[distanceSq] = *c68_d35bbc;
	vector<C68_HEntity> allies(*f4c[10].get230()->getMembers());
	c68_removeEntity(allies,adj);
	for (int distanceSq = 0; distanceSq < allies.size(); distanceSq++)
	{
		if (allies[distanceSq]->getTarget() >= 6)
		{
			allies[distanceSq]->unknown5dcc70(4,0);
			OpQ5_eraseStep(allies,distanceSq);
		}
	}
	C68_Pos col(38,3);
	C68_Pos cols(122,14);
	C68_Rect current = c68_cfd44c.getArea();
	for (int distanceSq = 0; distanceSq < allies.size(); distanceSq++)
	{
		if (!allies[distanceSq]->isXomCandidate())
		{
			if (allies[distanceSq]->unknown45ac40(137))
				allies[distanceSq]->unknown5dcc70(13,0);
			if (rng.chance(allies[distanceSq]->getPosition().x >= 75 ? 66 : 33))
				allies[distanceSq]->setAI((C68_AI *)new C68_NewAI(allies[distanceSq],26,0));
			else
			{
				allies[distanceSq]->setAI((C68_AI *)new C68_NewAI(allies[distanceSq],25,0));
				allies[distanceSq]->unknown45b590()->unknown459540(allies[distanceSq]->getPosition().x >= 75 ? cols : col);
			}
			OpQ5_eraseStep(allies,distanceSq);
		}
	}
	vector<C68_HEntity> begin;
	for (int distanceSq = 0; distanceSq < allies.size(); distanceSq++)
	{
		if (allies[distanceSq]->getFaction() == 45 || allies[distanceSq]->getFaction() == 78)
		{
			allies[distanceSq]->setAI((C68_AI *)new C68_NewAI(allies[distanceSq],3,14));
			allies[distanceSq]->unknown45b590()->unknown459410(current);
			allies[distanceSq]->unknown45b590()->setCachedSize(33);
			allies[distanceSq]->unknown45b340(new C68_Pos(c68_d2f0f8[138],1));
			if (allies[distanceSq]->getFaction() == 45 && allies[distanceSq]->getPosition().x >= 75)
				begin.push_back(allies[distanceSq]);
			OpQ5_eraseStep(allies,distanceSq);
		}
	}
	OpV4c_shuffle(begin);
	for (int distanceSq = 0; distanceSq < 2 && distanceSq < begin.size(); distanceSq++)
		begin[distanceSq]->unknown45b590()->setFollowEntity(adj,0);
	for (int distanceSq = 0; distanceSq < allies.size(); distanceSq++)
	{
		if (allies[distanceSq]->getFaction() == 38 && !allies[distanceSq]->unknown45ac40(136))
		{
			allies[distanceSq]->unknown5dcc70(13,0);
			allies[distanceSq]->unknown45b590()->setCachedSize(33);
			allies[distanceSq]->unknown45b340(new C68_Pos(c68_d2f0f8[138],1));
			OpQ5_eraseStep(allies,distanceSq);
		}
	}
	OpV4c_shuffle(allies);
	for (int distanceSq = (int)(allies.size() * 0.25); distanceSq < allies.size(); distanceSq++)
	{
		if (!allies[distanceSq]->unknown45ac40(136))
		{
			allies[distanceSq]->unknown5dcc70(13,0);
			allies[distanceSq]->setAI((C68_AI *)new C68_NewAI(allies[distanceSq],3,14));
			allies[distanceSq]->unknown45b590()->unknown459410(current);
			allies[distanceSq]->unknown45b590()->setCachedSize(33);
			allies[distanceSq]->unknown45b340(new C68_Pos(c68_d2f0f8[138],1));
			OpQ5_eraseStep(allies,distanceSq);
		}
	}
	for (unsigned int distanceSq = 0; distanceSq < allies.size(); distanceSq++)
	{
		allies[distanceSq]->unknown45b590()->unknown459470(current);
		allies[distanceSq]->unknown45b590()->setCachedSize(33);
		allies[distanceSq]->unknown45b340(new C68_Pos(c68_d2f0f8[138],1));
	}
	for (int distanceSq = 0; distanceSq < 2; distanceSq++)
	{
		vector<C68_HEntity> *distances = f4c[distanceSq].get230()->getMembers();
		for (unsigned int enemies = 0; enemies < distances->size(); enemies++)
		{
			if ((*distances)[enemies]->isXomCandidate())
				c68_d1eb40++;
		}
	}
}
