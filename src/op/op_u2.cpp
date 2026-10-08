// op_u2: assorted functions in 0x4c5000-0x5ba000
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Pos
{
	int x;
	int y;

	Pos();	// 0x453b40
	Pos(int x_, int y_);	// 0x46ca20
	Pos(int value);	// 0x409990
	Pos(const Pos &pos);
	Pos &operator=(const Pos &pos);	// 0x46ca50
	bool operator==(const Pos &pos) const;	// 0x409b90
};

class SoundData;
int soundPlayRelative(const Pos &pos, SoundData *sound, int channel, bool noPlay);	// NOTE: name from log string (0x4ff170)
int opY3_playSound(SoundData *sound, int channel, int fade, int loopsB, int loops);	// NOTE: placeholder name (0x4ff050)

class OpU2_Mixer	// NOTE: placeholder name (0xcefa90)
{
public:
	void unknown419c50();	// NOTE: placeholder name
	void unknown41a1f0(int channel, int value);	// NOTE: placeholder name
	void unknown41a210(int channel);	// NOTE: placeholder name
};
extern OpU2_Mixer *opu2_mixer;	// NOTE: placeholder name (0xcefa90)

struct OpU2_Channel	// NOTE: placeholder name
{
	int id;
	char pad4[0x1c];
	int mode;
	char pad24[4];
	int count;
};

struct OpU2_Event	// NOTE: placeholder name
{
	int trigger;
	float time;
	int type;
	SoundData *sound;
	OpU2_Channel *channel;
	int value;
};

struct OpU2_Timeline	// NOTE: placeholder name
{
	char pad0[0xdc];
	vector<OpU2_Event> events;
	bool hasSounds;	// NOTE: placeholder name
};

class OpU2_Player	// NOTE: placeholder name
{
public:
	OpU2_Timeline *timeline;
	char pad4[4];
	unsigned int start;
	char pad10[0x88];
	vector<int> done;

	void unknown50d500(const OpU2_Event &event);	// 0x50d500
	void unknown50d6c0(int trigger);	// 0x50d6c0
	void kill();	// 0x50e830
};
extern bool opu2_audioDisabled;	// NOTE: placeholder name (0xd28cbc)
extern unsigned int opu2_ticks;	// NOTE: placeholder name (0xcaed20)

void OpU2_Player::unknown50d500(const OpU2_Event &event)
{
	switch (event.type)
	{
	case 0:
		opu2_mixer->unknown419c50();
		break;
	case 1:
		opY3_playSound(event.sound, -1, 0, 0, event.value);
		break;
	case 2:
		switch (event.channel->mode)
		{
		case 0:
			opY3_playSound(event.sound, event.channel->id, 0, 0, event.value);
			break;
		case 1:
			if (event.channel->count == 0)
				opY3_playSound(event.sound, event.channel->id, 0, 0, event.value);
			event.channel->count = event.channel->count + 1;
			break;
		}
		break;
	case 3:
		opu2_mixer->unknown41a210(event.channel->id);
		opY3_playSound(event.sound, event.channel->id, 0, 0, event.value);
		break;
	case 4:
		if (event.channel->count != 0)
			event.channel->count = event.channel->count - 1;
		if (event.channel->count == 0)
			opu2_mixer->unknown41a210(event.channel->id);
		break;
	case 5:
		opu2_mixer->unknown41a210(event.channel->id);
		event.channel->count = 0;
		break;
	case 6:
		opu2_mixer->unknown41a1f0(event.channel->id, event.value);
		break;
	}
}

void OpU2_Player::unknown50d6c0(int trigger)
{
	for (unsigned int i = 0; i < timeline->events.size(); i++)
	{
		if (timeline->events[i].trigger == trigger)
		{
			switch (trigger)
			{
			case 0:
			case 2:
				unknown50d500(timeline->events[i]);
				break;
			case 1:
				if (done[i] == 0)
				{
					if ((double)(opu2_ticks - start) >= timeline->events[i].time)
					{
						done[i] = 1;
						unknown50d500(timeline->events[i]);
					}
				}
				break;
			}
		}
	}
}

