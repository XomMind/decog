// op_t7_b: CIntro / CMapAnim methods matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include "op_t7_r5f.h"

//==================================================================
// CIntro
//==================================================================

class CIntro : public Console
{
public:
	CIntro();	// 0x95ce50
	virtual ~CIntro();	// 0x4b2a20 (op_w7)
	virtual bool input(XEvent *event);
	virtual void update();
	virtual void open();
	virtual void trigger(const string &command, int value);	// 0x95d0b0

	void finish(bool haltSound);	// NOTE: placeholder name (0x95d020)

	int unknown6c;	// NOTE: placeholder name
	vector<Console*> consoles1;	// NOTE: placeholder name
	vector<Console*> consoles2;	// NOTE: placeholder name
	bool cursorHidden;	// NOTE: placeholder name
};

CIntro::CIntro()
	: Console(opr5f_rex.getConsole_4ab670(),opr5f_rex.unknown418980() / 2,opr5f_rex.unknown4189a0(),0,0,2,true,-1)
	, unknown6c	(0)
{
	cursorHidden = false;
}

void CIntro::open()
{
	unknown60 = 3;
	setHidden(false);
	opr5f_keyMap->unknown416570();
	opr5f_keyMap->unknown416340(true);
	opr5f_keyMap->unknown4162e0(0x1f,true);
	animate("A_CIntro_Timer");
	if (!opr5f_mouse2->getField_41a6e0())
	{
		opr5f_mouse2->setCursorHidden(true);
		cursorHidden = true;
	}
}

void CIntro::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		break;
		case 1:
		{
			unknown60 = 3;
			break;
		}
		case 3:
		{
			engine->update();
			break;
		}
		case 4:
		{
			unknown60 = 0;
			setHidden(true);
			opr5f_cec034->setHidden(false);
			opr5f_keyMap->unknown416640();
			opr5f_gm2->unknown78c050();
			opr5f_cec030 = NULL;
			opr5f_rex.getConsole_4ab670()->removeSubconsole(this);
			return;
		}
	}
	XConsole::update();
}

void CIntro::finish(bool haltSound)
{
	unknown60 = 4;
	unknown6c = 0;
	consoles1.clear();
	consoles2.clear();
	deleteSubconsoles();
	engine->stopAll();
	if (haltSound)
	{
		opr5f_sound->haltAll();
	}
	if (cursorHidden)
	{
		opr5f_mouse2->setCursorHidden(false);
		cursorHidden = false;
	}
}

bool CIntro::input(XEvent *event)
{
	if (isHidden() || opr5f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0x186:
		{
			finish(true);
			return true;
		}
		case 0x188:
		{
			finish(true);
			opr5f_cefaa8->unknown9c05e0();
			clear();
			open();
			return true;
		}
	}
	return false;
}

//==================================================================
// CMapAnim
//==================================================================

class OpT7_Sound	// NOTE: placeholder name (SoundMgr at 0xd2d2a0)
{
public:
	void setValue_4544c0(int value);	// NOTE: placeholder name (folded setter)
};
extern OpT7_Sound opt7_soundMgr;	// NOTE: placeholder name (0xd2d2a0)

class OpT7_World	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();	// 0x4630f0
};
extern OpT7_World *opt7_world;	// NOTE: placeholder name

class OpT7_Map : public Console	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	void unknown429fe0(XConsole *parent, Point *pos, bool flag);	// NOTE: placeholder name
};
extern OpT7_Map *opt7_cec054;	// NOTE: placeholder name

class OpT7_SpecialCommands	// NOTE: placeholder name (0xcec0ac)
{
public:
	void setTimer();	// 0x4acb40
};
extern OpT7_SpecialCommands *opt7_specialCommands;	// NOTE: placeholder name

class OpT7_GM	// NOTE: placeholder name (0xcefaa8)
{
public:
	void unknown78d700(bool a, bool b);	// NOTE: placeholder name
};
extern OpT7_GM *opt7_gm;	// NOTE: placeholder name

extern Rect opt7_cf27ec;	// NOTE: placeholder name
extern bool opt7_d28d15;	// NOTE: placeholder name
extern bool opt7_d28d30;	// NOTE: placeholder name
extern bool opt7_d28e7f;	// NOTE: placeholder name
extern int opt7_caed20;	// NOTE: placeholder name
extern XColor opt7_d29804;	// NOTE: placeholder name

class CMapAnim : public Console
{
public:
	CMapAnim();	// 0x95f6f0
	virtual ~CMapAnim();	// 0x4b2ad0 (op_w7)
	virtual bool input(XEvent *event);
	virtual void update();
	virtual void open();
	virtual void trigger(const string &command, int value);

	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
};
extern CMapAnim *opt7_cec050;	// NOTE: placeholder name

CMapAnim::CMapAnim()
	: Console(opr5f_cec034,opt7_cf27ec,(opt7_d28d15 != 0) + 2,false,-1)
{
	unknown70 = opt7_caed20;
	opt7_cec050 = this;
}

void CMapAnim::open()
{
	if (!opt7_d28e7f)
	{
		opt7_soundMgr.setValue_4544c0(opt7_world->getPlayer().ID);
		opt7_cec050 = NULL;
		opr5f_cec034->removeSubconsole(this);
		return;
	}
	unknown60 = 3;
	setHidden(false);
	opr5f_keyMap->unknown416570();
	opr5f_keyMap->unknown416340(true);
	opr5f_keyMap->unknown4162e0(0x1f,true);
	bool flag = opt7_d28d30;
	if (flag)
	{
		opt7_gm->unknown78d700(false,true);
	}
	opt7_cec054->render();
	opt7_cec054->unknown429fe0(this,&Point(0,0),false);
	opt7_cec054->setHidden(true);
	setForeAll_4183d0(opt7_d29804);
	setBackAll_418410(opt7_d29804);
	animate("A_CMapAnim_Timer",0x34,0);
	if (flag)
	{
		opt7_gm->unknown78d700(false,true);
	}
}

void CMapAnim::update()
{
	if (isHidden())
		return;
	switch (unknown60)
	{
		break;
		case 1:
		{
			unknown60 = 3;
			break;
		}
		case 3:
		{
			engine->update();
			break;
		}
		case 4:
		{
			unknown60 = 0;
			opt7_cec050 = NULL;
			opt7_cec054->setHidden(false);
			opt7_soundMgr.setValue_4544c0(opt7_world->getPlayer().ID);
			opt7_specialCommands->setTimer();
			opr5f_keyMap->unknown416640();
			opr5f_cec034->removeSubconsole(this);
			return;
		}
	}
	XConsole::update();
}

void CMapAnim::trigger(const string &command, int value)
{
	if (command == "killcrawlers")
	{
		engine->killGroup("crawler");
	}
	else if (command == "done")
	{
		close();
	}
}

bool CMapAnim::input(XEvent *event)
{
	if (isHidden() || opr5f_inputBlocked)
		return false;
	if (XConsole::input(event))
		return true;

	switch (event->type)
	{
		case 0x186:
		{
			close();
			return true;
		}
	}
	return false;
}

//==================================================================
// CEffect
//==================================================================

class CEffect : public Console
{
public:
	CEffect(XConsole *parent, const Rect &rect, int type_);	// 0x4b2b90 (op_w7)
	virtual ~CEffect();	// 0x95fa70 (not reconstructed)
	virtual void trigger(const string &command, int value);

	int type;	// NOTE: placeholder name
};

void CEffect::trigger(const string &command, int value)
{
	if (command == "end")
	{
		close();
	}
}
