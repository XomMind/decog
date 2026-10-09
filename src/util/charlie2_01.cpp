// Lore console input/export (0x7e93b0). From scratch/loop_delta_44/lore_mutable.cpp + literals.h (inlined).
// NOTE: placeholder names/layouts throughout (D44*).
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
extern const char d44_bfce74[];
extern const char d44_bfce84[];
extern const char d44_bfce8c[];
extern const char d44_bfce94[];
extern const char d44_bfce9c[];
extern const char d44_bfcea4[];
extern const char d44_bfcea8[];
extern const char d44_bfceac[];
extern const char d44_bfceb0[];
extern const char d44_bfcec8[];
extern const char d44_bfcecc[];
extern const char d44_bfced0[];
extern const char d44_bfcf14[];
extern const char d44_bfcf18[];
extern const char d44_bfcf5c[];
extern const char d44_bfcf60[];
extern const char d44_bfcf68[];
extern const char d44_bfcf70[];
extern const char d44_bfcf74[];
extern const char d44_bfcf78[];
extern const char d44_bfcf7c[];
extern const char d44_bfcf80[];
extern const char d44_bfcf84[];
extern const char d44_bfcf88[];
extern const char d44_bfcf8c[];
extern const char d44_bfcf90[];
extern const char d44_bfcf98[];
extern const char d44_bfcfa0[];
extern const char d44_bfcfbc[];
extern const char d44_bfcfd4[];
extern const char d44_bfcfe0[];
extern const char d44_bfd058[];
extern const char d44_bfd078[];
extern const char d44_bfd0dc[];
extern const char d44_bfd0e8[];
extern const char d44_bfd14c[];
extern const char d44_bfd154[];
extern const char d44_bfd168[];
extern const char d44_bfd1c8[];
extern const char d44_bfd230[];
extern const char d44_bfd23c[];
extern const char d44_bfd240[];
extern const char d44_bfd258[];
extern const char d44_bfd260[];
extern const char d44_bfd268[];
extern const char d44_bfd294[];
extern const char d44_bfd298[];
extern const char d44_bfd29c[];
extern const char d44_bfd2ac[];
extern const char d44_bfd2b4[];
extern const char d44_bfd2bc[];
extern const char d44_bfd2c0[];
extern const char d44_bfd2cc[];
extern const char d44_bfd2e8[];
extern const char d44_bfd330[];
extern const char d44_bfd338[];
extern const char d44_bfd340[];
extern const char d44_bfd360[];
extern const char d44_bfd3a8[];
extern const char d44_bfd3b0[];
extern const char d44_bfd3d4[];
extern const char d44_bfd3dc[];
extern const char d44_bfd3e4[];
extern const char d44_bfd404[];
extern const char d44_bfd40c[];
extern const char d44_bfd410[];
extern const char d44_bfd418[];
extern const char d44_bfd41c[];
extern const char d44_bfd424[];
extern const char d44_bfd43c[];
extern const char d44_bfd444[];
extern const char d44_bfd450[];
extern const char d44_bfd45c[];
extern const char d44_bfd480[];
extern const char d44_bfd484[];
extern const char d44_bfd488[];
extern const char d44_bfd48c[];
extern const char d44_bfd490[];
extern const char d44_bfd494[];
extern const char d44_bfd498[];
extern const char d44_bfd49c[];
extern const char d44_bfd4a0[];
extern const char d44_bfd4a4[];
extern const char d44_bfd4a8[];
extern const char d44_bfd4ac[];
extern const char d44_bfd4c4[];
extern const char d44_bfd4ec[];
// Private borrowed views. Names and omitted fields remain placeholders.
struct D44Source{int id;string name;int field20,type;};struct D44Dialogue{char p0[0x24];int type;};struct D44Record{char p0[0x24];int type;};
struct D44Entry{int id;bool known;D44Source*source;D44Dialogue*dialogue;int number;D44Record*record;string&category5169f0();string type516a60();string name516cf0();string&text517130();string label5171d0();string plural517230();};
struct D44Button{void set496e60();};struct D44Export{char p0[0x6c];vector<D44Button*>buttons;};
struct D44Lore{char p0[0x90];D44Export*exportConsole;bool select7eb9b0(int);void message497f20(string&);void input7e93b0(int,int);};
struct D44Player{string name4b98a0();};struct D44Meta{int percent46c830();};extern D44Player d44_d28c68;extern D44Meta d44_d25628;extern D44Lore*d44_cec044;extern vector<string>d44_d1d9b0;extern vector<D44Entry*>d44_d02cb4;extern string d44_cfd42c;extern int d44_bcabc4[];
bool d44_contains9d43b0(int*,unsigned,int);template<class T>void d44_insert9dbdc0(vector<T>&,int,T);
string d44_date436e70(bool,__int64);string d44_int4051f0(int);void d44_log404f10(string,string);void d44_replace407f00(string&,string,string);
void D44Lore::input7e93b0(int key,int modifier){
 switch(modifier){
 case 0:key-=32;while(key<=90){if(select7eb9b0(key))break;key++;}break;
 case 1:if(d44_contains9d43b0(d44_bcabc4,3,key)){
 vector<int>first;first.push_back(0);
 for(int i=1;i<d44_d1d9b0.size();i++){
 if(!lexicographical_compare(d44_d1d9b0[i].begin(),d44_d1d9b0[i].end(),d44_d1d9b0[first.back()].begin(),d44_d1d9b0[first.back()].end()))first.push_back(i);
 else{for(unsigned j=0;j<first.size();j++){if(lexicographical_compare(d44_d1d9b0[i].begin(),d44_d1d9b0[i].end(),d44_d1d9b0[first[j]].begin(),d44_d1d9b0[first[j]].end())){d44_insert9dbdc0(first,j,i);break;}}}
 }
 vector<D44Entry*>root;
 for(unsigned i=0;i<first.size();i++){
 int type=first[i];unsigned first=root.size();
 for(unsigned j=0;j<d44_d02cb4.size();j++){
 if(!d44_d02cb4[j]->source)break;
 if(d44_d02cb4[j]->source->type==type){
 if(first==root.size()||!lexicographical_compare(d44_d02cb4[j]->source->name.begin(),d44_d02cb4[j]->source->name.end(),((const vector<D44Entry*>&)root).back()->source->name.begin(),((const vector<D44Entry*>&)root).back()->source->name.end()))root.push_back(d44_d02cb4[j]);
 else{for(unsigned k=first;k<root.size();k++){if(lexicographical_compare(d44_d02cb4[j]->source->name.begin(),d44_d02cb4[j]->source->name.end(),root[k]->source->name.begin(),root[k]->source->name.end())){d44_insert9dbdc0(root,k,d44_d02cb4[j]);break;}}}
 }
 }
 }
 for(unsigned i=root.size();i<d44_d02cb4.size();i++)root.push_back(d44_d02cb4[i]);
 vector<int>row(d44_d1d9b0.size()+4,0);
 for(unsigned i=0;i<root.size();i++){if(root[i]->known)row[root[i]->dialogue?root[i]->dialogue->type:root[i]->source?root[i]->source->type:d44_d1d9b0.size()+root[i]->record->type]++;}
 string name=d44_cfd42c+d44_bfce84+d44_bfce74+d44_date436e70(true,0);
 switch(key){case 'T':name+=d44_bfce8c;break;case 'H':name+=d44_bfce94;break;case 'C':name+=d44_bfce9c;break;}
 ofstream output(name.c_str(),ios::out|ios::trunc);
 if(output.is_open()){
 string category;bool known;
 switch(key){
 case 'T':{
 output<<d44_d28c68.name4b98a0()<<d44_bfceb0<<d44_date436e70(true,0)<<d44_bfceac<<d44_int4051f0(d44_d25628.percent46c830())<<d44_bfcea8<<d44_bfcea4;
 output<<d44_bfcec8;
 for(unsigned i=0;i<root.size();i++){
 if(root[i]->category5169f0()!=category){
 category=root[i]->category5169f0();known=row[root[i]->dialogue?root[i]->dialogue->type:root[i]->source?root[i]->source->type:d44_d1d9b0.size()+root[i]->record->type];
 if(known){output<<d44_bfced0;output<<d44_bfcf14<<root[i]->type516a60()<<d44_bfcecc;output<<d44_bfcf18;output<<d44_bfcf5c;}
 }
 if(!root[i]->known){if(known){output<<d44_bfcf60;output<<d44_bfcf68;output<<d44_bfcf70;}continue;}
 const string&str=root[i]->name516cf0();
 output<<d44_bfcf7c<<str<<d44_bfcf78<<d44_bfcf74;
 for(unsigned j=0;j<str.size()+2;j++)output<<d44_bfcf80;
 output<<d44_bfcf84;output<<root[i]->text517130()<<d44_bfcf88;output<<d44_bfcf8c;
 }
 exportConsole->buttons[0]->set496e60();break;
 }
 case 'H':{
 output<<d44_bfcf90;
 output<<d44_bfcf98;
 output<<d44_bfcfa0;
 output<<d44_bfcfe0;
 output<<d44_bfcfbc;
 output<<d44_bfd058;
 output<<d44_bfd078;
 output<<d44_bfd0e8;
 output<<d44_bfd168;
 output<<d44_bfd1c8;
 output<<d44_bfcfd4;
 output<<d44_bfd0dc;
 output<<d44_bfd14c;
 output<<d44_bfd154;
 output<<d44_d28c68.name4b98a0()<<d44_bfd240<<d44_date436e70(true,0)<<d44_bfd23c<<d44_int4051f0(d44_d25628.percent46c830())<<d44_bfd230;output<<d44_bfd258;
 for(unsigned i=0;i<root.size();i++){
 if(root[i]->category5169f0()!=category){category=root[i]->category5169f0();known=row[root[i]->dialogue?root[i]->dialogue->type:root[i]->source?root[i]->source->type:d44_d1d9b0.size()+root[i]->record->type];if(known)output<<d44_bfd29c<<category<<d44_bfd298<<root[i]->plural517230()<<d44_bfd294<<category<<d44_bfd268<<root[i]->plural517230()<<d44_bfd260;}
 }
 category.clear();output<<d44_bfd2ac;
 for(unsigned i=0;i<root.size();i++){
 if(root[i]->category5169f0()!=category){category=root[i]->category5169f0();known=row[root[i]->dialogue?root[i]->dialogue->type:root[i]->source?root[i]->source->type:d44_d1d9b0.size()+root[i]->record->type];
 if(known){output<<d44_bfd2c0<<category<<d44_bfd2bc<<root[i]->plural517230()<<d44_bfd2b4;output<<d44_bfd2cc;output<<d44_bfd2e8;string title=root[i]->type516a60();output<<d44_bfd330<<title;for(int j=title.size();j<59;j++)output<<d44_bfd338;output<<d44_bfd340;output<<d44_bfd360;output<<d44_bfd3a8;}
 }
 if(!root[i]->known){if(known){output<<d44_bfd3b0;output<<d44_bfd3d4;}continue;}
 output<<d44_bfd3e4<<root[i]->name516cf0()<<d44_bfd3dc;
 string text=root[i]->text517130();d44_replace407f00(text,d44_bfd40c,d44_bfd404);d44_replace407f00(text,d44_bfd418,d44_bfd410);
 output<<d44_bfd424<<text<<d44_bfd41c;output<<d44_bfd43c;
 }
 output<<d44_bfd444;output<<d44_bfd450;exportConsole->buttons[1]->set496e60();break;
 }
 case 'C':{
 output<<d44_bfd45c;
 for(unsigned i=0;i<root.size();i++){
 if(root[i]->known){output<<d44_bfd488<<root[i]->label5171d0()<<d44_bfd484<<d44_bfd480;output<<d44_bfd494<<root[i]->category5169f0()<<d44_bfd490<<d44_bfd48c;output<<d44_bfd4a0<<root[i]->name516cf0()<<d44_bfd49c<<d44_bfd498;
 string text=root[i]->text517130();for(unsigned j=0;j<text.size();j++){if(text[j]=='"'){text.insert(text.begin()+j,'"');j++;}}output<<d44_bfd4a8<<text<<d44_bfd4a4;
 }
 }
 exportConsole->buttons[2]->set496e60();break;
 }
 }
 d44_cec044->message497f20(d44_bfd4ac+name);
 }else d44_log404f10(d44_bfd4ec,d44_bfd4c4+name);
 }break;
 }
}
