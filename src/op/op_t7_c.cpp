// op_t7_c: screen-effect helpers (object with consoles at 0xcec078..0xcec08c) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include "op_t7_r5f.h"

class RNG
{
public:
	int rangeInt(float a, float b) throw();	// 0x406d70
};
extern RNG rng;	// 0xd30908

class OpT7_ScreenShake	// NOTE: placeholder name (0xd16188)
{
public:
	void start(int amount);	// NOTE: placeholder name (0x418610)
};
extern OpT7_ScreenShake opt7_screenShake;	// NOTE: placeholder name (0xd16188)

int minInt(int a, int b);	// 0x9cdb30

class CEffect : public Console
{
public:
	CEffect(XConsole *parent, const Rect &rect, int type_);	// 0x4b2b90 (op_w7)
	virtual ~CEffect();	// 0x95fa70

	int type;	// NOTE: placeholder name
};

extern Console *opt7_cec078;	// NOTE: placeholder name
extern Console *opt7_cec07c;	// NOTE: placeholder name
extern Console *opt7_cec084;	// NOTE: placeholder name
extern Console *opt7_cec088;	// NOTE: placeholder name
extern Console *opt7_cec08c;	// NOTE: placeholder name
extern XColor opt7_cf6f2c;	// NOTE: placeholder name
extern bool opt7_d28e4f;	// NOTE: placeholder name
extern bool opt7_d28d4d;	// NOTE: placeholder name

class OpT7_Hud : public Console	// NOTE: placeholder name (parent of the effect consoles)
{
public:
	void unknown964d60(int type);	// NOTE: placeholder name
	void unknown9650c0(int type);	// NOTE: placeholder name

	int pad6c[2];
	int unknown74;	// NOTE: placeholder name
	int unknown78;	// NOTE: placeholder name
};

//==================================================================
// effect consoles
//==================================================================

void opt7_animateConsoles(const string &name);	// NOTE: placeholder name (0x964cb0)
void opt7_killGroupFore(const string &name);	// NOTE: placeholder name (0x964f80)

void opt7_animateConsoles(const string &name)
{
	opt7_cec078->animate(name);
	opt7_cec07c->animate(name);
	opt7_cec084->animate(name);
	opt7_cec088->animate(name);
	opt7_cec08c->animate(name);
}

void OpT7_Hud::unknown964d60(int type)
{
	if (!opt7_d28e4f)
		return;
	if (!((opt7_cec078->isHidden() || opt7_cec078->getState_48c360() == 3)
		&& (opt7_cec07c->isHidden() || opt7_cec07c->getState_48c360() == 3)
		&& (opt7_cec084->isHidden() || opt7_cec084->getState_48c360() == 3)
		&& (opt7_cec088->isHidden() || opt7_cec088->getState_48c360() == 3)
		&& (opt7_cec08c->isHidden() || opt7_cec08c->getState_48c360() == 3)))
		return;
	unknown74 = type;
	switch (type)
	{
		case 0x1d: opt7_animateConsoles("A_CEffect_StasisB"); break;
		case 0x1e: opt7_animateConsoles("A_CEffect_StasisP"); break;
		case 0x1f: opt7_animateConsoles("A_CEffect_Core"); break;
		case 0x20: opt7_animateConsoles("A_CEffect_Heat"); break;
	}
}

void opt7_killGroupFore(const string &name)
{
	opt7_cec078->engine->killGroup(name);
	opt7_cec078->setFrameFore(opt7_cf6f2c);
	opt7_cec07c->engine->killGroup(name);
	opt7_cec07c->setFrameFore(opt7_cf6f2c);
	opt7_cec084->engine->killGroup(name);
	opt7_cec084->setFrameFore(opt7_cf6f2c);
	opt7_cec088->engine->killGroup(name);
	opt7_cec088->setFrameFore(opt7_cf6f2c);
	opt7_cec08c->engine->killGroup(name);
	opt7_cec08c->setFrameFore(opt7_cf6f2c);
}

void OpT7_Hud::unknown9650c0(int type)
{
	unknown74 = 0x21;
	switch (type)
	{
		case 0x1d: opt7_killGroupFore("effectB"); break;
		case 0x1e: opt7_killGroupFore("effectP"); break;
		case 0x1f: opt7_killGroupFore("effectC"); break;
		case 0x20: opt7_killGroupFore("effectH"); break;
	}
}
