// SDL_main (exe 0x9add00): COGMIND.cpp main(). extern "C" (SDL renames main), hence no EH frame.
// NOTE: placeholder names for every callee/global (file-unique, paired by exe address).
#include <string>
#include <vector>
#include <stdlib.h>
using std::string;
using std::vector;

string intToString(int);
int stringToInt(const string&);
bool OpY1_equalsNoCase(const string &a, const string &b);
string OpR5f_toUpper_4083a0(const string &text);
int OpQ1_findStringNoCase(const string *list, unsigned int count, const string &text);
string OpY1_rotateText(const string &text);
int ops7_clamp_9cdc80(int low, int value, int high);
void logMessage(string);
void logInfo(string);
void logInfo(string, string);
void logError(string location, string message);
void OpQ1_createDirectories(string path);
void OpQ4f_dataIntegrity_9adc80();
void exitProgram();
void c46_injectLayout_446390(int *rootWidth, int *rootHeight, int *fontHeight, int *fontWidth);
void opY3_unknown4fd460(int button, int state);
string unknown4b3330(void *console);
string unknown4b3370(void *console);
void OpW7_checkPreviousLog();
string teamA23_initDiscord_4534b0();
void opR1f_465f30();
bool opr1c_hasPtr_cebd5c();
int checkScoreReupload(void *data);
void *opY2_startNetworkThread(void *id, bool force, int (*fn)(void*), void *data);
namespace google { namespace protobuf { namespace internal {
void VerifyVersion(int headerVersion, int minLibraryVersion, const char* filename);
}}}

struct D2Color { D2Color(int r, int g, int b); D2Color(const D2Color&) throw(); int v; };
struct D2Font { string *name9c0790(); };
struct D2Rex {
	void initJLog(int minLevel, const string &header, void (*callback)(int level), bool flag);
	void init_4225f0(int argc, char **argv, int width, int height, int x, int y, string title, int fontType, void *fontList, bool noLog, bool useIcon, D2Color *iconKey, int f4_, bool f8_, void (*layout)(int *, int *, int *, int *), string resA, string resB, int fd8_, D2Color color);
	void setCaption(string title_, string icon_);
	void unknown4241a0(int limit);
	bool unknown424020(string *mode, bool flag);
	void unknown418aa0(vector<string> *names, bool all);
	void unknown418ba0(vector<int> *heights, bool all);
	int fontHeight48c360();
	int unknown4189e0();
	void setMouse44e6c0(void (*fn)(int, int));
	void setA(string (*fn)(void *));
	void setB(string (*fn)(void *));
	int desktopHeight44afb0();
	int desktopWidth9b6bf0();
	bool fullscreen404af0();
	bool unknown4188e0();
	int offsetY418900();
	int offsetX44a630();
	int unknown4189a0();
	int unknown418980();
	int unknown4189c0();
	D2Font *font459300();
	void run();
};
struct D2ResourceMgr {
	int p0;
	D2ResourceMgr(int argc, char *argv[], string organization, string appName);
	bool addResourcePath(string path, bool append);
};
struct D2Config { char p0[0x20]; bool f20; bool f21; bool f22; char p23[0x56-0x23]; bool f56; void init_43afa0(); };
struct D2Network { static void init(); };
struct D2Mouse { void setCursorHidden(bool hidden); };
struct D2FrameTimer { void setFramesPerSecond_41b070(unsigned int value); };
struct D2JLog { int end(int type); };
struct D2Clock { void start_416920(); };
struct D2Game { D2Game(); void initialize(); char p[0x24]; };
struct D2Struct471550 { D2Struct471550(); void init_4715a0(); char p[0x8c]; };
struct D2State { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void enter(); };

