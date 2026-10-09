// Dijkstra cost/check callbacks used with Cartographer2D::dijkstra() (0x4faf40-0x4fd1c0).
// Class names are from RTTI; helper/global names are placeholders.
#include "cartographer2d.h"
#include "gamedecl.h"
#include "../util/rng.h"

extern RNG rng;

// The world object (0xcefc4c) seen as BS: retail calls BS::isVisible(const Point&) (0x4631c0, src/game/cc_r2_06.cpp),
// the Point overload of Map::isVisible in gamedecl.h has no configured identity.
class BS : public Map	// NOTE: placeholder name, same object as Map
{
public:
	bool isVisible(const Point &p);	// 0x4631c0
};

// Retail reads the item's type through the folded +0x08 getter 0x9b4350, not Item::getType (0x44aec0, +0x0c).
class DijkstraItem	// NOTE: placeholder name (Item)
{
public:
	int getType_9b4350();	// NOTE: placeholder name (ICF'd trivial getter of +0x08)
};

//==================================================================
// Dijkstra results
//==================================================================

vector<Point>	dijkstraCells;		// NOTE: placeholder name; cells found by the last search
vector<int>		dijkstraDistances;	// NOTE: placeholder name; parallel to dijkstraCells (only filled by some costs)

// current range of equidistant results in dijkstraCells
extern int	dijkstraRangeEnd;	// NOTE: placeholder name (0xced284)
extern int	dijkstraRangeStart;	// NOTE: placeholder name (0xcef678)

void clearDijkstraResults()	// NOTE: placeholder name
{
	dijkstraCells.clear();
	dijkstraDistances.clear();
}

void findFirstDijkstraRange()	// NOTE: placeholder name
{
	if (dijkstraCells.empty())
		return;

	dijkstraRangeEnd = 0;
	dijkstraRangeStart = dijkstraRangeEnd;
	for (unsigned int i = 1; i < dijkstraCells.size(); i++)
	{
		if (dijkstraDistances[i] == dijkstraDistances[dijkstraRangeStart])
			dijkstraRangeEnd = i;
		else
			break;
	}
}

bool findNextDijkstraRange()	// NOTE: placeholder name
{
	if (dijkstraRangeEnd == dijkstraCells.size() - 1)
		return false;

	dijkstraRangeEnd++;
	dijkstraRangeStart = dijkstraRangeEnd;
	for (unsigned int i = dijkstraRangeEnd + 1; i < dijkstraCells.size(); i++)
	{
		if (dijkstraDistances[i] == dijkstraDistances[dijkstraRangeStart])
			dijkstraRangeEnd = i;
		else
			break;
	}
	return true;
}

int getDijkstraDistance(const Point &p)	// NOTE: placeholder name
{
	int index = findIndex(dijkstraCells,p);
	if (index == -1)
		return index;
	else
		return dijkstraDistances[index];
}

//==================================================================
// Costs
//==================================================================

class DijkstraCostPlaceItem : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->canPlaceItem())
			return false;
		cost = (fromX != toX && fromY != toY) ? 3 : 2;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 &&
			(cells(x,y)->hasBlockingObject() ||
			 (data != NULL && (int)data == itemTypeMatter && cells(x,y)->getItem().isValid() &&
			  ((DijkstraItem *)cells(x,y)->getItem().operator->())->getType_9b4350() == (int)data && rng.chance(30))))
		{
			dijkstraCells.push_back(Point(x,y));
			dijkstraDistances.push_back(distance);
		}
		return false;
	};
};

class DijkstraCostPlaceEntity : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(*(int *)data))
			return false;
		cost = (fromX != toX && fromY != toY) ? 3 : 2;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 && cells(x,y)->canPlaceEntity(*(int *)data))
		{
			dijkstraCells.push_back(Point(x,y));
			dijkstraDistances.push_back(distance);
		}
		return false;
	};
};

class DijkstraCostFollowPlayer : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(*(int *)data) || cells(toX,toY)->isDoor())
			return false;
		cost = (fromX != toX && fromY != toY) ? 3 : 2;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 && cells(x,y)->canPlaceEntity(*(int *)data) && !cells(x,y)->isDoor())
		{
			dijkstraCells.push_back(Point(x,y));
			dijkstraDistances.push_back(distance);
		}
		return false;
	};
};

class DijkstraCostPlaceProp : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->canPlaceProp(data))
			return false;
		cost = (fromX != toX && fromY != toY) ? 3 : 2;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 && cells(x,y)->fitsProp(data))
		{
			dijkstraCells.push_back(Point(x,y));
			dijkstraDistances.push_back(distance);
		}
		return false;
	};
};

