// Partial call-site layouts for drag/drop input; placeholder helper names.
#include <string>
using namespace std;
struct DropPos {int x,y;};
struct DropEvent {int code;};
struct DropItem;
struct DropEntity;
struct DropHandle {int id; DropItem *operator->()const throw(); bool isValid()const throw();};
struct DropEntityHandle {int id; DropEntity *operator->()const throw();};
struct DropProp {int id; DropProp() throw();};
struct DropItem {int type() throw(); int category() throw(); string name(bool,bool);};
struct DropEntity {int capacity() throw(); int bonus() throw(); int energy() throw();};
struct DropRecord {char pad[0x6c]; DropHandle item; int unused70; DropHandle aux; int unused78; int category; int index;};
struct DropPanel {
 bool hidden() throw(); bool contains(const DropPos&) throw();
 DropRecord *find(DropHandle) throw(); DropRecord *selected() throw();
 void choose(DropRecord*) throw(); void swap(DropRecord*) throw();
 void remove(DropRecord*,DropProp,bool) throw(); void drop(DropRecord*) throw();
 void swapItem(DropHandle,int) throw(); void indicator(DropHandle) throw();
 DropRecord *inventoryFind(DropHandle,bool) throw();
 void equip(DropHandle,int,int,int) throw(); void destroy(DropHandle,bool) throw();
};
struct DropMouse {DropPos position() throw();};
struct DropWorld {DropEntityHandle player() throw();};
struct DropPhrase {char pad[0x20]; DropPhrase(int,string*,string*,string*,DropProp,DropProp);};
struct DropMessages {void add(DropPhrase*) throw();};
struct DropTutorial {void show(int,bool,int,int,int) throw();};
extern DropMouse *dropMouse;
extern DropWorld *dropWorld;
extern DropPanel *dropInventory,*dropHolder,*dropParts,*dropGround,*dropMap;
extern DropMessages *dropMessages;
extern DropTutorial *dropTutorial;
extern bool dropDisabled,dropRequireSelection;
extern int dropAmount;
void dropSound(int,int,int) throw();
void dropWarning(string,string);
string dropInt(int);
void dropMessage(int,const string*,int,int,DropEntityHandle,DropProp,int);
class DeltaDragDrop {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void close();
 char pad04[0x6c-4]; DropHandle item; bool inventoryMode;
 bool hidden() throw(); bool parentInput(DropEvent*) throw();
 bool input(DropEvent*);
};
bool DeltaDragDrop::input(DropEvent *event) {
 if(hidden() || dropDisabled) return false;
 if(parentInput(event)) return true;
 switch(event->code) {
 case 0x154: {
  int p=dropInventory->contains(dropMouse->position()) || (!dropHolder->hidden() && dropHolder->contains(dropMouse->position())) ? 1 : (dropParts->contains(dropMouse->position()) ? 0 : (dropGround->contains(dropMouse->position()) ? 2 : 3));
  if(!item.operator->()) p=3;
  if(p!=3) {
   int count;
   switch(item->type()) {case 5:break;case 4:count=1;break;default:count=0;break;}
   switch(count) {
   case 0:
    switch(p) {
    case 0: {
     DropRecord *p=dropParts->find(item);
     if(!p) {dropWarning("CDragDrop::input()","CParts does not contain item to re-assign: " + item->name(false,false));break;}
     DropRecord *count=dropParts->selected();
     if(p==count) {dropSound(0x2a,0,0);break;}
     if(count) {dropParts->choose(p);dropParts->swap(count);} else dropSound(0x2a,0,0);
     break;
    }
    case 1: {
     DropRecord *p=dropParts->find(item);
     if(!p) {dropWarning("CDragDrop::input()","CParts does not contain item to remove/swap: " + item->name(false,false));break;}
     dropParts->remove(dropParts->find(item),DropProp(),false);
     if(inventoryMode && item.operator->()) dropMap->indicator(item);
     break;
    }
    case 2:
     if(!dropParts->find(item)) {dropWarning("CDragDrop::input()","CParts does not contain item to drop: " + item->name(false,false));break;}
     dropParts->drop(dropParts->find(item));break;
    }
    break;
   case 1:
    switch(p) {
    case 0: {
     DropRecord *p=dropInventory->inventoryFind(item,false);
     DropRecord *count=dropParts->selected();
     if(count && count->aux.isValid() && count->item.isValid()) {
      dropMessages->add(new DropPhrase(0x78,0,0,0,DropProp(),DropProp()));
     } else if(count && count->item.isValid() && count->item->category()==p->item->category()) {
      int w=dropWorld->player()->capacity();
      int a=dropWorld->player()->bonus();
      int text=w+a;
      if(dropWorld->player()->energy()<text) {
       dropAmount=text;
       dropMessage(0,&dropInt(dropAmount),0,0,dropWorld->player(),DropProp(),0);
       dropTutorial->show(0x32,true,0,0,0);
      } else {dropParts->choose(count);dropParts->swapItem(p->item,count->index);}
     } else {
      if(!dropRequireSelection || count) {
       if(dropRequireSelection && count && count->category != p->item->category()) break;
       dropInventory->equip(item,0,0x20,0);
      }
     }
     break;
    }
    case 1:dropSound(0x2a,0,0);break;
    case 2:dropInventory->destroy(item,true);break;
    }
    break;
   }
  } else dropSound(0x2a,0,0);
  close();return true;
 }
 case 0x155: dropSound(0x2a,0,0);close();return true;
 }
 return false;
}
