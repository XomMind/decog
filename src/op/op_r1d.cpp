// op_r1d: functions in 0x434ad0-0x456a50 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &c);
	XColor &operator=(XColor c);
};

extern XColor *opW9_d25e0c;	// NOTE: placeholder name
extern XColor *opR1d_cf281c;	// NOTE: placeholder name
extern XColor *opR1d_d23094;	// NOTE: placeholder name
extern XColor *opR1d_d2f34c;	// NOTE: placeholder name
extern XColor opR1d_d29ae0[];	// NOTE: placeholder name

void opR1d_434ad0()	// NOTE: placeholder name
{
	opR1d_d29ae0[0] = *opW9_d25e0c;
	opR1d_d29ae0[1] = *opW9_d25e0c;
	opR1d_d29ae0[2] = *opR1d_cf281c;
	opR1d_d29ae0[3] = *opR1d_cf281c;
	opR1d_d29ae0[4] = *opR1d_d23094;
	opR1d_d29ae0[5] = *opR1d_d23094;
	opR1d_d29ae0[6] = *opR1d_d2f34c;
}

extern int opR1d_ba879c[];	// NOTE: placeholder name

int opR1d_434b90(int value)	// NOTE: placeholder name
{
	if (value >= 100)
	{
		return 6;
	}

	for (int i = 5; i >= 1; i--)
	{
		if (value >= opR1d_ba879c[i])
		{
			return i;
		}
	}

	return 0;
}

void opR1d_4350b0(string &s, int shift)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i]))
		{
			if (s[i] >= 'a')
			{
				char &c = s[i];
				c = c - shift;
				if (s[i] < 'a')
				{
					s[i] = 'z' - ('a' - s[i]) + 1;
				}
			}
			else
			{
				char &c = s[i];
				c = c - shift;
				if (s[i] < 'A')
				{
					s[i] = 'Z' - ('A' - s[i]) + 1;
				}
			}
		}
	}
}

void opR1d_4369a0(unsigned char *c, int n)	// NOTE: placeholder name
{
	if (n > c[0])
	{
		c[0] = 256 - (n - c[0]);
	}
	else
	{
		c[0] = c[0] - n;
	}

	if (n > c[1])
	{
		c[1] = 256 - (n - c[1]);
	}
	else
	{
		c[1] = c[1] - n;
	}

	if (n > c[2])
	{
		c[2] = 256 - (n - c[2]);
	}
	else
	{
		c[2] = c[2] - n;
	}
}

#include <time.h>

bool opR1d_436a50(int year, int month, int day)	// NOTE: placeholder name
{
	time_t rawtime;
	time(&rawtime);
	struct tm *timeinfo = localtime(&rawtime);

	return timeinfo->tm_year == year - 1900 && timeinfo->tm_mon == month - 1 && timeinfo->tm_mday == day;
}

bool opR1d_436ac0(int year, int month, int day, int days)	// NOTE: placeholder name
{
	if (days == 0)
	{
		return false;
	}
	if (days == 1)
	{
		return opR1d_436a50(year, month, day);
	}

	time_t time1;
	time(&time1);
	struct tm *tm1 = localtime(&time1);
	tm1->tm_year = year - 1900;
	tm1->tm_mon = month - 1;
	tm1->tm_mday = day;
	time1 = mktime(tm1);

	time_t time2;
	time(&time2);
	struct tm *tm2 = localtime(&time2);
	double delta = difftime(time2, time1);
	if (delta < 0)
	{
		return false;
	}
	else
	{
		double spd = 86400.0;
		int result = (int)(delta / spd);
		return result < days;
	}
}

string intToString(int value);
string &opR1d_padLeft(string &s, unsigned int width, char c);	// NOTE: placeholder name (0x408090)

#include <windows.h>
#include <rpc.h>

string opR1d_436bc0()	// NOTE: placeholder name
{
	GUID guid;
	CoCreateGuid(&guid);

	unsigned char *str;
	UuidToStringA(&guid, &str);
	string result((char *)str);
	RpcStringFreeA(&str);

	return result;
}

