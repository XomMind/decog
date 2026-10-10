// team_c_69: RIF ability install (0x780f30): raises the ability level, logs it, and applies the immediate effects
//	(Relay Coupler code value boosts for every coupler in play, or converting couplers to Relay Coupler [C])
// NOTE: names are placeholders; layout is partial
#include <string>
#include <vector>
using namespace std;

string intToString(int value);

class C69_HProp { public: int ID; C69_HProp(); };	// NOTE: placeholder (HProp)
struct C69_Def { int f0; char pad4[0x24 - 4]; string f24; };	// NOTE: placeholder (item def)
struct C69_Item	// NOTE: placeholder (Item)
{
	int unknown457f90();
	int getValue();
	void setValue(int v);
	int getType();
	int getNestedField();
	string unknown571db0(bool a, bool b);
	bool unknown578830();
	C69_Def *getDef();
	void unknown57dbe0(bool a, bool b, bool c, bool d);
	void setActive(bool active);
	int getWidth();
};
class C69_HItem { public: int ID; C69_HItem(); C69_Item *operator->() const; bool isValid() const; };	// NOTE: placeholder (HItem)
struct C69_Entity { vector<C69_HItem> *getInventoryList(); };
class C69_HEntity { public: int ID; C69_HEntity(); C69_Entity *operator->() const; };	// NOTE: placeholder (HEntity)
struct C69_Squad { vector<C69_HEntity> *getMembers(); };	// NOTE: placeholder (folded getter getFore)
class C69_HSquad { public: int ID; C69_HSquad(); C69_Squad *get230() const; };	// NOTE: placeholder
struct C69_Machine { char pad0[0xc]; int fc; };	// NOTE: placeholder
struct C69_Record { char pad0[0x24]; string f24; };	// NOTE: placeholder (item type record)
struct C69_Level { char pad0[8]; int f8; };	// NOTE: placeholder
class C69_HLevel { public: int ID; C69_Level *get23c() const; };	// NOTE: placeholder
struct C69_Cell { C69_HItem getItem(); };
struct C69_CellGrid { int getWidth(); int getHeight(); C69_Cell **at(int x, int y); };
struct C69_World	// NOTE: placeholder (BS/Map at 0xcefc4c)
{
	C69_HEntity getPlayer();
	vector<C69_Machine *> *unknown464940();
	C69_HSquad unknown463890(int index);
	C69_HItem unknown6c51d0(C69_Record *record, C69_HEntity owner, bool flag, int a);
};
struct C69_SlotInfo { int getField(); };	// NOTE: placeholder
struct C69_Parts { void unknown896a80(C69_HItem item); C69_SlotInfo *unknown894e70(C69_HItem item); };	// NOTE: placeholder (CParts)
struct C69_Inventory { void reopen(int a, C69_HProp p); };	// NOTE: placeholder (CInventory)
struct C69_Console2 { void unknown8758d0(bool flag); };
struct C69_Log { void scrollToEnd(); };
struct C69_Stats { bool add4729d0(unsigned int id, int value, string text, int extra); };
struct C69_PlayerData2 { void unknown77fbc0(int type); };
struct C69_GM { void addItemAttachCount(int type, int a, int b); };
bool c69_message5111e0(int id, const string *a, const string *b, int c, C69_HProp entity, C69_HProp prop, int d, int e);	// NOTE: placeholder name (0x5111e0)
bool c69_message5141b0(int id, const string *a, const string *b, int c, C69_HProp prop, int d);	// NOTE: placeholder name (0x5141b0)
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&result);	// NOTE: placeholder name

extern string rifAbilityNames_d2a2e0[];	// global_string_arrays.cpp
extern vector<int> c69_rifLevels_cf4a04;	// NOTE: placeholder names below
extern int c69_rifMaxLevels_b98958[];
extern int c69_couplerEfficiency_b988f0[];
extern int c69_couplerEfficiencyPrev_b988ec[];	// NOTE: c69_couplerEfficiency_b988f0 - 1 (the previous level's value); a separate symbol keeps [i*4-4] inside its own stub
extern C69_HLevel c69_d1e888;
extern C69_Stats c69_d2c658;
extern C69_PlayerData2 c69_cf45d8;
extern C69_Console2 *c69_cec058;
extern C69_Log *c69_cec0b4;
extern C69_World *c69_cefc4c;
extern C69_Parts *c69_cec088;
extern C69_Inventory *c69_cec08c;
extern vector<int> c69_cf4830;
extern C69_CellGrid c69_cfd44c;
extern vector<C69_Record *> c69_d2d1c4;
extern C69_GM c69_d25628;
extern const char c69_empty_b95b9b[];
extern const char c69_empty_b95ba6[];

#define C69_MSG(call) do { if (call) c69_cec058->unknown8758d0(true); c69_cec0b4->scrollToEnd(); } while (0)

class C69_PlayerData	// NOTE: placeholder layout
{
public:
	char pad0[0x1f4];
	vector<int> f1f4;
	char pad204[0x42c - 0x204];
	vector<int> f42c;
	vector<int> f43c;
	vector<int> f44c;

	void installRIF_780f30(int ability);
};

