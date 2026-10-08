// Private aliases and observed layouts for effect update 0x50e890.
#include "rng.h"
#include <cstdlib>
#include <cctype>
#include <cmath>
extern RNG rng;
struct LB13Point {int x,y;LB13Point();bool different_409bd0(const LB13Point &) const throw();void assign_46ca50(const LB13Point &) throw();int random_40c130() throw();};
struct LB13Pair {int x,y;};
struct LB13Cell {int glyph_9b8f00() throw();};
struct LB13Array {LB13Cell *at_9d2930(LB13Point &) throw();};
struct LB13Vec {
 int a,b,c,d; bool empty_9b86e0() const throw();void clear_9b9510() throw();
 int &integer_9b81f0(unsigned) throw();LB13Array *&array_9b81f0(unsigned) throw();LB13Array *&front_9b7060() throw();
 unsigned size_9b9260() const throw();unsigned pairs_9b6ab0() const throw();unsigned sounds_9b6b50() const throw();unsigned others_9b4f10() const throw();
 void assignPairs_9b6a30(unsigned,const LB13Pair &) throw();void assignInts_9b1950(unsigned,const int &) throw();
};
struct LB13Stepper {void init_4103b0(const LB13Point &,const LB13Point &,const LB13Point &,const LB13Point &,int) throw();bool next_410420(LB13Point &,LB13Point &) throw();char data[0x30];};
struct LB13Console {virtual void f0();virtual void f1();virtual void f2();virtual void f3();virtual void f4();virtual void f5();virtual void f6();virtual void f7();virtual void f8();virtual void f9();virtual int kind();char pad[0x68];LB13Vec arrays;};
struct LB13Owner {LB13Console *console;bool contains_454c20(const LB13Point &) throw();};
struct LB13Record {
 char pad[0x28];int durationMode,duration,durationRange,motion,speed;float speedRange;LB13Point delay;int glyphMode;LB13Vec glyphs;unsigned field5c;int colorMode;
 char pad64[0xb4-0x64];int palette;int fieldb8,foreground,fieldc0,background,fieldc8;LB13Vec spawns,sounds;int fieldec;LB13Vec others;
};
LB13Array *lb13_randomArray_9d5d00(LB13Vec &) throw();int lb13_randomInt_9d5d00(LB13Vec &) throw();float lb13_angle_40a680(const LB13Point &,const LB13Point &) throw();int lb13_max_9cdb60(int,int) throw();
char lb13_char_4085b0(const char *) throw();int lb13_random_9d9c10(int *,unsigned) throw();
extern const char lb13_chars_d34634[],lb13_chars_d33e1c[],lb13_chars_d346a4[];
extern int lb13_ints_bb93d0[10],lb13_ints_bb93f8[14];extern unsigned lb13_clock_caed20,lb13_delta_cefa78;extern bool lb13_mute_d28cbc;
struct LB13Effect {
 LB13Record *record;LB13Owner *owner;unsigned start,end;LB13Point position,size,origin,extent;float speed,delay;LB13Stepper stepper;LB13Point target,targetSize;int extra,glyph;unsigned index;LB13Vec spawned,soundState,otherState;
 bool spawn_50ced0(int,LB13Point &) throw();void sound_50d6c0(int) throw();void other_50d7f0(int) throw();void paint_50da50(LB13Point &) throw();
 bool update_50e890();
};
void lb13_min_9d5b10(float *,float) throw();
bool LB13Effect::update_50e890(){
 if(!start)return false;
 if(end && lb13_clock_caed20>=end && (record->durationMode!=3 || !position.different_409bd0(target))){
  do{
   if(!record->spawns.empty_9b86e0())spawn_50ced0(5,position);
   do{if(!record->sounds.empty_9b86e0() && !lb13_mute_d28cbc)sound_50d6c0(2);}while(false);
   do{if(!record->others.empty_9b86e0())other_50d7f0(2);}while(false);
   if(record->palette || record->foreground || record->background)paint_50da50(position);
   start=0;return true;
  }while(false);
 }
 do{if(!record->spawns.empty_9b86e0() && spawn_50ced0(0,position)){
  do{if(!record->spawns.empty_9b86e0())spawn_50ced0(5,position);
   do{if(!record->sounds.empty_9b86e0() && !lb13_mute_d28cbc)sound_50d6c0(2);}while(false);
   do{if(!record->others.empty_9b86e0())other_50d7f0(2);}while(false);
   if(record->palette || record->foreground || record->background)paint_50da50(position);
   start=0;return true;
  }while(false);
 }}while(false);
 do{if(!record->spawns.empty_9b86e0() && spawn_50ced0(1,position)){
  do{if(!record->spawns.empty_9b86e0())spawn_50ced0(5,position);
   do{if(!record->sounds.empty_9b86e0() && !lb13_mute_d28cbc)sound_50d6c0(2);}while(false);
   do{if(!record->others.empty_9b86e0())other_50d7f0(2);}while(false);
   if(record->palette || record->foreground || record->background)paint_50da50(position);
   start=0;return true;
  }while(false);
 }}while(false);
 do{if(!record->others.empty_9b86e0())other_50d7f0(1);}while(false);
 do{if(!record->sounds.empty_9b86e0() && !lb13_mute_d28cbc)sound_50d6c0(1);}while(false);
 switch(record->motion){case 0:case 1:break;
 case 2:speed=record->speed+record->speedRange*(lb13_clock_caed20-start);lb13_min_9d5b10(&speed,15.0f);break;
 case 3:speed+=rng.rangeFloat(0,record->speedRange);lb13_min_9d5b10(&speed,15.0f);break;
 case 4:speed=record->speed+sin((float)((float)(lb13_clock_caed20-start)/(end-start)*1.5707963705062866))*(record->speedRange-record->speed);lb13_min_9d5b10(&speed,15.0f);break;
 }
 if(speed!=0){
  delay+=lb13_delta_cefa78;
  while(delay>=speed){
   LB13Point first;
   for(int count=0;count<9;++count){
    first.assign_46ca50(position);++extra;
    if(stepper.next_410420(position,size) || !owner->contains_454c20(position)){
     do{if(!record->spawns.empty_9b86e0()){LB13Point *a=first.different_409bd0(position)?&first:&position;spawn_50ced0(5,*a);}
      do{if(!record->sounds.empty_9b86e0() && !lb13_mute_d28cbc)sound_50d6c0(2);}while(false);
      do{if(!record->others.empty_9b86e0())other_50d7f0(2);}while(false);
      if(record->palette || record->foreground || record->background){LB13Point *a=first.different_409bd0(position)?&first:&position;paint_50da50(*a);}
      start=0;return true;
     }while(false);
    }
    if(first.different_409bd0(position)){
     do{if(!record->spawns.empty_9b86e0() && spawn_50ced0(4,first)){
      do{if(!record->spawns.empty_9b86e0())spawn_50ced0(5,position);
       do{if(!record->sounds.empty_9b86e0() && !lb13_mute_d28cbc)sound_50d6c0(2);}while(false);
       do{if(!record->others.empty_9b86e0())other_50d7f0(2);}while(false);
       if(record->palette || record->foreground || record->background)paint_50da50(position);
       start=0;return true;
      }while(false);
     }}while(false);
     do{if(!record->spawns.empty_9b86e0() && spawn_50ced0(3,position)){
      do{if(!record->spawns.empty_9b86e0())spawn_50ced0(5,position);
       do{if(!record->sounds.empty_9b86e0() && !lb13_mute_d28cbc)sound_50d6c0(2);}while(false);
       do{if(!record->others.empty_9b86e0())other_50d7f0(2);}while(false);
       if(record->palette || record->foreground || record->background)paint_50da50(position);
       start=0;return true;
      }while(false);
     }}while(false);
     extra=1;
    }
   }
   delay-=speed;
  }
  if(delay<0.0)return false;
 }
 if(record->glyphMode>=15){
  switch(record->glyphMode){
  case 15:case 16:case 17:case 18:glyph=owner->console->arrays.array_9b81f0(record->glyphMode-15)->at_9d2930(position)->glyph_9b8f00();break;
  case 19:glyph=record->glyphs.integer_9b81f0(((lb13_clock_caed20-start)/record->field5c)%record->glyphs.size_9b9260());break;
  case 27:glyph=owner->console->arrays.array_9b81f0(((lb13_clock_caed20-start)/record->field5c)%owner->console->arrays.size_9b9260())->at_9d2930(origin)->glyph_9b8f00();break;
  default:
   index+=(float)lb13_delta_cefa78;
   if(index>=record->field5c){
    switch(record->glyphMode){
    case 20:glyph=lb13_randomInt_9d5d00(record->glyphs);break;
    case 21:glyph=lb13_char_4085b0(lb13_chars_d34634);break;
    case 22:glyph=lb13_random_9d9c10(lb13_ints_bb93d0,10);break;
    case 23:glyph=lb13_char_4085b0(lb13_chars_d33e1c);break;
    case 24:glyph=lb13_char_4085b0(lb13_chars_d33e1c);if(islower(glyph))glyph=toupper(glyph);break;
    case 25:glyph=lb13_char_4085b0(lb13_chars_d346a4);break;
    case 26:glyph=lb13_random_9d9c10(lb13_ints_bb93f8,14);break;
    case 28:glyph=lb13_randomArray_9d5d00(owner->console->arrays)->at_9d2930(origin)->glyph_9b8f00();break;
    }
    index-=record->field5c;
   }
   while(index>=record->field5c)index-=record->field5c;
  }
 }
 return false;
}