struct OpU2_Event2	// NOTE: placeholder name
{
	int trigger;
	int time;
	char data[0x1c];
};

struct OpU2_Timeline2	// NOTE: placeholder name
{
	char pad0[0xf0];
	vector<OpU2_Event2> events;
};

class OpU2_Receiver	// NOTE: placeholder name
{
public:
	virtual void slot0();
	virtual void slot1();
	virtual void slot2();
	virtual void slot3();
	virtual void slot4();
	virtual void slot5();
	virtual void slot6();
	virtual void slot7();
	virtual void slot8();
	virtual void slot9();
	virtual void slot10();
	virtual void handle(void *data, class OpU2_Player2 *player);	// vtable slot 0x2c
};

class OpU2_Player2	// NOTE: placeholder name
{
public:
	OpU2_Timeline2 *timeline;
	OpU2_Receiver **receiver;
	unsigned int start;
	char padc[0x98];
	vector<int> delays;

	void unknown50d7f0(int trigger);	// 0x50d7f0
};

void OpU2_Player2::unknown50d7f0(int trigger)
{
	for (unsigned int i = 0; i < timeline->events.size(); i++)
	{
		if (timeline->events[i].trigger == trigger)
		{
			switch (trigger)
			{
			case 0:
			case 2:
				(*receiver)->handle(timeline->events[i].data,this);
				break;
			case 1:
				if (timeline->events[i].time < 0)
				{
					while ((double)(opu2_ticks - start) - delays[i] > (double)abs(timeline->events[i].time))
					{
						(*receiver)->handle(timeline->events[i].data,this);
						delays[i] += abs(timeline->events[i].time);
					}
				}
				else if (delays[i] == 0)
				{
					if ((double)(opu2_ticks - start) >= (double)timeline->events[i].time)
					{
						(*receiver)->handle(timeline->events[i].data,this);
						delays[i]++;
					}
				}
				break;
			}
		}
	}
}

//==================================================================
// positional sound timeline
//==================================================================

struct OpU2_Timeline3	// NOTE: placeholder name
{
	char pad0[0xc8];
	vector<OpU2_Event> events;
};

class OpU2_Player3	// NOTE: placeholder name
{
public:
	OpU2_Timeline3 *timeline;
	char pad4[4];
	unsigned int start;
	char padc[4];
	Pos pos;
	char pad18[0x1c];
	float volume;
	char pad38[0x6c];
	vector<int> done;

	void unknown5036d0(const OpU2_Event &event);	// 0x5036d0
	void unknown503930(int trigger);	// 0x503930
};

void OpU2_Player3::unknown5036d0(const OpU2_Event &event)
{
	switch (event.type)
	{
	case 0:
		opu2_mixer->unknown419c50();
		break;
	case 1:
		if (event.value)
			soundPlayRelative(pos,event.sound,-1,false);
		else
			opY3_playSound(event.sound,-1,0,0,0);
		break;
	case 2:
		switch (event.channel->mode)
		{
		case 0:
			if (event.value)
				soundPlayRelative(pos,event.sound,event.channel->id,false);
			else
				opY3_playSound(event.sound,event.channel->id,0,0,0);
			break;
		case 1:
			if (event.channel->count == 0)
			{
				if (event.value)
					soundPlayRelative(pos,event.sound,event.channel->id,false);
				else
					opY3_playSound(event.sound,event.channel->id,0,0,0);
			}
			event.channel->count = event.channel->count + 1;
			break;
		}
		break;
	case 3:
		opu2_mixer->unknown41a210(event.channel->id);
		if (event.value)
			soundPlayRelative(pos,event.sound,event.channel->id,false);
		else
			opY3_playSound(event.sound,event.channel->id,0,0,0);
		break;
	case 4:
		if (event.channel->count != 0)
			event.channel->count = event.channel->count - 1;
		if (event.channel->count == 0)
			opu2_mixer->unknown41a210(event.channel->id);
		break;
	case 5:
		opu2_mixer->unknown41a210(event.channel->id);
		event.channel->count = 0;
		break;
	case 6:
		opu2_mixer->unknown41a1f0(event.channel->id,event.value);
		break;
	}
}

