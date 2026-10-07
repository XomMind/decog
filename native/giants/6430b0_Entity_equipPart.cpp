// 0x6430b0 Entity::equipPart (COGMIND.exe Beta 17.1, 0xa446 bytes): semantic reconstruction, not byte-matched.
// int Entity::equipPart(HItem item, bool update, int extra): applies everything that happens when a part is attached
// (tutorial hints, statistics/achievements, single-use effects 0x7e-0x93, faulty/overloaded side effects, UI refresh).
// Notes, open questions and gdiff numbers: docs/giants/6430b0.md.
// NOTE: class layouts below are partial; members are listed in offset order with their 32-bit offsets in comments.
// Names are placeholders unless stated otherwise; callees keep their csv names.
#include <cstdlib>
#include <string>
#include <vector>
#include "util/rng.h"
using namespace std;

//==================================================================
// Declarations
//==================================================================

struct Point
{
	int x;
	int y;

	Point();								// 0x453b40 (-1,-1)
	Point(int v);							// 0x409990 (v,v)
	Point(int x_, int y_);					// 0x46ca20
	Point(const Point &p);					// 0x46ca50
	Point &operator=(const Point &p);		// 0x46ca50 (folded with the copy ctor)
	bool operator==(const Point &p) const;	// 0x409b90
};

struct Range	// NOTE: placeholder name
{
	int min;
	int max;

	Range();							// 0x40bef0 (0,0)
	Range(int min_, int max_);			// 0x46ca20
	void set(int min_, int max_);		// 0x40a010
	int randomInRange_40c130();			// NOTE: placeholder name
	bool contains_40c190(int value);	// NOTE: placeholder name (min <= value <= max)
};

struct Area	// NOTE: placeholder name
{
	Point min;	// +0x0
	Point max;	// +0x8

	Area();							// 0x40b100
	void randomPoint(Point *out);	// NOTE: placeholder name (0x40be30)
};

struct Rect	// NOTE: placeholder name (16 bytes)
{
	int x;		// +0x0
	int y;		// +0x4
	int width;	// +0x8
	int height;	// +0xc

	void set(int x_, int y_, int width_, int height_);	// NOTE: placeholder name (0x40a840)
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;
public:
	int getWidth();									// 0x9fcd80
	int getHeight();								// 0x9b8f00
	T &operator()(const Point &p);					// 0x9ced70
	T &operator()(int x, int y);					// 0x9ceda0
	void getBounds(const Point &p, int radius, Area *out);	// NOTE: placeholder name (0x9b4430)
};

class Entity;
class Item;
class Prop;
class Group;
class Marker;
struct Location;
struct EntityEffect;	// NOTE: opaque here (0x45ac40 result)

class HEntity
{
	int	ID;
public:
	HEntity();								// 0x9b6590
	bool isNull() const;					// 0x9b65d0
	bool isValid() const;					// 0x9b7230
	Entity *operator->() const;				// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;	// 0x9b6510
};

class HItem
{
	int	ID;
public:
	HItem();								// 0x9b6590
	bool isNull() const;					// 0x9b65d0
	bool isValid() const;					// 0x9b7230
	Item *operator->() const;				// 0x9b65b0
	bool operator==(HItem other) const;		// 0x9b78e0
};

class HProp
{
	int	ID;
public:
	HProp();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	Prop *operator->() const;				// 0x9b64f0
};

class HGroup
{
	int	ID;
public:
	Group *operator->() const;				// 0x9b7250
};

class HMarker	// NOTE: placeholder layout
{
	int	ID;
};

class HLocation	// NOTE: placeholder name (also the world map nodes)
{
	int	ID;
public:
	Location *operator->() const;			// 0x9b7910
};

class HRecord	// NOTE: placeholder name (handle returned by GM::createA, 0x7930e0)
{
	int	ID;
};

struct Location	// NOTE: placeholder name (world map node)
{
	int		unknown00;
	int		type;		// +0x04, NOTE: placeholder name (map type)
	bool	unknown26;	// +0x26
};

class Group
{
public:
	vector<HEntity> &unknown416f40();	// NOTE: placeholder name (ICF'd, returns this+0x0c: the members)
	int unknown9b4350();				// NOTE: placeholder name (ICF'd trivial getter of +0x08, the group type)
};

struct EntityData	// NOTE: placeholder name (robot definition)
{
	int		ID;		// +0x00
	int		size;	// +0x9c, NOTE: placeholder name
};

struct ItemData	// NOTE: placeholder name (item type definition)
{
	int			unknown44;	// +0x44
	bool		unknown76;	// +0x76
	int			unknown94;	// +0x94
	int			unknown190;	// +0x190 (effect animation)
	int			unknown194;	// +0x194 (effect animation when blocked)
	EntityData	*unknown1a0;	// +0x1a0
	bool		unknown1ac;	// +0x1ac

	string getPrefixedName(int *length);		// 0x456fd0 NOTE: placeholder name
	bool unknown56fae0(vector<int> &out);		// NOTE: placeholder name
	void unknown56fc30(vector<int> &out);		// NOTE: placeholder name (resistance modifiers per damage type)
};

struct ItemEffect	// NOTE: placeholder name
{
	int		type;
	int		state;

	ItemEffect(int type_, int state_);	// 0x46ca20
};

class Item
{
public:
	int unknown9fcd80();				// NOTE: placeholder name (ICF'd trivial getter of +0x00)
	ItemData *unknown9b4350();			// NOTE: placeholder name (ICF'd trivial getter of +0x08, the type)
	int unknown44aec0();				// NOTE: placeholder name (ICF'd trivial getter of +0x0c)
	int unknown9b6bf0();				// NOTE: placeholder name (ICF'd trivial getter of +0x1c, integrity)
	bool unknown415ee0();				// NOTE: placeholder name (ICF'd trivial getter of +0x20, faulty)
	bool unknown457db0();				// NOTE: placeholder name (+0x24 != 0, overloaded)
	int unknown457dd0();				// NOTE: placeholder name (ICF'd trivial getter of +0x24)
	int unknown45cb30();				// NOTE: placeholder name (ICF'd trivial getter of +0x44)
	void unknown44fc60(int value);		// NOTE: placeholder name (ICF'd setter of +0x44)
	int unknown457820();				// NOTE: placeholder name (type ID)
	const string &unknown457860();		// NOTE: placeholder name (type name, data->+0x08)
	int unknown457880();				// NOTE: placeholder name
	int unknown4578a0();				// NOTE: placeholder name
	bool unknown457ad0();				// NOTE: placeholder name
	ItemEffect *getEffect(int type);	// NOTE: placeholder name (0x457b70)
	int getEffectValue(int type);		// NOTE: placeholder name (0x457be0)
	int unknown457c80();				// NOTE: placeholder name (maximum integrity)
	int unknown457ca0();				// NOTE: placeholder name (integrity percent)
	int unknown457e10();				// NOTE: placeholder name
	int unknown457f90();				// NOTE: placeholder name (effect type)
	int unknown457fb0();				// NOTE: placeholder name (effect value)
	int unknown457fd0();				// NOTE: placeholder name
	bool unknown457ff0();				// NOTE: placeholder name
	void unknown458310(int amount);		// NOTE: placeholder name (damage, leaving at least 1)
	void unknown458360(int amount);		// NOTE: placeholder name (repair)
	void unknown458460();				// NOTE: placeholder name (clears +0x24)
	void unknown458480();				// NOTE: placeholder name (+0x38 counter)
	void addEffect(ItemEffect *effect);	// NOTE: placeholder name (0x4585a0)
	void unknown4585c0(int type);		// NOTE: placeholder name (removes an effect)
	int unknown577fb0();				// NOTE: placeholder name (getEffectValue(0x6b))
	void unknown579170(int value);		// NOTE: placeholder name (sets +0x0c, notifies the world)
	void setActive(bool active);		// 0x5791a0
	void setBroken(int turn, bool flag);	// 0x5795b0
	void unknown57a0f0(const Point *p, int a, int b);	// NOTE: placeholder name (drop at p)
	void unknown57ab10(int amount, int a, int b, int c, HEntity source, int d, int e);	// NOTE: placeholder name (damage)
	void unknown57c230(Item *source);	// NOTE: placeholder name (copies state from source)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name (detach/destroy)
	string getName(int a, int b);		// NOTE: placeholder name (0x571db0)
};

struct PropType	// NOTE: placeholder name (prop type definition)
{
	bool	unknown78;	// +0x78
};

struct Machine	// NOTE: placeholder name (object returned by Prop::unknown45cb30)
{
	int		unknown3c;	// +0x3c
};

class Prop
{
public:
	PropType *unknown9b8f00();			// NOTE: placeholder name (ICF'd getter, +0x4, the type)
	int unknown457b10();				// NOTE: placeholder name (ICF'd getter, +0x3c)
	Machine *unknown45cb30();			// NOTE: placeholder name (ICF'd getter, +0x44)
	void unknown45cc50(const Point &p);	// NOTE: placeholder name (sets the position)
	void unknown45ce10(bool a, bool b, bool c, HEntity d);	// NOTE: placeholder name
};

class Cell
{
public:
	HEntity getEntity();				// 0x45d250
	HProp getProp();					// 0x45d550
	HItem getItem();					// 0x45d8f0
	bool unknown45db70();				// NOTE: placeholder name
	bool unknown45df50(HProp prop);		// NOTE: placeholder name (sets the prop, returns true)
	bool canPlaceEntity(int size);		// 0x66ad20
};

struct Cartographer2DMoveCost;
class Cartographer2D
{
public:
	bool findPath(const Point &from, const Point &to, Cartographer2DMoveCost *moveCost, void *data, vector<Point> &path);	// 0x40c9a0
};

class Entity
{
public:
	HEntity			self;		// +0x04
	EntityData		*data;		// +0x08
	string			label;		// +0x0c, NOTE: placeholder name
	HGroup			group;		// +0x28
	vector<Point>	footprint;	// +0x30
	int				unknown8c;	// +0x8c (core integrity)
	int				unknown90;	// +0x90
	int				unknown94;	// +0x94
	int				unknownB0;	// +0xb0
	vector<HItem>	parts;		// +0x134

	int equipPart(HItem item, bool update, int extra);	// 0x6430b0

