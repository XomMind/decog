// Batch 7: Entity core methods matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; all type/member names are placeholders.
#include <string>
#include <vector>
#include <stdio.h>
#include "../util/stringutil.h"
using namespace std;

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
void logWarning(string location, string message);	// NOTE: placeholder name (0x404e50)

struct Point;
class Entity;
class Item;
class Group;

class HItem
{
public:
	int ID;
	HItem();
	bool isValid() const;	// the exe folds all the handle isValid() into this one
	Item *operator->() const;	// 0x9b65b0
};

class HEntity : public HItem	// NOTE: placeholder layout
{
public:
	HEntity();
	Entity *operator->() const;	// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b78e0
	int getID() const;	// 0x9fcd80
};

class HGroup : public HEntity	// NOTE: placeholder name (the exe folds the handle comparison with HEntity's)
{
public:
	HGroup();
	Group *operator->() const;	// 0x9b7250
	bool operator==(HGroup other) const;	// 0x9b78e0 (folded with the other handle comparisons)
};

class PropB;
class EntityAI;

class HProp
{
	int ID;
public:
	HProp();
	bool isNull() const;
	bool isValid() const;
	PropB *operator->() const;	// 0x9b65b0
};

struct EntityEffect;	// NOTE: placeholder layout
struct ItemType	// NOTE: placeholder name
{
	int ID;
	char pad04[0x26d];
	bool unknown271;	// NOTE: placeholder name
};

class Item
{
public:
	int getTypeID();	// NOTE: placeholder name (0x457820: [this+8]->[0])
	int getCategory();	// NOTE: placeholder name (0x44aec0: [this+0xc]); op_u2.cpp uses the same getter as `getCategory() <= 3`
	ItemType *unknown9b4350();	// NOTE: placeholder name (0x9b4350: [this+8])
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
	void unknown57a190(HEntity e, int a, int b, int c);	// NOTE: placeholder name
	void unknown57a0f0(const Point *p, int a, int b);	// NOTE: placeholder name
	int pad0;
	int pad4;
	ItemType *type;
};

class Group	// NOTE: placeholder name
{
public:
	int getFaction();	// NOTE: placeholder name (0x9b4350: [this+8]); the exe prints it as "faction" (changeFaction diagnostic), ctor 0x670ff0 stores the group index in +4 and +8
	void removeMember(HEntity e);	// NOTE: placeholder name (0x6716f0)
	void addMember(HEntity e, int flag);	// NOTE: placeholder name (0x671280)
};

class HItemList	// NOTE: placeholder name
{
public:
	unsigned int count();	// NOTE: placeholder name (0x9b9260)
	HItem &at(unsigned int i);	// NOTE: placeholder name (0x9b81f0)
	bool isEmpty();	// NOTE: placeholder name (0x9b86e0)
	HItem &back();	// NOTE: placeholder name (0x9b7060)
};

class IntArray	// NOTE: placeholder name
{
public:
	int &at(int i);	// NOTE: placeholder name (0x9b81f0)
};
extern vector<int> unknownCf4830;	// NOTE: placeholder name (0xcf4830), indexed by the ItemType's first word (Item::getTypeID)

class EntityAI	// NOTE: placeholder name (controller object, 0x130 bytes; Entity+0x144)
{
public:
	EntityAI(HEntity owner, int mode1, int mode2);	// 0x57f6a0
	int takeTurn();
	bool unknown459030();	// NOTE: placeholder name
	char pad[0x130];
};

struct EntityRecord	// NOTE: placeholder
{
	char pad00[0x28];
	int faction;
	char pad2c[0x78 - 0x2c];
	int unknown78;	// NOTE: placeholder name
	char pad7c[0x94 - 0x7c];
	int unknown94;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
	int size;	// NOTE: placeholder name
	char pada0[4];
	int unknownA4;	// NOTE: placeholder name
	char padA8[0x1e4 - 0xa8];
	int unknown1E4;	// NOTE: placeholder name
	int unknown1E8;	// NOTE: placeholder name
	char pad1EC[4];
	int unknown1F0;	// NOTE: placeholder name
	char pad1F4[0x21c - 0x1f4];
	int unknown21C;	// NOTE: placeholder name
};

