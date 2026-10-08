// Achievement-entry artwork, title, unlocked count, and wrapped description.
// NOTE: classes and fields are partial placeholders except established game types.
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
	virtual ~CText();
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);
	char pad6c[0x88 - 0x6c];
};

class CArtAnimated : public Console
{
public:
	virtual ~CArtAnimated();
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
extern vector<vector<AsciiImage*> > loop_art_cf4544;	// NOTE: placeholder name (artwork table at 0xcf4544)
extern Point opV3e_effectOrigin;	// NOTE: placeholder name (0xd2e20c)

extern vector<OpV3e_AchievementDef*> opV3e_achievementRecs;
class LoopDeltaAchievements {
public: OpV3e_AchievementRec *get_4984a0(int index);
};
extern LoopDeltaAchievements *loop_achievementPanel_cec048;
string intToString(int value);
class LoopDeltaAchievementEntry : public Console {
public:
 virtual ~LoopDeltaAchievementEntry();
 int index;
 int unknown70;
 LoopDeltaAchievementEntry(XConsole *parent,int x,int y,int index_,int unknown70_);
};
LoopDeltaAchievementEntry::LoopDeltaAchievementEntry(XConsole *parent,int x,int y,int index_,int unknown70_)
 : Console(parent,54,5,x,y,0,false,-1),index(index_),unknown70(unknown70_) {
 int n = opV3e_achievementRecs[index]->category;
 OpV3e_AchievementRec *h = loop_achievementPanel_cec048->get_4984a0(index);
 // Materialize the selected artwork pointer before evaluating the remaining arguments.
 CArtAnimated *sx = new CArtAnimated(this,static_cast<AsciiImage * const &>(h ? &opV3e_achievementRecs[index]->image : loop_art_cf4544[n][opV3e_achievementRecs[index]->artIndex]),0,0,false,opV3e_anim_cef7c0[n],-1,-1,Pos(-1),0,0);
 sx->resetBack_418450();
 sx->unknown4b29b0();
 string name = opV3e_achievementRecs[index]->name;
 CText *type = new CText(this,Pos(11,0),name,0,0,-1);
 type->unknown48c3c0(h ? opV3e_anim_cef930[n] : opV3e_anim_cef96c);
 if (h) {
  type = new CText(this,Pos(11,1),"> "+intToString(h->unknown20),0,0,-1);
  type->unknown48c3c0(opV3e_anim_cef828[n]);
 }
 Pos pos(11,2);
 string description = h || !opV3e_achievementRecs[index]->secret ? string(opV3e_achievementRecs[index]->description) : string("???");
 int w = printWrapped_418260(pos.x,pos.y,width_44b0d0()-11,3,description);
 if (w == 1) {
  type = new CText(this,pos,description,0,0,-1);
  type->unknown48c3c0(h ? opV3e_anim_cef8c4[n] : opV3e_anim_cef974);
 } else {
  for (int i = pos.x; i < width_44b0d0(); i++)
   engine->unknown50fb50(engine,h ? opV3e_anim_cef890[n] : opV3e_anim_cef7d8,&Pos(i,y),&opV3e_effectOrigin,&Pos(i,pos.y+w-1),&Point(opV3e_effectOrigin),9)->unknown50de10();
 }
}
