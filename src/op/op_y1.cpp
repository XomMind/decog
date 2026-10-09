// op_y1: core engine helpers (0x400000-0x440000) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctype.h>
#include <math.h>
#include <sstream>
#include <iomanip>
#include "thirdparty/physfs.hpp"
#include "util/stringutil.h"
using namespace std;

// small 3-word generator
unsigned int OpY1_rng4033c0(unsigned int *state)	// NOTE: placeholder name
{
	state[0] += 0x423a35c7;
	unsigned int t = ((state[1] << 21) | (state[1] >> 11)) ^ state[0];
	state[1] = ((state[2] << 13) | (state[2] >> 19)) + t;
	state[2] = state[0] + t;
	return state[2];
}

unsigned int OpY1_hashSeedString(const string &seedText)	// NOTE: placeholder name
{
	string text(seedText);
	hash<string> hasher;
	transform(text.begin(),text.end(),text.begin(),tolower);
	return hasher(text);
}

//==================================================================
// string conversion helpers (0x405290-0x4059d0)
//==================================================================

string unsignedToString(unsigned int value)	// NOTE: placeholder name
{
	ostringstream stream;
	stream << value;
	return stream.str();
}

string OpY1_intToStringGrouped(int value)	// NOTE: placeholder name
{
	ostringstream stream;
	stream << value;
	string text = stream.str();
	for (int i = 0, index = text.size() % 3 + (text.size() % 3 ? 0 : 3), end = text.size() / 3 - (text.size() % 3 ? 0 : 1); i < end; i++, index += 4)
		text.insert(index,",");
	return text;
}

string OpY1_floatToStringFixed(float value)	// NOTE: placeholder name
{
	ostringstream stream;
	stream << fixed << value;
	return stream.str();
}

string OpY1_intToStringSigned(int value)	// NOTE: placeholder name
{
	ostringstream stream;
	stream.setf(ios::showpos);
	stream << value;
	return stream.str();
}

int stringToInt(const string &str)	// NOTE: placeholder name
{
	istringstream stream(str);
	int result;
	stream >> result;
	return result;
}

unsigned int OpY1_stringToUnsigned(const string &str)	// NOTE: placeholder name
{
	istringstream stream(str);
	unsigned int value;
	stream >> value;
	return value;
}

string floatToString(float value, int unknown1, int unknown2)	// NOTE: placeholder name
{
	string text = OpY1_floatToStringFixed(value);
	unsigned int pos = text.find('.');
	if (unknown1 == 0)
	{
		if (pos == string::npos)
			return text;
		else if (fabs(value - (int)value) < 0.001)
		{
			text.erase(text.begin() + pos,text.end());
			return text;
		}
	}

	if (pos == string::npos)
	{
		text += ".";
		text.append(unknown1,'0');
	}
	else if (text.size() - pos <= unknown1)
		text.append(unknown1 - (text.size() - pos) + 1,'0');

	if (unknown2 != -1)
	{
		pos = text.find('.');
		if (text.size() - pos - 1 > unknown2)
			return string(text.begin(),text.begin() + pos + unknown2 + 1);
	}
	return text;
}

string OpY1_floatToStringSigned(float value, int unknown1, int unknown2)	// NOTE: placeholder name
{
	if (value >= 0.0)
		return "+" + floatToString(value,unknown1,unknown2);
	else
		return floatToString(value,unknown1,unknown2);
}

float OpY1_stringToFloat(const string &str)	// NOTE: placeholder name
{
	istringstream stream(str);
	float value;
	stream >> dec >> value;
	return value;
}

bool OpY1_hexToByte(const string &str, unsigned char *value)	// NOTE: placeholder name
{
	int result = 0;
	int shift = 0;
	for (int i = str.size() - 1; i >= 0; shift++, i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
			result += (str[i] - '0') * (1 << (shift * 4));
		else
		{
			switch (str[i])
			{
				case 'A':
				case 'a': result += (1 << (shift * 4)) * 10; break;
				case 'B':
				case 'b': result += (1 << (shift * 4)) * 11; break;
				case 'C':
				case 'c': result += (1 << (shift * 4)) * 12; break;
				case 'D':
				case 'd': result += (1 << (shift * 4)) * 13; break;
				case 'E':
				case 'e': result += (1 << (shift * 4)) * 14; break;
				case 'F':
				case 'f': result += (1 << (shift * 4)) * 15; break;
				default: return false;
			}
		}
	}
	*value = result;
	return true;
}

