// op_u5_s1: functions in 0x77f260-0x789ac0 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
using namespace std;

template <class T> void writeBinary(ostream &stream, T *value);	// NOTE: placeholder name
template <class T> void OpQ5_writeElements(ostream &stream, vector<T> &v);	// NOTE: placeholder name
template <class T> void OpS8a_writeRawVector(ostream &stream, vector<T> &v);	// NOTE: placeholder name (0x9d2130)

struct OpQ5_U9d9600
{
	int pad;
	void write(ostream &stream);
};

class HProp
{
	int	ID;
public:
	HProp() throw();
	void unknown9cfa90(ostream &stream);	// NOTE: placeholder name
};

class Entity;
class HEntity
{
	int	ID;
public:
	HEntity() throw();
	Entity *operator->() const throw();	// 0x9b6570
};

bool showMessage(int type, const string &text, int a, int b, HEntity entity, HProp prop, int c, int d);	// 0x5111e0

class OpU5s2_Messages	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(int flag);	// NOTE: placeholder name
};

class OpU5s2_LogMsgs	// NOTE: placeholder name (CLogMsgs)
{
public:
	void scrollToEnd();	// 0x7b4f10
};

class OpU5s1_GM	// NOTE: placeholder name (object at 0xcefaa8)
{
public:
	void add470c00(int value);	// NOTE: placeholder name (0x470c00)
	bool unknown793450(int id, bool enabled, const string *text, bool repeat, bool flag);	// NOTE: placeholder name (0x793450)
};

class Item;
class HItem
{
	int	ID;
public:
	Item *operator->() const throw();	// 0x9b65b0
};

class HEntity;
class Item
{
public:
	int getWidth();	// NOTE: placeholder name (0x9fcd80)
	int getNestedField();	// NOTE: placeholder name (0x457820)
	int unknown4578a0();	// NOTE: placeholder name
	int unknown457f90();	// NOTE: placeholder name
	HItem unknown45a260();	// NOTE: placeholder name (handle)
	HEntity unknown457b50();	// NOTE: placeholder name (owner)
	void unknown44eb00(HEntity owner);	// NOTE: placeholder name
	void unknown44fc40(int value);	// NOTE: placeholder name
};

class HItemList : public vector<HItem>	// NOTE: placeholder layout
{
};

class EntityRecord
{
public:
	int unknown9b4350() throw();	// NOTE: placeholder name
};

class Entity
{
public:
	void unknown5dfbd0(HItem item);	// NOTE: placeholder name
	int getFaction();	// 0x45a2c0
	EntityRecord *getRecord() throw();	// NOTE: placeholder name (0x45b590)
	int getWidth();	// NOTE: placeholder name (0x9fcd80)
	HItemList *getInventoryList();	// 0x45ab00
};

class Map	// NOTE: partial
{
public:
	HEntity getPlayer() throw();	// 0x4630f0
};
extern Map *opu5_world;	// NOTE: placeholder name (0xcefc4c)

string intToString(int value);	// 0x4051f0
void opR4p_unknown5141b0(int id, const string *a, int b, int c, HProp e, int d);	// NOTE: placeholder name (0x5141b0)

struct OpU5_StatSet	// NOTE: placeholder name
{
	vector<int> a;
};

class OpR1h_Stats	// NOTE: placeholder name
{
public:
	OpU5_StatSet *current;
	int unknown472c70(int id);	// NOTE: placeholder name (0x472c70)
	bool add4729d0(unsigned int id, int value, string text, int extra) throw();	// NOTE: placeholder name (0x4729d0)
};
extern OpR1h_Stats opu5_stats;	// NOTE: placeholder name (0xd2c658)

class DiscordWebhook
{
public:
	void addComment(string comment);
};

class OpU5s1_Tally	// NOTE: placeholder name (0xcf6888)
{
public:
	void unknown6998a0(unsigned int index, int amount, bool set);	// NOTE: placeholder name
};
extern OpU5s1_Tally opu5_tally;	// NOTE: placeholder name (0xcf6888)

