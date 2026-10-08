#include <string>
#include <vector>
using namespace std;
struct LC17Point{int x,y;LC17Point(int,int)throw();LC17Point(const LC17Point&,int,int)throw();};
struct LC17Def;
struct LC17Console{virtual~LC17Console();char p4[0x68];LC17Console(LC17Console*,int,int,int,int,int,bool,int);LC17Point pos417480()throw();int height4174c0()throw();int width44b0d0()throw();void move417ac0(int,int);void set4289e0(const LC17Point&);void print4181d0(int,int,const string&);void row4297f0(int,int,int,int);void animate48c3c0(LC17Def*);void animate48c3f0(string);void remove428b20(LC17Console*);};
struct LC17Bubble{LC17Console*console;unsigned time;int type;LC17Bubble(LC17Console*,unsigned,int);~LC17Bubble();};
struct LC17Bubbles{LC17Bubble**first,**last,**capacity;allocator<LC17Bubble*>alloc;unsigned size9b9260()const throw();bool empty9b86e0()const throw();LC17Bubble*&at9b81f0(unsigned)throw();LC17Bubble*&front9b7060()throw();LC17Bubble*const&back9b6540()const throw();void push9b9d30(LC17Bubble*const&);void push9b9280(LC17Bubble*&&);};
struct LC17Strings{string*first,*last,*capacity;allocator<string>alloc;LC17Strings();~LC17Strings();unsigned size9b0650()const throw();string&at9b06a0(unsigned)throw();string&back9b06c0()throw();};
struct LC17Entry{int type;char p4[0x20];int color;char p28[0xc];int animation;};
struct LC17Entries{unsigned size9b9260()const throw();LC17Entry*&at9b81f0(unsigned)throw();};
struct LC17Message{LC17Entry*entry;string text;int row,turn;};
struct LC17Messages{LC17Message**first,**last,**capacity;allocator<LC17Message*>alloc;unsigned size9b9260()const throw();LC17Message*&at9b81f0(unsigned)throw();LC17Message*const&back9b6540()const throw();};
struct LC17Log{LC17Messages messages;char p10[0x28];bool flag;LC17Messages&get9c0790()throw();bool state4550b0()throw();};
struct LC17Defs{LC17Def*&at9b81f0(unsigned)throw();};
struct LC17Map:LC17Console{char p6c[0x10];LC17Bubbles bubbles0;LC17Bubble*current0;LC17Bubbles bubbles1;LC17Bubble*current1;LC17Bubbles bubbles2;LC17Bubble*current2;void remove49c2f0(LC17Bubble*,int);void bubble(bool);};
extern int lc17_cebd5c,lc17_d28d18,lc17_d28f6c,lc17_d28d64,lc17_d28f70,lc17_d28f84,lc17_d28f7c,lc17_d28f78,lc17_caf12c,lc17_d01a34,lc17_d01a24;extern bool lc17_d28f74,lc17_cefa77;extern unsigned lc17_caed20;extern LC17Log lc17_cf1080,lc17_d2f75c;extern LC17Console*lc17_cec054;extern LC17Map*lc17_cec058;extern LC17Entries lc17_d35b48;extern LC17Entry*lc17_cefbcc;extern LC17Defs lc17_cfe704;extern string lc17_d312d4;
bool OpT8b_Fn9daf80(int,int,int)throw();int OpX5_minInt(int,int)throw();void lc17_insert9d4440(LC17Strings&,int,string);void lc17_delete9d4950(LC17Bubbles&,int);int countRun_408000(string&,char,unsigned);
LC17Bubble::LC17Bubble(LC17Console*p,unsigned t,int kind){console=p;time=t;type=kind;}
LC17Bubble::~LC17Bubble(){if(lc17_cefa77)return;lc17_cec058->remove428b20(console);}
void LC17Map::bubble(bool combat){
 int root;
 if(combat){if(lc17_cebd5c!=2)return;root=1;}else switch(lc17_cebd5c){case 0:manual:if(lc17_d28d18!=1||lc17_d28f6c==0)return;root=0;break;case 1:if(lc17_d28f74){goto manual;}else return;break;case 2:if(lc17_d28f74)goto manual;if(lc17_d28d64!=3)return;root=2;break;}
 LC17Messages&str2=combat?lc17_cf1080.get9c0790():lc17_d2f75c.get9c0790();
 string range=root==0?"A_CLogMsg_Map_FCmb_Fa":root==2?"A_CLogMsg_Map_Combat_Fa":"A_CLogMsg_Map_Log_Fa";
 unsigned time=lc17_caed20+(root==0?lc17_d28f70:root==2?lc17_d28f84:lc17_d28f7c);
 if(lc17_cebd5c==2&&str2.back9b6540()->entry&&OpT8b_Fn9daf80(813,str2.back9b6540()->entry->type,899)){range="A_CLogMsg_Map_Tut_Fa";time=lc17_caed20+10000;}
 LC17Bubbles&vec=root==0?bubbles0:(root==2?bubbles2:bubbles1);LC17Bubble**cur=root==0?&current0:root==2?&current2:&current1;
 LC17Strings base;int len=str2.back9b6540()->row;for(int i=str2.size9b9260()-1;i>=0&&str2.at9b81f0(i)->row==len;i--){lc17_insert9d4440(base,0,str2.at9b81f0(i)->text);}
 LC17Entry*entity=str2.back9b6540()->entry?lc17_d35b48.at9b81f0(str2.back9b6540()->entry->color):lc17_cefbcc;
 int m1,width,n;
 switch(root){case 0:m1=0;width=lc17_cebd5c==2?lc17_d28f78+3:1;n=OpX5_minInt(lc17_cec054->height4174c0()*lc17_caf12c-2,width+lc17_d28f6c);break;case 1:case 2:m1=root==2?lc17_d01a34:0;width=1;n=((lc17_d28d64==2)+1)*lc17_d28f78+1;break;}
 if(lc17_cebd5c==2&&root==1&&lc17_d28d64==2){for(int i=0;i<vec.size9b9260();i++)if(vec.at9b81f0(i)->console->pos417480().x>0)vec.at9b81f0(i)->console->set4289e0(LC17Point(vec.at9b81f0(i-1)->console->pos417480(),0,1));if(*cur)(*cur)->console->set4289e0(LC17Point(vec.back9b6540()->console->pos417480(),0,1));n++;}
 int y;if(*cur){y=(*cur)->console->pos417480().y;delete *cur;*cur=0;}else y=width;
 int first=0;if(string(1,base.back9b06c0().back())==lc17_d312d4&&!vec.empty9b86e0()){first=1;if(combat?lc17_cf1080.state4550b0():lc17_d2f75c.state4550b0())first=2;}
 if(first==1){base.back9b06c0().insert(0,1,' ');base.back9b06c0()+=" ";LC17Bubble*item=new LC17Bubble(new LC17Console(lc17_cec058,base.back9b06c0().size(),1,m1,vec.back9b6540()->console->pos417480().y,0,false,-1),time,root);remove49c2f0(vec.back9b6540(),root);vec.push9b9d30(item);vec.back9b6540()->console->print4181d0(0,0,base.back9b06c0());vec.back9b6540()->console->animate48c3c0(lc17_cfe704.at9b81f0(entity->animation));vec.back9b6540()->console->animate48c3f0(range);}
 else for(int i=first==2?base.size9b0650()-1:0;i<base.size9b0650();i++){
  if(y==n){if(root==0)y=width;else{remove49c2f0(vec.front9b7060(),root);for(int j=0;j<vec.size9b9260();j++)vec.at9b81f0(j)->console->move417ac0(0,-1);y--;}}
  if(!vec.empty9b86e0()&&vec.front9b7060()->console->pos417480().y==y)lc17_delete9d4950(vec,0);
  base.at9b06a0(i).insert(0,1,' ');base.at9b06a0(i)+=" ";vec.push9b9280(new LC17Bubble(new LC17Console(lc17_cec058,base.at9b06a0(i).size(),1,m1,y,0,false,-1),time,root));vec.back9b6540()->console->print4181d0(0,0,base.at9b06a0(i));vec.back9b6540()->console->animate48c3c0(lc17_cfe704.at9b81f0(entity->animation));vec.back9b6540()->console->animate48c3f0(range);y++;
 }
 if(y<n&&vec.front9b7060()->console->pos417480().y==y)lc17_delete9d4950(vec,0);
 int x2=-1;if(lc17_cebd5c==2&&root==1&&lc17_d28d64==2&&vec.size9b9260()>lc17_d28f78+1){x2=1;for(int i=lc17_d28f78+1;i<vec.size9b9260();i++,x2++)vec.at9b81f0(i)->console->set4289e0(LC17Point(lc17_d01a24,x2));}
 *cur=new LC17Bubble(new LC17Console(lc17_cec058,vec.back9b6540()->console->width44b0d0(),1,vec.back9b6540()->console->pos417480().x,x2!=-1?x2:y,0,false,-1),time,root);
 LC17Point b(countRun_408000(base.back9b06c0(),' ',0),base.back9b06c0().size()-2);(*cur)->console->row4297f0(b.x,0,b.y-b.x+1,129);(*cur)->console->animate48c3f0("A_CLogMsg_GR1_Map_Log");(*cur)->console->animate48c3f0(range);
}
