// op_v3e: console constructors and list functions in 0x7d7e90-0x7f48e0, Beta 17.1.
// NOTE: class layouts are partial; names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor() throw();
	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
};

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
	Pos(int v);
	Pos(const Pos &pos) throw();
};

class XConsole
{
public:
	virtual ~XConsole();

	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	bool isHidden();	// NOTE: placeholder name
	int getWidth();
	int getHeight();
	Pos getPos();
	void setHidden(bool hidden_);	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	void clear();
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	void putChar_4180b0(int x, int y, int ch);	// NOTE: placeholder name
	void resetBack_418450();	// NOTE: placeholder name
	int width_44b0d0();	// NOTE: placeholder name (a getter at 0x44b0d0, distinct from getWidth 0x9b6bd0)
	int printWrapped_418260(int x, int y, int width, int height, const string &text);	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch);	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch, XColor fore);	// NOTE: placeholder name
	void setCharColumn(int x, int y, int height, int ch, XColor fore);	// NOTE: placeholder name
	void setFore(XColor color);
	bool input429d00(void *event);	// NOTE: placeholder name (XConsole::input body)
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)

	char pad04[0x60 - 0x04];
};

class ConsoleTitle;

struct Point
{
	int x;
	int y;

	Point(const Point &p);
};

class OpV3e_EngineAnim	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class Engine
{
public:
	OpV3e_EngineAnim *unknown50fb50(Engine *engine, int type, const void *a, const void *b, const void *c, const void *d, int value);	// NOTE: placeholder name (pointer params, as in op_x5_c)
	bool isRunning();	// NOTE: placeholder name (0x50fff0)
	void killGroup(string group);
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();

	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	void animate(string name);	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void setTitle(ConsoleTitle *title_);	// NOTE: placeholder name (0x7ad4e0)

	int unknown60;
	Engine *engine;
	void *title;
};

class ConsoleTitle : public Console
{
public:
	ConsoleTitle(XConsole *parent, string title_, int font, int align_);
	char pad6c[0x8c - 0x6c];
};

class CCloseButton : public Console
{
public:
	CCloseButton(XConsole *parent, const XColor &color, int x);
	char pad6c[0x8c - 0x6c];
};

class OpV3e_Rex	// NOTE: placeholder name (object at 0xd223f0)
{
public:
	int getWidth_418980();	// NOTE: placeholder name
	int getHeight_4189a0();	// NOTE: placeholder name
};
extern OpV3e_Rex opV3e_rex;	// NOTE: placeholder name

class CCommands : public Console
{
public:
	void unknown7d67c0(XConsole *other);	// NOTE: placeholder name
};
extern CCommands *opV3e_commands;	// NOTE: placeholder name (0xcec03c)

class CCollectionCounts : public Console
{
public:
	CCollectionCounts(XConsole *parent, int x, int y);	// 0x496a30
};

class CCollectionPercent : public Console
{
public:
	CCollectionPercent(XConsole *parent, int x, int y, int value_);	// 0x7d7b10
	virtual void update();	// 0x7d7e90

	int target;	// NOTE: placeholder name
	int current;	// NOTE: placeholder name
	unsigned int lastTick;	// NOTE: placeholder name
};

class CCollectionExport : public Console
{
public:
	CCollectionExport(XConsole *parent, int x, int y);	// 0x496e90
};

class OpV3e_GameMetaData	// NOTE: placeholder name (object at 0xd25628)
{
public:
	int getLoreCollectionPercent();
	int getAchievementPercent_46c930();	// NOTE: placeholder name
};
extern OpV3e_GameMetaData opV3e_gameMetaData;	// NOTE: placeholder name (0xd25628)

class OpS_Graph	// NOTE: placeholder name
{
public:
	void pushFrame(int index, int value, int other, bool flag);
};
extern OpS_Graph *opV3e_graph;	// NOTE: placeholder name (0xcefa8c)

