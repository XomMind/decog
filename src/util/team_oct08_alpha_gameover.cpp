// Missing gameover constructors; layouts are partial placeholders.
#include <string>
using namespace std;
struct XColor { unsigned char r,g,b; XColor(const XColor &) throw(); };
struct Rect { int x,y,w,h; Rect(const Rect &); };
class XConsole {
public:
 virtual ~XConsole(); virtual void resize(int,int); virtual bool mouseEnter(); virtual void mouseLeave(); virtual bool input(void*); virtual void inputMouse(int,int); virtual void update(); virtual void render();
 void setFore(XColor) throw(); void print(int,int,const string&);
 char pad04[0x5c];
};
class Console:public XConsole {
public:
 Console(XConsole*,Rect,int,bool,int) throw(); Console(XConsole*,int,int,int,int,int,bool,int) throw();
 virtual ~Console(); virtual void resize(int,int); virtual bool input(void*); virtual void update(); virtual void render(); virtual void open(); virtual void close(); virtual int getFrame(); virtual void trigger(const string&,int);
 void animate(string);
 char pad60[12];
};
extern XColor *team_oct08_alpha_color_d29758; // NOTE: placeholder name
class CGameoverUpload:public Console {public: CGameoverUpload(XConsole*,const Rect&);};
CGameoverUpload::CGameoverUpload(XConsole *parent,const Rect &rect):Console(parent,rect,0,false,-1) {setFore(*team_oct08_alpha_color_d29758);}
class CGamoverButton:public Console {public: CGamoverButton(XConsole*,int,int,int); virtual bool input(void*); virtual bool mouseEnter(); virtual void mouseLeave(); int command;};
CGamoverButton::CGamoverButton(XConsole *parent,int x,int y,int command_):Console(parent,command_==0x19e?10:command_==0x19f?20:15,1,x,y,0,false,-1),command(command_) {
 print(0,0,command==0x19e?"[Load (L)]":command==0x19f?"[Restart (Spacebar)]":"[Quit (Escape)]");
 animate(command==0x19e?"A_CGameoverButton_Load":command==0x19f?"A_CGameoverButton_Restart":"A_CGameoverButton_Quit");
}
