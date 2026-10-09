// 0x605040 BS::checkEffectScrapEngine (COGMIND.exe Beta 17.1, size 0xb3e2): byte-matched as
// XsEnt::checkEffectScrapEngine_605040. 'this' is the Entity (self at +0x4, parts at +0x134); the function's own
// error strings say "Entity::checkEffectScrapEngine()" and "BS::checkEffectScrapEngine()"; caller: Entity::turnUpdate.
// Based on Heni's semantic draft (native/giants/605040_Entity_checkEffectScrapEngine.cpp); notes: scratch/xray/NOTES.md.
// All types, callees and globals use private Xs*/xs_* names so they stay stubs in the full link (same nothrow
// inference as a single-file build); they pair with the exe by address. NOTE: placeholder names/layouts throughout.
// Local variable names were chosen for their /Od stack-slot buckets; the stat-averaging loops are written out
// (not macros) because their order and scopes fix the frame layout.

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

//==================================================================
// declarations (only the members this function touches; 32-bit offsets in comments)
//==================================================================

class XsEnt;
class XsItem;
struct XsItemType;

struct XsPoint
{
	int x;	// +0x0
	int y;	// +0x4

	XsPoint(int v);					// 0x409990: x = y = v
	void set(int x_, int y_);		// 0x40a010
	int randomInRange_40c130();	// NOTE: placeholder name (0x40c130): rng.rangeInt(x,y), or y when the range is empty
	int clamp_40c270(int value);	// NOTE: placeholder name (0x40c270): clamp value to [x,y]
};

class XsHEntity
{
public:
	int ID;	// +0x0

	XsHEntity();								// 0x9b6590
};

class XsHProp
{
public:
	int ID;	// +0x0

	XsHProp();								// 0x9b6590
};

class XsHItem
{
public:
	int ID;	// +0x0

	XsHItem();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	bool isNull() const;					// 0x9b65d0
	XsItem *operator->() const;				// 0x9b65b0
};

class XsRNG
{
public:
	bool chance(int percent);			// 0x406c90
	int rangeInt(float a, float b);		// 0x406d70
	float rangeFloat(float a, float b);	// 0x406e20
};

struct XsItemType	// NOTE: placeholder name; elements of itemTypes (0xd2d1c4), Item+0x8
{
	int			ID;	// +0x0 NOTE: placeholder name (index in itemTypes)
	int				pad4[1];
	string			internalName;	// +0x8 NOTE: placeholder name ("Scrap Engine", shown in the upgrade log)
	string			name;	// +0x24
	int				pad40[1];
	int			unknown44;	// +0x44 NOTE: placeholder name (part type: 6 engine, 8 reactor, 9..13 propulsion, 20..23 weapon kinds)
	int			slot;	// +0x48 NOTE: placeholder name (0 power, 1 propulsion, 2 utility, 3 weapon)
	int			size;	// +0x4c NOTE: placeholder name (slots occupied)
	int			rating;	// +0x50 NOTE: placeholder name
	int				pad54[9];
	int			unknown78;	// +0x78 NOTE: placeholder name (copied from the source part with the best rating)
	int				pad7c[6];
	int			unknown94;	// +0x94 NOTE: placeholder name
	int				pad98[3];
	int			unknownA4;	// +0xa4 stat 0
	int			maxIntegrity;	// +0xa8 stat 1
	int			unknownAC;	// +0xac stat 2
	int			unknownB0;	// +0xb0 stat 3
	float			unknownB4;	// +0xb4 stat 4
	int			unknownB8;	// +0xb8 stat 5
	int			unknownBC;	// +0xbc stat 6
	int			unknownC0;	// +0xc0 stat 7
	int				padc4[1];
	int			unknownC8;	// +0xc8 stat 8 (non-zero: the construct is "Cld.")
	int			unknownCC;	// +0xcc stat 9
	int				padd0[1];
	int			unknownD4;	// +0xd4 NOTE: placeholder name (scaled when a propulsion construct grows, except types 12/13)
	float			unknownD8;	// +0xd8 stat 10
	int			unknownDC;	// +0xdc stat 11
	int			unknownE0;	// +0xe0 stat 12
	int			unknownE4;	// +0xe4 stat 13
	int			unknownE8;	// +0xe8 stat 14
	int			unknownEC;	// +0xec stat 15
	int				padf0[4];
	int			unknown100;	// +0x100 stat 16
	int			unknown104;	// +0x104 stat 17
	int			unknown108;	// +0x108 stat 18
	int			unknown10C;	// +0x10c stat 19
	int			unknown110;	// +0x110 stat 20
	int			unknown114;	// +0x114 stat 21
	int			projectiles;	// +0x118 stat 22 NOTE: placeholder name (damage values are per projectile)
	int			unknown11C;	// +0x11c stat 23
	int			damageMin;	// +0x120 stat 24 NOTE: placeholder name
	int			damageMax;	// +0x124 stat 25 NOTE: placeholder name
	int			damageType;	// +0x128 NOTE: placeholder name (7: the construct unlocks achievement 0x14a)
	int			unknown12C;	// +0x12c stat 26
	int			unknown130;	// +0x130 stat 27
	int			critical;	// +0x134 NOTE: placeholder name (critical type, valid per damage type in scrapCriticalAllowed)
	int			criticalChance;	// +0x138 stat 28 NOTE: placeholder name
	vector<int>			penetration;	// +0x13c NOTE: placeholder name (stat name "Penetration" in the upgrade log)
	int			unknown14C;	// +0x14c stat 29
	int			unknown150;	// +0x150 stat 30
	int			unknown154;	// +0x154 NOTE: placeholder name (copied from the source part closest in stat 30)
	int			unknown158;	// +0x158 NOTE: placeholder name
	int			unknown15C;	// +0x15c stat 31
	char			pad160[219];
	bool			scrappable;	// +0x23b NOTE: placeholder name (part type the Scrap Engine can consume/build)
	vector<string>			nameParts;	// +0x23c NOTE: placeholder name (words for the construct's name)

	int *getStatPtr(int index);		// NOTE: placeholder name (0x456da0, OpR1e_Stats::getStatPtr in the csv)
};

class XsItem
{
public:
	int unknown9fcd80();				// NOTE: placeholder name (ICF'd trivial getter 0x9fcd80): this->+0x0
	XsItemType *unknown9b4350();			// NOTE: placeholder name (ICF'd trivial getter 0x9b4350): data (+0x8)
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
	void unknown5759b0(string *slots, vector<struct XsScrapSlotEntry> *entries);	// NOTE: placeholder name (0x5759b0): list of the slots the part occupies
	void unknown57a0f0(const XsPoint *p, int a, int b);	// NOTE: placeholder name (0x57a0f0): drop at p
	void unknown57a190(XsHEntity entity, int slot, int a, int b);	// NOTE: placeholder name (0x57a190): attach to entity
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name (0x57dbe0): destroy/remove the part
};

struct XsScrapSlotEntry	// NOTE: placeholder name and layout (elements of the second Item::unknown5759b0 output; dtor 0x9b3da0)
{
	int unknown00;
};

class XsCell
{
public:
	XsHItem getItem();	// NOTE: placeholder name (0x45d8f0)
};

template <class T>
class XsArray2D	// NOTE: placeholder name (OpX5_Array2D in the csv)
{
public:
	int getWidth();			// NOTE: placeholder name (ICF'd trivial getter 0x9fcd80): +0x0
	int getHeight();		// NOTE: placeholder name (ICF'd trivial getter 0x9b8f00): +0x4
	T *at(int x, int y);	// 0x9ceda0
};

class XsEnt
{
public:
	void *vfptr_;			// +0x0
	XsHEntity self;			// +0x4
	int pad8[(0x134 - 0x8) / 4];
	vector<XsHItem> items;	// +0x134 attached parts

	void checkEffectScrapEngine_605040(XsHItem engine);	// 0x605040

	void unknown5c93d0(vector<int> *out);	// NOTE: placeholder name (0x5c93d0): per-slot counts
	int unknown5cad50();					// NOTE: placeholder name (0x5cad50)
	int unknown5dc440(XsHItem item);			// NOTE: placeholder name (0x5dc440)
	void unknown5e2b50();					// NOTE: placeholder name (0x5e2b50)
	bool unknown5cd220(XsHItem item);			// NOTE: placeholder name (0x5cd220)
	int unknown5d1390();					// NOTE: placeholder name (0x5d1390)
};

class XsMap
{
public:
	XsHEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
	int getTurn();	// 0x464270
	XsHItem unknown6c51d0(XsItemType *type, XsHEntity owner, bool a, bool b);	// NOTE: placeholder name (0x6c51d0, BS::unknown6c51d0 in the csv): create a part attached to owner
};

class XsPlayerData	// NOTE: partial (object at 0xcf45d8)
{
public:
	bool unknown46df10();				// NOTE: placeholder name (0x46df10, Unknown46d8b0::hasMarkedList in the csv)
	void unknown77fbc0(int id);			// NOTE: placeholder name (0x77fbc0): looks like "unlock achievement id"
};

class XsOpR1h_Stats	// NOTE: placeholder name (object at 0xd2c658)
{
public:
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
};

class XsOpW5_RolledValues	// NOTE: placeholder name (object pointer at 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);	// 0x49e250
};

class XsGM	// NOTE: partial (object at 0xd25628)
{
public:
	void addItemAttachCount(int itemID, int count, bool force);	// 0x778560
};

class XsOpU5_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);		// NOTE: placeholder name (0x8758d0)
};

class XsCLogMsgs
{
public:
	void scrollToEnd();					// 0x7b4f10
};

class XsCMap	// NOTE: partial (object at 0xcec054)
{
public:
	void unknown49abf0();				// NOTE: placeholder name (0x49abf0, Panel::unknown49abf0 in the csv)
	void unknown49adc0(int value);		// NOTE: placeholder name (0x49adc0, MapView::unknown49adc0 in the csv)
};

