// Private aliases and observed layouts for effect initialization 0x50de10.
#include "../../src/util/rng.h"
#include <cstdlib>
#include <cctype>
extern RNG rng;
struct LB10Point {int x,y;void assign_46ca50(const LB10Point &) throw();int random_40c130() throw();};
struct LB10Pair {int x,y;};
struct LB10Cell {int glyph_9b8f00() throw();};
struct LB10Array {LB10Cell *at_9d2930(LB10Point &) throw();};
struct LB10Vec {
 int a,b,c,d; bool empty_9b86e0() const throw();void clear_9b9510() throw();
 int &integer_9b81f0(unsigned) throw();LB10Array *&array_9b81f0(unsigned) throw();LB10Array *&front_9b7060() throw();
 unsigned size_9b9260() const throw();unsigned pairs_9b6ab0() const throw();unsigned sounds_9b6b50() const throw();unsigned others_9b4f10() const throw();
 void assignPairs_9b6a30(unsigned,const LB10Pair &) throw();void assignInts_9b1950(unsigned,const int &) throw();
};
struct LB10Stepper {void init_4103b0(const LB10Point &,const LB10Point &,const LB10Point &,const LB10Point &,int) throw();char data[0x30];};
struct LB10Console {virtual void f0();virtual void f1();virtual void f2();virtual void f3();virtual void f4();virtual void f5();virtual void f6();virtual void f7();virtual void f8();virtual void f9();virtual int kind();char pad[0x68];LB10Vec arrays;};
struct LB10Owner {LB10Console *console;};
struct LB10Record {
 char pad[0x28];int durationMode,duration,durationRange,motion,speed;float speedRange;LB10Point delay;int glyphMode;LB10Vec glyphs;int field5c,colorMode;
 char pad64[0xb4-0x64];int palette;int fieldb8,foreground,fieldc0,background,fieldc8;LB10Vec spawns,sounds;int fieldec;LB10Vec others;
};
LB10Array *lb10_randomArray_9d5d00(LB10Vec &) throw();int lb10_randomInt_9d5d00(LB10Vec &) throw();float lb10_angle_40a680(const LB10Point &,const LB10Point &) throw();int lb10_max_9cdb60(int,int) throw();
char lb10_char_4085b0(const char *) throw();int lb10_random_9d9c10(int *,unsigned) throw();
extern const char lb10_chars_d34634[],lb10_chars_d33e1c[],lb10_chars_d346a4[];
extern int lb10_ints_bb93d0[10],lb10_ints_bb93f8[14];extern unsigned lb10_clock_caed20;extern bool lb10_mute_d28cbc;
struct LB10Effect {
 LB10Record *record;LB10Owner *owner;unsigned start,end;LB10Point position,size,origin,extent;float speed,delay;LB10Stepper stepper;LB10Point target,targetSize;int extra,glyph,index;LB10Vec spawned,soundState,otherState;
 bool spawn_50ced0(int,LB10Point &) throw();void sound_50d6c0(int) throw();void other_50d7f0(int) throw();void paint_50da50(LB10Point &) throw();
 bool init_50de10(LB10Owner *,LB10Record *,const LB10Point &,const LB10Point &,const LB10Point *,const LB10Point *,int);
};
bool LB10Effect::init_50de10(LB10Owner *newOwner,LB10Record *newRecord,const LB10Point &point,const LB10Point &dimensions,const LB10Point *destination,const LB10Point *destinationSize,int value){
 record=newRecord;owner=newOwner;position.assign_46ca50(point);size.assign_46ca50(dimensions);origin.assign_46ca50(point);extent.assign_46ca50(dimensions);delay=0;
 if(destination){target.assign_46ca50(*destination);targetSize.assign_46ca50(*destinationSize);
  switch(record->motion){case 0:speed=0;break;
  case 1:speed=record->speedRange>0.0 ? record->speed+rng.rangeInt(-record->speedRange,record->speedRange):record->speed;goto motion;
  case 2:case 3:case 4:speed=(float)record->speed;
  motion:delay=(float)-record->delay.random_40c130();stepper.init_4103b0(origin,extent,target,targetSize,9);break;}
 }else speed=0;
 extra=value;start=lb10_clock_caed20;
 switch(record->durationMode){case 0:end=0;break;
 case 1:end=lb10_clock_caed20+(record->durationRange ? record->duration+rng.rangeInt((float)-record->durationRange,(float)record->durationRange):record->duration);break;
 case 2:end=lb10_clock_caed20+(record->durationRange ? record->duration+rng.rangeInt((float)-record->durationRange,(float)record->durationRange):record->duration)*speed;break;
 case 3:end=lb10_clock_caed20+lb10_max_9cdb60(abs(destination->x-position.x),abs(destination->y-position.y))*speed;break;}
 switch(record->glyphMode){case 0:break;
 case 1:glyph=record->glyphs.integer_9b81f0(0);break;
 case 2:if(!destination)glyph=record->glyphs.integer_9b81f0(0);else{float first=lb10_angle_40a680(origin,*destination);int count=first>=337.5 ? 0:(int)((first/22.5+1.0)/2.0);glyph=record->glyphs.integer_9b81f0(count);}break;
 case 11:case 12:case 13:case 14:
  if(owner->console->kind()!=1){glyph=32;record->glyphMode=0;}
  else if(record->glyphMode-11>=owner->console->arrays.size_9b9260()){glyph=32;record->glyphMode=0;}
  else glyph=owner->console->arrays.array_9b81f0(record->glyphMode-11)->at_9d2930(target)->glyph_9b8f00();break;
 case 15:case 16:case 17:case 18:
  if(owner->console->kind()!=1){glyph=32;record->glyphMode=0;}
  else if(record->glyphMode-15>=owner->console->arrays.size_9b9260()){glyph=32;record->glyphMode=0;}
  else glyph=owner->console->arrays.array_9b81f0(record->glyphMode-15)->at_9d2930(origin)->glyph_9b8f00();break;
 case 10:case 27:case 28:
  if(owner->console->kind()!=1){glyph=32;record->glyphMode=0;}
  else if(record->glyphMode==27)glyph=owner->console->arrays.front_9b7060()->at_9d2930(origin)->glyph_9b8f00();
  else glyph=lb10_randomArray_9d5d00(owner->console->arrays)->at_9d2930(origin)->glyph_9b8f00();break;
 case 19:glyph=record->glyphs.integer_9b81f0(0);break;
 case 3:case 20:glyph=lb10_randomInt_9d5d00(record->glyphs);break;
 case 4:case 21:glyph=lb10_char_4085b0(lb10_chars_d34634);break;
 case 5:case 22:glyph=lb10_random_9d9c10(lb10_ints_bb93d0,10);break;
 case 6:case 23:glyph=lb10_char_4085b0(lb10_chars_d33e1c);break;
 case 7:case 24:glyph=lb10_char_4085b0(lb10_chars_d33e1c);if(islower(glyph))glyph=toupper(glyph);break;
 case 8:case 25:glyph=lb10_char_4085b0(lb10_chars_d346a4);break;
 case 9:case 26:glyph=lb10_random_9d9c10(lb10_ints_bb93f8,14);break;
 }
 index=0;
 if(record->colorMode>=15){if(owner->console->kind()!=1)record->colorMode=0;else if((record->colorMode-15)%4>=owner->console->arrays.size_9b9260())record->colorMode=0;}
 if(!spawned.empty_9b86e0())spawned.clear_9b9510();
 if(!record->spawns.empty_9b86e0()){LB10Pair a={0,0};spawned.assignPairs_9b6a30(record->spawns.pairs_9b6ab0(),a);}
 if(!record->sounds.empty_9b86e0()){int i=0;soundState.assignInts_9b1950(record->sounds.sounds_9b6b50(),i);}
 if(!record->others.empty_9b86e0()){int base=0;otherState.assignInts_9b1950(record->others.others_9b4f10(),base);}
 do{if(!record->spawns.empty_9b86e0() && spawn_50ced0(2,position)){
  do{if(!record->spawns.empty_9b86e0())spawn_50ced0(5,position);
   do{if(!record->sounds.empty_9b86e0() && !lb10_mute_d28cbc)sound_50d6c0(2);}while(false);
   do{if(!record->others.empty_9b86e0())other_50d7f0(2);}while(false);
   if(record->palette || record->foreground || record->background)paint_50da50(position);
   start=0;return true;
  }while(false);
 }}while(false);
 do{if(!record->sounds.empty_9b86e0() && !lb10_mute_d28cbc)sound_50d6c0(0);}while(false);
 do{if(!record->others.empty_9b86e0())other_50d7f0(0);}while(false);
 return true;
}