class OpQ3_Location	// NOTE: placeholder name
{
public:
	int pad0;
	int depth;
};

class OpQ3_HLocation	// NOTE: placeholder name
{
public:
	OpQ3_Location *operator->() const throw();	// 0x9b7910
};
extern OpQ3_HLocation opu5_location;	// NOTE: placeholder name (0xd1e888)

struct OpU5_DepthEntry	// NOTE: placeholder name (0x34 bytes)
{
	int value;
	char pad4[0x30];
};
extern OpU5_DepthEntry opu5_depthTable[];	// NOTE: placeholder name (0xba4518)
extern int opu5_table_b982f0[];	// NOTE: placeholder name
template <class T> bool addUnique(vector<T> &v, T e);	// NOTE: placeholder name (0x9d30e0)
bool OpT8b_Fn9db000(vector<int> &v, int value);	// NOTE: placeholder name (0x9db000)

class Unknown46f1e0	// NOTE: placeholder name
{
public:
	int getTier();	// NOTE: placeholder name
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
	void unknown46f700(const string &key, const string &value);	// NOTE: placeholder name
};
extern Unknown46f1e0 opu5_gameData;	// NOTE: placeholder name (0xd1e860)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

class OpR4a_Unk7782d0	// NOTE: placeholder name
{
public:
	int ID;
	string name;
	int first;
	int second;
	int unknown28;
	int unknown2c;

	OpR4a_Unk7782d0(int ID_, int a, int b);	// 0x7782d0
};

struct OpU5_ItemType	// NOTE: placeholder name
{
	char pad0[8];
	string name;
	string text;
	char pad40[0x36];
	bool flag76;
	char pad77[0x1d];
	int value94;
};

struct OpU5_Achievement	// NOTE: placeholder name
{
	int pad0;
	string name;
	string text;
};

//==================================================================
// 0x7836e0
//==================================================================

class OpU5_Rec7836e0	// NOTE: placeholder name
{
public:
	HProp	prop0;
	int	value4;
	int	value8;
	vector<OpQ5_U9d9600>	listc;
	int	value1c;
	int	value20;
	bool	flags[12];
	vector<int>	list30;
	vector<OpQ5_U9d9600>	list40;
	vector<OpQ5_U9d9600>	list50;
	bool	flag60;
	bool	flag61;

	void write(ostream &stream);	// NOTE: placeholder name (0x7836e0)
};

void OpU5_Rec7836e0::write(ostream &stream)
{
	prop0.unknown9cfa90(stream);
	writeBinary(stream,&value4);
	writeBinary(stream,&value8);
	OpQ5_writeElements(stream,listc);
	writeBinary(stream,&value1c);
	writeBinary(stream,&value20);
	writeBinary(stream,&flags[0]);
	writeBinary(stream,&flags[1]);
	writeBinary(stream,&flags[2]);
	writeBinary(stream,&flags[3]);
	writeBinary(stream,&flags[4]);
	writeBinary(stream,&flags[5]);
	writeBinary(stream,&flags[6]);
	writeBinary(stream,&flags[7]);
	writeBinary(stream,&flags[8]);
	writeBinary(stream,&flags[9]);
	writeBinary(stream,&flags[10]);
	writeBinary(stream,&flags[11]);
	OpS8a_writeRawVector(stream,list30);
	OpQ5_writeElements(stream,list40);
	OpQ5_writeElements(stream,list50);
	writeBinary(stream,&flag60);
	writeBinary(stream,&flag61);
}

//==================================================================
// PlayerData
//==================================================================

struct OpR1g_PropPair	// NOTE: placeholder name
{
	OpR1g_PropPair(int a_, int b, HProp first_, int c, HProp second_) throw();	// 0x46d1b0
	bool isFirstEmpty();	// NOTE: placeholder name

	int		a;
	Item *	item;
	HProp	first;
	Item *	item2;
	HProp	second;
};

