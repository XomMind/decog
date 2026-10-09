// op_w7_df: DF map generator builders (DF::Tunneler/DF::Roomie helpers, 0x4b9a30-0x4c3xxx), Beta 17.1.
// NOTE: the DF classes themselves live in src/dungeon/df.h; to avoid symbol clashes these
//	reconstructions use OpW7_ placeholder classes with the same layout.
#include <string>
#include <vector>
#include <istream>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos();	// 0x453b40
	Pos(int value);	// NOTE: placeholder name (0x409990)
	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos(const Pos &pos, int dx, int dy);	// 0x4099c0
	void set(int x_, int y_);	// NOTE: placeholder name (0x40a010)
	Pos &operator=(const Pos &pos);	// 0x46ca50
	bool equals_409cb0(int x_, int y_);	// NOTE: placeholder name
	bool differs_409cf0(int x_, int y_);	// NOTE: placeholder name
	bool operator!=(const Pos &pos) const;	// 0x409bd0
	Pos &add_409a30(const Pos &pos);	// NOTE: placeholder name
	Pos &sub_409a70(const Pos &pos);	// NOTE: placeholder name
	Pos minus_409b30(const Pos &pos);	// NOTE: placeholder name
	void setBoth_409ff0(int value);	// NOTE: placeholder name
	void set_40a030(const Pos &pos);	// NOTE: placeholder name
	bool less_409c10(const Pos &pos);	// NOTE: placeholder name
	bool greater_409c60(const Pos &pos);	// NOTE: placeholder name
};

// a Pos-shaped temporary that the original never default-constructed
struct OpW7_RawPos	// NOTE: placeholder name
{
	int x;
	int y;

	OpW7_RawPos &operator=(const Pos &pos);	// 0x46ca50
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect();
	Rect(int x_, int y_, int width_, int height_);	// 0x456940
	Rect(const Rect &rect);
	Rect &operator=(const Rect &rect);	// NOTE: folded with the copy ctor (0x40a720)
	void set(int x_, int y_, int width_, int height_);	// NOTE: placeholder name (0x40a840)
	int area_40ad00();	// NOTE: placeholder name
	void set_40a870(const Pos &pos, int width_, int height_);	// NOTE: placeholder name
	Pos topLeft_40a970();	// NOTE: placeholder name
	Pos topRight_40ac60();	// NOTE: placeholder name
	Pos bottomRight_40acc0();	// NOTE: placeholder name
	Pos bottomLeft_40ac90();	// NOTE: placeholder name
	bool contains(int x_, int y_) const;	// NOTE: placeholder name (0x40a9a0)
	bool equals_40a7e0(const Rect &other);	// NOTE: placeholder name
	bool containsRect_40aa70(const Rect &other);	// NOTE: placeholder name
	void intersect_40ab30(const Rect &other, Rect &out);	// NOTE: placeholder name
	bool touches_40aef0(const Rect &other);	// NOTE: placeholder name
	bool containsPos_40aa00(const Pos &pos);	// NOTE: placeholder name
	int distance_40ae20(const Rect &other);	// NOTE: placeholder name
	int right_40ac20();	// NOTE: placeholder name
	int bottom_40ac40();	// NOTE: placeholder name
};

struct OpW7_Corridor	// NOTE: placeholder name
{
	Rect rect;
	int unknown10;	// NOTE: placeholder name
	vector<int> unknown14;	// NOTE: placeholder name
};
extern vector<OpW7_Corridor> opw7_corridors;	// NOTE: placeholder name (0xd1f31c)

void OpB_translateRotated(Pos *pos, int rotation, int dx, int dy);	// NOTE: placeholder name

class OpW7_CellMap	// NOTE: placeholder name (object at 0xcf1964)
{
public:
	bool contains(const Pos &pos);	// NOTE: placeholder name (0x9b43b0)
	int &operator[](const Pos &pos);	// NOTE: placeholder name (0x9ced70)
};
extern OpW7_CellMap opw7_cells;	// NOTE: placeholder name

class OpW7_Builder	// NOTE: placeholder name (DF::Builder)
{
public:
	OpW7_Builder(int delay_, int dir_, const Pos &pos_);	// 0x447e50
	virtual ~OpW7_Builder();	// 0x447ea0

	int delay;
	int age;
	int dir;
	Pos pos;
};

// defined here so that LTCG knows these constructors cannot throw (callers keep the new-expression temp but no EH state)
OpW7_Builder::OpW7_Builder(int delay_, int dir_, const Pos &pos_) : delay(delay_), age(0), dir(dir_), pos(pos_)
{
}

class OpW7_Tunneler : public OpW7_Builder	// NOTE: placeholder name (DF::Tunneler)
{
public:
	virtual ~OpW7_Tunneler();
	int measure(const Pos &start, int dir, int margin, int extra, int lookahead);	// NOTE: placeholder name
	bool dig(int type, int length, int margin, int extra, int lookahead);	// NOTE: placeholder name
	void load(istream &in);	// NOTE: placeholder name (0x447fc0)
	int build();	// NOTE: placeholder name
	void spawn(int roomType);	// NOTE: placeholder name (0x4bb040)
	OpW7_Tunneler(int delay_, int dir_, const Pos &pos_, int param1C_, int width_, int param24_, int param28_, int param2C_, int param30_, int param34_, int param38_, int param3C_, bool param40_);	// 0x447f10

	int startDir;
	int param1C;
	int width;
	int param24;
	int param28;
	int param2C;
	int param30;
	int param34;
	int param38;
	int param3C;
	bool param40;
};

OpW7_Tunneler::OpW7_Tunneler(int delay_, int dir_, const Pos &pos_, int param1C_, int width_, int param24_, int param28_, int param2C_, int param30_, int param34_, int param38_, int param3C_, bool param40_) : OpW7_Builder(delay_,dir_,pos_), startDir(dir_), param1C(param1C_), width(width_), param24(param24_), param28(param28_), param2C(param2C_), param30(param30_), param34(param34_), param38(param38_), param3C(param3C_), param40(param40_)
{
}

int OpW7_Tunneler::measure(const Pos &start, int dir, int margin, int extra, int lookahead)
{
	int result = -1;
	int length = 0;
	Pos pos;
	if (margin)
	{
		for (int i = -extra - margin; i < width + margin + extra; i++)
		{
			pos = start;
			OpB_translateRotated(&pos,dir,i,0);
			if ((i <= -margin || i >= width) && (!opw7_cells.contains(pos) || opw7_cells[pos] > 3))
				return 0;
		}
	}
	while (result == -1)
	{
		length++;
		for (int j = -extra - margin; j < width + margin + extra; j++)
		{
			pos = start;
			OpB_translateRotated(&pos,dir,j,length);
			if (!opw7_cells.contains(pos) || ((j < -margin || j >= width + margin) && opw7_cells[pos] > 3) || (j >= -margin && j < width + margin && opw7_cells[pos] != 3))
			{
				result = length - 1;
				if (result > 0)
				{
					for (int k = 1; k <= lookahead; k++)
					{
						for (int m = -extra - margin; m < width + margin + extra; m++)
						{
							pos = start;
							OpB_translateRotated(&pos,dir,m,result + k);
							if (!opw7_cells.contains(pos) || opw7_cells[pos] > 3)
							{
								result -= lookahead - k + 1;
								goto done;
							}
						}
					}
				}
done:
				break;
			}
		}
	}
	return result;
}

bool OpW7_Tunneler::dig(int type, int length, int margin, int extra, int lookahead)
{
	int available = measure(pos,dir,margin,extra,lookahead);
	if (available < length)
		return false;
	Pos cell;
	for (int i = 1; i <= length; i++)
	{
		for (int j = -margin; j < width + margin; j++)
		{
			cell = pos;
			OpB_translateRotated(&cell,dir,j,i);
			opw7_cells[cell] = type;
		}
	}
	if (type == 5)
	{
		OpW7_Corridor newCorridor;
		opw7_corridors.push_back(newCorridor);
		OpW7_Corridor *cor = &opw7_corridors.back();
		cor->unknown10 = 0;
		OpW7_RawPos corner;
		corner = pos;
		OpB_translateRotated((Pos*)&corner,dir,-margin,1);
		int w = width + margin * 2;
		int len = length;
		switch (dir)
		{
			case 0: cor->rect.set(corner.x,corner.y - len + 1,w,len); break;
			case 1: cor->rect.set(corner.x,corner.y,len,w); break;
			case 2: cor->rect.set(corner.x - w + 1,corner.y,w,len); break;
			case 3: cor->rect.set(corner.x - len + 1,corner.y - w + 1,len,w); break;
		}
	}
	return true;
}

class OpW7_Roomie : public OpW7_Builder	// NOTE: placeholder name (DF::Roomie)
{
public:
	OpW7_Roomie(int delay_, int dir_, const Pos &pos_, int roomType_, int param1C_);	// 0x4480d0
	virtual ~OpW7_Roomie();
	int measure(const Pos &origin, int width, int *left, int *right, int margin);	// NOTE: placeholder name
	int build();	// NOTE: placeholder name

	int roomType;
	int param1C;
};

OpW7_Roomie::OpW7_Roomie(int delay_, int dir_, const Pos &pos_, int roomType_, int param1C_) : OpW7_Builder(delay_,dir_,pos_), roomType(roomType_), param1C(param1C_)
{
}

int OpW7_Roomie::measure(const Pos &origin, int width, int *left, int *right, int margin)
{
	Pos from = origin;
	OpB_translateRotated(&from,dir,0,1);
	int result = -1;
	int length = -1;
	Pos at;
	while (result == -1)
	{
		length++;
		for (int i = -margin - width / 2; i < width / 2 + margin; i++)
		{
			at = from;
			OpB_translateRotated(&at,dir,i,length);
			if (!opw7_cells.contains(at) || ((i < -width / 2 || i >= width / 2) && opw7_cells[at] > 3) || (i >= -width / 2 && i < width / 2 && opw7_cells[at] != 3))
			{
				if ((result = length - 1) < 0)
					return 0;
				if (result > 0)
				{
					for (int k = 1; k <= margin; k++)
					{
						for (int m = -margin - width / 2; m <= width / 2 + margin; m++)
						{
							at = from;
							OpB_translateRotated(&at,dir,m,result + k);
							if (!opw7_cells.contains(at) || opw7_cells[at] > 3)
							{
								result -= margin - k + 1;
								goto lookaheadDone;
							}
						}
					}
				}
lookaheadDone:
				if (result > 0)
				{
					bool finished = false;
					length = 0;
					while (!finished)
					{
						length++;
						for (int a = 0; a <= result + margin; a++)
						{
							at = from;
							OpB_translateRotated(&at,dir,-length,a);
							if (!opw7_cells.contains(at) || (a > result && opw7_cells[at] > 3) || (a <= result && opw7_cells[at] != 3))
							{
								*left = length - 1;
								if (*left >= 0)
								{
									for (int b = 1; b <= margin; b++)
									{
										for (int c = 0; c <= result + margin; c++)
										{
											at = from;
											OpB_translateRotated(&at,dir,-*left - b,c);
											if (!opw7_cells.contains(at) || opw7_cells[at] > 3)
											{
												*left -= margin - b + 1;
												goto leftDone;
											}
										}
									}
								}
leftDone:
								finished = true;
								break;
							}
						}
					}
					finished = false;
					length = 0;
					while (!finished)
					{
						length++;
						for (int a = 0; a <= result + margin; a++)
						{
							at = from;
							OpB_translateRotated(&at,dir,length,a);
							if (!opw7_cells.contains(at) || (a > result && opw7_cells[at] > 3) || (a <= result && opw7_cells[at] != 3))
							{
								*right = length - 1;
								if (*right >= 0)
								{
									for (int b = 1; b <= margin; b++)
									{
										for (int c = 0; c <= result + margin; c++)
										{
											at = from;
											OpB_translateRotated(&at,dir,*right + b,c);
											if (!opw7_cells.contains(at) || opw7_cells[at] > 3)
											{
												*right -= margin - b + 1;
												goto rightDone;
											}
										}
									}
								}
rightDone:
								finished = true;
								break;
							}
						}
					}
				}
				break;
			}
		}
	}
	return result;
}

class RNG
{
public:
	bool chance(int percent);
	int rangeInt(float min, float max);
};
extern RNG rng;

int maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)

class OpW7_BoolGrid	// NOTE: placeholder name
{
public:
	OpW7_BoolGrid(int width, int height, bool value);	// NOTE: placeholder name (0x9d2720)
	~OpW7_BoolGrid();	// NOTE: placeholder name (0x9cec20)
	int width;
	int height;
	void *values;
	bool inBounds(int x, int y);	// NOTE: placeholder name (0x9b45c0)
	bool &at(int x, int y);	// NOTE: placeholder name (0x9cec50)
};

class OpW7_Generator	// NOTE: placeholder name (DF::Generator, 0xd31580)
{
public:
	int getRoomCount(int type);	// NOTE: placeholder name (0x448fe0)
	int getTurn();	// NOTE: placeholder name (folded getter)
	void addRoomCount(int type);	// NOTE: placeholder name (0x449040)
	void addBuilder(OpW7_Tunneler *builder);	// NOTE: placeholder name (0x449020)
	void addBuilderBase(OpW7_Builder *builder);	// NOTE: placeholder name (0x449020)
	void floodFill(int x, int y, OpW7_BoolGrid *visited, const Pos &offset, vector<Pos> &cells);	// NOTE: placeholder name
	void placeTunnelers();	// NOTE: placeholder name
	void findCaves();	// NOTE: placeholder name

	int unknown00[0x54 / 4];	// NOTE: placeholder name
	vector<Pos> starts;	// NOTE: placeholder name
	int unknown64[(0x74 - 0x64) / 4];	// NOTE: placeholder name
	int level;	// NOTE: placeholder name
	int unknown78[(0x8c - 0x78) / 4];	// NOTE: placeholder name
	vector<Rect> caves;	// NOTE: placeholder name
	vector<Rect> unknown9c;	// NOTE: placeholder name

	void widenUnknown9c();	// NOTE: placeholder name
	void removeBlockedDoors();	// NOTE: placeholder name
	void addRoomCorridors();	// NOTE: placeholder name
	void finalizeWalls();	// NOTE: placeholder name
	void growUnknown9c();	// NOTE: placeholder name
	bool checkStarts();	// NOTE: placeholder name
	void fitCaves();	// NOTE: placeholder name
	unsigned int traceRooms();	// NOTE: placeholder name
};
extern OpW7_Generator opw7_generator;	// NOTE: placeholder name

struct OpW7_Range8	// NOTE: placeholder name
{
	int min;
	int max;

	int randomInRange_40c130() throw();	// NOTE: placeholder name
	bool contains_40c190(int value);	// NOTE: placeholder name
	void load(istream &in);	// NOTE: placeholder name (0x45f040)
	bool isEmpty();	// NOTE: placeholder name (folded with vector<int>::empty)
};

struct OpW7_RoomSettings	// NOTE: placeholder name
{
	int getWeightA_448390(int width);	// NOTE: placeholder name
	int getWeightB_4483e0(int width);	// NOTE: placeholder name

	int minArea;
	int maxArea;
	int maxCount;
	vector<int> unknown0C;	// NOTE: placeholder name
	vector<int> unknown1C;	// NOTE: placeholder name
	int corridorChance;	// NOTE: placeholder name
	int corridorTries;	// NOTE: placeholder name
	int clearance;	// NOTE: placeholder name
	OpW7_Range8 segmentLength;	// NOTE: placeholder name
	int turns;	// NOTE: placeholder name
};

struct OpW7_Spawn	// NOTE: placeholder name (tunneler spawn settings)
{
	bool enabled;
	int level;
	int unknown08[3];
	OpW7_Range8 delay;
	OpW7_Range8 x;
	OpW7_Range8 y;
	vector<int> dirs;
	OpW7_Range8 param1C;
	OpW7_Range8 width;
	OpW7_Range8 param24;
	OpW7_Range8 param28;
	OpW7_Range8 param2C;
	OpW7_Range8 param30;
	OpW7_Range8 param34;
	OpW7_Range8 param38;
	OpW7_Range8 param3C;
};

int OpW7_randomElement_9d5d00(const vector<int> &v) throw();	// NOTE: placeholder name

class OpW7_WeightTable	// NOTE: placeholder name
{
public:
	OpW7_WeightTable();	// 0x448160
	~OpW7_WeightTable();	// 0x4489f0
	void add(int weight);	// NOTE: placeholder name (0x4481c0)
	int pick();	// NOTE: placeholder name (0x4481f0)

	int total;
	vector<int> weights;
};

struct OpW7_Elem12	// NOTE: placeholder name
{
	int unknown00;	// NOTE: placeholder name
	int unknown04;	// NOTE: placeholder name
	int unknown08;	// NOTE: placeholder name
};

struct OpW7_Settings	// NOTE: placeholder name (DF settings, *0xcefb50)
{
	int vary_4489a0(int value);	// NOTE: placeholder name

