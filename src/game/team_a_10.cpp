// team_a_10: std::string helpers in 0x407e00-0x408e00 (replace, case conversion, trimming, comment stripping).
// NOTE: function names are placeholders (several reuse the names other areas already declare).
// NOTE: local variable names affect the /Od stack layout (renaming n/i fixed opW5_truncate_408490).
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;


void opr5c_replace407e00(string &text, string from, string to)	// NOTE: placeholder name
{
	size_t pos = text.find(from.c_str());
	if (pos == string::npos)
		return;
	text.replace(text.begin() + pos,text.begin() + pos + from.size(),to);
}

void OpC_replaceAll_407f00(string &text, string from, string to)	// NOTE: placeholder name
{
	size_t pos = text.find(from.c_str());
	while (pos != string::npos)
	{
		text.replace(text.begin() + pos,text.begin() + pos + from.size(),to);
		pos = text.find(from.c_str(),pos);
	}
}

int countRun_408000(string &text, char c, unsigned int start)	// NOTE: placeholder name
{
	if (text.size() <= start || text[start] != c)
		return 0;
	int count = 1;
	for (unsigned int i = start + 1; i < text.size(); i++)
	{
		if (text[i] == c)
			count++;
		else
			break;
	}
	return count;
}

void OpC_removeChar_408100(string &text, char c)	// NOTE: placeholder name (collapse runs of c)
{
	int n;
	for (unsigned int i = 0; i < text.size(); i++)
	{
		if (text[i] == c)
		{
			n = 0;
			for (unsigned int j = i + 1; j < text.size(); j++, n++)
			{
				if (text[j] != c)
					break;
			}
			text.erase(i,n + 1);
			i += n;
		}
	}
}

bool opw6_truncate408220(string &text, unsigned int length, int offset)	// NOTE: placeholder name
{
	if (text.size() > length)
	{
		text.erase(text.begin() + length - offset,text.end() - offset);
		return true;
	}
	else
		return false;
}

string OpC_stringFunc_4082b0(const string &text)	// NOTE: placeholder name (lower-case copy)
{
	string s(text);
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (isupper(s[i]))
			s[i] = tolower(s[i]);
	}
	return s;
}

string OpR5f_toUpper_4083a0(const string &text)	// NOTE: placeholder name
{
	string s(text);
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (islower(s[i]))
			s[i] = toupper(s[i]);
	}
	return s;
}

string opW5_truncate_408490(const string &text, int length)	// NOTE: placeholder name
{
	string s(text);
	if (s.size() > length)
	{
		s.erase(s.begin() + length,s.end());
		for (int n = 0, i = s.size() - 1; n < 3; n++, i--)
			s[i] = '.';
	}
	return s;
}

void OpC_stringFunc_408660(string &text, char c)	// NOTE: placeholder name (trim trailing c)
{
	unsigned int n = 0;
	while (n < text.size() && text[text.size() - 1 - n] == c)
		n++;
	if (n)
		text.erase(text.end() - n,text.end());
}

void OpW7_trim_408ad0(string &text)	// NOTE: placeholder name (strip comments and trailing blanks)
{
	size_t pos = text.find("//");
	if (pos != string::npos)
		text.erase(text.begin() + pos,text.end());
	OpC_stringFunc_408660(text,' ');
	OpC_stringFunc_408660(text,'\t');
	pos = text.find("/*");
	while (pos != string::npos)
	{
		size_t end = text.find("*/",pos + 2);
		if (end != string::npos)
			text.erase(text.begin() + pos,text.begin() + end + 2);
		pos = text.find("/*");
	}
}

void replaceChar_4081c0(string &s, char from, char to);	// NOTE: placeholder name
void OpW7_split_408860(const string &text, char separator, char quote, vector<string> &out, bool flag);	// NOTE: placeholder name
void parseLine_408d70(string &text, vector<string> &out)	// NOTE: placeholder name (same body as OpW7_parseLine)
{
	if (text.empty())
		return;
	OpW7_trim_408ad0(text);
	replaceChar_4081c0(text,'\t',' ');
	OpC_removeChar_408100(text,'\n');
	OpC_replaceAll_407f00(text,"\\n","\n");
	if (text.find_first_of(' ') == string::npos)
		return;
	OpW7_split_408860(text,' ','"',out,true);
}


void opw1_split(string &text, char separator, vector<string> &out)	// NOTE: placeholder name
{
	if (text.empty())
		return;
	size_t start = text.find_first_of(separator);
	size_t end = text.find(separator,start + 1);
	if (end == string::npos)
		end = text.size();
	do
	{
		out.push_back(string(text.begin() + start,text.begin() + end));
		start = text.find_first_of(separator,end + 1);
		if (start == string::npos)
			return;
		end = text.find(separator,start);
		if (end == string::npos)
			end = text.size();
	} while (start != string::npos);
}

int splitBetween_408c20(string &text, const string &open, const string &close, vector<string> &out)	// NOTE: placeholder name
{
	if (text.empty())
		return 0;
	int result = 0;
	size_t index = -1;
	size_t p;
	while (true)
	{
		index = text.find(open,index + 1);
		if (index == string::npos)
			return result;
		index += open.size();
		p = text.find(close,index);
		if (p == string::npos)
			return result;
		out.push_back(string(text.begin() + index,text.begin() + p));
		result++;
	}
	return result;
}
