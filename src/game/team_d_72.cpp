// team_d_72: CompanionData::upgrade (0x7aba60: swaps the companion item for its Quantum/Superquantum version)
// the per-turn companion update 0x7ab2b0 and the companion summon 0x7aa680.
// NOTE: class layouts are partial; member names other than upgrade are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(const Point &p) throw();	// 0x46ca50
};

struct OpQ5_U9d7a40;	// item data record
template <class T> bool OpQ5_findByName(vector<T*> &v, const string &name, T *&result);	// NOTE: placeholder name; const string& here (the exe instantiation takes string&; the literal converts implicitly)
extern vector<OpQ5_U9d7a40 *> itemData72_d2d1c4;	// NOTE: placeholder name

void logError(string location, string message);
void opR1d_4541b0(int id, int a, int b);

class HProp
{
public:
	int ID;
	HProp();
};

void opW5_message(int type, HProp prop, const string &text, int value);	// NOTE: placeholder name
void message72_5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name

class Item
{
public:
	string unknown571db0(int a, int b);					// NOTE: placeholder name (name text)
	void unknown57dbe0(int a, int b, int c, int d);		// NOTE: placeholder name
	int getNestedField();								// NOTE: placeholder name (data ID)
	int unknown_getWidth();								// NOTE: placeholder name (folded getter)
	const Point &unknown575920();						// NOTE: placeholder name (position)
	class HEntity unknown457b50();						// NOTE: placeholder name (owner)
	int getType();
	int unknown_getNestedField();						// NOTE: placeholder name (Sweep_457880::getNestedField)
	int unknown457f90();								// NOTE: placeholder name
	bool unknown457e90();								// NOTE: placeholder name
	struct ItemData72 *getData();						// NOTE: placeholder name (folded getter)
	void unknown57a190(class HEntity e, int a, int b, int c);	// NOTE: placeholder name
};

struct ItemData72	// NOTE: placeholder name and layout
{
	char	pad000[0x70];
	int		unknown70;
	char	pad074[0x1ac - 0x74];
	bool	unknown1ac;
};

class HItem
{
public:
	int ID;
	HItem();	// NOTE: declared only (makes HItem a non-POD return type, as in the exe)
	bool isValid() const;
	bool isNull() const;
	Item *operator->() const;
};

class Entity;

class HEntity
{
public:
	int ID;
	bool isValid() const;	// NOTE: folded with HItem::isValid
	Entity *operator->() const;
	bool operator==(HEntity e) const;
	bool operator!=(HEntity e) const;
};

struct Group72	// NOTE: placeholder name and layout
{
	int getType();	// NOTE: placeholder name (folded getter)
};

class HGroup72	// NOTE: placeholder name
{
	int ID;
public:
	Group72 *operator->() const;	// NOTE: folded (OpC_Handle::get230)
};

class Entity
{
public:
	int unknown5c92e0(int slot);						// NOTE: placeholder name
	Point unknown45a4c0();								// NOTE: placeholder name (position)
	void unknown642940(HItem item, int a, int b, int c, int d);	// NOTE: placeholder name
	int getFaction();
	HGroup72 getGroup();
	void unknown5d2430(int type, vector<HItem> *out);	// NOTE: placeholder name
	HItem unknown5d2380(int type);						// NOTE: placeholder name
	vector<HItem> *getInventoryList();
};

class BS
{
public:
	HEntity getPlayer();
	int getTurn();
	int unknown4642d0();								// NOTE: placeholder name
	void opw3_unknown72e4c0(HEntity e, bool flag);		// NOTE: placeholder name
	HItem unknown6c51d0(OpQ5_U9d7a40 *type, HEntity e, bool a, bool b);	// NOTE: placeholder name
	HItem unknown6c5400(OpQ5_U9d7a40 *type, const Point &pos);			// NOTE: placeholder name
	HItem giveItem(const string &itemName, HEntity entity, bool a, bool b);
};
extern BS *world72_cefc4c;	// NOTE: placeholder name

class MapView72	// NOTE: placeholder name (0xcec054)
{
public:
	void unknown49adc0(int time);	// NOTE: placeholder name
};
extern MapView72 *mapView72_cec054;	// NOTE: placeholder name

struct Location72	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;
};

class HLoc72	// NOTE: placeholder name
{
	int ID;
public:
	Location72 *operator->() const;
};
extern HLoc72 location72_d1e888;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

struct Range72	// NOTE: placeholder name (Point::randomInRange_40c130)
{
	int lo;
	int hi;