class DijkstraCostAvoidEntrance : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(*(int *)data))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0)
		{
			switch (entranceMap(x,y))
			{
			case 0: entranceMap(x,y) = 2; break;
			case 1: entranceMap(x,y) = 4; break;
				break;
			case 3: entranceMap(x,y) = 5; break;
			}
			vector<Point> adjacent;
			cells.getAdjacent(Point(x,y),adjacent);
			for (unsigned int i = 0; i < adjacent.size(); i++)
			{
				if (!cells(adjacent[i])->isOpen())
				{
					switch (entranceMap(x,y))
					{
					case 0: entranceMap(x,y) = 2; break;
					case 1: entranceMap(x,y) = 4; break;
						break;
					case 3: entranceMap(x,y) = 5; break;
					}
				}
			}
		}
		return false;
	};
};

class DijkstraCostFindItems : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(1))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 && cells(x,y)->getItem().isValid())
			dijkstraCells.push_back(Point(x,y));
		return false;
	};
};

class DijkstraCostFindShortcuts : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(*(int *)data))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 && cells(x,y)->isShortcut())
			dijkstraCells.push_back(Point(x,y));
		return false;
	};
};

class DijkstraCostFindTraps : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(*(int *)data))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 && cells(x,y)->getProp().isValid() && cells(x,y)->getProp()->isTrap())
			dijkstraCells.push_back(Point(x,y));
		return false;
	};
};

class DijkstraCostRevealLayout : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (cells(toX,toY)->getTerrain() == TERRAIN_EARTH ||
			!((Grid2DBounds *)data)->contains(toX,toY) ||
			cells(toX,toY)->isEdge() ||
			cells(toX,toY)->getTerrain() == TERRAIN_RUBBLE ||
			(cells(toX,toY)->isMachinePart() &&
			 (world->getZone(Point(toX,toY))->machine->type == 15 ||
			  world->getZone(Point(toX,toY))->machine->type == 8 ||
			  world->getZone(Point(toX,toY))->machine->type == 11 ||
			  world->getZone(Point(toX,toY))->machine->type == 29)))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 && !world->isKnown(x,y))
			dijkstraCells.push_back(Point(x,y));
		return false;
	};
};

class DijkstraCostFindNoninteractiveMachine : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(1) &&
			(!cells(toX,toY)->getProp().isValid() ||
			 cells(toX,toY)->getProp()->getData()->interactType != 2 ||
			 cells(toX,toY)->getProp()->getTerminalIndex() == -1))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 && cells(x,y)->getProp().isValid() &&
			cells(x,y)->getProp()->getData()->interactType == 2 &&
			cells(x,y)->getProp()->getTerminalIndex() != -1)
		{
			dijkstraCells.push_back(Point(x,y));
			return true;
		}
		return false;
	};
};

class DijkstraCostFindHackActionTargetHoldBot : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(((Entity *)data)->getSize()))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 && cells(x,y)->getEntity().isValid() &&
			!cells(x,y)->getEntity()->isPlayer() &&
			cells(x,y)->getEntity()->getFaction() != 1 &&
			cells(x,y)->getEntity()->getAiType() == 1 &&
			cells(x,y)->getEntity()->getRecord()->getOwner().isNull() &&
			world->isReachable(9999,((Entity *)data)->getPosition(),Point(x,y)))
		{
			dijkstraCells.push_back(Point(x,y));
			return true;
		}
		return false;
	};
};

class DijkstraCostFindHackActionTargetDeconstructBot : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(((Entity *)data)->getSize()))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 && cells(x,y)->getEntity().isValid() &&
			!cells(x,y)->getEntity()->isPlayer() &&
			cells(x,y)->getEntity()->getAiType() == 1 &&
			cells(x,y)->getEntity()->getSize() == 1 &&
			cells(x,y)->getEntity()->isInGroup(((Entity *)data)->getGroup()) &&
			world->isReachable(9999,((Entity *)data)->getPosition(),Point(x,y)))
		{
			dijkstraCells.push_back(Point(x,y));
			return true;
		}
		return false;
	};
};

class DijkstraCostFindHaulers : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(1))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance != 0 && cells(x,y)->getEntity().isValid() &&
			cells(x,y)->getEntity()->getFaction() == 4 &&
			(cells(x,y)->getEntity()->getGroup()->getType() == 3 ||
			 cells(x,y)->getEntity()->getGroup()->getType() == 4))
			dijkstraCells.push_back(Point(x,y));
		return false;
	};
};

