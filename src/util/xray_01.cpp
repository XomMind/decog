// 0x6516b0 SEntityShoot::update (COGMIND.exe Beta 17.1, size 0x7380): byte-matched as XrShoot::update_6516b0.
// bool update(): runs one step of an entity's attack (all weapons of a volley, one after the other).
// Based on Heni's semantic draft (native/giants/6516b0_SEntityShoot_update.cpp); notes: scratch/xray/NOTES.md.
// All types, callees and globals use private Xr*/xr_* names so they stay stubs in the full link (same nothrow
// inference as a single-file build); they pair with the exe by address. NOTE: placeholder names/layouts throughout.
// Local variable names (aK, b0, ...) were chosen for their /Od stack-slot buckets, not for meaning.
#include <string>
#include <vector>
using namespace std;

//==================================================================
// Declarations
//==================================================================

struct XrPoint
{
	int x;
	int y;

	XrPoint();								// 0x453b40 (-1,-1)
	XrPoint(int v);							// 0x409990, (v,v)
	XrPoint(int x_, int y_);					// 0x46ca20
	XrPoint(const XrPoint &p) throw();					// 0x46ca50
	XrPoint(const XrPoint &a, const XrPoint &b);	// 0x4099f0 (sum)
	XrPoint &operator=(const XrPoint &p);		// 0x46ca50 (folded with the copy ctor)
	XrPoint &operator*=(int factor);			// NOTE: placeholder name (0x40a300)
	bool operator==(const XrPoint &p) const;	// 0x409b90
	bool operator!=(const XrPoint &p) const;	// 0x409bd0
};

struct XrArea	// NOTE: placeholder name
{
	XrPoint min;	// +0x0
	XrPoint max;	// +0x8

	XrArea();		// 0x40b100
};

struct XrRange	// NOTE: placeholder name
{
	int min;
	int max;

	int randomInRange_40c130();	// NOTE: placeholder name
};

struct XrFRange	// NOTE: placeholder name (OpQ1_FRange)
{
	float min;
	float max;

	float clamp_40c760(float value);	// NOTE: placeholder name
};

template <class T>
class XrArray2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;
public:
	T &operator()(const XrPoint &p);	// 0x9ced70
	T &operator()(int x, int y);	// 0x9ceda0
	bool contains(const XrPoint &p);	// NOTE: placeholder name (0x9b43b0)
	void getBounds(const XrPoint &p, int radius, XrArea *out);	// NOTE: placeholder name (0x9b4430)
	void getNeighbors_9ce500(const XrPoint &p, vector<XrPoint> &out);	// NOTE: placeholder name
};

class XrEntity;
class XrItem;
class XrProp;
class XrGroup;
class XrInventory;
class XrEntityAI;
struct XrItemData;
struct XrEntityData;
struct XrTurnRecord;

class XrHEntity
{
	int	ID;
public:
	XrHEntity();								// 0x9b6590
	bool isNull() const;					// 0x9b65d0
	bool isValid() const;					// 0x9b7230
	void clear();							// NOTE: placeholder name (0x9b7270)
	XrEntity *operator->() const;				// 0x9b6570
	bool operator==(XrHEntity other) const;	// 0x9b78e0
	bool operator!=(XrHEntity other) const;	// 0x9b6510
};

class XrHItem
{
	int	ID;
public:
	XrHItem();								// 0x9b6590
	bool isNull() const;					// 0x9b65d0
	bool isValid() const;					// 0x9b7230
	XrItem *operator->() const;				// 0x9b65b0
	bool operator!=(XrHItem other) const;		// 0x9b6510
};

class XrHProp
{
	int	ID;
public:
	XrHProp();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	XrProp *operator->() const;				// 0x9b64f0
};

class XrHGroup
{
	int	ID;
public:
	XrGroup *operator->() const;				// 0x9b7250
};

class XrHBattleState	// NOTE: placeholder name (handle of a battle state, SEntityShoot+0x04)
{
	int	ID;
public:
	XrHBattleState();							// 0x9b6590
};

class XrHRecord	// NOTE: placeholder name (handle returned by GM::createA, 0x7930e0)
{
	int	ID;
};

class XrGroup
{
public:
	int unknown9b4350();					// NOTE: placeholder name (ICF'd trivial getter of +0x08, the group type)
};

struct XrEffPair	// NOTE: placeholder name
{
	int		type;
	int		state;

	XrEffPair(int type_, int state_);		// 0x46ca20
	};

	XrEffPair::XrEffPair(int type_, int state_)
	{
		type = type_;
		state = state_;
	}

struct XrProjectileRecord	// NOTE: placeholder name (OpR2b_Rec501030; ItemData+0x190/+0x198 and the effect "type")
{
	struct XrVariant	// NOTE: placeholder name (elements of +0xc8)
	{
		int		unknown00;
		int		unknown04;
		int		unknown08;
		struct XrSprite	// NOTE: placeholder name
		{
			char	pad00[0x18];
			string	unknown18;	// +0x18
		}		*unknown0c;			// +0x0c
	};

	char			pad00[0x40];
	int				unknown40;		// +0x40
	bool			unknown44;		// +0x44
	char			pad45[0xc8 - 0x45];
	vector<XrVariant>	unknownC8;		// +0xc8

	bool unknown5012a0(const XrPoint &pos);	// NOTE: placeholder name
};

struct XrExplosionRecord	// NOTE: placeholder name (ItemData+0x1a0)
{
	char	pad00[0x2c];
	int		unknown2c;		// +0x2c (damage type)
	int		unknown30;		// +0x30
};

struct XrItemData	// NOTE: placeholder name (the weapon's item type)
{
	char				pad00[0x24];
	int					unknown24;	// +0x24
	char				pad28[0x44 - 0x28];
	int					unknown44;	// +0x44
	char				pad48[0x100 - 0x48];
	int					unknown100;	// +0x100
	char				pad104[0x11c - 0x104];
	int					unknown11c;	// +0x11c
	char				pad120[0x128 - 0x120];
	int					unknown128;	// +0x128
	char				pad12c[0x165 - 0x12c];
	bool				unknown165;	// +0x165
	char				pad166[2];
	int					unknown168;	// +0x168
	char				pad16c[0x174 - 0x16c];
	int					unknown174;	// +0x174
	char				pad178[0x190 - 0x178];
	XrProjectileRecord	*unknown190;	// +0x190
	char				pad194[4];
	XrProjectileRecord	*unknown198;	// +0x198
	char				pad19c[4];
	XrExplosionRecord		*unknown1a0;	// +0x1a0
};

