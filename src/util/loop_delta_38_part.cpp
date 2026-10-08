#include <string>
#include <vector>
#include <memory>
#include <cstddef>
// NOTE: private names; complete allocated console owners, borrowed gameplay prefixes.
struct D38Point{int x,y;D38Point()throw();D38Point(int)throw();D38Point(const D38Point&)throw();};
struct D38Color{unsigned char r,g,b;D38Color(const D38Color&)throw();D38Color operator*(float);};
struct D38Item;struct D38Entity;struct D38Con;struct D38Engine;struct D38Title;struct D38Event;
struct D38HI{int id;D38HI()throw();D38Item*get9b65b0()const throw();bool valid9b7230()const throw();bool null9b65d0()const throw();bool equal9b78e0(D38HI)const throw();};
struct D38HE{int id;D38Entity*get9b6570()const throw();bool valid9b7230()const throw();bool null9b65d0()const throw();};
template<class T>struct D38Slots{T*first,*last,*end;std::allocator<T>allocator;D38Slots();~D38Slots();unsigned size9b9260()const throw();};
struct D38ConsoleCell{int font,glyph,value;D38Color fg,bg;};struct D38Buffer{int width,height;D38ConsoleCell*data;D38Buffer();~D38Buffer();};
struct D38Con{
 virtual ~D38Con();virtual void resize(int,int);virtual bool isActive();virtual void refresh();virtual bool input(D38Event*);virtual void mouseMoved(int,int);virtual void update();virtual void render();virtual void open();virtual void close();virtual int getFrame();virtual void trigger(const std::string&,int);
 D38Con*parent;D38Buffer buffer;int font,fontData;D38Point position,absolute;D38Color fg,bg;int backFlag,alignment;float scaleX,scaleY;D38Slots<D38Con*>children;bool hidden;int layer;bool passthrough,ignoreMouse;int state;D38Engine*engine;D38Title*title;
 bool hidden4175f0()throw();D38Point pos417480()throw();void pos417a90(int,int);void base429e30();void remove428b20(D38Con*);void back417fc0(int,int,D38Color,int);
};
struct D38Hit:D38Con{D38Slots<D38Con*>factors;D38Hit(D38Con*);~D38Hit();void refresh88e410(D38HI);};
struct D38Engine{bool update50fff0();};struct D38Effects;
struct D38Def{char omitted00[0xec];int durationType;char omittedf0[0x165-0xf0];bool blocked;};
struct D38Item{
 bool test457d30();D38Effects*effect457b70(int);int timer44ab90()throw();bool test457d50();bool test578d90(D38HI);bool test457cf0();D38Def*def9b4350()throw();int value577fb0();bool test458220();int type457f90()throw();int value4580c0();int value458240()throw();int matter457880()throw();int value577a90();int value457fb0()throw();int rating457ca0()throw();int value577ad0();int value458260()throw();int value578e90(bool);int value4582a0()throw();int value578f20(std::vector<D38Point>*,int*);int effectValue457be0(int);int value577fd0();int value578070();int value45cb30()throw();int subtype4578a0()throw();D38Color*color577260();
};
struct D38Entity{int effect5d22a0(int);bool test5d7560(D38HI);D38HI item5d5d40();const D38Point&pos45a4a0()throw();};
struct D38World{D38HE player4630f0()throw();int turn464270()throw();bool flag463280()throw();bool flag4632a0()throw();bool flag4632c0()throw();bool flag463260()throw();bool find74d420(const D38Point&,D38Point&);D38Slots<D38HE>*records463d80()throw();int value4644d0()throw();int value464290()throw();bool visible4631f0(D38HE);};extern D38World*d38_cefc4c;
struct D38Map{bool aim49aa20()throw();bool point805190(D38Point&);int value8054b0(bool);};extern D38Map*d38_cec054;
struct D38Parts{bool test4a9af0()throw();};extern D38Parts*d38_cec088;
struct D38Inventory{char omitted00[0x8c];D38HI item;};extern D38Inventory*d38_cec078;
struct D38Game{bool test46f4b0(int)throw();};extern D38Game d38_d1e860;
struct D38Cell{D38HE entity45d250()throw();};struct D38Cells{int width,height;D38Cell**data;D38Cells();~D38Cells();D38Cell**at9ced70(const D38Point&)throw();};extern D38Cells d38_cfd44c;
struct D38Hud:D38Con{int type,value;void set4a6630(int);void set4a6240(int);void set4a6940(int);void set4a6360(int);void set4a6d20(int);void set4a7150(int);void set4a6a30(int);void set4a7700(int);void set4a79f0(int);void set4a7e00(int);int mode4a6cb0();int item4a7db0(D38HI);};
extern bool d38_d28d16,d38_d25450,d38_d28e57;extern int d38_d255fc,d38_d25464;extern D38Color*d38_cfe674;extern const float d38_c36eb4;
int d38_sound4541b0(unsigned,int,int);
struct D38Part:D38Con{D38HI item;bool blank;D38HI other;bool flagged;int unknown7c,key,stamp;bool unknown88;int unknown8c;D38Hud*label;D38Con*bar;D38Hit*chance;int unknown9c;D38Con*confirming;D38Hud*create890bb0(int);void update88ee60();};
static_assert(sizeof(D38Con)==108&&sizeof(D38Hit)==124,"retail allocated owner extents");
void D38Part::update88ee60(){
 if(hidden4175f0())return;
 engine->update50fff0();base429e30();
 if(!d38_cec088->test4a9af0()&&pos417480().x!=2)pos417a90(2,pos417480().y);
 if(item.null9b65d0()||blank)return;
 int type=42;
 if(!item.get9b65b0()->test457d30()){
  if(item.get9b65b0()->effect457b70(82))type=0;
  else if(item.get9b65b0()->timer44ab90()>d38_cefc4c->turn464270())type=1;
  else if(item.get9b65b0()->test457d50())type=2;
  else if(d38_d28d16&&item.get9b65b0()->test578d90(D38HI()))type=10;
  else if(item.get9b65b0()->effect457b70(118))type=25;
  else if(item.get9b65b0()->test457cf0()){
   if(item.get9b65b0()->def9b4350()->durationType&&item.get9b65b0()->value577fb0()){
    int amount=item.get9b65b0()->value577fb0();
    switch(item.get9b65b0()->def9b4350()->durationType){case 1:case 2:type=amount+26;break;case 3:type=amount+29;break;case 4:type=amount+32;break;}
   }else if(item.get9b65b0()->test458220()){
    if(item.get9b65b0()->type457f90()==160||item.get9b65b0()->type457f90()==211)type=36;
    else if(item.get9b65b0()->type457f90()==166)type=37;else type=3;
   }else if(item.get9b65b0()->value4580c0()>=1)type=4;
   else if(item.get9b65b0()->value458240())type=5;
   else if((item.get9b65b0()->matter457880()==20||item.get9b65b0()->matter457880()==21)&&d38_cefc4c->player4630f0().get9b6570()->effect5d22a0(78)&&d38_cefc4c->player4630f0().get9b6570()->test5d7560(item)&&!item.get9b65b0()->def9b4350()->blocked)type=6;
   else if(item.get9b65b0()->matter457880()==24&&d38_cefc4c->player4630f0().get9b6570()->effect5d22a0(79)&&d38_cefc4c->player4630f0().get9b6570()->test5d7560(item))type=7;
   else if(item.get9b65b0()->type457f90()==199)type=8;
   else if(item.equal9b78e0(d38_cefc4c->player4630f0().get9b6570()->item5d5d40()))type=9;
   else if(flagged)type=11;
   else if(d38_d25450&&d38_d255fc&&(item.get9b65b0()->type457f90()==11||item.get9b65b0()->type457f90()==13||item.get9b65b0()->type457f90()==14||item.get9b65b0()->type457f90()==18))type=14;
   else if((item.get9b65b0()->type457f90()==11&&d38_cefc4c->flag463280())||(item.get9b65b0()->type457f90()==14&&d38_cefc4c->flag4632a0())||((item.get9b65b0()->type457f90()==16||item.get9b65b0()->type457f90()==24)&&d38_cefc4c->flag4632c0()))type=13;
   else if(item.get9b65b0()->type457f90()==11&&d38_cefc4c->flag463260())type=12;
   else if(item.get9b65b0()->type457f90()==169||item.get9b65b0()->type457f90()==168||item.get9b65b0()->type457f90()==171)type=15;
   else if(item.get9b65b0()->type457f90()==172){if(item.get9b65b0()->value577a90()==item.get9b65b0()->value457fb0()-1&&!d38_cefc4c->find74d420(d38_cefc4c->player4630f0().get9b6570()->pos45a4a0(),D38Point(0)))type=40;else type=15;}
   else if(item.get9b65b0()->type457f90()==170)type=16;
   else if(item.get9b65b0()->type457f90()==173)type=17;
   else if(item.get9b65b0()->type457f90()==28&&d38_cec054->value8054b0(true))type=18;
   else if(item.get9b65b0()->type457f90()==29&&d38_d1e860.test46f4b0(1))type=19;
   else if(item.get9b65b0()->type457f90()==185){type=20;if(label&&label->value!=d38_cefc4c->turn464270())type=42;}
   else if(item.get9b65b0()->type457f90()==201)type=21;
   else if(item.get9b65b0()->effect457b70(68))type=22;
   else if(item.get9b65b0()->effect457b70(69))type=23;
   else if(item.get9b65b0()->type457f90()==207)type=26;
   else if(item.get9b65b0()->effect457b70(71))type=24;
   else if(item.get9b65b0()->type457f90()==210)type=38;
   else if(item.get9b65b0()->type457f90()==31)type=39;
   else if(item.get9b65b0()->type457f90()==218)type=41;
  }
 }
 if(label){
  if(type==42||label->type!=type){if(label){remove428b20(label);label=0;}}
  else switch(type){
   case 0:if(label->value!=item.get9b65b0()->rating457ca0())label->set4a6630(item.get9b65b0()->rating457ca0());break;
   case 1:if(label->value!=item.get9b65b0()->value577ad0())label->set4a6240(item.get9b65b0()->value577ad0());break;
   case 5:if(label->value!=item.get9b65b0()->value458260())label->set4a6240(item.get9b65b0()->value458260());break;
   case 10:if(label->value!=item.get9b65b0()->value578e90(false))label->set4a6940(item.get9b65b0()->value578e90(false));break;
   case 15:case 16:if(label->value!=item.get9b65b0()->value4582a0())label->set4a6360(item.get9b65b0()->value4582a0());break;
   case 17:if(label->value!=item.get9b65b0()->value4582a0())label->set4a6d20(item.get9b65b0()->value4582a0());break;
   case 8:if(label->value!=d38_cefc4c->records463d80()->size9b9260())label->set4a7150(d38_cefc4c->records463d80()->size9b9260());break;
   case 18:if(label->value!=d38_cec054->value8054b0(true))label->set4a6240(d38_cec054->value8054b0(true));break;
   case 19:if(label->value!=label->mode4a6cb0())label->set4a6a30(label->mode4a6cb0());break;
   case 21:{int value=item.get9b65b0()->value578f20(0,0);if(label->value!=value)label->set4a6d20(value);break;}
   case 22:if(label->value!=item.get9b65b0()->effectValue457be0(68))label->set4a6240(item.get9b65b0()->effectValue457be0(68));break;
   case 24:if(label->value!=item.get9b65b0()->effectValue457be0(71))label->set4a7700(item.get9b65b0()->effectValue457be0(71));break;
   case 25:if(label->value!=item.get9b65b0()->effectValue457be0(118)-item.get9b65b0()->effectValue457be0(119))label->set4a79f0(item.get9b65b0()->effectValue457be0(118)-item.get9b65b0()->effectValue457be0(119));break;
   case 26:if(label->value!=label->item4a7db0(item))label->set4a7e00(label->item4a7db0(item));break;
   case 27:case 30:case 33:if(label->value!=item.get9b65b0()->value577fd0())label->set4a6240(item.get9b65b0()->value577fd0());break;
   case 29:case 32:case 35:if(label->value!=item.get9b65b0()->value578070())label->set4a6240(item.get9b65b0()->value578070());break;
   case 38:if(label->value!=d38_cefc4c->value4644d0())label->set4a6240(d38_cefc4c->value4644d0());break;
   case 39:if(label->value!=item.get9b65b0()->value45cb30())label->set4a7e00(item.get9b65b0()->value45cb30());break;
   case 41:if(label->value!=d38_d25464)label->set4a6360(d38_d25464);break;
  }
 }else if(type!=42&&type!=20){create890bb0(type);switch(type){case 12:case 13:case 14:d38_sound4541b0(67,0,0);break;case 18:case 19:d38_sound4541b0(83,0,0);break;}}
 D38Point p;
 if(chance&&(!d38_cec054->aim49aa20()||!d38_cec054->point805190(p)||d38_cfd44c.at9ced70(p)[0]->entity45d250().null9b65d0()||!d38_cefc4c->visible4631f0(d38_cfd44c.at9ced70(p)[0]->entity45d250()))){if(chance){remove428b20(chance);chance=0;}}
 else if(d38_cec054->aim49aa20()&&d38_cec078->item.valid9b7230()&&item.get9b65b0()->subtype4578a0()==3&&d38_cec054->point805190(p)&&d38_cfd44c.at9ced70(p)[0]->entity45d250().valid9b7230()&&d38_cefc4c->visible4631f0(d38_cfd44c.at9ced70(p)[0]->entity45d250())){if(!chance)chance=new D38Hit(this);chance->refresh88e410(item);}
 if(d38_d28d16&&d38_d28e57){if(d38_cefc4c->value464290()!=stamp)back417fc0(3,0,*d38_cfe674,true);else back417fc0(3,0,*item.get9b65b0()->color577260()*d38_c36eb4,true);}
}
