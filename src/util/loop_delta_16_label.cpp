// NOTE: private partial call-site types for item label formatter7ff100.
#include <string>
#include <vector>
using namespace std;
struct LabelDefinition{char pad[0x44];int matter;int pad48;int slots;int amount;char pad54[0x94-0x54];int category;string name(int,int);};
struct LabelMemory{char pad[0x10];int type,amount;char pad18[8];int style;};
struct LabelItem{int type();int matter();int amount();int percent();int current();LabelDefinition*definition();string name(bool,bool);};
struct LabelH{int id;bool valid()const throw();LabelItem*operator->()const throw();};
extern vector<LabelDefinition*>labelDefinitions;
extern vector<int>labelUnseen,labelKnown;
extern string labelMatterNames[];
extern bool labelSuppress,labelShowDamage,labelPercent,labelSlots;
string labelUpper(const string&);string labelInt(int);
#define LABEL_TYPE (item.valid()?item->type():memory->type)
int deltaItemLabel(LabelH item,LabelMemory*memory,string&out,bool full){
 out=labelUpper(item.valid()?item->name(true,false):labelDefinitions[memory->type]->name(memory->amount,memory->style));
 if(labelUnseen[LABEL_TYPE]==0&&labelKnown[LABEL_TYPE]!=0)out+="!";
 if((item.valid()?item->matter():labelDefinitions[memory->type]->matter)>=6&&labelKnown[LABEL_TYPE]!=0){
  if(full){
   if(item.valid()){
    if(!labelSuppress)out+=" ["+labelMatterNames[item->definition()->category]+labelInt(item->amount())+"]";
    if(labelShowDamage&&item->percent()<100){
     if(labelSuppress)out+=" <";
     if(labelPercent)out+=" "+labelInt(item->percent())+"%";
     else out+=" "+labelInt(item->current());
    }
   }else if(!labelSuppress)out+=" ["+labelMatterNames[labelDefinitions[memory->type]->category]+labelInt(labelDefinitions[memory->type]->amount)+"]";
  }else{
   if(item.valid()){
    if(!labelSuppress)out.insert(0,"["+labelMatterNames[item->definition()->category]+labelInt(item->amount())+"] ");
    if(labelShowDamage&&item->percent()<100){
     if(labelSuppress)out.insert(0,"> ");
     if(labelPercent)out.insert(0,labelInt(item->percent())+"% ");
     else out.insert(0,labelInt(item->current())+" ");
    }
   }else if(!labelSuppress)out.insert(0,"["+labelMatterNames[labelDefinitions[memory->type]->category]+labelInt(labelDefinitions[memory->type]->amount)+"] ");
  }
 }else if(labelSlots&&labelKnown[LABEL_TYPE]==0&&labelDefinitions[LABEL_TYPE]->slots>1)out+=" x"+labelInt(labelDefinitions[LABEL_TYPE]->slots);
 return out.size();
}
