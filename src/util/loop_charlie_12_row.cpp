// NOTE: private partial search-row console, field names inferred.
#include <string>
#include <vector>
using std::string;using std::vector;
struct LC12Event;
struct LC12Color{unsigned char r,g,b;LC12Color()throw();LC12Color(const LC12Color&)throw();bool operator!=(LC12Color)throw();LC12Color operator*(float)throw();};
struct LC12Point{int x,y;LC12Point(const LC12Point&)throw();};
struct LC12Position:LC12Point{int distance;};
struct LC12Record{int glyph;int unknown4;LC12Color color;char pad[5];int item,value,integrity,unknown1c,state;};
struct LC12Grid{LC12Record*at(LC12Point&)throw();};
struct LC12Map{LC12Grid*grid463e70()throw();bool visible4631c0(LC12Point&)throw();};extern LC12Map*lc12_cefc4c;
struct LC12Item{char pad[0x44];int category;string name55eb20(int,int);void description5705b0(string&,LC12Color&)throw();};
extern vector<LC12Item*>lc12_d2d1c4;extern vector<void*>lc12_cf4830;
extern LC12Color*lc12_d386c8,*lc12_cfc174,*lc12_d29758,*lc12_d22fcc,*lc12_d204ac,*lc12_d1dae0,*lc12_d2981c,*lc12_d2175c,*lc12_cf44c0,*lc12_cfe674;
extern bool lc12_d28d30;extern int lc12_d28d68,lc12_bcc2e0,lc12_bcc2e4;extern const float lc12_bcc2e8;
string lc12_int4051f0(int);string&lc12_left408090(string&,unsigned,char);string&lc12_right4080d0(string&,unsigned,char);bool lc12_truncate408220(string&,unsigned,int);int lc12_clamp9cdc80(int,int,int)throw();int lc12_max9cdb60(int,int)throw();LC12Color lc12_color4348a0(int)throw();
struct LC12Console{
 virtual void*release496510(unsigned);virtual void resize7ad4a0(int,int);virtual void enter4aa530();virtual void leave4aff80();virtual bool input8ac880(LC12Event*);virtual void ascii9c1b50(int,int);virtual void update8ac800();virtual void render48c5b0();virtual void slot8_9c05e0();virtual void slot9_9c05e0();virtual int frame48c350();virtual void trigger48c4e0(const string&,int);
 char pad[0x68];LC12Console(LC12Console*,int,int,int,int,int,bool,int);~LC12Console();int width44b0d0()throw();void fore417b00(LC12Color)throw();void put418110(int,int,int,LC12Color)throw();void print4181d0(int,int,const string&);void aligned418220(int,int,int,const string&);void row429a30(int,int,int,LC12Color)throw();
};
struct LC12Row:LC12Console{
 int extra;LC12Point position;int mode;
 virtual void*release496510(unsigned);virtual void enter4aa530();virtual void leave4aff80();virtual bool input8ac880(LC12Event*);virtual void update8ac800();
 LC12Row(LC12Console*,int,LC12Position*,int,int);
};
LC12Row::LC12Row(LC12Console*parent,int y,LC12Position*p,int type,int e):LC12Console(parent,parent->width44b0d0()-4,1,2,y,0,false,-1),extra(e),position(*p),mode(type){
 LC12Record*point=lc12_cefc4c->grid463e70()->at(position);
 if(mode==0){
  fore417b00(lc12_cefc4c->visible4631c0(position)?*lc12_d386c8:p->distance<=20?*lc12_cfc174:p->distance<=50?*lc12_d29758:*lc12_d22fcc);
  string count=p->distance>999?string("***"):lc12_int4051f0(p->distance);
  print4181d0(1,0,lc12_left408090(count,3,' '));
  if(lc12_d28d30){LC12Console*group=new LC12Console(this,1,1,7,0,2,false,-1);group->put418110(0,0,point->glyph,point->color);}else put418110(7,0,point->glyph,point->color);
 }
 string id=lc12_d2d1c4[point->item]->name55eb20(point->value,point->state);
 lc12_truncate408220(id,width44b0d0()-(9+(lc12_d28d30?1:0))-lc12_bcc2e4-3,0);
 lc12_right4080d0(id,width44b0d0()-(9+(lc12_d28d30?1:0))-lc12_bcc2e4-3,' ');
 if(mode==0)fore417b00(lc12_cf4830[point->item]&&(point->state==2||point->state==3)?*lc12_d204ac:point->state==5?*lc12_d1dae0:*lc12_d2981c);else fore417b00(*lc12_d2175c);
 print4181d0(9+(lc12_d28d30?1:0),0,id);
 if(mode==0&&lc12_d2d1c4[point->item]->category>=6){
  if(lc12_d28d68==3){string text;LC12Color color;
   if(!lc12_cf4830[point->item])text="???";else lc12_d2d1c4[point->item]->description5705b0(text,color);
   if(!text.empty()){fore417b00(*lc12_cf44c0);aligned418220(width44b0d0()-1,0,2,text);if(color!=*lc12_cfe674)row429a30(width44b0d0()-2,0,2,color);}
  }else{
   int h=lc12_clamp9cdc80(1,point->integrity,100);
   if(h>0){int distance=lc12_max9cdb60(1,int(h/100.0*lc12_bcc2e4));int base=40;int choices=lc12_bcc2e0-lc12_bcc2e4;
    if(lc12_cf4830[point->item])for(int i=base+lc12_bcc2e0-1-choices;distance>0;i--,distance--)put418110(i,0,'|',lc12_color4348a0(point->integrity)*lc12_bcc2e8);
    string source=!lc12_cf4830[point->item]?string(" ???"):point->value>9999?string("****"):string(lc12_left408090(lc12_int4051f0(point->value),4,' '));
    fore417b00(lc12_color4348a0(point->integrity)*lc12_bcc2e8);print4181d0(base+lc12_bcc2e0-choices,0,source);
   }
  }
 }
}
