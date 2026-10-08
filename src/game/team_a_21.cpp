// team_a_21: CHack tile lookups (0x4af3e0) plus the functions exposed by the funcindex byte-table fix
//	(0x426f30, 0x5b2ca0, 0x8900d0), matched against COGMIND.exe (Beta 17.1).
// NOTE: placeholder names.
#include <string>
#include <vector>
using namespace std;

bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
extern int teamA21_tile_cebd94;	// NOTE: placeholder name
extern int teamA21_tile_cebd98;	// NOTE: placeholder name
extern int teamA21_tile_cebd9c;	// NOTE: placeholder name
extern int teamA21_tile_cebda0;	// NOTE: placeholder name
extern int teamA21_tile_cebdd0;	// NOTE: placeholder name
extern int teamA21_tile_cebda4;	// NOTE: placeholder name
extern int teamA21_tile_cebd88;	// NOTE: placeholder name
extern int teamA21_tile_cebdb0;	// NOTE: placeholder name
extern int teamA21_tile_cebd68;	// NOTE: placeholder name
extern int teamA21_tile_cebd8c;	// NOTE: placeholder name
extern int teamA21_tile_cebdbc;	// NOTE: placeholder name
extern int teamA21_tile_cebdb4;	// NOTE: placeholder name
extern int teamA21_tile_cebd6c;	// NOTE: placeholder name
extern int teamA21_tile_cebd70;	// NOTE: placeholder name
extern int teamA21_tile_cebdb8;	// NOTE: placeholder name
extern int teamA21_tile_cebda8;	// NOTE: placeholder name
extern int teamA21_tile_cebd78;	// NOTE: placeholder name
extern int teamA21_tile_cebd7c;	// NOTE: placeholder name
extern int teamA21_tile_cebd80;	// NOTE: placeholder name
extern int teamA21_tile_cebd84;	// NOTE: placeholder name
extern int teamA21_tile_cebdc0;	// NOTE: placeholder name
extern int teamA21_tile_cebdc4;	// NOTE: placeholder name
extern int teamA21_tile_cebdc8;	// NOTE: placeholder name
extern int teamA21_tile_cebdcc;	// NOTE: placeholder name
extern int teamA21_tile_cebd74;	// NOTE: placeholder name
extern int teamA21_tile_cebdd4;	// NOTE: placeholder name
extern int teamA21_tile_cebd90;	// NOTE: placeholder name
extern int teamA21_tile_cebdac;	// NOTE: placeholder name

// looks up the CHack animation/tile ids by name (0x4af3e0)
void teamA21_lookupHackTiles_4af3e0()	// NOTE: placeholder name
{
	OpU8a_lookup1("A_CHack_Detection_Low",&teamA21_tile_cebd94);
	OpU8a_lookup1("A_CHack_Detection_Medium",&teamA21_tile_cebd98);
	OpU8a_lookup1("A_CHack_Detection_High",&teamA21_tile_cebd9c);
	OpU8a_lookup1("A_CHack_Detection_Very_High",&teamA21_tile_cebda0);
	OpU8a_lookup1("CHack_Trace_EndLeft",&teamA21_tile_cebdd0);
	OpU8a_lookup1("CHack_Trace_EndRight",&teamA21_tile_cebda4);
	OpU8a_lookup1("CHack_Trace_Fgd",&teamA21_tile_cebd88);
	OpU8a_lookup1("CHack_Trace_Progress",&teamA21_tile_cebdb0);
	OpU8a_lookup1("CHack_Trace_ProgressSnd",&teamA21_tile_cebd68);
	OpU8a_lookup1("CHack_Trace_Complete",&teamA21_tile_cebd8c);
	OpU8a_lookup1("CHack_Trace_CompleteSnd",&teamA21_tile_cebdbc);
	OpU8a_lookup1("CMachineTarget_Ascii",&teamA21_tile_cebdb4);
	OpU8a_lookup1("CMachineTarget_Dark",&teamA21_tile_cebd6c);
	OpU8a_lookup1("CMachineTarget_Faded",&teamA21_tile_cebd70);
	OpU8a_lookup1("CMachineTarget_Text",&teamA21_tile_cebdb8);
	OpU8a_lookup1("CMachineTarget_Successful",&teamA21_tile_cebda8);
	OpU8a_lookup1("CMachineTarget_Chance_Red",&teamA21_tile_cebd78);
	OpU8a_lookup1("CMachineTarget_Chance_Orange",&teamA21_tile_cebd7c);
	OpU8a_lookup1("CMachineTarget_Chance_Yellow",&teamA21_tile_cebd80);
	OpU8a_lookup1("CMachineTarget_Chance_Green",&teamA21_tile_cebd84);
	OpU8a_lookup1("CShellButton_Chance_Red",&teamA21_tile_cebdc0);
	OpU8a_lookup1("CShellButton_Chance_Orange",&teamA21_tile_cebdc4);
	OpU8a_lookup1("CShellButton_Chance_Yellow",&teamA21_tile_cebdc8);
	OpU8a_lookup1("CShellButton_Chance_Green",&teamA21_tile_cebdcc);
	OpU8a_lookup1("CShellButton_Delimiter",&teamA21_tile_cebd74);
	OpU8a_lookup1("CShellButton_Key",&teamA21_tile_cebdd4);
	OpU8a_lookup1("CShellButton_Successful",&teamA21_tile_cebd90);
	OpU8a_lookup1("CShellButton_Snd",&teamA21_tile_cebdac);
}

//==================================================================
// keyboard/mouse-button input record built from an SDL event (0x426f30)
//==================================================================

