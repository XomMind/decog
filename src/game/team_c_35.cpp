// team_c_35: CHudData::drawContent (0x87bd50): draws one HUD data line (core, energy, matter, ...) per CHudData::type
// NOTE: class/member names are placeholders (f<offset>/v<offset>); helper classes and globals are private placeholders
#include <string>
#include <vector>
#include <time.h>
using namespace std;

struct Point { int x; int y; Point(); Point(const Point &p); };	// NOTE: placeholder
struct Pos : Point { Pos(int x_, int y_); };	// NOTE: placeholder
struct XColor { unsigned char r; unsigned char g; unsigned char b; XColor(const XColor &c); XColor &operator=(XColor c); bool operator!=(XColor c); XColor operator*(float f); };
struct HProp { int v; bool isNull() const; };
struct C87_Item { int size(); int count(); int unknown457f90(); bool unknown457cf0(); int unknown457fb0(); int unknown457fd0(); int f0(); int f1(); int f2(); };	// NOTE: placeholder (Item)
struct C87_Handle { int id; C87_Item *get224(); bool isValid() const; bool isNull() const; };	// NOTE: placeholder (HItem)
struct C87_Rec23c { int f0; int f4; int f8; char pad0c[0x25 - 0x0c]; bool f25; };
struct C87_Tile { C87_Rec23c *get23c(); };	// NOTE: placeholder (OpC_Handle at 0xd1e888)
class Entity
{
public:
	int getField();	// NOTE: placeholder names (folded getters)
	int unknown45a8d0(); int unknown45a920(); int unknown45a990(); int unknown45a700(); int size();
	int unknown5ca400(); float unknown5ca4f0(); int unknown5ca580(); int unknown5ca670(); int unknown5ca750(); int unknown5ca840();
	int unknown5ca8d0(); int unknown5ca960(); int unknown5cab90(); int unknown5cad50(); int unknown5cb000(); int unknown5cb110();
	int unknown5cca00(); int unknown5c8c40(int a); int unknown5d1070(); int unknown5d1390(); int unknown5d15a0(int a);
	int unknown5d1d70(); int unknown5d1da0(); float unknown5d1e40(); int unknown5d2090(int a); int unknown5d22a0(int a);
	C87_Handle unknown5d2380(int a); int unknown5d2430(int a, vector<C87_Handle> &out);
	vector<C87_Handle> *getInventoryList();
};
class HEntity { public: int ID; Entity *operator->() const; };
class C87_Map { public: HEntity getPlayer(); int unknown463d40(); int unknown4642d0(); int getField(); int getTurn(); };	// NOTE: placeholder (Map)
class C87_Anims { public: void unknown454e20(const Pos &pos); };	// NOTE: placeholder (OpR1d_AnimList)

class XConsole
{
public:
	virtual ~XConsole();
	bool isHidden();
	void clear();
	void setFore(XColor c);
	void setFore_417f80(int x, int y, XColor c);
	XColor getFore(int x, int y);
	void setBackRow(int x, int y, int width, XColor c);
	void print(int x, int y, const string &text);
	int getLastCharX(int y);
	void printAligned(int x, int y, int align, const string &text);
	int getWidth();
	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	void animate(string name);
	int f60;
	C87_Anims *f64;
	void *f68;
};

class CHudData : public Console
{
public:
	void drawContent(bool keep);
	void drawBar(bool animated, string label, Point *meter, XColor color);
	int f6c;
	int f70;
};
struct C87_Flag { bool getField(); };	// NOTE: placeholder
struct C87_GM { unsigned int unknown470aa0(int a); };	// NOTE: placeholder
struct C87_GameData { const string &getEntryText(const string &name); bool unknown46f4b0(int a); };	// NOTE: placeholder
struct C87_Flags { int delegate(int id); };	// NOTE: placeholder
struct C87_PlayerData { void unknown77fbc0(int id); };	// NOTE: placeholder
extern string gameStrings_cf2740[], gameStrings_cf67e0[], gameStrings_cfaca0[], gameStrings_d227b0[], gameStrings_d2e148[];
string intToString(int value);
int stringToInt(const string &s);
void logError(string location, string message);
int OpX5_maxInt(int a, int b);
int OpX5_minInt(int a, int b);
bool OpX5_inRangeExcl(int a, int b, int c);
string OpY1_floatToStringSigned(float value, int unknown1, int unknown2);
string OpY1_intToStringSigned(int value);
float opR1d_4371a0(float a, float b, int period, int offset);
string &padLeft_408090(string &text, int width, char fill);
string opr1c_getSecurityName_4332b0(int value);
XColor opq4a_getSpeedLabel(int speed, string &label);
extern const float c30_c37088, c30_ba6b9c, c30_ba6ba0;	// NOTE: placeholder names

