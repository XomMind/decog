// op_u5_s2: assorted functions in 0x78c050-0x793700 (placeholder names)
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "thirdparty/zfstream.h"
#include "util/stringutil.h"
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	void set(unsigned char r_, unsigned char g_, unsigned char b_);
	void set(const XColor &color);
};

struct HProp
{
	int ID;
	HProp() throw();
};

class Entity;

struct HEntity
{
	int ID;
	HEntity() throw();
	Entity *operator->() const;	// 0x9b6570
};

bool showMessage(int type, const string &text, int a, int b, HEntity entity, HProp prop, int c, int d);	// 0x5111e0

class OpU5s2_Messages	// NOTE: placeholder name (0xcec058)
{
public:
	void unknown8758d0(int flag);	// NOTE: placeholder name
};

class OpU5s2_LogMsgs	// NOTE: placeholder name (CLogMsgs)
{
public:
	void scrollToEnd();	// 0x7b4f10
};

class OpU5s2_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	int unknown463e50();	// NOTE: placeholder name
};

int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name

extern bool opU5s2_flagD28d09;	// NOTE: placeholder name
extern vector<int> opU5s2_shownD22590;	// NOTE: placeholder name
extern OpU5s2_World *opU5s2_world;	// NOTE: placeholder name (0xcefc4c)
extern OpU5s2_Messages *opU5s2_messages;	// NOTE: placeholder name (0xcec058)
extern OpU5s2_LogMsgs *opU5s2_logMsgs;	// NOTE: placeholder name (0xcec0b4)
extern OpU5s2_LogMsgs *opU5s2_logMsgs2;	// NOTE: placeholder name (0xcec0c4)

class OpU5s2_Unk793450	// NOTE: placeholder name
{
public:
	bool showOnce(int id, bool enabled, const string &text, bool repeat, bool flag);	// NOTE: placeholder name (0x793450)
};

bool OpU5s2_Unk793450::showOnce(int id, bool enabled, const string &text, bool repeat, bool flag)
{
	if (enabled && opU5s2_flagD28d09 && (repeat || opU5s2_shownD22590[id] == 0) && opU5s2_world && (opU5s2_world->unknown463e50() == 2 || opU5s2_world->unknown463e50() == 1))
	{
		if (flag)
		{
			do
			{
				if (showMessage(id + 0x32d,text,0,0,HEntity(),HProp(),0,1))
					opU5s2_messages->unknown8758d0(0);
				opU5s2_logMsgs2->scrollToEnd();
			} while (false);
		}
		else
		{
			do
			{
				if (showMessage(id + 0x32d,text,0,0,HEntity(),HProp(),0,0))
					opU5s2_messages->unknown8758d0(1);
				opU5s2_logMsgs->scrollToEnd();
			} while (false);
		}
		opR1d_4541b0(0x22,0,0);
		opU5s2_shownD22590[id] = 1;
		return true;
	}
	return false;
}

//==================================================================
// Record creation (handle pools)
//==================================================================
// NOTE: all names below are placeholders; each pool's add() is folded in the exe with 0x9d1b20
template <class T, class H> struct OpU5s2_Pool
{
	H add(T *item);
};

struct OpU5s2_HA;
struct OpU5s2_ObjA
{
	void setHandle(OpU5s2_HA h);	// 0x4582d0
};
struct OpU5s2_HA
{
	int ID;
	OpU5s2_ObjA *operator->() const;	// 0x9b64d0
};
struct OpU5s2_RecA;
extern OpU5s2_Pool<OpU5s2_RecA,OpU5s2_HA> opU5s2_poolA;	// 0xd20404

struct OpU5s2_HB;
struct OpU5s2_ObjB
{
	void setHandle(OpU5s2_HB h);	// 0x45e5f0
};
struct OpU5s2_HB
{
	int ID;
	OpU5s2_ObjB *operator->() const;	// 0x9b7910
};
struct OpU5s2_RecB
{
	char pad00[0x64];
	OpU5s2_RecB() throw();	// 0x46eb20
};
extern OpU5s2_Pool<OpU5s2_RecB,OpU5s2_HB> opU5s2_poolB;	// 0xd33888

