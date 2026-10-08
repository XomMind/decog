// CScan::load (0x884f60): fills the scan window for the map position under the cursor (entity, item, prop,
// machine or terrain), skipping the rebuild when nothing changed since the last call.
// NOTE: placeholder names and layouts throughout (C2Y*, c2y_<address>).
#include <string>
using namespace std;

extern int TERRAIN_CAVE_WALL;
string intToString(int v);
void logError(string location, string message);

struct C2YPoint { int x, y; C2YPoint(const C2YPoint &o); C2YPoint &operator=(const C2YPoint &o); bool test409b90(const C2YPoint &o); };
struct C2YColor { unsigned char r, g, b; C2YColor(); C2YColor(const C2YColor &o); void setHSV(float h, float s, float v); bool nonzero(); };
struct C2YHSV { float h, s, v; };
struct C2YH { int id; C2YH(); };
struct C2YPos8 { int x, y; C2YPos8(); };	// NOTE: placeholder (generic handle passed by value)
struct C2YGroup { int type(); };
struct C2YGroupH { int id; C2YGroupH(); C2YGroup *operator->(); };
struct C2YAI { bool f458fb0(struct C2YEntityH other); };
struct C2YString { int f; };
struct C2YEntity
{
	int f490840();
	C2YColor *f5ca2b0();
	const string &name();
	C2YGroupH getGroup();
	int f5cad50();
	bool f45ade0();
	int f5c7fc0(struct C2YEntityH other);
	C2YAI *ai45b590();
	bool f5c8820(struct C2YEntityH other);
	C2YH f5d5d40();
	C2YPos8 f5c80f0();
	C2YPoint &getPosition();
};
struct C2YEntityH
{
	int id;
	C2YEntityH();
	bool isValid() const;
	C2YEntity *operator->() const;
	bool operator==(C2YEntityH o) const;
	bool operator!=(C2YEntityH o) const;
	void reset9b7270();
};
struct C2YHValid { int id; bool isValid() const; };
struct C2YIntVec { int &operator[](unsigned i); };
struct C2YColorVec { int f0, f1, f2, f3; C2YColorVec(); ~C2YColorVec(); };
struct C2YItem
{
	int trapHack();
	int damage();
	C2YColor *f577260();
	string f571db0(int a, int b);
	int f457880();
	int getNestedField();
	void describe5759b0(string &text, C2YColorVec &colors);
	int getEffectValue(int effect);
};
struct C2YItemH
{
	int id;
	bool isValid() const;
	C2YItem *operator->();
	bool operator!=(C2YItemH o) const;
};
struct C2YRange { char p00[0x2c]; int type; int center; int spread; char p38[4]; int f3c; };
struct C2YPropInfo { char p00[0x8c]; C2YRange *range; char p90[0xf8 - 0x90]; int hue; char pfc[0x118 - 0xfc]; int f118; char p11c[4]; int f120; char p124[0x164 - 0x124]; int glyph; };
struct C2YStats { bool f65cf50(int type); };
struct C2YProp
{
	int f45c570();
	int f45c5d0();
	bool f470b30();
	const string &getName();
	bool isTrap();
	C2YColor f65dbb0();
	C2YPropInfo *info();
	C2YStats *stats();
	int f45c630();
};
struct C2YPropH
{
	int id;
	C2YPropH();
	bool isValid() const;
	bool isNull() const;
	C2YProp *operator->() const;
};
struct C2YLocation { int f0; int type; char p08[0x25 - 8]; bool known; bool inRange46ecb0(); };
struct C2YLocH { int id; C2YLocation *operator->(); };
struct C2YZone { char p00[8]; C2YLocH loc; char p0c[0x1c - 0xc]; int kind; };
struct C2YCell
{
	C2YEntityH getEntity();
	C2YItemH getItem();
	C2YPropH getProp();
	int f45d1c0();
	const string &f45d140();
	bool isEdge();
	int f45d1a0();
	bool isShortcut();
	void *getEffect(int type);
	bool f45db70();
	bool isMachinePart();
	int getArmor();
};
struct C2YMap { C2YCell **atPoint(const C2YPoint &p); };
struct C2YBS
{
	C2YEntityH getPlayer();
	bool isVisible(const C2YPoint &p);
	double f718430(C2YEntityH from, const C2YPoint &to, int a, int b);
	double f719a90(C2YEntityH from, const C2YPos8 &with, C2YPoint &at, int a, int b);
	int getEntityValue(C2YEntityH e);
	bool f463e90(int v);
	bool f463e90(C2YPoint &p);
	C2YZone *getZone(int id);
};
struct C2YClamp { int clamp40c270(int v); };
struct C2YGameData { bool f789580(C2YEntityH e); };
struct C2YSquad { int f0; };
struct C2YOvermind { C2YSquad *f683310(C2YEntityH e); };
struct C2YTerrainRec { char p00[0x68]; int armor; };

