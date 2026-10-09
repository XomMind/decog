// 0x6430b0 Entity::equipPart (COGMIND.exe Beta 17.1, 0xa5ac bytes), byte-matched as YkEntity::equipPart.
// Based on Heni's semantic draft (native/giants/6430b0_Entity_equipPart.cpp); all types/externs are private (Yk*/yk_*).
// Covers tutorial hints, statistics/achievements, single-use effects 0x7e-0x93, faulty/overloaded side effects, UI refresh.
// Some local names are odd on purpose: VS2010 /Od orders stack slots by a hash of the local's name (frame layout).
// NOTE: class layouts below are partial; members are listed in offset order with their 32-bit offsets in comments.
// Names are placeholders unless stated otherwise; callees carry their exe addresses in comments.
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
struct YkRng{float rangeFloat(float,float);bool chance(int);int rangeInt(float,float);};

//==================================================================
// Declarations
//==================================================================

struct YkPoint
{
	int x;
	int y;

	YkPoint();								// 0x453b40 (-1,-1)
	YkPoint(int v);							// 0x409990 (v,v)
	YkPoint(int x_, int y_);					// 0x46ca20
	YkPoint(const YkPoint &p);					// 0x46ca50
	YkPoint &operator=(const YkPoint &p);		// 0x46ca50 (folded with the copy ctor)
	bool operator==(const YkPoint &p) const;	// 0x409b90
};

struct YkRange	// NOTE: placeholder name
{
	int min;
	int max;

	YkRange();							// 0x40bef0 (0,0)
	YkRange(int min_, int max_);			// 0x46ca20
	void set(int min_, int max_);		// 0x40a010
	int randomInRange_40c130();			// NOTE: placeholder name
	bool contains_40c190(int value);	// NOTE: placeholder name (min <= value <= max)
};

struct YkArea	// NOTE: placeholder name
{
	YkPoint min;	// +0x0
	YkPoint max;	// +0x8

	YkArea();							// 0x40b100
	void randomPoint(YkPoint *out);	// NOTE: placeholder name (0x40be30)
};

struct YkRect	// NOTE: placeholder name (16 bytes)
{
	int x;		// +0x0
	int y;		// +0x4
	int width;	// +0x8
	int height;	// +0xc

	void set(int x_, int y_, int width_, int height_);	// NOTE: placeholder name (0x40a840)
};

template <class T>
class YkArray2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;
public:
	int getWidth();									// 0x9fcd80
	int getHeight();								// 0x9b8f00
	T &operator()(const YkPoint &p);					// 0x9ced70
	T &operator()(int x, int y);					// 0x9ceda0
	void getBounds(const YkPoint &p, int radius, YkArea *out);	// NOTE: placeholder name (0x9b4430)
};

class YkEntity;
class YkItem;
class YkProp;
class YkGroup;
class YkMarker;
struct YkLocation;
struct YkEntityEffect;	// NOTE: opaque here (0x45ac40 result)

class YkHEntity
{
	int	ID;
public:
	YkHEntity();								// 0x9b6590
	bool isNull() const;					// 0x9b65d0
	bool isValid() const;					// 0x9b7230
	YkEntity *operator->() const;				// 0x9b6570
	bool operator==(YkHEntity other) const;	// 0x9b78e0
	bool operator!=(YkHEntity other) const;	// 0x9b6510
};

class YkHItem
{
	int	ID;
public:
	YkHItem();								// 0x9b6590
	bool isNull() const;					// 0x9b65d0
	bool isValid() const;					// 0x9b7230
	YkItem *operator->() const throw();				// 0x9b65b0
	bool operator==(YkHItem other) const;		// 0x9b78e0
};

class YkHProp
{
	int	ID;
public:
	YkHProp();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	YkProp *operator->() const;				// 0x9b64f0
};

class YkHGroup
{
	int	ID;
public:
	YkGroup *operator->() const;				// 0x9b7250
};

class YkHMarker	// NOTE: placeholder layout
{
	int	ID;
};

class YkHLocation	// NOTE: placeholder name (also the yk_world map nodes)
{
	int	ID;
public:
	YkLocation *operator->() const;			// 0x9b7910
};

class YkHRecord	// NOTE: placeholder name (handle returned by YkGM::createA, 0x7930e0)
{
	int	ID;
};

struct YkLocation	// NOTE: placeholder name (yk_world map node)
{
	int		unknown00;
	int		type;		// +0x04, NOTE: placeholder name (map type)
	int		pad08[(0x24-0x08)/4];
	short	pad24;
	bool	unknown26;	// +0x26
};

class YkGroup
{
public:
	vector<YkHEntity> &unknown416f40();	// NOTE: placeholder name (ICF'd, returns this+0x0c: the members)
	int unknown9b4350();				// NOTE: placeholder name (ICF'd trivial getter of +0x08, the group type)
};

struct YkEntityData	// NOTE: placeholder name (robot definition)
{
	int		ID;		// +0x00
	int		pad04[(0x9c-0x04)/4];
	int		size;	// +0x9c, NOTE: placeholder name
};

struct YkItemData	// NOTE: placeholder name (item type definition)
{
	int			pad00[0x44/4];
	int			unknown44;	// +0x44
	int			pad48[(0x74-0x48)/4];
	short		pad74;
	bool		unknown76;	// +0x76
	bool		pad77;
	int			pad78[(0x94-0x78)/4];
	int			unknown94;	// +0x94
	int			pad98[(0x190-0x98)/4];
	int			unknown190;	// +0x190 (effect animation)
	int			unknown194;	// +0x194 (effect animation when blocked)
	int			pad198[2];
	YkEntityData	*unknown1a0;	// +0x1a0
	int			pad1a4[2];
	bool		unknown1ac;	// +0x1ac

	string getPrefixedName(int *length);		// 0x456fd0 NOTE: placeholder name
	bool unknown56fae0(vector<int> &out);		// NOTE: placeholder name
	void unknown56fc30(vector<int> &out);		// NOTE: placeholder name (resistance modifiers per damage type)
};

struct YkItemEffect	// NOTE: placeholder name
{
	int		type;
	int		state;

	YkItemEffect(int type_, int state_);	// 0x46ca20
};

class YkItem
{
public:
	int unknown9fcd80();				// NOTE: placeholder name (ICF'd trivial getter of +0x00)
	YkItemData *unknown9b4350();			// NOTE: placeholder name (ICF'd trivial getter of +0x08, the type)
	int unknown44aec0();				// NOTE: placeholder name (ICF'd trivial getter of +0x0c)
	int unknown9b6bf0();				// NOTE: placeholder name (ICF'd trivial getter of +0x1c, integrity)
	bool unknown415ee0();				// NOTE: placeholder name (ICF'd trivial getter of +0x20, faulty)
	bool unknown457db0();				// NOTE: placeholder name (+0x24 != 0, overloaded)
	int unknown457dd0();				// NOTE: placeholder name (ICF'd trivial getter of +0x24)
	int unknown45cb30();				// NOTE: placeholder name (ICF'd trivial getter of +0x44)
	void unknown44fc60(int value);		// NOTE: placeholder name (ICF'd setter of +0x44)
	int unknown457820();				// NOTE: placeholder name (type ID)
	const string &unknown457860();		// NOTE: placeholder name (type name, data->+0x08)
	int unknown457880() throw();				// NOTE: placeholder name
	int unknown4578a0();				// NOTE: placeholder name
	bool unknown457ad0();				// NOTE: placeholder name
	YkItemEffect *getEffect(int type);	// NOTE: placeholder name (0x457b70)
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
	void addEffect(YkItemEffect *effect);	// NOTE: placeholder name (0x4585a0)
	void unknown4585c0(int type);		// NOTE: placeholder name (removes an effect)
	int unknown577fb0();				// NOTE: placeholder name (getEffectValue(0x6b))
	void unknown579170(int value);		// NOTE: placeholder name (sets +0x0c, notifies the yk_world)
	void setActive(bool active);		// 0x5791a0
	void setBroken(int turn, bool flag);	// 0x5795b0
	void unknown57a0f0(const YkPoint *p, int a, int b);	// NOTE: placeholder name (drop at p)
	void unknown57ab10(int amount, int a, int b, int c, YkHEntity source, int d, int e);	// NOTE: placeholder name (damage)
	void unknown57c230(YkItem *source);	// NOTE: placeholder name (copies state from source)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name (detach/destroy)
	string getName(int a, int b);		// NOTE: placeholder name (0x571db0)
};

struct YkPropType	// NOTE: placeholder name (prop type definition)
{
	int		pad00[0x78/4];
	bool	unknown78;	// +0x78
};

struct YkMachine	// NOTE: placeholder name (object returned by YkProp::unknown45cb30)
{
	int		pad00[0x3c/4];
	int		unknown3c;	// +0x3c
};

class YkProp
{
public:
	YkPropType *unknown9b8f00();			// NOTE: placeholder name (ICF'd getter, +0x4, the type)
	int unknown457b10();				// NOTE: placeholder name (ICF'd getter, +0x3c)
	YkMachine *unknown45cb30();			// NOTE: placeholder name (ICF'd getter, +0x44)
	void unknown45cc50(const YkPoint &p);	// NOTE: placeholder name (sets the position)
	void unknown45ce10(bool a, bool b, bool c, YkHEntity d);	// NOTE: placeholder name
};

class YkCell
{
public:
	YkHEntity getEntity();				// 0x45d250
	YkHProp getProp();					// 0x45d550
	YkHItem getItem();					// 0x45d8f0
	bool unknown45db70();				// NOTE: placeholder name
	bool unknown45df50(YkHProp prop);		// NOTE: placeholder name (sets the prop, returns true)
	bool canPlaceEntity(int size);		// 0x66ad20
};

struct YkCartographer2DMoveCost;
class YkCartographer2D
{
public:
	bool findPath(const YkPoint &from, const YkPoint &to, YkCartographer2DMoveCost *yk_moveCost, void *data, vector<YkPoint> &path);	// 0x40c9a0
};

class YkEntity
{
public:
	int				unknown00;
	YkHEntity			self;		// +0x04
	YkEntityData		*data;		// +0x08
	string			label;		// +0x0c, NOTE: placeholder name
	YkHGroup			group;		// +0x28
	int				unknown2c;
	vector<YkPoint>	footprint;	// +0x30
	int				pad40[(0x8c-0x40)/4];
	int				unknown8c;	// +0x8c (core integrity)
	int				unknown90;	// +0x90
	int				unknown94;	// +0x94
	int				pad98[(0xb0-0x98)/4];
	int				unknownB0;	// +0xb0
	int				padB4[(0x134-0xb4)/4];
	vector<YkHItem>	parts;		// +0x134

	int equipPart(YkHItem item, bool update, int extra);	// 0x6430b0

