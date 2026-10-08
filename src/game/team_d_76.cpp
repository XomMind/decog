// team_d_76: BS member 0x74cb00 (Elf summons near the robot held at +0xba8: Schematic Archive items with
// effects, then teleporting Elves).
// NOTE: class layouts are partial; member and method names are placeholders. Matching relies on the Pos
// constructors defined in team_a_repair.cpp (LTCG proves "new Pos(...)" cannot throw).
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();								// NOTE: placeholder name (Push_453b40::operate)
	Point(const Point &p) throw();			// 0x46ca50
	Point &operator=(const Point &p);		// NOTE: folded with the copy constructor (0x46ca50)
};

struct Pos	// NOTE: layout as in team_a_repair.cpp (which defines the constructors)
{
	int x;
	int y;

	Pos(int x_, int y_);	// 0x46ca20
	Pos(int v);				// 0x409990
	Pos &operator=(const Point &p);			// NOTE: folded with Point's copy constructor (0x46ca50)
};

struct Area
{
	int x1;
	int y1;
	int x2;
	int y2;

	Area();									// NOTE: placeholder name (Calls_40b100::delegate)
	void randomPoint_40be30(Point *out);	// NOTE: placeholder name
};

struct Range76	// NOTE: placeholder name (Point::randomInRange_40c130)
{
	int lo;
	int hi;

	int randomInRange_40c130();
};
extern Range76 range76_d2a4fc;	// NOTE: placeholder name
extern Range76 range76_d2f658;	// NOTE: placeholder name

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	T &pick();
};
extern OpR5h_WL<int> picks76_d31700;	// NOTE: placeholder name

struct OpQ5_U9d7a40;	// item data record
template <class T> bool OpQ5_findByName(vector<T*> &v, const string &name, T *&result);	// NOTE: placeholder name; const string& here (the exe instantiation takes string&)
extern vector<OpQ5_U9d7a40 *> itemData76_d2d1c4;	// NOTE: placeholder name
extern vector<int> effectTable76_d2f0f8;	// NOTE: placeholder name

class HProp
{
public:
	int ID;
	HProp();
};

void opW5_message(int type, HProp prop, const string &text, int value);	// NOTE: placeholder name
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)
int opR1d_454260(const Point &p, int id);	// NOTE: placeholder name

class Entity;
class EntityAI;

class HEntity
{
public:
	int ID;
	bool isValid() const;
	bool isNull() const;
	Entity *operator->() const;
};

class Item
{
public:
	void addEffect(Pos *effect);				// NOTE: placeholder name
	int getEffectValue(int type);				// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	bool isValid() const;
	Item *operator->() const;
};

class EntityAI
{
public:
	HEntity unknown458f50();					// NOTE: placeholder name (target)
	void unknown5b51b0(HEntity e);				// NOTE: placeholder name
	void setFollowEntity(HEntity followEntity_, int followParam_);
};

class Entity
{
public:
	EntityAI *getAI();
	Point &getPosition();
};

class CellGrid76	// NOTE: placeholder name (0xcfd44c)
{
public:
	void getRect(const Point &center, int radius, Area *out);
};
extern CellGrid76 cells76_cfd44c;	// NOTE: placeholder name

struct ItemDef76	// NOTE: placeholder name and layout
{
	int value;
};

class GameData76	// NOTE: placeholder name (0xd1e860)
{
public:
	int unknown46f4e0();	// NOTE: placeholder name
};
extern GameData76 gameData76_d1e860;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

class EffectObj76	// NOTE: placeholder name (object initialized by 0x503b20)
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name
};

class EndObjB
{
public:
	EffectObj76 *unknown508610();	// NOTE: placeholder name
};
extern EndObjB *endObj76_cefc50;	// NOTE: placeholder name
extern Point point76_d2e20c;		// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	char	pad000[0xba8];
	HEntity	unknownba8;		// +0xba8
	int		unknownbac;		// +0xbac (last turn)
	int		unknownbb0;		// +0xbb0 (count)

	int getTurn();
	HItem unknown6c5400(int id, const Point &pos);					// NOTE: placeholder name
	HItem unknown6c5400(OpQ5_U9d7a40 *type, const Point &pos);		// NOTE: placeholder name
	ItemDef76 *selectRandomItem(int chanceType, int rating, int category);
	ItemDef76 *unknown6c5180();										// NOTE: placeholder name
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
	bool unknown716940(const Point &from, const Point &to, Entity *e, unsigned int *length);	// NOTE: placeholder name
	HEntity unknown6c5dc0(const string &name, const Point &pos, int group, bool flag, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name
	bool isVisible(const Point &p);
	void unknown74cb00();	// NOTE: placeholder name
};
extern BS *world76_cefc4c;	// NOTE: placeholder name

void BS::unknown74cb00()
{
	if (!unknownba8.operator->() || getTurn() == unknownbac)
		return;
	for (int i = range76_d2a4fc.randomInRange_40c130(); i != 0; i--)
		unknown6c5400(picks76_d31700.pick(),unknownba8->getPosition());
	OpQ5_U9d7a40 *elem;
	if (OpQ5_findByName(itemData76_d2d1c4,"Schematic Archive",elem))
	{
		for (int j = range76_d2f658.randomInRange_40c130(); j != 0; j--)
		{
			HItem item = unknown6c5400(elem,unknownba8->getPosition());
			if (item.isValid())
			{
				if (rng.chance(75))
				{
					ItemDef76 *def = world76_cefc4c->selectRandomItem(0,0x1f,0x12);
					if (def)
						item->addEffect(new Pos(effectTable76_d2f0f8[0x4f],def->value));
				}
				else
				{
					ItemDef76 *def2 = world76_cefc4c->unknown6c5180();
					if (def2)
						item->addEffect(new Pos(effectTable76_d2f0f8[0x4f],-def2->value));
				}
				if (!item->getEffectValue(0x4f))
					item->unknown57dbe0(0,0,1,1);
			}
		}
	}
	Point pt;
	HEntity tag = unknownba8->getAI()->unknown458f50();
	if (tag.isNull())
		tag = unknownba8;
	pt = tag->getPosition();
	Area root;
	cells76_cfd44c.getRect(pt,0xf,&root);
	Point to;
	Pos point(-1);
	int amount;
	int best = 0;
	for (int k = 0; k < unknownbb0; k++)
	{
		for (int t = 0; t < 100; t++)
		{
			root.randomPoint_40be30(&to);
			if (findPlaceableNear(to,to,1) && unknown716940(pt,to,0,0))
			{
				HEntity e = world76_cefc4c->unknown6c5dc0("Elf",to,3,false,0x22,0xe,false);
				if (e.isValid())
				{
					unknownba8->getAI()->unknown5b51b0(e);
					e->getAI()->setFollowEntity(unknownba8,0);
					if (isVisible(to))
					{
						opW5_message(0x320,HProp(),string("An Elf is summoned!"),0);
						int id;
						if (OpU8a_lookup2("Teleport_Elf",&id))
							endObj76_cefc50->unknown508610()->init(endObj76_cefc50,id,to,point76_d2e20c,0,0,0,9,0);
						amount = opR1d_454260(to,0x13d);
						if (amount && amount > best)
						{
							best = amount;
							point = to;
						}
					}
				}
				break;
			}
		}
	}
	if (best)
		opR1d_454260(to,0x13d);
	unknownbac = getTurn();
	if (rng.chance(gameData76_d1e860.unknown46f4e0() * 4 + 0x23))
		unknownbb0++;
}
