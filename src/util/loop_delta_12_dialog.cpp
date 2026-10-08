// NOTE: private partial layouts and placeholder call-site names.
#include <string>
#include <vector>
using namespace std;
struct DialogPoint {int x,y;DialogPoint() throw();DialogPoint(int,int) throw();DialogPoint(const DialogPoint&,int,int) throw();void assign(const DialogPoint&) throw();};
struct DialogRect{int x,y,w,h;DialogRect() throw();DialogRect(const DialogRect&) throw();};
struct DialogColor {unsigned char r,g,b;};
struct DialogAnimation{void start();};
struct DialogEngine{DialogAnimation*animate(DialogEngine*,int,DialogPoint*,DialogColor*,DialogPoint*,DialogColor*,int);};
struct DialogConsole {
 char pad[0x64];DialogEngine*engine;int tail;
 DialogConsole(DialogConsole*,int,int,int,int,int,bool,int);
 DialogConsole(DialogConsole*,DialogRect,int,bool,int);
 DialogPoint position();void position(const DialogPoint&);int height();int width();
 void printWrapped(int,int,int,int,int,const string&);void animate(string);
 bool onMap(const DialogPoint&);DialogPoint*offset();
};
struct DialogEntity{const DialogPoint&position();int relation(struct DialogHandle);};
struct DialogHandle{int id;DialogEntity*operator->()const throw();bool valid()const throw();};
struct DialogWorld{DialogHandle player();};
struct DialogRecord {DialogConsole*console;unsigned expires;DialogHandle entity;int relation;bool alternate;char padding[3];DialogConsole*bar;unsigned barExpires;
 DialogRecord(DialogConsole*,unsigned,DialogHandle,int,bool,DialogConsole*,unsigned);~DialogRecord();};
extern DialogWorld*dialogWorld;extern DialogConsole*dialogMap,*dialogView;
extern int dialogCellW,dialogCellH,dialogFooter;extern unsigned dialogClock;
extern string dialogRelations[];extern DialogColor dialogColor;
bool dialogLookup(const string&,int*);
class DeltaDialog {public:char pad[0x6c];vector<DialogRecord*> records;void show(DialogHandle,const string&);};
void DeltaDialog::show(DialogHandle entity,const string& message){
 int range=dialogMap->width()*dialogCellW;
 const int type=2;
 int width=range-dialogCellW*type;
 int w=message.size()/width+(message.size()%width!=0);
 for(unsigned key=0;key<records.size();key++)records[key]->console->position(DialogPoint(records[key]->console->position(),0,-w));
 const int index=10;
 while(records.size()>index){delete records.front();records.erase(records.begin());}
 DialogRect a;
 DialogPoint name;
 if(entity.operator->())name.assign(entity->position());
 if(entity.operator->()&&dialogMap->onMap(name)){
  a.x=(name.x+dialogMap->offset()->x)*dialogCellW;
  a.y=(name.y+dialogMap->offset()->y+1)*dialogCellH;
  a.w=dialogCellW;
  a.h=dialogMap->height()*dialogCellH-dialogFooter-w-a.y;
  if(a.h<=0)a.x=-1;
 }else a.x=-1;
 int b=entity.valid()?(entity.operator->()?dialogWorld->player()->relation(entity):1):3;
 bool record=false;
 if(!records.empty()&&records.back()->relation==b&&!records.back()->alternate)record=true;
 records.push_back(new DialogRecord(new DialogConsole(dialogView,range,w,0,dialogMap->height()*dialogCellH-dialogFooter-w,0,false,-1),dialogClock+8000,entity,b,record,a.x!=-1?new DialogConsole(dialogView,a,0,false,-1):0,dialogClock+400));
 records.back()->console->printWrapped(range/2,0,width,w,1,message);
 string text="A_CMap_MapDialog_"+(b==3?string("S"):string(dialogRelations[b]));
 string line="CMap_MapDialog_E_"+(b==3?string("S"):string(dialogRelations[b]));
 if(record){text+="_Alt";line+="_Alt";}
 records.back()->console->animate(text);
 int key;dialogLookup(line,&key);
 DialogEngine*p=records.back()->console->engine;
 for(int j=0;j<w;j++){
  p->animate(p,key,&DialogPoint(range/2,j),&dialogColor,&DialogPoint(0,j),&dialogColor,9)->start();
  p->animate(p,key,&DialogPoint(range/2+1,j),&dialogColor,&DialogPoint(range,j),&dialogColor,9)->start();
 }
 if(records.back()->bar){
  text="A_CMap_MapDialog_Bar_"+(b==3?string("S"):string(dialogRelations[b]));
  if(record)text+="_Alt";
  records.back()->bar->animate(text);
 }
}
