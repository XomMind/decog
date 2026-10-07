//==================================================================
// Entity::checkEffectScrapEngine (0x605040, 0xb3a1 bytes): semantic reconstruction
//==================================================================
// Not byte-matched. Same behaviour as the exe: same callees in the same order (RNG calls included),
// same strings and globals. Notes, open questions and unresolved callees: docs/giants/605040.md.
// names.csv calls this BS::checkEffectScrapEngine, but 'this' is the Entity (self at +0x4, parts at
// +0x134) and the function's own error string says "Entity::checkEffectScrapEngine()"; the only caller
// is Entity::turnUpdate (0x610430).
// Callees keep their csv names (or unknown<va> when the exe function is unnamed or ICF-folded);
// members whose meaning is not known are unknown<offset>.

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

//==================================================================
// declarations (only the members this function touches; 32-bit offsets in comments)
//==================================================================

class Entity;
class Item;
struct ItemType;

struct Point
{
	int x;	// +0x0
	int y;	// +0x4

	Point(int v);					// 0x409990: x = y = v
	void set(int x_, int y_);		// 0x40a010
	int randomInRange_40c130();	// NOTE: placeholder name (0x40c130): rng.rangeInt(x,y), or y when the range is empty
	int clamp_40c270(int value);	// NOTE: placeholder name (0x40c270): clamp value to [x,y]
};

class HEntity
{
public:
	int ID;	// +0x0

	HEntity();								// 0x9b6590
};

class HProp
{
public:
	int ID;	// +0x0

	HProp();								// 0x9b6590
};

class HItem
{
public:
	int ID;	// +0x0

	HItem();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	bool isNull() const;					// 0x9b65d0
	Item *operator->() const;				// 0x9b65b0
};

class RNG
{
public:
	bool chance(int percent);			// 0x406c90
	int rangeInt(float a, float b);		// 0x406d70
	float rangeFloat(float a, float b);	// 0x406e20
};

struct ItemType	// NOTE: placeholder name; elements of itemTypes (0xd2d1c4), Item+0x8
{
	int				ID;				// +0x0 NOTE: placeholder name (index in itemTypes)
	string			internalName;	// +0x8 NOTE: placeholder name ("Scrap Engine", shown in the upgrade log)
	string			name;			// +0x24
	int				unknown44;		// +0x44 NOTE: placeholder name (part type: 6 engine, 8 reactor, 9..13 propulsion, 20..23 weapon kinds)
	int				slot;			// +0x48 NOTE: placeholder name (0 power, 1 propulsion, 2 utility, 3 weapon)
	int				size;			// +0x4c NOTE: placeholder name (slots occupied)
	int				rating;			// +0x50 NOTE: placeholder name
	int				unknown78;		// +0x78 NOTE: placeholder name (copied from the source part with the best rating)
	int				unknown94;		// +0x94 NOTE: placeholder name
	int				unknownA4;		// +0xa4 stat 0
	int				maxIntegrity;	// +0xa8 stat 1
	int				unknownAC;		// +0xac stat 2
	int				unknownB0;		// +0xb0 stat 3
	float			unknownB4;		// +0xb4 stat 4
	int				unknownB8;		// +0xb8 stat 5
	int				unknownBC;		// +0xbc stat 6
	int				unknownC0;		// +0xc0 stat 7
	int				unknownC8;		// +0xc8 stat 8 (non-zero: the construct is "Cld.")
	int				unknownCC;		// +0xcc stat 9
	int				unknownD4;		// +0xd4 NOTE: placeholder name (scaled when a propulsion construct grows, except types 12/13)
	float			unknownD8;		// +0xd8 stat 10
	int				unknownDC;		// +0xdc stat 11
	int				unknownE0;		// +0xe0 stat 12
	int				unknownE4;		// +0xe4 stat 13
	int				unknownE8;		// +0xe8 stat 14
	int				unknownEC;		// +0xec stat 15
	int				unknown100;		// +0x100 stat 16
	int				unknown104;		// +0x104 stat 17
	int				unknown108;		// +0x108 stat 18
	int				unknown10C;		// +0x10c stat 19
	int				unknown110;		// +0x110 stat 20
	int				unknown114;		// +0x114 stat 21
	int				unknown11C;		// +0x11c stat 23
	int				projectiles;	// +0x118 stat 22 NOTE: placeholder name (damage values are per projectile)
	int				damageMin;		// +0x120 stat 24 NOTE: placeholder name
	int				damageMax;		// +0x124 stat 25 NOTE: placeholder name
	int				damageType;		// +0x128 NOTE: placeholder name (7: the construct unlocks achievement 0x14a)
	int				unknown12C;		// +0x12c stat 26
	int				unknown130;		// +0x130 stat 27
	int				critical;		// +0x134 NOTE: placeholder name (critical type, valid per damage type in scrapCriticalAllowed)
	int				criticalChance;	// +0x138 stat 28 NOTE: placeholder name
	vector<int>		penetration;	// +0x13c NOTE: placeholder name (stat name "Penetration" in the upgrade log)
	int				unknown14C;		// +0x14c stat 29
	int				unknown150;		// +0x150 stat 30
	int				unknown154;		// +0x154 NOTE: placeholder name (copied from the source part closest in stat 30)
	int				unknown158;		// +0x158 NOTE: placeholder name
	int				unknown15C;		// +0x15c stat 31
	bool			scrappable;		// +0x23b NOTE: placeholder name (part type the Scrap Engine can consume/build)
	vector<string>	nameParts;		// +0x23c NOTE: placeholder name (words for the construct's name)

	int *getStatPtr(int index);		// NOTE: placeholder name (0x456da0, OpR1e_Stats::getStatPtr in the csv)
};

class Item
{
public:
	int unknown9fcd80();				// NOTE: placeholder name (ICF'd trivial getter 0x9fcd80): this->+0x0
	ItemType *unknown9b4350();			// NOTE: placeholder name (ICF'd trivial getter 0x9b4350): data (+0x8)
	int getType();						// 0x44aec0: +0xc (<= 3: attached to a slot)
	int unknown9b6bf0();				// NOTE: placeholder name (ICF'd trivial getter 0x9b6bf0): integrity (+0x1c)
	void unknown450460(int value);		// NOTE: placeholder name (ICF'd trivial setter 0x450460): integrity (+0x1c)
	int unknown457820();				// NOTE: placeholder name (0x457820): data->ID
	const string &unknown457860();		// NOTE: placeholder name (0x457860): data->+0x8 (internal name)
	int unknown457880();				// NOTE: placeholder name (0x457880): data->unknown44
	int unknown4578a0();				// NOTE: placeholder name (0x4578a0): data->slot
	int unknown4578c0();				// NOTE: placeholder name (0x4578c0): data->size
	int unknown457900();				// NOTE: placeholder name (0x457900): data->rating
	int unknown457c80();				// NOTE: placeholder name (0x457c80): data->maxIntegrity
	int unknown457ca0();				// NOTE: placeholder name (0x457ca0): integrity percent
	bool unknown457cf0();				// NOTE: placeholder name (0x457cf0): +0x28 != -1 (active?)
	bool unknown458220();				// NOTE: placeholder name (0x458220): +0x40 (overloaded?)
	int unknown458360(int amount);		// NOTE: placeholder name (0x458360): repair
	string getName(int a, int b);		// NOTE: placeholder name (0x571db0)
	bool unknown458180();				// NOTE: placeholder name (0x458180)
	void unknown5759b0(string *slots, vector<struct ScrapSlotEntry> *entries);	// NOTE: placeholder name (0x5759b0): list of the slots the part occupies
	void unknown57a0f0(const Point *p, int a, int b);	// NOTE: placeholder name (0x57a0f0): drop at p
	void unknown57a190(HEntity entity, int slot, int a, int b);	// NOTE: placeholder name (0x57a190): attach to entity
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name (0x57dbe0): destroy/remove the part
};

struct ScrapSlotEntry	// NOTE: placeholder name and layout (elements of the second Item::unknown5759b0 output; dtor 0x9b3da0)
{
	int unknown00;
};

class Cell
{
public:
	HItem getItem();	// NOTE: placeholder name (0x45d8f0)
};

