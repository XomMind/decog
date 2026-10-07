// team_d_42: Entity member 0x6028b0 (self-destructing weapon fired: break parts and explode).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(int v);					// NOTE: placeholder name (0x409990: sets both coordinates)
	Point(const Point &p) throw();	// 0x46ca50
};

class HEntity
{
	int ID;
};

class HProp
{
	int ID;
public:
	HProp();
};

class Item
{
public:
	const string &unknown457860();		// NOTE: placeholder name (record name)
	string unknown571db0(int a, int b);	// NOTE: placeholder name (item name)
	void unknown57dbe0(int a, int b, int c, int d);	// NOTE: placeholder name
};

class HItem
{
	int ID;
public:
	Item *operator->() const;
};

struct ExplosionRec42;	// NOTE: placeholder name
extern vector<ExplosionRec42 *> explosions42_cfd2cc;	// NOTE: placeholder name

class SExplosionExpand
{
public:
	SExplosionExpand(HEntity source, ExplosionRec42 *rec, const Point &pos, HProp prop, const Point &a, const Point &b);
	char pad[0x40];
};

class HRecord42	// NOTE: placeholder name
{
	int ID;
};

class Factory42	// NOTE: placeholder name (OpU5s2_Factory at 0xcefaa8)
{
public:
	HRecord42 createA(SExplosionExpand *action);	// NOTE: placeholder name
};
extern Factory42 *factory_cefaa8;	// NOTE: placeholder name

class Map42	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	HRecord42 addRecord(HRecord42 record);	// NOTE: placeholder name (OpU5_Level::addRecord)
};
extern Map42 *world42;	// NOTE: placeholder name (0xcefc4c)

class State42	// NOTE: placeholder name (object at 0xd25450)
{
public:
	bool unknown000;	// NOTE: placeholder name

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
};
extern State42 state42_d25450;	// NOTE: placeholder name

class PlayerData42	// NOTE: placeholder name (0xcf45d8)
{
public:
	void unknown77fbc0(int id);	// NOTE: placeholder name
};
extern PlayerData42 playerData_cf45d8;	// NOTE: placeholder name

class ConsoleA	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA *consoleA_cec058;	// NOTE: placeholder name
class CLogMsgs
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern CLogMsgs *logMsgs_cec0b4;	// NOTE: placeholder name
bool logMessageS_5111e0(int id, const string &text, int a, int b, HEntity e, HProp d, int f, int g);	// NOTE: placeholder name (0x5111e0)
void logEventS_5141b0(int id, const string &a, int b, int c, HProp p, int d);	// NOTE: placeholder name (0x5141b0)
void opR1d_4541b0(int id, int a, int b);	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
string intToString(int value);
template <class T> void OpV4c_shuffle(vector<T> &v);	// NOTE: placeholder name
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&result);	// NOTE: placeholder name

#define OPD_LOGS(id,text) do { if (logMessageS_5111e0(id,text,0,0,self,HProp(),0,0)) consoleA_cec058->unknown8758d0(true); logMsgs_cec0b4->scrollToEnd(); } while (0)	// NOTE: placeholder macro

class Entity
{
public:
	char	pad00[4];
	HEntity	self;	// +0x04
	char	pad08[0x8c - 0x08];
	int		unknown8c;	// NOTE: placeholder name

	bool isPlayer();				// 0x5c7600
	unsigned int unknown5cb8b0(vector<HItem> *out);	// NOTE: placeholder name
	void unknown5dea60(int value, int flag);	// NOTE: placeholder name
	Point unknown45a4c0();			// NOTE: placeholder name
	void unknown6028b0(HItem item);	// NOTE: placeholder name
};

void Entity::unknown6028b0(HItem item)
{
	bool player = isPlayer();
	bool success = item->unknown457860().find("YOLO",0) != string::npos;
	if (player && success)
		opR1d_4541b0(0x61,0,0);
	OPD_LOGS(0x17d,item->unknown571db0(0,0));
	if (player)
		do { logEventS_5141b0(0x32,item->unknown571db0(0,0),0,0,HProp(),0); } while (0);
	item->unknown57dbe0(player,1,1,1);
	if (success)
	{
		vector<HItem> parts;
		if (unknown5cb8b0(&parts))
		{
			int count = OpX5_maxInt(3,(int)parts.size() / 3);
			OpV4c_shuffle(parts);
			for (int i = parts.size() - 1, num = 0; i >= 0 && num < count; i--, num++)
			{
				OPD_LOGS(0x17e,parts[i]->unknown571db0(0,0));
				parts[i]->unknown57dbe0(player,1,1,1);
			}
		}
		if (unknown8c > 1)
		{
			OPD_LOGS(0x17f,intToString(unknown8c / 2));
			unknown5dea60(unknown8c / 2,0);
		}
		if (state42_d25450.unknown000)
			state42_d25450.unknown69e700(0x33,0,0.0f);
	}
	ExplosionRec42 *record;
	if (OpQ5_findByName(explosions42_cfd2cc,success ? "Yolo_Cannon_Selfdestruct" : "Obliterator_Selfdestruct",record))
		world42->addRecord(factory_cefaa8->createA(new SExplosionExpand(self,record,unknown45a4c0(),HProp(),Point(-1),Point(-1))));
	if (success && player)
		playerData_cf45d8.unknown77fbc0(0xd3);
}
