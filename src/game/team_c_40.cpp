// team_c_40: scoresheet player-state snapshot (0x483d30): core stats, sorted inventory, slot part names,
//	carried items, and a 50x50 ASCII map around the player (called from 0x4852a0 and Entity::die)
// NOTE: member names are placeholders (f<offset>); helper classes and globals are private placeholders
#include <string>
#include <vector>
using namespace std;

int OpX5_minInt(int a, int b);
int OpX5_maxInt(int a, int b);
bool OpX5_containsRecord(vector<int> &v, int value);	// NOTE: placeholder name
bool OpS8b_Fn9d43b0(int *values, unsigned int count, int value);	// NOTE: placeholder name
template <class T> void OpQ5_moveElement(vector<T> &v, unsigned int from, unsigned int to);	// NOTE: placeholder name

struct C40_Entity;
struct C40_Item;
struct C40_Prop;
class HEntity { public: int ID; HEntity(); C40_Entity *operator->() const; bool isValid() const; };	// NOTE: placeholder layout
class C40_HItem { public: int ID; C40_HItem(); C40_Item *operator->() const; };	// NOTE: placeholder (HItem)
class C40_HProp { public: int ID; C40_HProp(); C40_Prop *operator->() const; };	// NOTE: placeholder (HProp)
struct C40_Point { int x; int y; C40_Point(); C40_Point(int x_, int y_); C40_Point(const C40_Point &o); C40_Point &operator=(const C40_Point &o); void set(int x_, int y_); };	// NOTE: placeholder (Point/Pos)
template <class T> struct C40_Grid { int width; int height; T *cells; T *at(int x, int y); void resize(int w, int h, void *stream); void fill(int value); int getWidth(); int getHeight(); };	// NOTE: placeholder (Array2D)
struct C40_S14 { int f0; char pad4[0x10]; bool isActive(); int getValue(int a); };	// NOTE: placeholder
struct C40_S34 { int f0; int f4; char pad8[8]; int f10; char pad14[0x34 - 0x14]; };	// NOTE: placeholder
struct C40_PropDef { char pad0[0xf8]; int ff8; };	// NOTE: placeholder
struct C40_Prop { int unknown44ab40(); C40_PropDef *get9b8f00(); bool unknown45cb10(); int unknown457b10(); int unknown44a630(); };	// NOTE: placeholder names
struct C40_Item { int getNestedField(); int getType(); string unknown573860(bool full, int *length); int unknown573c90(string &name); void *getEffect(int type); int unknown5745d0(string &name); int unknown4578c0(); int unknown457ab0(); };	// NOTE: placeholder names
struct C40_Entity { int getField(); int unknown45a920(); int unknown5ca670(); int unknown45a8d0(); int unknown5ca400(); int unknown5cab90(); int unknown5ca840(); int unknown45a990(); int unknown5cad50(); int unknown5d1390(); int unknown5d15a0(int a); int unknown5c8cb0(); int unknown5d1ee0(); int unknown5c8d40(int a, int b); vector<C40_HItem> *getInventoryList(); int *unknown45a840(); int unknown5c92a0(int slot); int unknown5c92c0(C40_HItem item); int unknown5cccc0(); int unknown5ca210(); C40_Point &getPosition(); int getAsciiDefault(); };	// NOTE: placeholder names
struct C40_Cell { HEntity getEntity(); bool unknown45d700(); C40_HItem getItem(); bool unknown45d1e0(); C40_HProp getProp(); bool unknown45db70(); bool isEdge(); bool unknown45dbb0(); bool isMachinePart(); int get9b8f00(); bool unknown45d270(); bool unknown45dc70(); bool unknown45d4e0(); };	// NOTE: placeholder names
struct C40_World { char pad0[0x674]; C40_Grid<bool> f674; char pad680[0x69c - 0x680]; C40_Grid<int> f69c; char pad6a8[0x740 - 0x6a8]; C40_Grid<C40_S14> f740; int f74c; char pad750[0x7c4 - 0x750]; C40_Grid<C40_S34> f7c4; bool unknown463e90(const C40_Point &p); };	// NOTE: placeholder layout
struct C40_Big { char pad0[0xba0984]; bool fba0984; };	// NOTE: placeholder
struct C40_Terrain { int ID; };
struct C40_GameData { C40_Point unknown46f500(); };
struct C40_Stats { bool add4729d0(unsigned int id, int value, string text, int extra); };	// NOTE: placeholder (OpR1h_Stats)

extern int c40_cf4954, c40_cf49f4, c40_cf49fc, c40_cf4b38, c40_caf164;	// NOTE: placeholder names below
extern bool c40_cf49f0, c40_d28d30;
extern C40_Big *c40_cefb38;
extern C40_GameData c40_d1e860;
extern vector<int> c40_cf4830;
extern C40_Stats c40_d2c658;
extern C40_Terrain *c40_cefbb0, *c40_cefba8, *c40_cefbac;
extern C40_World *c40_cefc4c;
extern C40_Grid<C40_Cell *> c40_cfd44c;
extern C40_Grid<int> originalTerrain;	// 0xd378c0 (globals.csv)
extern C40_PropDef *c40_cefbd8;
extern int c40_ba69e0[];
extern const char c40_b99c08[];
extern const char c40_empty_b9017e[], c40_empty_b9017f[];

