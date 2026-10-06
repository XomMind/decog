// op_v3f_a: CAudioLogs helpers in 0x7f4f50-0x7f5170 of COGMIND.exe (Beta 17.1). Names are placeholders unless stated.
#include "op_v3f.h"

class CAllies	// NOTE: partial (see op_w9.cpp)
{
public:
	bool getUnknown48f0a0();	// NOTE: placeholder name
};

class CIntel	// NOTE: partial (see op_w9.cpp)
{
public:
	bool getSelecting();	// NOTE: placeholder name (folded getter 0x48f8b0)
};

class CMapFine : public Console	// NOTE: partial (see op_w5.cpp)
{
public:
	int getBottom_49c190();	// NOTE: placeholder name
};

int minInt(int a, int b) throw();	// 0x9cdb30
int opV3F_maxInt(int a, int b) throw();	// NOTE: placeholder name (0x9cdb60)

extern int opV3F_mode;	// NOTE: placeholder name (0xcebd5c)
extern CAllies *opV3F_allies;	// NOTE: placeholder name (0xcec0c8)
extern CIntel *opV3F_intel;	// NOTE: placeholder name (0xcec0cc)
extern XConsole *opV3F_info;	// NOTE: placeholder name (0xcec11c)
extern XConsole *opV3F_cec0f8;	// NOTE: placeholder name
extern CMapFine *opV3F_fine;	// NOTE: placeholder name (0xcec058)
extern Console *opV3F_mapConsole;	// NOTE: placeholder name (0xcec054)
extern int opV3F_tileHeight;	// NOTE: placeholder name (0xcaf12c)
extern int opV3F_d28f78;	// NOTE: placeholder name
extern int opV3F_d28f80;	// NOTE: placeholder name
extern int opV3F_d28fb4;	// NOTE: placeholder name

class CAudioLog : public Console	// NOTE: partial (see op_w5.cpp)
{
public:
	int type;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	int number;	// NOTE: placeholder name
	string name;	// NOTE: placeholder name
	unsigned int endTime;	// NOTE: placeholder name
};

class CAudioLogs : public Console	// NOTE: partial (see op_w5.cpp)
{
public:
	virtual ~CAudioLogs();

	void removeLog(CAudioLog *log);	// NOTE: placeholder name
	bool unknown7f5040();	// NOTE: placeholder name
	void unknown7f4f50();	// NOTE: placeholder name

	vector<CAudioLog*> logs;	// NOTE: placeholder name
};

void CAudioLogs::unknown7f4f50()
{
	if (opV3F_mode == 2 && (opV3F_allies->getUnknown48f0a0() || opV3F_intel->getSelecting()))
		setHidden(true);
	else
	{
		bool hasLogs = logs.size() > 1;
		if (opV3F_info->isHidden() && opV3F_cec0f8->isHidden())
			setHidden(!hasLogs);
		else
			setHidden(true);
	}
	if (opV3F_mode == 2 && !isHidden())
	{
		int bottom = opV3F_fine->getBottom_49c190() + 1;
		setPos(getPos().x,bottom);
	}
}

bool CAudioLogs::unknown7f5040()
{
	int maxLogs = minInt(opV3F_d28fb4,opV3F_mapConsole->getHeight() * opV3F_tileHeight - 2 - (opV3F_mode == 2 ? opV3F_maxInt(opV3F_d28f78,opV3F_d28f80) : 0));
	if (logs.size() == maxLogs)
	{
		if (logs.back()->type == 5)
			return false;
		int oldest = logs.size() - 1;
		for (int i = logs.size() - 2; logs[i]->type != 5; i--)
		{
			if (logs[i]->endTime < logs[oldest]->endTime)
				oldest = i;
		}
		removeLog(logs[oldest]);
	}
	return true;
}
