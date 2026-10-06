#include "../pathing/gamedecl.h"

// NOTE: descriptive placeholder names; these test a square footprint.
bool isFootprintOpen(const Point &position, int size)
{
	if (size == 1)
		return cells.contains(position);
	else
		return cells.contains(position) &&
			position.x + size - 1 < cells.getWidth() &&
			position.y + size - 1 < cells.getHeight();
}

bool footprintHasEntity(const Point &position, int size)
{
	if (size == 1)
		return cells(position)->getEntity().isValid();
	else
	{
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				if (cells(Point(position, x, y))->getEntity().isValid())
					return true;
			}
		}
		return false;
	}
}

bool footprintHasImpassableTile(const Point &position, int size)
{
	if (size == 1)
		return !cells(position)->isPassableFor(HEntity());
	else
	{
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				if (!cells(Point(position, x, y))->isPassableFor(HEntity()))
					return true;
			}
		}
		return false;
	}
}

Point::Point(const Point &p, int dx, int dy)
	: x (p.x + dx)
	, y (p.y + dy)
{
}
