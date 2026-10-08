// team_c_70: Zion under attack (0x731b10): flags the attack, posts the matching alert, clears props and robots tied
//	to the old state, places hostile Zionite markers and turns the locals and followers against the player
// NOTE: names are placeholders; BS layout is partial
#include <string>
#include <vector>
using namespace std;

int stringToInt(const string &s);
void opR1d_4541b0(int a, int b, int c);	// NOTE: placeholder name
struct C70_Point { int x; int y; C70_Point(); };	// NOTE: placeholder (Point)
struct C70_Rect { int x; int y; int w; int h; C70_Rect(int x_, int y_, int w_, int h_); void randomPos_40b000(C70_Point &out); };	// NOTE: placeholder (Rect)
void getAdjacentCells(const C70_Point &p, vector<C70_Point> &out);	// NOTE: placeholder signature
class C70_HProp { public: int ID; C70_HProp(); bool isValid() const; struct C70_Prop *operator->() const; };	// NOTE: placeholder (HProp)
struct C70_Prop { int unknown45c800(int a); bool unknown665be0(bool a); int getHeight(); void unknown665b90(const string &text, int a); };	// NOTE: placeholder names
class C70_HSquad;
struct C70_Entity	// NOTE: placeholder (Entity)
{
	bool unknown5c98c0(int a, int b, int c);
	bool isPlayer();
	int unknown45acb0(int a);
	void removeEffectsA(int a);
	int getSlotTotal();
	int getFaction();
	void changeFaction(C70_HSquad squad, bool flag);
	bool unknown45ad20(const string &tag);
};
class C70_HEntity { public: int ID; C70_HEntity(); C70_Entity *operator->() const; bool isValid() const; };	// NOTE: placeholder (HEntity)
struct C70_Cell { C70_HProp getProp(); C70_HEntity getEntity(); bool isPassableFor(C70_HEntity e); };
struct C70_CellGrid { int getWidth(); int getHeight(); C70_Cell **at(int x, int y); C70_Cell **atPoint(C70_Point &p); };
struct C70_Squad { vector<C70_HEntity> *getMembers(); };	// NOTE: placeholder (folded getter getFore)
class C70_HSquad { public: int ID; C70_Squad *get230() const; };	// NOTE: placeholder
struct C70_Level { char pad0[4]; int f4; int depth(); };	// NOTE: placeholder
class C70_HLevel { public: int ID; C70_Level *get23c() const; };	// NOTE: placeholder
struct C70_Exit { C70_Point p; C70_HLevel f8; };	// NOTE: placeholder
struct C70_GameData { void setEntryText(const string &key, const string &value); const string &getEntryText(const string &key); };
struct C70_Audio { bool enabled; void unknown69e700(int id, int flag, float volume); };	// NOTE: placeholder (0xd25450)
struct C70_Alerts { void setCachedSize(int v); };	// NOTE: placeholder (0xcf1080)
struct C70_Console2 { void unknown8758d0(bool flag); };
struct C70_Log { void scrollToEnd(); };
bool c70_message5111e0(int id, const string *a, const string *b, int c, C70_HProp entity, C70_HProp prop, int d, int e);	// NOTE: placeholder name (0x5111e0)
void c70_message5141b0(int id, const string *a, const string *b, int c, C70_HProp prop, int d);	// NOTE: placeholder name (0x5141b0)
void OpU8a_removeEntity(vector<C70_HProp> &v, C70_HProp p);	// NOTE: placeholder signature

extern C70_GameData c70_d1e860;	// NOTE: placeholder names below
extern bool c70_d1dd38;
extern C70_Alerts c70_cf1080;
extern C70_Console2 *c70_cec058;
extern C70_Log *c70_cec0b4;
extern C70_Audio c70_d25450;
extern C70_HLevel c70_d1e888;
extern C70_CellGrid c70_cfd44c;
extern int c70_cefbd8;

#define C70_MSG(text) do { if (c70_message5111e0(804,&string(text),0,0,C70_HProp(),C70_HProp(),0,0)) c70_cec058->unknown8758d0(true); c70_cec0b4->scrollToEnd(); } while (0)
#define C70_ALERT(text) do { c70_cf1080.setCachedSize(1); if (0) opR1d_4541b0(-1,0,0); C70_MSG(text); c70_cec0b4->scrollToEnd(); } while (0)
#define C70_LOG(id) do { c70_message5141b0(id,0,0,0,C70_HProp(),0); } while (0)

class BS	// NOTE: placeholder layout (partial)
{
public:
	char pad0[0x10];
	vector<C70_Exit *> f10;
	char pad20[0x4c - 0x20];
	vector<C70_HSquad> f4c;
	char pad5c[0x2f4 - 0x5c];
	vector<C70_HEntity> f2f4;
	vector<int> f304;
	char pad314[0x4f0 - 0x314];
	vector<C70_HProp> f4f0;
	char pad500[0x66c - 0x500];
	C70_HEntity f66c;

	void removeEntity(C70_HEntity entity);
	void unknown6c65a0(C70_HEntity entity, const string &text, int a);
	void unknown6c6b90(const C70_Point &p, const string &text, int a, int b);
	void zionAttacked_731b10(bool imprinter);
};

