// op_x4c: BS::unknown6de330 (0x6de330), Beta 17.1. NOTE: class/method names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	int randomInRange_40c130() const;	// NOTE: placeholder name
};

class HEntity
{
public:
	int ID;
};

class HItem
{
public:
	int ID;
	class Item *operator->() const throw();	// 0x9b65b0
	void reset() throw();	// NOTE: placeholder name (0x9b7270)
};

struct OpX4c_Link	// NOTE: placeholder name
{
	HItem a;
	HItem b;
	class Item *itemA;
	class Item *itemB;
	bool isActive();	// NOTE: placeholder name (0x46d440)
};
extern vector<OpX4c_Link *> opx4c_links;	// NOTE: placeholder name (0xcf4760)
template <class T> void opx4c_deleteObjectAndStep(vector<T *> &v, unsigned int &i);	// NOTE: placeholder name (0x9de640, steps i back)

struct OpX4c_Loc	// NOTE: placeholder name
{
	int unknown0;
	int type;
	int depth;
	char pad0c[0x27 - 0xc];
	bool unknown27;
	bool unknown28;
	bool unknown29;
	bool unknown2a;
	bool unknown2b;
	bool unknown2c;
	bool unknown2d;
	bool unknown2e;
};

class OpX4c_HLoc	// NOTE: placeholder name
{
public:
	int ID;
	OpX4c_Loc *operator->() const;	// 0x9b7910
};
extern OpX4c_HLoc opx4c_location;	// NOTE: placeholder name (0xd1e888)
extern vector<OpX4c_HLoc> opx4c_locations;	// NOTE: placeholder name (0xd1e88c)

class OpX4c_Overmind	// NOTE: placeholder name (object at 0xcf6428)
{
public:
	void init(OpX4c_HLoc from, OpX4c_HLoc to);	// NOTE: placeholder name (0x674aa0)
};
extern OpX4c_Overmind opx4c_overmind;	// NOTE: placeholder name (0xcf6428)

class OpX4c_Tally	// NOTE: placeholder name (object at 0xcf6888)
{
public:
	void unknown691fb0(OpX4c_HLoc from, OpX4c_HLoc to);	// NOTE: placeholder name
};
extern OpX4c_Tally opx4c_tally;	// NOTE: placeholder name (0xcf6888)

class OpX4c_Audio	// NOTE: placeholder name (object at 0xd25450)
{
public:
	void unknown69d570(OpX4c_HLoc from, OpX4c_HLoc to);	// NOTE: placeholder name
};
extern OpX4c_Audio opx4c_audio;	// NOTE: placeholder name (0xd25450)

class OpX4c_Mode	// NOTE: placeholder name (object at 0xd1dd38)
{
public:
	void unknown6beeb0(OpX4c_HLoc from, OpX4c_HLoc to);	// 0x6beeb0
};
extern OpX4c_Mode opx4c_mode;	// NOTE: placeholder name (0xd1dd38)

class OpX4c_GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	void setEntryText(const string &key, const string &text);	// NOTE: placeholder name (0x46f700)
};
extern OpX4c_GameData opx4c_gameData;	// NOTE: placeholder name (0xd1e860)

class OpX4c_PlayerData	// NOTE: placeholder name (object at 0xcf45d8)
{
public:
	bool getField_46dd90();	// NOTE: placeholder name
};
extern OpX4c_PlayerData opx4c_playerData;	// NOTE: placeholder name (0xcf45d8)

struct OpR1h_Stats
{
	bool add4729d0(unsigned int id, int value, string text, int extra) throw();	// NOTE: placeholder name
};
extern OpR1h_Stats opx4c_stats;	// NOTE: placeholder name (0xd2c658)

class OpX4c_Pending	// NOTE: placeholder name (object at 0xd338e4)
{
public:
	void unknown46e770(HEntity entity, int value);	// NOTE: placeholder name
};
extern OpX4c_Pending opx4c_pending;	// NOTE: placeholder name (0xd338e4)
extern int opx4c_pendingD338e0;	// NOTE: placeholder name

class OpX4c_Handle	// NOTE: placeholder name
{
public:
	int ID;
	class OpX4c_Slot *operator->() const;	// 0x9b73b0
};

class OpX4c_Slot	// NOTE: placeholder name
{
public:
	int take();	// NOTE: placeholder name (0x45e5c0)
};