void OpU2_Player3::unknown503930(int trigger)
{
	for (unsigned int i = 0; i < timeline->events.size(); i++)
	{
		if (timeline->events[i].trigger == trigger)
		{
			switch (trigger)
			{
			case 0:
			case 1:
			case 5:
				unknown5036d0(timeline->events[i]);
				break;
			case 2:
				if (done[i] == 0)
				{
					if ((double)(opu2_ticks - start) >= timeline->events[i].time)
					{
fire:
						done[i] = 1;
						unknown5036d0(timeline->events[i]);
					}
				}
				break;
			case 3:
				if (done[i] == 0 && volume >= 0.0)
					goto fire;
				break;
			case 4:
				if (done[i] == 0)
				{
					if (volume >= -timeline->events[i].time)
					{
						done[i] = 1;
						unknown5036d0(timeline->events[i]);
					}
				}
				break;
			}
		}
	}
}

//==================================================================
// item colors
//==================================================================

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct OpU2_SlotColor	// NOTE: placeholder name
{
	XColor color;
	int unknown04;
};

extern XColor *opu2_color_cf3fac;	// NOTE: placeholder name (0xcf3fac)
extern XColor *opu2_color_cf63b0;	// NOTE: placeholder name (0xcf63b0)
extern XColor *opu2_color_cfc180;	// NOTE: placeholder name (0xcfc180)
extern XColor *opu2_color_cfe5a0;	// NOTE: placeholder name (0xcfe5a0)
extern XColor *opu2_color_d15d98;	// NOTE: placeholder name (0xd15d98)
extern XColor *opu2_color_d1e048;	// NOTE: placeholder name (0xd1e048)
extern XColor *opu2_color_d201c4;	// NOTE: placeholder name (0xd201c4)
extern XColor *opu2_color_d20618;	// NOTE: placeholder name (0xd20618)
extern XColor *opu2_color_d20b78;	// NOTE: placeholder name (0xd20b78)
extern XColor *opu2_color_d23094;	// NOTE: placeholder name (0xd23094)
extern XColor *opu2_color_d25e0c;	// NOTE: placeholder name (0xd25e0c)
extern XColor *opu2_color_d2b284;	// NOTE: placeholder name (0xd2b284)
extern XColor *opu2_color_d2f170;	// NOTE: placeholder name (0xd2f170)
extern XColor *opu2_color_d32efc;	// NOTE: placeholder name (0xd32efc)
extern XColor *opu2_color_d3579c;	// NOTE: placeholder name (0xd3579c)
extern XColor *opu2_color_d38644;	// NOTE: placeholder name (0xd38644)
extern XColor *opu2_color_d386c8;	// NOTE: placeholder name (0xd386c8)
extern OpU2_SlotColor opu2_slotColors[];	// NOTE: placeholder name (0xd0161c)
extern XColor opu2_colors3[];	// NOTE: placeholder name (0xd216f8)
extern bool opu2_asciiEnabled;	// NOTE: placeholder name (0xd28d30)
extern bool opu2_flagD28def;	// NOTE: placeholder name (0xd28def)
extern vector<int> opu2_cf4830;	// NOTE: placeholder name

struct OpU2_ItemData	// NOTE: placeholder name
{
	int id;
	char pad4[0x20];
	string name;
	char pad40[4];
	int type;
	char pad48[8];
	int index;
};

