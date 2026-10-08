// alpha2_02: scoresheet upload thread callback (0x4884c0), from codex scratch/loop_charlie_43/upload_mutable.cpp.
// NOTE: placeholder names; private native transport and borrowed owner interfaces.
#include <string>
#include <vector>
#include <fstream>
#include "../web/scoresheet.pb.h"
#include "../thirdparty/zfstream.h"
using std::string;
struct LC43Https{LC43Https();virtual ~LC43Https();void agent4533e0(const string&);void server453400(const string&);void path453420(const string&);bool connect4f91a0(string);bool send4f9710(string&,const string&,string*);string response4f9ae0();void*internet,*request,*connect;string agent,server,path;unsigned short port;unsigned flags;string responseHeader;};
struct LC43Owner{Protobuf::PostScoresheetRequest*request;bool threaded;void serialize471a50(std::ostream&);};
struct LC43Discord{void add4f9f50(string);};extern LC43Discord*lc43_cefb5c;
extern string lc43_cfd42c,lc43_d21928,lc43_d307d0[],lc43_d2f508[];
extern std::vector<string>lc43_d25780;extern bool lc43_cefb58,lc43_cefc5e;
extern unsigned char lc43_d25680[],lc43_d256a0[];
extern "C" __declspec(dllimport) int __cdecl crypto_sign_detached(unsigned char*,unsigned long long*,const unsigned char*,unsigned long long,const unsigned char*);
string lc43_hex405ea0(const unsigned char*,unsigned);string lc43_int4051f0(int);void lc43_error404f10(string,string);void lc43_log404cb0(string);void lc43_mkdir409240(string);void lc43_replace407f00(string&,string,string);void lc43_erase9cfab0(std::vector<string>&,int);void lc43_quit449780(int);
static_assert(sizeof(LC43Https)==136,"native HTTPS owner");static_assert(sizeof(Protobuf::PostScoresheetResponse)==20,"generated response owner");static_assert(sizeof(LC43Owner)==8,"actual UploadScoreData record");
extern const char lc43_b9047e[],lc43_bbc4a8[],lc43_bbc4c4[],lc43_bbc4d4[],lc43_bbc4e0[],lc43_bbc500[],lc43_bbc510[],lc43_bbc518[],lc43_bbc540[],lc43_bbc544[],lc43_bbc55c[],lc43_bbc560[],lc43_bbc578[],lc43_bbc59c[],lc43_bbc5c0[],lc43_bbc5d0[],lc43_bbc5f8[],lc43_bbc600[],lc43_bbc604[],lc43_bbc60c[],lc43_bbc610[],lc43_bbc614[],lc43_bbc61c[],lc43_bbc620[],lc43_bbc628[],lc43_bbc630[],lc43_bbc65c[],lc43_bbc664[],lc43_bbc66c[],lc43_bbc670[],lc43_bbc684[],lc43_bbc688[],lc43_bbc68c[],lc43_bbc690[],lc43_bbc694[],lc43_bbc698[],lc43_bbc6a4[],lc43_bbc6bc[],lc43_bbc6c8[],lc43_bbc6d0[],lc43_bbc6d4[],lc43_bbc6d8[],lc43_bbc6dc[],lc43_bbc714[],lc43_bbc71c[],lc43_bbc72c[],lc43_bbc734[],lc43_bbc744[],lc43_bbc754[],lc43_bbc75c[],lc43_bbc760[],lc43_bbc764[],lc43_bbc768[],lc43_bbc778[],lc43_bbc7a4[],lc43_bbc7b0[],lc43_bbc7bc[],lc43_bbc7c0[],lc43_bbc7c8[],lc43_bbc7cc[],lc43_bbc7e0[];
int lc43_upload4884c0(LC43Owner*data){
 bool old=data->threaded;Protobuf::PostScoresheetRequest*n=data->request;
 string x;
 if(!n->SerializeToString(&x))lc43_error404f10(lc43_bbc4c4,lc43_bbc4a8);
 LC43Https h;
 h.agent4533e0(lc43_bbc4d4+lc43_d21928);h.server453400(lc43_bbc4e0);h.path453420(lc43_bbc500);
 if(!h.connect4f91a0(lc43_bbc510)){(old?lc43_cefb58:lc43_cefc5e)=false;}else{
  {
   string res=lc43_hex405ea0(lc43_d25680,32);unsigned char signature[64];
   crypto_sign_detached(signature,0,reinterpret_cast<const unsigned char*>(x.c_str()),x.size(),lc43_d256a0);
   string score=lc43_hex405ea0(signature,64);string y=lc43_bbc518;
   y+=lc43_bbc544+res+lc43_bbc540;y+=lc43_bbc560+score+lc43_bbc55c;y+=lc43_bbc578;
   if(!h.send4f9710(y,lc43_b9047e,&x)){(old?lc43_cefb58:lc43_cefc5e)=false;goto finished;}
  }
  {
  string score=h.response4f9ae0();Protobuf::PostScoresheetResponse i;
  if(!i.ParseFromString(score))lc43_error404f10(lc43_bbc5c0,lc43_bbc59c);
  string y=i.url();string res=i.error_message();(old?lc43_cefb58:lc43_cefc5e)=res.empty();
  if(res.empty()){
   lc43_d25780.push_back(n->mutable_scoresheet()->mutable_meta()->run_guid());
   while(lc43_d25780.size()>25)lc43_erase9cfab0(lc43_d25780,0);
   lc43_log404cb0(lc43_bbc5d0);lc43_log404cb0(lc43_bbc600+y+lc43_bbc5f8);lc43_log404cb0(lc43_bbc60c+y+lc43_bbc604);
   string path=lc43_cfd42c+lc43_bbc614+lc43_bbc610+n->mutable_scoresheet()->mutable_header()->filename();
   std::ofstream file(path.c_str(),std::ios_base::out|std::ios_base::app);
   if(file.is_open()){file<<lc43_bbc61c;file<<y<<lc43_bbc620;file<<y<<lc43_bbc628;file.close();}
   if(old&&lc43_cefb5c){
    lc43_log404cb0(lc43_bbc630);string n1=lc43_bbc65c;
    n1+=n->mutable_scoresheet()->mutable_header()->player_name()+lc43_bbc664;
    if(n->mutable_scoresheet()->mutable_header()->win())n1+=lc43_bbc670+lc43_int4051f0(n->mutable_scoresheet()->mutable_game()->win_type())+lc43_bbc66c;
    else n1+=n->mutable_scoresheet()->mutable_header()->run_result()+lc43_bbc684;
    n1+=lc43_bbc688;
    string s=lc43_bbc68c+lc43_d307d0[n->mutable_scoresheet()->mutable_header()->difficulty()];
    if(n->mutable_scoresheet()->mutable_header()->special_mode())s+=lc43_bbc690+lc43_d2f508[n->mutable_scoresheet()->mutable_header()->special_mode()];
    s+=lc43_bbc694;
    n1+=lc43_bbc6c8+lc43_int4051f0(n->mutable_scoresheet()->performance().total_score())+s+lc43_bbc6bc+lc43_int4051f0(n->mutable_scoresheet()->performance().regions_visited().count())+lc43_bbc6a4+lc43_int4051f0(n->mutable_scoresheet()->performance().robots_destroyed().count())+lc43_bbc698;
    n1+=lc43_bbc6d0;
    unsigned self=y.rfind(lc43_bbc6d4);
    if(self!=string::npos){string text(y.begin()+self+1,y.end());string found=lc43_bbc71c+y+lc43_bbc714+lc43_bbc6dc+text+lc43_bbc6d8;n1+=found;}
    string temp;string v;const string*y=&n->textual_scoresheet();string first=lc43_bbc72c;
    self=y->find(first);
    if(self!=string::npos){string first=lc43_bbc734;unsigned score=y->find(first);if(score!=string::npos){temp.assign(y->begin()+self,y->begin()+score-2);self=temp.find(lc43_bbc744);if(self!=string::npos){score=temp.rfind('>',self);v.assign(temp.begin()+score,temp.end());temp.erase(temp.begin()+score,temp.end());temp=lc43_bbc754+temp;}}}
    bool ok=false;
    if(!temp.empty()&&n1.size()+temp.size()<1900){n1+=temp;ok=true;}
    if(!v.empty()&&n1.size()+v.size()<1900){n1+=v;ok=true;}
    if(ok)n1+=lc43_bbc75c;
    lc43_replace407f00(n1,lc43_bbc764,lc43_bbc760);lc43_log404cb0(lc43_bbc768);lc43_cefb5c->add4f9f50(n1);
   }
  }else lc43_log404cb0(lc43_bbc778+res);
  }
 }
finished:
 if(old&&!lc43_cefb58){
  string first=lc43_cfd42c+lc43_bbc7a4;lc43_mkdir409240(lc43_cfd42c+lc43_bbc7b0);first+=lc43_bbc7bc;first+=n->mutable_scoresheet()->mutable_header()->filename();unsigned i=first.rfind('.');if(i!=string::npos){first.erase(first.begin()+i,first.end());first+=lc43_bbc7c0;
  gzofstream file(first.c_str(),std::ios_base::trunc|std::ios_base::binary);
  if(!file.is_open())lc43_error404f10(lc43_bbc7e0,lc43_bbc7cc+first+lc43_bbc7c8);else{data->serialize471a50(file);file.close();}
  }
 }
 delete data;if(old)lc43_quit449780(3);return 0;
}
