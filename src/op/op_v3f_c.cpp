// op_v3f_c: CMap path helpers in 0x805360-0x805520 of COGMIND.exe (Beta 17.1). Names are placeholders unless stated.
#include "op_v3f.h"

int CMap::unknown805360(HEntity entity, vector<OpV3f_PathStep> *path, Point *target)
{
	vector<OpV3f_PathStep> *pList = path ? path : &unknown50c;
	vector<OpV3f_PathStep> &route = *pList;
	Point *endPtr = target ? target : &unknown4c8;
	Point &dest = *endPtr;
	int length = 0;
	unsigned int idx;
	for (idx = 0; idx < route.size(); idx++)
		length += OpQ1_distanceCeil_40a3f0(idx == 0 ? entity->unknown5c80f0(dest) : route[idx - 1].pos,route[idx].pos);
	length += OpQ1_distanceCeil_40a3f0(route.empty() ? entity->unknown5c80f0(dest) : Point(route.back().pos),dest);
	return length;
}

int CMap::unknown8054b0(bool flag)
{
	if (flag)
	{
		HItem item = opV3F_world->unknown66c->unknown5d2380(0x1c);
		return item->unknown577a90() < 1 ? 0 : unknown384;
	}
	else
		return unknown384;
}