string opR1d_436e70(bool dateOnly, time_t t)	// NOTE: placeholder name
{
	time_t rawtime;
	if (t != 0)
	{
		rawtime = t;
	}
	else
	{
		time(&rawtime);
	}
	struct tm *timeinfo = localtime(&rawtime);

	string result;
	string yearStr = intToString(timeinfo->tm_year);
	result.assign<string::const_iterator>((const string::const_iterator &)(yearStr.end() - 2), (const string::const_iterator &)yearStr.end());	// iterator arithmetic, const_iterator template instance
	result += opR1d_padLeft(intToString(timeinfo->tm_mon + 1), 2, '0');
	result += opR1d_padLeft(intToString(timeinfo->tm_mday), 2, '0');

	if (!dateOnly)
	{
		result += "-";
		result += opR1d_padLeft(intToString(timeinfo->tm_hour), 2, '0');
		result += opR1d_padLeft(intToString(timeinfo->tm_min), 2, '0');
		result += opR1d_padLeft(intToString(timeinfo->tm_sec), 2, '0');
	}

	return result;
}

#include <math.h>

extern unsigned int opR1d_tickCount;	// NOTE: placeholder name (0xcaed20)

float opR1d_4371a0(float a, float b, int period, int offset)	// NOTE: placeholder name
{
	a = a + (float)((opR1d_tickCount + offset) % period) / period * (b - a) * 2;
	if (a > b)
	{
		a = b - (a - b);
	}

	return a;
}

float opR1d_437200(float a, float b, int duration, unsigned int start)	// NOTE: placeholder name
{
	return (b - a) * sin((float)(opR1d_tickCount - start) / duration * 3.14159265f) + a;
}

float opR1d_437250(float a, unsigned int start, int duration)	// NOTE: placeholder name
{
	if (opR1d_tickCount - start > duration)
	{
		return 0;
	}

	return a - sin((float)(opR1d_tickCount - start) / duration * 1.57079633f) * a;
}

float opR1d_4372b0(float a, float b, unsigned int start, int duration)	// NOTE: placeholder name
{
	if (opR1d_tickCount - start > duration)
	{
		return b;
	}

	return (a - b) - (a - b) * sin((float)(opR1d_tickCount - start) / duration * 1.57079633f) + b;
}

#include <stdlib.h>

bool opR1d_437360(int x1, int y1, int x2, int y2)	// NOTE: placeholder name
{
	return (abs(x2 - x1) == 1 || abs(y2 - y1) == 1) && abs(x2 - x1) < 2 && abs(y2 - y1) < 2;
}

struct Point
{
	int x;
	int y;

	bool adjacent(const Point &p) const;	// NOTE: placeholder name (PushGeometry::adjacent 0x409dd0)
	void serialize_40bf20(ostream &os);	// NOTE: placeholder name
};

int opR1d_4373f0(const Point &p, vector<Point> &points)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < points.size(); i++)
	{
		if (points[i].adjacent(p))
		{
			return i;
		}
	}

	return -1;
}

float OpY1_angle(int x1, int y1, int x2, int y2);	// NOTE: placeholder name

int opR1d_437440(int x1, int y1, int x2, int y2)	// NOTE: placeholder name
{
	if (x1 == x2 && y1 == y2)
	{
		return 8;
	}

	float angle = OpY1_angle(x1, y1, x2, y2);
	return angle >= 337.5 ? 0 : (int)((angle / 22.5 + 1) / 2);
}

#include <istream>

template <class T> void readBinary(istream &stream, T *value)	// NOTE: placeholder name
{
	stream.read((char*)value, sizeof(T));
}

void OpQ1_readString(istream &in, string *text);	// NOTE: placeholder name (0x4096f0)

class AsciiImage
{
public:
	AsciiImage() throw();	// 0x4588d0
	~AsciiImage();
	void read(istream &stream);	// 0x437560, NOTE: placeholder name

	vector<void*> layers;
};

class OpR1d_Entry	// NOTE: placeholder name
{
public:
	OpR1d_Entry(istream &stream);	// 0x438970

	int unknown0;
	string unknown4;
	string unknown20;
	int unknown3c;
	int unknown40;
	int unknown44;
	bool unknown48;
	int unknown4c;
	string unknown50;
	AsciiImage image;
};

OpR1d_Entry::OpR1d_Entry(istream &stream)
{
	readBinary(stream, &unknown0);
	OpQ1_readString(stream, &unknown4);
	OpQ1_readString(stream, &unknown20);
	readBinary(stream, &unknown3c);
	readBinary(stream, &unknown40);
	readBinary(stream, &unknown44);
	readBinary(stream, &unknown48);
	readBinary(stream, &unknown4c);
	OpQ1_readString(stream, &unknown50);
	image.read(stream);
}

