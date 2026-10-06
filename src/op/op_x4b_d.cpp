// op_x4b: map zone message (0x6c16d0) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
};

class HEntity
{
	int ID;
public:
	HEntity();
	Entity *operator->() const;	// 0x9b6570
};

class HProp
{
	int ID;
public:
	HProp();
};

struct OpX4b_MachineInfo	// NOTE: placeholder name
{
	char pad00[4];
	int type;	// NOTE: placeholder name
	char pad08[0x25 - 8];
	bool identified;	// NOTE: placeholder name
};

class OpX4b_MachineHandle	// NOTE: placeholder name
{
public:
	int ID;
	OpX4b_MachineInfo *operator->();	// 0x9b7910
};

class OpX4b_World	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
};
extern OpX4b_World *opx4b_world;	// NOTE: placeholder name (0xcefc4c)

class OpX4b_MsgConsole	// NOTE: placeholder name (object at 0xcec058)
{
public:
	void unknown8758d0(bool flag);	// NOTE: placeholder name
};
extern OpX4b_MsgConsole *opx4b_msgConsole;	// NOTE: placeholder name (0xcec058)

class OpX4b_LogMsgs	// NOTE: placeholder name (CLogMsgs)
{
public:
	void scrollToEnd();	// 0x7b4f10
};
extern OpX4b_LogMsgs *opx4b_logMsgs;	// NOTE: placeholder name (0xcec0b4)

extern string opx4b_machineNames[];	// NOTE: placeholder name (0xcfaca0)
extern bool opx4b_table_ba6650[];	// NOTE: placeholder name (0xba6650)
extern int opx4b_difficulty;	// NOTE: placeholder name (0xcf4718)

string OpR5f_toUpper_4083a0(const string &text);	// NOTE: placeholder name
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)
string intToString(int value);
bool opx4b_logMessage(int id, const string &text, const string *b, int c, HEntity d, HProp e, const Point *at, int flag);	// NOTE: placeholder name (0x5111e0)
void opx4b_unknown5141b0(int id, const string *a, const string *b, int c, HProp d, int e);	// NOTE: placeholder name (0x5141b0)

class OpX4b_Zone	// NOTE: placeholder name
{
public:
	void unknown6c16d0(string text);	// NOTE: placeholder name

	Point pos;
	OpX4b_MachineHandle machine;
	char pad0c[0x1c - 0xc];
	int state;	// NOTE: placeholder name
};

void OpX4b_Zone::unknown6c16d0(string text)
{
	string message = text;
	if (machine->identified)
	{
		message += ": ";
		message += OpR5f_toUpper_4083a0(opx4b_machineNames[machine->type]);
	}
	if (opx4b_table_ba6650[machine->type*3 + opx4b_difficulty])
		message += " (Inaccessible)";
	else if (state == 3)
		message += " (Lockdown)";
	else if (state == 4)
		message += " (Blocked)";
	do
	{
		if (opx4b_logMessage(0x209,message,0,0,HEntity(),HProp(),0,0))
			opx4b_msgConsole->unknown8758d0(true);
		opx4b_logMsgs->scrollToEnd();
	} while (0);
	if (machine->type != 1 && text == "FOUND")
	{
		if (machine->identified)
		{
			do
			{
				opx4b_unknown5141b0(7,&opx4b_machineNames[machine->type],&intToString(OpQ1_distanceCeil_40a3f0(opx4b_world->getPlayer()->getPosition(),pos)),0,HProp(),0);
			} while (0);
		}
		else
		{
			do
			{
				opx4b_unknown5141b0(6,&intToString(OpQ1_distanceCeil_40a3f0(opx4b_world->getPlayer()->getPosition(),pos)),0,0,HProp(),0);
			} while (0);
		}
	}
}
