// alpha2_07: DF::Generator step function (0x4c1880): runs builders, then the post-processing stages,
//	then validates the finished map (floor ratios, room/cave counts, connectivity).
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <string>
#include <vector>
using std::string;
using std::vector;

struct A2GPoint
{
	int x;
	int y;
	A2GPoint() throw();	// 0x453b40
	A2GPoint(int x_, int y_) throw();	// 0x46ca20
	int distance_409f80(int px, int py) throw();
	void set_40a010(int px, int py) throw();
};
struct A2GRange
{
	int min;
	int max;
	bool contains_40c190(int value) throw();
};
struct A2GRect
{
	int x;
	int y;
	int width;
	int height;
	bool containsPos_40aa00(const A2GPoint &p) throw();
	int area_40ad00() throw();
	bool onOutline_40ad80(int px, int py) throw();
};
struct A2GRoom	// DF::Room (0x6c bytes)
{
	int type;
	A2GRect rect;	// +0x04
	vector<A2GPoint> cells;	// +0x14
	int unknown24;
	vector<A2GPoint> doors;	// +0x28
	vector<int> doorDirs;	// +0x38
	vector<int> corridors;	// +0x48
	int maxDoorDistance;	// +0x58
	vector<int> unknown5c;
};
struct A2GBridge	// 0x24 bytes
{
	int x;
	int y;
	int width;
	int height;
	int positions;	// +0x10
	vector<int> rooms;	// +0x14
};
struct A2GBlob	// 0x14 bytes
{
	vector<A2GPoint> cells;
	int unknown10;
};
struct A2GSpawn	// 0x84 bytes
{
	char pad0[0x10];
	int type;	// +0x10
	char pad14[0x84 - 0x14];
};
struct A2GSettings
{
	char pad0[0x194];
	bool skipPost;	// +0x194
	char pad195[0x1bc - 0x195];
	vector<A2GSpawn> spawns;	// +0x1bc
	char pad1cc[0x250 - 0x1cc];
	vector<string> isolated;	// +0x250
	A2GRange floorPercent;	// +0x260
	int minRooms[3];	// +0x268
	unsigned int minRoomCount;	// +0x274
	unsigned int minCaveCount;	// +0x278
	int maxCaveArea;	// +0x27c
};
struct A2GGrid	// Array2D<int> at 0xcf1964
{
	int getWidth_9fcd80() throw();
	int getHeight_9b8f00() throw();
	int *at_9ceda0(int x, int y) throw();
	int *atPoint_9ced70(A2GPoint &p) throw();
};
struct A2GMoveCost;
class A2GCartographer	// Cartographer2D (0x38 bytes)
{
public:
	A2GCartographer(int width, int height);	// 0x40cac0
	~A2GCartographer();	// 0x40cde0
	bool findPath_40c9a0(const A2GPoint &from, const A2GPoint &to, A2GMoveCost *cost, void *data, vector<A2GPoint> &path);
	bool reach_40c9e0(const A2GPoint &from, vector<A2GPoint> &targets, A2GMoveCost *cost, void *data, vector<A2GPoint> &path);
	int data00, data04, data08, data0c, data10, data14, data18, data1c, data20, data24, data28, data2c, data30, data34;
};
class A2GBuilder
{
public:
	virtual void v0();
	virtual int update();	// slot 1: 0 = finished, 2 = paused
};

extern A2GSettings *a2g_settings_cefb50;
extern A2GGrid a2g_grid_cf1964;
extern vector<A2GRoom> a2g_rooms_cf13e8;
extern vector<A2GBridge> a2g_bridges_d1f31c;
extern vector<A2GRect> a2g_caves_d222f0;
extern vector<vector<A2GPoint> > a2g_groups_d02b4c;
extern vector<A2GBlob> a2g_blobs_cf65c4;
extern vector<string> a2g_groupNames_d21768;
extern A2GMoveCost a2g_cost_cf672c;
extern int a2g_maxCaveArea_ced220;
extern int a2g_floorPercent_ced1c4;
extern int a2g_maxDoorDistance_ced21c;
extern int a2g_avgDoorDistance_ced228;
extern int a2g_cellCounts_ced1c8[];
extern int a2g_cellPercents_ced170[];
extern int a2g_floorPercents_ced230[];
extern bool a2g_thinWalls_bb83bc;
extern bool a2g_findCaves_bb83bd;
extern bool a2g_fillCorners_bb83be;
extern bool a2g_fillWideCorners_bb83bf;
extern bool a2g_fitCaves_bb83c0;
extern bool a2g_widenCaves_bb83c1;
extern bool a2g_growCaves_bb83c2;
extern bool a2g_removeDoors_bb83c3;
extern bool a2g_addCorridors_bb83c4;

