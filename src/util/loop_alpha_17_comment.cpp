#include <string>
using std::string;
// File-private ABI views; unknown names and untouched layout are placeholders.
struct LA17Point{int x,y;};struct LA17Item;struct LA17Entity;
struct LA17HI{int id;LA17HI();LA17Item*get9b65b0()const throw();bool null9b65d0()const throw();bool valid9b7230()const throw();};
struct LA17H{int id;LA17Entity*get9b6570()const throw();};
struct LA17Items{int a,b,c,d;LA17Items();~LA17Items();unsigned size9b9260()const throw();LA17HI&at9b81f0(unsigned) throw();const LA17HI&back9b6540()const throw();void push9b80b0(const LA17HI&);};
struct LA17Points{int a,b,c,d;LA17Points();~LA17Points();unsigned size9b9a50()const throw();};
struct LA17Item{int kind4578a0() throw();int type44aec0() throw();int id457820() throw();int score457920() throw();string name571db0(bool,bool);};
struct LA17Entity{char pad[0x134];LA17Items items;LA17Items*inventory45ab00() throw();int count5d15a0(bool);unsigned collect5cb830(LA17Items*);unsigned collect5cb8b0(LA17Items*);const LA17Point&position45a4a0() throw();};
struct LA17AI{LA17H self;void comment5bd7d0();};
struct LA17Speaker{bool can49e120(int) throw();bool say49e250(int,bool,string);};extern LA17Speaker*la17_cefb48;
struct LA17GM{unsigned time470aa0(bool) throw();};extern LA17GM*la17_cefaa8;
struct LA17Mode{int getDepthIndex() throw();};struct LA17ModeH{int id;LA17Mode*get9b7910()const throw();};extern LA17ModeH la17_d1e888;
struct LA17Player{bool item77ffb0(int,bool);};extern LA17Player la17_cf45d8;
struct LA17Scores{int a,b,c,d;int&at9b81f0(unsigned) throw();};extern LA17Scores la17_cf4c28;
// Destination records start with a Point; trailing fields are never accessed here.
struct LA17Destination{LA17Point point;};
struct LA17Destinations{int a,b,c,d;unsigned size9b9260()const throw();LA17Destination*&at9b81f0(unsigned) throw();};
struct LA17Map{LA17H player4630f0() throw();LA17Destinations*dest462e10() throw();bool test463160(const LA17Point&) throw();bool route7168e0(const LA17Point&,const LA17Point&,LA17Entity*,LA17Points*);};extern LA17Map*la17_cefc4c;
extern int la17_cf46a8,la17_cf47b8;extern string la17_d31348[];
string la17_int4051f0(int);void la17_insert9d8fc0(LA17Items*,int,LA17HI);void la17_erase9d6440(LA17Items&,int&);LA17HI la17_random9dafb0(LA17Items&);int la17_distance40a3f0(const LA17Point&,const LA17Point&) throw();
void LA17AI::comment5bd7d0(){
 if(la17_cefb48->can49e120(4))if(la17_cefb48->say49e250(4,true,la17_int4051f0(la17_cefaa8->time470aa0(true)/60)))return;
 if(la17_cefb48&&la17_cefb48->can49e120(9)){
  LA17HI first;
  for(unsigned i=0;i<self.get9b6570()->items.size9b9260();i++)if(self.get9b6570()->items.at9b81f0(i).get9b65b0()->kind4578a0()==3&&self.get9b6570()->items.at9b81f0(i).get9b65b0()->type44aec0()<=3){if(first.null9b65d0()||self.get9b6570()->items.at9b81f0(i).get9b65b0()->score457920()>first.get9b65b0()->score457920())first=self.get9b6570()->items.at9b81f0(i);}
  if(first.valid9b7230()&&first.get9b65b0()->score457920()>la17_d1e888.get9b7910()->getDepthIndex()){
   la17_cf45d8.item77ffb0(first.get9b65b0()->id457820(),0);if(la17_cefb48->say49e250(9,true,first.get9b65b0()->name571db0(false,false)))return;
  }
 }
 if(la17_cefb48->can49e120(10)&&self.get9b6570()->count5d15a0(false)*2<=la17_cefc4c->player4630f0().get9b6570()->count5d15a0(false)){la17_cefb48->say49e250(10,true,"");return;}
 if(la17_cefb48->can49e120(11)&&self.get9b6570()->count5d15a0(false)>=la17_cefc4c->player4630f0().get9b6570()->count5d15a0(false)*2){la17_cefb48->say49e250(11,true,"");return;}
 if(la17_cefb48->can49e120(12)&&la17_cf46a8!=15){la17_cefb48->say49e250(12,true,la17_d31348[la17_cf46a8]);return;}
 if(la17_cefb48->can49e120(13)&&la17_cf47b8!=15&&la17_cf47b8!=16&&la17_cf47b8!=0){la17_cefb48->say49e250(13,true,la17_d31348[la17_cf47b8]);return;}
 if(la17_cefb48->can49e120(14)){
  LA17HI h;LA17Items*first=la17_cefc4c->player4630f0().get9b6570()->inventory45ab00();
  for(unsigned i=0;i<first->size9b9260();i++)if(first->at9b81f0(i).get9b65b0()->kind4578a0()==3&&first->at9b81f0(i).get9b65b0()->type44aec0()<=3&&la17_cf4c28.at9b81f0(first->at9b81f0(i).get9b65b0()->id457820())>=2000){if(h.null9b65d0()||la17_cf4c28.at9b81f0(first->at9b81f0(i).get9b65b0()->id457820())>=la17_cf4c28.at9b81f0(h.get9b65b0()->id457820()))h=first->at9b81f0(i);}
  if(h.valid9b7230()){la17_cefb48->say49e250(14,true,h.get9b65b0()->name571db0(false,false));return;}
 }
 if(la17_cefb48->can49e120(15)){
  int first=0;for(unsigned i=0;i<self.get9b6570()->items.size9b9260();i++)if(self.get9b6570()->items.at9b81f0(i).get9b65b0()->kind4578a0()==0&&self.get9b6570()->items.at9b81f0(i).get9b65b0()->type44aec0()==4)first++;
  if(first>=2){la17_cefb48->say49e250(15,true,la17_int4051f0(first));return;}
 }
 if(la17_cefb48->can49e120(16)){
  int first=0;for(unsigned i=0;i<self.get9b6570()->items.size9b9260();i++)if(self.get9b6570()->items.at9b81f0(i).get9b65b0()->kind4578a0()==1&&self.get9b6570()->items.at9b81f0(i).get9b65b0()->type44aec0()==4)first++;
  if(first>=2){la17_cefb48->say49e250(16,true,la17_int4051f0(first));return;}
 }
 if(la17_cefb48->can49e120(17)){
  int first=0;for(unsigned i=0;i<self.get9b6570()->items.size9b9260();i++)if(self.get9b6570()->items.at9b81f0(i).get9b65b0()->kind4578a0()==3&&self.get9b6570()->items.at9b81f0(i).get9b65b0()->type44aec0()==4)first++;
  if(first>=2){la17_cefb48->say49e250(17,true,la17_int4051f0(first));return;}
 }
 if(la17_cefb48->can49e120(18)){
  LA17Items first;
  if(self.get9b6570()->collect5cb830(&first)){
   LA17Items other;other.push9b80b0(first.at9b81f0(0));
   for(unsigned i=1;i<first.size9b9260();i++){
    LA17HI x=first.at9b81f0(i);
    if(x.get9b65b0()->score457920()<other.back9b6540().get9b65b0()->score457920())other.push9b80b0(x);
    else for(int j=0;j<other.size9b9260();j++)if(x.get9b65b0()->score457920()>=other.at9b81f0(j).get9b65b0()->score457920()){la17_insert9d8fc0(&other,j,x);break;}
   }
   for(int i=0;i<other.size9b9260();i++)for(int j=i+1;j<other.size9b9260();j++)if(other.at9b81f0(i).get9b65b0()->id457820()==other.at9b81f0(j).get9b65b0()->id457820())la17_erase9d6440(other,j);
   if(other.size9b9260()>=2){string text=other.at9b81f0(0).get9b65b0()->name571db0(false,false)+" and "+other.at9b81f0(1).get9b65b0()->name571db0(false,false);la17_cefb48->say49e250(18,true,text);return;}
  }
 }
 if(la17_cefb48->can49e120(19)){
  LA17Items first;if(self.get9b6570()->collect5cb8b0(&first)){la17_cefb48->say49e250(19,true,la17_random9dafb0(first).get9b65b0()->name571db0(false,false));return;}
 }
 if(la17_cefb48->can49e120(20)){
  LA17Items first;if(la17_cefc4c->player4630f0().get9b6570()->collect5cb8b0(&first)){la17_cefb48->say49e250(20,true,la17_random9dafb0(first).get9b65b0()->name571db0(false,false));return;}
 }
 if(la17_cefb48->can49e120(55)){
  LA17Destinations*first=la17_cefc4c->dest462e10();
  for(unsigned i=0;i<first->size9b9260();i++)if(!la17_cefc4c->test463160(first->at9b81f0(i)->point)&&la17_distance40a3f0(self.get9b6570()->position45a4a0(),first->at9b81f0(i)->point)<=25){
   LA17Points firstPath;if(la17_cefc4c->route7168e0(self.get9b6570()->position45a4a0(),first->at9b81f0(i)->point,self.get9b6570(),&firstPath)&&firstPath.size9b9a50()<=25){la17_cefb48->say49e250(55,true,"");return;}
  }
 }
 if(la17_cefb48)la17_cefb48->say49e250(72,false,"");
}
