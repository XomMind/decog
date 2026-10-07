// team_d_10: map view alert management (0x819e00).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
using namespace std;

class XConsole
{
public:
	void removeSubconsole(XConsole *child);	// 0x428b20
};

class CAlert : public XConsole	// NOTE: placeholder layout
{
public:
	CAlert(XConsole *parent, int alert_, bool warning_);	// 0x498880
	void draw();	// NOTE: placeholder name (0x498990)

	char pad[0x70];
	int alert;		// +0x70, NOTE: placeholder name
	bool warning;	// +0x74, NOTE: placeholder name
};

class CEffects
{
public:
	bool unknown4b3160();	// NOTE: placeholder name
};
extern CEffects *effects_cec138;	// NOTE: placeholder name

struct GameState	// NOTE: placeholder name
{
	int unknown0;	// NOTE: placeholder name
	int unknown4;	// NOTE: placeholder name
};
class HGameState	// NOTE: placeholder name
{
	int ID;
public:
	GameState *operator->() const;	// 0x9b7910
};
extern HGameState gameState_d1e888;	// NOTE: placeholder name
extern bool option_d28d60;			// NOTE: placeholder name
extern vector<int> alertStates_d1da60;	// NOTE: placeholder name

void eraseAlertAt(vector<CAlert *> &v, unsigned int &i);	// NOTE: placeholder name (folded with OpT8a_eraseAt 0x9ce6d0)

class OpD_MapView : public XConsole	// NOTE: placeholder name (MapView at 0xcec054)
{
public:
	void unknown819e00(int type, int mode);	// NOTE: placeholder name

	char pad[0x798];
	vector<CAlert *> alerts;	// +0x798, NOTE: placeholder name
};

void OpD_MapView::unknown819e00(int type, int mode)
{
	if (!option_d28d60 || gameState_d1e888->unknown4 == 1 || effects_cec138->unknown4b3160())
		return;
	for (unsigned int i = 0; i < alerts.size(); i++)
	{
		if (alerts[i]->alert == type)
		{
			switch (mode)
			{
				case 0:
					removeSubconsole(alerts[i]);
					eraseAlertAt(alerts,i);
					alertStates_d1da60[type] = 0;
					return;
				case 1:
					if (alertStates_d1da60[type] == 2)
					{
						alertStates_d1da60[type] = 1;
						alerts[i]->warning = true;
						alerts[i]->draw();
					}
					return;
				case 2:
					if (alertStates_d1da60[type] == 1)
					{
						alertStates_d1da60[type] = 2;
						alerts[i]->warning = false;
						alerts[i]->draw();
					}
					return;
			}
		}
	}
	if (mode != alertStates_d1da60[type])
	{
		if (mode > alertStates_d1da60[type])
			alerts.push_back(new CAlert(this,type,mode == 1));
		alertStates_d1da60[type] = mode;
	}
}
