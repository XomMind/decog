// op_r4_p: pathing helpers in 0x6fe000-0x777000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../pathing/cartographer2d.h"
using namespace std;

extern Cartographer2D opR4p_cartographer;	// NOTE: placeholder name (0xcfe568)
extern Cartographer2DMoveCost *opR4p_moveCostA;	// NOTE: placeholder name (0xcefc30)
extern Cartographer2DMoveCost *opR4p_moveCostB;	// NOTE: placeholder name (0xcefc3c)
extern CellTerrainRecord *opR4p_terrainCefb9c;	// NOTE: placeholder name (0xcefb9c)
extern bool opR4p_flags_caf17c[];	// NOTE: placeholder name

struct OpR4p_Info	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int type;	// NOTE: placeholder name
};

class OpR4p_HInfo	// NOTE: placeholder name
{
public:
	int ID;
	OpR4p_Info *operator->() const;	// 0x9b7910
};

struct OpR4p_Waypoint : public Point	// NOTE: placeholder name
{
	OpR4p_HInfo info;
};

void opR4p_setTerrain(const Point &p, CellTerrainRecord *terrain);	// NOTE: placeholder name (0x6c9c90)

class OpR4p_Route	// NOTE: placeholder name
{
public:
	char pad0[8];
	Point start;
	vector<OpR4p_Waypoint *> waypoints;

	void carvePaths();	// NOTE: placeholder name (0x700e30)
};

void OpR4p_Route::carvePaths()
{
	vector<OpR4p_Waypoint> unreachable;
	for (unsigned int i = 0; i < waypoints.size(); i++)
	{
		if (opR4p_flags_caf17c[waypoints[i]->info->type])
		{
			vector<Point> path;
			if (!opR4p_cartographer.findPath(start,*waypoints[i],opR4p_moveCostA,0,path))
			{
				unreachable.push_back(*waypoints[i]);
				break;
			}
		}
	}
	for (unsigned int j = 0; j < unreachable.size(); j++)
	{
		vector<Point> path;
		if (!opR4p_cartographer.findPath(start,unreachable[j],opR4p_moveCostB,0,path))
		{
		}
		else
		{
		for (unsigned int k = 0; k < path.size(); k++)
		{
			if (!cells(path[k])->isPassableFor(HEntity()))
				opR4p_setTerrain(path[k],opR4p_terrainCefb9c);
		}
		}
	}
}

struct OpR4p_Mark	// NOTE: placeholder name
{
	int stamp;
	int type;
	int unknown8, unknownc, unknown10;	// NOTE: placeholder names
};

template <class T>
class OpR4p_Grid	// NOTE: placeholder name
{
public:
	int width;
	int height;
	T *data;
	T &operator()(const Point &p);	// 0x9d2930
};

class OpR4p_World	// NOTE: placeholder name (BS)
{
public:
	char pad0[0x740];
	OpR4p_Grid<OpR4p_Mark> marks;	// NOTE: placeholder name

	void clearMarkRun(vector<Point> &path);	// NOTE: placeholder name (0x71fe20)
};

void OpR4p_World::clearMarkRun(vector<Point> &path)
{
	if (marks(path[0]).type == 5)
	{
		marks(path[0]).stamp = 0;
		if (path.size() > 1)
		{
			for (unsigned int i = 1; i < path.size(); i++)
			{
				if (marks(path[i]).type == 5)
					marks(path[i]).stamp = 0;
			}
		}
	}
}

class OpR4p_HEntity	// NOTE: placeholder name
{
public:
	int ID;
	bool operator==(OpR4p_HEntity other) const;	// 0x45a390 (HEntity::operator==)
	bool operator!=(OpR4p_HEntity other) const;	// HEntity::operator!=
};

class OpR4p_HProp	// NOTE: placeholder name
{
public:
	int ID;
	OpR4p_HProp();	// 0x9b6590
};

class OpR4p_MachineData	// NOTE: placeholder name
{
public:
	char pad0[4];
	int unknown4;	// NOTE: placeholder name
	char pad8[0x25 - 8];
	bool announced;	// NOTE: placeholder name

	bool unknown46ecb0();	// NOTE: placeholder name
};

class OpR4p_HMachine	// NOTE: placeholder name
{
public:
	int ID;
	OpR4p_MachineData *operator->() const;	// 0x9b7910
};

struct OpR4p_MachineMarker	// NOTE: placeholder name
{
	Point pos;
	OpR4p_HEntity machine;
};

class OpR4p_CellP	// NOTE: placeholder name
{
public:
	void unknown66b640();	// NOTE: placeholder name
};

class OpR4p_CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	OpR4p_CellP *&operator()(const Point &p);	// 0x9ced70
};
extern OpR4p_CellGrid opR4p_cells;	// NOTE: placeholder name
extern OpR4p_HEntity opR4p_gameHandle;	// NOTE: placeholder name (0xd1e888)
extern string opR4p_messageTable[];	// NOTE: placeholder name (0xcfaca0)
void opR4p_unknown5141b0(int id, const string *a, int b, int c, OpR4p_HProp e, int d);	// NOTE: placeholder name (0x5141b0)

class OpR4p_Level	// NOTE: placeholder name (BS)
{
public:
	char pad0[0x10];
	vector<OpR4p_MachineMarker *> markers;	// NOTE: placeholder name

	void announceMachine(OpR4p_HMachine machine);	// NOTE: placeholder name (0x71dd30)
};

void OpR4p_Level::announceMachine(OpR4p_HMachine machine)
{
	if (!machine->announced && opR4p_gameHandle != *(OpR4p_HEntity *)&machine)
		do { opR4p_unknown5141b0(8,&opR4p_messageTable[machine->unknown4],0,0,OpR4p_HProp(),0); } while (0);
	machine->announced = true;
	if (!machine->unknown46ecb0())
	{
		for (unsigned int i = 0; i < markers.size(); i++)
		{
			if (markers[i]->machine == *(OpR4p_HEntity *)&machine)
				opR4p_cells(markers[i]->pos)->unknown66b640();
		}
	}
}
