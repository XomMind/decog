// team_d_39: Entity member 0x5e3830 (chain nearby xom candidates and draw the activation effect).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();						// NOTE: placeholder name (0x453b40)
	Point(int x_, int y_);			// 0x46ca20
	Point(const Point &p) throw();	// 0x46ca50
};

struct Area39	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;

	Area39();	// NOTE: placeholder name (0x40b100)
};

class Entity;

class HEntity
{
	int ID;
public:
	bool isValid() const;
	Entity *operator->() const;
};

class HItem
{
	int ID;
public:
	bool isNull() const;
};

class Entity
{
public:
	char	pad00[4];
	HEntity	self;	// +0x04

	Point &getPosition();
	bool unknown45aaa0(HEntity e);	// NOTE: placeholder name
	bool isXomCandidate();			// 0x5d51a0
	HItem unknown5d5d40();			// NOTE: placeholder name
	Point unknown45a4c0();			// NOTE: placeholder name
	bool unknown5e3830();			// NOTE: placeholder name
};

class Cell
{
public:
	HEntity getEntity();
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getRect(const Point &center, int radius, Area39 *out);	// NOTE: placeholder name (0x9b4430)
	Cell **at(int x, int y);		// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

class Map39	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	bool isVisible(const Point &p);	// 0x4631c0
	void unknown7170a0(HEntity from, const Point &to, vector<Point> *path, vector<int> *a, vector<int> *b, Point *p, int c, int d, bool e, bool f);	// NOTE: placeholder name
};
extern Map39 *world39;	// NOTE: placeholder name (0xcefc4c)

class Effect39	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class EffectMgr39	// NOTE: placeholder name (0xcefc50)
{
public:
	Effect39 *create();	// NOTE: placeholder name (0x508610)
};
extern EffectMgr39 *effectMgr39_cefc50;	// NOTE: placeholder name
extern Point point_d2e20c;	// NOTE: placeholder name

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);
bool OpU8a_containsEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d31e0)
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)
template <class T> void OpV4c_shuffle(vector<T> &v);	// NOTE: placeholder name
void OpD_insertEntity_9d8fc0(vector<HEntity> &v, int index, HEntity e);	// NOTE: placeholder name (0x9d8fc0)

bool Entity::unknown5e3830()
{
	vector<HEntity> enemies;
	Area39 area;
	cells_cfd44c.getRect(getPosition(),10,&area);
	for (int x = area.x1; x <= area.x2; x++)
	{
		for (int y = area.y1; y <= area.y2; y++)
		{
			if ((*cells_cfd44c.at(x,y))->getEntity().isValid() && unknown45aaa0((*cells_cfd44c.at(x,y))->getEntity()) && (*cells_cfd44c.at(x,y))->getEntity()->isXomCandidate()
				&& (*cells_cfd44c.at(x,y))->getEntity()->unknown5d5d40().isNull() && !OpU8a_containsEntity(enemies,(*cells_cfd44c.at(x,y))->getEntity())
				&& OpQ1_distanceCeil_40a3f0(getPosition(),Point(x,y)) <= 10)
				enemies.push_back((*cells_cfd44c.at(x,y))->getEntity());
		}
	}
	if (enemies.empty())
		return false;
	int source;
	OpU8a_lookup2("TCS_Activate",&source);
	if (source)
	{
		OpV4c_shuffle(enemies);
		OpD_insertEntity_9d8fc0(enemies,0,self);
		enemies.push_back(self);
		for (unsigned int i = 1; i < enemies.size(); i++)
		{
			vector<Point> parts;
			vector<int> first;
			vector<int> value;
			Point x;
			world39->unknown7170a0(enemies[i - 1],enemies[i]->unknown45a4c0(),&parts,&first,&value,&x,0,4,true,true);
			for (unsigned int j = 1; j < parts.size() - 1; j++)
			{
				if (world39->isVisible(parts[j]))
					effectMgr39_cefc50->create()->init(effectMgr39_cefc50,source,parts[j],point_d2e20c,NULL,NULL,NULL,value[j],0);
			}
		}
	}
	return true;
}
