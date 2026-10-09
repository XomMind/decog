// CRobot::executeHack (exe 0x9471d0): runs one robot hack (Hack: list in the robot hacking console) on a robot.
// NOTE: class is declared here as D2RobotHack (placeholder name); layouts are partial, names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int value);	// 0x409990
	Pos(int x_, int y_) throw();	// 0x46ca20
	Pos(const Pos &pos) throw();	// 0x46ca50
	bool equals_409b90(const Pos &other);	// NOTE: placeholder name
	int randomInRange_40c130();	// NOTE: placeholder name
};
struct D2rPt : Pos	// NOTE: placeholder name (default ctor 0x453b40)
{
	D2rPt() throw();
};

struct D2rItemStats { char pad0[0x74]; bool b74; char pad75[0x94 - 0x75]; int f94; char pad98[0x1a8 - 0x98]; int f1a8; };	// NOTE: placeholder layout
class D2rItem	// NOTE: placeholder name
{
public:
	D2rItemStats *stats_9b4350();
	int getNestedField();
	void unknown57a0f0(Pos *at, int a, int b);
	void setActive(bool active);
	void setActivateOkayTurn(int turn);
	string unknown457990();
	int nested_4578a0();
	string getName_571db0(bool full, bool label);
	void setBroken_5795b0(int a, int b);
};
struct D2rMarker { char pad0[8]; Pos pos; void unknown6c20b0(int layer, const Pos &pos, int value); };	// NOTE: placeholder layout
class D2rHMarker { public: int ID; D2rMarker *operator->() const; };	// NOTE: placeholder name (0x9b7cd0)
class D2rFactory { public: D2rHMarker createC_793190(); };	// NOTE: placeholder name
extern D2rFactory *d2r_cefaa8;
class D2rHItem
{
public:
	int ID;
	D2rHItem() throw();
	bool isValid() const;
	bool isNull() const;
	D2rItem *operator->() const;	// 0x9b65b0
};

class D2rEntity;
class D2rHEntity
{
public:
	int ID;
	D2rHEntity() throw();
	D2rEntity *operator->() const throw();	// 0x9b6570
	bool operator!=(D2rHEntity other) const;
	bool isValid() const;
	bool isNull() const;
	bool operator==(D2rHEntity other) const;
};
struct D2rEffect	// NOTE: placeholder name (0x458890, size 0x1c)
{
	D2rEffect(int type_) throw();
	int type;
	int turn;
	vector<Pos> points;
	D2rHEntity target;
};
class D2rEffects { public: D2rEffect *add_57f140(D2rEffect *effect); D2rEffect *find_458950(int type); };	// NOTE: placeholder name
class D2rAI2 { public: D2rAI2(D2rHEntity owner, int a, int b); char pad[0x130]; };	// NOTE: placeholder name (0x57f6a0, size 0x130)
class D2rAI
{
public:
	D2rEffects *effects_4590f0();
	void clearMemoryUnlessPreserved();
	void clearMemory();
	bool unknown459090();
	void unknown4591c0(int type);
	void delegate_459540(const Pos &pos);
	bool unknown5b6130(Pos *out);
	void setField_451440(D2rHEntity entity);
	D2rHEntity unknown458e70();
	void setField_45b090(D2rHEntity entity);
	void resetField_459340();
	int type_9b8f00();
	vector<Pos> *route_458ef0();
	void delegate_459520(const Pos &pos);
	void unknown5b5220();
	const vector<Pos> &unknown4549b0();
	int chase(D2rHEntity target, int a, int b, int c, int d);
	bool unknown5b3890(D2rHEntity target, int a);
	void setFollowEntity(D2rHEntity target, int a);
};
struct D2rEntityStats { char pad0[0x48]; int f48; };	// NOTE: placeholder layout
class D2rSquad { public: int type_9b4350(); void unknown671c90(Pos *at, int range, vector<class D2rHEntity> *out); int type_9b8f00(); vector<class D2rHEntity> &members_416f40(); };	// NOTE: placeholder name
class D2rHSquad { public: int ID; D2rSquad *operator->() const; };	// NOTE: placeholder name (0x9b7250)

class D2rEntity
{
public:
	D2rAI *ai_45b590();
	Pos unknown45a4c0();
	Pos *getPosition();
	D2rHSquad getGroup();
	void unknown5cb930(vector<D2rHItem> *parts);
	void setAI(D2rAI2 *ai);
	const string &name_416f40();
	bool unknown5c8820(D2rHEntity target);
	int getSize();
	bool unknown5d5460(int a);
	D2rHItem unknown5d2380(int slot);
	int unknown5cb830(vector<D2rHItem> *items);
	int getFaction() throw();
	void die(int a, int b, D2rHEntity killer, int c, int d, int e, int f, int g);
	D2rEffects *effects_45ae50();
	bool unknown45ae30();
	void unknown45af20(int type);
	void unknown45b210(int amount);
	void unknown5fd900(int a, int b);
	bool isHostileTo(D2rHEntity other);
	void unknown5fdab0();
	void removeEffectsA(int a);
	void changeFaction(D2rHSquad squad, int a);
	struct D2rEntityStats *stats_9b4350();
	void unknown45b340(Pos *pos);
	bool unknown5cb680(D2rHSquad squad);
	int getAiType();
	void *getTarget();
	int unknown5d47c0(D2rHEntity target, vector<D2rHItem> *a, int b);
};

struct D2rPropInfo { char pad0[0xf8]; int type; };	// NOTE: placeholder layout
struct D2rPropStats { int f0; int f4; char pad8[0x10 - 8]; int f10; };	// NOTE: placeholder layout
class D2rProp	// NOTE: placeholder name
{
public:
	D2rPropInfo *getInfo_9b8f00();
	D2rPropStats *stats_44b020();
	void unknown65f170();
	int unknown44ab40();
	const string &getName_45c5b0();
	Pos *getPosition_4184d0();
};
class D2rHProp { public: int ID; D2rProp *operator->() const; bool isValid() const; };	// NOTE: placeholder name (0x9b64f0)
class D2rHProp2 { public: int ID; bool isValid() const; };	// NOTE: placeholder name
class D2rCell { public: bool isEdge(); D2rHEntity getEntity(); D2rHProp getProp(); D2rHItem getItem(); void removeProp(int a, int b); };	// NOTE: placeholder name
struct D2rRect { int x; int y; int x2; int y2; D2rRect(); };	// NOTE: placeholder name (ctor 0x40b100)
class D2rGrid { public: void getRect_9b4430(Pos *center, int range, D2rRect *rect); D2rCell **at(int x, int y); D2rCell **atPoint(const Pos &pos); void getBounds(const Pos &center, int range, Pos *lo, Pos *hi); };	// NOTE: placeholder name
extern D2rGrid d2r_cfd44c;

class D2rWL { public: int &pick(); int total_9b81d0(); };	// NOTE: placeholder name (weighted list)
class D2rMap
{
public:
	char pad0[0x720];
	int f720;
	bool unknown463040();
	void unknown714090(vector<Pos> *out);
	void unknown4647d0(const Pos &pos);
	void unknown4647a0(const Pos &pos, bool flag);
	void unknown9e29b0(int *list, D2rHProp prop);
	int unknown7359d0(Pos *pos);
	bool unknown716a60(Pos *pos, int kind, D2rEntity *self, vector<Pos> *out);
	bool unknown716c30(Pos *pos, D2rEntity *self, vector<Pos> *out);
	bool unknown463160(const Pos &pos);
	vector<vector<D2rHMarker> > *unknown463ec0();
	void opw3_unknown729eb0(const Pos &pos, const string &name, bool a, bool b);
	bool unknown71bc10(const Pos &from, Pos *out);
	vector<Pos> *unknown463c20();
	void unknown4656d0(D2rHEntity robot);
	void opw3_unknown72f5b0(D2rHEntity robot);
	void unknown734d60(const Pos &pos);
	vector<struct D2rRoute *> *unknown463df0();
	void unknown465140();
	bool unknown4635c0(D2rHEntity robot);
	void opw3_unknown72e990(D2rHEntity robot);
	D2rHEntity unknown463e10();
	void unknown465160(D2rHEntity robot);
	void unknown465180(D2rHEntity robot);
	int unknown463690();
	bool unknown463400(D2rHEntity entity);
	void unknown4651b0(D2rHEntity robot);
	void opw3_unknown724420(int x, int y);
	class D2rWL &unknown463a30();
	class D2rWL &unknown463a10();
	D2rHEntity getPlayer();
	int getTurn();
	void unknown464710(bool a);
	D2rHSquad unknown463890(int type);
	bool unknown4631f0(D2rHEntity entity);
	bool isVisible(int x, int y);
};
extern D2rMap *d2r_cefc4c;

