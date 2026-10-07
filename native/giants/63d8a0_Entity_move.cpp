// 0x63d8a0 Entity::move (Beta 17.1), semantic reconstruction (not byte-matched).
// int Entity::move(const Point &pos, int distance, bool forced): moves the entity to pos and returns the time the
// move takes (moveCost * distance). Notes and open questions: docs/giants/63d8a0.md.
// NOTE: class layouts below are partial (only the members this function touches, with their 32-bit offsets);
// member and method names are placeholders unless they come from mapping.csv or other src/ files.
#include <string>
#include <vector>
#include <algorithm>
#include "util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

//==================================================================
// Basic types
//==================================================================

struct Point
{
	int x;
	int y;

	Point();								// 0x453b40 (-1,-1)
	Point(int v);							// 0x409990
	Point(int x_, int y_);					// 0x46ca20
	Point(const Point &p);					// 0x46ca50
	Point(const Point &a, const Point &b);	// 0x4099f0 (sum)
	Point &operator=(const Point &p);		// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
	bool isInRect(int x_, int y_, int width, int height);	// NOTE: placeholder name (0x409d70)
};

struct Area	// NOTE: placeholder name
{
	Point min;	// +0x0
	Point max;	// +0x8

	Area();		// 0x40b100
};

struct Range	// NOTE: placeholder name
{
	int min;
	int max;

	int randomInRange_40c130();	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	T &operator()(int x, int y);	// 0x9ceda0
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
	void getBounds(const Point &p, int radius, Area *out);	// NOTE: placeholder name (0x9b4430)
};

class Entity;
class Item;
class Prop;
class Group;
class Marker;

class HEntity	// NOTE: placeholder layout
{
	int ID;
public:
	HEntity();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	bool operator==(HEntity other) const;	// 0x9b78e0
	bool operator!=(HEntity other) const;	// 0x9b6510
	Entity *operator->() const;				// 0x9b6570
};

class HItem	// NOTE: placeholder layout
{
	int ID;
public:
	HItem();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	bool isNull() const;					// 0x9b6c90
	Item *operator->() const;				// 0x9b65b0
};

class HProp	// NOTE: placeholder layout
{
	int ID;
public:
	HProp();								// 0x9b6590
	bool isValid() const;					// 0x9b7230
	bool operator<(const HProp &other) const;	// NOTE: used by sort()
	bool operator==(const HProp &other) const;	// NOTE: used by unique()
	Prop *operator->() const;				// 0x9b64f0
};

class HGroup	// NOTE: placeholder layout
{
	int ID;
public:
	Group *operator->() const;				// 0x9b7250
};

class HMarker	// NOTE: placeholder layout
{
	int ID;
public:
	Marker *operator->() const;				// 0x9b7cd0
};

int unknown4374c0(const Point &from, const Point &to);	// NOTE: placeholder name (direction from -> to)
int opr1c_getCircularDistance(int a, int b);			// 0x433e20 (steps between two of the 8 directions)
int opw8_increase(int *value, int amount, int maximum);	// NOTE: placeholder name (0x9d06d0, add clamped to maximum)
int opw8_decrease(int *value, int amount, int minimum);	// NOTE: placeholder name (0x9d0690, subtract clamped to minimum)
int minInt(int a, int b);								// 0x9cdb30
int maxInt(int a, int b);								// 0x9cdb60
int pointDistance(const Point &a, const Point &b);		// NOTE: placeholder name (0x40a3f0)
string intToString(int value);							// 0x4051f0
int stringToInt(const string &s);						// NOTE: placeholder name (0x405610)
void logError(string location, string message);			// NOTE: placeholder name (0x404f10)
bool lookupID(const string &name, int *id);				// NOTE: placeholder name (0x9d7980)
int findEntityIndex(vector<HEntity> &v, HEntity e);		// NOTE: placeholder name (0x9d3110)
bool containsPoint(vector<Point> &v, Point p);			// NOTE: placeholder name (0x9d0ce0)
bool containsInt(vector<int> &values, int value);		// NOTE: placeholder name (0x9db330)
void eraseAt(vector<int> &v, unsigned int &i);			// NOTE: placeholder name (0x9ce6d0, erases and steps i back)
template <class T> void eraseStep(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9d6440)
template <class T> void deleteAt(vector<T *> &v, int index);		// NOTE: placeholder name (0x9e5420 family, OpS8c_deleteObject)
template <class T> void shuffle(vector<T> &v);					// NOTE: placeholder name (0x9d9fc0)
int opR1d_454260(const Point &pos, unsigned int sound);	// NOTE: placeholder name (plays a sound at pos)
void opR1d_4541b0(int sound, int a, int b);				// NOTE: placeholder name (plays a sound)
bool unknown5111e0(int type, const string *text1, const string *text2, int value, HEntity subject, HEntity object, const Point *pos, int extra);	// NOTE: placeholder name (shows a message)
void unknown5141b0(int type, const string *text1, const string *text2, int value, HEntity e, int c);	// NOTE: placeholder name
bool unknown517ae0(int machineID, vector<Point> *out, int a, int b, int c);	// NOTE: placeholder name
void unknown6c0f10(const Point &p, int terrainID, int value);	// NOTE: placeholder name
void opW5_message(int type, HEntity entity, const string &text, int flag);	// NOTE: placeholder name (0x49c610, adds a log message)

//==================================================================
// Records and game objects
//==================================================================

struct EntityRecord	// NOTE: placeholder name, partial layout
{
	int unknown24;			// +0x24
	int unknown28;			// +0x28 (faction)
	int unknown8C;			// +0x8c
	int size;				// +0x9c NOTE: placeholder name
	int unknownA0;			// +0xa0 (digs through cave walls)
	vector<int> unknown148;	// +0x148
};

struct CellTerrainRecord	// NOTE: partial layout
{
	int ID;	// +0x0
};

struct CellEffect;
struct EntityEffect;

struct TrailMark	// NOTE: placeholder name (12 bytes)
{
	Point position;	// +0x0
	int tick;		// +0x8

	TrailMark(const Point &position_, int tick_);	// 0x45a010
};

struct MachineEffect	// NOTE: placeholder name
{
	bool unknown08;	// +0x8
};

struct Machine	// NOTE: placeholder name (object returned by Prop::unknown45cb30)
{
	bool unknown10;	// +0x10
	bool unknown11;	// +0x11
	int unknown28;	// +0x28
	bool unknown74;	// +0x74

	MachineEffect *unknown45c1c0(int type);	// NOTE: placeholder name
};

struct PropRecordF8	// NOTE: placeholder name (object returned by Prop::unknown9b8f00)
{
	int unknownF8;	// +0xf8
};

