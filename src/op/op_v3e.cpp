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

	XColor(const XColor &color) throw();
};

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
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
	bool input429d00(void *event);	// NOTE: placeholder name (XConsole::input body)
	void updateBase429e30();	// NOTE: placeholder name (0x429e30, XConsole::update body)

	char pad04[0x60 - 0x04];
};

class ConsoleTitle;

class Engine
{
public:
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
	CAchievementsEntry(XConsole *parent, int x, int y, void *record_, int index_);	// 0x7edf90

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

class OpV3e_AchievementDef	// NOTE: placeholder name (elements of the vector at 0xcf09a8)
{
public:
	char pad00[0x40];
	int category;	// NOTE: placeholder name
};

class OpV3e_AchievementPanel : public Console	// NOTE: placeholder name
{
public:
	OpV3e_AchievementPanel();	// 0x7ed730
	char pad6c[0xa0 - 0x6c];
};

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
extern int opV3e_heights_bcbe0c[2];	// NOTE: placeholder name
extern int opV3e_offsets_bcbe14[2];	// NOTE: placeholder name
extern CAchievements *opV3e_achievements;	// NOTE: placeholder name (0xcec048)
extern vector<bool> opV3e_achievementCategories;	// NOTE: placeholder name (0xd28d70)
extern int opV3e_achievementState_d28d84;	// NOTE: placeholder name
extern int opV3e_achievementSort_d28d88;	// NOTE: placeholder name
extern int opV3e_anim_cef944;	// NOTE: placeholder name

string intToString(int value);	// 0x4051f0
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