	int randomInRange_40c130();
};
extern Range72 range72_cf76e0;	// NOTE: placeholder name

HItem OpX5_randomRecord(vector<HItem> &v);	// NOTE: placeholder name
bool OpT8b_Fn9daf80(int a, int b, int c);	// NOTE: placeholder name
extern int chances72_bbca6c[];	// NOTE: placeholder name
extern int bonus72_bbca40;		// NOTE: placeholder name
extern int bonus72_bbca44;		// NOTE: placeholder name

struct Machine72	// NOTE: placeholder name and layout
{
	char			pad00[0x18];
	vector<HEntity>	unknown18;
};

struct MachineHolder72	// NOTE: placeholder name and layout
{
	char		pad00[0x38];
	Machine72	*machine;	// +0x38
};

class Prop
{
public:
	MachineHolder72 *unknown_getHolder();	// NOTE: placeholder name (folded getter)
	int unknown_getIndex();					// NOTE: placeholder name (folded getter)
};

class HProp72	// NOTE: placeholder name
{
	int ID;
public:
	Prop *operator->() const;	// NOTE: folded (OpC_Handle::get22c)
};

class Cell
{
public:
	HProp72 getProp();
};

class CellGrid72	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: folded (OpX5_Array2D<int>::atPoint)
};
extern CellGrid72 cells72_cfd44c;	// NOTE: placeholder name

bool OpU8a_removeEntity(vector<HEntity> &v, HItem e);	// NOTE: placeholder name (the exe's takes an HEntity-typed handle)
extern vector< vector<HEntity> > lists72_cf3a10;	// NOTE: placeholder name
extern vector<HEntity> list72_cf4a38;	// NOTE: placeholder name
void opd_insertItem(vector<HItem> *v, int index, HItem item);	// NOTE: placeholder name (0x9d8fc0)

class ConsoleA72	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA72 *consoleA72_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs72_cec0b4;	// NOTE: placeholder name

bool showMessage72(int id, const string &text, const string *b, int c, HEntity d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)

class CParts
{
public:
	bool isLinked4a9b10(HItem item);					// NOTE: placeholder name
	void unknown8987b0(HItem item, vector<HItem> *list);	// NOTE: placeholder name
	void *unknown894e70(HItem item);					// NOTE: placeholder name
	void unknown8993e0(void *part, bool flag);			// NOTE: placeholder name
	void unknown89d610(HItem item, int value);			// NOTE: placeholder name
	void unknown898860(HItem item, vector<HItem> *list);	// NOTE: placeholder name
};
extern CParts *parts72_cec088;	// NOTE: placeholder name

class GM
{
public:
	void addItemAttachCount(int itemID, int count, bool force);
};
extern GM gm72_d25628;	// NOTE: placeholder name

extern bool flag72_cefc5f;	// NOTE: placeholder name
extern vector<int> list72_cf47cc;	// NOTE: placeholder name

class PlayerData
{
public:
	bool hasCompanion();				// NOTE: placeholder name
	void unknown77ffb0(int a, int b);	// NOTE: placeholder name
	void unknown77fbc0(int id);			// NOTE: placeholder name
};
extern PlayerData playerData72_cf45d8;	// NOTE: placeholder name

class OpU5_SpawnTracker
{
public:
	bool spawn(unsigned int index, bool force, string extra);
};

struct Flag72	// NOTE: placeholder name and layout
{
	char	pad00[0x24];
	bool	unknown24;
};

struct State72	// NOTE: placeholder name and layout (0xcf4ac8)
{
	char				pad00[0x30];
	OpU5_SpawnTracker	*tracker;	// +0x30
};
extern State72 *state72_cf4ac8;	// NOTE: placeholder name

class OpR1h_Stats
{
public:
	void add472b90(unsigned int id, int value);
};
extern OpR1h_Stats stats72_d2c658;	// NOTE: placeholder name

class CompanionData	// NOTE: placeholder layout
{
public:
	int		level;		// +0x00
	HItem	item;		// +0x04
	int		unknown08;
	bool	unknown0c;
	int		unknown10;
	int		unknown14;
	int		unknown18;	// next remark turn
	char	pad1c[0x30 - 0x1c];
	Flag72	*unknown30;

	void increase48b8c0(int amount);	// NOTE: placeholder name (OpS1f_ItemRec::increase48b8c0)
	void unknown7aa680();				// NOTE: placeholder name
	void unknown7aaee0();				// NOTE: placeholder name
	void unknown7ab2b0();				// NOTE: placeholder name (per-turn update)
	void upgrade(bool installed, int level);
};

