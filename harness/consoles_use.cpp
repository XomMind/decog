// Emit header-inline functions until their game callers are reconstructed.
#include "../src/consoles/console.h"
#include "../src/consoles/consoleui.h"

void harness_consoles()
{
	Rect rect(*(Rect*)0);
	Pos pos(1,2);
	string s;
	Console *a = new Console(NULL,1,2,3,4,5,true,6);
	Console *b = new Console(NULL,rect,5,true,6);
	a->getUnknown60();
	a->getRect();
	delete a;
	delete b;
	delete new ConsoleTitle(NULL,s,1,2);
	delete new ConsoleArt(NULL,(AsciiImage*)0,1,2,true,3,4,pos,5,6);
	delete new ConsoleArt(NULL,s,1,2,true,3,4,pos,5,6);
	delete new CArtAnimated(NULL,(AsciiImage*)0,1,2,true,7,3,4,pos,5,6);
	delete new CArtAnimated(NULL,s,1,2,true,7,3,4,pos,5,6);
	delete new CText(NULL,pos,s,1,2,3);
	delete new CTextButton(NULL,pos,1,s,2,3);
}

void harness_consoles2()
{
	Pos pos(1,2);
	string s;
	XColor *c = 0;
	vector<int> v;
	CTextInput *ti = new CTextInput(NULL,1,2,3,4,true,true,5,6,7,8,"",9);
	ti->setUnknown98(v);
	ti->setUnknownA9(true);
	ti->setText("");
	ti->setUnknownBc(1,"");
	ti->setUnknown95(true);
	ti->setUnknownAa();
	delete ti;
	delete new CTemp(NULL,pos,1,2,3,4);
	delete new CCloseButton(NULL,*c,1);
	CInterfaceMsg *im = new CInterfaceMsg(NULL);
	im->refresh();
	delete im;
	delete new CListOption(NULL,1,2,3,s,4,true,5,6,true,7,8);
}

void harness_consoles3()
{
	Pos pos(1,2);
	string s;
	vector<string> v;
	CList *l = new CList(NULL,pos,s,1,v,2,3,NULL,4,5,true,true,NULL,NULL,NULL,true);
	l->getUnknown74();
	l->getOption(1);
	l->setUnknownC0(true);
	l->cancel();
	delete l;
}
