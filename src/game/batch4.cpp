// Batch 4: assorted engine/game methods matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members and names are placeholders.
//
// Two different animation/particle engines live here (both own HAnim-style animation lists and a noise field):
//  * Engine (RTTI-less; dtor 0x454ca0, scalar dtor 0x48c6e0, ctor 0x50fa20): the per-console UI engine, anims at +0x14,
//    dead at +0x24, noise field at +0x34. killGroup (0x50fd90) belongs to it.
//  * EndObjB (global 0xcefc50, dtor 0x4548e0, pool of 20000 items): the gameplay-effects engine, anims at +0,
//    pool/dead at +0x10, lastTick at +0x20, noise field at +0x44. update (0x508710) and stopAll (0x5086c0) belong to it.
#include <string>
#include <vector>
#include <algorithm>
#include "../engine/xconsole.h"
using namespace std;

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
void logNotice(string location, string message);	// NOTE: placeholder name (0x404d20)
void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
string intToString(int value);	// NOTE: placeholder name
class EngineAnim;
class HAnim;
void removeVectorElement_9de6f0(vector<EngineAnim *> &v, int index);	// NOTE: placeholder name (0x9de6f0, same body as the mapped removeVectorElement<int>)
void removeVectorElement_9de6f0(vector<HAnim *> &v, int index);	// NOTE: placeholder name (0x9de6f0)

struct AnimInfo	// NOTE: placeholder name (the info record at the start of every animation object)
{
	char pad[0x24];
	int group;	// NOTE: placeholder name
};

// animation object of the console (UI) engine; see OpR2b_EngineAnim in op_r2_b.cpp (0xb4 bytes, ctor 0x454a80)
class EngineAnim	// NOTE: placeholder name
{
public:
	int getGroup() { return info->group; };
	void kill();	// 0x50e830

	AnimInfo *info;
};

// animation object of the gameplay-effects engine (0xb8 bytes, HAnim::stop 0x504550)
class HAnim	// NOTE: placeholder name
{
public:
	bool update();	// 0x5045f0
	void stop();	// 0x504550
};

// noise field (TCODNoise wrapper): layout and methods as in op_r1b.cpp (0x4218e0 shifts the field's offset every `seed` ms)
class OpR1b_NoiseField	// NOTE: placeholder name
{
public:
	void update();	// 0x4218e0

	int				dimensions;
	void			*noise;
	float			offset;
	float			scale;
	int				seed;
	unsigned int	startTick;
	float			*coords;
	int				octaves;
};

extern vector<string> animGroups;	// NOTE: placeholder name (0xcfcc5c)
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
extern bool noEngineTimeout;	// NOTE: placeholder name (0xcefbc6)

// the console (UI) engine
class Engine
{
public:
	void killGroup(string group);

	XConsole *console;	// NOTE: placeholder name
	Pos size;	// NOTE: placeholder name
	Pos offset;	// NOTE: placeholder name
	vector<EngineAnim *> anims;
	vector<EngineAnim *> deadGroups;	// NOTE: placeholder name
	OpR1b_NoiseField noise;
};

// the gameplay-effects engine, global 0xcefc50 (class defined elsewhere as EndObjB)
class EndObjB
{
public:
	bool update();	// 0x508710
	void stopAll();	// 0x5086c0

	vector<HAnim *> anims;
	vector<HAnim *> pool;
	unsigned int lastTick;	// NOTE: placeholder name
	char pad24[0x44 - 0x24];
	OpR1b_NoiseField noise;
};
extern EndObjB *endObjB;	// NOTE: placeholder name (0xcefc50)

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
		if (anims[i]->getGroup() == groupID)
		{
			anims[i]->kill();
			deadGroups.push_back(anims[i]);
			removeVectorElement_9de6f0(anims,i);
		}
	}
}

bool EndObjB::update()
{
	if (!anims.empty())
	{
		noise.update();
		if (this == endObjB && tickCount - lastTick > 8000 && !noEngineTimeout)
		{
			logNotice("Engine::update()","Forcing engine timeout (" + intToString(8000) + "ms)");
			stopAll();
			return false;
		}
		for (int i = anims.size() - 1; i >= 0; i--)
		{
			if (anims[i]->update())
			{
				pool.push_back(anims[i]);
				removeVectorElement_9de6f0(anims,i);
			}
		}
		return !anims.empty();
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
