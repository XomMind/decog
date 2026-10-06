#include "mathutil.h"

float maxf(float a, float b)
{
	return a < b ? b : a;
}

float minf(float a, float b)
{
	return a > b ? b : a;
}
