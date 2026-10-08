// NOTE: placeholder names and layouts; private declarations preserve distinct retail callees.
struct LMgrWord { int id; };
struct LMgrString; // Opaque string; no field access is needed by this wrapper.
struct LMgrWordIterator {
 LMgrWord *value;
 int difference_a01dc0(const LMgrWordIterator &) const;
};
struct LMgrStringIterator {
 LMgrString *value;
 int difference_9b45a0(const LMgrStringIterator &) const;
};
LMgrWord *lmgr_unchecked_word_a008a0(LMgrWordIterator);
LMgrString *lmgr_unchecked_string_a008a0(LMgrStringIterator);
void lmgr_sort_words_9ef7f0(LMgrWord*,LMgrWord*,int,bool(*)(const LMgrWord&,const LMgrWord&));
void lmgr_sort_strings_9ef980(LMgrString*,LMgrString*,int,bool(*)(const LMgrString&,const LMgrString&));
void lmgr_sort9e3010(LMgrWordIterator first, LMgrWordIterator last, bool(*predicate)(const LMgrWord&,const LMgrWord&)) {
 lmgr_sort_words_9ef7f0(lmgr_unchecked_word_a008a0(first),lmgr_unchecked_word_a008a0(last),last.difference_a01dc0(first),predicate);
}
void lmgr_sort9e3160(LMgrStringIterator first, LMgrStringIterator last, bool(*predicate)(const LMgrString&,const LMgrString&)) {
 lmgr_sort_strings_9ef980(lmgr_unchecked_string_a008a0(first),lmgr_unchecked_string_a008a0(last),last.difference_9b45a0(first),predicate);
}
struct LMgrConstInsertIterator {
 LMgrWord *value;
 LMgrConstInsertIterator();
};
struct LMgrInsertIterator : LMgrConstInsertIterator {
 LMgrInsertIterator();
 LMgrInsertIterator advance_9e9880(int) const;
};
struct LMgrVector {
 LMgrWord *first,*last,*end; int allocator;
 unsigned size_9b9260() const;
 void push_back_9b80b0(const LMgrWord &);
 LMgrInsertIterator begin_9c1270();
 LMgrInsertIterator insert_9eee10(LMgrConstInsertIterator,LMgrWord &);
};
void lmgr_insert9d8fc0(LMgrVector &v,int index,LMgrWord value) {
 if(index==v.size_9b9260()) v.push_back_9b80b0(value);
 else v.insert_9eee10(v.begin_9c1270().advance_9e9880(index),value);
}
