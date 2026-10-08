// NOTE: private partial layouts and external call-site aliases for inventory reopen8a2ce0.
#include <string>
#include <vector>
using namespace std;
struct LC27Point{int x,y;LC27Point(int)throw();LC27Point(int,int)throw();LC27Point(const LC27Point&)throw();};
struct LC27Color{unsigned char r,g,b;LC27Color()throw();LC27Color(int,int,int)throw();LC27Color(const LC27Color&)throw();LC27Color&operator=(LC27Color)throw();};
struct LC27XCell{int font,glyph,value;LC27Color fore,back;};
struct LC27Buffer{int width,height;LC27XCell*data;LC27Buffer();~LC27Buffer();};
struct LC27Event;
struct LC27XConsole{virtual ~LC27XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LC27Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LC27XConsole*parent;LC27Buffer buffer;int font,fontType;LC27Point position,absolutePosition;LC27Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LC27XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 void remove(LC27XConsole*);void reset();void fore(LC27Color);void back(LC27Color);void enable(int);void print(int,int,const string&);int width()throw();LC27Point absolute(LC27Point)throw();void row(int,int,int,LC27Color);void rect(int,int,int,int,LC27Color);void put(int,int,int,LC27Color,LC27Color,int);};
struct LC27Engine;struct LC27Title;struct LC27Rect;
struct LC27Console:LC27XConsole{virtual ~LC27Console();virtual void resize(int,int);virtual bool input(LC27Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LC27Engine*engine;LC27Title*title;LC27Console(LC27XConsole*,int,int,int,int,int,bool,int);void frame(LC27Rect*,LC27Color,bool,bool);void baseRender();void animate48c3f0(string);};
static_assert(sizeof(LC27XCell)==20&&sizeof(LC27XConsole)==0x60&&sizeof(LC27Console)==0x6c,"actual console owners/layout");

struct LC27Rect{int x,y,w,h;LC27Rect(int,int,int,int)throw();};
struct LC27EffectType;struct LC27EffectPair{LC27EffectType*type;int value;};
struct LC27Item;struct LC27Entity;
struct LC27HI{int id;LC27HI()throw();LC27Item*get9b65b0()const throw();bool valid9b7230()const throw();bool operator==(LC27HI)const throw();};
struct LC27H{int id;LC27H()throw();LC27Entity*get9b6570()const throw();};
struct LC27Item{int type44aec0()throw();int index457820()throw();int rank457840()throw();int count4578c0()throw();LC27EffectPair*has457b70(int);};
struct LC27Entity{vector<LC27HI>*items45ab00()throw();unsigned collect5cb830(vector<LC27HI>*);int total5c8e20(int*);};
struct LC27Map{LC27H player4630f0()throw();bool blocked71bbd0();};extern LC27Map*lc27_cefc4c;
struct LC27Row:LC27Console{LC27HI item;};
struct LC27Button:LC27Console{unsigned tick;unsigned char reversed;};
struct LC27Buttons:LC27Console{vector<LC27Button*>buttons;};
struct LC27ModeReport:LC27Console{unsigned tick;~LC27ModeReport();LC27ModeReport(LC27XConsole*,const LC27Rect&,string);};
struct LC27Info:LC27Console{bool hidden4175f0()throw();LC27HI selected4aebc0()throw();void show8b4500(LC27H,LC27HI,LC27H,const LC27Point*,int,bool);};extern LC27Info*lc27_cec11c;
struct LC27Parts{bool swap89c350(LC27HI,int);};extern LC27Parts*lc27_cec088;
extern bool lc27_cefa5f;extern int lc27_cefc90;extern int lc27_caed20;extern vector<int>lc27_cf4830;
int lc27_sound4541b0(unsigned,int,int);void lc27_sort8a2a40(vector<LC27HI>&);
void lc27_erase9da940(vector<LC27HI>&,int);void lc27_step9d6440(vector<LC27HI>&,int&);void lc27_insert9d8fc0(vector<LC27HI>&,unsigned,LC27HI);void lc27_append9d49c0(vector<LC27HI>&,vector<LC27HI>&);void lc27_prepend9e2fc0(vector<LC27HI>&,vector<LC27HI>&);
struct LC27Event{int type;};
struct LC27Inventory:LC27Console{bool mode;unsigned tick;vector<LC27Row*>records;int a,b;LC27Row*r0,*r1;LC27HI selected;LC27Buttons*buttons;LC27ModeReport*report;vector<LC27HI>history;vector<int>ticks;
 bool hidden4175f0()throw();bool base429d00(LC27Event*);int height4174c0()throw();void reset8a53c0();void prev8a29b0();void next8a2930();void reopen8a2ce0(int,LC27HI);void clear4aa7c0();bool equip8a3f20(LC27HI,bool,int,bool);int select8a4ec0(LC27HI,bool);bool input8a5c50(LC27Event*);
};
#define ORDER(V,CMP,ICMP,F,N) {vector<LC27HI>V;V.push_back(i.back());i.pop_back();while(!i.empty()){if(V.back().get9b65b0()->F() CMP i.back().get9b65b0()->F()){V.push_back(i.back());i.pop_back();}else{for(unsigned N=0;N<V.size();N++){if(i.back().get9b65b0()->F() ICMP V[N].get9b65b0()->F()){lc27_insert9d8fc0(V,N,i.back());i.pop_back();break;}}}}i=V;}

static_assert(sizeof(LC27Inventory)==0xc0,"actual borrowed inventory owner extent");
void lc27_error404f10(string,string);
void LC27Inventory::reopen8a2ce0(int mode,LC27HI item){
 switch(mode){case 2:if(!r0)return;break;case 3:if(!r1)return;break;}
 if(r0){remove(r0);r0=0;}if(r1){remove(r1);r1=0;}
 for(unsigned j=0;j<records.size();j++){if(records[j])remove(records[j]);}
 records.clear();reset();state=3;
 switch(mode){
 case 2:{vector<LC27HI>i;lc27_cefc4c->player4630f0().get9b6570()->collect5cb830(&i);
 for(int count=9;count>0;count--){b--;if(b<0){a--;if(a<0){b=0;a=0;break;}b=i[a].get9b65b0()->count4578c0()-1;}}break;}
 case 3:{vector<LC27HI>i;lc27_cefc4c->player4630f0().get9b6570()->collect5cb830(&i);
 int count=i.size()-1;int current=i[count].get9b65b0()->count4578c0()-1;
 for(int step=9;step>0;step--){current--;if(current<0){count--;if(count<0){current=0;count=current;break;}current=i[count].get9b65b0()->count4578c0()-1;}}
 for(int next=9;next>0;next--){b++;if(b>i[a].get9b65b0()->count4578c0()-1){a++;b=0;if(a>count){a=count;b=current;break;}else if(a==count&&b==current)break;}}
 break;}
 case 0:b=0;a=0;break;
 case 1:if(lc27_cefc4c->player4630f0().get9b6570()->total5c8e20(0)<=10){b=0;a=0;}else{
 vector<LC27HI>i;lc27_cefc4c->player4630f0().get9b6570()->collect5cb830(&i);a=i.size()-1;b=i.back().get9b65b0()->count4578c0()-1;
 for(int count=9;count>0;count--){b--;if(b<0){a--;b=i[a].get9b65b0()->count4578c0()-1;}}}break;
 case 5:if(item.valid9b7230()){
 vector<LC27HI>*base=lc27_cefc4c->player4630f0().get9b6570()->items45ab00();vector<LC27HI>i(*base);vector<LC27HI>p;
 base->clear();for(int current=i.size()-1;current>=0;current--){if(i[current].get9b65b0()->type44aec0()!=4){base->push_back(i[current]);lc27_erase9da940(i,current);}}
 if(!i.empty())ORDER(group,<,<=,index457820,j)
 lc27_sort8a2a40(i);p=i;i.clear();
 for(int j=0;static_cast<unsigned>(j)<p.size();j++){if(p[j].get9b65b0()->has457b70(86)){i.push_back(p[j]);lc27_step9d6440(p,j);}}
 if(!i.empty()){if(!i.empty())ORDER(group,<,<=,index457820,j)lc27_append9d49c0(p,i);}
 i.clear();for(int j=0;static_cast<unsigned>(j)<p.size();j++){if(lc27_cf4830[p[j].get9b65b0()->index457820()]==0){i.push_back(p[j]);lc27_step9d6440(p,j);}}
 if(!i.empty()){if(!i.empty())ORDER(group,<,<=,rank457840,j)lc27_append9d49c0(p,i);}
 lc27_append9d49c0(*base,p);
 if(lc27_cefc4c->player4630f0().get9b6570()->total5c8e20(0)<=10){b=0;a=0;}else{
 vector<LC27HI>group;lc27_cefc4c->player4630f0().get9b6570()->collect5cb830(&group);
 for(unsigned j=0;j<group.size();j++){if(group[j]==item){a=j;b=0;break;}}
 if(a>0){for(int count=5;count>0;count--){b--;if(b==-1){if(a==0){b=0;break;}a--;b=group[a].get9b65b0()->count4578c0()-1;}}}
 }
 }else lc27_error404f10("CInventory::reopen()","no focus specified");
 // fall through: normalize retained window after focus reorder
 case 4:if(lc27_cefc4c->player4630f0().get9b6570()->total5c8e20(0)<=10){b=0;a=0;}else{
 vector<LC27HI>i;lc27_cefc4c->player4630f0().get9b6570()->collect5cb830(&i);
 if(static_cast<unsigned>(a)>=i.size()){b=0;a=0;break;}
 int count=a,current=b;if(b>i[a].get9b65b0()->count4578c0()-1)b=i[a].get9b65b0()->count4578c0()-1;
 int n=0;for(int step=10;step>0;step--){current++;n++;if(current>i[count].get9b65b0()->count4578c0()-1){count++;current=0;if(static_cast<unsigned>(count)>=i.size())break;}if(n==10)break;}
 if(n<10){for(int step=10-n;step>0;step--){b--;if(b==-1){if(a==0){b=0;break;}a--;b=i[a].get9b65b0()->count4578c0()-1;}}}
 }break;
 }
 history.push_back(item);ticks.push_back(lc27_caed20);animate48c3f0("CInventory_Content");
}
