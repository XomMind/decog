// op_b_filters: Config::parseColorFilters (0x4456b0), parses a colorFilters option value such as
// "Saturation(50)|Tint(255,0,0)" into the config's filter list (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &c);	// 0x411e30
	void set(unsigned char r_, unsigned char g_, unsigned char b_);	// 0x412590
};

struct XColorFilter	// NOTE: placeholder name
{
	XColorFilter();	// 0x412d80
	int type;
	int amount;
	float value;
	XColor color;
};

extern string OpB_colorFilterNames[];	// 0xd39468, NOTE: placeholder name
extern int OpB_colorFilterArgType[];	// 0xbb6d0c, NOTE: placeholder name
extern bool OpBF_colorFilterGlobalOnly[];	// NOTE: placeholder name (0xbb6d34)
extern string configOptionNames[];	// 0xd35e18 (global_string_arrays.cpp)
extern vector<XColorFilter> OpBF_activeFilters_d1d45c;	// NOTE: placeholder name

void opw1_split(const string &text, char separator, vector<string> &out);	// NOTE: placeholder name (0x408700)
int OpT8a_findStringIndex(const string *list, unsigned int count, string s);	// NOTE: placeholder name
void logError(string location, string message);	// 0x404f10
void logWarning(string location, string message);	// 0x404e50
int stringToInt(const string &str);	// 0x405610
float OpY1_stringToFloat(const string &str);	// NOTE: placeholder name
int ops7_clamp_9cdc80(int low, int value, int high);	// NOTE: placeholder name
void opr1c_setColor_4347a0(XColor color);	// NOTE: placeholder name

class Config	// NOTE: placeholder layout
{
public:
	void parseColorFilters(int which, string text);	// NOTE: placeholder name

	char pad00[0x128];
	vector<XColorFilter> colorFiltersA;	// NOTE: placeholder name
	vector<XColorFilter> colorFiltersB;	// NOTE: placeholder name
};

void Config::parseColorFilters(int which, string text)
{
	vector<XColorFilter> &filters = (which == 77 ? colorFiltersA : colorFiltersB);
	filters.clear();
	vector<string> entries;
	opw1_split(text,'|',entries);
	for (unsigned int i = 0; i < entries.size(); i++)
	{
		vector<string> args;
		size_t pos = entries[i].find('(',0);
		if (pos != string::npos)
		{
			opw1_split(string(entries[i].begin() + pos + 1,entries[i].end() - 1),',',args);
			entries[i].erase(entries[i].begin() + pos,entries[i].end());
		}
		int type = OpT8a_findStringIndex(OpB_colorFilterNames,10,entries[i]);
		if (type == -1)
		{
			logError("Config::init()","unknown colorFilterConfigType: " + entries[i]);
		}
		else if (!OpBF_colorFilterGlobalOnly[type] && which == 77)
		{
			logWarning("Config::init()","colorFilterConfigType " + entries[i] + " incompatible with " + configOptionNames[77]);
		}
		else
		{
		switch (type)
		{
		case 8:
			type = 3;
			args.push_back("47");
			args.push_back("30");
			args.push_back("31");
			break;
		case 9:
			type = 3;
			args.push_back("13");
			args.push_back("24");
			args.push_back("33");
			break;
		}
		XColorFilter filter;
		filter.type = type;
		switch (OpB_colorFilterArgType[filter.type])
		{
		case 1:
			filter.amount = stringToInt(args.front());
			break;
		case 2:
			filter.value = OpY1_stringToFloat(args.front()) / 100.0;
			break;
		case 3:
			filter.color.set(ops7_clamp_9cdc80(0,stringToInt(args[0]),255),ops7_clamp_9cdc80(0,stringToInt(args[1]),255),ops7_clamp_9cdc80(0,stringToInt(args[2]),255));
			break;
		}
		if (filter.type == 3)
			opr1c_setColor_4347a0(filter.color);
		if (filter.type == 5)
		{
			if (filter.amount == 0)
				filter.amount = 360;
			else if (filter.amount < 0)
			{
				do
					filter.amount += 360;
				while (filter.amount < 1);
			}
			else if (filter.amount > 360)
			{
				do
					filter.amount -= 360;
				while (filter.amount > 360);
			}
		}
		filters.push_back(filter);
		}
	}
	if (which == 78)
		OpBF_activeFilters_d1d45c = filters;
}
