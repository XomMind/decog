// alpha2_10: DF::Generator setup (0x4bf610): loads the settings, seeds the RNG, picks the level variant and
//	paints the selected prefab/area records into the map grids before the builders run.
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <string>
#include <vector>
#include <limits>
#include "rng.h"
using std::string;
using std::vector;
extern RNG rng;

struct A2IPos
{
	int x;
	int y;
	A2IPos(int x_, int y_) throw();	// 0x46ca20
	A2IPos(const A2IPos &other) throw();	// 0x46ca50
	A2IPos &operator=(const A2IPos &other) throw();	// 0x46ca50
};
struct A2IRange
{
	int low;
	int high;
	int randomInRange_40c130() throw();
};
struct A2IRect
{
	int x;
	int y;
	int width;
	int height;
	A2IRect(int x_, int y_, int width_, int height_) throw();	// 0x456940
};
struct A2IColor
{
	unsigned char r, g, b, a;
	A2IColor(const A2IColor &other) throw();	// 0x411e30
	bool operator==(A2IColor other) throw();	// 0x411f40
};
struct A2ICell
{
	A2IColor *getBack_416f60() throw();
	int glyph_9b8f00() throw();
};
struct A2IArt	// Array2D<XCell>
{
	int getWidth_9fcd80() throw();
	int getHeight_9b8f00() throw();
	A2ICell *at_9cdf20(int x, int y) throw();
};
struct A2IImage	// 0x60 bytes
{
	A2IImage();	// 0x448c00
	~A2IImage();	// 0x4c1430
	A2IImage &operator=(const A2IImage &other);	// 0x448de0
	void rotate_447010(bool clockwise);
	vector<A2IArt *> layers;
	char pad10[0x50 - 0x10];
	A2IPos offset;	// +0x50
	int rotation;	// +0x58
	bool placed;	// +0x5c
};
struct A2IBoolGrid
{
	A2IBoolGrid(int width, int height, bool value);	// 0x9d2720
	~A2IBoolGrid();	// 0x9cec20
	bool *at_9cec50(int x, int y) throw();
	int width;
	int height;
	bool *cells;
};
struct A2IGrid
{
	void init_9cf690(int width, int height, int value);
	int getWidth_9fcd80() throw();
	int getHeight_9b8f00() throw();
	int *at_9ceda0(int x, int y) throw();
	int *atPoint_9ced70(A2IPos &p) throw();
};
struct A2IRoom	// 0x6c bytes
{
	A2IRoom();	// 0x4bd0f0
	~A2IRoom();	// 0x4bd140
	int type;
	A2IRect rect;
	vector<A2IPos> cells;	// +0x14
	int category;	// +0x24
	char pad28[0x6c - 0x28];
};
struct A2ISpawn	// 0x84 bytes
{
	bool enabled;
	int level;
	int weight;
	int chance;
	char pad10[0x84 - 0x10];
};
struct A2IRecord	// 0xac bytes
{
	bool enabled;
	int level;
	int chance;
	int type;
	int index;
	string name;	// +0x14
	string suffix;	// +0x30
	char pad4c[0x6c - 0x4c];
	int group;	// +0x6c
	vector<unsigned int> directions;	// +0x70
	int category;	// +0x80
	char pad84[0x88 - 0x84];
	A2IRange range88;
	A2IRange range90;
	A2IRange range98;
	A2IRange rangeA0;
	int extra;
};
struct A2ISettings	// DF settings (0x280 bytes)
{
	A2ISettings();	// 0x448760
	~A2ISettings();	// 0x449070 (scalar deleting)
	bool read_4bd340(const string &filename, bool binary);

