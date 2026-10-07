// op_r2_f: Cartographer2D move cost callbacks and map/entity helpers in 0x600000-0x650000 (COGMIND.exe Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

struct Point
{
	int x;
	int y;

	Point();
	Point(int v);
	Point(int x_, int y_);
	Point(const Point &p);
	Point &operator=(const Point &p);
	bool operator!=(const Point &p) const;
};

bool unknown4373c0(const Point &a, const Point &b);
void OpQ1_lineBresenhamPoints_40ff30(const Point &from, const Point &to, vector<Point> &line);	// NOTE: placeholder name	// NOTE: placeholder name (adjacency test)

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const Point &p);	// 0x9ced70
	T &operator()(int x, int y);
	int getWidth();		// NOTE: placeholder name (0x9fcd80)
	int getHeight();	// NOTE: placeholder name (0x9b8f00)
};

class Entity;
class Prop;
class Map;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool isValid() const;
	Entity *operator->() const;
};

class OpR2_Item	// NOTE: placeholder name
{
public:
	int unknown44aec0();							// NOTE: placeholder name (trivial getter)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class HItem
{
	int	ID;
public:
	HItem();
	bool isValid() const;
	OpR2_Item *operator->() const;	// 0x9b65b0
};

struct OpR2_PropData	// NOTE: placeholder name
{
	char	pad[0xf4];
	int		interactType;
};

class Prop
{
public:
	OpR2_PropData *getData();	// NOTE: placeholder name (0x9b8f00)
	const string &getName();	// NOTE: placeholder name (0x45c590)
};

class HProp
{
	int	ID;
public:
	HProp();
	bool isValid() const;
	Prop *operator->() const;	// 0x9b64f0
};

class OpR2_Group	// NOTE: placeholder name
{
public:
	int getType();	// NOTE: placeholder name (ICF'd trivial getter)
	void unknown6716f0(HEntity e);	// NOTE: placeholder name
};

class OpR2_HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	bool isValid() const;
	OpR2_Group *operator->() const;	// 0x9b7250
};

struct EntityEffect	// NOTE: placeholder layout
{
	int	unknown0;
	int	duration;	// NOTE: placeholder name
};

struct OpR2_DamageInfo	// NOTE: placeholder name
{
	char	pad00[0x64];
	bool	unknown64;	// NOTE: placeholder name
	bool	unknown65;	// NOTE: placeholder name
	char	pad66[0x68 - 0x66];
	int		unknown68;	// NOTE: placeholder name
	int		unknown6c;	// NOTE: placeholder name
};

class OpR2_AI	// NOTE: placeholder name (EntityAI)
{
public:
	void willDie(bool flag);
};

class Entity
{
	int					unknown00;
	HEntity				self;			// +4
	char				pad08[0x28 - 0x08];
	OpR2_HGroup			group;			// NOTE: placeholder name
	char				pad2c[0x30 - 0x2c];
	vector<Point>		footprint;		// NOTE: placeholder name
	char				pad40[0x8c - 0x40];
	int					unknown8c;		// NOTE: placeholder name
	char				pad90[0x134 - 0x90];
	vector<HItem>		inventory;		// NOTE: placeholder name
	OpR2_AI				*ai;			// NOTE: placeholder name
public:
	void unknown637a50();	// NOTE: placeholder name
	void unknown637bb0();	// NOTE: placeholder name
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	bool unknown5cb680(OpR2_HGroup g);		// NOTE: placeholder name
	void unknown637d10(OpR2_DamageInfo *info, int damage);	// NOTE: placeholder name
	int takeDamage(int a, int b, int c, int d, int e, int f, int g, bool h, HProp i, int j, int k, int l, int m, int n);	// 0x5e5520
	bool isPlayer();					// 0x5c7600
	int getSize();						// NOTE: placeholder name (0x45a360)
	HEntity unknown45a260();			// NOTE: placeholder name
	int unknown45a3a0();				// NOTE: placeholder name
	OpR2_HGroup getGroup();				// NOTE: placeholder name
	const Point &getPosition();			// 0x45a4a0
	bool isHostileTo(HEntity e);		// 0x45aa70
	bool isXomCandidate();				// NOTE: placeholder name (0x5d51a0)
	void *getAI();						// NOTE: placeholder name (0x45b590)
};

