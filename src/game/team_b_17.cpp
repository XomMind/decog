// team_b_17: Entity group alert (0x639ec0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <vector>
using namespace std;
struct Point { int x; int y; };
class Entity;
class HEntity { public: int ID; HEntity(); Entity *operator->() const; bool operator!=(HEntity other) const; };
class Group { public: vector<HEntity> *getMembers(); };	// NOTE: placeholder name (ICF'd member address getter)
class HGroup { public: int ID; HGroup(); Group *operator->() const; };
class EntityAI
{
public:
	int getType_9b4350();	// NOTE: placeholder name (ICF'd getter)
	HEntity *getEntity459570(HEntity e);	// NOTE: placeholder name
	void unknown5b4710(HEntity e, int a, int b, int c, int d);	// NOTE: placeholder name
};
class Map
{
public:
	HGroup unknown463890(int i);	// NOTE: placeholder name
	bool isReachable(int range, const Point &from, const Point &to);	// NOTE: placeholder name (0x465230)
};
extern Map *endObjA;	// 0xcefc4c
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);
class Entity
{
public:
	int pad0;
	HEntity self;
	bool unknown5cb680(HGroup group);	// NOTE: placeholder name
	void *getTarget();
	EntityAI *getAI();
	const Point &getPosition();
	int unknown5c7d30();	// NOTE: placeholder name
	int unknown5d2150(int type, int b);	// NOTE: placeholder name
	void alertGroup639ec0(HEntity skip, bool checkSkip);	// NOTE: placeholder name
};
void Entity::alertGroup639ec0(HEntity skip, bool checkSkip)	// 0x639ec0
{
	if (unknown5cb680(endObjA->unknown463890(3)))
	{
		vector<HEntity> &members = *endObjA->unknown463890(4)->getMembers();
		for (unsigned int i = 0; i < members.size(); i++)
		{
			if (!members[i]->getTarget() && members[i]->getAI()->getType_9b4350() == 7 && !members[i]->getAI()->getEntity459570(self)
				&& OpQ1_distanceCeil_40a3f0(getPosition(),members[i]->getPosition()) <= members[i]->unknown5c7d30() - unknown5d2150(0x1e,0)
				&& endObjA->isReachable(members[i]->unknown5c7d30(),members[i]->getPosition(),getPosition())
				&& (!checkSkip || members[i] != skip))
				members[i]->getAI()->unknown5b4710(self,1,0,0,0);
		}
	}
}
