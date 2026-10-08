// team_d_93: member 0x69ee30 of the class whose 0x69fa80 rebuilds the map (Xom/repair effects: restores
// core and system integrity, then optionally shifts the surroundings).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

string intToString(int value);
void OpV4c_Fn9d0690(int *value, int step, int low);	// NOTE: placeholder name
int opR1f_45f9a0(int value);	// NOTE: placeholder name
int OpX5_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)
extern string names93_d2ce40[];	// NOTE: placeholder name

struct Point
{
	int x;
	int y;

	Point();	// NOTE: placeholder name (Push_453b40::operate)
};

struct Pos : public Point
{
	Pos(int x_, int y_);	// 0x46ca20
	void scale(int amount);	// NOTE: placeholder name (Push_40bf50::operate)
	int randomInRange_40c130();
};

class HProp
{
public:
	int ID;
	HProp();
};

class Item
{
public:
	int unknown457ca0();	// NOTE: placeholder name (integrity percent)
};

class HItem
{
public:
	int ID;
	bool isNull() const;	// NOTE: folded with HProp::isNull
	Item *operator->() const;
};

class Part93	// NOTE: placeholder name (CInfoCompare)
{
public:
	HItem getTarget();
};

class CParts
{
public:
	vector<Part93 *> *getFieldAddress();	// NOTE: placeholder name (Sweep_4a9ad0::getFieldAddress)
};
extern CParts *parts93_cec088;	// NOTE: placeholder name

class Entity
{
public:
	int unknown5ca260();				// NOTE: placeholder name
	void unknown5dea60(int value, int flag);	// NOTE: placeholder name
	int unknown490840();				// NOTE: placeholder name (folded getter)
	int unknown45a9d0();				// NOTE: placeholder name
	void setUnknown93(int value);			// NOTE: placeholder name (folded setter Stats_Kills_ClassesDestroyed::set_superbehemoth)
	Point &getPosition();
};

class HEntity
{
public:
	int ID;
	Entity *operator->() const;
};

class Map
{
public:
	HEntity getPlayer();
	vector<Point *> *getStarts();	// NOTE: placeholder name (folded getter Particle::getPos)
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
};
extern Map *world93_cefc4c;	// NOTE: placeholder name

struct Location93	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;
};

class HLoc93	// NOTE: placeholder name
{
	int ID;
public:
	Location93 *operator->() const;
};
extern HLoc93 location93_d1e888;	// NOTE: placeholder name

class ConsoleA93	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern ConsoleA93 *consoleA93_cec058;	// NOTE: placeholder name

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *logMsgs93_cec0b4;	// NOTE: placeholder name

class Obj93_cec138	// NOTE: placeholder name
{
public:
	void unknown9666d0();	// NOTE: placeholder name
};
extern Obj93_cec138 *obj93_cec138;	// NOTE: placeholder name

class MapView93	// NOTE: placeholder name (0xcec054)
{
public:
	void unknown49adc0(int time);	// NOTE: placeholder name
};
extern MapView93 *mapView93_cec054;	// NOTE: placeholder name

class EffectObj93	// NOTE: placeholder name (object initialized by 0x503b20)
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name
};

class EndObjB
{
public:
	EffectObj93 *unknown508610();	// NOTE: placeholder name
};
extern EndObjB *endObj93_cefc50;	// NOTE: placeholder name
extern Point point93_d2e20c;		// NOTE: placeholder name
extern int value93_caf154;		// NOTE: placeholder name

bool showMessage93(int id, const string *text, const string *b, int c, HProp d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
void message93_5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name
void opW5_message(int type, HProp prop, const string &text, int value);	// NOTE: placeholder name

class Builder93	// NOTE: placeholder name and layout (OpY5_Builder)
{
public:
	char	pad00[0x10];
	int		unknown10;	// +0x10
	char	pad14[0xa0 - 0x14];
	int		unknowna0;	// +0xa0
	bool	unknowna4;	// +0xa4

	bool unknown69fa80(Point *pos);	// NOTE: placeholder name
	void setValue(int value);		// NOTE: placeholder name (Push_45fce0::operate)
	void unknown69ee30(bool repair, bool power, bool rebuild);	// NOTE: placeholder name
};

void Builder93::unknown69ee30(bool repair, bool power, bool rebuild)
{
	do
	{
		if (showMessage93(0x2ba,&names93_d2ce40[opR1f_45f9a0(unknown10)],0,0,HProp(),HProp(),0,0))
			consoleA93_cec058->unknown8758d0(true);
		logMsgs93_cec0b4->scrollToEnd();
	} while (0);
	do
	{
		message93_5141b0(0x99,0,0,0,HProp(),0);
	} while (0);
	if (repair)
	{
		Pos pt(0x19,0x28);
		int count = 0;
		int dest = 0;
		vector<Part93 *> *mode = parts93_cec088->getFieldAddress();
		for (unsigned int i = 0; i < mode->size(); i++)
		{
			if ((*mode)[i]->getTarget().isNull() || (*mode)[i]->getTarget()->unknown457ca0() <= 0x28)
			{
				int v = 5;
				for (int j = 0; j < count; j++)
					OpV4c_Fn9d0690(&v,1,0);
				count++;
				dest += v;
			}
		}
		if (dest)
			pt.scale(dest);
		world93_cefc4c->getPlayer()->unknown5dea60(pt.randomInRange_40c130() * world93_cefc4c->getPlayer()->unknown5ca260() / 100,0);
		string x = "Core integrity partially restored (" + intToString(world93_cefc4c->getPlayer()->unknown490840()) + ").";
		do
		{
			if (showMessage93(0x2b7,&x,0,0,HProp(),HProp(),&world93_cefc4c->getPlayer()->getPosition(),0))
				consoleA93_cec058->unknown8758d0(true);
			logMsgs93_cec0b4->scrollToEnd();
		} while (0);
	}
	if (power)
	{
		Pos range2(0x14,0x32);
		world93_cefc4c->getPlayer()->setUnknown93(OpX5_minInt(world93_cefc4c->getPlayer()->unknown45a9d0(),100) * range2.randomInRange_40c130() / 100);
		string msg2 = "System integrity partially restored (" + intToString(world93_cefc4c->getPlayer()->unknown45a9d0()) + ").";
		do
		{
			if (showMessage93(0x2b7,&msg2,0,0,HProp(),HProp(),&world93_cefc4c->getPlayer()->getPosition(),0))
				consoleA93_cec058->unknown8758d0(true);
			logMsgs93_cec0b4->scrollToEnd();
		} while (0);
	}
	if (rebuild)
	{
		bool ok = false;
		if (location93_d1e888->type == 0xc)
		{
			Point p;
			if (world93_cefc4c->findPlaceableNear(*world93_cefc4c->getStarts()->front(),p,1))
				ok = unknown69fa80(&p);
		}
		else
			ok = unknown69fa80(0);
		if (ok)
		{
			string text = "The surroundings shift and blur.";
			opW5_message(0x320,HProp(),text,0);
			int fx;
			if (OpU8a_lookup2("Xom_Appear",&fx))
				endObj93_cefc50->unknown508610()->init(endObj93_cefc50,fx,world93_cefc4c->getPlayer()->getPosition(),point93_d2e20c,0,0,0,9,0);
		}
	}
	obj93_cec138->unknown9666d0();
	unknowna0 = value93_caf154;
	unknowna4 = false;
	setValue(0x4b);
	mapView93_cec054->unknown49adc0(1000);
}
