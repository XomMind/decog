#include <string>
#include <memory>
using std::string;
// NOTE: private partial retail views; typed native owners and all real operations remain external.
struct D32Points;
struct D32P{int x,y;D32P(int,int)throw();D32P(const D32P&)throw();void adjacent409e50(D32Points*,bool);};
struct D32RGB{unsigned char r,g,b;D32RGB(const D32RGB&)throw();bool equal411f40(D32RGB)throw();bool different411f90(D32RGB)throw();};
struct D32Ints{int*first,*last,*capacity;std::allocator<int>allocator;unsigned size9b9260()const throw();int&front9b7060()throw();int&at9b81f0(unsigned)throw();};
struct D32Points{D32P*first,*last,*capacity;std::allocator<D32P>allocator;D32Points()throw();D32Points(unsigned,const D32P&);~D32Points();void clear9b3560();unsigned size9b9a50()const throw();bool empty9b86e0()const throw();D32P&at9e7c10(unsigned)throw();void push9b32e0(const D32P&);};
template<class T>struct D32Vec{T*first,*last,*capacity;std::allocator<T>allocator;T&at9b8070(unsigned)throw();};
struct D32IntGrid{int width,height;int*data;D32IntGrid()throw();~D32IntGrid();void init9cf690(int,int,int);bool contains9b43b0(const D32P&)throw();int*at9ced70(D32P&)throw();};
struct D32Cell{char unobserved0[4];int glyph;char unobserved8[12];int glyph9b8f00()throw();};
struct D32CellGrid{int width,height;D32Cell*data;D32Cell*at9d2930(D32P&)throw();};
struct D32FxDef;
struct D32Engine;
struct D32Effect{bool init50de10(D32Engine*,D32FxDef*,const D32P&,const D32P&,const D32P*,const D32P*,int);};
struct D32Engine{bool update50fff0();D32Effect*next50fb50();};
struct D32Console{char p[0x60];int state;D32Engine*engine;void*title;int width44b0d0()throw();int height4174c0()throw();void hidden417ba0(bool)throw();void fore417b00(D32RGB);void put4180b0(int,int,int);void put418150(int,int,int,D32RGB,D32RGB,int);void row4298a0(int,int,int,int,D32RGB,D32RGB);void row4183a0(int,int,int);void back429c20(int,int,int,D32RGB);void print4181d0(int,int,const string&);void base429e30();};
struct D32Main:D32Console{D32Vec<D32CellGrid*>frames;};
struct D32Ufd{D32Main*main4b8e50()throw();};extern D32Ufd*d32_cec148;
struct D32Area:D32Console{int kind;unsigned start,delay;bool started;int old;void update997220();};
extern unsigned d32_caed20;extern const unsigned d32_bce9a4;extern unsigned char d32_bce818[];extern int d32_bce830[];
extern D32RGB d32_d21e5c[],d32_d2c37c[],d32_d2a584[];extern D32RGB*d32_cfe674,*d32_d1e1d8;
extern string d32_d29088[],d32_d33bf0[];extern const char d32_c151c8[],d32_c151dc[];extern D32P d32_cfbec0;
extern D32Vec<D32Ints>d32_cf670c,d32_d21f5c;extern D32Vec<D32Points>d32_cf4d94;
bool d32_lookup9d45a0(const string&,D32FxDef**);int d32_sound4541b0(unsigned,int,int);void d32_erase9d53f0(D32Points&,int,int);
// Retail xor/test backedge around each animation loop supports actual do/while(false) macro.
#define D32_FX(key) {D32FxDef*effect;d32_lookup9d45a0(key,&effect);do{for(int x=D32P(0,1).x;x<D32P(0,1).x+width44b0d0();x++)engine->next50fb50()->init50de10(engine,effect,D32P(x,D32P(0,1).y),d32_cfbec0,0,0,9);}while(0);}
static_assert(sizeof(D32Points)==16&&sizeof(D32IntGrid)==12&&sizeof(D32Cell)==20,"native owners/cell extent");
void D32Area::update997220(){
 engine->update50fff0();
 if(d32_caed20>=delay){
  bool visible=false;if(!started){started=true;hidden417ba0(false);d32_sound4541b0(124,0,0);visible=true;}
  int mode=d32_cf670c.at9b8070(kind).front9b7060();
  if(d32_caed20>start)for(int i=d32_d21f5c.at9b8070(kind).size9b9260()-1;i>0;i--)if((d32_caed20-start)*100/d32_bce9a4>=d32_d21f5c.at9b8070(kind).at9b81f0(i)){mode=d32_cf670c.at9b8070(kind).at9b81f0(i);break;}
  if(!d32_bce818[kind]){
   put418150(d32_bce830[kind],0,219,d32_d21e5c[kind],*d32_cfe674,true);
   row4298a0(0,0,d32_bce830[kind],196,d32_d2c37c[kind],*d32_cfe674);
   fore417b00(d32_d21e5c[kind]);print4181d0(d32_bce830[kind]+2,0,d32_d29088[kind]);back429c20(d32_bce830[kind]+2,0,d32_d29088[kind].size(),*d32_cfe674);
   row4183a0(0,1,width44b0d0());
   if(d32_d2a584[mode].equal411f40(*d32_d1e1d8))put4180b0(d32_bce830[kind],1,32);else put418150(d32_bce830[kind],1,45,d32_d2a584[mode],*d32_cfe674,true);
   fore417b00(d32_d2a584[mode]);print4181d0(d32_bce830[kind]+2,1,d32_d33bf0[mode]);back429c20(d32_bce830[kind]+2,1,d32_d33bf0[mode].size(),*d32_cfe674);
   if(old!=mode&&d32_d2a584[mode].different411f90(*d32_d1e1d8)){D32_FX(d32_c151c8);if(!visible)d32_sound4541b0(125,0,0);}
  }else{
   put418150(width44b0d0()-d32_bce830[kind]-1,0,219,d32_d21e5c[kind],*d32_cfe674,true);
   row4298a0(width44b0d0()-d32_bce830[kind],0,d32_bce830[kind],196,d32_d2c37c[kind],*d32_cfe674);
   fore417b00(d32_d21e5c[kind]);print4181d0(width44b0d0()-d32_bce830[kind]-2-d32_d29088[kind].size(),0,d32_d29088[kind]);back429c20(width44b0d0()-d32_bce830[kind]-2-d32_d29088[kind].size(),0,d32_d29088[kind].size(),*d32_cfe674);
   row4183a0(0,1,width44b0d0());
   if(d32_d2a584[mode].equal411f40(*d32_d1e1d8))put4180b0(width44b0d0()-d32_bce830[kind]-1,1,32);else put418150(width44b0d0()-d32_bce830[kind]-1,1,45,d32_d2a584[mode],*d32_cfe674,true);
   fore417b00(d32_d2a584[mode]);print4181d0(width44b0d0()-d32_bce830[kind]-2-d32_d33bf0[mode].size(),1,d32_d33bf0[mode]);back429c20(width44b0d0()-d32_bce830[kind]-2-d32_d33bf0[mode].size(),1,d32_d33bf0[mode].size(),*d32_cfe674);
   if(old!=mode&&d32_d2a584[mode].different411f90(*d32_d1e1d8)){D32_FX(d32_c151dc);if(!visible)d32_sound4541b0(125,0,0);}
  }
  old=mode;D32Main*col=d32_cec148->main4b8e50();D32CellGrid*base=col->frames.at9b8070(1);
  for(int i=0;i<d32_cf4d94.at9b8070(kind).size9b9a50();i++){
   D32IntGrid visited;visited.init9cf690(col->width44b0d0(),col->height4174c0(),0);
   D32Points points(1,d32_cf4d94.at9b8070(kind).at9e7c10(i));*visited.at9ced70(d32_cf4d94.at9b8070(kind).at9e7c10(i))=1;
   do{int count=points.size9b9a50();D32Points current;
    for(int j=0;j<count;j++){
     if(base->at9d2930(points.at9e7c10(j))->glyph9b8f00()==63)col->put418150(points.at9e7c10(j).x,points.at9e7c10(j).y,base->at9d2930(points.at9e7c10(j))->glyph9b8f00(),*d32_cfe674,d32_d21e5c[kind],true);
     else col->put418150(points.at9e7c10(j).x,points.at9e7c10(j).y,base->at9d2930(points.at9e7c10(j))->glyph9b8f00(),d32_d21e5c[kind],*d32_cfe674,true);
     current.clear9b3560();points.at9e7c10(j).adjacent409e50(&current,true);
     for(int k=0;k<current.size9b9a50();k++)if(visited.contains9b43b0(current.at9e7c10(k))&&!*visited.at9ced70(current.at9e7c10(k))&&(base->at9d2930(current.at9e7c10(k))->glyph9b8f00()==219||base->at9d2930(current.at9e7c10(k))->glyph9b8f00()==63)){points.push9b32e0(current.at9e7c10(k));*visited.at9ced70(current.at9e7c10(k))=1;}
    }
    d32_erase9d53f0(points,0,count-1);
   }while(!points.empty9b86e0());
  }
 }
 base429e30();
}
