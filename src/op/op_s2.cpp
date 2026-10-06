// op_s2: functions in 0x4b2000-0x5df000
#include <ctype.h>
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct OpS2_A	// NOTE: placeholder name
{
	int pad0[5];
	vector<Point> a;	// +0x14
	int pad1;
	vector<Point> b;	// +0x28
	vector<unsigned int> c;	// +0x38
	vector<unsigned int> d;	// +0x48
	int pad2;
	vector<unsigned int> e;	// +0x5c

	~OpS2_A();	// 0x4bd140
};

OpS2_A::~OpS2_A()
{
}

struct OpS2_Named	// NOTE: placeholder name
{
	char pad0[0x24];
	string name;	// +0x24
};

extern vector<OpS2_Named *> opS2_namedList;	// NOTE: placeholder name (0xd2d1c4)

struct OpS2_Sub	// NOTE: placeholder name
{
	char pad0[0x78];
	int m78;	// +0x78
};

struct OpS2_Target	// NOTE: placeholder name
{
	char pad0[0xf0];
	int m0f0;	// +0xf0
	char pad1[0x1a0 - 0xf4];
	OpS2_Sub *m1a0;	// +0x1a0
	char pad2[0x1f4 - 0x1a4];
	vector<int> m1f4;	// +0x1f4

	void fn55f080(string &text);	// NOTE: placeholder name (0x55f080)
	string describe();	// 0x5702b0
	string namesJoined();	// 0x5703b0
};

string OpS2_Target::describe()
{
	string result;
	if (m0f0 != 0 || (m1a0 != NULL && m1a0->m78 != 0))
	{
		if (m0f0 != 0)
		{
			fn55f080(result);
		}
		else
		{
			m0f0 = m1a0->m78;
			fn55f080(result);
			m0f0 = 0;
		}
	}
	return result;
}

string OpS2_Target::namesJoined()
{
	string result;
	if (!m1f4.empty())
	{
		for (unsigned int i = 0; i < m1f4.size(); i++)
		{
			if (i != 0)
			{
				result += ", ";
			}
			result += opS2_namedList[m1f4[i]]->name;
		}
	}
	return result;
}

struct OpS2_Target2	// NOTE: placeholder name
{
	char pad0[0x24];
	string m24;	// +0x24
	string initials();	// 0x5704b0
};

string OpS2_Target2::initials()
{
	string result;
	result += m24[0];
	for (unsigned int i = 1; i < m24.size(); i++)
	{
		if (m24[i] == ' ')
		{
			i++;
			result += m24[i];
		}
	}
	return result;
}

string intToString(int value);

struct OpS2_Ids	// NOTE: placeholder name
{
	char pad0[0x13c];
	vector<int> m13c;	// +0x13c

	string idList();	// 0x570160
};

string OpS2_Ids::idList()
{
	string result;
	if (!m13c.empty())
	{
		if (m13c.front() == -1)
		{
			result = "Unlimited";
		}
		else
		{
			for (unsigned int i = 0; i < m13c.size(); i++)
			{
				if (i != 0)
				{
					result += " / ";
				}
				result += intToString(m13c[i]);
			}
		}
	}
	return result;
}

void opS2_replaceIndexed(string &text, int index, const string &replacement)	// NOTE: placeholder name (0x5105c0)
{
	size_t pos = text.find('%' + intToString(index),0);
	if (pos != string::npos)
	{
		text.erase(pos,2);
		text.insert(pos,replacement);
	}
}

class Entity
{
public:
	const string &getNameAt0c();	// NOTE: placeholder name (folded getter 0x416f40)
};

class HEntity
{
public:
	int ID;
	bool isValid() const;
	Entity *operator->() const;	// 0x9b6570
};

extern string opS2_stringCf0c70;	// NOTE: placeholder name (0xcf0c70)
extern string opS2_stringCf4acc;	// NOTE: placeholder name (0xcf4acc)
extern int opS2_intCf462c;	// NOTE: placeholder name (0xcf462c)

void opS2_fn510690(string &text, HEntity entity, int slot);
bool opS2_replace407e00(string &text, string from, string to);	// NOTE: placeholder name (0x407e00)
string opS2_fn510110(string &text, bool *flag);
void opS2_fn510360(string &text);	// NOTE: placeholder name (0x510360)

void opS2_fn510770(string &text);	// NOTE: placeholder name (0x510770)

void opS2_buildText(string &text, string *a, string *b, string *c, HEntity d, HEntity e)	// NOTE: placeholder name (0x510a50)
{
	opS2_replace407e00(text,opS2_stringCf0c70,opS2_stringCf4acc);
	opS2_fn510110(text,NULL);
	if (opS2_intCf462c == 8)
	{
		opS2_fn510360(text);
	}
	if (a != NULL)
	{
		opS2_replaceIndexed(text,1,*a);
	}
	if (b != NULL)
	{
		opS2_replaceIndexed(text,2,*b);
	}
	if (c != NULL)
	{
		opS2_replaceIndexed(text,3,*c);
	}
	if (d.isValid())
	{
		opS2_fn510690(text,d,0);
	}
	if (e.isValid())
	{
		opS2_fn510690(text,e,1);
	}
	opS2_fn510770(text);
}

