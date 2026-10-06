#ifndef RNG_H
#define RNG_H

#include <time.h>
#include "../lib/mtrand.h"
#include "mathutil.h"

//==================================================================
// Random number generator
//==================================================================
// NOTE: class/method names are placeholders, the originals aren't in the binary.
// Instances: rng (0xD30908, nearly all callers) and a second one at 0xD20D00.

class RNG
{
	int			currentSeed;
	MTRand_open	mtRand;

public:
	RNG()
		: currentSeed	(0)
	{};

	// percent chance (0-100)
	bool chance(int percent)
	{
		return rangeInt(1,100) <= percent;
	};
	bool chance(float percent)
	{
		return rangeFloat(0,100) <= percent;
	};

	int seed()
	{
		currentSeed = (int)time(NULL);
		mtRand.seed(currentSeed);
		return currentSeed;
	};
	int seed(int seed_)
	{
		currentSeed = seed_;
		mtRand.seed(currentSeed);
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
			value = (int)(mtRand() * (high - low + 1.0) + low);
		} while (value > high);
		value += offset;
		return value;
	};

	// random float in [min(a,b),max(a,b))
	float rangeFloat(float a, float b)
	{
		return (float)(mtRand() * (maxf(a,b) - minf(a,b)) + minf(a,b));
	};
};

#endif // RNG_H
