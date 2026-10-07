// team_a_03: assorted tiny helpers in 0x403000-0x406500 (stream/file inlines, small accessors, int helpers).
// NOTE: class, member and function names are placeholders unless they are STL names.
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Handle404af0	// NOTE: placeholder name
{
public:
	int pad0;
	void *unknown4;
	bool isValid();
};

bool Handle404af0::isValid()
{
	return unknown4;
}

class REX404b70	// NOTE: placeholder name (REX::initJLog calls it)
{
public:
	char pad[0x58];
	bool unknown58;
	void setUnknown58(bool value);
};

void REX404b70::setUnknown58(bool value)
{
	unknown58 = value;
}

void discardString_404be0(string message)	// NOTE: placeholder name
{
}

int charToDigit_405b40(char c)	// NOTE: placeholder name
{
	int value = c - '0';
	return value;
}

int isEven_406320(int value)	// NOTE: placeholder name
{
	return value % 2 == 0;
}

bool isOdd_406340(int value)	// NOTE: placeholder name
{
	return value % 2;
}

int halfProduct_406460(int a, int b, int c)	// NOTE: placeholder name
{
	return (a + b) * c / 2;
}

// Not in the exe: references the stream templates whose out-of-line pieces are mapped here
// (basic_istringstream/basic_stringstream vbase destructors, std::_Fgetc/_Fputc/_Ungetc<char>).
void teamA03_useStreams(const string &s)	// NOTE: placeholder
{
	istringstream a(s); stringstream b(s);
	ifstream f("x"); char c; f.get(c); f.putback(c); ofstream o("y"); o.put(c);
}
