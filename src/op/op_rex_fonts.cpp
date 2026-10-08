// op_rex_fonts: REX::loadFonts (0x4243e0), sets up the font types and loads every font set listed in
// <font dir>/_config.xt (or the autoscaled variants), then restores the previously selected set
// (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <ctype.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct PHYSFS_File;
namespace PhysFScpp
{
	class base_fstream
	{
	protected:
		PHYSFS_File * const file;
	public:
		base_fstream(PHYSFS_File *file);
		virtual ~base_fstream();
		bool isOpen_404af0();	// NOTE: placeholder name
	};

	class ifstream : public base_fstream, public std::istream
	{
	public:
		ifstream(string const &filename, std::ios_base::openmode mode = std::ios_base::in);
		virtual ~ifstream();
	};
}

struct OpRF_Def	// NOTE: placeholder name (font type definition, 0x10 bytes)
{
	int kind;	// 0 standard, 1 wide, 2 quad, 3 oct
	int pad04[2];
	int source;	// +0x0c, generatedSourceIndex
};

struct OpRF_FontInfo	// NOTE: placeholder name (REX::FontSetInfo, 0x40 bytes)
{
	OpRF_FontInfo();	// 0x425ab0
	~OpRF_FontInfo();	// 0x425ae0
	void init(const OpRF_Def *def);	// NOTE: placeholder name (0x42e7d0)
	int type;	// +0x00
	int width;
	int height;
	int unknownc;
	void *pad10[12];	// +0x10, NOTE: placeholder layout (three vectors; no char array, so /GS keeps the temporary out of the buffer area)
};

class XFontSet	// NOTE: partial layout (0x88 bytes)
{
public:
	XFontSet() {}	// 0x425b50 (Calls_425b50::delegate); defined trivially so LTCG proves it nothrow
	bool init_42f5e0(const string &name, const vector<string> &args, vector<string> &files, int mode, int count);	// NOTE: placeholder name
	bool initAutoscaled(const string &name, XFontSet *base, int scale, int mode, int count);	// 0x4318d0
	void generateAutoscaledAll();	// 0x431de0

	string name;	// +0x00
	char pad1c[0x2c - 0x1c];
	int cellWidth;	// +0x2c, NOTE: placeholder name
	int cellHeight;	// +0x30, NOTE: placeholder name
	char pad34[0x88 - 0x34];
};

class OpRF_ResourceMgr	// NOTE: placeholder name (XResourceMgr at 0xcefa88)
{
public:
	void getFileList(string dir, vector<string> *files, string ext);	// NOTE: placeholder name (0x415610)
};
extern OpRF_ResourceMgr *opRF_resources_cefa88;	// NOTE: placeholder name
class OpRF_JLog	// NOTE: placeholder name (JLog at 0xcefa64)
{
public:
	void end(int level);	// 0x410e50
};
extern OpRF_JLog *opRF_jlog_cefa64;	// NOTE: placeholder name
extern string opRF_fontTypeName_cfb854;	// NOTE: placeholder name

void logMessage(string message);	// 0x404cb0
void logInfo(string message);	// NOTE: placeholder name
void logError(string location, string message);	// 0x404f10
void logFatal(string location, string message);	// 0x404fd0
string intToString(int value);	// 0x4051f0
int stringToInt(const string &s);	// 0x405610
int charToDigit_405b40(char c);	// NOTE: placeholder name
bool OpY1_getEncodedLine(PhysFScpp::ifstream *file, string &line, int key);	// NOTE: placeholder name (0x4074b0)
void opRF_splitConfigLine_424380(string &line, vector<string> &parts);	// NOTE: placeholder name
template <class T> void OpG_clearObjects(vector<T *> &v);	// NOTE: placeholder name
void opRF_deleteBack(vector<XFontSet *> &v);	// NOTE: placeholder name (OpT8a_deleteBack)

class REX	// NOTE: placeholder layout
{
public:
	void loadFonts(int count, OpRF_Def *defs);
	void unknown425e10(int index, int a, int b, int c, int d);	// NOTE: placeholder name (as in op_r1b.cpp)
	void unknown425bb0();	// NOTE: placeholder name
	void video4230e0();	// NOTE: placeholder name

	char pad00[0x20];
	int desktopHeight;	// +0x20, NOTE: placeholder name
	char pad24[0x5c - 0x24];
	int cellWidth;	// +0x5c, NOTE: placeholder name
	int cellHeight;	// +0x60, NOTE: placeholder name
	char pad64[0x68 - 0x64];
	int scale;	// +0x68, NOTE: placeholder name
	char pad6c[0x7c - 0x6c];
	string fontPath;	// +0x7c
	char pad98[0x9c - 0x98];
	vector<OpRF_FontInfo> fontTypes;	// +0x9c
	vector<void *> unknownac;	// +0xac
	vector<XFontSet *> fontSets;	// +0xbc
	int fontSetIndex;	// +0xcc
	XFontSet *fontSet;	// +0xd0
	bool standardOnly;	// +0xd4, NOTE: placeholder name
	int mode;	// +0xd8, NOTE: placeholder name
};

