// Cartographer2D::findPath (0x40c9a0, 0x40d280): A* over the map grid.
#include "cartographer2d.h"
#include <stdlib.h>

bool Cartographer2D::findPath(const Point &from, const Point &to, Cartographer2DMoveCost *moveCost, void *data, vector<Point> &path)
{
	return findPath(from.x, from.y, to.x, to.y, moveCost, data, path);
}

bool Cartographer2D::findPath(int startX, int startY, int goalX, int goalY, Cartographer2DMoveCost *moveCost, void *data, vector<Point> &path)
{
	unsigned int neighborX[9];
	unsigned int neighborY[9];
	unsigned int nx, ny;
	unsigned int curX, curY;
	unsigned int heapCount;
	unsigned int i, pos, smallest, nextNode, nbr, scan, resetIndex;
	int firstNeighbor, lastNeighbor;
	int cost, newG, swap;
	bool found;

	path.clear();

	if (startX == goalX && startY == goalY)
		return false;

	if (!moveCost->isPassable(goalX,goalY,data))
		return false;

	firstNeighbor = 1;
	lastNeighbor = diagonals ? 8 : 4;
	nextNode = 1;
	found = false;

	if (searchID > 1000000)
	{
		for (resetIndex = 0; resetIndex < (width+1)*(height+1); resetIndex++)
			cellState[resetIndex] = 0;
		searchID = 10;
	}

	cellG[startX*height+startY] = 0;
	searchID += 2;
	openMark = searchID - 1;
	heap[1] = 1;
	nodeX[1] = startX;
	nodeY[1] = startY;
	heapCount = 1;

	for (;;)
	{
		if (heapCount != 0)
		{
			curX = nodeX[heap[1]];
			curY = nodeY[heap[1]];
			cellState[curX*height+curY] = searchID;
			heap[1] = heap[heapCount];
			heapCount--;

			smallest = 1;
			for (;;)
			{
				i = smallest;
				if (2*i+1 <= heapCount)
				{
					if (nodeF[heap[i]] >= nodeF[heap[2*i]])
						smallest = 2*i;
					if (nodeF[heap[smallest]] >= nodeF[heap[2*i+1]])
						smallest = 2*i+1;
				}
				else if (2*i <= heapCount)
				{
					if (nodeF[heap[i]] >= nodeF[heap[2*i]])
						smallest = 2*i;
				}
				if (i != smallest)
				{
					swap = heap[i];
					heap[i] = heap[smallest];
					heap[smallest] = swap;
				}
				else
					break;
			}

			if (customNeighbors)
				firstNeighbor = !moveCost->getNeighbors(curX,curY,(int *)neighborX,(int *)neighborY,data);

			neighborX[1] = curX-1;	neighborY[1] = curY;
			neighborX[2] = curX+1;	neighborY[2] = curY;
			neighborX[3] = curX;	neighborY[3] = curY-1;
			neighborX[4] = curX;	neighborY[4] = curY+1;
			if (diagonals)
			{
				neighborX[5] = curX-1;	neighborY[5] = curY-1;
				neighborX[6] = curX+1;	neighborY[6] = curY-1;
				neighborX[7] = curX-1;	neighborY[7] = curY+1;
				neighborX[8] = curX+1;	neighborY[8] = curY+1;
			}

			for (nbr = firstNeighbor; (int)nbr <= lastNeighbor; nbr++)
			{
				nx = neighborX[nbr];
				ny = neighborY[nbr];

				if (nx < width && ny < height && cellState[nx*height+ny] != searchID && moveCost->getMoveCost(curX,curY,nx,ny,data,cost))
				{
					if (cellState[nx*height+ny] != openMark)
					{
						heapCount++;
						pos = heapCount;
						heap[heapCount] = nextNode;
						nodeX[nextNode] = nx;
						nodeY[nextNode] = ny;
						nextNode++;
						cellG[nx*height+ny] = cellG[curX*height+curY] + cost;
						// heuristic: Manhattan distance to the goal
						nodeH[heap[pos]] = abs((int)nx-goalX) + abs((int)ny-goalY);
						nodeF[heap[pos]] = cellG[nx*height+ny] + nodeH[heap[pos]];
						parentX[nx*height+ny] = curX;
						parentY[nx*height+ny] = curY;
						while (pos != 1)
						{
							if (nodeF[heap[pos]] < nodeF[heap[pos/2]])
							{
								swap = heap[pos/2];
								heap[pos/2] = heap[pos];
								heap[pos] = swap;
								pos = pos/2;
							}
							else
								break;
						}
						cellState[nx*height+ny] = openMark;
					}
					else
					{
						newG = cellG[curX*height+curY] + cost;
						if (newG < cellG[nx*height+ny])
						{
							parentX[nx*height+ny] = curX;
							parentY[nx*height+ny] = curY;
							cellG[nx*height+ny] = newG;
							for (scan = 1; scan <= heapCount; scan++)
							{
								if (nodeX[heap[scan]] == nx && nodeY[heap[scan]] == ny)
								{
									nodeF[heap[scan]] = cellG[nx*height+ny] + nodeH[heap[scan]];
									pos = scan;
									while (pos != 1)
									{
										if (nodeF[heap[pos]] < nodeF[heap[pos/2]])
										{
											swap = heap[pos/2];
											heap[pos/2] = heap[pos];
											heap[pos] = swap;
											pos = pos/2;
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
			found = true;
			break;
		}
	}

	if (found)
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

	return found;
}
