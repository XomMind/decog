#include "../pathing/gamedecl.h"

extern CellTerrainRecord *caveinWallTerrain;

CellEffect *Cell::getEffect(int type)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i]->record->type == type)
			return effects[i];
	}
	return 0;
}

bool Cell::isPassableFor(HEntity entity_)
{
	if (blocked)
		return false;
	if (terrain->passable)
	{
		if (open)
			return prop.isNull() || prop->isPassableFor(entity_);
		else
			return true;
	}
	else
	{
		return (open || (entity_.isValid() && entity_->canEnterCaveWall() && terrain == caveinWallTerrain)) &&
			(prop.isNull() || prop->isPassableFor(entity_));
	}
}

bool Cell::isPassableWithoutEntity()
{
	if (blocked)
		return false;
	if (terrain->passable)
	{
		if (open)
			return prop.isNull() || prop->isPassableFor(HEntity());
		else
			return true;
	}
	else
	{
		return open && (prop.isNull() || prop->isOpenPassage());
	}
}

// NOTE: placeholder names. Three original helpers test placement footprints.
extern bool isFootprintOpen(const Point &position, int size);
extern bool footprintHasEntity(const Point &position, int size);
extern bool footprintHasImpassableTile(const Point &position, int size);

bool Cell::canPlaceEntity(int size)
{
	return isFootprintOpen(position, size) &&
		!footprintHasEntity(position, size) &&
		!footprintHasImpassableTile(position, size);
}

int Cell::getArmor()
{
	return prop.isValid() && prop->usesWallArmor() ?
		caveinWallTerrain->armor : terrain->armor;
}

HEntity Cell::getEntity()
{
	return entity;
}

int Cell::getEffectValue(int type)
{
	for (unsigned int i = 0; i < effects.size(); i++)
	{
		if (effects[i]->record->type == type)
			return effects[i]->value;
	}
	return 0;
}

HProp Cell::getProp()
{
	return prop;
}

bool Cell::canPlaceItem()
{
	return (prop.isNull() || prop->isPassableFor(HEntity())) && open;
}

int findItemIndex(vector<HItem> &v, HItem item);	// NOTE: placeholder name (0x9d3110)
void eraseItemAt(vector<HItem> &v, int index);	// NOTE: placeholder name (0x9da940)
bool eraseItem(vector<HItem> &v, HItem item);	// NOTE: placeholder name (0x9d2f00)
extern vector<HItem> mapItems;	// NOTE: placeholder name (0xd33d74)
void logError(string location, string message);	// NOTE: placeholder name

void Cell::removeItem(HItem item)
{
	int index = findItemIndex(items, item);
	if (index == -1)
	{
		logError("Cell::removeItem()","Item does not exist (null), crashing to produce trace...");
		volatile int zero = 0;
		int crash = 1 / zero;
	}
	eraseItemAt(items, index);
	eraseItem(mapItems, item);
}