void OpU5_createCollectionConsoles(int percent, const Pos &origin, CCollectionCounts **counts, CCollectionPercent **percentConsole, CCollectionExport **exportConsole);	// NOTE: placeholder name (0x7d89d0)
bool opr1c_hasPtr_cebd5c();	// NOTE: placeholder name (0x4328a0)
int opV3e_centerOffset(int inner, int outer);	// NOTE: placeholder name (0x437190)
int opV3e_playSound(int sound, int loopsB, int loops);	// NOTE: placeholder name (0x4541b0)

extern int opV3e_width_bcbc20;	// NOTE: placeholder name
extern int opV3e_heights_bcbdfc[2];	// NOTE: placeholder name
extern int opV3e_rows_bcbe04[2];	// NOTE: placeholder name
extern int opV3e_unknown_caf16c;	// NOTE: placeholder name
extern int opV3e_heights_bcbe0c[2];	// NOTE: placeholder name
extern XColor *opV3e_closeColor;	// NOTE: placeholder name (0xcf1f2c)

class CLoreDetails : public Console
{
public:
	CLoreDetails();	// 0x7e8c90
	virtual bool input(void *event);
};

class CLore : public Console
{
public:
	CLore();	// 0x7e8ee0
	virtual ~CLore();

	void unknown7ebba0(int rows, int index, int value, bool flag);	// NOTE: placeholder name
	void unknown7eafe0(int value, int flag);	// NOTE: placeholder name
	void unknown7e91e0();	// NOTE: placeholder name
	void unknown7ebd60(int key);	// NOTE: placeholder name
	virtual bool input(void *event);	// 0x7e92a0

	CCloseButton *closeButton;	// NOTE: placeholder name
	vector<unsigned int> list;	// NOTE: placeholder name
	int unknown80;	// NOTE: placeholder name
	CLoreDetails *details;	// NOTE: placeholder name
	CCollectionCounts *counts;	// NOTE: placeholder name
	CCollectionPercent *percentConsole;	// NOTE: placeholder name
	CCollectionExport *exportConsole;	// NOTE: placeholder name
	int unknown94;	// NOTE: placeholder name
};

extern CLore *opV3e_lore;	// NOTE: placeholder name (0xcec044)

CLore::CLore()
	: Console(opV3e_commands,0x36,opV3e_heights_bcbdfc[opr1c_hasPtr_cebd5c() ? 1 : 0],opr1c_hasPtr_cebd5c() ? opV3e_centerOffset(opV3e_width_bcbc20 + 0x98,opV3e_rex.getWidth_418980()) : opV3e_centerOffset(0x98,opV3e_rex.getWidth_418980()),opV3e_centerOffset(opV3e_heights_bcbdfc[opr1c_hasPtr_cebd5c() ? 1 : 0],opV3e_rex.getHeight_4189a0()),0,false,10)
{
	unknown80 = opV3e_unknown_caf16c;
	unknown94 = 0;
	opV3e_lore = this;
	setTitle(new ConsoleTitle(this,"/ L O R E   C O L L E C T I O N /",0,opr1c_hasPtr_cebd5c() ? 4 : 0));
	opV3e_commands->unknown7d67c0(this);
	unknown7ebba0(opV3e_rows_bcbe04[opr1c_hasPtr_cebd5c() ? 1 : 0],0,2,false);
	details = new CLoreDetails();
	OpU5_createCollectionConsoles(opV3e_gameMetaData.getLoreCollectionPercent(),getPos(),&counts,&percentConsole,&exportConsole);
	opV3e_playSound(0x31,0,0);
	animate("CLore_Border");
	opV3e_graph->pushFrame(3,(int)this,-1,false);
	unknown60 = 3;
	closeButton = new CCloseButton(this,*opV3e_closeColor,3);
	closeButton->setHidden(false);
}

//==================================================================
// CAchievements
//==================================================================

class CAchievementsEntry : public Console	// NOTE: placeholder name (0x74 bytes)
{
public:
	CAchievementsEntry(XConsole *parent, int x, int y, int index_, int unknown70_);	// 0x7edf90

	int unknown6c;
	int unknown70;
};

