#include <string>
#include <vector>
using std::string;using std::vector;
// NOTE: private partial ABI names/layouts, real externally managed owners.
struct D27P{int x,y;};struct D27Rect{int x,y,w,h;D27Rect(const D27Rect&)throw();};struct D27Color{unsigned char r,g,b;};
struct D27Ints{int*first,*last,*end;std::allocator<int>allocator;D27Ints();~D27Ints();unsigned size9b9260()const throw();bool empty9b86e0()const throw();int&operator[](unsigned)throw();int&front9b7060()throw();void push9b9d30(const int&);vector<int>::iterator begin();vector<int>::iterator finish();};
struct D27Art{char owner[0x10];bool empty9b81b0()throw();};struct D27Def{int id,p4;string name;char p24[0x7c-0x24];D27Art art;char p8c[0x94-0x8c];int kind;};
struct D27Defs{unsigned size9b9260()const throw();D27Def*&at9b81f0(unsigned)throw();};extern D27Defs d27_d2d1c4;extern D27Ints d27_d25790;
struct D27Console{
 virtual ~D27Console();virtual void resize7ad4a0(int,int);virtual bool enter4184c0();virtual void leave9c05e0();virtual bool input(void*);virtual void mouse(int,int);virtual void update48c280();virtual void render48c5b0();virtual void open9c05e0();virtual void close();virtual int frame48c350();virtual void trigger48c4e0(const string&,int);
 D27Console(D27Console*,int,int,int,int,int,bool,int);int width44b0d0()throw();D27P pos417480()throw();void hidden417ba0(bool)throw();int wrap418260(int,int,int,int,const string&);void aligned418220(int,int,int,const string&);void animate48c3f0(string);void title7ad4e0(D27Console*);
 char p4[0x60-4];int state;void*engine;D27Console*title;
};
struct D27Text:D27Console{int type;D27Text(D27Console*,int,int,int,int,int);void color4969a0();};
struct D27Title:D27Console{char p[0x20];D27Title(D27Console*,string,int,int);};
struct D27Close{char p[0x8c];D27Close(D27Console*,const D27Color&,int);void hidden417ba0(bool)throw();};
struct D27Piece;struct D27Pieces{D27Piece**first,**last,**end;std::allocator<D27Piece*>allocator;D27Pieces();~D27Pieces();};struct D27Counts;struct D27Percent;struct D27Export;
struct D27Gallery:D27Console{D27Close*button;unsigned time;D27Ints all,claims,owned;D27Pieces pieces;D27Counts*counts;D27Percent*percent;D27Export*exporter;int index;
 D27Gallery();virtual ~D27Gallery();virtual bool input(void*);virtual void mouse(int,int);virtual void close();void rows7e8a50(int,int,D27P*,bool);
};
struct D27Commands:D27Console{void hide7d67c0(D27Console*);};extern D27Commands*d27_cec03c;extern D27Gallery*d27_cec040;
struct D27Rex{int width418980()throw();int height4189a0()throw();};extern D27Rex d27_d223f0;
struct D27Meta{int percent46c700()throw();};extern D27Meta d27_d25628;
struct D27Graph{void push416790(int,int,int,bool);};extern D27Graph*d27_cefa8c;
extern unsigned d27_caed20;extern int d27_bcbc20,d27_bcbdec[];extern D27Color*d27_cf1f2c;
extern int d27_d22270,d27_d22274,d27_d22278,d27_d2227c;
extern D27Rect d27_d39584[];extern D27P d27_d257f0[];extern string d27_d28ccc,d27_d2f184;
struct D27StringCol{string value;char stride[28];};extern D27StringCol d27_d035d8[],d27_d035f4[];
bool d27_mode4328a0()throw();int d27_half437190(int,int)throw();bool unknown7d8c30(int,int);void d27_sort9e2e00(vector<int>::iterator,vector<int>::iterator,bool(*)(int,int));string d27_int4051f0(int);void d27_collection7d89d0(int,const D27P&,D27Counts**,D27Percent**,D27Export**);int d27_sound4541b0(unsigned,int,int);
D27Gallery::D27Gallery():D27Console(d27_cec03c,152,d27_bcbdec[d27_mode4328a0()?1:0],d27_mode4328a0()?d27_half437190(152+d27_bcbc20,d27_d223f0.width418980()):d27_half437190(152,d27_d223f0.width418980()),d27_half437190(d27_bcbdec[d27_mode4328a0()?1:0],d27_d223f0.height4189a0()),0,false,10){
 index=0;d27_cec040=this;title7ad4e0(new D27Title(this,"/ G A L L E R Y   C O L L E C T I O N /",0,4));
 d27_cec03c->hide7d67c0(this);time=d27_caed20;
 for(int i=0;i<d27_d2d1c4.size9b9260();i++)if(!d27_d2d1c4.at9b81f0(i)->art.empty9b81b0()&&d27_d2d1c4.at9b81f0(i)->kind!=2)all.push9b9d30(i);
 d27_sort9e2e00(all.begin(),all.finish(),unknown7d8c30);
 D27Text*record=new D27Text(this,d27_d22270,d27_d22274,d27_d22278,d27_d2227c,0);
 record->wrap418260(0,0,d27_d22278,d27_d2227c,"Alpha Access participants who joined before the deadline each have their own randomly assigned personal item. This console also doubles as an item compendium in which you can view the art for all components you've ever attached while playing, and the total number of unique items attached.");record->color4969a0();
 if(d27_d28ccc!=d27_d2f184)for(int i=0;i<1352;i++)if(d27_d035d8[i].value==d27_d28ccc)claims.push9b9d30(i);
 if(!claims.empty9b86e0())for(int i=0;i<claims.size9b9260();i++)for(int j=0;j<d27_d2d1c4.size9b9260();j++)if(d27_d2d1c4.at9b81f0(j)->name==d27_d035f4[claims[i]].value){owned.push9b9d30(j);break;}
 string p;
 if(!owned.empty9b86e0()){
  int n=0;for(int i=0;i<owned.size9b9260();i++)if(d27_d25790[owned[i]]!=0)n++;
  if(owned.size9b9260()==1){if(d27_d25790[owned.front9b7060()]!=0)p="Thanks "+d27_d28ccc+"! You have discovered your item: "+d27_d2d1c4.at9b81f0(owned.front9b7060())->name;else p="Thanks "+d27_d28ccc+"! You have not yet discovered your item...";}
  else if(n==0)p="Thanks "+d27_d28ccc+"! You have not yet discovered any of your items...";
  else{
   if(n==owned.size9b9260())p="Thanks "+d27_d28ccc+"! You have discovered all your items: ";
   else p="Thanks "+d27_d28ccc+"! You have discovered "+d27_int4051f0(n)+" of your "+d27_int4051f0(owned.size9b9260())+" items: ";
   bool first=true;for(int i=0;i<owned.size9b9260();i++)if(d27_d25790[owned[i]]!=0){if(first)first=false;else p+=", ";p+=d27_d2d1c4.at9b81f0(owned[i])->name;}
  }
 }else p="(Alpha supporters and Sage+ patrons: Set your player name to the one you provided on registration to indicate its discovery status here.)";
 D27Rect a(d27_d39584[d27_mode4328a0()?1:0]);record=new D27Text(this,a.x,a.y,a.w,a.h,1);record->aligned418220(record->width44b0d0()-1,0,2,p);record->color4969a0();
 rows7e8a50(3,0,&d27_d257f0[d27_mode4328a0()?1:0],false);d27_collection7d89d0(d27_d25628.percent46c700(),pos417480(),&counts,&percent,&exporter);
 d27_sound4541b0(49,0,0);animate48c3f0("CGallery_Border");d27_cefa8c->push416790(3,(int)this,-1,false);state=3;
 button=new D27Close(this,*d27_cf1f2c,3);button->hidden417ba0(false);
}
