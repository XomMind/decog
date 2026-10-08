// op_map_scroll: 0x872ef0, shifts the map view offset in a direction according to the map-shift option
// (called from the CMap input handler) (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
// Point/HEntity/Entity/Array2D are private types with throw() declarations: LTCG must prove every call after
// the bounds vector nothrow (the exe has no EH state for it), and any TU declaring the shared names without
// throw() would add one.
#include <stdlib.h>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_) throw();	// 0x46ca20
	explicit Pos(int v) throw();	// 0x409990
};
struct OpMS_Point
{
	int x;
	int y;
	OpMS_Point() throw();	// 0x453b40
	OpMS_Point(const OpMS_Point &p) throw();	// 0x46ca50
	OpMS_Point &set_46ca50(const Pos &p) throw();	// NOTE: placeholder name (folded with the copy ctor)
	OpMS_Point &set_46ca50(const OpMS_Point &p) throw();	// NOTE: placeholder name (folded with the copy ctor)
	OpMS_Point &operator+=(const Pos &p) throw();	// 0x409a30
	OpMS_Point subtract_409b30(const Pos &p) const throw();	// NOTE: placeholder name
};

class OpMS_Entity
{
public:
	const OpMS_Point &getPosition() throw();	// 0x45a4a0
};
class OpMS_HEntity
{
public:
	int ID;
	OpMS_Entity *operator->() const throw();	// 0x9b6570
};

template<class T> class OpMS_Array2D
{
public:
	T *at(int x, int y) throw();
};

class OpMS_Map	// NOTE: placeholder name (Map at 0xcefc4c)
{
public:
	OpMS_HEntity getPlayer() throw();	// 0x4630f0
	OpMS_Array2D<int> *unknown463850() throw();	// NOTE: placeholder name
	int unknown463870() throw();	// NOTE: placeholder name
	int unknown463690() throw();	// NOTE: placeholder name
};
extern OpMS_Map *opMS_map;	// NOTE: placeholder name

class OpMS_Grid	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getBounds(const OpMS_Point &center, int radius, OpMS_Point &topLeft, OpMS_Point &bottomRight) throw();	// NOTE: placeholder name (0x9b7a40)
};
extern OpMS_Grid opMS_grid;	// NOTE: placeholder name

class OpMS_CMap	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	void unknown8069e0(OpMS_Point p, bool flag) throw();	// NOTE: placeholder name
	void unknown8051f0(OpMS_Point *min, OpMS_Point *max) throw();	// NOTE: placeholder name
};
extern OpMS_CMap *opMS_cmap;	// NOTE: placeholder name

struct OpMS_Dir { int x; int y; };	// NOTE: placeholder name
extern OpMS_Dir opMS_dirs_d015d8[];	// NOTE: placeholder name
extern bool opMS_enabled_d28c8a;	// NOTE: placeholder name
extern int opMS_range_d28e38;	// NOTE: placeholder name
extern void *opMS_cebd5c;	// NOTE: placeholder name
extern int opMS_mode_d28e30;	// NOTE: placeholder name
extern int opMS_mode_d28e34;	// NOTE: placeholder name
extern int opMS_lastDir_d1d9ec;	// NOTE: placeholder name

int ops7_clamp_9cdc80(int low, int value, int high);	// NOTE: placeholder name
int opMS_sumVector_9cdbd0(vector<int> &v) throw();	// NOTE: placeholder name (OpT8a_sumVector)

class OpMS_View	// NOTE: placeholder name
{
public:
	void shift_872ef0(int dir, int amount, bool flag);	// NOTE: placeholder name

	char pad00[0x1c];
	OpMS_Point offset;	// +0x1c
	char pad24[0x26 - 0x24];
	bool locked;	// +0x26
	char pad27[0x2c - 0x27];
	int dir;	// +0x2c
};