struct FactionInfo	// NOTE: placeholder name (stride 10)
{
	char pad0;
	bool unknown1;
	char pad2[8];
};
extern FactionInfo factionInfo[];	// NOTE: placeholder name (0xb96638)

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
	Point();	// 0x453b40
	Point(int v);	// 0x409990
	Point(const Point &p);	// 0x46ca50 (folded with operator=)
	Point(const Point &base, int dx, int dy);
	Point &operator=(const Point &p);	// 0x46ca50
	bool unknown409bd0(const Point &p) const;	// NOTE: placeholder name (operator!=)
	void unknown409ff0(int v);	// NOTE: placeholder name
};
int pointDistance(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
string pointToString(const Point &p);	// NOTE: placeholder name (0x40a4a0)

struct PointCopy	// NOTE: placeholder name (plain Point-like, no constructors)
{
	int x;
	int y;
	PointCopy &operator=(const Point &p);	// 0x46ca50
};

struct Range	// NOTE: placeholder name
{
	int min;
	int max;
	Range(int min_, int max_);	// 0x46ca20
	bool contains(int value);	// NOTE: placeholder name (0x40c190)
};

struct Area	// NOTE: placeholder name
{
	Area();	// 0x40b100
	void randomPoint(Point *out);	// NOTE: placeholder name (0x40be30)
	Point min;
	Point max;
};
int pointDistance(const PointCopy &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)

struct TerrainB	// NOTE: placeholder name
{
	char pad00[0xb0];
	int unknownB0;	// NOTE: placeholder name
	int unknownB4;	// NOTE: placeholder name
};

class Cell
{
public:
	bool canPlaceEntity(int a);
	HEntity getEntity();
	int getTerrain();	// 0x9fcd80 (really returns a pointer)
	void unknown66baf0();	// NOTE: placeholder name
	void unknown66b8f0(HEntity e);	// NOTE: placeholder name
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
	void getBounds(const PointCopy &p, int radius, Area *out);	// NOTE: placeholder name (0x9b4430)
};
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

class BS	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	void setActingEntity(int handle);	// NOTE: placeholder name (0x451930: [this+0x48] = handle; BS::f48 is serialized as one handle-sized box)
	HEntity getEntity671();	// NOTE: placeholder name (0x463110)
	bool unknown71c150(const Point &a, Point &b, int size);	// NOTE: placeholder name
	void unknown71cf70();	// NOTE: placeholder name
	void unknown734560(HEntity e, int a, int b);	// NOTE: placeholder name
	void unknown72ec60();	// NOTE: placeholder name
	HGroup getFoo(int i);	// NOTE: placeholder name (0x463890)
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	HEntity getPlayer();	// NOTE: placeholder name (0x4630f0)
	void unknown732ef0();	// NOTE: placeholder name
	void unknown729470(HEntity e, int a);	// NOTE: placeholder name
	void unknown465470();	// NOTE: placeholder name
	void unknown726320();	// NOTE: placeholder name
	void unknown465340();	// NOTE: placeholder name
	void unknown464730(bool a);	// NOTE: placeholder name
	void playerActionPrepare();
	void unknown732ce0(bool a);	// NOTE: placeholder name
	void unknown9ebbb0(int a);	// NOTE: placeholder name
	void unknown721240(vector<Point> *v);	// NOTE: placeholder name
	void unknown71fe20(vector<Point> *v);	// NOTE: placeholder name
	void unknown720e30(vector<Point> *v);	// NOTE: placeholder name
	void unknown720210(vector<Point> *v);	// NOTE: placeholder name
	void unknown720610(vector<Point> *v);	// NOTE: placeholder name
	void unknown720a30(vector<Point> *v);	// NOTE: placeholder name
	void unknown729160(HEntity e);	// NOTE: placeholder name
	void unknown721320(HEntity e);	// NOTE: placeholder name
	void unknown71fef0(HEntity e);	// NOTE: placeholder name
	void unknown7202f0(HEntity e);	// NOTE: placeholder name
	void unknown720b10(HEntity e);	// NOTE: placeholder name
	void unknown720f00(HEntity e);	// NOTE: placeholder name
	HEntity placeEntity(int a, const Point &p, int b, int c, int d, int e, int f);	// NOTE: placeholder parameter names
	void unknown72e4c0(HEntity e, int a);	// NOTE: placeholder name
	bool unknown71bc10(const Point &p, Point *out);	// NOTE: placeholder name
};
extern BS *world;	// NOTE: placeholder name (0xcefc4c)

