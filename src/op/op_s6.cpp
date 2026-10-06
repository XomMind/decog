// op_s6: functions in 0x7ed000-0x8b5000 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;

	Pos(int x_, int y_);
	Pos(const Pos &pos) throw();
	Pos(const Pos &pos, int dx, int dy);	// NOTE: placeholder name (0x4099c0)
};

class OpR2b_Engine	// NOTE: placeholder name
{
public:
	void stopAll();	// NOTE: placeholder name (0x50ff30)
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

	void clearBack();
	Pos getPos();
	void setPos(const Pos &pos);
	void removeSubconsole(XConsole *console);
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);
	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	virtual ~Console();

	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);

	void animate(string name);	// NOTE: placeholder name
	void unknown48c3c0(int value);	// NOTE: placeholder name
	void unknown48c650();	// NOTE: placeholder name

	int unknown60;
	OpR2b_Engine *engine;
	void *title;
};

extern vector<bool> opS6_achievementCategories;	// NOTE: placeholder name (0xd28d70)
extern int opS6_anim_cef864[];	// NOTE: placeholder name
extern int opS6_anim_cef930[];	// NOTE: placeholder name
extern int opS6_anim_cef998;	// NOTE: placeholder name
extern int opS6_anim_cef96c;	// NOTE: placeholder name
extern int opS6_bcbe24[];	// NOTE: placeholder name
bool opS6_hasPtr();	// NOTE: placeholder name (0x4328a0)
extern int opS6_anim_cef818;	// NOTE: placeholder name
extern int opS6_anim_cef97c;	// NOTE: placeholder name
extern int opS6_anim_cef8b0;	// NOTE: placeholder name
extern int opS6_anim_cef78c;	// NOTE: placeholder name
extern int opS6_anim_cef99c;	// NOTE: placeholder name

class CAchievementsCategoryToggleAllButton : public Console
{
public:
	void unknown7ed4f0(int mode);	// NOTE: placeholder name
};

void CAchievementsCategoryToggleAllButton::unknown7ed4f0(int mode)
{
	engine->stopAll();
	clearBack();
	switch (mode)
	{
		case 0:
			unknown48c3c0(opS6_anim_cef818);
			break;
		case 1:
			unknown48c3c0(opS6_anim_cef97c);
			break;
	}
}

class CAchievementsStateButton : public Console
{
public:
	CAchievementsStateButton(XConsole *parent, int x, int y, int state_, bool primary_);

	void unknown7ed5e0(int mode);	// NOTE: placeholder name

	int state;	// NOTE: placeholder name
	bool primary;	// NOTE: placeholder name
};

void CAchievementsStateButton::unknown7ed5e0(int mode)
{
	engine->stopAll();
	clearBack();
	switch (mode)
	{
		case 0:
			unknown48c3c0(opS6_anim_cef8b0);
			break;
		case 1:
			unknown48c3c0(opS6_anim_cef78c);
			break;
		case 2:
			unknown48c3c0(opS6_anim_cef99c);
			break;
	}
}

class CAchievementsEntry : public Console	// NOTE: placeholder name (0x74 bytes)
{
public:
	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
};

class OpS6_CategoryEntry	// NOTE: placeholder name
{
public:
	char pad0[0x70];
	Console *unknown70;	// NOTE: placeholder name
	char pad74[4];
	Console *unknown78;	// NOTE: placeholder name
};

class OpS6_CategoryPanel : public Console	// NOTE: placeholder name
{
public:
	vector<OpS6_CategoryEntry*> entries;	// NOTE: placeholder name
};

class OpS6_StatePanel : public Console	// NOTE: placeholder name
{
public:
	virtual void trigger(const string &command, int value);

	char pad6c[0x80 - 0x6c];
	vector<CAchievementsStateButton*> primaryButtons;	// NOTE: placeholder name
	vector<CAchievementsStateButton*> secondaryButtons;	// NOTE: placeholder name
};

