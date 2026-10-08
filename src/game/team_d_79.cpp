// team_d_79: BS member 0x6de850 (map generation step called from BS::initilize): duplicates marked items,
// places a Zionite carrying an Exiles log, edits Zion message records, and posts the level message.
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();								// NOTE: placeholder name (Push_453b40::operate)
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

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int w, int h);
	void randomPos_40b000(Point *out);	// NOTE: placeholder name
};

template <class T>
class OpR5h_WL	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	OpR5h_WL() throw();	// 0x9bab50
	void add(T value, int weight);
	T &pick();
	unsigned int size();	// NOTE: placeholder name (0x9b81d0)
};

struct Unlock79	// NOTE: placeholder name and layout
{
	char	pad000[0x140];
	int		index;	// +0x140
};

struct Log79	// NOTE: placeholder name and layout (Zion log record)
{
	int					unknown00;
	string				name;		// +0x04
	char				pad20[0xc0 - 0x20];
	vector<Unlock79 *>	unlocks;	// +0xc0
};
extern vector<Log79 *> logs79_d2c408;		// NOTE: placeholder name
extern vector<int> unlocked79_cf4934;		// NOTE: placeholder name
struct Weight79	// NOTE: placeholder name and layout
{
	char	pad00[0x9c];
	int		weight;	// +0x9c
};
extern vector<Weight79 *> weights79_cf3a20;	// NOTE: placeholder name
extern string prefix79_d292f4;				// NOTE: placeholder name

struct OpQ5_U9dba30	// NOTE: placeholder layout (message record)
{
	char	pad00[0x3c];
	string	text;		// +0x3c
	string	original;	// +0x58
};
template <class T> bool OpQ5_findByName(vector<T*> &v, const string &name, T *&result);	// NOTE: placeholder name; const string& here (the exe instantiation takes string&)
extern vector<OpQ5_U9dba30 *> messages79_d35b58;	// NOTE: placeholder name

class HProp
{
public:
	int ID;
	HProp();
};
void message79_5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name

class Entity
{
public:
	void unknown6395d0(Log79 *log, int flag);	// NOTE: placeholder name
};

class HEntity
{
public:
	int ID;
	HEntity();	// NOTE: folded with HProp::HProp
	Entity *operator->() const;
};

struct ItemData79	// NOTE: placeholder name and layout
{
	char	pad00[0x68];
	int		copies;	// +0x68
};

class Item
{
public:
	int getEffectValue(int type);	// NOTE: placeholder name
	ItemData79 *getData();			// NOTE: placeholder name (folded getter)
};

class HItem
{
public:
	int ID;
	bool isValid() const;
	Item *operator->() const;
};

class Cell
{
public:
	HItem getItem();
};

class CellGrid79	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **at(int x, int y);	// NOTE: folded with OpX5_Array2D<int>::at
};
extern CellGrid79 cells79_cfd44c;	// NOTE: placeholder name

extern int state79_d1eac0;	// NOTE: placeholder name
extern int state79_cf462c;	// NOTE: placeholder name

class BS
{
public:
	HItem unknown6c5400(ItemData79 *def, const Point &pos);			// NOTE: placeholder name
	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
	HEntity unknown6c5dc0(const string &name, const Point &pos, int group, bool flag, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name
	void unknown6de850();	// NOTE: placeholder name
};

void BS::unknown6de850()
{
	if (state79_d1eac0 != 2)
	{
		OpQ1_Box a(0x45,1,0x4b,4);
		vector<HItem> adj;
		vector<Point> first;
		for (int x = a.x1; x <= a.x2; x++)
		{
			for (int y = a.y1; y <= a.y2; y++)
			{
				if ((*cells79_cfd44c.at(x,y))->getItem().isValid() && (*cells79_cfd44c.at(x,y))->getItem()->getEffectValue(0x63))
				{
					adj.push_back((*cells79_cfd44c.at(x,y))->getItem());
					first.push_back(Pos(x,y));
				}
			}
		}
		for (unsigned int k = 0; k < adj.size(); k++)
		{
			if (adj[k]->getData()->copies)
			{
				for (int n = adj[k]->getData()->copies; n > 0; n--)
					unknown6c5400(adj[k]->getData(),first[k]);
			}
		}
	}
	if (state79_d1eac0 == 0 || state79_d1eac0 == 1)
	{
		Rect tag(0x2e,0x26,0x34,0x21);
		OpR5h_WL<int> it;
		for (unsigned int i = 0; i < logs79_d2c408.size(); i++)
		{
			if (logs79_d2c408[i]->name.find(prefix79_d292f4 + "EXI",0) != string::npos && unlocked79_cf4934[logs79_d2c408[i]->unlocks.front()->index] == 0)
				it.add((int)logs79_d2c408[i],weights79_cf3a20[logs79_d2c408[i]->unlocks.front()->index]->weight);
		}
		if (!it.size())
		{
		}
		else
		{
			Log79 *pick = (Log79 *)it.pick();
			for (int t = 500; t > 0; t--)
			{
				Point p;
				tag.randomPos_40b000(&p);
				if (findPlaceableNear(p,p,1))
				{
					HEntity e;
					e = unknown6c5dc0("Zionite",p,9,true,0x22,0xe,false);
					if (pick)
					{
						e->unknown6395d0(pick,0);
						unlocked79_cf4934[pick->unlocks.front()->index] = 1;
					}
					break;
				}
			}
		}
		if (state79_cf462c == 8)
		{
			OpQ5_U9dba30 *rec;
			if (!OpQ5_findByName(messages79_d35b58,"MSG001873-01*",rec))
			{
			}
			else
				rec->text = rec->original = "I heard MAIN.C made an account on Patchboard just to dis Warlord! --DEC";
			if (!OpQ5_findByName(messages79_d35b58,"MSG003537-01*",rec))
			{
			}
			else
				rec->text = rec->original = "Patchboard? -- HEX";
			if (!OpQ5_findByName(messages79_d35b58,"MSG004902-01*",rec))
			{
			}
			else
				rec->text = rec->original = "It's like the Pastebin of Zion. You can see what he wrote for yourself at 8KSDbDjz. --DEC";
		}
	}
	switch (state79_d1eac0)
	{
	case 2:
		do
		{
			message79_5141b0(0x13c,0,0,0,HProp(),0);
		} while (0);
		break;
	case 3:
		do
		{
			message79_5141b0(0x13d,0,0,0,HProp(),0);
		} while (0);
		break;
	}
}
