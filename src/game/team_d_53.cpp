// team_d_53: BS member 0x6eeaf0 (level generation: occasionally place a sapper squad and a Fedlink squad).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct PropData53	// NOTE: placeholder name and layout
{
	char	pad000[0x8c];
	int		unknown8c;	// NOTE: placeholder name
};

class Prop
{
public:
	bool unknown45cb10();			// NOTE: placeholder name
	PropData53 *getData();			// NOTE: placeholder name (folded getter)
	const Point &getPos();			// NOTE: placeholder name (0x4184d0)
};

class HProp
{
	int ID;
public:
	Prop *operator->() const;
};

class Cell
{
public:
	HProp getProp();
};

class CellGrid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(const Point &p);	// NOTE: folded with OpX5_Array2D<int>::atPoint
};
extern CellGrid cells_cfd44c;	// NOTE: placeholder name

struct FactionRec53;	// NOTE: placeholder name
extern vector<FactionRec53 *> factions53_d2c408;	// NOTE: placeholder name
extern vector<vector<int> *> rooms53_d39f1c;	// NOTE: placeholder name
extern vector<vector<HProp> > props53_d31640;	// NOTE: placeholder name

class Range53	// NOTE: placeholder name
{
public:
	int randomInRange();	// NOTE: folded with Point::randomInRange_40c130
};
extern Range53 sapperCount53_d35888;	// NOTE: placeholder name

struct Location53	// NOTE: placeholder name and layout
{
	int unknown00;
	int unknown04;
	int depth;		// +0x08
};

class HLoc53	// NOTE: placeholder name
{
	int ID;
public:
	Location53 *operator->() const;
};
extern HLoc53 location53_d1e888;	// NOTE: placeholder name
extern int int53_cf4b20;	// NOTE: placeholder name

class GameData53	// NOTE: placeholder name (0xd1e860)
{
public:
	const string &getEntryText(const string &key);	// 0x46f6d0
};
extern GameData53 gameData53_d1e860;	// NOTE: placeholder name

class Map53	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	vector<vector<Point> > *unknown459070();	// NOTE: placeholder name (trivial getter)
};
extern Map53 *world53;	// NOTE: placeholder name (0xcefc4c)

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&result);	// NOTE: placeholder name
template <class T> void OpX5_insertAt(vector<T> &v, int index, T value);	// NOTE: placeholder name

class BS
{
public:
	int countPassableAdjacent(const Point &p);	// NOTE: placeholder name (0x71c850)
	void unknown6c6770(HProp prop, FactionRec53 *faction, int a);	// NOTE: placeholder name
	void unknown6c6700(HProp prop, const string &name, int a);	// NOTE: placeholder name
	void unknown6eeaf0();	// NOTE: placeholder name
};

void BS::unknown6eeaf0()
{
	if (rng.chance(3))
	{
		FactionRec53 *rec;
		if (OpQ5_findByName(factions53_d2c408,"FAC_Sapper",rec))
		{
			vector<int> order;
			for (int i = 0; i < rooms53_d39f1c.size(); i++)
			{
				unsigned int n = rooms53_d39f1c[i]->size();
				if (order.empty() || n <= rooms53_d39f1c[order.back()]->size())
					order.push_back(i);
				else
				{
					for (unsigned int j = 0; j < order.size(); j++)
					{
						if (n > rooms53_d39f1c[order[j]]->size())
						{
							OpX5_insertAt(order,j,i);
							break;
						}
					}
				}
			}
			if (order.size())
			{
				for (int count = sapperCount53_d35888.randomInRange(); count != 0; count--)
				{
					bool done = count == 0 && rng.chance(33);
					int target = -1;
					if (done)
					{
						for (unsigned int k = 0; k < order.size(); k++)
						{
							if (props53_d31640[rooms53_d39f1c[order[k]]->front()].front()->unknown45cb10())
							{
								target = rooms53_d39f1c[order[k]]->front();
								break;
							}
						}
					}
					else
					{
						for (unsigned int a = 0; a < order.size(); a++)
						{
							for (unsigned int b = 0; b < rooms53_d39f1c[order[a]]->size(); b++)
							{
								if (props53_d31640[(*rooms53_d39f1c[order[a]])[b]].front()->getData()->unknown8c)
								{
									target = (*rooms53_d39f1c[order[a]])[b];
									goto found;
								}
							}
						}
					}
found:
					for (unsigned int c = 0; c < props53_d31640[target].size(); c++)
					{
						if (countPassableAdjacent(props53_d31640[target][c]->getPos()))
						{
							unknown6c6770(props53_d31640[target][c],rec,0);
							break;
						}
					}
				}
			}
		}
	}
	if (location53_d1e888->depth <= 5 && int53_cf4b20 && !stringToInt(gameData53_d1e860.getEntryText("scrAttackedLocals_g")) && rng.chance(5))
	{
		vector<Point> &markers = (*world53->unknown459070())[3];
		if (!markers.empty())
			unknown6c6700((*cells_cfd44c.atPoint(markers[0]))->getProp(),"FAC_Elite_Fedlink",0);
	}
}
