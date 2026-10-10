// team_c_52: BS::playerActionPrepare (0x773330): start-of-player-action bookkeeping: auto-pickup of special items under
//	the player, Relay Coupler [C] handling, queued temporary slot additions/removals and the UI refreshes they need
// NOTE: member/global names are placeholders; BS layout is partial
#include <string>
#include <vector>
using namespace std;

string intToString(int value);
void logWarning(string location, string message);	// NOTE: placeholder name (0x404e50)
void opR1d_4541b0(int a, int b, int c);	// NOTE: placeholder name

enum C52_Slot { C52_SLOT_0 };	// NOTE: placeholder (part slot type)
struct C52_Def { char pad0[0x24]; string f24; char pad40[0x1a0 - 0x40]; int f1a0; };	// NOTE: placeholder layout
struct C52_Item { int unknown457f90(); int getNestedField4578a0(); C52_Def *getDef(); bool unknown578830(); int getValue(); void setValue(int v); void unknown57dbe0(bool a, bool b, bool c, bool d); bool unknown457e90(); string unknown571db0(int a, int b); };	// NOTE: placeholder names
class C52_HItem { public: int ID; C52_HItem(); C52_Item *operator->() const; bool isValid() const; bool isNull() const; void resetField(); };	// NOTE: placeholder (HItem/HProp)
struct C52_Point { int x; int y; };
struct C52_Entity { C52_Point &getPosition(); int getSlotTotal(); void unknown5c94e0(int slot, C52_HItem item); int getRoomCount(int type); int *unknown45a840(); void unknown642940(C52_HItem item, bool a, bool b, bool c, bool d); };	// NOTE: placeholder names
class C52_HEntity { public: int ID; C52_HEntity(); C52_Entity *operator->() const; };	// NOTE: placeholder (HEntity)
struct C52_Cell { C52_HItem getItem(); };
struct C52_CellGrid { C52_Cell **atPoint(C52_Point &p); };
struct C52_Entry { C52_HItem getTarget(); int getField(); C52_HItem unknown4b1b30(); void unknown49ac50(); };	// NOTE: placeholder (inventory entry)
struct C52_Parts { vector<C52_Entry *> *getFieldAddress(); void open(int a); };	// NOTE: placeholder (CParts)
struct C52_Info { bool isHidden(); void unknown8b5080(); };	// NOTE: placeholder (CInfo)
struct C52_Pos { int x; int y; C52_Pos(); };
struct C52_Console { void setPos(const C52_Pos &p); };
struct C52_Console2 { void unknown8758d0(bool flag); };
struct C52_Log { void scrollToEnd(); };
struct C52_Owned { char pad0[8]; C52_HItem f8; };	// NOTE: placeholder
struct C52_MapRec;
struct C52_PlayerData { void unknown77fbc0(int type); void loadPartSlots(int a, int b); };
struct C52_Stats { bool add4729d0(unsigned int id, int value, string text, int extra); };
struct C52_Ui { void unknown965220(); };
template <class T> bool OpQ5_findByName(vector<T *> &v, const string &name, T *&result);	// NOTE: placeholder name
int OpU8b_removeAll(vector<int> &v, int value);	// NOTE: placeholder name
int OpT8b_countSlots_9db9d0(vector<C52_Slot> &v, int value);	// NOTE: placeholder name (0x9db9d0)
void OpT8a_eraseSlotAt(vector<C52_Slot> &v, unsigned int &index);	// NOTE: placeholder name (0x9d... OpT8a_eraseAt)
template <class T> void OpS8c_deleteObject(vector<T *> &v, unsigned int index);	// NOTE: placeholder name
bool c52_message5111e0(int id, const string *a, const string *b, int c, C52_HEntity entity, C52_HItem prop, int d, int e);	// NOTE: placeholder name (0x5111e0)
void c52_message5141b0(int id, const string &a, const string &b, int c, C52_HItem prop, int d);	// NOTE: placeholder name (0x5141b0)
C52_Pos unknown4b33b0();	// NOTE: placeholder name
void unknown4b3540(void *parent);	// NOTE: placeholder name

