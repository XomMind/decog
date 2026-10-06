// op_r1h: functions in 0x4729d0-0x490000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
#include <ostream>
using namespace std;

class Entity
{
public:
	const string &getNameAt0c();	// NOTE: placeholder name (folded getter 0x416f40)
};

class HEntity
{
public:
	int ID;
	Entity *operator->() const;	// 0x9b6570
	bool operator==(HEntity other) const;	// 0x9b6620
};

class HProp
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
	void save(ostream &stream);	// NOTE: placeholder name (0x9cfa90)
	void load(istream &stream);	// NOTE: placeholder name (0x9cfaf0)
};

void OpQ1_readString(istream &in, string *text);	// NOTE: placeholder name (0x4096f0)
void OpQ1_writeString(ostream &out, string text);	// NOTE: placeholder name (0x409650)
void OpQ1_readStringVectorList(istream &in, vector<vector<string> > *lists);	// NOTE: placeholder name (0x4098f0)
template <class T> void deleteVector(vector<T*> &v) throw();	// NOTE: placeholder name (0x9d21f0 for Console)
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0
class Console;

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

class OpR1h_StatSet	// NOTE: placeholder name
{
public:
	vector<int> a;
	vector<int> b;

	void add4722b0(unsigned int id, int value, string text);	// NOTE: placeholder name (0x4722b0)
};

bool opR1h_contains9d3fe0(vector<string> &values, string value);	// NOTE: placeholder name (0x9d3fe0)
bool opR1h_contains9db330(vector<int> &values, int value);	// NOTE: placeholder name (0x9db330)

class OpR1h_Unknown_cf45d8	// NOTE: placeholder name
{
public:
	void unknown77e900(int amount, int flag);	// NOTE: placeholder name
	unsigned char unknown46dd90();	// NOTE: placeholder name
	unsigned char unknown77ed10();	// NOTE: placeholder name
};
extern OpR1h_Unknown_cf45d8 opR1h_unknown_cf45d8;	// NOTE: placeholder name
extern const float opR1h_half_ba7ab0;	// NOTE: placeholder name (0.5f)
extern int opR1h_unknown_cf462c;	// NOTE: placeholder name
extern int opR1h_unknown_cf4b38;	// NOTE: placeholder name

class OpR1h_GM;
class OpR1h_Stats	// NOTE: placeholder name
{
public:
	OpR1h_StatSet *current;
	vector<OpR1h_StatSet*> stack;
	vector<vector<string> > strings;
	vector<vector<int> > ints;

	void update472db0();	// NOTE: placeholder name (0x472db0)
	void add472b90(unsigned int id, int value);	// NOTE: placeholder name (0x472b90)
	bool add4729d0(unsigned int id, int value, string text, int extra);	// NOTE: placeholder name (0x4729d0)
};

bool OpR1h_Stats::add4729d0(unsigned int id, int value, string text, int extra)
{
	switch (opR1h_records[id]->type)
	{
		case 4:
			if (opR1h_contains9d3fe0(strings[id], text))
				return false;
			strings[id].push_back(text);
			break;
		case 5:
			if (opR1h_contains9db330(ints[id], extra))
				return false;
			ints[id].push_back(extra);
			break;
	}
	current->add4722b0(id, value, string(""));
	if (opR1h_records[id]->unknown41)
		stack.back()->add4722b0(id, value, string(""));
	return true;
}

void OpR1h_Stats::add472b90(unsigned int id, int value)
{
	if (opR1h_records[id]->type == 2 && current->a[id] != 0)
		return;
	int amount = (value == -999999) ? opR1h_records[id]->unknown4c : value;
	current->a[id] += amount;
	current->a[6] += amount;
	if (opR1h_unknown_cf462c == 5 && opR1h_unknown_cf4b38 == 0x1c)
		opR1h_unknown_cf45d8.unknown77e900((int)(amount * opR1h_half_ba7ab0), 0);
}

struct OpQ5_U9e2ce0
{
	int value;	// NOTE: placeholder name
};
template <class T> void OpQ5_moveElement(vector<T> &v, unsigned int from, unsigned int to);	// NOTE: placeholder name (defined in op_q5_ser4)

class OpR1h_Sorter	// NOTE: placeholder name
{
public:
	void sort472cc0(vector<OpQ5_U9e2ce0> &v);	// NOTE: placeholder name (0x472cc0)
};