class OpV3e_AchievementRec	// NOTE: placeholder name (elements of the vector at 0xd257b0)
{
public:
	int index;	// NOTE: placeholder name
	char pad04[0x20 - 0x04];
	int unknown20;	// NOTE: placeholder name
	int unknown24;	// NOTE: placeholder name
};

class AsciiImage
{
public:
	char pad[0x10];
};

class OpV3e_AchievementDef	// NOTE: placeholder name (elements of the vector at 0xcf09a8)
{
public:
	char pad00[0x20];
	string name;	// NOTE: placeholder name
	char pad3c[0x40 - 0x3c];
	int category;	// NOTE: placeholder name
	int artIndex;	// NOTE: placeholder name
	bool secret;	// NOTE: placeholder name
	char pad49[0x50 - 0x49];
	string description;	// NOTE: placeholder name
	AsciiImage image;	// NOTE: placeholder name
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);
	char pad6c[0x88 - 0x6c];
};

class CAchievementsCategory : public Console
{
public:
	CAchievementsCategory(XConsole *parent, int x, int y, int category_);
	char pad6c[0x7c - 0x6c];
};

class CAchievementsCategoryToggleAllButton : public Console
{
public:
	CAchievementsCategoryToggleAllButton(XConsole *parent, int x, int y);
};

extern int opV3e_anim_cef7dc;	// NOTE: placeholder name

class OpV3e_AchievementPanel : public Console	// NOTE: placeholder name
{
public:
	OpV3e_AchievementPanel();	// 0x7ed730

	vector<CAchievementsCategory*> categories;	// NOTE: placeholder name
	CAchievementsCategoryToggleAllButton *toggleAll;	// NOTE: placeholder name
	vector<Console*> unknown80;	// NOTE: placeholder name
	vector<Console*> unknown90;	// NOTE: placeholder name
};

OpV3e_AchievementPanel::OpV3e_AchievementPanel()
	: Console(opV3e_commands,0x26,opV3e_heights_bcbe0c[opr1c_hasPtr_cebd5c() ? 1 : 0],opr1c_hasPtr_cebd5c() ? opV3e_centerOffset(opV3e_width_bcbc20 + 0x98,opV3e_rex.getWidth_418980()) : opV3e_centerOffset(0x98,opV3e_rex.getWidth_418980()),opV3e_centerOffset(opV3e_heights_bcbe0c[opr1c_hasPtr_cebd5c() ? 1 : 0],opV3e_rex.getHeight_4189a0()),0,false,10)
{
	animate("CAchieveFilter_Border");
	for (int i = 0, y = 2; i < 6; i++, y += 5)
		categories.push_back(new CAchievementsCategory(this,3,y,i));
	toggleAll = new CAchievementsCategoryToggleAllButton(this,6,0x20);
	CText *text = new CText(this,Pos(4,0x22),"State",0,0,-1);
	text->unknown48c3c0(opV3e_anim_cef7dc);
	Console *lines = new Console(this,7,3,0xa,0x22,0,false,-1);
	lines->setCharRow(0,0,7,0x81);
	lines->putChar_4180b0(4,0,0x86);
	lines->putChar_4180b0(4,1,0x85);
	lines->setCharRow(5,1,2,0x81);
	lines->putChar_4180b0(4,2,0x87);
	lines->setCharRow(5,2,2,0x81);
	lines->animate("A_AchieveFilterLines");
	text = new CText(this,Pos(4,0x26),"Order",0,0,-1);
	text->unknown48c3c0(opV3e_anim_cef7dc);
	lines = new Console(this,7,4,0xa,0x26,0,false,-1);
	lines->setCharRow(0,0,7,0x81);
	lines->putChar_4180b0(4,0,0x86);
	lines->putChar_4180b0(4,1,0x85);
	lines->setCharRow(5,1,2,0x81);
	lines->putChar_4180b0(4,2,0x85);
	lines->setCharRow(5,2,2,0x81);
	lines->putChar_4180b0(4,3,0x87);
	lines->setCharRow(5,3,2,0x81);
	lines->animate("A_AchieveFilterLines");
	animate("A_AchieveFilterTimer");
}

