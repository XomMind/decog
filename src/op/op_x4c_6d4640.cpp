// op_x4c: opx4c_unknown6d4640 (0x6d4640), Beta 17.1. NOTE: class/function names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
	void shift(int amount);	// NOTE: placeholder name (0x40bf50)
};

struct OpX4c_Area	// NOTE: placeholder name
{
	Point min;
	Point max;
};

class Cell
{
public:
	bool unknown45d6a0();	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	T &operator()(int x, int y);	// 0x9ceda0
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	bool contains(int x, int y);	// NOTE: placeholder name (0x9b45c0)
	int getWidth();	// 0x9fcd80
	int getHeight();	// NOTE: placeholder name (0x9b8f00)
};
extern Array2D<Cell *> cells;	// 0xcfd44c
extern Array2D<int> opx4c_grid;	// NOTE: placeholder name (0xcf1964)

void OpX5_shuffleBools(vector<bool> &v);	// NOTE: placeholder name (0x9db910)

bool opx4c_unknown6d4640(Point &p, int dir, OpX4c_Area &out)	// NOTE: placeholder name
{
	int maxX;
	for (maxX = p.x; maxX < cells.getWidth(); maxX++)
	{
		if (opx4c_grid(maxX,p.y) != 4)
		{
			maxX--;
			break;
		}
	}
	int xMin;
	for (xMin = p.x; xMin >= 0; xMin--)
	{
		if (opx4c_grid(xMin,p.y) != 4)
		{
			xMin++;
			break;
		}
	}
	int maxY;
	for (maxY = p.y; maxY < cells.getHeight(); maxY++)
	{
		if (opx4c_grid(p.x,maxY) != 4)
		{
			maxY--;
			break;
		}
	}
	int minY;
	for (minY = p.y; minY >= 0; minY--)
	{
		if (opx4c_grid(p.x,minY) != 4)
		{
			minY++;
			break;
		}
	}
	int w = maxX - xMin + 1;
	int h = maxY - minY + 1;
	if (w > 8 && h > 8)
		return false;
	if (dir == 3)
	{
		for (int i = 0; i < 5; i++)
		{
			if (!cells.contains(p) || !cells(p)->unknown45d6a0())
				break;
			if (cells.contains(p.x + 1,p.y + 1) && cells(p.x + 1,p.y + 1)->unknown45d6a0())
			{
				out.min = out.max = p;
				out.max.shift(1);
				p.shift(-1);
				return true;
			}
		}
		return false;
	}
	bool horizontal = w >= h;
	if (horizontal)
	{
		switch (dir)
		{
		case 1:
		case 2:
		case 4:
			out.min.x = out.max.x = p.x;
			out.min.y = minY;
			out.max.y = maxY;
			if (dir == 2 || dir == 4)
			{
				int dist = dir == 2 ? 1 : 4;
				vector<bool> order;
				order.push_back(true);
				order.push_back(false);
				OpX5_shuffleBools(order);
				for (unsigned int j = 0; j < order.size(); j++)
				{
					if (order[j] && xMin <= p.x - dist)
					{
						out.min.x -= dist;
						break;
					}
					else if (!order[j] && maxX >= p.x + dist)
					{
						out.max.x += dist;
						break;
					}
				}
			}
		}
	}
	else
	{
		switch (dir)
		{
		case 1:
		case 2:
		case 4:
			out.min.y = out.max.y = p.y;
			out.min.x = xMin;
			out.max.x = maxX;
			if (dir == 2 || dir == 4)
			{
				int dist = dir == 2 ? 1 : 4;
				vector<bool> order;
				order.push_back(true);
				order.push_back(false);
				OpX5_shuffleBools(order);
				for (unsigned int k = 0; k < order.size(); k++)
				{
					if (order[k] && minY <= p.y - dist)
					{
						out.min.y -= dist;
						break;
					}
					else if (!order[k] && maxY >= p.y + dist)
					{
						out.max.y += dist;
						break;
					}
				}
			}
		}
	}
	return true;
}
