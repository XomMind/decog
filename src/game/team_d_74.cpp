// team_d_74: BS member 0x736510: spawns Exiles' Farcom thieves (Thief_7) near a point or in an area.
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

int stringToInt(const string &s);

struct Point
{
	int x;
	int y;

	Point();	// NOTE: placeholder name (Push_453b40::operate)
};

struct Area
{
	int x1;
	int y1;
	int x2;
	int y2;

	void randomPoint_40be30(Point *out);	// NOTE: placeholder name
};

class Entity;
class EntityAI;
class Item;

class HEntity
{
public:
	int ID;
	HEntity();	// NOTE: folded with HProp::HProp
	bool isValid() const;
	bool isNull() const;
	Entity *operator->() const;
};

class HItem
{
public:
	int ID;
	HItem();	// NOTE: folded with HProp::HProp
	bool isValid() const;
	Item *operator->() const;
};

class Item
{
public:
	void unknown57bff0(int id, bool flag);	// NOTE: placeholder name
};

class EntityAI
{
public:
	int unknown5b4710(HEntity e, int a, int b, int c, int d);	// NOTE: placeholder name
};

class Entity
{
public:
	EntityAI *getAI();
};

class OpV1_GameData
{
public:
	const string &getEntryText(const string &key);
	void addToEntry(const string &key, int amount);	// NOTE: placeholder name
};
extern OpV1_GameData gameData74_d1e860;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

extern int state74_cf462c;			// NOTE: placeholder name
extern vector<int> list74_cf46e4;	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	char	pad000[0x658];
	int		unknown658;		// +0x658
	char	pad65c[0x66c - 0x65c];
	HEntity	player;			// +0x66c

	HEntity unknown6c5dc0(const string &name, const Point &pos, int group, bool flag, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name
	HItem giveItem(const string &itemName, HEntity entity, bool a, bool b);
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
	bool isVisible(const Point &p);
	void unknown6c65a0(HEntity e, const string &text, int value);
	bool unknown736510(int count, const Point &pos, Area &area, bool unseen, bool quiet);	// NOTE: placeholder name
};

bool BS::unknown736510(int count, const Point &pos, Area &area, bool unseen, bool quiet)
{
	int spawned = 0;
	for (int i = 0; i < count; i++)
	{
		HEntity e;
		if (pos.x != -1)
			e = unknown6c5dc0("Thief_7",pos,5,unknown658 == 0,0x22,0xe,false);
		if (e.isNull())
		{
			Point pt;
			bool ok = false;
			for (int t = 0; t < 200; t++)
			{
				area.randomPoint_40be30(&pt);
				if (findPlaceableNear(pt,pt,1) && (!unseen || !isVisible(pt)))
				{
					ok = true;
					break;
				}
			}
			if (ok)
				e = unknown6c5dc0("Thief_7",pt,5,unknown658 == 0,0x22,0xe,false);
		}
		if (e.isValid())
		{
			spawned++;
			e->getAI()->unknown5b4710(player,-2,100000,0,0);
			gameData74_d1e860.addToEntry("exiFarcomThiefCount_g",1);
			unknown6c65a0(e,"EXI_Thief_History",0);
			if (rng.chance(15))
			{
				HItem item;
				if (rng.chance(15))
					item = giveItem("Exp. Plasma Cutter",e,false,false);
				else
					item = giveItem("CPS Tube",e,false,false);
				if (item.isValid())
					item->unknown57bff0(0x41,true);
			}
			if (i == 0 && !quiet)
			{
				if (state74_cf462c == 8 && list74_cf46e4[10] == 0)
					unknown6c65a0(e,"FL_Dialogue_Thief",0);
				else if (stringToInt(gameData74_d1e860.getEntryText("exiFarcomThiefCount_g")) == 1)
					unknown6c65a0(e,stringToInt(gameData74_d1e860.getEntryText("exiAttackedLocals_g")) == 1 ? "EXI_Thief_Talk_Enemy" : "EXI_Thief_Talk_First",0);
				else if (rng.chance(10))
					unknown6c65a0(e,"EXI_Thief_Talk_Random",0);
			}
		}
	}
	return spawned;
}