class CAchievements : public Console
{
public:
	CAchievements();	// 0x7ee700
	virtual ~CAchievements();
	virtual bool input(void *event);
	virtual void update();

	void unknown7eeb50();	// NOTE: placeholder name
	void unknown7f0d10(int value);	// NOTE: placeholder name
	void unknown7f1bd0(int count, int start, bool flag);	// NOTE: placeholder name
	void unknown7f1120();	// NOTE: placeholder name
	OpV3e_AchievementRec *getRecord_4984a0(int index);	// NOTE: placeholder name

	CCloseButton *closeButton;
	vector<OpV3e_AchievementRec*> unknown70;
	vector<int> unknown80;
	vector<CAchievementsEntry*> unknown90;
	Console *unknowna0;
	OpV3e_AchievementPanel *unknowna4;
	CCollectionCounts *unknowna8;
	CCollectionPercent *unknownac;
	CCollectionExport *unknownb0;
	int unknownb4;
};

extern vector<OpV3e_AchievementDef*> opV3e_achievementRecs;	// NOTE: placeholder name (0xcf09a8)
extern vector<OpV3e_AchievementRec*> opV3e_achievementOrder;	// NOTE: placeholder name (0xd257b0)
extern int opV3e_offsets_bcbe14[2];	// NOTE: placeholder name
extern CAchievements *opV3e_achievements;	// NOTE: placeholder name (0xcec048)
extern vector<bool> opV3e_achievementCategories;	// NOTE: placeholder name (0xd28d70)
extern int opV3e_achievementState_d28d84;	// NOTE: placeholder name
extern int opV3e_achievementSort_d28d88;	// NOTE: placeholder name
extern int opV3e_anim_cef944;	// NOTE: placeholder name

string intToString(int value);	// 0x4051f0

class CArtAnimated : public Console
{
public:
	CArtAnimated(XConsole *parent, AsciiImage *image, int x, int y, bool hidden, int anim, int unknown1, int unknown2, const Pos &offset, int width, int height);
	void unknown4b29b0();	// NOTE: placeholder name
	char pad6c[0x88 - 0x6c];
};

extern int opV3e_anim_cef7c0[];	// NOTE: placeholder name
extern int opV3e_anim_cef930[];	// NOTE: placeholder name
extern int opV3e_anim_cef96c;	// NOTE: placeholder name
extern int opV3e_anim_cef828[];	// NOTE: placeholder name
extern int opV3e_anim_cef8c4[];	// NOTE: placeholder name
extern int opV3e_anim_cef974;	// NOTE: placeholder name
extern int opV3e_anim_cef890[];	// NOTE: placeholder name
extern int opV3e_anim_cef7d8;	// NOTE: placeholder name
extern vector<vector<AsciiImage*> > opV3e_art_cf4544;	// NOTE: placeholder name
extern Point opV3e_effectOrigin;	// NOTE: placeholder name (0xd2e20c)
void OpT8a_eraseAt(vector<int> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0)
void opR2_insertAt9dbdc0(vector<int> &v, int index, int value);	// NOTE: placeholder name (0x9dbdc0)
bool OpT6_compareNames_7f10e0(unsigned int a, unsigned int b);	// NOTE: placeholder name

