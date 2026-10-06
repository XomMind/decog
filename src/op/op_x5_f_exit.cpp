// op_x5_f_exit: exitProgram() (0x9ad420) of COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <iostream>
#include "../engine/xcolor.h"
#include "../thirdparty/zfstream.h"
using namespace std;

struct Pos
{
	int x;
	int y;
};

struct Point
{
	int x;
	int y;

	Point(int x_, int y_);	// 0x46ca20
};

struct Rect
{
	int x;
	int y;
	int width;
	int height;

	Rect(int x_, int y_, int width_, int height_);	// 0x456940
	Rect(const Rect &rect);	// 0x40a720
};

class XConsole
{
public:
	virtual ~XConsole();

	int getWidth();
	int getHeight();
	void setChar_417f50(int x, int y, int ch);	// NOTE: placeholder name
	XColor getFore(int x, int y);	// NOTE: placeholder name
	XColor getBack(int x, int y);	// NOTE: placeholder name
	void setBack_417fc0(int x, int y, XColor color, int mode);	// NOTE: placeholder name
	void setBackAll_418410(XColor color);	// NOTE: placeholder name
	void setFore(XColor color);	// NOTE: placeholder name (0x417b00)
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Point &pos, int flag);	// NOTE: placeholder name

	char pad04[0x6c - 0x04];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, Rect rect, int font, bool hidden, int layer);
};

class REX	// NOTE: placeholder layout (0xd223f0)
{
public:
	int unknown418980();	// NOTE: placeholder name
	int unknown4189a0();	// NOTE: placeholder name
	XConsole *getConsole_4ab670();	// NOTE: placeholder name (folded getter)
	void renderRoot();	// 0x426c00
};
extern REX opx5f_rex;	// NOTE: placeholder name (0xd223f0)

class JLog
{
public:
	bool lastMessageFatal();	// NOTE: placeholder name
	int end(int type);	// NOTE: placeholder name
};
extern JLog *opx5f_jlog;	// NOTE: placeholder name (0xcefa64)

class OpX5F_Config	// NOTE: placeholder name (object at 0xd28c68)
{
public:
	void save(int index, int flag);	// NOTE: placeholder name (0x440450)
};
extern OpX5F_Config opx5f_config;	// NOTE: placeholder name (0xd28c68)

class GM
{
public:
	void serialize(bool a, bool b, bool c, bool d, bool e);	// NOTE: placeholder name (0x78c260)
};
extern GM *opx5f_gm;	// NOTE: placeholder name (0xcefaa8)

class GameMetaData
{
public:
	void serialize();	// NOTE: placeholder name
};
extern GameMetaData opx5f_gameMetaData;	// NOTE: placeholder name (0xd25628)

class LuigiAi
{
public:
	void cleanup();	// 0x434d50
};
extern LuigiAi opx5f_luigiAi;	// NOTE: placeholder name (0xcebffc)
extern bool opx5f_luigiAiActive;	// NOTE: placeholder name (0xcefb3e)

struct OpX5F_NetThread	// NOTE: placeholder name
{
	char pad00[0x1c];
	void *thread1c;
	char pad20[0x34 - 0x20];
	void *thread34;
};

class Network
{
public:
	static void threadQuitting(int threadType);
	static void deinit();
};
extern OpX5F_NetThread *opx5f_cefc58;	// NOTE: placeholder name
extern OpX5F_NetThread *opx5f_cefb5c;	// NOTE: placeholder name

extern "C" void SDL_KillThread(void *thread);
extern "C" void SDL_Delay(unsigned int milliseconds);

extern string gameString_cfd42c;	// CUSTOM_FILE_PATH
extern string opx5f_tutorialNames[0x57];	// NOTE: placeholder name (0xd32f00)
extern vector<int> opx5f_d22590;	// NOTE: placeholder name
extern bool opx5f_cefa77;	// NOTE: placeholder name
extern XColor opx5f_d29804;	// NOTE: placeholder name
extern XColor *opx5f_cfe674;	// NOTE: placeholder name
extern XColor *opx5f_d25f60;	// NOTE: placeholder name

