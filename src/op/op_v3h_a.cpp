// op_v3h_a: CMap item pickup handling (COGMIND.exe Beta 17.1).
#include "op/op_v3h.h"

bool OpV3h_Map::unknown826920(HEntity player)
{
	HItem item = opV3h_cells(player->getPosition())->getItem();
	switch (player->unknown5db2b0(item,false))
	{
		case 0:
			do
			{
				if (OpV3h_unknown5111e0(0,item->getName_571db0(0,0),0,0,player,HProp(),0,0))
					opV3h_msgConsole->unknown8758d0(true);
				opV3h_logMsgs->scrollToEnd();
			}
			while (0);
			opV3h_world->playerActionFinish(3,player->unknown6421a0(false));
			break;
		case 3:
			OpV3h_message7b1750(4,0,0,0,player,HProp(),0);
			break;
		case 4:
			OpV3h_message7b1750(5,0,0,0,player,HProp(),0);
			break;
		case 5:
			OpV3h_message7b1750(6,0,0,0,player,HProp(),0);
			break;
		case 6:
			OpV3h_message7b1750(7,0,0,0,player,HProp(),0);
			break;
		case 2:
			OpV3h_message7b1750(3,0,0,0,player,HProp(),0);
			break;
		case 7:
			if (player->unknown5db2b0(item,true) == 0 && opV3h_cf4830[item->unknown457820()] != 0)
			{
				vector<HItem> items;
				player->unknown5cb830(&items);
				HItem found = OpV3h_unknown4fd9e0(item,items,true);
				if (found.isValid())
				{
					if (opV3h_inventory->unknown8a4ec0(found,false))
						return true;
					do
					{
						if (OpV3h_unknown5111e0(0,item->getName_571db0(0,0),0,0,player,HProp(),0,0))
							opV3h_msgConsole->unknown8758d0(true);
						opV3h_logMsgs->scrollToEnd();
					}
					while (0);
					opV3h_world->playerActionFinish(3,player->unknown6421a0(false));
					break;
					break;
				}
				else
				{
					OpV3h_message7b1750(0xd,intToString(item->unknown4578c0()),0,0,player,HProp(),0);
					return false;
				}
			}
			OpV3h_message7b1750(0xd,intToString(item->unknown4578c0()),0,0,player,HProp(),0);
			break;
	}
	return true;
}

void OpV3h_Map::unknown826e50(HEntity player, bool flagA, bool flagB)
{
	HItem item = opV3h_cells(player->getPosition())->getItem();
	switch (player->unknown5db2b0(item,true))
	{
		case 0:
			if (opV3h_parts->unknown89d780())
				opV3h_rex.getHighlighter()->unknown42ded0();
			if (!opV3h_inventory->attemptEquip(item,1,0x20,0))
			{
				bool ok = false;
				if (flagA)
				{
					if (!unknown826920(player))
						ok = true;
				}
				else
					ok = true;
				if (ok)
				{
					if (opV3h_tickCount > unknown640 + 500 || player->getPosition() != unknown644)
					{
						unknown640 = opV3h_tickCount;
						unknown644 = player->getPosition();
						OpV3h_message7b1750(0x21,0,0,0,player,HProp(),0);
						opV3h_audio->showOnce(0x19,true,NULL,false,false);
					}
					else
						opV3h_partswap->open(0,0,item,flagB);
				}
			}
			else if (opV3h_popup != NULL && item.operator->() != NULL && item->unknown457920() > opV3h_gameState->getDepthIndex() && item == opV3h_world->getEntity671()->getAI_45b590()->unknown4592c0() && opV3h_popup != NULL)
				opV3h_popup->say(0x1a,false,item->getName_571db0(0,0));
			break;
		case 3:
			OpV3h_message7b1750(4,0,0,0,player,HProp(),0);
			break;
		case 4:
			OpV3h_message7b1750(5,0,0,0,player,HProp(),0);
			break;
		case 5:
			OpV3h_message7b1750(6,0,0,0,player,HProp(),0);
			break;
		case 6:
			OpV3h_message7b1750(7,0,0,0,player,HProp(),0);
			break;
		case 2:
			OpV3h_message7b1750(3,0,0,0,player,HProp(),0);
			break;
	}
}
