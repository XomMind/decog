// NOTE: placeholder names and partial layouts; BS::initilize (0x7026b0): builds a new map (terrain from the generator,
// stairs/exits, cells, squads, items, encounters, allies, events) when entering a location.
#include <string>
#include <vector>
#include "rng.h"
using namespace std;
extern RNG rng;

struct G8Rect;
struct G8Point
{
	int x, y;
	G8Point() {}	// 0x453b40
	G8Point(int x_, int y_);	// 0x46ca20
	G8Point(int v);	// 0x409990
	G8Point(const G8Point &p);	// 0x46ca50
	G8Point &operator=(const G8Point &p);	// 0x46ca50
	G8Point &operator=(int v);	// 0x409ff0
	int randomInRange();	// 0x40c130
	void set40a060(const G8Point &p, int a, int b);	// 0x40a060
};
struct G8Dims {int x, y;};
struct G8Rect
{
	int x, y, w, h;
	G8Rect();	// 0x40a6e0
	G8Rect(int x_, int y_, int w_, int h_);	// 0x456940
	int right40ac20();	// 0x40ac20
	int bottom40ac40();	// 0x40ac40
	void set40a840(int a, int b, int c, int d);	// 0x40a840
	void set40a870(const G8Point &p, int w_, int h_);	// 0x40a870
	bool contains(int x_, int y_);	// 0x40a9a0
	G8Point center40ad40();	// 0x40ad40
	G8Point randomPos40b080();	// 0x40b080
};
struct G8Area
{
	G8Point p1, p2;
	G8Area();	// 0x40b100
	G8Area(const G8Rect &r);	// 0x40b290
	G8Area &operator=(const G8Area &a);	// 0x40b130
	void set40b300(int a, int b, int c, int d);	// 0x40b300
};
struct G8Grid
{
	int *data;
	int w, h;
	G8Grid(int w_, int h_, int v);	// 0x9ced10
	~G8Grid();	// 0x9cec20
	int *at(int x_, int y_);	// 0x9ceda0
	int *atPoint(const G8Point &p);	// 0x9ced70
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	void resize9d4090(int w_, int h_, int v);	// 0x9d4090
	void zero9d23e0();	// 0x9d23e0
};
struct G8BoolGrid {char pad[12]; void resize9d2810(int w, int h, int v); void zero9d28b0();};	// 0x9d2810, 0x9d28b0
struct G8ColorProp {void reset461bc0();};	// 0x461bc0
struct G8ColorGrid {char pad[12]; void resize9d2ae0(int w, int h, int v); G8ColorProp *at9cdf20(int x, int y);};	// 0x9d2ae0, 0x9cdf20
struct G8Style {void reset460f00();};	// 0x460f00
struct G8StyleGrid {char pad[12]; void resize9d2de0(int w, int h, int v); G8Style *at9d2c30(int x, int y);};	// 0x9d2de0, 0x9d2c30
struct G8Sel {int x;};
struct G8Reset {int x; void reset9c07a0();};	// 0x9c07a0
struct G8ViewInit {int x; void init9cffc0(int w, int h, int v);};	// 0x9cffc0
struct G8Entity;
struct G8Prop;
struct G8Item;
struct G8Location;
struct G8Squad;
struct G8Group;
struct G8HE {int id; G8HE() {} bool isValid() const; bool isNull() const; G8Entity *operator->() const; void reset9b7270();};	// 0x9b6590, 0x9b7230, 0x9b65d0, 0x9b6570, 0x9b7270
struct G8HProp {int id; G8HProp() {} bool isValid() const; bool isNull() const; G8Prop *operator->() const;};	// 0x9b64f0
struct G8HItem {int id; bool isValid() const; G8Item *operator->() const;};	// 0x9b65b0
struct G8HLocation {int id; G8HLocation() {} bool isValid() const; bool isNull() const; G8Location *operator->() const throw(); bool operator==(G8HLocation o) const; bool operator!=(G8HLocation o) const;};	// 0x9b7910, 0x9b78e0, 0x9b6510
struct G8HSquad {int id; G8Squad *operator->() const;};	// 0x9b7250
struct G8HGroup {int id; G8Group *operator->() const;};	// 0x9b7250
struct G8HTurn {int id;};
struct G8Terrain {int id; char pad4[0x44 - 4]; struct G8Color {int v; G8Color(int c); G8Color &operator=(G8Color c);} color;};	// 0x411e30, 0x411f10
struct G8Location
{
	char pad0[4];
	int depth;
	int f8;
	vector<G8HLocation> links;
	int f1c;
	int f20;
	bool b24;
	bool b25;
	char pad26[7];
	bool b2d;
	bool inRange46ecb0();	// 0x46ecb0
	int rating46ed20();	// 0x46ed20
	G8HLocation find46ee80(int kind);	// 0x46ee80
	void init46eb70(int a, int b, int c, int d);	// 0x46eb70
};
struct G8Group {int kind9b4350();};	// 0x9b4350
struct G8EntDef {char pad[0x48]; int f48;};
struct G8Obj;
struct G8AI
{
	char pad[0x130];
	G8AI(G8HE e, int a, int b);	// 0x57f6a0
	void setFollowEntity(G8HE e, int mode);	// 0x5b2f80
	void unknown459540(const G8Point &p);	// 0x459540
};
struct G8Entity
{
	const G8Point &getPosition();	// 0x45a4a0
	G8AI *getAI();	// 0x45b590
	int getFaction();	// 0x45a2c0
	int getTarget45a760();	// 0x45a760
	void setAI(G8AI *ai);	// 0x64ecf0
	void changePos5dccb0(const G8Point &p, int a);	// 0x5dccb0
	int unknown448fe0(int a);	// 0x448fe0
	G8HE handle45a260();	// 0x45a260
	int kind9fcd80();	// 0x9fcd80
	int getSize45a360();	// 0x45a360
	vector<G8Obj *> *unknown45a740();	// 0x45a740
	G8EntDef *def9b4350();	// 0x9b4350
	G8HGroup getGroup();	// 0x45a3f0
	string &name416f40();	// 0x416f40
	void unknown637bb0();	// 0x637bb0
	int unknown45a920();	// 0x45a920
	int unknown5d1390();	// 0x5d1390
	vector<G8HItem> *getInventoryList45ab00();	// 0x45ab00
	void unknown5e2590(G8HItem i, int a, int b);	// 0x5e2590
	int unknown5db5f0(G8HItem i, int a, int b, int c);	// 0x5db5f0
	int unknown5dc440(G8HItem i);	// 0x5dc440
	int unknown45a810();	// 0x45a810
	int unknown5cb9b0(int a);	// 0x5cb9b0
	int unknown5c8e20(int a);	// 0x5c8e20
	int unknown45a880();	// 0x45a880
	G8Point unknown45a4c0();	// 0x45a4c0
	int unknown5cccc0();	// 0x5cccc0
	bool unknown5d26e0(int a);	// 0x5d26e0
	int unknown5c7c80();	// 0x5c7c80
	void unknown5e2b50();	// 0x5e2b50
	void unknown45b070(const string &s);	// 0x45b070
};
struct G8Squad {vector<G8HE> *members416f40(); void addMember671280(G8HE e, int a);};	// 0x416f40, 0x671280
struct G8Machine {char pad[0x28]; int f28; int unknown45c1c0(int a);};	// 0x45c1c0
struct G8PropDef {char pad[0x140]; int f140;};
struct G8Data {char pad[0x70]; int f70; bool hasData4560d0(int a);};	// 0x4560d0
struct G8RecList {G8Data *getDataOfType4564e0(int a);};	// 0x4564e0
struct G8Prop
{
	string &getType();	// 0x45c590
	string *getName();	// 0x45c5b0
	G8Machine *machine45cb30();	// 0x45cb30
	G8PropDef *def9b8f00();	// 0x9b8f00
	const G8Point &pos4184d0();	// 0x4184d0
	G8RecList *unknown45c9b0();	// 0x45c9b0
};
struct G8ItemType {char pad[0x54]; int f54;};
struct G8Item
{
	int unknown457880();	// 0x457880
	int unknown457f90();	// 0x457f90
	int unknown457ca0();	// 0x457ca0
	int slot4578a0();	// 0x4578a0
	int unknown457900();	// 0x457900
	int unknown4578c0();	// 0x4578c0
	void remove57dbe0(int a, int b, int c, int d);	// 0x57dbe0
	void unknown4582d0(G8HItem i);	// 0x4582d0
	void unknown57a0f0(const G8Point &p, int a, int b);	// 0x57a0f0
	bool unknown571d70();	// 0x571d70
	int kind9fcd80();	// 0x9fcd80
	G8HItem handle45a260();	// 0x45a260
	G8ItemType *def9b4350();	// 0x9b4350
	void unknown57a190(G8HE e, int a, int b, int c);	// 0x57a190
	void setActive5791a0(int a);	// 0x5791a0
};
struct G8Cell
{
	char pad[0x70];
	G8Cell(G8Terrain *t);	// 0x669bf0
	G8HProp getProp();	// 0x45d550
	G8HE getEntity();	// 0x45d250
	G8HItem getItem();	// 0x45d8f0
	void setPos45dea0(int x, int y);	// 0x45dea0
	void unknown66a050(int a, int b, int c);	// 0x66a050
	bool isMachinePart45dcd0();	// 0x45dcd0
	void unknown66b640();	// 0x66b640
	bool unknown45db70();	// 0x45db70
	bool unknown45dc70();	// 0x45dc70
	G8Terrain *terrain9fcd80();	// 0x9fcd80
	void trigger45e110(int a, int b, G8HE e);	// 0x45e110
	int unknown66afe0();	// 0x66afe0
	void set45b090(int a);	// 0x45b090
	bool unknown45dcf0();	// 0x45dcf0
	void removeProp66c100(int a, int b);	// 0x66c100
};
struct G8Cells
{
	G8Cell **at(int x, int y);	// 0x9ceda0
	G8Cell **atPoint(const G8Point &p);	// 0x9ced70
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	void resize9d4090(int w, int h, int v);	// 0x9d4090
	void zero9d23e0();	// 0x9d23e0
	void getRect(const G8Point &p, int r, G8Area &out);	// 0x9b4430
	void getRandom9cf0c0(G8Point &p);	// 0x9cf0c0
	void getNeighbors9ce500(const G8Point &p, vector<G8Point> &out);	// 0x9ce500
};
struct G8Marker
{
	G8Point pos;
	G8HLocation loc;
	char padc[8];
	G8HProp h14;
	char pad18[4];
	int f1c;
	char pad20[0x60 - 0x20];
	G8Marker(const G8Point &p, G8HLocation l, bool b, G8HE e1, G8HE e2) {}	// 0x6c13a0
};
struct G8Branch {char pad[0x38]; G8Branch(int k, G8HLocation l) {}};	// 0x460860
struct G8Actor {char pad[4]; G8Actor() {}};	// 0x45e510
struct G8Actor2 {char pad[4]; G8Actor2(G8HE e) {} G8Actor2(G8HItem i) {}};	// 0x9f57e0
struct G8Turn {char pad[0x10]; G8Turn(int a, void *actor);};	// 0x45e530
struct G8Region {char pad[0x3c]; G8Region(int k);};	// 0x670ff0
struct G8Option {char pad[0xc]; G8Option(int a, void *def, int b) {}};	// 0x455da0
struct G8Rec {int id;};
struct G8ItemDef {char pad0[0x28]; int f28; char pad2c[0x44 - 0x2c]; int f44; char pad48[0x50 - 0x48]; int f50; int f54; int f58; char pad5c[4]; int f60; char pad64[0x94 - 0x64]; int f94; char pad98[0xf0 - 0x98]; int ff0;};
typedef G8ItemDef G8Def;
struct G8Challenge {int id; int depth; int weight; int fc; char b10; bool b11; char pad12[2]; int f14; int f18;};
struct G8Prefab {vector<G8Grid *> layers; char pad10[0x48 - 0x10]; int f48; int f4c; G8Point f50; char pad58[8];};
struct G8PrefabList {G8Prefab *a, *b, *c, *d; unsigned int size() const; const G8Prefab &operator[](unsigned int i) const; void clear();};	// 0x9b5450, 0x9b5470, 0x9b55c0
struct G8Room {vector<G8Point> cells; char pad10[0x45 - 0x10]; bool b45; char pad46[0x54 - 0x46];};
struct G8Encounter {int f0; G8Rect rect; char pad14[0x58 - 0x14]; int f58; char pad5c[4];};
struct G8Ally {int kind; G8Entity *ent; char pad8[0x38 - 8]; void unknown46e740();};	// 0x46e740
struct G8AllyList {void *p, *a, *b, *c; unsigned int size() const; const G8Ally &operator[](unsigned int i) const; void clear();};	// 0x9b8760, 0x9b8780, 0x9b88d0
struct G8EventDef {int f0, f4, f8, fc, f10; char pad[0xc];};
struct G8Link {G8HE h0; G8HE h4; G8Entity *e8; G8Entity *ec;};
struct G8Holder {int f0; G8HItem h4; ~G8Holder();};	// 0x70e610
struct G8Dialog {int f0; string name;};
struct G8Spawn;
struct G8Strings {void *proxy; string *a, *b, *c; void push(const string &s); void pushMove(string &&s); void clear();};	// 0x9b06f0, 0x9b0340, 0x9b0900
struct G8Stats {vector<int> *values; void add4729d0(int id, int v, string s, int a); void add472b90(int id, int v);};	// 0x4729d0, 0x472b90
struct G8Player {bool isSlotEmpty(int slot); void unknown77fbc0(int a); void unknown46df70(); void unknown783540();};	// 0x46de40, 0x77fbc0, 0x46df70, 0x783540
struct G8GameData
{
	string &getEntryText(const string &key);	// 0x46f6d0
	void setEntryText(const string &key, const string &value);	// 0x46f700
	bool unknown46f4b0(int a);	// 0x46f4b0
	int unknown46f4e0();	// 0x46f4e0
	void unknown7897a0(int a);	// 0x7897a0
	bool hasAnyObjects46f9f0();	// 0x46f9f0
	bool hasObjectID46fa40(int a);	// 0x46fa40
	bool isFlagEnabledB46fc40();	// 0x46fc40
	int getWeightedDepthCount7896a0() throw();	// 0x7896a0
};
struct G8Tutorial {bool unknown7784b0();};	// 0x7784b0
struct G8Flags {void start511440(int a, int b);};	// 0x511440
struct G8Pool {void initialize460510();};	// 0x460510
struct G8Item;
struct G8ItemPool {G8HItem add9d1b20(G8Spawn *s); void getAll9d0c30(vector<G8Item *> &out);};	// 0x9d1b20, 0x9d0c30
struct G8Sound {void unknown454430(); void unknown500260(int a);};	// 0x454430, 0x500260
struct G8CMap {void unknown8069e0(G8Point p, int a);};	// 0x8069e0
struct G8Luigi {void unknown777bc0();};	// 0x777bc0
struct G8JLog {void end410e50(int a);};	// 0x410e50
struct G8Noise
{
	char pad[0x20];
	G8Noise();	// 0x421650
	~G8Noise();	// 0x421750
	void init421680(int a, float b, int c);	// 0x421680
	void set450460(int a);	// 0x450460
	float sampleFbmXY421820(int x, int y);	// 0x421820
};
struct G8Factory {G8HSquad createF793410(G8Region *r); G8HE createEntity793200(G8Rec *rec); G8HLocation createB793120();};	// 0x793410, 0x793200, 0x793120
struct G8Queue {G8HTurn add672310(void *turn, int a); void clear9c05e0(); void unknown672800(G8HE e);};	// 0x672310, 0x9c05e0, 0x672800
struct G8Gen
{
	void init4bf610(int a, const string &s1, const string &s2, int b, int c, int d, int e);	// 0x4bf610
	void placeTunnelers4c15a0();	// 0x4c15a0
	void generate4c1880(int a);	// 0x4c1880
	bool getField449000();	// 0x449000
	int traceRooms4c7950();	// 0x4c7950
	void finalizeWalls4c7420();	// 0x4c7420
};
struct G8Cave
{
	void init4c9d80(int a, const string &s1, const string &s2, int b, int c, int d, int e);	// 0x4c9d80
	void step4cbcd0(int a);	// 0x4cbcd0
	bool getField449500();	// 0x449500
	void resetField449520();	// 0x449520
};
struct G8Carto
{
	char pad[0x38];
	G8Carto(int w, int h);	// 0x40cac0
	~G8Carto();	// 0x40cde0
	bool findPath(const G8Point &a, const G8Point &b, void *cost, void *data, vector<G8Point> &path);	// 0x40c9a0
	void resize40cec0(int w, int h);	// 0x40cec0
	void setField40c980(int a);	// 0x40c980
	void unknown40ca20(const G8Point &p, int r, void *cost, int *out);	// 0x40ca20
};
template <class T> class OpR5h_WL	// NOTE: placeholder name (weighted list)
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	OpR5h_WL(const int *w, int count);	// 0x9ba790
	void add(T value, int weight);	// 0x9ba310
	unsigned int size();	// 0x9b81d0
	T &pick();	// 0x9ba470
	vector<T> *getValues();	// 0x9c0790
};

