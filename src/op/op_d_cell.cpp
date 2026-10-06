// op_d: Cell methods (0x66aed0-0x66b8f0) matched against COGMIND.exe (Beta 17.1).
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
};

class SoundMgr
{
public:
	void updatePropMute(HProp prop);	// 0x454520
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
	void unknown670dc0();				// NOTE: placeholder name
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
	void unknown670b60(bool flag);		// NOTE: placeholder name
	void unknown6706d0(bool flag);		// NOTE: placeholder name
};

bool Cell::unknown66aed0()
{
	return prop.isValid() && !prop->isPassableFor(HEntity()) && prop->isPassableFor(entity);
}

int Cell::unknown66afe0()
{
	return (unknown45db70() && getEffect(6) == NULL) ? 1 :
		((prop.isValid() && prop->unknown44ab40() != -1 && prop->unknown457b10() != 1) ? 2 : 0);
}

void Cell::unknown66b070()
{
	int index = unknown66afe0();
	OpD_CellRange *range = &opd_cellRanges[index];
	if (unknown40 < range->low)
		unknown40++;
	else if (unknown40 > range->high)
		unknown40--;
	else
	{
		unknown40 += rng.rangeInt(-1,1);
		opd_clamp(range->low,unknown40,range->high);
	}
}

bool Cell::unknown66b120()
{
	return prop.isValid() && prop->unknown45cb30() != NULL;
}

bool Cell::unknown66b1c0(int type, bool unpowered)
{
	return prop.isValid() && prop->unknown45cb30() != NULL && (!unpowered || prop->unknown457b10() == 0) && prop->unknown9b8f00()->unknownF8 == type;
}

bool Cell::unknown66b250()
{
	return prop.isValid() && prop->unknown45cb30() != NULL && prop->unknown9b8f00()->unknownF8 == 0 && prop->unknown457b10() == 0 &&
		prop->unknown45cb30()->unknown28 >= 0 && !prop->unknown45cb30()->unknown11 && prop->unknown45cb30()->unknown34 <= 15 &&
		(prop->unknown45cb30()->unknown78 == NULL || prop->unknown45cb30()->unknown78[0] == 0);
}

bool Cell::unknown66b360()
{
	return prop.isValid() && prop->unknown45cb30() != NULL && prop->unknown45cb30()->unknown10;
}

bool Cell::unknown66b3d0(Entity *entity_)
{
	return isDoor() && entity_->getGroup()->unknown9b4350() <= 2 && prop->unknown44b020()->unknown65cf50(entity_->getGroup()->unknown9b4350());
}

bool Cell::unknown66b460()
{
	return world->isVisible(position) && !unknown3a;
}

bool Cell::unknown66b4b0()
{
	return world->isVisible(position) && (unknown45d1e0() || isMachinePart());
}

bool Cell::unknown66b510()
{
	return world->isVisible(position) && entity.isValid();
}

bool Cell::unknown66b560()
{
	return world->isVisible(position) && unknown45d700();
}

bool Cell::unknown66b5b0()
{
	return world->isVisible(position) && unknown3a && !unknown45d1e0() && !isMachinePart() && entity.isNull() && !unknown45d700();
}

void Cell::unknown66b780()
{
	CellEffect *effect;
	for (unsigned int i = 0; i < terrain->base->effects.size(); i++)
		effects.push_back(new CellEffect(*terrain->base->effects[i]));
	for (unsigned int j = 0; j < terrain->effects.size(); j++)
	{
		effect = getEffect(terrain->effects[j]->record->type);
		if (effect != NULL)
			effect->value += terrain->effects[j]->value;
		else
			effects.push_back(new CellEffect(*terrain->effects[j]));
	}
}

void Cell::setEntity(HEntity entity_)
{
	int size = (entity_.isValid() && entity_->getGroup().isValid()) ? entity_->getGroup()->unknown9b4350() : 3;
	entity = entity_;
	if (unknown45db70())
		unknown670b60(false);
	else
	{
		Point p = position;
		if (--p.x >= 0 && cells(p)->unknown45dc90(size))
			cells(p)->unknown670b60(false);
		p = position;
		if (++p.x < cells.getWidth() && cells(p)->unknown45dc90(size))
			cells(p)->unknown670b60(false);
		p = position;
		if (--p.y >= 0 && cells(p)->unknown45dc90(size))
			cells(p)->unknown670b60(false);
		p = position;
		if (++p.y < cells.getHeight() && cells(p)->unknown45dc90(size))
			cells(p)->unknown670b60(false);
	}
}