void C69_PlayerData::installRIF_780f30(int ability)
{
	if (c69_rifLevels_cf4a04[ability] == c69_rifMaxLevels_b98958[ability])
		return;
	f42c[ability]++;
	f43c.push_back(ability);
	f44c.push_back(c69_d1e888.get23c()->f8);
	c69_d2c658.add4729d0(ability + 782,1,c69_empty_b95b9b,-1);
	C69_MSG(c69_message5111e0(667,&rifAbilityNames_d2a2e0[ability],0,0,C69_HProp(),C69_HProp(),0,0));
	do
	{
		c69_message5141b0(403,&rifAbilityNames_d2a2e0[ability],0,0,C69_HProp(),0);
	} while (0);
	c69_cf45d8.unknown77fbc0(103);
	if (f43c.size() == 8)
		c69_cf45d8.unknown77fbc0(196);
	else if (f43c.size() == 15)
		c69_cf45d8.unknown77fbc0(354);
	switch (ability)
	{
		case 3:
		{
			int adj = c69_couplerEfficiency_b988f0[c69_rifLevels_cf4a04[3]];
			if (c69_rifLevels_cf4a04[3] > 1)
				adj -= c69_couplerEfficiencyPrev_b988ec[c69_rifLevels_cf4a04[3]];
			bool center = false;
			vector<C69_HItem> *behaviour = c69_cefc4c->getPlayer()->getInventoryList();
			for (unsigned int col = 0; col < behaviour->size(); col++)
			{
				if ((*behaviour)[col]->unknown457f90() == 124)
				{
					(*behaviour)[col]->setValue((*behaviour)[col]->getValue() + adj);
					if ((*behaviour)[col]->getType() == 4)
						center = true;
					else
						c69_cec088->unknown896a80((*behaviour)[col]);
					if (c69_cf4830[(*behaviour)[col]->getNestedField()] != 0)
						C69_MSG(c69_message5111e0(673,&(*behaviour)[col]->unknown571db0(false,false),&intToString((*behaviour)[col]->getValue()),0,C69_HProp(),C69_HProp(),0,0));
				}
			}
			if (center)
				c69_cec08c->reopen(4,C69_HProp());
			for (int col = 0; col < c69_cfd44c.getWidth(); col++)
			{
				for (int cols = 0; cols < c69_cfd44c.getHeight(); cols++)
				{
					if ((*c69_cfd44c.at(col,cols))->getItem().isValid() && (*c69_cfd44c.at(col,cols))->getItem()->unknown457f90() == 124)
						(*c69_cfd44c.at(col,cols))->getItem()->setValue((*c69_cfd44c.at(col,cols))->getItem()->getValue() + adj);
				}
			}
			vector<C69_Machine *> *clean = c69_cefc4c->unknown464940();
			for (unsigned int col = 0; col < clean->size(); col++)
				(*clean)[col]->fc += adj;
			for (int col = 1; col < 15; col++)
			{
				vector<C69_HEntity> *cols = c69_cefc4c->unknown463890(col).get230()->getMembers();
				for (unsigned int current = 0; current < cols->size(); current++)
				{
					vector<C69_HItem> *distanceSq = (*cols)[current]->getInventoryList();
					for (unsigned int distances = 0; distances < distanceSq->size(); distances++)
					{
						if ((*distanceSq)[distances]->unknown457f90() == 124)
							(*distanceSq)[distances]->setValue((*distanceSq)[distances]->getValue() + adj);
					}
				}
			}
			break;
		}
		case 18:
		{
			bool center = false;
			C69_Record *col;
			if (OpQ5_findByName(c69_d2d1c4,"Relay Coupler [C]",col))
			{
				vector<C69_HItem> *cols = c69_cefc4c->getPlayer()->getInventoryList();
				for (int current = cols->size() - 1; current >= 0; current--)
				{
					if ((*cols)[current]->unknown578830())
					{
						int distanceSq = (*cols)[current]->getValue();
						int distances = 0;
						C69_SlotInfo *adj = c69_cec088->unknown894e70((*cols)[current]);
						if (adj != 0)
							distances = adj->getField();
						C69_Def *allies = (*cols)[current]->getDef();
						(*cols)[current]->unknown57dbe0(true,false,false,true);
						C69_HItem a1 = c69_cefc4c->unknown6c51d0(col,c69_cefc4c->getPlayer(),distances != 0,0);
						if (a1.isValid())
						{
							a1->setValue(distanceSq);
							if (a1->getType() == 4)
								center = true;
							else
							{
								a1->setActive(true);
								f1f4.push_back(a1->getWidth());
								c69_d25628.addItemAttachCount(a1->getNestedField(),1,0);
								c69_cec088->unknown896a80(a1);
							}
							if (c69_cf4830[allies->f0] != 0)
								C69_MSG(c69_message5111e0(683,&allies->f24,&col->f24,0,C69_HProp(),C69_HProp(),0,0));
							c69_d2c658.add4729d0(886,1,c69_empty_b95ba6,-1);
						}
					}
				}
			}
			if (center)
				c69_cec08c->reopen(4,C69_HProp());
			break;
		}
	}
}