void BS::zionAttacked_731b10(bool imprinter)
{
	c70_d1e860.setEntryText("zioAttackedLocals_g","1");
	c70_d1dd38 = false;
	if (imprinter)
	{
		C70_ALERT("IMPRINTER ALERT: Unauthorized bot attempting to interface! Defend our home!");
		C70_LOG(366);
	}
	else if (stringToInt(c70_d1e860.getEntryText("installedRif_g")))
	{
		C70_ALERT("PUBLIC SERVICE ANNOUNCEMENT: 0b10 RIF detected in Zion! Defend our home!");
		C70_LOG(365);
	}
	else if (stringToInt(c70_d1e860.getEntryText("scrAttackedLocals_g")))
		C70_ALERT("PUBLIC SERVICE ANNOUNCEMENT: We have a pariah in our midst! Give them the departure escort they deserve!");
	else
		C70_ALERT("PUBLIC SERVICE ANNOUNCEMENT: Zion is under attack! Defend our home!");
	C70_LOG(364);
	if (c70_d25450.enabled)
		c70_d25450.unknown69e700(99,imprinter || f66c->getSlotTotal() < c70_d1e888.get23c()->depth() * 2 + 5 || f66c->unknown5c98c0(0,66,0),0.0f);
	for (int col = 0; col < c70_cfd44c.getWidth(); col++)
	{
		for (int cols = 0; cols < c70_cfd44c.getHeight(); cols++)
		{
			if ((*c70_cfd44c.at(col,cols))->getProp().isValid() && !(*c70_cfd44c.at(col,cols))->getProp()->unknown45c800(142))
			{
				(*c70_cfd44c.at(col,cols))->getProp()->unknown665be0(false);
				OpU8a_removeEntity(f4f0,(*c70_cfd44c.at(col,cols))->getProp());
			}
			if ((*c70_cfd44c.at(col,cols))->getEntity().isValid() && !(*c70_cfd44c.at(col,cols))->getEntity()->isPlayer() && !(*c70_cfd44c.at(col,cols))->getEntity()->unknown45acb0(142))
			{
				removeEntity((*c70_cfd44c.at(col,cols))->getEntity());
				(*c70_cfd44c.at(col,cols))->getEntity()->removeEffectsA(1);
			}
		}
	}
	f4f0.clear();
	f2f4.clear();
	f304.clear();
	const int allies = 50;
	C70_Rect begin(0,0,100,130);
	C70_Point a1;
	vector<C70_Point> center;
	for (int col = 0; col < allies; col++)
	{
		for (int cols = 500; cols > 0; cols--)
		{
			begin.randomPos_40b000(a1);
			center.clear();
			getAdjacentCells(a1,center);
			int current = 0;
			bool clean = false;
			for (unsigned int distanceSq = 0; distanceSq < center.size(); distanceSq++)
			{
				if ((*c70_cfd44c.atPoint(center[distanceSq]))->getProp().isValid() && (*c70_cfd44c.atPoint(center[distanceSq]))->getProp()->getHeight() == c70_cefbd8)
					clean = true;
				else if ((*c70_cfd44c.atPoint(center[distanceSq]))->isPassableFor(C70_HEntity()))
					current++;
			}
			if (clean && current != 0)
			{
				unknown6c6b90(a1,"ZIO_Hostile_Zionite1",0,-1);
				break;
			}
		}
	}
	const int adj = 25;
	for (int col = 0; col < adj; col++)
	{
		for (int cols = 500; cols > 0; cols--)
		{
			begin.randomPos_40b000(a1);
			if ((*c70_cfd44c.atPoint(a1))->getProp().isValid() && (*c70_cfd44c.atPoint(a1))->getProp()->getHeight() == c70_cefbd8)
			{
				(*c70_cfd44c.atPoint(a1))->getProp()->unknown665b90("ZIO_Hostile_Zionite3",0);
				break;
			}
		}
	}
	vector<C70_HEntity> *base = f4c[8].get230()->getMembers();
	for (int col = base->size() - 1; col >= 0; col--)
		(*base)[col]->changeFaction(f4c[5],true);
	vector<C70_HEntity> *bottom = f4c[2].get230()->getMembers();
	for (int col = bottom->size() - 1; col >= 0; col--)
	{
		if ((*bottom)[col]->unknown45ad20("ZIO_Follower"))
			(*bottom)[col]->changeFaction(f4c[5],true);
	}
	for (unsigned int col = 0; col < f10.size(); col++)
	{
		if (f10[col]->f8.get23c()->f4 == 18)
		{
			unknown6c6b90(f10[col]->p,"ZIO_Hero_Defender_Spawn",0,-1);
			break;
		}
	}
	vector<C70_HEntity> *behaviour = f4c[5].get230()->getMembers();
	for (unsigned int col = 0; col < behaviour->size(); col++)
	{
		if ((*behaviour)[col]->getFaction() == 76)
		{
			unknown6c65a0((*behaviour)[col],"ZIO_Imprinter_Retreat",0);
			break;
		}
	}
}
