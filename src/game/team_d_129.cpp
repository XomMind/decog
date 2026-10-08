// team_d_129: Cell member 0x66e650 (callers SEntityShoot::update and 0x5045f0): a shot or blast hits a cell's
// terrain - special weapons start an effect instead, a certain mode/terrain combination triggers a breach,
// otherwise the damage is rolled from the weapon range with the attacker's bonuses, scaled by the terrain's
// resistance and applied; messages report insufficient damage or destruction.
// NOTE: class layouts are partial; names are placeholders. Local names follow the stack-slot hash order.
// NOTE: x is the terrain definition and f the "bonus already applied" flag (names chosen for slot order).
#include <string>
#include <vector>
using namespace std;

void opS2_fn510360(string &text);	// NOTE: placeholder name (0x510360)
void OpV4c_Fn9d06d0(int *value, int a, int b);	// NOTE: placeholder name
void opR1d_454160(const struct Point &p, int sound, int channel);	// NOTE: placeholder name

struct Point
{
	int x;
	int y;

	Point(const Point &p);			// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
	int randomInRange_40c130();	// NOTE: placeholder name
};
extern Point playerPos129_d1d9fc;	// NOTE: placeholder name

class Entity;

class HEntity
{
public:
	int ID;
	HEntity();
	Entity *operator->() const;
};

class HProp
{
public:
	int ID;
	HProp();
};

class HItem
{
public:
	int ID;
	HItem();
};

class Entity
{
public:
	int unknown5d22a0(int type);	// NOTE: placeholder name
	int unknown5d2150(int type, int base);	// NOTE: placeholder name
	int unknown5d2090(int type);	// NOTE: placeholder name
	bool isPlayer();
};

struct Weapon129	// NOTE: placeholder name and layout (item record)
{
	char	pad000[0x44];
	int		type;		// +0x044
	char	pad048[0xf0 - 0x48];
	int		unknownf0;	// +0x0f0
	char	pad0f4[0x120 - 0xf4];
	Point	damage;		// +0x120
	int		damageType;	// +0x128
	char	pad12c[0x165 - 0x12c];
	bool	unknown165;	// +0x165
	char	pad166[0x16c - 0x166];
	int		unknown16c;	// +0x16c
	char	pad170[0x1a0 - 0x170];
	int		unknown1a0;	// +0x1a0
	char	pad1a4[0x1b0 - 0x1a4];
	bool	unknown1b0;	// +0x1b0
	char	pad1b1[0x278 - 0x1b1];
	int		*unknown278;	// +0x278
	int		soundMode;	// +0x27c
	int		sound;		// +0x280

	int getValue457330(int id);	// NOTE: placeholder name (OpR1e_RecLists::getValue457330)
};

struct TerrainInfo129	// NOTE: placeholder name and layout
{
	char					pad00[0x20];
	int						resist[8];	// +0x20 (indexed by damage type)
	char					pad40[0x50 - 0x40];
	vector< vector<int> >	sounds;		// +0x50
};

struct TerrainDef129	// NOTE: placeholder name and layout
{
	char			pad00[0x20];
	string			name;		// +0x20
	char			pad3c[0x50 - 0x3c];
	TerrainInfo129	*info;		// +0x50
	char			pad54[0x5c - 0x54];
	int				unknown5c;	// +0x5c
};

struct CellEffect129	// NOTE: placeholder name (CellEffect); the throw() constructor keeps the new expression free of EH state
{
	int		type;
	int		count;	// +0x04

	CellEffect129(int type_, int count_) throw();	// NOTE: folded with Pos(int, int), 0x46ca20
};
extern vector<int> effectTypes129_d2f0f8;	// NOTE: placeholder name

struct TurnRecord129;	// NOTE: placeholder name
bool turnUpdate129_51da30(vector<TurnRecord129 *> *records, int type, HEntity a, HProp b, HItem c, const Point *pos, int flag);	// NOTE: placeholder name (BS::turnUpdate_51da30)