#include <fstream>

extern string gameString_cfd42c;	// CUSTOM_FILE_PATH
extern string gameStrings_d230f8[];	// key names
void logError(string location, string message);	// NOTE: placeholder name
string &opR1d_padRight(string &s, unsigned int width, char c);	// NOTE: placeholder name (0x4080d0)

void logWarning(string location, string message);	// NOTE: placeholder name (0x404e50)
void logMessage(string message);	// NOTE: placeholder name (0x404cb0)
int stringToInt(const string &str);	// NOTE: placeholder name (0x405610)
void parseLine_408d70(string &text, vector<string> &out);	// NOTE: placeholder name
int OpT8a_findStringIndex(const string *list, unsigned int count, string s);	// NOTE: placeholder name
extern int OpS_indices_cec458[323];	// NOTE: placeholder name (0xcec458, active key mapping)

class Keyboard
{
public:
	void init();	// 0x438ad0
	void save();	// 0x439120

	bool modified;	// NOTE: placeholder name
	vector<int> keys;
};

void Keyboard::init()
{
	for (int i = 0; i < 0x143; i++)
		keys.push_back(i);
	ifstream file((gameString_cfd42c + "user/" + "keyboard.cfg").c_str());
	if (!file.is_open())
	{
		logWarning("Keyboard::init()","Unable to open " + (gameString_cfd42c + "user/" + "keyboard.cfg") + ", creating default keyboard settings");
		save();
	}
	else
	{
		string data;
		vector<string> rows;
		int j = 0;
		int total = 0;
		int val;
		int key;
		while (getline(file,data))
		{
			j++;
			rows.clear();
			parseLine_408d70(data,rows);
			if (rows.size() == 3)
			{
				val = stringToInt(rows[0]);
				key = OpT8a_findStringIndex(gameStrings_d230f8,0x143,rows[2]);
				if (key == -1)
					logError("Keyboard::init()","No key name found matching \"" + rows[2] + "\", ignoring key " + intToString(val));
				else
				{
					keys[val] = key;
					total++;
				}
			}
		}
		file.close();
		logMessage("...overwrote " + intToString(total) + " keys");
	}
	for (unsigned int i = 0; i < keys.size(); i++)
	{
		if (!modified && OpS_indices_cec458[i] != keys[i])
			modified = true;
		OpS_indices_cec458[i] = keys[i];
	}
}

void Keyboard::save()
{
	ofstream file((gameString_cfd42c + "user/" + "keyboard.cfg").c_str());
	if (!file.is_open())
	{
		logError("Keyboard::save()", "Unable to open " + (gameString_cfd42c + "user/" + "keyboard.cfg") + " for writing, keyboard layout not saved");
		return;
	}

	file << "// Default           Keyboard\n";
	string str;
	for (unsigned int i = 0; i < keys.size(); i++)
	{
		str = intToString(i);
		opR1d_padRight(str, 4, ' ');
		file << str;
		if (i != 0 && gameStrings_d230f8[i].find("NA_") == string::npos)
		{
			str = gameStrings_d230f8[i];
			opR1d_padRight(str, 17, ' ');
			file << str;
			str = gameStrings_d230f8[keys[i]];
			file << str;
		}
		file << "\n";
	}
	file.close();
}

struct OpR1d_KeyBinding	// NOTE: placeholder name (KeyBinding_4395b0 in team_a_11.cpp)
{
	int category;	// NOTE: placeholder name
	int command;	// NOTE: placeholder name
	string name;	// NOTE: placeholder name
	bool ctrl;	// NOTE: placeholder name
	bool shift;	// NOTE: placeholder name
	bool alt;	// NOTE: placeholder name
	int key;	// NOTE: placeholder name
};
extern string gameStrings_cfcdc0[];	// NOTE: placeholder name (command category names)
extern string gameStrings_cfe718[];	// NOTE: placeholder name (command names)

class Keybinds
{
public:
	void save();	// 0x43a840

	vector<OpR1d_KeyBinding*> bindings;	// NOTE: placeholder name
};