class OpU2_Item	// NOTE: placeholder name
{
public:
	XColor *unknown5755f0(bool force);	// 0x5755f0

	char pad0[8];
	OpU2_ItemData *data;
	char padc[0x10];
	int level;
};

XColor *OpU2_Item::unknown5755f0(bool force)
{
	if (data->type <= 3)
	{
		switch (data->type)
		{
		case 0:
			if (level <= 0x19)
				return opu2_color_d32efc;
			if (level <= 0x32)
				return opu2_color_d201c4;
			if (level <= 0x4b)
				return opu2_color_d3579c;
			if (level <= 0x64)
				return opu2_color_d38644;
			if (level <= 0x7d)
				return opu2_color_d1e048;
			if (level <= 0x96)
				return opu2_color_d20b78;
			return opu2_color_cfc180;
		case 1:
		{
			XColor *color;
			XColor *other;
			color = (data->name == "Data Core" || data->name == "Schematic Archive") ? opu2_color_d25e0c : (other = (data->name == "Derelict Log") ? opu2_color_d23094 : opu2_color_cf63b0);
			return color;
		}
		case 2:
			return opu2_color_d20618;
		case 3:
			if (level <= 0xf)
				return opu2_color_d2f170;
			if (level <= 0x1e)
				return opu2_color_cfe5a0;
			if (level <= 0x2d)
				return opu2_color_d2b284;
			if (level <= 0x3c)
				return opu2_color_d386c8;
			if (level <= 0x4b)
				return opu2_color_cf3fac;
			if (level <= 0x5a)
				return opu2_color_cf63b0;
			return opu2_color_d15d98;
		default:
			return opu2_color_cfc180;
		}
	}
	else
	{
		if (opu2_asciiEnabled && opu2_flagD28def)
		{
			XColor *color = (!force && opu2_cf4830[data->id] == 0) ? opu2_colors3 : &opu2_colors3[data->index];
			return color;
		}
		else
			return &opu2_slotColors[data->type].color;
	}
}

//==================================================================
// effect list updates
//==================================================================

class OpS1c_RecList
{
public:
	bool hasTypeFlagA();	// 0x456540
	bool hasTypeFlagB();	// 0x4565a0
};

class OpU2_Prop;	// NOTE: placeholder name
class OpU2_Item2;	// NOTE: placeholder name

class HProp
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230 (folded)
	OpU2_Prop *operator->() const;	// 0x9b64f0
};

class HItem
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230 (folded)
	bool isNull() const;	// 0x9b65d0
	OpU2_Item2 *operator->() const;	// 0x9b65b0
};

class OpU2_Ent;	// NOTE: placeholder name

class OpU2_HEnt	// NOTE: placeholder name (HEntity)
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230 (folded)
	bool operator==(OpU2_HEnt e) const;	// 0x9b6620
	OpU2_Ent *operator->() const;	// 0x9b6570
};

class OpU2_Ent	// NOTE: placeholder name
{
public:
	vector<HItem> *getInventoryList();	// 0x45ab00
};

class OpU2_Prop	// NOTE: placeholder name
{
public:
	OpS1c_RecList *getEffects();	// 0x45c9b0
	Pos *getPos();	// 0x4184d0
	void unknown45cf60(int ID, bool flag);	// 0x45cf60
};

class OpU2_Item2	// NOTE: placeholder name (same object as OpU2_Item, only the methods used here)
{
public:
	OpS1c_RecList *getEffects();	// 0x44a7d0
	int getCategory();	// 0x44aec0
	bool unknown457d70();	// 0x457d70
	int unknown457970();	// 0x457970
	void unknown57dbe0(int a, int b, int c, int d);	// 0x57dbe0
	void unknown458690(int ID, bool flag);	// 0x458690
};