class XrItem
{
public:
	int unknown9b6bf0();					// NOTE: placeholder name (ICF'd trivial getter of +0x1c)
	XrInventory *unknown44a7d0();				// NOTE: placeholder name (ICF'd trivial getter of +0x58)
	int unknown45cb30();					// NOTE: placeholder name (ICF'd trivial getter of +0x44, use count)
	XrItemData *unknown9b4350();				// NOTE: placeholder name (ICF'd trivial getter of +0x08, the data)
	const string &unknown457860();			// NOTE: placeholder name (data->+0x08, the data name)
	int unknown457880();					// NOTE: placeholder name (data->+0x44, slot)
	int unknown4578a0();					// NOTE: placeholder name (data->+0x48)
	int unknown4578c0();					// NOTE: placeholder name (data->+0x4c)
	int unknown457900();					// NOTE: placeholder name (data->+0x50)
	XrEffPair *getEffect(int type);		// NOTE: placeholder name (0x457b70)
	int getEffectValue(int type);			// NOTE: placeholder name (0x457be0)
	bool unknown457cf0();					// NOTE: placeholder name (+0x28 != -1)
	bool unknown457d10();					// NOTE: placeholder name (+0x2c < 0)
	int unknown457f90();					// NOTE: placeholder name (data->+0xf0, special type)
	int unknown457fb0();					// NOTE: placeholder name (data->+0xf4)
	int unknown4580a0();					// NOTE: placeholder name (data->+0x100, range)
	int unknown4580c0();					// NOTE: placeholder name (data->+0x104)
	int unknown458100();					// NOTE: placeholder name (data->+0x14c)
	int unknown458120();					// NOTE: placeholder name (data->+0x118, shots per volley)
	int unknown458160();					// NOTE: placeholder name (data->+0x15c)
	bool unknown458220();					// NOTE: placeholder name (+0x40)
	int unknown458240();					// NOTE: placeholder name (data->+0x160)
	void unknown458310(int amount);			// NOTE: placeholder name
	void unknown458580();					// NOTE: placeholder name (+0x44 += 1)
	void addEffect(XrEffPair *effect);		// NOTE: placeholder name (0x4585a0)
	void unknown4585c0(int type);			// NOTE: placeholder name (removes an effect)
	string getName(int a, int b);			// NOTE: placeholder name (0x571db0)
	int unknown5788e0();					// NOTE: placeholder name (energy cost)
	int unknown5789c0();					// NOTE: placeholder name (matter cost)
	int unknown578b10();					// NOTE: placeholder name
	void unknown578f20(vector<XrPoint> *out, int a);	// NOTE: placeholder name
	int unknown579050();					// NOTE: placeholder name
	float unknown579090();					// NOTE: placeholder name
	void setBroken(int a, bool b);			// 0x5795b0
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class XrInventory	// NOTE: placeholder name (OpT2_Inventory; Entity+0xec, Item+0x58)
{
public:
	vector<XrTurnRecord *> *unknown51ca20(vector<int> &types, XrHEntity e, XrHEntity a, XrHProp b, XrHItem c, int d, vector<XrTurnRecord *> *records, int *value, int f, int g);	// NOTE: placeholder name
};

class XrProp
{
public:
	void unknown664840(XrHEntity attacker, int type, vector<XrTurnRecord *> *records, XrItemData *weapon, float multiplier, bool a, int b, void *c);	// NOTE: placeholder name
};

struct XrEntityData	// NOTE: placeholder name (robot definition)
{
	string getName459c30();					// NOTE: placeholder name (OpR1e_Variant::getName459c30)
};

class XrEntityAI
{
public:
	bool unknown5814f0(XrHEntity e);			// NOTE: placeholder name
};

struct XrExplosionData;	// NOTE: opaque here

class XrEntity
{
public:
	XrEntityData *unknown9b4350();			// NOTE: placeholder name (ICF'd trivial getter of +0x08)
	const string &getLabel();				// NOTE: placeholder name (0x416f40, returns this+0x0c)
	int getFaction();						// 0x45a2c0
	int getSize();							// 0x45a360
	XrHGroup getGroup();						// 0x45a3f0
	string unknown45a410();					// NOTE: placeholder name
	const XrPoint &getPosition();				// 0x45a4a0
	XrPoint unknown45a4c0();					// NOTE: placeholder name
	int getTarget();						// NOTE: placeholder name (0x45a760, returns +0x70)
	int unknown45a8d0();					// NOTE: placeholder name (+0x90, energy)
	int unknown45a920();					// NOTE: placeholder name (+0x94, matter)
	bool isHostileTo(XrHEntity e);			// 0x45aa70
	bool unknown45aaa0(XrHEntity e);			// NOTE: placeholder name
	vector<XrHItem> *getInventoryList();		// 0x45ab00
	XrInventory *getInventory();				// 0x45ad90
	void unknown45b1b0(int amount);			// NOTE: placeholder name (energy -= amount)
	void unknown45b1e0(int amount);			// NOTE: placeholder name (matter -= amount)
	XrEntityAI *unknown45b590();				// NOTE: placeholder name (ICF'd trivial getter of +0x144, the AI)
	void unknown451600(XrHEntity e);			// NOTE: placeholder name (ICF'd setter of +0x118)
	int unknown490840();					// NOTE: placeholder name (ICF'd trivial getter of +0x8c)
	bool isPlayer();						// 0x5c7600
	int unknown5c7d30();					// NOTE: placeholder name
	int unknown5c7e90();					// NOTE: placeholder name
	int unknown5c7fc0(XrHEntity other);		// NOTE: placeholder name
	XrPoint unknown5c80f0(const XrPoint &p);	// NOTE: placeholder name
	bool unknown5c87f0(const XrPoint &p);		// NOTE: placeholder name
	int unknown5c8c40(int type);			// NOTE: placeholder name
	int unknown5cad50();					// NOTE: placeholder name
	int unknown5d2090(int type);			// NOTE: placeholder name
	int unknown5d22a0(int type);			// NOTE: placeholder name
	XrHItem unknown5d2380(int type);			// NOTE: placeholder name
	bool isXomCandidate();					// 0x5d51a0
	float unknown5d7bc0();					// NOTE: placeholder name
	float unknown5d7bf0(int damageType);	// NOTE: placeholder name
	void unknown5dea60(int amount, int a);	// NOTE: placeholder name
	void unknown5defa0(int amount, bool a);	// NOTE: placeholder name
	void projectileImpact(XrHEntity attacker, int type, vector<XrTurnRecord *> *records, XrItemData *weapon, float multiplier, XrPoint *origin, bool a, XrExplosionData *explosion, int *explosionDamage);	// 0x5f1010
	void unknown601700(XrHItem item);			// NOTE: placeholder name
	void unknown602170(XrHItem item, int direction);	// NOTE: placeholder name
	void unknown6028b0(XrHItem item);			// NOTE: placeholder name
	bool unknown603030(XrHItem item);			// NOTE: placeholder name
	bool unknown603280(XrHItem item);			// NOTE: placeholder name
	void die(bool unseen, int damageType, XrHEntity killer, int cause, int critType, struct XrDeathSource *source, vector<XrTurnRecord *> *records, bool quiet);	// 0x633790
	void unknown63c120();					// NOTE: placeholder name
	void unknown64e7e0(XrHItem item);					// NOTE: placeholder name (OpS3b_ItemOwner::unknown64e7e0)
};

class XrCell
{
public:
	XrHProp getProp();						// 0x45d550
	XrHEntity getEntity();					// 0x45d250
	int unknown45a6e0();					// NOTE: placeholder name (ICF'd trivial getter)
	bool canCaveIn();						// 0x66af50
	void unknown66d470(XrHEntity e, int amount, bool c, bool d);	// NOTE: placeholder name
	void destabilize(int amount, bool player);	// 0x66d4e0
	void unknown66e650(XrHEntity attacker, int type, vector<XrTurnRecord *> *records, XrItemData *weapon, float multiplier, bool a);	// NOTE: placeholder name
};

class XrObj515ca0	// NOTE: placeholder name; 0x40 bytes in the exe, layout not reconstructed
{
	int	data_[16];	// NOTE: placeholder layout
public:
	XrObj515ca0(XrHEntity a, XrExplosionRecord *id, const XrPoint &pos, XrHEntity b, const XrPoint &c, const XrPoint &d);	// 0x515ca0
};

struct XrE8_1	// NOTE: placeholder name (elements of SEntityShoot+0x2c)
{
	int unknown0;
};

class XrOpR2b_Obj500dd0	// NOTE: placeholder name (projectile; 100 bytes in the exe, layout not reconstructed)
{
	int	data_[25];	// NOTE: placeholder layout
public:
	XrOpR2b_Obj500dd0(XrItemData *weapon, XrHEntity shooter, int type, int range, float multiplier, XrHItem a, XrHItem b, int c, XrHBattleState state, vector<XrE8_1> *elems, vector<XrTurnRecord *> *records, int d);	// 0x500dd0
};

class XrOpR1F_Named460780	// NOTE: placeholder name (shot record; 0x3c bytes in the exe)
{
	int	data_[15];	// NOTE: placeholder layout
public:
	XrOpR1F_Named460780(string name, XrPoint from, XrPoint to, const XrPoint &subcell, const XrPoint &offset);	// 0x460780
};

struct XrClusterCell	// NOTE: placeholder name (0x10 bytes, elements of ClusterState::list)
{
	XrPoint	pos;		// +0x00
	int		amount;		// +0x08
	int		time;		// +0x0c

	XrClusterCell(XrPoint pos_, int amount_, int time_);	// NOTE: placeholder name (0x4606d0)
	};

	XrClusterCell::XrClusterCell(XrPoint pos_, int amount_, int time_)
		: pos(pos_)
	{
		amount = amount_;
		time = time_;
	}

struct XrClusterState	// NOTE: placeholder name (global at 0xd2a864)
{
	XrHEntity					owner;		// +0x00
	float					heat;		// +0x04, NOTE: placeholder name
	vector<XrClusterCell *>	list;		// +0x08
	XrPoint					origin;		// +0x18
	XrPoint					target;		// +0x20