class XsCPart
{
public:
	void drawStatus(bool damaged);		// NOTE: placeholder name (0x4a8e70)
	void unknown4a8f90(bool flag);		// NOTE: placeholder name (0x4a8f90)
	void delegate4a9120();				// NOTE: placeholder name (0x4a9120, Calls_4a9120::delegate in the csv)
};

class XsCParts	// NOTE: partial (object at 0xcec088)
{
public:
	XsCPart *unknown894e70(XsHItem item);	// NOTE: placeholder name (0x894e70)
	void unknown896820(XsHItem item);		// NOTE: placeholder name (0x896820)
	void unknown8987b0(XsHItem item, vector<unsigned int> *out);	// NOTE: placeholder name (0x8987b0)
	void unknown898860(XsHItem item, vector<unsigned int> *list);	// NOTE: placeholder name (0x898860)
	void unknown8993e0(XsCPart *part, bool flag);	// NOTE: placeholder name (0x8993e0)
	bool isLinked4a9b10(XsHItem item);	// NOTE: placeholder name (0x4a9b10)
	void unknown89d610(XsHItem item, int type);	// NOTE: placeholder name (0x89d610)
};

template <class T>
class XsWeightedList	// NOTE: placeholder name (OpR5h_WL<int> in the csv)
{
public:
	vector<T> values;	// +0x0
	vector<int> weights;	// +0x10
	int total;	// +0x20

	XsWeightedList();	// 0x9bab50
	~XsWeightedList();	// 0x700dd0
	void add(T value, int weight);	// 0x9ba310
	T &pick();	// 0x9ba470
	void remove(T value);	// 0x9bab80
};

// free helpers (csv names)
bool xs_findItemType(vector<XsItemType *> &v, const string &name, XsItemType **out);	// NOTE: placeholder name (0x9d7a40)
bool xs_unknown5111e0(int id, const string &text, const string *b, const string *c, XsHEntity d, XsHProp e, const XsPoint *at, int flag);	// NOTE: placeholder name (0x5111e0): log message, true = also flash
int xs_opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name (0x4541b0): play sound
int xs_OpX5_maxInt(int a, int b);	// 0x9cdb60
int xs_OpX5_minInt(int a, int b);	// 0x9cdb30
string xs_intToString(int value);	// 0x4051f0
string xs_OpY1_intToStringSigned(int value);	// 0x405560
string xs_floatToString(float value, int unknown1, int unknown2);	// NOTE: placeholder name (0x405760)
string xs_OpY1_floatToStringSigned(float value, int unknown1, int unknown2);	// 0x4059d0
float xs_opr1c_getFloatByIndex(int index);	// 0x4343a0
float xs_fabs_4012b0(float v);	// NOTE: placeholder name (0x4012b0, fabs)
void xs_logError(string location, string message);	// 0x404f10
void xs_opw1_split(const string &text, char separator, vector<string> &out);	// NOTE: placeholder name (0x408700)
void xs_opu4_shuffle(vector<int> &v);	// NOTE: placeholder name (0x9d8f80, OpS8c_shuffle<int>)
template <class T> void xs_opr4c_eraseRange(vector<T> &v, int first, int last);	// NOTE: placeholder name (0x9e25a0)
template <class T> int xs_OpQ5_randomIndex(vector<T> &v);	// NOTE: placeholder name (0x9d9b20)
template <class T> T xs_randomElement(vector<T> &v);	// NOTE: placeholder name (0x9d5d00, OpU8a_randomRec)
template <class T> T xs_randomRecord(vector<T> &v);	// NOTE: placeholder name (0x9dafb0, OpX5_randomRecord)
int xs_OpT8b_Fn9d99a0(vector<int> &v);	// NOTE: placeholder name (0x9d99a0): sum of the parts' ratings
int xs_OpT8b_Fn9d9ab0(vector<float> &v);	// NOTE: placeholder name (0x9d9ab0)
int xs_OpT8b_Fn9d7d70(vector<float> &v);	// NOTE: placeholder name (0x9d7d70)
int xs_OpS8b_Fn9d4500(vector<int> &v);	// NOTE: placeholder name (0x9d4500): index of the largest value
int xs_OpS8c_indexOfMinInt(vector<int> &v);	// NOTE: placeholder name (0x9d9270)
bool xs_OpS8b_Fn9d51d0(vector<int> &v, int value);	// NOTE: placeholder name (0x9d51d0): remove value
void xs_OpT8a_eraseAt(vector<int> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0): erase v[i], i--
template <class T> void xs_opq3_eraseStepBack(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440)
template <class T> void xs_OpR1F_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9cfab0)
string xs_OpU8a_randomString(vector<string> &v);	// NOTE: placeholder name (0x9d3280)

// scrap engine helpers next to this function (src/op/op_r2_f.cpp, src/game/team_d_31.cpp)
void xs_OpR2_unknown603550(vector<int> &ids, vector<int> &sorted);	// NOTE: placeholder name: sort by rating
void xs_OpR2_unknown603660(vector<int> &ids, XsItemType *type);	// NOTE: placeholder name: pick the propulsion type
void xs_OpR2_unknown6037d0(vector<int> &ids, XsItemType *type);	// NOTE: placeholder name
void xs_OpR2_unknown6038e0(vector<int> &ids, XsItemType *type, bool flag);	// NOTE: placeholder name
bool xs_OpR2_unknown603c00(vector<int> &ids, XsItemType *type, bool flag);	// NOTE: placeholder name: pick the weapon type
void xs_OpD_inheritPartTraits_6040d0(vector<int> &sources, XsItemType *type, bool flag);	// NOTE: placeholder name
void xs_unknown604c20(vector<int> &ids, XsItemType *type);	// NOTE: placeholder name (0x604c20)

//==================================================================
// globals
//==================================================================

extern XsMap						*xs_world;					// 0xcefc4c
extern XsArray2D<XsCell *>			xs_cells;					// NOTE: placeholder name (0xcfd44c, the map's cells)
extern XsRNG						rng;					// 0xd30908
extern XsPlayerData				xs_playerData;				// NOTE: placeholder name (0xcf45d8)
extern XsGM						xs_gm;						// NOTE: placeholder name (0xd25628)
extern XsOpR1h_Stats				xs_stats;					// NOTE: placeholder name (0xd2c658)
extern XsOpW5_RolledValues		*xs_rolledValues;			// NOTE: placeholder name (0xcefb48)
extern XsOpU5_MsgConsole			*xs_msgConsole;			// NOTE: placeholder name (0xcec058)
extern XsCLogMsgs					*xs_logMsgs;				// NOTE: placeholder name (0xcec0b4)
extern XsCMap						*xs_cmap;					// NOTE: placeholder name (0xcec054)
extern XsCParts					*xs_parts;					// NOTE: placeholder name (0xcec088)
extern vector<XsItemType *>		xs_itemTypes;				// NOTE: placeholder name (0xd2d1c4)
extern vector<vector<int> >		xs_scrapLists;				// NOTE: placeholder name (0xcf4a58): consumed item type IDs per slot
extern vector<int>				xs_scrapBuiltItems;		// NOTE: placeholder name (0xcf47cc)
extern int						xs_noItemType;				// NOTE: placeholder name (0xcaf164, -1)
extern int						xs_scrapEngineTurn;		// NOTE: placeholder name (0xcf4a68)
extern int						xs_scrapEngineNextTurn;	// NOTE: placeholder name (0xcf4a6c)
extern bool						xs_scrapDebug;				// NOTE: placeholder name (0xcefb24): forces weapon constructs/upgrades
extern XsPoint					xs_scrapArmDelay;			// NOTE: placeholder name (0xd01b40)
extern XsPoint					xs_scrapRepairDelay;		// NOTE: placeholder name (0xd1e04c)
extern XsPoint					xs_scrapBuildDelay;		// NOTE: placeholder name (0xd31724)
extern XsPoint					xs_scrapUpgradeDelay;		// NOTE: placeholder name (0xcfbed0)
extern int						xs_scrapExpandChance[][9];	// NOTE: placeholder name (0xba3b48, [slot][size])
extern XsPoint					xs_scrapBuildIDs[];		// NOTE: placeholder name (0xd2c3b8, per slot): .y = minimum, random count kept
extern XsPoint					xs_scrapUpgradeIDs[];		// NOTE: placeholder name (0xcf45b0, per slot)
extern XsPoint					xs_scrapUpgradeCount[];	// NOTE: placeholder name (0xd35890, per slot): number of stats changed
extern int						xs_scrapMaxConstructs[];	// NOTE: placeholder name (0xba3be8, per slot)
extern int						xs_scrapWeaponChance;		// NOTE: placeholder name (0xba3bf4)
extern int						xs_scrapMinRating[];		// NOTE: placeholder name (0xba3c08, per slot)
extern int						xs_scrapUpgradeMinRating[];	// NOTE: placeholder name (0xba3c18, per slot)
extern int						xs_scrapStatChance[];		// NOTE: placeholder name (0xba3d78, per stat): chance that a part after the first counts
extern int						xs_scrapStatWeights[][4];		// NOTE: placeholder name (0xba3df8, [stat][slot]: 4 ints per stat)
extern int						xs_scrapStatKind[];		// NOTE: placeholder name (0xba3ff8, per stat)
extern int						xs_scrapStatMode[];		// NOTE: placeholder name (0xba4078, per stat)
extern bool						xs_scrapStatPerSlot[];		// NOTE: placeholder name (0xba40f8, per stat): stat scales with size
extern int						xs_scrapStatBonus[];		// NOTE: placeholder name (0xba4118, per stat)
extern int						xs_scrapStatMinChange[];	// NOTE: placeholder name (0xba4198, per stat)
extern bool						xs_scrapCriticalAllowed[];	// NOTE: placeholder name (0xba4378, [critical * 10 + damageType])
extern XsPoint					xs_scrapStatRanges[];		// NOTE: placeholder name (0xcf3a30, per stat)
extern XsPoint					xs_scrapBuffRanges[];		// NOTE: placeholder name (0xd33ad8, per stat)
extern XsPoint					xs_scrapNerfRanges[];		// NOTE: placeholder name (0xd20518, per stat)
extern string					xs_scrapPropulsionNames[];	// NOTE: placeholder name (0xcfe678, per propulsion type 9..13)
extern string					xs_criticalNames[];		// NOTE: placeholder name (0xd1e058, gameStrings_d1e058 in takeDamage)
extern string					xs_scrapStat30Names[];		// NOTE: placeholder name (0xd31b68, names for ItemType::unknown154)
extern string					xs_scrapStatNames[];		// NOTE: placeholder name (0xd3bb78, per stat)