class Message	// NOTE: placeholder name
{
public:
	Message(int type, int a, int b, int c, HProp p1, HProp p2);	// 0x510f80
	char pad[0x28];
};

class MessageLog
{
public:
	int push(Message *msg);
};
extern MessageLog messageLog;	// NOTE: placeholder name (0xcf1080)

class Profiler	// NOTE: placeholder name
{
public:
	void unknown69e900();	// NOTE: placeholder name
	void unknown69ec90();
	void unknown69ecb0(int a);
	bool enabled;
};
extern Profiler profiler;	// NOTE: placeholder name (0xd25450)

class SomeSystem	// NOTE: placeholder name
{
public:
	void unknown793690();	// NOTE: placeholder name
	void unknown96bbb0();	// NOTE: placeholder name
	void unknown9695b0();
};
extern SomeSystem *someSystem;	// NOTE: placeholder name (0xcec138)
extern SomeSystem *someSystem2;	// NOTE: placeholder name (0xcefaa8)
extern int rangeA;	// NOTE: placeholder name (0xd01d58)
extern int rangeB;	// NOTE: placeholder name (0xd01d5c)
extern int cellSize;	// NOTE: placeholder name (0xcf49fc)

class Messages	// NOTE: placeholder name
{
public:
	void unknown8758d0(int a);	// NOTE: placeholder name
};
extern Messages *messages;	// NOTE: placeholder name (0xcec058)
class UIRefresh	// NOTE: placeholder name
{
public:
	void unknown7b4f10();	// NOTE: placeholder name
};
extern UIRefresh *uiRefresh;	// NOTE: placeholder name (0xcec0b4)
class CInventory
{
public:
	void reopen(int a, HProp b);
};
extern CInventory *cinventory;	// NOTE: placeholder name (0xcec08c)
class ItemRegistry	// NOTE: placeholder name
{
public:
	void unknown77ffb0(int itemTypeID, int flag);
	void unknown77fbc0(int a);
	bool unknown46de40(int a);	// NOTE: placeholder name
	bool unknown77ed10();	// NOTE: placeholder name
};
extern ItemRegistry unknownCf45d8;	// NOTE: placeholder name (0xcf45d8)

class SoundPlayer	// NOTE: placeholder name
{
public:
	void unknown4729d0(int a, int b, string c, int d);
};
extern SoundPlayer soundPlayer;	// NOTE: placeholder name (0xd2c658)
class PopupMgr	// NOTE: placeholder name
{
public:
	void unknown49e250(int a, int b, string c);
};
extern PopupMgr *popupMgr;	// NOTE: placeholder name (0xcefb48)
class MapView	// NOTE: placeholder name
{
public:
	HProp unknown49af40();	// NOTE: placeholder name
	HEntity unknown49ab00();	// NOTE: placeholder name
	void unknown8069e0(Point p, int a);	// NOTE: placeholder name
	void unknown819cb0();	// NOTE: placeholder name
	void unknown44e360(HProp p);	// NOTE: placeholder name
	void unknown49ad30();
	void unknown49adc0(int a);
};
extern MapView *mapView;	// NOTE: placeholder name (0xcec054)

class PanelA	// NOTE: placeholder name
{
public:
	void unknown7b7980();	// NOTE: placeholder name
};
extern PanelA *panelA;	// NOTE: placeholder name (0xcec0c8)
class PanelItem	// NOTE: placeholder name
{
public:
	void unknown4a9120();	// NOTE: placeholder name
};

class PanelItemList	// NOTE: placeholder name
{
public:
	unsigned int count();	// 0x9b9260
	PanelItem *&at(unsigned int i);	// 0x9b81f0
};

class PanelB	// NOTE: placeholder name
{
public:
	void unknown8966a0();	// NOTE: placeholder name
	PanelItemList *unknown4a9ad0();	// NOTE: placeholder name
};
extern PanelB *panelB;	// NOTE: placeholder name (0xcec088)
extern bool unknownFlagCefb3e;	// NOTE: placeholder name (0xcefb3e)
string unknown432d80();	// NOTE: placeholder name
void logNote(string location, string message);	// NOTE: placeholder name (0x404fd0)

