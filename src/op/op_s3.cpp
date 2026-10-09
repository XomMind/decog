// op_s3: Cell methods (0x670b20-0x673b20) etc. matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member/method names are placeholders unless named in config/.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// NOTE: placeholder name (0xd30908)

struct Point
{
	int x;
	int y;

	Point();
	Point(int x_, int y_) throw();
	Point(const Point &p);
	Point &operator=(const Point &p);
	void set(int x_, int y_);
	void read(istream &stream);		// NOTE: placeholder name (0x40a330)
	void write(ostream &stream);	// NOTE: placeholder name (0x40a370)
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();
	XColor(const XColor &c);
	void read(istream &stream);
	void write(ostream &stream);
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const Point &p);	// 0x9ced70
	int getWidth();					// 0x9fcd80
	int getHeight();				// 0x9b8f00
};

class Cell;
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

class Entity;
class Prop;
class Group;

class HEntity	// NOTE: placeholder layout
{
	int	ID;
public:
	HEntity();
	bool isValid() const;
	bool isNull() const;
	Entity *operator->() const;
	void unknown9b7270();	// NOTE: placeholder name (resets the handle)
	void read(istream &stream);		// NOTE: placeholder name (0x9cfaf0)
	void write(ostream &stream);	// NOTE: placeholder name (0x9cfa90)
};

class Item;

class HItem
{
	int	ID;
public:
	HItem();
	bool isValid() const;
	Item *operator->() const;	// 0x9b65b0
};

struct ItemEffect;

class Item
{
public:
	ItemEffect *getEffect(int type);
	bool unknown457d70();
	int unknown457880();	// NOTE: placeholder name (ICF'd getter)
	int unknown4578a0();	// NOTE: placeholder name (ICF'd getter)
	bool unknown575850(HItem other);	// NOTE: placeholder name (sort order)
};

struct OpD_GameState	// NOTE: placeholder name
{
	int		unknown00;
	int		mapType;	// NOTE: placeholder name
};

class OpD_HGameState	// NOTE: placeholder name
{
	int	ID;
public:
	OpD_GameState *operator->() const;	// 0x9b7910
};

extern OpD_HGameState opd_gameState;	// NOTE: placeholder name (0xd1e888)
extern int opd_gameModeCf462c;			// NOTE: placeholder name (0xcf462c)
extern vector<HItem> opd_mapItems;		// NOTE: placeholder name (0xd33d74)
void opd_insertItem(vector<HItem> *v, int index, HItem item);	// NOTE: placeholder name (0x9d8fc0)
extern const float opd_itemDistanceLimit;	// NOTE: placeholder name (0xba76e4, 6.0f)
int distance(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)

class HProp
{
	int	ID;
public:
	HProp();
	bool isValid() const;
	bool isNull() const;
	Prop *operator->() const;
	void unknown9b7270();				// NOTE: placeholder name (resets the handle)
	void read(istream &stream);		// NOTE: placeholder name (0x9cfaf0)
	void write(ostream &stream);	// NOTE: placeholder name (0x9cfa90)
};

class HGroup	// NOTE: placeholder name
{
	int	ID;
public:
	HGroup();
	bool isValid() const;
	Group *operator->() const;	// 0x9b7250
};

class Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();	// NOTE: placeholder name (ICF'd getter)
};

class Entity
{
public:
	HGroup getGroup();
};

struct OpD_PropInfo	// NOTE: placeholder name (the machine/prop info behind Prop::unknown45cb30)
{
	char	pad00[0x10];
	bool	unknown10;
	bool	unknown11;
	char	pad12[0x28 - 0x12];
	int		unknown28;
	char	pad2c[0x34 - 0x2c];
	int		unknown34;
	char	pad38[0x78 - 0x38];
	unsigned char	*unknown78;
};

struct OpD_PropData	// NOTE: placeholder name
{
	char	pad[0xf8];
	int		unknownF8;
};

struct OpD_PropUnk44b020	// NOTE: placeholder name
{
	int		unknown00;
	int		unknown04;

	bool unknown65cf50(int groupType);	// NOTE: placeholder name
};

