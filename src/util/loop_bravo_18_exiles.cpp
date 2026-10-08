// Private ABI aliases for Exiles perimeter incident 6df0b0.
#include <string>
using std::string;
struct LB18Entity;struct LB18Prop;struct LB18Item;struct LB18Squad;
struct LB18H {int id;LB18H() throw();bool valid9b7230()const throw();LB18Entity*get9b6570()const throw();};
struct LB18HP {int id;LB18HP() throw();bool valid9b7230()const throw();LB18Prop*get9b64f0()const throw();};
struct LB18HI {int id;LB18Item*get9b65b0()const throw();};
struct LB18HS {int id;LB18Squad*get9b7250()const throw();};
struct LB18Area {int a,b,c,d;LB18Area(int,int,int,int) throw();};
struct LB18TargetRecord;
struct LB18AI {void region459470(const LB18Area&) throw();void mode44bef0(int) throw();LB18TargetRecord*chase5b4710(LB18H,int,int,bool,bool*) throw();};
struct LB18Entity {bool player5c7600() throw();int effect45acb0(int) throw();void remove639730(bool) throw();void faction5dc780(LB18HS,bool) throw();int faction45a2c0() throw();int target45a760() throw();void push5fdab0() throw();LB18AI*ai45b590() throw();const string&name45a280() throw();};
struct LB18Prop {int effect45c800(int) throw();void disable665be0(int) throw();};
struct LB18Item {int effect457b70(int) throw();};
struct LB18Entities {int a,b,c,d;LB18Entities(const LB18Entities&);~LB18Entities();unsigned size9b9260()const throw();LB18H&at9b81f0(unsigned) throw();};
struct LB18Squad {LB18Entities*members416f40() throw();};
struct LB18Squads {int a,b,c,d;LB18HS&at9b81f0(unsigned) throw();};
struct LB18Items {int a,b,c,d;unsigned size9b9260()const throw();LB18HI&at9b81f0(unsigned) throw();};
struct LB18Ints {int a,b,c,d;int&at9b81f0(unsigned) throw();};
struct LB18Props {int a,b,c,d;};
struct LB18Cell {LB18HP prop45d550() throw();LB18H entity45d250() throw();};
struct LB18Grid {int width9b8f10() throw();int height9b8f00() throw();LB18Cell**at(int,int) throw();LB18Area area9b4400() throw();};extern LB18Grid lb18_cfd44c;
struct LB18Map {char p0[0x4c];LB18Squads squads;char p5c[0x390-0x5c];LB18Items items;LB18Ints values;char p3b0[0x4f0-0x3b0];LB18Props props;char p500[0x66c-0x500];LB18H player;void remove465750(LB18H) throw();void dialog6c65a0(LB18H,const string&,bool);void exiles6df0b0(bool);};
struct LB18Data {void set46f700(const string&,const string&);const string&get46f6d0(const string&);};extern LB18Data lb18_d1e860;extern bool lb18_d1eacc;
int lb18_int405610(const string&) throw();bool lb18_remove(LB18Props&,LB18HP) throw();
struct LB18Flag {void set451400(int) throw();};extern LB18Flag lb18_cf1080;extern bool lb18_d28fb0;
int lb18_sound4541b0(unsigned,int,int) throw();bool lb18_route5111e0(int,const string&,const string*,const string*,LB18H,LB18HP,const void*,bool);
bool lb18_phrase5141b0(int,const string*,const string*,const string*,LB18H,int);
struct LB18UI {void update8758d0(bool) throw();};extern LB18UI*lb18_cec058;
struct LB18Log {void end7b4f10() throw();};extern LB18Log*lb18_cec0b4;
struct LB18Xom {bool enabled;void event69e700(int,int,float) throw();};extern LB18Xom lb18_d25450;
void LB18Map::exiles6df0b0(bool){
 lb18_d1e860.set46f700("exiFarcomEnabled_g","0");lb18_d1eacc=false;
 lb18_d1e860.set46f700("exiAttackedLocals_g","1");
 bool active=lb18_int405610(lb18_d1e860.get46f6d0("exiMaincAttacked_g"));
 string line=active?"EXILES: Additional hostile detected within perimeter.":"EXILES: Hostile robot within lab perimeter. Defensive protocols time, folks!";
 do{lb18_cf1080.set451400(true);if(true){if(!(lb18_d28fb0&&true&&!true))lb18_sound4541b0(0x12d,0,0);}do{if(lb18_route5111e0(0x324,line,0,0,LB18H(),LB18HP(),0,false))lb18_cec058->update8758d0(true);lb18_cec0b4->end7b4f10();}while(false);lb18_cec0b4->end7b4f10();}while(false);
 do{lb18_phrase5141b0(0x13a,0,0,0,LB18H(),0);}while(false);
 if(lb18_d25450.enabled)lb18_d25450.event69e700(90,0,0.f);
 for(unsigned i=0;i<items.size9b9260();i++){if(items.at9b81f0(i).get9b65b0()&&items.at9b81f0(i).get9b65b0()->effect457b70(87))values.at9b81f0(i)=5;}
 if(!active){for(int x=0;x<lb18_cfd44c.width9b8f10();x++){for(int y=0;y<lb18_cfd44c.height9b8f00();y++){
 if((*lb18_cfd44c.at(x,y))->prop45d550().valid9b7230()&&!(*lb18_cfd44c.at(x,y))->prop45d550().get9b64f0()->effect45c800(132)){(*lb18_cfd44c.at(x,y))->prop45d550().get9b64f0()->disable665be0(0);lb18_remove(props,(*lb18_cfd44c.at(x,y))->prop45d550());}
 if((*lb18_cfd44c.at(x,y))->entity45d250().valid9b7230()&&!(*lb18_cfd44c.at(x,y))->entity45d250().get9b6570()->player5c7600()&&!(*lb18_cfd44c.at(x,y))->entity45d250().get9b6570()->effect45acb0(132)){remove465750((*lb18_cfd44c.at(x,y))->entity45d250());(*lb18_cfd44c.at(x,y))->entity45d250().get9b6570()->remove639730(true);}
 }}}
 LB18Area group(21,82,67,88);LB18Area type(46,38,98,70);
 LB18Entities list=*squads.at9b81f0(9).get9b7250()->members416f40();
 for(int i=list.size9b9260()-1;i>=0;i--){
 list.at9b81f0(i).get9b6570()->faction5dc780(squads.at9b81f0(5),false);
 if(list.at9b81f0(i).get9b6570()->faction45a2c0()==60&&list.at9b81f0(i).get9b6570()->target45a760()!=6){list.at9b81f0(i).get9b6570()->push5fdab0();list.at9b81f0(i).get9b6570()->ai45b590()->region459470(type);}
 else if(list.at9b81f0(i).get9b6570()->name45a280()=="Zionite"||list.at9b81f0(i).get9b6570()->name45a280()=="EX-BIN"||list.at9b81f0(i).get9b6570()->name45a280()=="EX-DEC"||list.at9b81f0(i).get9b6570()->name45a280()=="EX-HEX"){
 list.at9b81f0(i).get9b6570()->ai45b590()->region459470(group);
 if(list.at9b81f0(i).get9b6570()->name45a280()=="EX-DEC"){dialog6c65a0(list.at9b81f0(i),"EXI_Dec_Retreat_Player",false);dialog6c65a0(list.at9b81f0(i),"EXI_Dec_Death",false);}
 else if(list.at9b81f0(i).get9b6570()->name45a280()=="EX-BIN"){dialog6c65a0(list.at9b81f0(i),"EXI_Bin_Retreat_Player",false);dialog6c65a0(list.at9b81f0(i),"EXI_Bin_Death",false);}
 }else if(list.at9b81f0(i).get9b6570()->name45a280()=="8R-AWN"){
 list.at9b81f0(i).get9b6570()->ai45b590()->mode44bef0(8);list.at9b81f0(i).get9b6570()->ai45b590()->region459470(lb18_cfd44c.area9b4400());list.at9b81f0(i).get9b6570()->ai45b590()->chase5b4710(player,-2,1,false,0);dialog6c65a0(list.at9b81f0(i),"EXI_Brawn_Death",false);
 }
 if(list.at9b81f0(i).get9b6570()->faction45a2c0()==60)list.at9b81f0(i).get9b6570()->ai45b590()->chase5b4710(player,-2,1,false,0);
 }
}
