// op_r4_a: game data loaders and small helpers in 0x777000-0x7a8000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include "../game/luigiai.h"
#include "../thirdparty/zfstream.h"
using namespace std;

struct Point
{
	int x;
	int y;

	Point(int x_, int y_);	// 0x409990
	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);	// NOTE: folded with the copy constructor (0x46ca50)
};

struct RectXYWH	// NOTE: placeholder name
{
	int x;
	int y;
	int w;
	int h;
};

struct Area	// NOTE: placeholder name
{
	Point min;
	Point max;

	Area(const RectXYWH &r);	// 0x40b290
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	int getWidth();	// NOTE: placeholder name (0x9fcd80)
	int getHeight();	// NOTE: placeholder name (0x9b8f00)
};
class Cell;
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

struct OpR4a_LocationInfo	// NOTE: placeholder name
{
	int unknown0;
	int type;
	int depth;
};

class OpR4a_HLocation	// NOTE: placeholder name
{
public:
	int ID;
	OpR4a_LocationInfo *operator->() const;	// 0x9b7910
};
extern OpR4a_HLocation opr4a_location;	// NOTE: placeholder name (0xd1e888)

template <class T>
class OpR4a_WeightedList	// NOTE: placeholder name
{
public:
	vector<T> values;
	vector<int> weights;
	int total;

	void add(T value, int weight);	// NOTE: placeholder name (0x9ba310)
	bool isEmpty();	// NOTE: placeholder name (0x9b81b0)
	T &pick();	// NOTE: placeholder name (0x9ba470)
};

class Console;
class XConsole
{
public:
	bool isHidden();
};

class BS	// map object (0xcefc4c)
{
public:
	bool unknown71bbd0();	// NOTE: placeholder name
};

class OpR4a_Quit46dd50	// NOTE: placeholder name
{
public:
	bool unknown46dd50();	// NOTE: placeholder name
};

class Wrapper_470c20
{
	char unknown00[0x14];
	char field[1];
public:
	void cleanup();
};

class Push_470b90
{
public:
	char unknown0[0xc];
	int fieldc;
	void operate(int arg0);
};

class Stats_Combat
{
public:
	int GetCachedSize() const;
};

template <class T> void deleteVector(vector<T*> &v);	// NOTE: placeholder name (0x9d21f0 for Console)

extern int *opr4a_cec144;	// NOTE: placeholder name
extern int *opr4a_cec134;	// NOTE: placeholder name
extern int *opr4a_cec130;	// NOTE: placeholder name
extern XConsole *opr4a_cec0f8;	// NOTE: placeholder name
extern int *opr4a_cec140;	// NOTE: placeholder name
extern bool opr4a_cefacd;	// NOTE: placeholder name
extern OpR4a_Quit46dd50 opr4a_cf45d8;	// NOTE: placeholder name
extern int *opr4a_cefb1c;	// NOTE: placeholder name
extern bool opr4a_cefb18;	// NOTE: placeholder name
extern BS *opr4a_world;	// NOTE: placeholder name (0xcefc4c)
extern int opr4a_cf4b38;	// NOTE: placeholder name
struct OpR4a_Achievement	// NOTE: placeholder name
{
	char pad0[4];
	string name;
};
extern vector<OpR4a_Achievement *> opr4a_cf09a8;	// NOTE: placeholder name
extern vector<int> opr4a_cf47dc;	// NOTE: placeholder name
extern vector<Console*> opr4a_cf47ec;	// NOTE: placeholder name
extern Wrapper_470c20 *opr4a_cefaa8;	// NOTE: placeholder name
extern Stats_Combat *opr4a_cefa8c;	// NOTE: placeholder name
extern unsigned int tickCount;	// 0xcaed20

bool opr4a_unknown778220()	// NOTE: placeholder name
{
	return !opr4a_cec144 && !opr4a_cec134 && !opr4a_cec130 && opr4a_cec0f8->isHidden() && !opr4a_cec140
		&& (!(opr4a_cefacd || opr4a_cf45d8.unknown46dd50()) || opr4a_cefb1c || opr4a_cefb18)
		&& opr4a_world && !opr4a_world->unknown71bbd0() && opr4a_cf4b38 != 21;
}

