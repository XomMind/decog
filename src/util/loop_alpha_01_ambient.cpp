// NOTE: private placeholder aliases preserve proven retail nothrow inference.
#include <vector>
using namespace std;
struct LA1Point { int x,y; LA1Point() throw(); LA1Point(int,int) throw(); };
struct LA1Sound;
struct LA1Info { char pad[0x15c]; LA1Sound *ambientSound; };
class LA1Prop { public: LA1Info *getInfo9b8f00() throw(); int getFlags457b10() throw(); bool canSound45cad0() throw(); bool muted45caf0() throw(); };
struct LA1HProp { int id; bool valid9b7230() const throw(); LA1Prop *get9b64f0() const throw(); };
struct LA1Cell { LA1HProp getProp45d550() throw(); };
struct LA1Grid { LA1Cell *&at9ceda0(int,int) throw(); void getBounds9b7a40(const LA1Point&,int,LA1Point&,LA1Point&) throw(); };
extern LA1Grid la1_grid_cfd44c;
int la1_volume500500(LA1Sound *,const LA1Point&,const LA1Point&) throw();
void la1_load4fed60(LA1Sound *) throw();
struct LA1AmbientSource { LA1HProp prop; LA1Sound *sound; int volume; LA1AmbientSource(LA1HProp,int); };
LA1AmbientSource::LA1AmbientSource(LA1HProp prop_,int volume_) { prop=prop_; sound=prop.get9b64f0()->getInfo9b8f00()->ambientSound; volume=volume_; }
class LA1AmbientSystem { public: void collect4ff4c0(const LA1Point &,vector<LA1AmbientSource *> *); };
void LA1AmbientSystem::collect4ff4c0(const LA1Point &center,vector<LA1AmbientSource *> *sources) {
 LA1Point a; LA1Point b; int volume;
 la1_grid_cfd44c.getBounds9b7a40(center,25,a,b);
 for(int y=a.y;y<=b.y;y++) {
  for(int x=a.x;x<=b.x;x++) {
   if(la1_grid_cfd44c.at9ceda0(x,y)->getProp45d550().valid9b7230() && la1_grid_cfd44c.at9ceda0(x,y)->getProp45d550().get9b64f0()->getFlags457b10()==0 && la1_grid_cfd44c.at9ceda0(x,y)->getProp45d550().get9b64f0()->canSound45cad0() && !la1_grid_cfd44c.at9ceda0(x,y)->getProp45d550().get9b64f0()->muted45caf0()) {
    volume=la1_volume500500(la1_grid_cfd44c.at9ceda0(x,y)->getProp45d550().get9b64f0()->getInfo9b8f00()->ambientSound,LA1Point(x,y),center);
    if(volume!=0) {
     la1_load4fed60(la1_grid_cfd44c.at9ceda0(x,y)->getProp45d550().get9b64f0()->getInfo9b8f00()->ambientSound);
     sources->push_back(new LA1AmbientSource(la1_grid_cfd44c.at9ceda0(x,y)->getProp45d550(),volume));
    }
   }
  }
 }
}
