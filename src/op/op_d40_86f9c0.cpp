// op_d40_86f9c0: draws edge markers for off-screen map records along the map console border (COGMIND.exe Beta 17.1).
// NOTE: placeholder names/layouts throughout; D40Map/D40Record match the declarations in loop_delta_40_collect.cpp.
#include <vector>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor() throw();
	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	XColor operator*(float value);
};

struct Pos	// NOTE: placeholder layout
{
	int x;
	int y;
	Pos(const Pos &pos) throw();
};

struct D40dPt	// NOTE: placeholder name (map point)
{
	int x;
	int y;
	D40dPt();	// 0x453b40
	D40dPt(int v);	// 0x409990
	D40dPt(const D40dPt &p);	// 0x46ca50
	D40dPt &operator=(const D40dPt &p);	// 0x46ca50
	D40dPt operator+(const D40dPt &p) const;	// 0x409b60
	D40dPt &operator+=(const D40dPt &p);	// 0x409a30
	void set(int x_, int y_);	// 0x40a010
	void translate(int dx, int dy);	// 0x40a2a0
};

class D40dEntity	// NOTE: placeholder name
{
public:
	const D40dPt &getPosition45a4a0();
	int getSize45a360();
	int getAscii5c7a10(const D40dPt &p);
	XColor &color5c7810();
};

struct D40dHandle	// NOTE: placeholder name (HEntity)
{
	unsigned int id;
	bool isValid9b7230() const;
	D40dEntity *operator->() const;	// 0x9b6570
};

struct D40Record	// NOTE: placeholder layout
{
	D40dHandle entity;
	D40dPt position;
	XColor color;
	int glyph;
};

class XConsole
{
public:
	bool isHidden();
	int getHeight();
	Pos getPos();
	void putChar_418150(int x, int y, int ch, XColor fore_, XColor back_, int flag);
};

class D40Map : public XConsole	// NOTE: placeholder layout
{
public:
	char base[0x6c];
	D40dPt offset;
	char pad74[0x36c - 0x74];
	XConsole *sub36c;
	char pad370[0x7a8 - 0x370];
	int field7a8;
	int width44b0d0();
	void draw86f9c0(int type, vector<D40Record *> *records, vector<int> *topUsed, vector<int> *bottomUsed, vector<int> *leftUsed, vector<int> *rightUsed);
};

bool blink_437320(unsigned int period);
bool OpT8b_Fn9daf80(int low, int value, int high);
int teamb_findFreeRun86f8a0(int start, int end, int count, vector<int> &used, bool forward);
void d40d_deleteStep9de640(vector<D40Record *> &v, int &index);	// NOTE: placeholder name (0x9de640)

extern XColor *d40d_cf6ed4, *d40d_d30424, *d40d_d316f4, *d40d_d22fcc, *d40d_d2175c, *d40d_cf44c0;
extern XColor *d40d_d28fc8, *d40d_d29d90, *d40d_d21f54, *d40d_d292f0, *d40d_cfe674;
extern bool d40d_d28d26;
extern int d40d_mapWidth_cf27f4, d40d_mapHeight_cf27f8;
extern XConsole *d40d_cec0f4;
extern const float d40d_c36eb4;

#define REC (*records)[i]

#define D40D_STYLE \
	bool hidden = false; \
	switch (type) \
	{ \
	case 0: \
	case 1: \
		c = REC->entity->getAscii5c7a10(base); \
		color = REC->entity->color5c7810(); \
		break; \
	case 2: \
		c = REC->glyph; \
		color = REC->color; \
		break; \
	case 3: \
		c = REC->entity->getAscii5c7a10(base); \
		color = REC->entity->color5c7810() * d40d_c36eb4; \
		if (blink_437320(750)) \
			hidden = true; \
		break; \
	case 4: \
		c = REC->glyph; \
		color = REC->color * d40d_c36eb4; \
		if (blink_437320(750)) \
			hidden = true; \
		break; \
	case 5: \
	case 6: \
		c = REC->glyph; \
		color = *d40d_cfe674; \
		if (blink_437320(750)) \
			hidden = true; \
		break; \
	}

#define D40D_PUT(X, Y) \
	if (!hidden) \
	{ \
		int px = X; \
		if (sub36c && !sub36c->isHidden() && X == width44b0d0() - 1 && OpT8b_Fn9daf80(1,Y,sub36c->getHeight())) \
			px = sub36c->getPos().x - 1; \
		int py = Y; \
		if (Y == 0) \
		{ \
			if (field7a8) \
				py++; \
			if (!d40d_cec0f4->isHidden()) \
				py++; \
		} \
		putChar_418150(px,py,c,color,back,1); \
	}

#define D40D_RUN(USED, X, Y, STEP) \
	do \
	{ \
		D40D_STYLE \
		D40D_PUT(X, Y) \
		(USED).push_back(index); \
		tiles--; \
		index STEP; \
		base += step; \
	} while (tiles != 0);

#define D40D_CORNER(FROM, TO, FWD, USED, TX, TY, SX, SY, X, Y, STEP) \
	index = teamb_findFreeRun86f8a0(FROM,TO,tiles,USED,FWD); \
	if (index != -1) \
	{ \
		base.translate(TX,TY); \
		step.set(SX,SY); \
		D40D_RUN(USED, X, Y, STEP) \
	} \
	d40d_deleteStep9de640(*records,i);

#define D40D_LOAD \
	point = (REC->entity.isValid9b7230() ? REC->entity->getPosition45a4a0() : REC->position) + offset; \
	tiles = REC->entity.isValid9b7230() ? REC->entity->getSize45a360() : 1; \
	base = REC->entity.isValid9b7230() ? REC->entity->getPosition45a4a0() : D40dPt(0);