bool OpY1_hexToRGB(const string &hex, unsigned char *r, unsigned char *g, unsigned char *b)	// NOTE: placeholder name
{
	return hex.size() == 6 && OpY1_hexToByte(hex.substr(0,2),r) && OpY1_hexToByte(hex.substr(2,2),g) && OpY1_hexToByte(hex.substr(4,2),b);
}

string OpY1_bytesToHex(const unsigned char *data, unsigned int length)	// NOTE: placeholder name
{
	stringstream stream;
	stream << hex;
	stream << setfill('0');
	for (unsigned int i = 0; i < length; i++)
		stream << setw(2) << (unsigned int)data[i];
	return stream.str();
}

string OpY1_rotateText(const string &text)	// NOTE: placeholder name
{
	int shift = 13;
	string result(text);
	for (unsigned int i = 0; i < result.size(); i++)
	{
		if (isalpha(result[i]))
		{
			if (result[i] >= 'a')
			{
				result[i] -= shift;
				if (result[i] < 'a')
					result[i] = 'z' - ('a' - result[i]) + 1;
			}
			else
			{
				result[i] -= shift;
				if (result[i] < 'A')
					result[i] = 'Z' - ('A' - result[i]) + 1;
			}
		}
		else if (isdigit(result[i]))
		{
			switch (result[i])
			{
				case '0': result[i] = '5'; break;
				case '1': result[i] = '6'; break;
				case '2': result[i] = '7'; break;
				case '3': result[i] = '8'; break;
				case '4': result[i] = '9'; break;
				case '5': result[i] = '0'; break;
				case '6': result[i] = '1'; break;
				case '7': result[i] = '2'; break;
				case '8': result[i] = '3'; break;
				case '9': result[i] = '4'; break;
			}
		}
	}
	return result;
}

//==================================================================
// math helpers (0x406360-0x4068b0)
//==================================================================

int OpY1_sqr(int value);	// NOTE: placeholder name (0x9ccff0, template instance)
float OpY1_degToRad(float degrees);	// NOTE: placeholder name (0x9cd000, template instance)
bool OpY1_between(int low, int value, int high);	// NOTE: placeholder name (0x9daf80, template instance)

int OpY1_round(float value)	// NOTE: placeholder name
{
	return (int)(value < 0.0 ? -(int)(-value + 0.5) : value + 0.5);
}

int OpW7_remap(int value, int inMin, int inMax, int outMin, int outMax)	// NOTE: placeholder name
{
	value = (int)(outMin + (float)(value - inMin) / (inMax - inMin) * (outMax - outMin));
	if (outMax > outMin)
	{
		value = value < outMax ? value : outMax;
		return value > outMin ? value : outMin;
	}
	value = value < outMin ? value : outMin;
	return value > outMax ? value : outMax;
}

int opw8_distance(int x1, int y1, int x2, int y2)	// NOTE: placeholder name
{
	return (int)(sqrt((float)(OpY1_sqr(x2 - x1) + OpY1_sqr(y2 - y1))) + 0.9999);
}

float OpY1_angle(int x1, int y1, int x2, int y2)	// NOTE: placeholder name
{
	float dy = -y2 - -y1;
	float dx = x2 - x1;
	if (dx == 0)
	{
		if (dy > 0.0)
			return 0;
		else
			return 180;
	}
	if (dy == 0)
	{
		if (dx > 0.0)
			return 90;
		else
			return 270;
	}
	if (dx > 0.0)
		return 90.0 - atan(dy / dx) * 57.2957763671875;
	else
		return 270.0 - atan(dy / dx) * 57.2957763671875;
}

bool OpY1_angleInArc(int center, int width, int angle)	// NOTE: placeholder name
{
	int start = center - width / 2;
	int end = center + width / 2;
	return OpY1_between(start,angle,end) || (start < 0 && angle >= start + 360);
}

void OpY1_rotatePoint(float cx, float cy, float x, float y, float degrees, float *outX, float *outY)	// NOTE: placeholder name
{
	float radians = OpY1_degToRad(degrees);
	*outX = cos(radians) * (x - cx) + cx - sin(radians) * (y - cy);
	*outY = sin(radians) * (x - cx) + cy + cos(radians) * (y - cy);
}

