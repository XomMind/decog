// NOTE: private placeholders for the 20-byte bit vector and its 8-byte iterators.
// Isolates the backing-word resize helper from unrelated LTCG-folded vector instances.
struct LoopDeltaBitIterator;
struct LoopDeltaConstBitIterator {
 unsigned *ptr; unsigned offset;
 int operator-(const LoopDeltaConstBitIterator&) const throw();
};
struct LoopDeltaBitIterator : LoopDeltaConstBitIterator {
 LoopDeltaBitIterator operator+(int) const throw();
};
LoopDeltaBitIterator LoopDeltaCopyBackward(LoopDeltaBitIterator,LoopDeltaBitIterator,LoopDeltaBitIterator) throw();
struct LoopDeltaWords {
 unsigned pad[4]; // NOTE: actual vector<unsigned> object occupies 16 bytes.
 void resize_9c8a00(unsigned,unsigned) throw();
};
struct LoopDeltaBitVector {
 LoopDeltaWords words;
 unsigned _Mysize;
 LoopDeltaBitIterator begin() throw();
 LoopDeltaBitIterator end() throw();
 unsigned max_size() const throw();
 unsigned size() const throw();
 void _Xlen() const throw();
 static unsigned _Nw(unsigned) throw();
 unsigned insertSpace(LoopDeltaConstBitIterator _Where,unsigned _Count);
};
unsigned LoopDeltaBitVector::insertSpace(LoopDeltaConstBitIterator _Where,unsigned _Count) {
 unsigned _Off = _Where - begin();
 if (_Count == 0) ;
 else if (max_size() - size() < _Count) _Xlen();
 else {
  words.resize_9c8a00(_Nw(size()+_Count),0);
  if (size() == 0) _Mysize += _Count;
  else {
   LoopDeltaBitIterator _Oldend = end();
   _Mysize += _Count;
   LoopDeltaCopyBackward(begin()+_Off,_Oldend,end());
  }
 }
 return _Off;
}
