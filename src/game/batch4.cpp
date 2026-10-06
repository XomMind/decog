// Batch 4: assorted engine/game methods matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members and names are placeholders.
#include <string>
#include <vector>
#include <algorithm>
#include "../engine/xconsole.h"
using namespace std;

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
void logNotice(string location, string message);	// NOTE: placeholder name (0x404d20)
void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
string intToString(int value);	// NOTE: placeholder name
template <class T> void removeVectorElement(vector<T> &v, int index);	// NOTE: placeholder name

class Anim	// NOTE: placeholder name
{
public:
	char pad[0x24];
	int group;	// NOTE: placeholder name
};

class HAnim	// NOTE: placeholder name
{
public:
	int getGroup() { return anim->group; };
	void kill();	// 0x50e830
	bool update();	// 0x5045f0
	void stop();	// 0x504550
	Anim *anim;
};

class XTimer	// NOTE: placeholder name
{
public:
	void update();	// 0x4218e0
};

extern vector<string> animGroups;	// NOTE: placeholder name (0xcfcc5c)
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern bool noEngineTimeout;	// NOTE: placeholder name (0xcefbc6)

class Engine;
extern Engine *activeEngine;	// NOTE: placeholder name (0xcefc50)

// the animation list the engine's update code works on (the exe has it at two different offsets)
class AnimList	// NOTE: placeholder name
{
public:
	void stopAll();	// 0x5086c0

	vector<int> anims;	// NOTE: elements are HAnim pointers
	vector<int> dead;	// NOTE: placeholder name
	int pad20;
	int padc;
};

class Engine
{
public:
	bool update();
	void killGroup(string group);

	int pad0;
	int pad4;
	int pad8;
	int padc;
	int pad10;
	vector<int> anims;	// NOTE: elements are HAnim pointers
	vector<int> deadGroups;	// NOTE: placeholder name
};

void Engine::killGroup(string group)
{
	vector<string>::iterator it = find(animGroups.begin(),animGroups.end(),group);
	if (it == animGroups.end())
	{
		logError("Engine::killGroup()","Compendium does not contain group: " + group);
		return;
	}
	int groupID = it - animGroups.begin();
	for (int i = anims.size() - 1; i >= 0; i--)
	{
		if (((HAnim *)anims[i])->getGroup() == groupID)
		{
			((HAnim *)anims[i])->kill();
			deadGroups.push_back(anims[i]);
			removeVectorElement(anims,i);
		}
	}
}

// NOTE: the cast below stands in for the real class (this function's `this` is an AnimList)
#define ANIMS (((AnimList *)this)->anims)
#define DEAD (((AnimList *)this)->dead)
#define LASTTICK (*(unsigned int *)((char *)this + 0x20))
#define TIMER (*(XTimer *)((char *)this + 0x44))

bool Engine::update()
{
	if (!ANIMS.empty())
	{
		TIMER.update();
		if ((Engine *)this == activeEngine && tickCount - LASTTICK > 8000 && !noEngineTimeout)
		{
			logNotice("Engine::update()","Forcing engine timeout (" + intToString(8000) + "ms)");
			((AnimList *)this)->stopAll();
			return false;
		}
		for (int i = ANIMS.size() - 1; i >= 0; i--)
		{
			if (((HAnim *)ANIMS[i])->update())
			{
				DEAD.push_back(ANIMS[i]);
				removeVectorElement(ANIMS,i);
			}
		}
		return !ANIMS.empty();
	}
	return false;
}

class XCommandMgr	// NOTE: placeholder name
{
public:
	void addCommand(int domain, int command);

	vector< vector<int> > commands;	// NOTE: placeholder name; elements are XCommand pointers
};

class XCommand	// NOTE: placeholder name
{
public:
	bool equals(XCommand *other);	// 0x415e30
	string &getName() { return name; };	// 0x415ec0

	int pad0;
	string name;
};

void XCommandMgr::addCommand(int domain, int command)
{
	for (unsigned int i = 0; i < commands[domain].size(); i++)
	{
		if (((XCommand *)commands[domain][i])->equals((XCommand *)command))
		{
			logError("XCommandMgr::addCommand()","Existing command (\"" + ((XCommand *)commands[domain][i])->getName() + "\") has same definition as \"" + ((XCommand *)command)->getName() + "\"");
			return;
		}
	}
	commands[domain].push_back(command);
}

// NOTE: addCommand is 1 instruction off (the final "\"" literal operand compares against a neighbouring pool entry)

struct XBitmap	// NOTE: placeholder name
{
	int pad0;
	int pad4;
	int width;	// NOTE: placeholder name
	int height;	// NOTE: placeholder name
};

XBitmap *scaleBitmap(XBitmap *source, double scaleX, double scaleY, int mode);	// NOTE: placeholder name (0x4147e0)

class XFontData
{
public:
	void generateAutoscaled();
	void setBitmap(XBitmap *bitmap, int width, int height);	// NOTE: placeholder name (0x42efa0)

	char pad[0x20];
	XFontData *autoscaleSource;	// NOTE: placeholder name
	int autoscaleFactor;	// NOTE: placeholder name
	XBitmap *bitmap;	// NOTE: placeholder name
	int charWidth;	// NOTE: placeholder name
	int charHeight;	// NOTE: placeholder name
};

void XFontData::generateAutoscaled()
{
	if (bitmap == NULL)
	{
		if (autoscaleSource == NULL || autoscaleFactor == 0)
		{
			logFatal("XFontData::generateAutoscaled()","autoscaleSource or autoscaleFactor (" + intToString(autoscaleFactor) + ") invalid");
		}
		if (autoscaleSource->bitmap == NULL)
			autoscaleSource->generateAutoscaled();
		setBitmap(scaleBitmap(autoscaleSource->bitmap,autoscaleFactor,autoscaleFactor,0),autoscaleSource->bitmap->width / autoscaleSource->charWidth,autoscaleSource->bitmap->height / autoscaleSource->charHeight);
	}
}

class Config	// NOTE: placeholder name
{
public:
	bool breakConfigVar(const string &line, string &name, string &value, int lineNum, const string &file);
};

bool Config::breakConfigVar(const string &line, string &name, string &value, int lineNum, const string &file)
{
	char delimiter = '=';
	size_t pos = line.find(delimiter,0);
	if (pos == string::npos || pos == line.size() - 1)
	{
		logError("Config::breakConfigVar()","Syntax error in " + file + ", line " + intToString(lineNum));
		return false;
	}
	name.assign(line.begin(),line.begin() + pos);
	value.assign(line.begin() + pos + 1,line.end());
	return true;
}

extern string (*consoleToString)(XConsole *console);	// NOTE: placeholder name (0xcebc48)
void deleteVectorElement(vector<XConsole *> &v, int index);	// NOTE: placeholder name (0x9cea50)

void XConsole::removeSubconsole(XConsole *console)
{
	for (unsigned int i = 0; i < subconsoles.size(); i++)
	{
		if (subconsoles[i] == console)
		{
			deleteVectorElement(subconsoles,i);
			return;
		}
	}
	logError("XConsole::removeSubconsole()","Subconsole not found: " + consoleToString(console) + " (parent=" + (consoleToString != NULL ? consoleToString(this) : string("?")) + ")");
}