class OpU2_World	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	void unknown464f30(HProp prop);	// 0x464f30
	void unknown465030(HItem item);	// 0x465030
	int getTurn();	// 0x464270
	OpU2_HEnt getPlayer();	// 0x4630f0
};
extern OpU2_World *opu2_world;	// NOTE: placeholder name (0xcefc4c)
extern vector<int> opu2_d2c408;	// NOTE: placeholder name

void opu2_fn51d5e0(HProp prop, vector<int> ids, bool flag);	// NOTE: placeholder name (0x51d5e0)

void opu2_fn51d5e0(HProp prop, vector<int> ids, bool flag)
{
	bool hasFlag;
	bool hadFlag = prop->getEffects() && prop->getEffects()->hasTypeFlagA();
	for (unsigned int i = 0; i < ids.size(); i++)
		prop->unknown45cf60(opu2_d2c408[ids[i]],flag);
	hasFlag = prop->getEffects() && prop->getEffects()->hasTypeFlagA();
	if (hadFlag && !hasFlag)
		opu2_world->unknown464f30(prop);
}

void opu2_fn51d730(HItem item, vector<int> ids, bool flag);	// NOTE: placeholder name (0x51d730)

// BEGIN
void opu2_fn51d730(HItem item, vector<int> ids, bool flag)
{
	bool hasFlag;
	bool hadFlag = item->getEffects() && item->getEffects()->hasTypeFlagB();
	for (unsigned int i = 0; i < ids.size(); i++)
		item->unknown458690(opu2_d2c408[ids[i]],flag);
	hasFlag = item->getEffects() && item->getEffects()->hasTypeFlagB();
	if (hadFlag && !hasFlag)
		opu2_world->unknown465030(item);
}
// END

class OpU2_Cell	// NOTE: placeholder name
{
public:
	vector<HItem> *getItems();	// 0x463950
};

template <class T>
class OpU2_Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Pos &p);	// 0x9ced70
};
extern OpU2_Array2D<OpU2_Cell *> opu2_cells;	// NOTE: placeholder name (0xcfd44c)
void opu2_eraseStepBack(vector<HItem> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440)

void opu2_fn51d880(OpU2_HEnt owner, HProp prop, HItem item, const Pos *pos, vector<HItem> *result);	// NOTE: placeholder name (0x51d880)

// BEGIN
void opu2_fn51d880(OpU2_HEnt owner, HProp prop, HItem item, const Pos *pos, vector<HItem> *result)
{
	if (item.isValid())
		result->push_back(item);
	else if (owner.isValid())
	{
		vector<HItem> *inventory = owner->getInventoryList();
		for (unsigned int i = 0; i < inventory->size(); i++)
		{
			if ((*inventory)[i]->getCategory() <= 3)
			{
				result->push_back((*inventory)[i]);
				if (result->back().isNull())
					result->pop_back();
			}
		}
	}
	else
	{
		Pos at = prop.isValid() ? *prop->getPos() : (pos ? *pos : Pos(0));
		*result = *opu2_cells(at)->getItems();
	}
	for (unsigned int i = 0; i < result->size(); i++)
	{
		if (!(*result)[i].operator->())
			opu2_eraseStepBack(*result,i);
	}
}
// END

//==================================================================
// location rules
//==================================================================

struct Point
{
	int x;
	int y;

	bool contains_40c190(int value);	// 0x40c190
};

struct OpU2_Location	// NOTE: placeholder name
{
	int unknown0;
	int type;
	int unknown8;
	char padc[0x24];
	vector<int> visited;

	int getInverse();	// 0x46ed20
};

class OpU2_HLocation	// NOTE: placeholder name (global at 0xd1e888)
{
public:
	OpU2_Location *operator->() const;	// 0x9b7910
};
extern OpU2_HLocation opu2_location;	// NOTE: placeholder name (0xd1e888)
extern vector<int> opu2_d1e8d0;	// NOTE: placeholder name
bool opu2_contains(vector<int> &values, int value);	// NOTE: placeholder name (0x9db330)