extern int c52_cf4730, c52_cf462c;	// NOTE: placeholder names below
extern C52_CellGrid c52_cfd44c;
extern vector<int> c52_rifLevels_cf4a04, c52_d01be8;
extern vector<C52_MapRec *> c52_d2d1c4;
extern C52_Console2 *c52_cec058;
extern C52_Log *c52_cec0b4;
extern C52_Stats c52_d2c658;
extern const char c52_empty_b95b16[];
extern vector<C52_HEntity> c52_d1d4c4;
extern string gameStrings_d378d0[];	// global_string_arrays.cpp
extern C52_HItem c52_d2d504;
extern C52_PlayerData c52_cf45d8;
extern bool c52_cf4d14, c52_cf4d15;
extern vector<C52_Slot> c52_d378ac;
extern C52_Parts *c52_cec088;
extern vector< vector<C52_Owned *> > c52_cf4750;
extern C52_Info *c52_cec118, *c52_cec11c, *c52_cec120;
extern void *c52_cec034;
extern C52_Console *c52_cec08c;
extern C52_Ui *c52_cec138;

struct C52_MapRec { char pad0[0x24]; string f24; };

class BS	// NOTE: placeholder layout (partial)
{
public:
	char pad0[0x658];
	int f658;
	char pad65c[0x66c - 0x65c];
	C52_HEntity f66c;

	C52_HEntity unknown71e7c0(C52_Point &p, int range, int flag);	// NOTE: placeholder name
	C52_HItem unknown6c5400(C52_MapRec *type, C52_Point &p);	// NOTE: placeholder name
	void playerActionPrepare();
};

