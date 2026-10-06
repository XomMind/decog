// Small PRNG helpers (pcg32, xoroshiro64*, xorshift32, LCG...) and STL header inlines
// (char_traits, locale, iostream manipulators) found at 0x4014c0-0x402c7f.
// NOTE: all function/type names are placeholders (suffix = exe address); the STL ones are the real VS2010 inlines.
#include <string>
#include <locale>
#include <iostream>

using namespace std;

typedef unsigned int		u32;
typedef unsigned long long	u64;

//==================================================================
// STL header inlines (need a user so they get emitted)
//==================================================================

// NOTE: placeholder name, never called; only references the inlines below
void stlInlineUse_unused()
{
	wchar_t wa[4], wb[4];
	char_traits<wchar_t>::copy(wa,wb,4);
	char_traits<wchar_t>::move(wa,wb,4);
	char_traits<wchar_t>::assign(wa,4,L'x');
	char_traits<wchar_t>::assign(wa[0],wb[0]);
	char ca[4];
	char_traits<char>::assign(ca,4,'x');
	char_traits<char>::eq(ca[0],ca[1]);
	locale::facet *facet = NULL;
	facet->_Register();
	{
		locale loc;
		loc._Getfacet(1);
	}
	dec(cout);
	fixed(cout);
	hex(cout);
	istream::sentry s(cin);
}

//==================================================================
// PCG32 (pcg-random.org minimal C implementation)
//==================================================================

struct pcg32State_t		// NOTE: placeholder name
{
	u64 state;
	u64 inc;
};

u32 pcg32Random_4028e0(pcg32State_t *rng);		// NOTE: placeholder name

void pcg32Seed_402880(pcg32State_t *rng, u64 initstate, u64 initseq)	// NOTE: placeholder name
{
	rng->state = 0U;
	rng->inc = (initseq << 1u) | 1u;
	pcg32Random_4028e0(rng);
	rng->state += initstate;
	pcg32Random_4028e0(rng);
}

u32 pcg32Random_4028e0(pcg32State_t *rng)		// NOTE: placeholder name
{
	u64 oldstate = rng->state;
	rng->state = oldstate * 6364136223846793005ULL + rng->inc;
	u32 xorshifted = (u32)(((oldstate >> 18u) ^ oldstate) >> 27u);
	u32 rot = (u32)(oldstate >> 59u);
	return (xorshifted >> rot) | (xorshifted << ((-(int)rot) & 31));
}

u32 pcg32Bounded_402970(pcg32State_t *rng, u32 bound)	// NOTE: placeholder name
{
	u32 threshold = -(int)bound % bound;
	for (;;)
	{
		u32 r = pcg32Random_4028e0(rng);
		if (r >= threshold)
			return r % bound;
	}
}

//==================================================================
// Other small generators
//==================================================================

struct Rng4_t		// NOTE: placeholder name
{
	u32 a, b, c, d;
};

u32 rng4Next_4029b0(Rng4_t *arg)		// NOTE: placeholder name
{
	u32 s0, s1, s2, s3;
	Rng4_t *state = arg;
	s0 = state->a;
	s1 = state->b;
	s2 = state->c;
	s3 = state->d;
	state->a = s3 * 0xc61d672b;
	state->b = ((s0 << 26) | (s0 >> 6)) + s3;
	state->c = s2 - s1;
	state->d = s2 + s0;
	state->d = (state->d << 9) | (state->d >> 23);
	return s1;
}

void xoroshiro64Advance_402a40(u32 *s)		// NOTE: placeholder name
{
	s[1] ^= s[0];
	s[0] = ((s[0] << 26) | (s[0] >> 6)) ^ s[1] ^ (s[1] << 9);
	s[1] = (s[1] << 13) | (s[1] >> 19);
}

u32 xoroshiro64Star_402aa0(u32 *s)		// NOTE: placeholder name
{
	u32 result;
	u32 *state = s;
	result = state[0] * 0x9e3779bb;
	xoroshiro64Advance_402a40(state);
	return result;
}

u32 boundedRand_402ad0(u32 range, u32 (*gen)(void *), void *ctx)	// NOTE: placeholder name
{
	u64 m = (u64)gen(ctx) * range;
	u32 l = (u32)m;
	if (l < range)
	{
		u32 t = -(int)range % range;
		while (l < t)
		{
			m = (u64)gen(ctx) * range;
			l = (u32)m;
		}
	}
	return (u32)(m >> 32);
}

u32 mix1_402b40(u32 *s)		// NOTE: placeholder name
{
	return (s[0] << 16) + s[1];
}

u32 mix2_402b60(u32 *s)		// NOTE: placeholder name
{
	return (s[0] << 16) + (s[0] >> 16) + s[1];
}

u32 mix3_402b80(u32 *s)		// NOTE: placeholder name
{
	u32 r, m, n;
	r = (s[0] << 16) + (s[0] >> 16) + s[1];
	m = s[2];
	n = s[3];
	return (r ^ m) + n;
}

void lcgSeed_402bc0(u32 *s, u32 seed)		// NOTE: placeholder name
{
	*s = seed;
}

u32 lcgNext_402bd0(u32 *s)		// NOTE: placeholder name
{
	u32 x = *s * 69069 + 12345;
	*s = x;
	return x;
}

void xorshift32Fix_402c20(u32 *s);		// NOTE: placeholder name

void xorshift32Seed_402c00(u32 *s, u32 seed)	// NOTE: placeholder name
{
	*s = seed;
	xorshift32Fix_402c20(s);
}

void xorshift32Fix_402c20(u32 *s)		// NOTE: placeholder name
{
	if (*s == 0)
		*s = 0xffffffff;
}

u32 xorshift32Next_402c40(u32 *s)		// NOTE: placeholder name
{
	u32 x = *s;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	*s = x;
	return x;
}
