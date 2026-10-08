// team_b_36: console border flash effect (0x9655d0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include "../util/rng.h"
extern RNG rng;	// 0xd30908
struct Point { int x; int y; };
struct Pos { int x; int y; Pos(int x_, int y_); };
struct Rect { int x; int y; int width; int height; Rect(int x_, int y_, int width_, int height_); };
class TeamB_FlashEffect;
class TeamB_FlashEngine { public: TeamB_FlashEffect *unknown50fb50(TeamB_FlashEngine *engine, int type, const Pos &pos, Point *b, const Pos *c, Point *d, int value); };	// NOTE: placeholder name (OpR2b_Engine)
class TeamB_FlashEffect { public: void unknown50de10(); };	// NOTE: placeholder name
class XConsole
{
public:
	virtual ~XConsole();
	Pos getPos();
	int getHeight();
	int getWidth_44b0d0();	// NOTE: placeholder name
};
class TeamB_FlashConsole : public XConsole	// NOTE: placeholder name (CEffect)
{
public:
	TeamB_FlashConsole(XConsole *parent, const Rect &rect, int type_);	// NOTE: placeholder name (CEffect::CEffect 0x4b2b90)
	void unknown48c3c0(int value);	// NOTE: placeholder name
	char pad04[0x64 - 4];
	TeamB_FlashEngine *engine;
	char pad68[0x70 - 0x68];
};
extern XConsole *teamb_effectParent_cec138;	// NOTE: placeholder name
extern Point teamb_point_cfbec0;	// NOTE: placeholder name
void teamb_flashBorder9655d0(int type, int after, int before, XConsole *console, int amount)	// 0x9655d0 (local names follow docs/local-name-buckets.txt)
{
	bool flag;
	TeamB_FlashConsole *e;
	for (int side = 0; side < 4; side++)
	{
		flag = rng.chance(50);
		switch (side)
		{
			case 0:
				e = new TeamB_FlashConsole(teamb_effectParent_cec138,Rect(console->getPos().x,console->getPos().y,console->getWidth_44b0d0(),1),3);
				goto horizontal;
			case 1:
				e = new TeamB_FlashConsole(teamb_effectParent_cec138,Rect(console->getPos().x,console->getPos().y + console->getHeight() - 1,console->getWidth_44b0d0(),1),3);
			horizontal:
				e->unknown48c3c0(before);
				if (flag)
				{
					for (int i = 0; i < amount; i++)
						do { e->engine->unknown50fb50(e->engine,type,Pos(rng.rangeInt(e->getWidth_44b0d0() / 4,e->getWidth_44b0d0() - 1),0),&teamb_point_cfbec0,&Pos(0,0),&teamb_point_cfbec0,9)->unknown50de10(); } while (0);
				}
				else
				{
					for (int j = 0; j < amount; j++)
						do { e->engine->unknown50fb50(e->engine,type,Pos(rng.rangeInt(0,e->getWidth_44b0d0() / 4 * 3 - 1),0),&teamb_point_cfbec0,&Pos(e->getWidth_44b0d0() - 1,0),&teamb_point_cfbec0,9)->unknown50de10(); } while (0);
				}
				e->unknown48c3c0(after);
				break;
			case 2:
				e = new TeamB_FlashConsole(teamb_effectParent_cec138,Rect(console->getPos().x,console->getPos().y,1,console->getHeight()),3);
				goto vertical;
			case 3:
				e = new TeamB_FlashConsole(teamb_effectParent_cec138,Rect(console->getPos().x + console->getWidth_44b0d0() - 1,console->getPos().y,1,console->getHeight()),3);
			vertical:
				e->unknown48c3c0(before);
				if (flag)
				{
					for (int k = 0; k < amount; k++)
						do { e->engine->unknown50fb50(e->engine,type,Pos(0,rng.rangeInt(e->getHeight() / 4,e->getHeight() - 1)),&teamb_point_cfbec0,&Pos(0,0),&teamb_point_cfbec0,9)->unknown50de10(); } while (0);
				}
				else
				{
					for (int m = 0; m < amount; m++)
						do { e->engine->unknown50fb50(e->engine,type,Pos(0,rng.rangeInt(0,e->getHeight() / 4 * 3 - 1)),&teamb_point_cfbec0,&Pos(0,e->getHeight() - 1),&teamb_point_cfbec0,9)->unknown50de10(); } while (0);
				}
				e->unknown48c3c0(after);
				break;
		}
	}
}
