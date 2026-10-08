// NOTE: private borrowed partial layouts and complete native Console/Effect owners for Sigix integration9682e0.
#include <string>
#include <vector>
using namespace std;
struct LB32Point{int x,y;LB32Point()throw();LB32Point(int)throw();LB32Point&operator=(const LB32Point&)throw();LB32Point&add409a30(const LB32Point&)throw();LB32Point(int,int)throw();LB32Point(const LB32Point&)throw();};
struct LB32Color{unsigned char r,g,b;LB32Color()throw();LB32Color(int,int,int)throw();LB32Color(const LB32Color&)throw();LB32Color&operator=(LB32Color)throw();};
struct LB32XCell{int font,glyph,value;LB32Color fore,back;};
struct LB32Buffer{int width,height;LB32XCell*last;LB32Buffer();~LB32Buffer();};
struct LB32Event;struct LB32Rect;
struct LB32XConsole{virtual ~LB32XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LB32Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LB32XConsole*parent;LB32Buffer buffer;int font,fontType;LB32Point position,absolutePosition;LB32Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LB32XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 bool contains(const LB32Point&)throw();void remove(LB32XConsole*);void reset();void fore(LB32Color);void back(LB32Color);void enable(int);void print(int,int,const string&);int width()throw();LB32Point absolute(LB32Point)throw();void row(int,int,int,LB32Color);void rect(int,int,int,int,LB32Color);void put(int,int,int,LB32Color,LB32Color,int);bool hidden4175f0()throw();LB32Point pos417480()throw();int width44b0d0()throw();int height4174c0()throw();void pos4289e0(const LB32Point&);void copy429fe0(LB32XConsole*,LB32Point&,const LB32Rect*);int layer44a7d0()throw();};
struct LB32Engine;struct LB32Title;struct LB32Rect;
struct LB32Console:LB32XConsole{virtual ~LB32Console();virtual void resize(int,int);virtual bool input(LB32Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LB32Engine*engine;LB32Title*title;LB32Console(LB32XConsole*,int,int,int,int,int,bool,int);void frame(LB32Rect*,LB32Color,bool,bool);void baseRender();void animate48c3f0(string);void close8b5080();unsigned char active48e740()throw();void close7b60e0();void open894120(bool);void open965220();int equip81a0e0(int);void bubble8758d0(bool);void scroll7b4f10();void move8069e0(LB32Point,bool);};
static_assert(sizeof(LB32XCell)==20&&sizeof(LB32XConsole)==0x60&&sizeof(LB32Console)==0x6c,"actual console owners/layout");


struct LB32Rect{int x,y,width,height;LB32Rect(int,int,int,int)throw();};
struct LB32CEffect:LB32Console{int kind;LB32CEffect(LB32XConsole*,const LB32Rect&,int);virtual ~LB32CEffect();};
static_assert(sizeof(LB32CEffect)==112,"actual full Console owner plus mode kind");
struct LB32Entity;struct LB32H{int id;LB32H()throw();LB32Entity*get9b6570()const throw();};
struct LB32Item;struct LB32HI{int id;LB32Item*get9b65b0()const throw();};
struct LB32ItemDef{char undecoded[0x76];bool capture;};
struct LB32Item{LB32ItemDef*def9b4350()throw();int index9fcd80()throw();int type457820()throw();int subtype4578a0()throw();bool equip57a190(LB32H,int,bool,bool);};
struct LB32Entity{int slots45a860()throw();int*slots45a840()throw();vector<LB32HI>*inventory45ab00()throw();const LB32Point&position45a4a0()throw();void remove637bb0();void change5dccb0(const LB32Point&,bool);};
struct LB32World{LB32H player4630f0()throw();void reveal720c90(bool);void update724a10();};extern LB32World*lb32_cefc4c;
struct LB32Player{void clear46ddd0();};extern LB32Player lb32_cf45d8;
struct LB32Rex{LB32XConsole*highlighter4ab670()throw();void add426b60(LB32XConsole*,int);};extern LB32Rex lb32_d223f0;
struct LB32Marker{void reset49b870();};extern LB32Marker lb32_d1d9c0;
struct LB32FxDef;struct LB32Owner;struct LB32Owned;struct LB32Fx{void init503b20(LB32Owner*,LB32FxDef*,const LB32Point&,const LB32Point&,const LB32Point*,const LB32Point*,LB32Owned*,int,LB32Fx*);};struct LB32Owner{LB32Fx*acquire508610();};extern LB32Owner*lb32_cefc50;
extern LB32Console *lb32_cec118,*lb32_cec11c,*lb32_cec120,*lb32_cec0b0,*lb32_cec034,*lb32_cec088,*lb32_cec08c,*lb32_cec138,*lb32_cec058,*lb32_cec0b4,*lb32_cec074,*lb32_cec0c8,*lb32_cec07c,*lb32_cec078,*lb32_cec054;
extern unsigned lb32_caed20;extern int lb32_cefc90,lb32_d25568,lb32_d2556c;extern bool lb32_cf4d14,lb32_cf4d15,lb32_cf4a00;extern unsigned char lb32_d25450;
extern vector<int>lb32_cf4810,lb32_cf4820,lb32_cf4830;
int lb32_sound4541b0(unsigned,int,int);void lb32_parts4b3540(LB32XConsole*);LB32Point lb32_pos4b33b0();bool lb32_msg5111e0(int,const string*,const string*,const string*,LB32H,LB32H,const LB32Point*,bool);bool lb32_lookup9d7980(const string&,LB32FxDef**);
struct LB32Sigix:LB32Console{char undecoded6c[0x9c-0x6c];vector<LB32CEffect*>effects;int total;unsigned end,next;int phase;void integrate9682e0(LB32H);};
void LB32Sigix::integrate9682e0(LB32H target){
 end=lb32_caed20+2500;next=lb32_caed20+250;phase=0;lb32_sound4541b0(151,0,0);
 LB32H first=lb32_cefc4c->player4630f0();lb32_cec054->equip81a0e0(0);total=first.get9b6570()->slots45a860();int*slots=first.get9b6570()->slots45a840();slots[0]=1;slots[1]=3;slots[2]=3;slots[3]=2;
 lb32_cf45d8.clear46ddd0();lb32_cf4d14=false;if(slots[2]>4)lb32_cf4d15=false;
 if(!lb32_cec118->hidden4175f0())lb32_cec118->close8b5080();if(!lb32_cec11c->hidden4175f0())lb32_cec11c->close8b5080();if(!lb32_cec120->hidden4175f0())lb32_cec120->close8b5080();if(lb32_cec0b0->active48e740())lb32_cec0b0->close7b60e0();
 lb32_parts4b3540(lb32_cec034);lb32_cf4a00=true;lb32_cec088->open894120(true);lb32_cec08c->pos4289e0(lb32_pos4b33b0());lb32_cec138->open965220();
 do{if(lb32_msg5111e0(800,&string("Integrating with Sigix Exoskeleton..."),0,0,LB32H(),LB32H(),0,false))lb32_cec058->bubble8758d0(true);lb32_cec0b4->scroll7b4f10();}while(false);
 if(lb32_d25450){lb32_d25568=lb32_d2556c=0;}
 vector<LB32HI>*base=target.get9b6570()->inventory45ab00();while(!base->empty()){if(base->front().get9b65b0()->def9b4350()->capture){lb32_cf4810.push_back(base->front().get9b65b0()->index9fcd80());lb32_cf4820.push_back(lb32_cf4830[base->front().get9b65b0()->type457820()]!=0);}base->front().get9b65b0()->equip57a190(first,base->front().get9b65b0()->subtype4578a0(),true,false);}
 LB32Point count=target.get9b6570()->position45a4a0();target.get9b6570()->remove637bb0();first.get9b6570()->change5dccb0(count,true);
 effects.push_back(new LB32CEffect(this,LB32Rect(lb32_cec088->pos417480().x,lb32_cec088->pos417480().y,lb32_cec088->width44b0d0(),lb32_cec088->height4174c0()),17));lb32_d223f0.highlighter4ab670()->copy429fe0(effects.back(),LB32Point(0,0),&LB32Rect(lb32_cec088->pos417480().x,lb32_cec088->pos417480().y,lb32_cec088->width44b0d0(),lb32_cec088->height4174c0()));effects.back()->animate48c3f0("A_CEffect_SigExo_CParts");
 effects.push_back(new LB32CEffect(this,LB32Rect(lb32_cec074->pos417480().x,lb32_cec074->pos417480().y,lb32_cec074->width44b0d0(),lb32_cec074->height4174c0()),17));lb32_d223f0.highlighter4ab670()->copy429fe0(effects.back(),LB32Point(0,0),&LB32Rect(lb32_cec074->pos417480().x,lb32_cec074->pos417480().y,lb32_cec074->width44b0d0(),lb32_cec074->height4174c0()));effects.back()->animate48c3f0("A_CEffect_SigExo_CHud");
 effects.push_back(new LB32CEffect(this,LB32Rect(lb32_cec0c8->pos417480().x,lb32_cec0c8->pos417480().y,lb32_cec0c8->width44b0d0(),lb32_cec0c8->height4174c0()),17));lb32_d223f0.highlighter4ab670()->copy429fe0(effects.back(),LB32Point(0,0),&LB32Rect(lb32_cec0c8->pos417480().x,lb32_cec0c8->pos417480().y,lb32_cec0c8->width44b0d0(),lb32_cec0c8->height4174c0()));effects.back()->animate48c3f0("A_CEffect_SigExo_CAllies");
 effects.push_back(new LB32CEffect(this,LB32Rect(lb32_cec07c->pos417480().x,lb32_cec07c->pos417480().y,lb32_cec07c->width44b0d0(),lb32_cec07c->height4174c0()),17));lb32_d223f0.highlighter4ab670()->copy429fe0(effects.back(),LB32Point(0,0),&LB32Rect(lb32_cec07c->pos417480().x,lb32_cec07c->pos417480().y,lb32_cec07c->width44b0d0(),lb32_cec07c->height4174c0()));effects.back()->animate48c3f0("A_CEffect_SigExo_CEvasion");
 effects.push_back(new LB32CEffect(this,LB32Rect(lb32_cec078->pos417480().x,lb32_cec078->pos417480().y,lb32_cec078->width44b0d0(),lb32_cec078->height4174c0()),17));lb32_d223f0.highlighter4ab670()->copy429fe0(effects.back(),LB32Point(0,0),&LB32Rect(lb32_cec078->pos417480().x,lb32_cec078->pos417480().y,lb32_cec078->width44b0d0(),lb32_cec078->height4174c0()));effects.back()->animate48c3f0("A_CEffect_SigExo_CScan");
 if(lb32_cefc90!=1){ effects.push_back(new LB32CEffect(this,LB32Rect(lb32_cec08c->pos417480().x,lb32_cec08c->pos417480().y,lb32_cec08c->width44b0d0(),lb32_cec08c->height4174c0()),17));lb32_d223f0.highlighter4ab670()->copy429fe0(effects.back(),LB32Point(0,0),&LB32Rect(lb32_cec08c->pos417480().x,lb32_cec08c->pos417480().y,lb32_cec08c->width44b0d0(),lb32_cec08c->height4174c0()));effects.back()->animate48c3f0("A_CEffect_SigExo_CInv");
 }
 lb32_d1d9c0.reset49b870();lb32_cec054->move8069e0(first.get9b6570()->position45a4a0(),false);lb32_cec054->render();
 LB32CEffect*mode=new LB32CEffect(this,LB32Rect(lb32_cec054->pos417480().x,lb32_cec054->pos417480().y,lb32_cec054->width44b0d0(),lb32_cec054->height4174c0()),18);
 lb32_cec054->copy429fe0(mode,LB32Point(0,0),0);effects.push_back(mode);mode->animate48c3f0("A_CEffect_SigExo_MapOld");lb32_d223f0.add426b60(mode,mode->layer44a7d0()+1);
 lb32_cefc4c->reveal720c90(false);lb32_cefc4c->update724a10();lb32_cec054->render();
 effects.push_back(new LB32CEffect(this,LB32Rect(lb32_cec054->pos417480().x,lb32_cec054->pos417480().y,lb32_cec054->width44b0d0(),lb32_cec054->height4174c0()),18));lb32_cec054->copy429fe0(effects.back(),LB32Point(0,0),0);effects.back()->animate48c3f0("A_CEffect_SigExo_MapNew");
 LB32FxDef*last;lb32_lookup9d7980("Block_Turn_Progress_SigExo",&last);lb32_cefc50->acquire508610()->init503b20(lb32_cefc50,last,LB32Point(0,0),LB32Point(0,0),0,0,0,9,0);
}
