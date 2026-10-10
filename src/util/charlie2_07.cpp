// prelearnData (0x797e60): applies one "prelearned" data string (map regions, exits, zone layouts, traps,
// emergency access, stockpiles, intel, machines) to the player's knowledge and logs what was stored.
// Callers: BS turn updates and OpR5c_Transmission. NOTE: placeholder names and layouts (C2P*, c2p_<address>).
#include <string>
#include <vector>
using namespace std;

struct C2PLocation	// NOTE: placeholder layout (map location record)
{
	int f0;
	int location;	// +0x4
	int depth;		// +0x8
	char p0c[0x26 - 0xc];
	bool known;		// +0x26
	bool inRange46ecb0();
};
struct C2PHandle	// NOTE: placeholder (location handle)
{
	int id;
	C2PHandle();
	C2PLocation *operator->();
};
struct C2PIntVec { int &operator[](unsigned i); };
struct C2PBS { C2PIntVec *known463ce0(); };
struct C2PGrid { int *at(int x, int y); };
struct C2PStats { bool add4729d0(unsigned id, int value, string text, int extra); };

extern C2PHandle c2p_d1e884, c2p_d1e888;
extern C2PBS *c2p_cefc4c;
extern C2PGrid c2p_d1e970;
extern C2PStats c2p_d2c658;
extern string c2p_d32170[], c2p_cfe140[], c2p_mapNames_cfaca0[], c2p_cf3fb0[];

void opU5_logWithShell(bool flag, const string &text);
string intToString(int v);
int stringToInt(const string &s);
void logError(string location, string message);
int c2p_findStringIndex(const string *list, unsigned n, string s);
void c2p_split408700(const string &text, char separator, vector<string> &out);
void c2p_unique9db7e0(vector<string> &list);
void c2p_collectNodes46ff70(int type, int sub, C2PHandle node, vector<C2PHandle> &matches, vector<C2PHandle> &visited);
void c2p_removeEntity(vector<C2PHandle> &list, C2PHandle entry);
C2PHandle c2p_randomRecord(vector<C2PHandle> &list);
int c2p_reveal794da0(int kind, int count, bool flag, int max);
bool c2p_logPhrase5141b0(int id, const string *a, const string *b, const string *c, C2PHandle subject, const void *at);
string c2p_countString407a80(int count, const string &noun);
extern const char c2p_bf83a0[], c2p_bf83a4[], c2p_bf83ac[], c2p_bf83bc[], c2p_bf83d4[], c2p_bf83ec[], c2p_bf83e8[], c2p_b95bbf[], c2p_bf83f0[], c2p_bf840c[], c2p_bf8430[], c2p_bf8444[], c2p_bf8440[], c2p_bf8454[], c2p_bf8478[], c2p_bf848c[], c2p_bf8488[], c2p_bf8498[], c2p_bf84a0[], c2p_bf84c0[], c2p_bf84d0[], c2p_bf84d8[], c2p_bf84d4[], c2p_bf84ec[], c2p_bf84f0[], c2p_bf8500[], c2p_bf8504[], c2p_bf8520[], c2p_bf8524[], c2p_bf8538[], c2p_bf853c[], c2p_bf8550[], c2p_bf8564[], c2p_bf8568[], c2p_bf8570[], c2p_bf8588[], c2p_bf85a4[], c2p_bf859c[];

