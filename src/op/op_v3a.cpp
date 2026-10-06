// op_v3a: world exit/companion helpers in 0x6cb000-0x6f0000 matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	Point(const Point &p) throw();	// 0x46ca50
	Point(const Point &p, int dx, int dy);	// 0x4099c0
};

struct OpC_Node;	// NOTE: placeholder name
class OpC_HNode	// NOTE: placeholder name
{
	int ID;
public:
	OpC_HNode() throw();
	OpC_Node *operator->() const;
	bool isValid() const;
};
struct OpC_Node	// NOTE: placeholder name
{
	int pad0;
	int type;
	int ID;
	vector<OpC_HNode> links;
	char pad1c[0x25 - 0x1c];
	bool shortcutAppearance;	// NOTE: placeholder name
};
extern OpC_HNode opX1_rootNode;	// NOTE: placeholder name (0xd1e888)

class HProp
{
	int ID;
public:
	HProp() throw();
};

struct OpX1_ExitRecord	// NOTE: placeholder name
{
	Point position;
	OpC_HNode node;
	bool active;
	bool revealed;
	char paddingE[0x60 - 0xe];
	OpX1_ExitRecord(const Point &pos, OpC_HNode node_, bool active_, HProp existing, HProp other) throw();	// 0x6c13a0
};

class Cell
{
public:
	int unknown45d0e0();	// NOTE: placeholder name
	void unknown66a050(int terrainID, int cause, int flag);	// NOTE: placeholder name
	bool canPlaceEntity(int size) throw();	// 0x66ad20
};
class Push_66b640	// NOTE: placeholder name
{
public:
	void operate();
};
template <class T> class Array2D	// NOTE: placeholder name
{
	int width;
	int height;
	T *data;
public:
	T &operator()(const Point &pos);	// 0x9ced70
	Point getRandom_9cf050() throw();	// NOTE: placeholder name
};
extern Array2D<Cell *> cells;	// 0xcfd44c

class BS
{
public:
	char pad0[0x10];
	vector<OpX1_ExitRecord *> exits;
	void unknown6eab60();	// NOTE: placeholder name
};

void BS::unknown6eab60()
{
	OpC_HNode node;
	for (unsigned int i = 0; i < opX1_rootNode->links.size(); i++)
	{
		if (opX1_rootNode->links[i]->type == 0x21)
		{
			node = opX1_rootNode->links[i];
			break;
		}
	}
	if (node.isValid())
	{
		OpX1_ExitRecord *existing = NULL;
		for (unsigned int j = 0; j < exits.size(); j++)
		{
			if (exits[j]->node->type == 0x20)
			{
				existing = exits[j];
				break;
			}
		}
		Point pos(existing->position,0,-5);
		OpX1_ExitRecord *record = static_cast<OpX1_ExitRecord *const &>(new OpX1_ExitRecord(pos,node,true,HProp(),HProp()));
		exits.push_back(record);
		cells(record->position)->unknown66a050(cells(existing->position)->unknown45d0e0(),2,0);
		if (node->shortcutAppearance)
			reinterpret_cast<Push_66b640 *>(cells(record->position))->operate();
	}
}

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect() throw();	// 0x40a6e0
	Rect(const Rect &rect) throw();	// 0x40a720
	Rect &operator=(const Rect &rect) throw();	// NOTE: folded with the copy ctor (0x40a720)
	Point randomPos_40b080() throw();	// NOTE: placeholder name
};

struct OpV3a_Room	// NOTE: placeholder name (DF::Room)
{
	int type;
	Rect rect;
	vector<int> unknown14;
	int unknown24;
	vector<Point> doors;
	vector<int> doorDirs;
	vector<int> corridors;
	int unknown58;
	vector<int> unknown5c;
	~OpV3a_Room() throw();	// 0x4bd140
};
extern vector<OpV3a_Room> opV3a_rooms;	// NOTE: placeholder name (0xcf13e8)
OpV3a_Room opV3a_randomRoom_9db4b0(vector<OpV3a_Room> &rooms) throw();	// NOTE: placeholder name

bool opR4_isEntrance(const Point &p) throw();	// NOTE: placeholder name (0x448b80)

Point opV3a_randomPlaceable_6ed660(vector<Rect> &first, vector<Rect> &second)	// NOTE: placeholder name
{
	Rect area;
	if (!first.empty())
	{
		area = first.back();
		first.pop_back();
	}
	else if (!second.empty())
	{
		area = second.back();
		second.pop_back();
	}
	else
	{
		area = opV3a_randomRoom_9db4b0(opV3a_rooms).rect;
	}
	for (int i = 0; i < 100; i++)
	{
		Point p = area.randomPos_40b080();
		if (cells(p)->canPlaceEntity(1) && !opR4_isEntrance(p))
			return p;
	}
	while (true)
	{
		Point p = cells.getRandom_9cf050();
		if (cells(p)->canPlaceEntity(1) && !opR4_isEntrance(p))
			return p;
	}
}
