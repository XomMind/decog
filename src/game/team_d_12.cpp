// team_d_12: squad member scan (0x671c90).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

class EntityAI
{
public:
	int unknown9b4350();				// NOTE: placeholder name (trivial getter)
	int unknown9c3a90();				// NOTE: placeholder name (trivial getter, folded with Array2D<XCell>::getHeight)
	void unknown4593b0(const Point &p);	// NOTE: placeholder name
	void unknown459520(const Point &p);	// NOTE: placeholder name
};

class Entity
{
public:
	int getAiType();		// 0x45a2a0
	int getFaction();		// 0x45a2c0
	Point unknown45a4c0();	// NOTE: placeholder name
	int getTarget();		// 0x45a760
	EntityAI *getAI();		// 0x45b590
	bool isXomCandidate();	// 0x5d51a0
};

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	Entity *operator->() const;
};

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);

class OpD_Squad671c90	// NOTE: placeholder name
{
public:
	bool unknown671c90(const Point &pos, int range, vector<HEntity> *out);	// NOTE: placeholder name

	char pad[0xc];
	vector<HEntity> members;	// +0xc, NOTE: placeholder name
};

bool OpD_Squad671c90::unknown671c90(const Point &pos, int range, vector<HEntity> *out)
{
	int maxRange = range;
	bool found = false;
	for (unsigned int i = 0; i < members.size(); i++)
	{
		if (OpQ1_distanceCeil_40a3f0(pos,members[i]->unknown45a4c0()) <= maxRange && members[i]->getAI() && members[i]->getTarget() == 0
			&& members[i]->getAI()->unknown9b4350() >= 6 && members[i]->getAiType() == 1
			&& (members[i]->getAI()->unknown9c3a90() != 1 || members[i]->getFaction() == 0x15 || members[i]->getFaction() == 0x1a)
			&& members[i]->isXomCandidate())
		{
			if (members[i]->getFaction() == 0x15 || members[i]->getFaction() == 0x1a)
				members[i]->getAI()->unknown4593b0(pos);
			else
				members[i]->getAI()->unknown459520(pos);
			if (out)
				out->push_back(members[i]);
			found = true;
		}
	}
	return found;
}
