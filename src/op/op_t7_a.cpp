// op_t7_a: CTitle methods (0x95cb70-0x95cda0) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise
//	(RTTI class names are real).
#include "op_t7_r5f.h"

//==================================================================
// CTitle
//==================================================================

void CTitle::update()
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
			if (finished)
			{
				close();
			}
			else
			{
				break;
			}
		}
		case 4:
		{
			unknown60 = 0;
			opr5f_keyMap->unknown416640();
			if (opr5f_cec030)
			{
				opr5f_cec030->open();
			}
			else
			{
				opr5f_cec034->setHidden(false);
				opr5f_gm2->unknown78c050();
			}
			opr5f_cec02c = NULL;
			opr5f_rex.getConsole_4ab670()->removeSubconsole(this);
			return;
		}
	}
	XConsole::update();
}

void CTitle::close()
{
	unknown60 = 4;
	deleteSubconsoles();
	engine->stopAll();
	opr5f_sound->haltAll();
	if (cursorHidden)
	{
		opr5f_mouse2->setCursorHidden(false);
		cursorHidden = false;
	}
}

bool CTitle::input(XEvent *event)
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
		case 0x188:
		{
			if (opr5f_cefacd)
			{
				close();
				opr5f_cefaa8->unknown9c05e0();
				clear();
				show(true);
			}
			return true;
		}
	}
	return false;
}
