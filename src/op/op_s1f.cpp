// op_s1f: functions in 0x472000-0x4b2000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
using namespace std;

void OpR4b_readVector9cf5e0(istream &stream, vector<int> &v);	// NOTE: placeholder name
void OpR4b_writeVector9d2130(ostream &stream, vector<int> &v);	// NOTE: placeholder name

struct OpR1h_Record	// NOTE: placeholder name (MapRecord)
{
	char pad00[0x3c];
	int type;
	char pad40;
	bool unknown41;
	char pad42[0x4c - 0x42];
	int unknown4c;
};
extern vector<OpR1h_Record*> opR1h_records;	// NOTE: placeholder name (0xd389c4)

int OpX5_minInt(int a, int b);	// 0x9cdb30 (defined in op_x5.cpp, so LTCG can prove it nothrow)
int OpX5_maxInt(int a, int b);	// 0x9cdb60

class OpR1h_StatSet	// NOTE: placeholder name
{
public:
	vector<int> a;
	vector<int> b;

	OpR1h_StatSet();	// 0x472150
	OpR1h_StatSet(istream &stream);	// 0x4721f0
	void write472280(ostream &stream);	// NOTE: placeholder name (0x472280)
	void add4722b0(unsigned int id, int value, string text);	// NOTE: placeholder name (0x4722b0)
	int get472440(unsigned int id);	// NOTE: placeholder name (0x472440)
};

void OpR1h_StatSet::add4722b0(unsigned int id, int value, string text)
{
	switch (opR1h_records[id]->type)
	{
		case 1:
		case 4:
		case 5:
			a[id] += value;
			break;
		case 2:
			a[id] = OpX5_maxInt(a[id], value);
			break;
		case 3:
			a[id] = (a[id] == 0) ? value : OpX5_minInt(a[id], value);
			break;
		case 6:
			a[id] += value;
			b[id]++;
			break;
		case 7:
			if (value >= 1)
			{
				a[id] += value;
				b[id]++;
			}
			break;
	}
}

int OpR1h_StatSet::get472440(unsigned int id)
{
	if (opR1h_records[id]->type == 6 || opR1h_records[id]->type == 7)
		return (b[id] != 0) ? a[id] / b[id] : 0;
	else
		return a[id];
}

OpR1h_StatSet::OpR1h_StatSet()
{
	int valueA = 0;
	a.assign(0x4a1u,valueA);
	int valueB = 0;
	b.assign(0x4a1u,valueB);
}

OpR1h_StatSet::OpR1h_StatSet(istream &stream)
{
	OpR4b_readVector9cf5e0(stream,a);
	OpR4b_readVector9cf5e0(stream,b);
}

void OpR1h_StatSet::write472280(ostream &stream)
{
	OpR4b_writeVector9d2130(stream,a);
	OpR4b_writeVector9d2130(stream,b);
}

struct OpR1h_Large	// NOTE: placeholder name
{
	OpR1h_Large();	// 0x4831f0
	~OpR1h_Large();	// 0x4835b0

	char pad[0x65c];
};

template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v);	// NOTE: placeholder name
template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
void OpQ1_readStringVector(istream &in, vector<string> *list);	// NOTE: placeholder name (0x4097e0)
void OpQ1_writeStringVector(ostream &out, vector<string> *list);	// NOTE: placeholder name (0x409770)

class OpR1h_Stats	// NOTE: placeholder name
{
public:
	OpR1h_StatSet *current;
	vector<OpR1h_StatSet*> stack;
	vector<vector<string> > strings;
	vector<vector<int> > ints;
	OpR1h_Large large;
	int unknown690;

	OpR1h_Stats();	// 0x472670
	~OpR1h_Stats();	// 0x472700
	void load472830(istream &stream);	// NOTE: placeholder name (0x472830)
	void reset4724e0();	// NOTE: placeholder name (0x4724e0)
	void write472780(ostream &stream);	// NOTE: placeholder name (0x472780)
};