class OpR4a_Unk778500	// NOTE: placeholder name
{
	char pad[0x188];
	vector<Console*> consoles;
public:
	void unknown778500();	// NOTE: placeholder name
};

void OpR4a_Unk778500::unknown778500()
{
	deleteVector(consoles);
	int zero = 0;
	opr4a_cf47dc.assign(opr4a_cf09a8.size(), zero);
	opr4a_cf47ec.clear();
	if (opr4a_cefaa8)
		opr4a_cefaa8->cleanup();
}

void opr4a_unknown789a70()	// NOTE: placeholder name
{
	if (opr4a_cefaa8)
	{
		if (tickCount - opr4a_cefa8c->GetCachedSize() > 10000)
			((Push_470b90*)opr4a_cefaa8)->operate(tickCount - opr4a_cefa8c->GetCachedSize() - 10000);
	}
}

class OpR4a_Unk777aa0	// NOTE: placeholder name
{
	char pad0[0xc18];
public:
	vector<int> groupIDs;	// 0xc18
	vector<vector<Point> > groupPoints;	// 0xc28

	void addGroup(int groupID, const RectXYWH &rect, vector<Point> *points);	// NOTE: placeholder name
};

void OpR4a_Unk777aa0::addGroup(int groupID, const RectXYWH &rect, vector<Point> *points)
{
	groupIDs.push_back(groupID);
	groupPoints.push_back(vector<Point>());
	if (points)
	{
		groupPoints.back() = *points;
	}
	else
	{
		vector<Point> &list = groupPoints.back();
		Area area(rect);
		for (int x = area.min.x; x <= area.max.x; x++)
		{
			for (int y = area.min.y; y <= area.max.y; y++)
			{
				list.push_back(Point(x, y));
			}
		}
	}
}

struct OpR4a_LuigiAi : public LuigiAi	// NOTE: placeholder name
{
	void unknown777bc0();	// NOTE: placeholder name
};

void OpR4a_LuigiAi::unknown777bc0()
{
	mapWidth = cells.getWidth();
	mapHeight = cells.getHeight();
	locationDepth = -opr4a_location->depth;
	locationMap = opr4a_location->type;
	if (mapData)
		cleanup();
	mapData = new LuigiTile[mapWidth * mapHeight];
}

struct OpR4a_ItemType	// NOTE: placeholder name
{
	char pad0[0xf4];
	int unknownf4;
	char padf8[0x20c - 0xf8];
	int unknown20c;
};
extern vector<OpR4a_ItemType *> opr4a_itemTypes;	// NOTE: placeholder name (0xd2d1c4)
extern int opr4a_table_ba3acc[];	// NOTE: placeholder name
extern OpR4a_WeightedList<OpR4a_ItemType *> opr4a_itemSet;	// NOTE: placeholder name (0xd39794)
extern int opr4a_cf462c;	// NOTE: placeholder name
extern int opr4a_cf4730;	// NOTE: placeholder name

OpR4a_ItemType *opr4a_unknown777cf0()	// NOTE: placeholder name
{
	if (opr4a_itemSet.isEmpty())
	{
		for (unsigned int i = 0; i < opr4a_itemTypes.size(); i++)
		{
			if (opr4a_itemTypes[i]->unknown20c)
				opr4a_itemSet.add(opr4a_itemTypes[i], opr4a_table_ba3acc[opr4a_itemTypes[i]->unknown20c]);
		}
	}
	OpR4a_ItemType *item = *&opr4a_itemSet.pick();
	if (opr4a_cf462c == 5 || opr4a_cf4730)
	{
		while (item->unknownf4 == 7)
			item = opr4a_itemSet.pick();
	}
	return item;
}

struct OpQ5_U9d2090;
template <class T> void OpQ5_readVectors(istream &stream, vector< vector<T> > &v);	// NOTE: placeholder name (0x9d2090)
void OpR4b_readVector9cf5e0(istream &stream, vector<int> &v);	// NOTE: placeholder name

struct OpR4a_Node1;
struct OpR4a_Link1	// NOTE: placeholder name
{
	OpR4a_Node1 *node;
	char pad4[0x3c - 4];
};

struct OpR4a_Node1	// NOTE: placeholder name
{
	char pad0[0xb8];
	vector<OpR4a_Link1> links;	// 0xb8
};

