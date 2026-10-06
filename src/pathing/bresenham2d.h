#ifndef BRESENHAM2D_H
#define BRESENHAM2D_H

#include "gamedecl.h"

//==================================================================
// Bresenham line steppers
//==================================================================
// Class names are from RTTI; member names are placeholders.

class Bresenham2DStepper
{
protected:
	int	errorX;		// used when the line is mostly vertical
	int	errorY;		// used when the line is mostly horizontal
	int	deltaX2;	// 2*|dx|
	int	deltaY2;	// 2*|dy|
	int	stepX;		// sign of dx
	int	stepY;		// sign of dy
	int	deltaX;
	int	deltaY;
	int	x;
	int	y;

public:
	Bresenham2DStepper() {};
	Bresenham2DStepper(int x0, int y0, int x1, int y1)
	{
		init(x0,y0,x1,y1);
	};
	virtual ~Bresenham2DStepper() {};

	void init(int x0, int y0, int x1, int y1);	// NOTE: placeholder name
	void init(const Point &from, const Point &to)	// NOTE: placeholder name
	{
		init(from.x,from.y,to.x,to.y);
	};
	void step();	// NOTE: placeholder name
	void next(Point &p)	// NOTE: placeholder name
	{
		step();
		p.set(x,y);
	};
	void getDelta(Point &d)	// NOTE: placeholder name
	{
		d.x = deltaX;
		d.y = deltaY;
	};
};

// steps through a line at subcell resolution, reporting cell + subcell coordinates
class Bresenham2DStepperSubcell : public Bresenham2DStepper
{
	int	subcells;

public:
	Bresenham2DStepperSubcell() {};
	Bresenham2DStepperSubcell(const Point &fromCell, const Point &fromSubcell, const Point &toCell, const Point &toSubcell, int subcells_)
	{
		init(fromCell,fromSubcell,toCell,toSubcell,subcells_);
	};
	virtual ~Bresenham2DStepperSubcell() {};

	void init(int fromCellX, int fromCellY, int fromSubX, int fromSubY, int toCellX, int toCellY, int toSubX, int toSubY, int subcells_)	// NOTE: placeholder name
	{
		Bresenham2DStepper::init(fromCellX * subcells_ + fromSubX,fromCellY * subcells_ + fromSubY,toCellX * subcells_ + toSubX,toCellY * subcells_ + toSubY);
		subcells = subcells_;
	};
	void init(const Point &fromCell, const Point &fromSubcell, const Point &toCell, const Point &toSubcell, int subcells_)	// NOTE: placeholder name
	{
		init(fromCell.x,fromCell.y,fromSubcell.x,fromSubcell.y,toCell.x,toCell.y,toSubcell.x,toSubcell.y,subcells_);
	};
	bool next(Point &cell, Point &subcell)	// NOTE: placeholder name
	{
		step();
		cell.set(x / subcells,y / subcells);
		subcell.set(x % subcells,y % subcells);
		return subcell.isInvalid();
	};
};

bool traceSubcellLine(int x0, int y0, int x1, int y1, vector<Point> &cells, vector<int> &steps, int subcells);	// NOTE: placeholder name
bool traceSubcellLine(const Point &from, const Point &to, vector<Point> &cells, vector<int> &steps, int subcells);	// NOTE: placeholder name

#endif // BRESENHAM2D_H
