// op_v3h: CMap selection helpers (COGMIND.exe Beta 17.1).
#include "op/op_v3h.h"

void OpV3h_Map::unknown827850(int direction)
{
	Point pos;
	if (unknown805190(pos))
	{
		Point target(Point(pos),opV3h_directions[direction]);
		if (opV3h_cells.contains(target))
		{
			if (!unknown8052f0(target))
				unknown8069e0(Point(target),true);
			unknown806e70(target,true);
		}
	}
}

void OpV3h_Map::unknown827950()
{
	if (unknown680 == 8 && unknown684 == 3)
		unknown8142d0(9,0);
	if (opV3h_d1d9c4)
	{
		opV3h_mouse->setCursorHidden(false);
		opV3h_d28c8a = false;
		opV3h_d1d9c4 = false;
	}
	setSelected_8278f0(7);
	unknown807e60(false);
}

void OpV3h_Map::unknown8279c0(const Point &pos)
{
	setSelected_8278f0(8);
	unknown684 = 2;
	unknown6fc.fill(-1);
	unknown704.reset();
	unknown698 = -1;
	unknown688.clear();
	unknown688.push_back(opV3h_world->unknown66c);
	opV3h_world->unknown715800(unknown688);
	for (unsigned int i = 0; i < unknown688.size(); i++)
	{
		if (unknown688[i]->getPosition() == pos)
		{
			OpQ5_eraseAt((vector<OpQ5_U9da940>&)unknown688,i);
			break;
		}
	}
	vector<HEntity> entities(unknown688);
	unknown688.clear();
	vector<int> distances;
	vector<int> sorted;
	for (unsigned int i = 0; i < entities.size(); i++)
		distances.push_back(-OpV3h_distanceCeil_40a3f0(pos,entities[i]->unknown45a4c0()));
	unknown688.push_back(entities.front());
	sorted.push_back(distances.front());
	for (unsigned int j = 1; j < entities.size(); j++)
	{
		if (distances[j] <= sorted.back())
		{
			unknown688.push_back(entities[j]);
			sorted.push_back(distances[j]);
		}
		else
		{
			for (unsigned int k = 0; k < sorted.size(); k++)
			{
				if (distances[j] > sorted[k])
				{
					opV3h_insertAt(unknown688,k,entities[j]);
					opV3h_insertAt(sorted,k,distances[j]);
					break;
				}
			}
		}
	}
	unknown6ac = -1;
	unknown69c.clear();
}

void OpV3h_Map::unknown827cf0()
{
	setSelected_8278f0(8);
	unknown807e60(false);
	unknown684 = 3;
	unknown8142d0(0x12,0);
	for (unsigned int i = 0; i < opV3h_world->unknown7f0.size(); i++)
		unknown80ed40(false,opV3h_world->unknown7f0[i]);
	unknown200 = -1;
	unknown698 = -1;
}
