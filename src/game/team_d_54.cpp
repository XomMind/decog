// team_d_54: BS member 0x6ef100 (Exiles follow-ups on arriving from the mines: hero revenge or escaped tester).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();	// NOTE: placeholder name (0x453b40)
};

class Entity;

class HEntity
{
	int ID;
public:
	bool isValid() const;
	Entity *operator->() const;
};

class HProp
{
	int ID;
public:
	HProp();
};

class EntityAI54	// NOTE: placeholder name
{
public:
	int unknown5b4710(HEntity e, int a, int b, int c, int d);	// NOTE: placeholder name
	void setFollowEntity(HEntity followEntity_, int followParam_);	// 0x5b2f80
};

class Entity
{
public:
	void removeEffectsA(int a);					// NOTE: placeholder name (0x639730)
	EntityAI54 *getAI();						// 0x45b590
	void unknown6396a0(const string &name, int a);	// NOTE: placeholder name
	Point &getPosition();
	void unknown45b070(const string &name);		// NOTE: placeholder name
};

class Cell
{
public:
	bool canPlaceEntity(int size);
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getRandom(Point *out);		// NOTE: placeholder name (0x9cf0c0)
	Cell **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

struct EntityRec54	// NOTE: placeholder name and layout
{
	char	pad000[0x9c];
	int		size;	// +0x9c
};
extern vector<EntityRec54 *> entityRecs54_d25de0;	// NOTE: placeholder name
extern vector<int> uniques54_d1dd58;	// NOTE: placeholder name
extern int int_caf160;	// NOTE: placeholder name

struct Location54	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;		// +0x04
	int depth;		// +0x08

	int unknown46ed20();	// NOTE: placeholder name
};

class HLoc54	// NOTE: placeholder name
{
	int ID;
public:
	Location54 *operator->() const;
};
extern HLoc54 location54_d1e888;	// NOTE: placeholder name
extern vector<HLoc54> locations54_d1e88c;	// NOTE: placeholder name

class GameData54	// NOTE: placeholder name (0xd1e860)
{
public:
	const string &getEntryText(const string &key);	// 0x46f6d0
};
extern GameData54 gameData54_d1e860;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
void opW5_message(int type, HProp prop, const string &text, int value);	// NOTE: placeholder name
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name
string OpU8a_randomString(vector<string> &v);	// NOTE: placeholder name (0x9d3280)

class BS
{
public:
	char	pad000[0x66c];
	HEntity	leader;	// +0x66c

	HEntity placeEntity(EntityRec54 *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
	HEntity unknown6c5dc0(const string &name, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &talk, int a);	// NOTE: placeholder name
	void unknown6ef100();	// NOTE: placeholder name
};

void BS::unknown6ef100()
{
	if (locations54_d1e88c[locations54_d1e88c.size() - 2]->type == 8)
	{
		if (stringToInt(gameData54_d1e860.getEntryText("exiAttackedLocals_g")))
		{
			if (location54_d1e888->depth == 8)
			{
				int index = location54_d1e888->unknown46ed20();
				if (uniques54_d1dd58[index] != int_caf160 && rng.chance(33))
				{
					Point pos;
					bool done = false;
					for (int i = 0; i < 200; i++)
					{
						cells_cfd44c.getRandom(&pos);
						if ((*cells_cfd44c.atPoint(pos))->canPlaceEntity(entityRecs54_d25de0[uniques54_d1dd58[index]]->size))
						{
							done = true;
							break;
						}
					}
					if (done)
					{
						HEntity e = placeEntity(entityRecs54_d25de0[uniques54_d1dd58[index]],pos,5,true,0x22,0xe,false);
						if (e.isValid())
						{
							e->removeEffectsA(0);
							e->getAI()->unknown5b4710(leader,-1,10000,0,0);
							e->unknown6396a0("EXI_Hero_Revenge_Mines",0);
							opW5_message(0x320,HProp(),string("A strange signal echoes through the mines."),0);
							opR1d_4541b0(0x12c,0,0);
							uniques54_d1dd58[index] = int_caf160;
						}
					}
				}
			}
		}
		else if (stringToInt(gameData54_d1e860.getEntryText("exiMaincAttacked_g")))
		{
			HEntity tester = unknown6c5dc0("Zionite",leader->getPosition(),8,true,0x22,0xe,false);
			tester->getAI()->setFollowEntity(leader,0);
			vector<string> list;
			list.push_back("DK-RAY");
			list.push_back("J5-HVA");
			list.push_back("5L-KAT");
			list.push_back("W1-DM0");
			list.push_back("GM-J5T");
			list.push_back("ZX-C33");
			list.push_back("AM-PHS");
			tester->unknown45b070(OpU8a_randomString(list));
			unknown6c65a0(tester,"EXI_Tester_Escaped_Talk",0);
		}
	}
}
