// team_d_75: BS member 0x739e50: places weighted squads (spawned at 130,39) for a given level.
// NOTE: class layouts are partial; member and method names are placeholders. OpR5h_WL is declared
// with the layout used in the op_ files (implicit destructor generated here).
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct Pos : public Point
{
	Pos(int x_, int y_);
};

struct OpQ1_Box
{
	int x1;
	int y1;
	int x2;
	int y2;

	OpQ1_Box(int a, int b, int c, int d);
};

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL(vector<int> &w);	// 0x9baaa0
	T &pick();
};

class Entity;
class EntityAI;

class HEntity
{
public:
	int ID;
	HEntity();	// NOTE: folded with HProp::HProp
	bool isValid() const;
	void resetField();	// NOTE: placeholder name (Sweep_9b7270::resetField)
	Entity *operator->() const;
};

class EntityAI
{
public:
	void setFollowEntity(HEntity followEntity_, int followParam_);
	void unknown459410(const OpQ1_Box &area);	// NOTE: placeholder name
};

class Entity
{
public:
	EntityAI *getAI();
};

class CellGrid75	// NOTE: placeholder name (0xcfd44c)
{
public:
	int getWidth();
	int getHeight();
};
extern CellGrid75 cells75_cfd44c;	// NOTE: placeholder name

struct EntityRec75;	// NOTE: placeholder name

class BS
{
public:
	EntityRec75 *selectRobotOfClass(bool flag, int id, bool a, bool b);	// NOTE: placeholder name (OpX4b_World::selectRobotOfClass)
	HEntity placeEntity(EntityRec75 *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
	void unknown739e50(int level);	// NOTE: placeholder name
};

void BS::unknown739e50(int level)
{
	Pos dest(0x82,0x27);
	vector< vector<int> > vec;
	vector<int> table;
	switch (level)
	{
	case 1:
		vec.push_back(vector<int>());
		vec.back().push_back(13);
		vec.back().push_back(13);
		vec.back().push_back(0x18);
		vec.back().push_back(0x16);
		vec.back().push_back(0x18);
		vec.back().push_back(0x10);
		vec.back().push_back(0x10);
		vec.back().push_back(0x10);
		vec.back().push_back(0x10);
		vec.back().push_back(0x10);
		table.push_back(100);
		break;
	default:
		vec.push_back(vector<int>());
		vec.back().push_back(0x19);
		vec.back().push_back(0x19);
		vec.back().push_back(0x18);
		vec.back().push_back(0x18);
		vec.back().push_back(0x18);
		vec.back().push_back(0x10);
		vec.back().push_back(0x10);
		vec.back().push_back(0x10);
		vec.back().push_back(0x10);
		vec.back().push_back(0x10);
		vec.back().push_back(0x11);
		vec.back().push_back(0x12);
		table.push_back(100);
		break;
	}
	OpR5h_WL<int> mode(table);
	int num = (level >= 2) + 1;
	HEntity e2;
	HEntity parent;
	OpQ1_Box first(0,0,cells75_cfd44c.getWidth() - 1,cells75_cfd44c.getHeight() - 1);
	OpQ1_Box temp(0x2d,0x25,0x4e,0x47);
	OpQ1_Box &offset = level > 2 ? first : temp;
	EntityRec75 *part;
	for (int i = 0; i < num; i++)
	{
		bool ok = level <= 2;
		int idx = mode.pick();
		parent.resetField();
		for (unsigned int j = 0; j < vec[idx].size(); j++)
		{
			part = selectRobotOfClass(true,vec[idx][j],false,true);
			if (part)
			{
				e2 = placeEntity(part,dest,3,false,3,0xe,false);
				if (e2.isValid())
				{
					if (j == 0 && ok)
						parent = e2;
					else if (parent.isValid())
						e2->getAI()->setFollowEntity(parent,0);
					e2->getAI()->unknown459410(offset);
				}
			}
		}
	}
}
