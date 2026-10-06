#include "../pathing/gamedecl.h"

// Identity check used throughout damage, perception, and movement code.
// 0x5c7600 compares this entity's handle with the world's player handle.
bool Entity::isPlayer()
{
	return handle == world->getPlayer();
}
