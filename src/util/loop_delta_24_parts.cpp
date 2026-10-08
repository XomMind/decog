// Private partial CParts update894200 ABI views; borrowed child consoles and vectors.
#include <string>
#include <vector>
using namespace std;
struct P24Point{int x,y;P24Point(int,int)throw();};
struct P24Color{unsigned char r,g,b;P24Color(const P24Color&)throw();};
struct P24Console{char pad[0x60];bool hidden4175f0()throw();bool visible417610()throw();int width44b0d0()throw();int height4174c0()throw();P24Point position417480()throw();float scale417540()throw();void hidden417ba0(bool)throw();void scale417b60(float)throw();void scale417b80(float)throw();void pos4289e0(const P24Point&)throw();void fore417b00(P24Color)throw();void color4183d0(P24Color)throw();void print4181d0(int,int,const string&);void glyph417f50(int,int,int)throw();void remove428b20(P24Console*);void update429e30();void update98ac30();};
struct P24Engine{bool update50fff0();void stop50ff30();};
struct P24Part:P24Console{bool hovered4a9150()throw();};
struct P24Sorted{char pad[0x6c];P24Sorted(P24Part*);};
struct P24Text:P24Console{char tail[0x88-0x60];P24Text(P24Console*,const P24Point&,const string&,int,int,int);};
struct P24Item{int value578f20(vector<P24Point>*,int*)throw();};struct P24HI{int id;P24Item*get9b6540()const throw();};
struct P24Entity{int value5c8c40(int)throw();bool flag5d2a00(int)throw();P24HI item5d2a90(int)throw();};struct P24HE{int id;P24Entity*get9b6570()const throw();};struct P24Map{P24HE player4630f0()throw();void save71d130(bool);};extern P24Map*p24_cefc4c;
struct P24Inventory{void update8a5a40();void update8a5ab0();};extern P24Inventory*p24_cec08c;
struct P24Flash{void add426b60(P24Console*,int);};extern P24Flash p24_d223f0;
extern P24Console*p24_cec0d0,*p24_cec0d4,*p24_cec0d8,*p24_cec0dc,*p24_cec0e4,*p24_cec0e8,*p24_cec0ec,*p24_cec0f0;
extern void*p24_cefc90;extern unsigned p24_caed20;extern int p24_d25568,p24_cebd5c;extern bool p24_cefa74,p24_d28c8a,p24_d28d16;extern string p24_cfcccc;extern P24Color*p24_d2981c;
bool p24_ready778220()throw();void p24_drag7f4560(P24HI);string p24_int4051f0(int);
struct P24Parts:P24Console{int state;P24Engine*engine;char gap68[8];unsigned closeTime;vector<P24Part*>parts;int gap84;P24Console*a,*b,*c;vector<P24Console*>icons;P24Text*info;char gapa8[0xc4-0xa8];int mount,value;bool mini;char gapcd[0xfc-0xcd];unsigned dragTime;P24HI dragged;unsigned sortTime;vector<vector<P24Point> >paths;vector<unsigned>steps,times;bool idle7ad420()throw();P24Part*find894e70(P24HI)throw();void dragReset4a9c60()throw();void mounts897040();void value8970d0();void update894200();};
void P24Parts::update894200(){
 if(hidden4175f0())return;
 switch(state){break;
 case 1:if(!engine->update50fff0())state=3;break;
 case 3:{
  if(idle7ad420()&&p24_ready778220())p24_cefc4c->save71d130(false);
  if(sortTime){
   for(unsigned i=0;i<parts.size();i++){
    float type;
    if(p24_caed20<times[i])type=0;
    else if(p24_caed20>=times[i]+300)type=1;
    else type=(p24_caed20-times[i])/300.0;
    if(steps[i]<paths[i].size()-1){
     int index=(paths[i].size()-1)*type;
     if(index==paths[i].size()-1&&steps[i]!=index)new P24Sorted(parts[i]);
     steps[i]=index;parts[i]->pos4289e0(paths[i][steps[i]]);
    }
   }
   if(p24_caed20-sortTime>=1000)sortTime=0;
  }
  if(dragTime){
   P24Part*record=find894e70(dragged);
   if(!record)dragReset4a9c60();
   else if(!record->hovered4a9150()){if(p24_cefa74)p24_drag7f4560(dragged);dragReset4a9c60();}
   else if(p24_caed20>=dragTime){p24_drag7f4560(dragged);dragReset4a9c60();}
  }
  if(a){if(!p24_d28c8a&&p24_d28d16){a->hidden417ba0(false);b->hidden417ba0(false);c->hidden417ba0(false);}else{a->hidden417ba0(true);b->hidden417ba0(true);c->hidden417ba0(true);}}
  if(c){
   if(p24_d25568){
    string text=" +"+p24_int4051f0(p24_d25568)+" ";
    P24Point a(c->hidden4175f0()?p24_cfcccc.length()+4:c->position417480().x+c->width44b0d0()+1,c->position417480().y);
    if(!info){info=new P24Text(this,a,text,0,0,-1);info->fore417b00(*p24_d2981c);info->color4183d0(*p24_d2981c);p24_d223f0.add426b60(info,5);}
    else{info->print4181d0(0,0,text);info->pos4289e0(a);}
   }else if(info){remove428b20(info);info=0;}
  }
  if(mini){if(p24_d25568){icons[6]->glyph417f50(0,0,'+');if(icons[6]->height4174c0()>1)icons[6]->glyph417f50(0,1,p24_d25568+'0');}else{icons[6]->glyph417f50(0,0,' ');if(icons[6]->height4174c0()>1)icons[6]->glyph417f50(0,1,' ');}}
  p24_cec0d4->hidden417ba0(!(p24_cefc90&&p24_cec0d0->visible417610()));
  p24_cec0d8->hidden417ba0(!p24_cec0d0->visible417610());p24_cec0dc->hidden417ba0(!p24_cec0d0->visible417610());
  p24_cec0e4->hidden417ba0(!(!p24_d28c8a&&p24_cec0d0->visible417610()));
  p24_cec0e8->hidden417ba0(!(p24_cec0d0->visible417610()&&p24_cebd5c==2));p24_cec0ec->hidden417ba0(!(p24_cec0d0->visible417610()&&p24_cebd5c==2));
  p24_cec0f0->update98ac30();
  int p=p24_cefc4c->player4630f0().get9b6570()->value5c8c40(3);
  if(mount!=p){if(mount!=-1){mounts897040();p24_cec08c->update8a5a40();}mount=p;}
  if(p24_cefc4c->player4630f0().get9b6570()->flag5d2a00(201)){
   P24HI a=p24_cefc4c->player4630f0().get9b6570()->item5d2a90(201);int p=a.get9b6540()->value578f20(0,0);
   if(value!=p){if(value!=-1){value8970d0();p24_cec08c->update8a5ab0();}value=p;}
  }else value=-1;
  engine->update50fff0();break;
 }
 case 4:
  engine->update50fff0();
  if(scale417540()!=0.0f){
   if(p24_caed20-closeTime>=500){scale417b60(0);scale417b80(0);}
   else{scale417b60(1.0-(p24_caed20-closeTime)/500.0);scale417b80(1.0-(p24_caed20-closeTime)/500.0);break;}
  }
  engine->stop50ff30();state=0;hidden417ba0(true);parts.clear();
  break;
 }
 update429e30();
}