class BS
{
public:
	bool b0;
	char pad1[0x3];
	int f4;
	G8Point f8;
	vector<G8Marker*> f10;
	vector<G8Branch*> f20;
	bool b30;
	char pad31[0x3];
	int f34;
	G8Grid f38;
	int f44;
	G8HE f48;
	vector<G8HSquad> f4c;
	G8Grid f5c;
	G8Sel f68;
	char pad6c[0x20];
	G8Sel f8c;
	char pad90[0x20];
	vector<int> fb0;
	char padc0[0x24];
	vector<int> fe4;
	char padf4[0x10];
	int f104;
	vector<vector<G8Point> > f108;
	vector<vector<G8Point> > f118;
	vector<vector<G8Point> > f128;
	char pad138[0x20];
	vector<G8Point> f158;
	vector<int> f168;
	char pad178[0x60];
	bool b1d8;
	char pad1d9[0x23];
	int f1fc;
	int f200;
	bool b204;
	char pad205[0x3];
	vector<int> f208;
	int f218;
	int f21c;
	char pad220[0x10];
	int f230;
	G8HProp f234;
	int f238;
	int f23c;
	int f240;
	char pad244[0x10];
	int f254;
	char pad258[0x10];
	vector<vector<G8HE> > f268;
	char pad278[0x34];
	int f2ac;
	vector<int> f2b0;
	char pad2c0[0x30];
	bool b2f0;
	char pad2f1[0x23];
	int f314;
	int f318;
	int f31c;
	int f320;
	int f324;
	int f328;
	bool b32c;
	bool b32d;
	char pad32e[0x2];
	vector<vector<G8HE> > f330;
	char pad340[0x90];
	int f3d0;
	int f3d4;
	char pad3d8[0x10];
	int f3e8;
	int f3ec;
	char pad3f0[0x130];
	int f520;
	char pad524[0x10];
	int f534;
	vector<G8Point> f538;
	vector<int> f548;
	bool b558;
	bool b559;
	char pad55a[0x2];
	int f55c;
	char pad560[0x10];
	int f570;
	char pad574[0x40];
	int f5b4;
	int f5b8;
	char pad5bc[0x58];
	int f614;
	char pad618[0x24];
	bool b63c;
	char pad63d[0x3];
	int f640;
	bool b644;
	char pad645[0x13];
	int f658;
	G8HTurn f65c;
	bool b660;
	char pad661[0x3];
	int f664;
	int f668;
	G8HE f66c;
	G8HE f670;
	G8BoolGrid f674;
	G8BoolGrid f680;
	int f68c;
	G8Grid f690;
	G8Grid f69c;
	char pad6a8[0x64];
	bool b70c;
	char pad70d[0x33];
	G8ColorGrid f740;
	int f74c;
	bool b750;
	bool b751;
	bool b752;
	bool b753;
	char pad754[0x70];
	G8StyleGrid f7c4;
	char pad7d0[0x10];
	vector<vector<G8HE> > f7e0;
	char pad7f0[0x20];
	int f810;
	char pad814[0x4];
	int f818;
	char pad81c[0x10];
	int f82c;
	char pad830[0x38];
	int f868;
	G8Point f86c;
	vector<vector<int> > f874;
	vector<G8Point> f884;
	vector<int> f894;
	bool b8a4;
	char pad8a5[0x3];
	int f8a8;
	bool b8ac;
	char pad8ad[0x3];
	int f8b0;
	char pad8b4[0x10];
	int f8c4;
	bool b8c8;
	char pad8c9[0x3];
	G8Area f8cc;
	char pad8dc[0x20];
	int f8fc;
	int f900;
	char pad904[0x20];
	G8Area f924;
	G8Area f934;
	G8Area f944;
	G8Area f954;
	bool b964;
	char pad965[0x3];
	int f968;
	char pad96c[0x20];
	int f98c;
	char pad990[0x10];
	bool b9a0;
	char pad9a1[0x3];
	int f9a4;
	int f9a8;
	int f9ac;
	int f9b0;
	int f9b4;
	int f9b8;
	char pad9bc[0x10];
	int f9cc;
	int f9d0;
	char pad9d4[0x10];
	bool b9e4;
	char pad9e5[0x3];
	G8HE f9e8;
	int f9ec;
	int f9f0;
	char pad9f4[0x10];
	int fa04;
	int fa08;
	bool ba0c;
	bool ba0d;
	bool ba0e;
	char pada0f[0x1];
	int fa10;
	bool ba14;
	bool ba15;
	bool ba16;
	char pada17[0x1];
	int fa18;
	bool ba1c;
	char pada1d[0x53];
	int fa70;
	bool ba74;
	char pada75[0x3];
	G8HE fa78;
	G8HE fa7c;
	char pada80[0x10];
	vector<G8Point> fa90;
	vector<int> faa0;
	vector<int> fab0;
	char padac0[0x20];
	int fae0;
	char padae4[0x20];
	bool bb04;
	bool bb05;
	bool bb06;
	bool bb07;
	vector<G8Option*> fb08;
	int fb18;
	int fb1c;
	int fb20;
	char padb24[0x10];
	int fb34;
	int fb38;
	G8Point fb3c;
	bool bb44;
	char padb45[0x3];
	int fb48;
	G8Reset fb4c;
	char padb50[0x30];
	int fb80;
	char padb84[0x10];
	vector<int> fb94;
	int fba4;
	G8HE fba8;
	int fbac;
	int fbb0;
	char padbb4[0x30];
	bool bbe4;
	char padbe5[0x3];
	G8ViewInit fbe8;
	char padbec[0x28];
	int fc14;
	vector<int> fc18;
	vector<struct G8Fc28 *> fc28;
	char padc38[0x20];
	vector<int> fc58;
	bool initilize();
	void placeRandomEncounter(vector<int> &encounters, vector<G8Rect> &placed, vector<bool> &placedFlags, vector<int> &used);	// 0x6f1e90
	bool unknown6de330();	// 0x6de330
	void carvePaths700e30();	// 0x700e30
	void unknown6de850();	// 0x6de850
	void populate6dfdb0();	// 0x6dfdb0
	void populate6e0eb0(vector<G8Point> &edges, vector<G8Rect> &placed, vector<bool> &flags);	// 0x6e0eb0
	void setupArchitect6e2110();	// 0x6e2110
	void unknown6ed450();	// 0x6ed450
	void unknown6d4c00(vector<int> &chosen);	// 0x6d4c00
	void unknown6e2b40();	// 0x6e2b40
	void unknown6fd470();	// 0x6fd470
	void unknown6eeaf0();	// 0x6eeaf0
	void unknown6fdcb0();	// 0x6fdcb0
	void garrison6ff590();	// 0x6ff590
	void postprocessGarrison6e4dc0();	// 0x6e4dc0
	void dsf6e68d0();	// 0x6e68d0
	void unknown6e2cb0();	// 0x6e2cb0
	void populate6e3c30();	// 0x6e3c30
	void init6e9270();	// 0x6e9270
	void unknown6e9480();	// 0x6e9480
	void init6e9570();	// 0x6e9570
	void unknown6ea660();	// 0x6ea660
	void unknown6eab60();	// 0x6eab60
	void factory6ead20();	// 0x6ead20
	void unknown6ed0b0();	// 0x6ed0b0
	void setup6ed7d0();	// 0x6ed7d0
	bool unknown6c6b90(const G8Point &p, const string &name, int a, int b);	// 0x6c6b90
	bool unknown7168e0(const G8Point &a, const G8Point &b, G8Entity *e, vector<G8Point> &path);	// 0x7168e0
	G8HE unknown6c6450(G8HE e, int a);	// 0x6c6450
	bool findPlaceableNear71c150(const G8Point &p, G8Point &out, int a);	// 0x71c150
	bool findPlaceableNearWide71c200(const G8Point &p, G8Point &out, int a);	// 0x71c200
	bool unknown71bc10(const G8Point &p, G8Point &out);	// 0x71bc10
	void unknown464f60(G8HItem i);	// 0x464f60
	void unknown465060(G8HItem i);	// 0x465060
	G8HE unknown6c5e20(const G8Ally *a, const G8Point &p, int b, int c, int d, bool e);	// 0x6c5e20
	bool unknown73cfb0();	// 0x73cfb0
	G8Point unknown6c2230(int depth);	// 0x6c2230
	G8Point unknown6c2b60(bool a, int b, int *c);	// 0x6c2b60
	void unknown6c38a0(const G8Rect &r, int a, float b, int c);	// 0x6c38a0
	void unknown6c3a50(G8Sel &s, int a, int b);	// 0x6c3a50
	void unknown6c4fd0();	// 0x6c4fd0
	void unknown6cd110(const G8Prefab &p, int a, int b, float c);	// 0x6cd110
	void spawnPlayer2_6ee930();	// 0x6ee930
	void unknown6ef100();	// 0x6ef100
	void unknown6df000();	// 0x6df000
	void unknown6dfc00(int room);	// 0x6dfc00
	void clear9c05e0();	// 0x9c05e0
	void unknown6e33a0();	// 0x6e33a0
	void unknown6ff270();	// 0x6ff270
	void unknown6ef730();	// 0x6ef730
	void unknown6efb90();	// 0x6efb90
	void unknown6f1370();	// 0x6f1370
	void unknown6f1990();	// 0x6f1990
	void unknown6f1c70();	// 0x6f1c70
	void initialize701390(vector<int> &chosen);	// 0x701390
	void reinforce73d320(int a, int b, int c, const G8Point &p);	// 0x73d320
	G8HE placeEntity(G8Rec *rec, const G8Point &p, int a, int b, int c, int d, int e);	// 0x6c58c0
	void unknown6c65a0(G8HE e, const string &s, bool b);	// 0x6c65a0
	bool unknown736510(int a, const G8Point &p, const G8Area &area, int b, int c);	// 0x736510
	void unknown71ef30(const G8Point &p, int a);	// 0x71ef30
	G8HItem unknown6c5400(G8ItemDef *def, const G8Point &p);	// 0x6c5400
	G8ItemDef *selectRandomItem6c3bc0(int a, int b, int c);	// 0x6c3bc0
	G8HItem unknown71e7c0(const G8Point &p, int a, int b);	// 0x71e7c0
	void unknown72ec60();	// 0x72ec60
	int getTurn464270();	// 0x464270
	void unknown72e8e0(int a);	// 0x72e8e0
	bool unknown4631f0(G8HE e);	// 0x4631f0
	void routes6dd160();	// 0x6dd160
};