	bool isPlayer();							// 0x5c7600
	const string &getName();					// 0x45a280
	const string &getLabel();					// NOTE: placeholder name (0x416f40, returns this+0x0c)
	int getFaction();							// 0x45a2c0
	int getSize();								// 0x45a360
	YkHGroup getGroup();							// 0x45a3f0
	const YkPoint &getPosition();					// 0x45a4a0
	YkPoint unknown45a4c0();						// NOTE: placeholder name
	int getTarget();							// NOTE: placeholder name (0x45a760, returns +0x70)
	int unknown45a810();						// NOTE: placeholder name
	int getSlotTotal();							// 0x45a860
	bool isHostileTo(YkHEntity e);				// 0x45aa70
	YkEntityEffect *unknown45ac40(int type);		// NOTE: placeholder name
	void unknown45b090(int value);				// NOTE: placeholder name (ICF'd setter)
	void unknown45b0b0();						// NOTE: placeholder name
	void unknown45b1b0(int value);				// NOTE: placeholder name (decreases +0x90)
	void unknown45b1e0(int value);				// NOTE: placeholder name (decreases +0x94)
	void unknown45b210(int value);				// NOTE: placeholder name
	void unknown45b360(int type);				// NOTE: placeholder name (removes an effect)
	int unknown448fe0(int slotType);			// NOTE: placeholder name (ICF'd, slot count at +0x78)
	int unknown490840();						// NOTE: placeholder name (ICF'd trivial getter of +0x8c)
	int unknown5c8db0();						// NOTE: placeholder name
	void unknown5c94e0(int slotType, YkHItem item);	// NOTE: placeholder name (adds a slot)
	int unknown5ca260();						// NOTE: placeholder name (maximum core integrity)
	int unknown5ca400();						// NOTE: placeholder name
	int unknown5ca670();						// NOTE: placeholder name
	int unknown5cb760();						// NOTE: placeholder name
	int unknown5cb7a0();						// NOTE: placeholder name
	unsigned int unknown5cb8b0(vector<YkHItem> *out);	// NOTE: placeholder name
	unsigned int unknown5cb930(vector<YkHItem> *out);	// NOTE: placeholder name
	int unknown5d2090(int type);				// NOTE: placeholder name
	YkHItem unknown5d2380(int type);				// NOTE: placeholder name
	int unknown5dc440(YkHItem item);				// NOTE: placeholder name
	int unknown5dc700(YkHItem item);				// NOTE: placeholder name
	void changeFaction(YkHGroup newGroup, bool flag);	// 0x5dc780
	void changePos(const YkPoint &p, bool flag);	// 0x5dccb0
	void unknown5de870(int amount, bool linked);	// NOTE: placeholder name (core repair)
	void unknown5dea60(int amount, bool linked);	// NOTE: placeholder name (sets core integrity)
	int unknown5defa0(int amount, bool notify);	// NOTE: placeholder name
	void unknown5fd550(YkHItem item, int turns);	// NOTE: placeholder name
	void unknown602ec0(vector<YkRect> &rects);	// NOTE: placeholder name
	void unknown63a3e0(int a, YkHItem item);		// NOTE: placeholder name
	void unknown642940(YkHItem item, bool a, bool b, bool c, int d);	// NOTE: placeholder name
};

class YkMap	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	YkHEntity getPlayer();						// NOTE: placeholder name (0x4630f0)
	YkHEntity getEntity671();						// NOTE: placeholder name (0x463110)
	bool unknown463190(int x, int y);			// NOTE: placeholder name (isVisible(x,y))
	bool isVisible(const YkPoint &p);				// NOTE: placeholder name (0x4631c0)
	bool unknown4631f0(YkHEntity e);				// NOTE: placeholder name
	bool unknown463380(int x, int y);			// NOTE: placeholder name
	bool unknown463510(YkHEntity e);				// NOTE: placeholder name
	bool unknown4635c0(YkHEntity e);				// NOTE: placeholder name
	void unknown463770(bool value);				// NOTE: placeholder name
	YkHGroup unknown463890(int i);				// NOTE: placeholder name
	vector<vector<YkHMarker> > *unknown463ec0();	// NOTE: placeholder name
	int &unknown4640c0();						// NOTE: placeholder name
	int &unknown4640e0();						// NOTE: placeholder name
	int getTurn();								// 0x464270
	bool unknown464350();						// NOTE: placeholder name
	void clearPoints7d0();						// NOTE: placeholder name (0x4656b0)
	vector<vector<YkPoint> > *unknown459070();	// NOTE: placeholder name
	YkHItem unknown6c5400(YkItemData *type, const YkPoint &p);	// NOTE: placeholder name (creates an item)
	void unknown6c65a0(YkHEntity e, const string &name, int value);	// NOTE: placeholder name
	int unknown7151c0();						// NOTE: placeholder name
	YkHEntity unknown715230(int group, int faction);	// NOTE: placeholder name
	bool unknown71bc10(const YkPoint &p, YkPoint *out);	// NOTE: placeholder name
	bool findPlaceableNear(const YkPoint &p, YkPoint &out, int size);	// NOTE: placeholder name (0x71c150)
	void unknown71cf70();						// NOTE: placeholder name
	void opw3_unknown72e4c0(YkHEntity e, bool flag);	// NOTE: placeholder name
	void opw3_unknown72ea10();					// NOTE: placeholder name
	void opw3_unknown72ec60();					// NOTE: placeholder name
	void unknown734560(YkHEntity e, int a, vector<unsigned int> *types);	// NOTE: placeholder name
	void unknown747060(const YkPoint &center, int radius, int effect);	// NOTE: placeholder name
	YkHRecord addRecord(YkHRecord h);				// NOTE: placeholder name (0x777a20)
};

class YkMapView	// NOTE: placeholder name (0xcec054)
{
public:
	void unknown44e360(YkHItem item);			// NOTE: placeholder name (ICF'd setter of +0xcc)
	int unknown8054b0(bool flag);			// NOTE: placeholder name
	void unknown8069e0(YkPoint p, bool flag);	// NOTE: placeholder name
};

class YkConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);			// NOTE: placeholder name
};

class YkCLogMsgs
{
public:
	void scrollToEnd();						// 0x7b4f10
};

class YkCPart
{
public:
	int unknown416230();					// NOTE: placeholder name (ICF'd trivial getter of +0x7c, slot type)
	void unknown49ac50();					// NOTE: placeholder name (clears the +0x74 handle)
	void drawStatus(bool damaged);			// NOTE: placeholder name (0x4a8e70)
	void unknown4a9120();					// NOTE: placeholder name (Calls_4a9120::delegate)
	YkHItem unknown4aeed0();					// NOTE: placeholder name (ICF'd, handle at +0x6c)
	YkHItem unknown4b1b30();					// NOTE: placeholder name (ICF'd, handle at +0x74)
	void unknown890710(int a);				// NOTE: placeholder name
};

class YkCParts
{
public:
	vector<YkCPart *> &unknown4a9ad0();		// NOTE: placeholder name (ICF'd, returns this+0x74)
	YkCPart *unknown894e70(YkHItem item);		// NOTE: placeholder name
	void unknown896ab0(int type);			// NOTE: placeholder name
	void unknown896c20(int type);			// NOTE: placeholder name
	void unknown897290(YkHItem item, int extra);	// NOTE: placeholder name
};

class YkCInventory
{
public:
	void reopen(int mode, YkHItem item);		// 0x8a2ce0
};

class YkSceneConsole	// NOTE: placeholder name (0xcec118)
{
public:
	bool isHidden();						// 0x4175f0
	void unknown8b4500(YkHEntity a, YkHEntity b, YkHEntity c, const YkPoint &p, int d, int e);	// NOTE: placeholder name
};

class YkObj_cec138	// NOTE: placeholder name (pointer at 0xcec138)
{
public:
	void unknown965c10(int a, bool b, bool c);	// NOTE: placeholder name
	void unknown9675f0();					// NOTE: placeholder name
};

class YkEffectInstance	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const YkPoint &from, const YkPoint &to, YkPoint *p1, YkPoint *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class YkEffectMgr	// NOTE: placeholder name
{
public:
	YkEffectInstance *create();				// NOTE: placeholder name (0x508610)
};

class YkObj515ca0	// NOTE: placeholder name; 0x40 bytes in the exe, layout not reconstructed
{
public:
	YkObj515ca0(YkHEntity a, YkEntityData *type, const YkPoint &pos, YkHEntity b, const YkPoint &c, const YkPoint &d);	// 0x515ca0
	int data[16];
};

class YkGM	// NOTE: placeholder name (0xcefaa8)
{
public:
	YkHRecord createA(YkObj515ca0 *record);		// NOTE: placeholder name (0x7930e0)
	YkHProp createE(YkPropType *type);			// NOTE: placeholder name (0x793360)
	bool showOnce(int id, bool enabled, const string *text, bool repeat, bool flag);	// NOTE: placeholder name (0x793450)
	void unknown793690();					// NOTE: placeholder name
	void unknown78c260(int a, int b, int c, int d, int e);	// NOTE: placeholder name (csv: YkGM::serialize)
};

class YkGallery	// NOTE: placeholder name (0xd25628)
{
public:
	void addItemAttachCount(int itemID, int count, bool force);	// 0x778560
};

class YkPlayerData	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool isSlotEmpty(unsigned int index);	// NOTE: placeholder name (0x46de40); true while achievement <index> is not earned
	void unknown46df70();					// NOTE: placeholder name (Calls_46df70::delegate)
	void unknown77fbc0(int id);				// NOTE: placeholder name; earns achievement <id>
	bool unknown77ffb0(int typeID, bool known);	// NOTE: placeholder name (marks an item type known, true the first time)
	bool hasCompanion();					// NOTE: placeholder name (0x780790)
};

class YkCompanionData	// NOTE: placeholder name (pointer at 0xcf4ac8)
{
public:
	void upgrade(int a, int level);			// 0x7aba60
};

struct YkStatSet	// NOTE: placeholder name (OpR1h_StatSet)
{
	vector<int>	values;	// +0x00, NOTE: placeholder name
};

class YkOpR1h_Stats	// NOTE: placeholder name (0xd2c658)
{
public:
	YkStatSet		*current;	// +0x00

	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
	void add472b90(unsigned int id, int value);	// NOTE: placeholder name (0x472b90)
};

class YkGameData	// NOTE: placeholder name (0xd1e860)
{
public:
	const string &getEntryText(const string &key);			// NOTE: placeholder name (0x46f6d0)
	void setEntryText(const string &key, const string &text);	// NOTE: placeholder name (0x46f700)
	void unknown783ae0(int a);								// NOTE: placeholder name
};

class YkIntGrid	// NOTE: placeholder name (OpS7_IntGrid2)
{
public:
	void init_9cf690(int width, int height, int fill);	// NOTE: placeholder name
};