void OpR1h_Sorter::sort472cc0(vector<OpQ5_U9e2ce0> &v)
{
	for (unsigned int i = 1; i < v.size(); i++)
	{
		if (v[i].value < v[i - 1].value)
		{
			if (v[i].value < v[0].value)
			{
				OpQ5_moveElement(v, i, 0);
			}
			else
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (v[i].value >= v[j].value)
					{
						OpQ5_moveElement(v, i, j + 1);
						break;
					}
				}
			}
		}
	}
}

class OpR1h_GM	// NOTE: placeholder name
{
public:
	unsigned int unknown470aa0(bool keep);	// NOTE: placeholder name
};
extern OpR1h_GM *opR1h_gm;	// NOTE: placeholder name (0xcefaa8)

struct OpR1h_LocationInfo	// NOTE: placeholder name
{
	char pad00[8];
	int unknown08;
};

class OpR1h_HLocation	// NOTE: placeholder name
{
public:
	OpR1h_LocationInfo *operator->();	// 0x9b7910
};
extern OpR1h_HLocation opR1h_location;	// NOTE: placeholder name (0xd1e888)

struct OpR1h_Possession	// NOTE: placeholder name
{
	~OpR1h_Possession();	// NOTE: placeholder name
	int pad[13];
};
extern OpR1h_Possession *opR1h_possession;	// NOTE: placeholder name (0xcf4700)

extern unsigned int opR1h_playTime;	// NOTE: placeholder name (0xd2574c)
extern int opR1h_unknown_d257e0;	// NOTE: placeholder name
extern vector<int> opR1h_unknown_d25750;	// NOTE: placeholder name

void OpR1h_Stats::update472db0()
{
	opR1h_playTime += opR1h_gm->unknown470aa0(true) / 60;
	if (!opR1h_unknown_cf45d8.unknown46dd90())
	{
		if (opR1h_unknown_cf4b38 <= 9)
		{
			opR1h_unknown_d257e0 = 0;
			opR1h_unknown_d25750[opR1h_unknown_cf4b38]++;
		}
		else
		{
			opR1h_unknown_d257e0 = opR1h_location->unknown08;
		}
	}
	if (opR1h_possession != NULL)
	{
		if (!opR1h_unknown_cf45d8.unknown77ed10())
			delete opR1h_possession;
		opR1h_possession = NULL;
	}
}

//==================================================================
// large record (ctor 0x4831f0, dtor 0x4835b0)
//==================================================================

struct OpR1h_ElemB	// NOTE: placeholder name (element of the vectors destroyed by 0x9b8b60)
{
	char pad[4];
	~OpR1h_ElemB();
};

struct OpR1h_ElemC	// NOTE: placeholder name (element of the vector destroyed by 0x9b9030)
{
	char pad[4];
	~OpR1h_ElemC();
};

struct OpR1h_Pair8	// NOTE: placeholder name
{
	OpR1h_Pair8() throw();	// 0x453b40
	int a;
	int b;
};

struct OpR1h_Pair8b	// NOTE: placeholder name
{
	OpR1h_Pair8b() throw();	// 0x46c9f0
	int a;
	int b;
};

class OpR1h_Grid	// NOTE: placeholder name
{
public:
	OpR1h_Grid() throw();	// 0x9d2670
	~OpR1h_Grid() throw();	// 0x9cec20

	int data[3];
};

struct OpR1h_Sub	// NOTE: placeholder name
{
	OpR1h_Sub();	// 0x483b40
	~OpR1h_Sub();	// 0x483be0

	OpR1h_Pair8	m0;
	OpR1h_Pair8	m8;
	OpR1h_Pair8	m10;
	char			pad18[0x24];
	OpR1h_Pair8b	m3c;
	vector<unsigned int>	m44;
	vector<unsigned int>	m54;
	vector<char>	m64;
	vector<OpR1h_ElemB>	m74;
	vector<OpR1h_ElemB>	m84;
	char			pad94[0x8];
	vector<string>	m9c;
	vector<unsigned int>	mac;
	OpR1h_Grid	mbc;
	char			padc8[0x4];
};

struct OpR1h_Small	// NOTE: placeholder name
{
	OpR1h_Small();	// 0x483ac0
	~OpR1h_Small();	// 0x483ca0

	char			pad0[0x4];
	string	m4;
	char			pad20[0x4];
	vector<unsigned int>	m24;
	vector<unsigned int>	m34;
	vector<unsigned int>	m44;
	vector<unsigned int>	m54;
};