void OpY1_pointAlongLine(float x1, float y1, float x2, float y2, float distance, float *outX, float *outY)	// NOTE: placeholder name
{
	if (x2 == x1)
	{
		*outX = x2;
		if (y2 > y1)
			*outY = y1 + distance;
		else
			*outY = y1 - distance;
	}
	else if (y2 == y1)
	{
		*outY = y2;
		if (x2 > x1)
			*outX = x1 + distance;
		else
			*outX = x1 - distance;
	}
	else
	{
		float slope = (y2 - y1) / (x2 - x1);
		if (x2 > x1)
			*outX = x1 + distance / sqrt(1 + slope * slope);
		else
			*outX = x1 - distance / sqrt(1 + slope * slope);
		if (x2 > x1)
			*outY = y1 + distance / sqrt(1 + slope * slope) * slope;
		else
			*outY = y1 - distance / sqrt(1 + slope * slope) * slope;
	}
}

int OpY1_countDigits(unsigned int value)	// NOTE: placeholder name
{
	int digits = 1;
	do
	{
		if (value < pow(10.0f,digits))
			return digits;
		else
			digits++;
	} while (true);
}

//==================================================================
// shuffle bag of integers (0x406ec0, 0x4112e0-0x411580)
//==================================================================

template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0
void OpY1_shuffle(vector<int> &v);	// NOTE: placeholder name (0x9d8f80, template instance)
void OpY1_clamp(int low, int &value, int high);	// NOTE: placeholder name (0x9cdc50, template instance)
void OpY1_writeInt(ostream &stream, int *value);	// NOTE: placeholder name (0x9d3b60, template instance)
void OpY1_writeIntVector(ostream &stream, vector<int> *value);	// NOTE: placeholder name (0x9d2130, template instance)
void OpY1_readInt(istream &stream, int *value);	// NOTE: placeholder name (0x9d8480, template instance)
void OpY1_readIntVector(istream &stream, vector<int> *value);	// NOTE: placeholder name (0x9cf5e0, template instance)

extern const int OpY1_BLANK;	// NOTE: placeholder name (0xb6f57c, value -1)

class OpY1_ShuffleBag	// NOTE: placeholder name
{
public:
	int mode;
	int blanks;
	vector<int> items;
	vector<int> deck;

	OpY1_ShuffleBag(const vector<int> &items_, int blanks_, int mode_);
	OpY1_ShuffleBag(istream &stream);
	void save(ostream &stream);
	void refill();
	int draw();
};

OpY1_ShuffleBag::OpY1_ShuffleBag(const vector<int> &items_, int blanks_, int mode_)
	: mode(mode_),
	blanks(blanks_),
	items(items_)
{
	refill();
	for (int i = 0; i < 3; i++)
		draw();
}

void OpY1_ShuffleBag::save(ostream &stream)
{
	OpY1_writeInt(stream,&blanks);
	OpY1_writeIntVector(stream,&items);
	OpY1_writeIntVector(stream,&deck);
}

OpY1_ShuffleBag::OpY1_ShuffleBag(istream &stream)
{
	OpY1_readInt(stream,&blanks);
	OpY1_readIntVector(stream,&items);
	OpY1_readIntVector(stream,&deck);
}

void OpY1_ShuffleBag::refill()
{
	deck = items;
	if (mode == 1)
	{
		vector<int> offsets;
		for (int i = -10; i <= 9; i++)
			offsets.push_back(i);
		OpY1_shuffle(offsets);
		for (unsigned int j = 0; j < offsets.size(); j++)
		{
			deck[j] += offsets[j];
			OpY1_clamp(0,deck[j],100);
		}
	}
	for (int k = 0; k < blanks; k++)
		deck.push_back(OpY1_BLANK);
	OpY1_shuffle(deck);
}

int OpY1_ShuffleBag::draw()
{
	while (deck.empty() || deck.front() == -1)
		refill();
	int value = deck.front();
	removeVectorElement(deck,0);
	return value;
}

//==================================================================
// seeded generator wrappers used by the seed decoder (0x407060-0x4074b0)
//==================================================================

typedef unsigned int u32;
typedef unsigned long long u64;

struct pcg32State_t		// NOTE: placeholder name
{
	u64 state;
	u64 inc;
};

struct Rng4_t		// NOTE: placeholder name
{
	u32 a, b, c, d;
};

void pcg32Seed_402880(pcg32State_t *rng, u64 initstate, u64 initseq);	// NOTE: placeholder name
u32 pcg32Bounded_402970(pcg32State_t *rng, u32 bound);	// NOTE: placeholder name
u32 rng4Next_4029b0(Rng4_t *arg);	// NOTE: placeholder name
u32 boundedRand_402ad0(u32 range, u32 (*gen)(void *), void *ctx);	// NOTE: placeholder name

