// NOTE: private aliases and partial layouts for effect initialization 0x503b20.
#include "../../src/util/rng.h"
#include <cstdlib>
#include <cctype>
extern RNG rng;
struct LB8Point {
 int x,y; void assign_46ca50(const LB8Point &) throw();
 LB8Point(const LB8Point &,const LB8Point &) throw(); int random_40c130() throw();
 bool same_409b90(const LB8Point &) const throw();
};
struct LB8Pair {int x,y;};
struct LB8Color {
 unsigned char r,g,b; LB8Color(const LB8Color &) throw(); LB8Color &operator=(LB8Color) throw();
};
struct LB8Vec {
 int a,b,c,d; int &at_9b81f0(unsigned) throw(); bool empty_9b86e0() const throw();
 void clear_9b9510() throw(); unsigned sizePairs_9b69d0() const throw(); unsigned sizeInts_9b6b50() const throw();
 void assignPairs_9b6a30(unsigned,const LB8Pair &) throw(); void assignInts_9b1950(unsigned,const int &) throw();
};
struct LB8Stepper {void init_4103b0(const LB8Point &,const LB8Point &,const LB8Point &,const LB8Point &,int) throw();};
struct LB8Item {int glyph_457a30() const throw();};
struct LB8HI {int id; bool valid_9b7230() const throw(); LB8Item *get_9b65b0() const throw();};
struct LB8Glyph {int glyph_454560(const LB8Point &) throw();};
struct LB8Owned {char pad[0x1c];LB8HI item,other;char pad24[0x60-0x24];LB8Glyph *glyph;};
struct LB8Record {
 char pad[0x20];int kind,durationMode,duration,durationRange,speedMode,speed;float speedRange;
 LB8Point delay;bool scaleDelay;int glyphMode;LB8Vec glyphs;int field5c,field60,colorMode;LB8Color color;
 char pad6b[0xb8-0x6b];LB8Vec spawns,sounds;
};
struct LB8Console {
 const LB8Point &offset_458ef0() const throw(); int glyph_417700(const LB8Point &) const throw();
 LB8Color color_417720(const LB8Point &) const throw();
};
extern LB8Console *lb8_console_cec054;
extern int lb8_width_cf27f4,lb8_height_cf27f8,lb8_delayScale_cefb68;
extern unsigned lb8_clock_caed20;
extern const LB8Color *lb8_defaultColor_cfe674;
extern const LB8Color lb8_black_d02364;
extern bool lb8_mute_d28cbc;
struct LB8Text;
extern const LB8Text lb8_chars_d2022c,lb8_chars_d32974,lb8_chars_d01f04;
extern const int lb8_chars_bb9340[];
char lb8_randomChar_4085b0(const LB8Text &) throw();
int lb8_randomOf_9d9c10(const int *,unsigned) throw(); int lb8_randomVec_9d5d00(LB8Vec *) throw();
float lb8_angle_40a680(const LB8Point &,const LB8Point &) throw();
int lb8_max_9cdb60(int,int) throw();
struct LB8Effect;
struct LB8EffectList {int a,b,c,d;void push_9b9d30(LB8Effect *const &) throw();};
struct LB8Pool {char pad[0x24];LB8EffectList straight,other;};
struct LB8Effect {
 LB8Record *data;LB8Pool *owner;unsigned start,end;LB8Point origin,offset,point20,point28;
 float speed,delay;char stepper[0x30];LB8Point point68,point70;int target,field7c,field80,field84,glyph,frame;
 LB8Color color;LB8Vec spawns,sounds;LB8Owned *extra;
 void init_503b20(LB8Pool *,LB8Record *,const LB8Point &,const LB8Point &,const LB8Point *,const LB8Point *,LB8Owned *,int,LB8Effect *);
 void blend_5019c0(const LB8Color &,int &,const LB8Color &) throw();
 void spawn_5031d0(int,const LB8Point &) throw();void sound_503930(int) throw();
};
void LB8Effect::init_503b20(LB8Pool *pool,LB8Record *record,const LB8Point &p,const LB8Point &off,const LB8Point *to,const LB8Point *toOff,LB8Owned *owned,int kind,LB8Effect *parent) {
 data=record;owner=pool;origin.assign_46ca50(p);offset.assign_46ca50(off);
 delete extra;extra=owned;point20.assign_46ca50(p);point28.assign_46ca50(off);delay=0.0f;
 if(to) {
  point68.assign_46ca50(*to);point70.assign_46ca50(*toOff);
  if(data->kind==2 && point68.same_409b90(point20))speed=0.0f;
  else {
   switch(data->speedMode) {
   case 0:speed=0.0f;break;
   case 1:
    speed=data->speedRange>0.0 ? data->speed+rng.rangeInt(-data->speedRange,data->speedRange):data->speed;
    goto motion;
   case 2:case 3:case 4:speed=(float)data->speed;
 motion:
   if(data->scaleDelay)delay=(float)(-data->delay.random_40c130()*lb8_delayScale_cefb68);
   else delay=(float)-data->delay.random_40c130();
   reinterpret_cast<LB8Stepper *>(stepper)->init_4103b0(point20,point28,point68,point70,9);
   }
  }
 } else speed=0.0f;
 target=kind;start=lb8_clock_caed20;
 switch(data->durationMode) {
 case 0:end=0;break;
 case 1:end=lb8_clock_caed20+(data->durationRange?data->duration+rng.rangeInt(-data->durationRange,data->durationRange):data->duration);break;
 case 2:if(parent)end=parent->end;else end=lb8_clock_caed20+1;break;
 case 3:end=lb8_clock_caed20+(data->durationRange?data->duration+rng.rangeInt(-data->durationRange,data->durationRange):data->duration)*speed;break;
 case 4:end=lb8_clock_caed20+lb8_max_9cdb60(abs(to->x-origin.x),abs(to->y-origin.y))*speed;break;
 }
 field80=0;
 switch(data->glyphMode) {
 break;
 case 1:glyph=data->glyphs.at_9b81f0(0);break;
 case 2:
  if(!to)glyph=data->glyphs.at_9b81f0(0);
  else {
   float first=lb8_angle_40a680(point20,*to);
   int count=first>=337.5?0:(int)((first/22.5+1.0)/2.0);
   glyph=data->glyphs.at_9b81f0(count);
  }
  break;
 case 3:glyph=extra->item.valid_9b7230()?extra->item.get_9b65b0()->glyph_457a30():extra->other.get_9b65b0()->glyph_457a30();break;
 case 4:glyph=extra->glyph?extra->glyph->glyph_454560(origin):63;break;
 case 5:
  {
   LB8Point first(lb8_console_cec054->offset_458ef0(),origin);
   if(first.x<0 || first.x>=lb8_width_cf27f4 || first.y<0 || first.y>=lb8_height_cf27f8)glyph=32;
   else glyph=lb8_console_cec054->glyph_417700(first);
  }
  break;
 case 6:if(parent)glyph=parent->glyph;else glyph=32;break;
 case 13:glyph=data->glyphs.at_9b81f0(0);break;
 case 7:case 14:glyph=lb8_randomVec_9d5d00(&data->glyphs);break;
 case 8:case 15:glyph=lb8_randomChar_4085b0(lb8_chars_d2022c);break;
 case 9:case 16:glyph=lb8_randomOf_9d9c10(lb8_chars_bb9340,10);break;
 case 10:case 17:glyph=lb8_randomChar_4085b0(lb8_chars_d32974);break;
 case 11:case 18:glyph=lb8_randomChar_4085b0(lb8_chars_d32974);if(islower(glyph))glyph=toupper(glyph);break;
 case 12:case 19:glyph=lb8_randomChar_4085b0(lb8_chars_d01f04);break;
 }
 frame=0;
 switch(data->colorMode) {
 case 18:
  {
   LB8Point first(lb8_console_cec054->offset_458ef0(),origin);
   if(first.x<0 || first.x>=lb8_width_cf27f4 || first.y<0 || first.y>=lb8_height_cf27f8)color=*lb8_defaultColor_cfe674;
   else color=lb8_console_cec054->color_417720(first);
  }
  break;
 case 19:
  if(parent) {
   parent->blend_5019c0(parent->data->color,parent->data->colorMode,parent->data->color);
   color=lb8_black_d02364;
  } else color=*lb8_defaultColor_cfe674;
  break;
 }
 if(!spawns.empty_9b86e0())spawns.clear_9b9510();
 if(!data->spawns.empty_9b86e0()) {
  LB8Pair first={0,0};spawns.assignPairs_9b6a30(data->spawns.sizePairs_9b69d0(),first);
 }
 if(!data->sounds.empty_9b86e0())sounds.assignInts_9b1950(data->sounds.sizeInts_9b6b50(),0);
 do {if(!data->spawns.empty_9b86e0())spawn_5031d0(3,origin);}while(false);
 do {if(!data->sounds.empty_9b86e0() && !lb8_mute_d28cbc)sound_503930(0);}while(false);
 switch(data->kind) {
 case 1:owner->straight.push_9b9d30(this);break;
 case 3:owner->other.push_9b9d30(this);break;
 }
}