	int unknown00;
	int roomMargin;
	float maxRoomRatio;
	int unknown0C;	// NOTE: placeholder name
	int unknown10;	// NOTE: placeholder name
	OpW7_WeightTable unknown14;	// NOTE: placeholder name
	OpW7_WeightTable unknown28;	// NOTE: placeholder name
	OpW7_WeightTable unknown3C;	// NOTE: placeholder name
	int unknown50;	// NOTE: placeholder name
	int unknown54;	// NOTE: placeholder name
	int unknown58[(0x78 - 0x58) / 4];	// NOTE: placeholder name
	int unknown78;	// NOTE: placeholder name (child tunneler width)
	int unknown7C;	// NOTE: placeholder name (child tunneler param24)
	int unknown80;	// NOTE: placeholder name (child tunneler param28)
	int unknown84;	// NOTE: placeholder name (child tunneler param2C)
	int unknown88;	// NOTE: placeholder name (child tunneler param30)
	int unknown8C;	// NOTE: placeholder name (child tunneler param34)
	int unknown90;	// NOTE: placeholder name (child tunneler param38)
	int unknown94;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
	int unknown9C;	// NOTE: placeholder name (child tunneler delay)
	vector<OpW7_Elem12> unknownA0;	// NOTE: placeholder name
	int unknownB0;	// NOTE: placeholder name
	vector<int> unknownB4;	// NOTE: placeholder name
	OpW7_RoomSettings rooms[3];
	int unknown190[(0x1bc - 0x190) / 4];
	vector<struct OpW7_Spawn> spawns;	// NOTE: placeholder name
};
extern OpW7_Settings *opw7_settings;	// NOTE: placeholder name

struct OpW7_Room	// NOTE: placeholder name (DF::Room)
{
	OpW7_Room();	// 0x4bd0f0
	OpW7_Room(const OpW7_Room &room);
	~OpW7_Room();	// 0x4bd140

	int type;
	Rect rect;
	vector<int> unknown14;	// NOTE: placeholder name
	int unknown24;	// NOTE: placeholder name
	vector<Pos> doors;	// NOTE: placeholder name
	vector<int> doorDirs;	// NOTE: placeholder name
	vector<int> corridors;	// NOTE: placeholder name
	int unknown58;	// NOTE: placeholder name
	vector<int> unknown5c;	// NOTE: placeholder name (door corridor lengths)
};
extern vector<OpW7_Room> opw7_rooms;	// NOTE: placeholder name (0xcf13e8)

extern int opw7_bb8340[4];	// NOTE: placeholder name
extern int opw7_bb8350[4];	// NOTE: placeholder name
int OpW7_subtractMin_9d0690(int &value, int amount, int minimum);	// NOTE: placeholder name
int OpW7_pickIndex_9d4b30(bool *values, unsigned int count, bool value);	// NOTE: placeholder name

int OpW7_Tunneler::build()
{
	if (delay > opw7_generator.getTurn())
		return 1;
	age++;
	if (age > param1C)
		return 0;
	OpW7_WeightTable tableAs;
	OpW7_WeightTable tableB5;
	for (int k = 0; k < 3; k++)
	{
		tableAs.add(opw7_settings->rooms[k].getWeightA_448390(width));
		tableB5.add(opw7_settings->rooms[k].getWeightB_4483e0(width));
	}
	int pickAList = tableAs.pick();
	int pickB = tableB5.pick();
	int roomDelay1 = opw7_generator.getTurn() + opw7_settings->unknown14.pick();
	int lengths = measure(pos,dir,0,opw7_settings->unknown00,opw7_settings->unknown00);
	if (lengths == 0)
	{
		if (measure(pos,dir,0,opw7_settings->unknown00,0) > 0)
			spawn(pickAList);
		return 0;
	}
	if (lengths < param24 * 2 || age == param1C - 1)
	{
		spawn(pickAList);
		return 0;
	}
	dig(4,param24,0,opw7_settings->unknown00,opw7_settings->unknown00);
	if (param24 / 2 - 1 >= 1)
	{
		if (rng.chance(param34))
		{
			Pos p = pos;
			OpB_translateRotated(&p,dir,0,param24 / 2 + 1);
			opw7_generator.addBuilderBase(new OpW7_Roomie(roomDelay1,opw7_bb8350[dir],p,pickB,param24 / 2 - 1));
		}
		if (rng.chance(param38))
		{
			Pos p2 = pos;
			OpB_translateRotated(&p2,dir,width - 1,param24 / 2 + 1);
			opw7_generator.addBuilderBase(new OpW7_Roomie(roomDelay1,opw7_bb8340[dir],p2,pickB,param24 / 2 - 1));
		}
	}
	OpB_translateRotated(&pos,dir,0,param24);
	bool canWidens = measure(pos,dir,1,opw7_settings->unknown00,opw7_settings->unknown00) > width * 2 + 5;
	bool wide2s = measure(pos,dir,2,opw7_settings->unknown00,opw7_settings->unknown00) > width * 2 + 7;
	OpW7_Elem12 &elemSet = delay >= opw7_settings->unknownA0.size() ? opw7_settings->unknownA0.back() : opw7_settings->unknownA0[delay];
	int modeList = 0;
	int roll4 = rng.rangeInt(1,100);
	if (roll4 <= elemSet.unknown04)
	{
		if (width >= 3)
			modeList = -2;
	}
	else if (roll4 <= elemSet.unknown04 + elemSet.unknown08)
	{
		if (opw7_settings->unknownB0 == 0 || width + 2 <= opw7_settings->unknownB0)
			modeList = 2;
	}
	if (modeList > 0 && !wide2s)
		return 2;
	bool turnB = rng.chance(param28);
	bool branchVec = rng.chance(turnB ? param30 : param2C);
	if (!turnB && !branchVec)
		return 2;
	bool room6 = branchVec && !rng.chance(opw7_settings->unknown0C);
	int newDelayVec = delay + (modeList <= 0 ? opw7_settings->unknown28.pick() : opw7_settings->unknown3C.pick());
	int v28Ex = opw7_settings->vary_4489a0(param28);
	int v2CVec = opw7_settings->vary_4489a0(param2C);
	int chanceTurnBranchSet = opw7_settings->vary_4489a0(param30);
	int v34 = opw7_settings->vary_4489a0(param34);
	int v38Ex = opw7_settings->vary_4489a0(param38);
	int v3C = opw7_settings->vary_4489a0(param3C);
	Pos startsEx[3] = {pos,pos,pos};
	int dirs2[3] = {dir,opw7_bb8350[dir],opw7_bb8340[dir]};
	bool usedList[3] = {false,false,false};
	bool dug = false;
	if (modeList > 0)
	{
		if (branchVec || rng.chance(width >= opw7_settings->unknownB4.size() ? opw7_settings->unknownB4.back() : opw7_settings->unknownB4[width]))
		{
			int extra = 2;
			int len = width + extra * 2;
			dug = dig(5,len,extra,opw7_settings->unknown00,opw7_settings->unknown00);
			OpB_translateRotated(&startsEx[0],dir,0,len);
			OpB_translateRotated(&startsEx[1],dir,-extra,extra + 1);
			OpB_translateRotated(&startsEx[2],dir,width + extra - 1,len - extra);
		}
	}
	else if (canWidens)
	{
		if (rng.chance(width >= opw7_settings->unknownB4.size() ? opw7_settings->unknownB4.back() : opw7_settings->unknownB4[width]))
		{
			int extra = 1;
			int len = width + extra * 2;
			dug = dig(5,len,extra,opw7_settings->unknown00,opw7_settings->unknown00);
			OpB_translateRotated(&startsEx[0],dir,0,len);
			OpB_translateRotated(&startsEx[1],dir,-extra,extra + 1);
			OpB_translateRotated(&startsEx[2],dir,width + extra - 1,len - extra);
		}
	}
	if (!dug)
	{
		OpB_translateRotated(&startsEx[1],dir,0,-width + 1);
		OpB_translateRotated(&startsEx[2],dir,width - 1,0);
		if (opw7_cells[startsEx[1]] != 4 || opw7_cells[startsEx[2]] != 4)
			return 2;
	}
	int curDirA = dir;
	if (turnB)
	{
		int lenL = measure(startsEx[1],opw7_bb8350[curDirA],0,opw7_settings->unknown00,opw7_settings->unknown00);
		int lenR = measure(startsEx[2],opw7_bb8340[curDirA],0,opw7_settings->unknown00,opw7_settings->unknown00);
		int choice = 0;
		if (curDirA != startDir)
		{
			if (opw7_bb8350[curDirA] == startDir)
				choice = 1;
			else
				choice = 2;
		}
		else if (branchVec && modeList > 0)
		{
			if (lenL < lenR || (lenL == lenR && rng.chance(50)))
			{
				if (lenL > 0)
					choice = 1;
			}
			else
			{
				if (lenR > 0)
					choice = 2;
			}
		}
		else
		{
			if (lenL > lenR || (lenL == lenR && rng.chance(50)))
			{
				if (lenL > 0)
					choice = 1;
			}
			else
			{
				if (lenR > 0)
					choice = 2;
			}
		}
		pos = startsEx[choice];
		dir = dirs2[choice];
		usedList[choice] = true;
	}
	if (branchVec)
	{
		bool spawnedList = false;
		int which = rng.rangeInt(0,1);
		for (int i = 0; i < 2; i++)
		{
			int idx = OpW7_pickIndex_9d4b30(usedList,3,false);
			usedList[idx] = true;
			if (room6 && !spawnedList && which == i)
			{
				OpB_translateRotated(&startsEx[idx],dirs2[idx],width / 2,0);
				int size = width * 2;
				int rdelay = dug ? roomDelay1 + (roomDelay1 - opw7_generator.getTurn()) / opw7_settings->unknown50 : roomDelay1;
				opw7_generator.addBuilderBase(new OpW7_Roomie(rdelay,dirs2[idx],startsEx[idx],pickAList,size));
			}
			else
			{
				int ws = width;
				int len = param24;
				ws += modeList;
				if (modeList > 0)
					len += 2;
				else if (modeList < 0)
					OpW7_subtractMin_9d0690(len,2,3);
				if (modeList != 0)
					OpB_translateRotated(&startsEx[idx],dirs2[idx],-modeList / 2,0);
				opw7_generator.addBuilderBase(new OpW7_Tunneler(newDelayVec,dirs2[idx],startsEx[idx],elemSet.unknown00,ws,len,v28Ex,v2CVec,chanceTurnBranchSet,v34,v38Ex,v3C,false));
			}
		}
	}
	return 2;
}

extern int opw7_bb8360[4];	// NOTE: placeholder name (opposite direction)

void OpW7_Tunneler::spawn(int roomType)
{
	int rollB = rng.rangeInt(1,10) * 10;
	int length = measure(pos,dir,0,opw7_settings->unknown00,0);
	bool blocked = false;
	bool hitRoomList = false;
	bool hitTunnel = false;
	vector<int> hits;
	Pos pList;
	for (int i = 0; i < width; i++)
	{
		pList = pos;
		OpB_translateRotated(&pList,dir,i,length + 1);
		if (!opw7_cells.contains(pList))
			blocked = true;
		else if (opw7_cells[pList] == 4 || opw7_cells[pList] == 5)
		{
			hitTunnel = true;
			hits.push_back(i);
		}
		else if (opw7_cells[pList] == 7)
			hitRoomList = true;
	}
	if (length < 5 || (rng.chance(param3C) && (age < param1C - 1 || length <= opw7_settings->unknown54)))
	{
		if (hits.size() == width)
		{
			dig(4,length,0,opw7_settings->unknown00,0);
			return;
		}
		if (hitTunnel)
		{
			width = 1;
			OpB_translateRotated(&pos,dir,OpW7_randomElement_9d5d00(hits),0);
			dig(4,length,0,opw7_settings->unknown00,0);
			return;
		}
		if (hitRoomList && width == 1)
		{
			if (length > 1)
				dig(4,length - 1,0,opw7_settings->unknown00,0);
			Pos door = pos;
			OpB_translateRotated(&door,dir,0,length);
			opw7_cells[door] = (dir != 0 && dir != 2) ? 11 : 10;
			return;
		}
		if (blocked && width == 1)
		{
			if (rollB != 100 || param28 != opw7_settings->unknown80 || param2C != opw7_settings->unknown84 || param30 != opw7_settings->unknown88 || param34 != opw7_settings->unknown8C || param38 != opw7_settings->unknown90)
			{
				int lenL = measure(pos,opw7_bb8350[dir],0,opw7_settings->unknown00,opw7_settings->unknown00);
				int lenRList = measure(pos,opw7_bb8340[dir],0,opw7_settings->unknown00,opw7_settings->unknown00);
				if (lenL > lenRList || (lenL == lenRList && rng.chance(50)))
					opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + 1,opw7_bb8350[dir],pos,param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
				else
					opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + 1,opw7_bb8340[dir],pos,param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
			}
			return;
		}
	}
	if (opw7_generator.getRoomCount(roomType) < opw7_settings->rooms[roomType].maxCount)
	{
		Pos roomPosList = pos;
		OpB_translateRotated(&roomPosList,dir,width / 2,0);
		int size = width * 2;
		opw7_generator.addBuilderBase(new OpW7_Roomie(delay,dir,roomPosList,roomType,size));
	}
	if (rollB != 100 || param28 != opw7_settings->unknown80 || param2C != opw7_settings->unknown84 || param30 != opw7_settings->unknown88 || param34 != opw7_settings->unknown8C || param38 != opw7_settings->unknown90)
	{
		Pos endsList[4] = {pos,pos,pos,pos};
		OpB_translateRotated(&endsList[1],dir,0,-width + 1);
		int lenLVec = measure(endsList[1],opw7_bb8350[dir],0,opw7_settings->unknown00,opw7_settings->unknown00);
		OpB_translateRotated(&endsList[2],dir,width - 1,0);
		int lenR = measure(endsList[2],opw7_bb8340[dir],0,opw7_settings->unknown00,opw7_settings->unknown00);
		OpB_translateRotated(&endsList[3],dir,width - 1,0);
		int lenB = measure(endsList[3],opw7_bb8360[dir],0,opw7_settings->unknown00,opw7_settings->unknown00);
		if (width > 1)
		{
			if (blocked)
			{
				opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + opw7_settings->unknown9C,opw7_bb8350[dir],endsList[1],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
				opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + opw7_settings->unknown9C,opw7_bb8340[dir],endsList[2],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
			}
			else if (hitRoomList)
			{
				OpB_translateRotated(&endsList[0],dir,width / 2,0);
				opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + opw7_settings->unknown9C,dir,endsList[0],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
				if (rng.chance(50))
					opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + opw7_settings->unknown9C,opw7_bb8350[dir],endsList[1],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
				else
					opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + opw7_settings->unknown9C,opw7_bb8340[dir],endsList[2],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
			}
			else
			{
				bool left = rng.chance(50);
				opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + opw7_settings->unknown9C,left ? opw7_bb8350[dir] : dir,endsList[0],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
				OpB_translateRotated(&endsList[0],dir,width - 1,0);
				opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + opw7_settings->unknown9C,left ? dir : opw7_bb8340[dir],endsList[0],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
			}
		}
		else
		{
			if (!(param28 != opw7_settings->unknown80 || param2C != opw7_settings->unknown84 || param30 != opw7_settings->unknown88 || param34 != opw7_settings->unknown8C || param38 != opw7_settings->unknown90))
			{
				if (length >= lenLVec && length >= lenR && length >= lenB)
					opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + 1,dir,endsList[0],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
				else if (lenB >= lenLVec && lenB >= lenR)
					opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + opw7_settings->unknown9C,opw7_bb8360[dir],endsList[3],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
				else if (lenR > lenLVec || (lenR == lenLVec && rng.chance(50)))
					opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + opw7_settings->unknown9C,opw7_bb8340[dir],endsList[2],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
				else
					opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + opw7_settings->unknown9C,opw7_bb8350[dir],endsList[1],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
			}
			else
				opw7_generator.addBuilderBase(new OpW7_Tunneler(delay + opw7_settings->unknown9C,dir,endsList[0],param1C,opw7_settings->unknown78,opw7_settings->unknown7C,opw7_settings->unknown80,opw7_settings->unknown84,opw7_settings->unknown88,opw7_settings->unknown8C,opw7_settings->unknown90,rollB,false));
		}
	}
}

class OpW7_CellGrid	// NOTE: placeholder name (same object as opw7_cells)
{
public:
	OpW7_CellGrid(int width, int height, int value);	// NOTE: placeholder name (0x9ced10)
	~OpW7_CellGrid();	// NOTE: placeholder name (0x9cec20)
	int width;
	int height;
	void *values;
	int &at(int x, int y);	// NOTE: placeholder name (0x9ceda0)
	bool inBounds(int x, int y);	// NOTE: placeholder name (0x9b45c0)
	void replace_9cf630(int from, int to);	// NOTE: placeholder name
	int &operator[](const Pos &pos);	// NOTE: placeholder name (0x9ced70)
	bool isEdge_9b7960(const Pos &pos);	// NOTE: placeholder name
	void randomPos(Pos &pos);	// NOTE: placeholder name (0x9cf0c0)
	int getWidth();	// NOTE: placeholder name
	int getHeight();	// NOTE: placeholder name
};
extern OpW7_CellGrid opw7_grid;	// NOTE: placeholder name