int opx4c_find9db9d0(vector<int> &v, int value);	// NOTE: placeholder name (0x9db9d0)
int opx4c_decrease(int *value, int amount, int minimum);	// NOTE: placeholder name (0x9d0690)
void opx4c_playSound(int sound, int a, int b);	// NOTE: placeholder name (0x4541b0)

extern int opx4c_d257dc;	// NOTE: placeholder name
extern int opx4c_d1eb68;	// NOTE: placeholder name
extern int opx4c_d1eb54;	// NOTE: placeholder name
extern int opx4c_cf4b20;	// NOTE: placeholder name
extern int opx4c_cf462c;	// NOTE: placeholder name (game mode)
extern vector<int> opx4c_cf4704;	// NOTE: placeholder name
extern Point opx4c_rangeCfd2dc;	// NOTE: placeholder name (0xcfd2dc)

class OpX4c_World;
extern OpX4c_World *opx4c_world;	// NOTE: placeholder name (0xcefc4c)

class BS	// NOTE: placeholder name
{
public:
	char pad0[0x118];
	vector<vector<int> > unknown118;
	char pad128[0x65c - 0x128];
	OpX4c_Handle unknown65c;
	char pad660[0xac0 - 0x660];
	vector<int> unknownAc0;
	char padAd0[0xae4 - 0xad0];
	vector<int> unknownAe4;
	vector<int> unknownAf4;

	bool unknown6de330();	// NOTE: placeholder name
};

class OpX4c_World
{
public:
	char pad0[0x65c];
	OpX4c_Handle unknown65c;
	HEntity getPlayer();	// 0x4630f0
};

bool BS::unknown6de330()
{
	for (unsigned int i = 0; i < unknownAe4.size(); i++)
	{
		if (opx4c_find9db9d0(unknownAc0,unknownAe4[i]) != unknownAf4[i])
			goto fail;
	}
	switch (opx4c_location->type)
	{
	case 2:
		if (opx4c_location->depth == 8 && unknown118[5].empty())
			goto fail;
	}
	if (opx4c_locations.size() > 1)
	{
		OpX4c_HLoc last = opx4c_locations[opx4c_locations.size() - 2];
		OpX4c_HLoc cur = opx4c_location;
		opx4c_overmind.init(last,cur);
		opx4c_tally.unknown691fb0(last,cur);
		opx4c_audio.unknown69d570(last,cur);
		opx4c_mode.unknown6beeb0(last,cur);
		cur->unknown27 = true;
		if (cur->type == 0xc)
		{
			opx4c_playSound(0xa0,0,0);
			last->unknown28 = true;
		}
		else if (cur->type == 0xd)
			last->unknown29 = true;
		else if (cur->type == 0xe)
			last->unknown2a = true;
		if (last->type == 0xd)
		{
			if (last->depth != cur->depth || (opx4c_locations.size() >= 3 && opx4c_locations[opx4c_locations.size() - 3]->type != cur->type))
				cur->unknown2b = true;
		}
		if (last->type != 0xd)
			opx4c_gameData.setEntryText("garrisonRelaysDisabled_g","0");
		if (last->type == 0xe)
			cur->unknown2c = true;
		if (last->type > 6)
			cur->unknown2e = true;
		if (opx4c_d257dc < cur->depth && !opx4c_playerData.getField_46dd90())
			opx4c_d257dc = cur->depth;
		if (opx4c_d1eb68 != 0 && cur->depth < last->depth)
			opx4c_decrease(&opx4c_d1eb68,last->depth - cur->depth,0);
		if (opx4c_cf4b20 != 0 && cur->depth < last->depth)
			opx4c_d1eb54 += opx4c_rangeCfd2dc.randomInRange_40c130();
		opx4c_stats.add4729d0(1,1,"",-1);
		if (opx4c_cf462c == 0xb)
			opx4c_cf4704.assign(0x19u,0);
	}
	return true;
fail:
	opx4c_pendingD338e0 = opx4c_world->unknown65c->take();
	for (unsigned int j = 0; j < opx4c_links.size(); j++)
	{
		if (!opx4c_links[j]->isActive())
			opx4c_deleteObjectAndStep(opx4c_links,j);
		else
		{
			opx4c_links[j]->itemA = opx4c_links[j]->a.operator->();
			opx4c_links[j]->itemB = opx4c_links[j]->b.operator->();
			opx4c_links[j]->a.reset();
			opx4c_links[j]->b.reset();
		}
	}
	opx4c_pending.unknown46e770(opx4c_world->getPlayer(),0);
	return false;
}