void OpR1h_Stats::reset4724e0()
{
	delete current;
	current = new OpR1h_StatSet();
	OpQ5_clearObjects(stack);
	stack.push_back(new OpR1h_StatSet());
	strings.clear();
	vector<string> strList;
	strings.assign(0x4a1u,strList);
	ints.clear();
	vector<int> intList;
	ints.assign(0x4a1u,intList);
	unknown690 = 0;
}

OpR1h_Stats::OpR1h_Stats()
	: current	(NULL)
{
	reset4724e0();
}

OpR1h_Stats::~OpR1h_Stats()
{
}

void OpR1h_Stats::write472780(ostream &stream)
{
	current->write472280(stream);
	OpQ5_writeObjects(stream,stack);
	for (int i = 0; i < 0x4a1; i++)
		OpQ1_writeStringVector(stream,&strings[i]);
	for (int j = 0; j < 0x4a1; j++)
		OpR4b_writeVector9d2130(stream,ints[j]);
}

void OpR1h_Stats::load472830(istream &stream)
{
	delete current;
	current = new OpR1h_StatSet(stream);
	OpQ5_clearObjects(stack);
	OpQ5_readObjects(stream,stack,0);
	vector<string> strList;
	strings.assign(0x4a1u,strList);
	for (int i = 0; i < 0x4a1; i++)
		OpQ1_readStringVector(stream,&strings[i]);
	vector<int> intList;
	ints.assign(0x4a1u,intList);
	for (int j = 0; j < 0x4a1; j++)
		OpR4b_readVector9cf5e0(stream,ints[j]);
}

//==================================================================
// item record (ctor 0x48b720)
//==================================================================

class Point
{
public:
	int randomInRange_40c130();
};
extern Point opS1f_range_cf272c;	// NOTE: placeholder name (0xcf272c)
extern Point opS1f_range_cf76e0;	// NOTE: placeholder name (0xcf76e0)

class Map
{
public:
	int getTurn();	// 0x464270
};
extern Map *opS1f_world;	// NOTE: placeholder name (0xcefc4c)

class Item
{
public:
	int unknown457fb0();	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	Item *operator->() const;	// 0x9b65b0
};

struct OpR1h_TurnRecord	// NOTE: placeholder name
{
	OpR1h_TurnRecord();	// 0x48b510

	int turn;
	vector<int> a;
	vector<int> b;
	bool flag;
};

void opw8_increase(int *value, int amount, int maximum);	// NOTE: placeholder name (0x9d06d0)

class OpS1f_ItemRec	// NOTE: placeholder name
{
public:
	int unknown00;
	HItem item;
	int unknown08;
	bool unknown0c;
	int unknown10;
	int unknown14;
	int unknown18;
	vector<int> list;
	int unknown2c;
	OpR1h_TurnRecord *record;

	OpS1f_ItemRec(HItem item_);	// 0x48b720
	~OpS1f_ItemRec();	// 0x48b840
	void increase48b8c0(int amount);	// NOTE: placeholder name (0x48b8c0)
};

OpS1f_ItemRec::OpS1f_ItemRec(HItem item_)
	: unknown00	(item_->unknown457fb0())
	, item		(item_)
	, unknown08	(0)
	, unknown0c	(false)
	, unknown10	(opS1f_range_cf272c.randomInRange_40c130())
	, unknown14	(0)
	, unknown2c	(0x7a)
	, record	(new OpR1h_TurnRecord())
{
	unknown18 = opS1f_world->getTurn() + opS1f_range_cf76e0.randomInRange_40c130();
	list.assign(0x7au,0);
}

OpS1f_ItemRec::~OpS1f_ItemRec()
{
	delete record;
}

void OpS1f_ItemRec::increase48b8c0(int amount)
{
	if (unknown08 >= 1000)
		return;
	opw8_increase(&unknown08,amount,1000);
	if (unknown08 >= 1000 && !unknown0c)
	{
		unknown0c = true;
		unknown08 = 1000;
	}
}