void Keybinds::save()
{
	ofstream file((gameString_cfd42c + "user/" + "commands.cfg").c_str());
	if (!file.is_open())
	{
		logError("Keybinds::save()","Unable to open " + (gameString_cfd42c + "user/" + "commands.cfg") + " for writing, keybinds not saved");
		return;
	}
	file << "// Command                              Name                            Ctrl    Shift   Alt     Key\n";
	int state = -1;
	string text;
	for (unsigned int i = 0; i < bindings.size(); i++)
	{
		if (state == -1 || bindings[i]->category != state)
		{
			state = bindings[i]->category;
			text = "[" + gameStrings_cfcdc0[state] + "]";
			opR1d_padRight(text,0x6e,'-');
			file << text << "\n";
		}
		text = gameStrings_cfe718[bindings[i]->command];
		opR1d_padRight(text,0x28,' ');
		file << text;
		text = "\"" + bindings[i]->name + "\"";
		opR1d_padRight(text,0x20,' ');
		file << text;
		text = bindings[i]->ctrl ? "Ctrl" : "-";
		opR1d_padRight(text,8,' ');
		file << text;
		text = bindings[i]->shift ? "Shift" : "-";
		opR1d_padRight(text,8,' ');
		file << text;
		text = bindings[i]->alt ? "Alt" : "-";
		opR1d_padRight(text,8,' ');
		file << text;
		file << gameStrings_d230f8[bindings[i]->key] << "\n";
	}
	file.close();
}

struct OpR1d_E38	// NOTE: placeholder name
{
	int unknown0;
};

class OpR1d_Report	// NOTE: placeholder name
{
public:
	OpR1d_Report();	// 0x43aee0

	int unknown0;
	string unknown4;
	char pad20[0x44];
	string unknown64;
	string unknown80;
	char pad9c[0x6c];
	vector<bool> unknown108;
	char pad11c[0xc];
	vector<OpR1d_E38> unknown128;
	vector<OpR1d_E38> unknown138;
	char pad148[0x108];
	ofstream unknown250;
};

OpR1d_Report::OpR1d_Report()
{
}

//==================================================================
// sound wrappers
//==================================================================

class SoundData;

struct Point2	// NOTE: placeholder name
{
	int x;
	int y;
};

int soundPlayRelative(const Point2 &pos, SoundData *sound, int channel, bool noPlay);	// NOTE: name from log string (0x4ff170)
int opY3_playSound(SoundData *sound, int channel, int fade, int loopsB, int loops);	// NOTE: placeholder name (0x4ff050)

extern vector<int *> opR1d_channels;	// NOTE: placeholder name (0xd2c34c)
extern vector<SoundData *> opR1d_sounds;	// NOTE: placeholder name (0xd2e9a0)

bool opR1d_454160(const Point2 &pos, SoundData *sound, unsigned int id)	// NOTE: placeholder name
{
	if (opR1d_channels[id])
	{
		return soundPlayRelative(pos, sound, *opR1d_channels[id], false) ? true : false;
	}

	return false;
}

int opR1d_4541b0(unsigned int sound, int loopsB, int loops)	// NOTE: placeholder name
{
	if (opR1d_sounds[sound])
	{
		return opY3_playSound(opR1d_sounds[sound], -1, 0, loopsB, loops);
	}

	return -1;
}

int opR1d_454200(unsigned int sound, unsigned int channel, int loopsB, int loops)	// NOTE: placeholder name
{
	if (opR1d_sounds[sound] && opR1d_channels[channel])
	{
		return opY3_playSound(opR1d_sounds[sound], channel, 0, loopsB, loops);
	}

	return -1;
}

int opR1d_454260(const Point2 &pos, unsigned int sound)	// NOTE: placeholder name
{
	if (opR1d_sounds[sound])
	{
		return soundPlayRelative(pos, opR1d_sounds[sound], -1, false);
	}

	return 0;
}

int opR1d_4542a0(const Point2 &pos, unsigned int sound, unsigned int channel)	// NOTE: placeholder name
{
	if (opR1d_sounds[sound] && opR1d_channels[channel])
	{
		return soundPlayRelative(pos, opR1d_sounds[sound], channel, false);
	}

	return 0;
}

//==================================================================
// list helpers
//==================================================================

class Predicate_409b90
{
public:
	int field0;
	int field4;
	bool test(const Predicate_409b90 & arg0);
};