class Prop
{
public:
	bool isPassableFor(HEntity entity);		// NOTE: placeholder name (0x65e1d0)
	OpD_PropInfo *unknown45cb30();			// NOTE: placeholder name
	int unknown457b10();					// NOTE: placeholder name (ICF'd getter)
	int unknown44ab40();					// NOTE: placeholder name (ICF'd getter)
	OpD_PropData *unknown9b8f00();			// NOTE: placeholder name (ICF'd getter)
	OpD_PropUnk44b020 *unknown44b020();		// NOTE: placeholder name (ICF'd getter)
	int unknown45c650();					// NOTE: placeholder name (ascii)
	bool isTrap();							// NOTE: placeholder name (0x45cb70)
	void unknown6646f0(int a, int b, bool c, bool d);	// NOTE: placeholder name
	XColor unknown65dbb0();					// NOTE: placeholder name (color)
};

class BS
{
public:
	bool isVisible(const Point &p);
	bool unknown463e90(const Point &p);
	void unknown464ed0(HProp prop);
	void unknown727ea0(HItem item);
	void unknown7289f0(HItem item, int value);
	void unknown728f30(HItem item);
	int unknown4642d0();
	int unknown464000();
	int unknown717d60();
	vector<Point *> *unknown462e10();
	void addListB24(HItem item);
	int unknown463e50();
	void unknown4647a0(const Point &p, bool flag);
	void addPoint6a8(const Point &p);	// NOTE: placeholder name
	void unknown734d60(const Point &p);	// NOTE: placeholder name
};

class SoundMgr
{
public:
	void updatePropMute(HProp prop);	// 0x454520
	void unknown454500(const Point &p);	// NOTE: placeholder name
};

extern SoundMgr soundMgr;	// 0xd2d2a0

struct OpD_PropRegistry	// NOTE: placeholder name (object at 0xd1e720)
{
	void unknown9d0fc0(HProp prop, bool flag);	// NOTE: placeholder name
};

extern OpD_PropRegistry opd_propRegistry;	// NOTE: placeholder name (0xd1e720)
extern vector<vector<HProp> > opd_propsByD31640;	// NOTE: placeholder name (0xd31640)
extern vector<vector<Point> > opd_pointsByD2f32c;	// NOTE: placeholder name (0xd2f32c)
extern vector<vector<HProp> > opd_trapsByD20248;	// NOTE: placeholder name (0xd20248)
bool opd_eraseProp(vector<HProp> &v, HProp prop);	// NOTE: placeholder name (0x9d2f00)
void unknown9d0690(int *value, int delta, int limit);	// NOTE: placeholder name

extern BS *world;	// NOTE: placeholder name (0xcefc4c)

struct CellEffectRecord	// NOTE: partial record
{
	int type;
};

struct CellEffect	// NOTE: partial effect object
{
	CellEffectRecord	*record;
	int					value;

	CellEffect(const CellEffect &e)
		: record	(e.record)
		, value		(e.value)
	{};
};

struct OpD_TerrainBase	// NOTE: placeholder name
{
	char				pad00[0x3c];
	vector<CellEffect *>	effects;
};

struct OpD_TerrainSound;	// NOTE: placeholder name

struct CellTerrainRecord	// NOTE: member names are placeholders
{
	int					ID;
	string				name;
	string				tag;
	int					unknown3c;
	int					unknown40;
	XColor				foreColor;
	XColor				backColor;
	int					unknown4c;
	OpD_TerrainBase		*base;
	int					unknown54;
	bool				unknown58;
	int					passable;
	bool				unknown60;
	int					unknown64;
	int					armor;
	int					unknown6c;
	int					unknown70;
	int					unknown74;
	int					unknown78;
	bool				unknown7c;
	bool				unknown7d;
	vector<CellEffect *>	effects;
	string				description;
	OpD_TerrainSound	*sound1;
	OpD_TerrainSound	*sound2;
	OpD_TerrainSound	*sound3;
	string				unknownB8;
	int					unknownD4;
	int					unknownD8;
	bool				unknownDC;

	CellTerrainRecord(istream &stream);
};

extern CellTerrainRecord *TERRAIN_EARTH;
extern CellTerrainRecord *TERRAIN_CAVE_WALL;
extern CellTerrainRecord *caveinThirdTerrain;
extern CellTerrainRecord *opd_terrainCefb88;	// NOTE: placeholder name (0xcefb88)
extern CellTerrainRecord *opd_terrainCefb94;	// NOTE: placeholder name (0xcefb94)
extern CellTerrainRecord *opd_terrainCefb98;	// NOTE: placeholder name (0xcefb98)
extern CellTerrainRecord *opd_terrainCefb9c;	// NOTE: placeholder name (0xcefb9c)