CAchievements::CAchievements()
	: Console(opV3e_commands,0x72,opV3e_heights_bcbe0c[opr1c_hasPtr_cebd5c() ? 1 : 0],(opr1c_hasPtr_cebd5c() ? opV3e_centerOffset(opV3e_width_bcbc20 + 0x98,opV3e_rex.getWidth_418980()) : opV3e_centerOffset(0x98,opV3e_rex.getWidth_418980())) + 0x26,opV3e_centerOffset(opV3e_heights_bcbe0c[opr1c_hasPtr_cebd5c() ? 1 : 0],opV3e_rex.getHeight_4189a0()),0,false,10)
{
	unknownb4 = 0;
	opV3e_achievements = this;
	setTitle(new ConsoleTitle(this,"/ A C H I E V E M E N T S /",0,4));
	opV3e_commands->unknown7d67c0(this);
	unknowna0 = new Console(this,0x32,1,2,opV3e_offsets_bcbe14[opr1c_hasPtr_cebd5c() ? 1 : 0],0,false,-1);
	unknowna4 = new OpV3e_AchievementPanel();
	unknown70.assign(opV3e_achievementRecs.size(),NULL);
	for (unsigned int i = 0; i < opV3e_achievementOrder.size(); i++)
		unknown70[opV3e_achievementOrder[i]->index] = opV3e_achievementOrder[i];
	unknown7f1120();
	OpU5_createCollectionConsoles(opV3e_gameMetaData.getAchievementPercent_46c930(),unknowna4->getPos(),&unknowna8,&unknownac,&unknownb0);
	opV3e_playSound(0x31,0,0);
	animate("CAchievements_Border");
	opV3e_graph->pushFrame(3,(int)this,-1,false);
	unknown60 = 1;
	closeButton = new CCloseButton(this,*opV3e_closeColor,3);
	closeButton->setHidden(false);
}

void CAchievements::unknown7f1120()
{
	unknown80.clear();
	for (unsigned int i = 0; i < unknown90.size(); i++)
	{
		if (unknown90[i])
			removeSubconsole(unknown90[i]);
	}
	unknown90.clear();
	vector<int> filtered;
	for (int i = 0; i < unknown70.size(); i++)
	{
		if (opV3e_achievementCategories[opV3e_achievementRecs[i]->category])
		{
			if (opV3e_achievementState_d28d84 == 2 || (opV3e_achievementState_d28d84 == 0 && unknown70[i] != NULL) || (opV3e_achievementState_d28d84 == 1 && unknown70[i] == NULL))
				filtered.push_back(i);
		}
	}
	switch (opV3e_achievementSort_d28d88)
	{
		case 0:
		case 1:
			for (unsigned int i = 0; i < filtered.size(); i++)
			{
				if (unknown70[filtered[i]] == NULL)
					OpT8a_eraseAt(filtered,i);
			}
			if (filtered.empty())
				break;
			unknown80.push_back(filtered.front());
			if (opV3e_achievementSort_d28d88 == 0)
			{
				for (unsigned int j = 1; j < filtered.size(); j++)
				{
					if (unknown70[filtered[j]]->unknown20 < unknown70[unknown80.back()]->unknown20 || (unknown70[filtered[j]]->unknown20 == unknown70[unknown80.back()]->unknown20 && unknown70[filtered[j]]->unknown24 <= unknown70[unknown80.back()]->unknown24))
						unknown80.push_back(filtered[j]);
					else
					{
						for (unsigned int k = 0; k < unknown80.size(); k++)
						{
							if (unknown70[filtered[j]]->unknown20 > unknown70[unknown80[k]]->unknown20 || (unknown70[filtered[j]]->unknown20 == unknown70[unknown80[k]]->unknown20 && unknown70[filtered[j]]->unknown24 >= unknown70[unknown80[k]]->unknown24))
							{
								opR2_insertAt9dbdc0(unknown80,k,filtered[j]);
								break;
							}
						}
					}
				}
			}
			else
			{
				for (unsigned int j = 1; j < filtered.size(); j++)
				{
					if (unknown70[filtered[j]]->unknown20 > unknown70[unknown80.back()]->unknown20 || (unknown70[filtered[j]]->unknown20 == unknown70[unknown80.back()]->unknown20 && unknown70[filtered[j]]->unknown24 >= unknown70[unknown80.back()]->unknown24))
						unknown80.push_back(filtered[j]);
					else
					{
						for (unsigned int k = 0; k < unknown80.size(); k++)
						{
							if (unknown70[filtered[j]]->unknown20 < unknown70[unknown80[k]]->unknown20 || (unknown70[filtered[j]]->unknown20 == unknown70[unknown80[k]]->unknown20 && unknown70[filtered[j]]->unknown24 <= unknown70[unknown80[k]]->unknown24))
							{
								opR2_insertAt9dbdc0(unknown80,k,filtered[j]);
								break;
							}
						}
					}
				}
			}
			break;
		case 2:
			unknown80 = filtered;
			sort(unknown80.begin(),unknown80.end(),OpT6_compareNames_7f10e0);
			break;
		case 3:
			unknown80 = filtered;
			break;
	}
	unknowna0->clear();
	unknowna0->print(0,0,"Listing " + intToString(unknown80.size()) + " of " + intToString(opV3e_achievementRecs.size()) + " achievements.");
	unknowna0->unknown48c3c0(opV3e_anim_cef944);
}

