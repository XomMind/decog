// op_v3f_b: CMap view-coordinate helpers in 0x8050a0-0x805360 of COGMIND.exe (Beta 17.1). Names are placeholders unless stated.
#include "op_v3f.h"

bool CMap::unknown8050a0()
{
	Pos center;
	centerPush_805020(&center);
	return (opV3F_world->getPlayer()->getPosition() - opV3F_d1d9dc) == center;
}

bool CMap::unknown805100()
{
	Pos local = absToLocal(opV3F_mouse->getPos_40a970());
	if (local.x < 0 || local.y < 0)
		return false;
	return ((OpV3F_Dims *)&opV3F_cells)->inBounds(local.x - scrollX,local.y - scrollY) && local.x < opV3F_screenWidth && local.y < opV3F_screenHeight;
}

bool CMap::unknown805190(Pos *out)
{
	if (!unknown805100())
		return false;
	else
	{
		Pos local = absToLocal(opV3F_mouse->getPos_40a970());
		out->set(local.x - scrollX,local.y - scrollY);
		return true;
	}
}

void CMap::unknown8051f0(Pos *min, Pos *max)
{
	if (scrollX >= 0)
	{
		min->x = 0;
		max->x = minInt(opV3F_screenWidth - 1 - scrollX,opV3F_cells.getWidth() - 1);
	}
	else
	{
		min->x = -scrollX;
		max->x = minInt(min->x + opV3F_screenWidth - 1,opV3F_cells.getWidth() - 1);
	}
	if (scrollY >= 0)
	{
		min->y = 0;
		max->y = minInt(opV3F_screenHeight - 1 - scrollY,((Array2D<XCell> *)&opV3F_cells)->getHeight() - 1);
	}
	else
	{
		min->y = -scrollY;
		max->y = minInt(min->y + opV3F_screenHeight - 1,((Array2D<XCell> *)&opV3F_cells)->getHeight() - 1);
	}
}

bool CMap::unknown8052f0(Pos *pos)
{
	Pos min;
	Pos max;
	unknown8051f0(&min,&max);
	return pos->x >= min.x && pos->x <= max.x && pos->y >= min.y && pos->y <= max.y;
}