	bool isPlayer();							// 0x5c7600
	const string &getName();					// 0x45a280
	const string &getLabel();					// NOTE: placeholder name (0x416f40, returns this+0x0c)
	int getFaction();							// 0x45a2c0
	int getSize();								// 0x45a360
	HGroup getGroup();							// 0x45a3f0
	const Point &getPosition();					// 0x45a4a0
	Point unknown45a4c0();						// NOTE: placeholder name
	int getTarget();							// NOTE: placeholder name (0x45a760, returns +0x70)
	int unknown45a810();						// NOTE: placeholder name
	int getSlotTotal();							// 0x45a860
	bool isHostileTo(HEntity e);				// 0x45aa70
	EntityEffect *unknown45ac40(int type);		// NOTE: placeholder name
	void unknown45b090(int value);				// NOTE: placeholder name (ICF'd setter)
	void unknown45b0b0();						// NOTE: placeholder name
	void unknown45b1b0(int value);				// NOTE: placeholder name (decreases +0x90)
	void unknown45b1e0(int value);				// NOTE: placeholder name (decreases +0x94)
	void unknown45b210(int value);				// NOTE: placeholder name
	void unknown45b360(int type);				// NOTE: placeholder name (removes an effect)
	int unknown448fe0(int slotType);			// NOTE: placeholder name (ICF'd, slot count at +0x78)
	int unknown490840();						// NOTE: placeholder name (ICF'd trivial getter of +0x8c)
	int unknown5c8db0();						// NOTE: placeholder name
	void unknown5c94e0(int slotType, HItem item);	// NOTE: placeholder name (adds a slot)
	int unknown5ca260();						// NOTE: placeholder name (maximum core integrity)
	int unknown5ca400();						// NOTE: placeholder name
	int unknown5ca670();						// NOTE: placeholder name
	int unknown5cb760();						// NOTE: placeholder name
	int unknown5cb7a0();						// NOTE: placeholder name
	unsigned int unknown5cb8b0(vector<HItem> *out);	// NOTE: placeholder name
	unsigned int unknown5cb930(vector<HItem> *out);	// NOTE: placeholder name
	int unknown5d2090(int type);				// NOTE: placeholder name
	HItem unknown5d2380(int type);				// NOTE: placeholder name
	int unknown5dc440(HItem item);				// NOTE: placeholder name
	int unknown5dc700(HItem item);				// NOTE: placeholder name
	void changeFaction(HGroup newGroup, bool flag);	// 0x5dc780
	void changePos(const Point &p, bool flag);	// 0x5dccb0
	void unknown5de870(int amount, bool linked);	// NOTE: placeholder name (core repair)
	void unknown5dea60(int amount, bool linked);	// NOTE: placeholder name (sets core integrity)
	int unknown5defa0(int amount, bool notify);	// NOTE: placeholder name
	void unknown5fd550(HItem item, int turns);	// NOTE: placeholder name
	void unknown602ec0(vector<Rect> &rects);	// NOTE: placeholder name
	void unknown63a3e0(int a, HItem item);		// NOTE: placeholder name
	void unknown642940(HItem item, bool a, bool b, bool c, int d);	// NOTE: placeholder name
};

class Map	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HEntity getPlayer();						// NOTE: placeholder name (0x4630f0)
	HEntity getEntity671();						// NOTE: placeholder name (0x463110)
	bool unknown463190(int x, int y);			// NOTE: placeholder name (isVisible(x,y))
	bool isVisible(const Point &p);				// NOTE: placeholder name (0x4631c0)
	bool unknown4631f0(HEntity e);				// NOTE: placeholder name
	bool unknown463380(int x, int y);			// NOTE: placeholder name
	bool unknown463510(HEntity e);				// NOTE: placeholder name
	bool unknown4635c0(HEntity e);				// NOTE: placeholder name
	void unknown463770(bool value);				// NOTE: placeholder name
	HGroup unknown463890(int i);				// NOTE: placeholder name
	vector<vector<HMarker> > *unknown463ec0();	// NOTE: placeholder name
	int &unknown4640c0();						// NOTE: placeholder name
	int &unknown4640e0();						// NOTE: placeholder name
	int getTurn();								// 0x464270
	bool unknown464350();						// NOTE: placeholder name
	void clearPoints7d0();						// NOTE: placeholder name (0x4656b0)
	vector<vector<Point> > *unknown459070();	// NOTE: placeholder name
	HItem unknown6c5400(ItemData *type, const Point &p);	// NOTE: placeholder name (creates an item)
	void unknown6c65a0(HEntity e, const string &name, int value);	// NOTE: placeholder name
	int unknown7151c0();						// NOTE: placeholder name
	HEntity unknown715230(int group, int faction);	// NOTE: placeholder name
	bool unknown71bc10(const Point &p, Point *out);	// NOTE: placeholder name
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name (0x71c150)
	void unknown71cf70();						// NOTE: placeholder name
	void opw3_unknown72e4c0(HEntity e, bool flag);	// NOTE: placeholder name
	void opw3_unknown72ea10();					// NOTE: placeholder name
	void opw3_unknown72ec60();					// NOTE: placeholder name
	void unknown734560(HEntity e, int a, vector<unsigned int> *types);	// NOTE: placeholder name
	void unknown747060(const Point &center, int radius, int effect);	// NOTE: placeholder name
	HRecord addRecord(HRecord h);				// NOTE: placeholder name (0x777a20)
};

class MapView	// NOTE: placeholder name (0xcec054)
{
public:
	void unknown44e360(HItem item);			// NOTE: placeholder name (ICF'd setter of +0xcc)
	int unknown8054b0(bool flag);			// NOTE: placeholder name
	void unknown8069e0(Point p, bool flag);	// NOTE: placeholder name
};

class ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);			// NOTE: placeholder name
};

class CLogMsgs
{
public:
	void scrollToEnd();						// 0x7b4f10
};

class CPart
{
public:
	int unknown416230();					// NOTE: placeholder name (ICF'd trivial getter of +0x7c, slot type)
	void unknown49ac50();					// NOTE: placeholder name (clears the +0x74 handle)
	void drawStatus(bool damaged);			// NOTE: placeholder name (0x4a8e70)
	void unknown4a9120();					// NOTE: placeholder name (Calls_4a9120::delegate)
	HItem unknown4aeed0();					// NOTE: placeholder name (ICF'd, handle at +0x6c)
	HItem unknown4b1b30();					// NOTE: placeholder name (ICF'd, handle at +0x74)
	void unknown890710(int a);				// NOTE: placeholder name
};

class CParts
{
public:
	vector<CPart *> &unknown4a9ad0();		// NOTE: placeholder name (ICF'd, returns this+0x74)
	CPart *unknown894e70(HItem item);		// NOTE: placeholder name
	void unknown896ab0(int type);			// NOTE: placeholder name
	void unknown896c20(int type);			// NOTE: placeholder name
	void unknown897290(HItem item, int extra);	// NOTE: placeholder name
};

class CInventory
{
public:
	void reopen(int mode, HItem item);		// 0x8a2ce0
};

class SceneConsole	// NOTE: placeholder name (0xcec118)
{
public:
	bool isHidden();						// 0x4175f0
	void unknown8b4500(HEntity a, HEntity b, HEntity c, const Point &p, int d, int e);	// NOTE: placeholder name
};

class Obj_cec138	// NOTE: placeholder name (pointer at 0xcec138)
{
public:
	void unknown965c10(int a, bool b, bool c);	// NOTE: placeholder name
	void unknown9675f0();					// NOTE: placeholder name
};

class EffectInstance	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class EffectMgr	// NOTE: placeholder name
{
public:
	EffectInstance *create();				// NOTE: placeholder name (0x508610)
};

class Obj515ca0	// NOTE: placeholder name; 0x40 bytes in the exe, layout not reconstructed
{
public:
	Obj515ca0(HEntity a, EntityData *type, const Point &pos, HEntity b, const Point &c, const Point &d);	// 0x515ca0
};

class GM	// NOTE: placeholder name (0xcefaa8)
{
public:
	HRecord createA(Obj515ca0 *record);		// NOTE: placeholder name (0x7930e0)
	HProp createE(PropType *type);			// NOTE: placeholder name (0x793360)
	bool showOnce(int id, bool enabled, const string *text, bool repeat, bool flag);	// NOTE: placeholder name (0x793450)
	void unknown793690();					// NOTE: placeholder name
	void unknown78c260(int a, int b, int c, int d, int e);	// NOTE: placeholder name (csv: GM::serialize)
};

class Gallery	// NOTE: placeholder name (0xd25628)
{
public:
	void addItemAttachCount(int itemID, int count, bool force);	// 0x778560
};

class PlayerData	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool isSlotEmpty(unsigned int index);	// NOTE: placeholder name (0x46de40); true while achievement <index> is not earned
	void unknown46df70();					// NOTE: placeholder name (Calls_46df70::delegate)
	void unknown77fbc0(int id);				// NOTE: placeholder name; earns achievement <id>
	bool unknown77ffb0(int typeID, bool known);	// NOTE: placeholder name (marks an item type known, true the first time)
	bool hasCompanion();					// NOTE: placeholder name (0x780790)
};

class CompanionData	// NOTE: placeholder name (pointer at 0xcf4ac8)
{
public:
	void upgrade(int a, int level);			// 0x7aba60
};

struct StatSet	// NOTE: placeholder name (OpR1h_StatSet)
{
	vector<int>	values;	// +0x00, NOTE: placeholder name
};

class OpR1h_Stats	// NOTE: placeholder name (0xd2c658)
{
public:
	StatSet		*current;	// +0x00

	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
	void add472b90(unsigned int id, int value);	// NOTE: placeholder name (0x472b90)
};

class GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	const string &getEntryText(const string &key);			// NOTE: placeholder name (0x46f6d0)
	void setEntryText(const string &key, const string &text);	// NOTE: placeholder name (0x46f700)
	void unknown783ae0(int a);								// NOTE: placeholder name
};

class IntGrid	// NOTE: placeholder name (OpS7_IntGrid2)
{
public:
	void init_9cf690(int width, int height, int fill);	// NOTE: placeholder name
};