class MoveTracker	// NOTE: placeholder name
{
public:
	bool unknown789620();	// NOTE: placeholder name
	bool unknown46fb60();	// NOTE: placeholder name
	bool unknown789580(HEntity e);	// NOTE: placeholder name
};
extern MoveTracker moveTracker;	// NOTE: placeholder name (0xd1e860)
extern vector<Point> pointsA;	// NOTE: placeholder name (0xd29774)
extern vector<Point> pointsB;	// NOTE: placeholder name (0xd2c454)
extern IntArray b7_rifLevels_cf4a04;	// NOTE: placeholder name (0xcf4a04)
extern bool unknownFlagCf4a00;	// NOTE: placeholder name (0xcf4a00)
extern int unknownFlagD255ac;	// NOTE: placeholder name (0xd255ac)
extern bool unknownFlagCefacd;	// NOTE: placeholder name (0xcefacd)
extern Point unknownPointCf4d74;	// NOTE: placeholder name (0xcf4d74)
void unknown454160(const Point &p, int a, int b);	// NOTE: placeholder name
bool unknown9d3060(vector<Point> *v, Point p);	// NOTE: placeholder name
void unknown9d7300(vector<Point> *v, unsigned int *i);	// NOTE: placeholder name

class PolyPossessData	// NOTE: placeholder name
{
public:
	~PolyPossessData();
	int unknown0;	// NOTE: placeholder name
	char pad4[4];
	string unknown8;	// NOTE: placeholder name
	int unknown24;	// NOTE: placeholder name
	int unknown28;	// NOTE: placeholder name
};
extern PolyPossessData *possessed;	// NOTE: placeholder name (0xcf4700)
extern bool unpossessing;	// NOTE: placeholder name (0xcefb5a, "g_cogmindCurrentlyUnpossessing")
extern int unknownCf496c;	// NOTE: placeholder name
extern int unknownCf4978;	// NOTE: placeholder name
extern int unknownCf4960;	// NOTE: placeholder name
extern int unknownCf49d8;	// NOTE: placeholder name
extern int unknownCf4970;	// NOTE: placeholder name
extern int unknownCf4974;	// NOTE: placeholder name
extern int unknownCf49dc;	// NOTE: placeholder name
extern int unknownCf4984[];	// NOTE: placeholder name
extern int unknownCf4718;	// NOTE: placeholder name
extern int unknownBa64d8[][3];	// NOTE: placeholder name
extern int unknownCaf440;	// NOTE: placeholder name
extern int unknownCaf444;	// NOTE: placeholder name
extern int unknownCaf448;	// NOTE: placeholder name
extern int unknownCaf44c;	// NOTE: placeholder name
extern int unknownCefb4c;	// NOTE: placeholder name
extern int unknownCaf2b8;	// NOTE: placeholder name
extern IntArray unknownD25de0;	// NOTE: placeholder name
extern bool unknownFlagD28e27;	// NOTE: placeholder name
class Counter	// NOTE: placeholder name
{
public:
	int unknown40c130();	// NOTE: placeholder name
};
extern Counter unknownD1f3b0;	// NOTE: placeholder name
void unknown4541b0(int a, int b, int c);	// NOTE: placeholder name
void unknown789ac0();	// NOTE: placeholder name

bool showMessage(int type, const string &text, int a, int b, HEntity e, HProp p, int c, int d);	// NOTE: placeholder name (0x5111e0)

class PropB	// NOTE: placeholder name
{
public:
	int getField1c();	// NOTE: placeholder name (0x9b6bf0: [this+0x1c])
	string getName(int a, int b);	// NOTE: placeholder name (0x571db0)
};

class Entity
{
public:
	EntityRecord *unknown9b4350();	// NOTE: placeholder name (0x9b4350: [this+8], same body as Group::getFaction and Item::getType)
	void setField40(int value);	// NOTE: placeholder name (0x45b090: [this+0x40] = value)
	void polymindUnpossess(bool automatic);	// NOTE: placeholder parameter name
	void changeFaction(HGroup newGroup, bool flag);	// NOTE: placeholder parameter names
	void attemptTeleportitisTeleport();
	void changePos(const Point &p, bool flag);	// NOTE: placeholder parameter names
	const Point &getPosition();	// 0x45a4a0
	int getSize();	// 0x45a360
	void unknown5ddac0(const Point &p, int a);	// NOTE: placeholder name

