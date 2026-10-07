// team_d_28: location-type check 0x69d230 (whether the current map allows an Overmind event).
// NOTE: names are placeholders.
#include <string>
using namespace std;

struct Location28	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;
};

class HLoc28	// NOTE: placeholder name (location handle)
{
	int ID;
public:
	Location28 *operator->() const;
};
extern HLoc28 location28_d1e888;	// NOTE: placeholder name

class GameData28	// NOTE: placeholder name (0xd1e860)
{
public:
	const string &getEntryText(const string &key);	// 0x46f6d0
};
extern GameData28 gameData28_d1e860;	// NOTE: placeholder name

class Map28	// NOTE: placeholder name for the object behind the global at 0xcefc4c
{
public:
	int unknown4642d0();	// NOTE: placeholder name
};
extern Map28 *world28;	// NOTE: placeholder name (0xcefc4c)
extern int int_d1ec68;	// NOTE: placeholder name

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

bool teamb_check69d230()	// NOTE: placeholder name (as declared in team_b_11.cpp)
{
	switch (location28_d1e888->type)
	{
	case 8:
	case 21:
	case 22:
		return true;
	case 11:
		return !stringToInt(gameData28_d1e860.getEntryText("scrAttackedLocals_g")) && !stringToInt(gameData28_d1e860.getEntryText("scrCivilWar_g"));
	case 20:
		return !stringToInt(gameData28_d1e860.getEntryText("zioAttackedLocals_g"));
	case 23:
		return !stringToInt(gameData28_d1e860.getEntryText("warAttackedLocals_g")) && !stringToInt(gameData28_d1e860.getEntryText("warMaincAttacked_g"));
	case 19:
	case 29:
		return true;
	case 34:
		return int_d1ec68 && world28->unknown4642d0() >= int_d1ec68;
	}
	return false;
}
