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
	bool operator==(const Point &p) const;	// 0x409b90
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
	XColor &operator=(XColor c);
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
	bool unknown45ca30();					// NOTE: placeholder name
	bool unknown470b30();					// NOTE: placeholder name
	void unknown665d10(int *range, float factor);	// NOTE: placeholder name
	void unknown665d40(int *range, float factor);	// NOTE: placeholder name
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
	void unknown74b060(const Point &p, int type, int percent);	// NOTE: placeholder name
	HEntity unknown6c5dc0(const string &name, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name
	bool unknown6c65a0(HEntity e, const string &name, bool flag);	// NOTE: placeholder name
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	void unknown729350(Point p);	// NOTE: placeholder name
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
	void unknown45df90(Point *p);		// NOTE: placeholder name
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
	int unknown45d430();				// NOTE: placeholder name
	CellTerrainRecord *terrain9fcd80();	// 0x9fcd80 (folded [ecx] getter; Cell::getTerrain is the int-returning csv name)
	bool unknown45de40();				// NOTE: placeholder name

	bool unknown66ad90(int size);		// NOTE: placeholder name
	bool unknown66b170();				// NOTE: placeholder name
	void unknown66b660();				// NOTE: placeholder name
	void unknown66b690(int a, const XColor &c);	// NOTE: placeholder name
	void unknown66b700(int a, const XColor &c);	// NOTE: placeholder name
	void unknown66b740(Cell *other);	// NOTE: placeholder name
	void unknown670f50(int *range, float factor);	// NOTE: placeholder name
	void unknown670f90(int *range, float factor);	// NOTE: placeholder name
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

struct OpQ5_T9e2c40;	// NOTE: placeholder name
template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name (0x9e2c40)
void sweepGetSurroundingCells(const Point &point, vector<Point> &adjacent);	// 0x4faaf0
void opS3d_unknown5141b0(int id, int a, int b, int c, HProp prop, const Point *at);	// NOTE: placeholder name
void opS3d_unknown6c1080(const Point &p);	// NOTE: placeholder name
extern Array2D<int> originalTerrain;
extern Point opS3d_pointCf69c4;	// NOTE: placeholder name (0xcf69c4)

class OpS3d_Overmind	// NOTE: placeholder name (object at 0xcf6428)
{
public:
	void unknown68d920(int a);	// NOTE: placeholder name
	void unknown6823f0(int a);	// NOTE: placeholder name
};
extern OpS3d_Overmind opS3d_overmind;	// NOTE: placeholder name (0xcf6428)

class OpS3d_Unk6888	// NOTE: placeholder name (object at 0xcf6888)
{
public:
	void unknown69a9d0();	// NOTE: placeholder name
};
extern OpS3d_Unk6888 opS3d_cf6888;	// NOTE: placeholder name (0xcf6888)

class OpS3d_PlayerData	// NOTE: placeholder name (object at 0xcf45d8)
{
public:
	void unknown77fbc0(int a);	// NOTE: placeholder name
};
extern OpS3d_PlayerData opS3d_playerData;	// NOTE: placeholder name (0xcf45d8)

class OpS3d_MapView	// NOTE: placeholder name (object at 0xcec054)
{
public:
	void unknown49adc0(int time);	// NOTE: placeholder name
};
extern OpS3d_MapView *opS3d_mapView;	// NOTE: placeholder name (0xcec054)

struct MapRecord;
extern vector<MapRecord *> opS3d_mapRecordsCf4a04;	// NOTE: placeholder name (0xcf4a04)
extern bool opS3d_flagCefc9d;							// NOTE: placeholder name (0xcefc9d)
bool isFootprintOpen(const Point &position, int size);	// NOTE: placeholder name (0x4fad50)
bool footprintHasImpassableTile(const Point &position, int size);	// NOTE: placeholder name (0x4fae80)
int opS3d_findIndex(const int *table, unsigned int count, int value);	// NOTE: placeholder name (0x9cf560)

bool Cell::unknown66ad90(int size)
{
	if (!isFootprintOpen(position,size))
		return false;
	if (footprintHasImpassableTile(position,size))
		return false;
	if (!opS3d_flagCefc9d)
		return true;
	if (!isEdge())
		return true;
	if (isShortcut())
		return world->unknown463e90(position);
	return opS3d_mapRecordsCf4a04[14] != NULL && world->unknown463e90(position);
}

bool Cell::unknown66b170()
{
	return prop.isValid() && prop->unknown45ca30();
}

void Cell::unknown66b660()
{
	unknown04 = terrain->unknownD4;
	unknown08 = terrain->unknownD8;
}

void Cell::unknown66b690(int a, const XColor &c)
{
	if (open)
	{
		unknown0c = opS3d_findIndex(asciiEnabled ? opd_asciiTableA : opd_asciiTableB,18,a);
		color = c;
	}
}

void Cell::unknown66b700(int a, const XColor &c)
{
	if (open)
	{
		unknown0c = a;
		color = c;
	}
}

void Cell::unknown66b740(Cell *other)
{
	other->unknown0c = unknown0c;
	other->color = color;
	unknown45de40();
}

void Cell::unknown670f50(int *range, float factor)
{
	if (prop.isValid())
		prop->unknown665d10(range,factor);
}

void Cell::unknown670f90(int *range, float factor)
{
	*range -= terrain->unknown78 * factor;
	if (prop.isValid())
		prop->unknown665d40(range,factor);
}

class OpS3d_Unk670ff0	// NOTE: placeholder name
{
public:
	HProp			prop;
	int				unknown04;
	int				unknown08;
	vector<unsigned int>	unknown0c;
	bool			unknown1c;
	int				unknown20;
	int				unknown24;
	bool			unknown28;
	vector<unsigned int>	unknown2c;

	OpS3d_Unk670ff0(int a);
	void unknown45e4c0();	// NOTE: placeholder name
};

OpS3d_Unk670ff0::OpS3d_Unk670ff0(int a)
{
	prop.unknown9b7270();
	unknown04 = a;
	unknown08 = a;
	unknown1c = unknown08 <= 2;
	unknown20 = 0;
	unknown24 = 0;
	unknown28 = false;
	unknown45e4c0();
}

void Cell::unknown66a050(int terrainID, int cause, int unknown)
{
	switch (cause)
	{
	case 0:
		if (terrainID != originalTerrain(position) && originalTerrain(position) != TERRAIN_EARTH->ID)
			opS3_unknown6c0f10(position,originalTerrain(position),0);
		opS3d_overmind.unknown68d920(3);
		world->unknown74b060(position,terrain->unknown74,100);
		if (opd_gameState->mapType == 15 && terrain == TERRAIN_EARTH && terrainID == opd_terrainCefb88->ID && rng.chance(4) &&
			originalTerrain(position) == TERRAIN_EARTH->ID)
		{
			HEntity item = world->unknown6c5dc0("Subdweller",position,6,false,34,14,false);
			if (item.isValid())
			{
				world->unknown6c65a0(item,"SUB_Released_From_Earth",false);
				if (world->unknown4631f0(item))
				{
					do
					{
						opS3d_unknown5141b0(286,0,0,0,HProp(),&position);
					} while (0);
					opS3d_playerData.unknown77fbc0(27);
					opS3d_mapView->unknown49adc0(1000);
				}
			}
		}
		if (position == opS3d_pointCf69c4)
			opS3d_cf6888.unknown69a9d0();
		break;
	case 1:
		opS3d_unknown6c1080(position);
		break;
	case 2:
		originalTerrain(position) = terrainID;
		opS3d_unknown6c1080(position);
		break;
	case 3:
		opS3_unknown6c0f10(position,opd_terrainCefb9c->ID,0);
		break;
	case 4:
		originalTerrain(position) = opd_terrainCefb9c->ID;
		opS3d_unknown6c1080(position);
		break;
	case 5:
		{
			opS3_unknown6c0f10(position,opd_terrainCefb9c->ID,0);
			vector<Point> surrounding;
			sweepGetSurroundingCells(position,surrounding);
			for (unsigned int i = 0; i < surrounding.size(); i++)
			{
				if (cells(surrounding[i])->terrain9fcd80() == TERRAIN_EARTH)
					opS3_unknown6c0f10(surrounding[i],TERRAIN_CAVE_WALL->ID,0);
			}
			world->unknown74b060(position,terrain->unknown74,100);
		}
		break;
	case 6:
		world->unknown74b060(position,5,100);
		break;
	case 7:
		opS3d_overmind.unknown6823f0(22);
		opS3_unknown6c0f10(position,originalTerrain(position),0);
		break;
	case 8:
		opS3d_overmind.unknown6823f0(21);
		opS3_unknown6c0f10(position,originalTerrain(position),0);
		break;
	}
	if (unknown3a != opd_terrainRecords[terrainID]->unknownDC)
		world->addPoint6a8(position);
	if (unknown45d430() != opd_terrainRecords[terrainID]->unknown54)
		soundMgr.unknown454500(position);
	terrain = opd_terrainRecords[terrainID];
	unknown04 = terrain->unknownD4;
	unknown08 = terrain->unknownD8;
	unknown0c = -1;
	unknown14.clear();
	bool wasOpen = open;
	open = terrain->unknown58;
	unknown3a = terrain->unknownDC;
	caveinInstability = 0;
	if (prop.isValid() && (!prop->unknown470b30() || prop->isTrap()))
		removeProp(true,3);
	OpQ5_clearObjects((vector<OpQ5_T9e2c40*>&)effects);
	unknown66b780();
	if (!open && wasOpen)
		world->unknown729350(position);
}
