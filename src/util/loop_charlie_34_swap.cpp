// NOTE: private borrowed Part/Parts views, true Console prefix and native PhraseText owners for swap89adf0.
#include <string>
#include <vector>
// NOTE: genuine complete console prefix; only PhraseText objects allocated here.
using namespace std;
struct LC34Point{int x,y;LC34Point(int)throw();LC34Point(int,int)throw();LC34Point(const LC34Point&)throw();};
struct LC34Color{unsigned char r,g,b;LC34Color()throw();LC34Color(int,int,int)throw();LC34Color(const LC34Color&)throw();LC34Color&operator=(LC34Color)throw();};
struct LC34XCell{int font,glyph,value;LC34Color fore,back;};
struct LC34Buffer{int width,height;LC34XCell*data;LC34Buffer();~LC34Buffer();};
struct LC34Event;
struct LC34XConsole{virtual ~LC34XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LC34Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LC34XConsole*parent;LC34Buffer buffer;int font,fontType;LC34Point position,absolutePosition;LC34Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LC34XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 void remove(LC34XConsole*);void reset();void fore(LC34Color);void back(LC34Color);void enable(int);void print(int,int,const string&);int width()throw();LC34Point absolute(LC34Point)throw();void row(int,int,int,LC34Color);void rect(int,int,int,int,LC34Color);void put(int,int,int,LC34Color,LC34Color,int);};
struct LC34Engine;struct LC34Title;struct LC34Rect;
struct LC34Console:LC34XConsole{virtual ~LC34Console();virtual void resize(int,int);virtual bool input(LC34Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LC34Engine*engine;LC34Title*title;LC34Console(LC34XConsole*,int,int,int,int,int,bool,int);void frame(LC34Rect*,LC34Color,bool,bool);void baseRender();void animate48c3f0(string);};
static_assert(sizeof(LC34XCell)==20&&sizeof(LC34XConsole)==0x60&&sizeof(LC34Console)==0x6c,"actual console owners/layout");


struct LC34Item{int slots4578c0()throw();bool multi4578e0()throw();string name571db0(bool,bool);};
struct LC34HI{int id;LC34HI()throw();bool valid9b7230()const throw();bool null9b65d0()const throw();bool equal9b78e0(LC34HI)const throw();bool different9b6510(LC34HI)const throw();void clear9b7270()throw();LC34Item*get9b65b0()const throw();};
struct LC34HE{int id;LC34HE()throw();};
struct LC34Source;struct LC34Phrase{LC34Source*source;string text;LC34Phrase(int,string*,string*,string*,LC34HE,LC34HE);~LC34Phrase();};
struct LC34Messages{void add7b1880(LC34Phrase*);};extern LC34Messages*lc34_cec0f4;
void lc34_warn7b1750(int,const string*,const string*,const string*,LC34HE,LC34HE,const LC34Point*);
struct LC34Part:LC34Console{LC34HI item;bool continuation;LC34HI other;bool flagged;int type,key;void refresh4a9120();};
int lc34_find9d4660(vector<LC34Part*>&,LC34Part*);
struct LC34Parts:LC34Console{char unknown6c[8];vector<LC34Part*>parts;char unknown84[0xac-0x84];int selectedKey;int index8a0df0(int);void remove8979b0(LC34HI,bool,int);void insert897290(LC34HI,int);void swap89adf0(LC34Part*);};
static_assert(sizeof(LC34Phrase)==32,"native phrase owner");
void LC34Parts::swap89adf0(LC34Part*part){
 if(selectedKey==32){if(part->item.valid9b7230()){selectedKey=part->key;lc34_cec0f4->add7b1880(new LC34Phrase(110,0,0,0,LC34HE(),LC34HE()));}return;}
 if(selectedKey==part->key){lc34_cec0f4->add7b1880(new LC34Phrase(111,0,0,0,LC34HE(),LC34HE()));}
 else{
  int index=index8a0df0(selectedKey);
  if(part->type!=parts[index]->type){lc34_cec0f4->add7b1880(new LC34Phrase(112,0,0,0,LC34HE(),LC34HE()));}
  else if(part->item.equal9b78e0(parts[index]->item)){lc34_cec0f4->add7b1880(new LC34Phrase(111,0,0,0,LC34HE(),LC34HE()));}
  else{
   bool found=true;int key=32,base=32;
   if((part->item.valid9b7230()&&part->item.get9b65b0()->multi4578e0())||(parts[index]->item.valid9b7230()&&parts[index]->item.get9b65b0()->multi4578e0())){
    if(part->item.null9b65d0()||parts[index]->item.null9b65d0()){
     if(part->other.valid9b7230()||parts[index]->other.valid9b7230()){lc34_cec0f4->add7b1880(new LC34Phrase(115,0,0,0,LC34HE(),LC34HE()));found=false;}
     else{
      int first=part->item.null9b65d0()?lc34_find9d4660(parts,part):index;
      int type=part->item.null9b65d0()?parts[index]->item.get9b65b0()->slots4578c0():part->item.get9b65b0()->slots4578c0();
      int idx=0;
      for(int i=first;i<parts.size()&&parts[i]->type==part->type;i++){
       if((parts[i]->item.null9b65d0()||parts[i]->item.equal9b78e0(parts[index]->item))&&parts[i]->other.null9b65d0())idx++;else break;
      }
      if(idx<type){int before=0;for(int i=first-1;i>=0&&parts[i]->type==part->type;i--){
       if((parts[i]->item.null9b65d0()||parts[i]->item.equal9b78e0(parts[index]->item))&&parts[i]->other.null9b65d0())before++;else break;
      }
       if(idx+before>=type){if(part->item.valid9b7230())base=parts[index]->key-(type-idx);else key=part->key-(type-idx);idx=type;}
      }
      if(idx<type){lc34_cec0f4->add7b1880(new LC34Phrase(116,0,0,0,LC34HE(),LC34HE()));found=false;}
     }
    }else if(part->item.get9b65b0()->slots4578c0()==parts[index]->item.get9b65b0()->slots4578c0()){
     int first=lc34_find9d4660(parts,part);while(parts[first]->continuation)first--;part=parts[first];while(parts[index]->continuation)index--;
    }else{
     int source=lc34_find9d4660(parts,part);while(parts[source]->continuation)source--;part=parts[source];while(parts[index]->continuation)index--;
     if((source==0||parts[source-1]->item.different9b6510(parts[index]->item))&&(source==parts.size()-1||parts[source+1]->item.different9b6510(parts[index]->item))&&(index==0||parts[index-1]->item.different9b6510(parts[source]->item))&&(index==parts.size()-1||parts[index+1]->item.different9b6510(parts[source]->item))){lc34_cec0f4->add7b1880(new LC34Phrase(116,0,0,0,LC34HE(),LC34HE()));found=false;}
     bool adjacent=(index!=parts.size()-1&&parts[index+1]->item.equal9b78e0(parts[source]->item))||(source>0&&parts[source-1]->item.equal9b78e0(parts[index]->item));
     if(adjacent)key=parts[index]->key+parts[source]->item.get9b65b0()->slots4578c0();else base=parts[source]->key+parts[index]->item.get9b65b0()->slots4578c0();
    }
   }
   if(found){
    int source=lc34_find9d4660(parts,part);LC34HI item=parts[index]->item;LC34HI other=parts[source]->item;
    if(item.equal9b78e0(other))other.clear9b7270();
    if((item.valid9b7230()||other.valid9b7230())&&parts[index]!=parts[source]){
     for(int i=index,j=source;i<parts.size()&&j<parts.size()&&parts[i]->item.equal9b78e0(parts[index]->item);i++,j++){
      if(parts[i]->other.null9b65d0()&&parts[j]->other.valid9b7230()&&parts[j]->item.null9b65d0()){parts[i]->other=parts[j]->other;parts[j]->other.clear9b7270();}
     }
     vector<LC34HI>first;
     for(int i=index;i<parts.size()&&parts[i]->item.equal9b78e0(parts[index]->item);i++){first.push_back(parts[i]->other);parts[i]->other.clear9b7270();if(item.null9b65d0())break;}
     vector<LC34HI>second;
     for(int i=source;i<parts.size()&&parts[i]->item.equal9b78e0(parts[source]->item);i++){second.push_back(parts[i]->other);parts[i]->other.clear9b7270();if(other.null9b65d0())break;}
     int secondStart=key==32?parts[source]->key:key;int firstStart=base==32?parts[index]->key:base;
     if(item.valid9b7230())remove8979b0(item,true,0);if(other.valid9b7230())remove8979b0(other,true,0);part=0;
     if(item.valid9b7230())insert897290(item,key==32?parts[source]->key:key);
     if(other.valid9b7230())insert897290(other,base==32?parts[index]->key:base);
     for(int j=0,i=secondStart-97;j<first.size();j++,i++){parts[i]->other=first[j];if(parts[i]->other.valid9b7230())parts[i]->refresh4a9120();}
     for(int j=0,i=firstStart-97;j<second.size();j++,i++){parts[i]->other=second[j];if(parts[i]->other.valid9b7230())parts[i]->refresh4a9120();}
     string text;text+=(unsigned char)(key==32?parts[source]->key:key);
     lc34_warn7b1750(117,(item.valid9b7230()?&item.get9b65b0()->name571db0(false,false):&string("Unused")),&text,0,LC34HE(),LC34HE(),0);
    }
   }
  }
 }
 selectedKey=32;
}