class D2rMapView	// NOTE: placeholder name
{
public:
	void addPosMark(Pos *pos, int range, int b);
	void unknown8197f0(Pos *pos, int b);
	void setPath(Pos &center, int turn, vector<Pos> *cells);
	void label813050(int a, D2rHProp prop, int b, int c, int d);
	void setUnknown38c(const Pos &pos);
	void unknown8071e0(D2rHEntity robot, bool flag);
	void unknown8074d0(D2rHEntity robot);
	void labelAccess80e3a0(int a, const Pos &pos);
	void unknown8079e0(struct D2rRoute *route);
	void unknown807b40();
	void unknown49ae20(D2rHEntity target);
};
extern D2rMapView *d2r_cec054;

class D2rMsgMap { public: void bubble(int a); };	// NOTE: placeholder name
extern D2rMsgMap *d2r_cec058;
class D2rLog { public: void scrollToEnd_7b4f10(); };	// NOTE: placeholder name
extern D2rLog *d2r_cec0b4;
class D2rPlayerData { public: void unknown780810(D2rHEntity robot, int hack, int c); void unknown77fbc0(int id); bool unknown77ffb0(int id, int b); bool unknown780380(int id, int b); void unknown780700(int id, int b); };	// NOTE: placeholder name
extern D2rPlayerData d2r_cf45d8;
extern int d2r_cf4718;
struct D2rOwner { int f0; int f4; int unknown46ed20(); };	// NOTE: placeholder layout
class D2rHOwner { public: int ID; D2rOwner *operator->() const; };	// NOTE: placeholder name (0x9b7910)
extern D2rHOwner d2r_d1e888;
class D2rPathfinder	// NOTE: placeholder name (Cartographer2D)
{
public:
	bool findPath(const Pos &from, const Pos &to, void *cost, void *data, vector<Pos> &path);
	void unknown40ca20(Pos *from, int range, void *filter, void *self);
};
extern D2rPathfinder d2r_cfe568;
extern void *d2r_cefc30;
extern int d2r_cfc1c4;
extern int d2r_d2257c;
extern vector<Pos> d2r_d15e58;
extern Pos d2r_d015d8[];
extern Pos d2r_d22260;
extern Pos d2r_d22268;
extern const float d2r_b91a34;
extern Pos d2r_d305d8;
extern bool d2r_b95758[];
extern vector<int> d2r_cf4a04;
extern vector<int> d2r_cf4a14;
extern int d2r_b98948[];
extern int d2r_b97d38[];
extern vector<int> d2r_d2f0f8;
extern string d2r_d3a280[];
class D2rMission { public: void unknown987de0(); };	// NOTE: placeholder name
extern D2rMission *d2r_cec034;
class D2rSquad2 { public: int type; D2rHEntity leader; int f8; char padc[0x18 - 0xc]; int f18; bool test_45e820(); };	// NOTE: placeholder name
extern vector<D2rSquad2 *> d2r_cf6478;
extern string d2r_d2f3c0;
extern vector<D2rHEntity> d2r_d33d74;
extern int d2r_cf0fa8;
extern int d2r_d297a8;
struct D2rRoute { D2rRoute(int faction) throw(); int faction; vector<Pos> points; };	// NOTE: placeholder name (ctor 0x461700, size 0x14)
class D2rInventoryUI { public: void reopen8a2ce0(int a, D2rHEntity entity); };	// NOTE: placeholder name
extern D2rInventoryUI *d2r_cec08c;
extern vector<int> d2r_cf4844;
extern vector<int> d2r_cf4910;
struct D2rRec4 { char pad0[0x24]; int f24; char pad28[0x68 - 0x28]; int f68; char pad6c[0x170 - 0x6c]; string f170; char pad18c[0x1ac - 0x18c]; string f1ac; };	// NOTE: placeholder layout
extern vector<D2rRec4 *> d2r_d25de0;
class D2rOvermind { public: int level; void unknown682420(int id, int amount); D2rSquad2 *unknown683310(D2rHEntity entity); void unknown68cd80(D2rSquad2 *squad); };	// NOTE: placeholder name
extern D2rOvermind d2r_cf6428;
struct D2rRec8 { char pad0[0x24]; string name; char pad40[0x209 - 0x40]; bool known; };	// NOTE: placeholder layout
extern vector<D2rRec8 *> d2r_d2d1c4;
extern int d2r_cf45d4;
extern int d2r_cfd428;
extern int d2r_cf6474;
extern int d2r_cf645c;
extern bool d2r_cf6468;
extern vector<vector<D2rHProp> > d2r_d20248;
class D2rStatTracker { public: int unknown472c90(int id); };	// NOTE: placeholder name
extern D2rStatTracker d2r_d2c658;
extern vector<vector<D2rHProp> > d2r_d31640;
extern string d2r_cfc460[];

class RNG { public: bool chance(int percent); int rangeInt(float low, float high); };
extern RNG rng;

bool opS2_showMessage_5111e0(int id, const string *text, const string *a, const string *b, D2rHEntity e1, D2rHEntity e2, int c, int d);
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);
void teamb_create95a640(int id);
void clearDijkstraResults();
void OpV4c_shuffle_9d7350(vector<Pos> &list);
string OpQ1_pointToString(const Pos &pos);
void opR1d_454260(Pos *pos, int sound);
class HEntity	// NOTE: retail signature type of opr5f_unknown953d90 (same layout as D2rHEntity)
{
public:
	int ID;
};
void opr5f_unknown953d90(HEntity entity, vector<unsigned int> *hacks);
bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, D2rHEntity subject, const Pos *at);
int OpS8b_Fn9d4660(vector<int> &list, int value);
void OpQ5_eraseStep_9d6440(vector<D2rHItem> &list, int &index);
void OpQ5_eraseStep_9d7300(vector<Pos> &list, int &index);
string opw8_countString(int count, const string &word);
string intToString(int value);
char randomChar_4085b0(const string &chars);
string opr1c_getSecurityName_4332b0(int level);
bool OpT8b_Fn9db000(vector<int> &list, int value);
struct Point	// NOTE: retail signature type of the two helpers below (same layout as Pos)
{
	int x;
	int y;
	Point(const Point &p) throw();	// 0x46ca50
};
void OpS8c_appendUnique(vector<Point> &list, vector<Point> &other);
bool OpV4c_Fn9d3020(vector<Point> &list, Point pos);
void OpQ5_clearObjects_9d0670(int *list);
void OpQ5_clearObjects_9e2650(vector<D2rRoute *> &list);
void OpQ5_deleteBack_9e32e0(vector<D2rRoute *> &list);
void OpQ5_eraseStep_9d6440(vector<D2rHMarker> &list, int &index);
int OpQ1_distanceCeil_40a3f0(const Pos &a, const Pos &b);
bool OpX5_containsRecord(vector<int> &list, int value);
bool OpT8b_Fn9daf80(int lo, int v, int hi);
int OpS8d_popRandom(vector<int> &list);

#define SHOW(id, text) do { if (opS2_showMessage_5111e0(id, text, 0, 0, D2rHEntity(), D2rHEntity(), 0, 0)) d2r_cec058->bubble(1); d2r_cec0b4->scrollToEnd_7b4f10(); } while (0)
#define SHOWS(id, text) SHOW(id, &string(text))
#define SHOWR(id, text) do { if (opS2_showMessage_5111e0(id, &string(text), 0, 0, robot, D2rHEntity(), 0, 0)) d2r_cec058->bubble(1); d2r_cec0b4->scrollToEnd_7b4f10(); } while (0)
#define SHOWR2(id, text, arg) do { if (opS2_showMessage_5111e0(id, &string(text), arg, 0, robot, D2rHEntity(), 0, 0)) d2r_cec058->bubble(1); d2r_cec0b4->scrollToEnd_7b4f10(); } while (0)
#define SHOWA(id, text, arg) do { if (opS2_showMessage_5111e0(id, &string(text), arg, 0, D2rHEntity(), D2rHEntity(), 0, 0)) d2r_cec058->bubble(1); d2r_cec0b4->scrollToEnd_7b4f10(); } while (0)
#define SHOWE(id, text) do { if (opS2_showMessage_5111e0(id, text, 0, 0, robot, D2rHEntity(), 0, 0)) d2r_cec058->bubble(1); d2r_cec0b4->scrollToEnd_7b4f10(); } while (0)
#define LOGN(id) do { opS2_logPhrase_5141b0(id, &robot->name_416f40(), 0, 0, D2rHEntity(), 0); } while (0)
#define START() { unknown946da0(hack); d2r_cf45d8.unknown780810(robot, hack, -1); }
#define STARTC() if (!remote) { unknown946da0(hack); d2r_cf45d8.unknown780810(robot, hack, -1); chain = true; }
#define ADDFX0(e) robot->ai_45b590()->effects_4590f0()->add_57f140(static_cast<D2rEffect *&&>(e))
#define ADDFX(e) effect = robot->ai_45b590()->effects_4590f0()->add_57f140(static_cast<D2rEffect *&&>(e))

