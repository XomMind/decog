// team_b_29: CShell::scroll (0x90d0a0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
string intToString(int value);
void logError(string source, string message);
struct Pos { int x; int y; Pos(int x_, int y_); };
class XConsole
{
public:
	virtual ~XConsole();
	int getHeight();
	vector<XConsole *> *getSubconsoles();
	void setHidden(bool hidden);
	Pos getPos();
	void setPos(const Pos &pos);
};
bool teamb_contains_9db330(vector<XConsole *> &list, XConsole *console);	// NOTE: placeholder name
void teamb_clampMin_9cf5c0(int *value, int min);	// NOTE: placeholder name
void teamb_clampMax_9cf5a0(int *value, int max);	// NOTE: placeholder name
bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)
class TeamB_ShellScroll : public XConsole	// NOTE: placeholder name (CShell)
{
public:
	char pad04[0x74 - 4];
	vector<XConsole *> lines;
	int topLine;
	void scroll90d0a0(int amount);
};
void TeamB_ShellScroll::scroll90d0a0(int amount)	// 0x90d0a0
{
	topLine += amount;
	if (amount < 0)
		teamb_clampMin_9cf5c0(&topLine,0);
	else if (amount > 0)
		teamb_clampMax_9cf5a0(&topLine,lines.size() - (getHeight() - 1));
	int lastLine = topLine + getHeight() - 3;
	for (unsigned int i = 0; i < lines.size(); i++)
	{
		if (lines[i] != NULL)
		{
			if (!teamb_contains_9db330(*getSubconsoles(),lines[i]))
				logError("CShell::scroll()","conText at index " + intToString(i) + " is invalid (out of topLine=" + intToString(topLine) + ", lastLine=" + intToString(lastLine) + ")");
			else if (OpT8b_Fn9daf80(topLine,i,lastLine))
			{
				lines[i]->setHidden(false);
				if (lines[i] != NULL)
					lines[i]->setPos(Pos(lines[i]->getPos().x,i - topLine + 1));
			}
			else
				lines[i]->setHidden(true);
		}
	}
}
