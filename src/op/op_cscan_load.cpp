// op_cscan_load: CScan::load, builds the scan-window text for the cell under the cursor (COGMIND.exe Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;

	bool operator==(const Pos &pos) const;	// 0x409b90
	Pos &operator=(const Pos &pos);	// 0x46ca50
};

struct Point	// NOTE: the exe names this type Point
{
	int x;
	int y;

	int clamp_40c270(int value);	// 0x40c270
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();	// 0x411d40
	XColor(const XColor &color) throw();	// 0x411e30
	bool nonzero();	// 0x412180
	void setHSV(float h, float s, float v);	// 0x412500
};

class XConsole
{
public:
	virtual ~XConsole();

	void clearInterior();
	void removeSubconsole(XConsole *console);
	void setBack_417fc0(int x, int y, XColor color, int flag) throw();
	void putChar_418110(int x, int y, int ch, XColor fore_);

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	int unknown60;
	void *engine;
	void *title;
};

class CSLEntity;
class CSLItem;
class CSLProp;

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity() throw();	// 0x9b6590
	CSLEntity *operator->() const;	// 0x9b6570
	bool isValid() const throw();	// 0x9b7230
	void reset() throw();	// 0x9b7270
	bool operator==(HEntity other) const throw();	// 0x9b78e0
	bool operator!=(HEntity other) const;	// 0x9b6510
};

class HItem	// NOTE: placeholder layout
{
public:
	int ID;
	HItem() throw();	// 0x9b6590
	CSLItem *operator->() const;	// 0x9b65b0
	bool isValid() const throw();	// 0x9b7230
	bool operator!=(HItem other) const throw();	// 0x9b6510
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
	CSLProp *operator->() const;	// 0x9b64f0
	bool isValid() const throw();	// 0x9b7230
	bool isNull() const;	// 0x9b65d0
};

class CSLGroup	// NOTE: placeholder name (Group)
{
public:
	int getType();	// 0x9b4350
};

class CSLHGroup	// NOTE: placeholder name (group handle)
{
public:
	int ID;
	CSLGroup *operator->() const;	// 0x9b7250
};

class CSLAI	// NOTE: placeholder name (EntityAI)
{
public:
	bool unknown458fb0(HEntity e);	// NOTE: placeholder name
};

class CSLEntity	// NOTE: placeholder name (Entity)
{
public:
	int getField490840();	// NOTE: placeholder name
	XColor *unknown5ca2b0();	// NOTE: placeholder name
	string &getName416f40();	// NOTE: placeholder name (folded getter)
	CSLHGroup getGroup();	// 0x45a3f0
	int unknown5cad50();	// NOTE: placeholder name
	bool unknown45ade0();	// NOTE: placeholder name
	int unknown5c7fc0(HEntity other);	// NOTE: placeholder name
	CSLAI *unknown45b590();	// NOTE: placeholder name
	bool unknown5c8820(HEntity other);	// NOTE: placeholder name
	HItem unknown5d5d40();	// NOTE: placeholder name
	Pos &getPosition();	// 0x45a4a0
	Pos unknown5c80f0(const Pos &p);	// NOTE: placeholder name
};

struct CSLColorVec	// NOTE: placeholder layout (vector of description colors)
{
	int f0, f1, f2, f3;
	CSLColorVec();	// 0x9b8e80
	~CSLColorVec();	// 0x9b3da0
};

class CSLItem	// NOTE: placeholder name (Item)
{
public:
	int get9b6bf0();	// NOTE: placeholder name
	int get45cb30();	// NOTE: placeholder name
	XColor *unknown577260();	// NOTE: placeholder name
	string getName571db0(int a, int b);	// NOTE: placeholder name
	int getNestedField457880();	// NOTE: placeholder name
	int getNestedField457820();	// NOTE: placeholder name
	void describe5759b0(string &text, CSLColorVec &colors);	// NOTE: placeholder name
	int getEffectValue(int type);	// 0x457be0
};

struct CSLExplosion	// NOTE: placeholder layout
{
	char pad00[0x2c];
	int type;
	int damage;
	int spread;
	char pad38[0x3c - 0x38];
	int radius;
};

struct CSLPropData	// NOTE: placeholder layout
{
	char pad00[0x8c];
	CSLExplosion *explosion;
	char pad90[0xf8 - 0x90];
	int colorF8;
	char padFC[0x118 - 0xfc];
	int f118;
	char pad11C[0x120 - 0x11c];
	int f120;
	char pad124[0x164 - 0x124];
	int glyph;
};