class Audio	// NOTE: placeholder name (0xd25450)
{
public:
	bool	enabled;		// +0x00
	int		unknown98;		// +0x98
	int		unknownA0;		// +0xa0

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
	void unknown69ea20(bool flag);			// NOTE: placeholder name
	bool unknown69eba0(HItem item);			// NOTE: placeholder name
	void unknown69ec90();					// NOTE: placeholder name
	void unknown69ecb0(int id);				// NOTE: placeholder name
};

class SoundMgr	// NOTE: placeholder name (0xd2d2a0)
{
public:
	void unknown454540();					// NOTE: placeholder name
	void unknown500010();					// NOTE: placeholder name
};

class OpS2_PhraseTextB	// NOTE: placeholder name
{
public:
	OpS2_PhraseTextB(int index, string *a, string *b, string *c, HEntity d, HEntity e);	// 0x510f80
};

class MessageLog	// NOTE: placeholder name (0xcf1080)
{
public:
	int push(OpS2_PhraseTextB *text);		// NOTE: placeholder name (0x5121f0)
};

class RolledValues	// NOTE: placeholder name (OpW5_RolledValues, pointer at 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);	// 0x49e250
};

class Obj49b870	// NOTE: placeholder name (0xd1d9c0)
{
public:
	void reset();							// NOTE: placeholder name (0x49b870)
};

struct Obj_d39f1c	// NOTE: placeholder name (elements of the vector at 0xd39f1c)
{
	bool	unknown30;	// +0x30
};

bool unknown5111e0(int id, const string *text1, const string *text2, const string *text3, HEntity subject, HEntity object, const Point *pos, int extra);	// NOTE: placeholder name (show message)
void unknown5141b0(int id, const string *a, const string *b, int c, HEntity e, int d);	// NOTE: placeholder name (history/log record)
void opR1d_4541b0(int sound, int a, int b);	// NOTE: placeholder name (play sound)
void opW5_message(int type, HEntity entity, const string &text, int flag);	// NOTE: placeholder name (0x49c610)
void unknown789ac0();						// NOTE: placeholder name
void logError(string location, string message);	// 0x404f10
string intToString(int value);				// 0x4051f0
string OpY1_intToStringSigned(int value);	// NOTE: placeholder name (0x405560)
int stringToInt(const string &s);			// NOTE: placeholder name (0x405610)
string opw8_countString(int count, const string &noun);	// NOTE: placeholder name (0x407a80)
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
int minInt(int a, int b);					// 0x9cdb30
int maxInt(int a, int b);					// 0x9cdb60
void opw8_atLeast(int *value, int minimum);	// NOTE: placeholder name (0x9cf5c0)
void opw8_increase(int *value, int amount, int maximum);	// NOTE: placeholder name (0x9d06d0)
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (low <= value <= high)
bool containsInt(vector<int> &values, int value);	// NOTE: placeholder name (0x9db330)
void OpV4c_Fn9d5460(vector<Point> &v, unsigned int index, Point p);	// NOTE: placeholder name (insert at index)
void OpC_findNodes_470400(HLocation node, vector<HLocation> &matches, vector<HLocation> &visited);	// NOTE: placeholder name
void removeVectorElement(vector<int> &v, int index);	// NOTE: placeholder name (0x9de6f0)
template <class T> bool OpU8a_containsEntity(vector<T> &v, T e);	// NOTE: placeholder name (0x9d31e0, handle vectors)
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&out);	// NOTE: placeholder name (0x9d7710 props, 0x9d7a40 items)
template <class T> T OpU8a_randomRec(vector<T> &v);			// NOTE: placeholder name (0x9d5d00, random element)
template <class T> int OpQ5_randomIndex(vector<T> &v);		// NOTE: placeholder name (0x9d9b20)
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9da940)
template <class T> void eraseStep(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440, erases and steps i back)
template <class T> void shuffle(vector<T> &v);				// NOTE: placeholder name (0x9d9fc0)
template <class T> T OpX5_randomRecord(vector<T> &v);		// NOTE: placeholder name (0x9dafb0, random element)
template <class T> T OpS8c_popRandom(vector<T> &v);			// NOTE: placeholder name (0x9d8030, removes a random element)

extern RNG						rng;				// 0xd30908
extern Map						*world;				// 0xcefc4c
extern EffectMgr				*effectMgr;			// 0xcefc50
extern Point					effectOrigin;		// 0xd2e20c
extern Array2D<Cell *>			cells;				// 0xcfd44c
extern Cartographer2D			pathfinder;			// NOTE: placeholder name (0xcfe568)
extern Cartographer2DMoveCost	*moveCost;			// NOTE: placeholder name (0xcefc30)
extern GM						*gm;				// 0xcefaa8
extern Gallery					gallery;			// NOTE: placeholder name (0xd25628)
extern PlayerData				playerData;			// 0xcf45d8
extern CompanionData			*companion;			// NOTE: placeholder name (0xcf4ac8)
extern OpR1h_Stats				stats;				// 0xd2c658
extern MessageLog				messageLog;			// 0xcf1080
extern MapView					*mapView;			// 0xcec054
extern ConsoleA					*consoleA;			// 0xcec058
extern CLogMsgs					*logMsgs;			// 0xcec0b4
extern CParts					*cparts;			// 0xcec088
extern CInventory				*cinventory;		// NOTE: placeholder name (0xcec08c)
extern SceneConsole				*sceneConsole;		// NOTE: placeholder name (0xcec118)
extern Obj_cec138				*unknownCec138;
extern Audio					audio;				// 0xd25450
extern SoundMgr					soundMgr;			// NOTE: placeholder name (0xd2d2a0)
extern RolledValues				*rolledValues;		// 0xcefb48
extern GameData					gameData;			// 0xd1e860
extern HLocation				location;			// 0xd1e888
extern HLocation				unknownD1e884;		// world map root node
extern IntGrid					unknownD1e970;
extern Obj49b870				unknownD1d9c0;
extern vector<PropType *>		propTypes;			// NOTE: placeholder name (0xcf35b0)
extern vector<ItemData *>		itemTypes;			// NOTE: placeholder name (0xd2d1c4)
extern vector<EntityData *>		entityRecords;		// NOTE: placeholder name (0xd25de0)
extern vector<int>				effectTypes;		// 0xd2f0f8
extern vector<Obj_d39f1c *>		unknownD39f1c;
extern string					damageTypeNames[];	// 0xd323f8, NOTE: placeholder name
extern string					slotTypeNames[];	// 0xd378d0, NOTE: placeholder name
extern int						pairedPartTypes[];	// 0xba32f8, NOTE: placeholder name (indexed by effect type)
extern bool						mildMalfunctions[];	// 0xba3ab4, NOTE: placeholder name
extern int						resistances[];		// 0xcf4984, NOTE: placeholder name (per damage type)
extern vector<int>				pairedPartShown;	// 0xd22590, NOTE: placeholder name
extern vector<int>				attachedItems;		// 0xcf47cc, NOTE: placeholder name (item IDs ever attached)
extern int						unknownCf47c0;		// core modifications counter
extern vector<int>				unknownCf4810;
extern vector<int>				unknownCf4820;
extern vector<int>				unknownCf4830;		// per item type
extern int						unknownCf4840;
extern vector<int>				unknownCf4844;		// per item type
extern int						unknownCf4854;
extern vector<int>				unknownCf4858;
extern vector<int>				unknownCf4868;
extern vector<int>				unknownCf4878;
extern vector<int>				unknownCf4888;		// per robot type
extern int						unknownCf4898;
extern vector<int>				unknownCf489c;
extern vector<int>				unknownCf48ac;
extern vector<int>				unknownCf48bc;
extern vector<int>				unknownCf48cc;		// per item type
extern int						unknownCf48dc;
extern vector<int>				unknownCf48e0;
extern vector<int>				unknownCf48f0;
extern vector<int>				unknownCf4900;
extern vector<int>				unknownCf4910;		// per robot type
extern int						unknownCf4920;
extern int						unknownCf4954;
extern int						unknownCf496c;
extern int						unknownCf4970;
extern int						unknownCf4974;
extern int						unknownCf4978;
extern int						unknownCf497c;		// integrated mediator installed
extern bool						unknownCf4980;
extern int						unknownCf49d8;
extern int						unknownCf49dc;
extern int						unknownCf49e0;
extern bool						unknownCf49e4;
extern bool						unknownCf49f0;
extern int						unknownCf49f4;
extern int						unknownCf49f8;
extern int						unknownCf49fc;
extern bool						unknownCf4a00;
extern vector<int>				unknownCf4a04;
extern vector<int>				unknownCf4a14;
extern int						unknownCf4a34;
extern int						unknownCf4d1c;		// teleport counter (achievement 0x133 at 10)
extern vector<int>				unknownD01be8;
extern HItem					unknownD2d504;
extern bool						unknownD28d09;
extern bool						unknownD28d4c;
extern int						unknownD28d68;
extern int						unknownB95fb4;		// returned time (100)
extern const int				unknownB960f0;		// 0xb960f0 NOTE: placeholder name (200)
extern const int				unknownB960fc;		// NOTE: placeholder name (500)

// message to the main log (0xcec0b4)
#define MESSAGE(id,text1,text2,text3,subject,object,pos,extra) \
	do \
	{ \
		if (unknown5111e0(id,text1,text2,text3,subject,object,pos,extra)) \
			consoleA->unknown8758d0(true); \
		logMsgs->scrollToEnd(); \
	} while (0)
// phrase without arguments pushed to the message log
#define PHRASE(id) \
	do \
	{ \
		if (messageLog.push(new OpS2_PhraseTextB(id,NULL,NULL,NULL,HEntity(),HEntity()))) \
			consoleA->unknown8758d0(true); \
		logMsgs->scrollToEnd(); \
	} while (0)
#define HISTORY(id,a,b,c,e,d) unknown5141b0(id,a,b,c,e,d)
// the part cannot be used: message, restore +0x0c, back to the floor or the inventory, return 0
#define REJECT_PART(id) \
	{ \
		MESSAGE(id,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0); \
		item->unknown579170(oldUnknown0C); \
		if (unknown45a810() < 0) \
			item->unknown57a0f0(&getPosition(),0,1); \
		else cinventory->reopen(4,HItem()); \
		return 0; \
	}

//==================================================================
// Entity::equipPart
//==================================================================

