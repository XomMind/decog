#ifndef CARTOGRAPHER2D_H
#define CARTOGRAPHER2D_H

#include "gamedecl.h"

//==================================================================
// Cartographer2D callbacks
//==================================================================
// Class names are from RTTI; virtual method names are placeholders.
// None of these have a virtual destructor (no deleting dtor in the vtables).

// A* move cost callback (SoundPathCallback, EntityMovementCallback, DF::PathMoveCost...)
class Cartographer2DMoveCost
{
public:
	// optionally supply a custom neighbor list for x,y; false = use the default 4/8 neighbors
	virtual bool getNeighbors(int x, int y, int *neighborX, int *neighborY, void *data)	// NOTE: placeholder name
	{
		return false;
	};
	virtual bool isPassable(int x, int y, void *data) = 0;	// NOTE: placeholder name
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost) = 0;	// NOTE: placeholder name
};

// Dijkstra flood cost callback: getMoveCost() returns false for impassable cells,
//	checkCell() is called for each reached cell and returns true to stop the search
class Cartographer2DDijkstraCost
{
public:
	virtual bool getNeighbors(int x, int y, int *neighborX, int *neighborY, void *data)	// NOTE: placeholder name
	{
		return false;
	};
	virtual bool getMoveCost(int fromX, int fromY, int toX, int toY, void *data, int &cost) = 0;	// NOTE: placeholder name
	virtual bool checkCell(int x, int y, void *data, int distance) = 0;	// NOTE: placeholder name
};

class Cartographer2DDijkstraCheck
{
public:
	virtual bool check(int x, int y) = 0;	// NOTE: placeholder name
};

//==================================================================
// Cartographer2D
//==================================================================
// A* / Dijkstra over the map grid; one global instance @ 0xcfe568.
// All per-search arrays are indexed by cell (x * height + y) or by open-list node ID.

class Cartographer2D
{
	unsigned int	width;
	unsigned int	height;
	bool			customNeighbors;	// NOTE: placeholder name; ask the callback for the neighbor list
	bool			diagonals;			// NOTE: placeholder name; 8 neighbors instead of 4
	unsigned int	searchID;			// NOTE: placeholder name; bumped by 2 per search, so closed/open
										//	marks never need clearing between searches
	unsigned int	openMark;			// NOTE: placeholder name; searchID - 1
	unsigned int	*heap;				// NOTE: placeholder name; 1-based binary min-heap of node IDs
	unsigned int	*cellState;			// NOTE: placeholder name; per cell: openMark / searchID (closed)
	unsigned int	*nodeX;				// NOTE: placeholder name; per node
	unsigned int	*nodeY;				// NOTE: placeholder name; per node
	unsigned int	*parentX;			// NOTE: placeholder name; per cell
	unsigned int	*parentY;			// NOTE: placeholder name; per cell
	int				*nodeF;				// NOTE: placeholder name; per node: g + h
	int				*cellG;				// NOTE: placeholder name; per cell: cost so far
	int				*nodeH;				// NOTE: placeholder name; per node: heuristic

public:
	bool findPath(int startX, int startY, int goalX, int goalY, Cartographer2DMoveCost *moveCost, void *data, vector<Point> &path);	// NOTE: placeholder name
	bool findPath(const Point &from, const Point &to, Cartographer2DMoveCost *moveCost, void *data, vector<Point> &path);	// NOTE: placeholder name
};

#endif // CARTOGRAPHER2D_H