class YkAudio	// NOTE: placeholder name (0xd25450)
{
public:
	bool	enabled;		// +0x00
	int		pad04[(0x98-0x04)/4];
	int		unknown98;		// +0x98
	int		pad9c;
	int		unknownA0;		// +0xa0

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
	void unknown69ea20(bool flag);			// NOTE: placeholder name
	bool unknown69eba0(YkHItem item);			// NOTE: placeholder name
	void unknown69ec90();					// NOTE: placeholder name
	void unknown69ecb0(int id);				// NOTE: placeholder name
};

class YkSoundMgr	// NOTE: placeholder name (0xd2d2a0)
{
public:
	void unknown454540();					// NOTE: placeholder name
	void unknown500010();					// NOTE: placeholder name
};

class YkOpS2_PhraseTextB	// NOTE: placeholder name
{
public:
	YkOpS2_PhraseTextB(int index, string *a, string *b, string *c, YkHEntity d, YkHEntity e);	// 0x510f80
	int data[10];
};

class YkMessageLog	// NOTE: placeholder name (0xcf1080)
{
public:
	int push(YkOpS2_PhraseTextB *text);		// NOTE: placeholder name (0x5121f0)
};

class YkRolledValues	// NOTE: placeholder name (OpW5_RolledValues, pointer at 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);	// 0x49e250
};

class YkObj49b870	// NOTE: placeholder name (0xd1d9c0)
{
public:
	void reset();							// NOTE: placeholder name (0x49b870)
};

struct YkObj_d39f1c	// NOTE: placeholder name (elements of the vector at 0xd39f1c)
{
	int		pad00[0x30/4];
	bool	unknown30;	// +0x30
};

bool yk_unknown5111e0(int id, const string *text1, const string *text2, const string *text3, YkHEntity subject, YkHEntity object, const YkPoint *pos, int extra);	// NOTE: placeholder name (show message)
void yk_unknown5141b0(int id, const string *a, const string *b, int c, YkHEntity e, int d);	// NOTE: placeholder name (history/log record)
void yk_opR1d_4541b0(int sound, int a, int b);	// NOTE: placeholder name (play sound)
void yk_opW5_message(int type, YkHEntity entity, const string *text, int flag);	// NOTE: placeholder name (0x49c610)
void yk_unknown789ac0();						// NOTE: placeholder name
void yk_logError(string yk_location, string message);	// 0x404f10
string yk_intToString(int value);				// 0x4051f0
string yk_OpY1_intToStringSigned(int value);	// NOTE: placeholder name (0x405560)
int yk_stringToInt(const string &s);			// NOTE: placeholder name (0x405610)
string yk_opw8_countString(int count, const string &noun);	// NOTE: placeholder name (0x407a80)
int yk_OpQ1_distanceCeil_40a3f0(const YkPoint &a, const YkPoint &b);	// NOTE: placeholder name
int yk_minInt(int a, int b) throw();					// 0x9cdb30
int yk_maxInt(int a, int b);					// 0x9cdb60
void yk_opw8_atLeast(int *value, int minimum);	// NOTE: placeholder name (0x9cf5c0)
void yk_opw8_increase(int *value, int amount, int maximum);	// NOTE: placeholder name (0x9d06d0)
bool yk_OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (low <= value <= high)
bool yk_containsInt(vector<int> &values, int value);	// NOTE: placeholder name (0x9db330)
void yk_OpV4c_Fn9d5460(vector<YkPoint> &v, unsigned int index, YkPoint p);	// NOTE: placeholder name (insert at index)
void yk_OpC_findNodes_470400(YkHLocation node, vector<YkHLocation> &matches, vector<YkHLocation> &visited);	// NOTE: placeholder name
void yk_removeVectorElement(vector<int> &v, int index);	// NOTE: placeholder name (0x9de6f0)
template <class T> bool yk_OpU8a_containsEntity(vector<T> &v, T e);	// NOTE: placeholder name (0x9d31e0, handle vectors)
template <class T> bool yk_OpQ5_findByName(vector<T *> &v, const string &name, T *&out);	// NOTE: placeholder name (0x9d7710 props, 0x9d7a40 items)
template <class T> T yk_OpU8a_randomRec(vector<T> &v);			// NOTE: placeholder name (0x9d5d00, random element)
template <class T> int yk_OpQ5_randomIndex(vector<T> &v);		// NOTE: placeholder name (0x9d9b20)
template <class T> void yk_OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9da940)
template <class T> void yk_eraseStep(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440, erases and steps i back)
template <class T> void yk_shuffle(vector<T> &v);				// NOTE: placeholder name (0x9d9fc0)
template <class T> T yk_OpX5_randomRecord(vector<T> &v);		// NOTE: placeholder name (0x9dafb0, random element)
template <class T> T yk_OpS8c_popRandom(vector<T> &v);			// NOTE: placeholder name (0x9d8030, removes a random element)

extern YkRng						rng;				// 0xd30908
extern YkMap						*yk_world;				// 0xcefc4c
extern YkEffectMgr				*yk_effectMgr;			// 0xcefc50
extern YkPoint					yk_effectOrigin;		// 0xd2e20c
extern YkArray2D<YkCell *>			yk_cells;				// 0xcfd44c
extern YkCartographer2D			yk_pathfinder;			// NOTE: placeholder name (0xcfe568)
extern YkCartographer2DMoveCost	*yk_moveCost;			// NOTE: placeholder name (0xcefc30)
extern YkGM						*yk_gm;				// 0xcefaa8
extern YkGallery					yk_gallery;			// NOTE: placeholder name (0xd25628)
extern YkPlayerData				yk_playerData;			// 0xcf45d8
extern YkCompanionData			*yk_companion;			// NOTE: placeholder name (0xcf4ac8)
extern YkOpR1h_Stats				yk_stats;				// 0xd2c658
extern YkMessageLog				yk_messageLog;			// 0xcf1080
extern YkMapView					*yk_mapView;			// 0xcec054
extern YkConsoleA					*yk_consoleA;			// 0xcec058
extern YkCLogMsgs					*yk_logMsgs;			// 0xcec0b4
extern YkCParts					*yk_cparts;			// 0xcec088
extern YkCInventory				*yk_cinventory;		// NOTE: placeholder name (0xcec08c)
extern YkSceneConsole				*yk_sceneConsole;		// NOTE: placeholder name (0xcec118)
extern YkObj_cec138				*yk_unknownCec138;
extern YkAudio					yk_audio;				// 0xd25450
extern YkSoundMgr					yk_soundMgr;			// NOTE: placeholder name (0xd2d2a0)
extern YkRolledValues				*yk_rolledValues;		// 0xcefb48
extern YkGameData					yk_gameData;			// 0xd1e860
extern YkHLocation				yk_location;			// 0xd1e888
extern YkHLocation				yk_unknownD1e884;		// yk_world map root node
extern YkIntGrid					yk_unknownD1e970;
extern YkObj49b870				yk_unknownD1d9c0;
extern vector<YkPropType *>		yk_propTypes;			// NOTE: placeholder name (0xcf35b0)
extern vector<YkItemData *>		yk_itemTypes;			// NOTE: placeholder name (0xd2d1c4)
extern vector<YkEntityData *>		yk_entityRecords;		// NOTE: placeholder name (0xd25de0)
extern vector<int>				yk_effectTypes;		// 0xd2f0f8
extern vector<YkObj_d39f1c *>		yk_unknownD39f1c;
extern string					yk_damageTypeNames[];	// 0xd323f8, NOTE: placeholder name
extern string					yk_slotTypeNames[];	// 0xd378d0, NOTE: placeholder name
extern int						yk_pairedPartTypes[];	// 0xba32f8, NOTE: placeholder name (indexed by effect type)
extern bool						yk_mildMalfunctions[];	// 0xba3ab4, NOTE: placeholder name
extern int						yk_resistances[];		// 0xcf4984, NOTE: placeholder name (per damage type)
extern vector<int>				yk_pairedPartShown;	// 0xd22590, NOTE: placeholder name
extern vector<int>				yk_attachedItems;		// 0xcf47cc, NOTE: placeholder name (item IDs ever attached)
extern int						yk_unknownCf47c0;		// core modifications counter
extern vector<int>				yk_unknownCf4810;
extern vector<int>				yk_unknownCf4820;
extern vector<int>				yk_unknownCf4830;		// per item type
extern int						yk_unknownCf4840;
extern vector<int>				yk_unknownCf4844;		// per item type
extern int						yk_unknownCf4854;
extern vector<int>				yk_unknownCf4858;
extern vector<int>				yk_unknownCf4868;
extern vector<int>				yk_unknownCf4878;
extern vector<int>				yk_unknownCf4888;		// per robot type
extern int						yk_unknownCf4898;
extern vector<int>				yk_unknownCf489c;
extern vector<int>				yk_unknownCf48ac;
extern vector<int>				yk_unknownCf48bc;
extern vector<int>				yk_unknownCf48cc;		// per item type
extern int						yk_unknownCf48dc;
extern vector<int>				yk_unknownCf48e0;
extern vector<int>				yk_unknownCf48f0;
extern vector<int>				yk_unknownCf4900;
extern vector<int>				yk_unknownCf4910;		// per robot type
extern int						yk_unknownCf4920;
extern int						yk_unknownCf4954;
extern int						yk_unknownCf496c;
extern int						yk_unknownCf4970;
extern int						yk_unknownCf4974;
extern int						yk_unknownCf4978;
extern int						yk_unknownCf497c;		// integrated mediator installed
extern bool						yk_unknownCf4980;
extern int						yk_unknownCf49d8;
extern int						yk_unknownCf49dc;
extern int						yk_unknownCf49e0;
extern bool						yk_unknownCf49e4;
extern bool						yk_unknownCf49f0;
extern int						yk_unknownCf49f4;
extern int						yk_unknownCf49f8;
extern int						yk_unknownCf49fc;
extern bool						yk_unknownCf4a00;
extern vector<int>				yk_unknownCf4a04;
extern vector<int>				yk_unknownCf4a14;
extern int						yk_unknownCf4a34;
extern int						yk_unknownCf4d1c;		// teleport counter (achievement 0x133 at 10)
extern vector<int>				yk_unknownD01be8;
extern YkHItem					yk_unknownD2d504;
extern bool						yk_unknownD28d09;
extern bool						yk_unknownD28d4c;
extern int						yk_unknownD28d68;
extern int						yk_unknownB95fb4;		// returned time (100)
extern const int				yk_unknownB960f0;		// 0xb960f0 NOTE: placeholder name (200)
extern const int				yk_unknownB960fc;		// NOTE: placeholder name (500)
extern const float yk_ba0bb4;

