// CLog console, matched against COGMIND.exe (Beta 17.1). NOTE: layout partial, names placeholders.
#include "../consoles/console.h"

class CLogMsgs : public Console	// NOTE: placeholder name
{
public:
	void unknown7b3df0(int value);	// NOTE: placeholder name
};

class CLog : public Console
{
public:
	virtual void trigger(const string &command, int value);
	CLogMsgs *getMessages();	// NOTE: placeholder name (0x48e760)

	char pad[0x7c - sizeof(Console)];
	int mode;	// NOTE: placeholder name
};

void CLog::trigger(const string &command, int value)
{
	if (command == "open_messages")
	{
		if (getMessages()->getUnknown60())
		{
			logError("CLog::trigger()",command + " already triggered (console active)");
			return;
		}
		getMessages()->unknown7b3df0(-1);
	}
}
