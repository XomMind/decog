// Partial layouts; declarations reflect renderer call sites only.
#include <vector>
#include <string>
using namespace std;
struct DeltaPos {int x,y; DeltaPos(int,int) throw(); DeltaPos(const DeltaPos&) throw();};
struct DeltaRect {int x,y,x2,y2; DeltaRect() throw();};
struct DeltaColor {unsigned char r,g,b; DeltaColor(const DeltaColor&) throw();};
struct DeltaEntity;
struct DeltaItem;
struct DeltaAI {int size() throw();};
struct DeltaEntityHandle {unsigned value; DeltaEntityHandle() throw(); bool isValid()const throw(); DeltaEntity *operator->()const throw();};
struct DeltaItemHandle {unsigned value; bool isValid()const throw(); DeltaItem *operator->()const throw();};
struct DeltaEntity {bool hostile(DeltaEntityHandle) throw(); DeltaAI *ai() throw(); DeltaPos &position() throw(); int range() throw();};
struct DeltaItem {int category() throw();};
struct DeltaCell {DeltaEntityHandle entity() throw(); DeltaItemHandle item() throw();};
struct DeltaGrid {DeltaCell **atPoint(DeltaPos&) throw(); DeltaCell **at(int,int) throw(); void rect(DeltaPos&,int,DeltaRect&) throw();};
struct DeltaWorld {int turn() throw(); int threats() throw(); vector<DeltaPos>* points() throw(); DeltaEntityHandle player() throw(); bool known(int,int) throw(); bool visible(int,int) throw(); vector<vector<unsigned> > *pings() throw(); int torrent() throw();};
extern DeltaWorld *deltaWorld;
extern DeltaGrid deltaGrid;
extern DeltaColor *deltaBackground,*deltaForeground;
bool deltaContains(vector<DeltaEntityHandle>&,DeltaEntityHandle) throw();
int deltaMax(int,int) throw();
int deltaDistance(const DeltaPos&,const DeltaPos&) throw();
string deltaInt(int);
class DeltaExoskeleton {
public:
 char pad[0x6c]; int cached,threatCount,componentCount;
 void clear() throw(); void setBgColor(DeltaColor) throw(); void setFore(DeltaColor) throw(); void setBack(DeltaColor) throw(); void print(int,int,const string&) throw();
 void render();
};
void DeltaExoskeleton::render() {
 clear(); setBgColor(*deltaBackground); setFore(*deltaForeground); setBack(*deltaBackground);
 bool type=false;
 if(cached!=deltaWorld->turn()) {type=true;cached=deltaWorld->turn();}
 if(type) {
  threatCount=deltaWorld->threats();
  vector<DeltaPos> *count=deltaWorld->points();
  vector<DeltaEntityHandle> p;
  DeltaEntityHandle a;
  for(unsigned i=0;i<count->size();i++) {
   a=(*deltaGrid.atPoint((*count)[i]))->entity();
   if(a.isValid() && a->hostile(deltaWorld->player()) && a->ai() && a->ai()->size()>=2 && !deltaContains(p,a)) {threatCount++;p.push_back(a);}
  }
 }
 string text="THREATS " + (threatCount ? deltaInt(threatCount) : string("-"));
 print(1,0,text);
 if(type) {
  componentCount=0;
  DeltaPos p=deltaWorld->player()->position();
  DeltaRect count;
  deltaGrid.rect(p,deltaMax(deltaWorld->player()->range(),18),count);
  for(int x=count.x;x<count.x2;x++)
   for(int y=count.y;y<count.y2;y++)
    if((*deltaGrid.at(x,y))->item().isValid() && (*deltaGrid.at(x,y))->item()->category()>=6 && deltaWorld->known(x,y) && (deltaWorld->visible(x,y) || deltaDistance(p,DeltaPos(x,y))<=18)) componentCount++;
 }
 text="COMPONENTS " + (componentCount ? deltaInt(componentCount) : string("-"));
 print(13,0,text);
 int a=(*deltaWorld->pings())[18].size();
 text="PING_NUM " + (a ? deltaInt(a) : string("-"));
 print(29,0,text);
 int i=deltaWorld->torrent();
 text="TOR_DIST " + (i ? deltaInt(i) : string("?"));
 print(42,0,text);
}
