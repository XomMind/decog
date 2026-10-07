// team_d_57: event/holiday mode selection 0x779860 (pick the active special mode and its option flags).
// NOTE: names and layouts are placeholders. The 0x14-byte mode table at 0xba7430 is declared one column per
// extern so every access sits at offset 0 of its own symbol.
#include <vector>
using namespace std;

struct ModeColumn57	// NOTE: placeholder name
{
	int value;
	int rest[4];
};
extern ModeColumn57 modeYear57_ba7430[];	// NOTE: placeholder name
extern ModeColumn57 modeMonth57_ba7434[];	// NOTE: placeholder name
extern ModeColumn57 modeDay57_ba7438[];		// NOTE: placeholder name
extern ModeColumn57 modeDays57_ba743c[];	// NOTE: placeholder name
extern ModeColumn57 modeMin57_ba7440[];		// NOTE: placeholder name

struct SavedModes57	// NOTE: placeholder name and layout (object behind 0xcec034)
{
	char	pad00[0x79];
	bool	saved;		// +0x79
	char	pad7a[0x7c - 0x7a];
	int		mode;		// +0x7c
	int		flags[12];	// +0x80
};
extern SavedModes57 *saved57_cec034;	// NOTE: placeholder name

class GameMeta57	// NOTE: placeholder name (0xd25628)
{
public:
	bool unknown7784b0();	// NOTE: placeholder name
};
extern GameMeta57 gameMeta57_d25628;	// NOTE: placeholder name

class DataLoader57	// NOTE: placeholder name (OpT5_DataLoader at 0xcefaa8)
{
public:
	void unknown792750();	// NOTE: placeholder name
};
extern DataLoader57 *loader57_cefaa8;	// NOTE: placeholder name

extern int forcedMode57_cefb40;		// NOTE: placeholder name
extern int optionMode57_cefb44;		// NOTE: placeholder name
extern bool noModes57_cefb3d;		// NOTE: placeholder name
extern int int_d25740;				// NOTE: placeholder name
extern vector<unsigned int> vec_d379ec;
extern int defaultFlags57_d28db0[];	// NOTE: placeholder name

void OpS8c_copyInts(int *src, int *dst, unsigned int count);	// NOTE: placeholder name
bool OpV4c_Fn9d3f40(int *list, unsigned int count);	// NOTE: placeholder name
void OpX5_fillInts(int *list, unsigned int count, int value);	// NOTE: placeholder name
bool opR1d_436ac0(int year, int month, int day, int days);	// NOTE: placeholder name

class Modes57	// NOTE: placeholder name
{
public:
	char	pad000[0x54];
	int		mode;		// +0x54
	char	pad058[0x144 - 0x58];
	int		flags[12];	// +0x144
	bool	anyFlag;	// +0x174

	void unknown778930();	// NOTE: placeholder name
	void unknown779860();	// NOTE: placeholder name
};

void Modes57::unknown779860()
{
	if (saved57_cec034->saved)
	{
		mode = saved57_cec034->mode;
		OpS8c_copyInts(saved57_cec034->flags,flags,12);
		anyFlag = OpV4c_Fn9d3f40(flags,12);
	}
	else
	{
		mode = 0;
		if (forcedMode57_cefb40)
			mode = forcedMode57_cefb40;
		else if (optionMode57_cefb44 && modeYear57_ba7430[optionMode57_cefb44].value != 9999)
			mode = optionMode57_cefb44;
		else if (!noModes57_cefb3d && !gameMeta57_d25628.unknown7784b0())
		{
			for (int i = 1; i < 12; i++)
			{
				if (modeYear57_ba7430[i].value != 9999 && opR1d_436ac0(modeYear57_ba7430[i].value,modeMonth57_ba7434[i].value,modeDay57_ba7438[i].value,modeDays57_ba743c[i].value) && int_d25740 >= modeMin57_ba7440[i].value)
				{
					mode = i;
					break;
				}
			}
		}
		if (mode == 7 && vec_d379ec.empty())
			loader57_cefaa8->unknown792750();
		if (0) {}	// NOTE: no code; shifts MSVC's register rotation to match the exe
		if (mode)
			OpX5_fillInts(flags,12,0);
		else
		{
			OpS8c_copyInts(defaultFlags57_d28db0,flags,12);
			if (flags[0])
			{
				flags[3] = 0;
				flags[11] = 0;
			}
			if (flags[2])
				flags[9] = 0;
			if (flags[8])
				flags[1] = 0;
		}
		anyFlag = OpV4c_Fn9d3f40(flags,12);
		saved57_cec034->mode = mode;
		OpS8c_copyInts(flags,saved57_cec034->flags,12);
		saved57_cec034->saved = true;
		unknown778930();
	}
}
