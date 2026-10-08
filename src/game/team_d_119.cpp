// team_d_119: Entity member 0x6421a0 (callers OpV3h_Map::unknown826920 and CInventory::attemptEquip): a robot
// picks up the item under it - attach/pickup tutorial hints, player-only bookkeeping (attachment stats,
// identification by scanners or analysis, first-pickup records and phrases, companion reactions), special
// handling of one item type, and an operator remark about the map's key item. Returns the global at 0xb95fac.
// NOTE: class layouts are partial; names other than Entity are placeholders. Local names follow the
// stack-slot hash order.
#include <string>
#include <vector>
using namespace std;

bool OpX5_containsRecord(vector<int> &v, int value);	// NOTE: placeholder name
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&result);	// NOTE: placeholder name

struct Point
{
	int x;
	int y;
};

class Entity;
class AI119;

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
	bool isValid() const;	// NOTE: folded with HItem::isValid
};

class HProp
{
public:
	int ID;
	HProp();
};

struct ItemData119	// NOTE: placeholder name and layout
{
	char	pad000[0x76];
	bool	unknown76;	// +0x76
	char	pad077[0x94 - 0x77];
	int		unknown94;	// +0x94
	char	pad098[0x271 - 0x98];
	bool	unknown271;	// +0x271
};

struct PropType119;	// NOTE: placeholder name
extern vector<PropType119 *> propTypes119_d2c408;	// NOTE: placeholder name

struct ItemEffect;

class Item
{
public:
	void unknown57a190(HEntity e, int a, int b, int c);	// NOTE: placeholder name
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name
	bool getFlag119();		// NOTE: placeholder name (folded getter Sweep_415ee0::getField)
	int getCategory119();	// NOTE: placeholder name (folded getter Sweep_4578a0::getNestedField)
	int getKey119();		// NOTE: placeholder name (folded getter Array2D::getWidth)
	int getNestedField();
	ItemEffect *getEffect(int type);
	ItemData119 *getData119();	// NOTE: placeholder name (folded getter, +0x08)
	int unknown457f90();	// NOTE: placeholder name
	void unknown458690(PropType119 *type, bool b);	// NOTE: placeholder name
	void unknown4585c0(int id);	// NOTE: placeholder name
	int getDepth119();		// NOTE: placeholder name (Calls_457920::delegate)
};

class HItem
{
public:
	int ID;
	Item *operator->() const;	// NOTE: OpC_Handle::get224
	bool operator==(HItem other) const;	// NOTE: folded with HEntity::operator==
};

class AI119	// NOTE: placeholder name
{
public:
	HItem unknown4592c0();	// NOTE: placeholder name
};

class Entity
{
public:
	char			pad00[4];
	HEntity			self;		// +0x04
	char			pad08[0x30 - 8];
	vector<Point>	positions;	// +0x30

	bool isPlayer();
	AI119 *getAI119();	// NOTE: placeholder name (folded getter ManualUI::unknown45b590)
	int unknown6421a0(bool flag);	// NOTE: placeholder name
};

class Cell
{
public:
	HItem getItem();
};

class CellGrid119	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(Point &p);	// NOTE: folded (OpX5_Array2D<int>::atPoint)
};
extern CellGrid119 cells119_cfd44c;	// NOTE: placeholder name

class BS
{
public:
	HEntity unknown715c70();	// NOTE: placeholder name
	void unknown464fd0(HItem item);	// NOTE: placeholder name
	void unknown464f60(HItem item);	// NOTE: placeholder name
	HEntity getEntity671();	// NOTE: placeholder name
};
extern BS *world119_cefc4c;	// NOTE: placeholder name

struct Location119	// NOTE: placeholder name
{
	int getDepth119();	// NOTE: placeholder name (Push_46ed20::operate)
};

class HLocation119	// NOTE: placeholder name
{
public:
	int ID;
	Location119 *operator->() const;	// NOTE: OpC_Handle::get23c
};
extern HLocation119 location119_d1e888;	// NOTE: placeholder name

class Hints119	// NOTE: placeholder name (OpU5s2_Unk793450, GM at 0xcefaa8)
{
public:
	void showOnce(int id, bool player, const string *text, int a, int b);	// NOTE: placeholder name
};
extern Hints119 *hints119_cefaa8;	// NOTE: placeholder name

class GM119	// NOTE: placeholder name (GM at 0xd25628)
{
public:
	void addItemAttachCount(int item, int count, int extra);
};
extern GM119 gm119_d25628;	// NOTE: placeholder name

class PlayerData119	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	void unknown77ffb0(int item, bool flag);	// NOTE: placeholder name
	bool hasCompanion();
};
extern PlayerData119 playerData119_cf45d8;	// NOTE: placeholder name

class CInventory
{
public:
	void reopen(int mode, HItem item);
};
extern CInventory *inventory119_cec08c;	// NOTE: placeholder name

