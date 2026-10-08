// Protected image loading; file-private aliases retain typed callee roles.
#include <string>
#include "thirdparty/zfstream.h"
#include "lib/mtrand.h"
using std::string;
class LA10Rng {int currentSeed;MTRand_open mtRand;public:LA10Rng();~LA10Rng();int seed(int);int rangeInt(float,float);};
struct LA10Color {unsigned char r,g,b;};
struct LA10Cell {int font,ch,glyph;LA10Color fore,back;LA10Cell(int);LA10Cell(const LA10Cell&);void read(std::istream&);int getChar() throw();LA10Color *getFore() throw();LA10Color *getBack() throw();void setChar(int) throw();};
struct LA10Grid {int width,height;LA10Cell *cells;LA10Grid() throw();void resize(int,int,LA10Cell);LA10Cell *at(int,int) throw();int getHeight() throw();int getWidth() throw();void contract(int,int,int,int);};
struct LA10Rows {unsigned a,b,c,d;LA10Rows(unsigned,unsigned);~LA10Rows() throw();int &operator[](unsigned) throw();bool empty()const throw();unsigned size()const throw();};
struct LA10Layers {unsigned a,b,c,d;void push_back(void*const&);void *const &back()const throw();};
struct LA10Point {int x,y;};
struct LA10Image {LA10Layers layers;bool load(const string&,int,const LA10Point&,int,int);};
void la10_read(std::istream&,int*);void la10_remove(LA10Rows&,int);void la10_decode(LA10Color*,int) throw();void la10_notice(string,string);
extern int la10_caf5c8[6][100][100];
bool LA10Image::load(const string &filename,int fill,const LA10Point &crop,int right,int bottom) {
 gzifstream file((filename+".x").c_str(),std::ios_base::binary);
 if(file.is_open()) {
  int col, value,a,mode,num,index,height,width,turn;
  la10_read(file,&mode);mode=-mode;if(mode!=1)return false;
  LA10Rng zone;la10_read(file,&value);zone.seed(value);
  for(int i=0;i<10;i++){turn=zone.rangeInt(10000,20000);la10_read(file,&turn);}
  la10_read(file,&num);num-=zone.rangeInt(1,1000);
  if(num>=10000)num-=10000;
  else{la10_notice("AsciiImage::load()","Ignoring protected file: "+filename+".x");return false;}
  la10_read(file,&width);width-=zone.rangeInt(-10000,10000);
  la10_read(file,&height);height-=zone.rangeInt(-10000,10000);
  col=zone.rangeInt(0,5);a=zone.rangeInt(0,5);
  for(int layer=0;layer<num;layer++) {
   for(int i=0;i<10;i++){turn=zone.rangeInt(-10000,10000);la10_read(file,&turn);}
   LA10Rows vec(height,0);LA10Grid *f;
   for(int i=0;i<height;i++)vec[i]=i;
   layers.push_back(static_cast<LA10Grid*const&>(new LA10Grid));f=(LA10Grid*)layers.back();f->resize(width,height,LA10Cell(fill));
   while(!vec.empty()) {
    index=zone.rangeInt(0,vec.size()-1);turn=vec[index];
    for(int x=0;x<width;x++) {
     f->at(x,turn)->read(file);
     f->at(x,turn)->setChar(f->at(x,turn)->getChar()-la10_caf5c8[col][x%100][turn%100]);
     la10_decode(f->at(x,turn)->getFore(),la10_caf5c8[a][x%100][turn%100]);
     la10_decode(f->at(x,turn)->getBack(),la10_caf5c8[a][x%100][turn%100]);
    }
    la10_remove(vec,index);
   }
   if(crop.x!=-1)f->contract(crop.x,f->getWidth()-right-crop.x,crop.y,f->getHeight()-bottom-crop.y);
  }
  return true;
 }else return false;
}
