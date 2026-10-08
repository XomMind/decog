// NOTE: Shell addNew90d550 draft: observed mutable input/full integer mirror count.
#include <string>
#include <vector>
// NOTE: genuine complete console prefix; no custom object allocation in renderer.
using namespace std;
struct LC39Point{int x,y;LC39Point()throw();LC39Point(int)throw();LC39Point(int,int)throw();LC39Point(const LC39Point&)throw();};
struct LC39Color{unsigned char r,g,b;LC39Color()throw();LC39Color(int,int,int)throw();LC39Color(const LC39Color&)throw();LC39Color&operator=(LC39Color)throw();};
struct LC39XCell{int font,glyph,str;LC39Color fore,back;};
struct LC39Buffer{int width,height;LC39XCell*data;LC39Buffer();~LC39Buffer();};
struct LC39Event;
struct LC39XConsole{virtual ~LC39XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LC39Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LC39XConsole*parent;LC39Buffer buffer;int font,fontType;LC39Point position,absolutePosition;LC39Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LC39XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 bool isHidden()throw();void clearInterior();void remove(LC39XConsole*);void reset();void fore(LC39Color);void back(LC39Color);void enable(int);void print(int,int,const string&);int width()throw();LC39Point absolute(LC39Point)throw();void row(int,int,int,LC39Color);void rect(int,int,int,int,LC39Color);void put(int,int,int,LC39Color,LC39Color,int);int height()throw();int getChar(int,int);string getString(const LC39Point&,unsigned);void clear();void setChar(int,int,int);void setFore(int,int,LC39Color);int printWrapped(int,int,int,int,const string&);};
struct LC39Engine;struct LC39Title;struct LC39Rect{int x,y,w,h;LC39Rect(int,int,int,int)throw();};
struct LC39Console:LC39XConsole{virtual ~LC39Console();virtual void resize(int,int);virtual bool input(LC39Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LC39Engine*engine;LC39Title*title;LC39Console(LC39XConsole*,int,int,int,int,int,bool,int);void frame(LC39Rect*,LC39Color,bool,bool);void baseRender();void animate48c3f0(string);};
static_assert(sizeof(LC39XCell)==20&&sizeof(LC39XConsole)==0x60&&sizeof(LC39Console)==0x6c,"actual console owners/layout");




struct LC39Def;
struct LC39Button:LC39Console{LC39Def*other;bool unknown70,unknown71,unknown72;int digit;LC39Button(LC39XConsole*,const LC39Rect&,string&,LC39Def*,bool,bool);virtual~LC39Button();};
struct LC39Text:LC39Console{int type;vector<LC39Button*>buttons;LC39Text(LC39XConsole*,const string&,int);virtual~LC39Text();void emphasis90b850(bool);void add4b0be0(LC39Button*);};
struct LC39PropDef{char unknown0[0xf8];int level;};struct LC39Data{char unknown0[0x10];bool locked;};
struct LC39Prop{LC39PropDef*def4174c0();LC39Data*data45cb30();};struct LC39HP{int id;LC39Prop*get9b64f0();};
struct LC39Machine{LC39HP prop4b1460();};extern LC39Machine*lc39_cec0f8;
struct LC39Ref{int unknown0;LC39Def*other;};struct LC39Def{char unknown0[0xb0];vector<LC39Ref*>refs;};extern vector<LC39Def*>lc39_d35b58;
struct LC39Catalog{int unknown0;bool flag;LC39Def*def;};extern vector<LC39Catalog*>lc39_d02cb4;
struct LC39HE{int id;LC39HE()throw();};
bool lc39_message5111e0(int,const string*,const string*,const string*,LC39HE,LC39HE,const LC39Point*,bool);
struct LC39MapBubble{void bubble8758d0(bool);};extern LC39MapBubble*lc39_cec058;
struct LC39Log{void end7b4f10();};extern LC39Log*lc39_cec0b4;
string lc39_replace510110(string&,bool*);string lc39_int4051f0(int);void lc39_error404f10(string,string);bool lc39_truncate408220(string&,unsigned,int);
extern int lc39_bcd8f8[],lc39_cf4738;extern bool lc39_d28e75,lc39_d28c8a;extern string lc39_d2ed44,lc39_d2f26c;extern LC39Color*lc39_cfe674;
struct LC39Shell:LC39Console{int unknown6c;LC39HP prop;vector<LC39Text*>lines;int scrollOffset;LC39XConsole*mirror;vector<LC39Text*>multi;int unknown9c,digit;void scroll90d0a0(int);void addNew(string&,const string&,int,int,int);};
static_assert(sizeof(LC39Text)==128&&sizeof(LC39Button)==120,"retail allocated complete native owners");
#define B39(txt,kind) do{if(lc39_message5111e0(kind,&txt,0,0,LC39HE(),LC39HE(),0,false))lc39_cec058->bubble8758d0(true);lc39_cec0b4->end7b4f10();}while(false)
void LC39Shell::addNew(string&primary,const string&message,int type,int index,int skipMirrorLines){
 mirror->clear();
 if(!primary.empty()){
 primary.insert(primary.begin(),2,'>');lc39_truncate408220(primary,46,0);lines.push_back(new LC39Text(this,primary,0));lines.back()->emphasis90b850(true);lines.push_back(0);
 }
 string text=lc39_replace510110(string(message),0);
 if(lc39_bcd8f8[type]!=-1){
  if(!primary.empty()){B39(primary,0x202);}
  if(skipMirrorLines==0){B39(text,lc39_bcd8f8[type]);}
  else{string trimmed=text;for(int i=0;i<skipMirrorLines;i++){unsigned found=trimmed.find('\n',0);if(found==string::npos){if(trimmed.size()<=46)break;lc39_error404f10("CShell::addNew()","skipMirrorLines too large!");break;}trimmed.erase(trimmed.begin(),trimmed.begin()+found+1);}B39(trimmed,lc39_bcd8f8[type]);}
 }
 LC39Def*other=type==1&&index!=-1?lc39_d35b58[index]:0;int size;
 if(other&&(lc39_cec0f8->prop4b1460().get9b64f0()->def4174c0()->level>=6||lc39_cec0f8->prop4b1460().get9b64f0()->data45cb30()->locked)){
  string stripped=text;for(int i=0;i<stripped.size();i++){if(stripped[i]==lc39_d2ed44[0]||stripped[i]==lc39_d2f26c[0]){stripped.erase(stripped.begin()+i);i--;}}
  size=mirror->printWrapped(0,0,46,9999,stripped);
 }else{
  if(other&&!other->refs.empty()){
   if(lc39_d28e75){int r=-1;for(int i=0;i<text.size();i++){if(text[i]==lc39_d2ed44[0]){r++;LC39Def*ref=other->refs[r]->other;for(int j=0;j<lc39_d02cb4.size();j++){if(lc39_d02cb4[j]->def==ref){if(!lc39_d02cb4[j]->flag){text.insert(text.begin()+i+1,'!');i++;}break;}}}}}
   if(lc39_d28c8a){for(int i=0;i<text.size();i++){if(text[i]==lc39_d2f26c[0]){int num=digit+1;if(num==11)num=1;string str=lc39_int4051f0(num!=10?num:0);text.insert(text.begin()+i,str.begin(),str.end());text.insert(text.begin()+i,2,'>');
    if(!multi.empty()){for(int j=multi.size()-1;j>=0;j--){if(multi[j])for(int k=0;k<multi[j]->buttons.size();k++)if(multi[j]->buttons[k]->digit==num){multi[j]->buttons[k]->digit=-2;goto replaced;}}}
    if(lines.size()>1){for(int j=lines.size()-2;j>=0;j--){if(lines[j])for(int k=0;k<lines[j]->buttons.size();k++)if(lines[j]->buttons[k]->digit==num){lines[j]->buttons[k]->digit=-2;lines[j]->buttons[k]->setChar(lines[j]->buttons[k]->width()-2,0,32);lines[j]->buttons[k]->setFore(lines[j]->buttons[k]->width()-2,0,*lc39_cfe674);goto replaced;}}}
   replaced:i+=3;digit=num;
   }}}
  }
  size=mirror->printWrapped(0,0,46,9999,text);
 }
 string row;int begin=lines.size();for(int i=0;i<size;i++){row=mirror->getString(LC39Point(0,i),46);lines.push_back(new LC39Text(this,row,type));if(size==1)lines.back()->emphasis90b850(true);else multi.push_back(lines.back());}
 if(other&&prop.get9b64f0()->def4174c0()->level<6&&!prop.get9b64f0()->data45cb30()->locked&&lc39_cf4738==0){
  int n=0,rows=other->refs.size();int parts=-1;bool found=false;int oldValue;
  for(int i=begin;i<lines.size()&&n<rows;i++){for(int x=0;x<lines[i]->width();x++){
   if(lines[i]->getChar(x,0)!=32)oldValue=x;
   if(lines[i]->getChar(x,0)==lc39_d2ed44[0])parts=x;
   else if(lines[i]->getChar(x,0)==lc39_d2f26c[0]){lines[i]->add4b0be0(new LC39Button(lines[i],LC39Rect(parts,0,x-parts+1,1),lines[i]->getString(LC39Point(parts,0),x-parts+1),other->refs[n]->other,!found,true));n++;parts=-1;found=false;}
   else if(x==lines[i]->width()-1){if(parts!=-1){lines[i]->add4b0be0(new LC39Button(lines[i],LC39Rect(parts,0,oldValue-parts+1,1),lines[i]->getString(LC39Point(parts,0),oldValue-parts+1),other->refs[n]->other,true,false));found=true;parts=-1;}}
   else if(x==0&&found)parts=0;
  }}
  if(n<rows){lc39_error404f10("CShell::addNew()","Only found "+lc39_int4051f0(n)+" references out of "+lc39_int4051f0(rows));return;}
 }
 lines.push_back(0);if(lines.size()>=height()-1)scrollOffset=lines.size()-(height()-1);scroll90d0a0(0);
}