struct TerrainType129	// NOTE: placeholder name
{
	int		ID;
};
extern TerrainType129 *terrain129_cefb90;	// NOTE: placeholder name

class BS
{
public:
	bool unknown463e90(const Point &p);	// NOTE: placeholder name
	void unknown74b060(const Point &p, int a, int b);	// NOTE: placeholder name
};
extern BS *world129_cefc4c;	// NOTE: placeholder name

class Stats129	// NOTE: placeholder name (OpR1h_Stats at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name
};
extern Stats129 stats129_d2c658;	// NOTE: placeholder name

class ConsoleA129	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA129 *consoleA129_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs129_cec0b4;	// NOTE: placeholder name
extern CLogMsgs *logMsgs129_cec0c4;	// NOTE: placeholder name

bool showMessage129(int id, const string *text, const string *b, int c, HProp d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)

class Hints129	// NOTE: placeholder name (OpU5s2_Unk793450, GM at 0xcefaa8)
{
public:
	void showOnce(int id, bool player, const string *text, int a, int b);	// NOTE: placeholder name
};
extern Hints129 *hints129_cefaa8;	// NOTE: placeholder name

class PlayerData129	// NOTE: placeholder name (PlayerData at 0xcf45d8)
{
public:
	bool hasCompanion();
};
extern PlayerData129 playerData129_cf45d8;	// NOTE: placeholder name

class SpawnTracker129	// NOTE: placeholder name (OpU5_SpawnTracker)
{
public:
	void spawn(int type, bool flag, string text);
};

struct ItemRec129	// NOTE: placeholder name and layout (OpS1f_ItemRec at *0xcf4ac8)
{
	char			pad00[0x30];
	SpawnTracker129	*tracker;	// +0x30
};
extern ItemRec129 *itemRec129_cf4ac8;	// NOTE: placeholder name

extern int mode129_cf462c;		// NOTE: placeholder name
extern int damageBonus129_cf49bc[];	// NOTE: placeholder name
extern int lastDamage129_d1f3f0;	// NOTE: placeholder name
extern int messageLevel129_d28d18;	// NOTE: placeholder name

class Cell	// NOTE: placeholder layout
{
public:
	TerrainDef129	*def;	// +0x00
	char			pad04[0x30 - 4];
	Point			pos;	// +0x30

	void unknown45e110(bool a, bool b, HProp p);	// NOTE: placeholder name (Effect_45e110::trigger)
	CellEffect129 *getEffect(int type);
	void unknown45df90(CellEffect129 *effect);
	void unknown66a050(int terrainID, int cause, int flag);	// NOTE: placeholder name
	bool unknown45d4e0();	// NOTE: placeholder name
	bool unknown66dae0(int damage, int type, int a, int b, int cause, int c, HEntity attacker, bool flag);	// NOTE: placeholder name
	void unknown66e650(HEntity attacker, int direct, vector<TurnRecord129 *> *records, Weapon129 *weapon, float scale, bool flag);	// NOTE: placeholder name
};

