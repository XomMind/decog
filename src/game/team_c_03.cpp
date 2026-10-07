// team_c_03: assorted dynamic initializers (0xb23dc0-0xb2d350)
// NOTE: all names are placeholders (carry the exe data address)
#include <windows.h>
#include <vector>
using namespace std;

class REX	// NOTE: placeholder layout (0xd223f0)
{
public:
	char pad[16];

	REX();
	~REX();
};

struct FloatRange	// NOTE: placeholder name (ctor is ICF-folded with Push_40c490::operate)
{
	float a;
	float b;

	FloatRange(float a_, float b_);
};

REX	rex_d223f0;

void *(*sdlAlloc_d2f340)(unsigned int size) = (void *(*)(unsigned int))GetProcAddress(GetModuleHandleW(L"msvcrt"), "malloc");

FloatRange	range_d37978(0.1f, 0.95f);
FloatRange	range_cf195c(0.1f, 1.0f);
