// team_a_01: CRT header inlines from <math.h>/<time.inl> emitted out of line under /Od (0x401000-0x401350).
// The helpers below only exist to reference every float overload so that each inline is emitted.
#include <math.h>
#include <time.h>

float teamA01_useMath(float x, int n)	// NOTE: placeholder (not in the exe)
{
	float r = 0;
	r += atan(x); r += ceil(x); r += cos(x); r += fabs(x); r += log(x);
	r += pow(x, n); r += sin(x); r += sqrt(x); r += floor(x);
	return r;
}

double teamA01_useTime(time_t a, time_t b)	// NOTE: placeholder (not in the exe)
{
	localtime(&a); mktime(localtime(&b));
	return difftime(a, b);
}

#include <string>
size_t teamA01_useWide(wchar_t *a, const wchar_t *b, size_t n)	// NOTE: placeholder (not in the exe)
{
	std::char_traits<wchar_t>::copy(a, b, n);
	std::char_traits<wchar_t>::move(a, b, n);
	std::char_traits<wchar_t>::assign(a, n, L'x');
	return std::char_traits<wchar_t>::length(b);
}
