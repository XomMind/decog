// op_r3f: functions in 0x6c2000-0x6d0000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

struct Point
{
	int x;
	int y;
};

struct OpR3f_Range	// NOTE: placeholder name
{
	int randomInRange_40c130() throw();	// NOTE: placeholder name

	int min;
	int max;
};
extern OpR3f_Range opr3f_d21b3c;	// NOTE: placeholder name (0xd21b3c)
extern OpR3f_Range opr3f_d22fa0;	// NOTE: placeholder name (0xd22fa0)

class OpR3f_World	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	int getTurn() throw();	// 0x464270
};
extern OpR3f_World *opr3f_world;	// NOTE: placeholder name (0xcefc4c)

class OpR3f_Timer	// NOTE: placeholder name
{
public:
	OpR3f_Timer();	// 0x6c2110

	vector<unsigned int> values;
	int unknown10;
	int delay;
	int interval;
	int nextTurn;
	int remaining;
};

OpR3f_Timer::OpR3f_Timer()
{
	unknown10 = 0;
	delay = opr3f_d21b3c.randomInRange_40c130();
	interval = opr3f_d22fa0.randomInRange_40c130();
	nextTurn = opr3f_world->getTurn() + interval;
	remaining = interval;
}

struct OpR3f_PropData	// NOTE: placeholder name
{
	char pad00[0x28];
	int unknown28;
};

class Prop
{
public:
	int unknown457b10();	// NOTE: placeholder name
	OpR3f_PropData *unknown45cb30();	// NOTE: placeholder name
};

class HProp
{
	int ID;
public:
	Prop *operator->() const;	// 0x9b64f0
};

void OpR3f_eraseAt(vector<HProp> *v, int *i);	// NOTE: placeholder name (0x9d6440)

class OpR3f_PropList	// NOTE: placeholder name
{
public:
	bool unknown6c2180();	// NOTE: placeholder name

	vector<HProp> props;
};

bool OpR3f_PropList::unknown6c2180()
{
	for (int i = 0; i < props.size(); i++)
	{
		if (!props[i].operator->() || props[i]->unknown457b10() != 0 || props[i]->unknown45cb30()->unknown28 < 0)
			OpR3f_eraseAt(&props, &i);
	}
	return !props.empty();
}

bool OpR3f_splitAtBracket(const string &text, string &head, string &tail)	// NOTE: placeholder name
{
	size_t pos = text.find(']', 0);
	if (pos == string::npos || pos == text.length() - 1)
		return false;
	head.assign(text.begin(), text.begin() + pos + 1);
	tail.assign(text.begin() + pos + 1, text.end());
	return true;
}

class OpR3f_GameData	// NOTE: placeholder name
{
public:
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};
extern OpR3f_GameData opr3f_gameData;	// NOTE: placeholder name (0xd1e860)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

bool OpR3f_checkConditions(vector<string> &conditions)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < conditions.size(); i++)
	{
		string condition = conditions[i];
		size_t pos = condition.find("==");
		if (pos != string::npos)
		{
			if (opr3f_gameData.unknown46f6d0(string(condition.begin(), condition.begin() + pos)) != string(condition.begin() + pos + 2, condition.end()))
				return false;
			continue;
		}
		pos = condition.find("!=");
		if (pos != string::npos)
		{
			if (opr3f_gameData.unknown46f6d0(string(condition.begin(), condition.begin() + pos)) == string(condition.begin() + pos + 2, condition.end()))
				return false;
			continue;
		}
		bool positive = true;
		if (condition[0] == '!')
		{
			positive = false;
			condition.erase(condition.begin());
		}
		if (stringToInt(opr3f_gameData.unknown46f6d0(condition)))
		{
			if (!positive)
				return false;
		}
		else
		{
			if (positive)
				return false;
		}
	}
	return true;
}
