#include <string>
using std::string;
// NOTE: private partial ABI views and genuine native owners.
struct LB25Source{char p[0x24];int kind;char p28[0x45-0x28];bool mute,stamp;};
struct LB25Entity;struct LB25P{int x,y;};struct LB25H{int id;LB25H()throw();LB25Entity*get9b6570()const throw();};
struct LB25Msg{LB25Source*source;string text;int row,turn;LB25Msg(const LB25Msg&);~LB25Msg();};
LB25Msg::LB25Msg(const LB25Msg&a):source(a.source){row=a.row;turn=a.turn;}
struct LB25Messages{LB25Msg**begin,**end,**capacity;std::allocator<LB25Msg*>allocator;unsigned size9b9260()const throw();bool empty9b86e0()const throw();LB25Msg*&back9b6540()throw();LB25Msg*&at9b81f0(unsigned)throw();void push9b9d30(LB25Msg*const&);};
struct LB25Ints{int*begin,*end,*capacity;std::allocator<int>allocator;LB25Ints();~LB25Ints();bool empty9b86e0()const throw();unsigned size9b9260()const throw();int&back9b6540()throw();int&at9b81f0(unsigned)throw();void push9b9d30(const int&);void push9b9280(int&&);};
struct LB25Log:LB25Messages{string last;int width;bool streaming;char p31[3];int kind;bool wrapped;int push5121f0(LB25Msg*);void output513bb0(int);LB25Messages&messages9c0790()throw();};extern LB25Log lb25_cf1080;
struct LB25Map{int turn464270()throw();};extern LB25Map*lb25_cefc4c;
struct LB25Type{char p[0x20];int kind;};struct LB25Types{LB25Type*&at9b81f0(unsigned)throw();};extern LB25Types lb25_d35b48;
struct LB25Dialog{void show874d80(LB25H,const string&);};extern LB25Dialog*lb25_cec058;
extern LB25H lb25_d388f4;
struct LB25CMap{void message808860(const string&,int);};extern LB25CMap*lb25_cec054;
struct LB25CLog{void renew48e5b0();};extern LB25CLog*lb25_cec0b4,*lb25_cec0c4;
extern bool lb25_d28f60,lb25_cefc70,lb25_d28d16,lb25_d28f63,lb25_d28f62;
extern string lb25_d2ed60,lb25_d312d4,lb25_cf364c;extern unsigned lb25_c2ea48;extern int lb25_cebd64,lb25_cefb6c;
bool lb25_equal9d6280(LB25Messages&,LB25Messages&);int lb25_digit405b40(char);string lb25_int4051f0(int);string&lb25_pad408090(string&,unsigned,char);void logError(string,string);
bool lb25_route5111e0(int,const string*,const string*,const string*,LB25H,LB25H,const LB25P*,bool);
int LB25Log::push5121f0(LB25Msg*text){
 int type=size9b9260();int count=kind;kind=1;
 if(lb25_d28f60&&text->source&&text->source->mute){delete text;return size9b9260()-type;}
 string p=last;last=text->text;wrapped=false;
 if(lb25_cefc70)lb25_cec058->show874d80(LB25H(),text->text);else if(lb25_d388f4.get9b6570())lb25_cec058->show874d80(lb25_d388f4,text->text);
 if(text->source&&lb25_d35b48.at9b81f0(text->source->kind)->kind==3&&count)lb25_cec054->message808860(text->text,count);
 bool stamp=lb25_d28d16&&((streaming&&!lb25_d28f63)||(!streaming&&!lb25_d28f62))&&lb25_cefc4c->turn464270()>=2&&text->source&&!text->source->stamp;
 if(!empty9b86e0()&&!p.empty()&&text->text!=" "&&text->text!="\n"&&text->text==p){
  int x=back9b6540()->text.find(lb25_d2ed60,0);if(x==lb25_c2ea48)x=-1;
  string*value=&back9b6540()->text;bool valid=(size9b9260()>1&&back9b6540()->row==at9b81f0(size9b9260()-2)->row)?true:false;
  if(x!=-1){int num=x+lb25_d2ed60.size();if((*value)[num]!='*'){int n=lb25_digit405b40((*value)[num]);(*value)[num]=n==9?'*':lb25_int4051f0(n+1).c_str()[0];if(lb25_equal9d6280(lb25_cf1080.messages9c0790(),*this))lb25_cec0b4->renew48e5b0();else lb25_cec0c4->renew48e5b0();}}
  else if(value->size()+lb25_d2ed60.size()+lb25_d312d4.size()+1<=(valid?width-2:width)){(*value)+=lb25_d2ed60;(*value)+="2";(*value)+=lb25_d312d4;if(lb25_equal9d6280(lb25_cf1080.messages9c0790(),*this))lb25_cec0b4->renew48e5b0();else lb25_cec0c4->renew48e5b0();}
  else{text->text=" ";text->text+=lb25_d2ed60;text->text+="2";text->text+=lb25_d312d4;text->row=back9b6540()->row;stamp=false;wrapped=true;goto append;}
  delete text;output513bb0(0);return size9b9260()-type;
 }
 text->row=empty9b86e0()?0:back9b6540()->row+1;
 append:
 text->turn=lb25_cefc4c?lb25_cefc4c->turn464270():0;
 if(stamp){string line;if(lb25_cefc4c){int n=lb25_cefc4c->turn464270();while(n>99999)n-=99999;line=lb25_int4051f0(n);}lb25_pad408090(line,5,'0');line+=lb25_cf364c;text->text.insert(0,line);}
 if(text->text.size()<=lb25_cebd64&&text->text.find('\n',0)==lb25_c2ea48)push9b9d30(text);
 else{
  LB25Msg*p;int i,a,f;string str=text->text;LB25Ints active;LB25Ints v;int list=0;bool table=false;int vis=0;
  do{f=active.empty9b86e0()?lb25_cebd64:lb25_cebd64-2;active.push9b9d30(list);for(i=list,a=0;i<str.size()&&a<f;i++,a++){if(str[i]=='\n')break;}
   if(i<str.size()){
    if(str[i]=='\n'){v.push9b9280(i-1);list=i+1;}
    else if(str[i]==' '){v.push9b9280(i-1);int n=str.find_first_of(' ',i+1);if(n==lb25_c2ea48)table=true;else list=n;}
    else{vis++;if(vis>10000){logError("MessageLog::push()","Infinite loop detected, message erased: "+text->text);delete text;return 0;}
     int n=str.rfind(' ',i-1);if(n==lb25_c2ea48){v.push9b9280(i-1);list=i;}else if(i-n+1>f){v.push9b9280(i-1);list=i;}else{v.push9b9280(n-1);list=n+1;}
    }
   }else v.push9b9280(str.size()-1);
  }while((v.empty9b86e0()||v.back9b6540()!=str.size()-1)&&!table);
  for(unsigned i=0;i<active.size9b9260();i++){p=new LB25Msg(*text);p->text.assign(text->text,active.at9b81f0(i),v.at9b81f0(i)-active.at9b81f0(i)+1);if(i)p->text.insert(0,2,' ');push9b9d30(p);}delete text;
 }
 if(lb25_cefb6c){lb25_cefb6c=0;string data("internal `msg");lb25_route5111e0(805,&data,0,0,LB25H(),LB25H(),0,false);}
 output513bb0(size9b9260()-type);return size9b9260()-type;
}
