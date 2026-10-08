// Private aliases and observed layout for retail text-input key handling.
#include <string>
typedef std::string LB9String;
struct LB9Clipboard {bool get_41ae40(LB9String &) throw();};
extern LB9Clipboard *lb9_clip_cefa98;
extern bool lb9_ctrl_cec14d;
extern unsigned lb9_npos_c2ea48;
extern int lb9_black_caecf8[10];
bool lb9_range_9daf80(int,int,int) throw();bool lb9_lookup_9d43b0(int *,unsigned,int) throw();
bool lb9_contains_9db330(const void *,int) throw();bool lb9_same_9cce40(const LB9String &,const LB9String &) throw();
struct LB9Input {
 char pad[0x6c]; LB9String text;int cursor;bool readonly;char pad8d[3];unsigned maximum;bool digits,suppress;char pad96[2];
 int records[4];bool upper,trim,paren;char padab;
 void (__cdecl *accepted)(bool);int status;void (__cdecl *arrow)(bool);void (__cdecl *typed)();void (__cdecl *equal)();
 LB9String trigger;bool (__cdecl *space)(bool);void (__cdecl *callback)(int,int);
 void update_7b0b00(int key,int mode);
};
void LB9Input::update_7b0b00(int key,int mode) {
 if(suppress){suppress=false;return;}
 if(callback)callback(key,mode);
 switch(mode){
 case 3: if(readonly)break;
 case 0:case 1:case 2:case 4:
  if(key=='`')break;
  if(digits && mode!=2)break;
  if(maximum && text.size()==maximum)break;
  if(lb9_ctrl_cec14d){
   if(key=='v'){
    LB9String first;
    if(lb9_clip_cefa98->get_41ae40(first)){
     for(unsigned count=0;count<first.size();++count){
      if(!lb9_range_9daf80(32,first.operator[](count),122)||first.operator[](count)=='`'){
       first.erase(first.begin()+count);--count;
      }
     }
     if(maximum && first.size()>maximum)first.erase(first.begin()+maximum,first.end());
     if(digits){for(unsigned a=0;a<first.size();++a){if(!lb9_range_9daf80(48,first.operator[](a),57)){first.erase(first.begin()+a);--a;}}}
     if(readonly){for(unsigned i=0;i<first.size();++i){if(lb9_lookup_9d43b0(lb9_black_caecf8,10,first.operator[](i))){first.erase(first.begin()+i);--i;}}}
     text.operator=(first);cursor=text.size();
    }
   }
   break;
  }
  if(lb9_contains_9db330(&records,key))break;
  if(upper && mode==0)key-=32;
  text.insert(text.begin()+cursor,(char)key);
  if(key!=32 && typed)typed();
  if(key==32 && space && space(false))break;
  ++cursor;
  if(equal && lb9_same_9cce40(text,trigger))equal();
  break;
 case 5:
  switch(key){
  case 8:
   if(cursor>0){
    if(lb9_ctrl_cec14d){
     if(paren){unsigned index=text.find('(',0);if(index!=lb9_npos_c2ea48 && index<text.size()-1){text.erase(text.begin()+index+1,text.end());cursor=text.size();return;}}
     text.erase(text.begin(),text.begin()+cursor);cursor=0;
    }else{text.erase(text.begin()+cursor-1);--cursor;}
   }break;
  case 13:
   if(trim){while(!text.empty() && text.operator[](0)==32)text.erase(text.begin());}
   status=2;if(accepted)accepted(false);break;
  case 27:status=3;if(accepted)accepted(true);break;
  case 127:
   if(cursor!=text.size()){
    if(lb9_ctrl_cec14d)text.erase(text.begin()+cursor,text.end());
    else text.erase(text.begin()+cursor);
   }break;
  case 128:if(cursor!=0){if(lb9_ctrl_cec14d)cursor=0;else --cursor;}break;
  case 129:if(cursor<text.size()){if(lb9_ctrl_cec14d)cursor=text.size();else ++cursor;}break;
  case 130:case 131:if(arrow)arrow(key==130);break;
  case 132:cursor=0;break;
  case 133:cursor=text.size();break;
  case 135:if(space)space(true);break;
  }break;
 }
}
