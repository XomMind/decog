// Entity::getInventoryList with a vector<HItem> return type (0x45ab00, 19-byte `lea eax, [this+0x134]`).
// The return type is part of the decorated name, and callers disagree about the element type of the inventory list, so
// each element type the callers use needs its own definition (one file each: they cannot overload on return type).
#include <vector>

class HItem;

class Entity	// NOTE: placeholder layout
{
	char	pad[0x134];
	int		items;

public:
	std::vector<HItem> *getInventoryList();	// 0x45ab00
};

std::vector<HItem> *Entity::getInventoryList()
{
	return (std::vector<HItem> *) &items;
}