	char pad0[0x1a0];
	int width;	// +0x1a0
	int height;	// +0x1a4
	int seed;	// +0x1a8
	vector<A2IRecord> records;	// +0x1ac
	vector<A2ISpawn> spawns;	// +0x1bc
	char pad1cc[0x208 - 0x1cc];
	A2IRange exit208;
	char pad210[0x218 - 0x210];
	A2IRange exit218;
	A2IRange exit220;
	A2IRange exit228;
	A2IRange exit230;
	A2IRange exit238;
	A2IRange exit240;
	A2IRange exit248;
	char pad250[0x280 - 0x250];
};
struct A2IWeights	// WeightList<int> (0x24 bytes)
{
	A2IWeights();	// 0x9bab50
	~A2IWeights();	// 0x700dd0
	bool contains_9b6f10(int *value);
	void add_9ba310(int value, int weight);
	int &pick_9ba470();
	int total_9b81d0() throw();
	int data[0x24 / 4];
};
class A2IBuilder;
class A2ITunneler	// DF::Tunneler
{
public:
	A2ITunneler(int delay, int dir, const A2IPos &pos, int param1C, int width, int param24, int param28, int param2C, int param30, int param34, int param38, int param3C, bool param40);
	int data[0x44 / 4];
};
A2ITunneler::A2ITunneler(int delay, int dir, const A2IPos &pos, int param1C, int width, int param24, int param28, int param2C, int param30, int param34, int param38, int param3C, bool param40)
{
}

extern A2ISettings *a2i_settings_cefb50;
extern A2IGrid a2i_grid_cf1964;
extern A2IGrid a2i_categories_cf447c;
extern vector<int> a2i_vec_cfb678;
extern vector<int> a2i_vec_d2e224;
extern vector<A2IRoom> a2i_rooms_cf13e8;
struct A2IBridge { int x, y, width, height, blocked; vector<int> rooms; };
struct A2IBlob { vector<A2IPos> cells; int unknown10; };
struct A2ICave { int x, y, width, height; };
extern vector<A2IBridge> a2i_bridges_d1f31c;
extern vector<A2ICave> a2i_caves_d222f0;
extern vector<A2IBlob> a2i_blobs_cf65c4;
extern vector<A2IImage> a2i_images_cf124c;
extern vector<A2IImage *> a2i_prefabs_d161c4;
extern vector<vector<A2IPos> > a2i_groups_d02b4c;
extern vector<string> a2i_groupNames_d21768;
extern vector<A2IRect> a2i_vec_d39d30;
extern vector<string> a2i_disabled_d1e30c;
extern vector<string> a2i_unique_cf123c;
extern int a2i_maxDoorDistance_ced21c;
extern int a2i_rotations_bb8370[];
extern int a2i_cellTypes_bb8398[];
extern A2IColor a2i_colors_cf127c[];
extern A2IColor a2i_exitColor_d25f68;

void a2i_deleteAll_9cead0(vector<A2IBuilder *> &list);
void a2i_fillInts_9e2be0(int *values, unsigned int count, int value);
bool a2i_containsString_9d3fe0(vector<string> &list, string value);
bool a2i_containsRecord_9db330(vector<int> &list, int value);
int a2i_popRandom_9de500(vector<int> &list);
void a2i_shuffle_9d8f80(vector<int> &list);
int a2i_findString_9ceb50(vector<string> &list, string value);
void a2i_eraseString_9cfab0(vector<string> &list, int index);
void a2i_eraseIndex_9ce6d0(vector<int> &list, unsigned int &index);
int a2i_randomRec_9d5d00(vector<unsigned int> &list);
int a2i_findColor_9d4f10(A2IColor *colors, unsigned int count, A2IColor color);
bool a2i_between_9daf80(int low, int value, int high);
void a2i_translate_446dd0(A2IPos &pos, int dir, int lateral, int forward);

class A2IGenerator	// DF::Generator
{
public:
	void init(A2ISettings *settings, const string &path, const string &name, bool binary, bool keepSeed, bool newSeed, int level);
	void floodFill_4c1460(int x, int y, A2IBoolGrid *visited, const A2IPos &offset, vector<A2IPos> &cells);
	void addBuilder_449020(A2ITunneler *builder);

