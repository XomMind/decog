// op_x5_a4: CParts::unknown8979b0 (0x8979b0), matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
};

class XConsole
{
public:
	virtual ~XConsole();

	Pos getPos() throw();
	void removeSubconsole(XConsole *console);

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	int unknown60;
	void *engine;
	void *title;
};

class OpX5A4_Item;
class OpX5A4_Entity;

class HItem
{
public:
	int ID;
	HItem() throw();	// 0x9b6590
	bool isValid() const;
	OpX5A4_Item *operator->() const throw();	// 0x9b65b0
	bool operator==(HItem other) const;	// 0x9b78e0
};

class HEntity
{
public:
	int ID;
	OpX5A4_Entity *operator->() const throw();	// 0x9b6570
};

class OpX5A4_Item	// NOTE: placeholder name (Item)
{
public:
	int getField457880();	// NOTE: placeholder name (folded getter)
	int unknown457f90();	// NOTE: placeholder name
	int unknown4580c0();	// NOTE: placeholder name
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
};

class OpX5A4_Entity	// NOTE: placeholder name (Entity)
{
public:
	int unknown5dc440(HItem item);	// NOTE: placeholder name
	void unknown64da50(HItem item);	// NOTE: placeholder name
};

class OpX5A4_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
};
extern OpX5A4_Map *opX5A4_map;	// NOTE: placeholder name (0xcefc4c)

class CInventory
{
public:
	void unknown8a5740();	// NOTE: placeholder name
	void unknown8a57e0();	// NOTE: placeholder name
	void unknown8a5860();	// NOTE: placeholder name
	void unknown8a5900();	// NOTE: placeholder name
	void unknown8a59a0();	// NOTE: placeholder name
};
extern CInventory *opX5A4_inventory;	// NOTE: placeholder name (0xcec08c)

class CPartAnimation : public Console
{
public:
	CPartAnimation(XConsole *parent, const string &name, bool multislot, int key, int type);	// 0x4a8330
};

class CPart : public Console
{
public:
	CPart(XConsole *parent, int y, HItem item_, bool unknown70_, HItem unknown74_, int unknown7c_, int key_);	// 0x4a8bd0
	void unknown890710(int value);	// NOTE: placeholder name

	HItem item;
	bool unknown70;	// NOTE: placeholder name
	char pad71[0x74 - 0x71];
	HItem unknown74;	// NOTE: placeholder name
	char pad78[0x7c - 0x78];
	int unknown7c;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
	char pad84[0x9c - 0x84];
	int unknown9c;	// NOTE: placeholder name
	char padA0[0xa4 - 0xa0];
};

class CParts : public Console
{
public:
	void unknown8979b0(HItem item, bool flag, int value);	// NOTE: placeholder name (0x8979b0)
	void unknown896b40();	// NOTE: placeholder name
	void unknown896cc0();	// NOTE: placeholder name
	void unknown896d80();	// NOTE: placeholder name
	void unknown896e20();	// NOTE: placeholder name
	void unknown896ee0();	// NOTE: placeholder name
	void unknown896fa0();	// NOTE: placeholder name

	char pad6c[0x74 - 0x6c];
	vector<CPart*> parts;	// NOTE: placeholder name
	char pad84[0xac - 0x84];
	int unknownAC;	// NOTE: placeholder name
};

bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)
void opX5A4_insertAt(vector<CPart*> &v, int index, CPart *value);	// NOTE: placeholder name (0x9dbdc0)
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0 (for int)
extern int opX5A4_gameState;	// NOTE: placeholder name (0xd28d68)
extern bool opX5A4_d28e7c;	// NOTE: placeholder name
extern HItem opX5A4_d1d9c8;	// NOTE: placeholder name
extern vector<int> opX5A4_d378ac;	// NOTE: placeholder name

void CParts::unknown8979b0(HItem item, bool flag, int value)
{
	int type = 0;
	bool multislot = false;
	bool animated = false;
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		if (parts[i]->item == item)
		{
			parts[i];
			unknownAC = 32;
			if (!flag)
			{
				if (item->unknown457f90() == 212 && !animated)
				{
					for (unsigned int j = 0; j < parts.size(); j++)
					{
						if (j != i && parts[j]->unknown74 == item)
							opX5A4_d378ac.push_back(parts[j]->unknown7c);
					}
					animated = true;
				}
				if (parts[i]->unknown74.isValid())
					opX5A4_d378ac.push_back(parts[i]->unknown7c);
			}
			opX5A4_insertAt(parts,i,new CPart(this,parts[i]->getPos().y,HItem(),false,flag ? HItem() : parts[i]->unknown74,parts[i]->unknown7c,parts[i]->key));
			parts[i]->unknown890710(0);
			if (value)
				new CPartAnimation(parts[i],item->getName(0,0),multislot,parts[i]->key,value);
			else if (parts[i + 1]->unknown9c || type)
			{
				if (!type)
					type = parts[i + 1]->unknown9c;
				new CPartAnimation(parts[i],parts[i + 1]->item->getName(0,0),multislot,parts[i]->key,type);
			}
			if (parts[i + 1])
			{
				removeSubconsole(parts[i + 1]);
				parts[i + 1] = NULL;
			}
			removeVectorElement(parts,i + 1);
			if (!multislot)
			{
				if (opX5A4_gameState == 0 || opX5A4_gameState == 4)
					unknown896b40();
				if (opX5A4_gameState == 3)
				{
					switch (item->unknown457f90())
					{
						case 6:
							unknown896cc0();
							opX5A4_inventory->unknown8a5740();
							break;
						case 102:
							unknown896d80();
							opX5A4_inventory->unknown8a57e0();
							break;
						case 103:
							unknown896e20();
							opX5A4_inventory->unknown8a5860();
							break;
						case 105:
							unknown896ee0();
							opX5A4_inventory->unknown8a5900();
							break;
						case 90:
						case 106:
							unknown896fa0();
							opX5A4_inventory->unknown8a59a0();
							break;
					}
				}
				if (opX5A4_d28e7c && item->getField457880() == 24 && item == opX5A4_d1d9c8)
				{
					for (unsigned int k = 0; k < parts.size(); k++)
					{
						if (parts[k]->item.isValid() && !opX5A4_map->getPlayer()->unknown5dc440(parts[k]->item) && OpT8b_Fn9daf80(20,parts[k]->item->getField457880(),25) && parts[k]->item->getField457880() != 24 && parts[k]->item->unknown457f90() != 207 && parts[k]->item->unknown457f90() != 119 && !parts[k]->item->unknown4580c0())
						{
							opX5A4_map->getPlayer()->unknown64da50(parts[k]->item);
							parts[k]->unknown890710(1);
						}
					}
				}
			}
			multislot = true;
		}
	}
}