int OpW7_Roomie::build()
{
	if (opw7_generator.getRoomCount(roomType) >= opw7_settings->rooms[roomType].maxCount)
		return 0;
	if (delay > opw7_generator.getTurn())
		return 1;
	age++;
	int w = param1C;
	int rightSpace, leftSpace, roomW, roomH;
	do
	{
		int length = measure(pos,w,&leftSpace,&rightSpace,opw7_settings->roomMargin);
		if (length < 4 || leftSpace < 0 || rightSpace < 0)
			return 0;
		roomH = length;
		roomW = leftSpace + rightSpace;
		if ((float)roomW / roomH < opw7_settings->maxRoomRatio)
			roomH = (int)(roomW / opw7_settings->maxRoomRatio);
		else if ((float)roomH / roomW < opw7_settings->maxRoomRatio)
			roomW = (int)(roomH / opw7_settings->maxRoomRatio);
		while (roomW * roomH > opw7_settings->rooms[roomType].maxArea)
		{
			if (roomW > roomH)
				roomW--;
			else if (roomH > roomW)
				roomH--;
			else if (rng.chance(50))
				roomW--;
			else
				roomH--;
		}
		if (roomW * roomH >= opw7_settings->rooms[roomType].minArea)
		{
			Pos roomPos = pos;
			if (leftSpace <= rightSpace)
			{
				if (leftSpace * 2 - opw7_settings->roomMargin > roomW)
					OpB_translateRotated(&roomPos,dir,-roomW / 2,2);
				else
					OpB_translateRotated(&roomPos,dir,maxInt(-leftSpace,-roomW + 1),2);
			}
			else
			{
				if (rightSpace * 2 - opw7_settings->roomMargin > roomW)
					OpB_translateRotated(&roomPos,dir,-roomW / 2,2);
				else
					OpB_translateRotated(&roomPos,dir,rightSpace - roomW + 1,2);
			}
			OpW7_Room newRoom;
			opw7_rooms.push_back(newRoom);
			OpW7_Room *room = &opw7_rooms.back();
			room->type = roomType;
			switch (dir)
			{
				case 0: room->rect.set(roomPos.x,roomPos.y - roomH + 1,roomW,roomH); break;
				case 1: room->rect.set(roomPos.x,roomPos.y,roomH,roomW); break;
				case 2: room->rect.set(roomPos.x - roomW + 1,roomPos.y,roomW,roomH); break;
				case 3: room->rect.set(roomPos.x - roomH + 1,roomPos.y - roomW + 1,roomH,roomW); break;
			}
			for (int x = room->rect.x; x < room->rect.x + room->rect.width; x++)
				for (int y = room->rect.y; y < room->rect.y + room->rect.height; y++)
					opw7_grid.at(x,y) = 7;
			Pos entry = pos;
			OpB_translateRotated(&entry,dir,0,1);
			opw7_cells[entry] = (dir == 0 || dir == 2) ? 10 : 11;
			opw7_generator.addRoomCount(roomType);
			return 0;
		}
		else
			w += 2;
	} while (roomH >= (2.0 * roomW + 1.0) * opw7_settings->maxRoomRatio);
	return 0;
}

//==================================================================
// generator settings
//==================================================================

void readInt(istream &in, int *value);	// NOTE: placeholder name (0x9d8480)
void readFloat_9cf520(istream &in, float *value);	// NOTE: placeholder name

struct OpW7_Blob08 { int data[2]; };	// NOTE: placeholder name
struct OpW7_Blob0c { int data[3]; };	// NOTE: placeholder name
struct OpW7_Blob10 { int data[4]; };	// NOTE: placeholder name
struct OpW7_Blob44x3 { int data[0x33]; };	// NOTE: placeholder name

void OpW7_read_9d4cc0(istream &in, OpW7_Blob10 *value);	// NOTE: placeholder name
void OpW7_read_9cf5e0(istream &in, OpW7_Blob10 *value);	// NOTE: placeholder name
void OpW7_read_9d4d20(istream &in, OpW7_Blob44x3 *value);	// NOTE: placeholder name
void OpW7_read_9d4d70(istream &in, OpW7_Blob10 *value);	// NOTE: placeholder name
void OpW7_read_9d4e20(istream &in, OpW7_Blob10 *value);	// NOTE: placeholder name
void OpW7_read_4097e0(istream &in, OpW7_Blob10 *value);	// NOTE: placeholder name
void OpW7_read_9d4ec0(istream &in, OpW7_Blob0c *value);	// NOTE: placeholder name

struct OpW7_Range	// NOTE: placeholder name (0x14 bytes)
{
	void load(istream &in);	// NOTE: placeholder name (0x448190)
	int data[5];
};

struct OpW7_Settings84	// NOTE: placeholder name (0x84 bytes)
{
	void load(istream &in);	// NOTE: placeholder name (0x448630)
	int data[0x21];
};

struct OpW7_Settings08	// NOTE: placeholder name
{
	void load(istream &in);	// NOTE: placeholder name (0x45f040)
	int data[2];
};

struct OpW7_GenSettings	// NOTE: placeholder name (DF settings)
{
	void load(istream &in);	// NOTE: placeholder name

	int unknown00;
	int unknown04;
	int unknown08;
	int unknown0c;
	int unknown10;
	OpW7_Range unknown14;
	OpW7_Range unknown28;
	OpW7_Range unknown3c;
	int unknown50;
	int unknown54;
	OpW7_Tunneler tunneler;
	int unknown9c;
	OpW7_Blob10 unknowna0;
	int unknownb0;
	OpW7_Blob10 unknownb4;
	OpW7_Blob44x3 rooms;
	int unknown190;
	float unknown194;
	int unknown198;
	int unknown19c;
	int unknown1a0;
	int unknown1a4;
	int unknown1a8;
	OpW7_Blob10 unknown1ac;
	OpW7_Blob10 unknown1bc;
	OpW7_Settings84 unknown1cc;
	OpW7_Blob10 unknown250;
	OpW7_Settings08 unknown260;
	OpW7_Blob0c unknown268;
	int unknown274;
	int unknown278;
	int unknown27c;
};

void OpW7_GenSettings::load(istream &in)
{
	readInt(in,&unknown00);
	readInt(in,&unknown04);
	readInt(in,&unknown08);
	readInt(in,&unknown0c);
	readInt(in,&unknown10);
	unknown14.load(in);
	unknown28.load(in);
	unknown3c.load(in);
	readInt(in,&unknown50);
	readInt(in,&unknown54);
	tunneler.load(in);
	readInt(in,&unknown9c);
	OpW7_read_9d4cc0(in,&unknowna0);
	readInt(in,&unknownb0);
	OpW7_read_9cf5e0(in,&unknownb4);
	OpW7_read_9d4d20(in,&rooms);
	readInt(in,&unknown190);
	readFloat_9cf520(in,&unknown194);
	readInt(in,&unknown198);
	readInt(in,&unknown19c);
	readInt(in,&unknown1a0);
	readInt(in,&unknown1a4);
	readInt(in,&unknown1a8);
	OpW7_read_9d4d70(in,&unknown1ac);
	OpW7_read_9d4e20(in,&unknown1bc);
	unknown1cc.load(in);
	OpW7_read_4097e0(in,&unknown250);
	unknown260.load(in);
	OpW7_read_9d4ec0(in,&unknown268);
	readInt(in,&unknown274);
	readInt(in,&unknown278);
	readInt(in,&unknown27c);
}

struct OpW7_Record4bf300	// NOTE: placeholder name
{
	int unknown00[5];	// NOTE: placeholder name
	string unknown14;	// NOTE: placeholder name
	string unknown30;	// NOTE: placeholder name
	int unknown4c;	// NOTE: placeholder name
	string unknown50;	// NOTE: placeholder name
	int unknown6c;	// NOTE: placeholder name
	vector<int> unknown70;	// NOTE: placeholder name
};

void OpW7_useDf(OpW7_Record4bf300 *a)	// NOTE: placeholder name
{
	a->OpW7_Record4bf300::~OpW7_Record4bf300();
}

void OpW7_Generator::floodFill(int x, int y, OpW7_BoolGrid *visited, const Pos &offset, vector<Pos> &cells)
{
	if (!((OpW7_BoolGrid*)&opw7_cells)->inBounds(x,y) || !visited->inBounds(x - offset.x,y - offset.y) || visited->at(x - offset.x,y - offset.y))
		return;
	visited->at(x - offset.x,y - offset.y) = true;
	if (opw7_grid.at(x,y) == 7)
	{
		cells.push_back(Pos(x,y));
		floodFill(x - 1,y,visited,offset,cells);
		floodFill(x + 1,y,visited,offset,cells);
		floodFill(x,y - 1,visited,offset,cells);
		floodFill(x,y + 1,visited,offset,cells);
	}
}

void OpW7_Generator::placeTunnelers()
{
	starts.clear();
	Pos pos;
	int tries;
	for (unsigned int i = 0; i < opw7_settings->spawns.size(); i++)
	{
		if (opw7_settings->spawns[i].enabled && (opw7_settings->spawns[i].level == level || opw7_settings->spawns[i].level == 0))
		{
			OpW7_Spawn *s = &opw7_settings->spawns[i];
			tries = 0;
			do
			{
				pos.set(s->x.randomInRange_40c130(),s->y.randomInRange_40c130());
				if (opw7_cells[pos] == 3)
				{
					addBuilder(new OpW7_Tunneler(s->delay.randomInRange_40c130(),OpW7_randomElement_9d5d00(s->dirs),pos,s->param1C.randomInRange_40c130(),s->width.randomInRange_40c130(),s->param24.randomInRange_40c130(),s->param28.randomInRange_40c130(),s->param2C.randomInRange_40c130(),s->param30.randomInRange_40c130(),s->param34.randomInRange_40c130(),s->param38.randomInRange_40c130(),s->param3C.randomInRange_40c130(),false));
					starts.push_back(pos);
					break;
				}
				else if (s->x.isEmpty() && s->y.isEmpty())
				{
					starts.push_back(Pos(-1));
					break;
				}
			} while (++tries < 1000);
			if (tries == 1000)
				starts.push_back(Pos(-1));
		}
		else
			starts.push_back(Pos(-1));
	}
}

class OpW7_MoveCostBase	// NOTE: placeholder name (Cartographer2DMoveCost)
{
public:
	OpW7_MoveCostBase();	// 0x4c1860
	virtual ~OpW7_MoveCostBase();
	virtual bool isBlocked(int x, int y, int unused);	// NOTE: placeholder name
	virtual void unknown08();	// NOTE: placeholder name
};

class OpW7_PathMoveCost : public OpW7_MoveCostBase	// NOTE: placeholder name (DF::PathMoveCost)
{
public:
	virtual bool isBlocked(int x, int y, int unused);	// NOTE: placeholder name
};

bool OpW7_PathMoveCost::isBlocked(int x, int y, int unused)
{
	return opw7_grid.at(x,y) >= 4;
}

void OpW7_useDf2()	// NOTE: placeholder name
{
	OpW7_PathMoveCost cost;
}

int OpW7_getWallFacing(int x, int y)	// NOTE: placeholder name
{
	if (opw7_grid.at(x,y) == 4 && opw7_grid.at(x - 1,y) <= 3 && opw7_grid.at(x + 1,y) <= 3 && opw7_grid.at(x - 1,y + 1) <= 3 && opw7_grid.at(x,y + 1) <= 3 && opw7_grid.at(x + 1,y + 1) <= 3)
		return 0;
	if (opw7_grid.at(x,y) == 4 && opw7_grid.at(x - 1,y - 1) <= 3 && opw7_grid.at(x,y - 1) <= 3 && opw7_grid.at(x - 1,y) <= 3 && opw7_grid.at(x - 1,y + 1) <= 3 && opw7_grid.at(x,y + 1) <= 3)
		return 1;
	if (opw7_grid.at(x,y) == 4 && opw7_grid.at(x - 1,y - 1) <= 3 && opw7_grid.at(x,y - 1) <= 3 && opw7_grid.at(x + 1,y - 1) <= 3 && opw7_grid.at(x - 1,y) <= 3 && opw7_grid.at(x + 1,y) <= 3)
		return 2;
	if (opw7_grid.at(x,y) == 4 && opw7_grid.at(x,y - 1) <= 3 && opw7_grid.at(x + 1,y - 1) <= 3 && opw7_grid.at(x + 1,y) <= 3 && opw7_grid.at(x,y + 1) <= 3 && opw7_grid.at(x + 1,y + 1) <= 3)
		return 3;
	return 4;
}

class OpW7_WallThinner	// NOTE: placeholder name
{
public:
	void thinWalls();	// NOTE: placeholder name
};

void OpW7_WallThinner::thinWalls()
{
	int tx, cy, t;
	for (int x = 1; x < opw7_grid.getWidth() - 1; x++)
	{
		for (int y = 1; y < opw7_grid.getHeight() - 1; y++)
		{
			if (opw7_grid.at(x,y) == 4)
			{
				int facing = OpW7_getWallFacing(x,y);
				if (facing != 4)
				{
					tx = x;
					cy = y;
					while (facing != 4)
					{
						opw7_grid.at(tx,cy) = 3;
						switch (facing)
						{
							case 0: cy--; break;
							case 1: tx++; break;
							case 2: cy++; break;
							case 3: tx--; break;
						}
						facing = OpW7_getWallFacing(tx,cy);
					}
				}
			}
		}
	}
}

extern vector<Rect> opw7_d3161c;	// NOTE: placeholder name (removed corridors)
void OpW7_eraseIndex_9d4ff0(vector<OpW7_Corridor> &v, unsigned int index);	// NOTE: placeholder name

void OpW7_removeCorridorAt(int x, int y)	// NOTE: placeholder name
{
	if (opw7_grid.at(x,y) == 5)
	{
		bool found = false;
		for (unsigned int i = 0; i < opw7_corridors.size(); i++)
		{
			if (((const vector<OpW7_Corridor>&)opw7_corridors)[i].rect.contains(x,y))
			{
				found = true;
				for (int cx = ((const vector<OpW7_Corridor>&)opw7_corridors)[i].rect.x; cx < ((const vector<OpW7_Corridor>&)opw7_corridors)[i].rect.x + ((const vector<OpW7_Corridor>&)opw7_corridors)[i].rect.width; cx++)
					for (int cy = ((const vector<OpW7_Corridor>&)opw7_corridors)[i].rect.y; cy < ((const vector<OpW7_Corridor>&)opw7_corridors)[i].rect.y + ((const vector<OpW7_Corridor>&)opw7_corridors)[i].rect.height; cy++)
						opw7_grid.at(cx,cy) = 4;
				opw7_d3161c.push_back(((const vector<OpW7_Corridor>&)opw7_corridors)[i].rect);
				OpW7_eraseIndex_9d4ff0(opw7_corridors,i);
				break;
			}
		}
	}
}

bool OpW7_isFloor(int x, int y, bool *door)	// NOTE: placeholder name
{
	switch (opw7_grid.at(x,y))
	{
		case 0: return false;
		case 1: return false;
		case 2: return false;
		case 3: return true;
		case 4: return false;
		case 5: return false;
	}
	*door = true;
	return false;
}

void OpW7_fillArea(OpW7_BoolGrid *visited, OpW7_CellGrid *marks, int value, int x, int y, bool *door, vector<Pos> *cells)	// NOTE: placeholder name
{
	if (!((OpW7_BoolGrid*)&opw7_cells)->inBounds(x,y) || marks->at(x,y) == value)
		return;
	marks->at(x,y) = value;
	if (OpW7_isFloor(x,y,door))
	{
		visited->at(x,y) = true;
		cells->push_back(Pos(x,y));
		if (cells->size() > opw7_settings->unknown190[2])
			return;
		OpW7_fillArea(visited,marks,value,x - 1,y,door,cells);
		OpW7_fillArea(visited,marks,value,x + 1,y,door,cells);
		OpW7_fillArea(visited,marks,value,x,y - 1,door,cells);
		OpW7_fillArea(visited,marks,value,x,y + 1,door,cells);
	}
}

int opw3_minInt(int a, int b);	// NOTE: placeholder name (0x9cdb30)
void OpW7_eraseIndex_9d5030(vector<Rect> &v, unsigned int &index);	// NOTE: placeholder name

void OpW7_Generator::findCaves()
{
	OpW7_BoolGrid visited(opw7_grid.getWidth(),opw7_grid.getHeight(),false);
	OpW7_CellGrid marksAll(opw7_grid.getWidth(),opw7_grid.getHeight(),0);
	int countAll = 0;
	vector<Pos> cellsB;
	Pos pVec;
	Rect rAll;
	bool door;
	int left, topAll, right, bottomAll;
	for (int x = 1; x < opw7_grid.getWidth() - 1; x++)
	{
		for (int y = 1; y < opw7_grid.getHeight() - 1; y++)
		{
			if (opw7_grid.at(x,y) == 3 && !visited.at(x,y))
			{
				door = false;
				cellsB.clear();
				countAll++;
				OpW7_fillArea(&visited,&marksAll,countAll,x,y,&door,&cellsB);
				if (!door && cellsB.size() <= opw7_settings->unknown190[2])
				{
					caves.push_back(rAll);
					Rect *cave = &caves.back();
					cave->set(cellsB.front().x,cellsB.front().y,cellsB.front().x,cellsB.front().y);
					for (unsigned int k = 1; k < cellsB.size(); k++)
					{
						pVec = cellsB[k];
						opw7_cells[pVec] = 4;
						OpW7_removeCorridorAt(pVec.x - 1,pVec.y);
						OpW7_removeCorridorAt(pVec.x + 1,pVec.y);
						OpW7_removeCorridorAt(pVec.x,pVec.y - 1);
						OpW7_removeCorridorAt(pVec.x,pVec.y + 1);
						if (pVec.x < cave->x)
							cave->x = pVec.x;
						else if (pVec.x > cave->width)
							cave->width = pVec.x;
						if (pVec.y < cave->y)
							cave->y = pVec.y;
						else if (pVec.y > cave->height)
							cave->height = pVec.y;
					}
					cave->width = cave->width - cave->x + 1;
					cave->height = cave->height - cave->y + 1;
				}
			}
		}
	}
	for (unsigned int i = 0; i < caves.size(); i++)
	{
		for (unsigned int j = i + 1; j < caves.size(); j++)
		{
			if (caves[i].distance_40ae20(caves[j]) <= opw7_settings->unknown190[3])
			{
				left = opw3_minInt(caves[i].x,caves[j].x);
				topAll = opw3_minInt(caves[i].y,caves[j].y);
				right = maxInt(caves[i].right_40ac20(),caves[j].right_40ac20());
				bottomAll = maxInt(caves[i].bottom_40ac40(),caves[j].bottom_40ac40());
				caves[i].set(left,topAll,right - left + 1,bottomAll - topAll + 1);
				OpW7_eraseIndex_9d5030(caves,j);
			}
		}
	}
}