class C2YScanText	// NOTE: placeholder (CScanText, 0x74 bytes)
{
public:
	int f[0x1d];
	C2YScanText(class CScan *parent, int x, int y, int width, string text, C2YH a, C2YH b);
	void setStyle(int a, int b, int c);
};

class CScan	// NOTE: placeholder layout
{
public:
	char p00[0x74];
	C2YScanText *title;		// +0x74
	C2YScanText *detail;	// +0x78
	char p7c[4];
	C2YPoint pos80;			// +0x80
	C2YPropH prop88;		// +0x88
	C2YEntityH entity8c;	// +0x8c
	int f90, f94, f98, f9c;	// +0x90
	C2YItemH itemA0;		// +0xa0
	int fa4;				// +0xa4
	C2YPoint posA8;			// +0xa8
	char pb0[4];
	bool hidden;			// +0xb4

	int f884da0(C2YEntityH e);
	bool f884d00();
	void f887540();
	void removeSubconsole(C2YScanText *c);
	void clearInterior();
	void putChar418110(int x, int y, int ch, C2YColor color);
	void setBack417fc0(int x, int y, C2YColor color, int a);
	void load(C2YPoint *pos, bool force);
};

extern C2YMap c2y_cfd44c;
extern C2YBS *c2y_cefc4c;
extern C2YClamp c2y_d2c3f4, c2y_d1e01c;
extern bool c2y_d28d16;
extern int c2y_b96118[], c2y_b96130[];
extern C2YColor c2y_d2cf08[][10];
extern C2YGameData c2y_d1e860;
extern C2YOvermind c2y_cf6428;
extern int c2y_cefb38, c2y_cfb794, c2y_cf4718;
extern string c2y_d35c40[], c2y_d323f8[], c2y_cfaca0[];
extern C2YColor &c2y_d22e44, &c2y_d1d4d4;
extern C2YColor *c2y_d2b4f4;
extern C2YIntVec c2y_cf4830;
extern C2YHSV c2y_b9e678[], c2y_b9e654[];
extern unsigned char c2y_ba6650[][3];
string c2y_splitLine(const string &text, int width);
extern const char c2y_c0142c[], c2y_c01434[], c2y_c01438[], c2y_c01440[], c2y_c0143c[], c2y_c0144c[], c2y_c01458[],
	c2y_c0145c[], c2y_c01460[], c2y_c01474[], c2y_c01480[], c2y_c01488[], c2y_c01490[], c2y_c0149c[], c2y_c014a8[],
	c2y_c014c0[], c2y_c014bc[], c2y_c014b8[], c2y_c014b0[], c2y_c014ac[], c2y_c014c8[], c2y_c0150c[], c2y_c0151c[],
	c2y_c0152c[], c2y_c01538[], c2y_c01548[], c2y_c0154c[], c2y_c01558[], c2y_c01564[], c2y_c01570[], c2y_c0157c[];

