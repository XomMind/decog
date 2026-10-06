// mtrand.h
// C++ include file for MT19937, with initialization improved 2002/1/26.
// Coded by Takuji Nishimura and Makoto Matsumoto.
// Ported to C++ by Jasper Bedaux 2003/1/1 (see http://www.bedaux.net/mtrand/).
//
// Cogmind variant: state/p are per-instance members (not static), and the
// default constructor clears the state before seeding with 5489.

#ifndef MTRAND_H
#define MTRAND_H

class MTRand_int32 { // Mersenne Twister random number generator
public:
  MTRand_int32() { clear(); seed(5489UL); }
  void seed(unsigned long); // seed with 32 bit integer
  unsigned long operator()() { return rand_int32(); }
  virtual ~MTRand_int32() {}
  void clear() {
    for (int i = 0; i < n; ++i) state[i] = 0;
    p = 0;
  }
protected:
  unsigned long rand_int32();
private:
  static const int n = 624, m = 397;
  unsigned long state[n];
  int p;
  unsigned long twiddle(unsigned long, unsigned long);
  void gen_state();
  MTRand_int32(const MTRand_int32&);
  void operator=(const MTRand_int32&);
};

inline unsigned long MTRand_int32::twiddle(unsigned long u, unsigned long v) {
  return (((u & 0x80000000UL) | (v & 0x7FFFFFFFUL)) >> 1)
    ^ ((v & 1UL) ? 0x9908B0DFUL : 0x0UL);
}

inline unsigned long MTRand_int32::rand_int32() {
  if (p == n) gen_state();
  unsigned long x = state[p++];
  x ^= (x >> 11);
  x ^= (x << 7) & 0x9D2C5680UL;
  x ^= (x << 15) & 0xEFC60000UL;
  return x ^ (x >> 18);
}

// generates double floating point numbers in the open interval (0, 1)
class MTRand_open : public MTRand_int32 {
public:
  MTRand_open() : MTRand_int32() {}
  ~MTRand_open() {}
  double operator()() {
    return (static_cast<double>(rand_int32()) + .5) * (1. / 4294967296.); }
private:
  MTRand_open(const MTRand_open&);
  void operator=(const MTRand_open&);
};

#endif // MTRAND_H
