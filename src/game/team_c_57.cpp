// team_c_57: warlord raid spawn (0x68e1f0): builds the depth-dependent raid group table, picks the arrival point
//	(along the path to the main exit, or a random exit), spawns 4 groups with a commander, and posts the alert
// NOTE: names are placeholders
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908
int stringToInt(const string &s);
struct C57_Point { int x; int y; C57_Point(int v); C57_Point(int x_, int y_); C57_Point(const C57_Point &o) throw(); C57_Point &operator=(const C57_Point &o) throw(); };	// NOTE: placeholder (Point)

struct C57_Rect { int x; int y; int w; int h; C57_Rect(); };	// NOTE: placeholder (Rect)
struct C57_Exit { C57_Point p; char pad8[0x1c - 8]; int f1c; };	// NOTE: placeholder (exit record)
struct C57_Record;
struct C57_AI { void unknown459470(C57_Rect &area); void setFollowEntity(int entity, int flag); };	// NOTE: placeholder names
struct C57_Entity { C57_AI *unknown45b590(); void unknown5fd900(int level, int duration); };
class C57_HEntity { public: int ID; C57_HEntity(); C57_Entity *operator->() const; bool isNull() const; bool isValid() const; };	// NOTE: placeholder (HEntity)
struct C57_MoveCost;
struct C57_Cartographer { bool findPath(const C57_Point &from, const C57_Point &to, C57_MoveCost *moveCost, void *data, vector<C57_Point> &path); };
struct C57_World { C57_Point *getBuffer_4184d0(); vector<C57_Exit *> *getPos(); C57_HEntity unknown715230(int group, int faction); C57_HEntity spawn6c5dc0(const string &name, const C57_Point &position, int groupIndex, bool flag, int aiMode1, int aiMode2, bool forced); void unknown6c65a0(C57_HEntity entity, const string &text, int a); void unknown6c6b90(const C57_Point &p, const string &text, int a, int b); C57_Record *selectRobotOfClass(int a, int b, int c, int d); C57_HEntity placeEntity(C57_Record *record, const C57_Point &position, int groupIndex, bool flag, int aiMode1, int aiMode2, bool forced); int unknown4642d0(); };	// NOTE: placeholder (BS)
struct C57_Grid { C57_Rect getArea(); };
struct C57_GameData { int getDepthIndex(); const string &getEntryText(const string &key); };
template <class T> class C57_WL { public: vector<T> values; vector<int> weights; int total; C57_WL(); C57_WL(vector<int> &w); ~C57_WL(); void add(T value, int weight); T &pick(); };	// NOTE: placeholder (OpR5h_WL)
void OpT8a_eraseAt(vector<int> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0)
struct OpU8a_Rec;
OpU8a_Rec *OpU8a_randomRec(vector<OpU8a_Rec*> &v);	// NOTE: placeholder name
bool c57_message5141b0(int id, const string *a, const string *b, int c, C57_HEntity prop, int d);	// NOTE: placeholder name (0x5141b0)

extern C57_GameData c57_d1e860;	// NOTE: placeholder names below
extern C57_World *c57_cefc4c;
extern C57_Cartographer c57_cfe568;
extern C57_MoveCost *c57_cefc30;
extern C57_Grid c57_cfd44c;
extern bool c57_cf4a00;
extern int c57_cf65b4, c57_cf65b8;

class C57_Raid	// NOTE: placeholder
{
public:
	void spawnWarlordRaid_68e1f0(bool flag);
};