struct OpS2_Phrase	// NOTE: placeholder name
{
	char pad0[0x28];
	string m28;	// +0x28
};

extern vector<OpS2_Phrase *> opS2_phrasesD01c04;	// NOTE: placeholder name (0xd01c04)
extern vector<OpS2_Phrase *> opS2_phrasesD2b4d8;	// NOTE: placeholder name (0xd2b4d8)

struct OpS2_PhraseTextA	// NOTE: placeholder name
{
	OpS2_Phrase *m0;	// +0x00
	string m4;	// +0x04

	OpS2_PhraseTextA(int index, string *a, string *b, string *c, HEntity d, HEntity e);	// 0x510d20
};

OpS2_PhraseTextA::OpS2_PhraseTextA(int index, string *a, string *b, string *c, HEntity d, HEntity e)
	: m0	(opS2_phrasesD01c04[index])
{
	m4 = m0->m28;
	opS2_buildText(m4,a,b,c,d,e);
}

struct OpS2_PhraseTextB	// NOTE: placeholder name
{
	OpS2_Phrase *m0;	// +0x00
	string m4;	// +0x04

	OpS2_PhraseTextB(int index, string *a, string *b, string *c, HEntity d, HEntity e);	// 0x510f80
};

OpS2_PhraseTextB::OpS2_PhraseTextB(int index, string *a, string *b, string *c, HEntity d, HEntity e)
	: m0	(opS2_phrasesD2b4d8[index])
{
	m4 = m0->m28;
	opS2_buildText(m4,a,b,c,d,e);
}

struct OpS2_PhraseTextC	// NOTE: placeholder name
{
	OpS2_Phrase *m0;	// +0x00
	string m4;	// +0x04

	OpS2_PhraseTextC(string text, string *a, string *b, string *c, HEntity d, HEntity e);	// 0x511020
};

OpS2_PhraseTextC::OpS2_PhraseTextC(string text, string *a, string *b, string *c, HEntity d, HEntity e)
	: m0	(NULL)
	, m4	(text)
{
	opS2_buildText(m4,a,b,c,d,e);
}

extern char opS2_openChars[];	// NOTE: placeholder name (0xbb9430)
extern char opS2_closeChars[];	// NOTE: placeholder name (0xbb9434)

void opS2_fn510690(string &text, HEntity entity, int slot)	// NOTE: placeholder name (0x510690)
{
	size_t start = text.find(opS2_openChars[slot],0);
	while (start != string::npos)
	{
		size_t end = text.find(opS2_closeChars[slot],start + 1);
		if (end == string::npos)
		{
			break;
		}
		switch (text[start + 1])
		{
		case 'n':
			switch (text[start + 2])
			{
			case 'a':
				text.replace(start,end - start + 1,entity->getNameAt0c());
				break;
			}
			break;
		}
		start = text.find(opS2_openChars[slot],start + 1);
	}
}

int stringToInt(const string &text);

void opS2_fn510360(string &text)	// NOTE: placeholder name (0x510360)
{
	size_t pos;
	if (text[0] == '^')
	{
		pos = text.find('_',0);
		if (pos == string::npos)
		{
			return;
		}
		string key(text.begin() + 1,text.begin() + pos);
		text.erase(text.begin(),text.begin() + pos + 1);
		int shift = stringToInt(key);
		shift = shift / 2;
		for (unsigned int i = 0; i < text.size(); i++)
		{
			if (isalpha(text[i]))
			{
				if (text[i] >= 'a')
				{
					text[i] -= shift;
					if (text[i] < 'a')
					{
						text[i] = 'z' - ('a' - text[i]) + 1;
					}
				}
				else
				{
					text[i] -= shift;
					if (text[i] < 'A')
					{
						text[i] = 'Z' - ('A' - text[i]) + 1;
					}
				}
			}
		}
	}
}

void logError(string location, string message);	// NOTE: placeholder name
string opR1d_454ed0(char c, bool capital);	// NOTE: placeholder name (0x454ed0)

void opS2_fn510770(string &text)	// NOTE: placeholder name (0x510770)
{
	int pos = text.find('@');
	while (pos != (int)string::npos)
	{
		if (pos + 2 > text.size() - 1 || text[pos + 2] == ' ')
		{
			logError("parseGrammar()", "Message \"" + text + "\" contains \"" + '@' + "\" not followed by a word");
			return;
		}

		text.insert(pos + 1, opR1d_454ed0(text[pos + 2], pos == 0 || (pos > 0 && (text[pos - 1] == '"' || text[pos - 1] == '\''))));
		text.erase(text.begin() + pos);
		pos = text.find('@', pos + 2);
	}
}