struct OpR4a_Node2;
struct OpR4a_Link2	// NOTE: placeholder name
{
	OpR4a_Node2 *node;
	char pad4[0x48 - 4];
};

struct OpR4a_Node2	// NOTE: placeholder name
{
	char pad0[0xcc];
	vector<OpR4a_Link2> links;	// 0xcc
};

struct OpR4a_Part	// NOTE: placeholder name
{
	int unknown0;
};

struct OpR4a_Node4	// NOTE: placeholder name
{
	char pad0[0x154];
	OpR4a_ItemType *itemType;	// 0x154
};

struct OpR4a_Node3	// NOTE: placeholder name
{
	char pad0[0x20];
	OpR4a_ItemType *itemType;	// 0x20
	OpR4a_Node4 *node4;	// 0x24
	char pad28[0x9c - 0x28];
	vector<OpR4a_Part *> parts;	// 0x9c
};

struct OpR4a_Node6;

struct OpR4a_Node7	// NOTE: placeholder name
{
	char pad0[4];
	OpR4a_Node6 *node;	// 4
};

struct OpR4a_Node6	// NOTE: placeholder name
{
	char pad0[0xb0];
	vector<OpR4a_Node7 *> links;	// 0xb0
};

extern vector<vector<int> > opr4a_d20454;	// NOTE: placeholder name
extern vector<vector<int> > opr4a_cfb938;	// NOTE: placeholder name
extern vector<int> opr4a_cfb908;	// NOTE: placeholder name
extern vector<int> opr4a_cfb918;	// NOTE: placeholder name
extern vector<int> opr4a_cfb928;	// NOTE: placeholder name
extern vector<vector<int> > opr4a_d29734;	// NOTE: placeholder name
extern vector<vector<int> > opr4a_cfb8f8;	// NOTE: placeholder name
extern vector<OpR4a_Node1 *> opr4a_cf67c0;	// NOTE: placeholder name
extern vector<OpR4a_Node2 *> opr4a_cfe704;	// NOTE: placeholder name
extern vector<OpR4a_Node3 *> opr4a_cfd2cc;	// NOTE: placeholder name
extern vector<OpR4a_Node4 *> opr4a_cf35b0;	// NOTE: placeholder name
extern vector<OpR4a_Part *> opr4a_d2c408;	// NOTE: placeholder name
extern vector<OpR4a_Node6 *> opr4a_d35b58;	// NOTE: placeholder name
extern int opr4a_caf164;	// NOTE: placeholder name
extern int opr4a_caf15c;	// NOTE: placeholder name

void opr4a_unknown777dd0(istream &stream)	// NOTE: placeholder name
{
	OpQ5_readVectors(stream, (vector< vector<OpQ5_U9d2090> > &)opr4a_d20454);
	for (unsigned int i = 0; i < opr4a_d20454.size(); i++)
	{
		for (unsigned int j = 0; j < opr4a_d20454[i].size(); j++)
		{
			opr4a_cf67c0[i]->links[j].node = opr4a_cf67c0[opr4a_d20454[i][j]];
		}
	}
	opr4a_d20454.clear();
	OpQ5_readVectors(stream, (vector< vector<OpQ5_U9d2090> > &)opr4a_cfb938);
	for (unsigned int i = 0; i < opr4a_cfb938.size(); i++)
	{
		for (unsigned int j = 0; j < opr4a_cfb938[i].size(); j++)
		{
			opr4a_cfe704[i]->links[j].node = opr4a_cfe704[opr4a_cfb938[i][j]];
		}
	}
	opr4a_cfb938.clear();
	OpR4b_readVector9cf5e0(stream, opr4a_cfb908);
	OpR4b_readVector9cf5e0(stream, opr4a_cfb918);
	OpQ5_readVectors(stream, (vector< vector<OpQ5_U9d2090> > &)opr4a_d29734);
	for (unsigned int i = 0; i < opr4a_cfd2cc.size(); i++)
	{
		if (opr4a_cfb908[i] != opr4a_caf164)
			opr4a_cfd2cc[i]->itemType = opr4a_itemTypes[opr4a_cfb908[i]];
		if (opr4a_cfb918[i] != opr4a_caf15c)
			opr4a_cfd2cc[i]->node4 = opr4a_cf35b0[opr4a_cfb918[i]];
		for (unsigned int j = 0; j < opr4a_d29734[i].size(); j++)
		{
			opr4a_cfd2cc[i]->parts.push_back(opr4a_d2c408[opr4a_d29734[i][j]]);
		}
	}
	opr4a_cfb908.clear();
	opr4a_cfb918.clear();
	opr4a_d29734.clear();
	OpR4b_readVector9cf5e0(stream, opr4a_cfb928);
	for (unsigned int i = 0; i < opr4a_cf35b0.size(); i++)
	{
		if (opr4a_cfb928[i] != opr4a_caf164)
			opr4a_cf35b0[i]->itemType = opr4a_itemTypes[opr4a_cfb928[i]];
	}
	opr4a_cfb928.clear();
	OpQ5_readVectors(stream, (vector< vector<OpQ5_U9d2090> > &)opr4a_cfb8f8);
	for (unsigned int i = 0; i < opr4a_d35b58.size(); i++)
	{
		for (unsigned int j = 0; j < opr4a_cfb8f8[i].size(); j++)
		{
			opr4a_d35b58[i]->links[j]->node = opr4a_d35b58[opr4a_cfb8f8[i][j]];
		}
	}
	opr4a_cfb8f8.clear();
}

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
string opY3_dateString(int a, int b, int c);	// NOTE: placeholder name (0x436e70)
extern int opr4a_d25740;	// NOTE: placeholder name
extern int opr4a_cf4718;	// NOTE: placeholder name

