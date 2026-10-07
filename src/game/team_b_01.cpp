// team_b_01: small game-logic methods (0x500000-0x9affff) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
#include <vector>
#include <string>
#include <istream>
#include <ostream>
using namespace std;

//==================================================================
// shared partial declarations
//==================================================================

struct Point { int x; int y; };	// NOTE: placeholder layout

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
	bool operator==(HEntity other) const;	// 0x9b78e0
	void clear() throw();	// 0x9b7270
};

class HItemP { public: int ID; };	// NOTE: placeholder layout

class Map
{
public:
	int getTurn();	// 0x464270
	HEntity getPlayer();	// 0x4630f0
};
extern Map *endObjA;	// 0xcefc4c

class BS	// NOTE: same object as endObjA
{
public:
	int unknown7151c0();	// NOTE: placeholder name
	void opw3_unknown726b70(HItemP item);	// NOTE: placeholder name
};

template <class T> void readBinary(istream &stream, T *value);
template <class T> void writeBinary(ostream &stream, T *value);
template <class T> void OpQ5_clearObjects(vector<T*> &v);
template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v);
template <class T> void OpQ5_writeElements(ostream &stream, vector<T> &v);
template <class T> void OpU8_readStructs(istream &stream, vector<T> &v);
template <class T> bool OpQ5_findByName(vector<T*> &v, string &name, T *&result);

//==================================================================
// globals and free functions
//==================================================================

extern int opt5_loadThreads;	// NOTE: placeholder name (0xcefca4)
void opt5_decrementLoadThreads()	// 0x790be0, NOTE: placeholder name
{
	opt5_loadThreads--;
}

class CCodes { public: void unknown9000e0(); };	// NOTE: placeholder name
extern CCodes *opq4c_cec104;	// NOTE: placeholder name (0xcec104)
void opr5e_unknown8ff8a0()	// NOTE: placeholder name (0x8ff8a0, name from src/op/op_r5e.cpp)
{
	opq4c_cec104->unknown9000e0();
}

struct CellTerrainRecord;
struct OpT4_Cell;
OpT4_Cell *opt4_setTerrain(int x, int y, CellTerrainRecord *terrain);	// 0x6c9b40
struct TeamB_Pt { int x; int y; };	// NOTE: placeholder name
void teamb_setTerrainAt(TeamB_Pt &p, CellTerrainRecord *terrain)	// NOTE: placeholder name (0x6c9c90)
{
	opt4_setTerrain(p.x,p.y,terrain);
}

struct TeamB_Pair { int a; int b; };	// NOTE: placeholder name
int teamb_select808db0(bool first, TeamB_Pair &pair)	// NOTE: placeholder name (0x808db0)
{
	return first ? pair.a : pair.b;
}

//==================================================================
// turn counters
//==================================================================

struct TeamB_577af0	// NOTE: placeholder name/layout
{
	char pad[0x30];
	int startTurn;
	int turnsElapsed();
};
int TeamB_577af0::turnsElapsed()	// 0x577af0
{
	return endObjA->getTurn() - startTurn;
}

struct TeamB_577ad0 { char pad[0x2c]; int endTurn; int turnsLeft(); };	// NOTE: placeholder name/layout
int TeamB_577ad0::turnsLeft()	// 0x577ad0
{
	return endTurn - endObjA->getTurn();
}

struct TeamB_673b00 { int pad0; int pad4; int expireTurn; void setExpire673b00(); };	// NOTE: placeholder name/layout
void TeamB_673b00::setExpire673b00()	// 0x673b00
{
	expireTurn = endObjA->getTurn() + 20;
}

struct TeamB_69ec90 { char pad[0x94]; int value94; void update69ec90(); };	// NOTE: placeholder name/layout
void TeamB_69ec90::update69ec90()	// 0x69ec90
{
	value94 = ((BS*)endObjA)->unknown7151c0();
}

struct TeamB_579170 { int pad0; HItemP item; int pad8; int valueC; void unknown579170(int v); };	// NOTE: placeholder name/layout
void TeamB_579170::unknown579170(int v)	// 0x579170
{
	valueC = v;
	((BS*)endObjA)->opw3_unknown726b70(item);
}

struct TeamB_5758f0 { char pad[0x10]; HEntity entity; bool isPlayer(); };	// NOTE: placeholder name/layout
bool TeamB_5758f0::isPlayer()	// 0x5758f0
{
	return entity == endObjA->getPlayer();
}

extern int teamb_d323c0;	// NOTE: placeholder name (0xd323c0)
struct TeamB_7c6830 { int unknown7c6830(); };	// NOTE: placeholder name
int TeamB_7c6830::unknown7c6830()	// 0x7c6830
{
	return teamb_d323c0 + 3;
}

extern int teamb_difficulty_cf4718;	// NOTE: placeholder name (0xcf4718)
extern float teamb_scale_ba6614[];	// NOTE: placeholder name (0xba6614)
struct TeamB_579880 { char pad[0x24]; int value; void setScaled(int base); };	// NOTE: placeholder name/layout
void TeamB_579880::setScaled(int base)	// 0x579880
{
	value = (int)(base * teamb_scale_ba6614[teamb_difficulty_cf4718]);
}