void OpS6_StatePanel::trigger(const string &command, int value)
{
	if (command == "state_buttons")
	{
		for (int i = 0, y = 0x22; i < 3; i++, y++)
			primaryButtons.push_back(new CAchievementsStateButton(this,0x11,y,i,true));
		for (int j = 0, y2 = 0x26; j < 4; j++, y2++)
			secondaryButtons.push_back(new CAchievementsStateButton(this,0x11,y2,j,false));
	}
}

class CAchievements : public Console
{
public:
	virtual ~CAchievements();

	void unknown7f1bd0(int count, int start, bool flag);	// NOTE: placeholder name
	void unknown7f1e00(int category, bool flag);	// NOTE: placeholder name
	int unknown7f1f60();	// NOTE: placeholder name
	int unknown7f1fb0();	// NOTE: placeholder name
	void unknown7f1120();	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	vector<int> unknown70;	// NOTE: placeholder name
	vector<void*> unknown80;	// NOTE: placeholder name
	vector<CAchievementsEntry*> unknown90;	// NOTE: placeholder name
	int unknowna0;	// NOTE: placeholder name
	OpS6_CategoryPanel *unknowna4;	// NOTE: placeholder name
};

void CAchievements::unknown7f1e00(int category, bool flag)
{
	opS6_achievementCategories[category] = !opS6_achievementCategories[category];
	if (opS6_achievementCategories[category])
	{
		unknowna4->entries[category]->unknown70->unknown48c3c0(opS6_anim_cef864[category]);
		unknowna4->entries[category]->unknown78->unknown48c3c0(opS6_anim_cef930[category]);
	}
	else
	{
		unknowna4->entries[category]->unknown70->unknown48c3c0(opS6_anim_cef998);
		unknowna4->entries[category]->unknown78->unknown48c650();
		unknowna4->entries[category]->unknown78->unknown48c3c0(opS6_anim_cef96c);
	}
	if (flag)
	{
		unknown7f1120();
		unknown7f1bd0(opS6_bcbe24[opS6_hasPtr() != 0],0,true);
	}
}

int CAchievements::unknown7f1f60()
{
	return unknown90.empty() ? 0 : unknown90.front()->unknown70;
}

int CAchievements::unknown7f1fb0()
{
	return unknown90.empty() ? 0 : unknown80.size() - 1 - unknown90.back()->unknown70;
}

//==================================================================
// CSupporters
//==================================================================

class OpS6_Rex	// NOTE: placeholder name (object at 0xd223f0)
{
public:
	int getHeight_4189a0();	// NOTE: placeholder name
};
extern OpS6_Rex opS6_rex;	// NOTE: placeholder name

int minInt(int a, int b);	// 0x9cdb30
int opS6_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
template <class T> void opS6_eraseRange(vector<T> &v, int first, int last);	// NOTE: placeholder name (0x9e25a0)
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0

class OpW5_Console498540 : public Console	// NOTE: placeholder name
{
public:
	void refreshColor();	// NOTE: placeholder name

	int type;	// NOTE: placeholder name
};

class CSupportersText : public OpW5_Console498540
{
public:
	CSupportersText(XConsole *parent, int x, int y, int width, int height, int unknown6c_, int unknown70_);

	int unknown70;	// NOTE: placeholder name
};

void opS6_insertAt(vector<CSupportersText*> &v, int index, CSupportersText *value);	// NOTE: placeholder name (0x9dbdc0)
bool opS6_unknown406320(int index);	// NOTE: placeholder name
extern string opS6_strings_cf4dd0[];	// NOTE: placeholder name
extern string opS6_strings_d16318[];	// NOTE: placeholder name

class CSupporters : public Console
{
public:
	virtual ~CSupporters();

	void unknown7f30e0(int offset);	// NOTE: placeholder name
	void unknown7f3530(int count, int start, bool flag);	// NOTE: placeholder name
	int unknown7f37b0();	// NOTE: placeholder name