void CompanionData::upgrade(bool installed, int level)
{
	OpQ5_U9d7a40 *data;
	if (OpQ5_findByName(itemData72_d2d1c4,level == 1 ? "Quantum Companion" : "Superquantum Companion",data))
	{
		this->level = level;
		string msg = item->unknown571db0(0,0) + " blips out of existence for a moment, then partially fades back in.";
		opW5_message(0x320,HProp(),msg,0);
		if (installed)
		{
			vector<HItem> list;
			parts72_cec088->unknown8987b0(item,&list);
			flag72_cefc5f = true;
			item->unknown57dbe0(1,0,0,1);
			item = world72_cefc4c->unknown6c51d0(data,world72_cefc4c->getPlayer(),true,false);
			flag72_cefc5f = false;
			if (item.isValid())
			{
				list72_cf47cc.push_back(item->unknown_getWidth());
				gm72_d25628.addItemAttachCount(item->getNestedField(),1,false);
				void *part = parts72_cec088->unknown894e70(item);
				if (part)
					parts72_cec088->unknown8993e0(part,true);
				parts72_cec088->unknown89d610(item,10);
				if (!list.empty())
					parts72_cec088->unknown898860(item,&list);
			}
		}
		else
		{
			Point pos(item->unknown575920());
			flag72_cefc5f = true;
			item->unknown57dbe0(1,0,0,1);
			item = world72_cefc4c->unknown6c5400(data,pos);
			if (item.isNull())
				logError("CompanionData::upgrade()","placement failed");
			flag72_cefc5f = false;
			unknown08 = 1000;
			unknown0c = true;
			if (this->level == 2)
				unknown10 = 0;
		}
		opR1d_4541b0(0x115,0,0);
		do
		{
			message72_5141b0(0x56,&item->unknown571db0(0,0),0,0,HProp(),0);
		} while (0);
		if (installed)
		{
			if (playerData72_cf45d8.hasCompanion())
				state72_cf4ac8->tracker->spawn(9,false,"");
		}
		else if (playerData72_cf45d8.hasCompanion())
			state72_cf4ac8->tracker->spawn((level != 1) + 10,false,"");
		stats72_d2c658.add472b90(0x1e,-999999);

		playerData72_cf45d8.unknown77fbc0(0x14b);
	}
}

void CompanionData::unknown7ab2b0()
{
	if (!item.operator->())
	{
		if (level == 0)
			playerData72_cf45d8.hasCompanion();
		else if (rng.chance(chances72_bbca6c[level]))
			unknown7aa680();
		return;
	}
	switch (world72_cefc4c->unknown4642d0())
	{
	case 1:
		if (!unknown0c && location72_d1e888->type != 0xb)
		{
			int type = 0;
			string text = "";
			HEntity player = world72_cefc4c->getPlayer();
			if (item->unknown457b50() == player)
			{
				if (item->getType() == 3)
				{
					increase48b8c0(bonus72_bbca40);
					type = 1;
				}
				if (unknown14 < 10 || item->getType() != 3)
				{
					increase48b8c0(bonus72_bbca44);
					type = 2;
				}
				vector<HItem> list;
				player->unknown5d2430(0x51,&list);
				player->unknown5d2430(0x5a,&list);
				player->unknown5d2430(0x6c,&list);
				player->unknown5d2430(0x6a,&list);
				if (!list.empty())
				{
					increase48b8c0(list.size() * 2);
					if (list.size() >= 3)
					{
						type = 3;
						text = OpX5_randomRecord(list)->unknown571db0(0,0);
					}
				}
				if (type && !unknown0c && playerData72_cf45d8.hasCompanion())
					state72_cf4ac8->tracker->spawn(type,false,text);
			}
		}
		break;
	case 3:
		if (unknown30->unknown24 && playerData72_cf45d8.hasCompanion())
			state72_cf4ac8->tracker->spawn(0x33,false,"");
		break;
	case 0x11:
		if (level && unknown10 && item->unknown457b50() == world72_cefc4c->getPlayer())
		{
			unknown10--;
			if (unknown10 == 0)
			{
				if (playerData72_cf45d8.hasCompanion())
					state72_cf4ac8->tracker->spawn(0xc,false,"");
				world72_cefc4c->opw3_unknown72e4c0(world72_cefc4c->getPlayer(),true);
				mapView72_cec054->unknown49adc0(1000);
			}
		}
		break;
	}
	unknown7aaee0();
	if (unknown0c && level == 0 && item->unknown457b50() == world72_cefc4c->getPlayer() && item->getType() == 3)
		upgrade(true,1);
	if (!unknown0c && world72_cefc4c->getTurn() >= unknown18)
	{
		if (item->unknown457b50() == world72_cefc4c->getPlayer() && world72_cefc4c->getPlayer()->unknown5d2380(0xd6).isValid())
		{
			vector<HItem> list2;
			vector<HItem> *inv = world72_cefc4c->getPlayer()->getInventoryList();
			for (unsigned int k = 0; k < inv->size(); k++)
			{
				if ((*inv)[k]->getType() == 3 && OpT8b_Fn9daf80(0x14,(*inv)[k]->unknown_getNestedField(),0x17))
				{
					if (list2.empty())
						increase48b8c0(5);
					list2.push_back((*inv)[k]);
				}
			}
			if (!list2.empty() && playerData72_cf45d8.hasCompanion())
				state72_cf4ac8->tracker->spawn(6,false,OpX5_randomRecord(list2)->unknown571db0(0,0));
		}
		unknown18 = world72_cefc4c->getTurn() + range72_cf76e0.randomInRange_40c130();
	}
	if (item->unknown457b50() != world72_cefc4c->getPlayer() || item->getType() != 3)
	{
		if (rng.chance(chances72_bbca6c[level]))
			unknown7aa680();
	}
}