void BS::playerActionPrepare()
{
	f658 = 1;
	if (c52_cf4730 != 0 || c52_cf462c == 2)
	{
		C52_HItem center = (*c52_cfd44c.atPoint(f66c->getPosition()))->getItem();
		if (center.isValid() && (center->unknown457f90() == 7 || center->unknown457f90() == 143))
		{
			center->unknown57dbe0(false,false,true,true);
			unknown71e7c0(f66c->getPosition(),10,0);
		}
	}
	if (c52_cf462c == 9)
	{
		C52_HItem center = (*c52_cfd44c.atPoint(f66c->getPosition()))->getItem();
		if (center.isValid() && center->getNestedField4578a0() == 3 && center->getDef()->f1a0 != 0)
		{
			center->unknown57dbe0(false,false,true,true);
			unknown71e7c0(f66c->getPosition(),10,0);
		}
	}
	if (c52_rifLevels_cf4a04[18] != 0 && (*c52_cfd44c.atPoint(f66c->getPosition()))->getItem().isValid() && (*c52_cfd44c.atPoint(f66c->getPosition()))->getItem()->unknown578830())
	{
		C52_HItem adj = (*c52_cfd44c.atPoint(f66c->getPosition()))->getItem();
		int center = adj->getValue();
		C52_Def *behaviour = adj->getDef();
		adj->unknown57dbe0(false,false,true,true);
		C52_MapRec *clean;
		if (OpQ5_findByName(c52_d2d1c4,"Relay Coupler [C]",clean))
		{
			C52_HItem col = unknown6c5400(clean,f66c->getPosition());
			col->setValue(center);
			do
			{
				if (c52_message5111e0(683,&behaviour->f24,&clean->f24,0,C52_HEntity(),C52_HItem(),0,0))
					c52_cec058->unknown8758d0(true);
				c52_cec0b4->scrollToEnd();
			} while (0);
			c52_d2c658.add4729d0(886,1,c52_empty_b95b16,-1);
		}
	}
	c52_d1d4c4.clear();
	if (!c52_d01be8.empty())
	{
		vector<int> col;
		for (unsigned int cols = 0; cols < c52_d01be8.size(); cols++)
		{
			if (f66c->getSlotTotal() >= 26)
			{
				do
				{
					if (c52_message5111e0(294,0,0,0,f66c,C52_HItem(),0,0))
						c52_cec058->unknown8758d0(true);
					c52_cec0b4->scrollToEnd();
				} while (0);
				break;
			}
			else
			{
				do
				{
					if (c52_message5111e0(293,&gameStrings_d378d0[c52_d01be8[cols]],0,0,f66c,C52_HItem(),0,0))
						c52_cec058->unknown8758d0(true);
					c52_cec0b4->scrollToEnd();
				} while (0);
				f66c->unknown5c94e0(c52_d01be8[cols],c52_d2d504);
				col.push_back(c52_d01be8[cols]);
			}
		}
		if (!col.empty())
		{
			string current = col.size() > 1 ? "slots: " : "slot: ";
			int count = 0;
			do
			{
				count++;
				if (count > 1)
					current += ", ";
				int distanceSq = col.front();
				int desc = OpU8b_removeAll(col,distanceSq);
				current += gameStrings_d378d0[distanceSq];
				if (desc > 1)
					current += " x" + intToString(desc);
			} while (!col.empty());
			for (unsigned int distances = 0; distances < col.size(); distances++)
			{
				int enemies = col[distances];
				int dy = OpU8b_removeAll(col,col[distances]);
				current += gameStrings_d378d0[enemies];
				distances -= dy;
			}
			do
			{
				c52_message5141b0(62,c52_d2d504->unknown571db0(0,0),current,0,C52_HItem(),0);
			} while (0);
			opR1d_4541b0(200,0,0);
			if (f66c->getRoomCount(3) >= 7)
				c52_cf45d8.unknown77fbc0(139);
			if (f66c->getRoomCount(0) > 0 || f66c->getRoomCount(1) > 0 || f66c->getRoomCount(3) > 0)
				c52_cf4d14 = false;
			if (f66c->getRoomCount(2) > 4)
				c52_cf4d15 = false;
		}
		c52_d01be8.clear();
		c52_d2d504.resetField();
	}
	if (!c52_d378ac.empty())
	{
		vector<C52_Slot> desc(c52_d378ac);
		vector<C52_Slot> distanceSq;
		c52_d378ac.clear();
		for (int enemies = 0; enemies < 4; enemies++)
		{
			int facing = OpT8b_countSlots_9db9d0(desc,enemies);
			if (facing != 0)
				distanceSq.insert(distanceSq.end(),facing,(C52_Slot)enemies);
		}
		vector<C52_Slot> dy;
		vector<C52_Entry *> *distances = c52_cec088->getFieldAddress();
		for (unsigned int enemies = 0; enemies < distanceSq.size(); enemies++)
		{
			for (int facing = 0; facing < 2; facing++)
			{
				for (unsigned int first = 0; first < distances->size(); first++)
				{
					if ((facing != 0 || (*distances)[first]->getTarget().isNull()) && (*distances)[first]->getField() == distanceSq[enemies] && (*distances)[first]->unknown4b1b30().isValid())
					{
						(*distances)[first]->unknown49ac50();
						if ((*distances)[first]->getTarget().isValid())
						{
							if ((*distances)[first]->getTarget()->unknown457e90())
								(*distances)[first]->getTarget()->unknown57dbe0(true,false,true,true);
							else
								f66c->unknown642940((*distances)[first]->getTarget(),true,true,false,false);
						}
						f66c->unknown45a840()[distanceSq[enemies]]--;
						do
						{
							if (c52_message5111e0(295,&gameStrings_d378d0[distanceSq[enemies]],0,0,f66c,C52_HItem(),0,0))
								c52_cec058->unknown8758d0(true);
							c52_cec0b4->scrollToEnd();
						} while (0);
						dy.push_back(distanceSq[enemies]);
						OpT8a_eraseSlotAt(distanceSq,enemies);
						if (distanceSq.empty())
							goto out;
						else
							goto next;
					}
				}
			}
next:;
		}
out:
		if (!distanceSq.empty())
		{
			logWarning("BS::playerActionPrepare()","still have " + intToString(distanceSq.size()) + " temp slots unable to remove");
			distanceSq.clear();
		}
		c52_cf45d8.loadPartSlots(0,0);
		for (unsigned int facing = 0; facing < dy.size(); facing++)
		{
			for (unsigned int first = 0; first < c52_cf4750[dy[facing]].size(); first++)
			{
				if (c52_cf4750[dy[facing]][first]->f8.isNull())
				{
					OpS8c_deleteObject(c52_cf4750[dy[facing]],first);
					break;
				}
			}
		}
		if (!c52_cec118->isHidden())
			c52_cec118->unknown8b5080();
		if (!c52_cec11c->isHidden())
			c52_cec11c->unknown8b5080();
		if (!c52_cec120->isHidden())
			c52_cec120->unknown8b5080();
		unknown4b3540(c52_cec034);
		c52_cec088->open(1);
		c52_cec08c->setPos(unknown4b33b0());
		c52_cec138->unknown965220();
	}
}
