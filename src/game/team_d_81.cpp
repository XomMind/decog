// team_d_81: BS member 0x744010 (turn update): reinforces the newest 0b10 patrol squad with a Striker /
// Executioner pair, sometimes routing it to the Garrison, and announces Protoforge dispatches.
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point add(const Point &p) const;	// NOTE: placeholder name (PushCoord::add)
	void offset(int dx, int dy);		// NOTE: placeholder name (Push_40a2a0::operate)
};

struct Pos : public Point
{
	Pos(int x_, int y_);	// 0x46ca20
};

struct Area81	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;
};

class HProp
{
public:
	int ID;
	HProp();
};

class Entity;

class HEntity
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const;
};

class EntityAI
{
public:
	void setField(int value);						// NOTE: placeholder name (Sweep_4505b0::setField)
	void unknown459470(Area81 &area);				// NOTE: placeholder name
	void setFollowEntity(HEntity followEntity_, int followParam_);
	void setCachedSize(int value);					// NOTE: placeholder name (folded setter)
	void unknown4582d0(int value);					// NOTE: placeholder name
	void unknown4593d0(vector<Point> &route);		// NOTE: placeholder name
};

class Entity
{
public:
	Point &getPosition();
	EntityAI *getAI();
	int unknown639530(int type, int value);	// NOTE: placeholder name
};

class Group81	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: folded getter
};

class HGroup
{
	int ID;
public:
	Group81 *operator->() const;	// NOTE: folded (OpC_Handle::get230)
};

struct Squad81	// NOTE: placeholder name and layout
{
	int		type;	// +0x00
	HEntity	leader;	// +0x04
};

class Squads81	// NOTE: placeholder name (0xcf6428)
{
public:
	Squad81 *lastParty();	// NOTE: placeholder name (last squad)
	int spawnHunterParty(HProp entity, int a, int b);	// NOTE: placeholder name
};
extern Squads81 squads81_cf6428;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float lo, float hi);
};
extern RNG rng;

class MessageLog81	// NOTE: placeholder name (0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name (folded with a protobuf SetCachedSize)
};
extern MessageLog81 messageLog81_cf1080;	// NOTE: placeholder name

class ConsoleA81	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA81 *consoleA81_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs81_cec0b4;	// NOTE: placeholder name

void opR1d_4541b0(int id, int a, int b);
bool showMessage81(int id, const string &text, const string *b, int c, HProp d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
extern int state81_cf4718;	// NOTE: placeholder name

struct Marker81	// NOTE: placeholder name
{
	Point pos;
};

class BS	// NOTE: placeholder layout
{
public:
	char				pad000[0x10];
	vector<Marker81 *>	markers;	// +0x10
	char				pad020[0x4c - 0x20];
	vector<HGroup>		groups;		// +0x4c
	char				pad05c[0x8cc - 0x5c];
	Point				origin;		// +0x8cc
	char				pad8d4[0x954 - 0x8d4];
	Area81				area954;	// +0x954
	bool				unknown964;	// +0x964

	HEntity unknown6c5dc0(const string &name, const Point &pos, int group, bool flag, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name
	bool unknown744800(int a);	// NOTE: placeholder name
	void unknown744010(bool quiet);	// NOTE: placeholder name
};

void BS::unknown744010(bool quiet)
{
	if (groups[3]->getMembers()->size() >= 0x78)
		return;
	int count = quiet ? 1 : 2;
	for (int i = 0; i < count; i++)
	{
		if (squads81_cf6428.spawnHunterParty(HProp(),0,0))
		{
			Squad81 *center = squads81_cf6428.lastParty();
			if (!center || center->type != 7)
			{
			}
			else
			{
			vector<string> adj;
			switch (rng.rangeInt(0.0f,2.0f))
			{
			case 0:
				adj.push_back("Striker");
				adj.push_back("Striker");
				break;
			case 1:
				adj.push_back("Executioner");
				adj.push_back("Striker");
				break;
			case 2:
				adj.push_back("Executioner");
				adj.push_back("Executioner");
				break;
			}
			HEntity x = unknown6c5dc0(adj[0],center->leader->getPosition(),3,false,0x22,0xe,false);
			HEntity ok = unknown6c5dc0(adj[1],center->leader->getPosition(),3,false,0x22,0xe,false);
			if (x.isValid())
			{
				center->leader->getAI()->setField(5);
				center->leader->getAI()->unknown459470(area954);
				x->getAI()->unknown459470(area954);
				ok->getAI()->unknown459470(area954);
				center->leader->unknown639530(0x94,1);
				x->unknown639530(0x94,1);
				ok->unknown639530(0x94,1);
				ok->getAI()->setFollowEntity(x,0);
				center->leader->getAI()->setFollowEntity(x,0);
				center->leader = x;
				x->getAI()->setCachedSize(0);
				if (rng.chance(0x21))
				{
					HEntity w;	// NOTE: unused (the exe's frame has an unreferenced slot here)
					x->getAI()->unknown4582d0(2);
					vector<Point> temp;
					temp.push_back(origin.add(Pos(0x22,0x71)));
					temp.push_back(origin.add(Pos(0x4b,0x6b)));
					temp.push_back(origin.add(Pos(0x6b,0x71)));
					Pos pt(0x6b,0x7c);
					temp.push_back(pt.add(Pos(0x35,0x16)));
					temp.push_back(pt.add(Pos(0x37,0x2c)));
					temp.push_back(pt.add(Pos(0x14,0x34)));
					temp.push_back(markers[0]->pos);
					for (unsigned int k = 0; k < temp.size() - 1; k++)
						temp[k].offset(rng.rangeInt(-2.0f,2.0f),rng.rangeInt(-2.0f,2.0f));
					x->getAI()->unknown4593d0(temp);
				}
			}
			}
		}
	}
	if (quiet)
		return;
	if (state81_cf4718 == 0 && rng.chance(50) && unknown744800(0) && !unknown964)
	{
		string msg = "0bP_NET: New 0b10 prototypes are being dispatched from the Protoforge Garrison Access, destroy it to block them!";
		do
		{
			messageLog81_cf1080.unknown451400(1);
			if (0)
				opR1d_4541b0(-1,0,0);
			do
			{
				if (showMessage81(0x324,msg,0,0,HProp(),HProp(),0,0))
					consoleA81_cec058->unknown8758d0(true);
				logMsgs81_cec0b4->scrollToEnd();
			} while (0);
			logMsgs81_cec0b4->scrollToEnd();
		} while (0);
		unknown964 = true;
	}
}