void Cell::clearEntity()
{
	int size = (entity.isValid() && entity->getGroup().isValid()) ? entity->getGroup()->unknown9b4350() : 3;
	entity.unknown9b7270();
	if (unknown45db70())
		unknown6706d0(false);
	else
	{
		Point p = position;
		if (--p.x >= 0 && cells(p)->unknown45dc90(size))
			cells(p)->unknown6706d0(false);
		p = position;
		if (++p.x < cells.getWidth() && cells(p)->unknown45dc90(size))
			cells(p)->unknown6706d0(false);
		p = position;
		if (--p.y >= 0 && cells(p)->unknown45dc90(size))
			cells(p)->unknown6706d0(false);
		p = position;
		if (++p.y < cells.getHeight() && cells(p)->unknown45dc90(size))
			cells(p)->unknown6706d0(false);
	}
}

Cell::Cell(CellTerrainRecord *terrain_)
{
	terrain = terrain_;
	unknown04 = terrain->unknownD4;
	unknown08 = terrain->unknownD8;
	unknown0c = -1;
	position.set(-1,-1);
	open = terrain->unknown58;
	blocked = false;
	unknown3a = terrain->unknownDC;
	caveinInstability = 0;
	unknown40 = -9999;
	prop.unknown9b7270();
	entity.unknown9b7270();
	unknown66b780();
	unknown6c = 0;
}

void Cell::save(ostream &stream)
{
	opd_writeTerrain(stream,terrain);
	opd_writeInt(stream,&unknown04);
	opd_writeInt(stream,&unknown08);
	opd_writeInt(stream,&unknown0c);
	color.write(stream);
	opd_writeString(stream,unknown14);
	position.write(stream);
	opd_writeBool(stream,&open);
	opd_writeBool(stream,&unknown3a);
	opd_writeInt(stream,&caveinInstability);
	opd_writeInt(stream,&unknown40);
	prop.write(stream);
	entity.write(stream);
	opd_writeItems(stream,&items);
	opd_writeEffects(stream,&effects);
	opd_writeInt(stream,&unknown6c);
}

Cell::Cell(istream &stream)
{
	opd_readTerrain(stream,&terrain,opd_terrainRecords);
	readBinary(stream,&unknown04);
	readBinary(stream,&unknown08);
	readBinary(stream,&unknown0c);
	color.read(stream);
	opd_readString(stream,&unknown14);
	position.read(stream);
	opd_readBool(stream,&open);
	blocked = false;
	opd_readBool(stream,&unknown3a);
	readBinary(stream,&caveinInstability);
	readBinary(stream,&unknown40);
	prop.read(stream);
	entity.read(stream);
	opd_readItems(stream,&items);
	opd_readEffects(stream,&effects,0);
	readBinary(stream,&unknown6c);
}

CellTerrainRecord::CellTerrainRecord(istream &stream)
{
	readBinary(stream,&ID);
	opd_readString(stream,&name);
	opd_readString(stream,&tag);
	readBinary(stream,&unknown3c);
	readBinary(stream,&unknown40);
	foreColor.read(stream);
	backColor.read(stream);
	readBinary(stream,&unknown4c);
	opd_readTerrainBase(stream,&base,opd_terrainBases);
	readBinary(stream,&unknown54);
	opd_readBool(stream,&unknown58);
	readBinary(stream,&passable);
	opd_readBool(stream,&unknown60);
	readBinary(stream,&unknown64);
	opd_readUnk465ea0(stream,&armor);
	readBinary(stream,&unknown6c);
	readBinary(stream,&unknown70);
	readBinary(stream,&unknown74);
	readBinary(stream,&unknown78);
	opd_readBool(stream,&unknown7c);
	opd_readBool(stream,&unknown7d);
	opd_readEffects(stream,&effects,0);
	opd_readString(stream,&description);
	opd_readTerrainSound(stream,&sound1,opd_terrainSounds);
	opd_readTerrainSound(stream,&sound2,opd_terrainSounds);
	opd_readTerrainSound(stream,&sound3,opd_terrainSounds);
	opd_readString(stream,&unknownB8);
	readBinary(stream,&unknownD4);
	readBinary(stream,&unknownD8);
	opd_readBool(stream,&unknownDC);
}

bool Cell::unknown66a630()
{
	return terrain == TERRAIN_EARTH || terrain == TERRAIN_CAVE_WALL || terrain == caveinThirdTerrain;
}

