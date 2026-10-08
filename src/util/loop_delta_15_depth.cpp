// NOTE: private partial call-site views for world-map depth rendering996500.
#include <string>
#include <vector>
using namespace std;
struct DepthPoint{int x,y;};struct DepthInfo{int unk0,kind,depth;};
struct DepthH{int id;DepthInfo*operator->()const throw();};
struct DepthConsole{char bytes[0x6c];DepthConsole(DepthConsole*,int,int,int,int,int,bool,int);DepthPoint position();int width();void put(int,int,int);void print(int,int,const string&);void animate(string);DepthH target();};
struct DepthOverlay{char bytes[0x8c];DepthOverlay(DepthConsole*,int,int);};
extern int depthGroups[];
int depthMin(int,int);int depthMax(int,int);string depthInt(int);
class DeltaWorldDepth:public DepthConsole{public:char pad6c[4];vector<DepthH> zones;vector<DepthConsole*> rows;char pad90[8];vector<DepthConsole*> branches;DepthOverlay*overlay;void render(int,int,int);};
void DeltaWorldDepth::render(int zone,int left,int right){
 int count,index,a;
 if(zone==-1){a=rows.back()->position().y;index=left;count=right;}
 else{
  a=rows.back()->position().y+1;index=width();count=0;
  for(unsigned i=0;i<branches.size();i++){
   index=depthMin(index,branches[i]->position().x);
   count=depthMax(count,branches[i]->position().x+branches[i]->width());
  }
  index--;count++;
 }
 bool type=zone!=-1&&zones[zone]->depth==10;
 DepthConsole*record=new DepthConsole(this,index,1,0,a,2,false,-1);
 record->put(0,0,129);
 for(int i=1;i<record->width();i++)record->put(i,0,i%2?129:46);
 record->animate("A_CWorldMap_Depth_Line");
 if(!type){
  record=new DepthConsole(this,width()-count,1,count,a,2,false,-1);
  record->put(record->width()-1,0,129);
  for(int x=record->width()-2,i=1;x>=0;x--,i++)record->put(x,0,i%2?129:46);
  record->animate("A_CWorldMap_Depth_Line");
 }else{
  int x=rows.front()->position().x+5;
  if(zones.size()>=3&&depthGroups[zones[2]->kind]==2){
   if(zones.size()>=4&&zones[2]->kind==15&&zones[3]->kind==11)x+=10;
   else x+=5;
  }else if(zones.size()>=4&&zones[2]->kind==7&&zones[3]->kind==15){
   if(zones.size()>=5&&zones[4]->kind==11)x+=15;
   else x+=10;
  }
  overlay=new DepthOverlay(this,x,rows.front()->position().y-1);
 }
 const int key=5;
 const int i=4;
 int p=width()-key-i;
 string name="[-"+(type?string("10"):"0"+(zone==-1?depthInt(rows.back()->target()->depth):depthInt(zones[zone]->depth)))+"]";
 if(index>=key*2+i){
  record=new DepthConsole(this,key,1,i,a,2,false,-1);record->print(0,0,name);record->animate(type?"A_CWorldMap_Depth_10":"A_CWorldMap_Depth");
 }
 if(!type&&count<=width()-(key*2+i)){
  record=new DepthConsole(this,key,1,p,a,2,false,-1);record->print(0,0,name);record->animate("A_CWorldMap_Depth");
 }
}
