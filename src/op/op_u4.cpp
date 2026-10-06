// op_u4: functions in [0x68d000,0x700000). NOTE: layouts partial; names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x, y;
	Point(int x_, int y_);
	Point(const Point &p) throw();	// 0x46ca50
};
class GameData	// NOTE: placeholder name
{
public:
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};
extern GameData gameData;			// NOTE: placeholder name (0xd1e860)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
extern int	opu4_d1eac0;			// NOTE: placeholder name

class OpU4_Dialog	// NOTE: placeholder name
{
public:
	void unknown6df000();	// NOTE: placeholder name
	void unknown6df0b0(bool flag);	// NOTE: placeholder name
};

void OpU4_Dialog::unknown6df000()
{
	if (opu4_d1eac0 == 0 || opu4_d1eac0 == 1)
	{
		int attacked = stringToInt(gameData.unknown46f6d0("exiAttackedLocals_g"));
		if (attacked)
			unknown6df0b0(true);
	}
}

class Console;
template <class T> void deleteVector(vector<T*> &v);	// NOTE: placeholder name (0x9d21f0 for Console)
extern int	opu4_cf4718;			// NOTE: placeholder name
struct OpU4_Range	// NOTE: placeholder name
{
	int lo, hi;
	int randomInRange_40c130();	// NOTE: placeholder name
};
extern OpU4_Range opu4_cf6b0c[];	// NOTE: placeholder name

class OpU4_Wrapper43aeb0	// NOTE: placeholder name
{
public:
	~OpU4_Wrapper43aeb0();	// 0x43aeb0 scalar deleting dtor
};

class OpU4_Field9b7270	// NOTE: placeholder name
{
public:
	void resetField();
};

struct OpU4_EntityRecord	// NOTE: placeholder name
{
	int unknown0;
	string name;
};
extern vector<OpU4_EntityRecord *>	opu4_d25de0;	// NOTE: placeholder name
extern int	opu4_caf160;	// NOTE: placeholder name
void opu4_shuffle(vector<int> &v);	// NOTE: placeholder name (0x9d8f80)
void opu4_insertAt(vector<int> &v, int index, int value);	// NOTE: placeholder name (0x9dbdc0)

struct OpU4_Obj10	// NOTE: placeholder name
{
	void unknown9ceaf0(int a, int b);	// NOTE: placeholder name
};

class OpU4_Mode	// NOTE: placeholder name
{
public:
	bool unknown0;
	int unknown4;
	int unknown8;
	int unknownc;
	OpU4_Obj10 obj10;
	char pad11[0x0f];
	vector<int> list20;
	vector<int> list30;
	int unknown40;
	int unknown44;
	vector<Console*> consolesA;
	vector<Console*> consolesB;
	OpU4_Wrapper43aeb0 *wrapper;
	OpU4_Field9b7270 field6c;
	vector<Console*> consolesC;
	int unknown80;
	vector<Console*> consolesD;
	void unknown6be810();	// NOTE: placeholder name
	void unknown6be920();	// NOTE: placeholder name
};

void OpU4_Mode::unknown6be920()
{
	unknown44 = 0;
	unknown4 = opu4_cf6b0c[opu4_cf4718].randomInRange_40c130();
	consolesA.clear();
	deleteVector(consolesB);
	delete wrapper;
	wrapper = NULL;
	field6c.resetField();
	consolesC.clear();
	unknown80 = 15;
	consolesD.clear();
}

void OpU4_Mode::unknown6be810()
{
	unknown0 = false;
	unknown8 = 0;
	unknownc = 0;
	obj10.unknown9ceaf0(11, 0);
	list20.clear();
	int i;
	for (i = 0; i < opu4_d25de0.size(); i++)
	{
		if (opu4_d25de0[i]->name.find("Zion_Hero_", 0) != string::npos)
			list20.push_back(i);
	}
	opu4_shuffle(list20);
	while (list20.size() < 11)
		opu4_insertAt(list20, 0, opu4_caf160);
	int zero = 0;
	list30.assign(list20.size(), zero);
	unknown40 = 0;
	unknown6be920();
}

