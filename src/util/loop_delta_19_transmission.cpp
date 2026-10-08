// NOTE: private partial layouts and external aliases for transmission display8f3e50.
#include <string>
#include <vector>
using namespace std;
struct TxPoint{int x,y;TxPoint(int,int)throw();};struct TxColor{unsigned char r,g,b;TxColor(const TxColor&)throw();};
struct TxRecord;struct TxEngine;
struct TxEffect{bool init(TxEngine*,TxRecord*,const TxPoint&,const TxPoint&,const TxPoint*,const TxPoint*,int);};
struct TxEngine{TxEffect*allocate()throw();void stop()throw();};
struct TxConsole{char pad[0x64];TxEngine*engine;int tail;int width()throw();int height()throw();void clear();void clear(int,int,int,int);void print(int,int,const string&);void aligned(int,int,int,const string&);void wrapped(int,int,int,int,const string&);int glyph(int,int)throw();void back(int,int,TxColor,bool);};
struct TxDef{char pad[0x2c];vector<string>lines;};struct TxMemo{int pad;bool read;char gap[7];TxDef*definition;};
struct TxPlayer{bool mode()throw();};extern TxPlayer txPlayer;
extern vector<TxDef*>txDefs;extern vector<TxMemo*>txMemos;extern const TxPoint txZero;extern TxColor*txColor;extern string txFrom,txTo;
void txProcess(string&);void txReplace(string&,string,string);string txMarkers(string&,bool*);bool txLookup(const string&,TxRecord**);
class DeltaTransmission:public TxConsole{public:char gap[0x74-0x6c];int definition;unsigned page;vector<string>extra;int pad8c,mode;TxConsole*background;string speaker();void show();};
#define TX_AT(C,E,P) do{C->engine->allocate()->init(C->engine,E,P,txZero,0,0,9);}while(false)
#define TX_LINE(C,E,P,Q) do{C->engine->allocate()->init(C->engine,E,P,txZero,&Q,&txZero,9);}while(false)
void DeltaTransmission::show(){
 int p,n,index,record;TxRecord*key,*name,*b;
 int i=mode==0||mode==1?1:height()-2;
 clear(1,i==1?2:1,width()-2,height()-3);
 if(i!=1)print(width()/2-1,height()-2,"   ");
 string text=speaker();
 bool type=mode==0||mode==2;
 if(page==0){
  int w,a;TxRecord*count;
  if(type){w=width()-4;a=w-text.size()-1;aligned(w-1,i,2,text);}
  else{a=3;w=a+text.size()+1;print(a+1,i,text);}
  txLookup("CTransmission_Speaker",&count);
  for(int j=a;j<=w;j++){TX_AT(this,count,TxPoint(j,i));}
  txLookup("CTransmission_Line_E",&count);
  if(type){TX_LINE(this,count,TxPoint(width()-3,i),TxPoint(width()-1,i));}
  else{TX_LINE(this,count,TxPoint(2,i),TxPoint(0,i));}
 }
 string a=page>=txDefs[definition]->lines.size()?extra[page-txDefs[definition]->lines.size()]:txDefs[definition]->lines[page];
 txProcess(a);txReplace(a,txFrom,txTo);txMarkers(a,0);
 wrapped(2,2,width()-4,height()-4,a);
 if(page<txDefs[definition]->lines.size()+extra.size()-1)print(width()/2-1,height()-2,"...");
 if(!txPlayer.mode())for(unsigned j=0;j<txMemos.size();j++){if(txMemos[j]->definition==txDefs[definition]){txMemos[j]->read=true;break;}}
 background->clear();background->engine->stop();
 txLookup("CTransmission_Bkg",&b);txLookup("CTransmission_Reveal",&name);txLookup("CTransmission_Text",&key);
 for(int j=i==1?2:1;j<height()-(1+(i!=1));j++){
  int p=-1,n;
  for(int x=1;x<width()-1;x++){
   if(glyph(x,j)==32){TX_AT(background,b,TxPoint(x-1,j-1));}
   else{p=x;break;}
  }
  if(p!=-1){
   for(int x=width()-2;x>=p;x--){
    if(glyph(x,j)==32){TX_AT(background,b,TxPoint(x-1,j-1));}
    else{n=x;break;}
   }
   for(int x=p;x<=n;x++){
    TX_AT(background,name,TxPoint(x-1,j-1));
    if(glyph(x,j)!=32){TX_AT(this,key,TxPoint(x,j));}
   }
  }
 }
 if(type){p=0;record=width()-5-text.size()-1;index=background->width()-1;n=record-1;}
 else{record=0;index=text.size()+3;p=index+1;n=background->width()-1;}
 for(int j=p;j<=n;j++){TX_AT(background,b,TxPoint(j,i-1));}
 for(int j=record;j<=index;j++){
  if(page==0){TX_AT(background,name,TxPoint(j,i-1));}
  else background->back(j,i-1,*txColor,true);
 }
}
