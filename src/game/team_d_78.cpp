// team_d_78: BS member 0x6e33a0 (map generation step called from BS::initilize): Scraplab lockdown
// (collapsed tunnels, notices, sealed doors, Subdwellers) and the Scraptown Zionite.
// NOTE: class layouts are partial; member and method names are placeholders. Info78::Info78 is a local copy
// of 0x45b950 (Push_45b950::operate, mapped elsewhere), defined here only so LTCG proves the new cannot throw.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();								// NOTE: placeholder name (Push_453b40::operate)
	Point(const Point &p) throw();			// 0x46ca50
};

struct Area78	// NOTE: placeholder name
{
	Point min;
	Point max;
};
extern Area78 area78_d1eaf8;	// NOTE: placeholder name

struct Location78	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;
};

class HLoc78	// NOTE: placeholder name
{
	int ID;
public:
	Location78 *operator->() const;
};
extern vector<HLoc78> locations78_d1e88c;	// NOTE: placeholder name

class OpV1_GameData
{
public:
	void setEntryText(const string &key, const string &text);
};
extern OpV1_GameData gameData78_d1e860;	// NOTE: placeholder name

struct OpQ5_T9da9f0	// NOTE: placeholder layout (0x34-byte map marker)
{
	Point	pos;	// +0x00
	HLoc78	loc;	// +0x08
};
template <class T> void OpQ5_deleteObjectAndStep(vector<T*> &v, int &index);	// NOTE: placeholder name

struct OpQ5_U9d7710;	// machine data record
struct OpQ5_U9d7530;	// robot data record
template <class T> bool OpQ5_findByName(vector<T*> &v, const string &name, T *&result);	// NOTE: placeholder name; const string& here (the exe instantiation takes string&)
extern vector<OpQ5_U9d7710 *> machines78_cf35b0;	// NOTE: placeholder name
extern vector<OpQ5_U9d7530 *> records78_d25de0;	// NOTE: placeholder name

struct Rec78;	// NOTE: placeholder name
int OpU8a_indexOfName4(vector<Rec78 *> &v, const string &name);	// NOTE: placeholder name
extern vector<Rec78 *> names78_d35b58;	// NOTE: placeholder name

class Info78	// NOTE: placeholder name (0xc-byte record built by 0x45b950)
{
public:
	int		unknown0;
	int		index;
	bool	unknown8;

	Info78(int a, int index_);	// NOTE: defined here (body as Push_45b950::operate) so LTCG proves new cannot throw
};

Info78::Info78(int a, int index_)
{
	unknown0 = a;
	index = index_;
	unknown8 = false;
}

class Machine78	// NOTE: placeholder name (OpS1d_IntList45bbe0)
{
public:
	void unknown45bbe0(Info78 *info);	// NOTE: placeholder name
};

class Prop
{
public:
	int unknown45c870(int type);			// NOTE: placeholder name
	Machine78 *getMachine();				// NOTE: placeholder name (folded getter)
	const string &name45c590();				// NOTE: placeholder name (Push_45c590::operate)
	void unknown45ce10(bool a, int b, bool c, class HProp p);	// NOTE: placeholder name
	void unknown45cc50(const Point &p);		// NOTE: placeholder name
};

class HProp
{
public:
	int ID;
	HProp();
	bool isNull() const;
	bool isValid() const;
	Prop *operator->() const;
};

class Entity
{
public:
	int unknown45acb0(int value);	// NOTE: placeholder name
	void unknown637bb0();			// NOTE: placeholder name
	Point &getPosition();
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
	void unknown66a050(int terrainID, int cause, int flag);	// NOTE: placeholder name
	HProp getProp();
	HEntity getEntity();
	bool placeProp(HProp prop);	// NOTE: placeholder name (Push_45df50::operate)
};

class CellGrid78	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **at(int x, int y);			// NOTE: folded with OpX5_Array2D<int>::at
	Cell **atPoint(const Point &p);		// NOTE: folded (OpX5_Array2D<int>::atPoint)
	void getRandom_9cf0c0(Point *out);	// NOTE: placeholder name
};
extern CellGrid78 cells78_cfd44c;	// NOTE: placeholder name

class Factory78	// NOTE: placeholder name (0xcefaa8)
{
public:
	HProp createE(OpQ5_U9d7710 *data);	// NOTE: placeholder name
};
extern Factory78 *factory78_cefaa8;	// NOTE: placeholder name

