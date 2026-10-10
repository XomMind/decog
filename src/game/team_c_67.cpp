// team_c_67: Overmind::deployAssaultParty (0x687ef0): builds an assault party composition for the given type
//	(weighted by depth), places the members next to the owner, links followers and registers the party
// NOTE: names are placeholders; Overmind layout is partial
#include <string>
#include <vector>
using namespace std;

void logError(string location, string message);

struct C67_Point { int x; int y; };	// NOTE: placeholder (Point)
struct C67_Rect { int x; int y; int w; int h; };	// NOTE: placeholder (Rect)
struct C67_Record { char pad0[0x28]; int f28; };	// NOTE: placeholder (entity record)
class C67_HEntity;
struct C67_AI	// NOTE: placeholder (EntityAI)
{
	void unknown5b51b0(C67_HEntity entity);
	void setFollowEntity(C67_HEntity entity, int flag);
	bool getFollowers580a90(vector<C67_HEntity> &out, int range);
	C67_HEntity getFollowEntity();
	void unknown459470(C67_Rect &area);
};
struct C67_Entity { C67_AI *unknown45b590(); C67_Point &getPosition(); const string &getName(); void setAI(C67_AI *ai); void unknown639530(int a, int b); };	// NOTE: placeholder names
class C67_HEntity { public: int ID; C67_HEntity(); C67_Entity *operator->() const; bool isNull() const; bool isValid() const; };	// NOTE: placeholder (HEntity)
class C67_HItem { public: int ID; C67_HItem(); };	// NOTE: placeholder (HItem)
class C67_NewAI { public: C67_NewAI(C67_HEntity entity, int a, int b); char data[0x130]; };	// NOTE: placeholder (0x57f6a0)
template <class T> class C67_WL { public: vector<T> values; vector<int> weights; int total; C67_WL(); C67_WL(const T *weights, int count); ~C67_WL(); void add(T value, int weight); bool pick(T *out); };	// NOTE: placeholder (OpR5h_WL)
struct C67_World	// NOTE: placeholder (BS/Map at 0xcefc4c)
{
	C67_Record *selectRobotOfClass(int a, int b, bool c, int d);
	C67_HEntity placeEntity(C67_Record *record, const C67_Point &position, int groupIndex, bool flag, int aiMode1, int aiMode2, bool forced);
	C67_HItem giveItem(const string &name, C67_HEntity entity, int a, int b);
	void unknown6c65a0(C67_HEntity entity, const string &text, int a);
	C67_Rect &unknown464690();
	int getTurn();
};
struct C67_GameData { int getDepthIndex(); };
class C67_Party { public: C67_Party(int type, C67_HEntity leader, int a, bool b, int c); char data[0x38]; };	// NOTE: placeholder (Party)
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&result);	// NOTE: placeholder name
template <class T> void OpQ5_moveElement(vector<T> &v, unsigned int from, unsigned int to);	// NOTE: placeholder name
template <class T> void OpQ5_appendVector(vector<T> &v, vector<T> &add);	// NOTE: placeholder name

extern C67_World *c67_cefc4c;	// NOTE: placeholder names below
extern C67_GameData c67_d1e860;
extern int c67_b93b58[][5];
extern int c67_b93cb8[][4];
extern const int c67_b93c34[];
extern int c67_b93d68[][3];
extern int c67_b93df8[][3];
extern vector<C67_Record *> c67_d25de0;
extern int c67_b91e18;

class Overmind	// NOTE: placeholder layout (partial)
{
public:
	void addParty(C67_Party *party, int a);	// NOTE: placeholder name
	int deployAssaultParty(C67_HEntity owner, int type, bool flag, vector<C67_HEntity> *out);
};