void CompanionData::unknown7aa680()
{
	HEntity player = world72_cefc4c->getPlayer();
	int value;
	if (!player->unknown5c92e0(3))
	{
		vector<HItem> *inv = player->getInventoryList();
		vector<HItem> list;
		for (unsigned int i = 0; i < inv->size(); i++)
		{
			if ((*inv)[i]->getType() == 3 && !parts72_cec088->isLinked4a9b10((*inv)[i]) && (*inv)[i]->unknown457f90() != 0xd4 && (*inv)[i]->getData()->unknown70 > 1)
			{
				if ((*inv)[i]->getData()->unknown1ac)
					list.push_back((*inv)[i]);
				else
					opd_insertItem(&list,0,(*inv)[i]);
			}
		}
		if (list.empty())
			return;
		HItem it = list[0];
		if (it->unknown457e90())
		{
			do
			{
				if (showMessage72(0x45,it->unknown571db0(0,0),0,0,player,HProp(),&player->unknown45a4c0(),0))
					consoleA72_cec058->unknown8758d0(true);
				logMsgs72_cec0b4->scrollToEnd();
			} while (0);
			it->unknown57dbe0(1,1,1,1);
		}
		else
		{
			do
			{
				if (showMessage72(0xed,it->unknown571db0(0,0),0,0,player,HProp(),0,0))
					consoleA72_cec058->unknown8758d0(true);
				logMsgs72_cec0b4->scrollToEnd();
			} while (0);
			player->unknown642940(it,1,1,0,4);
		}
	}
	if (item.operator->())
	{
		value = item->unknown457b50() == player && item->getType() == 4 ? 0x1a : (item->unknown457b50().isValid() && item->unknown457b50()->getFaction() == 5 && item->unknown457b50()->getGroup()->getType() == 4 ? 0x1b : 0x1c);
		switch (item->getType())
		{
		case 6:
			(*cells72_cfd44c.atPoint(item->unknown575920()))->getProp()->unknown_getHolder()->machine->unknown18.clear();
			value = 0x35;
			break;
		case 7:
			OpU8a_removeEntity(lists72_cf3a10[(*cells72_cfd44c.atPoint(item->unknown575920()))->getProp()->unknown_getIndex()],item);
			value = 0x1b;
			break;
		case 8:
			OpU8a_removeEntity(list72_cf4a38,item);
			value = 0x27;
			break;
		}
		playerData72_cf45d8.unknown77ffb0(item->getNestedField(),0);
		item->unknown57a190(player,3,1,0);
	}
	else
	{
		item = world72_cefc4c->giveItem(level == 1 ? "Quantum Companion" : "Superquantum Companion",player,true,false);
		if (item.isNull())
			return;
		value = 0x1d;
	}
	void *cur = parts72_cec088->unknown894e70(item);
	if (cur)
		parts72_cec088->unknown8993e0(cur,true);
	opR1d_4541b0(0xfe,0,0);
	string msg = item->unknown571db0(0,0) + " materializes via a weapon slot.";
	opW5_message(0x320,HProp(),msg,0);
	if (value != 0x35 && playerData72_cf45d8.hasCompanion())
		state72_cf4ac8->tracker->spawn(value,false,"");
	mapView72_cec054->unknown49adc0(1000);
}