void REX::loadFonts(int count, OpRF_Def *defs)
{
	string title;
	if (fontTypes.empty())
	{
		logMessage("Initializing font type data");
		standardOnly = true;
		fontTypes.assign(count,OpRF_FontInfo());
		for (int i = 0; i < count; i++)
		{
			fontTypes[i].init(&defs[i]);
			if (defs[i].kind != 0)
				standardOnly = false;
			if (defs[i].source != -1)
			{
				if (defs[i].kind != 2 && defs[i].kind != 3)
					logFatal("REX::loadFonts()","Cannot use " + opRF_fontTypeName_cfb854 + " to generate a non-QUAD/OCT font (index " + intToString(i) + ")");
				else if ((defs[i].kind == 2 && defs[defs[i].source].kind != 0) || (defs[i].kind == 3 && defs[defs[i].source].kind != 1))
					logFatal("REX::loadFonts()","Cannot use " + opRF_fontTypeName_cfb854 + " to generate a _QUAD/_OCT from a non-_STANDARD/_WIDE font (" + intToString(defs[i].source) + ")");
				else if (defs[i].source >= i)
					logFatal("REX::loadFonts()","generatedSourceIndex must refer to a font type prior to the QUAD/OCT (font type " + intToString(i) + ")");
			}
		}
		logMessage("Mapping standard ASCII values");
		for (unsigned int i = 0; i < fontTypes.size(); i++)
		{
			unknown425e10(i,0x20,0x40,0,0);
			unknown425e10(i,0x5b,0x60,1,1);
			unknown425e10(i,0x7b,0x7e,7,1);
			unknown425e10(i,0x41,0x5a,0,2);
			unknown425e10(i,0x61,0x7a,0,3);
		}
		logInfo("Loading fonts");
	}
	else
	{
		title = fontSet->name;
		cellWidth = fontSet->cellWidth;
		cellHeight = fontSet->cellHeight;
		OpG_clearObjects(unknownac);
		OpG_clearObjects(fontSets);
		logInfo("Reloading fonts");
	}
	vector<string> tags;
	opRF_resources_cefa88->getFileList(fontPath,&tags,"png");
	if (tags.empty())
		logFatal("REX::loadFonts()","No fonts found in \"" + fontPath + "\"");
	string last;
	vector<string> ranks;
	string line = fontPath + "/" + "_config.xt";
	PhysFScpp::ifstream w(line.c_str(),1);
	if (!w.isOpen_404af0())
		logFatal("REX::loadFonts()","Unable to open config file (" + line + ")");
	while (OpY1_getEncodedLine(&w,last,-1))
	{
		if (!last.empty() && last[0] != '/')
		{
			ranks.clear();
			opRF_splitConfigLine_424380(last,ranks);
			if (ranks.size() == 2)
			{
				if (fontSets.empty())
					logFatal("REX::loadFonts()","Default font cannot be autoscaled (\"" + ranks[1] + "\")");
				ranks[1].erase(0,1);
				ranks[1].pop_back();
				int factor = charToDigit_405b40(ranks[1].back());
				ranks[1].pop_back();
				ranks[1].pop_back();
				string base(ranks[1]);
				for (unsigned int j = 0; j < fontSets.size(); j++)
				{
					if (fontSets[j]->name == base)
					{
						fontSets.push_back(new XFontSet());
						if (!fontSets.back()->initAutoscaled(ranks.front(),fontSets[j],factor,mode,count))
						{
							logError("REX::loadFonts()","Unable to load font set \"" + ranks.front() + "\"");
							opRF_deleteBack(fontSets);
						}
						goto found;
					}
				}
				logError("REX::loadFonts()","Unable to find scaled font source: \"" + base + "\"");
	found:
				;
			}
			else if (ranks.size() != count + count * 2 + 4)
				logFatal("REX::loadFonts()","Incorrect font config data count in line: \"" + last + "\"");
			else if (fontSets.empty() || stringToInt(ranks.back()))
			{
				if (!fontSets.empty() && mode == 0)
				{
					int resolution = 0;
					unsigned int pos = ranks[1].rfind('x',string::npos);
					if (pos != string::npos)
					{
						string digits;
						pos++;
						while (ranks[1].size() > pos)
						{
							if (isdigit(ranks[1][pos]))
								digits += ranks[1][pos];
							else
								break;
							pos++;
						}
						if (!digits.empty())
							resolution = stringToInt(digits);
					}
					if (resolution * scale > desktopHeight)
					{
						logMessage("[font set ignored: " + ranks.front() + "] (resolution exceeds desktop)");
						continue;
					}
				}
				fontSets.push_back(new XFontSet());
				if (!fontSets.back()->init_42f5e0(ranks.front(),vector<string>(ranks.begin() + 1,ranks.end() - 1),tags,mode,count))
				{
					if (fontSets.size() == 1)
						logFatal("REX::loadFonts()","Unable to load default font set (" + ranks.front() + ") (or any font sets if this is not the intended default)");
					else
					{
						logError("REX::loadFonts()","Unable to load font set \"" + ranks.front() + "\"");
						opRF_deleteBack(fontSets);
					}
				}
			}
			else
				logMessage("[font set skipped: " + ranks.front() + "] (unavailable)");
		}
	}
	if (fontSets.empty())
		logFatal("REX::loadFonts()","Unable to load any fonts");
	unknown425bb0();
	opRF_jlog_cefa64->end(2);
	fontSet = NULL;
	if (!title.empty())
	{
		for (unsigned int k = 0; k < fontSets.size(); k++)
		{
			if (fontSets[k]->name == title)
			{
				fontSetIndex = k;
				fontSet = fontSets[fontSetIndex];
				break;
			}
		}
	}
	if (!fontSet)
	{
		fontSetIndex = 0;
		fontSet = fontSets[fontSetIndex];
	}
	fontSet->generateAutoscaledAll();
	if (fontSet->cellWidth != cellWidth || fontSet->cellHeight != cellHeight)
		video4230e0();
}