template <class T>
class Array2D	// NOTE: placeholder name (OpX5_Array2D in the csv)
{
public:
	int getWidth();			// NOTE: placeholder name (ICF'd trivial getter 0x9fcd80): +0x0
	int getHeight();		// NOTE: placeholder name (ICF'd trivial getter 0x9b8f00): +0x4
	T *at(int x, int y);	// 0x9ceda0
};

class Entity
{
public:
	HEntity self;			// +0x4
	vector<HItem> items;	// +0x134 attached parts

	void checkEffectScrapEngine(HItem engine);	// 0x605040

	void unknown5c93d0(vector<int> *out);	// NOTE: placeholder name (0x5c93d0): per-slot counts
	int unknown5cad50();					// NOTE: placeholder name (0x5cad50)
	int unknown5dc440(HItem item);			// NOTE: placeholder name (0x5dc440)
	void unknown5e2b50();					// NOTE: placeholder name (0x5e2b50)
	bool unknown5cd220(HItem item);			// NOTE: placeholder name (0x5cd220)
	int unknown5d1390();					// NOTE: placeholder name (0x5d1390)
};

class Map
{
public:
	HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
	int getTurn();	// 0x464270
	HItem unknown6c51d0(ItemType *type, HEntity owner, bool a, bool b);	// NOTE: placeholder name (0x6c51d0, BS::unknown6c51d0 in the csv): create a part attached to owner
};

class PlayerData	// NOTE: partial (object at 0xcf45d8)
{
public:
	bool unknown46df10();				// NOTE: placeholder name (0x46df10, Unknown46d8b0::hasMarkedList in the csv)
	void unknown77fbc0(int id);			// NOTE: placeholder name (0x77fbc0): looks like "unlock achievement id"
};

class OpR1h_Stats	// NOTE: placeholder name (object at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
};

class OpW5_RolledValues	// NOTE: placeholder name (object pointer at 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);	// 0x49e250
};

class GM	// NOTE: partial (object at 0xd25628)
{
public:
	void addItemAttachCount(int itemID, int count, bool force);	// 0x778560
};

class OpU5_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);		// NOTE: placeholder name (0x8758d0)
};

class CLogMsgs
{
public:
	void scrollToEnd();					// 0x7b4f10
};

class CMap	// NOTE: partial (object at 0xcec054)
{
public:
	void unknown49abf0();				// NOTE: placeholder name (0x49abf0, Panel::unknown49abf0 in the csv)
	void unknown49adc0(int value);		// NOTE: placeholder name (0x49adc0, MapView::unknown49adc0 in the csv)
};

class CPart
{
public:
	void drawStatus(bool damaged);		// NOTE: placeholder name (0x4a8e70)
	void unknown4a8f90(bool flag);		// NOTE: placeholder name (0x4a8f90)
	void delegate4a9120();				// NOTE: placeholder name (0x4a9120, Calls_4a9120::delegate in the csv)
};

class CParts	// NOTE: partial (object at 0xcec088)
{
public:
	CPart *unknown894e70(HItem item);	// NOTE: placeholder name (0x894e70)
	void unknown896820(HItem item);		// NOTE: placeholder name (0x896820)
	void unknown8987b0(HItem item, vector<unsigned int> *out);	// NOTE: placeholder name (0x8987b0)
	void unknown898860(HItem item, vector<unsigned int> *list);	// NOTE: placeholder name (0x898860)
	void unknown8993e0(CPart *part, bool flag);	// NOTE: placeholder name (0x8993e0)
	bool isLinked4a9b10(HItem item);	// NOTE: placeholder name (0x4a9b10)
	void unknown89d610(HItem item, int type);	// NOTE: placeholder name (0x89d610)
};

template <class T>
class WeightedList	// NOTE: placeholder name (OpR5h_WL<int> in the csv)
{
public:
	vector<T> values;	// +0x0
	vector<int> weights;	// +0x10
	int total;	// +0x20

	WeightedList();	// 0x9bab50
	~WeightedList();	// 0x700dd0
	void add(T value, int weight);	// 0x9ba310
	T &pick();	// 0x9ba470
	void remove(T value);	// 0x9bab80
};

// free helpers (csv names)
bool findItemType(vector<ItemType *> &v, const string &name, ItemType **out);	// NOTE: placeholder name (0x9d7a40)
bool unknown5111e0(int id, const string &text, const string *b, const string *c, HEntity d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0): log message, true = also flash
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name (0x4541b0): play sound
int OpX5_maxInt(int a, int b);	// 0x9cdb60
int OpX5_minInt(int a, int b);	// 0x9cdb30
string intToString(int value);	// 0x4051f0
string OpY1_intToStringSigned(int value);	// 0x405560
string floatToString(float value, int unknown1, int unknown2);	// NOTE: placeholder name (0x405760)
string OpY1_floatToStringSigned(float value, int unknown1, int unknown2);	// 0x4059d0
float opr1c_getFloatByIndex(int index);	// 0x4343a0
float fabs_4012b0(float v);	// NOTE: placeholder name (0x4012b0, fabs)
void logError(string location, string message);	// 0x404f10
void opw1_split(const string &text, char separator, vector<string> &out);	// NOTE: placeholder name (0x408700)
void opu4_shuffle(vector<int> &v);	// NOTE: placeholder name (0x9d8f80, OpS8c_shuffle<int>)
template <class T> void opr4c_eraseRange(vector<T> &v, int first, int last);	// NOTE: placeholder name (0x9e25a0)
template <class T> int OpQ5_randomIndex(vector<T> &v);	// NOTE: placeholder name (0x9d9b20)
template <class T> T randomElement(vector<T> &v);	// NOTE: placeholder name (0x9d5d00, OpU8a_randomRec)
template <class T> T randomRecord(vector<T> &v);	// NOTE: placeholder name (0x9dafb0, OpX5_randomRecord)
int OpT8b_Fn9d99a0(vector<int> &v);	// NOTE: placeholder name (0x9d99a0): sum of the parts' ratings
int OpT8b_Fn9d9ab0(vector<float> &v);	// NOTE: placeholder name (0x9d9ab0)
int OpT8b_Fn9d7d70(vector<float> &v);	// NOTE: placeholder name (0x9d7d70)
int OpS8b_Fn9d4500(vector<int> &v);	// NOTE: placeholder name (0x9d4500): index of the largest value
int OpS8c_indexOfMinInt(vector<int> &v);	// NOTE: placeholder name (0x9d9270)
bool OpS8b_Fn9d51d0(vector<int> &v, int value);	// NOTE: placeholder name (0x9d51d0): remove value
void OpT8a_eraseAt(vector<int> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0): erase v[i], i--
template <class T> void opq3_eraseStepBack(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440)
template <class T> void OpR1F_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9cfab0)
string OpU8a_randomString(vector<string> &v);	// NOTE: placeholder name (0x9d3280)

// scrap engine helpers next to this function (src/op/op_r2_f.cpp, src/game/team_d_31.cpp)
void OpR2_unknown603550(vector<int> &ids, vector<int> &sorted);	// NOTE: placeholder name: sort by rating
void OpR2_unknown603660(vector<int> &ids, ItemType *type);	// NOTE: placeholder name: pick the propulsion type
void OpR2_unknown6037d0(vector<int> &ids, ItemType *type);	// NOTE: placeholder name
void OpR2_unknown6038e0(vector<int> &ids, ItemType *type, bool flag);	// NOTE: placeholder name
bool OpR2_unknown603c00(vector<int> &ids, ItemType *type, bool flag);	// NOTE: placeholder name: pick the weapon type
void OpD_inheritPartTraits_6040d0(vector<int> &sources, ItemType *type, bool flag);	// NOTE: placeholder name
void unknown604c20(vector<int> &ids, ItemType *type);	// NOTE: placeholder name (0x604c20)

//==================================================================
// globals
//==================================================================

