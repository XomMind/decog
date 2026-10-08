// alpha2_08: Entity position triggers (0x5fdd30): fires the script triggers for the cells, neighbors and props
//	an entity now occupies, then springs any traps under it. Returns false if the entity did not survive.
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <string>
#include <vector>
#include <algorithm>
#include "rng.h"
using std::string;
using std::vector;
extern RNG rng;

struct A2TEntity;
struct A2TProp;
struct A2TItem;
struct A2TPoint
{
	int x;
	int y;
	A2TPoint(const A2TPoint &other) throw();	// 0x46ca50
	A2TPoint(const A2TPoint &base, const A2TPoint &direction) throw();	// 0x4099f0
};
struct A2THandle	// HEntity / HProp / HItem (one id)
{
	int id;
	A2THandle() throw();	// 0x9b6590
	A2TEntity *get_9b6570() const throw();
	A2TProp *get_9b64f0() const throw();
	A2TItem *get_9b65b0() const throw();
	bool valid_9b7230() const throw();
	bool operator<(const A2THandle &other) const { return id < other.id; }
	bool operator==(const A2THandle &other) const { return id == other.id; }
};
struct A2TGroup
{
	int type_9b4350() throw();
};
struct A2TGroupHandle
{
	int id;
	A2TGroup *get_9b7250() const throw();
};
struct A2TRecList
{
	bool hasType_456490(int type);
};
struct A2TTrapRec
{
	bool armedFor_65cf50(int faction);
	bool disabled_65cf80();
};
struct A2TProp
{
	void *inventory_45c9b0() throw();
	const string &getName_45c5b0() throw();
	bool unknown45cb50() throw();
	bool unknown45cc10();
	void unknown45ce80(A2THandle entity, bool flag);
	A2TTrapRec *trap_44b020() throw();
};
struct A2TItem
{
	int triggerChance_457fd0() throw();
	string getName_571db0(bool full, bool label);
};
struct A2TCell
{
	A2THandle getProp_45d550();
	bool hasTrap_45dcf0();
	void removeProp_66c100(bool a, int b);
	void trigger_66c290();
};
struct A2TGrid
{
	A2TCell **atPoint_9ced70(A2TPoint &p) throw();
	bool contains_9b43b0(A2TPoint &p);
};
struct A2TMap
{
	A2THandle getPlayer_4630f0();
	bool isVisible_4631c0(A2TPoint &p);
	bool active_464c50();
	void entitiesAround_71c550(A2THandle entity, vector<A2THandle> &list);
	void propsAround_71c6d0(A2THandle entity, vector<A2THandle> &list);
	bool detect_728b00(A2TPoint p, int *count);
};
struct A2TStats
{
	bool add_4729d0(unsigned int id, int value, string text, int extra);
};
struct A2TEffect
{
	void init_503b20();
};
struct A2TEffects
{
	A2TEffect *create_508610(A2TEffects *owner, int id, A2TPoint &pos, void *color, int a, int b, int c, int d, int e);
};
struct A2TConsole
{
	void bubble_8758d0(bool flag);
};
struct A2TLog
{
	void scrollToEnd_7b4f10();
};
struct A2TEntityDef
{
	char pad0[0x28];
	int type;	// +0x28
	char pad2c[0x9c - 0x2c];
	int size;	// +0x9c
};

extern A2TMap *a2t_map_cefc4c;
extern A2TGrid a2t_grid_cfd44c;
extern A2TStats a2t_stats_d2c658;
extern A2TEffects *a2t_effects_cefc50;
extern A2TConsole *a2t_console_cec058;
extern A2TLog *a2t_log_cec0b4;
extern A2TPoint a2t_directions_d015d8[];
extern char a2t_color_d2e20c[];
extern const char a2t_empty_b94b7d[];

bool a2t_trigger_4569a0(int type, A2THandle a, A2THandle b, A2THandle c, A2THandle d, A2TPoint *pos, const string *name, void *data, A2THandle e, A2THandle f, A2THandle g, A2TPoint *pos2);
bool a2t_show_5111e0(int id, const string &text, const string *a, string *b, A2THandle entity, A2THandle other, A2TPoint *pos, int d);
bool a2t_lookup_9d7980(const string &name, int *id);
void a2t_shuffle_9d7350(vector<A2TPoint> &list);
bool a2t_contains_9d0ce0(vector<A2TPoint> &list, A2TPoint p);
int a2t_indexOf_9d53a0(vector<A2TPoint> &list, A2TPoint p);
void a2t_move_9d9020(vector<A2TPoint> &list, unsigned int from, unsigned int to);
void a2t_eraseAt_9d5190(vector<A2TPoint> &list, int index);

struct A2TEntity
{
	bool checkTriggers();
	A2THandle getItem_5d2380(int slot);
	void getItems_5d2430(int slot, vector<A2THandle> &items);
	void trapCells_5c89d0(vector<A2TPoint> &cells);
	void *effect_45ac40(int effect);
	bool hostile_45aaa0(A2THandle other);
	bool player_5c7600() throw();
	void *getInventory_45ad90() throw();