int OpW7_getFloorCorner(int x, int y)	// NOTE: placeholder name
{
	if (opw7_grid.at(x,y) == 3 && opw7_grid.at(x - 1,y) == 4 && opw7_grid.at(x + 1,y) == 4 && opw7_grid.at(x - 1,y + 1) == 4 && opw7_grid.at(x,y + 1) == 4 && opw7_grid.at(x + 1,y + 1) == 4)
		return 0;
	if (opw7_grid.at(x,y) == 3 && opw7_grid.at(x - 1,y - 1) == 4 && opw7_grid.at(x,y - 1) == 4 && opw7_grid.at(x - 1,y) == 4 && opw7_grid.at(x - 1,y + 1) == 4 && opw7_grid.at(x,y + 1) == 4)
		return 1;
	if (opw7_grid.at(x,y) == 3 && opw7_grid.at(x - 1,y - 1) == 4 && opw7_grid.at(x,y - 1) == 4 && opw7_grid.at(x + 1,y - 1) == 4 && opw7_grid.at(x - 1,y) == 4 && opw7_grid.at(x + 1,y) == 4)
		return 2;
	if (opw7_grid.at(x,y) == 3 && opw7_grid.at(x,y - 1) == 4 && opw7_grid.at(x + 1,y - 1) == 4 && opw7_grid.at(x + 1,y) == 4 && opw7_grid.at(x,y + 1) == 4 && opw7_grid.at(x + 1,y + 1) == 4)
		return 3;
	return 4;
}

class OpW7_FloorFiller	// NOTE: placeholder name
{
public:
	void fillCorners();	// NOTE: placeholder name
	void fillWideCorners();	// NOTE: placeholder name
};

void OpW7_FloorFiller::fillCorners()
{
	int tx, cy, t;
	for (int x = 1; x < opw7_grid.getWidth() - 1; x++)
	{
		for (int y = 1; y < opw7_grid.getHeight() - 1; y++)
		{
			if (opw7_grid.at(x,y) == 3)
			{
				int facing = OpW7_getFloorCorner(x,y);
				if (facing != 4)
				{
					tx = x;
					cy = y;
					while (facing != 4)
					{
						opw7_grid.at(tx,cy) = 4;
						switch (facing)
						{
							case 0: cy--; break;
							case 1: tx++; break;
							case 2: cy++; break;
							case 3: tx--; break;
						}
						facing = OpW7_getFloorCorner(tx,cy);
					}
				}
			}
		}
	}
}

int OpW7_getWideFloorCorner(int x, int y)	// NOTE: placeholder name
{
	if (opw7_grid.at(x,y) == 3 && opw7_grid.at(x + 1,y) == 3 && opw7_grid.at(x + 1,y + 1) == 4 && opw7_grid.at(x - 1,y) == 4 && opw7_grid.at(x + 2,y) == 4 && opw7_grid.at(x - 1,y + 1) == 4 && opw7_grid.at(x,y + 1) == 4 && opw7_grid.at(x + 2,y + 1) == 4)
		return 0;
	if (opw7_grid.at(x,y) == 3 && opw7_grid.at(x,y + 1) == 3 && opw7_grid.at(x - 1,y + 1) == 4 && opw7_grid.at(x - 1,y - 1) == 4 && opw7_grid.at(x,y - 1) == 4 && opw7_grid.at(x - 1,y) == 4 && opw7_grid.at(x - 1,y + 2) == 4 && opw7_grid.at(x,y + 2) == 4)
		return 1;
	if (opw7_grid.at(x,y) == 3 && opw7_grid.at(x - 1,y) == 3 && opw7_grid.at(x - 1,y - 1) == 4 && opw7_grid.at(x - 2,y - 1) == 4 && opw7_grid.at(x,y - 1) == 4 && opw7_grid.at(x + 1,y - 1) == 4 && opw7_grid.at(x - 2,y) == 4 && opw7_grid.at(x + 1,y) == 4)
		return 2;
	if (opw7_grid.at(x,y) == 3 && opw7_grid.at(x,y - 1) == 3 && opw7_grid.at(x + 1,y - 1) == 4 && opw7_grid.at(x,y - 2) == 4 && opw7_grid.at(x + 1,y - 2) == 4 && opw7_grid.at(x + 1,y) == 4 && opw7_grid.at(x,y + 1) == 4 && opw7_grid.at(x + 1,y + 1) == 4)
		return 3;
	return 4;
}

void OpW7_FloorFiller::fillWideCorners()
{
	int tx, cy, t;
	for (int x = 1; x < opw7_grid.getWidth() - 1; x++)
	{
		for (int y = 1; y < opw7_grid.getHeight() - 1; y++)
		{
			if (opw7_grid.at(x,y) == 3)
			{
				int facing = OpW7_getWideFloorCorner(x,y);
				if (facing != 4)
				{
					tx = x;
					cy = y;
					while (facing != 4)
					{
						opw7_grid.at(tx,cy) = 4;
						switch (facing)
						{
							case 0: opw7_grid.at(tx + 1,cy) = 4; cy--; break;
							case 1: opw7_grid.at(tx,cy + 1) = 4; tx++; break;
							case 2: opw7_grid.at(tx - 1,cy) = 4; cy++; break;
							case 3: opw7_grid.at(tx,cy - 1) = 4; tx--; break;
						}
						facing = OpW7_getWideFloorCorner(tx,cy);
					}
				}
			}
		}
	}
}

bool OpW7_hasNonWall(const Rect &rect)	// NOTE: placeholder name
{
	for (int x = rect.x; x < rect.x + rect.width; x++)
	{
		for (int y = rect.y; y < rect.y + rect.height; y++)
		{
			if (opw7_grid.at(x,y) != 4)
				return true;
		}
	}
	return false;
}

bool OpW7_anyNonZero_9d3f40(int *values, unsigned int count);	// NOTE: placeholder name

bool OpW7_measureWallEdges(const Rect &rect, int *depth, int *area)	// NOTE: placeholder name
{
	int i;
	bool full;
	for (i = 0; i < rect.height; i++)
	{
		full = true;
		for (int x = rect.x; x < rect.x + rect.width; x++)
		{
			if (opw7_grid.at(x,rect.y + i) != 4)
			{
				full = false;
				break;
			}
		}
		if (full)
			break;
	}
	depth[0] = i;
	area[0] = i == 0 ? 0 : (rect.height - i) * rect.width;
	for (i = 0; i < rect.height; i++)
	{
		full = true;
		for (int x = rect.x; x < rect.x + rect.width; x++)
		{
			if (opw7_grid.at(x,rect.y + rect.height - 1 - i) != 4)
			{
				full = false;
				break;
			}
		}
		if (full)
			break;
	}
	depth[2] = i;
	area[2] = i == 0 ? 0 : (rect.height - i) * rect.width;
	for (i = 0; i < rect.width; i++)
	{
		full = true;
		for (int y = rect.y; y < rect.y + rect.height; y++)
		{
			if (opw7_grid.at(rect.x + i,y) != 4)
			{
				full = false;
				break;
			}
		}
		if (full)
			break;
	}
	depth[3] = i;
	area[3] = i == 0 ? 0 : (rect.width - i) * rect.height;
	for (i = 0; i < rect.width; i++)
	{
		full = true;
		for (int y = rect.y; y < rect.y + rect.height; y++)
		{
			if (opw7_grid.at(rect.x + rect.width - 1 - i,y) != 4)
			{
				full = false;
				break;
			}
		}
		if (full)
			break;
	}
	depth[1] = i;
	area[1] = i == 0 ? 0 : (rect.width - i) * rect.height;
	return OpW7_anyNonZero_9d3f40(depth,4);
}

void OpW7_measureWallInset(const Rect &rect, int *depth, int *area)	// NOTE: placeholder name
{
	int i;
	bool full;
	for (i = 1; i < rect.height; i++)
	{
		full = true;
		for (int x = rect.x; x < rect.x + rect.width; x++)
		{
			if (opw7_grid.at(x,rect.y + rect.height - 1 - i) != 4)
			{
				full = false;
				break;
			}
		}
		if (!full)
		{
			i--;
			break;
		}
	}
	depth[0] = i;
	area[0] = (i + 1) * rect.width;
	for (i = 1; i < rect.height; i++)
	{
		full = true;
		for (int x = rect.x; x < rect.x + rect.width; x++)
		{
			if (opw7_grid.at(x,rect.y + i) != 4)
			{
				full = false;
				break;
			}
		}
		if (!full)
		{
			i--;
			break;
		}
	}
	depth[2] = i;
	area[2] = (i + 1) * rect.width;
	for (i = 1; i < rect.width; i++)
	{
		full = true;
		for (int y = rect.y; y < rect.y + rect.height; y++)
		{
			if (opw7_grid.at(rect.x + rect.width - 1 - i,y) != 4)
			{
				full = false;
				break;
			}
		}
		if (!full)
		{
			i--;
			break;
		}
	}
	depth[3] = i;
	area[3] = (i + 1) * rect.height;
	for (i = 1; i < rect.width; i++)
	{
		full = true;
		for (int y = rect.y; y < rect.y + rect.height; y++)
		{
			if (opw7_grid.at(rect.x + i,y) != 4)
			{
				full = false;
				break;
			}
		}
		if (!full)
		{
			i--;
			break;
		}
	}
	depth[1] = i;
	area[1] = (i + 1) * rect.height;
}

void opW9_fillBool(bool *values, unsigned int count, bool value);	// NOTE: placeholder name (0x9cdcc0)
bool OpW7_anyTrue_9d5080(bool *values, unsigned int count);	// NOTE: placeholder name

bool OpW7_findOpenSides(const Rect &rect, bool *open)	// NOTE: placeholder name
{
	opW9_fillBool(open,4,true);
	for (int x = rect.x; x < rect.x + rect.width; x++)
	{
		if (opw7_grid.at(x,rect.y - 1) != 4)
		{
			open[0] = false;
			break;
		}
	}
	for (int x = rect.x; x < rect.x + rect.width; x++)
	{
		if (opw7_grid.at(x,rect.y + rect.height) != 4)
		{
			open[2] = false;
			break;
		}
	}
	for (int y = rect.y; y < rect.y + rect.height; y++)
	{
		if (opw7_grid.at(rect.x - 1,y) != 4)
		{
			open[3] = false;
			break;
		}
	}
	for (int y = rect.y; y < rect.y + rect.height; y++)
	{
		if (opw7_grid.at(rect.x + rect.width,y) != 4)
		{
			open[1] = false;
			break;
		}
	}
	return OpW7_anyTrue_9d5080(open,4);
}

Rect OpW7_largestRemainder(const Rect &outer, const Rect &inner)	// NOTE: placeholder name
{
	Rect rect;
	Rect best(-1,-1,-1,-1);
	if (inner.y > outer.y)
	{
		rect.set(outer.x,outer.y,outer.width,inner.y - outer.y);
		if (rect.area_40ad00() > best.area_40ad00())
			best = rect;
	}
	if (inner.y + inner.height < outer.y + outer.height)
	{
		rect.set(outer.x,inner.y + inner.height,outer.width,outer.y + outer.height - (inner.y + inner.height));
		if (rect.area_40ad00() > best.area_40ad00())
			best = rect;
	}
	if (inner.x > outer.x)
	{
		rect.set(outer.x,outer.y,inner.x - outer.x,outer.height);
		if (rect.area_40ad00() > best.area_40ad00())
			best = rect;
	}
	if (inner.x + inner.width < outer.x + outer.width)
	{
		rect.set(inner.x + inner.width,outer.y,outer.x + outer.width - (inner.x + inner.width),outer.height);
		if (rect.area_40ad00() > best.area_40ad00())
			best = rect;
	}
	return best;
}

bool OpW7_widenCorner(const Rect &rect, int dir)	// NOTE: placeholder name
{
	bool result = false;
	Pos a;
	Pos bs;
	switch (dir)
	{
		case 0:
			a.set(rect.x,rect.y);
			bs.set(rect.x + rect.width - 1,rect.y);
			break;
		case 1:
			a.set(rect.x + rect.width - 1,rect.y);
			bs.set(rect.x + rect.width - 1,rect.y + rect.height - 1);
			break;
		case 2:
			a.set(rect.x + rect.width - 1,rect.y + rect.height - 1);
			bs.set(rect.x,rect.y + rect.height - 1);
			break;
		case 3:
			a.set(rect.x,rect.y + rect.height - 1);
			bs.set(rect.x,rect.y);
			break;
	}
	int side = 1;
	while (true)
	{
		Pos p1 = side == 1 ? a : bs;
		OpB_translateRotated(&p1,dir,-side,1);
		Pos front = p1;
		OpB_translateRotated(&front,dir,side,0);
		if (opw7_cells[p1] == 3 && opw7_cells[front] == 3)
		{
			int span = 1;
			Pos p3 = front;
			vector<Pos> path;
			int k = 1;
			while (true)
			{
				if (span == rect.width)
					goto next;
				path.push_back(p3);
				OpB_translateRotated(&p3,dir,side,0);
				switch (opw7_cells[p3])
				{
					case 3: span++; break;
					case 4:
					case 6: goto extend;
					default: goto next;
				}
			}
		extend:
			while (true)
			{
				k++;
				vector<Pos> line;
				p3 = p1;
				OpB_translateRotated(&p3,dir,0,k - 1);
				for (int m = 0; m < span + 2; m++)
				{
					line.push_back(p3);
					OpB_translateRotated(&p3,dir,side,0);
				}
				for (unsigned int n = 0; n < line.size(); n++)
				{
					if (opw7_cells[line[n]] != 3 && opw7_cells[line[n]] != 4 && opw7_cells[line[n]] != 6)
						goto next;
				}
				for (unsigned int q = 1; q < line.size() - 1; q++)
				{
					if (opw7_cells[line[q]] == 4 || opw7_cells[line[q]] == 6)
						goto fill;
				}
				if (opw7_cells[line.back()] == 3)
					goto fill;
				path.insert(path.end(),line.begin() + 1,line.end() - 1);
			}
		fill:
			for (unsigned int i = 0; i < path.size(); i++)
				opw7_cells[path[i]] = 4;
			result = true;
		}
	next:
		if (side == 1)
			side = -1;
		else
			break;
	}
	return result;
}

struct OpW7_Box : public Rect	// NOTE: placeholder name
{
	OpW7_Box();	// 0x9cf970
};
extern vector<OpW7_Box> opw7_boxes;	// NOTE: placeholder name (0xd222f0, same object as opw7_d222f0)
int OpW7_maxIndex_9d50c0(int *values, unsigned int count);	// NOTE: placeholder name
void OpW7_sortRects_9d5110(vector<Rect> &v);	// NOTE: placeholder name
int OpW7_pickIndex_9d4b30(bool *values, unsigned int count, bool value);	// NOTE: placeholder name

void OpW7_Generator::fitCaves()
{
	int tries;
	int depths[4];
	int area[4];
	int inset[4];
	bool open[4];
	int direction;
	for (unsigned int i = 0; i < caves.size(); i++)
	{
		Rect &cave = caves[i];
		tries = 0;
		while (OpW7_measureWallEdges(cave,depths,area))
		{
			direction = OpW7_maxIndex_9d50c0(area,4);
			switch (direction)
			{
				case 0:
					cave.y += depths[direction];
					cave.height -= depths[direction];
					break;
				case 2:
					cave.height -= depths[direction];
					break;
				case 3:
					cave.x += depths[direction];
					cave.width -= depths[direction];
					break;
				case 1:
					cave.width -= depths[direction];
					break;
			}
			tries++;
			if (tries > 1000)
				break;
		}
		if (cave.width == 0 || cave.height == 0 || tries > 1000)
			OpW7_eraseIndex_9d5030(caves,i);
		else
		{
			if (OpW7_hasNonWall(cave))
			{
				OpW7_measureWallInset(cave,inset,area);
				direction = OpW7_maxIndex_9d50c0(area,4);
				switch (direction)
				{
					case 0:
						cave.set(cave.x,cave.y + cave.height - 1 - inset[direction],cave.width,inset[direction] + 1);
						break;
					case 2:
						cave.set(cave.x,cave.y,cave.width,inset[direction] + 1);
						break;
					case 3:
						cave.set(cave.x + cave.width - 1 - inset[direction],cave.y,inset[direction] + 1,cave.height);
						break;
					case 1:
						cave.set(cave.x,cave.y,inset[direction] + 1,cave.height);
						break;
				}
			}
			while (OpW7_findOpenSides(cave,open))
			{
				direction = OpW7_pickIndex_9d4b30(open,4,true);
				switch (direction)
				{
					case 0:
						cave.y--;
						cave.height++;
						break;
					case 2:
						cave.height++;
						break;
					case 3:
						cave.x--;
						cave.width++;
						break;
					case 1:
						cave.width++;
						break;
				}
			}
		}
	}
	for (unsigned int i = 0; i < caves.size(); i++)
	{
		if (caves[i].width < opw7_settings->unknown190[0] || caves[i].height < opw7_settings->unknown190[0])
			OpW7_eraseIndex_9d5030(caves,i);
	}
	OpW7_sortRects_9d5110(caves);
	Rect overlapAll;
	for (unsigned int i = 0; i < caves.size(); i++)
	{
		for (unsigned int j = i + 1; j < caves.size(); j++)
		{
			if (caves[i].touches_40aef0(caves[j]))
			{
				if (caves[i].equals_40a7e0(caves[j]))
					OpW7_eraseIndex_9d5030(caves,j);
				else if (caves[i].area_40ad00() > caves[j].area_40ad00())
				{
					if (caves[i].containsRect_40aa70(caves[j]))
						OpW7_eraseIndex_9d5030(caves,j);
					else
					{
						Rect &other = caves[j];
						caves[i].intersect_40ab30(other,overlapAll);
						other = OpW7_largestRemainder(other,overlapAll);
					}
				}
				else
				{
					if (caves[j].containsRect_40aa70(caves[i]))
					{
						OpW7_eraseIndex_9d5030(caves,i);
						break;
					}
					else
					{
						Rect &other = caves[i];
						caves[j].intersect_40ab30(other,overlapAll);
						other = OpW7_largestRemainder(other,overlapAll);
					}
				}
			}
		}
	}
	for (unsigned int i = 0; i < caves.size(); i++)
	{
		for (unsigned int j = i + 1; j < caves.size(); j++)
		{
			if (caves[i].containsRect_40aa70(caves[j]))
				OpW7_eraseIndex_9d5030(caves,j);
			else if (caves[j].containsRect_40aa70(caves[i]))
			{
				OpW7_eraseIndex_9d5030(caves,i);
				break;
			}
		}
	}
	OpW7_Box boxList;
	for (unsigned int i = 0; i < caves.size(); i++)
	{
		if (caves[i].width >= opw7_settings->unknown190[0] && caves[i].height >= opw7_settings->unknown190[0])
		{
			opw7_boxes.push_back(boxList);
			((Rect&)opw7_boxes.back()) = caves[i];
			Rect r(caves[i]);
			for (int x = r.x; x < r.x + r.width; x++)
			{
				for (int y = r.y; y < r.y + r.height; y++)
					opw7_grid.at(x,y) = 6;
			}
		}
	}
}