//==================================================================
// macros
//==================================================================

// message to the log: flash the message console when asked to, then scroll the log
#define SCRAP_MESSAGE(id, text, b, c, owner)	\
	do	\
	{	\
		if (xs_unknown5111e0(id,text,b,c,owner,XsHProp(),0,0))	\
			xs_msgConsole->unknown8758d0(true);	\
		xs_logMsgs->scrollToEnd();	\
	} while (0)

// average one integer stat over the consumed parts: parts after the first only count with a per-stat chance,
// per-slot stats are divided by the part's size, the remainder rounds up at random, then clamp to the stat's range
#define SCRAP_AVERAGE_VALUE(stat, index, value)	\
	total = count = 0;	\
	for (unsigned int i = 0; i < ids.size(); i++)	\
	{	\
		if (i == 0 || rng.chance(xs_scrapStatChance[index]))	\
		{	\
			total += value / (xs_scrapStatPerSlot[index] ? xs_itemTypes[ids[i]]->size : 1);	\
			count++;	\
		}	\
	}	\
	newType->stat = total / count;	\
	if (total % count != 0 && rng.chance(total % count * 100 / count))	\
		newType->stat++;	\
	newType->stat = xs_scrapStatRanges[index].clamp_40c270(newType->stat)

#define SCRAP_AVERAGE(stat, index)	SCRAP_AVERAGE_VALUE(stat,index,xs_itemTypes[ids[i]]->stat)

