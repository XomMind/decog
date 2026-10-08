// alpha2_11: cave generator setup (0x4c9d80): the cave counterpart of alpha2_10 (0x4bf610); loads the
//	settings, seeds the RNG, picks the level and paints prefab/area records, retrying prefab placement.
// NOTE: placeholder names / placeholder layout throughout; private aliases for mapped callees.
#include <string>
#include <vector>
#include <limits>
#include "rng.h"
using std::string;
using std::vector;
extern RNG rng;

struct A2CPos
{
	int x;
	int y;
	A2CPos(int x_, int y_) throw();	// 0x46ca20
	A2CPos(const A2CPos &other) throw();	// 0x46ca50
	A2CPos &operator=(const A2CPos &other) throw();	// 0x46ca50
	void set_40a010(int x_, int y_) throw();
};
struct A2CRange
{
	int low;
	int high;
	int randomInRange_40c130() throw();
};
struct A2CRect
{
	int x;
	int y;
	int width;
	int height;
	A2CRect(int x_, int y_, int width_, int height_) throw();	// 0x456940
};
struct A2CColor
{
	unsigned char r, g, b, a;
	A2CColor(const A2CColor &other) throw();	// 0x411e30
	bool operator==(A2CColor other) throw();	// 0x411f40
};
struct A2CCell
{
	A2CColor *getBack_416f60() throw();
	int glyph_9b8f00() throw();
};
struct A2CArt	// Array2D<XCell>
{
	int getWidth_9fcd80() throw();
	int getHeight_9b8f00() throw();
	A2CCell *at_9cdf20(int x, int y) throw();
};
struct A2CImage	// 0x60 bytes
{
	A2CImage();	// 0x448c00
	~A2CImage();	// 0x4c1430
	A2CImage &operator=(const A2CImage &other);	// 0x448de0
	void rotate_447010(bool clockwise);
	vector<A2CArt *> layers;
	char pad10[0x50 - 0x10];
	A2CPos offset;	// +0x50
	int rotation;	// +0x58
	bool placed;	// +0x5c
};
struct A2CBoolGrid
{
	A2CBoolGrid(int width, int height, bool value);	// 0x9d2720
	~A2CBoolGrid();	// 0x9cec20
	bool *at_9cec50(int x, int y) throw();
	int width;
	int height;
	bool *cells;
};
struct A2CGrid
{
	void init_9cf690(int width, int height, int value);
	int getWidth_9fcd80() throw();
	int getHeight_9b8f00() throw();
	int *at_9ceda0(int x, int y) throw();
	int *atPoint_9ced70(A2CPos &p) throw();
};
struct A2CRoom	// 0x6c bytes
{
	A2CRoom();	// 0x4bd0f0
	~A2CRoom();	// 0x4bd140
	int type;
	A2CRect rect;
	vector<A2CPos> cells;	// +0x14
	int category;	// +0x24
	char pad28[0x6c - 0x28];
};
struct A2CSpawn	// 0x84 bytes
{
	bool enabled;
	int level;
	int weight;
	int chance;
	char pad10[0x84 - 0x10];
};
struct A2CRecord	// 0xac bytes
{
	bool enabled;
	int level;
	int chance;
	int type;
	int index;
	string name;	// +0x14
	string suffix;	// +0x30
	bool flag4c;	// +0x4c
	char pad4d[0x6c - 0x4d];
	int group;	// +0x6c
	vector<unsigned int> directions;	// +0x70
	int category;	// +0x80
	bool flag84;	// +0x84
	char pad85[0x88 - 0x85];
	A2CRange range88;
	A2CRange range90;
	A2CRange range98;
	A2CRange rangeA0;
	int extra;
};
struct A2CBridgeSpec	// 0x34 bytes
{
	bool enabled;
	int level;
	int weight;
	int chance;
	char pad10[0x34 - 0x10];
};
struct A2CSettings	// cave settings (0xa4 bytes)
{
	A2CSettings();	// 0x4492b0
	~A2CSettings();	// 0x449540 (scalar deleting)
	bool read_4c8740(const string &filename, bool binary);

