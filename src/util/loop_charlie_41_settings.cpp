// NOTE: cave generator settings loader4c8740; private real native config owners.
// True172B record: native strings14/30/50 and unsigned-index vector70; actual four Range8 fields88..a0.
// PhysFScpp stream declaration follows bundled native hierarchy; placeholder members bind real pure file4/empty close leaves.
// Complex files/parsers/owner mutation keep ordinary exception contracts. Unknown scalar names are provisional.
#include <string>
#include <vector>
#include <cstdio>
#include <istream>
#include "../thirdparty/zfstream.h"
using namespace std;
struct PHYSFS_File;
namespace PhysFScpp {class base_fstream {protected: PHYSFS_File*const file;public:base_fstream(PHYSFS_File*);virtual~base_fstream();bool isOpen_404af0()throw();};class ifstream:public base_fstream,public std::istream {public:ifstream(const string&,ios_base::openmode=ios_base::in);virtual~ifstream();void close9c05e0()throw();};}
struct LC41Range{int low,high;LC41Range();void set40a010(int,int)throw();bool parse40bf80(const string&);};
struct LC41Rect{int x,y,w,h;LC41Rect()throw();};
struct LC41Record{bool enabled;int level,chance,type,index;string name,suffix;bool flag4c;string other;int value;vector<unsigned>directions;int category;bool flag84;LC41Range range88,range90,range98,rangeA0;int extra;LC41Record();~LC41Record();void suffix4485a0();};
struct LC41Bridge{bool enabled;int level,unknown08,chance;LC41Range x,y;int dir;LC41Range width,length;LC41Bridge();};
struct LC41Settings{int f0,f4,f8;LC41Range size;int f14,f18,f1c;float f20;int f24,f28,f2c;LC41Range segment;int f38,f3c;float f40;int f44;vector<LC41Rect>regions;int f58,f5c,f60,f64,f68,f6c;vector<LC41Record>records;vector<LC41Bridge>bridges;LC41Range range90;int f98,f9c,fa0;void load4c9b40(istream&);bool read(const string&,bool);};
static_assert(sizeof(LC41Record)==0xac&&sizeof(LC41Bridge)==0x34&&sizeof(LC41Rect)==16,"actual native record extent");
static_assert(sizeof(gzifstream)==184,"gzip size184");
static_assert(sizeof(PhysFScpp::ifstream)==96,"physfs size96");
static_assert(sizeof(LC41Settings)==164,"settings size164");
struct LC41Resource{bool exists415590(string);};extern LC41Resource*lc41_cefa88;
struct LC41Log{void end410e50(int);};extern LC41Log*lc41_cefa64;
bool lc41_line4074b0(PhysFScpp::ifstream*,string&,int);int lc41_value432ac0(int);void lc41_parse4bd1d0(string&,vector<string>&);int lc41_int4bd2c0(const string&);int lc41_float4bd300(const string&);int lc41_int405610(const string&);void lc41_erase4077e0(string&);int lc41_find9cda80(const string*,unsigned,string);
extern string lc41_cf7240[],lc41_cf63b8[],lc41_d1e4b8[],lc41_d2e840[];extern int lc41_bb87b0[];extern const char lc41_bced00[],lc41_bced04[],lc41_bced08[],lc41_bced0c[];
bool LC41Settings::read(const string&filename,bool binary){
 FILE*file=0;
 if(!lc41_cefa88->exists415590(filename)){return false;}
 else if(binary){
  if(file)fclose(file);gzifstream input(filename.c_str(),ios::binary);load4c9b40(input);input.close();
 }else{
  char flags='^';bool changed=false;int counter=0;string line;vector<string>parts;int next=0;int type;
  if(file)fclose(file);PhysFScpp::ifstream input(filename.c_str());
  if(!input.isOpen_404af0()){lc41_cefa64->end410e50(2);return false;}
  while(lc41_line4074b0(&input,line,lc41_value432ac0(counter))){
   counter++;parts.clear();lc41_parse4bd1d0(line,parts);
   if(!parts.empty()){
    type=lc41_find9cda80(lc41_cf7240,28,parts[0]);
    if(type==-1)return false;
    if(next<24&&type!=next)return false;
    if(lc41_bb87b0[type]==0&&parts.size()<=2)return false;
    if(lc41_bb87b0[type]>0&&parts.size()-1!=lc41_bb87b0[type])return false;
    if(changed&&parts[0][0]=='^')continue;else changed=false;
    switch(type){
    case 0:f0=lc41_int4bd2c0(parts[1]);break;
    case 1:f4=lc41_int4bd2c0(parts[1]);break;
    case 2:f8=lc41_int4bd2c0(parts[1]);break;
    case 3:size.set40a010(lc41_int4bd2c0(parts[1]),lc41_int4bd2c0(parts[2]));break;
    case 4:f14=lc41_int4bd2c0(parts[1]);break;
    case 5:f18=lc41_int4bd2c0(parts[1]);break;
    case 6:f1c=lc41_int4bd2c0(parts[1]);break;
    case 7:f20=lc41_float4bd300(parts[1]);break;
    case 8:f24=lc41_int4bd2c0(parts[1]);break;
    case 9:f28=lc41_int4bd2c0(parts[1]);if(f28>=100)return false;break;
    case 10:f2c=lc41_int4bd2c0(parts[1]);break;
    case 11:segment.set40a010(lc41_int4bd2c0(parts[1]),lc41_int4bd2c0(parts[2]));if(segment.low<2)return false;break;
    case 12:f38=lc41_int4bd2c0(parts[1]);break;
    case 13:f3c=lc41_int4bd2c0(parts[1]);break;
    case 14:f40=lc41_float4bd300(parts[1]);break;
    case 15:f44=lc41_int4bd2c0(parts[1]);break;
    case 16:f58=lc41_float4bd300(parts[1]);break;
    case 17:f60=lc41_float4bd300(parts[1]);break;
    case 18:range90.set40a010(lc41_int4bd2c0(parts[1]),lc41_int4bd2c0(parts[2]));break;
    case 19:f98=lc41_int4bd2c0(parts[1]);break;
    case 20:f9c=lc41_int4bd2c0(parts[1]);break;
    case 21:fa0=lc41_int4bd2c0(parts[1]);f5c=lc41_int4bd2c0(parts[2]);if(fa0>0&&f58==0)return false;break;
    case 22:f64=lc41_int4bd2c0(parts[1]);f68=lc41_int4bd2c0(parts[2]);if(f64<=0||f68<=0)return false;break;
    case 23:f6c=lc41_int4bd2c0(parts[1]);break;
    case 24:{LC41Bridge bridge;bridges.push_back(bridge);bridges.back().enabled=true;bridges.back().level=lc41_int4bd2c0(parts[1]);bridges.back().unknown08=lc41_int4bd2c0(parts[2]);bridges.back().chance=parts[3]==lc41_bced00?100:lc41_int4bd2c0(parts[3]);bridges.back().dir=lc41_find9cda80(lc41_cf63b8,4,parts[6]);if(bridges.back().dir==-1)return false;
     if(!bridges.back().x.parse40bf80(parts[4])||!bridges.back().y.parse40bf80(parts[5])||!bridges.back().width.parse40bf80(parts[7])||!bridges.back().length.parse40bf80(parts[8]))return false;break;}
    case 25:{LC41Record record;records.push_back(record);LC41Record*data=&records.back();data->enabled=true;data->level=lc41_int4bd2c0(parts[1]);data->chance=parts[2]==lc41_bced04?100:lc41_int4bd2c0(parts[2]);data->type=lc41_find9cda80(lc41_d1e4b8,21,parts[3]);data->index=-1;data->flag4c=false;
     if(data->type==-1){data->type=21;if(parts[3][0]=='*'){data->flag4c=true;lc41_erase4077e0(parts[3]);}data->name=parts[3];data->suffix4485a0();if(parts[4]!=lc41_bced08)data->other=parts[4];}
     data->value=lc41_int4bd2c0(parts[5]);if(parts[6]!=lc41_bced0c){for(int i=0;i<4;i++){if(parts[6].find(lc41_cf63b8[i],0)!=string::npos)data->directions.push_back(i);}}
     if(data->type==21&&data->directions.empty())data->directions.push_back(2);
     data->category=lc41_find9cda80(lc41_d2e840,6,parts[7]);if(data->category==-1)return false;data->flag84=parts[8][0]!='-';
     if(!data->range88.parse40bf80(parts[9])||!data->range90.parse40bf80(parts[10])||!data->range98.parse40bf80(parts[11])||!data->rangeA0.parse40bf80(parts[12]))return false;data->extra=0;break;}
    case 26:if(records.empty()||records.back().name.empty())return false;records.back().extra=lc41_int405610(parts[1]);break;
    case 27:{LC41Rect rect;regions.push_back(rect);regions.back().x=lc41_int4bd2c0(parts[1]);regions.back().y=lc41_int4bd2c0(parts[2]);regions.back().w=lc41_int4bd2c0(parts[3]);regions.back().h=lc41_int4bd2c0(parts[4]);break;}
    }next++;
   }
  }
  input.close9c05e0();if(next<24)return false;
 }
 return true;
}
