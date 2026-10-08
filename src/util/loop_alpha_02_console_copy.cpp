// NOTE: private names and partial layouts; cropped alpha copy of character cells.
struct LA2Pos { int x,y; };
struct LA2Rect { int x,y,w,h; LA2Rect() throw(); LA2Rect &operator=(const LA2Rect&) throw(); void set(int,int,int,int) throw(); };
struct LA2Color { unsigned char r,g,b; LA2Color(const LA2Color&) throw(); bool operator==(LA2Color) throw(); void lerp(LA2Color,float) throw(); static LA2Color lerp(LA2Color,LA2Color,float) throw(); LA2Color &operator=(LA2Color) throw(); };
struct LA2Cell { int font,ch,unknown8; LA2Color fg,bg; LA2Cell &operator=(const LA2Cell&) throw(); };
struct LA2Buffer { int a,b; void *p; int width() throw(); int height() throw(); LA2Cell *at(int,int) throw(); };
extern LA2Color *la2_transparent_d20cfc;
struct LA2Console { char pad[8]; LA2Buffer buffer; char pad14[0x3c-0x14]; float fgAlpha,bgAlpha; void copy429fe0(LA2Console*,LA2Pos&,const LA2Rect*); };
void LA2Console::copy429fe0(LA2Console *target,LA2Pos &offset,const LA2Rect *region) {
 int x,y,ty,dx; LA2Cell *cur,*dest;
 LA2Buffer *in2=&target->buffer;
 LA2Rect area;
 if(region) area=*region;
 else area.set(0,0,buffer.width(),buffer.height());
 if(offset.x<0) { if(area.w < -offset.x) return; area.x+=-offset.x;area.w-=-offset.x;offset.x=0; }
 if(offset.y<0) { if(area.h < -offset.y) return; area.y+=-offset.y;area.h-=-offset.y;offset.y=0; }
 if(offset.x+area.w>in2->width()) area.w=in2->width()-offset.x;
 if(offset.y+area.h>in2->height()) area.h=in2->height()-offset.y;
 for(x=area.x, dx=offset.x;x<area.x+area.w;x++,dx++) {
  for(y=area.y, ty=offset.y;y<area.y+area.h;y++,ty++) {
   if(buffer.at(x,y)->bg==*la2_transparent_d20cfc) continue;
   if(fgAlpha==1 && bgAlpha==1) *in2->at(dx,ty)=*buffer.at(x,y);
   else {
    cur=buffer.at(x,y);
    dest=in2->at(dx,ty);
    dest->bg.lerp(cur->bg,bgAlpha);
    if(cur->ch==' ') dest->fg.lerp(cur->bg,bgAlpha);
    else if(dest->ch==' ') { dest->ch=cur->ch;dest->unknown8=cur->unknown8;dest->fg=LA2Color::lerp(dest->bg,cur->fg,fgAlpha); }
    else if(dest->ch==cur->ch) dest->fg.lerp(cur->fg,fgAlpha);
    else if(fgAlpha<0.5) dest->fg.lerp(dest->bg,fgAlpha*2);
    else { dest->ch=cur->ch;dest->unknown8=cur->unknown8;dest->fg=LA2Color::lerp(dest->bg,cur->fg,(fgAlpha-0.5)*2); }
   }
  }
 }
}
