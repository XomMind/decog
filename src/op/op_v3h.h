// op_v3h: shared declarations for the op_v3h*.cpp files (COGMIND.exe Beta 17.1, 0x826920-0x878d70).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#ifndef OP_V3H_H
#define OP_V3H_H

#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point() throw();	// 0x453b40
	Point(const Point &p);	// 0x46ca50
	Point &operator=(const Point &p);	// 0x46ca50 (ICF with the copy ctor)
	Point(const Point &a, const Point &b);	// 0x4099f0 (sum)
	bool operator==(const Point &p) const;	// 0x409b90
	bool operator!=(const Point &p) const;	// 0x409bd0
	void fill(int v);	// NOTE: placeholder name (0x409ff0)
};

class HItem;
class HProp;
class OpV3h_AI;

class Item
{
public:
	int unknown457820();	// NOTE: placeholder name (folded getter)
	int unknown4578c0();	// NOTE: placeholder name (folded getter)
	int unknown457920();	// NOTE: placeholder name
	string getName_571db0(int a, int b);	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	HItem();
	bool isValid() const;
	Item *operator->() const;	// 0x9b65b0
	bool operator==(HItem other) const;	// 0x9b78e0
};

class HProp
{
public:
	int ID;
	HProp();	// 0x9b6590
};

class Entity
{
public:
	Point &getPosition();	// 0x45a4a0
	Point unknown45a4c0();	// NOTE: placeholder name
	int unknown5db2b0(HItem item, bool ignoreMass);	// NOTE: placeholder name
	unsigned int unknown5cb830(vector<HItem> *out);	// NOTE: placeholder name
	int unknown6421a0(bool flag);	// NOTE: placeholder name
	OpV3h_AI *getAI_45b590();	// NOTE: placeholder name (folded getter)
};

class OpV3h_AI	// NOTE: placeholder name
{
public:
	HItem unknown4592c0();	// NOTE: placeholder name (folded getter)
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const;	// 0x9b6570
	void reset() throw();	// 0x9b7270
};

class Cell
{
public:
	HItem getItem();	// 0x45d8f0
};

template <class T>
class Array2D	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// NOTE: placeholder name (0x9ced70)
	bool contains(const Point &p);	// NOTE: placeholder name (0x9b43b0)
};
extern Array2D<Cell *> opV3h_cells;	// NOTE: placeholder name (0xcfd44c)
extern Point opV3h_directions[];	// NOTE: placeholder name (0xd015d8)
extern unsigned int opV3h_tickCount;	// NOTE: placeholder name (0xcaed20)
extern vector<int> opV3h_cf4830;	// NOTE: placeholder name

string intToString(int value);	// 0x4051f0

class OpV3h_Mouse	// NOTE: placeholder name (0xcefa94)
{
public:
	void setCursorHidden(bool hidden);	// 0x432170
};
extern OpV3h_Mouse *opV3h_mouse;	// NOTE: placeholder name
extern bool opV3h_d1d9c4;	// NOTE: placeholder name
extern bool opV3h_d28c8a;	// NOTE: placeholder name

class OpV3h_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	int unknown715800(vector<HEntity> &out);	// NOTE: placeholder name
	void unknown774390(int type, int value);	// NOTE: placeholder name
	HEntity getEntity671();	// NOTE: placeholder name (0x463110)

	char pad[0x66c];
	HEntity unknown66c;
	char pad670[0x7f0 - 0x670];
	vector<HEntity> unknown7f0;
};
extern OpV3h_World *opV3h_world;	// NOTE: placeholder name

class OpV3h_MsgConsole	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpV3h_MsgConsole *opV3h_msgConsole;	// NOTE: placeholder name

class OpV3h_LogMsgs	// NOTE: placeholder name (0xcec0b4)
{
public:
	void scrollToEnd();	// NOTE: placeholder name
};
extern OpV3h_LogMsgs *opV3h_logMsgs;	// NOTE: placeholder name

class OpV3h_Highlighter	// NOTE: placeholder name
{
public:
	void unknown42ded0();	// NOTE: placeholder name
};

class OpV3h_Rex	// NOTE: placeholder name (0xd223f0)
{
public:
	OpV3h_Highlighter *getHighlighter();	// NOTE: placeholder name (folded getter 0x4ab670)
};
extern OpV3h_Rex opV3h_rex;	// NOTE: placeholder name

