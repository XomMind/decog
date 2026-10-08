// Cartographer2D::findPath (0x40c9a0, 0x40d280): A* over the map grid.
#include "cartographer2d.h"
#include <stdlib.h>

bool Cartographer2D::findPath(const Point &from, const Point &to, Cartographer2DMoveCost *moveCost, void *data, vector<Point> &path)
{
	return findPath(from.x, from.y, to.x, to.y, moveCost, data, path);
}

bool Cartographer2D::findPath(int startX, int startY, int goalX, int goalY, Cartographer2DMoveCost *moveCost, void *data, vector<Point> &path)
{
	unsigned int amount[9];
	unsigned int adj[9];
	unsigned int center;
	unsigned int base;
	unsigned int active;
	unsigned int a1;
	unsigned int bonus;
	unsigned int child;
	unsigned int ally;
	unsigned int added;
	unsigned int col;
	unsigned int adjacent;
	unsigned int action;
	unsigned int attempts;
	int cur;
	int areas;
	int a;
	int behaviour;
	int attempt;
	bool clean;

	path.clear();

	if (startX == goalX && startY == goalY)
		return false;

	if (!moveCost->isPassable(goalX,goalY,data))
		return false;

	cur = 1;
	areas = diagonals ? 8 : 4;
	col = 1;
	clean = false;

	if (searchID > 1000000)
	{
		for (attempts = 0; attempts < (width+1)*(height+1); attempts++)
			cellState[attempts] = 0;
		searchID = 10;
	}

	cellG[startX*height+startY] = 0;
	searchID += 2;
	openMark = searchID - 1;
	heap[1] = 1;
	nodeX[1] = startX;
	nodeY[1] = startY;
	bonus = 1;

	for (;;)
	{
		if (bonus != 0)
		{
			active = nodeX[heap[1]];
			a1 = nodeY[heap[1]];
			cellState[active*height+a1] = searchID;
			heap[1] = heap[bonus];
			bonus--;

			added = 1;
			for (;;)
			{
				child = added;
				if (2*child+1 <= bonus)
				{
					if (nodeF[heap[child]] >= nodeF[heap[2*child]])
						added = 2*child;
					if (nodeF[heap[added]] >= nodeF[heap[2*child+1]])
						added = 2*child+1;
				}
				else if (2*child <= bonus)
				{
					if (nodeF[heap[child]] >= nodeF[heap[2*child]])
						added = 2*child;
				}
				if (child != added)
				{
					attempt = heap[child];
					heap[child] = heap[added];
					heap[added] = attempt;
				}
				else
					break;
			}

			if (customNeighbors)
				cur = !moveCost->getNeighbors(active,a1,(int *)amount,(int *)adj,data);

			amount[1] = active-1;	adj[1] = a1;
			amount[2] = active+1;	adj[2] = a1;
			amount[3] = active;	adj[3] = a1-1;
			amount[4] = active;	adj[4] = a1+1;
			if (diagonals)
			{
				amount[5] = active-1;	adj[5] = a1-1;
				amount[6] = active+1;	adj[6] = a1-1;
				amount[7] = active-1;	adj[7] = a1+1;
				amount[8] = active+1;	adj[8] = a1+1;
			}

			for (adjacent = cur; (int)adjacent <= areas; adjacent++)
			{
				center = amount[adjacent];
				base = adj[adjacent];

				if (center < width && base < height && cellState[center*height+base] != searchID && moveCost->getMoveCost(active,a1,center,base,data,a))
				{
					if (cellState[center*height+base] != openMark)
					{
						bonus++;
						ally = bonus;
						heap[bonus] = col;
						nodeX[col] = center;
						nodeY[col] = base;
						col++;
						cellG[center*height+base] = cellG[active*height+a1] + a;
						// heuristic: Manhattan distance to the goal
						nodeH[heap[ally]] = abs((int)center-goalX) + abs((int)base-goalY);
						nodeF[heap[ally]] = cellG[center*height+base] + nodeH[heap[ally]];
						parentX[center*height+base] = active;
						parentY[center*height+base] = a1;
						while (ally != 1)
						{
							if (nodeF[heap[ally]] < nodeF[heap[ally/2]])
							{
								attempt = heap[ally/2];
								heap[ally/2] = heap[ally];
								heap[ally] = attempt;
								ally = ally/2;
							}
							else
								break;
						}
						cellState[center*height+base] = openMark;
					}
					else
					{
						behaviour = cellG[active*height+a1] + a;
						if (behaviour < cellG[center*height+base])
						{
							parentX[center*height+base] = active;
							parentY[center*height+base] = a1;
							cellG[center*height+base] = behaviour;
							for (action = 1; action <= bonus; action++)
							{
								if (nodeX[heap[action]] == center && nodeY[heap[action]] == base)
								{
									nodeF[heap[action]] = cellG[center*height+base] + nodeH[heap[action]];
									ally = action;
									while (ally != 1)
									{
										if (nodeF[heap[ally]] < nodeF[heap[ally/2]])
										{
											attempt = heap[ally/2];
											heap[ally/2] = heap[ally];
											heap[ally] = attempt;
											ally = ally/2;
										}
										else
											break;
									}
								}
							}
						}
					}
				}
			}
		}
		else
			break;

		if (cellState[goalX*height+goalY] == openMark)
		{
			clean = true;
			break;
		}
	}

	if (clean)
	{
		Point p(goalX,goalY);
		path.push_back(p);
		do
		{
			unsigned int px = parentX[p.x*height+p.y];
			p.y = parentY[p.x*height+p.y];
			p.x = px;
			path.insert(path.begin(),p);
		}
		while (p.x != startX || p.y != startY);
	}

	return clean;
}
