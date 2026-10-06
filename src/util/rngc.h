#ifndef RNGC_H
#define RNGC_H

#include <stdlib.h>
#ifndef _WIN32
#include <stdint.h>
#endif

//==================================================================
// C runtime rand() based generator
//==================================================================
// NOTE: placeholder names. Same interface as RNG but on srand()/rand();
// only used by the seed string decoder (0x4351E0).

class RNGC
{
	int	currentSeed;

#ifndef _WIN32
	// MSVCR100 rand(): one shared state across all RNGC instances/TUs.
	static uint32_t &crtState()
	{
		static uint32_t state = 1;
		return state;
	};
	static int crtRand()
	{
		uint32_t &state = crtState();
		state = state * 214013U + 2531011U;
		return (state >> 16) & 0x7fff;
	};
#endif

public:
	RNGC()
		: currentSeed	(0)
	{};

	int seed(int seed_)
	{
		currentSeed = seed_;
#ifdef _WIN32
		srand(currentSeed);
#else
		crtState() = (uint32_t)currentSeed;
#endif
		return currentSeed;
	};

	// random integer in [a,b] (either order)
	int rangeInt(float a, float b)
	{
		float high, low;
		if (a > b) { high = a; low = b; }
		else { high = b; low = a; }
		int offset;	// shift negative ranges up to 0
		if (low < 0.0) offset = (int)low;
		else offset = 0;
		high -= offset;
		low -= offset;
		int value;
		do
		{
#ifdef _WIN32
			value = (int)(rand() / (double)RAND_MAX * (high - low + 1.0) + low);
#else
			value = (int)(crtRand() / 32767.0 * (high - low + 1.0) + low);
#endif
		} while (value > high);
		value += offset;
		return value;
	};
};

#endif // RNGC_H
