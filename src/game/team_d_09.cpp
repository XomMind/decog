// team_d_09: BS squad selection (0x68cf70).
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
	class HEntity getFollowEntity();	// 0x458ed0
	void unknown5b5220();				// NOTE: placeholder name
};

class Entity;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	bool operator==(HEntity other) const;
	Entity *operator->() const;
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
	EntityAI *getAI();		// 0x45b590
};

struct Squad	// NOTE: placeholder name (records of the global list at 0xcf6478)
{
	int		type;	// NOTE: placeholder name
	HEntity	leader;	// NOTE: placeholder name

	bool unknown45e820();	// NOTE: placeholder name
};

extern vector<Squad *>	squads_cf6478;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

bool containsValue_ints(vector<int> &v, int value);	// NOTE: placeholder name (0x9d55a0 area, folded with OpX5_containsRecord)
int indexOfMinInt(vector<int> &v);					// NOTE: placeholder name (OpS8c_indexOfMinInt)
int randomElement_ints(vector<int> &v);				// NOTE: placeholder name (folded with OpU8a_randomRec)
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);

class BS
{
public:
	Squad *unknown68cf70(vector<int> types, const Point &pos);	// NOTE: placeholder name
};

Squad *BS::unknown68cf70(vector<int> types, const Point &pos)
{
	vector<int> candidates;
	Squad *result;
	for (int i = 0; i < squads_cf6478.size(); i++)
	{
		if (containsValue_ints(types,squads_cf6478[i]->type) && !squads_cf6478[i]->unknown45e820())
			candidates.push_back(i);
	}
	result = NULL;
	if (!candidates.empty())
	{
		int best;
		vector<HEntity> *members;
		if (rng.chance(66))
		{
			vector<int> distances;
			for (unsigned int j = 0; j < candidates.size(); j++)
				distances.push_back(OpQ1_distanceCeil_40a3f0(pos,squads_cf6478[candidates[j]]->leader->getPosition()));
			best = indexOfMinInt(distances);
			result = squads_cf6478[candidates[best]];
			members = result->leader->getGroup()->getMembers();
			for (unsigned int k = 0; k < members->size(); k++)
			{
				if ((*members)[k]->getAI()->getFollowEntity() == result->leader)
					(*members)[k]->getAI()->unknown5b5220();
			}
		}
		else
			result = squads_cf6478[randomElement_ints(candidates)];
	}
	return result;
}
