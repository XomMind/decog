// Parts swap/attach operation. Private partial call-site layouts.
#include <vector>
#include <string>
using namespace std;
struct SwapItem;
struct SwapEntity;
struct SwapH {int id;SwapH() throw();};
struct SwapHI {int id;SwapItem *operator->()const throw();};
struct SwapHE {int id;SwapEntity *operator->()const throw();};
struct SwapItem {bool locked() throw();int category() throw();bool chargeable() throw();int capacity() throw();int current() throw();};
struct SwapEntity {int canEquip(SwapHI,bool,int,int) throw();void refresh() throw();};
struct SwapWorld {SwapHE player() throw();};
struct SwapRecord {char pad[0x6c];SwapHI item;int pad70,pad74,pad78;int category;};
struct SwapPhrase {char pad[0x20];SwapPhrase(int,string*,string*,string*,SwapH,SwapH);};
struct SwapMessages {void add(SwapPhrase*);};
struct SwapPair {char pad[0x10];SwapPair(SwapHI,SwapHI) throw();bool has(SwapHI) throw();};
// NOTE: private 16-byte x86 pair-pointer collection ABI; actual typed leaf helpers.
struct SwapPairSlots {char layout[16];unsigned size()const;void*&operator[](unsigned);void push_back(void*const&);};
extern SwapPairSlots swapPairs;
void swapDeleteStep(SwapPairSlots&,int&) throw();
struct SwapInventory {void equip(SwapHI,int,int,bool) throw();};
struct SwapTutorial {void show(int,bool,int,int,int) throw();};
extern SwapMessages *swapMessages;
extern SwapWorld *swapWorld;
extern SwapInventory *swapInventory;
extern SwapTutorial *swapTutorial;
extern int swapGameMode,swapEnergy,swapMatter,swapNameIndex;
extern string swapNames[];
string swapInt(int);
void swapMessage(int,const string*,int,int,SwapHE,SwapH,int);
class DeltaPartsSwap {
public:
 char pad00[0x74];vector<SwapRecord*> records;char pad84[0xac-0x84];int selected;SwapHI first,second;
 int selectedIndex(int) throw();int remove(SwapRecord*,SwapHI,int) throw();
 bool swap(SwapHI item,int slot);
};
#define SWAP_PHRASE(ID) swapMessages->add(new SwapPhrase(ID,0,0,0,SwapH(),SwapH()))
bool DeltaPartsSwap::swap(SwapHI item,int slot) {
 int p,type;
 if(selected==32) {SWAP_PHRASE(0x71);goto finished;}
 if(item->locked()) {SWAP_PHRASE(0x72);goto finished;}
 p=selectedIndex(selected);
 selected=32;
 if(item->category()==5) {SWAP_PHRASE(0x1f);goto finished;}
 if(swapGameMode==11) {SWAP_PHRASE(0xe7);goto finished;}
 if(item->category()!=records[p]->category) {SWAP_PHRASE(0x70);goto finished;}
 if(records[p]->item->locked()) {SWAP_PHRASE(0x72);goto finished;}
 type=swapWorld->player()->canEquip(item,true,0,0);
 switch(type) {
 case 0:
  first=records[p]->item;second=item;
  for(int i=0;i<swapPairs.size();i++) {
   if(static_cast<SwapPair*>(swapPairs[i])->has(first) || static_cast<SwapPair*>(swapPairs[i])->has(second))swapDeleteStep(swapPairs,i);
  }
  swapPairs.push_back(static_cast<SwapPair*const&>(new SwapPair(first,second)));
  if(remove(records[p],item,item->chargeable()?item->capacity()-item->current():0))break;
  swapInventory->equip(item,0,slot,true);
  swapWorld->player()->refresh();
  return true;
 case 15:SWAP_PHRASE(0x1f);break;
 case 16:SWAP_PHRASE(0xe7);break;
 case 1:
  swapMessage(0,&swapInt(swapEnergy),0,0,swapWorld->player(),SwapH(),0);
  swapTutorial->show(0x32,true,0,0,0);break;
 case 20:
  swapMessage(1,&swapInt(swapMatter),0,0,swapWorld->player(),SwapH(),0);
  swapTutorial->show(0x35,true,0,0,0);break;
 case 21:swapMessage(8,0,0,0,swapWorld->player(),SwapH(),0);break;
 case 22:swapMessage(9,0,0,0,swapWorld->player(),SwapH(),0);break;
 case 23:swapMessage(10,0,0,0,swapWorld->player(),SwapH(),0);break;
 case 24:swapMessage(11,&string(swapNames[swapNameIndex]),0,0,swapWorld->player(),SwapH(),0);break;
 }
finished:
 return false;
}