void OpMS_View::shift_872ef0(int dir_, int amount, bool flag)
{
	if (opMS_enabled_d28c8a && !locked)
	{
		int range = opMS_range_d28e38;
		int mode = opMS_cebd5c == 0 ? opMS_mode_d28e30 : opMS_mode_d28e34;
		switch (mode)
		{
			break;
			case 1:
			case 2:
			{
				Pos delta(-range * opMS_dirs_d015d8[dir_].x,-range * opMS_dirs_d015d8[dir_].y);
				if (mode == 2 && flag && dir != 8 && (abs(dir_ - dir) == 1 || abs(dir_ - dir) == 7))
				{
					delta.x += (offset.x - delta.x) / 2;
					delta.y += (offset.y - delta.y) / 2;
				}
				offset.set_46ca50(delta);
				opMS_cmap->unknown8069e0(opMS_map->getPlayer()->getPosition(),false);
				break;
			}
			case 3:
			{
				int chance = -(amount * 2);
				offset += Pos(opMS_dirs_d015d8[dir_].x * chance,opMS_dirs_d015d8[dir_].y * chance);
				switch (dir_)
				{
					case 0:
					case 4:
						if (offset.x > 0)
							offset.x--;
						else if (offset.x < 0)
							offset.x++;
						break;
					case 2:
					case 6:
						if (offset.y > 0)
							offset.y--;
						else if (offset.y < 0)
							offset.y++;
						break;
					default:
						if (offset.x > offset.y)
							offset.x--;
						else if (offset.x < offset.y)
							offset.y--;
				}
				offset.x = ops7_clamp_9cdc80(-range,offset.x,range);
				offset.y = ops7_clamp_9cdc80(-range,offset.y,range);
				vector<int> xx(4,-1);
				OpMS_Array2D<int> *base = opMS_map->unknown463850();
				int pick = opMS_map->unknown463870();
				OpMS_Point p;
				OpMS_Point y2;
				int v1 = opMS_map->unknown463690();
				opMS_grid.getBounds(opMS_map->getPlayer()->getPosition(),v1,p,y2);
				for (int y = p.y; y <= y2.y; y++)
				{
					for (int x = p.x; x <= y2.x; x++)
					{
						if (*base->at(x,y) == pick)
						{
							xx[0] = y;
							goto top;
						}
					}
				}
top:
				for (int y = y2.y; y >= p.y; y--)
				{
					for (int x = p.x; x <= y2.x; x++)
					{
						if (*base->at(x,y) == pick)
						{
							xx[2] = y;
							goto bottom;
						}
					}
				}
bottom:
				for (int x = p.x; x <= y2.x; x++)
				{
					for (int y = p.y; y <= y2.y; y++)
					{
						if (*base->at(x,y) == pick)
						{
							xx[3] = x;
							goto left;
						}
					}
				}
left:
				for (int x = y2.x; x >= p.x; x--)
				{
					for (int y = p.y; y <= y2.y; y++)
					{
						if (*base->at(x,y) == pick)
						{
							xx[1] = x;
							goto right;
						}
					}
				}
right:
				opMS_cmap->unknown8069e0(opMS_map->getPlayer()->getPosition(),false);
				OpMS_Point v;
				OpMS_Point last;
				opMS_cmap->unknown8051f0(&v,&last);
				while (xx[0] < v.y && xx[2] < last.y)
				{
					v.y--;
					last.y--;
					offset.y++;
				}
				while (xx[2] > last.y && xx[0] > v.y)
				{
					v.y++;
					last.y++;
					offset.y--;
				}
				while (xx[3] < v.x && xx[1] < last.x)
				{
					v.x--;
					last.x--;
					offset.x++;
				}
				while (xx[1] > last.x && xx[3] > v.x)
				{
					v.x++;
					last.x++;
					offset.x--;
				}
				opMS_cmap->unknown8069e0(opMS_map->getPlayer()->getPosition(),false);
				break;
			}
			case 4:
			OpMS_Array2D<int> *base = opMS_map->unknown463850();
			int tag = opMS_map->unknown463870();
			OpMS_Point p;
			OpMS_Point h2;
			int ty = opMS_map->unknown463690();
			opMS_grid.getBounds(opMS_map->getPlayer()->getPosition(),ty,p,h2);
			vector<int> vec(h2.x - p.x + 1,0);
			vector<int> parts(h2.y - p.y + 1,0);
			for (int x = p.x, i = 0; x <= h2.x; x++, i++)
			{
				for (int y = p.y, j = 0; y <= h2.y; y++, j++)
				{
					if (*base->at(x,y) == tag)
					{
						vec[i]++;
						parts[j]++;
					}
				}
			}
			int total2 = opMS_sumVector_9cdbd0(vec) / 2;
			int u = opMS_sumVector_9cdbd0(parts) / 2;
			Pos cx(-1);
			for (unsigned int i = 0; i < vec.size(); i++)
			{
				total2 -= vec[i];
				if (total2 <= 0)
				{
					cx.x = p.x + i;
					break;
				}
			}
			for (unsigned int i = 0; i < parts.size(); i++)
			{
				u -= parts[i];
				if (u <= 0)
				{
					cx.y = p.y + i;
					break;
				}
			}
			offset.set_46ca50(opMS_map->getPlayer()->getPosition().subtract_409b30(cx));
			opMS_cmap->unknown8069e0(opMS_map->getPlayer()->getPosition(),false);
			break;
		}
	}
	opMS_lastDir_d1d9ec = dir_;
}
