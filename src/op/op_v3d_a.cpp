// op_v3d_a: GM startup functions (0x78b8a0-0x78f320), Beta 17.1.
#include "op_v3d.h"

class OpV3d_KeyMap	// NOTE: placeholder name (0xcefa8c)
{
public:
	void unknown427300();	// NOTE: placeholder name
};
extern OpV3d_KeyMap *opv3d_keyMap;	// NOTE: placeholder name

class OpV3d_Clock	// NOTE: placeholder name (0xcefa9c)
{
public:
	void start_416920();	// NOTE: placeholder name
};
extern OpV3d_Clock *opv3d_clock;	// NOTE: placeholder name

class CParts : public Console
{
public:
	void open(bool immediate);	// NOTE: placeholder name (0x894120)
};

class CMission : public Console
{
public:
	bool unknown987b10(int mode);	// NOTE: placeholder name
	void unknown987ea0();	// NOTE: placeholder name
	void unknown988270();	// NOTE: placeholder name
};

class OpV3d_Map : public Console	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	void unknown7f5fd0(int value);	// NOTE: placeholder name
	void unknown8069e0(Point pos, int value);	// NOTE: placeholder name
};

class CMapAnim : public Console
{
public:
	CMapAnim();	// 0x95f6f0
	virtual ~CMapAnim();	// 0x4b2ad0

	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
};

class OpV3d_SoundMgr	// NOTE: placeholder name (0xd2d2a0)
{
public:
	void unknown500260(bool flag);	// NOTE: placeholder name
};
extern OpV3d_SoundMgr opv3d_soundMgr;	// NOTE: placeholder name

class OpV3d_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
};
extern OpV3d_World *opv3d_world;	// NOTE: placeholder name

struct OpV3d_Entity2	// NOTE: placeholder name
{
};

void unknown4b3540(XConsole *parent);	// NOTE: placeholder name
Pos unknown4b33b0();	// NOTE: placeholder name

extern Console *opv3d_cec074;	// NOTE: placeholder name
extern Console *opv3d_cec078;	// NOTE: placeholder name
extern Console *opv3d_cec07c;	// NOTE: placeholder name
extern Console *opv3d_cec084;	// NOTE: placeholder name
extern CParts *opv3d_cec088;	// NOTE: placeholder name
extern Console *opv3d_cec08c;	// NOTE: placeholder name
extern Console *opv3d_cec0b0;	// NOTE: placeholder name
extern Console *opv3d_cec0d0;	// NOTE: placeholder name
extern Console *opv3d_cec0e4;	// NOTE: placeholder name
extern CMission *opv3d_cec034;	// NOTE: placeholder name
extern OpV3d_Map *opv3d_cec054;	// NOTE: placeholder name
extern int opv3d_d28d64;	// NOTE: placeholder name

struct OpV3d_GM	// NOTE: placeholder name (0xcefaa8)
{
	void reset_470bb0() throw();	// NOTE: placeholder name
	void unknown793690();	// NOTE: placeholder name
	void unknown78c050();	// NOTE: placeholder name
};

void OpV3d_GM::unknown78c050()
{
	reset_470bb0();
	opv3d_keyMap->unknown427300();
	unknown793690();
	logMessage("Initializing consoles");
	opv3d_cec054->unknown7f5fd0(0);
	opv3d_clock->start_416920();
	if (opv3d_cec0b0 == NULL)
		opv3d_cec034->unknown987ea0();
	opv3d_cec074->open();
	opv3d_cec0b0->open();
	if (opv3d_cec088 == NULL)
		opv3d_cec034->unknown988270();
	opv3d_cec0d0->setHidden(false);
	opv3d_cec034->unknown987b10(opv3d_d28d64);
	opv3d_cec0e4->setHidden(false);
	opv3d_cec078->open();
	opv3d_cec07c->open();
	opv3d_cec084->open();
	unknown4b3540(opv3d_cec034);
	opv3d_cec088->open(false);
	opv3d_cec08c->setPos(unknown4b33b0());
	opv3d_cec08c->open();
	opv3d_cec054->unknown8069e0(opv3d_world->getPlayer()->unknown45a4c0(),0);
	CMapAnim *anim = new CMapAnim();
	anim->open();
	opv3d_soundMgr.unknown500260(false);
}
