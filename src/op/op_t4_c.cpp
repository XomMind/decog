// op_t4_c: condition string helpers (0x6c3240-0x6c4600) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

class OpT4_GameData	// NOTE: placeholder name
{
public:
	string &unknown46f6d0(const string &key);	// NOTE: placeholder name
};
extern OpT4_GameData opt4_gameData;	// NOTE: placeholder name (0xd1e860)
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
void opw1_split(const string &text, char separator, vector<string> &out);	// NOTE: placeholder name (0x408700)

bool opt4_checkConditions(vector<string> &conditions)	// NOTE: placeholder name (0x6c3240)
{
	for (unsigned int i = 0; i < conditions.size(); i++)
	{
		string condition = conditions[i];
		size_t pos = condition.find("==");
		if (pos != string::npos)
		{
			if (opt4_gameData.unknown46f6d0(string(condition.begin(), condition.begin() + pos)) != string(condition.begin() + pos + 2, condition.end()))
				return false;
			continue;
		}
		pos = condition.find("!=");
		if (pos != string::npos)
		{
			if (opt4_gameData.unknown46f6d0(string(condition.begin(), condition.begin() + pos)) == string(condition.begin() + pos + 2, condition.end()))
				return false;
			continue;
		}
		else
		{
			bool positive = true;
			if (condition[0] == '!')
			{
				positive = false;
				condition.erase(condition.begin());
			}
			if (stringToInt(opt4_gameData.unknown46f6d0(condition)))
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
	}
	return true;
}
