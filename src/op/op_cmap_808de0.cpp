// op_cmap_808de0: CMap map-overlay animation dispatcher (0x808de0): starts the scan/sensor/IFF/terrain/shield/hacktrap/
//	stasis/label overlay animations requested by item activation (COGMIND.exe Beta 17.1).
// NOTE: class layouts are partial; member, method and global names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

string intToString(int value);
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
void opR1d_4541b0(int a, int b, int c);	// NOTE: placeholder name
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
int ops7_clamp_9cdc80(int low, int value, int high);	// NOTE: placeholder name
int opr1c_getPercentTier(int value, int max);	// NOTE: placeholder name (0x4347e0)
string &padLeft_408090(string &text, int width, char fill);	// NOTE: placeholder name
int opw8_distance(int x1, int y1, int x2, int y2);	// NOTE: placeholder name (0x406480)

struct Pos
{
	int x;
	int y;

	Pos();	// 0x453b40
	Pos(int x_, int y_);	// 0x46ca20
	Pos(int v);	// 0x409990
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos &operator=(const Pos &pos);	// 0x46ca50 (folded with the copy ctor)
	Pos operator+(const Pos &pos) const;	// 0x409b60
	Pos &operator+=(const Pos &pos);	// 0x409a30
	bool operator==(const Pos &pos) const;	// 0x409b90
	bool operator!=(const Pos &pos) const;	// 0x409bd0
	void set(int x_, int y_);	// 0x40a010 NOTE: placeholder name
};
typedef Pos Point;
struct PosB { int x; int y; };	// NOTE: same name as src/game/cc_r2_19.cpp

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
int teamb_select808db0(bool useX, Point &p);	// NOTE: placeholder name (picks x or y)
void OpV4c_Fn9d5460(vector<Point> &v, unsigned int index, Point p);	// NOTE: placeholder name (insert at index)
bool traceSubcellLine(const Point &from, const Point &to, vector<Point> &path, vector<int> &steps, int speed);
template <class T> void OpQ5_appendVector(vector<T> &v, vector<T> &other);	// NOTE: placeholder name
template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name
bool cmapAnim_containsInt_9db330(vector<int> &v, int value);	// NOTE: placeholder name (OpX5_containsRecord)

class Area	// NOTE: placeholder name (two corner points)
{
public:
	Area();	// 0x40b100
	Area(int x1, int y1, int x2, int y2);	// 0x40b1e0
	bool touches_40baa0(const Area &other);	// NOTE: placeholder name
	void clip_40bc40(const Point &min_, const Point &max_);	// NOTE: placeholder name
	void offset_40bdd0(const Point &by);	// NOTE: placeholder name

	Point min;
	Point max;
};

template <class T>
class Array2D	// NOTE: partial
{
public:
	int width;
	int height;
	T *data;

	T &operator()(int x, int y);	// 0x9ceda0
	T &operator()(const Point &p);	// 0x9ced70
	bool inBounds(int x, int y);	// 0x9b45c0
	bool contains(const Point &p);	// 0x9b43b0
	int getWidth();	// 0x9fcd80
	int getHeight();	// 0x9b8f00
	void getRect(const Point &p, int radius, Area &out);	// 0x9b4430
	void getBounds(const Point &center, int radius, Point &min, Point &max);	// 0x9b7a40
};

struct XColor;

class XConsole
{
public:
	virtual ~XConsole();

	bool inBounds(int x, int y);	// 0x417360
	bool inBounds(const Pos &pos);	// 0x4173d0
	int getWidth();	// 0x44b0d0
	int getHeight();	// 0x4174c0
	void print(int x, int y, const string &text);	// 0x4181d0
	void resetBack_418450();	// NOTE: placeholder name
	Array2D<XColor> *getBuffer_4184d0();	// NOTE: placeholder name

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);	// 0x48c060
	void unknown48c3c0(int value);	// NOTE: placeholder name

	int unknown60;
	void *engine;
	void *title;
};

class XTimerI	// NOTE: same declaration as src/game/cc_r2_19.cpp
{
public:
	XTimerI(int type_, XConsole *console_, bool c_, int d_, const PosB &e_, int f_, int g_, int h_, const PosB &i_);
	int type;
	Console *console;
	char pad8[0x31 - 8];
	bool unknown31;	// NOTE: placeholder name
	char pad32[0x34 - 0x32];
};

class HItem;
class HGroup;
class Entity	// NOTE: partial
{
public:
	int unknown5c7d30();	// NOTE: placeholder name
	int unknown5c7d80(bool *out);	// NOTE: placeholder name
	int unknown5c7e40();	// NOTE: placeholder name
	int unknown45a3c0();	// NOTE: placeholder name
	int unknown5d22a0(int type);	// NOTE: placeholder name
	int unknown5d2090(int type);	// NOTE: placeholder name
	int unknown5d2150(int type, int base);	// NOTE: placeholder name
	int unknown5d7b00(bool flag);	// NOTE: placeholder name
	HItem unknown5d2380(int type);	// NOTE: placeholder name
	HItem unknown5d24e0(int type);	// NOTE: placeholder name
	int unknown5c7fc0(class HEntity other);	// NOTE: placeholder name
	int getSize();	// 0x45a360
	int getTarget();	// 0x45a760
	HGroup getGroup();	// 0x45a3f0
	const Point &getPosition() throw();	// 0x45a4a0
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	Entity *operator->() const;	// 0x9b6570
	bool operator!=(HEntity other) const;	// 0x9b6510
};