class OpU2_Rule	// NOTE: placeholder name
{
public:
	int ID;
	char pad4[0x1c];
	int unknown20;
	char pad24[4];
	Point range;
	int limit;
	char pad34[0x4c];
	vector<int> allowed;

	bool unknown517290();	// 0x517290
};

bool OpU2_Rule::unknown517290()
{
	if (limit < 0)
		return opu2_contains(opu2_location->visited,unknown20);
	else
		return allowed[opu2_location->type] != 0 && (range.y == 0 || range.contains_40c190(opu2_location->getInverse())) && (limit == 0 || opu2_d1e8d0[ID] == 0 || opu2_d1e8d0[ID] < limit);
}

//==================================================================
// item upkeep
//==================================================================

struct OpU2_Spec	// NOTE: placeholder name
{
	int type;
	char pad4[0x20];

	bool unknown455f40(int value);	// 0x455f40
};

struct OpU2_SpecList	// NOTE: placeholder name
{
	char pad0[0x40];
	vector<OpU2_Spec> specs;
};

class OpU2_Tracker	// NOTE: placeholder name
{
public:
	OpU2_SpecList *list;
	char pad4[8];
	int count;
	int turn;

	void unknown5189b0(OpU2_HEnt owner);	// 0x5189b0
};

void OpU2_Tracker::unknown5189b0(OpU2_HEnt owner)
{
	count++;
	turn = opu2_world->getTurn();
	for (vector<OpU2_Spec>::iterator it = list->specs.begin(); it != list->specs.end(); ++it)
	{
		if (it->type == 0x2a)
		{
			vector<HItem> *inventory = owner->getInventoryList();
			for (unsigned int i = 0; i < inventory->size(); i++)
			{
				if ((*inventory)[i]->getCategory() <= 3 && (*inventory)[i]->unknown457d70() && it->unknown455f40((*inventory)[i]->unknown457970()))
				{
					(*inventory)[i]->unknown57dbe0(owner == opu2_world->getPlayer(),0,1,1);
					break;
				}
			}
		}
	}
}

//==================================================================
// follow-target rule
//==================================================================

class OpU2_HEnt2;	// NOTE: placeholder name

class OpU2_AI	// NOTE: placeholder name (EntityAI)
{
public:
	void setFollowEntity(OpU2_HEnt2 e, int value);	// NOTE: placeholder name
};

class OpU2_Group	// NOTE: placeholder name
{
public:
	vector<OpU2_HEnt2> *getMembers();	// NOTE: placeholder name (0x416f40)
};

class OpU2_HGroup	// NOTE: placeholder name
{
public:
	int ID;
	OpU2_Group *operator->() const;	// 0x9b7250
};

class OpU2_Ent2	// NOTE: placeholder name (Entity)
{
public:
	const Pos &getPosition();	// 0x45a4a0
	OpU2_AI *getAI();	// NOTE: placeholder name (0x45b590)
	void *getTarget();	// 0x45a760
	OpU2_HGroup getGroup();	// NOTE: placeholder name (0x45a3f0)
};

class OpU2_HEnt2	// NOTE: placeholder name (HEntity)
{
public:
	int ID;
	OpU2_HEnt2();	// ICF'd with HProp::HProp
	bool isValid() const;	// 0x9b7230 (folded)
	bool operator!=(OpU2_HEnt2 e) const;	// 0x9b6670
	OpU2_Ent2 *operator->() const;	// 0x9b6570
};

struct OpU2_FollowRule	// NOTE: placeholder name
{
	char pad0[0xc4];
	int mode;
	int value;
};

int OpQ1_distanceCeil_40a3f0(const Pos &a, const Pos &b);	// NOTE: placeholder name

struct OpU2_PlayerWorld	// NOTE: placeholder name (object at 0xcefc4c)
{
	OpU2_HEnt2 getPlayer();	// 0x4630f0
};
extern OpU2_PlayerWorld *opu2_world2;	// NOTE: placeholder name (0xcefc4c)