class Entity	// NOTE: placeholder layout
{
public:
	bool unknown5d2a00(int type);	// NOTE: placeholder name
	bool isPlayer();
	class OpU4_AI *getAI();	// NOTE: placeholder name (0x45b590)
	const Point &getPosition();	// NOTE: placeholder name
	void unknown5fd900(int level, int duration);	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
	bool isValid() const;
	Entity *operator->() const throw();	// 0x9b6570
};

class Map	// NOTE: partial
{
public:
	HEntity getPlayer() throw();	// 0x4630f0
};

class Push_46ed20
{
public:
	char unknown0[0x8];
	int field8;
	int operate();
};

class OpU4_HGameState	// NOTE: placeholder name
{
public:
	int ID;
	Push_46ed20 *operator->() const;	// 0x9b7910
};
extern OpU4_HGameState opu4_d1e888;	// NOTE: placeholder name

struct OpR5h_Pair	// NOTE: placeholder name
{
	int value;
	int weight;
};

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void init(const struct OpR5h_Pair *pairs, int count);	// NOTE: placeholder name (0x9b9e90)
	void add(T value, int weight);	// 0x9ba310
	void removeAt(int index);	// NOTE: placeholder name (0x9c1d20)
	T &pick();	// 0x9ba470
	unsigned int size();	// NOTE: placeholder name (0x9b81d0)
	vector<T> *getValues();	// NOTE: placeholder name (0x9c0790)
};

extern int		opu4_table[21][11];	// NOTE: placeholder name (0xbbb618)
extern Map		*opu4_world;		// NOTE: placeholder name (0xcefc4c)
extern Entity	*opu4_d338e8;		// NOTE: placeholder name

class OpU4_Obj6bed40	// NOTE: placeholder name
{
public:
	char pad0[0x20];
	vector<int> list20;
	char pad30[0x10];
	int unknown40;
	void unknown6bed40(OpR5h_WL<int> *a, OpR5h_WL<int> *b);	// NOTE: placeholder name
};

void OpU4_Obj6bed40::unknown6bed40(OpR5h_WL<int> *a, OpR5h_WL<int> *b)
{
	int depth = opu4_d1e888->operate();
	for (int i = 0; i <= 7; i++)
	{
		if (opu4_table[i][depth] != 0)
		{
			if (i == 7)
			{
				if (depth < unknown40 + 2 || list20[depth] == opu4_caf160)
					continue;
			}
			a->add(i, opu4_table[i][depth]);
		}
	}
	for (int j = 8; j < 21; j++)
	{
		if (opu4_table[j][depth] != 0)
		{
			int mult = 1;
			if (j == 12)
			{
				if (opu4_world->getPlayer().isValid() ? opu4_world->getPlayer()->unknown5d2a00(0xa6) : opu4_d338e8->unknown5d2a00(0xa6))
					mult = 2;
			}
			b->add(j, opu4_table[j][depth] * mult);
		}
	}
}

class OpR1e_Variant
{
public:
	void appendCode459d00(string &code);	// NOTE: placeholder name
};
extern vector<OpR1e_Variant *>	opu4_variants;	// NOTE: placeholder name (0xd25de0)
extern vector<int>				opu4_d1dd80;	// NOTE: placeholder name
extern OpU4_Range				opu4_d1dde0[];	// NOTE: placeholder name

class OpU4_Spawn	// NOTE: placeholder name
{
public:
	int type;
	string code;
	int unknown20;
	OpU4_Spawn(int type_);	// NOTE: placeholder name
};

OpU4_Spawn::OpU4_Spawn(int type_)
	: type	(type_)
{
	if (type <= 7)
	{
		if (opu4_d1dd80[type] != opu4_caf160)
			opu4_variants[opu4_d1dd80[type]]->appendCode459d00(code);
	}
	unknown20 = opu4_d1dde0[type].randomInRange_40c130();
}

class OpU4_GridCell	// NOTE: placeholder name
{
public:
	int getHeight();	// NOTE: placeholder name (0x9b8f00)
};