bool OpW7_widenCorner(const Rect &rect, int dir);	// NOTE: placeholder name

void OpW7_Generator::widenUnknown9c()
{
	bool changed;
	for (unsigned int i = 0; i < unknown9c.size(); i++)
	{
		changed = false;
		for (int dir = 0; dir < 4; dir++)
		{
			if (OpW7_widenCorner(unknown9c[i],dir))
				changed = true;
		}
		if (!changed)
			OpW7_eraseIndex_9d5030(unknown9c,i);
	}
}

extern vector<Rect> opw7_d222f0;	// NOTE: placeholder name
int OpW7_pickIndex_9d4b30(bool *values, unsigned int count, bool value);	// NOTE: placeholder name

void OpW7_Generator::growUnknown9c()
{
	bool open[4];
	int side;
	for (unsigned int i = 0; i < unknown9c.size(); i++)
	{
		for (unsigned int j = 0; j < opw7_d222f0.size(); j++)
		{
			if (opw7_d222f0[j].distance_40ae20(unknown9c[i]) == 0)
			{
				Rect &room = opw7_d222f0[j];
				side = -1;
				while (OpW7_findOpenSides(room,open))
				{
					side = OpW7_pickIndex_9d4b30(open,4,true);
					switch (side)
					{
						case 0:
							room.y--;
							room.height++;
							break;
						case 2:
							room.height++;
							break;
						case 3:
							room.x--;
							room.width++;
							break;
						case 1:
							room.width++;
							break;
					}
				}
				if (side != -1)
				{
					for (int x = room.x; x < room.x + room.width; x++)
					{
						for (int y = room.y; y < room.y + room.height; y++)
							opw7_grid.at(x,y) = 6;
					}
				}
			}
		}
	}
	unknown9c.clear();
}

extern int opw7_bb8340[4];	// NOTE: placeholder name
extern int opw7_bb8350[4];	// NOTE: placeholder name

bool OpW7_isClearSides(const Pos &pos, int dir, int length)	// NOTE: placeholder name
{
	Pos p;
	for (int side = 0; side < 2; side++)
	{
		p = pos;
		for (int i = 0; i < length; i++)
		{
			OpB_translateRotated(&p,side != 0 ? opw7_bb8350[dir] : opw7_bb8340[dir],0,1);
			if (!opw7_cells.contains(p) || opw7_cells[p] != 3)
				return false;
		}
	}
	return true;
}

struct OpW7_Struct_4c6aa0	// NOTE: placeholder name
{
	OpW7_Struct_4c6aa0();	// 0x4cd540
	~OpW7_Struct_4c6aa0();

	vector<Pos> path;	// NOTE: placeholder name
	vector<int> rooms;	// NOTE: placeholder name
};

OpW7_Struct_4c6aa0::~OpW7_Struct_4c6aa0()
{
}

void erasePointAt(vector<Pos> &v, int index);	// NOTE: placeholder name (0x9d5190)
template <class T> void removeVectorElement(vector<T> &v, int index);

void OpW7_Generator::removeBlockedDoors()
{
	for (unsigned int i = 0; i < opw7_rooms.size(); i++)
	{
		for (unsigned int j = 0; j < opw7_rooms[i].doors.size(); j++)
		{
			Pos p = opw7_rooms[i].doors[j];
			OpB_translateRotated(&p,opw7_rooms[i].doorDirs[j],0,1);
			if (opw7_cells[p] == 3)
			{
				opw7_cells[opw7_rooms[i].doors[j]] = 3;
				erasePointAt(opw7_rooms[i].doors,j);
				removeVectorElement(opw7_rooms[i].doorDirs,j);
				j--;
			}
		}
	}
}

extern int opw7_bb8360[4];	// NOTE: placeholder name (opposite direction)
extern vector<int> opw7_d2e224;	// NOTE: placeholder name (segment directions)
extern vector<int> opw7_cfb678;	// NOTE: placeholder name (segment lengths)
extern vector<OpW7_Struct_4c6aa0> opw7_cf65c4;	// NOTE: placeholder name
extern OpW7_CellMap opw7_cf447c;	// NOTE: placeholder name

bool OpW7_digCorridor(int roomIndex, const Pos &start, int dir)	// NOTE: placeholder name
{
	OpW7_RoomSettings *settingsList = &opw7_settings->rooms[opw7_rooms[roomIndex].type];
	int seg = 0;
	int backList = opw7_bb8360[dir];
	int turnsA = settingsList->turns;
	Pos pList = start;
	int len;
	opw7_d2e224[seg] = dir;
	opw7_cfb678[seg] = 0;
	while (turnsA != 0)
	{
		turnsA--;
		len = settingsList->segmentLength.randomInRange_40c130();
		while (len != 0)
		{
			len--;
			OpB_translateRotated(&pList,dir,0,1);
			opw7_cfb678[seg]++;
			if (!opw7_cells.contains(pList))
				return false;
			if (opw7_cells[pList] >= 4)
			{
				if (opw7_cells[pList] != 7)
					return false;
				else
				{
					OpW7_Struct_4c6aa0 corridor;
					opw7_cf65c4.push_back(corridor);
					vector<Pos> &path = opw7_cf65c4.back().path;
					pList = start;
					path.push_back(pList);
					for (int s = 0; s <= seg; s++)
					{
						for (int k = 0; k < opw7_cfb678[s]; k++)
						{
							OpB_translateRotated(&pList,opw7_d2e224[s],0,1);
							path.push_back(pList);
						}
					}
					int targetSet = -1;
					pList = path.back();
					for (unsigned int r = 0; r < opw7_rooms.size(); r++)
					{
						if (opw7_rooms[r].rect.containsPos_40aa00(pList))
						{
							targetSet = r;
							break;
						}
					}
					if (targetSet == -1)
					{
						opw7_cf65c4.pop_back();
						return false;
					}
					if (path.size() == 4)
					{
						opw7_cf65c4.pop_back();
						return false;
					}
					else
					{
						opw7_cf65c4.back().rooms.push_back(roomIndex);
						opw7_rooms[roomIndex].corridors.push_back(opw7_cf65c4.size() - 1);
						opw7_cf65c4.back().rooms.push_back(targetSet);
						opw7_rooms[targetSet].corridors.push_back(opw7_cf65c4.size() - 1);
						erasePointAt(path,0);
						path.pop_back();
						for (unsigned int m = 0; m < path.size(); m++)
							opw7_cf447c[path[m]] = 5;
						return true;
					}
				}
			}
			if (!OpW7_isClearSides(pList,dir,settingsList->clearance))
				return false;
		}
		int back2 = opw7_bb8360[dir];
		do
		{
			dir = rng.rangeInt(0,3.0f);
		} while (dir == backList || dir == back2);
		if (opw7_bb8360[dir] != back2)
		{
			Pos q = pList;
			if (!opw7_grid.inBounds(pList.x - 1,pList.y - 1) || opw7_grid.at(pList.x - 1,pList.y - 1) != 3 || !opw7_grid.inBounds(pList.x + 1,pList.y - 1) || opw7_grid.at(pList.x + 1,pList.y - 1) != 3 || !opw7_grid.inBounds(pList.x - 1,pList.y + 1) || opw7_grid.at(pList.x - 1,pList.y + 1) != 3 || !opw7_grid.inBounds(pList.x + 1,pList.y + 1) || opw7_grid.at(pList.x + 1,pList.y + 1) != 3)
				return false;
		}
		seg++;
		opw7_d2e224[seg] = dir;
		opw7_cfb678[seg] = 0;
	}
	return false;
}

void OpW7_removeElement_9d51d0(vector<unsigned int> &v, unsigned int value);	// NOTE: placeholder name
unsigned int OpW7_randomElement_9d5d00b(vector<unsigned int> &v);	// NOTE: placeholder name

void OpW7_Generator::addRoomCorridors()
{
	int dirs;
	int triesSet;
	for (int t = 0; t < 3; t++)
	{
		if (opw7_settings->rooms[t].corridorChance != 0)
			goto found;
	}
	return;
found:
	Pos pVec;
	for (unsigned int i = 0; i < opw7_rooms.size(); i++)
	{
		if (opw7_rooms[i].type != 3 && rng.chance(opw7_settings->rooms[opw7_rooms[i].type].corridorChance) && opw7_rooms[i].rect.width >= 3 && opw7_rooms[i].rect.height >= 3)
		{
			OpW7_Room &room = opw7_rooms[i];
			vector<unsigned int> dirsList;
			for (int d = 0; d < 4; d++)
				dirsList.push_back((unsigned int)d);
			for (unsigned int j = 0; j < room.doorDirs.size(); j++)
				OpW7_removeElement_9d51d0(dirsList,room.doorDirs[j]);
			if (!dirsList.empty())
			{
				triesSet = opw7_settings->rooms[opw7_rooms[i].type].corridorTries;
				do
				{
					dirs = OpW7_randomElement_9d5d00b(dirsList);
					switch (dirs)
					{
						case 0:
							pVec.set(rng.rangeInt(1,room.rect.width - 2) + room.rect.x,room.rect.y);
							break;
						case 1:
							pVec.set(room.rect.x + room.rect.width - 1,rng.rangeInt(0,room.rect.height - 1) + room.rect.y);
							break;
						case 2:
							pVec.set(rng.rangeInt(1,room.rect.width - 2) + room.rect.x,room.rect.y + room.rect.height - 1);
							break;
						case 3:
							pVec.set(room.rect.x,rng.rangeInt(1,room.rect.height - 2) + room.rect.y);
							break;
					}
					if (OpW7_digCorridor(i,pVec,dirs))
					{
						vector<Pos> &path = opw7_cf65c4.back().path;
						opw7_cells[path.front()] = opw7_cells[Pos(path.front(),0,-1)] == 7 || opw7_cells[Pos(path.front(),0,1)] == 7 ? 13 : 12;
						opw7_cells[path.back()] = opw7_cells[Pos(path.back(),0,-1)] == 7 || opw7_cells[Pos(path.back(),0,1)] == 7 ? 13 : 12;
						for (unsigned int k = 1; k < path.size() - 1; k++)
							opw7_cells[path[k]] = 4;
						break;
					}
				} while (--triesSet > 0);
			}
		}
	}
}

bool opw1_isBetween(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)

void OpW7_Generator::finalizeWalls()
{
	for (int x = 1; x < opw7_grid.getWidth() - 1; x++)
	{
		for (int y = 1; y < opw7_grid.getHeight() - 1; y++)
		{
			if (opw1_isBetween(0,opw7_grid.at(x,y),3) && opw7_grid.at(x - 1,y) <= 3 && opw7_grid.at(x + 1,y) <= 3 && opw7_grid.at(x,y - 1) <= 3 && opw7_grid.at(x,y + 1) <= 3 && opw7_grid.at(x - 1,y - 1) <= 3 && opw7_grid.at(x + 1,y - 1) <= 3 && opw7_grid.at(x - 1,y + 1) <= 3 && opw7_grid.at(x + 1,y + 1) <= 3)
				opw7_grid.at(x,y) = -1;
		}
	}
	opw7_grid.replace_9cf630(-1,4);
	opw7_grid.replace_9cf630(5,4);
	for (int x = 1; x < opw7_grid.getWidth() - 1; x++)
	{
		for (int y = 1; y < opw7_grid.getHeight() - 1; y++)
		{
			if (opw1_isBetween(0,opw7_grid.at(x,y),3) && opw7_grid.at(x - 1,y) != 7 && opw7_grid.at(x + 1,y) != 7 && opw7_grid.at(x,y - 1) != 7 && opw7_grid.at(x,y + 1) != 7 && opw7_grid.at(x - 1,y - 1) != 7 && opw7_grid.at(x + 1,y - 1) != 7 && opw7_grid.at(x - 1,y + 1) != 7 && opw7_grid.at(x + 1,y + 1) != 7)
				opw7_grid.at(x,y) = -1;
		}
	}
	opw7_grid.replace_9cf630(-1,4);
	for (int x = 0; x < opw7_grid.getWidth(); x++)
	{
		opw7_grid.at(x,0) = 2;
		if (opw7_grid.at(x,1) == 7)
			opw7_grid.at(x,1) = 0;
	}
	for (int x = 0; x < opw7_grid.getWidth(); x++)
	{
		opw7_grid.at(x,opw7_grid.getHeight() - 1) = 2;
		if (opw7_grid.at(x,opw7_grid.getHeight() - 2) == 7)
			opw7_grid.at(x,opw7_grid.getHeight() - 2) = 0;
	}
	for (int y = 1; y < opw7_grid.getHeight() - 1; y++)
	{
		opw7_grid.at(0,y) = 2;
		if (opw7_grid.at(1,y) == 7)
			opw7_grid.at(1,y) = 0;
	}
	for (int y = 1; y < opw7_grid.getHeight() - 1; y++)
	{
		opw7_grid.at(opw7_grid.getWidth() - 1,y) = 2;
		if (opw7_grid.at(opw7_grid.getWidth() - 2,y) == 7)
			opw7_grid.at(opw7_grid.getWidth() - 2,y) = 0;
	}
}

void OpW7_shuffle_9d8f80(vector<unsigned int> &v);	// NOTE: placeholder name
void OpW7_insertAt_9dbdc0(vector<unsigned int> &v, int index, unsigned int value);	// NOTE: placeholder name

bool OpW7_Generator::checkStarts()
{
	if (starts.size() != opw7_settings->spawns.size()) {}	// NOTE: presumably a compiled-out error macro (keeps the esi save)
	for (unsigned int i = 0; i < starts.size(); i++)
	{
		if (starts[i].x != -1 && opw7_settings->spawns[i].unknown08[2] != 3)
		{
			vector<unsigned int> dirs;
			for (int d = 0; d < 4; d++)
				dirs.push_back((unsigned int)d);
			OpW7_shuffle_9d8f80(dirs);
			if (opw7_settings->spawns[i].dirs.size() == 1)
			{
				OpW7_removeElement_9d51d0(dirs,opw7_settings->spawns[i].dirs.front());
				OpW7_insertAt_9dbdc0(dirs,0,opw7_settings->spawns[i].dirs.front());
			}
			Pos p;
			int w = opw7_settings->spawns[i].width.min;
			for (unsigned int j = 0; j < dirs.size(); j++)
			{
				p = starts[i];
				OpB_translateRotated(&p,dirs[j],w / 2,w / 2 + 1);
				if (opw7_cells[p] == 4)
				{
					starts[i] = p;
					goto found;
				}
			}
			return false;
found:
			if (opw7_settings->spawns[i].width.min >= 3)
			{
				for (int dx = -1; dx <= 1; dx++)
				{
					for (int dy = -1; dy <= 1; dy++)
					{
						if (dx != 0 || dy != 0)
						{
							Pos adj(p,dx,dy);
							if (opw7_cells[adj] != 4 && opw7_cells[adj] != 6)
								return false;
						}
					}
				}
			}
		}
	}
	return true;
}

void OpW7_shuffle_9d8f80b(vector<vector<Pos>*> &v);	// NOTE: placeholder name
enum OpW7_Dir {};	// NOTE: placeholder name (the loop pushing directions converted its counter)
void opW4_shuffle(vector<int> &v);	// NOTE: placeholder name (0x9d8f80)

