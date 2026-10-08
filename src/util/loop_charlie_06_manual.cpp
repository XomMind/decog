// NOTE: private aliases and observed layouts for CShellManual constructor0x4b0070.
#include <string>
#include <vector>
#include <algorithm>
using std::string;using std::vector;
class LC6Console {public:
 virtual ~LC6Console();virtual void resize(int,int);virtual bool mouse();virtual void refresh();virtual bool input(void*);virtual void ascii(int,int);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frame();virtual void trigger(const string&,int);
 LC6Console(LC6Console*,int,int,int,int,int,bool,int);char p04[0x68];
};
class LC6Text:public LC6Console {public:LC6Text(LC6Console*,int,int,int,int,bool,bool,int,int,int,int,const char*,int);void max_4544c0(int);void paren_48d380();char p6c[0xe4-0x6c];};
struct LC6Record {char p00[0x24];string name;};
struct LC6Records {LC6Record*&at_9b81f0(unsigned);unsigned size_9b9260()const;};extern LC6Records lc6_records_d2d1c4;
extern string gameStrings_d2d508[];
extern vector<unsigned> lc6_names_d3860c;extern vector<int> lc6_record_names_cfd1cc;
string lc6_upper_4083a0(const string&);
void lc6_insert_9dbdc0(vector<unsigned>&,int,int);void lc6_insert_9dbdc0(vector<int>&,int,int);
extern const int lc6_types_b9b418[],lc6_categories_b9b5d8[];
struct LC6Flag {bool value;char pad[5];};extern const LC6Flag lc6_flags_b9b17b[];
struct LC6GlobalRec {int unk0,type;};struct LC6GlobalH {LC6GlobalRec*get_9b7910();};extern LC6GlobalH lc6_global_d1e888;
bool teamb_isAvailable9004e0(int,const string*);
extern vector<string> lc6_available_d257c0;
bool lc6_contains_9d3fe0(vector<string>&,string);
struct LC6CategoryData {char p00[0x40];vector<int> ids;};
struct LC6Category {LC6CategoryData*get_45cb30();};struct LC6CategoryH {int id;LC6Category*get_9b64f0();};
struct LC6Shell {LC6CategoryH category_4aeb30();};extern LC6Shell *lc6_shell_cec0fc;
bool lc6_has_9db330(vector<int>*,int);
void lc6_accept_900920();void opq4c_scrollShell8fec50();void OpW7_unknown4b1c30();bool opq4c_suggest909990(bool);
struct LC6Keys {void push_416570();void clear_416340(bool);void focus_44cea0(LC6Console*);};extern LC6Keys*lc6_keys_cefa8c;
class LC6Manual:public LC6Console {public:
 LC6Text*text;vector<int> names;string current;vector<int> records;int unknownac;vector<int> other;int unknownc0,unknownc4;
 LC6Manual(LC6Console*,int);virtual void render();
};
LC6Manual::LC6Manual(LC6Console*parent,int y):LC6Console(parent,46,1,2,y,0,false,-1),unknownc4(0) {
 if(lc6_names_d3860c.empty()) {
  lc6_names_d3860c.push_back(0);
  for(int i=1;i<112;i++) {
   if(!std::lexicographical_compare(gameStrings_d2d508[i].begin(),gameStrings_d2d508[i].end(),gameStrings_d2d508[lc6_names_d3860c.back()].begin(),gameStrings_d2d508[lc6_names_d3860c.back()].end()))lc6_names_d3860c.push_back(int(i));
   else for(unsigned j=0;j<lc6_names_d3860c.size();j++) {
    if(std::lexicographical_compare(gameStrings_d2d508[i].begin(),gameStrings_d2d508[i].end(),gameStrings_d2d508[lc6_names_d3860c[j]].begin(),gameStrings_d2d508[lc6_names_d3860c[j]].end())) {lc6_insert_9dbdc0(lc6_names_d3860c,j,i);break;}
   }
  }
 }
 if(lc6_record_names_cfd1cc.empty()) {
  vector<string> items;
  for(unsigned i=0;i<lc6_records_d2d1c4.size_9b9260();i++)items.push_back(lc6_upper_4083a0(lc6_records_d2d1c4.at_9b81f0(i)->name));
  lc6_record_names_cfd1cc.push_back(0);
  for(int i=1;i<lc6_records_d2d1c4.size_9b9260();i++) {
   if(!std::lexicographical_compare(static_cast<const string&>(items[i]).begin(),static_cast<const string&>(items[i]).end(),static_cast<const string&>(items[lc6_record_names_cfd1cc.back()]).begin(),static_cast<const string&>(items[lc6_record_names_cfd1cc.back()]).end()))lc6_record_names_cfd1cc.push_back(i);
   else for(unsigned j=0;j<lc6_record_names_cfd1cc.size();j++) {
    if(std::lexicographical_compare(static_cast<const string&>(items[i]).begin(),static_cast<const string&>(items[i]).end(),static_cast<const string&>(items[lc6_record_names_cfd1cc[j]]).begin(),static_cast<const string&>(items[lc6_record_names_cfd1cc[j]]).end())) {lc6_insert_9dbdc0(lc6_record_names_cfd1cc,j,i);break;}
   }
  }
 }
 for(int i=0;i<112;i++) {
  int id=lc6_names_d3860c[i];
  if((lc6_types_b9b418[id]==38 || lc6_types_b9b418[id]==lc6_global_d1e888.get_9b7910()->type) && teamb_isAvailable9004e0(id,0)) {
   if(!lc6_flags_b9b17b[id].value || lc6_contains_9d3fe0(lc6_available_d257c0,gameStrings_d2d508[id])) {
    if(lc6_categories_b9b5d8[id]!=25 && lc6_has_9db330(&lc6_shell_cec0fc->category_4aeb30().get_9b64f0()->get_45cb30()->ids,lc6_categories_b9b5d8[id]))continue;
    names.push_back(i);
   }
  }
 }
 text=new LC6Text(this,0,0,44,0,false,false,(int)lc6_accept_900920,(int)opq4c_scrollShell8fec50,(int)OpW7_unknown4b1c30,0,0,(int)opq4c_suggest909990);
 text->max_4544c0(44);text->paren_48d380();lc6_keys_cefa8c->push_416570();lc6_keys_cefa8c->clear_416340(true);lc6_keys_cefa8c->focus_44cea0(text);
}