struct TeamA21_SDLEvent	// NOTE: SDL 1.2 event union (0x14 bytes); only the fields read here are named
{
	unsigned char type;
	unsigned char which;
	unsigned char button;	// button.button
	unsigned char state;
	unsigned char scancode;	// key.keysym.scancode
	unsigned char pad5[3];
	int sym;	// key.keysym.sym
	int mod;
	int unicode;
};
extern bool OpS_flags_cec14c[4];	// NOTE: placeholder name (0xcec14c: shift, ctrl, alt)

struct TeamA21_KeyInput	// NOTE: placeholder name
{
	TeamA21_KeyInput(unsigned char type, TeamA21_SDLEvent event);

	int unknown00;	// NOTE: placeholder name
	string text;	// NOTE: placeholder name
	bool isKey;	// NOTE: placeholder name
	int code;	// NOTE: placeholder name
	bool shift;	// NOTE: placeholder name
	bool ctrl;	// NOTE: placeholder name
	bool alt;	// NOTE: placeholder name
	bool down;	// NOTE: placeholder name
};

TeamA21_KeyInput::TeamA21_KeyInput(unsigned char type, TeamA21_SDLEvent event)
{
	shift = OpS_flags_cec14c[0];
	ctrl = OpS_flags_cec14c[1];
	alt = OpS_flags_cec14c[2];
	switch (type)
	{
		case 5:
			code = event.button;
			isKey = false;
			down = true;
			break;
		case 6:
			code = event.button;
			isKey = false;
			down = false;
			break;
		case 2:
			code = event.sym;
			isKey = true;
			down = true;
			goto translate;
		case 3:
			code = event.sym;
			isKey = true;
			down = false;
translate:
			if (shift)
			{
				switch (code)
				{
					case '`': code = '~'; shift = false; break;
					case '1': code = '!'; shift = false; break;
					case '2': code = '@'; shift = false; break;
					case '3': code = '#'; shift = false; break;
					case '4': code = '$'; shift = false; break;
					case '5': code = '%'; shift = false; break;
					case '6': code = '^'; shift = false; break;
					case '7': code = '&'; shift = false; break;
					case '8': code = '*'; shift = false; break;
					case '9': code = '('; shift = false; break;
					case '0': code = ')'; shift = false; break;
					case '-': code = '_'; shift = false; break;
					case '=': code = '+'; shift = false; break;
					case '[': code = '{'; shift = false; break;
					case ']': code = '}'; shift = false; break;
					case ';': code = ':'; shift = false; break;
					case '\'': code = '"'; shift = false; break;
					case ',': code = '<'; shift = false; break;
					case '.': code = '>'; shift = false; break;
					case '/': code = '?'; shift = false; break;
					case '\\': code = '|'; shift = false; break;
				}
			}
			break;
	}
}

//==================================================================
// destructor exposed by the funcindex byte-table fix (0x5b2ca0)
//==================================================================

struct TeamA21_AiPlan	// NOTE: placeholder name (destructor 0x5b2ca0; only the vector members are known)
{
	~TeamA21_AiPlan();

	char pad00[0x10];
	vector<unsigned int> unknown10;	// NOTE: placeholder name
	char pad20[0x24 - 0x20];
	vector<unsigned int> unknown24;	// NOTE: placeholder name
	char pad34[0x44 - 0x34];
	vector<unsigned int> unknown44;	// NOTE: placeholder name
};

TeamA21_AiPlan::~TeamA21_AiPlan()
{
}

//==================================================================
// part-slot label exposed by the funcindex byte-table fix (0x8900d0)
//==================================================================

class TeamA21_Item	// NOTE: placeholder name (Item)
{
public:
	string getName_571db0(int a, int b);	// NOTE: placeholder name
	bool unknown457cf0();	// NOTE: placeholder name
	int unknown45a3a0();	// NOTE: placeholder name (Entity::unknown45a3a0 in the mapping)
};
class TeamA21_HItem	// NOTE: placeholder name (HItem)
{
public:
	int ID;
	bool isValid();
	TeamA21_Item *operator->() const;
};
class TeamA21_Parts	// NOTE: placeholder name (0xcec088)
{
public:
	bool getField_4a9b90();	// NOTE: placeholder name
};
extern TeamA21_Parts *teamA21_parts_cec088;	// NOTE: placeholder name
extern int teamA21_cf462c;	// NOTE: placeholder name
extern int teamA21_cf4700;	// NOTE: placeholder name
extern string teamA21_slotNames_d378d0[];	// NOTE: placeholder name

class TeamA21_PartSlot	// NOTE: placeholder name (a part-list console)
{
public:
	string getLabel_8900d0();	// NOTE: placeholder name

	char pad00[0x6c];
	TeamA21_HItem item;	// NOTE: placeholder name
	char pad70[4];
	TeamA21_HItem other;	// NOTE: placeholder name
	char pad78[4];
	int slotType;	// NOTE: placeholder name
};

string TeamA21_PartSlot::getLabel_8900d0()
{
	string text = item.isValid() ? item->getName_571db0(0,0) : (teamA21_cf462c == 11 && teamA21_cf4700 == 0 ? string("Unusable") : (teamA21_parts_cec088->getField_4a9b90() ? "Unused (" + teamA21_slotNames_d378d0[slotType] + ")" : string("Unused")));
	if (item.isValid() && item->unknown457cf0() && item->unknown45a3a0() != 0)
		text.insert(0,"*");
	if (other.isValid())
		text.insert(0,"+");
	return text;
}
