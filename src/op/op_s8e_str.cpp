// op_s8e_str: std::string iterator-range template instances (VS2010)
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <istream>
using namespace std;

void OpS8e_StrUse(vector<char> &v, string &s)
{
	s.assign(v.begin(), v.end());
	s.append(v.begin(), v.end());
	string t(v.begin(), v.end());
	s = t;
}

void OpS8e_GetlineUse(istream &in, string &s)
{
	getline(in, s, 'x');
}

void OpS8e_IterUse(istream &in, string &s)
{
	s.assign(istreambuf_iterator<char>(in), istreambuf_iterator<char>());
	s.append(istreambuf_iterator<char>(in), istreambuf_iterator<char>());
	string t((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
	s = t;
}

struct OpY1_CharEqualNoCase	// NOTE: placeholder name (defined in op_y1.cpp)
{
	OpY1_CharEqualNoCase() {}
	bool operator()(char a, char b);
};

int OpS8e_SearchUse(string &text, string &term)
{
	string::iterator it = search(text.begin(),text.end(),term.begin(),term.end(),OpY1_CharEqualNoCase());
	return it - text.begin();
}

void OpS8e_TransformUse(string &s, vector<char> &v)
{
	transform(s.begin(), s.end(), s.begin(), toupper);
	transform(s.begin(), s.end(), v.begin(), toupper);
}