unsigned int OpW7_Generator::traceRooms()
{
	unsigned int first = opw7_rooms.size();
	for (int x = 1; x < opw7_grid.getWidth() - 1; x++)
	{
		for (int y = 1; y < opw7_grid.getHeight() - 1; y++)
		{
			if (opw7_grid.at(x,y) == 1 && opw7_grid.at(x - 1,y) == 0 && opw7_grid.at(x,y - 1) == 0 && opw7_grid.at(x + 1,y) == 1 && opw7_grid.at(x,y + 1) == 1)
			{
				vector<Pos> points(1,Pos(x,y));
				Pos at(x,y);
				Pos dirEx(0);
				if (opw7_grid.at(x - 1,y) == 1)
					dirEx.x = -1;
				else if (opw7_grid.at(x,y - 1) == 1)
					dirEx.y = -1;
				else if (opw7_grid.at(x + 1,y) == 1)
					dirEx.x = 1;
				else if (opw7_grid.at(x,y + 1) == 1)
					dirEx.y = 1;
				if (dirEx.equals_409cb0(0,0))
					goto next;
				for (int steps = 0; ; steps++)
				{
					at.add_409a30(dirEx);
					if (opw7_cells[at] != 1)
					{
						at.sub_409a70(dirEx);
						points.push_back(at);
						if (points.size() == 4)
							break;
						Pos prev = at.minus_409b30(dirEx);
						dirEx.setBoth_409ff0(0);
						if (opw7_grid.at(at.x - 1,at.y) == 1 && prev.differs_409cf0(at.x - 1,at.y))
							dirEx.x = -1;
						else if (opw7_grid.at(at.x,at.y - 1) == 1 && prev.differs_409cf0(at.x,at.y - 1))
							dirEx.y = -1;
						else if (opw7_grid.at(at.x + 1,at.y) == 1 && prev.differs_409cf0(at.x + 1,at.y))
							dirEx.x = 1;
						else if (opw7_grid.at(at.x,at.y + 1) == 1 && prev.differs_409cf0(at.x,at.y + 1))
							dirEx.y = 1;
						if (dirEx.equals_409cb0(0,0))
							goto next;
					}
					if (steps > 999)
						goto next;
				}
				OpW7_Room room;
				opw7_rooms.push_back(room);
				OpW7_Room &r1 = opw7_rooms.back();
				r1.type = 3;
				Pos min = points.front();
				Pos bottomRight = points.front();
				for (unsigned int i = 1; i < points.size(); i++)
				{
					if (points[i].less_409c10(min))
						min = points[i];
					if (points[i].greater_409c60(bottomRight))
						bottomRight = points[i];
				}
				r1.rect.set_40a870(min,bottomRight.x - min.x + 1,bottomRight.y - min.y + 1);
				for (int x2 = min.x; x2 <= bottomRight.x; x2++)
				{
					opw7_grid.at(x2,min.y) = 7;
					opw7_grid.at(x2,bottomRight.y) = 7;
				}
				for (int y2 = min.y; y2 <= bottomRight.y; y2++)
				{
					opw7_grid.at(min.x,y2) = 7;
					opw7_grid.at(bottomRight.x,y2) = 7;
				}
				vector<Pos> startsEx;
				vector<Pos> ends;
				vector<vector<Pos>*> lists;
				lists.push_back(&startsEx);
				lists.push_back(&ends);
				vector<int> dirsList;
				for (OpW7_Dir d = (OpW7_Dir)0; d < 4; d = (OpW7_Dir)(d + 1))
					dirsList.push_back((int)d);
				opW4_shuffle(dirsList);
				for (unsigned int i = 0; i < dirsList.size(); i++)
				{
					OpW7_shuffle_9d8f80b(lists);
					switch (dirsList[i])
					{
						case 0:
							lists[0]->push_back(Pos(r1.rect.topLeft_40a970(),-1,-1));
							lists[1]->push_back(Pos(r1.rect.topRight_40ac60(),1,-1));
							break;
						case 1:
							lists[0]->push_back(Pos(r1.rect.topRight_40ac60(),1,-1));
							lists[1]->push_back(Pos(r1.rect.bottomRight_40acc0(),1,1));
							break;
						case 2:
							lists[0]->push_back(Pos(r1.rect.bottomLeft_40ac90(),-1,1));
							lists[1]->push_back(Pos(r1.rect.bottomRight_40acc0(),1,1));
							break;
						case 3:
							lists[0]->push_back(Pos(r1.rect.topLeft_40a970(),-1,-1));
							lists[1]->push_back(Pos(r1.rect.bottomLeft_40ac90(),-1,1));
							break;
					}
				}
				for (unsigned int i = 0; i < startsEx.size(); i++)
				{
					dirEx.set(startsEx[i].x != ends[i].x ? (ends[i].x >= startsEx[i].x ? 1 : -1) : 0,startsEx[i].x != ends[i].x ? 0 : (ends[i].y >= startsEx[i].y ? 1 : -1));
					at.set_40a030(startsEx[i]);
					while (at != ends[i])
					{
						at.add_409a30(dirEx);
						if (opw7_cells[at] == 1)
						{
							r1.doors.push_back(at);
							r1.doorDirs.push_back(dirsList[i]);
							at.add_409a30(dirEx);
							while (opw7_cells[at] == 1)
							{
								r1.doors.push_back(at);
								r1.doorDirs.push_back(dirsList[i]);
								at.add_409a30(dirEx);
							}
							for (unsigned int j = 0; j < r1.doors.size(); j++)
							{
								at = r1.doors[j];
								opw7_cells[at] = 7;
								r1.unknown5c.push_back(1);
								OpB_translateRotated(&at,r1.doorDirs[j],0,1);
								while (opw7_cells[at] == 1)
								{
									opw7_cells[at] = 7;
									r1.unknown5c.back()++;
									OpB_translateRotated(&at,r1.doorDirs[j],0,1);
								}
							}
							goto done;
						}
					}
				}
				opw7_rooms.pop_back();
done:
				r1.unknown58 = 0;
			}
next:
			;
		}
	}
	for (int x = 1; x < opw7_grid.getWidth() - 1; x++)
	{
		for (int y = 1; y < opw7_grid.getHeight() - 1; y++)
		{
			if (opw7_grid.at(x,y) == 1)
				opw7_grid.at(x,y) = 0;
		}
	}
	return first;
}

int OpW7_countSolidNeighbours(const Pos &pos)	// NOTE: placeholder name
{
	int count = 0;
	if (opw7_grid.inBounds(pos.x - 1,pos.y) && opw7_grid.at(pos.x - 1,pos.y) >= 4)
		count++;
	if (opw7_grid.inBounds(pos.x,pos.y - 1) && opw7_grid.at(pos.x,pos.y - 1) >= 4)
		count++;
	if (opw7_grid.inBounds(pos.x,pos.y + 1) && opw7_grid.at(pos.x,pos.y + 1) >= 4)
		count++;
	if (opw7_grid.inBounds(pos.x + 1,pos.y) && opw7_grid.at(pos.x + 1,pos.y) >= 4)
		count++;
	return count;
}

struct OpW7_Segment	// NOTE: placeholder name
{
	OpW7_Segment();	// 0x40b100

	Pos a;
	Pos b;
};

struct OpW7_BridgeSpec	// NOTE: placeholder name (0x34 bytes)
{
	bool enabled;	// NOTE: placeholder name
	int level;	// NOTE: placeholder name
	int unknown08[2];	// NOTE: placeholder name
	OpW7_Range8 x;	// NOTE: placeholder name
	OpW7_Range8 y;	// NOTE: placeholder name
	int dir;	// NOTE: placeholder name
	OpW7_Range8 width;	// NOTE: placeholder name
	OpW7_Range8 lineLength;	// NOTE: placeholder name
};

struct OpW7_Bridge	// NOTE: placeholder name (0x24 bytes)
{
	Pos pos;	// NOTE: placeholder name
	int dir;	// NOTE: placeholder name
	int width;	// NOTE: placeholder name
	OpW7_Segment segment;	// NOTE: placeholder name
	int maxSteps;	// NOTE: placeholder name
};

struct OpW7_CaveSettings	// NOTE: placeholder name (object at *0xcefb54)
{
	void load(istream &in);	// NOTE: placeholder name

	int unknown00;	// NOTE: placeholder name
	int unknown04;	// NOTE: placeholder name
	int unknown08;	// NOTE: placeholder name
	OpW7_Range8 sizeRange;	// NOTE: placeholder name
	int fillNeighbours;	// NOTE: placeholder name
	int clearNeighbours;	// NOTE: placeholder name
	int unknown1C;	// NOTE: placeholder name
	float unknown20;	// NOTE: placeholder name
	int unknown24;	// NOTE: placeholder name
	int unknown28;	// NOTE: placeholder name
	int clearance;	// NOTE: placeholder name
	OpW7_Range8 segmentLength;	// NOTE: placeholder name
	int turns;	// NOTE: placeholder name
	int unknown3C;	// NOTE: placeholder name
	float unknown40;	// NOTE: placeholder name
	int unknown44;	// NOTE: placeholder name
	vector<Rect> regions;	// NOTE: placeholder name
	int unknown58;	// NOTE: placeholder name
	int unknown5C;	// NOTE: placeholder name
	int unknown60;	// NOTE: placeholder name
	int unknown64;	// NOTE: placeholder name
	int unknown68;	// NOTE: placeholder name
	int unknown6C;	// NOTE: placeholder name
	OpW7_Blob10 unknown70;	// NOTE: placeholder name
	vector<OpW7_BridgeSpec> bridges;	// NOTE: placeholder name
	OpW7_Range8 unknown90;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
	int unknown9C;	// NOTE: placeholder name
	int unknownA0;	// NOTE: placeholder name
};
extern OpW7_CaveSettings *opw7_caveSettings;	// NOTE: placeholder name
struct OpW7_Struct_4ccdc0	// NOTE: placeholder name (a cave area)
{
	OpW7_Struct_4ccdc0();	// 0x4ccd70
	~OpW7_Struct_4ccdc0();

	vector<Pos> cells;	// NOTE: placeholder name
	vector<int> unknown10;	// NOTE: placeholder name
	vector<Pos> unknown20;	// NOTE: placeholder name
	vector<int> unknown30;	// NOTE: placeholder name
	int unknown40;	// NOTE: placeholder name
	bool unknown44;	// NOTE: placeholder name
	bool masked;	// NOTE: placeholder name
	Pos unknown48;	// NOTE: placeholder name
	bool touchesRect;	// NOTE: placeholder name
};
extern vector<OpW7_Struct_4ccdc0> opw7_cf126c;	// NOTE: placeholder name (cave areas)

class OpW7_CaveGen	// NOTE: placeholder name
{
public:
	void fillPass();	// NOTE: placeholder name
	void clearPass();	// NOTE: placeholder name
	bool canLabel(int x, int y);	// NOTE: placeholder name
	void label(int x, int y, int id);	// NOTE: placeholder name
	bool canLabelMasked(int x, int y);	// NOTE: placeholder name
	void labelMasked(int x, int y, int id);	// NOTE: placeholder name
	bool isOpen(const Pos &pos);	// NOTE: placeholder name
	bool isOpenAround(const Pos &pos);	// NOTE: placeholder name
	void pickEdge(int area, Pos &pos, int &dir);	// NOTE: placeholder name
	bool isClearSides(const Pos &pos, int dir, int length);	// NOTE: placeholder name
	int findAreas();	// NOTE: placeholder name
	bool pickCorridorStart(Pos &pos, int &dir);	// NOTE: placeholder name
	bool digTunnel(const Pos &start, int dir, vector<int> &targets);	// NOTE: placeholder name
	bool isLineClear(Pos pos, int dir, bool reverse, int count, int areaA, int areaB);	// NOTE: placeholder name
	void flood(vector<int> &found, OpW7_CellGrid &visited, int x, int y);	// NOTE: placeholder name
	void linkAreas(OpW7_CellGrid &visited, int x, int y);	// NOTE: placeholder name
	void computeLinks();	// NOTE: placeholder name
	bool hasForeignDiagonal(const Pos &pos, int area);	// NOTE: placeholder name
	bool traceBridge(Pos pos, int dir, int width, int lineLength, int maxSteps, vector<Pos> &out, const OpW7_Segment &segment = OpW7_Segment());	// NOTE: placeholder name
	bool placeBridges();	// NOTE: placeholder name
	bool widenPath(bool flip);	// NOTE: placeholder name
	void straightenPath(bool fromEnd);	// NOTE: placeholder name
	void boxCaves();	// NOTE: placeholder name
	bool connectAreas(int mode);	// NOTE: placeholder name
	void sprout();	// NOTE: placeholder name
	void seed();	// NOTE: placeholder name
	bool step(bool singleStep);	// NOTE: placeholder name

	int unknown00[0x40 / 4];	// NOTE: placeholder name
	vector<OpW7_Bridge> bridges;	// NOTE: placeholder name
	int level;	// NOTE: placeholder name
	int unknown54;	// NOTE: placeholder name
	OpW7_CellGrid mask;	// NOTE: placeholder name
	OpW7_CellGrid labels;	// NOTE: placeholder name
	OpW7_CellGrid unknown70;	// NOTE: placeholder name
	int connectTries;	// NOTE: placeholder name
	int bridgeFailures;	// NOTE: placeholder name
	bool finished;	// NOTE: placeholder name
	bool failed;	// NOTE: placeholder name
};

void OpW7_CaveGen::fillPass()
{
	for (int pass = 0; pass < 5; pass++)
	{
		for (int x = 0; x < opw7_grid.getWidth(); x++)
		{
			for (int y = 0; y < opw7_grid.getHeight(); y++)
			{
				if (opw7_grid.at(x,y) <= 3 && mask.at(x,y) == 0 && OpW7_countSolidNeighbours(Pos(x,y)) >= opw7_caveSettings->fillNeighbours)
					opw7_grid.at(x,y) = 8;
			}
		}
	}
}

void OpW7_CaveGen::clearPass()
{
	for (int pass = 0; pass < 5; pass++)
	{
		for (int x = 0; x < opw7_grid.getWidth(); x++)
		{
			for (int y = 0; y < opw7_grid.getHeight(); y++)
			{
				if (opw7_grid.at(x,y) >= 4 && mask.at(x,y) == 0 && 4 - OpW7_countSolidNeighbours(Pos(x,y)) >= opw7_caveSettings->clearNeighbours)
					opw7_grid.at(x,y) = 3;
			}
		}
	}
}

bool OpW7_CaveGen::canLabel(int x, int y)
{
	return opw7_grid.inBounds(x,y) && labels.at(x,y) == -1 && opw7_grid.at(x,y) == 8 && mask.at(x,y) == 0;
}

void OpW7_CaveGen::label(int x, int y, int id)
{
	if (canLabel(x - 1,y))
	{
		opw7_cf126c[id].cells.push_back(Pos(x - 1,y));
		labels.at(x - 1,y) = id;
		label(x - 1,y,id);
	}
	if (canLabel(x,y - 1))
	{
		opw7_cf126c[id].cells.push_back(Pos(x,y - 1));
		labels.at(x,y - 1) = id;
		label(x,y - 1,id);
	}
	if (canLabel(x,y + 1))
	{
		opw7_cf126c[id].cells.push_back(Pos(x,y + 1));
		labels.at(x,y + 1) = id;
		label(x,y + 1,id);
	}
	if (canLabel(x + 1,y))
	{
		opw7_cf126c[id].cells.push_back(Pos(x + 1,y));
		labels.at(x + 1,y) = id;
		label(x + 1,y,id);
	}
}

bool OpW7_CaveGen::canLabelMasked(int x, int y)
{
	return opw7_grid.inBounds(x,y) && labels.at(x,y) == -1 && opw7_grid.at(x,y) == 8 && mask.at(x,y) != 0;
}

void OpW7_CaveGen::labelMasked(int x, int y, int id)
{
	if (canLabelMasked(x - 1,y))
	{
		opw7_cf126c[id].cells.push_back(Pos(x - 1,y));
		labels.at(x - 1,y) = id;
		labelMasked(x - 1,y,id);
	}
	if (canLabelMasked(x,y - 1))
	{
		opw7_cf126c[id].cells.push_back(Pos(x,y - 1));
		labels.at(x,y - 1) = id;
		labelMasked(x,y - 1,id);
	}
	if (canLabelMasked(x,y + 1))
	{
		opw7_cf126c[id].cells.push_back(Pos(x,y + 1));
		labels.at(x,y + 1) = id;
		labelMasked(x,y + 1,id);
	}
	if (canLabelMasked(x + 1,y))
	{
		opw7_cf126c[id].cells.push_back(Pos(x + 1,y));
		labels.at(x + 1,y) = id;
		labelMasked(x + 1,y,id);
	}
}

int OpW7_countSolidAround(const Pos &pos)	// NOTE: placeholder name
{
	int count = 0;
	if (opw7_grid.inBounds(pos.x - 1,pos.y - 1) && opw7_grid.at(pos.x - 1,pos.y - 1) >= 4)
		count++;
	if (opw7_grid.inBounds(pos.x - 1,pos.y) && opw7_grid.at(pos.x - 1,pos.y) >= 4)
		count++;
	if (opw7_grid.inBounds(pos.x - 1,pos.y + 1) && opw7_grid.at(pos.x - 1,pos.y + 1) >= 4)
		count++;
	if (opw7_grid.inBounds(pos.x,pos.y - 1) && opw7_grid.at(pos.x,pos.y - 1) >= 4)
		count++;
	if (opw7_grid.inBounds(pos.x,pos.y + 1) && opw7_grid.at(pos.x,pos.y + 1) >= 4)
		count++;
	if (opw7_grid.inBounds(pos.x + 1,pos.y - 1) && opw7_grid.at(pos.x + 1,pos.y - 1) >= 4)
		count++;
	if (opw7_grid.inBounds(pos.x + 1,pos.y) && opw7_grid.at(pos.x + 1,pos.y) >= 4)
		count++;
	if (opw7_grid.inBounds(pos.x + 1,pos.y + 1) && opw7_grid.at(pos.x + 1,pos.y + 1) >= 4)
		count++;
	if (opw7_cells[pos] >= 4)
		count++;
	return count;
}

void OpW7_CaveGen::seed()
{
	for (int x = 2; x < opw7_grid.getWidth() - 2; x++)
	{
		for (int y = 2; y < opw7_grid.getHeight() - 2; y++)
		{
			if (rng.chance(opw7_caveSettings->unknown00) && mask.at(x,y) == 0)
				opw7_grid.at(x,y) = 8;
		}
	}
	Pos pos;
	for (int i = 0; i < opw7_caveSettings->unknown08; i++)
	{
		opw7_grid.randomPos(pos);
		if (mask[pos] == 0)
			opw7_grid[pos] = OpW7_countSolidAround(pos) > opw7_caveSettings->unknown04 ? 8 : 3;
	}
}