	char pad0[0x1c];
	int f1c;	// +0x1c
	char pad20[0x38 - 0x20];
	int levelCount;	// +0x38
	char pad3c[0x64 - 0x3c];
	int width;	// +0x64
	int height;	// +0x68
	int seed;	// +0x6c
	vector<A2CRecord> records;	// +0x70
	vector<A2CBridgeSpec> bridges;	// +0x80
	char pad90[0xa4 - 0x90];
};
struct A2CWeights	// WeightList<int> (0x24 bytes)
{
	A2CWeights();	// 0x9bab50
	~A2CWeights();	// 0x700dd0
	bool contains_9b6f10(int *value);
	void add_9ba310(int value, int weight);
	int &pick_9ba470();
	int total_9b81d0() throw();
	int data[0x24 / 4];
};
struct A2CEdge	// 0x24 bytes
{
	A2CEdge() throw();	// 0x4cb8d0
	A2CPos pos;	// +0x00
	int dir;	// +0x08
	int value;	// +0x0c
	struct A2CArea
	{
		void set_40b360(const A2CPos &pos, int width, int height) throw();
		int data0, data4, data8, datac;
	} area;	// +0x10
	int extra;	// +0x20
};
extern A2CSettings *a2c_settings_cefb54;
extern A2CGrid a2c_grid_cf1964;
extern A2CGrid a2c_categories_cf447c;
extern vector<int> a2c_vec_cf4590;
extern vector<int> a2c_vec_d1ecc0;
extern vector<int> a2c_vec_d1defc;
struct A2CMark { int a, b; };
extern vector<A2CMark> a2c_marks_cf126c;
extern int a2c_count_ced16c;
struct A2CBlob { vector<A2CPos> cells; int unknown10; };
extern vector<A2CBlob> a2c_blobs_cf125c;
extern vector<A2CImage> a2c_images_cf124c;
extern vector<A2CImage *> a2c_prefabs_d161c4;
extern vector<vector<A2CPos> > a2c_groups_d02b4c;
extern vector<string> a2c_groupNames_d21768;
struct A2CPlaced
{
	int x, y, width, height;
	A2CPlaced(const A2CPos &pos, int width_, int height_) throw();	// 0x40a760
};
extern vector<A2CPlaced> a2c_placed_d39d30;
extern vector<string> a2c_disabled_d1e30c;
extern vector<string> a2c_unique_cf123c;
extern int a2c_maxDoorDistance_ced21c;
extern int a2c_rotations_bb8370[];
extern int a2c_cellTypes_bb8398[];
extern A2CColor a2c_colors_cf127c[];
extern A2CColor a2c_exitColor_d25f68;

bool a2c_containsString_9d3fe0(vector<string> &list, string value);
bool a2c_containsRecord_9db330(vector<int> &list, int value);
int a2c_popRandom_9de500(vector<int> &list);
void a2c_shuffle_9d8f80(vector<int> &list);
int a2c_findString_9ceb50(vector<string> &list, string value);
void a2c_eraseString_9cfab0(vector<string> &list, int index);
void a2c_eraseIndex_9ce6d0(vector<int> &list, unsigned int &index);
int a2c_randomRec_9d5d00(vector<unsigned int> &list);
int a2c_findColor_9d4f10(A2CColor *colors, unsigned int count, A2CColor color);
bool a2c_between_9daf80(int low, int value, int high);

A2CSettings::A2CSettings()
{
}

struct A2CIntGrid
{
	void init_9cf690(int width, int height, int value);
	int *at_9ceda0(int x, int y) throw();
	int width;
	int height;
	int *cells;
};
class A2CGenerator	// cave generator
{
public:
	void init(A2CSettings *settings, const string &path, const string &name, bool binary, bool keepSeed, bool newSeed, int level);

	string path;	// +0x00
	string name;	// +0x1c
	bool binary;	// +0x38
	int seed;	// +0x3c
	vector<A2CEdge> edges;	// +0x40
	int level;	// +0x50
	int f54;	// +0x54
	A2CIntGrid occupied;	// +0x58
	A2CIntGrid grid64;	// +0x64
	A2CIntGrid grid70;	// +0x70
	int f7c;	// +0x7c
	int f80;	// +0x80
	bool b84;	// +0x84
	bool b85;	// +0x85
};

