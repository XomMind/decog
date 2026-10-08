// Private replay upload thread, with genuine gzifstream ABI from bundled header.
#include <string>
#include <cstdio>
#include "thirdparty/zfstream.h"
using std::string;
struct LA9Files {unsigned a,b,c,d;bool empty9b86e0()const throw();unsigned size9b0650()const throw();string &operator[](unsigned) throw();};
struct LA9Dir {string name;LA9Files files;};
struct LA9Dirs {unsigned a,b,c,d;LA9Dirs() throw();~LA9Dirs() throw();LA9Dir *&operator[](unsigned) throw();};
struct LA9Resource {void tree4156c0(string,LA9Dirs*,string);};extern LA9Resource *la9_cefa88;extern string la9_cfd42c;extern LA9Files la9_d25780;extern bool la9_cefc5e;
struct LA9Meta {const string &runName44b0d0() throw();};struct LA9Sheet {LA9Meta *meta44bc00() throw();};struct LA9Post {LA9Sheet *sheet44b040() throw();};
struct LA9Owner {LA9Owner(std::istream&,bool);LA9Post *request;bool flag;};
bool la9_contains9d3fe0(LA9Files&,string);int la9_upload4884c0(LA9Owner*);void la9_erase9d3d90(LA9Files&,int&) throw();
void la9_info405090(string,string);void la9_error404f10(string,string);void la9_log404cb0(string);string la9_int4051f0(int);void la9_quit449780(int) throw();struct LA9JLog {int end410e50(int) throw();};extern LA9JLog *la9_cefa64;
extern const char la9_bbc834[],la9_bbc858[],la9_bbc8bc[],la9_bbc8dc[],la9_bbc864[],la9_bbc8b8[],la9_bbc8d8[];
int la9_reupload489c20(void*) {
 la9_info405090("checkScoreReupload()","Checking for old scores to upload...");
 LA9Dirs dirs;
 la9_cefa88->tree4156c0(la9_cfd42c+la9_bbc834,&dirs,"bin");
 if(!dirs[0]->files.empty9b86e0()) {
  la9_log404cb0("Found "+la9_int4051f0(dirs[0]->files.size9b0650())+" relevant files");
  for(int i=0;i<dirs[0]->files.size9b0650();i++) {
   string path=la9_cfd42c+la9_bbc858;path+=la9_bbc864;path+=dirs[0]->files[i];
   gzifstream file(path.c_str(),std::ios_base::binary);
   if(!file.is_open()) la9_error404f10("checkScoreReupload()","Unable to open \""+dirs[0]->files[i]+"\"");
   else {
    LA9Owner *owner=new LA9Owner(file,false);file.close();
    if(la9_contains9d3fe0(la9_d25780,owner->request->sheet44b040()->meta44bc00()->runName44b0d0())) {
     la9_log404cb0("Skipping already uploaded run: "+dirs[0]->files[i]);
     remove((la9_cfd42c+la9_bbc8bc+la9_bbc8b8+dirs[0]->files[i]).c_str());
     la9_erase9d3d90(dirs[0]->files,i);
    } else {
     la9_log404cb0("Uploading "+dirs[0]->files[i]+"...");la9_upload4884c0(owner);
     if(la9_cefc5e) {
      remove((la9_cfd42c+la9_bbc8dc+la9_bbc8d8+dirs[0]->files[i]).c_str());la9_erase9d3d90(dirs[0]->files,i);la9_log404cb0("Upload succeeded");
     } else {la9_log404cb0("Upload failed, quitting");break;}
    }
   }
  }
 }
 la9_cefa64->end410e50(2);la9_quit449780(2);return 0;
}
