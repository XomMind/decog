// basic_string insertion implementations. NOTE: placeholder names/layout.
extern unsigned cb_insert_npos_c2ea48;
extern char* cb_string_move(char*,const char*,unsigned);
extern char* cb_string_copy(char*,const char*,unsigned);
struct CBInsertStringOct07 {
 char buffer[16]; unsigned size,capacity; int alloc;
 unsigned length() const;
 bool inside(const char*);
 char* myptr() const;
 void xrange() const;
 void xlength() const;
 bool grow(unsigned,bool);
 void eos(unsigned);
 CBInsertStringOct07& f_9bb200(unsigned,const CBInsertStringOct07&,unsigned,unsigned);
 CBInsertStringOct07& f_9bb340(unsigned,const char*,unsigned);
};
CBInsertStringOct07& CBInsertStringOct07::f_9bb200(unsigned pos,const CBInsertStringOct07& str,unsigned off,unsigned count) {
 if(size<pos || str.length()<off) xrange();
 unsigned n=str.length()-off;
 if(n<count) count=n;
 if(cb_insert_npos_c2ea48-size<=count) xlength();
 if(0<count && grow(n=size+count,false)) {
  cb_string_move(myptr()+pos+count,myptr()+pos,size-pos);
  if(this==&str) cb_string_move(myptr()+pos,myptr()+(pos<off?off+count:off),count);
  else cb_string_copy(myptr()+pos,str.myptr()+off,count);
  eos(n);
 }
 return *this;
}
CBInsertStringOct07& CBInsertStringOct07::f_9bb340(unsigned pos,const char* ptr,unsigned count) {
 if(inside(ptr)) return f_9bb200(pos,*this,ptr-myptr(),count);
 if(size<pos) xrange();
 if(cb_insert_npos_c2ea48-size<=count) xlength();
 unsigned n;
 if(0<count && grow(n=size+count,false)) {
  cb_string_move(myptr()+pos+count,myptr()+pos,size-pos);
  cb_string_copy(myptr()+pos,ptr,count);
  eos(n);
 }
 return *this;
}