//==================================================================
// string comparators
//==================================================================

extern string gameStrings_d16318[];
extern string gameStrings_cf4dd0[];

bool OpV3e_compareStrings7f2210(int a, int b)	// NOTE: placeholder name
{
	string *nameA = &gameStrings_d16318[a];
	string *nameB = &gameStrings_d16318[b];
	if ((!isalpha((*nameA)[0]) || isupper((*nameA)[0])) && (!isalpha((*nameB)[0]) || isupper((*nameB)[0])))
	{
		return lexicographical_compare(nameA->begin(),nameA->end(),nameB->begin(),nameB->end());
	}
	else
	{
		string sa = gameStrings_d16318[a];
		string sb = gameStrings_d16318[b];
		sa[0] = toupper(sa[0]);
		sb[0] = toupper(sb[0]);
		return lexicographical_compare(((const string &)sa).begin(),((const string &)sa).end(),((const string &)sb).begin(),((const string &)sb).end());
	}
}

bool OpV3e_compareStrings7f2410(int a, int b)	// NOTE: placeholder name
{
	string *nameA = &gameStrings_cf4dd0[a];
	string *nameB = &gameStrings_cf4dd0[b];
	if ((!isalpha((*nameA)[0]) || isupper((*nameA)[0])) && (!isalpha((*nameB)[0]) || isupper((*nameB)[0])))
	{
		return lexicographical_compare(nameA->begin(),nameA->end(),nameB->begin(),nameB->end());
	}
	else
	{
		string sa = gameStrings_cf4dd0[a];
		string sb = gameStrings_cf4dd0[b];
		sa[0] = toupper(sa[0]);
		sb[0] = toupper(sb[0]);
		return lexicographical_compare(((const string &)sa).begin(),((const string &)sa).end(),((const string &)sb).begin(),((const string &)sb).end());
	}
}

//==================================================================
// CSupporters
//==================================================================

struct Rect	// NOTE: placeholder layout
{
	int x, y, width, height;

	Rect(int x_, int y_, int width_, int height_);
};
extern Rect rect_cf67d0;	// NOTE: placeholder name

class OpV3e_SupportersText : public Console	// NOTE: placeholder name (CSupportersText, base OpW5_Console498540)
{
public:
	OpV3e_SupportersText(XConsole *parent, int x, int y, int width, int height, int unknown6c_, int unknown70_);	// 0x4984f0 (CSupportersText)

	void refreshColor();	// NOTE: placeholder name (0x498540)

	int type;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
};

class CSupporterCounts : public Console
{
public:
	CSupporterCounts(XConsole *parent, int x, int y);
};

class CSupporters : public Console
{
public:
	CSupporters(bool patrons);	// 0x7f2610
	virtual ~CSupporters();

	void unknown7f3530(int count, int start, bool flag);	// NOTE: placeholder name

	CCloseButton *closeButton;	// NOTE: placeholder name
	vector<int> unknown70;	// NOTE: placeholder name
	int unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	vector<OpV3e_SupportersText*> unknown88;	// NOTE: placeholder name
	CSupporterCounts *unknown98;	// NOTE: placeholder name
	bool unknown9c;	// NOTE: placeholder name
};
extern CSupporters *opV3e_supporters;	// NOTE: placeholder name (0xcec04c)

