// team_d_102: CMap member 0x7fe7a0 (callers CMap's destructor and GM::endGame): tears down the map view
// state - optional game-over hook, the global engine object, the owned object lists and the sub-consoles.
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
using namespace std;

template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name

struct ObjA102;	// NOTE: placeholder element types (distinct clearObjects instantiations)
struct ObjB102;
struct ObjC102;
struct ObjD102;

class Engine
{
public:
	~Engine();
};
extern Engine *engine102_cefc64;	// NOTE: placeholder name

class GM102	// NOTE: placeholder name (GM at 0xcefaa8)
{
public:
	void unknown78d700(int a, int b);	// NOTE: placeholder name
};
extern GM102 *gm102_cefaa8;	// NOTE: placeholder name
extern bool flag102_d28d30;	// NOTE: placeholder name

class MapFine102	// NOTE: placeholder name (TeamB_MapFine, 0xcec058)
{
public:
	void clear874340();	// NOTE: placeholder name
};
extern MapFine102 *mapFine102_cec058;	// NOTE: placeholder name

class XConsole
{
public:
	void removeSubconsole(XConsole *console);
};

class CMap102 : public XConsole	// NOTE: placeholder name and layout (CMap)
{
public:
	char				pad000[0x124];
	vector<ObjA102 *>	list124;
	char				pad134[0x1a8 - 0x134];
	vector<ObjA102 *>	list1a8;
	char				pad1b8[0x1c8 - 0x1b8];
	vector<ObjB102 *>	list1c8;
	vector<ObjC102 *>	list1d8;
	char				pad1e8[0x31c - 0x1e8];
	vector<ObjA102 *>	list31c;
	vector<ObjA102 *>	list32c;
	char				pad33c[0x35c - 0x33c];
	vector<ObjA102 *>	list35c;
	XConsole			*sub36c;
	XConsole			*sub370;
	int					mode;		// +0x374
	char				pad378[4];
	bool				unknown37c;
	char				pad37d[0x460 - 0x37d];
	vector<ObjD102 *>	list460;
	char				pad470[0x558 - 0x470];
	XConsole			*sub558;
	char				pad55c[0x798 - 0x55c];
	vector<XConsole *>	subs798;
	XConsole			*sub7a8;
	char				pad7ac[4];
	vector<XConsole *>	subs7b0;

	void unknown7fe7a0();	// NOTE: placeholder name
};

void CMap102::unknown7fe7a0()
{
	if (mode != 5 && unknown37c && !flag102_d28d30)
		gm102_cefaa8->unknown78d700(0,0);
	delete engine102_cefc64;
	engine102_cefc64 = 0;
	OpQ5_clearObjects(list124);
	OpQ5_clearObjects(list1a8);
	OpQ5_clearObjects(list1c8);
	OpQ5_clearObjects(list1d8);
	OpQ5_clearObjects(list31c);
	OpQ5_clearObjects(list32c);
	OpQ5_clearObjects(list35c);
	OpQ5_clearObjects(list460);
	if (sub36c)
	{
		removeSubconsole(sub36c);
		sub36c = 0;
	}
	if (sub370)
	{
		removeSubconsole(sub370);
		sub370 = 0;
	}
	if (sub558)
	{
		removeSubconsole(sub558);
		sub558 = 0;
	}
	for (unsigned int i = 0; i < subs798.size(); i++)
		if (subs798[i])
			removeSubconsole(subs798[i]);
	subs798.clear();
	if (sub7a8)
	{
		removeSubconsole(sub7a8);
		sub7a8 = 0;
	}
	for (unsigned int j = 0; j < subs7b0.size(); j++)
		if (subs7b0[j])
			removeSubconsole(subs7b0[j]);
	subs7b0.clear();
	mapFine102_cec058->clear874340();
}