class Cell
{
public:
	void clearEntity();				// NOTE: placeholder name
	bool unknown66b3d0(Entity *e);	// NOTE: placeholder name
	bool canCaveIn();				// 0x66af50
	bool isPassableFor(HEntity e);	// 0x66ab30
	bool isPassableWithoutEntity();	// NOTE: placeholder name (0x66ac40)
	bool isOpen();					// NOTE: placeholder name (0x4550b0)
	int getTerrain();				// NOTE: placeholder name (0x9fcd80)
	HProp getProp();				// 0x45d550
	HEntity getEntity();			// 0x45d250
	bool isEdge();					// NOTE: placeholder name (0x45dc30)
	bool isMachinePart();			// NOTE: placeholder name (0x45dcd0)
	bool isShortcut();				// NOTE: placeholder name (0x45dc50)
	bool unknown45dc70();			// NOTE: placeholder name
};

struct OpR2_MapRecord	// NOTE: placeholder name; element of the grid at world+0x7c4
{
	char	pad00[0x30];
	bool	unknown30;	// NOTE: placeholder name
};

struct OpR2_MapObject	// NOTE: placeholder name
{
	char	pad00[0x24];
	int		type;
};

class OpR2_Chance	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool unknown77f260(int value);	// NOTE: placeholder name
};

struct MapZone	// NOTE: placeholder
{
	char	pad[0xd];
	bool	unknownd;	// NOTE: placeholder name
};

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	bool isKnown(int x, int y);			// NOTE: placeholder name (0x463130)
	bool isVisible(int x, int y);		// NOTE: placeholder name (0x463190)
	HEntity getPlayer();				// NOTE: placeholder name (0x4630f0)
	Array2D<OpR2_MapRecord> &unknown463e70();	// NOTE: placeholder name
	bool unknown463e90(const Point &p);	// NOTE: placeholder name
	bool unknown4631f0(HEntity e);		// NOTE: placeholder name
	Array2D<bool> *unknown4637f0();		// NOTE: placeholder name
	MapZone *getZone(const Point &p);	// NOTE: placeholder name (0x462e30)
	void unknown7353a0(int x, int y);	// NOTE: placeholder name
	int unknown463e50();				// NOTE: placeholder name
	bool unknown463dc0(HEntity e);		// NOTE: placeholder name
	void unknown464800(HEntity e);		// NOTE: placeholder name
	void opw3_unknown729470(HEntity e, bool ownerOnly);	// NOTE: placeholder name
};

class OpR2_Allies	// NOTE: placeholder name (CAllies)
{
public:
	bool unknown48f040(HEntity e);	// NOTE: placeholder name
	void unknown7b7980();			// NOTE: placeholder name (CAllies::unknown7b7980)
};

class OpR2_Obj_cf6428	// NOTE: placeholder name
{
public:
	void unknown681b70(HEntity e, HProp p);	// NOTE: placeholder name
};

class OpR2_EntityPool	// NOTE: placeholder name (0xd21720)
{
public:
	void unknown9d0b30(HEntity e, bool flag);	// NOTE: placeholder name
};

class Cartographer2DMoveCost
{
public:
	virtual bool getNeighbors(int x, int y, int *neighborX, int *neighborY, void *data);	// NOTE: placeholder name
	virtual bool isPassable(int x, int y, void *data) = 0;	// NOTE: placeholder name
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost) = 0;	// NOTE: placeholder name
};

