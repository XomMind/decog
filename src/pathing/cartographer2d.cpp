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


// Dijkstra flood from a start cell up to range, reporting each settled cell to cost->checkCell (0x40e990)
void Cartographer2D::dijkstra(int startX, int startY, int range, Cartographer2DDijkstraCost *cost, void *data)
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

	cur = 1;
	areas = diagonals ? 8 : 4;
	col = 1;

	if (searchID > 1000000)
	{
		for (attempts = 0; attempts < (width+1)*(height+1); attempts++)
			cellState[attempts] = 0;
		searchID = 10;
	}

	cellG[startX*height+startY] = 0;
	nodeF[1] = 0;
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
			if (cost->checkCell(active,a1,data,nodeF[heap[1]]))
				return;
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
				cur = !cost->getNeighbors(active,a1,(int *)amount,(int *)adj,data);

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

				if (center < width && base < height && cellState[center*height+base] != searchID && cost->getMoveCost(active,a1,center,base,data,a))
				{
					if (cellState[center*height+base] != openMark)
					{
						cellG[center*height+base] = cellG[active*height+a1] + a;
						if (cellG[center*height+base] + a > range)
							cellState[center*height+base] = searchID;
						else
						{
							bonus++;
							ally = bonus;
							heap[bonus] = col;
							nodeX[col] = center;
							nodeY[col] = base;
							col++;
							nodeF[heap[ally]] = cellG[center*height+base];
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
									nodeF[heap[action]] = cellG[center*height+base];
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
	}
}

// Like dijkstra, but stops at the first settled cell check->check() accepts and returns the path to it (0x40f310)
bool Cartographer2D::findNearest(int startX, int startY, int range, Cartographer2DMoveCost *cost, void *data, vector<Point> &path, Cartographer2DDijkstraCheck *check)
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

	path.clear();
	cur = 1;
	areas = diagonals ? 8 : 4;
	col = 1;
	Point res(-1);

	if (searchID > 1000000)
	{
		for (attempts = 0; attempts < (width+1)*(height+1); attempts++)
			cellState[attempts] = 0;
		searchID = 10;
	}

	cellG[startX*height+startY] = 0;
	nodeF[1] = 0;
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
			if (check->check(active,a1))
			{
				res.set(active,a1);
				break;
			}
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
				cur = !cost->getNeighbors(active,a1,(int *)amount,(int *)adj,data);

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

				if (center < width && base < height && cellState[center*height+base] != searchID && cost->getMoveCost(active,a1,center,base,data,a))
				{
					if (cellState[center*height+base] != openMark)
					{
						cellG[center*height+base] = cellG[active*height+a1] + a;
						if (cellG[center*height+base] + a > range)
							cellState[center*height+base] = searchID;
						else
						{
							bonus++;
							ally = bonus;
							heap[bonus] = col;
							nodeX[col] = center;
							nodeY[col] = base;
							col++;
							nodeF[heap[ally]] = cellG[center*height+base];
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
									nodeF[heap[action]] = cellG[center*height+base];
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
	}

	if (res.x != -1)
	{
		Point p(res);
		path.push_back(p);
		do
		{
			unsigned int px = parentX[p.x*height+p.y];
			p.y = parentY[p.x*height+p.y];
			p.x = px;
			path.insert(path.begin(),p);
		}
		while (p.x != startX || p.y != startY);
		return true;
	}
	else
		return false;
}

// A* toward whichever of goals is reached first; removes the start and impassable cells from goals (0x40dd50)
bool Cartographer2D::findPathToAny(int startX, int startY, vector<Point> &goals, Cartographer2DMoveCost *cost, void *data, vector<Point> &path)
{
	unsigned int amount[9];
	unsigned int adj[9];
	unsigned int center;
	unsigned int base;
	unsigned int active;
	unsigned int a1;
	unsigned int bonus;
	bool retval;
	unsigned int child;
	unsigned int ally;
	unsigned int added;
	unsigned int col;
	unsigned int adjacent;
	unsigned int action;
	unsigned int attempts;
	int left;
	int next;
	int cur;
	int areas;
	int a;
	int behaviour;
	int attempt;

	path.clear();
	for (next = goals.size() - 1; next >= 0; next--)
	{
		if (startX == goals[next].x && startY == goals[next].y)
			goals.erase(goals.begin() + next);
	}
	for (left = goals.size() - 1; left >= 0; left--)
	{
		if (!cost->isPassable(goals[left].x,goals[left].y,data))
			goals.erase(goals.begin() + left);
	}
	if (goals.size() == 1)
		return findPath(startX,startY,goals[0].x,goals[0].y,cost,data,path);
	if (goals.size() == 0)
		return false;

	cur = 1;
	areas = diagonals ? 8 : 4;
	col = 1;
	retval = false;
	Point record;

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
				cur = !cost->getNeighbors(active,a1,(int *)amount,(int *)adj,data);

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

				if (center < width && base < height && cellState[center*height+base] != searchID && cost->getMoveCost(active,a1,center,base,data,a))
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
						nodeF[heap[ally]] = cellG[center*height+base];
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
									nodeF[heap[action]] = cellG[center*height+base];
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
			for (unsigned int i = 0; i < goals.size(); i++)
			{
				if (cellState[goals[i].x*height+goals[i].y] == openMark)
				{
					record = goals[i];
					retval = true;
					break;
				}
			}
			if (retval)
				break;
		}
		else
			break;
	}

	if (retval)
	{
		path.push_back(record);
		do
		{
			unsigned int px = parentX[record.x*height+record.y];
			record.y = parentY[record.x*height+record.y];
			record.x = px;
			path.insert(path.begin(),record);
		}
		while (record.x != startX || record.y != startY);
	}

	return retval;
}
