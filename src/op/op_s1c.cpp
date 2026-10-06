// op_s1c: functions in 0x440000-0x45b000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <istream>
using namespace std;

//==================================================================
// HttpsConnection (layout from op_y3_https.cpp)
//==================================================================

class HttpsConnection
{
public:
	virtual ~HttpsConnection();
	void closeHandles() throw();	// NOTE: placeholder name

	void *hInternet;
	void *hRequest;
	void *hConnect;
	string agent;
	string server;
	string path;
	unsigned short port;
	unsigned long flags;
	string responseHeader;
};

HttpsConnection::~HttpsConnection()
{
	closeHandles();
}

//==================================================================
// list of records (vector of pointers at the start of the object)
//==================================================================

struct OpS1c_Data	// NOTE: placeholder name
{
	int ID;
	char pad04[0x3c - 0x04];
	int type;
	char pad40[0x78 - 0x40];
	int unknown78;
	int unknown7c;
};

class C065_Rec518870	// NOTE: placeholder name
{
public:
	void init() throw();	// 0x518870
};

class C065_Rec518b30	// NOTE: placeholder name
{
public:
	void updateTurn();	// 0x518b30
};

struct OpQ5_T9d0160	// NOTE: placeholder name (record of an entity effect, 20 bytes)
{
	OpQ5_T9d0160(istream &stream);
	~OpQ5_T9d0160();
	OpQ5_T9d0160(OpS1c_Data *data_);	// NOTE: placeholder name (0x456130)
	bool isExpired();				// NOTE: placeholder name (0x4561c0)
	OpS1c_Data *getData();			// NOTE: placeholder name (0x9fcd80, folded getter)
	int getFieldC();				// NOTE: placeholder name (0x9fcd80, folded getter)

	OpS1c_Data *data;
	int field4;
	int field8;
	int fieldc;
	int field10;
};

OpQ5_T9d0160::OpQ5_T9d0160(OpS1c_Data *data_)
{
	data = data_;
	fieldc = 0;
	field10 = -999;
	((C065_Rec518870*)this)->init();
}

bool OpQ5_T9d0160::isExpired()
{
	return data->unknown78 && fieldc >= data->unknown78;
}

extern bool opS1c_table_ba62f0[];	// NOTE: placeholder name
extern bool opS1c_table_ba6380[];	// NOTE: placeholder name

template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
template <class T> void readBinary(istream &stream, T *value);	// NOTE: placeholder name
template <class T> void eraseAt(vector<T> &v, unsigned int *index);	// NOTE: placeholder name (0x9de640, steps index back)

class OpS1c_RecList	// NOTE: placeholder name
{
public:
	bool hasData(OpS1c_Data *data);		// NOTE: placeholder name (0x4563e0)
	int countDef(int ID);				// NOTE: placeholder name (0x456430)
	bool hasType(int type);				// NOTE: placeholder name (0x456490)
	OpS1c_Data *getDataOfType(int type);	// NOTE: placeholder name (0x4564e0)
	bool hasTypeFlagA();				// NOTE: placeholder name (0x456540)
	bool hasTypeFlagB();				// NOTE: placeholder name (0x4565a0)
	bool hasActiveType39();				// NOTE: placeholder name (0x456600)
	OpS1c_RecList(vector<OpS1c_Data*> list);	// NOTE: placeholder name (0x456280)
	OpS1c_RecList(istream &stream);		// NOTE: placeholder name (0x456310)
	void add(OpS1c_Data *data);			// NOTE: placeholder name (0x456660)
	void addAll(vector<OpS1c_Data*> list);	// NOTE: placeholder name (0x4566c0)
	bool removeData(OpS1c_Data *data, bool once);	// NOTE: placeholder name (0x4567f0)
	bool removeExpired();				// NOTE: placeholder name (0x456860)
	bool removeActiveType39();			// NOTE: placeholder name (0x4568c0)

