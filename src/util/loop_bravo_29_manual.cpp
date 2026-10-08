// NOTE: private partial layouts and external call-site aliases for shell manual render90a360.
#include <string>
#include <vector>
using namespace std;
struct LB29Point{int x,y;LB29Point(int,int)throw();LB29Point(const LB29Point&)throw();};
struct LB29Color{unsigned char r,g,b;LB29Color()throw();LB29Color(int,int,int)throw();LB29Color(const LB29Color&)throw();LB29Color&operator=(LB29Color)throw();};
struct LB29XCell{int font,glyph,value;LB29Color fore,back;};
struct LB29Buffer{int width,height;LB29XCell*data;LB29Buffer();~LB29Buffer();};
struct LB29Event;
struct LB29XConsole{virtual ~LB29XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LB29Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LB29XConsole*parent;LB29Buffer buffer;int font,fontType;LB29Point position,absolutePosition;LB29Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LB29XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 void remove(LB29XConsole*);void reset();void fore(LB29Color);void back(LB29Color);void enable(int);void print(int,int,const string&);int width()throw();LB29Point absolute(LB29Point)throw();void row(int,int,int,LB29Color);void rect(int,int,int,int,LB29Color);void put(int,int,int,LB29Color,LB29Color,int);};
struct LB29Engine;struct LB29Title;struct LB29Rect;
struct LB29Console:LB29XConsole{virtual ~LB29Console();virtual void resize(int,int);virtual bool input(LB29Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LB29Engine*engine;LB29Title*title;LB29Console(LB29XConsole*,int,int,int,int,int,bool,int);void frame(LB29Rect*,LB29Color,bool,bool);void baseRender();};
static_assert(sizeof(LB29XCell)==20&&sizeof(LB29XConsole)==0x60&&sizeof(LB29Console)==0x6c,"actual console owners/layout");
struct LB29Text:public LB29Console{const string&text()throw();int width()throw();};
struct LB29Data{char pad[0xf8];int kind;};struct LB29Prop{LB29Data*data()throw();};struct LB29H{int id;LB29Prop*operator->()const throw();};struct LB29Shell{LB29H prop()throw();};extern LB29Shell*lb29_manualShell;
struct LB29Record{char pad[0x24];string name;};extern vector<LB29Record*>lb29_manualRecords;extern vector<unsigned> lb29_manualNames,lb29_manualRecordNames;extern vector<int> lb29_manualKnown;extern string gameStrings_d2d508[],lb29_manualItemTemplate_d2d524;
extern LB29Color *lb29_manualSpecialFore,*lb29_manualSpecialHint,*lb29_manualFore,*lb29_manualHint,*lb29_manualRow,*lb29_manualFrame,*lb29_manualSelected,*lb29_manualUnknown,*lb29_manualNormal;extern LB29Color lb29_manualBlack;
extern bool lb29_manualDisabled;extern const unsigned lb29_manualNpos;extern unsigned lb29_manualClock;
struct LB29Keys{LB29XConsole*focused() throw();};extern LB29Keys*lb29_manualKeys;
struct LB29Screen{int height()throw();};extern LB29Screen lb29_manualScreen;
void lb29_manualStrip(string&,bool);bool opy7_compareNames8b2b40(string&,string&);void lb29_manualSort(vector<string>::iterator,vector<string>::iterator,bool(*)(string&,string&));
class LB29Manual:public LB29Console{public:LB29Text*input;vector<unsigned>names;string current;vector<unsigned>matches;unsigned matchIndex;vector<unsigned>items;unsigned itemIndex;LB29Console*suggestions;void suggest();void render();};
#define MBEGIN(S) (S).begin()
void LB29Manual::render(){
 LB29Color point,b;
 if(lb29_manualShell->prop()->data()->kind==6){point=*lb29_manualSpecialFore;b=*lb29_manualSpecialHint;}else{point=*lb29_manualFore;b=*lb29_manualHint;}
 if(suggestions){remove(suggestions);suggestions=0;}
 reset();fore(point);back(lb29_manualBlack);enable(1);print(0,0,string(2,'>'));
 string x=input->text();print(2,0,x);
 if(!lb29_manualDisabled){
  suggest();
  if(!current.empty()){
   unsigned count=current.find('(',0);unsigned p=0;vector<string>i;
   if(!matches.empty()){
    string a=gameStrings_d2d508[lb29_manualNames[matches[matchIndex]]];
    lb29_manualStrip(a,current.find('(',0)!=lb29_manualNpos);
    a.erase(MBEGIN(a),MBEGIN(a)+input->text().size());
    if(!a.empty()){
     x+=a;fore(b);print(input->width()+2,0,a);
     if(matches.size()>1&&current.find('(',0)!=lb29_manualNpos){
      for(unsigned j=0;j<matches.size();j++){
       a=gameStrings_d2d508[lb29_manualNames[matches[j]]];lb29_manualStrip(a,true);
       a.erase(MBEGIN(a),MBEGIN(a)+count+1);a.pop_back();i.push_back(a);
      }
      lb29_manualSort(i.begin(),i.end(),opy7_compareNames8b2b40);
      for(unsigned j=0;j<i.size();j++)if(i[j].size()+1>p)p=i[j].size()+1;
      a=gameStrings_d2d508[lb29_manualNames[matches[matchIndex]]];
      a.erase(MBEGIN(a),MBEGIN(a)+count+1);
      if(a.size()>p)p=a.size();p+=2;
     }
    }
   }else if(!items.empty()){
    string a=lb29_manualItemTemplate_d2d524;
    lb29_manualStrip(a,true);a+=lb29_manualRecords[lb29_manualRecordNames[items[itemIndex]]]->name;a+=")";
    p=a.size()-1-a.find('(',0);
    a.erase(MBEGIN(a),MBEGIN(a)+input->text().size());
    if(!a.empty()){
     x+=a;fore(b);print(input->width()+2,0,a);
     if(items.size()>14){fore(b);print(x.size()+2,0," (15+)");}
     else{
      for(unsigned j=0;j<items.size();j++){a=lb29_manualRecords[lb29_manualRecordNames[items[j]]]->name;i.push_back(a);}
      for(unsigned j=0;j<i.size();j++)if(i[j].size()+1>p)p=i[j].size()+1;
      a=lb29_manualRecords[lb29_manualRecordNames[items[itemIndex]]]->name;p+=2;
     }
    }
   }
   if(i.size()>1){
    unsigned record=matches.empty()?itemIndex:matchIndex;
    int w=i.size()+3;bool text=absolute(LB29Point(0,0)).y+w-2<lb29_manualScreen.height();
    suggestions=new LB29Console(this,p,w,count+2,text?-1:-w+2,0,false,-1);
    suggestions->row(0,text?1:w-2,p-1,*lb29_manualRow);
    suggestions->frame(0,*lb29_manualFrame,true,false);
    suggestions->rect(1,text?2:1,p-2,w-3,LB29Color(0,32,0));
    for(unsigned j=0,n=text?2:1;j<i.size();j++,n++){
     if(j==record)suggestions->fore(*lb29_manualSelected);
     else if(matches.empty()&&lb29_manualKnown[lb29_manualRecordNames[items[j]]])suggestions->fore(*lb29_manualUnknown);
     else suggestions->fore(*lb29_manualNormal);
     suggestions->print(1,n,i[j]);
    }
   }
  }
 }
 x.empty();
 // AGENTS.md register-rotation idiom, zero emitted runtime code.
 if(false){}
 if(lb29_manualKeys->focused()==input&&(lb29_manualClock/500)%2&&input->width()+2<width())put(input->width()+2,0,170,point,lb29_manualBlack,true);
 baseRender();
}