void g8_logInfo(string location, string message);	// 0x405090
void g8_logError(string location, string message);	// 0x404f10
bool g8_containsRecord(vector<int> &v, int x);	// 0x9db330
void g8_fn9d78c0(G8Strings &v, string s);	// 0x9d78c0
int g8_stringToInt(const string &s);	// 0x405610
bool g8_findTerrain(vector<G8Terrain *> &v, const string &name, G8Terrain *&out);	// 0x9db6a0
bool g8_findRec(vector<G8Rec *> &v, const string &name, G8Rec *&out);	// 0x9d7530
bool g8_findDef(vector<G8ItemDef *> &v, const string &name, G8ItemDef *&out);	// 0x9d7a40
void g8_eraseStep(vector<G8Point> &v, unsigned int &index);	// 0x9d7300
void g8_removePoint(vector<G8Point> &v, G8Point p);	// 0x9d3060
void g8_addUniquePoint(vector<G8Point> &v, G8Point p);	// 0x9dbce0
void g8_surrounding(const G8Point &p, vector<G8Point> &out);	// 0x4faaf0
bool g8_fn9d0ce0(vector<G8Point> &v, G8Point p);	// 0x9d0ce0
void g8_eraseAtP(vector<G8Point> &v, int index);	// 0x9d5190
G8Point g8_popRandomPoint(vector<G8Point> &v);	// 0x9dbc70
bool g8_terrainFlagB(const G8Point &p) throw();	// 0x448b80
bool g8_terrainFlagA(const G8Point &p);	// 0x448b60
G8Point g8_randomPoint(vector<G8Point> &v);	// 0x9d5350
int g8_randomRec(vector<int> &v);	// 0x9d5d00
int g8_randomIndex(vector<G8Point> &v);	// 0x9d9230
void g8_eraseAtS(vector<string> &v, int index);	// 0x9cfab0
bool g8_containsEntity(vector<G8HLocation> &v, G8HLocation h);	// 0x9d31e0
int g8_indexOfName(vector<G8Terrain *> &v, const string &name);	// 0x9d7b80
bool g8_fn9daf80(int a, int b, int c);	// 0x9daf80
int g8_distance(const G8Point &a, const G8Point &b);	// 0x40a3f0
void g8_insertAt(vector<const G8Ally *> &v, unsigned int index, const G8Ally *a);	// 0x9dbdc0
void g8_insertAtI(vector<int> &v, unsigned int index, int a);	// 0x9dbdc0
void g8_clearDijkstra();	// 0x4faf40
void g8_adjacent(const G8Point &p, vector<G8Point> &out);	// 0x4fab80
void g8_fn6c0f10(const G8Point &p, int a, int b);	// 0x6c0f10
void g8_clearObjects(vector<G8Obj *> *v);	// 0x9d0670
string g8_intToString(int v);	// 0x4051f0
void g8_removeElement(vector<int> &v, int index);	// 0x9de6f0
void g8_eraseAt(vector<int> &v, unsigned int &index);	// 0x9ce6d0
void g8_fn9d51d0(vector<int> &v, int a);	// 0x9d51d0
int g8_minInt(int a, int b);	// 0x9cdb30
void g8_shuffleStrings(vector<string> &v);	// 0x9db7e0
void g8_shuffleInts(vector<int> &v);	// 0x9d8f80
void g8_deleteObjectAndStep(vector<G8Spawn *> &v, unsigned int &index);	// 0x9dbd40
void g8_fn465b10();	// 0x465b10
int g8_fn9d4500(vector<int> &v);	// 0x9d4500
bool g8_fn9d85c0(float lo, float v, float hi);	// 0x9d85c0
bool g8_anyNonZero(int *v, int n);	// 0x9d3f40
void g8_moveElement(vector<G8HItem> &v, unsigned int from, int to);	// 0x9da1f0
void g8_logPhrase(int id, string *a, string *b, string *c, G8HE e, int f);	// 0x5141b0
#define G8_PHRASE(id,a) do { g8_logPhrase(id,a,0,0,G8HE(),0); } while (0)

extern G8HLocation g8_location_d1e888, g8_hloc_d1e884, g8_hloc_d1ebd8, g8_hloc_d1ebe4;
extern vector<G8HLocation> g8_hist_d1e88c;
extern int g8_caf130, g8_cefb30, g8_cebd64, g8_cec34c, g8_ced1c4, g8_cefb70, g8_cefcac, g8_cefdcc, g8_cf462c, g8_cf471c, g8_cf4724, g8_cf4740;
extern bool g8_cefb3c, g8_cefb3e, g8_cefacf, g8_cefafe, g8_cf4d17, g8_d1e880, g8_d1ebfc, g8_d25450, g8_d257e5, g8_d257ea, g8_d28de0;
extern vector<float> g8_cf4634;
extern vector<G8HItem> g8_cf4a38, g8_cf4a48;
extern vector<G8HE> g8_cf4aa8;
extern vector<int> g8_cf4ab8, g8_cf4b24, g8_d33a40, g8_d33a50, g8_d33a60, g8_used_d1e8ac;
extern G8Holder *g8_cf4ac8;
extern vector<vector<G8Point> > g8_markers_d02b4c;
extern vector<G8Point> g8_d15e58, g8_d29774, g8_d2c454;
extern vector<G8HLocation> g8_d1ea7c;
extern vector<string> g8_d1ea8c, g8_d33a70, g8_exitNames_d21768;
extern int g8_d1eac0, g8_d1ead0, g8_d1ead4, g8_d1ead8, g8_d1eb64, g8_d1eb68, g8_d257d0, g8_d257e0, g8_d2c46c, g8_d33a3c, g8_d33ad4, g8_diff_cf4718;
extern vector<vector<G8HProp> > g8_d20248;
extern G8Flags g8_flags_cf1080, g8_d2f75c;
extern G8Actor *g8_d338e0;
extern G8Ally g8_d338e4;
extern vector<vector<int> > g8_d33a80;
extern vector<G8ItemDef *> g8_defs_cfd2cc, g8_defs_d2d1c4;
extern vector<G8Dialog *> g8_dialogs_d2c408;
extern vector<G8Encounter> g8_encounters_cf13e8;
extern G8EventDef g8_events_b99d78[];
extern G8Factory *g8_factory_cefaa8;
extern G8GameData g8_gameData_d1e860;
extern G8Grid g8_genMap_cf1964;
extern G8Grid originalTerrain;
extern G8Gen g8_gen_d31580;
extern G8Cave g8_cave_d29268;
extern G8Carto g8_carto_cfe568;
extern G8Cells g8_cells_cfd44c;
extern G8ItemPool g8_itemPool_d2a298;
extern vector<G8Spawn *> g8_items_d3391c, g8_items_d3392c, g8_items_d3393c;
extern G8JLog *g8_jlog_cefa64;
extern vector<G8Link *> g8_links_cf4760;
extern G8Luigi g8_luigi_cebffc;
extern string g8_names_cf7670[], g8_objNames_d1ecd8[], g8_zoneNames_cfe140[];
extern G8Player g8_player_cf45d8;
extern G8Pool g8_pool_d2c41c;
extern G8PrefabList g8_prefabList_cf124c;
extern G8Strings g8_prefabs_d1e30c, g8_zones_cf123c;
extern G8Queue g8_queue_d225a0;
extern G8Point g8_range_d1d614, g8_range_d1ecb4, g8_range_d3172c, g8_range_d35bd8;
extern G8Point g8_ranges_d25874[], g8_ranges_d2d348[], g8_ranges_d37a00[];
extern vector<G8Rec *> g8_records_d25de0;
extern vector<G8Room> g8_rooms_cf126c;
extern G8Sound g8_sound_d2d2a0;
extern G8Stats g8_stats_d2c658;
extern G8Terrain *TERRAIN_EARTH, *TERRAIN_CAVE_WALL, *caveinThirdTerrain, *g8_floor_cefb9c, *g8_shortcut_cefba8, *g8_phasewall_cefbac, *g8_door_cefbb0;
extern G8Terrain *g8_t_cefb84, *g8_t_cefb88, *g8_t_cefb8c, *g8_t_cefb90, *g8_t_cefb94, *g8_t_cefb98;
extern vector<G8Terrain *> g8_terrains_cfb844;
extern G8Tutorial g8_tutorial_d25628;
extern vector<G8Challenge *> g8_challenges_cf1a04;
extern G8CMap *g8_cmap_cec054;
extern G8Area g8_area_d255bc;
extern G8AllyList g8_allies_d3394c[];
extern bool g8_b90158[], g8_b99d1c[], g8_caf1a4[];
extern bool g8_ba6650[][3];
extern int g8_b904a8[], g8_b90d70[], g8_b91068[], g8_b99b38[];
extern int g8_b94550[][15];
extern float g8_b90540[], g8_b91100[], g8_ba0498[], g8_ba65c0[];
extern float g8_ba32f4, g8_ba3664, g8_ba76cc, g8_ba76d4;
extern int g8_cost_cf672c, g8_cost_cefc30_obj, g8_cfe5e8, g8_d31660, g8_d2b4b8;
extern void *g8_cost_cefc30;