extern Map						*world;					// 0xcefc4c
extern Array2D<Cell *>			cells;					// NOTE: placeholder name (0xcfd44c, the map's cells)
extern RNG						rng;					// 0xd30908
extern PlayerData				playerData;				// NOTE: placeholder name (0xcf45d8)
extern GM						gm;						// NOTE: placeholder name (0xd25628)
extern OpR1h_Stats				stats;					// NOTE: placeholder name (0xd2c658)
extern OpW5_RolledValues		*rolledValues;			// NOTE: placeholder name (0xcefb48)
extern OpU5_MsgConsole			*msgConsole;			// NOTE: placeholder name (0xcec058)
extern CLogMsgs					*logMsgs;				// NOTE: placeholder name (0xcec0b4)
extern CMap						*cmap;					// NOTE: placeholder name (0xcec054)
extern CParts					*parts;					// NOTE: placeholder name (0xcec088)
extern vector<ItemType *>		itemTypes;				// NOTE: placeholder name (0xd2d1c4)
extern vector<vector<int> >		scrapLists;				// NOTE: placeholder name (0xcf4a58): consumed item type IDs per slot
extern vector<int>				scrapBuiltItems;		// NOTE: placeholder name (0xcf47cc)
extern int						noItemType;				// NOTE: placeholder name (0xcaf164, -1)
extern int						scrapEngineTurn;		// NOTE: placeholder name (0xcf4a68)
extern int						scrapEngineNextTurn;	// NOTE: placeholder name (0xcf4a6c)
extern bool						scrapDebug;				// NOTE: placeholder name (0xcefb24): forces weapon constructs/upgrades
extern Point					scrapArmDelay;			// NOTE: placeholder name (0xd01b40)
extern Point					scrapRepairDelay;		// NOTE: placeholder name (0xd1e04c)
extern Point					scrapBuildDelay;		// NOTE: placeholder name (0xd31724)
extern Point					scrapUpgradeDelay;		// NOTE: placeholder name (0xcfbed0)
extern int						scrapExpandChance[][9];	// NOTE: placeholder name (0xba3b48, [slot][size])
extern Point					scrapBuildIDs[];		// NOTE: placeholder name (0xd2c3b8, per slot): .y = minimum, random count kept
extern Point					scrapUpgradeIDs[];		// NOTE: placeholder name (0xcf45b0, per slot)
extern Point					scrapUpgradeCount[];	// NOTE: placeholder name (0xd35890, per slot): number of stats changed
extern int						scrapMaxConstructs[];	// NOTE: placeholder name (0xba3be8, per slot)
extern int						scrapWeaponChance;		// NOTE: placeholder name (0xba3bf4)
extern int						scrapMinRating[];		// NOTE: placeholder name (0xba3c08, per slot)
extern int						scrapUpgradeMinRating[];	// NOTE: placeholder name (0xba3c18, per slot)
extern int						scrapStatChance[];		// NOTE: placeholder name (0xba3d78, per stat): chance that a part after the first counts
extern int						scrapStatWeights[];		// NOTE: placeholder name (0xba3df8, [stat][slot]: 4 ints per stat)
extern int						scrapStatKind[];		// NOTE: placeholder name (0xba3ff8, per stat)
extern int						scrapStatMode[];		// NOTE: placeholder name (0xba4078, per stat)
extern bool						scrapStatPerSlot[];		// NOTE: placeholder name (0xba40f8, per stat): stat scales with size
extern int						scrapStatBonus[];		// NOTE: placeholder name (0xba4118, per stat)
extern int						scrapStatMinChange[];	// NOTE: placeholder name (0xba4198, per stat)
extern bool						scrapCriticalAllowed[];	// NOTE: placeholder name (0xba4378, [critical * 10 + damageType])
extern Point					scrapStatRanges[];		// NOTE: placeholder name (0xcf3a30, per stat)
extern Point					scrapBuffRanges[];		// NOTE: placeholder name (0xd33ad8, per stat)
extern Point					scrapNerfRanges[];		// NOTE: placeholder name (0xd20518, per stat)
extern string					scrapPropulsionNames[];	// NOTE: placeholder name (0xcfe678, per propulsion type 9..13)
extern string					criticalNames[];		// NOTE: placeholder name (0xd1e058, gameStrings_d1e058 in takeDamage)
extern string					scrapStat30Names[];		// NOTE: placeholder name (0xd31b68, names for ItemType::unknown154)
extern string					scrapStatNames[];		// NOTE: placeholder name (0xd3bb78, per stat)

//==================================================================
// macros
//==================================================================

// message to the log: flash the message console when asked to, then scroll the log
#define SCRAP_MESSAGE(id, text, b, c, owner)	\
	do	\
	{	\
		if (unknown5111e0(id,text,b,c,owner,HProp(),0,0))	\
			msgConsole->unknown8758d0(true);	\
		logMsgs->scrollToEnd();	\
	} while (0)

// average one integer stat over the consumed parts: parts after the first only count with a per-stat chance,
// per-slot stats are divided by the part's size, the remainder rounds up at random, then clamp to the stat's range
#define SCRAP_AVERAGE_VALUE(stat, index, value)	\
	total = count = 0;	\
	for (unsigned int i = 0; i < ids.size(); i++)	\
	{	\
		if (i == 0 || rng.chance(scrapStatChance[index]))	\
		{	\
			total += value / (scrapStatPerSlot[index] ? itemTypes[ids[i]]->size : 1);	\
			count++;	\
		}	\
	}	\
	newType->stat = total / count;	\
	if (total % count != 0 && rng.chance(total % count * 100 / count))	\
		newType->stat++;	\
	newType->stat = scrapStatRanges[index].clamp_40c270(newType->stat)

#define SCRAP_AVERAGE(stat, index)	SCRAP_AVERAGE_VALUE(stat,index,itemTypes[ids[i]]->stat)

// same for a float stat: average, +-0.25 at random, rounded down to a multiple of 0.5, not negative
#define SCRAP_AVERAGE_FLOAT(stat, index)	\
	ftotal = count = 0;	\
	for (unsigned int i = 0; i < ids.size(); i++)	\
	{	\
		if (i == 0 || rng.chance(scrapStatChance[index]))	\
		{	\
			ftotal += itemTypes[ids[i]]->stat / (scrapStatPerSlot[index] ? (float)itemTypes[ids[i]]->size : 1.0f);	\
			count++;	\
		}	\
	}	\
	newType->stat = ftotal / count;	\
	newType->stat += rng.rangeFloat(-0.25f,0.25f);	\
	newType->stat = (int)(newType->stat / 0.5) * 0.5;	\
	if (newType->stat < 0.0)	\
		newType->stat = 0

// upgrades: halve the sum of the old value and the source part's value, rounding an odd sum up at random
#define SCRAP_HALVE(value, result)	\
	*value = result / 2;	\
	if (result % 2 != 0 && rng.chance(result % 2 * 100 / 2))	\
		(*value)++

// float upgrades: +-0.25 at random, rounded down to a multiple of 0.5
#define SCRAP_JITTER_FLOAT(value)	\
	*value += rng.rangeFloat(-0.25f,0.25f);	\
	*value = (int)(*value / 0.5) * 0.5

// float upgrades: rounded down to a multiple of 0.5, not negative
#define SCRAP_CLAMP_FLOAT(value)	\
	*value = (int)(*value / 0.5) * 0.5;	\
	if (*value < 0.0)	\
		*value = 0

//==================================================================
// Entity::checkEffectScrapEngine
//==================================================================