class Prop
{
public:
	PropRecordF8 *unknown9b8f00();		// NOTE: placeholder name (ICF'd getter, +0x4)
	const Point &getPosition();			// NOTE: placeholder name (0x4184d0, +0x8)
	int unknown44ab40();				// NOTE: placeholder name (ICF'd getter, +0x34)
	int unknown457b10();				// NOTE: placeholder name (ICF'd getter, +0x3c)
	Machine *unknown45cb30();			// NOTE: placeholder name (ICF'd getter, +0x44)
	const string &getName();			// NOTE: placeholder name (0x45c5b0)
	int unknown45c630();				// NOTE: placeholder name
	void *unknown45c800(int type);		// NOTE: placeholder name
	void unknown45ce10(bool a, bool b, bool c, HEntity d);	// NOTE: placeholder name
};

class Item
{
public:
	int unknown44aec0();				// NOTE: placeholder name (ICF'd getter)
	int unknown9b6bf0();				// NOTE: placeholder name (ICF'd getter, amount)
	void unknown450460(int value);		// NOTE: placeholder name (ICF'd setter, amount)
	int unknown45cb30();				// NOTE: placeholder name (ICF'd getter)
	void unknown44fc60(int value);		// NOTE: placeholder name (ICF'd setter)
	int unknown457880();				// NOTE: placeholder name
	int unknown4578a0();				// NOTE: placeholder name
	int unknown4578c0();				// NOTE: placeholder name
	int getEffectValue(int type);		// NOTE: placeholder name (0x457be0)
	int unknown457ca0();				// NOTE: placeholder name
	int unknown457cd0();				// NOTE: placeholder name
	bool unknown457cf0();				// NOTE: placeholder name (active)
	bool unknown457e30();				// NOTE: placeholder name
	int unknown457f90();				// NOTE: placeholder name
	int unknown457fb0();				// NOTE: placeholder name
	void unknown458360(int amount);		// NOTE: placeholder name
	void unknown4584a0();				// NOTE: placeholder name
	string unknown571db0(bool a, bool b);	// NOTE: placeholder name (name)
	int unknown577790();				// NOTE: placeholder name
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();	// NOTE: placeholder name (ICF'd getter, +0x8)
};

class Marker	// NOTE: placeholder name
{
public:
	Point position;	// +0x8

	void unknown6c20b0(int type, const Point &p, int value);	// NOTE: placeholder name
};

class Cell
{
public:
	CellTerrainRecord *getTerrain();	// 0x9fcd80
	HEntity getEntity();				// 0x45d250
	HProp getProp();					// 0x45d550
	HItem getItem();					// 0x45d8f0
	const string &unknown45d140();		// NOTE: placeholder name
	CellEffect *getEffect(int type);	// 0x45d350
	bool unknown45d4e0();				// NOTE: placeholder name
	bool unknown45d500();				// NOTE: placeholder name
	bool unknown45db70();				// NOTE: placeholder name
	bool unknown45de40();				// NOTE: placeholder name
	void unknown45e110(bool a, bool b, HEntity e);	// NOTE: placeholder name
	int getArmor();						// 0x66ae70
	bool canCaveIn();					// 0x66af50
	void clearEntity();					// NOTE: placeholder name (0x66baf0)
	void unknown66d580(int a);			// NOTE: placeholder name (cave-in)
};

class OpV4c_View	// NOTE: placeholder name (findAlternativePosArrangement() result)
{
public:
	OpV4c_View();			// 0x9cfd10
	~OpV4c_View();			// 0x9b6bd0
	int *get(int x, int y);	// 0x9cfe20
	int unknown9b6bf0();	// NOTE: placeholder name (ICF'd getter, left)
	int unknown44afb0();	// NOTE: placeholder name (ICF'd getter, top)
	int unknown9b6c10();	// NOTE: placeholder name (right)
	int unknown9b6c30();	// NOTE: placeholder name (bottom)
	Point findOffset(int value);	// NOTE: placeholder name (0x9b6cb0)
};

class Entity
{
public:
	HEntity self;					// +0x4
	EntityRecord *data;				// +0x8
	HGroup group;					// +0x28
	vector<Point> footprint;		// +0x30
	int momentum;					// +0x50 NOTE: placeholder name
	int lastDirection;				// +0x54 NOTE: placeholder name
	int propulsion;					// +0x58 NOTE: placeholder name
	float caveinStress;				// +0x5c NOTE: placeholder name
	vector<TrailMark *> trailMarks;	// +0x60 NOTE: placeholder name
	int unknown7C;					// +0x7c
	int unknownB0;					// +0xb0
	int unknownB4;					// +0xb4
	vector<HItem> parts;			// +0x134 NOTE: placeholder name

	int move(const Point &pos, int distance, bool forced);

	EntityRecord *unknown9b4350();				// NOTE: placeholder name (ICF'd getter, returns data)
	const string &getNameAt0c();				// NOTE: placeholder name (0x416f40)
	const string &getName();					// 0x45a280
	int getFaction();							// 0x45a2c0
	int unknown45a340();						// NOTE: placeholder name
	int getSize();								// 0x45a360
	HGroup getGroup();							// 0x45a3f0
	const Point &getPosition();					// 0x45a4a0
	int getTarget();							// 0x45a760
	int unknown45a920();						// NOTE: placeholder name
	bool isHostileTo(HEntity e);				// 0x45aa70
	EntityEffect *unknown45ac40(int type);		// NOTE: placeholder name
	void unknown45b090(int value);				// NOTE: placeholder name (ICF'd setter)
	void unknown45b0b0();						// NOTE: placeholder name
	void unknown45b1b0(int value);				// NOTE: placeholder name
	void unknown45b210(int value);				// NOTE: placeholder name
	int unknown490840();						// NOTE: placeholder name (ICF'd getter, +0x8c)
	bool isPlayer();							// 0x5c7600
	int unknown5c7d30();						// NOTE: placeholder name
	int unknown5c7fc0(HEntity other);			// NOTE: placeholder name
	bool unknown5c85a0(const Point &p, bool large);	// NOTE: placeholder name
	void unknown5c8880(vector<HEntity> *out);	// NOTE: placeholder name
	int unknown5ca670();						// NOTE: placeholder name
	bool unknown5cb680(HGroup g);				// NOTE: placeholder name
	HItem unknown5cbd10();						// NOTE: placeholder name
	int unknown5ccab0();						// NOTE: placeholder name
	int unknown5d1390();						// NOTE: placeholder name (propulsion type)
	int unknown5d15a0(bool notify);				// NOTE: placeholder name (move cost)
	int unknown5d1da0();						// NOTE: placeholder name
	float unknown5d1e40();						// NOTE: placeholder name
	int unknown5d2150(int type, int base);		// NOTE: placeholder name
	HItem unknown5d2380(int type);				// NOTE: placeholder name
	unsigned int unknown5d2430(int type, vector<HItem> *out);	// NOTE: placeholder name
	HItem unknown5d25e0(int type);				// NOTE: placeholder name
	void unknown5daf90(int type);				// NOTE: placeholder name
	void changePos(const Point &p, bool flag);	// NOTE: placeholder signature (0x5dccb0)
	void unknown5dd8a0(HEntity other);			// NOTE: placeholder name
	void unknown5dd9c0(HEntity e, const Point &p);	// NOTE: placeholder name
	bool unknown5ddf50(const Point &p, OpV4c_View *arrangement, bool *tooLarge);	// NOTE: placeholder name (findAlternativePosArrangement)
	int unknown5deb40(int amount);				// NOTE: placeholder name
	int unknown5ded70(int amount);				// NOTE: placeholder name
	void unknown5dfd80();						// NOTE: placeholder name
	bool unknown5fdae0();						// NOTE: placeholder name
	bool unknown5fdd30();						// NOTE: placeholder name
	bool unknown603030(HItem item);				// NOTE: placeholder name
	bool unknown603280(HItem item);				// NOTE: placeholder name
	void die(bool a, int cause, HEntity killer, int b, int c, int d, int e, int f);	// NOTE: placeholder signature (0x633790)
	void unknown637bb0();						// NOTE: placeholder name
	void unknown639ec0(HEntity other, int a);	// NOTE: placeholder name
	void unknown63a0d0();						// NOTE: placeholder name
	int unknown63c120();						// NOTE: placeholder name
	bool unknown63c340(HEntity other);			// NOTE: placeholder name
};

