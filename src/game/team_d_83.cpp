// team_d_83: BS member 0x73a490 (Warlord base attacked: sentry mobilization, clears tagged props and
// robots, assigns sentry posts).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct Pos : public Point
{
	Pos(int x_, int y_);	// 0x46ca20
};

struct OpQ1_Box
{
	int x1;
	int y1;
	int x2;
	int y2;

	OpQ1_Box(int a, int b, int c, int d);
};

class HProp;

class Prop
{
public:
	int unknown45c800(int type);			// NOTE: placeholder name
	bool unknown665be0(bool flag);			// NOTE: placeholder name
};

class HProp
{
public:
	int ID;
	HProp();
	bool isValid() const;
	Prop *operator->() const;
};

class EntityAI
{
public:
	void unknown459540(const Point &p);		// NOTE: placeholder name
	void unknown459410(const OpQ1_Box &area);	// NOTE: placeholder name
};

struct EntityEffect;
class AI83	// NOTE: placeholder name (0x130-byte AI built by 0x57f6a0)
{
public:
	AI83(class HEntity e, int a, int b);
	char pad[0x130];
};

class Entity
{
public:
	EntityEffect *unknown45ac40(int type);	// NOTE: placeholder name
	void setAI(AI83 *ai);
	int getTarget();
	int getFaction();
	void unknown5fdab0();					// NOTE: placeholder name (Push_5fdab0::operate)
	bool isPlayer();
	int unknown45acb0(int value);			// NOTE: placeholder name
	void removeEffectsA(bool onlyInactive);	// NOTE: placeholder name (0x639730)
	const string &getName();
	EntityAI *getAI();
};

class HEntity
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const;
};

class Cell
{
public:
	void unknown670ed0();	// NOTE: placeholder name
	HProp getProp();
	HEntity getEntity();
};

class CellGrid83	// NOTE: placeholder name (0xcfd44c)
{
public:
	int getWidth();
	int getHeight();
	Cell **at(int x, int y);	// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid83 cells83_cfd44c;	// NOTE: placeholder name

class Group83	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: folded getter
};

class HGroup
{
	int ID;
public:
	Group83 *operator->() const;	// NOTE: folded (OpC_Handle::get230)
};

int stringToInt(const string &s);

class OpV1_GameData
{
public:
	const string &getEntryText(const string &key);
	void setEntryText(const string &key, const string &text);
};
extern OpV1_GameData gameData83_d1e860;	// NOTE: placeholder name

class MessageLog83	// NOTE: placeholder name (0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name (folded with a protobuf SetCachedSize)
};
extern MessageLog83 messageLog83_cf1080;	// NOTE: placeholder name

class ConsoleA83	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA83 *consoleA83_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs83_cec0b4;	// NOTE: placeholder name

void opR1d_4541b0(int id, int a, int b);
bool showMessage83(int id, const string *text, const string *b, int c, HProp d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
void message83_5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name
bool OpU8a_removeEntity(vector<HProp> &v, HProp e);	// NOTE: placeholder name (the exe's takes an HEntity-typed handle)
extern int value83_d1ebcc;	// NOTE: placeholder name

class OpR1h_Stats
{
public:
	void add472b90(unsigned int id, int value);
};
extern OpR1h_Stats stats83_d2c658;	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	char			pad000[0x4c];
	vector<HGroup>	groups;		// +0x4c
	char			pad05c[0x320 - 0x5c];
	int				unknown320;	// +0x320
	char			pad324[0x4f0 - 0x324];
	vector<HProp>	unknown4f0;	// +0x4f0
	char			pad500[0xa16 - 0x500];
	bool			unknowna16;	// +0xa16

	void removeEntity(HEntity e);
	void unknown73acc0(bool a, bool b);	// NOTE: placeholder name
	void unknown73a490();	// NOTE: placeholder name
};

void BS::unknown73a490()
{
	gameData83_d1e860.setEntryText("warMaincAttacked_g","1");
	do
	{
		messageLog83_cf1080.unknown451400(1);
		if (0)
			opR1d_4541b0(-1,0,0);
		do
		{
			if (showMessage83(0x324,&string("ANNOUNCEMENT: MAIN.C incursion imminent. Mobilizing sentries."),0,0,HProp(),HProp(),0,0))
				consoleA83_cec058->unknown8758d0(true);
			logMsgs83_cec0b4->scrollToEnd();
		} while (0);
		logMsgs83_cec0b4->scrollToEnd();
	} while (0);
	value83_d1ebcc = unknown320;
	stats83_d2c658.add472b90(0x36,-999999);
	do
	{
		message83_5141b0(0x1ba,0,0,0,HProp(),0);
	} while (0);
	if (!stringToInt(gameData83_d1e860.getEntryText("warAttackedLocals_g")))
		unknowna16 = true;
	for (int x = 0; x < cells83_cfd44c.getWidth(); x++)
	{
		for (int y = 0; y < cells83_cfd44c.getHeight(); y++)
		{
			if ((*cells83_cfd44c.at(x,y))->getProp().isValid() && !(*cells83_cfd44c.at(x,y))->getProp()->unknown45c800(0x8f))
			{
				(*cells83_cfd44c.at(x,y))->getProp()->unknown665be0(false);
				OpU8a_removeEntity(unknown4f0,(*cells83_cfd44c.at(x,y))->getProp());
			}
			if ((*cells83_cfd44c.at(x,y))->getEntity().isValid() && !(*cells83_cfd44c.at(x,y))->getEntity()->isPlayer() && !(*cells83_cfd44c.at(x,y))->getEntity()->unknown45acb0(0x8f))
			{
				removeEntity((*cells83_cfd44c.at(x,y))->getEntity());
				(*cells83_cfd44c.at(x,y))->getEntity()->removeEffectsA(true);
			}
		}
	}
	OpQ1_Box center(0,0,0x49,cells83_cfd44c.getHeight() - 1);
	vector<Point> adj;
	adj.push_back(Pos(0x44,0x1f));
	adj.push_back(Pos(0x43,0x22));
	adj.push_back(Pos(0x43,0x23));
	adj.push_back(Pos(0x43,0x24));
	adj.push_back(Pos(0x43,0x25));
	adj.push_back(Pos(0x44,0x28));
	vector<HEntity> a(*groups[stringToInt(gameData83_d1e860.getEntryText("warAttackedLocals_g")) ? 5 : 9]->getMembers());
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (!adj.empty() && a[i]->getFaction() == 0x15)
		{
			a[i]->getAI()->unknown459540(adj.back());
			adj.pop_back();
		}
		else if (a[i]->unknown45ac40(0x91))
		{
			a[i]->setAI(new AI83(a[i],0x22,0xe));
			a[i]->getAI()->unknown459410(center);
			if (a[i]->getTarget() == 2)
				a[i]->unknown5fdab0();
		}
	}
	(*cells83_cfd44c.at(0x4b,0x22))->unknown670ed0();
	(*cells83_cfd44c.at(0x4b,0x23))->unknown670ed0();
	(*cells83_cfd44c.at(0x4b,0x24))->unknown670ed0();
	(*cells83_cfd44c.at(0x4b,0x25))->unknown670ed0();
	unknown73acc0(true,false);
}
