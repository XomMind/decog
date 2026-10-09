// Bresenham line steppers (0x410010-0x410702).
#include "bresenham2d.h"

void Bresenham2DStepper::init(int x0, int y0, int x1, int y1)
{
	deltaX = x1 - x0;
	deltaY = y1 - y0;
	deltaX2 = (deltaX < 0 ? -deltaX : deltaX) << 1;
	deltaY2 = (deltaY < 0 ? -deltaY : deltaY) << 1;
	stepX = deltaX < 0 ? -1 : deltaX > 0;
	stepY = deltaY < 0 ? -1 : deltaY > 0;
	x = x0;
	y = y0;
	if (deltaX2 >= deltaY2)
		errorY = deltaY2 - (deltaX2 >> 1);
	else
		errorX = deltaX2 - (deltaY2 >> 1);
}

void Bresenham2DStepper::step()
{
	if (deltaX2 >= deltaY2)
	{
		if (errorY >= 0)
		{
			y += stepY;
			errorY -= deltaX2;
		}
		x += stepX;
		errorY += deltaY2;
	}
	else
	{
		if (errorX >= 0)
		{
			x += stepX;
			errorX -= deltaY2;
		}
		y += stepY;
		errorX += deltaX2;
	}
}

// fills cells with each cell the line passes through and steps with the number of subcell steps spent in each
bool traceSubcellLine(int x0, int y0, int x1, int y1, vector<Point> &cells, vector<int> &steps, int subcells)
{
	if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0 || (x0 == x1 && y0 == y1))
		return false;

	Bresenham2DStepperSubcell stepper(Point(x0,y0),subcells / 2,Point(x1,y1),subcells / 2,subcells);
	Point current(x0,y0);
	Point end(x1,y1);
	cells.push_back(current);
	steps.push_back(1);
	Point cell;
	Point subPt;	// name sets the frame slot (0x4104f0)
	do
	{
		stepper.next(cell,subPt);
		if (cell != current)
		{
			cells.push_back(cell);
			current = cell;
			steps.push_back(1);
		}
		else
			steps.back()++;
	} while (current != end || steps.back() < subcells / 2);
	return true;
}

bool traceSubcellLine(const Point &from, const Point &to, vector<Point> &cells, vector<int> &steps, int subcells)
{
	return traceSubcellLine(from.x,from.y,to.x,to.y,cells,steps,subcells);
}