class OpV3h_Parts	// NOTE: placeholder name (CParts, 0xcec088)
{
public:
	bool unknown89d780();	// NOTE: placeholder name
};
extern OpV3h_Parts *opV3h_parts;	// NOTE: placeholder name

class OpV3h_Inventory	// NOTE: placeholder name (CInventory, 0xcec08c)
{
public:
	bool attemptEquip(HItem item, int a, int slot, int b);	// NOTE: placeholder signature (0x8a3f20)
	int unknown8a4ec0(HItem item, bool flag);	// NOTE: placeholder name
};
extern OpV3h_Inventory *opV3h_inventory;	// NOTE: placeholder name

class OpV3h_Partswap	// NOTE: placeholder name (CPartswap, 0xcec090)
{
public:
	void open(int a, int b, HItem item, bool flag);	// 0x8a7b00
};
extern OpV3h_Partswap *opV3h_partswap;	// NOTE: placeholder name

class OpV3h_Audio	// NOTE: placeholder name (0xcefaa8)
{
public:
	bool showOnce(int id, bool enabled, const string *text, bool repeat, bool flag);	// NOTE: placeholder name (0x793450)
};
extern OpV3h_Audio *opV3h_audio;	// NOTE: placeholder name

class OpV3h_Popup	// NOTE: placeholder name (OpW5_RolledValues, 0xcefb48)
{
public:
	bool say(int ID, bool force, string name);	// 0x49e250
};
extern OpV3h_Popup *opV3h_popup;	// NOTE: placeholder name

struct OpV3h_GameStateData	// NOTE: placeholder name
{
	int unknown46ed20();	// NOTE: placeholder name (folded getter)
};
class OpV3h_HGameState	// NOTE: placeholder name
{
public:
	int ID;
	OpV3h_GameStateData *operator->() const;	// 0x9b7910
};
extern OpV3h_HGameState opV3h_gameState;	// NOTE: placeholder name (0xd1e888)

bool OpV3h_unknown5111e0(int id, const string &text, int a, int b, HEntity entity, HProp prop, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
void OpV3h_message7b1750(int type, int text, int a, int b, HEntity entity, HProp prop, int c);	// NOTE: placeholder name (0x7b1750)
void OpV3h_message7b1750(int type, const string &text, int a, int b, HEntity entity, HProp prop, int c);	// NOTE: placeholder name (0x7b1750)
HItem OpV3h_unknown4fd9e0(HItem item, vector<HItem> &list, bool flag);	// NOTE: placeholder name

int OpV3h_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name
struct OpQ5_U9da940;	// NOTE: placeholder name
void opV3h_insertAt(vector<HEntity> &v, int index, HEntity value);	// NOTE: placeholder name (0x9d8fc0)
void opV3h_insertAt(vector<int> &v, int index, int value);	// NOTE: placeholder name (0x9dbdc0)

class OpV3h_Map	// NOTE: placeholder name (CMap, 0xcec054)
{
public:
	bool unknown805190(Point &pos);	// NOTE: placeholder name
	bool unknown8052f0(const Point &pos);	// NOTE: placeholder name
	void unknown8069e0(Point pos, bool flag);	// NOTE: placeholder name
	void unknown806e70(const Point &pos, bool flag);	// NOTE: placeholder name
	void unknown8142d0(int a, int b);	// NOTE: placeholder name
	void unknown807e60(bool value);	// NOTE: placeholder name
	void setSelected_8278f0(int selected_);	// NOTE: placeholder name
	void unknown80ed40(bool a, HEntity e);	// NOTE: placeholder name

	bool unknown826920(HEntity player);	// NOTE: placeholder name
	void unknown826e50(HEntity player, bool flagA, bool flagB);	// NOTE: placeholder name
	void unknown827850(int direction);	// NOTE: placeholder name
	void unknown827950();	// NOTE: placeholder name
	void unknown8279c0(const Point &pos);	// NOTE: placeholder name
	void unknown827cf0();	// NOTE: placeholder name

	char pad0[0x200];
	int unknown200;
	char pad204[0x640 - 0x204];
	unsigned int unknown640;
	Point unknown644;
	char pad64c[0x680 - 0x64c];
	int unknown680;
	int unknown684;
	vector<HEntity> unknown688;
	int unknown698;
	vector<HEntity> unknown69c;
	int unknown6ac;
	char pad6b0[0x6fc - 0x6b0];
	Point unknown6fc;
	HEntity unknown704;
};

#endif