class SpawnTracker119	// NOTE: placeholder name (OpU5_SpawnTracker)
{
public:
	void spawn(int type, bool flag, string text);
};

struct ItemRec119	// NOTE: placeholder name and layout (OpS1f_ItemRec at *0xcf4ac8)
{
	char			pad00[8];
	int				unknown08;
	char			pad0c[0x30 - 0xc];
	SpawnTracker119	*tracker;	// +0x30
};
extern ItemRec119 *itemRec119_cf4ac8;	// NOTE: placeholder name

class RolledValues119	// NOTE: placeholder name (OpW5_RolledValues at *0xcefb48)
{
public:
	bool say(int ID, bool force, string name);
};
extern RolledValues119 *rolled119_cefb48;	// NOTE: placeholder name
extern bool flag119_d25450;	// NOTE: placeholder name

extern vector<int> attached119_cf47cc;	// NOTE: placeholder name
extern vector<int> found119_cf4810;		// NOTE: placeholder name
extern vector<int> foundIdentified119_cf4820;	// NOTE: placeholder name
extern vector<int> identified119_cf4830;	// NOTE: placeholder name
extern int result119_b95fac;	// NOTE: placeholder name

class ConsoleA119	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA119 *consoleA119_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs119_cec0b4;	// NOTE: placeholder name

bool showMessage119(int id, const string *text, const void *b, int c, HEntity d, HProp e, const void *at, int flag);	// NOTE: placeholder name (0x5111e0)
bool addPhrase119(int id, const string *a, int b, int c, HProp e, int d);	// NOTE: placeholder name (0x5141b0)

int Entity::unknown6421a0(bool flag)
{
	HItem item = (*cells119_cfd44c.atPoint(positions[0]))->getItem();
	item->unknown57a190(self,4,1,1);
	hints119_cefaa8->showOnce(0x17,isPlayer(),&item->unknown571db0(false,false),0,0);
	if (item->getFlag119())
		hints119_cefaa8->showOnce(0x18,isPlayer(),&item->unknown571db0(false,false),0,0);
	if (isPlayer())
	{
		if (item->getCategory119() == 5 && !OpX5_containsRecord(attached119_cf47cc,item->getKey119()))
		{
			attached119_cf47cc.push_back(item->getKey119());
			gm119_d25628.addItemAttachCount(item->getNestedField(),1,0);
		}
		if (identified119_cf4830[item->getNestedField()] == 0)
		{
			if (item->getEffect(0x56))
			{
				playerData119_cf45d8.unknown77ffb0(item->getNestedField(),true);
				inventory119_cec08c->reopen(5,item);
			}
			if (!item->getData119()->unknown271)
			{
				HEntity analyzer = world119_cefc4c->unknown715c70();
				if (analyzer.isValid())
				{
					playerData119_cf45d8.unknown77ffb0(item->getNestedField(),false);
					if (item->getData119()->unknown94)
					{
						do
						{
							if (showMessage119(0x264,&item->unknown571db0(false,false),0,0,analyzer,HProp(),0,0))
								consoleA119_cec058->unknown8758d0(true);
							logMsgs119_cec0b4->scrollToEnd();
						} while (0);
					}
					inventory119_cec08c->reopen(5,item);
				}
			}
		}
		if (item->getData119()->unknown76 && !item->getEffect(0x68) && !OpX5_containsRecord(found119_cf4810,item->getKey119()))
		{
			found119_cf4810.push_back(item->getKey119());
			foundIdentified119_cf4820.push_back(identified119_cf4830[item->getNestedField()] != 0);
			do
			{
				addPhrase119(0x2f,&item->unknown571db0(false,false),0,0,HProp(),0);
			} while (0);
		}
		if (item->unknown457f90() == 0xd6 && playerData119_cf45d8.hasCompanion())
		{
			if (playerData119_cf45d8.hasCompanion())
				itemRec119_cf4ac8->tracker->spawn(itemRec119_cf4ac8->unknown08 >= 100 ? 0x1f : 0x1e,false,"");
			if (rolled119_cefb48)
				rolled119_cefb48->say(0x47,false,"");
			if (flag119_d25450 && playerData119_cf45d8.hasCompanion())
				itemRec119_cf4ac8->tracker->spawn(0x28,false,"");
		}
	}
	if (item->unknown457f90() == 0xcb)
	{
		PropType119 *type;
		if (OpQ5_findByName(propTypes119_d2c408,"Deploy_Turret",type))
		{
			world119_cefc4c->unknown464fd0(item);
			item->unknown458690(type,false);
			item->unknown4585c0(1);
			world119_cefc4c->unknown464f60(item);
		}
	}
	if (rolled119_cefb48 && isPlayer() && item->getDepth119() > location119_d1e888->getDepth119() && item == world119_cefc4c->getEntity671()->getAI119()->unknown4592c0() && rolled119_cefb48)
		rolled119_cefb48->say(0x1a,false,item->unknown571db0(false,false));
	return result119_b95fac;
}
