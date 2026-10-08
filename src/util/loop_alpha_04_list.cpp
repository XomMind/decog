// CList construction, private partial layouts and semantic nothrow aliases.
#include <string>
using std::string;
struct LA4Pos {int x,y;}; struct LA4Color {unsigned char r,g,b;};
class LA4Console {public: virtual ~LA4Console(); virtual void resize7ad4a0(int,int); virtual bool isActive4184c0(); virtual void refresh(); virtual bool input(void*); virtual void inputAscii(int,int); virtual void update(); virtual void render48c5b0(); virtual void open(); virtual void close(); virtual int getFrame48c350(); virtual void trigger48c4e0(const string&,int);
 LA4Console(LA4Console*,int,int,int,int,int,bool,int); void animate48c3f0(string); void title7ad4e0(LA4Console*); int width44b0d0() throw(); int height4174c0() throw(); void hidden417ba0(bool) throw();
 char pad4[0x5c]; int state; char pad64[8];};
// NOTE: private partial vector<string> layout; copy ctor 0x9b01d0, destructor 0x9b0460.
struct LA4Strings {char data[16]; LA4Strings(const LA4Strings&); ~LA4Strings(); unsigned size9b0650() const throw(); string& at9b06a0(unsigned) throw();};
struct LA4Ints {int& at9b9230(unsigned) throw();};
struct LA4BoolRef {unsigned *ptr; unsigned bit; operator bool() const throw();}; struct LA4Bools {LA4BoolRef at9b3850(unsigned) throw();};
class LA4Option;
// NOTE: private vector<LA4Option*> layout; ctor folds to 0x9b8e80.
struct LA4Rows {char data[16]; LA4Rows(); ~LA4Rows(); void push9b9280(LA4Option *&&) throw(); LA4Option * const& back9b6540() const throw();};
class LA4Title:public LA4Console {public: LA4Title(LA4Console*,string,int,int);char extra[32];};
class LA4Close:public LA4Console {public: LA4Close(LA4Console*,const LA4Color&,int);char extra[32];};
class LA4Option:public LA4Console {public: LA4Option(LA4Console*,int,int,int,const string&,int,bool,int,int,bool,int,int); void draw7b1e40() throw();char extra[20];};
struct LA4Keys {void push416790(int,int,int,bool) throw();}; extern LA4Keys *la4_cefa8c;extern LA4Color *la4_cf1f2c;
int la4_min9cdb30(int,int) throw();int la4_max9cdb60(int,int) throw();
class LA4List:public LA4Console {public:
 LA4List(LA4Console*,const LA4Pos&,string,int,const LA4Strings&,int,int,void(*)(int,const string&),void(*)(int,const string&),int,bool,bool,LA4Bools*,LA4Ints*,LA4Ints*,bool);
 virtual bool input(void*); virtual void inputAscii(int,int);virtual void update();virtual void close();void scroll7b3a60() throw();
 unsigned closeTime;LA4Close *closeButton;int mode;LA4Strings options;unsigned maxLength;int optionWidth,numVisible,unknown94,unknown98;bool flag9c,flag9d,noClose;LA4Bools *enabled;LA4Ints *colorsA,*colorsB;LA4Rows rows;void(*callback)(int,const string&);bool flagC0;void(*callback2)(int,const string&);int unknownC8;LA4Option *moreAbove,*moreBelow;
}; extern LA4List *la4_cec130;
// 0x48d9a0; all member offsets and constructor roles follow the retail body.
LA4List::LA4List(LA4Console *parent,const LA4Pos &pos,string title,int mode_,const LA4Strings &options_,int maxVisible,int font,void(*callback_)(int,const string&),void(*callback2_)(int,const string&),int layer,bool flag9c_,bool flag9d_,LA4Bools *enabled_,LA4Ints *colorsA_,LA4Ints *colorsB_,bool noClose_):LA4Console(parent,1,1,pos.x,pos.y,font,false,layer),mode(mode_),options(options_),unknown94(1),unknown98(0),flag9c(flag9c_),flag9d(flag9d_),noClose(noClose_),enabled(enabled_),colorsA(colorsA_),colorsB(colorsB_),callback(callback_),flagC0(false),callback2(callback2_),unknownC8(0),moreAbove(0),moreBelow(0) {
 la4_cec130=this;if(false){} maxLength=0;
 for(unsigned i=0;i<options.size9b0650();i++) if(options.at9b06a0(i).length()>maxLength) maxLength=options.at9b06a0(i).length();
 numVisible=la4_min9cdb30(options.size9b0650(),maxVisible);
 resize7ad4a0(la4_max9cdb60(title.length()+3,maxLength+10),numVisible+4);
 optionWidth=width44b0d0()-9;
 title7ad4e0(new LA4Title(this,title,0,2));
 for(int i=0,y=2;i<numVisible;i++,y++) {
 rows.push9b9280(new LA4Option(this,7,y,optionWidth,options.at9b06a0(i),font,false,i,0,enabled?enabled->at9b3850(i):true,colorsA?colorsA->at9b9230(i):0,colorsB?colorsB->at9b9230(i):-1));
 rows.back9b6540()->draw7b1e40();scroll7b3a60();
 }
 if(options.size9b0650()>numVisible) {moreBelow=new LA4Option(this,7,height4174c0()-2,optionWidth,options.at9b06a0(numVisible),font,false,0,1,true,0,-1);moreBelow->draw7b1e40();}
 animate48c3f0("CList_Border");la4_cefa8c->push416790(0x12,(int)this,noClose?-1:0x10e,false);state=1;
 if(!noClose){closeButton=new LA4Close(this,*la4_cf1f2c,0x12);closeButton->hidden417ba0(false);}
}
