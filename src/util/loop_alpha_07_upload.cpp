// NOTE: private upload-thread aliases and partial input layout, retail0x48ae20.
#include <string>
using std::string;
struct LA7Ints {char data[16];unsigned size9b9260() const throw();int& operator[](unsigned) throw();};
struct LA7Run {int id;string name;int seed;LA7Ints a1,turns,x,v1;};
struct LA7Http {LA7Http(const string&,const string&,int);~LA7Http();bool upload4cfd20(const string&,const string&);string host,text;int port;};
void la7_log404bf0(string,string);string la7_int4051f0(int);string la7_date436e70(bool,__int64);void la7_quit449780(int) throw();
extern const char la7_bbc9bc[],la7_bbc9c0[],la7_bbc9c4[],la7_bbc9c8[],la7_bbc9f0[],la7_bbc9ec[],la7_bbc9e8[];
int la7_upload48ae20(void *data) {
 la7_log404bf0("CXLJEXZ","VC530SA...");
 LA7Ints *a1=&((LA7Run*)data)->a1;LA7Ints *turns=&((LA7Run*)data)->turns;LA7Ints *x=&((LA7Run*)data)->x;LA7Ints *v1=&((LA7Run*)data)->v1;
 string *content=new string;
 for(int i=0;i<turns->size9b9260();i++) {
  *content+=la7_int4051f0((*turns)[i]);*content+=la7_bbc9bc;
  *content+=la7_int4051f0((*a1)[i]);*content+=la7_bbc9c0;
  *content+=la7_int4051f0((*x)[i]);*content+=la7_bbc9c4;
  *content+=la7_int4051f0((*v1)[i]);*content+=la7_bbc9c8;
 }
 la7_log404bf0("A98+>>","CVGLSAFDV...");
 string filename=((LA7Run*)data)->name+la7_bbc9f0+la7_date436e70(false,0)+la7_bbc9ec+la7_int4051f0(((LA7Run*)data)->id)+la7_bbc9e8+la7_int4051f0(((LA7Run*)data)->seed)+string()+".xi";
 string text("/cogmind/temp/run_data_xi_17-260816/upload.php");
 LA7Http f("www.gridsagegames.com",text,80);
 f.upload4cfd20(filename,*content);
 delete data;
 la7_quit449780(5);
 return 0;
}