class HAnim	// NOTE: placeholder name
{
public:
	void kill();	// 0x50e830
};

struct Pos;

class Particle
{
public:
	Pos *getPos();	// 0x462e10
};

template <class T> void removeVectorElement(vector<T> &v, int index);	// NOTE: placeholder name (0x9de6f0 for int)

class OpR1d_TrackedPos	// NOTE: placeholder name
{
public:
	bool unknown454bd0(int value, const Predicate_409b90 &pos);	// 0x454bd0

	int unknown0;
	char pad4[0xc];
	Predicate_409b90 unknown10;
};

bool OpR1d_TrackedPos::unknown454bd0(int value, const Predicate_409b90 &pos)
{
	return unknown0 == value && unknown10.test(pos);
}

class OpR1d_AnimList	// NOTE: placeholder name
{
public:
	void unknown454d90(int anim);	// 0x454d90
	void unknown454e20(const Predicate_409b90 &pos);	// 0x454e20

	char pad0[0x14];
	vector<int> anims;
	vector<int> removed;
};

void OpR1d_AnimList::unknown454d90(int anim)
{
	for (int i = anims.size() - 1; i >= 0; i--)
	{
		if (anims[i] == anim)
		{
			((HAnim *)anims[i])->kill();
			removed.push_back(anims[i]);
			removeVectorElement(anims, i);
			break;
		}
	}
}

void OpR1d_AnimList::unknown454e20(const Predicate_409b90 &pos)
{
	for (int i = anims.size() - 1; i >= 0; i--)
	{
		if (((Predicate_409b90 *)((Particle *)anims[i])->getPos())->test(pos))
		{
			((HAnim *)anims[i])->kill();
			removed.push_back(anims[i]);
			removeVectorElement(anims, i);
			break;
		}
	}
}

string opR1d_454ed0(char c, bool capital)	// NOTE: placeholder name
{
	switch (tolower(c))
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return string(capital ? "An" : "an");
		default:
			return string(capital ? "A" : "a");
	}
}

class OpR1d_Named	// NOTE: placeholder name
{
public:
	OpR1d_Named(const OpR1d_Named &other);	// 0x454fa0

	int unknown0;
	string unknown4;
	int unknown20;
	int unknown24;
};

OpR1d_Named::OpR1d_Named(const OpR1d_Named &other)
	: unknown0	(other.unknown0)
{
	unknown20 = other.unknown20;
	unknown24 = other.unknown24;
}

void OpQ1_writeString(ostream &out, string text);	// NOTE: placeholder name (0x409650)
void OpQ1_writeStringVector(ostream &out, vector<string> *list);	// NOTE: placeholder name (0x409770)
void OpQ1_readStringVector(istream &in, vector<string> *list);	// NOTE: placeholder name (0x4097e0)

template <class T> void writeBinary(ostream &stream, T *value)	// NOTE: placeholder name
{
	stream.write((char*)value, sizeof(T));
}

string opR1d_4550d0(int number)	// NOTE: placeholder name
{
	switch (number)
	{
		case 1: return string("one");
		case 2: return string("two");
		case 3: return string("three");
		case 4: return string("four");
		case 5: return string("five");
		case 6: return string("six");
		case 7: return string("seven");
		case 8: return string("eight");
		case 9: return string("nine");
		case 10: return string("ten");
		default: return string("many");
	}
}

class OpR1d_Phrase	// NOTE: placeholder name
{
public:
	OpR1d_Phrase(int a_, int b_, int c_, const string *s1, const string *s2, const string *s3);	// 0x455270
	OpR1d_Phrase(istream &stream);	// 0x455320
	void write(ostream &stream);	// 0x4553c0

	int a;
	int b;
	int c;
	vector<string> names;
};

OpR1d_Phrase::OpR1d_Phrase(int a_, int b_, int c_, const string *s1, const string *s2, const string *s3)
	: a	(a_)
	, b	(b_)
	, c	(c_)
{
	if (s1)
	{
		names.push_back(*s1);
	}
	if (s2)
	{
		names.push_back(*s2);
	}
	if (s3)
	{
		names.push_back(*s3);
	}
}

OpR1d_Phrase::OpR1d_Phrase(istream &stream)
{
	readBinary(stream, &a);
	readBinary(stream, &b);
	readBinary(stream, &c);
	OpQ1_readStringVector(stream, &names);
}