class CSLPropRec	// NOTE: placeholder name
{
public:
	bool unknown65cf50(int groupType);	// NOTE: placeholder name
};

class CSLProp	// NOTE: placeholder name (Prop)
{
public:
	int getNestedField45c5d0();	// NOTE: placeholder name
	bool getField470b30();	// NOTE: placeholder name
	int getNestedField45c570();	// NOTE: placeholder name
	const string &getName();	// 0x45c5b0
	bool isTrap();	// 0x45cb70
	XColor unknown65dbb0();	// NOTE: placeholder name
	CSLPropData *getData();	// NOTE: placeholder name (0x9b8f00, folded getter)
	CSLPropRec *unknown44b020();	// NOTE: placeholder name
	int getNestedField45c630();	// NOTE: placeholder name
};

class CSLCell	// NOTE: placeholder name (Cell)
{
public:
	HEntity getEntity();	// 0x45d250
	HItem getItem();	// 0x45d8f0
	HProp getProp();	// 0x45d550
	int unknown45d1c0();	// NOTE: placeholder name
	string &unknown45d140();	// NOTE: placeholder name
	bool isEdge();	// 0x45dc30
	Pos &unknown45d1a0();	// NOTE: placeholder name (position)
	bool isShortcut();	// 0x45dc50
	void *getEffect(int type);	// 0x45d350
	bool unknown45db70();	// NOTE: placeholder name
	bool isMachinePart();	// 0x45dcd0
	int getArmor();
};

class CSLCells	// NOTE: placeholder name (0xcfd44c)
{
public:
	CSLCell **atPoint(const Pos &p);	// 0x9ced70
};
extern CSLCells csl_cells;	// NOTE: placeholder name

class CSLLocation	// NOTE: placeholder name
{
public:
	int pad00;
	int type;
	char pad08[0x25 - 0x08];
	bool known;
	bool inRange();	// 0x46ecb0
};

class CSLHLocation	// NOTE: placeholder name (location handle)
{
public:
	int ID;
	CSLLocation *operator->() const;	// 0x9b7910
};

struct CSLZone	// NOTE: placeholder layout
{
	char pad00[0x08];
	CSLHLocation location;
	char pad0C[0x1c - 0x0c];
	int state;
};

class CSLMap	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
	bool isVisible(const Pos &pos);	// 0x4631c0
	double unknown718430(HEntity entity, const Pos &pos, int a, int b);	// NOTE: placeholder name
	double unknown719a90(HEntity entity, const Pos &pos, int a, int b);	// NOTE: placeholder name
	int getEntityValue(HEntity e);	// 0x465660
	bool unknown463e90(const Pos &p);	// NOTE: placeholder name
	CSLZone *getZone(const Pos &p);	// 0x462e30
};
extern CSLMap *csl_map;	// NOTE: placeholder name (0xcefc4c)

struct CSLSquad	// NOTE: placeholder layout
{
	int leader;
};

class CSLOvermind	// NOTE: placeholder name (0xcf6428)
{
public:
	CSLSquad *unknown683310(HEntity e);	// NOTE: placeholder name
};
extern CSLOvermind csl_overmind;	// NOTE: placeholder name

class CSLGameData	// NOTE: placeholder name (0xd1e860)
{
public:
	bool unknown789580(HEntity e);	// NOTE: placeholder name
};
extern CSLGameData csl_gameData;	// NOTE: placeholder name

struct CSLTerrain	// NOTE: placeholder layout
{
	char pad00[0x68];
	int armor;
};
extern CSLTerrain *TERRAIN_CAVE_WALL;	// 0xcefba0

struct CSLHsv	// NOTE: placeholder layout
{
	float h;
	float s;
	float v;
};

struct MapRecord;

