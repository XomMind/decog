// NOTE: placeholder names and partial layouts; private aliases preserve nothrow inference.
class TB8Item {
public:
 int current_9b6bf0() throw();
 int maximum_457c80() throw();
 void add_458360(int) throw();
};
class TB8ItemHandle {
public:
 int id;
 TB8Item *get_9b65b0() throw();
};
class TB8Items {
public:
 int a,b,c,d;
 unsigned size_9b9260() const throw();
 TB8ItemHandle &at_9b81f0(unsigned) throw();
};
class TB8EntityData {
public:
 int size_9b4350() const throw();
};
class TB8DataHandle {
public:
 int id;
 TB8EntityData *get_9b7250() throw();
};
class TB8Map {
public:
 int turn_464270() throw();
 float rate_7163d0(int,int) throw();
};
extern TB8Map *tb8_map_cefc4c;
int tb8_max_9cdb60(int,int) throw();
class TB8Entity {
public:
 char pad00[0x28];
 TB8DataHandle data;
 int turn;
 char pad30[0x8c-0x30];
 int current;
 char pad90[0x134-0x90];
 TB8Items items;
 int effect_5d22a0(int) throw();
 int maximum_5ca260() throw();
 void add_5de870(int,int) throw();
 void regenerate_63d700();
};
void TB8Entity::regenerate_63d700() {
 if ((tb8_map_cefc4c->turn_464270()-turn)%2==0) {
  float factor=tb8_map_cefc4c->rate_7163d0(data.get_9b7250()->size_9b4350(),0)*2;
  int bonus=effect_5d22a0(200);
  if (bonus) factor*=bonus;
  if (current<maximum_5ca260()) add_5de870(tb8_max_9cdb60(1,(int)(maximum_5ca260()*factor/100.0)),0);
  for(unsigned i=0;i<items.size_9b9260();i++) {
   if(items.at_9b81f0(i).get_9b65b0()->current_9b6bf0()<items.at_9b81f0(i).get_9b65b0()->maximum_457c80())
    items.at_9b81f0(i).get_9b65b0()->add_458360(tb8_max_9cdb60(1,(int)(items.at_9b81f0(i).get_9b65b0()->maximum_457c80()*factor/100.0)));
  }
 }
}
