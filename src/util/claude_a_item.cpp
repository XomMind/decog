// claude_a: Item 0x571820 (pool init after OpU5s2_Factory::createD): set the handle, build the status list,
// register with the world and queue a turn slot for items that need one.
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
using namespace std;

class Item;
struct OpS1c_Data;

class HItem
{
	int	ID;
public:
	Item *operator->() const;
};

class OpS1c_RecList	// NOTE: placeholder name
{
public:
	OpS1c_RecList(vector<OpS1c_Data*> list);	// NOTE: placeholder name (0x456280)

	vector<OpS1c_Data*> records;
	int turn;
};

struct ItemData	// NOTE: placeholder layout
{
	char pad00[0x1e0];
	vector<OpS1c_Data*> unknown1e0;		// NOTE: placeholder name
};

class BS
{
public:
	void unknown464f60(HItem item);		// NOTE: placeholder name
	void unknown465060(HItem item);		// NOTE: placeholder name
};
extern BS *world;

struct ClaudeA_TurnRef	// NOTE: placeholder name (4-byte handle copy, folds to 0x9f57e0)
{
	ClaudeA_TurnRef(HItem h);
	int ID;
};

class ClaudeA_TurnSlot	// NOTE: placeholder name (0x45e530)
{
public:
	ClaudeA_TurnSlot(int type, ClaudeA_TurnRef *ref);
	char pad[0x10];
};

class HTurnClock	// NOTE: placeholder name
{
	int ID;
};

class ClaudeA_TurnQueue	// NOTE: placeholder name (0xd225a0)
{
public:
	HTurnClock add(ClaudeA_TurnSlot *slot, int delay);	// 0x672310
};
extern ClaudeA_TurnQueue claudeA_turnQueue_d225a0;	// NOTE: placeholder name

class Item
{
public:
	char pad00[4];
	HItem self;					// +0x04
	ItemData *data;				// +0x08
	char pad0c[0x58 - 0xc];
	OpS1c_RecList *statuses;	// +0x58 NOTE: placeholder name

	void init(HItem h);			// NOTE: placeholder name (0x571820)
	bool unknown571d70();		// NOTE: placeholder name
};

void Item::init(HItem h)
{
	self = h;
	if (!data->unknown1e0.empty())
	{
		statuses = new OpS1c_RecList(data->unknown1e0);
		world->unknown464f60(self);
	}
	world->unknown465060(self);
	if (unknown571d70())
		claudeA_turnQueue_d225a0.add(new ClaudeA_TurnSlot(2,new ClaudeA_TurnRef(self)),0);
}

// Defined here so LTCG proves the constructor nothrow (no EH state around its new, result slot kept).
ClaudeA_TurnRef::ClaudeA_TurnRef(HItem h)
{
	ID = *(int *)&h;
}
