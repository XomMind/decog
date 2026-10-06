#include "df.h"
#include "../util/rng.h"

extern RNG rng;

int maxi(int a, int b);	// NOTE: placeholder name (0x9CDB60)

namespace DF
{

int Tunneler::build()
{
	return 0;
}

int Roomie::build()
{
	if (generator.getRoomCount(roomType) >= settings->rooms[roomType].maxCount) return 0;
	if (delay > generator.getTurn()) return 1;

	age++;
	int w = param1C;
	int rightSpace, leftSpace, roomW, roomH;
	do
	{
		int length = measure(pos,w,&leftSpace,&rightSpace,settings->roomMargin);
		if (length < 4 || leftSpace < 0 || rightSpace < 0) return 0;

		roomH = length;
		roomW = leftSpace + rightSpace;
		if ((float)roomW / roomH < settings->maxRoomRatio) roomH = (int)(roomW / settings->maxRoomRatio);
		else if ((float)roomH / roomW < settings->maxRoomRatio) roomW = (int)(roomH / settings->maxRoomRatio);

		while (roomW * roomH > settings->rooms[roomType].maxArea)
		{
			if (roomW > roomH) roomW--;
			else if (roomH > roomW) roomH--;
			else if (rng.chance(50)) roomW--;
			else roomH--;
		}

		if (roomW * roomH >= settings->rooms[roomType].minArea)
		{
			Pos roomPos(pos);
			if (leftSpace <= rightSpace)
			{
				if (leftSpace * 2 - settings->roomMargin > roomW) shiftPos(roomPos,dir,-roomW / 2,2);
				else shiftPos(roomPos,dir,maxi(-leftSpace,-roomW + 1),2);
			}
			else
			{
				if (rightSpace * 2 - settings->roomMargin > roomW) shiftPos(roomPos,dir,-roomW / 2,2);
				else shiftPos(roomPos,dir,rightSpace - roomW + 1,2);
			}

			Room newRoom;
			rooms.push_back(newRoom);
			Room* room = &rooms.back();
			room->type = roomType;
			switch (dir)
			{
				case 0: room->rect.set(roomPos.x,roomPos.y - roomH + 1,roomW,roomH); break;
				case 1: room->rect.set(roomPos.x,roomPos.y,roomH,roomW); break;
				case 2: room->rect.set(roomPos.x - roomW + 1,roomPos.y,roomW,roomH); break;
				case 3: room->rect.set(roomPos.x - roomH + 1,roomPos.y - roomW + 1,roomH,roomW); break;
			}

			for (int x = room->rect.x; x < room->rect.x + room->rect.width; x++)
				for (int y = room->rect.y; y < room->rect.y + room->rect.height; y++)
					grid.at(x,y) = 7;

			Pos entry(pos);
			shiftPos(entry,dir,0,1);
			grid.at(entry) = (dir == 0 || dir == 2) ? 10 : 11;

			generator.addRoomCount(roomType);
			return 0;
		}
		else w += 2;
	} while (roomH >= (2.0 * roomW + 1.0) * settings->maxRoomRatio);

	return 0;
}

}