bool OpW7_hasSolidDiagonal(const Pos &pos)	// NOTE: placeholder name
{
	return (opw7_grid.inBounds(pos.x - 1,pos.y - 1) && opw7_grid.at(pos.x - 1,pos.y - 1) >= 4) || (opw7_grid.inBounds(pos.x + 1,pos.y - 1) && opw7_grid.at(pos.x + 1,pos.y - 1) >= 4) || (opw7_grid.inBounds(pos.x - 1,pos.y + 1) && opw7_grid.at(pos.x - 1,pos.y + 1) >= 4) || (opw7_grid.inBounds(pos.x + 1,pos.y + 1) && opw7_grid.at(pos.x + 1,pos.y + 1) >= 4);
}

OpW7_Struct_4ccdc0::~OpW7_Struct_4ccdc0()
{
}

extern vector<OpW7_Struct_4c6aa0> opw7_cf125c;	// NOTE: placeholder name
bool opW5_contains(vector<int> &values, int value);	// NOTE: placeholder name (0x9db330)

bool OpW7_CaveGen::isOpen(const Pos &pos)
{
	return opw7_cells.contains(pos) && (opw7_cells[pos] == 3 || unknown70[pos] == opw7_cf125c.size() - 1 || opW5_contains(opw7_cf125c.back().rooms,labels[pos]));
}

bool OpW7_CaveGen::isOpenAround(const Pos &pos)
{
	return opw7_cells.contains(pos) && isOpen(Pos(pos.x - 1,pos.y - 1)) && isOpen(Pos(pos.x - 1,pos.y)) && isOpen(Pos(pos.x - 1,pos.y + 1)) && isOpen(Pos(pos.x,pos.y - 1)) && isOpen(Pos(pos.x,pos.y + 1)) && isOpen(Pos(pos.x + 1,pos.y - 1)) && isOpen(Pos(pos.x + 1,pos.y)) && isOpen(Pos(pos.x + 1,pos.y + 1));
}

Pos OpW7_randomPos_9d5350(vector<Pos> &v);	// NOTE: placeholder name

void OpW7_CaveGen::pickEdge(int area, Pos &pos, int &dir)
{
	do
	{
		pos = OpW7_randomPos_9d5350(opw7_cf126c[area].cells);
		dir = rng.rangeInt(0,3.0f);
		do
		{
			OpB_translateRotated(&pos,dir,0,1);
		} while (opw7_cells.contains(pos) && labels[pos] == area);
	} while (opw7_cells.contains(pos) && opw7_cells[pos] != 3);
}

bool OpW7_CaveGen::isClearSides(const Pos &pos, int dir, int length)
{
	Pos p;
	for (int side = 0; side < 2; side++)
	{
		p = pos;
		for (int i = 0; i < length; i++)
		{
			OpB_translateRotated(&p,side != 0 ? opw7_bb8350[dir] : opw7_bb8340[dir],0,1);
			if (!opw7_cells.contains(p) || opw7_cells[p] != 3)
				return false;
		}
	}
	return true;
}

extern vector<Rect> opw7_d39d30;	// NOTE: placeholder name
extern int opw7_ced16c;	// NOTE: placeholder name (largest cave size)

int OpW7_CaveGen::findAreas()
{
	OpW7_Struct_4ccdc0 cave;
	for (int x = 0; x < opw7_grid.getWidth(); x++)
	{
		for (int y = 0; y < opw7_grid.getHeight(); y++)
		{
			if (opw7_grid.at(x,y) == 8 && labels.at(x,y) == -1)
			{
				opw7_cf126c.push_back(cave);
				OpW7_Struct_4ccdc0 *c = &opw7_cf126c.back();
				c->cells.push_back(Pos(x,y));
				labels.at(x,y) = opw7_cf126c.size() - 1;
				if (mask.at(x,y) != 0)
				{
					labelMasked(x,y,opw7_cf126c.size() - 1);
					c->masked = true;
				}
				else
				{
					label(x,y,opw7_cf126c.size() - 1);
					c->masked = false;
				}
				c->unknown44 = false;
				c->unknown48.x = -1;
				c->touchesRect = false;
				for (unsigned int i = 0; i < opw7_d39d30.size(); i++)
				{
					for (unsigned int j = 0; j < c->cells.size(); j++)
					{
						if (opw7_d39d30[i].containsPos_40aa00(c->cells[j]))
						{
							c->touchesRect = true;
							break;
						}
					}
				}
				if (!c->masked && opw7_caveSettings->sizeRange.max > 0 && !opw7_caveSettings->sizeRange.contains_40c190(c->cells.size()))
				{
					for (unsigned int k = 0; k < c->cells.size(); k++)
					{
						opw7_cells[c->cells[k]] = 3;
						labels[c->cells[k]] = -1;
					}
					opw7_cf126c.pop_back();
				}
				else if (c->cells.size() > opw7_ced16c)
					opw7_ced16c = c->cells.size();
			}
		}
	}
	return opw7_cf126c.size();
}

int OpW7_randomIndex_9d5310(const vector<OpW7_Struct_4c6aa0> &v);	// NOTE: placeholder name
extern vector<int> opw7_d1defc;	// NOTE: placeholder name

bool OpW7_CaveGen::pickCorridorStart(Pos &pos, int &dir)
{
	int numDirs = -1;
	int attempts = 0;
	do
	{
		attempts++;
		if (attempts > 100)
			return false;
		int index = OpW7_randomIndex_9d5310(opw7_cf125c);
		if (((const vector<OpW7_Struct_4c6aa0>&)opw7_cf125c)[index].path.size() < 3)
			continue;
		pos = const_cast<vector<Pos>&>(((const vector<OpW7_Struct_4c6aa0>&)opw7_cf125c)[index].path)[rng.rangeInt(1,((const vector<OpW7_Struct_4c6aa0>&)opw7_cf125c)[index].path.size() - 2)];
		if (opw7_grid.inBounds(pos.x - 1,pos.y) && opw7_grid.at(pos.x - 1,pos.y) == 3)
		{
			numDirs++;
			opw7_d1defc[numDirs] = 3;
		}
		if (opw7_grid.inBounds(pos.x,pos.y - 1) && opw7_grid.at(pos.x,pos.y - 1) == 3)
		{
			numDirs++;
			opw7_d1defc[numDirs] = 0;
		}
		if (opw7_grid.inBounds(pos.x,pos.y + 1) && opw7_grid.at(pos.x,pos.y + 1) == 3)
		{
			numDirs++;
			opw7_d1defc[numDirs] = 2;
		}
		if (opw7_grid.inBounds(pos.x + 1,pos.y) && opw7_grid.at(pos.x + 1,pos.y) == 3)
		{
			numDirs++;
			opw7_d1defc[numDirs] = 1;
		}
	} while (numDirs == -1);
	dir = opw7_d1defc[rng.rangeInt(0,numDirs)];
	OpB_translateRotated(&pos,dir,0,1);
	return true;
}

extern vector<int> opw7_d1ecc0;	// NOTE: placeholder name (segment directions)
extern vector<int> opw7_cf4590;	// NOTE: placeholder name (segment lengths)

bool OpW7_CaveGen::digTunnel(const Pos &start, int dir, vector<int> &targets)
{
	int seg = 0;
	int backList = opw7_bb8360[dir];
	int turnsA = opw7_caveSettings->turns;
	Pos pList = start;
	int len;
	opw7_d1ecc0[seg] = dir;
	opw7_cf4590[seg] = 0;
	while (turnsA != 0)
	{
		turnsA--;
		len = opw7_caveSettings->segmentLength.randomInRange_40c130();
		while (len != 0)
		{
			len--;
			OpB_translateRotated(&pList,dir,0,1);
			opw7_cf4590[seg]++;
			if (!opw7_cells.contains(pList) || mask[pList] != 0)
				return false;
			if (opw7_cells[pList] >= 4)
			{
				if (labels[pList] == -1 || !opW5_contains(targets,labels[pList]))
					return false;
				else
				{
					OpW7_Struct_4c6aa0 corridor;
					opw7_cf125c.push_back(corridor);
					vector<Pos> &route = opw7_cf125c.back().path;
					pList = start;
					route.push_back(pList);
					for (int s = 0; s <= seg; s++)
					{
						for (int k = 0; k < opw7_cf4590[s]; k++)
						{
							OpB_translateRotated(&pList,opw7_d1ecc0[s],0,1);
							route.push_back(pList);
						}
					}
					return true;
				}
			}
			if (!isClearSides(pList,dir,opw7_caveSettings->clearance))
				return false;
		}
		int back2 = opw7_bb8360[dir];
		do
		{
			dir = rng.rangeInt(0,3.0f);
		} while (dir == backList || dir == back2);
		seg++;
		opw7_d1ecc0[seg] = dir;
		opw7_cf4590[seg] = 0;
	}
	return false;
}

void OpW7_read_9d5250(istream &in, vector<Rect> *value);
void readInt(istream &in, float *value);	// NOTE: folded with the int version (0x9d8480)	// NOTE: placeholder name
void OpW7_read_9d52b0(istream &in, vector<OpW7_BridgeSpec> *value);	// NOTE: placeholder name

void OpW7_CaveSettings::load(istream &in)
{
	readInt(in,&unknown00);
	readInt(in,&unknown04);
	readInt(in,&unknown08);
	sizeRange.load(in);
	readInt(in,&fillNeighbours);
	readInt(in,&clearNeighbours);
	readInt(in,&unknown1C);
	readInt(in,&unknown20);
	readInt(in,&unknown24);
	readInt(in,&unknown28);
	readInt(in,&clearance);
	segmentLength.load(in);
	readInt(in,&turns);
	readInt(in,&unknown3C);
	readInt(in,&unknown40);
	readInt(in,&unknown44);
	OpW7_read_9d5250(in,&regions);
	readInt(in,&unknown58);
	readInt(in,&unknown5C);
	readInt(in,&unknown60);
	readInt(in,&unknown64);
	readInt(in,&unknown68);
	readInt(in,&unknown6C);
	OpW7_read_9d4d70(in,&unknown70);
	OpW7_read_9d52b0(in,&bridges);
	unknown90.load(in);
	readInt(in,&unknown98);
	readInt(in,&unknown9C);
	readInt(in,&unknownA0);
}

bool OpW7_CaveGen::isLineClear(Pos pos, int dir, bool reverse, int count, int areaA, int areaB)
{
	do
	{
		OpB_translateRotated(&pos,dir,reverse ? -1 : 1,0);
		if ((!opw7_cells.contains(pos) || opw7_cells[pos] >= 4) && (areaA == -1 || labels[pos] != areaA) && (areaB == -1 || unknown70[pos] != areaB))
			return false;
	} while (--count);
	return true;
}

void OpW7_addUnique_9db000(vector<int> &v, int value);	// NOTE: placeholder name

void OpW7_CaveGen::flood(vector<int> &found, OpW7_CellGrid &visited, int x, int y)
{
	visited.at(x,y) = 1;
	if (labels.at(x,y) != -1)
		OpW7_addUnique_9db000(found,labels.at(x,y));
	else if (opw7_grid.at(x,y) == 9)
	{
		if (opw7_grid.inBounds(x - 1,y) && visited.at(x - 1,y) == 0)
			flood(found,visited,x - 1,y);
		if (opw7_grid.inBounds(x + 1,y) && visited.at(x + 1,y) == 0)
			flood(found,visited,x + 1,y);
		if (opw7_grid.inBounds(x,y - 1) && visited.at(x,y - 1) == 0)
			flood(found,visited,x,y - 1);
		if (opw7_grid.inBounds(x,y + 1) && visited.at(x,y + 1) == 0)
			flood(found,visited,x,y + 1);
	}
}

void OpW7_CaveGen::linkAreas(OpW7_CellGrid &visited, int x, int y)
{
	vector<int> found;
	flood(found,visited,x,y);
	for (unsigned int i = 0; i < found.size(); i++)
	{
		for (unsigned int j = 0; j < found.size(); j++)
		{
			if (j != i)
				OpW7_addUnique_9db000(opw7_cf126c[found[i]].unknown30,found[j]);
		}
	}
}

void OpW7_CaveGen::computeLinks()
{
	OpW7_CellGrid visited(opw7_caveSettings->unknown64,opw7_caveSettings->unknown68,0);
	for (int x = 0; x < visited.getWidth(); x++)
	{
		for (int y = 0; y < visited.getHeight(); y++)
		{
			if (opw7_grid.at(x,y) == 9 && visited.at(x,y) == 0)
				linkAreas(visited,x,y);
		}
	}
	for (unsigned int i = 0; i < opw7_cf126c.size(); i++)
	{
		opw7_cf126c[i].unknown40 = opw7_cf126c[i].unknown30.size();
		for (unsigned int j = 0; j < opw7_cf126c[i].unknown30.size(); j++)
			opw7_cf126c[i].unknown40 += opw7_cf126c[opw7_cf126c[i].unknown30[j]].unknown30.size();
	}
}

void OpW7_CaveGen::sprout()
{
	int chance = opw7_caveSettings->unknown44;
	Pos p;
	for (unsigned int i = 0; i < opw7_cf125c.size(); i++)
	{
		const OpW7_Struct_4c6aa0 &c = ((const vector<OpW7_Struct_4c6aa0>&)opw7_cf125c)[i];
		for (int j = c.path.size() - 1; j >= 0; j--)
		{
			p = const_cast<vector<Pos>&>(c.path)[j];
			if (opw7_grid.isEdge_9b7960(p))
				continue;
			for (int dx = -1; dx <= 1; dx++)
			{
				for (int dy = -1; dy <= 1; dy++)
				{
					if ((dx != 0 || dy != 0) && opw7_grid.at(p.x + dx,p.y + dy) == 3 && rng.chance(chance))
					{
						opw7_grid.at(p.x + dx,p.y + dy) = 9;
						unknown70[opw7_grid.at(p.x + dx,p.y + dy)] = i;
						const_cast<vector<Pos>&>(((const vector<OpW7_Struct_4c6aa0>&)opw7_cf125c)[i].path).push_back(Pos(p.x + dx,p.y + dy));
					}
				}
			}
		}
	}
}

bool OpW7_CaveGen::hasForeignDiagonal(const Pos &pos, int area)
{
	return (opw7_grid.inBounds(pos.x - 1,pos.y - 1) && opw7_grid.at(pos.x - 1,pos.y - 1) >= 4 && labels.at(pos.x - 1,pos.y - 1) != area && (opw7_grid.at(pos.x - 1,pos.y - 1) != 9 || !opW5_contains(opw7_cf126c[area].unknown10,unknown70.at(pos.x - 1,pos.y - 1)))) || (opw7_grid.inBounds(pos.x + 1,pos.y - 1) && opw7_grid.at(pos.x + 1,pos.y - 1) >= 4 && labels.at(pos.x + 1,pos.y - 1) != area && (opw7_grid.at(pos.x + 1,pos.y - 1) != 9 || !opW5_contains(opw7_cf126c[area].unknown10,unknown70.at(pos.x + 1,pos.y - 1)))) || (opw7_grid.inBounds(pos.x - 1,pos.y + 1) && opw7_grid.at(pos.x - 1,pos.y + 1) >= 4 && labels.at(pos.x - 1,pos.y + 1) != area && (opw7_grid.at(pos.x - 1,pos.y + 1) != 9 || !opW5_contains(opw7_cf126c[area].unknown10,unknown70.at(pos.x - 1,pos.y + 1)))) || (opw7_grid.inBounds(pos.x + 1,pos.y + 1) && opw7_grid.at(pos.x + 1,pos.y + 1) >= 4 && labels.at(pos.x + 1,pos.y + 1) != area && (opw7_grid.at(pos.x + 1,pos.y + 1) != 9 || !opW5_contains(opw7_cf126c[area].unknown10,unknown70.at(pos.x + 1,pos.y + 1))));
}

bool OpW7_anyPositive_9d54c0(vector<int> &v);	// NOTE: placeholder name

bool OpW7_CaveGen::traceBridge(Pos pos, int dir, int width, int lineLength, int maxSteps, vector<Pos> &out, const OpW7_Segment &segment)
{
	vector<int> widthsVec;
	int areaA = -1;
	int areaB2 = -1;
	Pos q = pos;
	do
	{
		OpB_translateRotated(&q,dir,0,1);
		if (!opw7_cells.contains(q))
			goto fail;
		if (opw7_cells[q] == 8)
			areaA = labels[q];
		else if (opw7_cells[q] == 9)
		{
			if (unknown70[q] != -1)
				areaB2 = unknown70[q];
			else
				goto fail;
		}
	} while (areaA == -1 && areaB2 == -1);
	int stepsList = 0;
	while (true)
	{
		stepsList++;
		if (maxSteps != 0 && stepsList > maxSteps)
			goto fail;
		OpB_translateRotated(&pos,dir,0,1);
		Pos p = pos;
		for (int i = 0; i < width; i++)
		{
			if (widthsVec.empty() || widthsVec[i] > 0)
			{
				if (!opw7_cells.contains(p) || opw7_cells[p] == 2)
					goto fail;
				if (opw7_cells[p] >= 4)
				{
					if (widthsVec.empty())
					{
						for (int k = 0; k < width; k++)
							widthsVec.push_back(width);
					}
					widthsVec[i] = 0;
				}
				if (!widthsVec.empty())
					widthsVec[i]--;
				if (widthsVec.empty() || widthsVec[i] > 0)
					out.push_back(p);
			}
			if (!widthsVec.empty() && !OpW7_anyPositive_9d54c0(widthsVec))
				goto success;
			OpB_translateRotated(&p,dir,1,0);
		}
		if (widthsVec.empty() || widthsVec.front() > 0)
		{
			if (!isLineClear(pos,dir,true,lineLength,areaA,areaB2))
				goto fail;
		}
		OpB_translateRotated(&p,dir,-1,0);
		if (widthsVec.empty() || widthsVec.back() > 0)
		{
			if (!isLineClear(p,dir,false,lineLength,areaA,areaB2))
				goto fail;
		}
	}
success:
	return true;
fail:
	out.clear();
	return false;
}

