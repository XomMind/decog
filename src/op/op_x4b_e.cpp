// op_x4b: spawn condition check (0x6c36c0) matched against COGMIND.exe (Beta 17.1).
// NOTE: placeholder names throughout.
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
void opw1_split(const string &text, char separator, vector<string> &out);	// NOTE: placeholder name (0x408700)
bool opt4_checkConditions(vector<string> &conditions);	// NOTE: placeholder name (0x6c3240)

bool opt4_checkSpawnCondition(const string &text)	// NOTE: placeholder name (0x6c36c0)
{
	if (text.empty())
		return true;
	if (text[0] == '`')
		return true;
	size_t pos = text.find("%_",0);
	if (pos == string::npos)
		goto next;
	if (rng.chance(stringToInt(string(const_cast<string&>(text).begin(),const_cast<string&>(text).begin() + pos))))
		goto next;
	else
		return false;
next:
	pos = text.find(',',0);
	if (pos == string::npos)
		return true;
	vector<string> parts;
	opw1_split(string(const_cast<string&>(text).begin(),const_cast<string&>(text).begin() + pos),'+',parts);
	return opt4_checkConditions(parts);
}