// message to the main log (0xcec0b4)
#define MESSAGE(id,text1,text2,text3,subject,object,pos,extra) \
	do \
	{ \
		if (yk_unknown5111e0(id,text1,text2,text3,subject,object,pos,extra)) \
			yk_consoleA->unknown8758d0(true); \
		yk_logMsgs->scrollToEnd(); \
	} while (0)
// phrase without arguments pushed to the message log
#define PHRASE(id) \
	do \
	{ \
		if (yk_messageLog.push(new YkOpS2_PhraseTextB(id,NULL,NULL,NULL,YkHEntity(),YkHEntity()))) \
			yk_consoleA->unknown8758d0(true); \
		yk_logMsgs->scrollToEnd(); \
	} while (0)
#define HISTORY(id,a,b,c,e,d) do { yk_unknown5141b0(id,a,b,c,e,d); } while (0)
// the part cannot be used: message, restore +0x0c, back to the floor or the inventory, return 0
#define REJECT_PART(id) \
	{ \
		MESSAGE(id,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0); \
		item->unknown579170(aC); \
		if (unknown45a810() < 0) \
			item->unknown57a0f0(&getPosition(),0,1); \
		else yk_cinventory->reopen(4,YkHItem()); \
		return 0; \
	}

//==================================================================
// YkEntity::equipPart
//==================================================================

// helper: lets LTCG prove the 0x46ca20 ctor nothrow (no EH state around new, extra temp slot kept)
YkItemEffect::YkItemEffect(int type_, int state_)
{
	type = type_;
	state = state_;
}