class Map	// NOTE: placeholder name (world object at 0xcefc4c)
{
public:
	HEntity getPlayer();										// NOTE: placeholder name (0x4630f0)
	bool unknown463160(const Point &p);							// NOTE: placeholder name
	bool isVisible(const Point &p);								// NOTE: placeholder name (0x4631c0)
	bool unknown463400(HEntity e);								// NOTE: placeholder name
	bool unknown463490(HEntity e, const Point &p);				// NOTE: placeholder name
	vector<HEntity> *unknown4636b0();							// NOTE: placeholder name
	bool unknown463b50(Point p);								// NOTE: placeholder name
	void unknown463b80(Point p);								// NOTE: placeholder name
	vector<int> &unknown463bc0();								// NOTE: placeholder name
	vector<vector<HMarker> > *unknown463ec0();					// NOTE: placeholder name
	int unknown4642f0();										// NOTE: placeholder name
	bool unknown464350();										// NOTE: placeholder name
	void unknown4647a0(const Point &p, bool flag);				// NOTE: placeholder name
	void unknown464800(HEntity e);								// NOTE: placeholder name
	void unknown464840(HItem item);								// NOTE: placeholder name
	void unknown4657c0();										// NOTE: placeholder name (move counter +1)
	bool isReachable(int range, const Point &from, const Point &to);	// NOTE: placeholder name (0x465230)
	vector<vector<Point> > *unknown459070();					// NOTE: placeholder name
	void unknown6c6b90(const Point &p, const string &type, int a, int b);	// NOTE: placeholder name
	bool unknown715d20();										// NOTE: placeholder name
	bool unknown715ed0();										// NOTE: placeholder name
	void addPropsAround(HEntity entity, vector<HProp> *out);	// NOTE: placeholder name (0x71c6d0)
	void addTrailPoint(const Point &p);							// NOTE: placeholder name (0x71ce30)
	HItem unknown71e7c0(const Point &p, int amount, bool protomatter);	// NOTE: placeholder name
	void unknown71f700(const Point &p, int a);					// NOTE: placeholder name
	void unknown725930(HEntity e, bool reset);					// NOTE: placeholder name
	void unknown729520(const Point &p);							// NOTE: placeholder name
	void unknown72e4c0(HEntity e, bool flag);					// NOTE: placeholder name
	void unknown74b060(const Point &p, int type, int percent);	// NOTE: placeholder name
	void unknown74bb90(HProp prop, HProp &door, Point &pos, bool &flag);	// NOTE: placeholder name
};

class MapView	// NOTE: placeholder name (0xcec054)
{
public:
	void unknown49ad30();						// NOTE: placeholder name
	void unknown49ad70(int time);				// NOTE: placeholder name
	void unknown49adc0(int time);				// NOTE: placeholder name
	void unknown49afd0(const Point &p, bool a);	// NOTE: placeholder name
	void unknown49b670();						// NOTE: placeholder name
	void unknown81a340(HEntity e);				// NOTE: placeholder name
};

class MessageConsole	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};

class CLogMsgs
{
public:
	void scrollToEnd();	// 0x7b4f10
};

class CPart
{
public:
	void drawStatus(bool damaged);	// NOTE: placeholder name (0x4a8e70)
};

class CParts
{
public:
	CPart *unknown894e70(HItem item);	// NOTE: placeholder name
};

class CMission
{
public:
	void unknown987de0();	// NOTE: placeholder name
};

class EffectPool;
class Effect	// NOTE: placeholder name
{
public:
	void unknown503b20(EffectPool *pool, int id, const Point &pos, const Point &offset, int a, int b, int c, int d, int e);	// NOTE: placeholder name
};

class EffectPool	// NOTE: placeholder name (0xcefc50)
{
public:
	Effect *unknown508610();	// NOTE: placeholder name
};

class ObjectFactory	// NOTE: placeholder name (0xcefaa8)
{
public:
	HMarker createMarker();	// NOTE: placeholder name (0x793190)
};

class StatSet	// NOTE: placeholder name
{
public:
	vector<int> values;	// +0x0
};

class OpR1h_Stats	// NOTE: placeholder name (0xd2c658)
{
public:
	StatSet *current;	// +0x0

	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
	int unknown472c70(int id);	// NOTE: placeholder name (0x472c70, current value)
};

class PlayerData	// NOTE: partial (0xcf45d8)
{
public:
	bool isSlotEmpty(unsigned int index);	// NOTE: placeholder name (0x46de40, achievement not yet earned)
	void unknown77fbc0(int achievement);	// NOTE: placeholder name (earns an achievement)
	void addPolymindSuspicion(float amount, int type, HEntity entity);	// 0x77ee70
};

class GameData	// NOTE: placeholder name (0xd1e860)
{
public:
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
	bool unknown46f4b0(int index);	// NOTE: placeholder name
};

struct Location	// NOTE: placeholder name
{
	int type;	// +0x4
};

class HLocation	// NOTE: placeholder name (0xd1e888)
{
	int ID;
public:
	Location *operator->() const;	// 0x9b7910
};

