// NOTE: private placeholder names and partial call-site layouts, verified retail offsets.
#include <string>
using namespace std;
struct RemoveItem; struct RemoveEntity;
struct RemoveProp{int id;RemoveProp() throw();};
struct RemoveHI{int id;RemoveItem* operator->()const throw();bool isValid()const throw();bool isNull()const throw();};
struct RemoveHE{int id;RemoveEntity* operator->()const throw();};
struct RemoveDefinition{char pad[0x1ac];bool special;};
struct RemoveItem{RemoveDefinition* definition()const throw();int effect(int) throw();int kind() throw();int capacity() throw();string name(bool,bool);};
struct RemoveEntity{int canRemove(RemoveHI,int,bool,bool) throw();int remove(RemoveHI,RemoveHI,bool,int) throw();int destroy(RemoveHI,bool,bool,bool,int) throw();int energy() throw();void drain(int) throw();};
struct RemoveWorld{RemoveHE player() throw();bool blocked() throw();void event(int,int) throw();};
struct RemoveConsole{void scroll(bool) throw();};struct RemoveLog{void end() throw();};struct RemoveTutorial{void show(int,bool,int,int,int) throw();};
struct RemoveRecord{char pad[0x6c];RemoveHI item;char pad70[8];bool flag;int field() throw();};
extern RemoveWorld* removeWorld;extern RemoveConsole* removeConsole;extern RemoveLog* removeLog;extern RemoveTutorial* removeTutorial;
extern int removeEnergy;extern string removeNames[];
string removeInt(int);
void removeWarning(int,const string*,int,int,RemoveHE,RemoveProp,int);
bool removeRoute(int,const string*,int,int,RemoveHE,RemoveProp,int,int);
class DeltaPartsRemove{public:char pad[0x140];string name140;char gap[0x1a0-0x140-28];string name1a0;int slots(RemoveRecord*) throw();int slots2(RemoveRecord*) throw();int remove(RemoveRecord*,RemoveHI,int);};
#define WARNING(ID,STR) removeWarning(ID,STR,0,0,count,RemoveProp(),0)
#define ROUTE(ID,STR) do{if(removeRoute(ID,STR,0,0,count,RemoveProp(),0,0))removeConsole->scroll(true);removeLog->end();}while(false)
int DeltaPartsRemove::remove(RemoveRecord* item,RemoveHI replacement,int value){
 RemoveHE count=removeWorld->player();
 int p=count->canRemove(item->item,replacement.isValid()&&replacement->kind()==7?replacement->capacity():0,replacement.isValid()||item->item->definition()->special||item->item->effect(0x6e)?true:false,false);
 int a;
 switch(p){
 case 0:
  if(item->item->definition()->special||item->item->effect(0x6e))ROUTE(16,&item->item->name(false,false));
  else WARNING(35,&item->item->name(false,false));
  a=count->remove(item->item,replacement,item->flag,value);
  if(replacement.isNull())removeWorld->event(6,a);break;
 case 7:
  WARNING(14,0);
  ROUTE(item->item->definition()->special||item->item->effect(0x6e)?16:15,&item->item->name(false,false));
  if(!removeWorld->blocked())count->drain(count->energy());
  removeWorld->event(8,count->destroy(item->item,true,true,item->flag,0));break;
 case 9:WARNING(21,&item->item->name(false,false));break;
 case 10:WARNING(22,&name1a0);break;
 case 26:WARNING(15,0);break;
 case 27:WARNING(16,&name140);break;
 case 28:WARNING(18,&string(slots(item)>1?"slots":"slot"));break;
 case 29:WARNING(19,&(string(removeNames[item->field()])+(slots2(item)>1?" slots":" slot")));break;
 case 30:WARNING(17,&item->item->name(false,false));break;
 case 11:WARNING(23,&item->item->name(false,false));break;
 case 12:WARNING(25,&item->item->name(false,false));break;
 case 13:WARNING(26,&item->item->name(false,false));break;
 case 14:WARNING(27,&item->item->name(false,false));break;
 case 34:WARNING(30,&item->item->name(false,false));break;
 case 1:WARNING(0,&removeInt(removeEnergy));removeTutorial->show(0x32,true,0,0,0);break;
 }
 return p;
}