void C57_Raid::spawnWarlordRaid_68e1f0(bool flag)
{
	int base = 4;
	vector< vector<string> > center;
	vector<int> a1;
	if (c57_d1e860.getDepthIndex() >= 7)
	{
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),6,"Wasp_7");
		a1.push_back(10);
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),5,"Thug_7");
		a1.push_back(20);
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),1,"Thug_7");
		a1.push_back(10);
		center.back().insert(center.back().end(),2,"Savage_7");
		center.back().insert(center.back().end(),2,"Butcher_7");
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),5,"Butcher_7");
		a1.push_back(10);
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),2,"Guerilla_7");
		a1.push_back(15);
		center.back().insert(center.back().end(),2,"Wasp_7");
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),3,"Wizard_7");
		a1.push_back(10);
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),2,"Mutant_8");
		a1.push_back(10);
		center.back().insert(center.back().end(),2,"Mutant_7");
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),2,"Martyr_7");
		a1.push_back(5);
		center.back().insert(center.back().end(),1,"Mutant_8");
		center.back().insert(center.back().end(),2,"Thug_7");
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),5,"Fireman_7");
		a1.push_back(10);
	}
	else
	{
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),6,"Wasp_5");
		a1.push_back(10);
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),5,"Thug_5");
		a1.push_back(20);
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),1,"Thug_5");
		a1.push_back(10);
		center.back().insert(center.back().end(),2,"Savage_5");
		center.back().insert(center.back().end(),2,"Butcher_5");
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),5,"Butcher_5");
		a1.push_back(10);
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),2,"Guerilla_5");
		a1.push_back(15);
		center.back().insert(center.back().end(),2,"Wasp_5");
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),3,"Wizard_5");
		a1.push_back(10);
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),2,"Mutant_6");
		a1.push_back(10);
		center.back().insert(center.back().end(),2,"Mutant_5");
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),2,"Martyr_5");
		a1.push_back(5);
		center.back().insert(center.back().end(),1,"Mutant_6");
		center.back().insert(center.back().end(),2,"Thug_5");
		center.push_back(vector<string>());
		center.back().insert(center.back().end(),5,"Fireman_5");
		a1.push_back(10);
	}
	C57_WL<int> adj(a1);
	int attempt = 50;
	C57_WL<string> allies;
	allies.add("Commander",1);
	int bonus = 10;
	C57_Point ay(-1);
	C57_Point col(-1);
	if (flag)
	{
		vector<C57_Point> cols;
		if (c57_cfe568.findPath(*c57_cefc4c->getBuffer_4184d0(),(*c57_cefc4c->getPos())[0]->p,c57_cefc30,0,cols))
		{
			ay = cols[10];
			col = cols[15];
		}
	}
	else
	{
		vector<C57_Exit *> cols(*c57_cefc4c->getPos());
		for (unsigned int current = 0; current < cols.size(); current++)
		{
			if (cols[current]->f1c != 0 && cols[current]->f1c != 1)
				OpT8a_eraseAt((vector<int> &)cols,current);
		}
		if (!cols.empty())
		{
			C57_Exit *current = (C57_Exit *)OpU8a_randomRec((vector<OpU8a_Rec *> &)cols);
			current->f1c = 0;
			ay = current->p;
		}
	}
	if (ay.x != -1)
	{
		C57_Rect cols = c57_cfd44c.getArea();
		int behaviour = c57_cf4a00 || stringToInt(c57_d1e860.getEntryText("warAttackedLocals_g")) != 0 || c57_cefc4c->unknown715230(2,94).isValid() ? 5 : 9;
		for (int current = 0; current < 4; current++)
		{
			C57_HEntity clean;
			C57_HEntity distanceSq;
			int begin = adj.pick();
			vector<string> &bottom = center[begin];
			bool count = false;
			if (rng.chance(10))
			{
				bottom.push_back(c57_d1e860.getDepthIndex() >= 6 ? "Surgeon_6" : "Surgeon_4");
				count = true;
			}
			for (unsigned int distances = 0; distances < bottom.size(); distances++)
			{
				if (distances == 0 && rng.chance(50))
				{
					clean = c57_cefc4c->spawn6c5dc0(allies.pick(),ay,behaviour,flag,34,14,false);
					if (clean.isValid())
						clean->unknown45b590()->unknown459470(cols);
				}
				distanceSq = c57_cefc4c->spawn6c5dc0(bottom[distances],ay,behaviour,flag,34,14,false);
				if (distanceSq.isValid())
				{
					distanceSq->unknown45b590()->unknown459470(cols);
					if (clean.isNull())
						clean = distanceSq;
					else
						distanceSq->unknown45b590()->setFollowEntity(clean.ID,0);
				}
			}
			if (current == 0 && clean.isValid())
				c57_cefc4c->unknown6c65a0(clean,"GAR_W_Attack_Talk",0);
			if (count)
				bottom.pop_back();
		}
		c57_cefc4c->unknown6c6b90(C57_Point(0,0),"GAR_Warlord_Retreat",0,-1);
		if (flag && col.x != -1 && rng.chance(50))
		{
			C57_Record *current = c57_cefc4c->selectRobotOfClass(1,21,0,1);
			if (current != 0)
			{
				C57_HEntity distanceSq = c57_cefc4c->placeEntity(current,col,3,flag,34,14,false);
				if (distanceSq.isValid())
					distanceSq->unknown5fd900(1,50);
			}
		}
		if (c57_cf65b4 == 0)
			c57_cf65b8 = c57_cefc4c->unknown4642d0() + rng.rangeInt(10.0f,50.0f);
		do
		{
			c57_message5141b0(410,0,0,0,C57_HEntity(),0);
		} while (0);
	}
}