extern bool asciiEnabled;				// NOTE: placeholder name (0xd28d30)
extern int opd_colorMode;				// NOTE: placeholder name (0xd28d44)
extern XColor opd_modeColors[];			// NOTE: placeholder name (0xd01714)
extern XColor &opd_colorD323c4;		// NOTE: placeholder name (0xd323c4)
extern const int opd_asciiTableA[];		// NOTE: placeholder name (0xba6a28)
extern const int opd_asciiTableB[];		// NOTE: placeholder name (0xba69e0)

extern vector<OpD_TerrainBase *> opd_terrainBases;		// NOTE: placeholder name (0xcf671c)
extern vector<OpD_TerrainSound *> opd_terrainSounds;	// NOTE: placeholder name (0xcfd2ec)
extern vector<CellTerrainRecord *> opd_terrainRecords;	// NOTE: placeholder name (0xcfb844)

// save/load helpers
template <class T> void readBinary(istream &stream, T *value);	// 0x9d8480, NOTE: placeholder name
void opd_readString(istream &stream, string *value);			// NOTE: placeholder name (0x4096f0)
void opd_readBool(istream &stream, bool *value);				// NOTE: placeholder name (0x9cf520)
void opd_readTerrainBase(istream &stream, OpD_TerrainBase **value, vector<OpD_TerrainBase *> &list);	// NOTE: placeholder name (0x9d92d0)
void opd_readTerrainSound(istream &stream, OpD_TerrainSound **value, vector<OpD_TerrainSound *> &list);	// NOTE: placeholder name (0x9d5880)
void opd_readTerrain(istream &stream, CellTerrainRecord **value, vector<CellTerrainRecord *> &list);	// NOTE: placeholder name (0x9da040)
void opd_readUnk465ea0(istream &stream, int *value);			// NOTE: placeholder name (0x465ea0)
void opd_readEffects(istream &stream, vector<CellEffect *> *value, int unknown);	// NOTE: placeholder name (0x9d6580)
void opd_readItems(istream &stream, vector<HItem> *value);		// NOTE: placeholder name (0x9da130)
void opd_writeTerrain(ostream &stream, CellTerrainRecord *value);	// NOTE: placeholder name (0x9da000)
void opd_writeInt(ostream &stream, int *value);					// NOTE: placeholder name (0x9d3b60)
void opd_writeString(ostream &stream, string value);			// NOTE: placeholder name (0x409650)
void opd_writeBool(ostream &stream, bool *value);				// NOTE: placeholder name (0x9cf540)
void opd_writeItems(ostream &stream, vector<HItem> *value);		// NOTE: placeholder name (0x9d9600)
void opd_writeEffects(ostream &stream, vector<CellEffect *> *value);	// NOTE: placeholder name (0x9d6770)

struct OpD_CellRange	// NOTE: placeholder name
{
	int	low;
	int	high;
};

extern OpD_CellRange opd_cellRanges[];	// NOTE: placeholder name (0xd25874)

void opd_clamp(int low, int &value, int high);	// NOTE: placeholder name (0x9cdc50)

class Cell
{
public:
	CellTerrainRecord	*terrain;
	int					unknown04;
	int					unknown08;
	int					unknown0c;
	XColor				color;
	string				unknown14;
	Point				position;
	bool				open;
	bool				blocked;
	bool				unknown3a;
	char				pad3b;
	int					caveinInstability;
	int					unknown40;
	HProp				prop;
	HEntity				entity;
	vector<HItem>		items;
	vector<CellEffect *>	effects;
	int					unknown6c;

	Cell(CellTerrainRecord *terrain_);
	Cell(istream &stream);
	void save(ostream &stream);			// NOTE: placeholder name

	CellEffect *getEffect(int type);
	bool isDoor();
	bool isMachinePart();
	bool unknown45db70();
	bool unknown45d1e0();
	bool unknown45d700();
	bool unknown45d4e0();
	bool isEdge();
	bool isShortcut();

	bool unknown66a630();				// NOTE: placeholder name
	void unknown66a050(int terrainID, int cause, int unknown);	// NOTE: placeholder name
	void removeProp(bool keepTerrain, int cause);	// NOTE: placeholder name (0x66c100)
	void addItem(HItem item, int cause);	// NOTE: placeholder name (0x66bcf0)
	void unknown66d470(int a, int amount, bool c, bool d);	// NOTE: placeholder name
	void unknown670b20();				// NOTE: placeholder name
	void unknown670b60(bool flag);		// NOTE: placeholder name
	void unknown6706d0(bool flag);		// NOTE: placeholder name
	bool unknown45dbb0();				// NOTE: placeholder name
	bool unknown45dbf0();				// NOTE: placeholder name
	void unknown45df90(CellEffect *effect);		// NOTE: placeholder name
	void unknown670dc0();
	void unknown670ed0();				// NOTE: placeholder name				// NOTE: placeholder name
	XColor getColor();					// NOTE: placeholder name (0x66a680)
	int getAscii();						// NOTE: placeholder name (0x66a830)
	int getAsciiAlt();					// NOTE: placeholder name (0x66a9b0)