	int getFaction();	// 0x45a2c0
	vector<HItem> *getInventoryList();	// NOTE: placeholder name (0x45ab00: this+0x134, the carried-item list)
	void setAI(EntityAI *ai);	// 0x64ecf0
	int takeTurn();
	void unknown637bb0();	// NOTE: placeholder name
	bool isPlayer();	// NOTE: placeholder name (0x5c7600)
	const string &getNameAt0c();	// NOTE: placeholder name (0x416f40 returns this+0xc, not Entity::getName)
	void unknown5d2430(int type, vector<HProp> *out);	// NOTE: placeholder name
	void unknown451600(HProp p);	// NOTE: placeholder name
	HEntity unknown45a260();	// NOTE: placeholder name
	int getTarget();	// 0x45a760
	HGroup getGroup();	// 0x45a3f0
	Point unknown5c80f0(const Point &toward);	// NOTE: placeholder name
	int unknown5cb9b0(int a);	// NOTE: placeholder name
	int unknown5c8db0();	// NOTE: placeholder name
	int unknown45a860();	// NOTE: placeholder name
	int unknown5c92e0(int a);	// NOTE: placeholder name
	bool unknown5d9340(bool *placed, Point *pos);	// NOTE: placeholder name
	void unknown45b070(const string &s);	// NOTE: placeholder name
	void unknown5dea60(int a, int b);	// NOTE: placeholder name
	void unknown5deb40(int a);	// NOTE: placeholder name
	void unknown5ded70(int a);	// NOTE: placeholder name
	void unknown45b210(int a);	// NOTE: placeholder name
	void unknown5fd900(int a, int b);	// NOTE: placeholder name
	void unknown45b0b0();	// NOTE: placeholder name
	EntityEffect *unknown45ac40(int a);	// NOTE: placeholder name
	void unknown45b360(int a);	// NOTE: placeholder name

	int unknown00;	// NOTE: placeholder name
	HEntity self;	// NOTE: placeholder name
	EntityRecord *record;
	string name;	// NOTE: placeholder name
	HGroup group;	// NOTE: placeholder name
	char pad2c[4];
	vector<Point> footprint;	// NOTE: placeholder name
	char pad40[0x90 - 0x40];
	int unknown90;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
	char pad9c[0xbc - 0x9c];
	int unknownBC;	// NOTE: placeholder name
	char padC0[0x134 - 0xc0];
	HItemList items;	// NOTE: placeholder name
	char pad135[0x144 - 0x135];
	EntityAI *ai;	// NOTE: placeholder name
};

void Entity::changeFaction(HGroup newGroup, bool flag)
{
	if (group == newGroup)
	{
		logError("Entity::changeFaction()",name + " is already a member of faction (" + intToString(group->getFaction()) + ")");
		volatile int zero;
		volatile int one = 1;
		zero = 0;
		int crash = one / zero;
	}
	if (factionInfo[record->faction].unknown1 && newGroup->getFaction() == 1)
	{
		newGroup = world->getFoo(0);
	}
	group->removeMember(self);
	group = newGroup;
	group->addMember(self,0);
	if (flag)
	{
		setAI(new EntityAI(self,0x22,0xe));
	}
	if (group->getFaction() == 1 && getFaction() == 0x14 && world->unknown4631f0(self))
	{
		vector<HItem> *list = world->getPlayer()->getInventoryList();
		{
		bool found = false;
		for (unsigned int i = 0; i < list->size(); i++)
		{
			if (unknownCf4830[(*list)[i]->getTypeID()] == 0 && !(*list)[i]->unknown9b4350()->unknown271)
			{
				unknownCf45d8.unknown77ffb0((*list)[i]->getTypeID(),0);
				found = true;
				do
				{
					if (showMessage(0x264,(*list)[i]->getName(0,0),0,0,self,HProp(),0,0))
						messages->unknown8758d0(1);
					uiRefresh->unknown7b4f10();
				}
				while (0);
			}
		}
		if (found)
			cinventory->reopen(4,HProp());
		}
	}
}