struct MapTypeData	// NOTE: placeholder name (0x34-byte rows at 0xba4500, indexed by location type)
{
	int	turnInterval;	// +0x0 NOTE: placeholder name
	int	amount;			// +0x4 NOTE: placeholder name
	int	maximum;		// +0x8 NOTE: placeholder name
	int	unknown0C;		// +0xc
	int	unknown10;		// +0x10
	int	unknown14;		// +0x14
	int	unknown18;		// +0x18
	int	unknown1C;		// +0x1c
	int	unknown20;		// +0x20
	int	unknown24;		// +0x24
	int	unknown28;		// +0x28
	int	unknown2C;		// +0x2c
	int	unknown30;		// +0x30
};

struct Possession	// NOTE: placeholder name
{
	int recordIndex;	// +0x0 NOTE: placeholder name
};

class Tally	// NOTE: placeholder name (0xcf6888)
{
public:
	vector<int> counts;	// +0x10 NOTE: placeholder name

	void unknown6998a0(unsigned int index, int amount, bool set);	// NOTE: placeholder name
};

class CBD	// NOTE: placeholder name (0xcefc14)
{
public:
	bool take48bf50(HEntity entity);	// NOTE: placeholder name
	void unknown7ac1c0(HEntity entity, int a, int b, string name);	// NOTE: placeholder name
};

class MessageLog	// NOTE: placeholder name (0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name (ICF'd setter)
};

//==================================================================
// Globals
//==================================================================

extern int timeUnitsPerTurn;					// NOTE: placeholder name (0xb95fd8, holds 100)
extern unsigned int tickCount;					// NOTE: placeholder name (0xcaed20)
extern Map *world;								// NOTE: placeholder name (0xcefc4c)
extern Array2D<Cell *> cells;					// NOTE: placeholder name (0xcfd44c)
extern Array2D<int> originalTerrain;			// NOTE: placeholder type (0xd378c0)
extern CellTerrainRecord *TERRAIN_CAVE_WALL;	// 0xcefba0
extern CellTerrainRecord *caveinThirdTerrain;	// 0xcefba4
extern int trailMarksEnabled;					// NOTE: placeholder name (0xd28d40)
extern MapView *mapView;						// NOTE: placeholder name (0xcec054)
extern MessageConsole *msgConsole;				// NOTE: placeholder name (0xcec058)
extern CLogMsgs *logMsgs;						// NOTE: placeholder name (0xcec0b4)
extern CParts *partsConsole;					// NOTE: placeholder name (0xcec088)
extern CMission *cmission;						// NOTE: placeholder name (0xcec034)
extern EffectPool *effectPool;					// NOTE: placeholder name (0xcefc50)
extern Point effectOrigin;						// NOTE: placeholder name (0xd2e20c)
extern ObjectFactory *objectFactory;			// NOTE: placeholder name (0xcefaa8)
extern OpR1h_Stats stats;						// NOTE: placeholder name (0xd2c658)
extern PlayerData playerData;					// NOTE: placeholder name (0xcf45d8)
extern GameData gameData;						// NOTE: placeholder name (0xd1e860)
extern HLocation location;						// NOTE: placeholder name (0xd1e888)
extern Possession *possession;					// NOTE: placeholder name (0xcf4700)
extern vector<EntityRecord *> entityRecords;	// NOTE: placeholder name (0xd25de0)
extern vector<HEntity> entityList;				// NOTE: placeholder name (0xd35850)
extern vector<vector<HProp> > machines;			// NOTE: placeholder name (0xd31640)
extern Tally tally;								// NOTE: placeholder name (0xcf6888)
extern int unknownD255e4;						// NOTE: placeholder name
extern int turnCounter;							// NOTE: placeholder name (0xcf47fc)
extern MapTypeData mapTypeData[];				// NOTE: placeholder name (0xba4500)
extern bool mapTypeHasDataMiner[];				// NOTE: placeholder name (0xb91198)
extern bool factionCausesCaveins[];				// NOTE: placeholder name (0xb95150)
extern int propulsionClass[];					// NOTE: placeholder name (0xb96080)
extern int propulsionNoise[];					// NOTE: placeholder name (0xb96064, indexed by class)
extern Range dataCoreDrainRange;				// NOTE: placeholder name (0xd306a4)
extern Point directions[];						// NOTE: placeholder name (0xd015d8)
extern CBD *cbd;								// NOTE: placeholder name (0xcefc14)
extern Point cbdExit1;							// NOTE: placeholder name (0xcfcc6c)
extern Point cbdExit2;							// NOTE: placeholder name (0xd3578c)
extern bool luigiAiActive;						// NOTE: placeholder name (0xcefc5d)
extern bool luigiDiggingReported;				// NOTE: placeholder name (0xcefc9c)
extern MessageLog messageLog;					// NOTE: placeholder name (0xcf1080)

// message helper as it appears inline throughout the exe
#define SHOW_MESSAGE(type, text1, text2, value, subject, object, pos, extra)	\
	do { if (unknown5111e0(type,text1,text2,value,subject,object,pos,extra)) msgConsole->unknown8758d0(true); logMsgs->scrollToEnd(); } while (0)

//==================================================================
// Entity::move
//==================================================================