	int unknown6c;	// NOTE: placeholder name
	vector<int> unknown70;	// NOTE: placeholder name
	int unknown80;	// NOTE: placeholder name
	int unknown84;	// NOTE: placeholder name
	vector<CSupportersText*> unknown88;	// NOTE: placeholder name
	XConsole *unknown98;	// NOTE: placeholder name
	bool unknown9c;	// NOTE: placeholder name
};

void CSupporters::unknown7f30e0(int offset)
{
	if (offset == 0)
		return;
	int first = unknown88.front()->unknown70;
	if (offset < 0)
	{
		offset = -offset;
		if (first == 0)
			return;
		if (offset >= (opS6_rex.getHeight_4189a0() - 0xd) / 2 || first - offset < 0)
		{
			for (unsigned int i = 0; i < unknown88.size(); i++)
			{
				if (unknown88[i])
					removeSubconsole(unknown88[i]);
			}
			unknown88.clear();
			first = opS6_maxInt(0,first - offset);
			unknown7f3530((opS6_rex.getHeight_4189a0() - 0xd) / 2,first,true);
		}
		else
		{
			int start = (opS6_rex.getHeight_4189a0() - 0xd) / 2 - offset;
			for (unsigned int j = start; j < unknown88.size(); j++)
				removeSubconsole(unknown88[j]);
			opS6_eraseRange(unknown88,start,unknown88.size() - 1);
			int amount = offset * 2;
			for (unsigned int k = 0; k < unknown88.size(); k++)
				unknown88[k]->setPos(Pos(unknown88[k]->getPos(),0,amount));
			first -= offset;
			unknown7f3530(offset,first,true);
		}
	}
	else
	{
		if (unknown88.back()->unknown70 == unknown70.size() - 1)
			return;
		if (offset >= (opS6_rex.getHeight_4189a0() - 0xd) / 2 || first + offset >= (int)unknown70.size() - (opS6_rex.getHeight_4189a0() - 0xd) / 2)
		{
			for (unsigned int l = 0; l < unknown88.size(); l++)
			{
				if (unknown88[l])
					removeSubconsole(unknown88[l]);
			}
			unknown88.clear();
			first = minInt(unknown70.size() - (opS6_rex.getHeight_4189a0() - 0xd) / 2,first + offset);
			unknown7f3530((opS6_rex.getHeight_4189a0() - 0xd) / 2,first,false);
		}
		else
		{
			for (int m = 0; m < offset; m++)
			{
				removeSubconsole(unknown88.front());
				removeVectorElement(unknown88,0);
			}
			int amount = offset * 2;
			for (unsigned int n = 0; n < unknown88.size(); n++)
				unknown88[n]->setPos(Pos(unknown88[n]->getPos(),0,-amount));
			first = unknown88.size() + offset + first;
			unknown7f3530(offset,first,false);
		}
	}
}

void CSupporters::unknown7f3530(int count, int start, bool flag)
{
	string *labels = unknown9c ? opS6_strings_cf4dd0 : opS6_strings_d16318;
	int idx = 0;
	int k = 0;
	int py = ((!flag && (flag || !unknown88.empty())) ? unknown88.size() * 2 : 0) + 6;
	for (; k < count; k++, py += 2, start++, idx++)
	{
		if (start >= unknown70.size())
			break;
		CSupportersText *text = new CSupportersText(this,2,py,0x2f,1,unknown9c ? (start <= unknown80 ? 7 : 8 + (start > unknown84)) : (start <= unknown80 ? 1 : 2 + (start > unknown84)) + (opS6_unknown406320(start) ? 0 : 3),start);
		text->printAligned(0x17,0,1,labels[unknown70[start]]);
		text->refreshColor();
		if (flag)
			opS6_insertAt(unknown88,idx,text);
		else
			unknown88.push_back(text);
	}
}

int CSupporters::unknown7f37b0()
{
	return unknown70.size() - 1 - unknown88.back()->unknown70;
}