void CScan::load(C2YPoint *pos, bool force)
{
	C2YEntityH entity = (*c2y_cfd44c.atPoint(*pos))->getEntity();
	if (entity == c2y_cefc4c->getPlayer())
		entity.reset9b7270();
	C2YItemH item = (*c2y_cfd44c.atPoint(*pos))->getItem();
	if (!force && pos80.test409b90(*pos))
	{
		if (entity != entity8c)
			goto changed;
		else if (entity.isValid() && entity == entity8c)
		{
			if (entity->f490840() != f90 || f884da0(entity) != f94 || c2y_d2c3f4.clamp40c270((int)(c2y_cefc4c->f718430(c2y_cefc4c->getPlayer(), *pos, 0, 0) * 100.0)) != f98)
				goto changed;
		}
		else if (item != itemA0)
			goto changed;
		else if (item.isValid())
		{
			if (item->trapHack() != f90 || item->damage() != fa4)
				goto changed;
		}
		return;
	}
changed:
	if (!c2y_cefc4c->isVisible(*pos))
	{
		if (!hidden)
		{
			f887540();
			hidden = true;
		}
		return;
	}
	hidden = false;
	C2YPropH prop = (*c2y_cfd44c.atPoint(*pos))->getProp().isValid() && (*c2y_cfd44c.atPoint(*pos))->getProp()->f45c5d0() && !(*c2y_cfd44c.atPoint(*pos))->getProp()->f470b30() ? (*c2y_cfd44c.atPoint(*pos))->getProp() : C2YPropH();
	if (prop.isValid() && prop88.operator->() && prop->f45c570() == prop88->f45c570())
		return;
	else if (entity.isValid() && entity8c.operator->() && entity == entity8c && entity->f490840() == f90 && f884da0(entity) == f94 && c2y_d2c3f4.clamp40c270((int)(c2y_cefc4c->f718430(c2y_cefc4c->getPlayer(), *pos, 0, 0) * 100.0)) == f98)
		return;
	f90 = -1;
	f94 = 6;
	fa4 = -1;
	C2YCell *cell = (*c2y_cfd44c.atPoint(*pos))->f45d1c0() ? *c2y_cfd44c.atPoint(*pos) : 0;
	if (entity.isValid() || item.isValid() || prop.isValid() || cell || f884d00())
	{
		if (title)
		{
			removeSubconsole(title);
			title = 0;
		}
		if (detail)
		{
			removeSubconsole(detail);
			detail = 0;
		}
		clearInterior();
		pos80 = *pos;
		prop88 = prop;
		entity8c = entity;
		itemA0 = item;
		if (entity.isValid())
		{
			f90 = entity->f490840();
			f94 = f884da0(entity);
			if (c2y_d28d16)
			{
				putChar418110(1, 1, 0xae, *entity->f5ca2b0());
				if (f94 != 6)
					setBack417fc0(1, 1, c2y_d2cf08[c2y_b96118[f94]][c2y_b96130[f94]], 1);
			}
			else
				putChar418110(1, 1, 0xb3, *entity->f5ca2b0());
			string label = entity->name();
			if (entity->getGroup()->type() == 3 && c2y_d1e860.f789580(entity))
			{
				C2YSquad *squad = c2y_cf6428.f683310(entity);
				if (squad && squad->f0)
					label += c2y_c0142c;
			}
			if (entity->f5cad50() == 2)
				label += c2y_c01434 + c2y_d35c40[c2y_cefb38];
			title = new C2YScanText(this, 3, 1, c2y_cfb794 - 4, label, C2YH(), *(C2YH *)&entity);
			title->setStyle(0, 0, 0);
			int value = c2y_cefc4c->getEntityValue(entity);
			if (value != 0 && !entity->f45ade0())
				value = 0;
			if (value != 0)
				putChar418110(1, 2, 0x3f, value == 1 ? c2y_d22e44 : c2y_d1d4d4);
			else if (!entity->f5c7fc0(c2y_cefc4c->getPlayer()) && entity->ai45b590() && entity->ai45b590()->f458fb0(c2y_cefc4c->getPlayer()))
				putChar418110(1, 2, 0x21, *c2y_d2b4f4);
			f98 = c2y_d2c3f4.clamp40c270((int)(c2y_cefc4c->f718430(c2y_cefc4c->getPlayer(), *pos, 0, 0) * 100.0));
			f9c = c2y_cefc4c->getPlayer()->f5c8820(entity) && ((C2YHValid &)c2y_cefc4c->getPlayer()->f5d5d40()).isValid()
				? c2y_d1e01c.clamp40c270((int)(c2y_cefc4c->f719a90(c2y_cefc4c->getPlayer(), entity->f5c80f0(), c2y_cefc4c->getPlayer()->getPosition(), 0, 0) * 100.0))
				: -1;
			detail = new C2YScanText(this, 3, 2, c2y_cfb794 - 4, c2y_c0144c + intToString(f98) + (f9c == -1 ? string(c2y_c01438) : c2y_c01440 + intToString(f9c) + c2y_c0143c), C2YH(), C2YH());
			detail->setStyle(1, 0, 0);
		}
		else if (item.isValid())
		{
			f90 = item->trapHack();
			fa4 = item->damage();
			putChar418110(1, 1, 0xb3, *item->f577260());
			title = new C2YScanText(this, 3, 1, c2y_cfb794 - 4, item->f571db0(1, 0), *(C2YH *)&item, C2YH());
			title->setStyle(0, 0, 0);
			if (item->f457880() >= 6 && c2y_cf4830[item->getNestedField()] != 0)
			{
				string desc;
				C2YColorVec cols;
				item->describe5759b0(desc, cols);
				detail = new C2YScanText(this, 3, 2, c2y_cfb794 - 4, desc, C2YH(), C2YH());
				detail->setStyle(1, 0, 0);
			}
			else if (item->getEffectValue(0x4a))
			{
				string range = intToString(item->getEffectValue(0x49)) + c2y_c01458 + intToString(item->getEffectValue(0x4a));
				detail = new C2YScanText(this, 3, 2, c2y_cfb794 - 4, range, C2YH(), C2YH());
				detail->setStyle(1, 0, 0);
			}
			else if (item->getEffectValue(0x4b))
			{
				string bonus = intToString(item->getEffectValue(0x4b)) + c2y_c0145c;
				detail = new C2YScanText(this, 3, 2, c2y_cfb794 - 4, bonus, C2YH(), C2YH());
				detail->setStyle(1, 0, 0);
			}
		}
		else
		{
			string result;
			if (prop.isValid())
				result = prop->getName();
			else
			{
				C2YCell *c = cell ? cell : *c2y_cfd44c.atPoint(posA8);
				string s = c->f45d140();
				if (c->isEdge())
				{
					if (c2y_cefc4c->f463e90(c->f45d1a0()))
					{
						if (c->isShortcut())
							s = c2y_c01460;
						else
							s = c2y_c01474;
						if (c->getEffect(6))
							s.insert(0, c2y_c01480);
					}
				}
				else if (c->f45db70() && c->getEffect(6))
					s.insert(0, c2y_c01488);
				result = s;
			}
			string caption = c2y_splitLine(result, c2y_cfb794 - 4);
			bool open = prop.isValid() ? prop->f45c5d0() == 2 : cell ? cell->f45d1c0() == 2 : true;
			bool seen = false;
			bool valid = false;
			if (prop.isValid())
			{
				if (prop->isTrap())
				{
					putChar418110(1, 1, prop->info()->glyph, prop->f65dbb0());
					caption = prop->stats()->f65cf50(c2y_cefc4c->getPlayer()->getGroup()->type()) ? c2y_c01490 : c2y_c0149c;
					valid = true;
				}
				else
				{
					C2YColor color;
					if (prop->info()->hue != 9)
						color.setHSV(c2y_b9e678[prop->info()->hue].h, c2y_b9e678[prop->info()->hue].s, c2y_b9e678[prop->info()->hue].v);
					else if (prop->info()->f118 != 0 || prop->info()->f120 != 0)
						color.setHSV(c2y_b9e654[prop->info()->f120].h, c2y_b9e654[prop->info()->f120].s, c2y_b9e654[prop->info()->f120].v);
					if (color.nonzero())
						putChar418110(1, 1, 0xb3, color);
					if (!prop->f470b30() && caption.empty())
					{
						caption = prop->f45c630() == -1 ? string(c2y_c014a8) : intToString(prop->f45c630());
						if (prop->info()->range)
						{
							C2YRange *r = prop->info()->range;
							caption += c2y_c014c0 + c2y_d323f8[r->type] + c2y_c014bc + intToString(r->center - r->spread) + c2y_c014b8
								+ intToString(r->center + r->spread) + c2y_c014b0 + intToString(r->f3c) + c2y_c014ac;
						}
						valid = true;
					}
				}
			}
			else if (cell && cell->isMachinePart())
			{
				if (!caption.empty())
					logError(c2y_c0150c, c2y_c014c8);
				else
				{
					C2YZone *zone = c2y_cefc4c->getZone(cell->f45d1a0());
					C2YLocH loc = zone->loc;
					if (loc->known && !loc->inRange46ecb0())
					{
						switch (loc->type)
						{
						case 0xd:
							result = c2y_c0151c;
							break;
						case 0xe:
							result = c2y_c0152c;
							break;
						default:
							result = c2y_c01538;
						}
						seen = true;
					}
					caption = loc->known ? c2y_cfaca0[loc->type] : string(c2y_c01548);
					if (c2y_ba6650[loc->type][c2y_cf4718])
						caption += c2y_c0154c;
					else if (zone->kind == 2)
						caption += c2y_c01558;
					else if (zone->kind == 3)
						caption += c2y_c01564;
					else if (zone->kind == 4)
						caption += c2y_c01570;
				}
			}
			bool selected = prop.isNull() && cell == 0;
			title = new C2YScanText(this, 3, 1, c2y_cfb794 - 4, result, C2YH(), C2YH());
			title->setStyle(0, open, selected);
			if (selected)
			{
				int armor = (*c2y_cfd44c.atPoint(posA8))->getArmor();
				if ((*c2y_cfd44c.atPoint(posA8))->isEdge() && !c2y_cefc4c->f463e90(posA8))
					armor = ((C2YTerrainRec *)TERRAIN_CAVE_WALL)->armor;
				caption = armor == -1 ? string(c2y_c0157c) : intToString(armor);
				valid = true;
			}
			if (!caption.empty())
			{
				if (!valid && caption.size() + 2 < c2y_cfb794 - 4)
				{
					caption.insert(0, 2, ' ');
					if (prop.isNull() && cell)
						caption[0] = seen ? '>' : '<';
				}
				detail = new C2YScanText(this, 3, 2, c2y_cfb794 - 4, caption, C2YH(), C2YH());
				detail->setStyle(valid, open, selected);
			}
		}
	}
	else
		f887540();
}