class D2RobotHack	// NOTE: placeholder name (CRobot)
{
public:
	void executeHack(D2rHEntity robot, int hack, string arg);
	void unknown946da0(int hack);
	void unknown946990();
	void unknown953c70();

	char pad0[0x74];
	D2rHEntity entity;
};

void D2RobotHack::executeHack(D2rHEntity robot, int hack, string arg)
{
	if (hack != 0x49)
	{
		string text(2, '>');
		text += d2r_cfc460[hack];
		SHOW(0x1f4, &text);
	}
	bool remote = robot != entity;
	bool chain = false;
	Pos here = robot->unknown45a4c0();
	D2rEffect *effect = 0;
	switch (hack)
	{
	case 0:
	{
		START();
		SHOWS(0x1f5, "Reading system data...");
		robot->ai_45b590()->clearMemoryUnlessPreserved();
		int id = robot.ID;
		unknown946990();
		d2r_cefc4c->unknown464710(1);
		teamb_create95a640(id);
		return;
	}
	case 1:
		STARTC();
		SHOWS(0x1f5, "Distress signal routine blocked.");
		ADDFX(new D2rEffect(1));
		break;
	case 2:
	{
		vector<D2rHItem> parts;
		robot->unknown5cb930(&parts);
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->nested_4578a0() == 0)
				goto found2;
		}
		SHOWS(0x1f5, "Unable to locate active power source.");
		goto done;
found2:
		STARTC();
		SHOWS(0x1f5, "Tweaked power modulation, spike imminent.");
		SHOWR(0x1f6, "[name] emits distorted distress signal.");
		vector<D2rHEntity> vec;
		robot->getGroup()->unknown671c90(robot->getPosition(), 15, &vec);
		if (robot->getGroup()->type_9b8f00() == 4)
			d2r_cefc4c->unknown463890(3)->unknown671c90(robot->getPosition(), 15, &vec);
		d2r_cec054->addPosMark(robot->getPosition(), 15, 1);
		opR1d_4541b0(0x12e, 0, 0);
		if (d2r_cf4718)
		{
			for (unsigned int i = 0; i < vec.size(); i++)
			{
				if (!d2r_cefc4c->unknown4631f0(vec[i]))
					d2r_cec054->unknown8197f0(vec[i]->getPosition(), 0);
			}
		}
		break;
	}
	case 3:
	{
		D2rHItem core;
		vector<D2rHItem> items;
		robot->unknown5cb930(&items);
		for (unsigned int i = 0; i < items.size(); i++)
		{
			if (items[i]->nested_4578a0() == 0)
			{
				core = items[i];
				goto found3;
			}
		}
		SHOWS(0x1f5, "Unable to locate active power source.");
		goto done;
found3:
		START();
		SHOWS(0x1f5, "Rerouting power flow.");
		SHOWR(0x1f6, "[name] emits a wave of energy.");
		if (rng.chance(50))
		{
			SHOWR2(0x1f6, "[name] %2 breaks down.", &core->getName_571db0(0, 0));
			core->setBroken_5795b0(-2, 0);
		}
		vector<Pos> hits;
		Pos origin(*robot->getPosition());
		D2rPt low;
		D2rPt high;
		d2r_cfd44c.getBounds(origin, 20, &low, &high);
		for (int x = low.x; x <= high.x; x++)
		{
			for (int y = low.y; y <= high.y; y++)
			{
				if ((*d2r_cfd44c.at(x, y))->getEntity().isValid() && !d2r_cefc4c->isVisible(x, y))
					hits.push_back(Pos(x, y));
			}
		}
		d2r_cec054->setPath(origin, d2r_cefc4c->getTurn() + 5, &hits);
		opR1d_4541b0(0x12f, 0, 0);
		break;
	}
	case 4:
	{
		bool found = false;
		if (d2r_d1e888->f4 != 0x22 && d2r_d1e888->f4 != 5)
		{
			vector<Pos> exits;
			d2r_cefc4c->unknown714090(&exits);
			if (!exits.empty())
			{
				OpV4c_shuffle_9d7350(exits);
				for (unsigned int i = 0; i < exits.size(); i++)
				{
					vector<Pos> path;
					if (d2r_cfe568.findPath(*robot->getPosition(), exits[i], d2r_cefc30, 0, path))
					{
						robot->setAI(new D2rAI2(robot, 0x19, 0xe));
						robot->ai_45b590()->delegate_459540(exits[i]);
						found = true;
						break;
					}
				}
			}
		}
		if (!found)
		{
			SHOWS(0x1f5, "No evac targets found in memory.");
			goto done;
		}
		else
		{
			STARTC();
			SHOWS(0x1f5, "Triggered evac routine.");
		}
		break;
	}
	case 5:
	{
		if (d2r_d1e888->f4 == 3)
			d2r_cf45d8.unknown77fbc0(0x65);
		D2rPt chute;
		if (!d2r_cefc4c->unknown463040() || !robot->ai_45b590()->unknown5b6130(&chute))
		{
			SHOWS(0x1f5, "No applicable chute records found in memory.");
			goto done;
		}
		else
		{
			START();
			string text = "Pinpointed chute assignment: " + OpQ1_pointToString(chute) + ".";
			SHOW(0x1f5, &text);
			(*d2r_cfd44c.atPoint(chute))->getProp()->unknown65f170();
			d2r_cefc4c->unknown4647d0(chute);
			d2r_cec054->label813050(1, (*d2r_cfd44c.atPoint(chute))->getProp(), 0, 0, 0);
			d2r_cefc4c->unknown9e29b0(&d2r_cefc4c->f720, (*d2r_cfd44c.atPoint(chute))->getProp());
			d2r_cec054->setUnknown38c(chute);
		}
		break;
	}
	case 6:
		clearDijkstraResults();
		d2r_cfe568.unknown40ca20(robot->getPosition(), 0x32, &d2r_cfc1c4, 0);
		if (d2r_d15e58.empty())
		{
			SHOWS(0x1f5, "No applicable machines found in memory.");
			goto done;
		}
		else
		{
			STARTC();
			Pos at(d2r_d15e58.front());
			D2rHProp machine = (*d2r_cfd44c.atPoint(at))->getProp();
			vector<D2rHProp> &parts = d2r_d31640[machine->unknown44ab40()];
			ADDFX(new D2rEffect(6));
			for (unsigned int i = 0; i < parts.size(); i++)
				effect->points.push_back(*parts[i]->getPosition_4184d0());
			OpV4c_shuffle_9d7350(effect->points);
			SHOWA(0x1f5, "Set dismantle target: %2.", &machine->getName_45c5b0());
			robot->ai_45b590()->clearMemory();
			robot->ai_45b590()->unknown4591c0(7);
			robot->ai_45b590()->unknown4591c0(8);
		}
		break;
	case 7:
		if (robot->ai_45b590()->unknown459090() && robot->ai_45b590()->effects_4590f0()->find_458950(7))
		{
			STARTC();
			D2rEffect *hold = robot->ai_45b590()->effects_4590f0()->find_458950(7);
			hold->turn = d2r_cefc4c->getTurn() + 25;
			SHOWA(0x1f5, "Reset hold target: %2.", &hold->target->name_416f40());
			robot->ai_45b590()->clearMemory();
		}
		else
		{
			clearDijkstraResults();
			d2r_cfe568.unknown40ca20(robot->getPosition(), 0x14, &d2r_d2257c, robot.operator->());
			if (d2r_d15e58.empty())
			{
				SHOWS(0x1f5, "Unable to find valid hold target.");
				goto done;
			}
			else
			{
				STARTC();
				Pos at(d2r_d15e58.front());
				D2rHEntity target = (*d2r_cfd44c.atPoint(at))->getEntity();
				target->ai_45b590()->setField_451440(robot);
				ADDFX(new D2rEffect(7));
				effect->turn = d2r_cefc4c->getTurn() + 25;
				effect->target = target;
				SHOWA(0x1f5, "Set hold target: %2.", &target->name_416f40());
				robot->ai_45b590()->clearMemory();
				robot->ai_45b590()->unknown4591c0(6);
			}
		}
		break;
	case 8:
		if (!robot->ai_45b590()->unknown459090() || !robot->ai_45b590()->effects_4590f0()->find_458950(7))
		{
			SHOWS(0x1f5, "No current hold target.");
			goto done;
		}
		else
		{
			effect = robot->ai_45b590()->effects_4590f0()->find_458950(7);
			if (!effect->target.operator->())
			{
				SHOWS(0x1f5, "No current hold target.");
				goto done;
			}
			else
			{
				robot->ai_45b590()->clearMemory();
				if (!robot->unknown5c8820(effect->target))
				{
					SHOWS(0x1f5, "Not currently latched onto hold target.");
					goto done;
				}
				else if (effect->target->getSize() > 1)
				{
					SHOWS(0x1f5, "Current hold target exceeds disposal limits.");
					goto done;
				}
				else
				{
					D2rPt chute;
					if (!d2r_cefc4c->unknown463040() || !robot->ai_45b590()->unknown5b6130(&chute))
					{
						SHOWS(0x1f5, "No applicable chute records found in memory.");
						goto done;
					}
					else
					{
						STARTC();
						ADDFX0(new D2rEffect(8));
						SHOWA(0x1f5, "Scheduling %2 for disposal.", &effect->target->name_416f40());
					}
				}
			}
		}
		break;
	case 9:
		STARTC();
		SHOWS(0x1f5, "Repair routines blocked.");
		ADDFX(new D2rEffect(9));
		robot->ai_45b590()->clearMemory();
		break;
	case 0xa:
		START();
		SHOWS(0x1f5, "Extracting local structural data...");
		d2r_cec054->unknown8071e0(robot, 1);
		robot->ai_45b590()->clearMemoryUnlessPreserved();
		break;
	case 0xb:
		if (!robot->unknown5d5460(0))
		{
			SHOWS(0x1f5, "Mining Laser offline.");
			goto done;
		}
		else
		{
			STARTC();
			SHOWS(0x1f5, "Randomized corridor algorithm. Beginning excavation sequence...");
			ADDFX(new D2rEffect(0xb));
			effect->turn = d2r_cefc4c->getTurn() + 200;
			int dir = d2r_cefc4c->unknown7359d0(robot->getPosition());
			effect->points.push_back(dir == 8 ? d2r_d015d8[rng.rangeInt(0.0f, 3.0f) * 2] : d2r_d015d8[dir]);
			effect->points.push_back(Pos(d2r_d22260.randomInRange_40c130()));
			effect->points.back().y = 0;
			robot->ai_45b590()->clearMemory();
		}
		break;
	case 0xc:
		START();
		SHOWS(0x1f5, "Extracting local subterrain data...");
		d2r_cec054->unknown8071e0(robot, 0);
		robot->ai_45b590()->clearMemoryUnlessPreserved();
		break;
	case 0xd:
	case 0x12:
	case 0x14:
	case 0x19:
	case 0x27:
	case 0x30:
	{
		int kind;
		switch (hack)
		{
		case 0xd:
			kind = 1;
			break;
		case 0x12:
			kind = 3;
			break;
		case 0x14:
			kind = 2;
			break;
		case 0x19:
			kind = 0;
			break;
		case 0x27:
			kind = 4;
			break;
		case 0x30:
			kind = 5;
			break;
		}
		vector<Pos> found;
		if (!d2r_cefc4c->unknown716a60(robot->getPosition(), kind, robot.operator->(), &found))
		{
			string text = "No accessible " + d2r_d3a280[kind] + " found in memory.";
			SHOW(0x1f5, &text);
			goto done;
		}
		else
		{
			START();
			Pos at(found.back());
			string text = "Pinpointed nearest " + d2r_d3a280[kind] + ": " + OpQ1_pointToString(at);
			bool known = false;
			vector<D2rHMarker> &marks = (*d2r_cefc4c->unknown463ec0())[0];
			for (unsigned int i = 0; i < marks.size(); i++)
			{
				if (marks[i]->pos.equals_409b90(at))
				{
					known = true;
					break;
				}
			}
			if (!known && !d2r_cefc4c->unknown463160(at))
			{
				text += " (added to intel).";
				vector<D2rHMarker> &list = (*d2r_cefc4c->unknown463ec0())[0];
				list.push_back(d2r_cefaa8->createC_793190());
				list.back()->unknown6c20b0(0, at, (*d2r_cfd44c.atPoint(at))->getProp()->getInfo_9b8f00()->type);
				d2r_cec034->unknown987de0();
			}
			else
				text += " (already known).";
			SHOW(0x1f5, &text);
		}
		break;
	}
	case 0xe:
	{
		vector<Pos> found;
		if (!d2r_cefc4c->unknown716c30(robot->getPosition(), robot.operator->(), &found))
		{
			string text = "No accessible DSF found in memory.";
			SHOW(0x1f5, &text);
			goto done;
		}
		else
		{
			START();
			Pos at(found.back());
			string text = "Pinpointed nearest DSF Access: " + OpQ1_pointToString(at);
			bool known = false;
			vector<D2rHMarker> &marks = (*d2r_cefc4c->unknown463ec0())[0];
			for (unsigned int i = 0; i < marks.size(); i++)
			{
				if (marks[i]->pos.equals_409b90(at))
				{
					known = true;
					break;
				}
			}
			if (!known && !d2r_cefc4c->unknown463160(at))
			{
				text += " (added to intel).";
				vector<D2rHMarker> &list = (*d2r_cefc4c->unknown463ec0())[0];
				list.push_back(d2r_cefaa8->createC_793190());
				list.back()->unknown6c20b0(0, at, (*d2r_cfd44c.atPoint(at))->getProp()->getInfo_9b8f00()->type);
				d2r_cec034->unknown987de0();
			}
			else
				text += " (already known).";
			SHOW(0x1f5, &text);
			d2r_cefc4c->opw3_unknown729eb0(at, "DSF Access", 1, 1);
		}
		break;
	}
	case 0xf:
	case 0x15:
	{
		vector<D2rHItem> items;
		if (!robot->unknown5cb830(&items))
		{
			string text = hack == 0xf ? "Inventory empty." : "No backups in storage.";
			SHOW(0x1f5, &text);
			goto done;
		}
		else
		{
			STARTC();
			string text = hack == 0xf ? "Dumping inventory..." : "Decompressing backups for release...";
			SHOW(0x1f5, &text);
			vector<int> vec;
			vector<int> hits;
			for (int i = 0; i < items.size(); i++)
			{
				if (!items[i]->stats_9b4350()->b74 || hack == 0x15)
				{
					D2rPt drop;
					if (d2r_cefc4c->unknown71bc10(robot->unknown45a4c0(), &drop))
					{
						d2r_cf45d8.unknown77ffb0(items[i]->getNestedField(), 0);
						int index = OpS8b_Fn9d4660(vec, items[i]->getNestedField());
						if (index == -1)
						{
							vec.push_back(items[i]->getNestedField());
							hits.push_back(1);
						}
						else
							hits[index]++;
						items[i]->unknown57a0f0(&drop, 1, 0);
						OpQ5_eraseStep_9d6440(items, i);
					}
				}
			}
			for (unsigned int i = 0; i < vec.size(); i++)
			{
				text = "  " + intToString(hits[i]) + "x " + d2r_d2d1c4[vec[i]]->name;
				SHOW(0x1f5, &text);
			}
			if (!items.empty())
			{
				string text = "Insufficient room to drop " + opw8_countString(items.size(), "part") + ".";
				SHOW(0x1f5, &text);
			}
		}
		break;
	}
	case 0x10:
	{
		D2rSquad2 *squad = d2r_cf6428.unknown683310(robot->ai_45b590()->unknown458e70());
		if (!squad)
		{
			SHOWS(0x1f5, "No applicable reinforcements on record.");
			goto done;
		}
		else
		{
			STARTC();
			SHOWS(0x1f5, "Threat cleared, reinforcements rerouted to exit.");
			d2r_cf6428.unknown68cd80(squad);
			robot->ai_45b590()->setField_45b090(D2rHEntity());
		}
		break;
	}
	case 0x11:
	{
		vector<Pos> *stock = d2r_cefc4c->unknown463c20();
		vector<Pos> cells;
		D2rHItem item;
		for (int i = 0; i < stock->size(); i++)
		{
			item = (*d2r_cfd44c.atPoint((*stock)[i]))->getItem();
			if (item.isNull())
				OpQ5_eraseStep_9d7300(*stock, i);
			else if (item->stats_9b4350()->f94 == 0)
				cells.push_back((*stock)[i]);
		}
		if (cells.empty())
		{
			SHOWS(0x1f5, "No stockpiles on record.");
			goto done;
		}
		else
		{
			START();
			string text = "Pinpointed " + intToString(cells.size()) + " registered component " + (cells.size() == 1 ? "stockpile." : "stockpiles.");
			SHOW(0x1f5, &text);
			int level = 14;
			vector<D2rHMarker> &res = (*d2r_cefc4c->unknown463ec0())[level];
			res.clear();
			string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ09123456789";
			string desc;
			for (unsigned int i = 0; i < cells.size(); i++)
			{
				desc.clear();
				for (int j = 0; j < 10; j++)
					desc += randomChar_4085b0(chars);
				text = "  " + desc + ": " + (*d2r_cfd44c.atPoint(cells[i]))->getItem()->unknown457990();
				SHOW(0x1f5, &text);
				res.push_back(d2r_cefaa8->createC_793190());
				res.back()->unknown6c20b0(level, cells[i], (*d2r_cfd44c.atPoint(cells[i]))->getItem()->getNestedField());
				d2r_cefc4c->unknown4647d0(cells[i]);
			}
			d2r_cec034->unknown987de0();
		}
		break;
	}
	case 0x13:
		STARTC();
		SHOWS(0x1f5, "Collection routines blocked.");
		ADDFX(new D2rEffect(0x13));
		break;
	case 0x16:
		clearDijkstraResults();
		d2r_cfe568.unknown40ca20(robot->getPosition(), 0x14, &d2r_cf45d4, robot.operator->());
		if (d2r_d15e58.empty())
		{
			SHOWS(0x1f5, "Unable to find valid deconstruct target.");
			goto done;
		}
		else
		{
			STARTC();
			Pos at(d2r_d15e58.front());
			D2rHEntity target = (*d2r_cfd44c.atPoint(at))->getEntity();
			ADDFX(new D2rEffect(0x16));
			effect->target = target;
			SHOWA(0x1f5, "Set deconstruct target: %2.", &target->name_416f40());
			target->ai_45b590()->resetField_459340();
			robot->ai_45b590()->clearMemory();
		}
		break;
	case 0x17:
	{
		START();
		string text = "Querying alert level: ";
		if (d2r_cf6474)
			text += "Sterilization";
		else if (d2r_cf645c)
			text += d2r_cf6468 ? "Maximum Security" : "High Security";
		else
			text += opr1c_getSecurityName_4332b0(d2r_cf6428.level);
		SHOW(0x1f5, &text);
		break;
	}
	case 0x18:
		if (d2r_cf6474 || d2r_cf645c)
			SHOWS(0x1f5, "Remote reporting system inaccessible.");
		else if (d2r_cf6428.level == 0)
			SHOWS(0x1f5, "No threats on record.");
		else
		{
			STARTC();
			int count = d2r_d2c658.unknown472c90(0x33f) - 1;
			int old = (int)d2r_b91a34;
			for (int i = 0; i < count; i++)
				old += 25;
			if (old > -50)
				old = -50;
			d2r_cf6428.unknown682420(0x27, old);
			string text;
			if (old <= -150)
				text = "Purged multiple threat records, alert level lowered.";
			else if (old <= -100)
				text = "Purged threat record, alert level lowered.";
			else
				text = "Purged minor threat record, alert level lowered.";
			SHOW(0x1f5, &text);
		}
		break;
	case 0x1a:
	case 0x1b:
	case 0x1c:
	{
		STARTC();
		SHOWS(0x1f5, "Extracting local trap data...");
		clearDijkstraResults();
		int filter = 1;
		d2r_cfe568.unknown40ca20(robot->getPosition(), 0x1e, &d2r_cfd428, &filter);
		vector<Pos> *results = &d2r_d15e58;
		if (results->empty())
			SHOWS(0x1f5, "No trap data on record.");
		else
		{
			vector<Pos> cells;
			vector<int> groups;
			for (unsigned int i = 0; i < results->size(); i++)
				OpT8b_Fn9db000(groups, (*d2r_cfd44c.atPoint((*results)[i]))->getProp()->stats_44b020()->f4);
			results->clear();
			for (unsigned int i = 0; i < groups.size(); i++)
			{
				for (unsigned int j = 0; j < d2r_d20248[groups[i]].size(); j++)
					results->push_back(*d2r_d20248[groups[i]][j]->getPosition_4184d0());
			}
			if (hack == 0x1a)
			{
				string text = "Pinpointed " + opw8_countString(results->size(), "trap") + " in " + opw8_countString(groups.size(), "array") + ":";
				SHOW(0x1f5, &text);
				for (unsigned int i = 0; i < groups.size(); i++)
				{
					text = "  " + intToString(d2r_d20248[groups[i]].size()) + "x " + d2r_d20248[groups[i]].front()->getName_45c5b0();
					SHOW(0x1f5, &text);
					for (unsigned int j = 0; j < d2r_d20248[groups[i]].size(); j++)
					{
						d2r_d20248[groups[i]][j]->unknown65f170();
						d2r_cefc4c->unknown4647d0(*d2r_d20248[groups[i]][j]->getPosition_4184d0());
					}
				}
				OpS8c_appendUnique((vector<Point> &)cells,(vector<Point> &)*results);
				for (unsigned int i = 0; i < results->size(); i++)
					d2r_cefc4c->unknown9e29b0(&d2r_cefc4c->f720, (*d2r_cfd44c.atPoint((*results)[i]))->getProp());
			}
			else
			{
				vector<int> armed;
				for (unsigned int i = 0; i < groups.size(); i++)
				{
					for (unsigned int j = 0; j < d2r_d20248[groups[i]].size(); j++)
					{
						if (d2r_d20248[groups[i]][j]->stats_44b020()->f10 == 3)
						{
							armed.push_back(groups[i]);
							break;
						}
					}
				}
				if (armed.empty())
					SHOWS(0x1f5, "No applicable trap data on record.");
				else
				{
					vector<D2rHProp> vec(d2r_d20248[armed.front()]);
					string title = vec.front()->getName_45c5b0();
					int count = 0;
					for (unsigned int i = 0; i < vec.size(); i++)
					{
						if (vec[i]->stats_44b020()->f10 == 3)
						{
							if (hack == 0x1c)
							{
								vec[i]->stats_44b020()->f10 = 0;
								vec[i]->unknown65f170();
								d2r_cefc4c->unknown4647d0(*vec[i]->getPosition_4184d0());
								OpV4c_Fn9d3020((vector<Point> &)cells,*(Point *)vec[i]->getPosition_4184d0());
								d2r_cefc4c->unknown9e29b0(&d2r_cefc4c->f720, vec[i]);
								count++;
							}
							else
							{
								Pos at(*vec[i]->getPosition_4184d0());
								(*d2r_cfd44c.atPoint(at))->removeProp(0, 4);
								d2r_cefc4c->unknown4647a0(at, 1);
								count++;
							}
						}
					}
					string msg = (hack == 0x1c ? "Reprogrammed " : "Disarmed ") + opw8_countString(count, title) + ".";
					SHOW(0x1f5, &msg);
				}
			}
			if (!cells.empty())
			{
				for (unsigned int i = 0; i < cells.size(); i++)
				{
					if ((*d2r_cfd44c.atPoint(cells[i]))->getProp().isValid())
					{
						d2r_cec054->label813050(1, (*d2r_cfd44c.atPoint(cells[i]))->getProp(), 0, 0, 0);
						d2r_cefc4c->unknown9e29b0(&d2r_cefc4c->f720, (*d2r_cfd44c.atPoint(cells[i]))->getProp());
					}
				}
			}
		}
		break;
	}
	case 0x1d:
		STARTC();
		SHOWS(0x1f5, "Reporting routines blocked.");
		ADDFX(new D2rEffect(0x1d));
		break;
	case 0x1e:
		STARTC();
		SHOWS(0x1f5, "Tweaked reinforcement routines.");
		ADDFX(new D2rEffect(0x1e));
		break;
	case 0x1f:
		if (!d2r_cf6478.empty())
		{
			D2rSquad2 *squad = 0;
			for (int i = d2r_cf6478.size() - 1; i >= 0; i--)
			{
				if (d2r_cf6478[i]->type == 4 && !d2r_cf6478[i]->test_45e820())
				{
					squad = d2r_cf6478[i];
					break;
				}
			}
			if (!squad)
				SHOWS(0x1f5, "No investigations on record.");
			else if (d2r_d1e888->f4 == 0x22)
				SHOWS(0x1f5, "Unable to override squad orders.");
			else
			{
				STARTC();
				string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ09123456789";
				string id;
				for (int j = 0; j < 10; j++)
					id += randomChar_4085b0(chars);
				string text = "Recalled " + d2r_d2f3c0 + " squad " + id + ".";
				d2r_cf6428.unknown68cd80(squad);
				SHOW(0x1f5, &text);
			}
		}
		break;
	case 0x20:
	{
		STARTC();
		SHOWS(0x1f5, "Cleared repair queue and pending orders.");
		OpQ5_clearObjects_9d0670(&d2r_cf0fa8);
		vector<D2rHEntity> &members = d2r_cefc4c->unknown463890(4)->members_416f40();
		for (unsigned int i = 0; i < members.size(); i++)
		{
			if (members[i]->getFaction() == 2)
				members[i]->ai_45b590()->delegate_459520(Pos(-1));
		}
		break;
	}
	case 0x21:
	{
		STARTC();
		SHOWS(0x1f5, "Cleared collection queue and pending orders.");
		d2r_d33d74.clear();
		vector<D2rHEntity> &members = d2r_cefc4c->unknown463890(4)->members_416f40();
		for (unsigned int i = 0; i < members.size(); i++)
		{
			if (members[i]->getFaction() == 5)
				members[i]->ai_45b590()->delegate_459520(Pos(-1));
		}
		break;
	}
	case 0x22:
		if (robot->ai_45b590()->type_9b8f00() != 2 || robot->ai_45b590()->route_458ef0()->size() != 2)
			SHOWS(0x1f5, "No patrol data available.");
		else
		{
			START();
			SHOWS(0x1f5, "Extracting route scan data...");
			d2r_cec054->unknown8074d0(robot);
		}
		break;
	case 0x23:
	{
		STARTC();
		int old = 0;
		int count = 0;
		int kind = 0;
		int layer = 2;
		vector<D2rHMarker> &markers = (*d2r_cefc4c->unknown463ec0())[layer];
		old = markers.size();
		bool dirty = false;
		for (int i = 0; i < markers.size(); i++)
		{
			if (OpQ1_distanceCeil_40a3f0(markers[i]->pos, *robot->getPosition()) <= 40)
			{
				OpQ5_eraseStep_9d6440(markers, i);
				dirty = true;
			}
		}
		for (unsigned int i = 0; i < d2r_cf6478.size(); i++)
		{
			if (d2r_cf6478[i]->type == kind && !d2r_cf6478[i]->test_45e820() && OpQ1_distanceCeil_40a3f0(*d2r_cf6478[i]->leader->getPosition(), *robot->getPosition()) <= 40)
			{
				count++;
				dirty = true;
				markers.push_back(d2r_cefaa8->createC_793190());
				markers.back()->unknown6c20b0(layer, d2r_cf6478[i]->leader->unknown45a4c0(), -1);
			}
		}
		string line;
		if (count == 0)
			line = "No nearby security on record.";
		else if (old > count)
			line = "Removed " + opw8_countString(old - count, "inapplicable security record") + ".";
		else
			line = "Added " + opw8_countString(count, "security record") + ".";
		SHOW(0x1f5, &line);
		if (dirty)
			d2r_cec034->unknown987de0();
		break;
	}
	case 0x24:
		if (robot->ai_45b590()->unknown459090() && robot->ai_45b590()->effects_4590f0()->find_458950(0x24))
		{
			SHOWS(0x1f5, "Active feed link already exists.");
			goto done;
		}
		else
		{
			STARTC();
			SHOWS(0x1f5, "Installed feed listener.");
			ADDFX(new D2rEffect(0x24));
			d2r_cefc4c->unknown4656d0(robot);
		}
		break;
	case 0x25:
	case 0x26:
	{
		D2rHItem part = robot->unknown5d2380(0x46);
		if (part.isNull())
			part = robot->unknown5d2380(0x47);
		if (part.isNull())
		{
			SHOWS(0x1f5, "Unable to find suitable target system.");
			goto done;
		}
		else
		{
			STARTC();
			if (hack == 0x25)
			{
				string text = part->getName_571db0(0, 0) + " permanently disabled.";
				SHOW(0x1f5, &text);
				part->setBroken_5795b0(-2, 0);
			}
			else
			{
				string text = "Reprogrammed remote defense routines.";
				SHOW(0x1f5, &text);
				ADDFX(new D2rEffect(0x26));
			}
		}
		break;
	}
	case 0x28:
	{
		D2rHItem part = robot->unknown5d2380(0x73);
		if (part.isNull())
		{
			SHOWS(0x1f5, "Unable to find suitable target system.");
			goto done;
		}
		else
		{
			STARTC();
			string text = part->getName_571db0(0, 0) + " permanently disabled.";
			SHOW(0x1f5, &text);
			part->setBroken_5795b0(-2, 0);
		}
		break;
	}
	case 0x29:
	{
		D2rHItem item;
		vector<D2rHItem> inv;
		d2r_cefc4c->getPlayer()->unknown5cb830(&inv);
		bool updated = false;
		int count = 0;
		int result = 0;
		vector<int> ids;
		D2rRect area;
		d2r_cfd44c.getRect_9b4430(robot->getPosition(), 20, &area);
		for (int x = area.x; x <= area.x2; x++)
		{
			for (int y = area.y; y <= area.y2; y++)
			{
				if ((*d2r_cfd44c.at(x, y))->getItem().isValid() && (*d2r_cfd44c.at(x, y))->getItem()->stats_9b4350()->f94 != 0)
				{
					count++;
					item = (*d2r_cfd44c.at(x, y))->getItem();
					if (d2r_cf45d8.unknown77ffb0(item->getNestedField(), 0))
					{
						result++;
						OpT8b_Fn9db000(ids, item->getNestedField());
						for (unsigned int i = 0; i < inv.size(); i++)
						{
							if (inv[i]->getNestedField() == item->getNestedField())
							{
								updated = true;
								break;
							}
						}
					}
					d2r_cefc4c->opw3_unknown724420(x, y);
				}
			}
		}
		if (updated)
			d2r_cec08c->reopen8a2ce0(4, D2rHEntity());
		START();
		string line = "Extracted " + opw8_countString(result, "prototype ID") + ".";
		SHOW(0x1f5, &line);
		line = "Pinpointed " + opw8_countString(count, "registered prototype") + ".";
		SHOW(0x1f5, &line);
		break;
	}
	case 0x2a:
	{
		STARTC();
		SHOWS(0x1f5, "Accessing prototype database...");
		D2rWL &pool = d2r_cefc4c->unknown463a30();
		vector<int> ids;
		if (pool.total_9b81d0())
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					int id = pool.pick();
					if (d2r_cf45d8.unknown77ffb0(id, 0))
					{
						ids.push_back(id);
						break;
					}
				}
			}
		}
		if (ids.empty())
			SHOWS(0x1f5, "No applicable prototype records.");
		else
		{
			string text;
			for (unsigned int i = 0; i < ids.size(); i++)
			{
				text = "  " + d2r_d2d1c4[ids[i]]->name;
				SHOW(0x1f5, &text);
			}
			text = "Found " + opw8_countString(ids.size(), "accessible ID") + ".";
			SHOW(0x1f5, &text);
			vector<D2rHItem> inv;
			d2r_cefc4c->getPlayer()->unknown5cb830(&inv);
			for (unsigned int i = 0; i < inv.size(); i++)
			{
				if (OpX5_containsRecord(ids, inv[i]->getNestedField()))
				{
					d2r_cec08c->reopen8a2ce0(4, D2rHEntity());
					break;
				}
			}
		}
		break;
	}
	case 0x2b:
	{
		STARTC();
		SHOWS(0x1f5, "Accessing schematics database...");
		vector<int> ids;
		for (int i = 0; i < 10; i++)
		{
			D2rWL &pool = rng.chance(75) ? d2r_cefc4c->unknown463a30() : d2r_cefc4c->unknown463a10();
			if (pool.total_9b81d0())
			{
				for (int j = 0; j < 20; j++)
				{
					int id = pool.pick();
					if (!d2r_cf4844[id] && d2r_d2d1c4[id]->known)
					{
						d2r_cf45d8.unknown780380(id, 5);
						ids.push_back(id);
						break;
					}
				}
			}
		}
		if (ids.empty())
			SHOWS(0x1f5, "No applicable schematic records.");
		else
		{
			string text;
			for (unsigned int i = 0; i < ids.size(); i++)
			{
				text = "  " + d2r_d2d1c4[ids[i]]->name;
				SHOW(0x1f5, &text);
			}
			text = "Found " + opw8_countString(ids.size(), "accessible schematic") + ".";
			SHOW(0x1f5, &text);
			vector<D2rHItem> inv;
			d2r_cefc4c->getPlayer()->unknown5cb830(&inv);
			for (unsigned int i = 0; i < inv.size(); i++)
			{
				if (OpX5_containsRecord(ids, inv[i]->getNestedField()))
				{
					d2r_cec08c->reopen8a2ce0(4, D2rHEntity());
					break;
				}
			}
		}
		break;
	}
	case 0x2c:
	{
		STARTC();
		SHOWS(0x1f5, "Accessing analysis database...");
		int group = d2r_d1e888->unknown46ed20();
		vector<int> candidates;
		for (int i = 0; i < d2r_d25de0.size(); i++)
		{
			if (!d2r_d25de0[i]->f170.empty() && d2r_d25de0[i]->f24 == 1 && OpT8b_Fn9daf80(group - 2, d2r_d25de0[i]->f68, group + 2) && !d2r_cf4910[i])
				candidates.push_back(i);
		}
		vector<int> vec;
		int count = rng.rangeInt(3.0f, 5.0f);
		for (int i = 0; i < count; i++)
		{
			if (candidates.empty())
				break;
			vec.push_back(OpS8d_popRandom(candidates));
		}
		if (vec.empty())
			SHOWS(0x1f5, "No applicable analyses.");
		else
		{
			string text;
			for (unsigned int i = 0; i < vec.size(); i++)
			{
				text = "  " + d2r_d25de0[vec[i]]->f1ac;
				SHOW(0x1f5, &text);
				d2r_cf45d8.unknown780700(i, 0);
			}
			text = "Found " + opw8_countString(vec.size(), "accessible record") + ".";
			SHOW(0x1f5, &text);
		}
		break;
	}
	case 0x2d:
		STARTC();
		SHOWS(0x1f5, "Processing routines blocked.");
		ADDFX(new D2rEffect(0x2d));
		robot->ai_45b590()->unknown5b5220();
		robot->ai_45b590()->delegate_459520(Pos(-1));
		d2r_cefc4c->opw3_unknown72f5b0(robot);
		break;
	case 0x2e:
		STARTC();
		SHOWS(0x1f5, "Triggered emergency deployment routine.");
		robot->die(0, 10, D2rHEntity(), 1, 0, 0, 0, 0);
		break;
	case 0x2f:
	{
		STARTC();
		SHOWS(0x1f5, "Extracting local emergency access data...");
		clearDijkstraResults();
		int filter = 1;
		d2r_cfe568.unknown40ca20(robot->getPosition(), 0x32, &d2r_d297a8, &filter);
		if (d2r_d15e58.empty())
			SHOWS(0x1f5, "No emergency access points on record.");
		else
		{
			int hits = 0;
			for (unsigned int i = 0; i < d2r_d15e58.size(); i++)
			{
				hits++;
				d2r_cefc4c->unknown734d60(d2r_d15e58[i]);
				d2r_cefc4c->unknown4647a0(d2r_d15e58[i], 1);
				d2r_cec054->labelAccess80e3a0(1, d2r_d15e58[i]);
			}
			string text = "Pinpointed " + opw8_countString(hits, "location") + ".";
			SHOW(0x1f5, &text);
		}
		break;
	}
	case 0x31:
	{
		D2rSquad2 *squad = d2r_cf6428.unknown683310(robot);
		if (!squad)
		{
			SHOWS(0x1f5, "Not a squad leader system, no relevant data available.");
			goto done;
		}
		else if (squad->type != 2 || squad->f8 == -2 || squad->f18 != 0)
		{
			SHOWS(0x1f5, "Not a patrol squad, no relevant data available.");
			goto done;
		}
		else
		{
			START();
			vector<D2rRoute *> *routes = d2r_cefc4c->unknown463df0();
			OpQ5_clearObjects_9e2650(*routes);
			int hits = 0;
			for (unsigned int i = 0; i < d2r_cf6478.size(); i++)
			{
				if (d2r_cf6478[i]->type == 2 && !d2r_cf6478[i]->test_45e820())
				{
					routes->push_back(new D2rRoute(d2r_cf6478[i]->leader->getFaction()));
					routes->back()->points = d2r_cf6478[i]->leader->ai_45b590()->unknown4549b0();
					if (routes->back()->points.empty())
						OpQ5_deleteBack_9e32e0(*routes);
					else
					{
						hits++;
						vector<Pos> &points = routes->back()->points;
						for (unsigned int j = 0; j < points.size(); j++)
						{
							if ((*d2r_cfd44c.atPoint(points[j]))->isEdge())
								d2r_cefc4c->unknown734d60(points[j]);
							d2r_cefc4c->unknown4647a0(points[j], 1);
						}
						d2r_cec054->unknown8079e0(routes->back());
					}
				}
			}
			string text = "Traced " + opw8_countString(hits, "patrol route") + ".";
			SHOW(0x1f5, &text);
			if (hits)
				d2r_cefc4c->unknown465140();
		}
		break;
	}
	case 0x32:
		if (d2r_cefc4c->unknown4635c0(robot))
		{
			SHOWS(0x1f5, "Already have visual feed link with target.");
			goto done;
		}
		else
		{
			STARTC();
			if (robot->ai_45b590()->unknown459090() && robot->ai_45b590()->effects_4590f0()->find_458950(0x32))
			{
				string text = "Re-established visual feed link, T-" + intToString(100) + " until cutoff.";
				SHOW(0x1f5, &text);
				robot->ai_45b590()->effects_4590f0()->find_458950(0x32)->turn = d2r_cefc4c->getTurn() + 100;
			}
			else
			{
				string text = "Established visual feed link, T-" + intToString(100) + " until cutoff.";
				SHOW(0x1f5, &text);
				ADDFX(new D2rEffect(0x32));
				effect->turn = d2r_cefc4c->getTurn() + 100;
				d2r_cefc4c->opw3_unknown72e990(robot);
				d2r_cec054->unknown807b40();
				robot->ai_45b590()->clearMemory();
			}
		}
		break;
	case 0x33:
		STARTC();
		if (!robot->ai_45b590()->chase(d2r_cefc4c->getPlayer(), 1, 10000, 0, 0))
		{
			SHOWS(0x1f5, "Unable to set target.");
			goto done;
		}
		else
			SHOWS(0x1f5, "Set priority target: LRC-V3.");
		break;
	case 0x34:
	{
		STARTC();
		effect = robot->effects_45ae50()->add_57f140(static_cast<D2rEffect *&&>(new D2rEffect(0x34)));
		effect->turn = d2r_cefc4c->getTurn() + 15;
		string text = "Triggered propulsion reboot sequence, T-" + intToString(15) + " to completion.";
		SHOW(0x1f5, &text);
		robot->unknown45af20(0x35);
		break;
	}
	case 0x35:
		if (robot->unknown45ae30() && robot->effects_45ae50()->find_458950(0x35))
		{
			SHOWS(0x1f5, "Found existing mod algorithms.");
			goto done;
		}
		else if (robot->unknown45ae30() && robot->effects_45ae50()->find_458950(0x34))
			SHOWS(0x1f5, "Reboot in progress, unable to apply modifications.");
		else
		{
			STARTC();
			effect = robot->effects_45ae50()->add_57f140(static_cast<D2rEffect *&&>(new D2rEffect(0x35)));
			string text = "Applied mods to movement regulation algorithms, effective base speed reduced by 50%.";
			SHOW(0x1f5, &text);
		}
		break;
	case 0x36:
		if (robot->unknown45ae30() && robot->effects_45ae50()->find_458950(0x36))
		{
			SHOWS(0x1f5, "Found existing mod algorithms.");
			goto done;
		}
		else
		{
			STARTC();
			effect = robot->effects_45ae50()->add_57f140(static_cast<D2rEffect *&&>(new D2rEffect(0x36)));
			string text = "Applied mods to targeting algorithms, effective accuracy halved.";
			SHOW(0x1f5, &text);
		}
		break;
	case 0x37:
		if (robot->ai_45b590()->unknown459090() && robot->ai_45b590()->effects_4590f0()->find_458950(0x37))
		{
			SHOWS(0x1f5, "Target already marked.");
			d2r_cefc4c->unknown465160(robot);
			goto done;
		}
		else
		{
			STARTC();
			bool same = robot == d2r_cefc4c->unknown463e10();
			d2r_cefc4c->unknown465160(robot);
			robot->ai_45b590()->effects_4590f0()->add_57f140(static_cast<D2rEffect *&&>(new D2rEffect(0x37)));
			SHOWA(0x1f5, "System marked: %2.", &robot->name_416f40());
		}
		break;
	case 0x38:
		if (robot->ai_45b590()->unknown459090() && robot->ai_45b590()->effects_4590f0()->find_458950(0x38))
		{
			SHOWS(0x1f5, "Relevant algorithms already linked.");
			goto done;
		}
		else
		{
			STARTC();
			robot->ai_45b590()->effects_4590f0()->add_57f140(static_cast<D2rEffect *&&>(new D2rEffect(0x38)));
			SHOWS(0x1f5, "Linking to adaptive combat algorithms.");
		}
		break;
	case 0x39:
		if (robot->ai_45b590()->unknown459090() && robot->ai_45b590()->effects_4590f0()->find_458950(0x39))
		{
			SHOWS(0x1f5, "Found existing data sniffer.");
			goto done;
		}
		else
		{
			STARTC();
			robot->ai_45b590()->effects_4590f0()->add_57f140(static_cast<D2rEffect *&&>(new D2rEffect(0x39)));
			SHOWS(0x1f5, "Sniffer active, transmitting defense network data.");
			d2r_cefc4c->unknown465180(robot);
		}
		break;
	case 0x3a:
		if (robot->ai_45b590()->unknown459090() && robot->ai_45b590()->effects_4590f0()->find_458950(0x3a))
		{
			SHOWS(0x1f5, "Found active disruption routine.");
			goto done;
		}
		else
		{
			STARTC();
			robot->ai_45b590()->effects_4590f0()->add_57f140(static_cast<D2rEffect *&&>(new D2rEffect(0x3a)));
			SHOWS(0x1f5, "Initiated network disruption routine.");
			d2r_cefc4c->unknown4651b0(robot);
		}
		break;
	case 0x3b:
	{
		D2rHItem engine;
		vector<D2rHItem> parts;
		robot->unknown5cb930(&parts);
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			if (parts[i]->nested_4578a0() == 0)
			{
				engine = parts[i];
				goto found3b;
			}
		}
		SHOWS(0x1f5, "Unable to locate active power source.");
		goto done;