void Entity::checkEffectScrapEngine(HItem engine)
{
	if (world->getTurn() < scrapEngineTurn + 30 || world->getTurn() < scrapEngineNextTurn)
		return;

	// Scrap Engine: arm it with the utility parts it consumed
	if (playerData.unknown46df10() && engine->unknown457860() == "Scrap Engine")
	{
		for (unsigned int i = 0; i < scrapLists[2].size(); i++)
		{
			ItemType *armType;
			if (findItemType(itemTypes,string("Arm. Scrap Engine"),&armType))
			{
				SCRAP_MESSAGE(0x11b,engine->getName(0,0),0,0,HEntity());
				playerData.unknown77fbc0(0x83);
				int integrity = (engine->unknown9b6bf0() == engine->unknown457c80()) ? 100 : engine->unknown457ca0();
				bool active = engine->unknown457cf0();
				bool overloaded = engine->unknown458220();
				vector<unsigned int> links;
				parts->unknown8987b0(engine,&links);
				engine->unknown57dbe0(1,0,0,1);
				HItem arm = world->unknown6c51d0(armType,self,true,false);
				if (arm.isValid())
				{
					if (integrity < 100)
						arm->unknown450460(OpX5_maxInt(1,arm->unknown457c80() * integrity / 100));
					scrapBuiltItems.push_back(arm->unknown9fcd80());
					gm.addItemAttachCount(arm->unknown457820(),1,false);
					CPart *part = parts->unknown894e70(arm);
					if (part != NULL)
					{
						if (active)
							parts->unknown8993e0(part,true);
						if (overloaded)
							parts->unknown8993e0(part,true);
						parts->unknown89d610(arm,10);
						if (integrity < 100)
							part->drawStatus(false);
						if (!links.empty())
							parts->unknown898860(arm,&links);
					}
					opR1d_4541b0(0xf5,0,0);
				}
			}
			scrapLists[2].clear();
			cmap->unknown49abf0();
			scrapEngineNextTurn = world->getTurn() + scrapArmDelay.randomInRange_40c130();
			return;
		}
	}

	// Arm. Scrap Engine: repair itself with the utility parts it consumed
	if (playerData.unknown46df10() && engine->unknown457860() == "Arm. Scrap Engine" && engine->unknown9b6bf0() < engine->unknown457c80())
	{
		unsigned int consumed = scrapLists[2].size();
		if (consumed != 0)
		{
			scrapLists[2].clear();
			cmap->unknown49abf0();
			int percent = consumed * 20;
			int amount = OpX5_minInt(engine->unknown457c80() * percent / 100,engine->unknown457c80() - engine->unknown9b6bf0());
			SCRAP_MESSAGE(0x11c,engine->getName(0,0),&intToString(amount),0,HEntity());
			stats.add4729d0(0x178,amount,"",-1);
			engine->unknown458360(amount);
			CPart *part = parts->unknown894e70(engine);
			if (part != NULL)
			{
				part->drawStatus(false);
				part->unknown4a8f90(true);
			}
			opR1d_4541b0(0xf6,0,0);
			scrapEngineNextTurn = world->getTurn() + scrapRepairDelay.randomInRange_40c130();
			return;
		}
	}

	// constructs already attached
	vector<HItem> constructs;
	int constructSize = -1;
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i]->getType() <= 3 && items[i]->unknown9b4350()->scrappable)
		{
			constructs.push_back(items[i]);
			constructSize += items[i]->unknown4578c0();
		}
	}
	if (constructSize + 1 == 15)
		playerData.unknown77fbc0(0x149);

	if (playerData.unknown46df10())
	{
		vector<int> slotCounts;
		unknown5c93d0(&slotCounts);
		vector<int> slots;
		slots.push_back(0);
		slots.push_back(1);
		slots.push_back(3);
		opu4_shuffle(slots);
		for (unsigned int s = 0; s < slots.size(); s++)
		{
			int slot = slots[s];
			if (slot == 1)
			{
				if (unknown5cad50() != 0)
					continue;
				int hasLegs = 0;
				for (unsigned int i = 0; i < items.size(); i++)
				{
					if (items[i]->unknown458220() && (items[i]->unknown457880() == 12 || items[i]->unknown457880() == 13))
					{
						hasLegs = 1;
						break;
					}
				}
				if (hasLegs != 0)
					continue;
			}

			// build a new construct from the parts consumed for this slot
			if (slotCounts[slot] != 0 && rng.chance(100))
			{
				int count = 0;
				for (unsigned int i = 0; i < constructs.size(); i++)
				{
					if (constructs[i]->unknown4578a0() == slot)
						count++;
				}
				if (scrapMaxConstructs[slot] == count)
					goto tryUpgrade;
				if (slot == 3 && (rng.chance(100 / scrapWeaponChance * count) || scrapDebug))
					goto tryUpgrade;
				vector<int> ids(scrapLists[slot]);
				if (ids.size() >= (unsigned int)scrapBuildIDs[slot].y)
				{
					opu4_shuffle(ids);
					unsigned int keep = scrapBuildIDs[slot].randomInRange_40c130();
					if (keep < ids.size())
						opr4c_eraseRange(ids,keep,ids.size() - 1);
					if ((unsigned int)OpT8b_Fn9d99a0(ids) < (unsigned int)scrapMinRating[slot])
						goto tryUpgrade;
					ItemType *newType = NULL;
					for (unsigned int i = 0; i < itemTypes.size(); i++)
					{
						if (itemTypes[i]->scrappable && itemTypes[i]->slot == slot)
						{
							for (unsigned int j = 0; j < constructs.size(); j++)
							{
								if (constructs[j]->unknown457820() == i)
									goto nextType;
							}
							newType = itemTypes[i];
						}
					nextType:;
					}
					if (newType != NULL)
					{
						switch (slot)
						{
						case 0:
							{
								newType->size = 1;
								int total = 0;
								for (unsigned int i = 0; i < ids.size(); i++)
									total += itemTypes[ids[i]]->rating;
								newType->rating = total / ids.size();
								int count = 0;
								SCRAP_AVERAGE(unknownA4,0);
								SCRAP_AVERAGE(maxIntegrity,1);
								SCRAP_AVERAGE(unknownAC,2);
								SCRAP_AVERAGE(unknownB0,3);
								SCRAP_AVERAGE(unknownB8,5);
								SCRAP_AVERAGE(unknownBC,6);
								SCRAP_AVERAGE(unknownC0,7);
								SCRAP_AVERAGE(unknownC8,8);
								vector<int> sorted;
								OpR2_unknown603550(ids,sorted);
								vector<string> names;
								for (unsigned int i = 0; i < sorted.size(); i++)
								{
									if (!itemTypes[sorted[i]]->nameParts.empty())
										names.push_back(OpU8a_randomString(itemTypes[sorted[i]]->nameParts));
								}
								if (names.empty())
									newType->name = "Power Construct";
								else
								{
									newType->unknown44 = itemTypes[sorted[0]]->unknown44;
									newType->unknown78 = itemTypes[sorted[0]]->unknown78;
									bool prefix = false;
									if (names.size() == 1)
									{
										newType->name = "Construct";
										prefix = true;
									}
									else if (names[0] == names[1])
										newType->name = "Multi-" + names[0];
									else
										newType->name = names[0] + "-" + names[1];
									switch (newType->unknown44)
									{
									case 6:
										if (prefix)
											newType->name.insert(0,"Engine ");
										else
											newType->name += " Engine";
										break;
									case 8:
										if (prefix)
											newType->name.insert(0,"Reactor ");
										else
											newType->name += " Reactor";
										break;
									default:
										if (prefix)
											newType->name.insert(0,"Core ");
										else
											newType->name += " Core";
										break;
									}
								}
								if (newType->unknownC8 != 0)
									newType->name.insert(0,"Cld. ");
								HItem construct = world->unknown6c51d0(newType,self,true,false);
								CPart *part = parts->unknown894e70(construct);
								if (unknown5dc440(construct) == 0)
									parts->unknown8993e0(part,false);
								opR1d_4541b0(0xf3,0,0);
								SCRAP_MESSAGE(0x121,engine->getName(0,0),&construct->getName(0,0),0,self);
								stats.add4729d0(0xcc,1,"",-1);
								if (rolledValues != NULL)
									rolledValues->say(0x20,false,"");
								for (unsigned int i = 0; i < ids.size(); i++)
									OpS8b_Fn9d51d0(scrapLists[slot],ids[i]);
								cmap->unknown49abf0();
								scrapEngineNextTurn = world->getTurn() + scrapBuildDelay.randomInRange_40c130();
								cmap->unknown49adc0(1000);
								return;
							}
						case 1:
							{
								newType->size = 1;
								int total = 0;
								for (unsigned int i = 0; i < ids.size(); i++)
									total += itemTypes[ids[i]]->rating;
								newType->rating = total / ids.size();
								OpR2_unknown603660(ids,newType);
								int count = 0;
								float ftotal;
								SCRAP_AVERAGE(maxIntegrity,1);
								SCRAP_AVERAGE(unknownAC,2);
								SCRAP_AVERAGE(unknownB0,3);
								SCRAP_AVERAGE_FLOAT(unknownB4,4);
								SCRAP_AVERAGE(unknownCC,9);
								OpR2_unknown6037d0(ids,newType);
								SCRAP_AVERAGE_FLOAT(unknownD8,10);
								SCRAP_AVERAGE(unknownDC,11);
								SCRAP_AVERAGE(unknownE0,12);
								SCRAP_AVERAGE(unknownE4,13);
								OpR2_unknown6038e0(ids,newType,false);
								vector<int> sorted;
								OpR2_unknown603550(ids,sorted);
								vector<string> names;
								for (unsigned int i = 0; i < sorted.size(); i++)
								{
									if (!itemTypes[sorted[i]]->nameParts.empty())
										names.push_back(OpU8a_randomString(itemTypes[sorted[i]]->nameParts));
								}
								newType->name = scrapPropulsionNames[newType->unknown44 - 9];
								if (newType->name.empty() && names.empty())
									newType->name += "Construct ";
								else if (names.size() == 1 || (names.size() == 2 && names[0] == names[1]))
									newType->name += names[0] + " ";
								else if (names.size() > 1)
									newType->name += names[0] + "-" + names[1] + " ";
								newType->name += "Exoskeleton";
								HItem construct = world->unknown6c51d0(newType,self,true,false);
								CPart *part = parts->unknown894e70(construct);
								if (unknown5dc440(construct) == 0)
									parts->unknown8993e0(part,false);
								opR1d_4541b0(0xf3,0,0);
								SCRAP_MESSAGE(0x121,engine->getName(0,0),&construct->getName(0,0),0,self);
								stats.add4729d0(0xcc,1,"",-1);
								if (rolledValues != NULL)
									rolledValues->say(0x20,false,"");
								for (unsigned int i = 0; i < ids.size(); i++)
									OpS8b_Fn9d51d0(scrapLists[slot],ids[i]);
								cmap->unknown49abf0();
								scrapEngineNextTurn = world->getTurn() + scrapBuildDelay.randomInRange_40c130();
								cmap->unknown49adc0(1000);
								return;
							}
						case 3:
							{
								newType->size = 1;
								int total = 0;
								for (unsigned int i = 0; i < ids.size(); i++)
									total += itemTypes[ids[i]]->rating;
								newType->rating = total / ids.size();
								OpR2_unknown603c00(ids,newType,false);
								int count = 0;
								SCRAP_AVERAGE(unknownA4,0);
								SCRAP_AVERAGE(maxIntegrity,1);
								SCRAP_AVERAGE(unknownAC,2);
								SCRAP_AVERAGE(unknown100,16);
								SCRAP_AVERAGE(unknown108,18);
								SCRAP_AVERAGE(unknown10C,19);
								SCRAP_AVERAGE(unknown110,20);
								SCRAP_AVERAGE(unknown114,21);
								SCRAP_AVERAGE(projectiles,22);
								// damage and critical chance are averaged over all projectiles, then split again
								SCRAP_AVERAGE_VALUE(damageMin,24,(float)(itemTypes[ids[i]]->damageMin * itemTypes[ids[i]]->projectiles));
								SCRAP_AVERAGE_VALUE(damageMax,25,(float)(itemTypes[ids[i]]->damageMax * itemTypes[ids[i]]->projectiles));
								if (newType->damageMax < newType->damageMin)
									newType->damageMax = newType->damageMin;
								if (newType->projectiles > 1)
								{
									newType->damageMin /= newType->projectiles;
									newType->damageMax /= newType->projectiles;
								}
								SCRAP_AVERAGE(unknown12C,26);
								SCRAP_AVERAGE(unknown130,27);
								SCRAP_AVERAGE_VALUE(criticalChance,28,(float)(itemTypes[ids[i]]->criticalChance * itemTypes[ids[i]]->projectiles));
								if (newType->criticalChance != 0)
								{
									vector<int> criticals;
									for (unsigned int i = 0; i < ids.size(); i++)
									{
										if (itemTypes[ids[i]]->damageType == newType->damageType && scrapCriticalAllowed[itemTypes[ids[i]]->critical * 10 + newType->damageType])
											criticals.push_back(itemTypes[ids[i]]->critical);
									}
									if (criticals.empty())
									{
										newType->criticalChance = 0;
										newType->critical = 0;
									}
									else
									{
										newType->criticalChance /= newType->projectiles;
										newType->critical = randomElement(criticals);
									}
								}
								else
								{
									newType->criticalChance = 0;
									newType->critical = 0;
								}
								SCRAP_AVERAGE(unknown14C,29);
								SCRAP_AVERAGE(unknown150,30);
								if (newType->unknown150 != 0)
									newType->unknown158 = 0;
								if (newType->unknown158 == 0 && newType->critical == 1)
								{
									newType->critical = 0;
									newType->criticalChance = 0;
								}
								// unknown154 comes from the part closest in stat 30
								int closest = noItemType;
								closest = ids[0];
								for (unsigned int i = 1; i < ids.size(); i++)
								{
									if (abs(itemTypes[ids[i]]->unknown150 - newType->unknown150) < abs(itemTypes[closest]->unknown150 - newType->unknown150))
										closest = ids[i];
								}
								newType->unknown154 = itemTypes[closest]->unknown154;
								OpD_inheritPartTraits_6040d0(ids,newType,false);
								vector<int> sorted;
								OpR2_unknown603550(ids,sorted);
								for (unsigned int i = 0; i < sorted.size(); i++)
								{
									if (itemTypes[sorted[i]]->damageType != newType->damageType)
										OpT8a_eraseAt(sorted,i);
								}
								unknown604c20(sorted,newType);
								HItem construct = world->unknown6c51d0(newType,self,true,false);
								CPart *part = parts->unknown894e70(construct);
								if (unknown5dc440(construct) == 0)
									parts->unknown8993e0(part,false);
								opR1d_4541b0(0xf3,0,0);
								SCRAP_MESSAGE(0x121,engine->getName(0,0),&construct->getName(0,0),0,self);
								stats.add4729d0(0xcc,1,"",-1);
								if (construct->unknown9b4350()->damageType == 7)
									playerData.unknown77fbc0(0x14a);
								if (rolledValues != NULL)
									rolledValues->say(0x20,false,"");
								for (unsigned int i = 0; i < ids.size(); i++)
									OpS8b_Fn9d51d0(scrapLists[slot],ids[i]);
								cmap->unknown49abf0();
								scrapEngineNextTurn = world->getTurn() + scrapBuildDelay.randomInRange_40c130();
								cmap->unknown49adc0(1000);
								return;
							}
						}
					}
				}
			}
		tryUpgrade:
			// upgrade an existing construct of this slot with the parts consumed for it
			if (rng.chance(7) || (scrapDebug && slot == 3))
			{
				vector<int> ids(scrapLists[slot]);
				if (ids.size() >= (unsigned int)scrapUpgradeIDs[slot].y)
				{
					opu4_shuffle(ids);
					unsigned int keep = scrapUpgradeIDs[slot].randomInRange_40c130();
					if (keep < ids.size())
						opr4c_eraseRange(ids,keep,ids.size() - 1);
					if ((unsigned int)OpT8b_Fn9d99a0(ids) < (unsigned int)scrapUpgradeMinRating[slot])
						continue;
					vector<HItem> applicable;
					for (unsigned int i = 0; i < constructs.size(); i++)
					{
						if (constructs[i]->unknown4578a0() == slot)
							applicable.push_back(constructs[i]);
					}
					if (!applicable.empty())
					{
						// usually prefer the lowest-rated constructs
						if (applicable.size() > 1 && rng.chance(66))
						{
							int lowestRating = applicable[0]->unknown457900();
							for (unsigned int i = 1; i < applicable.size(); i++)
							{
								if (applicable[i]->unknown457900() < lowestRating)
									lowestRating = applicable[i]->unknown457900();
							}
							for (unsigned int i = 0; i < applicable.size(); i++)
							{
								if (applicable[i]->unknown457900() > lowestRating)
									opq3_eraseStepBack(applicable,i);
							}
							if (applicable.empty())
							{
								logError("Entity::checkEffectScrapEngine()","applicableConstructPool completely empty");
								return;
							}
						}
						HItem target = randomRecord(applicable);
						ItemType *type = target->unknown9b4350();
						bool active = target->unknown457cf0();
						bool overloaded = target->unknown458220();
						int partType = type->unknown44;
						vector<string> log;
						int buffChance = 35;
						for (unsigned int i = 0; i < ids.size(); i++)
						{
							if (itemTypes[ids[i]]->unknown94 != 0 || itemTypes[ids[i]]->rating > target->unknown457900())
								buffChance += 15;
						}
						log.push_back("buffChance=" + intToString(buffChance) + "%");
						WeightedList<int> statPool;
						for (int i = 0; i < 32; i++)
							statPool.add(i,scrapStatWeights[i * 4 + slot]);
						vector<string> changes;
						vector<int> upgraded;
						vector<int> buffed;
						for (int n = scrapUpgradeCount[slot].randomInRange_40c130(); n != 0; n--)
						{
							int stat = statPool.pick();
							statPool.remove(stat);
							bool buff = rng.chance(buffChance);
							int mode = scrapStatMode[stat];
							log.push_back("#" + intToString(n) + ": ");
							switch (scrapStatKind[stat])
							{
							case 0:	// integer stat
								{
									vector<int> values;
									for (unsigned int i = 0; i < ids.size(); i++)
										values.push_back(*itemTypes[ids[i]]->getStatPtr(stat));
									int *value = type->getStatPtr(stat);
									int oldValue = *value;
									int index = -1;
									int result;
									switch (mode)
									{
									case 0:	// higher is better
										if (buff)
										{
											log.back() += intToString(*value) + "[buff]->";
											if (stat == 24 || stat == 25 || stat == 28)
											{
												// damage and critical chance: work on the total over all projectiles
												*value = (int)(type->projectiles * (stat == 28 ? 1.0f : opr1c_getFloatByIndex(type->projectiles)) * *value);
												index = OpS8b_Fn9d4500(values);
												float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
												result = (int)(itemTypes[ids[index]]->projectiles * (stat == 28 ? 1.0f : opr1c_getFloatByIndex(itemTypes[ids[index]]->projectiles)) * scale * values[index] + *value);
												SCRAP_HALVE(value,result);
												*value = (rng.rangeInt(scrapBuffRanges[stat].x + 100,scrapBuffRanges[stat].y + 100) + constructSize * scrapStatBonus[stat]) * *value / 100;
												*value = *value / type->projectiles;
												*value = scrapStatRanges[stat].clamp_40c270(*value);
											}
											else
											{
												index = OpS8b_Fn9d4500(values);
												float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
												result = (int)(values[index] * scale + *value);
												SCRAP_HALVE(value,result);
												*value = (rng.rangeInt(scrapBuffRanges[stat].x + 100,scrapBuffRanges[stat].y + 100) + constructSize * scrapStatBonus[stat]) * *value / 100;
												*value = scrapStatRanges[stat].clamp_40c270(*value);
											}
											log.back() += intToString(*value);
										}
										else
										{
											log.back() += intToString(*value) + "->";
											if (stat == 24 || stat == 25 || stat == 28)
											{
												*value = (int)(type->projectiles * (stat == 28 ? 1.0f : opr1c_getFloatByIndex(type->projectiles)) * *value);
												index = OpQ5_randomIndex(values);
												float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
												result = (int)(itemTypes[ids[index]]->projectiles * (stat == 28 ? 1.0f : opr1c_getFloatByIndex(itemTypes[ids[index]]->projectiles)) * scale * values[index] + *value);
												SCRAP_HALVE(value,result);
												*value = OpX5_minInt(100,rng.rangeInt(100 - scrapNerfRanges[stat].y,100 - scrapNerfRanges[stat].x) + constructSize * scrapStatBonus[stat]) * *value / 100;
												*value = *value / type->projectiles;
												*value = scrapStatRanges[stat].clamp_40c270(*value);
											}
											else
											{
												index = OpQ5_randomIndex(values);
												float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
												result = (int)(values[index] * scale + *value);
												SCRAP_HALVE(value,result);
												*value = OpX5_minInt(100,rng.rangeInt(100 - scrapNerfRanges[stat].y,100 - scrapNerfRanges[stat].x) + constructSize * scrapStatBonus[stat]) * *value / 100;
												*value = scrapStatRanges[stat].clamp_40c270(*value);
											}
											log.back() += intToString(*value);
										}
										break;
									case 1:	// lower is better
										if (buff)
										{
											log.back() += intToString(*value) + "[buff]->";
											index = OpS8c_indexOfMinInt(values);
											float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
											result = (int)(values[index] * scale + *value);
											SCRAP_HALVE(value,result);
											*value = OpX5_maxInt(0,rng.rangeInt(100 - scrapBuffRanges[stat].y,100 - scrapBuffRanges[stat].x) - constructSize * scrapStatBonus[stat]) * *value / 100;
											*value = scrapStatRanges[stat].clamp_40c270(*value);
											log.back() += intToString(*value);
										}
										else
										{
											log.back() += intToString(*value) + "->";
											index = OpQ5_randomIndex(values);
											float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
											result = (int)(values[index] * scale + *value);
											SCRAP_HALVE(value,result);
											*value = (rng.rangeInt(scrapNerfRanges[stat].x + 100,scrapNerfRanges[stat].y + 100) + constructSize * scrapStatBonus[stat]) * *value / 100;
											*value = scrapStatRanges[stat].clamp_40c270(*value);
											log.back() += intToString(*value);
										}
										break;
									case 2:	// neither: wider random range
										{
											log.back() += intToString(*value) + "[special]->";
											index = OpQ5_randomIndex(values);
											float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
											result = (int)(values[index] * scale + *value);
											SCRAP_HALVE(value,result);
											*value = rng.rangeInt(100 - scrapBuffRanges[stat].y,scrapNerfRanges[stat].y + 100) * *value / 100;
											*value = scrapStatRanges[stat].clamp_40c270(*value);
											log.back() += intToString(*value);
										}
										break;
									}
									log.back() += " " + scrapStatNames[stat];
									if (abs(*value - oldValue) < scrapStatMinChange[stat])
									{
										*value = oldValue;
										log.back() += " (cancelled)";
									}
									else if (*value != oldValue)
									{
										log.back() += " {" + itemTypes[ids[index]]->internalName + "}";
										upgraded.push_back(ids[index]);
										if (buff)
											buffed.push_back(upgraded.back());
										changes.push_back(scrapStatNames[stat]);
										changes.back() += " " + OpY1_intToStringSigned(*value - oldValue);
										switch (stat)
										{
										case 1:	// max integrity: keep the same damage, cap integrity
											if (target->unknown457c80() > oldValue)
												target->unknown458360(target->unknown457c80() - oldValue);
											if (target->unknown9b6bf0() > target->unknown457c80())
												target->unknown450460(target->unknown457c80());
											break;
										case 7:
											unknown5e2b50();
											break;
										case 22:	// projectiles: rescale the per-projectile values
											{
												float oldMultiplier = opr1c_getFloatByIndex(oldValue);
												float newMultiplier = opr1c_getFloatByIndex(type->projectiles);
												type->damageMin = (int)((float)type->damageMin * oldValue / oldMultiplier * newMultiplier / type->projectiles);
												type->damageMax = (int)((float)type->damageMax * oldValue / oldMultiplier * newMultiplier / type->projectiles);
												type->criticalChance = (int)((float)type->criticalChance * oldValue / type->projectiles);
											}
											break;
										case 24:
											if (type->damageMin > type->damageMax)
												type->damageMax = type->damageMin;
											break;
										case 25:
											if (type->damageMin > type->damageMax)
												type->damageMin = type->damageMax;
											break;
										case 28:	// critical chance: maybe take over the source part's critical
											if (!scrapCriticalAllowed[type->critical * 10 + type->damageType])
												type->critical = 0;
											if (itemTypes[upgraded.back()]->critical != 0 && itemTypes[upgraded.back()]->critical != type->critical &&
												scrapCriticalAllowed[itemTypes[upgraded.back()]->critical * 10 + itemTypes[upgraded.back()]->damageType])
											{
												type->critical = itemTypes[upgraded.back()]->critical;
												changes.back() += "/" + criticalNames[type->critical];
											}
											if (type->criticalChance == 0)
												type->critical = 0;
											else if (type->critical == 0)
												type->criticalChance = 0;
											break;
										case 30:
											if (itemTypes[upgraded.back()]->unknown154 != 0 && itemTypes[upgraded.back()]->unknown154 != type->unknown154)
											{
												type->unknown154 = itemTypes[upgraded.back()]->unknown154;
												changes.back() += "/" + scrapStat30Names[type->unknown154];
											}
											if (type->unknown150 == 0)
												type->unknown154 = 0;
											else if (type->unknown158 != 0)
												type->unknown158 = 0;
											break;
										}
									}
								}
								break;
							case 1:	// float stat
								{
									vector<float> values;
									for (unsigned int i = 0; i < ids.size(); i++)
										values.push_back(*(float *)itemTypes[ids[i]]->getStatPtr(stat));
									float *value = (float *)type->getStatPtr(stat);
									float oldValue = *value;
									int index = -1;
									float result;
									switch (mode)
									{
									case 0:
										if (buff)
										{
											log.back() += floatToString(*value,0,1) + "[buff]->";
											index = OpT8b_Fn9d9ab0(values);
											float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
											result = values[index] * scale + *value;
											*value = result / 2.0;
											SCRAP_JITTER_FLOAT(value);
											*value = (rng.rangeInt(scrapBuffRanges[stat].x + 100,scrapBuffRanges[stat].y + 100) + constructSize * scrapStatBonus[stat]) * *value / 100.0;
											SCRAP_CLAMP_FLOAT(value);
											log.back() += floatToString(*value,0,1);
										}
										else
										{
											log.back() += floatToString(*value,0,1) + "->";
											index = OpQ5_randomIndex(values);
											float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
											result = values[index] * scale + *value;
											*value = result / 2.0;
											SCRAP_JITTER_FLOAT(value);
											*value = OpX5_minInt(100,rng.rangeInt(100 - scrapNerfRanges[stat].y,100 - scrapNerfRanges[stat].x) + constructSize * scrapStatBonus[stat]) * *value / 100.0;
											SCRAP_CLAMP_FLOAT(value);
											log.back() += floatToString(*value,0,1);
										}
										break;
									case 1:
										if (buff)
										{
											log.back() += floatToString(*value,0,1) + "[buff]->";
											index = OpT8b_Fn9d7d70(values);
											float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
											result = values[index] * scale + *value;
											*value = result / 2.0;
											SCRAP_JITTER_FLOAT(value);
											*value = OpX5_maxInt(0,rng.rangeInt(100 - scrapBuffRanges[stat].y,100 - scrapBuffRanges[stat].x) - constructSize * scrapStatBonus[stat]) * *value / 100.0;
											SCRAP_CLAMP_FLOAT(value);
											log.back() += floatToString(*value,0,1);
										}
										else
										{
											log.back() += floatToString(*value,0,1) + "->";
											index = OpQ5_randomIndex(values);
											float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
											result = values[index] * scale + *value;
											*value = result / 2.0;
											SCRAP_JITTER_FLOAT(value);
											*value = (rng.rangeInt(scrapNerfRanges[stat].x + 100,scrapNerfRanges[stat].y + 100) + constructSize * scrapStatBonus[stat]) * *value / 100.0;
											SCRAP_CLAMP_FLOAT(value);
											log.back() += floatToString(*value,0,1);
										}
										break;
									case 2:
										{
											log.back() += floatToString(*value,0,1) + "[special]->";
											index = OpQ5_randomIndex(values);
											float scale = scrapStatPerSlot[stat] ? (float)type->size / itemTypes[ids[index]]->size : 1.0;
											result = values[index] * scale + *value;
											*value = result / 2.0;
											SCRAP_JITTER_FLOAT(value);
											*value = rng.rangeInt(100 - scrapBuffRanges[stat].y,scrapNerfRanges[stat].y + 100) * *value / 100.0;
											SCRAP_CLAMP_FLOAT(value);
											log.back() += floatToString(*value,0,1);
										}
										break;
									}
									log.back() += " " + scrapStatNames[stat];
									if (fabs_4012b0(*value - oldValue) < scrapStatMinChange[stat])
									{
										*value = oldValue;
										log.back() += " (cancelled)";
									}
									else if (*value != oldValue)
									{
										log.back() += " {" + itemTypes[ids[index]]->internalName + "}";
										upgraded.push_back(ids[index]);
										if (buff)
											buffed.push_back(upgraded.back());
										changes.push_back(scrapStatNames[stat]);
										changes.back() += " " + OpY1_floatToStringSigned(*value - oldValue,0,1);
									}
								}
								break;
							}
						}
						if (!upgraded.empty())
						{
							// sometimes the construct also grows by one slot (removing a smaller construct when the slot is full)
							bool expanded = false;
							if ((slotCounts[slot] != 0 || slot == 3) && (rng.chance(scrapExpandChance[slot][type->size]) || (scrapDebug && slot == 3)))
							{
								bool noRoom = false;
								if (slotCounts[slot] == 0)
								{
									vector<HItem> removable;
									for (unsigned int i = 0; i < applicable.size(); i++)
									{
										if (applicable[i]->unknown4578c0() == 1 && applicable[i]->unknown457900() < type->rating && !parts->isLinked4a9b10(applicable[i]))
											removable.push_back(applicable[i]);
									}
									if (!removable.empty())
										randomRecord(removable)->unknown57dbe0(1,0,0,0);
									else
										noRoom = true;
								}
								if (!noRoom)
								{
									int oldSize = type->size;
									type->size++;
									float factor = (float)type->size / oldSize;
									for (int i = 0; i < 32; i++)
									{
										if (scrapStatWeights[i * 4 + slot] != 0 && scrapStatPerSlot[i])
										{
											switch (scrapStatKind[i])
											{
											case 0:
												*type->getStatPtr(i) *= factor;
												if (i == 1)
													target->unknown458360(target->unknown9b6bf0() * factor);
												break;
											case 1:
												{
													float *value = (float *)type->getStatPtr(i);
													*value *= factor;
													*value = (int)(*value / 0.5) * 0.5;
												}
												break;
											}
										}
									}
									if (slot == 1 && type->unknown44 != 12 && type->unknown44 != 13)
										type->unknownD4 *= factor;
									// reattach the construct through an empty cell so it takes the new size
									Point tempLoc(-1);
									for (int x = 0; x < cells.getWidth(); x++)
									{
										for (int y = 0; y < cells.getHeight(); y++)
										{
											if ((*cells.at(x,y))->getItem().isNull())
											{
												tempLoc.set(x,y);
												break;
											}
										}
									}
									if (tempLoc.x == -1)
										logError("BS::checkEffectScrapEngine()","unable to find tempLoc");
									else
									{
										target->unknown57a0f0(&tempLoc,0,1);
										target->unknown57a190(world->getPlayer(),slot,1,0);
										expanded = true;
									}
								}
							}

							// type-specific traits
							if (slot == 3)
							{
								int oldDamageType = type->damageType;
								vector<int> oldPenetration(type->penetration);
								if (OpR2_unknown603c00(upgraded,type,true) && !scrapCriticalAllowed[type->critical * 10 + type->damageType])
								{
									type->criticalChance = 0;
									type->critical = 0;
									for (unsigned int i = 0; i < changes.size(); i++)
									{
										if (changes[i].find(scrapStatNames[28],0) != string::npos)
										{
											changes[i] = "-Critical";
											break;
										}
									}
								}
								if (type->unknown158 == 0 && type->critical == 1)
								{
									type->critical = 0;
									type->criticalChance = 0;
								}
								if (type->penetration.empty() != oldPenetration.empty())
								{
									changes.push_back(string(oldPenetration.empty() ? "+" : "-"));
									changes.back() += "Penetration";
								}
								int old104 = type->unknown104;
								int old11C = type->unknown11C;
								int old15C = type->unknown15C;
								OpD_inheritPartTraits_6040d0(upgraded,type,true);
								if (type->unknown104 != old104)
								{
									changes.push_back(scrapStatNames[17]);
									changes.back() += " " + OpY1_intToStringSigned(type->unknown104 - old104);
								}
								if (type->unknown11C != old11C)
								{
									changes.push_back(scrapStatNames[23]);
									changes.back() += " " + OpY1_intToStringSigned(type->unknown11C - old11C);
								}
								if (type->unknown15C != old15C)
								{
									changes.push_back(scrapStatNames[31]);
									changes.back() += " " + OpY1_intToStringSigned(type->unknown15C - old15C);
								}
							}
							else if (slot == 1)
							{
								if (!buffed.empty())
								{
									OpR2_unknown603660(buffed,type);
									if (type->unknown44 != partType)
										OpR2_unknown6037d0(buffed,type);
								}
								int oldE8 = type->unknownE8;
								int oldEC = type->unknownEC;
								OpR2_unknown6038e0(upgraded,type,true);
								if (type->unknownE8 != oldE8)
								{
									changes.push_back(scrapStatNames[14]);
									changes.back() += " " + OpY1_intToStringSigned(type->unknownE8 - oldE8);
								}
								if (type->unknownEC != oldEC)
								{
									if (type->unknownEC == 0)
										changes.push_back("-" + scrapStatNames[15]);
									else
										changes.push_back("+" + scrapStatNames[15]);
								}
							}

							// log summary
							CPart *part = parts->unknown894e70(target);
							bool renamed = false;
							string summary(changes[0]);
							for (unsigned int i = 1; i < changes.size(); i++)
								summary += ", " + changes[i];
							if (expanded)
							{
								string slotList;
								vector<ScrapSlotEntry> slotEntries;
								target->unknown5759b0(&slotList,&slotEntries);
								summary += "\nExpanded to " + intToString(type->size) + " slots (" + slotList + ")";
							}
							int rating = 0;
							for (unsigned int i = 0; i < upgraded.size(); i++)
								rating += itemTypes[upgraded[i]]->rating;
							rating /= upgraded.size();
							type->rating = (rating + type->rating) / 2;

							// rename the construct from the parts that improved it
							if (slot == 3)
							{
								string oldName = target->getName(0,0);
								unknown604c20(buffed,type);
								if (target->getName(0,0) != oldName)
								{
									SCRAP_MESSAGE(0x123,oldName,&summary,&target->getName(0,0),self);
									if (part != NULL)
									{
										part->delegate4a9120();
										parts->unknown896820(target);
									}
									renamed = true;
								}
							}
							else if (!buffed.empty() && rng.chance(100))
							{
								switch (slot)
								{
								case 0:
									{
										string oldName = target->getName(0,0);
										vector<string> words;
										opw1_split(target->getName(0,0),' ',words);
										if (words.front() == "Cld.")
											OpR1F_eraseAt(words,0);
										words.pop_back();
										if (words[0] == "Construct")
											words.clear();
										vector<string> oldParts;
										for (unsigned int i = 0; i < words.size(); i++)
										{
											if (words[i].find('-',0) == string::npos)
												oldParts.push_back(words[i]);
											else
											{
												vector<string> pieces;
												opw1_split(words[i],'-',pieces);
												for (unsigned int j = 0; j < pieces.size(); j++)
												{
													if (pieces[j] != "Multi")
														oldParts.push_back(pieces[j]);
												}
											}
										}
										vector<int> sorted;
										if (!buffed.empty())
											OpR2_unknown603550(buffed,sorted);
										vector<string> names;
										for (unsigned int i = 0; i < sorted.size(); i++)
										{
											if (!itemTypes[sorted[i]]->nameParts.empty())
												names.push_back(OpU8a_randomString(itemTypes[sorted[i]]->nameParts));
										}
										if (!oldParts.empty())
										{
											if (names.empty())
												names = oldParts;
											else if (names.size() == 1)
												names.push_back(OpU8a_randomString(oldParts));
											else
												names[1] = OpU8a_randomString(oldParts);
										}
										if (names.empty())
											type->name = "Power Construct";
										else
										{
											type->unknown44 = itemTypes[sorted[0]]->unknown44;
											type->unknown78 = itemTypes[sorted[0]]->unknown78;
											bool prefix = false;
											if (names.size() == 1)
											{
												type->name = "Construct";
												prefix = true;
											}
											else if (names[0] == names[1])
												type->name = "Multi-" + names[0];
											else
												type->name = names[0] + "-" + names[1];
											switch (type->unknown44)
											{
											case 6:
												if (prefix)
													type->name.insert(0,"Engine ");
												else
													type->name += " Engine";
												break;
											case 8:
												if (prefix)
													type->name.insert(0,"Reactor ");
												else
													type->name += " Reactor";
												break;
											default:
												if (prefix)
													type->name.insert(0,"Core ");
												else
													type->name += " Core";
												break;
											}
										}
										if (type->unknownC8 != 0)
											type->name.insert(0,"Cld. ");
										if (target->getName(0,0) != oldName)
										{
											SCRAP_MESSAGE(0x123,oldName,&summary,&target->getName(0,0),self);
											if (part != NULL)
											{
												part->delegate4a9120();
												parts->unknown896820(target);
											}
											renamed = true;
										}
									}
									break;
								case 1:
									{
										string oldName = target->getName(0,0);
										vector<string> words;
										opw1_split(target->getName(0,0),' ',words);
										if (!scrapPropulsionNames[partType - 9].empty())
											words.erase(words.begin());
										words.pop_back();
										if (words[0] == "Construct")
											words.clear();
										vector<string> oldParts;
										for (unsigned int i = 0; i < words.size(); i++)
										{
											if (words[i].find('-',0) == string::npos)
												oldParts.push_back(words[i]);
											else
												opw1_split(words[i],'-',oldParts);
										}
										vector<int> sorted;
										if (!buffed.empty())
											OpR2_unknown603550(buffed,sorted);
										vector<string> names;
										for (unsigned int i = 0; i < sorted.size(); i++)
										{
											if (!itemTypes[sorted[i]]->nameParts.empty())
												names.push_back(OpU8a_randomString(itemTypes[sorted[i]]->nameParts));
										}
										if (!oldParts.empty())
										{
											if (names.empty())
												names = oldParts;
											else if (names.size() == 1)
												names.push_back(OpU8a_randomString(oldParts));
											else
												names[1] = OpU8a_randomString(oldParts);
										}
										type->name = scrapPropulsionNames[type->unknown44 - 9];
										if (type->name.empty() && names.empty())
											type->name += "Construct ";
										else if (names.size() == 1 || (names.size() >= 2 && names[0] == names[1]))
											type->name += names[0] + " ";
										else if (names.size() > 1)
											type->name += names[0] + "-" + names[1] + " ";
										type->name += "Exoskeleton";
										if (target->getName(0,0) != oldName)
										{
											SCRAP_MESSAGE(0x123,oldName,&summary,&target->getName(0,0),self);
											if (part != NULL)
											{
												part->delegate4a9120();
												parts->unknown896820(target);
											}
											renamed = true;
										}
									}
									break;
								}
							}
							if (!renamed)
								SCRAP_MESSAGE(0x122,target->getName(0,0),&summary,0,self);
							opR1d_4541b0(0xf4,0,0);
							stats.add4729d0(0xcd,1,"",-1);
							if (slot == 3)
							{
								if (expanded && target->unknown4578c0() >= 3)
									playerData.unknown77fbc0(0xd8);
								if (target->unknown9b4350()->damageType == 7)
									playerData.unknown77fbc0(0x14a);
							}
							cmap->unknown49adc0(1000);

							// integrity: never above the (possibly lower) maximum, and a partial repair
							if (target->unknown457c80() < target->unknown9b6bf0())
								target->unknown450460(target->unknown457c80() - 1);
							if (target->unknown9b6bf0() < target->unknown457c80())
							{
								int repair = OpX5_minInt(OpX5_maxInt(1,target->unknown457c80() * 35 / 100),target->unknown457c80() - target->unknown9b6bf0());
								stats.add4729d0(0x178,repair,"",-1);
								target->unknown458360(repair);
							}
							if (part != NULL)
							{
								part->drawStatus(false);
								part->unknown4a8f90(true);
							}

							// restore the activation state (a changed propulsion type may not be compatible)
							while (target->unknown457cf0())
								parts->unknown8993e0(part,false);
							if (slot != 1 || type->unknown44 == partType || !unknown5cd220(target))
							{
								if (active)
									parts->unknown8993e0(part,false);
								if (overloaded && target->unknown458180())
									parts->unknown8993e0(part,false);
								if (slot == 1 && type->unknown44 != partType && !target->unknown457cf0() && unknown5d1390() == type->unknown44 - 9)
									parts->unknown8993e0(part,false);
							}
						}
						for (unsigned int i = 0; i < ids.size(); i++)
							OpS8b_Fn9d51d0(scrapLists[slot],ids[i]);
						cmap->unknown49abf0();
						scrapEngineNextTurn = world->getTurn() + scrapUpgradeDelay.randomInRange_40c130();
						return;
					}
				}
			}
		}
	}
}