struct C38_Snapshot	// NOTE: placeholder layout (scoresheet player block)
{
	int f0;
	int f4;
	int f8;
	int fc;
	int f10;
	int f14;
	int f18;
	bool f1c;
	int f20;
	int f24;
	bool f28;
	int f2c;
	int f30;
	int f34;
	int f38;
	C40_Point f3c;
	vector<int> f44;
	vector<int> f54;
	vector< vector<string> > f64;
	vector< vector<int> > f74;
	vector< vector<int> > f84;
	int f94;
	int f98;
	vector<string> f9c;
	vector<int> fac;
	C40_Grid<int> fbc;

	void unknown483d30(HEntity player, bool isDump);
};

void C38_Snapshot::unknown483d30(HEntity player, bool isDump)
{
	int amount;
	C40_Cell *ally;
	f0 = player->getField();
	f4 = c40_cf4954;
	f8 = player->unknown45a920();
	fc = player->unknown5ca670();
	f10 = player->unknown45a8d0();
	f14 = player->unknown5ca400();
	f18 = player->unknown5cab90();
	f1c = c40_cf49f0;
	f20 = player->unknown5ca840();
	f24 = player->unknown45a990();
	f28 = c40_cf49f4 != 0;
	if (player->unknown5cad50() && c40_cefb38->fba0984)
	{
		f2c = 5;
		f30 = 0;
	}
	else
	{
		f2c = player->unknown5d1390();
		f30 = player->unknown5d15a0(0);
	}
	f34 = c40_cf49fc;
	int a1 = player->unknown5c8cb0();
	int allies = player->unknown5d1ee0();
	if (a1 > allies)
		f38 = player->unknown5c8d40(a1,allies);
	else
		f38 = 0;
	if (c40_cf4b38 <= 9)
		f3c.set(c40_cf4b38,39);
	else
		f3c = c40_d1e860.unknown46f500();
	vector<C40_HItem> *areas = player->getInventoryList();
	for (unsigned int distanceSq = 1; distanceSq < areas->size(); distanceSq++)
	{
		if ((*areas)[distanceSq]->getNestedField() < (*areas)[distanceSq - 1]->getNestedField())
		{
			if ((*areas)[distanceSq]->getNestedField() < (*areas)[0]->getNestedField())
				OpQ5_moveElement(*areas,distanceSq,0);
			else
			{
				for (int distances = distanceSq - 1; distances >= 0; distances--)
				{
					if ((*areas)[distanceSq]->getNestedField() >= (*areas)[distances]->getNestedField())
					{
						OpQ5_moveElement(*areas,distanceSq,distances + 1);
						break;
					}
				}
			}
		}
	}
	f44.clear();
	f54.clear();
	f64.clear();
	f74.clear();
	f84.clear();
	for (int distanceSq = 0; distanceSq < 4; distanceSq++)
	{
		f44.push_back(player->unknown45a840()[distanceSq]);
		f54.push_back(player->unknown5c92a0(distanceSq));
		f64.push_back(vector<string>());
		f74.push_back(vector<int>());
		f84.push_back(vector<int>());
		for (unsigned int distances = 0; distances < areas->size(); distances++)
		{
			if ((*areas)[distances]->getType() == distanceSq)
			{
				f74[distanceSq].push_back(0);
				f64[distanceSq].push_back((*areas)[distances]->unknown573860(false,&f74[distanceSq].back()));
				(*areas)[distances]->unknown573c90(f64[distanceSq].back());
				if ((*areas)[distances]->getEffect(110))
					f64[distanceSq].back() += " (fused)";
				f84[distanceSq].push_back(player->unknown5c92c0((*areas)[distances]));
			}
		}
	}
	f94 = player->unknown5cccc0();
	f98 = player->unknown5ca210();
	f9c.clear();
	fac.clear();
	int active = 0;
	for (unsigned int distanceSq = 0; distanceSq < areas->size(); distanceSq++)
	{
		if ((*areas)[distanceSq]->getType() == 4)
		{
			fac.push_back(0);
			if (isDump && c40_cf4830[(*areas)[distanceSq]->getNestedField()] == 0)
				f9c.push_back((*areas)[distanceSq]->unknown573860(false,&fac.back()));
			else
			{
				f9c.push_back((*areas)[distanceSq]->unknown573860(true,&fac.back()));
				if (c40_cf4830[(*areas)[distanceSq]->getNestedField()] != 0)
					(*areas)[distanceSq]->unknown5745d0(f9c.back());
			}
			active += (*areas)[distanceSq]->unknown4578c0();
		}
	}
	c40_d2c658.add4729d0(201,f98,c40_empty_b9017e,-1);
	c40_d2c658.add4729d0(202,active,c40_empty_b9017f,-1);
	const int center = 50;
	fbc.resize(center,center,0);
	fbc.fill(32);
	vector<int> col;
	col.push_back(c40_cefbb0->ID);
	col.push_back(c40_cefba8->ID);
	col.push_back(c40_cefbac->ID);
	C40_Grid<bool> &begin = c40_cefc4c->f674;
	C40_Grid<int> &c2 = c40_cefc4c->f69c;
	C40_Grid<C40_S14> &cols = c40_cefc4c->f740;
	int attempt = c40_cefc4c->f74c;
	C40_Grid<C40_S34> &current = c40_cefc4c->f7c4;
	C40_Point base(player->getPosition());
	C40_Point adj;
	C40_Point bottom;
	adj.x = OpX5_maxInt(base.x - 25,0);
	adj.y = OpX5_maxInt(base.y - 25,0);
	bottom.x = OpX5_minInt(base.x + 25,c40_cfd44c.getWidth() - 1);
	bottom.y = OpX5_minInt(base.y + 25,c40_cfd44c.getHeight() - 1);
	C40_Point arr(base.x < 25 ? 25 - base.x : -OpX5_maxInt(base.x - 25,0),base.y < 25 ? 25 - base.y : -OpX5_maxInt(base.y - 25,0));
	for (int distanceSq = adj.x, behaviour = OpX5_maxInt(arr.x,0); distanceSq <= bottom.x && behaviour < center; distanceSq++, behaviour++)
	{
		for (int distances = adj.y, clean = OpX5_maxInt(arr.y,0); distances <= bottom.y && clean < center; distances++, clean++)
		{
			if (!*begin.at(distanceSq,distances))
			{
				if (cols.at(distanceSq,distances)->f0 == attempt && !cols.at(distanceSq,distances)->isActive())
					*fbc.at(behaviour,clean) = cols.at(distanceSq,distances)->getValue(0);
				else
					*fbc.at(behaviour,clean) = 63;
			}
			else
			{
				ally = *c40_cfd44c.at(distanceSq,distances);
				if (*c2.at(distanceSq,distances) != 0)
				{
					if (ally->getEntity().isValid())
						*fbc.at(behaviour,clean) = ally->getEntity()->getAsciiDefault();
					else if (ally->unknown45d700())
						*fbc.at(behaviour,clean) = ally->getItem()->unknown457ab0();
					else if (ally->unknown45d1e0())
					{
						if (ally->getProp()->unknown44ab40() != -1 || ally->getProp()->get9b8f00() == c40_cefbd8)
							*fbc.at(behaviour,clean) = ally->getProp()->unknown45cb10() ? c40_b99c08[ally->getProp()->get9b8f00()->ff8] : (ally->getProp()->unknown457b10() ? 34 : 34);
						else
						{
							*fbc.at(behaviour,clean) = ally->getProp()->unknown44a630();
							if (*fbc.at(behaviour,clean) >= 128)
								*fbc.at(behaviour,clean) = 60;
						}
					}
					else if (ally->unknown45db70() && (!ally->isEdge() || c40_cefc4c->unknown463e90(C40_Point(distanceSq,distances))))
						*fbc.at(behaviour,clean) = ally->unknown45dbb0() ? 47 : 43;
					else if (ally->isMachinePart())
						*fbc.at(behaviour,clean) = ally->get9b8f00();
					else if (!ally->unknown45d270())
						*fbc.at(behaviour,clean) = 35;
					else
						*fbc.at(behaviour,clean) = 32;
				}
				else
				{
					if (cols.at(distanceSq,distances)->f0 == attempt && !cols.at(distanceSq,distances)->isActive())
						*fbc.at(behaviour,clean) = cols.at(distanceSq,distances)->getValue(0);
					else if (current.at(distanceSq,distances)->f0 != 32)
					{
						amount = c40_d28d30 ? current.at(distanceSq,distances)->f4 : current.at(distanceSq,distances)->f0;
						if (amount >= 128)
							*fbc.at(behaviour,clean) = 34;
						else if ((*c40_cfd44c.at(distanceSq,distances))->unknown45dc70() && c40_cefc4c->unknown463e90(C40_Point(distanceSq,distances)))
							*fbc.at(behaviour,clean) = (*c40_cfd44c.at(distanceSq,distances))->unknown45d4e0() ? 43 : 47;
						else if ((amount == 43 || amount == 47) && ((*c40_cfd44c.at(distanceSq,distances))->unknown45db70() || OpX5_containsRecord(col,*originalTerrain.at(distanceSq,distances))))
							*fbc.at(behaviour,clean) = amount;
						else if (current.at(distanceSq,distances)->f10 != c40_caf164 || !OpS8b_Fn9d43b0(c40_ba69e0,18,amount))
							*fbc.at(behaviour,clean) = amount == 46 ? 32 : amount;
						else
							*fbc.at(behaviour,clean) = 32;
					}
				}
			}
		}
	}
}