class Item	// NOTE: partial
{
public:
	int unknown457fb0();	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	Item *operator->() const;	// 0x9b65b0
};

class CmapAnim_Group	// NOTE: placeholder name (Group)
{
public:
	int getType();	// 0x9b4350
};

class HGroup
{
public:
	int ID;
	CmapAnim_Group *operator->() const;	// 0x9b7250
};

class CmapAnim_PropRec	// NOTE: placeholder name
{
public:
	bool unknown65cf50(int groupType);	// NOTE: placeholder name
};

class Prop	// NOTE: partial
{
public:
	CmapAnim_PropRec *unknown44b020();	// NOTE: placeholder name (folded getter)
	int unknown457af0();	// NOTE: placeholder name (conduit index)
};

class HProp
{
public:
	int ID;
	HProp();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	Prop *operator->() const;	// 0x9b64f0
};

class Cell	// NOTE: partial
{
public:
	HEntity getEntity();	// 0x45d250
	HProp getProp();	// 0x45d550
	bool unknown45db70();	// NOTE: placeholder name
	bool isDoor();	// 0x45dda0
	bool unknown66b5b0();	// NOTE: placeholder name
};

struct CmapAnim_Scan	// NOTE: placeholder name (0xc-byte scan-memory entry)
{
	int turn;
	int pad4;
	HEntity entity;
};

class BS	// NOTE: partial (the world object behind the global at 0xcefc4c)
{
public:
	bool isVisible_463190(int x, int y);	// NOTE: placeholder name
	bool unknown463380(int x, int y);	// NOTE: placeholder name
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	int unknown7163a0(HEntity e);	// NOTE: placeholder name
	bool unknown716250(HEntity e, int rating, string *reason);	// NOTE: placeholder name
	int getMaxItemRange71c930();	// NOTE: placeholder name

	char pad0[0x66c];
	HEntity player;	// NOTE: placeholder name
	char pad670[0x674 - 0x670];
	Array2D<bool> unknown674;	// NOTE: placeholder name
	char pad680[0x69c - 0x680];
	Array2D<int> unknown69c;	// NOTE: placeholder name
	char pad6a8[0x740 - 0x6a8];
	Array2D<CmapAnim_Scan> scans;	// NOTE: placeholder name
	int scanTurn;	// NOTE: placeholder name
	static bool opw3_unknown72c080(vector<class CmapAnim_Conduit *> &list, bool silent, HEntity e);	// NOTE: placeholder name
};

class CmapAnim_Conduit	// NOTE: placeholder name (OpR3e_Conduit)
{
public:
	bool unknown6c1320();	// NOTE: placeholder name
};

class CmapAnim_Effect	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class CmapAnim_Engine	// NOTE: placeholder name (0xcefc64)
{
public:
	CmapAnim_Effect *unknown50fb50(CmapAnim_Engine *engine, int type, const Pos &a, const Pos &b, Pos *c, Pos *d, int value);	// NOTE: placeholder name
};

class RNG
{
public:
	int rangeInt(float a, float b) throw();	// 0x406d70
};
extern RNG rng;	// 0xd30908

extern BS *cmapAnim_world;	// NOTE: placeholder name (0xcefc4c)
extern CmapAnim_Engine *cmapAnim_engine;	// NOTE: placeholder name (0xcefc64)
extern Array2D<Cell *> cmapAnim_cells;	// NOTE: placeholder name (0xcfd44c)
extern Pos cmapAnim_cfbec0;	// NOTE: placeholder name
extern unsigned int cmapAnim_tickCount;	// NOTE: placeholder name (0xcaed20)
extern XConsole *cmapAnim_mapConsole;	// NOTE: placeholder name (0xcec054)
extern bool cmapAnim_asciiEnabled;	// NOTE: placeholder name (0xd28d15)
extern string cmapAnim_d33e38[];	// NOTE: placeholder name (decoy anim suffixes)
extern vector<Point> cmapAnim_d35860;	// NOTE: placeholder name
extern vector<Point> cmapAnim_d1daec;	// NOTE: placeholder name
extern vector<CmapAnim_Conduit *> cmapAnim_d39f1c;	// NOTE: placeholder name

struct C63_CMap : public Console	// NOTE: placeholder name (CMap); partial layout
{
	bool unknown808de0(int type);	// NOTE: placeholder name
	void unknown808510(const Pos &center, int radius, vector<Point> &points);	// NOTE: placeholder name
	void unknown8051f0(Pos *min, Pos *max);	// NOTE: placeholder name
	bool hasEntityLabel(int type, HEntity entity);	// NOTE: placeholder name (0x49b1a0)
	void removeLabels(int type);	// NOTE: placeholder name (0x49b390)

	Pos unknown6c;	// NOTE: placeholder name
	char pad74[0x134 - 0x74];
	int mode;	// NOTE: placeholder name
	vector<Point> points;	// NOTE: placeholder name
	int radius;	// NOTE: placeholder name
	Pos center;	// NOTE: placeholder name
	Pos offset;	// NOTE: placeholder name
	unsigned int startTick;	// NOTE: placeholder name
	int unknown160;	// NOTE: placeholder name
	int unknown164;	// NOTE: placeholder name
	vector<vector<Point> > paths;	// NOTE: placeholder name
	vector<vector<int> > steps;	// NOTE: placeholder name
	vector<Area> boxes;	// NOTE: placeholder name
	vector<unsigned int> boxTimes;	// NOTE: placeholder name
	char pad1a8[0x1d8 - 0x1a8];
	vector<XTimerI *> labels;	// NOTE: placeholder name
	char pad1e8[0x460 - 0x1e8];
	vector<CmapAnim_Conduit *> conduits;	// NOTE: placeholder name
};

