// NOTE: borrowed Volley render88a000, genuine Console/native HItem and float vector owners.
#include <string>
#include <vector>
// NOTE: genuine complete console prefix; no custom object allocation in renderer.
using namespace std;
struct LC38Point{int x,y;LC38Point()throw();LC38Point(int)throw();LC38Point(int,int)throw();LC38Point(const LC38Point&)throw();};
struct LC38Color{unsigned char r,g,b;LC38Color()throw();LC38Color(int,int,int)throw();LC38Color(const LC38Color&)throw();LC38Color&operator=(LC38Color)throw();};
struct LC38XCell{int font,glyph,value;LC38Color fore,back;};
struct LC38Buffer{int width,height;LC38XCell*data;LC38Buffer();~LC38Buffer();};
struct LC38Event;
struct LC38XConsole{virtual ~LC38XConsole();virtual void resize(int,int);virtual bool active();virtual void refresh();virtual bool input(LC38Event*);virtual void mouse(int,int);virtual void update();virtual void render();
 LC38XConsole*parent;LC38Buffer buffer;int font,fontType;LC38Point position,absolutePosition;LC38Color foreground,background;int backFlag,alignment;float scaleX,scaleY;vector<LC38XConsole*>children;bool hidden;int layer;bool passThrough,ignoreMouse;
 bool isHidden()throw();void clearInterior();void remove(LC38XConsole*);void reset();void fore(LC38Color);void back(LC38Color);void enable(int);void print(int,int,const string&);int width()throw();LC38Point absolute(LC38Point)throw();void row(int,int,int,LC38Color);void rect(int,int,int,int,LC38Color);void put(int,int,int,LC38Color,LC38Color,int);};
struct LC38Engine;struct LC38Title;struct LC38Rect;
struct LC38Console:LC38XConsole{virtual ~LC38Console();virtual void resize(int,int);virtual bool input(LC38Event*);virtual void update();virtual void render();virtual void open();virtual void close();virtual int frameKind();virtual void trigger(const string&,int);int state;LC38Engine*engine;LC38Title*title;LC38Console(LC38XConsole*,int,int,int,int,int,bool,int);void frame(LC38Rect*,LC38Color,bool,bool);void baseRender();void animate48c3f0(string);};
static_assert(sizeof(LC38XCell)==20&&sizeof(LC38XConsole)==0x60&&sizeof(LC38Console)==0x6c,"actual console owners/layout");