void A2CGenerator::init(A2CSettings *settings, const string &path, const string &name, bool binary, bool keepSeed, bool newSeed, int filter)
{
restart:
	this->path = path;
	this->name = name;
	this->binary = binary;
	if (settings)
		a2c_settings_cefb54 = settings;
	else
	{
		delete a2c_settings_cefb54;
		a2c_settings_cefb54 = new A2CSettings();
		a2c_settings_cefb54->read_4c8740(this->path + this->name,this->binary);
	}
	a2c_vec_cf4590.assign(a2c_settings_cefb54->levelCount + 1u,0u);
	a2c_vec_d1ecc0.assign(a2c_settings_cefb54->levelCount + 1u,4);
	a2c_vec_d1defc.assign(4u,4);
	a2c_grid_cf1964.init_9cf690(a2c_settings_cefb54->width,a2c_settings_cefb54->height,3);
	a2c_categories_cf447c.init_9cf690(a2c_settings_cefb54->width,a2c_settings_cefb54->height,0);
	a2c_marks_cf126c.clear();
	a2c_count_ced16c = 0;
	a2c_blobs_cf125c.clear();
	a2c_images_cf124c.clear();
	if (!keepSeed || newSeed)
	{
		if (a2c_settings_cefb54->seed && !newSeed)
			seed = a2c_settings_cefb54->seed;
		else
			seed = rng.rangeInt(1,std::numeric_limits<int>::max());
		rng.seed(seed);
	}
	edges.clear();
	f54 = 0;
	occupied.init_9cf690(a2c_settings_cefb54->width,a2c_settings_cefb54->height,0);
	grid64.init_9cf690(a2c_settings_cefb54->width,a2c_settings_cefb54->height,-1);
	grid70.init_9cf690(a2c_settings_cefb54->width,a2c_settings_cefb54->height,-1);
	f7c = a2c_settings_cefb54->f1c;
	b84 = false;
	b85 = false;
	for (unsigned int i = 0; i < a2c_settings_cefb54->bridges.size(); i++)
		a2c_settings_cefb54->bridges[i].enabled = true;
	for (unsigned int i = 0; i < a2c_settings_cefb54->records.size(); i++)
		a2c_settings_cefb54->records[i].enabled = true;
	for (unsigned int i = 0; i < a2c_settings_cefb54->records.size(); i++)
	{
		if (a2c_containsString_9d3fe0(a2c_disabled_d1e30c,a2c_settings_cefb54->records[i].name))
			a2c_settings_cefb54->records[i].enabled = false;
	}
	for (unsigned int i = 0; i < a2c_settings_cefb54->bridges.size(); i++)
	{
		if (a2c_settings_cefb54->bridges[i].chance != -1 && a2c_settings_cefb54->bridges[i].chance < 100 && !rng.chance(a2c_settings_cefb54->bridges[i].chance))
			a2c_settings_cefb54->bridges[i].enabled = false;
	}
	for (unsigned int i = 0; i < a2c_settings_cefb54->records.size(); i++)
	{
		if (a2c_settings_cefb54->records[i].chance != -1 && a2c_settings_cefb54->records[i].chance < 100 && !rng.chance(a2c_settings_cefb54->records[i].chance))
			a2c_settings_cefb54->records[i].enabled = false;
	}
	A2CWeights weight;
	for (unsigned int i = 0; i < a2c_settings_cefb54->bridges.size(); i++)
	{
		if (a2c_settings_cefb54->bridges[i].enabled && a2c_settings_cefb54->bridges[i].level && !weight.contains_9b6f10(&a2c_settings_cefb54->bridges[i].level) && (filter == -1 || a2c_settings_cefb54->bridges[i].level == filter))
			weight.add_9ba310(a2c_settings_cefb54->bridges[i].level,a2c_settings_cefb54->bridges[i].weight);
	}
	level = weight.total_9b81d0() ? weight.pick_9ba470() : 0;
	vector<int> flags;
	vector<int> vec;
	bool ok;
	do
	{
		ok = false;
		for (int i = 0; i < a2c_settings_cefb54->records.size(); i++)
		{
			if (a2c_settings_cefb54->records[i].enabled && (a2c_settings_cefb54->records[i].level == level || a2c_settings_cefb54->records[i].level == 0) && a2c_settings_cefb54->records[i].group && !a2c_containsRecord_9db330(flags,a2c_settings_cefb54->records[i].group))
			{
				ok = true;
				vec.clear();
				vec.push_back(i);
				for (int j = i + 1; j < a2c_settings_cefb54->records.size(); j++)
				{
					if (a2c_settings_cefb54->records[j].enabled && (a2c_settings_cefb54->records[j].level == level || a2c_settings_cefb54->records[j].level == 0) && a2c_settings_cefb54->records[j].group == a2c_settings_cefb54->records[i].group)
						vec.push_back(j);
				}
				a2c_popRandom_9de500(vec);
				for (unsigned int k = 0; k < vec.size(); k++)
					a2c_settings_cefb54->records[vec[k]].enabled = false;
				flags.push_back(a2c_settings_cefb54->records[i].group);
			}
		}
	}
	while (ok);
	vector<int> current;
	for (int i = 0; i < a2c_settings_cefb54->records.size(); i++)
	{
		if (a2c_settings_cefb54->records[i].enabled && a2c_settings_cefb54->records[i].chance == -1 && (a2c_settings_cefb54->records[i].level == level || a2c_settings_cefb54->records[i].level == 0))
			current.push_back(i);
	}
	a2c_shuffle_9d8f80(current);
	vector<string> parts(a2c_unique_cf123c);
	for (unsigned int i = 0; i < current.size(); i++)
	{
		string suffix = a2c_settings_cefb54->records[current[i]].suffix;
		int index = a2c_findString_9ceb50(parts,suffix);
		if (index != -1)
		{
			a2c_eraseString_9cfab0(parts,index);
			a2c_eraseIndex_9ce6d0(current,i);
		}
	}
	for (unsigned int i = 0; i < current.size(); i++)
		a2c_settings_cefb54->records[current[i]].enabled = false;
	a2c_groups_d02b4c.clear();
	a2c_groups_d02b4c.assign(5,vector<A2CPos>());
	a2c_groupNames_d21768.clear();
	a2c_placed_d39d30.clear();
	for (unsigned int i = 0; i < a2c_settings_cefb54->records.size(); i++)
	{
		if (a2c_settings_cefb54->records[i].enabled && (a2c_settings_cefb54->records[i].level == level || a2c_settings_cefb54->records[i].level == 0))
		{
			A2CRecord *record = &a2c_settings_cefb54->records[i];
			if (record->type < 21)
			{
				A2CRect area(record->range88.randomInRange_40c130(),record->range90.randomInRange_40c130(),record->range98.randomInRange_40c130(),record->rangeA0.randomInRange_40c130());
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
				if (area.x + area.width >= a2c_grid_cf1964.getWidth_9fcd80() - 1)
					area.width = a2c_grid_cf1964.getWidth_9fcd80() - 2 - area.x;
				if (area.y + area.height >= a2c_grid_cf1964.getHeight_9b8f00() - 1)
					area.height = a2c_grid_cf1964.getHeight_9b8f00() - 2 - area.y;
				for (int x = area.x; x < area.x + area.width; x++)
				{
					for (int y = area.y; y < area.y + area.height; y++)
					{
						*a2c_grid_cf1964.at_9ceda0(x,y) = record->type;
						*occupied.at_9ceda0(x,y) = record->type != 3;
						*a2c_categories_cf447c.at_9ceda0(x,y) = record->type == 3 ? 0 : record->category;
					}
				}
			}
			else
			{
				A2CImage temp;
				int other;
				a2c_images_cf124c.push_back(temp);
				A2CImage *list = &a2c_images_cf124c.back();
				a2c_images_cf124c.back() = *a2c_prefabs_d161c4[record->index];
				a2c_images_cf124c.back().rotation = a2c_randomRec_9d5d00(record->directions);
				a2c_images_cf124c.back().placed = false;
				for (int r = 0; r < a2c_rotations_bb8370[a2c_images_cf124c.back().rotation]; r++)
					list->rotate_447010(true);
				A2CArt *layer = list->layers.front();
				if (record->range88.high + layer->getWidth_9fcd80() - 1 < a2c_grid_cf1964.getWidth_9fcd80())
					layer->getHeight_9b8f00() < a2c_grid_cf1964.getHeight_9b8f00();
				A2CPos point(record->range88.randomInRange_40c130(),record->range90.randomInRange_40c130());
				if (record->flag4c)
				{
					for (int tries = 0; tries < 2000; tries++)
					{
						bool blocked = false;
						for (int x = point.x; x < layer->getWidth_9fcd80() + point.x; x++)
						{
							for (int y = point.y; y < layer->getHeight_9b8f00() + point.y; y++)
							{
								if (*occupied.at_9ceda0(x,y) != 0)
								{
									blocked = true;
									break;
								}
							}
						}
						if (!blocked)
							goto placed;
						point.set_40a010(record->range88.randomInRange_40c130(),record->range90.randomInRange_40c130());
					}
					goto restart;
				}
placed:
				a2c_images_cf124c.back().offset = point;
				if (record->flag84)
					a2c_placed_d39d30.push_back(A2CPlaced(point,layer->getWidth_9fcd80(),layer->getHeight_9b8f00()));
				vector<A2CPos> elements;
				for (int x = 0; x < layer->getWidth_9fcd80(); x++)
				{
					for (int y = 0; y < layer->getHeight_9b8f00(); y++)
					{
						other = a2c_findColor_9d4f10(a2c_colors_cf127c,9,*layer->at_9cdf20(x,y)->getBack_416f60());
						*a2c_grid_cf1964.at_9ceda0(point.x + x,point.y + y) = other == 4 ? 9 : other == 5 ? 8 : a2c_cellTypes_bb8398[other];
						if (a2c_between_9daf80(0,layer->at_9cdf20(x,y)->glyph_9b8f00() - 48,4))
						{
							*a2c_grid_cf1964.at_9ceda0(point.x + x,point.y + y) = layer->at_9cdf20(x,y)->glyph_9b8f00() - 32;
							elements.push_back(A2CPos(point.x + x,point.y + y));
						}
						if (a2c_cellTypes_bb8398[other] != 3)
							*occupied.at_9ceda0(point.x + x,point.y + y) = 1;
						if (*a2c_grid_cf1964.at_9ceda0(point.x + x,point.y + y) != 3)
							*a2c_categories_cf447c.at_9ceda0(point.x + x,point.y + y) = record->category;
					}
				}
				for (unsigned int m = 0; m < elements.size(); m++)
				{
					a2c_groups_d02b4c[*a2c_grid_cf1964.atPoint_9ced70(elements[m]) - 16].push_back(A2CPos(elements[m]));
					if (*a2c_grid_cf1964.atPoint_9ced70(elements[m]) == 20)
						a2c_groupNames_d21768.push_back(record->suffix);
					for (int dx = -1; dx <= 1; dx++)
					{
						for (int dy = -1; dy <= 1; dy++)
						{
							if (a2c_between_9daf80(4,*a2c_grid_cf1964.at_9ceda0(elements[m].x + dx,elements[m].y + dy),9))
							{
								*a2c_grid_cf1964.atPoint_9ced70(elements[m]) = *a2c_grid_cf1964.at_9ceda0(elements[m].x + dx,elements[m].y + dy);
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
						if (*a2c_grid_cf1964.at_9ceda0(x,y) == 10 && y > 0 && *a2c_grid_cf1964.at_9ceda0(x,y - 1) >= 4 && *a2c_grid_cf1964.at_9ceda0(x,y - 1) != 10 && *a2c_grid_cf1964.at_9ceda0(x,y - 1) != 11)
							*a2c_grid_cf1964.at_9ceda0(x,y) = 11;
					}
				}
				if (list->layers.size() >= 2)
				{
					A2CArt *exitLayer = list->layers[1];
					for (int x = 0; x < exitLayer->getWidth_9fcd80(); x++)
					{
						for (int y = 0; y < exitLayer->getHeight_9b8f00(); y++)
						{
							if (*exitLayer->at_9cdf20(x,y)->getBack_416f60() == a2c_exitColor_d25f68)
							{
								A2CEdge edge;
								edges.push_back(edge);
								A2CEdge *added = &edges.back();
								added->dir = 0;
								int limit = y;
								if (exitLayer->getWidth_9fcd80() - 1 - x < limit)
								{
									limit = exitLayer->getWidth_9fcd80() - 1 - x;
									added->dir = 1;
								}
								if (exitLayer->getHeight_9b8f00() - 1 - y < limit)
								{
									limit = exitLayer->getHeight_9b8f00() - 1 - y;
									added->dir = 2;
								}
								if (x < limit)
								{
									limit = x;
									added->dir = 3;
								}
								added->pos.set_40a010(point.x + x,point.y + y);
								a2c_between_9daf80(49,exitLayer->at_9cdf20(x,y)->glyph_9b8f00(),57);
								if (false) {}
								added->value = exitLayer->at_9cdf20(x,y)->glyph_9b8f00() - 48;
								added->area.set_40b360(point,exitLayer->getWidth_9fcd80(),exitLayer->getHeight_9b8f00());
								added->extra = a2c_settings_cefb54->records[i].extra;
							}
						}
					}
				}
			}
		}
	}
}
