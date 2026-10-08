// CIntro::trigger (exe 0x95d0b0, vtable slot 11): intro sequence script commands.
// NOTE: class is declared here as D2Intro (placeholder name); layouts are partial, names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_);	// 0x46ca20
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();

	Pos getPos();
	int getWidth_44b0d0();
	void resetBack_418450() throw();
	void removeSubconsole(XConsole *console);
	void deleteSubconsoles();
	void unknown429f10(int a, int b);	// NOTE: placeholder name
	void copy429fe0(XConsole *parent, const Pos &pos, int flag);	// NOTE: placeholder name
	string getString(const Pos &pos, unsigned int length);
	string getStringVertical(const Pos &pos, unsigned int length);

	char pad04[0x60 - 0x04];
};

class D2iEngine { public: void killGroup(string group); };

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	void animate(string name);

	int unknown60;
	D2iEngine *engine;
	void *title;
};

class CText : public Console
{
public:
	CText(XConsole *parent, const Pos &pos, const string &text_, int font, int maxWidth, int layer);
	char pad6c[0x88 - 0x6c];
};

class D2iParticle { public: Pos *getPos(); };	// NOTE: placeholder name

class D2Intro : public Console
{
public:
	virtual bool input(void *event);
	virtual void update();
	virtual void open();
	void trigger(const string &command, D2iParticle *particle);	// NOTE: overrides trigger(const string&, int) in the exe

	void finish(bool haltSound);	// NOTE: placeholder name (0x95d020)

	CText *process;
	vector<Console*> consoles1;
	vector<Console*> consoles2;
	bool cursorHidden;
};

