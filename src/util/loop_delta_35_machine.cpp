#include <string>
#include <vector>
#include <memory>
#include <cstddef>
using std::string;
// NOTE: private names; full native owned layouts and borrowed definition/record prefixes.
struct D35Point{int x,y;D35Point(int,int)throw();};
struct D35Color{unsigned char r,g,b;};
template<class T>struct D35Slots{T*first,*last,*end;std::allocator<T>allocator;D35Slots();~D35Slots();unsigned size9b9260()const throw();T&index9b81f0(unsigned)throw();const T&back9b6540()const throw();void push9b9280(const T&);};
struct D35Con;struct D35Engine;struct D35Title;struct D35Event{int type;D35Point point;};
struct D35Cell{int font,glyph,value;D35Color fore,back;};
struct D35Buffer{int width,height;D35Cell*data;D35Buffer();~D35Buffer();};
struct D35Con{
 virtual ~D35Con();virtual void resize(int,int);virtual bool mouseEnter();virtual void mouseLeave();virtual bool input(D35Event*);virtual void inputMouse(int,int);virtual void update();virtual void render();virtual void open();virtual void close();virtual int getFrame();virtual void trigger8fd710(const string&,int);
 D35Con*parent;D35Buffer buffer;int font,fontData;D35Point pos,offset;D35Color fg,bg;int unknown34,unknown38;float scaleX,scaleY;D35Slots<D35Con*>children;bool hidden;int unknown58;bool unknown5c,unknown5d;int state;D35Engine*engine;D35Title*title;
 void animate48c3f0(string);void copy429f10(std::vector<D35Con*>*,bool);void remove417dd0(D35Con*);
};
struct D35Text:D35Con{string text;D35Text(D35Con*,const D35Point&,const string&,int,int,int);~D35Text();};
struct D35Record{int type,index;bool flag;};
struct D35Link{char undecoded00[0xc];int security;char undecoded10[8];D35Slots<D35Record*>records;char undecoded28[0x14];int deadline;string name65cc80();};
struct D35Def{char undecoded00[0xf8];int type;};
struct D35Prop{D35Link*link45cb30()throw();D35Def*def9b8f00()throw();const string&name45c590()throw();};
struct D35HP{int id;D35HP()throw();D35Prop*get9b64f0()const throw();};
struct D35Target:D35Con{bool alternate;D35Record*record;int unknown74,key,state;string label;D35Target(D35Con*,int,bool,D35HP,D35Record*,int);~D35Target();};
struct D35ShellText;struct D35UnknownA;struct D35UnknownB;struct D35UnknownC;struct D35UnknownD;struct D35UnknownE;struct D35UnknownF;struct D35UnknownG;
struct D35Shell:D35Con{unsigned tick;D35HP prop;D35Slots<D35ShellText*>text;int unknown84,unknown88;D35Slots<D35ShellText*>lines;unsigned tick9c;int unknowna0,unknowna4;D35Slots<D35UnknownA>listA;D35Slots<D35UnknownB>listB;D35Slots<D35UnknownC>listC;int unknownd8;D35Slots<D35UnknownD>listD;int unknownec,unknownf0;D35Slots<D35UnknownE>listE;D35Slots<D35UnknownF>listF;D35Slots<D35UnknownG>listG;int unknown124;D35Shell(D35Con*,D35HP);~D35Shell();};
struct D35Map{int turn464270()throw();};
extern D35Map*d35_cefc4c;extern D35Con*d35_cec034;
string d35_int4051f0(int);bool d35_even406320(int)throw();
struct D35Machine:D35Con{unsigned tick;D35HP prop;bool blocked;D35Slots<D35Target*>targets;D35Target*selected;int itemHandle,unknown90,unknown94;void trigger8fd710(const string&,int);};
static_assert(sizeof(D35Con)==0x6c&&sizeof(D35Text)==0x88&&sizeof(D35Target)==0x9c&&sizeof(D35Shell)==0x128,"actual allocated owner extents");
static_assert(offsetof(D35Machine,prop)==0x70&&offsetof(D35Machine,targets)==0x78,"machine fields");
void D35Machine::trigger8fd710(const string&command,int value){
 if(command=="content"){
  D35Link*line=prop.get9b64f0()->link45cb30();int y=2;
  string title=prop.get9b64f0()->def9b8f00()->type==6?prop.get9b64f0()->name45c590()+" - Unrestricted Access":(prop.get9b64f0()->def9b8f00()->type==7?string(prop.get9b64f0()->name45c590()):(prop.get9b64f0()->def9b8f00()->type==8?string(prop.get9b64f0()->name45c590()):line->name65cc80()+" - Restricted Access"));
  D35Text*child=new D35Text(this,D35Point(2,y),title,0,0,-1);child->animate48c3f0("A_CHack_Text");y+=2;
  if(prop.get9b64f0()->def9b8f00()->type==6)child=new D35Text(this,D35Point(3,y),"                OPEN SYSTEM                ",0,0,-1);
  else if(prop.get9b64f0()->def9b8f00()->type==7)child=new D35Text(this,D35Point(3,y),"              UNKNOWN SYSTEM               ",0,0,-1);
  else if(prop.get9b64f0()->def9b8f00()->type==8)child=new D35Text(this,D35Point(3,y),"                 ARCHIVES                  ",0,0,-1);
  else child=new D35Text(this,D35Point(3,y),"              SECURITY LEVEL "+d35_int4051f0(line->security)+"              ",0,0,-1);
  child->animate48c3f0("A_CMachine_Security_"+(prop.get9b64f0()->def9b8f00()->type<6?d35_int4051f0(line->security):string("0")));y+=2;
  child=new D35Text(this,D35Point(2,y),"Targets",0,0,-1);child->animate48c3f0("A_CHack_Header");y++;
  if(prop.get9b64f0()->def9b8f00()->type==0){if(d35_cefc4c->turn464270()<=line->deadline)blocked=true;else line->deadline=0;}
  int count=97;unsigned index=0;int row=0;
  for(;index<line->records.size9b9260()&&targets.size9b9260()<25;index++){
   targets.push9b9280(new D35Target(this,y,d35_even406320(row),prop,line->records.index9b81f0(index),count));row++;y++;count++;
  }
  targets.push9b9280(new D35Target(this,y,d35_even406320(targets.size9b9260()),D35HP(),0,122));
  new D35Shell(d35_cec034,prop);
 }else if(command=="zhack_override"){
  copy429f10(0,false);remove417dd0(targets.back9b6540());animate48c3f0("A_CMachine_ZHack_Inter");
 }
}
