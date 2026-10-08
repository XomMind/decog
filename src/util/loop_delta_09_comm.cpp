// Comm-array squad overlay. Private partial call-site layouts.
#include <vector>
#include <string>
using namespace std;
struct CommPos {int x,y;CommPos(int,int) throw();CommPos(const CommPos&) throw();bool same(const CommPos&)const throw();};
struct CommHandle {int id;CommHandle() throw();};
struct CommColor {unsigned char r,g,b;CommColor(const CommColor&) throw();};
struct CommAnimation {void start();};
struct CommEngine {CommAnimation *animation(CommEngine*,int,CommPos*,CommPos*,CommPos*,CommPos*,int);};
struct CommConsole {
 char pad[0x64];CommEngine *engine;int end;
 CommConsole(CommConsole*,int,int,int,int,int,bool,int);
 void resetBack();void print(int,int,const string&);void animate(string);
 int layer();void setBackRow(int,int,int,CommColor);
};
struct CommTimer {int type;char pad04[0x28-4];CommPos point;int tail;CommTimer(int,CommConsole*,int,unsigned,const CommPos&,CommHandle,CommHandle,CommHandle,const CommPos&) throw();};
struct CommWorld {vector<CommPos>*locations();vector<int>*categories();vector<vector<int> > *squads();};
struct CommTemplate {char pad[0x2c];string name;};
extern CommWorld *commWorld;
extern CommConsole *commView;
extern CommColor *commRowColor;
extern string commCategoryNames[];
extern vector<CommTemplate*> commTemplates;
extern CommPos commEffectOrigin;
extern unsigned commClock,commTimeout;
extern bool commMode;
int commIndex(vector<CommPos>&,CommPos) throw();
// NOTE: private 16-byte x86 timer-pointer collection ABI; actual typed leaf helpers.
struct CommTimerSlots {char layout[16];unsigned size()const;void*&operator[](unsigned);void push_back(void*const&);};
void commDelete(CommTimerSlots&,int);
void commErase(vector<int>&,int);
void commError(string,string);
string commUpper(const string&);
string commInt(int);
int commMax(int,int);
bool commLookup(const string&,int*);
class DeltaCommMap {
public:
 char pad00[0x6c];int x,y;char pad74[0x1d8-0x74];CommTimerSlots timers;
 void show(const CommPos&);
};
void DeltaCommMap::show(const CommPos &point) {
 int record=commIndex(*commWorld->locations(),point);
 if(record==-1) {commError("CMap::showCommArraySquad()","Invalid loc");return;}
 for(unsigned i=0;i<timers.size();i++) {
  if(static_cast<CommTimer*>(timers[i])->type==17 && static_cast<CommTimer*>(timers[i])->point.same(point)) {commDelete(timers,i);break;}
 }
 CommPos a(1,0);
 string name=" "+commUpper(commCategoryNames[(*commWorld->categories())[record]])+" SQUAD ";
 CommConsole *key=new CommConsole(commView,name.size(),1,point.x+a.x+x,point.y+a.y+y,commMode != 0,false,-1);
 timers.push_back(static_cast<CommTimer*const&>(new CommTimer(17,key,0,commClock+commTimeout,a,CommHandle(),CommHandle(),CommHandle(),point)));
 key->resetBack();key->print(0,0,name);key->animate("A_CMap_HaulerHeader");
 vector<int> type=(*commWorld->squads())[record];
 vector<string> i;
 for(unsigned j=0;j<type.size();j++) {
  int p=1;
  for(unsigned n=j+1;n<type.size();n++) {
   if(type[n]==type[j]) {p++;commErase(type,n);n--;}
  }
  i.push_back(" "+commInt(p)+"x "+commTemplates[type[j]]->name);
 }
 int w=0;
 for(unsigned j=0;j<i.size();j++)w=commMax(w,i[j].size()+1);
 int text=i.size();
 key=new CommConsole(key,w,text,0,1,commMode != 0,false,key->layer());
 key->resetBack();
 for(unsigned j=0;j<i.size();j++) {key->print(0,j,i[j]);key->setBackRow(0,j,i[j].size()+1,*commRowColor);}
 int index=0;
 if(i.size()>1) {
  commLookup("Type_GR3_Vert_E",&index);
  key->engine->animation(key->engine,index,&CommPos(1,0),&commEffectOrigin,&CommPos(1,text-1),&CommPos(commEffectOrigin),9)->start();
  commLookup("Type_GR2_Vert_E",&index);
  key->engine->animation(key->engine,index,&CommPos(2,0),&commEffectOrigin,&CommPos(2,text-1),&CommPos(commEffectOrigin),9)->start();
  commLookup("Type_WH7_Vert_E",&index);
  for(int j=4;j<w;j++)key->engine->animation(key->engine,index,&CommPos(j,0),&commEffectOrigin,&CommPos(j,text-1),&CommPos(commEffectOrigin),9)->start();
 } else key->animate("A_CMap_HaulerSingle");
}
