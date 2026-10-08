// Cogshop refresh. Private partial call-site layouts.
#include <vector>
#include <string>
using namespace std;
struct ShopPos {int x,y;ShopPos(int,int) throw();};
struct ShopColor {unsigned char r,g,b;ShopColor(const ShopColor&) throw();};
struct ShopItem {
 char pad00[0x24];string name;int pad40,category,pad48,pad4c,tier,pad54,pad58,condition;char pad60[0x94-0x60];int damaged;
 void info(string&,const ShopColor&);
};
struct ShopEntry {int type;ShopItem *item;int price;};
struct ShopWorld {vector<ShopEntry*> *stock();int turn();int selected();};
struct ShopConsole {char pad[0x6c];int priceWidth,nameWidth,infoWidth;bool hidden();ShopPos position();int height();};
struct ShopList {char pad[0xd4];ShopList(ShopConsole*,const ShopPos&,string,int,const vector<string>&,int,int,void(*)(void*,const string&),void(*)(void*,const string&),int,bool,bool,vector<bool>*,vector<int>*,vector<int>*,bool);void field(int);void scroll(int,int);void flag(bool);void draw(void(*)(struct TeamB_SlotRow*));};
struct TeamB_SlotRow;
void teamb_drawSlotRow876f60(TeamB_SlotRow*);
void teamb_buy877150(void*,const string&);
extern ShopConsole *shopWindow1,*shopWindow2,*shopView,*shopRoot,*shopWidths;
extern ShopList *shopList;
extern ShopWorld *shopWorld;
extern vector<float> shopMultipliers;
extern int shopSaleCategory,shopSaleUntil,shopMoney,shopCellScale,shopX;
extern ShopPos shopGlyphs[];
extern ShopColor *shopInfoColor;
extern const float shopTierFactor_ba76c8;
string shopGrouped(int);
void shopPadLeft(string&,unsigned,char);
void shopPadRight(string&,unsigned,char);
int shopMin(int,int);
void deltaShopRefresh() {
 if(!shopWindow1->hidden() || !shopWindow2->hidden() || shopList) return;
 vector<ShopEntry*> *type=shopWorld->stock();
 for(unsigned n=0;n<type->size();n++) {
  ShopItem *p=(*type)[n]->item;
  if((*type)[n]->type==1) {
   float a=1.0f;
   if(p->damaged) a*=4-p->condition;
   a*=shopMultipliers[p->category];
   int count=a*1000.0;
   count*=1.0f+(p->tier-5)*shopTierFactor_ba76c8;
   if(p->category==shopSaleCategory && shopWorld->turn()<=shopSaleUntil) count*=0.5f;
   if(count<1)count=1;
   (*type)[n]->price=count;
  }
 }
 vector<string> idx;
 unsigned name=0;
 for(unsigned n=0;n<type->size();n++) {
  idx.push_back(shopGrouped((*type)[n]->price));
  if(idx.back().size()>name)name=idx.back().size();
 }
 for(unsigned n=0;n<idx.size();n++)shopPadLeft(idx[n],name,' ');
 shopWidths->priceWidth=name+1;
 unsigned index=0;
 for(unsigned n=0;n<type->size();n++) {
  idx[n]+=' ';
  idx[n]+=static_cast<unsigned char>((*type)[n]->type==0 ? '?' : shopGlyphs[(*type)[n]->item->category].x);
  idx[n]+=' ';
  idx[n]+=(*type)[n]->type==0 ? string("Loot Box") : string((*type)[n]->item->name);
  if(idx[n].size()>index)index=idx[n].size();
 }
 index+=2;
 for(unsigned n=0;n<idx.size();n++)shopPadRight(idx[n],index,' ');
 shopWidths->nameWidth=idx.front().size()-1;
 unsigned a=0;
 vector<string> text;
 for(unsigned n=0;n<type->size();n++) {
  text.push_back(string());
  if((*type)[n]->type==0)text.back()="What's inside?";
  else (*type)[n]->item->info(text.back(),ShopColor(*shopInfoColor));
  if(text.back().size()>a)a=text.back().size();
 }
 for(unsigned n=0;n<text.size();n++) {shopPadLeft(text[n],a,' ');idx[n]+=text[n];}
 shopWidths->infoWidth=a+1;
 vector<bool> *record=new vector<bool>(idx.size(),true);
 for(unsigned n=0;n<idx.size();n++) {
  if((*type)[n]->price>shopMoney)record->at(n)=false;
 }
 int w=shopMin(idx.size(),26)+4;
 int i=shopView->position().y+shopView->height()*shopCellScale-3-w-shopCellScale+1;
 new ShopList(shopRoot,ShopPos(shopX,i),"\\ C O G S H O P \\",18,idx,26,0,teamb_buy877150,0,22,false,false,record,0,0,false);
 shopList->field(5);
 shopList->scroll(0,shopWorld->selected());
 shopList->flag(true);
 shopList->draw(teamb_drawSlotRow876f60);
}