extern int teamb_cf645c;	// NOTE: placeholder name (0xcf645c)
extern float teamb_cf46f8;	// NOTE: placeholder name (0xcf46f8)
struct TeamB_77f230 { char pad[0x120]; float value120; void set77f230(float value, int unused); };	// NOTE: placeholder name/layout
void TeamB_77f230::set77f230(float value, int unused)	// 0x77f230
{
	if (teamb_cf645c)
		return;
	float previous = teamb_cf46f8;
	value120 = value;
}

//==================================================================
// loading / serialization helpers
//==================================================================

void opv1_initColorSlots_434440();	// NOTE: placeholder name
void opR1f_465b10();	// NOTE: placeholder name
struct OpT5_DataLoader { void unknown78f9f0(); };	// NOTE: placeholder name
void OpT5_DataLoader::unknown78f9f0()	// 0x78f9f0
{
	opv1_initColorSlots_434440();
	opR1f_465b10();
}

struct OpQ5_T9d1d80;
struct OpQ5_T9d8800;
struct OpQ5_U9d9600 { char pad[8]; };	// NOTE: placeholder layout
struct OpU8_T9da130 { int m0; };	// NOTE: placeholder layout
struct OpQ5_U9d7530;

struct TeamB_674a80	// NOTE: placeholder name/layout (global object at 0xcf6428)
{
	char pad[0x50];
	vector<OpQ5_T9d1d80*> objects;
	void clear674a80();
};
void TeamB_674a80::clear674a80()	// 0x674a80
{
	OpQ5_clearObjects(objects);
}

struct OpQ5_T9d8dd0	// NOTE: placeholder layout
{
	vector<OpQ5_T9d8800*> objects;
	void serialize(ostream &stream);
};
void OpQ5_T9d8dd0::serialize(ostream &stream)	// 0x57f120
{
	OpQ5_writeObjects(stream,objects);
}

struct OpQ5_T9d1270	// NOTE: placeholder layout
{
	bool flag;
	void serialize(ostream &stream);
};
void OpQ5_T9d1270::serialize(ostream &stream)	// 0x65c1b0
{
	writeBinary(stream,&flag);
}

struct OpQ5_T9d1550	// NOTE: placeholder layout
{
	bool flag;
	OpQ5_T9d1550(istream &stream);
};
OpQ5_T9d1550::OpQ5_T9d1550(istream &stream)	// 0x65c1d0
{
	readBinary(stream,&flag);
}

struct TeamB_6722d0 { vector<OpQ5_U9d9600> elements; void serialize(ostream &stream); };	// NOTE: placeholder name
void TeamB_6722d0::serialize(ostream &stream)	// 0x6722d0
{
	OpQ5_writeElements(stream,elements);
}

struct TeamB_6722f0 { vector<OpU8_T9da130> elements; void unserialize(istream &stream); };	// NOTE: placeholder name
void TeamB_6722f0::unserialize(istream &stream)	// 0x6722f0
{
	OpU8_readStructs(stream,elements);
}

extern vector<OpQ5_U9d7530 *> opX4d_entityRecords;	// NOTE: placeholder name (0xd25de0)
struct TeamB_56f3c0 { char pad[0x1b4]; string name; OpQ5_U9d7530 *getRecord(); };	// NOTE: placeholder name/layout
OpQ5_U9d7530 *TeamB_56f3c0::getRecord()	// 0x56f3c0
{
	OpQ5_U9d7530 *record;
	OpQ5_findByName(opX4d_entityRecords,name,record);
	return record;
}

struct OpR6_KC_4_0	// NOTE: placeholder name (same as src/op/op_r6_kc.cpp)
{
	int m0;
	OpR6_KC_4_0();
	OpR6_KC_4_0(const OpR6_KC_4_0 &o);
};
extern int teamb_caed20;	// NOTE: placeholder name (0xcaed20, tick count)
struct TeamB_807f40 { char pad[0x218]; vector<OpR6_KC_4_0> list; int value228; void setList(const vector<OpR6_KC_4_0> &v); };	// NOTE: placeholder name/layout
void TeamB_807f40::setList(const vector<OpR6_KC_4_0> &v)	// 0x807f40
{
	list = v;
	value228 = teamb_caed20;
}

//==================================================================
// misc objects
//==================================================================

struct Prop65 { int unknown0; void unknown65ec20(); void init65d660(int value); };	// NOTE: placeholder name/layout
void Prop65::init65d660(int value)	// 0x65d660
{
	unknown0 = value;
	unknown65ec20();
}

struct OpY9_Pool4 { void clearAll(bool deleteItems); };	// NOTE: placeholder name
extern OpY9_Pool4 globalPool4;	// 0xd208d4
struct TeamB_EntityList { vector<HEntity> entities; void clear6722b0(); };	// NOTE: placeholder name
void TeamB_EntityList::clear6722b0()	// 0x6722b0
{
	globalPool4.clearAll(true);
	entities.clear();
}