	string path;	// +0x00
	string name;	// +0x1c
	bool binary;	// +0x38
	int seed;	// +0x3c
	int turn;	// +0x40
	vector<A2IBuilder *> builders;	// +0x44
	vector<A2IPos> starts;	// +0x54
	vector<A2IPos> exits;	// +0x64
	int level;	// +0x74
	int roomCounts[3];	// +0x78
	bool paused;	// +0x84
	int stage;	// +0x88
	vector<A2IRect> caves8c;	// +0x8c
	vector<A2IRect> caves9c;	// +0x9c
	vector<A2IPos> network;	// +0xac
	bool finished;	// +0xbc
	bool failed;	// +0xbd
};

void A2IGenerator::init(A2ISettings *settings, const string &path, const string &name, bool binary, bool keepSeed, bool newSeed, int filter)
{
	this->path = path;
	this->name = name;
	this->binary = binary;
	if (settings)
		a2i_settings_cefb50 = settings;
	else
	{
		delete a2i_settings_cefb50;
		a2i_settings_cefb50 = new A2ISettings();
		a2i_settings_cefb50->read_4bd340(this->path + this->name,this->binary);
	}
	a2i_vec_cfb678.assign(10u,0u);
	a2i_vec_d2e224.assign(10u,4);
	a2i_grid_cf1964.init_9cf690(a2i_settings_cefb50->width,a2i_settings_cefb50->height,3);
	a2i_categories_cf447c.init_9cf690(a2i_settings_cefb50->width,a2i_settings_cefb50->height,0);
	a2i_rooms_cf13e8.clear();
	a2i_bridges_d1f31c.clear();
	a2i_caves_d222f0.clear();
	a2i_blobs_cf65c4.clear();
	a2i_images_cf124c.clear();
	a2i_maxDoorDistance_ced21c = 0;
	if (!keepSeed || newSeed)
	{
		if (a2i_settings_cefb50->seed && !newSeed)
			seed = a2i_settings_cefb50->seed;
		else
			seed = rng.rangeInt(1,std::numeric_limits<int>::max());
		rng.seed(seed);
	}
	turn = 0;
	a2i_deleteAll_9cead0(builders);
	exits.clear();
	a2i_fillInts_9e2be0(roomCounts,3,0);
	paused = true;
	stage = -1;
	caves8c.clear();
	caves9c.clear();
	finished = false;
	failed = false;
	for (unsigned int i = 0; i < a2i_settings_cefb50->spawns.size(); i++)
		a2i_settings_cefb50->spawns[i].enabled = true;
	for (unsigned int i = 0; i < a2i_settings_cefb50->records.size(); i++)
		a2i_settings_cefb50->records[i].enabled = true;
	for (unsigned int i = 0; i < a2i_settings_cefb50->records.size(); i++)
	{
		if (a2i_containsString_9d3fe0(a2i_disabled_d1e30c,a2i_settings_cefb50->records[i].name))
			a2i_settings_cefb50->records[i].enabled = false;
	}
	bool found = false;
	for (unsigned int i = 0; i < a2i_settings_cefb50->spawns.size(); i++)
	{
		if (a2i_settings_cefb50->spawns[i].chance != -1 && a2i_settings_cefb50->spawns[i].chance < 100 && !rng.chance(a2i_settings_cefb50->spawns[i].chance))
			a2i_settings_cefb50->spawns[i].enabled = false;
		else
			found = true;
	}
	for (unsigned int i = 0; i < a2i_settings_cefb50->records.size(); i++)
	{
		if (a2i_settings_cefb50->records[i].chance != -1 && a2i_settings_cefb50->records[i].chance < 100 && !rng.chance(a2i_settings_cefb50->records[i].chance))
			a2i_settings_cefb50->records[i].enabled = false;
	}
	A2IWeights weight;
	if (found)
	{
		for (unsigned int i = 0; i < a2i_settings_cefb50->spawns.size(); i++)
		{
			if (a2i_settings_cefb50->spawns[i].enabled && a2i_settings_cefb50->spawns[i].level && !weight.contains_9b6f10(&a2i_settings_cefb50->spawns[i].level) && (filter == -1 || a2i_settings_cefb50->spawns[i].level == filter))
				weight.add_9ba310(a2i_settings_cefb50->spawns[i].level,a2i_settings_cefb50->spawns[i].weight);
		}
		level = weight.total_9b81d0() ? weight.pick_9ba470() : 0;
	}
	else
	{
		for (unsigned int i = 0; i < a2i_settings_cefb50->records.size(); i++)
		{
			if (a2i_settings_cefb50->records[i].enabled && a2i_settings_cefb50->records[i].level && !weight.contains_9b6f10(&a2i_settings_cefb50->records[i].level) && (filter == -1 || a2i_settings_cefb50->records[i].level == filter))
				weight.add_9ba310(a2i_settings_cefb50->records[i].level,100);
		}
		level = weight.total_9b81d0() ? weight.pick_9ba470() : 0;
	}
	vector<int> flags;
	vector<int> vec;
	bool ok;
	do
	{
		ok = false;
		for (int i = 0; i < a2i_settings_cefb50->records.size(); i++)
		{
			if (a2i_settings_cefb50->records[i].enabled && (a2i_settings_cefb50->records[i].level == level || a2i_settings_cefb50->records[i].level == 0) && a2i_settings_cefb50->records[i].group && !a2i_containsRecord_9db330(flags,a2i_settings_cefb50->records[i].group))
			{
				ok = true;
				vec.clear();
				vec.push_back(i);
				for (int j = i + 1; j < a2i_settings_cefb50->records.size(); j++)
				{
					if (a2i_settings_cefb50->records[j].enabled && (a2i_settings_cefb50->records[j].level == level || a2i_settings_cefb50->records[j].level == 0) && a2i_settings_cefb50->records[j].group == a2i_settings_cefb50->records[i].group)
						vec.push_back(j);
				}
				a2i_popRandom_9de500(vec);
				for (unsigned int k = 0; k < vec.size(); k++)
					a2i_settings_cefb50->records[vec[k]].enabled = false;
				flags.push_back(a2i_settings_cefb50->records[i].group);
			}
		}
	}
	while (ok);
	vector<int> current;
	for (int i = 0; i < a2i_settings_cefb50->records.size(); i++)
	{
		if (a2i_settings_cefb50->records[i].enabled && a2i_settings_cefb50->records[i].chance == -1 && (a2i_settings_cefb50->records[i].level == level || a2i_settings_cefb50->records[i].level == 0))
			current.push_back(i);
	}
	a2i_shuffle_9d8f80(current);
	vector<string> parts(a2i_unique_cf123c);
	for (unsigned int i = 0; i < current.size(); i++)
	{
		string suffix = a2i_settings_cefb50->records[current[i]].suffix;
		int index = a2i_findString_9ceb50(parts,suffix);
		if (index != -1)
		{
			a2i_eraseString_9cfab0(parts,index);
			a2i_eraseIndex_9ce6d0(current,i);
		}
	}
	for (unsigned int i = 0; i < current.size(); i++)
		a2i_settings_cefb50->records[current[i]].enabled = false;
	a2i_groups_d02b4c.clear();
	a2i_groups_d02b4c.assign(5,vector<A2IPos>());
	a2i_groupNames_d21768.clear();
	a2i_vec_d39d30.clear();
	for (unsigned int i = 0; i < a2i_settings_cefb50->records.size(); i++)
	{
		if (a2i_settings_cefb50->records[i].enabled && (a2i_settings_cefb50->records[i].level == level || a2i_settings_cefb50->records[i].level == 0))
		{
			A2IRecord *record = &a2i_settings_cefb50->records[i];
			if (record->type < 21)
			{
				A2IRect area(record->range88.randomInRange_40c130(),record->range90.randomInRange_40c130(),record->range98.randomInRange_40c130(),record->rangeA0.randomInRange_40c130());
				if (area.x < 1)
				{
					area.width -= 1 - area.x;
					area.x = 1;
				}
				if (area.y < 1)
				{
					area.height -= 1 - area.y;
					area.y = 1;
				}
				if (area.x + area.width >= a2i_grid_cf1964.getWidth_9fcd80() - 1)
					area.width = a2i_grid_cf1964.getWidth_9fcd80() - 2 - area.x;
				if (area.y + area.height >= a2i_grid_cf1964.getHeight_9b8f00() - 1)
					area.height = a2i_grid_cf1964.getHeight_9b8f00() - 2 - area.y;
				for (int x = area.x; x < area.x + area.width; x++)
				{
					for (int y = area.y; y < area.y + area.height; y++)
					{
						*a2i_grid_cf1964.at_9ceda0(x,y) = record->type;
						*a2i_categories_cf447c.at_9ceda0(x,y) = record->type == 3 ? 0 : record->category;
					}
				}
			}
			else
			{
				if (false) {}
				A2IImage temp;
				int other;
				a2i_images_cf124c.push_back(temp);
				A2IImage *list = &a2i_images_cf124c.back();
				a2i_images_cf124c.back() = *a2i_prefabs_d161c4[record->index];
				a2i_images_cf124c.back().rotation = a2i_randomRec_9d5d00(record->directions);
				a2i_images_cf124c.back().placed = false;
				for (int r = 0; r < a2i_rotations_bb8370[a2i_images_cf124c.back().rotation]; r++)
					list->rotate_447010(true);
				A2IArt *layer = list->layers.front();
				if (record->range88.high + layer->getWidth_9fcd80() - 1 < a2i_grid_cf1964.getWidth_9fcd80())
					layer->getHeight_9b8f00() < a2i_grid_cf1964.getHeight_9b8f00();
				A2IPos point(record->range88.randomInRange_40c130(),record->range90.randomInRange_40c130());
				a2i_images_cf124c.back().offset = point;
				vector<A2IPos> elements;
				for (int x = 0; x < layer->getWidth_9fcd80(); x++)
				{
					for (int y = 0; y < layer->getHeight_9b8f00(); y++)
					{
						other = a2i_findColor_9d4f10(a2i_colors_cf127c,9,*layer->at_9cdf20(x,y)->getBack_416f60());
						*a2i_grid_cf1964.at_9ceda0(point.x + x,point.y + y) = a2i_cellTypes_bb8398[other];
						if (a2i_between_9daf80(0,layer->at_9cdf20(x,y)->glyph_9b8f00() - 48,4))
						{
							*a2i_grid_cf1964.at_9ceda0(point.x + x,point.y + y) = layer->at_9cdf20(x,y)->glyph_9b8f00() - 32;
							elements.push_back(A2IPos(point.x + x,point.y + y));
						}
						if (*a2i_grid_cf1964.at_9ceda0(point.x + x,point.y + y) != 3)
							*a2i_categories_cf447c.at_9ceda0(point.x + x,point.y + y) = record->category;
					}
				}
				for (unsigned int m = 0; m < elements.size(); m++)
				{
					a2i_groups_d02b4c[*a2i_grid_cf1964.atPoint_9ced70(elements[m]) - 16].push_back(A2IPos(elements[m]));
					if (*a2i_grid_cf1964.atPoint_9ced70(elements[m]) == 20)
						a2i_groupNames_d21768.push_back(record->suffix);
					for (int dx = -1; dx <= 1; dx++)
					{
						for (int dy = -1; dy <= 1; dy++)
						{
							if (a2i_between_9daf80(4,*a2i_grid_cf1964.at_9ceda0(elements[m].x + dx,elements[m].y + dy),9))
							{
								*a2i_grid_cf1964.atPoint_9ced70(elements[m]) = *a2i_grid_cf1964.at_9ceda0(elements[m].x + dx,elements[m].y + dy);
								goto nextMarker;
							}
						}
					}
nextMarker:;
				}
				for (int x = point.x, i = 0; x < layer->getWidth_9fcd80(); x++, i++)
				{
					for (int y = point.y, j = 0; y < layer->getHeight_9b8f00(); y++, j++)
					{
						switch (*a2i_grid_cf1964.at_9ceda0(x,y))
						{
							case 10:
								if (y > 0 && *a2i_grid_cf1964.at_9ceda0(x,y - 1) >= 4 && *a2i_grid_cf1964.at_9ceda0(x,y - 1) != 10 && *a2i_grid_cf1964.at_9ceda0(x,y - 1) != 11)
									*a2i_grid_cf1964.at_9ceda0(x,y) = 11;
								break;
							case 12:
								if (y > 0 && *a2i_grid_cf1964.at_9ceda0(x,y - 1) >= 4 && *a2i_grid_cf1964.at_9ceda0(x,y - 1) != 12 && *a2i_grid_cf1964.at_9ceda0(x,y - 1) != 13)
									*a2i_grid_cf1964.at_9ceda0(x,y) = 13;
								break;
							case 14:
								if (y > 0 && *a2i_grid_cf1964.at_9ceda0(x,y - 1) >= 4 && *a2i_grid_cf1964.at_9ceda0(x,y - 1) != 14 && *a2i_grid_cf1964.at_9ceda0(x,y - 1) != 15)
									*a2i_grid_cf1964.at_9ceda0(x,y) = 15;
								break;
						}
					}
				}
				A2IBoolGrid visited(layer->getWidth_9fcd80(),layer->getHeight_9b8f00(),false);
				for (int x = point.x, i = 0; i < layer->getWidth_9fcd80(); x++, i++)
				{
					for (int y = point.y, j = 0; j < layer->getHeight_9b8f00(); y++, j++)
					{
						if (*a2i_grid_cf1964.at_9ceda0(x,y) == 7 && !*visited.at_9cec50(i,j))
						{
							A2IRoom room;
							a2i_rooms_cf13e8.push_back(room);
							a2i_rooms_cf13e8.back().type = 3;
							a2i_rooms_cf13e8.back().rect.x = -1;
							floodFill_4c1460(x,y,&visited,point,a2i_rooms_cf13e8.back().cells);
							a2i_rooms_cf13e8.back().category = record->category;
						}
					}
				}
				if (list->layers.size() >= 2)
				{
					A2IArt *exitLayer = list->layers[1];
					for (int x = 0; x < exitLayer->getWidth_9fcd80(); x++)
					{
						for (int y = 0; y < exitLayer->getHeight_9b8f00(); y++)
						{
							if (*exitLayer->at_9cdf20(x,y)->getBack_416f60() == a2i_exitColor_d25f68)
							{
								int direction = 0;
								int dist = y;
								if (exitLayer->getWidth_9fcd80() - 1 - x < dist)
								{
									dist = exitLayer->getWidth_9fcd80() - 1 - x;
									direction = 1;
								}
								if (exitLayer->getHeight_9b8f00() - 1 - y < dist)
								{
									dist = exitLayer->getHeight_9b8f00() - 1 - y;
									direction = 2;
								}
								if (x < dist)
								{
									dist = x;
									direction = 3;
								}
								A2IPos target(point.x + x,point.y + y);
								a2i_between_9daf80(49,exitLayer->at_9cdf20(x,y)->glyph_9b8f00(),57);
								if (false) {}
								int len = exitLayer->at_9cdf20(x,y)->glyph_9b8f00() - 48;
								addBuilder_449020(new A2ITunneler(0,direction,target,a2i_settings_cefb50->exit208.randomInRange_40c130(),len,a2i_settings_cefb50->exit218.randomInRange_40c130(),a2i_settings_cefb50->exit220.randomInRange_40c130(),a2i_settings_cefb50->exit228.randomInRange_40c130(),a2i_settings_cefb50->exit230.randomInRange_40c130(),a2i_settings_cefb50->exit238.randomInRange_40c130(),a2i_settings_cefb50->exit240.randomInRange_40c130(),a2i_settings_cefb50->exit248.randomInRange_40c130(),true));
								a2i_translate_446dd0(target,direction,0,1);
								exits.push_back(target);
							}
						}
					}
				}
			}
		}
	}
}
