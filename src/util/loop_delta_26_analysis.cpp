#include <string>
#include <vector>
using std::string;using std::vector;
// Private partial ABI views; names and omitted fields are placeholders.
// Actual owning string collection: 16B proxy/begin/end/capacity, const-reference insertion.
struct D26Strings{void*proxy;string*begin,*end,*capacity;D26Strings();~D26Strings();unsigned size9b0650()const throw();string&operator[](unsigned)throw();void push9b06f0(const string&);void push9b0340(string&&);};
struct D26P{int x,y;D26P();D26P(int,int)throw();};
struct D26Rect{D26P pos;int width,height;};
struct D26Def{char p0[0x170];string description;};
struct D26Effect{char p0[0x284];int kind;string description;void describe55f080(string&);};
struct D26Item{D26Effect*record9b4350()throw();};
struct D26Entity{D26Def*record9b4350()throw();string describe5cd670();int resistance5cb570(int,int)throw();unsigned immune5cd490(vector<int>*);};
struct D26H{int id;D26Entity*get9b6570()const throw();};struct D26HI{int id;D26Item*get9b65b0()const throw();};
struct D26Console{char p0[0x6c];D26Console(D26Console*,int,int,int,int,int,bool,int);int width44b0d0()throw();int height4174c0()throw();bool hidden4175f0()throw();D26P pos417480()throw();D26P max4174e0()throw();int wrapped418260(int,int,int,int,const string&);string line4177a0(const D26P&,unsigned);void remove428b20(D26Console*);};
struct D26Info:D26Console{const D26P&anchor4aec60()throw();const D26P&anchor4aec80()throw();int more4aeca0()throw();};
struct D26Hud:D26Console{int bottom4a2560()throw();};
struct D26Analysis{char p0[0x74];D26Analysis(D26Console*,const D26Rect&,int,const D26Strings&);};
struct D26Player{int count46e150()throw();string describe781a10();};struct D26Rex{int width418980()throw();};
extern D26Player d26_cf45d8;extern D26Rex d26_d223f0;
extern D26Console*d26_cec034;extern D26Info*d26_cec11c,*d26_cec118,*d26_cec120,*d26_cec124;extern D26Hud*d26_cec074;
extern int d26_d31698,d26_cf0db4,d26_cf0db0;extern float d26_b9636c;
extern string d26_d29980[],d26_d2a5a8[];
string d26_int4051f0(int);void d26_log404f10(string,string);void d26_pad4080d0(string&,unsigned,char);
void d26_analysis8b1da0(D26H entity,D26HI item,int type){
 D26Strings result;
 int width;D26Console*console;
 if(type==4){width=(int)(d26_cf45d8.count46e150()>=8?d26_d223f0.width418980():d26_d31698*1.5);console=new D26Console(d26_cec034,width-5,d26_cf0db4*2,0,0,0,true,-1);}
 else if(type==3){width=30;console=new D26Console(d26_cec11c,width-5,d26_cf0db4,0,0,0,true,-1);}
 else{width=d26_cf0db0;console=new D26Console(d26_cec11c,width-5,d26_cf0db4,0,0,0,true,-1);}
 string text;
 switch(type){
 case 0:text=entity.get9b6570()->record9b4350()->description;break;
 case 1:text=entity.get9b6570()->describe5cd670();break;
 case 2:if(item.get9b65b0()->record9b4350()->kind==1)item.get9b65b0()->record9b4350()->describe55f080(text);else text=item.get9b65b0()->record9b4350()->description;break;
 case 3:{
 unsigned count=(!d26_cec11c->hidden4175f0()?d26_cec11c:d26_cec118)->more4aeca0();
 D26Strings first;D26Strings b;
 for(int i=0;i<7;i++){
  int value=100-entity.get9b6570()->resistance5cb570(i,0);
  if(value){string text=(value>=0?d26_int4051f0(value):"-"+d26_int4051f0(-value))+"%";b.push9b06f0(text);first.push9b06f0(d26_d29980[i]);}
 }
 if(!d26_cec11c->hidden4175f0()){
  vector<int> immune;
  if(entity.get9b6570()->immune5cd490(&immune))for(unsigned i=0;i<immune.size();i++){b.push9b06f0("IMMUNE");first.push9b06f0(d26_d2a5a8[immune[i]]);}
 }
 if(count>first.size9b0650())d26_log404f10("showRobotAnalysis()","moreResistancesCount error");
 for(unsigned i=first.size9b0650()-count,j=0;i<first.size9b0650();i++,j++){
  if(j)text+="\n";
  d26_pad4080d0(first[i],16+(b[i][0]!='-'),32);text+=first[i];text+=b[i];
 }
 break;}
 case 4:text=d26_cf45d8.describe781a10();break;
 }
 int p=console->wrapped418260(0,0,console->width44b0d0(),console->height4174c0(),text);
 for(int i=0;i<p;i++)result.push9b0340(console->line4177a0(D26P(0,i),console->width44b0d0()));
 if(type==0)result.push9b0340(" <weaknesses identified: +"+d26_int4051f0((int)(d26_b9636c*100.0))+"% hit, +"+d26_int4051f0(10)+"% dmg>");
 if(type==4)d26_cec034->remove428b20(console);else d26_cec11c->remove428b20(console);
 D26Rect rect;rect.width=width;rect.height=result.size9b0650()+4;
 if(type==4){rect.pos.x=d26_cec074->pos417480().x+d26_cec074->width44b0d0()-rect.width;rect.pos.y=d26_cec074->bottom4a2560();new D26Analysis(d26_cec034,rect,type,result);}
 else{
  D26Info*parent=type==3?(!d26_cec11c->hidden4175f0()?d26_cec11c:d26_cec118):(d26_cec124?d26_cec124:!d26_cec120->hidden4175f0()?d26_cec120:d26_cec11c);
  rect.pos.x=0;int y=type==3?parent->anchor4aec80().y:parent->anchor4aec60().y;
  if(y+rect.height-1>parent->max4174e0().y)y-=y+rect.height-1-parent->max4174e0().y;
  rect.pos.y=y;new D26Analysis(parent,rect,type,result);
 }
}
