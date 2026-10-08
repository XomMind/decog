// NOTE: private borrowed REX/font views for actual setVideoMode4230e0.
#include <string>
#include <vector>
using std::string;using std::vector;
struct LB35Rect{short x,y;unsigned short w,h;};
struct LB35PixelFormat;
struct LB35Surface{unsigned flags;LB35PixelFormat*format;int w,h;};
struct LB35Event{unsigned char type,gain,state,pad;unsigned short x,y;int word8,wordc,word10;};
extern "C" {
__declspec(dllimport) LB35Rect** SDL_ListModes(LB35PixelFormat*,unsigned);
__declspec(dllimport) int SDL_VideoModeOK(int,int,int,unsigned);
__declspec(dllimport) LB35Surface* SDL_SetVideoMode(int,int,int,unsigned);
__declspec(dllimport) char*SDL_GetError();
__declspec(dllimport) void SDL_UpdateRect(LB35Surface*,int,int,unsigned,unsigned);
__declspec(dllimport) int SDL_PollEvent(LB35Event*);
}
struct LB35FontSet;
struct LB35Font{LB35Font();~LB35Font();string name;LB35FontSet*fontSet;LB35Font*autoscaleSource;int autoscaleFactor;LB35Surface*bitmap;int w,h;};
struct LB35FontSet{LB35FontSet();~LB35FontSet();string name;vector<LB35Font*> fonts;};
struct LB35Log{int end410e50(int);};extern LB35Log*lb35_cefa64;extern LB35Surface*lb35_cefa80;
void lb35_info405150(string);void lb35_log404cb0(string);void lb35_fatal404fd0(string,string);string lb35_int4051f0(int);
struct LB35Rex{
 int renderer,fullscreen;bool borderless;char unknown9[3];int customw,customh,offsetx,offsety,desktopw,desktoph;char unknown24[0x5c-0x24];int charw,charh,cols,rows;char unknown6c[0xd0-0x6c];LB35FontSet*font;void video4230e0();
};
void LB35Rex::video4230e0(){
 lb35_info405150("Setting video mode");
 unsigned commands=0x10000000;
 if(fullscreen){lb35_log404cb0("Targeting fullscreen");commands|=0x80000000;if(borderless&&(commands&0x80000000)){lb35_log404cb0("...setting borderless window flags");commands^=0x80000000;commands^=0x20;}}
 int other=font?font->fonts[0]->w:charw;
 int mode=font?font->fonts[0]->h:charh;
 int a=cols*other;int count=rows*mode;int tmp,first;int end;
 switch(fullscreen){case 0:tmp=a;first=count;break;case 1:tmp=desktopw;first=desktoph;break;case 2:tmp=customw;first=customh;break;}
 lb35_log404cb0("Calculating dimensions");
 lb35_log404cb0("...charW="+lb35_int4051f0(other));lb35_log404cb0("...charH="+lb35_int4051f0(mode));lb35_log404cb0("...wMin="+lb35_int4051f0(a));lb35_log404cb0("...hMin="+lb35_int4051f0(count));lb35_log404cb0("...wWanted="+lb35_int4051f0(tmp));lb35_log404cb0("...hWanted="+lb35_int4051f0(first));
 if(a>tmp||count>first)lb35_fatal404fd0("REX::setVideoMode()","Unsupported fullscreen mode (fonts filtered assuming no custom fullscreen resolution)");
 int base=99999,slots=99999;
 LB35Rect**point=SDL_ListModes(0,commands);
 if(!point)lb35_fatal404fd0("REX::setVideoMode()","No video modes available for specified format");
 if(point!=(LB35Rect**)-1){
  lb35_log404cb0("Limited video mode availability");
  for(end=0;point[end];end++){
   lb35_log404cb0("Testing mode: "+lb35_int4051f0(point[end]->w)+"x"+lb35_int4051f0(point[end]->h));
   if(point[end]->w>=tmp&&point[end]->w<=base&&point[end]->h>=first&&point[end]->h<=slots){
    if(SDL_VideoModeOK(point[end]->w,point[end]->h,32,commands)){base=point[end]->w;slots=point[end]->h;lb35_log404cb0("...OKAY: wBest="+lb35_int4051f0(base)+", hBest="+lb35_int4051f0(slots));}else lb35_log404cb0("...not supported");
   }else lb35_log404cb0("...dimensions unsuitable");
  }
 }else{lb35_log404cb0("All video modes available");base=tmp;slots=first;}
 switch(renderer){case 0:lb35_log404cb0("Setting software video mode");lb35_cefa80=SDL_SetVideoMode(base,slots,32,commands);break;}
 if(!lb35_cefa80)lb35_fatal404fd0("REX::setVideoMode()","SDL_SetVideoMode() failed: "+string(SDL_GetError()));
 if(fullscreen){offsetx=(lb35_cefa80->w-cols*other)/2;offsety=(lb35_cefa80->h-rows*mode)/2;lb35_log404cb0("Setting fullscreen offset: +"+lb35_int4051f0(offsetx)+",+"+lb35_int4051f0(offsety));}else offsetx=offsety=0;
 SDL_UpdateRect(lb35_cefa80,0,0,0,0);LB35Event event;while(SDL_PollEvent(&event)){}lb35_cefa64->end410e50(2);
}