void Entity::attemptTeleportitisTeleport()
{
	someSystem->unknown9695b0();
	Range dist(rangeA * cellSize,rangeB * cellSize);
	PointCopy origin;
	origin = getPosition();
	Area zone;
	cells.getBounds(origin,dist.max,&zone);
	Point goal;
	bool found = false;
	bool second = false;
retry:
	for (int i = 0; i < 2000; i++)
	{
		zone.randomPoint(&goal);
		if (dist.contains(pointDistance(origin,goal)) && cells(goal)->canPlaceEntity(1))
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		if (second)
		{
			logWarning("Entity::attemptTeleportitisTeleport()","complete failure");
			return;
		}
		else
		{
			dist.min = 1;
			second = true;
			goto retry;
		}
	}
	if (profiler.enabled)
		profiler.unknown69ec90();
	do
	{
		if (messageLog.push(new Message(0x113,0,0,0,HProp(),HProp())))
			messages->unknown8758d0(1);
		uiRefresh->unknown7b4f10();
	}
	while (0);
	unknown5ddac0(goal,1);
	if (profiler.enabled)
		profiler.unknown69ecb0(0x38);
	Point final(-1);
	if (world->getEntity671().isValid() && world->unknown71c150(goal,final,world->getEntity671()->getSize()))
	{
		world->getEntity671()->changePos(final,1);
		if (popupMgr)
			popupMgr->unknown49e250(0x28,0,"");
	}
	world->unknown71cf70();
	world->unknown734560(self,-2,0);
	if (world->getEntity671().isValid())
		world->unknown734560(world->getEntity671(),-2,0);
	soundPlayer.unknown4729d0(0x3fe,1,"",-1);
	unknownCf45d8.unknown77fbc0(0x86);
	world->unknown72ec60();
	mapView->unknown49ad30();
	mapView->unknown49adc0(0x3e8);
}

int Entity::takeTurn()
{
	world->unknown732ef0();
	world->setActingEntity(self.ID);
	world->unknown729470(self,1);
	world->unknown465470();
	world->unknown726320();
	if (profiler.enabled)
		profiler.unknown69e900();
	world->unknown465340();
	mapView->unknown819cb0();
	if (isPlayer())
	{
		world->unknown464730(1);
		world->playerActionPrepare();
		world->unknown732ce0(0);
		panelA->unknown7b7980();
		panelB->unknown8966a0();
		if (mapView->unknown49af40().isValid())
		{
			HProp hacker;
			vector<HProp> list;
			world->getPlayer()->unknown5d2430(0xb7,&list);
			for (unsigned int i = 0; i < list.size(); i++)
			{
				if (list[i]->getField1c() == 1)
				{
					hacker = list[i];
					break;
				}
			}
			if (hacker.isNull())
			{
				mapView->unknown44e360(HProp());
			}
			else
			{
				FILE *file = fopen(unknown432d80().c_str(),"r");
				if (file == NULL)
				{
					do
					{
						if (showMessage(0x116,hacker->getName(0,0),0,0,HEntity(),HProp(),0,0))
							messages->unknown8758d0(1);
						uiRefresh->unknown7b4f10();
					}
					while (0);
				}
				else
				{
					someSystem->unknown96bbb0();
				}
				if (file)
					fclose(file);
			}
		}
		if (unknownFlagCefb3e)
			world->unknown9ebbb0(0);
		return -1;
	}
	else
	{
		if (ai == NULL)
		{
			logNote("Entity::takeTurn()","Non-player Entity has no controller: " + getNameAt0c());
		}
		world->unknown464730(0);
		HEntity oldSelf = self;
		int result = ai->takeTurn();
		if (oldSelf.operator->())
		{
			if (!ai->unknown459030())
				unknown451600(HProp());
		}
		return result;
	}
}

