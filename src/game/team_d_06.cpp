// team_d_06: assorted dynamic initializers / atexit destructors in 0xb37ac0-0xb5e810:
// references bound to the XColor at 0xd29804, std::string globals built with operator+, and a
// container global with its own destructor (0x9b4c60).
// NOTE: all names are placeholders carrying the exe data address.
#include <string>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();
};

extern XColor	unknown_d29804;	// NOTE: placeholder name

XColor&	ptr_d01d4c	= unknown_d29804;
XColor&	ptr_d39294	= unknown_d29804;
XColor&	ptr_d20514	= unknown_d29804;
XColor&	ptr_d2cf04	= unknown_d29804;

extern string	gameString_d32974;
extern string	gameString_d01f04;
extern string	gameString_d33e1c;
extern string	gameString_d346a4;

string	str_d2022c	= gameString_d32974 + gameString_d01f04;	// NOTE: placeholder name
string	str_d34634	= gameString_d33e1c + gameString_d346a4;	// NOTE: placeholder name

class Unknown_9b4c60	// NOTE: placeholder name (vector-like; destructor 0x9b4c60)
{
	int pad[4];
public:
	Unknown_9b4c60();
	~Unknown_9b4c60();
};

Unknown_9b4c60	unk_cf13e8;	// NOTE: placeholder name