	int pad0;
	A2THandle self;	// +0x04
	A2TEntityDef *def;	// +0x08
	char padc[0x28 - 0x0c];
	A2TGroupHandle faction;	// +0x28
	char pad2c[0x30 - 0x2c];
	vector<A2TPoint> cells;	// +0x30
	char pad40[0x50 - 0x40];
	int moving;	// +0x50
	int direction;	// +0x54
	char pad58[0xec - 0x58];
	A2TRecList *triggers;	// +0xec
};

#define H A2THandle()

bool A2TEntity::checkTriggers()
{
	A2THandle current = self;
	if (triggers)
	{
		if (a2t_trigger_4569a0(0,self,H,H,H,0,0,triggers,self,H,H,0) && !current.get_9b6570())
			return false;
		if (triggers && (triggers->hasType_456490(51) || triggers->hasType_456490(52)))
		{
			for (unsigned int i = 0; i < cells.size(); i++)
			{
				if (a2t_grid_cfd44c.atPoint_9ced70(cells[i])[0]->getProp_45d550().valid_9b7230() && a2t_trigger_4569a0(51,self,H,a2t_grid_cfd44c.atPoint_9ced70(cells[i])[0]->getProp_45d550(),H,0,0,triggers,self,H,H,0) && !current.get_9b6570())
					return false;
				if (a2t_grid_cfd44c.atPoint_9ced70(cells[i])[0]->getProp_45d550().valid_9b7230() && a2t_trigger_4569a0(52,self,H,a2t_grid_cfd44c.atPoint_9ced70(cells[i])[0]->getProp_45d550(),H,0,0,triggers,H,a2t_grid_cfd44c.atPoint_9ced70(cells[i])[0]->getProp_45d550(),H,0) && !current.get_9b6570())
					return false;
			}
		}
		if (triggers && triggers->hasType_456490(1))
		{
			for (unsigned int i = 0; i < cells.size(); i++)
			{
				if (a2t_trigger_4569a0(1,self,H,H,H,&cells[i],0,triggers,H,H,H,&cells[i]) && !current.get_9b6570())
					return false;
			}
		}
	}
	vector<A2THandle> entities;
	a2t_map_cefc4c->entitiesAround_71c550(self,entities);
	if (!entities.empty())
	{
		std::sort(entities.begin(),entities.end());
		entities.erase(std::unique(entities.begin(),entities.end()),entities.end());
		for (unsigned int i = 0; i < entities.size(); i++)
		{
			if (entities[i].get_9b6570())
			{
				if (a2t_trigger_4569a0(41,entities[i],self,H,H,0,0,entities[i].get_9b6570()->getInventory_45ad90(),self,H,H,0) && !current.get_9b6570())
					return false;
				if (a2t_trigger_4569a0(42,self,H,H,H,0,0,entities[i].get_9b6570()->getInventory_45ad90(),entities[i],H,H,0) && !current.get_9b6570())
					return false;
			}
			if (entities[i].get_9b6570())
			{
				if (a2t_trigger_4569a0(43,self,entities[i],H,H,0,0,triggers,self,H,H,0) && !current.get_9b6570())
					return false;
				if (a2t_trigger_4569a0(44,self,H,H,H,0,0,triggers,entities[i],H,H,0) && !current.get_9b6570())
					return false;
			}
		}
	}
	vector<A2THandle> props;
	for (unsigned int i = 0; i < cells.size(); i++)
	{
		if (a2t_grid_cfd44c.atPoint_9ced70(cells[i])[0]->getProp_45d550().valid_9b7230())
			props.push_back(a2t_grid_cfd44c.atPoint_9ced70(cells[i])[0]->getProp_45d550());
	}
	if (!props.empty())
	{
		for (unsigned int i = 0; i < props.size(); i++)
		{
			if (a2t_trigger_4569a0(50,self,H,props[i],H,0,&props[i].get_9b64f0()->getName_45c5b0(),props[i].get_9b64f0()->inventory_45c9b0(),H,props[i],H,0) && !current.get_9b6570())
				return false;
			if (props[i].get_9b64f0())
			{
				if (a2t_trigger_4569a0(49,self,H,props[i],H,0,&props[i].get_9b64f0()->getName_45c5b0(),props[i].get_9b64f0()->inventory_45c9b0(),self,H,H,0) && !current.get_9b6570())
					return false;
			}
		}
		props.clear();
	}
	a2t_map_cefc4c->propsAround_71c6d0(self,props);
	if (!props.empty())
	{
		std::sort(props.begin(),props.end());
		props.erase(std::unique(props.begin(),props.end()),props.end());
		for (unsigned int i = 0; i < props.size(); i++)
		{
			if (props[i].get_9b64f0())
			{
				if (a2t_trigger_4569a0(46,self,H,props[i],H,0,&props[i].get_9b64f0()->getName_45c5b0(),props[i].get_9b64f0()->inventory_45c9b0(),H,props[i],H,0) && !current.get_9b6570())
					return false;
			}
			if (props[i].get_9b64f0())
			{
				if (a2t_trigger_4569a0(45,self,H,props[i],H,0,&props[i].get_9b64f0()->getName_45c5b0(),props[i].get_9b64f0()->inventory_45c9b0(),self,H,H,0) && !current.get_9b6570())
					return false;
			}
			if (props[i].get_9b64f0())
			{
				if (a2t_trigger_4569a0(48,self,H,props[i],H,0,&props[i].get_9b64f0()->getName_45c5b0(),triggers,H,props[i],H,0) && !current.get_9b6570())
					return false;
			}
			if (props[i].get_9b64f0())
			{
				if (a2t_trigger_4569a0(47,self,H,props[i],H,0,&props[i].get_9b64f0()->getName_45c5b0(),triggers,self,H,H,0) && !current.get_9b6570())
					return false;
			}
		}
	}
	if (!props.empty() && faction.get_9b7250()->type_9b4350() == 3)
	{
		for (unsigned int i = 0; i < props.size(); i++)
		{
			if (props[i].get_9b64f0() && props[i].get_9b64f0()->unknown45cb50())
				props[i].get_9b64f0()->unknown45ce80(a2t_map_cefc4c->getPlayer_4630f0(),true);
		}
		if (!current.get_9b6570())
			return false;
	}
	if (def->type != 7)
	{
		if (def->size == 1)
			a2t_grid_cfd44c.atPoint_9ced70(cells[0])[0]->trigger_66c290();
		else
		{
			vector<A2TPoint> area(cells);
			for (unsigned int i = 0; i < area.size(); i++)
				a2t_grid_cfd44c.atPoint_9ced70(area[i])[0]->trigger_66c290();
		}
		if (!current.get_9b6570())
			return false;
	}
	if (a2t_map_cefc4c->active_464c50())
	{
		bool found = false;
		int count = 0;
		if (def->size == 1)
		{
			if (a2t_map_cefc4c->detect_728b00(cells[0],&count))
				found = true;
		}
		else
		{
			vector<A2TPoint> area(cells);
			for (unsigned int i = 0; i < area.size(); i++)
			{
				if (a2t_map_cefc4c->detect_728b00(area[i],&count))
					found = true;
			}
		}
		if (!current.get_9b6570())
			return false;
		if (found && count)
			a2t_stats_d2c658.add_4729d0(599,count,a2t_empty_b94b7d,-1);
	}
	if (getItem_5d2380(25).valid_9b7230() && !effect_45ac40(45))
	{
		vector<A2TPoint> nearby;
		trapCells_5c89d0(nearby);
		vector<A2TPoint> traps;
		for (unsigned int i = 0; i < nearby.size(); i++)
		{
			if (a2t_grid_cfd44c.atPoint_9ced70(nearby[i])[0]->hasTrap_45dcf0() && !a2t_grid_cfd44c.atPoint_9ced70(nearby[i])[0]->getProp_45d550().get_9b64f0()->trap_44b020()->disabled_65cf80()
				&& (faction.get_9b7250()->type_9b4350() > 2 || a2t_grid_cfd44c.atPoint_9ced70(nearby[i])[0]->getProp_45d550().get_9b64f0()->unknown45cc10())
				&& a2t_grid_cfd44c.atPoint_9ced70(nearby[i])[0]->getProp_45d550().get_9b64f0()->trap_44b020()->armedFor_65cf50(faction.get_9b7250()->type_9b4350()))
				traps.push_back(nearby[i]);
		}
		if (!traps.empty())
		{
			a2t_shuffle_9d7350(traps);
			if (moving)
			{
				A2TPoint p(cells[0],a2t_directions_d015d8[direction]);
				if (a2t_grid_cfd44c.contains_9b43b0(p) && a2t_contains_9d0ce0(traps,p))
					a2t_move_9d9020(traps,a2t_indexOf_9d53a0(traps,p),0);
			}
			vector<A2THandle> items;
			getItems_5d2430(25,items);
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (rng.chance(items[i].get_9b65b0()->triggerChance_457fd0()))
				{
					do{if(a2t_show_5111e0(player_5c7600() ? 529 : hostile_45aaa0(a2t_map_cefc4c->getPlayer_4630f0()) ? 530 : 531,items[i].get_9b65b0()->getName_571db0(false,false),&a2t_grid_cfd44c.atPoint_9ced70(traps.front())[0]->getProp_45d550().get_9b64f0()->getName_45c5b0(),0,self,H,&traps.front(),0))a2t_console_cec058->bubble_8758d0(true);a2t_log_cec0b4->scrollToEnd_7b4f10();}while(false);
					a2t_grid_cfd44c.atPoint_9ced70(traps.front())[0]->removeProp_66c100(false,4);
					if (a2t_map_cefc4c->isVisible_4631c0(traps.front()))
					{
						int id;
						if (a2t_lookup_9d7980("Trap_Scan_Disable",&id))
							a2t_effects_cefc50->create_508610(a2t_effects_cefc50,id,traps.front(),a2t_color_d2e20c,0,0,0,9,0)->init_503b20();
					}
					a2t_eraseAt_9d5190(traps,0);
					if (traps.empty())
						break;
				}
			}
		}
	}
	return true;
}
