// alpha2_19: XFontSet::init (0x42f5e0): loads a font set's mirror and UTF8 tables, then each of its fonts
//	(copied, AUTO-generated from a source type, "<...>"-scaled, or loaded from a .png charmap) and checks sizes.
// NOTE: placeholder names / placeholder layout; stream declarations follow src/util/loop_charlie_41_settings.cpp.
#include <string>
#include <vector>
#include <istream>
using namespace std;
struct PHYSFS_File;
namespace PhysFScpp
{
	class base_fstream
	{
	protected:
		PHYSFS_File *const file;
	public:
		base_fstream(PHYSFS_File *);
		virtual ~base_fstream();
		bool isOpen_404af0() throw();
	};
	class ifstream : public base_fstream, public std::istream
	{
	public:
		ifstream(const string &, ios_base::openmode = ios_base::in);
		virtual ~ifstream();
		void close9c05e0() throw();
	};
}

struct A2FFontInfo	// REX::FontSetInfo, 0x40 bytes
{
	int type;	// +0x00
	int cols;	// +0x04
	int rows;	// +0x08
	int source;	// +0x0c
	int f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
};
struct A2FFont	// XFont
{
	A2FFont(A2FFontInfo *info = 0, const string &name = "", A2FFont *source = 0, int scale = 1);	// 0x416ad0
	int getWidth_416b70() throw();
	int getHeight_416bb0() throw();
	bool loadCharmap_416c40(A2FFontInfo *info, string file, int a, int b);
	string name;	// +0x00
	A2FFontInfo *info;	// +0x1c
	A2FFont *source;	// +0x20
	int scale;	// +0x24
	char pad28[0x4c - 0x28];
};
struct A2FRex	// REX
{
	A2FFont *findFont_425d50(string *name, int scale, A2FFontInfo *info);
	char pad0[0x9c];
	vector<A2FFontInfo> fontSets;	// +0x9c
	vector<A2FFont *> fonts;	// +0xac
};
extern A2FRex a2f_rex_d223f0;
extern string a2f_fontDir_d2246c;
extern string a2f_auto_cfb854;
extern int a2f_widthScale_b8cf18[];
extern int a2f_heightScale_b8cf28[];

void a2f_logMessage_404cb0(string message);
void a2f_logError_404f10(string location, string message);
string a2f_intToString_4051f0(int value);
int a2f_stringToInt_405610(const string &text);
unsigned int a2f_stringToUnsigned_405690(const string &text);
int a2f_charToDigit_405b40(char c);
bool a2f_getEncodedLine_4074b0(PhysFScpp::ifstream *file, string &line, int key);
void a2f_parseLine_408d70(const string &line, vector<string> &tokens);
int a2f_findString_9d57d0(vector<string> &list, string s);
bool a2f_checkFontSetFits_42f530(int cols, int rows, int mode, bool *removed);

class A2FFontSet	// XFontSet
{
public:
	bool init(const string &name_, vector<string> &list, vector<string> *files, int mode, int count);

	string name;	// +0x00
	vector<A2FFont *> fonts;	// +0x1c
	int width;	// +0x2c
	int height;	// +0x30
	bool removed;	// +0x34
	vector<unsigned int> utf8;	// +0x38
	vector<int> mirrorA;	// +0x48
	vector<int> mirrorB;	// +0x58
	vector<int> mirrorC;	// +0x68
	vector<int> mirrorD;	// +0x78
};

