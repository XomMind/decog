// Entity::getInventoryList with a vector<HItemB> return type (0x45ab00, 19-byte `lea eax, [this+0x134]`).
// The return type is part of the decorated name, and callers disagree about the element type of the inventory list, so
// each element type the callers use needs its own definition (one file each: they cannot overload on return type).
#include <vector>

class HItemB;

class Entity	// NOTE: placeholder layout
{
	char	pad[0x134];
	int		items;

public:
	std::vector<HItemB> *getInventoryList();	// 0x45ab00
};

std::vector<HItemB> *Entity::getInventoryList()
{
	return (std::vector<HItemB> *) &items;
}