void a2g_eraseAt_9d4f60(vector<A2GBuilder *> &list, int &index);
void a2g_fillInts_9e2be0(int *values, unsigned int count, int value);
bool a2g_containsString_9d3fe0(const vector<string> &list, string value);

class A2GGenerator	// DF::Generator
{
public:
	bool generate(bool step);
	void thinWalls_4c36c0();
	void findCaves_4c3b20();
	void fillCorners_4c42e0();
	void fillWideCorners_4c47d0();
	void fitCaves_4c52a0();
	void widenCaves_4c61c0();
	void growCaves_4c6260();
	void removeBlockedDoors_4c6b00();
	void addRoomCorridors_4c6c50();
	bool checkStarts_4c7100();

	char pad0[0x40];
	int turn;	// +0x40
	vector<A2GBuilder *> builders;	// +0x44
	vector<A2GPoint> starts;	// +0x54
	vector<A2GPoint> exits;	// +0x64
	int pad74;
	int roomCounts[3];	// +0x78
	bool paused;	// +0x84
	int stage;	// +0x88
	char pad8c[0xac - 0x8c];
	vector<A2GPoint> network;	// +0xac
	bool finished;	// +0xbc
	bool failed;	// +0xbd
};

bool A2GGenerator::generate(bool step)
{
	if (finished)
		return true;
	while (!builders.empty())
	{
		while (paused)
		{
			paused = false;
			for (int i = 0; i < builders.size(); i++)
			{
				switch (builders[i]->update())
				{
					case 0:
						a2g_eraseAt_9d4f60(builders,i);
						break;
					case 1:
						break;
					case 2:
						paused = true;
						break;
				}
			}
			if (step)
				return false;
		}
		turn++;
		paused = true;
	}
	switch (stage)
	{
		case -1:
			stage++;
			for (int x = 1; x < a2g_grid_cf1964.getWidth_9fcd80() - 1; x++)
			{
				for (int y = 1; y < a2g_grid_cf1964.getHeight_9b8f00() - 1; y++)
				{
					if (*a2g_grid_cf1964.at_9ceda0(x,y) == 10 || *a2g_grid_cf1964.at_9ceda0(x,y) == 11)
					{
						for (unsigned int r = 0; r < a2g_rooms_cf13e8.size(); r++)
						{
							bool adjacent = false;
							if (a2g_rooms_cf13e8[r].rect.x != -1)
								adjacent = a2g_rooms_cf13e8[r].rect.onOutline_40ad80(x,y);
							else
							{
								for (unsigned int c = 0; c < a2g_rooms_cf13e8[r].cells.size(); c++)
								{
									if (a2g_rooms_cf13e8[r].cells[c].distance_409f80(x,y) == 1)
									{
										adjacent = true;
										break;
									}
								}
							}
							if (adjacent)
							{
								a2g_rooms_cf13e8[r].doors.push_back(A2GPoint(x,y));
								if (*a2g_grid_cf1964.at_9ceda0(x - 1,y) == 7)
									a2g_rooms_cf13e8[r].doorDirs.push_back(1);
								else if (*a2g_grid_cf1964.at_9ceda0(x + 1,y) == 7)
									a2g_rooms_cf13e8[r].doorDirs.push_back(3);
								else if (*a2g_grid_cf1964.at_9ceda0(x,y - 1) == 7)
									a2g_rooms_cf13e8[r].doorDirs.push_back(2);
								else if (*a2g_grid_cf1964.at_9ceda0(x,y + 1) == 7)
									a2g_rooms_cf13e8[r].doorDirs.push_back(0);
							}
						}
					}
				}
			}
			{
				A2GPoint p;
				for (unsigned int b = 0; b < a2g_bridges_d1f31c.size(); b++)
				{
					for (int x = a2g_bridges_d1f31c[b].x; x < a2g_bridges_d1f31c[b].x + a2g_bridges_d1f31c[b].width; x++)
					{
						switch (*a2g_grid_cf1964.at_9ceda0(x,a2g_bridges_d1f31c[b].y - 1))
						{
							case 4:
								a2g_bridges_d1f31c[b].positions++;
								x = 10000000;
								break;
							case 10:
							case 11:
								p.set_40a010(x,a2g_bridges_d1f31c[b].y - 2);
								for (int r = 0; r < a2g_rooms_cf13e8.size(); r++)
								{
									if (a2g_rooms_cf13e8[r].rect.containsPos_40aa00(p))
									{
										a2g_bridges_d1f31c[b].rooms.push_back(r);
										break;
									}
								}
								x = 10000000;
								break;
						}
					}
					for (int x = a2g_bridges_d1f31c[b].x; x < a2g_bridges_d1f31c[b].x + a2g_bridges_d1f31c[b].width; x++)
					{
						switch (*a2g_grid_cf1964.at_9ceda0(x,a2g_bridges_d1f31c[b].y + a2g_bridges_d1f31c[b].height - 1))
						{
							case 4:
								a2g_bridges_d1f31c[b].positions++;
								x = 10000000;
								break;
							case 10:
							case 11:
								p.set_40a010(x,a2g_bridges_d1f31c[b].y + a2g_bridges_d1f31c[b].height);
								for (int r = 0; r < a2g_rooms_cf13e8.size(); r++)
								{
									if (a2g_rooms_cf13e8[r].rect.containsPos_40aa00(p))
									{
										a2g_bridges_d1f31c[b].rooms.push_back(r);
										break;
									}
								}
								x = 10000000;
								break;
						}
					}
					for (int y = a2g_bridges_d1f31c[b].y; y < a2g_bridges_d1f31c[b].y + a2g_bridges_d1f31c[b].height; y++)
					{
						switch (*a2g_grid_cf1964.at_9ceda0(a2g_bridges_d1f31c[b].x - 1,y))
						{
							case 4:
								a2g_bridges_d1f31c[b].positions++;
								y = 10000000;
								break;
							case 10:
							case 11:
								p.set_40a010(a2g_bridges_d1f31c[b].x - 2,y);
								for (int r = 0; r < a2g_rooms_cf13e8.size(); r++)
								{
									if (a2g_rooms_cf13e8[r].rect.containsPos_40aa00(p))
									{
										a2g_bridges_d1f31c[b].rooms.push_back(r);
										break;
									}
								}
								y = 10000000;
								break;
						}
					}
					for (int y = a2g_bridges_d1f31c[b].y; y < a2g_bridges_d1f31c[b].y + a2g_bridges_d1f31c[b].height; y++)
					{
						switch (*a2g_grid_cf1964.at_9ceda0(a2g_bridges_d1f31c[b].x + a2g_bridges_d1f31c[b].width - 1,y))
						{
							case 4:
								a2g_bridges_d1f31c[b].positions++;
								y = 10000000;
								break;
							case 10:
							case 11:
								p.set_40a010(a2g_bridges_d1f31c[b].x + a2g_bridges_d1f31c[b].width,y);
								for (int r = 0; r < a2g_rooms_cf13e8.size(); r++)
								{
									if (a2g_rooms_cf13e8[r].rect.containsPos_40aa00(p))
									{
										a2g_bridges_d1f31c[b].rooms.push_back(r);
										break;
									}
								}
								y = 10000000;
								break;
						}
					}
				}
			}
		case 0:
			stage++;
			if (!a2g_settings_cefb50->skipPost && a2g_thinWalls_bb83bc)
			{
				thinWalls_4c36c0();
				if (step)
					break;
			}
		case 1:
			stage++;
			if (!a2g_settings_cefb50->skipPost && a2g_findCaves_bb83bd)
			{
				findCaves_4c3b20();
				if (step)
					break;
			}
		case 2:
			stage++;
			if (!a2g_settings_cefb50->skipPost && a2g_fillCorners_bb83be)
			{
				fillCorners_4c42e0();
				if (step)
					break;
			}
		case 3:
			stage++;
			if (!a2g_settings_cefb50->skipPost && a2g_fillWideCorners_bb83bf)
			{
				fillWideCorners_4c47d0();
				fillCorners_4c42e0();
				if (step)
					break;
			}
		case 4:
			stage++;
			if (!a2g_settings_cefb50->skipPost && a2g_fitCaves_bb83c0)
			{
				fitCaves_4c52a0();
				if (step)
					break;
			}
		case 5:
			stage++;
			if (!a2g_settings_cefb50->skipPost && a2g_widenCaves_bb83c1)
			{
				widenCaves_4c61c0();
				if (step)
					break;
			}
		case 6:
			stage++;
			if (!a2g_settings_cefb50->skipPost && a2g_growCaves_bb83c2 && a2g_fitCaves_bb83c0 && a2g_widenCaves_bb83c1)
			{
				growCaves_4c6260();
				if (step)
					break;
			}
		case 7:
			stage++;
			if (!a2g_settings_cefb50->skipPost && a2g_removeDoors_bb83c3)
			{
				removeBlockedDoors_4c6b00();
				if (step)
					break;
			}
		case 8:
			stage++;
			if (!a2g_settings_cefb50->skipPost && a2g_addCorridors_bb83c4)
				addRoomCorridors_4c6c50();
	}
	if (false) {}
	if (builders.empty() && stage == 9)
	{
		a2g_maxCaveArea_ced220 = 0;
		for (unsigned int i = 0; i < a2g_caves_d222f0.size(); i++)
		{
			if (a2g_caves_d222f0[i].area_40ad00() > a2g_maxCaveArea_ced220)
				a2g_maxCaveArea_ced220 = a2g_caves_d222f0[i].area_40ad00();
		}
		a2g_fillInts_9e2be0(a2g_cellCounts_ced1c8,21,0);
		a2g_fillInts_9e2be0(a2g_cellPercents_ced170,21,0);
		a2g_fillInts_9e2be0(a2g_floorPercents_ced230,21,0);
		for (int x = 0; x < a2g_grid_cf1964.getWidth_9fcd80(); x++)
		{
			for (int y = 0; y < a2g_grid_cf1964.getHeight_9b8f00(); y++)
				a2g_cellCounts_ced1c8[*a2g_grid_cf1964.at_9ceda0(x,y)]++;
		}
		int area = a2g_grid_cf1964.getWidth_9fcd80() * a2g_grid_cf1964.getHeight_9b8f00();
		int cells = 0;
		for (int t = 4; t < 21; t++)
			cells += a2g_cellCounts_ced1c8[t];
		a2g_floorPercent_ced1c4 = cells * 100 / area;
		int result = 12;
		if (cells == 0)
		{
			result = 1;
			goto done;
		}
		for (int t = 0; t < 21; t++)
		{
			a2g_cellPercents_ced170[t] = a2g_cellCounts_ced1c8[t] * 100 / area;
			a2g_floorPercents_ced230[t] = a2g_cellCounts_ced1c8[t] * 100 / cells;
		}
		network.clear();
		if (!a2g_settings_cefb50->floorPercent.contains_40c190(a2g_floorPercent_ced1c4))
		{
			result = a2g_floorPercent_ced1c4 < a2g_settings_cefb50->floorPercent.min ? 1 : 2;
			goto done;
		}
		for (int t = 0; t < 3; t++)
		{
			if (roomCounts[t] < a2g_settings_cefb50->minRooms[t])
			{
				result = 3;
				goto done;
			}
		}
		if (a2g_rooms_cf13e8.size() < a2g_settings_cefb50->minRoomCount)
		{
			result = 4;
			goto done;
		}
		if (a2g_caves_d222f0.size() < a2g_settings_cefb50->minCaveCount)
		{
			result = 5;
			goto done;
		}
		if (a2g_maxCaveArea_ced220 > a2g_settings_cefb50->maxCaveArea)
		{
			result = 6;
			goto done;
		}
		if (!checkStarts_4c7100())
		{
			result = 7;
			goto done;
		}
		else
		{
			vector<A2GPoint> targets;
			for (unsigned int i = 0; i < starts.size(); i++)
			{
				if (starts[i].x != -1)
				{
					switch (a2g_settings_cefb50->spawns[i].type)
					{
						case 0:
							a2g_groups_d02b4c[1].push_back(starts[i]);
							break;
						case 1:
							a2g_groups_d02b4c[2].push_back(starts[i]);
							break;
						case 2:
							a2g_groups_d02b4c[0].push_back(starts[i]);
							break;
						case 3:
							targets.push_back(starts[i]);
							break;
					}
				}
			}
			vector<A2GPoint> positions;
			vector<int> prev;
			for (unsigned int i = 0; i < a2g_blobs_cf65c4.size(); i++)
			{
				positions.push_back(a2g_blobs_cf65c4[i].cells.front());
				prev.push_back(*a2g_grid_cf1964.atPoint_9ced70(positions.back()));
				*a2g_grid_cf1964.atPoint_9ced70(positions.back()) = 0;
			}
			A2GCartographer frontier(a2g_grid_cf1964.getWidth_9fcd80(),a2g_grid_cf1964.getHeight_9b8f00());
			vector<A2GPoint> path;
			for (unsigned int a = 0; a < a2g_groups_d02b4c.size(); a++)
			{
				for (unsigned int ai = 0; ai < a2g_groups_d02b4c[a].size(); ai++)
				{
					for (unsigned int b = a; b < a2g_groups_d02b4c.size(); b++)
					{
						for (unsigned int bi = b == a ? ai + 1 : 0; bi < a2g_groups_d02b4c[b].size(); bi++)
						{
							if (a == 4 && a2g_containsString_9d3fe0(a2g_settings_cefb50->isolated,a2g_groupNames_d21768[ai]) || b == 4 && a2g_containsString_9d3fe0(a2g_settings_cefb50->isolated,a2g_groupNames_d21768[bi]))
								continue;
							if (frontier.findPath_40c9a0(a2g_groups_d02b4c[a][ai],a2g_groups_d02b4c[b][bi],&a2g_cost_cf672c,0,path))
							{
								if (a != 4 && b != 4)
								{
									for (unsigned int k = 0; k < path.size(); k += 20)
										network.push_back(path[k]);
								}
								path.clear();
							}
							else
							{
								result = 8;
								goto done;
							}
						}
					}
				}
			}
			if (network.empty())
			{
				for (unsigned int g = 0; g < a2g_groups_d02b4c.size(); g++)
				{
					if (!a2g_groups_d02b4c[g].empty())
					{
						network.push_back(a2g_groups_d02b4c[g].front());
						break;
					}
				}
			}
			for (unsigned int i = 0; i < targets.size(); i++)
			{
				if (frontier.findPath_40c9a0(targets[i],network.front(),&a2g_cost_cf672c,0,path))
					path.clear();
				else
				{
					result = 9;
					goto done;
				}
			}
			for (unsigned int i = 0; i < exits.size(); i++)
			{
				if (*a2g_grid_cf1964.atPoint_9ced70(exits[i]) >= 4 && frontier.findPath_40c9a0(exits[i],network.front(),&a2g_cost_cf672c,0,path))
					path.clear();
				else
				{
					result = 10;
					goto done;
				}
			}
			a2g_maxDoorDistance_ced21c = 0;
			int distances = 0;
			for (unsigned int r = 0; r < a2g_rooms_cf13e8.size(); r++)
			{
				if (a2g_rooms_cf13e8[r].rect.x != -1)
				{
					a2g_rooms_cf13e8[r].maxDoorDistance = 0;
					for (unsigned int d = 0; d < a2g_rooms_cf13e8[r].doors.size(); d++)
					{
						if (frontier.reach_40c9e0(a2g_rooms_cf13e8[r].doors[d],network,&a2g_cost_cf672c,0,path))
						{
							if (a2g_rooms_cf13e8[r].maxDoorDistance == 0 || a2g_rooms_cf13e8[r].maxDoorDistance < path.size())
								a2g_rooms_cf13e8[r].maxDoorDistance = path.size();
						}
						else
						{
							result = 11;
							goto done;
						}
						path.clear();
					}
					if (a2g_rooms_cf13e8[r].maxDoorDistance > a2g_maxDoorDistance_ced21c)
						a2g_maxDoorDistance_ced21c = a2g_rooms_cf13e8[r].maxDoorDistance;
					distances += a2g_rooms_cf13e8[r].maxDoorDistance;
				}
			}
			a2g_avgDoorDistance_ced228 = distances / a2g_rooms_cf13e8.size();
			network.clear();
			for (unsigned int i = 0; i < positions.size(); i++)
				*a2g_grid_cf1964.atPoint_9ced70(positions[i]) = prev[i];
		}
done:
		if (result != 12)
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