extern Array2D<Cell *>	cells;				// NOTE: placeholder name (0xcfd44c)
extern Map				*world;
extern OpR2_Allies		*opr2_allies;		// NOTE: placeholder name (0xcec0c8)
extern OpR2_Obj_cf6428	opr2_cf6428;		// NOTE: placeholder name
extern OpR2_EntityPool	opr2_entityPool;	// NOTE: placeholder name (0xd21720)
extern vector<HEntity>	opr2_cf6adc;		// NOTE: placeholder name
bool OpR2_eraseEntity(vector<HEntity> &v, HEntity e);	// NOTE: placeholder name (0x9d2f00)				// NOTE: placeholder name (0xcefc4c)
extern bool				opr2_d28e46;		// NOTE: placeholder name
extern vector<OpR2_MapObject *>	opr2_mapObjects;	// NOTE: placeholder name (0xcf4a04)
extern OpR2_Chance		opr2_cf45d8;		// NOTE: placeholder name
extern int				TERRAIN_CAVE_WALL;	// NOTE: placeholder (0xcefba0)
extern int				TERRAIN_RUBBLE;		// NOTE: placeholder (0xcefb84)
extern OpR2_PropData	*subcavePropData;	// NOTE: placeholder (0xcefbd8)

//==================================================================
// Cartographer2DMoveCost callbacks
//==================================================================

class PathCheckCallback : public Cartographer2DMoveCost
{
public:
	virtual bool isPassable(int x, int y, void *data);
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};

bool PathCheckCallback::isPassable(int x, int y, void *data)
{
	return cells(x,y)->isPassableFor(HEntity());
}

bool PathCheckCallback::getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
{
	if (!isPassable(toX,toY,data))
		return false;
	cost = 1;
	return true;
}

class DesirePathCheckCallback : public Cartographer2DMoveCost
{
public:
	virtual bool isPassable(int x, int y, void *data);
};

bool DesirePathCheckCallback::isPassable(int x, int y, void *data)
{
	return cells(x,y)->isPassableWithoutEntity();
}

class NearestDamagedMachineCallback : public Cartographer2DMoveCost
{
public:
	virtual bool isPassable(int x, int y, void *data);
};

bool NearestDamagedMachineCallback::isPassable(int x, int y, void *data)
{
	return cells(x,y)->isOpen();
}

class CaveForcePathCallback : public Cartographer2DMoveCost
{
public:
	virtual bool isPassable(int x, int y, void *data);
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};

bool CaveForcePathCallback::isPassable(int x, int y, void *data)
{
	return true;
}

bool CaveForcePathCallback::getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
{
	cost = (int)((cells(toX,toY)->isPassableFor(HEntity()) ? 1 : (cells(toX,toY)->getProp().isValid() ? 1000000 : 10000)) * ((fromX != toX && fromY != toY) ? 1.5 : 1.0));
	return true;
}

class CaveinForcedPathCallback : public Cartographer2DMoveCost
{
public:
	virtual bool isPassable(int x, int y, void *data);
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};

bool CaveinForcedPathCallback::isPassable(int x, int y, void *data)
{
	return cells(x,y)->isPassableFor(HEntity()) ||
		(cells(x,y)->getProp().isValid() && cells(x,y)->getProp()->getData() == subcavePropData);
}

bool CaveinForcedPathCallback::getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
{
	if (!isPassable(toX,toY,data))
		return false;
	cost = (cells(toX,toY)->getProp().isValid() && cells(toX,toY)->getProp()->getData() == subcavePropData) ? 10000 : ((fromX != toX && fromY != toY) ? 3 : 2);
	return true;
}

class SubEntranceForcePathCallback : public Cartographer2DMoveCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};

bool SubEntranceForcePathCallback::getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
{
	cost = (int)((cells(toX,toY)->isPassableFor(HEntity()) ? 1 : ((cells(toX,toY)->getTerrain() != TERRAIN_RUBBLE) ? 1000000 : 20)) * ((fromX != toX && fromY != toY) ? 1.5 : 1.0));
	return true;
}

class EntityMovementCallback : public Cartographer2DMoveCost
{
public:
	bool isPassableAt(int x, int y, Entity *e);	// NOTE: placeholder name (0x64f0e0)
	virtual bool isPassable(int x, int y, void *data);
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost);
};