struct OpR1h_Large	// NOTE: placeholder name
{
	OpR1h_Large();	// 0x4831f0
	~OpR1h_Large();	// 0x4835b0

	char			pad0[0x8];
	string	m8;
	string	m24;
	string	m40;
	string	m5c;
	string	m78;
	string	m94;
	string	mb0;
	vector<unsigned int>	mcc;
	char			paddc[0x4];
	OpR1h_Sub	me0;
	vector<char>	m1ac;
	vector<OpR1h_ElemB>	m1bc;
	vector<unsigned int>	m1cc;
	vector<string>	m1dc;
	vector<unsigned int>	m1ec;
	char			pad1fc[0x4];
	vector<string>	m200;
	vector<string>	m210;
	vector<string>	m220;
	vector<unsigned int>	m230;
	vector<string>	m240;
	char			pad250[0x4];
	vector<unsigned int>	m254;
	vector<string>	m264;
	vector<unsigned int>	m274;
	vector<unsigned int>	m284;
	vector<OpR1h_ElemB>	m294;
	vector<string>	m2a4;
	vector<OpR1h_ElemC>	m2b4;
	vector<unsigned int>	m2c4;
	vector<unsigned int>	m2d4;
	vector<string>	m2e4;
	vector<string>	m2f4;
	vector<string>	m304;
	vector<unsigned int>	m314;
	vector<unsigned int>	m324;
	vector<string>	m334;
	vector<unsigned int>	m344;
	vector<unsigned int>	m354;
	vector<string>	m364;
	vector<unsigned int>	m374;
	vector<unsigned int>	m384;
	vector<unsigned int>	m394;
	vector<unsigned int>	m3a4;
	vector<string>	m3b4;
	vector<unsigned int>	m3c4;
	vector<unsigned int>	m3d4;
	vector<unsigned int>	m3e4;
	vector<unsigned int>	m3f4;
	vector<string>	m404;
	vector<unsigned int>	m414;
	vector<unsigned int>	m424;
	vector<OpR1h_ElemB>	m434;
	vector<string>	m444;
	vector<string>	m454;
	vector<string>	m464;
	vector<string>	m474;
	vector<unsigned int>	m484;
	vector<string>	m494;
	vector<unsigned int>	m4a4;
	vector<unsigned int>	m4b4;
	string	m4c4;
	char			pad4e0[0xc];
	string	m4ec;
	string	m508;
	char			pad524[0x8];
	string	m52c;
	char			pad548[0x18];
	vector<unsigned int>	m560;
	char			pad570[0x24];
	string	m594;
	char			pad5b0[0x10];
	string	m5c0;
	string	m5dc;
	char			pad5f8[0x4];
	string	m5fc;
	char			pad618[0x20];
	string	m638;
};

OpR1h_Sub::OpR1h_Sub()
{
}

OpR1h_Small::OpR1h_Small()
{
}

OpR1h_Large::OpR1h_Large()
{
}

OpR1h_Sub::~OpR1h_Sub()
{
}

OpR1h_Small::~OpR1h_Small()
{
}

OpR1h_Large::~OpR1h_Large()
{
}

//==================================================================
// per-turn record (ctor 0x48b510)
//==================================================================

template <class T> void readBinary(istream &stream, T *value)	// NOTE: placeholder name
{
	stream.read((char*)value,sizeof(T));
}

template <class T> void writeBinary(ostream &stream, T *value)	// NOTE: placeholder name
{
	stream.write((char*)value,sizeof(T));
}

struct OpR1h_Cell	// NOTE: placeholder name
{
	int value;
};

void opR1h_readVector9cf5e0(istream &stream, vector<OpR1h_Cell> &v);	// NOTE: placeholder name
void opR1h_writeVector9d2130(ostream &stream, vector<OpR1h_Cell> &v);	// NOTE: placeholder name

struct OpR1h_Range	// NOTE: placeholder name
{
	int randomInRange_40c130();	// NOTE: placeholder name
};

struct OpR1h_RangeOwner	// NOTE: placeholder name
{
	char pad00[0x28];
	OpR1h_Range range;
};
extern vector<OpR1h_RangeOwner*> opR1h_rangeOwners;	// NOTE: placeholder name (0xd25860)

class OpR1h_Map	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	int getTurn();	// 0x464270
};
extern OpR1h_Map *opR1h_world;	// NOTE: placeholder name (0xcefc4c)

