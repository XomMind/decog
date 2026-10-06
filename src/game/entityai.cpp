#include "entityai.h"

void EntityAI::addTargetScore(HEntity entity, int amount)
{
	unsigned int i;
	for (i = 0; i < targets.size(); i++)
	{
		if (targets[i]->entity == entity)
		{
			targets[i]->score += amount;
			break;
		}
	}
}

void EntityAI::prioritizeTarget(HEntity entity)
{
	addTarget(entity, 1, 10000, 0, 0);
	unsigned int i;
	for (i = 0; i < targets.size(); i++)
	{
		if (targets[i]->entity != entity)
			targets[i]->score = 1;
	}
}

void EntityAI::adjustTargetForOrder3(HEntity source, HEntity target)
{
	unsigned int i;
	if (order && order->type == 3 && order->subject == source)
	{
		for (i = 0; i < targets.size(); i++)
		{
			if (targets[i]->entity == target)
			{
				targets[i]->score += 10;
				break;
			}
		}
	}
}

void EntityAI::adjustTargetForOrder4(HEntity source, HEntity target)
{
	unsigned int i;
	if (order && order->type == 4 && order->subject == source)
	{
		for (i = 0; i < targets.size(); i++)
		{
			if (targets[i]->entity == target)
			{
				targets[i]->score += 10;
				break;
			}
		}
	}
}

void EntityAI::clearMemory()
{
	remembered.clear();
	preserveMemory = false;
}

void EntityAI::clearMemoryUnlessPreserved()
{
	if (!preserveMemory)
		clearMemory();
}