XColor Cell::getColor()
{
	if (unknown45d1e0())
		return prop->unknown65dbb0();
	if (unknown0c != -1 && open && !unknown45db70() && !isMachinePart())
		return opd_colorMode ? opd_modeColors[opd_colorMode] : color;
	if (isEdge() && unknown45d4e0() && world->unknown463e90(position))
		return isShortcut() ? opd_terrainCefb94->foreColor : opd_terrainCefb98->foreColor;
	if (unknown45db70() && (getEffect(6) != NULL || getEffect(7) != NULL))
		return opd_colorD323c4;
	return (opd_colorMode && terrain == opd_terrainCefb9c) ? opd_modeColors[opd_colorMode] : terrain->foreColor;
}

int Cell::getAscii()
{
	if (unknown45d1e0())
		return prop->unknown45c650();
	if (unknown0c != -1 && open && !unknown45db70() && !isMachinePart())
		return asciiEnabled ? opd_asciiTableA[unknown0c] : opd_asciiTableB[unknown0c];
	if (isEdge() && unknown45d4e0() && world->unknown463e90(position))
		return isShortcut() ? (asciiEnabled ? opd_terrainCefb94->unknownD8 : opd_terrainCefb94->unknownD4) : (asciiEnabled ? opd_terrainCefb98->unknownD8 : opd_terrainCefb98->unknownD4);
	return asciiEnabled ? unknown08 : unknown04;
}

int Cell::getAsciiAlt()
{
	if (unknown45d1e0())
		return prop->unknown45c650();
	if (unknown0c != -1 && open && !unknown45db70() && !isMachinePart())
		return !asciiEnabled ? opd_asciiTableA[unknown0c] : opd_asciiTableB[unknown0c];
	if (isEdge() && unknown45d4e0() && world->unknown463e90(position))
		return isShortcut() ? (!asciiEnabled ? opd_terrainCefb94->unknownD8 : opd_terrainCefb94->unknownD4) : (!asciiEnabled ? opd_terrainCefb98->unknownD8 : opd_terrainCefb98->unknownD4);
	return !asciiEnabled ? unknown08 : unknown04;
}

void Cell::removeProp(bool keepTerrain, int cause)
{
	if (prop.isNull())
		return;

	bool replaceTerrain = prop->isTrap() && !keepTerrain;
	soundMgr.updatePropMute(prop);
	world->unknown464ed0(prop);
	if (prop->unknown44ab40() != -1)
	{
		opd_eraseProp(opd_propsByD31640[prop->unknown44ab40()],prop);
		opd_pointsByD2f32c[prop->unknown44ab40()].push_back(position);
	}
	if (prop->isTrap())
		opd_eraseProp(opd_trapsByD20248[prop->unknown44b020()->unknown04],prop);
	opd_propRegistry.unknown9d0fc0(prop,true);
	prop.unknown9b7270();
	if (replaceTerrain)
		unknown66a050(cause == 3 ? opd_terrainCefb88->ID : opd_terrainCefb9c->ID,cause,0);
}

void Cell::unknown66d470(int a, int amount, bool c, bool d)
{
	unknown9d0690(&unknown40,amount,0);
	unknown670dc0();
	if (prop.isValid() && c)
		prop->unknown6646f0(a,3,true,d);
}

void Cell::addItem(HItem item, int cause)
{
	if (items.empty() || !item->unknown575850(items.back()))
		items.push_back(item);
	else
	{
		for (unsigned int i = 0; i < items.size(); i++)
		{
			if (item->unknown575850(items[i]))
			{
				opd_insertItem(&items,i,item);
				return;
			}
		}
	}

	if (cause == 1 && item->unknown457880() >= 6)
		opd_mapItems.push_back(item);
	if (item->unknown457880() == 3)
		world->unknown727ea0(item);
	if (item->getEffect(0x56) != NULL)
		world->unknown7289f0(item,item->getEffect(0x57) != NULL ? 9 : 0);
	if (opd_gameState->mapType == 15)
		world->unknown728f30(item);
	if (opd_gameModeCf462c == 4 && item->unknown4578a0() == 0 && item->unknown457d70())
	{
		if (opd_gameState->mapType != 0x24 || world->unknown4642d0() != 0)
		{
			int odds = (int)(world->unknown464000() <= world->unknown717d60() / 2 ? 80.0 : (double)(world->unknown464000() - world->unknown717d60() / 2) / (world->unknown717d60() / 2) * 40.0 + 40.0);
			vector<Point *> *points = world->unknown462e10();
			for (unsigned int i = 0; i < points->size(); i++)
			{
				if (opd_itemDistanceLimit >= ::distance(*(*points)[i],position))
				{
					odds *= 0.66f;
					break;
				}
			}
			if (rng.chance(odds))
				world->addListB24(item);
		}
	}
	if (world->unknown463e50() != 0 && world->isVisible(position))
		world->unknown4647a0(position,false);
}
