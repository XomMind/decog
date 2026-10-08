#include <string>
#include <vector>
#include <cstdlib>
#include <cstddef>
using std::string;using std::vector;
// NOTE: private borrowed partial Item/definition views, actual string and vector output owners.
struct LB31Color{unsigned char r,g,b;LB31Color()throw();LB31Color(const LB31Color&)throw();LB31Color&operator=(LB31Color)throw();};
struct LB31Item;struct LB31Entity;struct LB31HI{int id;LB31HI()throw();bool valid9b7230()const throw();};struct LB31H{int id;bool valid9b7230()const throw();LB31Entity*get9b6570()const throw();};
struct LB31Damage{char omitted[0x2c];int kind,damage,variance;};
struct LB31Def{int id;char omitted04[0x40];int type,category;char omitted4c[4];int rating;char omitted54[0x40];int class94;char omitted98[0xc];int mass;char omitteda8[0x48];int effect,effectValue,effectAux;char omittedfc[0x1c];int projectiles;char omitted11c[4];int minDamage,maxDamage,damageType;char omitted12c[0x39];bool flag165;char omitted166[0x3a];LB31Damage*damage;char omitted1a4[0xc];bool flag1b0;};
struct LB31Entity{LB31HI item5d2380(int);bool player5c7600()throw();float scale5d7bc0();float scale5d7bf0(int);int value5d22a0(int);int value5d2150(int,int);int value5d2090(int);};
struct LB31Item{char omitted[8];LB31Def*def;int unknown0c;LB31H owner;bool active458220();int energy577bd0();int time577c90();int speed577e60();float ratio579090();void describe5759b0(string&,vector<LB31Color>&);};
extern vector<int>lb31_cf4844;extern string gameStrings_d22280[],gameStrings_d33e38[],gameStrings_d3a380[],gameStrings_d323f8[];extern LB31Color*lb31_cf44c0,*lb31_d316f8;extern LB31Color lb31_d2ed1c[];extern int lb31_cf462c,lb31_cf49c4,lb31_cf49bc[];
extern const float lb31_c37098,lb31_c3709c;
string lb31_int4051f0(int);int lb31_max9cdb60(int,int)throw();bool lb31_near9d85c0(float,float,float)throw();bool lb31_between9daf80(int,int,int)throw();void lb31_clamp9d06d0(int*,int,int)throw();
static_assert(sizeof(LB31Color)==3,"native RGB ABI");
static_assert(sizeof(LB31HI)==4&&sizeof(LB31H)==4,"pooled handle ABI");
static_assert(offsetof(LB31Def,effect)==0xf0&&offsetof(LB31Def,damage)==0x1a0&&offsetof(LB31Def,flag165)==0x165&&offsetof(LB31Def,flag1b0)==0x1b0,"borrowed definition fields");
void LB31Item::describe5759b0(string&text,vector<LB31Color>&colors){
 if(lb31_cf4844[def->id]!=0)text+="+";
 if(def->class94!=0)text+=gameStrings_d22280[def->class94];
 switch(def->class94){case 0:case 1:text+=(def->rating==10?string("X"):lb31_int4051f0(def->rating));break;case 2:text+="?";break;}
 switch(def->category){
 case 0:
  text+=" M";text+=lb31_int4051f0(def->mass);text+=" E";colors.assign(text.size(),*lb31_cf44c0);text+=lb31_int4051f0(energy577bd0());
  while(colors.size()<text.size())colors.push_back(owner.valid9b7230()&&active458220()?*lb31_d316f8:*lb31_cf44c0);break;
 case 1:
  text+=" T";colors.assign(text.size(),*lb31_cf44c0);text+=lb31_int4051f0(time577c90());
  while(colors.size()<text.size())colors.push_back(owner.valid9b7230()&&active458220()&&def->type==10?*lb31_d316f8:*lb31_cf44c0);
  text+=" S";colors.push_back(*lb31_cf44c0);colors.push_back(*lb31_cf44c0);text+=lb31_int4051f0(speed577e60());
  while(colors.size()<text.size())colors.push_back(owner.valid9b7230()&&active458220()&&def->type!=10?*lb31_d316f8:*lb31_cf44c0);break;
 case 2:{
  text+=" M";text+=lb31_int4051f0(def->mass);colors.assign(text.size(),*lb31_cf44c0);
  string title;LB31Color item(*lb31_cf44c0);
  switch(def->effect){
  case 0:break;
  case 1:if(def->effectAux&&owner.valid9b7230()&&owner.get9b6570()->item5d2380(6).valid9b7230()){title=lb31_int4051f0(def->effectValue*2);item=*lb31_d316f8;}else goto utilityFallback;
  case 46:break;
  case 19:title=lb31_int4051f0(def->effectValue+1);break;
  case 152:title=gameStrings_d33e38[def->effectValue];break;
  case 127:title=lb31_int4051f0(abs(def->effectValue));if(def->effectValue<0)title+="!";break;
  default:utilityFallback:title=lb31_int4051f0(def->effectValue);break;
  }
  if(!title.empty()){
   text+=" "+gameStrings_d3a380[def->effect]+"/";
   while(colors.size()<text.size())colors.push_back(*lb31_cf44c0);
   text+=title;while(colors.size()<text.size())colors.push_back(item);
  }break;}
 case 3:{
  text+=" M";text+=lb31_int4051f0(def->mass);colors.assign(text.size(),*lb31_cf44c0);
  LB31Color item,terrain;
  if(def->damage){
   bool flag=false;float multiplier=1.0f;
   if(owner.valid9b7230()){
    if(def->effect==201){multiplier=ratio579090();flag=true;}
    else if(lb31_cf462c==5&&owner.get9b6570()->player5c7600()&&def->damage->kind==2&&lb31_cf49c4!=0){multiplier+=lb31_cf49c4/100.0;flag=true;}
   }
   int count=lb31_max9cdb60(0,(int)(def->damage->damage*multiplier-def->damage->variance));
   int first=lb31_max9cdb60(0,(int)(def->damage->damage*multiplier+def->damage->variance));
   text+=" "+(count!=first?lb31_int4051f0(count)+"-"+lb31_int4051f0(first):lb31_int4051f0(first));
   item=flag?*lb31_d316f8:*lb31_cf44c0;terrain=lb31_d2ed1c[def->damage->kind];
  }else{
   bool flag=false;float multiplier=1.0f;
   if(owner.valid9b7230()){
    if(active458220()){multiplier=owner.get9b6570()->scale5d7bc0();flag=true;}
    else if(def->type>=26){multiplier=owner.get9b6570()->scale5d7bf0(def->damageType);flag=!lb31_near9d85c0(lb31_c37098,multiplier,lb31_c3709c);}
   }
   int count=(int)(def->minDamage*multiplier);int first=(int)(def->maxDamage*multiplier);
   if(owner.valid9b7230()){
    if(def->flag1b0&&!def->flag165&&owner.get9b6570()->value5d22a0(102)){
     int bonus=owner.get9b6570()->value5d22a0(102);if(bonus!=0){count+=count*bonus/100;first+=first*bonus/100;flag=true;}
    }else if(def->type==20||def->type==21){
     if(!def->flag165){int bonus=owner.get9b6570()->value5d2150(103,0);if(bonus!=0){count+=count*bonus/100;first+=first*bonus/100;flag=true;}}
    }else if(def->type==22||def->type==23){
     int bonus=owner.get9b6570()->value5d22a0(105);if(bonus!=0){count+=count*bonus/100;if(count>first)first=count;flag=true;}
    }else if(lb31_between9daf80(26,def->type,28)){
     int bonus=owner.get9b6570()->value5d2150(106,0);if(bonus!=0){first+=first*bonus/100;flag=true;}
     int old=owner.get9b6570()->value5d2090(90);if(old!=0){lb31_clamp9d06d0(&count,old/2,first);flag=true;}
    }
    if(lb31_cf462c==5&&owner.get9b6570()->player5c7600()&&def->damageType<7&&lb31_cf49bc[def->damageType]!=0){int bonus=lb31_cf49bc[def->damageType];count+=count*bonus/100;first+=first*bonus/100;flag=true;}
   }
   text+=" "+(count!=first?lb31_int4051f0(count)+"-"+lb31_int4051f0(first):lb31_int4051f0(first));
   item=flag?*lb31_d316f8:*lb31_cf44c0;terrain=lb31_d2ed1c[def->damageType];
  }
  while(colors.size()<text.size())colors.push_back(text[colors.size()]=='-'?*lb31_cf44c0:item);
  if(def->projectiles>1)text+="*";else text+=" ";colors.push_back(*lb31_cf44c0);
  string name=gameStrings_d323f8[def->damage?def->damage->kind:def->damageType];
  if(name.size()==1)name.insert(0,1,' ');text+=name;while(colors.size()<text.size())colors.push_back(terrain);
  break;}
 }
}
