// team_d_99: MachineProcessRecord::MachineProcessRecord (0x659800; the class name comes from its logError
// location string). Callers: Entity::projectileImpact and three unnamed functions. The constructor stores its
// arguments and then, depending on the process type, consumes matching parts from the player's inventory,
// absorbs an item, spawns scrap or sets up a garrison, posting a timed map text for the first three.
// NOTE: class layouts are partial; member names, the record types and the tables are placeholders.
// NOTE: getTurn, HProp::operator-> and the position getter are declared throw() so the PosText arguments get no
// EH state (the exe knew them as nothrow); the local vector is "list" and the part list "v" for slot order.
// NOTE: World99/HProp99/getTurn99 are file-unique names so the full build links stubs rather than real
// definitions that LTCG cannot prove nothrow.
#include <string>
#include <vector>
using namespace std;

void logError(string location, string message);	// NOTE: placeholder name

struct Pos
{
	int x;
	int y;

	Pos() throw();	// 0x453b40
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos &operator=(const Pos &pos);	// NOTE: folded with the copy constructor
};

class OpR1F_PosText460aa0 : public Pos	// NOTE: placeholder name (defined in op_r1f.cpp)
{
public:
	int value8;
	int valueC;
	string text10;

	OpR1F_PosText460aa0(Pos pos, int value8_, int valueC_, string text);
};

class Prop
{
public:
	Pos &getPosition99() throw();	// NOTE: placeholder name (folded getter XConsole::getBuffer_4184d0)
};

class HProp99
{
public:
	int ID;
	Prop *operator->() const throw();	// NOTE: OpC_Handle::get22c
};

class Item
{
public:
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown57a520(HProp99 prop, int flag);	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	Item *operator->() const;	// NOTE: OpC_Handle::get224
};

class Entity;

class HEntity
{
public:
	int ID;
	HEntity();
	Entity *operator->() const;
};

class Entity
{
public:
	void unknown5cb830(vector<HItem> *list);	// NOTE: placeholder name
};

class World99
{
public:
	HEntity getPlayer();
	int getTurn99() throw();
	void opw3_unknown7270c0(OpR1F_PosText460aa0 *text);	// NOTE: placeholder name
};
extern World99 *world99_cefc4c;	// NOTE: placeholder name

struct ItemRecord99	// NOTE: placeholder name and layout
{
	char	pad00[0x24];
	string	name;	// +0x24
};
extern vector<ItemRecord99 *> itemRecords99_d2d1c4;	// NOTE: placeholder name

struct ProcessA99	// NOTE: placeholder name and layout
{
	char		pad000[0x24];
	string		name;	// +0x24
	char		pad040[0x1f4 - 0x40];
	vector<int>	parts;	// +0x1f4
};

struct ProcessB99	// NOTE: placeholder name and layout
{
	char		pad000[0xfc];
	vector<int>	parts;	// +0xfc
	char		pad10c[0x1ac - 0x10c];
	string		name;	// +0x1ac
};

extern int garrisons99_b93fc8[][6];	// NOTE: placeholder name

template <class T> void OpQ5_eraseStep(vector<T> &list, int &index);	// NOTE: placeholder name

class MachineProcessRecord
{
public:
	HProp99		machine;		// +0x00
	int			type;			// +0x04
	int			delay;			// +0x08
	ProcessA99	*processA;		// +0x0c
	ProcessB99	*processB;		// +0x10
	bool		unknown14;
	bool		unknown15;
	vector<HItem>	items;		// +0x18
	int			garrisonType;	// +0x28
	Pos			target;			// +0x2c
	vector<int>	garrison;		// +0x34
	bool		unknown44;
	bool		unknown45;

	MachineProcessRecord(HProp99 machine_, int type_, int delay_, ProcessA99 *processA_, ProcessB99 *processB_, bool unknown14_, bool unknown15_, HItem item, int garrisonType_, Pos *target_, bool unknown44_, bool unknown45_);
};

MachineProcessRecord::MachineProcessRecord(HProp99 machine_, int type_, int delay_, ProcessA99 *processA_, ProcessB99 *processB_, bool unknown14_, bool unknown15_, HItem item, int garrisonType_, Pos *target_, bool unknown44_, bool unknown45_)
	: machine		(machine_)
	, type			(type_)
	, delay			(delay_)
	, processA		(processA_)
	, processB		(processB_)
	, unknown14		(unknown14_)
	, unknown15		(unknown15_)
	, garrisonType	(garrisonType_)
	, unknown44		(unknown44_)
	, unknown45		(unknown45_)
{
	switch (type)
	{
	case 0x43:
		if (unknown44)
		{
			vector<HItem> list;
			world99_cefc4c->getPlayer()->unknown5cb830(&list);
			vector<int> &v = processA ? processA->parts : processB->parts;
			if (!v.empty())
			{
				for (int i = 0; i < v.size(); i++)
				{
					for (int j = 0; j < list.size(); j++)
					{
						if (list[j]->unknown571db0(false,false) == itemRecords99_d2d1c4[v[i]]->name)
						{
							list[j]->unknown57dbe0(1,0,1,1);
							OpQ5_eraseStep(list,j);
							break;
						}
					}
				}
			}
			world99_cefc4c->opw3_unknown7270c0(new OpR1F_PosText460aa0(machine->getPosition99(),1,world99_cefc4c->getTurn99() + delay,processA ? processA->name : processB->name));
		}
		break;
	case 0x4d:
		item->unknown57a520(machine,1);
		items.push_back(item);
		world99_cefc4c->opw3_unknown7270c0(new OpR1F_PosText460aa0(machine->getPosition99(),2,world99_cefc4c->getTurn99() + delay,item->unknown571db0(false,false)));
		break;
	case 0x5c:
	case 0x5d:
		world99_cefc4c->opw3_unknown7270c0(new OpR1F_PosText460aa0(machine->getPosition99(),3,world99_cefc4c->getTurn99() + delay,type == 0x5c ? "Scrapoids" : "Scraphulk"));
		break;
	case 0x70:
		if (garrisonType == 3)
			logError("MachineProcessRecord()","no garrison type provided");
		else if (!target_)
			logError("MachineProcessRecord()","no garrison target provided");
		else
		{
			target = *target_;
			for (int k = 3; k <= 5; k++)
				if (garrisons99_b93fc8[garrisonType][k] != -1)
					garrison.push_back(garrisons99_b93fc8[garrisonType][k]);
		}
		break;
	}
}