	vector<OpQ5_T9d0160*> records;
	int turn;
};

bool OpS1c_RecList::hasData(OpS1c_Data *data)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->data == data)
		{
			return true;
		}
	}

	return false;
}

int OpS1c_RecList::countDef(int ID)
{
	int count = 0;
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->data->ID == ID)
		{
			count++;
		}
	}

	return count;
}

bool OpS1c_RecList::hasType(int type)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->data->type == type)
		{
			return true;
		}
	}

	return false;
}

OpS1c_Data *OpS1c_RecList::getDataOfType(int type)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->data->type == type)
		{
			return records[i]->getData();
		}
	}

	return NULL;
}

bool OpS1c_RecList::hasTypeFlagA()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (opS1c_table_ba62f0[records[i]->data->type])
		{
			return true;
		}
	}

	return false;
}

bool OpS1c_RecList::hasTypeFlagB()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (opS1c_table_ba6380[records[i]->data->type])
		{
			return true;
		}
	}

	return false;
}

bool OpS1c_RecList::hasActiveType39()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->data->type == 0x39 && records[i]->data->unknown7c)
		{
			return true;
		}
	}

	return false;
}

OpS1c_RecList::OpS1c_RecList(vector<OpS1c_Data*> list)
{
	((C065_Rec518b30*)this)->updateTurn();
	addAll(list);
}

OpS1c_RecList::OpS1c_RecList(istream &stream)
{
	OpQ5_readObjects(stream,records,0);
	readBinary(stream,&turn);
}

void OpS1c_RecList::add(OpS1c_Data *data)
{
	records.push_back(new OpQ5_T9d0160(data));
}

void OpS1c_RecList::addAll(vector<OpS1c_Data*> list)
{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		records.push_back(new OpQ5_T9d0160(list[i]));
	}
}

bool OpS1c_RecList::removeData(OpS1c_Data *data, bool once)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->data == data)
		{
			eraseAt(records,&i);
			if (once)
			{
				break;
			}
		}
	}

	return records.empty();
}

bool OpS1c_RecList::removeExpired()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->isExpired())
		{
			eraseAt(records,&i);
		}
	}

	return records.empty();
}

bool OpS1c_RecList::removeActiveType39()
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->getData()->type == 0x39 && records[i]->getFieldC() > 0)
		{
			eraseAt(records,&i);
		}
	}

	return records.empty();
}

class OpS1c_Holder	// NOTE: placeholder name
{
public:
	bool hasData(OpS1c_Data *data);	// NOTE: placeholder name (0x4560d0)

	char pad00[0xc0];
	vector<OpQ5_T9d0160*> records;
};

bool OpS1c_Holder::hasData(OpS1c_Data *data)
{
	for (unsigned int i = 0; i < records.size(); i++)
	{
		if (records[i]->data == data)
		{
			return true;
		}
	}

	return false;
}

//==================================================================
// effect triggers
//==================================================================

template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name (0x9e2c40)

class OpS1c_Inventory	// NOTE: placeholder name
{
public:
	vector<OpQ5_T9d0160*> *getRecords518c00(int type, int a, int b, int c, int d, int e, int f, int g, int h, int i);	// NOTE: placeholder name (0x518c00)
};

class BS	// NOTE: placeholder name
{
public:
	static bool turnUpdate_51da30(vector<OpQ5_T9d0160*> *records, int type, int a, int b, int c, int d, int e);	// 0x51da30
};

bool OpS1c_unknown4569a0(int type, int a, int b, int c, int d, int e, int f, OpS1c_Inventory *inventory, int g, int h, int i, int j)	// NOTE: placeholder name (0x4569a0)
{
	if (!inventory)
	{
		return false;
	}

	vector<OpQ5_T9d0160*> *records = inventory->getRecords518c00(type,a,b,c,d,e,0,f,0,0);
	if (!records)
	{
		return false;
	}

	bool result = BS::turnUpdate_51da30(records,type,g,h,i,j,0);
	OpQ5_clearObjects(*records);
	delete records;
	return result;
}

