// team_d_104: Group member 0x6719c0 (callers BS::opw3_unknown726af0 and two unnamed functions): alerts the
// group's members within a radius of a robot (or of a point) to a target, reporting whether anyone heard,
// whether a high-alert member reacted, and optionally collecting the members that newly engaged.
// NOTE: class layouts are partial; member and method names are placeholders. The locals found/value/cur
// are named for their stack-slot hash order.
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p);	// 0x46ca50
};

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name

class Entity;

class HEntity
{
public:
	int ID;
	HEntity();
	Entity *operator->() const;
	bool isValid() const;	// NOTE: folded with HItem::isValid
	bool operator!=(HEntity e) const;
};

class AI104	// NOTE: placeholder name (the robot's AI state)
{
public:
	int getHearing();	// NOTE: placeholder name (folded getter Stats_Hacking::GetCachedSize)
	int getAlert();		// NOTE: placeholder name (folded getter PingRequest::GetCachedSize)
	void unknown5b4710(HEntity target, int a, int b, int c, bool *engaged);	// NOTE: placeholder name
};

class Entity
{
public:
	AI104 *getAI();			// NOTE: placeholder name (folded getter ManualUI::unknown45b590)
	Point unknown45a4c0();	// NOTE: placeholder name (position)
	int getTarget();
	int getFaction();
	bool isXomCandidate();
};

extern int defaultHearing104_bba1e0;	// NOTE: placeholder name

class Group104	// NOTE: placeholder name and layout (Group)
{
public:
	char			pad00[8];
	int				type;		// +0x08
	vector<HEntity>	members;	// +0x0c

	bool unknown6719c0(bool quiet, HEntity e, HEntity target, bool *alerted, vector<HEntity> *out, const Point &pos, int range);	// NOTE: placeholder name
};

bool Group104::unknown6719c0(bool quiet, HEntity e, HEntity target, bool *alerted, vector<HEntity> *out, const Point &pos, int range)
{
	int value = e.isValid() ? (e->getAI() == 0 ? defaultHearing104_bba1e0 : e->getAI()->getHearing()) : range;
	if (value == 0)
		return false;
	bool found = false;
	Point cur = e.isValid() ? e->unknown45a4c0() : pos;
	for (unsigned int i = 0; i < members.size(); i++)
	{
		if (OpQ1_distanceCeil_40a3f0(cur,members[i]->unknown45a4c0()) <= value && members[i] != e && members[i]->getAI() && (!members[i]->getTarget() || members[i]->getTarget() == 2) && (members[i]->getFaction() != 0x14 || type != 4))
		{
			bool engaged = false;
			if (!quiet)
				members[i]->getAI()->unknown5b4710(target,1,0,0,&engaged);
			found = true;
			if (members[i]->getAI()->getAlert() >= 6 && (members[i]->isXomCandidate() || members[i]->getAI()->getAlert() == 6))
			{
				*alerted = true;
				if (engaged && out)
					out->push_back(members[i]);
			}
		}
	}
	return found;
}