bool opX4d_unknown6fcc60(bool flag);	// NOTE: placeholder name
HEntity opX4d_unknown6fcf90(bool flag);	// NOTE: placeholder name
struct TeamB_6fd920 { void unknown6fd920(); };	// NOTE: placeholder name
void TeamB_6fd920::unknown6fd920()	// 0x6fd920
{
	opX4d_unknown6fcc60(true);
	opX4d_unknown6fcf90(true);
}

struct TeamB_965220 { char pad[0x74]; int effect; void unknown9650c0(int effect); void unknown965220(); };	// NOTE: placeholder name/layout
void TeamB_965220::unknown965220()	// 0x965220
{
	if (effect >= 29)
		unknown9650c0(effect);
}

struct ItemEffect;
class Item	// NOTE: partial
{
public:
	ItemEffect *getEffect(int type);
	void unknown458630(ItemEffect *effect);	// NOTE: placeholder name
	void reset578800();	// NOTE: placeholder name
	char pad[0x40];
	bool flag40;
	int value44;
};
void Item::reset578800()	// 0x578800
{
	flag40 = false;
	value44 = 0;
	unknown458630(getEffect(107));
}

struct TeamB_783020	// NOTE: placeholder name/layout
{
	char pad[0x4f4];
	vector<Point>::iterator it4f4;
	char pad2[0x510 - 0x4f4 - sizeof(vector<Point>::iterator)];
	vector<Point>::const_iterator it510;
	char pad3[0x548 - 0x510 - sizeof(vector<Point>::const_iterator)];
	int value548;
	void unknown783020();
};
void TeamB_783020::unknown783020()	// 0x783020
{
	if (value548)
		return;
	it4f4 - it510;
}

class OpR2c_Options { public: bool unknown46f4b0(int a); };	// NOTE: placeholder name
extern OpR2c_Options opr2c_d1e860;	// NOTE: placeholder name (0xd1e860)
class OpR3c_Overmind { public: void unknown682420(int type, int amount); void unknown681e70(int amount); };	// NOTE: placeholder name
void OpR3c_Overmind::unknown681e70(int amount)	// 0x681e70
{
	if (amount > 0 && opr2c_d1e860.unknown46f4b0(1))
		unknown682420(6,amount);
}

extern HEntity teamb_d1da44;	// NOTE: placeholder name (0xd1da44)
struct TeamB_Rect16 { int a, b, c, d; };	// NOTE: placeholder name
class OpV3h_Map	// NOTE: placeholder name
{
public:
	void unknown827950();
	void unknown81a090(HEntity entity);
	char pad[0x50c];
	vector<TeamB_Rect16> list50c;
};
void OpV3h_Map::unknown81a090(HEntity entity)	// 0x81a090
{
	if (entity == teamb_d1da44 && list50c.size())
	{
		unknown827950();
		teamb_d1da44.clear();
	}
}

//==================================================================
// UI consoles
//==================================================================

class XConsole	// NOTE: partial
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool isActive();
	XConsole *getParent() throw();	// 0x9b8f00
	char pad04[0x60 - 0x04];
};

class Console : public XConsole	// NOTE: partial
{
public:
	virtual ~Console();
	int unknown60;
	void *engine;
	void *title;
};

// slot 2 override shared (ICF) by CAllySymbol, CIntelSymbol, CGamemenuButtonText, CInfoText, ...
class TeamB_ParentForward : public XConsole { public: bool isActive7c5eb0(); };	// NOTE: placeholder name
bool TeamB_ParentForward::isActive7c5eb0()	// 0x7c5eb0
{
	return getParent()->isActive();
}

// NOTE: CEffect::~CEffect (0x95fa70) is the implicit destructor generated in src/op/op_w7.cpp; not defined here.

struct TeamB_Page { char pad[0x6c]; int *value6c; int value70; };	// NOTE: placeholder layout

class CGallery { public: char pad[0xa4]; vector<TeamB_Page*> pages; int unknown7e8c30(); };	// NOTE: partial
int CGallery::unknown7e8c30()	// 0x7e8c30
{
	return pages.front()->value70;
}

struct MapRecord;
extern vector<MapRecord*> teamb_mapRecords;	// NOTE: placeholder name (0xd02cb4)
class CLore	// NOTE: partial
{
public:
	char pad[0x70];
	vector<TeamB_Page*> pages;
	int unknown7ebd10();
	int unknown7ebd30() const;
};
int CLore::unknown7ebd10()	// 0x7ebd10
{
	return *pages.front()->value6c;
}
int CLore::unknown7ebd30() const	// 0x7ebd30
{
	return teamb_mapRecords.size() - 1 - *pages.back()->value6c;
}

class CSupporters { public: char pad[0x88]; vector<TeamB_Page*> pages; int unknown7f3790(); };	// NOTE: partial
int CSupporters::unknown7f3790()	// 0x7f3790
{
	return pages.front()->value70;
}

class CCommands	// NOTE: partial; v0..v9 stand in for the Console virtuals
{
public:
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	void unknown7d08c0();	// NOTE: placeholder name
	void unknown7d0a80();	// NOTE: placeholder name
};
void CCommands::unknown7d0a80()	// 0x7d0a80
{
	v9();
	unknown7d08c0();
}