class DijkstraCostWalls : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(((Entity *)data)->getSize()))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (cells(x,y)->isOpen())
			dijkstraCells.push_back(Point(x,y));
		return false;
	};
};

class DijkstraCostEarth : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (cells(x,y)->getTerrain() == TERRAIN_EARTH)
			dijkstraCells.push_back(Point(x,y));
		return false;
	};
};

class DijkstraCostMapRoute : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassable(1) &&
			(cells(toX,toY)->getProp().isNull() || cells(toX,toY)->getProp()->blocksEntity(HEntity())))
		{
			if (!cells(toX,toY)->isOpen())
				addUnique(dijkstraCells,Point(toX,toY));
			return false;
		}
		cost = (cells(toX,toY)->getProp().isValid() && !cells(toX,toY)->getProp()->blocksEntity(HEntity())) ? 2 : 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		dijkstraCells.push_back(Point(x,y));
		return false;
	};
};

class DijkstraCostSubcaveWallCells : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isOpen() ||
			(cells(toX,toY)->getProp().isValid() && cells(toX,toY)->getProp()->getData() != subcavePropData))
			return false;
		cost = (fromX != toX && fromY != toY) ? 3 : 2;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		vector<Point> adjacent;
		getAdjacentCells(Point(x,y),adjacent);
		for (unsigned int i = 0; i < adjacent.size(); i++)
		{
			if ((cells(adjacent[i])->getTerrain() == TERRAIN_CAVE_WALL || cells(adjacent[i])->getTerrain() == TERRAIN_EARTH) &&
				addUnique(dijkstraCells,adjacent[i]))
				dijkstraDistances.push_back(distance);
		}
		return false;
	};
};

class DijkstraCostOpenCells : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isOpen())
			return false;
		cost = (fromX != toX && fromY != toY) ? 3 : 2;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (cells(x,y)->isOpen())
		{
			dijkstraCells.push_back(Point(x,y));
			dijkstraDistances.push_back(distance);
		}
		return false;
	};
};

class DijkstraCostItemPushCells : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isOpen())
			return false;
		cost = (fromX != toX && fromY != toY) ? 3 : 2;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (cells(x,y)->isOpen())
		{
			dijkstraCells.push_back(Point(x,y));
			dijkstraDistances.push_back(distance);
		}
		return false;
	};
};

class DijkstraCostFovEdgeOpenCells : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!world->isVisible(toX,toY))
			return false;
		cost = (fromX != toX && fromY != toY) ? 3 : 2;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (cells(x,y)->isPassableFor(HEntity()) && world->isVisible(x,y))
		{
			vector<Point> adjacent;
			getAdjacentCells(Point(x,y),adjacent);
			for (unsigned int i = 0; i < adjacent.size(); i++)
			{
				if (!((BS *)world)->isVisible(adjacent[i]))
				{
					if (addUnique(dijkstraCells,Point(x,y)))
						dijkstraDistances.push_back(distance);
					break;
				}
			}
		}
		return false;
	};
};

class DijkstraCostFovAccessibleWallCells : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!world->isVisible(toX,toY))
			return false;
		cost = (fromX != toX && fromY != toY) ? 3 : 2;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (cells(x,y)->getTerrain() == TERRAIN_CAVE_WALL && world->isVisible(x,y))
		{
			vector<Point> adjacent;
			getAdjacentCells(Point(x,y),adjacent);
			for (unsigned int i = 0; i < adjacent.size(); i++)
			{
				if (cells(adjacent[i])->isPassableFor(HEntity()) && ((BS *)world)->isVisible(adjacent[i]))
				{
					if (addUnique(dijkstraCells,Point(x,y)))
						dijkstraDistances.push_back(distance);
					break;
				}
			}
		}
		return false;
	};
};

static const int gladosTurretDistances[5] = { 7, 15, 35, 55, 80 };	// NOTE: placeholder name

class DijkstraCostGladosTurretPlacement : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassableFor(HEntity()))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (distance > gladosTurretDistances[4])
			return true;
		if (cells(x,y)->isOpen() && inArray(gladosTurretDistances,5,distance))
		{
			dijkstraCells.push_back(Point(x,y));
			dijkstraDistances.push_back(distance);
		}
		return false;
	};
};