void D2Intro::trigger(const string &command, D2iParticle *particle)
{
	if (command == "sequence")
	{
		CText *t = new CText(this, Pos(1, 2), string("SEQUENCE INITIATED"), 2, 0, 10);
		t->resetBack_418450();
		t->animate("A_CIntro_Text");
	}
	else if (command == "regenerate")
	{
		CText *t = new CText(this, Pos(1, 4), string("REGENERATING NEURAL FIBERS"), 2, 0, 10);
		t->resetBack_418450();
		t->animate("A_CIntro_Text");
	}
	else if (command == "regenerate_process")
	{
		process = new CText(this, Pos(28, 4), string("   "), 2, 0, 10);
		process->resetBack_418450();
		process->animate("A_CIntro_Process");
		animate("A_CIntro_Bkg");
	}
	else if (command == "scan")
	{
		if (process)
		{
			removeSubconsole(process);
			process = NULL;
		}
		CText *t = new CText(this, Pos(1, 6), string("SCANNING NETWORK"), 2, 0, 10);
		t->resetBack_418450();
		t->animate("A_CIntro_Text");
	}
	else if (command == "scan_process")
	{
		process = new CText(this, Pos(18, 6), string("   "), 2, 0, 10);
		process->resetBack_418450();
		process->animate("A_CIntro_Process");
		animate("A_CIntro_Scan");
	}
	else if (command == "scanpoint")
	{
		if (particle->getPos()->x < getWidth_44b0d0() - 10)
		{
			string text = getString(*particle->getPos(), 8);
			Console *t = new CText(this, *particle->getPos(), text, 2, 0, -1);
			t->animate("A_CIntro_ScanPoint");
			consoles1.push_back(t);
		}
	}
	else if (command == "virus")
	{
		if (process)
		{
			removeSubconsole(process);
			process = NULL;
		}
		for (unsigned int i = 0; i < consoles1.size(); i++)
		{
			if (consoles1[i])
				removeSubconsole(consoles1[i]);
		}
		consoles1.clear();
		CText *t = new CText(this, Pos(18, 6), string(" VIRUS DETECTED "), 2, 0, 10);
		t->animate("A_CIntro_Alert");
		animate("A_CIntro_Virus");
	}
	else if (command == "format")
	{
		CText *t = new CText(this, Pos(1, 8), string("FORMATTING NON-VITAL INORGANICS"), 2, 0, 10);
		t->resetBack_418450();
		t->animate("A_CIntro_Text");
		process = new CText(this, Pos(33, 8), string("   "), 2, 0, 10);
		process->resetBack_418450();
		process->animate("A_CIntro_Process");
		engine->killGroup("virus");
		animate("A_CIntro_Format");
	}
	else if (command == "download")
	{
		if (process)
		{
			removeSubconsole(process);
			process = NULL;
		}
		CText *t = new CText(this, Pos(1, 10), string("DOWNLOADING ORGANIC MEMORY"), 2, 0, 10);
		t->resetBack_418450();
		t->animate("A_CIntro_Text");
	}
	else if (command == "download_process")
	{
		process = new CText(this, Pos(28, 10), string("   "), 2, 0, 10);
		process->resetBack_418450();
		process->animate("A_CIntro_Process");
		animate("A_CIntro_Download");
	}
	else if (command == "fragment")
	{
		if (process)
		{
			removeSubconsole(process);
			process = NULL;
		}
		CText *t = new CText(this, Pos(28, 10), string(" FRAGMENTED "), 2, 0, 10);
		t->animate("A_CIntro_Alert");
		animate("A_CIntro_Fragment");
	}
	else if (command == "fragmentpoint")
	{
		string text = getStringVertical(*particle->getPos(), 8);
		Console *c = new Console(this, 1, text.size(), particle->getPos()->x, particle->getPos()->y, 2, false, -1);
		c->animate("A_CIntro_FragmentPoint");
		consoles2.push_back(c);
	}
	else if (command == "recovery")
	{
		for (unsigned int i = 0; i < consoles2.size(); i++)
			consoles2[i]->copy429fe0(this, consoles2[i]->getPos(), 0);
		for (unsigned int i = 0; i < consoles2.size(); i++)
		{
			if (consoles2[i])
				removeSubconsole(consoles2[i]);
		}
		consoles2.clear();
		CText *t = new CText(this, Pos(1, 12), string("INITIATING RECOVERY"), 2, 0, 10);
		t->resetBack_418450();
		t->animate("A_CIntro_Text");
	}
	else if (command == "recovery_process")
	{
		process = new CText(this, Pos(21, 12), string("   "), 2, 0, 10);
		process->resetBack_418450();
		process->animate("A_CIntro_Process");
		Console *c = new Console(this, 0x24, 3, 3, 0xd, 2, false, 10);
		c->animate("A_CIntro_Recovery");
		c = new Console(this, 1, 3, 2, 0xd, 2, false, 10);
		c->animate("A_CIntro_BarEndL");
		c = new Console(this, 1, 3, 0x27, 0xd, 2, false, 10);
		c->animate("A_CIntro_BarEndR");
	}
	else if (command == "failed")
	{
		if (process)
		{
			removeSubconsole(process);
			process = NULL;
		}
		CText *t = new CText(this, Pos(21, 12), string(" FAILED "), 2, 0, 10);
		t->animate("A_CIntro_Alert");
	}
	else if (command == "secure")
	{
		CText *t = new CText(this, Pos(1, 17), string("SECURING SYSTEM"), 2, 0, 10);
		t->resetBack_418450();
		t->animate("A_CIntro_Text");
	}
	else if (command == "secure_process")
	{
		process = new CText(this, Pos(17, 17), string("   "), 2, 0, 10);
		process->resetBack_418450();
		process->animate("A_CIntro_Process");
		animate("A_CIntro_Secure");
	}
	else if (command == "secure_done")
	{
		if (process)
		{
			removeSubconsole(process);
			process = NULL;
		}
		CText *t = new CText(this, Pos(17, 17), string(" SECURED "), 2, 0, 10);
		t->animate("A_CIntro_Okay");
	}
	else if (command == "audio")
	{
		CText *t = new CText(this, Pos(1, 19), string("EXTERNAL AUDIO ACTIVE"), 2, 0, 10);
		t->resetBack_418450();
		t->animate("A_CIntro_Text");
		Console *c = new Console(this, 0x11, 7, 2, 0x14, 2, false, 10);
		c->resetBack_418450();
		c->animate("A_CIntro_Audio");
	}
	else if (command == "core")
	{
		CText *t = new CText(this, Pos(1, 28), string("ENGAGE CORE"), 2, 0, 10);
		t->resetBack_418450();
		t->animate("A_CIntro_Text");
	}
	else if (command == "core_process")
	{
		process = new CText(this, Pos(13, 28), string("   "), 2, 0, 10);
		process->resetBack_418450();
		process->animate("A_CIntro_Process");
		animate("A_CIntro_Core");
	}
	else if (command == "core_stable")
	{
		if (process)
		{
			removeSubconsole(process);
			process = NULL;
		}
		CText *t = new CText(this, Pos(13, 28), string(" STABLE "), 2, 0, 10);
		t->animate("A_CIntro_Okay");
	}
	else if (command == "control")
	{
		CText *t = new CText(this, Pos(1, 30), string("PREPARING CONTROL OVERLAY"), 2, 0, 10);
		t->resetBack_418450();
		t->animate("A_CIntro_Text");
	}
	else if (command == "control_process")
	{
		process = new CText(this, Pos(27, 30), string("   "), 2, 0, 10);
		process->resetBack_418450();
		process->animate("A_CIntro_Process");
		animate("A_CIntro_Fade_Bkg");
	}
	else if (command == "clear")
	{
		if (process)
		{
			removeSubconsole(process);
			process = NULL;
		}
		unknown429f10(0, 0);
		deleteSubconsoles();
		animate("A_CIntro_BlockFade");
	}
	else if (command == "start")
	{
		finish(false);
	}
}