extern bool d2_cefb3d, d2_cefb36, d2_cefb34, d2_caed24, d2_cefad0, d2_ceface, d2_cefaee, d2_cefb2e, d2_cefb2f;
extern int d2_cefb44, d2_cefabc, d2_cefac0, d2_cefac4, d2_cefac8, d2_caf130, d2_cebd5c;
extern string d2_d2f508[12];
extern string d2_cf33fc, d2_d21928, d2_cfd42c, d2_d2a504, d2_d2d490;
extern string d2_d2a530[];
extern D2Rex d2_d223f0;
extern D2ResourceMgr *d2_cefa88;
extern void (*d2_cefa68)();
extern D2Config d2_d28c68;
extern string d2_d28c6c;
extern bool d2_d28c88, d2_d28c89, d2_d28c8a, d2_d28cbe, d2_d28d30;
extern int d2_d28cac, d2_d28cb4, d2_d28cb8;
extern D2Color *d2_cfe674;
extern char d2_ba6950[];
extern D2Mouse *d2_cefa94;
extern D2FrameTimer *d2_cefaa0;
extern D2JLog *d2_cefa64;
extern D2Game *d2_cefaa8;
extern D2Struct471550 *d2_cefc58;
extern D2Clock *d2_cefa9c;
extern D2State *d2_cec02c, *d2_cec028;
extern "C" int __cdecl SDL_EnableKeyRepeat(int delay, int interval);