struct OpU5s2_HC;
struct OpU5s2_ObjC
{
	void setHandle(OpU5s2_HC h);	// 0x45e5f0
};
struct OpU5s2_HC
{
	int ID;
	OpU5s2_ObjC *operator->() const;	// 0x9b7cd0
};
struct OpU5s2_RecC
{
	char pad00[0x18];
	OpU5s2_RecC() throw();	// 0x461390
};
extern OpU5s2_Pool<OpU5s2_RecC,OpU5s2_HC> opU5s2_poolC;	// 0xd2f288

struct OpU5s2_HF;
struct OpU5s2_ObjF
{
	void setHandle(OpU5s2_HF h);	// 0x45e5f0
};
struct OpU5s2_HF
{
	int ID;
	OpU5s2_ObjF *operator->() const;	// 0x9b7250
};
struct OpU5s2_RecF;
extern OpU5s2_Pool<OpU5s2_RecF,OpU5s2_HF> opU5s2_poolF;	// 0xcfac14

struct OpU5s2_EntityRecord;
class Entity
{
	char pad00[0x148];
public:
	Entity(OpU5s2_EntityRecord *record_);	// 0x5c3590
	void init(HEntity self);	// 0x5c4640
};
extern OpU5s2_Pool<Entity,HEntity> opU5s2_entityPool;	// 0xd21720

struct OpU5s2_HD;
struct OpU5s2_ObjD
{
	char pad00[0x78];
	OpU5s2_ObjD(int *p);	// 0x571590
	void init(OpU5s2_HD h);	// 0x571820
};
struct OpU5s2_HD
{
	int ID;
	OpU5s2_ObjD *operator->() const;	// 0x9b65b0
};
extern OpU5s2_Pool<OpU5s2_ObjD,OpU5s2_HD> opU5s2_poolD;	// 0xd2a298

struct OpU5s2_HE;
struct OpU5s2_ObjE
{
	char pad00[0x50];
	OpU5s2_ObjE(int *p);	// 0x65d4c0
	void init(OpU5s2_HE h);	// 0x65d660
};
struct OpU5s2_HE
{
	int ID;
	OpU5s2_ObjE *operator->() const;	// 0x9b64f0
};
extern OpU5s2_Pool<OpU5s2_ObjE,OpU5s2_HE> opU5s2_poolE;	// 0xd1e720

class OpU5s2_Factory	// NOTE: placeholder name
{
public:
	OpU5s2_HA createA(OpU5s2_RecA *rec);	// 0x7930e0
	OpU5s2_HB createB();	// 0x793120
	OpU5s2_HC createC();	// 0x793190
	HEntity createEntity(OpU5s2_EntityRecord *record);	// 0x793200
	OpU5s2_HD createD(int *data);	// 0x7932b0
	OpU5s2_HE createE(int *data);	// 0x793360
	OpU5s2_HF createF(OpU5s2_RecF *rec);	// 0x793410
};

OpU5s2_HA OpU5s2_Factory::createA(OpU5s2_RecA *rec)
{
	OpU5s2_HA h = opU5s2_poolA.add(rec);
	h->setHandle(h);
	return h;
}

OpU5s2_HB OpU5s2_Factory::createB()
{
	OpU5s2_RecB *rec = new OpU5s2_RecB();
	OpU5s2_HB h = opU5s2_poolB.add(rec);
	h->setHandle(h);
	return h;
}

OpU5s2_HC OpU5s2_Factory::createC()
{
	OpU5s2_RecC *rec = new OpU5s2_RecC();
	OpU5s2_HC h = opU5s2_poolC.add(rec);
	h->setHandle(h);
	return h;
}

HEntity OpU5s2_Factory::createEntity(OpU5s2_EntityRecord *record)
{
	HEntity h = opU5s2_entityPool.add(new Entity(record));
	h->init(h);
	return h;
}

OpU5s2_HD OpU5s2_Factory::createD(int *data)
{
	OpU5s2_HD h = opU5s2_poolD.add(new OpU5s2_ObjD(data));
	h->init(h);
	return h;
}

OpU5s2_HE OpU5s2_Factory::createE(int *data)
{
	OpU5s2_HE h = opU5s2_poolE.add(new OpU5s2_ObjE(data));
	h->init(h);
	return h;
}

OpU5s2_HF OpU5s2_Factory::createF(OpU5s2_RecF *rec)
{
	OpU5s2_HF h = opU5s2_poolF.add(rec);
	h->setHandle(h);
	return h;
}

//==================================================================
// Manual line wrapping
//==================================================================
struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
};