bool EntityMovementCallback::isPassableAt(int x, int y, Entity *e)
{
	if (cells(x,y)->isPassableFor(e->unknown45a260()))
	{
		if (e->isPlayer() && !world->isKnown(x,y))
			return false;
		if (cells(x,y)->isEdge())
		{
			switch (e->getGroup()->getType())
			{
			case 3:
			case 11:
			case 12:
				return true;
			case 4:
				return false;
			case 0:
			case 1:
			case 2:
				if (cells(x,y)->isShortcut() ||
					(cells(x,y)->unknown45dc70() && (opr2_mapObjects[14] != NULL || (opr2_cf45d8.unknown77f260(100) && e->isPlayer()))) ||
					(e->getAI() != NULL && cells(x,y)->getEntity().isValid() && e->isHostileTo(cells(x,y)->getEntity()) && e->isXomCandidate()))
					return world->unknown463e90(Point(x,y));
				else
					return false;
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 13:
			case 14:
				if (cells(x,y)->isShortcut())
					return true;
				else
				{
					if (e->getAI() != NULL && cells(x,y)->getEntity().isValid() && e->isHostileTo(cells(x,y)->getEntity()) && e->isXomCandidate())
						return true;
					return false;
				}
			default:
				return false;
			}
		}
		else
			return true;
	}
	else
		return false;
}

bool EntityMovementCallback::isPassable(int x, int y, void *data)
{
	if (((Entity *)data)->getSize() == 1)
		return isPassableAt(x,y,(Entity *)data);
	else
	{
		int size = ((Entity *)data)->getSize();
		if (x + size > cells.getWidth() || y + size > cells.getHeight())
			return false;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (!isPassableAt(x + i,y + j,(Entity *)data))
					return false;
			}
		}
		return true;
	}
}

bool EntityMovementCallback::getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
{
	if (!isPassable(toX,toY,data))
		return false;
	cost = (fromX != toX && fromY != toY) ? 3 : 2;
	for (int i = toX + ((Entity *)data)->getSize() - 1; i >= toX; i--)
	{
		for (int j = toY + ((Entity *)data)->getSize() - 1; j >= toY; j--)
		{
			if (cells(i,j)->unknown66b3d0((Entity *)data))
				cost += 50;
			if (cells(i,j)->getTerrain() == TERRAIN_CAVE_WALL)
				cost += ((Entity *)data)->unknown45a3a0();
			if (((Entity *)data)->isPlayer())
			{
				if (world->isVisible(i,j))
				{
					if (cells(i,j)->canCaveIn())
					{
						if (opr2_d28e46 && !unknown4373c0(world->getPlayer()->getPosition(),Point(i,j)))
							return false;
						else
							cost += 3;
					}
				}
				else if (world->unknown463e70()(i,j).unknown30)
				{
					if (opr2_d28e46)
						return false;
					cost += 3;
				}
			}
			else if (cells(i,j)->canCaveIn())
				cost += 3;
		}
	}
	return true;
}

//==================================================================
// Item type helpers
//==================================================================

class OpR2_AsciiImage	// NOTE: placeholder name (AsciiImage)
{
public:
	OpR2_AsciiImage &operator=(const OpR2_AsciiImage &other);
	char	data[0xc];
};

extern OpR2_AsciiImage	opr2_image_d1da88;	// NOTE: placeholder name
extern OpR2_AsciiImage	opr2_image_d2e9b0;	// NOTE: placeholder name

struct OpR2_ItemType	// NOTE: placeholder name; element of the vector at 0xd2d1c4
{
	char	pad00[0x44];
	int		type;			// NOTE: placeholder name
	char	pad48[0x4c - 0x48];
	int		unknown4c;		// NOTE: placeholder name
	int		unknown50;		// NOTE: placeholder name
	char	pad54[0x78 - 0x54];
	int		unknown78;		// NOTE: placeholder name
	OpR2_AsciiImage	image;	// NOTE: placeholder name
	char	pad88[0xd0 - 0x88];
	int		unknownd0;		// NOTE: placeholder name
	int		unknownd4;		// NOTE: placeholder name
	char	padd8[0xe8 - 0xd8];
	int		unknowne8;		// NOTE: placeholder name
	int		unknownec;		// NOTE: placeholder name
	int		unknownf0;		// NOTE: placeholder name
	int		unknownf4;		// NOTE: placeholder name
	char	padf8[0x128 - 0xf8];
	int		category;		// NOTE: placeholder name
	char	pad12c[0x13c - 0x12c];
	vector<int>	unknown13c;	// NOTE: placeholder name
	char	pad14c[0x150 - 0x14c];
	int		unknown150;		// NOTE: placeholder name
	int		unknown154;		// NOTE: placeholder name
	int		unknown158;		// NOTE: placeholder name
	char	pad15c[0x160 - 0x15c];
	int		unknown160;		// NOTE: placeholder name
	char	pad164[0x174 - 0x164];
	string	unknown174;		// NOTE: placeholder name
	int		unknown190;		// NOTE: placeholder name
	int		unknown194;		// NOTE: placeholder name

