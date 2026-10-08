// op_s2_510110: expands one "<m...=...>" / "<r...=...>" tag in a message (COGMIND.exe Beta 17.1).
// NOTE: placeholder names; tables are parallel string arrays / vectors indexed by tag number.
#include <string>
#include <vector>
using namespace std;

extern string opS2_tagNamesM_d2ae30[];	// NOTE: placeholder name (0xd2ae30, 39 entries)
extern vector<string> opS2_tagValuesM_d1e900;	// NOTE: placeholder name (0xd1e900)
extern vector<int> opS2_tagUsedM_d1e920;	// NOTE: placeholder name (0xd1e920)
extern string opS2_tagNamesR_d1d0f8[];	// NOTE: placeholder name (0xd1d0f8, 28 entries)
extern vector<string> opS2_tagValuesR_d1e930;	// NOTE: placeholder name (0xd1e930)
extern vector<int> opS2_tagUsedR_d1e950;	// NOTE: placeholder name (0xd1e950)

string opS2_fn510110(string &text, bool *flag)	// NOTE: placeholder name
{
	size_t first;
	string *tags;
	size_t begin;
	const vector<string> *output;
	size_t end;
	vector<int> *enabled;
	int limit;
	if (flag)
		*flag = false;
	first = text.find('<');
	if (first != string::npos)
	{
		end = text.find('>', first + 1);
		if (end == string::npos)
			return text;
		tags = NULL;
		switch (text[first + 1])
		{
		case 'm':
			tags = opS2_tagNamesM_d2ae30;
			limit = 39;
			output = &opS2_tagValuesM_d1e900;
			enabled = &opS2_tagUsedM_d1e920;
			break;
		case 'r':
			tags = opS2_tagNamesR_d1d0f8;
			limit = 28;
			output = &opS2_tagValuesR_d1e930;
			enabled = &opS2_tagUsedR_d1e950;
			break;
		default:
			return text;
		}
		begin = text.find('=', first + 1);
		string key(text.begin() + begin + 1, text.begin() + end);
		const string *replacement = NULL;
		for (int i = 0; i < limit; i++)
		{
			if (key == tags[i])
			{
				replacement = &output->at(i);
				enabled->at(i) = 1;
			}
		}
		if (replacement)
		{
			text.replace(first, end - first + 1, *replacement);
			if (flag)
				*flag = true;
		}
	}
	return text;
}
