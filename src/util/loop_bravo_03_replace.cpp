// NOTE: private string/iterator ABI placeholders for 0x510110.
struct LB3TIter {
 const char *p;
 LB3TIter();
 LB3TIter operator+(int) const;
};
struct LB3Text {
 int proxy;
 union { char buffer[16]; char *pointer; } storage;
 unsigned size,capacity;
 LB3Text(const LB3Text &);
 LB3Text(LB3TIter,LB3TIter);
 ~LB3Text();
 unsigned find_9afe40(char,unsigned) const;
 char &at_9afc00(unsigned);
 LB3TIter begin_9afb40() const;
 LB3Text &replace_9afac0(unsigned,unsigned,const LB3Text &);
};
struct LB3Texts { const LB3Text &at_9b0670(unsigned) const; };
struct LB3Seen { int &at_9b9230(unsigned); };
extern LB3Text lb3t_mnames_d2ae30[];
extern LB3Text lb3t_rnames_d1d0f8[];
extern LB3Texts lb3t_mvalues_d1e900,lb3t_rvalues_d1e930;
extern LB3Seen lb3t_mseen_d1e920,lb3t_rseen_d1e950;
extern const unsigned lb3t_npos_c2ea48;
bool lb3t_equal_9cce40(const LB3Text &,const LB3Text &);
LB3Text lb3t_replace_510110(LB3Text &text,bool *changed) {
 if(changed) *changed=false;
 unsigned pos=text.find_9afe40('<',0);
 if(pos!=lb3t_npos_c2ea48) {
  unsigned i=text.find_9afe40('>',pos+1);
  if(i==lb3t_npos_c2ea48) return text;
  LB3Text *first=0;
  int index;
  LB3Texts *a;
  LB3Seen *base;
  switch(text.at_9afc00(pos+1)) {
  case 'm':first=lb3t_mnames_d2ae30;index=39;a=&lb3t_mvalues_d1e900;base=&lb3t_mseen_d1e920;break;
  case 'r':first=lb3t_rnames_d1d0f8;index=28;a=&lb3t_rvalues_d1e930;base=&lb3t_rseen_d1e950;break;
  default:return text;
  }
  unsigned count=text.find_9afe40('=',pos+1);
  LB3Text key(text.begin_9afb40()+count+1,text.begin_9afb40()+i);
  const LB3Text *result=0;
  for(int j=0;j<index;j++) {
   if(lb3t_equal_9cce40(key,first[j])) {
    result=&a->at_9b0670(j);
    base->at_9b9230(j)=1;
   }
  }
  if(result) {
   text.replace_9afac0(pos,i-pos+1,*result);
   if(changed) *changed=true;
  }
 }
 return text;
}