class XConsole
{
public:
	void clear();
	int printWrapped_418260(int x, int y, int width, int height, const string &text);	// NOTE: placeholder name
	string getString(const Pos &p, unsigned int length);
	void removeSubconsole(XConsole *console);

	char pad00[0x6c];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
};

struct OpU5s2_ManualSection	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	string title;	// NOTE: placeholder name
	vector<string> lines;	// NOTE: placeholder name
	vector<int> headers;	// NOTE: placeholder name
};
extern vector<OpU5s2_ManualSection*> opU5s2_manualSections;	// NOTE: placeholder name (0xcf39dc)
extern XConsole *opU5s2_rootConsole;	// NOTE: placeholder name (0xcec034)

bool OpU5s2_contains(vector<int> &values, int value);	// NOTE: placeholder name (0x9db330)
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name
void OpU8a_insertString(vector<string> &v, int index, string s);	// NOTE: placeholder name (0x9d4440)

class JLog
{
public:
	int end(int type);
};
extern JLog *opU5s2_jlog;	// NOTE: placeholder name (0xcefa64)

class XStartupProgress
{
public:
	void addLine(const string &line, bool draw);
};
extern XStartupProgress *opU5s2_startupProgress;	// NOTE: placeholder name (0xcefa7c)

class GM
{
public:
	void unknown7908d0();	// NOTE: placeholder name (wraps manual lines)
	void loadManual(const string &path);	// 0x78fb80
	void loadDataset();	// 0x790e50
	bool unknown7913f0(const string &path, vector<string> *list, vector<string> *list2);	// NOTE: placeholder name
};

void GM::unknown7908d0()
{
	Console *console = new Console(opU5s2_rootConsole,0x44,0xc8,0,0,0,true,-1);
	for (unsigned int i = 0; i < opU5s2_manualSections.size(); i++)
	{
		for (unsigned int j = 0; j < opU5s2_manualSections[i]->lines.size(); j++)
		{
			if (opU5s2_manualSections[i]->lines[j].size() <= 0x44 || OpU5s2_contains(opU5s2_manualSections[i]->headers,j))
				continue;
			console->clear();
			int lineCount = console->printWrapped_418260(0,0,0x44,0xc8,opU5s2_manualSections[i]->lines[j]);
			OpQ5_eraseAt(opU5s2_manualSections[i]->lines,j);
			for (int k = 0; k < lineCount; k++)
			{
				OpU8a_insertString(opU5s2_manualSections[i]->lines,j + k,console->getString(Pos(0,k),0x44));
			}
			for (unsigned int m = 0; m < opU5s2_manualSections[i]->headers.size(); m++)
			{
				if (opU5s2_manualSections[i]->headers[m] > (int)j)
					opU5s2_manualSections[i]->headers[m] += lineCount - 1;
			}
			j += lineCount - 1;
		}
		while (!opU5s2_manualSections[i]->lines.empty() && opU5s2_manualSections[i]->lines.back().empty())
			opU5s2_manualSections[i]->lines.pop_back();
	}
	opU5s2_rootConsole->removeSubconsole(console);
}

struct OpU5s2_TerrainRecord	// NOTE: placeholder name
{
	int		ID;
	string	name;
	string	tag;
	int		unknown3c;
	int		unknown40;
	XColor	foreColor;
	XColor	backColor;
};

extern bool asciiEnabled;	// NOTE: placeholder name (0xd28d30)
extern vector<OpU5s2_TerrainRecord *> opd_terrainRecords;	// NOTE: placeholder name (0xcfb844)
extern XColor *opU5s2_earthColor;	// NOTE: placeholder name (0xcfe674)

class OpU5s2_Unk7935b0	// NOTE: placeholder name
{
public:
	void setEarthColors();	// NOTE: placeholder name (0x7935b0)
};

