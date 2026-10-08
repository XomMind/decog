// Private partial Config/color-filter views; method names are reconstruction aliases.
// Configuration fields at128/138 are16-byte filter vectors; filter value is16 bytes.
#include <string>
using std::string;
struct LA11Strings {unsigned a,b,c,d;LA11Strings() throw();~LA11Strings() throw();unsigned size()const throw();string&operator[](unsigned) throw();string&front() throw();void push_back(const string&);};
struct LA11Color {unsigned char r,g,b;LA11Color(const LA11Color&) throw();void set(unsigned char,unsigned char,unsigned char) throw();};
struct LA11Filter {int type,amount;float value;LA11Color color;LA11Filter() throw();};
struct LA11Filters {unsigned a,b,c,d;void clear() throw();void push_back(const LA11Filter&);LA11Filters &operator=(const LA11Filters&);};
struct LA11Config {char pad[0x128];LA11Filters first,second;void init(int,string);};
void la11_split(const string&,char,LA11Strings*);int la11_find(const string*,unsigned,string) throw();int la11_int(const string&) throw();float la11_float(const string&) throw();int la11_clamp(int,int,int) throw();void la11_color(LA11Color) throw();void la11_error(string,string);void la11_warn(string,string);
extern string gameStrings_d39468[],configOptionNames[];extern bool la11_bb6d34[];extern int la11_bb6d0c[];extern LA11Filters la11_d1d45c;
void LA11Config::init(int id,string value) {
 LA11Filters *p=&(id==77?first:second);p->clear();LA11Strings items;la11_split(value,'|',&items);
 for(unsigned i=0;i<items.size();i++) {
  LA11Strings vec;int type;unsigned found2=items[i].find('(');
  if(found2!=string::npos) {
   la11_split(string(static_cast<const string&>(items[i]).begin()+found2+1,static_cast<const string::const_iterator&>(items[i].end()-1)),',',&vec);
   items[i].erase(items[i].begin()+found2,items[i].end());
  }
  type=la11_find(gameStrings_d39468,10,items[i]);
  if(type==-1)la11_error("Config::init()","unknown colorFilterConfigType: "+items[i]);
  else if(!la11_bb6d34[type]&&id==77)la11_warn("Config::init()","colorFilterConfigType "+items[i]+" incompatible with "+configOptionNames[77]);
  else {
   switch(type) {
    case 8:type=3;vec.push_back("47");vec.push_back("30");vec.push_back("31");break;
    case 9:type=3;vec.push_back("13");vec.push_back("24");vec.push_back("33");break;
   }
   LA11Filter layer;layer.type=type;
   switch(la11_bb6d0c[layer.type]) {
    case 1:layer.amount=la11_int(vec.front());break;
    case 2:layer.value=la11_float(vec.front())/100.0;break;
    case 3:layer.color.set(la11_clamp(0,la11_int(vec[0]),255),la11_clamp(0,la11_int(vec[1]),255),la11_clamp(0,la11_int(vec[2]),255));break;
   }
   if(layer.type==3)la11_color(layer.color);
   if(layer.type==5) {
    if(layer.amount==0)layer.amount=360;
    else if(layer.amount<0){do{layer.amount+=360;}while(layer.amount<1);}
    else if(layer.amount>360){do{layer.amount-=360;}while(layer.amount>360);}
   }
   p->push_back(layer);
  }
 }
 if(id==78)la11_d1d45c=*p;
}