class OpR4a_Unk7782d0	// NOTE: placeholder name
{
public:
	int ID;
	string name;
	int first;
	int second;
	int unknown28;
	int unknown2c;

	OpR4a_Unk7782d0(int ID_, int a, int b);	// 0x7782d0
};

OpR4a_Unk7782d0::OpR4a_Unk7782d0(int ID_, int a, int b)
	: ID(ID_)
	, name(opr4a_cf09a8[ID]->name)
{
	string date = opY3_dateString(0, a, b);
	first = stringToInt(string(date.begin(), date.begin() + date.find('-')));
	second = stringToInt(string(date.begin() + date.find('-') + 1, date.end()));
	unknown28 = opr4a_d25740;
	unknown2c = opr4a_cf4718;
}

string opr1c_getSaveName_432af0(int version, bool error);	// 0x432af0, NOTE: placeholder name
string opr1c_getChronoSaveName_432d80();	// 0x432d80, NOTE: placeholder name
string opr1c_getManualSaveName_432f20(const string &name);	// 0x432f20, NOTE: placeholder name
string intToString(int value);
bool opW5_replace(string &text, string from, string to);	// NOTE: placeholder name (0x407e00)
void OpQ1_readString(istream &in, string *text);	// NOTE: placeholder name (0x4096f0)
extern string opr4a_cf45f8;	// NOTE: placeholder name
extern string opr4a_d204b0;	// NOTE: placeholder name

template <class T> void readBinary(istream &stream, T *value)	// NOTE: placeholder name
{
	stream.read((char*)value, sizeof(T));
}

int opr4a_unknown77e2b0(gzifstream &stream, bool chrono, bool manual)	// NOTE: placeholder name
{
	string path = manual ? opr1c_getManualSaveName_432f20(opr4a_cf45f8) : chrono ? opr1c_getChronoSaveName_432d80() : opr1c_getSaveName_432af0(0x5e, false);
	stream.open(path.c_str(), 0x20);
	if (!stream.is_open())
		return 1;
	string version;
	OpQ1_readString(stream, &version);
	opr4a_d204b0.clear();
	OpQ1_readString(stream, &opr4a_d204b0);
	int ver;
	readBinary(stream, &ver);
	if (ver != 0x5e)
	{
		stream.close();
		string suffix = "_v" + intToString(ver);
		int loc = path.find("_v", 0);
		int end = path.find("_", loc + 2);
		string old(path.begin() + loc, path.begin() + end);
		string copy = path;
		opW5_replace(copy, old, suffix);
		rename(path.c_str(), copy.c_str());
		return 2;
	}
	else
		return 0;
}