void OpU5s2_Unk7935b0::setEarthColors()
{
	if (asciiEnabled)
	{
		for (int i = 0; ; i++)
		{
			if (opd_terrainRecords[i]->tag == "Earth")
			{
				opd_terrainRecords[i]->backColor.set(*opU5s2_earthColor);
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		for (int j = 0; ; j++)
		{
			if (opd_terrainRecords[j]->tag == "Earth")
			{
				opd_terrainRecords[j]->backColor.set(0x27,0x1e,0x13);
			}
			else
			{
				break;
			}
		}
	}
}

//==================================================================
// GM::loadDataset
//==================================================================
struct OpQ5_T9dc620;	// NOTE: placeholder name
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
void OpQ1_readString(istream &in, string *text);	// NOTE: placeholder name (0x4096f0)
void OpQ1_readStringVector(istream &in, vector<string> *list);	// NOTE: placeholder name (0x4097e0)
void logInfo(string location, string message);	// NOTE: placeholder name (0x405090)
void logMessage(string message);	// NOTE: placeholder name (0x404cb0)
string opt5_makeDerelictName();	// 0x790cf0, NOTE: placeholder name
extern "C" void *SDL_CreateThread(int (*fn)(void*), void *data);
extern "C" void SDL_Delay(unsigned int milliseconds);
int opt5_loadThread(void *data);	// 0x790c00, NOTE: placeholder name

extern vector<string> opU5s2_stringsD1ddcc;	// NOTE: placeholder name
extern vector<OpQ5_T9dc620 *> opU5s2_objectsD2f108;	// NOTE: placeholder name
extern vector<OpQ5_T9dc620 *> opU5s2_objectsCf7550;	// NOTE: placeholder name
extern int opt5_loadThreads;	// NOTE: placeholder name (0xcefca4)

void GM::loadDataset()
{
	gzifstream stream((string() + "data/anim/chrono.bin").c_str(),ios::binary);
	if (stream.is_open())
	{
		string version;
		OpQ1_readString(stream,&version);
		OpQ1_readStringVector(stream,&opU5s2_stringsD1ddcc);
		OpQ5_readObjects(stream,opU5s2_objectsD2f108,0);
		stream.close();
	}
	stream.open((string() + "data/anim/civil.bin").c_str(),ios::binary);
	if (stream.is_open())
	{
		string version;
		OpQ1_readString(stream,&version);
		OpQ5_readObjects(stream,opU5s2_objectsCf7550,0);
		stream.close();
	}
	logInfo("GM::loadDataset()","Loading static objects");
	opU5s2_startupProgress->addLine(opt5_makeDerelictName(),true);
	opt5_loadThreads++;
	SDL_CreateThread(opt5_loadThread,NULL);
	int timer = 0;
	string message;
	while (opt5_loadThreads > 0)
	{
		SDL_Delay(10);
		timer += 10;
		if (timer >= 50)
		{
			timer = 0;
			opU5s2_startupProgress->addLine(opt5_makeDerelictName(),true);
		}
	}
	opU5s2_startupProgress->addLine("Manual",true);
	loadManual(string() + "manual.txt");
	logMessage("..." + intToString(opU5s2_manualSections.size()) + " " + "Manual Content" + " loaded");
	unknown7908d0();
	opU5s2_jlog->end(2);
}

//==================================================================
// GM::unknown7913f0 (name list file)
//==================================================================
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
		void close_9c05e0();	// NOTE: placeholder name (empty)
	};
}

bool OpY1_getEncodedLine(PhysFScpp::ifstream *file, string &line, int key);	// NOTE: placeholder name (0x4074b0)
int opr1c_getValueIfFlag(int value);	// 0x432ac0, NOTE: placeholder name
void OpU5s2_splitLine(string *line, vector<string> *tokens);	// NOTE: placeholder name (0x408d70)

bool GM::unknown7913f0(const string &path, vector<string> *list, vector<string> *list2)
{
	int counter = 0;
	int len;
	string name;
	vector<string> elements;
	vector<string> other;
	string msg;
	logMessage("Loading " + string("Battle Royale Names") + "...");
	PhysFScpp::ifstream input(path.c_str(),1);
	if (!input.isOpen_404af0())
	{
		opU5s2_jlog->end(2);
		return false;
	}
	else
		logMessage("[File: " + path + "] ");
	vector<string> *tail = list;
	while (OpY1_getEncodedLine(&input,name,opr1c_getValueIfFlag(counter)))
	{
		counter++;
		elements.clear();
		OpU5s2_splitLine(&name,&elements);
		if (!elements.empty())
		{
			if (elements.size() != 1)
			{
			}
			else if (elements[0][0] == '?')
			{
				if (elements[0].find("COMPOUND_2",0) != string::npos)
					tail = list2;
			}
			else
				tail->push_back(elements[0]);
		}
	}
	input.close_9c05e0();
	return true;
}
