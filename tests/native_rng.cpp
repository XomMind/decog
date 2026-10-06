// Native portability check: MT19937 vectors, state rollover, and RNG wrappers.
#include <cmath>
#include <cstdio>
#include <random>
#include "../src/lib/mtrand.h"
#include "../src/util/rng.h"
#include "../src/util/rngc.h"

int peerCrtDraw();

int main()
{
	const unsigned long seeds[] = { 5489UL, 0UL, 1UL, 0xffffffffUL };
	for (unsigned long seed : seeds)
	{
		MTRand_int32 actual;
		actual.seed(seed);
		std::mt19937 expected(seed);
		for (int i = 0; i < 10000; ++i)
		{
			const unsigned long got = actual();
			const unsigned long want = expected();
			if (got != want)
			{
				std::fprintf(stderr, "MT seed=%lu draw=%d: got %lu, expected %lu\n", seed, i, got, want);
				return 1;
			}
		}
	}
	MTRand_open open;
	std::mt19937 expected(5489UL);
	for (int i = 0; i < 10000; ++i)
	{
		const double want = (expected() + 0.5) / 4294967296.0;
		if (open() != want) return 2;
	}
	RNG a, b;
	a.seed(123); b.seed(123);
	for (int i = 0; i < 10000; ++i)
	{
		const int value = a.rangeInt(-10, 20);
		if (value < -10 || value > 20 || value != b.rangeInt(20, -10)) return 3;
		const float valuef = a.rangeFloat(-10, 20);
		if (!std::isfinite(valuef) || valuef < -10 || valuef > 20 || valuef != b.rangeFloat(20, -10)) return 4;
	}
	// Known Microsoft CRT rand() outputs for srand(1). With [0,32766],
	// the reconstructed range transform returns those outputs directly.
	const int crt[] = { 41, 18467, 6334, 26500, 19169, 15724, 11478, 29358, 26962, 24464 };
	RNGC c;
	c.seed(1);
	for (int i = 0; i < 10; ++i)
	{
		const int got = (i % 2 ? peerCrtDraw() : c.rangeInt(0, 32766));
		if (got != crt[i])
		{
			std::fprintf(stderr, "CRT draw=%d: got %d, expected %d\n", i, got, crt[i]);
			return 5;
		}
	}
	std::puts("Native RNG PASS: 40,000 MT vectors, 10,000 open doubles, 10,000 paired ranges, shared MSVCRT sequence");
}