bool C63_CMap::unknown808de0(int type)
{
	if (mode != 0)
	{
		if (!points.empty())
		{
			points.clear();
			if (mode == 2)
				removeLabels(0);
		}
		else if (!paths.empty())
		{
			paths.clear();
			steps.clear();
			removeLabels(0xd);
		}
		else if (!boxes.empty())
		{
			boxes.clear();
			boxTimes.clear();
		}
	}
	mode = type;
	if (mode == 0)
		return false;
	center = cmapAnim_world->player->getPosition();
	offset = unknown6c;
	startTick = cmapAnim_tickCount;
	unknown160 = -1;
	unknown164 = -1;
	int sound = 0;
	switch (mode)
	{
		case 1:
			radius = cmapAnim_world->player->unknown5c7d30();
			sound = 0x44;
			break;
		case 2:
			radius = cmapAnim_world->player->unknown5c7d80(NULL);
			sound = 0x45;
			goto ring;
		case 6:
			radius = cmapAnim_world->player->unknown45a3c0();
			sound = 0x4b;
			goto ring;
		case 9:
			radius = cmapAnim_world->player->unknown5d22a0(0x14);
			sound = 0x4e;
			goto ring;
		case 25:
			radius = 3;
		ring:
			unknown808510(center + offset,radius,points);
			if (!points.empty())
			{
				bool vertical = mode == 6;
				vector<Point> copy(points);
				points.clear();
				points.push_back(copy.back());
				copy.pop_back();
				while (!copy.empty())
				{
					if (teamb_select808db0(vertical,copy.back()) >= teamb_select808db0(vertical,points.back()))
					{
						points.push_back(copy.back());
						copy.pop_back();
					}
					else
					{
						for (unsigned int i = 0; i < points.size(); i++)
						{
							if (teamb_select808db0(vertical,copy.back()) < teamb_select808db0(vertical,points[i]))
							{
								OpV4c_Fn9d5460(points,i,copy.back());
								copy.pop_back();
								break;
							}
						}
					}
				}
				if (mode == 9)
				{
					int anim = 0;
					OpU8a_lookup1("CMap_Anim_Jam_Comm",&anim);
					if (anim)
					{
						vector<Point> edge;
						Pos pos = center + offset;
						for (unsigned int i = 0; i < points.size(); i++)
						{
							if (points[i].x > pos.x)
							{
								edge.push_back(points[i]);
								while (i + 1 < points.size() && points[i + 1].y == edge.back().y)
									i++;
							}
						}
						for (unsigned int j = 0; j < edge.size(); j++)
						{
							if (inBounds(pos.x,edge[j].y))
							{
								cmapAnim_engine->unknown50fb50(cmapAnim_engine,anim,Pos(pos.x,edge[j].y),cmapAnim_cfbec0,&Pos(edge[j].x,edge[j].y),&cmapAnim_cfbec0,9)->unknown50de10();
								cmapAnim_engine->unknown50fb50(cmapAnim_engine,anim,Pos(pos.x,edge[j].y),cmapAnim_cfbec0,&Pos(pos.x - (edge[j].x - pos.x),edge[j].y),&cmapAnim_cfbec0,9)->unknown50de10();
							}
						}
					}
					points.clear();
					mode = 0;
				}
			}
			break;
		case 26:
		{
			radius = 0x19;
			sound = 0x5a;
			unknown808510(center + offset,radius,points);
			if (!points.empty())
			{
				int anim = 0;
				OpU8a_lookup1("CMap_Anim_Unused_A_E",&anim);
				if (anim)
				{
					vector<Point> edge;
					Pos pos = center + offset;
					for (unsigned int i = 0; i < points.size(); i++)
					{
						if (points[i].y < pos.y)
						{
							edge.push_back(points[i]);
							while (i + 1 < points.size() && points[i + 1].x == edge.back().x)
								i++;
						}
					}
					for (unsigned int j = 0; j < edge.size(); j++)
					{
						Pos top(edge[j].x,edge[j].y + 1);
						Pos bottom(edge[j].x,pos.y + (pos.y - edge[j].y) - 1);
						if (top != bottom)
						{
							if (inBounds(top))
								cmapAnim_engine->unknown50fb50(cmapAnim_engine,anim,top,cmapAnim_cfbec0,&bottom,&cmapAnim_cfbec0,9)->unknown50de10();
							if (inBounds(bottom))
								cmapAnim_engine->unknown50fb50(cmapAnim_engine,anim,bottom,cmapAnim_cfbec0,&top,&cmapAnim_cfbec0,9)->unknown50de10();
						}
					}
				}
				points.clear();
				mode = 0;
			}
			break;
		}
		case 27:
		{
			radius = 0x19;
			sound = 0x5a;
			int animEdge2 = 0;
			int animSingle = 0;
			int animFill = 0;
			OpU8a_lookup1("CMap_Anim_Unused_B_E",&animEdge2);
			OpU8a_lookup1("CMap_Anim_Unused_B",&animSingle);
			OpU8a_lookup1("CMap_Anim_Unused_B_F",&animFill);
			if (animEdge2 && animSingle && animFill)
			{
				Array2D<int> *grid2 = &cmapAnim_world->unknown69c;
				for (int x = center.x - radius; x <= center.x + radius; x++)
				{
					for (int y = center.y - radius; y <= center.y + radius; y++)
					{
						if (grid2->inBounds(x,y) && (*grid2)(x,y) != 0)
							cmapAnim_engine->unknown50fb50(cmapAnim_engine,animFill,Pos(x + offset.x,y + offset.y),cmapAnim_cfbec0,0,0,9)->unknown50de10();
					}
				}
				Pos start;
				Pos endP;
				int x0 = center.x - radius;
				int top = center.y - radius;
				for (int y = center.y - radius; y <= center.y + radius; y++)
				{
					int cxB = x0;
					int cy = y;
				again:
					while (grid2->inBounds(cxB,cy) && (*grid2)(cxB,cy) != 0 && cy >= top)
					{
						cxB++;
						cy--;
					}
					if (cy >= top)
						start.set(cxB,cy);
					else
						continue;
					endP = start;
					while ((!grid2->contains(endP) || (*grid2)(endP) == 0) && endP.y >= top)
					{
						endP.x++;
						endP.y--;
					}
					cxB = endP.x + 1;
					cy = endP.y - 1;
					endP.x--;
					endP.y++;
					start += unknown6c;
					if (inBounds(start))
					{
						endP += unknown6c;
						if (endP == start)
							cmapAnim_engine->unknown50fb50(cmapAnim_engine,animSingle,endP,cmapAnim_cfbec0,0,0,9)->unknown50de10();
						else
							cmapAnim_engine->unknown50fb50(cmapAnim_engine,animEdge2,start,cmapAnim_cfbec0,&endP,&cmapAnim_cfbec0,9)->unknown50de10();
					}
					if (inBounds(cxB + unknown6c.x,cy + unknown6c.y))
						goto again;
				}
			}
			points.clear();
			mode = 0;
			break;
		}
		case 28:
		case 29:
		case 30:
		case 31:
		{
			sound = 0x5a;
			int animDecoy = 0;
			int animFog = 0;
			OpU8a_lookup1("CMap_Anim_0b10_Dec_" + cmapAnim_d33e38[mode - 28] + "_E",&animDecoy);
			OpU8a_lookup1("CMap_Anim_0b10_D_NonFOV",&animFog);
			if (animDecoy && animFog)
			{
				Array2D<int> *grid = &cmapAnim_world->unknown69c;
				for (int x = 0, ox = x - offset.x; x < getWidth(); x++, ox++)
				{
					for (int yP = 0, my = yP - offset.y; yP < getHeight(); yP++, my++)
					{
						if (!grid->inBounds(ox,my) || (*grid)(ox,my) == 0)
							cmapAnim_engine->unknown50fb50(cmapAnim_engine,animFog,Pos(x,yP),cmapAnim_cfbec0,0,0,9)->unknown50de10();
					}
				}
				for (int i = 0, maxY = getHeight() - 1; i < getWidth(); i++)
					cmapAnim_engine->unknown50fb50(cmapAnim_engine,animDecoy,Pos(i,0),cmapAnim_cfbec0,&Pos(i,maxY),&cmapAnim_cfbec0,9)->unknown50de10();
			}
			mode = 0;
			break;
		}
		case 32:
		{
			sound = 0x4a;
			int anim = 0;
			OpU8a_lookup1("CMap_Anim_Zeronet_Line",&anim);
			const int spacing = 15;
			Area rect;
			unknown8051f0(&rect.min,&rect.max);
			for (int x = rect.min.x; x <= rect.max.x; x++)
			{
				if (x % spacing == 0)
				{
					for (int y = rect.min.y; y <= rect.max.y; y++)
						cmapAnim_engine->unknown50fb50(cmapAnim_engine,anim,Pos(x + unknown6c.x,y + unknown6c.y),cmapAnim_cfbec0,0,0,9)->unknown50de10();
				}
			}
			for (int y = rect.min.y; y <= rect.max.y; y++)
			{
				if (y % spacing == 0)
				{
					for (int x = rect.min.x; x <= rect.max.x; x++)
						cmapAnim_engine->unknown50fb50(cmapAnim_engine,anim,Pos(x + unknown6c.x,y + unknown6c.y),cmapAnim_cfbec0,0,0,9)->unknown50de10();
				}
			}
			for (int x = 0; x < cmapAnim_cells.getWidth(); x += spacing)
			{
				for (int y = 0; y < cmapAnim_cells.getHeight(); y += spacing)
				{
					Area box(x + 1,y + 1,x + 14,y + 14);
					if (rect.touches_40baa0(box))
					{
						box.clip_40bc40(rect.min,rect.max);
						box.offset_40bdd0(offset);
						boxes.push_back(box);
						boxTimes.push_back(rng.rangeInt(50.0,500.0) + cmapAnim_tickCount);
					}
				}
			}
			break;
		}
		case 3:
			radius = cmapAnim_world->player->unknown5c7d80(NULL);
			sound = 0x48;
			goto scan;
		case 4:
			radius = cmapAnim_world->player->unknown5c7d80(NULL);
			sound = 0x46;
			goto scan;
		case 5:
			radius = cmapAnim_world->player->unknown5d22a0(0xe);
			sound = 0x49;
			goto scan;
		case 7:
		{
			radius = cmapAnim_world->player->unknown45a3c0();
			sound = 0x4c;
		scan:
			if (radius == 0)
			{
				mode = 0;
				break;
			}
			int anim3 = 0;
			switch (mode)
			{
				case 3:
				{
					int level = OpX5_maxInt(cmapAnim_world->player->unknown5d2380(0xd).isValid() ? 4 : 0,cmapAnim_world->player->unknown5d22a0(0xc));
					OpU8a_lookup1("CMap_Anim_Ent_Detail_" + intToString(level),&anim3);
					break;
				}
				case 4:
					OpU8a_lookup1("CMap_Anim_Ent_All",&anim3);
					break;
				case 5:
					OpU8a_lookup1("CMap_Anim_Ent_IFF",&anim3);
					break;
				case 7:
				{
					int density = cmapAnim_world->player->unknown5c7e40();
					string tier = density < 100 ? "Low" : (density < 200 ? "Med" : "High");
					OpU8a_lookup1("CMap_Anim_Terr_Dense_" + tier,&anim3);
					break;
				}
			}
			if (anim3 == 0)
			{
				mode = 0;
				break;
			}
			Pos low;
			Pos high;
			cmapAnim_cells.getBounds(center,radius,low,high);
			Pos view0;
			Pos viewMax;
			unknown8051f0(&view0,&viewMax);
			if (low.x < view0.x)
				low.x = view0.x;
			if (low.y < view0.y)
				low.y = view0.y;
			if (high.x > viewMax.x)
				high.x = viewMax.x;
			if (high.y > viewMax.y)
				high.y = viewMax.y;
			if (mode == 5)
			{
				for (int x = low.x, cx = low.x + offset.x; x <= high.x; x++, cx++)
				{
					for (int y = low.y, cy = low.y + offset.y; y <= high.y; y++, cy++)
					{
						if (!cmapAnim_world->isVisible_463190(x,y) && opw8_distance(center.x,center.y,x,y) <= radius)
							cmapAnim_engine->unknown50fb50(cmapAnim_engine,anim3,Pos(cx,cy),cmapAnim_cfbec0,0,0,9)->unknown50de10();
					}
				}
			}
			else
			{
				for (int x = low.x, cx = low.x + offset.x; x <= high.x; x++, cx++)
				{
					for (int y = low.y, cy = low.y + offset.y; y <= high.y; y++, cy++)
					{
						if (cmapAnim_world->unknown674(x,y) && opw8_distance(center.x,center.y,x,y) <= radius)
							cmapAnim_engine->unknown50fb50(cmapAnim_engine,anim3,Pos(cx,cy),cmapAnim_cfbec0,0,0,9)->unknown50de10();
					}
				}
			}
			if (mode == 3 || mode == 4)
			{
				int labelType = mode == 3 ? 1 : 2;
				vector<int> ranksPos(3u,0);
				vector<string> names2(3);
				int rel2;
				if (mode == 3)
				{
					names2[0] = "A_CMap_S_Ent_Detail_Hostile";
					names2[1] = "A_CMap_S_Ent_Detail_Neutral";
					names2[2] = "A_CMap_S_Ent_Detail_Friendly";
				}
				else
				{
					names2[0] = "A_CMap_S_Ent_All_Hostile";
					names2[1] = "A_CMap_S_Ent_All_Neutral";
					names2[2] = "A_CMap_S_Ent_All_Friendly";
				}
				for (int x = low.x, cx = low.x + offset.x; x <= high.x; x++, cx++)
				{
					for (int y = low.y, cy = low.y + offset.y; y <= high.y; y++, cy++)
					{
						if (cmapAnim_cells(x,y)->getEntity().isValid() && cmapAnim_cells(x,y)->getEntity() != cmapAnim_world->player && cmapAnim_world->unknown4631f0(cmapAnim_cells(x,y)->getEntity()) && OpQ1_distanceCeil_40a3f0(center,Pos(x,y)) <= radius && !hasEntityLabel(labelType,cmapAnim_cells(x,y)->getEntity()))
						{
							rel2 = cmapAnim_world->player->unknown5c7fc0(cmapAnim_cells(x,y)->getEntity());
							if (ranksPos[rel2] == 0)
								OpU8a_lookup1(names2[rel2],&ranksPos[rel2]);
							labels.push_back(new XTimerI(labelType,mode == 3 ? new Console(cmapAnim_mapConsole,5,3,x + offset.x,y + offset.y,cmapAnim_asciiEnabled != 0,false,-1) : new Console(cmapAnim_mapConsole,1,1,x + offset.x,y + offset.y,(cmapAnim_asciiEnabled != 0) + 2,false,-1),true,cmapAnim_tickCount + 1000,mode == 3 ? (const PosB&)Pos(-1,-1) : (const PosB&)Pos(0),HProp().ID,HProp().ID,HProp().ID,(const PosB&)Pos(x,y)));
							labels.back()->console->resetBack_418450();
							if (ranksPos[rel2] != 0)
								labels.back()->console->unknown48c3c0(ranksPos[rel2]);
						}
					}
				}
				if (OpX5_maxInt(cmapAnim_world->player->unknown5d2380(0xd).isValid() ? 4 : 0,cmapAnim_world->player->unknown5d22a0(0xc)) >= 2)
				{
					for (int x = low.x, cx = low.x + offset.x; x <= high.x; x++, cx++)
					{
						for (int y = low.y, cy = low.y + offset.y; y <= high.y; y++, cy++)
						{
							if (cmapAnim_world->scans(x,y).turn == cmapAnim_world->scanTurn && cmapAnim_world->scans(x,y).entity.operator->() != NULL && OpQ1_distanceCeil_40a3f0(center,Pos(x,y)) <= radius && !hasEntityLabel(labelType,cmapAnim_world->scans(x,y).entity))
							{
								rel2 = cmapAnim_world->player->unknown5c7fc0(cmapAnim_world->scans(x,y).entity);
								if (ranksPos[rel2] == 0)
									OpU8a_lookup1(names2[rel2],&ranksPos[rel2]);
								labels.push_back(new XTimerI(labelType,mode == 3 ? new Console(cmapAnim_mapConsole,5,3,x + offset.x,y + offset.y,cmapAnim_asciiEnabled != 0,false,-1) : new Console(cmapAnim_mapConsole,1,1,x + offset.x,y + offset.y,(cmapAnim_asciiEnabled != 0) + 2,false,-1),true,cmapAnim_tickCount + 1000,mode == 3 ? (const PosB&)Pos(-1,-1) : (const PosB&)Pos(0),cmapAnim_world->scans(x,y).entity.ID,HProp().ID,HProp().ID,(const PosB&)Pos(0,0)));
								labels.back()->console->resetBack_418450();
								if (ranksPos[rel2] != 0)
									labels.back()->console->unknown48c3c0(ranksPos[rel2]);
								labels.back()->unknown31 = true;
							}
						}
					}
				}
			}
			else if (mode == 5)
			{
				OpU8a_lookup1("CMap_Anim_Ent_IFF_Edge",&anim3);
				unknown808510(center + offset,radius,points);
				for (unsigned int i = 0; i < points.size(); i++)
				{
					if (inBounds(points[i]))
						cmapAnim_engine->unknown50fb50(cmapAnim_engine,anim3,points[i],cmapAnim_cfbec0,0,0,9)->unknown50de10();
				}
				points.clear();
				int animMC;
				OpU8a_lookup1("CMap_Anim_Ent_IFF_MC",&animMC);
				int animNMCPos;
				OpU8a_lookup1("CMap_Anim_Ent_IFF_NMC",&animNMCPos);
				vector<Point> allies(cmapAnim_d35860);
				int count2 = allies.size();
				OpQ5_appendVector(allies,cmapAnim_d1daec);
				for (int i = 0; i < allies.size(); i++)
				{
					labels.push_back(new XTimerI(0xe,new Console(cmapAnim_mapConsole,1,1,allies[i].x + offset.x,allies[i].y + offset.y,(cmapAnim_asciiEnabled != 0) + 2,false,-1),true,cmapAnim_tickCount + 600,(const PosB&)Pos(0),HProp().ID,HProp().ID,HProp().ID,(const PosB&)allies[i]));
					labels.back()->console->unknown48c3c0(i < count2 ? animMC : animNMCPos);
				}
			}
			if (mode != 4)
				mode = 0;
			break;
		}
		case 10:
			sound = 0x4f;
			break;
		case 11:
			sound = 0x50;
			break;
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		{
			radius = cmapAnim_world->player->unknown5c7d30();
			int anim = 0;
			string textVal;
			switch (mode)
			{
				case 13:
					textVal = "          ";
					OpU8a_lookup1("A_CMap_Triangulate",&anim);
					sound = 0x52;
					break;
				case 14:
					textVal = intToString(cmapAnim_world->player->unknown5d7b00(false));
					OpU8a_lookup1("A_CMap_Label_Target_Hit_Chance",&anim);
					break;
				case 15:
					textVal = intToString(cmapAnim_world->player->unknown5d2090(0x5a));
					OpU8a_lookup1("A_CMap_Label_Target_Melee_Accuracy",&anim);
					break;
				case 16:
					textVal = intToString(cmapAnim_world->player->unknown5d2150(0x6a,0) / 5);
					OpU8a_lookup1("A_CMap_Label_Target_Melee_Accuracy",&anim);
					break;
				case 17:
					textVal = intToString(cmapAnim_world->player->unknown5d2090(0x5d));
					OpU8a_lookup1("A_CMap_Label_Target_Launcher_Accuracy",&anim);
					break;
				case 18:
					textVal = intToString(cmapAnim_world->player->unknown5d22a0(0x5e));
					OpU8a_lookup1("A_CMap_Label_Target_Weapon_Accuracy",&anim);
					break;
				case 19:
					textVal = intToString(cmapAnim_world->player->unknown5d2150(0x5f,0));
					OpU8a_lookup1("A_CMap_Label_Target_Critical",&anim);
					break;
				case 20:
					textVal = intToString(OpX5_maxInt(cmapAnim_world->player->unknown5d2150(0x60,0),cmapAnim_world->player->unknown5d22a0(0x61)));
					OpU8a_lookup1("A_CMap_Label_Target_Core_Exposure",&anim);
					break;
			}
			if (anim == 0)
				break;
			if (mode != 13)
			{
				if (mode != 16)
					textVal.insert(0,"[+");
				else
					textVal.insert(0,"[-");
				textVal += "%]";
			}
			Pos min;
			Pos high;
			cmapAnim_cells.getBounds(center,radius,min,high);
			for (int x = min.x, cx = min.x + offset.x; x <= high.x; x++, cx++)
			{
				for (int y = min.y, cy = min.y + offset.y; y <= high.y; y++, cy++)
				{
					if (cmapAnim_cells(x,y)->getEntity().isValid() && cmapAnim_world->unknown463380(x,y) && (mode == 13 ? cmapAnim_world->player->unknown5c7fc0(cmapAnim_cells(x,y)->getEntity()) == 0 : cmapAnim_world->player->unknown5c7fc0(cmapAnim_cells(x,y)->getEntity()) != 2) && (mode != 13 || cmapAnim_cells(x,y)->getEntity()->getTarget() == 0) && !hasEntityLabel(0xd,cmapAnim_cells(x,y)->getEntity()))
					{
						labels.push_back(new XTimerI(0xd,new Console(cmapAnim_mapConsole,textVal.size(),1,cx,cy,cmapAnim_asciiEnabled != 0,false,-1),true,(mode == 13 ? 1075 : 2000) + cmapAnim_tickCount,mode == 13 ? (const PosB&)Pos(1,0) : (const PosB&)Pos(-1,1),cmapAnim_cells(x,y)->getEntity().ID,HProp().ID,HProp().ID,(const PosB&)Pos(cmapAnim_cells(x,y)->getEntity()->getSize() / 2,cmapAnim_cells(x,y)->getEntity()->getSize() - 1)));
						labels.back()->console->print(0,0,textVal);
						labels.back()->console->unknown48c3c0(anim);
						paths.push_back(vector<Point>());
						steps.push_back(vector<int>());
						float speed = 10.0f;
						traceSubcellLine(center,Pos(x,y),paths.back(),steps.back(),(int)speed);
					}
				}
			}
			break;
		}
		case 21:
		case 22:
		case 23:
		case 24:
		{
			sound = mode == 21 ? 0x57 : (mode == 22 ? 0x59 : 0x58);
			int anim = 0;
			OpU8a_lookup1(mode == 21 ? "CMap_Anim_Shield_TH" : (mode == 22 ? "CMap_Anim_Shield_Corr" : (mode == 23 ? "CMap_Anim_Shield_25" : "CMap_Anim_Shield_50")),&anim);
			if (anim)
			{
				radius = mode == 21 ? 10 : (mode == 22 ? 10 : 10);
				Pos low;
				Pos max;
				Pos pos = center + offset;
				getBuffer_4184d0()->getBounds(pos,radius,low,max);
				for (int x = low.x; x <= max.x; x++)
				{
					for (int y = low.y; y <= max.y; y++)
					{
						if (opw8_distance(pos.x,pos.y,x,y) <= radius)
							cmapAnim_engine->unknown50fb50(cmapAnim_engine,anim,Pos(x,y),cmapAnim_cfbec0,0,0,9)->unknown50de10();
					}
				}
			}
			break;
		}
		case 33:
		{
			radius = cmapAnim_world->player->unknown5d22a0(0xba);
			sound = 0x4c;
			if (radius == 0)
			{
				mode = 0;
				break;
			}
			int animFloorCur = 0;
			int animHostileId = 0;
			int animFriendly = 0;
			OpU8a_lookup1("CMap_Anim_Hacktrap_Fl",&animFloorCur);
			OpU8a_lookup1("CMap_Anim_Hacktrap_Hstl",&animHostileId);
			OpU8a_lookup1("CMap_Anim_Hacktrap_Frnd",&animFriendly);
			if (animFloorCur == 0)
			{
				mode = 0;
				break;
			}
			Pos min;
			Pos high;
			cmapAnim_cells.getBounds(center,radius,min,high);
			Pos view0;
			Pos vMax2;
			unknown8051f0(&view0,&vMax2);
			if (min.x < view0.x)
				min.x = view0.x;
			if (min.y < view0.y)
				min.y = view0.y;
			if (high.x > vMax2.x)
				high.x = vMax2.x;
			if (high.y > vMax2.y)
				high.y = vMax2.y;
			int groupTypePos = cmapAnim_world->player->getGroup()->getType();
			vector<Point> doors;
			vector<Point> trapsVal;
			for (int x = min.x, cx = min.x + offset.x; x <= high.x; x++, cx++)
			{
				for (int y = min.y, cy = min.y + offset.y; y <= high.y; y++, cy++)
				{
					if (cmapAnim_world->unknown463380(x,y) && opw8_distance(center.x,center.y,x,y) <= radius)
					{
						if (cmapAnim_cells(x,y)->isDoor())
						{
							if (cmapAnim_cells(x,y)->getProp()->unknown44b020()->unknown65cf50(groupTypePos))
								cmapAnim_engine->unknown50fb50(cmapAnim_engine,animHostileId,Pos(cx,cy),cmapAnim_cfbec0,0,0,9)->unknown50de10();
							else
								cmapAnim_engine->unknown50fb50(cmapAnim_engine,animFriendly,Pos(cx,cy),cmapAnim_cfbec0,0,0,9)->unknown50de10();
						}
						else if (cmapAnim_cells(x,y)->unknown66b5b0() && !cmapAnim_cells(x,y)->unknown45db70())
							cmapAnim_engine->unknown50fb50(cmapAnim_engine,animFloorCur,Pos(cx,cy),cmapAnim_cfbec0,0,0,9)->unknown50de10();
					}
				}
			}
			mode = 0;
			break;
		}
		case 34:
		{
			sound = 0x5b;
			int range = cmapAnim_world->getMaxItemRange71c930();
			vector<int> anims(range + 1,0);
			for (int i = 0; i <= range; i++)
				OpU8a_lookup1("CMap_Anim_Gen_Stasis_" + intToString(i),&anims[i]);
			Area areaCur;
			int distP;
			cmapAnim_cells.getRect(cmapAnim_world->player->getPosition(),range,areaCur);
			for (int x = areaCur.min.x; x <= areaCur.max.x; x++)
			{
				for (int y = areaCur.min.y; y <= areaCur.max.y; y++)
				{
					distP = OpQ1_distanceCeil_40a3f0(cmapAnim_world->player->getPosition(),Pos(x,y));
					if (distP <= range && cmapAnim_world->isVisible_463190(x,y))
						cmapAnim_engine->unknown50fb50(cmapAnim_engine,anims[distP],Pos(x + unknown6c.x,y + unknown6c.y),cmapAnim_cfbec0,0,0,9)->unknown50de10();
				}
			}
			break;
		}
		case 36:
			radius = cmapAnim_world->player->unknown5d24e0(0xc9)->unknown457fb0();
			sound = 0x44;
			break;
		case 37:
			radius = cmapAnim_world->player->unknown5d24e0(0xb0)->unknown457fb0();
			sound = 0x101;
			break;
		case 38:
			radius = cmapAnim_world->player->unknown5d24e0(0xb1)->unknown457fb0();
			sound = 0x11b;
			break;
		case 8:
			radius = cmapAnim_world->player->unknown5d22a0(0x12);
			sound = 0x4d;
			break;
		case 12:
		{
			vector<CmapAnim_Conduit *> previous2(conduits);
			conduits.clear();
			Array2D<int> *gridTmp = &cmapAnim_world->unknown69c;
			vector<CmapAnim_Conduit *> linked;
			vector<int> indicesVal;
			int index;
			for (int x = 0, ox = x - offset.x; x < getWidth(); x++, ox++)
			{
				for (int yP = 0, my = yP - offset.y; yP < getHeight(); yP++, my++)
				{
					if (gridTmp->inBounds(ox,my) && (*gridTmp)(ox,my) != 0 && cmapAnim_cells(ox,my)->getProp().isValid())
					{
						index = cmapAnim_cells(ox,my)->getProp()->unknown457af0();
						if (index != -1 && !cmapAnim_containsInt_9db330(indicesVal,index))
						{
							indicesVal.push_back(index);
							linked.push_back(cmapAnim_d39f1c[index]);
							if (!linked.back()->unknown6c1320())
								linked.pop_back();
						}
					}
				}
			}
			BS::opw3_unknown72c080(linked,true,HEntity());
			if (conduits.empty())
				conduits = previous2;
			else
				OpQ5_clearObjects(previous2);
			sound = 0x51;
			break;
		}
		case 35:
		{
			radius = cmapAnim_world->player->unknown5c7d30();
			vector<int> anims(4u,0);
			for (int i = 0; i < 4; i++)
				OpU8a_lookup1("A_CMap_Label_Target_Borg_Assim_" + intToString(i),&anims[i]);
			int anim2 = 0;
			string label;
			Pos min;
			Pos bottomRight;
			cmapAnim_cells.getBounds(center,radius,min,bottomRight);
			for (int x = min.x, cx = min.x + offset.x; x <= bottomRight.x; x++, cx++)
			{
				for (int y = min.y, cy = min.y + offset.y; y <= bottomRight.y; y++, cy++)
				{
					if (cmapAnim_cells(x,y)->getEntity().isValid() && cmapAnim_world->unknown463380(x,y) && cmapAnim_world->player->unknown5c7fc0(cmapAnim_cells(x,y)->getEntity()) != 2 && !hasEntityLabel(0xd,cmapAnim_cells(x,y)->getEntity()))
					{
						string reason;
						int chance = ops7_clamp_9cdc80(0,cmapAnim_world->unknown7163a0(cmapAnim_cells(x,y)->getEntity()),100);
						if (!cmapAnim_world->unknown716250(cmapAnim_cells(x,y)->getEntity(),chance,&reason))
						{
							if (reason.find("rating") != string::npos)
							{
								label = "[  0%]";
								anim2 = anims[0];
							}
							else
							{
								label = "[N/A]";
								anim2 = anims[0];
							}
						}
						else
						{
							label = "[" + padLeft_408090(intToString(chance),3,' ') + "%]";
							anim2 = anims[opr1c_getPercentTier(chance,100)];
						}
						labels.push_back(new XTimerI(0xd,new Console(cmapAnim_mapConsole,label.size(),1,cx,cy,cmapAnim_asciiEnabled != 0,false,-1),true,cmapAnim_tickCount + 2000,(const PosB&)Pos(-1,1),cmapAnim_cells(x,y)->getEntity().ID,HProp().ID,HProp().ID,(const PosB&)Pos(cmapAnim_cells(x,y)->getEntity()->getSize() / 2,cmapAnim_cells(x,y)->getEntity()->getSize() - 1)));
						labels.back()->console->print(0,0,label);
						labels.back()->console->unknown48c3c0(anim2);
					}
				}
			}
			break;
		}
	}
	if (sound)
		opR1d_4541b0(sound,0,0);
	return sound;
}