int opS1c_9cdbd0(vector<int> *v);	// NOTE: placeholder name (0x9cdbd0)

class OpS1c_Stats	// NOTE: placeholder name
{
public:
	int getTotal();	// NOTE: placeholder name (0x457160)

	char pad00[0x44 - 0x00];
	int unknown44;	// NOTE: placeholder name
	char pad48[0x4c - 0x48];
	int unknown4c;	// NOTE: placeholder name
	int unknown50;	// NOTE: placeholder name
	int unknown54;	// NOTE: placeholder name
	int unknown58;	// NOTE: placeholder name
	int unknown5c;	// NOTE: placeholder name
	int unknown60;	// NOTE: placeholder name
	int unknown64;	// NOTE: placeholder name
	int unknown68;	// NOTE: placeholder name
	char pad6c[0x94 - 0x6c];
	int unknown94;	// NOTE: placeholder name
	int unknown98;	// NOTE: placeholder name
	char pad9c[0xa0 - 0x9c];
	int unknowna0;	// NOTE: placeholder name
	int unknowna4;	// NOTE: placeholder name
	int unknowna8;	// NOTE: placeholder name
	int unknownac;	// NOTE: placeholder name
	int unknownb0;	// NOTE: placeholder name
	float unknownb4;	// NOTE: placeholder name
	int unknownb8;	// NOTE: placeholder name
	int unknownbc;	// NOTE: placeholder name
	int unknownc0;	// NOTE: placeholder name
	int unknownc4;	// NOTE: placeholder name
	char padc8[0xcc - 0xc8];
	int unknowncc;	// NOTE: placeholder name
	int unknownd0;	// NOTE: placeholder name
	char padd4[0xd8 - 0xd4];
	float unknownd8;	// NOTE: placeholder name
	int unknowndc;	// NOTE: placeholder name
	int unknowne0;	// NOTE: placeholder name
	int unknowne4;	// NOTE: placeholder name
	int unknowne8;	// NOTE: placeholder name
	char padec[0xf0 - 0xec];
	int unknownf0;	// NOTE: placeholder name
	int unknownf4;	// NOTE: placeholder name
	char padf8[0x100 - 0xf8];
	int unknown100;	// NOTE: placeholder name
	int unknown104;	// NOTE: placeholder name
	int unknown108;	// NOTE: placeholder name
	int unknown10c;	// NOTE: placeholder name
	int unknown110;	// NOTE: placeholder name
	int unknown114;	// NOTE: placeholder name
	int unknown118;	// NOTE: placeholder name
	char pad11c[0x124 - 0x11c];
	int unknown124;	// NOTE: placeholder name
	int unknown128;	// NOTE: placeholder name
	int unknown12c;	// NOTE: placeholder name
	int unknown130;	// NOTE: placeholder name
	char pad134[0x138 - 0x134];
	int unknown138;	// NOTE: placeholder name
	vector<int> unknown13c;	// NOTE: placeholder name
	int unknown14c;	// NOTE: placeholder name
	int unknown150;	// NOTE: placeholder name
	char pad154[0x15c - 0x154];
	int unknown15c;	// NOTE: placeholder name
	int unknown160;	// NOTE: placeholder name
	char pad164[0x204 - 0x164];
	int unknown204;	// NOTE: placeholder name
};

int OpS1c_Stats::getTotal()
{
	return (int)(unknown44 + unknown4c + unknown50 + unknown54 + unknown58 + unknown5c + unknown60 + unknown64 + unknown68 + unknown94 + unknown98 + unknowna0 + unknowna4 + unknowna8 + unknownac + unknownb0 + unknownb4 + unknownb8 + unknownbc + unknownc0 + unknownc4 + unknowncc + unknownd0 + unknownd8 + unknowndc + unknowne0 + unknowne4 + unknowne8 + unknownf0 + unknownf4 + unknown100 + unknown104 + unknown108 + unknown10c + unknown110 + unknown114 + unknown118 + unknown124 + unknown128 + unknown12c + unknown130 + unknown138 + opS1c_9cdbd0(&unknown13c) + unknown14c + unknown150 + unknown15c + unknown160 + unknown204);
}