// 0x7f2610. Local names (current/text/last/entries/limit/item) are chosen for the frame layout. The text console
// uses a file-local class (OpV3e_SupportersText) so CSupportersText's other declarations stay untouched.
CSupporters::CSupporters(bool patrons)
	: Console(opV3e_commands,0x33,opV3e_rex.getHeight_4189a0() - 7,opV3e_centerOffset(0x33,opV3e_rex.getWidth_418980()),opV3e_centerOffset(opV3e_rex.getHeight_4189a0() - 7,opV3e_rex.getHeight_4189a0()),0,false,10)
{
	unknown9c = patrons;
	opV3e_supporters = this;
	if (unknown9c)
		setTitle(new ConsoleTitle(this,"/ P A T R O N S /",0,4));
	else
		setTitle(new ConsoleTitle(this,"/ A L P H A   S U P P O R T E R S /",0,4));
	opV3e_commands->unknown7d67c0(this);
	int limit = unknown9c ? 200 : 1000;
	string *entries = unknown9c ? gameStrings_cf4dd0 : gameStrings_d16318;
	string last(unknown9c ? "TIER_END_ARCHITECT" : "TIER_END_ADVANCED");
	string current(unknown9c ? "TIER_END_SAGE" : "TIER_END_IMPROVED");
	for (int i = 0; i < limit; i++)
	{
		if (!entries[i].empty())
		{
			if (entries[i] == last)
			{
				unknown80 = i - 1;
				break;
			}
			else
				unknown70.push_back(i);
		}
	}
	if (unknown9c)
		sort(unknown70.begin(),unknown70.end(),OpV3e_compareStrings7f2410);
	else
		sort(unknown70.begin(),unknown70.end(),OpV3e_compareStrings7f2210);
	for (int j = unknown80 + 2; j < limit; j++)
	{
		if (!entries[j].empty())
		{
			if (entries[j] == current)
			{
				unknown84 = j - 2;
				break;
			}
			else
				unknown70.push_back(j);
		}
	}
	if (unknown9c)
		sort(unknown70.begin() + unknown80 + 1,unknown70.end(),OpV3e_compareStrings7f2410);
	else
		sort(unknown70.begin() + unknown80 + 1,unknown70.end(),OpV3e_compareStrings7f2210);
	for (int k = unknown84 + 3; k < limit; k++)
	{
		if (!entries[k].empty())
			unknown70.push_back(k);
	}
	if (unknown9c)
		sort(unknown70.begin() + unknown84 + 1,unknown70.end(),OpV3e_compareStrings7f2410);
	else
		sort(unknown70.begin() + unknown84 + 1,unknown70.end(),OpV3e_compareStrings7f2210);
	string text(unknown9c ? "I greatly appreciate all the help from my wonderful patrons through Beta and beyond!" : "A huge thanks to everyone who supported Cogmind during alpha development!");
	OpV3e_SupportersText *item = new OpV3e_SupportersText(this,rect_cf67d0.x,rect_cf67d0.y,rect_cf67d0.width,rect_cf67d0.height,0,-1);
	item->printWrapped_418260(0,0,rect_cf67d0.width,rect_cf67d0.height,text);
	item->refreshColor();
	unknown7f3530((opV3e_rex.getHeight_4189a0() - 13) / 2,0,true);
	unknown98 = new CSupporterCounts(opV3e_commands,getPos().x,getPos().y + getHeight());
	opV3e_playSound(0x31,0,0);
	animate("CSupporters_Border");
	opV3e_graph->pushFrame(3,(int)this,-1,false);
	unknown60 = 3;
	closeButton = new CCloseButton(this,*opV3e_closeColor,3);
	closeButton->setHidden(false);
}