struct OpR1h_TurnRecord	// NOTE: placeholder name
{
	OpR1h_TurnRecord();	// 0x48b510
	OpR1h_TurnRecord(istream &stream);	// 0x48b610
	void write(ostream &stream);	// NOTE: placeholder name (0x48b6c0)

	int turn;
	vector<OpR1h_Cell> a;
	vector<OpR1h_Cell> b;
	bool flag;
};

OpR1h_TurnRecord::OpR1h_TurnRecord()
{
	turn = opR1h_world->getTurn();
	unsigned int i;
	OpR1h_Cell fillB = {0};
	a.assign(53,fillB);
	OpR1h_Cell fillA = {0};
	b.assign(53,fillA);
	for (i = 0; i < opR1h_rangeOwners.size(); i++)
		b[i].value = opR1h_rangeOwners[i]->range.randomInRange_40c130();
	flag = false;
}

OpR1h_TurnRecord::OpR1h_TurnRecord(istream &stream)
{
	readBinary(stream,&turn);
	opR1h_readVector9cf5e0(stream,a);
	opR1h_readVector9cf5e0(stream,b);
	readBinary(stream,&flag);
}

void OpR1h_TurnRecord::write(ostream &stream)
{
	writeBinary(stream,&turn);
	opR1h_writeVector9d2130(stream,a);
	opR1h_writeVector9d2130(stream,b);
	writeBinary(stream,&flag);
}

//==================================================================
// small records (0x48bcd0-0x48bfd0)
//==================================================================

struct OpR1h_EntityName	// NOTE: placeholder name
{
	OpR1h_EntityName(HEntity entity_, int value_);	// 0x48bcd0

	HEntity entity;
	string name;
	int value;
};

OpR1h_EntityName::OpR1h_EntityName(HEntity entity_, int value_)
	: entity	(entity_)
	, name	(entity_->getNameAt0c())
	, value	(value_)
{
}

struct OpR1h_PropName	// NOTE: placeholder name
{
	OpR1h_PropName(istream &stream);	// 0x48bd10
	void write(ostream &stream);	// NOTE: placeholder name (0x48bda0)

	HProp prop;
	string name;
	int value;
};

OpR1h_PropName::OpR1h_PropName(istream &stream)
{
	OpQ1_readString(stream,&name);
	readBinary(stream,&value);
}

void OpR1h_PropName::write(ostream &stream)
{
	OpQ1_writeString(stream,name);
	writeBinary(stream,&value);
}

struct OpR1h_Lists	// NOTE: placeholder name
{
	OpR1h_Lists(istream &stream);	// 0x48bdf0

	int id;
	string name;
	vector<OpR1h_Cell> a;
	vector<OpR1h_Cell> b;
	vector<vector<string> > c;
};

OpR1h_Lists::OpR1h_Lists(istream &stream)
{
	readBinary(stream,&id);
	OpQ1_readString(stream,&name);
	opR1h_readVector9cf5e0(stream,a);
	opR1h_readVector9cf5e0(stream,b);
	OpQ1_readStringVectorList(stream,&c);
}

struct OpR1h_IntGrid	// NOTE: placeholder name
{
	int width;
	int height;
	int *cells;

	void freeCells() throw();	// NOTE: placeholder name (0x9cec20)
};

struct OpR1h_Consoles	// NOTE: placeholder name
{
	~OpR1h_Consoles();	// 0x48bed0

	vector<unsigned int> a;
	vector<unsigned int> b;
	OpR1h_IntGrid grid;
};

OpR1h_Consoles::~OpR1h_Consoles()
{
	deleteVector((vector<Console*>&)a);
	deleteVector((vector<Console*>&)b);
	grid.freeCells();
}

struct OpR1h_EntityLists	// NOTE: placeholder name
{
	bool take48bf50(HEntity entity);	// NOTE: placeholder name
	bool take48bfd0(HEntity entity);	// NOTE: placeholder name

	vector<HEntity*> a;
	vector<HEntity*> b;
};

bool OpR1h_EntityLists::take48bf50(HEntity entity)
{
	for (unsigned int i = 0; i < a.size(); i++)
	{
		if (a[i]->operator==(entity))
		{
			b.push_back(a[i]);
			removeVectorElement(a,i);
			return true;
		}
	}
	return false;
}

bool OpR1h_EntityLists::take48bfd0(HEntity entity)
{
	for (unsigned int i = 0; i < b.size(); i++)
	{
		if (b[i]->operator==(entity))
		{
			a.push_back(b[i]);
			removeVectorElement(b,i);
			return true;
		}
	}
	return false;
}