	void unknown460700();				// NOTE: placeholder name (deletes the list entries)
};

class XrEffect	// NOTE: placeholder name
{
public:
	char	pad00[0x68];
	XrPoint	unknown68;	// +0x68
	XrPoint	unknown70;	// +0x70
};

class XrEffectInstance	// NOTE: placeholder name
{
public:
	void init(void *owner, XrProjectileRecord *type, const XrPoint &from, const XrPoint &to, XrPoint *p1, XrPoint *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class XrEffectMgr	// NOTE: placeholder name
{
public:
	XrEffectInstance *create();				// NOTE: placeholder name (0x508610)
	vector<XrEffect *> &unknown4549b0();		// NOTE: placeholder name (returns this+0x24)
};

class XrBresenham2DStepperSubcell
{
	int	data[11];	// NOTE: placeholder layout (base class Bresenham2DStepper + subcells)
public:
	XrBresenham2DStepperSubcell(const XrPoint &fromCell, const XrPoint &fromSubcell, const XrPoint &toCell, const XrPoint &toSubcell, int subcells_);	// 0x410320
	virtual ~XrBresenham2DStepperSubcell();	// 0x410400
	bool next(XrPoint &cell, XrPoint &subcell);	// NOTE: placeholder name (0x410420)
};

class XrMap	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	XrHEntity getPlayer();					// NOTE: placeholder name (0x4630f0)
	bool isVisible(const XrPoint &p);			// NOTE: placeholder name (0x4631c0)
	bool unknown4631f0(XrHEntity e);			// NOTE: placeholder name
	bool unknown463380(int x, int y);		// NOTE: placeholder name
	bool unknown4633c0(const XrPoint &p);		// NOTE: placeholder name
	int unknown463fa0();					// NOTE: placeholder name (+0xa70)
	int getTurn();							// 0x464270
	bool unknown464370();					// NOTE: placeholder name (+0xb06)
	bool unknown464390();					// NOTE: placeholder name (+0xb07)
	void addList9bc(XrHEntity e);				// NOTE: placeholder name (0x465360)
	void raiseUnknownA70(int value);		// NOTE: placeholder name (0x465490)
	void setFlagA74(bool flag);				// NOTE: placeholder name (0x4654d0)
	void unknown465a70();					// NOTE: placeholder name (+0xc14 += 1)
	bool unknown7170a0(XrHEntity e, const XrPoint &p, vector<XrPoint> &path, vector<int> &hits, vector<int> &blocks, XrPoint &last, const XrPoint *at, int atMode, bool f1, bool f2);	// NOTE: placeholder name
	bool unknown717e40(const XrPoint &from, const XrPoint &to, int range, XrPoint &cur, XrPoint &last, XrItemData *attack, vector<XrPoint> *hits);	// NOTE: placeholder name
	float unknown718430(XrHEntity e, const XrPoint &p, vector<float> *breakdown, int range);	// NOTE: placeholder name (melee hit chance)
	float unknown719a90(XrHEntity e, const XrPoint &p, vector<float> *breakdown, bool *sneakAttack);	// NOTE: placeholder name (ranged hit chance)
	void addEntitiesAround(XrHEntity e, vector<XrHEntity> *out);	// NOTE: placeholder name (0x71c550)
	void unknown732ce0(bool force);			// NOTE: placeholder name
	void setPausedShootState(XrHBattleState state);	// NOTE: placeholder signature (0x733070)
	void unknown735720(XrHEntity source, XrHEntity target, bool flag);	// NOTE: placeholder name
	void unknown7358c0(XrHEntity source, XrHEntity target);	// NOTE: placeholder name
	void thrownItemArrived(XrHEntity thrower, XrHItem item, int mode, const XrPoint &position, vector<XrTurnRecord *> *records);	// 0x7499f0
	void unknown74b060(const XrPoint &p, int type, int percent);	// NOTE: placeholder name
	XrHRecord addRecord(XrHRecord h);			// NOTE: placeholder name (0x777a20)
};

class XrGM	// NOTE: placeholder name (0xcefaa8)
{
public:
	XrHRecord createA(XrObj515ca0 *record);		// NOTE: placeholder name (0x7930e0)
};

class XrPlayerData	// NOTE: placeholder name (0xcf45d8)
{
public:
	bool isSlotEmpty(unsigned int index);	// NOTE: placeholder name (0x46de40); true while achievement <index> is not earned
	bool unknown77f260(int id);				// NOTE: placeholder name
	void unknown77fbc0(int id);				// NOTE: placeholder name; earns achievement <id>
	bool hasCompanion();					// NOTE: placeholder name (0x780790)
};

struct XrStatSet	// NOTE: placeholder name (OpR1h_StatSet)
{
	vector<int>	values;	// +0x00, NOTE: placeholder name
};

class XrOpR1h_Stats	// NOTE: placeholder name (0xd2c658)
{
public:
	XrStatSet		*current;	// +0x00

	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
	int unknown472c70(int id);				// NOTE: placeholder name (0x472c70, current->get472440(id))
};

class XrConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);			// NOTE: placeholder name
};

class XrCLogMsgs
{
public:
	void scrollToEnd();						// 0x7b4f10
};

class XrCPart
{
public:
	void unknown4a9120();					// NOTE: placeholder name (Calls_4a9120::delegate)
	void drawStatus(bool damaged);			// NOTE: placeholder name (0x4a8e70)
	void unknown890710(bool flag);			// NOTE: placeholder name
};

class XrCParts
{
public:
	XrCPart *unknown894e70(XrHItem item);		// NOTE: placeholder name
};

class XrAudio	// NOTE: placeholder name (0xd25450)
{
public:
	bool	enabled;		// +0x00

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
};

class XrSpawnTracker	// NOTE: placeholder name (OpU5_SpawnTracker)
{
public:
	bool spawn(unsigned int index, bool force, string extra);	// NOTE: placeholder name (0x7aa280)
};

class XrCompanion	// NOTE: placeholder name (OpS1f_ItemRec, pointer at 0xcf4ac8)
{
public:
	int				pad00[3];
	bool			unknown0c;		// +0x0c
	int				pad10;
	int				unknown14;		// +0x14
	int				pad18[6];
	XrSpawnTracker	*tracker;		// +0x30

	void increase48b8c0(int amount);		// NOTE: placeholder name (0x48b8c0)
};

class XrParticleMgr	// NOTE: placeholder name (OpV4a_EffectMgr, pointer at 0xcec138)
{
public:
	void unknown965430(int id);				// NOTE: placeholder name
	void unknown966c10(int id, int value);	// NOTE: placeholder name
};

class XrShoot	// NOTE: placeholder layout (vtable at +0x00; BattleState in src/op/op_s1d.cpp)
{
public:
	void				*vfptr_;				// +0x00
	XrHBattleState	handle;				// +0x04, NOTE: placeholder name
	int				state;				// +0x08, NOTE: placeholder name (0 new, 1 waiting, 2 firing)
	int				time;				// +0x0c, NOTE: placeholder name
	XrHEntity			shooter;			// +0x10, NOTE: placeholder name
	int				type;				// +0x14, NOTE: placeholder name (0 ranged, 1 melee)
	XrPoint			target;				// +0x18, NOTE: placeholder name
	XrPoint			targetSubcell;		// +0x20, NOTE: placeholder name
	XrHEntity			targetEntity;		// +0x28, NOTE: placeholder name
	vector<XrE8_1>	unknown2c;			// +0x2c
	bool			unknown3c;			// +0x3c
	bool			unknown3d;			// +0x3d
	bool			martialStrike;		// +0x3e, NOTE: placeholder name
	XrHEntity			unknown40;			// +0x40
	vector<XrHItem>	weapons;			// +0x44, NOTE: placeholder name
	int				index;				// +0x54, NOTE: placeholder name (next weapon)
	int				pending;			// +0x58, NOTE: placeholder name (projectiles in flight)
	int				unknown5c;			// +0x5c
	int				hits;				// +0x60, NOTE: placeholder name
	int				misses;				// +0x64, NOTE: placeholder name
	int				gunslingCount;		// +0x68, NOTE: placeholder name
	vector<XrPoint>	spreadTargets;		// +0x6c, NOTE: placeholder name

	bool update_6516b0();						// 0x6516b0
	XrPoint unknown658a70(const XrPoint &origin, XrPoint target, float spread);	// NOTE: placeholder name (miss deviation)
	bool unknown6591c0(XrHEntity e);		// NOTE: placeholder name
	bool unknown659220(XrHEntity e);		// NOTE: placeholder name
};

struct XrDeathSource;	// NOTE: opaque here

bool xr_unknown5111e0(int id, const string *text1, const string *text2, int value, XrHEntity subject, XrHEntity object, const XrPoint *pos, int extra);	// NOTE: placeholder name (show message)
void xr_unknown5141b0(int id, const string *a, const string *b, int c, XrHEntity e, int d);	// NOTE: placeholder name (history/log record)
void xr_opW5_message(int type, XrHEntity entity, const string &text, int flag);	// NOTE: placeholder name (0x49c610, adds a log message)
void xr_opW5_unknown49bde0(XrHEntity e);			// NOTE: placeholder name
void xr_opR1d_4541b0(int sound, int a, int b);	// NOTE: placeholder name (play sound)
void xr_logError(string location, string message);	// 0x404f10
string xr_intToString(int value);				// 0x4051f0
string xr_OpY1_intToStringSigned(int value);	// NOTE: placeholder name (0x405560, with a leading '+')
string xr_OpQ1_pointToString(const XrPoint &p);	// NOTE: placeholder name (0x40a4a0)
int xr_OpQ1_distanceCeil_40a3f0(const XrPoint &a, const XrPoint &b);	// NOTE: placeholder name
int xr_unknown4374c0(const XrPoint &from, const XrPoint &to);	// NOTE: placeholder name (direction from -> to)
bool xr_OpS1c_unknown4569a0(int id, XrHEntity a, XrHEntity b, XrHProp c, XrHItem item, int d, const string *name, void *e, XrHEntity f, XrHProp g, XrHItem h, int i);	// NOTE: placeholder name (0x4569a0, trigger)
void xr_opR1f_460820(XrOpR1F_Named460780 *entry);	// NOTE: placeholder name (adds a shot record, keeps 5)
void xr_opr2b_rotatePoint(const XrPoint &origin, const XrPoint &p, float angle, XrPoint &out);	// NOTE: placeholder name (0x501fc0)
void xr_OpS3b_f651590(XrItemData *data, XrPoint &from, XrPoint &to, vector<XrPoint> &fromOut, vector<XrPoint> &toOut);	// NOTE: placeholder name
int xr_minInt(int a, int b);					// 0x9cdb30
int xr_maxInt(int a, int b);					// 0x9cdb60
bool xr_containsPoint(vector<XrPoint> &v, XrPoint p);	// NOTE: placeholder name (0x9d0ce0)
bool xr_OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (low <= value <= high)
unsigned int xr_OpT8b_Fn9d9ab0(vector<float> &weights);	// NOTE: placeholder name (weighted random index)
template <class T> void xr_eraseAt(vector<T> &v, int i);		// NOTE: placeholder name (0x9da940/0x9d5190 family)
template <class T> void xr_eraseStep(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440, erases and steps i back)
template <class T> void xr_shuffle(vector<T> &v);				// NOTE: placeholder name (0x9d9fc0/0x9d7350)
template <class T> void xr_removeVectorElement(vector<T> &v, int i);	// 0x9de6f0