bool prelearnData(string &text, bool flag)
{
	int pos = text.find(c2p_bf83a0, 0);
	if (pos == string::npos)
		return false;
	string prefix = flag ? c2p_bf83a4 : c2p_bf83ac;
	if (text.find(c2p_d32170[0], 0) != string::npos)
	{
		vector<C2PHandle> found;
		vector<bool> seen;
		string list(text.begin() + pos + 1, text.end());
		vector<string> names;
		c2p_split408700(list, '|', names);
		c2p_unique9db7e0(names);
		for (unsigned i = 0; i < names.size(); i++)
		{
			int index = c2p_findStringIndex(c2p_cfe140, 0x26, names[i]);
			if (index == -1)
				;
			else
			{
				vector<C2PHandle> matches;
				vector<C2PHandle> visited;
				c2p_collectNodes46ff70(index, -1, c2p_d1e884, matches, visited);
				c2p_removeEntity(matches, c2p_d1e888);
				if (!matches.empty())
				{
					C2PHandle pick = c2p_randomRecord(matches);
					found.push_back(pick);
					seen.push_back(pick->known);
					pick->known = true;
					c2p_d2c658.add4729d0(0x405, 1, c2p_b95bbf, -1);
					break;
				}
			}
		}
		if (!found.empty())
		{
			for (unsigned j = 0; j < found.size(); j++)
			{
				string message = seen[j] ? c2p_bf83bc : c2p_bf83d4;
				message += intToString(-found[j]->depth) + c2p_bf83ec + c2p_mapNames_cfaca0[found[j]->location] + c2p_bf83e8;
				opU5_logWithShell(flag, message);
				if (!seen[j] && found[j]->depth <= c2p_d1e888->depth && !found[j]->inRange46ecb0())
				{
					do
					{
						c2p_logPhrase5141b0(0x1a, &c2p_mapNames_cfaca0[found[j]->location], &intToString(-found[j]->depth), 0, C2PHandle(), 0);
					} while (0);
				}
			}
		}
	}
	else if (text.find(c2p_d32170[1], 0) != string::npos)
	{
		int id = stringToInt(string(text.begin() + pos + 1, text.end()));
		if (!c2p_reveal794da0(1, id, flag, 0x26))
		{
			string message = c2p_bf83f0;
			opU5_logWithShell(flag, message);
		}
	}
	else if (text.find(c2p_d32170[2], 0) != string::npos)
	{
		if (text.find('/', 0) == string::npos)
		{
			logError(c2p_bf8430, c2p_bf840c + text);
			return false;
		}
		string area(text.begin() + pos + 1, text.begin() + text.find('/', 0));
		int count = stringToInt(string(text.begin() + text.find('/', 0) + 1, text.end()));
		int requested = count;
		int index = c2p_findStringIndex(c2p_cfe140, 0x26, area);
		if (index == -1)
			;
		else
		{
			if (!flag || (*c2p_cefc4c->known463ce0())[2] == 0)
				count -= c2p_reveal794da0(2, count, flag, index);
			if (count != 0)
			{
				*c2p_d1e970.at(2, index) += count;
				string message = prefix + c2p_mapNames_cfaca0[index] + c2p_bf8444 + intToString(count) + c2p_bf8440;
				opU5_logWithShell(flag, message);
			}
		}
	}
	else if (text.find(c2p_d32170[3], 0) != string::npos)
	{
		if (text.find('/', 0) == string::npos)
		{
			logError(c2p_bf8478, c2p_bf8454 + text);
			return false;
		}
		string area(text.begin() + pos + 1, text.begin() + text.find('/', 0));
		int count = stringToInt(string(text.begin() + text.find('/', 0) + 1, text.end()));
		int index = c2p_findStringIndex(c2p_cfe140, 0x26, area);
		if (index == -1)
			;
		else
		{
			if (c2p_d1e888->location == index && (!flag || (*c2p_cefc4c->known463ce0())[3] == 0))
				count -= c2p_reveal794da0(3, count, flag, 0x26);
			if (count != 0)
			{
				*c2p_d1e970.at(3, index) += count;
				string message = prefix + c2p_mapNames_cfaca0[index] + c2p_bf848c + intToString(count) + c2p_bf8488;
				opU5_logWithShell(flag, message);
				do
				{
					c2p_logPhrase5141b0(0x1b, &c2p_mapNames_cfaca0[index], &c2p_countString407a80(count, c2p_bf8498), 0, C2PHandle(), 0);
				} while (0);
			}
		}
	}
	else if (text.find(c2p_d32170[4], 0) != string::npos)
	{
		if (text.find('/', 0) == string::npos)
		{
			logError(c2p_bf84c0, c2p_bf84a0 + text);
			return false;
		}
		string area(text.begin() + pos + 1, text.begin() + text.find('/', 0));
		int count = stringToInt(string(text.begin() + text.find('/', 0) + 1, text.end()));
		int index = area == c2p_bf84d0 ? 0 : c2p_findStringIndex(c2p_cfe140, 0x26, area);
		if (index == -1)
			;
		else if ((index == 0 || c2p_d1e888->location == index) && (!flag || (*c2p_cefc4c->known463ce0())[4] == 0))
			c2p_reveal794da0(4, count, flag, 0x26);
		else
		{
			*c2p_d1e970.at(4, index) += count;
			string message = prefix + c2p_mapNames_cfaca0[index] + c2p_bf84d8 + intToString(count) + c2p_bf84d4;
			opU5_logWithShell(flag, message);
			do
			{
				c2p_logPhrase5141b0(0x1c, &c2p_mapNames_cfaca0[index], &intToString(count), 0, C2PHandle(), 0);
			} while (0);
		}
	}
	else if (text.find(c2p_d32170[5], 0) != string::npos)
	{
		string area(text.begin() + pos + 1, text.end());
		int index = area == c2p_bf84ec ? 0 : c2p_findStringIndex(c2p_cfe140, 0x26, area);
		if (index == -1)
			;
		else if ((index == 0 || c2p_d1e888->location == index) && (!flag || (*c2p_cefc4c->known463ce0())[5] == 0))
			c2p_reveal794da0(5, 0, flag, 0x26);
		else
		{
			(*c2p_d1e970.at(5, index))++;
			string text5 = prefix + c2p_mapNames_cfaca0[index] + c2p_bf84f0;
			opU5_logWithShell(flag, text5);
			do
			{
				c2p_logPhrase5141b0(0x1d, &c2p_mapNames_cfaca0[index], 0, 0, C2PHandle(), 0);
			} while (0);
		}
	}
	else if (text.find(c2p_d32170[6], 0) != string::npos)
	{
		string area(text.begin() + pos + 1, text.end());
		int index = area == c2p_bf8500 ? 0 : c2p_findStringIndex(c2p_cfe140, 0x26, area);
		if (index == -1)
			;
		else if ((index == 0 || c2p_d1e888->location == index) && (!flag || (*c2p_cefc4c->known463ce0())[6] == 0))
			c2p_reveal794da0(6, 0, flag, 0x26);
		else
		{
			(*c2p_d1e970.at(6, index))++;
			string text6 = prefix + c2p_mapNames_cfaca0[index] + c2p_bf8504;
			opU5_logWithShell(flag, text6);
			do
			{
				c2p_logPhrase5141b0(0x1e, &c2p_mapNames_cfaca0[index], 0, 0, C2PHandle(), 0);
			} while (0);
		}
	}
	else if (text.find(c2p_d32170[7], 0) != string::npos)
	{
		string area(text.begin() + pos + 1, text.end());
		int index = area == c2p_bf8520 ? 0 : c2p_findStringIndex(c2p_cfe140, 0x26, area);
		if (index == -1)
			;
		else if ((index == 0 || c2p_d1e888->location == index) && (!flag || (*c2p_cefc4c->known463ce0())[7] == 0))
			c2p_reveal794da0(7, 0, flag, 0x26);
		else
		{
			(*c2p_d1e970.at(7, index))++;
			string text7 = prefix + c2p_mapNames_cfaca0[index] + c2p_bf8524;
			opU5_logWithShell(flag, text7);
			do
			{
				c2p_logPhrase5141b0(0x1f, &c2p_mapNames_cfaca0[index], 0, 0, C2PHandle(), 0);
			} while (0);
		}
	}
	else if (text.find(c2p_d32170[8], 0) != string::npos)
	{
		string area(text.begin() + pos + 1, text.end());
		int index = area == c2p_bf8538 ? 0 : c2p_findStringIndex(c2p_cfe140, 0x26, area);
		if (index == -1)
			;
		else if ((index == 0 || c2p_d1e888->location == index) && (!flag || (*c2p_cefc4c->known463ce0())[8] == 0))
			c2p_reveal794da0(8, 0, flag, 0x26);
		else
		{
			(*c2p_d1e970.at(8, index))++;
			string text8 = prefix + c2p_mapNames_cfaca0[index] + c2p_bf853c;
			opU5_logWithShell(flag, text8);
			do
			{
				c2p_logPhrase5141b0(0x20, &c2p_mapNames_cfaca0[index], 0, 0, C2PHandle(), 0);
			} while (0);
		}
	}
	else if (text.find(c2p_bf8550, 0) != string::npos)
	{
		int type = c2p_findStringIndex(c2p_d32170, 0x13, string(text.begin(), text.begin() + text.find('=', 0) + 1));
		if (type == -1)
			;
		else
		{
			string area(text.begin() + pos + 1, text.end());
			int index = area == c2p_bf8564 ? 0 : c2p_findStringIndex(c2p_cfe140, 0x26, area);
			if (index == -1)
				;
			else if ((index == 0 || c2p_d1e888->location == index) && (!flag || (*c2p_cefc4c->known463ce0())[type] == 0))
				c2p_reveal794da0(type, 0, flag, 0x26);
			else
			{
				(*c2p_d1e970.at(type, index))++;
				string kind;
				switch (type)
				{
				case 9:
					kind = c2p_bf8568;
					break;
				case 10:
					kind = c2p_bf8570;
					break;
				case 11:
					kind = c2p_bf8588;
					break;
				default:
					kind = c2p_cf3fb0[type - 12];
				}
				string message = prefix + c2p_mapNames_cfaca0[index] + c2p_bf85a4 + kind + c2p_bf859c;
				opU5_logWithShell(flag, message);
				do
				{
					c2p_logPhrase5141b0(0x21, &c2p_mapNames_cfaca0[index], &kind, 0, C2PHandle(), 0);
				} while (0);
			}
		}
	}
	else
		return false;
	return true;
}
