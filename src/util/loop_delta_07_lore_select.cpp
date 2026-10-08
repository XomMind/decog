// Lore selection renderer. Partial layouts and call-site helper names.
#include <string>
#include <vector>
using namespace std;
struct SelectPos {int x,y; SelectPos(int,int) throw();};
struct SelectColor {unsigned char r,g,b; SelectColor(const SelectColor&) throw();};
struct SelectAnimation {void start();};
struct SelectEngine {
 void stopAll() throw();
 SelectAnimation *animation(SelectEngine*,int,SelectPos*,SelectPos*,SelectPos*,SelectPos*,int);
};
struct SelectConsole {
 char pad[0x64]; SelectEngine *engine; int tail;
 SelectConsole(SelectConsole*,int,int,int,int,int,bool,int);
 void clearInterior() throw(); void clear() throw();
 int printWrapped(int,int,int,int,const string&) throw();
 void print(int,int,const string&);
 SelectPos getPos() throw(); SelectPos maxCoord() throw(); int height() throw();
 void setFore(SelectColor) throw(); string getString(const SelectPos&,unsigned);
 void removeSubconsole(SelectConsole*) throw();
};
struct SelectRecord {int index; bool known; const string& text() throw();};
struct SelectPage : SelectConsole {SelectRecord *record;};
extern vector<SelectRecord*> selectRecords;
extern SelectColor *selectMainColor,*selectOtherColor;
extern SelectPos selectEffectOrigin;
bool selectLookup(const string&,int*);
class DeltaLoreSelect {
public:
 char pad[0x70]; vector<SelectPage*> pages; unsigned current; SelectConsole *display;
 void select(int);
};
#define SELECT_EFFECT(anim,at,extent) do { \
 for(int col=SelectPos(2,at).x;col<SelectPos(2,at).x+(extent);col++) \
  display->engine->animation(display->engine,anim,&SelectPos(col,SelectPos(2,at).y),&selectEffectOrigin,0,0,9)->start(); \
} while(false)
void DeltaLoreSelect::select(int value) {
 if(current==value) return;
 current=value;
 SelectPage *record=0;
 for(unsigned i=0;i<pages.size();i++) {
  if(pages[i]->record->index==current) {record=pages[i];break;}
 }
 display->clearInterior(); display->engine->stopAll();
 SelectConsole *p=new SelectConsole(display,94,25,2,1,0,false,-1);
 int height=p->printWrapped(0,0,94,25,record->record->text());
 int row=record->getPos().y;
 if(row+height>=display->maxCoord().y) row-=row+height-display->height()+1;
 display->setFore(*selectMainColor);
 for(int i=0,x=row;i<height;i++,x++) {
  string text=p->getString(SelectPos(0,i),94);
  display->print(2,x,text);
 }
 int index,type;
 selectLookup("CLore_Text_Discovered",&index);
 selectLookup("CLore_Text_Unknown",&type);
 display->setFore(*selectOtherColor);
 int count=1;
 int x=row+height+1;
 int i=record->record->index+1;
 while(i<selectRecords.size() && x<display->maxCoord().y) {
  if(!selectRecords[i]->known) {
   height=1;
   display->print(2,x,"???");
   SELECT_EFFECT(type,x,3);
  } else {
   p->clear();
   height=p->printWrapped(0,0,94,25,selectRecords[i]->text());
   for(int i=0,y=x;i<height && y<display->maxCoord().y;i++,y++) {
    string text=p->getString(SelectPos(0,i),94);
    display->print(2,y,text);
    SELECT_EFFECT(index,y,text.size());
   }
  }
  i++;x=x+height+1;
 }
 x=row;i=record->record->index-1;
 while(i>=0) {
  if(!selectRecords[i]->known) {
   height=1;x-=height+1;
   if(x>1) {
    display->print(2,x,"???");
    SELECT_EFFECT(type,x,3);
   } else break;
  } else {
   p->clear();height=p->printWrapped(0,0,94,25,selectRecords[i]->text());
   x-=2;
   for(int i=height-1;i>=0;i--,x--) {
    if(x<1) goto finished;
    string text=p->getString(SelectPos(0,i),94);
    display->print(2,x,text);
    SELECT_EFFECT(index,x,text.size());
   }
   x++;
  }
  i--;
 }
finished:
 display->removeSubconsole(p);
}
