// NOTE: private borrowed Map/World/Cell/Entity/Item/Group views; names are placeholders.
// Allocated records are genuine20B values; native vectors own pointer buffers and explicit delete releases their records.
// Prefix byte ranges below are only borrowed views, never allocated or sized as complete game objects.
#include <vector>
using namespace std;
struct D40Point{int x,y;D40Point();D40Point(int);D40Point(int,int)throw();D40Point(const D40Point&)throw();};
D40Point::D40Point(int v):x(v),y(v){}
struct D40Area{D40Point min,max;D40Area();D40Area(const D40Point&,const D40Point&);bool containsXY40b700(int,int);bool contains40b750(const D40Point&);};
struct D40Color{unsigned char r,g,b;D40Color(const D40Color&)throw();};
class D40Entity;class D40Item;class D40Group;
struct D40HE{unsigned int id;D40HE()throw();bool valid9b7230()const;D40Entity*get9b6570()const throw();};
struct D40HI{unsigned int id;bool valid9b7230()const;D40Item*get9b65b0()const;};
struct D40HG{unsigned int id;D40Group*get9b7250()const;};
class D40Group{public:int type9b4350();};
class D40Entity{public:D40HG group45a3f0();int target45a760();bool hostile45aa70(D40HE);int size45a360();vector<D40Point>*cells45d1a0();};
class D40Item{public:int glyph457a30();D40Color*color5755f0(bool);};
class D40Cell{public:D40HE entity45d250();D40HI item45d8f0();};
struct D40Track{int type,level;D40HE entity;int glyph;D40Color color;int glyph461cf0(bool)throw();D40Color color72eb70()throw();};
template<class T>struct D40Grid{int width,height;T*data;T*at9ceda0(int,int)throw();T*point9ced70(D40Point&);int height9b8f00();int width9fcd80();};
struct D40TrackGrid{int width,height;D40Track*data;D40Track*at9cdf20(int,int)throw();D40Track*point9d2930(D40Point&);};
class D40World{public:char prefix[0x66c];D40HE player;char gap[0x69c-0x670];D40Grid<int> tables;char gap2[0x730-0x6a8];vector<D40HI> excluded;D40TrackGrid visible;int type;bool contains9e2970(vector<D40HI>*,D40HI);};
struct D40Record{D40HE entity;D40Point position;D40Color color;int glyph;D40Record(const D40HE&,const D40Point&,const D40Color&,int);};
extern D40World*world_cefc4c;extern D40Grid<D40Cell*>cells_cfd44c;extern bool tile_d28d15;extern D40Color *color_cfe674,*color_d29d90,*color_d21f54;extern vector<D40Point>points_d35860,points_d1daec;
int min9cdb30(int,int);int max9cdb60(int,int);bool contains9d31e0(vector<D40HE>&,D40HE);void erase9d6440(vector<D40HE>&,int&);void delete9e2c40(vector<D40Record*>&);
class D40Map{public:char base[0x6c];D40Point offset;int width44b0d0();int height4174c0();void bounds8051f0(D40Point*,D40Point*);void draw86f9c0(int,vector<D40Record*>*,vector<int>*,vector<int>*,vector<int>*,vector<int>*);void collect86e310();};
void D40Map::collect86e310(){
 D40Grid<int>*tables=&world_cefc4c->tables;D40TrackGrid*visible=&world_cefc4c->visible;int type=world_cefc4c->type;
 D40Area record;bounds8051f0(&record.min,&record.max);int factor=tile_d28d15?1:2;
 D40Area zones(D40Point(max9cdb60(0,record.min.x-width44b0d0()/factor),max9cdb60(0,record.min.y-height4174c0()/factor)),D40Point(min9cdb30(cells_cfd44c.width9fcd80()-1,record.max.x+width44b0d0()/factor),min9cdb30(cells_cfd44c.height9b8f00()-1,record.max.y+height4174c0()/factor)));
 vector<D40HE>label,vec;vector<D40Record*>part;vector<D40HE>entities;vector<D40Record*>mode,start,areas;
 for(int x=zones.min.x;x<=zones.max.x;x++)for(int y=zones.min.y;y<=zones.max.y;y++){
  if(!record.containsXY40b700(x,y)){
  if(*tables->at9ceda0(x,y)){
   if((*cells_cfd44c.at9ceda0(x,y))->entity45d250().valid9b7230()&&(*cells_cfd44c.at9ceda0(x,y))->entity45d250().get9b6570()->group45a3f0().get9b7250()->type9b4350()&&(*cells_cfd44c.at9ceda0(x,y))->entity45d250().get9b6570()->target45a760()<6){
    if((*cells_cfd44c.at9ceda0(x,y))->entity45d250().get9b6570()->hostile45aa70(world_cefc4c->player)){if(!contains9d31e0(label,(*cells_cfd44c.at9ceda0(x,y))->entity45d250()))label.push_back((*cells_cfd44c.at9ceda0(x,y))->entity45d250());}
    else if(!contains9d31e0(vec,(*cells_cfd44c.at9ceda0(x,y))->entity45d250()))vec.push_back((*cells_cfd44c.at9ceda0(x,y))->entity45d250());
   }
   if((*cells_cfd44c.at9ceda0(x,y))->item45d8f0().valid9b7230()&&!world_cefc4c->contains9e2970(&world_cefc4c->excluded,(*cells_cfd44c.at9ceda0(x,y))->item45d8f0()))part.push_back(new D40Record(D40HE(),D40Point(x,y),*(*cells_cfd44c.at9ceda0(x,y))->item45d8f0().get9b65b0()->color5755f0(false),(*cells_cfd44c.at9ceda0(x,y))->item45d8f0().get9b65b0()->glyph457a30()));
  }else if(visible->at9cdf20(x,y)->type==type){
   if(visible->at9cdf20(x,y)->level>=4&&visible->at9cdf20(x,y)->entity.get9b6570()){
    if(!contains9d31e0(entities,visible->at9cdf20(x,y)->entity))entities.push_back(visible->at9cdf20(x,y)->entity);
   }else mode.push_back(new D40Record(D40HE(),D40Point(x,y),visible->at9cdf20(x,y)->color72eb70(),visible->at9cdf20(x,y)->glyph461cf0(true)));
  }
 }}
 vector<D40Record*>ret;
 for(int i=0;i<label.size();i++){
  if(label[i].get9b6570()->size45a360()>1){for(int j=0;j<label[i].get9b6570()->cells45d1a0()->size();j++)if(record.contains40b750((*label[i].get9b6570()->cells45d1a0())[j])&&*tables->point9ced70((*label[i].get9b6570()->cells45d1a0())[j])){erase9d6440(label,i);goto hostileNext;}}
  ret.push_back(new D40Record(label[i],D40Point(-1),*color_cfe674,0));
 hostileNext:;
 }
 vector<D40Record*>s;
 for(int i=0;i<vec.size();i++){
  if(vec[i].get9b6570()->size45a360()>1){for(int j=0;j<vec[i].get9b6570()->cells45d1a0()->size();j++)if(record.contains40b750((*vec[i].get9b6570()->cells45d1a0())[j])&&*tables->point9ced70((*vec[i].get9b6570()->cells45d1a0())[j])){erase9d6440(vec,i);goto friendlyNext;}}
  s.push_back(new D40Record(vec[i],D40Point(-1),*color_cfe674,0));
 friendlyNext:;
 }
 vector<D40Record*>a;
 for(int i=0;i<entities.size();i++){
  if(entities[i].get9b6570()->size45a360()>1){for(int j=0;j<entities[i].get9b6570()->cells45d1a0()->size();j++)if(record.contains40b750((*entities[i].get9b6570()->cells45d1a0())[j])&&(*tables->point9ced70((*entities[i].get9b6570()->cells45d1a0())[j])||visible->point9d2930((*entities[i].get9b6570()->cells45d1a0())[j])->type==type)){erase9d6440(entities,i);goto memoryNext;}}
  a.push_back(new D40Record(entities[i],D40Point(-1),*color_cfe674,0));
 memoryNext:;
 }
 for(int i=0;i<points_d35860.size();i++)if(zones.contains40b750(points_d35860[i])&&!record.contains40b750(points_d35860[i]))start.push_back(new D40Record(D40HE(),points_d35860[i],*color_d29d90,32));
 for(int i=0;i<points_d1daec.size();i++)if(zones.contains40b750(points_d1daec[i])&&!record.contains40b750(points_d1daec[i]))areas.push_back(new D40Record(D40HE(),points_d1daec[i],*color_d21f54,32));
 vector<int>step;step.push_back(0);step.push_back(width44b0d0()-1);vector<int>current;current.push_back(0);current.push_back(width44b0d0()-1);vector<int>row;row.push_back(0);row.push_back(height4174c0()-1);vector<int>line;line.push_back(0);current.push_back(height4174c0()-1);
 for(int x=record.min.x,screen=record.min.x+offset.x;x<=record.max.x;x++,screen++){
  if((*tables->at9ceda0(x,record.min.y)&&(*cells_cfd44c.at9ceda0(x,record.min.y))->entity45d250().valid9b7230())||visible->at9cdf20(x,record.min.y)->type==type)step.push_back(screen);
  if((*tables->at9ceda0(x,record.max.y)&&(*cells_cfd44c.at9ceda0(x,record.max.y))->entity45d250().valid9b7230())||visible->at9cdf20(x,record.max.y)->type==type)current.push_back(screen);
 }
 for(int y=record.min.y,screen=record.min.y+offset.y;y<=record.max.y;y++,screen++){
  if((*tables->at9ceda0(record.min.x,y)&&(*cells_cfd44c.at9ceda0(record.min.x,y))->entity45d250().valid9b7230())||visible->at9cdf20(record.min.x,y)->type==type)row.push_back(screen);
  if((*tables->at9ceda0(record.max.x,y)&&(*cells_cfd44c.at9ceda0(record.max.x,y))->entity45d250().valid9b7230())||visible->at9cdf20(record.max.x,y)->type==type)line.push_back(screen);
 }
 draw86f9c0(0,&ret,&step,&current,&row,&line);delete9e2c40(ret);
 draw86f9c0(1,&s,&step,&current,&row,&line);delete9e2c40(s);
 draw86f9c0(2,&part,&step,&current,&row,&line);delete9e2c40(part);
 draw86f9c0(3,&a,&step,&current,&row,&line);delete9e2c40(a);
 draw86f9c0(4,&mode,&step,&current,&row,&line);delete9e2c40(mode);
 draw86f9c0(5,&start,&step,&current,&row,&line);delete9e2c40(start);
 draw86f9c0(6,&areas,&step,&current,&row,&line);delete9e2c40(areas);
}

D40Area::D40Area():min(-1),max(-1){}
D40Area::D40Area(const D40Point&a,const D40Point&b):min(a),max(b){}
D40Record::D40Record(const D40HE&a,const D40Point&p,const D40Color&c,int g):entity(a),position(p),color(c),glyph(g){}

static_assert(sizeof(D40Point)==8&&sizeof(D40Color)==3&&sizeof(D40Area)==16&&sizeof(D40Record)==20&&sizeof(D40Track)==20&&sizeof(vector<D40HE>)==16,"actual native coordinate/color/marker/storage shapes");

// Genuine native leaf constructor bodies, observed storage/copy only; covered retail aliases.
D40Point::D40Point(int a,int b)throw():x(a),y(b){}
D40Point::D40Point(const D40Point&p)throw():x(p.x),y(p.y){}
D40Color::D40Color(const D40Color&c)throw():r(c.r),g(c.g),b(c.b){}
D40HE::D40HE()throw():id(0){}
