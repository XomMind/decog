// op_v2_d: EntityAI (0x5b0000-0x600000), Beta 17.1.
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Point;
class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	HEntity();
};

class HProp
{
public:
	int ID;
	HProp();
};

struct OpV2_LocationInfo	// NOTE: placeholder name
{
	int pad00;
	int type;	// NOTE: placeholder name
};

class OpV2_HLocation	// NOTE: placeholder name
{
public:
	int ID;
	OpV2_LocationInfo *operator->() const;	// 0x9b7910
};
extern OpV2_HLocation opv2_location;	// NOTE: placeholder name (0xd1e888)

class Map	// NOTE: partial
{
public:
	int getTurn();	// 0x464270
};
extern Map *world;	// NOTE: placeholder name (0xcefc4c)

class OpV2_Overmind	// NOTE: placeholder name (object at 0xcf6428)
{
public:
	void unknown682770(int a, int b);	// NOTE: placeholder name
};
extern OpV2_Overmind opv2_overmind;	// NOTE: placeholder name (0xcf6428)

class OpV2_ConsoleA	// NOTE: placeholder name
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpV2_ConsoleA *opv2_consoleA;	// NOTE: placeholder name (0xcec058)
class OpV2_LogMsgs	// NOTE: placeholder name
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpV2_LogMsgs *opv2_logMsgs;	// NOTE: placeholder name (0xcec0b4)

class OpV2_MessageLog	// NOTE: placeholder name (object at 0xcf1080)
{
public:
	void unknown451400(int value);	// NOTE: placeholder name
};
extern OpV2_MessageLog opv2_messageLog;	// NOTE: placeholder name (0xcf1080)

void opv2_unknown4541b0(int a, int b, int c);	// NOTE: placeholder name
bool opv2_unknown5111e0(int id, const string *a, const string *b, int c, HEntity d, HProp e, const Point *f, int g);	// NOTE: placeholder name (0x5111e0)
void opv2_unknown5141b0(int id, int a, int b, int c, HProp d, int e);	// NOTE: placeholder name (0x5141b0)

class EntityAI
{
public:
	HEntity self;						// +0
	int state;							// +4, NOTE: placeholder name
	char pad08[0x10c - 0x08];
	int unknown10c;						// NOTE: placeholder name

	void unknown5ba3e0();				// NOTE: placeholder name
};

void EntityAI::unknown5ba3e0()
{
	unknown10c = world->getTurn();
	opv2_overmind.unknown682770(0x19,0);
	do
	{
		if (opv2_unknown5111e0(0x23a,NULL,NULL,0,self,HProp(),NULL,0))
			opv2_consoleA->unknown8758d0(true);
		opv2_logMsgs->scrollToEnd();
	} while (0);
	switch (opv2_location->type)
	{
	case 10:
		do
		{
			opv2_messageLog.unknown451400(1);
			if (0)
				opv2_unknown4541b0(-1,0,0);
			do
			{
				if (opv2_unknown5111e0(0x324,&string("ALERT: Unidentified potential threat approaching Factory."),0,0,HEntity(),HProp(),0,0))
					opv2_consoleA->unknown8758d0(true);
				opv2_logMsgs->scrollToEnd();
			} while (0);
			opv2_logMsgs->scrollToEnd();
		} while (0);
		break;
	default:
		do
		{
			opv2_messageLog.unknown451400(1);
			if (0)
				opv2_unknown4541b0(-1,0,0);
			do
			{
				if (opv2_unknown5111e0(0x324,&string("ALERT: Unidentified potential threat approaching Complex 0b10."),0,0,HEntity(),HProp(),0,0))
					opv2_consoleA->unknown8758d0(true);
				opv2_logMsgs->scrollToEnd();
			} while (0);
			opv2_logMsgs->scrollToEnd();
		} while (0);
		break;
	}
	do { opv2_unknown5141b0(0xf2,0,0,0,HProp(),0); } while (0);
}