void Entity::changePos(const Point &newPos, bool flag)
{
	if (flag)
	{
		for (unsigned int i = 0; i < footprint.size(); i++)
			cells(footprint[i])->unknown66baf0();
		switch (getGroup()->getFaction())
		{
		case 4:
			world->unknown721240(&footprint);
			break;
		case 3:
			world->unknown71fe20(&footprint);
			world->unknown720e30(&footprint);
			world->unknown721240(&footprint);
			break;
		}
		world->unknown720210(&footprint);
		world->unknown720610(&footprint);
		world->unknown720a30(&footprint);
	}
	footprint.clear();
	for (int y = 0; y < record->size; y++)
	{
		for (int x = 0; x < record->size; x++)
		{
			footprint.push_back(Point(newPos,x,y));
			if (cells(footprint.back())->getEntity().isValid())
			{
				logError("Entity::changePos()",name + " (" + intToString(self.getID()) + ") being moved to " + pointToString(footprint.back()) + ", which is already occupied by " + cells(footprint.back())->getEntity()->name + " (" + intToString(cells(footprint.back())->getEntity()->unknown45a260().getID()) + "), destroying occupier");
				cells(footprint.back())->getEntity()->unknown637bb0();
			}
			cells(footprint.back())->unknown66b8f0(self);
		}
	}
	if (!pointsA.empty() || !pointsB.empty())
	{
		for (unsigned int i = 0; i < pointsA.size(); i++)
		{
			if (unknown9d3060(&pointsB,pointsA[i]))
				unknown9d7300(&pointsA,&i);
		}
		for (unsigned int i = 0; i < pointsA.size(); i++)
		{
			if (((TerrainB *)cells(pointsA[i])->getTerrain())->unknownB0)
				unknown454160(pointsA[i],((TerrainB *)cells(pointsA[i])->getTerrain())->unknownB0,0x13);
		}
		for (unsigned int i = 0; i < pointsB.size(); i++)
		{
			if (((TerrainB *)cells(pointsB[i])->getTerrain())->unknownB4)
				unknown454160(pointsB[i],((TerrainB *)cells(pointsB[i])->getTerrain())->unknownB4,0x13);
		}
		pointsA.clear();
		pointsB.clear();
	}
	world->unknown729160(self);
	if (flag && getTarget() == 0)
	{
		switch (getGroup()->getFaction())
		{
		case 4:
			if (moveTracker.unknown789620())
				world->unknown721320(self);
			break;
		case 3:
			if (moveTracker.unknown789620())
				world->unknown721320(self);
			if (moveTracker.unknown46fb60())
			{
				if (pointDistance(unknown5c80f0(world->getPlayer()->getPosition()),world->getPlayer()->getPosition()) <= 0x12)
					world->unknown71fef0(self);
			}
			if (b7_rifLevels_cf4a04.at(0xa) != 0 && moveTracker.unknown789580(self))
			{
				if (pointDistance(unknown5c80f0(world->getPlayer()->getPosition()),world->getPlayer()->getPosition()) <= 0x18)
					world->unknown720f00(self);
			}
			break;
		}
		if (unknownFlagD255ac != 0)
		{
			if (pointDistance(unknown5c80f0(world->getPlayer()->getPosition()),world->getPlayer()->getPosition()) <= 0x12)
				world->unknown7202f0(self);
		}
		if (unknownFlagCf4a00)
		{
			if (pointDistance(unknown5c80f0(world->getPlayer()->getPosition()),world->getPlayer()->getPosition()) <= 0x12)
				world->unknown720b10(self);
		}
	}
	if (isPlayer())
	{
		if (unknownCf45d8.unknown46de40(0x11c))
		{
			if (getPosition().unknown409bd0(unknownPointCf4d74))
				unknownPointCf4d74.unknown409ff0(-1);
		}
	}
	if (unknownFlagCefacd)
	{
		if (mapView->unknown49ab00() == self)
			mapView->unknown8069e0(getPosition(),0);
	}
}