bool BS::initilize()
{
	int e22;
	int e10[0x26];
	G8Terrain *e19[0x26];
	G8Terrain *e28[0x26];
	G8Terrain *e31[0x26];
	G8Terrain *e18[0x26];
	G8Terrain *g13[0x26];
	G8Terrain *e0[0x26];
	G8Terrain *g18[0x26];
	G8Dims e21;
	G8Challenge *e3;
	int g30;
	bool e5;
	int e33;
	g8_logInfo("BS::initialize()","Initializing BattleScape");
	f2ac = 0;
	f320 = 0;
	f324 = 0;
	f3d4 = 0;
	f330.assign(0xdb,vector<G8HE>());
	f670.reset9b7270();
	fb80 = 0;
	e22 = g8_location_d1e888->depth;
	string g34;
	if (g8_caf130 == 7)
	{
		rng.seed(g8_location_d1e888->f1c);
		OpR5h_WL<int> pool;
		for (unsigned int k = 0; k < g8_challenges_cf1a04.size(); k++)
		{
			if (g8_challenges_cf1a04[k]->depth == e22 && (g8_challenges_cf1a04[k]->weight == 1000 || !g8_containsRecord(g8_used_d1e8ac,k)) && (g8_challenges_cf1a04[k]->fc == -1 || g8_challenges_cf1a04[k]->fc == g8_location_d1e888->f8) && (!g8_challenges_cf1a04[k]->b11 || g8_hist_d1e88c[g8_hist_d1e88c.size() - 2]->depth != 0x17))
				pool.add(k,g8_challenges_cf1a04[k]->weight);
		}
		e3 = 0;
		for (unsigned int k = 0; k < pool.getValues()->size(); k++)
		{
			if (g8_challenges_cf1a04[(*pool.getValues())[k]]->fc == g8_location_d1e888->f8)
			{
				e3 = g8_challenges_cf1a04[(*pool.getValues())[k]];
				break;
			}
		}
		if (e3 == 0)
			e3 = g8_challenges_cf1a04[pool.pick()];
		if (e3->weight != 1000)
			g8_used_d1e8ac.push_back(e3->id);
		if (e3->b11)
			g8_hloc_d1ebe4 = g8_location_d1e888;
		for (int k = 0; k < 0x26; k++)
		{
			e10[k] = g8_ranges_d2d348[k].randomInRange();
			switch (k)
			{
			case 7:
				if (e22 == 8)
					e10[k] = 2;
				break;
			case 0xf:
				if (e22 == 2)
					e10[k] = 0;
				break;
			case 0x10:
			case 0x11:
			case 0x12:
				switch (e22)
				{
				case 0x10:
				case 0x11:
				case 0x13:
					e10[k] = 1;
					break;
				case 0x14:
					e10[k] = 1;
					break;
				case 0x15:
				case 0x16:
					e10[k] = 1;
					break;
				case 0x17:
					e10[k] = 1;
					break;
				}
				break;
			}
		}
		g8_zones_cf123c.clear();
		if (g8_cefb30 == 0)
		{
			for (unsigned int k = 0; k < g8_location_d1e888->links.size(); k++)
			{
				if (!g8_location_d1e888->links[k]->inRange46ecb0())
				{
					for (int j = 0; j < e10[g8_location_d1e888->links[k]->depth]; j++)
						g8_zones_cf123c.push(g8_zoneNames_cfe140[g8_location_d1e888->links[k]->depth]);
				}
			}
		}
		g8_prefabs_d1e30c.clear();
		switch (e22)
		{
		case 7:
			if (g8_location_d1e888->find46ee80(8).isNull())
				g8_prefabs_d1e30c.push("MIN_00_EXI");
			break;
		case 8:
			for (int j = 0; j < 4; j++)
				g8_prefabs_d1e30c.push(g8_names_cf7670[j]);
			g8_fn9d78c0(g8_prefabs_d1e30c,g8_names_cf7670[g8_d1eac0]);
			break;
		case 0x1a:
			g8_prefabs_d1e30c.pushMove(g8_stringToInt(g8_gameData_d1e860.getEntryText("zhirovInHideout_g")) ? "ARC_00_zhirov_HUB" : "ARC_00_nozhirov_HUB");
			break;
		case 0x1e:
		case 0x1f:
			if (g8_location_d1e888->find46ee80(0x20).isNull())
				g8_prefabs_d1e30c.push("TES_00_main_SEC");
			break;
		}
		if (g8_cefb30 != 0)
			rng.seed(g8_cefb30);
		if (e22 == 1)
		{
			if (g8_tutorial_d25628.unknown7784b0())
			{
				g8_d257d0++;
				g8_gameData_d1e860.setEntryText("tutorialRun_g","1");
			}
			else
				g8_gameData_d1e860.setEntryText("tutorialRun_g","0");
		}
		while (true)
		{
			int attempts = 0;
			if (g8_b90158[e22])
			{
				do
				{
					g8_cave_d29268.init4c9d80(e3->f14,"","",0,1,0,-1);
					g8_cave_d29268.step4cbcd0(0);
					attempts++;
					if (false) {}
					if (false) {}
					if (!g8_cave_d29268.getField449500())
					{
						switch (e22)
						{
						case 0x23:
							{
								G8Point target(-1);
								for (unsigned int k = 0; k < g8_prefabList_cf124c.size(); k++)
								{
									if (g8_prefabList_cf124c[k].f48 == g8_d33ad4)
									{
										target.set40a060(g8_prefabList_cf124c[k].f50,8,8);
										break;
									}
								}
								if (target.x != -1)
								{
									G8Carto g22(g8_genMap_cf1964.getWidth(),g8_genMap_cf1964.getHeight());
									vector<G8Point> e4;
									if (!g22.findPath(g8_markers_d02b4c[1][0],target,&g8_cost_cf672c,0,e4))
										g8_cave_d29268.resetField449520();
								}
							}
							break;
						}
					}
				} while (g8_cave_d29268.getField449500());
			}
			else
			{
				int mode = -1;
				switch (e22)
				{
				case 1:
					mode = g8_tutorial_d25628.unknown7784b0() ? 1 : 2;
				}
				do
				{
					g8_gen_d31580.init4bf610(e3->f18,"","",0,1,0,mode);
					g8_gen_d31580.placeTunnelers4c15a0();
					g8_gen_d31580.generate4c1880(0);
					attempts++;
				} while (g8_gen_d31580.getField449000());
				if (e22 == 0xd || e22 == 0xb)
					fae0 = g8_gen_d31580.traceRooms4c7950();
				if (g8_cf462c == 6)
					g8_gen_d31580.finalizeWalls4c7420();
			}
			break;
		}
	}
	if (g8_caf130 == 6)
	{
		e21.x = 0x32;
		e21.y = 0x12c;
	}
	else
	{
		e21.x = g8_genMap_cf1964.getWidth();
		e21.y = g8_genMap_cf1964.getHeight();
	}
	g8_carto_cfe568.resize40cec0(e21.x,e21.y);
	g8_carto_cfe568.setField40c980(1);
	g8_queue_d225a0.clear9c05e0();
	if (g8_caf130 == 6)
		f65c = g8_queue_d225a0.add672310(new G8Turn(0,new G8Actor),0);
	else
	{
		f65c = g8_queue_d225a0.add672310(new G8Turn(0,g8_location_d1e888 == g8_hloc_d1e884 ? new G8Actor : g8_d338e0),0);
		g8_d338e0 = 0;
	}
	if (g8_location_d1e888 == g8_hloc_d1e884)
	{
		g8_flags_cf1080.start511440(g8_cebd64,0);
		g8_d2f75c.start511440(g8_cebd64,1);
	}
	g8_pool_d2c41c.initialize460510();
	g8_cells_cfd44c.resize9d4090(e21.x,e21.y,0);
	g8_cells_cfd44c.zero9d23e0();
	originalTerrain.resize9d4090(e21.x,e21.y,0);
	originalTerrain.zero9d23e0();
	g8_cec34c = g8_ced1c4;
	f34 = 0;
	if (!g8_findTerrain(g8_terrains_cfb844,string("EARTH"),TERRAIN_EARTH)) ;
	if (!g8_findTerrain(g8_terrains_cfb844,string("EARTH_EXC"),g8_t_cefb84)) ;
	if (!g8_findTerrain(g8_terrains_cfb844,string("GROUND"),g8_t_cefb88)) ;
	if (!g8_findTerrain(g8_terrains_cfb844,string("TEMP_WALL"),g8_t_cefb8c)) ;
	if (!g8_findTerrain(g8_terrains_cfb844,string("SEALED_DOOR"),g8_t_cefb90)) ;
	if (!g8_findTerrain(g8_terrains_cfb844,string("SHORTCUT_KNOWN"),g8_t_cefb94)) ;
	if (!g8_findTerrain(g8_terrains_cfb844,string("PHASEWALL_KNOWN"),g8_t_cefb98)) ;
	f118.assign(9,vector<G8Point>());
	f128.assign(9,vector<G8Point>());
	if (g8_hist_d1e88c.size() == 1 || g8_hist_d1e88c.back()->rating46ed20() != g8_hist_d1e88c[g8_hist_d1e88c.size() - 2]->rating46ed20())
		g8_cf4b24.assign(g8_records_d25de0.size(),0);
	for (int k = 0; k < 0x26; k++)
		g8_findTerrain(g8_terrains_cfb844,"FLOOR_" + g8_zoneNames_cfe140[k],e19[k]);
	for (int k = 0; k < 0x26; k++)
		g8_findTerrain(g8_terrains_cfb844,"WALL_" + g8_zoneNames_cfe140[k],e28[k]);
	for (int k = 0; k < 0x26; k++)
		g8_findTerrain(g8_terrains_cfb844,"BARRIER_" + g8_zoneNames_cfe140[k],e31[k]);
	for (int k = 0; k < 0x26; k++)
		g8_findTerrain(g8_terrains_cfb844,"SHORTCUT_" + g8_zoneNames_cfe140[k],e18[k]);
	for (int k = 0; k < 0x26; k++)
		g8_findTerrain(g8_terrains_cfb844,"PHASEWALL_" + g8_zoneNames_cfe140[k],g13[k]);
	for (int k = 0; k < 0x26; k++)
		g8_findTerrain(g8_terrains_cfb844,"DOOR_" + g8_zoneNames_cfe140[k],e0[k]);
	for (int k = 0; k < 0x26; k++)
		g8_findTerrain(g8_terrains_cfb844,"STAIRS_" + g8_zoneNames_cfe140[k],g18[k]);
	g8_floor_cefb9c = e19[e22];
	TERRAIN_CAVE_WALL = e28[e22];
	caveinThirdTerrain = e31[e22];
	g8_shortcut_cefba8 = e18[e22];
	g8_phasewall_cefbac = g13[e22];
	g8_door_cefbb0 = e0[e22];
	if (g8_cefb3c)
		g8_t_cefb88->color = g8_cefdcc;
	if (g8_caf130 == 6)
	{
	}
	else
	{
		G8Grid *e56 = &originalTerrain;
		int e15 = TERRAIN_EARTH->id;
		int rb34 = g8_t_cefb84->id;
		int e48 = g8_floor_cefb9c->id;
		int e16 = TERRAIN_CAVE_WALL->id;
		int e44 = caveinThirdTerrain->id;
		int m59 = g8_shortcut_cefba8->id;
		int g48 = g8_phasewall_cefbac->id;
		int g46 = g8_door_cefbb0->id;
		int m7 = g18[e22]->id;
		for (int x = 0; x < e21.x; x++)
		{
			for (int y = 0; y < e21.y; y++)
			{
				switch (*g8_genMap_cf1964.at(x,y))
				{
				case 0:
				case 1:
				case 2:
				case 3:
					*e56->at(x,y) = e15;
					break;
				case 0xa:
				case 0xb:
					*e56->at(x,y) = g46;
					break;
				case 0xc:
				case 0xd:
					*e56->at(x,y) = m59;
					break;
				case 0xe:
				case 0xf:
					*e56->at(x,y) = g48;
					break;
				default:
					*e56->at(x,y) = e48;
					break;
				}
			}
		}
		if (e22 == 0x18)
		{
			for (int y = 0x23; y < 0x2c; y++)
			{
				*e56->at(0xbd,y) = e48;
				*e56->at(0xa,y) = e48;
			}
		}
		vector<G8Point> h37;
		for (int x = 0; x < e21.x; x++)
		{
			for (int y = 0; y < e21.y; y++)
			{
				if (*e56->at(x,y) == e15)
				{
					if (x - 1 >= 0)
					{
						if (*e56->at(x - 1,y) != e15)
							goto addEdge;
						if (y - 1 >= 0 && *e56->at(x - 1,y - 1) != e15)
							goto addEdge;
						if (y + 1 < e21.y && *e56->at(x - 1,y + 1) != e15)
							goto addEdge;
					}
					if (x + 1 < e21.x)
					{
						if (*e56->at(x + 1,y) != e15)
							goto addEdge;
						if (y - 1 >= 0 && *e56->at(x + 1,y - 1) != e15)
							goto addEdge;
						if (y + 1 < e21.y && *e56->at(x + 1,y + 1) != e15)
							goto addEdge;
					}
					if (y - 1 >= 0 && *e56->at(x,y - 1) != e15)
						goto addEdge;
					if (y + 1 < e21.y && *e56->at(x,y + 1) != e15)
						goto addEdge;
					continue;
addEdge:
					h37.push_back(G8Point(x,y));
				}
			}
		}
		if (e22 == 0x14)
		{
			for (unsigned int k = 0; k < h37.size(); k++)
			{
				if (h37[k].x >= 0x65)
				{
					*e56->atPoint(h37[k]) = e16;
					g8_eraseStep(h37,k);
				}
			}
			vector<G8Rect> g45;
			g45.push_back(G8Rect(0x2d,0x2d,0x28,3));
			g45.push_back(G8Rect(0x2d,0x52,0x28,3));
			g45.push_back(G8Rect(0x2d,0x30,3,0x22));
			g45.push_back(G8Rect(0x53,0x30,3,0x22));
			for (unsigned int k = 0; k < g45.size(); k++)
			{
				for (int x = g45[k].x; x <= g45[k].right40ac20(); x++)
				{
					for (int y = g45[k].y; y <= g45[k].bottom40ac40(); y++)
					{
						*e56->at(x,y) = e48;
						g8_removePoint(h37,G8Point(x,y));
					}
				}
			}
			vector<G8Rect> e20;
			e20.push_back(G8Rect(0x2c,0x2c,0x2a,1));
			e20.push_back(G8Rect(0x2c,0x56,0x2a,1));
			e20.push_back(G8Rect(0x2c,0x2d,1,0x28));
			e20.push_back(G8Rect(0x57,0x2d,1,0x28));
			e20.push_back(G8Rect(0x31,0x31,0x25,1));
			e20.push_back(G8Rect(0x31,0x51,0x25,1));
			e20.push_back(G8Rect(0x31,0x32,1,0x25));
			e20.push_back(G8Rect(0x52,0x32,1,0x25));
			for (unsigned int k = 0; k < e20.size(); k++)
			{
				for (int x = e20[k].x; x <= e20[k].right40ac20(); x++)
				{
					for (int y = e20[k].y; y <= e20[k].bottom40ac40(); y++)
					{
						if (*e56->at(x,y) == e15)
							g8_addUniquePoint(h37,G8Point(x,y));
					}
				}
			}
			for (unsigned int k = 0; k < h37.size(); k++)
				*e56->atPoint(h37[k]) = e48;
			vector<G8Point> e7;
			vector<G8Point> e46;
			for (int pass = 0; pass < 2; pass++)
			{
				int chance = (pass + 1) * 10;
				for (int k = h37.size() - 1; k >= 0; k--)
				{
					e7.clear();
					g8_surrounding(h37[k],e7);
					for (unsigned int j = 0; j < e7.size(); j++)
					{
						if (*e56->atPoint(e7[j]) == e15 && rng.chance(chance) && !g8_fn9d0ce0(h37,e7[j]))
						{
							*e56->atPoint(e7[j]) = e48;
							h37.push_back(e7[j]);
						}
					}
				}
			}
			G8Grid e27(e56->getWidth(),e56->getHeight(),-1);
			for (unsigned int k = 0; k < g8_rooms_cf126c.size(); k++)
			{
				vector<G8Point> *cells = &g8_rooms_cf126c[k].cells;
				for (unsigned int j = 0; j < cells->size(); j++)
					*e27.atPoint((*cells)[j]) = k;
			}
			for (unsigned int k = 0; k < g8_rooms_cf126c.size(); k++)
			{
				vector<G8Point> *cells = &g8_rooms_cf126c[k].cells;
				for (int pass = 0; pass < 3; pass++)
				{
					for (int j = cells->size() - 1; j >= 0; j--)
					{
						e7.clear();
						g8_surrounding((*cells)[j],e7);
						for (unsigned int i = 0; i < e7.size(); i++)
						{
							if (*e27.atPoint(e7[i]) == -1 && g8_fn9d0ce0(h37,e7[i]))
							{
								cells->push_back(e7[i]);
								*e27.atPoint(e7[i]) = k;
								break;
							}
						}
					}
				}
			}
			for (int k = h37.size() - 1; k >= 0; k--)
			{
				e7.clear();
				g8_surrounding(h37[k],e7);
				for (unsigned int j = 0; j < e7.size(); j++)
				{
					if (*e56->atPoint(e7[j]) == e15)
						*e56->atPoint(e7[j]) = e16;
				}
			}
		}
		else
		{
			for (unsigned int k = 0; k < h37.size(); k++)
				*e56->atPoint(h37[k]) = e16;
		}
		for (int x = 0; x < e21.x; x++)
		{
			for (int y = 0; y < e21.y; y++)
			{
				switch (*g8_genMap_cf1964.at(x,y))
				{
				case 1:
					*e56->at(x,y) = rb34;
					break;
				case 2:
					*e56->at(x,y) = e44;
					if (e22 == 0x14)
						g8_removePoint(h37,G8Point(x,y));
					break;
				}
			}
		}
		if (e22 == 1)
		{
			G8Rect g49;
			G8Rect g51(-1,-1,0,0);
			if (g8_tutorial_d25628.unknown7784b0())
				g49.set40a840(0x28,0x28,0x15,0x15);
			else
			{
				g49.set40a840(0x28,0x2e,0x15,9);
				for (unsigned int k = 0; k < g8_prefabList_cf124c.size(); k++)
				{
					if (g8_prefabList_cf124c[k].f4c == g8_cefcac)
					{
						g51.set40a870(g8_prefabList_cf124c[k].f50,g8_prefabList_cf124c[k].layers.front()->getWidth(),g8_prefabList_cf124c[k].layers.front()->getHeight());
						break;
					}
				}
			}
			for (int x = 0; x < e21.x; x++)
			{
				for (int y = 0; y < e21.y; y++)
				{
					if (!g49.contains(x,y) && (g51.x == -1 || !g51.contains(x,y)))
					{
						if (*e56->at(x,y) == e48 || *e56->at(x,y) == g46)
							*e56->at(x,y) = rb34;
						else if (*e56->at(x,y) == e16 || *e56->at(x,y) == e44)
							*e56->at(x,y) = e15;
					}
					else
					{
						if (*e56->at(x,y) == e16)
							*e56->at(x,y) = e15;
					}
				}
			}
		}
		G8Point k37(-1);
		if (unknown73cfb0())
		{
			vector<G8Point> *list = 0;
			if (!g8_markers_d02b4c[1].empty())
				list = &g8_markers_d02b4c[1];
			else if (!g8_markers_d02b4c[0].empty())
				list = &g8_markers_d02b4c[0];
			if (list != 0)
			{
				int best = 0;
				for (unsigned int k = 1; k < list->size(); k++)
				{
					if (list->at(k).x < list->at(best).x)
						best = k;
				}
				k37 = list->at(best);
				g8_eraseAtP(*list,best);
			}
		}
		if (k37.x == -1)
		{
			if (!g8_markers_d02b4c[1].empty())
				k37 = g8_popRandomPoint(g8_markers_d02b4c[1]);
			else if (!g8_markers_d02b4c[0].empty())
				k37 = g8_popRandomPoint(g8_markers_d02b4c[0]);
		}
		vector<int> m16;
		m16.push_back(0x13);
		m16.push_back(0x12);
		m16.push_back(0x10);
		vector<int> g17;
		g17.push_back(0x14);
		g17.push_back(0x12);
		g17.push_back(0x10);
		G8HLocation m24;
		if (g8_location_d1e888->inRange46ecb0())
		{
			for (unsigned int k = 0; k < g8_location_d1e888->links.size(); k++)
			{
				if (g8_location_d1e888->links[k]->inRange46ecb0())
				{
					m24 = g8_location_d1e888->links[k];
					break;
				}
			}
			int remaining = g8_b904a8[e22];
			for (unsigned int k = 0; k < m16.size(); k++)
			{
				while (remaining != 0 && !g8_markers_d02b4c[m16[k] - 0x10].empty())
				{
					G8Point p = g8_popRandomPoint(g8_markers_d02b4c[m16[k] - 0x10]);
					f10.push_back(new G8Marker(p,m24,g8_terrainFlagB(p),G8HE(),G8HE()));
					*e56->atPoint(f10.back()->pos) = m7;
					remaining--;
				}
			}
			while (remaining != 0)
			{
				G8Point p = unknown6c2230(m24->depth);
				f10.push_back(new G8Marker(p,m24,g8_terrainFlagB(p),G8HE(),G8HE()));
				*e56->atPoint(p) = m7;
				remaining--;
			}
		}
		if (e22 == 0xd)
		{
			g8_location_d1e888->links.size();
			for (unsigned int k = 0; k < g8_markers_d02b4c[0].size(); k++)
			{
				G8Point p(g8_markers_d02b4c[0][k]);
				f10.push_back(new G8Marker(p,g8_location_d1e888->links.front(),g8_terrainFlagB(p),G8HE(),G8HE()));
				*e56->atPoint(p) = m7;
			}
		}
		else if (e22 == 0xe)
		{
			g8_location_d1e888->links.size();
			G8Point p = g8_randomPoint(g8_markers_d02b4c[0]);
			f10.push_back(new G8Marker(p,g8_location_d1e888->links.front(),g8_terrainFlagB(p),G8HE(),G8HE()));
			*e56->atPoint(p) = m7;
		}
		else
		{
			for (unsigned int k = 0; k < g8_location_d1e888->links.size(); k++)
			{
				if (m24.isNull() || g8_location_d1e888->links[k] != m24)
				{
					bool h49 = g8_location_d1e888->links[k]->inRange46ecb0();
					vector<int> &h59 = h49 ? m16 : g17;
					int g0 = g8_location_d1e888->links[k]->inRange46ecb0() ? g8_b904a8[e22] : e10[g8_location_d1e888->links[k]->depth];
					while (g0 != 0)
					{
						bool placed = false;
						for (unsigned int j = 0; j < h59.size(); j++)
						{
checkKind:
							if (!placed && !g8_markers_d02b4c[h59[j] - 0x10].empty())
							{
								int k24 = -1;
								if (h59[j] == 0x14)
								{
									vector<int> matches;
									for (int i = 0; i < g8_exitNames_d21768.size(); i++)
									{
										if (g8_exitNames_d21768[i] == g8_zoneNames_cfe140[g8_location_d1e888->links[k]->depth])
											matches.push_back(i);
									}
									if (!matches.empty())
										k24 = g8_randomRec(matches);
									else
									{
										vector<int> blanks;
										for (int i = 0; i < g8_exitNames_d21768.size(); i++)
										{
											if (g8_exitNames_d21768[i].empty())
												blanks.push_back(i);
										}
										if (!blanks.empty())
											k24 = g8_randomRec(blanks);
										else
											break;
									}
								}
								else
									k24 = g8_randomIndex(g8_markers_d02b4c[h59[j] - 0x10]);
								G8Point g14(g8_markers_d02b4c[h59[j] - 0x10][k24]);
								g8_eraseAtP(g8_markers_d02b4c[h59[j] - 0x10],k24);
								if (h59[j] == 0x14)
									g8_eraseAtS(g8_exitNames_d21768,k24);
								f10.push_back(new G8Marker(g14,g8_location_d1e888->links[k],g8_terrainFlagB(g14),G8HE(),G8HE()));
								*e56->atPoint(g14) = m7;
								placed = true;
								if (g8_b90158[e22])
								{
									for (int i = 0; i < g8_rooms_cf126c.size(); i++)
									{
										if (g8_fn9d0ce0(g8_rooms_cf126c[i].cells,g14))
										{
											fc58.push_back(i);
											break;
										}
									}
								}
								goto checkKind;
							}
						}
						if (!placed)
						{
							G8Point p;
							if (g8_b90158[e22])
							{
								bool k27 = false;
								int k30;
								if (g8_location_d1e888->links[k]->inRange46ecb0() && (e22 == 0x10 || e22 == 0x11) && !g8_hist_d1e88c[g8_hist_d1e88c.size() - 2]->inRange46ecb0() && g8_location_d1e888->f20 != 2)
									k27 = true;
								p = unknown6c2b60(k27,g8_location_d1e888->f20,&k30);
							}
							else
								p = unknown6c2230(g8_location_d1e888->links[k]->depth);
							f10.push_back(new G8Marker(p,g8_location_d1e888->links[k],g8_terrainFlagB(p),G8HE(),G8HE()));
							*e56->atPoint(p) = m7;
						}
						g0--;
					}
				}
			}
		}
		f10.empty();
		if (false) {}
		int rb38 = -1;
		if (k37.x == -1)
		{
			if (g8_b90158[e22])
				k37 = unknown6c2b60(true,g8_location_d1e888->f20,&rb38);
			else
				k37 = unknown6c2230(0x27);
		}
		f8 = k37;
		for (int x = 0; x < e21.x; x++)
		{
			for (int y = 0; y < e21.y; y++)
			{
				*g8_cells_cfd44c.at(x,y) = new G8Cell(g8_terrains_cfb844[*e56->at(x,y)]);
				(*g8_cells_cfd44c.at(x,y))->setPos45dea0(x,y);
			}
		}
		if (e22 == 0x14)
		{
			unknown6c38a0(G8Rect(1,1,0x64,g8_cells_cfd44c.getHeight() - 2),0,1.0f,g8_d2c46c);
			unknown6c38a0(G8Rect(0x64,1,g8_cells_cfd44c.getWidth() - 0x66,g8_cells_cfd44c.getHeight() - 2),0,g8_b90540[e22],g8_d2c46c);
		}
		else
			unknown6c38a0(G8Rect(1,1,g8_cells_cfd44c.getWidth() - 2,g8_cells_cfd44c.getHeight() - 2),0,g8_b90540[e22],g8_d2c46c);
		g8_d29774.clear();
		g8_d2c454.clear();
		f48.reset9b7270();
		for (int k = 0; k < 15; k++)
			f4c.push_back(g8_factory_cefaa8->createF793410(new G8Region(k)));
		f5c.resize9d4090(15,15,0);
		for (int k50 = 0, g25 = 0; k50 < 15; k50++, g25++)
		{
			for (int k = g25; k < 15; k++)
				*f5c.at(k50,k) = *f5c.at(k,k50) = g8_b94550[k50][k];
		}
		if (g8_location_d1e888 == g8_hloc_d1e884)
		{
			G8Rec *rec;
			g8_findRec(g8_records_d25de0,"Cogmind",rec);
			f66c = g8_factory_cefaa8->createEntity793200(rec);
			f66c->changePos5dccb0(k37,0);
			f4c[0]->addMember671280(f66c,1);
			g8_queue_d225a0.add672310(new G8Turn(1,new G8Actor2(f66c)),0);
		}
		else
		{
			f66c = unknown6c5e20(&g8_d338e4,k37,0,1,0,0);
			g8_d338e4.unknown46e740();
			if (f66c->unknown448fe0(3) >= 7)
				g8_player_cf45d8.unknown77fbc0(0x8b);
			for (unsigned int k = 0; k < g8_links_cf4760.size(); k++)
			{
				g8_links_cf4760[k]->h0 = g8_links_cf4760[k]->e8->handle45a260();
				g8_links_cf4760[k]->h4 = g8_links_cf4760[k]->ec->handle45a260();
				g8_links_cf4760[k]->e8 = 0;
				g8_links_cf4760[k]->ec = 0;
			}
		}
		unknown6c3a50(f68,0,0);
		unknown6c3a50(f8c,1,0);
		unknown6c4fd0();
		fb0.assign(g8_defs_d2d1c4.size(),0);
		fe4.assign(g8_records_d25de0.size(),0);
		fb4c.reset9c07a0();
		for (unsigned int k = 0; k < g8_prefabList_cf124c.size(); k++)
			unknown6cd110(g8_prefabList_cf124c[k],0x12f,0,0);
		f8c4 = 0xf;
		f8cc.set40b300(0,0,0,0);
		f8fc = -1;
		f900 = -1;
		f924.set40b300(0,0,0,0);
		f934.set40b300(0,0,0,0);
		f944.set40b300(0,0,0,0);
		f954.set40b300(0,0,0,0);
		b964 = false;
		f968 = 0;
		f98c = 0;
		b9a0 = false;
		fc18.clear();
		fc28.clear();
		vector<int> e50;
		if (g8_b90158[e22])
		{
			vector<int> g42;
			if (e22 != 0xf)
				rb38 = -1;
			for (int k = 0; k < g8_rooms_cf126c.size(); k++)
			{
				if (g8_rooms_cf126c[k].b45 || k == rb38)
					continue;
				else
					g42.push_back(k);
			}
			vector<G8Rect> g44;
			vector<bool> k51;
			vector<int> g57;
			placeRandomEncounter(g42,g44,k51,g57);
			if (!unknown6de330())
				return false;
			carvePaths700e30();
			switch (e22)
			{
			case 8:
				unknown6de850();
				g8_d257e5 = true;
				break;
			case 0x10:
			case 0x11:
			case 0x12:
				populate6dfdb0();
				break;
			case 0x14:
				populate6e0eb0(h37,g44,k51);
				break;
			case 0x15:
				g8_d257ea = true;
				break;
			case 0x23:
				setupArchitect6e2110();
				break;
			case 0x24:
				unknown6ed450();
				break;
			}
		}
		else
		{
			int range = 1;
			g8_carto_cfe568.unknown40ca20(k37,0x14,&g8_d2b4b8,&range);
			unknown6d4c00(e50);
			if (!unknown6de330())
				return false;
			switch (e22)
			{
			case 1:
				unknown6e2b40();
				break;
			case 2:
				unknown6fd470();
				break;
			case 3:
				unknown6eeaf0();
				break;
			case 0xc:
				unknown6fdcb0();
				break;
			case 0xd:
				garrison6ff590();
				postprocessGarrison6e4dc0();
				break;
			case 0xe:
				dsf6e68d0();
				break;
			case 0xa:
				unknown6e2cb0();
				break;
			case 0xb:
				populate6e3c30();
				break;
			case 0x18:
				init6e9270();
				break;
			case 0x19:
				unknown6e9480();
				break;
			case 0x17:
				init6e9570();
				break;
			case 0x1c:
				unknown6ea660();
				break;
			case 0x1e:
			case 0x1f:
				unknown6eab60();
				break;
			case 0x21:
				factory6ead20();
				break;
			case 0x22:
				unknown6ed0b0();
				break;
			case 0x25:
				setup6ed7d0();
				break;
			}
		}
		if (g8_containsEntity(g8_d1ea7c,g8_location_d1e888))
			g8_location_d1e888->b2d = true;
		g8_prefabList_cf124c.clear();
		g8_d1ea7c.clear();
		g8_d1ea8c.clear();
		int rb4 = 0;
		for (unsigned int k = 0; k < f4c.size(); k++)
			rb4 += f4c[k]->members416f40()->size();
		if (g8_gameData_d1e860.hasAnyObjects46f9f0())
		{
			for (int k = 0; k < 4; k++)
			{
				if (g8_gameData_d1e860.hasObjectID46fa40(k))
					unknown6c6b90(f66c->getPosition(),g8_objNames_d1ecd8[k],0,-1);
			}
		}
		for (unsigned int k = 0; k < f10.size(); k++)
		{
			if (g8_ba6650[f10[k]->loc->depth][g8_diff_cf4718])
			{
				int noAccess = g8_indexOfName(g8_terrains_cfb844,"STAIRS_NOACCESS");
				(*g8_cells_cfd44c.atPoint(f10[k]->pos))->unknown66a050(noAccess,2,0);
			}
			else if (f10[k]->f1c == 4)
			{
				int blocked = g8_indexOfName(g8_terrains_cfb844,"STAIRS_BLOCKED");
				(*g8_cells_cfd44c.atPoint(f10[k]->pos))->unknown66a050(blocked,2,0);
			}
		}
		if (f118[5].size() > 1 && e22 == 3 && f234.isNull() && g8_cf4740 == 0 && rng.chance(3))
		{
			OpR5h_WL<int> events;
			for (int k = 0; k < 3; k++)
			{
				if (g8_fn9daf80(g8_events_b99d78[k].f0,g8_location_d1e888->f8,g8_events_b99d78[k].f4))
					events.add(k,g8_events_b99d78[k].f8);
			}
			if (events.size())
			{
				f234 = (*g8_cells_cfd44c.atPoint(g8_randomPoint(f118[5])))->getProp();
				f238 = events.pick();
				f23c = g8_events_b99d78[f238].f10;
				f240 = 0;
				f254 = 0;
			}
		}
		b30 = false;
		G8HLocation q10;
		vector<G8HProp> g5;
		if (!g8_cefafe)
		{
			for (unsigned int k = 0; k < g8_d20248.size(); k++)
			{
				if (!g8_d20248[k].empty() && g8_d20248[k].front()->def9b8f00()->f140 == 0xe)
				{
					G8HLocation loc = g8_factory_cefaa8->createB793120();
					loc->init46eb70(0xc,g8_location_d1e888->f8,8,0);
					g8_location_d1e888->links.push_back(loc);
					if (q10.isNull())
					{
						q10 = g8_factory_cefaa8->createB793120();
						q10->init46eb70(e22,g8_location_d1e888->f8,8,0);
						q10->links = g8_location_d1e888->links;
					}
					loc->links.push_back(q10);
					f20.push_back(new G8Branch(k,loc));
					g5.push_back(g8_d20248[k].front());
				}
			}
		}
		for (unsigned int k = 0; k < f10.size(); k++)
		{
			if ((*g8_cells_cfd44c.atPoint(f10[k]->pos))->isMachinePart45dcd0() && !f10[k]->loc->inRange46ecb0() && f10[k]->loc->b25)
				(*g8_cells_cfd44c.atPoint(f10[k]->pos))->unknown66b640();
		}
		if (!g5.empty() && g8_gameData_d1e860.unknown46f4b0(1))
		{
			bool k57 = false;
			vector<G8HE> *h16 = f4c[4]->members416f40();
			for (unsigned int k = 0; k < h16->size(); k++)
			{
				if ((*h16)[k]->getFaction() == 1 && (*h16)[k]->getTarget45a760() == 0 && (!k57 || rng.chance(10)))
				{
					vector<G8Point> path;
					for (unsigned int j = 0; j < g5.size(); j++)
					{
						if (unknown7168e0((*h16)[k]->getPosition(),g5[j]->pos4184d0(),(*h16)[k].operator->(),path))
						{
							k57 = true;
							b30 = true;
							unknown6c6450((*h16)[k],1);
							break;
						}
					}
				}
			}
		}
		for (unsigned int k = 0; k < f118.size(); k++)
		{
			if (g8_b99d1c[k])
			{
				for (unsigned int j = 0; j < f118[k].size(); j++)
				{
					if ((*g8_cells_cfd44c.atPoint(f118[k][j]))->getProp()->machine45cb30()->unknown45c1c0(5) != 0)
					{
						f158.push_back(f118[k][j]);
						f168.push_back(0x27);
					}
					else
					{
						G8RecList *list = (*g8_cells_cfd44c.atPoint(f118[k][j]))->getProp()->unknown45c9b0();
						if (list != 0)
						{
							G8Data *data = list->getDataOfType4564e0(0x38);
							if (data != 0 && data->hasData4560d0(0xe))
							{
								f158.push_back(f118[k][j]);
								f168.push_back(data->f70);
							}
						}
					}
				}
			}
		}
		f534 = 0;
		b558 = false;
		b559 = false;
		if (g8_b90d70[e22] != 0)
		{
			int m14 = g8_b90d70[e22];
			const int h2 = 50;
			while (m14 != 0)
			{
				G8Point p;
				for (int t = 0; t < h2; t++)
				{
					g8_cells_cfd44c.getRandom9cf0c0(p);
					if (findPlaceableNear71c150(p,p,1) && !g8_terrainFlagB(p))
					{
						if (t < 25)
						{
							bool near = false;
							for (unsigned int j = 0; j < f538.size(); j++)
							{
								if (g8_distance(p,f538[j]) <= 20)
								{
									near = true;
									break;
								}
							}
							if (near)
								continue;
						}
						vector<G8Point> path;
						if (!g8_carto_cfe568.findPath(f66c->getPosition(),p,g8_cost_cefc30,0,path))
							continue;
						f538.push_back(p);
						f548.push_back(0);
						break;
					}
				}
				m14--;
			}
		}
		f55c = 0;
		g8_player_cf45d8.unknown46df70();
		g8_d1eb64 = 0;
		f520 = rng.rangeInt(5,10);
		f570 = g8_b91068[e22];
		f5b4 = e22 == 0x22 ? -1 : g8_range_d1ecb4.randomInRange();
		f5b8 = 0;
		f108.assign(5,vector<G8Point>());
		G8Noise q57;
		q57.init421680(2,0,0);
		q57.set450460(8);
		float rc1 = g8_b91100[e22];
		int e47;
		int e54[1];
		char h27[4];
		int g50;
		for (int x = 0; x < e21.x; x++)
		{
			for (int y = 0; y < e21.y; y++)
			{
				e47 = (*g8_cells_cfd44c.at(x,y))->unknown66afe0();
				if (e47 != 0 || q57.sampleFbmXY421820(x,y) >= rc1)
				{
					g50 = g8_ranges_d25874[e47].randomInRange();
					(*g8_cells_cfd44c.at(x,y))->set45b090(g50);
					f108[rng.rangeInt(0,4)].push_back(G8Point(x,y));
				}
			}
		}
		routes6dd160();
		fa90.clear();
		faa0.clear();
		fab0.clear();
		if (g8_cf462c == 9)
		{
			int rating = g8_gameData_d1e860.unknown46f4e0();
			for (int k = 0; k < g8_defs_cfd2cc.size(); k++)
			{
				if (g8_defs_cfd2cc[k]->f28 >= 0 && g8_defs_cfd2cc[k]->f28 <= rating)
					fb94.push_back(k);
			}
		}
		vector<G8Point> q19;
		g8_cells_cfd44c.getNeighbors9ce500(f8,q19);
		for (unsigned int k = 0; k < q19.size(); k++)
		{
			if ((*g8_cells_cfd44c.atPoint(q19[k]))->unknown45db70())
				(*g8_cells_cfd44c.atPoint(q19[k]))->unknown66a050(g8_floor_cefb9c->id,2,0);
		}
		for (unsigned int k = 0; k < g8_items_d3391c.size(); k++)
		{
			G8Point p;
			if (unknown71bc10(f8,p))
			{
				G8HItem item = g8_itemPool_d2a298.add9d1b20(g8_items_d3391c[k]);
				item->unknown4582d0(item);
				item->unknown57a0f0(p,0,0);
				unknown464f60(item);
				unknown465060(item);
			}
			else
				g8_deleteObjectAndStep(g8_items_d3391c,k);
		}
		g8_items_d3391c.clear();
		f66c->unknown5e2b50();
		for (unsigned int k = 0; k < g8_items_d3392c.size(); k++)
		{
			G8HItem item = g8_itemPool_d2a298.add9d1b20(g8_items_d3392c[k]);
			item->unknown4582d0(item);
			unknown464f60(item);
			unknown465060(item);
			g8_cf4a38.push_back(item);
			if (item->unknown571d70())
				g8_queue_d225a0.add672310(new G8Turn(2,new G8Actor2(item)),0);
		}
		g8_items_d3392c.clear();
		for (unsigned int k = 0; k < g8_items_d3393c.size(); k++)
		{
			G8HItem item = g8_itemPool_d2a298.add9d1b20(g8_items_d3393c[k]);
			item->unknown4582d0(item);
			unknown464f60(item);
			unknown465060(item);
			g8_cf4a48.push_back(item);
			if (item->unknown571d70())
				g8_queue_d225a0.add672310(new G8Turn(2,new G8Actor2(item)),0);
		}
		g8_items_d3393c.clear();
		f640 = 0;
		vector<const G8Ally *> g3;
		vector<int> h39;
		for (int i = 0; i < 15; i++)
		{
			for (unsigned int j = 0; j < g8_allies_d3394c[i].size(); j++)
			{
				g3.push_back(&g8_allies_d3394c[i][j]);
				h39.push_back(+i);
			}
		}
		if (!g3.empty())
		{
			vector<const G8Ally *> m31;
			vector<int> m34;
			m31.push_back(g3.front());
			m34.push_back(h39.front());
			for (unsigned int k = 1; k < g3.size(); k++)
			{
				if (g3[k]->ent->unknown5c7c80() <= m31.back()->ent->unknown5c7c80())
				{
					m31.push_back(g3[k]);
					m34.push_back(h39[k]);
				}
				else
				{
					for (unsigned int j = 0; j < m31.size(); j++)
					{
						if (g3[k]->ent->unknown5c7c80() > m31[j]->ent->unknown5c7c80())
						{
							g8_insertAt(m31,j,g3[k]);
							g8_insertAtI(m34,j,h39[k]);
							break;
						}
					}
				}
			}
			for (unsigned int k = 0; k < m31.size(); k++)
			{
				if (m31[k]->ent->getSize45a360() > 1)
				{
					const int radius = 4;
					g8_clearDijkstra();
					g8_carto_cfe568.unknown40ca20(k37,10,&g8_cfe5e8,0);
					if (g8_d15e58.empty())
					{
					}
					else
					{
						vector<G8Point> adj;
						for (unsigned int i = 0; i < g8_d15e58.size(); i++)
						{
							adj.clear();
							g8_adjacent(g8_d15e58[i],adj);
							for (unsigned int j = 0; j < adj.size(); j++)
							{
								if ((*g8_cells_cfd44c.atPoint(adj[j]))->terrain9fcd80() == TERRAIN_CAVE_WALL || (*g8_cells_cfd44c.atPoint(adj[j]))->unknown45db70())
								{
									if ((*g8_cells_cfd44c.atPoint(adj[j]))->unknown45dc70())
										(*g8_cells_cfd44c.atPoint(adj[j]))->unknown66a050(g8_floor_cefb9c->id,2,0);
									else
									{
										G8Terrain *old = (*g8_cells_cfd44c.atPoint(adj[j]))->terrain9fcd80();
										(*g8_cells_cfd44c.atPoint(adj[j]))->trigger45e110(0,1,G8HE());
										g8_fn6c0f10(adj[j],old->id,100);
									}
								}
							}
						}
					}
				}
			}
			int m38 = 0;
			vector<string> m51;
			for (unsigned int k = 0; k < m31.size(); k++)
			{
				G8Point p;
				if (findPlaceableNearWide71c200(k37,p,m31[k]->ent->getSize45a360()))
				{
					g8_clearObjects(m31[k]->ent->unknown45a740());
					G8HE e = unknown6c5e20(m31[k],p,m34[k],1,1,m31[k]->kind < 2);
					if (e.isValid() && e->getFaction() != 0x49)
					{
						m38++;
						if (e->def9b4350()->f48 == 0x79)
							m51.push_back(e->name416f40());
					}
				}
				else
					f640++;
			}
			if (m38 != 0)
			{
				string text = g8_intToString(m38) + (m38 == 1 ? " ally" : " allies");
				if (!m51.empty())
				{
					if (m51.size() == 1)
						text += " (" + m51[0] + ")";
					else
					{
						text += " (incl. ";
						for (unsigned int i = 0; i < m51.size(); i++)
						{
							if (i != 0)
								text += ", ";
							text += m51[i];
						}
						text += ")";
					}
				}
				G8_PHRASE(3,&text);
			}
			if (f640 != 0)
			{
				string text = g8_intToString(f640) + (f640 == 1 ? " ally" : " allies");
				G8_PHRASE(4,&text);
			}
			if (g8_cf462c == 7)
			{
				vector<G8HE> *members = f4c[2]->members416f40();
				for (unsigned int k = 0; k < members->size(); k++)
				{
					if ((*members)[k]->getFaction() == 0x49)
					{
						f670 = (*members)[k];
						break;
					}
				}
			}
			for (int k = 0; k < 15; k++)
				g8_allies_d3394c[k].clear();
		}
		if (g8_d33a3c != g8_cefb70 && g8_cf4ac8 != 0)
		{
			vector<G8Item *> all;
			g8_itemPool_d2a298.getAll9d0c30(all);
			for (int k = all.size() - 1; k >= 0; k--)
			{
				if (all[k]->kind9fcd80() == g8_d33a3c)
				{
					g8_cf4ac8->h4 = all[k]->handle45a260();
					goto holderDone;
				}
			}
			if (g8_cf4ac8->f0 == 0)
			{
				delete g8_cf4ac8;
				g8_cf4ac8 = 0;
			}
holderDone:;
		}
		if (!g8_d33a40.empty())
		{
			g8_cf4aa8.clear();
			vector<G8HE> *members = f4c[0]->members416f40();
			for (unsigned int k = 0; k < g8_d33a40.size(); k++)
			{
				for (unsigned int j = 1; j < members->size(); j++)
				{
					if ((*members)[j]->kind9fcd80() == g8_d33a40[k])
					{
						g8_cf4aa8.push_back((*members)[j]);
						goto nextCompanion;
					}
				}
				g8_removeElement(g8_cf4ab8,k);
				g8_eraseAt(g8_d33a40,k);
nextCompanion:;
			}
			g8_d33a40.clear();
		}
		switch (e22)
		{
		case 2:
			spawnPlayer2_6ee930();
			break;
		case 7:
			unknown6ef100();
			break;
		case 8:
			unknown6df000();
			break;
		case 0xf:
			unknown6dfc00(rb38);
			break;
		case 0x14:
			clear9c05e0();
			break;
		case 0xa:
			unknown6e33a0();
			break;
		case 0xc:
			unknown6ff270();
			break;
		case 0xd:
			unknown6ef730();
			break;
		case 4:
			unknown6efb90();
			break;
		case 5:
			unknown6f1370();
			break;
		case 0x22:
			unknown6f1990();
			break;
		case 0x23:
			unknown6f1c70();
			break;
		}
		initialize701390(e50);
		if (g8_d1ebfc)
		{
			for (unsigned int k = 0; k < f118[5].size(); k++)
				(*g8_cells_cfd44c.atPoint(f118[5][k]))->getProp()->machine45cb30()->f28 = -1;
		}
		if (g8_hloc_d1ebd8.isValid() && (e22 == 0x1e || e22 == 0x1f || e22 == 5) && g8_stringToInt(g8_gameData_d1e860.getEntryText("warAttackedLocals_g")) == 0)
		{
			f8c4 = 9;
			reinforce73d320(1,1,0,f66c->getPosition());
		}
		vector<G8HE> g9;
		for (unsigned int k = 0; k < g8_d33a50.size(); k++)
		{
			G8HE e = placeEntity(g8_records_d25de0[g8_d33a50[k]],k37,g8_d33a60[k],1,0x22,0xe,0);
			if (e.isValid())
			{
				e->unknown45b070(g8_d33a70[k]);
				for (unsigned int j = 0; j < g8_d33a80[k].size(); j++)
					unknown6c65a0(e,g8_dialogs_d2c408[g8_d33a80[k][j]]->name,false);
				g9.push_back(e);
			}
		}
		if (!g9.empty())
		{
			G8HE leader = g9.front();
			for (int k = 1; k < g9.size(); k++)
			{
				if (k % 5 == 0)
					leader = g9[k];
				else
					g9[k]->getAI()->setFollowEntity(leader,0);
			}
		}
		g8_d33a50.clear();
		g8_d33a60.clear();
		g8_d33a70.clear();
		g8_d33a80.clear();
		g8_area_d255bc.p1.x = -1;
		if (g8_d25450 && !e50.empty() && g8_gameData_d1e860.unknown46f4b0(1) && g8_location_d1e888->depth != 0x23)
		{
			int q12 = -1;
			int q3;
			for (unsigned int k = 0; k < e50.size(); k++)
			{
				if (q12 == -1 || g8_encounters_cf13e8[e50[k]].f58 > q3)
				{
					vector<G8Point> path;
					if (g8_carto_cfe568.findPath(f66c->getPosition(),g8_encounters_cf13e8[e50[k]].rect.center40ad40(),g8_cost_cefc30,0,path))
					{
						q12 = e50[k];
						q3 = g8_encounters_cf13e8[k].f58;
					}
				}
			}
			if (q12 != -1)
			{
				g8_area_d255bc = g8_encounters_cf13e8[q12].rect;
				g8_fn9d51d0(e50,q12);
			}
		}
		if (g8_d1eb68 != 0 && g8_gameData_d1e860.isFlagEnabledB46fc40())
		{
			int h28 = g8_gameData_d1e860.unknown46f4e0();
			int q42 = g8_minInt(g8_d1eb68,g8_cells_cfd44c.getWidth() * g8_cells_cfd44c.getHeight() / 5000);
			OpR5h_WL<int> h8(g8_b99b38,8);
			vector<int> q48(e50);
			for (int k = 0; k < q42; k++)
			{
				int q49 = h8.pick();
				vector<string> qq42;
				switch (q49)
				{
				case 0:
					qq42.push_back(h28 >= 7 ? "Wasp_7" : "Wasp_5");
					break;
				case 1:
					qq42.push_back(h28 >= 7 ? "Thug_7" : "Thug_5");
					break;
				case 2:
					qq42.push_back(h28 >= 7 ? "Savage_7" : "Savage_5");
					qq42.push_back(h28 >= 7 ? "Butcher_7" : "Butcher_5");
					break;
				case 3:
					qq42.push_back(h28 >= 7 ? "Wizard_7" : "Wizard_5");
					break;
				case 4:
					qq42.push_back(h28 >= 7 ? "Guerilla_7" : "Guerilla_5");
					break;
				case 5:
					qq42.push_back(h28 >= 7 ? "Fireman_7" : "Fireman_5");
					break;
				case 6:
					qq42.push_back(h28 >= 8 ? "Mutant_8" : h28 >= 7 ? "Mutant_7" : h28 >= 6 ? "Mutant_6" : "Mutant_5");
					break;
				case 7:
					qq42.push_back(h28 >= 8 ? "Infiltrator_8" : h28 >= 7 ? "Infiltrator_7" : "Infiltrator_6");
					break;
				}
				if (qq42.size() > 1)
					g8_shuffleStrings(qq42);
				int qq46 = g8_ranges_d37a00[q49].randomInRange();
				f874.push_back(vector<int>());
				int k36 = qq46 / qq42.size();
				G8Rec *g2;
				for (unsigned int j = 0; j < qq42.size(); j++)
				{
					g8_findRec(g8_records_d25de0,qq42[j],g2);
					for (int i = 0; i < k36; i++)
						f874.back().push_back(g2->id);
					if (j + 1 == qq42.size() && f874.back().size() < qq46)
						f874.back().push_back(g2->id);
				}
				if (rng.chance(15))
				{
					g8_findRec(g8_records_d25de0,h28 >= 6 ? "Surgeon_6" : "Surgeon_4",g2);
					f874.back().push_back(g2->id);
				}
				bool ra11 = false;
				G8Point g26;
				if (!q48.empty())
				{
					g8_shuffleInts(q48);
					for (unsigned int j = 0; j < q48.size(); j++)
					{
						g26 = g8_encounters_cf13e8[q48[j]].rect.randomPos40b080();
						if (findPlaceableNear71c150(g26,g26,1) && !g8_terrainFlagB(g26) && (*g8_cells_cfd44c.atPoint(g26))->getProp().isNull())
						{
							if (j < q48.size() / 2)
							{
								bool near = false;
								for (unsigned int i = 0; i < f884.size(); i++)
								{
									if (g8_distance(g26,f884[i]) <= 30)
									{
										near = true;
										break;
									}
								}
								if (near)
									continue;
							}
							vector<G8Point> path;
							if (!g8_carto_cfe568.findPath(f66c->getPosition(),g26,g8_cost_cefc30,0,path))
								continue;
							f884.push_back(g26);
							f894.push_back(q49);
							g8_fn9d51d0(e50,q48[j]);
							ra11 = true;
							break;
						}
					}
				}
				if (!ra11)
				{
					const int tries = 100;
					for (int t = 0; t < tries; t++)
					{
						g8_cells_cfd44c.getRandom9cf0c0(g26);
						if (findPlaceableNear71c150(g26,g26,1) && !g8_terrainFlagB(g26) && (*g8_cells_cfd44c.atPoint(g26))->getProp().isNull())
						{
							if (t < 50)
							{
								bool near = false;
								for (unsigned int i = 0; i < f884.size(); i++)
								{
									if (g8_distance(g26,f884[i]) <= 30)
									{
										near = true;
										break;
									}
								}
								if (near)
									continue;
							}
							vector<G8Point> path;
							if (!g8_carto_cfe568.findPath(f66c->getPosition(),g26,g8_cost_cefc30,0,path))
								continue;
							f884.push_back(g26);
							f894.push_back(q49);
							ra11 = true;
							break;
						}
					}
				}
				if (!ra11)
					f874.pop_back();
			}
		}
		if (g8_caf1a4[e22] && g8_stringToInt(g8_gameData_d1e860.getEntryText("exiFarcomRescindedWarn_g")) != 0)
		{
			int ra15 = 20 - (g8_location_d1e888->b24 ? g8_d1ead0 : g8_d1ead4) * 5;
			bool ra19 = false;
			if (rng.chance(ra15))
			{
				(g8_location_d1e888->b24 ? g8_d1ead0 : g8_d1ead4)++;
				G8Area area;
				g8_cells_cfd44c.getRect(f66c->getPosition(),20,area);
				for (int x = area.p1.x; x <= area.p2.x; x++)
				{
					for (int y = area.p1.y; y <= area.p2.y; y++)
					{
						if ((*g8_cells_cfd44c.at(x,y))->getEntity().isValid() && (*g8_cells_cfd44c.at(x,y))->getEntity()->getGroup()->kind9b4350() > 2)
							(*g8_cells_cfd44c.at(x,y))->getEntity()->unknown637bb0();
					}
				}
				ra19 = unknown736510(rng.rangeInt(1,2),f8,area,0,0);
				if (rng.chance(50) && unknown736510(1,G8Point(-1),area,0,1))
					ra19 = true;
			}
			if (!ra19 && !g8_location_d1e888->b24 && rng.chance(0x42 - g8_d1ead8 * 0x21))
			{
				for (unsigned int k = 0; k < f10.size(); k++)
				{
					if (!f10[k]->loc->inRange46ecb0())
					{
						if (unknown6c6b90(f10[k]->pos,"CAV_Master_Thief_Ambush",0,-1))
						{
							g8_d1ead8++;
							G8Area area;
							g8_cells_cfd44c.getRect(f10[k]->pos,20,area);
							for (int x = area.p1.x; x <= area.p2.x; x++)
							{
								for (int y = area.p1.y; y <= area.p2.y; y++)
								{
									if ((*g8_cells_cfd44c.at(x,y))->getEntity().isValid() && (*g8_cells_cfd44c.at(x,y))->getEntity()->getGroup()->kind9b4350() > 2)
										(*g8_cells_cfd44c.at(x,y))->getEntity()->unknown637bb0();
								}
							}
						}
						break;
					}
				}
			}
		}
		if (e22 == 1)
			unknown71ef30(f66c->getPosition(),0);
		if (g8_d1e880 && e22 == 2 && g8_location_d1e888->f8 == 0xa && (g8_d257e0 == -1 || (rng.chance(50) && g8_fn9daf80(7,g8_d257e0,10))))
		{
			G8Def *launcher;
			if (g8_findDef(g8_defs_d2d1c4,"Grenade Launcher",launcher))
			{
				for (int r = 20; r <= 40; r += 20)
				{
					g8_clearDijkstra();
					g8_carto_cfe568.unknown40ca20(f66c->getPosition(),r * 2,&g8_d31660,0);
					if (!g8_d15e58.empty())
					{
						for (unsigned int k = 0; k < g8_d15e58.size(); k++)
						{
							if (!g8_terrainFlagA(g8_d15e58[k]))
							{
								(*g8_cells_cfd44c.atPoint(g8_d15e58[k]))->getItem()->remove57dbe0(0,0,1,1);
								unknown6c5400(launcher,g8_d15e58[k]);
								break;
							}
						}
					}
				}
			}
		}
		if (g8_diff_cf4718 == 2 && g8_gameData_d1e860.unknown46f4b0(1) && e22 != 1)
		{
			vector<int> rc32(6);
			G8ItemDef *q21;
			int g7 = g8_location_d1e888->rating46ed20();
			rc32[0] = f66c->unknown45a920() < 100;
			rc32[1] = f66c->unknown448fe0(0);
			rc32[2] = f66c->unknown448fe0(1);
			rc32[3] = f66c->unknown448fe0(3);
			rc32[4] = 1;
			rc32[5] = g7 >= 4;
			int rc36 = f66c->unknown5d1390();
			int h11 = rc36 == 6 || rc36 == 2 ? 10 : rc36 + 9;
			vector<G8HItem> *q28 = f66c->getInventoryList45ab00();
			for (unsigned int k = 0; k < q28->size(); k++)
			{
				if ((*q28)[k]->unknown457ca0() >= 0x42)
				{
					switch ((*q28)[k]->slot4578a0())
					{
					case 0:
						rc32[1]--;
						break;
					case 1:
						if ((*q28)[k]->unknown457880() == h11)
							rc32[2]--;
						break;
					case 2:
						if ((*q28)[k]->unknown457880() == 0x12)
							rc32[4]--;
						break;
					case 3:
						if ((*q28)[k]->unknown457900() >= g7 - 1)
						{
							rc32[3]--;
							if ((*q28)[k]->unknown457880() == 0x18)
								rc32[5]--;
						}
						break;
					}
				}
			}
			int q35 = 40;
			g8_clearDijkstra();
			g8_carto_cfe568.unknown40ca20(f66c->getPosition(),q35 * 2,&g8_d31660,0);
			for (unsigned int k = 0; k < g8_d15e58.size(); k++)
			{
				if (g8_terrainFlagA(g8_d15e58[k]) || (*g8_cells_cfd44c.atPoint(g8_d15e58[k]))->getItem()->def9b4350()->f54 == 0)
					g8_eraseStep(g8_d15e58,k);
			}
			for (unsigned int k = 0; k < rc32.size() && !g8_d15e58.empty(); k++)
			{
				if (k == 0)
				{
					G8Point p(g8_d15e58.front());
					(*g8_cells_cfd44c.atPoint(p))->getItem()->remove57dbe0(0,0,1,1);
					unknown71e7c0(p,rng.rangeInt(50,150),0);
					g8_eraseAtP(g8_d15e58,0);
				}
				else
				{
					int ra33 = 0x1f;
					int ra37 = 0x12;
					switch (k)
					{
					case 1:
						ra37 = 0;
						break;
					case 2:
						ra33 = h11;
						break;
					case 3:
						ra37 = 3;
						break;
					case 4:
						ra33 = 0x12;
						break;
					case 5:
						ra33 = 0x18;
						break;
					}
					while (rc32[k] > 0)
					{
						q21 = selectRandomItem6c3bc0(0,ra33,ra37);
						if (q21 != 0)
						{
							G8Point p(g8_d15e58.front());
							(*g8_cells_cfd44c.atPoint(p))->getItem()->remove57dbe0(0,0,1,1);
							unknown6c5400(q21,p);
							g8_eraseAtP(g8_d15e58,0);
							if (g8_d15e58.empty())
								break;
						}
						rc32[k]--;
					}
				}
			}
		}
		if ((e22 == 0x10 || e22 == 0x11) && g8_stringToInt(g8_gameData_d1e860.getEntryText("scrEnhScrapShieldGave_g")) != 0 && g8_stringToInt(g8_gameData_d1e860.getEntryText("scrEnhScrapShieldDelivered_g")) == 0 && g8_stringToInt(g8_gameData_d1e860.getEntryText("scrAttackedLocals_g")) == 0)
		{
			unknown6c65a0(f66c,"SCR_Enh_Scrap_Shield3",false);
			g8_gameData_d1e860.setEntryText("scrEnhScrapShieldDelivered_g","1");
		}
		if ((e22 == 0x10 || e22 == 0x11) && g8_hist_d1e88c[g8_hist_d1e88c.size() - 2]->depth == e22 && g8_stringToInt(g8_gameData_d1e860.getEntryText("scrTriangleResearchDelivered_g")) == 1)
		{
			unknown6c65a0(f66c,"Yendor_Amulet_Trigger1",false);
			g8_gameData_d1e860.setEntryText("scrTriangleResearchDelivered_g","2");
		}
		switch (g8_cf462c)
		{
		G8ItemDef *def;
		case 1:
			for (int x = 0; x < g8_cells_cfd44c.getWidth(); x++)
			{
				for (int y = 0; y < g8_cells_cfd44c.getHeight(); y++)
				{
					if ((*g8_cells_cfd44c.at(x,y))->getItem().isValid())
					{
						def = selectRandomItem6c3bc0(0,0x18,0x12);
						if (def != 0)
						{
							(*g8_cells_cfd44c.at(x,y))->getItem()->remove57dbe0(0,0,1,1);
							unknown6c5400(def,G8Point(x,y));
						}
					}
				}
			}
			break;
		case 2:
			{
				for (int x = 0; x < g8_cells_cfd44c.getWidth(); x++)
				{
					for (int y = 0; y < g8_cells_cfd44c.getHeight(); y++)
					{
						if ((*g8_cells_cfd44c.at(x,y))->getItem().isValid())
							(*g8_cells_cfd44c.at(x,y))->getItem()->remove57dbe0(0,0,1,1);
					}
				}
				for (unsigned int k = 0; k < f118[3].size(); k++)
					(*g8_cells_cfd44c.atPoint(f118[3][k]))->getProp()->machine45cb30()->f28 = -1;
				for (unsigned int k = 0; k < f118[1].size(); k++)
					(*g8_cells_cfd44c.atPoint(f118[1][k]))->getProp()->machine45cb30()->f28 = -1;
				for (unsigned int k = 0; k < f118[2].size(); k++)
					(*g8_cells_cfd44c.atPoint(f118[2][k]))->getProp()->machine45cb30()->f28 = -1;
				for (unsigned int k = 0; k < g8_cf4634.size(); k++)
				{
					float target = g8_ba0498[k];
					if (!g8_fn9d85c0(target - 0.019999999552965164,g8_cf4634[k],target + 0.019999999552965164))
					{
						if (g8_cf4634[k] < target)
							g8_cf4634[k] += (target - g8_cf4634[k]) * g8_ba76d4;
						else if (g8_cf4634[k] > target)
							g8_cf4634[k] -= (g8_cf4634[k] - target) * g8_ba76d4;
					}
				}
				int level = g8_location_d1e888->rating46ed20();
				level++;
				if (e22 == 1)
					level++;
				fb08.push_back(new G8Option(0,0,500));
				for (unsigned int k = 0; k < g8_defs_d2d1c4.size(); k++)
				{
					G8ItemDef *def = (G8ItemDef *)g8_defs_d2d1c4[k];
					if (def->f44 >= 6 && def->f50 <= level && def->f54 != 0 && def->ff0 != 7 && def->ff0 != 0x8f)
					{
						float weight = 1.0f;
						if (def->f58 != 0)
							weight -= (level - def->f50) * (def->f58 == 1 ? g8_ba32f4 : g8_ba3664);
						if (def->f94 != 0)
							weight *= g8_ba76cc;
						if (weight > 0.0)
						{
							int chance = (int)(def->f60 * weight);
							if (rng.chance(chance))
								fb08.push_back(new G8Option(1,def,1));
						}
					}
				}
			}
			break;
		case 4:
			for (unsigned int k = 0; k < f10.size(); k++)
			{
				if (!f10[k]->loc->inRange46ecb0())
					f10[k]->f1c = 4;
			}
			break;
		case 5:
			for (int x = 0; x < g8_cells_cfd44c.getWidth(); x++)
			{
				for (int y = 0; y < g8_cells_cfd44c.getHeight(); y++)
				{
					if ((*g8_cells_cfd44c.at(x,y))->getItem().isValid())
					{
						switch ((*g8_cells_cfd44c.at(x,y))->getItem()->unknown457f90())
						{
						case 7:
							(*g8_cells_cfd44c.at(x,y))->getItem()->remove57dbe0(0,0,1,1);
							unknown71e7c0(G8Point(x,y),g8_range_d3172c.randomInRange(),0);
							break;
						case 0x39:
						case 0x40:
						case 0x41:
							(*g8_cells_cfd44c.at(x,y))->getItem()->remove57dbe0(0,0,1,1);
							break;
						}
					}
				}
			}
			break;
		}
		if (e22 != 0xc && e22 != 0xd)
		{
			if (g8_cf4724 != 0)
			{
				vector<int> ra42;
				vector<G8Point> m43;
				for (unsigned int k = 0; k < f10.size(); k++)
				{
					if (f10[k]->h14.isValid())
						ra42.push_back(0);
					else if (f10[k]->loc->depth == 6)
						ra42.push_back(9999999);
					else
					{
						m43.clear();
						if (f10[k]->loc->inRange46ecb0() && g8_carto_cfe568.findPath(f8,f10[k]->pos,g8_cost_cefc30,0,m43))
							ra42.push_back(m43.size());
						else
							ra42.push_back(0);
						f10[k]->f1c = 4;
					}
				}
				int ra46 = g8_fn9d4500(ra42);
				if (ra46 != -1)
					f10[ra46]->f1c = 0;
				else
					g8_logError("BS::initilize()","No valid exit found for CHALLENGE_GAUNTLET at depth -" + g8_intToString(g8_location_d1e888->f8));
			}
			if (g8_cf4740 != 0)
			{
				if (!f118[5].empty())
				{
					for (unsigned int k = 0; k < f10.size(); k++)
					{
						if (f10[k]->h14.isNull() && f10[k]->loc->depth != 6)
							f10[k]->f1c = 4;
					}
					for (unsigned int k = 0; k < f118[5].size(); k++)
						(*g8_cells_cfd44c.atPoint(f118[5][k]))->getProp()->machine45cb30()->f28 = -1;
					int rb1 = g8_randomIndex(f118[5]);
					(*g8_cells_cfd44c.atPoint(f118[5][rb1]))->getProp()->machine45cb30()->f28 = 0;
					G8Area m49;
					g8_cells_cfd44c.getRect(f118[5][rb1],20,m49);
					for (int x = m49.p1.x; x < m49.p2.x; x++)
					{
						for (int y = m49.p1.y; y < m49.p2.y; y++)
						{
							if ((*g8_cells_cfd44c.at(x,y))->unknown45dcf0())
								(*g8_cells_cfd44c.at(x,y))->removeProp66c100(1,4);
						}
					}
				}
				else
				{
					for (unsigned int k = 0; k < f10.size(); k++)
					{
						if (!f10[k]->loc->inRange46ecb0())
							f10[k]->f1c = 4;
					}
				}
			}
		}
		if (g8_d28de0 && !g8_tutorial_d25628.unknown7784b0() && e22 == 1 && !g8_anyNonZero(&g8_cf471c,0xc))
		{
			vector<G8HItem> m5;
			G8Area rb12;
			g8_cells_cfd44c.getRect(f66c->getPosition(),25,rb12);
			for (int x = rb12.p1.x; x < rb12.p2.x; x++)
			{
				for (int y = rb12.p1.y; y < rb12.p2.y; y++)
				{
					if ((*g8_cells_cfd44c.at(x,y))->getItem().isValid())
						m5.push_back((*g8_cells_cfd44c.at(x,y))->getItem());
				}
			}
			for (unsigned int k = 0; k < m5.size(); k++)
			{
				if (m5[k]->unknown457880() == 10)
					g8_moveElement(m5,k,0);
			}
			for (unsigned int k = 0; k < m5.size(); k++)
			{
				if (m5[k]->unknown457f90() == 7)
				{
					g8_moveElement(m5,k,0);
					break;
				}
			}
			G8Point rb16;
			for (unsigned int k = 0; k < m5.size(); k++)
			{
				if (m5[k]->unknown457880() == 0)
					f66c->unknown5e2590(m5[k],0,1);
				else if (!f66c->unknown5db5f0(m5[k],0,1,1))
				{
					m5[k]->unknown57a190(f66c,m5[k]->slot4578a0(),0,1);
					if (f66c->unknown5dc440(m5[k]) == 0)
						m5[k]->setActive5791a0(1);
				}
				else if (f66c->unknown45a810() >= m5[k]->unknown4578c0())
					m5[k]->unknown57a190(f66c,4,0,1);
				else if (unknown71bc10(f10.front()->pos,rb16))
					m5[k]->unknown57a0f0(rb16,0,0);
			}
			vector<G8Point> rb30;
			g8_surrounding(f10.front()->pos,rb30);
			for (unsigned int k = 0; k < rb30.size(); k++)
			{
				if ((*g8_cells_cfd44c.atPoint(rb30[k]))->getEntity().isNull())
				{
					f66c->changePos5dccb0(rb30[k],1);
					break;
				}
			}
			vector<G8HE> *m57 = f4c[4]->members416f40();
			for (unsigned int k = 0; k < m57->size(); k++)
			{
				if ((*m57)[k]->getFaction() == 0x4a)
				{
					(*m57)[k]->unknown637bb0();
					break;
				}
			}
		}
	}
	g8_fn465b10();
	g8_queue_d225a0.unknown672800(f66c);
	b0 = false;
	f4 = 0;
	f104 = 0;
	if (e22 == 0xd)
		b1d8 = false;
	else
	{
		b1d8 = true;
		for (int x = 0; x < e21.x; x++)
		{
			for (int y = 0; y < e21.y; y++)
			{
				if ((*g8_cells_cfd44c.at(x,y))->getProp().isValid() && (*g8_cells_cfd44c.at(x,y))->getProp()->getType() == "GAR_Generator")
				{
					b1d8 = false;
					break;
				}
			}
		}
	}
	f1fc = 0;
	f200 = 0;
	b204 = false;
	f208.assign(0x70u,0);
	f218 = 0;
	f21c = 0;
	f230 = 0;
	f268.assign(0x19,vector<G8HE>());
	f2b0.assign(0x13u,0);
	b2f0 = false;
	f314 = -1;
	f318 = 0;
	f31c = 0;
	f328 = 0;
	b32c = false;
	b32d = false;
	f3d0 = e22 == 0xf;
	f3e8 = 0;
	f3ec = 1;
	f614 = 0;
	b63c = false;
	b644 = false;
	b660 = false;
	f664 = 0;
	f668 = 0;
	f674.resize9d2810(e21.x,e21.y,0);
	f674.zero9d28b0();
	f680.resize9d2810(e21.x,e21.y,0);
	f680.zero9d28b0();
	f68c = 0;
	g30 = TERRAIN_EARTH->id;
	for (int x = 0; x < e21.x; x++)
	{
		for (int y = 0; y < e21.y; y++)
		{
			if (*originalTerrain.at(x,y) != g30)
				f68c++;
		}
	}
	f690.resize9d4090(e21.x,e21.y,0);
	f690.zero9d23e0();
	f69c.resize9d4090(e21.x,e21.y,0);
	f69c.zero9d23e0();
	b70c = false;
	f740.resize9d2ae0(e21.x,e21.y,0);
	for (int x = 0; x < e21.x; x++)
	{
		for (int y = 0; y < e21.y; y++)
			f740.at9cdf20(x,y)->reset461bc0();
	}
	f74c = 1;
	b750 = false;
	b751 = false;
	b752 = false;
	b753 = false;
	f7c4.resize9d2de0(e21.x,e21.y,0);
	for (int x = 0; x < e21.x; x++)
	{
		for (int y = 0; y < e21.y; y++)
			f7c4.at9d2c30(x,y)->reset460f00();
	}
	f7e0.assign(0x14,vector<G8HE>());
	f810 = -1;
	f818 = 0;
	f82c = 0;
	unknown72ec60();
	f868 = 0;
	f86c = -1;
	b8a4 = false;
	f8a8 = 0;
	b8ac = false;
	f8b0 = 0;
	b8c8 = false;
	f9a4 = 0;
	f9a8 = 0;
	f9ac = 0;
	f9b0 = 0;
	f9b4 = 0;
	f9b8 = 0;
	f9cc = 0;
	f9d0 = 0;
	b9e4 = false;
	f9e8.reset9b7270();
	f9ec = 0;
	f9f0 = 0;
	fa04 = 0;
	fa08 = 0;
	ba0c = e22 == 0x19;
	e5 = f66c->unknown5cb9b0(0);
	e33 = f66c->unknown5c8e20(0);
	ba0d = !e5 && g8_location_d1e888->inRange46ecb0() && g8_location_d1e888->f8 <= 5 && g8_player_cf45d8.isSlotEmpty(0x130);
	ba0e = !e5 && g8_location_d1e888->inRange46ecb0() && g8_location_d1e888->f8 <= 3 && e33 == 0 && g8_player_cf45d8.isSlotEmpty(0x13d);
	fa10 = 0;
	ba14 = e22 == 0xd && f66c->unknown45a880() < 10;
	ba15 = false;
	ba16 = false;
	fa18 = 0;
	ba1c = false;
	fa70 = 0;
	ba74 = false;
	fa78.reset9b7270();
	fa7c.reset9b7270();
	bb04 = true;
	fbe8.init9cffc0(e21.x,e21.y,0);
	bb05 = g8_cefacf;
	bb06 = g8_cefacf;
	bb07 = g8_cefacf;
	fb18 = 0;
	fb1c = 0;
	fb20 = e22 == 0x24 ? 9999999 : g8_cf462c == 4 && g8_location_d1e888->inRange46ecb0() && g8_location_d1e888->f8 < 0xb ? -(getTurn464270() + g8_range_d1d614.randomInRange()) : 0;
	fb34 = 0;
	fb38 = 0;
	fb3c = -1;
	bb44 = false;
	fb48 = 0;
	fba4 = 0;
	fba8.reset9b7270();
	fbac = 0;
	if (g8_cf462c == 0xa && g8_location_d1e888->inRange46ecb0() && g8_location_d1e888->rating46ed20() > 3)
		fba4 = getTurn464270() + g8_range_d35bd8.randomInRange();
	fbb0 = 1;
	bbe4 = false;
	fc14 = 0;
	f38.resize9d4090(e21.x,e21.y,0);
	f38.zero9d23e0();
	f44 = 0;
	g8_sound_d2d2a0.unknown454430();
	g8_sound_d2d2a0.unknown500260(0);
	unknown72e8e0(1);
	g8_cmap_cec054->unknown8069e0(f66c->unknown45a4c0(),0);
	if (g8_location_d1e888->f8 > g8_ba65c0[g8_diff_cf4718])
	{
		vector<G8HE> *members = f4c[3]->members416f40();
		for (unsigned int k = 0; k < members->size(); k++)
		{
			if ((*members)[k]->getFaction() == 9 && unknown4631f0((*members)[k]))
			{
				(*members)[k]->unknown637bb0();
				k--;
			}
		}
	}
	g8_stats_d2c658.add4729d0(0xbe,f66c->unknown5cccc0(),"",-1);
	if (g8_hist_d1e88c.size() >= 2 && g8_hist_d1e88c[g8_hist_d1e88c.size() - 2]->depth == 0x12)
		g8_player_cf45d8.unknown77fbc0(0x10a);
	if (g8_hist_d1e88c.size() >= 2 && g8_hist_d1e88c[g8_hist_d1e88c.size() - 2]->depth == 0xe)
		g8_player_cf45d8.unknown77fbc0(0x10b);
	if (e22 != 1)
		g8_stats_d2c658.add4729d0(0x403,1,"",-1);
	if ((*g8_stats_d2c658.values)[0x403] == 0x23)
		g8_player_cf45d8.unknown77fbc0(0x10f);
	g8_stats_d2c658.add4729d0(0x378,g8_gameData_d1e860.getWeightedDepthCount7896a0(),"",-1);
	if (!g8_location_d1e888->inRange46ecb0() && e22 != 0xd && e22 != 0xe && e22 != 0xc)
	{
		g8_stats_d2c658.add4729d0(0x404,1,"",-1);
		if ((*g8_stats_d2c658.values)[0x404] == 3)
			g8_player_cf45d8.unknown77fbc0(0x10c);
		else if ((*g8_stats_d2c658.values)[0x404] == 10)
			g8_player_cf45d8.unknown77fbc0(0x10e);
	}
	g8_player_cf45d8.unknown783540();
	switch (e22)
	{
	case 3:
		g8_player_cf45d8.unknown77fbc0(0x106);
		if (g8_player_cf45d8.isSlotEmpty(0x122) && g8_hist_d1e88c.size() > 2 && g8_hist_d1e88c[g8_hist_d1e88c.size() - 2]->depth == 0xa && f66c->unknown5d26e0(0xd3))
			g8_player_cf45d8.unknown77fbc0(0x122);
		break;
	case 4:
		g8_player_cf45d8.unknown77fbc0(0x107);
		break;
	case 5:
		g8_player_cf45d8.unknown77fbc0(0x108);
		if (g8_cf4d17)
			g8_player_cf45d8.unknown77fbc0(0x166);
		break;
	case 0xa:
		if (g8_hist_d1e88c.size() >= 2 && g8_hist_d1e88c[g8_hist_d1e88c.size() - 2]->depth == 9)
			g8_player_cf45d8.unknown77fbc0(0x109);
		break;
	case 0xb:
		g8_player_cf45d8.unknown77fbc0(0x179);
		break;
	case 0xd:
		g8_stats_d2c658.add472b90(0x24,-999999);
		if (g8_player_cf45d8.isSlotEmpty(0xd0))
		{
			for (unsigned int k = 0; k < f4c[1]->members416f40()->size(); k++)
			{
				if ((*f4c[1]->members416f40())[k]->getFaction() == 9)
				{
					g8_player_cf45d8.unknown77fbc0(0xd0);
					break;
				}
			}
		}
		break;
	case 0xe:
		g8_stats_d2c658.add472b90(0x26,-999999);
		break;
	case 0x13:
		g8_player_cf45d8.unknown77fbc0(0x182);
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
		if (g8_player_cf45d8.isSlotEmpty(0x10d) && g8_hist_d1e88c.size() >= 2)
		{
			for (int k = g8_hist_d1e88c.size() - 2; k != 0; k--)
			{
				if (g8_hist_d1e88c[k]->depth == 0x13 || g8_hist_d1e88c[k]->depth == 0x14 || g8_hist_d1e88c[k]->depth == 0x15 || g8_hist_d1e88c[k]->depth == 0x16 || g8_hist_d1e88c[k]->depth == 0x17)
				{
					g8_player_cf45d8.unknown77fbc0(0x10d);
					break;
				}
			}
		}
		break;
	}
	f658 = 2;
	rng.seed();
	if (g8_cefb3e)
		g8_luigi_cebffc.unknown777bc0();
	g8_jlog_cefa64->end410e50(2);
	return true;
}