	bool unknown66aed0();				// NOTE: placeholder name
	int unknown66afe0();				// NOTE: placeholder name
	void unknown66b070();				// NOTE: placeholder name
	bool unknown66b120();				// NOTE: placeholder name
	bool unknown66b1c0(int type, bool unpowered);	// NOTE: placeholder name
	bool unknown66b250();				// NOTE: placeholder name
	bool unknown66b360();				// NOTE: placeholder name
	bool unknown66b3d0(Entity *entity_);	// NOTE: placeholder name
	bool unknown66b460();				// NOTE: placeholder name
	bool unknown66b4b0();				// NOTE: placeholder name
	bool unknown66b510();				// NOTE: placeholder name
	bool unknown66b560();				// NOTE: placeholder name
	bool unknown66b5b0();				// NOTE: placeholder name
	void unknown66b780();				// NOTE: placeholder name (copies terrain effects)
	void setEntity(HEntity entity_);	// NOTE: placeholder name (0x66b8f0)
	void clearEntity();				// NOTE: placeholder name (0x66baf0)
	bool unknown45dc90(int size);
};

class OpS3_Console	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpS3_Console *opS3_console;	// NOTE: placeholder name (0xcec058)

class CLogMsgs
{
public:
	void scrollToEnd();
};
extern CLogMsgs *opS3_logMsgs;	// NOTE: placeholder name (0xcec0b4)

extern vector<Point> opS3_pointsD29774;	// NOTE: placeholder name (0xd29774)
extern vector<int> opS3_d2f0f8;			// NOTE: placeholder name (0xd2f0f8)
bool opS3_unknown5111e0(int id, const string *text, int a, int b, HEntity entity, HProp prop, const Point *at, int flag);	// NOTE: placeholder name
void opS3_unknown6c0f10(const Point &p, int type, int duration);	// NOTE: placeholder name

void Cell::unknown670b20()
{
	unknown04 = terrain->unknown3c;
	unknown08 = terrain->unknown40;
	unknown3a = true;
	open = true;
}

void Cell::unknown670b60(bool flag)
{
	if (unknown45dbb0())
		return;
	unknown670b20();
	world->addPoint6a8(position);
	soundMgr.unknown454500(position);
	if (world->unknown463e50() && isEdge() && world->isVisible(position) && !world->unknown463e90(position))
		world->unknown734d60(position);
	if (terrain->sound2 != NULL)
		opS3_pointsD29774.push_back(position);
	if (!flag)
	{
		Point p = position;
		p.x--;
		while (p.x >= 0 && cells(p)->unknown45dbf0())
		{
			cells(p)->unknown670b60(true);
			p.x--;
		}
		p = position;
		p.x++;
		while (p.x < cells.getWidth() && cells(p)->unknown45dbf0())
		{
			cells(p)->unknown670b60(true);
			p.x++;
		}
		p = position;
		p.y--;
		while (p.y >= 0 && cells(p)->unknown45dbf0())
		{
			cells(p)->unknown670b60(true);
			p.y--;
		}
		p = position;
		p.y++;
		while (p.y < cells.getHeight() && cells(p)->unknown45dbf0())
		{
			cells(p)->unknown670b60(true);
			p.y++;
		}
	}
}

void Cell::unknown670dc0()
{
	if (terrain->passable != 0 && terrain->passable <= 2 && getEffect(6) == NULL)
	{
		unknown45df90(reinterpret_cast<CellEffect *>(new Point(opS3_d2f0f8[6],1)));
		do
		{
			if (opS3_unknown5111e0((terrain->passable != 1) + 0x1b5,NULL,0,0,HEntity(),HProp(),&position,0))
				opS3_console->unknown8758d0(true);
			opS3_logMsgs->scrollToEnd();
		} while (0);
		unknown670b60(false);
		opS3_unknown6c0f10(position,terrain->ID,0);
	}
}

void Cell::unknown670ed0()
{
	if (terrain->passable != 0 && getEffect(7) == NULL)
	{
		unknown45df90(reinterpret_cast<CellEffect *>(new Point(opS3_d2f0f8[7],1)));
		unknown670b60(false);
	}
}