	int getRating();		// NOTE: placeholder name (0x457130)
};

extern vector<OpR2_ItemType *>	opr2_itemTypes;			// NOTE: placeholder name (0xd2d1c4)
extern int						opr2_ba4220[];			// NOTE: placeholder name
extern int						opr2_ba3bdc;			// NOTE: placeholder name
extern int						opr2_ba3b10;			// NOTE: placeholder name
extern bool						opr2_ba0968[];			// NOTE: placeholder name
extern RNG						rng;					// 0xd30908
template <class T> T OpR2_randomElement(vector<T> &v);	// NOTE: placeholder name (0x9d5d00)

void OpR2_unknown6037d0(vector<int> &ids, OpR2_ItemType *item)	// NOTE: placeholder name
{
	if (item->type == 12 || item->type == 13)
	{
		for (unsigned int i = 0; i < ids.size(); i++)
		{
			if (opr2_itemTypes[ids[i]]->type == item->type)
			{
				item->unknownd0 = opr2_itemTypes[ids[i]]->unknownd0;
				break;
			}
		}
		item->unknownd4 = 0;
	}
	else
	{
		item->unknownd0 = 0;
		item->unknownd4 = opr2_ba4220[item->type] * item->unknown4c;
	}
	if (item->type == 9)
	{
		item->unknownf0 = 118;
		item->unknownf4 = item->unknown4c * 5;
	}
	else
	{
		item->unknownf0 = 0;
		item->unknownf4 = 0;
	}
}

void OpR2_insertAt(vector<int> &v, int index, int value);	// NOTE: placeholder name (0x9dbdc0)

void OpR2_unknown603550(vector<int> &ids, vector<int> &sorted)	// NOTE: placeholder name
{
	sorted.push_back(ids[0]);
	for (unsigned int i = 1; i < ids.size(); i++)
	{
		int rating = opr2_itemTypes[ids[i]]->getRating();
		if (rating <= opr2_itemTypes[sorted.back()]->getRating())
			sorted.push_back(ids[i]);
		else
		{
			for (unsigned int j = 0; j < sorted.size(); j++)
			{
				if (rating >= opr2_itemTypes[sorted[j]]->getRating())
				{
					OpR2_insertAt(sorted,j,ids[i]);
					break;
				}
			}
		}
	}
}

//==================================================================
// Entity helpers
//==================================================================

void Entity::unknown637d10(OpR2_DamageInfo *info, int damage)
{
	takeDamage(1,0,0,(damage == -1) ? info->unknown68 : damage,info->unknown6c,0,0,!world->unknown4631f0(self),HProp(),info->unknown64 ? 1 : 0,8,0,0,info->unknown65);
}

void Entity::unknown637a50()
{
	if (footprint.front().x >= 0)
	{
		for (unsigned int i = 0; i < footprint.size(); i++)
			cells(footprint[i])->clearEntity();
	}
	if (group.isValid())
		group->unknown6716f0(self);
	if (world->unknown463e50())
	{
		if (footprint.front().x >= 0 && world->unknown4631f0(self) && world->getPlayer().operator->() && world->getPlayer()->unknown5cb680(group))
			world->unknown464800(self);
		if (opr2_allies->unknown48f040(self))
			opr2_allies->unknown7b7980();
		world->opw3_unknown729470(self,false);
	}
}

