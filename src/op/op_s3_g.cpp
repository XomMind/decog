// op_s3_g: functions in 0x68a000-0x691000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member/method names are placeholders unless named in config/.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;

	Point(int x_, int y_) throw();

	int randomInRange_40c130();	// NOTE: placeholder name
};
extern Point opS3g_range;	// NOTE: placeholder name (0xd31508)

struct OpS3g_Location	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int type;		// NOTE: placeholder name
};
class OpS3g_HLocation	// NOTE: placeholder name
{
public:
	int ID;
	OpS3g_Location *operator->() const;	// 0x9b7910
};
extern OpS3g_HLocation opS3g_location;	// NOTE: placeholder name (0xd1e888)

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	T &operator()(const Point &p);	// 0x9ced70
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity() throw();	// 0x9b6590
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	HProp() throw();	// 0x9b6590
	struct OpS3g_Prop *operator->() const;	// 0x9b64f0
};

struct CellTerrainRecord
{
	int ID;
};
extern CellTerrainRecord *opS3g_terrainCefb9c;	// NOTE: placeholder name (0xcefb9c)

class Cell
{
public:
	void unknown66a050(int terrainID, int cause, int unknown);	// NOTE: placeholder name
};
extern Array2D<Cell *> cells;	// NOTE: placeholder name (0xcfd44c)

struct OpS3g_Pos : public Point	// NOTE: placeholder name
{
	char pad8[5];
	bool unknownD;		// NOTE: placeholder name
	char padE[0x18 - 0xe];
	HProp prop;			// NOTE: placeholder name
};

bool showMessage(int type, const string &text, int a, int b, HEntity entity, HProp prop, int c, int d);	// 0x5111e0
void opS3g_unknown454260(OpS3g_Pos *pos, int type);	// NOTE: placeholder name (0x454260)
template <class T> void opS3g_deleteObjectAndStep(vector<T*> &v, int &index);	// NOTE: placeholder name (0x9da9f0)

class OpS3g_Messages	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(int flag);	// NOTE: placeholder name
};
extern OpS3g_Messages *opS3g_messages;	// NOTE: placeholder name (0xcec058)

class OpS3g_LogMsgs	// NOTE: placeholder name (CLogMsgs at 0xcec0b4)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpS3g_LogMsgs *opS3g_logMsgs;	// NOTE: placeholder name (0xcec0b4)

class BS	// NOTE: placeholder name (the object behind the global at 0xcefc4c)
{
public:
	vector<OpS3g_Pos*> *unknown462e10();	// NOTE: placeholder name
	int getTurn();	// 0x464270
	void opw3_unknown7297a0();	// NOTE: placeholder name
};
extern BS *world;	// NOTE: placeholder name (0xcefc4c)

class OpS3g_A	// NOTE: placeholder name
{
public:
	char pad0[0x30];
	bool unknown30;		// NOTE: placeholder name
	char pad31[3];
	int unknown34;		// NOTE: placeholder name
	char pad38[0x14];
	int unknown4c;		// NOTE: placeholder name
	char pad50[0xb0];
	bool unknown100;	// NOTE: placeholder name
	char pad101[0x37];
	int unknown138;		// NOTE: placeholder name
	int unknown13c;		// NOTE: placeholder name

	void unknown68d6d0(bool flag);	// NOTE: placeholder name
	void unknown68d920(int a);	// NOTE: placeholder name
	bool unknown68e1a0();		// NOTE: placeholder name
};

void OpS3g_A::unknown68d920(int a)
{
	if (unknown138 == 0 && opS3g_location->type == 14)
	{
		unknown138 = world->getTurn() + opS3g_range.randomInRange_40c130();
		unknown13c = a;
	}
}

bool OpS3g_A::unknown68e1a0()
{
	if (unknown100 || unknown4c || unknown34)
		return false;
	unknown100 = true;
	world->opw3_unknown7297a0();
	return true;
}

void OpS3g_A::unknown68d6d0(bool flag)
{
	if (unknown30)
	{
		unknown30 = false;
		bool found = false;
		vector<OpS3g_Pos*> *positions = world->unknown462e10();
		for (int i = 0; i < positions->size(); i++)
		{
			if ((*positions)[i]->prop.operator->())
			{
				OpS3g_Pos *pos = (*positions)[i];
				cells(*pos)->unknown66a050(opS3g_terrainCefb9c->ID,2,1);
				if (pos->unknownD)
				{
					do
					{
						if (showMessage(0x1b4,string("DSF"),0,0,HEntity(),HProp(),(int)pos,0))
							opS3g_messages->unknown8758d0(1);
						opS3g_logMsgs->scrollToEnd();
					} while (false);
				}
				opS3g_unknown454260(pos,0x83);
				opS3g_deleteObjectAndStep(*positions,i);
				found = true;
			}
		}
		if (found && flag)
		{
			do
			{
				if (showMessage(0x324,string("ALERT: All DSF locations entering lockdown mode."),0,0,HEntity(),HProp(),0,0))
					opS3g_messages->unknown8758d0(1);
				opS3g_logMsgs->scrollToEnd();
			} while (false);
		}
	}
}