//==================================================================
// unit-related values
//==================================================================

class OpS1c_Unit	// NOTE: placeholder name
{
public:
	int getValue457580(int divisor);	// NOTE: placeholder name
	int getValue4575d0(int divisor);	// NOTE: placeholder name

	char pad00[0x50];
	int unknown50;	// NOTE: placeholder name
	char pad54[0x40];
	int unknown94;	// NOTE: placeholder name
};

int OpS1c_Unit::getValue457580(int divisor)
{
	return (unknown50 / 2 + 1) * (8 + (unknown94 ? 4 : 0)) / (divisor ? divisor : 1);
}

int OpS1c_Unit::getValue4575d0(int divisor)
{
	return (3 + (unknown94 ? 2 : 0)) * unknown50 / (divisor ? divisor : 1);
}

class OpS1c_Lists	// NOTE: placeholder name
{
public:
	bool hasOnlyList24();	// NOTE: placeholder name (0x4595f0)

	char pad00[0x24];
	vector<int> list24;	// NOTE: placeholder name
	char pad34[0xf0 - 0x34];
	vector<int> listF0;	// NOTE: placeholder name
};

bool OpS1c_Lists::hasOnlyList24()
{
	return !list24.empty() && listF0.empty();
}

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
	Point(const Point &p) throw();
};

class OpS1c_Path	// NOTE: placeholder name
{
public:
	OpS1c_Path(int a_, int b_, const Point &p1, const Point &p2, const Point &p3);	// NOTE: placeholder name (0x455880)
	void init515790();	// NOTE: placeholder name

	int a;
	int b;
	Point pos1;
	Point pos2;
	Point pos3;
};

OpS1c_Path::OpS1c_Path(int a_, int b_, const Point &p1, const Point &p2, const Point &p3)
	: a		(a_)
	, b		(b_)
	, pos1	(p1)
	, pos2	(p2)
	, pos3	(p3)
{
	init515790();
}

struct HExplosive
{
	char pad[0x40];	// NOTE: placeholder layout
	~HExplosive();
};

class OpS1c_Base	// NOTE: placeholder name (dtor 0x453c00)
{
public:
	virtual ~OpS1c_Base();

	char pad04[0x30 - 0x04];
};

class OpS1c_Explosives : public OpS1c_Base	// NOTE: placeholder name
{
public:
	~OpS1c_Explosives();

	vector<HExplosive> explosives;
};

OpS1c_Explosives::~OpS1c_Explosives()
{
}

struct OpS1c_Obj;	// NOTE: placeholder name

class OpS1c_Lists2	// NOTE: placeholder name
{
public:
	~OpS1c_Lists2();	// NOTE: placeholder name (0x4596f0)

	char pad00[0x04];
	string str04;
	char pad20[0x2c - 0x20];
	string str2c;
	string str4c;
	char pad68[0xc4 - 0x68];
	vector<OpS1c_Obj*> listC4;
	vector<unsigned int> listD4;
	char padE4[0xfc - 0xe4];
	vector<unsigned int> listFC;
	char pad10c[0x148 - 0x10c];
	vector<unsigned int> list148;
	char pad158[0x160 - 0x158];
	vector<vector<OpS1c_Obj*> > list160;
	string str170;
	string str18c;
	string str1ac;
};

OpS1c_Lists2::~OpS1c_Lists2()
{
	OpQ5_clearObjects(listC4);
	for (unsigned int i = 0; i < list160.size(); i++)
	{
		OpQ5_clearObjects(list160[i]);
	}
}
