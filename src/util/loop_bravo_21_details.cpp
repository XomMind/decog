// Private partial record detail formatter5705b0; arrays remain borrowed.
#include <string>
#include <cstdlib>
using std::string;
struct LB21Color{unsigned char r,g,b;LB21Color(const LB21Color&)throw();LB21Color&operator=(LB21Color)throw();};
struct LB21Explosion{char p0[0x2c];int type,damage,range;};
struct LB21Record{int id;char p4[0x40];int rating,kind;char p4c[4];int value;char p54[0x40];int status;char p98[0xc];int mass;char pa8[0x14];int energy;char pc0[0xc];int heat;char pd0[0x10];int stability;char pe4[0xc];int special,specialValue;char pf8[0x20];int shots;char p11c[4];int minimum,maximum,type;char p12c[0x74];LB21Explosion*explosion;void details5705b0(string&,LB21Color&);};
struct LB21Ints{int a,b,c,d;int&at9b81f0(unsigned)throw();};extern LB21Ints lb21_cf4844;
extern string lb21_d22280[],lb21_d33e38[],lb21_d3a380[],lb21_d323f8[];extern LB21Color lb21_d2ed1c[];
string lb21_int4051f0(int);int lb21_max9cdb60(int,int)throw();
void LB21Record::details5705b0(string&out,LB21Color&color){
 if(rating<6){out.clear();return;}
 if(lb21_cf4844.at9b81f0(id))out+="+";
 if(status)out+=lb21_d22280[status];
 if(status!=3)out+=(value==10?string("X"):lb21_int4051f0(value));
 switch(kind){
 case 0:out+=" M";out+=lb21_int4051f0(mass);out+=" E";out+=lb21_int4051f0(energy);break;
 case 1:out+=" T";out+=lb21_int4051f0(heat);out+=" S";out+=lb21_int4051f0(stability);break;
 case 2:{out+=" M";out+=lb21_int4051f0(mass);string line;
 switch(special){case 0:break;case 46:goto detailDone;case 19:line=lb21_int4051f0(specialValue+1);break;case 152:line=lb21_d33e38[specialValue];break;case 127:line=lb21_int4051f0(abs(specialValue));if(specialValue<0)line+="!";break;default:line=lb21_int4051f0(specialValue);}
 detailDone:
 if(!line.empty())out+=" "+lb21_d3a380[special]+"/"+line;
 break;}
 case 3:{out+=" M";out+=lb21_int4051f0(mass);
 if(explosion){bool active=false;float x=1;int count=lb21_max9cdb60(0,(int)(explosion->damage*x-explosion->range));int first=lb21_max9cdb60(0,(int)(explosion->damage*x+explosion->range));out+=" "+(count!=first?lb21_int4051f0(count)+"-"+lb21_int4051f0(first):lb21_int4051f0(first));color=lb21_d2ed1c[explosion->type];}
 else{bool active=false;float x=1;int count=(int)(minimum*x);int first=(int)(maximum*x);out+=" "+(count!=first?lb21_int4051f0(count)+"-"+lb21_int4051f0(first):lb21_int4051f0(first));color=lb21_d2ed1c[type];}
 if(shots>1)out+="*";else out+=" ";
 string line=lb21_d323f8[explosion?explosion->type:type];if(line.length()==1)line.insert(0,1,' ');out+=line;
 break;}
 }
}