void logInfo(string location, string message);	// NOTE: placeholder name (0x405090)
void logMessage(string message);	// NOTE: placeholder name (0x404cb0)
void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
void OpQ1_writeString(ostream &out, string text);	// NOTE: placeholder name (0x409650)
template <class T> void writeBinary(ostream &stream, T *value);	// NOTE: placeholder name
bool opr4a_unknown778220();	// NOTE: placeholder name
void opx5f_unknown466440();	// NOTE: placeholder name
void opx5f_unknowna44590();	// NOTE: placeholder name
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name (0x4541b0)

void exitProgram()
{
	if (opx5f_jlog->lastMessageFatal())
		return;
	logInfo("exitProgram()","Closing");
	opx5f_cefa77 = true;
	Console *screen = new Console(opx5f_rex.getConsole_4ab670(),Rect(0,0,opx5f_rex.unknown418980(),opx5f_rex.unknown4189a0()),0,false,0x1e);
	opx5f_rex.getConsole_4ab670()->unknown429fe0(screen,Point(0,0),0);
	for (int x = 0; x < screen->getWidth(); x++)
	{
		for (int y = 0; y < screen->getHeight(); y++)
		{
			screen->setChar_417f50(x,y,0x20);
			if (screen->getBack(x,y) == opx5f_d29804)
				screen->setBack_417fc0(x,y,screen->getFore(x,y) * 0.5f,1);
			else
				screen->setBack_417fc0(x,y,screen->getBack(x,y) * 0.5f,1);
		}
	}
	int centerY = screen->getHeight() / 2;
	Console *msg = new Console(screen,Rect(0,centerY,opx5f_rex.unknown418980() / 2,1),1,false,-1);
	msg->setBackAll_418410(*opx5f_d25f60);
	msg->setFore(*opx5f_cfe674);
	msg->printAligned(msg->getWidth() / 2,0,1,">>> SHUTDOWN PROCEDURE IN PROGRESS <<<");
	opx5f_rex.renderRoot();
	logMessage("Saving config");
	for (int i = 0; i < 3; i++)
		opx5f_config.save(i,0);
	logMessage("Saving tutorial records");
	gzofstream file((gameString_cfd42c + "user/" + "tut.bin").c_str(),ios::trunc | ios::binary);
	if (!file.is_open())
		logError("exitProgram()","Unable to open/create " + (gameString_cfd42c + "user/" + "tut.bin"));
	else
	{
		int count = 0x57;
		writeBinary(file,&count);
		for (int j = 0; j < 0x57; j++)
		{
			OpQ1_writeString(file,opx5f_tutorialNames[j]);
			writeBinary(file,&opx5f_d22590[j]);
		}
		file.close();
	}
	logMessage("Auto-saving game");
	if (opr4a_unknown778220())
		opx5f_gm->serialize(true,true,false,false,false);
	else
	{
		logMessage("(auto-save conditions not met)");
		logMessage("Saving game meta data");
		opx5f_gameMetaData.serialize();
	}
	if (opx5f_cefc58 != NULL && opx5f_cefc58->thread34 != NULL)
	{
		Network::threadQuitting(6);
		SDL_KillThread(opx5f_cefc58->thread34);
	}
	if (opx5f_cefb5c != NULL && opx5f_cefb5c->thread1c != NULL)
	{
		Network::threadQuitting(7);
		SDL_KillThread(opx5f_cefb5c->thread1c);
	}
	Network::deinit();
	logMessage("Cleaning up program before exit");
	opx5f_unknown466440();
	opR1d_4541b0(0x3a,0,0);
	SDL_Delay(0xdc);
	opx5f_unknowna44590();
	if (opx5f_luigiAiActive)
		opx5f_luigiAi.cleanup();
	opx5f_jlog->end(2);
}
