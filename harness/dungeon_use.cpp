// Not game code: references header-inline members so they get emitted for matching
// until their real callers are decompiled.
#include "../src/dungeon/df.h"

void harness_dungeon(istream &in, const Pos &pos)
{
	DF::Tunneler *tunneler = new DF::Tunneler();
	tunneler->load(in);
	tunneler->resetWidth();
	tunneler->setParam38(1);
	delete tunneler;
	tunneler = new DF::Tunneler(0,1,pos,2,3,4,5,6,7,8,9,10,true);
	delete tunneler;
	DF::Roomie *roomie = new DF::Roomie(0,1,pos,2,3);
	delete roomie;
}
