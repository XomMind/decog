// Lore-list scrolling and selection. NOTE: partial layouts and placeholder names.
#include <vector>
#include <cstdlib>
using namespace std;
struct LoopLorePos {
 int x,y;
 LoopLorePos(int,int) throw();
 LoopLorePos(const LoopLorePos&) throw();
 LoopLorePos(const LoopLorePos&,int,int) throw();
};
struct LoopLoreRecord { int index; bool known; void *data; };
class LoopLorePage {
public:
 virtual ~LoopLorePage();
 char pad04[0x6c-4];
 LoopLoreRecord *record; // +0x6c
 LoopLorePos getPos() throw();
 void setPos(const LoopLorePos&) throw();
 int width_44b0d0() throw();
 LoopLorePos localToAbs(LoopLorePos) throw();
};
struct LoopLoreMouse { void setCellPoint_41a910(const LoopLorePos&) throw(); };
extern LoopLoreMouse *loopLoreMouse_cefa94;
extern vector<LoopLoreRecord*> loopLoreRecords_d02cb4;
extern unsigned loopLoreNpos_caf16c;
extern int loopLoreRows_bcbe04[2];
extern bool loopLoreMouseMode_d28c8a;
bool loopLoreWide_cebd5c() throw();
int loopLoreMax_9cdb60(int,int) throw();
int loopLoreMin_9cdb30(int,int) throw();
void loopLoreEraseRange_9e25a0(vector<LoopLorePage*>&,int,int) throw();
void loopLoreEraseAt_9de6f0(vector<LoopLorePage*>&,int) throw();
class LoopLorePanel {
public:
 char pad00[0x70];
 vector<LoopLorePage*> pages; // +0x70
 unsigned current; // +0x80
 void removeSubconsole(LoopLorePage*) throw();
 void fill_7ebba0(int,int,int,bool) throw();
 void select_7ebd60(int) throw();
 void scroll_7eafe0(int value,int flag);
};
void LoopLorePanel::scroll_7eafe0(int value,int flag) {
 if (value == 0) return;
 bool p = false;
 int index = loopLoreNpos_caf16c;
 bool from;
 int start;
 if (abs(value) == 1) {
  if (current == loopLoreNpos_caf16c) {
   for (unsigned i=0;i<loopLoreRecords_d02cb4.size();i++) {
    if (loopLoreRecords_d02cb4[i]->known) {index=i;break;}
   }
  } else if (value == 1) {
   for (unsigned i=current+1;i<loopLoreRecords_d02cb4.size();i++) {
    if (loopLoreRecords_d02cb4[i]->known) {index=i;break;}
   }
  } else {
   for (int i=current-1;i>=0;i--) {
    if (loopLoreRecords_d02cb4[i]->known) {index=i;break;}
   }
  }
  if (index != loopLoreNpos_caf16c) {
   for (unsigned i=0;i<pages.size();i++) {
    if (pages[i]->record->index == index) {goto selection;}
   }
   if (index != pages.front()->record->index-1 && index != pages.back()->record->index+1) {
    p=true;
    from = value != 1;
   }
  }
 }
 start = pages.front()->record->index;
 if (value < 0) {
  value = -value;
  if (start == 0) return;
  if (value >= loopLoreRows_bcbe04[loopLoreWide_cebd5c()?1:0] || start-value < 0) {
   for (unsigned i=0;i<pages.size();i++) if (pages[i]) removeSubconsole(pages[i]);
   pages.clear();
   start = loopLoreMax_9cdb60(0,start-value);
   fill_7ebba0(loopLoreRows_bcbe04[loopLoreWide_cebd5c()?1:0],start,2,true);
  } else {
   int amount;
   int end = loopLoreRows_bcbe04[loopLoreWide_cebd5c()?1:0]-value;
   for (unsigned i=end;i<pages.size();i++) removeSubconsole(pages[i]);
   loopLoreEraseRange_9e25a0(pages,end,pages.size()-1);
   amount=value;
   for (unsigned i=0;i<pages.size();i++) pages[i]->setPos(LoopLorePos(pages[i]->getPos(),0,amount));
   start -= value;
   fill_7ebba0(value,start,2,true);
  }
 } else {
  if (pages.back()->record->index == loopLoreRecords_d02cb4.size()-1) return;
  if (value >= loopLoreRows_bcbe04[loopLoreWide_cebd5c()?1:0] || start+value >= (int)loopLoreRecords_d02cb4.size()-loopLoreRows_bcbe04[loopLoreWide_cebd5c()?1:0]) {
   for (unsigned i=0;i<pages.size();i++) if (pages[i]) removeSubconsole(pages[i]);
   pages.clear();
   start = loopLoreMin_9cdb30(loopLoreRecords_d02cb4.size()-loopLoreRows_bcbe04[loopLoreWide_cebd5c()?1:0],start+value);
   fill_7ebba0(loopLoreRows_bcbe04[loopLoreWide_cebd5c()?1:0],start,2,false);
  } else {
   int amount;
   for (int i=0;i<value;i++) {removeSubconsole(pages.front());loopLoreEraseAt_9de6f0(pages,0);}
   amount=value;
   for (unsigned i=0;i<pages.size();i++) pages[i]->setPos(LoopLorePos(pages[i]->getPos(),0,-amount));
   start = pages.size()+value+start;
   fill_7ebba0(value,start,pages.back()->getPos().y+1,false);
  }
 }
 if (p) {
  if (from) {
   for (unsigned i=0;i<pages.size();i++) if (pages[i]->record->known) {index=pages[i]->record->index;break;}
  } else {
   for (int i=pages.size()-1;i>=0;i--) if (pages[i]->record->known) {index=pages[i]->record->index;break;}
  }
 }
selection:
 if (index != loopLoreNpos_caf16c) {
  for (unsigned i=0;i<pages.size();i++) if (pages[i]->record->index == index) {
   loopLoreMouse_cefa94->setCellPoint_41a910(pages[i]->localToAbs(LoopLorePos(pages[i]->width_44b0d0()-2,0)));
   select_7ebd60(index);
   break;
  }
 } else if (loopLoreMouseMode_d28c8a) {
  if (flag == 0x29 || flag == 0x2c) {
   for (int i=pages.size()-1;i>=0;i--) if (pages[i]->record->known) {
    loopLoreMouse_cefa94->setCellPoint_41a910(pages[i]->localToAbs(LoopLorePos(pages[i]->width_44b0d0()-2,0)));
    select_7ebd60(pages[i]->record->index);
    break;
   }
  } else if (flag == 0x2a || flag == 0x2b) {
   for (unsigned i=0;i<pages.size();i++) if (pages[i]->record->known) {
    loopLoreMouse_cefa94->setCellPoint_41a910(pages[i]->localToAbs(LoopLorePos(pages[i]->width_44b0d0()-2,0)));
    select_7ebd60(pages[i]->record->index);
    break;
   }
  }
 }
}