void D40Map::draw86f9c0(int type, vector<D40Record *> *records, vector<int> *topUsed, vector<int> *bottomUsed, vector<int> *leftUsed, vector<int> *rightUsed)
{
	XColor color;
	XColor back;
	switch (type)
	{
	case 0:
		back = blink_437320(250) ? *d40d_cf6ed4 : *d40d_d30424;
		break;
	case 1:
		back = d40d_d28d26 ? (blink_437320(250) ? *d40d_d316f4 : *d40d_d22fcc) : (blink_437320(250) ? *d40d_d2175c : *d40d_cf44c0);
		break;
	case 2:
		back = blink_437320(250) ? *d40d_d316f4 : *d40d_d22fcc;
		break;
	case 3:
	case 4:
		back = *d40d_d28fc8;
		break;
	case 5:
		back = *d40d_d29d90 * d40d_c36eb4;
		break;
	case 6:
		back = *d40d_d21f54 * d40d_c36eb4;
		break;
	default:
		back = *d40d_d292f0;
		break;
	}
	D40dPt point;
	int count;	// NOTE: unused; reproduces the exe's spare slot at [ebp-0xc]
	D40dPt base;
	D40dPt step;
	int index;
	int c;
	int tiles;
	for (int i = 0; i < records->size(); i++)
	{
		D40D_LOAD
		if (point.x < 0)
		{
			if (point.y < 0)
			{
				if (point.x < point.y)
				{
					D40D_CORNER(1, d40d_mapHeight_cf27f8 - 2, true, *leftUsed, tiles - 1, 0, 0, 1, 0, index, ++)
				}
				else
				{
					D40D_CORNER(1, d40d_mapWidth_cf27f4 - 2, true, *topUsed, 0, tiles - 1, 1, 0, index, 0, ++)
				}
			}
			else if (point.y >= d40d_mapHeight_cf27f8)
			{
				if (-point.x > point.y - d40d_mapHeight_cf27f8)
				{
					D40D_CORNER(d40d_mapHeight_cf27f8 - 2, 1, false, *leftUsed, tiles - 1, tiles - 1, 0, -1, 0, index, --)
				}
				else
				{
					D40D_CORNER(1, d40d_mapWidth_cf27f4 - 2, true, *bottomUsed, 0, 0, 1, 0, index, d40d_mapHeight_cf27f8 - 1, ++)
				}
			}
		}
		else if (point.x >= d40d_mapWidth_cf27f4)
		{
			if (point.y < 0)
			{
				if (-(point.x - d40d_mapWidth_cf27f4) < point.y)
				{
					D40D_CORNER(1, d40d_mapHeight_cf27f8 - 2, true, *rightUsed, 0, 0, 0, 1, d40d_mapWidth_cf27f4 - 1, index, ++)
				}
				else
				{
					D40D_CORNER(d40d_mapWidth_cf27f4 - 2, 1, false, *topUsed, tiles - 1, tiles - 1, -1, 0, index, 0, --)
				}
			}
			else if (point.y >= d40d_mapHeight_cf27f8)
			{
				if (point.x - d40d_mapWidth_cf27f4 > point.y - d40d_mapHeight_cf27f8)
				{
					D40D_CORNER(d40d_mapHeight_cf27f8 - 2, 1, false, *rightUsed, 0, tiles - 1, 0, -1, d40d_mapWidth_cf27f4 - 1, index, --)
				}
				else
				{
					D40D_CORNER(d40d_mapWidth_cf27f4 - 2, 1, false, *bottomUsed, tiles - 1, 0, -1, 0, index, d40d_mapHeight_cf27f8 - 1, --)
				}
			}
		}
	}
	for (int i = 0; i < records->size(); i++)
	{
		D40D_LOAD
		if (point.x < 0 || point.x >= d40d_mapWidth_cf27f4)
		{
			bool left = point.x < 0;
			vector<int> &list = left ? *leftUsed : *rightUsed;
			int col = left ? 0 : d40d_mapWidth_cf27f4 - 1;
			index = teamb_findFreeRun86f8a0(point.y,d40d_mapHeight_cf27f8 - 2,tiles,list,true);
			if (index != -1)
			{
				left ? base.translate(tiles - 1,0) : base.translate(0,0);
				step.set(0,1);
				D40D_RUN(list, col, index, ++)
			}
			else
			{
				index = teamb_findFreeRun86f8a0(point.y,1,tiles,list,false);
				if (index != -1)
				{
					left ? base.translate(tiles - 1,tiles - 1) : base.translate(0,tiles - 1);
					step.set(0,-1);
					D40D_RUN(list, col, index, --)
				}
			}
		}
		else
		{
			bool upper = point.y < 0;
			vector<int> &list = upper ? *topUsed : *bottomUsed;
			int row = upper ? 0 : d40d_mapHeight_cf27f8 - 1;
			index = teamb_findFreeRun86f8a0(point.x,d40d_mapWidth_cf27f4 - 2,tiles,list,true);
			if (index != -1)
			{
				upper ? base.translate(0,tiles - 1) : base.translate(0,0);
				step.set(1,0);
				D40D_RUN(list, index, row, ++)
			}
			else
			{
				index = teamb_findFreeRun86f8a0(point.x,1,tiles,list,false);
				if (index != -1)
				{
					upper ? base.translate(tiles - 1,tiles - 1) : base.translate(tiles - 1,0);
					step.set(-1,0);
					D40D_RUN(list, index, row, --)
				}
			}
		}
	}
}