int YkEntity::equipPart(YkHItem item, bool update, int extra)
{
	// tutorial hints
	if (isPlayer())
	{
		yk_gm->showOnce(0x1b,unknown5dc440(item) == 0 || unknown5dc700(item) == 0,&item->getName(0,0),false,false);
		yk_gm->showOnce(0x1c,item->unknown9b4350()->unknown1ac,&item->getName(0,0),false,false);
		yk_gm->showOnce(0x1d,item->unknown457f90() == 7,&item->getName(0,0),false,false);
		yk_gm->showOnce(0x1e,item->unknown457e10() != 0 && item->unknown4578a0() == 0,&item->getName(0,0),false,false);
	}

	// first part of a matched pair (yk_pairedPartTypes[type] == 1 or 2) attached: one-time message
	if (yk_unknownD28d09)
	{
		if (yk_pairedPartTypes[item->unknown457f90()] != 0)
		{
			int index = (yk_pairedPartTypes[item->unknown457f90()] != 2) + 0x1f;
			if (yk_pairedPartShown[index] == 0)
			{
				YkHItem other = unknown5d2380(item->unknown457f90());
				if (other.isValid())
				{
					MESSAGE((index != 0x1f) + 0x34c,&item->getName(0,0),&other->getName(0,0),0,YkHEntity(),YkHEntity(),NULL,0);
					yk_opR1d_4541b0(0x22,0,0);
					yk_pairedPartShown[index] = 1;
				}
			}
		}
	}

	int aC = item->unknown44aec0();
	item->unknown579170(item->unknown4578a0());
	if (!yk_world->unknown464350())
	{
		unknown45b1b0(unknown5cb760());
		unknown45b1e0(unknown5cb7a0());
	}

	// player statistics and achievements
	int firstTime = 0;	// NOTE: placeholder name (the exe keeps the bool result in an int)
	if (isPlayer())
	{
		firstTime = yk_playerData.unknown77ffb0(item->unknown457820(),true);
		if (firstTime)
		{
			if (item->unknown9b4350()->unknown94 != 0)
			{
				yk_stats.add4729d0(0x8d,1,string(""),-1);
				yk_playerData.unknown77fbc0(0x11);
				if (yk_stats.current->values[0x8d] == 20)
					yk_playerData.unknown77fbc0(0x12);
			}
		}
		if (item->unknown9b4350()->unknown94 == 3)
		{
			yk_stats.add4729d0(5,1,item->unknown9b4350()->getPrefixedName(NULL),-1);
			yk_playerData.unknown77fbc0(0x13);
			if (yk_stats.current->values[5] == 15)
				yk_playerData.unknown77fbc0(0x153);
		}
		if (!yk_containsInt(yk_attachedItems,item->unknown9fcd80()))
		{
			yk_attachedItems.push_back(item->unknown9fcd80());
			yk_gallery.addItemAttachCount(item->unknown457820(),1,false);
		}
		item->unknown458480();
		if (item->unknown9b4350()->unknown76)
		{
			if (item->getEffect(0x68) == NULL)
			{
				if (!yk_containsInt(yk_unknownCf4810,item->unknown9fcd80()))
				{
					yk_unknownCf4810.push_back(item->unknown9fcd80());
					yk_unknownCf4820.push_back(yk_unknownCf4830[item->unknown457820()] != 0);
					HISTORY(0x2f,&item->getName(0,0),NULL,0,YkHEntity(),0);
				}
			}
		}
		if (yk_world->unknown4640c0() != 0 && item->unknown4578a0() == 3)
		{
			yk_world->unknown4640c0()--;
			yk_world->unknown4640e0()++;
			if (yk_mapView->unknown8054b0(false) != 0)
			{
				if (yk_world->unknown4640e0() >= 1)
					yk_playerData.unknown77fbc0(0x26);
				if (yk_world->unknown4640e0() >= 4)
					yk_playerData.unknown77fbc0(0x9e);
			}
		}
		switch (item->unknown457f90())
		{
			case 0xd: yk_playerData.unknown77fbc0(0x81); break;
			case 0x1b: yk_playerData.unknown77fbc0(0x1a6); break;
		}
		if (yk_playerData.isSlotEmpty(0x84) && ((item->unknown457f90() == 0x14 && unknown5d2380(0x15).isValid()) || (item->unknown457f90() == 0x15 && unknown5d2380(0x14).isValid())))
			yk_playerData.unknown77fbc0(0x84);
		if (yk_playerData.isSlotEmpty(0x11f) && item->unknown457860() == "8R-AWN's Boregun")
			yk_playerData.unknown77fbc0(0x11f);
		else if (yk_playerData.isSlotEmpty(0x134) && item->unknown457860() == "Vortex Field Projector")
			yk_playerData.unknown77fbc0(0x134);
		else if (yk_playerData.isSlotEmpty(0x135) && item->unknown457860() == "BFG-9k Vortex Edition")
			yk_playerData.unknown77fbc0(0x135);
	}

	// effects applied when the part is attached
	switch (item->unknown457f90())
	{
		case 0x7c:
		{
			if (yk_stringToInt(yk_gameData.getEntryText("installedRif_g")) == 0)
			{
				MESSAGE(0x29e,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
				yk_opR1d_4541b0(0xa5,0,0);
				item->unknown57dbe0(update,0,1,1);
			}
			else yk_stats.add4729d0(0x375,1,string(""),-1);
			break;
		}
		case 0xd2:
		{
			if (yk_stringToInt(yk_gameData.getEntryText("installedRif_g")) != 0 || yk_stringToInt(yk_gameData.getEntryText("zioWasImprinted_g")) != 0 || yk_stringToInt(yk_gameData.getEntryText("warAttackedLocals_g")) != 0)
			{
				MESSAGE(0x29e,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
				yk_opR1d_4541b0(0xa5,0,0);
				item->unknown57dbe0(update,0,1,1);
			}
			break;
		}
		case 0xb7:
		{
			HISTORY(0x52,NULL,NULL,0,YkHEntity(),0);
			yk_gm->unknown78c260(0,0,1,0,0);
			MESSAGE(0x115,NULL,NULL,0,self,YkHEntity(),NULL,0);
			if (item->unknown9b6bf0() == 1)
				yk_mapView->unknown44e360(item);
			break;
		}
		case 0xd4:
		{
			if (isPlayer())
			{
				if (item->unknown9b4350()->unknown56fae0(yk_unknownD01be8) && yk_unknownD2d504.isNull())
					yk_unknownD2d504 = item;
			}
			break;
		}
		case 0x1f:
		{
			if ((yk_unknownCf4a00 && isPlayer()) || yk_location->type == 0x22)
			{
				MESSAGE(0x29e,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
				if (isPlayer())
					yk_opR1d_4541b0(0xa5,0,0);
				item->unknown579170(aC);
				item->unknown57dbe0(update,0,1,1);
			}
			else
			{
				vector<unsigned int> types;
				for (int i = 3; i <= 4; i++)
					types.push_back((unsigned int)i);
				yk_world->unknown734560(self,-2,&types);
				item->unknown44fc60(item->unknown457fb0());
				if (isPlayer())
				{
					MESSAGE(0xc2,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
					HISTORY(0x5f,&item->getName(0,0),NULL,0,self,0);
					yk_stats.add4729d0(0x247,1,string(""),-1);
				}
			}
			break;
		}
		default:
		{
			if (yk_OpT8b_Fn9daf80(0x7e,item->unknown457f90(),0x93))
			{
			// single-use effects (0x7e-0x93): the part is used up afterwards
			switch (item->unknown457f90())
			{
				case 0x7e:	// dimension slip node
				{
					YkPoint pos(getPosition());
					YkPropType *nodeType;
					if (yk_OpQ5_findByName(yk_propTypes,"ARM_Dimension_Slip_Node",nodeType))
					{
						if (yk_cells(pos)->getProp().isValid() && yk_cells(pos)->getProp()->unknown9b8f00()->unknown78)
							yk_cells(pos)->getProp()->unknown45ce10(true,false,false,YkHEntity());
						if (yk_cells(pos)->getProp().isValid() || yk_cells(pos)->unknown45db70())
						{
							yk_world->unknown6c5400(item->unknown9b4350(),getPosition());
							PHRASE(0xef);
						}
						else if (yk_cells(pos)->unknown45df50(yk_gm->createE(nodeType)))
						{
							yk_cells(pos)->getProp()->unknown45cc50(pos);
							yk_opR1d_4541b0(199,0,0);
							PHRASE(0xee);
							HISTORY(0x39,NULL,NULL,0,YkHEntity(),0);
							yk_soundMgr.unknown454540();
							yk_soundMgr.unknown500010();
						}
					}
					break;
				}
				case 0x7f:	// teleport
				{
					YkPoint a5(getPosition());
					YkPoint dest;
					if (unknown8c > 1)
						unknown5dea60((int)(unknown8c * rng.rangeFloat(0.9f,0.95f)),false);
					bool found9 = false;
					vector<YkPoint> nodes;
					bool b0 = false;
					YkPropType *nodeType;
					YkPropType *aE;
					if (yk_OpQ5_findByName(yk_propTypes,"ARM_Dimension_Slip_Node",nodeType) && yk_OpQ5_findByName(yk_propTypes,"COM_Teleport_Inhibitor",aE))
					{
						for (int x = 0; x < yk_cells.getWidth(); x++)
						{
							for (int y = 0; y < yk_cells.getHeight(); y++)
							{
								if (yk_cells(x,y)->getProp().isValid())
								{
									if (yk_cells(x,y)->getProp()->unknown9b8f00() == nodeType)
										nodes.push_back(YkPoint(x,y));
									else if (yk_cells(x,y)->getProp()->unknown9b8f00() == aE && yk_cells(x,y)->getProp()->unknown457b10() == 0)
										b0 = true;
								}
							}
						}
					}
					if (b0 && item->unknown457fb0() > 0)
					{
						PHRASE(0xf3);
						HISTORY(0x3c,NULL,NULL,0,YkHEntity(),0);
						if (yk_world->isVisible(footprint[0]))
						{
							for (unsigned int i = 0; i < footprint.size(); i++)
								yk_effectMgr->create()->init(yk_effectMgr,item->unknown9b4350()->unknown194,footprint[i],yk_effectOrigin,NULL,NULL,NULL,9,0);
						}
						if (yk_audio.enabled)
							yk_audio.unknown69e700(0x3c,0,0.0f);
					}
					else
					{
						// nearest reachable slip node first
						if (!nodes.empty())
						{
							vector<YkPoint> sorted;
							if (nodes.size() > 1)
							{
								sorted.push_back(nodes.back());
								nodes.pop_back();
								while (!nodes.empty())
								{
									int distance = yk_OpQ1_distanceCeil_40a3f0(a5,nodes.back());
									if (distance >= yk_OpQ1_distanceCeil_40a3f0(a5,sorted.back()))
										sorted.push_back(nodes.back());
									else
									{
										for (unsigned int i = 0; i < sorted.size(); i++)
										{
											if (distance < yk_OpQ1_distanceCeil_40a3f0(a5,sorted[i]))
											{
												yk_OpV4c_Fn9d5460(sorted,i,nodes.back());
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
								if (a5 == dest || yk_world->findPlaceableNear(dest,dest,1))
								{
									found9 = true;
									break;
								}
							}
						}
						// otherwise a random destination with a path length in range
						if (!found9)
						{
							YkRange range_(abs(item->unknown457fb0()) * 75 / 100,abs(item->unknown457fb0()) * 125 / 100);
							YkArea areaRef;
							yk_cells.getBounds(a5,range_.max,&areaRef);
							int attempts = 0;
							do
							{
								vector<YkPoint> path;
								areaRef.randomPoint(&dest);
								if (yk_cells(dest)->canPlaceEntity(data->size) && yk_pathfinder.findPath(a5,dest,yk_moveCost,NULL,path))
								{
									if (attempts > 500 || range_.contains_40c190(path.size()))
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
								yk_logError("Entity::equipPart()","Could not find EFFECT_TELEPORT destination within range (" + yk_intToString(range_.min) + "-" + yk_intToString(range_.max) + ")");
								break;
							}
						}

						// the item on the departure cell is moved away
						YkPoint dropPos;
						if (yk_cells(a5)->getItem().isValid() && yk_world->unknown71bc10(dest,&dropPos))
							yk_cells(a5)->getItem()->unknown57a0f0(&dropPos,0,0);

						// robots teleported along: the stand-in entity, and for negative ranges every non-player robot within 10
						vector<YkHEntity> others;
						if (yk_world->getEntity671().isValid())
							others.push_back(yk_world->getEntity671());
						if (item->unknown457fb0() < 0)
						{
							YkArea area;
							yk_cells.getBounds(a5,10,&area);
							for (int x = area.min.x; x <= area.max.x; x++)
							{
								for (int y = area.min.y; y <= area.max.y; y++)
								{
									if (yk_cells(x,y)->getEntity().isValid() && yk_world->unknown463380(x,y) && !yk_cells(x,y)->getEntity()->isPlayer() && !yk_OpU8a_containsEntity(others,yk_cells(x,y)->getEntity()) && yk_cells(x,y)->getEntity()->getFaction() != 0x56 && yk_cells(x,y)->getEntity()->getFaction() != 0x57 && yk_cells(x,y)->getEntity()->getFaction() != 0x58)
										others.push_back(yk_cells(x,y)->getEntity());
								}
							}
						}

						if (yk_audio.enabled && !found9)
							yk_audio.unknown69ec90();
						changePos(dest,true);
						unknown45b090(0);
						unknown45b0b0();
						if (isPlayer())
						{
							PHRASE((found9 ? 1 : 0) + 0xf0);
							HISTORY((found9 ? 1 : 0) + 0x3a,NULL,NULL,0,YkHEntity(),0);
							yk_world->unknown71cf70();
						}
						else MESSAGE(0xf2,NULL,NULL,0,self,YkHEntity(),NULL,0);

						YkPoint a2;
						for (unsigned int i = 0; i < others.size(); i++)
						{
							if (yk_world->findPlaceableNear(dest,a2,others[i]->getSize()))
							{
								others[i]->changePos(a2,true);
								if (others[i]->unknown490840() > 1 && others[i] != yk_world->getEntity671())
									others[i]->unknown5dea60((int)(others[i]->unknown490840() * rng.rangeFloat(0.9f,0.95f)),false);
								if (yk_world->unknown463510(others[i]) || yk_world->unknown4635c0(others[i]))
									yk_world->opw3_unknown72e4c0(others[i],true);
							}
							else yk_eraseStep(others,i);
						}
						yk_world->unknown734560(self,-2,NULL);
						for (unsigned int i = 0; i < others.size(); i++)
							yk_world->unknown734560(others[i],-2,NULL);
						if (group->unknown9b4350() == 0)
						{
							yk_world->opw3_unknown72e4c0(self,true);
							if (isPlayer())
							{
								yk_unknownD1d9c0.reset();
								yk_mapView->unknown8069e0(dest,false);
								yk_stats.add4729d0(0x3fe,1,string(""),-1);
								yk_unknownCf4d1c++;
								if (yk_unknownCf4d1c == 10)
									yk_playerData.unknown77fbc0(0x133);
							}
						}
						if (yk_audio.enabled && !found9)
							yk_audio.unknown69ecb0(0x37);
						if (yk_world->isVisible(dest))
						{
							for (unsigned int i = 0; i < footprint.size(); i++)
								yk_effectMgr->create()->init(yk_effectMgr,item->unknown9b4350()->unknown190,footprint[i],yk_effectOrigin,NULL,NULL,NULL,9,0);
						}
						for (unsigned int i = 0; i < others.size(); i++)
						{
							if (yk_world->unknown4631f0(others[i]))
							{
								vector<YkPoint> &otherFootprint = others[i]->footprint;
								for (unsigned int j = 0; j < otherFootprint.size(); j++)
									yk_effectMgr->create()->init(yk_effectMgr,item->unknown9b4350()->unknown190,otherFootprint[j],yk_effectOrigin,NULL,NULL,NULL,9,0);
								if (others[i] == yk_world->getEntity671())
								{
									YkHEntity hostile;
									for (unsigned int j = 0; j < others.size(); j++)
									{
										if (others[j]->isHostileTo(yk_world->getPlayer()))
										{
											hostile = others[j];
											break;
										}
									}
									// NOTE: dangling else as compiled: the 0x26 line is only reachable when yk_rolledValues is NULL
									if (hostile.isValid())
									{
										if (yk_rolledValues != NULL)
											yk_rolledValues->say(0x27,false,hostile->getLabel());
										else if (yk_rolledValues != NULL)
											yk_rolledValues->say(0x26,false,"");
									}
								}
								else if (others[i]->getFaction() == 0x5b)
								{
									if (others[i]->getGroup()->unknown9b4350() == 9 && yk_location->type == 0x22 && found9)
										{ string msg = others[i]->getLabel() + ": \"What is this? Where are we now?\""; yk_opW5_message(0x322,others[i],&msg,0); }
								}
							}
						}
					}
					if (isPlayer())
						yk_playerData.unknown77fbc0(0x86);
					break;
				}
				case 0x80:	// gain slot
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_GAIN_SLOT, found on " + getName());
						break;
					}
					{
						int slotType = rng.rangeInt(0,3);
						bool full = getSlotTotal() >= 26;
						bool b5 = false;
						if (full)
						{
							// at the slot limit an empty slot is converted instead
							vector<YkCPart *> emptySlots;
							vector<YkCPart *> &slotsD = yk_cparts->unknown4a9ad0();
							for (unsigned int i = 0; i < slotsD.size(); i++)
							{
								if (slotsD[i]->unknown4b1b30().isValid())
									emptySlots.push_back(slotsD[i]);
							}
							if (!emptySlots.empty())
							{
								YkCPart *slot = yk_OpU8a_randomRec(emptySlots);
								slot->unknown49ac50();
								slotType = slot->unknown416230();
								slot->unknown4a9120();
								b5 = true;
								full = false;
							}
						}
						if (full)
						{
							MESSAGE(0xf5,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
							break;
						}
						{
							if (!b5)
								unknown5c94e0(slotType,YkHItem());
							yk_unknownCf47c0++;
							MESSAGE(0xf4,&item->getName(0,0),&yk_slotTypeNames[slotType],0,self,YkHEntity(),NULL,0);
							HISTORY(0x3d,&item->getName(0,0),&yk_slotTypeNames[slotType],0,YkHEntity(),0);
							yk_opR1d_4541b0(200,0,0);
							if (slotType == 3 && unknown448fe0(3) >= 7)
								yk_playerData.unknown77fbc0(0x8b);
						}
					}
					break;
				}
				case 0x81:	// core regeneration
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_REGENERATION, found on " + getName());
						break;
					}
					{
						int amount = yk_minInt(unknown5ca260() - unknown8c,item->unknown457fb0() * unknown5ca260() / 100);
						unknown5de870(amount,false);
						MESSAGE(0xf6,&yk_intToString(amount),NULL,0,self,YkHEntity(),NULL,0);
						HISTORY(0x3f,&item->getName(0,0),&yk_intToString(amount),0,YkHEntity(),0);
						yk_opR1d_4541b0(0xc9,0,0);
					}
					break;
				}
				case 0x82:	// redistribute integrity between the core and the parts
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_REDISTRIBUTE_INTEGRITY, found on " + getName());
						break;
					}
					{
						bool a7 = unknown8c < unknown5ca260() / 2;
						int amount = item->unknown457fb0();
						int transfers = 0;
						vector<YkHItem> changed3;
						if (a7)
						{
							vector<YkHItem> donors;
							vector<int> cd;
							int index;
							for (unsigned int i = 0; i < parts.size(); i++)
							{
								if (parts[i]->unknown44aec0() <= 3)
								{
									if (parts[i]->unknown9b6bf0() > parts[i]->unknown457c80() * yk_ba0bb4)
									{
										donors.push_back(parts[i]);
										cd.push_back(parts[i]->unknown9b6bf0() - (int)(parts[i]->unknown457c80() * yk_ba0bb4));
										if (cd.back() < amount)
										{
											donors.pop_back();
											cd.pop_back();
										}
									}
								}
							}
							while (unknown8c < unknown5ca260() && !donors.empty())
							{
								index = yk_OpQ5_randomIndex(donors);
								unknown8c++;
								transfers++;
								donors[index]->unknown458310(amount);
								cd[index] -= amount;
								if (!yk_OpU8a_containsEntity(changed3,donors[index]))
									changed3.push_back(donors[index]);
								if (cd[index] <= 0)
								{
									yk_OpQ5_eraseAt(donors,index);
									yk_removeVectorElement(cd,index);
								}
							}
						}
						else
						{
							int e5 = (int)(unknown8c - unknown5ca260() * yk_ba0bb4);
							vector<YkHItem> vDamaged;
							int aG;
							int aK;
							for (unsigned int i = 0; i < parts.size(); i++)
							{
								if (parts[i]->unknown44aec0() <= 3)
								{
									if (parts[i]->unknown457ca0() < 100)
										vDamaged.push_back(parts[i]);
								}
							}
							int repaired7 = 0;
							while (e5 != 0 && vDamaged.size() != 0)
							{
								aG = yk_OpQ5_randomIndex(vDamaged);
								unknown8c--;
								e5--;
								transfers++;
								aK = yk_minInt(amount,vDamaged[aG]->unknown457c80() - vDamaged[aG]->unknown9b6bf0());
								repaired7 += aK;
								vDamaged[aG]->unknown458360(aK);
								if (!yk_OpU8a_containsEntity(changed3,vDamaged[aG]))
									changed3.push_back(vDamaged[aG]);
								if (vDamaged[aG]->unknown9b6bf0() == vDamaged[aG]->unknown457c80())
									yk_OpQ5_eraseAt(vDamaged,aG);
							}
							if (isPlayer())
								yk_stats.add4729d0(0x178,repaired7,string(""),-1);
						}
						unknown5dea60(unknown8c,false);
						for (unsigned int i = 0; i < changed3.size(); i++)
						{
							YkCPart *part = yk_cparts->unknown894e70(changed3[i]);
							if (part != NULL)
								part->drawStatus(false);
						}
						MESSAGE((a7 ? 1 : 0) + 0xf7,&yk_intToString(transfers),NULL,0,self,YkHEntity(),NULL,0);
						HISTORY((a7 ? 1 : 0) + 0x40,&item->getName(0,0),&yk_intToString(transfers),0,YkHEntity(),0);
						yk_opR1d_4541b0(0xca,0,0);
					}
					break;
				}
				case 0x83:	// core heat dissipation
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_HEAT_DISSIPATION, found on " + getName());
						break;
					}
					{
						yk_unknownCf49dc += item->unknown457fb0();
						yk_unknownCf47c0++;
						MESSAGE(0xf9,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,self,YkHEntity(),NULL,0);
						HISTORY(0x42,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x84:	// core energy generation
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_ENERGY_GENERATION, found on " + getName());
						break;
					}
					{
						yk_unknownCf49d8 += item->unknown457fb0();
						yk_unknownCf47c0++;
						MESSAGE(0xfa,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,self,YkHEntity(),NULL,0);
						HISTORY(0x43,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x85:	// core attachment efficiency
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_ATTACHMENT_EFFICIENCY, found on " + getName());
						break;
					}
					{
						yk_unknownCf497c = item->unknown457fb0();
						yk_unknownCf47c0++;
						MESSAGE(0xfb,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
						HISTORY(0x44,&item->getName(0,0),NULL,0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x86:	// core matter restoration (once)
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_MATTER_RESTORATION, found on " + getName());
						break;
					}
					{
						if (yk_unknownCf4980)
							REJECT_PART(0xfd) else {
						yk_unknownCf4980 = true;
						yk_unknownCf47c0++;
						MESSAGE(0xfc,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
						HISTORY(0x45,&item->getName(0,0),NULL,0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
						}
					}
					break;
				}
				case 0x87:	// core corruption immunity (once)
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_CORRUPTION_IMMUNITY, found on " + getName());
						break;
					}
					{
						if (yk_unknownCf49f0)
							REJECT_PART(0x100) else {
						yk_unknownCf49f0 = true;
						yk_gameData.setEntryText("usedCoreMembrane_g","0");
						yk_unknownCf47c0++;
						MESSAGE(0xff,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
						HISTORY(0x46,&item->getName(0,0),NULL,0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
						}
					}
					break;
				}
				case 0x88:	// core thermoelectrics (slot type 0x13 only)
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_THERMOELECTRICS, found on " + getName());
						break;
					}
					{
						if (item->unknown457880() != 0x13)
							goto notConsumed;
						if (yk_unknownCf49f4 != 0 && yk_unknownCf49f4 <= item->unknown457fb0())
							REJECT_PART(0x102) else {
						yk_unknownCf49f4 = item->unknown457fb0();
						yk_unknownCf49f8 = item->unknown457fd0();
						yk_unknownCf47c0++;
						MESSAGE(0x101,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
						HISTORY(0x47,&item->getName(0,0),NULL,0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
						}
					}
					break;
				}
				case 0x89:	// core teleportitis
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_TELEPORTITIS, found on " + getName());
						break;
					}
					{
						yk_unknownCf49fc++;
						yk_unknownCf47c0++;
						yk_world->opw3_unknown72ec60();
						MESSAGE((yk_unknownCf49fc != 1) + 0x103,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
						HISTORY(0x48,&item->getName(0,0),NULL,0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
						if (yk_audio.enabled)
							yk_audio.unknown69e700(0x3e,firstTime != 0,0.0f);
					}
					break;
				}
				case 0x8a:	// core reset
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_CORE_RESET, found on " + getName());
						break;
					}
					{
						unknownB0 = 0;
						// parts whose type stays known
						vector<YkHItem> aD;
						for (unsigned int i = 0; i < parts.size(); i++)
						{
							if (parts[i]->unknown9b4350()->unknown94 == 1)
							{
								if (yk_unknownCf4830[parts[i]->unknown457820()] == 0)
									aD.push_back(parts[i]);
							}
						}
						yk_unknownCf4830.assign(yk_itemTypes.size(),0);
						yk_unknownCf4840 = 0;
						for (unsigned int i = 0; i < parts.size(); i++)
						{
							if (parts[i]->unknown44aec0() <= 4)
							{
								if (!yk_OpU8a_containsEntity(aD,parts[i]))
									yk_playerData.unknown77ffb0(parts[i]->unknown457820(),false);
							}
						}
						for (unsigned int i = 0; i < yk_itemTypes.size(); i++)
						{
							if (yk_itemTypes[i]->unknown44 < 6 || yk_itemTypes[i]->unknown94 == 3)
								yk_playerData.unknown77ffb0(i,false);
						}
						for (unsigned int i = 0; i < yk_itemTypes.size(); i++)
						{
							if (yk_unknownCf48cc[i] != 0)
							{
								yk_unknownCf48cc[i] = 0;
								yk_cparts->unknown896ab0(i);
								if (yk_unknownD28d68 == 3)
									yk_cparts->unknown896c20(i);
							}
						}
						yk_unknownCf48dc = 0;
						yk_unknownCf48e0.clear();
						yk_unknownCf48f0.clear();
						yk_unknownCf4900.clear();
						if (yk_unknownD28d68 == 3)
						{
							for (unsigned int i = 0; i < yk_itemTypes.size(); i++)
							{
								if (yk_unknownCf4844[i] != 0)
								{
									yk_unknownCf4844[i] = 0;
									yk_cparts->unknown896c20(i);
								}
							}
						}
						else yk_unknownCf4844.assign(yk_itemTypes.size(),0);
						yk_unknownCf4854 = 0;
						yk_unknownCf4858.clear();
						yk_unknownCf4868.clear();
						yk_unknownCf4878.clear();
						yk_unknownCf4888.assign(yk_entityRecords.size(),0);
						yk_unknownCf4898 = 0;
						yk_unknownCf489c.clear();
						yk_unknownCf48ac.clear();
						yk_unknownCf48bc.clear();
						yk_unknownCf4910.assign(yk_entityRecords.size(),0);
						yk_unknownCf4920 = 0;

						// forget map knowledge
						vector<vector<YkHMarker> > *markersTmp = yk_world->unknown463ec0();
						for (unsigned int i = 0; i < markersTmp->size(); i++)
							(*markersTmp)[i].clear();
						vector<vector<YkPoint> > *a9 = yk_world->unknown459070();
						for (unsigned int i = 0; i < a9->size(); i++)
						{
							// NOTE: the exe always indexes element 0 here
							for (unsigned int j = 0; j < (*a9)[0].size(); j++)
								yk_cells((*a9)[0][j])->getProp()->unknown45cb30()->unknown3c = 0;
						}
						yk_gameData.unknown783ae0(0);
						if (yk_unknownCf49e4)
						{
							yk_unknownCf49e4 = false;
							yk_unknownCf49e0 -= 10;
						}
						yk_gameData.setEntryText("extAcquiredA7DataCore_g","0");
						yk_unknownD1e970.init_9cf690(0x13,0x26,0);

						// yk_world map
						vector<YkHLocation> nodes;
						vector<YkHLocation> visited;
						yk_OpC_findNodes_470400(yk_unknownD1e884,nodes,visited);
						for (unsigned int i = 0; i < nodes.size(); i++)
							nodes[i]->unknown26 = false;

						// Zionites and allied factions turn hostile again
						vector<YkHEntity> &aX = yk_world->unknown463890(2)->unknown416f40();
						if (!aX.empty())
						{
							for (int i = aX.size() - 1; i >= 0; i--)
							{
								if (aX[i]->getName().find("Z_",0) != string::npos)
									aX[i]->changeFaction(yk_world->unknown463890(1),true);
							}
						}
						vector<YkHEntity> &a8 = yk_world->unknown463890(5)->unknown416f40();
						if (!a8.empty())
						{
							for (int i = a8.size() - 1; i >= 0; i--)
							{
								if (a8[i]->getFaction() == 0x3b || a8[i]->getFaction() == 0x3c || a8[i]->getFaction() == 0x3d || a8[i]->getName().find("Z_",0) != string::npos)
									a8[i]->changeFaction(yk_world->unknown463890(2),true);
							}
						}
						yk_cinventory->reopen(0,YkHItem());
						if (yk_audio.enabled && firstTime != 0)
							yk_audio.unknown69e700(0x3f,0,0.0f);
						yk_unknownCec138->unknown9675f0();
						vector<YkRect> gN(1);
						gN.front().set(0,0,yk_cells.getWidth(),yk_cells.getHeight());
						unknown602ec0(gN);
						yk_world->clearPoints7d0();
						for (unsigned int i = 0; i < yk_unknownD39f1c.size(); i++)
							yk_unknownD39f1c[i]->unknown30 = false;
						if (yk_stringToInt(yk_gameData.getEntryText("usedCoreResetMatrix_g")) == 0)
						{
							yk_stats.add472b90(0x40,-999999);
							HISTORY(0x31,&string("Core Reset Matrix"),NULL,0,YkHEntity(),0);
							yk_gameData.setEntryText("usedCoreResetMatrix_g",yk_intToString(yk_world->getTurn()));
						}
						yk_gameData.setEntryText("installedRif_g","0");
						yk_unknownCf4a04.assign((unsigned int)0x13,0);
						yk_unknownCf4a14.clear();

						// an attached RIF installer is rejected
						vector<YkCPart *> &slots = yk_cparts->unknown4a9ad0();
						for (unsigned int i = slots.size() - 1; i != 0; i--)
						{
							if (slots[i]->unknown4aeed0().isValid())
							{
								if (slots[i]->unknown4aeed0()->unknown457f90() == 0x7c)
								{
									MESSAGE(0x29e,&slots[i]->unknown4aeed0()->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
									yk_opR1d_4541b0(0xa5,0,0);
									slots[i]->unknown4aeed0()->unknown57dbe0(1,0,8,1);
								}
							}
						}
						yk_world->opw3_unknown72ea10();
						yk_gm->unknown793690();
					}
					break;
				}
				case 0x8b:	// terrabomb
				{
					MESSAGE(0x107,&item->getName(0,0),NULL,0,YkHEntity(),YkHEntity(),&getPosition(),0);
					HISTORY(0x31,&string("Terrabomb"),NULL,0,YkHEntity(),0);
					if (yk_audio.enabled)
						yk_audio.unknown98 = yk_world->unknown7151c0();
					yk_world->unknown747060(getPosition(),item->unknown457fb0(),item->unknown9b4350()->unknown190);
					break;
				}
				case 0x8d:	// applied to the item on the floor below
				{
					YkHItem target = yk_cells(getPosition())->getItem();
					if (target.isValid())
					{
						if (target->unknown457f90() == 0xb7)
						{
							if (target->getEffectValue(0x6a) != 0)
							{
								MESSAGE(0x10a,NULL,NULL,0,self,YkHEntity(),NULL,0);
								HISTORY(0x4b,&item->getName(0,0),&target->getName(0,0),0,YkHEntity(),0);
								if (yk_audio.enabled)
									yk_audio.unknownA0 = target->unknown9b4350()->unknown1a0->ID;
								yk_world->addRecord(yk_gm->createA(new YkObj515ca0(self,target->unknown9b4350()->unknown1a0,unknown45a4c0(),YkHEntity(),YkPoint(-1),YkPoint(-1))));
								target->unknown57dbe0(0,0,1,1);
							}
							else
							{
								MESSAGE(0x10c,&target->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
								target->addEffect(new YkItemEffect(yk_effectTypes[0x6a],1));
								item->unknown579170(aC);
								return 0;
							}
						}
						else if (target->unknown457f90() == 0xd6)
						{
							if (!yk_playerData.hasCompanion() || target->unknown457fb0() == 2)
								goto reject;
							yk_companion->upgrade(0,target->unknown457fb0() + 1);
							yk_opR1d_4541b0(0xce,0,0);
						}
						else
						{
							YkHItem gi;
							bool supercharged = false;
							if (target->unknown457860() == "Sigix Terminator" || target->unknown457860() == "Integrated Dissipator" || target->unknown457860() == "Integrated Reactor" || target->unknown457860() == "Transdimensional Reconstructor" || target->unknown457860() == "Hpw. Transdimensional Reconstructor" || target->unknown457860() == "Cep. Navigation Harness")
							{
								string i8("Supercharged ");
								if (target->unknown457860().find("Transdimensional Reconstructor",0) != string::npos)
									i8 += "TR";
								else if (target->unknown457860().find("Harness",0) != string::npos)
									i8 += "Navigation Harness";
								else i8 += target->unknown457860();
								YkItemData *type;
								yk_OpQ5_findByName(yk_itemTypes,i8,type);
								gi = yk_world->unknown6c5400(type,getPosition());
								supercharged = true;
							}
							else gi = yk_world->unknown6c5400(target->unknown9b4350(),getPosition());
							if (gi.isValid())
							{
								gi->unknown57c230(target.operator->());
								if (gi->unknown9b4350()->unknown76)
								{
									yk_unknownCf4810.push_back(gi->unknown9fcd80());
									yk_unknownCf4820.push_back(yk_unknownCf4830[gi->unknown457820()] != 0);
								}
								if (supercharged)
								{
									MESSAGE(0x109,&gi->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
									HISTORY(0x4a,&item->getName(0,0),&gi->getName(0,0),0,YkHEntity(),0);
									target->unknown57dbe0(0,0,1,1);
									if (gi->unknown457f90() == 0xd9)
										yk_playerData.unknown46df70();
								}
								else
								{
									MESSAGE(0x108,&target->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
									HISTORY(0x49,&item->getName(0,0),&target->getName(0,0),0,YkHEntity(),0);
									if (gi->unknown457860() == "Sigix Corpse")
									{
										YkHEntity sigix = yk_world->unknown715230(2,0x5e);
										if (sigix.isValid())
											yk_world->unknown6c65a0(sigix,"SEC_Sigix_Copy_Corpse",0);
										else
										{
											for (unsigned int i = 0; i < parts.size(); i++)
											{
												if (parts[i]->unknown457860() == "Sigix Containment Pod")
												{
													yk_world->unknown6c65a0(self,"SEC_Sigix_Copy_Corpse_P",0);
													break;
												}
											}
										}
									}
									else if (gi->unknown457860() == "Sigix Containment Pod")
										yk_world->unknown6c65a0(self,"SEC_Sigix_Copy_Pod",0);
								}
								yk_opR1d_4541b0(0xce,0,0);
							}
							else goto reject;
						}
					}
					else
					{
					reject:
						REJECT_PART(0x10b);
					}
					break;
				}
				case 0x8e:	// permanent integrity
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_INTEGRITY, found on " + getName());
						break;
					}
					{
						yk_unknownCf4954 += item->unknown457fb0();
						unknown5de870(item->unknown457fb0(),false);
						yk_unknownCf47c0++;
						MESSAGE(0x10d,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,self,YkHEntity(),NULL,0);
						HISTORY(0x4c,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x8f:	// permanent inventory capacity
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_INV_CAPACITY, found on " + getName());
						break;
					}
					{
						yk_unknownCf496c += item->unknown457fb0();
						yk_unknownCf47c0++;
						MESSAGE(0x10e,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,self,YkHEntity(),NULL,0);
						HISTORY(0x4d,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x90:	// permanent energy
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_ENERGY, found on " + getName());
						break;
					}
					{
						yk_unknownCf4970 += item->unknown457fb0();
						yk_unknownCf47c0++;
						MESSAGE(0x10f,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,self,YkHEntity(),NULL,0);
						HISTORY(0x4e,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x91:	// permanent matter
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_MATTER, found on " + getName());
						break;
					}
					{
						yk_unknownCf4974 += item->unknown457fb0();
						yk_unknownCf47c0++;
						MESSAGE(0x110,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,self,YkHEntity(),NULL,0);
						HISTORY(0x4f,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x92:	// permanent support
				{
					if (!isPlayer())
					{
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_SUPPORT, found on " + getName());
						break;
					}
					{
						yk_unknownCf4978 += item->unknown457fb0();
						yk_unknownCf47c0++;
						MESSAGE(0x111,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,self,YkHEntity(),NULL,0);
						HISTORY(0x50,&item->getName(0,0),&yk_intToString(item->unknown457fb0()),0,YkHEntity(),0);
						yk_opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
				case 0x93:	// permanent yk_resistances
				{
					if (!isPlayer())
						yk_logError("Entity::equipPart()","Only player should be able to use EFFECT_PERMANENT_RESISTANCE, found on " + getName());
					else
					{
						vector<int> values;
						item->unknown9b4350()->unknown56fc30(values);
						vector<string> it;
						for (unsigned int i = 0; i < values.size(); i++)
						{
							if (values[i] == 100)
								continue;
							int old = yk_resistances[i];
							yk_resistances[i] += values[i] - 100;
							yk_opw8_atLeast(&yk_resistances[i],0);
							if (yk_resistances[i] != old)
							{
								string change = yk_damageTypeNames[i] + " " + yk_OpY1_intToStringSigned(old - yk_resistances[i]) + "%";
								it.push_back(change);
							}
						}
						if (it.empty())
							MESSAGE(0x112,&item->getName(0,0),&string("no effect"),0,self,YkHEntity(),NULL,0);
						else
						{
							if (item->unknown457880() == 0x13)
								yk_unknownCf47c0++;
							string text = yk_opw8_countString(it.size(),"resistance") + " modified: ";
							text += it[0];
							for (unsigned int i = 1; i < it.size(); i++)
							{
								text += ", ";
								text += it[i];
							}
							MESSAGE(0x112,&item->getName(0,0),&text,0,self,YkHEntity(),NULL,0);
							HISTORY(0x51,&item->getName(0,0),&text,0,YkHEntity(),0);
						}
						yk_opR1d_4541b0(0xcb,0,0);
					}
					break;
				}
			}
			// the single-use part is consumed
			item->unknown579170(aC);
			item->unknown57dbe0(update,0,1,1);
			}
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
				MESSAGE(0x138,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
			vector<unsigned int> j4;
			if (fromEffect)
			{
				for (int i = 0; i < 6; i++)
				{
					if (yk_mildMalfunctions[i])
						j4.push_back((unsigned int)i);
				}
			}
			else
			{
				for (int i = 0; i < 6; i++)
					j4.push_back((unsigned int)i);
			}
			if (yk_unknownCf497c != 0 && isPlayer() && unknown94 >= 20 && rng.chance(50))
			{
				MESSAGE(0x139,&string("Integrated Mediator"),NULL,0,self,YkHEntity(),NULL,0);
				unknown45b1e0(20);
			}
			else
			{
				switch (yk_OpU8a_randomRec(j4))
				{
					case 0:
					{
						if (unknown90 == 0)
							break;
						int amount = yk_maxInt(1,rng.rangeInt(25,100) * unknown90 / 100);
						unknown45b1b0(amount);
						MESSAGE(0x13a,&item->getName(0,0),&yk_intToString(amount),0,self,YkHEntity(),NULL,0);
						yk_opR1d_4541b0(0x5e,0,0);
						break;
					}
					case 1:
					{
						YkRange countD;
						if (fromEffect)
							countD.set(1,2);
						else countD.set(1,3);
						YkRange percent;
						if (fromEffect)
							percent.set(10,20);
						else percent.set(20,50);
						MESSAGE(0x13b,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
						item->unknown57dbe0(update,1,1,1);
						int pDamaged = countD.randomInRange_40c130();
						vector<YkHItem> others;
						if (unknown5cb8b0(&others) != 0)
						{
							yk_shuffle(others);
							bool any = false;
							for (unsigned int i = 0; i < others.size() && (int)i < pDamaged; i++)
							{
								int integrity = others[i]->unknown9b6bf0();
								if (integrity > 1)
								{
									int damage = yk_maxInt(1,percent.randomInRange_40c130() * integrity / 100);
									MESSAGE(0x13c,&others[i]->getName(0,0),&yk_intToString(damage),0,self,YkHEntity(),NULL,0);
									any = true;
									others[i]->unknown57ab10(yk_minInt(others[i]->unknown9b6bf0() - 1,damage),1,0,0,YkHEntity(),0,0);
								}
							}
							if (any)
								yk_opR1d_4541b0(0x5e,0,0);
						}
						break;
					}
					case 2:
					{
						bool reported = false;
						vector<YkHItem> k5;
						if (unknown5cb930(&k5) != 0)
						{
							for (int i = k5.size() - 1; i >= 0; i--)
							{
								if (k5[i]->unknown457ad0() || k5[i]->unknown457880() >= 0x1a || k5[i]->unknown577fb0() != 0 || k5[i]->getEffect(0x55) != NULL || k5[i]->unknown9b4350()->unknown94 == 2)
									yk_OpQ5_eraseAt(k5,i);
							}
							if (!k5.empty())
							{
								YkHItem victim = yk_OpX5_randomRecord(k5);
								MESSAGE(0x13e,&victim->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
								victim->setBroken(-2,update);
								if (!reported)
								{
									MESSAGE(0x13d,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
									reported = true;
									if (yk_audio.enabled && yk_audio.unknown69eba0(victim))
										yk_audio.unknown69e700(1,0,0.0f);
								}
								yk_opR1d_4541b0(0x5e,0,0);
							}
						}
						break;
					}
					case 3:
					{
						YkRange percent;
						if (fromEffect)
							percent.set(30,50);
						else percent.set(25,75);
						vector<YkHItem> others;
						if (unknown5cb8b0(&others) != 0)
						{
							YkHItem victim = yk_OpX5_randomRecord(others);
							int lo = victim->unknown9b6bf0();
							if (lo > 1)
							{
								int damage = yk_maxInt(1,percent.randomInRange_40c130() * lo / 100);
								MESSAGE(0x13f,&item->getName(0,0),&victim->getName(0,0),&yk_intToString(damage),self,YkHEntity(),NULL,0);
								yk_opR1d_4541b0(0x5e,0,0);
								victim->unknown57ab10(yk_minInt(victim->unknown9b6bf0() - 1,damage),0,0,0,YkHEntity(),0,0);
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
							MESSAGE(0x140,&item->getName(0,0),&yk_intToString(amount),0,self,YkHEntity(),NULL,0);
							yk_audio.unknown69ea20(noHeat);
						}
						yk_opR1d_4541b0(0x5e,0,0);
						break;
					}
					case 5:
					{
						int amount = rng.rangeInt(yk_unknownB960f0,yk_unknownB960fc - 1);
						unknown45b210(amount);
						MESSAGE(0x141,&item->getName(0,0),&yk_intToString(amount),0,self,YkHEntity(),NULL,0);
						yk_opR1d_4541b0(0x5e,0,0);
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
				if (yk_unknownCf497c != 0 && unknown94 >= 20 && rng.chance(50))
				{
					MESSAGE(0x139,&string("Integrated Mediator"),NULL,0,self,YkHEntity(),NULL,0);
					unknown45b1e0(20);
				}
				else
				{
					MESSAGE(0x130,&item->getName(0,0),&yk_intToString(item->unknown457dd0()),0,self,YkHEntity(),NULL,0);
					int damage = unknown5defa0(item->unknown457dd0(),false);
					if (damage != 0)
					{
						yk_stats.add4729d0(0x8e,1,string(""),-1);
						yk_stats.add4729d0(0x8f,damage,string(""),-1);
						yk_playerData.unknown77fbc0(0x16);
						if (yk_unknownD28d4c)
							yk_unknownCec138->unknown965c10(0x28,false,true);
						int chance = (8 - damage) * 10;
						if (rng.chance(chance))
						{
							int sideEffect = rng.rangeInt(0,4);
							switch (sideEffect)
							{
								case 0:
								{
									bool reported = false;
									vector<YkHItem> nG;
									if (unknown5cb930(&nG) != 0)
									{
										for (int i = nG.size() - 1; i >= 0; i--)
										{
											if (nG[i]->unknown457ad0() || (nG[i]->unknown4578a0() != 2 && nG[i]->unknown4578a0() != 3))
												yk_OpQ5_eraseAt(nG,i);
										}
										if (!nG.empty())
										{
											yk_shuffle(nG);
											int count = rng.rangeInt(1,yk_minInt(3,nG.size()));
											for (int i = 0; i < count; i++)
											{
												YkHItem part = yk_OpX5_randomRecord(nG);
												unknown5fd550(part,rng.rangeInt(8,15));
												if (isPlayer())
												{
													YkCPart *cpart = yk_cparts->unknown894e70(part);
													if (cpart != NULL)
														cpart->unknown890710(0);
												}
												if (!reported)
												{
													MESSAGE(0x131,NULL,NULL,0,self,YkHEntity(),NULL,0);
													reported = true;
												}
												MESSAGE(0x132,&part->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
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
											YkCPart *cpart = yk_cparts->unknown894e70(item);
											if (cpart != NULL)
												cpart->unknown890710(0);
										}
										MESSAGE(0x132,&item->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
									}
									break;
								}
								case 2:
								{
									vector<YkHItem> others;
									if (unknown5cb8b0(&others) != 0)
									{
										for (unsigned int i = 0; i < others.size(); i++)
										{
											if (others[i]->unknown9b4350()->unknown1ac || others[i]->getEffect(0x6e) != NULL || others[i]->getEffect(0x6c) != NULL || others[i]->unknown457f90() == 7 || others[i]->unknown457f90() == 8 || others[i]->unknown457f90() == 9 || others[i]->unknown577fb0() != 0 || others[i] == item)
												yk_eraseStep(others,i);
										}
										if (!others.empty())
										{
											for (int count = rng.rangeInt(2,3); count > 0 && !others.empty(); count--)
											{
												YkHItem part = yk_OpS8c_popRandom(others);
												MESSAGE(0x133,&part->getName(0,0),NULL,0,self,YkHEntity(),NULL,0);
												unknown642940(part,true,true,false,4);
											}
										}
									}
									break;
								}
								case 3:
								{
									if (unknown90 == 0)
										break;
									{
										int integrity = item->unknown9b6bf0();
										if (integrity > 1)
										{
											int loss = yk_maxInt(1,rng.rangeInt(50,100) * unknown90 / 100);
											unknown45b1b0(loss);
											int aI = item->unknown9b6bf0();
											int damage = yk_maxInt(1,rng.rangeInt(20,50) * aI / 100);
											item->unknown57ab10(damage,1,0,0,YkHEntity(),0,0);
											MESSAGE(0x134,&item->getName(0,0),&yk_intToString(damage),0,self,YkHEntity(),NULL,0);
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
					case 8: yk_opw8_increase(&unknown90,item->unknown45cb30(),unknown5ca400()); break;
					case 9: yk_opw8_increase(&unknown94,item->unknown45cb30(),unknown5ca670()); break;
				}
				item->unknown44fc60(0);
			}
		}
		if (item->unknown457f90() == 0x18 || item->unknown457f90() == 0x1a || item->unknown457f90() == 0xd)
			yk_world->unknown463770(true);
		yk_stats.add4729d0(0x70,1,string(""),item->unknown9fcd80());
		switch (item->unknown4578a0())
		{
			case 0:
				yk_stats.add4729d0(0x71,1,string(""),item->unknown9fcd80());
				yk_stats.add4729d0(item->unknown457880() + 0x6c,1,string(""),item->unknown9fcd80());
				break;
			case 1:
				yk_stats.add4729d0(0x75,1,string(""),item->unknown9fcd80());
				yk_stats.add4729d0(item->unknown457880() + 0x6d,1,string(""),item->unknown9fcd80());
				break;
			case 2:
				yk_stats.add4729d0(0x7b,1,string(""),item->unknown9fcd80());
				yk_stats.add4729d0(item->unknown457880() + 0x6e,1,string(""),item->unknown9fcd80());
				break;
			case 3:
				yk_stats.add4729d0(0x82,1,string(""),item->unknown9fcd80());
				yk_stats.add4729d0(yk_minInt(item->unknown457880(),0x1d) + 0x6f,1,string(""),item->unknown9fcd80());
				break;
		}
	}

	if (item.operator->() != NULL && isPlayer())
	{
		switch (item->unknown457f90())
		{
			case 7:
				if (item->unknown457860() == "Lightpack 2.0")
					yk_unknownCf4a34 = unknown5c8db0();
				break;
			case 0x1f:
				yk_gm->unknown793690();
				yk_unknown789ac0();
				yk_opR1d_4541b0(0x55,0,0);
				break;
			case 0x4b:
				if (unknown5d2090(0x4b) >= 100)
					yk_playerData.unknown77fbc0(0xd1);
				break;
		}

		// attaching a part in front of watching Scraptown locals
		if (yk_location->type == 0xb && yk_stringToInt(yk_gameData.getEntryText("scrAttackedLocals_g")) == 0)
		{
			YkArea area;
			yk_cells.getBounds(getPosition(),5,&area);
			for (int x = area.min.x; x <= area.max.x; x++)
			{
				for (int y = area.min.y; y <= area.max.y; y++)
				{
					if (yk_world->unknown463190(x,y))
					{
						if (yk_cells(x,y)->getEntity().isValid() && yk_cells(x,y)->getEntity()->unknown45ac40(0x98) != NULL)
						{
							if (yk_cells(x,y)->getEntity()->getTarget() == 0)
							{
								yk_opW5_message(0x322,yk_cells(x,y)->getEntity(),&string("[name]: I am going to pretend I did not see you do that. For my sanity."),0);
								yk_cells(x,y)->getEntity()->unknown45b360(0x98);
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
		yk_cinventory->reopen(4,YkHItem());
		if (item.operator->() != NULL)
			yk_cparts->unknown897290(item,extra);
	}
	if (!yk_sceneConsole->isHidden())
		yk_sceneConsole->unknown8b4500(self,YkHEntity(),YkHEntity(),YkPoint(-1),0,0);
	if (reportAfter)
		unknown63a3e0(0,item);
	return yk_unknownB95fb4;
}