class OpU4_Grid	// NOTE: placeholder name
{
public:
	OpU4_GridCell *at(int x, int y);	// NOTE: placeholder name (0x9cdf20)
	bool contains(int x, int y);		// NOTE: placeholder name (0x9b45c0)
};

bool opu4_containsPoint(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d0ce0)

void opu4_floodFill(OpU4_Grid *grid, int x, int y, vector<Point> *visited)	// NOTE: placeholder name
{
	if (grid->at(x,y)->getHeight() != 32)
	{
		if (!opu4_containsPoint(*visited,Point(x,y)))
		{
			visited->push_back(Point(x,y));
			if (grid->contains(x - 1,y))
				opu4_floodFill(grid,x - 1,y,visited);
			if (grid->contains(x + 1,y))
				opu4_floodFill(grid,x + 1,y,visited);
			if (grid->contains(x,y - 1))
				opu4_floodFill(grid,x,y - 1,visited);
			if (grid->contains(x,y + 1))
				opu4_floodFill(grid,x,y + 1,visited);
		}
	}
}

struct OpU4_MapRecord	// NOTE: placeholder name
{
	char pad0[0x48];
	int unknown48;
};
extern vector<OpU4_MapRecord *>	opu4_d2d1c4;	// NOTE: placeholder name
extern int						opu4_caf164;	// NOTE: placeholder name

class OpU4_Obj6ed550	// NOTE: placeholder name
{
public:
	char pad0[0xb4c];
	OpR5h_WL<int> weights;
	int unknown6ed550(int type);	// NOTE: placeholder name
};

int OpU4_Obj6ed550::unknown6ed550(int type)
{
	OpR5h_WL<int> list(weights);
	vector<int> *values = list.getValues();
	for (int i = list.size() - 1; i >= 0; i--)
	{
		if (opu4_d2d1c4[(*values)[i]]->unknown48 != type)
			list.removeAt(i);
	}
	if (list.size())
	{
		return list.pick();
	}
	else
	{
		return opu4_caf164;
	}
}

struct OpQ5_U9db510;
template <class T> bool OpQ5_findByName(vector<T*> &v, string &name, T *&result);	// NOTE: placeholder name (0x9db510 for OpQ5_U9db510)
extern vector<OpQ5_U9db510 *>	opu4_d2f0f8;	// NOTE: placeholder name
void opr5c_unknown4351e0(string &text);	// NOTE: placeholder name
void opw1_split(const string &text, char separator, vector<string> &out);	// NOTE: placeholder name (0x408700)
bool opw8_extractParenthesized(string &s, string &out);	// NOTE: placeholder name (0x436d80)

class OpU4_Obj6ccdf0	// NOTE: placeholder name
{
public:
	char pad0[0x7c];
	vector<string> strings;
};

void opu4_unknown6ccdf0(int unused, OpU4_Obj6ccdf0 *obj, int index, vector<OpQ5_U9db510 *> *types, vector<int> *weights)	// NOTE: placeholder name
{
	vector<string> parts;
	opr5c_unknown4351e0(obj->strings[index]);
	opw1_split(obj->strings[index],'|',parts);
	string part;
	{
		OpQ5_U9db510 *type;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (!opw8_extractParenthesized(parts[i],part))
				goto next;
			if (!OpQ5_findByName(opu4_d2f0f8,parts[i],type))
				goto next;
			types->push_back(type);
			weights->push_back(part.empty() ? 1 : stringToInt(part));
		next:;
		}
	}
}

struct OpQ5_U9d7de0	// NOTE: placeholder layout
{
	char pad0[0x3c];
	int unknown3c;
};
extern vector<OpQ5_U9d7de0 *>	opu4_d2c408;	// NOTE: placeholder name
extern int						opu4_ba5f40[];	// NOTE: placeholder name

void opu4_unknown6ccf60(int unused, OpU4_Obj6ccdf0 *obj, int index, vector<OpQ5_U9d7de0 *> *out, int filter)	// NOTE: placeholder name
{
	vector<string> parts;
	opr5c_unknown4351e0(obj->strings[index]);
	opw1_split(obj->strings[index],'|',parts);
	{
		OpQ5_U9d7de0 *type;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i][0] == '&')
			{
				out->push_back(opu4_d2c408[stringToInt(string(parts[i].begin() + 1,parts[i].end()))]);
			}
			else
			{
				if (!OpQ5_findByName(opu4_d2c408,parts[i],type))
					goto next;
				if (opu4_ba5f40[type->unknown3c] != filter)
					goto next;
				out->push_back(type);
			}
		next:;
		}
	}
}

