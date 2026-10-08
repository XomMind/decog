// team_d_112: BS member 0x742630 (callers BS::unknown7456a0/unknown7457f0 and one more): opens a set of door
// cells - door sound and open effect, Garrison checkpoint scanners in range (or anywhere when global) are
// switched, the open message names the door, and every door prop in the set is toggled.
// NOTE: class layouts are partial; names other than BS are placeholders.
// NOTE: the non-global scanner switch leaves both loops with a goto (the exe jumps straight past them).
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};
extern Point effectOrigin112_d2e20c;	// NOTE: placeholder name

struct Area112	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;

	Area112();								// 0x40b100
	Area112(const Area112 &a);				// 0x40b130
	Area112 &operator=(const Area112 &a);	// NOTE: folded with the copy constructor
};

int opR1d_454260(const Point &p, int id);	// NOTE: placeholder name
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&result);	// NOTE: placeholder name
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

struct Scanner112;	// NOTE: placeholder name (prop type record)
extern vector<Scanner112 *> propTypes112_d2c408;	// NOTE: placeholder name

class Prop;

class HProp
{
public:
	int ID;
	HProp();
	Prop *operator->() const;	// NOTE: OpC_Handle::get22c
	bool isValid() const;	// NOTE: folded with HItem::isValid
};

class Prop
{
public:
	const string &getName();
	bool unknown45c9d0(Scanner112 *type);	// NOTE: placeholder name
	void unknown45ce10(bool a, int b, bool c, HProp d);	// NOTE: placeholder name
};

class Cell
{
public:
	HProp getProp();
};

class CellGrid112	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **at(int x, int y);			// NOTE: folded (OpX5_Array2D<int>::at)
	Cell **atPoint(Point &p);			// NOTE: folded (OpX5_Array2D<int>::atPoint)
	Area112 getArea();					// NOTE: placeholder name (0x9b4400)
	void getRect(const Point &center, int radius, Area112 *out);	// NOTE: placeholder name (0x9b4430)
};
extern CellGrid112 cells112_cfd44c;	// NOTE: placeholder name

class EffectObj112	// NOTE: placeholder name (object initialized by 0x503b20)
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name
};

class EndObjB
{
public:
	EffectObj112 *unknown508610();	// NOTE: placeholder name
};
extern EndObjB *endObj112_cefc50;	// NOTE: placeholder name

struct Location112	// NOTE: placeholder name and layout
{
	int		unknown00;
	int		type;	// +0x04
};

class HLocation112	// NOTE: placeholder name
{
public:
	int ID;
	Location112 *operator->() const;	// NOTE: OpC_Handle::get23c
};
extern HLocation112 location112_d1e888;	// NOTE: placeholder name

class OpV1_GameData
{
public:
	const string &getEntryText(const string &key);
};
extern OpV1_GameData gameData112_d1e860;	// NOTE: placeholder name

void opW5_message(int type, HProp prop, const string &text, int value);	// NOTE: placeholder name

class BS
{
public:
	bool isVisible(const Point &p);
	void unknown742630(vector<Point> &points, bool global, bool hacked);	// NOTE: placeholder name
};

void BS::unknown742630(vector<Point> &points, bool global, bool hacked)
{
	bool found = false;
	for (unsigned int i = 0; i < points.size(); i++)
	{
		if (opR1d_454260(points[i],0x7e))
			break;
	}
	int fx;
	if (OpU8a_lookup2("P_Machine_Door_Open",&fx))
	{
		for (unsigned int j = 0; j < points.size(); j++)
		{
			if (isVisible(points[j]))
			{
				endObj112_cefc50->unknown508610()->init(endObj112_cefc50,fx,points[j],effectOrigin112_d2e20c,0,0,0,9,0);
				found = true;
			}
		}
	}
	if (location112_d1e888->type == 0xd)
	{
		Scanner112 *scanner;
		if (OpQ5_findByName(propTypes112_d2c408,"GAR_Checkpoint_Scan",scanner))
		{
			Area112 area;
			if (global)
				area = cells112_cfd44c.getArea();
			else
				cells112_cfd44c.getRect(points.front(),3,&area);
			for (int x = area.x1; x <= area.x2; x++)
			{
				for (int y = area.y1; y <= area.y2; y++)
				{
					if ((*cells112_cfd44c.at(x,y))->getProp().isValid() && (*cells112_cfd44c.at(x,y))->getProp()->unknown45c9d0(scanner))
					{
						(*cells112_cfd44c.at(x,y))->getProp()->unknown45ce10(true,0,true,HProp());
						if (!global)
							goto done;
					}
				}
			}
		}
	}
done:
	if (found)
	{
		string msg = (*cells112_cfd44c.atPoint(points.front()))->getProp()->getName();
		if (hacked)
			msg += " opened.";
		else if (location112_d1e888->type == 0x17 && !stringToInt(gameData112_d1e860.getEntryText("warAttackedLocals_g")))
			msg += " hacked open.";
		else if (location112_d1e888->type != 0xd)
			msg += " opened remotely.";
		else
			msg += " activated.";
		opW5_message(0x320,HProp(),msg,0);
	}
	for (unsigned int k = 0; k < points.size(); k++)
		(*cells112_cfd44c.atPoint(points[k]))->getProp()->unknown45ce10(true,0,true,HProp());
}