class OpU5s1_ItemPool	// NOTE: placeholder name (0xd2a298)
{
public:
	Item *unknown9d0bc0(HItem id);	// NOTE: placeholder name
};
extern OpU5s1_ItemPool opu5_itemPool;	// NOTE: placeholder name (0xd2a298)
extern vector<Item*> opu5_d3391c;	// NOTE: placeholder name

template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0
template <class T> void OpU5_eraseAt(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0)
template <class T> void OpU5_insertAt(vector<T> &v, int index, T value);	// NOTE: placeholder name (0x9dbdc0)
bool OpU5_fn9db000(vector<Item*> &v, Item *value);	// NOTE: placeholder name (0x9db000)
struct Unknown46d8b0	// NOTE: placeholder name
{
	bool isSlotEmpty(unsigned int index);	// NOTE: placeholder name
	void clearMarkers();	// NOTE: placeholder name
	bool unknown46dd90();	// NOTE: placeholder name

	char			pad0[0x54];
	int		value54;
	char			pad58[0x11c];
	bool	flag174;
	char			pad175[0x3];
	vector<vector<OpR1g_PropPair*> >	v178;
	char			pad188[0x7c];
	vector<int>	v204;
	vector<int>	v214;
	char			pad224[0x34];
	vector<int>	v258;
	int		value268;
	char			pad26c[0x4f4];
	vector<int>	v760;
	vector<HEntity>	v770;
};

class PlayerData : public Unknown46d8b0
{
public:
	bool unknown77f260(int value);	// NOTE: placeholder name
	void unknown77fea0(bool flag);	// NOTE: placeholder name
	bool unknown77fbc0(int type);	// NOTE: placeholder name
	bool unknown77ffb0(int ID, bool announce);	// NOTE: placeholder name
	void unknown780810(HEntity e, int type, int value);	// NOTE: placeholder name
	void unknown783540();	// NOTE: placeholder name
	void unknown77f2f0(vector<Item*> &list, int *counts);	// NOTE: placeholder name
};

struct OpU5_Rec77f260	// NOTE: placeholder name
{
	int		index;
	char			pad4[0x20];
	int		type;
};

struct OpU5_Rec77f260b	// NOTE: placeholder name
{
	char			pad0[0x24];
	int		type;
};

extern OpU5_Rec77f260 *opu5_cf4700;	// NOTE: placeholder name
extern float opu5_cf46f8;	// NOTE: placeholder name
extern vector<OpU5_Rec77f260b*> opu5_d25de0;	// NOTE: placeholder name

bool PlayerData::unknown77f260(int value)
{
	return opu5_cf4700 && value > opu5_cf46f8 && (opu5_cf4700->type == 3 || opu5_cf4700->type == 4 || opu5_d25de0[opu5_cf4700->index]->type == 1 || opu5_d25de0[opu5_cf4700->index]->type == 2);
}

extern vector<vector<int>*> opu5_d2c65c;	// NOTE: placeholder name
extern vector<int> opu5_d1e88c;	// NOTE: placeholder name

void PlayerData::unknown77fea0(bool flag)
{
	if (isSlotEmpty(0xa8))
	{
		int count = 4;
		if (opu5_d1e88c.size() < (flag ? 4 : 5))
			return;
		for (unsigned int i = opu5_d1e88c.size() - (flag ? 4 : 5); i < opu5_d1e88c.size() - (flag ? 0 : 1); i++)
		{
			int value = (*opu5_d2c65c[i])[0x3c5];
			if (value == 0)
				return;
			for (int j = 0x3bd; j <= 0x3ce; j++)
			{
				if (j != 0x3c5)
				{
					if ((*opu5_d2c65c[i])[j] >= value)
						return;
				}
			}
		}
		unknown77fbc0(0xa8);
	}
}