extern "C" int SDL_main(int argc, char *argv[])
{
	string version = intToString(1);
	google::protobuf::internal::VerifyVersion(3005001, 3005000, "COGMIND.cpp");

	for (int i = 0; i < argc; i++)
	{
		string arg(argv[i]);
		if (OpY1_equalsNoCase(arg, "-noSpecialMode"))
			d2_cefb3d = true;
		else if (OpR5f_toUpper_4083a0(arg).find("-FORCEMODE:") != string::npos)
		{
			unsigned int pos = arg.find(':');
			if (pos != arg.size() - 1)
			{
				string mode(arg.begin() + pos + 1, arg.end());
				int idx = OpQ1_findStringNoCase(d2_d2f508, 12, mode);
				if (idx != -1)
					d2_cefb44 = idx;
				else
				{
					vector<string> names;
					for (int j = 0; j < 12; j++)
						names.push_back(OpR5f_toUpper_4083a0(d2_d2f508[j]));
					mode = OpR5f_toUpper_4083a0(mode);
					for (int j = 1; j < 12; j++)
					{
						if (names[j].find(mode) != string::npos)
						{
							d2_cefb44 = j;
							break;
						}
					}
				}
			}
		}
		else if (arg.find("-rpglikeOffset") != string::npos)
		{
			unsigned int pos = arg.find(':');
			if (pos != string::npos && pos < arg.size() - 1)
			{
				string value(arg.begin() + pos + 1, arg.end());
				d2_cefabc = ops7_clamp_9cdc80(0, abs(stringToInt(value)), 10);
			}
		}
		else if (arg.find("-player2Offset") != string::npos)
		{
			unsigned int pos = arg.find(':');
			if (pos != string::npos && pos < arg.size() - 1)
			{
				string value(arg.begin() + pos + 1, arg.end());
				d2_cefac0 = ops7_clamp_9cdc80(0, abs(stringToInt(value)), 10);
			}
		}
		else if (arg.find("-polymindOffset") != string::npos)
		{
			unsigned int pos = arg.find(':');
			if (pos != string::npos && pos < arg.size() - 1)
			{
				string value(arg.begin() + pos + 1, arg.end());
				d2_cefac4 = ops7_clamp_9cdc80(0, abs(stringToInt(value)), 10);
			}
		}
		else if (arg.find("-mapDialogueOffset") != string::npos)
		{
			unsigned int pos = arg.find(':');
			if (pos != string::npos && pos < arg.size() - 1)
			{
				string value(arg.begin() + pos + 1, arg.end());
				d2_cefac8 = ops7_clamp_9cdc80(0, abs(stringToInt(value)), 10);
			}
		}
		else if (OpY1_equalsNoCase(arg, "-" + OpY1_rotateText("PHOROENJY")))
			d2_cefb36 = true;
		else if (OpY1_equalsNoCase(arg, "-exportRobots"))
			d2_cefb34 = true;
		else if (OpY1_equalsNoCase(arg, "-singleThreadedData"))
			d2_caed24 = true;
	}

	d2_d223f0.initJLog(!d2_ceface, "Cogmind - " + d2_d21928 + " (build " + d2_cf33fc + ")", 0, d2_cefad0);
	logMessage("Initializing resources");
	d2_cefa88 = new D2ResourceMgr(argc, argv, "Grid Sage Games", "Cogmind");
	d2_cefa88->addResourcePath("cogmind", true);
	d2_cefa68 = OpQ4f_dataIntegrity_9adc80;
	OpQ1_createDirectories(d2_cfd42c + "user/");
	d2_d28c68.init_43afa0();
	D2Network::init();
	switch (d2_caf130) {}
	atexit(exitProgram);
	d2_d223f0.init_4225f0(argc, argv, 0, 0, 12, 12, string() + "data/fonts", 6, d2_ba6950, true, true, d2_cfe674, d2_d28c88 ? 1 : 0, d2_d28c89, c46_injectLayout_446390, "Grid Sage Games", "Cogmind", d2_d28cbe ? 2 : 1, D2Color(1, 1, 1));
	d2_d223f0.setCaption("Cogmind - " + d2_d21928, "Cogmind");
	if (opr1c_hasPtr_cebd5c())
		d2_d223f0.unknown4241a0(14);
	if (d2_d28c6c == d2_d2a504 || !d2_d223f0.unknown424020(&d2_d28c6c, false))
	{
		if (d2_d28c6c != d2_d2a504)
		{
			logError("main()", d2_cfd42c + "user/" + "system.cfg" + " specifies unrecognized font set: " + d2_d28c6c);
			d2_d28c6c = d2_d2a504;
		}
		vector<string> names;
		vector<int> heights;
		d2_d223f0.unknown418aa0(&names, false);
		d2_d223f0.unknown418ba0(&heights, false);
		int height = d2_d223f0.fontHeight48c360();
		for (unsigned int i = 0; i < heights.size(); i++)
		{
			if (heights[i] == height)
			{
				d2_d2d490 = d2_d28c6c = names[i];
				break;
			}
		}
		if (!d2_d223f0.unknown424020(&d2_d28c6c, false))
			logError("main()", "unable to load font set: " + d2_d28c6c);
	}
	else
		d2_d2d490 = d2_d28c6c;
	if (d2_d223f0.unknown4189e0() <= 10 && d2_d28d30)
		d2_d28d30 = false;
	if (d2_d28c8a)
		d2_cefa94->setCursorHidden(true);
	SDL_EnableKeyRepeat(d2_d28cb4, d2_d28cb8);
	d2_cefaa0->setFramesPerSecond_41b070(d2_d28cac);
	d2_d223f0.setMouse44e6c0(opY3_unknown4fd460);
	d2_d223f0.setA(unknown4b3330);
	d2_d223f0.setB(unknown4b3370);
	OpW7_checkPreviousLog();
	if (!d2_cefaee)
	{
		logInfo("Discord", "Initializing");
		logMessage(teamA23_initDiscord_4534b0());
		d2_cefa64->end(2);
	}
	opR1f_465f30();
	logInfo("Summarizing settings");
	logMessage("Desktop: " + intToString(d2_d223f0.desktopWidth9b6bf0()) + "x" + intToString(d2_d223f0.desktopHeight44afb0()));
	logMessage("Fullscreen: " + string(d2_d223f0.fullscreen404af0() ? (d2_d223f0.unknown4188e0() ? "Borderless" : "True") : "No"));
	logMessage("Offset: +" + intToString(d2_d223f0.offsetX44a630()) + ",+" + intToString(d2_d223f0.offsetY418900()));
	logMessage("Layout: " + d2_d2a530[d2_cebd5c]);
	logMessage("Root: " + intToString(d2_d223f0.unknown418980()) + "x" + intToString(d2_d223f0.unknown4189a0()));
	logMessage("Cell: " + intToString(d2_d223f0.unknown4189c0()) + "x" + intToString(d2_d223f0.unknown4189e0()));
	logMessage("Font: " + *d2_d223f0.font459300()->name9c0790());
	d2_cefa64->end(2);
	d2_cefaa8 = new D2Game();
	d2_cefaa8->initialize();
	d2_cefc58 = new D2Struct471550();
	d2_cefc58->init_4715a0();
	opY2_startNetworkThread((void *)2, false, checkScoreReupload, 0);
	d2_cefa9c->start_416920();
	if (d2_cefb2e || d2_cefb2f)
		d2_cec02c->enter();
	else
		d2_cec028->enter();
	d2_d223f0.run();
	return 0;
}
