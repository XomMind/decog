// High-address string/iterator forwarding functions. NOTE: placeholder names/layout.
struct CBStringIteratorOct07 {
 char* ptr;
 CBStringIteratorOct07(const char*,const void*);
};
extern unsigned cb_string_npos_c2ea48;
struct CBStringOct07 {
 char buffer[16]; unsigned size;
 char* myptr_9bbde0();
 CBStringOct07& append_9af460(const char*);
 CBStringOct07& insert_9bb200(unsigned,const CBStringOct07&,unsigned,unsigned);
 CBStringOct07& f_9af3f0(const char*);
 CBStringOct07& f_9af760(unsigned,const CBStringOct07&);
 CBStringIteratorOct07 f_9afb70();
 CBStringIteratorOct07 f_9afbd0();
};
CBStringOct07& CBStringOct07::f_9af3f0(const char* p) { return append_9af460(p); }
CBStringOct07& CBStringOct07::f_9af760(unsigned pos,const CBStringOct07& str) { return insert_9bb200(pos,str,0,cb_string_npos_c2ea48); }
CBStringIteratorOct07 CBStringOct07::f_9afb70() { return CBStringIteratorOct07(myptr_9bbde0(),this); }
CBStringIteratorOct07 CBStringOct07::f_9afbd0() { return CBStringIteratorOct07(myptr_9bbde0()+size,this); }
struct CBVectorIteratorOct07 {
 int ptr;
 CBVectorIteratorOct07& plus_9cbfc0(int);
 CBVectorIteratorOct07& f_9c7df0(int n);
};
CBVectorIteratorOct07& CBVectorIteratorOct07::f_9c7df0(int n) { return plus_9cbfc0(-n); }
struct CBVectorConstIteratorOct07 {
 int ptr;
 int difference_a00570(const CBVectorConstIteratorOct07&) const;
 int f_a00550(const CBVectorConstIteratorOct07&) const;
};
int CBVectorConstIteratorOct07::f_a00550(const CBVectorConstIteratorOct07& rhs) const { return difference_a00570(rhs); }
struct CBVecPosOct07 { void destruct_bplaceholder(); };
struct CBVecStringOct07 { void destruct_bplaceholder(); };
extern CBVecPosOct07 cb_vec_d2d4f4,cb_vec_d2ed08;
extern CBVecStringOct07 cb_vec_d2d4c8;
void cb_f_b5ccb0() { cb_vec_d2d4f4.destruct_bplaceholder(); }
void cb_f_b5ccc0() { cb_vec_d2d4c8.destruct_bplaceholder(); }
void cb_f_b5ccd0() { cb_vec_d2ed08.destruct_bplaceholder(); }
