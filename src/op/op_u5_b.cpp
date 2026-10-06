// op_u5_b: assorted functions in 0x770000-0x7ea000
#include <string>
#include <vector>
using namespace std;

class HEntity
{
public:
	int ID;
};

class OpU5_VRec	// NOTE: placeholder name
{
public:
	virtual void unknown0();
	virtual void unknown4();
	virtual bool isTemporary();	// NOTE: placeholder name
};

class OpU5_HVRec	// NOTE: placeholder name
{
public:
	int ID;
	OpU5_HVRec();
	OpU5_VRec *operator->() const;	// 0x9b64d0
};

struct OpS8a_VRec1;
template <class T> struct OpS8a_Pool	// NOTE: placeholder name
{
	void remove(HEntity h, bool deleteItem);
};
extern OpS8a_Pool<OpS8a_VRec1> opU5_pool;	// NOTE: placeholder name (0xd20404)

class OpU5_MapView	// NOTE: placeholder name
{
public:
	void unknown49ad30();	// NOTE: placeholder name
};
extern OpU5_MapView *opU5_mapView;	// NOTE: placeholder name (0xcec054)

class OpU5_Level	// NOTE: placeholder name
{
public:
	char pad0[0xa30];
	vector<OpU5_HVRec> records;	// +0xa30
	OpU5_HVRec addRecord(OpU5_HVRec h);	// NOTE: placeholder name (0x777a20)
};

OpU5_HVRec OpU5_Level::addRecord(OpU5_HVRec h)
{
	if (h->isTemporary())
	{
		opU5_pool.remove(*(HEntity *)&h,true);
		return OpU5_HVRec();
	}
	else
	{
		records.push_back(h);
		opU5_mapView->unknown49ad30();
		return h;
	}
}

class OpU5_Group	// NOTE: placeholder name
{
public:
	int unknown9b4350();	// NOTE: placeholder name (folded getter)
};

class OpU5_HGroup	// NOTE: placeholder name
{
public:
	int ID;
	OpU5_HGroup();
	OpU5_Group *operator->() const;	// 0x9b7250
};

class OpU5_Entity	// NOTE: placeholder name
{
public:
	int getNestedField();		// NOTE: placeholder name (0x457820)
	string *getNameAt0c();		// NOTE: placeholder name (0x416f40)
	OpU5_HGroup getGroup();		// 0x45a3f0
	int unknown490840();		// NOTE: placeholder name
};

class OpU5_HEntity	// NOTE: placeholder name
{
public:
	int ID;
	OpU5_Entity *operator->() const;	// 0x9b6570
};

class OpU5_Options	// NOTE: placeholder name
{
public:
	int unknown46f530();	// NOTE: placeholder name
};
extern OpU5_Options opU5_options;	// NOTE: placeholder name (0xd1e860)
extern int opU5_serial;				// NOTE: placeholder name (0xcf46fc)

class OpU5_EntityEntry	// NOTE: placeholder name
{
public:
	int type;
	int serial;
	string name;
	int groupType;
	int value;
	int unknown2c;
	int option;

	OpU5_EntityEntry(OpU5_HEntity entity);	// NOTE: placeholder name (0x7786b0)
};

OpU5_EntityEntry::OpU5_EntityEntry(OpU5_HEntity entity)
{
	type = entity->getNestedField();
	serial = opU5_serial++;
	name = *entity->getNameAt0c();
	groupType = entity->getGroup()->unknown9b4350();
	value = entity->unknown490840();
	unknown2c = 0;
	option = opU5_options.unknown46f530();
}

struct OpU5_Rec	// NOTE: placeholder name
{
	char pad0[0x2c];
	int score;	// +0x2c
};

template <class T> void OpQ5_deleteBack(vector<T*> &v);	// NOTE: placeholder name (0x9df2e0)
void opU5_insertAt(vector<OpU5_Rec*> &v, int index, OpU5_Rec *value);	// NOTE: placeholder name (0x9dbdc0)
bool opU5_contains(vector<OpU5_Rec*> &v, OpU5_Rec *value);	// NOTE: placeholder name (0x9db330)

class OpU5_Board	// NOTE: placeholder name
{
public:
	char pad0[0x11c];
	int amount;				// +0x11c
	char pad120[8];
	OpU5_Rec *current;		// +0x128
	char pad12c[0x608 - 0x12c];
	vector<OpU5_Rec*> records;	// +0x608

	int addCapped(int delta);	// NOTE: placeholder name (0x77eca0)
	bool addRecord();		// NOTE: placeholder name (0x77ed10)
};

int OpU5_Board::addCapped(int delta)
{
	int cap = 500;
	if (amount + delta <= cap)
	{
		amount += delta;
		return 0;
	}
	delta = amount + delta - cap;
	amount = cap;
	return delta;
}

bool OpU5_Board::addRecord()
{
	if (current->score == 0)
		return false;
	if (records.empty())
	{
		records.push_back(current);
		return true;
	}
	else
	{
		if (current->score <= records.back()->score)
		{
			if (records.size() < 5)
				records.push_back(current);
		}
		else
		{
			for (unsigned int i = 0; i < records.size(); i++)
			{
				if (current->score > records[i]->score)
				{
					opU5_insertAt(records,i,current);
					break;
				}
			}
			if (records.size() > 5)
				OpQ5_deleteBack(records);
		}
		return opU5_contains(records,current);
	}
}
