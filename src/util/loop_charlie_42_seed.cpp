// NOTE: recursive seed string decoder4351e0; native RNG state extents recovered from actual seed bodies.
// Borrowed native grid interfaces are partial; no grid object is allocated/copied/destructed here.
// Private constructors and complex external calls retain ordinary exception contracts; no fabricated helper bodies.
#include <string>
#include <ctype.h>
#include "rng.h"
#include "rngc.h"
using namespace std;
struct LC42Pcg {unsigned initState,initSeq;unsigned __int64 state,inc;LC42Pcg();void seed407060(unsigned);int range4070a0(int,unsigned);};
struct LC42Rng4 {int currentSeed;unsigned a,b,c,d;LC42Rng4();void seed4070d0(int);int range407120(int,unsigned);};
struct LC42Xoro {unsigned seed;unsigned state[2];LC42Xoro();void seed407150(unsigned);int range407180(int,unsigned);};
struct LC42R4071b0{unsigned state;LC42R4071b0();void seed4071b0(unsigned);int range4071d0(int,unsigned);};
struct LC42R407200{unsigned state;LC42R407200();void seed407200(unsigned);int range407220(int,unsigned);};
struct LC42R407250{unsigned state[2];LC42R407250();void seed407250(unsigned);int range407280(int,unsigned);};
struct LC42R4072b0{unsigned state[2];LC42R4072b0();void seed4072b0(unsigned);int range4072e0(int,unsigned);};
struct LC42R407310{unsigned state[4];LC42R407310();void seed407310(unsigned);int range407350(int,unsigned);};
struct LC42R407380{unsigned state[4];LC42R407380();void seed407380(unsigned);int range4073c0(int,unsigned);};
struct LC42R4073f0{unsigned state[3];LC42R4073f0();void seed4073f0(unsigned);int range407420(int,unsigned);};
struct LC42R407450{unsigned state[3];LC42R407450();void seed407450(unsigned);int range407480(int,unsigned);};
static_assert(sizeof(RNG)==2508&&sizeof(RNGC)==4&&sizeof(LC42Pcg)==24&&sizeof(LC42Rng4)==20&&sizeof(LC42Xoro)==12,"actual native engine states");
static_assert(sizeof(LC42R4071b0)==4&&sizeof(LC42R407200)==4&&sizeof(LC42R407250)==8&&sizeof(LC42R4072b0)==8&&sizeof(LC42R407310)==16&&sizeof(LC42R407380)==16&&sizeof(LC42R4073f0)==12&&sizeof(LC42R407450)==12,"actual scalar RNG states");
struct LC42CharGrid{char*at9cec50(int,int);};extern LC42CharGrid lc42_d21b28;
struct LC42IntGrid{int*at9ceda0(int,int);};extern LC42IntGrid lc42_d396dc;
int lc42_index9cf120(const char*,unsigned,char);int lc42_digit405b40(char);void lc42_rotate434e50(string&);void lc42_shift4350b0(string&,int);
extern char lc42_caf450[];extern int lc42_cec150[];
extern int lc42_caf474;
extern char lc42_cef680[];
extern int lc42_caf478;
extern char lc42_cef9e0[];
extern int lc42_caf47c;
extern char lc42_ced0e8[];
extern int lc42_caf480;
extern char lc42_cebe58[];
extern int lc42_caf484;
extern char lc42_cec968[];
extern int lc42_caf488;
extern int lc42_caf584;
extern char lc42_cebdd8[];
extern int lc42_caf48c;
extern int lc42_caf588;
extern char lc42_cec3d0[];
extern int lc42_caf490;
extern int lc42_caf58c;
extern char lc42_cec350[];
extern int lc42_caf494;
extern int lc42_caf590;
extern char lc42_cebc58[];
extern int lc42_caf498;
extern int lc42_caf594;
extern char lc42_cec9e8[];
extern int lc42_caf49c;
extern int lc42_caf598;
extern char lc42_cef700[];
extern int lc42_caf4a0;
extern int lc42_caf59c;
extern char lc42_cebcd8[];
extern int lc42_caf4a4;
extern int lc42_caf5a0;
bool lc42_decode4351e0(string&s){
 if(s.size()<4)goto done;
 if(lc42_index9cf120(lc42_caf450,12,s[0])==-1)goto done;
 switch(s[1]){
case 'b':{RNG p;p.seed(lc42_cec150[s[2]]-1);s.erase(s.begin(),s.begin()+3);for(int i=0;i<s.size();i++)s[i]=s[i]+p.rangeInt(1,lc42_caf474);break;}
case 'S':{RNGC p;p.seed(lc42_cef680[s[2]]);s.erase(s.begin(),s.begin()+3);for(int i=0;i<s.size();i++)s[i]=s[i]+p.rangeInt(1,lc42_caf478);break;}
case 'q':{LC42Pcg p;p.seed407060(lc42_cef9e0[s[2]]);s.erase(s.begin(),s.begin()+3);for(int i=0;i<s.size();i++)s[i]=s[i]+p.range4070a0(1,lc42_caf47c);break;}
case 'u':{LC42Rng4 p;p.seed4070d0(lc42_ced0e8[s[2]]);s.erase(s.begin(),s.begin()+3);for(int i=0;i<s.size();i++)s[i]=s[i]+p.range407120(1,lc42_caf480);break;}
case 'x':{LC42Xoro p;p.seed407150(lc42_cebe58[s[2]]);s.erase(s.begin(),s.begin()+3);for(int i=0;i<s.size();i++)s[i]=s[i]+p.range407180(1,lc42_caf484);break;}
case 'g':{LC42R4071b0 p;p.seed4071b0(lc42_cec968[s[2]]);s.erase(s.begin(),s.begin()+3);int count=p.range4071d0(1,lc42_caf584);for(int i=0;i<count;i++)p.range4071d0(1,lc42_caf584);for(int i=0;i<s.size();i++)s[i]=s[i]+p.range4071d0(1,lc42_caf488);break;}
case '*':{LC42R407200 p;p.seed407200(lc42_cebdd8[s[2]]);s.erase(s.begin(),s.begin()+3);int count=p.range407220(1,lc42_caf588);for(int i=0;i<count;i++)p.range407220(1,lc42_caf588);for(int i=0;i<s.size();i++)s[i]=s[i]+p.range407220(1,lc42_caf48c);break;}
case '(':{LC42R407250 p;p.seed407250(lc42_cec3d0[s[2]]);s.erase(s.begin(),s.begin()+3);int count=p.range407280(1,lc42_caf58c);for(int i=0;i<count;i++)p.range407280(1,lc42_caf58c);for(int i=0;i<s.size();i++)s[i]=s[i]+p.range407280(1,lc42_caf490);break;}
case 'A':{LC42R4072b0 p;p.seed4072b0(lc42_cec350[s[2]]);s.erase(s.begin(),s.begin()+3);int count=p.range4072e0(1,lc42_caf590);for(int i=0;i<count;i++)p.range4072e0(1,lc42_caf590);for(int i=0;i<s.size();i++)s[i]=s[i]+p.range4072e0(1,lc42_caf494);break;}
case '{':{LC42R407310 p;p.seed407310(lc42_cebc58[s[2]]);s.erase(s.begin(),s.begin()+3);int count=p.range407350(1,lc42_caf594);for(int i=0;i<count;i++)p.range407350(1,lc42_caf594);for(int i=0;i<s.size();i++)s[i]=s[i]+p.range407350(1,lc42_caf498);break;}
case '[':{LC42R407380 p;char old=s[2];bool clean=s[3]=='1';s.erase(s.begin(),s.begin()+4);p.seed407380(clean?lc42_cec9e8[old]:s.size());int parts=p.range4073c0(1,lc42_caf598);for(int i=0;i<parts;i++)p.range4073c0(1,lc42_caf598);for(int i=0;i<s.size();i++)s[i]=s[i]+p.range4073c0(1,lc42_caf49c);break;}
case '^':{LC42R4073f0 p;char old=s[2];bool clean=s[3]=='1';s.erase(s.begin(),s.begin()+4);p.seed4073f0(clean?lc42_cef700[old]:s.size());int parts=p.range407420(1,lc42_caf59c);for(int i=0;i<parts;i++)p.range407420(1,lc42_caf59c);for(int i=0;i<s.size();i++)s[i]=s[i]+p.range407420(1,lc42_caf4a0);break;}
case '?':{LC42R407450 p;char old=s[2];bool clean=s[3]=='1';s.erase(s.begin(),s.begin()+4);p.seed407450(clean?lc42_cebcd8[old]:s.size());int parts=p.range407480(1,lc42_caf5a0);for(int i=0;i<parts;i++)p.range407480(1,lc42_caf5a0);for(int i=0;i<s.size();i++)s[i]=s[i]+p.range407480(1,lc42_caf4a4);break;}
case 's':case 'M':{int n=lc42_digit405b40(s[2]);int count=s[1]=='M'?n*2:n;s.erase(s.begin(),s.begin()+3);for(int i=0;i<s.size();i++)s[i]=s[i]+count;break;}
case '/':{s.erase(s.begin(),s.begin()+2);lc42_rotate434e50(s);break;}
case 'r':{int count=lc42_digit405b40(s[2]);s.erase(s.begin(),s.begin()+3);lc42_shift4350b0(s,count);break;}
case 'n':case 'N':{int first;int type;int n=lc42_digit405b40(s[2]);int count=s[1]=='N'?n*2:n;s.erase(s.begin(),s.begin()+3);for(int i=0;i<s.size();i++){if(isdigit(s[i])&&s[i]!='9'){first=count;type=lc42_digit405b40(s[i]);while(first>type){first-=type;type=9;}type-=first;s[i]=type+'0';}}break;}
case 'a':case '<':{int n=lc42_digit405b40(s[2]);int count=s[1]=='<'?n/2:n;s.erase(s.begin(),s.begin()+3);for(int i=0;i<s.size();i++)s[i]=*lc42_d21b28.at9cec50(s[i],count);break;}
case 'c':{int first=lc42_digit405b40(s[2]);int count=lc42_digit405b40(s[3]);s.erase(s.begin(),s.begin()+4);for(int i=0;i<s.size();i++)s[i]+=*lc42_d396dc.at9ceda0((i+count)%30,first);break;}
default:goto done;
 }lc42_decode4351e0(s);done:return true;
}