void Cell::unknown66e650(HEntity attacker, int direct, vector<TurnRecord129 *> *records, Weapon129 *weapon, float scale, bool flag)
{
	if (weapon->getValue457330(0x43))
	{
		unknown45e110(false,false,HProp());
		CellEffect129 *effect = getEffect(5);
		if (effect)
			effect->count++;
		else
			unknown45df90(new CellEffect129(effectTypes129_d2f0f8[5],1));
		return;
	}
	if (mode129_cf462c == 8 && def->unknown5c != 0 && def->unknown5c <= 2 && (def->unknown5c != 2 || world129_cefc4c->unknown463e90(pos)) && weapon->getValue457330(0x3d))
	{
		unknown66a050(terrain129_cefb90->ID,7,0);
		stats129_d2c658.add4729d0(0x411,1,"",-1);
		string msg("^22_Ozzc dplwpo... JPD!");
		opS2_fn510360(msg);
		do
		{
			if (showMessage129(0x320,&msg,0,0,HProp(),HProp(),&pos,0))
				consoleA129_cec058->unknown8758d0(true);
			logMsgs129_cec0b4->scrollToEnd();
		} while (0);
	}
	if (!unknown45d4e0() && !weapon->unknown1a0)
		return;
	int type = weapon->damageType;
	switch (type)
	{
	case 10:
		return;
	}
	bool f = false;
	int damage;
	if (type == 9)
		damage = 0;
	else
	{
		Point range(weapon->damage);
		if (attacker.operator->())
		{
			if (weapon->unknown1b0 && !weapon->unknown165 && attacker->unknown5d22a0(0x66))
			{
				int bonus = attacker->unknown5d22a0(0x66);
				range.x += range.x * bonus / 100;
				range.y += range.y * bonus / 100;
				f = true;
			}
			else if (!direct)
			{
				range.y += attacker->unknown5d2150(0x6a,0) * range.y / 100;
				OpV4c_Fn9d06d0(&range.x,attacker->unknown5d2090(0x5a) / 2,range.y);
			}
			else if (weapon->type == 0x16 || weapon->type == 0x17)
			{
				range.x += attacker->unknown5d22a0(0x69) * range.x / 100;
				if (range.x > range.y)
					range.y = range.x;
			}
		}
		damage = (int)(range.randomInRange_40c130() * scale);
	}
	if (attacker.operator->() && (weapon->type == 0x14 || weapon->type == 0x15) && !weapon->unknown165 && !f)
		damage += attacker->unknown5d2150(0x67,0) * damage / 100;
	if (type < 7)
	{
		if (damageBonus129_cf49bc[type] && attacker.operator->() && attacker->isPlayer())
			damage += damage * damageBonus129_cf49bc[type] / 100;
		damage = damage * def->info->resist[type] / 100;
	}
	lastDamage129_d1f3f0 = damage;
	if (records)
	{
		turnUpdate129_51da30(records,0x17,HEntity(),HProp(),HItem(),&pos,0);
		turnUpdate129_51da30(records,0x18,HEntity(),HProp(),HItem(),&pos,0);
	}
	if (type == 9)
		return;
	world129_cefc4c->unknown74b060(pos,weapon->unknown16c,100);
	TerrainDef129 *x = def;
	if (!unknown66dae0(damage,type,0,0,!direct ? 2 : (weapon ? (weapon->type == 0x14 || weapon->type == 0x16 ? 3 : 4) : 5),0,attacker,flag))
	{
		if (messageLevel129_d28d18 >= 0 && playerPos129_d1d9fc == pos && attacker.operator->() && attacker->isPlayer())
		{
			string text = "  Damage insufficient to overcome " + x->name + " armor";
			do
			{
				if (showMessage129(0x2cc,&text,0,0,HProp(),HProp(),&pos,1))
					consoleA129_cec058->unknown8758d0(false);
				logMsgs129_cec0c4->scrollToEnd();
			} while (0);
			hints129_cefaa8->showOnce(0x55,true,0,0,0);
		}
		int sound = 0;
		int sound2 = 0;
		switch (weapon->soundMode)
		{
			break;
		case 1:
			sound = weapon->sound;
			break;
		case 2:
			sound = def->info->sounds[2][*weapon->unknown278];
			sound2 = def->info->sounds[3][*weapon->unknown278];
		}
		if (sound)
			opR1d_454160(pos,sound,0x12);
		if (sound2)
			opR1d_454160(pos,sound2,0x12);
		return;
	}
	if (messageLevel129_d28d18 == 1)
	{
		string text2 = "  " + x->name + " destroyed";
		do
		{
			if (showMessage129(0x2cc,&text2,0,0,HProp(),HProp(),&pos,1))
				consoleA129_cec058->unknown8758d0(false);
			logMsgs129_cec0c4->scrollToEnd();
		} while (0);
	}
	if (weapon && weapon->unknownf0 == 0xd6 && playerData129_cf45d8.hasCompanion())
		itemRec129_cf4ac8->tracker->spawn(0x21,false,"");
}
