#include <string>
#include <vector>
#include <fstream>
using namespace std;
static_assert(sizeof(ifstream)==0xb0&&sizeof(string)==28&&sizeof(vector<string>)==16,"real VS2010 native owner layouts");
// NOTE: complete native other/keybinding owners and stream; actual external constructors and borrowed manager.
struct LB34Command{int id;string name;bool enabled;int key;bool shift,ctrl,alt,flag2b,flag2c,flag2d;LB34Command(int,string,bool,int,bool,bool,bool,bool,bool,bool);LB34Command(const LB34Command&);~LB34Command();string&name415ec0()throw();unsigned char enabled415f60()throw();void set415f80(int,bool,bool,bool)throw();};
LB34Command::~LB34Command(){}
struct LB34Binding{int category,id;string name;bool ctrl,shift,alt;int key;LB34Binding(int,LB34Command*);~LB34Binding();};
static_assert(sizeof(LB34Command)==48&&sizeof(LB34Binding)==44,"actual owned record layouts");
struct LB34Manager{vector<vector<LB34Command*> >*get9c0790()throw();};extern LB34Manager*lb34_cefa8c;
extern int lb34_cec458[];extern string gameString_cfd42c,gameStrings_cfcdc0[],gameStrings_cfe718[],gameStrings_d230f8[];
string lb34_int4051f0(int);void lb34_error404f10(string,string);void lb34_warn404e50(string,string);void lb34_fatal404fd0(string,string);void lb34_log404cb0(string);void lb34_parse408d70(string&,vector<string>&);int lb34_find9cda80(const string*,unsigned,string);int lb34_index9cf560(const int*,unsigned,int)throw();bool lb34_between9daf80(int,int,int)throw();string lb34_count407a80(int,const string&);
struct LB34Keys{vector<LB34Binding*>bindings;void init439650();void save43a840();};
void LB34Keys::init439650(){
 vector<vector<LB34Command*> >*first=lb34_cefa8c->get9c0790();
 for(unsigned i=0;i<first->size();i++)for(unsigned j=0;j<(*first)[i].size();j++)if((*first)[i][j]->enabled415f60())bindings.push_back(new LB34Binding(i,(*first)[i][j]));
 for(unsigned i=0;i<bindings.size();i++){int key=lb34_index9cf560(lb34_cec458,323,bindings[i]->key);if(key==-1)lb34_error404f10("Keybinds::init()","Unknown keyboard key ("+lb34_int4051f0(bindings[i]->key)+"), unable to map to internal keys");else if(lb34_between9daf80(65,bindings[i]->key,90)){bindings[i]->key=key+32;bindings[i]->shift=true;}else if(lb34_between9daf80(65,key,90)){bindings[i]->key=key+32;bindings[i]->shift=true;}else bindings[i]->key=key;}
 int count=0;ifstream f((gameString_cfd42c+"user/"+"commands.cfg").c_str());
 if(!f.is_open()){lb34_warn404e50("Keybinds::init()","Unable to open "+(gameString_cfd42c+"user/"+"commands.cfg")+", creating default commands");save43a840();}
 else{
  string s;vector<string>vec;int index=0;int mode=-1;int a;
  while(getline(f,s)){index++;vec.clear();lb34_parse408d70(s,vec);if(!vec.empty()){
   if(vec[0][0]=='['){unsigned end=vec[0].find(']');if(end==string::npos)lb34_fatal404fd0("Keybinds::init()","Domain header missing closing ']' in line "+lb34_int4051f0(index));mode=lb34_find9cda80(gameStrings_cfcdc0,37,string(vec[0].begin()+1,vec[0].begin()+end));}else{
   for(unsigned i=0;i<bindings.size();i++){
    a=lb34_find9cda80(gameStrings_cfe718,423,vec[0]);if(a==-1){lb34_error404f10("Keyboard::init()","No command type found matching \""+vec[0]+"\", ignoring command");goto nextLine;}
    if(bindings[i]->category==mode&&bindings[i]->id==a&&bindings[i]->name==vec[1]){bindings[i]->ctrl=vec[2]!="-";bindings[i]->shift=vec[3]!="-";bindings[i]->alt=vec[4]!="-";bindings[i]->key=lb34_find9cda80(gameStrings_d230f8,323,vec[5]);goto nextLine;}
   }
   a=lb34_find9cda80(gameStrings_cfe718,423,vec[0]);if(a==-1){lb34_error404f10("Keyboard::init()","No command type found matching \""+vec[0]+"\", ignoring command");goto nextLine;}
   (*first)[mode].push_back(new LB34Command(a,vec[1],true,lb34_find9cda80(gameStrings_d230f8,323,vec[5]),vec[3]!="-",vec[2]!="-",vec[4]!="-",true,false,true));bindings.push_back(new LB34Binding(mode,(*first)[mode].back()));count++;
nextLine:;
   }}
  }
  f.close();
 }
 int tmp=0;LB34Command*other=0;
 for(unsigned i=0;i<bindings.size();i++)for(unsigned j=0;j<(*first)[bindings[i]->category].size();j++)if(bindings[i]->name==(*first)[bindings[i]->category][j]->name415ec0()){
  other=new LB34Command(*(*first)[bindings[i]->category][j]);other->set415f80(bindings[i]->key,bindings[i]->shift,bindings[i]->ctrl,bindings[i]->alt);(*first)[bindings[i]->category][j]->set415f80(bindings[i]->key,bindings[i]->shift,bindings[i]->ctrl,bindings[i]->alt);tmp++;delete other;other=0;break;
 }
 lb34_log404cb0("...overwrote "+lb34_count407a80(tmp,"keybind"));lb34_log404cb0("...added "+lb34_count407a80(count,"alternative keybind"));
}