extern vector<OpU5_Achievement*> opu5_cf09a8;	// NOTE: placeholder name
extern vector<OpR4a_Unk7782d0*> opu5_d257b0;	// NOTE: placeholder name
extern bool opu5_d28d07;	// NOTE: placeholder name
extern bool opu5_d28f67;	// NOTE: placeholder name
extern int opu5_d28f68;	// NOTE: placeholder name
extern int opu5_cf4718;	// NOTE: placeholder name
extern OpU5s1_GM *opu5_cefaa8;	// NOTE: placeholder name
extern DiscordWebhook *opu5_cefb5c;	// NOTE: placeholder name
extern OpU5s2_Messages *opu5_cec058;	// NOTE: placeholder name
extern OpU5s2_LogMsgs *opu5_cec0b4;	// NOTE: placeholder name
extern PlayerData opu5_playerData;	// NOTE: placeholder name (0xcf45d8)

bool PlayerData::unknown77fbc0(int type)
{
	if (v204[type])
		return false;
	if (opu5_playerData.unknown46dd90())
		return false;
	if (!opu5_d28d07 && (value54 || flag174))
		return false;
	v204[type] = 1;
	for (unsigned int i = 0; i < opu5_d257b0.size(); i++)
	{
		if (opu5_d257b0[i]->name == opu5_cf09a8[type]->name)
		{
			opu5_d257b0[i]->unknown2c = opu5_cf4718;
			return false;
		}
	}
	v214.push_back(type);
	opu5_d257b0.push_back(new OpR4a_Unk7782d0(type,0,0));
	bool unused = false;
	if (type != 0 || unused)
	{
		if (opu5_d28f67)
		{
			do
			{
				if (showMessage(0x326,opu5_cf09a8[type]->text,0,0,HEntity(),HProp(),0,0))
					opu5_cec058->unknown8758d0(1);
				opu5_cec0b4->scrollToEnd();
			} while (false);
		}
		if (opu5_d28f68)
			opu5_cefaa8->add470c00(type);
		opu5_cefaa8->unknown793450(0x13,opu5_d257b0.size() >= 10,NULL,false,false);
	}
	if (opu5_cefb5c)
		opu5_cefb5c->addComment("*[ACHIEVEMENT]: " + opu5_cf09a8[type]->text + "*");
	return true;
}

extern vector<OpU5_ItemType*> opu5_d2d1c4;	// NOTE: placeholder name
extern vector<int> opu5_cf4810;	// NOTE: placeholder name
extern vector<int> opu5_cf4820;	// NOTE: placeholder name

bool PlayerData::unknown77ffb0(int ID, bool announce)
{
	if (v258[ID])
		return false;
	v258[ID] = 1;
	value268++;
	switch (opu5_d2d1c4[ID]->value94)
	{
	case 1:
	case 2:
		opu5_stats.add4729d0(4,1,opu5_d2d1c4[ID]->name,-1);
	}
	if (announce)
	{
		do
		{
			if (showMessage(0xe,opu5_d2d1c4[ID]->text,0,0,opu5_world->getPlayer(),HProp(),0,0))
				opu5_cec058->unknown8758d0(1);
			opu5_cec0b4->scrollToEnd();
		} while (false);
	}
	if (opu5_d2d1c4[ID]->flag76)
	{
		HItemList *inventory = opu5_world->getPlayer()->getInventoryList();
		int found = 0;
		for (unsigned int i = 0; i < opu5_cf4810.size(); i++)
		{
			if (opu5_cf4820[i] == 0)
			{
				for (unsigned int j = 0; j < inventory->size(); j++)
				{
					if ((*inventory)[j]->getWidth() == opu5_cf4810[i])
					{
						if ((*inventory)[j]->getNestedField() == ID)
						{
							opu5_cf4820[i] = 1;
							found++;
						}
						break;
					}
				}
			}
		}
		if (found)
		{
			string text = opu5_d2d1c4[ID]->text;
			if (found > 1)
				text += " (x" + intToString(found) + ")";
			do
			{
				opR4p_unknown5141b0(0x30,&text,0,0,HProp(),0);
			} while (false);
		}
	}
	return true;
}