class OpY1_RngPcg	// NOTE: placeholder name
{
public:
	u32 initState;
	u32 initSeq;
	pcg32State_t rng;

	void seed(u32 seed_);
	int rangeInt(int low, u32 count);
};

void OpY1_RngPcg::seed(u32 seed_)
{
	initState = seed_;
	initSeq = seed_;
	pcg32Seed_402880(&rng,initState,initSeq);
}

int OpY1_RngPcg::rangeInt(int low, u32 count)
{
	return pcg32Bounded_402970(&rng,count) + low;
}

class OpY1_Rng4	// NOTE: placeholder name
{
public:
	int currentSeed;
	Rng4_t rng;

	void seed(int seed_);
	int rangeInt(int low, u32 count);
};

void OpY1_Rng4::seed(int seed_)
{
	currentSeed = seed_;
	rng.a = currentSeed;
	rng.b = currentSeed + 1;
	rng.c = currentSeed + 2;
	rng.d = currentSeed + 3;
}

int OpY1_Rng4::rangeInt(int low, u32 count)
{
	return boundedRand_402ad0(count,(u32 (*)(void *))rng4Next_4029b0,&rng) + low;
}

//==================================================================
// encoded text file lines (0x4074b0)
//==================================================================

extern const int OpY1_lineKeys[][300];	// NOTE: placeholder name (0xb6f580)
extern void (*OpY1_tamperCallback)();	// NOTE: placeholder name (0xcefa68)

bool OpY1_getEncodedLine(PhysFScpp::ifstream *file, string &line, int key)	// NOTE: placeholder name
{
	bool ok = getline(*file,line);
	if (!line.empty())
	{
		if (ok && line[line.size() - 1] == '\r')
			line.erase(line.end() - 1);
		if (!line.empty() && key != -1)
		{
			// local names chosen for /Od layout (name-hash buckets; GS buffer splits the scalars)
			int table = key < 100 ? key : key % 100;
			char d = line[0];
			string message(line.begin() + 1,line.begin() + 1 + 4);
			int val = stringToInt(message);
			line.erase(line.begin(),line.begin() + 1 + 4);
			int len = line[line.size() - 1] == '\n' ? line.size() - 1 : line.size();
			int c;
			for (int i = 0, n = 0; i < len; i++)
			{
				c = line[i] - OpY1_lineKeys[table][n];
				if (c < 32)
					c += 95;
				line[i] = c;
				n++;
				if (n == 300)
					n = 0;
				if (line[i] == d)
					val--;
			}
			if (val != 0 && OpY1_tamperCallback != NULL)
				OpY1_tamperCallback();
		}
	}
	return ok;
}

//==================================================================
// string editing/comparison helpers (0x4077e0-0x407e00)
//==================================================================

void opw8_eraseFirstChar(string &s)	// NOTE: placeholder name
{
	s.erase(s.begin());
}

string &OpY1_eraseFirstCharRef(string &s)	// NOTE: placeholder name
{
	s.erase(s.begin());
	return s;
}

void opw8_eraseLastChar(string &s)	// NOTE: placeholder name
{
	s.erase(s.end() - 1);
}

struct OpY1_CharEqualNoCase	// NOTE: placeholder name
{
	OpY1_CharEqualNoCase() {}
	bool operator()(char a, char b);
};

bool OpY1_CharEqualNoCase::operator()(char a, char b)
{
	return toupper(a) == toupper(b);
}

int opw1_findNoCase(const string &text, const string &term) throw()	// NOTE: placeholder name
{
	string::const_iterator it = search(text.begin(),text.end(),term.begin(),term.end(),OpY1_CharEqualNoCase());
	if (it != text.end())
		return it - text.begin();
	else
		return -1;
}

bool OpY1_equalsNoCase(const string &a, const string &b)	// NOTE: placeholder name
{
	if (a.size() != b.size())
		return false;
	for (unsigned int i = 0; i < a.size(); i++)
	{
		if (toupper(a[i]) != toupper(b[i]))
			return false;
	}
	return true;
}

bool opw1_startsWith(const string &text, const string &prefix) throw()	// NOTE: placeholder name
{
	if (prefix.size() > text.size())
		return false;
	for (unsigned int i = 0; i < prefix.size(); i++)
	{
		if (toupper(text[i]) != toupper(prefix[i]))
			return false;
	}
	return true;
}

string opw8_countString(int count, const string &noun)	// NOTE: placeholder name
{
	return count == 1 ? intToString(count) + " " + noun : intToString(count) + " " + noun + (noun[noun.size() - 1] == 's' ? "es" : "s");
}