class XrRNG	// private stand-in for RNG (util/rng.h), declared throw() so the calls stay nothrow stubs
{
public:
	bool chance(int percent) throw();			// 0x406c90
	bool chance(float percent) throw();			// 0x406cc0
	int rangeInt(float a, float b) throw();		// 0x406d70
	float rangeFloat(float a, float b) throw();
};
extern XrRNG				rng;					// 0xd30908
extern const float			xr_flt1_b96368;			// 1.0f
extern XrMap					*xr_world;					// 0xcefc4c
extern XrEffectMgr			*xr_effectMgr;				// 0xcefc50
extern XrPoint				xr_effectOrigin;			// 0xd2e20c
extern XrArray2D<XrCell *>		xr_cells;					// 0xcfd44c
extern XrGM					*xr_gm;					// 0xcefaa8
extern XrPlayerData			xr_playerData;				// 0xcf45d8
extern XrOpR1h_Stats			xr_stats;					// 0xd2c658
extern XrConsoleA				*xr_consoleA;				// 0xcec058
extern XrCLogMsgs				*xr_logMsgs;				// 0xcec0b4
extern XrCLogMsgs				*xr_combatLog;				// 0xcec0c4, NOTE: placeholder name
extern XrCParts				*xr_cparts;				// 0xcec088
extern XrAudio				xr_audio;					// 0xd25450
extern vector<int>			xr_effectTypes;			// 0xd2f0f8
extern bool					xr_factionTableB951c0[];
extern int					xr_gameMode;				// 0xcf462c, NOTE: placeholder name
extern int					xr_unknownD28d18;			// combat log detail level
extern unsigned int			xr_tickCount;				// NOTE: placeholder name (0xcaed20)
extern int					xr_unknownCefa78;			// NOTE: placeholder name (time per update)
extern XrCompanion			*xr_unknownCf4ac8;
extern XrParticleMgr			*xr_unknownCec138;
extern int					xr_unknownCefb68;
extern int					xr_unknownBbca50[];
extern XrFRange				xr_unknownCf195c;			// ranged hit chance limits
extern XrFRange				xr_unknownD37978;			// melee hit chance limits
extern XrEntityData			*xr_unknownCefc0c;
extern int					xr_unknownCf4b98;
extern int					xr_unknownCf4b9c;			// consecutive melee hits
extern int					xr_unknownCf4ba0;			// consecutive melee misses
extern XrClusterState			xr_unknownD2a864;
extern XrRange				xr_unknownD35bd0;
extern bool					xr_unknownCefb25;			// debug flag
extern vector<string>		xr_unknownD2d4c8;			// debug log
extern vector<XrPoint>		xr_unknownD3976c;
extern vector<XrPoint>		xr_unknownD29d6c;
extern vector<XrPoint>		xr_unknownD2ac84;
extern string				xr_breakdownLabels[];		// 0xd37a90, NOTE: placeholder name (0x13 hit chance factors)
extern bool					xr_unknownBa0968[];
extern int					xr_unknownCefb38;

// message to the main log (0xcec0b4)
#define MESSAGE(id,text1,text2,value,subject,object,pos,extra) \
	do \
	{ \
		if (xr_unknown5111e0(id,text1,text2,value,subject,object,pos,extra)) \
			xr_consoleA->unknown8758d0(true); \
		xr_logMsgs->scrollToEnd(); \
	} while (0)
// message to the combat log (0xcec0c4)
#define COMBAT_MESSAGE(id,text1,text2,value,subject,object,pos,extra) \
	do \
	{ \
		if (xr_unknown5111e0(id,text1,text2,value,subject,object,pos,extra)) \
			xr_consoleA->unknown8758d0(false); \
		xr_combatLog->scrollToEnd(); \
	} while (0)
#define HISTORY(id,a,b,c,e,d) \
	do \
	{ \
		xr_unknown5141b0(id,a,b,c,e,d); \
	} while (0)
// percentage with rounding away from zero
#define PERCENT_ROUNDED(x) (int)(((x) + ((x) > 0 ? 0.005 : -0.005)) * 100.0)
// gunslinging is always available in this build (the exe tests the constant 100)
#define GUNSLINGING 100	// NOTE: placeholder name
// address of a temporary string that lives until the end of the full expression (the exe passes &temp)
#define TEMP_PTR(s) (&static_cast<const string &>(s))

//==================================================================
// SEntityShoot::update
//==================================================================