void Entity::unknown637bb0()
{
	unknown8c = 0;
	if (ai != NULL)
		ai->willDie(true);
	opr2_cf6428.unknown681b70(self,HProp());
	if (unknown45ac40(0x39) && !world->unknown463dc0(self))
		OpR2_eraseEntity(opr2_cf6adc,self);
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->unknown44aec0() == 4)
		{
			inventory[i]->unknown57dbe0(0,1,1,1);
			i--;
		}
	}
	while (!inventory.empty())
		inventory.front()->unknown57dbe0(0,1,1,1);
	unknown637a50();
	opr2_entityPool.unknown9d0b30(self,true);
}

//==================================================================
// Map helpers
//==================================================================

struct OpR2_Rect	// NOTE: placeholder name (Elem_9e3c60)
{
	int	x;
	int	y;
	int	width;
	int	height;
};

class OpR2_Obj_602ec0	// NOTE: placeholder name
{
public:
	void unknown602ec0(vector<OpR2_Rect> &rects);	// NOTE: placeholder name
};

void OpR2_Obj_602ec0::unknown602ec0(vector<OpR2_Rect> &rects)
{
	Array2D<bool> *seen = world->unknown4637f0();
	for (unsigned int i = 0; i < rects.size(); i++)
	{
		int maxX = rects[i].x + rects[i].width - 1;
		int maxY = rects[i].y + rects[i].height - 1;
		for (int x = rects[i].x; x <= maxX; x++)
		{
			for (int y = rects[i].y; y <= maxY; y++)
			{
				if (!world->isVisible(x,y))
				{
					(*seen)(x,y) = false;
					if (cells(x,y)->isMachinePart())
						world->getZone(Point(x,y))->unknownd = false;
					world->unknown7353a0(x,y);
				}
			}
		}
	}
}

class OpR2_WeightedTable	// NOTE: placeholder name
{
public:
	OpR2_WeightedTable();	// NOTE: placeholder name (0x9bab50)
	~OpR2_WeightedTable();	// NOTE: placeholder name (0x700dd0)
	void add(int value, int weight);	// NOTE: placeholder name (0x9ba310)
	int &pick() throw();	// NOTE: placeholder name (0x9ba470)

	vector<unsigned int>	values;
	vector<unsigned int>	weights;
	int						total;
};

void OpR2_unknown603660(vector<int> &ids, OpR2_ItemType *item)	// NOTE: placeholder name
{
	OpR2_WeightedTable table;
	for (int type = 9; type <= 13; type++)
	{
		int weight = 0;
		for (unsigned int i = 0; i < ids.size(); i++)
		{
			if (opr2_itemTypes[ids[i]]->type == type)
				weight += opr2_itemTypes[ids[i]]->unknown50;
		}
		table.add(type,weight);
	}
	item->type = table.pick();
	for (unsigned int i = 0; i < ids.size(); i++)
	{
		if (opr2_itemTypes[ids[i]]->type == item->type)
		{
			item->unknown78 = opr2_itemTypes[ids[i]]->unknown78;
			break;
		}
	}
}

void OpR2_unknown6038e0(vector<int> &ids, OpR2_ItemType *item, bool flag)	// NOTE: placeholder name
{
	if (!flag || rng.chance(opr2_ba3bdc))
	{
		item->unknowne8 = 0;
		item->unknownec = 0;
	}
	vector<unsigned int> choices;
	if (item->type == 9)
	{
		for (unsigned int i = 0; i < ids.size(); i++)
		{
			if (opr2_ba0968[opr2_itemTypes[ids[i]]->unknownec])
			{
				choices.push_back(15);
				break;
			}
		}
	}
	else if (item->type == 10)
	{
		for (unsigned int i = 0; i < ids.size(); i++)
		{
			if (opr2_itemTypes[ids[i]]->unknownec != 0 && !opr2_ba0968[opr2_itemTypes[ids[i]]->unknownec])
			{
				choices.push_back(15);
				break;
			}
		}
	}
	else if (item->type == 12 || item->type == 13)
	{
		for (unsigned int i = 0; i < ids.size(); i++)
		{
			if (opr2_itemTypes[ids[i]]->unknowne8 >= 1)
			{
				choices.push_back(14);
				break;
			}
		}
	}
	if (!choices.empty() && rng.chance(100 - opr2_ba3b10))
	{
		switch (OpR2_randomElement(choices))
		{
		case 14:
			item->unknowne8 = opr2_itemTypes[OpR2_randomElement(ids)]->unknowne8;
			break;
		case 15:
			item->unknownec = opr2_itemTypes[OpR2_randomElement(ids)]->unknownec;
			break;
		}
	}
	if (item->unknowne8 != 0 && item->type != 12 && item->type != 13)
		item->unknowne8 = 0;
	if (item->unknownec != 0 &&
		((item->type != 9 && opr2_ba0968[item->unknownec]) || (item->type != 10 && !opr2_ba0968[item->unknownec])))
		item->unknownec = 0;
}

