// NOTE: private partial call-site layouts for hauler manifest817de0.
#include <string>
#include <vector>
using namespace std;
struct HaulerPoint{int x,y;HaulerPoint(int,int) throw();HaulerPoint(const HaulerPoint&) throw();};
struct HaulerEntity;struct HaulerItem;
struct HaulerH{int id;HaulerH() throw();HaulerEntity*operator->()const throw();bool equal(HaulerH)const throw();};
struct HaulerHI{int id;HaulerItem*operator->()const throw();};
struct HaulerItem{int type() throw();int matter() throw();int current() throw();string name();};
struct HaulerEntity{int size() throw();void inventory(vector<HaulerHI>&);};
struct HaulerEffect{void start();};
struct HaulerEngine{HaulerEffect*animate(HaulerEngine*,int,const HaulerPoint*,const HaulerPoint*,const HaulerPoint*,const HaulerPoint*,int);};
struct HaulerColor{unsigned char r,g,b;HaulerColor(const HaulerColor&) throw();};
struct HaulerConsole{char pad[0x64];HaulerEngine*engine;int tail;HaulerConsole(HaulerConsole*,int,int,int,int,int,bool,int);void reset();void print(int,int,const string&);void animate(string);void row(int,int,int,HaulerColor);int layer() throw();};
struct HaulerTimer{int type;char pad4[0x1c-4];HaulerH owner;char pad20[0x28-0x20];HaulerPoint point;int tail;HaulerTimer(int,HaulerConsole*,int,unsigned,const HaulerPoint&,HaulerH,HaulerH,HaulerH,const HaulerPoint&) throw();};
struct HaulerTimers{char layout[16];unsigned size()const;void*&operator[](unsigned);void push_back(void*const&);};
struct HaulerWorld{bool valid(HaulerH);};extern HaulerWorld*haulerWorld;
extern HaulerConsole*haulerView;extern HaulerColor*haulerColor;
extern unsigned haulerClock,haulerTimeout;extern bool haulerMode;extern const HaulerPoint haulerZero;
void haulerError(string,string);void haulerDelete(HaulerTimers&,int);void haulerErase(vector<HaulerHI>&,int);
int haulerMax(int,int);string haulerInt(int);bool haulerLookup(const string&,int*);
class DeltaHauler{public:char pad[0x6c];int x,y;char gap[0x1d8-0x74];HaulerTimers timers;void show(HaulerH,const HaulerPoint&);};
#define HAULER_EFFECT(X) name->engine->animate(name->engine,record,&HaulerPoint(X,0),&haulerZero,&HaulerPoint(X,count-1),&HaulerPoint(haulerZero),9)->start()
void DeltaHauler::show(HaulerH owner,const HaulerPoint&point){
 if(!owner.operator->()||!haulerWorld->valid(owner)){haulerError("CMap::showHaulerContent()","Invalid hauler");return;}
 for(unsigned j=0;j<timers.size();j++){if(((HaulerTimer*)timers[j])->type==16&&((HaulerTimer*)timers[j])->owner.equal(owner)){haulerDelete(timers,j);break;}}
 HaulerPoint a(point);
 HaulerPoint i(owner->size(),0);
 string b=" MANIFEST ";
 HaulerConsole*name=new HaulerConsole(haulerView,b.size(),1,a.x+i.x+x,a.y+i.y+y,haulerMode!=0,false,-1);
 timers.push_back(static_cast<HaulerTimer*const&>(new HaulerTimer(16,name,0,haulerClock+haulerTimeout,i,HaulerH(),HaulerH(),HaulerH(),a)));
 name->reset();name->print(0,0,b);name->animate("A_CMap_HaulerHeader");
 bool index=true;
 vector<string>type;vector<HaulerHI>key;
 owner->inventory(key);
 if(key.empty())type.push_back(" Empty");
 else{
  index=false;
  for(unsigned j=0;j<key.size();j++){
   int p=1;int count=0;
   for(unsigned n=j+1;n<key.size();n++){
    if(key[n]->type()==key[j]->type()){
     p++;if(key[n]->matter()==0)count+=key[n]->current();
     haulerErase(key,n);n--;
    }
   }
   type.push_back(" "+haulerInt(p)+"x "+key[j]->name());
   if(key[j]->matter()==0){count+=key[j]->current();type.back()+=" ("+haulerInt(count)+")";}
  }
 }
 int w=0;
 for(unsigned j=0;j<type.size();j++)w=haulerMax(w,type[j].size()+1);
 int count=type.size();
 name=new HaulerConsole(name,w,count,0,1,haulerMode!=0,false,name->layer());name->reset();
 for(unsigned j=0;j<type.size();j++){name->print(0,j,type[j]);name->row(0,j,type[j].size()+1,*haulerColor);}
 int record=0;
 if(type.size()>1){
  haulerLookup("Type_GR3_Vert_E",&record);HAULER_EFFECT(1);
  haulerLookup("Type_GR2_Vert_E",&record);HAULER_EFFECT(2);
  haulerLookup("Type_WH7_Vert_E",&record);for(int j=4;j<w;j++){HAULER_EFFECT(j);}
 }else if(index)name->animate("A_CMap_HaulerEmpty");
 else name->animate("A_CMap_HaulerSingle");
}