bool OpW7_CaveGen::placeBridges()
{
	vector<Pos> path;
	for (unsigned int i = 0; i < opw7_caveSettings->bridges.size(); i++)
	{
		if (opw7_caveSettings->bridges[i].enabled && (opw7_caveSettings->bridges[i].level == level || opw7_caveSettings->bridges[i].level == 0))
		{
			OpW7_BridgeSpec &spec = opw7_caveSettings->bridges[i];
			int tries = 0;
			while (tries < 10)
			{
				if (traceBridge(Pos(spec.x.randomInRange_40c130(),spec.y.randomInRange_40c130()),spec.dir,spec.width.randomInRange_40c130(),spec.lineLength.randomInRange_40c130(),0,path))
				{
					for (unsigned int k = 0; k < path.size(); k++)
						opw7_cells[path[k]] = 4;
					path.clear();
					tries = -1;
					break;
				}
				tries++;
			}
			if (tries != -1)
				return false;
		}
	}
	for (unsigned int j = 0; j < bridges.size(); j++)
	{
		OpW7_Bridge &bridge = bridges[j];
		if (!traceBridge(bridge.pos,bridge.dir,bridge.width,1,bridge.maxSteps,path,bridge.segment))
			return false;
		for (unsigned int m = 0; m < path.size(); m++)
			opw7_cells[path[m]] = 4;
		path.clear();
	}
	return true;
}

int OpW7_dirBetween_4491a0(const Pos &a, const Pos &b);	// NOTE: placeholder name

bool OpW7_CaveGen::widenPath(bool flip)
{
	vector<Pos> &paths = opw7_cf125c.back().path;
	if (paths.size() == 1)
		return false;
	vector<Pos> addeds;
	int dirs = OpW7_dirBetween_4491a0(paths[0],paths[1]);
	unsigned int i = 0;
	Pos pVec = paths[i];
	int next2;
	OpB_translateRotated(&pVec,dirs,flip ? -1 : 1,-1);
	if (opw7_cells[pVec] == 3)
		addeds.push_back(pVec);
	OpB_translateRotated(&pVec,dirs,0,1);
	if (!isOpenAround(pVec))
		return false;
	if (opw7_cells[pVec] == 3)
		addeds.push_back(pVec);
	while (true)
	{
		next2 = i >= paths.size() - 1 ? dirs : OpW7_dirBetween_4491a0(paths[i],paths[i + 1]);
		while (next2 == dirs)
		{
			i++;
			OpB_translateRotated(&pVec,dirs,0,1);
			if (!isOpenAround(pVec))
				return false;
			if (opw7_cells[pVec] == 3)
				addeds.push_back(pVec);
			if (i == paths.size())
			{
				OpB_translateRotated(&pVec,dirs,0,1);
				if (opw7_cells[pVec] == 3)
					addeds.push_back(pVec);
				paths.insert(paths.begin() + 1,addeds.begin(),addeds.end());
				for (unsigned int k = 0; k < addeds.size(); k++)
				{
					opw7_cells[addeds[k]] = 9;
					unknown70[addeds[k]] = opw7_cf125c.size() - 1;
				}
				return true;
			}
			next2 = i >= paths.size() - 1 ? dirs : OpW7_dirBetween_4491a0(paths[i],paths[i + 1]);
		}
		bool sameSide;
		if (next2 == opw7_bb8350[dirs])
			sameSide = flip;
		else
			sameSide = !flip;
		if (sameSide)
		{
			i += 2;
			dirs = next2;
		}
		else
		{
			i++;
			OpB_translateRotated(&pVec,dirs,0,1);
			if (!isOpenAround(pVec))
				return false;
			if (opw7_cells[pVec] == 3)
				addeds.push_back(pVec);
			dirs = next2;
			OpB_translateRotated(&pVec,dirs,0,1);
			if (!isOpenAround(pVec))
				return false;
			if (opw7_cells[pVec] == 3)
				addeds.push_back(pVec);
		}
	}
	return false;
}

bool OpW7_containsPos_9d0ce0(vector<Pos> &v, Pos value);	// NOTE: placeholder name
int OpW7_indexOfPos_9d53a0(vector<Pos> &v, Pos value);	// NOTE: placeholder name
void OpW7_eraseRange_9d53f0(vector<Pos> &v, int from, int to);	// NOTE: placeholder name
void OpW7_insertPos_9d5460(vector<Pos> &v, int index, Pos value);	// NOTE: placeholder name

void OpW7_CaveGen::straightenPath(bool fromEnd)
{
	vector<Pos> &pathList = opw7_cf125c.back().path;
	if (pathList.size() < 8)
		return;
	int step3 = fromEnd ? -1 : 1;
	Pos pList;
	int dirs = fromEnd ? OpW7_dirBetween_4491a0(pathList[pathList.size() - 1],pathList[pathList.size() - 2]) : OpW7_dirBetween_4491a0(pathList[0],pathList[1]);
	int nextDir;
	for (int i = fromEnd ? pathList.size() - 2 : 1; i >= 1 && i < pathList.size() - 1; i += step3)
	{
		nextDir = OpW7_dirBetween_4491a0(pathList[i],pathList[i + step3]);
		if (nextDir != dirs)
		{
			vector<Pos> line;
			pList = pathList[i];
			OpB_translateRotated(&pList,dirs,0,1);
			while (opw7_cells.contains(pList) && opw7_cells[pList] == 3)
			{
				if (!isClearSides(pList,dirs,1))
					break;
				if (OpW7_containsPos_9d0ce0(pathList,pList))
				{
					int index = OpW7_indexOfPos_9d53a0(pathList,pList);
					OpW7_eraseRange_9d53f0(pathList,opw3_minInt(i + step3,index - step3),maxInt(i + step3,index - step3));
					for (unsigned int k = 0; k < line.size(); k++)
						OpW7_insertPos_9d5460(pathList,fromEnd ? index - step3 : i + step3 + k,line[k]);
					i = fromEnd ? index - step3 : line.size() + i;
					nextDir = dirs;
					break;
				}
				line.push_back(pList);
				OpB_translateRotated(&pList,dirs,0,1);
			}
		}
		dirs = nextDir;
	}
}

void opW4_shuffle(vector<int> &v);	// NOTE: placeholder name (0x9d8f80)

void OpW7_CaveGen::boxCaves()
{
	if (opw7_caveSettings->unknown58 == 0)
	{
		for (unsigned int i = 0; i < opw7_cf126c.size(); i++)
			opw7_cf126c[i].unknown44 = false;
		return;
	}
	int count = 0;
	vector<int> order;
	for (int i = 0; i < opw7_cf126c.size(); i++)
	{
		order.push_back(i);
		opw7_cf126c[i].unknown44 = false;
	}
	opW4_shuffle(order);
	for (unsigned int j = 0; j < order.size(); j++)
	{
		if (rng.chance(opw7_caveSettings->unknown58))
		{
			Pos lo(100000,100000);
			Pos his(-1,-1);
			OpW7_Struct_4ccdc0 &cave = opw7_cf126c[order[j]];
			for (unsigned int k = 0; k < cave.cells.size(); k++)
			{
				if (cave.cells[k].x < lo.x)
					lo.x = cave.cells[k].x;
				else if (cave.cells[k].x > his.x)
					his.x = cave.cells[k].x;
				if (cave.cells[k].y < lo.y)
					lo.y = cave.cells[k].y;
				else if (cave.cells[k].y > his.y)
					his.y = cave.cells[k].y;
			}
			if (opw7_caveSettings->unknown60 != 0 && (his.x - lo.x) * (his.y - lo.y) > opw7_caveSettings->unknown60)
				continue;
			for (int x = lo.x; x <= his.x; x++)
			{
				for (int y = lo.y; y <= his.y; y++)
				{
					if (labels.at(x,y) != order[j] && opw7_grid.at(x,y) != 3)
						goto nextCave;
				}
			}
			if (hasForeignDiagonal(lo,order[j]) || hasForeignDiagonal(Pos(his.x,lo.y),order[j]) || hasForeignDiagonal(Pos(lo.x,his.y),order[j]) || hasForeignDiagonal(his,order[j]))
				continue;
			cave.cells.clear();
			for (int x = lo.x; x <= his.x; x++)
			{
				for (int y = lo.y; y <= his.y; y++)
				{
					cave.cells.push_back(Pos(x,y));
					labels.at(x,y) = j;
					opw7_grid.at(x,y) = 8;
				}
			}
			opw7_cf126c[order[j]].unknown44 = true;
			if (cave.cells.size() > opw7_ced16c)
				opw7_ced16c = cave.cells.size();
			count++;
			if (count == opw7_caveSettings->unknown5C)
				return;
		}
nextCave:
		;
	}
}

void OpW7_removeElement_9d51d0b(vector<int> &v, int value);	// NOTE: placeholder name

bool OpW7_CaveGen::connectAreas(int mode)
{
	if (opw7_caveSettings->regions.empty())
		opw7_caveSettings->regions.push_back(Rect(0,0,opw7_caveSettings->unknown64,opw7_caveSettings->unknown68));
	for (unsigned int r = 0; r < opw7_caveSettings->regions.size(); r++)
	{
		Rect &rect = opw7_caveSettings->regions[r];
		vector<int> connected;
		vector<int> left;
		for (int i = 0; i < opw7_cf126c.size(); i++)
		{
			if (!opw7_cf126c[i].masked && rect.containsPos_40aa00(opw7_cf126c[i].cells.front()))
			{
				if (mode == 1 || !rng.chance((int)((100.0 - (double)opw7_cf126c[i].cells.size() / opw7_ced16c * 100.0) * opw7_caveSettings->unknown20)))
					left.push_back(i);
			}
		}
		int attempts = 0;
		Pos pos;
		int direction;
		if (left.empty())
			return true;
		int cave = OpW7_randomElement_9d5d00(left);
		connected.push_back(cave);
		OpW7_removeElement_9d51d0b(left,cave);
		do
		{
			bool fromCorridor = false;
			if (!opw7_cf125c.empty() && rng.chance(opw7_caveSettings->unknown28))
			{
				cave = -1;
				if (pickCorridorStart(pos,direction))
					fromCorridor = true;
			}
			if (!fromCorridor)
			{
				cave = OpW7_randomElement_9d5d00(connected);
				pickEdge(cave,pos,direction);
			}
			if (digTunnel(pos,direction,left))
			{
				int target = labels[opw7_cf125c.back().path.back()];
				opw7_cf125c.back().path.pop_back();
				if (cave != -1)
					opw7_cf125c.back().rooms.push_back(cave);
				opw7_cf125c.back().rooms.push_back(target);
				connected.push_back(target);
				OpW7_removeElement_9d51d0b(left,target);
				straightenPath(false);
				straightenPath(true);
				bool ok = true;
				vector<Pos> &route = opw7_cf125c.back().path;
				if (route.size() >= 6)
				{
					for (unsigned int k = 2; k < route.size() - 2; k++)
					{
						if (OpW7_hasSolidDiagonal(route[k]))
						{
							opw7_cf125c.pop_back();
							left.push_back(connected.back());
							connected.pop_back();
							ok = false;
							break;
						}
					}
				}
				if (ok)
				{
					for (unsigned int m = 0; m < route.size(); m++)
					{
						opw7_cells[route[m]] = 9;
						unknown70[route[m]] = opw7_cf125c.size() - 1;
					}
					if (cave != -1)
					{
						opw7_cf126c[cave].unknown10.push_back(opw7_cf125c.size() - 1);
						opw7_cf126c[cave].unknown20.push_back(opw7_cf125c.back().path.front());
					}
					opw7_cf126c[connected.back()].unknown10.push_back(opw7_cf125c.size() - 1);
					opw7_cf126c[connected.back()].unknown20.push_back(opw7_cf125c.back().path.back());
					if (opw7_caveSettings->unknown40 != 0)
					{
						int chance = (opw7_cf125c.back().rooms.size() == 1 ? 0 : opw7_cf126c[opw7_cf125c.back().rooms[1]].cells.size()) + opw7_cf126c[opw7_cf125c.back().rooms.front()].cells.size();
						chance = chance / 2;
						chance = (int)(chance / opw7_caveSettings->unknown40);
						if (rng.chance(chance))
						{
							bool side = rng.chance(50);
							if (!widenPath(side))
								widenPath(!side);
						}
					}
				}
			}
			attempts++;
			if (attempts >= opw7_caveSettings->unknown24)
				return false;
		} while (!left.empty());
	}
	return true;
}

extern bool opw7_doFill;	// NOTE: placeholder name (0xbb856d)
extern bool opw7_doClear;	// NOTE: placeholder name (0xbb856e)
extern bool opw7_doConnect;	// NOTE: placeholder name (0xbb8570)
extern bool opw7_doBox;	// NOTE: placeholder name (0xbb8571)
extern int opw7_ced22c;	// NOTE: placeholder name (cave count)
extern int opw7_ced224;	// NOTE: placeholder name
extern int opw7_ced1c4;	// NOTE: placeholder name (solid percentage)
extern int opw7_ced1c8[21];	// NOTE: placeholder name (cell type counts)
extern int opw7_ced170[21];	// NOTE: placeholder name
extern int opw7_ced230[21];	// NOTE: placeholder name
void OpW7_fill_9e2be0(int *values, int count, int value);	// NOTE: placeholder name

bool OpW7_CaveGen::step(bool singleStep)
{
	if (finished)
		return true;
	int result = 9;
	switch (unknown54)
	{
	case 0:
		unknown54++;
		seed();
		if (singleStep)
			break;
	case 1:
		unknown54++;
		if (opw7_doFill)
		{
			fillPass();
			if (singleStep)
				break;
		}
	case 2:
		unknown54++;
		if (opw7_doClear)
		{
			clearPass();
			if (singleStep)
				break;
		}
	case 3:
		unknown54++;
		if (!findAreas())
		{
			result = 1;
			goto done;
		}
		if (singleStep)
			break;
	case 4:
		if (connectTries == 0 || !opw7_doConnect)
			unknown54++;
		else
		{
			while (connectTries != 0)
			{
				connectTries--;
				if (!connectAreas(opw7_caveSettings->unknown1C - connectTries) && connectTries == opw7_caveSettings->unknown1C - 1)
				{
					result = 2;
					goto done;
				}
				if (singleStep)
					return false;
			}
			unknown54++;
		}
	case 5:
		unknown54++;
		if (opw7_doBox)
		{
			boxCaves();
			if (singleStep)
				break;
		}
	case 6:
		unknown54++;
		if (!placeBridges())
		{
			bridgeFailures++;
			result = 3;
			goto done;
			if (0) {}	// NOTE: emits nothing; shifts register rotation to match
		}
		else
			bridgeFailures = 0;
		if (singleStep)
			break;
	case 7:
		unknown54++;
		if (opw7_caveSettings->unknown44 && opw7_doBox)
			sprout();
		if (0) {}	// NOTE: emits nothing; shifts register rotation to match
	}
	if (unknown54 == 8)
	{
		opw7_ced22c = 0;
		for (unsigned int i = 0; i < opw7_cf126c.size(); i++)
		{
			if (opw7_cf126c[i].unknown44)
				opw7_ced22c++;
		}
		opw7_ced224 = 0;
		computeLinks();
		for (unsigned int j = 0; j < opw7_cf126c.size(); j++)
		{
			if (opw7_cf126c[j].unknown40 > opw7_ced224)
				opw7_ced224 = opw7_cf126c[j].unknown40;
		}
		OpW7_fill_9e2be0(opw7_ced1c8,21,0);
		OpW7_fill_9e2be0(opw7_ced170,21,0);
		OpW7_fill_9e2be0(opw7_ced230,21,0);
		for (int x = 0; x < opw7_grid.getWidth(); x++)
		{
			for (int y = 0; y < opw7_grid.getHeight(); y++)
				opw7_ced1c8[opw7_grid.at(x,y)]++;
		}
		int total = opw7_grid.getWidth() * opw7_grid.getHeight();
		int open = 0;
		for (int k = 4; k < 21; k++)
			open += opw7_ced1c8[k];
		opw7_ced1c4 = open * 100 / total;
		for (int n = 0; n < 21; n++)
		{
			opw7_ced170[n] = opw7_ced1c8[n] * 100 / total;
			opw7_ced230[n] = opw7_ced1c8[n] * 100 / open;
		}
		if (!opw7_caveSettings->unknown90.contains_40c190(opw7_ced1c4))
		{
			result = (opw7_ced1c4 >= opw7_caveSettings->unknown90.min) + 4;
			goto done;
		}
		if (opw7_cf126c.size() < opw7_caveSettings->unknown98)
		{
			result = 6;
			goto done;
		}
		if (opw7_caveSettings->unknown9C && opw7_ced16c > opw7_caveSettings->unknown9C)
		{
			result = 7;
			goto done;
		}
		if (opw7_ced22c < opw7_caveSettings->unknownA0)
			result = 8;
done:
		if (result != 9)
		{
			failed = true;
			return true;
		}
		else
		{
			finished = true;
			failed = false;
			return true;
		}
	}
	else
		return false;
}