struct LC38Item{int range4580a0()throw();int guided4580c0()throw();int energy5788e0();int matter5789c0();};
struct LC38HI{int id;LC38HI()throw();LC38Item*get9b65b0()const throw();bool valid9b7230()const throw();bool null9b65d0()const throw();};
struct LC38HE{int id;LC38HE()throw();struct LC38Entity*get9b6570()const throw();};
struct LC38Entity{LC38Point&position45a4a0()throw();bool ranged5d6c30(vector<LC38HI>*);LC38HI melee5d5d40();int volleyTime5d6d80(vector<LC38HI>*,LC38HE);int heat5d7320(vector<LC38HI>*,bool);int energy45a8d0()throw();int matter45a920()throw();};
struct LC38Map{LC38HE player4630f0()throw();};extern LC38Map*lc38_cefc4c;
struct LC38PathStep;
struct LC38MapView{bool point805190(LC38Point&);bool hasTarget49ab40()throw();int range805360(LC38HE,vector<LC38PathStep>*,LC38Point*);};extern LC38MapView*lc38_cec054;
struct LC38Part:LC38Console{char unknown6c[0x80-0x6c];int key;};struct LC38Parts{LC38Part*find894e70(LC38HI);};extern LC38Parts*lc38_cec088;
struct LC38Engine{void render5100b0();};extern LC38XConsole*lc38_cec070;
extern LC38Color*lc38_d161d4,*lc38_d39294,*lc38_d2981c,*lc38_cfc174,*lc38_d204ac;
extern vector<LC38Color>lc38_d2b4bc;
struct LC38IntList{vector<int>values;LC38IntList();~LC38IntList();int sum40c820()throw();};extern LC38IntList lc38_cfcd20;extern bool lc38_d28d16;
int lc38_distance40a3f0(const LC38Point&,const LC38Point&)throw();bool lc38_adjacent4373c0(const LC38Point&,const LC38Point&)throw();
void lc38_insert9d8fc0(vector<LC38HI>&,int,LC38HI);void lc38_erase9da940(vector<LC38HI>&,int);
string lc38_intToString4051f0(int);
struct LC38Volley:LC38Console{bool unknown6c;int unknown70;bool active74;vector<LC38HI>weapons;bool guided;vector<float>fractions;virtual ~LC38Volley();virtual void render();};
void LC38Volley::render(){
 if(isHidden())return;
 clearInterior();fore(*lc38_d161d4);back(*lc38_d39294);engine->render5100b0();weapons.clear();guided=false;
 if(active74&&lc38_cec070->isHidden()){
  LC38Point target;bool enabled=lc38_cec054->point805190(target);LC38HE player=lc38_cefc4c->player4630f0();if(!player.get9b6570())return;
  int total2=player.get9b6570()->ranged5d6c30(&weapons)?weapons.front().get9b65b0()->guided4580c0():0;
  LC38HI melee;int row=1;if(weapons.empty())melee=player.get9b6570()->melee5d5d40();
  if(weapons.empty()&&melee.null9b65d0()){print(1,row,"No active weapons");fractions.clear();}
  else{
   fractions.clear();int range=0;
   if(melee.valid9b7230())fractions.push_back(-1.0f);
   else{
    for(int i=0;i<weapons.size();i++){if(weapons[i].get9b65b0()->range4580a0()>=range)range=weapons[i].get9b65b0()->range4580a0();}
    fractions.push_back((float)weapons.size());
    for(int i=1;i<=range;i++){fractions.push_back(0.0f);for(int j=0;j<weapons.size();j++){if(weapons[j].get9b65b0()->range4580a0()>=i)fractions.back()+=1.0;}}
    float count=(float)weapons.size();for(int i=0;i<fractions.size();i++){fractions[i]=fractions[i]/count;}
   }
   range=melee.valid9b7230()?-1:lc38_cec054->hasTarget49ab40()?lc38_cec054->range805360(player,0,0):lc38_distance40a3f0(player.get9b6570()->position45a4a0(),target);
   if(melee.valid9b7230())weapons.push_back(melee);
   vector<LC38HI>slots;slots.push_back(weapons[0]);
   for(int i=1;i<weapons.size();i++){int key=lc38_cec088->find894e70(weapons[i])->key;
    if(key>lc38_cec088->find894e70(slots.back())->key)slots.push_back(weapons[i]);
    else{for(int j=0;j<slots.size();j++){if(key<lc38_cec088->find894e70(slots[j])->key){lc38_insert9d8fc0(slots,j,weapons[i]);break;}}}
   }
   weapons=slots;
   string caption="R="+(range==-1?string("Melee"):lc38_intToString4051f0(range))+" [";print(1,row,caption);
   string s;int x=caption.size()+1;
   for(int i=0;i<weapons.size();i++,x++){
    s.clear();LC38Part*part=lc38_cec088->find894e70(weapons[i]);if(part)s+=(unsigned char)part->key;
    if(range!=-1?weapons[i].get9b65b0()->range4580a0()>=range:lc38_adjacent4373c0(player.get9b6570()->position45a4a0(),target))lc38_d2b4bc[0]=*lc38_d2981c;
    else{lc38_d2b4bc[0]=*lc38_cfc174;lc38_erase9da940(weapons,i);i--;}
    print(x,row,"`f"+lc38_intToString4051f0(0)+"`"+s+"`x`");
   }
   print(x,row,string("]"));
   if(total2){x+=2;print(x,row,"GUIDED/WPx"+lc38_intToString4051f0(total2));guided=true;}
   row++;
   if(weapons.size()){
    int time=player.get9b6570()->volleyTime5d6d80(&weapons,LC38HE());
    string description=lc38_d28d16?"Time "+lc38_intToString4051f0(time):"Spd "+lc38_intToString4051f0((int)((double)lc38_cfcd20.sum40c820()/time*100.0))+"%";
    int energy=0,matter=0;for(int i=0;i<weapons.size();i++){energy+=weapons[i].get9b65b0()->energy5788e0();matter+=weapons[i].get9b65b0()->matter5789c0();}
    int heat=player.get9b6570()->heat5d7320(&weapons,false);int factor=time/100;if(factor>0)heat/=factor;
    print(1,row,description);x=description.size()+1;lc38_d2b4bc[0]=*lc38_d204ac;
    description=" E-"+lc38_intToString4051f0(energy);
    if(player.get9b6570()->energy45a8d0()<energy)print(x,row,"`f"+lc38_intToString4051f0(0)+"`"+description+"`x`");else print(x,row,description);x+=description.size();
    description=" M-"+lc38_intToString4051f0(matter);
    if(player.get9b6570()->matter45a920()<matter)print(x,row,"`f"+lc38_intToString4051f0(0)+"`"+description+"`x`");else print(x,row,description);x+=description.size();
    description=" H+"+lc38_intToString4051f0(heat);print(x,row,description);
   }
  }
 }
 baseRender();
}