class EntityRecord;
class ItemDef
{
public:
	char pad0[0x64];
	int unknown64;
};
template <class T> int OpQ5_randomIndex(vector<T> &v);	// NOTE: placeholder name (0x9d9b20)
class OpU4_GameData	// NOTE: placeholder name
{
public:
	bool unknown46f4b0(int a);	// NOTE: placeholder name
};
extern OpU4_GameData	opu4_gameData;	// NOTE: placeholder name (0xd1e860)
extern OpR5h_Pair		opu4_b957e0[];	// NOTE: placeholder name

class BS
{
public:
	char pad0[0x30];
	bool unknown30;
	char pad31[0x658 - 0x31];
	EntityRecord *unknown6c5600(int a, int b, int c, int d);	// NOTE: placeholder name (0x6c5600)
	HEntity placeEntity(EntityRecord *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// 0x6c58c0
	HEntity unknown6c6450(HEntity target, bool flag);	// NOTE: placeholder name
	ItemDef *selectRandomItem(int chanceType, int rating, int category);	// 0x6c3bc0
	ItemDef *selectRandomItemOfRating(int level, int mode, int chanceType, int rating, int category, int unknown, int attempt);	// 0x6c40e0
};

HEntity BS::unknown6c6450(HEntity target, bool flag)
{
	if (!unknown30 || !opu4_gameData.unknown46f4b0(1))
		return HEntity();
	{
		OpR5h_WL<int> wl;
		wl.init(opu4_b957e0,9);
		EntityRecord *record;
		for (int i = 0; i < 20; i++)
		{
			record = unknown6c5600(1,wl.pick(),0,0);
			if (record != NULL)
				break;
		}
		HEntity placed;
		if (record)
		{
			placed = placeEntity(record,target->getPosition(),4,flag,0x22,0xe,false);
			if (placed.isValid())
				placed->unknown5fd900(4,99999);
		}

		return placed;
	}
}

struct OpU4_Area	// NOTE: placeholder name
{
	Point min;
	Point max;
	OpU4_Area();	// 0x40b100
	bool contains_40b750(const Point &p);	// NOTE: placeholder name
};

class OpU4_AI	// NOTE: placeholder name
{
public:
	int unknown9b8f00();	// NOTE: placeholder name (ICF'd trivial getter)
	HEntity getFollowEntity();	// NOTE: placeholder name
	OpU4_Area *getArea();	// NOTE: placeholder name (0x4b5730)
	void unknown459470(OpU4_Area &area);	// NOTE: placeholder name (Calls_459470::delegate)
};

class OpU4_Grid2
{
public:
	void getRect(const Point &p, int radius, OpU4_Area &out);	// NOTE: placeholder name (0x9b4430)
};
extern OpU4_Grid2 opu4_cfd44c;	// NOTE: placeholder name

class OpU4_Obj699f30	// NOTE: placeholder name
{
public:
	char padfc[0xfc];
	HEntity unknownfc;
	void unknown699f30();	// NOTE: placeholder name
};

void OpU4_Obj699f30::unknown699f30()
{
	if (unknownfc->getAI()->unknown9b8f00() == 1)
		return;
	HEntity target;
	if (unknownfc->getAI()->getFollowEntity().isValid())
	{
		target = unknownfc->getAI()->getFollowEntity();
		if (target.operator->() == NULL || target->isPlayer())
			return;
	}
	else
	{
		target = unknownfc;
	}
	if (target->getAI()->unknown9b8f00() != 3 || !target->getAI()->getArea()->contains_40b750(opu4_world->getPlayer()->getPosition()))
	{
		OpU4_Area area;
		opu4_cfd44c.getRect(opu4_world->getPlayer()->getPosition(),15,area);
		target->getAI()->unknown459470(area);
	}
}