found3b:
		STARTC();
		SHOWS(0x1f5, "Tweaking power source heat flow.");
		if (rng.chance(50))
		{
			SHOWR2(0x1f6, "[name] %2 breaks down.", &engine->getName_571db0(0, 0));
			engine->setBroken_5795b0(-2, 0);
		}
		robot->unknown45b210(250);
		break;
	}
	case 0x3c:
		if (robot->unknown45ae30() && robot->effects_45ae50()->find_458950(0x3c))
		{
			SHOWS(0x1f5, "Found active overload routine.");
			goto done;
		}
		else
		{
			D2rHItem engine;
			vector<D2rHItem> parts;
			robot->unknown5cb930(&parts);
			for (unsigned int i = 0; i < parts.size(); i++)
			{
				if (parts[i]->nested_4578a0() == 0 && parts[i]->stats_9b4350()->f1a8 != 0)
				{
					engine = parts[i];
					goto found3c;
				}
			}
			SHOWS(0x1f5, "Unable to locate active power source.");
			goto done;
found3c:
			STARTC();
			int last = d2r_d22268.randomInRange_40c130();
			effect = robot->effects_45ae50()->add_57f140(static_cast<D2rEffect *&&>(new D2rEffect(0x3c)));
			effect->turn = d2r_cefc4c->getTurn() + last;
			effect->target = d2r_cefc4c->getPlayer();
			string text = "Initiated overload sequence, T-" + intToString(last) + " to critical power.";
			SHOW(0x1f5, &text);
		}
		break;
	case 0x3d:
		if (robot->unknown45ae30() && robot->effects_45ae50()->find_458950(0x3d))
		{
			SHOWS(0x1f5, "Found active resonance routine.");
			goto done;
		}
		else
		{
			D2rHItem engine;
			vector<D2rHItem> parts;
			robot->unknown5cb930(&parts);
			for (unsigned int i = 0; i < parts.size(); i++)
			{
				if (parts[i]->nested_4578a0() == 0 && parts[i]->stats_9b4350()->f1a8 != 0)
				{
					engine = parts[i];
					goto found3d;
				}
			}
			SHOWS(0x1f5, "Unable to locate active power source.");
			goto done;
found3d:
			STARTC();
			effect = robot->effects_45ae50()->add_57f140(static_cast<D2rEffect *&&>(new D2rEffect(0x3d)));
			effect->target = d2r_cefc4c->getPlayer();
			string text = "Amplifying resonance, compromised power stability.";
			SHOW(0x1f5, &text);
		}
		break;
	case 0x3e:
		STARTC();
		SHOWS(0x1f5, "Installed hostile record filter.");
		if (robot->ai_45b590()->unknown5b3890(d2r_cefc4c->getPlayer(), 0))
			SHOWS(0x1f5, "Deleted hostile record.");
		ADDFX(new D2rEffect(0x3e));
		effect->turn = d2r_cefc4c->getTurn() + 10;
		break;
	case 0x3f:
	{
		vector<D2rHItem> found;
		robot->unknown5cb930(&found);
		for (int i = 0; i < found.size(); i++)
		{
			if (found[i]->nested_4578a0() != 3)
				OpQ5_eraseStep_9d6440(found, i);
		}
		if (found.empty())
		{
			SHOWS(0x1f5, "Unable to locate active weapons.");
			goto done;
		}
		STARTC();
		string text = "Deactivating " + opw8_countString(found.size(), "weapon system") + ".";
		SHOW(0x1f5, &text);
		for (unsigned int i = 0; i < found.size(); i++)
		{
			found[i]->setActive(false);
			found[i]->setActivateOkayTurn(d2r_cefc4c->getTurn() + 20);
		}
		break;
	}
	case 0x40:
	{
		STARTC();
		int level = d2r_d305d8.randomInRange_40c130();
		string text = "Initiating full reboot, ETC: " + intToString(level) + ".";
		SHOWE(0x1f5, &text);
		if (d2r_cefc4c->getPlayer()->isHostileTo(robot))
			d2r_cf45d8.unknown77fbc0(0x6a);
		opR1d_4541b0(0x6a, 0, 0);
		robot->unknown5fd900(1, level);
		break;
	}
	case 0x41:
		STARTC();
		SHOWS(0x1f5, "Shutting down primary systems.");
		robot->ai_45b590()->unknown5b5220();
		robot->unknown5fd900(2, 0);
		opR1d_454260(robot->getPosition(), 0x136);
		break;
	case 0x43:
	case 0x44:
		if (OpQ1_distanceCeil_40a3f0(robot->unknown45a4c0(), *d2r_cefc4c->getPlayer()->getPosition()) > 5)
		{
			string text = "System outside max range to establish control (" + intToString(5) + ").";
			SHOW(0x1f5, &text);
			goto done;
		}
	case 0x42:
	case 0x45:
	case 0x46:
	case 0x47:
	{
		STARTC();
		int type = robot->getGroup()->type_9b4350();
		robot->unknown5fdab0();
		robot->removeEffectsA(0);
		robot->changeFaction(d2r_cefc4c->unknown463890(hack == 0x42 ? 2 : 1), 1);
		opR1d_4541b0(0x6b, 0, 0);
		switch (hack)
		{
		case 0x42:
			SHOWS(0x1f5, "Rewriting IFF filter.");
			ADDFX(new D2rEffect(0x42));
			effect->turn = d2r_cefc4c->getTurn() + 10;
			effect->points.push_back(Pos(type));
			break;
		case 0x43:
		case 0x44:
			SHOWS(0x1f5, "Hijacking control node.");
			if (d2r_b95758[robot->stats_9b4350()->f48])
				LOGN(0x8c);
			ADDFX(new D2rEffect(hack));
			effect->points.push_back(Pos(type));
			robot->ai_45b590()->setFollowEntity(d2r_cefc4c->getPlayer(), 0);
			break;
		case 0x45:
		case 0x46:
		case 0x47:
		{
			SHOWS(0x1f5, "Rerouting network defenses.");
			SHOWS(0x1f5, "Erasing system data.");
			if (hack == 0x47)
				SHOWS(0x1f5, "Penetrating internal systems.");
			string text = "Installing primary routines, ETC: " + intToString(6) + ".";
			SHOW(0x1f5, &text);
			if (hack == 0x47)
			{
				LOGN(0x8e);
				d2r_cf45d8.unknown77fbc0(0x6d);
				robot->unknown45b340(new Pos(d2r_d2f0f8[0x30], 1));
			}
			else if (d2r_b95758[robot->stats_9b4350()->f48])
				LOGN(0x8d);
			if (d2r_cefc4c->getPlayer()->unknown5cb680(d2r_cefc4c->unknown463890(type)))
				d2r_cf45d8.unknown77fbc0(0x6c);
			if (robot->getFaction() == 0x19 && robot->getAiType() == 1)
				d2r_cf45d8.unknown77fbc0(0x12b);
			robot->unknown5fd900(1, 6);
			break;
		}
		}
		break;
	}
	break;
	//@@CASES
	case 0x49:
		unknown953c70();
		return;
	}
	if (chain && d2r_cf4a04[6] && rng.chance(d2r_b98948[d2r_cf4a04[6]]))
	{
		D2rHEntity where;
		int first = 99999;
		D2rHEntity target;
		vector<int> ranks;
		vector<D2rHItem> vec;
		D2rPt lo;
		D2rPt bottom;
		int range = d2r_cefc4c->unknown463690();
		d2r_cfd44c.getBounds(*d2r_cefc4c->getPlayer()->getPosition(), range, &lo, &bottom);
		for (int x = lo.x; x <= bottom.x; x++)
		{
			for (int y = lo.y; y <= bottom.y; y++)
			{
				if ((*d2r_cfd44c.at(x, y))->getEntity().isValid() && (*d2r_cfd44c.at(x, y))->getEntity() != robot && d2r_cefc4c->unknown463400((*d2r_cfd44c.at(x, y))->getEntity()))
				{
					target = (*d2r_cfd44c.at(x, y))->getEntity();
					if (!target->getTarget())
					{
						int dist = OpQ1_distanceCeil_40a3f0(here, target->unknown45a4c0());
						if (where.isNull() || dist < first)
						{
							ranks.clear();
							opr5f_unknown953d90(*(HEntity *)&target,(vector<unsigned int> *)&ranks);
							if (OpX5_containsRecord(ranks, hack))
							{
								vec.clear();
								if (d2r_cefc4c->getPlayer()->unknown5d47c0(target, &vec, 0))
								{
									where = target;
									first = dist;
								}
							}
						}
					}
				}
			}
		}
		if (where.isValid())
		{
			do { if (opS2_showMessage_5111e0(0x2a6, 0, 0, 0, where, D2rHEntity(), 0, 0)) d2r_cec058->bubble(1); d2r_cec0b4->scrollToEnd_7b4f10(); } while (0);
			d2r_cec054->unknown49ae20(where);
			executeHack(where, hack, arg);
		}
	}
done:
	if (d2r_b97d38[hack] == -1 && d2r_cf4a14.empty())
		d2r_cf45d8.unknown77fbc0(100);
	else if (d2r_b97d38[hack] > 0)
		d2r_cf45d8.unknown77fbc0(0x68);
	if (!remote)
		unknown946990();
}
