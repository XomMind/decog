// NOTE: private partial layouts and external aliases for score/news polling thread 79ba00.
#include <string>
#include <vector>
using namespace std;
extern "C" __declspec(dllimport) void __cdecl SDL_Delay(unsigned);
struct NewsHttp{string host,path;int port;NewsHttp(const string&,const string&,int);~NewsHttp();string check4d08e0(bool);};
struct NewsRecord{int kind,id,value;string text,other;NewsRecord(int,int);~NewsRecord()throw();};
struct NewsMap{char pad[0x18];string name;};struct NewsName{int pad;string name;};
struct NewsManager{bool flag;char gap[0x13];string version;char gap30[8];int delay;bool active,busy;char gap3e[2];string last;vector<NewsRecord*>records;vector<int>ids;};
extern NewsManager *news_cefc58;extern int news_cefc7c,news_cefc78,news_cefc74,news_caed20;
extern string news_d1f410[],news_d01860[];extern int news_bbc168[];extern vector<NewsMap*>news_cfd2ec;extern vector<NewsName*>news_cf67c0;
int newsSplit408c20(string&,const string&,const string&,vector<string>&);void newsParse408d70(string&,vector<string>&);bool newsBracket6c3170(const string&,string&,string&);int newsFind9cda80(const string*,unsigned,string);int newsInt405610(const string&);bool newsContains9db330(vector<int>&,int);int newsMap9e2020(vector<NewsMap*>&,const string&);int newsName9d7b80(vector<NewsName*>&,const string&);void newsQuit449780(int)throw();
NewsRecord::NewsRecord(int k,int i):kind(k),id(i),value(0){}
int newsThread79ba00(void*){
 SDL_Delay(news_cefc58->delay);
 while(true){
  while(news_cefc58->busy)SDL_Delay(20);
  news_cefc58->active=true;
  NewsHttp a("www.gridsagegames.com","/cogmind/temp/scores.php",80);
  news_cefc7c=0;
  string b=a.check4d08e0(news_cefc58->flag);
  if(b!=news_cefc58->last){
   news_cefc58->last=b;
   vector<string>i;string record;string x;
   if(newsSplit408c20(b,"<L>","</L>",i))for(unsigned n=0;n<i.size();n++){
    vector<string>p;newsParse408d70(i[n],p);
    if(n==0){if(news_cefc58->version!=p[0])break;}
    else{
     if(p.size()<2)goto nextLine;
     if(!newsBracket6c3170(p[1],record,x))goto nextLine;
     int count=newsFind9cda80(news_d1f410,28,record);if(count==-1)goto nextLine;
     if(p.size()<news_bbc168[count]+2)goto nextLine;
     int a=newsInt405610(p[0]);
     if(!newsContains9db330(news_cefc58->ids,a)){
      NewsRecord*i=new NewsRecord(count,a);bool type=false;
      switch(count){
       case 0:news_cefc58->delay=newsInt405610(x)*1000;type=true;break;
       case 1:case 2:case 17:
        i->text=x;
        if(p.size()>2)switch(count){
         case 1:if(!newsBracket6c3170(p[2],record,x))type=true;else{i->value=newsMap9e2020(news_cfd2ec,x);if(i->value==-1)i->value=0;}break;
         case 2:if(!newsBracket6c3170(p[2],record,x))type=true;else i->other=x;
          if(p.size()>3){if(!newsBracket6c3170(p[3],record,x))type=true;else i->value=newsInt405610(x);}break;
         case 17:if(!newsBracket6c3170(p[2],record,x))type=true;else{i->value=newsName9d7b80(news_cf67c0,x);if(i->value==-1)type=true;}break;
        }break;
       case 4:i->value=newsMap9e2020(news_cfd2ec,x);if(i->value==-1)type=true;break;
       case 3:i->text=x;
        if(!newsBracket6c3170(p[2],record,x))type=true;
        else{
         i->value=-1;
         if(x!="-1")for(unsigned j=0;j<news_cfd2ec.size();j++){if(news_cfd2ec[j]->name==x){i->value=j;break;}}
         if(p.size()>3){if(!newsBracket6c3170(p[3],record,x))type=true;else i->other=x;}
        }break;
       case 5:case 6:i->text=x;if(p.size()>2){if(!newsBracket6c3170(p[2],record,x))type=true;else i->other=x;}break;
       case 7:case 8:case 9:case 12:case 16:
        i->text=x;if(!newsBracket6c3170(p[2],record,x))type=true;else i->other=x;
        if(count==8||count==9){if(i->other.size()>46)type=true;}
        if(count==16&&p.size()>3){if(!newsBracket6c3170(p[3],record,x))type=true;else{i->value=newsName9d7b80(news_cf67c0,x);if(i->value==-1)type=true;}}break;
       case 10:i->value=newsInt405610(x);break;
       case 11:break;
       case 13:i->text=x;if(!newsBracket6c3170(p[2],record,x))type=true;else i->value=newsInt405610(x);break;
       case 14:case 15:case 19:
        i->text=x;if(!newsBracket6c3170(p[2],record,x))type=true;
        else{i->value=newsFind9cda80(news_d01860,15,x);if(count==14||count==15){if(p.size()>3){if(!newsBracket6c3170(p[3],record,x))type=true;else i->other=x;}}}break;
       case 18:i->text=x;if(p.size()>2){if(!newsBracket6c3170(p[2],record,x))type=true;else i->other=x;}break;
       case 20:i->text=x;if(!newsBracket6c3170(p[2],record,x))type=true;
        else{i->other=x;if(!newsBracket6c3170(p[3],record,x))type=true;else i->value=newsInt405610(x);}break;
       case 21:case 22:i->text=x;break;
       case 23:break;
       case 24:case 25:case 26:case 27:i->value=newsInt405610(x);break;
       default:type=true;
      }
      if(type)delete i;
      else{news_cefc58->records.push_back(i);news_cefc58->ids.push_back(i->id);news_cefc7c++;}
     }
    }
    nextLine:;
   }
  }
  if(news_cefc7c!=0){news_cefc78=news_caed20;news_cefc74=news_caed20+2000;}
  news_cefc58->active=false;SDL_Delay(news_cefc58->delay);
 }
 newsQuit449780(6);return 0;
}
