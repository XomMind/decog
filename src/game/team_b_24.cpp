// team_b_24: CShell link select (0x90cdf0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
class XConsole { public: virtual ~XConsole(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void inputAscii(int key, int modifier); };
class CTextInput : public XConsole { public: void setText(const string &text); };
class CShellManual { public: char pad[0x6c]; CTextInput *textInput; };
struct TeamB_ShellLabel { int pad0; string name; };	// NOTE: placeholder layout
struct TeamB_ShellLink { char pad[0x6c]; TeamB_ShellLabel *label; char pad70[4]; int id; };	// NOTE: placeholder layout
struct TeamB_ShellText { char pad[0x70]; vector<TeamB_ShellLink*> links; };	// NOTE: placeholder layout
class TeamB_Targeter { public: bool testField_4afe50(); };
extern TeamB_Targeter *opX5C_cec0fc;	// NOTE: placeholder name (0xcec0fc)
extern string opq4c_d2d508[];	// NOTE: placeholder name
class TeamB_Shell	// NOTE: placeholder name (CShell)
{
public:
	char pad[0x74];
	vector<TeamB_ShellText*> texts;
	char pad84[0xa4 - 0x84];
	CShellManual *manual;
	void unknown939890();
	bool selectLink90cdf0(int id);
};
bool TeamB_Shell::selectLink90cdf0(int id)	// 0x90cdf0
{
	if (texts.empty() || opX5C_cec0fc->testField_4afe50())
		return false;
	for (int i = texts.size() - 1; i >= 0; i--)
	{
		if (texts[i] && !texts[i]->links.empty())
		{
			for (unsigned int j = 0; j < texts[i]->links.size(); j++)
			{
				if (texts[i]->links[j]->id == id)
				{
					if (!manual)
						unknown939890();
					string command = opq4c_d2d508[0];
					int pos = command.rfind('*',string::npos);
					command.erase(command.begin() + pos);
					command.insert(command.begin() + pos,texts[i]->links[j]->label->name.begin(),texts[i]->links[j]->label->name.end());
					command.insert(command.begin(),'&');
					manual->textInput->setText(command);
					manual->textInput->inputAscii(0xd,5);
					return true;
				}
			}
		}
	}
	return false;
}