class DijkstraCostTensionEntitiesXom : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassableFor(HEntity()))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (cells(x,y)->getEntity().isValid() && !cells(x,y)->getEntity()->isPlayer() &&
			::distance(world->getPlayer()->getPosition(),Point(x,y)) <= 20 &&
			cells(x,y)->getEntity()->getTarget() == 0 &&
			cells(x,y)->getEntity()->isXomCandidate())
		{
			dijkstraCells.push_back(Point(x,y));
			dijkstraDistances.push_back(distance);
		}
		return false;
	};
};

class DijkstraCostWallEnemiesXom : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassableFor(HEntity()))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (cells(x,y)->getEntity().isValid() && !cells(x,y)->getEntity()->isPlayer() &&
			cells(x,y)->getEntity()->isHostileTo(world->getPlayer()) &&
			::distance(world->getPlayer()->getPosition(),Point(x,y)) <= 20 &&
			cells(x,y)->getEntity()->getTarget() == 0 &&
			cells(x,y)->getEntity()->isXomCandidate())
		{
			dijkstraCells.push_back(Point(x,y));
			dijkstraDistances.push_back(distance);
		}
		return false;
	};
};

class DijkstraCostPartMimicXom : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		if (!cells(toX,toY)->isPassableFor(HEntity()))
			return false;
		cost = 1;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		if (!world->isVisible(x,y) && !world->getMimicGrid()(x,y) && cells(x,y)->hasBlockingObject())
		{
			dijkstraCells.push_back(Point(x,y));
			dijkstraDistances.push_back(distance);
		}
		return false;
	};
};

class DijkstraCostAllCells : public Cartographer2DDijkstraCost
{
public:
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost)
	{
		cost = (fromX != toX && fromY != toY) ? 3 : 2;
		return true;
	};
	virtual bool checkCell(int x, int y, void *data, int distance)
	{
		dijkstraCells.push_back(Point(x,y));
		dijkstraDistances.push_back(distance);
		return false;
	};
};

//==================================================================
// Checks
//==================================================================

class DijkstraAutoexploreCheck : public Cartographer2DDijkstraCheck
{
public:
	virtual bool check(int x, int y)
	{
		return !world->isKnown(x,y);
	};
};

class DijkstraNearestDamagedMachineCheck : public Cartographer2DDijkstraCheck
{
public:
	virtual bool check(int x, int y)
	{
		return cells(x,y)->isDamagedMachine();
	};
};

//==================================================================
// Instances
//==================================================================
// NOTE: placeholder names

DijkstraCostPlaceItem							dijkstraCostPlaceItem;
DijkstraCostPlaceEntity							dijkstraCostPlaceEntity;
DijkstraCostFollowPlayer						dijkstraCostFollowPlayer;
DijkstraCostPlaceProp							dijkstraCostPlaceProp;
DijkstraCostAvoidEntrance						dijkstraCostAvoidEntrance;
DijkstraCostFindItems							dijkstraCostFindItems;
DijkstraCostFindShortcuts						dijkstraCostFindShortcuts;
DijkstraCostFindTraps							dijkstraCostFindTraps;
DijkstraCostRevealLayout						dijkstraCostRevealLayout;
DijkstraCostFindNoninteractiveMachine			dijkstraCostFindNoninteractiveMachine;
DijkstraCostFindHackActionTargetHoldBot			dijkstraCostFindHackActionTargetHoldBot;
DijkstraCostFindHackActionTargetDeconstructBot	dijkstraCostFindHackActionTargetDeconstructBot;
DijkstraCostFindHaulers							dijkstraCostFindHaulers;
DijkstraCostWalls								dijkstraCostWalls;
DijkstraCostEarth								dijkstraCostEarth;
DijkstraCostMapRoute							dijkstraCostMapRoute;
DijkstraAutoexploreCheck						dijkstraAutoexploreCheck;
DijkstraNearestDamagedMachineCheck				dijkstraNearestDamagedMachineCheck;
DijkstraCostSubcaveWallCells					dijkstraCostSubcaveWallCells;
DijkstraCostOpenCells							dijkstraCostOpenCells;
DijkstraCostItemPushCells						dijkstraCostItemPushCells;
DijkstraCostFovEdgeOpenCells					dijkstraCostFovEdgeOpenCells;
DijkstraCostFovAccessibleWallCells				dijkstraCostFovAccessibleWallCells;
DijkstraCostGladosTurretPlacement				dijkstraCostGladosTurretPlacement;
DijkstraCostTensionEntitiesXom					dijkstraCostTensionEntitiesXom;
DijkstraCostWallEnemiesXom						dijkstraCostWallEnemiesXom;
DijkstraCostPartMimicXom						dijkstraCostPartMimicXom;
DijkstraCostAllCells							dijkstraCostAllCells;
