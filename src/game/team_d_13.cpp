// team_d_13: follow-target assignment rule (0x51caa0).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

class HEntity;

class EntityAI
{
public:
	void setFollowEntity(HEntity followEntity_, int followParam_);	// 0x5b2f80
};

class Group	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: placeholder name (trivial getter)
};

class HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	Group *operator->() const;
};

class Entity
{
public:
	Point &getPosition();	// 0x45a4a0
	HGroup getGroup();		// 0x45a3f0
	int getTarget();		// 0x45a760
	EntityAI *getAI();		// 0x45b590
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool operator!=(HEntity other) const;
	bool isValid() const;
	Entity *operator->() const;
};

class Map
{
public:
	HEntity getPlayer();	// 0x4630f0
};
extern Map *world;

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);

struct OpD_FollowRule	// NOTE: placeholder name
{
	char pad[0xc4];
	int mode;		// +0xc4, NOTE: placeholder name
	int param;		// +0xc8, NOTE: placeholder name
};

void OpD_assignFollow_51caa0(OpD_FollowRule *rule, HEntity e, HEntity a, HEntity b)	// NOTE: placeholder name
{
	if (e->getAI())
	{
		switch (rule->mode)
		{
			break;
			case 1:
				if (a.operator->())
					e->getAI()->setFollowEntity(a,rule->param);
				break;
			case 2:
				if (b.operator->())
					e->getAI()->setFollowEntity(b,rule->param);
				break;
			case 3:
			{
				HEntity target;
				int minDist = 999999;
				vector<HEntity> *members = e->getGroup()->getMembers();
				int unit;
				for (unsigned int i = 0; i < members->size(); i++)
				{
					if (e != (*members)[i] && (*members)[i]->getTarget() == 0)
					{
						unit = OpQ1_distanceCeil_40a3f0(e->getPosition(),(*members)[i]->getPosition());
						if (unit < minDist)
						{
							minDist = unit;
							target = (*members)[i];
						}
					}
				}
				if (target.isValid())
					e->getAI()->setFollowEntity(target,rule->param);
				break;
			}
			case 4:
				if (!e->getGroup()->getMembers()->empty())
					e->getAI()->setFollowEntity(e->getGroup()->getMembers()->back(),rule->param);
				break;
			case 5:
				e->getAI()->setFollowEntity(world->getPlayer(),rule->param);
				break;
		}
	}
}
