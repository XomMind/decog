#include <string>
#include "rng.h"
using std::string;extern RNG rng;
// Private partial ABI views; names and untouched fields are placeholders.
struct LA19Point{int x,y;LA19Point(const LA19Point&)throw();int random40c130()throw();bool equal409b90(const LA19Point&)throw();};struct LA19Entity;struct LA19Prop;struct LA19Effects;struct LA19Sound;struct LA19ProcessA;struct LA19ProcessB;struct LA19TurnRecord;
struct LA19TurnRecords{int a,b,c,d;};struct LA19HI{int id;LA19HI();};
struct LA19H{int id;LA19H();LA19Entity*get9b6570()const throw();bool valid9b7230()const throw();};struct LA19HP{int id;LA19HP();LA19Prop*get9b64f0()const throw();};struct LA19HG{int id;};
struct LA19Entity{bool player5c7600()throw();int bonus5d22a0(int)throw();int bonus5d2150(int,int)throw();int bonus5d2090(int)throw();bool friendly5cb680(LA19HG)throw();const LA19Point&position45a4a0()throw();};
struct LA19Rec;struct LA19Recs{int a,b,c,d;LA19Recs(const LA19Recs&);~LA19Recs();bool empty9b86e0()const throw();};
struct LA19Effects{char data[0x14];LA19Effects(LA19Recs);~LA19Effects();};
struct LA19Explosion{char p0[0x2c];int type;char p30[0x50];bool flag80;char p81[0x1b];LA19Recs effects;};
struct LA19Ints{int a,b,c,d;LA19Sound*&at9b81f0(unsigned)throw();};struct LA19NestedInts{int a,b,c,d;LA19Ints&at9b8070(unsigned)throw();};
struct LA19MachineDef{char pad[0x20];int resistance[7];char p3c[0x14];LA19NestedInts sounds;};
struct LA19Def{char pad0[0x20];string name;char pad3c[0x24];LA19MachineDef*machine;char pad64[0x14];bool flag78;char pad79[0x13];int armor;char pad90[0x18];int resistance[7];char padc4[0x30];int f4,kind;char padfc[0x28];string message;};
struct LA19Weapon{char pad0[0x44];int category;char pad48[0xd8];LA19Point range;int type;char pad12c[0x39];bool flag165;char pad166[6];int value16c;char pad170[0x40];bool flag1b0;char pad1b1[0xc7];int*soundIndex;int soundType;LA19Sound*sound;int value457330(int)throw();};
struct LA19Process{char data[0x48];LA19Process(LA19HP,int,int,LA19ProcessA*,LA19ProcessB*,bool,bool,LA19HI,int,const LA19Point*,bool,bool);};struct LA19Machine{char pad[0x38];LA19Process*process;};
struct LA19Prop{LA19HP self;LA19Def*record;LA19Point position;bool flag10;char p11[0x1f];LA19Effects*effects;int machineID;char p38[4];int flag3c;LA19Machine*machine45cb30()throw();void remove45ce10(bool,int,bool,LA19H);bool damage65f520(int,int,bool,bool,int,LA19H,bool,bool,bool);void damage664840(LA19H,int,LA19TurnRecords*,LA19Weapon*,float,bool,LA19Explosion*,int*);};
struct LA19HPs{int a,b,c,d;LA19HP&front9b7060()throw();};struct LA19NestedHPs{int a,b,c,d;LA19HPs&at9b8070(unsigned)throw();};extern LA19NestedHPs la19_d31640;
struct LA19Cell{LA19H entity45d250()throw();};struct LA19Grid{LA19Cell**at9d0640(LA19Point&)throw();};extern LA19Grid la19_cfd44c;
struct LA19Map{void value74b060(const LA19Point&,int,int);LA19HG group463890(int)throw();};extern LA19Map*la19_cefc4c;
struct LA19UI{void update8758d0(bool);};extern LA19UI*la19_cec058;struct LA19Log{void end7b4f10()throw();};extern LA19Log*la19_cec0c4;
struct LA19Factory{bool show793450(int,bool,const string*,bool,bool);};extern LA19Factory*la19_cefaa8;
extern int la19_cf49bc[],la19_d1f3f0,la19_d28d18,la19_b93fcc,la19_b93fd0;extern bool la19_cf65bf;extern const float la19_c371b8;extern string la19_d323f8[],la19_d1f3d4;extern LA19Def*la19_cefbd8;extern LA19Point la19_d1d9fc;
void la19_increment9d06d0(int*,int,int)throw();bool la19_turn51da30(LA19TurnRecords*,int,LA19H,LA19HP,LA19HP,int,int);bool la19_effect4569a0(int,LA19H,LA19H,LA19HP,LA19H,int,int,LA19Effects*,LA19H,LA19HP,LA19HP,int);
bool la19_route5111e0(int,const string*,const string*,const string*,LA19H,LA19HP,const LA19Point*,bool);bool la19_sound454160(const LA19Point&,LA19Sound*,unsigned);
#define LA19_LOG(TEXT) do{if(la19_route5111e0(716,TEXT,0,0,LA19H(),LA19HP(),&p,true))la19_cec058->update8758d0(false);la19_cec0c4->end7b4f10();}while(false)
void LA19Prop::damage664840(LA19H attacker,int origin,LA19TurnRecords*source,LA19Weapon*weapon,float scale,bool flag,LA19Explosion*explosion,int*fixed){
 if(weapon&&weapon->value457330(67)){remove45ce10(false,1,false,LA19H());return;}
 int first=weapon?weapon->type:explosion->type;switch(first){case 10:return;}
 bool h=false;int u;
 if(first==9)u=0;
 else if(weapon){
  LA19Point first(weapon->range);
  if(attacker.get9b6570()){
   if(weapon->flag1b0&&!weapon->flag165&&attacker.get9b6570()->bonus5d22a0(102)){int i=attacker.get9b6570()->bonus5d22a0(102);first.x+=first.x*i/100;first.y+=first.y*i/100;h=true;}
   else if(origin==0){first.y+=first.y*attacker.get9b6570()->bonus5d2150(106,0)/100;la19_increment9d06d0(&first.x,attacker.get9b6570()->bonus5d2090(90)/2,first.y);}
   else if(weapon->category==22||weapon->category==23){first.x+=first.x*attacker.get9b6570()->bonus5d22a0(105)/100;if(first.x>first.y)first.y=first.x;}
  }
  u=(int)(first.random40c130()*scale);
 }else u=*fixed;
 if(explosion&&explosion->flag80&&record->f4)u=(int)(u*la19_c371b8);
 if(attacker.get9b6570()&&weapon&&(weapon->category==20||weapon->category==21)&&!weapon->flag165&&!h)u+=u*attacker.get9b6570()->bonus5d2150(103,0)/100;
 if(first<7){if(la19_cf49bc[first]&&attacker.get9b6570()&&attacker.get9b6570()->player5c7600())u+=u*la19_cf49bc[first]/100;u=u*record->resistance[first]/100*record->machine->resistance[first]/100;}
 la19_d1f3d4=la19_d323f8[first];la19_d1f3f0=u;
 if(source){LA19HP first=self;if(la19_turn51da30(source,22,LA19H(),self,LA19HP(),0,0)&&!first.get9b64f0())return;if(la19_turn51da30(source,24,LA19H(),self,LA19HP(),0,0)&&!first.get9b64f0())return;}
 else if(explosion&&!explosion->effects.empty9b86e0()){
  LA19HP first=self;LA19Effects*other=new LA19Effects(explosion->effects);bool h=la19_effect4569a0(27,attacker,LA19H(),self,LA19H(),0,0,other,LA19H(),self,LA19HP(),0);delete other;if(h&&!first.get9b64f0())return;
 }
 if(effects){LA19HP first=self;if(la19_effect4569a0(18,attacker,LA19H(),self,LA19H(),0,0,effects,LA19H(),self,LA19HP(),0)&&!first.get9b64f0())return;}
 if(first==9)return;
 if(weapon)la19_cefc4c->value74b060(position,weapon->value16c,100);
 LA19Def*n=record;LA19Point p(position);
 if(!damage65f520(u,first,0,0,origin==0?2:weapon?(weapon->category==20||weapon->category==22?3:4):5,attacker,flag,0,0)){
  if(la19_d28d18==1&&n==la19_cefbd8&&(*la19_cfd44c.at9d0640(p))->entity45d250().valid9b7230()){string text="  "+n->name+" absorbed attack";LA19_LOG(&text);}
  else if(la19_d28d18>=0&&la19_d1d9fc.equal409b90(p)&&attacker.get9b6570()&&attacker.get9b6570()->player5c7600()&&!flag10){string text="  Damage insufficient to overcome "+n->name+" armor";LA19_LOG(&text);la19_cefaa8->show793450(85,true,0,0,0);}
  if(weapon){LA19Sound*first=0,*h=0;switch(weapon->soundType){break;case 1:first=weapon->sound;break;case 2:first=record->machine->sounds.at9b8070(2).at9b81f0(*weapon->soundIndex);h=record->machine->sounds.at9b8070(3).at9b81f0(*weapon->soundIndex);break;}if(first)la19_sound454160(position,first,18);if(h)la19_sound454160(position,h,18);}
  if(record->kind==5&&!flag3c&&la19_d31640.at9b8070(machineID).front9b7060().get9b64f0()->machine45cb30()&&!la19_d31640.at9b8070(machineID).front9b7060().get9b64f0()->machine45cb30()->process&&attacker.get9b6570()&&attacker.get9b6570()->friendly5cb680(la19_cefc4c->group463890(3))&&!la19_cf65bf&&rng.chance(la19_b93fcc)){
   la19_d31640.at9b8070(machineID).front9b7060().get9b64f0()->machine45cb30()->process=new LA19Process(la19_d31640.at9b8070(machineID).front9b7060(),112,la19_b93fd0,0,0,false,false,LA19HI(),0,&attacker.get9b6570()->position45a4a0(),true,false);
  }
  if(effects){LA19HP first=self;if(la19_effect4569a0(19,attacker,LA19H(),self,LA19H(),0,0,effects,LA19H(),self,LA19HP(),0)&&!first.get9b64f0())return;}
 }else if(!n->armor&&!n->flag78&&la19_d28d18==1){string text="  "+n->name+" "+(n->message.empty()?string("damaged"):string(n->message));LA19_LOG(&text);}
}