void PlayerData::unknown780810(HEntity e, int type, int value)
{
	opu5_stats.add4729d0(0x321,1,"",e->getWidth());
	opu5_stats.add4729d0(0x322 + (e->getRecord()->unknown9b4350() >= 6),1,"",e->getWidth());
	if (opu5_stats.current->a[0x323] == 0x32)
		unknown77fbc0(0xbd);
	if (value != -1)
		opu5_stats.add4729d0(value,1,"",-1);
	else
	{
		opu5_stats.add4729d0(0x326,1,"",-1);
		opu5_stats.add4729d0(type + 0x327,1,"",-1);
		if (opu5_table_b982f0[type])
			opu5_tally.unknown6998a0(4,opu5_table_b982f0[type] + opu5_depthTable[opu5_location->depth].value,false);
		if (isSlotEmpty(0xbe))
		{
			int count = 0;
			for (int i = 0x327; i <= 0x370; i++)
			{
				if (opu5_stats.unknown472c70(i))
					count++;
			}
			if (count >= 10)
				unknown77fbc0(0xbe);
		}
		switch (type)
		{
		case 0x18:
			if (opu5_stats.unknown472c70(0x33f) >= 5)
				unknown77fbc0(0xc0);
			break;
		case 0x22:
			if (opu5_playerData.isSlotEmpty(0xc1))
			{
				addUnique(v770,e);
				if (v770.size() == 3)
					unknown77fbc0(0xc1);
			}
			break;
		}
	}
	OpT8b_Fn9db000(v760,e->getFaction());
	if (v760.size() >= 10)
		unknown77fbc0(0xbf);
}

void PlayerData::unknown783540()
{
	bool ready = isSlotEmpty(0x14e) && stringToInt(opu5_gameData.getEntryText("scrUfdJoined0bPrime_g")) && !stringToInt(opu5_gameData.getEntryText("scrAttackedLocals_g")) && !stringToInt(opu5_gameData.getEntryText("scrOptimusDestroyed_g")) && opu5_gameData.getTier() == 5;
	if (ready)
		unknown77fbc0(0x14e);
}

void PlayerData::unknown77f2f0(vector<Item*> &list, int *counts)
{
	Item *cur = list[0];
	removeVectorElement(list,0);
	vector<OpR1g_PropPair*> &vec = v178[cur->unknown4578a0()];
	unsigned int i;
	int idx;
	unsigned int kk;
	int q;
	unsigned int ii;
	for (i = 0; i < vec.size(); i++)
	{
		if (vec[i]->item == cur)
			break;
	}
	int amount = vec[i]->a;
	for (idx = i - 1; idx >= 0; idx--)
	{
		if (vec[idx]->item == cur)
			amount--;
	}
	removeVectorElement(vec,i);
	counts[cur->unknown4578a0()]++;
	for (kk = 0; kk < vec.size(); kk++)
	{
		if (vec[kk]->item == cur)
		{
			if (vec[kk]->item2)
				OpU5_eraseAt(vec,kk);
			else
			{
				removeVectorElement(vec,kk);
				if (counts[cur->unknown4578a0()] >= 0)
				{
					OpR1g_PropPair *slot = new OpR1g_PropPair(amount,0,HProp(),0,HProp());
					OpU5_insertAt(vec,kk,slot);
				}
				else
					counts[cur->unknown4578a0()]++;
			}
		}
	}
	if (cur->unknown457f90() == 0xd4)
	{
		for (q = 0; q < 4; q++)
		{
			for (ii = 0; ii < v178[q].size(); ii++)
			{
				if (v178[q][ii]->item2 == cur)
				{
					if (v178[q][ii]->item == NULL)
					{
						removeVectorElement(v178[q],ii);
						ii--;
					}
					else
						OpU5_fn9db000(list,v178[q][ii]->item);
				}
			}
		}
	}
	cur->unknown457b50()->unknown5dfbd0(cur->unknown45a260());
	cur->unknown44eb00(HEntity());
	cur->unknown44fc40(10);
	opu5_d3391c.push_back(opu5_itemPool.unknown9d0bc0(cur->unknown45a260()));
}