//==================================================================
// CCollectionPercent
//==================================================================

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
void OpC_clampMax(int *value, int max);	// 0x9cf5a0
int opr1c_getPercentTier(int value, int max);	// NOTE: placeholder name (0x4347e0)
bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)
extern XColor *opV3e_color_d2f34c;	// NOTE: placeholder name
extern XColor *opV3e_color_d204ac;	// NOTE: placeholder name
extern XColor *opV3e_color_d23094;	// NOTE: placeholder name
extern XColor *opV3e_color_cf27e8;	// NOTE: placeholder name
extern XColor *opV3e_color_cf281c;	// NOTE: placeholder name
extern XColor *opV3e_color_d20438;	// NOTE: placeholder name
extern XColor *opV3e_color_d25e0c;	// NOTE: placeholder name
extern XColor *opV3e_color_d2981c;	// NOTE: placeholder name
struct OpV3e_XY { int x, y; };	// NOTE: placeholder name (Point-like globals)
extern OpV3e_XY opV3e_pt_d39704;	// NOTE: placeholder name
extern OpV3e_XY opV3e_pt_d37d40;	// NOTE: placeholder name
extern OpV3e_XY opV3e_pt_d204fc;	// NOTE: placeholder name
extern OpV3e_XY opV3e_pt_d2284c;	// NOTE: placeholder name
extern OpV3e_XY opV3e_pt_cfbec0;	// NOTE: placeholder name

// 0x7d7e90. Local names (step/delta/color/base) are chosen for the frame layout.
void CCollectionPercent::update()
{
	if (isHidden())
		return;
	if (current != target)
	{
		unsigned int step = 20;
		unsigned int delta = tickCount - lastTick;
		if (delta > step)
		{
			current += delta / step;
			OpC_clampMax(&current,target);
			XColor color;
			XColor base;
			switch (opr1c_getPercentTier(current,100))
			{
			case 0:
				color = *opV3e_color_d2f34c;
				base = *opV3e_color_d204ac;
				break;
			case 1:
				color = *opV3e_color_d23094;
				base = *opV3e_color_cf27e8;
				break;
			case 2:
				color = *opV3e_color_cf281c;
				base = *opV3e_color_d20438;
				break;
			case 3:
				color = *opV3e_color_d25e0c;
				base = *opV3e_color_d2981c;
				break;
			}
			setFore(color);
			if (opr1c_hasPtr_cebd5c())
			{
				print(opV3e_pt_d39704.x,opV3e_pt_d39704.y,intToString(current) + "%");
				setFore(base);
				int height = current * 30 / 100;
				setCharColumn(opV3e_pt_d37d40.x,30 - height + opV3e_pt_d37d40.y,height,0xb0,base);
				lastTick += delta / step * step;
				if (current == 100)
				{
					int anim;
					OpU8a_lookup1("CCollectionPcnt_100",&anim);
					if (anim)
						do
						{
							for (int i = opV3e_pt_d37d40.y; i < opV3e_pt_d37d40.y + 30; i++)
								engine->unknown50fb50(engine,anim,&Pos(opV3e_pt_d37d40.x,i),&opV3e_pt_cfbec0,NULL,NULL,9)->unknown50de10();
						} while (0);
				}
			}
			else
			{
				print(opV3e_pt_d204fc.x,opV3e_pt_d204fc.y,intToString(current) + "%");
				setFore(base);
				setCharRow(opV3e_pt_d2284c.x,opV3e_pt_d2284c.y,current * 0x44 / 100,0xb3,base);
				lastTick += delta / step * step;
				if (current == 100)
				{
					int anim;
					OpU8a_lookup1("CCollectionPcnt_100",&anim);
					if (anim)
						do
						{
							for (int i = opV3e_pt_d2284c.x; i < opV3e_pt_d2284c.x + 0x44; i++)
								engine->unknown50fb50(engine,anim,&Pos(i,opV3e_pt_d2284c.y),&opV3e_pt_cfbec0,NULL,NULL,9)->unknown50de10();
						} while (0);
				}
			}
		}
	}
	else if (target == 0)
	{
		setFore(*opV3e_color_d204ac);
		if (opr1c_hasPtr_cebd5c())
			print(opV3e_pt_d39704.x + 1,opV3e_pt_d39704.y,"0%");
		else
			print(opV3e_pt_d204fc.x,opV3e_pt_d204fc.y,"0%");
	}
	engine->isRunning();
	updateBase429e30();
}