int Entity::move(const Point &pos, int distance, bool forced)
{
	bool player = isPlayer();

	// momentum
	int direction = unknown4374c0(footprint[0],pos);
	int turn = opr1c_getCircularDistance(lastDirection,direction);
	switch (turn)
	{
		case 0: opw8_increase(&momentum,1,3); break;
		case 1: opw8_decrease(&momentum,1,1); break;
		default: momentum = 1; break;
	}
	lastDirection = direction;

	// propulsion type (7 when an active part in slot 10 has effect 0x7f)
	propulsion = unknown5d1390();
	if (propulsion == 1)
	{
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown457880() == 10 && parts[i]->unknown457cf0() && parts[i]->getEffectValue(0x7f) != 0)
			{
				propulsion = 7;
				break;
			}
		}
	}

	int moveCost = unknown5d15a0(player);
	int moveTime = moveCost * distance;

	if (!forced)
	{
		if (unknown5fdae0())
			return timeUnitsPerTurn;
		if (!world->unknown464350())
		{
			unknown45b1b0((int)(unknown5d1e40() * distance));
			unknown45b210(unknown5d1da0() * distance);
		}
	}

	// cave-in stress
	if (cells(pos)->canCaveIn())
	{
		if (caveinStress < 2.0 && (originalTerrain(pos) == TERRAIN_CAVE_WALL->ID || originalTerrain(pos) == caveinThirdTerrain->ID))
			caveinStress += 0.4;
		else
			caveinStress += 1.0;
	}
	else
		caveinStress = 0;

	// trail marks on the cells being left
	if (trailMarksEnabled && !player)
	{
		for (unsigned int i = 0; i < footprint.size(); i++)
		{
			for (unsigned int j = 0; j < trailMarks.size(); j++)
			{
				if (footprint[i] == trailMarks[j]->position)
				{
					trailMarks[j]->tick = tickCount;
					goto nextCell;
				}
			}
			trailMarks.push_back(new TrailMark(footprint[i],tickCount));
		nextCell:;
		}
	}

	// entering or leaving the player group's area
	int groupChange = 0;
	if (self != world->getPlayer() && world->getPlayer()->unknown5cb680(group))
	{
		if (world->unknown463490(self,pos))
		{
			if (!world->unknown463400(self))
				groupChange = 1;
		}
		else if (world->unknown463400(self) && !world->unknown463490(self,pos))
			groupChange = -1;
	}

	// player stats and achievements
	if (player && !forced)
	{
		stats.add4729d0(0x3f6,moveCost,string(""),-1);
		stats.add4729d0(0x3f8,moveCost,string(""),-1);
		for (int i = 0; i < distance; i++)
			stats.add4729d0(0x3f7,moveCost,string(""),-1);
		mapView->unknown49b670();

		if (playerData.isSlotEmpty(0x77) || playerData.isSlotEmpty(0xac) || playerData.isSlotEmpty(0xad))
		{
			if (moveCost <= 25)
				playerData.unknown77fbc0(0x77);
			if (moveCost <= 10)
				playerData.unknown77fbc0(0xac);
			if (moveCost <= 5)
				playerData.unknown77fbc0(0xad);
		}
		if (propulsionClass[propulsion] == 1)
		{
			if (moveCost < 100)
				playerData.unknown77fbc0(0xea);
			if (playerData.isSlotEmpty(0xee) && unknown7C >= 8)
			{
				int total = 0;
				for (unsigned int i = 0; i < parts.size(); i++)
				{
					if (parts[i]->unknown457880() == 10 && parts[i]->unknown457cf0())
						total += parts[i]->unknown4578c0();
				}
				if (total >= 8)
					playerData.unknown77fbc0(0xee);
			}
		}
		if (moveCost <= 50 && propulsionClass[propulsion] == 6 && playerData.isSlotEmpty(0x79))
		{
			for (unsigned int i = 0; i < parts.size(); i++)
			{
				if (parts[i]->unknown457880() == 9 && !parts[i]->unknown457cf0() && parts[i]->unknown44aec0() == 1)
				{
					playerData.unknown77fbc0(0x79);
					break;
				}
			}
		}
	}

	// diggers tunnel through cave walls
	if (data->unknownA0)
	{
		for (int x = pos.x; x < pos.x + data->size; x++)
		{
			for (int y = pos.y; y < pos.y + data->size; y++)
			{
				if (cells(x,y)->getTerrain() == TERRAIN_CAVE_WALL)
				{
					CellTerrainRecord *terrain = cells(x,y)->getTerrain();
					cells(x,y)->unknown45e110(false,false,self);
					unknown6c0f10(Point(x,y),terrain->ID,100);
				}
			}
		}
	}

	// change position
	if (getSize() >= 2 && unknown5c85a0(pos,false))
	{
		// large robot: shift the robots in the way to the alternative arrangement
		OpV4c_View arrangement;
		if (!unknown5ddf50(pos,&arrangement,NULL))
		{
			logError("Entity::move()","findAlternativePosArrangement() mismatch");
			return timeUnitsPerTurn;
		}
		vector<HEntity> displaced;
		vector<int> displacedIndices;
		for (int x = arrangement.unknown9b6bf0(); x <= arrangement.unknown9b6c10(); x++)
		{
			for (int y = arrangement.unknown44afb0(); y <= arrangement.unknown9b6c30(); y++)
			{
				if (cells(x,y)->getEntity().isValid())
				{
					if (cells(x,y)->getEntity() == self)
						cells(x,y)->clearEntity();
					else
					{
						int index = findEntityIndex(entityList,cells(x,y)->getEntity());
						if (index == -1)
						{
							logError("Entity::move()","posMap entityIndex not found! destroying " + cells(x,y)->getEntity()->getName());
							cells(x,y)->getEntity()->unknown637bb0();
						}
						else if (index != *arrangement.get(x,y))
						{
							displaced.push_back(cells(x,y)->getEntity());
							displacedIndices.push_back(index);
							cells(x,y)->clearEntity();
						}
					}
				}
			}
		}
		Point newPos;
		for (unsigned int i = 0; i < displaced.size(); i++)
		{
			newPos = arrangement.findOffset(displacedIndices[i]);
			if (newPos.x == -1)
			{
				logError("Entity::move()","new loc for adjustment not found, destroying " + displaced[i]->getName());
				displaced[i]->unknown637bb0();
			}
			else
			{
				Point oldPos = displaced[i]->getPosition();
				displaced[i]->changePos(newPos,false);
				displaced[i]->unknown45b090(0);
				displaced[i]->unknown45b0b0();
				unknown5dd9c0(displaced[i],newPos);
				// small robots caught under the new footprint may be crushed
				if (oldPos.isInRect(pos.x,pos.y,pos.x + data->size,pos.y + data->size)
				 && displaced[i]->unknown5c7fc0(self) != 2
				 && !displaced[i]->isPlayer()
				 && displaced[i]->unknown45a340() < 3
				 && displaced[i]->unknown490840() < 51
				 && displaced[i]->unknown45ac40(0x17) == NULL
				 && rng.chance(20))
				{
					SHOW_MESSAGE(0x9d + isHostileTo(world->getPlayer()),NULL,NULL,0,displaced[i],self,NULL,0);
					unknown639ec0(displaced[i],0);
					displaced[i]->unknownB4 -= 20;
					opR1d_454260(displaced[i]->getPosition(),0xaf);
					opR1d_454260(displaced[i]->getPosition(),0xb0);
					int effectID;
					lookupID(string("Robot_Crushed"),&effectID);
					effectPool->unknown508610()->unknown503b20(effectPool,effectID,displaced[i]->getPosition(),effectOrigin,0,0,0,9,0);
					displaced[i]->die(false,4,self,7,0,0,0,0);
				}
			}
		}
		changePos(pos,false);
	}
	else
	{
		if (cells(pos)->getEntity().isValid() && cells(pos)->getEntity() != self)
		{
			HEntity occupant = cells(pos)->getEntity();
			unknown5dd8a0(occupant);
			if (occupant->group->unknown9b4350() == 0)
				world->unknown72e4c0(occupant,true);
		}
		else
			changePos(pos,true);
	}

	// movement noise
	if (!player)
	{
		for (unsigned int i = 0; i < footprint.size(); i++)
			world->unknown74b060(footprint[i],propulsionNoise[propulsionClass[propulsion]],100);
	}

	if (groupChange != 0)
	{
		if (groupChange == 1)
			world->unknown725930(self,true);
		else
			world->unknown464800(self);
	}

	// trail marks under the new footprint expire
	for (unsigned int i = 0; i < trailMarks.size(); i++)
	{
		if (containsPoint(footprint,trailMarks[i]->position))
		{
			deleteAt(trailMarks,i);
			i--;
		}
	}

	if (player && !forced)
	{
		world->addTrailPoint(getPosition());
		world->unknown729520(getPosition());
		if (possession != NULL)
		{
			if (gameData.unknown46f4b0(1))
			{
				if (entityRecords[possession->recordIndex]->unknown24 == 3)
					playerData.addPolymindSuspicion(0.15f,0x11,HEntity());
				else
					playerData.addPolymindSuspicion(0.4f,0x10,HEntity());
			}
			unknown5daf90(0x18);
		}
	}

	// matter intake: an active 0xd5 part absorbs matter lying on the destination
	if (propulsion == 2)
	{
		if (cells(pos)->getItem().isValid() && cells(pos)->getItem()->unknown457880() == 0)
		{
			HItem intake;
			for (unsigned int i = 0; i < parts.size(); i++)
			{
				if (parts[i]->unknown457cf0() && parts[i]->unknown457f90() == 0xd5 && parts[i]->unknown457cd0() != 0)
				{
					if (intake.isNull() || parts[i]->unknown457ca0() < intake->unknown457ca0())
						intake = parts[i];
				}
			}
			if (intake.isValid())
			{
				HItem matter = cells(pos)->getItem();
				int amount = matter->unknown9b6bf0();
				if (unknown45a920() < unknown5ca670())
					amount /= 2;
				int absorbed = minInt(amount / intake->unknown457fb0(),intake->unknown457cd0());
				intake->unknown458360(absorbed);
				if (player)
				{
					CPart *part = partsConsole->unknown894e70(intake);
					part->drawStatus(false);
					SHOW_MESSAGE(0x185,&intake->unknown571db0(false,false),&intToString(absorbed),0,self,HEntity(),NULL,0);
				}
				int used = intake->unknown457fb0() * absorbed;
				if (used >= matter->unknown9b6bf0())
					matter->unknown57dbe0(0,1,1,1);
				else
					matter->unknown450460(matter->unknown9b6bf0() - used);
			}
		}
	}

	unknown5dfd80();
	if (player && unknownD255e4)
		world->unknown71f700(getPosition(),3);

	if (player)
	{
		stats.add4729d0(0x3ef,distance,string(""),-1);
		if (stats.unknown472c70(0x3ef) % 8 == 0)
		{
			int total = unknown5ccab0();
			int inactive = 0;
			for (unsigned int i = 0; i < parts.size(); i++)
			{
				if (parts[i]->unknown44aec0() != 4)
				{
					total += parts[i]->unknown577790();
					if (parts[i]->unknown4578a0() == 1 && !parts[i]->unknown457cf0())
						inactive += parts[i]->unknown577790();
				}
			}
			stats.add4729d0(0xbf,total ? inactive * 100 / total : 0,string(""),-1);
		}
		if (!forced)
		{
			if (distance > 1)
				stats.add4729d0(0x3fb,distance - 1,string(""),-1);
			int propulsionType = unknown5d1390();
			if (propulsionType == 6)
				stats.add4729d0(0x3f0,distance,string(""),-1);
			else
				stats.add4729d0(0x3f1 + propulsionType,distance,string(""),-1);
			if (playerData.isSlotEmpty(3)
			 && stats.current->values[0x3f1] != 0
			 && stats.current->values[0x3f3] != 0
			 && stats.current->values[0x3f2] != 0
			 && stats.current->values[0x3f4] != 0
			 && stats.current->values[0x3f5] != 0)
				playerData.unknown77fbc0(3);
			if (distance >= 4)
				playerData.unknown77fbc0(0x78);
		}
		world->unknown4657c0();
		turnCounter++;
		if (mapTypeData[location->type].turnInterval != 0 && world->unknown4642f0() != 0)
		{
			if (world->unknown4642f0() % mapTypeData[location->type].turnInterval == 0)
			{
				if (tally.counts[1] < mapTypeData[location->type].maximum)
				{
					int amount = minInt(mapTypeData[location->type].amount,mapTypeData[location->type].maximum - tally.counts[1]);
					tally.unknown6998a0(1,amount,false);
				}
			}
		}
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown44aec0() < 4)
				parts[i]->unknown4584a0();
		}
	}

	unknown5dd9c0(self,pos);

	// robots crushed by this move
	if (!forced)
	{
		int crushed = unknown63c120();
		if (crushed != 0 && isPlayer())
		{
			stats.add4729d0(0x3f9,1,string(""),-1);
			if (crushed >= 4)
				playerData.unknown77fbc0(0xab);
		}
	}

	if (getFaction() == 0 || getFaction() == 0x30)
	{
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->unknown457cf0() && parts[i]->unknown4578a0() == 1)
			{
				if (unknown603030(parts[i]) || unknown603280(parts[i]))
				{
					if (isPlayer())
					{
						mapView->unknown49ad30();
						mapView->unknown49adc0(1000);
					}
					break;
				}
			}
		}
	}

	// data cores (type 0x1f) drain near hostiles
	if (unknown5d2380(0x1f).isValid())
	{
		int drain = 0;
		if (player)
		{
			vector<HEntity> *hostiles = world->unknown4636b0();
			for (unsigned int i = 0; i < hostiles->size(); i++)
			{
				if ((*hostiles)[i].operator->() == NULL)
					eraseStep(*hostiles,i);
				else if (drain < (*hostiles)[i]->unknown9b4350()->unknown8C
				 && (*hostiles)[i]->getGroup()->unknown9b4350() == 3
				 && pointDistance(getPosition(),(*hostiles)[i]->getPosition()) <= (*hostiles)[i]->unknown5c7d30() - unknown5d2150(0x1e,0))
					drain = (*hostiles)[i]->unknown9b4350()->unknown8C;
			}
		}
		else
		{
			Area area;
			cells.getBounds(getPosition(),12,&area);
			for (int x = area.min.x; x <= area.max.x; x++)
			{
				for (int y = area.min.y; y <= area.max.y; y++)
				{
					if (cells(x,y)->getEntity().isValid()
					 && cells(x,y)->getEntity()->getGroup()->unknown9b4350() == 3
					 && cells(x,y)->getEntity()->getTarget() == 0
					 && drain < cells(x,y)->getEntity()->unknown9b4350()->unknown8C
					 && pointDistance(getPosition(),Point(x,y)) <= cells(x,y)->getEntity()->unknown5c7d30() - unknown5d2150(0x1e,0)
					 && world->isReachable(cells(x,y)->getEntity()->unknown5c7d30(),Point(x,y),getPosition()))
						drain = cells(x,y)->getEntity()->unknown9b4350()->unknown8C;
				}
			}
		}
		drain += dataCoreDrainRange.randomInRange_40c130();
		drain -= maxInt(0,minInt(unknownB0 / 10,3));
		vector<HItem> cores;
		unknown5d2430(0x1f,&cores);
		for (unsigned int i = 0; i < cores.size(); i++)
		{
			if (drain < cores[i]->unknown45cb30())
				cores[i]->unknown44fc60(cores[i]->unknown45cb30() - drain);
			else
			{
				if (player)
				{
					SHOW_MESSAGE(0xc3,&cores[i]->unknown571db0(false,false),NULL,0,self,HEntity(),NULL,0);
					unknown5141b0(0x60,&cores[i]->unknown571db0(false,false),NULL,0,self,0);
					mapView->unknown49adc0(2000);
				}
				cores[i]->unknown57dbe0(1,0,9,1);
			}
		}
	}

	// Data Miner: machine doors open as the player approaches
	if (player
	 && mapTypeHasDataMiner[location->type]
	 && stringToInt(gameData.getEntryText(string("datMetDataMiner_g"))) != 0
	 && stringToInt(gameData.getEntryText(string("datHostileToDataMiner_g"))) == 0
	 && stringToInt(gameData.getEntryText(string("enemiesWithArchitect_g"))) == 0)
	{
		vector<HProp> props;
		world->addPropsAround(self,&props);
		if (!props.empty())
		{
			sort(props.begin(),props.end());
			props.erase(unique(props.begin(),props.end()),props.end());
			for (unsigned int i = 0; i < props.size(); i++)
			{
				if (props[i].operator->() != NULL
				 && props[i]->unknown45cb30() != NULL
				 && props[i]->unknown9b8f00()->unknownF8 == 0
				 && props[i]->unknown457b10() == 0
				 && !props[i]->unknown45cb30()->unknown74)
				{
					props[i]->unknown45cb30()->unknown74 = true;
					MachineEffect *doorEffect = props[i]->unknown45cb30()->unknown45c1c0(5);
					if (doorEffect != NULL && !doorEffect->unknown08)
					{
						int chance = 50;
						if (props[i]->unknown45c800(0x8c) != NULL)
							chance = 100;
						else if (props[i]->unknown45c800(0x8d) != NULL)
							chance = 0;
						if (rng.chance(chance))
						{
							vector<Point> doorCells;
							if (unknown517ae0(props[i]->unknown44ab40(),&doorCells,0,2,0))
							{
								doorEffect->unknown08 = true;
								string text = props[i]->getName() + " flashes as you approach.";
								opW5_message(0x320,HEntity(),text,0);
								opR1d_454260(doorCells.front(),0x7e);
								int effectID;
								if (lookupID(string("P_Machine_Door_Open"),&effectID))
								{
									for (unsigned int j = 0; j < doorCells.size(); j++)
									{
										if (world->isVisible(doorCells[j]))
											effectPool->unknown508610()->unknown503b20(effectPool,effectID,doorCells[j],effectOrigin,0,0,0,9,0);
										cells(doorCells[j])->getProp()->unknown45ce10(true,false,true,HEntity());
									}
								}
							}
						}
					}
				}
			}
		}
	}

	// cave seals
	if (player)
	{
		if (world->unknown715d20())
		{
			vector<Point> &triggers = (*world->unknown459070())[0];
			for (unsigned int i = 0; i < triggers.size(); i++)
			{
				if (!cells(triggers[i])->getProp()->unknown45cb30()->unknown11
				 && !cells(triggers[i])->getProp()->unknown45cb30()->unknown10
				 && cells(triggers[i])->getProp()->unknown45cb30()->unknown28 >= 0
				 && pointDistance(getPosition(),triggers[i]) < 11)
				{
					cells(triggers[i])->getProp()->unknown45cb30()->unknown11 = true;
					SHOW_MESSAGE(0x2af,NULL,NULL,0,self,HEntity(),NULL,0);
					if (!world->unknown463160(triggers[i]) && !world->isVisible(triggers[i]))
					{
						vector<HMarker> &markers = (*world->unknown463ec0())[0];
						for (unsigned int j = 0; j < markers.size(); j++)
						{
							if (markers[j]->position == triggers[i])
								goto sealMarked;
						}
						markers.push_back(objectFactory->createMarker());
						markers.back()->unknown6c20b0(0,triggers[i],0);
						cmission->unknown987de0();
					}
				sealMarked:
					mapView->unknown49afd0(triggers[i],true);
					opR1d_4541b0(299,0,0);
					mapView->unknown49ad70(tickCount + 500);
					if (location->type == 0x22)
					{
						if (cells(triggers[i])->getProp()->unknown45cb30()->unknown45c1c0(0x31) != NULL)
						{
							HProp door;
							Point doorPos(-1);
							bool doorFlag = false;
							world->unknown74bb90(cells(triggers[i])->getProp(),door,doorPos,doorFlag);
							if (door.isValid() && !doorFlag && doorPos.x != -1)
								world->unknown6c6b90(doorPos,string("COM_Cave_Seal_Timer"),0,-1);
						}
					}
				}
			}
		}
		if (world->unknown715ed0())
		{
			vector<Point> &triggers = (*world->unknown459070())[5];
			for (unsigned int i = 0; i < triggers.size(); i++)
			{
				if (!world->unknown463b50(triggers[i]) && pointDistance(getPosition(),triggers[i]) < 16)
				{
					world->unknown463b80(triggers[i]);
					SHOW_MESSAGE(0x29f,NULL,NULL,0,self,HEntity(),NULL,0);
					if (!world->unknown463160(triggers[i]) && !world->isVisible(triggers[i]))
					{
						vector<HMarker> &markers = (*world->unknown463ec0())[0];
						for (unsigned int j = 0; j < markers.size(); j++)
						{
							if (markers[j]->position == triggers[i])
								goto triggerMarked;
						}
						markers.push_back(objectFactory->createMarker());
						markers.back()->unknown6c20b0(0,triggers[i],5);
						cmission->unknown987de0();
					}
				triggerMarked:
					mapView->unknown49afd0(triggers[i],false);
					opR1d_4541b0(299,0,0);
					mapView->unknown49ad70(tickCount + 500);
				}
			}
			if (location->type == 0xd)
			{
				vector<int> &machineIDs = world->unknown463bc0();
				for (unsigned int i = 0; i < machineIDs.size(); i++)
				{
					for (unsigned int j = 0; j < machines[machineIDs[i]].size(); j++)
					{
						if (pointDistance(getPosition(),machines[machineIDs[i]][j]->getPosition()) < 16)
						{
							if (machines[machineIDs[i]][j]->unknown457b10() == 0)
							{
								SHOW_MESSAGE(0x2a0,NULL,NULL,0,self,HEntity(),NULL,0);
								Point center(machines[machineIDs[i]][j]->getPosition());
								for (unsigned int k = 0; k < machines[machineIDs[i]].size(); k++)
								{
									Point p(machines[machineIDs[i]][k]->getPosition());
									world->unknown4647a0(p,true);
								}
								mapView->unknown49afd0(center,false);
								opR1d_4541b0(299,0,0);
								mapView->unknown49ad70(tickCount + 500);
							}
							eraseAt(machineIDs,i);
							break;
						}
					}
				}
			}
		}
	}

	// possessed robots dig as they move
	if (player && possession != NULL)
	{
		if (containsInt(entityRecords[possession->recordIndex]->unknown148,0) && cells(getPosition())->unknown45de40())
		{
			HItem item = unknown5cbd10();
			if (item.isValid())
				item->unknown44fc60(minInt(item->unknown45cb30() + rng.rangeInt(1,5),item->unknown457fb0()));
			SHOW_MESSAGE(0x309,NULL,NULL,0,self,HEntity(),NULL,0);
			if (gameData.unknown46f4b0(1))
				playerData.addPolymindSuspicion(-3.0f,0,HEntity());
		}
		else if (containsInt(entityRecords[possession->recordIndex]->unknown148,2))
		{
			if (cells(getPosition())->unknown45de40())
			{
				HItem matter = world->unknown71e7c0(getPosition(),rng.rangeInt(1,5),false);
				if (matter.isValid())
					world->unknown464840(matter);
				SHOW_MESSAGE(0x30b,&string("debris"),NULL,0,self,HEntity(),NULL,0);
			}
			else if (cells(getPosition())->getItem().isValid() && cells(getPosition())->getItem()->unknown457e30())
			{
				HItem item = cells(getPosition())->getItem();
				SHOW_MESSAGE(0x30b,&item->unknown571db0(false,false),NULL,0,self,HEntity(),NULL,0);
				int amount = rng.rangeInt(5,item->unknown9b6bf0() / 2 + 1);
				item->unknown57dbe0(0,0,1,1);
				HItem matter = world->unknown71e7c0(getPosition(),amount,false);
				if (matter.isValid())
					world->unknown464840(matter);
			}
		}
	}

	// laser shovel (part 0xd7) digs the cell ahead at enough momentum
	if (player)
	{
		HItem shovel = unknown5d25e0(0xd7);
		if (shovel.isValid() && shovel->unknown457fb0() <= momentum)
		{
			Point target(footprint[0],directions[lastDirection]);
			if (cells.contains(target))
			{
				int effectID = 0;
				bool dug = false;
				if (cells(target)->unknown45d500() && cells(target)->getProp()->unknown45c630() != -1 && cells(target)->getProp()->unknown45c800(8) == NULL)
				{
					SHOW_MESSAGE(0x298,&shovel->unknown571db0(false,false),&cells(target)->getProp()->getName(),0,self,HEntity(),NULL,0);
					cells(target)->getProp()->unknown45ce10(false,false,false,self);
					if (lookupID(string("Laser_Shovel_Auto"),&effectID))
						effectPool->unknown508610()->unknown503b20(effectPool,effectID,target,effectOrigin,0,0,0,9,0);
					dug = true;
				}
				if (cells(target)->unknown45d4e0() && !cells(target)->unknown45db70() && cells(target)->getArmor() != -1 && cells(target)->getEffect(8) == NULL)
				{
					SHOW_MESSAGE(0x298,&shovel->unknown571db0(false,false),&cells(target)->unknown45d140(),0,self,HEntity(),NULL,0);
					cells(target)->unknown45e110(false,false,self);
					stats.add4729d0(0x409,1,string(""),-1);
					int wallEffectID = 0;
					if (lookupID(string("Laser_Shovel_Auto"),&wallEffectID))
						effectPool->unknown508610()->unknown503b20(effectPool,wallEffectID,target,effectOrigin,0,0,0,9,0);
					dug = true;
				}
				if (dug)
				{
					unknown639ec0(HEntity(),0);
					unknown63a0d0();
				}
			}
		}
	}

	if (!unknown5fdd30())
		return moveTime;

	// nearby robots react; stop if one of them destroyed this entity
	HEntity selfHandle = self;
	vector<HEntity> nearby;
	unknown5c8880(&nearby);
	shuffle(nearby);
	for (unsigned int i = 0; i < nearby.size(); i++)
	{
		if (nearby[i]->unknown63c340(self))
		{
			if (selfHandle.operator->() == NULL)
				return moveTime;
			break;
		}
	}

	// cave-ins
	if (caveinStress >= 2.0 && factionCausesCaveins[data->unknown28])
	{
		if (isPlayer())
		{
			stats.add4729d0(0x3fc,1,string(""),-1);
			if (stats.unknown472c70(0x3fc) == 30)
				playerData.unknown77fbc0(0xe6);
		}
		if (rng.chance(caveinStress >= 8.0 ? (caveinStress >= 16.0 ? 10 : 5) : 3))
			cells(pos)->unknown66d580(0);
	}

	// leaving through the CBD exits
	if (cbd != NULL)
	{
		if ((footprint[0] == cbdExit1 || footprint[0] == cbdExit2) && cbd->take48bf50(self))
		{
			unknown5ded70(10000);
			unknown5deb40(10000);
			mapView->unknown81a340(self);
			opR1d_4541b0(0x8a,0,0);
			if (cbd != NULL)
				cbd->unknown7ac1c0(self,0,0,getNameAt0c());
			mapView->unknown49adc0(2000);
		}
	}

	if (player && luigiAiActive && !luigiDiggingReported && caveinStress >= 10.0)
	{
		do	// an inlined "alert" macro: flags the message log, optional sound (constant-false here), message
		{
			messageLog.unknown451400(1);
			if (false)
				opR1d_4541b0(-1,0,0);
			SHOW_MESSAGE(0x324,&string("ALERT: LUIGI IS DIGGING AGAIN."),NULL,0,HEntity(),HEntity(),NULL,0);
			logMsgs->scrollToEnd();
		} while (0);
		luigiDiggingReported = true;
	}

	return moveTime;
}
