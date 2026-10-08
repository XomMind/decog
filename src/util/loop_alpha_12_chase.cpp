#include <string>
using std::string;
// File-private aliases, partial layouts and inferred roles; no reserved implementation.
struct LA12Point {int x,y;};
struct LA12AI;struct LA12Entity;struct LA12Group;
struct LA12H {int id;LA12H() throw();LA12Entity *get()const throw();bool operator==(LA12H)const throw();};
struct LA12HG {int id;LA12Group *get()const throw();};struct LA12Group {int type()const throw();};
struct LA12Prop {int id;LA12Prop() throw();};
struct LA12HI {int id;bool valid()const throw();};
struct LA12Entity {char pad0[0x28];LA12HG group;LA12HG getGroup() throw();const string &name() throw();int faction() throw();bool isPlayer() throw();LA12HI item(int) throw();int effect(int) throw();LA12AI *ai() throw();};
struct LA12Target {LA12H entity;int priority,threat,unknownC;LA12Target(LA12H,int,int) throw();};
struct LA12Targets {unsigned a,b,c,d;unsigned size()const throw();void*&operator[](unsigned) throw();void*const&back()const throw();void push_back(void*const&);};
struct LA12AI {LA12H self;int mode,level;char padC[0x28];int tracker;char pad38[0xb8];LA12Targets targets;char pad100[8];int engaged;bool blocked(LA12H) throw();int speed() throw();bool detected() throw();LA12H *relation(LA12H) throw();LA12Target *chase(LA12H,int,int,bool,bool*);};
struct LA12Map {LA12H player() throw();LA12H special() throw();LA12H focus() throw();bool visible(LA12H) throw();void alert(int) throw();void alerted(unsigned char) throw();};extern LA12Map *la12_cefc4c;
struct LA12Stats {bool add(unsigned,int,string,int) throw();int count(unsigned) throw();};extern LA12Stats la12_d2c658;
struct LA12Player {void achievement(int) throw();bool has(int) throw();};extern LA12Player la12_cf45d8;
struct LA12Overmind {int respond(bool,LA12H,LA12Point*) throw();bool lockdown(bool,bool,bool) throw();void known(bool) throw();void wake() throw();};extern LA12Overmind la12_cf6428;
struct LA12Flag {void set(int) throw();};extern LA12Flag la12_cf1080;
struct LA12Data {bool check(int) throw();};extern LA12Data la12_d1e860;
struct LA12Datum {int a,type;};struct LA12DH {int id;LA12Datum *get()const throw();};extern LA12DH la12_d1e888;
extern int la12_cf462c,la12_cf645c,la12_cf6474,la12_cf6464;extern bool la12_cf4a00,la12_cf6458;extern float la12_cf46f8;extern LA12HI la12_cf6454;struct LA12Handles {unsigned a,b,c,d;};extern LA12Handles la12_cf46d4;
void la12_message(int,LA12H,const string&,int);bool la12_route(int,const string&,const string*,int,LA12H,LA12Prop,const LA12Point*,bool);void la12_clamp(int*,int) throw();bool la12_contains(LA12Handles&,LA12H) throw();int la12_sound(unsigned,int,int) throw();
struct LA12Log {void end() throw();};extern LA12Log *la12_cec0b4;struct LA12UI {void update(bool) throw();};extern LA12UI *la12_cec058;
LA12Target *LA12AI::chase(LA12H target,int amount,int extra,bool seen,bool *newTarget) {
 if(blocked(target))return 0;
 if(self.get()->getGroup().get()->type()==3) {
  if(target.get()->item(31).valid()) {
   if(target.get()->isPlayer()) {la12_d2c658.add(0x248,1,"",-1);if(la12_d2c658.count(0x248)==200)la12_cf45d8.achievement(213);}
   return 0;
  }
  if(la12_cf462c==11&&target.get()->isPlayer()&&la12_cf45d8.has(100))return 0;
 }
 int current=this->speed();int value;unsigned i;int temp;
 if(current<0)amount=current;
 for(i=0;i<targets.size();i++) {
  if(((LA12Target*)targets[i])->entity==target) {
   if(amount<0&&!seen)((LA12Target*)targets[i])->priority=amount;
   else if((((LA12Target*)targets[i])->priority>=0||(seen&&((LA12Target*)targets[i])->priority!=-2))&&((LA12Target*)targets[i])->priority<current/amount) {
    if(self.get()->faction()==13&&tracker&&self.get()->name()=="Tracker"&&((LA12Target*)targets[i])->priority==-1&&target.get()->isPlayer()) {
     tracker=0;
     if(la12_cefc4c->visible(self))la12_message(0x322,self,string("[name]: \"THREAT CONFIRMED. DEPLOY COMBAT PROGRAMMER.\""),0);
     la12_cf6428.respond(true,target,0);
    }
    ((LA12Target*)targets[i])->priority=current/amount;
   }
   ((LA12Target*)targets[i])->threat+=extra;
   if(target==la12_cefc4c->focus()&&self.get()->getGroup().get()->type()<=2)((LA12Target*)targets[i])->threat=10000;
   temp=((LA12Target*)targets[i])->entity.get()->effect(43);
   if(temp&&self.get()->getGroup().get()->type()!=12)la12_clamp(&((LA12Target*)targets[i])->threat,temp);
   if(seen&&self.get()->getGroup().get()->type()==3) {
    if(la12_cf4a00&&la12_cf645c==0&&la12_cf6474==0&&target.get()->isPlayer()&&la12_d1e860.check(1)&&la12_d1e888.get()->type!=13&&la12_d1e888.get()->type!=14&&la12_d1e888.get()->type!=34&&la12_d1e888.get()->type!=35) {
     do {
      la12_cf1080.set(true);if(false)la12_sound(-1,0,0);
      do {
       if(la12_route(0x324,string("ALERT: Sigix Warrior spotted in local area. Maximum security lockdown in progress."),0,0,LA12H(),LA12Prop(),0,false))la12_cec058->update(true);
       la12_cec0b4->end();
      }while(false);
      la12_cec0b4->end();
     }while(false);
     la12_cf6464=5;la12_cf6428.lockdown(true,true,true);
    }
    if(la12_cf6458&&(self.get()->effect(32)||!detected()))la12_cf6428.known(true);
    if(la12_cf6454.valid()&&(self.get()->effect(32)||!detected()))la12_cf6428.wake();
   }
   if(la12_cf46f8==100.0&&target.get()->isPlayer()&&self.get()->group.get()->type()==3&&level>=6)la12_cefc4c->alerted(true);
   return (LA12Target*)targets[i];
  }
 }
 if(la12_cf462c==7&&self==la12_cefc4c->special()&&!target.get()->ai()->relation(self)&&!target.get()->ai()->relation(la12_cefc4c->player())&&!la12_contains(la12_cf46d4,target))return 0;
 targets.push_back(static_cast<LA12Target*const&>(new LA12Target(target,amount>0?current/amount:amount,extra)));
 if(target==la12_cefc4c->focus()&&self.get()->getGroup().get()->type()<=2)((LA12Target*)targets.back())->threat=10000;
 value=((LA12Target*)targets.back())->entity.get()->effect(43);
 if(value&&self.get()->getGroup().get()->type()!=12)la12_clamp(&((LA12Target*)targets.back())->threat,value);
 if(newTarget)*newTarget=true;
 if(target==la12_cefc4c->player()&&level>=2) {engaged=1;if(self.get()->faction()==60)la12_cefc4c->alert(2);}
 if(la12_cf46f8==100.0&&target.get()->isPlayer()&&self.get()->group.get()->type()==3&&level>=6)la12_cefc4c->alerted(true);
 return (LA12Target*)targets.back();
}
