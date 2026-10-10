// NOTE: placeholder names and partial layouts; Overmind::turnUpdate (0x675100): per-turn Complex 0b10 response
// logic (sensor drones, garrison alerts, squad retasking, investigations, intercepts, patrols and other events).
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;

struct F7Point
{
	int x, y;
	F7Point();	// 0x453b40
	F7Point(int x_, int y_);	// 0x46ca20
	F7Point(int v);	// 0x409990
	F7Point(const F7Point &p);	// 0x46ca50
	F7Point &operator=(const F7Point &p);	// 0x46ca50
	int randomInRange();	// 0x40c130
	F7Point &operator+=(const F7Point &p);	// 0x409a30
	bool operator==(const F7Point &p) const;	// 0x409b90
	void set40a030(const F7Point &p);	// 0x40a030
	void set40a090(const F7Point &a, const F7Point &b);	// 0x40a090
	F7Point &operator=(int v);	// 0x409ff0
};
struct F7Area
{
	F7Point p1, p2;
	F7Area();	// 0x40b100
	F7Area(int x1, int y1, int x2, int y2);	// 0x40b1e0
	F7Point randomPoint40be90();	// 0x40be90
	int width();	// 0x40b670
	int height();	// 0x40b690
	F7Point center();	// 0x40b620
	void grow(int n);	// 0x40bc10
	void clip(const F7Point &a, const F7Point &b);	// 0x40bc40
};
struct F7View
{
	char pad[0x14];
	F7View(int w, int h, int x, int y, int cw, int ch, int a, int b);	// 0x9cfc50
	~F7View();	// 0x9b6bd0
	int &operator()(const F7Point &p);	// 0x9cfd90
};
struct F7Entity;
struct F7AI;
struct F7Item;
struct F7Prop;
struct F7HE {int id; F7HE(); bool isValid() const; bool isNull() const; F7Entity *operator->() const; bool operator!=(F7HE o) const; void reset9b7270();};	// 0x9b6590, 0x9b7230, 0x9b65d0, 0x9b6570, 0x9b6510
struct F7HProp {int id; F7HProp(); bool isValid() const; bool isNull() const; F7Prop *operator->() const;};	// 0x9b7230, 0x9b64f0
struct F7Prop
{
	string &getType();	// 0x45c590
	string *getName();	// 0x45c5b0
	int id44ab40();	// 0x44ab40
	void unknown45ce10(int a, int b, int c, F7HE e);	// 0x45ce10
	int unknown457b10();	// 0x457b10
	struct F7PropDef *def9b8f00();	// 0x9b8f00
	struct F7Machine *machine45cb30();	// 0x45cb30
	const F7Point &pos4184d0();	// 0x4184d0
	int unknown45c650();	// 0x45c650
	bool isPassableFor(F7HE e);	// 0x65e1d0
};
struct F7Cell
{
	F7HProp getProp();	// 0x45d550
	F7HE getEntity();	// 0x45d250
	struct F7HItem getItem();	// 0x45d8f0
	bool field4550b0();	// 0x4550b0
};
struct F7Map
{
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	F7Cell **atPoint(const F7Point &p);	// 0x9ced70
	void getRect(const F7Point &p, int r, F7Area &out);	// 0x9b4430
	F7Point size9b7930();	// 0x9b7930
	F7Area getArea9b4400();	// 0x9b4400
	F7Cell **at(int x, int y);	// 0x9ceda0
	void getNeighbors9d24b0(const F7Point &p, vector<F7Point> &out);	// 0x9d24b0
};
extern F7Map f7_cells_cfd44c;
struct F7AI
{
	bool unknown458fb0(F7HE e);	// 0x458fb0
	F7Area *area4b5730();	// 0x4b5730
	int mode4();	// 0x9b8f00
	void set451930(int v);	// 0x451930
	vector<F7Point> *path4549b0();	// 0x4549b0
	void setFollowEntity(F7HE e, int mode);	// 0x5b2f80
	void unknown459540(const F7Point &p);	// 0x459540
	void unknown4582d0(int a);	// 0x4582d0
	void setMode4505b0(int a);	// 0x4505b0
	char pad[0x130];
	F7AI(F7HE e, int a, int b);	// 0x57f6a0
	void unknown459470(const F7Area &a);	// 0x459470
	vector<F7Point> *path458ef0();	// 0x458ef0
};
struct F7Entity
{
	const F7Point &getPosition();	// 0x45a4a0
	F7AI *getAI();	// 0x45b590
	int getFaction();	// 0x45a2c0
	string &getName();	// 0x45a280
	bool unknown5c98c0(int a, int b, int c);	// 0x5c98c0
	struct F7HGroup getGroup();	// 0x45a3f0
	int unknown5c8db0();	// 0x5c8db0
	struct F7HItem unknown5d2380(int a);	// 0x5d2380
	int unknown5d15a0(int a);	// 0x5d15a0
	int getTarget45a760();	// 0x45a760
	void unknown5fdab0();	// 0x5fdab0
	bool isPlayer();	// 0x5c7600
	F7Point unknown45a4c0();	// 0x45a4c0
	void setAI(F7AI *ai);	// 0x64ecf0
	string &name416f40();	// 0x416f40
	void unknown5de480(struct F7Def *d);	// 0x5de480
	void unknown5deb40(int a);	// 0x5deb40
	void unknown5ded70(int a);	// 0x5ded70
	void removeEffectsA639730(int a);	// 0x639730
	bool unknown5cb680(struct F7HSquad s);	// 0x5cb680
};
struct F7Group {int kind9b4350();};	// 0x9b4350
struct F7HGroup {int id; F7Group *operator->() const;};	// 0x9b7250
struct F7Item
{
	int unknown457880();	// 0x457880
	int unknown9b6bf0();	// 0x9b6bf0
	const F7Point &unknown575920();	// 0x575920
	string getName571db0(int a, int b);	// 0x571db0
	int unknown457a30();	// 0x457a30
	void remove57dbe0(int a, int b, int c, int d);	// 0x57dbe0
};
struct F7HItem {int id; bool isValid() const; F7Item *operator->() const;};	// 0x9b7230, 0x9b65b0
struct F7Marker {void unknown6c20b0(int a, const F7Point &p, int b);};	// 0x6c20b0
struct F7HM {int id; F7Marker *operator->() const;};	// 0x9b7cd0
struct F7Access;
struct F7Kind {int f0; string name;};
struct F7PropDef {char pad0[0x60]; F7Kind *f60; char pad64[0x8c - 0x64]; int f8c; char pad90[0xf8 - 0x90]; int kind;};
struct F7Rec {int f0; char pad4[0x9c - 4]; int f9c; char pada0[0x148 - 0xa0]; vector<int> f148; int getValue459840(int a);};	// 0x459840
typedef F7Rec F7Unit;
struct F7ItemDef {int f0; char pad4[0x44 - 4]; int f44; int getValue457430(int a);};	// 0x457430
class F7MachineProcess;
struct F7Machine {char pad0[8]; int f8; char padc[0x28 - 0xc]; int f28; char pad2c[0x38 - 0x2c]; F7MachineProcess *process; char pad3c[0x80 - 0x3c]; int f80; int f84; int f88; int f8c;};
class F7MachineProcess
{
	char pad[0x48];
public:
	F7MachineProcess(F7HProp machine_, int type_, int delay_, F7ItemDef *processA_, F7Unit *processB_, bool unknown14_, bool unknown15_, F7HE item, int garrisonType_, F7Point *target_, bool unknown44_, bool unknown45_);	// 0x659800
};
template <class T> class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void add(T value, int weight);	// 0x9ba310
	T &pick();	// 0x9ba470
};
struct F7Def;
struct F7Cfg {char pad[0x14]; F7Cfg() {} void randomize45e940();};	// 0x9c0790
struct F7Party {char pad[0x38]; F7Party(int a, F7HE e, int b, int c, int d);};	// 0x673310
struct F7Tracker {void spawn7aa280(int a, int b, string s);};	// 0x7aa280
struct F7Holder {char pad[0x30]; F7Tracker *f30;};
struct F7CMap {void unknown8195a0(const F7Point &p, int a, int b);};	// 0x8195a0
struct F7Squad
{
	int type;
	F7HE leader;
	int f8;
	bool fc;
	int f10;
	int f14;
	int f18;
	string name1c;
	bool unknown45e7d0();	// 0x45e7d0
	bool test45e820();	// 0x45e820
	void pickArea673780();	// 0x673780
};
struct F7Members {vector<F7HE> *members(); int count44afb0();};	// 0x416f40, 0x44afb0
struct F7HSquad {int id; F7Members *operator->() const;};	// 0x9b7250
struct F7Game
{
	F7HE getPlayer();	// 0x4630f0
	int getTurn();	// 0x464270
	int unknown4642d0();	// 0x4642d0
	int unknown4642f0();	// 0x4642f0
	F7HSquad squad463890(int kind);	// 0x463890
	bool unknown4658e0();	// 0x4658e0
	vector<struct F7Access *> *accesses462e10();	// 0x462e10
	int unknown464000();	// 0x464000
	int unknown717d60();	// 0x717d60
	vector<F7HE> *unknown463c00(int a);	// 0x463c00
	vector<vector<F7HM> > &lists463ec0();	// 0x463ec0
	vector<vector<F7Point> > *lists459070();	// 0x459070
	vector<F7Point *> *unknown464940();	// 0x464940
	int unknown463d20();	// 0x463d20
	int unknown463d40();	// 0x463d40
	vector<F7Point> *unknown463d60();	// 0x463d60
	vector<F7Point> *unknown463ab0();	// 0x463ab0
	void unknown465120(int a);	// 0x465120
	bool findPlaceableNear(const F7Point &p, F7Point &out, int a);	// 0x71c150
	F7HM addRecord(F7HM h);	// 0x777a20
	F7HE placeEntity(F7Rec *rec, const F7Point &p, int a, int b, int c, int d, int e);	// 0x6c58c0
	bool isVisible(const F7Point &p);	// 0x4631c0
	F7HE unknown6c51d0(struct F7Def *d, F7HE e, int a, int b);	// 0x6c51d0
	void unknown714000(vector<F7Point> &v);	// 0x714000
	void unknown714090(vector<F7Point> &v);	// 0x714090
	void unknown736270(const string &s);	// 0x736270
	bool unknown74d270();	// 0x74d270
	bool unknown4631f0(F7HE e);	// 0x4631f0
	char pad[0x320];
	int f320;
	int f324;
	char pad328[0x5b4 - 0x328];
	int f5b4;
};
extern F7Game *f7_map_cefc4c;
struct F7Drone {F7HE e; int f4; int f8;};
struct F7Location
{
	char pad0[4];
	int depth;
	int f8;
	bool inRange46ecb0();	// 0x46ecb0
	int getDepthIndex();	// 0x46ed20
};
struct F7HLocation {int id; bool isValid() const; F7Location *operator->() const; bool operator!=(F7HLocation o) const;};	// 0x9b7910, 0x9b6510
extern F7HLocation f7_location_d1e888;
extern F7HLocation f7_hloc_d1ebe0, f7_hloc_d1ebd8;
struct F7Access {F7Point pos; F7HLocation loc; bool fc;};
struct F7GameData
{
	string &getEntryText(const string &key);	// 0x46f6d0
	bool unknown46f4b0(int a);	// 0x46f4b0
	void addToEntry46f7e0(const string &key, int v);	// 0x46f7e0
	int getDepthIndex();	// 0x46f4e0
	void unknown7897a0(int a);	// 0x7897a0
	string generateID();	// 0x46f890
};
extern F7GameData f7_gameData_d1e860;
struct F7Stats
{
	void add4729d0(int id, int value, string s, int a);	// 0x4729d0
	int get472c90(int id);	// 0x472c90
	int get472c70(int id);	// 0x472c70
	void add472b90(int id, int value);	// 0x472b90
};
extern F7Stats f7_stats_d2c658;
struct F7Flags {void set451400(int v);};	// 0x451400
extern F7Flags f7_flags_cf1080;
struct F7Bubble {void bubble(bool b);};	// 0x8758d0
extern F7Bubble *f7_bubble_cec058;
struct F7Log {void scrollToEnd();};	// 0x7b4f10
extern F7Log *f7_log_cec0b4;
struct F7Tally {void unknown6998a0(int a, int b, int c); void unknown699c20();};	// 0x6998a0, 0x699c20
extern F7Tally f7_tally_cf6888;
extern vector<int> f7_vec_cf6898;
struct F7Player {bool isSlotEmpty(int slot); void unknown77fbc0(int a); bool hasCompanion780790();};	// 0x780790
//	// 0x46de40, 0x77fbc0
extern F7Player f7_player_cf45d8;
struct F7Voice {void say(int a, int b, string s);};	// 0x49e250
extern F7Voice *f7_voice_cefb48;
struct F7Carto {bool findPath(const F7Point &a, const F7Point &b, void *cost, void *data, vector<F7Point> &path); bool unknown40ca50(const F7Point &p, int r, void *cost, void *data, vector<F7Point> &path, void *x);};	// 0x40ca50
extern F7Carto f7_carto_cfe568;
extern void *f7_cost_cefc38;
extern int f7_cfc224;
struct F7World
{
	void unknown742630(vector<F7Point> &v, int a, int b);	// 0x742630
	F7HE unknown6c6450(F7HE e, int a);	// 0x6c6450
	F7HE unknown6c5dc0(const string &name, const F7Point &p, int a, bool b, int c, int d, bool e);	// 0x6c5dc0
	void unknown6c65a0(F7HE e, const string &s, bool b);	// 0x6c65a0
	void unknown7456a0();	// 0x7456a0
	F7Rec *selectRobotOfClass(int a, int b, int c, int d);	// 0x6c5600
	struct F7ItemDef *selectRandomItemOfRating(int rating, int a, int b, int c, int d, int e, int f);	// 0x6c40e0
};
extern F7World *f7_bs_cefc4c;
struct F7Strings
{
	void *proxy;
	string *first, *last, *end;
	F7Strings();	// 0x9b8e80
	~F7Strings();	// 0x9b0460
	void push(const string &s);	// 0x9b06f0
	string &at(unsigned int i) throw();	// 0x9b06a0
};
extern string f7_squadNames_d2f350[];
extern string f7_zoneNames_cfaca0[];
extern const float f7_b91a2c, f7_b9077c, f7_ba6568, f7_b91e2c, f7_b91b70;
extern int f7_diff_cf4718;
extern int f7_cf462c;
extern bool f7_cefb0f;
extern int f7_tblA_b92dd8[][9];
extern int f7_tblB_b92880[][9];
extern int f7_b92558[][5];
extern int f7_factions_caf1cc[];
extern int f7_b91e8c[][3];
extern int f7_b91e90[][3];
extern int f7_b91df4[];
extern int f7_b91dfc[][2][3];
extern int f7_b91e00[][6];
extern int f7_b91e04[][2][3];
extern int f7_b91e08[][6];
extern int f7_b91e0c[][6];
extern bool f7_d25450, f7_d25610, f7_d257d7, f7_mute_d28fb0;
extern bool f7_surgicalMaps_b90180[][6];
extern bool f7_b90181[][6];
extern bool f7_b90182[][6];
extern int f7_surgicalIntervals_b93790[][5];
extern int f7_b938b8[][3];
extern int f7_b938bc[][3];
extern int f7_b93f18[][4];
extern int f7_cf47fc;
extern const double f7_c37068, f7_c370c8;
struct F7Obj {char pad[0x110]; int f110;};
extern F7Obj *f7_cf68b4;
extern int f7_cf6428;
extern int f7_b93f1c[][4];
extern bool f7_d1ebfc, f7_d257d8;
extern F7Point f7_range_d223cc;
extern int f7_ba6644[];
extern bool f7_b90183[][6];
extern bool f7_b90184[][6];
extern int f7_b939a0[][10];
extern int f7_b939a4[][10];
extern int f7_b939a8[][10];
extern int f7_b939ac[][10];
extern const float f7_b91a3c;
extern string f7_cf2648;
extern void *f7_cost_cefc30;
struct F7Xom {void unknown69e700(int a, int b, float c); bool unknown69e9b0(const F7Point &p);};	// 0x69e700, 0x69e9b0
extern F7Xom f7_xom_d25450;
struct F7Explosion
{
	char pad[0x40];
	F7Explosion(F7HE a, struct F7Def *def, const F7Point &p, F7HE b, const F7Point &c, const F7Point &d);	// 0x515ca0
};
struct F7Factory {F7HM createC(); F7HM createA(F7Explosion *e);};	// 0x7930e0
//	// 0x793190
extern F7Factory *f7_factory_cefaa8;
void f7_eraseAt(vector<int> &v, unsigned int &index);	// 0x9ce6d0
void f7_eraseAtP(vector<F7Point> &v, unsigned int index);	// 0x9d5190
int f7_thresholdIndex(int v);	// 0x433260
F7HE f7_randomRecord(vector<F7HE> &v);	// 0x9dafb0
F7Point f7_randomPoint(vector<F7Point> &v);	// 0x9d5350
void f7_deleteObjectAndStep(vector<F7Point *> &v, unsigned int &index);	// 0x9de640
bool f7_containsRecord(vector<int> &v, int x);	// 0x9db330
string f7_intToString(int v);	// 0x4051f0
extern bool f7_b90185[][6];
extern F7Point f7_range_cf39ec;
extern int f7_b92208[][5], f7_b9220c[][5], f7_b92210[][5], f7_b92214[][5], f7_b92218[][5];
extern const float f7_ba7ebc;
extern int f7_b93948[][2], f7_b9394c[][2];
extern int *f7_cf4700;
extern vector<F7Rec *> f7_records_d25de0;
extern int f7_b94030[][4], f7_b94034[][4], f7_b94038[][4], f7_b9403c[][4];
extern int f7_caf160, f7_caf164;
F7Access *f7_randomRec(vector<F7Access *> &v);	// 0x9d5d00
F7Def *f7_randomDef(vector<F7Def *> &v);	// 0x9d5d00
bool f7_findByName(vector<F7Def *> &v, const string &name, F7Def *&out);	// 0x9d7be0
bool f7_findRec(vector<F7Rec *> &v, const string &name, F7Rec *&out);	// 0x9d7530
void f7_message(int id, F7HE e, const string &s, int a);	// 0x49c610
char f7_randomChar(const string &chars);	// 0x4085b0
int f7_minInt(int a, int b);	// 0x9cdb30
void f7_sound454260(const F7Point &p, int id);	// 0x454260
void f7_eraseStep(vector<F7Point> &v, unsigned int &index);	// 0x9d7300
void f7_fn9d5460(vector<F7Point> &v, int a, F7Point p);	// 0x9d5460
void f7_shuffle(vector<F7Point> &v);	// 0x9d7350
void f7_fn9d0690(int &v, int a, int b);	// 0x9d0690
void f7_fn9da8f0(vector<F7HProp> &v, vector<int> &out);	// 0x9da8f0
void f7_fn9db000(vector<F7Def *> &v, F7Def *d);	// 0x9db000
void f7_deleteObjects(vector<F7Def *> &v);	// 0x9d9c50
extern bool f7_d1dd38;
extern int f7_d1dd3c;
extern vector<F7Def *> f7_defs_cfd2cc, f7_defs_d2d1c4;
extern F7Point f7_range_cf0468, f7_range_d1de88;
extern const float f7_c36f84;
extern vector<vector<F7HProp> > f7_machines_d31640;
extern F7CMap *f7_cmap_cec054;
extern int f7_ba5000[][5];
extern F7Point f7_dirs_d015d8[];
extern vector<F7HLocation> f7_hist_d1e88c;
extern bool f7_cf4d16, f7_d1eacc;
extern int f7_b903c0[];
extern vector<vector<int> *> f7_statsHist_d2c65c;
extern vector<int> f7_d1eb9c;
extern int f7_cefbc0;
extern F7Holder *f7_cf4ac8;
struct F7DroneList;
void f7_deleteObject(vector<F7Drone *> &v, int index);	// 0x9d8f20
void f7_eraseRange(vector<F7Point> &v, int from, int to);	// 0x9d53f0
void f7_adjacent(const F7Point &p, vector<F7Point> &out);	// 0x4fab80
void f7_collectProps(int id, vector<F7Point> &v, int a, int b, int c);	// 0x517ae0
bool f7_showMessage(int id, string *a, string *b, string *c, F7HE e1, F7HE e2, const F7Point *at, bool log);	// 0x5111e0
void f7_logPhrase(int id, string *a, string *b, string *c, F7HE e, int f);	// 0x5141b0
void f7_sound(int id, int a, int b);	// 0x4541b0
int f7_stringToInt(const string &s);	// 0x405610
int f7_maxInt(int a, int b);	// 0x9cdb60
int f7_round(float f);	// 0x406360
bool f7_anyNonZero(int *v, unsigned int n);	// 0x9d3f40
int f7_distance(const F7Point &a, const F7Point &b);	// 0x40a3f0
void f7_replace(string &s, string a, string b);	// 0x407e00
int f7_randomIndex(F7Strings &v);	// 0x9da8b0
void f7_clampMax(int *v, int max);	// 0x9cf5a0