bool OpR2_unknown603c00(vector<int> &ids, OpR2_ItemType *item, bool flag)	// NOTE: placeholder name
{
	OpR2_WeightedTable table;
	for (int type = 20; type <= 23; type++)
	{
		int weight = 0;
		for (unsigned int i = 0; i < ids.size(); i++)
		{
			if (opr2_itemTypes[ids[i]]->type == type)
				weight += opr2_itemTypes[ids[i]]->unknown50;
		}
		table.add(type,weight);
	}
	item->type = table.pick();
	if (item->unknown4c > 1 && (item->type == 20 || item->type == 22))
		item->type++;
	for (unsigned int i = 0; i < opr2_itemTypes.size(); i++)
	{
		if (opr2_itemTypes[i]->type == item->type)
		{
			item->unknown78 = opr2_itemTypes[i]->unknown78;
			break;
		}
	}
	item->image = (item->type != 20 && item->type != 22) ? opr2_image_d1da88 : opr2_image_d2e9b0;
	int oldCategory = item->category;
	if (true)
	{
		OpR2_WeightedTable table2;
		for (int category = 0; category < 10; category++)
		{
			int weight = 0;
			for (unsigned int i = 0; i < ids.size(); i++)
			{
				if (opr2_itemTypes[ids[i]]->category == category)
					weight += opr2_itemTypes[ids[i]]->unknown50;
			}
			table2.add(category,weight);
		}
		item->category = table2.pick();
		item->unknown160 = (item->category != 7) - 1 & 3;
		vector<OpR2_ItemType *> matches;
		for (unsigned int i = 0; i < ids.size(); i++)
		{
			if (opr2_itemTypes[ids[i]]->category == item->category)
				matches.push_back(opr2_itemTypes[ids[i]]);
		}
		if (!matches.empty())
		{
			OpR2_ItemType *other = OpR2_randomElement(matches);
			item->unknown190 = other->unknown190;
			item->unknown174 = other->unknown174;
			item->unknown194 = other->unknown194;
			item->unknown13c = other->unknown13c;
			if (item->category != 1 && item->unknown158 != 0)
				item->unknown158 = 0;
			else if (other->unknown158 != 0)
			{
				if (item->unknown150 == 0 || rng.chance(25))
				{
					item->unknown158 = other->unknown158;
					item->unknown150 = 0;
					item->unknown154 = 0;
				}
			}
		}
	}
	return flag ? item->category != oldCategory : true;
}

bool OpR2_unknown63a2b0(const Point &from, const Point &to)	// NOTE: placeholder name
{
	vector<Point> line;
	OpQ1_lineBresenhamPoints_40ff30(from,to,line);
	for (unsigned int i = 1; i < line.size(); i++)
	{
		if (cells(line[i])->getProp().isValid() && cells(line[i])->getProp()->getName() == "GAR_RIF_Installer")
			return true;
	}
	return false;
}

class OpR2_Named	// NOTE: placeholder name
{
public:
	void unknown63c660();	// NOTE: placeholder name

	char	pad00[0xc];
	string	name;	// NOTE: placeholder name
};

void OpR2_Named::unknown63c660()
{
	if (name[1] == '-')
		name = "Borg" + string(name.begin() + 4,name.end());
	else
		name.insert(0,"Borg ");
}