extern bool csl_d28d16;	// NOTE: placeholder name (option)
extern int csl_b96118[];	// NOTE: placeholder name
extern int csl_b96130[];	// NOTE: placeholder name
extern XColor csl_d2cf08[][10];	// NOTE: placeholder name
extern int csl_cefb38;	// NOTE: placeholder name
extern string csl_d35c40[];	// NOTE: placeholder name
extern int csl_cfb794;	// NOTE: placeholder name (scan window width)
extern XColor *csl_d22e44;	// NOTE: placeholder name
extern XColor *csl_d1d4d4;	// NOTE: placeholder name
extern XColor *csl_d2b4f4;	// NOTE: placeholder name
extern Point csl_d2c3f4;	// NOTE: placeholder name
extern Point csl_d1e01c;	// NOTE: placeholder name
extern vector<MapRecord*> csl_cf4830;	// NOTE: placeholder name
extern CSLHsv csl_b9e678[];	// NOTE: placeholder name (hue column)
extern CSLHsv csl_b9e67c[];	// NOTE: placeholder name (saturation column)
extern CSLHsv csl_b9e680[];	// NOTE: placeholder name (value column)
extern CSLHsv csl_b9e654[];	// NOTE: placeholder name (hue column)
extern CSLHsv csl_b9e658[];	// NOTE: placeholder name (saturation column)
extern CSLHsv csl_b9e65c[];	// NOTE: placeholder name (value column)
extern string csl_d323f8[];	// NOTE: placeholder name
extern string csl_cfaca0[];	// NOTE: placeholder name
extern bool csl_ba6650[][3];	// NOTE: placeholder name
extern int csl_cf4718;	// NOTE: placeholder name

string intToString(int value);
void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
string opq4a_splitLine(string &text, unsigned int maxWidth);	// NOTE: placeholder name (0x884e00)

class CScanText : public Console
{
public:
	CScanText(XConsole *parent, int x, int y, int width, string text, HItem item_, HEntity entity_);	// 0x4a27c0
	void setStyle(bool dark, bool silent, bool cell);	// NOTE: placeholder name (0x4a28d0)

	HItem item;	// NOTE: placeholder name
	HEntity entity;	// NOTE: placeholder name
};

class CScan : public Console
{
public:
	void load(const Pos &pos, bool force);	// 0x884f60
	bool unknown884d00();	// NOTE: placeholder name
	void unknown887540();	// NOTE: placeholder name
	int unknown884da0(HEntity entity);	// NOTE: placeholder name

	bool unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	CScanText *unknown74;	// NOTE: placeholder name
	CScanText *unknown78;	// NOTE: placeholder name
	void *buttons;	// NOTE: placeholder name
	Pos unknown80;	// NOTE: placeholder name
	HProp unknown88;	// NOTE: placeholder name
	HEntity unknown8c;	// NOTE: placeholder name
	int unknown90;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
	int unknown9c;	// NOTE: placeholder name
	HItem unknownA0;	// NOTE: placeholder name
	int unknownA4;	// NOTE: placeholder name
	Pos unknownA8;	// NOTE: placeholder name
	int unknownB0;	// NOTE: placeholder name
	bool unknownB4;	// NOTE: placeholder name
};