void opu2_fn51caa0(OpU2_FollowRule *rule, OpU2_HEnt2 e, OpU2_HEnt2 a, OpU2_HEnt2 b);	// NOTE: placeholder name (0x51caa0)

// BEGIN
void opu2_fn51caa0(OpU2_FollowRule *rule, OpU2_HEnt2 e, OpU2_HEnt2 a, OpU2_HEnt2 b)
{
	if (e->getAI())
	{
		switch (rule->mode)
		{
		default:
			break;
		case 1:
			if (a.operator->())
				e->getAI()->setFollowEntity(a,rule->value);
			break;
		case 2:
			if (b.operator->())
				e->getAI()->setFollowEntity(b,rule->value);
			break;
// BEGIN
		case 3:
		{
			int bestDistance;
			OpU2_HEnt2 best;
			bestDistance = 999999;
			vector<OpU2_HEnt2> *members = e->getGroup()->getMembers();
			int distance;
			unsigned int i;
			for (i = 0; i < members->size(); i++)
			{
				if (e != (*members)[i] && !(*members)[i]->getTarget())
				{
					distance = OpQ1_distanceCeil_40a3f0(e->getPosition(),(*members)[i]->getPosition());
					if (distance < bestDistance)
					{
						bestDistance = distance;
						best = (*members)[i];
					}
				}
			}
			if (best.isValid())
				e->getAI()->setFollowEntity(best,rule->value);
			break;
		}
// END

		case 4:
			if (!e->getGroup()->getMembers()->empty())
				e->getAI()->setFollowEntity(e->getGroup()->getMembers()->back(),rule->value);
			break;
		case 5:
			e->getAI()->setFollowEntity(opu2_world2->getPlayer(),rule->value);
			break;
		}
	}
}
// END

//==================================================================
// effect engine
//==================================================================

class XConsole
{
public:
	Pos getMaxCoord();
};

class OpU2_NoiseField	// NOTE: placeholder name
{
public:
	OpU2_NoiseField();	// 0x421650
	~OpU2_NoiseField();
	void init(int dimensions, float scale, int seed_);	// 0x421680

	char pad0[0x20];
};

struct OpU2_AnimInfo	// NOTE: placeholder name
{
	int unknown0;
	string name;
};

class OpU2_Anim	// NOTE: placeholder name
{
public:
	OpU2_AnimInfo *getInfo();	// 0x9fcd80
	Pos *getPos();	// 0x462e10
};

class OpU2_Engine	// NOTE: placeholder name
{
public:
	OpU2_Engine(XConsole *console_, Pos *size_, Pos *offset_);	// 0x50fa20
	string unknown50fc60(const Pos &pos);	// 0x50fc60

	XConsole *console;
	Pos size;
	Pos offset;
	vector<OpU2_Anim *> anims;
	vector<int *> dead;
	OpU2_NoiseField noise;
};

OpU2_Engine::OpU2_Engine(XConsole *console_, Pos *size_, Pos *offset_)
{
	console = console_;
	size = size_ ? *size_ : console->getMaxCoord();
	offset = offset_ ? *offset_ : Pos(0,0);
	noise.init(2,0.01f,30);
}

string OpU2_Engine::unknown50fc60(const Pos &pos)
{
	string text;
	if (!anims.empty())
	{
		for (int i = anims.size() - 1; i >= 0; i--)
		{
			if (*anims[i]->getPos() == pos)
			{
				if (!text.empty())
					text += ", ";
				text += anims[i]->getInfo()->name;
			}
		}
	}
	return text;
}

void OpU2_Player::kill()
{
	if (timeline->hasSounds)
	{
		do
		{
			if (!timeline->events.empty() && !opu2_audioDisabled)
				unknown50d6c0(2);
		} while (false);
	}
	start = 0;
}
