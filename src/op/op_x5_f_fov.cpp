// op_x5_f_fov: CFovEnemiesButton::input (0x98a5f0) of COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../engine/xcolor.h"
using namespace std;

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);	// 0x46ca50 (ICF with the copy ctor)
	bool operator==(const Point &p);	// 0x409b90
};

struct XEvent	// NOTE: placeholder name
{
	int type;
};

struct EntityData4563c0;

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputKey(int key, int mode);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	virtual ~Console();
	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);	// NOTE: placeholder name

	char pad60[0x6c - 0x60];
};

class CFovEnemiesButton : public Console
{
public:
	CFovEnemiesButton(XConsole *parent, int x, const string &text);
	virtual ~CFovEnemiesButton();
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
};

class Entity	// NOTE: partial
{
public:
	const Point &getPosition();	// 0x45a4a0
};

class HEntity
{
public:
	int ID;
	Entity *operator->() const;	// 0x9b6570
};

class Area	// NOTE: placeholder name (two corner points)
{
public:
	Area();	// 0x40b100
	bool contains_40b750(const Point &p);	// NOTE: placeholder name

	Point min;
	Point max;
};

class CMap : public Console	// NOTE: partial layout
{
public:
	void centerPush_805020(Point *out);	// NOTE: placeholder name
	void unknown8051f0(Point *min, Point *max);	// NOTE: placeholder name
	bool unknown806d00(vector<Point> &points, bool flag);	// NOTE: placeholder name
	void unknown8069e0(Point p, bool flag);	// NOTE: placeholder name
	void unknown807f40(vector<EntityData4563c0*> &entities);	// NOTE: placeholder name
};
extern CMap *opx5f_cec054;	// NOTE: placeholder name (0xcec054)

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getPlayer();	// 0x4630f0
	bool unknown71bbd0();	// NOTE: placeholder name
	void unknown726520();	// NOTE: placeholder name
	vector<HEntity> *unknown4636b0();	// NOTE: placeholder name
};
extern Map *opx5f_world;	// NOTE: placeholder name (0xcefc4c)

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
void OpV4c_Fn9d5460(vector<Point> &list, unsigned int index, Point p);	// NOTE: placeholder name (0x9d5460)
template <class T> void OpX5_insertAt(vector<T> &v, int index, T value);	// NOTE: placeholder name (0x9d5...)
bool OpX5_addUniqueEntityData(vector<EntityData4563c0*> &v, EntityData4563c0 *e);	// NOTE: placeholder name
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name (0x4541b0)

bool CFovEnemiesButton::input(void *event)
{
	if (opx5f_world->unknown71bbd0())
		return false;
	switch (((XEvent*)event)->type)
	{
	case 0xcc:
		opx5f_world->unknown726520();
		if (!opx5f_world->unknown4636b0()->empty())
		{
			Point mean = (*opx5f_world->unknown4636b0())[0]->getPosition();
			for (unsigned int i = 1; i < opx5f_world->unknown4636b0()->size(); i++)
			{
				mean.x += (*opx5f_world->unknown4636b0())[i]->getPosition().x;
				mean.y += (*opx5f_world->unknown4636b0())[i]->getPosition().y;
			}
			mean.x /= opx5f_world->unknown4636b0()->size();
			mean.y /= opx5f_world->unknown4636b0()->size();
			Point old;
			opx5f_cec054->centerPush_805020(&old);
			opx5f_cec054->unknown8069e0(mean,true);
			Area region;
			opx5f_cec054->unknown8051f0(&region.min,&region.max);
			bool shown = false;
			for (unsigned int i = 0; i < opx5f_world->unknown4636b0()->size(); i++)
			{
				if (region.contains_40b750((*opx5f_world->unknown4636b0())[i]->getPosition()))
				{
					shown = true;
					break;
				}
			}
			if (!shown)
			{
				opx5f_cec054->unknown8069e0(old,true);
				Point cent;
				opx5f_cec054->centerPush_805020(&cent);
				vector<Point> sortedList;
				vector<int> dists;
				Point next;
				int distance;
				for (unsigned int i = 0; i < opx5f_world->unknown4636b0()->size(); i++)
				{
					next = (*opx5f_world->unknown4636b0())[i]->getPosition();
					distance = OpQ1_distanceCeil_40a3f0(cent,next);
					if (sortedList.empty() || distance <= dists.back())
					{
						sortedList.push_back(next);
						dists.push_back(distance);
					}
					else
					{
						for (unsigned int j = 0; j < sortedList.size(); j++)
						{
							if (distance > dists[j])
							{
								OpV4c_Fn9d5460(sortedList,j,next);
								OpX5_insertAt(dists,j,distance);
								break;
							}
						}
					}
				}
				if (opx5f_cec054->unknown806d00(sortedList,false))
					opx5f_cec054->unknown8051f0(&region.min,&region.max);
			}
			Point destination;
			opx5f_cec054->centerPush_805020(&destination);
			if (destination == old)
				opx5f_cec054->unknown8069e0(opx5f_world->getPlayer()->getPosition(),false);
			else
			{
				vector<EntityData4563c0*> visible;
				for (unsigned int i = 0; i < opx5f_world->unknown4636b0()->size(); i++)
				{
					if (region.contains_40b750((*opx5f_world->unknown4636b0())[i]->getPosition()))
						OpX5_addUniqueEntityData(visible,*(EntityData4563c0**)&(*opx5f_world->unknown4636b0())[i]);
				}
				opx5f_cec054->unknown807f40(visible);
				opR1d_4541b0(0x39,0,0);
			}
		}
		return true;
	}
	return false;
}