#define F7_MESSAGE(id,text,at) do { if (f7_showMessage(id,text,0,0,F7HE(),F7HE(),at,false)) f7_bubble_cec058->bubble(true); f7_log_cec0b4->scrollToEnd(); } while (0)
#define F7_ALERT(sound,text) do { f7_flags_cf1080.set451400(1); if ((sound) != -1 && !(f7_mute_d28fb0 && (sound) != 0 && (sound) != 1)) f7_sound(sound,0,0); F7_MESSAGE(0x324,text,0); f7_log_cec0b4->scrollToEnd(); } while (0)
#define F7_ALERTX(flag,sound,c2,text) do { f7_flags_cf1080.set451400(flag); if ((sound) != -1 && !(f7_mute_d28fb0 && (c2) && (sound) != 1)) f7_sound(sound,0,0); F7_MESSAGE(0x324,text,0); f7_log_cec0b4->scrollToEnd(); } while (0)
#define F7_PHRASE(id,a) do { f7_logPhrase(id,a,0,0,F7HE(),0); } while (0)

class Overmind
{
public:
	int f0;
	int f4;
	char pad8[4];
	float fc;
	int f10;
	int f14;
	vector<int> patrols;
	int f28;
	char pad2c[5];
	bool b31;
	char pad32[2];
	int f34;
	int f38;
	int f3c;
	bool b40;
	char pad41[3];
	int f44;
	bool b48;
	bool b49;
	bool b4a;
	char pad4b;
	int f4c;
	vector<F7Squad *> squads;
	char pad60[0x6c - 0x60];
	int lastDispatchTurn;
	int surgicalTimer;
	int f74;
	bool b78;
	int f7c;
	int f80;
	char pad84[0x90 - 0x84];
	struct F7Cfg *f90;
	int f94;
	vector<F7Point> locs;
	vector<int> turns;
	int fb8;
	int fbc;
	char padc0[0xd0 - 0xc0];
	int fd0;
	F7HE convoy;
	vector<F7HE> escorts;
	char pade8[0xf8 - 0xe8];
	F7Point convoyPos;
	char pad100[4];
	int f104;
	vector<F7Drone *> drones;
	vector<F7Point> f118;
	int f128;
	F7Point f12c;
	char pad134[4];
	int f138;
	int f13c;
	int f140;
	int f144;
	vector<vector<int> > f148;
	vector<vector<F7Point> > f158;
	bool b168;
	vector<int> f16c;
	int f17c;
	int f180;
	F7Point f184;
	int f18c;
	int f190;
	bool b194;
	bool b195;
	bool b196;
	bool b197;
	bool b198;
	void unknown682420(int a, int b);	// 0x682420
	F7HE unknown683b60(int a, int b, bool *c);	// 0x683b60
	void unknown6892c0(int a, int b, int c);	// 0x6892c0
	void unknown68cd80(F7Squad *s);	// 0x68cd80
	void resetSurgicalTimer();	// 0x684c40
	int countParties(int a);	// 0x45edd0
	F7Squad *findParty(int a);	// 0x45ed50
	int spawnSurgicalParty(F7HE e, int a);	// 0x685a10
	int spawnInterceptParty(int a, F7HE e, int b);	// 0x686490
	int spawnHunterParty(F7HE e, int a, int b);	// 0x687520
	int spawnPatrolParty(F7HE e, int a, int b, void *c, int d, int f, int g, int h, int i);	// 0x6896d0
	bool unknown68e1a0();	// 0x68e1a0
	void spawnCargoDispatch68aba0();	// 0x68aba0
	void spawnCargoDispatch68aec0();	// 0x68aec0
	int unknown684250(const F7Point &p, int a);	// 0x684250
	int spawnCouplingParty(const F7Point &p);	// 0x6868e0
	void spawnAntiInfestationCarrier(const F7Point &p, const string &text);	// 0x688e80
	bool filter681a90(vector<F7Point> &points, vector<int> &out);	// 0x681a90
	void loadZWeaponList(vector<int> &v, int a);	// 0x684de0
	void loadZPartList(vector<int> &parts, vector<int> &weapons);	// 0x6854e0
	void unknown690470(const F7Point &a, const F7Point &b, int c, bool *d);	// 0x690470
	int spawnResponseParty(int a, F7HE e, const F7Point &p, F7Point &out);	// 0x68c2f0
	bool findDispatchExit(F7Point &p, int a, int b, int c, const F7Point &q, int *d, int e, int f);	// 0x683500
	void addParty(struct F7Party *p, int a);	// 0x6827d0
	void unknown681550();	// 0x681550
	void unknown681810();	// 0x681810
	void unknown68d980(int a, int b, int c);	// 0x68d980
	void unknown68d6d0(int a);	// 0x68d6d0
	void turnUpdate();
};