void CScan::load(const Pos &pos, bool force)
{
	HEntity entity = (*csl_cells.atPoint(pos))->getEntity();
	if (entity == csl_map->getPlayer())
		entity.reset();
	HItem item = (*csl_cells.atPoint(pos))->getItem();
	if (!force && unknown80 == pos)
	{
		if (entity != unknown8c)
			goto reload;
		else if (entity.isValid() && entity == unknown8c)
		{
			if (entity->getField490840() != unknown90 || unknown884da0(entity) != unknown94 || csl_d2c3f4.clamp_40c270((int)(csl_map->unknown718430(csl_map->getPlayer(),pos,0,0) * 100.0)) != unknown98)
				goto reload;
		}
		else if (item != unknownA0)
			goto reload;
		else if (item.isValid())
		{
			if (item->get9b6bf0() != unknown90 || item->get45cb30() != unknownA4)
				goto reload;
		}
		return;
	}
reload:
	if (!csl_map->isVisible(pos))
	{
		if (!unknownB4)
		{
			unknown887540();
			unknownB4 = true;
		}
		return;
	}
	unknownB4 = false;
	HProp prop = (*csl_cells.atPoint(pos))->getProp().isValid() && (*csl_cells.atPoint(pos))->getProp()->getNestedField45c5d0() && !(*csl_cells.atPoint(pos))->getProp()->getField470b30() ? (*csl_cells.atPoint(pos))->getProp() : HProp();
	if (prop.isValid() && unknown88.operator->() && prop->getNestedField45c570() == unknown88->getNestedField45c570())
		return;
	else if (entity.isValid() && unknown8c.operator->() && entity == unknown8c && entity->getField490840() == unknown90 && unknown884da0(entity) == unknown94 && csl_d2c3f4.clamp_40c270((int)(csl_map->unknown718430(csl_map->getPlayer(),pos,0,0) * 100.0)) == unknown98)
		return;
	unknown90 = -1;
	unknown94 = 6;
	unknownA4 = -1;
	CSLCell *cell = (*csl_cells.atPoint(pos))->unknown45d1c0() ? *csl_cells.atPoint(pos) : NULL;
	if (entity.isValid() || item.isValid() || prop.isValid() || cell || unknown884d00())
	{
		if (unknown74)
		{
			removeSubconsole(unknown74);
			unknown74 = NULL;
		}
		if (unknown78)
		{
			removeSubconsole(unknown78);
			unknown78 = NULL;
		}
		clearInterior();
		unknown80 = pos;
		unknown88 = prop;
		unknown8c = entity;
		unknownA0 = item;
		if (entity.isValid())
		{
			unknown90 = entity->getField490840();
			unknown94 = unknown884da0(entity);
			if (csl_d28d16)
			{
				putChar_418110(1,1,0xae,*entity->unknown5ca2b0());
				if (unknown94 != 6)
					setBack_417fc0(1,1,csl_d2cf08[csl_b96118[unknown94]][csl_b96130[unknown94]],1);
			}
			else
				putChar_418110(1,1,0xb3,*entity->unknown5ca2b0());
			string name = entity->getName416f40();
			if (entity->getGroup()->getType() == 3 && csl_gameData.unknown789580(entity))
			{
				CSLSquad *squad = csl_overmind.unknown683310(entity);
				if (squad && squad->leader)
					name += " (L)";
			}
			if (entity->unknown5cad50() == 2)
				name += " " + csl_d35c40[csl_cefb38];
			unknown74 = new CScanText(this,3,1,csl_cfb794 - 4,name,HItem(),entity);
			unknown74->setStyle(false,false,false);
			int value = csl_map->getEntityValue(entity);
			if (value && !entity->unknown45ade0())
				value = 0;
			if (value)
				putChar_418110(1,2,'?',value == 1 ? *csl_d22e44 : *csl_d1d4d4);
			else if (!entity->unknown5c7fc0(csl_map->getPlayer()) && entity->unknown45b590() && entity->unknown45b590()->unknown458fb0(csl_map->getPlayer()))
				putChar_418110(1,2,'!',*csl_d2b4f4);
			unknown98 = csl_d2c3f4.clamp_40c270((int)(csl_map->unknown718430(csl_map->getPlayer(),pos,0,0) * 100.0));
			unknown9c = csl_map->getPlayer()->unknown5c8820(entity) && csl_map->getPlayer()->unknown5d5d40().isValid() ? csl_d1e01c.clamp_40c270((int)(csl_map->unknown719a90(csl_map->getPlayer(),entity->unknown5c80f0(csl_map->getPlayer()->getPosition()),0,0) * 100.0)) : -1;
			unknown78 = new CScanText(this,3,2,csl_cfb794 - 4,"Base Hit " + intToString(unknown98) + (unknown9c == -1 ? string("%") : "% (melee " + intToString(unknown9c) + "%)"),HItem(),HEntity());
			unknown78->setStyle(true,false,false);
		}
		else if (item.isValid())
		{
			unknown90 = item->get9b6bf0();
			unknownA4 = item->get45cb30();
			putChar_418110(1,1,0xb3,*item->unknown577260());
			unknown74 = new CScanText(this,3,1,csl_cfb794 - 4,item->getName571db0(1,0),item,HEntity());
			unknown74->setStyle(false,false,false);
			if (item->getNestedField457880() >= 6 && csl_cf4830[item->getNestedField457820()])
			{
				string desc;
				CSLColorVec cols;
				item->describe5759b0(desc,cols);
				unknown78 = new CScanText(this,3,2,csl_cfb794 - 4,desc,HItem(),HEntity());
				unknown78->setStyle(true,false,false);
			}
			else if (item->getEffectValue(0x4a))
			{
				string text = intToString(item->getEffectValue(0x49)) + "/" + intToString(item->getEffectValue(0x4a));
				unknown78 = new CScanText(this,3,2,csl_cfb794 - 4,text,HItem(),HEntity());
				unknown78->setStyle(true,false,false);
			}
			else if (item->getEffectValue(0x4b))
			{
				string text = intToString(item->getEffectValue(0x4b)) + "%";
				unknown78 = new CScanText(this,3,2,csl_cfb794 - 4,text,HItem(),HEntity());
				unknown78->setStyle(true,false,false);
			}
		}
		else
		{
			string name;
			if (prop.isValid())
				name = prop->getName();
			else
			{
				CSLCell *c = cell ? cell : *csl_cells.atPoint(unknownA8);
				string cellName = c->unknown45d140();
				if (c->isEdge())
				{
					if (csl_map->unknown463e90(c->unknown45d1a0()))
					{
						if (c->isShortcut())
							cellName = "Emergency Access";
						else
							cellName = "Phase Wall";
						if (c->getEffect(6))
							cellName.insert(0,"Broken ");
					}
				}
				else if (c->unknown45db70() && c->getEffect(6))
					cellName.insert(0,"Broken ");
				name = cellName;
			}
			string msg = opq4a_splitLine(name,csl_cfb794 - 4);
			bool disabled = prop.isValid() ? prop->getNestedField45c5d0() == 2 : (cell ? cell->unknown45d1c0() == 2 : true);
			bool dest = false;
			bool valid = false;
			if (prop.isValid())
			{
				if (prop->isTrap())
				{
					putChar_418110(1,1,prop->getData()->glyph,prop->unknown65dbb0());
					msg = prop->unknown44b020()->unknown65cf50(csl_map->getPlayer()->getGroup()->getType()) ? "(HOSTILE)" : "(FRIENDLY)";
					valid = true;
				}
				else
				{
					XColor color;
					if (prop->getData()->colorF8 != 9)
						color.setHSV(csl_b9e678[prop->getData()->colorF8].h,csl_b9e67c[prop->getData()->colorF8].h,csl_b9e680[prop->getData()->colorF8].h);
					else if (prop->getData()->f118 || prop->getData()->f120)
						color.setHSV(csl_b9e654[prop->getData()->f120].h,csl_b9e658[prop->getData()->f120].h,csl_b9e65c[prop->getData()->f120].h);
					if (color.nonzero())
						putChar_418110(1,1,0xb3,color);
					if (!prop->getField470b30() && msg.empty())
					{
						msg = prop->getNestedField45c630() == -1 ? string("**") : intToString(prop->getNestedField45c630());
						if (prop->getData()->explosion)
						{
							CSLExplosion *expl = prop->getData()->explosion;
							msg += " Expl/" + csl_d323f8[expl->type] + " " + intToString(expl->damage - expl->spread) + "-" + intToString(expl->damage + expl->spread) + " (R=" + intToString(expl->radius) + ")";
						}
						valid = true;
					}
				}
			}
			else if (cell && cell->isMachinePart())
			{
				if (!msg.empty())
					logError("CScan::load()","Multi-line level access cell name, unable to fit destination text");
				else
				{
					CSLZone *zone = csl_map->getZone(cell->unknown45d1a0());
					CSLHLocation location = zone->location;
					if (location->known && !location->inRange())
					{
						switch (location->type)
						{
						case 0xd:
							name = "Garrison Access";
							break;
						case 0xe:
							name = "DSF Access";
							break;
						default:
							name = "Branch Access";
							break;
						}
						dest = true;
					}
					msg = location->known ? csl_cfaca0[location->type] : string("???");
					if (csl_ba6650[location->type][csl_cf4718])
						msg += " (LOCKED)";
					else if (zone->state == 2)
						msg += " (SEALED)";
					else if (zone->state == 3)
						msg += " (LOCKDOWN)";
					else if (zone->state == 4)
						msg += " (BLOCKED)";
				}
			}
			bool terrain = prop.isNull() && !cell;
			unknown74 = new CScanText(this,3,1,csl_cfb794 - 4,name,HItem(),HEntity());
			unknown74->setStyle(false,disabled,terrain);
			if (terrain)
			{
				int armor = (*csl_cells.atPoint(unknownA8))->getArmor();
				if ((*csl_cells.atPoint(unknownA8))->isEdge() && !csl_map->unknown463e90(unknownA8))
					armor = TERRAIN_CAVE_WALL->armor;
				msg = armor == -1 ? string("**") : intToString(armor);
				valid = true;
			}
			if (!msg.empty())
			{
				if (!valid && msg.size() + 2 < csl_cfb794 - 4)
				{
					msg.insert(0,2,' ');
					if (prop.isNull() && cell)
						msg[0] = dest ? '>' : '<';
				}
				unknown78 = new CScanText(this,3,2,csl_cfb794 - 4,msg,HItem(),HEntity());
				unknown78->setStyle(valid,disabled,terrain);
			}
		}
	}
	else
		unknown887540();
}
