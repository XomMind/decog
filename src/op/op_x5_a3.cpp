// op_x5_a3: CPartWeaponHitChance::refresh (0x88e410), matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

class XConsole
{
public:
	virtual ~XConsole();

	int getWidth();	// 0x44b0d0
	void removeSubconsole(XConsole *console);
	void setPos(int x, int y);	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	int unknown60;
	void *engine;
	void *title;
};

class OpX5A3_Entity;
class OpX5A3_ItemBase457880	// NOTE: placeholder name
{
public:
	int getNestedField();	// NOTE: placeholder name (0x457880)
};

class OpX5A3_Item : public OpX5A3_ItemBase457880
{
public:
	bool unknown457cf0();	// NOTE: placeholder name
	int unknown4580c0();	// NOTE: placeholder name
	int unknown458100();	// NOTE: placeholder name
	int unknown578b10();	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	bool isValid() const;
	OpX5A3_Item *operator->() const throw();	// 0x9b65b0
	bool operator!=(HItem other) const;	// 0x9b6510
};

class HEntity
{
public:
	int ID;
	OpX5A3_Entity *operator->() const throw();	// 0x9b6570
};

class OpX5A3_Entity	// NOTE: placeholder name
{
public:
	int unknown5d2090(int type);	// NOTE: placeholder name
	int unknown5c7e90();	// NOTE: placeholder name
};

class OpX5A3_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
};
extern OpX5A3_Map *opX5A3_map;	// NOTE: placeholder name (0xcefc4c)

class OpX5A3_Scan	// NOTE: placeholder name (CScan at 0xcec078)
{
public:
	char pad00[0x8c];
	HItem unknown8c;	// NOTE: placeholder name
	char pad90[0x98 - 0x90];
	int unknown98;	// NOTE: placeholder name
	int unknown9c;	// NOTE: placeholder name
};
extern OpX5A3_Scan *opX5A3_scan;	// NOTE: placeholder name (0xcec078)

class OpX5A3_Selection	// NOTE: placeholder name (object at 0xcec084)
{
public:
	char pad00[0x78];
	vector<HItem> unknown78;	// NOTE: placeholder name
	bool unknown88;	// NOTE: placeholder name
};
extern OpX5A3_Selection *opX5A3_selection;	// NOTE: placeholder name (0xcec084)

string intToString(int value);
string OpY1_intToStringSigned(int value);	// NOTE: placeholder name (0x405560)
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
bool OpU8a_containsEntity(vector<HItem> &v, HItem e);	// NOTE: placeholder name (0x9d31e0)
void OpU8a_insertString(vector<string> &v, int index, string s);	// NOTE: placeholder name (0x9d4440)
void OpR2_insertAt(vector<int> &v, int index, int value);	// NOTE: placeholder name (0x9dbdc0)
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0 (for int)

class CPartWeaponHitFactor : public Console
{
public:
	CPartWeaponHitFactor(XConsole *parent, int x, int width, int type_, string text_);	// 0x88e130
	virtual ~CPartWeaponHitFactor();

	int type;	// NOTE: placeholder name
	string text;	// NOTE: placeholder name
};

class CPartWeaponHitChance : public Console
{
public:
	CPartWeaponHitChance(XConsole *parent);	// 0x88e3c0
	virtual ~CPartWeaponHitChance();
	void refresh(HItem item);	// NOTE: placeholder name (0x88e410)

	vector<Console*> factors;	// NOTE: placeholder name
};

void CPartWeaponHitChance::refresh(HItem item)
{
	vector<int> types;
	vector<string> labels;
	if (item->unknown457cf0() && opX5A3_scan->unknown8c.isValid() && OpU8a_containsEntity(opX5A3_selection->unknown78,item) && (!opX5A3_selection->unknown88 || item->unknown4580c0() >= 1))
	{
		int chance;
		if (item->getNestedField() >= 26)
		{
			chance = opX5A3_scan->unknown9c;
			if (chance == -1)
				goto done;
		}
		else
			chance = opX5A3_scan->unknown98;
		int modifier = item->unknown578b10();
		if (modifier)
		{
			types.push_back(1);
			labels.push_back(" " + OpY1_intToStringSigned(modifier));
		}
		int extra = 0;
		if (item->getNestedField() == 24)
		{
			extra = opX5A3_map->getPlayer()->unknown5d2090(93);
			if (extra)
			{
				types.push_back(2);
				labels.push_back(" " + OpY1_intToStringSigned(extra));
			}
		}
		int penalty = 0;
		if (item->getNestedField() < 26)
		{
			int limit = opX5A3_map->getPlayer()->unknown5c7e90();
			for (unsigned int i = 0; i < opX5A3_selection->unknown78.size(); i++)
			{
				if (opX5A3_selection->unknown78[i] != item && opX5A3_selection->unknown78[i].operator->())
					penalty += OpX5_maxInt(0,opX5A3_selection->unknown78[i]->unknown458100() - limit);
			}
			if (penalty)
			{
				types.push_back(3);
				labels.push_back(" " + OpY1_intToStringSigned(-penalty));
			}
		}
		if (item->unknown4580c0() >= 1)
			chance = 100;
		else
			chance = chance + modifier + extra - penalty;
		OpR2_insertAt(types,0,0);
		OpU8a_insertString(labels,0," " + intToString(chance) + "% ");
	}
done:
	vector<Console*> old = factors;
	factors.clear();
	int x = getWidth();
	for (unsigned int i = 0; i < types.size(); i++)
	{
		x -= labels[i].size();
		for (unsigned int j = 0; j < old.size(); j++)
		{
			if (((CPartWeaponHitFactor *)old[j])->type == types[i] && ((CPartWeaponHitFactor *)old[j])->text == labels[i])
			{
				factors.push_back(old[j]);
				factors.back()->setPos(x,0);
				removeVectorElement(old,j);
				goto next;
			}
		}
		factors.push_back(new CPartWeaponHitFactor(this,x,labels[i].size(),types[i],labels[i]));
next:
		if (i == 0)
			x -= 2;
	}
	for (unsigned int k = 0; k < old.size(); k++)
	{
		if (old[k])
			removeSubconsole(old[k]);
	}
	old.clear();
}