int Entity::equipPart(HItem item, bool update, int extra)
{
	// tutorial hints
	if (isPlayer())
	{
		gm->showOnce(0x1b,unknown5dc440(item) == 0 || unknown5dc700(item) == 0,&item->getName(0,0),false,false);
		gm->showOnce(0x1c,item->unknown9b4350()->unknown1ac,&item->getName(0,0),false,false);
		gm->showOnce(0x1d,item->unknown457f90() == 7,&item->getName(0,0),false,false);
		gm->showOnce(0x1e,item->unknown457e10() != 0 && item->unknown4578a0() == 0,&item->getName(0,0),false,false);
	}

	// first part of a matched pair (pairedPartTypes[type] == 1 or 2) attached: one-time message
	if (unknownD28d09)
	{
		if (pairedPartTypes[item->unknown457f90()] != 0)
		{
			int index = (pairedPartTypes[item->unknown457f90()] != 2) + 0x1f;
			if (pairedPartShown[index] == 0)
			{
				HItem other = unknown5d2380(item->unknown457f90());
				if (other.isValid())
				{
					MESSAGE((index != 0x1f) + 0x34c,&item->getName(0,0),&other->getName(0,0),0,HEntity(),HEntity(),NULL,0);
					opR1d_4541b0(0x22,0,0);
					pairedPartShown[index] = 1;
				}
			}
		}
	}

	int oldUnknown0C = item->unknown44aec0();
	item->unknown579170(item->unknown4578a0());
	if (!world->unknown464350())
	{
		unknown45b1b0(unknown5cb760());
		unknown45b1e0(unknown5cb7a0());
	}

	// player statistics and achievements
	int firstTime = 0;	// NOTE: placeholder name (the exe keeps the bool result in an int)
	if (isPlayer())
	{
		firstTime = playerData.unknown77ffb0(item->unknown457820(),true);
		if (firstTime)
		{
			if (item->unknown9b4350()->unknown94 != 0)
			{
				stats.add4729d0(0x8d,1,string(""),-1);
				playerData.unknown77fbc0(0x11);
				if (stats.current->values[0x8d] == 20)
					playerData.unknown77fbc0(0x12);
			}
		}
		if (item->unknown9b4350()->unknown94 == 3)
		{
			stats.add4729d0(5,1,item->unknown9b4350()->getPrefixedName(NULL),-1);
			playerData.unknown77fbc0(0x13);
			if (stats.current->values[5] == 15)
				playerData.unknown77fbc0(0x153);
		}
		if (!containsInt(attachedItems,item->unknown9fcd80()))
		{
			attachedItems.push_back(item->unknown9fcd80());
			gallery.addItemAttachCount(item->unknown457820(),1,false);
		}
		item->unknown458480();
		if (item->unknown9b4350()->unknown76)
		{
			if (item->getEffect(0x68) == NULL)
			{
				if (!containsInt(unknownCf4810,item->unknown9fcd80()))
				{
					unknownCf4810.push_back(item->unknown9fcd80());
					unknownCf4820.push_back(unknownCf4830[item->unknown457820()] != 0);
					HISTORY(0x2f,&item->getName(0,0),NULL,0,HEntity(),0);
				}
			}
		}
		if (world->unknown4640c0() != 0 && item->unknown4578a0() == 3)
		{
			world->unknown4640c0()--;
			world->unknown4640e0()++;
			if (mapView->unknown8054b0(false) != 0)
			{
				if (world->unknown4640e0() > 0)
					playerData.unknown77fbc0(0x26);
				if (world->unknown4640e0() > 3)
					playerData.unknown77fbc0(0x9e);
			}
		}
		switch (item->unknown457f90())
		{
			case 0xd: playerData.unknown77fbc0(0x81); break;
			case 0x1b: playerData.unknown77fbc0(0x1a6); break;
		}
		if (playerData.isSlotEmpty(0x84) && ((item->unknown457f90() == 0x14 && unknown5d2380(0x15).isValid()) || (item->unknown457f90() == 0x15 && unknown5d2380(0x14).isValid())))
			playerData.unknown77fbc0(0x84);
		if (playerData.isSlotEmpty(0x11f) && item->unknown457860() == "8R-AWN's Boregun")
			playerData.unknown77fbc0(0x11f);
		else if (playerData.isSlotEmpty(0x134) && item->unknown457860() == "Vortex Field Projector")
			playerData.unknown77fbc0(0x134);
		else if (playerData.isSlotEmpty(0x135) && item->unknown457860() == "BFG-9k Vortex Edition")
			playerData.unknown77fbc0(0x135);
	}

	// effects applied when the part is attached
	switch (item->unknown457f90())
	{
		case 0x7c:
		{
			if (stringToInt(gameData.getEntryText(string("installedRif_g"))) == 0)
			{
				MESSAGE(0x29e,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
				opR1d_4541b0(0xa5,0,0);
				item->unknown57dbe0(update,0,1,1);
			}
			else stats.add4729d0(0x375,1,string(""),-1);
			break;
		}
		case 0xd2:
		{
			if (stringToInt(gameData.getEntryText(string("installedRif_g"))) != 0 || stringToInt(gameData.getEntryText(string("zioWasImprinted_g"))) != 0 || stringToInt(gameData.getEntryText(string("warAttackedLocals_g"))) != 0)
			{
				MESSAGE(0x29e,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
				opR1d_4541b0(0xa5,0,0);
				item->unknown57dbe0(update,0,1,1);
			}
			break;
		}
		case 0xb7:
		{
			HISTORY(0x52,NULL,NULL,0,HEntity(),0);
			gm->unknown78c260(0,0,1,0,0);
			MESSAGE(0x115,NULL,NULL,0,self,HEntity(),NULL,0);
			if (item->unknown9b6bf0() == 1)
				mapView->unknown44e360(item);
			break;
		}
		case 0xd4:
		{
			if (isPlayer())
			{
				if (item->unknown9b4350()->unknown56fae0(unknownD01be8) && unknownD2d504.isNull())
					unknownD2d504 = item;
			}
			break;
		}
		case 0x1f:
		{
			if ((unknownCf4a00 && isPlayer()) || location->type == 0x22)
			{
				MESSAGE(0x29e,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
				if (isPlayer())
					opR1d_4541b0(0xa5,0,0);
				item->unknown579170(oldUnknown0C);
				item->unknown57dbe0(update,0,1,1);
			}
			else
			{
				vector<unsigned int> types;
				for (int i = 3; i < 5; i++)
					types.push_back(i);
				world->unknown734560(self,-2,&types);
				item->unknown44fc60(item->unknown457fb0());
				if (isPlayer())
				{
					MESSAGE(0xc2,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
					HISTORY(0x5f,&item->getName(0,0),NULL,0,self,0);
					stats.add4729d0(0x247,1,string(""),-1);
				}
			}
			break;
		}
		default:
		{
			if (!OpT8b_Fn9daf80(0x7e,item->unknown457f90(),0x93))
				break;
			// single-use effects (0x7e-0x93): the part is used up afterwards
			switch (item->unknown457f90())
			{
				case 0x7e:	// dimension slip node
				{
					Point pos(getPosition());
					PropType *nodeType;
					if (OpQ5_findByName(propTypes,string("ARM_Dimension_Slip_Node"),nodeType))
					{
						if (cells(pos)->getProp().isValid() && cells(pos)->getProp()->unknown9b8f00()->unknown78)
							cells(pos)->getProp()->unknown45ce10(true,false,false,HEntity());
						if (cells(pos)->getProp().isValid() || cells(pos)->unknown45db70())
						{
							world->unknown6c5400(item->unknown9b4350(),getPosition());
							PHRASE(0xef);
						}
						else if (cells(pos)->unknown45df50(gm->createE(nodeType)))
						{
							cells(pos)->getProp()->unknown45cc50(pos);
							opR1d_4541b0(199,0,0);
							PHRASE(0xee);
							HISTORY(0x39,NULL,NULL,0,HEntity(),0);
							soundMgr.unknown454540();
							soundMgr.unknown500010();
						}
					}
					break;
				}
				case 0x7f:	// teleport
				{
					Point pos(getPosition());
					Point dest;
					if (unknown8c > 1)
						unknown5dea60((int)(unknown8c * rng.rangeFloat(0.9f,0.95f)),false);
					bool found = false;
					vector<Point> nodes;
					bool inhibited = false;
					PropType *nodeType;
					PropType *inhibitorType;
					if (OpQ5_findByName(propTypes,string("ARM_Dimension_Slip_Node"),nodeType) && OpQ5_findByName(propTypes,string("COM_Teleport_Inhibitor"),inhibitorType))
					{
						for (int x = 0; x < cells.getWidth(); x++)
						{
							for (int y = 0; y < cells.getHeight(); y++)
							{
								if (cells(x,y)->getProp().isValid())
								{
									if (cells(x,y)->getProp()->unknown9b8f00() == nodeType)
										nodes.push_back(Point(x,y));
									else if (cells(x,y)->getProp()->unknown9b8f00() == inhibitorType && cells(x,y)->getProp()->unknown457b10() == 0)
										inhibited = true;
								}
							}
						}
					}
					if (inhibited && item->unknown457fb0() > 0)
					{
						PHRASE(0xf3);
						HISTORY(0x3c,NULL,NULL,0,HEntity(),0);
						if (world->isVisible(footprint[0]))
						{
							for (unsigned int i = 0; i < footprint.size(); i++)
								effectMgr->create()->init(effectMgr,item->unknown9b4350()->unknown194,footprint[i],effectOrigin,NULL,NULL,NULL,9,0);
						}
						if (audio.enabled)
							audio.unknown69e700(0x3c,0,0.0f);
					}
					else
					{
						// nearest reachable slip node first
						if (!nodes.empty())
						{
							vector<Point> sorted;
							if (nodes.size() > 1)
							{
								sorted.push_back(nodes.back());
								nodes.pop_back();
								while (!nodes.empty())
								{
									int distance = OpQ1_distanceCeil_40a3f0(pos,nodes.back());
									if (distance >= OpQ1_distanceCeil_40a3f0(pos,sorted.back()))
										sorted.push_back(nodes.back());
									else
									{
										for (unsigned int i = 0; i < sorted.size(); i++)
										{
											if (distance < OpQ1_distanceCeil_40a3f0(pos,sorted[i]))
											{
												OpV4c_Fn9d5460(sorted,i,nodes.back());
												break;
											}
										}
									}
									nodes.pop_back();
								}
							}
							else sorted = nodes;
							for (unsigned int i = 0; i < sorted.size(); i++)
							{
								dest = sorted[i];
								if (pos == dest || world->findPlaceableNear(dest,dest,1))
								{
									found = true;
									break;
								}
							}
						}
						// otherwise a random destination with a path length in range
						if (!found)
						{
							Range range(abs(item->unknown457fb0()) * 75 / 100,abs(item->unknown457fb0()) * 125 / 100);
							Area area;
							cells.getBounds(pos,range.max,&area);
							int attempts = 0;
							do
							{
								vector<Point> path;
								area.randomPoint(&dest);
								if (cells(dest)->canPlaceEntity(data->size) && pathfinder.findPath(pos,dest,moveCost,NULL,path))
								{
									if (attempts > 500 || range.contains_40c190(path.size()))
									{
										attempts = -1;
										break;
									}
								}
								attempts++;
							}
							while (attempts < 1000);
							if (attempts != -1)
							{
								logError("Entity::equipPart()","Could not find EFFECT_TELEPORT destination within range (" + intToString(range.min) + "-" + intToString(range.max) + ")");
								break;
							}
						}

						// the item on the departure cell is moved away
						Point dropPos;
						if (cells(pos)->getItem().isValid() && world->unknown71bc10(dest,&dropPos))
							cells(pos)->getItem()->unknown57a0f0(&dropPos,0,0);

						// robots teleported along: the stand-in entity, and for negative ranges every non-player robot within 10
						vector<HEntity> others;
						if (world->getEntity671().isValid())
							others.push_back(world->getEntity671());
						if (item->unknown457fb0() < 0)
						{
							Area area;
							cells.getBounds(pos,10,&area);
							for (int x = area.min.x; x <= area.max.x; x++)
							{
								for (int y = area.min.y; y <= area.max.y; y++)
								{
									if (cells(x,y)->getEntity().isValid() && world->unknown463380(x,y) && !cells(x,y)->getEntity()->isPlayer() && !OpU8a_containsEntity(others,cells(x,y)->getEntity()) && cells(x,y)->getEntity()->getFaction() != 0x56 && cells(x,y)->getEntity()->getFaction() != 0x57 && cells(x,y)->getEntity()->getFaction() != 0x58)
										others.push_back(cells(x,y)->getEntity());
								}
							}
						}

						if (audio.enabled && !found)
							audio.unknown69ec90();
						changePos(dest,true);
						unknown45b090(0);
						unknown45b0b0();
						if (isPlayer())
						{
							PHRASE((found ? 1 : 0) + 0xf0);
							HISTORY((found ? 1 : 0) + 0x3a,NULL,NULL,0,HEntity(),0);
							world->unknown71cf70();
						}
						else MESSAGE(0xf2,NULL,NULL,0,self,HEntity(),NULL,0);

						Point otherDest;
						for (unsigned int i = 0; i < others.size(); i++)
						{
							if (world->findPlaceableNear(dest,otherDest,others[i]->getSize()))
							{
								others[i]->changePos(otherDest,true);
								if (others[i]->unknown490840() > 1 && others[i] != world->getEntity671())
									others[i]->unknown5dea60((int)(others[i]->unknown490840() * rng.rangeFloat(0.9f,0.95f)),false);
								if (world->unknown463510(others[i]) || world->unknown4635c0(others[i]))
									world->opw3_unknown72e4c0(others[i],true);
							}
							else eraseStep(others,i);
						}
						world->unknown734560(self,-2,NULL);
						for (unsigned int i = 0; i < others.size(); i++)
							world->unknown734560(others[i],-2,NULL);
						if (group->unknown9b4350() == 0)
						{
							world->opw3_unknown72e4c0(self,true);
							if (isPlayer())
							{
								unknownD1d9c0.reset();
								mapView->unknown8069e0(dest,false);
								stats.add4729d0(0x3fe,1,string(""),-1);
								unknownCf4d1c++;
								if (unknownCf4d1c == 10)
									playerData.unknown77fbc0(0x133);
							}
						}
						if (audio.enabled && !found)
							audio.unknown69ecb0(0x37);
						if (world->isVisible(dest))
						{
							for (unsigned int i = 0; i < footprint.size(); i++)
								effectMgr->create()->init(effectMgr,item->unknown9b4350()->unknown190,footprint[i],effectOrigin,NULL,NULL,NULL,9,0);
						}
						for (unsigned int i = 0; i < others.size(); i++)
						{
							if (world->unknown4631f0(others[i]))
							{
								vector<Point> &otherFootprint = others[i]->footprint;
								for (unsigned int j = 0; j < otherFootprint.size(); j++)
									effectMgr->create()->init(effectMgr,item->unknown9b4350()->unknown190,otherFootprint[j],effectOrigin,NULL,NULL,NULL,9,0);
								if (others[i] == world->getEntity671())
								{
									HEntity hostile;
									for (unsigned int j = 0; j < others.size(); j++)
									{
										if (others[j]->isHostileTo(world->getPlayer()))
										{
											hostile = others[j];
											break;
										}
									}
									// NOTE: dangling else as compiled: the 0x26 line is only reachable when rolledValues is NULL
									if (hostile.isValid())
									{
										if (rolledValues != NULL)
											rolledValues->say(0x27,false,hostile->getLabel());
										else if (rolledValues != NULL)
											rolledValues->say(0x26,false,"");
									}
								}
								else if (others[i]->getFaction() == 0x5b)
								{
									if (others[i]->getGroup()->unknown9b4350() == 9 && location->type == 0x22 && found)
										opW5_message(0x322,others[i],others[i]->getLabel() + ": \"What is this? Where are we now?\"",0);
								}
							}
						}
					}
					if (isPlayer())
						playerData.unknown77fbc0(0x86);
					break;
				}
				case 0x80:	// gain slot
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_GAIN_SLOT, found on " + getName());
					else
					{
						int slotType = rng.rangeInt(0,3);
						bool full = getSlotTotal() > 25;
						bool replaced = false;
						if (full)
						{
							// at the slot limit an empty slot is converted instead
							vector<CPart *> emptySlots;
							vector<CPart *> &slots = cparts->unknown4a9ad0();
							for (unsigned int i = 0; i < slots.size(); i++)
							{
								if (slots[i]->unknown4b1b30().isValid())
									emptySlots.push_back(slots[i]);
							}
							if (!emptySlots.empty())
							{
								CPart *slot = OpU8a_randomRec(emptySlots);
								slot->unknown49ac50();
								slotType = slot->unknown416230();
								slot->unknown4a9120();
								replaced = true;
								full = false;
							}
						}
						if (full)
							MESSAGE(0xf5,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
						else
						{
							if (!replaced)
								unknown5c94e0(slotType,HItem());
							unknownCf47c0++;
							MESSAGE(0xf4,&item->getName(0,0),&slotTypeNames[slotType],0,self,HEntity(),NULL,0);
							HISTORY(0x3d,&item->getName(0,0),&slotTypeNames[slotType],0,HEntity(),0);
							opR1d_4541b0(200,0,0);
							if (slotType == 3 && unknown448fe0(3) > 6)
								playerData.unknown77fbc0(0x8b);
						}
					}
					break;
				}
				case 0x81:	// core regeneration
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_REGENERATION, found on " + getName());
					else
					{
						int amount = minInt(unknown5ca260() - unknown8c,item->unknown457fb0() * unknown5ca260() / 100);
						unknown5de870(amount,false);
						MESSAGE(0xf6,&intToString(amount),NULL,0,self,HEntity(),NULL,0);
						HISTORY(0x3f,&item->getName(0,0),&intToString(amount),0,HEntity(),0);
						opR1d_4541b0(0xc9,0,0);
					}
					break;
				}
				case 0x82:	// redistribute integrity between the core and the parts
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_REDISTRIBUTE_INTEGRITY, found on " + getName());
					else
					{
						bool toCore = unknown8c < unknown5ca260() / 2;
						int amount = item->unknown457fb0();
						int transfers = 0;
						vector<HItem> changed;
						if (toCore)
						{
							vector<HItem> donors;
							vector<int> available;
							for (unsigned int i = 0; i < parts.size(); i++)
							{
								if (parts[i]->unknown44aec0() < 4)
								{
									if (parts[i]->unknown9b6bf0() > parts[i]->unknown457c80() * 0.25f)
									{
										donors.push_back(parts[i]);
										available.push_back(parts[i]->unknown9b6bf0() - (int)(parts[i]->unknown457c80() * 0.25f));
										if (((const vector<int> &)available).back() < amount)
										{
											donors.pop_back();
											available.pop_back();
										}
									}
								}
							}
							while (unknown8c < unknown5ca260() && !donors.empty())
							{
								int index = OpQ5_randomIndex(donors);
								unknown8c++;
								transfers++;
								donors[index]->unknown458310(amount);
								available[index] -= amount;
								if (!OpU8a_containsEntity(changed,donors[index]))
									changed.push_back(donors[index]);
								if (available[index] < 1)
								{
									OpQ5_eraseAt(donors,index);
									removeVectorElement(available,index);
								}
							}
						}
						else
						{
							int excess = (int)(unknown8c - unknown5ca260() * 0.25f);
							vector<HItem> damaged;
							for (unsigned int i = 0; i < parts.size(); i++)
							{
								if (parts[i]->unknown44aec0() < 4)
								{
									if (parts[i]->unknown457ca0() < 100)
										damaged.push_back(parts[i]);
								}
							}
							int repaired = 0;
							while (excess != 0 && damaged.size() != 0)
							{
								int index = OpQ5_randomIndex(damaged);
								unknown8c--;
								excess--;
								transfers++;
								int repair = minInt(amount,damaged[index]->unknown457c80() - damaged[index]->unknown9b6bf0());
								repaired += repair;
								damaged[index]->unknown458360(repair);
								if (!OpU8a_containsEntity(changed,damaged[index]))
									changed.push_back(damaged[index]);
								if (damaged[index]->unknown9b6bf0() == damaged[index]->unknown457c80())
									OpQ5_eraseAt(damaged,index);
							}
							if (isPlayer())
								stats.add4729d0(0x178,repaired,string(""),-1);
						}
						unknown5dea60(unknown8c,false);
						for (unsigned int i = 0; i < changed.size(); i++)
						{
							CPart *part = cparts->unknown894e70(changed[i]);
							if (part != NULL)
								part->drawStatus(false);
						}
						MESSAGE((toCore ? 1 : 0) + 0xf7,&intToString(transfers),NULL,0,self,HEntity(),NULL,0);
						HISTORY((toCore ? 1 : 0) + 0x40,&item->getName(0,0),&intToString(transfers),0,HEntity(),0);
						opR1d_4541b0(0xca,0,0);
					}
					break;
				}
				case 0x83:	// core heat dissipation
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_HEAT_DISSIPATION, found on " + getName());
					else
					{
						unknownCf49dc += item->unknown457fb0();
						unknownCf47c0++;
						MESSAGE(0xf9,&item->getName(0,0),&intToString(item->unknown457fb0()),0,self,HEntity(),NULL,0);
						HISTORY(0x42,&item->getName(0,0),&intToString(item->unknown457fb0()),0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x84:	// core energy generation
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_ENERGY_GENERATION, found on " + getName());
					else
					{
						unknownCf49d8 += item->unknown457fb0();
						unknownCf47c0++;
						MESSAGE(0xfa,&item->getName(0,0),&intToString(item->unknown457fb0()),0,self,HEntity(),NULL,0);
						HISTORY(0x43,&item->getName(0,0),&intToString(item->unknown457fb0()),0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x85:	// core attachment efficiency
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_ATTACHMENT_EFFICIENCY, found on " + getName());
					else
					{
						unknownCf497c = item->unknown457fb0();
						unknownCf47c0++;
						MESSAGE(0xfb,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
						HISTORY(0x44,&item->getName(0,0),NULL,0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x86:	// core matter restoration (once)
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_MATTER_RESTORATION, found on " + getName());
					else
					{
						if (unknownCf4980)
							REJECT_PART(0xfd);
						unknownCf4980 = true;
						unknownCf47c0++;
						MESSAGE(0xfc,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
						HISTORY(0x45,&item->getName(0,0),NULL,0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x87:	// core corruption immunity (once)
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_CORRUPTION_IMMUNITY, found on " + getName());
					else
					{
						if (unknownCf49f0)
							REJECT_PART(0x100);
						unknownCf49f0 = true;
						gameData.setEntryText(string("usedCoreMembrane_g"),string("0"));
						unknownCf47c0++;
						MESSAGE(0xff,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
						HISTORY(0x46,&item->getName(0,0),NULL,0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x88:	// core thermoelectrics (slot type 0x13 only)
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_THERMOELECTRICS, found on " + getName());
					else
					{
						if (item->unknown457880() != 0x13)
							goto notConsumed;
						if (unknownCf49f4 != 0 && unknownCf49f4 <= item->unknown457fb0())
							REJECT_PART(0x102);
						unknownCf49f4 = item->unknown457fb0();
						unknownCf49f8 = item->unknown457fd0();
						unknownCf47c0++;
						MESSAGE(0x101,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
						HISTORY(0x47,&item->getName(0,0),NULL,0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x89:	// core teleportitis
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_TELEPORTITIS, found on " + getName());
					else
					{
						unknownCf49fc++;
						unknownCf47c0++;
						world->opw3_unknown72ec60();
						MESSAGE((unknownCf49fc != 1) + 0x103,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
						HISTORY(0x48,&item->getName(0,0),NULL,0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
						if (audio.enabled)
							audio.unknown69e700(0x3e,firstTime != 0,0.0f);
					}
					break;
				}
				case 0x8a:	// core reset
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_RESET, found on " + getName());
					else
					{
						unknownB0 = 0;
						// parts whose type stays known
						vector<HItem> kept;
						for (unsigned int i = 0; i < parts.size(); i++)
						{
							if (parts[i]->unknown9b4350()->unknown94 == 1)
							{
								if (unknownCf4830[parts[i]->unknown457820()] == 0)
									kept.push_back(parts[i]);
							}
						}
						unknownCf4830.assign(itemTypes.size(),0);
						unknownCf4840 = 0;
						for (unsigned int i = 0; i < parts.size(); i++)
						{
							if (parts[i]->unknown44aec0() < 5)
							{
								if (!OpU8a_containsEntity(kept,parts[i]))
									playerData.unknown77ffb0(parts[i]->unknown457820(),false);
							}
						}
						for (unsigned int i = 0; i < itemTypes.size(); i++)
						{
							if (itemTypes[i]->unknown44 < 6 || itemTypes[i]->unknown94 == 3)
								playerData.unknown77ffb0(i,false);
						}
						for (unsigned int i = 0; i < itemTypes.size(); i++)
						{
							if (unknownCf48cc[i] != 0)
							{
								unknownCf48cc[i] = 0;
								cparts->unknown896ab0(i);
								if (unknownD28d68 == 3)
									cparts->unknown896c20(i);
							}
						}
						unknownCf48dc = 0;
						unknownCf48e0.clear();
						unknownCf48f0.clear();
						unknownCf4900.clear();
						if (unknownD28d68 == 3)
						{
							for (unsigned int i = 0; i < itemTypes.size(); i++)
							{
								if (unknownCf4844[i] != 0)
								{
									unknownCf4844[i] = 0;
									cparts->unknown896c20(i);
								}
							}
						}
						else unknownCf4844.assign(itemTypes.size(),0);
						unknownCf4854 = 0;
						unknownCf4858.clear();
						unknownCf4868.clear();
						unknownCf4878.clear();
						unknownCf4888.assign(entityRecords.size(),0);
						unknownCf4898 = 0;
						unknownCf489c.clear();
						unknownCf48ac.clear();
						unknownCf48bc.clear();
						unknownCf4910.assign(entityRecords.size(),0);
						unknownCf4920 = 0;

						// forget map knowledge
						vector<vector<HMarker> > *markers = world->unknown463ec0();
						for (unsigned int i = 0; i < markers->size(); i++)
							(*markers)[i].clear();
						vector<vector<Point> > *machineCells = world->unknown459070();
						for (unsigned int i = 0; i < machineCells->size(); i++)
						{
							// NOTE: the exe always indexes element 0 here
							for (unsigned int j = 0; j < (*machineCells)[0].size(); j++)
								cells((*machineCells)[0][j])->getProp()->unknown45cb30()->unknown3c = 0;
						}
						gameData.unknown783ae0(0);
						if (unknownCf49e4)
						{
							unknownCf49e4 = false;
							unknownCf49e0 -= 10;
						}
						gameData.setEntryText(string("extAcquiredA7DataCore_g"),string("0"));
						unknownD1e970.init_9cf690(0x13,0x26,0);

						// world map
						vector<HLocation> nodes;
						vector<HLocation> visited;
						OpC_findNodes_470400(unknownD1e884,nodes,visited);
						for (unsigned int i = 0; i < nodes.size(); i++)
							nodes[i]->unknown26 = false;

						// Zionites and allied factions turn hostile again
						vector<HEntity> &group2 = world->unknown463890(2)->unknown416f40();
						if (!group2.empty())
						{
							for (int i = group2.size() - 1; i >= 0; i--)
							{
								if (group2[i]->getName().find("Z_",0) != string::npos)
									group2[i]->changeFaction(world->unknown463890(1),true);
							}
						}
						vector<HEntity> &group5 = world->unknown463890(5)->unknown416f40();
						if (!group5.empty())
						{
							for (int i = group5.size() - 1; i >= 0; i--)
							{
								if (group5[i]->getFaction() == 0x3b || group5[i]->getFaction() == 0x3c || group5[i]->getFaction() == 0x3d || group5[i]->getName().find("Z_",0) != string::npos)
									group5[i]->changeFaction(world->unknown463890(2),true);
							}
						}
						cinventory->reopen(0,HItem());
						if (audio.enabled && firstTime != 0)
							audio.unknown69e700(0x3f,0,0.0f);
						unknownCec138->unknown9675f0();
						vector<Rect> rects(1);
						rects.front().set(0,0,cells.getWidth(),cells.getHeight());
						unknown602ec0(rects);
						world->clearPoints7d0();
						for (unsigned int i = 0; i < unknownD39f1c.size(); i++)
							unknownD39f1c[i]->unknown30 = false;
						if (stringToInt(gameData.getEntryText(string("usedCoreResetMatrix_g"))) == 0)
						{
							stats.add472b90(0x40,-999999);
							HISTORY(0x31,&string("Core Reset Matrix"),NULL,0,HEntity(),0);
							gameData.setEntryText("usedCoreResetMatrix_g",intToString(world->getTurn()));
						}
						gameData.setEntryText(string("installedRif_g"),string("0"));
						unknownCf4a04.assign((unsigned int)0x13,0);
						unknownCf4a14.clear();

						// an attached RIF installer is rejected
						vector<CPart *> &slots = cparts->unknown4a9ad0();
						for (unsigned int i = slots.size() - 1; i != 0; i--)
						{
							if (slots[i]->unknown4aeed0().isValid())
							{
								if (slots[i]->unknown4aeed0()->unknown457f90() == 0x7c)
								{
									MESSAGE(0x29e,&slots[i]->unknown4aeed0()->getName(0,0),NULL,0,self,HEntity(),NULL,0);
									opR1d_4541b0(0xa5,0,0);
									slots[i]->unknown4aeed0()->unknown57dbe0(1,0,8,1);
								}
							}
						}
						world->opw3_unknown72ea10();
						gm->unknown793690();
					}
					break;
				}
				case 0x8b:	// terrabomb
				{
					MESSAGE(0x107,&item->getName(0,0),NULL,0,HEntity(),HEntity(),&getPosition(),0);
					HISTORY(0x31,&string("Terrabomb"),NULL,0,HEntity(),0);
					if (audio.enabled)
						audio.unknown98 = world->unknown7151c0();
					world->unknown747060(getPosition(),item->unknown457fb0(),item->unknown9b4350()->unknown190);
					break;
				}
				case 0x8d:	// applied to the item on the floor below
				{
					HItem target = cells(getPosition())->getItem();
					if (target.isValid())
					{
						if (target->unknown457f90() == 0xb7)
						{
							if (target->getEffectValue(0x6a) != 0)
							{
								MESSAGE(0x10a,NULL,NULL,0,self,HEntity(),NULL,0);
								HISTORY(0x4b,&item->getName(0,0),&target->getName(0,0),0,HEntity(),0);
								if (audio.enabled)
									audio.unknownA0 = target->unknown9b4350()->unknown1a0->ID;
								world->addRecord(gm->createA(new Obj515ca0(self,target->unknown9b4350()->unknown1a0,unknown45a4c0(),HEntity(),Point(-1),Point(-1))));
								target->unknown57dbe0(0,0,1,1);
							}
							else
							{
								MESSAGE(0x10c,&target->getName(0,0),NULL,0,self,HEntity(),NULL,0);
								target->addEffect(new ItemEffect(effectTypes[0x6a],1));
								item->unknown579170(oldUnknown0C);
								return 0;
							}
							break;
						}
						if (target->unknown457f90() == 0xd6)
						{
							if (playerData.hasCompanion() && target->unknown457fb0() != 2)
							{
								companion->upgrade(0,target->unknown457fb0() + 1);
								opR1d_4541b0(0xce,0,0);
								break;
							}
						}
						else
						{
							HItem result;
							bool supercharged = false;
							if (target->unknown457860() == "Sigix Terminator" || target->unknown457860() == "Integrated Dissipator" || target->unknown457860() == "Integrated Reactor" || target->unknown457860() == "Transdimensional Reconstructor" || target->unknown457860() == "Hpw. Transdimensional Reconstructor" || target->unknown457860() == "Cep. Navigation Harness")
							{
								string name("Supercharged ");
								if (target->unknown457860().find("Transdimensional Reconstructor",0) != string::npos)
									name += "TR";
								else if (target->unknown457860().find("Harness",0) != string::npos)
									name += "Navigation Harness";
								else name += target->unknown457860();
								ItemData *type;
								OpQ5_findByName(itemTypes,name,type);
								result = world->unknown6c5400(type,getPosition());
								supercharged = true;
							}
							else result = world->unknown6c5400(target->unknown9b4350(),getPosition());
							if (result.isValid())
							{
								result->unknown57c230(target.operator->());
								if (result->unknown9b4350()->unknown76)
								{
									unknownCf4810.push_back(result->unknown9fcd80());
									unknownCf4820.push_back(unknownCf4830[result->unknown457820()] != 0);
								}
								if (supercharged)
								{
									MESSAGE(0x109,&result->getName(0,0),NULL,0,self,HEntity(),NULL,0);
									HISTORY(0x4a,&item->getName(0,0),&result->getName(0,0),0,HEntity(),0);
									target->unknown57dbe0(0,0,1,1);
									if (result->unknown457f90() == 0xd9)
										playerData.unknown46df70();
								}
								else
								{
									MESSAGE(0x108,&target->getName(0,0),NULL,0,self,HEntity(),NULL,0);
									HISTORY(0x49,&item->getName(0,0),&target->getName(0,0),0,HEntity(),0);
									if (result->unknown457860() == "Sigix Corpse")
									{
										HEntity sigix = world->unknown715230(2,0x5e);
										if (sigix.isValid())
											world->unknown6c65a0(sigix,string("SEC_Sigix_Copy_Corpse"),0);
										else
										{
											for (unsigned int i = 0; i < parts.size(); i++)
											{
												if (parts[i]->unknown457860() == "Sigix Containment Pod")
												{
													world->unknown6c65a0(self,string("SEC_Sigix_Copy_Corpse_P"),0);
													break;
												}
											}
										}
									}
									else if (result->unknown457860() == "Sigix Containment Pod")
										world->unknown6c65a0(self,string("SEC_Sigix_Copy_Pod"),0);
								}
								opR1d_4541b0(0xce,0,0);
								break;
							}
						}
					}
					REJECT_PART(0x10b);
				}
				case 0x8e:	// permanent integrity
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_INTEGRITY, found on " + getName());
					else
					{
						unknownCf4954 += item->unknown457fb0();
						unknown5de870(item->unknown457fb0(),false);
						unknownCf47c0++;
						MESSAGE(0x10d,&item->getName(0,0),&intToString(item->unknown457fb0()),0,self,HEntity(),NULL,0);
						HISTORY(0x4c,&item->getName(0,0),&intToString(item->unknown457fb0()),0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x8f:	// permanent inventory capacity
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_INV_CAPACITY, found on " + getName());
					else
					{
						unknownCf496c += item->unknown457fb0();
						unknownCf47c0++;
						MESSAGE(0x10e,&item->getName(0,0),&intToString(item->unknown457fb0()),0,self,HEntity(),NULL,0);
						HISTORY(0x4d,&item->getName(0,0),&intToString(item->unknown457fb0()),0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x90:	// permanent energy
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_ENERGY, found on " + getName());
					else
					{
						unknownCf4970 += item->unknown457fb0();
						unknownCf47c0++;
						MESSAGE(0x10f,&item->getName(0,0),&intToString(item->unknown457fb0()),0,self,HEntity(),NULL,0);
						HISTORY(0x4e,&item->getName(0,0),&intToString(item->unknown457fb0()),0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x91:	// permanent matter
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_MATTER, found on " + getName());
					else
					{
						unknownCf4974 += item->unknown457fb0();
						unknownCf47c0++;
						MESSAGE(0x110,&item->getName(0,0),&intToString(item->unknown457fb0()),0,self,HEntity(),NULL,0);
						HISTORY(0x4f,&item->getName(0,0),&intToString(item->unknown457fb0()),0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x92:	// permanent support
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_SUPPORT, found on " + getName());
					else
					{
						unknownCf4978 += item->unknown457fb0();
						unknownCf47c0++;
						MESSAGE(0x111,&item->getName(0,0),&intToString(item->unknown457fb0()),0,self,HEntity(),NULL,0);
						HISTORY(0x50,&item->getName(0,0),&intToString(item->unknown457fb0()),0,HEntity(),0);
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x93:	// permanent resistances
				{
					if (!isPlayer())
						logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_RESISTANCE, found on " + getName());
					else
					{
						vector<int> values;
						item->unknown9b4350()->unknown56fc30(values);
						vector<string> changes;
						for (unsigned int i = 0; i < values.size(); i++)
						{
							if (values[i] == 100)
								continue;
							int old = resistances[i];
							resistances[i] += values[i] - 100;
							opw8_atLeast(&resistances[i],0);
							if (resistances[i] != old)
							{
								string change = damageTypeNames[i] + " " + OpY1_intToStringSigned(old - resistances[i]) + "%";
								changes.push_back(change);
							}
						}
						if (changes.empty())
							MESSAGE(0x112,&item->getName(0,0),&string("no effect"),0,self,HEntity(),NULL,0);
						else
						{
							if (item->unknown457880() == 0x13)
								unknownCf47c0++;
							string text = opw8_countString(changes.size(),string("resistance")) + " modified: ";
							text += changes[0];
							for (unsigned int i = 1; i < changes.size(); i++)
							{
								text += ", ";
								text += changes[i];
							}
							MESSAGE(0x112,&item->getName(0,0),&text,0,self,HEntity(),NULL,0);
							HISTORY(0x51,&item->getName(0,0),&text,0,HEntity(),0);
						}
						opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
			}
			// the single-use part is consumed
			item->unknown579170(oldUnknown0C);
			item->unknown57dbe0(update,0,1,1);
		notConsumed:
			break;
		}
	}

	// faulty part (item flag +0x20) or effect 0x60: random malfunction on attach
	if (item.operator->() != NULL)
	{
		if (item->unknown415ee0() || item->getEffect(0x60) != NULL)
		{
			bool fromEffect = !item->unknown415ee0();
			item->unknown4585c0(0x60);
			if (fromEffect)
				MESSAGE(0x138,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
			vector<unsigned int> malfunctions;
			if (fromEffect)
			{
				for (int i = 0; i < 6; i++)
				{
					if (mildMalfunctions[i])
						malfunctions.push_back(i);
				}
			}
			else
			{
				for (int i = 0; i < 6; i++)
					malfunctions.push_back(i);
			}
			if (unknownCf497c != 0 && isPlayer() && unknown94 >= 20 && rng.chance(50))
			{
				MESSAGE(0x139,&string("Integrated Mediator"),NULL,0,self,HEntity(),NULL,0);
				unknown45b1e0(20);
			}
			else
			{
				switch (OpU8a_randomRec(malfunctions))
				{
					case 0:
					{
						if (unknown90 != 0)
						{
							int amount = maxInt(1,rng.rangeInt(25,100) * unknown90 / 100);
							unknown45b1b0(amount);
							MESSAGE(0x13a,&item->getName(0,0),&intToString(amount),0,self,HEntity(),NULL,0);
							opR1d_4541b0(0x5e,0,0);
						}
						break;
					}
					case 1:
					{
						Range count;
						if (fromEffect)
							count.set(1,2);
						else count.set(1,3);
						Range percent;
						if (fromEffect)
							percent.set(10,20);
						else percent.set(20,50);
						MESSAGE(0x13b,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
						item->unknown57dbe0(update,1,1,1);
						int damaged = count.randomInRange_40c130();
						vector<HItem> others;
						if (unknown5cb8b0(&others) != 0)
						{
							shuffle(others);
							bool any = false;
							for (unsigned int i = 0; i < others.size() && (int)i < damaged; i++)
							{
								int integrity = others[i]->unknown9b6bf0();
								if (integrity > 1)
								{
									int damage = maxInt(1,percent.randomInRange_40c130() * integrity / 100);
									MESSAGE(0x13c,&others[i]->getName(0,0),&intToString(damage),0,self,HEntity(),NULL,0);
									any = true;
									others[i]->unknown57ab10(minInt(others[i]->unknown9b6bf0() - 1,damage),1,0,0,HEntity(),0,0);
								}
							}
							if (any)
								opR1d_4541b0(0x5e,0,0);
						}
						break;
					}
					case 2:
					{
						bool reported = false;
						vector<HItem> others;
						if (unknown5cb930(&others) != 0)
						{
							for (int i = others.size() - 1; i >= 0; i--)
							{
								if (others[i]->unknown457ad0() || others[i]->unknown457880() > 0x19 || others[i]->unknown577fb0() != 0 || others[i]->getEffect(0x55) != NULL || others[i]->unknown9b4350()->unknown94 == 2)
									OpQ5_eraseAt(others,i);
							}
							if (!others.empty())
							{
								HItem victim = OpX5_randomRecord(others);
								MESSAGE(0x13e,&victim->getName(0,0),NULL,0,self,HEntity(),NULL,0);
								victim->setBroken(-2,update);
								if (!reported)
								{
									MESSAGE(0x13d,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
									reported = true;
									if (audio.enabled && audio.unknown69eba0(victim))
										audio.unknown69e700(1,0,0.0f);
								}
								opR1d_4541b0(0x5e,0,0);
							}
						}
						break;
					}
					case 3:
					{
						Range percent;
						if (fromEffect)
							percent.set(30,50);
						else percent.set(25,75);
						vector<HItem> others;
						if (unknown5cb8b0(&others) != 0)
						{
							HItem victim = OpX5_randomRecord(others);
							int integrity = victim->unknown9b6bf0();
							if (integrity > 1)
							{
								int damage = maxInt(1,percent.randomInRange_40c130() * integrity / 100);
								MESSAGE(0x13f,&item->getName(0,0),&victim->getName(0,0),&intToString(damage),self,HEntity(),NULL,0);
								opR1d_4541b0(0x5e,0,0);
								victim->unknown57ab10(minInt(victim->unknown9b6bf0() - 1,damage),0,0,0,HEntity(),0,0);
							}
						}
						break;
					}
					case 4:
					{
						bool noHeat = unknownB0 == 0;
						int amount = rng.rangeInt(2,5);
						amount = unknown5defa0(amount,false);
						if (amount != 0)
						{
							MESSAGE(0x140,&item->getName(0,0),&intToString(amount),0,self,HEntity(),NULL,0);
							audio.unknown69ea20(noHeat);
						}
						opR1d_4541b0(0x5e,0,0);
						break;
					}
					case 5:
					{
						int amount = rng.rangeInt(unknownB960f0,unknownB960fc - 1);
						unknown45b210(amount);
						MESSAGE(0x141,&item->getName(0,0),&intToString(amount),0,self,HEntity(),NULL,0);
						opR1d_4541b0(0x5e,0,0);
						break;
					}
				}
			}
		}
	}

	// overloaded part (item +0x24): damage on attach, chance of a side effect
	bool reportAfter = false;	// NOTE: placeholder name
	if (item.operator->() != NULL)
	{
		if (item->unknown457db0())
		{
			if (isPlayer())
			{
				if (unknownCf497c != 0 && unknown94 >= 20 && rng.chance(50))
				{
					MESSAGE(0x139,&string("Integrated Mediator"),NULL,0,self,HEntity(),NULL,0);
					unknown45b1e0(20);
				}
				else
				{
					MESSAGE(0x130,&item->getName(0,0),&intToString(item->unknown457dd0()),0,self,HEntity(),NULL,0);
					int damage = unknown5defa0(item->unknown457dd0(),false);
					if (damage != 0)
					{
						stats.add4729d0(0x8e,1,string(""),-1);
						stats.add4729d0(0x8f,damage,string(""),-1);
						playerData.unknown77fbc0(0x16);
						if (unknownD28d4c)
							unknownCec138->unknown965c10(0x28,false,true);
						int chance = (8 - damage) * 10;
						if (rng.chance(chance))
						{
							int sideEffect = rng.rangeInt(0,4);
							switch (sideEffect)
							{
								case 0:
								{
									bool reported = false;
									vector<HItem> others;
									if (unknown5cb930(&others) != 0)
									{
										for (int i = others.size() - 1; i >= 0; i--)
										{
											if (others[i]->unknown457ad0() || (others[i]->unknown4578a0() != 2 && others[i]->unknown4578a0() != 3))
												OpQ5_eraseAt(others,i);
										}
										if (!others.empty())
										{
											shuffle(others);
											int count = rng.rangeInt(1,minInt(3,others.size()));
											for (int i = 0; i < count; i++)
											{
												HItem part = OpX5_randomRecord(others);
												unknown5fd550(part,rng.rangeInt(8,15));
												if (isPlayer())
												{
													CPart *cpart = cparts->unknown894e70(part);
													if (cpart != NULL)
														cpart->unknown890710(0);
												}
												if (!reported)
												{
													MESSAGE(0x131,NULL,NULL,0,self,HEntity(),NULL,0);
													reported = true;
												}
												MESSAGE(0x132,&part->getName(0,0),NULL,0,self,HEntity(),NULL,0);
											}
										}
									}
									break;
								}
								case 1:
								{
									if (!item->unknown457ad0())
									{
										unknown5fd550(item,rng.rangeInt(50,99));
										if (isPlayer())
										{
											CPart *cpart = cparts->unknown894e70(item);
											if (cpart != NULL)
												cpart->unknown890710(0);
										}
										MESSAGE(0x132,&item->getName(0,0),NULL,0,self,HEntity(),NULL,0);
									}
									break;
								}
								case 2:
								{
									vector<HItem> others;
									if (unknown5cb8b0(&others) != 0)
									{
										for (unsigned int i = 0; i < others.size(); i++)
										{
											if (others[i]->unknown9b4350()->unknown1ac || others[i]->getEffect(0x6e) != NULL || others[i]->getEffect(0x6c) != NULL || others[i]->unknown457f90() == 7 || others[i]->unknown457f90() == 8 || others[i]->unknown457f90() == 9 || others[i]->unknown577fb0() != 0 || others[i] == item)
												eraseStep(others,i);
										}
										if (!others.empty())
										{
											int count = rng.rangeInt(2,3);
											while (count > 0 && !others.empty())
											{
												HItem part = OpS8c_popRandom(others);
												MESSAGE(0x133,&part->getName(0,0),NULL,0,self,HEntity(),NULL,0);
												unknown642940(part,true,true,false,4);
												count--;
											}
										}
									}
									break;
								}
								case 3:
								{
									if (unknown90 != 0)
									{
										int integrity = item->unknown9b6bf0();
										if (integrity > 1)
										{
											int loss = maxInt(1,rng.rangeInt(50,100) * unknown90 / 100);
											unknown45b1b0(loss);
											int current = item->unknown9b6bf0();
											int damage = maxInt(1,rng.rangeInt(20,50) * current / 100);
											item->unknown57ab10(damage,1,0,0,HEntity(),0,0);
											MESSAGE(0x134,&item->getName(0,0),&intToString(damage),0,self,HEntity(),NULL,0);
										}
									}
									break;
								}
								case 4:
								{
									if (item->unknown4578a0() == 3)
										reportAfter = true;
									break;
								}
							}
						}
					}
				}
			}
			item->unknown458460();
		}
	}

	// activation, stored charge, statistics
	if (item.operator->() != NULL)
	{
		if (item->unknown457ad0())
			item->setActive(true);
		if (item->unknown457ff0())
		{
			if (item->unknown45cb30() != 0)
			{
				switch (item->unknown457f90())
				{
					case 8: opw8_increase(&unknown90,item->unknown45cb30(),unknown5ca400()); break;
					case 9: opw8_increase(&unknown94,item->unknown45cb30(),unknown5ca670()); break;
				}
				item->unknown44fc60(0);
			}
		}
		if (item->unknown457f90() == 0x18 || item->unknown457f90() == 0x1a || item->unknown457f90() == 0xd)
			world->unknown463770(true);
		stats.add4729d0(0x70,1,string(""),item->unknown9fcd80());
		switch (item->unknown4578a0())
		{
			case 0:
				stats.add4729d0(0x71,1,string(""),item->unknown9fcd80());
				stats.add4729d0(item->unknown457880() + 0x6c,1,string(""),item->unknown9fcd80());
				break;
			case 1:
				stats.add4729d0(0x75,1,string(""),item->unknown9fcd80());
				stats.add4729d0(item->unknown457880() + 0x6d,1,string(""),item->unknown9fcd80());
				break;
			case 2:
				stats.add4729d0(0x7b,1,string(""),item->unknown9fcd80());
				stats.add4729d0(item->unknown457880() + 0x6e,1,string(""),item->unknown9fcd80());
				break;
			case 3:
				stats.add4729d0(0x82,1,string(""),item->unknown9fcd80());
				stats.add4729d0(minInt(item->unknown457880(),0x1d) + 0x6f,1,string(""),item->unknown9fcd80());
				break;
		}
	}

	if (item.operator->() != NULL && isPlayer())
	{
		switch (item->unknown457f90())
		{
			case 7:
				if (item->unknown457860() == "Lightpack 2.0")
					unknownCf4a34 = unknown5c8db0();
				break;
			case 0x1f:
				gm->unknown793690();
				unknown789ac0();
				opR1d_4541b0(0x55,0,0);
				break;
			case 0x4b:
				if (unknown5d2090(0x4b) > 99)
					playerData.unknown77fbc0(0xd1);
				break;
		}

		// attaching a part in front of watching Scraptown locals
		if (location->type == 0xb && stringToInt(gameData.getEntryText(string("scrAttackedLocals_g"))) == 0)
		{
			Area area;
			cells.getBounds(getPosition(),5,&area);
			for (int x = area.min.x; x <= area.max.x; x++)
			{
				for (int y = area.min.y; y <= area.max.y; y++)
				{
					if (world->unknown463190(x,y))
					{
						if (cells(x,y)->getEntity().isValid() && cells(x,y)->getEntity()->unknown45ac40(0x98) != NULL)
						{
							if (cells(x,y)->getEntity()->getTarget() == 0)
							{
								opW5_message(0x322,cells(x,y)->getEntity(),string("[name]: I am going to pretend I did not see you do that. For my sanity."),0);
								cells(x,y)->getEntity()->unknown45b360(0x98);
							}
							goto witnessed;
						}
					}
				}
			}
		}
	}
witnessed:

	if (update)
	{
		cinventory->reopen(4,HItem());
		if (item.operator->() != NULL)
			cparts->unknown897290(item,extra);
	}
	if (!sceneConsole->isHidden())
		sceneConsole->unknown8b4500(self,HEntity(),HEntity(),Point(-1),0,0);
	if (reportAfter)
		unknown63a3e0(0,item);
	return unknownB95fb4;
}