// globals (placeholders)
extern int c87_b96118[];
extern int c87_b96130[];
extern int c87_b961cc;
extern bool c87_ba0984[];
extern unsigned int c87_caed20;
extern int c87_cebd5c;
extern C87_Flag * c87_cec054;
extern C87_GM * c87_cefaa8;
extern bool c87_cefacd;
extern int c87_cefaf4;
extern int c87_cefb38;
extern C87_Map * c87_cefc4c;
extern int c87_cefc74;
extern int c87_cefc78;
extern int c87_cefc7c;
extern bool c87_cefc8a;
extern XColor * c87_cf13fc;
extern XColor * c87_cf27e8;
extern XColor * c87_cf44c0;
extern C87_PlayerData c87_cf45d8;
extern int c87_cf462c;
extern bool c87_cf468c;
extern int c87_cf4954;
extern bool c87_cf4980;
extern bool c87_cf49f0;
extern int c87_cf49f4;
extern int c87_cf49fc;
extern vector<int> c87_cf4a14;
extern XColor * c87_cf63b0;
extern int c87_cf6428;
extern int c87_cf645c;
extern bool c87_cf6468;
extern int c87_cf6474;
extern XColor * c87_cf6b24;
extern XColor * c87_cfd2fc;
extern string c87_cfe110;
extern XColor * c87_cfe674;
extern XColor * c87_d01564;
extern XColor * c87_d15d98;
extern XColor * c87_d161d4;
extern C87_GameData c87_d1e860;
extern C87_Tile c87_d1e888;
extern XColor * c87_d20438;
extern XColor * c87_d2043c;
extern XColor * c87_d204ac;
extern XColor * c87_d20b70;
extern XColor * c87_d2175c;
extern XColor * c87_d22130;
extern XColor * c87_d25e0c;
extern bool c87_d28c8a;
extern bool c87_d28d16;
extern bool c87_d28d26;
extern bool c87_d28d8c;
extern bool c87_d28d8d;
extern bool c87_d28e76;
extern bool c87_d28e77;
extern bool c87_d28e78;
extern XColor c87_d29804;
extern XColor * c87_d2981c;
extern vector<XColor> c87_d2b4bc;
extern C87_Flags c87_d2c658;
extern XColor c87_d2cf08[][10];
extern XColor * c87_d2f34c;
extern XColor * c87_d31574;
extern XColor * c87_d3579c;
extern XColor * c87_d35be0;
extern int c87_d3846c;
extern XColor * c87_d38644;
extern XColor * c87_d395f8;
void CHudData::drawContent(bool keep)
{
	HEntity center = c87_cefc4c->getPlayer();
	if (!center.operator->())
	{
		return;
	}
	if (!keep)
	{
		clear();
	}
	Point col;
	string cols;
	switch (f6c)
	{
	case 0:
		col.x = center->getField();
		col.y = c87_cf4954;
		if (col.x < 0)
	{
		logError("CHudData::drawContent()", "Negative core integrity!");
		col.x = 0;
	}
		cols = " CORE   " + intToString(col.x) + "/" + intToString(col.y);
		setFore((keep ? *c87_cfe674 : (c87_d28d26 ? *c87_d35be0 : *c87_d25e0c)));
		print(0, 0, cols);
		if (keep)
	{
		animate("A_CHudData_Core");
	}
		if (!keep && c87_d28d16)
	{
		int current = center->unknown5cca00();
		string distanceSq = " (" + intToString(current) + "% exposed)";
		c87_d2b4bc[0] = c87_d28d26 ? *c87_d20b70 : *c87_d2981c;
		print(cols.size(), 0, "`f" + intToString(0) + "`" + distanceSq + "`x`");
		if (current <= 2)
	{
		c87_cf45d8.unknown77fbc0(137);
	}
	}
		drawBar(keep, "Core", &col, *c87_d2175c);
		if (c87_cefc7c != 0)
	{
		if (OpX5_inRangeExcl(c87_cefc78, c87_caed20, c87_cefc74))
	{
		for (int current = 0, distanceSq = 1; current < c87_cefc7c; current++, distanceSq++)
			setFore_417f80(distanceSq, 0, getFore(distanceSq, 0) * c30_c37088);
	}
	}
		break;
	case 1:
		col.x = center->unknown45a8d0();
		col.y = center->unknown5ca400();
		if (col.x < 0)
	{
		logError("CHudData::drawContent()", "Negative energy!");
		col.x = 0;
	}
		cols = " ENERGY " + intToString(col.x) + "/" + intToString(col.y);
		setFore((keep ? *c87_cfe674 : (c87_d28d26 ? *c87_d31574 : *c87_d15d98)));
		print(0, 0, cols);
		if (keep)
	{
		animate("A_CHudData_Energy");
	}
		if (!keep)
	{
		int adj = center->unknown5d1070();
		if (center->unknown5d2380(154).isValid())
	{
		vector<C87_Handle> distances;
		center->unknown5d2430(154, distances);
		int dy = center->unknown45a920();
		if (dy != 0)
		{
			for (unsigned int enemies = 0; enemies < distances.size() && dy != 0; enemies++, dy--)
				adj += distances[enemies].get224()->unknown457fb0();
		}
	}
		if (center->unknown5d2380(155).isValid())
	{
		if (center->unknown45a990() > 0)
	{
		vector<C87_Handle> facing;
		center->unknown5d2430(155, facing);
		for (unsigned int first = 0; first < facing.size(); first++)
	{
		adj = center->unknown45a990() / facing[first].get224()->unknown457fb0() + adj;
	}
	}
	}
		float a1 = center->unknown5ca4f0();
		if (center->unknown5d2380(153).isValid())
	{
		vector<C87_Handle> distances;
		center->unknown5d2430(153, distances);
		for (unsigned int enemies = 0; enemies < distances.size(); enemies++)
	{
		a1 = distances[enemies].get224()->unknown457fd0() + a1;
	}
	}
		float base = center->unknown5d15a0(0);
		float allies = adj - a1;
		float behaviour = center->unknown5d1e40();
		float clean = ((base / 100.0) * allies) - behaviour;
		float current = allies - 100 / base * behaviour;
		float &attempt = (c87_d28e76 ? current : clean);
		string distanceSq = OpY1_floatToStringSigned(allies, 1, 1);
		string amount = OpY1_floatToStringSigned(attempt, 1, 1);
		XColor ay((c87_d28d26 ? *c87_cfd2fc : *c87_cf63b0));
		XColor active((c87_d28d26 ? *c87_d2f34c : *c87_d204ac));
		if (!c87_d28d16)
	{
		c87_d2b4bc[0] = (attempt) >= 0.0 ? ay : active;
		print(cols.size(), 0, "`f" + intToString(0) + "`" + " (" + amount + ")" + "`x`");
	}
	else
	{
		int distances = getLastCharX(0) + 2;
		c87_d2b4bc[0] = ay;
		print(distances, 0, "`f" + intToString(0) + "`" + "(" + "`x`");
		distances = distances + 1;
		c87_d2b4bc[0] = allies >= 0.0 ? ay : active;
		print(distances, 0, "`f" + intToString(0) + "`" + distanceSq + "`x`");
		distances = distances + distanceSq.size() + 1;
		c87_d2b4bc[0] = (attempt) >= 0.0 ? ay : active;
		print(distances, 0, "`f" + intToString(0) + "`" + amount + "`x`");
		distances = amount.size() + distances;
		c87_d2b4bc[0] = ay;
		print(distances, 0, "`f" + intToString(0) + "`" + ")" + "`x`");
	}
		int desc = center->unknown5ca580();
		if (desc != 0)
	{
		int distances = getLastCharX(0) + 2;
		print(distances, 0, "`f" + intToString(0) + "`" + "I:" + intToString(desc) + "`x`");
	}
	}
		drawBar(keep, "Energy", &col, *c87_d395f8);
		break;
	case 2:
		col.x = center->unknown45a920();
		col.y = center->unknown5ca670();
		if (col.x < 0)
	{
		logError("CHudData::drawContent()", "Negative matter!");
		col.x = 0;
	}
		cols = " MATTER " + intToString(col.x) + "/" + intToString(col.y);
		setFore((keep ? *c87_cfe674 : (c87_d28d26 ? *c87_d20438 : *c87_d38644)));
		print(0, 0, cols);
		if (keep)
	{
		animate("A_CHudData_Matter");
	}
		if (!keep)
	{
		int current = 0;
		int adj = 0;
		vector<C87_Handle> * allies = center->getInventoryList();
		for (unsigned int distanceSq = 0; distanceSq < allies->size(); distanceSq++)
	{
		if ((*allies)[distanceSq].get224()->unknown457f90() == 160)
	{
		if ((*allies)[distanceSq].get224()->unknown457cf0())
	{
		if ((*allies)[distanceSq].get224()->size())
	{
		current = (OpX5_minInt((*allies)[distanceSq].get224()->unknown457fb0() / 10, (*allies)[distanceSq].get224()->size())) + current;
	}
	}
		adj = (*allies)[distanceSq].get224()->size() + adj;
	}
	}
		if (adj != 0)
	{
		setFore((c87_d28d26 ? *c87_cf13fc : *c87_d3579c));
		print(getLastCharX(0) + 2, 0, "(+" + intToString(current) + "/" + intToString(adj) + ")");
	}
		if (c87_d28d16)
	{
		setFore((c87_d28d26 ? *c87_cf13fc : *c87_d3579c));
		int distanceSq = center->unknown5ca750();
		if (distanceSq != 0)
	{
		print(getLastCharX(0) + 2, 0, "I:" + intToString(distanceSq));
	}
	}
		if (c87_cf4980)
	{
		setFore((c87_d28d26 ? *c87_cf13fc : *c87_d3579c));
		print(getLastCharX(0) + 2, 0, "ED");
	}
	}
		drawBar(keep, "Matter", &col, *c87_d01564);
		break;
	case 3:
	{
		col.x = center->unknown5cab90();
		col.y = 100;
		if (col.x < 0)
	{
		logError("CHudData::drawContent()", "Negative corruption!");
		col.x = 0;
	}
		cols = " SYS. CORRUPTION " + intToString(col.x) + "%";
		if (c87_cf49f0)
	{
		cols += " (Immune)";
	}
		setFore((keep ? *c87_cfe674 : *c87_d2981c));
		print(0, 0, cols);
		int current = center->unknown5d2090(42);
		if (current != 0)
	{
		int distanceSq = getLastCharX(0) + 2;
		cols = "(-" + intToString(current) + ")";
		c87_d2b4bc[0] = *c87_cf6b24;
		print(distanceSq, 0, "`f" + intToString(0) + "`" + cols + "`x`");
	}
		if (keep)
	{
		animate("A_CHudData_Corruption");
	}
		drawBar(keep, "Corruption", &col, *c87_d35be0);
	}
	break;
	case 4:
	{
		int current = center->unknown5ca840();
		string adj(gameStrings_cf2740[current]);
		XColor behaviour(c87_d2cf08[c87_b96118[current]][c87_b96130[current]]);
		if (center->unknown45a990() < 0)
	{
		adj = (center->unknown45a990() < -100 ? "FREEZING" : "FRIGID");
		behaviour = *c87_d15d98;
	}
		setFore((keep ? *c87_cfe674 : *c87_d2981c));
		c87_d2b4bc[0] = *c87_cfe674;
		cols = " TEMP " + ("`f" + intToString(0) + "`") + " " + adj + " " + "`x`" + " Heat " + intToString(center->unknown45a990());
		print(0, 0, cols);
		if (keep)
	{
		animate("A_CHudData_Temperature");
	}
	else
	{
		int distanceSq = OpX5_maxInt(c87_b961cc, center->unknown5d22a0(40));
		if (distanceSq > c87_b961cc)
	{
		if (center->unknown45a990() >= c87_b961cc)
	{
		if (!c87_cefc4c->unknown463d40())
	{
		c87_d2b4bc[0] = *c87_d20438;
		print(getLastCharX(0) + 1, 0, "`f" + intToString(0) + "`" + "/" + intToString(distanceSq) + "`x`");
	}
	}
	}
		if (current >= 3)
	{
		if (center->unknown45a990() >= distanceSq)
	{
		setBackRow(0, 0, c87_d3846c, behaviour * opR1d_4371a0(c30_ba6b9c, c30_ba6ba0, 1000, 0));
	}
	}
		setBackRow(6, 0, adj.size() + 2, behaviour);
		float distances = center->unknown5d15a0(0);
		float enemies = center->unknown5ca8d0() - center->unknown5ca960() + c87_cefc4c->unknown463d40();
		float facing = center->unknown5d1da0();
		float clean = ((distances / 100.0) * enemies) + facing;
		float desc = ((100.0 / distances) * facing) + enemies;
		float &allies = (c87_d28e77 ? desc : clean);
		string dy = OpY1_floatToStringSigned(enemies, 1, 1);
		string first = OpY1_floatToStringSigned(allies, 1, 1);
		if (!c87_d28d16)
	{
		c87_d2b4bc[0] = (allies) >= 0.0 ? *c87_d204ac : *c87_cf6b24;
		print(getLastCharX(0) + 1, 0, "`f" + intToString(0) + "`" + " (" + first + ")" + "`x`");
	}
	else
	{
		int found = getLastCharX(0) + 2;
		c87_d2b4bc[0] = *c87_cf6b24;
		print(found, 0, "`f" + intToString(0) + "`" + "(" + "`x`");
		found = found + 1;
		c87_d2b4bc[0] = enemies >= 0.0 ? *c87_d204ac : *c87_cf6b24;
		print(found, 0, "`f" + intToString(0) + "`" + dy + "`x`");
		found = found + dy.size() + 1;
		c87_d2b4bc[0] = (allies) >= 0.0 ? *c87_d204ac : *c87_cf6b24;
		print(found, 0, "`f" + intToString(0) + "`" + first + "`x`");
		found = first.size() + found;
		int element = center->unknown5d2090(2);
		if (element != 0)
	{
		string hits = " -" + intToString(element);
		c87_d2b4bc[0] = *c87_d20438;
		print(found, 0, "`f" + intToString(0) + "`" + hits + "`x`");
		found = hits.size() + found;
	}
		vector<C87_Handle> begin;
		if (center->unknown5d2430(4, begin))
	{
		int entityID = 0;
		for (unsigned int it = 0; it < begin.size(); it++)
	{
		entityID = (begin[it].get224()->count() * begin[it].get224()->unknown457fb0()) + entityID;
	}
		bool hits = 0;
		if (entityID >= 1000)
	{
		entityID = entityID / 1000;
		hits = 1;
	}
		string h2 = " -" + intToString(entityID);
		if (hits)
	{
		h2 += "K";
	}
		c87_d2b4bc[0] = *c87_cf27e8;
		print(found, 0, "`f" + intToString(0) + "`" + h2 + "`x`");
		found = h2.size() + found;
	}
		if (center->unknown5d2380(5).isValid())
	{
		c87_d2b4bc[0] = *c87_cf27e8;
		print(found, 0, "`f" + intToString(0) + "`" + " *" + "`x`");
		found = found + 2;
	}
		c87_d2b4bc[0] = *c87_cf6b24;
		print(found, 0, "`f" + intToString(0) + "`" + ")" + "`x`");
	}
		if (c87_cefc4c->unknown463d40())
	{
		int found = getLastCharX(0) + 2;
		c87_d2b4bc[0] = *c87_cf6b24;
		print(found, 0, "`f" + intToString(0) + "`" + "(amb. " + "`x`");
		found = found + 6;
		int hits = c87_cefc4c->unknown463d40();
		string element = intToString(hits);
		c87_d2b4bc[0] = hits < 0 ? *c87_d2043c : *c87_cf27e8;
		print(found, 0, "`f" + intToString(0) + "`" + element + "`x`");
		found = element.size() + found;
		c87_d2b4bc[0] = *c87_cf6b24;
		print(found, 0, "`f" + intToString(0) + "`" + ")" + "`x`");
	}
		if (c87_cf49f4 != 0)
	{
		int found = getLastCharX(0) + 2;
		c87_d2b4bc[0] = *c87_d2981c;
		print(found, 0, "`f" + intToString(0) + "`" + "ITN" + "`x`");
	}
	}
	}
	break;
	case 5:
	{
		int current = center->unknown5d1d70();
		int adj = center->unknown5d15a0(0);
		string allies;
		XColor behaviour = opq4a_getSpeedLabel(adj, allies);
		c87_d2b4bc[0] = *c87_cfe674;
		int clean = 0;
		cols = " MOVEMENT: ";
		int begin = center->unknown5cad50();
		if (begin != 0 && c87_ba0984[c87_cefb38])
	{
		cols += "Immobile ";
		clean = cols.size();
		switch (begin)
	{
	case 2:
		allies = " " + gameStrings_d227b0[c87_cefb38] + " ";
		behaviour = *c87_d20438;
		if (behaviour != c87_d29804)
	{
		cols += "`f" + intToString(0) + "`" + allies + "`x`" + " ";
	}
		break;
	case 1:
		cols += "(" + gameStrings_cf67e0[c87_cefb38] + " in " + intToString(center->unknown5cb000()) + ")";
		break;
	case 3:
		cols += "(" + gameStrings_cf67e0[c87_cefb38] + " end in " + intToString(center->unknown5cb110()) + ")";
	}
	}
	else
	{
		int distanceSq = center->unknown5d1390();
		int desc = center->size();
		cols += (distanceSq == 1 && center->unknown45a700() && (desc == 1 || desc == 7) ? string(desc == 1 ? "Running " : "Weaving ") : gameStrings_d2e148[distanceSq] + " ");
		clean = cols.size();
		if (begin != 0 && c87_cefb38 == 3)
	{
		if (begin == 2)
	{
		allies = " " + gameStrings_d227b0[c87_cefb38] + " ";
		behaviour = *c87_d20438;
	}
	else
	{
		allies.clear();
		behaviour = c87_d29804;
	}
	}
		if (c87_cefc8a)
	{
		behaviour = *c87_d204ac;
		allies = " INTERDICT ";
	}
		if (behaviour != c87_d29804)
	{
		cols += "`f" + intToString(0) + "`" + allies + "`x`" + " ";
	}
		cols += "(" + (c87_d28d16 ? intToString(adj) + ") " + intToString(center->unknown5c8c40(3)) : intToString(current) + "%)");
	}
		setFore((keep ? *c87_cfe674 : *c87_d2981c));
		if (c87_cf49fc != 0)
	{
		cols += " // NEM " + intToString(c87_cf49fc);
	}
		if (begin != 0 && begin != 2 && c87_cefb38 == 3)
	{
		switch (begin)
	{
	case 1:
		cols += " (" + gameStrings_cf67e0[c87_cefb38] + " in " + intToString(center->unknown5cb000()) + ")";
		break;
	case 3:
		cols += " (" + gameStrings_cf67e0[c87_cefb38] + " end in " + intToString(center->unknown5cb110()) + ")";
	}
	}
		print(0, 0, cols);
		if (keep)
	{
		animate("A_CHudData_Movement");
	}
	else
	{
		if (begin != 0 && c87_ba0984[c87_cefb38])
	{
		setBackRow(0, 0, c87_d3846c, *c87_d20438 * opR1d_4371a0(c30_ba6b9c, c30_ba6ba0, 1000, 0));
	}
	else
	{
		if (adj >= 335 || c87_cefc8a)
	{
		setBackRow(0, 0, c87_d3846c, *c87_d204ac * opR1d_4371a0(c30_ba6b9c, c30_ba6ba0, 1000, 0));
	}
	}
		if (begin == 0 || begin == 2)
	{
		setBackRow(clean, 0, allies.size(), behaviour);
	}
	}
	}
	break;
	case 6:
		if (!c87_d2c658.delegate(347))
	{
		break;
	}
		if (c87_cf468c)
	{
		cols = "  Abominations: !!! ";
	}
	else
	{
		cols = " Abominations: " + intToString(c87_d2c658.delegate(347));
	}
		if (keep || c87_cf468c)
	{
		setFore(*c87_cfe674);
	}
	else
	{
		int current = 12;
		if (c87_d2c658.delegate(347) < current)
	{
		setFore(*c87_d2981c);
	}
	else
	{
		if (c87_d2c658.delegate(347) < current << 1)
	{
		setFore(*c87_d20438);
	}
	else
	{
		if (c87_d2c658.delegate(347) < current * 3)
	{
		setFore(*c87_cf27e8);
	}
	else
	{
		setFore(*c87_d204ac);
	}
	}
	}
	}
		print(0, 0, cols);
		if (keep)
	{
		animate("A_CHudData_Time");
	}
	else
	{
		if (c87_cf468c)
	{
		setBackRow(1, 0, cols.size() - 1, *c87_d204ac);
	}
	}
		break;
	case 7:
		cols = " Time: " + intToString(c87_cefc4c->getTurn());
		if (c87_cefacd && (c87_cec054->getField() || c87_cefaf4 != 0))
	{
		cols += " (" + intToString(c87_cefc4c->getField()) + " instant)";
	}
	else
		if (c87_d28e78)
	{
		if (c87_cefc4c->unknown4642d0() >= 1000000)
	{
		cols += " // M: " + intToString(c87_cefc4c->unknown4642d0());
	}
	else
	{
		cols += " // Map: " + intToString(c87_cefc4c->unknown4642d0());
	}
	}
		setFore((keep ? *c87_cfe674 : *c87_d2981c));
		print(0, 0, cols);
		if (keep)
	{
		animate("A_CHudData_Time");
	}
		break;
	case 8:
		if (c87_d1e888.get23c()->f4 == 36)
	{
		cols = "Loc: " + c87_cfe110;
	}
	else
	{
		cols = "Loc: -" + intToString(c87_d1e888.get23c()->f8) + "/" + (c87_d1e888.get23c()->f25 ? string(gameStrings_cfaca0[c87_d1e888.get23c()->f4]) : string("???"));
	}
		setFore((keep ? *c87_cfe674 : *c87_d2981c));
		print(0, 0, cols);
		if (keep)
	{
		animate("A_CHudData_Location");
	}
		if ((c87_cf6474 != 0 || c87_cf645c != 0) && !stringToInt(c87_d1e860.getEntryText("installedRif_g")) && center->unknown5d2380(29).isNull())
	{
		setFore(*c87_cfe674);
		c87_d2b4bc[0] = *c87_d204ac;
		string current((c87_cf6474 != 0 ? " Steri " : (c87_cf6468 ? " MaxSec " : " HiSec ")));
		int distanceSq = getWidth() - 3;
		int distances = 2;
		if (cols.size() + 1 < distanceSq)
	{
		distanceSq = cols.size() + 1;
		distances = 0;
	}
		printAligned(distanceSq, 0, distances, "`b" + intToString(0) + "`" + current + "`x`");
		setFore(*c87_d161d4);
		if (keep)
	{
		for (int enemies = distanceSq, adj = 0; adj < current.size(); enemies--, adj++)
			f64->unknown454e20(Pos(enemies, 0));
	}
	}
		break;
	case 9:
		if (c87_d1e860.unknown46f4b0(1) && c87_d1e888.get23c()->f4 != 35 && (stringToInt(c87_d1e860.getEntryText("installedRif_g")) || center->unknown5d2380(29).isValid()))
	{
		cols = "Influence: " + intToString(c87_cf6428) + " ";
		if (c87_cf6474 != 0)
	{
		cols = "Influence: STERILIZE";
	}
	else
	{
		if (c87_cf645c != 0)
	{
		cols += (c87_cf6468 ? "MAX" : "HIGH");
	}
	else
	{
		string facing = opr1c_getSecurityName_4332b0(c87_cf6428);
		if (facing == "Low Security")
	{
		facing = "LOW";
	}
		cols += facing;
	}
	}
	}
		if (c87_d28c8a)
	{
		if (!c87_cf4a14.empty())
	{
		int current = 29;
		string adj = "RIF_" + padLeft_408090(intToString(c87_cf4a14.size()), 2, 48);
		if (cols.size() + adj.size() < current)
	{
		cols.append(current - (cols.size() + adj.size()), 32);
	}
		cols += adj;
	}
	}
		if (!cols.empty())
	{
		setFore((keep ? *c87_cfe674 : *c87_d22130));
		print(0, 0, cols);
		if (keep)
	{
		animate("A_CHudData_Influence");
	}
	}
		break;
	case 10:
		if (c87_d28d8c || c87_d28d8d)
	{
		if (c87_cebd5c == 0 || c87_cf462c != 4)
	{
		if (c87_d28d8c)
	{
		time_t current;
		time(&current);
		tm *adj = localtime(&current);
		cols += " Clock: ";
		cols += padLeft_408090(intToString(adj->tm_hour), 2, 48);
		cols += ":";
		cols += padLeft_408090(intToString(adj->tm_min), 2, 48);
	}
		if (c87_d28d8d)
	{
		if (c87_d28d8c)
	{
		cols += " //";
	}
		unsigned int current = c87_cefaa8->unknown470aa0(0) / 60;
		cols += " Run: ";
		cols += padLeft_408090(intToString(current / 60), 2, 48);
		cols += ":";
		cols += padLeft_408090(intToString(current % 60), 2, 48);
	}
		setFore((keep ? *c87_cfe674 : *c87_cf44c0));
		print(0, 0, cols);
		if (keep)
	{
		animate("A_CHudData_Clock");
	}
	}
	}
	}
}
