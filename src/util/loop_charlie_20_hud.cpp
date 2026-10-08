#include <string>
#include <cctype>
using std::string;
// NOTE: private observed retail partial views and address aliases.
struct LC20P{int x,y;LC20P(int,int)throw();LC20P(const LC20P&)throw();};
struct LC20Bounds{int x1,y1,x2,y2;LC20Bounds()throw();};
struct LC20Color{unsigned char r,g,b;LC20Color(const LC20Color&)throw();LC20Color&assign411f10(LC20Color);};
struct LC20Entity{const LC20P&pos45a4a0()throw();int stage5cad50();string situation5c9c30();};
struct LC20H{int id;LC20Entity*get9b6570()const throw();};
struct LC20Map{LC20H player4630f0()throw();};extern LC20Map*lc20_cefc4c;
struct LC20Cell{bool latent45db50()throw();int count45a6e0()throw();};
struct LC20Grid{void bounds9b4430(const LC20P&,int,LC20Bounds&)throw();LC20Cell**at9ceda0(int,int)throw();int width9fcd80()throw();int height9b8f00()throw();};extern LC20Grid lc20_cfd44c;
struct LC20Player{unsigned char special46dd90()throw();bool flag46dd50()throw();};extern LC20Player lc20_cf45d8;
struct LC20Engine{void update5100b0();};
struct LC20Console{virtual~LC20Console();char p4[0x60];LC20Engine*engine;char p68[4];bool hidden4175f0()throw();int width44b0d0()throw();void clear417bf0(int,int,int,int);void fore417b00(LC20Color);void print4181d0(int,int,const string&);void aligned418220(int,int,int,const string&);void render429ea0();};
struct LC20Stats{unsigned char fps41b150()throw();int value9b8f00()throw();};extern LC20Stats*lc20_cefaa0;
struct LC20Colors{LC20Color&at9b3e50(unsigned)throw();};extern LC20Colors lc20_d2b4bc;
extern LC20Color*lc20_cf6b24,*lc20_cfe674,*lc20_d2981c,*lc20_d204ac,*lc20_cf44c0,*lc20_d35bbc,*lc20_d20438;
extern int lc20_cf4614,lc20_cf6428,lc20_cefad8,lc20_d1ec60;
extern unsigned char lc20_cefacd,lc20_cefad4,lc20_cefad5,lc20_cefadc,lc20_cefb11,lc20_cefad2;
extern unsigned lc20_caed20;extern double lc20_cefae0;extern const double lc20_c36cd0;
extern string gameStrings_d38730[];
extern const char lc20_c0136c[],lc20_c01370[],lc20_c01390[],lc20_c01394[];
string intToString(int);string OpY1_rotateText(const string&);int lc20_dist40a3f0(const LC20P&,const LC20P&);
struct LC20Hud:LC20Console{unsigned last;void render883020();};
void LC20Hud::render883020(){
 if(hidden4175f0())return;
 engine->update5100b0();clear417bf0(0,0,width44b0d0(),1);
 if(lc20_cefaa0->fps41b150()){
  string text="FPS    "+intToString(lc20_cefaa0->value9b8f00());fore417b00(*lc20_cf6b24);print4181d0(1,0,text);
 }
 if(lc20_cf45d8.special46dd90()){
  string text=" >>> "+OpY1_rotateText("JVMNEQ")+" <<< ";fore417b00(*lc20_cfe674);
  lc20_d2b4bc.at9b3e50(0).assign411f10(lc20_cf45d8.flag46dd50()?*lc20_d2981c:*lc20_d204ac);
  aligned418220(width44b0d0()-1,0,2,lc20_c01370+intToString(0)+lc20_c0136c+text+"`x`");
 }else if(lc20_cf4614){
  string text=" >>> LOADED "+intToString(lc20_cf4614)+" <<< ";fore417b00(*lc20_cfe674);lc20_d2b4bc.at9b3e50(0).assign411f10(*lc20_cf44c0);
  aligned418220(width44b0d0()-1,0,2,lc20_c01394+intToString(0)+lc20_c01390+text+"`x`");
 }
 if(lc20_cefacd||lc20_cf45d8.flag46dd50()){
  if(lc20_cefad4){fore417b00(*lc20_d35bbc);string text="Presence: "+intToString(lc20_cf6428);print4181d0(1,0,text);}
  else if(lc20_cefad8){
   fore417b00(*lc20_d35bbc);LC20P n(lc20_cefc4c->player4630f0().get9b6570()->pos45a4a0());int entityID=lc20_cefad8;int current=0;LC20Bounds base;
   lc20_cfd44c.bounds9b4430(n,entityID,base);
   for(int x=base.x1;x<=base.x2;x++)for(int y=base.y1;y<=base.y2;y++)if((*lc20_cfd44c.at9ceda0(x,y))->latent45db50()&&lc20_dist40a3f0(n,LC20P(x,y))<=entityID)current+=(*lc20_cfd44c.at9ceda0(x,y))->count45a6e0();
   int x2=0;for(int x=0;x<lc20_cfd44c.width9fcd80();x++)for(int y=0;y<lc20_cfd44c.height9b8f00();y++)if((*lc20_cfd44c.at9ceda0(x,y))->latent45db50())x2+=(*lc20_cfd44c.at9ceda0(x,y))->count45a6e0();
   print4181d0(1,0,string("Latent: ")+intToString(current)+" / "+intToString(x2));
  }else if(lc20_cefad5){fore417b00(*lc20_d35bbc);print4181d0(1,0,string("QKills: ")+intToString(lc20_d1ec60));}
  else if(lc20_cefadc){fore417b00(*lc20_d35bbc);print4181d0(1,0,"Pitch: "+intToString((int)(lc20_cefae0*lc20_c36cd0)));}
  else if(lc20_cefb11){fore417b00(*lc20_d20438);string text(gameStrings_d38730[lc20_cefc4c->player4630f0().get9b6570()->stage5cad50()]);print4181d0(1,0,"SIEGE: "+text);}
  else if(lc20_caed20>last+5000){if(lc20_cefad2){fore417b00(*lc20_d20438);string text=lc20_cefc4c->player4630f0().get9b6570()->situation5c9c30();toupper(text[0]);print4181d0(1,0,"SITUATION: "+text);}last=lc20_caed20;}
 }
 render429ea0();
}