bool XrShoot::update_6516b0()
{
	if (shooter.operator->() == NULL || weapons.empty())
		return true;

	if (state == 0)
		state = 2;
	time += xr_unknownCefa78;

	switch (state)
	{
	case 1:
		return false;
	case 2:
	{
		// first weapon at an entity: notify the target and fire the attack triggers
		if (index == 0 && xr_cells(target)->getEntity().isValid())
		{
			XrHEntity victim = xr_cells(target)->getEntity();
			if (!unknown3c)
			{
				if (!unknown6591c0(victim))
					xr_world->unknown735720(shooter,victim,false);
				if (!unknown659220(victim))
					xr_world->unknown7358c0(shooter,victim);
			}
			xr_OpS1c_unknown4569a0(10,shooter,shooter,XrHProp(),XrHItem(),0,0,shooter->getInventory(),shooter,XrHProp(),XrHItem(),0);
			if (shooter.operator->() == NULL)
				return true;
			xr_OpS1c_unknown4569a0(9,shooter,victim,XrHProp(),XrHItem(),0,0,shooter->getInventory(),victim,XrHProp(),XrHItem(),0);
			if (shooter.operator->() == NULL)
				return true;
		}

		bool skipAnimation = false;
		nextWeapon:
		{
			if (shooter.operator->() == NULL)
				return true;

			// pick the next usable weapon
			while (true)
			{
				if (weapons[index].operator->() != NULL)
					weapons[index]->unknown458580();
				if (weapons[index].operator->() != NULL && weapons[index]->unknown458220())
				{
					if (shooter == xr_world->getPlayer())
					{
						xr_stats.add4729d0(0x1d2,1,string(""),-1);
						if (xr_stats.current->values[0x1d2] == 10)
							xr_playerData.unknown77fbc0(0x2c);
					}
					if (rng.chance(weapons[index]->unknown458160()))
						shooter->unknown601700(weapons[index]);
				}
				if (weapons[index].operator->() != NULL && weapons[index]->getEffect(0x5a) != NULL)
				{
					if (weapons[index]->getEffectValue(0x5b) == 0 || weapons[index]->unknown45cb30() > weapons[index]->getEffectValue(0x5b))
					{
						if (rng.chance(weapons[index]->getEffectValue(0x5a)))
							shooter->unknown6028b0(weapons[index]);
					}
				}
				if (weapons[index].operator->() != NULL)
				{
					if (weapons[index]->getEffect(0x5c) != NULL && (weapons[index]->getEffectValue(0x5d) == 0 || weapons[index]->unknown45cb30() > weapons[index]->getEffectValue(0x5d)))
					{
						float chance = weapons[index]->getEffectValue(0x5c) / 10.0f;
						if (weapons[index]->getEffectValue(0x5d) != 0 && weapons[index]->unknown45cb30() > weapons[index]->getEffectValue(0x5d))
						{
							for (int i = 2; ; i++)
							{
								if (weapons[index]->unknown45cb30() / weapons[index]->getEffectValue(0x5d) >= i)
									chance *= 2;
								else
									break;
							}
						}
						if (rng.chance(chance))
						{
							if (shooter->isPlayer())
							{
								MESSAGE(0x180,TEMP_PTR(weapons[index]->getName(0,0)),NULL,0,shooter,XrHEntity(),NULL,0);
								HISTORY(0x33,TEMP_PTR(weapons[index]->getName(0,0)),NULL,0,XrHEntity(),0);
							}
							weapons[index]->setBroken(-2,true);
						}
					}
					shooter->unknown603030(weapons[index]);
					shooter->unknown603280(weapons[index]);
				}

				if (weapons[index].operator->() == NULL)
				{
					xr_eraseAt(weapons,index);
					if (index == weapons.size())
						return true;
					else
						continue;
				}

				if (xr_world->unknown464370())
					break;

				int energy = weapons[index]->unknown5788e0();
				int b5 = weapons[index]->unknown5789c0();
				if (shooter->unknown45a8d0() - energy >= 0 && shooter->unknown45a920() - b5 >= 0 && !weapons[index]->unknown457d10())
				{
					shooter->unknown45b1b0(energy);
					shooter->unknown45b1e0(b5);
					break;
				}
				else
				{
					xr_eraseAt(weapons,index);
					if (index == weapons.size())
						return true;
				}
			}

			index++;
			pending = 0;
			bool aa = index == weapons.size();
			if (!aa && !skipAnimation)
				xr_world->unknown732ce0(true);
			skipAnimation = false;
			XrHItem weapon4 = weapons[index - 1];

			// player statistics, achievements and weapon sounds
			if (shooter == xr_world->getPlayer())
			{
				if (weapon4->unknown457880() >= 0x1a)
					xr_stats.add4729d0(0x1a3,1,string(""),-1);
				else
				{
					xr_stats.add4729d0(0x17d,1,string(""),-1);
					switch (weapon4->unknown457880())
					{
					case 0x14:
						if (xr_playerData.isSlotEmpty(0xd6) && weapon4->unknown4578c0() >= 4 && weapon4->getName(0,0).find("Storm") != string::npos)
							xr_playerData.unknown77fbc0(0xd6);
					case 0x16:
						xr_stats.add4729d0(0x17e,1,string(""),-1);
						break;
					case 0x15:
						if (xr_playerData.isSlotEmpty(0xdc) && weapon4->getName(0,0).find("Potential Cannon") != string::npos)
							xr_playerData.unknown77fbc0(0xdc);
						if (xr_playerData.isSlotEmpty(0x165) && weapon4->getName(0,0).find("L-Cannon") != string::npos)
							xr_playerData.unknown77fbc0(0x165);
					case 0x17:
						xr_stats.add4729d0(0x17f,1,string(""),-1);
						break;
					case 0x18:
						if (xr_playerData.isSlotEmpty(0x154) && weapon4->unknown457860() == "Supercharged Sigix Terminator")
							xr_playerData.unknown77fbc0(0x154);
						xr_stats.add4729d0(0x180,1,string(""),-1);
						break;
					case 0x19:
						xr_stats.add4729d0(0x181,1,string(""),-1);
						break;
					}
					if (weapons.size() == 1 && (weapon4->unknown457880() == 0x14 || weapon4->unknown457880() == 0x15) && xr_world->getPlayer()->unknown5d22a0(0x4e) && !weapons[0]->unknown9b4350()->unknown165)
						xr_stats.add4729d0(0x190,1,string(""),-1);
				}

				int damageType = weapon4->unknown9b4350()->unknown1a0 != NULL ? weapon4->unknown9b4350()->unknown1a0->unknown2c : (weapon4->unknown9b4350()->unknown190 != NULL ? weapon4->unknown9b4350()->unknown128 : 10);
				if (damageType != 9)
				{
					if (weapon4->unknown457880() >= 0x1a)
						xr_stats.add4729d0(damageType + 0x1a4,1,string(""),-1);
					else
						xr_stats.add4729d0(damageType + 0x182,1,string(""),-1);
				}

				if (weapon4->unknown457860().find("Sigix Terminator",0) != string::npos || weapon4->unknown457860().find("L-Cannon",0) != string::npos)
				{
					HISTORY(0x34,&weapon4->unknown457860(),NULL,0,XrHEntity(),0);
					if (xr_audio.enabled && weapon4->unknown457860().find("L-Cannon",0) != string::npos)
					{
						if (weapon4->unknown457860().find("Drained",0) != string::npos)
							xr_audio.unknown69e700(0x45,3,100.0f);
						else
							xr_audio.unknown69e700(0x45,0,0.0f);
					}
				}

				if (weapon4->unknown457f90() == 0xd6 && xr_unknownCf4ac8 != NULL)
					xr_unknownCf4ac8->unknown14++;

				if (weapon4->unknown458220())
					xr_unknownCec138->unknown965430(weapon4->unknown457900());

				if (weapon4->unknown9b4350()->unknown44 == 0x15 && weapon4->unknown9b4350()->unknown128 == 1 && !weapon4->unknown9b4350()->unknown190->unknownC8.empty()
					&& string(weapon4->unknown9b4350()->unknown190->unknownC8.front().unknown0c->unknown18.end() - 3,weapon4->unknown9b4350()->unknown190->unknownC8.front().unknown0c->unknown18.end()) == "_CH")
					xr_unknownCec138->unknown966c10(weapon4->unknown457900(),weapon4->unknown9b4350()->unknown190->unknown40);
			}

			// some weapons destabilize the ceiling
			if (xr_OpT8b_Fn9daf80(0x14,weapon4->unknown457880(),0x1e))
			{
				if (xr_cells(shooter->unknown45a4c0())->canCaveIn())
					xr_cells(shooter->unknown45a4c0())->destabilize(weapon4->unknown457880() - 0x12,shooter->isPlayer());
			}

			// follow-up attacks pick a new hostile target
			if (type == 0 && index > 1 && weapon4->unknown457f90() == 0xd6 && weapons[0].operator->() != NULL && weapons[0]->unknown457f90() == 0xd6 && targetEntity.isValid())
			{
				vector<XrHEntity> candidates;
				xr_world->addEntitiesAround(shooter,&candidates);
				if (!candidates.empty())
				{
					for (unsigned int i = 0; i < candidates.size(); i++)
					{
						if (!candidates[i]->isHostileTo(shooter) || candidates[i] == targetEntity)
							xr_eraseStep(candidates,i);
					}
					xr_shuffle(candidates);
				}
					if (candidates.empty())
						return true;
					else
					{
						target = candidates[0]->unknown5c80f0(shooter->getPosition());
						targetEntity = candidates[0];
						goto targetChosen;
					}
				}
				if (type == 0 && index > 1)
				{
					if (xr_cells(target)->getEntity().isNull() || !shooter->unknown5c87f0(target))
					{
						if (rng.chance(shooter->unknown5d2090(0x5a) * 2 + 100))
						{
						vector<XrHEntity> candidates;
					xr_world->addEntitiesAround(shooter,&candidates);
					if (!candidates.empty())
					{
						for (unsigned int i = 0; i < candidates.size(); i++)
						{
							if (!candidates[i]->isHostileTo(shooter))
								xr_eraseStep(candidates,i);
						}
						xr_shuffle(candidates);
					}
										if (candidates.empty())
											return true;
										else
										{
											target = candidates[0]->unknown5c80f0(shooter->getPosition());
											targetEntity = candidates[0];
										}
										}
										else
											return true;
									}
								}
					targetChosen:

								// gunslinging: a melee volley whose locked target died picks another one in range
			if (type == 1 && index > 1 && unknown40.isValid() && unknown40.operator->() == NULL)
			{
				unknown40.clear();
				if (GUNSLINGING)
				{
					int range8 = 999999;
					for (unsigned int i = index - 1; i < weapons.size(); i++)
					{
						if (weapons[i].operator->() != NULL && weapons[i]->unknown4580a0() < range8)
							range8 = weapons[i]->unknown4580a0();
					}

					vector<XrPoint> positions;
					vector<float> ct;
					XrArea area_;
					xr_cells.getBounds(shooter->getPosition(),shooter->unknown5c7d30(),&area_);
					for (int y = area_.min.y; y <= area_.max.y; y++)
					{
						for (int x = area_.min.x; x <= area_.max.x; x++)
						{
							if (xr_world->unknown463380(x,y) && xr_cells(x,y)->getEntity().isValid() && xr_cells(x,y)->getEntity() != shooter && shooter->isHostileTo(xr_cells(x,y)->getEntity()) && xr_cells(x,y)->getEntity()->isXomCandidate() && xr_cells(x,y)->getEntity()->getTarget() == 0)
							{
								if (!(xr_gameMode == 0xb && shooter->getGroup()->unknown9b4350() == 3 && xr_cells(x,y)->getEntity()->isPlayer() && xr_playerData.unknown77f260(100)))
								{
									if (xr_OpQ1_distanceCeil_40a3f0(shooter->getPosition(),XrPoint(x,y)) <= range8)
									{
										if (!(shooter->getGroup()->unknown9b4350() == 3 && !xr_cells(x,y)->getEntity()->unknown5d2380(0x1f).isNull()))
										{
											if (!xr_containsPoint(positions,XrPoint(x,y)))
											{
												positions.push_back(XrPoint(x,y));
												ct.push_back(xr_world->unknown718430(shooter,XrPoint(x,y),NULL,0));
											}
										}
									}
								}
								}
								}
					}

					while (!positions.empty())
					{
						unsigned int nPick = xr_OpT8b_Fn9d9ab0(ct);
						if (xr_cells(positions[nPick])->getEntity()->getSize() > 1)
						{
							XrPoint pos = xr_cells(positions[nPick])->getEntity()->unknown5c80f0(shooter->getPosition());
							if (xr_world->unknown4633c0(pos))
								positions[nPick] = pos;
							else
							{
								xr_eraseAt(positions,nPick);
								xr_removeVectorElement(ct,nPick);
								continue;
							}
						}

						vector<XrPoint> path;
						vector<int> hitList;
						vector<int> blocks;
						XrPoint a5;
						if (!xr_world->unknown7170a0(shooter,positions[nPick],path,hitList,blocks,a5,NULL,4,true,true))
						{
							xr_eraseAt(positions,nPick);
							xr_removeVectorElement(ct,nPick);
							continue;
						}
						target = positions[nPick];
						targetEntity = xr_cells(positions[nPick])->getEntity();
						unknown40 = xr_cells(target)->getEntity();
						shooter->unknown451600(targetEntity);
						if (shooter->isPlayer())
						{
							MESSAGE(0xb1,&xr_cells(target)->getEntity()->getLabel(),NULL,0,shooter,XrHEntity(),NULL,0);
							string text = " Gunslinging -> " + xr_cells(target)->getEntity()->getLabel();
							if (xr_unknownD28d18 >= 0)
								COMBAT_MESSAGE(0x2e1,&text,NULL,0,shooter,XrHEntity(),NULL,1);
							xr_stats.add4729d0(0x18e,1,string(""),-1);
							gunslingCount++;
							xr_stats.add4729d0(0x18f,gunslingCount,string(""),-1);
							xr_world->addList9bc(unknown40);
						}
						break;
					}
				}
			}

			// hit chance
			vector<float> b0;
			if (index == 1 && shooter == xr_world->getPlayer() && xr_unknownD28d18 == 1)
				b0.assign(0x13,0.0f);

			bool aG = false;
			int maxRange = 0;
			if (shooter->isPlayer() && type == 1)
			{
				for (unsigned int i = 0; i < weapons.size(); i++)
				{
					if (weapons[i].operator->() != NULL && weapons[i]->unknown4580a0() > maxRange)
						maxRange = weapons[i]->unknown4580a0();
				}
			}

			float baseHit = type == 0 ? xr_world->unknown719a90(shooter,target,b0.empty() ? NULL : &b0,&aG) : xr_world->unknown718430(shooter,target,b0.empty() ? NULL : &b0,maxRange);

			if (type == 0)
			{
				if (aG)
				{
					MESSAGE(shooter->isPlayer() ? 0xa7 : (shooter->unknown45aaa0(xr_world->getPlayer()) ? 0xa8 : 0xa9),&xr_cells(target)->getEntity()->getLabel(),NULL,0,shooter,XrHEntity(),NULL,0);
					if (shooter->isPlayer() && xr_cells(target)->getEntity()->getTarget() < 6)
					{
						xr_stats.add4729d0(0x1ad,1,string(""),-1);
						if (shooter->isHostileTo(xr_cells(target)->getEntity()) && xr_factionTableB951c0[xr_cells(target)->getEntity()->getFaction()] && xr_cells(target)->getEntity()->getTarget() == 0)
						{
							xr_stats.add4729d0(0x1ae,1,string(""),-1);
							if (xr_stats.current->values[0x1ae] == 0xf)
								xr_playerData.unknown77fbc0(0xaf);
							if (weapon4->unknown457f90() == 0xd6 && xr_playerData.hasCompanion())
								xr_unknownCf4ac8->tracker->spawn(0x25,false,xr_cells(target)->getEntity()->unknown9b4350()->getName459c30());
						}
					}
				}

				if (index > 1 && xr_cells(target)->getEntity().isValid())
				{
					bool followUp = weapon4->unknown457f90() == 0xd6 && weapons[index - 2].operator->() != NULL && weapons[index - 2]->unknown457f90() == 0xd6;
					MESSAGE(followUp ? 0xad : (shooter->isPlayer() ? 0xaa : (shooter->unknown45aaa0(xr_world->getPlayer()) ? 0xab : 0xac)),TEMP_PTR(weapon4->getName(0,0)),&xr_cells(target)->getEntity()->getLabel(),0,shooter,XrHEntity(),NULL,0);
					if (shooter->isPlayer())
					{
						xr_stats.add4729d0(0x1af,1,string(""),-1);
						if (!followUp && xr_unknownCf4ac8 != NULL && weapon4->unknown457f90() == 0xd6 && !xr_unknownCf4ac8->unknown0c)
						{
							xr_unknownCf4ac8->increase48b8c0(xr_unknownBbca50[0]);
							if (weapons[index - 2].operator->() != NULL && xr_playerData.hasCompanion())
								xr_unknownCf4ac8->tracker->spawn(5,false,weapons[index - 2]->getName(0,0));
						}
					}
					if (followUp && xr_playerData.hasCompanion())
						xr_unknownCf4ac8->tracker->spawn(0x11,false,xr_cells(target)->getEntity()->unknown9b4350()->getName459c30());
				}
			}

			if (!b0.empty())
			{
				string text("Base Hit%: ");
				for (int i = 0; i < 0x13; i++)
				{
					if (b0[i] * 100.0 != 0)
					{
						if (i != 0)
							text += xr_OpY1_intToStringSigned(PERCENT_ROUNDED(b0[i]));
						else
							text += xr_intToString(PERCENT_ROUNDED(b0[i]));
						text += xr_breakdownLabels[i];
					}
				}
				text += "=";
				if (aG)
					text += "N/A (" + xr_intToString(PERCENT_ROUNDED(baseHit)) + ")";
				else
					text += xr_intToString(PERCENT_ROUNDED(baseHit));
				COMBAT_MESSAGE(0x2e1,&text,NULL,0,XrHEntity(),XrHEntity(),NULL,1);
			}

			// fire every shot of the weapon
			bool animated = false;
			bool countedHit = false;
			int aK = 0;
			xr_unknownCefb68 = 0;
			for (int shot = 0; weapon4.operator->() != NULL && shot < weapon4->unknown458120(); shot++)
			{
				if (shooter.operator->() == NULL)
					return true;

				if (weapon4->unknown9b4350()->unknown128 == 0)
					unknown5c++;
				if (unknown5c == 10 && shooter->isPlayer())
					xr_playerData.unknown77fbc0(0x8d);

				vector<XrTurnRecord *> *aN = NULL;
				if (weapon4->unknown44a7d0() != NULL)
				{
					vector<int> types;
					types.push_back(0x14);
					types.push_back(0x15);
					types.push_back(0x16);
					types.push_back(0x17);
					types.push_back(0x18);
					types.push_back(0x19);
					if (type != 0)
					{
						types.push_back(0x22);
						types.push_back(0x23);
					}
					aN = weapon4->unknown44a7d0()->unknown51ca20(types,shooter,XrHEntity(),XrHProp(),XrHItem(),0,aN,&weapon4->unknown9b4350()->unknown174,0,0);
					if (type != 0)
					{
						types.clear();
						types.push_back(0x20);
						types.push_back(0x21);
						aN = weapon4->unknown44a7d0()->unknown51ca20(types,shooter,XrHEntity(),XrHProp(),XrHItem(),0,aN,&weapon4->unknown9b4350()->unknown24,0,0);
					}
				}

				float a1 = weapon4->unknown578b10() / 100.0;
				float aH = weapon4->unknown457880() == 0x18 ? shooter->unknown5d2090(0x5d) / 100.0 : 0;
				float e5 = type == 0 && index > 1 ? 0.1f : 0;
				float chance = baseHit + a1 + aH + e5;
				float aA = 0;
				int a_ = shooter->unknown5c7e90();
				int total2 = 0;
				for (unsigned int i = 0; i < weapons.size(); i++)
				{
					if (weapons[i] != weapon4 && weapons[i].operator->() != NULL)
					{
						aA += xr_maxInt(0,weapons[i]->unknown458100() - a_) / 100.0;
						total2 += xr_minInt(weapons[i]->unknown458100(),a_);
					}
				}
				chance -= aA;
				chance = type != 0 ? xr_unknownD37978.clamp_40c760(chance) : xr_unknownCf195c.clamp_40c760(chance);
				if (total2 >= 0x10 && shooter->isPlayer())
					xr_playerData.unknown77fbc0(0x8e);

				bool aB = false;
				bool en = false;
				if (xr_world->unknown464390() || weapon4->unknown4580c0() >= 1)
				{
					chance = 1;
					aB = true;
				}
				else if (type == 0 && index > 1 && weapon4->unknown457f90() == 0xd6 && weapons[0].operator->() != NULL && weapons[0]->unknown457f90() == 0xd6)
				{
					chance = 1;
					aB = true;
					en = true;
				}

				if (weapon4->getEffectValue(0x3f))
				{
					vector<XrHItem> *inventory = shooter->getInventoryList();
					for (unsigned int i = 0; i < inventory->size(); i++)
					{
						if ((*inventory)[i]->unknown4578a0() == 0 && (*inventory)[i]->unknown457cf0())
							goto activeFound;
					}
					chance = 0;
				}
activeFound:
				bool hit3 = rng.rangeFloat(0,1) <= chance;
				if (hit3 && shooter->unknown9b4350() == xr_unknownCefc0c && rng.chance(50))
					hit3 = false;
				if (hit3)
					aK++;

				if (targetEntity.operator->() != NULL && targetEntity->isPlayer())
				{
					xr_stats.add4729d0(0x165,1,string(""),-1);
					if (hit3)
					{
						xr_stats.add4729d0(0x169,1,string(""),-1);
						xr_stats.add4729d0(0x16a + (type != 0),1,string(""),-1);
					}
					else
						xr_stats.add4729d0(0x166,1,string(""),-1);
				}

				// combat log line after the last shot
				if (xr_unknownD28d18 >= 0 && shot == weapon4->unknown458120() - 1)
				{
					string text(" ");
					if (shooter != xr_world->getPlayer())
					{
						text.append(shooter->unknown45a410());
						text += ": ";
					}
					text += weapon4->getName(0,0);
					if (en)
						text += " surprise attack";
					else
					{
						if (e5 != 0)
							text += " follow-up";
						if (aG)
							text += " sneak attack";
						if (martialStrike)
							text += " martial strike";
					}
					text += " (";
					if (xr_unknownD28d18 >= 0 && shooter == xr_world->getPlayer() && !aB && (a1 != 0 || aH != 0 || e5 != 0 || aA != 0))
					{
						text += xr_intToString((int)(baseHit * 100.0));
						if (a1 != 0)
							text += xr_OpY1_intToStringSigned(PERCENT_ROUNDED(a1));
						if (aH != 0)
							text += xr_OpY1_intToStringSigned((int)((aH + 0.005) * 100.0));
						if (e5 != 0)
							text += xr_OpY1_intToStringSigned((int)((e5 + 0.005) * 100.0));
						if (aA != 0)
							text += xr_OpY1_intToStringSigned((int)(-(aA + 0.005) * 100.0));
						text += "=";
					}
					text += xr_intToString((int)((chance + 0.005) * 100.0));
					text += "%) ";
					bool gN;
					if (shot != 0)
					{
						text += xr_intToString(aK) + "/" + xr_intToString(weapon4->unknown458120()) + " Hit";
						gN = aK;
					}
					else
					{
						text += hit3 ? "Hit" : "Miss";
						gN = hit3;
					}
					if (xr_world->getPlayer().operator->() != NULL)
					{
						xr_opW5_unknown49bde0(shooter);
						if (shooter->isPlayer())
							COMBAT_MESSAGE(gN ? 0x2c0 : 0x2c1,&text,NULL,0,shooter,XrHEntity(),NULL,1);
						else if (shooter->unknown5c7fc0(xr_world->getPlayer()) == 2)
							COMBAT_MESSAGE(gN ? 0x2c2 : 0x2c3,&text,NULL,0,shooter,XrHEntity(),NULL,1);
						else
							COMBAT_MESSAGE(gN ? 0x2c4 : 0x2c5,&text,NULL,0,shooter,XrHEntity(),NULL,1);
					}
				}

				// a ranged miss with no line of fire to animate
				if (!hit3 && type == 0)
				{
					misses++;
					if (xr_world->isVisible(target))
					{
						xr_world->setFlagA74(true);
						xr_effectMgr->create()->init(xr_effectMgr,weapon4->unknown9b4350()->unknown198,target,targetSubcell,NULL,NULL,NULL,9,0);
						xr_world->raiseUnknownA70(200);
						xr_world->setFlagA74(false);
						animated = true;
					}
					else
						skipAnimation = true;
					goto nextShot;
				}

				{
				XrPoint origin = shooter->unknown5c80f0(target);
				XrPoint aim2;
				if (hit3)
				{
					hits++;
					if (!countedHit)
					{
						if (shooter->isPlayer() && xr_cells.contains(target) && xr_cells(target)->getEntity().isValid())
						{
							countedHit = true;
							xr_stats.add4729d0(0x192,1,string(""),-1);
						}
					}
					if (shooter->isPlayer() && xr_cells.contains(target) && xr_cells(target)->getEntity().isValid() && type == 1)
					{
						xr_unknownCf4ba0 = 0;
						xr_unknownCf4b9c++;
						xr_stats.add4729d0(0x18b,xr_unknownCf4b9c,string(""),-1);
						if (xr_stats.current->values[0x18b] == 10)
							xr_playerData.unknown77fbc0(0x23);
					}
					aim2 = target;
				}
				else
				{
					misses++;
					if (shooter->isPlayer() && xr_cells.contains(target) && xr_cells(target)->getEntity().isValid() && type == 1)
					{
						xr_unknownCf4b9c = 0;
						xr_unknownCf4ba0++;
						xr_stats.add4729d0(0x18c,xr_unknownCf4ba0,string(""),-1);
						if (xr_stats.current->values[0x18c] == 5)
							xr_playerData.unknown77fbc0(0x22);
					}
					aim2 = unknown658a70(origin,target,0.25f);
				}

				// spread: shots of one volley avoid each other's aim points
				if (weapon4->unknown9b4350()->unknown11c != 0 && aim2 != origin)
				{
					int spread0 = weapon4->unknown9b4350()->unknown11c;
					int attempts = 0;
					do
					{
						int factor;
						switch (xr_OpQ1_distanceCeil_40a3f0(origin,aim2))
						{
						case 1: factor = 20; break;
						case 2: factor = 10; break;
						case 3: factor = 7; break;
						default: factor = 5; break;
						}
						XrPoint delta1(aim2.x - origin.x,aim2.y - origin.y);
						delta1 *= factor;
						XrPoint theFar(origin,delta1);
						int angle = rng.rangeInt(-spread0 / 2,spread0 / 2);
						if (angle < 0)
							angle += 360;
						xr_opr2b_rotatePoint(origin,theFar,(float)angle,aim2);
						attempts++;
						} while (attempts < 10 && xr_containsPoint(spreadTargets,aim2));
					spreadTargets.push_back(aim2);
				}

				xr_opR1f_460820(new XrOpR1F_Named460780(shooter->getLabel(),target,aim2,targetSubcell,target == aim2 ? XrPoint(0) : XrPoint(aim2.x - target.x,aim2.y - target.y)));

				if (aim2 == origin)
				{
					xr_logError("SEntityShoot::update()","target matches origin, aborting attack");
					return true;
				}

				// damage multiplier
				float a8 = 1.0f;
				if (weapon4->unknown458220())
					a8 = shooter->unknown5d7bc0();
				else if (type == 0)
				{
					a8 = shooter->unknown5d7bf0(weapon4->unknown9b4350()->unknown128);
					if (shooter->isPlayer() && shooter->unknown5c8c40(3))
						shooter->unknown63c120();
					if (xr_cells(target)->getEntity().isValid())
					{
						if (xr_cells(target)->getEntity()->unknown45b590() != NULL && xr_cells(target)->getEntity()->unknown45b590()->unknown5814f0(shooter))
							a8 += xr_flt1_b96368;
						if (shooter->isPlayer() && xr_playerData.isSlotEmpty(0x33) && xr_cells(target)->getEntity()->isHostileTo(shooter) && shooter->unknown5c8c40(3) >= 4)
							xr_playerData.unknown77fbc0(0x33);
					}
				}

				// cluster weapons spread heat over the cells around the shooter
				if (weapon4->unknown457f90() == 0xc9)
				{
					int gi;
					int amountD;
					xr_unknownD2a864.owner = shooter;
					xr_unknownD2a864.heat = weapon4->unknown579090();
					xr_unknownD2a864.origin = shooter->getPosition();
					xr_unknownD2a864.target = target;
					int remaining = weapon4->unknown579050();
					if (shooter->isPlayer())
					{
						xr_stats.add4729d0(0x20a,remaining,string(""),-1);
						if (xr_stats.unknown472c70(0x20a) >= 1000)
							xr_playerData.unknown77fbc0(0xd4);
					}
					vector<XrPoint> positions;
					weapon4->unknown578f20(&positions,0);
					xr_shuffle(positions);
					for (unsigned int i = 0; i < positions.size() && remaining != 0; i++)
					{
						gi = xr_cells(positions[i])->unknown45a6e0();
						if (gi > remaining)
						{
							amountD = remaining;
							remaining = 0;
						}
						else
						{
							amountD = gi;
							remaining -= gi;
						}
						xr_unknownD2a864.list.push_back(new XrClusterCell(positions[i],amountD,rng.rangeInt(0,500) + xr_tickCount));
					}
					int bC = (int)(weapon4->unknown9b4350()->unknown1a0->unknown30 * xr_unknownD2a864.heat / 34.0 + 1.0);
					shooter->unknown5defa0(bC,false);
					if (shooter->isPlayer())
						xr_stats.add4729d0(0x20b,bC,string(""),-1);
				}
				else if (weapon4->unknown457f90() == 0x9e)
				{
					if (weapon4->getEffectValue(0x46) == 2 && shot == 0)
					{
						int heat = xr_unknownD35bd0.randomInRange_40c130();
						shooter->unknown5defa0(heat,false);
						if (shooter->isPlayer())
							xr_stats.add4729d0(0x20b,heat,string(""),-1);
					}
				}

				if (!shooter->isPlayer() && weapon4->unknown9b4350()->unknown168 != 0)
					xr_world->unknown74b060(origin,weapon4->unknown9b4350()->unknown168,100);

				// resolve the shot instantly when nothing of it can be seen, otherwise launch a projectile
				XrPoint a7;
				XrPoint stop;
				vector<XrPoint> oldPath;
				bool instant;
				if (xr_world->isVisible(origin))
					instant = false;
				else if (xr_world->unknown717e40(origin,aim2,weapon4->unknown4580a0(),a7,stop,weapon4->unknown9b4350(),&oldPath))
					instant = false;
				else if (weapon4->unknown9b4350()->unknown190->unknown5012a0(origin))
					instant = false;
				else
					instant = true;

				if (instant)
				{
					if (a7.x != -1)
						oldPath.push_back(a7);
					for (unsigned int i = 0; i < oldPath.size(); i++)
					{
						a7 = oldPath[i];
						xr_world->setFlagA74(true);
						if (xr_cells(a7)->getEntity().isValid())
						{
							xr_cells(a7)->getEntity()->projectileImpact(shooter,type,aN,weapon4->unknown9b4350(),a8,&origin,true,NULL,NULL);
							if (weapon4.operator->() != NULL && weapon4->unknown9b4350()->unknown1a0 != NULL)
								xr_world->addRecord(xr_gm->createA(new XrObj515ca0(shooter,weapon4->unknown9b4350()->unknown1a0,a7,XrHEntity(),XrPoint(-1),XrPoint(-1))));
						}
						else if (xr_cells(a7)->getProp().isValid())
						{
							xr_cells(a7)->getProp()->unknown664840(shooter,type,aN,weapon4->unknown9b4350(),a8,true,0,NULL);
							if (weapon4.operator->() != NULL && weapon4->unknown9b4350()->unknown1a0 != NULL)
								xr_world->addRecord(xr_gm->createA(new XrObj515ca0(shooter,weapon4->unknown9b4350()->unknown1a0,a7,XrHEntity(),XrPoint(-1),XrPoint(-1))));
						}
						else
						{
							xr_cells(a7)->unknown66e650(shooter,type,aN,weapon4->unknown9b4350(),a8,true);
							if (weapon4.operator->() != NULL && weapon4->unknown9b4350()->unknown1a0 != NULL)
								xr_world->addRecord(xr_gm->createA(new XrObj515ca0(shooter,weapon4->unknown9b4350()->unknown1a0,stop,XrHEntity(),XrPoint(-1),XrPoint(-1))));
						}
						xr_world->setFlagA74(false);
						if (shooter.operator->() == NULL || weapon4.operator->() == NULL)
							break;
					}
					if (weapon4.operator->() != NULL && weapon4->getEffect(0x45) != NULL)
						xr_world->thrownItemArrived(shooter,weapon4,weapon4->getEffectValue(0x45),a7,aN);
					delete aN;
					skipAnimation = true;
					xr_world->unknown465a70();
					for (unsigned int i = 0; i < xr_unknownD2a864.list.size(); i++)
						xr_cells(xr_unknownD2a864.list[i]->pos)->unknown66d470(shooter,xr_unknownD2a864.list[i]->amount,true,true);
					xr_unknownD2a864.unknown460700();
				}
				else
				{
					vector<XrPoint> origins;
					vector<XrPoint> targets;
					xr_OpS3b_f651590(weapon4->unknown9b4350(),origin,aim2,origins,targets);
					for (unsigned int i = 0; i < origins.size(); i++)
					{
						xr_effectMgr->create()->init(xr_effectMgr,weapon4->unknown9b4350()->unknown190,origins[i],xr_effectOrigin,&targets[i],&targetSubcell,new XrOpR2b_Obj500dd0(weapon4->unknown9b4350(),shooter,type,weapon4->unknown4580a0(),a8,type == 0 ? weapon4 : XrHItem(),weapon4->getEffect(0x45) != NULL ? weapon4 : XrHItem(),weapon4->getEffectValue(0x45),aa ? XrHBattleState() : handle,&unknown2c,aN,0),9,0);
						if (!aa)
							pending++;
						if (weapon4->unknown9b4350()->unknown190->unknown44 && i == 0)
							xr_unknownCefb68++;
						if (xr_unknownCefb25)
						{
							XrEffect *effect = xr_effectMgr->unknown4549b0().back();
							xr_unknownD2d4c8.push_back("target=" + xr_OpQ1_pointToString(effect->unknown68) + " | offset=" + xr_OpQ1_pointToString(effect->unknown70));
						}
					}
				}

				// overheating rings (effect 0x79/0x7a)
				if (weapon4.operator->() != NULL && weapon4->getEffectValue(0x79))
				{
					xr_unknownD3976c.clear();
					xr_unknownD29d6c.clear();
					xr_unknownD2ac84.clear();
					XrPoint from = shooter->getPosition();
					int a4 = weapon4->unknown9b4350()->unknown100;
					XrPoint subcell;
					XrPoint previous;
					XrPoint i8;
					XrBresenham2DStepperSubcell stepper(from,xr_effectOrigin,aim2,targetSubcell,9);
					previous = from;
					stepper.next(i8,subcell);
					while (i8 == from)
						stepper.next(i8,subcell);
					while (!stepper.next(i8,subcell))
					{
						if (previous != i8)
						{
							if (!xr_cells.contains(i8))
								break;
							xr_unknownD3976c.push_back(i8);
							if (xr_OpQ1_distanceCeil_40a3f0(from,i8) >= a4)
								break;
							previous = i8;
						}
					}

					vector<XrPoint> j4;
					for (unsigned int i = 0; i < xr_unknownD3976c.size(); i++)
					{
						j4.clear();
						xr_cells.getNeighbors_9ce500(xr_unknownD3976c[i],j4);
						for (unsigned int j = 0; j < j4.size(); j++)
						{
							if (j4[j] != from && !xr_containsPoint(xr_unknownD3976c,j4[j]))
								xr_unknownD29d6c.push_back(j4[j]);
						}
					}
					for (unsigned int i = 0; i < xr_unknownD29d6c.size(); i++)
					{
						j4.clear();
						xr_cells.getNeighbors_9ce500(xr_unknownD29d6c[i],j4);
						for (unsigned int j = 0; j < j4.size(); j++)
						{
							if (j4[j] != from && !xr_containsPoint(xr_unknownD3976c,j4[j]) && !xr_containsPoint(xr_unknownD29d6c,j4[j]))
								xr_unknownD2ac84.push_back(j4[j]);
						}
					}

					if (weapon4->getEffect(0x7a) != NULL)
						weapon4->getEffect(0x7a)->state++;
					else
						weapon4->addEffect(new XrEffPair(xr_effectTypes[0x7a],1));
					int heat_ = weapon4->getEffect(0x7a)->state;
					if (weapon4->getEffectValue(0x79) > 1 && heat_ > (weapon4->getEffectValue(0x79) == 3 ? 20 : 10) && rng.chance(heat_ > 50 ? 33 : 10))
					{
						weapon4->getEffect(0x79)->state--;
						weapon4->getEffect(0x7a)->state = 1;
						if (shooter->isPlayer())
						{
							string text = weapon4->getName(0,0) + " violently vaporizes one of its rings.";
							xr_opW5_message(0x320,XrHEntity(),text,0);
							HISTORY(0x110,&weapon4->unknown457860(),NULL,0,XrHEntity(),0);
							xr_cparts->unknown894e70(weapon4)->unknown4a9120();
							xr_opR1d_4541b0(0xfd,0,0);
						}
						int k5 = weapon4->getEffect(0x79)->state;
						int value = k5 == 2 ? 5 : 10;
						if (weapon4->getEffect(0x5a) != NULL)
							weapon4->getEffect(0x5a)->state = value;
						else
							weapon4->addEffect(new XrEffPair(xr_effectTypes[0x5a],value));
					}
				}
				}
				nextShot:;
			}

			// after the volley
			if (weapon4.operator->() != NULL && weapon4->unknown457f90() == 0xc2)
			{
				int damage = weapon4->unknown457fb0();
				damage = rng.rangeInt(damage * 0.5,damage * 1.5);
				if (damage < shooter->unknown490840())
					shooter->unknown5dea60(shooter->unknown490840() - damage,0);
				else
					shooter->die(!xr_world->unknown4631f0(shooter),10,XrHEntity(),1,0,NULL,NULL,false);
			}

			if (shooter.operator->() != NULL && weapon4.operator->() != NULL && weapon4->getEffectValue(0x44))
			{
				weapon4->getEffect(0x44)->state--;
				if (weapon4->getEffectValue(0x44) == 0)
				{
					MESSAGE(0x191,TEMP_PTR(weapon4->getName(0,0)),NULL,0,shooter,XrHEntity(),NULL,0);
					weapon4->unknown57dbe0(1,0,0,1);
				}
			}

			if (shooter.operator->() != NULL && weapon4.operator->() != NULL && weapon4->getEffectValue(0x47))
			{
				weapon4->getEffect(0x47)->state--;
				if (weapon4->getEffectValue(0x47) == 0)
				{
					weapon4->getEffect(0x47)->state = -1;
					shooter->unknown64e7e0(weapon4);
					if (shooter->isPlayer())
						xr_cparts->unknown894e70(weapon4)->unknown890710(true);
				}
			}

			if (shooter.operator->() != NULL && weapon4.operator->() != NULL && weapon4->getEffectValue(0x76))
			{
				weapon4->unknown4585c0(0x77);
				shooter->unknown64e7e0(weapon4);
				if (shooter->isPlayer())
					xr_cparts->unknown894e70(weapon4)->unknown890710(true);
			}

			if (shooter.operator->() != NULL && weapon4.operator->() != NULL && weapon4->getEffectValue(0x59))
			{
				if (rng.chance(weapon4->getEffectValue(0x59)))
				{
					if (shooter->unknown5cad50() != 2 || !xr_unknownBa0968[xr_unknownCefb38])
						shooter->unknown602170(weapon4,xr_unknown4374c0(target,shooter->getPosition()));
				}
			}

			if (shooter.operator->() != NULL && weapon4.operator->() != NULL && weapon4->unknown458240())
			{
				if (weapon4->unknown9b6bf0() <= weapon4->unknown458240())
				{
					MESSAGE(0x192,TEMP_PTR(weapon4->getName(0,0)),NULL,0,shooter,XrHEntity(),NULL,0);
					weapon4->unknown57dbe0(1,0,1,1);
				}
				else
				{
					weapon4->unknown458310(weapon4->unknown458240());
					XrCPart *part = xr_cparts->unknown894e70(weapon4);
					if (part != NULL)
						part->drawStatus(true);
				}
			}

			if (shooter.operator->() != NULL && weapon4.operator->() != NULL)
				xr_OpS1c_unknown4569a0(6,shooter,XrHEntity(),XrHProp(),weapon4,0,TEMP_PTR(weapon4->getName(0,0)),weapon4->unknown44a7d0(),XrHEntity(),XrHProp(),weapon4,0);

			if (shooter.operator->() != NULL && weapon4.operator->() != NULL)
				xr_OpS1c_unknown4569a0(7,shooter,XrHEntity(),XrHProp(),weapon4,0,TEMP_PTR(weapon4->getName(0,0)),weapon4->unknown44a7d0(),shooter,XrHProp(),weapon4,0);

			if (xr_cells(target)->getEntity().isValid())
			{
				XrHEntity victim = xr_cells(target)->getEntity();
				if (weapon4.operator->() != NULL)
				{
					if (type == 0)
						xr_OpS1c_unknown4569a0(0xb,victim,XrHEntity(),XrHProp(),XrHItem(),0,TEMP_PTR(weapon4->getName(0,0)),victim->getInventory(),victim,XrHProp(),XrHItem(),0);
					else
						xr_OpS1c_unknown4569a0(0xc,victim,XrHEntity(),XrHProp(),XrHItem(),0,TEMP_PTR(weapon4->getName(0,0)),victim->getInventory(),victim,XrHProp(),XrHItem(),0);
				}
				if (victim.operator->() != NULL && weapon4.operator->() != NULL)
					xr_OpS1c_unknown4569a0(0xd,victim,XrHEntity(),XrHProp(),XrHItem(),0,TEMP_PTR(weapon4->getName(0,0)),victim->getInventory(),victim,XrHProp(),XrHItem(),0);
			}

			if (aa)
			{
				if (shooter.operator->() != NULL)
				{
					if (shooter == xr_world->getPlayer())
						xr_unknownCf4b98 = xr_world->getTurn();
					if (type == 1 && targetEntity.operator->() != NULL)
						shooter->unknown451600(targetEntity);
					else
						shooter->unknown451600(XrHEntity());
				}
				return true;
			}
			// nothing to animate: fire the next weapon right away
			else if (skipAnimation && xr_world->unknown463fa0() == 0)
				goto nextWeapon;
			else
			{
				state = 1;
				if (skipAnimation || animated)
					xr_world->setPausedShootState(handle);
			}
		}
		break;
	}
	default:
		return true;
	}

	return false;
}
