// NOTE: private borrowed partial layouts and complete native Console/Effect owners for assimilate handler969b60.
#include <string>
#include <vector>
using namespace std;
struct LB36Point{int x,y;LB36Point()throw();LB36Point(int)throw();LB36Point&operator=(const LB36Point&)throw();LB36Point&add409a30(const LB36Point&)throw();LB36Point(int,int)throw();LB36Point(const LB36Point&)throw();};
struct LB36Color{unsigned char r,g,b;LB36Color()throw();LB36Color(int,int,int)throw();LB36Color(const LB36Color&)throw();LB36Color&operator=(LB36Color)throw();};
struct LB36XCell{int font,glyph,value;LB36Color fore,back;LB36XCell(int,int,LB36Color,LB36Color);};
struct LB36Buffer{int width,height;LB36XCell*last;LB36Buffer();~LB36Buffer();};
struct LB36Event;struct LB36Rect;
struct LB36XConsole{virtual ~LB36XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LB36Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LB36XConsole*parent;LB36Buffer buffer;int font,fontType;LB36Point position,absolutePosition;LB36Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LB36XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 bool contains(const LB36Point&)throw();void remove(LB36XConsole*);void reset();void fore(LB36Color);void back(LB36Color);void enable(int);void print(int,int,const string&);int width()throw();LB36Point absolute(LB36Point)throw();bool visible417610()throw();void hide417ba0(bool);LB36Point max4174e0()throw();void put4181a0(int,int,const LB36XCell&);const LB36Point&offset458ef0()throw();void range8051f0(LB36Point*,LB36Point*)throw();void center805020(LB36Point*)throw();void row(int,int,int,LB36Color);void rect(int,int,int,int,LB36Color);void put(int,int,int,LB36Color,LB36Color,int);bool hidden4175f0()throw();LB36Point pos417480()throw();int width44b0d0()throw();int height4174c0()throw();void pos4289e0(const LB36Point&);void copy429fe0(LB36XConsole*,LB36Point&,const LB36Rect*);int layer44a7d0()throw();};
struct LB36Engine;struct LB36Title;struct LB36Rect;
struct LB36Console:LB36XConsole{virtual ~LB36Console();virtual void resize(int,int);virtual bool input(LB36Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LB36Engine*engine;LB36Title*title;LB36Console(LB36XConsole*,int,int,int,int,int,bool,int);void frame(LB36Rect*,LB36Color,bool,bool);void baseRender();void animate48c3f0(string);void close8b5080();unsigned char active48e740()throw();void close7b60e0();void open894120(bool);void open965220();int equip81a0e0(int);void bubble8758d0(bool);void scroll7b4f10();void move8069e0(LB36Point,bool);};
static_assert(sizeof(LB36XCell)==20&&sizeof(LB36XConsole)==0x60&&sizeof(LB36Console)==0x6c,"actual console owners/layout");


struct LB36Rect{int x,y,width,height;LB36Rect(int,int,int,int)throw();};
struct LB36CEffect:LB36Console{int kind;LB36CEffect(LB36XConsole*,const LB36Rect&,int);virtual ~LB36CEffect();};
static_assert(sizeof(LB36CEffect)==112,"actual full Console owner plus mode kind");

struct LB36Sound{void stop5003b0();void reset4544e0();};extern LB36Sound lb36_d2d2a0;struct LB36Mixer{void halt419c50();};extern LB36Mixer*lb36_cefa90;
struct LB36Rex{LB36XConsole*high4ab670()throw();};extern LB36Rex lb36_d223f0;
struct LB36Cell{LB36Color color66a680();int ascii66a830();};
struct LB36Grid{int width,height;LB36Cell**cells;LB36Grid();~LB36Grid();LB36Cell**at9ceda0(int,int)throw();};extern LB36Grid lb36_cfd44c;
struct LB36World{void reveal7243c0(int,int,bool);};extern LB36World*lb36_cefc4c;
extern LB36Console *lb36_cec0b0,*lb36_cec0c8,*lb36_cec074,*lb36_cec078,*lb36_cec07c,*lb36_cec088,*lb36_cec08c,*lb36_cec054,*lb36_cec0f4,*lb36_cec0d0,*lb36_cec0d4,*lb36_cec0d8,*lb36_cec0dc,*lb36_cec0e4,*lb36_cec0e8,*lb36_cec0ec,*lb36_cec0cc,*lb36_cec0b8,*lb36_cec0c0,*lb36_cec058,*lb36_cec084;
extern int lb36_d01a20,lb36_cf27f4,lb36_cf27f8,lb36_cefc90,lb36_cebd5c;extern bool lb36_d28d15,lb36_d28c8a;extern LB36Color lb36_d29804;
int lb36_sound4541b0(unsigned,int,int);string lb36_ending490080();int lb36_max9cdb60(int,int)throw();int lb36_distance40a3f0(const LB36Point&,const LB36Point&)throw();
struct LB36Assimilate:LB36Console{char undecoded6c[0x15c-0x6c];vector<LB36CEffect*>effects;int undecoded16c,phase,distance,count;void start969b60();};
void LB36Assimilate::start969b60(){
 lb36_cec054->render();lb36_d2d2a0.stop5003b0();lb36_d2d2a0.reset4544e0();lb36_cefa90->halt419c50();lb36_sound4541b0(117,0,0);
 string name=lb36_ending490080();
 effects.push_back(new LB36CEffect(this,LB36Rect(0,0,lb36_cec0b0->width44b0d0(),lb36_d01a20),24));lb36_d223f0.high4ab670()->copy429fe0(effects.back(),LB36Point(0,0),&LB36Rect(0,0,lb36_cec0b0->width44b0d0(),lb36_d01a20));effects.back()->animate48c3f0("A_CEffect_Assimilate_"+name+"_CLog");
 effects.push_back(new LB36CEffect(this,LB36Rect(lb36_cec0c8->pos417480().x,0,lb36_cec0c8->width44b0d0(),lb36_d01a20),24));lb36_d223f0.high4ab670()->copy429fe0(effects.back(),LB36Point(0,0),&LB36Rect(lb36_cec0c8->pos417480().x,0,lb36_cec0c8->width44b0d0(),lb36_d01a20));effects.back()->animate48c3f0("A_CEffect_Assimilate_"+name+"_CAllies");
 effects.push_back(new LB36CEffect(this,LB36Rect(lb36_cec074->pos417480().x,0,lb36_cec074->width44b0d0(),lb36_cec078->pos417480().y),24));lb36_d223f0.high4ab670()->copy429fe0(effects.back(),LB36Point(0,0),&LB36Rect(lb36_cec074->pos417480().x,0,lb36_cec074->width44b0d0(),lb36_cec078->pos417480().y));effects.back()->animate48c3f0("A_CEffect_Assimilate_"+name+"_CHud");
 effects.push_back(new LB36CEffect(this,LB36Rect(lb36_cec078->pos417480().x,lb36_cec078->pos417480().y,lb36_cec078->width44b0d0(),lb36_cec078->height4174c0()),24));lb36_d223f0.high4ab670()->copy429fe0(effects.back(),LB36Point(0,0),&LB36Rect(lb36_cec078->pos417480().x,lb36_cec078->pos417480().y,lb36_cec078->width44b0d0(),lb36_cec078->height4174c0()));effects.back()->animate48c3f0("A_CEffect_Assimilate_"+name+"_CScan");
 effects.push_back(new LB36CEffect(this,LB36Rect(lb36_cec07c->pos417480().x,lb36_cec07c->pos417480().y,lb36_cec07c->width44b0d0(),lb36_cec07c->height4174c0()),24));lb36_d223f0.high4ab670()->copy429fe0(effects.back(),LB36Point(0,0),&LB36Rect(lb36_cec07c->pos417480().x,lb36_cec07c->pos417480().y,lb36_cec07c->width44b0d0(),lb36_cec07c->height4174c0()));effects.back()->animate48c3f0("A_CEffect_Assimilate_"+name+"_CEvasion");
 effects.push_back(new LB36CEffect(this,LB36Rect(lb36_cec088->pos417480().x,lb36_cec088->pos417480().y,lb36_cec088->width44b0d0(),lb36_cec088->height4174c0()),24));lb36_d223f0.high4ab670()->copy429fe0(effects.back(),LB36Point(0,0),&LB36Rect(lb36_cec088->pos417480().x,lb36_cec088->pos417480().y,lb36_cec088->width44b0d0(),lb36_cec088->height4174c0()));effects.back()->animate48c3f0("A_CEffect_Assimilate_"+name+"_CParts");
 if(lb36_cefc90!=1){
 effects.push_back(new LB36CEffect(this,LB36Rect(lb36_cec08c->pos417480().x,lb36_cec08c->pos417480().y,lb36_cec08c->width44b0d0(),lb36_cec08c->height4174c0()),24));lb36_d223f0.high4ab670()->copy429fe0(effects.back(),LB36Point(0,0),&LB36Rect(lb36_cec08c->pos417480().x,lb36_cec08c->pos417480().y,lb36_cec08c->width44b0d0(),lb36_cec08c->height4174c0()));effects.back()->animate48c3f0("A_CEffect_Assimilate_"+name+"_CInventory");
 }
 effects.push_back(new LB36CEffect(this,LB36Rect(lb36_cec054->pos417480().x,lb36_cec054->pos417480().y,lb36_cec054->width44b0d0(),lb36_cec054->height4174c0()),25));lb36_cec054->copy429fe0(effects.back(),LB36Point(0,0),0);effects.back()->animate48c3f0("A_CEffect_Assim_Asci_"+lb36_ending490080());
 LB36Point temp=lb36_cec054->offset458ef0();LB36Point first,last;lb36_cec054->range8051f0(&first,&last);
 for(int a=first.x,mode=lb36_max9cdb60(temp.x,0);a<=last.x&&mode<lb36_cf27f4;a++,mode++){
  for(int base=first.y,slots=lb36_max9cdb60(temp.y,0);base<=last.y&&slots<lb36_cf27f8;base++,slots++){
   effects.back()->put4181a0(mode,slots,LB36XCell(lb36_d28d15?3:2,(*lb36_cfd44c.at9ceda0(a,base))->ascii66a830(),(*lb36_cfd44c.at9ceda0(a,base))->color66a680(),lb36_d29804));lb36_cefc4c->reveal7243c0(a,base,true);
  }
 }
 phase=-3;count=0;LB36Point pt;lb36_cec054->center805020(&pt);distance=lb36_distance40a3f0(pt,lb36_cec054->max4174e0());
 lb36_cec0f4->hide417ba0(true);lb36_cec0b0->hide417ba0(true);lb36_cec0d0->hide417ba0(true);
 lb36_cec0d4->hide417ba0(!(lb36_cefc90&&lb36_cec0d0->visible417610()));lb36_cec0d8->hide417ba0(!lb36_cec0d0->visible417610());lb36_cec0dc->hide417ba0(!lb36_cec0d0->visible417610());lb36_cec0e4->hide417ba0(!(!lb36_d28c8a&&lb36_cec0d0->visible417610()));lb36_cec0e8->hide417ba0(!(lb36_cec0d0->visible417610()&&lb36_cebd5c==2));lb36_cec0ec->hide417ba0(!(lb36_cec0d0->visible417610()&&lb36_cebd5c==2));
 lb36_cec0c8->hide417ba0(true);
 lb36_cec0cc->hide417ba0(true);
 lb36_cec0b8->hide417ba0(true);
 lb36_cec0c0->hide417ba0(true);
 lb36_cec054->hide417ba0(true);
 lb36_cec058->hide417ba0(true);
 lb36_cec074->hide417ba0(true);
 lb36_cec078->hide417ba0(true);
 lb36_cec07c->hide417ba0(true);
 lb36_cec084->hide417ba0(true);
 lb36_cec088->hide417ba0(true);
 lb36_cec08c->hide417ba0(true);
}
