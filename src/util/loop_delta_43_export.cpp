#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;
// Private borrowed views; names and undisclosed storage are placeholders.
struct D43Range{int low,high;string text40c2b0(string);};
struct D43Choice{int index,width,chance;};
struct D43Def{
 int id;string name;char p20[0x68-0x20];int tier,threat,value;char p74[8];int memory,spot;char p84[0x94-0x84];int size,profile,extent;char pa0[0xc];int hackKind,hackDifficulty,accuracy,meleeAccuracy;char pbc[0xe4-0xbc];int suffix;char pe8[0x160-0xe8];vector<vector<D43Choice*> > equipment;string description;char p18c[0x20];string display;int inventory,slots[4],sight;int p1e0,storage,generation,dissipation,matter;char p1f4[0x1c];D43Range salvage;
 string class459a40();string suffix459e00();
};
struct D43ItemDef{char p0[0x24];string name;char p40[8];int kind;};
struct D43Entity{
 D43Def*record9b4350()throw();int faction45a2c0()throw();int inventory45ab90()throw();int sight5c7d30();int energy5ca960();int resistance5cb570(int,bool);int heat5cca00();int rating5cccc0();unsigned immune5cd490(vector<int>*);bool analyzed5cd5d0();string analysis5cd670();int energy5d1070();int move5d1390();int speed5d15a0(bool);int speedPercent5d1d70();int accuracy5d2090(int);int bonus5d2150(int,int);int slots448fe0(int);void remove637bb0();
};
struct D43HE{int id;D43HE()throw();D43Entity*get9b6570()const throw();};
struct D43Factory{D43HE create793200(D43Def*);};
extern D43Factory*d43_cefaa8;extern vector<D43Def*>d43_d25de0;extern vector<D43ItemDef*>d43_d2d1c4;extern string d43_cfd42c,d43_d39e90[],d43_d388f8[],d43_d2e148[],d43_d3a210[],d43_d32d18[],d43_d2a5a8[];extern bool d43_cefb34;
string d43_date436e70(bool,__int64);string d43_int4051f0(int);void d43_log404f10(string,string);void d43_int79a050(ostream&,int);void d43_text79a0a0(ostream&,const string&);
extern const char d43_b95bca[],d43_b95bcb[],d43_b95bd3[],d43_b95bee[],d43_b95bef[];
void d43_export79a180(){
 string description=d43_cfd42c+"user/"+"robots_export_"+d43_date436e70(true,0);description+=".csv";
 ofstream output(description.c_str(),ios::out|ios::trunc);
 if(!output.is_open()){d43_log404f10("exportEntityData()","could not open file for export: "+description);return;}
 D43HE first;
 output<<"Name,Class,Tier,Threat,Rating,Value"<<",Size Class,Size,Profile"<<",Memory,Spot %"<<",Movement,Speed,Speed %"<<",Sight Range,Energy Generation,Heat Dissipation"<<",Innate Energy Storage,Innate Energy Generation,Innate Heat Dissipation,Innate Matter Storage"<<",Core Integrity,Core Exposure,Core Exposure %,Salvage Potential"<<",Accuracy,Melee Accuracy"<<",Inventory Capacity"<<",Hacking Availability,Hacking Difficulty"<<",Power Slots,Propulsion Slots,Utility Slots,Weapon Slots"<<",Kinetic,Thermal,Explosive,Electromagnetic,Impact,Slashing,Piercing"<<",Immunities,Traits"<<",Fabrication Count,Fabrication Time"<<",Armament,Components"<<",Analysis"<<"\n";
 D43Def*data;
 for(unsigned current=1;current<d43_d25de0.size();current++){
 data=d43_d25de0[current];
 if(d43_d25de0[current]->name=="Sigix Containment Pod"||d43_d25de0[current]->name=="Sigix Exoskeleton")continue;
 first=d43_cefaa8->create793200(data);
 d43_text79a0a0(output,data->display);d43_text79a0a0(output,data->class459a40());d43_int79a050(output,data->tier);d43_int79a050(output,data->threat);d43_int79a050(output,first.get9b6570()->rating5cccc0());d43_int79a050(output,data->value);
 d43_text79a0a0(output,d43_d39e90[data->profile]);d43_int79a050(output,data->extent);d43_text79a0a0(output,d43_d388f8[data->size]);d43_int79a050(output,data->memory);d43_int79a050(output,data->spot);
 int size=first.get9b6570()->move5d1390();
 d43_text79a0a0(output,size==6&&first.get9b6570()->faction45a2c0()!=0&&first.get9b6570()->faction45a2c0()!=73?string("N/A"):d43_d2e148[size]);
 d43_int79a050(output,first.get9b6570()->speed5d15a0(false));d43_int79a050(output,first.get9b6570()->speedPercent5d1d70());d43_int79a050(output,first.get9b6570()->sight5c7d30());d43_int79a050(output,first.get9b6570()->energy5d1070());d43_int79a050(output,first.get9b6570()->energy5ca960());
 d43_int79a050(output,first.get9b6570()->record9b4350()->storage);d43_int79a050(output,first.get9b6570()->record9b4350()->generation);d43_int79a050(output,first.get9b6570()->record9b4350()->matter);d43_int79a050(output,first.get9b6570()->record9b4350()->dissipation);
 d43_int79a050(output,data->sight);d43_int79a050(output,first.get9b6570()->inventory45ab90());d43_int79a050(output,first.get9b6570()->heat5cca00());d43_text79a0a0(output,data->salvage.text40c2b0("~"));
 d43_int79a050(output,first.get9b6570()->accuracy5d2090(85)+data->accuracy);d43_int79a050(output,data->meleeAccuracy+first.get9b6570()->accuracy5d2090(90)-first.get9b6570()->bonus5d2150(106,0)/5);
 d43_int79a050(output,data->inventory);d43_text79a0a0(output,d43_d3a210[data->hackKind]);d43_text79a0a0(output,data->hackKind==0?d43_d32d18[data->hackDifficulty]:string(d43_b95bca));
 d43_int79a050(output,first.get9b6570()->slots448fe0(0));d43_int79a050(output,first.get9b6570()->slots448fe0(1));d43_int79a050(output,first.get9b6570()->slots448fe0(2));d43_int79a050(output,first.get9b6570()->slots448fe0(3));
 for(int col=0;col<7;col++){
 int value=100-first.get9b6570()->resistance5cb570(col,false);
 string name=value?(value>=0?d43_int4051f0(value):"-"+d43_int4051f0(-value))+"%":string(d43_b95bcb);d43_text79a0a0(output,name);
 }
 vector<int> slots;
 if(first.get9b6570()->immune5cd490(&slots)){
 string text;for(unsigned col=0;col<slots.size();col++){if(col)text+=", ";text+=d43_d2a5a8[slots[col]];}d43_text79a0a0(output,text);
 }else d43_text79a0a0(output,d43_b95bd3);
 string record;
 d43_text79a0a0(output,first.get9b6570()->analyzed5cd5d0()?first.get9b6570()->analysis5cd670():string(d43_b95bee));
 d43_int79a050(output,data->suffix);d43_text79a0a0(output,data->suffix?data->suffix459e00():string(d43_b95bef));
 string label;int width=0;vector<vector<D43Choice*> >*choices=&data->equipment;
 for(unsigned col=0;col<choices->size();col++){
 if(d43_d2d1c4[(*choices)[col][0]->index]->kind==3){
 if(width)label+=", ";for(unsigned k=0;k<(*choices)[col].size();k++){
 if(k)label+=" OR ";if((*choices)[col][k]->width>1)label+=d43_int4051f0((*choices)[col][k]->width)+"x ";label+=d43_d2d1c4[(*choices)[col][k]->index]->name;if((*choices)[col][k]->chance!=100)label+=" ("+d43_int4051f0((*choices)[col][k]->chance)+"%)";
 }width++;
 }}
 d43_text79a0a0(output,label);label.clear();width=0;
 for(unsigned col=0;col<choices->size();col++){
 if(d43_d2d1c4[(*choices)[col][0]->index]->kind!=3){
 if(width)label+=", ";for(unsigned k=0;k<(*choices)[col].size();k++){
 if(k)label+=" OR ";if((*choices)[col][k]->width>1)label+=d43_int4051f0((*choices)[col][k]->width)+"x ";label+=d43_d2d1c4[(*choices)[col][k]->index]->name;if((*choices)[col][k]->chance!=100)label+=" ("+d43_int4051f0((*choices)[col][k]->chance)+"%)";
 }width++;
 }}
 d43_text79a0a0(output,label);d43_text79a0a0(output,data->description);output<<"\n";first.get9b6570()->remove637bb0();
 }
 output.close();d43_cefb34=false;
}