void Entity::polymindUnpossess(bool automatic)
{
	if (!isPlayer())
		logNote("Entity::polymindUnpossess()","only works on Cogmind!");
	if (possessed == NULL)
	{
		logError("Entity::polymindUnpossess()","isAutomatic=" + intToString(automatic));
		logError("Entity::polymindUnpossess()","g_cogmindCurrentlyUnpossessing=" + intToString(unpossessing));
		logError("Entity::polymindUnpossess()","getEquippedPartCount()=" + intToString(unknown5cb9b0(0)));
		logError("Entity::polymindUnpossess()","getInventoryCount()=" + intToString(unknown5c8db0()));
		logError("Entity::polymindUnpossess()","getSlotTotal()=" + intToString(unknown45a860()));
		logError("Entity::polymindUnpossess()","getSlotFreeCount()=" + intToString(unknown5c92e0(4)));
		logNote("Entity::polymindUnpossess()","no possessed Ent!");
	}
	if (!automatic && unknown5cb9b0(0) == 0)
	{
		logError("Entity::polymindUnpossess()","no attached parts, should've automatically happened earlier");
		return;
	}
	Point old = getPosition();
	Point destination;
	bool valid;
	if (!unknown5d9340(&valid,&destination))
	{
		logError("Entity::polymindUnpossess()","potentially insufficient room despite earlier confirmation?");
		valid = false;
	}
	unpossessing = true;
	do
	{
		if (showMessage(0x307 + (automatic != 0),possessed->unknown8,0,0,self,HProp(),0,0))
			messages->unknown8758d0(1);
		uiRefresh->unknown7b4f10();
	}
	while (0);
	EntityRecord *record = unknown9b4350();
	unknownCf496c = 0;
	unknownCf4978 = 0;
	unknownCf4960 = record->unknown21C;
	unknownCf49d8 = record->unknown1E8;
	unknownCf4970 = record->unknown1E4;
	unknownCf4974 = 0;
	unknownCf49dc = record->unknown1F0;
	for (int i = 0; i < 7; i++)
		unknownCf4984[i] = unknownBa64d8[i][unknownCf4718];
	int height = record->size;
	record->size = unknownCaf440;
	record->unknown98 = unknownCaf444;
	record->unknown94 = unknownCaf448;
	record->unknownA4 = unknownCaf44c;
	record->unknown78 = unknownCefb4c;
	unknownCaf2b8 = 0x40;
	for (unsigned int i = 0; i < footprint.size(); i++)
		cells(footprint[i])->unknown66baf0();
	footprint.clear();
	HEntity robot;
	if (valid)
	{
		robot = world->placeEntity(unknownD25de0.at(possessed->unknown0),old,possessed->unknown24,0,0x22,0xe,0);
		if (robot.isValid())
		{
			robot->unknown45b070(possessed->unknown8);
			robot->unknown5dea60(possessed->unknown28,0);
			while (!robot->items.isEmpty())
				robot->items.back()->unknown57dbe0(0,0,1,1);
			while (!items.isEmpty())
				items.back()->unknown57a190(robot,items.back()->getCategory(),1,1);
			unknown98 = 0;
			unknown90 = 0;
			unknown94 = 0;
			robot->unknown5deb40(unknown94);
			robot->unknown5ded70(unknown90);
			robot->unknown45b210(unknown98);
			robot->unknown5fd900(1,unknownD1f3b0.unknown40c130());
		}
	}
	changePos(destination,false);
	setField40(0);
	unknown45b0b0();
	world->unknown72e4c0(self,1);
	if (unknownFlagD28e27)
		mapView->unknown8069e0(destination,0);
	while (!items.isEmpty())
	{
		if (items.back()->getCategory() <= 3)
		{
			items.back()->unknown57dbe0(1,0,4,1);
		}
		else
		{
			Point dropPos;
			if (world->unknown71bc10(destination,&dropPos))
				items.back()->unknown57a0f0(&dropPos,1,1);
			else
				items.back()->unknown57dbe0(1,0,1,1);
		}
	}
	unknown94 = 0;
	unknown90 = 10;
	unknown98 = 0;
	if (unknownBC != 0 && robot.isValid())
	{
		robot->unknownBC = unknownBC;
		unknownBC = 0;
	}
	if (unknown45ac40(0x1d))
		unknown45b360(0x1d);
	if (!unknownCf45d8.unknown77ed10())
		delete possessed;
	possessed = NULL;
	PanelItemList *list = panelB->unknown4a9ad0();
	for (unsigned int i = 0; i < list->count(); i++)
		list->at(i)->unknown4a9120();
	unknown4541b0(0x140,0,0);
	someSystem2->unknown793690();
	unknown789ac0();
	unpossessing = false;
}