bool A2FFontSet::init(const string &name_, vector<string> &list, vector<string> *files, int mode, int count)
{
	name = name_;
	removed = false;
	a2f_logMessage_404cb0("[font set: " + name + "]");
	string line;
	vector<string> tags;
	int total = 0;
	if (list.back() != "-")
	{
		string path = a2f_fontDir_d2246c + "/" + list.back() + ".txt";
		PhysFScpp::ifstream res(path.c_str());
		if (!res.isOpen_404af0())
			a2f_logError_404f10("XFontSet::init()","Could not find mirror file for font \"" + name + "\": " + path + " (will have no mirror support for it)");
		else
		{
			while (a2f_getEncodedLine_4074b0(&res,line,-1))
			{
				int x, y;	// NOTE: unused in the exe too (two stack slots)
				total++;
				tags.clear();
				a2f_parseLine_408d70(line,tags);
				if (!tags.empty())
				{
					if (tags.size() != 3)
						a2f_logError_404f10("XFontSet::init()",path + " contains incorrect data count in line " + a2f_intToString_4051f0(total) + ", skipping (expected 3 values, found " + a2f_intToString_4051f0(tags.size()) + ")");
					else if (tags[0][0] == 'h')
					{
						mirrorA.push_back(a2f_stringToInt_405610(tags[1]));
						mirrorB.push_back(a2f_stringToInt_405610(tags[2]));
						mirrorA.push_back(a2f_stringToInt_405610(tags[2]));
						mirrorB.push_back(a2f_stringToInt_405610(tags[1]));
					}
					else
					{
						mirrorC.push_back(a2f_stringToInt_405610(tags[1]));
						mirrorD.push_back(a2f_stringToInt_405610(tags[2]));
						mirrorC.push_back(a2f_stringToInt_405610(tags[2]));
						mirrorD.push_back(a2f_stringToInt_405610(tags[1]));
					}
				}
			}
			res.close9c05e0();
		}
	}
	list.pop_back();
	if (list.back() != "-")
	{
		string text = a2f_fontDir_d2246c + "/" + list.back() + ".txt";
		PhysFScpp::ifstream input(text.c_str());
		if (!input.isOpen_404af0())
			a2f_logError_404f10("XFontSet::init()","Could not find UTF8 file for font \"" + name + "\": " + text + " (will have no UTF8 export support for it)");
		else
		{
			while (a2f_getEncodedLine_4074b0(&input,line,-1))
			{
				total++;
				tags.clear();
				a2f_parseLine_408d70(line,tags);
				if (!tags.empty())
				{
					if (tags.size() < 2)
						a2f_logError_404f10("XFontSet::init()",text + " contains incorrect data count in line " + a2f_intToString_4051f0(total) + ", skipping (expected 2 values, found " + a2f_intToString_4051f0(tags.size()) + ")");
					else
					{
						unsigned int a = a2f_stringToUnsigned_405690(tags[0]);
						unsigned int b = a2f_stringToUnsigned_405690(tags[1]);
						if (a >= utf8.size())
						{
							for (unsigned int j = utf8.size(); j < a + 1; j++)
								utf8.push_back(63);
						}
						utf8[a] = b;
					}
				}
			}
			input.close9c05e0();
		}
	}
	list.pop_back();
	if (list.size() % 3 != 0)
		a2f_logError_404f10("XFontSet::init()","Font values not a multiple of three, missing data");
	for (unsigned int i = 0, k = 0; i < list.size(); i += 3, k++)
	{
		if (list[i] == a2f_auto_cfb854)
		{
			if (a2f_rex_d223f0.fontSets[k].source == -1)
			{
				a2f_logError_404f10("XFontSet::init()","Used " + a2f_auto_cfb854 + " keyword on a font type with no specified generatedSourceIndex, only applicable to QUAD/OCT fonts");
				return false;
			}
			string item(fonts[a2f_rex_d223f0.fontSets[k].source]->name);
			int depth = fonts[a2f_rex_d223f0.fontSets[k].source]->scale * 2;
			A2FFont *first = a2f_rex_d223f0.findFont_425d50(&item,depth,&a2f_rex_d223f0.fontSets[k]);
			if (first)
			{
				fonts.push_back(first);
				a2f_logMessage_404cb0("..." + item + " (copied)");
			}
			else
			{
				a2f_rex_d223f0.fonts.push_back(new A2FFont(&a2f_rex_d223f0.fontSets[k],item,fonts[a2f_rex_d223f0.fontSets[k].source]->source ? fonts[a2f_rex_d223f0.fontSets[k].source]->source : fonts[a2f_rex_d223f0.fontSets[k].source],depth));
				fonts.push_back(a2f_rex_d223f0.fonts.back());
				a2f_logMessage_404cb0("..." + item + " (AUTO*" + a2f_intToString_4051f0(fonts.back()->scale) + ")");
			}
		}
		else if (list[i][0] == '<')
		{
			list[i].erase(0,1);
			list[i].pop_back();
			int depth = a2f_charToDigit_405b40(list[i].back());
			if (depth > 9)
			{
				a2f_logError_404f10("XFontSet::init()","Scaling beyond a factor of 9 not currently supported (" + list[i] + ")");
				return false;
			}
			list[i].pop_back();
			list[i].pop_back();
			string source(list[i]);
			A2FFont *node = a2f_rex_d223f0.findFont_425d50(&source,depth,&a2f_rex_d223f0.fontSets[k]);
			if (node)
			{
				fonts.push_back(node);
				a2f_logMessage_404cb0("..." + source + " (copied)");
			}
			else
			{
				node = a2f_rex_d223f0.findFont_425d50(&source,1,&a2f_rex_d223f0.fontSets[k]);
				if (node)
				{
					a2f_rex_d223f0.fonts.push_back(new A2FFont(&a2f_rex_d223f0.fontSets[k],source,node,depth));
					fonts.push_back(a2f_rex_d223f0.fonts.back());
					a2f_logMessage_404cb0("..." + source + " (*" + a2f_intToString_4051f0(fonts.back()->scale) + ")");
				}
				else
				{
					a2f_logError_404f10("XFontSet::init()","Unable to find " + source + " among same type for source-specific scaling");
					return false;
				}
			}
		}
		else
		{
			A2FFont *font = a2f_rex_d223f0.findFont_425d50(&list[i],1,&a2f_rex_d223f0.fontSets[k]);
			if (font)
			{
				fonts.push_back(font);
				a2f_logMessage_404cb0("..." + list[i] + " (copied)");
			}
			else
			{
				list[i] += ".png";
				if (a2f_findString_9d57d0(*files,list[i]) == -1)
				{
					a2f_logError_404f10("XFontSet::init()","Could not find font \"" + list[i] + "\"");
					return false;
				}
				a2f_rex_d223f0.fonts.push_back(new A2FFont());
				fonts.push_back(a2f_rex_d223f0.fonts.back());
				if (fonts.back()->loadCharmap_416c40(&a2f_rex_d223f0.fontSets[k],list[i],a2f_stringToInt_405610(list[i + 1]),a2f_stringToInt_405610(list[i + 2])))
					a2f_logMessage_404cb0("..." + list[i]);
				else
				{
					a2f_logError_404f10("XFontSet::init()","Could not load font \"" + list[i] + "\"");
					return false;
				}
			}
		}
		if (i == 0)
		{
			width = fonts[0]->getWidth_416b70();
			height = fonts[0]->getHeight_416bb0();
			if (!a2f_checkFontSetFits_42f530(width,height,mode,&removed))
				return false;
		}
		if (fonts.back()->source)
		{
			if (a2f_rex_d223f0.fontSets[k].cols != fonts.back()->source->info->cols || a2f_rex_d223f0.fontSets[k].rows != fonts.back()->source->info->rows)
			{
				a2f_logError_404f10("XFontSet::init()","Scaled font \"" + list[i] + "\" does not share same col/row count as source: " + a2f_intToString_4051f0(fonts.back()->source->info->cols) + "x" + a2f_intToString_4051f0(fonts.back()->source->info->rows));
				return false;
			}
		}
		else if (fonts.back()->getWidth_416b70() != width * a2f_widthScale_b8cf18[a2f_rex_d223f0.fontSets[k].type] || fonts.back()->getHeight_416bb0() != height * a2f_heightScale_b8cf28[a2f_rex_d223f0.fontSets[k].type])
		{
			a2f_logError_404f10("XFontSet::init()","Font image \"" + list[i] + "\" does not have required dimensions for col/row specifications: " + a2f_intToString_4051f0(width * a2f_widthScale_b8cf18[a2f_rex_d223f0.fontSets[k].type]) + "x" + a2f_intToString_4051f0(height * a2f_heightScale_b8cf28[a2f_rex_d223f0.fontSets[k].type]));
			return false;
		}
	}
	return true;
}