// same for a float stat: average, +-0.25 at random, rounded down to a multiple of 0.5, not negative
#define SCRAP_AVERAGE_FLOAT(stat, index)	\
	ftotal = count = 0;	\
	for (unsigned int i = 0; i < ids.size(); i++)	\
	{	\
		if (i == 0 || rng.chance(xs_scrapStatChance[index]))	\
		{	\
			ftotal += xs_itemTypes[ids[i]]->stat / (xs_scrapStatPerSlot[index] ? (float)xs_itemTypes[ids[i]]->size : 1.0f);	\
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
// XsEnt::checkEffectScrapEngine
//==================================================================

void XsEnt::checkEffectScrapEngine_605040(XsHItem engine)
{
	if (xs_world->getTurn() < xs_scrapEngineTurn + 30 || xs_world->getTurn() < xs_scrapEngineNextTurn)
		return;

	// Scrap Engine: arm it with the utility parts it consumed
	if (xs_playerData.unknown46df10() && engine->unknown457860() == "Scrap Engine")
	{
		for (unsigned int i = 0; i < xs_scrapLists[2].size(); i++)
		{
			XsItemType *armType;
			if (xs_findItemType(xs_itemTypes,"Arm. Scrap Engine",&armType))
			{
				SCRAP_MESSAGE(0x11b,engine->getName(0,0),0,0,XsHEntity());
				xs_playerData.unknown77fbc0(0x83);
				int b0 = (engine->unknown9b6bf0() == engine->unknown457c80()) ? 100 : engine->unknown457ca0();
				bool active = engine->unknown457cf0();
				bool b5 = engine->unknown458220();
				vector<unsigned int> links;
				xs_parts->unknown8987b0(engine,&links);
				engine->unknown57dbe0(1,0,0,1);
				XsHItem arm = xs_world->unknown6c51d0(armType,self,true,false);
				if (arm.isValid())
				{
					if (b0 < 100)
						arm->unknown450460(xs_OpX5_maxInt(1,arm->unknown457c80() * b0 / 100));
					xs_scrapBuiltItems.push_back(arm->unknown9fcd80());
					xs_gm.addItemAttachCount(arm->unknown457820(),1,false);
					XsCPart *part = xs_parts->unknown894e70(arm);
					if (part != NULL)
					{
						if (active)
							xs_parts->unknown8993e0(part,true);
						if (b5)
							xs_parts->unknown8993e0(part,true);
						xs_parts->unknown89d610(arm,10);
						if (b0 < 100)
							part->drawStatus(false);
						if (!links.empty())
							xs_parts->unknown898860(arm,&links);
					}
					xs_opR1d_4541b0(0xf5,0,0);
				}
			}
			xs_scrapLists[2].clear();
			xs_cmap->unknown49abf0();
			xs_scrapEngineNextTurn = xs_world->getTurn() + xs_scrapArmDelay.randomInRange_40c130();
			return;
		}
	}

	// Arm. Scrap Engine: repair itself with the utility parts it consumed
	if (xs_playerData.unknown46df10() && engine->unknown457860() == "Arm. Scrap Engine" && engine->unknown9b6bf0() < engine->unknown457c80())
	{
		unsigned int consumed = xs_scrapLists[2].size();
		if (consumed != 0)
		{
			xs_scrapLists[2].clear();
			xs_cmap->unknown49abf0();
			int percent = consumed * 20;
			int amountX = xs_OpX5_minInt(engine->unknown457c80() * percent / 100,engine->unknown457c80() - engine->unknown9b6bf0());
			SCRAP_MESSAGE(0x11c,engine->getName(0,0),&xs_intToString(amountX),0,XsHEntity());
			xs_stats.add4729d0(0x178,amountX,"",-1);
			engine->unknown458360(amountX);
			XsCPart *part = xs_parts->unknown894e70(engine);
			if (part != NULL)
			{
				part->drawStatus(false);
				part->unknown4a8f90(true);
			}
			xs_opR1d_4541b0(0xf6,0,0);
			xs_scrapEngineNextTurn = xs_world->getTurn() + xs_scrapRepairDelay.randomInRange_40c130();
			return;
		}
	}

	// constructs already attached
	vector<XsHItem> aa;
	int constructSize = -1;
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i]->getType() <= 3 && items[i]->unknown9b4350()->scrappable)
		{
			aa.push_back(items[i]);
			constructSize += items[i]->unknown4578c0();
		}
	}
	if (constructSize + 1 == 15)
		xs_playerData.unknown77fbc0(0x149);

	if (xs_playerData.unknown46df10())
	{
		vector<int> ct;
		unknown5c93d0(&ct);
		vector<int> slots;
		slots.push_back(0);
		slots.push_back(1);
		slots.push_back(3);
		xs_opu4_shuffle(slots);
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
			if (ct[slot] != 0 && rng.chance(100))
			{
				int count = 0;
				for (unsigned int i = 0; i < aa.size(); i++)
				{
					if (aa[i]->unknown4578a0() == slot)
						count++;
				}
				if (xs_scrapMaxConstructs[slot] == count)
					goto tryUpgrade;
				if (slot == 3 && (rng.chance(100 / xs_scrapWeaponChance * count) || xs_scrapDebug))
					goto tryUpgrade;
				vector<int> e5(xs_scrapLists[slot]);
				if (e5.size() >= (unsigned int)xs_scrapBuildIDs[slot].y)
				{
					xs_opu4_shuffle(e5);
					unsigned int keep = xs_scrapBuildIDs[slot].randomInRange_40c130();
					if (keep < e5.size())
						xs_opr4c_eraseRange(e5,keep,e5.size() - 1);
					if ((unsigned int)xs_OpT8b_Fn9d99a0(e5) < (unsigned int)xs_scrapMinRating[slot])
						goto tryUpgrade;
					XsItemType *en = NULL;
					for (unsigned int i = 0; i < xs_itemTypes.size(); i++)
					{
						if (xs_itemTypes[i]->scrappable && xs_itemTypes[i]->slot == slot)
						{
							for (unsigned int j = 0; j < aa.size(); j++)
							{
								if (aa[j]->unknown457820() == i)
									goto nextType;
							}
							en = xs_itemTypes[i];
						}
					nextType:;
					}
					if (en != NULL)
					{
						switch (slot)
						{
						case 0:
							{
								en->size = 1;
								int gN = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
									gN += xs_itemTypes[e5[i]]->rating;
								en->rating = gN / e5.size();
								int countB;
								gN = countB = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[0]))
									{
										gN += xs_itemTypes[e5[i]]->unknownA4 / (xs_scrapStatPerSlot[0] ? xs_itemTypes[e5[i]]->size : 1);
										countB++;
									}
								}
								en->unknownA4 = gN / countB;
								if (gN % countB != 0 && rng.chance(gN % countB * 100 / countB))
									en->unknownA4++;
								en->unknownA4 = xs_scrapStatRanges[0].clamp_40c270(en->unknownA4);
								gN = countB = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[1]))
									{
										gN += xs_itemTypes[e5[i]]->maxIntegrity / (xs_scrapStatPerSlot[1] ? xs_itemTypes[e5[i]]->size : 1);
										countB++;
									}
								}
								en->maxIntegrity = gN / countB;
								if (gN % countB != 0 && rng.chance(gN % countB * 100 / countB))
									en->maxIntegrity++;
								en->maxIntegrity = xs_scrapStatRanges[1].clamp_40c270(en->maxIntegrity);
								gN = countB = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[2]))
									{
										gN += xs_itemTypes[e5[i]]->unknownAC / (xs_scrapStatPerSlot[2] ? xs_itemTypes[e5[i]]->size : 1);
										countB++;
									}
								}
								en->unknownAC = gN / countB;
								if (gN % countB != 0 && rng.chance(gN % countB * 100 / countB))
									en->unknownAC++;
								en->unknownAC = xs_scrapStatRanges[2].clamp_40c270(en->unknownAC);
								gN = countB = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[3]))
									{
										gN += xs_itemTypes[e5[i]]->unknownB0 / (xs_scrapStatPerSlot[3] ? xs_itemTypes[e5[i]]->size : 1);
										countB++;
									}
								}
								en->unknownB0 = gN / countB;
								if (gN % countB != 0 && rng.chance(gN % countB * 100 / countB))
									en->unknownB0++;
								en->unknownB0 = xs_scrapStatRanges[3].clamp_40c270(en->unknownB0);
								gN = countB = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[5]))
									{
										gN += xs_itemTypes[e5[i]]->unknownB8 / (xs_scrapStatPerSlot[5] ? xs_itemTypes[e5[i]]->size : 1);
										countB++;
									}
								}
								en->unknownB8 = gN / countB;
								if (gN % countB != 0 && rng.chance(gN % countB * 100 / countB))
									en->unknownB8++;
								en->unknownB8 = xs_scrapStatRanges[5].clamp_40c270(en->unknownB8);
								gN = countB = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[6]))
									{
										gN += xs_itemTypes[e5[i]]->unknownBC / (xs_scrapStatPerSlot[6] ? xs_itemTypes[e5[i]]->size : 1);
										countB++;
									}
								}
								en->unknownBC = gN / countB;
								if (gN % countB != 0 && rng.chance(gN % countB * 100 / countB))
									en->unknownBC++;
								en->unknownBC = xs_scrapStatRanges[6].clamp_40c270(en->unknownBC);
								gN = countB = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[7]))
									{
										gN += xs_itemTypes[e5[i]]->unknownC0 / (xs_scrapStatPerSlot[7] ? xs_itemTypes[e5[i]]->size : 1);
										countB++;
									}
								}
								en->unknownC0 = gN / countB;
								if (gN % countB != 0 && rng.chance(gN % countB * 100 / countB))
									en->unknownC0++;
								en->unknownC0 = xs_scrapStatRanges[7].clamp_40c270(en->unknownC0);
								gN = countB = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[8]))
									{
										gN += xs_itemTypes[e5[i]]->unknownC8 / (xs_scrapStatPerSlot[8] ? xs_itemTypes[e5[i]]->size : 1);
										countB++;
									}
								}
								en->unknownC8 = gN / countB;
								if (gN % countB != 0 && rng.chance(gN % countB * 100 / countB))
									en->unknownC8++;
								en->unknownC8 = xs_scrapStatRanges[8].clamp_40c270(en->unknownC8);
								vector<int> sortedRef;
								xs_OpR2_unknown603550(e5,sortedRef);
								vector<string> namesB;
								for (unsigned int i = 0; i < sortedRef.size(); i++)
								{
									if (!xs_itemTypes[sortedRef[i]]->nameParts.empty())
										namesB.push_back(xs_OpU8a_randomString(xs_itemTypes[sortedRef[i]]->nameParts));
								}
								if (namesB.empty())
									en->name = "Power Construct";
								else
								{
									en->unknown44 = xs_itemTypes[sortedRef[0]]->unknown44;
									en->unknown78 = xs_itemTypes[sortedRef[0]]->unknown78;
									bool prefix = false;
									if (namesB.size() == 1)
									{
										en->name = "Construct";
										prefix = true;
									}
									else if (namesB[0] == namesB[1])
										en->name = "Multi-" + namesB[0];
									else
										en->name = namesB[0] + "-" + namesB[1];
									switch (en->unknown44)
									{
									case 6:
										prefix ? en->name.insert(0,"Engine ") : (en->name += " Engine");
										break;
									case 8:
										prefix ? en->name.insert(0,"Reactor ") : (en->name += " Reactor");
										break;
									default:
										prefix ? en->name.insert(0,"Core ") : (en->name += " Core");
										break;
									}
								}
								if (en->unknownC8 != 0)
									en->name.insert(0,"Cld. ");
								XsHItem construct = xs_world->unknown6c51d0(en,self,true,false);
								XsCPart *part = xs_parts->unknown894e70(construct);
								if (unknown5dc440(construct) == 0)
									xs_parts->unknown8993e0(part,false);
								xs_opR1d_4541b0(0xf3,0,0);
								SCRAP_MESSAGE(0x121,engine->getName(0,0),&construct->getName(0,0),0,self);
								xs_stats.add4729d0(0xcc,1,"",-1);
								if (xs_rolledValues != NULL)
									xs_rolledValues->say(0x20,false,"");
								for (unsigned int i = 0; i < e5.size(); i++)
									xs_OpS8b_Fn9d51d0(xs_scrapLists[slot],e5[i]);
								xs_cmap->unknown49abf0();
								xs_scrapEngineNextTurn = xs_world->getTurn() + xs_scrapBuildDelay.randomInRange_40c130();
								xs_cmap->unknown49adc0(1000);
								return;
							}
						case 1:
							{
								en->size = 1;
								int total = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
									total += xs_itemTypes[e5[i]]->rating;
								en->rating = total / e5.size();
								xs_OpR2_unknown603660(e5,en);
								int aE;
								float ftotal;
								total = aE = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[1]))
									{
										total += xs_itemTypes[e5[i]]->maxIntegrity / (xs_scrapStatPerSlot[1] ? xs_itemTypes[e5[i]]->size : 1);
										aE++;
									}
								}
								en->maxIntegrity = total / aE;
								if (total % aE != 0 && rng.chance(total % aE * 100 / aE))
									en->maxIntegrity++;
								en->maxIntegrity = xs_scrapStatRanges[1].clamp_40c270(en->maxIntegrity);
								total = aE = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[2]))
									{
										total += xs_itemTypes[e5[i]]->unknownAC / (xs_scrapStatPerSlot[2] ? xs_itemTypes[e5[i]]->size : 1);
										aE++;
									}
								}
								en->unknownAC = total / aE;
								if (total % aE != 0 && rng.chance(total % aE * 100 / aE))
									en->unknownAC++;
								en->unknownAC = xs_scrapStatRanges[2].clamp_40c270(en->unknownAC);
								total = aE = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[3]))
									{
										total += xs_itemTypes[e5[i]]->unknownB0 / (xs_scrapStatPerSlot[3] ? xs_itemTypes[e5[i]]->size : 1);
										aE++;
									}
								}
								en->unknownB0 = total / aE;
								if (total % aE != 0 && rng.chance(total % aE * 100 / aE))
									en->unknownB0++;
								en->unknownB0 = xs_scrapStatRanges[3].clamp_40c270(en->unknownB0);
								ftotal = aE = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[4]))
									{
										ftotal += xs_itemTypes[e5[i]]->unknownB4 / (xs_scrapStatPerSlot[4] ? (float)xs_itemTypes[e5[i]]->size : 1.0f);
										aE++;
									}
								}
								en->unknownB4 = ftotal / aE;
								en->unknownB4 += rng.rangeFloat(-0.25f,0.25f);
								en->unknownB4 = (int)(en->unknownB4 / 0.5) * 0.5;
								if (en->unknownB4 < 0.0)
									en->unknownB4 = 0;
								total = aE = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[9]))
									{
										total += xs_itemTypes[e5[i]]->unknownCC / (xs_scrapStatPerSlot[9] ? xs_itemTypes[e5[i]]->size : 1);
										aE++;
									}
								}
								en->unknownCC = total / aE;
								if (total % aE != 0 && rng.chance(total % aE * 100 / aE))
									en->unknownCC++;
								en->unknownCC = xs_scrapStatRanges[9].clamp_40c270(en->unknownCC);
								xs_OpR2_unknown6037d0(e5,en);
								ftotal = aE = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[10]))
									{
										ftotal += xs_itemTypes[e5[i]]->unknownD8 / (xs_scrapStatPerSlot[10] ? (float)xs_itemTypes[e5[i]]->size : 1.0f);
										aE++;
									}
								}
								en->unknownD8 = ftotal / aE;
								en->unknownD8 += rng.rangeFloat(-0.25f,0.25f);
								en->unknownD8 = (int)(en->unknownD8 / 0.5) * 0.5;
								if (en->unknownD8 < 0.0)
									en->unknownD8 = 0;
								total = aE = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[11]))
									{
										total += xs_itemTypes[e5[i]]->unknownDC / (xs_scrapStatPerSlot[11] ? xs_itemTypes[e5[i]]->size : 1);
										aE++;
									}
								}
								en->unknownDC = total / aE;
								if (total % aE != 0 && rng.chance(total % aE * 100 / aE))
									en->unknownDC++;
								en->unknownDC = xs_scrapStatRanges[11].clamp_40c270(en->unknownDC);
								total = aE = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[12]))
									{
										total += xs_itemTypes[e5[i]]->unknownE0 / (xs_scrapStatPerSlot[12] ? xs_itemTypes[e5[i]]->size : 1);
										aE++;
									}
								}
								en->unknownE0 = total / aE;
								if (total % aE != 0 && rng.chance(total % aE * 100 / aE))
									en->unknownE0++;
								en->unknownE0 = xs_scrapStatRanges[12].clamp_40c270(en->unknownE0);
								total = aE = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[13]))
									{
										total += xs_itemTypes[e5[i]]->unknownE4 / (xs_scrapStatPerSlot[13] ? xs_itemTypes[e5[i]]->size : 1);
										aE++;
									}
								}
								en->unknownE4 = total / aE;
								if (total % aE != 0 && rng.chance(total % aE * 100 / aE))
									en->unknownE4++;
								en->unknownE4 = xs_scrapStatRanges[13].clamp_40c270(en->unknownE4);
								xs_OpR2_unknown6038e0(e5,en,false);
								vector<int> sortedB;
								xs_OpR2_unknown603550(e5,sortedB);
								vector<string> names;
								for (unsigned int i = 0; i < sortedB.size(); i++)
								{
									if (!xs_itemTypes[sortedB[i]]->nameParts.empty())
										names.push_back(xs_OpU8a_randomString(xs_itemTypes[sortedB[i]]->nameParts));
								}
								en->name = xs_scrapPropulsionNames[en->unknown44 - 9];
								if (en->name.empty() && names.empty())
									en->name += "Construct ";
								else if (names.size() == 1 || (names.size() == 2 && names[0] == names[1]))
									en->name += names[0] + " ";
								else if (names.size() > 1)
									en->name += names[0] + "-" + names[1] + " ";
								en->name += "Exoskeleton";
								XsHItem a5 = xs_world->unknown6c51d0(en,self,true,false);
								XsCPart *part2 = xs_parts->unknown894e70(a5);
								if (unknown5dc440(a5) == 0)
									xs_parts->unknown8993e0(part2,false);
								xs_opR1d_4541b0(0xf3,0,0);
								SCRAP_MESSAGE(0x121,engine->getName(0,0),&a5->getName(0,0),0,self);
								xs_stats.add4729d0(0xcc,1,"",-1);
								if (xs_rolledValues != NULL)
									xs_rolledValues->say(0x20,false,"");
								for (unsigned int i = 0; i < e5.size(); i++)
									xs_OpS8b_Fn9d51d0(xs_scrapLists[slot],e5[i]);
								xs_cmap->unknown49abf0();
								xs_scrapEngineNextTurn = xs_world->getTurn() + xs_scrapBuildDelay.randomInRange_40c130();
								xs_cmap->unknown49adc0(1000);
								return;
							}
						case 3:
							{
								en->size = 1;
								int gi = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
									gi += xs_itemTypes[e5[i]]->rating;
								en->rating = gi / e5.size();
								xs_OpR2_unknown603c00(e5,en,false);
								int tmpCount;
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[0]))
									{
										gi += xs_itemTypes[e5[i]]->unknownA4 / (xs_scrapStatPerSlot[0] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->unknownA4 = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->unknownA4++;
								en->unknownA4 = xs_scrapStatRanges[0].clamp_40c270(en->unknownA4);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[1]))
									{
										gi += xs_itemTypes[e5[i]]->maxIntegrity / (xs_scrapStatPerSlot[1] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->maxIntegrity = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->maxIntegrity++;
								en->maxIntegrity = xs_scrapStatRanges[1].clamp_40c270(en->maxIntegrity);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[2]))
									{
										gi += xs_itemTypes[e5[i]]->unknownAC / (xs_scrapStatPerSlot[2] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->unknownAC = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->unknownAC++;
								en->unknownAC = xs_scrapStatRanges[2].clamp_40c270(en->unknownAC);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[16]))
									{
										gi += xs_itemTypes[e5[i]]->unknown100 / (xs_scrapStatPerSlot[16] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->unknown100 = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->unknown100++;
								en->unknown100 = xs_scrapStatRanges[16].clamp_40c270(en->unknown100);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[18]))
									{
										gi += xs_itemTypes[e5[i]]->unknown108 / (xs_scrapStatPerSlot[18] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->unknown108 = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->unknown108++;
								en->unknown108 = xs_scrapStatRanges[18].clamp_40c270(en->unknown108);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[19]))
									{
										gi += xs_itemTypes[e5[i]]->unknown10C / (xs_scrapStatPerSlot[19] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->unknown10C = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->unknown10C++;
								en->unknown10C = xs_scrapStatRanges[19].clamp_40c270(en->unknown10C);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[20]))
									{
										gi += xs_itemTypes[e5[i]]->unknown110 / (xs_scrapStatPerSlot[20] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->unknown110 = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->unknown110++;
								en->unknown110 = xs_scrapStatRanges[20].clamp_40c270(en->unknown110);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[21]))
									{
										gi += xs_itemTypes[e5[i]]->unknown114 / (xs_scrapStatPerSlot[21] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->unknown114 = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->unknown114++;
								en->unknown114 = xs_scrapStatRanges[21].clamp_40c270(en->unknown114);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[22]))
									{
										gi += xs_itemTypes[e5[i]]->projectiles / (xs_scrapStatPerSlot[22] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->projectiles = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->projectiles++;
								en->projectiles = xs_scrapStatRanges[22].clamp_40c270(en->projectiles);
								// damage and critical chance are averaged over all projectiles, then split again
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[24]))
									{
										gi += (float)(xs_itemTypes[e5[i]]->damageMin * xs_itemTypes[e5[i]]->projectiles) / (xs_scrapStatPerSlot[24] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->damageMin = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->damageMin++;
								en->damageMin = xs_scrapStatRanges[24].clamp_40c270(en->damageMin);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[25]))
									{
										gi += (float)(xs_itemTypes[e5[i]]->damageMax * xs_itemTypes[e5[i]]->projectiles) / (xs_scrapStatPerSlot[25] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->damageMax = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->damageMax++;
								en->damageMax = xs_scrapStatRanges[25].clamp_40c270(en->damageMax);
								if (en->damageMin > en->damageMax)
									en->damageMax = en->damageMin;
								if (en->projectiles > 1)
								{
									en->damageMin /= en->projectiles;
									en->damageMax /= en->projectiles;
								}
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[26]))
									{
										gi += xs_itemTypes[e5[i]]->unknown12C / (xs_scrapStatPerSlot[26] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->unknown12C = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->unknown12C++;
								en->unknown12C = xs_scrapStatRanges[26].clamp_40c270(en->unknown12C);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[27]))
									{
										gi += xs_itemTypes[e5[i]]->unknown130 / (xs_scrapStatPerSlot[27] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->unknown130 = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->unknown130++;
								en->unknown130 = xs_scrapStatRanges[27].clamp_40c270(en->unknown130);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[28]))
									{
										gi += (float)(xs_itemTypes[e5[i]]->criticalChance * xs_itemTypes[e5[i]]->projectiles) / (xs_scrapStatPerSlot[28] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->criticalChance = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->criticalChance++;
								en->criticalChance = xs_scrapStatRanges[28].clamp_40c270(en->criticalChance);
								if (en->criticalChance != 0)
								{
									vector<int> criticals;
									for (unsigned int i = 0; i < e5.size(); i++)
									{
										if (xs_itemTypes[e5[i]]->damageType == en->damageType && xs_scrapCriticalAllowed[xs_itemTypes[e5[i]]->critical * 10 + en->damageType])
											criticals.push_back(xs_itemTypes[e5[i]]->critical);
									}
									if (criticals.empty())
									{
										en->criticalChance = 0;
										en->critical = 0;
									}
									else
									{
										en->criticalChance /= en->projectiles;
										en->critical = xs_randomElement(criticals);
									}
								}
								else
								{
									en->criticalChance = 0;
									en->critical = 0;
								}
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[29]))
									{
										gi += xs_itemTypes[e5[i]]->unknown14C / (xs_scrapStatPerSlot[29] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->unknown14C = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->unknown14C++;
								en->unknown14C = xs_scrapStatRanges[29].clamp_40c270(en->unknown14C);
								gi = tmpCount = 0;
								for (unsigned int i = 0; i < e5.size(); i++)
								{
									if (i == 0 || rng.chance(xs_scrapStatChance[30]))
									{
										gi += xs_itemTypes[e5[i]]->unknown150 / (xs_scrapStatPerSlot[30] ? xs_itemTypes[e5[i]]->size : 1);
										tmpCount++;
									}
								}
								en->unknown150 = gi / tmpCount;
								if (gi % tmpCount != 0 && rng.chance(gi % tmpCount * 100 / tmpCount))
									en->unknown150++;
								en->unknown150 = xs_scrapStatRanges[30].clamp_40c270(en->unknown150);
								if (en->unknown150 != 0)
									en->unknown158 = 0;
								if (en->unknown158 == 0 && en->critical == 1)
								{
									en->critical = 0;
									en->criticalChance = 0;
								}
								// unknown154 comes from the part closest in stat 30
								int i8 = xs_noItemType;
								i8 = e5[0];
								for (unsigned int i = 1; i < e5.size(); i++)
								{
									if (abs(xs_itemTypes[e5[i]]->unknown150 - en->unknown150) < abs(xs_itemTypes[i8]->unknown150 - en->unknown150))
										i8 = e5[i];
								}
								en->unknown154 = xs_itemTypes[i8]->unknown154;
								xs_OpD_inheritPartTraits_6040d0(e5,en,false);
								vector<int> aX;
								xs_OpR2_unknown603550(e5,aX);
								for (unsigned int i = 0; i < aX.size(); i++)
								{
									if (xs_itemTypes[aX[i]]->damageType != en->damageType)
										xs_OpT8a_eraseAt(aX,i);
								}
								xs_unknown604c20(aX,en);
								XsHItem construct = xs_world->unknown6c51d0(en,self,true,false);
								XsCPart *part = xs_parts->unknown894e70(construct);
								if (unknown5dc440(construct) == 0)
									xs_parts->unknown8993e0(part,false);
								xs_opR1d_4541b0(0xf3,0,0);
								SCRAP_MESSAGE(0x121,engine->getName(0,0),&construct->getName(0,0),0,self);
								xs_stats.add4729d0(0xcc,1,"",-1);
								if (construct->unknown9b4350()->damageType == 7)
									xs_playerData.unknown77fbc0(0x14a);
								if (xs_rolledValues != NULL)
									xs_rolledValues->say(0x20,false,"");
								for (unsigned int i = 0; i < e5.size(); i++)
									xs_OpS8b_Fn9d51d0(xs_scrapLists[slot],e5[i]);
								xs_cmap->unknown49abf0();
								xs_scrapEngineNextTurn = xs_world->getTurn() + xs_scrapBuildDelay.randomInRange_40c130();
								xs_cmap->unknown49adc0(1000);
								return;
							}
						}
					}
				}
			}
		tryUpgrade:
			// upgrade an existing construct of this slot with the parts consumed for it
			if (rng.chance(7) || (xs_scrapDebug && slot == 3))
			{
				vector<int> ids(xs_scrapLists[slot]);
				if (ids.size() >= (unsigned int)xs_scrapUpgradeIDs[slot].y)
				{
					xs_opu4_shuffle(ids);
					unsigned int keep = xs_scrapUpgradeIDs[slot].randomInRange_40c130();
					if (keep < ids.size())
						xs_opr4c_eraseRange(ids,keep,ids.size() - 1);
					if ((unsigned int)xs_OpT8b_Fn9d99a0(ids) < (unsigned int)xs_scrapUpgradeMinRating[slot])
						continue;
					vector<XsHItem> j4;
					for (unsigned int i = 0; i < aa.size(); i++)
					{
						if (aa[i]->unknown4578a0() == slot)
							j4.push_back(aa[i]);
					}
					if (!j4.empty())
					{
						// usually prefer the lowest-rated constructs
						if (j4.size() > 1 && rng.chance(66))
						{
							int lowestRating = j4[0]->unknown457900();
							for (unsigned int i = 1; i < j4.size(); i++)
							{
								if (j4[i]->unknown457900() < lowestRating)
									lowestRating = j4[i]->unknown457900();
							}
							for (unsigned int i = 0; i < j4.size(); i++)
							{
								if (j4[i]->unknown457900() > lowestRating)
									xs_opq3_eraseStepBack(j4,i);
							}
							if (j4.empty())
							{
								xs_logError("Entity::checkEffectScrapEngine()","applicableConstructPool completely empty");
								return;
							}
						}
						XsHItem target4 = xs_randomRecord(j4);
						XsItemType *type6 = target4->unknown9b4350();
						bool activeX = target4->unknown457cf0();
						bool k5 = target4->unknown458220();
						int partType = type6->unknown44;
						vector<string> b3;
						int buffChance = 35;
						for (unsigned int i = 0; i < ids.size(); i++)
						{
							if (xs_itemTypes[ids[i]]->unknown94 != 0 || xs_itemTypes[ids[i]]->rating > target4->unknown457900())
								buffChance += 15;
						}
						b3.push_back("buffChance=" + xs_intToString(buffChance) + "%");
						XsWeightedList<int> aG;
						for (int i = 0; i < 32; i++)
							aG.add(i,xs_scrapStatWeights[i][slot]);
						vector<string> aH;
						vector<int> upgraded;
						vector<int> buffed;
						for (int n = xs_scrapUpgradeCount[slot].randomInRange_40c130(); n != 0; n--)
						{
							int stat = aG.pick();
							aG.remove(stat);
							bool lo = rng.chance(buffChance);
							int mode = xs_scrapStatMode[stat];
							b3.push_back("#" + xs_intToString(n) + ": ");
							switch (xs_scrapStatKind[stat])
							{
							case 0:	// integer stat
								{
									vector<int> values;
									for (unsigned int i = 0; i < ids.size(); i++)
										values.push_back(*xs_itemTypes[ids[i]]->getStatPtr(stat));
									int *value = type6->getStatPtr(stat);
									int oldValue = *value;
									int a_ = -1;
									int nG;
									switch (mode)
									{
									case 0:	// higher is better
										if (lo)
										{
											b3.back() += xs_intToString(*value) + "[buff]->";
											if (stat == 24 || stat == 25 || stat == 28)
											{
												// damage and critical chance: work on the total over all projectiles
												*value = (int)(type6->projectiles * (stat == 28 ? 1.0f : xs_opr1c_getFloatByIndex(type6->projectiles)) * *value);
												a_ = xs_OpS8b_Fn9d4500(values);
												float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[a_]]->size : 1.0;
												nG = (int)(values[a_] * (xs_itemTypes[ids[a_]]->projectiles * (stat == 28 ? 1.0f : xs_opr1c_getFloatByIndex(xs_itemTypes[ids[a_]]->projectiles)) * scale) + *value);
												SCRAP_HALVE(value,nG);
												*value = (rng.rangeInt(xs_scrapBuffRanges[stat].x + 100,xs_scrapBuffRanges[stat].y + 100) + constructSize * xs_scrapStatBonus[stat]) * *value / 100;
												*value = *value / type6->projectiles;
												*value = xs_scrapStatRanges[stat].clamp_40c270(*value);
											}
											else
											{
												a_ = xs_OpS8b_Fn9d4500(values);
												float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[a_]]->size : 1.0;
												nG = (int)(values[a_] * scale + *value);
												SCRAP_HALVE(value,nG);
												*value = (rng.rangeInt(xs_scrapBuffRanges[stat].x + 100,xs_scrapBuffRanges[stat].y + 100) + constructSize * xs_scrapStatBonus[stat]) * *value / 100;
												*value = xs_scrapStatRanges[stat].clamp_40c270(*value);
											}
											b3.back() += xs_intToString(*value);
										}
										else
										{
											b3.back() += xs_intToString(*value) + "->";
											if (stat == 24 || stat == 25 || stat == 28)
											{
												*value = (int)(type6->projectiles * (stat == 28 ? 1.0f : xs_opr1c_getFloatByIndex(type6->projectiles)) * *value);
												a_ = xs_OpQ5_randomIndex(values);
												float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[a_]]->size : 1.0;
												nG = (int)(values[a_] * (xs_itemTypes[ids[a_]]->projectiles * (stat == 28 ? 1.0f : xs_opr1c_getFloatByIndex(xs_itemTypes[ids[a_]]->projectiles)) * scale) + *value);
												SCRAP_HALVE(value,nG);
												*value = xs_OpX5_minInt(100,rng.rangeInt(100 - xs_scrapNerfRanges[stat].y,100 - xs_scrapNerfRanges[stat].x) + constructSize * xs_scrapStatBonus[stat]) * *value / 100;
												*value = *value / type6->projectiles;
												*value = xs_scrapStatRanges[stat].clamp_40c270(*value);
											}
											else
											{
												a_ = xs_OpQ5_randomIndex(values);
												float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[a_]]->size : 1.0;
												nG = (int)(values[a_] * scale + *value);
												SCRAP_HALVE(value,nG);
												*value = xs_OpX5_minInt(100,rng.rangeInt(100 - xs_scrapNerfRanges[stat].y,100 - xs_scrapNerfRanges[stat].x) + constructSize * xs_scrapStatBonus[stat]) * *value / 100;
												*value = xs_scrapStatRanges[stat].clamp_40c270(*value);
											}
											b3.back() += xs_intToString(*value);
										}
										break;
									case 1:	// lower is better
										if (lo)
										{
											b3.back() += xs_intToString(*value) + "[buff]->";
											a_ = xs_OpS8c_indexOfMinInt(values);
											float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[a_]]->size : 1.0;
											nG = (int)(values[a_] * scale + *value);
											SCRAP_HALVE(value,nG);
											*value = xs_OpX5_maxInt(0,rng.rangeInt(100 - xs_scrapBuffRanges[stat].y,100 - xs_scrapBuffRanges[stat].x) - constructSize * xs_scrapStatBonus[stat]) * *value / 100;
											*value = xs_scrapStatRanges[stat].clamp_40c270(*value);
											b3.back() += xs_intToString(*value);
										}
										else
										{
											b3.back() += xs_intToString(*value) + "->";
											a_ = xs_OpQ5_randomIndex(values);
											float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[a_]]->size : 1.0;
											nG = (int)(values[a_] * scale + *value);
											SCRAP_HALVE(value,nG);
											*value = (rng.rangeInt(xs_scrapNerfRanges[stat].x + 100,xs_scrapNerfRanges[stat].y + 100) + constructSize * xs_scrapStatBonus[stat]) * *value / 100;
											*value = xs_scrapStatRanges[stat].clamp_40c270(*value);
											b3.back() += xs_intToString(*value);
										}
										break;
									case 2:	// neither: wider random range
										b3.back() += xs_intToString(*value) + "[special]->";
										a_ = xs_OpQ5_randomIndex(values);
										float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[a_]]->size : 1.0;
										nG = (int)(values[a_] * scale + *value);
										SCRAP_HALVE(value,nG);
										*value = rng.rangeInt(100 - xs_scrapBuffRanges[stat].y,xs_scrapNerfRanges[stat].y + 100) * *value / 100;
										*value = xs_scrapStatRanges[stat].clamp_40c270(*value);
										b3.back() += xs_intToString(*value);
										break;
									}
									b3.back() += " " + xs_scrapStatNames[stat];
									if (abs(*value - oldValue) < xs_scrapStatMinChange[stat])
									{
										*value = oldValue;
										b3.back() += " (cancelled)";
									}
									else if (*value != oldValue)
									{
										b3.back() += " {" + xs_itemTypes[ids[a_]]->internalName + "}";
										upgraded.push_back(ids[a_]);
										if (lo)
											buffed.push_back(upgraded.back());
										aH.push_back(xs_scrapStatNames[stat]);
										aH.back() += " " + xs_OpY1_intToStringSigned(*value - oldValue);
										switch (stat)
										{
										case 1:	// max integrity: keep the same damage, cap integrity
											if (target4->unknown457c80() > oldValue)
												target4->unknown458360(target4->unknown457c80() - oldValue);
											if (target4->unknown9b6bf0() > target4->unknown457c80())
												target4->unknown450460(target4->unknown457c80());
											break;
										case 7:
											unknown5e2b50();
											break;
										case 22:	// projectiles: rescale the per-projectile values
											{
												float oldMultiplier = xs_opr1c_getFloatByIndex(oldValue);
												float newMultiplier = xs_opr1c_getFloatByIndex(type6->projectiles);
												type6->damageMin = (int)((float)type6->damageMin * oldValue / oldMultiplier * newMultiplier / type6->projectiles);
												type6->damageMax = (int)((float)type6->damageMax * oldValue / oldMultiplier * newMultiplier / type6->projectiles);
												type6->criticalChance = (int)((float)type6->criticalChance * oldValue / type6->projectiles);
											}
											break;
										case 24:
											if (type6->damageMin > type6->damageMax)
												type6->damageMax = type6->damageMin;
											break;
										case 25:
											if (type6->damageMin > type6->damageMax)
												type6->damageMin = type6->damageMax;
											break;
										case 28:	// critical chance: maybe take over the source part's critical
											if (!xs_scrapCriticalAllowed[type6->critical * 10 + type6->damageType])
												type6->critical = 0;
											if (xs_itemTypes[upgraded.back()]->critical != 0 && xs_itemTypes[upgraded.back()]->critical != type6->critical &&
												xs_scrapCriticalAllowed[xs_itemTypes[upgraded.back()]->critical * 10 + xs_itemTypes[upgraded.back()]->damageType])
											{
												type6->critical = xs_itemTypes[upgraded.back()]->critical;
												aH.back() += "/" + xs_criticalNames[type6->critical];
											}
											if (type6->criticalChance == 0)
												type6->critical = 0;
											else if (type6->critical == 0)
												type6->criticalChance = 0;
											break;
										case 30:
											if (xs_itemTypes[upgraded.back()]->unknown154 != 0 && xs_itemTypes[upgraded.back()]->unknown154 != type6->unknown154)
											{
												type6->unknown154 = xs_itemTypes[upgraded.back()]->unknown154;
												aH.back() += "/" + xs_scrapStat30Names[type6->unknown154];
											}
											if (type6->unknown150 == 0)
												type6->unknown154 = 0;
											else if (type6->unknown158 != 0)
												type6->unknown158 = 0;
											break;
										}
									}
								}
								break;
							case 1:	// float stat
								{
									vector<float> values;
									for (unsigned int i = 0; i < ids.size(); i++)
										values.push_back(*(float *)xs_itemTypes[ids[i]]->getStatPtr(stat));
									float *value = (float *)type6->getStatPtr(stat);
									float oldValue = *value;
									int bC = -1;
									float nW;
									switch (mode)
									{
									case 0:
										if (lo)
										{
											b3.back() += xs_floatToString(*value,0,1) + "[buff]->";
											bC = xs_OpT8b_Fn9d9ab0(values);
											float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[bC]]->size : 1.0;
											nW = values[bC] * scale + *value;
											*value = nW / 2.0;
											SCRAP_JITTER_FLOAT(value);
											*value = (rng.rangeInt(xs_scrapBuffRanges[stat].x + 100,xs_scrapBuffRanges[stat].y + 100) + constructSize * xs_scrapStatBonus[stat]) * *value / 100.0;
											SCRAP_CLAMP_FLOAT(value);
											b3.back() += xs_floatToString(*value,0,1);
										}
										else
										{
											b3.back() += xs_floatToString(*value,0,1) + "->";
											bC = xs_OpQ5_randomIndex(values);
											float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[bC]]->size : 1.0;
											nW = values[bC] * scale + *value;
											*value = nW / 2.0;
											SCRAP_JITTER_FLOAT(value);
											*value = xs_OpX5_minInt(100,rng.rangeInt(100 - xs_scrapNerfRanges[stat].y,100 - xs_scrapNerfRanges[stat].x) + constructSize * xs_scrapStatBonus[stat]) * *value / 100.0;
											SCRAP_CLAMP_FLOAT(value);
											b3.back() += xs_floatToString(*value,0,1);
										}
										break;
									case 1:
										if (lo)
										{
											b3.back() += xs_floatToString(*value,0,1) + "[buff]->";
											bC = xs_OpT8b_Fn9d7d70(values);
											float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[bC]]->size : 1.0;
											nW = values[bC] * scale + *value;
											*value = nW / 2.0;
											SCRAP_JITTER_FLOAT(value);
											*value = xs_OpX5_maxInt(0,rng.rangeInt(100 - xs_scrapBuffRanges[stat].y,100 - xs_scrapBuffRanges[stat].x) - constructSize * xs_scrapStatBonus[stat]) * *value / 100.0;
											SCRAP_CLAMP_FLOAT(value);
											b3.back() += xs_floatToString(*value,0,1);
										}
										else
										{
											b3.back() += xs_floatToString(*value,0,1) + "->";
											bC = xs_OpQ5_randomIndex(values);
											float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[bC]]->size : 1.0;
											nW = values[bC] * scale + *value;
											*value = nW / 2.0;
											SCRAP_JITTER_FLOAT(value);
											*value = (rng.rangeInt(xs_scrapNerfRanges[stat].x + 100,xs_scrapNerfRanges[stat].y + 100) + constructSize * xs_scrapStatBonus[stat]) * *value / 100.0;
											SCRAP_CLAMP_FLOAT(value);
											b3.back() += xs_floatToString(*value,0,1);
										}
										break;
									case 2:
										b3.back() += xs_floatToString(*value,0,1) + "[special]->";
										bC = xs_OpQ5_randomIndex(values);
										float scale = xs_scrapStatPerSlot[stat] ? (float)type6->size / xs_itemTypes[ids[bC]]->size : 1.0;
										nW = values[bC] * scale + *value;
										*value = nW / 2.0;
										SCRAP_JITTER_FLOAT(value);
										*value = rng.rangeInt(100 - xs_scrapBuffRanges[stat].y,xs_scrapNerfRanges[stat].y + 100) * *value / 100.0;
										SCRAP_CLAMP_FLOAT(value);
										b3.back() += xs_floatToString(*value,0,1);
										break;
									}
									b3.back() += " " + xs_scrapStatNames[stat];
									if (xs_fabs_4012b0(*value - oldValue) < xs_scrapStatMinChange[stat])
									{
										*value = oldValue;
										b3.back() += " (cancelled)";
									}
									else if (*value != oldValue)
									{
										b3.back() += " {" + xs_itemTypes[ids[bC]]->internalName + "}";
										upgraded.push_back(ids[bC]);
										if (lo)
											buffed.push_back(upgraded.back());
										aH.push_back(xs_scrapStatNames[stat]);
										aH.back() += " " + xs_OpY1_floatToStringSigned(*value - oldValue,0,1);
									}
								}
								break;
							}
						}
						if (!upgraded.empty())
						{
							// sometimes the construct also grows by one slot (removing a smaller construct when the slot is full)
							bool a2 = false;
							if ((ct[slot] != 0 || slot == 3) && (rng.chance(xs_scrapExpandChance[slot][type6->size]) || (xs_scrapDebug && slot == 3)))
							{
								bool noRoom = false;
								if (ct[slot] == 0)
								{
									vector<XsHItem> removable;
									for (unsigned int i = 0; i < j4.size(); i++)
									{
										if (j4[i]->unknown4578c0() == 1 && j4[i]->unknown457900() < type6->rating && !xs_parts->isLinked4a9b10(j4[i]))
											removable.push_back(j4[i]);
									}
									if (!removable.empty())
										xs_randomRecord(removable)->unknown57dbe0(1,0,0,0);
									else
										noRoom = true;
								}
								if (!noRoom)
								{
									int a9 = type6->size;
									type6->size++;
									float factor = (float)type6->size / a9;
									for (int i = 0; i < 32; i++)
									{
										if (xs_scrapStatWeights[i][slot] != 0 && xs_scrapStatPerSlot[i])
										{
											switch (xs_scrapStatKind[i])
											{
											case 0:
												*type6->getStatPtr(i) *= factor;
												if (i == 1)
													target4->unknown458360(target4->unknown9b6bf0() * factor);
												break;
											case 1:
												{
													float *value = (float *)type6->getStatPtr(i);
													*value *= factor;
													*value = (int)(*value / 0.5) * 0.5;
												}
												break;
											}
										}
									}
									if (slot == 1 && type6->unknown44 != 12 && type6->unknown44 != 13)
										type6->unknownD4 *= factor;
									// reattach the construct through an empty cell so it takes the new size
									XsPoint tempLoc(-1);
									for (int x = 0; x < xs_cells.getWidth(); x++)
									{
										for (int y = 0; y < xs_cells.getHeight(); y++)
										{
											if ((*xs_cells.at(x,y))->getItem().isNull())
											{
												tempLoc.set(x,y);
												break;
											}
										}
									}
									if (tempLoc.x == -1)
										xs_logError("BS::checkEffectScrapEngine()","unable to find tempLoc");
									else
									{
										target4->unknown57a0f0(&tempLoc,0,1);
										target4->unknown57a190(xs_world->getPlayer(),slot,1,0);
										a2 = true;
									}
								}
							}

							// type-specific traits
							if (slot == 3)
							{
								int oldDamageType = type6->damageType;
								vector<int> oldPenetration(type6->penetration);
								if (xs_OpR2_unknown603c00(upgraded,type6,true) && !xs_scrapCriticalAllowed[type6->critical * 10 + type6->damageType])
								{
									type6->criticalChance = 0;
									type6->critical = 0;
									for (unsigned int i = 0; i < aH.size(); i++)
									{
										if (aH[i].find(xs_scrapStatNames[28],0) != string::npos)
										{
											aH[i] = "-Critical";
											break;
										}
									}
								}
								if (type6->unknown158 == 0 && type6->critical == 1)
								{
									type6->critical = 0;
									type6->criticalChance = 0;
								}
								if (type6->penetration.empty() != oldPenetration.empty())
								{
									aH.push_back(oldPenetration.empty() ? "+" : "-");
									aH.back() += "Penetration";
								}
								int ns = type6->unknown104;
								int a1 = type6->unknown11C;
								int old15C = type6->unknown15C;
								xs_OpD_inheritPartTraits_6040d0(upgraded,type6,true);
								if (type6->unknown104 != ns)
								{
									aH.push_back(xs_scrapStatNames[17]);
									aH.back() += " " + xs_OpY1_intToStringSigned(type6->unknown104 - ns);
								}
								if (type6->unknown11C != a1)
								{
									aH.push_back(xs_scrapStatNames[23]);
									aH.back() += " " + xs_OpY1_intToStringSigned(type6->unknown11C - a1);
								}
								if (type6->unknown15C != old15C)
								{
									aH.push_back(xs_scrapStatNames[31]);
									aH.back() += " " + xs_OpY1_intToStringSigned(type6->unknown15C - old15C);
								}
							}
							else if (slot == 1)
							{
								if (!buffed.empty())
								{
									xs_OpR2_unknown603660(buffed,type6);
									if (type6->unknown44 != partType)
										xs_OpR2_unknown6037d0(buffed,type6);
								}
								int oldE8 = type6->unknownE8;
								int oldEC = type6->unknownEC;
								xs_OpR2_unknown6038e0(upgraded,type6,true);
								if (type6->unknownE8 != oldE8)
								{
									aH.push_back(xs_scrapStatNames[14]);
									aH.back() += " " + xs_OpY1_intToStringSigned(type6->unknownE8 - oldE8);
								}
								if (type6->unknownEC != oldEC)
								{
									if (type6->unknownEC == 0)
										aH.push_back("-" + xs_scrapStatNames[15]);
									else
										aH.push_back("+" + xs_scrapStatNames[15]);
								}
							}

							// log summary
							XsCPart *part1 = xs_parts->unknown894e70(target4);
							bool renamed = false;
							string summary(aH[0]);
							for (unsigned int i = 1; i < aH.size(); i++)
								summary += ", " + aH[i];
							if (a2)
							{
								string pK;
								vector<XsScrapSlotEntry> slotEntries;
								target4->unknown5759b0(&pK,&slotEntries);
								summary += "\nExpanded to " + xs_intToString(type6->size) + " slots (" + pK + ")";
							}
							int rating = 0;
							for (unsigned int i = 0; i < upgraded.size(); i++)
								rating += xs_itemTypes[upgraded[i]]->rating;
							rating /= upgraded.size();
							type6->rating = (rating + type6->rating) / 2;

							// rename the construct from the parts that improved it
							if (slot == 3)
							{
								string oldName = target4->getName(0,0);
								xs_unknown604c20(buffed,type6);
								if (target4->getName(0,0) != oldName)
								{
									SCRAP_MESSAGE(0x123,oldName,&summary,&target4->getName(0,0),self);
									if (part1 != NULL)
									{
										part1->delegate4a9120();
										xs_parts->unknown896820(target4);
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
										string oldName = target4->getName(0,0);
										vector<string> words;
										xs_opw1_split(target4->getName(0,0),' ',words);
										if (words.front() == "Cld.")
											xs_OpR1F_eraseAt(words,0);
										words.pop_back();
										if (words[0] == "Construct")
											words.clear();
										vector<string> oldParts;
										for (unsigned int i = 0; i < words.size(); i++)
										{
											if (words[i].find('-',0) != string::npos)
											{
												vector<string> pieces;
												xs_opw1_split(words[i],'-',pieces);
												for (unsigned int j = 0; j < pieces.size(); j++)
												{
													if (pieces[j] != "Multi")
														oldParts.push_back(pieces[j]);
												}
											}
											else
												oldParts.push_back(words[i]);
										}
										vector<int> sortedVal;
										if (!buffed.empty())
											xs_OpR2_unknown603550(buffed,sortedVal);
										vector<string> names;
										for (unsigned int i = 0; i < sortedVal.size(); i++)
										{
											if (!xs_itemTypes[sortedVal[i]]->nameParts.empty())
												names.push_back(xs_OpU8a_randomString(xs_itemTypes[sortedVal[i]]->nameParts));
										}
										if (!oldParts.empty())
										{
											if (names.empty())
												names = oldParts;
											else if (names.size() == 1)
												names.push_back(xs_OpU8a_randomString(oldParts));
											else
												names[1] = xs_OpU8a_randomString(oldParts);
										}
										if (names.empty())
											type6->name = "Power Construct";
										else
										{
											type6->unknown44 = xs_itemTypes[sortedVal[0]]->unknown44;
											type6->unknown78 = xs_itemTypes[sortedVal[0]]->unknown78;
											bool prefix = false;
											if (names.size() == 1)
											{
												type6->name = "Construct";
												prefix = true;
											}
											else if (names[0] == names[1])
												type6->name = "Multi-" + names[0];
											else
												type6->name = names[0] + "-" + names[1];
											switch (type6->unknown44)
											{
											case 6:
												prefix ? type6->name.insert(0,"Engine ") : (type6->name += " Engine");
												break;
											case 8:
												prefix ? type6->name.insert(0,"Reactor ") : (type6->name += " Reactor");
												break;
											default:
												prefix ? type6->name.insert(0,"Core ") : (type6->name += " Core");
												break;
											}
										}
										if (type6->unknownC8 != 0)
											type6->name.insert(0,"Cld. ");
										if (target4->getName(0,0) != oldName)
										{
											SCRAP_MESSAGE(0x123,oldName,&summary,&target4->getName(0,0),self);
											if (part1 != NULL)
											{
												part1->delegate4a9120();
												xs_parts->unknown896820(target4);
											}
											renamed = true;
										}
									}
									break;
								case 1:
									{
										string oldName = target4->getName(0,0);
										vector<string> words;
										xs_opw1_split(target4->getName(0,0),' ',words);
										if (!xs_scrapPropulsionNames[partType - 9].empty())
											words.erase(words.begin());
										words.pop_back();
										if (words[0] == "Construct")
											words.clear();
										vector<string> oldParts;
										for (unsigned int i = 0; i < words.size(); i++)
										{
											if (words[i].find('-',0) != string::npos)
												xs_opw1_split(words[i],'-',oldParts);
											else
												oldParts.push_back(words[i]);
										}
										vector<int> sortedTmp;
										if (!buffed.empty())
											xs_OpR2_unknown603550(buffed,sortedTmp);
										vector<string> names;
										for (unsigned int i = 0; i < sortedTmp.size(); i++)
										{
											if (!xs_itemTypes[sortedTmp[i]]->nameParts.empty())
												names.push_back(xs_OpU8a_randomString(xs_itemTypes[sortedTmp[i]]->nameParts));
										}
										if (!oldParts.empty())
										{
											if (names.empty())
												names = oldParts;
											else if (names.size() == 1)
												names.push_back(xs_OpU8a_randomString(oldParts));
											else
												names[1] = xs_OpU8a_randomString(oldParts);
										}
										type6->name = xs_scrapPropulsionNames[type6->unknown44 - 9];
										if (type6->name.empty() && names.empty())
											type6->name += "Construct ";
										else if (names.size() == 1 || (names.size() >= 2 && names[0] == names[1]))
											type6->name += names[0] + " ";
										else if (names.size() > 1)
											type6->name += names[0] + "-" + names[1] + " ";
										type6->name += "Exoskeleton";
										if (target4->getName(0,0) != oldName)
										{
											SCRAP_MESSAGE(0x123,oldName,&summary,&target4->getName(0,0),self);
											if (part1 != NULL)
											{
												part1->delegate4a9120();
												xs_parts->unknown896820(target4);
											}
											renamed = true;
										}
									}
									break;
								}
							}
							if (!renamed)
								SCRAP_MESSAGE(0x122,target4->getName(0,0),&summary,0,self);
							xs_opR1d_4541b0(0xf4,0,0);
							xs_stats.add4729d0(0xcd,1,"",-1);
							if (slot == 3)
							{
								if (a2 && target4->unknown4578c0() >= 3)
									xs_playerData.unknown77fbc0(0xd8);
								if (target4->unknown9b4350()->damageType == 7)
									xs_playerData.unknown77fbc0(0x14a);
							}
							xs_cmap->unknown49adc0(1000);

							// integrity: never above the (possibly lower) maximum, and a partial repair
							if (target4->unknown457c80() < target4->unknown9b6bf0())
								target4->unknown450460(target4->unknown457c80() - 1);
							if (target4->unknown9b6bf0() < target4->unknown457c80())
							{
								int repair = xs_OpX5_minInt(xs_OpX5_maxInt(1,target4->unknown457c80() * 35 / 100),target4->unknown457c80() - target4->unknown9b6bf0());
								xs_stats.add4729d0(0x178,repair,"",-1);
								target4->unknown458360(repair);
							}
							if (part1 != NULL)
							{
								part1->drawStatus(false);
								part1->unknown4a8f90(true);
							}

							// restore the activation state (a changed propulsion type may not be compatible)
							while (target4->unknown457cf0())
								xs_parts->unknown8993e0(part1,false);
							if (slot != 1 || type6->unknown44 == partType || !unknown5cd220(target4))
							{
								if (activeX)
									xs_parts->unknown8993e0(part1,false);
								if (k5 && target4->unknown458180())
									xs_parts->unknown8993e0(part1,false);
								if (slot == 1 && type6->unknown44 != partType && !target4->unknown457cf0() && unknown5d1390() == type6->unknown44 - 9)
									xs_parts->unknown8993e0(part1,false);
							}
						}
						for (unsigned int i = 0; i < ids.size(); i++)
							xs_OpS8b_Fn9d51d0(xs_scrapLists[slot],ids[i]);
						xs_cmap->unknown49abf0();
						xs_scrapEngineNextTurn = xs_world->getTurn() + xs_scrapUpgradeDelay.randomInRange_40c130();
						return;
					}
				}
			}
		}
	}
}
