#include <string>
#include <memory>
#include "rng.h"
using std::string;extern RNG rng;
// NOTE: private partial retail views. All real owner/render operations remain external.
struct D33P{int x,y;D33P()throw();D33P(int,int)throw();D33P(const D33P&)throw();D33P&assign46ca50(const D33P&)throw();D33P add409b60(const D33P&)throw();bool contains40c190(int)throw();};
struct D33Bounds{int x1,y1,x2,y2;D33Bounds()throw();};
struct D33RGB{unsigned char r,g,b;D33RGB(const D33RGB&)throw();};
struct D33Pixel{int font,glyph,mappedGlyph;D33RGB fore,back;D33Pixel(int,int,D33RGB,D33RGB);};
struct D33Points{D33P*first,*last,*capacity;std::allocator<D33P>allocator;D33Points()throw();~D33Points();void clear9b3560();bool empty9b86e0()const throw();unsigned size9b9a50()const throw();D33P&at9e7c10(unsigned)throw();void push9b32e0(const D33P&);};
struct D33IntGrid{int width,height;int*data;D33IntGrid();~D33IntGrid();int*at9ced70(D33P&)throw();};
struct D33PixelGrid{int width,height;D33Pixel*data;void bounds9b4430(const D33P&,int,D33Bounds&)throw();};
struct D33Prop{int flag44ab40()throw();};struct D33HP{int id;bool valid9b7230()const throw();D33Prop*get9b64f0()const throw();};
struct D33Cell{D33HP prop45d550()throw();D33RGB color66a680();int glyph66a830();unsigned char occupied4550b0()throw();};
struct D33MapGrid{D33Cell**at9ceda0(int,int)throw();D33Cell**point9ced70(D33P&)throw();};extern D33MapGrid d33_cfd44c;
struct D33Entity{D33P&position45a4a0()throw();};struct D33HE{int id;D33Entity*get9b6570()const throw();};
struct D33Map{D33HE player4630f0()throw();void mark7243c0(int,int,bool);};extern D33Map*d33_cefc4c;
struct D33Def;struct D33Root;struct D33Rect;
struct D33Engine{bool update50fff0();bool busy454d30()throw();};
struct D33Console{virtual~D33Console();virtual void resize(int,int);virtual bool mouseEnter();virtual void mouseLeave();virtual bool input(void*);virtual void inputAscii(int,int);virtual void update();virtual void render();virtual void open();virtual void close();char p4[0x5c];int state;D33Engine*engine;void*title;bool hidden4175f0()throw();int width44b0d0()throw();int height4174c0()throw();D33PixelGrid*buffer4184d0()throw();D33Root*parent9b8f00()throw();void effect48c460(D33Def*,const D33P&);void cell4181a0(int,int,const D33Pixel&);void position417a90(int,int);void copy429fe0(D33Console*,D33P&,const D33Rect*);bool bounds4173d0(const D33P&)throw();void remove428b20(D33Console*);void base429e30();};
struct D33Fx:D33Console{int type;void update95fab0();};
struct D33Root{char p0[0xf8];int imprint;unsigned imprintTick;char p100[0x16c-0x100];unsigned wait;int radius,limit;unsigned radiusTick;char p17c[0x18c-0x17c];D33Console*copy;D33Points cells;D33IntGrid visited;unsigned shakeTick,waveTick,endTick;void done969970(D33Console*);void done4b31e0(D33Console*);void done4b3210();void finish96b930();void finish96b9d0();void remove428b20(D33Console*);};
struct D33View:D33Console{D33P&offset458ef0()throw();void range8051f0(D33P&,D33P&);};extern D33View*d33_cec054;extern D33Root*d33_cec138;
extern unsigned d33_caed20;extern bool d33_d28d15;extern int d33_cf27ec,d33_cf27f0,d33_cf27f4,d33_cf27f8;extern D33RGB d33_d29804;
extern const char d33_c10f8c[],d33_c10fa0[],d33_c10fb4[],d33_c10fcc[],d33_c10fe4[],d33_c10ffc[];
bool d33_lookup9d45a0(const string&,D33Def**);string d33_ending490080();int d33_distance406480(int,int,int,int);int d33_max9cdb60(int,int)throw();void d33_adjacent4fab80(const D33P&,D33Points&);void d33_erase9d53f0(D33Points&,int,int);
static_assert(sizeof(D33Console)==108&&sizeof(D33Fx)==112&&sizeof(D33Pixel)==20&&sizeof(D33Points)==16,"actual native extents");
void D33Fx::update95fab0(){
 if(hidden4175f0())return;
 switch(state){break;
 case 1:state=3;break;
 case 3:
  engine->update50fff0();
  switch(type){
  case 16:{D33Root*root=parent9b8f00();
   if(root->imprint<16){D33P center(width44b0d0()/2,height4174c0()/2);D33Def*effect;
    if(root->imprint==-1){root->imprint=0;root->imprintTick=d33_caed20;if(d33_lookup9d45a0(d33_c10f8c,&effect))effect48c460(effect,center);}
    else if(d33_caed20-root->imprintTick>=60&&d33_lookup9d45a0(d33_c10fa0,&effect)){
     D33P ring(root->imprint+1,root->imprint);do{root->imprintTick+=60;ring.y++;}while(d33_caed20-root->imprintTick>=60);
     D33Bounds local;buffer4184d0()->bounds9b4430(center,12,local);D33Bounds world;buffer4184d0()->bounds9b4430(d33_cefc4c->player4630f0().get9b6570()->position45a4a0(),12,world);
     for(int x=local.x1,x2=world.x1;x<=local.x2;x++,x2++)for(int col=local.y1,y2=world.y1;col<=local.y2;col++,y2++)if((*d33_cfd44c.at9ceda0(x2,y2))->prop45d550().valid9b7230()&&(*d33_cfd44c.at9ceda0(x2,y2))->prop45d550().get9b64f0()->flag44ab40()!=-1&&ring.contains40c190(d33_distance406480(center.x,center.y,x,col))){cell4181a0(x,col,D33Pixel(d33_d28d15?3:2,(*d33_cfd44c.at9ceda0(x2,y2))->glyph66a830(),(*d33_cfd44c.at9ceda0(x2,y2))->color66a680(),d33_d29804));d33_cefc4c->mark7243c0(x2,y2,true);effect48c460(effect,D33P(x,col));}
     root->imprint=ring.y;
    }
   }break;}
  case 19:if(!engine->busy454d30()){d33_cec138->done969970(this);d33_cec138->done4b31e0(this);close();}break;
  case 20:if(!engine->busy454d30()){d33_cec138->done4b31e0(this);close();}break;
  case 23:if(!engine->busy454d30()){d33_cec138->done4b3210();close();}break;
  case 25:{D33Root*root=parent9b8f00();
   if(root->radius!=-4&&root->radius!=-1){
    if(root->radius==-3&&!engine->busy454d30()){root->radius=-2;root->wait=d33_caed20+2000;}
    if(root->radius!=-3&&root->radius<root->limit){D33P center(width44b0d0()/2,height4174c0()/2);string name=d33_ending490080();D33Def*active;
     if(root->radius==-2){root->radius=0;root->radiusTick=d33_caed20;if(d33_lookup9d45a0(d33_c10fb4+name,&active))effect48c460(active,center);}
     else if(d33_caed20-root->radiusTick>=10&&d33_lookup9d45a0(d33_c10fcc+name,&active)){
      D33P ring(root->radius+1,root->radius);do{root->radiusTick+=10;ring.y++;}while(d33_caed20-root->radiusTick>=10);
      D33P delta(d33_cec054->offset458ef0());D33P begin;D33P end;d33_cec054->range8051f0(begin,end);
      for(int col=begin.x,x2=d33_max9cdb60(delta.x,0);col<=end.x&&x2<d33_cf27f4;col++,x2++)for(int sy=begin.y,y2=d33_max9cdb60(delta.y,0);sy<=end.y&&y2<d33_cf27f8;sy++,y2++)if(ring.contains40c190(d33_distance406480(center.x,center.y,x2,y2)))effect48c460(active,D33P(x2,y2));
      root->radius=ring.y;
     }
    }
   }break;}
  case 27:if(!engine->busy454d30()){parent9b8f00()->finish96b930();return;}break;
  case 28:{unsigned count=parent9b8f00()->endTick;unsigned*point=&parent9b8f00()->shakeTick;
   if(d33_caed20>=count){parent9b8f00()->finish96b9d0();return;}
   if(d33_caed20>=*point){int dx,dy;do{dx=rng.rangeInt(-1,1);dy=rng.rangeInt(-1,1);}while(dx==0&&dy==0);position417a90(d33_cf27ec+dx,d33_cf27f0+dy);parent9b8f00()->copy->position417a90(d33_cf27ec+dx,d33_cf27f0+dy);*point=d33_caed20+(count-d33_caed20<1000)?60:count-d33_caed20<2000?125:250;}
   d33_cec054->copy429fe0(this,D33P(0,0),0);int time=count-d33_caed20<1000?20:count-d33_caed20<2000?40:80;unsigned*x2=&parent9b8f00()->waveTick;
   if(!*x2||d33_caed20>=*x2+time){D33Points*cells=&parent9b8f00()->cells;
    if(!cells->empty9b86e0()){D33IntGrid*last=&parent9b8f00()->visited;D33Def*node;d33_lookup9d45a0(d33_c10fe4,&node);D33Def*flags;d33_lookup9d45a0(d33_c10ffc,&flags);D33P delta(d33_cec054->offset458ef0());D33P base;D33Points vec;
     do{int count=cells->size9b9a50();for(int i=0;i<count;i++){base.assign46ca50(cells->at9e7c10(i).add409b60(delta));if(bounds4173d0(base))effect48c460((*d33_cfd44c.point9ced70(cells->at9e7c10(i)))->occupied4550b0()?node:flags,base);vec.clear9b3560();d33_adjacent4fab80(cells->at9e7c10(i),vec);for(int j=0;j<vec.size9b9a50();j++)if(!*last->at9ced70(vec.at9e7c10(j))){cells->push9b32e0(vec.at9e7c10(j));*last->at9ced70(vec.at9e7c10(j))=1;}}
      d33_erase9d53f0(*cells,0,count-1);if(!*x2)*x2=d33_caed20;else *x2+=time;
     }while(d33_caed20>=*x2+time&&!cells->empty9b86e0());
    }
   }break;}
  }
  break;
 case 4:d33_cec138->remove428b20(this);return;
 }
 base429e30();
}
