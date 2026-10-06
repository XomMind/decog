#include "../pathing/gamedecl.h"

// NOTE: placeholder names. This grid stores original terrain, before excavation.
extern Array2D<int> originalTerrain;
extern CellTerrainRecord *caveinEarthTerrain;
extern CellTerrainRecord *caveinWallTerrain;
extern CellTerrainRecord *caveinThirdTerrain;

bool Cell::canCaveIn()
{
	return open &&
		(originalTerrain(position) == caveinEarthTerrain->ID ||
		 originalTerrain(position) == caveinWallTerrain->ID ||
		 originalTerrain(position) == caveinThirdTerrain->ID) &&
		!getEffect(5);
}

int Cell::getCaveinInstability()
{
	return caveinInstability;
}

// NOTE: placeholder name. Values are copied from the original read-only table.
extern const int caveinInstabilityIncrease[];

void Cell::destabilize(int cause, bool force)
{
	if (cause >= 2 &&
		(originalTerrain(position) == caveinWallTerrain->ID ||
		 originalTerrain(position) == caveinThirdTerrain->ID) &&
		!force)
		return;
	if (caveinInstability == 0)
	{
		caveinInstability = caveinInstabilityIncrease[0];
		world->registerUnstableCell(position);
	}
	caveinInstability += caveinInstabilityIncrease[cause];
}