int Overmind::deployAssaultParty(C67_HEntity owner, int type, bool flag, vector<C67_HEntity> *out)
{
	vector<C67_Record *> adj;
	if (type == 1)
	{
		C67_Record *cols = c67_cefc4c->selectRobotOfClass(1,22,0,1);
		if (cols == 0)
		{
			logError("Overmind::deployAssaultParty()","No CLASS_DEMOLISHER found");
			return 0;
		}
		adj.assign(2,cols);
	}
	else
	{
		switch (type)
		{
			case 4:
			{
				int current;
				C67_WL<int> element;
				for (int distanceSq = 0; distanceSq < 5; distanceSq++)
					element.add(distanceSq,c67_b93b58[c67_d1e860.getDepthIndex()][distanceSq]);
				for (int distanceSq = 0; distanceSq < 4; distanceSq++)
				{
					element.pick(&current);
					switch (current)
					{
						case 0:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,24,0,1));
							break;
						case 1:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,25,0,1));
							break;
						case 2:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,23,0,1));
							break;
						case 3:
							adj.push_back(c67_cefc4c->selectRobotOfClass(2,30,0,1));
							break;
						case 4:
							adj.push_back(c67_cefc4c->selectRobotOfClass(2,31,0,1));
							break;
					}
				}
				break;
			}
			case 3:
			{
				int current;
				C67_WL<int> element;
				for (int distanceSq = 0; distanceSq < 4; distanceSq++)
					element.add(distanceSq,c67_b93cb8[c67_d1e860.getDepthIndex()][distanceSq]);
				for (int distanceSq = 0; distanceSq < 3; distanceSq++)
				{
					element.pick(&current);
					switch (current)
					{
						case 0:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,24,0,1));
							break;
						case 1:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,25,0,1));
							break;
						case 2:
							adj.push_back(c67_cefc4c->selectRobotOfClass(2,30,0,1));
							break;
						case 3:
							adj.push_back(c67_cefc4c->selectRobotOfClass(2,31,0,1));
							break;
					}
				}
				break;
			}
			case 5:
			{
				int current;
				C67_WL<int> element(c67_b93c34,6);
				for (int distanceSq = 0; distanceSq < 4; distanceSq++)
				{
					element.pick(&current);
					switch (current)
					{
						case 0:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,13,0,0));
							break;
						case 1:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,16,0,0));
							break;
						case 2:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,17,0,0));
							break;
						case 3:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,18,0,0));
							break;
						case 4:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,24,0,1));
							break;
						case 5:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,25,0,1));
							break;
					}
				}
				break;
			}
			default:
			{
				int current;
				C67_WL<int> element;
				for (int distances = 0; distances < 3; distances++)
					element.add(distances,c67_b93d68[c67_d1e860.getDepthIndex()][distances]);
				bool distanceSq = false;
				for (int distances = 0; distances < 4; distances++)
				{
					element.pick(&current);
					switch (current)
					{
						case 0:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,16,!distanceSq,0));
							distanceSq = true;
							break;
						case 1:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,17,0,0));
							break;
						case 2:
							adj.push_back(c67_cefc4c->selectRobotOfClass(1,18,0,0));
							break;
					}
				}
			}
		}
		C67_WL<int> cols;
		for (int current = 0; current < 3; current++)
			cols.add(current,c67_b93df8[c67_d1e860.getDepthIndex()][current]);
		int dy;
		cols.pick(&dy);
		switch (dy)
		{
			case 0:
				adj.push_back(c67_cefc4c->selectRobotOfClass(1,8,0,0));
				break;
			case 1:
				adj.push_back(c67_cefc4c->selectRobotOfClass(1,19,0,0));
				break;
			case 2:
				adj.push_back(c67_cefc4c->selectRobotOfClass(1,15,0,0));
				break;
		}
	}
	if (type == 2)
	{
		C67_Record *cols;
		if (OpQ5_findByName(c67_d25de0,"Investigator",cols))
			adj.push_back(cols);
	}
	if (adj.front()->f28 != 16)
	{
		for (unsigned int cols = 1; cols < adj.size(); cols++)
		{
			if (adj[cols]->f28 == 16)
			{
				OpQ5_moveElement(adj,cols,0);
				break;
			}
		}
	}
	int center = 0;
	C67_HEntity behaviour;
	vector<C67_HEntity> clean;
	bool col = false;
	for (unsigned int cols = 0; cols < adj.size(); cols++)
	{
		C67_HEntity current = c67_cefc4c->placeEntity(adj[cols],owner->getPosition(),col ? 2 : 3 + (adj[cols]->f28 == 8),false,34,14,false);
		if (current.isNull())
			continue;
		center++;
		if (current->getName() == "Investigator")
		{
			current->setAI((C67_AI *)new C67_NewAI(current,3,8));
			c67_cefc4c->giveItem("Containment Facilitator",current,0,0);
			c67_cefc4c->unknown6c65a0(current,"High_Security_Assault_1",0);
		}
		if (behaviour.isValid())
			current->unknown45b590()->setFollowEntity(behaviour,0);
		else
			behaviour = current;
		clean.push_back(current);
	}
	if (behaviour.isNull())
		return center;
	if (out != 0)
		*out = clean;
	for (unsigned int cols = 0; cols < clean.size(); cols++)
		owner->unknown45b590()->unknown5b51b0(clean[cols]);
	if (col)
		return center;
	vector<C67_HEntity> desc;
	if (owner->unknown45b590()->getFollowers580a90(desc,15))
	{
		for (unsigned int current = 0; current < desc.size(); current++)
			desc[current]->unknown45b590()->setFollowEntity(behaviour,0);
		OpQ5_appendVector(clean,desc);
	}
	if (type == 4)
		behaviour->unknown45b590()->setFollowEntity(owner->unknown45b590()->getFollowEntity(),0);
	if (type == 5)
	{
		for (unsigned int distanceSq = 0; distanceSq < clean.size(); distanceSq++)
		{
			clean[distanceSq]->unknown45b590()->unknown459470(c67_cefc4c->unknown464690());
			clean[distanceSq]->unknown639530(148,1);
		}
	}
	addParty(new C67_Party(7,behaviour,-1,flag,c67_cefc4c->getTurn() + c67_b91e18),0);
	return center;
}