void OpR1d_Phrase::write(ostream &stream)
{
	writeBinary(stream, &a);
	writeBinary(stream, &b);
	writeBinary(stream, &c);
	OpQ1_writeStringVector(stream, &names);
}

class OpR1d_Replacer	// NOTE: placeholder name
{
public:
	void unknown455420(string &text, int number, const string &replacement);	// 0x455420
};

void OpR1d_Replacer::unknown455420(string &text, int number, const string &replacement)
{
	unsigned int pos = text.find('%' + intToString(number));
	if (pos != string::npos)
	{
		text.erase(pos, 2);
		text.insert(pos, replacement);
	}
}

class OpR1d_Grammar	// NOTE: placeholder name
{
public:
	void parseGrammar(string &text);	// 0x4554f0
};

void OpR1d_Grammar::parseGrammar(string &text)
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

//==================================================================
// deserializing records
//==================================================================

class OpR1d_Pair08	// NOTE: placeholder name
{
public:
	OpR1d_Pair08();	// 0x40bef0
	void load(istream &stream);	// 0x45f040

	int data[2];
};

class OpR1d_IntString	// NOTE: placeholder name
{
public:
	OpR1d_IntString(istream &stream);	// 0x4559a0

	int unknown0;
	string unknown4;
};

OpR1d_IntString::OpR1d_IntString(istream &stream)
{
	readBinary(stream, &unknown0);
	OpQ1_readString(stream, &unknown4);
}

class OpR1d_IntString2	// NOTE: placeholder name
{
public:
	OpR1d_IntString2(istream &stream);	// 0x455a20

	int unknown0;
	string unknown4;
	string unknown20;
};

OpR1d_IntString2::OpR1d_IntString2(istream &stream)
{
	readBinary(stream, &unknown0);
	OpQ1_readString(stream, &unknown4);
	OpQ1_readString(stream, &unknown20);
}

class OpR1d_PairRecord	// NOTE: placeholder name
{
public:
	OpR1d_PairRecord(istream &stream);	// 0x455ac0

	OpR1d_Pair08 unknown0;
	int unknown8;
	int unknownc;
	string unknown10;
};

OpR1d_PairRecord::OpR1d_PairRecord(istream &stream)
{
	unknown0.load(stream);
	readBinary(stream, &unknown8);
	readBinary(stream, &unknownc);
	OpQ1_readString(stream, &unknown10);
}

class OpR1d_PointRecord	// NOTE: placeholder name
{
public:
	void write(ostream &stream);	// 0x455b60

	Point unknown0;
	int unknown8;
	int unknownc;
	string unknown10;
};

void OpR1d_PointRecord::write(ostream &stream)
{
	unknown0.serialize_40bf20(stream);
	writeBinary(stream, &unknown8);
	writeBinary(stream, &unknownc);
	OpQ1_writeString(stream, unknown10);
}

//==================================================================
// condition comparisons
//==================================================================

int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)

class OpR1d_Condition	// NOTE: placeholder name
{
public:
	bool compareInt(int value);	// 0x455e00
	bool compareString(const string &value);	// 0x455f40

	char pad0[0x20];
	int mode;
	string operand;
};

bool OpR1d_Condition::compareInt(int value)
{
	switch (mode)
	{
		case 0: return value == stringToInt(operand);
		case 1: return value != stringToInt(operand);
		case 2: return value <= stringToInt(operand);
		case 3: return value >= stringToInt(operand);
		case 4: return value < stringToInt(operand);
		case 5: return value > stringToInt(operand);
		case 6: return value % stringToInt(operand) != 0;
		case 7: return value % stringToInt(operand) == 0;
	}

	return false;
}

bool OpR1d_Condition::compareString(const string &value)
{
	switch (mode)
	{
		case 0: return value == operand;
		case 1: return value != operand;
		case 2: return stringToInt(value) <= stringToInt(operand);
		case 3: return stringToInt(value) >= stringToInt(operand);
		case 4: return stringToInt(value) < stringToInt(operand);
		case 5: return stringToInt(value) > stringToInt(operand);
		case 6: return stringToInt(value) % stringToInt(operand) != 0;
		case 7: return stringToInt(value) % stringToInt(operand) == 0;
	}

	return false;
}