extern Overmind f7_overmind_cf6428;

void Overmind::turnUpdate()
{
	if (!drones.empty())
	{
		for (int i = drones.size() - 1; i >= 0; i--)
		{
			int unused = 10;
			if (f7_map_cefc4c->getTurn() >= drones[i]->f8 || drones[i]->e.operator->() == 0)
				f7_deleteObject(drones,i);
			else if (drones[i]->f4 >= 10)
			{
				int e19 = 15;
				F7Point e22(drones[i]->e->getPosition());
				F7Area e0;
				f7_cells_cfd44c.getRect(e22,15,e0);
				F7View e20(f7_cells_cfd44c.getWidth(),f7_cells_cfd44c.getHeight(),e0.p1.x,e0.p1.y,e0.width(),e0.height(),0,1);
				vector<F7Point> e10;
				vector<F7Point> e5;
				e10.push_back(drones[i]->e->getPosition());
				e20(e10[0]) = 1;
				int e31 = 0;
				int g22;
				int e18;
				int e27[6];
				do
				{
					g22 = e10.size();
					for (e18 = 0; e18 < g22; e18++)
					{
						if ((*f7_cells_cfd44c.atPoint(e10[e18]))->getProp().isValid() && (*f7_cells_cfd44c.atPoint(e10[e18]))->getProp()->getType().find("Door",0) != string::npos)
							e5.push_back(e10[e18]);
						vector<F7Point> adj;
						f7_adjacent(e10[e18],adj);
						for (unsigned int j = 0; j < adj.size(); j++)
						{
							if (e20(adj[j]) == 0 && (*f7_cells_cfd44c.atPoint(adj[j]))->field4550b0())
							{
								e10.push_back(adj[j]);
								e20(adj[j]) = 1;
							}
						}
					}
					if (g22 != 0)
						f7_eraseRange(e10,0,g22 - 1);
					e31++;
				} while (!e10.empty() && e31 < 15);
				if (!e5.empty())
				{
					for (unsigned int k = 0; k < e5.size(); k++)
						f7_collectProps((*f7_cells_cfd44c.atPoint(e5[k]))->getProp()->id44ab40(),e5,1,2,0);
					f7_bs_cefc4c->unknown742630(e5,0,0);
					f7_deleteObject(drones,i);
				}
				else
				{
					for (int n = rng.rangeInt(1,3); n != 0; n--)
					{
						vector<F7Point> path;
						if (f7_carto_cfe568.unknown40ca50(e22,5,f7_cost_cefc38,0,path,&f7_cfc224))
						{
							F7Point last(path.back());
							if ((*f7_cells_cfd44c.atPoint(last))->getProp().isValid())
							{
								F7_MESSAGE(0x1ba,(*f7_cells_cfd44c.atPoint(last))->getProp()->getName(),&last);
								(*f7_cells_cfd44c.atPoint(last))->getProp()->unknown45ce10(0,1,0,F7HE());
							}
						}
					}
					drones[i]->f4 = 9;
				}
			}
		}
	}
	if (f7_stringToInt(f7_gameData_d1e860.getEntryText("comMaincReinforced_g")) || f7_stringToInt(f7_gameData_d1e860.getEntryText("comMaincDestroyed_g")))
	{
		f34 = 0;
		return;
	}
	if (f7_location_d1e888->depth == 0xd)
	{
		if (f7_map_cefc4c->unknown4642d0() % f190 == 0)
		{
			unknown682420(0x18,0);
			f18c++;
			int delay = 1200;
			for (int k = 0; k < f18c; k++)
				delay /= 2;
			f190 += f7_maxInt(delay,150);
			F7_ALERT(-1,&string("ALERT: Garrison interior compromised."));
			if (f18c == 1)
				f7_gameData_d1e860.unknown7897a0(3);
			if (f7_vec_cf6898[9] == 0)
				f7_tally_cf6888.unknown6998a0(9,1,0);
		}
	}
	else if (f34 == 0 && f7_map_cefc4c->unknown4642d0() != 0 && f7_map_cefc4c->unknown4642d0() % 20 == 0 && f7_location_d1e888->depth != 0xe)
	{
		int amount = (int)f7_b91a2c;
		switch (f7_diff_cf4718)
		{
		case 0:
			for (int k = f7_map_cefc4c->unknown4642d0() / 400; k > 0; k--)
				amount = (int)(amount * f7_b9077c);
			break;
		case 2:
			amount = (int)(amount * f7_ba6568);
			break;
		}
		amount = -amount;
		amount = f7_round(amount / (f7_c37068 / f7_c370c8));
		if ((amount = -amount) < 0)
			unknown682420(0x25,amount);
	}
	if (f7_gameData_d1e860.unknown46f4b0(1) && f7_location_d1e888->depth != 0x23)
	{
		f7_stats_d2c658.add4729d0(0x216,f0,"",-1);
		f7_stats_d2c658.add4729d0(0x218,f0,"",-1);
		if (f7_cf462c != 9 && !f7_cefb0f)
		{
			if (!b194)
			{
				int *weights = f7_location_d1e888->inRange46ecb0() ? f7_tblA_b92dd8[f7_gameData_d1e860.getDepthIndex()] : f7_tblB_b92880[f7_location_d1e888->depth];
				if (f7_map_cefc4c->getTurn() % 24 == 0 && f7_anyNonZero(weights,9))
				{
					int g31;
					float mult = f7_b91e2c;
					if (f7_stringToInt(f7_gameData_d1e860.getEntryText("extTransferStationDisabled_g")) || f7_stringToInt(f7_gameData_d1e860.getEntryText("hubTransferStationDisabled_g")) || (f7_cf68b4 != 0 && f7_cf68b4->f110 == 8) || f7_cf462c == 4)
						mult /= 2.0;
					for (int k = 0; k < 5; k++)
					{
						g31 = (int)(weights[8] * f7_b92558[f7_location_d1e888->depth][k] / 100 * mult);
						vector<F7HE> *e4 = f7_map_cefc4c->squad463890(4)->members();
						for (unsigned int j = 0; j < e4->size(); j++)
							if ((*e4)[j]->getFaction() == f7_factions_caf1cc[k])
								g31--;
						while (g31 > 0)
						{
							bool g45 = rng.chance(50);
							F7HE g49 = unknown683b60(k,0,&g45);
							if (g49.isNull())
								break;
							if (g49->getFaction() == 1 && !g45 && rng.chance(10))
								f7_bs_cefc4c->unknown6c6450(g49,0);
							g31--;
						}
					}
				}
			}
			if (f7_b91e90[f7_location_d1e888->depth][0] != 0 && f7_map_cefc4c->getTurn() % f7_b91e90[f7_location_d1e888->depth][0] == 0)
			{
				vector<F7HE> *members = f7_map_cefc4c->squad463890(3)->members();
				int spotters = 0;
				for (unsigned int j = 0; j < members->size(); j++)
					if ((*members)[j]->getName() == "N-01 Spotter")
						spotters++;
				while (spotters < f7_b91e8c[f7_location_d1e888->depth][0])
				{
					unknown6892c0(0,0,1);
					F7_ALERT(-1,&string("ALERT: Threat analysis in progress, dispatching additional drones."));
					spotters++;
				}
			}
		}
	}
	for (unsigned int i = 0; i < squads.size(); i++)
		if (squads[i]->f8 >= 0 && f7_map_cefc4c->getTurn() >= squads[i]->f8)
			unknown68cd80(squads[i]);
	if (f7_player_cf45d8.isSlotEmpty(0x42))
	{
		int cnt = 0;
		for (unsigned int i = 0; i < squads.size(); i++)
			if (squads[i]->type == 4)
				cnt++;
		if (cnt >= 3)
			f7_player_cf45d8.unknown77fbc0(0x42);
	}
	if (f7_map_cefc4c->getTurn() % 10 == 0)
	{
		for (unsigned int i = 0; i < squads.size(); i++)
		{
			if (squads[i]->unknown45e7d0() && squads[i]->leader->getAI()->unknown458fb0(f7_map_cefc4c->getPlayer()))
			{
				int g51 = squads[i]->type != 5;
				squads[i]->f10 = f7_map_cefc4c->getTurn() + f7_b91e00[g51][0];
				F7Area *h49 = squads[i]->leader->getAI()->area4b5730();
				f7_cells_cfd44c.getRect(f7_map_cefc4c->getPlayer()->getPosition(),f7_b91df4[0],*h49);
				if (squads[i]->type == 5)
					squads[i]->leader->getAI()->set451930(0);
			}
		}
	}
	if (f7_map_cefc4c->unknown4642f0() % 100 == 0)
	{
		for (unsigned int i = 0; i < squads.size(); i++)
		{
			if (squads[i]->unknown45e7d0() && squads[i]->f14 != -1 && !squads[i]->leader->getAI()->unknown458fb0(f7_map_cefc4c->getPlayer()))
			{
				int e41 = squads[i]->type != 5;
				int h59 = f7_b91df4[e41];
				if (squads[i]->f10 < 0)
					h59 += f7_b91dfc[e41][0][0];
				else if (squads[i]->f10 == 0)
				{
					h59 += f7_b91dfc[e41][0][0];
					h59 += f7_b91e08[e41][0];
				}
				F7Area *e58 = squads[i]->leader->getAI()->area4b5730();
				f7_cells_cfd44c.getRect(f7_map_cefc4c->getPlayer()->getPosition(),h59,*e58);
			}
		}
	}
	for (unsigned int i = 0; i < squads.size(); i++)
	{
		if (squads[i]->unknown45e7d0() && squads[i]->f10 != 0 && f7_map_cefc4c->getTurn() == abs(squads[i]->f10))
		{
			int k24 = squads[i]->type != 5;
			int k27 = squads[i]->f10 <= 0;
			squads[i]->f10 = k27 == 1 ? 0 : -(f7_map_cefc4c->getTurn() + f7_b91e0c[k24][0]);
			if (squads[i]->leader->getAI()->mode4() == 3)
			{
				squads[i]->leader->getAI()->area4b5730()->grow(f7_b91dfc[k24][k27][0]);
				F7Area *area = squads[i]->leader->getAI()->area4b5730();
				area->clip(F7Point(0,0),f7_cells_cfd44c.size9b7930());
				if (squads[i]->type == 5)
					squads[i]->leader->getAI()->set451930(f7_b91e04[k24][k27][0]);
			}
		}
	}
	if (f7_gameData_d1e860.unknown46f4b0(1) && f7_stringToInt(f7_gameData_d1e860.getEntryText("datMetDataMiner_g")) && !f7_stringToInt(f7_gameData_d1e860.getEntryText("datHostileToDataMiner_g")) && !f7_stringToInt(f7_gameData_d1e860.getEntryText("enemiesWithArchitect_g")) && f7_location_d1e888 != f7_hloc_d1ebe0 && f7_location_d1e888 != f7_hloc_d1ebd8 && (f7_location_d1e888->depth != 0x21 || !f7_stringToInt(f7_gameData_d1e860.getEntryText("frgUfdAttacked_g"))) && f34 == 0 && (!f7_d25450 || !f7_d25610))
	{
		for (unsigned int i = 0; i < squads.size(); i++)
		{
			if (squads[i]->f14 > 0 && squads[i]->f14 == f7_map_cefc4c->getTurn())
			{
				bool retask = false;
				if (!squads[i]->test45e820() && rng.chance(50))
				{
					retask = true;
					switch (squads[i]->type)
					{
					case 4:
						if (f7_distance(f7_map_cefc4c->getPlayer()->getPosition(),squads[i]->leader.operator->() && squads[i]->leader->getAI() ? squads[i]->leader->getAI()->area4b5730()->center() : F7Point(9999,9999)) > 15)
							retask = false;
						break;
					case 5:
					case 7:
						if (!squads[i]->fc)
							retask = false;
						break;
					}
					if (!f7_map_cefc4c->getPlayer()->unknown5c98c0(0,0x42,0))
						retask = false;
					if (retask)
					{
						squads[i]->pickArea673780();
						string text = "ALERT: Higher priority target reported, redirecting " + f7_squadNames_d2f350[squads[i]->type] + ".";
						F7_ALERT(-1,&text);
						f7_stats_d2c658.add4729d0(0x23a,1,"",-1);
						F7_PHRASE(0x162,&f7_squadNames_d2f350[squads[i]->type]);
						if (f7_voice_cefb48 != 0)
							f7_voice_cefb48->say(0x2f,0,"");
						if (f7_d25450 && rng.chance(15))
						{
							f7_d25610 = true;
							F7_MESSAGE(0x2b9,&string("X0-1V1: \"That meddlesome character is spoiling all the fun. Not anymore!\""),&f7_map_cefc4c->getPlayer()->getPosition());
							F7_PHRASE(0xc3,0);
						}
					}
				}
				if (!retask)
					squads[i]->f14 = 0;
			}
		}
	}
	if (f34 == 0 && f4c == 0)
	{
		for (unsigned int i = 0; i < squads.size(); i++)
		{
			if (squads[i]->f18 != 0 && squads[i]->f18 == f7_map_cefc4c->getTurn())
			{
				squads[i]->f18 = 0;
				F7Strings k30;
				k30.push("Squad [D] mysteriously retasked... again!");
				k30.push("[T] squad [D]! Get back on the job!");
				k30.push("Found errant [T] squad. Retasking [D].");
				k30.push("Just where do you think you're going, squad [D]?");
				k30.push("[T] squad [D] is back on target with renewed vigor.");
				k30.push("[T] squad [D], please report to the right place at the right time.");
				int e7 = f7_randomIndex(k30);
				f7_replace(k30.at(e7),"[D]",squads[i]->name1c);
				f7_replace(k30.at(e7),"[T]",f7_squadNames_d2f350[squads[i]->type]);
				string g0 = "ALERT: " + k30.at(e7);
				F7_ALERT(-1,&g0);
				squads[i]->name1c.clear();
			}
		}
	}
	if (f7_surgicalMaps_b90180[f7_location_d1e888->depth][0] && f7_surgicalIntervals_b93790[f7_gameData_d1e860.getDepthIndex()][0] && !b195 && f7_map_cefc4c->getTurn() >= surgicalTimer)
	{
		resetSurgicalTimer();
		if (f7_map_cefc4c->getTurn() < lastDispatchTurn + 25 || countParties(5) >= 10)
			;
		else
		{
			int before = squads.size();
			bool sent = spawnSurgicalParty(f7_map_cefc4c->getPlayer(),0);
			if (sent)
			{
				lastDispatchTurn = f7_map_cefc4c->getTurn();
				string k5("Programmers");
				if (before == squads.size())
				{
					if (!f7_map_cefc4c->squad463890(2)->members()->empty() && f7_map_cefc4c->squad463890(2)->members()->back()->getFaction() == 0x1b)
						k5 = "Q-Series";
				}
				else if (!squads.empty() && squads.back()->leader->getFaction() == 0x1b)
					k5 = "Q-Series";
				string g14;
				if (!squads.back()->leader->getAI()->unknown458fb0(f7_map_cefc4c->getPlayer()))
				{
					g14 = "ALERT: Potential suspicious activity detected, " + k5 + " report to ";
					if (f7_cf462c == 0xb)
					{
						f7_stats_d2c658.add4729d0(0x45c,1,"",-1);
						if (f7_stats_d2c658.get472c90(0x45c) / 150 <= 6)
							f7_stats_d2c658.add472b90(0x13,150);
					}
				}
				else
					g14 = "ALERT: Potential suspicious activity detected, " + k5 + " report to ";
				g14 += f7_zoneNames_cfaca0[f7_location_d1e888->depth];
				g14 += " Zone ";
				g14 += f7_gameData_d1e860.generateID();
				g14 += ".";
				F7_ALERT(0x128,&g14);
				if (k5[0] == 'P' && f7_voice_cefb48 != 0)
					f7_voice_cefb48->say(0x2c,0,"");
				if (!f7_d257d7 && f7_location_d1e888->depth == 3)
					f74 = f7_map_cefc4c->getTurn() + 10;
			}
		}
		if (f74 != 0 && f74 == f7_map_cefc4c->getTurn())
		{
			F7Squad *squad = findParty(5);
			if (squad != 0 && squad->leader->getAI()->path4549b0()->size() >= 20)
			{
				F7HE e = f7_bs_cefc4c->unknown6c5dc0("Thug_5",f7_map_cefc4c->getPlayer()->getPosition(),8,false,0x22,0xe,false);
				if (e.isValid())
				{
					e->getAI()->setFollowEntity(f7_map_cefc4c->getPlayer(),0);
					f7_bs_cefc4c->unknown6c65a0(e,"Warn_Surgical_Talk",false);
					f7_d257d7 = true;
				}
			}
			f74 = 0;
		}
	}
	if (f7_b90182[f7_location_d1e888->depth][0] && (f7_stringToInt(f7_gameData_d1e860.getEntryText("enemiesWithArchitect_g")) || f7_stringToInt(f7_gameData_d1e860.getEntryText("secScannedCogmind_g"))) && !b198)
	{
		int interval = f7_b938b8[f7_gameData_d1e860.getDepthIndex()][0];
		if (f7_b938bc[f7_gameData_d1e860.getDepthIndex()][0] != 0 && f7_map_cefc4c->f324 != 0 && ((f7_map_cefc4c->f324 % interval == 0 && f80 != f7_cf47fc && rng.chance(f7_b938bc[f7_gameData_d1e860.getDepthIndex()][0])) || f7_cf47fc >= f80 + interval * (100.0 / f7_b938bc[f7_gameData_d1e860.getDepthIndex()][0])))
		{
			f80 = f7_cf47fc;
			if (f7_map_cefc4c->getTurn() < lastDispatchTurn + 25 || countParties(9) >= 5)
				;
			else
			{
				bool sent = spawnInterceptParty(0,f7_map_cefc4c->getPlayer(),0);
				if (sent)
				{
					lastDispatchTurn = f7_map_cefc4c->getTurn();
					if (!f7_map_cefc4c->unknown4658e0())
					{
						bool scanned = f7_stringToInt(f7_gameData_d1e860.getEntryText("secScannedCogmind_g"));
						string text;
						if (!squads.back()->leader->getAI()->unknown458fb0(f7_map_cefc4c->getPlayer()))
						{
							text = scanned ? "ALERT: Potential LRC-V3 signature in area, intercept squad dispatched." : "ALERT: Reliable intel has suggested a potential LRC-V3 signature, intercept squad en route.";
							if (f7_cf462c == 0xb)
							{
								f7_stats_d2c658.add4729d0(0x45c,1,"",-1);
								if (f7_stats_d2c658.get472c90(0x45c) / 150 <= 6)
									f7_stats_d2c658.add472b90(0x13,150);
							}
						}
						else
							text = scanned ? "ALERT: LRC-V3 signature pinpointed, intercept squad dispatched." : "ALERT: Reliable intel has pinpointed LRC-V3, intercept squad en route.";
						F7_ALERT(0x128,&text);
						F7_PHRASE(0x7c,0);
					}
					f7_stats_d2c658.add4729d0(0x231,1,"",-1);
					f7_stats_d2c658.add4729d0(0x237,1,"",-1);
					if (f7_stats_d2c658.get472c90(0x237) == 1)
						f7_stats_d2c658.add472b90(0x47,-999999);
					switch (f7_stats_d2c658.get472c70(0x237))
					{
					case 1:
						f7_player_cf45d8.unknown77fbc0(0x19c);
						break;
					case 5:
						f7_player_cf45d8.unknown77fbc0(0xa4);
						break;
					}
				}
			}
		}
	}
	if (f7_b90181[f7_location_d1e888->depth][0] && !b196)
	{
		if (f7_b93f18[f7_gameData_d1e860.getDepthIndex()][0] != 0 && f7_map_cefc4c->f320 % f7_b93f18[f7_gameData_d1e860.getDepthIndex()][0] == 0 && f7_map_cefc4c->getTurn() >= lastDispatchTurn + 25)
		{
			bool hot = f4 >= f0 * f7_b91b70;
			if (f7_cf6428 >= (hot ? 200 : 400))
			{
				if (hot)
				{
					lastDispatchTurn = f7_map_cefc4c->getTurn();
					if (f14 == 0)
						f14 = 2;
					else
						f14++;
					f7_clampMax(&f14,3);
					int level = f14;
					if (!f7_location_d1e888->inRange46ecb0())
						level--;
					string text("ALERT: Heightened foreign activity detected, ");
					text += level > 1 ? "multiple search patrols dispatched." : "dispatching search patrol.";
					F7_ALERT(0x127,&text);
					f7_stats_d2c658.add4729d0(0x238,1,"",-1);
					F7_PHRASE(0x77,0);
					if (f7_voice_cefb48 != 0)
						f7_voice_cefb48->say(0x2d,0,"");
					f7_player_cf45d8.unknown77fbc0(0x46);
					if (f7_stats_d2c658.get472c70(0x238) == 4)
						f7_player_cf45d8.unknown77fbc0(0xa1);
					int when = f7_map_cefc4c->getTurn();
					for (int k = 0; k < level; k++)
					{
						when += f7_range_d223cc.randomInRange();
						patrols.push_back(when);
					}
					unknown682420(0x26,0);
					f7_tally_cf6888.unknown6998a0(5,1,0);
				}
				else if (countParties(7) < 20)
				{
					lastDispatchTurn = f7_map_cefc4c->getTurn();
					int k50 = f7_cf6428 / f7_b93f1c[f7_gameData_d1e860.getDepthIndex()][0];
					int k51 = 0;
					while (rng.chance(k50) || (f7_d1ebfc && k51 < 2))
					{
						if (!spawnHunterParty(f7_map_cefc4c->getPlayer(),0,0))
							break;
						k50 /= 2;
						k51++;
					}
					if (k51 != 0)
					{
						string text;
						if (!squads.back()->leader->getAI()->unknown458fb0(f7_map_cefc4c->getPlayer()))
						{
							text = "ALERT: Unidentified disturbance in Zone ";
							if (f7_cf462c == 0xb)
							{
								f7_stats_d2c658.add4729d0(0x45c,1,"",-1);
								if (f7_stats_d2c658.get472c90(0x45c) / 150 <= 6)
									f7_stats_d2c658.add472b90(0x13,150);
							}
						}
						else
							text = "ALERT: Significant disruption in Zone ";
						text += f7_gameData_d1e860.generateID();
						text += ", ";
						text += k51 > 1 ? "multiple assault carriers dispatched." : "assault force dispatched.";
						F7_ALERT(0x129,&text);
						if (!b78)
							F7_PHRASE(0x78,0);
						if (f7_voice_cefb48 != 0)
							f7_voice_cefb48->say(0x2e,0,"");
						b78 = true;
						f7_player_cf45d8.unknown77fbc0(0x43);
						if (!f7_d257d8 && f7_location_d1e888->depth == 3)
							f7c = f7_map_cefc4c->getTurn() + 10;
						f7_tally_cf6888.unknown6998a0(6,1,0);
						if (f7_d25450 && k51 >= 2)
							f7_xom_d25450.unknown69e700(0x2d,0,0);
					}
				}
			}
		}
		if (!patrols.empty())
		{
			for (unsigned int k = 0; k < patrols.size(); k++)
			{
				if (patrols[k] <= f7_map_cefc4c->getTurn())
				{
					spawnPatrolParty(F7HE(),0,0,0,0,0,0,7,0);
					f7_eraseAt(patrols,k);
				}
			}
		}
		if (f7c != 0 && f7c == f7_map_cefc4c->getTurn())
		{
			F7Squad *squad = findParty(7);
			if (squad != 0 && squad->leader->getAI()->path4549b0()->size() >= 20)
			{
				F7Access *g25 = 0;
				unsigned int k54 = -1;
				vector<F7Access *> *g42 = f7_map_cefc4c->accesses462e10();
				for (unsigned int k = 0; k < g42->size(); k++)
				{
					if ((*g42)[k]->loc->depth == 0x10 || (*g42)[k]->loc->depth == 0x11)
					{
						vector<F7Point> path;
						if (f7_carto_cfe568.findPath(f7_map_cefc4c->getPlayer()->getPosition(),(*g42)[k]->pos,f7_cost_cefc30,0,path))
						{
							if (g25 == 0 || path.size() < k54)
							{
								k54 = path.size();
								g25 = (*g42)[k];
							}
						}
					}
				}
				if (g25 != 0)
				{
					F7HE e = f7_bs_cefc4c->unknown6c5dc0("Guerilla_7",f7_map_cefc4c->getPlayer()->getPosition(),8,false,0x19,0xe,false);
					if (e.isValid())
					{
						e->getAI()->unknown459540(g25->pos);
						f7_bs_cefc4c->unknown6c65a0(e,"Warn_Assault_Talk",false);
						f7_d257d8 = true;
					}
				}
			}
			f7c = 0;
		}
		if (f7_cf462c == 4 && f7_map_cefc4c->unknown4642d0() >= 200 && f7_map_cefc4c->getTurn() % f7_ba6644[f7_diff_cf4718] == 0 && rng.chance(50) && f7_map_cefc4c->unknown464000() >= f7_map_cefc4c->unknown717d60() / 2)
		{
			F7_ALERT(-1,&string("ALERT: Dispatching additional forces to engage threats."));
			spawnHunterParty(F7HE(),0,0);
		}
	}
	if (f7_b90183[f7_location_d1e888->depth][0])
	{
		bool reset = false;
		if (convoy.isValid())
		{
			if (convoy.operator->() == 0)
				reset = true;
			else
			{
				convoyPos = convoy->getPosition();
				if (convoy->getGroup()->kind9b4350() != 3 || convoy->unknown5c8db0() < 5)
					reset = true;
			}
		}
		if (!reset)
		{
			for (unsigned int k = 0; k < escorts.size(); k++)
			{
				if (escorts[k].operator->() == 0 || escorts[k]->getGroup()->kind9b4350() != 3)
				{
					reset = true;
					break;
				}
			}
		}
		if (reset)
		{
			fb8 = 0;
			f7_stats_d2c658.add4729d0(0x23e,1,"",-1);
			if (unknown68e1a0())
			{
				F7_ALERT(-1,&string("ALERT: Cargo convoy interrupted, initiating access lockdown."));
				if (f7_map_cefc4c->getPlayer()->unknown5d2380(0x16).isValid() || f7_map_cefc4c->getPlayer()->unknown5d2380(0x17).isValid() || !f7_map_cefc4c->unknown463c00(0xb)->empty())
				{
					vector<F7HM> *markers = &f7_map_cefc4c->lists463ec0()[0x10];
					markers->push_back(f7_factory_cefaa8->createC());
					markers->back()->unknown6c20b0(0x10,convoyPos,-1);
				}
				else if (f7_d25450 && f7_xom_d25450.unknown69e9b0(convoyPos) && f7_stats_d2c658.get472c90(0x252) == 0 && f7_map_cefc4c->getPlayer()->unknown5d15a0(0) >= 80)
					f7_xom_d25450.unknown69e700(0x27,f7_map_cefc4c->getPlayer()->unknown5c98c0(0,0x42,0) ? 1 : 0,0);
			}
			f7_tally_cf6888.unknown6998a0(7,1,0);
			F7_PHRASE(0x70,0);
			f7_player_cf45d8.unknown77fbc0(0x47);
			if (f7_stats_d2c658.get472c70(0x23e) == 4)
				f7_player_cf45d8.unknown77fbc0(0x148);
			convoy.reset9b7270();
			escorts.clear();
		}
		if (fb8 != 0 && f7_map_cefc4c->getTurn() == fb8 && !b194 && convoy.isNull())
		{
			spawnCargoDispatch68aba0();
			if (fbc == f7_b939ac[f7_gameData_d1e860.getDepthIndex()][0])
				fb8 = 0;
			else
				fb8 = f7_map_cefc4c->getTurn() + rng.rangeInt(f7_b939a0[f7_gameData_d1e860.getDepthIndex()][0],f7_b939a4[f7_gameData_d1e860.getDepthIndex()][0] + fbc * f7_b939a8[f7_gameData_d1e860.getDepthIndex()][0]);
		}
		if (fd0 != 0 && f7_map_cefc4c->getTurn() == fd0 && !b194)
			spawnCargoDispatch68aec0();
	}
	if (f7_b90184[f7_location_d1e888->depth][0] && (!b194 || f7_location_d1e888->depth == 0x22) && fc >= f7_b91a3c && f7_map_cefc4c->getTurn() >= f10 && unknown684250(f7_map_cefc4c->getPlayer()->getPosition(),1))
	{
		string text = "ALERT: Active scanning activity reported from Zone " + f7_gameData_d1e860.generateID() + ", dispatching " + f7_cf2648 + " squad.";
		F7_ALERT(0x127,&text);
		unknown682420(0x1d,0);
		fc = 0;
		f10 = f7_map_cefc4c->getTurn() + 100;
		f7_stats_d2c658.add4729d0(0x23d,1,"",-1);
		if (f7_stats_d2c658.get472c70(0x23d) == 10)
			f7_player_cf45d8.unknown77fbc0(0xa3);
	}
	else if (f7_location_d1e888->depth == 0xd && f10 != -1 && fc >= f7_b91a3c)
	{
		string text("ALERT: Active scanning activity detected within garrison interior, activating patrols.");
		F7_ALERT(0x127,&text);
		f7_bs_cefc4c->unknown7456a0();
		vector<F7HE> *members = f7_map_cefc4c->squad463890(3)->members();
		for (unsigned int k = 0; k < members->size(); k++)
		{
			if ((*members)[k]->getAI()->mode4() == 1)
			{
				if ((*members)[k]->getTarget45a760() == 2)
					(*members)[k]->unknown5fdab0();
				(*members)[k]->getAI()->unknown459470(f7_cells_cfd44c.getArea9b4400());
			}
		}
		fc = 0;
		f10 = -1;
		f7_stats_d2c658.add4729d0(0x23d,1,"",-1);
	}
	if (f7_b90185[f7_location_d1e888->depth][0] && !b194 && f7_map_cefc4c->getTurn() >= f104)
	{
		if (f7_map_cefc4c->getTurn() == f104 && f7_thresholdIndex(f0) <= 2 && f7_map_cefc4c->squad463890(1)->members()->size() + f7_map_cefc4c->squad463890(2)->members()->size() >= 18)
		{
			F7Point center(f7_map_cefc4c->getPlayer()->getPosition());
			for (int k = 1; k <= 2; k++)
			{
				vector<F7HE> *members = f7_map_cefc4c->squad463890(k)->members();
				for (unsigned int j = 0; j < members->size(); j++)
					center += (*members)[j]->getPosition();
				center.x /= members->size() + 1;
				center.y /= members->size() + 1;
			}
			vector<F7HE> near;
			for (int k = 1; k <= 2; k++)
			{
				vector<F7HE> *members = f7_map_cefc4c->squad463890(k)->members();
				for (unsigned int j = 0; j < members->size(); j++)
				{
					if (f7_distance((*members)[j]->getPosition(),center) <= 15)
						near.push_back((*members)[j]);
				}
			}
			if (near.size() >= 18)
			{
				spawnAntiInfestationCarrier(f7_randomRecord(near)->getPosition(),string("ALERT: Concentration of foreign units detected, dispatching Demolisher response squad."));
				if (f7_d25450)
					f7_xom_d25450.unknown69e700(0x57,0,0);
			}
		}
		f104 = f7_map_cefc4c->getTurn() + f7_range_cf39ec.randomInRange();
	}
	if (f7_b9220c[f7_location_d1e888->depth][0] != 0 && f4c == 0 && f7_map_cefc4c->unknown4642d0() >= f28 && f7_map_cefc4c->unknown4642d0() <= f7_b92218[f7_location_d1e888->depth][0])
	{
		int period = f7_b92208[f7_location_d1e888->depth][0];
		if (f7_cf462c == 9)
			period /= 2;
		if (f7_hloc_d1ebd8.isValid())
		{
			switch (f7_location_d1e888->depth)
			{
			case 5:
			case 0x1e:
			case 0x1f:
				period /= 2;
				break;
			}
		}
		if (f7_map_cefc4c->unknown4642d0() % f7_b92208[f7_location_d1e888->depth][0] == 0 && rng.chance((int)(f7_b9220c[f7_location_d1e888->depth][0] * (f7_cf462c == 9 ? f7_ba7ebc : 1.0f))))
		{
			if (spawnPatrolParty(F7HE(),0,0,0,0,0,0,10,0) && !squads.empty())
			{
				squads.back()->f8 = f7_map_cefc4c->getTurn() + f7_b92210[f7_location_d1e888->depth][0];
				f28 = f7_map_cefc4c->unknown4642d0() + f7_b92214[f7_location_d1e888->depth][0];
			}
		}
	}
	if (!(*f7_map_cefc4c->lists459070())[5].empty() && f7_b9394c[f7_gameData_d1e860.getDepthIndex()][0] != 0 && f7_map_cefc4c->unknown4642d0() % f7_b93948[f7_gameData_d1e860.getDepthIndex()][0] == 0 && rng.chance(f7_b9394c[f7_gameData_d1e860.getDepthIndex()][0]) && f4c == 0 && !b195)
	{
		F7Point g44 = f7_randomPoint((*f7_map_cefc4c->lists459070())[5]);
		unsigned int k57 = squads.size();
		bool g57 = spawnCouplingParty(g44);
		if (g57)
		{
			F7HE e;
			if (k57 == squads.size())
			{
				if (!f7_map_cefc4c->squad463890(2)->members()->empty())
					e = f7_map_cefc4c->squad463890(2)->members()->back();
			}
			else if (!squads.empty())
				e = squads.back()->leader;
			if (e.isValid())
			{
				vector<F7Point *> *list = f7_map_cefc4c->unknown464940();
				for (unsigned int k = 0; k < list->size(); k++)
				{
					if (*(*list)[k] == g44)
						f7_deleteObjectAndStep(*list,k);
				}
			}
		}
	}
	if (!turns.empty())
	{
		for (unsigned int k = 0; k < turns.size(); k++)
		{
			if (f7_map_cefc4c->getTurn() == turns[k])
			{
				if (!b195 && (*f7_cells_cfd44c.atPoint(locs[k]))->getProp().isValid() && (*f7_cells_cfd44c.atPoint(locs[k]))->getProp()->unknown457b10() == 0 && (*f7_cells_cfd44c.atPoint(locs[k]))->getProp()->def9b8f00()->kind == 5)
				{
					bool found = false;
					for (unsigned int j = 0; j < squads.size(); j++)
					{
						if (squads[j]->type == 10 && !squads[j]->leader->getAI()->path458ef0()->empty() && squads[j]->leader->getAI()->path458ef0()->front() == locs[k])
						{
							found = true;
							break;
						}
					}
					if (!found)
					{
						bool ok = spawnCouplingParty(locs[k]);
						if (ok)
						{
							string text = "ALERT: Unscheduled coupler replacement inbound for " + (*f7_cells_cfd44c.atPoint(locs[k]))->getProp()->getType() + ".";
							F7_ALERT(-1,&text);
						}
					}
				}
				f7_eraseAtP(locs,k);
				f7_eraseAt(turns,k);
			}
		}
	}
	vector<F7HE> *m14 = f7_map_cefc4c->squad463890(1)->members();
	F7HE m27;
	bool m31 = false;
	if (f7_cf4700 != 0 && f7_containsRecord(f7_records_d25de0[*f7_cf4700]->f148,0xc))
	{
		m27 = f7_map_cefc4c->getPlayer();
		m31 = true;
	}
	else
	{
		vector<F7HE> *members = f7_map_cefc4c->squad463890(1)->members();
		for (unsigned int k = 0; k < members->size(); k++)
		{
			if ((*members)[k]->getFaction() == 9 && (*members)[k]->getTarget45a760() == 0)
			{
				m27 = (*members)[k];
				if (f7_distance(f7_map_cefc4c->getPlayer()->getPosition(),(*members)[k]->unknown45a4c0()) <= 20)
				{
					m31 = true;
					break;
				}
			}
		}
	}
	if (m27.isValid())
	{
		int level = f7_thresholdIndex(f0);
		if (f94 == -1)
			f94 = level;
		else if (m31 && f94 != level)
		{
			if (m27->isPlayer())
			{
				do { if (f7_showMessage((level <= f94) + 0x317,&f7_intToString(level),0,0,m27,F7HE(),0,false)) f7_bubble_cec058->bubble(true); f7_log_cec0b4->scrollToEnd(); } while (0);
			}
			else
			{
				do { if (f7_showMessage((level <= f94) + 0x1db,&f7_intToString(level),0,0,m27,F7HE(),0,false)) f7_bubble_cec058->bubble(true); f7_log_cec0b4->scrollToEnd(); } while (0);
			}
			f94 = level;
		}
	}
	else
		f94 = -1;
	if (!b194)
	{
		if (f7_b94030[f7_location_d1e888->depth][0] != 0 && f7_map_cefc4c->getTurn() % f7_b94030[f7_location_d1e888->depth][0] == 0 && rng.chance(f7_b94034[f7_location_d1e888->depth][0]))
		{
			vector<F7Point> points((*f7_map_cefc4c->lists459070())[1]);
			vector<int> slots;
			if (filter681a90(points,slots))
			{
				OpR5h_WL<int> m34;
				m34.add(0x10,0x32);
				m34.add(0x11,5);
				m34.add(0x12,5);
				m34.add(0x15,0x14);
				m34.add(0x18,10);
				m34.add(0x19,10);
				int h16 = m34.pick();
				F7Unit *h2 = f7_bs_cefc4c->selectRobotOfClass(1,h16,0,1);
				if (h2 != 0)
				{
					F7HProp m38 = (*f7_cells_cfd44c.atPoint(f7_randomPoint(points)))->getProp();
					F7Machine *m51 = m38->machine45cb30();
					int q12 = h2->getValue459840(m51->f8);
					m51->process = new F7MachineProcess(m38,0x43,q12,0,h2,false,false,F7HE(),3,0,false,false);
					m51->f80 = f7_caf164;
					m51->f84 = f7_caf164;
					m51->f88 = h2->f0;
					m51->f8c = m51->f88;
				}
			}
		}
		if (f7_b94038[f7_location_d1e888->depth][0] != 0 && f7_map_cefc4c->getTurn() % f7_b94038[f7_location_d1e888->depth][0] == 0 && rng.chance(f7_b9403c[f7_location_d1e888->depth][0]))
		{
			vector<F7Point> points((*f7_map_cefc4c->lists459070())[1]);
			vector<int> slots;
			if (filter681a90(points,slots))
			{
				F7ItemDef *item;
				for (int k = 0; k < 50; k++)
				{
					item = f7_bs_cefc4c->selectRandomItemOfRating(f7_location_d1e888->getDepthIndex() + rng.rangeInt(0,2),0,0,0x1f,0x12,0x2a,0);
					if (item != 0 && item->f44 >= 6)
						break;
				}
				if (item != 0)
				{
					F7HProp q3 = (*f7_cells_cfd44c.atPoint(f7_randomPoint(points)))->getProp();
					F7Machine *q42 = q3->machine45cb30();
					int q48 = item->getValue457430(q3->machine45cb30()->f8);
					q42->process = new F7MachineProcess(q3,0x43,q48,item,0,false,false,F7HE(),3,0,false,false);
					q42->f80 = item->f0;
					q42->f84 = q42->f80;
					q42->f88 = f7_caf160;
					q42->f8c = f7_caf160;
				}
			}
		}
	}
	if (f7_b90181[f7_location_d1e888->depth][0] && !f7_map_cefc4c->squad463890(2)->members()->empty() && (f7_map_cefc4c->unknown4642d0() - f7_map_cefc4c->unknown463d20()) % 150 == 0 && f4c == 0)
	{
		vector<F7HE> *members = f7_map_cefc4c->squad463890(2)->members();
		int count = 0;
		for (unsigned int k = 0; k < members->size(); k++)
		{
			if ((*members)[k]->getFaction() == 0x3c)
				count++;
		}
		if (count != 0 && rng.chance(count * 5))
			spawnAntiInfestationCarrier(f7_map_cefc4c->getPlayer()->getPosition(),string("ALERT: Infestation gathering in Complex 0b10, dispatching Demolisher response squad."));
	}
	if (f7_gameData_d1e860.unknown46f4b0(1) && f7_location_d1e888->depth != 0x23)
	{
		if (f12c.x != -1)
		{
			F7Rec *unit = f7_bs_cefc4c->selectRobotOfClass(1,0x16,0,1);
			if (unit == 0)
			{
			}
			else
			{
				vector<F7Rec *> units(2,unit);
				F7HE prev;
				for (unsigned int k = 0; k < units.size(); k++)
				{
					F7HE e = f7_map_cefc4c->placeEntity(units[k],f12c,3,0,0x22,0xe,0);
					if (e.isNull())
						break;
					if (prev.isValid())
						e->getAI()->setFollowEntity(prev,0);
					else
						prev = e;
				}
			}
			f12c = -1;
		}
		if (f128 >= 4)
		{
			f128 = 2;
			vector<F7Access *> *h22 = f7_map_cefc4c->accesses462e10();
			vector<F7Access *> q49;
			vector<F7Access *> e29;
			for (unsigned int k = 0; k < h22->size(); k++)
			{
				if (!(*h22)[k]->fc)
				{
					q49.push_back((*h22)[k]);
					if ((*f7_cells_cfd44c.atPoint((*h22)[k]->pos))->getEntity().isValid() && (*f7_cells_cfd44c.atPoint((*h22)[k]->pos))->getEntity()->unknown5cb680(f7_map_cefc4c->squad463890(3)))
						e29.push_back((*h22)[k]);
				}
			}
			F7Point h28(-1);
			if (!e29.empty())
				h28 = f7_randomRec(e29)->pos;
			else if (!q49.empty())
				h28 = f7_randomRec(q49)->pos;
			if (h28.x != -1)
			{
				bool late = f7_gameData_d1e860.getDepthIndex() >= 9;
				F7Def *def;
				if (f7_findByName(f7_defs_cfd2cc,late ? "WAR_Infiltration_Entrance" : "WAR_Staging_Area_Clear",def))
				{
					if (f7_map_cefc4c->isVisible(h28))
						f7_message(0x320,F7HE(),string(late ? "A bomb flies into the area." : "A missile flies into the area."),0);
					f7_map_cefc4c->addRecord(f7_factory_cefaa8->createA(new F7Explosion(F7HE(),def,h28,F7HE(),F7Point(-1),F7Point(-1))));
				}
				f12c = h28;
			}
			unknown682420(0x1e,0);
		}
	}
	if (f7_d1dd38 && f7_d1dd3c == f7_map_cefc4c->unknown4642d0() && f7_gameData_d1e860.unknown46f4b0(1) && f7_location_d1e888->depth != 0xc && f7_location_d1e888->depth != 0xd && f7_location_d1e888->depth != 0xe && f7_location_d1e888->depth != 0x1a && f7_location_d1e888->depth != 1 && (f34 == 0 || f7_map_cefc4c->getTurn() - f34 < (b40 ? 1 : 50)))
	{
		F7_ALERT(-1,&string("ALERT: Terminal network compromised, cutting hard line."));
		F7_PHRASE(0x173,0);
		vector<F7Point> *points = &(*f7_map_cefc4c->lists459070())[0];
		for (unsigned int k = 0; k < points->size(); k++)
			(*f7_cells_cfd44c.atPoint((*points)[k]))->getProp()->machine45cb30()->f28 = -1;
	}
	if (f4c == 0)
	{
		switch (f7_location_d1e888->depth)
		{
		case 0xe:
			if (f138 > 0)
			{
				if (f7_map_cefc4c->getTurn() == f138)
				{
					string text("ALERT: ");
					switch (f13c)
					{
					case 0:
						text = "Hostiles detected in DSF";
						break;
					case 1:
						text = "Hostiles detected in DSF";
						break;
					case 2:
						text = "DSF alarm triggered";
						break;
					case 3:
						{
							text = "DSF_0";
							string digits("0123456789");
							text += f7_randomChar(digits);
							text += f7_randomChar(digits);
							text += " integrity compromised";
						}
						break;
					}
					text += ", routing additional patrols.";
					F7_ALERT(-1,&text);
					F7_PHRASE(0x19f,0);
					f140 = f7_map_cefc4c->getTurn() + f7_range_cf0468.randomInRange();
				}
				if (f7_map_cefc4c->getTurn() == f140)
				{
					if (spawnPatrolParty(F7HE(),0,0,0,0,0,0,10,0))
					{
						f144++;
						if (f144 < 3)
							f140 = f7_map_cefc4c->getTurn() + f7_range_d1de88.randomInRange();
					}
					else
						f140 += 5;
				}
			}
			if (!f148.empty() && rng.chance(1))
			{
				F7HE e = f7_map_cefc4c->placeEntity(f7_bs_cefc4c->selectRobotOfClass(1,4,0,0),(*f7_map_cefc4c->accesses462e10())[0]->pos,4,0,0x15,0xe,0);
				if (e.isValid())
				{
					for (unsigned int k = 0; k < f148.back().size(); k++)
					{
						f7_map_cefc4c->unknown6c51d0(f7_defs_d2d1c4[f148.back()[k]],e,0,1);
						e->getAI()->path458ef0()->push_back(f158.back()[k]);
					}
				}
				f148.pop_back();
				f158.pop_back();
			}
			break;
		case 0xd:
			if (!f148.empty() && rng.chance(f7_c36f84))
			{
				vector<F7Access *> *qq42 = f7_map_cefc4c->accesses462e10();
				F7Point h8(-1);
				unsigned int qq46 = 0;
				for (unsigned int k = 0; k < qq42->size(); k++)
				{
					vector<F7Point> path;
					if (f7_carto_cfe568.findPath((*qq42)[k]->pos,f158.back().back(),f7_cost_cefc30,0,path))
					{
						if (path.size() > qq46)
						{
							qq46 = path.size();
							h8.set40a030((*qq42)[k]->pos);
						}
					}
				}
				if (h8.x == -1)
				{
				}
				else
				{
					F7HE e = f7_bs_cefc4c->unknown6c5dc0("A-27 Freighter",h8,3,0,0x15,0xe,0);
					if (e.isValid())
					{
						F7_ALERT(-1,&string("ALERT: Cache delivery inbound."));
						for (unsigned int k = 0; k < f148.back().size(); k++)
						{
							f7_map_cefc4c->unknown6c51d0(f7_defs_d2d1c4[f148.back()[k]],e,0,0);
							e->getAI()->path458ef0()->push_back(f158.back()[k]);
						}
					}
					f148.pop_back();
					f158.pop_back();
				}
			}
			if (f180 != 0 && f7_map_cefc4c->getTurn() >= f180)
			{
				vector<F7Point> adj;
				f7_adjacent(f184,adj);
				F7HProp assembler;
				for (unsigned int k = 0; k < adj.size(); k++)
				{
					if ((*f7_cells_cfd44c.atPoint(adj[k]))->getProp().isValid() && (*f7_cells_cfd44c.atPoint(adj[k]))->getProp()->unknown457b10() == 0 && (*f7_cells_cfd44c.atPoint(adj[k]))->getProp()->getType() == "GAR_QS_Assembler")
					{
						assembler = (*f7_cells_cfd44c.atPoint(adj[k]))->getProp();
						break;
					}
				}
				if (assembler.isNull())
					(*f7_cells_cfd44c.atPoint(f184))->getProp()->unknown45ce10(0,0,1,F7HE());
				else
				{
					F7Rec *unit = f7_bs_cefc4c->selectRobotOfClass(1,0x1b,0,1);
					if (unit != 0)
					{
						F7Cfg *saved = f90;
						f90 = new F7Cfg;
						f90->randomize45e940();
						F7Access *access = (*f7_map_cefc4c->accesses462e10())[rng.rangeInt(0,f7_minInt(3,f7_map_cefc4c->accesses462e10()->size()) - 1)];
						for (int k = 0; k < 2; k++)
						{
							F7Point p;
							if (f7_map_cefc4c->findPlaceableNear(f184,p,unit->f9c))
							{
								F7HE e = f7_map_cefc4c->placeEntity(unit,p,3,0,0x19,0xe,0);
								if (e.isValid())
								{
									e->getAI()->unknown459540(access->pos);
									vector<int> weapons;
									loadZWeaponList(weapons,f7_gameData_d1e860.getDepthIndex());
									vector<int> parts;
									loadZPartList(parts,weapons);
									for (unsigned int j = 0; j < weapons.size(); j++)
										e->unknown5de480(f7_defs_d2d1c4[weapons[j]]);
									for (unsigned int j = 0; j < parts.size(); j++)
										e->unknown5de480(f7_defs_d2d1c4[parts[j]]);
									e->unknown5deb40(10000);
									e->unknown5ded70(10000);
									if (k == 0)
										f7_sound454260(p,0x86);
									if (f7_map_cefc4c->isVisible(p))
									{
										string text = *assembler->getName() + " finishes assembling " + e->name416f40() + ".";
										f7_message(0x320,F7HE(),text,0);
									}
								}
							}
						}
						delete f90;
						f90 = saved;
					}
				}
				f180 = 0;
				f184 = -1;
			}
			break;
		case 0x18:
			if (!b194)
			{
				bool k36 = rng.chance(25);
				F7Point ra11 = k36 ? F7Point(7,0x2d) : F7Point(0xc0,0x2d);
				F7Point k48 = k36 ? F7Point(0xc0,0x2d) : F7Point(7,0x2d);
				if (f7_map_cefc4c->unknown4642d0() == 2)
				{
					F7Area ra15(0xc,0x25,0xbb,0x29);
					bool m15 = false;
					for (int k = 0; k < 10; k++)
					{
						F7Point p;
						for (int j = 0; j < 200; j++)
						{
							p = ra15.randomPoint40be90();
							if (!f7_map_cefc4c->isVisible(p))
								break;
						}
						unknown690470(p,k48,0,&m15);
					}
				}
				if (rng.chance(f7_cf68b4 != 0 && f7_cf68b4->f110 == 8 ? 5 : 10) && f7_stringToInt(f7_gameData_d1e860.getEntryText("extTransferStationDisabled_g")) == 0)
				{
					if ((*f7_cells_cfd44c.at(7,0x2e))->getProp().isNull() || (*f7_cells_cfd44c.at(7,0x2e))->getProp()->unknown457b10() != 0 || (*f7_cells_cfd44c.at(0xc0,0x2e))->getProp().isNull() || (*f7_cells_cfd44c.at(0xc0,0x2e))->getProp()->unknown457b10() != 0)
					{
						f7_gameData_d1e860.addToEntry46f7e0("extTransferStationDisabled_g",1);
						vector<F7HE> *members = f7_map_cefc4c->squad463890(4)->members();
						for (unsigned int k = 0; k < members->size(); k++)
						{
							if ((*members)[k]->getAI()->mode4() == 0x19)
								(*members)[k]->getAI()->unknown459540(F7Point(0xc4,0x2a));
						}
						int n = rng.rangeInt(1,2);
						while (n != 0)
						{
							spawnPatrolParty(F7HE(),0,0,0,0,0,0,10,0);
							n--;
						}
						F7_ALERT(0x127,&string("ALERT: Transfer network disrupted, dispatching additional forces."));
						F7_PHRASE(0x71,0);
					}
					else
					{
						bool spawned = false;
						for (int n = rng.rangeInt(1,3); n > 0; n--)
							unknown690470(ra11,k48,0,&spawned);
					}
				}
				if (f7_map_cefc4c->unknown4642d0() % 25 == 0 && f7_map_cefc4c->squad463890(4)->count44afb0() > 20 && f7_stringToInt(f7_gameData_d1e860.getEntryText("extTransferStationDisabled_g")) == 0 && f7_stringToInt(f7_gameData_d1e860.getEntryText("extTransferThreatened_g")) == 0)
				{
					f7_gameData_d1e860.addToEntry46f7e0("extTransferThreatened_g",1);
					vector<F7HE> *members = f7_map_cefc4c->squad463890(4)->members();
					for (unsigned int k = 0; k < members->size(); k++)
					{
						if ((*members)[k]->getAI()->mode4() == 0x19)
							(*members)[k]->getAI()->unknown459540(F7Point(0xc4,0x2a));
					}
					int n = 2;
					while (n != 0)
					{
						spawnPatrolParty(F7HE(),0,0,0,0,0,0,10,0);
						n--;
					}
					F7_ALERT(0x127,&string("ALERT: Persistent threat to transfer network, dispatching additional forces."));
					F7_PHRASE(0x71,0);
				}
			}
			break;
		case 0x1b:
			if (!b194)
			{
				F7Point gate(0x60,0x31);
				if (rng.chance(f7_cf68b4 != 0 && f7_cf68b4->f110 == 8 ? 5 : 10) && f7_stringToInt(f7_gameData_d1e860.getEntryText("hubTransferStationDisabled_g")) == 0)
				{
					if ((*f7_cells_cfd44c.at(0x61,0x31))->getProp().isNull() || (*f7_cells_cfd44c.at(0x61,0x31))->getProp()->unknown457b10() != 0)
					{
						f7_gameData_d1e860.addToEntry46f7e0("hubTransferStationDisabled_g",1);
						int n = rng.rangeInt(1,2);
						while (n != 0)
						{
							spawnPatrolParty(F7HE(),0,0,0,0,0,0,10,0);
							n--;
						}
						F7_ALERT(0x127,&string("ALERT: Transfer network disrupted, dispatching garrison force."));
						F7_PHRASE(0x71,0);
					}
					else
					{
						vector<F7Point> points;
						f7_map_cefc4c->unknown714000(points);
						bool spawned = false;
						for (int n = rng.rangeInt(1,3); n > 0; n--)
							unknown690470(gate,f7_randomPoint(points),0,&spawned);
					}
				}
			}
			if (b168)
			{
				b168 = false;
				vector<F7Point> ra19;
				vector<F7Point> *m21 = f7_map_cefc4c->unknown463ab0();
				for (unsigned int k = 0; k < m21->size(); k++)
				{
					if ((*f7_cells_cfd44c.atPoint((*m21)[k]))->getProp().isNull() || (*f7_cells_cfd44c.atPoint((*m21)[k]))->getProp()->def9b8f00()->f8c == 0)
						f7_eraseStep(*m21,k);
					else if ((*f7_cells_cfd44c.atPoint((*m21)[k]))->getProp()->getType() == "HUB_Network_Hub")
						ra19.push_back((*m21)[k]);
				}
				F7Point e46;
				for (unsigned int k = 0; k < ra19.size(); k++)
				{
					if (f7_overmind_cf6428.spawnResponseParty(2,F7HE(),ra19[k],e46))
						f118.push_back(e46);
				}
				f118.clear();
			}
			break;
		case 0x1e:
			if (!f16c.empty())
			{
				const int ra22 = 15;
				int m25 = f7_map_cefc4c->unknown463d40();
				for (unsigned int k = 0; k < f16c.size(); k++)
				{
					if (f7_map_cefc4c->getTurn() >= f16c[k] + ra22)
					{
						f7_map_cefc4c->unknown465120(f7_map_cefc4c->unknown463d40() + 20);
						f7_eraseAt(f16c,k);
					}
				}
				if (m25 < f7_map_cefc4c->unknown463d40())
				{
					F7_ALERT(-1,&("ALERT: Ambient heat levels +" + f7_intToString(f7_map_cefc4c->unknown463d40() - m25) + "."));
					F7_PHRASE(0x1f4,&f7_intToString(f7_map_cefc4c->unknown463d40() - m25));
				}
				if (f7_map_cefc4c->unknown463d40() >= 0 && !b194)
				{
					b194 = true;
					vector<F7Point> points;
					f7_map_cefc4c->unknown714000(points);
					if (points.empty())
					{
					}
					else
					{
						vector<F7HE> *members = f7_map_cefc4c->squad463890(4)->members();
						for (unsigned int k = 0; k < members->size(); k++)
						{
							(*members)[k]->setAI(new F7AI((*members)[k],0x19,0xe));
							(*members)[k]->getAI()->unknown459540(f7_randomPoint(points));
						}
					}
					F7_ALERT(-1,&string("ALERT: All non-combat units evacuate."));
					F7_PHRASE(0x1f5,0);
				}
				if (f7_map_cefc4c->unknown463d40() >= 20 && !b195)
				{
					b195 = true;
					b196 = true;
					b197 = true;
					b198 = true;
					vector<F7Point> points;
					f7_map_cefc4c->unknown714000(points);
					if (points.empty())
					{
					}
					else
					{
						vector<F7HE> *members = f7_map_cefc4c->squad463890(3)->members();
						for (unsigned int k = 0; k < members->size(); k++)
						{
							if ((*members)[k]->getFaction() != 0x21)
								(*members)[k]->getAI()->unknown4582d0(0x17);
						}
					}
					F7_ALERT(-1,&string("ALERT: All combat units evacuate."));
					F7_PHRASE(0x1f6,0);
					f17c = f7_map_cefc4c->getTurn() + 100;
					f7_map_cefc4c->unknown736270("QUA_Malfunction_Detect");
					if (f7_d25450)
						f7_xom_d25450.unknown69e700(0x52,0,0);
				}
				if (f7_cf68b4 != 0 && f7_map_cefc4c->unknown463d40() >= f7_ba5000[f7_cf68b4->f110][0])
					f7_tally_cf6888.unknown699c20();
			}
			if (f17c != 0 && f7_map_cefc4c->getTurn() == f17c)
			{
				F7Rec *guard;
				f7_findRec(f7_records_d25de0,"Quarantine Guard",guard);
				if (guard != 0)
				{
					F7_ALERT(0x129,&string("ALERT: Activating Quarantine Guard."));
					F7_PHRASE(0x1f7,0);
					const int ra26 = 12;
					vector<F7Point> m43(*f7_map_cefc4c->unknown463d60());
					vector<F7Access *> *e53 = f7_map_cefc4c->accesses462e10();
					for (unsigned int k = 0; k < e53->size(); k++)
						f7_fn9d5460(m43,0,(*e53)[k]->pos);
					vector<F7Point> m49;
					for (unsigned int k = 0; k < m43.size(); k++)
					{
						if (!(*f7_cells_cfd44c.atPoint(m43[k]))->field4550b0() || ((*f7_cells_cfd44c.atPoint(m43[k]))->getProp().isValid() && !(*f7_cells_cfd44c.atPoint(m43[k]))->field4550b0()))
						{
							f7_cells_cfd44c.getNeighbors9d24b0(m43[k],m49);
							f7_shuffle(m49);
							for (unsigned int j = 0; j < m49.size(); j++)
							{
								if ((*f7_cells_cfd44c.atPoint(m49[j]))->field4550b0() && ((*f7_cells_cfd44c.atPoint(m49[j]))->getProp().isNull() || (*f7_cells_cfd44c.atPoint(m49[j]))->getProp()->isPassableFor(F7HE())))
								{
									m43[k] = m49[j];
									goto nextSpot;
								}
							}
							f7_eraseStep(m43,k);
						}
nextSpot:;
					}
					for (int k = 0; k < ra26; k++)
					{
						F7Point ra33;
						int ra37 = 0;
						if (!findDispatchExit(ra33,0,0,1,F7Point(-1),&ra37,0,0))
						{
							f128++;
							break;
						}
						else
							f7_fn9d0690(f128,1,0);
						F7HE ra42 = f7_map_cefc4c->placeEntity(guard,ra33,3,0,0x22,0xe,0);
						if (ra42.isValid())
						{
							if (k < m43.size())
								ra42->getAI()->unknown459540(m43[k]);
							else
								ra42->getAI()->unknown459470(f7_cells_cfd44c.getArea9b4400());
							addParty(new F7Party(0,ra42,-1,0,0),ra37);
						}
					}
				}
			}
			break;
		}
	}
	if (f34 != 0)
	{
		if (f7_map_cefc4c->getTurn() - f34 == (b40 ? 1 : 50))
			unknown681550();
		else if (f7_map_cefc4c->getTurn() - f34 == (b40 ? 2 : 65))
			unknown681810();
		else if (f4c == 0)
		{
			if (f7_map_cefc4c->getTurn() - f34 == (b40 ? 3 : 80))
			{
				F7_ALERT(-1,&string("ALERT: Lockdown in effect, collecting threat data."));
				if (!b40)
					F7_PHRASE(0x6c,0);
				F7Rec *unit = f7_bs_cefc4c->selectRobotOfClass(1,0x15,0,0);
				if (unit != 0)
				{
					vector<F7Point> ra46;
					f7_map_cefc4c->unknown714090(ra46);
					F7Point m5;
					for (unsigned int k = 0; k < ra46.size(); k++)
					{
						for (int d = 0; d < 8; d += 2)
						{
							m5.set40a090(ra46[k],f7_dirs_d015d8[d]);
							F7HE e = f7_map_cefc4c->placeEntity(unit,m5,3,0,0x22,0xe,0);
							if (e.isValid())
								e->getAI()->unknown459540(m5);
						}
					}
				}
			}
			if ((f7_map_cefc4c->getTurn() - f34) % f3c == 0)
			{
				int waves = f38 == 1 ? 2 : f38;
				if (b40)
					waves++;
				waves *= 2;
				for (int k = 0; k < waves; k++)
				{
					int mode = 0;
					if (f7_location_d1e888->f8 <= 3 && k == 0 && (f38 == 2 || (f38 > 2 && rng.chance(0x21))))
						mode = 2;
					else if (f7_location_d1e888->f8 <= 7 && rng.chance(f7_minInt(0x42,f38 * 15)))
						mode = 3;
					if (spawnHunterParty(f7_map_cefc4c->getPlayer(),0,0) && !squads.empty())
						squads.back()->leader->getAI()->setMode4505b0(mode);
				}
				string text(f38 <= 2 ? "ALERT: Assault forces dispatched." : "ALERT: Heavy assault forces dispatched.");
				F7_ALERT(0x129,&text);
				f38++;
				f3c += f38 * 50;
			}
		}
	}
	else
	{
		switch (f7_location_d1e888->depth)
		{
		case 5:
			if (!b31 && (*f7_map_cefc4c->lists459070())[5].size() == 1)
			{
				b31 = true;
				F7_ALERT(-1,&string("ALERT: Garrison responsiveness significantly impaired, staging for potential maximum security."));
			}
			if ((*f7_map_cefc4c->lists459070())[5].empty())
			{
				f7_player_cf45d8.unknown77fbc0(0x159);
				unknown68d980(1,0,1);
			}
			else if (f7_map_cefc4c->unknown4642d0() == 3 && f7_hist_d1e88c[f7_hist_d1e88c.size() - 2]->depth == 0xd && f7_hist_d1e88c[f7_hist_d1e88c.size() - 2]->f8 == f7_location_d1e888->f8)
			{
				f7_cf4d16 = true;
				F7_ALERT(-1,&string("ALERT: Access garrison breached."));
				unknown681550();
			}
			break;
		case 0x1e:
		case 0x1f:
		case 0x20:
		case 0x21:
			if (f7_d1eacc)
			{
				F7_ALERT(-1,&string("ALERT: Suspected Assembled signals penetrating research branch."));
				unknown68d980(1,0,1);
			}
			break;
		}
	}
	if (f4c != 0)
	{
		int elapsed = f7_map_cefc4c->getTurn() - f4c;
		if (f7_location_d1e888->depth != 0xe)
		{
			switch (elapsed)
			{
			case 100:
				{
					vector<F7Point> points;
					f7_map_cefc4c->unknown714000(points);
					if (!points.empty())
					{
						vector<F7HE> *members = f7_map_cefc4c->squad463890(3)->members();
						for (unsigned int k = 0; k < members->size(); k++)
						{
							if ((*members)[k]->getFaction() != 0x21)
								(*members)[k]->getAI()->unknown4582d0(0x17);
						}
						F7_ALERT(-1,&string("ALERT: All combat units evacuate."));
						F7_PHRASE(0x1f6,0);
					}
				}
				break;
			case 0x69:
				if (f34 == 0)
					unknown681550();
				break;
			case 0x6e:
				if (f34 == 0)
					unknown681810();
				break;
			default:
				if (elapsed == 0xaf)
					f7_map_cefc4c->unknown736270("QUA_Malfunction_Detect");
				if (elapsed >= 250 && f7_map_cefc4c->unknown463d40() >= 10)
				{
					const int range = 20;
					if (elapsed % 53 == 0)
					{
						F7Point pos(f7_map_cefc4c->getPlayer()->getPosition());
						for (unsigned int k = 0; k < f7_machines_d31640.size(); k++)
						{
							if (!f7_machines_d31640[k].empty() && f7_distance(f7_machines_d31640[k][0]->pos4184d0(),pos) <= range && rng.chance(25) && f7_machines_d31640[k][0]->def9b8f00()->f60->name == "Machine")
							{
								vector<int> rb1;
								f7_fn9da8f0(f7_machines_d31640[k],rb1);
								int m57 = f7_minInt(f7_maxInt(3,rb1.size() / 3),rb1.size());
								vector<F7HProp> m59;
								for (int j = 0; j < m57; j++)
									m59.push_back(f7_machines_d31640[k][rb1[j]]);
								string rb12;
								for (unsigned int j = 0; j < m59.size(); j++)
								{
									if (f7_map_cefc4c->isVisible(m59[j]->pos4184d0()))
									{
										if (rb12.empty())
											rb12 = *m59[j]->getName();
										f7_cmap_cec054->unknown8195a0(m59[j]->pos4184d0(),m59[j]->unknown45c650(),5);
									}
									m59[j]->unknown45ce10(1,1,1,F7HE());
								}
								if (!rb12.empty())
								{
									string text = rb12 + " melts.";
									F7_MESSAGE(0x320,&text,0);
								}
							}
						}
					}
					if (elapsed % 37 == 0)
					{
						F7Area area;
						f7_cells_cfd44c.getRect(f7_map_cefc4c->getPlayer()->getPosition(),range,area);
						for (int x = area.p1.x; x <= area.p2.x; x++)
						{
							for (int y = area.p1.y; y <= area.p2.y; y++)
							{
								if ((*f7_cells_cfd44c.at(x,y))->getItem().isValid())
								{
									F7HItem item = (*f7_cells_cfd44c.at(x,y))->getItem();
									if (item->unknown457880() != 0)
									{
										int chance = (200 - item->unknown9b6bf0()) / 6;
										if (chance > 0 && rng.chance(chance))
										{
											if (f7_map_cefc4c->isVisible(item->unknown575920()))
											{
												string text = item->getName571db0(0,0) + " melts.";
												F7_MESSAGE(0x320,&text,0);
												f7_cmap_cec054->unknown8195a0(item->unknown575920(),item->unknown457a30(),5);
											}
											item->remove57dbe0(0,0,1,1);
										}
									}
								}
							}
						}
					}
				}
				elapsed -= 150;
				if (elapsed > 0 && elapsed % 150 == 0)
				{
					const int heat = 10;
					f7_map_cefc4c->unknown465120(f7_map_cefc4c->unknown463d40() + heat);
					F7_ALERT(-1,&("ALERT: Ambient heat levels +" + f7_intToString(heat) + "."));
					F7_PHRASE(0x1f4,&f7_intToString(heat));
					if (f7_voice_cefb48 != 0)
						f7_voice_cefb48->say(0x34,0,f7_intToString(f7_map_cefc4c->unknown463d40()));
					if (f7_player_cf45d8.hasCompanion780790())
						f7_cf4ac8->f30->spawn7aa280(0x2b,0,"");
				}
				break;
			}
		}
		else
		{
			elapsed -= 5;
			if (elapsed > 0 && elapsed % 15 == 0)
			{
				const int heat = 10;
				f7_map_cefc4c->unknown465120(f7_map_cefc4c->unknown463d40() + heat);
				F7_ALERT(-1,&("ALERT: Ambient heat levels +" + f7_intToString(heat) + "."));
				F7_PHRASE(0x1f4,&f7_intToString(heat));
			}
		}
	}
	else
	{
		if (b49 || (f7_b903c0[f7_location_d1e888->depth] != 0 && (f44 >= f7_b903c0[f7_location_d1e888->depth] * (f7_d1ebfc ? 2 : 1) || f7_map_cefc4c->unknown74d270()) && !b48 && (f7_location_d1e888 != f7_hloc_d1ebd8 || f7_stringToInt(f7_gameData_d1e860.getEntryText("warWarlordDestroyed_g")) != 0) && (f7_location_d1e888 != f7_hloc_d1ebe0 || f7_stringToInt(f7_gameData_d1e860.getEntryText("resR17Destroyed_g")) != 0) && (f44 < f7_b903c0[f7_location_d1e888->depth] * (f7_d1ebfc ? 2 : 1) || rng.chance(f44 + 2 - f7_b903c0[f7_location_d1e888->depth] * (f7_d1ebfc ? 2 : 1) * (f7_cf462c == 9 ? 2 : 1)))))
		{
			f4c = f7_map_cefc4c->getTurn();
			F7_PHRASE(0x6e,0);
			f7_stats_d2c658.add4729d0(0x215,1,"",-1);
			if (!b49)
			{
				if (f7_map_cefc4c->unknown74d270())
					f7_stats_d2c658.add472b90(0x23,-999999);
				if (f7_b903c0[f7_location_d1e888->depth] >= 100)
					f7_tally_cf6888.unknown6998a0(0xb,1,0);
				if (f7_location_d1e888->depth == 3 || f7_location_d1e888->depth == 4)
					f7_player_cf45d8.unknown77fbc0(0x13e);
				if (f7_player_cf45d8.isSlotEmpty(0x15d))
				{
					int count = 0;
					for (unsigned int k = 0; k < f7_hist_d1e88c.size(); k++)
					{
						if ((*f7_statsHist_d2c65c[k])[0x215] != 0 && f7_hist_d1e88c[k]->depth != 0xe)
							count++;
					}
					if (count >= 4)
						f7_player_cf45d8.unknown77fbc0(0x15d);
				}
			}
			b194 = true;
			b195 = true;
			b196 = true;
			b197 = true;
			b198 = true;
			f7_map_cefc4c->f5b4 = -1;
			unknown68d6d0(0);
			string rb16 = "ALERT: Persistent threat exposed, engaging " + f7_zoneNames_cfaca0[f7_location_d1e888->depth] + " sterilization system.";
			F7_ALERTX(1,0x11e,0,&rb16);
			vector<F7Point> rb30;
			f7_map_cefc4c->unknown714000(rb30);
			if (!rb30.empty())
			{
				vector<F7HE> *members = f7_map_cefc4c->squad463890(4)->members();
				for (unsigned int k = 0; k < members->size(); k++)
				{
					(*members)[k]->setAI(new F7AI((*members)[k],0x19,0xe));
					(*members)[k]->getAI()->unknown459540(f7_randomPoint(rb30));
				}
				F7_ALERT(-1,&string("ALERT: All non-combat units evacuate."));
				F7_PHRASE(0x1f5,0);
			}
			f7_tally_cf6888.unknown699c20();
			if (f7_voice_cefb48 != 0)
				f7_voice_cefb48->say(0x33,0,"");
			if (f7_d25450 && !b49)
				f7_xom_d25450.unknown69e700(0x30,0,0);
		}
		else if (f7_location_d1e888->depth == 0xe && (f44 >= 8 || b4a || f7_map_cefc4c->unknown74d270()) && !b48)
		{
			int chance = !b4a && f44 < 12 && !f7_map_cefc4c->unknown74d270() ? f44 - 5 : 100;
			if (rng.chance(chance))
			{
				f4c = f7_map_cefc4c->getTurn();
				f7_stats_d2c658.add4729d0(0x215,1,"",-1);
				if (f7_map_cefc4c->unknown74d270())
					f7_stats_d2c658.add472b90(0x23,-999999);
				F7_PHRASE(0x6e,0);
				b194 = true;
				b195 = true;
				b196 = true;
				b197 = true;
				b198 = true;
				f7_map_cefc4c->f5b4 = -1;
				string text = "ALERT: Persistent threat exposed, engaging " + f7_zoneNames_cfaca0[f7_location_d1e888->depth] + " rapid sterilization system.";
				F7_ALERTX(1,0x11e,0,&text);
				f7_player_cf45d8.unknown77fbc0(0xa2);
				b4a = false;
				f7_gameData_d1e860.unknown7897a0(4);
				switch (f7_d1eb9c[f7_gameData_d1e860.getDepthIndex()])
				{
				case 3:
					{
						vector<F7HE> *members = f7_map_cefc4c->squad463890(9)->members();
						int shown = 0;
						for (unsigned int k = 0; k < members->size(); k++)
						{
							(*members)[k]->setAI(new F7AI((*members)[k],0x19,0));
							(*members)[k]->getAI()->unknown459540(f7_map_cefc4c->accesses462e10()->front()->pos);
							if (shown < 3 && f7_map_cefc4c->unknown4631f0((*members)[k]))
							{
								shown++;
								f7_bs_cefc4c->unknown6c65a0((*members)[k],"DSF_W_Active_Dialogue_" + f7_intToString(shown),false);
							}
						}
					}
					break;
				case 4:
					{
						vector<F7HE> *members = f7_map_cefc4c->squad463890(5)->members();
						int shown = 0;
						for (unsigned int k = 0; k < members->size(); k++)
						{
							(*members)[k]->setAI(new F7AI((*members)[k],0x19,0));
							(*members)[k]->getAI()->unknown459540(f7_map_cefc4c->accesses462e10()->front()->pos);
							(*members)[k]->removeEffectsA639730(0);
							if (shown == 0 && f7_map_cefc4c->unknown4631f0((*members)[k]))
							{
								shown++;
								f7_bs_cefc4c->unknown6c65a0((*members)[k],"DSF_Wild_Derelicts_Flee",false);
							}
						}
					}
					break;
				}
			}
		}
	}
	if (f7_d1ebfc && f7_location_d1e888->depth != 0x21 && f7_gameData_d1e860.unknown46f4b0(1) && f7_location_d1e888->depth != 0xd && f7_location_d1e888->depth != 0x23 && f34 == 0 && f4c == 0 && (f7_map_cefc4c->unknown4642d0() == 15 || f7_map_cefc4c->unknown4642d0() % 500 == 0))
		F7_ALERTX(0,-1,1,&string("NOTICE: Protoforge disruption unresolved, advanced fortification protocols active."));
	if (f7_cefbc0 != 0 && rng.chance(5))
	{
		f7_cefbc0 = 0;
		vector<F7Def *> items;
		for (int n = rng.rangeInt(7,13); n > 0; n--)
			f7_fn9db000(items,f7_randomDef(f7_defs_d2d1c4));
		f7_deleteObjects(items);
	}
}