struct Terrain78	// NOTE: placeholder name
{
	int ID;
};
extern Terrain78 *terrain78_cefb9c;	// NOTE: placeholder name
bool terrainFlagB_448b80(const Point &p);	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float lo, float hi);
};
extern RNG rng;

extern bool flag78_d1e880;	// NOTE: placeholder name
extern bool flag78_d257e6;	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	char						pad000[0x10];
	vector<OpQ5_T9da9f0 *>		markers;	// +0x10
	char						pad020[0x66c - 0x20];
	HEntity						player;		// +0x66c

	bool findPlaceableNear(const Point &p, Point &out, int size);	// NOTE: placeholder name
	HEntity placeEntity(OpQ5_U9d7530 *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
	HEntity unknown6c5dc0(const string &name, const Point &pos, int group, bool flag, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &text, int value);
	void unknown6e33a0();	// NOTE: placeholder name
};

void BS::unknown6e33a0()
{
	bool lockdown = false;
	for (unsigned int i = 1; i < locations78_d1e88c.size(); i++)
	{
		if (locations78_d1e88c[i]->type == 0xf)
		{
			if (locations78_d1e88c[i + 1]->type != 0xa)
				lockdown = true;
			break;
		}
	}
	if (lockdown)
	{
		gameData78_d1e860.setEntryText("recScraplabLockedDown_g","1");
		OpQ5_U9d7530 *sub;
		for (int j = 0; j < markers.size(); j++)
		{
			if (markers[j]->loc->type == 0xb)
			{
				OpQ5_T9da9f0 *it = markers[j];
				(*cells78_cfd44c.atPoint(it->pos))->unknown66a050(terrain78_cefb9c->ID,2,1);
				OpQ5_U9d7710 *tag;
				Point pt(it->pos);
				OpQ5_deleteObjectAndStep(markers,j);
				if (OpQ5_findByName(machines78_cf35b0,"Collapsed Tunnel",tag) && (*cells78_cfd44c.atPoint(pt))->getProp().isNull())
				{
					if ((*cells78_cfd44c.atPoint(pt))->placeProp(factory78_cefaa8->createE(tag)))
						(*cells78_cfd44c.atPoint(pt))->getProp()->unknown45cc50(pt);
				}
				break;
			}
		}
		for (int x = area78_d1eaf8.min.x; x <= area78_d1eaf8.max.x; x++)
		{
			for (int y = area78_d1eaf8.min.y; y <= area78_d1eaf8.max.y; y++)
			{
				if ((*cells78_cfd44c.at(x,y))->getProp().isValid() && (*cells78_cfd44c.at(x,y))->getProp()->unknown45c870(0x86))
				{
					if ((*cells78_cfd44c.at(x,y))->getProp()->getMachine())
					{
						if ((*cells78_cfd44c.at(x,y))->getProp()->name45c590() == "Scraplab SEP")
						{
							Machine78 *m = (*cells78_cfd44c.at(x,y))->getProp()->getMachine();
							int idx = OpU8a_indexOfName4(names78_d35b58,"Notice");
							m->unknown45bbe0(new Info78(0,idx));
						}
					}
					else
						(*cells78_cfd44c.at(x,y))->getProp()->unknown45ce10(false,0,true,HProp());
				}
				if ((*cells78_cfd44c.at(x,y))->getEntity().isValid() && (*cells78_cfd44c.at(x,y))->getEntity()->unknown45acb0(0x86))
					(*cells78_cfd44c.at(x,y))->getEntity()->unknown637bb0();
			}
		}
		OpQ5_findByName(records78_d25de0,"Subdweller",sub);
		if (sub)
		{
			Point p2;
			for (int n = rng.rangeInt(5.0f,10.0f); n > 0; n--)
			{
				for (int t = 500; t > 0; t--)
				{
					cells78_cfd44c.getRandom_9cf0c0(&p2);
					if (findPlaceableNear(p2,p2,1) && !terrainFlagB_448b80(p2))
					{
						placeEntity(sub,p2,6,true,0x22,0xe,false);
						break;
					}
				}
			}
		}
	}
	if (flag78_d1e880 && (!flag78_d257e6 || rng.chance(5)))
	{
		HEntity z = unknown6c5dc0("Zionite",player->getPosition(),8,true,0x18,0xe,false);
		if (z.isValid())
		{
			unknown6c65a0(z,"REC_Scraptown_Zionite1",0);
			flag78_d257e6 = true;
		}
	}
}
