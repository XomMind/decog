// op_w: inventory/partswap/search UI consoles (0x8a7370-0x8b0000) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <string>
#include <vector>
using namespace std;

class OpW_World	// NOTE: placeholder name (object at 0xcefc4c)
{
public:
	bool unknown71bbd0();	// NOTE: placeholder name
};
extern OpW_World *opw_world;	// NOTE: placeholder name

class OpW_Target	// NOTE: placeholder name (object at 0xcec090)
{
public:
	virtual void v00();
	virtual void v04();
	virtual void v08();
	virtual void v0c();
	virtual void v10();
	virtual void inputMouse(int id, int flag);	// NOTE: placeholder name
};
extern OpW_Target *opw_cec090;	// NOTE: placeholder name

class OpW_CPartswapListPart	// NOTE: placeholder layout
{
public:
	bool input(void *event);

	char pad00[0x70];
	int id;	// NOTE: placeholder name
};

bool OpW_CPartswapListPart::input(void *event)
{
	if (opw_world->unknown71bbd0())
		return false;
	switch (*(int*)event)
	{
		case 0x156:
			opw_cec090->inputMouse(id,0);
			return true;
	}
	return false;
}
